/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: ufs device vendor modify file
 * Author: y00572850
 * Create: 2021-06-10
 */

#ifndef __UFS_DEVICE_VENDOR_MODIFY_H__
#define __UFS_DEVICE_VENDOR_MODIFY_H__
#include "ufshcd.h"
#include "ufs-qcom.h"
#include <linux/version.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#ifdef CONFIG_UFS_DEVICE_VENDOR_MODIFY
int ufs_adapt_interface(struct ufs_hba *hba,
		struct ufs_pa_layer_attr *pwr_mode);
void ufs_qcom_parse_clkscaling(struct ufs_qcom_host *host);
#else
static inline  __attribute__((unused)) int
ufs_adapt_interface(struct ufs_hba *hba, struct ufs_pa_layer_attr *pwr_mode
		__attribute__((unused)))
{
	return 0;
}
static inline  __attribute__((unused)) void
ufs_qcom_parse_clkscaling(struct ufs_qcom_host *host
		__attribute__((unused)))
{
	return;
}
#endif /* CONFIG_UFS_DEVICE_VENDOR_MODIFY */
#endif
#endif
