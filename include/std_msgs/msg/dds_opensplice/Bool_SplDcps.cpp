#include "Bool_SplDcps.h"
#include "ccpp_Bool_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__Bool___name(void)
{
    return (const char*)"std_msgs::msg::dds_::Bool_";
}

const char *
__std_msgs_msg_dds__Bool___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__Bool___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::Bool_ *from,
    struct _std_msgs_msg_dds__Bool_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->data_ = (c_bool)from->data_;
    return result;
}

void
__std_msgs_msg_dds__Bool___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__Bool_ *from = (struct _std_msgs_msg_dds__Bool_ *)_from;
    struct ::std_msgs::msg::dds_::Bool_ *to = (struct ::std_msgs::msg::dds_::Bool_ *)_to;
    to->data_ = (::DDS::Boolean)(from->data_ != 0);
}

