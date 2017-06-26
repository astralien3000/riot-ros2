APPLICATION = gyro

RIOTBASE ?= ../../../RIOT

RIOTBOARD ?= ../boards
BOARD ?= samr21-xpro-ceres

FEATURES_REQUIRED += periph_gpio
FEATURES_REQUIRED += periph_pwm
FEATURES_REQUIRED += periph_i2c

USEMODULE += l3g4200d
USEMODULE += xtimer

CXXEXFLAGS += -std=c++11

include $(RIOTBASE)/Makefile.include
