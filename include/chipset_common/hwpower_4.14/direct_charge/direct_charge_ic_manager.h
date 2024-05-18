/*
 * direct_charge_ic_manager.h
 *
 * direct charge ic management interface
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

#ifndef _DIRECT_CHARGE_IC_MANAGER_H_
#define _DIRECT_CHARGE_IC_MANAGER_H_

#include <linux/init.h>
#include <linux/bitops.h>

#define DC_IC_ENABLE            1
#define DC_IC_DISABLE           0
#define DC_IC_VAC_INSERT_ENABLE  1
#define DC_IC_VAC_INSERT_DISABLE 0

#define SENSE_R_1_MOHM          10 /* 1 mohm */
#define SENSE_R_2_MOHM          20 /* 2 mohm */
#define SENSE_R_2P5_MOHM        25 /* 2.5 mohm */
#define SENSE_R_5_MOHM          50 /* 5 mohm */
#define SENSE_R_10_MOHM         100 /* 10 mohm */

#define CHARGE_IC_MAX_NUM       2
#define CHARGE_IC_MAIN          BIT(0)
#define CHARGE_IC_AUX           BIT(1)
#define CHARGE_MULTI_IC         (CHARGE_IC_MAIN | CHARGE_IC_AUX)

enum dc_working_mode {
	UNDEFINED_MODE = 0x0,
	LVC_MODE = 0x1,
	SC_MODE = 0x2,
	HSC_MODE = 0x4,
};

enum dc_ic_type {
	CHARGE_IC_TYPE_MAIN = 0,
	CHARGE_IC_TYPE_AUX,
	CHARGE_IC_TYPE_MAX,
};

enum dc_sc_working_mode {
	SC_FBBY_MODE = 0x0,
	SC_F21SC_MODE = 0x1,
	SC_F41SC_MODE = 0x2,
	SC_RBPS_MODE = 0x3,
	SC_R12SC_MODE = 0x4,
	SC_R14SC_MODE = 0x5,
};

struct dc_ic_ops {
	void *dev_data;
	const char *dev_name;
	int (*ic_init)(void *);
	int (*ic_exit)(void *);
	int (*ic_enable)(int, void *);
	int (*ic_adc_enable)(int, void *);
	int (*ic_discharge)(int, void *);
	int (*is_ic_close)(void *);
	int (*ic_enable_prepare)(void *);
	int (*config_ic_watchdog)(int, void *);
	int (*kick_ic_watchdog)(void *);
	int (*get_ic_id)(void *);
	int (*get_ic_status)(void *);
	int (*set_ic_buck_enable)(int, void *);
	int (*ic_reg_reset_and_init)(void *);
	void (*vusb_uv_det_enable)(u8, void *);
	int (*ic_set_sc_mode)(int, void *);
	int (*ic_set_ovp_gate)(int, void *);
	int (*ic_vac_insert_control)(int, void *);
	int (*ic_config_freq_shift)(int, void *);
};

struct dc_batinfo_ops {
	void *dev_data;
	int (*init)(void *);
	int (*exit)(void *);
	int (*get_bat_btb_voltage)(void *);
	int (*get_bat_package_voltage)(void *);
	int (*get_vbus_voltage)(int *, void *);
	int (*get_bat_current)(int *, void *);
	int (*get_ic_ibus)(int *, void *);
	int (*get_ic_temp)(int *, void *);
	int (*get_ic_vout)(int *, void *);
	int (*get_ic_vusb)(int *, void *);
};

