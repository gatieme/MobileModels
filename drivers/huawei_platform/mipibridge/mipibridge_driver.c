/*
 * Huawei mipibridge core code
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#include "mipibridge.h"
#include "jw/hv6100.h"

struct mipibridge_device_info g_bridge_dev = {0};

/* mipibridge log */
static int g_mipibridge_log_mask = MIPIBRIDGE_LOG_INFO;

static struct mipibridge_panel_map panel_map[] = {
	{ PANEL_HV6100, hv6100_probe },
};

int mipibridge_log_level(void)
{
	return g_mipibridge_log_mask;
}

int mipibridge_parse_u32(const struct device_node *np, const char *prop_name,
	unsigned int *out, unsigned int def)
{
	unsigned int temp = 0;

	if (!np || !out || !prop_name) {
		mipibridge_errmsg("pointer is null\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (of_property_read_u32(np, prop_name, &temp)) {
		*out = def;
		mipibridge_errmsg("of_property_read: %s not find, val = %d\n", prop_name, *out);
		return MIPI_BRIDGE_FAIL;
	}
	*out = temp;
	return MIPI_BRIDGE_OK;
}

static int mipibridge_parse_string(const struct device_node *np, const char *prop_name,
	const char **out_strs)
{
	if (!np || !prop_name || !out_strs) {
		mipibridge_errmsg("pointer is null\n");
		return MIPI_BRIDGE_FAIL;
	}

	return of_property_read_string(np, prop_name, out_strs);
}

static void mipibridge_upgrade_firmware_work(struct work_struct *work)
{
	mipibridge_infomsg("start upgrade work \n");
	if (g_bridge_dev.fw.support && g_bridge_dev.fw.fw_update) {
		g_bridge_dev.fw.time.start = ktime_get();
		g_bridge_dev.fw.status = FIRMWARE_UPGRADE_DOING;
		g_bridge_dev.fw.status = g_bridge_dev.fw.fw_update(g_bridge_dev.dev);
		g_bridge_dev.fw.time.end = ktime_get();
		g_bridge_dev.fw.time.actual_time = ktime_to_ms(ktime_sub(g_bridge_dev.fw.time.end, g_bridge_dev.fw.time.start));
		mipibridge_infomsg("load actual_time %u ms!\n", (unsigned int)(g_bridge_dev.fw.time.actual_time));
	}

	mipibridge_infomsg("upgrade %s\n",
		(g_bridge_dev.fw.status == FIRMWARE_UPGRADE_SUCC) ? "SUCC" : "FAIL");
}

static ssize_t mipibridge_fw_update_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	if (!dev || !attr || !buf) {
		mipibridge_errmsg("input NULL\n");
		return -EINVAL;
	}

	if (!g_bridge_dev.fw.support) {
		mipibridge_errmsg("not support fw update\n");
		return 0;
	}

	mipibridge_infomsg("upgrade status = %d\n", g_bridge_dev.fw.status);

	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", g_bridge_dev.fw.status);
}

static ssize_t mipibridge_fw_update_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret = 0;
	unsigned int mode = 0;

	if (!dev || !attr || !buf) {
		mipibridge_errmsg("input NULL\n");
		return -EINVAL;
	}

	ret = kstrtouint(buf, 10, &mode);	/* 10:decimal notation */
	if (ret != 0) {
		mipibridge_errmsg("invalid parameter!\n");
		return count;
	}

	mipibridge_infomsg("mode=%d\n", mode);

	if (mode != UPGRADE_MODE_NORAML_UPGRADE) {
		mipibridge_errmsg("error cmd mode = %d\n", mode);
		return count;
	}

	if (!g_bridge_dev.fw.support) {
		mipibridge_errmsg("not support fw update\n");
		return count;
	}

	if (g_bridge_dev.fw.status == FIRMWARE_UPGRADE_DOING) {
		mipibridge_errmsg("upgrade doing! ignore this cmd\n");
		return count;
	}

	if (!g_bridge_dev.fw.open_fw) {
		mipibridge_errmsg("open_fw is NULL!\n");
		return count;
	}

	ret = g_bridge_dev.fw.open_fw(dev);
	if (ret) {
		mipibridge_errmsg("read firmware err!\n");
		g_bridge_dev.fw.status = FIRMWARE_NOT_FIND_FW;
		return count;
	}

	schedule_work(&g_bridge_dev.fw.upgrade_work);

	return count;
}

static DEVICE_ATTR(firmware_upgrade, 0644,
	mipibridge_fw_update_show, mipibridge_fw_update_store);

static struct attribute *mipibridge_attributes[] = {
	&dev_attr_firmware_upgrade.attr,
	NULL
};

