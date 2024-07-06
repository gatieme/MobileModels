ccflags-y += -Idrivers/devkit/audiokit/

obj-y += hw_pd.o
obj-y += hw_usb_vbus.o

ifdef CONFIG_TCPC_RT1715
obj-$(CONFIG_TCPC_RT1715) += rt1715/
else
obj-$(CONFIG_RT_USB_PD) += richtek/
endif
obj-$(CONFIG_FSC_USB_PD) += fsc/
