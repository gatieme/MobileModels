# deviceboxID driver

ifneq ($(TARGET_BUILD_VARIANT), user)
	ccflags-y += -DDEVICEBOXID_DEBUG
endif
obj-$(CONFIG_HONOR_DEVICEBOX_AUDIO) += boxid.o
