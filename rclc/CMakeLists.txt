cmake_minimum_required(VERSION 3.5)

project(rclc)

find_package(ament_cmake REQUIRED)
find_package(rcl REQUIRED)

include_directories(include)

ament_export_dependencies(ament_cmake)
ament_export_dependencies(rcl)

ament_export_include_directories(include)

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

ament_package()
