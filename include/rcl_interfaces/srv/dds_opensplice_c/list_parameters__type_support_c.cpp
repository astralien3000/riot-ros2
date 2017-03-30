// generated from rosidl_typesupport_opensplice_c/resource/srv__type_support_c.cpp.em
// generated code does not contain a copyright notice

#include <cstring>
#include <iostream>
#include <sstream>

// This is defined in the rosidl_typesupport_opensplice_c package and
// is in the include/rosidl_typesupport_opensplice_c/impl folder.
#include "rosidl_generator_c/message_type_support.h"
#include "rmw/rmw.h"

#include "rcl_interfaces/srv/list_parameters__request.h"
#include "rcl_interfaces/srv/list_parameters__response.h"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_ListParameters_Request_.h"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_ListParameters_Response_.h"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_Sample_ListParameters_Request_.h"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_Sample_ListParameters_Response_.h"
#include "rosidl_typesupport_opensplice_c/identifier.h"

#include "rcl_interfaces/srv/dds_opensplice/list_parameters__type_support.cpp"
#include "rcl_interfaces/msg/rosidl_generator_c__visibility_control.h"

#if defined(__cplusplus)
extern "C"
{
#endif

const char *
register_types__ListParameters(
  void * untyped_participant, const char * request_type_name, const char * response_type_name)
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::register_types__ListParameters(
    untyped_participant, request_type_name, response_type_name);
}

const char *
create_requester__ListParameters(
  void * untyped_participant, const char * service_name,
  void ** untyped_requester, void ** untyped_reader,
  const void * untyped_datareader_qos,
  const void * untyped_datawriter_qos,
  void * (*allocator)(size_t))
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::create_requester__ListParameters(
    untyped_participant, service_name,
    untyped_requester, untyped_reader,
    untyped_datareader_qos,
    untyped_datawriter_qos,
    allocator);
}

const char *
create_responder__ListParameters(
  void * untyped_participant, const char * service_name,
  void ** untyped_responder, void ** untyped_reader,
  const void * untyped_datareader_qos,
  const void * untyped_datawriter_qos,
  void * (*allocator)(size_t))
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::create_responder__ListParameters(
    untyped_participant, service_name,
    untyped_responder, untyped_reader,
    untyped_datareader_qos,
    untyped_datawriter_qos,
    allocator);
}

const char *
send_request__ListParameters(
  void * untyped_requester, const void * untyped_ros_request, int64_t * sequence_number)
{
  using SampleT = rosidl_typesupport_opensplice_cpp::Sample<rcl_interfaces::srv::dds_::ListParameters_Request_>;

  SampleT request;
  const rosidl_message_type_support_t * ts =
    ROSIDL_GET_TYPE_SUPPORT(rcl_interfaces, srv, ListParameters_Request);
  const message_type_support_callbacks_t * callbacks =
    static_cast<const message_type_support_callbacks_t *>(ts->data);
  callbacks->convert_ros_to_dds(untyped_ros_request, static_cast<void *>(&request.data()));

  using RequesterT = rosidl_typesupport_opensplice_cpp::Requester<
      rcl_interfaces::srv::dds_::ListParameters_Request_,
      rcl_interfaces::srv::dds_::ListParameters_Response_
      >;

  auto requester = reinterpret_cast<RequesterT *>(untyped_requester);

  const char * error_string = requester->send_request(request);
  if (error_string) {
    return error_string;
  }
  *sequence_number = request.sequence_number_;

  return nullptr;
}

const char *
take_request__ListParameters(
  void * untyped_responder, rmw_request_id_t * request_header, void * untyped_ros_request,
  bool * taken)
{
  using ResponderT = rosidl_typesupport_opensplice_cpp::Responder<
      rcl_interfaces::srv::dds_::ListParameters_Request_,
      rcl_interfaces::srv::dds_::ListParameters_Response_
      >;

  auto responder = reinterpret_cast<ResponderT *>(untyped_responder);

  rosidl_typesupport_opensplice_cpp::Sample<rcl_interfaces::srv::dds_::ListParameters_Request_> request;
  const char * error_string = responder->take_request(request, taken);
  if (error_string) {
    return error_string;
  }

  if (*taken) {
    const rosidl_message_type_support_t * ts =
      ROSIDL_GET_TYPE_SUPPORT(rcl_interfaces, srv, ListParameters_Request);
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(ts->data);
    callbacks->convert_dds_to_ros(static_cast<void *>(&request.data()), untyped_ros_request);

    request_header->sequence_number = request.sequence_number_;
    std::memcpy(
      &request_header->writer_guid[0], &request.client_guid_0_, sizeof(request.client_guid_0_));
    std::memcpy(
      &request_header->writer_guid[0] + sizeof(request.client_guid_0_),
      &request.client_guid_1_, sizeof(request.client_guid_1_));

    *taken = true;
    return nullptr;
  }
  *taken = false;
  return nullptr;
}

