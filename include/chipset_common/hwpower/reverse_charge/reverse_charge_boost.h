/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge_boost.h
 *
 * reverse charge boost api
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _REVERSE_CHARGE_BOOST_H_
#define _REVERSE_CHARGE_BOOST_H_

#ifdef CONFIG_REVERSE_CHARGE
int boost_set_vcg_on(int enable);
int boost_set_vbus(int vbus);
int boost_set_ibus(int ibus);
int boost_ic_enable(int enable);
int boost_set_idle_mode(int mode);
#else
int boost_set_vcg_on(int enable)
{
	return 0;
}

int boost_set_vbus(int vbus)
{
	return 0;
}

int boost_set_ibus(int ibus)
{
	return 0;
}

int boost_ic_enable(int enable)
{
	return 0;
}

int boost_set_idle_mode(int mode)
{
	return 0;
}
#endif

#endif /* _REVERSE_CHARGE_BOOST_H_ */
