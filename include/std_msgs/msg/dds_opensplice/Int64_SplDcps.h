#ifndef INT64_SPLTYPES_H
#define INT64_SPLTYPES_H

#include "ccpp_Int64_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Int64__std_msgs__load (c_base base);

extern c_metaObject __Int64__std_msgs_msg__load (c_base base);

extern c_metaObject __Int64__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Int64___load (c_base base);
extern const char * __std_msgs_msg_dds__Int64___keys (void);
extern const char * __std_msgs_msg_dds__Int64___name (void);
struct _std_msgs_msg_dds__Int64_ ;
extern  c_bool __std_msgs_msg_dds__Int64___copyIn(c_base base, struct std_msgs::msg::dds_::Int64_ *from, struct _std_msgs_msg_dds__Int64_ *to);
extern  void __std_msgs_msg_dds__Int64___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Int64_ {
    c_longlong data_;
};

#endif
