// generated from rosidl_generator_c/resource/msg__functions.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_VALUE__FUNCTIONS_H_
#define RCL_INTERFACES__MSG__PARAMETER_VALUE__FUNCTIONS_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "rcl_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rcl_interfaces/msg/parameter_value__struct.h"

/// Initialize rcl_interfaces/ParameterValue message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(rcl_interfaces__msg__ParameterValue)) before
 * or use rcl_interfaces__msg__ParameterValue__create() to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
bool
rcl_interfaces__msg__ParameterValue__init(rcl_interfaces__msg__ParameterValue * msg);

/// Finalize rcl_interfaces/ParameterValue message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
void
rcl_interfaces__msg__ParameterValue__fini(rcl_interfaces__msg__ParameterValue * msg);

/// Create rcl_interfaces/ParameterValue message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls rcl_interfaces__msg__ParameterValue__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
rcl_interfaces__msg__ParameterValue *
rcl_interfaces__msg__ParameterValue__create();

/// Destroy rcl_interfaces/ParameterValue message.
/**
 * It calls rcl_interfaces__msg__ParameterValue__fini() and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
void
rcl_interfaces__msg__ParameterValue__destroy(rcl_interfaces__msg__ParameterValue * msg);


/// Initialize array of rcl_interfaces/ParameterValue messages.
/**
 * It allocates the memory for the number of elements and
 * calls rcl_interfaces__msg__ParameterValue__init() for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
bool
rcl_interfaces__msg__ParameterValue__Array__init(rcl_interfaces__msg__ParameterValue__Array * array, size_t size);

/// Finalize array of rcl_interfaces/ParameterValue messages.
/**
 * It calls rcl_interfaces__msg__ParameterValue__fini() for each element of the array and
 * frees the memory for the number of elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
void
rcl_interfaces__msg__ParameterValue__Array__fini(rcl_interfaces__msg__ParameterValue__Array * array);

/// Create array of rcl_interfaces/ParameterValue messages.
/**
 * It allocates the memory for the array and
 * calls rcl_interfaces__msg__ParameterValue__Array__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
rcl_interfaces__msg__ParameterValue__Array *
rcl_interfaces__msg__ParameterValue__Array__create(size_t size);

/// Destroy array of rcl_interfaces/ParameterValue messages.
/**
 * It calls rcl_interfaces__msg__ParameterValue__Array__fini() on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rcl_interfaces
void
rcl_interfaces__msg__ParameterValue__Array__destroy(rcl_interfaces__msg__ParameterValue__Array * array);

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_VALUE__FUNCTIONS_H_
