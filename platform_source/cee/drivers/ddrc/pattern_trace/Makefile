ccflags-y += -I$(srctree)/platform_source/basicplatform/drivers/mntn/blackbox \
             -I$(srctree)/platform_source/cee/drivers/ddrc \
             -Wall -Werror

ccflags-$(CONFIG_DDR_CHAMAELEON) += -I$(srctree)/platform_source/cee/drivers/ddrc/pattern_trace/chamaeleon
ccflags-$(CONFIG_DDR_CRATER) += -I$(srctree)/platform_source/cee/drivers/ddrc/pattern_trace/crater
obj-$(CONFIG_DDR_CHAMAELEON) += chamaeleon/
obj-$(CONFIG_DDR_CRATER) += crater/
obj-$(CONFIG_DDR_QICE_PT) += ddr_pt_drv.o ddr_pt_dump.o
