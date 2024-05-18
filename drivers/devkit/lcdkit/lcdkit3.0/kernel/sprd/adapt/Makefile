obj-$(CONFIG_LCD_KIT_SPRD)	+= lcd_kit_adapt.o
obj-$(CONFIG_LCD_KIT_SPRD)	+= lcd_kit_sysfs_sprd.o
obj-$(CONFIG_LCD_KIT_SPRD)	+= bias_bl_utils.o
ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DLCD_FACTORY_MODE
endif
EXTRA_CFLAGS += -Idrivers/staging/android \
		-Idrivers/atfdriver \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/common/include \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/sprd/include \
		-Idrivers/base
ccflags-$(CONFIG_LCD_KIT_SPRD) += -I$(srctree)/drivers/gpu/drm/ \
		-I$(srctree)/drivers/gpu/drm/sprd/
