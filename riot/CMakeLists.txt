cmake_minimum_required(VERSION 3.5)

project(riot)

include(ExternalProject)

find_package(ament_cmake REQUIRED)

ExternalProject_Add(RIOT
    GIT_REPOSITORY https://github.com/astralien3000/RIOT.git
    GIT_TAG e5aad80350c07b0f6bcc18d21e8080d939a2f768

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
