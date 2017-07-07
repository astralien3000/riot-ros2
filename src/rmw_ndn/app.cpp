#include "app.hpp"

#include "sub.hpp"
#include "pub.hpp"

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

using namespace rmw::ndn;

static const uint8_t ecc_key_pri[] = {
  0x38, 0x67, 0x54, 0x73, 0x8B, 0x72, 0x4C, 0xD6,
  0x3E, 0xBD, 0x52, 0xF3, 0x64, 0xD8, 0xF5, 0x7F,
  0xB5, 0xE6, 0xF2, 0x9F, 0xC2, 0x7B, 0xD6, 0x90,
  0x42, 0x9D, 0xC8, 0xCE, 0xF0, 0xDE, 0x75, 0xB3
};

static int _on_data(ndn_block_t* interest, ndn_block_t* data);
static int _on_interest(ndn_block_t* interest);

Application& Application::instance(void) {
  static Application ret;
  return ret;
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

void Application::add_publisher(Publisher* pub) {
  instance()._pubs.push_back(pub);

  char prefix[64] = { 0 };
  snprintf(prefix, 32, "/%s", pub->get_topic_name());
  ndn_shared_block_t* sp = ndn_name_from_uri(prefix, strlen(prefix));
  if (sp == NULL) {
    return;
  }

  // pass ownership of "sp" to the API
  if (ndn_app_register_prefix(instance()._app, sp, _on_interest) != 0) {
    return;
  }
}

void Application::rm_publisher(Publisher* pub) {
  auto rm = instance()._pubs.end();
  for(auto it = instance()._pubs.begin() ; it != instance()._pubs.end() ; it++) {
    if((*it) == pub) {
      rm = it;
      break;
    }
  }
  instance()._pubs.erase(rm);
}

void Application::create(void) {
  if(instance()._app != NULL) {
    destroy();
  }
  instance()._app = ndn_app_create();
}

void Application::destroy(void) {
  if(instance()._app != NULL) {
    ndn_app_destroy(instance()._app);
    instance()._app = NULL;
  }
}

void Application::update(void) {
  ndn_app_run_once(instance()._app);
  for(auto it = instance()._subs.begin() ; it != instance()._subs.end() ; it++) {
    (*it)->update();
  }
}

void Application::send_sync_interest(const char* topic, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/sync/%lu", topic, random_uint32());
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(instance()._app, &sin->block, NULL, lifetime,
                           _on_data, NULL);
  ndn_shared_block_release(sin);
}

void Application::send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/%u", topic, seq);
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(instance()._app, &sin->block, NULL, lifetime,
                           _on_data, NULL);
  ndn_shared_block_release(sin);
}

std::vector<Subscription*>::iterator Application::begin_subscriptions(void) {
  return instance()._subs.begin();
}

std::vector<Subscription*>::iterator Application::end_subscriptions(void) {
  return instance()._subs.end();
}

std::vector<Publisher*>::iterator Application::begin_publisher(void) {
  return instance()._pubs.begin();
}

std::vector<Publisher*>::iterator Application::end_publisher(void) {
  return instance()._pubs.end();
}

void Application::publish(const char* topic, unsigned int seq, const char* data) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/%u", topic, seq);
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sdn = ndn_name_from_uri(uri, strlen(uri));
  if (sdn == NULL) {
    DEBUG("ERROR : ndn_name_from_uri\n");
    return;
  }

  ndn_metainfo_t meta = { NDN_CONTENT_TYPE_BLOB, -1 };

  ndn_block_t content = { (const uint8_t*)data, (int)(strlen(data)+1) };

  ndn_shared_block_t* sd =
      ndn_data_create(&sdn->block, &meta, &content,
                      NDN_SIG_TYPE_HMAC_SHA256, NULL,
                      ecc_key_pri, sizeof(ecc_key_pri));
  if (sd == NULL) {
    DEBUG("ERROR : ndn_data_create\n");
    return;
  }

  ndn_shared_block_release(sdn);

  // pass ownership of "sd" to the API
  if (ndn_app_put_data(instance()._app, sd) != 0) {
    DEBUG("ERROR : ndn_app_put_data\n");
    return;
  }
}

