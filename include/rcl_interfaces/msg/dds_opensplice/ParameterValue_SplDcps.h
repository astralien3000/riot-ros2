#ifndef PARAMETERVALUE_SPLTYPES_H
#define PARAMETERVALUE_SPLTYPES_H

#include "ccpp_ParameterValue_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ParameterValue__rcl_interfaces__load (c_base base);

extern c_metaObject __ParameterValue__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ParameterValue__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ParameterValue___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ParameterValue___keys (void);
extern const char * __rcl_interfaces_msg_dds__ParameterValue___name (void);
struct _rcl_interfaces_msg_dds__ParameterValue_ ;
extern  c_bool __rcl_interfaces_msg_dds__ParameterValue___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ParameterValue_ *from, struct _rcl_interfaces_msg_dds__ParameterValue_ *to);
extern  void __rcl_interfaces_msg_dds__ParameterValue___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ParameterValue_ {
    c_octet type_;
    c_bool bool_value_;
    c_longlong integer_value_;
    c_double double_value_;
    c_string string_value_;
    c_sequence bytes_value_;
};

#endif
