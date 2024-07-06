// SPDX-License-Identifier: GPL-2.0
/*
 * bq40z50.c
 *
 * bq40z50 driver
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#include "bq40z50.h"
#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <chipset_common/hwmanufac/dev_detect/dev_detect.h>
#endif
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#ifdef CONFIG_HUAWEI_DSM
#include <log/hiview_hievent.h>
#endif

#define HWLOG_TAG bq40z50
HWLOG_REGIST();

int bq40z50_read_byte(struct bq40z50_device_info *di, u8 reg, u8 *value)
{
	if (!di) {
		hwlog_err("chip not init\n");
		return -ENODEV;
	}

	return power_i2c_u8_read_byte(di->client, reg, value);
}

int bq40z50_write_byte(struct bq40z50_device_info *di, u8 reg, u8 value)
{
	if (!di) {
		hwlog_err("chip not init\n");
		return -ENODEV;
	}

	return power_i2c_u8_write_byte(di->client, reg, value);
}

int bq40z50_read_word(struct bq40z50_device_info *di, u8 reg, u16 *data)
{
	int ret;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->rw_lock);
	ret = power_i2c_u8_read_word(di->client, reg, data, false);
	mutex_unlock(&di->rw_lock);
	if (ret < 0)
		hwlog_err("reg=0x%x read fail\n", reg);

	return ret;
}

int bq40z50_write_word(struct bq40z50_device_info *di, u8 reg, u16 data)
{
	int ret;

	if (!di)
		return -ENODEV;

	mutex_lock(&di->rw_lock);
	ret = power_i2c_u8_write_word(di->client, reg, data);
	mutex_unlock(&di->rw_lock);
	if (ret < 0)
		hwlog_err("reg=0x%x write fail\n", reg);

	return ret;
}

int bq40z50_read_block(struct bq40z50_device_info *di, u8 reg, u8 *buf, u8 buf_len)
{
	int ret;
	u8 cmd[BQ40Z50_CMD_LEN] = { 0 };

	if (!di)
		return -ENODEV;

	cmd[0] = reg;
	mutex_lock(&di->rw_lock);
	ret = power_i2c_read_block(di->client, cmd, sizeof(cmd), buf, buf_len);
	mutex_unlock(&di->rw_lock);
	if (ret < 0)
		hwlog_err("reg=0x%x read block fail\n", reg);

	return ret;
}

int bq40z50_write_block(struct bq40z50_device_info *di, u8 reg, u8 *buf, u8 buf_len)
{
	int ret;
	u8 *cmd = NULL;

	if (!di || !buf || (buf_len > BQ40Z50_BLOCK_LEN_MAX))
		return -EINVAL;

	cmd = kcalloc(BQ40Z50_CMD_LEN + buf_len, sizeof(u8), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd[0] = reg;
	memcpy(&cmd[BQ40Z50_CMD_LEN], buf, buf_len);

	mutex_lock(&di->rw_lock);
	ret = power_i2c_write_block(di->client, cmd, BQ40Z50_CMD_LEN + buf_len);
	mutex_unlock(&di->rw_lock);
	if (ret < 0)
		hwlog_err("reg=0x%x write block fail\n", reg);
	kfree(cmd);

	return ret;
}

static int bq40z50_get_batt_para(struct bq40z50_device_info *di)
{
	if (!di)
		return -ENODEV;

	/* vbat_max */
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"vbat_max", (u32 *)&di->vbat_max, BQ40Z50_BATT_MAX_VOLTAGE_DEFAULT);

	/* cell count */
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"cell_count", (u32 *)&di->cell_count, BQ40Z50_BATT_CELL_COUNT_DEFAULT);

#if defined(CONFIG_COUL_DRV)
	/* smart charge support */
	(void)power_dts_read_u32_compatible(power_dts_tag(HWLOG_TAG),
		"bq40z50_battery", "is_smart_battery", &di->is_smart_battery, true);

	/* prevent low cap */
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"prevent_low_cap", (u32 *)&di->prevent_low_cap, 0);

	/* cutoff vol */
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"cutoff_vol", (u32 *)&di->cutoff_vol, BQ40Z50_CUTOFF_VOL_DEFAULT);

	/* is using 2:1 converter */
	di->use_converter = of_property_read_bool(di->dev->of_node, "use_converter");

	/* soc jump calibrate */
	di->soc_cali_enable = of_property_read_bool(di->dev->of_node, "soc_cali_enable");

	return bq40z50_get_para_data(di);
