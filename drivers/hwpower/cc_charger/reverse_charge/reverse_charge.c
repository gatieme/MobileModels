// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge.c
 *
 * reverse charge with boost and protocol driver
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

#include <securec.h>
#include <linux/math64.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_boost.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_protocol.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_pd.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_interface.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_temp.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_time.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <huawei_platform/power/battery_voltage.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/usb/hw_pd_dev.h>

#define HWLOG_TAG reverse_charge
HWLOG_REGIST();

#define HIVIEW_START_INFO_LENGTH        2
#define HIVIEW_STOP_INFO_LENGTH         1
static struct timespec64 ts_start = {0, 0};
static struct reverse_charge_device *g_rchg_di;

static const struct rchg_boost_device_data g_boost_dev_data[] = {
	{ BOOST_DEVICE_ID_SC8726, "sc8726" },
};

static int boost_get_device_id(const char *str)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(g_boost_dev_data); i++) {
		if (!strncmp(str, g_boost_dev_data[i].name,
			strlen(str)))
			return g_boost_dev_data[i].id;
	}

	return -EPERM;
}

int boost_ops_register(struct boost_ops *ops)
{
	int dev_id;

	if (!g_rchg_di || !ops || !ops->chip_name) {
		hwlog_err("g_rchg_di or ops or chip_name is null\n");
		return -EPERM;
	}

	dev_id = boost_get_device_id(ops->chip_name);
	if (dev_id < 0) {
		hwlog_err("%s ops register fail\n", ops->chip_name);
		return -EPERM;
	}

	g_rchg_di->bst_ops = ops;
	g_rchg_di->bst_dev_id = dev_id;

	hwlog_info("%d:%s ops register ok\n", dev_id, ops->chip_name);
	return 0;
}

struct boost_ops *boost_get_ops(void)
{
	if (!g_rchg_di || !g_rchg_di->bst_ops) {
		hwlog_err("g_rchg_di or bst_ops is null\n");
		return NULL;
	}

	return g_rchg_di->bst_ops;
}

static const struct rchg_rprotocol_device_data g_rprotocol_dev_data[] = {
	{ RPROTOCOL_DEVICE_ID_STM32G031, "rstm32g031" },
};

static int rprotocol_get_device_id(const char *str)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(g_rprotocol_dev_data); i++) {
		if (!strncmp(str, g_rprotocol_dev_data[i].name,
			strlen(str)))
			return g_rprotocol_dev_data[i].id;
	}

	return -EPERM;
}

int rprotocol_ops_register(struct rprotocol_ops *ops)
{
	int dev_id;

	if (!g_rchg_di || !ops || !ops->chip_name) {
		hwlog_err("g_rchg_di or ops or chip_name is null\n");
		return -EPERM;
	}

	dev_id = rprotocol_get_device_id(ops->chip_name);
	if (dev_id < 0) {
		hwlog_err("%s ops register fail\n", ops->chip_name);
		return -EPERM;
	}

	g_rchg_di->rprot_ops = ops;
	g_rchg_di->rprot_dev_id = dev_id;

	hwlog_info("%d:%s ops register ok\n", dev_id, ops->chip_name);
	return 0;
}

struct rprotocol_ops *rprotocol_get_ops(void)
{
	if (!g_rchg_di || !g_rchg_di->rprot_ops) {
		hwlog_err("g_rchg_di or rprot_ops is null\n");
		return NULL;
	}

	return g_rchg_di->rprot_ops;
}

static void reverse_charge_report_stop_info(void)
{
	int ret;
	struct timespec64 ts_end = {0, 0};
	struct timespec64 ts_delta;
	struct hiview_info info;
	char used_time_val[POWER_DSM_BUF_SIZE_0016] = { 0 };

	ts_end = power_get_current_kernel_time();
	ts_delta.tv_sec = ts_end.tv_sec - ts_start.tv_sec;
	info.key = "ReverseScUsedTime";
	ret = snprintf_s(used_time_val, POWER_DSM_BUF_SIZE_0016, POWER_DSM_BUF_SIZE_0016 - 1, "%d", ts_delta.tv_sec);
	if (ret < 0) {
		hwlog_err("snprintf_s failed\n");
		return;
	}
	info.value = used_time_val;

	if ((ts_start.tv_sec > 0) || (ts_start.tv_nsec > 0))
		power_dsm_report_multi_hiview(DSM_RCHG_TYPE_SUPER, &info, HIVIEW_STOP_INFO_LENGTH);

	ts_start.tv_sec = ts_start.tv_nsec = 0;
}

