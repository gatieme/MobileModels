// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2021 Huawei Technologies Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <asm/cacheflush.h>
#include <platform/linux/blackbox.h>
#include <linux/delay.h>
#include <linux/dirent.h>
#include <linux/kmsg_dump.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/stacktrace.h>
#include <linux/string.h>
#include <linux/reboot.h>
#include <linux/syscalls.h>
#include <linux/ctype.h>
#include <linux/of_address.h>
#include <linux/io.h>
#include <securec.h>
#include "rainbow.h"
#include "../blackbox_common.h"

/* ---- local macroes ---- */
#define LOG_FILE_WAIT_TIME           1000 /* unit: ms */
#define RETRY_MAX_COUNT    10
#define PSTORE_MOUNT_POINT  "/sys/fs/pstore/"
#define BOOTLOADER_LOG_NAME "fastboot_log"
#define KERNEL_LOG_NAME "last_kmsg"
#define SIZE_1K 1024
#define RB_KERNEL_LOG_SIZE 0x00100000
#define KERNEL_LOG_MAX_SIZE \
	round_down((RB_KERNEL_LOG_SIZE - sizeof(struct fault_log_info)), SIZE_1K)
#define CALLSTACK_MAX_ENTRIES 20
#define FILE_LIMIT  (0660)
#define PARTITION_PATH "/dev/block/by-name/rawdump"
#define MNTN_LASTKMSG_OFFSET  0x200000

/* ---- local prototypes ---- */

/* ---- local function prototypes ---- */
static int save_kmsg_from_buffer(const char *log_dir,
				 const char *file_name, int clean_buf);
static void do_kmsg_dump(struct kmsg_dumper *dumper,
			 enum kmsg_dump_reason reason);
static void dump(const char *log_dir, struct error_info *info);
static void reset(struct error_info *info);
static int get_last_log_info(struct error_info *info);
static long write_to_raw_partition(const char *dev_path, loff_t offset,
				   char *buf, size_t buf_size);
static int save_last_log(const char *log_dir, struct error_info *info);
static int bbox_reboot_notify(struct notifier_block *nb,
					unsigned long code, void *unused);
static int bbox_task_panic(struct notifier_block *this,
					unsigned long event, void *ptr);

/* ---- local variables ---- */
static struct rb_header *g_rb_header;
static struct rb_header *g_rb_header_paddr;

static char *kernel_log;
static DEFINE_SEMAPHORE(kmsg_sem);
static struct notifier_block bbox_reboot_nb = {
	.notifier_call = bbox_reboot_notify,
};

static struct notifier_block bbox_panic_block = {
	.notifier_call = bbox_task_panic,
};

/* ---- function definitions ---- */
static void dump_stacktrace(char *pbuf, size_t buf_size, bool is_panic)
{
	int i;
	size_t stack_len = 0;
	size_t com_len = 0;
	unsigned long entries[CALLSTACK_MAX_ENTRIES];
	unsigned int nr_entries;
	char tmp_buf[ERROR_DESC_MAX_LEN];
	bool find_panic = false;

	if (unlikely(!pbuf || !buf_size))
		return;

	memset(pbuf, 0, buf_size);
	memset(tmp_buf, 0, sizeof(tmp_buf));
	nr_entries = stack_trace_save(entries, ARRAY_SIZE(entries), 0);
	com_len = scnprintf(pbuf, buf_size, "Comm:%s,CPU:%d,Stack:",
						current->comm, raw_smp_processor_id());
	for (i = 0; i < nr_entries; i++) {
		if (stack_len >= sizeof(tmp_buf)) {
			tmp_buf[sizeof(tmp_buf) - 1] = '\0';
			break;
		}
		stack_len += scnprintf(tmp_buf + stack_len, sizeof(tmp_buf) - stack_len,
				"%pS-", (void *)entries[i]);
		if (!find_panic && is_panic) {
			if (strncmp(tmp_buf, "panic", strlen("panic")) == 0)
				find_panic = true;
			else
				(void)memset(tmp_buf, 0, sizeof(tmp_buf));
		}
	}
	if (com_len >= buf_size)
		return;
	stack_len = min(buf_size - com_len, strlen(tmp_buf));
	memcpy(pbuf + com_len, tmp_buf, stack_len);
	*(pbuf + buf_size - 1) = '\0';
}

