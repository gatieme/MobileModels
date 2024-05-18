/*
 * Copyright (c) Honor Device Co., Ltd 2021-2021. All rights reserved.
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

#ifndef __HNRIL_NETLINK_H
#define __HNRIL_NETLINK_H
#include <linux/types.h>

#define HNRIL_GENL_FAMILY "hnril"

enum {
	HNRIL_CMD_UNSPEC,
	HNRIL_CMD_VSIM_SET_IFNAME,
	HNRIL_CMD_VSIM_RESET_IFNAME,
	HNRIL_CMD_VSIM_RESET_COUNTER,
	HNRIL_CMD_VSIM_GET_FLOW,

	HNRIL_CMD_VSIM_NOTIFY,
	__HNRIL_CMD_MAX,
};

#define HNRIL_CMD_MAX (__HNRIL_CMD_MAX - 1)

enum {
	HNRIL_ATTR_UNSPEC,
	HNRIL_ATTR_VSIM_IFNAME,
	HNRIL_ATTR_VSIM_TX_BYTES,
	HNRIL_ATTR_VSIM_RX_BYTES,
	HNRIL_ATTR_VSIM_TEE_TASK,
	HNRIL_ATTR_PAD,
	__HNRIL_ATTR_MAX,
};

#define HNRIL_ATTR_MAX (__HNRIL_ATTR_MAX - 1)

int hnril_nl_vsim_flow_notify(u64 tx_bytes, u64 rx_bytes);
int hnril_nl_vsim_tee_notify(u32 task_type);
#endif	/* __HNRIL_NETLINK_H */
