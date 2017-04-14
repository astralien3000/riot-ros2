MODULE = ros2

ifneq (,$(filter rclcpp,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rclcpp
endif

ifneq (,$(filter rcl,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rcl
endif

ifneq (,$(filter rmw,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rmw
endif

ifneq (,$(filter rmw_fake,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rmw_fake
endif

include $(RIOTBASE)/Makefile.base
