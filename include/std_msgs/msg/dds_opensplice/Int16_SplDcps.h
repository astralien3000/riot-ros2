#ifndef INT16_SPLTYPES_H
#define INT16_SPLTYPES_H

#include "ccpp_Int16_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Int16__std_msgs__load (c_base base);

extern c_metaObject __Int16__std_msgs_msg__load (c_base base);

extern c_metaObject __Int16__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Int16___load (c_base base);
extern const char * __std_msgs_msg_dds__Int16___keys (void);
extern const char * __std_msgs_msg_dds__Int16___name (void);
struct _std_msgs_msg_dds__Int16_ ;
extern  c_bool __std_msgs_msg_dds__Int16___copyIn(c_base base, struct std_msgs::msg::dds_::Int16_ *from, struct _std_msgs_msg_dds__Int16_ *to);
extern  void __std_msgs_msg_dds__Int16___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Int16_ {
    c_short data_;
};

#endif
