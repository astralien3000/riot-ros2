#ifndef SUB_HPP
#define SUB_HPP

#include "timer.hpp"

#include <vector>

namespace rmw {
namespace ndn {

class Subscription {
private:
  using FIFO = std::vector<const char*>;

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
  Timer::us _timeout;
  unsigned int _window;
  FIFO _data;
  Timer::us _last_interest_date;

public:
  Subscription(const char* topic_name);

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

  inline bool can_take(void) {
    return !_data.empty();
  }

public:
  void push_data(unsigned int seq, const char* data);
  void on_timeout(void);

  void update(void);

  const char* take(void);
};

}
}

#endif//SUB_HPP
