cmake_minimum_required(VERSION 3.5)
project(talker_c)

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker_c main.c)
ament_target_dependencies(talker_c rclc std_msgs)

install(TARGETS
  talker_c
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