static void do_kmsg_dump(struct kmsg_dumper *dumper,
	enum kmsg_dump_reason reason)
{
	struct fault_log_info *pinfo = NULL;

	if (kernel_log == NULL) {
		bbox_print_err("kernel_log: %p!\n", kernel_log);
		return;
	}

	/* get kernel log from kmsg dump module */
	if (down_trylock(&kmsg_sem) != 0) {
		bbox_print_err("down_trylock failed!\n");
		return;
	}
	pinfo = (struct fault_log_info *)kernel_log;
	(void)kmsg_dump_get_buffer(dumper, true, kernel_log + sizeof(*pinfo),
		KERNEL_LOG_MAX_SIZE, (size_t *)&pinfo->len);
	up(&kmsg_sem);
}

static int save_kmsg_from_buffer(const char *log_dir, const char *file_name,
				 int clean_buf)
{
	int ret = -1;
	char path[PATH_MAX_LEN];
	struct fault_log_info *pinfo = NULL;
	size_t size;

	if (unlikely(!log_dir || !file_name)) {
		bbox_print_err("log_dir: %p, file_name: %p!\n", log_dir, file_name);
		return -EINVAL;
	}

	memset(path, 0, sizeof(path));
	(void)scnprintf(path, sizeof(path) - 1, "%s/%s", log_dir, file_name);
	down(&kmsg_sem);
	if (kernel_log) {
		pinfo = (struct fault_log_info *)kernel_log;
		size = min((size_t)RB_KERNEL_LOG_SIZE,
			   (size_t)pinfo->len + sizeof(*pinfo));
		ret = full_write_file(path, kernel_log, size, 0);
		if (clean_buf) {
			memset(kernel_log, 0, RB_KERNEL_LOG_SIZE);
			write_to_raw_partition(PARTITION_PATH, MNTN_LASTKMSG_OFFSET, LOG_RECORDED, strlen(LOG_RECORDED));
		}
	} else {
		bbox_print_err("kernel_log: %p!\n", kernel_log);
	}
	up(&kmsg_sem);
	if (ret == 0)
		change_own(path, AID_ROOT, AID_SYSTEM);

	return ret;
}

void rb_mreason_set(uint32_t reason)
{
	struct rb_reason_header *reason_node_local = NULL;

	if (!g_rb_header) {
		bbox_print_err("%s g_rb_header is null\n", __func__);
		return;
	}

	if (reason <= RB_M_UINIT || reason > RB_M_UNKOWN) {
		bbox_print_err("reason is invalid, %d\n", reason);
		return;
	}
	reason_node_local = &(g_rb_header->reason_node);
	bbox_print_err("mreason_num is %d\n", reason_node_local->mreason_num);
	if (reason_node_local->mreason_num == RB_M_UINIT) {
		reason_node_local->mreason_num = reason;
		bbox_print_err("mreason_num set to %d\n", reason);
	}
	bbox_print_info("%s", linux_banner);
	bbox_print_info("end\n");
}
EXPORT_SYMBOL(rb_mreason_set);

static void rb_sreason_str_set(char *sreason_info)
{
#ifdef CONFIG_ARM64
	unsigned int sreason_info_size = strlen(sreason_info);
#endif
	struct rb_reason_header *reason_node_local = NULL;

	if (!sreason_info || !g_rb_header)
		return;

	reason_node_local = &(g_rb_header->reason_node);
	bbox_print_info("sreason_str set start\n");
	if (reason_node_local->sreason_str_flag  == RB_REASON_STR_VALID) {
		bbox_print_info("sreason_str have set, so skip\n");
		return;
	}
#ifdef CONFIG_ARM64
	if (sreason_info_size >= RB_SREASON_STR_MAX) {
		memcpy_toio(reason_node_local->sreason_str, sreason_info, RB_SREASON_STR_MAX);
		reason_node_local->sreason_str[RB_SREASON_STR_MAX - 1] = '\0';
	} else {
		memcpy_toio(reason_node_local->sreason_str, sreason_info, sreason_info_size);
		reason_node_local->sreason_str[sreason_info_size] = '\0';
	}
#else
	strlcpy(reason_node_local->sreason_str, sreason_info, RB_SREASON_STR_MAX);
#endif
	reason_node_local->sreason_str_flag = RB_REASON_STR_VALID;
	bbox_print_err("sreason_str set %s end\n", reason_node_local->sreason_str);
}

