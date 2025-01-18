// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge_scp_auth.c
 *
 * authenticate for reverse scp charge
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/completion.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_genl.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_scp_auth.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_protocol.h>
#include <securec.h>

#define HWLOG_TAG rscp_charge_auth
HWLOG_REGIST();

static struct completion g_rscp_auth_completion;
static bool g_rscp_auth_srv_state;
static int g_rscp_auth_result;
static u8 g_rscp_auth_hash[RSCP_AUTH_RANDOM_LEN];

bool rscp_auth_get_srv_state(void)
{
	return g_rscp_auth_srv_state;
}

void rscp_auth_clean_hash_data(void)
{
	memset_s(g_rscp_auth_hash, RSCP_AUTH_RANDOM_LEN, 0x00, RSCP_AUTH_RANDOM_LEN);
}

u8 *rscp_auth_get_hash_data_header(void)
{
	return g_rscp_auth_hash;
}

unsigned int rscp_auth_get_hash_data_size(void)
{
	return RSCP_AUTH_RANDOM_LEN;
}

static int rscp_auth_wait_service_ready(void)
{
	int i;
	int delay = RSCP_AUTH_RETRY_INTERVAL_BASE;

	for (i = 1; i <= RSCP_AUTH_RETRY_COUNT; i++) {
		power_msleep(delay, 0, NULL);
		if (g_rscp_auth_srv_state == true)
			return 0;

		if (i % RSCP_AUTH_RETRY_INTERVAL_CYCLE == 0) {
			delay = RSCP_AUTH_RETRY_INTERVAL_BASE +
				i / RSCP_AUTH_RETRY_INTERVAL_CYCLE * RSCP_AUTH_RETRY_INTERVAL_INC;
			power_event_bnc_notify(POWER_BNT_BMS_AUTH, POWER_NE_BMS_AUTH_START_FORCE, "rscp_charge");
			power_msleep(delay, 0, NULL);
		}
	}
	return -EPERM;
}

int rscp_auth_wait_completion(void)
{
	int ret = -EPERM;

	g_rscp_auth_result = 0;
	reinit_completion(&g_rscp_auth_completion);

	power_event_bnc_notify(POWER_BNT_BMS_AUTH, POWER_NE_BMS_AUTH_START, "rscp_charge");

	/*
	 * if bms_auth service not ready, we assume the serivce is dead,
	 * return hash calculate ok anyway
	 */
	if (rscp_auth_wait_service_ready()) {
		hwlog_err("service not ready\n");
		goto end;
	}
	if (power_genl_easy_send(POWER_GENL_TP_AF,
		POWER_GENL_CMD_RSCP_AUTH_HASH, 0,
		g_rscp_auth_hash, RSCP_AUTH_RANDOM_LEN)) {
		hwlog_err("power genl send rscp auth failed\n");
		goto end;
	}
	/*
	 * if timeout happend, we assume the serivce is dead,
	 * return hash calculate ok anyway
	 */
	if (!wait_for_completion_timeout(&g_rscp_auth_completion,
		msecs_to_jiffies(RSCP_AUTH_WAIT_TIMEOUT))) {
		hwlog_err("service wait timeout\n");
		goto end;
	}
	/*
	 * if not timeout,
	 * return the antifake result base on the hash calc result
	 */
	if (g_rscp_auth_result == 0) {
		hwlog_err("hash calculate fail\n");
		goto end;
	}

	hwlog_err("hash calculate ok\n");
	ret = 0;
end:
	power_event_bnc_notify(POWER_BNT_BMS_AUTH, POWER_NE_BMS_AUTH_STOP, "rscp_charge");
	return ret;
}

static int rscp_auth_srv_state_cb(bool state)
{
	g_rscp_auth_srv_state = state;
	hwlog_err("srv_%s_cb ok\n", state ? "on" : "off");
	return 0;
}

static int rscp_auth_cb(unsigned char version, void *data, int len)
{
	u8 hash[RSCP_AUTH_HASH_LEN] = { 0 };

	if (!data || (len != RSCP_AUTH_HASH_LEN)) {
		hwlog_err("data is null or len invalid\n");
		return -EPERM;
	}

	g_rscp_auth_result = true;
	complete(&g_rscp_auth_completion);

	memcpy_s(hash, RSCP_AUTH_HASH_LEN, data, RSCP_AUTH_HASH_LEN);
	rprot_set_rscp_auth_result(hash, RSCP_AUTH_HASH_LEN);

	hwlog_err("version=%u auth_result=%d\n", version, g_rscp_auth_result);
	return 0;
}

static const struct power_genl_easy_ops rscp_auth_easy_ops[] = {
	{
		.cmd = POWER_GENL_CMD_RSCP_AUTH_HASH,
		.doit = rscp_auth_cb,
	}
};

static struct power_genl_node rscp_auth_genl_node = {
	.target = POWER_GENL_TP_AF,
	.name = "RSCP_AUTH",
	.easy_ops = rscp_auth_easy_ops,
	.n_easy_ops = RSCP_AUTH_GENL_OPS_NUM,
	.srv_state_cb = rscp_auth_srv_state_cb,
};

static int __init rscp_auth_init(void)
{
	init_completion(&g_rscp_auth_completion);
	power_genl_easy_node_register(&rscp_auth_genl_node);
	return 0;
}

static void __exit rscp_auth_exit(void)
{
}

subsys_initcall(rscp_auth_init);
module_exit(rscp_auth_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("auth for reverse scp charge module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
