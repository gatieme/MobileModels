/*
 * wireless_tx_pwr_ctrl.c
 *
 * power control for wireless reverse charging
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

#include <linux/kernel.h>
#include <linux/delay.h>
#include <log/hw_log.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/wireless/wireless_transmitter.h>

static struct wltx_pwr_ctrl_info g_pwr_ctrl_di;

#define HWLOG_TAG wireless_tx_pwr_ctrl
HWLOG_REGIST();

extern int huawei_battery_capacity(void);

static struct {
	enum wltx_pwr_sw_scene scn;
	const char *name;
} const g_pwr_sw_scn[] = {
	{ PWR_SW_BY_VBUS_ON,  "PWR_SW_BY_VBUS_ON" },
	{ PWR_SW_BY_VBUS_OFF, "PWR_SW_BY_VBUS_OFF" },
	{ PWR_SW_BY_OTG_ON,   "PWR_SW_BY_OTG_ON" },
	{ PWR_SW_BY_OTG_OFF,  "PWR_SW_BY_OTG_OFF" },
	{ PWR_SW_BY_DC_DONE,  "PWR_SW_BY_DC_DONE" }
};

/* pwr_type: VBUS_OTG */
const struct wltx_pwr_attr g_attr1[] = {
	{ PWR_SW_BY_VBUS_ON, true, PWR_SRC_VBUS },
	{ PWR_SW_BY_VBUS_OFF, true, PWR_SRC_OTG },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_OTG },
	{ PWR_SW_BY_OTG_OFF, false, PWR_SRC_OTG }
};

/* pwr_type: 5VBST_OTG */
const struct wltx_pwr_attr g_attr2[] = {
	{ PWR_SW_BY_VBUS_ON, true, PWR_SRC_5VBST },
	{ PWR_SW_BY_VBUS_OFF, true, PWR_SRC_OTG },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_OFF, true, PWR_SRC_OTG }
};

/* pwr_type: SP_BST */
const struct wltx_pwr_attr g_attr3[] = {
	{ PWR_SW_BY_VBUS_ON, false, PWR_SRC_SPBST },
	{ PWR_SW_BY_VBUS_OFF, false, PWR_SRC_SPBST },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_SPBST },
	{ PWR_SW_BY_OTG_OFF, false, PWR_SRC_SPBST }
};

/* pwr_type: 5VBST */
const struct wltx_pwr_attr g_attr4[] = {
	{ PWR_SW_BY_VBUS_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_VBUS_OFF, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_OFF, false, PWR_SRC_5VBST }
};

/* pwr_type: 5VBST_VBUS_OTG_CP */
const struct wltx_pwr_attr g_attr5[] = {
	{ PWR_SW_BY_VBUS_ON, true, PWR_SRC_5VBST },
	{ PWR_SW_BY_VBUS_OFF, true, PWR_SRC_OTG_CP },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_OFF, true, PWR_SRC_OTG_CP },
	{ PWR_SW_BY_DC_DONE, true, PWR_SRC_VBUS_CP }
};

/* pwr_type: 5VBST_OTG_PMU_VBUS */
const struct wltx_pwr_attr g_attr6[] = {
	{ PWR_SW_BY_VBUS_ON, true, PWR_SRC_5VBST },
	{ PWR_SW_BY_VBUS_OFF, true, PWR_SRC_PMU },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_OFF, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_DC_DONE, true, PWR_SRC_VBUS_CP}
};

/* pwr_type: 5VBST_OTG_VBUS_CP */
const struct wltx_pwr_attr g_attr7[] = {
	{ PWR_SW_BY_VBUS_ON, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_VBUS_OFF, true, PWR_SRC_5VBST },
	{ PWR_SW_BY_OTG_ON, false, PWR_SRC_OTG },
	{ PWR_SW_BY_OTG_OFF, false, PWR_SRC_5VBST },
	{ PWR_SW_BY_DC_DONE, true, PWR_SRC_VBUS_CP_7P5}
};

