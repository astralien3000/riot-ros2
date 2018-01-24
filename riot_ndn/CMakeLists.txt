cmake_minimum_required(VERSION 3.5)

project(riot_ndn)

find_package(ament_cmake REQUIRED)

install(DIRECTORY ndn-riot DESTINATION . USE_SOURCE_PERMISSIONS)

ament_package()
