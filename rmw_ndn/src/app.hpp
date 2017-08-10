#ifndef APP_HPP
#define APP_HPP

#include <vector>

#include <ndn-riot/app.h>

namespace rmw {
namespace ndn {

class Subscription;
class Publisher;

class Application {
private:
  ndn_app_t* _app = 0;
  std::vector<Subscription*> _subs;
  std::vector<Publisher*> _pubs;

public:
  static Application& instance(void);

public:
  static void add_subscription(Subscription* sub);
  static void rm_subscription(Subscription* sub);

  static std::vector<Subscription*>::iterator begin_subscriptions(void);
  static std::vector<Subscription*>::iterator end_subscriptions(void);

public:
  static void add_publisher(Publisher* pub);
  static void rm_publisher(Publisher* pub);

  static std::vector<Publisher*>::iterator begin_publisher(void);
  static std::vector<Publisher*>::iterator end_publisher(void);

public:
  static void send_sync_interest(const char* topic, unsigned int timeout);
  static void send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout);

public:
  static void publish(const char* topic, unsigned int seq, const char* data, size_t size);

public:
  static void create(void);
  static void destroy(void);

public:
  static void update(void);

public:
  static ndn_app_t* get_app(void) {
    return instance()._app;
  }
};

}
}

#endif//APP_HPP