static struct {
	enum wltx_pwr_type type;
	const char *name;
	const struct wltx_pwr_attr *attr;
	int size;
} const g_pwr_ctrl[] = {
	{ WL_TX_PWR_VBUS_OTG, "VBUS_OTG", g_attr1, ARRAY_SIZE(g_attr1) },
	{ WL_TX_PWR_5VBST_OTG, "5VBST_OTG", g_attr2, ARRAY_SIZE(g_attr2) },
	{ WL_TX_PWR_SPBST, "SP-BST", g_attr3, ARRAY_SIZE(g_attr3) },
	{ WL_TX_PWR_5VBST, "5VBST", g_attr4, ARRAY_SIZE(g_attr4) },
	{ WL_TX_PWR_5VBST_VBUS_OTG_CP, "5VBST_VBUS_OTG_CP",
		g_attr5, ARRAY_SIZE(g_attr5) },
	{ WL_TX_PWR_5VBST_OTG_PMU_VBUS_CP, "5VBST_OTG_PMU_VBUS_CP", g_attr6, ARRAY_SIZE(g_attr6) },
	{ WL_TX_PWR_5VBST_OTG_VBUS_CP, "5VBST_OTG_VBUS_CP", g_attr7, ARRAY_SIZE(g_attr7) },
};

struct wltx_pwr_ctrl_info *wltx_get_pwr_ctrl_info(void)
{
	return &g_pwr_ctrl_di;
}

const char *wltx_get_pwr_type_name(enum wltx_pwr_type type)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(g_pwr_ctrl); i++) {
		if (type == g_pwr_ctrl[i].type)
			return g_pwr_ctrl[i].name;
	}
	return "NA";
}

const char *wltx_get_pwr_sw_scn_name(enum wltx_pwr_sw_scene scn)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(g_pwr_sw_scn); i++) {
		if (scn == g_pwr_sw_scn[i].scn)
			return g_pwr_sw_scn[i].name;
	}
	return "NA";
}

static const struct wltx_pwr_attr *wltx_get_pwr_attr(enum wltx_pwr_type type,
	enum wltx_pwr_sw_scene scn)
{
	int t_id, s_id;

	for (t_id = 0; t_id < ARRAY_SIZE(g_pwr_ctrl); t_id++) {
		if (type == g_pwr_ctrl[t_id].type)
			break;
	}
	if (t_id >= ARRAY_SIZE(g_pwr_ctrl))
		return NULL;

	for (s_id = 0; s_id < g_pwr_ctrl[t_id].size; s_id++) {
		if (scn == g_pwr_ctrl[t_id].attr[s_id].scn)
			return &g_pwr_ctrl[t_id].attr[s_id];
	}

	return NULL;
}

static enum wltx_pwr_src wltx_get_pwr_src_by_type_scn(
	enum wltx_pwr_type type, enum wltx_pwr_sw_scene scn)
{
	const struct wltx_pwr_attr *attr = wltx_get_pwr_attr(type, scn);

	if (!attr)
		return PWR_SRC_NA;

	return attr->src;
}

bool wltx_need_switch_power(enum wltx_pwr_type type,
	enum wltx_pwr_sw_scene scn, enum wltx_pwr_src cur_src)
{
	const struct wltx_pwr_attr *attr = wltx_get_pwr_attr(type, scn);

	if (!attr)
		return false;

	return attr->need_sw && (cur_src != attr->src);
}

bool wltx_need_disable_wired_dc(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return false;

	if (di->pwr_type != WL_TX_PWR_VBUS_OTG)
		return false;
	if (!wireless_tx_get_tx_open_flag())
		return false;

	return true;
}

static void wltx_pre_pwr_supply(struct wireless_tx_device_info *di, bool flag)
{
	if (!di || !di->tx_ops || !di->tx_ops->pre_ps)
		return;

	di->tx_ops->pre_ps(flag);
}

void wltx_activate_tx_chip(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di || !di->tx_ops || !di->tx_ops->activate_tx_chip)
		return;

	di->tx_ops->activate_tx_chip();
}

