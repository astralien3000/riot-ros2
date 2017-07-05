#include "app.hpp"

#include <random.h>
#include <stdio.h>
#include <string.h>

extern "C" {
typedef struct ndn_app_t ndn_app_t;

ndn_app_t* ndn_app_create(void);
void ndn_app_destroy(ndn_app_t* handle);
int ndn_app_run_once(ndn_app_t* handle);

typedef struct ndn_block_t ndn_block_t;
typedef int (*ndn_app_data_cb_t)(ndn_block_t* interest, ndn_block_t* data);
void ndn_app_send_sync_interest(ndn_app_t* app, const char* topic, unsigned int timeout, ndn_app_data_cb_t on_data);
int ndn_app_on_data(ndn_block_t* interest, ndn_block_t* data);
}

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

void rmw::ndn::Application::create(void) {
  if(instance()._app != NULL) {
    destroy();
  }
  instance()._app = ndn_app_create();
}

void rmw::ndn::Application::destroy(void) {
  if(instance()._app != NULL) {
    ndn_app_destroy(instance()._app);
    instance()._app = NULL;
  }
}

void rmw::ndn::Application::update(void) {
  ndn_app_run_once(instance()._app);
}

void rmw::ndn::Application::send_sync_interest(const char* topic, unsigned int timeout) {
  ndn_app_send_sync_interest(instance()._app, topic, timeout, ndn_app_on_data);
}

void rmw::ndn::Application::send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {

}

void rmw::ndn::Application::on_data(void) {

}
