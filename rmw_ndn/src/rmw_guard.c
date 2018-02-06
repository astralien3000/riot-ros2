#include <rmw/rmw.h>

#include <stdlib.h>

#define ENABLE_DEBUG 0
#include <debug.h>

const rmw_guard_condition_t *
rmw_node_get_graph_guard_condition(const rmw_node_t * node)
{
  DEBUG("rmw_node_get_graph_guard_condition" "\n");
  rmw_guard_condition_t * ret = (rmw_guard_condition_t *)malloc(sizeof(rmw_guard_condition_t));
  ret->data = NULL;
  ret->implementation_identifier = rmw_get_implementation_identifier();
  return ret;
}

rmw_guard_condition_t *
rmw_create_guard_condition(void)
{
  DEBUG("rmw_create_guard_condition" "\n");
  rmw_guard_condition_t * ret = (rmw_guard_condition_t *)malloc(sizeof(rmw_guard_condition_t));
  ret->data = NULL;
  ret->implementation_identifier = rmw_get_implementation_identifier();
  return ret;
}

rmw_ret_t
rmw_destroy_guard_condition(rmw_guard_condition_t * guard_condition)
{
  DEBUG("rmw_destroy_guard_condition" "\n");
  free(guard_condition);
  return RMW_RET_OK;
}

rmw_ret_t
rmw_trigger_guard_condition(const rmw_guard_condition_t * guard_condition)
{
  (void) guard_condition;
  DEBUG("rmw_trigger_guard_condition" "\n");
  return RMW_RET_OK;
}
