/*
 * battery_leakage_public.h
 *
 * honor battery leakage kernel info collect
 *
 * Copyright (c) 2022 Honor Technologies Co., Ltd.
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

#ifndef _BATTERY_LEAKAGE_PUBLIC_H_
#define _BATTERY_LEAKAGE_PUBLIC_H_

struct bat_leakage_ops {
	void *dev_data;
	int (*get_iterm_ma)(void *); /* must */
	int (*get_ibat_ma)(void *, int *);  /* not must use power supply instead */
	int (*get_vbat_uv)(void *, int *);  /* not must use power supply instead */
	int (*get_temp)(void *, int *);     /* not must use power supply instead */
};

#if IS_ENABLED(CONFIG_HONOR_BATTERY_LEAKAGE)
int bat_leakage_register_ops(struct bat_leakage_ops *ops);
void bat_leakage_check_chg_cur_low_enough(void);
#else
static inline int bat_leakage_register_ops(struct bat_leakage_ops *ops)
{
    return 0;
}
static inline void bat_leakage_check_chg_cur_low_enough(void)
{
}
#endif

#endif /* _BATTERY_LEAKAGE_PUBLIC_H_ */