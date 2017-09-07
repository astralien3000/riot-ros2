#ifndef GYRO_HPP
#define GYRO_HPP

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

#include <stdint.h>
#include "math.hpp"

class Gyro : public Singleton<Gyro>, public Service {
private:
  class Updater;

private:
  struct Config {
    int32_t gyro2rad = -15000;
  };

protected:
  int32_t x_angle;
  int32_t y_angle;
  int32_t z_angle;

  Config _config;

public:
  Gyro(void);

public:
  inline float getXAngle(void) {
    return x_angle * M_PI / _config.gyro2rad;
  }

  inline void putXAngle(float val) {
    x_angle = (val / M_PI) * _config.gyro2rad;
  }

  inline float getYAngle(void) {
    return y_angle * M_PI / _config.gyro2rad;
  }

  inline void putYAngle(float val) {
    y_angle = (val / M_PI) * _config.gyro2rad;
  }

  inline float getZAngle(void) {
    return z_angle * M_PI / _config.gyro2rad;
  }

  inline void putZAngle(float val) {
    z_angle = (val / M_PI) * _config.gyro2rad;
  }

  inline Updater& updater(void) { return *(Updater*)this; }
  inline Config& config(void) { return _config; }
};

class Gyro::Updater : private Gyro {
public:
  static const int FREQ = 100;

public:
  void update(void);
};

#endif//GYRO_HPP
