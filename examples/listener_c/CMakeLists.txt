cmake_minimum_required(VERSION 3.5)
project(listener_c)

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(listener_c main.c)
ament_target_dependencies(listener_c rclc std_msgs)

install(TARGETS
  listener_c
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
