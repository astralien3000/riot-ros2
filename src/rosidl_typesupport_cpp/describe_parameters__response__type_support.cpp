// generated from rosidl_typesupport_cpp/resource/msg__type_support.cpp.em
// generated code does not contain a copyright notice

#include <cstddef>

#include "rosidl_generator_c/message_type_support_struct.h"

#include "rcl_interfaces/srv/describe_parameters__response__struct.hpp"

#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
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

static const _type_support_ids_t _DescribeParameters_Response_message_typesupport_ids = {
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

static const _type_support_symbol_names_t _DescribeParameters_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rcl_interfaces, srv, DescribeParameters_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_opensplice_cpp, rcl_interfaces, srv, DescribeParameters_Response)),
  }
};

typedef struct _type_support_data_t
{
  void * data[2];
} _type_support_data_t;

static _type_support_data_t _DescribeParameters_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DescribeParameters_Response_message_typesupport_map = {
  2,
  "rcl_interfaces",
  &_DescribeParameters_Response_message_typesupport_ids.typesupport_identifier[0],
  &_DescribeParameters_Response_message_typesupport_symbol_names.symbol_name[0],
  &_DescribeParameters_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DescribeParameters_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DescribeParameters_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace rcl_interfaces


namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rcl_interfaces::srv::DescribeParameters_Response>()
{
  return &::rcl_interfaces::srv::rosidl_typesupport_cpp::DescribeParameters_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
