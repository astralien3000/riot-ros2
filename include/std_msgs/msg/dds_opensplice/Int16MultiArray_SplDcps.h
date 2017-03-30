#ifndef INT16MULTIARRAY_SPLTYPES_H
#define INT16MULTIARRAY_SPLTYPES_H

#include "ccpp_Int16MultiArray_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "MultiArrayLayout_SplDcps.h"

extern c_metaObject __Int16MultiArray__std_msgs__load (c_base base);

extern c_metaObject __Int16MultiArray__std_msgs_msg__load (c_base base);

extern c_metaObject __Int16MultiArray__std_msgs_msg_dds___load (c_base base);

extern c_metaObject __std_msgs_msg_dds__Int16MultiArray___load (c_base base);
extern const char * __std_msgs_msg_dds__Int16MultiArray___keys (void);
extern const char * __std_msgs_msg_dds__Int16MultiArray___name (void);
struct _std_msgs_msg_dds__Int16MultiArray_ ;
extern  c_bool __std_msgs_msg_dds__Int16MultiArray___copyIn(c_base base, struct std_msgs::msg::dds_::Int16MultiArray_ *from, struct _std_msgs_msg_dds__Int16MultiArray_ *to);
extern  void __std_msgs_msg_dds__Int16MultiArray___copyOut(void *_from, void *_to);
struct _std_msgs_msg_dds__Int16MultiArray_ {
    struct _std_msgs_msg_dds__MultiArrayLayout_ layout_;
    c_sequence data_;
};

#endif
