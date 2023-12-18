/*
  * process for rainbow driver
  *
  * Copyright (c) 2019-2019 Huawei Technologies Co., Ltd.
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

#ifndef _RAINBOW_H_
#define _RAINBOW_H_

#include <linux/types.h>
#include <linux/printk.h>
#include <platform/linux/rainbow.h>

struct rb_reason_header {
	uint32_t reset_reason;          /* reserve flag */
	uint32_t inner_reset_reason;
	uint32_t reset_type;
	uint32_t mreason_num;
	uint32_t mreason_str_flag;
	uint32_t sreason_str_flag;
	uint32_t attach_info_flag;
	uint32_t emmc_flag;
	char mreason_str[RB_MREASON_STR_MAX];
	char sreason_str[RB_SREASON_STR_MAX];
	char attach_info[RB_SREASON_STR_MAX];
};

struct rb_region_log_info {
	uint64_t magic;
	uint64_t virt_addr;
	uint64_t phys_addr;
	uint64_t size;
};
struct rb_header {
	uint64_t himntn_data;
	struct rb_reason_header reason_node;
	struct rb_region_log_info kernel_log;
	struct rb_region_log_info tz_log;
};

void rb_init_ex(void);
void rb_exit_ex(void);
#endif
