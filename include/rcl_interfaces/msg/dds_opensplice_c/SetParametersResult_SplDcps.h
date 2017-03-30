#ifndef SETPARAMETERSRESULT_SPLTYPES_H
#define SETPARAMETERSRESULT_SPLTYPES_H

#include "ccpp_SetParametersResult_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __SetParametersResult__rcl_interfaces__load (c_base base);

extern c_metaObject __SetParametersResult__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __SetParametersResult__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__SetParametersResult___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__SetParametersResult___keys (void);
extern const char * __rcl_interfaces_msg_dds__SetParametersResult___name (void);
struct _rcl_interfaces_msg_dds__SetParametersResult_ ;
extern  c_bool __rcl_interfaces_msg_dds__SetParametersResult___copyIn(c_base base, struct rcl_interfaces::msg::dds_::SetParametersResult_ *from, struct _rcl_interfaces_msg_dds__SetParametersResult_ *to);
extern  void __rcl_interfaces_msg_dds__SetParametersResult___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__SetParametersResult_ {
    c_bool successful_;
    c_string reason_;
};

#endif