#elif defined(CONFIG_HUAWEI_COUL)
	/* smart charge support */
	di->is_smart_battery = of_property_read_bool(di->dev->of_node, "is_smart_battery");

	return 0;
#endif
}

struct battery_dev_name_table {
	char *name;
	int battery_fuel_id;
};

static struct battery_dev_name_table battery_dev_tab[] = {
	{"21T1", BATTERY_FUEL_BQ40Z50},
	{"21S1", BATTERY_FUEL_SH366006},
};

static int bq40z50_check_chip(struct bq40z50_device_info *di)
{
	char device_name[BQ40Z50_BLOCK_LEN_MAX] = {0};
	int ret;
	int i = 0;
	int retry = BQ40Z50_RETRY_COUNT;

	while (retry--) {
		ret = bq40z50_read_block(di, BQ40Z50_REG_DEVICE_NAME, device_name, BQ40Z50_BLOCK_LEN_MAX);
		if (!ret)
			break;
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}
	if (ret != 0) {
		hwlog_err("read device name 3 times fail\n");
		return ret;
	}
	hwlog_info("device name : %s\n", device_name);
	for (i = 0; i < ARRAY_SIZE(battery_dev_tab); i++) {
		if (strstr(device_name, battery_dev_tab[i].name)) {
			di->device_id = battery_dev_tab[i].battery_fuel_id;
			return 0;
		}
	}
	di->device_id = BATTERY_FUEL_INVALID;
	hwlog_err("device name not match\n");

	return ret;
}

static int bq40z50_ops_register(struct bq40z50_device_info *di)
{
#if defined(CONFIG_COUL_DRV)
	return bq40z50_ops_register_hisi(di);
#elif defined(CONFIG_HUAWEI_COUL)
	return bq40z50_ops_register_base(di);
#endif
}

#ifdef CONFIG_HUAWEI_DSM
static void bq40z50_report_ocv_upgrade_status(int result_code)
{
	int ret;
	struct hiview_hievent *hi_event = NULL;

	hi_event = hiview_hievent_create(BQ40Z50_OCV_UPGRADE_DMD_REPORT_ID);
	if (hi_event == NULL) {
		hwlog_err("%s create hievent fail\n", __func__);
		return;
	}

	ret = hiview_hievent_put_integral(hi_event, "update_result", result_code);
	if (ret < 0)
		hwlog_err("%s put integral fail ret_put=%d\n", __func__, ret);

	ret = hiview_hievent_report(hi_event);
	if (ret < 0)
		hwlog_err("%s report fail ret=%d\n", __func__, ret);

	hiview_hievent_destroy(hi_event);
}
#endif

static int bq40z50_read_sub_cmd(struct bq40z50_device_info *di, u16 sub_cmd, u8 *data, int data_size)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_LEN,
		(u8)(sub_cmd & BQ40Z50_SUB_CMD_SING_BYTE_MASK),
		(u8)(sub_cmd >> BQ40Z50_SUB_CMD_SING_BYTE_LEN) };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_SIZE);
		if (ret) {
			hwlog_err("%s write command 0x%x fail\n", __func__, sub_cmd);
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		ret = bq40z50_read_block(di, BQ40Z50_REG_CTL, data, data_size);
		if (!ret)
			return 0;
		hwlog_err("%s read command 0x%x fail\n", __func__, sub_cmd);
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("%s read command 0x%x %d times fail\n", __func__, sub_cmd, BQ40Z50_RETRY_COUNT);
	return ret;
}

