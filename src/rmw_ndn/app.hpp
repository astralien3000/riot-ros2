#ifndef APP_HPP
#define APP_HPP

#include <vector>

extern "C" {
typedef struct ndn_app_t ndn_app_t;
}

namespace rmw {
namespace ndn {

class Subscription;

class Application {
private:
  ndn_app_t* _app = 0;
  std::vector<Subscription*> _subs;

public:
  static Application& instance(void);

public:
  static void add_subscription(Subscription* sub);
  static void rm_subscription(Subscription* sub);

public:
  static void send_sync_interest(const char* topic, unsigned int timeout);
  static void send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout);

public:
  static void create(void);
  static void destroy(void);

public:
  static void update(void);

public:
  static void on_data(void);
};

}
}

#endif//APP_HPP
