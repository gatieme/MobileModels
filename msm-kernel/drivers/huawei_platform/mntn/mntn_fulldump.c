/*
 * Copyright (C) Huawei technologies Co., Ltd All rights reserved.
 * Filename: rdr_fulldump.c
 * Description: rdr fulldump adaptor
 * Author: 2021-03-27 zhangxun dfx re-design
 */

#include <linux/printk.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rculist.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include "securec.h"

#define RESIZE_RESULT_NAME                 "resize_cb"
#define RESIZE_PROC_RIGHT                  0660

#define SKP_DUMP_RESIZE_SUCCESS_FLAG       0x1
#define SKP_DUMP_RESIZE_FAIL               0x0

#define RESIZE_FLAG_MAX                    2
#define BASE_VALUE_GET_SWITCH              0x8000000000
#define HIMNTN_NAME_FASTBOOT_SWITCH        16
#define HIMNTN_NAME_BOOTDUMP_SWITCH        17
#define HIMNTN_NAME_FINAL_RELEASE          18

#ifdef CONFIG_DFX_FUSE_DUMP_SWITCH
#define COMMERCIAL_FUSE_SUFFIX             '2'
char g_oem_pk_suffix = '0';
#endif

int g_fulldump_resize_flag = SKP_DUMP_RESIZE_FAIL;

unsigned long long g_himntn_value = 0;

static int check_himntn(unsigned int index)
{
	unsigned long long tmp_value;

	tmp_value = (BASE_VALUE_GET_SWITCH >> index);

	if (g_himntn_value & tmp_value) {
		pr_err("himntn index %u is enabled\n", index);
		return 1;
	}
	pr_info("himntn index %u is not enabled\n", index);
	return 0;
}

static int early_parse_himntn_cmdline(char *p)
{
	int ret;

	if (p == NULL)
		return -1;

	ret = sscanf_s(p, "%llx", &g_himntn_value);
	if (ret != 1) {
		pr_err("sscanf parse error\n");
		return -1;
	}

	pr_err("g_himntn_value is 0x%llx\n", g_himntn_value);
	return 0;
}
early_param("HIMNTN", early_parse_himntn_cmdline);

#ifdef CONFIG_DFX_FUSE_DUMP_SWITCH
static int early_parse_oem_pk_hash_cmdline(char *p)
{
	int ret;
	if (!p) {
		pr_err("early_parse_oem_pk_hash_cmdline, p is null\n");
		return -1;
	}
	if (strlen(p) == 0) {
		pr_err("early_parse_oem_pk_hash_cmdline, p len is 0\n");
		return -1;
	}
	g_oem_pk_suffix = *(p + strlen(p) - 1);
	pr_err("early_parse_oem_pk_hash_cmdline, flag=%c\n", g_oem_pk_suffix);
	return 0;
}
early_param("oem_pk_hash", early_parse_oem_pk_hash_cmdline);
#endif

static int resizecb_proc_para_check(struct file *file, char __user *buffer, loff_t *data)
{
	if (!file || !buffer || !data)
		return -1;

	return 0;
}

/*
 * Function:       dataready_info_show
 * Description:    show g_dataready_flag
 * Input:          struct seq_file *m, void *v
 * Output:         NA
 * Return:         0:success;other:fail
 */
static int resizecb_info_show(struct seq_file *m, void *v)
{
	pr_err("%x\n", g_fulldump_resize_flag);
	return 0;
}

/*
 * Function:       dataready_open
 * Description:    open /proc/data-ready
 * Input:          inode;file
 * Output:         NA
 * Return:         0:success;other:fail
 */
static int resizecb_open(struct inode *inode, struct file *file)
{
	if (!file)
		return -EFAULT;

	return single_open(file, resizecb_info_show, NULL);
}

/*
 * Function:       dataready_write_proc
 * Description:    write /proc/resize-cb, for get the status of data_partition
 * Input:          file;buffer;count;data
 * Output:         NA
 * Return:         >0:success;other:fail
 */
ssize_t resizecb_write_proc(struct file *file, const char __user *buffer, size_t count, loff_t *data)
{
	ssize_t ret = -EINVAL;
	char tmp;

	/* buffer must be '1' or '0', so count<=2 */
	if (count > RESIZE_FLAG_MAX)
		return ret;

	if (resizecb_proc_para_check(file, (char __user *)buffer, data))
		return ret;

	/* should ignore character '\n' */
	if (copy_from_user(&tmp, buffer, sizeof(tmp)))
		return -EFAULT;

	pr_err("%s():%d:input arg [%c],%d\n", __func__, __LINE__, tmp, tmp);

	if (tmp == '1') {
		g_fulldump_resize_flag = SKP_DUMP_RESIZE_SUCCESS_FLAG;
		pr_err("%s():%d resize success\n", __func__, __LINE__);
	} else if (tmp == '0') {
		g_fulldump_resize_flag = SKP_DUMP_RESIZE_FAIL;
		pr_err("%s():%d resize failed\n", __func__, __LINE__);
	} else {
		pr_err("%s():%d:input arg invalid[%c]\n", __func__, __LINE__, tmp);
	}
	return 1;
}

ssize_t resizecb_read_proc(struct file *file, char __user *buffer, size_t count, loff_t *data)
{
	ssize_t ret = -EINVAL;
	char tmp;

	if (resizecb_proc_para_check(file, buffer, data))
		return ret;

	if (count < RESIZE_FLAG_MAX)
		return ret;

	if (*data)
		return 0;

	// default set to be enabled
	tmp = '0' + g_fulldump_resize_flag;

	ret = simple_read_from_buffer(buffer, count, data, &tmp, sizeof(char));

	pr_info("%s():%d:output arg [%c],%d\n", __func__, __LINE__, tmp, tmp);

	return ret;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,6,0)
#define HAVE_PROC_OPS
#endif
#ifdef HAVE_PROC_OPS
static const struct proc_ops resizecb_proc_fops = {
	.proc_open	= resizecb_open,
	.proc_write	= resizecb_write_proc,
	.proc_read	= resizecb_read_proc,
	.proc_lseek	= seq_lseek,
	.proc_release	= single_release,
};
#else
static const struct file_operations resizecb_proc_fops = {
	.open		= resizecb_open,
	.write		= resizecb_write_proc,
	.read		= resizecb_read_proc,
	.llseek		= seq_lseek,
	.release	= single_release,
};
#endif

int fulldump_init(void)
{
	struct proc_dir_entry *proc_dir_entry = NULL;

	if (check_himntn(HIMNTN_NAME_BOOTDUMP_SWITCH) == 0) {
		pr_err("fulldump is not enabled\n");
		return 0;
	}

#ifdef CONFIG_DFX_FUSE_DUMP_SWITCH
	if (g_oem_pk_suffix == COMMERCIAL_FUSE_SUFFIX) {
		pr_err("fuse device do not need dump.\n");
		return 0;
	}
#endif

	proc_dir_entry = proc_create(RESIZE_RESULT_NAME, RESIZE_PROC_RIGHT, NULL, &resizecb_proc_fops);
	if (!proc_dir_entry) {
		pr_err("proc_create RESIZE_RESULT_NAME fail\n");
		return -1;
	}
	return 0;
}

early_initcall(fulldump_init);

