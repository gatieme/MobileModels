/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_module.c for kernel stp
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "hn_kernel_stp_utils.h"
#include "hn_kernel_stp_proc.h"
#include "hn_kernel_stp_scanner.h"
#include "hn_kernel_stp_uploader.h"
#include <security/hn_kernel_stp_interface.h>

static const char *TAG = "kernel_stp_module";

struct kernel_stp_module_work {
	struct workqueue_struct *kernel_stp_wq;
	struct work_struct kernel_stp_work;
};

static struct kernel_stp_module_work g_kernel_stp_work_data;
static void __exit kernel_stp_module_exit(void);
const struct stp_item_info *get_item_info_by_idx(int idx)
{
	if (idx < STP_ITEM_MAX)
		return &item_info[idx];
	return NULL;
};
EXPORT_SYMBOL(get_item_info_by_idx);

static void kernel_stp_work_init(struct work_struct *data)
{
	int result;

	(void)data;
	KSTPLogTrace(TAG, "kernel stp work init.");

	do {
		/* init kernel stp proc */
		result = kernel_stp_proc_init();
		if (result != 0) {
			KSTPLogError(TAG, "kernel_stp_proc init failed.");
			break;
		}

		/* init kernel stp scanner */
		result = kernel_stp_scanner_init();
		if (result != 0) {
			KSTPLogError(TAG, "kernel_stp_scanner init failed.");
			break;
		}

		/* init kernel stp uploader */
		result = kernel_stp_uploader_init();
		if (result != 0) {
			KSTPLogError(TAG, "kernel_stp_uploader init failed.");
			break;
		}
	} while (0);

	if (result != 0) {
		kernel_stp_module_exit();

		KSTPLogError(TAG, "kernel stp module init failed.");
		return;
	}

	KSTPLogTrace(TAG, "kernel stp module init success.");
}

static int __init kernel_stp_module_init(void)
{
	g_kernel_stp_work_data.kernel_stp_wq =
			create_singlethread_workqueue("HN_KERNEL_STP_MODULE");

	if (g_kernel_stp_work_data.kernel_stp_wq == NULL) {
		KSTPLogError(TAG, "kernel stp module wq error, no mem");
		return -ENOMEM;
	}

	INIT_WORK(&(g_kernel_stp_work_data.kernel_stp_work),
		kernel_stp_work_init);
	queue_work(g_kernel_stp_work_data.kernel_stp_wq,
			&(g_kernel_stp_work_data.kernel_stp_work));

	return 0;
}

static void __exit kernel_stp_module_exit(void)
{
	if (g_kernel_stp_work_data.kernel_stp_wq != NULL) {
		destroy_workqueue(g_kernel_stp_work_data.kernel_stp_wq);
		g_kernel_stp_work_data.kernel_stp_wq = NULL;
	}

	kernel_stp_proc_exit();
	kernel_stp_scanner_exit();
	kernel_stp_uploader_exit();

}

module_init(kernel_stp_module_init);
module_exit(kernel_stp_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jiayunlong <jiayunlong@hihonor.com>");
MODULE_DESCRIPTION("Honor kernel stp");