#ifdef CONFIG_DIRECT_CHARGER
int dc_ic_ops_register(int mode, unsigned int type, struct dc_ic_ops *ops);
int dc_batinfo_ops_register(int mode, unsigned int type, struct dc_batinfo_ops *ops);
int dc_ic_init(int mode, unsigned int type);
int dc_ic_exit(int mode, unsigned int type);
int dc_ic_enable(int mode, unsigned int type, int enable);
int dc_ic_adc_enable(int mode, unsigned int type, int enable);
int dc_ic_discharge(int mode, unsigned int type, int enable);
int dc_is_ic_close(int mode, unsigned int type);
bool dc_is_ic_support_prepare(int mode, unsigned int type);
int dc_ic_enable_prepare(int mode, unsigned int type);
int dc_config_ic_watchdog(int mode, unsigned int type, int time);
int dc_kick_ic_watchdog(int mode, unsigned int type);
int dc_get_ic_id(int mode, unsigned int type);
int dc_get_ic_status(int mode, unsigned int type);
int dc_set_ic_buck_enable(int mode, unsigned int type, int enable);
int dc_ic_reg_reset_and_init(int mode, unsigned int type);
const char *dc_get_ic_name(int mode, unsigned int type);
int dc_ic_set_sc_mode(int mode, unsigned int type, int sc_mode);
int dc_ic_set_ovp_gate(int mode, unsigned int type, int ovp_gate);
int dc_batinfo_init(int mode, unsigned int type);
int dc_batinfo_exit(int mode, unsigned int type);
int dc_get_bat_btb_voltage(int mode, unsigned int type);
int dc_get_bat_package_voltage(int mode, unsigned int type);
int dc_get_bat_btb_voltage_with_comp(int mode, unsigned int type, const int *vbat_comp);
int dc_get_bat_max_btb_voltage_with_comp(int mode, const int *vbat_comp);
int dc_get_vbus_voltage(int mode, unsigned int type, int *vbus);
int dc_get_bat_current(int mode, unsigned int type, int *ibat);
int dc_get_bat_current_with_calibration(int mode, unsigned int type, int *ibat, int comb);
int dc_get_ic_ibus(int mode, unsigned int type, int *ibus);
int dc_get_ic_temp(int mode, unsigned int type, int *temp);
int dc_get_ic_vusb(int mode, unsigned int type, int *vusb);
int dc_get_ic_vout(int mode, unsigned int type, int *vout);
int dc_get_ic_max_temp(int mode, int *temp);
int dc_get_total_bat_current(int mode, int *ibat);
int dc_get_bat_btb_avg_voltage(int mode, int *vbat);
int dc_get_bat_package_avg_voltage(int mode, int *vbat);
int dc_get_vbus_avg_voltage(int mode, int *vbus);
int dc_set_vusb_uv_det(int mode, unsigned int type, u8 val);
int dc_ic_vac_insert_control(int mode, unsigned int type, int enable);
int dc_ic_set_freq(int mode, unsigned int type, int data);

#else
static inline int dc_ic_ops_register(int mode, unsigned int type,
	struct dc_ic_ops *ops)
{
	return -1;
}

static inline int dc_set_vusb_uv_det(int mode,
	unsigned int type, u8 val)
{
	return -1;
}

static inline int dc_batinfo_ops_register(int mode, unsigned int type,
	struct dc_batinfo_ops *ops)
{
	return -1;
}

static inline int dc_ic_init(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_ic_exit(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_ic_enable(int mode, unsigned int type, int enable)
{
	return -1;
}

static inline int dc_ic_set_freq(int mode, unsigned int type, int data)
{
	return -1;
}

static int dc_ic_vac_insert_control(int mode, unsigned int type, int enable)
{
	return -1;
}
static inline int dc_ic_adc_enable(int mode, unsigned int type, int enable)
{
	return -1;
}

static inline int dc_ic_discharge(int mode, unsigned int type, int enable)
{
	return -1;
}

static inline int dc_is_ic_close(int mode, unsigned int type)
{
	return -1;
}

static inline bool dc_is_ic_support_prepare(int mode, unsigned int type)
{
	return false;
}

static inline int dc_ic_enable_prepare(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_config_ic_watchdog(int mode, unsigned int type, int time)
{
	return -1;
}

static inline int dc_kick_ic_watchdog(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_get_ic_id(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_get_ic_status(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_set_ic_buck_enable(int mode, unsigned int type, int enable)
{
	return -1;
}

static inline int dc_ic_reg_reset_and_init(int mode, unsigned int type)
{
	return -1;
}

static inline const char *dc_get_ic_name(int mode, unsigned int type)
{
	return "invalid ic";
}

static inline int dc_batinfo_init(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_batinfo_exit(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_get_bat_btb_voltage(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_get_bat_package_voltage(int mode, unsigned int type)
{
	return -1;
}

static inline int dc_get_bat_btb_voltage_with_comp(int mode, unsigned int type, const int *vbat_comp)
{
	return -1;
}

static inline int dc_get_bat_max_btb_voltage_with_comp(int mode, const int *vbat_comp)
{
	return -1;
}

static inline int dc_get_vbus_voltage(int mode, unsigned int type, int *vbus)
{
	return -1;
}

static inline int dc_get_bat_current(int mode, unsigned int type, int *ibat)
{
	return -1;
}

static inline int dc_get_bat_current_with_calibration(int mode, unsigned int type, int *ibat, int comb)
{
	return -1;
}

static inline int dc_get_ic_ibus(int mode, unsigned int type, int *ibus)
{
	return -1;
}

static inline int dc_get_ic_temp(int mode, unsigned int type, int *temp)
{
	return -1;
}

static inline int dc_get_ic_vusb(int mode, unsigned int type, int *vusb)
{
	return -1;
}

static inline int dc_get_ic_vout(int mode, unsigned int type, int *vout)
{
	return -1;
}

static inline int dc_get_ic_max_temp(int mode, int *temp)
{
	return -1;
}

static inline int dc_get_total_bat_current(int mode, int *ibat)
{
	return -1;
}

static inline int dc_get_bat_btb_avg_voltage(int mode, int *vbat)
{
	return -1;
}

static inline int dc_get_bat_package_avg_voltage(int mode, int *vbat)
{
	return -1;
}

static inline int dc_get_vbus_avg_voltage(int mode, int *vbus)
{
	return -1;
}
#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_IC_MANAGER_H_ */
