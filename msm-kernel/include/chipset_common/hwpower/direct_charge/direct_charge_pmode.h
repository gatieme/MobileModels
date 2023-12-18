/*
 * direct_charge_pmode.h
 *
 * direct charge pmode driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#ifndef _DIRECT_CHARGE_PMODE_H_
#define _DIRECT_CHARGE_PMODE_H_

enum dc_dis_flag {
	DC_EN = 0,
	DC_DIS_BY_CHRG_DONE = BIT(0),
	DC_DIS_BY_PRIORITY = BIT(1),
};

#ifdef CONFIG_DIRECT_CHARGER
void dc_clear_pmode_data(void);
int dc_get_pmode_max_pwr(unsigned int mode);
void dc_enable_mode(unsigned int flag, unsigned int mode);
void dc_disable_mode(unsigned int flag, unsigned int mode);
int dc_init_local_mode(void);
int dc_init_adp_mode(unsigned int *mode);
void dc_update_mode_power(void);
unsigned int dc_get_optimal_mode(void);
int dc_get_pmode_pwr(void);
#else
static inline void dc_clear_pmode_data(void)
{
}

static inline int dc_get_pmode_max_pwr(unsigned int mode)
{
	return 0;
}

static inline void dc_enable_mode(unsigned int flag, unsigned int mode)
{
}

static inline void dc_disable_mode(unsigned int flag, unsigned int mode)
{
}

static inline int dc_init_local_mode(void)
{
	return -1;
}

static inline int dc_init_adp_mode(unsigned int *mode)
{
	return -1;
}

static inline void dc_update_mode_power(void)
{
}

static inline unsigned int dc_get_optimal_mode(void)
{
	return UNDEFINED_MODE;
}

static inline int dc_get_pmode_pwr(void)
{
	return 0;
}

#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_PMODE_H_ */
