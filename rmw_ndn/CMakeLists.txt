cmake_minimum_required(VERSION 3.5)

project(rmw_ndn)

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
  rosidl_typesupport_test
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
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "EXTERNAL_MODULE_DIRS += ${CMAKE_INSTALL_PREFIX}/ndn-riot\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += gnrc_netdev_default\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += auto_init_gnrc_netif\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ndn-riot\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "INCLUDES += -I${CMAKE_INSTALL_PREFIX}\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "CXXEXFLAGS += -std=c++11\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "CFLAGS += -std=c11\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "LINKFLAGS += -lstdc++\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += cpp11-compat\n")

ament_package()
