# Makefile for the smartpa devkit drivers.
#

# Each configuration option enables a list of files.
ifeq ($(TARGET_BUILD_VARIANT),eng)
	ccflags-y += -DSMARTPAKIT_MISC_RW_PERMISSION_ENABLE
endif
ifdef CONFIG_HONOR_SMARTPAKIT_AUDIO
	ccflags-y += -I$(srctree)/drivers/audiokit/
endif
obj-$(CONFIG_HONOR_SMARTPAKIT_AUDIO) += smartpakit.o

smartpakit_i2c-objs := smartpakit_i2c_ops.o
ifneq ($(TARGET_BUILD_VARIANT),user)
	smartpakit_i2c-objs += smartpakit_info.o
endif
smartpakit_i2c-objs += smartpakit_awinic.o
obj-$(CONFIG_HONOR_SMARTPAKIT_AUDIO) += smartpakit_i2c.o
obj-$(CONFIG_SND_SOC_SELF_DEV_PA) += external_requirement.o
obj-$(CONFIG_HONOR_ARMPC_PLATFORM) += smartpakit_i2c_pm.o
