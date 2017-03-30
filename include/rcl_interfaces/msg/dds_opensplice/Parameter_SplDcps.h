#ifndef PARAMETER_SPLTYPES_H
#define PARAMETER_SPLTYPES_H

#include "ccpp_Parameter_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "ParameterValue_SplDcps.h"

extern c_metaObject __Parameter__rcl_interfaces__load (c_base base);

extern c_metaObject __Parameter__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __Parameter__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__Parameter___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__Parameter___keys (void);
extern const char * __rcl_interfaces_msg_dds__Parameter___name (void);
struct _rcl_interfaces_msg_dds__Parameter_ ;
extern  c_bool __rcl_interfaces_msg_dds__Parameter___copyIn(c_base base, struct rcl_interfaces::msg::dds_::Parameter_ *from, struct _rcl_interfaces_msg_dds__Parameter_ *to);
extern  void __rcl_interfaces_msg_dds__Parameter___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__Parameter_ {
    c_string name_;
    struct _rcl_interfaces_msg_dds__ParameterValue_ value_;
};

#endif
