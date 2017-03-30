#ifndef EMPTY_SPLTYPES_H
#define EMPTY_SPLTYPES_H

#include "ccpp_Empty_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Empty__std_msgs__load (c_base base);

extern c_metaObject __Empty__std_msgs_msg__load (c_base base);

extern c_metaObject __Empty__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Empty___load (c_base base);
extern const char * __std_msgs_msg_dds__Empty___keys (void);
extern const char * __std_msgs_msg_dds__Empty___name (void);
struct _std_msgs_msg_dds__Empty_ ;
extern  c_bool __std_msgs_msg_dds__Empty___copyIn(c_base base, struct std_msgs::msg::dds_::Empty_ *from, struct _std_msgs_msg_dds__Empty_ *to);
extern  void __std_msgs_msg_dds__Empty___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Empty_ {
    c_bool dummy;
};

#endif
