/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 Huawei Technologies Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <platform/linux/blackbox.h>
#include <platform/linux/blackbox_subsystem_def.h>
#include <platform/linux/blackbox_subsystem.h>

struct subsys_list {
	char *subsys_name;
	unsigned int subsys_num;
};

struct subsys_list find_subsys_number[] = {
	{"2400000.remoteproc-slpi", SLPI_SUBSYS_NUMBER},
	{"3000000.remoteproc-adsp", ADSP_SUBSYS_NUMBER},
	{"32300000.remoteproc-cdsp", CDSP_SUBSYS_NUMBER},
	{"4080000.remoteproc-mss", MODEM_SUBSYS_NUMBER},
	{"CNSS_WLAN", WLAN_SUBSYS_NUMBER},
	{"bt", BT_SUBSYS_NUMBER},
	{"venus", VENUS_SUBSYS_NUMBER},
};

static int bbox_find_subsys_number(const char *name)
{
	unsigned int i;
	unsigned int number = 0;
	for (i = 0; i < sizeof(find_subsys_number) / sizeof(struct subsys_list); i++) {
		if (!strcmp(name, find_subsys_number[i].subsys_name)) {
			number = find_subsys_number[i].subsys_num;
			break;
		}
	}
	bbox_print_info("bbox_find_subsys_number: %d\n", number);
	return number;
}

int bbox_subsystem_crash_notify(const char *name)
{
	char event[EVENT_MAX_LEN] = "NULL";
	char module[MODULE_MAX_LEN] = "NULL";
	char error_desc[ERROR_DESC_MAX_LEN] = "NULL";

	unsigned int number = bbox_find_subsys_number(name);

	switch (number) {
	case SLPI_SUBSYS_NUMBER:
		strncpy(event, EVENT_SLPI_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_SLPI, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_SLPI_CRASH, sizeof(error_desc) - 1);
		break;
	case ADSP_SUBSYS_NUMBER:
		strncpy(event, EVENT_ADSP_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_ADSP, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_ADSP_CRASH, sizeof(error_desc) - 1);
		break;
	case CDSP_SUBSYS_NUMBER:
		strncpy(event, EVENT_CDSP_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_CDSP, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_CDSP_CRASH, sizeof(error_desc) - 1);
		break;
	case MODEM_SUBSYS_NUMBER:
		strncpy(event, EVENT_MSS_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_MSS, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_MSS_CRASH, sizeof(error_desc) - 1);
		break;
	case WLAN_SUBSYS_NUMBER:
		strncpy(event, EVENT_WLAN_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_WLAN, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_WLAN_CRASH, sizeof(error_desc) - 1);
		break;
	case BT_SUBSYS_NUMBER:
		strncpy(event, EVENT_BT_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_BT, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_BT_CRASH, sizeof(error_desc) - 1);
		break;
	case VENUS_SUBSYS_NUMBER:
		strncpy(event, EVENT_VENUS_CRASH, sizeof(event) - 1);
		strncpy(module, MODULE_VENUS, sizeof(module) - 1);
		strncpy(error_desc, ERROR_DESC_VENUS_CRASH, sizeof(error_desc) - 1);
		break;
	default:
		bbox_print_err("bbox_cp:invalid event code: %lu!\n", number);
		break;
	}

	bbox_notify_error(event, module, error_desc, false);
	bbox_print_err("bbox_cp:bbox_notify_error %s\n", error_desc);

	return 0;
}
EXPORT_SYMBOL(bbox_subsystem_crash_notify);

static void dump(const char *log_dir, struct error_info *info)
{
	bbox_print_err("Bbox_subsys: Get subsys dump elf!");
}
static void reset(struct error_info *info)
{
	bbox_print_err("Bbox_subsys: Reset the cp!");
}

void subsystem_register_module_ops(void)
{
#define subsys_module_ops(name) \
		struct module_ops ops_##name = { \
			.module = #name, \
			.dump = dump, \
			.reset = reset, \
			.get_last_log_info = NULL, \
			.save_last_log = NULL, \
		};
	subsys_module_ops(CP)
	subsys_module_ops(SLPI)
	subsys_module_ops(ADSP)
	subsys_module_ops(CDSP)
	subsys_module_ops(MODEM)
	subsys_module_ops(WLAN)
	subsys_module_ops(BT)
	subsys_module_ops(VENUS)

	if (!bbox_register_module_ops(&ops_CP))
		bbox_print_info("bbox_cp register ops succ");
	else
		bbox_print_info("bbox_cp register ops failed");

	if (!bbox_register_module_ops(&ops_SLPI))
		bbox_print_info("bbox_slpi register ops succ");
	else
		bbox_print_info("bbox_slpi register ops failed");

	if (!bbox_register_module_ops(&ops_ADSP))
		bbox_print_info("bbox_adsp register ops succ");
	else
		bbox_print_info("bbox_adsp register ops failed");

	if (!bbox_register_module_ops(&ops_CDSP))
		bbox_print_info("bbox_cdsp register ops succ");
	else
		bbox_print_info("bbox_cdsp register ops failed");

	if (!bbox_register_module_ops(&ops_MODEM))
		bbox_print_info("bbox_modem register ops succ");
	else
		bbox_print_info("bbox_modem register ops failed");

	if (!bbox_register_module_ops(&ops_WLAN))
		bbox_print_info("bbox_wlan register ops succ");
	else
		bbox_print_info("bbox_wlan register ops failed");

	if (!bbox_register_module_ops(&ops_BT))
		bbox_print_info("bbox_bt register ops succ");
	else
		bbox_print_info("bbox_bt register ops failed");

	if (!bbox_register_module_ops(&ops_VENUS))
		bbox_print_info("bbox_venus register ops succ");
	else
		bbox_print_info("bbox_venus register ops failed");
}
EXPORT_SYMBOL(subsystem_register_module_ops);

