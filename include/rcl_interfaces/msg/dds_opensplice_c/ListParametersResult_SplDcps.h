#ifndef LISTPARAMETERSRESULT_SPLTYPES_H
#define LISTPARAMETERSRESULT_SPLTYPES_H

#include "ccpp_ListParametersResult_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ListParametersResult__rcl_interfaces__load (c_base base);

extern c_metaObject __ListParametersResult__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __ListParametersResult__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__ListParametersResult___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__ListParametersResult___keys (void);
extern const char * __rcl_interfaces_msg_dds__ListParametersResult___name (void);
struct _rcl_interfaces_msg_dds__ListParametersResult_ ;
extern  c_bool __rcl_interfaces_msg_dds__ListParametersResult___copyIn(c_base base, struct rcl_interfaces::msg::dds_::ListParametersResult_ *from, struct _rcl_interfaces_msg_dds__ListParametersResult_ *to);
extern  void __rcl_interfaces_msg_dds__ListParametersResult___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__ListParametersResult_ {
    c_sequence names_;
    c_sequence prefixes_;
};

#endif