static bool bq40z50_check_seal_status(struct bq40z50_device_info *di, u8 status)
{
	u8 seal_status;
	u8 data[BQ40Z50_SUB_CMD_READ_STATUS_BLOCK_LEN] = { 0 };

	if (bq40z50_read_sub_cmd(di, BQ40Z50_SUB_CMD_OP_STATUS, data, BQ40Z50_SUB_CMD_READ_STATUS_BLOCK_LEN))
		return false;
	seal_status = data[BQ40Z50_SUB_CMD_READ_SEAL_STATUS_INDEX] & BQ40Z50_SUB_CMD_READ_SEAL_STATUS_BIT_SCOPE;
	hwlog_info("%s gauge seal status=0x%x\n", __func__, seal_status);
	return (seal_status == status);
}

static u8 bq40z50_get_version(struct bq40z50_device_info *di)
{
	u8 version;
	u8 data[BQ40Z50_SUB_CMD_READ_BLOCK_LEN_MAX] = { 0 };

	if (bq40z50_read_sub_cmd(di, BQ40Z50_SUB_CMD_MFI, data, BQ40Z50_SUB_CMD_READ_BLOCK_LEN_MAX))
		return BQ40Z50_GAUGE_VERSION_INVALID;

	version = data[BQ40Z50_SUB_CMD_READ_VERSION_INDEX];
	hwlog_info("%s gauge version=0x%x\n", __func__, version);
	return version;
}

static bool bq40z50_check_version(struct bq40z50_device_info *di)
{
	u8 version = bq40z50_get_version(di);

	return ((version >= BQ40Z50_GAUGE_VERSION_BEFORE_MIN) && (version <= BQ40Z50_GAUGE_VERSION_BEFORE_MAX));
}

static int bq40z50_batt_unseal(struct bq40z50_device_info *di, u16 pwd1, u16 pwd2)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;

	while (retry--) {
		ret = bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND, pwd1);
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND, pwd2);
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND, BQ40Z50_GAUGE_ALL_UNSEAL_FIRST_SENT_PWD);
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND, BQ40Z50_GAUGE_ALL_UNSEAL_SECOND_SENT_PWD);
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		if (ret) {
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}

		if (bq40z50_check_seal_status(di, BQ40Z50_GAUGE_BATT_UNSEAL_STATUS)) {
			hwlog_info("%s batt unseal success\n", __func__);
			return 0;
		}
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("%s batt unseal %d times fail\n", __func__, BQ40Z50_RETRY_COUNT);
	return -EIO;
}

static int bq40z50_batt_seal(struct bq40z50_device_info *di)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_LEN, BQ40Z50_REG_LOCK, 0x00 };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_SIZE);
		if (ret) {
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		if (bq40z50_check_seal_status(di, BQ40Z50_GAUGE_BATT_SEAL_STATUS)) {
			hwlog_info("%s batt lock success\n", __func__);
			return 0;
		}
		power_msleep(DT_MSLEEP_10MS, 0, NULL);
	}

	hwlog_err("%s batt lock %d times fail\n", __func__, BQ40Z50_RETRY_COUNT);
	return -EIO;
}

static int bq40z50_update_ocv_param(struct bq40z50_device_info *di, u16 sub_cmd, u16 update_data)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 data[BQ40Z50_SUB_CMD_READ_BLOCK_LEN_MAX] = { 0 };
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_OCV_PARAM_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_OCV_PARAM_LEN,
		(u8)(sub_cmd & BQ40Z50_SUB_CMD_SING_BYTE_MASK),
		(u8)(sub_cmd >> BQ40Z50_SUB_CMD_SING_BYTE_LEN),
		(u8)(update_data & BQ40Z50_SUB_CMD_SING_BYTE_MASK),
		(u8)(update_data >> BQ40Z50_SUB_CMD_SING_BYTE_LEN) };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_OCV_PARAM_SIZE);
		if (ret) {
			hwlog_err("%s sub command 0x%x update ocv param=0x%x fail\n", __func__, sub_cmd, update_data);
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		if (bq40z50_read_sub_cmd(di, sub_cmd, data, BQ40Z50_SUB_CMD_READ_BLOCK_LEN_MAX)) {
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		if (data[BQ40Z50_SUB_CMD_READ_OCV_PARAM_FIRST_INDEX] == (u8)(update_data & BQ40Z50_SUB_CMD_SING_BYTE_MASK) &&
			data[BQ40Z50_SUB_CMD_READ_OCV_PARAM_SECOND_INDEX] == (u8)(update_data >> BQ40Z50_SUB_CMD_SING_BYTE_LEN)) {
			hwlog_info("%s sub command 0x%x update ocv param=0x%x success\n", __func__, sub_cmd, update_data);
			return 0;
		}
	}

	hwlog_err("%s sub commond 0x%x update ocv param:0x%x %d times fail\n",
		__func__, sub_cmd, update_data, BQ40Z50_RETRY_COUNT);
	return -EIO;
}

