#include <stdio.h>
#include <math.h>
#include <string.h>

#include <periph/pwm.h>
#include <xtimer.h>

#include <rclc/rclc.h>

#include <custom_msgs/msg/imu.h>
#include <custom_msgs/msg/drone_motors.h>

struct {
  pwm_t dev;
  uint8_t chan;
} config[4] = {
  { PWM_DEV(0), 0 },
  { PWM_DEV(0), 1 },
  { PWM_DEV(1), 0 },
  { PWM_DEV(1), 1 },
};

void chatter_callback(const void* v_msg)
{
  const custom_msgs__msg__DroneMotors* msg = (const custom_msgs__msg__DroneMotors*)v_msg;

  pwm_set(config[0].dev, config[0].chan, msg->motor1);
  pwm_set(config[1].dev, config[1].chan, msg->motor2);
  pwm_set(config[2].dev, config[2].chan, msg->motor3);
  pwm_set(config[3].dev, config[3].chan, msg->motor4);
}

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  pwm_init(config[0].dev, PWM_LEFT, 1000U, 256U);
  pwm_init(config[1].dev, PWM_LEFT, 1000U, 256U);
  pwm_init(config[2].dev, PWM_LEFT, 1000U, 256U);
  pwm_init(config[3].dev, PWM_LEFT, 1000U, 256U);

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("drone");
  rclc_subscription_t* sub =
      rclc_create_subscription(node, ROSIDL_GET_MSG_TYPE_SUPPORT(custom_msgs, DroneMotors), "motors", chatter_callback, 1, false);

  rclc_publisher_t* pub = rclc_create_publisher(node, ROSIDL_GET_MSG_TYPE_SUPPORT(custom_msgs, IMU), "imu", 1);

  custom_msgs__msg__IMU msg;

  while (rclc_ok()) {
    msg.acc_x = 0;
    msg.acc_y = 0;
    msg.acc_z = 0;

    msg.gyro_x = 0;
    msg.gyro_y = 0;
    msg.gyro_z = 0;

    msg.mag_x = 0;
    msg.mag_y = 0;
    msg.mag_z = 0;

    rclc_publish(pub, (const void*)&msg);
    rclc_sleep_ms(100);
  }

  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  
  return 0;
}
