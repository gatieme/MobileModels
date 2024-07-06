obj-$(CONFIG_HISI_TCPC)				+= hisi-tcpc/
obj-$(CONFIG_VENDOR_USB_TYPEC)			+= hisi-usb-typec.o
obj-$(CONFIG_CS32G_USB_PD)			+= oem_typec.o
ifeq ($(CONFIG_TCPC_CLASS),y)
obj-$(CONFIG_VENDOR_USB_TYPEC)			+= oem-typec-adapter.o
obj-$(CONFIG_USB_VBUS_CTRL)			+= hisi_usb_vbus_ctrl.o
else
obj-$(CONFIG_VENDOR_USB_TYPEC)		        += vendor-typec-adapter.o
endif
