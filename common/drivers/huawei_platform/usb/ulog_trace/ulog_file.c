/*
 * ulog_file.h
 *
 * save adsp log
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#include "ulog_file.h"
#include <linux/version.h>
#include <linux/ktime.h>
#include <linux/time.h>
#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <huawei_platform/log/hw_log.h>

#if IS_ENABLED(HWLOG_TAG)
#undef HWLOG_TAG
#endif
#define HWLOG_TAG ulog_trace
HWLOG_REGIST();

static int g_write_cnt;
static int g_file_max_save = ULOG_FILE_MAX_SAVE;

static void ulog_get_time(struct tm *ptm)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 1, 0)
	struct timespec64 tv;
#else
	struct timeval tv;
#endif

	memset(&tv, 0, sizeof(tv));
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 1, 0)
	ktime_get_real_ts64(&tv);
	time64_to_tm(tv.tv_sec, 0, ptm);
#else
	do_gettimeofday(&tv);
	time_to_tm(tv.tv_sec, 0, ptm);
#endif
}

static void ulog_get_file_name(struct ulog_file *file)
{
	struct tm ctm;

	ulog_get_time(&ctm);
	memset(file->name, 0, sizeof(file->name));
	snprintf(file->name, ULOG_FILE_NAME_SIZE - 1,
		"%s%u-%u-%u_%u.%u.%u",
		ULOG_FILE_PATH,
		ctm.tm_year + ULOG_BASIC_YEAR, ctm.tm_mon + 1,
		ctm.tm_mday, ctm.tm_hour, ctm.tm_min, ctm.tm_sec);
}

static void ulog_check_file(struct ulog_file *file)
{
	struct kstat stat;

	memset(&stat, 0, sizeof(stat));
	vfs_stat(file->name, &stat);

	hwlog_debug("ulog file stat size=%u\n", stat.size);
	if (stat.size > ULOG_FILE_MAX_SIZE) {
		ulog_get_file_name(file);
		hwlog_info("new ulog file %s\n", file->name);
	}
}

static struct file *ulog_open_file(struct ulog_file *file)
{
	struct file *fp = NULL;

	fp = filp_open(file->name, O_WRONLY | O_APPEND, 0644);
	if (!IS_ERR(fp))
		return fp;

	hwlog_info("file %s not exist\n", file->name);
	fp = filp_open(file->name, O_WRONLY | O_CREAT, 0644);
	if (IS_ERR(fp)) {
		hwlog_info("create %s file fail\n", file->name);
		return NULL;
	}

	return fp;
}

static int ulog_write_data(struct file *fp, const char *data, u32 size)
{
	char head[ULOG_DATA_HEAD_SIZE];
	struct tm ctm;
	loff_t pos = 0;
	int ret;

	ulog_get_time(&ctm);
	memset(head, 0, sizeof(head));
	snprintf(head, ULOG_DATA_HEAD_SIZE - 1,
		"\n\nupload time: %u-%u-%u %u:%u:%u\n\n",
		ctm.tm_year + ULOG_BASIC_YEAR, ctm.tm_mon + 1,
		ctm.tm_mday, ctm.tm_hour, ctm.tm_min, ctm.tm_sec);

	ret = vfs_write(fp, head, strlen(head), &pos);
	if (ret != strlen(head)) {
		hwlog_err("write head failed ret=%d\n", ret);
		return -EFAULT;
	}

	ret = vfs_write(fp, data, size, &pos);
	if (ret != size) {
		hwlog_err("write data failed ret=%d\n", ret);
		return -EFAULT;
	}

	return 0;
}

static int ulog_write_file(struct ulog_file *file, const char *data, u32 size)
{
	int ret;
	struct file *fp = NULL;

	fp = ulog_open_file(file);
	if (!fp) {
		hwlog_err("open %s failed\n", file->name);
		return -EFAULT;
	}

	ret = vfs_llseek(fp, 0L, SEEK_END);
	if (ret < 0) {
		hwlog_err("lseek %s failed from end\n", file->name);
		filp_close(fp, NULL);
		return -EFAULT;
	}

	ret = ulog_write_data(fp, data, size);
	if (ret) {
		hwlog_err("write %s failed ret=%d\n", file->name, ret);
		filp_close(fp, NULL);
		return -EFAULT;
	}

	filp_close(fp, NULL);
	return 0;
}

static time64_t ulog_get_file_time(char *path)
{
	struct kstat stat;

	memset_s(&stat, sizeof(stat), 0, sizeof(stat));
	vfs_stat(path, &stat);

	hwlog_info("ulog file stat time=%ld\n", (long)stat.mtime.tv_sec);
	return stat.mtime.tv_sec;
}

static int ulog_delete_file(char *path)
{
	int ret;

	if (!path) {
		hwlog_err("path is invalid\n");
		return -EFAULT;
	}

	ret = ksys_access(path, 0);
	if (ret) {
		hwlog_err("path access failed\n");
		return -EFAULT;
	}

	ret = ksys_unlink(path);
	if (ret) {
		hwlog_err("unlink file failed\n");
		return -EFAULT;
	}
	hwlog_info("unlink file ok\n");
	return 0;
}

static int ulog_ctr_callback(struct dir_context *cb, const char *name,
	int len, loff_t offset, u64 ino, unsigned int type)
{
	int ret;
	time64_t time;
	char buf[ULOG_FILE_NAME_SIZE] = { 0 };
	char file_name[ULOG_FILE_NAME_SIZE] = { 0 };
	struct ulog_getdents_callback *ucb =
		container_of(cb, struct ulog_getdents_callback, ctx);

	if (!ucb) {
		hwlog_info("ucb is null\n");
		return -EFAULT;
	}

	if ((len < 0) || (len > ULOG_FILE_NAME_SIZE - 1)) {
		hwlog_info("length is outsize, len=%d\n", len);
		return -EFAULT;
	}

	if (strncpy_s(file_name, ULOG_FILE_NAME_SIZE, name, len)) {
		hwlog_err("%s: strncpy_s file fail\n", __func__);
		return 0;
	}

	if (!strstr(file_name, ULOG_FILE_NAME))
		return 0;

	if (strlen(file_name) > ULOG_ADSP_FILE_LENGTH) {
		hwlog_info("adsp file length is invalid, file name=%s\n", file_name);
		return 0;
	}

	ret = snprintf_s(buf, ULOG_FILE_NAME_SIZE, ULOG_FILE_NAME_SIZE - 1, "%s%s", ULOG_FILE_DIR, file_name);
	if (ret < 0) {
		hwlog_err("%s: snprintf_s buf fail\n", __func__);
		return 0;
	}

	time = ulog_get_file_time(buf);
	if ((ucb->earliest_file_time == 0) || ((ucb->earliest_file_time > time) && (time != 0))) {
		ucb->earliest_file_time = time;
		ret = snprintf_s(ucb->earliest_file_name, ULOG_FILE_NAME_SIZE, ULOG_FILE_NAME_SIZE - 1, "%s%s", ULOG_FILE_DIR, file_name);
		if (ret < 0)
			hwlog_err("%s: snprintf_s file fail\n", __func__);
	}
	ucb->file_num++;
	return 0;
}

static int ulog_check_size_and_remove(void)
{
	struct file *pfile = NULL;
	mm_segment_t old_fs;
	int ret = 0;
	struct ulog_getdents_callback buffer = {
		.ctx.actor = ulog_ctr_callback,
		.file_num = 0,
		.earliest_file_time = 0,
	};

	memset_s(buffer.earliest_file_name, sizeof(buffer.earliest_file_name), 0, sizeof(buffer.earliest_file_name));

	old_fs = get_fs();
	set_fs(KERNEL_DS);

	pfile = filp_open(ULOG_FILE_DIR, O_RDONLY, 0);
	if (IS_ERR(pfile)) {
		hwlog_err("open dir failed\n");
		set_fs(old_fs);
		return -EFAULT;
	}

	if (!pfile->f_op->iterate && !pfile->f_op->iterate_shared) {
		hwlog_err("iterate and iterate_shared is null\n");
		goto err_out;
	}

	if (pfile->f_op->iterate_shared) {
		ret = pfile->f_op->iterate_shared(pfile, &(buffer.ctx));
		if (ret) {
			hwlog_err("iterate_shared is failed\n");
			goto err_out;
		}
	} else if (pfile->f_op->iterate) {
		ret = pfile->f_op->iterate(pfile, &(buffer.ctx));
		if (ret) {
			hwlog_err("iterate is failed\n");
			goto err_out;
		}
	}

	hwlog_info("adsp file num: %d\n", buffer.file_num);
	if (buffer.file_num > g_file_max_save) {
		hwlog_info("remove original file : %s\n", buffer.earliest_file_name);
		ret = ulog_delete_file(buffer.earliest_file_name);
	}

err_out:
	filp_close(pfile, NULL);
	set_fs(old_fs);
	return ret;
}

int ulog_write(struct ulog_file *file, const char *data, u32 size)
{
	int ret;
	mm_segment_t fs;

	if (!file || !data || (size == 0))
		return -EFAULT;

	ulog_check_file(file);
	if (g_write_cnt % ULOG_FILE_CHECK_CNT == 0) {
		g_write_cnt = 0;
		ret = ulog_check_size_and_remove();
		if (ret)
			return -EFAULT;
	}
	g_write_cnt++;

	fs = get_fs();
	set_fs(KERNEL_DS);
	ret = ulog_write_file(file, data, size);
	set_fs(fs);

	hwlog_debug("write ulog size=%u\n", size);
	return ret;
}

void ulog_init(struct ulog_file *file)
{
	if (!file)
		return;

	ulog_get_file_name(file);
	if (power_cmdline_is_factory_mode())
		g_file_max_save = 30; /* factory version need more adsp log */
}
