#include "rcl/time.h"

#include "xtimer.h"

#include "./common.h"
#include "rcl/error_handling.h"

#define __WOULD_BE_NEGATIVE(seconds, subseconds) (seconds < 0 || (subseconds < 0 && seconds == 0))

rcl_ret_t
rcl_system_time_now(rcl_time_point_value_t * now)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(now, RCL_RET_INVALID_ARGUMENT);
  *now = xtimer_now_usec64();
  return RCL_RET_OK;
}

rcl_ret_t
rcl_steady_time_now(rcl_time_point_value_t * now)
{
  RCL_CHECK_ARGUMENT_FOR_NULL(now, RCL_RET_INVALID_ARGUMENT);
  *now = xtimer_now_usec64();
  return RCL_RET_OK;
}
