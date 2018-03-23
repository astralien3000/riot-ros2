cmake_minimum_required(VERSION 3.5)

project(rmw_ndn)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
endif()

find_package(ament_cmake REQUIRED)

find_package(rmw REQUIRED)
find_package(rosidl_generator_c REQUIRED)
find_package(rosidl_typesupport_cbor REQUIRED)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/dummy.c" "")
add_library(rmw_ndn STATIC "${CMAKE_CURRENT_BINARY_DIR}/dummy.c")

ament_export_dependencies(
  rmw
  rosidl_generator_c
  rosidl_typesupport_cbor
)

configure_rmw_library(rmw_ndn)

register_rmw_implementation(
  "c:rosidl_typesupport_c:rosidl_typesupport_introspection_c"
  "cpp:rosidl_typesupport_cpp:rosidl_typesupport_introspection_cpp")

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

file(APPEND "${MAKEFILE_INCLUDE_PATH}" "TAP ?= tap0\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "ifeq (,$(filter native,$(BOARD)))\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += ethos\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "ETHOS_BAUDRATE ?= 115200\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "CFLAGS += -DETHOS_BAUDRATE=$(ETHOS_BAUDRATE) -DUSE_ETHOS_FOR_STDIO\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "FEATURES_REQUIRED += periph_uart\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "TERMPROG ?= $(RIOTBASE)/dist/tools/ethos/ethos\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "TERMFLAGS ?= $(TAP) $(PORT) $(ETHOS_BAUDRATE)\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "TERMDEPS += host-tools\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "else\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += gnrc_netdev_default\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "PORT ?= $(TAP)\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "endif\n")

file(APPEND "${MAKEFILE_INCLUDE_PATH}" ".PHONY: host-tools\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "host-tools:\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "	$(Q)env -u CC -u CFLAGS make -C $(RIOTBASE)/dist/tools\n")

file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEMODULE += auto_init_gnrc_netif\n")
file(APPEND "${MAKEFILE_INCLUDE_PATH}" "USEPKG += ndn-riot\n")

ament_package()
