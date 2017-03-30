// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_H_
#define RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// reason
#include "rosidl_generator_c/string.h"

/// Struct of message rcl_interfaces/SetParametersResult
typedef struct rcl_interfaces__msg__SetParametersResult
{
  bool successful;
  rosidl_generator_c__String reason;
} rcl_interfaces__msg__SetParametersResult;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__SetParametersResult__Array
{
  rcl_interfaces__msg__SetParametersResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__SetParametersResult__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_H_
