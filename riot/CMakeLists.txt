cmake_minimum_required(VERSION 3.5)

project(riot)

find_package(ament_cmake REQUIRED)

install(
  DIRECTORY RIOT
  DESTINATION .
)

ament_package()
