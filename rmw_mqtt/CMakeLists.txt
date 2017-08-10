cmake_minimum_required(VERSION 3.5)

project(rmw_mqtt)

set(CONNEXT_STATIC_DISABLE $ENV{CONNEXT_STATIC_DISABLE}
  CACHE BOOL "If Connext Static should be disabled.")

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
endif()

find_package(ament_cmake REQUIRED)

find_package(rmw REQUIRED)
find_package(rosidl_generator_c REQUIRED)
find_package(rosidl_typesupport_test REQUIRED)

ament_export_dependencies(
  rmw
  rosidl_generator_c
  rosidl_typesupport_test)

ament_package()

install(
  DIRECTORY src/
  DESTINATION ${PROJECT_NAME}
)
