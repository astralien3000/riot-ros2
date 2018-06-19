#include <rclc/rclc.h>

#include <std_msgs/msg/string.h>

#include <stdio.h>

#include "ros2_log.h"
#include "xtimer.h"
#include "periph/gpio.h"
#include "periph/timer.h"

// SAMR21
#define SYNC_OUT_PIN GPIO_PIN(PA, 16)
#define SYNC_IN_PIN  GPIO_PIN(PA, 17)

// IOTLAB
//#define SYNC_IN_PIN  GPIO_PIN(PORT_A, 3)

void sync_cb(void* arg) {
  ros2_log_add_event(APP_SYNC);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

#ifdef SYNC_IN_PIN
  gpio_init_int(SYNC_IN_PIN, GPIO_IN, GPIO_BOTH, sync_cb, NULL);
#endif

  xtimer_sleep(2);

  rclc_init(argc, argv);

  ros2_log_add_event(APP_CREATE_NODE);
  rclc_node_t* node = rclc_create_node("talker", "");

  ros2_log_add_event(APP_CREATE_PUBLISHER);
  rclc_publisher_t* pub = rclc_create_publisher(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "chatter", 1);

  std_msgs__msg__String msg;
  char buff[64] = {0};
  msg.data.data = buff;
  msg.data.capacity = sizeof(buff);
  msg.data.size = 0;
  
  int i = 0;

  xtimer_sleep(3);

  for (int i = 0 ; rclc_ok() && i < 50 ; i++) {
    msg.data.size = snprintf(msg.data.data, msg.data.capacity, "Hello World: %i", i+1);
    if(msg.data.size > msg.data.capacity) msg.data.size = 0;

    if(msg.data.data[msg.data.size] == '\0') {
      printf("Publishing: '%s'\n", msg.data.data);
    }

    ros2_log_add_event(APP_PUBLISH);
    rclc_publish(pub, (const void*)&msg);

    rclc_spin_node_once(node, 100);
  }

  ros2_log_print();
  ros2_log_reset();

  while(1);
    
  rclc_destroy_publisher(pub);
  rclc_destroy_node(node);
  return 0;
}
