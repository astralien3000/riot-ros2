#include "sub.hpp"

#include "app.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

using namespace rmw::ndn;
using App = Application;

Subscription::Subscription(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t))
  : _topic_name(topic_name)
  , _state(UNSYNCHRONIZED_NOSENT)
  , _seq(0)
  , _timeout(MAX_TIMEOUT)
  , _window(MIN_WINDOW)
  , _deserialize(deserialize) {

  App::add_subscription(this);
  _last_interest_date = Timer::now() - _timeout;
  update();
}

void Subscription::push_data(unsigned int seq, const char* data, size_t size) {
  DEBUG("push_data(%u, data, %u)\n", seq, (unsigned int)size);

  if(_seq >= seq) {
    return;
  }

  _seq = seq;
  _data.push_back(std::make_pair(data, size));
  _state = SYNCHRONIZED_UPDATED;

  const Timer::us dur = Timer::now() - _last_interest_date;
  if(dur < _timeout / 4) {
    _timeout /= 2;
    if(_timeout < MIN_TIMEOUT) {
      _timeout = MIN_TIMEOUT;
    }
  }

  App::send_data_interest(_topic_name, _seq+1, _window, _timeout);
  _last_interest_date = Timer::now();
  _state = SYNCHRONIZED_OUTDATED;
}

void Subscription::on_timeout(void) {
  _state = UNSYNCHRONIZED_NOSENT;
  _timeout *= 2;
  if(_timeout > MAX_TIMEOUT) {
    _timeout = MAX_TIMEOUT;
  }

  App::send_sync_interest(_topic_name, _timeout);
  _last_interest_date = Timer::now();
  _state = UNSYNCHRONIZED_SENT;
}

void Subscription::update(void) {
  const Timer::us timeout_date = _last_interest_date + _timeout;
  if(timeout_date <= Timer::now()) {
    on_timeout();
  }
}

void Subscription::take(void* msg) {
  if(_data.empty()) {
    return;
  }

  auto ret = _data.front();
  _data.erase(_data.begin());
  size_t tmp = _deserialize(msg, std::get<0>(ret), std::get<1>(ret));
}
