/*
 * npu_platform_pm.c
 *
 * about npu adapter
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "npu_platform_pm.h"

#include <linux/device.h>
#include <linux/iommu/mm_svm.h>

#include "npu_platform_register.h"
#include "npu_pm_framework.h"
#include "npu_pm_internal.h"
#include "npu_platform.h"
#include "dts/npu_reg.h"
#include "npu_log.h"

static int npu_plat_powerup_smmu(struct device *dev)
{
	int ret;
	ret = mm_smmu_poweron(dev);
	if (ret != 0) {
		npu_drv_err("mm smmu poweron failed\n");
		return ret;
	}

	ret = npu_plat_powerup_tbu();
	if (ret != 0) {
		npu_drv_warn("powerup tbu failed ret = %d\n", ret);
		return ret;
	}
	return 0;
}

static int npu_plat_poweroff_smmu(void)
{
	struct npu_platform_info *plat_info = NULL;

	plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info failed\n");

	npu_plat_powerdown_tbu(0);
	(void)mm_smmu_poweroff(plat_info->pdev);
	return 0;
}

int npu_plat_pm_powerup(struct npu_dev_ctx *dev_ctx, u32 work_mode)
{
	int ret = 0;
	u32 *stage = NULL;

	cond_return_error(work_mode == NPU_SEC, ret, "Security is not supported.\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "invalid para\n");

	npu_drv_boot_time_tag("start powerup till npucpu \n");
	stage = &dev_ctx->pm.power_stage;

	if (*stage == NPU_PM_DOWN) {
		ret = npu_plat_powerup_till_npucpu(work_mode);
		if (ret != 0) {
			npu_drv_warn("powerup till npucpu failed ,ret=%d\n",
				ret);
			goto failed;
		}
		*stage = NPU_PM_NPUCPU;
	}
	npu_drv_boot_time_tag("start powerup till ts \n");

	if (*stage == NPU_PM_NPUCPU) {
		ret = npu_plat_powerup_till_ts(work_mode, NPU_SC_TESTREG0_OFFSET);
		if (ret != 0) {
			npu_drv_warn("powerup till ts failed ret=%d\n", ret);
			goto ts_failed;
		}
		*stage = NPU_PM_TS;
	}
	npu_drv_boot_time_tag("start powerup smmu \n");

	if (*stage == NPU_PM_TS) {
		// power up smmu in non_secure npu mode
		if (work_mode != NPU_SEC) {
			struct npu_platform_info *plat_info = NULL;

			plat_info = npu_plat_get_info();
			cond_goto_error(plat_info == NULL, smmu_failed, ret, -1,
				"get platform info failed\n");
			ret = npu_plat_powerup_smmu(plat_info->pdev);
			cond_goto_error(ret != 0, smmu_failed, ret, ret,
				"powerup smmu failed ret=%d\n", ret);
		} else {
			npu_drv_warn("secure power up ,no need to power up smmu"
				"in linux non_secure world, smmu power up will"
				"be excuted on tee secure world \n");
		}
	}
	*stage = NPU_PM_UP;
	npu_plat_set_npu_power_status(DRV_NPU_POWER_ON_FLAG);
	npu_drv_warn("pm powerup success \n");
	return 0;

smmu_failed:
	(void)npu_plat_powerdown_ts(NPU_SC_TESTREG8_OFFSET, work_mode);
	// continue even if gic grace exit failed
	*stage = NPU_PM_NPUCPU;
ts_failed:
	(void)npu_plat_powerdown_npucpu(0x1 << 5, work_mode);
	(void)npu_plat_powerdown_nputop();
	*stage = NPU_PM_DOWN;
failed:
	return ret;
}

int npu_plat_pm_powerdown(struct npu_dev_ctx *dev_ctx, u32 work_mode)
{
	int ret = 0;
	u32 *stage = NULL;

	cond_return_error(work_mode == NPU_SEC, ret, "Security is not supported.\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "invalid para\n");

	stage = &dev_ctx->pm.power_stage;
	npu_plat_set_npu_power_status(DRV_NPU_POWER_OFF_FLAG);

	if (*stage == NPU_PM_UP) {
		if (work_mode != NPU_SEC) {
			ret = npu_plat_poweroff_smmu();
			if (ret != 0)
				npu_drv_err("poweroff smmu failed\n");
		} else {
			npu_drv_warn("secure power down ,no need to power down smmu"
				"in linux non_secure world, smmu power down has"
				"been excuted on tee secure world \n");
		}

		*stage = NPU_PM_TS;
	}

	if (*stage == NPU_PM_TS) {
		ret = npu_plat_powerdown_ts(NPU_SC_TESTREG8_OFFSET, work_mode);
		// continue even if gic grace exit failed
		*stage = NPU_PM_NPUCPU;
	}
	if (*stage == NPU_PM_NPUCPU) {
		ret = npu_plat_powerdown_npucpu(0x1<<5, work_mode);
		if (ret != 0)
			npu_drv_err("pm power down fail\n");
		ret = npu_plat_powerdown_nputop();
		if (ret != 0)
			npu_drv_err("power down nputop fail\n");
	}
	*stage = NPU_PM_DOWN;

	npu_drv_warn("pm power down success\n");

	return ret;
}

int npu_plat_dev_pm_suspend(void)
{
	return 0;
}
