#include "rmw/rmw.h"

#include <stdlib.h>

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

const char *
rmw_get_implementation_identifier(void)
{
  DEBUG("rmw_get_implementation_identifier" "\n");
  static const char * fake_impl_id = "rmw_ndn";
  return fake_impl_id;
}

rmw_ret_t
rmw_init(void)
{
  DEBUG("rmw_init" "\n");
  return RMW_RET_OK;
}

rmw_node_t *
rmw_create_node(const char * name, size_t domain_id)
{
  (void) name;
  (void) domain_id;
  DEBUG("rmw_create_node" "\n");
  rmw_node_t *node = (rmw_node_t *)malloc(sizeof(rmw_node_t));
  node->implementation_identifier = rmw_get_implementation_identifier();
  node->data = NULL;
  node->name = name;

  rmw::mqtt::Application::create();

  return node;
}

rmw_ret_t
rmw_destroy_node(rmw_node_t * node)
{
  DEBUG("rmw_destroy_node" "\n");
  free(node);
  rmw::mqtt::Application::destroy();
  return RMW_RET_OK;
}
