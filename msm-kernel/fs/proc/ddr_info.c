/*
 * ddr_info.c
 *
 * set ddr info API
 *
 * Copyright (c) 2019-2019 Huawei Technologies Co., Ltd.
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

#include <misc/app_info.h>
#include <misc/ddr_info.h>
#include <linux/export.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm-generic/errno-base.h>
#include <linux/soc/qcom/smem.h>
#include <linux/module.h>
#include <asm/setup.h>
#include <linux/version.h>

static char ddr_info_cmd[DDR_INFO_LEN];

static unsigned int cmd_to_res (char str) {
	if (str >= '0' && str <= '9') {
		return (unsigned int)(str - '0');
	}
	if (str >= 'A' && str <= 'F') {
		return (unsigned int)(str - 'A' + 10);
	}
	return UINT_MAX;
}

static int get_ddr_info_cmd(void)
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = strnstr(saved_command_line, "ddr_info=0x",
		COMMAND_LINE_SIZE);
	if (p1 == NULL) {
		pr_err("ddr_info not found in cmdline");
		return -ENODEV;
	}
	p2 = strnchr(p1, strlen(p1), ' ');
	p2 = (p2 == NULL) ? (p1 + DDR_INFO_MAX) : p2;
	if (p2 == NULL) {
		pr_err("ddr_info end not found in cmdline");
		return -ENODEV;
	}
	strlcpy(ddr_info_cmd, p1,
		((p2 - p1 + 1) > DDR_INFO_LEN) ?
			DDR_INFO_LEN : (p2 - p1 + 1));

	return 0;
}

char* get_ddr_vendor_id(unsigned int ddr_vendor_id)
{
	switch (ddr_vendor_id) {
	case SAMSUNG_ID:
		return "SAMSUNG";
	case ELPIDA_ID:
		return "MICRON";
	case HYNIX_ID:
		return "HYNIX";
	case FC_ID:
		return "FC";
	case MICRON_ID:
		return "MICRON";
	default:
		return "UNKNOWN";
	}
	return "UNKNOWN";
}

char* get_ddr_type(unsigned int ddr_type)
{
	switch (ddr_type) {
	case DDR_TYPE_LPDDR1:
		return "LPDDR1";
	case DDR_TYPE_LPDDR2:
		return "LPDDR2";
	case DDR_TYPE_LPDDR3:
		return "LPDDR3";
	case DDR_TYPE_LPDDR4X:
		return "LPDDR4X";
	case DDR_TYPE_LPDDR5:
		return "LPDDR5";
	case DDR_TYPE_LPDDR5X:
		return "LPDDR5X";
	default:
		return "UNKNOWN";
	}
	return "UNKNOWN";
}

void export_ddr_info(unsigned int ddr_vendor_id, unsigned int ddr_size,
	unsigned int ddr_type)
{
	char ddr_info_all[APP_INFO_VALUE_LENTH] = {0};
	char *ddr_info = NULL;
	char ddr_size_info[8] = {0};
	char *ddr_type_info = NULL;
	ddr_info = get_ddr_vendor_id(ddr_vendor_id);

	if (ddr_size >= DDR_SIZE_MIN && ddr_size <= DDR_SIZE_MAX)
		snprintf(ddr_size_info, HW_BUF_LEN_8, "%dGbit", ddr_size);
	else
		snprintf(ddr_size_info, HW_BUF_LEN_8, "UNKNOWN");

	ddr_type_info = get_ddr_type(ddr_type);

	snprintf(ddr_info_all, APP_INFO_VALUE_LENTH - 1, "%s %s %s",
		ddr_info, ddr_size_info, ddr_type_info);
	if (app_info_set("ddr_vendor", ddr_info_all))
		pr_err("Error setting DDR vendor info\n");
	pr_err("DDR VENDOR is : %s", ddr_info_all);
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
void app_info_print_smem(void)
{
	unsigned int ddr_vendor_id;
	/* read share memory and get DDR ID */
	struct smem_exten_huawei_paramater *smem = NULL;
	unsigned int ddr_size;
	unsigned int ddr_type;
	unsigned int ret;
	size_t size = sizeof(*smem);

	ret = qcom_smem_alloc(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, size);
	if (ret < 0 && ret != -EEXIST) {
		if (app_info_set("ddr_vendor", "UNKNOWN"))
			pr_err("Error setting DDR vendor name to UNKNOWN\n");
		pr_err("%s: qcom_smem_alloc failed, %d\n", __func__, ret);
		return;
	}
	smem = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, &size);

	if (smem == NULL) {
		/* Set the vendor name in app_info */
		if (app_info_set("ddr_vendor", "UNKNOWN"))
			pr_err("Error setting DDR vendor name to UNKNOWN\n");
		pr_err("%s: SMEM Error, READING DDR VENDOR NAME", __func__);
		return;
	}

	ddr_vendor_id = smem->lpddr_id;
	ddr_vendor_id &= HW_MASK;

	ddr_size = (smem->lpddr_id >> HW_RIGHT_SHIFT_8) & HW_MASK;
	ddr_type = (smem->lpddr_id >> HW_RIGHT_SHIFT_24) & HW_MASK;

	pr_err("ddr_info %x,%d\n", smem->lpddr_id, ddr_size);

	export_ddr_info(ddr_vendor_id, ddr_size, ddr_type);
}

