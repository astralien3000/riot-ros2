#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>

#include "task.h"
#include "gyro.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <std_msgs/msg/string.h>

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  task_init();

  xtimer_sleep(1);
  Gyro::instance().start();

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("talker");
  rclc_publisher_t* pub = rclc_create_publisher(node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, String), "chatter", 1);

  std_msgs__msg__String msg;
  char buff[64] = {0};
  msg.data.data = buff;
  msg.data.capacity = sizeof(buff);
  msg.data.size = 0;

  while (rclc_ok()) {
    msg.data.size = snprintf(msg.data.data, msg.data.capacity, "%i", (int)(100*Gyro::instance().angle().get()));
    if(msg.data.size > msg.data.capacity) msg.data.size = 0;

    if(msg.data.data[msg.data.size] == '\0') {
      printf("Publishing: '%s'\n", msg.data.data);
    }

    rclc_publish(pub, (const void*)&msg);

    rclc_sleep_ms(500);
  }

  rclc_destroy_publisher(pub);
  rclc_destroy_node(node);

  while(1) {
  }
  
  return 0;
}
