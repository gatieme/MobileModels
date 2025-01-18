/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: efuse source file to provide custom service with smc
 * Create: 2023/01/30
 */

#include <platform_include/see/bl31_smc.h> /* smc_id */
#include <platform_include/see/efuse_driver.h>
#include <securec.h>               /* memset_s */
#include <linux/bits.h>            /* BITS_PER_BYTE */
#include <linux/kernel.h>            /* BITS_PER_BYTE */
#include <linux/mutex.h>           /* mutex_lock */
#include "../efuse_utils.h"           /* efuse_min */
#include "../efuse_plat.h"            /* efuse_err */
#include "../efuse_call.h"             /* efuse_call_args */

static DEFINE_MUTEX(g_efuse_rw_lock);

#define BL31_CRC_TABLE_SIZE                      256
#define BYTE_TO_BIT_SIZE                         8

static void init_crctable(u32 *pcrc32tab, u32 table_size)
{
	u32 i;
	u32 j;
	u32 crc;

	for (i = 0; i < table_size; i++) {
		crc = i;
		for (j = 0; j < BYTE_TO_BIT_SIZE; j++) {
			if (crc & 1)
				crc = (crc >> 1) ^ 0xEDB88320;  /* 0xEDB88320: crc32 const number */
			else
				crc = crc >> 1;
		}
		pcrc32tab[i] = crc;
	}
}

static u32 efuse_gen_crc32(const u8 *buf, u32 buf_size)
{
	u32 i;
	u32 crc = 0xFFFFFFFF;   /* crc initial number */
	u32 crc32tab[BL31_CRC_TABLE_SIZE] = { 0 };

	if (!buf)
		return crc;

	/* if buf is NULL, cpu will report this error. we don't care buf is NULL or not */
	init_crctable(crc32tab, efuse_array_size(crc32tab));
	for (i = 0; i < buf_size; i++)
		crc = crc32tab[(unsigned char)crc ^ buf[i]] ^ (crc >> BITS_PER_BYTE);
	crc = ~crc;
	return crc;
}

