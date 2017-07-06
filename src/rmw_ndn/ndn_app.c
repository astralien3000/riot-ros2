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

void app_on_data(const char* data);

int ndn_app_on_data(ndn_block_t* interest, ndn_block_t* data) {
  DEBUG("Data received\n");

  ndn_block_t name;
  int r = ndn_data_get_name(data, &name);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  ndn_block_t content;
  r = ndn_data_get_content(data, &content);
  if(r != 0) {
    return NDN_APP_ERROR;
  }

  app_on_data((const char*)(content.buf+2));
  //strncpy(fake_buffer, (const char*)(content.buf+2), (size_t)content.buf[1]);
  //fake_buffer[((size_t)content.buf[1])] = 0;
  //fake_new = true;

  //_seq_num++;
  //_ndn_send_topic_interest();

  return NDN_APP_CONTINUE;
}

void ndn_app_send_sync_interest(ndn_app_t* app, const char* topic, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/sync/%lu", topic, random_uint32());
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    // error
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                           ndn_app_on_data, NULL);
  ndn_shared_block_release(sin);
}

void ndn_app_send_data_interest(ndn_app_t* app, const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/%lu", topic, seq);
  DEBUG("Send interest %s\n", uri);

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    // error
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                           ndn_app_on_data, NULL);
  ndn_shared_block_release(sin);
}
