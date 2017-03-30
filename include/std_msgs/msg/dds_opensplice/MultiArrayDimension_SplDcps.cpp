#include "MultiArrayDimension_SplDcps.h"
#include "ccpp_MultiArrayDimension_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__MultiArrayDimension___name(void)
{
    return (const char*)"std_msgs::msg::dds_::MultiArrayDimension_";
}

const char *
__std_msgs_msg_dds__MultiArrayDimension___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__MultiArrayDimension___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::MultiArrayDimension_ *from,
    struct _std_msgs_msg_dds__MultiArrayDimension_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->label_){
        to->label_ = c_stringNew(base, from->label_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'std_msgs::msg::dds_::MultiArrayDimension_.label_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->label_ = c_stringNew(base, from->label_);
#endif
    to->size_ = (c_ulong)from->size_;
    to->stride_ = (c_ulong)from->stride_;
    return result;
}

void
__std_msgs_msg_dds__MultiArrayDimension___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__MultiArrayDimension_ *from = (struct _std_msgs_msg_dds__MultiArrayDimension_ *)_from;
    struct ::std_msgs::msg::dds_::MultiArrayDimension_ *to = (struct ::std_msgs::msg::dds_::MultiArrayDimension_ *)_to;
    to->label_ = DDS::string_dup(from->label_ ? from->label_ : "");
    to->size_ = (::DDS::ULong)from->size_;
    to->stride_ = (::DDS::ULong)from->stride_;
}

