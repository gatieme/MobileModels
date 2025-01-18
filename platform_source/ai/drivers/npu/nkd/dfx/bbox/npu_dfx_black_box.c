/*
 * npu_dfx_black_box.c
 *
 * about npu dfx black box
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#include "npu_dfx_black_box.h"

#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/timekeeping.h>
#include <linux/uaccess.h>
#include <linux/idr.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/stat.h>
#include <linux/io.h>
#include <linux/pci.h>
#include <linux/vmalloc.h>
#include <linux/notifier.h>
#include <linux/iommu/mm_svm.h>
#include <platform_include/basicplatform/linux/dfx_noc_modid_para.h>
#include <platform_include/basicplatform/linux/rdr_pub.h>
#include <platform_include/basicplatform/linux/rdr_platform.h>
#ifdef CONFIG_SELF_HEALING
#include <platform_include/basicplatform/linux/nve/nve_ap_kernel_interface.h>
#include <platform_include/basicplatform/linux/dfx_bbox_diaginfo.h>
#include "bbox_diaginfo_id_def.h"
#endif
#include <securec.h>

#include "npu_shm.h"
#include "npu_platform.h"
#include "mntn_public_interface.h"
#include "mntn_subtype_exception.h"
#include "npu_platform_register.h"
#include "npu_pm_framework.h"
#include "npu_dfx_black_box_adapter.h"
#include "npd_interface.h"
#include "npu_counter.h"
#include "npu_ddr_map.h"
#ifndef CONFIG_NPU_SWTS
#include "npu_dfx_log.h"
#endif

#define NPU_DUMP_BBOXINFO_TIMEOUT_MSEC 2000

static vir_addr_t g_bbox_addr_vir;

static struct npu_mntn_private_s *g_npu_mntn_private;

#define NPU_TASK_DUMP_NUM 10
#define NPU_RDR_RECORD_NUM 5
#define NPU_RDR_RECORD_TIME_MAX (24 * 60 * 60)

enum {
	NPU_TASK_DUMP_IDLE,
	NPU_TASK_DUMP_INCOMPLETE,
	NPU_TASK_DUMP_COMPLETE
};
struct npu_task_dump_info_manager {
	struct npu_task_dump_info info[NPU_TASK_DUMP_NUM];
	uint8_t flag[NPU_TASK_DUMP_NUM];
	uint8_t wptr;
};
static struct npu_task_dump_info_manager g_npu_task_dump_manager;
static struct bbox_smmu_exp_info g_smmu_exp_info;

#ifdef CONFIG_SELF_HEALING
struct npu_rdr_record_info {
	enum rdr_npu_system_error_type error_code;
	time64_t stamp;
};
struct npu_rdr_record_info_manager {
	struct npu_rdr_record_info info[NPU_RDR_RECORD_NUM];
	uint8_t start;
	uint8_t end;
	struct mutex lock;
};
static struct npu_rdr_record_info_manager g_npu_rdr_record_manager;
#endif

/* The header file is defined separately in TS(log_agent.h) and RUNTIME(dlogd.h) module.
   An unified header file is NEVER used and is not defined in kernel code.
   Therefore, it is defined here for bbox */
typedef struct tslog_header {
	unsigned short magic;
	unsigned short reserved;
	unsigned int length;
	unsigned int log_level;
} tslog_header_t;

/*
 * Description: npu_mntn_copy_reg_to_bbox
 * input: const char *src_addr, unsigned int* offset, unsigned int len
 * output: NA
 * return: void
 */
int npu_mntn_copy_reg_to_bbox(const char *src_addr,
	unsigned int len)
{
	unsigned int left_len;
	unsigned int rdr_left_len;
	int ret;

	if (g_npu_mntn_private == NULL) {
		npu_drv_err("g_npu_mntn_private is NULL!\n");
		return -EINVAL;
	}

	if ((src_addr == NULL) || (len == 0) ||
		(g_npu_mntn_private->mntn_info.rdr_addr == NULL)) {
		npu_drv_err("input parameter is error!\n");
		return -EINVAL;
	}

	if (g_npu_mntn_private->mntn_info.bbox_addr_offset >
		g_npu_mntn_private->mntn_info.npu_ret_info.log_len) {
		npu_drv_err("bbox_addr_offset is error!\n");
		return -EINVAL;
	}

	if (g_npu_mntn_private->mntn_info.bbox_addr_offset >
		NPU_BBOX_MEM_MAX - sizeof(exce_module_info_t)) {
		npu_drv_err("bbox_addr_offset is error!\n");
		return -EINVAL;
	}

	left_len = NPU_BBOX_MEM_MAX - sizeof(exce_module_info_t) -
		g_npu_mntn_private->mntn_info.bbox_addr_offset;
	rdr_left_len = g_npu_mntn_private->mntn_info.npu_ret_info.log_len -
		g_npu_mntn_private->mntn_info.bbox_addr_offset;

	if (len > left_len || len > rdr_left_len) {
		npu_drv_warn("bbox buf is full, turn to the start to reuse, "
			"len=%u, left_len=%u, rdr_left_len=%u\n",
			len, left_len, rdr_left_len);
		g_npu_mntn_private->mntn_info.bbox_addr_offset = 0;
		rdr_left_len = g_npu_mntn_private->mntn_info.npu_ret_info.log_len;
	}

	if (len > rdr_left_len) {
		npu_drv_err("message is too long to write into bbox buffer, "
			"len=%u, rdr_left_len=%u\n", len, rdr_left_len);
		len = rdr_left_len;
	}

	ret = memcpy_s(((char *)g_npu_mntn_private->mntn_info.rdr_addr +
		g_npu_mntn_private->mntn_info.bbox_addr_offset), len, src_addr, len);
	cond_return_error(ret != 0, -EINVAL, "memcpy_s failed, ret=%d\n", ret);

	g_npu_mntn_private->mntn_info.bbox_addr_offset += len;

	return 0;
}
EXPORT_SYMBOL(npu_mntn_copy_reg_to_bbox);

static void npu_mntn_log_add_exception_type(unsigned int modid,
	char log_buf[], unsigned int buf_size)
{
	int ret;

	switch (modid) {
	case (unsigned int)EXC_TYPE_TS_AICORE_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : aic exception\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_AICORE_TIMEOUT:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : aic timeout\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_AIV_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : aiv exception\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_AIV_TIMEOUT:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : aiv timeout\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_SDMA_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : sdma exception\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_SDMA_TIMEOUT:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : sdma timeout\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_TS_RUNNING_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : ts running exception\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_TS_RUNNING_TIMEOUT:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : ts running timeout\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_OS_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : OS running exception\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_TS_INIT_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : ts init exception\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_NPU_POWERUP_FAIL:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : npu powerup fail\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_NPU_POWERDOWN_FAIL:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : npu powerdown fail\r\n");
		break;
	case (unsigned int)RDR_EXC_TYPE_NPU_SMMU_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : npu smmu exception\r\n");
		break;
	case (unsigned int)RDR_TYPE_HWTS_BUS_ERROR:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : hwts bus error\r\n");
		break;
	case (unsigned int)RDR_TYPE_HWTS_EXCEPTION_ERROR:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : hwts exception error\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_AICORE_EFF_EXCEPTION:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : eff aic exception\r\n");
		break;
	case (unsigned int)EXC_TYPE_TS_AICORE_EFF_TIMEOUT:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : eff aic timeout\r\n");
		break;
	default:
		ret = snprintf_s(log_buf, buf_size, buf_size - 1, "%s",
			"NPU exception info : no exception\r\n");
		break;
	}

	cond_return_void(ret < 0, "snprintf_s failed, ret = %d", ret);
}

