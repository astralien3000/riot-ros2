#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>
#include "motors.hpp"

int main(void) {

  Motors::instance().start();
  //Motors::instance().left().put(-255);
  while(1) {
    Motors::instance().left().put(255);
    xtimer_sleep(2);
    Motors::instance().left().put(-255);
    xtimer_sleep(2);
  }
  
  return 0;
}
