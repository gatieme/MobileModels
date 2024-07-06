ccflags-$(CONFIG_SECURITY_INFO) += -I$(srctree)/drivers/platform_drivers/tzdriver
ccflags-$(CONFIG_VENDOR_EFUSE)  += -I$(srctree)/drivers/platform_drivers/efuse

obj-$(CONFIG_DFX_DEBUG_FS)	+= efuse_driver_debugfs.o

ifeq ($(CONFIG_EFUSE_SUPPORT_FFA), y)
obj-$(CONFIG_VENDOR_EFUSE)	+= efuse_call_ffa.o
obj-$(CONFIG_VENDOR_EFUSE)	+= custom_call/efuse_cust_rw_ffa.o
else
obj-$(CONFIG_VENDOR_EFUSE)	+= efuse_call_smc.o
obj-$(CONFIG_VENDOR_EFUSE)	+= custom_call/efuse_cust_rw_smc.o
endif

obj-$(CONFIG_VENDOR_EFUSE)	+= common_call/efuse.o
obj-$(CONFIG_VENDOR_EFUSE)	+= common_call/efuse_internal.o

obj-$(CONFIG_VENDOR_EFUSE)	+= custom_call/efuse_driver.o
obj-$(CONFIG_GENERAL_SEE)	+= custom_call/flash_general_see_otp.o