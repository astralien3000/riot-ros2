#include "UInt8_SplDcps.h"
#include "ccpp_UInt8_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__UInt8___name(void)
{
    return (const char*)"std_msgs::msg::dds_::UInt8_";
}

const char *
__std_msgs_msg_dds__UInt8___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__UInt8___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::UInt8_ *from,
    struct _std_msgs_msg_dds__UInt8_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->data_ = (c_octet)from->data_;
    return result;
}

void
__std_msgs_msg_dds__UInt8___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__UInt8_ *from = (struct _std_msgs_msg_dds__UInt8_ *)_from;
    struct ::std_msgs::msg::dds_::UInt8_ *to = (struct ::std_msgs::msg::dds_::UInt8_ *)_to;
    to->data_ = (::DDS::Octet)from->data_;
}

