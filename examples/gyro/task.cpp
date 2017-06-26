#include "task.h"

#include "gyro.hpp"

#include "periph/timer.h"

#include <stdint.h>

#define TASK_TIMER      TIMER_DEV(0)
#define TASK_CHAN       (0)
#define TASK_TIMER_FERQ (1000000UL)
#define TASK_FREQ       (100UL)
#define TASK_TIMEOUT    (TASK_TIMER_FERQ/TASK_FREQ)

static uint32_t _counter = 0;

static inline const uint32_t count(const uint32_t freq) {
  return TASK_FREQ/freq;
}

static inline int _timer_set(void) {
  return timer_set(TASK_TIMER, TASK_CHAN, TASK_TIMEOUT);
}

template<class Singleton>
static inline void _update_singleton(void) {
  if(_counter % count(Singleton::instance().updater().FREQ) == 0) {
    Singleton::instance().updater().update();
  }
}

static void _update(void *arg, int chan) {
  _counter++;
  _timer_set();
  _update_singleton<Gyro>();
}

int task_init(void) {
  if(timer_init(TASK_TIMER, TASK_TIMER_FERQ, _update, NULL) < 0) {
    return -1;
  }

  if(_timer_set() < 0) {
    return -2;
  }

  return 0;
}
