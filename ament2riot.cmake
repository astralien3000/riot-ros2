################################################################
# cmake2riot
################################################################
#
# This file should be used as a CMAKE_TOOLCHAIN_FILE
# Warning : It replace some common cmake functions,
#           your project may not work properly.
#
################################################################

# Toolchain Files are called twice in the process...
if(CALL_ONCE)
    return()
endif()
set(CALL_ONCE 1)

# Basic configuration of the toolchain
message("[cmake2riot] toolchain configuration")
set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Define BOARD
if(NOT DEFINED BOARD)
    if(DEFINED ENV{BOARD})
        set(BOARD $ENV{BOARD})
    else()
        set(BOARD native)
    endif()
endif()

################################################################
# Replace try_compile
################################################################
macro(try_compile)
    # Do nothing
endmacro()

################################################################
# Replace add_executable
################################################################
#
# add_executable(<name> [WIN32] [MACOSX_BUNDLE]
#                [EXCLUDE_FROM_ALL]
#                source1 [source2 ...])
#
################################################################
macro(add_executable target)
    message("[cmake2riot] executing custom add_executable command")

    # Parse arguments
    set(options WIN32 MACOSX_BUNDLE EXCLUDE_FROM_ALL)
    set(oneValueArgs "")
    set(multiValueArgs "")
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Display Warnings for unsupported parameters
    foreach(opt in ${options})
        if(args_${opt})
            message(WARNING "[cmake2riot] ${opt} option is not supported")
        endif()
    endforeach()

    # Make the directory where the RIOT project will be put
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target})

    # Foreach source arguments
    set(${target}_sources "")
    foreach(arg ${args_UNPARSED_ARGUMENTS})
        # Copy source to the RIOT project
        set(src_file ${CMAKE_CURRENT_SOURCE_DIR}/${arg})
        set(dst_file ${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target}/${arg})
        configure_file(${src_file} ${dst_file} COPYONLY)

        # Add the source to ${target}_sources
        set(${target}_sources ${${target}_sources} ${dst_file})
    endforeach(arg)

    # Create the RIOT project's Makefile
    set(MAKEFILE_PATH "${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target}/Makefile")
    file(WRITE  "${MAKEFILE_PATH}" "APPLICATION = ${target}\n")
    file(APPEND "${MAKEFILE_PATH}" "RIOTBASE ?= $ENV{HOME}/RIOT\n")
    file(APPEND "${MAKEFILE_PATH}" "BOARD ?= ${BOARD}\n")
    file(APPEND "${MAKEFILE_PATH}" "QUIET ?= 1\n")
    file(APPEND "${MAKEFILE_PATH}" "WERROR ?= 0\n")
    file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.include\n")

    # Add custom target to compile the target
    add_custom_target(
        ${target} ALL
        COMMAND make
        DEPENDS ${${target}_sources} ${MAKEFILE_PATH}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target}
        )

    # Add custom target to flash the target
    add_custom_target(
        ${target}-flash
        COMMAND make flash
        DEPENDS ${target}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target}
        )

    # Add custom target to run "make term" on the target
    add_custom_target(
        ${target}-term
        COMMAND make term
        DEPENDS ${target}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cmake2riot/${target}
        )
endmacro()

################################################################
# Replace add_library
################################################################
#
# add_library(<name> [STATIC | SHARED | MODULE]
#             [EXCLUDE_FROM_ALL]
#             source1 [source2 ...])
#
################################################################
macro(add_library target)
    message("[cmake2riot] executing custom add_library command")

    # Parse arguments
    set(options STATIC SHARED MODULE EXCLUDE_FROM_ALL)
    set(oneValueArgs "")
    set(multiValueArgs "")
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Display Warnings for unsupported parameters
    foreach(opt in ${options})
        if(args_${opt})
            message(WARNING "[cmake2riot] ${opt} option is not supported")
        endif()
    endforeach()

    # Make the directory where the RIOT project will be put
    file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${target})

    # Foreach source arguments
    set(${target}_sources "")
    foreach(arg ${args_UNPARSED_ARGUMENTS})
        # Copy source to the RIOT module
        install(FILES ${src_file} DESTINATION ${target})

        # Add the source to ${target}_sources
        set(${target}_sources ${${target}_sources} ${arg})
    endforeach(arg)

    # Hack to get ament-generated *_BUILD_DEPENDS variables
    #ament_package_xml()

    # Create the RIOT module's Makefile
    set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${target}/Makefile")
    file(WRITE  "${MAKEFILE_PATH}" "MODULE = ${PROJECT_NAME}\n")
    foreach(src ${${target}_sources})
      file(APPEND "${MAKEFILE_PATH}" "SRC += ${src}\n")
    endforeach()
    file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

    # Create the RIOT module's Makefile.include
    set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${target}/Makefile.include")
    file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
    foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
    endforeach()
    foreach(idir ${${PROJECT_NAME}_INCLUDE_DIRS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "INCLUDES += -I${idir}\n")
    endforeach()

    # Add custom target to compile the target
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/dummy.c" "")
    _add_library(${target} STATIC "${CMAKE_CURRENT_BINARY_DIR}/dummy.c")

    # Add custom target to trigger sources generation if any
    add_custom_target(${target}_dummy ALL DEPENDS ${${target}_sources})
endmacro()
