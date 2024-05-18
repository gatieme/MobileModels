ifeq ($(CONFIG_KRETPROBES), y)
KERNEL_DIR := $(srctree)
ccflags-y += -Ifs/
ccflags-y += -I$(KERNEL_DIR)/
ccflags-y += -I$(KERNEL_DIR)/drivers/hwmemcheck/
ccflags-y += -fno-pic

obj-m := rfile.o
rfile-objs := rfile/rasfile.o rasbase/rasbase.o rasbase/rasprobe.o rasbase/rasproc.o

obj-m += rmem.o
rmem-objs := rmem/rasmemory.o rasbase/rasbase.o  rasbase/rasproc.o

obj-m += rSd.o
rSd-objs := rsd/rassd.o rasbase/rasbase.o  rasbase/rasprobe.o rasbase/rasproc.o

obj-m += rEmmc.o
rEmmc-objs := remmc/rasemmc.o rasbase/rasbase.o  rasbase/rasprobe.o rasbase/rasproc.o

#obj-m += rIO.o
#rIO-objs := rio/rasio.o rasbase/rasbase.o  rasbase/rasprobe.o rasbase/rasproc.o

obj-m += rF2fs.o
rF2fs-objs := rf2fs/rasf2fs.o rasbase/rasbase.o  rasbase/rasprobe.o rasbase/rasproc.o

obj-m += rmissile.o
rmissile-objs := rmissile/rasmissile.o rasbase/rasbase.o  rasbase/rasproc.o

ifeq ($(CONFIG_HN_XCOLLIE), y)
obj-m += rxcollie.o
rxcollie-objs := rxcollie/rasxcollie.o rasbase/rasbase.o rasbase/rasprobe.o rasbase/rasproc.o
endif

obj-m += rProcess.o
rProcess-objs := rprocess/rasprocess.o rasbase/rasbase.o  rasbase/rasproc.o

obj-m += rScsi.o
rScsi-objs := rscsi/rasscsi.o rasbase/rasbase.o  rasbase/rasproc.o

obj-m += rBattery.o
rBattery-objs := rbattery/rasbattery.o rasbase/rasbase.o  rasbase/rasproc.o rasbase/rasprobe.o

ifdef CONFIG_MTK_PLATFORM
obj-m += rGPU.o
rGPU-objs := rgpu/rasgpu.o rasbase/rasbase.o  rasbase/rasproc.o rasbase/rasprobe.o
else
ifeq  ($(CONFIG_RPHONE_MTK),y)
obj-m += rGPU.o
rGPU-objs := rgpu/rasgpu.o rasbase/rasbase.o  rasbase/rasproc.o rasbase/rasprobe.o
endif
endif

ifeq ($(CONFIG_HN_MEMCHECK), y)
obj-m += rMemleak.o
rMemleak-objs := rmemleak/rmemleak.o rasbase/rasbase.o rasbase/rasprobe.o rasbase/rasproc.o
endif
ifeq ($(CONFIG_KASAN), y)
obj-m += rkasan.o
rkasan-objs := rkasan/rkasan.o
CFLAGS_rkasan.o += -fno-builtin
endif

endif
