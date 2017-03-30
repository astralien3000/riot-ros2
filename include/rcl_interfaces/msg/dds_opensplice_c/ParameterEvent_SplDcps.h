#ifndef PARAMETEREVENT_SPLTYPES_H
#define PARAMETEREVENT_SPLTYPES_H

#include "ccpp_ParameterEvent_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "Parameter_SplDcps.h"

extern c_metaObject __ParameterEvent__rcl_interfaces__load (c_base base);

extern c_metaObject __ParameterEvent__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ParameterEvent__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ParameterEvent___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ParameterEvent___keys (void);
extern const char * __rcl_interfaces_msg_dds__ParameterEvent___name (void);
struct _rcl_interfaces_msg_dds__ParameterEvent_ ;
extern  c_bool __rcl_interfaces_msg_dds__ParameterEvent___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ParameterEvent_ *from, struct _rcl_interfaces_msg_dds__ParameterEvent_ *to);
extern  void __rcl_interfaces_msg_dds__ParameterEvent___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ParameterEvent_ {
    c_sequence new_parameters_;
    c_sequence changed_parameters_;
    c_sequence deleted_parameters_;
};

#endif
