/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/bsearch.h>
#include <linux/rcupdate.h>
#include <securec.h>

#include "hvgr_dm_driver_adapt_defs.h"

#include "hvgr_defs.h"
#include "hvgr_regmap.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_sch_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_log_api.h"
#include "hvgr_dm_driver_base.h"
#include "hvgr_datan_api.h"

/*
 * The GPU and JOB fault names are defined as follows:
 */
static struct hvgr_dm_fault_msg gpu_fault_name_tbl[] = {
	{0x00, "OK"},
	{0x01, "DONE"},
	{0x03, "STOPPED"},
	{0x40, "FAULT_PWR"},
	{0x48, "FAULT_OOB"},
	{0x49, "FAULT_SKIP_CSHARP"},
	{0x4a, "FAULT_INDEX_CSHARP"},
	{0x4b, "FAULT_PKC_SIZE_ZERO"},
	{0x4c, "FAULT_TCM_ADDR_ERR"},
	{0x4d, "FAULT_TCM_ADDR_REQ_ERR"},
	{0x4e, "FAULT_DESC_ERR"},
	{0x4f, "FAULT_OUT_SIZE_ZERO"},
	{0x50, "FAULT_SW_CTX"},
	{0x51, "FAULT_HW_CTX"},
	{0x52, "FAULT_ENTRY"},
	{0x53, "FAULT_ENTRYLIST"},
	{0x54, "FAULT_INST"},
	{0x55, "FAULT_SPLIT"},
	{0x56, "FAULT_VCQ"},
	{0x57, "FAULT_CFG"},
	{0x58, "JOB_CONFIG_FAULT"},
	{0x59, "JOB_AFFINITY_FAULT"},
	{0x5a, "DATA_INVALID_FAULT"},
	{0x60, "OUT_OF_MEMORY"},
	{0x63, "FBD"},
	{0x69, "PGL_HEADER"},
	{0x6a, "PGL_CMD"},
	{0x7b, "FAULT_BARRIER"},
	{0x7c, "LSC_FAULT"},
	{0x7d, "HEBC_FAULT"},
	{0x7f, "UNKNOWN"},
	{0x80, "DELAYED_BUS_FAULT"},
	{0x90, "UMMAP"},
	{0xc1, "TRANSLATION_FAULT_1"},
	{0xc2, "TRANSLATION_FAULT_2"},
	{0xc3, "TRANSLATION_FAULT_3"},
	{0xc5, "BLOCK_AT_SL_FAULT_1"},
	{0xc9, "PERMISSION_FAULT_1"},
	{0xca, "PERMISSION_FAULT_2"},
	{0xcb, "PERMISSION_FAULT_3"},
	{0xd9, "ACCESS_FLAG_FAULT_1"},
	{0xda, "ACCESS_FLAG_FAULT_2"},
	{0xdb, "ACCESS_FLAG_FAULT_3"},
	{0xe9, "MEMATTR_INDEX_FAULT_1"},
	{0xea, "MEMATTR_INDEX_FAULT_2"},
	{0xeb, "MEMATTR_INDEX_FAULT_3"},
};

static const uint32_t fault_no_need_reset_gpu[] = {
	0x0, /* NOT_STARTED/IDLE/OK */
	0x1, /* DONE */
	0x3, /* STOPPED */
	0x7c, /* LSC_FAULT */
	0x7d, /* HEBC_FAULT */
};

bool hvgr_gpu_reset_needed_by_fault(uint32_t fault_code)
{
	uint32_t i;
	size_t arry_size = ARRAY_SIZE(fault_no_need_reset_gpu);

	for (i = 0; i < arry_size; i++) {
		if (fault_code == fault_no_need_reset_gpu[i])
			return false;
	}
	return true;
}

int hvgr_msg_fault_cmp(const void *key, const void *elt)
{
	uint32_t target = *(uint32_t *)key;
	struct hvgr_dm_fault_msg *msg_elt = (struct hvgr_dm_fault_msg *)elt;

	if (target == msg_elt->fault_code)
		return 0;
	if (target > msg_elt->fault_code)
		return 1;

	return -1;
}

