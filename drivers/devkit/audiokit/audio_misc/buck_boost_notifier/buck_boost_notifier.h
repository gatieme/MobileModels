/*
 * buck_boost_notifier.h
 *
 * buck_boost_notifier driver
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __BUCK_BOOST_NOTIFIER_H__
#define __BUCK_BOOST_NOTIFIER_H__

#include "../audio_misc.h"

/*Ioctl for buck_boost pwm*/
#define BUCK_BOOST_IOCTL_TYPE           'A'
#define BUCK_BOOST_NOTIFIER              _IOW(BUCK_BOOST_IOCTL_TYPE, 0x01, int)

#define BUCK_BOOST_INDEX 				 0
#define BUCK_BOOST_PWM_ENABLE            1
#define BUCK_BOOST_PWM_DISABLE           0

int buck_boost_notifier_probe(struct device *dev, struct device_node *np);

#endif  /* __BUCK_BOOST_NOTIFIER_H__ */
