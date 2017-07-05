#include "sub.hpp"

#include "app.hpp"

using App = rmw::ndn::Application;

rmw::ndn::Subscription::Subscription(const char* topic_name)
  : _topic_name(topic_name)
  , _state(UNSYNCHRONIZED_NOSENT)
  , _seq(0)
  , _timeout(MAX_TIMEOUT)
  , _window(MIN_WINDOW) {

  App::add_subscription(this);
  _last_interest_date = Timer::now() - _timeout;
  update();
}

void rmw::ndn::Subscription::push_data(unsigned int seq, const char* data) {
  if(_seq >= seq) {
    return;
  }

  _seq = seq;
  _data.push_back(data);
  _state = SYNCHRONIZED_UPDATED;

  const Timer::us dur = Timer::now() - _last_interest_date;
  if(dur < _timeout / 8) {
    _timeout /= 2;
  }

  App::send_data_interest(_topic_name, _seq, _window, _timeout);
  _last_interest_date = Timer::now();
  _state = SYNCHRONIZED_OUTDATED;
}

void rmw::ndn::Subscription::on_timeout(void) {
  _state = UNSYNCHRONIZED_NOSENT;
  _timeout *= 2;

  App::send_sync_interest(_topic_name, _timeout);
  _last_interest_date = Timer::now();
  _state = UNSYNCHRONIZED_SENT;
}

void rmw::ndn::Subscription::update(void) {
  const Timer::us timeout_date = _last_interest_date + _timeout;
  if(timeout_date <= Timer::now()) {
    on_timeout();
  }
}

const char* rmw::ndn::Subscription::take(void) {
  if(_data.empty()) {
    return NULL;
  }

  const char* ret = _data.front();
  _data.erase(_data.begin());
  return ret;
}
