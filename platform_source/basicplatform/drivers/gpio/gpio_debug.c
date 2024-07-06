/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: provide gpio debug function interfaces.
 * Create: 2022-3-27
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <linux/version.h>
#include <linux/gpio.h>

int gpio_input_test(unsigned gpio)
{
	return gpiod_direction_input(gpio_to_desc(gpio));
}

int gpio_output_test(unsigned gpio, int value)
{
	return gpiod_direction_output(gpio_to_desc(gpio), value);
}

#if (LINUX_VERSION_CODE == KERNEL_VERSION(5, 4, 0))
#if defined(CONFIG_ARCH_HISI) && defined(CONFIG_DFX_DEBUG_FS)

int gpio_direction_input_test(unsigned gpio)
{
	return gpio_direction_input(gpio);
}

int gpio_direction_output_test(unsigned gpio, int value)
{
	return gpio_direction_output(gpio, value);
}

#endif
#endif
