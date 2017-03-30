MODULE = ros2

DIRS += $(CURDIR)/src/rclcpp
DIRS += $(CURDIR)/src/rcl
DIRS += $(CURDIR)/src/rmw
DIRS += $(CURDIR)/src/rmw_fake
DIRS += $(CURDIR)/src/rosidl_generator_c
DIRS += $(CURDIR)/src/rosidl_typesupport_introspection_cpp
DIRS += $(CURDIR)/src/rosidl_typesupport_cpp

include $(RIOTBASE)/Makefile.base