static void reverse_charge_report_start_info(void)
{
	int i;
	int ret;
	int bat_temp = 0;
	int soc = 0;
	struct hiview_info info[HIVIEW_START_INFO_LENGTH];
	char ssoc_val[POWER_DSM_BUF_SIZE_0016] = { 0 };
	char temp_val[POWER_DSM_BUF_SIZE_0016] = { 0 };

	ts_start = power_get_current_kernel_time();
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&soc, POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_TEMP,
		&bat_temp, POWER_SUPPLY_DEFAULT_TEMP / POWER_SUPPLY_BAT_TEMP_UNIT,
		POWER_SUPPLY_BAT_TEMP_UNIT);

	info[0].key = "SSOC";
	ret = snprintf_s(ssoc_val, POWER_DSM_BUF_SIZE_0016, POWER_DSM_BUF_SIZE_0016 - 1, "%d", soc);
	if (ret < 0) {
		hwlog_err("snprintf_s failed\n");
		return;
	}
	info[0].value = ssoc_val;
	info[1].key = "BatStartTemp";
	ret = snprintf_s(temp_val, POWER_DSM_BUF_SIZE_0016, POWER_DSM_BUF_SIZE_0016 - 1, "%d", bat_temp);
	if (ret < 0) {
		hwlog_err("snprintf_s failed\n");
		return;
	}
	info[1].value = temp_val;

	power_dsm_report_multi_hiview(DSM_RCHG_TYPE_SUPER, info, HIVIEW_START_INFO_LENGTH);
}

static void rchg_send_icon_uevent(int icon_type)
{
	struct reverse_charge_device *di = g_rchg_di;

	if (!di)
		return;

	hwlog_info("%s enter,icon_type=%d, last_icon_type=%d\n",
		__func__, icon_type, di->last_icon_type);
	if (icon_type == di->last_icon_type)
		return;

	if (icon_type == ICON_TYPE_RCHG_SUPER)
		reverse_charge_report_start_info();
	else
		reverse_charge_report_stop_info();

	di->last_icon_type = icon_type;
	power_icon_notify(icon_type);
}

static void rchg_parse_thre_para(struct device_node *np,
	struct rchg_thre_para *data, const char *name)
{
	int row, col, len;
	int idata[RCHG_THRE_PARA_LEVEL * RCHG_THRE_TOTAL] = { 0 };

	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np,
		name, idata, RCHG_THRE_PARA_LEVEL, RCHG_THRE_TOTAL);
	if (len < 0)
		return;

	for (row = 0; row < len / RCHG_THRE_TOTAL; row++) {
		col = row * RCHG_THRE_TOTAL + RCHG_THRE_HIGH;
		data[row].thre_high = idata[col];
		col = row * RCHG_THRE_TOTAL + RCHG_THRE_LOW;
		data[row].thre_low = idata[col];
		col = row * RCHG_THRE_TOTAL + RCHG_THRE_IBUS;
		data[row].ibus_limit = idata[col];
	}

	for (row = 0; row < len / RCHG_THRE_TOTAL; row++)
		hwlog_info("thre_para[%d]: %d %d %d\n",
		row, data[row].thre_high, data[row].thre_low, data[row].ibus_limit);
}

static void rchg_parse_power_curve_para(struct device_node *np,
	struct rchg_power_curve *data, const char *name)
{
	int len;
	int idata[RCHG_POWER_CURVE_PARA_LEVEL] = { 0 };

	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np,
		name, idata, RCHG_POWER_CURVE_PARA_LEVEL, 1);

	if (len < 0)
		return;

	data->power_curve = idata[0];
	data->volt_curve = idata[1];
	data->current_curve = idata[2];

	hwlog_info("power_curve: %d %d %d\n",
		data->power_curve, data->volt_curve, data->current_curve);
}

