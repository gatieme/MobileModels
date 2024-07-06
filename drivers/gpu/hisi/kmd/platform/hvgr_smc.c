/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 */

#include "hvgr_smc.h"

#include <linux/version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <linux/arm-smccc.h>

#include "platform_include/see/bl31_smc.h"
#include <linux/platform_drivers/atf_shmem.h>

#define FID_BL31_LP_GPU_SH_RUNTIME 0xc3004506

static unsigned long hvgr_smc_ops_list[HVGR_SMC_OPS_MAX] = {
	FID_BL31_GPU_SMMU_TBU_BYPASS,
	FID_BL31_GPU_SMMU_TBU_LINK,
	FID_BL31_GPU_SMMU_TBU_UNLINK,
	FID_BL31_GPU_SEC_CONFIG,
	FID_BL31_GPU_CRG_RESET,
	FID_BL31_GPU_SET_MODE,
	FID_BL31_GPU_SMMU_SET_SID,
	FID_BL31_GPU_SET_QOS,
	FID_BL31_LP_GPU_SH_RUNTIME,
};

uint64_t hvgr_smc_call(struct hvgr_device *gdev, struct hvgr_smc_para *para)
{
	struct arm_smccc_res res;
	uint64_t shmem_size;

	if (para == NULL || para->op >= HVGR_SMC_OPS_MAX) {
		dev_err(gdev->dev, "smc input is invalid.");
		return (uint64_t)-EINVAL;
	}

	if (para->with_shared_mem) {
		shmem_size = get_atf_shmem_size();
		if (para->size > shmem_size) {
			dev_err(gdev->dev, "hvgr smc shmem too large (%lu:%lu)",
				para->size, shmem_size);
			return (uint64_t)-EINVAL;
		}
		(void)smccc_with_shmem(hvgr_smc_ops_list[para->op], SHMEM_IN, para->addr,
			para->size, para->a1, para->a2, para->a3, para->a4, &res);
	} else {
		arm_smccc_smc(hvgr_smc_ops_list[para->op], para->a1, para->a2, para->a3, para->a4,
			para->a5, para->a6, para->a7, &res);
	}

	return (uint64_t)res.a0;
}
#else
uint64_t hvgr_smc_call(struct hvgr_device *gdev, struct hvgr_smc_para *para)
{
	dev_err(gdev->dev, "linux version is less than 5.10, not support arm_smccc_smc!");
	return (uint64_t)-EINVAL;
}
#endif