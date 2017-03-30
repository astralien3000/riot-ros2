// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__GET_PARAMETERS__RESPONSE__STRUCT_H_
#define RCL_INTERFACES__SRV__GET_PARAMETERS__RESPONSE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// values
#include "rcl_interfaces/msg/parameter_value__struct.h"

/// Struct of message rcl_interfaces/GetParameters_Response
typedef struct rcl_interfaces__srv__GetParameters_Response
{
  rcl_interfaces__msg__ParameterValue__Array values;
} rcl_interfaces__srv__GetParameters_Response;

/// Struct for an array of messages
typedef struct rcl_interfaces__srv__GetParameters_Response__Array
{
  rcl_interfaces__srv__GetParameters_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__srv__GetParameters_Response__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__GET_PARAMETERS__RESPONSE__STRUCT_H_
