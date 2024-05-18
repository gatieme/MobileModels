/*
 * power_compensation.h
 *
 * compensation for power module
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _POWER_COMPENSATION_H_
#define _POWER_COMPENSATION_H_

#include <hwpower/power_algorithm.h>

#define NTC_PARA_LEVEL			20
#define COMPENSATION_THRESHOLD		200

enum ntc_temp_compensation_para_info {
	NTC_PARA_ICHG = 0,
	NTC_PARA_VALUE,
	NTC_PARA_TOTAL,
};

#if IS_ENABLED(CONFIG_HONOR_COMMON_POWER)
void power_compensation_parse_ntc_para(const struct device_node *np,
	int *ntc_compensation_is, struct compensation_para *para);
int power_compensation_get_ntc_temp(int ntc_compensation_is, struct compensation_para *para,
	int temp_val, int cur_temp);
#else
static inline void power_compensation_parse_ntc_para(const struct device_node *np,
	int *ntc_compensation_is, struct compensation_para *para)
{
}

static inline int power_compensation_get_ntc_temp(int ntc_compensation_is, struct compensation_para *para,
	int temp_val, int cur_temp)
{
	return -1;
}
#endif /* CONFIG_HONOR_COMMON_POWER */

#endif /* _POWER_COMPENSATION_H_ */

