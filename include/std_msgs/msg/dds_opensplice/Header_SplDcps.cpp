#include "Header_SplDcps.h"
#include "ccpp_Header_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__Header___name(void)
{
    return (const char*)"std_msgs::msg::dds_::Header_";
}

const char *
__std_msgs_msg_dds__Header___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__Header___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::Header_ *from,
    struct _std_msgs_msg_dds__Header_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    if(result){
        extern c_bool __DDS_Time_t__copyIn(c_base, ::DDS::Time_t *, _DDS_Time_t *);
        result = __DDS_Time_t__copyIn(base, &from->stamp_, &to->stamp_);
    }
#ifdef OSPL_BOUNDS_CHECK
    if(from->frame_id_){
        to->frame_id_ = c_stringNew(base, from->frame_id_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'std_msgs::msg::dds_::Header_.frame_id_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->frame_id_ = c_stringNew(base, from->frame_id_);
#endif
    return result;
}

void
__std_msgs_msg_dds__Header___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__Header_ *from = (struct _std_msgs_msg_dds__Header_ *)_from;
    struct ::std_msgs::msg::dds_::Header_ *to = (struct ::std_msgs::msg::dds_::Header_ *)_to;
    {
        extern void __DDS_Time_t__copyOut(void *, void *);
        __DDS_Time_t__copyOut((void *)&from->stamp_, (void *)&to->stamp_);
    }
    to->frame_id_ = DDS::string_dup(from->frame_id_ ? from->frame_id_ : "");
}