/*
 * Description: npu_get_peri_reg_info
 * input:	struct device *dev, char *buf, int len
 * output:	NA
 * return:	0: succes,  -1: error
 */
static int npu_get_peri_reg_info(struct device *dev, char *buf, unsigned int len)
{
	char *ptr = buf;
	unsigned int value, i, j;
	int remain = (int)len;
	int ret = 0;
	void __iomem  *vaddr = NULL;
	struct npu_dump_reg *cur_reg = NULL;

	buf[0] = 0;
	if (ARRAY_SIZE(peri_regs) == 0)
		return -1;

	for (i = 0; i < ARRAY_SIZE(peri_regs); ++i) {
		cur_reg = peri_regs + i;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		vaddr = devm_ioremap(dev, cur_reg->base, cur_reg->range);
#else
		vaddr = devm_ioremap_nocache(dev, cur_reg->base, cur_reg->range);
#endif
		if (vaddr == NULL) {
			npu_drv_err("ioremap failed\n");
			continue;
		}

		for (j = 0; j < cur_reg->reg_num; ++j) {
			value = ioread32(vaddr + cur_reg->regs[j].offset);
			ret = snprintf_s(ptr, (size_t)remain, (size_t)remain - 1, "%s = 0x%x\n", cur_reg->regs[j].desc, value);
			if (ret < 0) {
				npu_drv_err("snprintf_s failed, remain=%d\n", remain);
				devm_iounmap(dev, vaddr);
				return -1;
			}
			ptr += ret;

			if (remain <= ret)
				break;

			remain -= ret;
		}

		devm_iounmap(dev, vaddr);

		if (remain <= ret)
			break;
	}

	return 0;
}

/*
 * Description: npu_mntn_dump_by_modid
 * input:	unsigned int modid
 * output:	NA
 * return:	void
 */
static void npu_mntn_dump_by_modid(unsigned int modid)
{
	int ret;
	char log_buf[SMMU_EXCP_INFO_BUF_LEN];
	struct npu_platform_info *plat_info = npu_plat_get_info();

	cond_return_void(plat_info == NULL, "get plat info fail\n");
	cond_return_void(plat_info->pdev == NULL, "plat_info->pdev is NULL\n");

	if ((modid == RDR_EXC_TYPE_NOC_NPU7) || (modid == RDR_EXC_TYPE_NPU_SMMU_EXCEPTION)) {
		if (mm_get_smmu_info(plat_info->pdev, log_buf, sizeof(log_buf)))
			npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		ret = npu_get_peri_reg_info(plat_info->pdev, log_buf, sizeof(log_buf));
		if (ret == 0)
			npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	}
}

/*
 * Description: to dump tsch log from share memory
 * input:	void
 * output:	NA
 * return:	void
 */
#ifndef CONFIG_NPU_SWTS
static void npu_bbox_dump_tsch_log(void)
{
	const char *tsch_log_title = "\r\n[TSCH log dump]:\r\n";
	char *dump_buf = NULL;
	char log_buf[NPU_BUF_LEN_MAX + 2]; /* +2, means include \r\n in head of each log */
	uint32_t pos = 0;
	uint32_t pos_max = (uint32_t)(NPU_BUF_TSCH_LEN - sizeof(tslog_header_t));
	tslog_header_t *tslog_header = NULL;
	errno_t rc = EOK;

	dump_buf = (char *)kmalloc(NPU_BUF_TSCH_LEN, GFP_KERNEL);
	cond_return_void(dump_buf == NULL, "kmalloc dump_buf fail\n");
	if (log_tsch_dump(dump_buf, NPU_BUF_TSCH_LEN) != IDE_DRV_OK) {
		npu_drv_err("log_tsch_dump fail\n");
		kfree(dump_buf);
		return;
	}

	npu_mntn_copy_reg_to_bbox(tsch_log_title, (unsigned int)strlen(tsch_log_title));

	while (pos < pos_max) {
		/* to parse tslog: binary to text */
		if (dump_buf[pos] == 0xCD && dump_buf[pos + 1] == 0xAB) {
			tslog_header = (tslog_header_t *)&dump_buf[pos];
			pos += (uint32_t)sizeof(tslog_header_t);
			if (tslog_header->length <= NPU_BUF_LEN_MAX && tslog_header->length > 0) {
				if (pos + tslog_header->length > NPU_BUF_TSCH_LEN) {
					npu_drv_err("invalid tslog len = %u in pos = 0x%x", tslog_header->length, pos);
					continue;
				}

				log_buf[0] = '\r';
				log_buf[1] = '\n';
				rc = memcpy_s(&log_buf[2], NPU_BUF_LEN_MAX, &dump_buf[pos], tslog_header->length);
				if (rc != EOK)
					npu_drv_err("memcpy_s failed\n");
				log_buf[NPU_BUF_LEN_MAX + 1] = '\0'; /* to avoid if no \0 in original tslog */

				npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			} else {
				npu_drv_err("invalid tslog len = %u", tslog_header->length);
			}

			pos += tslog_header->length;
		} else {
			pos++;
		}
	}

	kfree(dump_buf);
}
#endif

static void npu_mntn_query_mem_region(uint8_t wptr)
{
	int ret;
	int mem_id = 0;
	uint32_t va_offset = 0;
	uint64_t bad_va = g_smmu_exp_info.exp_info.bad_va;
	char log_buf[NPU_BUF_LEN_MAX + 1] = {0};
	const int max_mem_id = sizeof(struct mem_region_info)/sizeof(struct buffer_info);
	struct buffer_info* buffer = &(g_npu_task_dump_manager.info[wptr].mem_region.weight_buffer);

	if (bad_va == 0) {
		ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
				"SMMU exeption occurs! [event_id]: 0x%x, bad va is null\r\n",
				g_smmu_exp_info.exp_info.event_id);
		cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
		(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		return;
	}

	// cv fd scenario, addr&size is 0
	if (buffer->addr == 0 || buffer->size == 0) {
		ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
				"SMMU exeption occurs! [event_id]: 0x%x, it is the fd parameter scenario of cv.\r\n",
				g_smmu_exp_info.exp_info.event_id);
		cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
		(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		return;
	}

	// query which mem region the bad_va is in
	do {
		npu_drv_err("idx:%d, addr:0x%lx, size:0x%x", mem_id, buffer->addr, buffer->size);
		if (bad_va >= buffer->addr && bad_va < buffer->addr + buffer->size) {
			va_offset = bad_va - buffer->addr;
			break;
		}
		buffer++;
		mem_id++;
	} while (mem_id < max_mem_id);

	if (mem_id != max_mem_id) {
		ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
				"SMMU exeption occurs! [event_id]: 0x%x"
				"[va_offset]: 0x%x, [buffer_idx]: %d\r\n",
				g_smmu_exp_info.exp_info.event_id, va_offset, mem_id);
		cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
	} else {
		ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
		"SMMU exeption occurs! Bad_va is out of range! [event_id]: 0x%x\r\n",
		g_smmu_exp_info.exp_info.event_id);
		cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
	}
	(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
}

