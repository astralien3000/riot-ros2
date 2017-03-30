#include "ListParameters_Response_SplDcps.h"
#include "ccpp_ListParameters_Response_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_srv_dds__ListParameters_Response___name(void)
{
    return (const char*)"rcl_interfaces::srv::dds_::ListParameters_Response_";
}

const char *
__rcl_interfaces_srv_dds__ListParameters_Response___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_srv_dds__ListParameters_Response___copyIn(
    c_base base,
    struct ::rcl_interfaces::srv::dds_::ListParameters_Response_ *from,
    struct _rcl_interfaces_srv_dds__ListParameters_Response_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    if(result){
        extern c_bool __rcl_interfaces_msg_dds__ListParametersResult___copyIn(c_base, ::rcl_interfaces::msg::dds_::ListParametersResult_ *, _rcl_interfaces_msg_dds__ListParametersResult_ *);
        result = __rcl_interfaces_msg_dds__ListParametersResult___copyIn(base, &from->result_, &to->result_);
    }
    return result;
}

void
__rcl_interfaces_srv_dds__ListParameters_Response___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_srv_dds__ListParameters_Response_ *from = (struct _rcl_interfaces_srv_dds__ListParameters_Response_ *)_from;
    struct ::rcl_interfaces::srv::dds_::ListParameters_Response_ *to = (struct ::rcl_interfaces::srv::dds_::ListParameters_Response_ *)_to;
    {
        extern void __rcl_interfaces_msg_dds__ListParametersResult___copyOut(void *, void *);
        __rcl_interfaces_msg_dds__ListParametersResult___copyOut((void *)&from->result_, (void *)&to->result_);
    }
}

