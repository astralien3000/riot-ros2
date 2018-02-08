cmake_minimum_required(VERSION 3.5)
project(pub_int32_c)

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(pub_int32_c main.c)
ament_target_dependencies(pub_int32_c rclc std_msgs)

install(TARGETS
  pub_int32_c
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
