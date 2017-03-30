// generated from rosidl_generator_c/resource/msg__functions.h.em
// generated code does not contain a copyright notice

#ifndef BUILTIN_INTERFACES__MSG__TIME__FUNCTIONS_H_
#define BUILTIN_INTERFACES__MSG__TIME__FUNCTIONS_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "builtin_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "builtin_interfaces/msg/time__struct.h"

/// Initialize builtin_interfaces/Time message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(builtin_interfaces__msg__Time)) before
 * or use builtin_interfaces__msg__Time__create() to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
bool
builtin_interfaces__msg__Time__init(builtin_interfaces__msg__Time * msg);

/// Finalize builtin_interfaces/Time message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
void
builtin_interfaces__msg__Time__fini(builtin_interfaces__msg__Time * msg);

/// Create builtin_interfaces/Time message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls builtin_interfaces__msg__Time__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
builtin_interfaces__msg__Time *
builtin_interfaces__msg__Time__create();

/// Destroy builtin_interfaces/Time message.
/**
 * It calls builtin_interfaces__msg__Time__fini() and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
void
builtin_interfaces__msg__Time__destroy(builtin_interfaces__msg__Time * msg);


/// Initialize array of builtin_interfaces/Time messages.
/**
 * It allocates the memory for the number of elements and
 * calls builtin_interfaces__msg__Time__init() for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
bool
builtin_interfaces__msg__Time__Array__init(builtin_interfaces__msg__Time__Array * array, size_t size);

/// Finalize array of builtin_interfaces/Time messages.
/**
 * It calls builtin_interfaces__msg__Time__fini() for each element of the array and
 * frees the memory for the number of elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
void
builtin_interfaces__msg__Time__Array__fini(builtin_interfaces__msg__Time__Array * array);

/// Create array of builtin_interfaces/Time messages.
/**
 * It allocates the memory for the array and
 * calls builtin_interfaces__msg__Time__Array__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
builtin_interfaces__msg__Time__Array *
builtin_interfaces__msg__Time__Array__create(size_t size);

/// Destroy array of builtin_interfaces/Time messages.
/**
 * It calls builtin_interfaces__msg__Time__Array__fini() on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_builtin_interfaces
void
builtin_interfaces__msg__Time__Array__destroy(builtin_interfaces__msg__Time__Array * array);

#if __cplusplus
}
#endif

#endif  // BUILTIN_INTERFACES__MSG__TIME__FUNCTIONS_H_
