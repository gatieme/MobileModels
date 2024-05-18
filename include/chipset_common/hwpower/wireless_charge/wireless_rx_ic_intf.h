/*
 * wireless_rx_ic_intf.h
 *
 * common interface, varibles, definition etc for wireless_rx_ic_intf
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

#ifndef _WIRELESS_RX_IC_INTF_H_
#define _WIRELESS_RX_IC_INTF_H_

#include <linux/device.h>
#include <hwpower/wireless_charge/wireless_trx_ic_intf.h>

struct wlrx_ic_ops {
	void *dev_data;
	struct device_node *(*get_dev_node)(void *);
};

#if IS_ENABLED(CONFIG_WIRELESS_CHARGER)
int wlrx_ic_ops_register(struct wlrx_ic_ops *ops, unsigned int type);
struct device_node *wlrx_get_dev_node(unsigned int type);
#else
static inline int wlrx_ic_ops_register(struct wlrx_ic_ops *ops, unsigned int type)
{
	return 0;
}

static inline struct device_node *wlrx_get_dev_node(unsigned int type)
{
	return NULL;
}
#endif /* CONFIG_WIRELESS_CHARGER */

#endif /* _WIRELESS_RX_IC_INTF_H_ */
