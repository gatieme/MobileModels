// SPDX-License-Identifier: GPL-2.0
/*
 * sc8726.c
 *
 * sc8726 boost driver
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

#include "sc8726.h"
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_pd.h>
#include <securec.h>

#define HWLOG_TAG sc8726
HWLOG_REGIST();

int sc8726_write_byte(struct sc8726_device_info *di, u8 reg, u8 value)
{
	int ret;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -ENODEV;
	}

	ret = power_i2c_u8_write_byte(di->client, reg, value);

	return ret;
}

int sc8726_read_byte(struct sc8726_device_info *di, u8 reg, u8 *value)
{
	int ret;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -ENODEV;
	}

	ret = power_i2c_u8_read_byte(di->client, reg, value);

	return ret;
}

int sc8726_write_mask(struct sc8726_device_info *di, u8 reg, u8 mask, u8 shift, u8 value)
{
	int ret;
	u8 val = 0;

	ret = sc8726_read_byte(di, reg, &val);
	if (ret < 0)
		return ret;

	val &= ~mask;
	val |= ((value << shift) & mask);

	return sc8726_write_byte(di, reg, val);
}

static int sc8726_set_vcg_on(void *dev_data, int enable)
{
	struct sc8726_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	gpio_direction_output(di->pwrbank_en, enable);
	return 0;
}

/* pull up CE */
static int sc8726_set_idle_mode(void *dev_data, int mode)
{
	struct sc8726_device_info *di = dev_data;
	int ret;

	if (!di)
		return -ENODEV;

	di->in_sleep = mode;
	ret = gpio_direction_output(di->boost_en, !mode);
	(void)power_msleep(DT_MSLEEP_20MS, 0, NULL);

	hwlog_info("set idle mode:%d\n", !mode);
	return ret;
}

static int sc8726_set_vbus_mv(void *dev_data, int vbus)
{
	int ret;
	s16 offset = 0;
	u8 fb_dir = 0;
	u8 flag[2] = { 0 }; /* 2: two regs */
	u8 vout_set_value = 0;
	struct sc8726_device_info *di = dev_data;

	if (!di || (vbus <= 0))
		return -EINVAL;

	vbus += di->vbus_comp;
	if (vbus < SC8726_VBUS_BASE) {
		fb_dir = 1;
		offset = (SC8726_VBUS_BASE - vbus) / SC8726_VBUS_LSB;
	} else {
		fb_dir = 0;
		offset = (vbus - SC8726_VBUS_BASE) / SC8726_VBUS_LSB;
	}

	vout_set_value |= (offset & SC8726_VBUS_SET_LSB_MASK);
	vout_set_value |= ((fb_dir << SC8726_FB_DIR_SHIFT) & SC8726_FB_DIR_MASK);
	vout_set_value |= ((1 << SC8726_FB_ON_SHIFT) & SC8726_FB_ON_MASK);
	vout_set_value |= ((1 << SC8726_FB_SEL_SHIFT) & SC8726_FB_SEL_MASK);

	ret = sc8726_write_byte(di, SC8726_VBUS_SET_MSB_REG,
		(offset >> SC8726_VBUS_LOW_BITS) & SC8726_VBUS_SET_MSB_MASK);
	ret += sc8726_write_byte(di, SC8726_VOUT_SET_REG, vout_set_value);
	ret += sc8726_write_mask(di, SC8726_GLOBAL_CTRL_REG,
		SC8726_LOAD_MASK, SC8726_LOAD_SHIFT,
		SC8726_LOAD_ENABLE);
	if (ret)
		return -ENODEV;

	(void)sc8726_read_byte(di, SC8726_VBUS_SET_MSB_REG, &flag[0]);
	(void)sc8726_read_byte(di, SC8726_VOUT_SET_REG, &flag[1]);
	hwlog_info("%s: reg[0x%x]=0x%x reg[0x%x]=0x%x\n", __func__,
		SC8726_VBUS_SET_MSB_REG, flag[0], SC8726_VOUT_SET_REG, flag[1]);

	return 0;
}

