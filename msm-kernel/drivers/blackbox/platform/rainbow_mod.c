/*
 * rainbow_mod.c
 *
 * This file contains all of rainbow's tracepoint
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/init.h>
#include <platform/linux/rainbow.h>

#include "rainbow.h"
#include "rainbow_himntn.h"

#if (KERNEL_VERSION(5, 10, 0) <= LINUX_VERSION_CODE)
#include <platform/trace/hooks/rainbow.h>
#else
#include <platform/trace/events/rainbow.h>
#endif

static void hook_rb_mreason_set(void *ignore, uint32_t reason)
{
	rb_mreason_set(reason);
}

static void hook_rb_sreason_set(void *ignore, char *fmt)
{
	rb_sreason_set(fmt);
}

static void hook_rb_attach_info_set(void *ignore, char *fmt)
{
	rb_attach_info_set(fmt);
}

static void hook_rb_kallsyms_set(void *ignore, const char *fmt)
{
	rb_kallsyms_set(fmt);
}

static void hook_cmd_himntn_item_switch(void *ignore, unsigned int index, bool *rtn)
{
#ifdef CONFIG_DFX_RAINBOW_HIMNTN
	cmd_himntn_item_switch(index, rtn);
#endif
}

static int __init rb_mod_init(void)
{
	REGISTER_HCK_VNH(rb_mreason_set, hook_rb_mreason_set, NULL);
	REGISTER_HCK_VNH(rb_sreason_set, hook_rb_sreason_set, NULL);
	REGISTER_HCK_VNH(rb_attach_info_set, hook_rb_attach_info_set, NULL);
	REGISTER_HCK_VNH(rb_kallsyms_set, hook_rb_kallsyms_set, NULL);
#ifdef CONFIG_DFX_RAINBOW_HIMNTN
	REGISTER_HCK_VNH(cmd_himntn_item_switch, hook_cmd_himntn_item_switch, NULL);
#endif

	return 0;
}
module_init(rb_mod_init);

static void __exit rb_mod_exit(void)
{
}
module_exit(rb_mod_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_DESCRIPTION("Huawei Rainbow Module");
