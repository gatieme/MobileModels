// SPDX-License-Identifier: GPL-2.0
/*
 * hl7603.c
 *
 * hl7603 driver
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include "hl7603.h"
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_devices_info.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/hardware_ic/buck_boost.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>

#define HWLOG_TAG hl7603
HWLOG_REGIST();

#define HL7603_VOUT_SEL_MAX                          5000
#define HL7603_VOUT_SEL_MIN                          2850
#define HL7603_DBG_NAME_LEN                          16
#define HL7603_DSM_BUFF_SIZE                         64
#define HL7603_ABNORMAL_STATE_MASK                   0x86
#define HL7603_SHUTDOWN_DELAY_MS                     5
#define HL7603_SHUTDOWN_SET_VEL                      4750
#define HL7603_MAX_REG_ADDR                          0X05
#define HL7603_ADC_CHANNEL_NONE                      -1
#define HL7603_ADC_UNIT                              1000

enum {
	HL7603_STATUS_FAULT,
	HL7603_STATUS_POWER_GOOD,
};

static int hl7603_read_byte(struct hl7603_device_info *di, u8 reg, u8 *val)
{
	int ret;
	char buf[HL7603_DSM_BUFF_SIZE] = { 0 };

	if (!di) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	ret = power_i2c_u8_read_byte(di->client, reg, val);
	if (ret) {
		snprintf_s(buf, sizeof(buf), sizeof(buf) - 1,
			"deviceID=0x%x, index=%d, fail to read 0x%x\n", di->dev_id, di->ic_role, reg);
		hwlog_info("dmd content: %s\n", buf);
		power_dsm_report_dmd(POWER_DSM_BATTERY, POWER_DSM_BYPASS_BOOST_I2C_TRANS_FAIL, buf);
	}

	return ret;
}

static int hl7603_write_mask(struct hl7603_device_info *di,
	u8 reg, u8 mask, u8 shift, u8 value)
{
	int ret;
	char buf[HL7603_DSM_BUFF_SIZE] = { 0 };

	if (!di) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	ret = power_i2c_u8_write_byte_mask(di->client, reg, value, mask, shift);
	if (ret) {
		snprintf_s(buf, sizeof(buf), sizeof(buf) - 1,
			"deviceID=0x%x, index=%d, fail to wirte to 0x%x\n", di->dev_id, di->ic_role, reg);
		hwlog_info("dmd content: %s\n", buf);
		power_dsm_report_dmd(POWER_DSM_BATTERY, POWER_DSM_BYPASS_BOOST_I2C_TRANS_FAIL, buf);
	}

	return ret;
}

static int hl7603_write_byte(struct hl7603_device_info *di, u8 reg, u8 value)
{
	int ret;
	char buf[HL7603_DSM_BUFF_SIZE] = { 0 };

	if (!di) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	ret = power_i2c_u8_write_byte(di->client, reg, value);
	if (ret) {
		snprintf_s(buf, sizeof(buf), sizeof(buf) - 1,
			"deviceID=0x%x, index=%d, fail to wirte to 0x%x\n", di->dev_id, di->ic_role, reg);
		hwlog_info("dmd content: %s\n", buf);
		power_dsm_report_dmd(POWER_DSM_BATTERY, POWER_DSM_BYPASS_BOOST_I2C_TRANS_FAIL, buf);
	}

	return ret;
}

static int hl7603_set_vout(struct hl7603_device_info *di, unsigned int vset)
{
	u8 vset_reg;

	vset_reg = (vset - HL7603_VOUT_SEL_BASE) / HL7603_VOUT_SEL_STEP;
	return hl7603_write_mask(di, HL7603_VOUT_SEL_ADDR,
		HL7603_VOUT_SEL_MASK, HL7603_VOUT_SEL_SHIFT, vset_reg);
}

static int hl7603_get_vout(struct hl7603_device_info *di, unsigned int *vol)
{
	u8 vset_reg;

	if (hl7603_read_byte(di, HL7603_VOUT_SEL_ADDR, &vset_reg))
		return -EIO;

	*vol = HL7603_VOUT_SEL_BASE + vset_reg * HL7603_VOUT_SEL_STEP;
	return 0;
}

static int hl7603_set_mode(struct hl7603_device_info *di, unsigned int mode)
{
	if ((mode < HL7603_MODE_BEGIN) || (mode >= HL7603_MODE_END)) {
		hwlog_err("mode is not valid\n");
		return -EINVAL;
	}

	if (hl7603_write_mask(di, HL7603_CONFIG_ADDR,
		HL7603_MODE_MASK, HL7603_MODE_SHIFT, mode)) {
		hwlog_err("fail to set mode\n");
		return -EIO;
	}

	hwlog_info("set device mode=%d\n", mode);
	return 0;
}

static int hl7603_get_mode(struct hl7603_device_info *di, unsigned int *mode)
{
	u8 reg_val;

	if (hl7603_read_byte(di, HL7603_CONFIG_ADDR, &reg_val)) {
		hwlog_err("fail to read config reg\n");
		return -EIO;
	}

	*mode = (reg_val & HL7603_MODE_MASK) >> HL7603_MODE_SHIFT;

	return 0;
}

static int hl7603_get_state(struct hl7603_device_info *di, u8 *state)
{
	u8 addr;

	switch (di->dev_id) {
	case HL7603_DEVID_HL:
	case HL7603_DEVID_HLR:
		addr = HL7603_STATE_ADDR_HL;
		break;
	case HL7603_DEVID_JWT:
	case HL7603_DEVID_SBW:
		addr = HL7603_STATE_ADDR_JWT;
		break;
	default:
		hwlog_err("no chip match\n");
		return -EINVAL;
	}

	if (hl7603_read_byte(di, addr, state))
		return -EIO;

	return 0;
}

static void hl7603_init_mode(struct hl7603_device_info *di)
{
	hwlog_info("init mode is %d\n", di->init_mode);
	hl7603_set_mode(di, di->init_mode);
}

static void hl7603_init_vout(struct hl7603_device_info *di)
{
	hwlog_info("init const_vout is %d\n", di->const_vout);
	hl7603_set_vout(di, di->const_vout);
}

static int hl7603_get_device_id(struct hl7603_device_info *di)
{
	int ret;
	u8 reg_val;
	int i;
	int retry_times = 3; /* retry 3 times */

	for (i = 0; i < retry_times; i++) {
		ret = hl7603_read_byte(di, HL7603_DEVID_ADDR, &reg_val);
		if (!ret)
			break;
		power_usleep(DT_USLEEP_1MS);
	}
	if (i == retry_times) {
		hwlog_err("chek chip fail\n");
		return BYPASS_BST_IC_BAD;
	}

	di->dev_id = (reg_val & HL7603_DEVID_MASK) >> HL7603_DEVID_SHIFT;
	hwlog_info("device_id is 0x%x\n", di->dev_id);
	switch (di->dev_id) {
	case HL7603_DEVID_HL:
	case HL7603_DEVID_JWT:
	case HL7603_DEVID_HLR:
	case HL7603_DEVID_SBW:
		hwlog_info("hl7603 is good\n");
		return BYPASS_BST_IC_GOOD;
	default:
		hwlog_err("no chip match, return ic bad\n");
		return BYPASS_BST_IC_BAD;
	}
}

