#include "ColorRGBA_SplDcps.h"
#include "ccpp_ColorRGBA_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__ColorRGBA___name(void)
{
    return (const char*)"std_msgs::msg::dds_::ColorRGBA_";
}

const char *
__std_msgs_msg_dds__ColorRGBA___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__ColorRGBA___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::ColorRGBA_ *from,
    struct _std_msgs_msg_dds__ColorRGBA_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->r_ = (c_float)from->r_;
    to->g_ = (c_float)from->g_;
    to->b_ = (c_float)from->b_;
    to->a_ = (c_float)from->a_;
    return result;
}

void
__std_msgs_msg_dds__ColorRGBA___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__ColorRGBA_ *from = (struct _std_msgs_msg_dds__ColorRGBA_ *)_from;
    struct ::std_msgs::msg::dds_::ColorRGBA_ *to = (struct ::std_msgs::msg::dds_::ColorRGBA_ *)_to;
    to->r_ = (::DDS::Float)from->r_;
    to->g_ = (::DDS::Float)from->g_;
    to->b_ = (::DDS::Float)from->b_;
    to->a_ = (::DDS::Float)from->a_;
}