static const struct attribute_group mipibridge_attr_group = {
	.attrs = mipibridge_attributes,
};

static int mipibridge_panel_init(void)
{
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(panel_map); i++) {
		if (!strncmp(g_bridge_dev.device, panel_map[i].device, strlen(g_bridge_dev.device))) {
			panel_map[i].callback(&g_bridge_dev);
			break;
		}
	}

	if (i >= ARRAY_SIZE(panel_map))
		mipibridge_errmsg("not find adapter ops\n");
	return MIPI_BRIDGE_OK;
}

static int mipibridge_parse_config(struct device_node *node)
{
	int id = 0;
	int device_num = 0;

	if (!node) {
		mipibridge_errmsg("node is NULL\n");
		return -ENODEV;
	}

	mipibridge_parse_u32(node, "id_pin", &g_bridge_dev.id_pin, 0);
	mipibridge_parse_u32(node, "uart_support", &g_bridge_dev.uart.support, 0);
	if (g_bridge_dev.uart.support) {
		mipibridge_parse_u32(node, "uart_recv_support", &g_bridge_dev.uart.uart_recv_support, 0);
		mipibridge_parse_u32(node, "uart_default_baud", &g_bridge_dev.uart.default_baud, 115200); // 115200:uart default baud
		mipibridge_parse_string(node, "uart_name", &g_bridge_dev.uart.tty_name);
	}
	mipibridge_parse_u32(node, "update_fw_support", &g_bridge_dev.fw.support, 0);

	if (g_bridge_dev.id_pin) {
		gpio_request_one(g_bridge_dev.id_pin, GPIOF_IN, "id_pin");
		id = gpio_get_value(g_bridge_dev.id_pin);
	}
	/* get devices */
	device_num = of_property_count_strings(node, "bridge_names");
	id = (id < device_num) ? id : 0;
	of_property_read_string_index(node, "bridge_names", id, &g_bridge_dev.device);
	mipibridge_infomsg("mipibridge device is %s\n", g_bridge_dev.device);

	return MIPI_BRIDGE_OK;
}

static int mipibridge_drv_probe(struct platform_device *pdev)
{
	int ret = MIPI_BRIDGE_OK;

	if (!pdev)
		return -ENODEV;

	mipibridge_infomsg("mipibridge_drv_probe enter\n");

	g_bridge_dev.dev = &pdev->dev;
	ret = mipibridge_parse_config(pdev->dev.of_node);
	if (ret) {
		mipibridge_errmsg("parse dts err! ret:%d\n", ret);
		return MIPI_BRIDGE_FAIL;
	}

	if (g_bridge_dev.uart.support) {
		ret = mipibridge_uart_register(&g_bridge_dev.uart);
		if (ret) {
			mipibridge_errmsg("register uart err! ret:%d\n", ret);
			return MIPI_BRIDGE_FAIL;
		}
	}

	if (g_bridge_dev.fw.support) {
		g_bridge_dev.fw.status = FIRMWARE_UPGRADE_DEFAUL;
		INIT_WORK(&g_bridge_dev.fw.upgrade_work, mipibridge_upgrade_firmware_work);
	}

	mipibridge_panel_init();

	ret = sysfs_create_group(&pdev->dev.kobj, &mipibridge_attr_group);
	if (ret < 0) {
		mipibridge_errmsg("sysfs create error %d\n", ret);
		return -EIO;
	}

	return ret;
}

static int mipibridge_drv_remove(struct platform_device *pdev)
{
	mipibridge_infomsg("mipibridge_drv_remove enter\n");
	if (!pdev)
		return -ENODEV;

	return 0;
}

static const struct of_device_id mipibridge_drv_match_table[] = {
	{ .compatible = "huawei,mipibridge", },
	{ },
};

MODULE_DEVICE_TABLE(of, mipibridge_drv_match_table);

struct platform_driver mipibridge_drv = {
	.probe = mipibridge_drv_probe,
	.remove = mipibridge_drv_remove,
	.driver = {
		.name = "mipibridge_drv_platform",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(mipibridge_drv_match_table),
	},
};

static int __init mipibridge_module_init(void)
{
	int ret = 0;
	mipibridge_infomsg("mipibridge_module_init enter\n");
	/* register driver */
	ret = platform_driver_register(&mipibridge_drv);
	if (ret)
		mipibridge_errmsg("platform_driver_register failed, error=%d!\n", ret);
	return ret;
}

static void __exit mipibridge_module_exit(void)
{
	mipibridge_infomsg("mipibridge_module_exit enter\n");
	platform_driver_unregister(&mipibridge_drv);
}

module_init(mipibridge_module_init);
module_exit(mipibridge_module_exit);
MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei mipibridge");
MODULE_LICENSE("GPL v2");