void rb_sreason_set(char *fmt)
{
	if (!fmt)
		return;
	rb_sreason_str_set(fmt);
}
EXPORT_SYMBOL(rb_sreason_set);

static void rb_attach_info_str_set(char *attach_info)
{
#ifdef CONFIG_ARM64
	unsigned int attach_info_size = strlen(attach_info);
#endif
	struct rb_reason_header *reason_node_local = NULL;

	if (!attach_info || !g_rb_header)
		return;

	reason_node_local = &(g_rb_header->reason_node);
	bbox_print_info("attach_info set start\n");
	if (reason_node_local->attach_info_flag == RB_REASON_STR_VALID) {
		bbox_print_info("attach_info have set,so skip\n");
		return;
	}

#ifdef CONFIG_ARM64
	if (attach_info_size >= RB_SREASON_STR_MAX) {
		memcpy_toio(reason_node_local->attach_info, attach_info, RB_SREASON_STR_MAX);
		reason_node_local->attach_info[RB_SREASON_STR_MAX - 1] = '\0';
	} else {
		memcpy_toio(reason_node_local->attach_info, attach_info, attach_info_size);
		reason_node_local->attach_info[attach_info_size] = '\0';
	}
#else
	strlcpy(reason_node_local->attach_info, attach_info, RB_SREASON_STR_MAX);
#endif
	reason_node_local->attach_info_flag = RB_REASON_STR_VALID;
	bbox_print_err("attach_info set %s end\n", reason_node_local->attach_info);
}

void rb_attach_info_set(char *fmt)
{
	if (!fmt)
		return;

	bbox_print_err("%s %s.", __func__, fmt);
	rb_attach_info_str_set(fmt);
}
EXPORT_SYMBOL(rb_attach_info_set);

void rb_kallsyms_set(const char *fmt)
{
	int err;
	char attach_info_buffer[RB_SREASON_STR_MAX] = {0};
	char kallsyms_buffer[KSYM_SYMBOL_LEN] = {0};

	if (!fmt)
		return;

	err = snprintf(attach_info_buffer, RB_SREASON_STR_MAX, fmt, kallsyms_buffer);
	if (err < 0) {
		bbox_print_err("fail\n");
		return;
	}
	bbox_print_err("%s\n", attach_info_buffer);
	rb_attach_info_str_set(attach_info_buffer);
}
EXPORT_SYMBOL(rb_kallsyms_set);

static void rb_kernel_log_buf_reg(void)
{
	char *log_bufp = NULL;
	uint32_t log_buf_len = 0;
	struct rb_region_log_info *log_info = NULL;

	log_bufp = log_buf_addr_get();
	log_buf_len = log_buf_len_get();
	if (!log_bufp || !log_buf_len) {
		bbox_print_err("Unable to find log_buf or log_size by kallsyms\n");
		return;
	}

	if (g_rb_header == NULL) {
		bbox_print_err("rb_header map error\n");
		return;
	}
	log_info = &(g_rb_header->kernel_log);
	log_info->virt_addr = (uintptr_t)log_bufp;
	log_info->phys_addr = virt_to_phys(log_bufp);
	log_info->size = log_buf_len;
	log_info->magic = RB_REGION_LOG_MAGIC_VALID;
}

void *rb_bl_log_get(unsigned int *size)
{
	void *addr = NULL;

	if (!g_rb_header || !size) {
		bbox_print_err("%s: addr or size or g_rb_header is null\n", __func__);
		return NULL;
	}
	bbox_print_info("g_rb_header:%x\n", g_rb_header);
	addr = (void *)((char *)g_rb_header + RB_PRE_LOG_OFFSET);
	*size = RB_BL_LOG_SIZE;
	return addr;
}
EXPORT_SYMBOL(rb_bl_log_get);

