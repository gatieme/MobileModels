subdir-ccflags-y += -I$(srctree)/drivers/micro_dump
subdir-ccflags-y += -I$(srctree)/include/
subdir-ccflags-y += -I$(srctree)/kernel/
subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/aee/mrdump/
obj-$(CONFIG_HN_MICRODUMP) += microdump.o
microdump-y += micro_dump.o irq_dump.o out_print.o page_dump.o policy.o process_dump.o register_dump.o sched_dump.o stack_dump.o bitflip.o lock_dump.o common_interface.o
microdump-$(CONFIG_HN_MICRODUMP_GKI) += micro_utils.o
obj-y  += test/