static int rchg_parse_dts(struct device_node *np, struct reverse_charge_device *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "soc_protect_th",
		&di->soc_protect_th, RCHG_SOC_PROTECT_TH);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "temp_h_protect_th",
		&di->temp_h_protect_th, RCHG_TEMP_H_PROTECT_TH);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "temp_l_protect_th",
		&di->temp_l_protect_th, RCHG_TEMP_L_PROTECT_TH);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "vbat_protect_th",
		&di->vbat_protect_th, RCHG_VBAT_PROTECT_TH);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "vbus_init",
		&di->vbus_init, RCHG_VBUS_OUTPUT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ibus_init",
		&di->ibus_init, RCHG_IBUS_OUTPUT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "ibus_h_temp",
		&di->ibus_h_temp, RCHG_IBUS_H_TEMP);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "rchg_use_boost",
		&di->rchg_use_boost, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "mmi_pass_vbus",
		&di->mmi_pass_vbus, RCHG_MMI_PASS_VBUS);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "mmi_pass_ibat",
		&di->mmi_pass_ibat, RCHG_MMI_PASS_IBAT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "rchg_hv_support",
		&di->rchg_hv_support, 0);

	rchg_parse_power_curve_para(np, di->power_curve, "power_curve");
	rchg_parse_thre_para(np, di->soc_para, "soc_para");
	rchg_parse_thre_para(np, di->temp_para, "temp_para");
	rchg_parse_thre_para(np, di->temp_para1, "temp_para1");
	rchg_parse_thre_para(np, di->pwr_consum_para, "pwr_consum_para");
	return 0;
}

static void psy_tst_work(struct work_struct *work)
{
	struct reverse_charge_device *di = NULL;

	di = container_of(work, struct reverse_charge_device,
		psy_tst_work.work);
	if (!di) {
		hwlog_err("%s: di is null\n", __func__);
		return;
	}

	(void)power_msleep(DT_MSLEEP_200MS, 0, NULL); /* wait equipment usb off */
	hwlog_info("dbc test, supply 5v vbus\n");
	(void)boost_set_idle_mode(BST_NORMAL_STATE);
	(void)boost_set_vcg_on(BST_VCG_ON);
	(void)boost_set_vbus(di->vbus_init);
	(void)boost_ic_enable(BST_EN);

	(void)power_msleep(DT_MSLEEP_2S, 0, NULL); /* supply power for 2 sec */
	(void)boost_set_vcg_on(BST_VCG_OFF);
	(void)boost_ic_enable(BST_DIS);
	(void)boost_set_idle_mode(BST_IDLE_STATE);
}

#ifdef CONFIG_SYSFS
static ssize_t rchg_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t rchg_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info rchg_sysfs_field_tbl[] = {
	power_sysfs_attr_rw(rchg, 0644, RCHG_SYSFS_RCHG_ENABLE, rchg_enable), /* for dbc test */
	power_sysfs_attr_rw(rchg, 0644, RCHG_SYSFS_RCHG_SUCCESS, rchg_success), /* for mmi test */
	power_sysfs_attr_rw(rchg, 0644, RCHG_SYSFS_RCHG_HV_SUPPORT, rchg_hv_support),
	power_sysfs_attr_rw(rchg, 0644, RCHG_SYSFS_RCHG_VOL_TEST, rchg_vol_test), /* for dbc test */
};

#define RCHG_SYSFS_ATTRS_SIZE  ARRAY_SIZE(rchg_sysfs_field_tbl)

static struct attribute *rchg_sysfs_attrs[RCHG_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group rchg_sysfs_attr_group = {
	.attrs = rchg_sysfs_attrs,
};

static ssize_t rchg_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct reverse_charge_device *di = dev_get_drvdata(dev);
	int rchg_success;
	int ibat = 0;

	info = power_sysfs_lookup_attr(attr->attr.name,
		rchg_sysfs_field_tbl, RCHG_SYSFS_ATTRS_SIZE);
	if (!info || !di)
		return -EINVAL;

	switch (info->name) {
	case RCHG_SYSFS_RCHG_SUCCESS:
		power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
			POWER_SUPPLY_PROP_CURRENT_NOW, &ibat,
			POWER_SUPPLY_DEFAULT_CURRENT_NOW, 1);
		rchg_success = (int)((rprot_get_request_vbus() >= di->mmi_pass_vbus) &&
			(abs(ibat) >= di->mmi_pass_ibat));
		hwlog_info("mmi visit rchg success: %d\n", rchg_success);
		return snprintf(buf, MAX_SIZE, "%d\n", rchg_success);
	case RCHG_SYSFS_RCHG_HV_SUPPORT:
		hwlog_info("rchg_hv_support: %d\n", di->rchg_hv_support);
		return snprintf(buf, MAX_SIZE, "%d\n", di->rchg_hv_support);
	default:
		break;
	}

	return 0;
}

