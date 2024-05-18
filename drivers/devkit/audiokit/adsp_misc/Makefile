ifdef CONFIG_ADSP_HONOR_SHARED_MEM
ifeq ($(CONFIG_MACH_MT6893),y)
MTK_ADSP_PLATFORM := mt6885
else
MTK_ADSP_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
endif
ccflags-y += -I$(srctree)/drivers/misc/mediatek/adsp/$(MTK_ADSP_PLATFORM)
ccflags-y += -I$(srctree)/drivers/misc/mediatek/audio_ipi/common/framework
obj-$(CONFIG_ADSP_HONOR_SHARED_MEM) += adsp_shared_mem.o
endif
subdir-ccflags-y += -I$(srctree)/sound/soc/mediatek/audio_dsp
subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/audio_ipi/include
subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/include
subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/adsp/include
obj-$(CONFIG_HONOR_ADSP_MISC) += adsp_misc.o
