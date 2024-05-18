/*
 * wireless_trx_ic_intf.h
 *
 * common interface, varibles, definition etc for wireless_trx_ic_intf
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

#ifndef _WIRELESS_TRX_IC_INTF_H_
#define _WIRELESS_TRX_IC_INTF_H_

#include <linux/bitops.h>

#define WLTRX_IC_MAIN             BIT(0)
#define WLTRX_IC_AUX              BIT(1)
#define WLTRX_IC_MULTI            (WLTRX_IC_MAIN | WLTRX_IC_AUX)

enum wltrx_ic_type {
	WLTRX_IC_TYPE_MAIN = 0,
	WLTRX_IC_TYPE_AUX,
	WLTRX_IC_TYPE_MAX,
};

#endif /* _WIRELESS_TRX_IC_INTF_H_ */
