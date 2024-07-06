#
# Makefile for the linux kernel.
#

-include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk
ccflags-y := -Werror
ccflags-y += -Iinclude/linux -I$(srctree)/drivers/platform_drivers/modem/drv/include -I$(srctree)/drivers/platform_drivers/modem/drv/sys_bus/intf -I$(srctree)/drivers/platform_drivers/modem/drv/sys_bus/test

#add frame files
obj-y += frame/sys_bus_core.o
obj-y += frame/sys_bus_cmd.o

#add test files
obj-y += test/sys_sample.o
obj-y += test/sys_odt.o
obj-y += test/sys_acore.o
