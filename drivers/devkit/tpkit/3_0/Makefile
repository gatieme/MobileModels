# Makefile for the irda drivers.
#

# Each configuration option enables a list of files.
#CFLAGS_honor_ts_kit_core.o := -I$(src)
#CFLAGS_honor_ts_kit_api.o := -I$(src)


#ifeq ($(CONFIG_HONOR_GKI_V1),y)
obj-$(CONFIG_HONOR_TS_KIT_3_0) += tpkits.o
tpkits-objs += \
	honor_ts_kit_core.o \
	honor_ts_kit_fsnode.o \
	honor_ts_kit_api.o \
	honor_ts_kit_algo.o \
	honor_ts_kit_csvparse.o \
	honor_ts_kit_misc.o \
	qcom_adapter/tpkit_cmdline_parse.o \
	qcom_adapter/tpkit_platform_adapter.o \
	panel/synaptics_tcm/synaptics_tcm_core.o \
	panel/synaptics_tcm/synaptics_tcm_zeroflash.o \
	panel/synaptics_tcm/synaptics_tcm_touch.o \
	panel/synaptics_tcm/synaptics_tcm_device.o \
	panel/synaptics_tcm/synaptics_tcm_cap_check.o \
	panel/synaptics_tcm/synaptics_tcm_reflash.o
#else
#obj-$(CONFIG_HONOR_TS_KIT_3_0) += tpkits.o panel/
#tpkits-objs += honor_ts_kit_core.o honor_ts_kit_fsnode.o honor_ts_kit_api.o honor_ts_kit_algo.o honor_ts_kit_csvparse.o honor_ts_kit_misc.o qcom_adapter/tpkit_cmdline_parse.o qcom_adapter/tpkit_platform_adapter.o
#endif
EXTRA_CFLAGS += -Itechpack/display
EXTRA_CFLAGS += -Itechpack/display/msm/dsi


ccflags-y += -I$(srctree)/include/oeminfo
ifeq ($(CONFIG_HONOR_DEVKIT_MTK_3_0),y)
obj-$(CONFIG_HONOR_TS_KIT_3_0) += tpkits.o
tpkits-objs += honor_ts_kit_core.o honor_ts_kit_fsnode.o honor_ts_kit_api.o honor_ts_kit_algo.o honor_ts_kit_csvparse.o honor_ts_kit_misc.o mtk_adapter/tpkit_platform_adapter.o
EXTRA_CFLAGS += -Idrivers/tzdriver
endif

obj-$(CONFIG_HONOR_TS_KIT_COMMON_3_0) += honor_tp_common.o
obj-$(CONFIG_HONOR_TP_KIT_COLOR_INFO_3_0) += tp_color.o
EXTRA_CFLAGS += -I$(srctree)/drivers/hwspinlock
EXTRA_CFLAGS += -I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/common/include
EXTRA_CFLAGS += -I$(srctree)/drivers/video/fbdev/honor/dss
EXTRA_CFLAGS += -I$(srctree)/drivers/devkit/lcdkit/lcdkit1.0/core/common
ccflags-y += -Idrivers/misc/mediatek/sensors-1.0/sensorHub/inc_v1

ifeq ($(CONFIG_HONOR_TS_KIT_TEST_3_0),y)
EXTRA_CFLAGS += -DHONOR_TS_KIT_TEST
endif

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DTP_FACTORY_MODE
endif
