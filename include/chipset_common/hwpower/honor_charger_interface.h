/*
 * honor_charger_interface.h
 *
 * honor charger interface drivers
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _HONOR_CHARGER_INTERFACE_
#define _HONOR_CHARGER_INTERFACE_

enum voter_name {
	FLASH_HV_VOTER = 0,
	SYSFS_HV_VOTER,
	USCP_HV_VOTER,
	MAX_HV_VOTER,
};
 /* 1:enable highvol, 0:disable highvol */
void honor_charger_enable_high_voltage_charging(enum voter_name name, int val);

#endif /* _HONOR_CHARGER_INTERFACE_ */
