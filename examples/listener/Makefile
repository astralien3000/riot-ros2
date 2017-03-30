APPLICATION = listener

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
CFLAGS += -DDEVELHELP
QUIET ?= 0

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rclcpp rcl rmw rmw_fake

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
