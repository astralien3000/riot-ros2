#ifndef PUB_HPP
#define PUB_HPP

#include "app.h"

#include "timer.hpp"

#include <vector>
#include <utility>

namespace rmw {
namespace ndn {

class Publisher : pub_t {
private:
  static const unsigned int MAX_QUEUE = 1;

public:
  Publisher(const char* topic_name, size_t (*serialize)(const void*, char*, size_t));

public:
  void push_data(const void* msg);
};

static_assert(sizeof(Publisher) == sizeof(pub_t), "ERROR");

}
}

#endif//PUB_HPP