static ssize_t rchg_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct power_sysfs_attr_info *info = NULL;
	struct reverse_charge_device *di = dev_get_drvdata(dev);
	long val = 0;

	info = power_sysfs_lookup_attr(attr->attr.name,
		rchg_sysfs_field_tbl, RCHG_SYSFS_ATTRS_SIZE);
	if (!info || !di)
		return -EINVAL;

	switch (info->name) {
	case RCHG_SYSFS_RCHG_ENABLE:
		mod_delayed_work(system_power_efficient_wq,
			&di->psy_tst_work, 0);
		break;
	case RCHG_SYSFS_RCHG_VOL_TEST:
#ifndef CONFIG_FACTORY_MODE
		return -EINVAL;
#endif
		if (di->test_process != WRITE_DEFAULT)
			return -EINVAL;

		if (kstrtol(buf, POWER_BASE_DEC, &val) < 0)
			return -EINVAL;
		if (val < RCHG_MIN_VOL || val > RCHG_MAX_VOL)
			return -EINVAL;

		hwlog_info("write rchg vol:%d\n", val);
		di->test_process = WRITE_START;
		di->write_value = val * RCHG_MV;
		mod_delayed_work(system_power_efficient_wq,
			&di->rchg_vol_test_work, 0);
		break;
	default:
		break;
	}

	return count;
}

static void rchg_sysfs_create_group(struct device *dev)
{
	power_sysfs_init_attrs(rchg_sysfs_attrs,
		rchg_sysfs_field_tbl, RCHG_SYSFS_ATTRS_SIZE);
	power_sysfs_create_link_group("hw_power", "charger", "reverse_charge",
		dev, &rchg_sysfs_attr_group);
}

static void rchg_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_link_group("hw_power", "charger", "reverse_charge",
		dev, &rchg_sysfs_attr_group);
}
#else
static inline void rchg_sysfs_create_group(struct device *dev)
{
}

static inline void rchg_sysfs_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int rchg_get_para_thre(int vol, struct rchg_thre_para *para)
{
	int i = 0;

	for (; i < RCHG_THRE_PARA_LEVEL; i++) {
		if ((vol <= para[i].thre_high) &&
			(vol > para[i].thre_low))
			return para[i].ibus_limit;
	}

	return -ENOMEM;
}

static bool rchg_check_battery_status(struct reverse_charge_device *di,
	int *vbus_limit, int *ibus_limit)
{
	int bat_temp = 0;
	int soc = 0;
	int vbat = 0;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_CAPACITY,
		&soc, POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME, POWER_SUPPLY_PROP_TEMP,
		&bat_temp, POWER_SUPPLY_DEFAULT_TEMP / POWER_SUPPLY_BAT_TEMP_UNIT,
		POWER_SUPPLY_BAT_TEMP_UNIT);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vbat,
		POWER_SUPPLY_DEFAULT_VOLTAGE_NOW, POWER_UV_PER_MV);

	if (bat_temp >= di->temp_h_protect_th) {
		*vbus_limit = di->vbus_init;
		*ibus_limit = di->ibus_h_temp;
		return false;
	}
	if ((bat_temp <= di->temp_l_protect_th) ||
		(vbat <= di->vbat_protect_th) ||
		(soc <= di->soc_protect_th)) {
		*vbus_limit = di->vbus_init;
		*ibus_limit = di->ibus_init;
		return 0;
	}

	return true;
}

static int get_rchg_temp(void)
{
	return power_temp_get_average_value(POWER_RCHG_TEMP) / 1000; /* 1000 : millicenti & centi */
}

