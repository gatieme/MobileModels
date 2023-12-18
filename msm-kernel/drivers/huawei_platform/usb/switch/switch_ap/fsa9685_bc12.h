/*
 * fsa9685_bc12.h
 *
 * fsa9685_bc12 header file
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

#ifndef _FSA9685_BC12_
#define _FSA9685_BC12_

#include <linux/device.h>
#include <linux/workqueue.h>
#include "switch_interface.h"

#define FSA9688_NON_STANDARD_RETRY_MAX          3
#define DELAY_FOR_BC12_REG                      300 /* ms */
#define DELAY_FOR_SDP_RETRY                     300 /* ms */
#define DELAY_FOR_RESET                         300 /* ms */

enum fsa9685_usbsw_state {
	FSA9685_USBSW_CHG = 0,
	FSA9685_USBSW_USB,
};

int fsa9685_psy_chg_type_changed(void);
void fsa9685_update_nstd_chg_type(unsigned int chg_type);
void fsa9685_update_type_work(struct work_struct *work);
void fsa9685_chg_det_work(struct work_struct *work);
struct switch_interface_bc12_ops *fas9685_get_bc12_ops(void);

#endif /* _FSA9685_BC12_ */