static void npu_mntn_copy_smmu_exp_info(uint8_t wptr)
{
	int ret;
	char log_buf[NPU_BUF_LEN_MAX + 1] = {0};

	if (g_smmu_exp_info.record_flag == 1) {
		npu_mntn_query_mem_region(wptr);
		g_smmu_exp_info.record_flag = 0;
	} else {
		ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX, "No SMMU exeption!\r\n");
		cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
		(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	}
}

static void npu_mntn_dump_task_info(void)
{
	uint8_t wptr = g_npu_task_dump_manager.wptr;
	char log_buf[NPU_BUF_LEN_MAX + 1] = {0};
	int try_count;
	int ret;
	int count = 0;

	do {
		wptr = wptr == 0 ? (NPU_TASK_DUMP_NUM - 1) : wptr - 1;
		// if incomplete then wait
		try_count = NPU_DUMP_BBOXINFO_TIMEOUT_MSEC;
		while (try_count-- > 0 && g_npu_task_dump_manager.flag[wptr] == NPU_TASK_DUMP_INCOMPLETE)
			msleep(1);
		if (g_npu_task_dump_manager.info[wptr].func_name[0] != 0) {
			if (count == 0) {
				ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
					"\r\nNPU error task info:\r\n");
					cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
					(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			}
			ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
				"[FuncName]: %s, [ModelId]: %u, [StreamId]: %u, [TaskId]: %u, "
				"[RtErrCode]: 0x%x, [TaskType]: %u, [BlockDim]: %u, [Priority]: %u, "
				"[ProcessName]: %s, [uid]: %u, [ModelName]: %s\r\n",
				g_npu_task_dump_manager.info[wptr].func_name, g_npu_task_dump_manager.info[wptr].model_id,
				g_npu_task_dump_manager.info[wptr].strm_id, g_npu_task_dump_manager.info[wptr].task_id,
				g_npu_task_dump_manager.info[wptr].complete_err, g_npu_task_dump_manager.info[wptr].task_type,
				g_npu_task_dump_manager.info[wptr].block_dim, g_npu_task_dump_manager.info[wptr].priority,
				g_npu_task_dump_manager.info[wptr].process_name, g_npu_task_dump_manager.info[wptr].uid,
				g_npu_task_dump_manager.info[wptr].model_name);
			cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
			(void)npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			npu_mntn_copy_smmu_exp_info(wptr);
			count++;
		}
	} while (wptr != g_npu_task_dump_manager.wptr);
}

/*
 * Description: npu_mntn_write_reg_log
 * input:	void
 * output:	NA
 * return:	void
 */
static void npu_mntn_write_reg_log(void)
{
	char log_buf[NPU_BUF_LEN_MAX + 1] = {0};
	unsigned int modid;
	int ret = 0;

	ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
		"\r\nNPU exception info : core_id = 0x%x\r\n",
		g_npu_mntn_private->mntn_info.dump_info.coreid);
	cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
	npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));

	ret = snprintf_s(log_buf, NPU_BUF_LEN_MAX + 1, NPU_BUF_LEN_MAX,
		"NPU exception info : exception_code =0x%x\r\n",
		g_npu_mntn_private->mntn_info.dump_info.modid);
	cond_return_void(ret < 0, "snprintf_s failed, ret = %d\n", ret);
	npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));

	modid = g_npu_mntn_private->mntn_info.dump_info.modid;
	npu_mntn_log_add_exception_type(modid, log_buf, sizeof(log_buf));
	npu_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));

	npu_mntn_dump_task_info();

#ifndef CONFIG_NPU_SWTS
	/* dump tsch log */
	npu_bbox_dump_tsch_log();
#endif

	npu_mntn_dump_by_modid(modid);
}

static void npu_rdr_regs_dump(void *dest, const void *src, size_t len)
{
	size_t remain;
	size_t mult;
	size_t i;
	u64 *u64_dst = NULL;
	u64 *u64_src = NULL;

	remain = len % sizeof(u64);
	mult = len / sizeof(u64);
	u64_dst = (u64 *)dest;
	u64_src = (u64 *)src;

	for (i = 0; i < mult; i++) {
		*u64_dst = *u64_src;
		npu_drv_debug("index:%llu u64_dst:0x%pK= 0x%016lx  u64_src:0x%pK = 0x%016lx",
			i, (u64)u64_dst, *u64_dst, (u64)(u64_src), *u64_src);
		u64_dst++;
		u64_src++;
	}

	for (i = 0; i < remain; i++)
		*((u8 *)u64_dst + i) = *((u8 *)u64_src + i);
}

