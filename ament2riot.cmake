# Copyright 2018 INRIA
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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

# Define RIOT
set(RIOT 1)

# Create the RIOT module's Makefile
set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
file(WRITE "${MAKEFILE_PATH}" "")
file(APPEND "${MAKEFILE_PATH}" "MODULE = ${PROJECT_NAME}\n")
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

# Create the RIOT module's Makefile.include
set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")
file(WRITE "${MAKEFILE_INCLUDE_PATH}" "")

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
        # Search source file
        if(IS_ABSOLUTE ${arg})
            set(src ${arg})
        elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${arg})
            set(src ${arg})
        elseif(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${arg})
            set(src ${CMAKE_CURRENT_BINARY_DIR}/${arg})
        else()
            message(ERROR "Could not find source : ${arg}")
        endif()

        # Add install rule for source file
        if("${target}" STREQUAL "${PROJECT_NAME}")
            install(FILES ${src} DESTINATION ${target})
        else()
            install(FILES ${src} DESTINATION ${PROJECT_NAME}/${target})
        endif()

        # Add the source to ${target}_sources
        set(${target}_sources ${${target}_sources} ${arg})

        # Add the source directory to ${target}_src_dirs
        get_filename_component(dir ${src} DIRECTORY)
        list(APPEND ${target}_src_dirs ${dir})
    endforeach(arg)

    # Hack to get ament-generated *_BUILD_DEPENDS variables
    unset(_AMENT_PACKAGE_NAME)
    ament_package_xml()


    # Fill the RIOT module's Makefile
    file(WRITE  "${MAKEFILE_PATH}" "APPLICATION = ${target}\n")
    file(APPEND "${MAKEFILE_PATH}" "RIOTBASE ?= ${CMAKE_INSTALL_PREFIX}/RIOT\n")
    file(APPEND "${MAKEFILE_PATH}" "BOARD ?= ${BOARD}\n")
    file(APPEND "${MAKEFILE_PATH}" "QUIET ?= 1\n")
    file(APPEND "${MAKEFILE_PATH}" "WERROR ?= 0\n")

    if("${target}" STREQUAL "${PROJECT_NAME}")
        foreach(src ${${target}_sources})
            if("${src}" MATCHES ".c$|.cpp$")
                file(APPEND "${MAKEFILE_PATH}" "SRC += ${src}\n")
            else()
                message(WARNING "[cmake2riot] adding a header to library : ${src}")
            endif()
        endforeach()
    endif()
    file(APPEND "${MAKEFILE_PATH}" "CFLAGS += -DROS_PACKAGE_NAME=\\\"${PROJECT_NAME}\\\"\n")
    file(APPEND "${MAKEFILE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include\n")
    file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.include\n")

    # Fill the RIOT module's Makefile.include
    foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
    endforeach()
    foreach(idir ${${PROJECT_NAME}_INCLUDE_DIRS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "INCLUDES += -I${idir}\n")
    endforeach()

    # Add dummy executable target to enable related commands
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/dummy.c" "int main() {}")
    _add_executable(${target} "${CMAKE_CURRENT_BINARY_DIR}/dummy.c")

    # Add custom target to trigger sources generation if any
    add_custom_target(${target}_dummy ALL DEPENDS ${${target}_sources})
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
function(add_library target)
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
        # Search source file
        if(IS_ABSOLUTE ${arg})
            set(src ${arg})
        elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${arg})
            set(src ${arg})
        elseif(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${arg})
            set(src ${CMAKE_CURRENT_BINARY_DIR}/${arg})
        else()
            message(ERROR "Could not find source : ${arg}")
        endif()

        # Add install rule for source file
        if("${target}" STREQUAL "${PROJECT_NAME}")
            install(FILES ${src} DESTINATION ${target})
        else()
            install(FILES ${src} DESTINATION ${PROJECT_NAME}/${target})
        endif()

        # Add the source to ${target}_sources
        set(${target}_sources ${${target}_sources} ${arg})

        # Add the source directory to ${target}_src_dirs
        get_filename_component(dir ${src} DIRECTORY)
        list(APPEND ${target}_src_dirs ${dir})
    endforeach(arg)

    # Search additional sources files that are not listed in args (headers)
    list(REMOVE_DUPLICATES ${target}_src_dirs)
    foreach(dir ${${target}_src_dirs})
        # Get unlisted headers
        file(GLOB srcs "${dir}/*.h")

        # Add install rule for unlisted files
        if("${target}" STREQUAL "${PROJECT_NAME}")
            install(FILES ${srcs} DESTINATION ${target})
        else()
            install(FILES ${srcs} DESTINATION ${PROJECT_NAME}/${target})
        endif()
    endforeach()

    # Hack to get ament-generated *_BUILD_DEPENDS variables
    unset(_AMENT_PACKAGE_NAME)
    ament_package_xml()

    # Fill the RIOT module's Makefile
    if("${target}" STREQUAL "${PROJECT_NAME}")
        foreach(src ${${target}_sources})
            if("${src}" MATCHES ".c$|.cpp$")
                file(APPEND "${MAKEFILE_PATH}" "SRC += ${src}\n")
            else()
                message(WARNING "[cmake2riot] adding a header to library : ${src}")
            endif()
        endforeach()
    endif()
    file(APPEND "${MAKEFILE_PATH}" "CFLAGS += -DROS_PACKAGE_NAME=\\\"${PROJECT_NAME}\\\"\n")

    # Fill the RIOT module's Makefile.include
    foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${dep}\n")
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
    endforeach()
    foreach(idir ${${PROJECT_NAME}_INCLUDE_DIRS})
      file(APPEND "${MAKEFILE_INCLUDE_PATH}" "INCLUDES += -I${idir}\n")
    endforeach()

    if(NOT "${target}" STREQUAL "${PROJECT_NAME}")
        # Create the RIOT sub-module's Makefile
        set(SUB_MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/${target}/Makefile")
        file(WRITE  "${SUB_MAKEFILE_PATH}" "MODULE = ${target}\n")
        foreach(src ${${target}_sources})
            if("${src}" MATCHES ".c$|.cpp$")
                file(APPEND "${MAKEFILE_PATH}" "SRC += ${src}\n")
            else()
                message(WARNING "[cmake2riot] adding a header to library : ${src}")
            endif()
        endforeach()
        file(APPEND "${SUB_MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

        # Add submodule to module's Makefile.include
        file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/${target}\n")
        file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${target}\n")
    endif()

    # Add dummy library target to enable related commands
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/dummy.c" "")
    _add_library(${target} STATIC "${CMAKE_CURRENT_BINARY_DIR}/dummy.c")

    # Add custom target to trigger sources generation if any
    add_custom_target(${target}_dummy ALL DEPENDS ${${target}_sources})
endfunction()
