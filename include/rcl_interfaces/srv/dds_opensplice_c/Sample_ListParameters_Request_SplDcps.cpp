#include "Sample_ListParameters_Request_SplDcps.h"
#include "ccpp_Sample_ListParameters_Request_.h"
#include "dds_type_aliases.h"

const char *
__rcl_interfaces_srv_dds__Sample_ListParameters_Request___name(void)
{
    return (const char*)"rcl_interfaces::srv::dds_::Sample_ListParameters_Request_";
}

const char *
__rcl_interfaces_srv_dds__Sample_ListParameters_Request___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__rcl_interfaces_srv_dds__Sample_ListParameters_Request___copyIn(
    c_base base,
    struct ::rcl_interfaces::srv::dds_::Sample_ListParameters_Request_ *from,
    struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->client_guid_0_ = (c_ulonglong)from->client_guid_0_;
    to->client_guid_1_ = (c_ulonglong)from->client_guid_1_;
    to->sequence_number_ = (c_longlong)from->sequence_number_;
    if(result){
        extern c_bool __rcl_interfaces_srv_dds__ListParameters_Request___copyIn(c_base, ::rcl_interfaces::srv::dds_::ListParameters_Request_ *, _rcl_interfaces_srv_dds__ListParameters_Request_ *);
        result = __rcl_interfaces_srv_dds__ListParameters_Request___copyIn(base, &from->request_, &to->request_);
    }
    return result;
}

void
__rcl_interfaces_srv_dds__Sample_ListParameters_Request___copyOut(
    void *_from,
    void *_to)
{
    struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ *from = (struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ *)_from;
    struct ::rcl_interfaces::srv::dds_::Sample_ListParameters_Request_ *to = (struct ::rcl_interfaces::srv::dds_::Sample_ListParameters_Request_ *)_to;
    to->client_guid_0_ = (::DDS::ULongLong)from->client_guid_0_;
    to->client_guid_1_ = (::DDS::ULongLong)from->client_guid_1_;
    to->sequence_number_ = (::DDS::LongLong)from->sequence_number_;
    {
        extern void __rcl_interfaces_srv_dds__ListParameters_Request___copyOut(void *, void *);
        __rcl_interfaces_srv_dds__ListParameters_Request___copyOut((void *)&from->request_, (void *)&to->request_);
    }
}

