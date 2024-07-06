subdir-ccflags-y := -Werror
 -include $(srctree)/drivers/platform_drivers/modem/drv/product_config/product_config.mk

obj-y += vdev_core.o vdev_msg.o vdev_app.o vdev_relay.o vdev_socket.o vdev_om.o
ifeq ($(strip $(CFG_CONFIG_VDEV_BRIDGE)),YES)
obj-y += vdev_bridge.o
endif

ifeq ($(strip $(CFG_CONFIG_VDEV_PHONE)),YES)
obj-y += vdev_proc.o
endif

ifeq ($(strip $(CFG_CONFIG_VDEV_DEBUG)),YES)
obj-y += vdev_atp.o
endif
