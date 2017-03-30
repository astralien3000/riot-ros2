#include "IntraProcessMessage_SplDcps.h"
#include "ccpp_IntraProcessMessage_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_msg_dds__IntraProcessMessage___name(void)
{
    return (const char*)"rcl_interfaces::msg::dds_::IntraProcessMessage_";
}

const char *
__rcl_interfaces_msg_dds__IntraProcessMessage___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_msg_dds__IntraProcessMessage___copyIn(
    c_base base,
    struct ::rcl_interfaces::msg::dds_::IntraProcessMessage_ *from,
    struct _rcl_interfaces_msg_dds__IntraProcessMessage_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->publisher_id_ = (c_ulonglong)from->publisher_id_;
    to->message_sequence_ = (c_ulonglong)from->message_sequence_;
    return result;
}

void
__rcl_interfaces_msg_dds__IntraProcessMessage___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_msg_dds__IntraProcessMessage_ *from = (struct _rcl_interfaces_msg_dds__IntraProcessMessage_ *)_from;
    struct ::rcl_interfaces::msg::dds_::IntraProcessMessage_ *to = (struct ::rcl_interfaces::msg::dds_::IntraProcessMessage_ *)_to;
    to->publisher_id_ = (::DDS::ULongLong)from->publisher_id_;
    to->message_sequence_ = (::DDS::ULongLong)from->message_sequence_;
}

