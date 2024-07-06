/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: gear ctrl header file
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __UFS_GEAR_CTRL_H__
#define __UFS_GEAR_CTRL_H__

typedef enum {
	UFS_CTRL_GEAR_LEVEL_MIN,
	UFS_CTRL_GEAR_LEVEL_0 = UFS_CTRL_GEAR_LEVEL_MIN,
	UFS_CTRL_GEAR_LEVEL_1,
	UFS_CTRL_GEAR_LEVEL_MAX = UFS_CTRL_GEAR_LEVEL_1
} ufs_ctrl_gear_level_t;

typedef enum {
	UFS_CTRL_GEAR_TYPE_GEAR,
	UFS_CTRL_GEAR_TYPE_LANE,
	UFS_CTRL_GEAR_TYPE_MAX = UFS_CTRL_GEAR_TYPE_LANE
} ufs_ctrl_gear_type_t;

void ufshcd_gear_ctrl_op_register(struct ufs_hba *hba);
void ufshcd_gear_ctrl_set_type(struct ufs_hba *hba, ufs_ctrl_gear_type_t type);
ufs_ctrl_gear_type_t ufshcd_gear_ctrl_get_type(void);
void mas_blk_disable_gear_ctrl(bool enable);
void mas_blk_auto_gear_ctrl(bool enable);

#endif
