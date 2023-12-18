# SPDX-License-Identifier: GPL-2.0
# UFSHCD makefile

# The link order is important here. ufshcd-core must initialize
# before vendor drivers.
obj-$(CONFIG_SCSI_UFSHCD)		+= ufshcd-core.o
ufshcd-core-y				+= ufshcd.o ufs-sysfs.o
ufshcd-core-$(CONFIG_DEBUG_FS)		+= ufs-debugfs.o
ufshcd-core-$(CONFIG_SCSI_UFS_BSG)	+= ufs_bsg.o
ufshcd-core-$(CONFIG_SCSI_UFS_CRYPTO)	+= ufshcd-crypto.o
ufshcd-core-$(CONFIG_SCSI_UFS_HPB)	+= ufshpb.o

obj-$(CONFIG_SCSI_UFS_DWC_TC_PCI) += tc-dwc-g210-pci.o ufshcd-dwc.o tc-dwc-g210.o
obj-$(CONFIG_SCSI_UFS_DWC_TC_PLATFORM) += tc-dwc-g210-pltfrm.o ufshcd-dwc.o tc-dwc-g210.o
obj-$(CONFIG_SCSI_UFS_CDNS_PLATFORM) += cdns-pltfrm.o
obj-$(CONFIG_SCSI_UFS_QCOM) += ufs_qcom.o
ufs_qcom-y += ufs-qcom.o
ufs_qcom-$(CONFIG_SCSI_UFS_CRYPTO) += ufs-qcom-ice.o
obj-$(CONFIG_SCSI_UFS_EXYNOS) += ufs-exynos.o
obj-$(CONFIG_SCSI_UFSHCD_PCI) += ufshcd-pci.o
obj-$(CONFIG_SCSI_UFSHCD_PLATFORM) += ufshcd-pltfrm.o
obj-$(CONFIG_SCSI_UFS_HISI) += ufs-hisi.o
obj-$(CONFIG_SCSI_UFS_MEDIATEK) += ufs-mediatek.o
obj-$(CONFIG_MAS_BLK)  += mas_ufs.o
obj-$(CONFIG_MAS_UFS_MANUAL_BKOPS) += mas-ufs-bkops.o mas_ufs_bkops_interface.o
obj-$(CONFIG_SCSI_UFS_TI_J721E) += ti-j721e-ufs.o
obj-y += proc_ufs.o
obj-$(CONFIG_HUAWEI_UFS_VENDOR_MODE) += ufs_vendor_mode.o ufs_vendor_cmd.o ufs_vendor_extern.o
obj-$(CONFIG_HUAWEI_UFS_DSM)  += dsm_ufs.o
obj-$(CONFIG_SCSI_UFS_HS_ERROR_RECOVER) += ufs_error_recovery.o
obj-$(CONFIG_HUAWEI_UFS_DYNAMIC_SWITCH_WB)  += ufs_wb_dynamic_switch.o
obj-$(CONFIG_UFS_DEVICE_VENDOR_MODIFY) += ufs_device_vendor_modify.o

ifeq ($(TARGET_VERSION_MODE),factory)
    EXTRA_CFLAGS += -DHEALTH_INFO_FACTORY_MODE
endif
