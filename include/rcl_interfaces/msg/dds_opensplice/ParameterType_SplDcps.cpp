#include "ParameterType_SplDcps.h"
#include "ccpp_ParameterType_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_msg_dds__ParameterType___name(void)
{
    return (const char*)"rcl_interfaces::msg::dds_::ParameterType_";
}

const char *
__rcl_interfaces_msg_dds__ParameterType___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_msg_dds__ParameterType___copyIn(
    c_base base,
    struct ::rcl_interfaces::msg::dds_::ParameterType_ *from,
    struct _rcl_interfaces_msg_dds__ParameterType_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->dummy = (c_bool)from->dummy;
    return result;
}

void
__rcl_interfaces_msg_dds__ParameterType___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_msg_dds__ParameterType_ *from = (struct _rcl_interfaces_msg_dds__ParameterType_ *)_from;
    struct ::rcl_interfaces::msg::dds_::ParameterType_ *to = (struct ::rcl_interfaces::msg::dds_::ParameterType_ *)_to;
    to->dummy = (::DDS::Boolean)(from->dummy != 0);
}

