#ifndef BOOL_SPLTYPES_H
#define BOOL_SPLTYPES_H

#include "ccpp_Bool_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Bool__std_msgs__load (c_base base);

extern c_metaObject __Bool__std_msgs_msg__load (c_base base);

extern c_metaObject __Bool__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Bool___load (c_base base);
extern const char * __std_msgs_msg_dds__Bool___keys (void);
extern const char * __std_msgs_msg_dds__Bool___name (void);
struct _std_msgs_msg_dds__Bool_ ;
extern  c_bool __std_msgs_msg_dds__Bool___copyIn(c_base base, struct std_msgs::msg::dds_::Bool_ *from, struct _std_msgs_msg_dds__Bool_ *to);
extern  void __std_msgs_msg_dds__Bool___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Bool_ {
    c_bool data_;
};

#endif