static int hl7603_bbst_set_vout(unsigned int vout, void *dev_data)
{
	struct hl7603_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	if (vout > HL7603_VOUT_SEL_MAX)
		vout = HL7603_VOUT_SEL_MAX;

	if (vout < HL7603_VOUT_SEL_MIN)
		vout = HL7603_VOUT_SEL_MIN;

	return hl7603_set_vout(di, vout);
}

static bool hl7603_bbst_set_enable(unsigned int enable, void *dev_data)
{
	struct hl7603_device_info *di = dev_data;
	unsigned int mode;

	if (!di) {
		hwlog_err("di is null\n");
		return false;
	}

	if (!di->need_ctrl_mode)
		return true;

	mode = enable ? HL7603_MODE_AUTO_BYPASS : HL7603_MODE_FORCE_BYPASS;

	return !hl7603_set_mode(di, mode);
}

static bool hl7603_is_power_good(u8 state)
{
	return state & BIT(0);
}

static bool hl7603_is_fault(u8 state)
{
	return state & HL7603_ABNORMAL_STATE_MASK;
}

static int hl7603_get_vout_adc(int *value, void *dev_data)
{
	struct hl7603_device_info *di = dev_data;
	int raw_data;

	if (!di || di->adc_channel == HL7603_ADC_CHANNEL_NONE)
		return -EINVAL;

	raw_data = power_platform_get_adc_voltage(di->adc_channel);
	*value = raw_data * di->adc_coef / HL7603_ADC_UNIT;
	return 0;
}

