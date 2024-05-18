/*
 * buck_ic_interface.h
 *
 * buck ic interface drivers
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _BUCK_CHARGER_INTERFACE
#define _BUCK_CHARGER_INTERFACE

#include <hwpower/honor_charger_type.h>

#define PD_FCP_UPPER_VOL_9000MV              9000
#define PD_FCP_LOWER_VOL_5000MV              5000

enum {
	CHAGRE_STATE_CHARGE_READY = 0,
	CHAGRE_STATE_CHARGING,
	CHAGRE_STATE_CHARGE_DONE,
	CHAGRE_STATE_FAULT,
	CHAGRE_STATE_UNKNOW,
};

/**
 * voter has been added to charger_voter,
 * and corresponding voter string must be added to buck_vote_table.
 */
enum charger_voter {
	VOTER_DEFAULT = 0,
	VOTER_JETIA,
	VOTER_RUNTEST,
	VOTER_SYSFS,
	VOTER_INTERFACE,
	VOTER_DC,
	VOTER_BASP,
	VOTER_WIRELESS,
	VOTER_THERMAL,
	VOTER_USCP,
	VOTER_SW_TERM, /* software term and rechg */
	VOTER_MAX,
};

/**
 * SET_DEFAULT: only client current value different last value, the current value can vote with
 * other clients vote final result, set in the device register
 * SET_NORMAL: current client value always be voted with other clients value vote final result,
 * set in the device register
 * SET_OVERRIDE: mask other client value vote , only current client value vote take effect,
 * set in the device register
 */
enum buck_charger_set_vote_type {
	SET_DEFAULT = 0,
	SET_NORMAL,
	SET_OVERRIDE,
	SET_TYPE_MAX,
};

/**
 * GET_CLIENT_EN: get current client voted result is valid or invalid
 * GET_CLIENT_VAL: get current client voted value
 * GET_EFFECTIVE_RESULT: get all client vote effective result
 */
enum buck_charger_get_vote_type {
	GET_CLIENT_EN = 0,
	GET_CLIENT_VAL,
	GET_EFFECTIVE_RESULT,
	GET_TYPE_MAX,
};

/* vote name */
enum buck_charger_vote_name {
	/* main ic */
	MAIN_IC_ILIM = 0,
	MAIN_IC_ICHG,
	MAIN_IC_CV,
	MAIN_IC_ITERM,
	MAIN_IC_CHG_EN,
	MAIN_IC_EN_WTD,
	MAIN_IC_HIZ,
	MAIN_IC_EOC,
	MAIN_IC_VDPM,
	MAIN_IC_OTG_EN,
	MAIN_IC_OVP_EN,
	/* aux ic */
	AUX_IC_ILIM,
	AUX_IC_ICHG,
	AUX_IC_CV,
	AUX_IC_ITERM,
	AUX_IC_CHG_EN,
	AUX_IC_EN_WTD,
	AUX_IC_HIZ,
	AUX_IC_EOC,
	AUX_IC_VDPM,
	AUX_IC_OTG_EN,
	AUX_IC_OVP_EN,
	/* other */
	ADAPTER_VOL, /* set adapter vol */
	SDP_CUR, /* factory set at cmd sdp current */
	ALL_VOTE_MAX,
};

enum buck_charger_if_info_type {
	/* main */
	MAIN_IC_VBUS = 0,
	MAIN_IC_IBUS,
	MAIN_IC_CHG_DONE,
	MAIN_IC_CHG_STATE,
	MAIN_IC_VPH_PWR,
	MAIN_IC_MONITOR,
	/* aux */
	AUX_IC_VBUS,
	AUX_IC_IBUS,
	AUX_IC_CHG_DONE,
	AUX_IC_CHG_STATE,
	AUX_IC_VPH_PWR,
	AUX_IC_MONITOR,
	/* other */
	CHG_TYPE,
	MAIN_INFO_MAX,
};

typedef enum buck_charger_driver_type {
	CHARGER_DRIVER_TYPE_BEGIN = 0,
	CHARGER_DRIVER_TYPE_BC12_DETECT,
	CHARGER_DRIVER_TYPE_BUCK_MAIN = CHARGER_DRIVER_TYPE_BEGIN,
	CHARGER_DRIVER_TYPE_BUCK_AUX,
	CHARGER_DRIVER_TYPE_MAX,
} buck_charger_driver_type;

struct buck_charger_interface_adapter_ops
{
	int (*set_adapter_output_vol)(int val);
};

int buck_charger_interface_adapter_register(struct buck_charger_interface_adapter_ops *ops);
int buck_charger_interface_adapter_unregister(struct buck_charger_interface_adapter_ops *ops);

int buck_charger_interface_get_info(enum buck_charger_if_info_type type, int *val);
int buck_charger_interface_set_info(enum buck_charger_if_info_type type, int val);
int buck_charger_interface_set_vote_val(enum buck_charger_vote_name name,
	enum charger_voter chg_voter,
	enum buck_charger_set_vote_type set_type,
	int val);
int buck_charger_interface_get_vote_val(enum buck_charger_vote_name name,
	enum charger_voter chg_voter,
	enum buck_charger_get_vote_type get_type,
	int *val);
#endif /* _BUCK_CHARGER_INTERFACE */