static void rchg_calculate_charge_param(struct reverse_charge_device *di,
	int *vbus_limit, int *ibus_limit, int *drop_ibus)
{
	int soc = 0;
	int bat_temp = 0;
	int vbat = 0;
	int ibat = 0;
	int pwr_consume, temp_ibus, rchg_tmp;

	if (!vbus_limit || !ibus_limit || !drop_ibus)
		return;

	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &soc, POWER_SUPPLY_DEFAULT_CAPACITY, 1);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_TEMP, &bat_temp,
		POWER_SUPPLY_DEFAULT_TEMP / POWER_SUPPLY_BAT_TEMP_UNIT,
		POWER_SUPPLY_BAT_TEMP_UNIT);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vbat,
		POWER_SUPPLY_DEFAULT_VOLTAGE_NOW, POWER_UV_PER_MV);
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_CURRENT_NOW, &ibat,
		POWER_SUPPLY_DEFAULT_CURRENT_NOW, 1);
	rchg_tmp = get_rchg_temp();

	/* step-1: get requested vbus/ibus */
	*vbus_limit = rprot_get_request_vbus();
	*ibus_limit = rprot_get_request_ibus();

	/* step-2: update ibus limit by soc */
	temp_ibus = rchg_get_para_thre(soc, di->soc_para);
	*drop_ibus = temp_ibus;
	hwlog_info("soc:%d, temp_ibus:%d\n", soc, temp_ibus);
	if (temp_ibus > 0)
		*ibus_limit = min(*ibus_limit, temp_ibus);

	/* step-3: update ibus limit by temp */
	temp_ibus = rchg_get_para_thre(bat_temp, di->temp_para);
	hwlog_info("bat_temp:%d, temp_ibus:%d\n", bat_temp, temp_ibus);
	if (temp_ibus > 0) {
		*ibus_limit = min(*ibus_limit, temp_ibus);
		*drop_ibus = min(*drop_ibus, temp_ibus);
	}

	/* step-4: update ibus limit by temp */
	temp_ibus = rchg_get_para_thre(rchg_tmp, di->temp_para1);
	hwlog_info("rchg_tmp:%d, temp_ibus:%d\n", rchg_tmp, temp_ibus);
	if (temp_ibus >= 0) {
		*ibus_limit = min(*ibus_limit, temp_ibus);
		*drop_ibus = min(*drop_ibus, temp_ibus);
	}

	/* step-5: update ibus limit by power consume */
	pwr_consume = (abs(ibat * vbat * hw_battery_get_series_num()) - rprot_get_rt_ibus() *
		*vbus_limit) / POWER_MW_PER_W;
	temp_ibus = rchg_get_para_thre(pwr_consume, di->pwr_consum_para);
	hwlog_info("ibat:%d, pwr_consume:%d, temp_ibus:%d\n",
		ibat, pwr_consume, temp_ibus);
	if (temp_ibus > 0) {
		*ibus_limit = min(*ibus_limit, temp_ibus);
		*drop_ibus = min(*drop_ibus, temp_ibus);
	}
}

