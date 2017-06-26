#ifndef GYRO_HPP
#define GYRO_HPP

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

#include <stdint.h>
#include "math.hpp"

class Gyro : public Singleton<Gyro>, public Service {
private:
  class Angle;
  class Updater;

private:
  struct Config {
    int32_t gyro2rad = -15000;
  };

protected:
  int32_t _angle;
  Config _config;

public:
  Gyro(void);

public:
  inline Angle& angle(void) { return *(Angle*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }
  inline Config& config(void) { return _config; }
};

class Gyro::Angle : private Gyro, public Input<float>, public Output<float> {
public:
  inline float get(void) {
    return _angle * M_PI / _config.gyro2rad;
  }

  inline void put(float val) {
    _angle = (val / M_PI) * _config.gyro2rad;
  }
};

class Gyro::Updater : private Gyro {
public:
  static const int FREQ = 100;

public:
  void update(void);
};

#endif//GYRO_HPP
