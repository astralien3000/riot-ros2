// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/various__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// up_to_three_int32_values
// up_to_three_int32_values_with_default_values
// unbounded_uint64_values
#include "rosidl_generator_c/primitives_array_functions.h"
// empty
// two_empty
// unbounded_empty
#include "rosidl_generator_c/msg/empty__functions.h"
// nested
// two_nested
// up_to_three_nested
// unbounded_nested
#include "rosidl_generator_c/msg/nested__functions.h"

bool
rosidl_generator_c__msg__Various__init(rosidl_generator_c__msg__Various * msg)
{
  if (!msg) {
    return false;
  }
  // bool_value
  msg->bool_value = false;
  // byte_value
  // char_value
  // float32_value
  msg->float32_value = 1.23f;
  // float64_value
  // int8_value
  msg->int8_value = -5;
  // two_uint16_value
  msg->two_uint16_value[0] = 5u;
  msg->two_uint16_value[1] = 23u;
  // up_to_three_int32_values
  rosidl_generator_c__int32__Array__init(&msg->up_to_three_int32_values, 0);
  // up_to_three_int32_values_with_default_values
  {
    bool success = rosidl_generator_c__int32__Array__init(&msg->up_to_three_int32_values_with_default_values, 2);
    if (!success) {
      goto abort_init_0;
    }
  }
  msg->up_to_three_int32_values_with_default_values.data[0] = 5;
  msg->up_to_three_int32_values_with_default_values.data[1] = 23;
  // unbounded_uint64_values
  rosidl_generator_c__uint64__Array__init(&msg->unbounded_uint64_values, 0);
  // empty
  rosidl_generator_c__msg__Empty__init(&msg->empty);
  // two_empty
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Empty__init(&msg->two_empty[i]);
  }
  // unbounded_empty
  rosidl_generator_c__msg__Empty__Array__init(&msg->unbounded_empty, 0);
  // nested
  rosidl_generator_c__msg__Nested__init(&msg->nested);
  // two_nested
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Nested__init(&msg->two_nested[i]);
  }
  // up_to_three_nested
  rosidl_generator_c__msg__Nested__Array__init(&msg->up_to_three_nested, 0);
  // unbounded_nested
  rosidl_generator_c__msg__Nested__Array__init(&msg->unbounded_nested, 0);
  return true;
abort_init_0:
  return false;
}

void
rosidl_generator_c__msg__Various__fini(rosidl_generator_c__msg__Various * msg)
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
  // two_uint16_value
  // up_to_three_int32_values
  rosidl_generator_c__int32__Array__fini(&msg->up_to_three_int32_values);
  // up_to_three_int32_values_with_default_values
  rosidl_generator_c__int32__Array__fini(&msg->up_to_three_int32_values_with_default_values);
  // unbounded_uint64_values
  rosidl_generator_c__uint64__Array__fini(&msg->unbounded_uint64_values);
  // empty
  rosidl_generator_c__msg__Empty__fini(&msg->empty);
  // two_empty
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Empty__fini(&msg->two_empty[i]);
  }
  // unbounded_empty
  rosidl_generator_c__msg__Empty__Array__fini(&msg->unbounded_empty);
  // nested
  rosidl_generator_c__msg__Nested__fini(&msg->nested);
  // two_nested
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Nested__fini(&msg->two_nested[i]);
  }
  // up_to_three_nested
  rosidl_generator_c__msg__Nested__Array__fini(&msg->up_to_three_nested);
  // unbounded_nested
  rosidl_generator_c__msg__Nested__Array__fini(&msg->unbounded_nested);
}

rosidl_generator_c__msg__Various *
rosidl_generator_c__msg__Various__create()
{
  rosidl_generator_c__msg__Various * msg = (rosidl_generator_c__msg__Various *)malloc(sizeof(rosidl_generator_c__msg__Various));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Various));
  bool success = rosidl_generator_c__msg__Various__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Various__destroy(rosidl_generator_c__msg__Various * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Various__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Various__Array__init(rosidl_generator_c__msg__Various__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Various * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Various *)calloc(size, sizeof(rosidl_generator_c__msg__Various));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Various__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Various__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Various__Array__fini(rosidl_generator_c__msg__Various__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Various__fini(&array->data[i]);
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

rosidl_generator_c__msg__Various__Array *
rosidl_generator_c__msg__Various__Array__create(size_t size)
{
  rosidl_generator_c__msg__Various__Array * array = (rosidl_generator_c__msg__Various__Array *)malloc(sizeof(rosidl_generator_c__msg__Various__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Various__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Various__Array__destroy(rosidl_generator_c__msg__Various__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Various__Array__fini(array);
  }
  free(array);
}
