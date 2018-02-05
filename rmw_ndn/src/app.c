#include "app.h"

#include <ndn-riot/app.h>
#include <ndn-riot/ndn.h>
#include <ndn-riot/encoding/name.h>
#include <ndn-riot/encoding/interest.h>
#include <ndn-riot/encoding/data.h>
#include <ndn-riot/msg-type.h>

#include <list.h>

#include <random.h>
#include <stdio.h>
#include <string.h>

#define ENABLE_DEBUG 0
#include <debug.h>

typedef struct Application {
  ndn_app_t* _app;
  list_node_t _subs;
  list_node_t _pubs;
} Application;

static const uint8_t ecc_key_pri[] = {
  0x38, 0x67, 0x54, 0x73, 0x8B, 0x72, 0x4C, 0xD6,
  0x3E, 0xBD, 0x52, 0xF3, 0x64, 0xD8, 0xF5, 0x7F,
  0xB5, 0xE6, 0xF2, 0x9F, 0xC2, 0x7B, 0xD6, 0x90,
  0x42, 0x9D, 0xC8, 0xCE, 0xF0, 0xDE, 0x75, 0xB3
};

static int _on_data(ndn_block_t* interest, ndn_block_t* data);
static int _on_interest(ndn_block_t* interest);

static Application _instance;

void app_add_sub(sub_t* sub) {
  list_add(&_instance._subs, &sub->node);
}

void app_rm_sub(sub_t* sub) {
  list_remove(&_instance._subs, &sub->node);
}

void app_add_pub(pub_t* pub) {
  list_add(&_instance._pubs, &pub->node);

  char prefix[64] = { 0 };
  snprintf(prefix, 32, "%s", pub->_topic_name);
  ndn_shared_block_t* sp = ndn_name_from_uri(prefix, strlen(prefix));
  if (sp == NULL) {
    return;
  }

  // pass ownership of "sp" to the API
  if (ndn_app_register_prefix(_instance._app, sp, _on_interest) != 0) {
    return;
  }
}

void app_rm_pub(pub_t* pub) {
  list_remove(&_instance._pubs, &pub->node);
}

void app_create(void) {
  if(_instance._app != NULL) {
    app_destroy();
  }
  _instance._app = ndn_app_create();
}

void app_destroy(void) {
  if(_instance._app != NULL) {
    ndn_app_destroy(_instance._app);
    _instance._app = NULL;
  }
}

void app_update(void) {
  ndn_app_run_once(_instance._app);
  for(list_node_t* it = _instance._subs.next ; it != NULL ; it = it->next) {
    sub_update(container_of(it, sub_t, node));
  }
}

void app_send_sync_interest(const char* topic, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "%s/sync/%lu", topic, random_uint32());
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(_instance._app, &sin->block, NULL, lifetime,
                           _on_data, NULL);
  ndn_shared_block_release(sin);
}

void app_send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "%s/%u", topic, seq);
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DEBUG("ERROR\n");
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(_instance._app, &sin->block, NULL, lifetime,
                           _on_data, NULL);
  ndn_shared_block_release(sin);
}

void app_publish(const char* topic, unsigned int seq, const char* data, size_t size) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "%s/%u", topic, seq);
  DEBUG("Publish %s\n", uri);

  ndn_shared_block_t* sdn = ndn_name_from_uri(uri, strlen(uri));
  if (sdn == NULL) {
    DEBUG("ERROR : ndn_name_from_uri\n");
    return;
  }

  ndn_metainfo_t meta = { NDN_CONTENT_TYPE_BLOB, -1 };

  ndn_block_t content = { (const uint8_t*)data, (int)(size) };

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
  if (ndn_app_put_data(_instance._app, sd) != 0) {
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
  size_t tmp_size = (size_t)*(const char*)(content.buf+1);
  for(list_node_t* it = _instance._subs.next ; it != NULL ; it = it->next) {
    char uri[32] = {0};
    snprintf(uri, sizeof(uri), "%s", container_of(it, sub_t, node)->_topic_name);

    ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
    if (sin == NULL) {
      DEBUG("ERROR\n");
      continue;
    }

    if(ndn_name_compare_block(&name, &(sin->block)) == 2) {
      ndn_name_component_t comp;
      ndn_name_get_component_from_block(&name, ndn_name_get_size_from_block(&name)-1, &comp);
      unsigned int seq = atoi((const char*)comp.buf);
      sub_push_data(container_of(it, sub_t, node), seq, tmp_data, tmp_size);
    }

    ndn_shared_block_release(sin);
  }

  return NDN_APP_CONTINUE;
}

int send_sync(ndn_block_t name, unsigned int seq, const char* data, size_t size) {
  DEBUG("send_sync(%u, %s, %u)\n", seq, data, (unsigned int)size);

  char strseq[32] = {0};
  sprintf(strseq, "%i", (int)seq);
  ndn_shared_block_t* sdn = ndn_name_append(&name, (const uint8_t*)strseq, strlen(strseq));

  if (sdn == NULL) {
    DEBUG("ERROR\n");
    return NDN_APP_ERROR;
  }

  ndn_metainfo_t meta = { NDN_CONTENT_TYPE_BLOB, -1 };

  ndn_block_t content = { (const uint8_t*)data, (int)(size) };

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
  if (ndn_app_put_data(_instance._app, sd) != 0) {
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

  for(list_node_t* it = _instance._pubs.next ; it != NULL ; it = it->next) {
    char uri[32] = {0};
    snprintf(uri, sizeof(uri), "%s", container_of(it, pub_t, node)->_topic_name);

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
        size_t size = 0;
        pub_get_sync_data(container_of(it, pub_t, node), &seq, &data, &size);
        if(data != NULL) {
          send_sync(name, seq, data, size);
        }
      }
      else {
        DEBUG("DATA\n");
        ndn_name_component_t comp;
        ndn_name_get_component_from_block(&name, ndn_name_get_size_from_block(&name)-1, &comp);
        unsigned int seq = atoi((const char*)comp.buf);
        pub_on_interest(container_of(it, pub_t, node), seq);
      }
    }

    ndn_shared_block_release(sin);
  }

  return NDN_APP_CONTINUE;
}
