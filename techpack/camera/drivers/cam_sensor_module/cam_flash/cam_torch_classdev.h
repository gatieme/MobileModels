/*
 * cam_torch_classdev.h
 *
 * Copyright (c) 2020-2020 Honor Technologies Co., Ltd.
 *
 * fled regulator interface
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

#ifndef _CAM_TORCH_CLASSDEV_H_
#define _CAM_TORCH_CLASSDEV_H_

#include <linux/leds.h>
#include <linux/platform_device.h>
#include <linux/device.h>

struct torch_classdev_data {
	struct device *dev;
	struct led_classdev cdev_torch;
	struct led_trigger *torch_trigger;
	struct led_trigger *switch_trigger;
	struct mutex lock;
	bool is_regulator_enabled;
};

int cam_torch_classdev_register(struct platform_device *pdev, void *data);

#endif /* _CAM_TORCH_CLASSDEV_H_ */
