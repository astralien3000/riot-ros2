APPLICATION = talker

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
CFLAGS += -DDEVELHELP
QUIET ?= 0
WERROR ?= 0

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rclcpp
USEMODULE += rcl
USEMODULE += rmw

RMW ?= rmw_fake
USEMODULE += $(RMW)

USEMODULE += rosidl_generator_c
USEMODULE += rosidl_typesupport_introspection_cpp
USEMODULE += std_msgs
USEMODULE += rcl_interfaces

LINKFLAGS += -lpthread
CFLAGS += -DUSE_SHARED_POINTER

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
