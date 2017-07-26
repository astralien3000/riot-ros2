#ifndef PUB_HPP
#define PUB_HPP

#include "timer.hpp"

#include <vector>

namespace rmw {
namespace mqtt {

class Publisher {
private:
  using FIFO = std::vector<const char*>;

private:
  const char* _topic_name;

public:
  Publisher(const char* topic_name);

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

public:
  void push_data(const char* data);
};

}
}

#endif//PUB_HPP
