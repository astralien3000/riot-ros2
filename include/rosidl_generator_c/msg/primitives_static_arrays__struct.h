// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__PRIMITIVES_STATIC_ARRAYS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__PRIMITIVES_STATIC_ARRAYS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Struct of message rosidl_generator_c/PrimitivesStaticArrays
typedef struct rosidl_generator_c__msg__PrimitivesStaticArrays
{
  bool bool_array[7];
  uint8_t byte_array[7];
  char char_array[7];
  float float32_array[7];
  double float64_array[7];
  int8_t int8_array[7];
  int16_t int16_array[7];
  int32_t int32_array[7];
  int64_t int64_array[7];
  uint8_t uint8_array[7];
  uint16_t uint16_array[7];
  uint32_t uint32_array[7];
  uint64_t uint64_array[7];
} rosidl_generator_c__msg__PrimitivesStaticArrays;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__PrimitivesStaticArrays__Array
{
  rosidl_generator_c__msg__PrimitivesStaticArrays * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__PrimitivesStaticArrays__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__PRIMITIVES_STATIC_ARRAYS__STRUCT_H_
