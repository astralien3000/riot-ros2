#ifndef SETPARAMETERS_RESPONSE_SPLTYPES_H
#define SETPARAMETERS_RESPONSE_SPLTYPES_H

#include "ccpp_SetParameters_Response_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "SetParametersResult_SplDcps.h"

extern c_metaObject __SetParameters_Response__rcl_interfaces__load (c_base base);

extern c_metaObject __SetParameters_Response__rcl_interfaces_srv__load (c_base base);

extern c_metaObject __SetParameters_Response__rcl_interfaces_srv_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_srv_dds__SetParameters_Response___load (c_base base);
extern const char * __rcl_interfaces_srv_dds__SetParameters_Response___keys (void);
extern const char * __rcl_interfaces_srv_dds__SetParameters_Response___name (void);
struct _rcl_interfaces_srv_dds__SetParameters_Response_ ;
extern  c_bool __rcl_interfaces_srv_dds__SetParameters_Response___copyIn(c_base base, struct rcl_interfaces::srv::dds_::SetParameters_Response_ *from, struct _rcl_interfaces_srv_dds__SetParameters_Response_ *to);
extern  void __rcl_interfaces_srv_dds__SetParameters_Response___copyOut(void *_from, void *_to);
struct _rcl_interfaces_srv_dds__SetParameters_Response_ {
    c_sequence results_;
};

#endif
