#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>

#include "task.h"
#include "gyro.hpp"

int main(void) {
  task_init();

  xtimer_sleep(1);
  Gyro::instance().start();

  while(1) {
    printf("%i\n", (int)(1000*Gyro::instance().angle().get()));
    xtimer_sleep(2);
  }
  
  return 0;
}
