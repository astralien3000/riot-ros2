#include "app.hpp"

#include "sub.hpp"

#include "net/ipv6/addr.h"
#include "net/gnrc/ipv6/netif.h"

#include "net/emcute.h"

#define ENABLE_DEBUG 1
#include <debug.h>

#define SC_NETIF_IPV6_DEFAULT_PREFIX_LEN (64)

#define EMCUTE_PORT (1883U)
#define EMCUTE_PRIO (THREAD_PRIORITY_MAIN - 1)

using namespace rmw::mqtt;

Application& Application::instance(void) {
  static Application ret;
  return ret;
}

static void *_emcute_thread(void *arg)
{
    emcute_run(EMCUTE_PORT, (const char*)arg);
    return NULL;
}

void Application::create(const char* name) {
  (void)name;
  
  kernel_pid_t dev = 5;

#ifdef MYADDR
  const char* addr_str = MYADDR;
  ipv6_addr_t addr;
  ipv6_addr_t* ifaddr;
  
  uint8_t prefix_len = SC_NETIF_IPV6_DEFAULT_PREFIX_LEN;
  
  if(ipv6_addr_from_str(&addr, addr_str) == NULL) {
    puts("error: unable to parse IPv6 address.");
    return;
  }
  
  uint8_t flags = GNRC_IPV6_NETIF_ADDR_FLAGS_NDP_AUTO | GNRC_IPV6_NETIF_ADDR_FLAGS_UNICAST;
  
  
  if((ifaddr = gnrc_ipv6_netif_add_addr(dev, &addr, prefix_len, flags)) == NULL) {
    puts("error: unable to add IPv6 address\n");
    return;
  }
  
  // Address shall be valid infinitely
  gnrc_ipv6_netif_addr_get(ifaddr)->valid = UINT32_MAX;
  // Address shall be preferred infinitely
  gnrc_ipv6_netif_addr_get(ifaddr)->preferred = UINT32_MAX;
  
  DEBUG("success: added %s/%d to interface %" PRIkernel_pid "\n", addr_str, prefix_len, dev);
#endif
  
  static char stack[THREAD_STACKSIZE_DEFAULT];
  thread_create(stack, sizeof(stack), EMCUTE_PRIO, 0, _emcute_thread, (void*)name, "emcute");
  
  DEBUG("emcute thread created\n");
  
  sock_udp_ep_t gw = {0};
  gw.family = AF_INET6;
  gw.port = 1885;
  
  if(ipv6_addr_from_str((ipv6_addr_t *)&gw.addr.ipv6, BROKERADDR) == NULL) {
    puts("error parsing IPv6 address");
    return;
  }
  
  if(emcute_con(&gw, true, NULL, NULL, 0, 0) != EMCUTE_OK) {
      printf("error: unable to connect to [%s]:%i\n", BROKERADDR, (int)gw.port);
  }
  
  DEBUG("Successfully connected to gateway at [%s]:%i\n", BROKERADDR, (int)gw.port);
}

void Application::destroy(void) {
  if(emcute_discon() != EMCUTE_OK) {
    puts("error: unable to disconnect");
  }
}

void Application::publish(const char* topic, const char* data) {
  emcute_topic_t t;
  unsigned flags = EMCUTE_QOS_0;
  
  const size_t len = strlen(data);

  t.name = topic;
  if(emcute_reg(&t) != EMCUTE_OK) {
    puts("error: unable to obtain topic ID");
    return;
  }
  
  if(emcute_pub(&t, data, len, flags) != EMCUTE_OK) {
    printf("error: unable to publish data to topic '%s [%i]'\n", t.name, (int)t.id);
    return;
  }
  
  DEBUG("Published %i bytes to topic '%s [%i]'\n", len, t.name, t.id);
}

void Application::add_subscription(Subscription* sub) {
  instance()._subs.push_back(sub);
}

void Application::rm_subscription(Subscription* sub) {
  auto rm = instance()._subs.end();
  for(auto it = instance()._subs.begin() ; it != instance()._subs.end() ; it++) {
    if((*it) == sub) {
      rm = it;
      break;
    }
  }
  instance()._subs.erase(rm);
}

std::vector<Subscription*>::iterator Application::begin_subscriptions(void) {
  return instance()._subs.begin();
}

std::vector<Subscription*>::iterator Application::end_subscriptions(void) {
  return instance()._subs.end();
}
