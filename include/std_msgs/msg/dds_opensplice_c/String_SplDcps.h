#ifndef STRING_SPLTYPES_H
#define STRING_SPLTYPES_H

#include "ccpp_String_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __String__std_msgs__load (c_base base);

extern c_metaObject __String__std_msgs_msg__load (c_base base);

extern c_metaObject __String__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__String___load (c_base base);
extern const char * __std_msgs_msg_dds__String___keys (void);
extern const char * __std_msgs_msg_dds__String___name (void);
struct _std_msgs_msg_dds__String_ ;
extern  c_bool __std_msgs_msg_dds__String___copyIn(c_base base, struct std_msgs::msg::dds_::String_ *from, struct _std_msgs_msg_dds__String_ *to);
extern  void __std_msgs_msg_dds__String___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__String_ {
    c_string data_;
};

#endif
