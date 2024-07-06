/*
 * direct_charge_test.c
 *
 * direct charge test driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <chipset_common/hwpower/adapter/adapter_test.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic_manager.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG direct_charge_test
HWLOG_REGIST();

static const int g_at_mode_tbl[] = {
	[UNDEFINED_MODE] = AT_TYPE_OTHER,
	[LVC_MODE] = AT_TYPE_LVC,
	[SC_MODE] = AT_TYPE_SC,
	[SC4_MODE] = AT_TYPE_SC4,
};

void dc_test_set_adapter_test_result(int mode, int result)
{
	adapter_test_set_result(g_at_mode_tbl[mode], result);
}