static void dump(const char *log_dir, struct error_info *info)
{
	struct rb_reason_header *reason_node_local = NULL;
	if (unlikely(!log_dir || !info)) {
		bbox_print_err("log_dir: %p, info: %p!\n", log_dir, info);
		return;
	}

	if (!strcmp(info->category, CATEGORY_SYSTEM_PANIC) ||
	    !strcmp(info->category, CATEGORY_SYSTEM_REBOOT) ||
	    !strcmp(info->category, CATEGORY_SYSTEM_POWEROFF)) {

		struct rb_region_log_info *log_info = NULL;
		struct fault_log_info *pinfo = (struct fault_log_info *)kernel_log;

		if (!strcmp(info->category, CATEGORY_SYSTEM_PANIC)) {

#ifdef CONFIG_PREEMPT
			/* Ensure that cond_resched() won't try to preempt anybody */
			preempt_count_add(PREEMPT_DISABLE_OFFSET);
#endif
			rb_mreason_set(RB_M_APANIC);
#ifdef CONFIG_PREEMPT
			preempt_count_sub(PREEMPT_DISABLE_OFFSET);
#endif
		}

		if (down_trylock(&kmsg_sem) != 0) {
			bbox_print_err("down_trylock failed!\n");
			return;
		}

		if (kernel_log) {
			memcpy(pinfo->flag, LOG_FLAG, strlen(LOG_FLAG));

			if (!g_rb_header) {
				bbox_print_err("%s g_rb_header is null\n", __func__);
				return;
			}
			reason_node_local = &(g_rb_header->reason_node);
			if (reason_node_local->sreason_str_flag == RB_REASON_STR_VALID) {
				bbox_print_err("sreason:%s\n", reason_node_local->sreason_str);
				memset(info->event, 0, sizeof(info->event));
				memcpy(info->event, reason_node_local->sreason_str,
				       min(strlen(reason_node_local->sreason_str), sizeof(info->event) - 1));
			}

			if (reason_node_local->attach_info_flag == RB_REASON_STR_VALID)
				bbox_print_err("attach_info:%s\n", reason_node_local->attach_info);
			memcpy(&pinfo->info, info, sizeof(*info));

#if __BITS_PER_LONG == 64
			__flush_dcache_area(kernel_log, RB_KERNEL_LOG_SIZE);
#else
			__cpuc_flush_dcache_area(kernel_log, RB_KERNEL_LOG_SIZE);
#endif

			log_info = &(g_rb_header->kernel_log);
			log_info->virt_addr = (uintptr_t)kernel_log;
			log_info->phys_addr = virt_to_phys(kernel_log);
			log_info->size = RB_KERNEL_LOG_SIZE;
			log_info->magic = RB_REGION_LOG_MAGIC_VALID;

			bbox_print_info("rb_kernel_log_buf_reg the size is %d\n", log_info->size);
		}

		up(&kmsg_sem);
	} else {
		bbox_print_info("module [%s] starts saving log for event [%s]!\n",
				info->module, info->event);
		save_kmsg_from_buffer(log_dir, KERNEL_LOG_NAME, 0);
		bbox_print_info("module [%s] ends saving log for event [%s]!\n",
				info->module, info->event);
	}
}

static void reset(struct error_info *info)
{
	if (unlikely(!info)) {
		bbox_print_err("info: %p!\n", info);
		return;
	}
}

static int check_partition_status(const char *dev_path)
{
	int fs_ret = -1;

	if (unlikely(!dev_path)) {
		bbox_print_err("Invalid parameter, dev_path: %p!\n", dev_path);
		return -EINVAL;
	}

	fs_ret = file_exists(dev_path);
	if (fs_ret) {
		bbox_print_err("Open partition %s failed! fs_ret: [%d].\n", dev_path, fs_ret);
		return -EBADF;
	}
	return fs_ret;
}