static int sc8726_set_ibus_ma(void *dev_data, int ibus)
{
	int ret;
	u8 flag = 0;
	u8 cso_set = 0;
	struct sc8726_device_info *di = dev_data;

	if (!di || (ibus <= 0))
		return -EINVAL;

	/* iout_ilmit = ((cso_set+1) * 4mV * 2k¦¸) / (rs *  rcso) */
	cso_set = ibus * di->r_sensor_mohm * di->r_cso_kohm / 8000 + 1;
	ret = sc8726_write_byte(di, SC8726_CSO_SET_REG, cso_set);
	ret += sc8726_write_mask(di, SC8726_GLOBAL_CTRL_REG,
		SC8726_LOAD_MASK, SC8726_LOAD_SHIFT,
		SC8726_LOAD_ENABLE);
	if (ret)
		return -ENODEV;

	(void)sc8726_read_byte(di, SC8726_CSO_SET_REG, &flag);
	hwlog_info("%s:reg[0x%x]=0x%x\n", __func__, SC8726_CSO_SET_REG, flag);

	return 0;
}

static int sc8726_ic_enable(void *dev_data, int enable)
{
	int ret = 0;
	struct sc8726_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	return ret;
}

static int sc8726_enable_reverse_9v_pd_charge(bool enable, void *dev_data)
{
	struct sc8726_device_info *di = dev_data;
	int ret;

	if (!di)
		return -EPERM;

	if (enable) {
		ret = sc8726_set_vbus_mv(di, SC8726_REVERSE_9V);
		ret += sc8726_set_ibus_ma(di, SC8726_REVERSE_2A);
	} else {
		ret = sc8726_set_vbus_mv(di, SC8726_REVERSE_5V);
		ret += sc8726_set_ibus_ma(di, SC8726_REVERSE_3A);
	}

	return ret;
}

static struct rchg_pd_ic_ops sc8726_rc_pd_ops = {
	.dev_name = "sc8726",
	.enable_reverse_charge = sc8726_enable_reverse_9v_pd_charge,
};

/* print the register head in charging process */
static int sc8726_register_head(char *buffer, int size, void *dev_data)
{
	char tmp_buff[BUF_LEN] = {0};
	int i;
	int ret;

	if (!buffer)
		return -ENODEV;

	snprintf_s(tmp_buff, BUF_LEN, BUF_LEN, "chip      ");
	if (strncat_s(buffer, BUF_LEN-1, tmp_buff, strlen(tmp_buff)))
		hwlog_err("strncat_s fail\n");
	for (i = 0; i < SC8726_REG_NUM; i++) {
		snprintf_s(tmp_buff, BUF_LEN, BUF_LEN, "R[0x%02x]  ", i + 1);
		if (strncat_s(buffer, BUF_LEN-1, tmp_buff, strlen(tmp_buff)))
			hwlog_err("strncat_s fail\n");
	}

	return 0;
}

/* print the register value in charging process */
static int sc8726_dump_reg(char *buffer, int size, void *dev_data)
{
	struct sc8726_device_info *di = dev_data;
	u8 reg[SC8726_REG_NUM] = {0};
	char tmp_buff[BUF_LEN] = {0};
	int i;
	int ret;

	if (!buffer || !di || di->in_sleep)
		return -ENODEV;

	snprintf_s(tmp_buff, BUF_LEN, BUF_LEN, "%-10s", di->name);
	if (strncat_s(buffer, BUF_LEN-1, tmp_buff, strlen(tmp_buff)))
		hwlog_err("strncat_s fail\n");
	for (i = 0; i < SC8726_REG_NUM; i++) {
		ret = sc8726_read_byte(di, i + 1, &reg[i]);
		if (ret)
			hwlog_err("dump_register read fail\n");

		snprintf_s(tmp_buff, BUF_LEN, BUF_LEN, "0x%-7.2x", reg[i]);
		if (strncat_s(buffer, BUF_LEN-1, tmp_buff, strlen(tmp_buff)))
			hwlog_err("strncat_s fail\n");
	}

	return 0;
}

