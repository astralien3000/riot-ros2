#include "Int32_SplDcps.h"
#include "ccpp_Int32_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__Int32___name(void)
{
    return (const char*)"std_msgs::msg::dds_::Int32_";
}

const char *
__std_msgs_msg_dds__Int32___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__Int32___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::Int32_ *from,
    struct _std_msgs_msg_dds__Int32_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->data_ = (c_long)from->data_;
    return result;
}

void
__std_msgs_msg_dds__Int32___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__Int32_ *from = (struct _std_msgs_msg_dds__Int32_ *)_from;
    struct ::std_msgs::msg::dds_::Int32_ *to = (struct ::std_msgs::msg::dds_::Int32_ *)_to;
    to->data_ = (::DDS::Long)from->data_;
}

