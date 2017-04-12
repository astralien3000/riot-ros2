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

ifneq (,$(filter rosidl_generator_c,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rosidl_generator_c
endif

ifneq (,$(filter rosidl_typesupport_introspection_cpp,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rosidl_typesupport_introspection_cpp
endif

ifneq (,$(filter rosidl_typesupport_introspection_c,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rosidl_typesupport_introspection_c
endif

ifneq (,$(filter rosidl_typesupport_cpp,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rosidl_typesupport_cpp
endif

include $(RIOTBASE)/Makefile.base
