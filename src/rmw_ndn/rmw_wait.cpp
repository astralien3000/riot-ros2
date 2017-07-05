#include "rmw/rmw.h"

#include <stdlib.h>

#include <xtimer.h>

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

rmw_ret_t
rmw_wait(
    rmw_subscriptions_t * subscriptions,
    rmw_guard_conditions_t * guard_conditions,
    rmw_services_t * services,
    rmw_clients_t * clients,
    rmw_waitset_t * waitset,
    const rmw_time_t * wait_timeout)
{
  (void) subscriptions;
  (void) guard_conditions;
  (void) services;
  (void) clients;
  (void) waitset;
  (void) wait_timeout;
  DEBUG("rmw_wait" "\n");

  const uint32_t begin = xtimer_now_usec();
  const uint32_t timeout = wait_timeout->nsec/1000 + wait_timeout->sec*1000000;
  const uint32_t end = begin + timeout;
  do {
    thread_yield();
    rmw::ndn::Application::update();

    DEBUG("timeout: %ul\n", timeout);

    DEBUG("subscriptions:    %4i\n", (int)subscriptions->subscriber_count);
    for(size_t i = 0 ; i < subscriptions->subscriber_count ; i++) {
      DEBUG("\t[%i] => %p\n", (int)i, (void*)subscriptions->subscribers[i]);
      /*
      if(fake_new) {
        subscriptions->subscribers[i] = (void*)1;
        fake_new = false;
        return RMW_RET_OK;
      }
      */
    }

  } while(xtimer_now_usec() < end);

  return RMW_RET_OK;
}
