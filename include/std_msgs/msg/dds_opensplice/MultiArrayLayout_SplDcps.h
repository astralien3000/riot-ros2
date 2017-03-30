#ifndef MULTIARRAYLAYOUT_SPLTYPES_H
#define MULTIARRAYLAYOUT_SPLTYPES_H

#include "ccpp_MultiArrayLayout_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "MultiArrayDimension_SplDcps.h"

extern c_metaObject __MultiArrayLayout__std_msgs__load (c_base base);

extern c_metaObject __MultiArrayLayout__std_msgs_msg__load (c_base base);

extern c_metaObject __MultiArrayLayout__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__MultiArrayLayout___load (c_base base);
extern const char * __std_msgs_msg_dds__MultiArrayLayout___keys (void);
extern const char * __std_msgs_msg_dds__MultiArrayLayout___name (void);
struct _std_msgs_msg_dds__MultiArrayLayout_ ;
extern  c_bool __std_msgs_msg_dds__MultiArrayLayout___copyIn(c_base base, struct std_msgs::msg::dds_::MultiArrayLayout_ *from, struct _std_msgs_msg_dds__MultiArrayLayout_ *to);
extern  void __std_msgs_msg_dds__MultiArrayLayout___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__MultiArrayLayout_ {
    c_sequence dim_;
    c_ulong data_offset_;
};

#endif
