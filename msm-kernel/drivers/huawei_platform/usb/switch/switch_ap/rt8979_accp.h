/*
 * rt8979_accp.h
 *
 * rt8979_accp header file
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _RT8979_ACCP_
#define _RT8979_ACCP_

#include <linux/device.h>
#include "rt8979.h"
#include "switch_interface.h"

int rt8979_sw_open(bool open);
void rt8979_disable_accp_intr(struct rt8979_device_info *di);
void rt8979_dcp_accp_init(void);
int rt8979_accp_enable(struct rt8979_device_info *di, bool en);
int rt8979_is_accp_charger_type(void *dev_data);
struct switch_interface_charger_ops *rt8979_get_accp_ops(void);

#endif /* _RT8979_ACCP_ */
