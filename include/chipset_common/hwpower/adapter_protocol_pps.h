/*
 * adapter_protocol_pps.h
 *
 * pps protocol driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#ifndef _ADAPTER_PROTOCOL_PPS_H_
#define _ADAPTER_PROTOCOL_PPS_H_

#define PPS_PROTOCOL_ISSET_STEP              50 /* step: 50ma */

enum pps_protocol_device_id {
	PPS_DEVICE_ID_BEGIN = 0,
	PPS_DEVICE_ID_MT6375 = PPS_DEVICE_ID_BEGIN,
	PPS_DEVICE_ID_BUILDIN,
	PPS_DEVICE_ID_END,
};

struct pps_protocol_device_info {
	int output_voltage;
	int output_current;
	int max_current;
	int inside_temp;
};

struct pps_protocol_ops {
	const char *chip_name;
	int (*set_output_voltage)(int volt);
	int (*get_output_voltage)(int *volt);
	int (*set_output_current)(int cur);
	int (*get_output_current)(int *cur);
	int (*get_output_current_set)(int *cur);
	int (*get_max_current)(int *cur);
	int (*get_inside_temp)(int *temp);
	int (*get_adp_type)(int *type);
	int (*set_default_state)(void);
	bool (*get_rdy_st)(void);
};

struct pps_protocol_dev {
	struct device *dev;
	struct pps_protocol_device_info info;
	struct pps_protocol_ops *p_ops;
	int dev_id;
};

#if IS_ENABLED(CONFIG_ADAPTER_PROTOCOL_PPS)
int pps_protocol_ops_register(struct pps_protocol_ops *ops);
#else
static inline int pps_protocol_ops_register(struct pps_protocol_ops *ops)
{
	return -1;
}
#endif /* CONFIG_ADAPTER_PROTOCOL_PPS */

#endif /* _ADAPTER_PROTOCOL_PPS_H_ */

