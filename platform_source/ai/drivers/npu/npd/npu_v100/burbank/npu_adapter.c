/*
 * npu_adapter.c
 *
 * about npu adapter
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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
#include "npu_adapter.h"

#include <linux/io.h>
#include <linux/vmalloc.h>
#include <asm/barrier.h>
#include <securec.h>

#include "npu_log.h"

u32 npu_get_feature_bits(void)
{
	return 0;
}

int npu_plat_res_mailbox_send(void *mailbox, unsigned long mailbox_len,
	const void *message, unsigned long message_len)
{
	u8 *message_buf = NULL;
	int ret;

	cond_return_error(message_len > mailbox_len, -1,
		"message len =%d, too long", message_len);

	message_buf = vmalloc(mailbox_len);
	cond_return_error(message_buf == NULL, -1, "message buf alloc failed");

	ret = memcpy_s(message_buf, mailbox_len, message, mailbox_len);
	cond_goto_error(ret != 0, OUT, ret, ret, "memcpy failed. ret=%d\n", ret);

	memcpy_toio(mailbox, message_buf, mailbox_len);
	mb();
OUT:
	vfree(message_buf);
	return ret;
}

int npu_plat_bypass_status(void)
{
	return NPU_NON_BYPASS;
}
