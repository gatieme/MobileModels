// SPDX-License-Identifier: GPL-2.0
/*
 * bq40z50_param_upgrade.c
 *
 * bq40z50 param upgrade
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

#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <securec.h>
#include "bq40z50_param_upgrade.h"

#define HWLOG_TAG bq40z50_param_upgrade
HWLOG_REGIST();

static int bq40z50_read_sub_cmd(struct bq40z50_device_info *di, u16 sub_cmd, u8 *data, int data_size)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_LEN,
		(u8)(sub_cmd & BQ40Z50_SUB_CMD_SING_BYTE_MASK), (u8)(sub_cmd >> BQ40Z50_SUB_CMD_SING_BYTE_LEN) };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_SIZE);
		if (ret) {
			hwlog_err("%s write command 0x%x fail\n", __func__, sub_cmd);
			power_usleep(DT_USLEEP_10MS);
			continue;
		}
		ret = bq40z50_read_block(di, BQ40Z50_REG_CTL, data, data_size);
		if (!ret)
			return 0;
		hwlog_err("%s read command 0x%x fail\n", __func__, sub_cmd);
		power_usleep(DT_USLEEP_10MS);
	}

	hwlog_err("%s read command 0x%x %d times fail\n", __func__, sub_cmd, BQ40Z50_RETRY_COUNT);
	return ret;
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

static void bq40z50_report_param_upgrade_result(struct bq40z50_device_info *di)
{
	u8 version = bq40z50_get_version(di);
	char v_string[GAUGE_VERSION_STRING_LEN] = { 0 };
	int ret = sprintf_s(v_string, GAUGE_VERSION_STRING_LEN, "0x%x", version);
	struct hiview_info info[GAUGE_REPORT_PARAM_SIZE];

	if (ret == -1)
		hwlog_err("sprintf_s gauge_version err");

	info[UPDATE_RESULT_INDEX].key = "update_result";
	if (di->gauge_upgrade_result == BQ40Z50_GAUGE_UPGRADE_SUCCESS_STATUS)
		info[UPDATE_RESULT_INDEX].value = "0";
	else
		info[UPDATE_RESULT_INDEX].value = "1";

	info[GAUGE_VERSION_INDEX].key = "gauge_version";
	info[GAUGE_VERSION_INDEX].value = v_string;
	info[DEVICE_NAME_INDEX].key = "device_name";
	info[DEVICE_NAME_INDEX].value = di->device_name;
	info[MANUFAC_NAME_INDEX].key = "manufac_name";
	info[MANUFAC_NAME_INDEX].value = di->manufac_name;

	power_dsm_report_multi_hiview(BQ40Z50_PARAM_UPGRADE_DMD_REPORT_ID, info, GAUGE_REPORT_PARAM_SIZE);
}

static bool bq40z50_check_version(struct bq40z50_device_info *di)
{
	u8 version = bq40z50_get_version(di);
	hwlog_info("gauge param version is 0x%x\n", di->upgrade_param_dts.gauge_version);
	return (version < di->upgrade_param_dts.gauge_version);
}

static int bq40z50_batt_unseal(struct bq40z50_device_info *di)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 unseal_status =
		di->device_id == BATTERY_FUEL_BQ40Z50 ? BQ40Z50_GAUGE_A_BATT_UNSEAL_STATUS : BQ40Z50_GAUGE_C_BATT_UNSEAL_STATUS;

	while (retry--) {
		ret = bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND,
			(di->upgrade_param_dts.gauge_part_word & BQ40Z50_UNSEAL_WORD_SING_BYTE_MASK));
		power_usleep(DT_USLEEP_20MS);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND,
			(di->upgrade_param_dts.gauge_part_word >> BQ40Z50_UNSEAL_WORD_SING_BYTE_LEN));
		power_msleep(DT_MSLEEP_1S, 0, NULL);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND,
			(u16)(di->upgrade_param_dts.gauge_all_word & BQ40Z50_UNSEAL_WORD_SING_BYTE_MASK));
		power_usleep(DT_USLEEP_20MS);
		ret += bq40z50_write_word(di, BQ40Z50_REG_MANUFACTURER_SEND,
			(u16)(di->upgrade_param_dts.gauge_all_word >> BQ40Z50_UNSEAL_WORD_SING_BYTE_LEN));
		power_msleep(DT_MSLEEP_1S, 0, NULL);
		if (ret) {
			power_usleep(DT_USLEEP_10MS);
			continue;
		}

		if (bq40z50_check_seal_status(di, unseal_status)) {
			hwlog_info("%s batt unseal success\n", __func__);
			return 0;
		}
		power_usleep(DT_USLEEP_10MS);
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
			power_usleep(DT_USLEEP_10MS);
			continue;
		}
		power_msleep(DT_MSLEEP_1S, 0, NULL);
		if (bq40z50_check_seal_status(di, BQ40Z50_GAUGE_BATT_SEAL_STATUS)) {
			hwlog_info("%s batt lock success\n", __func__);
			return 0;
		}
		power_usleep(DT_USLEEP_10MS);
	}

	hwlog_err("%s batt lock %d times fail\n", __func__, BQ40Z50_RETRY_COUNT);
	return -EIO;
}

static int bq40z50_update_version(struct bq40z50_device_info *di, u16 sub_cmd, u8 version)
{
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	u8 buf[BQ40Z50_SUB_CMD_WIRTE_VERSION_SIZE] = { BQ40Z50_SUB_CMD_WIRTE_VERSION_LEN,
		(u8)(sub_cmd & BQ40Z50_SUB_CMD_SING_BYTE_MASK), (u8)(sub_cmd >> BQ40Z50_SUB_CMD_SING_BYTE_LEN), version };

	while (retry--) {
		ret = bq40z50_write_block(di, BQ40Z50_REG_CTL, buf, BQ40Z50_SUB_CMD_WIRTE_VERSION_SIZE);
		if (ret) {
			hwlog_err("%s sub command 0x%x update version:0x%x fail\n", __func__, sub_cmd, version);
			power_usleep(DT_USLEEP_10MS);
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

static int bq40z50_process_write_param(struct bq40z50_device_info *di, int index, u8 *param)
{
	u8 *data;
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	int data_size = param[index + OPERATE_BUF_LEN_INDEX];

	hwlog_info("write datasize is %d , write cmd is 0x%x\n", data_size, param[index + REG_CMD_INDEX]);
	if (data_size <= 0) {
		hwlog_err("%s upgarde_gauge_param process write data_size error!\n", __func__);
		return -EIO;
	}

	if ((index + OPERATE_BUF_START_INDEX + data_size) > di->upgrade_param_dts.upgrade_param_len) {
		hwlog_err("%s upgarde_gauge_param write len error!\n", __func__);
		return -EIO;
	}

	data = kcalloc(data_size, sizeof(u8), GFP_KERNEL);
	if (memcpy_s(data, data_size, param + index + OPERATE_BUF_START_INDEX, data_size) != EOK) {
		hwlog_err("%s upgarde_gauge_param process write cpy data error!\n", __func__);
		kfree(data);
		return -EIO;
	}

	while (retry--) {
		ret = bq40z50_write_block(di, param[index + REG_CMD_INDEX], data, data_size);
		if (ret) {
			hwlog_err("%s upgarde_gauge_param process write for write data error!\n", __func__);
			power_usleep(DT_USLEEP_10MS);
			continue;
		}
		break;
	}

	kfree(data);
	return ret;
}

static int bq40z50_compare_c_param(int index, int data_size, u8* param, u8 *read_data)
{
	int i = 0;
	for (; i < data_size; i++) {
		if (param[index + OPERATE_BUF_START_INDEX + i] != read_data[i]) {
			hwlog_err("%s upgarde_gauge_param process compare data not identical\n", __func__);
			return -EIO;
		}
	}

	return 0;
}

static int bq40z50_compare_a_param(int index, u8* param, u8 *read_data)
{
	int i = 0;
	for (; i < param[index + OPERATE_COMPARE_A_BUF_LEN_INDEX]; i++) {
		if (param[index + OPERATE_COMPARE_A_BUF_START_INDEX + i] != read_data[COMPARE_BUF_FIRST_INDEX + i]) {
			hwlog_err("%s upgarde_gauge_param process compare data not identical\n", __func__);
			return -EIO;
		}
	}

	return 0;
}

static int bq40z50_process_compare_param(struct bq40z50_device_info *di, int index, u8 *param)
{
	u8 *read_data;
	int ret;
	int retry = BQ40Z50_RETRY_COUNT;
	int data_size = param[index + OPERATE_BUF_LEN_INDEX];

	hwlog_info("compare datasize is %d , compare cmd is 0x%x\n", data_size, param[index + REG_CMD_INDEX]);
	if (data_size <= 0) {
		hwlog_err("%s upgarde_gauge_param process compare data_size error\n", __func__);
		return -EIO;
	}

	read_data = kcalloc(data_size, sizeof(u8), GFP_KERNEL);
	while (retry--) {
		ret = bq40z50_read_block(di, param[index + REG_CMD_INDEX], read_data, data_size);
		if (ret) {
			hwlog_err("%s upgarde_gauge_param process compare for read data error!\n", __func__);
			power_usleep(DT_USLEEP_10MS);
			continue;
		}
		break;
	}

	if (ret) {
		hwlog_err("%s upgarde_gauge_param process compare for read data error!\n", __func__);
		kfree(read_data);
		return -EIO;
	}

	if (di->device_id == BATTERY_FUEL_SH366006) {
		ret = bq40z50_compare_c_param(index, data_size, param, read_data);
	} else if (di->device_id == BATTERY_FUEL_BQ40Z50) {
		hwlog_info("compare bq40z50 datasize is 0x%x \n", param[index + OPERATE_COMPARE_A_BUF_LEN_INDEX]);
		ret = bq40z50_compare_a_param(index, param, read_data);
	} else {
		ret = -EIO;
	}

	kfree(read_data);
	return ret;
}

static int bq40z50_process_wait_param(struct bq40z50_device_info *di, int index, u8 *param)
{
	int wait_ms = ((int)param[index + OPERATE_WAIT_BUF_HIGH_INDEX] * BYTE_HIGH_TO_LOW) +
				  param[index + OPERATE_WAIT_BUF_LOW_INDEX];

	if (param[index + OPERATE_WAIT_BUF_LEN_INDEX] == OPERATE_WAIT_BUF_LEN) {
		hwlog_info("wait time is %d\n", wait_ms);
		power_msleep(wait_ms, 0, NULL);
	} else {
		hwlog_info("%s upgarde_gauge_param process wait time error!\n", __func__);
		return -EIO;
	}

	return 0;
}

static int bq40z50_update_param(struct bq40z50_device_info *di)
{
	int index = 0;
	u8 *param = di->upgrade_param_dts.upgrade_param;

	while (index < di->upgrade_param_dts.upgrade_param_len) {
		if (param[index + INDEX_TYPE] == OPERATE_WRITE) {
			if (bq40z50_process_write_param(di, index, param))
				return -EIO;
			index += OPERATE_LINE_LEN + param[index + OPERATE_BUF_LEN_INDEX];
		} else if (param[index + INDEX_TYPE] == OPERATE_COMPARE) {
			if (bq40z50_process_compare_param(di, index, param))
				return -EIO;
			if (di->device_id == BATTERY_FUEL_BQ40Z50)
				index += OPERATE_COMPARE_A_LINE_LEN + param[index + OPERATE_COMPARE_A_BUF_LEN_INDEX];
			else if (di->device_id == BATTERY_FUEL_SH366006)
				index += OPERATE_LINE_LEN + param[index + OPERATE_BUF_LEN_INDEX];
		} else if (param[index + INDEX_TYPE] == OPERATE_WAIT) {
			if (bq40z50_process_wait_param(di, index, param))
				return -EIO;
			index += OPERATE_LINE_LEN;
		} else {
			return -EIO;
		}
	}

	return 0;
}

static void parse_upgrade_param(struct bq40z50_device_info *di, char *type)
{
	int len = of_property_count_u8_elems(di->dev->of_node, type);

	if (len <= 0)
		return;

	di->upgrade_param_dts.upgrade_param = kzalloc(len * sizeof(*(di->upgrade_param_dts.upgrade_param)), GFP_KERNEL);
	if (!di->upgrade_param_dts.upgrade_param)
		return;

	if (power_dts_read_u8_array(power_dts_tag(HWLOG_TAG), di->dev->of_node, type,
		di->upgrade_param_dts.upgrade_param, len)) {
		kfree(di->upgrade_param_dts.upgrade_param);
		return;
	}

	di->upgrade_param_dts.upgrade_param_len = len;
}

static void parse_upgrade_param_dts(struct bq40z50_device_info *di)
{
	int ret;
	char part_word[UPGRADE_PARAM_DTSI_TITLE_LEN] = { '\0' };
	char all_word[UPGRADE_PARAM_DTSI_TITLE_LEN] = { '\0' };
	char upgrade_param[UPGRADE_PARAM_DTSI_TITLE_LEN] = { '\0' };

	ret = sprintf_s(part_word, UPGRADE_PARAM_DTSI_TITLE_LEN, "%s_%d_%s", di->manufac_name, di->device_id, "part_word");
	if (ret == -1)
		hwlog_err("sprintf_s part_word err");
	
	ret = sprintf_s(all_word, UPGRADE_PARAM_DTSI_TITLE_LEN, "%s_%d_%s", di->manufac_name, di->device_id, "all_word");
	if (ret == -1)
		hwlog_err("sprintf_s all_word err");

	ret = sprintf_s(upgrade_param, UPGRADE_PARAM_DTSI_TITLE_LEN, "%d_%s", di->device_id, "upgrade_param");
	if (ret == -1)
		hwlog_err("sprintf_s upgrade_param err");

	parse_upgrade_param(di, upgrade_param);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		part_word, (u32 *)&di->upgrade_param_dts.gauge_part_word, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		all_word, (u32 *)&di->upgrade_param_dts.gauge_all_word, 0);
}

static void bq40z50_update_gauge_info(struct bq40z50_device_info *di)
{
	int ret;

	hwlog_info("gauge upgrade enable is %d\n", di->upgrade_param_dts.gauge_upgrade_enable);
	if (!di->upgrade_param_dts.gauge_upgrade_enable) {
		hwlog_info("%s gauge upgrade disable\n", __func__);
		return;
	}

	if (!bq40z50_check_version(di)) {
		hwlog_info("%s gauge version not match\n", __func__);
		return;
	}

	di->gauge_upgrade_result = BQ40Z50_GAUGE_UPGRADE_FAIL_STATUS;
	parse_upgrade_param_dts(di);
	ret = bq40z50_batt_unseal(di);
	if (ret)
		goto bq40z50_report_ocv_upgrade_result;

	ret = bq40z50_update_param(di);
	if ((!ret) && (di->device_id == BATTERY_FUEL_BQ40Z50))
		ret += bq40z50_update_version(di, BQ40Z50_SUB_CMD_VERSION, di->upgrade_param_dts.gauge_version);

	ret += bq40z50_batt_seal(di);

	if (!ret)
		di->gauge_upgrade_result = BQ40Z50_GAUGE_UPGRADE_SUCCESS_STATUS;

bq40z50_report_ocv_upgrade_result:
	hwlog_info("%s gauge info update status: %d\n", __func__, di->gauge_upgrade_result);
	bq40z50_report_param_upgrade_result(di);
}

static void bq40z50_delay_gauge_upgrade_work(struct work_struct *work)
{
	struct bq40z50_device_info *di = container_of(work, struct bq40z50_device_info, gauge_upgrade_work.work);

	if (!di)
		return;

	hwlog_info("%s enter\n", __func__);

	bq40z50_update_gauge_info(di);

	hwlog_info("%s end\n", __func__);
}

void bq40z50_creat_param_upgrade_delay_work(struct bq40z50_device_info *di)
{
	if (!di)
		return;

	INIT_DELAYED_WORK(&di->gauge_upgrade_work, bq40z50_delay_gauge_upgrade_work);
	schedule_delayed_work(&di->gauge_upgrade_work, msecs_to_jiffies(BQ40Z50_OCV_UPGRADE_DMD_DELAY_REPORT_TIME60S));
}

void bq40z50_cancel_param_upgrade_delay_work(struct bq40z50_device_info *di)
{
	if (!di)
		return;

	cancel_delayed_work(&di->gauge_upgrade_work);
}
