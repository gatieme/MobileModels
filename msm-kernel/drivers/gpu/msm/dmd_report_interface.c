/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: add GPU FAULT DMD upload to GPU driver
 * Author: Yiping Long 00525429
 * Create: 2021-07-13
 * version 2.0: 2022-0705
 * file: dmd_report_interface.c
 */

#include <log/hiview_hievent.h>
#include <log/hw_log.h>
#include <log/log_exception.h>
#include <linux/workqueue.h>
#include <linux/module.h>

#define MAX_CONTEXT_SIZE 256
static void report_worker(struct work_struct *work);
static DECLARE_WORK(dmd_work, report_worker);
int g_event = 0;
const char* g_context;

int dmd_table[] = {
	922002000,
	922002001,
	922002004,
	922002005,
	920007005, // for pon event
};

static void fault_dmd_report(int event, const char* context)
{
	struct hiview_hievent *hi_event = NULL;
	if (event >= (sizeof(dmd_table) / sizeof(dmd_table[0])) || event < 0) {
	 	return;
	}
	hi_event = hiview_hievent_create(dmd_table[event]);
	hiview_hievent_put_string(hi_event, "CONTENT", context);
	hiview_hievent_report(hi_event);
	hiview_hievent_destroy(hi_event);
	return;
}

static void report_worker(struct work_struct *work)
{
	fault_dmd_report(g_event, g_context);
	return;
}

void report_dmd_inirq(int event, const char* context)
{
	g_event = event;
	g_context = context;
	schedule_work(&dmd_work);
	return;
}

MODULE_LICENSE("GPL v2");