/*
 * direct_charge_cable.h
 *
 * cable detect for direct charge module
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

#ifndef _DIRECT_CHARGE_CABLE_H_
#define _DIRECT_CHARGE_CABLE_H_

struct resist_data {
	int vadapt;
	int iadapt;
	int vbus;
	int ibus;
};

#endif /* _DIRECT_CHARGE_CABLE_H_ */
