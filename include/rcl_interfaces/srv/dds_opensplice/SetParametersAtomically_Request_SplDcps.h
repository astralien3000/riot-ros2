#ifndef SETPARAMETERSATOMICALLY_REQUEST_SPLTYPES_H
#define SETPARAMETERSATOMICALLY_REQUEST_SPLTYPES_H

#include "ccpp_SetParametersAtomically_Request_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "Parameter_SplDcps.h"

extern c_metaObject __SetParametersAtomically_Request__rcl_interfaces__load (c_base base);

extern c_metaObject __SetParametersAtomically_Request__rcl_interfaces_srv__load (c_base base);

extern c_metaObject __SetParametersAtomically_Request__rcl_interfaces_srv_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_srv_dds__SetParametersAtomically_Request___load (c_base base);
extern const char * __rcl_interfaces_srv_dds__SetParametersAtomically_Request___keys (void);
extern const char * __rcl_interfaces_srv_dds__SetParametersAtomically_Request___name (void);
struct _rcl_interfaces_srv_dds__SetParametersAtomically_Request_ ;
extern  c_bool __rcl_interfaces_srv_dds__SetParametersAtomically_Request___copyIn(c_base base, struct rcl_interfaces::srv::dds_::SetParametersAtomically_Request_ *from, struct _rcl_interfaces_srv_dds__SetParametersAtomically_Request_ *to);
extern  void __rcl_interfaces_srv_dds__SetParametersAtomically_Request___copyOut(void *_from, void *_to);
struct _rcl_interfaces_srv_dds__SetParametersAtomically_Request_ {
    c_sequence parameters_;
};

#endif
