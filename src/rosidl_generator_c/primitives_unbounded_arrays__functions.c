// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/primitives_unbounded_arrays__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
#include "rosidl_generator_c/primitives_array_functions.h"

bool
rosidl_generator_c__msg__PrimitivesUnboundedArrays__init(rosidl_generator_c__msg__PrimitivesUnboundedArrays * msg)
{
  if (!msg) {
    return false;
  }
  // bool_array
  rosidl_generator_c__bool__Array__init(&msg->bool_array, 0);
  // byte_array
  rosidl_generator_c__byte__Array__init(&msg->byte_array, 0);
  // char_array
  rosidl_generator_c__char__Array__init(&msg->char_array, 0);
  // float32_array
  rosidl_generator_c__float32__Array__init(&msg->float32_array, 0);
  // float64_array
  rosidl_generator_c__float64__Array__init(&msg->float64_array, 0);
  // int8_array
  rosidl_generator_c__int8__Array__init(&msg->int8_array, 0);
  // int16_array
  rosidl_generator_c__int16__Array__init(&msg->int16_array, 0);
  // int32_array
  rosidl_generator_c__int32__Array__init(&msg->int32_array, 0);
  // int64_array
  rosidl_generator_c__int64__Array__init(&msg->int64_array, 0);
  // uint8_array
  rosidl_generator_c__uint8__Array__init(&msg->uint8_array, 0);
  // uint16_array
  rosidl_generator_c__uint16__Array__init(&msg->uint16_array, 0);
  // uint32_array
  rosidl_generator_c__uint32__Array__init(&msg->uint32_array, 0);
  // uint64_array
  rosidl_generator_c__uint64__Array__init(&msg->uint64_array, 0);
  return true;
}

void
rosidl_generator_c__msg__PrimitivesUnboundedArrays__fini(rosidl_generator_c__msg__PrimitivesUnboundedArrays * msg)
{
  if (!msg) {
    return;
  }
  // bool_array
  rosidl_generator_c__bool__Array__fini(&msg->bool_array);
  // byte_array
  rosidl_generator_c__byte__Array__fini(&msg->byte_array);
  // char_array
  rosidl_generator_c__char__Array__fini(&msg->char_array);
  // float32_array
  rosidl_generator_c__float32__Array__fini(&msg->float32_array);
  // float64_array
  rosidl_generator_c__float64__Array__fini(&msg->float64_array);
  // int8_array
  rosidl_generator_c__int8__Array__fini(&msg->int8_array);
  // int16_array
  rosidl_generator_c__int16__Array__fini(&msg->int16_array);
  // int32_array
  rosidl_generator_c__int32__Array__fini(&msg->int32_array);
  // int64_array
  rosidl_generator_c__int64__Array__fini(&msg->int64_array);
  // uint8_array
  rosidl_generator_c__uint8__Array__fini(&msg->uint8_array);
  // uint16_array
  rosidl_generator_c__uint16__Array__fini(&msg->uint16_array);
  // uint32_array
  rosidl_generator_c__uint32__Array__fini(&msg->uint32_array);
  // uint64_array
  rosidl_generator_c__uint64__Array__fini(&msg->uint64_array);
}

rosidl_generator_c__msg__PrimitivesUnboundedArrays *
rosidl_generator_c__msg__PrimitivesUnboundedArrays__create()
{
  rosidl_generator_c__msg__PrimitivesUnboundedArrays * msg = (rosidl_generator_c__msg__PrimitivesUnboundedArrays *)malloc(sizeof(rosidl_generator_c__msg__PrimitivesUnboundedArrays));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__PrimitivesUnboundedArrays));
  bool success = rosidl_generator_c__msg__PrimitivesUnboundedArrays__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__PrimitivesUnboundedArrays__destroy(rosidl_generator_c__msg__PrimitivesUnboundedArrays * msg)
{
  if (msg) {
    rosidl_generator_c__msg__PrimitivesUnboundedArrays__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__init(rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__PrimitivesUnboundedArrays * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__PrimitivesUnboundedArrays *)calloc(size, sizeof(rosidl_generator_c__msg__PrimitivesUnboundedArrays));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__PrimitivesUnboundedArrays__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__PrimitivesUnboundedArrays__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__fini(rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__PrimitivesUnboundedArrays__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array *
rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__create(size_t size)
{
  rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array * array = (rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array *)malloc(sizeof(rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__destroy(rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__PrimitivesUnboundedArrays__Array__fini(array);
  }
  free(array);
}
