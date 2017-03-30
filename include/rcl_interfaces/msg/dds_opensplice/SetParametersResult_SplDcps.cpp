#include "SetParametersResult_SplDcps.h"
#include "ccpp_SetParametersResult_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_msg_dds__SetParametersResult___name(void)
{
    return (const char*)"rcl_interfaces::msg::dds_::SetParametersResult_";
}

const char *
__rcl_interfaces_msg_dds__SetParametersResult___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_msg_dds__SetParametersResult___copyIn(
    c_base base,
    struct ::rcl_interfaces::msg::dds_::SetParametersResult_ *from,
    struct _rcl_interfaces_msg_dds__SetParametersResult_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->successful_ = (c_bool)from->successful_;
#ifdef OSPL_BOUNDS_CHECK
    if(from->reason_){
        to->reason_ = c_stringNew(base, from->reason_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'rcl_interfaces::msg::dds_::SetParametersResult_.reason_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->reason_ = c_stringNew(base, from->reason_);
#endif
    return result;
}

void
__rcl_interfaces_msg_dds__SetParametersResult___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_msg_dds__SetParametersResult_ *from = (struct _rcl_interfaces_msg_dds__SetParametersResult_ *)_from;
    struct ::rcl_interfaces::msg::dds_::SetParametersResult_ *to = (struct ::rcl_interfaces::msg::dds_::SetParametersResult_ *)_to;
    to->successful_ = (::DDS::Boolean)(from->successful_ != 0);
    to->reason_ = DDS::string_dup(from->reason_ ? from->reason_ : "");
}

