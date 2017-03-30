#ifndef PARAMETEREVENTDESCRIPTORS_SPLTYPES_H
#define PARAMETEREVENTDESCRIPTORS_SPLTYPES_H

#include "ccpp_ParameterEventDescriptors_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "ParameterDescriptor_SplDcps.h"

extern c_metaObject __ParameterEventDescriptors__rcl_interfaces__load (c_base base);

extern c_metaObject __ParameterEventDescriptors__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ParameterEventDescriptors__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ParameterEventDescriptors___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ParameterEventDescriptors___keys (void);
extern const char * __rcl_interfaces_msg_dds__ParameterEventDescriptors___name (void);
struct _rcl_interfaces_msg_dds__ParameterEventDescriptors_ ;
extern  c_bool __rcl_interfaces_msg_dds__ParameterEventDescriptors___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ParameterEventDescriptors_ *from, struct _rcl_interfaces_msg_dds__ParameterEventDescriptors_ *to);
extern  void __rcl_interfaces_msg_dds__ParameterEventDescriptors___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ParameterEventDescriptors_ {
    c_sequence new_parameters_;
    c_sequence changed_parameters_;
    c_sequence deleted_parameters_;
};

#endif
