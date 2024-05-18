/*
 * direct_charge_uevent.h
 *
 * uevent handle for direct charge
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

#ifndef _DIRECT_CHARGE_UEVENT_H_
#define _DIRECT_CHARGE_UEVENT_H_

#if IS_ENABLED(CONFIG_DIRECT_CHARGER)
int dc_get_super_charging_flag(void);
void dc_send_super_charging_uevent(void);
void dc_send_max_power_uevent(void);
void dc_send_soc_decimal_uevent(void);
void dc_send_cable_type_uevent(void);
#else
static inline int dc_get_super_charging_flag(void)
{
	return 0;
}

static inline void dc_send_super_charging_uevent(void)
{
}

static inline void dc_send_max_power_uevent(void)
{
}

static inline void dc_send_soc_decimal_uevent(void)
{
}

static inline void dc_send_cable_type_uevent(void)
{
}
#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_UEVENT_H_ */
