#ifndef MULTIARRAYDIMENSION_SPLTYPES_H
#define MULTIARRAYDIMENSION_SPLTYPES_H

#include "ccpp_MultiArrayDimension_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __MultiArrayDimension__std_msgs__load (c_base base);

extern c_metaObject __MultiArrayDimension__std_msgs_msg__load (c_base base);

extern c_metaObject __MultiArrayDimension__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__MultiArrayDimension___load (c_base base);
extern const char * __std_msgs_msg_dds__MultiArrayDimension___keys (void);
extern const char * __std_msgs_msg_dds__MultiArrayDimension___name (void);
struct _std_msgs_msg_dds__MultiArrayDimension_ ;
extern  c_bool __std_msgs_msg_dds__MultiArrayDimension___copyIn(c_base base, struct std_msgs::msg::dds_::MultiArrayDimension_ *from, struct _std_msgs_msg_dds__MultiArrayDimension_ *to);
extern  void __std_msgs_msg_dds__MultiArrayDimension___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__MultiArrayDimension_ {
    c_string label_;
    c_ulong size_;
    c_ulong stride_;
};

#endif