static void hl7603_monitor_state(void *dev_data)
{
	u8 state = 0;
	int vout_adc = 0;
	char buf[HL7603_DSM_BUFF_SIZE] = { 0 };
	struct hl7603_device_info *di = dev_data;

	if (!di)
		return;

	if (hl7603_get_state(di, &state))
		return;

	hl7603_get_vout_adc(&vout_adc, dev_data);
	snprintf_s(buf, sizeof(buf), sizeof(buf) - 1, "deviceID=0x%x, index=%d, state=0x%x, vout=%d\n",
		di->dev_id, di->ic_role, state, vout_adc);
	hwlog_info("%s:%s", __func__, buf);
	if (hl7603_is_fault(state)) {
		power_dsm_report_dmd(POWER_DSM_BATTERY, POWER_DSM_BYASS_BOOST_FAULT, buf);
		if (hl7603_is_power_good(state)) {
			power_event_bnc_notify(POWER_BNT_BYPASSBOOST,
				POWER_NE_BYPASSBOOST_RECOVERY, &di->ic_role);
			di->status = HL7603_STATUS_POWER_GOOD;
			return;
		}
		if (di->status == HL7603_STATUS_POWER_GOOD) {
			di->status = HL7603_STATUS_FAULT;
			power_event_bnc_notify(POWER_BNT_BYPASSBOOST,
				POWER_NE_BYPASSBOOST_FAULT, &di->ic_role);
		}
	}
}

static struct buck_boost_ops hl7603_ops = {
	.set_vout = hl7603_bbst_set_vout,
	/* hl7603 set enable means switch mode */
	.set_enable = hl7603_bbst_set_enable,
	.monitor_state = hl7603_monitor_state,
};

static void hl7603_parse_dts(struct device_node *np,
	struct hl7603_device_info *di)
{
	(void)power_dts_read_str2int(power_dts_tag(HWLOG_TAG), np,
		"ic_role", &di->ic_role, -1);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"const_vout", &di->const_vout, HL7603_VOUT_SEL_DEFAULT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"init_mode", &di->init_mode, HL7603_MODE_AUTO_BYPASS);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"need_ctrl_mode", &di->need_ctrl_mode, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"shutdown_boost", &di->shutdown_boost, 1);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"adc_channel", &di->adc_channel, HL7603_ADC_CHANNEL_NONE);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"adc_coef", &di->adc_coef, 1);
	(void)power_gpio_config_output(np,
		"gpio_enable", "gpio_enable", &di->gpio_no, 1);
}

#ifdef CONFIG_HUAWEI_POWER_DEBUG
static ssize_t hl7603_dbg_vout_show(void *dev_data, char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	unsigned int vout = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}
	if (hl7603_get_vout(di, &vout))
		return scnprintf(buf, size, "fail to get vout\n");

	return scnprintf(buf, size, "hl7603 vout=%u\n", vout);
}

static ssize_t hl7603_dbg_vout_store(void *dev_data, const char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	unsigned int vout = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (sscanf_s(buf, "%u", &vout) != 1) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	hl7603_set_vout(di, vout);
	return size;
}

static ssize_t hl7603_dbg_mode_show(void *dev_data, char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	unsigned int mode = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}
	if (hl7603_get_mode(di, &mode))
		return scnprintf(buf, size, "fail to get mode\n");

	return scnprintf(buf, size, "hl7603 mode=%u\n", mode);
}

static ssize_t hl7603_dbg_mode_store(void *dev_data, const char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	unsigned int mode = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (sscanf_s(buf, "%u", &mode) != 1) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	hl7603_set_mode(di, mode);
	return size;
}

static ssize_t hl7603_dbg_state_show(void *dev_data, char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	u8 state = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}
	if (hl7603_get_state(di, &state))
		return scnprintf(buf, size, "fail to get mode\n");

	return scnprintf(buf, size, "hl7603 state reg=0x%x\n", state);
}

static ssize_t hl7603_dbg_reg_store(void *dev_data, const char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	u8 reg_val = 0;
	u8 addr = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	if (sscanf_s(buf, "0x%x 0x%x", &addr, &reg_val) != 2) {
		hwlog_err("%s sscanf_s failed\n", __func__);
		return -EINVAL;
	}

	hl7603_write_byte(di, addr, reg_val);
	return size;
}

static ssize_t hl7603_dbg_dump_show(void *dev_data, char *buf, size_t size)
{
	struct hl7603_device_info *di = dev_data;
	u8 reg_val = 0;
	u8 addr = 0;
	int ret = 0;
	int len;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	for (addr = 0; addr <= HL7603_MAX_REG_ADDR; addr++) {
		if (hl7603_read_byte(di, addr, &reg_val))
			reg_val = -EPERM;
		len = scnprintf(buf + ret, size, "reg[0x%x]:0x%x\n", addr, reg_val);
		if (len < 0)
			return ret;
		ret += len;
	}

	return ret;
}