static struct boost_ops g_sc8726_boost_ops = {
	.chip_name = "sc8726",
	.set_vcg_on = sc8726_set_vcg_on,
	.set_vbus = sc8726_set_vbus_mv,
	.set_ibus = sc8726_set_ibus_ma,
	.ic_enable = sc8726_ic_enable,
	.set_idle_mode = sc8726_set_idle_mode,
};

static struct power_log_ops g_sc8726_log_ops = {
	.dev_name = "sc8726",
	.dump_log_head = sc8726_register_head,
	.dump_log_content = sc8726_dump_reg,
};

static void sc8726_init_ops_dev_data(struct sc8726_device_info *di)
{
	memcpy_s(&di->bst_ops, sizeof(struct boost_ops), &g_sc8726_boost_ops, sizeof(struct boost_ops));
	di->bst_ops.dev_data = (void *)di;
	memcpy_s(&di->log_ops, sizeof(struct power_log_ops), &g_sc8726_log_ops, sizeof(struct power_log_ops));
	di->log_ops.dev_data = (void *)di;
	snprintf_s(di->name, CHIP_DEV_NAME_LEN, CHIP_DEV_NAME_LEN, "sc8726");
}

static void sc8726_ops_register(struct sc8726_device_info *di)
{
	int ret;

	sc8726_init_ops_dev_data(di);

	ret = boost_ops_register(&di->bst_ops);
	ret += power_log_ops_register(&di->log_ops);
	if (ret)
		hwlog_err("sc8726 ops register fail\n");
}

static void sc8726_parse_dts(struct device_node *np,
	struct sc8726_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "vbus_comp",
		&di->vbus_comp, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "r_sensor_mohm",
		&di->r_sensor_mohm, SC8726_R_SENSE_MOHM);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "r_cso_kohm",
		&di->r_cso_kohm, SC8726_R_CSO_KOHM);
	(void)power_gpio_config_output(np, "boost_en", "sc8726_boost_en",
		&di->boost_en, 0);
	(void)power_gpio_config_output(np, "pwrbank_en", "sc8726_pwrbank_en",
		&di->pwrbank_en, 0);
}

static int sc8726_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct sc8726_device_info *di = NULL;
	struct device_node *np = NULL;

	if (!client || !client->dev.of_node || !id)
		return -ENODEV;

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;
	di->chip_already_init = 1;

	sc8726_parse_dts(np, di);

	sc8726_ops_register(di);
	sc8726_rc_pd_ops.dev_data = (void *)di;
	(void)rchg_pd_ops_register(&sc8726_rc_pd_ops);
	i2c_set_clientdata(client, di);
	hwlog_info("%s success\n", __func__);
	return 0;
}

static int sc8726_remove(struct i2c_client *client)
{
	struct sc8726_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return -ENODEV;

	return 0;
}

static void sc8726_shutdown(struct i2c_client *client)
{
	struct sc8726_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return;

	sc8726_set_idle_mode(di, SC8726_IDLE_STATE);
}

#ifdef CONFIG_PM
static int sc8726_i2c_suspend(struct device *dev)
{
	return 0;
}

static int sc8726_i2c_resume(struct device *dev)
{
	return 0;
}

static const struct dev_pm_ops sc8726_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(sc8726_i2c_suspend, sc8726_i2c_resume)
};
#define SC8726_PM_OPS (&sc8726_pm_ops)
#else
#define SC8726_PM_OPS (NULL)
#endif /* CONFIG_PM */

MODULE_DEVICE_TABLE(i2c, sc8726);
static const struct of_device_id sc8726_of_match[] = {
	{
		.compatible = "sc8726",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id sc8726_i2c_id[] = {
	{ "sc8726", 0 }, {}
};

static struct i2c_driver sc8726_driver = {
	.probe = sc8726_probe,
	.remove = sc8726_remove,
	.shutdown = sc8726_shutdown,
	.id_table = sc8726_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "sc8726",
		.of_match_table = of_match_ptr(sc8726_of_match),
		.pm = SC8726_PM_OPS,
	},
};

static int __init sc8726_init(void)
{
	return i2c_add_driver(&sc8726_driver);
}

static void __exit sc8726_exit(void)
{
	i2c_del_driver(&sc8726_driver);
}

module_init(sc8726_init);
module_exit(sc8726_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("sc8726 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
