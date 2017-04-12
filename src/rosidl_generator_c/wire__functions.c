// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/wire__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// cablegram1
#include "rosidl_generator_c/msg/telegram1__functions.h"
// cablegram2
#include "rosidl_generator_c/msg/telegram2__functions.h"

bool
rosidl_generator_c__msg__Wire__init(rosidl_generator_c__msg__Wire * msg)
{
  if (!msg) {
    return false;
  }
  // cablegram1
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__msg__Telegram1__init(&msg->cablegram1[i]);
  }
  // cablegram2
  rosidl_generator_c__msg__Telegram2__init(&msg->cablegram2);
  return true;
}

void
rosidl_generator_c__msg__Wire__fini(rosidl_generator_c__msg__Wire * msg)
{
  if (!msg) {
    return;
  }
  // cablegram1
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__msg__Telegram1__fini(&msg->cablegram1[i]);
  }
  // cablegram2
  rosidl_generator_c__msg__Telegram2__fini(&msg->cablegram2);
}

rosidl_generator_c__msg__Wire *
rosidl_generator_c__msg__Wire__create()
{
  rosidl_generator_c__msg__Wire * msg = (rosidl_generator_c__msg__Wire *)malloc(sizeof(rosidl_generator_c__msg__Wire));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Wire));
  bool success = rosidl_generator_c__msg__Wire__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Wire__destroy(rosidl_generator_c__msg__Wire * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Wire__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Wire__Array__init(rosidl_generator_c__msg__Wire__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Wire * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Wire *)calloc(size, sizeof(rosidl_generator_c__msg__Wire));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Wire__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Wire__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Wire__Array__fini(rosidl_generator_c__msg__Wire__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Wire__fini(&array->data[i]);
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

rosidl_generator_c__msg__Wire__Array *
rosidl_generator_c__msg__Wire__Array__create(size_t size)
{
  rosidl_generator_c__msg__Wire__Array * array = (rosidl_generator_c__msg__Wire__Array *)malloc(sizeof(rosidl_generator_c__msg__Wire__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Wire__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Wire__Array__destroy(rosidl_generator_c__msg__Wire__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Wire__Array__fini(array);
  }
  free(array);
}
