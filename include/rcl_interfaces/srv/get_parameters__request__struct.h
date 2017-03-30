// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__GET_PARAMETERS__REQUEST__STRUCT_H_
#define RCL_INTERFACES__SRV__GET_PARAMETERS__REQUEST__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// names
#include "rosidl_generator_c/string.h"

/// Struct of message rcl_interfaces/GetParameters_Request
typedef struct rcl_interfaces__srv__GetParameters_Request
{
  rosidl_generator_c__String__Array names;
} rcl_interfaces__srv__GetParameters_Request;

/// Struct for an array of messages
typedef struct rcl_interfaces__srv__GetParameters_Request__Array
{
  rcl_interfaces__srv__GetParameters_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__srv__GetParameters_Request__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__GET_PARAMETERS__REQUEST__STRUCT_H_
