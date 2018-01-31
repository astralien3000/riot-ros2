#include "sub.hpp"

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

using namespace rmw::mqtt;

static void on_pub(const emcute_topic_t *topic, void *data, size_t len) {
    char *in = (char *)data;

    DEBUG("got publication for topic '%s' [%i] : %s\n", topic->name, (int)topic->id, in);
    in[len] = 0; // dirty
    
    for(auto it = Application::begin_subscriptions() ; it != Application::end_subscriptions() ; it++) {
      if(strcmp((*it)->get_topic_name(), topic->name) == 0) {
        (*it)->push_data((const char*)data);
      }
    }
}

Subscription::Subscription(const char* topic) {
  unsigned flags = EMCUTE_QOS_0;
  
  sub.cb = on_pub;
  sub.topic.name = topic;
  
  if (emcute_sub(&sub, flags) != EMCUTE_OK) {
    printf("error: unable to subscribe to %s\n", topic);
    return;
  }
  
  Application::add_subscription(this);
  DEBUG("Now subscribed to %s\n", topic);
}

const char* Subscription::take(void) {
  if(_data.empty()) {
    return NULL;
  }

  const char* ret = _data.front();
  _data.erase(_data.begin());
  return ret;
}
