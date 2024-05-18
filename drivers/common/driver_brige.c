#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/pm_wakeup.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of.h>
#include "driver_brige.h"

struct lcd_kit_ops *g_lcd_kit_ops;
struct ts_kit_ops *g_ts_kit_ops;
struct tpkit_thp_ops *g_tpkit_thp_ops;
struct ud_fp_ops *g_ud_fp_operations;
struct usb_kit_ops *g_usb_kit_ops;
struct bat_leakage_kit_ops *g_bat_leakage_ops;
struct ud_fp_lcd_ops *g_ud_fp_lcd_operations;
struct bat_heating_ops *g_bat_heating_ops;

int bat_heating_ops_register(struct bat_heating_ops *ops)
{
	if (!g_bat_heating_ops) {
		g_bat_heating_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int bat_heating_ops_unregister(struct bat_heating_ops *ops)
{
	if (g_bat_heating_ops == ops) {
		g_bat_heating_ops = NULL;
		pr_info("%s:ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}

struct bat_heating_ops *bat_heating_get_ops(void)
{
	return g_bat_heating_ops;
}

int usb_kit_ops_register(struct usb_kit_ops *ops)
{
	if (!g_usb_kit_ops) {
		g_usb_kit_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int usb_kit_ops_unregister(struct usb_kit_ops *ops)
{
	if (g_usb_kit_ops == ops) {
		g_usb_kit_ops = NULL;
		pr_info("%s:ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}

struct usb_kit_ops *usb_kit_get_ops(void)
{
	return g_usb_kit_ops;
}

int bat_leakage_kit_ops_register(struct bat_leakage_kit_ops *ops)
{
	if (!g_bat_leakage_ops) {
		g_bat_leakage_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int bat_leakage_kit_ops_unregister(struct bat_leakage_kit_ops *ops)
{
	if (g_bat_leakage_ops == ops) {
		g_bat_leakage_ops = NULL;
		pr_info("%s:ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}

struct bat_leakage_kit_ops *bat_leakage_kit_get_ops(void)
{
	return g_bat_leakage_ops;
}

int lcd_kit_ops_register(struct lcd_kit_ops *ops)
{
	if (!g_lcd_kit_ops) {
		g_lcd_kit_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int lcd_kit_ops_unregister(struct lcd_kit_ops *ops)
{
	if (g_lcd_kit_ops == ops) {
		g_lcd_kit_ops = NULL;
		pr_info("%s:ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}
struct lcd_kit_ops *lcd_kit_get_ops(void)
{
	return g_lcd_kit_ops;
}
/* tp ops, provide to lcd*/
int ts_kit_ops_register(struct ts_kit_ops *ops)
{
	if (!g_ts_kit_ops) {
		g_ts_kit_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int ts_kit_ops_unregister(struct ts_kit_ops *ops)
{
	if (g_ts_kit_ops == ops) {
		g_ts_kit_ops = NULL;
		pr_info("%s: ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}

struct ts_kit_ops *ts_kit_get_ops(void)
{
	return g_ts_kit_ops;
}

int tpkit_ops_register(struct tpkit_thp_ops *ops)
{
	if (!g_tpkit_thp_ops) {
		g_tpkit_thp_ops = ops;
		pr_info("%s: ops register suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops have been registered!\n", __func__);
	return -1;
}

int tpkit_ops_unregister(struct tpkit_thp_ops *ops)
{
	if (g_tpkit_thp_ops == ops) {
		g_tpkit_thp_ops = NULL;
		pr_info("%s: ops unregister suc!\n", __func__);
		return 0;
	}
	pr_err("%s: ops unregister fail!\n", __func__);
	return -1;
}

struct tpkit_thp_ops *tpkit_get_ops(void)
{
	return g_tpkit_thp_ops;
}
void fp_ops_register(struct ud_fp_ops *ops)
{
	if (g_ud_fp_operations == NULL) {
		g_ud_fp_operations = ops;
		pr_info("%s:g_ud_fp_ops register success\n", __func__);
	} else {
		pr_info("%s:g_ud_fp_ops has been registered\n", __func__);
	}
}

void fp_ops_unregister(struct ud_fp_ops *ops)
{
	if (g_ud_fp_operations != NULL) {
		g_ud_fp_operations = NULL;
		pr_info("%s:g_ud_fp_ops_unregister success\n", __func__);
	} else {
		pr_info("%s:g_ud_fp_ops has been unregister\n", __func__);
	}
}

struct ud_fp_ops *fp_get_ops(void)
{
	return g_ud_fp_operations;
}

void ud_lcd_fp_ops_register(struct ud_fp_lcd_ops *ops)
{
	if (g_ud_fp_lcd_operations == NULL) {
		g_ud_fp_lcd_operations = ops;
		pr_info("%s g_ud_fp_lcd register success\n", __func__);
	} else {
		pr_err("%s g_ud_fp_lcd has been registered \n", __func__);
	}
}

void ud_lcd_fp_ops_unregister(struct ud_fp_lcd_ops *ops)
{
	if (g_ud_fp_lcd_operations != NULL) {
		g_ud_fp_lcd_operations = NULL;
		pr_info("%s g_ud_fp_lcd unregister success\n", __func__);
	} else {
		pr_err("%s g_ud_fp_lcd has been unregistered \n", __func__);
	}
}

struct ud_fp_lcd_ops* ud_fp_lcd_get_ops(void)
{
	return g_ud_fp_lcd_operations;
}

EXPORT_SYMBOL(ud_lcd_fp_ops_register);
EXPORT_SYMBOL(ud_lcd_fp_ops_unregister);
EXPORT_SYMBOL(ud_fp_lcd_get_ops);
EXPORT_SYMBOL(bat_heating_ops_register);
EXPORT_SYMBOL(bat_heating_ops_unregister);
EXPORT_SYMBOL(bat_heating_get_ops);
EXPORT_SYMBOL(usb_kit_ops_register);
EXPORT_SYMBOL(usb_kit_ops_unregister);
EXPORT_SYMBOL(usb_kit_get_ops);
EXPORT_SYMBOL(bat_leakage_kit_ops_register);
EXPORT_SYMBOL(bat_leakage_kit_ops_unregister);
EXPORT_SYMBOL(bat_leakage_kit_get_ops);
EXPORT_SYMBOL(fp_ops_register);
EXPORT_SYMBOL(fp_ops_unregister);
EXPORT_SYMBOL(fp_get_ops);
EXPORT_SYMBOL(lcd_kit_ops_register);
EXPORT_SYMBOL(lcd_kit_ops_unregister);
EXPORT_SYMBOL(lcd_kit_get_ops);
EXPORT_SYMBOL(ts_kit_ops_register);
EXPORT_SYMBOL(ts_kit_ops_unregister);
EXPORT_SYMBOL(ts_kit_get_ops);
EXPORT_SYMBOL(tpkit_ops_register);
EXPORT_SYMBOL(tpkit_ops_unregister);
EXPORT_SYMBOL(tpkit_get_ops);
static int brige_probe(struct platform_device *pdev)
{
	pr_info("%s enter\n", __func__);
	return 0;
}

static int brige_remove(struct platform_device *pdev)
{
	pr_info("%s enter\n", __func__);
	return 0;
}

static const struct of_device_id brige_of_match[] = {
	{ .compatible = "honor,brige_driver", },
	{}
};

MODULE_DEVICE_TABLE(of, brige_of_match);

static struct platform_driver brige_driver = {
	.driver = {
		.name     = "honor_brige_driver",
		.owner    = THIS_MODULE,
		.of_match_table = brige_of_match,
	},
	.probe  = brige_probe,
	.remove = brige_remove
};

static int __init brige_init(void)
{
	pr_info("%s enter\n", __func__);
	if (platform_driver_register(&brige_driver))
		return -EINVAL;

	return 0;
}

static void __exit brige_exit(void)
{
	pr_info("%s enter\n", __func__);
	platform_driver_unregister(&brige_driver);
}

module_init(brige_init);
module_exit(brige_exit);

MODULE_LICENSE("GPL");
