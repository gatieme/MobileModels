/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2022. All rights reserved.
 * Description: This file describe GPU ewp self healing soulution
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * A copy of the licence is included with the program, and can also be obtained
 * from Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 */

#include <securec.h>
#include "mali_kbase.h"
#include "mali_kbase_platform.h"
#include <platform_include/basicplatform/linux/nve/nve_ap_kernel_interface.h>

#define DMD_NV_NUM 512
#define DMD_NV_DATA_SIZE 15

struct gpu_dmd_nv_data {
	union {
		uint8_t value;
		struct {
			uint8_t en      : 1;
			uint8_t sh_mark : 1;
			uint8_t res     : 6;
		} bit;
	} info;

	uint8_t buf[DMD_NV_DATA_SIZE];
};

static int gpu_dmd_nv_read(struct kbase_device *kbdev, struct gpu_dmd_nv_data *data)
{
	int ret;
	errno_t err;
	struct opt_nve_info_user nve = {0};

	err = strncpy_s(nve.nv_name, sizeof(nve.nv_name),
			"GPUSH", strlen("GPUSH"));
	if (err != EOK || sizeof(*data) > NVE_NV_DATA_SIZE) {
		dev_err(kbdev->dev, "gpu_dmd nv read name cpy fail");
		ret = -1;
		return ret;
	}
	nve.nv_number = DMD_NV_NUM;
	nve.valid_size = (uint32_t)sizeof(*data);
	nve.nv_operation = NV_READ;

	ret = nve_direct_access_interface(&nve);
	if (ret) {
		dev_err(kbdev->dev, "gpu_dmd nv read fail, %d", ret);
		return ret;
	}
	(void)memcpy_s(data, sizeof(*data), nve.nv_data, sizeof(*data));
	return 0;
}

static int gpu_dmd_nv_write(struct kbase_device *kbdev, struct gpu_dmd_nv_data *data)
{
	int ret;
	errno_t err;
	struct opt_nve_info_user nve = {0};

	err = strncpy_s(nve.nv_name, sizeof(nve.nv_name),
		"GPUSH", strlen("GPUSH"));
	if (err != EOK || sizeof(*data) > NVE_NV_DATA_SIZE) {
		dev_err(kbdev->dev, "gpu_dmd nv write name cpy failed");
		ret = -1;
		return ret;
	}
	nve.nv_number = DMD_NV_NUM;
	nve.valid_size = (uint32_t)sizeof(*data);
	nve.nv_operation = NV_WRITE;
	(void)memcpy_s(nve.nv_data, sizeof(*data), data, sizeof(*data));

	ret = nve_direct_access_interface(&nve);
	if (ret) {
		dev_err(kbdev->dev, "gpu_dmd nv write fail, %d", ret);
		return ret;
	}

	return 0;
}

int gpu_dmd_msg_check(struct kbase_device *kbdev, enum dmd_nv_mark *nv_mark)
{
	int ret = -1;
	static int check_succ = 0;
	struct gpu_dmd_nv_data data = {0};

	if (kbdev == NULL || nv_mark == NULL)
		return ret;

	if (check_succ != 0)
		goto end;
	gpu_dmd_nv_read(kbdev, &data);
	dev_err(kbdev->dev, "gpu_dmd nv write fail, %d, %d", data.info.bit.en, data.info.bit.sh_mark);

	if (data.info.bit.sh_mark == 1) {
		/* unmark, write sh_mark to 0 */
		data.info.bit.sh_mark = 0;
		if (gpu_dmd_nv_write(kbdev, &data) != 0)
			goto end;
		*nv_mark = DMD_NV_UNMARK;
		check_succ = 1;
		ret = 0;
		goto end;
	}
	/* mark, write dmd nv to mark value */
	data.info.bit.sh_mark = 1;
	if (gpu_dmd_nv_write(kbdev, &data) != 0)
		goto end;
	*nv_mark = DMD_NV_MARK;
	check_succ = 1;
	ret = 0;
end:
	return ret;
}
