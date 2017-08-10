# Copyright 2014-2015 Open Source Robotics Foundation, Inc.
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

set(_output_path
  "${CMAKE_CURRENT_BINARY_DIR}/rosidl_typesupport_test/${PROJECT_NAME}")
set(_generated_msg_header_files "")
set(_generated_msg_source_files "")
set(_generated_srv_header_files "")
set(_generated_srv_source_files "")
foreach(_idl_file ${rosidl_generate_interfaces_IDL_FILES})
  get_filename_component(_extension "${_idl_file}" EXT)
  get_filename_component(_parent_folder "${_idl_file}" DIRECTORY)
  get_filename_component(_parent_folder "${_parent_folder}" NAME)
  get_filename_component(_msg_name "${_idl_file}" NAME_WE)
  string_camel_case_to_lower_case_underscore("${_msg_name}" _header_name)

  if(_extension STREQUAL ".msg")
    if(_parent_folder STREQUAL "msg")
      list(APPEND _generated_msg_header_files
        "${_output_path}/${_parent_folder}/${_header_name}__test_type_support.h")
      list(APPEND _generated_msg_source_files
        "${_output_path}/${_parent_folder}/${_header_name}__type_support.c")
    elseif(_parent_folder STREQUAL "srv")
      list(APPEND _generated_srv_header_files
        "${_output_path}/${_parent_folder}/${_header_name}__introspection_type_support.h")
      list(APPEND _generated_srv_source_files
        "${_output_path}/${_parent_folder}/${_header_name}__type_support.c")
    else()
      message(FATAL_ERROR "Interface file with unknown parent folder: ${_idl_file}")
    endif()
  elseif(_extension STREQUAL ".srv")
    list(APPEND _generated_srv_header_files
      "${_output_path}/${_parent_folder}/${_header_name}__introspection_type_support.h"
    )
    list(APPEND _generated_srv_source_files
      "${_output_path}/${_parent_folder}/${_header_name}__type_support.c"
    )
  else()
    message(FATAL_ERROR "Interface file with unknown extension: ${_idl_file}")
  endif()
endforeach()

set(_dependency_files "")
set(_dependencies "")
foreach(_pkg_name ${rosidl_generate_interfaces_DEPENDENCY_PACKAGE_NAMES})
  foreach(_idl_file ${${_pkg_name}_INTERFACE_FILES})
  get_filename_component(_extension "${_idl_file}" EXT)
  if(_extension STREQUAL ".msg")
    set(_abs_idl_file "${${_pkg_name}_DIR}/../${_idl_file}")
    normalize_path(_abs_idl_file "${_abs_idl_file}")
    list(APPEND _dependency_files "${_abs_idl_file}")
    list(APPEND _dependencies "${_pkg_name}:${_abs_idl_file}")
  endif()
  endforeach()
endforeach()

set(target_dependencies
  "${rosidl_typesupport_test_BIN}"
  ${rosidl_typesupport_test_GENERATOR_FILES}
  "${rosidl_typesupport_test_TEMPLATE_DIR}/msg__test_type_support.h.em"
  "${rosidl_typesupport_test_TEMPLATE_DIR}/msg__type_support.c.em"
  "${rosidl_typesupport_test_TEMPLATE_DIR}/srv__introspection_type_support.h.em"
  "${rosidl_typesupport_test_TEMPLATE_DIR}/srv__type_support.c.em"
  ${rosidl_generate_interfaces_IDL_FILES}
  ${_dependency_files})
foreach(dep ${target_dependencies})
  if(NOT EXISTS "${dep}")
    message(FATAL_ERROR "Target dependency '${dep}' does not exist")
  endif()
endforeach()

set(generator_arguments_file "${CMAKE_BINARY_DIR}/rosidl_typesupport_test__arguments.json")
rosidl_write_generator_arguments(
  "${generator_arguments_file}"
  PACKAGE_NAME "${PROJECT_NAME}"
  ROS_INTERFACE_FILES "${rosidl_generate_interfaces_IDL_FILES}"
  ROS_INTERFACE_DEPENDENCIES "${_dependencies}"
  OUTPUT_DIR "${_output_path}"
  TEMPLATE_DIR "${rosidl_typesupport_test_TEMPLATE_DIR}"
  TARGET_DEPENDENCIES ${target_dependencies}
)

add_custom_command(
  OUTPUT ${_generated_msg_header_files} ${_generated_msg_source_files}
          ${_generated_srv_header_files} ${_generated_srv_source_files}
  COMMAND ${PYTHON_EXECUTABLE} ${rosidl_typesupport_test_BIN}
  --generator-arguments-file "${generator_arguments_file}"
  DEPENDS ${target_dependencies}
  COMMENT "Generating C typesupport_test for ROS interfaces"
  VERBATIM
)

# generate header to switch between export and import for a specific package
set(_visibility_control_file
  "${_output_path}/msg/rosidl_typesupport_test__visibility_control.h")
string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
configure_file(
  "${rosidl_typesupport_test_TEMPLATE_DIR}/rosidl_typesupport_test__visibility_control.h.in"
  "${_visibility_control_file}"
  @ONLY
)
list(APPEND _generated_msg_header_files "${_visibility_control_file}")

set(_target_suffix "__rosidl_typesupport_test")

add_custom_target(${rosidl_generate_interfaces_TARGET}${_target_suffix} ALL
  DEPENDS ${_generated_msg_header_files} ${_generated_msg_source_files}
          ${_generated_srv_header_files} ${_generated_srv_source_files}
)

add_dependencies(
  ${rosidl_generate_interfaces_TARGET}
  ${rosidl_generate_interfaces_TARGET}${_target_suffix}
)

if(NOT rosidl_generate_interfaces_SKIP_INSTALL)
  if(NOT _generated_msg_header_files STREQUAL "")
    install(
      FILES ${_generated_msg_header_files}
      DESTINATION "include/${PROJECT_NAME}/msg"
    )
  endif()
  if(NOT _generated_msg_source_files STREQUAL "")
    install(
      FILES ${_generated_msg_source_files}
      DESTINATION "${rosidl_generate_interfaces_TARGET}${_target_suffix}"
    )
  endif()

  set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${rosidl_generate_interfaces_TARGET}${_target_suffix}/Makefile")
  file(WRITE  "${MAKEFILE_PATH}" "MODULE = ${rosidl_generate_interfaces_TARGET}${_target_suffix}\n")
  file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

  set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${rosidl_generate_interfaces_TARGET}${_target_suffix}/Makefile.include")
  file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += cbor\n")

endif()
