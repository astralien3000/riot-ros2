APPLICATION = listener

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
CFLAGS += -DDEVELHELP
QUIET ?= 0

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
