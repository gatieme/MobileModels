/*
 * wireless_power_supply.c
 *
 * power supply for wireless charging and reverse charging
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/version.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <chipset_common/hwpower/power_delay.h>
#include <chipset_common/hwpower/boost_5v.h>
#include <chipset_common/hwpower/wireless_charge/wireless_power_supply.h>
#include <huawei_platform/power/wireless/wireless_charger.h>
#include <chipset_common/hwpower/power_dts.h>
#include <chipset_common/hwpower/power_gpio.h>
#include <chipset_common/hwpower/charge_pump.h>
#include <chipset_common/hwpower/power_printk.h>
#include <chipset_common/hwpower/wired_channel_switch.h>

#define HWLOG_TAG wireless_ps
HWLOG_REGIST();

static struct wlps_dev_info *g_wlps_di;
static struct wlps_tx_ops *g_tx_ops;
static bool g_tx_pwr_sw_on;

int wlps_tx_ops_register(struct wlps_tx_ops *ops)
{
	if (!ops || g_tx_ops) {
		hwlog_err("tx_ops_register: di null or already register\n");
		return -WLC_ERR_PARA_NULL;
	}

	g_tx_ops = ops;
	return 0;
}

static void wlps_gpio_read_back(int gpio_num, const char *name)
{
	int value;

	if ((gpio_num <= 0) || !name)
		return;

	value = gpio_get_value(gpio_num);
	hwlog_info("[gpio_read_back] name = %s, value = %d\n", name, value);
}

static void wlps_rxsw_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_rxsw <= 0)
		return;

	if (flag == WLPS_CTRL_ON) {
		if (g_tx_pwr_sw_on) {
			hwlog_err("rxsw_ctrl: tx_pwr_sw on, ignore rx_sw on\n");
			return;
		}
		gpio_set_value(di->gpio_rxsw, di->gpio_rxsw_valid_val);
	} else {
		gpio_set_value(di->gpio_rxsw, !di->gpio_rxsw_valid_val);
	}

	hwlog_info("[rxsw_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_rxsw, "gpio_rxsw");
}

static void wlps_rxsw_aux_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_rxsw_aux <= 0)
		return;

	if (flag == WLPS_CTRL_ON)
		gpio_set_value(di->gpio_rxsw_aux, di->gpio_rxsw_aux_valid_val);
	else
		gpio_set_value(di->gpio_rxsw_aux, !di->gpio_rxsw_aux_valid_val);

	hwlog_info("[rxsw_aux_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_rxsw_aux, "gpio_rxsw_aux");
}

static void wlps_txsw_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_txsw <= 0)
		return;

	if (flag == WLPS_CTRL_ON)
		gpio_set_value(di->gpio_txsw, di->gpio_txsw_valid_val);
	else
		gpio_set_value(di->gpio_txsw, !di->gpio_txsw_valid_val);

	hwlog_info("[txsw_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_txsw, "gpio_txsw");
}

static void wlps_tx_pmu_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	if (flag == WLPS_CTRL_ON) {
		wired_chsw_set_wired_channel_wireless(WIRED_CHANNEL_ALL, WIRED_CHANNEL_CUTOFF);
		gpio_set_value(di->gpio_rxsw, di->gpio_rxsw_valid_val);
	} else {
		wired_chsw_set_wired_channel_wireless(WIRED_CHANNEL_ALL, WIRED_CHANNEL_RESTORE);
		gpio_set_value(di->gpio_rxsw, !di->gpio_rxsw_valid_val);
	}
	hwlog_info("[rxsw_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_rxsw, "gpio_rxsw");
}

static void  wlps_tx_vbus_ctrl(struct wlps_dev_info *di, int flag) {
	if (di->gpio_txsw <= 0 || di->gpio_rxsw <= 0)
		return;

	if (flag == WLPS_CTRL_ON) {
		gpio_set_value(di->gpio_txsw, !di->gpio_txsw_valid_val);
		gpio_set_value(di->gpio_rxsw, di->gpio_rxsw_valid_val);
	}
	else {
		gpio_set_value(di->gpio_txsw, di->gpio_txsw_valid_val);
		gpio_set_value(di->gpio_rxsw, !di->gpio_rxsw_valid_val);
	}

	hwlog_info("[txsw_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "off" : "on");
	hwlog_info("[rxsw_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_rxsw, "gpio_rxsw");
	wlps_gpio_read_back(di->gpio_txsw, "gpio_txsw");

}

static void wlps_sc_sw2_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_sc_sw2 <= 0)
		return;

	if (flag == WLPS_CTRL_ON)
		gpio_set_value(di->gpio_sc_sw2, di->gpio_sc_sw2_valid_val);
	else
		gpio_set_value(di->gpio_sc_sw2, !di->gpio_sc_sw2_valid_val);

	hwlog_info("[sc_sw2_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_sc_sw2, "gpio_sc_sw2");
}

static void wlps_rx_ext_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_ext_pwr_sw <= 0)
		return;

	if (flag == WLPS_CTRL_ON) {
		wlc_rx_ext_pwr_prev_ctrl(WLPS_CTRL_ON);
		boost_5v_enable(BOOST_5V_ENABLE, BOOST_CTRL_WLC);
		power_usleep(DT_USLEEP_10MS);
		gpio_set_value(di->gpio_ext_pwr_sw, di->gpio_ext_pwr_sw_valid_val);
		wlc_rx_ext_pwr_post_ctrl(WLPS_CTRL_ON);
	} else {
		wlc_rx_ext_pwr_post_ctrl(WLPS_CTRL_OFF);
		gpio_set_value(di->gpio_ext_pwr_sw, !di->gpio_ext_pwr_sw_valid_val);
		power_usleep(DT_USLEEP_10MS);
		boost_5v_enable(BOOST_5V_DISABLE, BOOST_CTRL_WLC);
		wlc_rx_ext_pwr_prev_ctrl(WLPS_CTRL_OFF);
	}

	hwlog_info("[rx_ext_pwr_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_ext_pwr_sw, "gpio_ext_pwr_sw");
}

static void wlps_tx_sp_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	if (di->gpio_tx_sppwr_en <= 0)
		return;

	if (flag == WLPS_CTRL_ON) {
		g_tx_pwr_sw_on = true;
		wlps_rxsw_ctrl(di, WLPS_CTRL_OFF);
		gpio_set_value(di->gpio_txsw, di->gpio_txsw_valid_val);
		power_usleep(DT_USLEEP_10MS);
		gpio_set_value(di->gpio_tx_sppwr_en, di->gpio_tx_sppwr_en_valid_val);
	} else {
		g_tx_pwr_sw_on = false;
		gpio_set_value(di->gpio_txsw, !di->gpio_txsw_valid_val);
		power_usleep(DT_USLEEP_10MS);
		gpio_set_value(di->gpio_tx_sppwr_en, !di->gpio_tx_sppwr_en_valid_val);
	}

	hwlog_info("[tx_sp_pwr_ctrl] %s\n", (flag == WLPS_CTRL_ON) ? "on" : "off");
	wlps_gpio_read_back(di->gpio_tx_sppwr_en, "gpio_tx_sppwr_en");
	wlps_gpio_read_back(di->gpio_txsw, "gpio_txsw");
}

static void wlps_proc_otp_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	switch (di->proc_otp_pwr) {
	case WLPS_CHIP_PWR_NULL:
		wlps_rxsw_ctrl(di, flag);
		break;
	case WLPS_CHIP_PWR_RX:
		wlps_rx_ext_pwr_ctrl(di, flag);
		break;
	case WLPS_CHIP_PWR_TX:
		wlps_tx_sp_pwr_ctrl(di, flag);
		break;
	default:
		hwlog_err("proc_otp_pwr_ctrl: 0x%x\n", di->proc_otp_pwr);
		break;
	}
}

static void wlps_recover_otp_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	switch (di->recover_otp_pwr) {
	case WLPS_CHIP_PWR_RX:
		wlps_rx_ext_pwr_ctrl(di, flag);
		break;
	case WLPS_CHIP_PWR_TX:
		wlps_tx_sp_pwr_ctrl(di, flag);
		break;
	default:
		hwlog_err("recover_otp_pwr_ctrl: 0x%x\n", di->recover_otp_pwr);
		break;
	}
}

static void wlps_sysfs_en_pwr_ctrl(struct wlps_dev_info *di, int flag)
{
	switch (di->sysfs_en_pwr) {
	case WLPS_CHIP_PWR_NULL:
		wlps_rxsw_ctrl(di, flag);
		break;
	case WLPS_CHIP_PWR_RX:
		wlps_rx_ext_pwr_ctrl(di, flag);
		break;
	case WLPS_CHIP_PWR_TX:
		wlps_tx_sp_pwr_ctrl(di, flag);
		break;
	default:
		hwlog_err("sysfs_en_pwr_ctrl: 0x%x\n", di->sysfs_en_pwr);
		break;
	}
}

void wlps_control(enum wlps_ctrl_scene scene, int ctrl_flag)
{
	struct wlps_dev_info *di = g_wlps_di;

	if (!di) {
		hwlog_err("control: di null\n");
		return;
	}

	switch (scene) {
	case WLPS_PROBE_PWR:
		wlps_rx_ext_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_SYSFS_EN_PWR:
		wlps_sysfs_en_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_PROC_OTP_PWR:
		wlps_proc_otp_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_RECOVER_OTP_PWR:
		wlps_recover_otp_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_RX_EXT_PWR:
		wlps_rx_ext_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_TX_PWR_SW:
		wlps_tx_sp_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_RX_SW:
		wlps_rxsw_ctrl(di, ctrl_flag);
		break;
	case WLPS_RX_SW_AUX:
		wlps_rxsw_aux_ctrl(di, ctrl_flag);
		break;
	case WLPS_TX_SW:
		wlps_txsw_ctrl(di, ctrl_flag);
		break;
	case WLPS_SC_SW2:
		wlps_sc_sw2_ctrl(di, ctrl_flag);
		break;
	case WLPS_TX_PMU_SW:
		wlps_tx_pmu_pwr_ctrl(di, ctrl_flag);
		break;
	case WLPS_TX_VBUS_SW:
		wlps_tx_vbus_ctrl(di, ctrl_flag);
		break;
	default:
		hwlog_err("control: 0x%x\n", scene);
		break;
	}
}

int wlps_tx_mode_vset(int tx_vset)
{
	struct wlps_tx_ops *tx_ops = g_tx_ops;

	if (!tx_ops || !tx_ops->tx_vset)
		return -WLC_ERR_PARA_NULL;

	hwlog_info("[tx_mode_vset] vset:%dmV\n", tx_vset);
	return tx_ops->tx_vset(tx_vset);
}

static int wlps_tx_sw_gpio_init(struct device_node *np, struct wlps_dev_info *di)
{
	int ret;

	di->gpio_txsw = of_get_named_gpio(np, "gpio_txsw", 0);
	hwlog_info("[tx_sw_gpio_init] gpio_txsw = %d\n", di->gpio_txsw);
	if (di->gpio_txsw <= 0) {
		hwlog_err("%s: gpio init fail defer\n", __func__);
		return di->gpio_txsw;
	}
	if (!gpio_is_valid(di->gpio_txsw)) {
		hwlog_err("tx_sw_gpio_init: gpio_txsw is not valid\n");
		di->gpio_txsw = 0;
		return -EINVAL;
	}
	ret = gpio_request(di->gpio_txsw, "wireless_txsw");
	if (ret) {
		hwlog_err("tx_sw_gpio_init: could not request gpio_txsw\n");
		return -ENOMEM;
	}

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"gpio_txsw_valid_val", (u32 *)&di->gpio_txsw_valid_val, 1);

	ret = gpio_direction_output(di->gpio_txsw, !di->gpio_txsw_valid_val);
	if (ret)
		hwlog_err("tx_sw_gpio_init: gpio_dir_output fail\n");

	return 0;
}

static int wlps_tx_sppwr_gpio_init(struct device_node *np, struct wlps_dev_info *di)
{
	int ret;

	di->gpio_tx_sppwr_en = of_get_named_gpio(np, "gpio_tx_sppwr_en", 0);
	hwlog_info("[tx_sppwr_gpio_init] gpio_tx_sppwr_en = %d\n", di->gpio_tx_sppwr_en);
	if (di->gpio_tx_sppwr_en <= 0)
		return 0;

	if (!gpio_is_valid(di->gpio_tx_sppwr_en)) {
		hwlog_err("tx_sppwr_gpio_init: gpio_tx_sppwr_en is not valid\n");
		di->gpio_tx_sppwr_en = 0;
		return -EINVAL;
	}
	ret = gpio_request(di->gpio_tx_sppwr_en, "wireless_tx_sppwr_en");
	if (ret) {
		hwlog_err("tx_sppwr_gpio_init: could not request gpio_tx_sppwr_en\n");
		return -ENOMEM;
	}

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"gpio_tx_sppwr_en_valid_val", (u32 *)&di->gpio_tx_sppwr_en_valid_val, 1);

	ret = gpio_direction_output(di->gpio_tx_sppwr_en, !di->gpio_tx_sppwr_en_valid_val);
	if (ret)
		hwlog_err("tx_sppwr_gpio_init: gpio_dir_output fail\n");

	return 0;
}

static int wlps_rx_sw_gpio_init(struct device_node *np, struct wlps_dev_info *di)
{
	int ret;

	di->gpio_rxsw = of_get_named_gpio(np, "gpio_rxsw", 0);
	hwlog_info("[rx_sw_gpio_init] gpio_rxsw = %d\n", di->gpio_rxsw);
	if (di->gpio_rxsw <= 0)
		return 0;
	if (!gpio_is_valid(di->gpio_rxsw)) {
		hwlog_err("gpio_rxsw is not valid\n");
		di->gpio_rxsw = 0;
		return -EINVAL;
	}
	ret = gpio_request(di->gpio_rxsw, "wireless_rxsw");
	if (ret) {
		hwlog_err("rx_sw_gpio_init: could not request gpio_rxsw\n");
		return -ENOMEM;
	}

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"gpio_rxsw_valid_val", (u32 *)&di->gpio_rxsw_valid_val, 0);

	ret = gpio_direction_output(di->gpio_rxsw, di->gpio_rxsw_valid_val);
	if (ret)
		hwlog_err("rx_sw_gpio_init: gpio_dir_output fail\n");

	if (power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "gpio_rxsw_aux_valid_val",
		(u32 *)&di->gpio_rxsw_aux_valid_val, 0))
		return 0;

	if (power_gpio_config_output(np, "gpio_rxsw_aux", "wireless_rxsw_aux",
		&di->gpio_rxsw_aux, !di->gpio_rxsw_aux_valid_val)) {
		gpio_free(di->gpio_rxsw);
		return -EINVAL;
	}

	return 0;
}

static int wlps_ext_pwr_sw_gpio_init(struct device_node *np, struct wlps_dev_info *di)
{
	int ret;

	di->gpio_ext_pwr_sw = of_get_named_gpio(np, "gpio_ext_pwr_sw", 0);
	hwlog_info("[ext_pwr_sw_gpio_init] gpio_ext_pwr_sw = %d\n", di->gpio_ext_pwr_sw);
	if (di->gpio_ext_pwr_sw <= 0)
		return 0;

	if (!gpio_is_valid(di->gpio_ext_pwr_sw)) {
		hwlog_err("ext_pwr_sw_gpio_init: gpio_ext_pwr_sw is not valid\n");
		di->gpio_ext_pwr_sw = 0;
		return -EINVAL;
	}
	ret = gpio_request(di->gpio_ext_pwr_sw, "wireless_ext_pwr_sw");
	if (ret) {
		hwlog_err("ext_pwr_sw_gpio_init: could not request gpio_ext_pwr_sw\n");
		return -ENOMEM;
	}

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "gpio_ext_pwr_sw_valid_val",
		(u32 *)&di->gpio_ext_pwr_sw_valid_val, 1);

	ret = gpio_direction_output(di->gpio_ext_pwr_sw,
		!di->gpio_ext_pwr_sw_valid_val);
	if (ret)
		hwlog_err("ext_pwr_sw_gpio_init: gpio_dir_output fail\n");

	return 0;
}

static int wlps_sc_sw2_gpio_init(struct device_node *np, struct wlps_dev_info *di)
{
	if (power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"gpio_sc_sw2_valid_val", (u32 *)&di->gpio_sc_sw2_valid_val, 0))
		return 0;

	if (power_gpio_config_output(np, "gpio_sc_sw2", "wireless_gpio_sc_sw2",
		&di->gpio_sc_sw2, !di->gpio_sc_sw2_valid_val)) {
		di->gpio_sc_sw2 = 0;
		return -EINVAL;
	}

	return 0;
}

static void wlps_parse_dts(struct device_node *np, struct wlps_dev_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sysfs_en_pwr", (u32 *)&di->sysfs_en_pwr, WLPS_CHIP_PWR_NULL);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"proc_otp_pwr", (u32 *)&di->proc_otp_pwr, WLPS_CHIP_PWR_NULL);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"recover_otp_pwr", (u32 *)&di->recover_otp_pwr, WLPS_CHIP_PWR_TX);
}

static void wireless_ps_gpio_free(int gpio_no)
{
	if (gpio_no > 0)
		gpio_free(gpio_no);
}

static int wireless_ps_probe(struct platform_device *pdev)
{
	int ret;
	struct wlps_dev_info *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_wlps_di = di;
	di->dev = &pdev->dev;
	np = pdev->dev.of_node;

	wlps_parse_dts(np, di);

	ret = wlps_tx_sw_gpio_init(np, di);
	if (ret) {
		kfree(di);
		di = NULL;
		g_wlps_di = NULL;
		return ret;
	}
	ret = wlps_tx_sppwr_gpio_init(np, di);
	if (ret)
		goto tx_sppwr_gpio_init_fail;
	ret = wlps_rx_sw_gpio_init(np, di);
	if (ret)
		goto rx_sw_gpio_init_fail;
	ret = wlps_ext_pwr_sw_gpio_init(np, di);
	if (ret)
		goto ext_pwr_sw_gpio_init_fail;
	ret = wlps_sc_sw2_gpio_init(np, di);
	if (ret)
		goto sc_sw2_gpio_init_fail;

	hwlog_info("wireless_ps probe ok\n");
	return 0;

sc_sw2_gpio_init_fail:
	wireless_ps_gpio_free(di->gpio_ext_pwr_sw);
ext_pwr_sw_gpio_init_fail:
	wireless_ps_gpio_free(di->gpio_rxsw_aux);
	wireless_ps_gpio_free(di->gpio_rxsw);
rx_sw_gpio_init_fail:
	wireless_ps_gpio_free(di->gpio_tx_sppwr_en);
tx_sppwr_gpio_init_fail:
	wireless_ps_gpio_free(di->gpio_txsw);
	kfree(di);
	di = NULL;
	g_wlps_di = NULL;
	hwlog_info("wireless_ps probe fail\n");
	return ret;
}

static void wireless_ps_shutdown(struct platform_device *pdev)
{
	wlps_control(WLPS_TX_PWR_SW, WLPS_CTRL_OFF);
	charge_pump_chip_enable(CP_TYPE_MAIN, false);
	wlps_control(WLPS_RX_SW, WLPS_CTRL_OFF);
}

static const struct of_device_id wlps_match_table[] = {
	{
		.compatible = "huawei,wireless_ps",
		.data = NULL,
	},
	{},
};

static struct platform_driver wlps_driver = {
	.probe = wireless_ps_probe,
	.shutdown = wireless_ps_shutdown,
	.driver = {
		.owner = THIS_MODULE,
		.name = "wireless_ps",
		.of_match_table = of_match_ptr(wlps_match_table),
	},
};

static int __init wireless_ps_init(void)
{
	return platform_driver_register(&wlps_driver);
}

static void __exit wireless_ps_exit(void)
{
	platform_driver_unregister(&wlps_driver);
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
device_initcall_sync(wireless_ps_init);
#else
fs_initcall_sync(wireless_ps_init);
#endif

module_exit(wireless_ps_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("wireless power supply module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");