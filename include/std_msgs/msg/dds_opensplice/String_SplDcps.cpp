#include "String_SplDcps.h"
#include "ccpp_String_.h"
#include "dds_type_aliases.h"

const char *
__std_msgs_msg_dds__String___name(void)
{
    return (const char*)"std_msgs::msg::dds_::String_";
}

const char *
__std_msgs_msg_dds__String___keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__std_msgs_msg_dds__String___copyIn(
    c_base base,
    struct ::std_msgs::msg::dds_::String_ *from,
    struct _std_msgs_msg_dds__String_ *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->data_){
        to->data_ = c_stringNew(base, from->data_);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'std_msgs::msg::dds_::String_.data_' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->data_ = c_stringNew(base, from->data_);
#endif
    return result;
}

void
__std_msgs_msg_dds__String___copyOut(
    void *_from,
    void *_to)
{
    struct _std_msgs_msg_dds__String_ *from = (struct _std_msgs_msg_dds__String_ *)_from;
    struct ::std_msgs::msg::dds_::String_ *to = (struct ::std_msgs::msg::dds_::String_ *)_to;
    to->data_ = DDS::string_dup(from->data_ ? from->data_ : "");
}

