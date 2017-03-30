#ifndef SAMPLE_LISTPARAMETERS_REQUEST_SPLTYPES_H
#define SAMPLE_LISTPARAMETERS_REQUEST_SPLTYPES_H

#include "ccpp_Sample_ListParameters_Request_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "ListParameters_Request_SplDcps.h"

extern c_metaObject __Sample_ListParameters_Request__rcl_interfaces__load (c_base base);

extern c_metaObject __Sample_ListParameters_Request__rcl_interfaces_srv__load (c_base base);

extern c_metaObject __Sample_ListParameters_Request__rcl_interfaces_srv_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_srv_dds__Sample_ListParameters_Request___load (c_base base);
extern const char * __rcl_interfaces_srv_dds__Sample_ListParameters_Request___keys (void);
extern const char * __rcl_interfaces_srv_dds__Sample_ListParameters_Request___name (void);
struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ ;
extern  c_bool __rcl_interfaces_srv_dds__Sample_ListParameters_Request___copyIn(c_base base, struct rcl_interfaces::srv::dds_::Sample_ListParameters_Request_ *from, struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ *to);
extern  void __rcl_interfaces_srv_dds__Sample_ListParameters_Request___copyOut(void *_from, void *_to);
struct _rcl_interfaces_srv_dds__Sample_ListParameters_Request_ {
    c_ulonglong client_guid_0_;
    c_ulonglong client_guid_1_;
    c_longlong sequence_number_;
    struct _rcl_interfaces_srv_dds__ListParameters_Request_ request_;
};

#endif
