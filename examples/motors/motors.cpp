#include "motors.hpp"

#include <periph/pwm.h>
#include <periph/gpio.h>

#define MODE        PWM_LEFT
#define FREQU       (1000U)
#define MAX_PWM     (256U)
#define MIN_PWM     (90U)

#define MOT_PWM   PWM_DEV(0)

#define MOT1_CHAN 0
#define MOT2_CHAN 1

#define MOT1_DIR1 GPIO_PIN(PA, 13)
#define MOT1_DIR2 GPIO_PIN(PA, 28)
#define MOT2_DIR1 GPIO_PIN(PB, 22)
#define MOT2_DIR2 GPIO_PIN(PB, 23)

#define MIN(a, b) ((a > b) ? b : a)

static inline void _pwm_set(pwm_t dev, uint8_t chan, uint16_t val) {
  if(val > 5) {
    pwm_set(dev, chan, MIN(val+MIN_PWM, MAX_PWM));
  }
  else {
    pwm_set(dev, chan, 0);
  }
}

void Motors::Left::put(int pwm) {
  if(state() == RUN) {
    if(pwm < 0) {
      gpio_set(MOT1_DIR2);
      gpio_clear(MOT1_DIR1);
      _pwm_set(MOT_PWM, MOT1_CHAN, -pwm);
    }
    else {
      gpio_set(MOT1_DIR1);
      gpio_clear(MOT1_DIR2);
      _pwm_set(MOT_PWM, MOT1_CHAN, pwm);
    }
  }
  else {
    gpio_clear(MOT1_DIR1);
    gpio_clear(MOT1_DIR2);
    _pwm_set(MOT_PWM, MOT1_CHAN, 0);
  }
}

void Motors::Right::put(int pwm) {
  if(state() == RUN) {
    if(pwm < 0) {
      gpio_set(MOT2_DIR2);
      gpio_clear(MOT2_DIR1);
      _pwm_set(MOT_PWM, MOT2_CHAN, -pwm);
    }
    else {
      gpio_set(MOT2_DIR1);
      gpio_clear(MOT2_DIR2);
      _pwm_set(MOT_PWM, MOT2_CHAN, pwm);
    }
  }
  else {
    gpio_clear(MOT2_DIR1);
    gpio_clear(MOT2_DIR2);
    _pwm_set(MOT_PWM, MOT1_CHAN, 0);
  }
}

Motors::Motors(void) {
  if(pwm_init(MOT_PWM, MODE, FREQU, MAX_PWM) == 0) {
    setState(ERROR);
    return;
  }

  if(gpio_init(MOT1_DIR1, GPIO_OUT) != 0) {
    setState(ERROR);
    return;
  }

  if(gpio_init(MOT1_DIR2, GPIO_OUT) != 0) {
    setState(ERROR);
    return;
  }

  if(gpio_init(MOT2_DIR1, GPIO_OUT) != 0) {
    setState(ERROR);
    return;
  }

  if(gpio_init(MOT2_DIR2, GPIO_OUT) != 0) {
    setState(ERROR);
    return;
  }

  left().put(0);
  right().put(0);
}
