APPLICATION = talker

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
QUIET ?= 0
WERROR ?= 0

LINKFLAGS += -lstdc++

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rcl
USEMODULE += rclc
USEMODULE += rmw

RMW ?= rmw_ndn
USEMODULE += $(RMW)

USEMODULE += rosidl_generator_c
USEMODULE += rosidl_typesupport_introspection_c
USEMODULE += std_msgs

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
