#ifndef PUB_HPP
#define PUB_HPP

#include "app.h"

#ifdef __cplusplus
extern "C" {
#endif

void pub_init(pub_t* pub, const char* topic_name, size_t (*serialize)(const void*, char*, size_t));

pub_t* pub_create(const char* topic_name, size_t (*serialize)(const void*, char*, size_t));
void pub_destroy(pub_t* pub);

void pub_push_data(pub_t* pub, const void* msg);

#ifdef __cplusplus
}
#endif

#endif//PUB_HPP
