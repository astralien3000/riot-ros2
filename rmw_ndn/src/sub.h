#ifndef SUB_HPP
#define SUB_HPP

#include "app.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void sub_init(sub_t* sub, const char* topic_name, size_t (*deserialize)(void*, const char*, size_t));

sub_t* sub_create(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t));
void sub_destroy(sub_t* sub);

static inline bool sub_can_take(sub_t* sub) {
  return sub->_data.next;
}

void sub_on_timeout(sub_t* sub);

bool sub_take(sub_t* sub, void* msg);

#ifdef __cplusplus
}
#endif

#endif//SUB_HPP
