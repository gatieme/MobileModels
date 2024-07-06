/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 */

#include <linux/security.h>
#include <linux/version.h>
#include <linux/kthread.h>
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <securec.h>
#include "hvgr_log_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_platform_api.h"
#include <platform_include/basicplatform/linux/nve/nve_ap_kernel_interface.h>

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <dfx_bbox_diaginfo.h>
#else
#include <platform_include/basicplatform/linux/dfx_bbox_diaginfo.h>
#endif

#define HVGR_DMD_NV_NUM 512
#define HVGR_DMD_NV_DATA_SIZE 23
#define HVGR_DMD_GAF_IDX 21
#define HVGR_DMD_SID_OFFSET 2

struct hvgr_dmd_nv_data {
	union {
		uint8_t value;
		struct {
			uint8_t en      : 1;
			uint8_t sh_mark : 1;
			uint8_t gaf_mark : 1;
			uint8_t res     : 5;
		} bit;
	} info;

	uint8_t buf[HVGR_DMD_NV_DATA_SIZE];
};

static int hvgr_dmd_nv_read(struct hvgr_device *gdev, struct hvgr_dmd_nv_data *data)
{
	int ret;
	errno_t err;
	struct opt_nve_info_user nve = {0};

	err = strncpy_s(nve.nv_name, sizeof(nve.nv_name),
			"GPUSH", strlen("GPUSH"));
	if (err != EOK || sizeof(*data) > NVE_NV_DATA_SIZE) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd nv read name cpy fail");
		ret = -1;
		return ret;
	}
	nve.nv_number = HVGR_DMD_NV_NUM;
	nve.valid_size = (uint32_t)sizeof(*data);
	nve.nv_operation = NV_READ;

	ret = nve_direct_access_interface(&nve);
	if (ret) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd nv read fail, %d", ret);
		return ret;
	}
	(void)memcpy_s(data, sizeof(*data), nve.nv_data, sizeof(*data));
	return 0;
}

static int hvgr_dmd_nv_write(struct hvgr_device *gdev, struct hvgr_dmd_nv_data *data)
{
	int ret;
	errno_t err;
	struct opt_nve_info_user nve = {0};

	err = strncpy_s(nve.nv_name, sizeof(nve.nv_name),
		"GPUSH", strlen("GPUSH"));
	if (err != EOK || sizeof(*data) > NVE_NV_DATA_SIZE) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd nv write name cpy failed");
		ret = -1;
		return ret;
	}
	nve.nv_number = HVGR_DMD_NV_NUM;
	nve.valid_size = (uint32_t)sizeof(*data);
	nve.nv_operation = NV_WRITE;
	(void)memcpy_s(nve.nv_data, sizeof(*data), data, sizeof(*data));

	ret = nve_direct_access_interface(&nve);
	if (ret) {
		hvgr_err(gdev, HVGR_DM, "higpu_dmd nv write fail, %d", ret);
		return ret;
	}

	return 0;
}

static bool hvgr_dmd_need_check_nv(struct hvgr_device *gdev)
{
	u64 *check_ts = &(gdev->dm_dev.dmd_msg->dmd_check_ts[0]);
	u32 last_idx = (gdev->dm_dev.dmd_msg->dmd_check_cnt - 1) % MAX_DMD_CHECK_CNT;
	u32 first_idx = (1 + last_idx) % MAX_DMD_CHECK_CNT;

	if (check_ts[last_idx] == 0 || check_ts[first_idx] == 0 ||
		check_ts[last_idx] < check_ts[first_idx])
		return false;
	if ((check_ts[last_idx] - check_ts[first_idx]) <= MAX_DMD_CHECK_INTERVAL)
		return true;

	return false;
}

static inline void hvgr_dmd_sr_awake(struct hvgr_device *gdev)
{
	if (gdev->dm_dev.dmd_msg->sr_wakeup_lock != NULL)
		__pm_stay_awake(gdev->dm_dev.dmd_msg->sr_wakeup_lock);
}

static inline void hvgr_dmd_sr_relax(struct hvgr_device *gdev)
{
	if (gdev->dm_dev.dmd_msg->sr_wakeup_lock != NULL)
		__pm_relax(gdev->dm_dev.dmd_msg->sr_wakeup_lock);
}

