#include "ParameterDescriptor_SplDcps.h"
#include "ccpp_ParameterDescriptor_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_msg_dds__ParameterDescriptor___name(void)
{
    return (const char*)"rcl_interfaces::msg::dds_::ParameterDescriptor_";
}

const char *
__rcl_interfaces_msg_dds__ParameterDescriptor___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_msg_dds__ParameterDescriptor___copyIn(
    c_base base,
    struct ::rcl_interfaces::msg::dds_::ParameterDescriptor_ *from,
    struct _rcl_interfaces_msg_dds__ParameterDescriptor_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->name_){
        to->name_ = c_stringNew(base, from->name_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'rcl_interfaces::msg::dds_::ParameterDescriptor_.name_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->name_ = c_stringNew(base, from->name_);
#endif
    to->type_ = (c_octet)from->type_;
    return result;
}

void
__rcl_interfaces_msg_dds__ParameterDescriptor___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_msg_dds__ParameterDescriptor_ *from = (struct _rcl_interfaces_msg_dds__ParameterDescriptor_ *)_from;
    struct ::rcl_interfaces::msg::dds_::ParameterDescriptor_ *to = (struct ::rcl_interfaces::msg::dds_::ParameterDescriptor_ *)_to;
    to->name_ = DDS::string_dup(from->name_ ? from->name_ : "");
    to->type_ = (::DDS::Octet)from->type_;
}

