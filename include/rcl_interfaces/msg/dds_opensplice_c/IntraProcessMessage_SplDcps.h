#ifndef INTRAPROCESSMESSAGE_SPLTYPES_H
#define INTRAPROCESSMESSAGE_SPLTYPES_H

#include "ccpp_IntraProcessMessage_.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __IntraProcessMessage__rcl_interfaces__load (c_base base);

extern c_metaObject __IntraProcessMessage__rcl_interfaces_msg__load (c_base base);

extern c_metaObject __IntraProcessMessage__rcl_interfaces_msg_dds___load (c_base base);

extern c_metaObject __rcl_interfaces_msg_dds__IntraProcessMessage___load (c_base base);
extern const char * __rcl_interfaces_msg_dds__IntraProcessMessage___keys (void);
extern const char * __rcl_interfaces_msg_dds__IntraProcessMessage___name (void);
struct _rcl_interfaces_msg_dds__IntraProcessMessage_ ;
extern  c_bool __rcl_interfaces_msg_dds__IntraProcessMessage___copyIn(c_base base, struct rcl_interfaces::msg::dds_::IntraProcessMessage_ *from, struct _rcl_interfaces_msg_dds__IntraProcessMessage_ *to);
extern  void __rcl_interfaces_msg_dds__IntraProcessMessage___copyOut(void *_from, void *_to);
struct _rcl_interfaces_msg_dds__IntraProcessMessage_ {
    c_ulonglong publisher_id_;
    c_ulonglong message_sequence_;
};

#endif
