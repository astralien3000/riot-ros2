#include "gyro.hpp"

#include "l3g4200d.h"

#define GYRO_MODE        L3G4200D_MODE_100_25
#define GYRO_SCALE       L3G4200D_SCALE_250DPS

#define GYRO_I2C  I2C_DEV(0)
#define GYRO_ADDR 105
#define GYRO_INT  GPIO_PIN(PA, 19)
#define GYRO_DR   GPIO_PIN(PA, 18)

static l3g4200d_t dev;

void Gyro::Updater::update(void) {
  if(state() == RUN) {
    l3g4200d_data_t data = { 0,0,0 };
    l3g4200d_read(&dev, &data);
    _angle += data.acc_z;
  }
}

Gyro::Gyro(void)
  : _angle(0) {
  if (l3g4200d_init(&dev, GYRO_I2C, GYRO_ADDR, GYRO_INT, GYRO_DR, GYRO_MODE, GYRO_SCALE) != 0) {
    setState(ERROR);
    return;
  }
}
