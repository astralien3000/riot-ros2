#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>

#include "task.h"
#include "gyro.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <custom_msgs/msg/gyro.h>

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  task_init();

  xtimer_sleep(1);
  Gyro::instance().start();

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("talker");
  rclc_publisher_t* pub = rclc_create_publisher(node, ROSIDL_GET_MSG_TYPE_SUPPORT(custom_msgs, Gyro), "chatter", 1);

  custom_msgs__msg__Gyro msg;
  msg.x_angle = 0;
  msg.y_angle = 0;
  msg.z_angle = 0;

  while (rclc_ok()) {
    msg.x_angle = (int)(100*Gyro::instance().getXAngle());
    msg.y_angle = (int)(100*Gyro::instance().getYAngle());
    msg.z_angle = (int)(100*Gyro::instance().getZAngle());

    printf("Publishing: [ %i %i %i ]\n", (int)msg.x_angle, (int)msg.y_angle, (int)msg.z_angle);

    rclc_publish(pub, (const void*)&msg);

    rclc_sleep_ms(100);
  }

  rclc_destroy_publisher(pub);
  rclc_destroy_node(node);
  
  return 0;
}