static void npu_mntn_dump_npucrg(
	const struct npu_mem_desc *dump_region, vir_addr_t dest_addr)
{
	u8 *source_addr = NULL;
	uint32_t pericrg_stat;
	u64 pericrg_base;
	struct npu_platform_info *plat_info = npu_plat_get_info();

	if (plat_info == NULL) {
		npu_drv_err("get platform irq failed\n");
		return;
	}

	pericrg_base = (u64) (uintptr_t)plat_info->dts_info.reg_vaddr[NPU_REG_PERICRG_BASE];
	if (pericrg_base == 0) {
		npu_drv_err("pericrg_base is 0\n");
		return;
	}
	npu_drv_debug("dump region: base=0x%pK len=0x%llx",
		dump_region->base, dump_region->len);

	pericrg_stat = readl_relaxed((const volatile void *)(
		uintptr_t)soc_crgperiph_npucrg_stat_addr(pericrg_base));
	if (npu_bitmap_get(pericrg_stat,
		SOC_CRGPERIPH_NPUCRG_IP_RST_BIT_OFFSET_START) == 0x1) {
		npu_drv_err("NPU CRG has not been unreset!\n");
		return;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	source_addr = ioremap(dump_region->base, dump_region->len);
#else
	source_addr = ioremap_nocache(dump_region->base, dump_region->len);
#endif
	if (source_addr == NULL) {
		npu_drv_err("ioremap_nocache failed, len=0x%llx\n", dump_region->len);
		npu_drv_debug("ioremap_nocache failed, base=0x%pK", dump_region->base);
		return;
	}
	npu_rdr_regs_dump((void *)(uintptr_t)dest_addr, source_addr,
		dump_region->len);
	iounmap(source_addr);
}

static void npu_mntn_dump_region(void)
{
	u32 i;
	vir_addr_t target_addr = g_bbox_addr_vir + BBOX_ADDR_LEN;
	struct npu_mem_desc *dump_region = NULL;
	struct npu_platform_info *plat_info = npu_plat_get_info();
	struct npu_dev_ctx *dev_ctx = NULL;

	for (i = 0; i < NPU_DUMP_REGION_MAX; i++) {
		dump_region = &plat_info->dts_info.dump_region_desc[i];
		if (dump_region == NULL) {
			npu_drv_err("dump_region %d is NULL", i);
			break;
		}
		if (dump_region->base == 0 || dump_region->len == 0) {
			npu_drv_warn("unsupport to dump region in this platform, dump_region %d len=0x%lx", i, dump_region->len);
			npu_drv_debug("dump_region base=0x%pK", dump_region->base);
			break;
		}
		/* from the last area of npu_bbox */
		target_addr = target_addr - dump_region->len;

		npu_drv_debug("dump region %d: base=0x%pK len=0x%llx, bbox offset=0x%llx",
			i, dump_region->base, dump_region->len,
			target_addr - g_bbox_addr_vir);

		if ((target_addr < g_bbox_addr_vir) ||
			(target_addr > (g_bbox_addr_vir + BBOX_ADDR_LEN))) {
			npu_drv_err("dump_region %d ' out of range; len:0x%llx is error",
				i, dump_region->len);
			return;
		}

		if (i == NPU_DUMP_REGION_NPU_CRG) {
			dev_ctx = get_dev_ctx_by_id(0);
			if (dev_ctx == NULL) {
				npu_drv_err("dev_ctx 0 is null\n");
				return;
			}

			mutex_lock(&dev_ctx->pm.npu_power_mutex);

			if (dev_ctx->pm.power_stage != NPU_PM_UP)
				npu_drv_warn("can not dump npu_crg because npu is powered off\n");
			else if (npu_bitmap_get(dev_ctx->pm.work_mode, NPU_SEC))
				npu_drv_warn("can not dump npu_crg because npu is in secure mode\n");
			else
				npu_mntn_dump_npucrg(dump_region, target_addr);

			mutex_unlock(&dev_ctx->pm.npu_power_mutex);
		}
	}
}

/*
 * Description: npu_mntn_dump
 * input: NA
 * output: NA
 * return: NA
 */
static void npu_mntn_dump(void)
{
	exce_module_info_t *module_info = NULL;
	struct npu_platform_info *plat_info = npu_plat_get_info();
	vir_addr_t bbox_tslog_addr_vir;
	size_t addr_vir_ofs;
	if (plat_info == NULL) {
		npu_drv_err("get platform info null\n");
		return;
	}

	npu_mntn_write_reg_log();

	module_info = (exce_module_info_t *)(uintptr_t)(g_bbox_addr_vir);
	cond_return_void(module_info == 0, "module_info is invalid");
	if (module_info->exp_message_len > module_info->buffer_len ||
		module_info->exp_message_len == 0) {
			npu_drv_warn("exp_message_len = 0x%x is more than the max len or is 0\n",
				module_info->exp_message_len);
	} else {
		addr_vir_ofs = sizeof(exce_module_info_t);
		bbox_tslog_addr_vir = g_bbox_addr_vir + addr_vir_ofs;
		npu_mntn_copy_reg_to_bbox((void *)((uintptr_t)bbox_tslog_addr_vir),
			module_info->exp_message_len);
	}

	npu_mntn_dump_region();

	/* please DO CALL this callback function, or bbox would timeout */
	if (g_npu_mntn_private->mntn_info.dump_info.cb != NULL) {
		g_npu_mntn_private->mntn_info.dump_info.cb(
			g_npu_mntn_private->mntn_info.dump_info.modid,
			g_npu_mntn_private->mntn_info.dump_info.coreid);
	} else {
		npu_drv_err("rdr callback is null");
	}
}

/*
 * Description: npu_mntn_reset_work
 * input: struct work_struct *work
 * output: NA
 * return: NA
 */
static void npu_mntn_reset_work(
	struct work_struct *work __attribute__((__unused__)))
{
	struct npd_registry *npd = get_npd();

	cond_return_void(npd == NULL, "npd ptr is NULL\n");
	npd->npd_notify(NULL, NPD_NOTICE_MNTN_RESET, 0, 0);  // plat_mntn_reset
}

/*
 * Description : npu_rdr_resource_init
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
static int npu_rdr_resource_init(void)
{
#ifdef CONFIG_SELF_HEALING
	int ret;

	ret = memset_s(&g_npu_rdr_record_manager, sizeof(g_npu_rdr_record_manager), 0, sizeof(g_npu_rdr_record_manager));
	cond_return_error(ret != 0, -EINVAL,  "memset_s failed. ret=%d\n", ret);
	mutex_init(&g_npu_rdr_record_manager.lock);
#endif

	g_npu_mntn_private = kzalloc(
		sizeof(struct npu_mntn_private_s), GFP_KERNEL);
	if (g_npu_mntn_private == NULL) {
		npu_drv_err("failed to allocate memory!");
		return -ENOMEM;
	}

	g_npu_mntn_private->rdr_wq =
		create_singlethread_workqueue("npu_mntn_rdr_wq");
	if (g_npu_mntn_private->rdr_wq == NULL) {
		npu_drv_err("create_singlethread_workqueue is failed!");
		kfree(g_npu_mntn_private);
		g_npu_mntn_private = NULL;
		return -EINTR;
	}

	INIT_WORK(&g_npu_mntn_private->reset_work, npu_mntn_reset_work);
	return 0;
}

static void npu_rdr_resource_destroy(void)
{
	if (g_npu_mntn_private != NULL) {
		destroy_workqueue(g_npu_mntn_private->rdr_wq);
		kfree(g_npu_mntn_private);
		g_npu_mntn_private = NULL;
	}
#ifdef CONFIG_SELF_HEALING
	mutex_destroy(&g_npu_rdr_record_manager.lock);
#endif
}

/* when smmu is exception, platform  callback this func report */
static int npu_smmu_excp_callback(struct notifier_block *nb,
	unsigned long value, void *data)
{
	(void)nb;
	(void)value;
	u8 smmu_event_id;

	if (data == NULL)
		return -ENOMEM;

	// data pointer to u64 evt[EVTQ_ENT_DWORDS]
	smmu_event_id = ((u64 *)data)[0] & 0xFF;
	g_smmu_exp_info.exp_info.event_id = smmu_event_id;
	g_smmu_exp_info.exp_info.bad_va = ((u64 *)data)[2];
	g_smmu_exp_info.record_flag = 1;
	npu_drv_warn("evt_id: 0x%x!", smmu_event_id);
	// fiter arm_smmu_ai event 0x10
	if (smmu_event_id != SMMU_ADDR_TRANSLATION_FAULT &&
		smmu_event_id != SMMU_BAD_CD_FAULT)
		npu_rdr_exception_report(RDR_EXC_TYPE_NPU_SMMU_EXCEPTION);
	return 0;
}

static struct notifier_block smmu_excp_notifier = {
	.notifier_call = npu_smmu_excp_callback,
};

/*
 * Description : npu_rdr_register_exception
 * input : void
 * output : NA
 * rdr_register_exception : ret == 0 is fail. ret > 0 is success.
 */
int npu_rdr_register_exception(void)
{
	size_t size;
	unsigned int ret;
	unsigned long index;

	size = sizeof(npu_rdr_excetption_info) /
		sizeof(npu_rdr_excetption_info[0]);
	for (index = 0; index < size; index++) {
		/* error return 0, ok return modid */
		ret = rdr_register_exception(&npu_rdr_excetption_info[index]);
		if (ret == 0) {
			npu_drv_err("register rdr exception is failed! index = %ld, ret = %d",
				index, ret);
			return -EINTR;
		}
	}
	return 0;
}

/*
 * Description : npu_rdr_unregister_exception
 * input : void
 * output : NA
 * rdr_unregister_exception : ret < 0 is fail. ret >= 0 success.
 */
static int npu_rdr_unregister_exception(void)
{
	int ret;
	size_t size;
	unsigned long index;

	size = sizeof(npu_rdr_excetption_info) /
		sizeof(npu_rdr_excetption_info[0]);
	for (index = 0; index < size; index++) {
		/* ret < 0 is fail, ret >= 0 is success */
		ret = rdr_unregister_exception(
			npu_rdr_excetption_info[index].e_modid);
		if (ret < 0) {
			npu_drv_err("unregister rdr exception is failed! index = %ld, ret = %d",
				index, ret);
			return -EINTR;
		}
	}
	return 0;
}

/*
 * Description: npu_mntn_rdr_dump
 * input: modid: module id
 *        etype:exception type
 *        coreid: core id
 *        pathname: log path
 *        pfn_cb: callback function
 * output: NA
 * return: NA
 */
static void npu_mntn_rdr_dump(u32 modid, u32 etype, u64 coreid,
	char *pathname, pfn_cb_dump_done pfn_cb)
{
	npu_drv_warn("modid=0x%x, etype=0x%x, coreid=0x%llx",
		modid, etype, coreid);
	if (pathname == NULL) {
		npu_drv_err("pathname is empty!");
		return;
	}
	g_npu_mntn_private->core_id = (unsigned int)coreid;
	g_npu_mntn_private->mntn_info.dump_info.modid = modid;
	g_npu_mntn_private->mntn_info.dump_info.coreid = coreid;
	g_npu_mntn_private->mntn_info.dump_info.pathname = pathname;
	g_npu_mntn_private->mntn_info.dump_info.cb = pfn_cb;
	npu_mntn_dump();
}

/*
 * Description: npu_mntn_rdr_reset
 * input: modid:module id
 *        etype:exception type
 *        coreid:core id
 * output: NA
 * return: NA
 */
static void npu_mntn_rdr_reset(u32 modid, u32 etype, u64 coreid)
{
	npu_drv_warn("modid=0x%x, etype=0x%x, coreid=0x%llx",
		modid, etype, coreid);
	if ((modid >= RDR_EXC_TYPE_NOC_NPU0) && (modid <= RDR_EXC_TYPE_NOC_NPU7))
		queue_work(g_npu_mntn_private->rdr_wq,
			&g_npu_mntn_private->reset_work);
}

/*
 * Description : npu_rdr_register_core
 * input : void
 * output : NA
 * rdr_register_module_ops : ret <0 is fail. ret >= 0 is success.
 */
int npu_rdr_register_core(void)
{
	int ret;
	struct rdr_module_ops_pub s_soc_ops;

	ret = memset_s(&g_npu_task_dump_manager, sizeof(struct npu_task_dump_info_manager),
		0x0, sizeof(struct npu_task_dump_info_manager));
	cond_return_error(ret != 0, -EINVAL,  "memset_s failed. ret=%d\n", ret);

	s_soc_ops.ops_dump = npu_mntn_rdr_dump;
	s_soc_ops.ops_reset = npu_mntn_rdr_reset;
	/* register npu core dump and reset function */
	ret = rdr_register_module_ops((u64)RDR_NPU, &s_soc_ops,
		&g_npu_mntn_private->mntn_info.npu_ret_info);
	if (ret < 0)
		npu_drv_err("register rdr module_ops is failed! ret = 0x%08x", ret);

	return ret;
}

/*
 * Description : npu_rdr_unregister_core
 * input : void
 * output : NA
 * rdr_unregister_module_ops : ret < 0 is fail. ret >= 0 is success.
 */
static int npu_rdr_unregister_core(void)
{
	int ret;

	/* unregister npu core dump and reset function */
	ret = rdr_unregister_module_ops((u64)RDR_NPU);
	if (ret < 0)
		npu_drv_err("unregister rdr module_ops is failed! ret = 0x%08x", ret);

	return ret;
}

/*
 * Description : npu_rdr_addr_map
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
int npu_rdr_addr_map(void)
{
	int ret;
	if (g_npu_mntn_private == NULL) {
		npu_drv_err("invalid null pointer");
		return -EINVAL;
	}
	g_npu_mntn_private->mntn_info.rdr_addr =
		dfx_bbox_map((
		phys_addr_t)g_npu_mntn_private->mntn_info.npu_ret_info.log_addr,
		g_npu_mntn_private->mntn_info.npu_ret_info.log_len);
	if (g_npu_mntn_private->mntn_info.rdr_addr == NULL) {
		npu_drv_err("map dfx bbox is failed!");
		return -EFAULT;
	}
	ret = memset_s((char *)g_npu_mntn_private->mntn_info.rdr_addr,
		g_npu_mntn_private->mntn_info.npu_ret_info.log_len, 0,
		g_npu_mntn_private->mntn_info.npu_ret_info.log_len);
	cond_return_error(ret != 0, -EINVAL,  "memset_s failed. ret=%d\n", ret);

	return 0;
}

/*
 * Description : npu_rdr_addr_unmap
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
static int npu_rdr_addr_unmap(void)
{
	dfx_bbox_unmap(g_npu_mntn_private->mntn_info.rdr_addr);
	g_npu_mntn_private->mntn_info.rdr_addr = NULL;
	return 0;
}

/*
 * Description : npu_blackbox_addr_init
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
static int npu_blackbox_addr_init(void)
{
	struct npu_platform_info *plat_info = NULL;
	struct npu_dfx_desc *dfx_desc = NULL;
	int ret;

	plat_info = npu_plat_get_info();
	if (plat_info == NULL) {
		npu_drv_err("get platform info error\n");
		return -1;
	}

	dfx_desc = &plat_info->resmem_info.dfx_desc[NPU_DFX_DEV_BLACKBOX];
	if (dfx_desc == NULL) {
		npu_drv_err("get dtsi failed\n");
		return -1;
	}

	g_bbox_addr_vir = (unsigned long long)(uintptr_t)ioremap_wc(
		dfx_desc->bufs->base, BBOX_ADDR_LEN);
	if (g_bbox_addr_vir == 0) {
		npu_drv_err("ioremap_wc failed\n");
		return -1;
	}

	ret = memset_s((void *)(uintptr_t)g_bbox_addr_vir, BBOX_ADDR_LEN, 0, BBOX_ADDR_LEN);
	if (ret != 0) {
		npu_drv_err("memset_s failed. ret=%d\n", ret);
		iounmap((void *)((uintptr_t)g_bbox_addr_vir));
		g_bbox_addr_vir = 0;
		return -1;
	}

	return 0;
}

int npu_blackbox_addr_release(void)
{
	if (g_bbox_addr_vir != 0) {
		iounmap((void *)((uintptr_t)g_bbox_addr_vir));
		g_bbox_addr_vir = 0;
	}

	return 0;
}

static struct rdr_exception_info g_rdr_exception_info[] = {
		/* OS exception code 0xc0000000-0xc00000ff */
		{EXC_TYPE_OS_DATA_ABORT, 1, 0},
		{EXC_TYPE_OS_INSTRUCTION_ABORT, 1, 0},
		{EXC_TYPE_OS_PC_ALIGN_FAULT, 1, 0},
		{EXC_TYPE_OS_SP_ALIGN_FAULT, 1, 0},
		{EXC_TYPE_OS_INFINITE_LOOP, 1, 0},
		{EXC_TYPE_OS_UNKNOWN_EXCEPTION, 1, 0},
		{RDR_EXC_TYPE_OS_EXCEPTION, 1, 0},
		/* AICORE exception code 0xc0000200-0xc000023f */
		{EXC_TYPE_TS_AICORE_EXCEPTION, 1, 0},
		{EXC_TYPE_TS_AICORE_TIMEOUT, 1, 0},
		/* EFF AICORE exception code 0xc0000240-0xc000027f */
		{EXC_TYPE_TS_AICORE_EFF_EXCEPTION, 1, 0},
		{EXC_TYPE_TS_AICORE_EFF_TIMEOUT, 1, 0},	
		/* AIV exception code 0xc0000280-0xc00002ff */
		{EXC_TYPE_TS_AIV_EXCEPTION, 1, 0},
		{EXC_TYPE_TS_AIV_TIMEOUT, 1, 0},
		/* SDMA exception code 0xc0000300-0xc00003ff */
		{EXC_TYPE_TS_SDMA_EXCEPTION, 1, 0},
		{EXC_TYPE_TS_SDMA_TIMEOUT, 1, 0},
		/* TS exception code 0xc0000400-0xc00004ff */
		{RDR_EXC_TYPE_TS_RUNNING_EXCEPTION, 1, 0},
		{RDR_EXC_TYPE_TS_RUNNING_TIMEOUT, 1, 0},
		{RDR_EXC_TYPE_TS_INIT_EXCEPTION, 1, 0},
		/* driver exception code 0xc0000600-0xc00006ff, only for driver */
		{RDR_EXC_TYPE_NPU_POWERUP_FAIL, 1, 0},
		{RDR_EXC_TYPE_NPU_POWERDOWN_FAIL, 1, 0},
		{RDR_EXC_TYPE_NPU_SMMU_EXCEPTION, 1, 0},
		/* NPU NOC exception code 0xc0000700-0xc00007ff */
		{RDR_EXC_TYPE_NOC_NPU0, 1, 0},
		{RDR_EXC_TYPE_NOC_NPU1, 1, 0},
		{RDR_EXC_TYPE_NOC_NPU5, 1, 0},
		{RDR_EXC_TYPE_NOC_NPU7, 1, 0},
		{RDR_EXC_TYPE_NOC_NORESET_NPU0, 1, 0},
		{RDR_EXC_TYPE_NOC_NORESET_NPU1, 1, 0},
		{RDR_EXC_TYPE_NOC_NORESET_NPU2, 1, 0},
		/* HWTS exception code 0xc0000800-0xc00008ff */
		{RDR_TYPE_HWTS_BUS_ERROR, 1, 0},
		{RDR_TYPE_HWTS_EXCEPTION_ERROR, 1, 0}
};

