cmake_minimum_required(VERSION 3.5)

project(rosidl_generator_c C)

if(NOT WIN32)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

include_directories(include)

ament_export_dependencies(rosidl_cmake)
ament_export_include_directories(include)

ament_python_install_package(${PROJECT_NAME})

install(
  PROGRAMS bin/rosidl_generator_c
  DESTINATION lib/rosidl_generator_c
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
foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
  foreach(idir ${${dep}_INCLUDE_DIRS})
    file(APPEND "${MAKEFILE_PATH}" "INCLUDES += -I${idir}\n")
  endforeach()
  file(APPEND "${MAKEFILE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
endforeach()
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")
file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ${dep}\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
endforeach()

ament_package(
  CONFIG_EXTRAS "rosidl_generator_c-extras.cmake.in"
)
