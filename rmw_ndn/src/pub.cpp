#include "pub.hpp"

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

#include <string.h>

using namespace rmw::ndn;
using App = Application;

Publisher::Publisher(const char* topic_name, size_t (*serialize)(const void*, char*, size_t))
  : _cur_seq(0)
  , _req_seq(0)
  , _serialize(serialize) {

  _topic_name = (char*)malloc(strlen(topic_name));
  strcpy(_topic_name, topic_name);
  App::add_publisher(this);
}

void Publisher::on_interest(unsigned int seq) {
  if(_req_seq < seq) {
    _req_seq = seq;
  }

  if(_cur_seq <= _req_seq) {
    App::publish(_topic_name, _cur_seq, std::get<0>(_data.back()), std::get<1>(_data.back()));
  }
}

void Publisher::push_data(const void* msg) {
  char* data = (char*)malloc(64);
  size_t size = 0;
  
  size = _serialize(msg, data, 64);
  data = (char*)realloc(data, size);
  DEBUG("push_data(%s) on %s\n", data, _topic_name);

  if(_data.size() >= MAX_QUEUE) {
    _data.erase(_data.begin());
  }

  _cur_seq++;
  _data.push_back(std::make_pair(data, size));

  if(_cur_seq <= _req_seq) {
    App::publish(_topic_name, _cur_seq, data, size);
  }
}