void npu_rdr_exception_reset(void)
{
	u32 i = 0;

	for (; i < ARRAY_SIZE(g_rdr_exception_info); i++)
		g_rdr_exception_info[i].count = 0;
}

/*
 * Description : npu_rdr_exception_is_count_exceeding
 * input : u32
 * output : NA
 * return : u32: 0 means not exceeding limitation and allowed to report,
 *          otherwise not allowed.
 */
static u32 npu_rdr_exception_is_count_exceeding(u32 error_code)
{
	u32 i;

	for (i = 0; i < ARRAY_SIZE(g_rdr_exception_info); i++)
		if (g_rdr_exception_info[i].error_code == error_code) {
			if (g_rdr_exception_info[i].count >=
				g_rdr_exception_info[i].limitation) {
				npu_drv_warn("error code %u exceeds the limitation %u",
					error_code, g_rdr_exception_info[i].limitation);
				return 1;
			}
			g_rdr_exception_info[i].count++;
			npu_drv_debug("error code %u occurs %u time(s)",
				error_code, g_rdr_exception_info[i].count);
			return 0;
		}

	npu_drv_warn("error code %u is undefined", error_code);

	return 1;
}

#ifdef CONFIG_SELF_HEALING
#define NPU_SH_NUM           521
#define NPU_SH_LEN           1
#define FDUL_SH_NUM           522
#define FDUL_SH_LEN           1

