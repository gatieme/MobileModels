/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "tz_pm.h"
#include <securec.h>
#include <linux/types.h>
#include <linux/vmalloc.h>
#include <linux/dma-mapping.h>
#include <asm/cacheflush.h>
#include <smc_smp.h>
#include "tc_ns_client.h"
#include "teek_ns_client.h"
#include "tc_ns_log.h"
#include "smc_call.h"
#include <linux/arm-smccc.h>
#ifdef CONFIG_TZ_S4_OPTIMIZE
#include <linux/cpufreq.h>
#include <linux/cpumask.h>
#include <linux/pm.h>
#include <linux/delay.h>
#endif

#define S4_ADDR_4G              0xffffffff
#ifdef CONFIG_AP_CUST_PAD_MEM
#include <global_ddr_map.h>
#else
#define RESERVED_SECOS_PHYMEM_BASE                  0x22800000
#define RESERVED_SECOS_PHYMEM_SIZE                  (0x3000000)
#define RESERVED_S4_NS_BASE                         0x27760000
#endif
#define RESERVED_SECOS_S4_NS_SIZE                   (0x100000)

#ifdef CONFIG_CMD_BUFFER_RESTORE
static struct tc_ns_smc_queue *g_cmd_data_bk;
#endif
static char *g_s4_kernel_mem_addr;
static char *g_s4_buffer_vaddr;
static uint64_t g_s4_buffer_paddr;
static uint32_t g_s4_buffer_size;

struct s4_mem_info g_s4_mem_info[S4_MEM_NUM] = {
	/* Add exmem for static ION */
#ifdef CONFIG_AP_CUST_PAD_MEM
	{ RESERVED_SUPERSONIC_EX_PHYMEM_BASE, RESERVED_SECOS_EX_PHYMEM_SIZE + RESERVED_SUPERSONIC_EX_PHYMEM_SIZE},
#endif
	{ RESERVED_SECOS_PHYMEM_BASE, RESERVED_SECOS_PHYMEM_SIZE}
};

#ifdef CONFIG_AP_CUST_PAD_MEM
#define S4_THAW_ENABLE 1
#define S4_THAW_DISABLE 0
__visible uint32_t g_s4_thaw_config __nosavedata;

static void set_s4_thaw_config(uint32_t thaw_config)
{
	g_s4_thaw_config = thaw_config;
}

static uint32_t get_s4_thaw_config(void)
{
	return g_s4_thaw_config;
}
#endif

static void *tc_vmap(phys_addr_t paddr, size_t size)
{
	uint32_t i;
	void *vaddr = NULL;
	pgprot_t pgprot = PAGE_KERNEL;
	uintptr_t offset;
	uint32_t pages_count;
	struct page **pages = NULL;

	offset = paddr & ~PAGE_MASK;
	paddr &= PAGE_MASK;
	pages_count = (uint32_t)(PAGE_ALIGN(size + offset) / PAGE_SIZE);

	pages = kzalloc(sizeof(struct page *) * pages_count, GFP_KERNEL);
	if (pages == NULL)
		return NULL;

	for (i = 0; i < pages_count; i++)
		*(pages + i) = phys_to_page((uintptr_t)(paddr + PAGE_SIZE * i));

	vaddr = vmap(pages, pages_count, VM_MAP, pgprot);
	kfree(pages);
	if (vaddr == NULL)
		return NULL;

	return offset + (char *)vaddr;
}

static int tc_s4_alloc_crypto_buffer(struct device *dev,
	 char **kernel_mem_addr)
{
	(void)dev;
	if (RESERVED_S4_NS_BASE > S4_ADDR_4G) {
		tloge("addr is invalid\n");
		return -EFAULT;
	}

	g_s4_buffer_vaddr = tc_vmap(RESERVED_S4_NS_BASE, RESERVED_SECOS_S4_NS_SIZE);
	if (g_s4_buffer_vaddr == NULL) {
		tloge("vmap failed for s4\n");
		return -EFAULT;
	}
	g_s4_buffer_paddr = RESERVED_S4_NS_BASE;
	g_s4_buffer_size = RESERVED_SECOS_S4_NS_SIZE;

#ifdef CONFIG_AP_CUST_PAD_MEM
	/* Add exmem for static ION */
	*kernel_mem_addr = vmalloc(RESERVED_SECOS_PHYMEM_SIZE + RESERVED_SECOS_EX_PHYMEM_SIZE + RESERVED_SUPERSONIC_PHYMEM_SIZE);
#else
	*kernel_mem_addr = vmalloc(RESERVED_SECOS_PHYMEM_SIZE);
#endif
	if (*kernel_mem_addr == NULL) {
		vunmap(g_s4_buffer_vaddr);
		g_s4_buffer_paddr = 0;
		g_s4_buffer_vaddr = NULL;
		g_s4_buffer_size = 0;
		tloge("vmalloc failed for s4\n");
		return -ENOMEM;
	}

	return 0;
}

