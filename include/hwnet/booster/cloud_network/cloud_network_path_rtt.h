/*
 * cloud_network_path_rtt.h
 *
 * cloud network kernel module implementation
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef _CLOUD_NETWORK_PATH_RTT_H_
#define _CLOUD_NETWORK_PATH_RTT_H_

#include <linux/types.h>

#pragma pack(1)
struct time_sync_respond {
	u8 type;
	u8 length;
	u32 t1;
	u32 t2;
	u32 t3;
};
#pragma pack()

#pragma pack(1)
struct path_rtt_opt {
	u8 type;
	u8 length;
	u32 t5;
};
#pragma pack()

struct time_sync_respond_data {
	u32 type;
	u32 t1;
	u32 t2;
	u32 t3;
	u32 t4;
};

struct path_rtt_opt_data {
	u32 type;
	u32 t5;
	u32 t6;
};

bool get_time_sync_state(void);
void start_path_rtt_module(void);
void stop_path_rtt_module(void);
void offset_reset(void);
void recv_time_sync_respond(__u8 fid, void *opt_data);
void recv_path_rtt(__u8 fid, void *opt_data);
void cloud_network_time_sync_init(void);
void cloud_network_time_sync_exit(void);
#endif