static void wltx_check_dc_done(struct wireless_tx_device_info *di)
{
	int soc;

	soc = huawei_battery_capacity();
	if (soc >= di->tx_high_pwr_soc) {
		g_pwr_ctrl_di.dc_done = true;
		direct_charge_set_disable_flags(DC_SET_DISABLE_FLAGS,
			DC_DISABLE_WIRELESS_TX);
	} else if (soc <= (di->tx_high_pwr_soc - WL_TX_HI_PWR_SOC_BACK)) {
		g_pwr_ctrl_di.dc_done = false;
	}
}

static void wltx_update_pwr_scn(struct wireless_tx_device_info *di)
{
	static struct power_supply *usb_psy;
	union power_supply_propval pval = {0, };

	if (di->pwr_type != WL_TX_PWR_5VBST_OTG_PMU_VBUS_CP &&
		di->pwr_type != WL_TX_PWR_5VBST_OTG_VBUS_CP &&
		di->pwr_type != WL_TX_PWR_5VBST_VBUS_OTG_CP)
		return;
	usb_psy = power_supply_get_by_name("usb");
	if (!usb_psy) {
		hwlog_err("%s: get usb power supply failed\n", __func__);
		return;
	}
	power_supply_get_property(usb_psy, POWER_SUPPLY_PROP_ONLINE, &pval);

	if (!pval.intval) {
		hwlog_info("%s PWR_SW_BY_VBUS_OFF\n", __func__);
		di->cur_pwr_sw_scn = PWR_SW_BY_VBUS_OFF;
	} else {
		di->cur_pwr_sw_scn = PWR_SW_BY_VBUS_ON;
		wltx_check_dc_done(di);
		if (g_pwr_ctrl_di.dc_done)
			di->cur_pwr_sw_scn = PWR_SW_BY_DC_DONE;
	}
	schedule_delayed_work(&g_pwr_ctrl_di.mon_dc_work,
		msecs_to_jiffies(WLTX_MON_DC_ADP_INTERVAL));
}

int wltx_enable_pwr_supply(void)
{
	int ret;
	enum wltx_pwr_src src;
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return -EPERM;

	wltx_pre_pwr_supply(di, true);
	wltx_update_pwr_scn(di);
	/* delay 500ms to avoid state disorder in case of quick open/close */
	ret = wltx_msleep(500);
	if (ret) {
		wltx_pre_pwr_supply(di, false);
		return ret;
	}

	hwlog_info("[%s] before, pwr_sw_scn: %s pwr_src: %s\n",
		__func__, wltx_get_pwr_sw_scn_name(di->cur_pwr_sw_scn),
		wltx_get_pwr_src_name(di->cur_pwr_src));
	src = wltx_get_pwr_src_by_type_scn(di->pwr_type, di->cur_pwr_sw_scn);
	di->cur_pwr_src = wltx_set_pwr_src_output(true, src);
	hwlog_info("[%s] after, pwr_sw_scn: %s, pwr_src: %s\n",
		__func__, wltx_get_pwr_sw_scn_name(di->cur_pwr_sw_scn),
		wltx_get_pwr_src_name(di->cur_pwr_src));

	wltx_activate_tx_chip();
	wltx_pre_pwr_supply(di, false);

	return 0;
}

void wltx_disable_pwr_supply(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	hwlog_info("[%s] before, pwr_sw_scn: %s pwr_src: %s\n",
		__func__, wltx_get_pwr_sw_scn_name(di->cur_pwr_sw_scn),
		wltx_get_pwr_src_name(di->cur_pwr_src));

	di->cur_pwr_src = wltx_set_pwr_src_output(false, di->cur_pwr_src);

	hwlog_info("[%s] after, pwr_sw_scn: %s, pwr_src: %s\n",
		__func__, wltx_get_pwr_sw_scn_name(di->cur_pwr_sw_scn),
		wltx_get_pwr_src_name(di->cur_pwr_src));
}

