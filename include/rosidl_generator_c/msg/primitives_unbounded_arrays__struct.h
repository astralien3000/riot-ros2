// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__PRIMITIVES_UNBOUNDED_ARRAYS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__PRIMITIVES_UNBOUNDED_ARRAYS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// bool_array
// byte_array
// char_array
// float32_array
// float64_array
// int8_array
// int16_array
// int32_array
// int64_array
// uint8_array
// uint16_array
// uint32_array
// uint64_array
#include "rosidl_generator_c/primitives_array.h"

/// Struct of message rosidl_generator_c/PrimitivesUnboundedArrays
typedef struct rosidl_generator_c__msg__PrimitivesUnboundedArrays
{
  rosidl_generator_c__bool__Array bool_array;
  rosidl_generator_c__byte__Array byte_array;
  rosidl_generator_c__char__Array char_array;
  rosidl_generator_c__float32__Array float32_array;
  rosidl_generator_c__float64__Array float64_array;
  rosidl_generator_c__int8__Array int8_array;
  rosidl_generator_c__int16__Array int16_array;
  rosidl_generator_c__int32__Array int32_array;
  rosidl_generator_c__int64__Array int64_array;
  rosidl_generator_c__uint8__Array uint8_array;
  rosidl_generator_c__uint16__Array uint16_array;
  rosidl_generator_c__uint32__Array uint32_array;
  rosidl_generator_c__uint64__Array uint64_array;
} rosidl_generator_c__msg__PrimitivesUnboundedArrays;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array
{
  rosidl_generator_c__msg__PrimitivesUnboundedArrays * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__PRIMITIVES_UNBOUNDED_ARRAYS__STRUCT_H_
