#ifndef PARAMETERDESCRIPTOR_SPLTYPES_H
#define PARAMETERDESCRIPTOR_SPLTYPES_H

#include "ccpp_ParameterDescriptor_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ParameterDescriptor__rcl_interfaces__load (c_base base);

extern c_metaObject __ParameterDescriptor__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ParameterDescriptor__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ParameterDescriptor___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ParameterDescriptor___keys (void);
extern const char * __rcl_interfaces_msg_dds__ParameterDescriptor___name (void);
struct _rcl_interfaces_msg_dds__ParameterDescriptor_ ;
extern  c_bool __rcl_interfaces_msg_dds__ParameterDescriptor___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ParameterDescriptor_ *from, struct _rcl_interfaces_msg_dds__ParameterDescriptor_ *to);
extern  void __rcl_interfaces_msg_dds__ParameterDescriptor___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ParameterDescriptor_ {
    c_string name_;
    c_octet type_;
};

#endif
