#include <ndn-riot/app.h>
#include <ndn-riot/ndn.h>
#include <ndn-riot/encoding/name.h>
#include <ndn-riot/encoding/interest.h>
#include <ndn-riot/encoding/data.h>
#include <ndn-riot/msg-type.h>

#include <random.h>
#include <stdio.h>
#include <string.h>

void ndn_app_send_sync_interest(ndn_app_t* app, const char* topic, unsigned int timeout, ndn_app_data_cb_t on_data) {
  char uri[32] = {0};
  snprintf(uri, sizeof(uri), "/%s/sync/%lu", topic, random_uint32());

  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    // error
    return;
  }

  uint32_t lifetime = timeout/1000;  // ms
  ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                           on_data, NULL);
  ndn_shared_block_release(sin);
}

void ndn_app_send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {

}

int ndn_app_on_data(ndn_block_t* interest, ndn_block_t* data) {
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

  //strncpy(fake_buffer, (const char*)(content.buf+2), (size_t)content.buf[1]);
  //fake_buffer[((size_t)content.buf[1])] = 0;
  //fake_new = true;

  //_seq_num++;
  //_ndn_send_topic_interest();

  return NDN_APP_CONTINUE;
}
