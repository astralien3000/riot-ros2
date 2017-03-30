// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_H_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// new_parameters
// changed_parameters
// deleted_parameters
#include "rcl_interfaces/msg/parameter_descriptor__struct.h"

/// Struct of message rcl_interfaces/ParameterEventDescriptors
typedef struct rcl_interfaces__msg__ParameterEventDescriptors
{
  rcl_interfaces__msg__ParameterDescriptor__Array new_parameters;
  rcl_interfaces__msg__ParameterDescriptor__Array changed_parameters;
  rcl_interfaces__msg__ParameterDescriptor__Array deleted_parameters;
} rcl_interfaces__msg__ParameterEventDescriptors;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__ParameterEventDescriptors__Array
{
  rcl_interfaces__msg__ParameterEventDescriptors * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__ParameterEventDescriptors__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_H_
