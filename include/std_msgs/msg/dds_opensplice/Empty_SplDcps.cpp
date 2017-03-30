#include "Empty_SplDcps.h"
#include "ccpp_Empty_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__Empty___name(void)
{
    return (const char*)"std_msgs::msg::dds_::Empty_";
}

const char *
__std_msgs_msg_dds__Empty___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__Empty___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::Empty_ *from,
    struct _std_msgs_msg_dds__Empty_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->dummy = (c_bool)from->dummy;
    return result;
}

void
__std_msgs_msg_dds__Empty___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__Empty_ *from = (struct _std_msgs_msg_dds__Empty_ *)_from;
    struct ::std_msgs::msg::dds_::Empty_ *to = (struct ::std_msgs::msg::dds_::Empty_ *)_to;
    to->dummy = (::DDS::Boolean)(from->dummy != 0);
}

