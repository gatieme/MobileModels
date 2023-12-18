/*
 * usbswitch_fsa9685.h
 *
 * usbswitch with fsa9685 driver
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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

#ifndef _USBSWITCH_FSA9685_H_
#define _USBSWITCH_FSA9685_H_

#include <linux/bitops.h>

#define FSA9685_FM8_WAITTIME_50MS                        0
#define FSA9685_FM8_WAITTIME_100MS                       1
#define FSA9685_FM8_WAITTIME_150MS                       2
#define FSA9685_FM8_WAITTIME_200MS                       3
#define FSA9685_FM8_WAITTIME_250MS                       4
#define FSA9685_FM8_WAITTIME_300MS                       5
#define FSA9685_FM8_WAITTIME_350MS                       6
#define FSA9685_FM8_WAITTIME_400MS                       7

void usbswitch_fsa9685_detach_work(void);
int usbswitch_fsa9685_manual_switch(int input_select);
struct switch_interface_control_ops* usbswitch_fsa9685_get_control_ops(void);

#endif /* _USBSWITCH_FSA9685_H_ */
