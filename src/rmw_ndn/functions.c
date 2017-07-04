#include "rmw/rmw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "std_msgs/msg/string.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"

#include <ndn-riot/app.h>
#include <ndn-riot/ndn.h>
#include <ndn-riot/encoding/name.h>
#include <ndn-riot/encoding/interest.h>
#include <ndn-riot/encoding/data.h>
#include <ndn-riot/msg-type.h>

#include <thread.h>
#include <random.h>

#define ENABLE_DEBUG 0

#if ENABLE_DEBUG
#define DPUTS(str) puts(str)
#define DPRINTF(...) printf(__VA_ARGS__)
#define DPRINT(...) printf(__VA_ARGS__)
#else
#define DPUTS(str)
#define DPRINTF(...)
#define DPRINT(...)
#endif

static const char * fake_impl_id = "rmw_ndn";

static char fake_buffer[128] = { 0 };
static bool fake_new = false;

static ndn_app_t* app = NULL;

static const uint8_t ecc_key_pri[] = {
  0x38, 0x67, 0x54, 0x73, 0x8B, 0x72, 0x4C, 0xD6,
  0x3E, 0xBD, 0x52, 0xF3, 0x64, 0xD8, 0xF5, 0x7F,
  0xB5, 0xE6, 0xF2, 0x9F, 0xC2, 0x7B, 0xD6, 0x90,
  0x42, 0x9D, 0xC8, 0xCE, 0xF0, 0xDE, 0x75, 0xB3
};

static const uint8_t ecc_key_pub[] = {
  0x2C, 0x3C, 0x18, 0xCB, 0x31, 0x88, 0x0B, 0xC3,
  0x73, 0xF4, 0x4A, 0xD4, 0x3F, 0x8C, 0x80, 0x24,
  0xD4, 0x8E, 0xBE, 0xB4, 0xAD, 0xF0, 0x69, 0xA6,
  0xFE, 0x29, 0x12, 0xAC, 0xC1, 0xE1, 0x26, 0x7E,
  0x2B, 0x25, 0x69, 0x02, 0xD5, 0x85, 0x51, 0x4B,
  0x91, 0xAC, 0xB9, 0xD1, 0x19, 0xE9, 0x5E, 0x97,
  0x20, 0xBB, 0x16, 0x2A, 0xD3, 0x2F, 0xB5, 0x11,
  0x1B, 0xD1, 0xAF, 0x76, 0xDB, 0xAD, 0xB8, 0xCE
};

static char ndn_app_thread_stack[THREAD_STACKSIZE_MAIN];

const char *
rmw_get_implementation_identifier(void)
{
  DPUTS("rmw_get_implementation_identifier");
  return fake_impl_id;
}

rmw_ret_t
rmw_init(void)
{
  DPUTS("rmw_init");
  return RMW_RET_OK;
}

rmw_node_t *
rmw_create_node(const char * name, size_t domain_id)
{
  (void) name;
  (void) domain_id;
  DPUTS("rmw_create_node");
  rmw_node_t *node = (rmw_node_t *)malloc(sizeof(rmw_node_t));
  node->implementation_identifier = fake_impl_id;
  node->data = NULL;
  node->name = name;
  
  if(app == NULL) {
    app = ndn_app_create();
  }
  
  return node;
}

rmw_ret_t
rmw_destroy_node(rmw_node_t * node)
{
  (void) node;
  DPUTS("rmw_destroy_node");
  
  if(app != NULL) {
    ndn_app_destroy(app);
    app = NULL;
  }
  
  return RMW_RET_OK;
}

const rmw_guard_condition_t *
rmw_node_get_graph_guard_condition(const rmw_node_t * node)
{
  (void) node;
  DPUTS("rmw_node_get_graph_guard_condition");
  rmw_guard_condition_t * ret = (rmw_guard_condition_t *)malloc(sizeof(rmw_guard_condition_t));
  ret->data = NULL;
  ret->implementation_identifier = fake_impl_id;
  return ret;
}

