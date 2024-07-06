ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DLCD_FACTORY_MODE
endif

obj-y	+= lcd_kit_displayengine.o
obj-y	+= lcd_kit_local_hbm.o
obj-y	+= lcd_kit_ddic_ram.o
obj-y	+= lcd_kit_panel_irc.o

EXTRA_CFLAGS += -I$(srctree)/include/platform_include/display/dkmd \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0 \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/common/include \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/dkmd/include \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/dkmd/adapt \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/dkmd/displayengine \
		-I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/dkmd/displayengine/include \
