cmake_minimum_required(VERSION 3.5)

project(rmw_implementation)

find_package(ament_cmake REQUIRED)

find_package(rmw_implementation_cmake REQUIRED)

get_default_rmw_implementation(RMW_IMPLEMENTATION)

get_available_rmw_implementations(RMW_IMPLEMENTATIONS)
message(STATUS "")
message(STATUS "Found these rmw implementations:")
foreach(impl IN LISTS RMW_IMPLEMENTATIONS)
  message(STATUS "  '${impl}'")
endforeach()

message(STATUS "")
message(STATUS "Using default rmw implementation: '${RMW_IMPLEMENTATION}'")
message(STATUS "")

file(APPEND "${MAKEFILE_INCLUDE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${RMW_IMPLEMENTATION}\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${RMW_IMPLEMENTATION}\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${RMW_IMPLEMENTATION}/Makefile.include\n")

register_rmw_implementation(
  "c:rosidl_typesupport_c"
  "cpp:rosidl_typesupport_cpp"
)

# necessary since get_available_rmw_implementations excludes rmw_implementation
list(APPEND RMW_IMPLEMENTATIONS "rmw_implementation")
ament_package(
  CONFIG_EXTRAS "rmw_implementation-extras.cmake.in"
)
