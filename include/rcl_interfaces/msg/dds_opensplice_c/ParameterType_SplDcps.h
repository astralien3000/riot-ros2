#ifndef PARAMETERTYPE_SPLTYPES_H
#define PARAMETERTYPE_SPLTYPES_H

#include "ccpp_ParameterType_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ParameterType__rcl_interfaces__load (c_base base);

extern c_metaObject __ParameterType__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ParameterType__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ParameterType___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ParameterType___keys (void);
extern const char * __rcl_interfaces_msg_dds__ParameterType___name (void);
struct _rcl_interfaces_msg_dds__ParameterType_ ;
extern  c_bool __rcl_interfaces_msg_dds__ParameterType___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ParameterType_ *from, struct _rcl_interfaces_msg_dds__ParameterType_ *to);
extern  void __rcl_interfaces_msg_dds__ParameterType___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ParameterType_ {
    c_bool dummy;
};

#endif
