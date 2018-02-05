#ifndef SUB_HPP
#define SUB_HPP

#include "app.h"

#include "timer.hpp"

#include <vector>
#include <utility>

namespace rmw {
namespace ndn {

class Subscription : sub_t {

public:
  static const unsigned int MAX_TIMEOUT = 2000000; // 2s,   in us
  static const unsigned int MIN_TIMEOUT =   10000; // 10ms, in us

  static const unsigned int MAX_WINDOW = 10;
  static const unsigned int MIN_WINDOW = 1;

private:


public:
  Subscription(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t));

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

  inline bool can_take(void) {
    return _data.next;
  }

public:
  void on_timeout(void);


  bool take(void* msg);
};

static_assert(sizeof(Subscription) == sizeof(sub_t), "ERROR");

}
}

#endif//SUB_HPP