static void free_resource(const char *kernel_mem_addr)
{
#ifdef CONFIG_CMD_BUFFER_RESTORE
	if (g_cmd_data_bk != NULL) {
		vfree(g_cmd_data_bk);
		g_cmd_data_bk = NULL;
	}
#endif
	vunmap(g_s4_buffer_vaddr);
	vfree(kernel_mem_addr);
	g_s4_kernel_mem_addr = NULL;
	g_s4_buffer_paddr = 0;
	g_s4_buffer_vaddr = NULL;
	g_s4_buffer_size = 0;
}

static uint64_t tc_s4_suspend_or_resume(uint32_t power_op)
{
	u64 smc_id = (u64)power_op;
	u64 smc_ret = 0xffff;
	struct smc_in_params in_param = { smc_id };
	struct smc_out_params out_param = { smc_ret };

	smc_req(&in_param, &out_param, 0);
#ifdef CONFIG_FFA_SUPPORT
	smc_ret = out_param.exit_reason;
#else
	smc_ret = out_param.ret;
#endif
	return smc_ret;
}

#ifdef CONFIG_TZ_S4_SMC
void tz_s4_do_smc_transport(struct smc_in_params *in, struct smc_out_params *out, uint8_t wait)
{
	isb();
	wmb();
	do {
		asm volatile(
			"mov x0, %[fid]\n"
			"mov x1, %[a1]\n"
			"mov x2, %[a2]\n"
			"mov x3, %[a3]\n"
			"mov x4, %[a4]\n"
			"mov x5, %[a5]\n"
			"mov x6, %[a6]\n"
			"mov x7, %[a7]\n"
			SMCCC_SMC_INST"\n"
			"str x0, [%[re0]]\n"
			"str x1, [%[re1]]\n"
			"str x2, [%[re2]]\n"
			"str x3, [%[re3]]\n" :
			[fid] "+r"(in->x0),
			[a1] "+r"(in->x1),
			[a2] "+r"(in->x2),
			[a3] "+r"(in->x3),
			[a4] "+r"(in->x4),
			[a5] "+r"(in->x5),
			[a6] "+r"(in->x6),
			[a7] "+r"(in->x7):
			[re0] "r"(&out->ret),
			[re1] "r"(&out->exit_reason),
			[re2] "r"(&out->ta),
			[re3] "r"(&out->target) :
			"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7");
	} while (out->ret == TSP_REQUEST && wait != 0);
	isb();
	wmb();
}
 
void tz_s4_smc_req(struct smc_in_params *in, struct smc_out_params *out, uint8_t wait)
{
	tz_s4_do_smc_transport(in, out, wait);
}
#endif

static uint64_t tc_s4_crypto_and_copy(uint32_t crypt_op,
	uint64_t middle_mem_addr,
	uintptr_t secos_mem,
	uint32_t size, uint32_t index)
{
	u64 smc_id = (u64)crypt_op;
	u64 arg0 = (u64)middle_mem_addr;
	u64 arg1 = (u64)secos_mem;
	u64 arg2 = (u64)size;
	u64 arg3 = (u64)index;
	u64 smc_ret = 0xffff;
	struct smc_in_params in_param = { smc_id, arg0, arg1, arg2, arg3 };
	struct smc_out_params out_param = {smc_ret};

#ifdef CONFIG_TZ_S4_SMC
	tz_s4_smc_req(&in_param, &out_param, 0);
#else
	smc_req(&in_param, &out_param, 0);
#endif
	smc_ret = out_param.ret;

	return smc_ret;
}

