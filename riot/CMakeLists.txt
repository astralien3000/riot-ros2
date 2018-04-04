cmake_minimum_required(VERSION 3.5)

project(riot)

include(ExternalProject)

find_package(ament_cmake REQUIRED)

ExternalProject_Add(RIOT
    GIT_REPOSITORY https://github.com/astralien3000/RIOT.git
    GIT_TAG f15d9fc1d1dca9079c0ca48d326e9d3dd01d50d4

    SOURCE_DIR RIOT

    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    )

install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/RIOT
    DESTINATION .
    USE_SOURCE_PERMISSIONS
    )

ament_package()