static long write_to_raw_partition(const char *dev_path, loff_t offset, char *buf, size_t buf_size)
{
	struct file *filp = NULL;
	int rawdump_status = -1;
	mm_segment_t old_fs;
	loff_t pos = offset;
	int ret = -1;

	if (unlikely(!dev_path) || unlikely(!buf)) {
		bbox_print_err("Invalid parameter, dev_path: %p buf: %p!\n", dev_path, buf);
		return -EINVAL;
	}

	rawdump_status = check_partition_status(dev_path);
	if (rawdump_status < 0) {
		bbox_print_err("Check partition status %s failed!.\n", dev_path);
		return -EBADF;
	}

	filp = file_open(dev_path, O_RDWR, 0);
	if (IS_ERR(filp)) {
		bbox_print_err("Open partition %s failed! [%ld]\n", dev_path, PTR_ERR(filp));
		return -EBADF;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	ret = vfs_write(filp, buf, buf_size, &pos);

	set_fs(old_fs);

	file_close(filp);

	if (ret < 0)
		bbox_print_err("write [%s] failed! [%d]\n", dev_path, ret);

	return 0;
}

static int get_last_log_info(struct error_info *info)
{
	struct fault_log_info *pinfo = (struct fault_log_info *)kernel_log;
	struct file *filp = NULL;
	int rawdump_status = -1;
	mm_segment_t old_fs;
	int read_ret = -1;
	loff_t pos = MNTN_LASTKMSG_OFFSET;
	int cmp_ret;

	if (unlikely(!info)) {
		bbox_print_err("Invalid parameter info: %p!\n", info);
		return -EINVAL;
	}

	rawdump_status = check_partition_status(PARTITION_PATH);
	if (rawdump_status < 0) {
		bbox_print_err("Check partition status %s failed!.\n", PARTITION_PATH);
		return -EBADF;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	filp = file_open(PARTITION_PATH, O_RDWR, FILE_LIMIT);
	if (IS_ERR(filp)) {
		bbox_print_err("Open partition %s failed! [%ld]\n", PARTITION_PATH, PTR_ERR(filp));
		goto __out;
	}

	down(&kmsg_sem);
	read_ret = vfs_read(filp, kernel_log, RB_KERNEL_LOG_SIZE, &pos);
	if (read_ret < 0) {
		bbox_print_err("Read partition %s failed! read_ret: %d.\n", PARTITION_PATH, read_ret);
		up(&kmsg_sem);
		goto __out;
	}
	bbox_print_info("Read partition %s successfully! read_ret: [%d].\n", PARTITION_PATH, read_ret);

	cmp_ret = memcmp(pinfo->flag, LOG_FLAG, strlen(LOG_FLAG));
	if (!cmp_ret)
		memcpy(info, &pinfo->info, sizeof(*info));
	else
		bbox_print_err("There's no valid fault log! cmp_ret: %d.\n", cmp_ret);

	up(&kmsg_sem);

__out:
	if (!IS_ERR(filp))
		file_close(filp);
	set_fs(old_fs);

	return !(read_ret > 0 && !cmp_ret);
}

static int save_last_log(const char *log_dir, struct error_info *info)
{
	int ret;

	if (unlikely(!log_dir || !info)) {
		bbox_print_err("log_dir: %p, info: %p!\n", log_dir, info);
		return -EINVAL;
	}

	ret = save_kmsg_from_buffer(log_dir, KERNEL_LOG_NAME, 1);
	bbox_print_info("save last fault log %s!\n",
			ret ? "failed" : "successfully");

	return ret;
}

static int bbox_reboot_notify(struct notifier_block *nb,
					unsigned long code, void *unused)
{
	char error_desc[ERROR_DESC_MAX_LEN];

	/* notify blackbox to do dump */
	memset(error_desc, 0, sizeof(error_desc));
	dump_stacktrace(error_desc, sizeof(error_desc), false);
	kmsg_dump(KMSG_DUMP_UNDEF);

	switch (code) {
	case SYS_RESTART:
		bbox_notify_error(EVENT_SYSREBOOT, MODULE_SYSTEM, error_desc, 1);
		break;
	case SYS_POWER_OFF:
		bbox_notify_error(EVENT_POWEROFF, MODULE_SYSTEM, error_desc, 0);
		break;
	default:
		bbox_print_err("Invalid event code: %lu!\n", code);
		break;
	}

	return NOTIFY_DONE;
}

static int bbox_task_panic(struct notifier_block *this,
				unsigned long event, void *ptr)
{
	char error_desc[ERROR_DESC_MAX_LEN];

	rb_mreason_set(RB_M_APANIC);
	/* notify blackbox to do dump */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	kmsg_dump(KMSG_DUMP_PANIC);
#endif
	memset(error_desc, 0, sizeof(error_desc));
	dump_stacktrace(error_desc, sizeof(error_desc), false);
	bbox_notify_error(EVENT_PANIC, MODULE_SYSTEM, error_desc, 1);

	return NOTIFY_DONE;
}

#ifdef CONFIG_BLACKBOX_TEST
static void test_bbox(void)
{
	int ret;

	struct module_ops ops = {
		.module = "TEST",
		.dump = NULL,
		.reset = NULL,
		.get_last_log_info = NULL,
		.save_last_log = NULL,
	};

	ret = bbox_register_module_ops(&ops);
	if (ret != 0) {
		bbox_print_err("bbox_register_module_ops failed!\n");
		return ret;
	}
	kmsg_dump(KMSG_DUMP_OOPS);
	bbox_notify_error("EVENT_TEST", "TEST", "Test bbox_notify_error", 0);
}
#endif

static void rb_header_init(void)
{
	struct device_node *rb_dev_node = NULL;
	unsigned long rb_header_dts_addr;
	const u32 *rb_dts_basep = NULL;
	unsigned long rb_header_dts_size = 0;

	rb_dev_node = of_find_compatible_node(NULL, NULL, "rainbow_mem");
	if (!rb_dev_node) {
		bbox_print_err("dtsi find fail\n");
		return;
	}
	rb_dts_basep = of_get_address(rb_dev_node, 0, (u64 *)&rb_header_dts_size, NULL);
	if (!rb_dts_basep) {
		bbox_print_err("Getting address failed\n");
		return;
	}
	rb_header_dts_addr = (unsigned long)of_translate_address(rb_dev_node, rb_dts_basep);
	if (!rb_header_dts_addr) {
		bbox_print_err("wrong address or size\n");
		return;
	}
	g_rb_header_paddr = (struct rb_header *)rb_header_dts_addr;
	bbox_print_info("phy addr %x, size is %x\n",
		rb_header_dts_addr, rb_header_dts_size);
#ifdef CONFIG_ARM
	g_rb_header = (struct rb_header *)ioremap_nocache(rb_header_dts_addr, rb_header_dts_size);
#else
	g_rb_header = (struct rb_header *)ioremap_wc(rb_header_dts_addr, rb_header_dts_size);
#endif
	if (!g_rb_header)
		bbox_print_err("fail get g_rb_header\n");
	else
		bbox_print_info("g_rb_header addr is %x ioremap to %x, size is %x\n",
				rb_header_dts_addr, g_rb_header, rb_header_dts_size);
}

void *get_rb_header_paddr(void)
{
	return g_rb_header_paddr;
}
EXPORT_SYMBOL(get_rb_header_paddr);

void *get_rb_header(void)
{
	return g_rb_header;
}
EXPORT_SYMBOL(get_rb_header);

static void rb_header_exit(void)
{
	if (g_rb_header != NULL)
		iounmap((void *)g_rb_header);
}

static int __init blackbox_init(void)
{
	int ret = -1;
	struct kmsg_dumper *dumper = NULL;
	struct module_ops ops = {
		.module = MODULE_SYSTEM,
		.dump = dump,
		.reset = reset,
		.get_last_log_info = get_last_log_info,
		.save_last_log = save_last_log,
	};

	if (bbox_register_module_ops(&ops) != 0) {
		bbox_print_err("bbox_register_module_ops failed!\n");
		return -EINVAL;
	}

	/* allocate buffer for kmsg */
	kernel_log = kmalloc(RB_KERNEL_LOG_SIZE, GFP_KERNEL);
	if (!kernel_log)
		goto __err;
	memset(kernel_log, 0, RB_KERNEL_LOG_SIZE);

	bbox_print_info("kernel_log: %p for blackbox!\n", kernel_log);

	rb_header_init();
	rb_kernel_log_buf_reg();
	/* register kdumper */
	dumper = kmalloc(sizeof(*dumper), GFP_KERNEL);
	if (!dumper)
		goto __err;

	memset(dumper, 0, sizeof(*dumper));
	dumper->max_reason = KMSG_DUMP_OOPS;
	dumper->dump = do_kmsg_dump;
	ret = kmsg_dump_register(dumper);
	if (ret != 0) {
		bbox_print_err("kmsg_dump_register failed!\n");
		goto __err;
	}

	atomic_notifier_chain_register(&panic_notifier_list, &bbox_panic_block);

	register_reboot_notifier(&bbox_reboot_nb);
#ifdef CONFIG_BLACKBOX_TEST
	test_bbox();
#endif
	return 0;

__err:
	kfree(kernel_log);
	kernel_log = NULL;

	if (dumper) {
		kfree(dumper);
		dumper = NULL;
	}

	return ret;
}

static void __exit blackbox_exit(void)
{
	rb_header_exit();
}

postcore_initcall(blackbox_init);
module_exit(blackbox_exit);
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Blackbox for system");
MODULE_AUTHOR("OHOS");
