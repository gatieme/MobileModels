/*
 * fsa9685_accp.h
 *
 * fsa9685_accp header file
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

#ifndef _FSA9685_ACCP_
#define _FSA9685_ACCP_

#include <linux/device.h>
#include <huawei_platform/usb/switch/fsa9685.h>
#include "switch_interface.h"

void fsa9685_disable_accp_intr(struct fsa9685_device_info *di);
int fsa9685_is_accp_charger_type(void *dev_data);
struct switch_interface_charger_ops *fas9685_get_accp_ops(void);

#endif /* _FSA9685_ACCP_ */