static int bq40z50_update_version(struct bq40z50_device_info *di, u16 sub_cmd, u8 version)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_VERSION_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_VERSION_LEN,
		(u8)(sub_cmd & BQ40Z50_SUB_CMD_SING_BYTE_MASK),
		(u8)(sub_cmd >> BQ40Z50_SUB_CMD_SING_BYTE_LEN),
		version };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_VERSION_SIZE);
		if (ret) {
			hwlog_err("%s sub command 0x%x update version:0x%x fail\n", __func__, sub_cmd, version);
			power_msleep(DT_MSLEEP_10MS, 0, NULL);
			continue;
		}
		power_msleep(DT_MSLEEP_100MS, 0, NULL);
		if (bq40z50_get_version(di) == version) {
			hwlog_info("%s sub command 0x%x update version:0x%x success\n", __func__, sub_cmd, version);
			return 0;
		}
	}

	hwlog_err("%s update version=0x%x %d times fail\n", __func__, version, BQ40Z50_RETRY_COUNT);
	return -EIO;
}

static void bq40z50_delay_report_upgarde_result_work(struct work_struct *work)
{
	struct bq40z50_device_info *di = container_of(work, struct bq40z50_device_info, ocv_update_work.work);

	if (!di)
		return;

	hwlog_info("%s enter\n", __func__);

#ifdef CONFIG_HUAWEI_DSM
	bq40z50_report_ocv_upgrade_status(di->ocv_upgrade_result);
#endif

	hwlog_info("%s end\n", __func__);
}

static void bq40z50_update_gauge_info(struct bq40z50_device_info *di)
{
	int ret;

	if (di->device_id != BATTERY_FUEL_BQ40Z50) {
		hwlog_info("%s device name not match\n", __func__);
		return;
	}

	if (!bq40z50_check_version(di)) {
		di->ocv_upgrade_result = BQ40Z50_OCV_UPGRADE_SUCCESS_STATUS;
		schedule_delayed_work(&di->ocv_update_work, msecs_to_jiffies(BQ40Z50_OCV_UPGRADE_DMD_DELAY_REPORT_TIME60S));
		hwlog_info("%s gauge version not match\n", __func__);
		return;
	}

	if (!bq40z50_check_seal_status(di, BQ40Z50_GAUGE_BATT_SEAL_STATUS)) {
		hwlog_info("%s check batt is not lock status\n", __func__);
		return;
	}

	di->ocv_upgrade_result = BQ40Z50_OCV_UPGRADE_FAIL_STATUS;
	ret = bq40z50_batt_unseal(
		di, BQ40Z50_GAUGE_MASS_PART_UNSEAL_FIRST_SENT_PWD, BQ40Z50_GAUGE_MASS_PART_UNSEAL_SECOND_SENT_PWD);
	if (ret) {
		power_msleep(DT_MSLEEP_1S, 0, NULL);
		ret = bq40z50_batt_unseal(
			di, BQ40Z50_GAUGE_TRIAL_PART_UNSEAL_FIRST_SENT_PWD, BQ40Z50_GAUGE_TRIAL_PART_UNSEAL_SECOND_SENT_PWD);
		if (ret)
			goto bq40z50_report_ocv_upgrade_result;
	}

	ret = bq40z50_update_ocv_param(di, BQ40Z50_SUB_CMD_QC, BQ40Z50_SUB_CMD_QC_PARAM);
	ret += bq40z50_update_ocv_param(di, BQ40Z50_SUB_CMD_DCT, BQ40Z50_SUB_CMD_DCT_PARAM);
	ret += bq40z50_update_ocv_param(di, BQ40Z50_SUB_CMD_OUT, BQ40Z50_SUB_CMD_OUT_PARAM);
	if (!ret)
		ret += bq40z50_update_version(di, BQ40Z50_SUB_CMD_VERSION, BQ40Z50_GAUGE_VERSION_AFTER);

	ret += bq40z50_batt_seal(di);
	if (!ret)
		di->ocv_upgrade_result = BQ40Z50_OCV_UPGRADE_SUCCESS_STATUS;

bq40z50_report_ocv_upgrade_result:
	hwlog_info("%s gauge info update status: %d\n", __func__, di->ocv_upgrade_result);
	schedule_delayed_work(&di->ocv_update_work, msecs_to_jiffies(BQ40Z50_OCV_UPGRADE_DMD_DELAY_REPORT_TIME60S));
}

