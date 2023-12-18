/*
 * rt8979_bc12.h
 *
 * driver file for switch chip
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

#ifndef _RT8979_BC12_H_
#define _RT8979_BC12_H_

#include <linux/device.h>
#include "rt8979.h"
#include "switch_interface.h"

bool rt8979_get_dcd_timeout_enabled(void);
void rt8979_set_dcd_timeout_enabled(bool flag);
int rt8979_psy_chg_type_changed(void);
struct switch_interface_bc12_ops *rt8979_get_bc12_ops(void);
void rt8979_deal_resume_irq(int irq, void *data);
/* bc12 type detect */
int rt8979_init_early(struct rt8979_device_info *chip);
int rt8979_init_later(struct rt8979_device_info *chip);
void rt8979_re_init(struct rt8979_device_info *chip);
int rt8979_reset(struct rt8979_device_info *chip);

#endif /* _RT8979_BC12_H_ */