static void wltx_5vbst_otg_extra_pwr(struct wireless_tx_device_info *di)
{
	enum wltx_pwr_src expected_src =
		wltx_get_pwr_src_by_type_scn(di->pwr_type, di->cur_pwr_sw_scn);

	if (expected_src == PWR_SRC_OTG) {
		di->cur_pwr_src = wltx_set_pwr_src_output(false, PWR_SRC_OTG);
		msleep(20); /* delay 20ms for otg pwr_off */
		di->cur_pwr_src = wltx_set_pwr_src_output(true, PWR_SRC_5VBST);
	}
}

static void wltx_5vbst_vbus_otg_cp_extra_pwr(struct wireless_tx_device_info *di)
{
}

void wltx_enable_extra_pwr_supply(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	switch (di->pwr_type) {
	case WL_TX_PWR_5VBST_OTG:
		wltx_5vbst_otg_extra_pwr(di);
		break;
	case WL_TX_PWR_5VBST_VBUS_OTG_CP:
		wltx_5vbst_vbus_otg_cp_extra_pwr(di);
		break;
	default:
		break;
	}
}

void wltx_disable_all_pwr(void)
{
	int i;
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	for (i = PWR_SW_SCN_BEGIN; i < PWR_SW_SCN_END; i++) {
		di->cur_pwr_src = wltx_get_pwr_src_by_type_scn(di->pwr_type, i);
		wltx_disable_pwr_supply();
	}
}

enum wltx_pwr_type wltx_get_pwr_type(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return WL_TX_PWR_END;

	return di->pwr_type;
}

void wireless_tx_cancel_work(enum wltx_pwr_sw_scene pwr_sw_scn)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	if (pwr_sw_scn == PWR_SW_BY_VBUS_OFF) {
		g_pwr_ctrl_di.dc_done = false;
		g_pwr_ctrl_di.charger_type = WLTX_UNKOWN_CHARGER;
	}

	if (!wireless_tx_get_tx_open_flag())
		return;

	if (wltx_need_switch_power(di->pwr_type, pwr_sw_scn, di->cur_pwr_src))
		wltx_cancle_work_handler();
}

void wireless_tx_restart_check(enum wltx_pwr_sw_scene pwr_sw_scn)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	di->cur_pwr_sw_scn = pwr_sw_scn;
	if (!wireless_tx_get_tx_open_flag())
		return;

	if (wltx_need_switch_power(di->pwr_type, pwr_sw_scn, di->cur_pwr_src))
		wltx_restart_work_handler();
}

static void wltx_switch_pwr_src(enum wltx_pwr_sw_scene pwr_sw_scn)
{
	wireless_tx_cancel_work(pwr_sw_scn);
	wireless_tx_restart_check(pwr_sw_scn);
}


static void wltx_monitor_dc_work(struct work_struct *work)
{
	static struct power_supply *usb_psy;
	union power_supply_propval pval = {0, };
	struct wireless_tx_device_info *di = wltx_get_dev_info();

	if (!di)
		return;

	if (!wireless_tx_get_tx_open_flag())
		return;

	usb_psy = power_supply_get_by_name("usb");
	if (!usb_psy) {
		hwlog_err("%s: get usb power supply failed\n", __func__);
		return;
	}
	power_supply_get_property(usb_psy, POWER_SUPPLY_PROP_ONLINE, &pval);

	// switch to pmu
	if (!pval.intval) {
		if (di->cur_pwr_sw_scn != PWR_SW_BY_VBUS_OFF) {
			hwlog_info("%s: wltx_switch_pwr_src by PWR_SW_BY_VBUS_OFF", __func__);
			wltx_switch_pwr_src(PWR_SW_BY_VBUS_OFF);
		}
	} else {
		wltx_check_dc_done(di);

		if (g_pwr_ctrl_di.dc_done &&
			di->cur_pwr_sw_scn != PWR_SW_BY_DC_DONE) {
			hwlog_info("%s: wltx_switch_pwr_src by PWR_SW_BY_DC_DONE", __func__);
			wltx_switch_pwr_src(PWR_SW_BY_DC_DONE);
		} else if (!g_pwr_ctrl_di.dc_done &&
			di->cur_pwr_sw_scn != PWR_SW_BY_VBUS_ON) {
			hwlog_info("%s: wltx_switch_pwr_src by PWR_SW_BY_VBUS_ON", __func__);
			wltx_switch_pwr_src(PWR_SW_BY_VBUS_ON);
		}
	}
	schedule_delayed_work(&g_pwr_ctrl_di.mon_dc_work,
		msecs_to_jiffies(WLTX_MON_DC_ADP_INTERVAL));
}