static int _on_interest(ndn_block_t* interest)
{
  if(!fake_new) {
    return NDN_APP_CONTINUE;
  }
  fake_new = false;

  ndn_block_t in;
  if (ndn_interest_get_name(interest, &in) != 0) {
    DPRINT("server (pid=%" PRIkernel_pid "): cannot get name from interest"
                                         "\n", app->id);
    return NDN_APP_ERROR;
  }

  DPRINT("server (pid=%" PRIkernel_pid "): interest received, name=",
         app->id);
  //ndn_name_print(&in);
  //putchar('\n');

  ndn_shared_block_t* sdn = ndn_shared_block_create(&in);
  if (sdn == NULL) {
    DPRINT("server (pid=%" PRIkernel_pid "): cannot create name\n", app->id);
    return NDN_APP_ERROR;
  }

  ndn_metainfo_t meta = { NDN_CONTENT_TYPE_BLOB, -1 };

  ndn_block_t content = { (const uint8_t*)&fake_buffer, strlen(fake_buffer) };
  puts(fake_buffer);

  ndn_shared_block_t* sd =
      ndn_data_create(&sdn->block, &meta, &content,
                      NDN_SIG_TYPE_HMAC_SHA256, NULL,
                      ecc_key_pri, sizeof(ecc_key_pri));
  if (sd == NULL) {
    DPRINT("server (pid=%" PRIkernel_pid "): cannot create data block\n", app->id);
    ndn_shared_block_release(sdn);
    return NDN_APP_ERROR;
  }

  DPRINT("server (pid=%" PRIkernel_pid "): send data to NDN thread, name=", app->id);
  //ndn_name_print(&sdn->block);
  //putchar('\n');
  ndn_shared_block_release(sdn);

  // pass ownership of "sd" to the API
  if (ndn_app_put_data(app, sd) != 0) {
    DPRINT("server (pid=%" PRIkernel_pid "): cannot put data\n", app->id);
    return NDN_APP_ERROR;
  }

  DPRINT("server (pid=%" PRIkernel_pid "): return to the app\n", app->id);

  DPRINT("server (pid=%" PRIkernel_pid "): content length = %d\n", app->id, content.len);
  DPRINT("server (pid=%" PRIkernel_pid "): content = %lu\n", app->id, *(uint32_t*)content.buf);
  return NDN_APP_CONTINUE;
}

rmw_publisher_t *
rmw_create_publisher(
    const rmw_node_t * node,
    const rosidl_message_type_support_t * type_support,
    const char * topic_name,
    const rmw_qos_profile_t * qos_policies)
{
  (void) node;
  (void) type_support;
  (void) topic_name;
  (void) qos_policies;
  DPUTS("rmw_create_publisher");
  
  rmw_publisher_t * ret = (rmw_publisher_t *)malloc(sizeof(rmw_publisher_t));
  ret->data = NULL;
  ret->implementation_identifier = fake_impl_id;
  ret->topic_name = topic_name;
  
  char prefix[64] = { 0 };
  snprintf(prefix, 32, "/%s", topic_name);
  ndn_shared_block_t* sp = ndn_name_from_uri(prefix, strlen(prefix));
  if (sp == NULL) {
      DPRINT("server (pid=%" PRIkernel_pid "): cannot create name from uri \"%s\"\n", app->id, prefix);
      return NULL;
  }

  DPRINT("server (pid=%" PRIkernel_pid "): register prefix \"%s\"\n", app->id, prefix);
  // pass ownership of "sp" to the API
  if (ndn_app_register_prefix(app, sp, _on_interest) != 0) {
      DPRINT("server (pid=%" PRIkernel_pid "): failed to register prefix\n", app->id);
  }
      
  return ret;
}