const char *
send_response__ListParameters(
  void * untyped_responder, const rmw_request_id_t * request_header,
  const void * untyped_ros_response)
{
  rosidl_typesupport_opensplice_cpp::Sample<rcl_interfaces::srv::dds_::ListParameters_Response_> response;
  const rosidl_message_type_support_t * ts =
    ROSIDL_GET_TYPE_SUPPORT(rcl_interfaces, srv, ListParameters_Response);
  const message_type_support_callbacks_t * callbacks =
    static_cast<const message_type_support_callbacks_t *>(ts->data);
  callbacks->convert_ros_to_dds(untyped_ros_response, static_cast<void *>(&response.data()));

  using ResponderT = rosidl_typesupport_opensplice_cpp::Responder<
      rcl_interfaces::srv::dds_::ListParameters_Request_,
      rcl_interfaces::srv::dds_::ListParameters_Response_
      >;
  auto responder = reinterpret_cast<ResponderT *>(untyped_responder);

  const char * error_string = responder->send_response(*request_header, response);
  if (error_string) {
    return error_string;
  }
  return nullptr;
}

const char *
take_response__ListParameters(
  void * untyped_requester, rmw_request_id_t * request_header, void * untyped_ros_response,
  bool * taken)
{
  using RequesterT = rosidl_typesupport_opensplice_cpp::Requester<
      rcl_interfaces::srv::dds_::ListParameters_Request_,
      rcl_interfaces::srv::dds_::ListParameters_Response_
      >;
  auto requester = reinterpret_cast<RequesterT *>(untyped_requester);

  rosidl_typesupport_opensplice_cpp::Sample<rcl_interfaces::srv::dds_::ListParameters_Response_> response;
  const char * error_string = requester->take_response(response, taken);
  if (error_string) {
    return error_string;
  }
  if (*taken) {
    request_header->sequence_number = response.sequence_number_;

    const rosidl_message_type_support_t * ts =
      ROSIDL_GET_TYPE_SUPPORT(rcl_interfaces, srv, ListParameters_Response);
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(ts->data);
    callbacks->convert_dds_to_ros(
      static_cast<void *>(&response.data()), untyped_ros_response);
    return nullptr;
  }

  return nullptr;
}

const char *
destroy_requester__ListParameters(void * untyped_requester, void (* deallocator)(void *))
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::destroy_requester__ListParameters(
    untyped_requester, deallocator);
}

const char *
destroy_responder__ListParameters(void * untyped_responder, void (* deallocator)(void *))
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::destroy_responder__ListParameters(
    untyped_responder, deallocator);
}

const char *
server_is_available__ListParameters(
  void * requester, const rmw_node_t * node, bool * is_available,
  rmw_ret_t (* count_publishers)(const rmw_node_t *, const char *, size_t *),
  rmw_ret_t (* count_subscribers)(const rmw_node_t *, const char *, size_t *))
{
  return rcl_interfaces::srv::typesupport_opensplice_cpp::server_is_available__ListParameters(
    requester, node, is_available, count_publishers, count_subscribers);
}

static service_type_support_callbacks_t __callbacks = {
  "rcl_interfaces",
  "ListParameters",
  &create_requester__ListParameters,
  &destroy_requester__ListParameters,
  &create_responder__ListParameters,
  &destroy_responder__ListParameters,
  &send_request__ListParameters,
  &take_request__ListParameters,
  &send_response__ListParameters,
  &take_response__ListParameters,
  &server_is_available__ListParameters,
};

static rosidl_service_type_support_t __type_support = {
  rosidl_typesupport_opensplice_c__identifier,
  &__callbacks,  // data
  get_service_typesupport_handle_function,
};

ROSIDL_GENERATOR_C_EXPORT_rcl_interfaces
const rosidl_service_type_support_t *
ROSIDL_GET_TYPE_SUPPORT_FUNCTION(rcl_interfaces, srv, ListParameters)() {
  return &__type_support;
}

#if defined(__cplusplus)
}
#endif
