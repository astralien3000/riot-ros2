#ifndef APP_HPP
#define APP_HPP

#include <vector>

#include <ndn-riot/app.h>

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

  static std::vector<Subscription*>::iterator begin_subscriptions(void);
  static std::vector<Subscription*>::iterator end_subscriptions(void);

public:
  static void send_sync_interest(const char* topic, unsigned int timeout);
  static void send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout);

public:
  static void create(void);
  static void destroy(void);

public:
  static void update(void);
};

}
}

#endif//APP_HPP