int npu_sh_nve_read(unsigned char *data)
{
	struct opt_nve_info_user npu_sh_nv_read_info;
	int ret;

	if (data == NULL) {
		npu_drv_err("invalid data\n");
		return -1;
	}

	(void)memset_s(&npu_sh_nv_read_info, sizeof(npu_sh_nv_read_info), 0, sizeof(npu_sh_nv_read_info));

	ret = strncpy_s(npu_sh_nv_read_info.nv_name, sizeof("NPU_SH"), "NPU_SH", (sizeof("NPU_SH") - 1));
	if (ret != 0) {
		npu_drv_err("strncpy_s fail\n");
		return -1;
	}

	npu_sh_nv_read_info.nv_number = NPU_SH_NUM;
	npu_sh_nv_read_info.valid_size = NPU_SH_LEN;
	npu_sh_nv_read_info.nv_operation = NV_READ;

	ret = nve_direct_access_interface(&npu_sh_nv_read_info);
	if (ret == 0) {
		*data = npu_sh_nv_read_info.nv_data[0];
		npu_drv_warn("npu sh nv read 0x%x success!\n",
			    npu_sh_nv_read_info.nv_data[0]);
		return 0;
	}

	npu_drv_err("npu sh nv read faild!\n");

	return -1;
}

int fdul_sh_nve_read(unsigned char *data)
{
	struct opt_nve_info_user fdul_sh_nv_read_info;
	int ret;

	if (data == NULL) {
		npu_drv_err("invalid data\n");
		return -1;
	}

	(void)memset_s(&fdul_sh_nv_read_info, sizeof(fdul_sh_nv_read_info), 0, sizeof(fdul_sh_nv_read_info));

	ret = strncpy_s(fdul_sh_nv_read_info.nv_name, sizeof("FDUL_SH"), "FDUL_SH", (sizeof("FDUL_SH") - 1));
	if (ret != 0) {
		npu_drv_err("strncpy_s fail\n");
		return -1;
	}

	fdul_sh_nv_read_info.nv_number = FDUL_SH_NUM;
	fdul_sh_nv_read_info.valid_size = FDUL_SH_LEN;
	fdul_sh_nv_read_info.nv_operation = NV_READ;

	ret = nve_direct_access_interface(&fdul_sh_nv_read_info);
	if (ret == 0) {
		if (data != NULL)
			*data = fdul_sh_nv_read_info.nv_data[0];
		npu_drv_warn("fdul sh nv read 0x%x success!\n",
			    fdul_sh_nv_read_info.nv_data[0]);
		return 0;
	}

	npu_drv_err("fdul sh nv read faild!\n");

	return -1;
}