int _on_data(ndn_block_t* interest, ndn_block_t* data) {
  ndn_block_t name;
  int r = ndn_data_get_name(data, &name);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  DEBUG("Data received ");
#if ENABLE_DEBUG
  ndn_name_print(&name);
#endif
  DEBUG("\n");

  ndn_block_t content;
  r = ndn_data_get_content(data, &content);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  DEBUG("content : [%s]\n", (const char*)(content.buf+2));

  const char* tmp_data = (const char*)(content.buf+2);
  for(auto it = Application::begin_subscriptions() ; it != Application::end_subscriptions() ; it++) {
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

int send_sync(ndn_block_t& name, unsigned int seq, const char* data) {
  DEBUG("send_sync(%u, %s)\n", seq, data);
  DEBUG("strlen(data) = %u\n", strlen(data));

  char strseq[32] = {0};
  sprintf(strseq, "%i", (int)seq);
  ndn_shared_block_t* sdn = ndn_name_append(&name, (const uint8_t*)strseq, strlen(strseq));

  if (sdn == NULL) {
    DEBUG("ERROR\n");
    return NDN_APP_ERROR;
  }

  ndn_metainfo_t meta = { NDN_CONTENT_TYPE_BLOB, -1 };

  ndn_block_t content = { (const uint8_t*)data, (int)(strlen(data)+1) };

  ndn_shared_block_t* sd =
      ndn_data_create(&sdn->block, &meta, &content,
                      NDN_SIG_TYPE_HMAC_SHA256, NULL,
                      ecc_key_pri, sizeof(ecc_key_pri));

  if (sd == NULL) {
    ndn_shared_block_release(sdn);
    DEBUG("ERROR\n");
    return NDN_APP_ERROR;
  }

  ndn_shared_block_release(sdn);

  // pass ownership of "sd" to the API
  if (ndn_app_put_data(Application::get_app(), sd) != 0) {
    DEBUG("ERROR\n");
    return NDN_APP_ERROR;
  }

  return NDN_APP_CONTINUE;
}

int _on_interest(ndn_block_t* interest)
{
  ndn_block_t name;
  if (ndn_interest_get_name(interest, &name) != 0) {
    return NDN_APP_ERROR;
  }

  DEBUG("Interest received");
#if ENABLE_DEBUG
  ndn_name_print(&name);
#endif
  DEBUG("\n");

  for(auto it = Application::begin_publisher() ; it != Application::end_publisher() ; it++) {
    char uri[32] = {0};
    snprintf(uri, sizeof(uri), "/%s", (*it)->get_topic_name());

    ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
    if (sin == NULL) {
      DEBUG("ERROR\n");
      continue;
    }

    if(ndn_name_compare_block(&name, &(sin->block)) == 2) {
      ndn_name_component_t comp;
      ndn_name_get_component_from_block(&name, ndn_name_get_size_from_block(&sin->block), &comp);
      if(strncmp("sync", (const char*)comp.buf, strlen("sync")) == 0) {
        DEBUG("SYNC\n");
        unsigned int seq = 0;
        const char* data = NULL;
        (*it)->get_sync_data(&seq, &data);
        if(data != NULL) {
          send_sync(name, seq, data);
        }
      }
      else {
        DEBUG("DATA\n");
        ndn_name_component_t comp;
        ndn_name_get_component_from_block(&name, ndn_name_get_size_from_block(&name)-1, &comp);
        unsigned int seq = atoi((const char*)comp.buf);
        (*it)->on_interest(seq);
      }
    }

    ndn_shared_block_release(sin);
  }

  return NDN_APP_CONTINUE;
}
