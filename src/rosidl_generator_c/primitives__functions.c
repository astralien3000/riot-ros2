// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/primitives__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// string_value
// string_value_with_default
// fixed_length_string_value
// upper_bound_string_value
// unbound_string_value
#include "rosidl_generator_c/string_functions.h"

bool
rosidl_generator_c__msg__Primitives__init(rosidl_generator_c__msg__Primitives * msg)
{
  if (!msg) {
    return false;
  }
  // bool_value
  msg->bool_value = true;
  // byte_value
  // char_value
  // float32_value
  msg->float32_value = 1.125f;
  // float64_value
  // int8_value
  msg->int8_value = -5;
  // uint8_value
  msg->uint8_value = 23u;
  // int16_value
  // uint16_value
  // int32_value
  // uint32_value
  // int64_value
  // uint64_value
  // string_value
  rosidl_generator_c__String__init(&msg->string_value);
  // string_value_with_default
  rosidl_generator_c__String__init(&msg->string_value_with_default);
  {
    bool success = rosidl_generator_c__String__assign(&msg->string_value_with_default, "default");
    if (!success) {
      goto abort_init_0;
    }
  }
  // fixed_length_string_value
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__String__init(&msg->fixed_length_string_value[i]);
  }
  // upper_bound_string_value
  rosidl_generator_c__String__Array__init(&msg->upper_bound_string_value, 0);
  // unbound_string_value
  rosidl_generator_c__String__init(&msg->unbound_string_value);
  return true;
abort_init_0:
  return false;
}

void
rosidl_generator_c__msg__Primitives__fini(rosidl_generator_c__msg__Primitives * msg)
{
  if (!msg) {
    return;
  }
  // bool_value
  // byte_value
  // char_value
  // float32_value
  // float64_value
  // int8_value
  // uint8_value
  // int16_value
  // uint16_value
  // int32_value
  // uint32_value
  // int64_value
  // uint64_value
  // string_value
  rosidl_generator_c__String__fini(&msg->string_value);
  // string_value_with_default
  rosidl_generator_c__String__fini(&msg->string_value_with_default);
  // fixed_length_string_value
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__String__fini(&msg->fixed_length_string_value[i]);
  }
  // upper_bound_string_value
  rosidl_generator_c__String__Array__fini(&msg->upper_bound_string_value);
  // unbound_string_value
  rosidl_generator_c__String__fini(&msg->unbound_string_value);
}

rosidl_generator_c__msg__Primitives *
rosidl_generator_c__msg__Primitives__create()
{
  rosidl_generator_c__msg__Primitives * msg = (rosidl_generator_c__msg__Primitives *)malloc(sizeof(rosidl_generator_c__msg__Primitives));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Primitives));
  bool success = rosidl_generator_c__msg__Primitives__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Primitives__destroy(rosidl_generator_c__msg__Primitives * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Primitives__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Primitives__Array__init(rosidl_generator_c__msg__Primitives__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Primitives * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Primitives *)calloc(size, sizeof(rosidl_generator_c__msg__Primitives));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Primitives__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Primitives__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Primitives__Array__fini(rosidl_generator_c__msg__Primitives__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Primitives__fini(&array->data[i]);
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

rosidl_generator_c__msg__Primitives__Array *
rosidl_generator_c__msg__Primitives__Array__create(size_t size)
{
  rosidl_generator_c__msg__Primitives__Array * array = (rosidl_generator_c__msg__Primitives__Array *)malloc(sizeof(rosidl_generator_c__msg__Primitives__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Primitives__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Primitives__Array__destroy(rosidl_generator_c__msg__Primitives__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Primitives__Array__fini(array);
  }
  free(array);
}