static void rchg_control_work(struct work_struct *work)
{
	int vbus_limit = 0;
	int ibus_limit = 0;
	int drop_ibus = 0;
	int i;
	struct reverse_charge_device *di = NULL;

	di = container_of(work, struct reverse_charge_device,
		rchg_control_work.work);
	if (!di) {
		hwlog_err("%s: di is null\n", __func__);
		return;
	}

	for (i = 0; i < AUTH_TIMEOUT; i++) {
		if (di->rchg_ignore_work_flag) {
			(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
			continue;
		} else {
			break;
		}
	}

	if (i == AUTH_TIMEOUT)
		di->rchg_ignore_work_flag = 0;

	if (!rchg_check_battery_status(di, &vbus_limit, &ibus_limit)) {
		hwlog_err("%s: battery status bad, not do super charge\n", __func__);
		goto next_loop;
	}
	if (rprot_check_protocol_state() != OUTPUT_MODE_SCP) {
		hwlog_err("%s: scp control mode fail, not do super charge\n", __func__);
		vbus_limit = di->vbus_init;
		ibus_limit = di->ibus_init;
		goto next_loop;
	}
	rchg_send_icon_uevent(ICON_TYPE_RCHG_SUPER);

	rchg_calculate_charge_param(di, &vbus_limit, &ibus_limit, &drop_ibus);

next_loop:
	boost_set_ibus(ibus_limit);
	boost_set_vbus(vbus_limit);
	rprot_update_vbus(vbus_limit);
	rprot_update_drop_cur(drop_ibus);
	schedule_delayed_work(&g_rchg_di->rchg_control_work,
		msecs_to_jiffies(RCHG_CONTROL_WORK_DELAY_TIME));
}

static int reverse_charge_stop(struct reverse_charge_device *di)
{
	int ret;

	hwlog_info("%s enter\n", __func__);

	ret = boost_set_idle_mode(BST_IDLE_STATE);
	ret += boost_set_vcg_on(BST_VCG_OFF);
	ret += boost_ic_enable(BST_DIS);

	ret += rprot_enable_sleep(1);
	ret += charge_set_hiz_enable(HIZ_MODE_DISABLE);
	cancel_delayed_work_sync(&di->rchg_control_work);
	di->last_icon_type = ICON_TYPE_INVALID;
	power_wakeup_unlock(di->rchg_lock, false);
	reverse_charge_report_stop_info();

	return ret;
}

static int reverse_charge_start(struct reverse_charge_device *di)
{
	int ret;

	hwlog_info("%s enter\n", __func__);
	power_wakeup_lock(di->rchg_lock, false);

	ret = charge_set_hiz_enable(HIZ_MODE_ENABLE);
	ret += rprot_ic_reset();

	ret += rprot_update_vbus(di->vbus_init);
	if (ret)
		hwlog_err("rchg protocol start err\n");

	ret = boost_set_idle_mode(BST_NORMAL_STATE);
	ret += boost_set_vcg_on(BST_VCG_ON);
	ret += boost_set_ibus(di->ibus_init);
	ret += boost_set_vbus(di->vbus_init);
	ret += boost_ic_enable(BST_EN);
	if (ret) {
		hwlog_err("boost err\n");
		return ret;
	}

	if (hw_pd_is_reverse_charge_enable()) {
		ret += rprot_enable_rscp(RSCP_EN);
		ret += rprot_set_power_curve(di->power_curve);
	} else {
		ret += rprot_detect_device();
		rchg_pd_otg_enable(true);
		hwlog_info("reverse sc detect\n");
		return ret;
	}

	mod_delayed_work(system_power_efficient_wq,
		&di->rchg_control_work, 0);

	return ret;
}

int reverse_charge_enable(int enable)
{
	if (!g_rchg_di || !g_rchg_di->rchg_use_boost) {
		hwlog_info("%s:use buck charger to supply otg power, enable:%d\n", __func__, enable);
		return charge_otg_mode_enable(enable, VBUS_CH_USER_WIRED_OTG);
	}

	if (enable)
		return reverse_charge_start(g_rchg_di);
	else
		return reverse_charge_stop(g_rchg_di);
}

static void rchg_set_ignore_work_flag(void *data)
{
	struct reverse_charge_device *di = g_rchg_di;

	if (!di) {
		hwlog_err("%s: di is null\n", __func__);
		return;
	}

	di->rchg_ignore_work_flag = *(int *)data;
	hwlog_info("%s ignore work flag is %d\n", __func__, di->rchg_ignore_work_flag);
}

static void rchg_auth_process_work(struct work_struct *work)
{
	int ret;

	if (!work)
		return;

	ret = rprot_auth_process();

	if (ret)
		hwlog_err("rscp auth fail\n");
}

static int rchg_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct reverse_charge_device *di = g_rchg_di;

	if (!di)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_RVS_CHG_RESET_PROTOCOL:
		hwlog_info("%s rchg reset protocol\n", __func__);
		rprot_ic_reset();
		break;
	case POWER_NE_RVS_CHG_PROTOCOL_FAIL:
		hwlog_info("%s rchg protocol fail\n", __func__);
		rchg_send_icon_uevent(ICON_TYPE_RCHG_NORMAL);
		break;
	case POWER_NE_BMS_REVERSE_AUTH_IGNORE_WORK:
		hwlog_info("%s auth ignore reverse work\n", __func__);
		rchg_set_ignore_work_flag(data);
		break;
	case POWER_NE_BMS_REVERSE_AUTH_START:
		hwlog_info("%s reverse auth start\n", __func__);
		schedule_work(&di->rchg_auth_process_work);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static void rchg_vol_test_work(struct work_struct *work)
{
	struct reverse_charge_device *di = NULL;

	di = container_of(work, struct reverse_charge_device,
		rchg_vol_test_work.work);
	if (!di) {
		hwlog_err("%s: di is null\n", __func__);
		return;
	}

	(void)power_msleep(DT_MSLEEP_200MS, 0, NULL); /* wait equipment usb off */
	hwlog_info("dbc test, supply %d vbus\n", di->write_value);
	(void)boost_set_idle_mode(BST_NORMAL_STATE);
	(void)boost_set_vcg_on(BST_VCG_ON);
	(void)boost_set_vbus(di->write_value);
	(void)boost_ic_enable(BST_EN);
	di->test_process = WRITE_DONE;
}

static void rchg_test_exit_work(struct work_struct *work)
{
	struct reverse_charge_device *di = NULL;

	di = container_of(work, struct reverse_charge_device,
		rchg_test_exit_work.work);
	if (!di || (di->test_process == PWK_EVT_PROCESS)) {
		hwlog_err("%s: di is null or test process err\n", __func__);
		return;
	}

	di->test_process = PWK_EVT_PROCESS;
	hwlog_info("%s\n", __func__);
	(void)boost_set_vcg_on(BST_VCG_OFF);
	(void)boost_ic_enable(BST_DIS);
	(void)boost_set_idle_mode(BST_IDLE_STATE);
	di->write_value = 0;
	di->test_process = WRITE_DEFAULT;
}

static int rchg_pwrkey_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct reverse_charge_device *di = g_rchg_di;

	if (!di)
		return NOTIFY_OK;

	if ((di->test_process == WRITE_DONE) && (event == PRESS_KEY_DOWN))
		mod_delayed_work(system_power_efficient_wq,
			&di->rchg_test_exit_work, 0);

	return NOTIFY_OK;
}

