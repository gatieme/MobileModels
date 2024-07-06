ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wshadow -Wformat=2

PM_DIR :=$(srctree)/platform_source/cee/drivers/pm

EXTRA_CFLAGS += -I$(PM_DIR)

obj-$(CONFIG_SR) += suspend.o
obj-$(CONFIG_SR) += sr_mntn.o
obj-$(CONFIG_SR_SYNC) += sys_sync.o
obj-$(CONFIG_PM_LPCTRL) += lowpm_ctrl.o
obj-$(CONFIG_SYS_PM_ULSR) += ulsr.o
obj-$(CONFIG_SYS_PM_DOZE) += doze.o
