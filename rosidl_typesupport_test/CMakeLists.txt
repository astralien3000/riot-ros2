cmake_minimum_required(VERSION 3.5)

project(rosidl_typesupport_test)

if(NOT WIN32)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

ament_export_dependencies(rosidl_cmake)
ament_export_dependencies(rosidl_generator_c)

# The reason the impl folder is exported is that it contains the implementation
# for the get_*_type_support_handle functions and defines the opensplice
# specific version of these functions.
ament_export_include_directories(include include/${PROJECT_NAME}/impl)

ament_python_install_package(${PROJECT_NAME})

install(
  PROGRAMS bin/rosidl_typesupport_test
  DESTINATION lib/rosidl_typesupport_test
)
install(
  DIRECTORY cmake resource
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  DIRECTORY src/
  DESTINATION ${PROJECT_NAME}
)

ament_package_xml()
set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
file(WRITE  "${MAKEFILE_PATH}" "MODULE = ${PROJECT_NAME}\n")
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")
file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
  foreach(idir ${${dep}_INCLUDE_DIRS})
    file(APPEND "${MAKEFILE_INCLUDE_PATH}" "INCLUDES += -I${idir}\n")
  endforeach()
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${dep}\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
endforeach()

ament_package(
  CONFIG_EXTRAS "rosidl_typesupport_test-extras.cmake.in"
)
