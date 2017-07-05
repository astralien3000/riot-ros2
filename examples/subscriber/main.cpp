#include <stdio.h>
#include <math.h>
#include <string.h>

#include <vector>

#include <xtimer.h>

class Timer {
public:
  static unsigned int now(void) { return xtimer_now_usec(); } // in us
};

class Subscription;


namespace rmw {
namespace ndn {

class Application {
private:
  std::vector<Subscription*> _subs;

public:
  static Application& instance(void);

public:
  void add_subscription(Subscription* sub) {
    _subs.push_back(sub);
  }

  void rm_subscription(Subscription* sub) {
    auto rm = _subs.end();
    for(auto it = _subs.begin() ; it != _subs.end() ; it++) {
      if((*it) == sub) {
        rm = it;
        break;
      }
    }
    _subs.erase(rm);
  }

public:
  void send_sync_interest(const char* topic, unsigned int timeout);
  void send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout);

public:
  void test(void);
};

}
}

rmw::ndn::Application& rmw::ndn::Application::instance(void) {
  static rmw::ndn::Application ret;
  return ret;
}

class Subscription {
private:
  using FIFO = std::vector<const char*>;
  using Timer = ::Timer;

private:
  enum State {
    UNSYNCHRONIZED_NOSENT,
    UNSYNCHRONIZED_SENT,
    SYNCHRONIZED_OUTDATED,
    SYNCHRONIZED_UPDATED,
  };

  enum Event {
    INTEREST,
    SYNC,
    SEQ,
    TIMEOUT,
  };

private:
  static const unsigned int MAX_TIMEOUT = 10000000; // 10s, in us
  static const unsigned int MIN_TIMEOUT = 10000; // 10ms, in us

  static const unsigned int MAX_WINDOW = 10;
  static const unsigned int MIN_WINDOW = 2;

private:
  const char* _topic_name;
  State _state;
  unsigned int _seq;
  unsigned int _timeout;
  unsigned int _window;
  FIFO _data;
  unsigned int _last_interest_date;

public:
  Subscription(const char* topic_name)
    : _topic_name(topic_name)
    , _state(UNSYNCHRONIZED_NOSENT)
    , _seq(0)
    , _timeout(MAX_TIMEOUT)
    , _window(MIN_WINDOW) {

    rmw::ndn::Application::instance().add_subscription(this);
    _last_interest_date = Timer::now() - _timeout;
    update();
  }

public:
  const char* get_topic_name(void) {
    return _topic_name;
  }

public:
  void push_data(unsigned int seq, const char* data) {
    if(_seq >= seq) {
      return;
    }

    _seq = seq;
    _data.push_back(data);
    _state = SYNCHRONIZED_UPDATED;

    unsigned int dur = Timer::now() - _last_interest_date;
    if(dur < _timeout / 8) {
      _timeout /= 2;
    }

    rmw::ndn::Application::instance().send_data_interest(_topic_name, _seq, _window, _timeout);
    _last_interest_date = Timer::now();
    _state = SYNCHRONIZED_OUTDATED;
  }

  void on_timeout(void) {
    _state = UNSYNCHRONIZED_NOSENT;
    _timeout *= 2;

    rmw::ndn::Application::instance().send_sync_interest(_topic_name, _timeout);
    _last_interest_date = Timer::now();
    _state = UNSYNCHRONIZED_SENT;
  }

  void update(void) {
    const unsigned int timeout_date = _last_interest_date + _timeout;
    if(timeout_date <= Timer::now()) {
      on_timeout();
    }
  }

  bool can_take(void) {
    return !_data.empty();
  }

  const char* take(void) {
    if(_data.empty()) {
      return NULL;
    }

    const char* ret = _data.front();
    _data.erase(_data.begin());
    return ret;
  }
};

static unsigned int _test_seq = 0;
static unsigned int _last_pub = 0;
static unsigned int _periods[] = { 100000, 10000000 };

void rmw::ndn::Application::test(void) {
  if(Timer::now() < _last_pub+_periods[(_test_seq/10)%(sizeof(_periods)/sizeof(_periods[0]))]) {
    return;
  }
  _last_pub = Timer::now();

  for(auto it = _subs.begin() ; it != _subs.end() ; it++) {
    if(strcmp((*it)->get_topic_name(), "test") == 0) {
      ++_test_seq;
      printf("[%u] recv: /test/%u\n", _last_pub, _test_seq);
      (*it)->push_data(_test_seq, "a");
    }
  }
}

void rmw::ndn::Application::send_sync_interest(const char* topic, unsigned int timeout) {
  printf("[%u] send : /%s/sync (timeout:%u)\n", Timer::now(), topic, timeout);
}

void rmw::ndn::Application::send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout) {
  for(unsigned int i = 1 ; i <= window ; i++) {
    printf("[%u] send : /%s/%u (timeout:%u)\n", Timer::now(), topic, seq+i, timeout);
  }
}

int main(void) {
  Subscription s("test");

  while(1) {
    rmw::ndn::Application::instance().test();
    if(s.can_take()) {
      const char* test = s.take();
      printf("got:%s\n", test);
    }
    s.update();
  }

  return 0;
}
