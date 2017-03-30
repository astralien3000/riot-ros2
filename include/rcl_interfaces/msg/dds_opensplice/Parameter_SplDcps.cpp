#include "Parameter_SplDcps.h"
#include "ccpp_Parameter_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_msg_dds__Parameter___name(void)
{
    return (const char*)"rcl_interfaces::msg::dds_::Parameter_";
}

const char *
__rcl_interfaces_msg_dds__Parameter___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_msg_dds__Parameter___copyIn(
    c_base base,
    struct ::rcl_interfaces::msg::dds_::Parameter_ *from,
    struct _rcl_interfaces_msg_dds__Parameter_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->name_){
        to->name_ = c_stringNew(base, from->name_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'rcl_interfaces::msg::dds_::Parameter_.name_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->name_ = c_stringNew(base, from->name_);
#endif
    if(result){
        extern c_bool __rcl_interfaces_msg_dds__ParameterValue___copyIn(c_base, ::rcl_interfaces::msg::dds_::ParameterValue_ *, _rcl_interfaces_msg_dds__ParameterValue_ *);
        result = __rcl_interfaces_msg_dds__ParameterValue___copyIn(base, &from->value_, &to->value_);
    }
    return result;
}

void
__rcl_interfaces_msg_dds__Parameter___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_msg_dds__Parameter_ *from = (struct _rcl_interfaces_msg_dds__Parameter_ *)_from;
    struct ::rcl_interfaces::msg::dds_::Parameter_ *to = (struct ::rcl_interfaces::msg::dds_::Parameter_ *)_to;
    to->name_ = DDS::string_dup(from->name_ ? from->name_ : "");
    {
        extern void __rcl_interfaces_msg_dds__ParameterValue___copyOut(void *, void *);
        __rcl_interfaces_msg_dds__ParameterValue___copyOut((void *)&from->value_, (void *)&to->value_);
    }
}

