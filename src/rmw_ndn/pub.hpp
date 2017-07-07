#ifndef PUB_HPP
#define PUB_HPP

#include "timer.hpp"

#include <vector>

namespace rmw {
namespace ndn {

class Publisher {
private:
  using FIFO = std::vector<const char*>;

private:
  static const unsigned int MAX_QUEUE = 1;

private:
  const char* _topic_name;
  unsigned int _cur_seq;
  unsigned int _req_seq;
  FIFO _data;

public:
  Publisher(const char* topic_name);

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

public:
  inline void get_sync_data(unsigned int* seq, const char** data) {
    *seq = _cur_seq;
    if(!_data.empty()) {
      *data = _data.back();
    }
    else {
      *data = NULL;
    }
  }

public:
  void on_interest(unsigned int seq);

  void push_data(const char* data);
};

}
}

#endif//PUB_HPP
