-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

ifeq ($(strip $(CFG_CHR_V100)),YES)
obj-y           += chr_v100/
else
obj-y           += chr_v200/
endif
