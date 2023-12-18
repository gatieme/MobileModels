/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Team:    Huawei DIVS
 * Date:    2021.07.20
 * Description: xhub pm module
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

#include "xhub_pm.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/sysfs.h>
#include <securec.h>
#include <linux/fb.h>
#include <../apsensor_channel/ap_sensor_route.h>
#include <../apsensor_channel/ap_sensor.h>
#include <linux/hrtimer.h>
#include <linux/backlight.h>
#include <linux/completion.h>
#include <linux/err.h>

#include <linux/soc/qcom/panel_event_notifier.h>
#ifdef CONFIG_DRM
#include <drm/drm_panel.h>
struct drm_panel *active_panel[PANEL_MAX];
const char * g_panel_map[PANEL_MAX] = {"huawei,lcd_panel_type", "huawei,sec_lcd_panel_type"};
enum panel_event_notifier_client g_client[PANEL_MAX] = {
	PANEL_EVENT_NOTIFIER_CLIENT_XHUB_PM, PANEL_EVENT_NOTIFIER_CLIENT_SEC_XHUB_PM};

static int xhub_pm_ts_check_dt(sys_panel_t panel_index)
{
	int i, count;
	struct device_node *node;
	struct drm_panel *panel;
	const char * panel_node = g_panel_map[panel_index];
	struct device_node *np = of_find_compatible_node(NULL, NULL, panel_node);
	if (!np) {
		pr_err("%s: panel_node not found\n", __func__);
		return -ENODEV;
	}
	count = of_count_phandle_with_args(np, "panel", NULL);
	pr_info("%s: panel %d count = %d\n", __func__, panel_index, count);
	if (count <= 0)
		return 0;

	for (i = 0; i < count; i++) {
		node = of_parse_phandle(np, "panel", i);
		panel = of_drm_find_panel(node);
		of_node_put(node);
		if (!IS_ERR(panel)) {
			active_panel[panel_index] = panel;
			of_node_put(np);
			pr_err(" %s: panel %d find %d\n", __func__, panel_index, i);
			return 0;
		}
	}
	of_node_put(np);
	pr_err(" %s: panel %d not find\n", __func__, panel_index);
	return PTR_ERR(panel);
}

static void xhub_drm_notifier_callback(enum panel_event_notifier_tag tag,
		 struct panel_event_notification *notification, void *client_data)
{
	struct xhub_pm_dev *xhub_dev = client_data;
	if (!notification) {
		pr_err("%s Invalid notification\n", __func__);
		return;
	}

	switch (notification->notif_type) {
		case DRM_PANEL_EVENT_UNBLANK:
			xhub_dev->pm_buf.ap_status = ST_SCREENON;
			pr_info("%s panel %d screen on\n", __func__, xhub_dev->pm_buf.panel);
			ap_sensor_route_write((char *)&xhub_dev->pm_buf, sizeof(xhub_dev->pm_buf));
			break;
		case DRM_PANEL_EVENT_BLANK:
			xhub_dev->pm_buf.ap_status = ST_SCREENOFF;
			pr_info("%s panel %d screen off\n", __func__, xhub_dev->pm_buf.panel);
			ap_sensor_route_write((char *)&xhub_dev->pm_buf, sizeof(xhub_dev->pm_buf));
			break;
		case DRM_PANEL_EVENT_BLANK_LP:
			xhub_dev->pm_buf.ap_status = ST_SLEEP;
			pr_info("%s panel %d screen off low power\n", __func__, xhub_dev->pm_buf.panel);
			ap_sensor_route_write((char *)&xhub_dev->pm_buf, sizeof(xhub_dev->pm_buf));
			break;
		case DRM_PANEL_EVENT_FPS_CHANGE:
			pr_info("%s panel %d fps change\n", __func__, xhub_dev->pm_buf.panel);
			break;
		default:
			pr_info("%s panel %d notification serviced :%d\n", __func__,
				xhub_dev->pm_buf.panel, notification->notif_type);
			break;
	}
}

static int xhub_panel_register(struct xhub_pm_dev *xhub_dev, sys_panel_t panel_index)
{
	void *cookie = NULL;
	enum panel_event_notifier_tag tag_map[PANEL_MAX] = {
		PANEL_EVENT_NOTIFICATION_PRIMARY, PANEL_EVENT_NOTIFICATION_SECONDARY };
	xhub_dev->pm_buf.sensor_type = SENSOR_TYPE_PM;
	xhub_dev->pm_buf.cmd = 0;
	xhub_dev->pm_buf.subcmd = 0;
	xhub_dev->pm_buf.panel = panel_index;

	cookie = panel_event_notifier_register(
		tag_map[panel_index], g_client[panel_index],
		active_panel[panel_index], &xhub_drm_notifier_callback, xhub_dev);
	if (!cookie) {
		pr_err("Failed to register for panel %d events\n", panel_index);
		return -ENOMEM;
	}
	pr_info("registered for notifications on panel %d: 0x%x\n",
		panel_index, active_panel[panel_index]);

	xhub_dev->notifier_cookie = cookie;
	return 0;
}
#endif

static int xhub_pm_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct xhub_pm_dev *xhub_dev = NULL;
	struct xhub_pm_dev *xhub_dev_sec = NULL;

	if (pdev == NULL) {
		pr_info("%s pdev is NULL\n", __func__);
		return -ENODEV;
	}
	/* primary panel */
	ret = xhub_pm_ts_check_dt(PANEL_PRIMARY);
	if (ret != 0)
		return ret;
	xhub_dev = (struct xhub_pm_dev *)kzalloc(sizeof(*xhub_dev), GFP_KERNEL);
	if (!xhub_dev) {
		pr_info("allocate memory for xhub_dev fail");
		return -ENOMEM;
	}
	xhub_dev->dev = &pdev->dev;
	ret = xhub_panel_register(xhub_dev, PANEL_PRIMARY);
	if (ret != 0)
		return ret;
	/* second panel */
	ret = xhub_pm_ts_check_dt(PANEL_SECOND);
	pr_info("PANEL_SECOND ret = %d", ret);
	if (ret == -ENODEV)
		return 0;
	if (ret != 0)
		return ret;
	xhub_dev_sec = (struct xhub_pm_dev *)kzalloc(sizeof(*xhub_dev_sec), GFP_KERNEL);
	if (!xhub_dev_sec) {
		pr_info("allocate memory for xhub_dev_sec fail");
		return -ENOMEM;
	}
	xhub_dev_sec->dev = &pdev->dev;
	ret = xhub_panel_register(xhub_dev_sec, PANEL_SECOND);
	return ret;
}
static int xhub_pm_remove(struct platform_device *pdev)
{
	pr_info("xhub_pm_remove\n");
	return 0;
}
static const struct of_device_id xhub_pm_match_table[] = {
	{ .compatible = "huawei,xhub_pm", },
	{ },
};
MODULE_DEVICE_TABLE(of, xhub_pm_match_table);

struct platform_driver xhub_pm_drv_pf = {
	.probe = xhub_pm_probe,
	.remove = xhub_pm_remove,
	.driver = {
		.name = "xhub_pm_platform",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(xhub_pm_match_table),
	},
};
module_platform_driver(xhub_pm_drv_pf);

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("remote screen");
MODULE_LICENSE("GPL");
