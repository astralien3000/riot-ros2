// generated from rosidl_typesupport_opensplice_c/resource/msg__type_support_c.cpp.em
// generated code does not contain a copyright notice

#include <cassert>
#include <limits>

#include <u_instanceHandle.h>

// Provides the definition of the rosidl_message_type_support_t struct as well
// as the OpenSplice specific macros, e.g. ROSIDL_GET_TYPE_SUPPORT_FUNCTION.
#include "rosidl_generator_c/message_type_support.h"
// Ensure the correct version of the above header was included.
static_assert(USING_ROSIDL_TYPESUPPORT_OPENSPLICE_C, "expected OpenSplice C message type support");
// Provides the rosidl_typesupport_opensplice_c__identifier symbol declaration.
#include "rosidl_typesupport_opensplice_c/identifier.h"
#include "rcl_interfaces/msg/rosidl_generator_c__visibility_control.h"
// Provides the definition of the message_type_support_callbacks_t struct.
#include "rosidl_typesupport_opensplice_cpp/message_type_support.h"

#include "rcl_interfaces/srv/set_parameters__request__struct.h"
#include "rcl_interfaces/srv/set_parameters__request__functions.h"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_SetParameters_Request_.h"

// includes and forward declarations of message dependencies and their conversion functions
#if defined(__cplusplus)
extern "C"
{
#endif

// include message dependencies
#include "rcl_interfaces/msg/parameter__functions.h"  // parameters

// forward declare type support functions
const rosidl_message_type_support_t *
  ROSIDL_GET_TYPE_SUPPORT_FUNCTION(rcl_interfaces, msg, Parameter)();  // parameters

using __dds_msg_type = rcl_interfaces::srv::dds_::SetParameters_Request_;
using __ros_msg_type = rcl_interfaces__srv__SetParameters_Request;

static const char *
register_type(void * untyped_participant, const char * type_name)
{
  if (!untyped_participant) {
    return "untyped participant handle is null";
  }
  if (!type_name) {
    return "type name handle is null";
  }
  using DDS::DomainParticipant;
  DomainParticipant * participant = static_cast<DomainParticipant *>(untyped_participant);

  rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport type_support;
  DDS::ReturnCode_t status = type_support.register_type(participant, type_name);
  switch (status) {
    case DDS::RETCODE_ERROR:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport.register_type: "
             "an internal error has occurred";
    case DDS::RETCODE_BAD_PARAMETER:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport.register_type: "
             "bad domain participant or type name parameter";
    case DDS::RETCODE_OUT_OF_RESOURCES:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport.register_type: "
             "out of resources";
    case DDS::RETCODE_PRECONDITION_NOT_MET:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport.register_type: "
             "already registered with a different TypeSupport class";
    case DDS::RETCODE_OK:
      return nullptr;
    default:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_TypeSupport.register_type: unknown return code";
  }
}

static const char *
convert_ros_to_dds(const void * untyped_ros_message, void * untyped_dds_message)
{
  if (!untyped_ros_message) {
    return "ros message handle is null";
  }
  if (!untyped_dds_message) {
    return "dds message handle is null";
  }
  const __ros_msg_type * ros_message = static_cast<const __ros_msg_type *>(untyped_ros_message);
  __dds_msg_type * dds_message = static_cast<__dds_msg_type *>(untyped_dds_message);
  // Field name: parameters
  {
    const message_type_support_callbacks_t * rcl_interfaces__msg__Parameter__callbacks =
      static_cast<const message_type_support_callbacks_t *>(ROSIDL_GET_TYPE_SUPPORT_FUNCTION(
        rcl_interfaces, msg, Parameter
      )()->data);
    size_t size = ros_message->parameters.size;
    if (size > (std::numeric_limits<DDS::Long>::max)()) {
      return "array size exceeds maximum DDS sequence size";
    }
    DDS::Long length = static_cast<DDS::Long>(size);
    dds_message->parameters_.length(length);
    for (DDS::ULong i = 0; i < size; ++i) {
      auto & ros_i = ros_message->parameters.data[i];
      const char * err_msg = rcl_interfaces__msg__Parameter__callbacks->convert_ros_to_dds(
        &ros_i, &dds_message->parameters_[i]);
      if (err_msg != 0) {
        return err_msg;
      }
    }
  }

  return 0;
}

static const char *
publish(void * dds_data_writer, const void * ros_message)
{
  if (!dds_data_writer) {
    return "data writer handle is null";
  }
  if (!ros_message) {
    return "ros message handle is null";
  }

  DDS::DataWriter * topic_writer = static_cast<DDS::DataWriter *>(dds_data_writer);

  __dds_msg_type dds_message;
  const char * err_msg = convert_ros_to_dds(ros_message, &dds_message);
  if (err_msg != 0) {
    return err_msg;
  }

  rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter * data_writer =
    rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter::_narrow(topic_writer);
  DDS::ReturnCode_t status = data_writer->write(dds_message, DDS::HANDLE_NIL);
  switch (status) {
    case DDS::RETCODE_ERROR:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "an internal error has occurred";
    case DDS::RETCODE_BAD_PARAMETER:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "bad handle or instance_data parameter";
    case DDS::RETCODE_ALREADY_DELETED:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "this rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter has already been deleted";
    case DDS::RETCODE_OUT_OF_RESOURCES:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "out of resources";
    case DDS::RETCODE_NOT_ENABLED:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "this rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter is not enabled";
    case DDS::RETCODE_PRECONDITION_NOT_MET:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "the handle has not been registered with this rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter";
    case DDS::RETCODE_TIMEOUT:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: "
             "writing resulted in blocking and then exceeded the timeout set by the "
             "max_blocking_time of the ReliabilityQosPolicy";
    case DDS::RETCODE_OK:
      return nullptr;
    default:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataWriter.write: unknown return code";
  }
}

static const char *
convert_dds_to_ros(const void * untyped_dds_message, void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    return "ros message handle is null";
  }
  if (!untyped_dds_message) {
    return "dds message handle is null";
  }
  const __dds_msg_type * dds_message = static_cast<const __dds_msg_type *>(untyped_dds_message);
  __ros_msg_type * ros_message = static_cast<__ros_msg_type *>(untyped_ros_message);
  // Field name: parameters
  {
    size_t size = dds_message->parameters_.length();
    if (ros_message->parameters.data) {
      rcl_interfaces__msg__Parameter__Array__fini(&ros_message->parameters);
    }
    if (!rcl_interfaces__msg__Parameter__Array__init(&ros_message->parameters, size)) {
      return "failed to create array for field 'parameters'";
    }
    for (DDS::ULong i = 0; i < size; i++) {
      auto & ros_i = ros_message->parameters.data[i];
      const rosidl_message_type_support_t * ts =
        ROSIDL_GET_TYPE_SUPPORT_FUNCTION(rcl_interfaces, msg, Parameter)();
      const message_type_support_callbacks_t * callbacks =
        static_cast<const message_type_support_callbacks_t *>(ts->data);
      callbacks->convert_dds_to_ros(&dds_message->parameters_[i], &ros_i);
    }
  }

  return 0;
}

