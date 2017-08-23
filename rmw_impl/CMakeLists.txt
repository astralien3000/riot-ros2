cmake_minimum_required(VERSION 3.5)

project(rmw_impl)

find_package(ament_cmake REQUIRED)

ament_package_xml()
set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
file(WRITE  "${MAKEFILE_PATH}" "MODULE = ${PROJECT_NAME}\n")
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")
file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
foreach(dep ${${PROJECT_NAME}_BUILD_DEPENDS})
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "RMW ?= rmw_ndn\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "ifeq ($(RMW),${dep})\n")
  foreach(idir ${${dep}_INCLUDE_DIRS})
    file(APPEND "${MAKEFILE_INCLUDE_PATH}" "    INCLUDES += -I${idir}\n")
  endforeach()
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "    USEMODULE += ${dep}\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "    include ${CMAKE_INSTALL_PREFIX}/${dep}/Makefile.include\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "    DIRS += ${CMAKE_INSTALL_PREFIX}/${dep}\n")
  file(APPEND "${MAKEFILE_INCLUDE_PATH}" "endif\n")
endforeach()

ament_package()
