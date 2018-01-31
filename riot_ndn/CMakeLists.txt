cmake_minimum_required(VERSION 3.5)

project(riot_ndn)

include(ExternalProject)

find_package(ament_cmake REQUIRED)

ExternalProject_Add(ndn-riot
    GIT_REPOSITORY https://github.com/astralien3000/ndn-riot.git
    GIT_TAG 532eb723869a11ca4f95f6fc2ecd734fa4567069

    SOURCE_DIR ndn-riot

    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    )

install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ndn-riot
    DESTINATION .
    USE_SOURCE_PERMISSIONS
    )

ament_package()
