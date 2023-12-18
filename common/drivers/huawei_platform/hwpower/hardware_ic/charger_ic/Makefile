ifeq ($(CONFIG_HUAWEI_POWER_GLINK), y)
	obj-$(CONFIG_HUAWEI_CHARGER) += adsp_charger.o
	obj-$(CONFIG_HUAWEI_CHARGER_AP) += adsp_charger.o
else ifeq ($(CONFIG_HUAWEI_POWER_GLINK_INTERFACE), y)
	obj-$(CONFIG_HUAWEI_CHARGER) += adsp_charger.o
	obj-$(CONFIG_HUAWEI_CHARGER_AP) += adsp_charger.o
else
	obj-$(CONFIG_HUAWEI_CHARGER) += nonadsp_charger.o
	obj-$(CONFIG_HUAWEI_CHARGER_AP) += nonadsp_charger.o
endif
