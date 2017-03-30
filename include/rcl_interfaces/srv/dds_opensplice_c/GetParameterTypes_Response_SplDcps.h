#ifndef GETPARAMETERTYPES_RESPONSE_SPLTYPES_H
#define GETPARAMETERTYPES_RESPONSE_SPLTYPES_H

#include "ccpp_GetParameterTypes_Response_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __GetParameterTypes_Response__rcl_interfaces__load (c_base base);

extern c_metaObject __GetParameterTypes_Response__rcl_interfaces_srv__load (c_base base);

extern c_metaObject __GetParameterTypes_Response__rcl_interfaces_srv_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_srv_dds__GetParameterTypes_Response___load (c_base base);
extern const char * __rcl_interfaces_srv_dds__GetParameterTypes_Response___keys (void);
extern const char * __rcl_interfaces_srv_dds__GetParameterTypes_Response___name (void);
struct _rcl_interfaces_srv_dds__GetParameterTypes_Response_ ;
extern  c_bool __rcl_interfaces_srv_dds__GetParameterTypes_Response___copyIn(c_base base, struct rcl_interfaces::srv::dds_::GetParameterTypes_Response_ *from, struct _rcl_interfaces_srv_dds__GetParameterTypes_Response_ *to);
extern  void __rcl_interfaces_srv_dds__GetParameterTypes_Response___copyOut(void *_from, void *_to);
struct _rcl_interfaces_srv_dds__GetParameterTypes_Response_ {
    c_sequence types_;
};

#endif
