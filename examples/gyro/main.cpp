#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>

#include "task.h"
#include "gyro.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <std_msgs/msg/int32.h>

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  task_init();

  xtimer_sleep(1);
  Gyro::instance().start();

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("talker");
  rclc_publisher_t* pub = rclc_create_publisher(node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, Int32), "chatter", 1);

  std_msgs__msg__Int32 msg;
  msg.data = 0;

  while (rclc_ok()) {
    msg.data = (int)(100*Gyro::instance().angle().get());

    printf("Publishing: %i\n", (int)msg.data);

    rclc_publish(pub, (const void*)&msg);

    rclc_sleep_ms(100);
  }

  rclc_destroy_publisher(pub);
  rclc_destroy_node(node);
  
  return 0;
}
