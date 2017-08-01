#include "pub.hpp"

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

using namespace rmw::ndn;
using App = Application;

Publisher::Publisher(const char* topic_name)
  : _topic_name(topic_name)
  , _cur_seq(0)
  , _req_seq(0) {
  App::add_publisher(this);
}

void Publisher::on_interest(unsigned int seq) {
  if(_req_seq < seq) {
    _req_seq = seq;
  }

  if(_cur_seq <= _req_seq) {
    App::publish(_topic_name, _cur_seq, _data.back());
  }
}

void Publisher::push_data(const char* data) {
  DEBUG("push_data(%s)\n", data);

  if(_data.size() >= MAX_QUEUE) {
    _data.erase(_data.begin());
  }

  _cur_seq++;
  _data.push_back(data);

  if(_cur_seq <= _req_seq) {
    App::publish(_topic_name, _cur_seq, data);
  }
}