int npu_sh_nve_write(const unsigned char *data)
{
	int ret;
	struct opt_nve_info_user npu_sh_nv_write_info;

	if (data == NULL) {
		npu_drv_err("data is null\n");
		return -1;
	}

	(void)memset_s(&npu_sh_nv_write_info, sizeof(npu_sh_nv_write_info), 0, sizeof(npu_sh_nv_write_info));

	ret = strncpy_s(npu_sh_nv_write_info.nv_name, sizeof("NPU_SH"), "NPU_SH", (sizeof("NPU_SH") - 1));
	if (ret != 0) {
		npu_drv_err("strncpy_s fail\n");
		return -1;
	}

	npu_sh_nv_write_info.nv_number = NPU_SH_NUM;
	npu_sh_nv_write_info.valid_size = NPU_SH_LEN;
	npu_sh_nv_write_info.nv_operation = NV_WRITE;

	npu_sh_nv_write_info.nv_data[0] = *data;

	ret = nve_direct_access_interface(&npu_sh_nv_write_info);
	if (ret == 0) {
		npu_drv_err("test nv write 0x%x success!\n",
			    npu_sh_nv_write_info.nv_data[0]);
		return 0;
	}

	npu_drv_err("test nv write faild!\n");

	return 0;
}

static void npu_rdr_record_manager(uint32_t error_code)
{
	uint8_t i;
	time64_t stamp = ktime_get_boottime_seconds();
	char data = 0;
	static int npu_sh_flag = 0;

	mutex_lock(&g_npu_rdr_record_manager.lock);
	if (npu_sh_flag == 1) {
		mutex_unlock(&g_npu_rdr_record_manager.lock);
		npu_drv_warn("npu sh can not self healing\n");
		return;
	}
	// 1. record
	i = g_npu_rdr_record_manager.end;
	g_npu_rdr_record_manager.info[i].error_code = error_code;
	g_npu_rdr_record_manager.info[i].stamp = stamp;
	g_npu_rdr_record_manager.end = (i + 1) % NPU_RDR_RECORD_NUM;

	// 2. filt old record
	if (g_npu_rdr_record_manager.end == g_npu_rdr_record_manager.start) {
		while (g_npu_rdr_record_manager.start != i) {
			if ((stamp - g_npu_rdr_record_manager.info[g_npu_rdr_record_manager.start].stamp)
				< NPU_RDR_RECORD_TIME_MAX)
				break;
			g_npu_rdr_record_manager.start = (g_npu_rdr_record_manager.start + 1) % NPU_RDR_RECORD_NUM;
		}
	}

	// 3. if table full, check nv
	if (g_npu_rdr_record_manager.end == g_npu_rdr_record_manager.start) {
		// 3.1 read nv
		(void)npu_sh_nve_read(&data);
		if (data == 0) {
			// 3.2 write nv
			data = 0x1;
			npu_sh_nve_write(&data);
			// 3.3 dmd
			bbox_diaginfo_record(DMD_NPU_SH_PV_CNT, NULL, "npu sh pv: enable");
		} else {
			npu_sh_flag = 1;
			data = 0;
			npu_sh_nve_write(&data);
			bbox_diaginfo_record(DMD_NPU_SH_PV_CNT, NULL, "npu sh pv: cancel");
		}
	}
	mutex_unlock(&g_npu_rdr_record_manager.lock);
}
#endif

void npu_rdr_exception_report(uint32_t error_code)
{
#ifdef CONFIG_SELF_HEALING
	if (error_code == EXC_TYPE_TS_AICORE_EXCEPTION || error_code == EXC_TYPE_TS_AIV_EXCEPTION ||
		error_code == EXC_TYPE_TS_AICORE_TIMEOUT || error_code == EXC_TYPE_TS_AIV_TIMEOUT)
		npu_rdr_record_manager(error_code);
#endif
	if (npu_rdr_exception_is_count_exceeding(error_code) == 0) {
		npu_drv_err("call rdr_system_error, error_code: 0x%x\n", error_code);
		rdr_system_error(error_code, 0, 0);
		npu_counter_print();
	}
}
EXPORT_SYMBOL(npu_rdr_exception_report);

void npu_rdr_taskerr_exception_report(uint32_t error_code, struct hwts_exception_report_info *report)
{
	if (report != NULL && report->persist_stream_id != UINT16_MAX) {
		g_npu_task_dump_manager.flag[g_npu_task_dump_manager.wptr] = NPU_TASK_DUMP_INCOMPLETE;
		g_npu_task_dump_manager.info[g_npu_task_dump_manager.wptr].func_name[0] = 0;
		g_npu_task_dump_manager.info[g_npu_task_dump_manager.wptr].model_id = report->model_id;
		g_npu_task_dump_manager.info[g_npu_task_dump_manager.wptr].strm_id = report->persist_stream_id;
		g_npu_task_dump_manager.info[g_npu_task_dump_manager.wptr].task_id = report->persist_task_id;
		g_npu_task_dump_manager.wptr++;
		g_npu_task_dump_manager.wptr %= NPU_TASK_DUMP_NUM;
	}
	npu_rdr_exception_report(error_code);
}