static int bq40z50_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret = -ENOMEM;
	struct bq40z50_device_info *di = NULL;
	struct device_node *np = NULL;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return ret;

	di->cache.vol = BQ40Z50_BATT_VOLTAGE_DEFAULT;
	di->cache.temp = BQ40Z50_BATT_TEMP_ABNORMAL_LOW - 1;
	di->cache.soc = BQ40Z50_BATT_CAPACITY_DEFAULT;
	di->charge_status = BQ40Z50_CHARGE_STATE_NOT_CHARGING;
	di->dev = &client->dev;
	np = di->dev->of_node;
	di->client = client;
	INIT_DELAYED_WORK(&di->ocv_update_work, bq40z50_delay_report_upgarde_result_work);
	i2c_set_clientdata(client, di);
	mutex_init(&di->rw_lock);
#if defined(CONFIG_COUL_DRV)
	bq40z50_set_di(di);
#endif
	ret = bq40z50_check_chip(di);
	if (ret)
		goto dev_check_fail;

	ret = bq40z50_get_batt_para(di);
	if (ret)
		goto get_para_fail;

	bq40z50_update_gauge_info(di);

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
	set_hw_dev_flag(DEV_I2C_GAUGE_IC);
#endif

	ret = bq40z50_ops_register(di);
	if (ret)
		goto register_coul_ops_fail;

	return 0;

register_coul_ops_fail:
#ifdef CONFIG_COUL_DRV
	kfree(di->para_batt_data);
	di->para_batt_data = NULL;
#endif
get_para_fail:
#if defined(CONFIG_COUL_DRV)
	bq40z50_set_di(NULL);
#endif
dev_check_fail:
	mutex_destroy(&di->rw_lock);
	kfree(di);
	return ret;
}

static int bq40z50_remove(struct i2c_client *client)
{
	struct bq40z50_device_info *di = i2c_get_clientdata(client);

#if defined(CONFIG_COUL_DRV)
	if (!di || !di->para_batt_data)
		return -ENODEV;

	kfree(di->para_batt_data);
	di->para_batt_data = NULL;
	bq40z50_set_di(NULL);
	power_event_bnc_unregister(POWER_BNT_CONNECT, &di->event_nb);
#elif defined(CONFIG_HUAWEI_COUL)
	if (!di)
		return -ENODEV;
#endif
	cancel_delayed_work(&di->ocv_update_work);
	mutex_destroy(&di->rw_lock);
	kfree(di);

	return 0;
}

MODULE_DEVICE_TABLE(i2c, bq40z50);
static const struct of_device_id bq40z50_of_match[] = {
	{
		.compatible = "huawei,bq40z50",
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id bq40z50_i2c_id[] = {
	{ "bq40z50", 0 },
	{},
};

static struct i2c_driver bq40z50_driver = {
	.probe = bq40z50_probe,
	.remove = bq40z50_remove,
	.id_table = bq40z50_i2c_id,
	.driver = {
		.owner = THIS_MODULE,
		.name = "bq40z50_fg",
		.of_match_table = of_match_ptr(bq40z50_of_match),
	},
};

static int __init bq40z50_init(void)
{
	return i2c_add_driver(&bq40z50_driver);
}

static void __exit bq40z50_exit(void)
{
	i2c_del_driver(&bq40z50_driver);
}

rootfs_initcall(bq40z50_init);
module_exit(bq40z50_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("bq40z50 module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
