#ifndef INT8_SPLTYPES_H
#define INT8_SPLTYPES_H

#include "ccpp_Int8_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Int8__std_msgs__load (c_base base);

extern c_metaObject __Int8__std_msgs_msg__load (c_base base);

extern c_metaObject __Int8__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Int8___load (c_base base);
extern const char * __std_msgs_msg_dds__Int8___keys (void);
extern const char * __std_msgs_msg_dds__Int8___name (void);
struct _std_msgs_msg_dds__Int8_ ;
extern  c_bool __std_msgs_msg_dds__Int8___copyIn(c_base base, struct std_msgs::msg::dds_::Int8_ *from, struct _std_msgs_msg_dds__Int8_ *to);
extern  void __std_msgs_msg_dds__Int8___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Int8_ {
    c_octet data_;
};

#endif