const char *hvgr_exception_name(uint32_t exception_code)
{
	struct hvgr_dm_fault_msg *msg = NULL;

	msg = bsearch(&exception_code, gpu_fault_name_tbl, ARRAY_SIZE(gpu_fault_name_tbl),
		sizeof(struct hvgr_dm_fault_msg),
		hvgr_msg_fault_cmp);
	if (msg == NULL)
		return "UNKNOWN";

	return msg->fault_name;
}

void hvgr_gpu_fault_proc(struct hvgr_device *gdev, uint32_t val)
{
	uint32_t status;
	uint32_t fault_status;
	uint32_t fault_code;
	uint32_t type;
	uint64_t address;
	uint64_t value;
	bool is_reset_gpu = false;
	uint32_t m = val & GPU_FAULT;
	static const char * const gpu_fault_type_tbl[] = { "JOB", "CQ", "FCP",
		"FCP_CTRL", "MISC_CTRL" };
	uint32_t chn;
	uint32_t entryid;
	int ret;
	char process_msg[MAX_DMD_LOG_LENTH] = {0};
	char dmd_msg[MAX_DMD_LOG_LENTH] = {0};

	while (m) {
		type = (uint32_t)ffs((int)m) - 1;
		uint32_t offset = type * GPU_FAULT_REG_STRIDE;

		status = hvgr_read_reg(gdev,
			gpu_control_reg(gdev, GPU_FAULTSTATUS + offset));
		address = (uint64_t)hvgr_read_reg(gdev,
			gpu_control_reg(gdev, GPU_FAULTDATA1 + offset));
		address <<= 32;
		address |= hvgr_read_reg(gdev,
			gpu_control_reg(gdev, GPU_FAULTDATA0 + offset));

		value = (uint64_t)hvgr_read_reg(gdev,
			gpu_control_reg(gdev, GPU_FAULTDATA3 + offset));
		value <<= 32;
		value |= hvgr_read_reg(gdev,
			gpu_control_reg(gdev, GPU_FAULTDATA2 + offset));

		chn = (value & 0xf);
		entryid = (value & 0xffff0) >> 4;

		fault_status = (status & 0xFF);
		fault_code = (status & 0xFF00) >> 8;

		if (type == 1) {
			hvgr_err(gdev, HVGR_DM,
				"%s Fault 0x%08x (%s) at 0x%016llx, value 0x%016llx,"
				"fault_code 0x%08x  chn %d  entryid %d",
				gpu_fault_type_tbl[type], fault_status,
				hvgr_exception_name(fault_status),
				address, value,  fault_code, chn,  entryid);
		} else {
			hvgr_err(gdev, HVGR_DM,
				"%s Fault 0x%08x (%s) at 0x%016llx, value 0x%016llx",
				gpu_fault_type_tbl[type], fault_status,
				hvgr_exception_name(fault_status),
				address, value);
		}

		if (hvgr_gpu_reset_needed_by_fault(status))
			is_reset_gpu = true;

		m &= ~(1 << ((uint32_t)ffs(m) - 1));
	}

	hvgr_gpu_fault_show_process(gdev, process_msg, MAX_DMD_LOG_LENTH);
	if (is_reset_gpu) {
		ret = snprintf_s(dmd_msg, MAX_DMD_LOG_LENTH, MAX_DMD_LOG_LENTH - 1,
			"higpu gpu fault,fault:%u 0x%x,data:%u,task:%s",
			type, status, chn, process_msg);
		if (ret > 0)
			hvgr_datan_gpu_fault_type_set(gdev, DMD_JOB_FAIL, dmd_msg);
		else
			hvgr_datan_gpu_fault_type_set(gdev, DMD_JOB_FAIL, "higpu gpu fault");

		hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_IMMEDIATELY);
	}
}
