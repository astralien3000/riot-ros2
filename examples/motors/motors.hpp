#ifndef MOTORS_HPP
#define MOTORS_HPP

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

class Motors : public Singleton<Motors>, public Service {
private:
  class Left;
  class Right;

public:
  Motors(void);

public:
  Left& left(void) { return *(Left*)this; }
  Right& right(void) { return *(Right*)this; }
};

class Motors::Left : private Motors, public Output<int> {
public:
  void put(int);
};

class Motors::Right : private Motors, public Output<int> {
public:
  void put(int);
};

#endif//MOTORS_HPP
