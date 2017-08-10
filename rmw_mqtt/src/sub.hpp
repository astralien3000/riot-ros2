#ifndef SUB_HPP
#define SUB_HPP

#include "net/emcute.h"

#include <vector>

namespace rmw {
namespace mqtt {

class Subscription {
public:
  emcute_sub_t sub;
  
private:
  using FIFO = std::vector<const char*>;

private:
  FIFO _data;

public:
  Subscription(const char* topic_name);

public:
  inline const char* get_topic_name(void) {
    return sub.topic.name;
  }

  inline bool can_take(void) {
    return !_data.empty();
  }

  void push_data(const char* data) {
    _data.push_back(data);
  }

  const char* take(void);
};

}
}

#endif//SUB_HPP
