cmake_minimum_required(VERSION 3.5)
project(talker_c)

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

find_package(rosidl_typesupport_test REQUIRED)

install(
  FILES main.c
  DESTINATION ${PROJECT_NAME}
)

ament_package_xml()

set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
file(WRITE  "${MAKEFILE_PATH}" "APPLICATION = ${PROJECT_NAME}\n")
file(APPEND "${MAKEFILE_PATH}" "RIOTBASE ?= ${CMAKE_INSTALL_PREFIX}/RIOT\n")
file(APPEND "${MAKEFILE_PATH}" "BOARD ?= native\n")
file(APPEND "${MAKEFILE_PATH}" "QUIET ?= 0\n")
file(APPEND "${MAKEFILE_PATH}" "WERROR ?= 0\n")
foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
  foreach(idir ${${dep}_INCLUDE_DIRS})
    file(APPEND "${MAKEFILE_PATH}" "INCLUDES += -I${idir}\n")
  endforeach()
  file(APPEND "${MAKEFILE_PATH}" "DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
  file(APPEND "${MAKEFILE_PATH}" "USEMODULE += ${dep}\n")
  file(APPEND "${MAKEFILE_PATH}" "include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
endforeach()
file(APPEND "${MAKEFILE_PATH}" "INCLUDES += -I/Users/loicdauphin/myws/install/include/rosidl_typesupport_test/impl/\n")
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.include\n")

ament_package()