int hvgr_dmd_sh_process(void *data)
{
	enum dmd_nv_mark nv_mark;
	struct hvgr_dmd_nv_data nv_data = {0};
	struct hvgr_device *gdev = (struct hvgr_device *)data;

	if (unlikely(gdev == NULL))
		return -1;

	mutex_lock(&gdev->dm_dev.dmd_msg->dmd_lock);
	hvgr_dmd_sr_awake(gdev);
	if (hvgr_dmd_nv_read(gdev, &nv_data) != 0 || nv_data.info.bit.en == 0)
		goto err_end;

	if (nv_data.info.bit.sh_mark == 1) {
		/* unmark, write sh_mark to 0 */
		nv_data.info.bit.sh_mark = 0;
		if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
			goto err_end;

		hvgr_dmd_sr_relax(gdev);
		nv_mark = DMD_NV_UNMARK;
		goto end;
	}
	/* mark, write dmd nv to mark value */
	nv_data.info.bit.sh_mark = 1;
	if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
		goto err_end;

	hvgr_dmd_sr_relax(gdev);
	nv_mark = DMD_NV_MARK;
	(void)hvgr_platform_sh_runtime(gdev, ptr_to_u64(&nv_data), sizeof(nv_data));
end:
	gdev->dm_dev.dmd_msg->dmd_sh_flag = 1;
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
	if (nv_mark == DMD_NV_MARK)
		hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd sh nv mark");
	else
		hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd sh nv unmark");
	hvgr_dmd_msg_report(gdev);
	return 0;
err_end:
	gdev->dm_dev.dmd_msg->dmd_sh_flag = 0;
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
	return -1;
}

void hvgr_dmd_msg_check(struct hvgr_device *gdev)
{
	struct task_struct *tsk = NULL;

	if (unlikely(gdev == NULL))
		return;

	mutex_lock(&gdev->dm_dev.dmd_msg->dmd_lock);
	if (gdev->dm_dev.dmd_msg->dmd_sh_flag != 0 || gdev->dm_dev.dmd_msg->dmd_check_cnt == 0 ||
		!hvgr_dmd_need_check_nv(gdev)) {
		mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
		return;
	}
	gdev->dm_dev.dmd_msg->dmd_sh_flag = 1;
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);

	tsk = kthread_run(hvgr_dmd_sh_process, (void *)gdev, "dmd_sh_process");
	if (IS_ERR(tsk)) {
		gdev->dm_dev.dmd_msg->dmd_sh_flag = 0;
		hvgr_err(gdev, HVGR_DM, "higpu_dmd: sh tsk fail");
	}
}

unsigned int hvgr_get_sh_dmd_id(void)
{
	return DMD_HIGPU_SH_INFO;
}

static int hvgr_dmd_write_gaf(void *data)
{
	struct hvgr_ctx *ctx = (struct hvgr_ctx *)data;
	struct hvgr_device *gdev = NULL;
	struct hvgr_dmd_nv_data nv_data = {0};

	if (ctx == NULL)
		return -1;

	gdev = ctx->gdev;
	mutex_lock(&gdev->dm_dev.dmd_msg->dmd_lock);
	hvgr_dmd_sr_awake(gdev);
	if (hvgr_dmd_nv_read(gdev, &nv_data) != 0 || nv_data.info.bit.en == 0)
		goto end;

	nv_data.info.bit.gaf_mark = 1;
	nv_data.buf[HVGR_DMD_GAF_IDX] = (uint8_t)ctx->sid;
	if (hvgr_dmd_nv_write(gdev, &nv_data) != 0)
		goto end;
	gdev->dm_dev.dmd_msg->dmd_gaf = ctx->sid;
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
	hvgr_dmd_msg_report(gdev);
	hvgr_dmd_msg_set(gdev, DMD_SH_NV_MARK, "dmd af nv mark");
	hvgr_dmd_msg_report(gdev);
	return 0;
end:
	hvgr_dmd_sr_relax(gdev);
	mutex_unlock(&gdev->dm_dev.dmd_msg->dmd_lock);
	return -1;
}

void hvgr_set_sid(struct hvgr_ctx *ctx, uint32_t sid)
{
	struct task_struct *tsk = NULL;

	if (ctx->gaf_flag != 1)
		return;

	if (ctx->sid != 0 || sid < HVGR_DMD_SID_OFFSET)
		return;

	ctx->sid = 1 << (sid - HVGR_DMD_SID_OFFSET);

	tsk = kthread_run(hvgr_dmd_write_gaf, (void *)ctx, "dmd_gaf_process");
	if (IS_ERR(tsk))
		hvgr_err(ctx->gdev, HVGR_DM, "higpu_dmd: gaf tsk fail");
}

void hvgr_config_ctx_gaf(struct hvgr_ctx *ctx, uint32_t flag)
{
	struct hvgr_device *gdev = ctx->gdev;

	if (gdev == NULL || flag != 1)
		return;

	ctx->gaf_flag = flag;
	ctx->sid = gdev->dm_dev.dmd_msg->dmd_gaf;
}

uint32_t hvgr_dmd_read_gaf(struct hvgr_device *gdev)
{
	struct hvgr_dmd_nv_data data = {0};

	if (hvgr_dmd_nv_read(gdev, &data) != 0 ||
		data.info.bit.en == 0 ||
		data.info.bit.gaf_mark == 0)
		return 0;

	return (uint32_t)data.buf[HVGR_DMD_GAF_IDX];
}
