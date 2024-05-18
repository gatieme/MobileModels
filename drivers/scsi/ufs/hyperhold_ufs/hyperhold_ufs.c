/*
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "ufshcd.h"
#include "ufs.h"

enum health_device_desc_param {
	HEALTH_DEVICE_DESC_PARAM_LEN		= 0x0,
	HEALTH_DEVICE_DESC_PARAM_TYPE		= 0x1,
	HEALTH_DEVICE_DESC_PARAM_PREEOL		= 0x2,
	HEALTH_DEVICE_DESC_PARAM_LIFETIMEA	= 0x3,
	HEALTH_DEVICE_DESC_PARAM_LIFETIMEB	= 0x4,
	HEALTH_DEVICE_DESC_PARAM_RESERVED	= 0x5,
};

#define QUERY_DESC_HEALTH_MAX_SIZE (0x25)

u8 pre_eol_info_val = 0;
u8 life_time_est_a_val = 0;
u8 life_time_est_b_val = 0;
int ufshcd_get_health_info(struct scsi_device *sdev,
	u8 *pre_eol_info, u8 *life_time_est_a, u8 *life_time_est_b)
{
	int ret;
	struct ufs_hba *hba = NULL;
	u8 buff[QUERY_DESC_HEALTH_MAX_SIZE];

	if ((!sdev) || (!pre_eol_info) || (!life_time_est_a) ||
		(!life_time_est_b))
		return -EFAULT;

	if ((pre_eol_info_val != 0) && (life_time_est_a_val != 0) && (life_time_est_b_val != 0)) {
		*pre_eol_info = pre_eol_info_val;
		*life_time_est_a = life_time_est_a_val;
		*life_time_est_b = life_time_est_b_val;
		return 0;
	}

	hba = shost_priv(sdev->host);
	if (!hba)
		return -EFAULT;

	pm_runtime_get_sync(hba->dev);
	ret = ufshcd_read_desc_param(hba, QUERY_DESC_IDN_HEALTH, 0, 0, buff, QUERY_DESC_HEALTH_MAX_SIZE);
	pm_runtime_put_sync(hba->dev);
	if (ret) {
		dev_err(hba->dev, "%s: Failed getting device health info\n",
			__func__);
		return ret;
	}

	pre_eol_info_val = *pre_eol_info = buff[HEALTH_DEVICE_DESC_PARAM_PREEOL];
	life_time_est_a_val = *life_time_est_a = buff[HEALTH_DEVICE_DESC_PARAM_LIFETIMEA];
	life_time_est_b_val = *life_time_est_b = buff[HEALTH_DEVICE_DESC_PARAM_LIFETIMEB];

	dev_err(hba->dev, "%s: get health info: %02x,%02x,%02x\n",
                        __func__, *pre_eol_info, *life_time_est_a, *life_time_est_b);
	return 0;
}

static int scsi_health_query(struct request_queue *q, u8 *pre_eol_info,
	u8 *life_time_est_a, u8 *life_time_est_b)
{
	struct scsi_device *sdev = q->queuedata;

	if (sdev->type != TYPE_DISK || !sdev->host->hostt->get_health_info)
		return -EINVAL;

	if (sdev->host->host_self_blocked || sdev->sdev_state != SDEV_RUNNING)
		return -EINVAL;

	return sdev->host->hostt->get_health_info(sdev, pre_eol_info,
		life_time_est_a, life_time_est_b);
}

int blk_lld_health_query(struct block_device *bi_bdev, u8 *pre_eol_info,
	u8 *life_time_est_a, u8 *life_time_est_b)
{
	struct request_queue *q = NULL;
	int ret = -EPERM;

	if ((!bi_bdev) || (!pre_eol_info) || (!life_time_est_a) ||
		(!life_time_est_b))
		return ret;

	q = bdev_get_queue(bi_bdev);
	ret = scsi_health_query(q, pre_eol_info, life_time_est_a, life_time_est_b);

	return ret;
}
