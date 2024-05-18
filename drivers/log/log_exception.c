/*
 * log_exception.c
 *
 * drivers to write messages to exception node
 *
 * Copyright (c) Honor Device Co., Ltd. 2017-2019. All rights reserved.
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

#include <log/log_exception.h>

#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/uio.h>
#include <linux/version.h>

#include <log/hw_log.h>
#include <log/hw_logger.h>

#define HWLOG_TAG	log_exception
HILOG_REGIST();

static int CHECK_CODE = LOGGER_CHECK_MAGIC;

#ifdef CONFIG_LOGGER_LEGACY

int logbuf_to_exception(char category, int level, char log_type,
			char sn, void *msg, int msglen)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
	struct iov_iter iter;
#endif
	mm_segment_t oldfs;
	struct file *filp = NULL;
	int ret;
	struct idapheader idaphdr;
	struct iovec vec[5];
	unsigned long vcount = 0;

	if ((!msg) || (msglen < 0)) {
		hilog_err("%s: invalid arguments\n", __func__);
		return -EINVAL;
	}

	filp = filp_open(LOG_EXCEPTION_FS, O_WRONLY, 0);

	if ((!filp) || IS_ERR(filp)) {
		hilog_err("%s: access '%s' failed\n", __func__, LOG_EXCEPTION_FS);
		return -ENODEV;
	}

	idaphdr.level    = level;
	idaphdr.category = category;
	idaphdr.log_type = log_type;
	idaphdr.sn       = sn;

	vec[vcount].iov_base  = &CHECK_CODE;
	vec[vcount++].iov_len = sizeof(CHECK_CODE);
	vec[vcount].iov_base  = (void *)&idaphdr;
	vec[vcount++].iov_len = sizeof(idaphdr);
	vec[vcount].iov_base  = msg;
	vec[vcount++].iov_len = msglen;

	oldfs = get_fs();
	set_fs(KERNEL_DS);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
	iov_iter_init(&iter, WRITE, vec, vcount, iov_length(vec, vcount));
	ret = vfs_iter_write(filp, &iter, &filp->f_pos, 0);
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 9, 0))
	ret = vfs_writev(filp, vec, vcount, &filp->f_pos, 0);
#else
	ret = vfs_writev(filp, vec, vcount, &filp->f_pos);
#endif
	set_fs(oldfs);

	if (ret < 0) {
		hilog_err("%s: write '%s' failed: %d\n",
				__func__, LOG_EXCEPTION_FS, ret);
		filp_close(filp, NULL);
		return -EIO;
	}

	filp_close(filp, NULL);
	return ret;
}
EXPORT_SYMBOL(logbuf_to_exception);

#endif

ssize_t send_hievent(const char sn, const char *msg, ssize_t msg_len)
{
	struct iovec vec[3]; // 3:hievent data vector size
	struct idapheader idaphdr;
	const int magic = CHECK_CODE;

//	pr_info("%s:%s\n", __func__, msg);
	/* according to the arguments, fill the iovec struct  */
	idaphdr.level    = 0;
	idaphdr.category = 0;
	idaphdr.log_type = IDAP_LOGTYPE_CMD;
	idaphdr.sn       = sn;

	vec[0].iov_base = (void *)&magic;
	vec[0].iov_len = sizeof(int);
	vec[1].iov_base = (void *)&idaphdr;
	vec[1].iov_len = sizeof(idaphdr);
	vec[2].iov_base = (void *)msg;
	vec[2].iov_len = msg_len;

	return send_hievent_vector(LOGGER_LOG_EXCEPTION, vec, ARRAY_SIZE(vec));
}
EXPORT_SYMBOL(send_hievent);
