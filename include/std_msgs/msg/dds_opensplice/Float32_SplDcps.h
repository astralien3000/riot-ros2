#ifndef FLOAT32_SPLTYPES_H
#define FLOAT32_SPLTYPES_H

#include "ccpp_Float32_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Float32__std_msgs__load (c_base base);

extern c_metaObject __Float32__std_msgs_msg__load (c_base base);

extern c_metaObject __Float32__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Float32___load (c_base base);
extern const char * __std_msgs_msg_dds__Float32___keys (void);
extern const char * __std_msgs_msg_dds__Float32___name (void);
struct _std_msgs_msg_dds__Float32_ ;
extern  c_bool __std_msgs_msg_dds__Float32___copyIn(c_base base, struct std_msgs::msg::dds_::Float32_ *from, struct _std_msgs_msg_dds__Float32_ *to);
extern  void __std_msgs_msg_dds__Float32___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Float32_ {
    c_float data_;
};

#endif
