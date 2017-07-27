APPLICATION = listener

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
QUIET ?= 0

LINKFLAGS += -lstdc++

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rcl
USEMODULE += rclc
USEMODULE += rmw

#USEMODULE += rmw_ndn
USEMODULE += rmw_mqtt

USEMODULE += rosidl_generator_c
USEMODULE += rosidl_typesupport_introspection_c
USEMODULE += std_msgs

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