void wltx_reset_dc_charger_type(struct wireless_tx_device_info *di, int type)
{
	if (type == WLTX_SC_HI_PWR2_CHARGER) {
		if (!(di->tx_cap.cap_mode & WLTX_CAP_HIGH_PWR2))
			type = WLTX_SC_HI_PWR_CHARGER;
	}

	if (type == WLTX_SC_HI_PWR_CHARGER) {
		if (!(di->tx_cap.cap_mode & WLTX_CAP_HIGH_PWR))
			type = WLTX_SC_LOW_PWR_CHARGER;
	}

	g_pwr_ctrl_di.charger_type = type;
	hwlog_info("[reset_dc_charger_type] type=%d\n", type);
}

void wltx_set_dc_charger_type(struct wireless_tx_device_info *di)
{
	int adp_vmax;
	int adp_imax;

	if (dc_get_adapter_max_voltage(&adp_vmax)) {
		hwlog_err("set_dc_charger_type: get vmax fail\n");
		return;
	}

	hwlog_info("[set_dc_charger_type] scp charger, vmax=%d\n", adp_vmax);
	if (adp_vmax >= WIRELESS_ADAPTER_9V) {
		adp_imax = dc_get_adapter_max_current(WIRELESS_ADAPTER_9V);
		hwlog_info("[set_dc_charger_type] scp charger, imax=%d\n", adp_imax);
		if (adp_imax >= WLTX_HIGH_PWR_SC_MIN_IOUT) {
			wltx_reset_dc_charger_type(di, WLTX_SC_HI_PWR2_CHARGER);
			return;
		}
	}
	if (adp_vmax >= WIRELESS_ADAPTER_5V) {
		adp_imax = dc_get_adapter_max_current(WIRELESS_ADAPTER_5V);
		hwlog_info("[set_dc_charger_type] scp charger, imax=%d\n", adp_imax);
		if (adp_imax >= WLTX_HIGH_PWR_SC_MIN_IOUT) {
			wltx_reset_dc_charger_type(di, WLTX_SC_HI_PWR_CHARGER);
			return;
		}
	}

	wltx_reset_dc_charger_type(di, WLTX_SC_LOW_PWR_CHARGER);
}

void wltx_dc_adaptor_handler(void)
{
	struct wireless_tx_device_info *di = wltx_get_dev_info();
	if (!di) {
		hwlog_info("[wltx_dc_adaptor_handler] di is null\n");
		return;
	}
	if ((di->pwr_type != WL_TX_PWR_5VBST_VBUS_OTG_CP) &&
		(di->pwr_type != WL_TX_PWR_5VBST_OTG_PMU_VBUS_CP)) {
		hwlog_info("[wltx_dc_adaptor_handler] di->pwr_type = %d\n", di->pwr_type);
		return;
	}

	if (g_pwr_ctrl_di.charger_type != WLTX_UNKOWN_CHARGER) {
		hwlog_info("[wltx_dc_adaptor_handler] charger_type = %d\n", g_pwr_ctrl_di.charger_type);
		return;
	}

	wltx_set_dc_charger_type(di);

	if (wireless_tx_get_tx_open_flag())
		wltx_check_dc_done(di);

	schedule_delayed_work(&g_pwr_ctrl_di.mon_dc_work, msecs_to_jiffies(0));
}

static int __init wltx_pwr_ctrl_init(void)
{
	INIT_DELAYED_WORK(&g_pwr_ctrl_di.mon_dc_work, wltx_monitor_dc_work);
	return 0;
}

static void __exit wltx_pwr_ctrl_exit(void)
{
}

device_initcall(wltx_pwr_ctrl_init);
module_exit(wltx_pwr_ctrl_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("wireless tx_pwr_ctrl driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");