static int ddr_info_show(struct seq_file *m, void *v)
{
	unsigned int ddr_vendor_id;
	/* read share memory and get DDR ID */
	struct smem_exten_huawei_paramater *smem = NULL;
	unsigned int ddr_size;
	unsigned int tmp_reg_value;
	unsigned int ret;
	size_t size = sizeof(*smem);

	ret = qcom_smem_alloc(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, size);
	if (ret < 0 && ret != -EEXIST) {
		pr_err("%s: qcom_smem_alloc failed, %d\n", __func__, ret);
		return ret;
	}
	smem = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, &size);

	if (smem == NULL) {
		/* Set the vendor name in app_info */
		pr_err("%s: SMEM Error, READING DDR VENDOR NAME", __func__);
		return -EINVAL;
	}
	ddr_vendor_id = smem->lpddr_id;
	ddr_vendor_id &= HW_MASK;

	ddr_size = ((smem->lpddr_id >> HW_RIGHT_SHIFT_8) & HW_MASK) >> 3;

	tmp_reg_value = (ddr_vendor_id & 0xFF) | (ddr_size << 8);
	seq_printf(m, "ddr_info:\n0x%x\n", tmp_reg_value);
	return 0;
}

static int ddrinfo_open(struct inode *inode, struct file *file)
{
	return single_open(file, ddr_info_show, NULL);
}

static const struct file_operations proc_ddrinfo_operations = {
	.open = ddrinfo_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static int __init proc_ddr_info_init(void)
{
	proc_create("ddr_info", 0644, NULL, &proc_ddrinfo_operations);
	app_info_ddr_print();
	return 0;
}

#else
void app_info_ddr_cmd(void)
{
	unsigned int ddr_vendor_id;
	unsigned int ddr_size;
	unsigned int ddr_type;

	if (get_ddr_info_cmd() < 0) {
		return;
	}

	ddr_type = 16 * cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET]) +
		cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET + 1]);
	ddr_size = 16 * cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET + 2]) +
		cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET + 3]);
	ddr_vendor_id = 16 * cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET + 4]) +
		cmd_to_res(ddr_info_cmd[DDR_INFO_OFFSET + 5]);
	pr_err("ddr_vendor:0x%x,ddr_size:0x%x,ddr_type:0x%x\n",
		ddr_vendor_id, ddr_size, ddr_type);

	export_ddr_info(ddr_vendor_id, ddr_size << 3, ddr_type);
}

static int ddr_info_proc_show(struct seq_file *m, void *v)
{
	unsigned int ddr_info = 0;
	char ddr_info_prt[HW_BUF_LEN_8];

	if (get_ddr_info_cmd() < 0) {
		return -1;
	}
	memcpy(ddr_info_prt, ddr_info_cmd + DDR_INFO_OFFSET + 2, DDR_INFO_PRT);
	ddr_info_prt[DDR_INFO_PRT] = '\0';
	seq_printf(m, "ddr_info:\n0x%s\n", ddr_info_prt);

	return 0;
}

static int ddrinfo_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, ddr_info_proc_show, NULL);
}

static const struct proc_ops ddrinfo_proc_fops = {
	.proc_open = ddrinfo_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int __init proc_ddr_info_init(void)
{
	proc_create("ddr_info", 0644, NULL, &ddrinfo_proc_fops);
	app_info_ddr_print();
	return 0;
}
#endif

void app_info_ddr_print(void)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	app_info_print_smem();
#else
	app_info_ddr_cmd();
#endif;
}

module_init(proc_ddr_info_init);

