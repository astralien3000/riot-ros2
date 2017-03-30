#ifndef UINT32_SPLTYPES_H
#define UINT32_SPLTYPES_H

#include "ccpp_UInt32_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __UInt32__std_msgs__load (c_base base);

extern c_metaObject __UInt32__std_msgs_msg__load (c_base base);

extern c_metaObject __UInt32__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__UInt32___load (c_base base);
extern const char * __std_msgs_msg_dds__UInt32___keys (void);
extern const char * __std_msgs_msg_dds__UInt32___name (void);
struct _std_msgs_msg_dds__UInt32_ ;
extern  c_bool __std_msgs_msg_dds__UInt32___copyIn(c_base base, struct std_msgs::msg::dds_::UInt32_ *from, struct _std_msgs_msg_dds__UInt32_ *to);
extern  void __std_msgs_msg_dds__UInt32___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__UInt32_ {
    c_ulong data_;
};

#endif
