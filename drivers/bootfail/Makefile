# Makefile for the Boot Detector modules.

obj-$(CONFIG_BOOT_DETECTOR) = bootfail.o

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DFACTORY_MODE_ENABLE
endif

ifeq ($(HLTHERM_RUNTEST), true)
EXTRA_CFLAGS+= -DCONFIG_HLTHERM_RUNTEST
endif

bootfail-y += \
	core/boot_detector.o \
	core/boot_recovery.o \
	common/bootfail_common.o \
	common/bootfail_fs.o \
	common/adapter_common.o \
	common/bootfail_timer.o

ifeq ($(CONFIG_BOOT_DETECTOR_MTK),y)
ccflags-y += -fno-builtin-memset -fno-builtin-memcpy
ccflags-y += -I$(srctree)/drivers/misc/mediatek/log_store
bootfail-y += chipsets/mtk/bootfail_mtk.o
bootfail-y += chipsets/mtk/adapter_mtk.o
endif

ifeq ($(CONFIG_BOOT_DETECTOR_QCOM),y)
bootfail-y += chipsets/qcom/bootfail_qcom.o
bootfail-y += chipsets/qcom/adapter_qcom.o
endif

ifeq ($(CONFIG_BOOT_DETECTOR_MSTAR),y)
bootfail-y += chipsets/mstar/bootfail_mstar.o
bootfail-y += chipsets/mstar/adapter_mstar.o
endif