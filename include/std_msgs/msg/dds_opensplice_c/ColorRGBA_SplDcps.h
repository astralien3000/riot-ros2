#ifndef COLORRGBA_SPLTYPES_H
#define COLORRGBA_SPLTYPES_H

#include "ccpp_ColorRGBA_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __ColorRGBA__std_msgs__load (c_base base);

extern c_metaObject __ColorRGBA__std_msgs_msg__load (c_base base);

extern c_metaObject __ColorRGBA__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__ColorRGBA___load (c_base base);
extern const char * __std_msgs_msg_dds__ColorRGBA___keys (void);
extern const char * __std_msgs_msg_dds__ColorRGBA___name (void);
struct _std_msgs_msg_dds__ColorRGBA_ ;
extern  c_bool __std_msgs_msg_dds__ColorRGBA___copyIn(c_base base, struct std_msgs::msg::dds_::ColorRGBA_ *from, struct _std_msgs_msg_dds__ColorRGBA_ *to);
extern  void __std_msgs_msg_dds__ColorRGBA___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__ColorRGBA_ {
    c_float r_;
    c_float g_;
    c_float b_;
    c_float a_;
};

#endif
