/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
 * Description: syscache api
 * Create: 2021-07-06
 */
#include "npu_syscache.h"

#include <linux/dma-buf.h>
#include <linux/mm_lb/mm_lb.h>

#include "npu_common.h"
#include "npu_log.h"
#include "npd_interface.h"

enum npu_syscache_state {
	NPU_SYSCACHE_DISABLE = 0,
	NPU_SYSCACHE_ENABLE,
	NPU_SYSCACHE_ENABLE_AND_HIGH_PRIORITY,
};

static u8 g_syscache_state = NPU_SYSCACHE_DISABLE;

int npu_ioctl_attach_syscache(struct npu_proc_ctx *proc_ctx,
	unsigned long arg)
{
	int ret = 0;
	struct npu_attach_sc msg = {0};
	unused(proc_ctx);

	ret = copy_from_user_safe(&msg, (void __user *)(uintptr_t)arg, sizeof(msg));
	cond_return_error(ret != 0, -EINVAL,
		"fail to copy npu sc attach params, ret = %d\n", ret);

	cond_return_error(msg.size > get_sc_size(), -EINVAL,
		"msg size invalid, msg.size = %d\n", msg.size);

	if (!g_npd->npd_query_sku_value(NPU_SKU_VAR_SUPPORT_SC)) {
		npu_drv_debug("do not support sc\n");
		return 0;
	}

	/* syscahce attach interface with offset */
	npu_drv_info("fd = 0x%x, offset = 0x%lx, size = 0x%lx\n",
		msg.fd, msg.offset, msg.size);
#ifdef CONFIG_MM_LB
	ret = dma_buf_attach_lb(msg.fd, PID_NPU, msg.offset, (size_t)msg.size);
	cond_return_error(ret != 0, -EINVAL,
		"dma buf attach lb fail, ret = %d\n", ret);
#endif

	return 0;
}

void npu_sc_timeout(struct timer_list *syscache_timer)
{
#ifdef CONFIG_MM_LB
	int ret = lb_gid_bypass(PID_NPU);
	g_syscache_state = NPU_SYSCACHE_DISABLE;
	if (ret != 0)
		npu_drv_warn("npu_sc_timeout %d\n", ret);
#endif
	unused(syscache_timer);
}

void npu_sc_enable_and_high(struct npu_dev_ctx *dev_ctx)
{
	int ret = 0;

	if (!g_npd->npd_query_sku_value(NPU_SKU_VAR_SUPPORT_SC)) {
		npu_drv_debug("do not support sc\n");
		return;
	}
#ifdef CONFIG_MM_LB
	mutex_lock(&dev_ctx->syscache_mutex);
	del_timer_sync(&dev_ctx->syscache_timer);
	if (g_syscache_state == NPU_SYSCACHE_ENABLE_AND_HIGH_PRIORITY) {
		goto sc_enable_finish;
	} else if (g_syscache_state == NPU_SYSCACHE_ENABLE) {
		goto sc_priority_up;
	}

	npu_drv_debug("npu_sc_enable_and_high\n");
	ret = lb_gid_enable(PID_NPU);
	cond_goto_error(ret != 0, sc_enable_err, ret,
		ret, "lb gid enable fail, ret = %d\n", ret);
	g_syscache_state = NPU_SYSCACHE_ENABLE;
sc_priority_up:
	ret = lb_up_policy_prio(PID_NPU);
	cond_goto_error(ret != 0, sc_up_policy_err, ret,
		ret, "lb up policy prio fail, ret = %d\n", ret);
	g_syscache_state = NPU_SYSCACHE_ENABLE_AND_HIGH_PRIORITY;
	goto sc_enable_finish;

sc_up_policy_err:
	lb_gid_bypass(PID_NPU);
	g_syscache_state--;
sc_enable_err:
sc_enable_finish:
	mutex_unlock(&dev_ctx->syscache_mutex);
#endif
}

void npu_sc_low(struct npu_dev_ctx *dev_ctx)
{
	int ret = 0;

	if (!g_npd->npd_query_sku_value(NPU_SKU_VAR_SUPPORT_SC)) {
		npu_drv_debug("do not support sc\n");
		return;
	}

#ifdef CONFIG_MM_LB
	mutex_lock(&dev_ctx->syscache_mutex);
	if (g_syscache_state != NPU_SYSCACHE_ENABLE_AND_HIGH_PRIORITY) {
		mutex_unlock(&dev_ctx->syscache_mutex);
		return;
	}

	npu_drv_debug("npu_sc_low\n");
	/*  */
	ret = lb_down_policy_prio(PID_NPU);
	g_syscache_state--;
	if (ret != 0)
		npu_drv_warn("lb down policy prio fail, ret = %d\n", ret);
	mutex_unlock(&dev_ctx->syscache_mutex);
#endif
}

void npu_sc_disable(struct npu_dev_ctx *dev_ctx)
{
	int ret = 0;

	if (!g_npd->npd_query_sku_value(NPU_SKU_VAR_SUPPORT_SC)) {
		npu_drv_debug("do not support sc\n");
		return;
	}

#ifdef CONFIG_MM_LB
	mutex_lock(&dev_ctx->syscache_mutex);
	npu_drv_debug("npu_sc_low\n");
	del_timer_sync(&dev_ctx->syscache_timer);
	ret = lb_down_policy_prio(PID_NPU);
	if (ret != 0)
		npu_drv_warn("lb down policy prio fail, ret = %d\n", ret);

	ret = lb_gid_bypass(PID_NPU);
	g_syscache_state = NPU_SYSCACHE_DISABLE;
	if (ret != 0)
		npu_drv_warn("lb gid bypass fail, ret = %d\n", ret);

	npu_drv_debug("npu_sc_disable\n");
	mutex_unlock(&dev_ctx->syscache_mutex);
#endif
}