static u32 efuse_send_read_signal(u32 smc_id, u32 *id, u32 *recv_size, u32 *recv_check)
{
	u32 ret;
	struct efuse_call_args args = { 0 };

	args.arg0 = smc_id;
	ret = efuse_smc(&args);
	if (ret != EFUSE_OK) {
		efuse_err("error, smc failed, smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return EFUSE_SMC_PROC_ERR;
	}

	*id = (u32)args.arg1;
	*recv_size = (u32)args.arg2;
	*recv_check = (u32)args.arg3;

	return EFUSE_OK;
}

static u32 efuse_send_write_signal(u32 smc_id, u32 id, u32 send_size, u32 send_check)
{
	u32 ret;
	struct efuse_call_args args = { 0 };

	args.arg0 = smc_id;
	args.arg1 = id;
	args.arg2 = send_size;
	args.arg3 = send_check;
	ret = efuse_smc(&args);
	if (ret != EFUSE_OK) {
		efuse_err("error, smc failed, smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return EFUSE_SMC_PROC_ERR;
	}

	return EFUSE_OK;
}

static u32 efuse_recv_buffer(u32 id, u8 *buf, u32 size, u32 recv_size)
{
	u32 ret;
	u32 cur_size;
	u32 offset = 0;
	struct efuse_call_args args = { 0 };

	if (recv_size > size) {
		efuse_err("error, overflow, size=%u, need=%u\n", size, recv_size);
		return EFUSE_INVALID_PARAM_ERR;
	}

	while (recv_size > 0) {
		cur_size = efuse_min(recv_size, (u32)sizeof(u32));
		args.arg0 = EFUSE_BL31_KERNEL_READ_BUFFER;
		args.arg1 = id;
		args.arg2 = offset;
		args.arg3 = cur_size;
		ret = efuse_smc(&args);
		if (ret != EFUSE_OK) {
			efuse_err("error, read_buf ret=0x%08x, id=0x%x, cur_size=%u, offset=%u\n",\
				  ret, id, cur_size, offset);
			return EFUSE_SMC_PROC_ERR;
		}

		if (memcpy_s((void *)&buf[offset], size - offset, (void *)&args.arg1, cur_size) != EOK) {
			efuse_err("error, memcpy_s failed\n");
			return EFUSE_OVERFLOW_ERR;
		}

		offset += cur_size;
		recv_size -= cur_size;
	}

	return EFUSE_OK;
}

static u32 efuse_send_buffer(u32 id, u8 *src, u32 send_size)
{
	u32 ret;
	u32 cur_size;
	u32 offset = 0;
	struct efuse_call_args args = { 0 };

	while (send_size > 0) {
		cur_size = efuse_min(send_size, (u32)sizeof(u32));
		args.arg0 = EFUSE_BL31_KERNEL_WRITE_BUFFER;
		args.arg1 = id;
		args.arg2 = offset;
		args.arg3 = cur_size;
		if (memcpy_s((void *)&args.arg4, sizeof(args.arg4), (void *)&src[offset], cur_size) != EOK) {
			efuse_err("error, memcpy_s failed\n");
			return EFUSE_OVERFLOW_ERR;
		}

		ret = efuse_smc(&args);
		if (ret != EFUSE_OK) {
			efuse_err("error, write_buf ret=0x%08x, id=0x%x, cur_size=%u, offset=%u\n",\
				  ret, id, cur_size, offset);
			return EFUSE_SMC_PROC_ERR;
		}

		offset += cur_size;
		send_size -= cur_size;
	}

	return EFUSE_OK;
}

static u32 efuse_check_recv_value(u8 *buf, u32 size, u32 recv_check)
{
	u32 value;

	value = efuse_gen_crc32(buf, size);
	if (value != recv_check) {
		efuse_err("error, check crc value=0x%08x, exp=0x%08x\n", value, recv_check);
		return EFUSE_INVALID_PARAM_ERR;
	}

	return EFUSE_OK;
}

static u32 efuse_gen_checksum(const u8* buf, u32 size)
{
	return efuse_gen_crc32(buf, size);
}

static u32 efuse_custom_read_process(u8 *buf, u32 *size, u32 smc_id)
{
	u32 ret;
	u32 id = 0;         /* received identifier */
	u32 recv_size = 0;  /* received efuse item size, count in u8 */
	u32 recv_check = 0; /* received checksum of efuse item */
	u8 value[EFUSEC_GROUP_MAX_COUNT * sizeof(u32)] = { 0 };

	ret = efuse_send_read_signal(smc_id, &id, &recv_size, &recv_check);
	if (ret != EFUSE_OK) {
		efuse_err("error, start_read smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return EFUSE_SMC_PROC_ERR;
	}

	if (recv_size > *size) {
		efuse_err("error, overflow, size=%u, recv_size=%u\n", *size, recv_size);
		return EFUSE_OVERFLOW_ERR;
	}

	ret = efuse_recv_buffer(id, value, sizeof(value), recv_size);
	if (ret != EFUSE_OK) {
		efuse_err("error, recv_buf smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return ret;
	}

	ret = efuse_check_recv_value(value, recv_size, recv_check);
	if (ret != EFUSE_OK) {
		efuse_err("error, check recv value");
		return ret;
	}

	if (memcpy_s((void *)buf, *size, (void *)&value[0], recv_size) != EOK) {
		efuse_err("error, memcpy_s failed\n");
		return EFUSE_OVERFLOW_ERR;
	}

	*size = recv_size;
	return EFUSE_OK;
}

static u32 efuse_custom_write_process(u8 *buf, u32 size, u32 smc_id)
{
	u32 ret;
	u32 checksum;
	u8 buffer[EFUSEC_GROUP_MAX_COUNT * sizeof(u32)] = { 0 };

	if (memcpy_s((void *)&buffer[0], sizeof(buffer), (void *)buf, size) != EOK) {
		efuse_err("error, memcpy_s failed\n");
		return EFUSE_OVERFLOW_ERR;
	}

	ret = efuse_send_buffer(smc_id, buffer, size);
	if (ret != EFUSE_OK) {
		efuse_err("error, send_buf smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return ret;
	}

	checksum = efuse_gen_checksum(buf, size);

	ret = efuse_send_write_signal(smc_id, smc_id, size, checksum);
	if (ret != EFUSE_OK) {
		efuse_err("error, start_write smc_id=0x%08x, ret=0x%08x\n", smc_id, ret);
		return EFUSE_SMC_PROC_ERR;
	}

	return EFUSE_OK;
}

u32 efuse_custom_read(u8 *buf, u32 *size, u32 fid)
{
	u32 ret;

	if (!buf || !size) {
		efuse_err("error, param is null\n");
		return EFUSE_INVALID_PARAM_ERR;
	}

	mutex_lock(&g_efuse_rw_lock);
	ret = efuse_custom_read_process(buf, size, fid);
	mutex_unlock(&g_efuse_rw_lock);

	return ret;
}

u32 efuse_custom_write(u8 *buf, u32 size, u32 fid)
{
	u32 ret;

	if (!buf) {
		efuse_err("error, buf is null\n");
		return EFUSE_INVALID_PARAM_ERR;
	}

	mutex_lock(&g_efuse_rw_lock);
	ret = efuse_custom_write_process(buf, size, fid);
	mutex_unlock(&g_efuse_rw_lock);

	return ret;
}
