// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__PRIMITIVES_BOUNDED_ARRAYS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__PRIMITIVES_BOUNDED_ARRAYS__STRUCT_H_

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

// constants for array fields with an upper bound
// bool_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__bool_array__MAX_SIZE = 8
};
// byte_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__byte_array__MAX_SIZE = 8
};
// char_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__char_array__MAX_SIZE = 8
};
// float32_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__float32_array__MAX_SIZE = 8
};
// float64_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__float64_array__MAX_SIZE = 8
};
// int8_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__int8_array__MAX_SIZE = 8
};
// int16_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__int16_array__MAX_SIZE = 8
};
// int32_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__int32_array__MAX_SIZE = 8
};
// int64_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__int64_array__MAX_SIZE = 8
};
// uint8_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__uint8_array__MAX_SIZE = 8
};
// uint16_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__uint16_array__MAX_SIZE = 8
};
// uint32_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__uint32_array__MAX_SIZE = 8
};
// uint64_array
enum
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays__uint64_array__MAX_SIZE = 8
};

/// Struct of message rosidl_generator_c/PrimitivesBoundedArrays
typedef struct rosidl_generator_c__msg__PrimitivesBoundedArrays
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
} rosidl_generator_c__msg__PrimitivesBoundedArrays;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__PrimitivesBoundedArrays__Array
{
  rosidl_generator_c__msg__PrimitivesBoundedArrays * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__PrimitivesBoundedArrays__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__PRIMITIVES_BOUNDED_ARRAYS__STRUCT_H_
