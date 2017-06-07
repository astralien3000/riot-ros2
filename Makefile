MODULE = ros2

ifneq (,$(filter rclcpp,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rclcpp
endif

ifneq (,$(filter rclc,$(USEMODULE)))
    DIRS += $(CURDIR)/src/rclc
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

ifneq (,$(filter rcl_interfaces,$(USEMODULE)))
    ifneq (,$(filter rosidl_typesupport_introspection_cpp,$(USEMODULE)))
        DIRS += $(CURDIR)/generated/rcl_interfaces/rosidl_typesupport_introspection_cpp
    endif
endif

ifneq (,$(filter std_msgs,$(USEMODULE)))
    ifneq (,$(filter rosidl_typesupport_introspection_cpp,$(USEMODULE)))
        DIRS += $(CURDIR)/generated/std_msgs/rosidl_typesupport_introspection_cpp
    endif
    ifneq (,$(filter rosidl_typesupport_introspection_c,$(USEMODULE)))
        DIRS += $(CURDIR)/generated/std_msgs/rosidl_typesupport_introspection_c
    endif
endif

include $(RIOTBASE)/Makefile.base
