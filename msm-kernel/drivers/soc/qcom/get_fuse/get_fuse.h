/*
 * get_fuse.h
 *
 * get_fuse sched header
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#ifndef GET_FUSE_H
#define GET_FUSE_H

typedef enum {
	CPR_VOLTAGE_MODE_OFF,
	CPR_VOLTAGE_MODE_RETENTION,
	CPR_VOLTAGE_MODE_MIN_SVS,
	CPR_VOLTAGE_MODE_LOW_SVS_D1,
	CPR_VOLTAGE_MODE_LOW_SVS,
	CPR_VOLTAGE_MODE_LOW_SVS_L1,
	CPR_VOLTAGE_MODE_LOW_SVS_L2,
	CPR_VOLTAGE_MODE_SVS,
	CPR_VOLTAGE_MODE_SVS_L0,
	CPR_VOLTAGE_MODE_SVS_L1,
	CPR_VOLTAGE_MODE_SVS_L2,
	CPR_VOLTAGE_MODE_NOMINAL,
	CPR_VOLTAGE_MODE_NOMINAL_L0,
	CPR_VOLTAGE_MODE_NOMINAL_L1,
	CPR_VOLTAGE_MODE_NOMINAL_L2,
	CPR_VOLTAGE_MODE_TURBO,
	CPR_VOLTAGE_MODE_TURBO_L0,
	CPR_VOLTAGE_MODE_TURBO_L1,
	CPR_VOLTAGE_MODE_TURBO_L2,
	CPR_VOLTAGE_MODE_TURBO_L3,
	CPR_VOLTAGE_MODE_SUPER_TURBO,
	CPR_VOLTAGE_MODE_SUPER_TURBO_NO_CPR,

	CPR_VOLTAGE_MODE_COUNT
} voltage_mode;

typedef enum {
	CPR_RAIL_MX,
	CPR_RAIL_CX,
	CPR_RAIL_MSS,
	CPR_RAIL_GFX,
	CPR_RAIL_VDDA,
	CPR_RAIL_MM,
	CPR_RAIL_MXC,
	DOMAIN_COUNT,
} cpr_domain_id;

typedef struct fuse_rail_info {
	voltage_mode mode;
	u32 volt_addr;
	u32 volt_mask;
	u32 volt_offset;
	u32 volt_offset_addr;
	u32 volt_offset_mask;
	u32 volt_offset_offset;
} fuse_rail_info;

typedef struct fuse_domain_info {
	cpr_domain_id id;
	u32 mode_count;
	fuse_rail_info *rail;
} fuse_domain_info;

typedef struct fuse_rail_result {
	voltage_mode mode;
	u32 targ_volt;
	u32 targ_volt_offset;
} fuse_rail_result;

typedef struct fuse_domain_result {
	cpr_domain_id id;
	u32 modecount;
	fuse_rail_result *rail_result;
} fuse_domain_result;

typedef struct result_to_send {
    cpr_domain_id id;
    voltage_mode mode;
    u32 targ_volt;
    u32 targ_voltoffset;
} result_to_send;

#endif
