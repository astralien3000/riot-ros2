cmake_minimum_required(VERSION 3.5)
project(custom_boards)

find_package(ament_cmake REQUIRED)

install(
  DIRECTORY samr21-xpro-ceres
  DESTINATION ${PROJECT_NAME}
)

ament_package_xml()
set(MAKEFILE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile")
file(WRITE  "${MAKEFILE_PATH}" "MODULE = ${PROJECT_NAME}\n")
file(APPEND "${MAKEFILE_PATH}" "include $(RIOTBASE)/Makefile.base\n")

set(MAKEFILE_INCLUDE_PATH "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/Makefile.include")
file(WRITE  "${MAKEFILE_INCLUDE_PATH}" "")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "RIOTBOARD ?= ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}\n")

ament_package()