static int reverse_charge_probe(struct platform_device *pdev)
{
	int ret;
	struct reverse_charge_device *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	np = di->dev->of_node;

	ret = rchg_parse_dts(np, di);
	if (ret)
		goto fail_free_mem;

	INIT_DELAYED_WORK(&di->rchg_control_work, rchg_control_work);
	INIT_DELAYED_WORK(&di->psy_tst_work, psy_tst_work);
	di->rchg_nb.notifier_call = rchg_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_REVERSE_SC, &di->rchg_nb);
	if (ret)
		goto fail_free_mem;
	di->rchg_lock = power_wakeup_source_register(di->dev, "reverse_charge_wakelock");

	INIT_DELAYED_WORK(&di->rchg_vol_test_work, rchg_vol_test_work);
	INIT_DELAYED_WORK(&di->rchg_test_exit_work, rchg_test_exit_work);
	INIT_WORK(&di->rchg_auth_process_work, rchg_auth_process_work);
	di->pwrkey_nb.notifier_call = rchg_pwrkey_notifier_call;
	ret = power_platform_powerkey_register_notifier(&di->pwrkey_nb);
	if (ret)
		goto fail_reg_pwk_notifier;

	rchg_sysfs_create_group(di->dev);
	di->test_process = WRITE_DEFAULT;
	di->write_value = 0;
	g_rchg_di = di;
	platform_set_drvdata(pdev, di);
	hwlog_info("%s success\n", __func__);
	return 0;

fail_reg_pwk_notifier:
	power_event_bnc_unregister(POWER_BNT_REVERSE_SC, &di->rchg_nb);
	power_wakeup_source_unregister(di->rchg_lock);
fail_free_mem:
	devm_kfree(&pdev->dev, di);
	g_rchg_di = NULL;

	return ret;
}

static int reverse_charge_remove(struct platform_device *pdev)
{
	struct reverse_charge_device *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	power_event_bnc_unregister(POWER_BNT_REVERSE_SC, &di->rchg_nb);
	power_wakeup_source_unregister(di->rchg_lock);
	rchg_sysfs_remove_group(di->dev);
	cancel_delayed_work(&di->rchg_control_work);
	devm_kfree(&pdev->dev, di);
	g_rchg_di = NULL;

	return 0;
}

static const struct of_device_id reverse_charge_match_table[] = {
	{
		.compatible = "huawei,reverse_charge",
		.data = NULL,
	},
	{},
};

static struct platform_driver reverse_charge_driver = {
	.probe = reverse_charge_probe,
	.remove = reverse_charge_remove,
	.driver = {
		.name = "reverse_charge",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(reverse_charge_match_table),
	},
};

static int __init reverse_charge_init(void)
{
	return platform_driver_register(&reverse_charge_driver);
}

static void __exit reverse_charge_exit(void)
{
	platform_driver_unregister(&reverse_charge_driver);
}

subsys_initcall_sync(reverse_charge_init);
module_exit(reverse_charge_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("reverse charge with boost and protocol module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
