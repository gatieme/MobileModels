obj-y += rmeminspect.o
rmeminspect-objs := ddr_inspect_fops.o ddr_inspect_drv.o

ifeq ($(TARGET_BOARD_PLATFORM), charlotte)
EXTRA_CFLAGS += -DDDR_CHARLOTTE_PLATFORM
endif