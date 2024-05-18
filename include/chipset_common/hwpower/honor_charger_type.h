/*
 * honor_charger_type.h
 *
 * honor charger type driver
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _HONOR_CHARGER_TYPE
#define _HONOR_CHARGER_TYPE

/* affects other modules(chargerType node), do not change the order */
typedef enum honor_charge_type {
	CHARGER_TYPE_USB = 0,
	CHARGER_TYPE_BC_USB,
	CHARGER_TYPE_NON_STANDARD,
	CHARGER_TYPE_STANDARD,
	CHARGER_TYPE_FCP,
	CHARGER_REMOVED,
	USB_EVENT_OTG_ID,
	CHARGER_TYPE_VR,
	CHARGER_TYPE_TYPEC,
	CHARGER_TYPE_PD,
	CHARGER_TYPE_SCP,
	CHARGER_TYPE_WIRELESS,
	CHARGER_TYPE_POGOPIN,
	CHARGER_TYPE_CTC,          /* ctc */
} honor_charge_type;

static char *adapter_info[] = {
	[CHARGER_TYPE_USB] = "usb",
	[CHARGER_TYPE_BC_USB] = "bc_usb",
	[CHARGER_TYPE_NON_STANDARD] = "non_standard",
	[CHARGER_TYPE_STANDARD] = "dcp",
	[CHARGER_TYPE_FCP] = "fcp ",
	[CHARGER_REMOVED] = "adapter removed",
	[USB_EVENT_OTG_ID] = "otg_id",
	[CHARGER_TYPE_VR] = "vr",
	[CHARGER_TYPE_TYPEC] = "typec",
	[CHARGER_TYPE_PD] = "pd",
	[CHARGER_TYPE_SCP] = "scp",
	[CHARGER_TYPE_WIRELESS] = "wireless",
	[CHARGER_TYPE_POGOPIN] = "pogogin",
	[CHARGER_TYPE_CTC] = "ctc",
};

static inline const char *charge_adapter_name(honor_charge_type type)
{
	if ((type < CHARGER_TYPE_USB) ||
		(type > CHARGER_TYPE_CTC)) {
		return "unknow type";
	}

	return adapter_info[type];
}
#endif /* _HONOR_CHARGER_TYPE */
