#ifndef SUB_HPP
#define SUB_HPP

#include "timer.hpp"

#include <vector>
#include <utility>

namespace rmw {
namespace ndn {

class Subscription {
private:
  using FIFO = std::vector<std::pair<const char*,size_t>>;

private:
  enum State {
    UNSYNCHRONIZED_NOSENT,
    UNSYNCHRONIZED_SENT,
    SYNCHRONIZED_OUTDATED,
    SYNCHRONIZED_UPDATED,
  };

private:
  static const unsigned int MAX_TIMEOUT = 2000000; // 2s,   in us
  static const unsigned int MIN_TIMEOUT =   10000; // 10ms, in us

  static const unsigned int MAX_WINDOW = 10;
  static const unsigned int MIN_WINDOW = 1;

private:
  const char* _topic_name;
  State _state;
  unsigned int _seq;
  Timer::us _timeout;
  unsigned int _window;
  FIFO _data;
  Timer::us _last_interest_date;
  
  size_t (*_deserialize)(void*, const char*, size_t);

public:
  Subscription(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t));

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

  inline bool can_take(void) {
    return !_data.empty();
  }

public:
  void push_data(unsigned int seq, const char* data, size_t size);
  void on_timeout(void);

  void update(void);

  bool take(void* msg);
};

}
}

#endif//SUB_HPP
