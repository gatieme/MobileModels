obj-$(CONFIG_LCD_KIT_SPRD) 	+= lcd_kit_utils.o
obj-$(CONFIG_LCD_KIT_SPRD) 	+= lcd_kit_panel.o
obj-$(CONFIG_LCD_KIT_SPRD) 	+= lcd_kit_power.o
obj-$(CONFIG_LCD_KIT_SPRD) 	+= lcd_kit_drm_panel.o
obj-$(CONFIG_LCD_KIT_SPRD) 	+= bias/
obj-$(CONFIG_LCD_KIT_SPRD) 	+= backlight/

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DLCD_FACTORY_MODE
endif
EXTRA_CFLAGS +=-Idrivers/staging/android \
		-Idrivers/atfdriver \
		-Idrivers/devkit/lcdkit/lcdkit3.0 \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/common/include \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/sprd/include \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/sprd/adapt \
		-Iinclude/drm

ccflags-$(CONFIG_LCD_KIT_SPRD) += -I$(srctree)/drivers/gpu/drm/ \
		-I$(srctree)/drivers/gpu/drm/sprd/
