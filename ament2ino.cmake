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
# ament2ino
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
message("[ament2ino] toolchain configuration")
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
set(ARDUINO 1)

# Keep used variables from ament2riot (TODO : remove)
set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")

# Fill the Arduino library include file
file(WRITE ${CMAKE_INSTALL_PREFIX}/Arduino/libraries/ros2_include/ros2_include.h "")
file(APPEND ${CMAKE_INSTALL_PREFIX}/Arduino/libraries/${PROJECT_NAME}/${PROJECT_NAME}.h "#include <ros2_include.h>\n")

################################################################
# Replace try_compile
################################################################
macro(try_compile)
    # Do nothing
endmacro()

################################################################
# riot_add_config
################################################################
#
# riot_add_config(<name> <cfg_str>)
#
################################################################
macro(riot_add_config target cfg)
  set(${target}_cfg ${${target}_cfg} ${cfg})
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
    message("[ament2ino] executing custom add_executable command")

    # Parse arguments
    set(options WIN32 MACOSX_BUNDLE EXCLUDE_FROM_ALL)
    set(oneValueArgs "")
    set(multiValueArgs "")
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Display Warnings for unsupported parameters
    foreach(opt in ${options})
        if(args_${opt})
            message(WARNING "[ament2ino] ${opt} option is not supported")
        endif()
    endforeach()

    # Make the directory where the RIOT project will be put
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ament2ino/${target})

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
            install(FILES ${src} DESTINATION Arduino/${target})
        else()
            install(FILES ${src} DESTINATION Arduino/${target})
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
    message("[ament2ino] executing custom add_library command")

    # Parse arguments
    set(options STATIC SHARED MODULE EXCLUDE_FROM_ALL)
    set(oneValueArgs "")
    set(multiValueArgs "")
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Display Warnings for unsupported parameters
    foreach(opt in ${options})
        if(args_${opt})
            message(WARNING "[ament2ino] ${opt} option is not supported")
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
            install(FILES ${src} DESTINATION Arduino/libraries/${target})
        else()
            install(FILES ${src} DESTINATION Arduino/libraries/${target})
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
            install(FILES ${srcs} DESTINATION Arduino/libraries/${target})
        else()
            install(FILES ${srcs} DESTINATION Arduino/libraries/${target})
        endif()
    endforeach()

    # Hack to get ament-generated *_BUILD_DEPENDS variables
    unset(_AMENT_PACKAGE_NAME)
    ament_package_xml()

    # Copy include dirs
    if("${target}" STREQUAL "${PROJECT_NAME}")
        foreach(dir ${${PROJECT_NAME}_INCLUDE_DIRECTORIES})
            file(GLOB_RECURSE INCLUDE_FILES_H "${dir}/*.h")
            file(GLOB_RECURSE INCLUDE_FILES_HPP "${dir}/*.hpp")
            set(INCLUDE_FILES ${INCLUDE_FILES_H} ${INCLUDE_FILES_HPP})
            foreach(f ${INCLUDE_FILES})
                string(REGEX REPLACE ".*/include/" "" ff ${f})
                string(REGEX REPLACE "/[a-z_]+\\.hp*" "" fff ${ff})
                install(FILES ${f} DESTINATION Arduino/libraries/${target}/${fff})
            endforeach()
        endforeach()
    endif()

    # Fill the Arduino library include file
    file(APPEND ${CMAKE_INSTALL_PREFIX}/Arduino/libraries/${target}/${target}.h "#include <ros2_include.h>\n")
    foreach(dep ${${target}_BUILD_DEPENDS})
      file(APPEND ${CMAKE_INSTALL_PREFIX}/Arduino/libraries/${target}/${target}.h "#include <${dep}.h>\n")
    endforeach()

    if(NOT "${target}" STREQUAL "${PROJECT_NAME}")
        file(APPEND ${CMAKE_INSTALL_PREFIX}/Arduino/libraries/${PROJECT_NAME}/${PROJECT_NAME}.h "#include <${target}.h>\n")
    endif()

    # Add dummy library target to enable related commands
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/dummy.c" "")
    _add_library(${target} STATIC "${CMAKE_CURRENT_BINARY_DIR}/dummy.c")

    # Add custom target to trigger sources generation if any
    add_custom_target(${target}_dummy ALL DEPENDS ${${target}_sources})
endfunction()
