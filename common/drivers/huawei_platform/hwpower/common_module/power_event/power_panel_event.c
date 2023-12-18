// SPDX-License-Identifier: GPL-2.0
/*
 * power_panel_event.c
 *
 * panel event notify for power module
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

#include <linux/version.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <linux/soc/qcom/panel_event_notifier.h>
#endif /* (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)) */
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_extra_event.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <drm/drm_panel.h>

#define HWLOG_TAG power_panel_event
HWLOG_REGIST();

#if (LINUX_VERSION_CODE == KERNEL_VERSION(5, 4, 0))
static int power_panel_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct drm_panel_notifier *blank_event = data;
	int *blank = NULL;

	if (!blank_event || !blank_event->data) {
		hwlog_err("blank_event is null\n");
		return NOTIFY_DONE;
	}

	blank = blank_event->data;
	if ((event == DRM_PANEL_EVENT_BLANK) && (*blank == DRM_PANEL_BLANK_UNBLANK)) {
		power_event_bnc_notify(POWER_BNT_PANEL_EVENT, POWER_NE_PANEL_UNBLANK, NULL);
		hwlog_info("drm screen on\n");
	} else if ((event == DRM_PANEL_EVENT_BLANK) && (*blank == DRM_PANEL_BLANK_POWERDOWN)) {
		power_event_bnc_notify(POWER_BNT_PANEL_EVENT, POWER_NE_PANEL_BLANK, NULL);
		hwlog_info("drm screen off\n");
	}

	return NOTIFY_DONE;
}

static void power_panel_event_drm_register(struct power_extra_event_dev *di)
{
	di->nb.notifier_call = power_panel_event_notifier_call;
	(void)lcd_kit_drm_notifier_register(0, &di->nb);
}

static void power_panel_event_drm_unregister(struct power_extra_event_dev *di)
{
	(void)lcd_kit_drm_notifier_unregister(0, &di->nb);
}
#else
static void power_panel_event_drm_register(struct power_extra_event_dev *di)
{
}

static void power_panel_event_drm_unregister(struct power_extra_event_dev *di)
{
}
#endif /* (LINUX_VERSION_CODE == KERNEL_VERSION(5, 4, 0)) */

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
static struct drm_panel *g_active_panel;
int power_panel_event_parse_active_panel(void)
{
	int i;
	int count;
	struct device_node *np = NULL;
	struct device_node *node = NULL;
	struct drm_panel *panel = NULL;

	np = of_find_compatible_node(NULL, NULL, "huawei,lcd_panel_type");
	if (!np) {
		hwlog_err("huawei,lcd_panel_type is not found\n");
		return -EINVAL;
	}

	count = of_count_phandle_with_args(np, "panel", NULL);
	hwlog_info("panel count=%d\n", count);
	if (count <= 0)
		return -EINVAL;

	for (i = 0; i < count; i++) {
		node = of_parse_phandle(np, "panel", i);
		if (!node) {
			hwlog_err("panel node %d is not found\n", i);
			return -EINVAL;
		}

		panel = of_drm_find_panel(node);
		of_node_put(node);
		if (!IS_ERR(panel)) {
			g_active_panel = panel;
			of_node_put(np);
			hwlog_info("find active panel i=%d\n", i);
			return 0;
		}
	}

	of_node_put(np);
	hwlog_err("active panel is not find\n");
	return -EPROBE_DEFER;
}
EXPORT_SYMBOL_GPL(power_panel_event_parse_active_panel);

static void power_panel_event_drm_8425_notifier_call(enum panel_event_notifier_tag tag,
	struct panel_event_notification *notification, void *client_data)
{
	if (!notification) {
		hwlog_err("panel_notifier_callback: invalid notification\n");
		return;
	}

	hwlog_info("notif_type=%u\n", notification->notif_type);
	switch (notification->notif_type) {
	case DRM_PANEL_EVENT_UNBLANK:
		power_event_bnc_notify(POWER_BNT_PANEL_EVENT, POWER_NE_PANEL_UNBLANK, NULL);
		hwlog_info("drm 8425 screen on\n");
		break;
	case DRM_PANEL_EVENT_BLANK:
		power_event_bnc_notify(POWER_BNT_PANEL_EVENT, POWER_NE_PANEL_BLANK, NULL);
		hwlog_info("drm 8425 screen off\n");
		break;
	default:
		break;
	}
}

static void power_panel_event_drm_8425_register(struct power_extra_event_dev *di)
{
	void *cookie = panel_event_notifier_register(PANEL_EVENT_NOTIFICATION_PRIMARY,
		PANEL_EVENT_NOTIFIER_CLIENT_POWER_EXTRA_EVENT, g_active_panel,
		&power_panel_event_drm_8425_notifier_call, di);

	if (!cookie) {
		hwlog_err("failed to register for panel event\n");
		return;
	}

	di->notifier_cookie = cookie;
}

static void power_panel_event_drm_8425_unregister(struct power_extra_event_dev *di)
{
	if (g_active_panel && di->notifier_cookie)
		panel_event_notifier_unregister(di->notifier_cookie);
}
#else
int power_panel_event_parse_active_panel(void)
{
	return 0;
}
EXPORT_SYMBOL_GPL(power_panel_event_parse_active_panel);

static void power_panel_event_drm_8425_register(struct power_extra_event_dev *di)
{
}

static void power_panel_event_drm_8425_unregister(struct power_extra_event_dev *di)
{
}
#endif /* (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)) */

void  power_panel_event_register(struct power_extra_event_dev *di)
{
	if (!di)
		return;

	if (di->panel_client == PANEL_CLIENT_DRM_8425)
		power_panel_event_drm_8425_register(di);
	else
		power_panel_event_drm_register(di);
}
EXPORT_SYMBOL_GPL(power_panel_event_register);

void power_panel_event_unregister(struct power_extra_event_dev *di)
{
	if (!di)
		return;

	if (di->panel_client == PANEL_CLIENT_DRM_8425)
		power_panel_event_drm_8425_unregister(di);
	else
		power_panel_event_drm_unregister(di);
}
EXPORT_SYMBOL_GPL(power_panel_event_unregister);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("power panel event driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
