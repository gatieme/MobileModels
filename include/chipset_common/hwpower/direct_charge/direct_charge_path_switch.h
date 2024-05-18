/*
 * direct_charge_path_switch.h
 *
 * path switch for direct charge
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

#ifndef _DIRECT_CHARGE_PATH_SWITCH_H_
#define _DIRECT_CHARGE_PATH_SWITCH_H_

/*
 * define charging path with direct charge
 */
enum dc_charging_path_type {
	PATH_BEGIN,
	PATH_NORMAL = PATH_BEGIN,
	PATH_LVC,
	PATH_SC,
	PATH_END,
};

#endif /* _DIRECT_CHARGE_PATH_SWITCH_H_ */