int npu_bbox_record_err_task(struct npu_task_dump_info *error_task)
{
	uint8_t wptr = g_npu_task_dump_manager.wptr == 0 ? (NPU_TASK_DUMP_NUM - 1) : g_npu_task_dump_manager.wptr - 1;
	errno_t ret = 0;
	if (error_task != NULL) {
		while (wptr != g_npu_task_dump_manager.wptr) {
			if (g_npu_task_dump_manager.info[wptr].model_id == error_task->model_id &&
				g_npu_task_dump_manager.info[wptr].strm_id == error_task->strm_id &&
				g_npu_task_dump_manager.info[wptr].task_id == error_task->task_id) {
				ret = strncpy_s(g_npu_task_dump_manager.info[wptr].func_name, DUMP_NAME_MAX_LEN,
					error_task->func_name, DUMP_NAME_MAX_LEN);
				cond_return_error(ret != EOK, -1, "strncpy_s func_name error.\n");
				g_npu_task_dump_manager.info[wptr].complete_err = error_task->complete_err;
				g_npu_task_dump_manager.info[wptr].task_type = error_task->task_type;
				g_npu_task_dump_manager.info[wptr].block_dim = error_task->block_dim;
				g_npu_task_dump_manager.info[wptr].priority = error_task->priority;
				ret = strncpy_s(g_npu_task_dump_manager.info[wptr].process_name, DUMP_NAME_MAX_LEN,
					error_task->process_name, DUMP_NAME_MAX_LEN);
				cond_return_error(ret != EOK, -1, "strncpy_s process_name error.\n");
				g_npu_task_dump_manager.info[wptr].uid = error_task->uid;
				ret = strncpy_s(g_npu_task_dump_manager.info[wptr].model_name, DUMP_NAME_MAX_LEN,
					error_task->model_name, DUMP_NAME_MAX_LEN);
				cond_return_error(ret != EOK, -1, "strncpy_s model_name error.\n");
				ret = memcpy_s(&(g_npu_task_dump_manager.info[wptr].mem_region), sizeof(struct mem_region_info),
					&(error_task->mem_region), sizeof(struct mem_region_info));
				cond_return_error(ret != EOK, -1, "memcpy_s mem_region error.\n");
				g_npu_task_dump_manager.flag[wptr] = NPU_TASK_DUMP_COMPLETE;
				break;
			}
			wptr = (wptr == 0 ? (NPU_TASK_DUMP_NUM - 1) : wptr - 1);
		}
	}
	return 0;
}

/*
 * Description : npu_black_box_init
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
int npu_black_box_init(void)
{
	int ret;
#ifdef CONFIG_MM_SMMU_V3
	struct npu_platform_info *plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info is NULL\n");
#endif

	npu_drv_info("Enter\n");

	ret = npu_rdr_resource_init();
	cond_return_error(ret < 0, ret, "rdr resource init is faild ! ret = %d",
		ret);

	/* register NPU exception */
	ret = npu_rdr_register_exception();
	cond_goto_error(ret < 0, error, ret, ret,
		"register rdr exception is faild! ret = %d", ret);

	/* register NPU dump and reset function */
	ret = npu_rdr_register_core();
	if (ret < 0) {
		npu_drv_err("register rdr core is failed! ret = %d", ret);
		npu_rdr_unregister_exception();
		goto error;
	}

	ret = npu_rdr_addr_map();
	if (ret < 0) {
		npu_drv_err("map rdr addr is failed! ret = %d", ret);
		npu_rdr_unregister_core();
		npu_rdr_unregister_exception();
		goto error;
	}

	ret = npu_blackbox_addr_init();
	if (ret < 0) {
		npu_rdr_addr_unmap();
		npu_rdr_unregister_core();
		npu_rdr_unregister_exception();
		npu_drv_err("blackbox addr init is failed ! ret = %d", ret);
		goto error;
	}

#if defined(CONFIG_MM_SVM)
	ret = mm_smmu_evt_register_notify(&smmu_excp_notifier);
#elif defined(CONFIG_MM_SMMU_V3)
	ret = mm_smmu_evt_register_notify(plat_info->pdev, &smmu_excp_notifier);
#endif
	if (ret < 0) {
		npu_blackbox_addr_release();
		npu_rdr_addr_unmap();
		npu_rdr_unregister_core();
		npu_rdr_unregister_exception();
		npu_drv_err("mm evt register notify is failed ! ret = %d", ret);
		goto error;
	}

	return 0;

error:
	if (g_npu_mntn_private != NULL) {
		destroy_workqueue(g_npu_mntn_private->rdr_wq);
		kfree(g_npu_mntn_private);
		g_npu_mntn_private = NULL;
	}
	return ret;
}

/*
 * Description : npu_black_box_exit
 * input : void
 * output : NA
 * return : int:  0 is OK. other value is Error No.
 */
int npu_black_box_exit(void)
{
	int ret;

#if defined(CONFIG_MM_SMMU_V3)
	struct npu_platform_info *plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info is NULL\n");

	(void)mm_smmu_evt_unregister_notify(plat_info->pdev, &smmu_excp_notifier);
#elif defined(CONFIG_MM_SVM)
	(void)mm_smmu_evt_unregister_notify(&smmu_excp_notifier);
#endif

	npu_blackbox_addr_release();
	(void)npu_rdr_addr_unmap();

	ret = npu_rdr_unregister_core();
	if (ret < 0)
		npu_drv_err("unregister rdr core is faild! ret = %d", ret);

	ret = npu_rdr_unregister_exception();
	if (ret < 0)
		npu_drv_err("unregister rdr exception is faild! ret = %d", ret);

	npu_rdr_resource_destroy();

	return 0;
}

#if defined (CONFIG_NPU_NOC)
static int npu_noc_register(void)
{
	unsigned int i;

	if (array_size(npu_noc_para) != array_size(modid_array)) {
		npu_drv_err("array size not match, para size = %lu, modid size = %lu",
			array_size(npu_noc_para), array_size(modid_array));
		return -1;
	}

	for (i = 0; i < array_size(npu_noc_para); i++) {
		npu_drv_info("register noc err, type:%x", modid_array[i]);
		noc_modid_register(npu_noc_para[i], modid_array[i]);
	}
	return 0;
}
#elif defined (CONFIG_DFX_SEC_QIC_V100_MODID_REGISTER)
static int npu_qic_register(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(npu_qic_modid_array); i++) {
		npu_drv_info("register npu qic, qic_id:0x%x modid:0x%x", npu_qic_modid_array[i][0], npu_qic_modid_array[i][1]);
		dfx_qic_modid_register(npu_qic_modid_array[i][0], npu_qic_modid_array[i][1]);
	}
	return 0;
}
#elif defined (CONFIG_DFX_SEC_QIC_V300_MODID_REGISTER)
static int npu_qic_register(void)
{
	unsigned int i;
	struct npu_qic_register_info_s *qic_reg = NULL;

	for (i = 0; i < ARRAY_SIZE(npu_qic_modid_array); i++) {
		qic_reg = npu_qic_modid_array + i;
		npu_drv_info("register npu qic, mid_start:0x%x mid_end:0x%x modid:0x%x", \
			qic_reg->mid_start, qic_reg->mid_end, qic_reg->modid);
		dfx_qic_modid_register(qic_reg->mid_start, qic_reg->mid_end, qic_reg->qic_bus, qic_reg->modid);
	}
	return 0;
}
#endif


int npu_bus_errprobe_register(void)
{
#if defined (CONFIG_NPU_NOC)
	return npu_noc_register();
#elif defined (CONFIG_DFX_SEC_QIC_V100_MODID_REGISTER) || defined (CONFIG_DFX_SEC_QIC_V300_MODID_REGISTER)
	return npu_qic_register();
#else
	return 0;
#endif
}
