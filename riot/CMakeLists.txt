cmake_minimum_required(VERSION 3.5)

project(riot)

find_package(ament_cmake REQUIRED)

install(DIRECTORY RIOT DESTINATION . USE_SOURCE_PERMISSIONS)

ament_package()
