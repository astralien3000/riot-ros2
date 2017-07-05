#ifndef TIMER_HPP
#define TIMER_HPP

#include <xtimer.h>

class Timer {
public:
  using us = uint32_t;

public:
  static us now(void) { return xtimer_now_usec(); } // in us
};

#endif//TIMER_HPP
