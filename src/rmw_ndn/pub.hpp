#ifndef PUB_HPP
#define PUB_HPP

#include "timer.hpp"

#include <vector>
#include <utility>

namespace rmw {
namespace ndn {

class Publisher {
private:
  using FIFO = std::vector<std::pair<const char*,size_t>>;

private:
  static const unsigned int MAX_QUEUE = 1;

private:
  const char* _topic_name;
  unsigned int _cur_seq;
  unsigned int _req_seq;
  FIFO _data;
  
  size_t (*_serialize)(const void*, char*, size_t);

public:
  Publisher(const char* topic_name, size_t (*serialize)(const void*, char*, size_t));

public:
  inline const char* get_topic_name(void) {
    return _topic_name;
  }

public:
  inline void get_sync_data(unsigned int* seq, const char** data, size_t* size) {
    *seq = _cur_seq;
    if(!_data.empty()) {
      *data = std::get<0>(_data.back());
      *size = std::get<1>(_data.back());
    }
    else {
      *data = NULL;
    }
  }

public:
  void on_interest(unsigned int seq);

  void push_data(const void* msg);
};

}
}

#endif//PUB_HPP
