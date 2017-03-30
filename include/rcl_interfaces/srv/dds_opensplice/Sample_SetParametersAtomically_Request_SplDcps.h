#ifndef SAMPLE_SETPARAMETERSATOMICALLY_REQUEST_SPLTYPES_H
#define SAMPLE_SETPARAMETERSATOMICALLY_REQUEST_SPLTYPES_H

#include "ccpp_Sample_SetParametersAtomically_Request_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "SetParametersAtomically_Request_SplDcps.h"

extern c_metaObject __Sample_SetParametersAtomically_Request__rcl_interfaces__load (c_base base);

extern c_metaObject __Sample_SetParametersAtomically_Request__rcl_interfaces_srv__load (c_base base);

extern c_metaObject __Sample_SetParametersAtomically_Request__rcl_interfaces_srv_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request___load (c_base base);
extern const char * __rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request___keys (void);
extern const char * __rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request___name (void);
struct _rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request_ ;
extern  c_bool __rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request___copyIn(c_base base, struct rcl_interfaces::srv::dds_::Sample_SetParametersAtomically_Request_ *from, struct _rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request_ *to);
extern  void __rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request___copyOut(void *_from, void *_to);
struct _rcl_interfaces_srv_dds__Sample_SetParametersAtomically_Request_ {
    c_ulonglong client_guid_0_;
    c_ulonglong client_guid_1_;
    c_longlong sequence_number_;
    struct _rcl_interfaces_srv_dds__SetParametersAtomically_Request_ request_;
};

#endif
