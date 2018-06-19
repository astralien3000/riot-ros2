#include <rclc/rclc.h>

#include <std_msgs/msg/string.h>

#include <stdio.h>

#include "ros2_log.h"
#include "periph/gpio.h"
#include "xtimer.h"
#include "thread.h"

// SAMR21
#define SYNC_OUT_PIN GPIO_PIN(PA, 16)
#define SYNC_IN_PIN  GPIO_PIN(PA, 17)

// IOTLAB
//#define SYNC_IN_PIN  GPIO_PIN(PORT_A, 3)

void sync_cb(void* arg) {
  ros2_log_add_event(APP_SYNC);
}

char sync_toggle_thread_stack[THREAD_STACKSIZE_DEFAULT] = {0};

void sync_toggle_thread(void* arg) {
#ifdef SYNC_IN_PIN
  gpio_init_int(SYNC_IN_PIN, GPIO_IN, GPIO_BOTH, sync_cb, NULL);
#endif
  xtimer_sleep(1);

#ifdef SYNC_OUT_PIN
  xtimer_ticks32_t ticks = xtimer_now();
  gpio_init(SYNC_OUT_PIN, GPIO_OUT);
  gpio_clear(SYNC_OUT_PIN);

  while(1) {
    xtimer_periodic_wakeup(&ticks, 100000);
    if(SYNC_OUT_PIN != GPIO_UNDEF) {
      gpio_toggle(SYNC_OUT_PIN);
    }
  }
#endif
}

void chatter_callback(const void* v_msg)
{
  ros2_log_add_event(APP_SUB_RECV_CB);
  const std_msgs__msg__String* msg = v_msg;
  printf("I heard: [%s]\n", msg->data.data);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  xtimer_sleep(2);
  thread_create(sync_toggle_thread_stack, sizeof(sync_toggle_thread_stack), 0, 0, sync_toggle_thread, NULL, "sync");

  rclc_init(argc, argv);

  ros2_log_add_event(APP_CREATE_NODE);
  rclc_node_t* node = rclc_create_node("listener", "");

  ros2_log_add_event(APP_SUBSCRIBE);
  rclc_subscription_t* sub =
      rclc_create_subscription(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "chatter", chatter_callback, 1, false);
  
  for(int i = 0 ; i < 60 ; i++) {
    rclc_spin_node_once(node, 1000);
  }

  ros2_log_print();
  ros2_log_reset();

  while(1);
  
  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  return 0;
}