static ssize_t hl7603_dbg_vout_adc_show(void *dev_data, char *buf, size_t size)
{
	int value = 0;

	if (!buf || !dev_data) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}
	if (hl7603_get_vout_adc(&value, dev_data))
		return scnprintf(buf, size, "fail to get vout from adc\n");

	return scnprintf(buf, size, "hl7603 adc vout=%d\n", value);
}
#endif /* CONFIG_HUAWEI_POWER_DEBUG */

static void hl7603_register_power_debug(struct hl7603_device_info *di)
{
#ifdef CONFIG_HUAWEI_POWER_DEBUG
	char name[HL7603_DBG_NAME_LEN];
	snprintf_s(name, HL7603_DBG_NAME_LEN, HL7603_DBG_NAME_LEN - 1,
		"hl7603_%d", di->ic_role);
	power_dbg_ops_register(name, "vout", di,
		hl7603_dbg_vout_show, hl7603_dbg_vout_store);
	power_dbg_ops_register(name, "mode", di,
		hl7603_dbg_mode_show, hl7603_dbg_mode_store);
	power_dbg_ops_register(name, "state", di,
		hl7603_dbg_state_show, NULL);
	power_dbg_ops_register(name, "set_reg", di,
		NULL, hl7603_dbg_reg_store);
	power_dbg_ops_register(name, "dump", di,
		hl7603_dbg_dump_show, NULL);
	power_dbg_ops_register(name, "vout_adc", di,
		hl7603_dbg_vout_adc_show, NULL);
#endif /* CONFIG_HUAWEI_POWER_DEBUG */
}

static void hl7603_shutdown(struct i2c_client *client)
{
	struct hl7603_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return;

	if (di->dev_id == HL7603_DEVID_HL && di->shutdown_boost) {
		hl7603_set_vout(di, HL7603_SHUTDOWN_SET_VEL);
		power_msleep(HL7603_SHUTDOWN_DELAY_MS, 0, NULL);
	}

	hl7603_set_mode(di, HL7603_MODE_FORCE_BYPASS);
}

static int hl7603_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	int ret;
	struct device_node *np = NULL;
	struct hl7603_device_info *di = NULL;
	struct power_devices_info_data *power_dev_info = NULL;

	if (!client || !client->dev.of_node || !id)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;

	hl7603_parse_dts(np, di);
	ret = hl7603_get_device_id(di);
	if (ret != BYPASS_BST_IC_GOOD)
		goto get_devid_fail;
	if (di->ic_role >= 0) {
		memcpy(&di->bbst_ops, &hl7603_ops, sizeof(struct buck_boost_ops));
		di->bbst_ops.dev_data = (void *)di;
		di->bbst_ops.index = di->ic_role;
		buck_boost_ops_register(&di->bbst_ops);
		hl7603_register_power_debug(di);
	}
	power_dev_info = power_devices_info_register();
	if (power_dev_info) {
		power_dev_info->dev_name = di->dev->driver->name;
		power_dev_info->dev_id = di->dev_id;
		power_dev_info->ver_id = 0;
	}

	hl7603_init_mode(di);
	hl7603_init_vout(di);
	i2c_set_clientdata(client, di);
	return 0;

get_devid_fail:
	devm_kfree(&client->dev, di);
	return -EINVAL;
}

static int hl7603_remove(struct i2c_client *client)
{
	struct hl7603_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	i2c_set_clientdata(client, NULL);
	return 0;
}

MODULE_DEVICE_TABLE(i2c, bypass_bst_hl7603);
static const struct of_device_id hl7603_of_match[] = {
	{
		.compatible = "huawei,bypass_bst_hl7603",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id hl7603_i2c_id[] = {
	{ "bypass_bst_hl7603", 0 },
	{},
};

static struct i2c_driver hl7603_driver = {
	.probe = hl7603_probe,
	.remove = hl7603_remove,
	.id_table = hl7603_i2c_id,
	.shutdown = hl7603_shutdown,
	.driver = {
		.owner = THIS_MODULE,
		.name = "bypass_bst_hl7603",
		.of_match_table = of_match_ptr(hl7603_of_match),
	},
};

static int __init hl7603_init(void)
{
	return i2c_add_driver(&hl7603_driver);
}

static void __exit hl7603_exit(void)
{
	i2c_del_driver(&hl7603_driver);
}

fs_initcall_sync(hl7603_init);
module_exit(hl7603_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("hl7603 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");