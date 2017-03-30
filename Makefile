MODULE = ros2

DIRS += $(CURDIR)/src/rclcpp
DIRS += $(CURDIR)/src/rcl
DIRS += $(CURDIR)/src/rmw
DIRS += $(CURDIR)/src/rmw_fake

include $(RIOTBASE)/Makefile.base
