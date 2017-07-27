#ifndef APP_HPP
#define APP_HPP

#include <vector>

namespace rmw {
namespace mqtt {

class Subscription;
class Publisher;

class Application {
private:
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
  static void publish(const char* topic, const char* data);

public:
  static void create(const char* name);
  static void destroy(void);

public:
  static void update(void);
};

}
}

#endif//APP_HPP
