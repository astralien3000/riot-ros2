#include "app.hpp"

#include "sub.hpp"

#include <ndn-riot/app.h>
#include <ndn-riot/ndn.h>
#include <ndn-riot/encoding/name.h>
#include <ndn-riot/encoding/interest.h>
#include <ndn-riot/encoding/data.h>
#include <ndn-riot/msg-type.h>

#include <random.h>
#include <stdio.h>
#include <string.h>

#define ENABLE_DEBUG 1
#include <debug.h>

static int ndn_app_on_data(ndn_block_t* interest, ndn_block_t* data);

rmw::ndn::Application& rmw::ndn::Application::instance(void) {
  static rmw::ndn::Application ret;
  return ret;
}

void rmw::ndn::Application::add_subscription(Subscription* sub) {
  instance()._subs.push_back(sub);
}

void rmw::ndn::Application::rm_subscription(Subscription* sub) {
  auto rm = instance()._subs.end();
  for(auto it = instance()._subs.begin() ; it != instance()._subs.end() ; it++) {
    if((*it) == sub) {
      rm = it;
      break;
    }
  }
  instance()._subs.erase(rm);
}

extern "C" ndn_app_t* app;

void rmw::ndn::Application::create(void) {
  if(instance()._app != NULL) {
    destroy();
  }
  instance()._app = ndn_app_create();
  app = instance()._app;
}

void rmw::ndn::Application::destroy(void) {
  if(instance()._app != NULL) {
    ndn_app_destroy(instance()._app);
    instance()._app = NULL;
  }
  app = instance()._app;
}

void rmw::ndn::Application::update(void) {
  ndn_app_run_once(instance()._app);
  for(auto it = instance()._subs.begin() ; it != instance()._subs.end() ; it++) {
    (*it)->update();
  }
}

void rmw::ndn::Application::send_sync_interest(const char* topic, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/sync/%lu", topic, random_uint32());
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                           ndn_app_on_data, NULL);
  ndn_shared_block_release(sin);
}

void rmw::ndn::Application::send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/%lu", topic, seq);
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                           ndn_app_on_data, NULL);
  ndn_shared_block_release(sin);
}

std::vector<rmw::ndn::Subscription*>::iterator rmw::ndn::Application::begin_subscriptions(void) {
  return instance()._subs.begin();
}

std::vector<rmw::ndn::Subscription*>::iterator rmw::ndn::Application::end_subscriptions(void) {
  return instance()._subs.end();
}

static int ndn_app_on_data(ndn_block_t* interest, ndn_block_t* data) {
  ndn_block_t name;
  int r = ndn_data_get_name(data, &name);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  DEBUG("Data received");
#if ENABLE_DEBUG
  ndn_name_print(&name);
#endif
  DEBUG("\n");

  ndn_block_t content;
  r = ndn_data_get_content(data, &content);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  const char* tmp_data = (const char*)(content.buf+2);
  static unsigned int seq = 10;
  for(auto it = rmw::ndn::Application::begin_subscriptions() ; it != rmw::ndn::Application::end_subscriptions() ; it++) {
    char uri[32] = {0};
    snprintf(uri, sizeof(uri), "/%s", (*it)->get_topic_name());

    ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
    if (sin == NULL) {
      DEBUG("ERROR\n");
      continue;
    }

    if(ndn_name_compare_block(&name, &(sin->block)) == 2) {
      ndn_name_component_t comp;
      ndn_name_get_component_from_block(&name, ndn_name_get_size_from_block(&name)-1, &comp);
      unsigned int seq = atoi((const char*)comp.buf);
      (*it)->push_data(seq, tmp_data);
    }

    ndn_shared_block_release(sin);
  }

  return NDN_APP_CONTINUE;
}