static const char *
take(
  void * dds_data_reader,
  bool ignore_local_publications,
  void * untyped_ros_message,
  bool * taken,
  void * sending_publication_handle)
{
  if (untyped_ros_message == 0) {
    return "invalid ros message pointer";
  }

  DDS::DataReader * topic_reader = static_cast<DDS::DataReader *>(dds_data_reader);

  rcl_interfaces::srv::dds_::SetParameters_Request_DataReader * data_reader =
    rcl_interfaces::srv::dds_::SetParameters_Request_DataReader::_narrow(topic_reader);

  rcl_interfaces::srv::dds_::SetParameters_Request_Seq dds_messages;
  DDS::SampleInfoSeq sample_infos;
  DDS::ReturnCode_t status = data_reader->take(
    dds_messages,
    sample_infos,
    1,
    DDS::ANY_SAMPLE_STATE,
    DDS::ANY_VIEW_STATE,
    DDS::ANY_INSTANCE_STATE);

  const char * errs = nullptr;
  bool ignore_sample = false;

  switch (status) {
    case DDS::RETCODE_ERROR:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: "
        "an internal error has occurred";
      goto finally;
    case DDS::RETCODE_ALREADY_DELETED:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: "
        "this rcl_interfaces::srv::dds_::SetParameters_Request_DataReader has already been deleted";
      goto finally;
    case DDS::RETCODE_OUT_OF_RESOURCES:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: "
        "out of resources";
      goto finally;
    case DDS::RETCODE_NOT_ENABLED:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: "
        "this rcl_interfaces::srv::dds_::SetParameters_Request_DataReader is not enabled";
      goto finally;
    case DDS::RETCODE_PRECONDITION_NOT_MET:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: "
        "a precondition is not met, one of: "
        "max_samples > maximum and max_samples != LENGTH_UNLIMITED, or "
        "the two sequences do not have matching parameters (length, maximum, release), or "
        "maximum > 0 and release is false.";
      goto finally;
    case DDS::RETCODE_NO_DATA:
      *taken = false;
      errs = nullptr;
      goto finally;
    case DDS::RETCODE_OK:
      break;
    default:
      errs = "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.take: unknown return code";
      goto finally;
  }

  {
    DDS::SampleInfo & sample_info = sample_infos[0];
    if (!sample_info.valid_data) {
      // skip sample without data
      ignore_sample = true;
    } else {
      DDS::InstanceHandle_t sender_handle = sample_info.publication_handle;
      auto sender_gid = u_instanceHandleToGID(sender_handle);
      if (ignore_local_publications) {
        // compare the system id from the sender and this receiver
        // if they are equal the sample has been sent from this process and should be ignored
        DDS::InstanceHandle_t receiver_handle = topic_reader->get_instance_handle();
        auto receiver_gid = u_instanceHandleToGID(receiver_handle);
        ignore_sample = sender_gid.systemId == receiver_gid.systemId;
      }
      // This is nullptr when being used with plain rmw_take, so check first.
      if (sending_publication_handle) {
        *static_cast<DDS::InstanceHandle_t *>(sending_publication_handle) = sender_handle;
      }
    }
  }

  if (!ignore_sample) {
    errs = convert_dds_to_ros(&dds_messages[0], untyped_ros_message);
    if (errs != 0) {
      goto finally;
    }
    *taken = true;
  } else {
    *taken = false;
  }

finally:
  // Ensure the loan is returned.
  status = data_reader->return_loan(dds_messages, sample_infos);
  switch (status) {
    case DDS::RETCODE_ERROR:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan: "
             "an internal error has occurred";
    case DDS::RETCODE_ALREADY_DELETED:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan: "
             "this rcl_interfaces::srv::dds_::SetParameters_Request_DataReader has already been deleted";
    case DDS::RETCODE_OUT_OF_RESOURCES:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan: "
             "out of resources";
    case DDS::RETCODE_NOT_ENABLED:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan: "
             "this rcl_interfaces::srv::dds_::SetParameters_Request_DataReader is not enabled";
    case DDS::RETCODE_PRECONDITION_NOT_MET:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan: "
             "a precondition is not met, one of: "
             "the data_values and info_seq do not belong to a single related pair, or "
             "the data_values and info_seq were not obtained from this "
             "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader";
    case DDS::RETCODE_OK:
      return nullptr;
    default:
      return "rcl_interfaces::srv::dds_::SetParameters_Request_DataReader.return_loan failed with "
             "unknown return code";
  }

  return errs;
}

static message_type_support_callbacks_t __callbacks = {
  "rcl_interfaces",  // package_name
  "SetParameters_Request",  // message_name
  register_type,  // register_type
  publish,  // publish
  take,  // take
  convert_ros_to_dds,  // convert_ros_to_dds
  convert_dds_to_ros,  // convert_dds_to_ros
};

static rosidl_message_type_support_t __type_support = {
  rosidl_typesupport_opensplice_c__identifier,
  &__callbacks,  // data
  get_message_typesupport_handle_function,
};

ROSIDL_GENERATOR_C_EXPORT_rcl_interfaces
const rosidl_message_type_support_t *
ROSIDL_GET_TYPE_SUPPORT_FUNCTION(rcl_interfaces, srv, SetParameters_Request)() {
  return &__type_support;
}

#if defined(__cplusplus)
}
#endif
