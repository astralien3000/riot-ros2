APPLICATION = listener

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
CFLAGS += -DDEVELHELP
QUIET ?= 0

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rcl
USEMODULE += rclc
USEMODULE += rmw
USEMODULE += rmw_ndn
USEMODULE += rosidl_generator_c
USEMODULE += rosidl_typesupport_introspection_c
USEMODULE += std_msgs

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
