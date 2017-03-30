#ifndef FLOAT64_SPLTYPES_H
#define FLOAT64_SPLTYPES_H

#include "ccpp_Float64_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Float64__std_msgs__load (c_base base);

extern c_metaObject __Float64__std_msgs_msg__load (c_base base);

extern c_metaObject __Float64__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Float64___load (c_base base);
extern const char * __std_msgs_msg_dds__Float64___keys (void);
extern const char * __std_msgs_msg_dds__Float64___name (void);
struct _std_msgs_msg_dds__Float64_ ;
extern  c_bool __std_msgs_msg_dds__Float64___copyIn(c_base base, struct std_msgs::msg::dds_::Float64_ *from, struct _std_msgs_msg_dds__Float64_ *to);
extern  void __std_msgs_msg_dds__Float64___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Float64_ {
    c_double data_;
};

#endif
