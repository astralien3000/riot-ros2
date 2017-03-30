// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS__RESPONSE__STRUCT_H_
#define RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS__RESPONSE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// descriptors
#include "rcl_interfaces/msg/parameter_descriptor__struct.h"

/// Struct of message rcl_interfaces/DescribeParameters_Response
typedef struct rcl_interfaces__srv__DescribeParameters_Response
{
  rcl_interfaces__msg__ParameterDescriptor__Array descriptors;
} rcl_interfaces__srv__DescribeParameters_Response;

/// Struct for an array of messages
typedef struct rcl_interfaces__srv__DescribeParameters_Response__Array
{
  rcl_interfaces__srv__DescribeParameters_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__srv__DescribeParameters_Response__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__SRV__DESCRIBE_PARAMETERS__RESPONSE__STRUCT_H_