rmw_ret_t
rmw_destroy_publisher(rmw_node_t * node, rmw_publisher_t * publisher)
{
  (void) node;
  (void) publisher;
  DPUTS("rmw_destroy_publisher");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_publish(const rmw_publisher_t * publisher, const void * ros_message)
{
  (void) publisher;
  (void) ros_message;
  DPUTS("rmw_publish");
  
  std_msgs__msg__String* msg = (std_msgs__msg__String*)ros_message;
  DPRINTF("msg: %s\n", msg->data.data);
  
  strcpy(fake_buffer, msg->data.data);
  fake_new = true;
  
  return RMW_RET_OK;
}

char _topic_name[32] = {0};
uint32_t _seq_num = 0;

static int _on_data(ndn_block_t* interest, ndn_block_t* data);
static int _on_timeout(ndn_block_t* interest);

static int _ndn_send_topic_interest(void)
{
  char uri[32] = {0};
  snprintf(uri, 32, "/%s/%lu", _topic_name, _seq_num);
  
  ndn_shared_block_t* sin = ndn_name_from_uri(uri, strlen(uri));
  if (sin == NULL) {
    DPRINT("client (pid=%" PRIkernel_pid "): cannot create name from uri \"%s\"\n", app->id, uri);
    return NDN_APP_ERROR;
  }
    
  uint32_t lifetime = 100;  // ms
  
  DPRINT("client (pid=%" PRIkernel_pid "): express interest, name=", app->id);
  //ndn_name_print(&sin->block);
  //putchar('\n');
  
  int r = ndn_app_express_interest(app, &sin->block, NULL, lifetime,
                                   _on_data, _on_timeout);
  ndn_shared_block_release(sin);
  if (r != 0) {
    DPRINT("client (pid=%" PRIkernel_pid "): failed to express interest\n", app->id);
    return NDN_APP_ERROR;
  }
  
  return NDN_APP_CONTINUE;
}

static int _on_data(ndn_block_t* interest, ndn_block_t* data)
{
  (void)interest;
  
  uint32_t end = xtimer_now_usec();
  
  ndn_block_t name;
  int r = ndn_data_get_name(data, &name);
  assert(r == 0);
  
  DPRINT("client (pid=%" PRIkernel_pid "): data received, name=", app->id);
  //ndn_name_print(&name);
  //putchar('\n');
  
  DPRINT("client (pid=%" PRIkernel_pid "): RTT=%"PRIu32"us\n", app->id, end - begin);
  
  ndn_block_t content;
  r = ndn_data_get_content(data, &content);
  assert(r == 0);
  
  strncpy(fake_buffer, (const char*)(content.buf+2), (size_t)content.buf[1]);
  fake_buffer[((size_t)content.buf[1])] = 0;
  fake_new = true;
  
  DPRINT("client (pid=%" PRIkernel_pid "): content length = %d\n", app->id, content.len);
  DPRINT("client (pid=%" PRIkernel_pid "): content = %s\n", app->id, content.buf+2);
  DPRINT("client (pid=%" PRIkernel_pid "): content(prefix) = %d %d\n", app->id, (int)content.buf[0], (int)content.buf[1]);

  /*
  r = ndn_data_verify_signature(data, ecc_key_pub, sizeof(ecc_key_pub));
  if (r != 0) {
    DPRINT("client (pid=%" PRIkernel_pid "): fail to verify signature\n", app->id);
  }
  else {
    DPRINT("client (pid=%" PRIkernel_pid "): signature valid\n", app->id);
  }
  */

  _seq_num++;
  _ndn_send_topic_interest();

  return NDN_APP_CONTINUE;
}

static int _on_timeout(ndn_block_t* interest)
{
  ndn_block_t name;
  int r = ndn_interest_get_name(interest, &name);
  assert(r == 0);
  
  DPRINT("client (pid=%" PRIkernel_pid "): interest timeout, name=", app->id);
  //ndn_name_print(&name);
  //putchar('\n');

  _seq_num++;
  _ndn_send_topic_interest();

  return NDN_APP_CONTINUE;
}

rmw_subscription_t *
rmw_create_subscription(
    const rmw_node_t * node,
    const rosidl_message_type_support_t * type_support,
    const char * topic_name,
    const rmw_qos_profile_t * qos_policies,
    bool ignore_local_publications)
{
  (void) node;
  (void) type_support;
  (void) topic_name;
  (void) qos_policies;
  (void) ignore_local_publications;
  DPUTS("rmw_create_subscription");
  rmw_subscription_t * ret = (rmw_subscription_t *)malloc(sizeof(rmw_subscription_t));
  ret->data = NULL;
  ret->implementation_identifier = fake_impl_id;
  ret->topic_name = topic_name;
  
  DPRINTF("type_support->typesupport_identifier: %s\n", type_support->typesupport_identifier);
  
  const rosidl_typesupport_introspection_c__MessageMembers *ts_data = (const rosidl_typesupport_introspection_c__MessageMembers *)type_support->data;
  
  DPRINTF("ts_data->package_name_: %s\n", ts_data->package_name_);
  DPRINTF("ts_data->message_name_: %s\n", ts_data->message_name_);
  DPRINTF("ts_data->member_count_: %i\n", (int)ts_data->member_count_);
  
  for(size_t i = 0 ; i < ts_data->member_count_ ; i++) {
    DPRINTF("ts_data->members_[%i]:\n", (int)i);
    DPRINTF("\tname_: %s\n", ts_data->members_[i].name_);
    DPRINTF("\tmembers_: %p\n", (void*)ts_data->members_[i].members_);
  }
  
  strcpy(_topic_name, topic_name);
  _ndn_send_topic_interest();
  
  return ret;
}

rmw_ret_t
rmw_destroy_subscription(rmw_node_t * node, rmw_subscription_t * subscription)
{
  (void) node;
  (void) subscription;
  DPUTS("rmw_destroy_subscription");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take(const rmw_subscription_t * subscription, void * ros_message, bool * taken)
{
  (void) subscription;
  (void) ros_message;
  (void) taken;
  DPUTS("rmw_take");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take_with_info(
    const rmw_subscription_t * subscription,
    void * ros_message,
    bool * taken,
    rmw_message_info_t * message_info)
{
  (void) subscription;
  (void) ros_message;
  (void) taken;
  (void) message_info;
  DPUTS("rmw_take_with_info");
  
  DPRINTF("subscription: %p\n", (void*)subscription);
  DPRINTF("subscription->data: %p\n", (void*)(subscription->data));
  DPRINTF("ros_message: %p\n", (void*)ros_message);
  DPRINTF("taken: %p\n", (void*)taken);
  DPRINTF("message_info: %p\n", (void*)message_info);
  
  *taken = true;
  
  std_msgs__msg__String* msg = (std_msgs__msg__String*)ros_message;
  msg->data.data = fake_buffer;
  msg->data.size = strlen(fake_buffer);
  
  return RMW_RET_OK;
}

rmw_client_t *
rmw_create_client(
    const rmw_node_t * node,
    const rosidl_service_type_support_t * type_support,
    const char * service_name,
    const rmw_qos_profile_t * qos_policies)
{
  (void) node;
  (void) type_support;
  (void) service_name;
  (void) qos_policies;
  DPUTS("rmw_create_client");
  return NULL;
}

rmw_ret_t
rmw_destroy_client(rmw_node_t * node, rmw_client_t * client)
{
  (void) node;
  (void) client;
  DPUTS("rmw_destroy_client");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_send_request(
    const rmw_client_t * client,
    const void * ros_request,
    int64_t * sequence_id)
{
  (void) client;
  (void) ros_request;
  (void) sequence_id;
  DPUTS("rmw_send_request");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take_response(
    const rmw_client_t * client,
    rmw_request_id_t * request_header,
    void * ros_response,
    bool * taken)
{
  (void) client;
  (void) request_header;
  (void) ros_response;
  (void) taken;
  DPUTS("rmw_take_response");
  return RMW_RET_OK;
}

rmw_service_t *
rmw_create_service(
    const rmw_node_t * node,
    const rosidl_service_type_support_t * type_support,
    const char * service_name,
    const rmw_qos_profile_t * qos_policies)
{
  (void) node;
  (void) type_support;
  (void) service_name;
  (void) qos_policies;
  DPUTS("rmw_create_service");
  return NULL;
}

rmw_ret_t
rmw_destroy_service(rmw_node_t * node, rmw_service_t * service)
{
  (void) node;
  (void) service;
  DPUTS("rmw_destroy_service");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take_request(
    const rmw_service_t * service,
    rmw_request_id_t * request_header,
    void * ros_request,
    bool * taken)
{
  (void) service;
  (void) request_header;
  (void) ros_request;
  (void) taken;
  DPUTS("rmw_take_request");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_send_response(
    const rmw_service_t * service,
    rmw_request_id_t * request_header,
    void * ros_response)
{
  (void) service;
  (void) request_header;
  (void) ros_response;
  DPUTS("rmw_send_response");
  return RMW_RET_OK;
}

rmw_guard_condition_t *
rmw_create_guard_condition(void)
{
  DPUTS("rmw_create_guard_condition");
  rmw_guard_condition_t * ret = (rmw_guard_condition_t *)malloc(sizeof(rmw_guard_condition_t));
  ret->data = NULL;
  ret->implementation_identifier = fake_impl_id;
  return ret;
}

rmw_ret_t
rmw_destroy_guard_condition(rmw_guard_condition_t * guard_condition)
{
  (void) guard_condition;
  DPUTS("rmw_destroy_guard_condition");
  free(guard_condition);
  return RMW_RET_OK;
}

rmw_ret_t
rmw_trigger_guard_condition(const rmw_guard_condition_t * guard_condition)
{
  (void) guard_condition;
  DPUTS("rmw_trigger_guard_condition");
  return RMW_RET_OK;
}

rmw_waitset_t *
rmw_create_waitset(size_t max_conditions)
{
  (void) max_conditions;
  DPUTS("rmw_create_waitset");
  rmw_waitset_t * ret = (rmw_waitset_t *)malloc(sizeof(rmw_waitset_t));
  ret->data = NULL;
  ret->guard_conditions = NULL;
  ret->implementation_identifier = fake_impl_id;
  return ret;
}

rmw_ret_t
rmw_destroy_waitset(rmw_waitset_t * waitset)
{
  (void) waitset;
  DPUTS("rmw_destroy_waitset");
  free(waitset);
  return RMW_RET_OK;
}

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
  DPUTS("rmw_wait");
  
  const uint32_t begin = xtimer_now_usec();
  const uint32_t timeout = wait_timeout->nsec/1000 + wait_timeout->sec*1000000;
  const uint32_t end = begin + timeout;
  do {
    thread_yield();
    ndn_app_run_once(app);

    DPRINTF("timeout: %ul\n", timeout);

    DPRINTF("subscriptions:    %4i\n", (int)subscriptions->subscriber_count);
    for(size_t i = 0 ; i < subscriptions->subscriber_count ; i++) {
      DPRINTF("\t[%i] => %p\n", (int)i, (void*)subscriptions->subscribers[i]);
      if(fake_new) {
        subscriptions->subscribers[i] = (void*)1;
        fake_new = false;
        return RMW_RET_OK;
      }
    }

    DPRINTF("guard_conditions: %4i\n", (int)guard_conditions->guard_condition_count);
    for(size_t i = 0 ; i < guard_conditions->guard_condition_count ; i++) {
      DPRINTF("\t[%i] => %p\n", (int)i, (void*)guard_conditions->guard_conditions[i]);
    }

    DPRINTF("services:         %4i\n", (int)services->service_count);
    for(size_t i = 0 ; i < services->service_count ; i++) {
      DPRINTF("\t[%i] => %p\n", (int)i, (void*)services->services[i]);
    }

    DPRINTF("clients:          %4i\n", (int)clients->client_count);
    for(size_t i = 0 ; i < clients->client_count ; i++) {
      DPRINTF("\t[%i] => %p\n", (int)i, (void*)clients->clients[i]);
    }
  } while(xtimer_now_usec() < end);

  return RMW_RET_OK;
}

rmw_ret_t
rmw_get_topic_names_and_types(
    const rmw_node_t * node,
    rmw_topic_names_and_types_t * topic_names_and_types)
{
  (void) node;
  (void) topic_names_and_types;
  DPUTS("rmw_get_topic_names_and_types");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_destroy_topic_names_and_types(
    rmw_topic_names_and_types_t * topic_names_and_types)
{
  (void) topic_names_and_types;
  DPUTS("rmw_destroy_topic_names_and_types");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_count_publishers(
    const rmw_node_t * node,
    const char * topic_name,
    size_t * count)
{
  (void) node;
  (void) topic_name;
  (void) count;
  DPUTS("rmw_count_publishers");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_count_subscribers(
    const rmw_node_t * node,
    const char * topic_name,
    size_t * count)
{
  (void) node;
  (void) topic_name;
  (void) count;
  DPUTS("rmw_count_subscribers");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_get_gid_for_publisher(const rmw_publisher_t * publisher, rmw_gid_t * gid)
{
  (void) publisher;
  (void) gid;
  DPUTS("rmw_get_gid_for_publisher");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_compare_gids_equal(const rmw_gid_t * gid1, const rmw_gid_t * gid2, bool * result)
{
  (void) gid1;
  (void) gid2;
  (void) result;
  DPUTS("rmw_compare_gids_equal");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_service_server_is_available(
    const rmw_node_t * node,
    const rmw_client_t * client,
    bool * is_available)
{
  (void) node;
  (void) client;
  (void) is_available;
  DPUTS("rmw_service_server_is_available");
  return RMW_RET_OK;
}
