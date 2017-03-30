#ifndef HEADER_SPLTYPES_H
#define HEADER_SPLTYPES_H

#include "ccpp_Header_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "dds_dcps_builtintopicsSplDcps.h"

extern c_metaObject __Header__std_msgs__load (c_base base);

extern c_metaObject __Header__std_msgs_msg__load (c_base base);

extern c_metaObject __Header__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Header___load (c_base base);
extern const char * __std_msgs_msg_dds__Header___keys (void);
extern const char * __std_msgs_msg_dds__Header___name (void);
struct _std_msgs_msg_dds__Header_ ;
extern  c_bool __std_msgs_msg_dds__Header___copyIn(c_base base, struct std_msgs::msg::dds_::Header_ *from, struct _std_msgs_msg_dds__Header_ *to);
extern  void __std_msgs_msg_dds__Header___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Header_ {
    struct _DDS_Time_t stamp_;
    c_string frame_id_;
};

#endif