static int tc_s4_transfer_data(char *kernel_mem_addr, uint32_t crypt_op)
{
	uint32_t index = 0;
	uint32_t copied_size = 0;
	int i;

	for (i = 0; i < S4_MEM_NUM; i++) {
		if (g_s4_mem_info[i].start_addr == 0 || g_s4_mem_info[i].mem_size == 0)
			continue;

		while (copied_size < g_s4_mem_info[i].mem_size) {
			if (crypt_op == TSP_S4_DECRYPT_AND_COPY) {
				__inval_dcache_area(kernel_mem_addr + copied_size, g_s4_buffer_size);
				if (memcpy_s(g_s4_buffer_vaddr, g_s4_buffer_size,
					kernel_mem_addr + copied_size,
					g_s4_buffer_size) != EOK) {
					tloge("mem copy for decrypt failed\n");
					return -EFAULT;
				}
				__flush_dcache_area(g_s4_buffer_vaddr, g_s4_buffer_size);
			}

			if (tc_s4_crypto_and_copy(crypt_op, g_s4_buffer_paddr,
				g_s4_mem_info[i].start_addr + copied_size,
				g_s4_buffer_size, index) != 0) {
				tloge("crypto and copy failed\n");
				return -EFAULT;
			}

			if (crypt_op == TSP_S4_ENCRYPT_AND_COPY) {
				__inval_dcache_area(g_s4_buffer_vaddr, g_s4_buffer_size);
				if (memcpy_s(kernel_mem_addr + copied_size,
					g_s4_buffer_size, g_s4_buffer_vaddr,
					g_s4_buffer_size) != EOK) {
					tloge("mem copy for encrypt failed\n");
					return -EFAULT;
				}
				__flush_dcache_area(kernel_mem_addr + copied_size, g_s4_buffer_size);
			}

			copied_size += g_s4_buffer_size;
			index++;
		}
		kernel_mem_addr += g_s4_mem_info[i].mem_size;
		copied_size = 0;
	}

	return 0;
}

static int tc_s4_pm_ops(struct device *dev, uint32_t power_op,
			uint32_t crypt_op, char *kernel_mem_addr)
{
	int ret;
	(void)dev;

	if (power_op == TSP_S4_SUSPEND)
		g_s4_kernel_mem_addr = kernel_mem_addr;
	else
		kernel_mem_addr = g_s4_kernel_mem_addr;

	/* notify TEEOS to suspend all pm driver */
	if (power_op == TSP_S4_SUSPEND) {
		ret = (int)tc_s4_suspend_or_resume(power_op);
		if (ret != 0) {
			tloge("tc s4 suspend failed\n");
			return ret;
		}
#ifdef CONFIG_AP_CUST_PAD_MEM
		set_s4_thaw_config(S4_THAW_ENABLE);
#endif
	}

	ret = tc_s4_transfer_data(kernel_mem_addr, crypt_op);
	if (ret != 0) {
		tloge("transfer data failed, power_op=0x%x\n", power_op);
		return ret;
	}

	/* notify TEEOS to resume all pm driver */
	if (power_op == TSP_S4_RESUME) {
		ret = (int)tc_s4_suspend_or_resume(power_op);
		if (ret != 0) {
			tloge("tc s4 resume failed\n");
			return ret;
		}
#ifdef CONFIG_AP_CUST_PAD_MEM
		set_s4_thaw_config(S4_THAW_DISABLE);
#endif
	}

	return 0;
}

#ifdef CONFIG_CMD_BUFFER_RESTORE
static int tc_s4_save_cmd_buf(void)
{
	int ret = 0;
	bool is_reserved_cmd_buffer = get_reserved_cmd_buffer();
	if (!is_reserved_cmd_buffer)
		return 0;

	struct tc_ns_smc_queue *cmd_data = get_cmd_data();
	if (cmd_data == NULL) {
		tloge("get cmd data error\n");
		return -1;
	}

	g_cmd_data_bk = vmalloc(sizeof(struct tc_ns_smc_queue));
	if (g_cmd_data_bk == NULL) {
		tloge("vmalloc failed for s4\n");
		return -ENOMEM;
	}

	ret = memcpy_s(g_cmd_data_bk, sizeof(struct tc_ns_smc_queue),
		cmd_data, sizeof(struct tc_ns_smc_queue));
	if (ret != EOK) {
		vfree(g_cmd_data_bk);
		g_cmd_data_bk = NULL;
		tloge("memcpy failed: 0x%x\n", ret);
		return ret;
	}

	return ret;
}

static int tc_s4_restore_cmd_buf(void)
{
	bool is_reserved_cmd_buffer = get_reserved_cmd_buffer();
	if (!is_reserved_cmd_buffer)
		return 0;

	if (g_cmd_data_bk == NULL) {
		tloge("backup cmd buffer error\n");
		return -1;
	}

	struct tc_ns_smc_queue *cmd_data = get_cmd_data();
	if (cmd_data == NULL) {
		tloge("get cmd data error\n");
		return -1;
	}

	int ret = memcpy_s(cmd_data, sizeof(struct tc_ns_smc_queue),
		g_cmd_data_bk, sizeof(struct tc_ns_smc_queue));
	if (ret != EOK) {
		tloge("memcpy failed: 0x%x\n", ret);
		return ret;
	}

	return 0;
}
#endif

