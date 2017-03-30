// generated from rosidl_typesupport_cpp/resource/srv__type_support.cpp.em
// generated code does not contain a copyright notice

#include <cstddef>

#include "rosidl_generator_c/service_type_support.h"

#include "rcl_interfaces/srv/get_parameter_types__struct.hpp"

#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/type_support_map.h"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rcl_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _type_support_ids_t
{
  const char * typesupport_identifier[2];
} _type_support_ids_t;

static const _type_support_ids_t _GetParameterTypes_service_typesupport_ids = {
  {
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
    "rosidl_typesupport_opensplice_cpp",  // ::rosidl_typesupport_opensplice_cpp::typesupport_identifier,
  }
};

typedef struct _type_support_symbol_names_t
{
  const char * symbol_name[2];
} _type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _type_support_symbol_names_t _GetParameterTypes_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rcl_interfaces, GetParameterTypes)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_opensplice_cpp, rcl_interfaces, GetParameterTypes)),
  }
};

typedef struct _type_support_data_t
{
  void * data[2];
} _type_support_data_t;

static _type_support_data_t _GetParameterTypes_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetParameterTypes_service_typesupport_map = {
  2,
  "rcl_interfaces",
  &_GetParameterTypes_service_typesupport_ids.typesupport_identifier[0],
  &_GetParameterTypes_service_typesupport_symbol_names.symbol_name[0],
  &_GetParameterTypes_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetParameterTypes_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetParameterTypes_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace rcl_interfaces


namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<rcl_interfaces::srv::GetParameterTypes>()
{
  return &::rcl_interfaces::srv::rosidl_typesupport_cpp::GetParameterTypes_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
