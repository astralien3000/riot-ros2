APPLICATION = listener

RIOTBASE ?= $(CURDIR)/../../RIOT
ROS2BASE ?= $(CURDIR)/../..

BOARD ?= native
CFLAGS += -DDEVELHELP
QUIET ?= 0

EXTERNAL_MODULE_DIRS += $(ROS2BASE)

USEMODULE += rclcpp rcl
USEMODULE += rmw rmw_fake

USEMODULE += rcl_interfaces
USEMODULE += std_msgs
USEMODULE += rosidl_generator_c
USEMODULE += rosidl_typesupport_introspection_cpp

include $(ROS2BASE)/Makefile.include
include $(RIOTBASE)/Makefile.include