#ifdef CONFIG_TZ_S4_OPTIMIZE
static void tc_s4_setaffinity(int cpu)
{
	long retval;
	struct cpumask cpu_mask;

	/* The delay 10ms is to prevent the high probability of core binding failures 
	caused by core binding immediately after the CPU goes online. */
	msleep(10);

	cpumask_clear(&cpu_mask);
	cpumask_set_cpu(cpu, &cpu_mask);
	cpumask_set_cpu(cpu - 1, &cpu_mask);
 
	retval = sched_setaffinity(0, &cpu_mask);
	if (retval)
		tlogi("sched_setaffinity to bigcore %d failed, ret %ld\n", cpu, retval);
	else
		tlogi("sched_setaffinity to bigcore %d\n", cpu);
}

static void tc_s4_setcpufreq_max(int cpu)
{
	int ret;
	struct cpufreq_policy *policy = NULL;
	policy = cpufreq_cpu_get(cpu);
	if (!policy) {
		tloge("no policy for cpu%d\n", cpu);
		return;
	}

	ret = cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
	if (ret < 0)
		tloge("set cpufreq fail, ret = %d\n", ret);
	else
		tlogi("cpu%d set cpufreq %u\n", cpu, policy->max);

	cpufreq_cpu_put(policy);
}

static void tc_s4_set_cpu_high_performance(void)
{
	int bigcore = num_online_cpus() - 1;
	tc_s4_setaffinity(bigcore);
	tc_s4_setcpufreq_max(bigcore);
	tc_s4_setcpufreq_max(bigcore - 1);
	return;
}
#endif

#ifdef CONFIG_AP_CUST_PAD_MEM
int tc_s4_pm_thaw(struct device *dev)
{
	int ret = 0;
	(void)dev;

	if (get_s4_thaw_config() == S4_THAW_DISABLE)
		return ret;

	ret = (int)tc_s4_suspend_or_resume(TSP_S4_RESUME);
	if (ret != 0)
		tloge("s4 thaw failed\n");
	else
		set_s4_thaw_config(S4_THAW_DISABLE);

	return ret;
}
#endif

int tc_s4_pm_suspend(struct device *dev)
{
	int ret;
	char *kernel_mem_addr = NULL;
#ifdef CONFIG_TZ_S4_OPTIMIZE
	int event;
	event = dpm_get_message_event();
	if (event == PM_EVENT_QUIESCE)
		return 0;
#endif

#ifdef CONFIG_CMD_BUFFER_RESTORE
	ret = tc_s4_save_cmd_buf();
	if (ret != 0) {
		tloge("save cmd buffer failed\n");
		return ret;
	}
#endif

	ret = tc_s4_alloc_crypto_buffer(dev, &kernel_mem_addr);
	if (ret != 0) {
#ifdef CONFIG_CMD_BUFFER_RESTORE
		vfree(g_cmd_data_bk);
		g_cmd_data_bk = NULL;
#endif
		tloge("alloc buffer failed\n");
		return ret;
	}

	ret = tc_s4_pm_ops(dev, TSP_S4_SUSPEND, TSP_S4_ENCRYPT_AND_COPY, kernel_mem_addr);
	if (ret != 0) {
		free_resource(kernel_mem_addr);
		tloge("s4 suspend failed\n");
#ifdef CONFIG_AP_CUST_PAD_MEM
		if (tc_s4_pm_thaw(dev) != 0)
			tloge("while s4 suspend thaw failed\n");
#endif
	}

	return ret;
}

int tc_s4_pm_resume(struct device *dev)
{
	int ret;

#ifdef CONFIG_AP_CUST_PAD_MEM
	if (g_s4_thaw_config == S4_THAW_ENABLE) {
		ret = tc_s4_pm_thaw(dev);
		tloge("while s4 restore thaw failed\n");
		return ret;
	}
#endif
#ifdef CONFIG_TZ_S4_OPTIMIZE
	tc_s4_set_cpu_high_performance();
#endif

#ifdef CONFIG_CMD_BUFFER_RESTORE
	ret = tc_s4_restore_cmd_buf();
	if (ret != 0)
		tloge("restore cmd buffer failed\n");
#endif

	ret = tc_s4_pm_ops(dev, TSP_S4_RESUME, TSP_S4_DECRYPT_AND_COPY, g_s4_kernel_mem_addr);
	if (ret != 0)
		tloge("s4 resume failed\n");

	free_resource(g_s4_kernel_mem_addr);
	return ret;
}
