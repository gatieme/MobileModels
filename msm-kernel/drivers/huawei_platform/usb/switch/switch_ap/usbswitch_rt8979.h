/*
 * usbswitch_rt8979.h
 *
 * usbswitch with rt8979 driver
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

#ifndef _USBSWITCH_RT8979_H_
#define _USBSWITCH_RT8979_H_

#include <linux/bitops.h>

#define RT8979_INTB_WATCHDOG_DISABLE                    0
#define RT8979_INTB_WATCHDOG_250MS                      1
#define RT8979_INTB_WATCHDOG_500MS                      2
#define RT8979_INTB_WATCHDOG_1000MS                     3

#define RT8979_DCD_TIMEOUT_SET_300MS                    0
#define RT8979_DCD_TIMEOUT_SET_600MS                    1
#define RT8979_DCD_TIMEOUT_SET_900MS                    2
#define RT8979_DCD_TIMEOUT_SET_1200MS                   3

#define RT8979_CHGDET_ONTIME_150MS                      0
#define RT8979_CHGDET_ONTIME_300MS                      1

#define RT8979_FM8_WAITTIME_50MS                        0
#define RT8979_FM8_WAITTIME_100MS                       1
#define RT8979_FM8_WAITTIME_150MS                       2
#define RT8979_FM8_WAITTIME_200MS                       3
#define RT8979_FM8_WAITTIME_250MS                       4
#define RT8979_FM8_WAITTIME_300MS                       5
#define RT8979_FM8_WAITTIME_350MS                       6
#define RT8979_FM8_WAITTIME_400MS                       7

/* other defined */
#define RT8979_FM8_MODE                                 17

void usbswitch_rt8979_detach_work(void);
int usbswitch_rt8979_manual_switch(int input_select);
struct switch_interface_control_ops* usbswitch_rt8979_get_control_ops(void);

#endif /* _USBSWITCH_RT8979_H_ */
