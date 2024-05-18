#
# Makefile for th iomt host state stat feature.
#
ifeq ($(CONFIG_SCSI_UFSHCD),y)
ccflags-y += -I$(srctree)/drivers/scsi/ufs
endif
obj-$(CONFIG_STORAGE_DSM_IOMT_HOST)	+= dsm_iomt_host.o
obj-$(CONFIG_STORAGE_DSM_IOMT_EMMC_HOST)	+= dsm_iomt_emmc_host.o
obj-$(CONFIG_STORAGE_DSM_IOMT_UFS_HOST) += dsm_iomt_ufs_host.o
obj-$(CONFIG_HONOR_IO_MEASURE) += iomeasure.o
