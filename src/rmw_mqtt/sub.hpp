#ifndef SUB_HPP
#define SUB_HPP

#include "timer.hpp"

#include <vector>

namespace rmw {
namespace mqtt {

class Subscription {
private:
  using FIFO = std::vector<const char*>;

private:
  const char* _topic_name;
  FIFO _data;

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
