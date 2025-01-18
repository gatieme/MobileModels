/*
 * lpcpu_dsu_pmu_cfg.c
 *
 * dsu_pmu config
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include "lpcpu_dsu_pmu_cfg.h"

#ifdef CONFIG_LPCPU_MULTIDRV_CPUIDLE
extern bool lpcpu_fcm_cluster_pwrdn(void);
#else
static inline bool lpcpu_fcm_cluster_pwrdn(void) {return 0;}
#endif

#ifdef CONFIG_CPU_PM
struct cpu_pm_dsu_pmu_args {
	struct dsu_pmu	*dsu_pmu;
	unsigned long	cmd;
	int		cpu;
	int		ret;
};

void dsu_pmu_stop(struct perf_event *event, int pmu_flags);
void dsu_pmu_start(struct perf_event *event, int pmu_flags);
void dsu_pmu_enable(struct pmu *pmu);
void dsu_pmu_disable(struct pmu *pmu);

static void cpu_pm_dsu_pmu_setup(struct dsu_pmu *dsu_pmu, unsigned long cmd)
{
	struct dsu_hw_events *hw_events = &dsu_pmu->hw_events;
	struct perf_event *event = NULL;
	int idx;

	for (idx = 0; idx < DSU_PMU_MAX_HW_CNTRS; idx++) {
		/*
		 * If the counter is not used skip it, there is no
		 * need of stopping/restarting it.
		 */
		if (!test_bit(idx, hw_events->used_mask))
			continue;

		event = hw_events->events[idx];
		if (!event)
			continue;

		/*
		 * Check if an attempt was made to free this event during
		 * the CPU went offline.
		 */
		if (event->state != PERF_EVENT_STATE_ACTIVE)
			continue;

		switch (cmd) {
		case CPU_PM_ENTER:
			/*
			 * Stop and update the counter
			 */
			dsu_pmu_stop(event, PERF_EF_UPDATE);
			break;
		case CPU_PM_EXIT:
		case CPU_PM_ENTER_FAILED:
			 /*
			  * Restore and enable the counter.
			  * dsu_pmu_start() indirectly calls
			  *
			  * perf_event_update_userpage()
			  *
			  * that requires RCU read locking to be functional,
			  * wrap the call within RCU_NONIDLE to make the
			  * RCU subsystem aware this cpu is not idle from
			  * an RCU perspective for the dsu_pmu_start() call
			  * duration.
			  */
			RCU_NONIDLE(dsu_pmu_start(event, PERF_EF_RELOAD));
			break;
		default:
			break;
		}
	}
}

static void cpu_pm_dsu_pmu_common(void *info)
{
	struct cpu_pm_dsu_pmu_args *data	= info;
	struct dsu_pmu *dsu_pmu		= data->dsu_pmu;
	unsigned long cmd		= data->cmd;
	int cpu				= data->cpu;
	struct dsu_hw_events *hw_events = &dsu_pmu->hw_events;
	bool enabled = false;
	bool fcm_pwrdn = 0;

	if (!cpumask_test_cpu(cpu, &dsu_pmu->associated_cpus)) {
		data->ret = NOTIFY_DONE;
		return;
	}

	enabled = test_bit(DSU_PMU_IDX_CYCLE_COUNTER, hw_events->used_mask) > 0 ||
		 bitmap_weight(hw_events->used_mask, dsu_pmu->num_counters) > 0;
	if (!enabled) {
		data->ret = NOTIFY_OK;
		return;
	}

	data->ret = NOTIFY_OK;

	switch (cmd) {
	case CPU_PM_ENTER:
		spin_lock(&dsu_pmu->fcm_idle_lock);
		fcm_pwrdn = lpcpu_fcm_cluster_pwrdn();
		if (fcm_pwrdn && !dsu_pmu->fcm_idle) {
			dsu_pmu->fcm_idle = true;
			dsu_pmu_disable(&dsu_pmu->pmu);
			cpu_pm_dsu_pmu_setup(dsu_pmu, cmd);
		}
		spin_unlock(&dsu_pmu->fcm_idle_lock);
		break;
	case CPU_PM_EXIT:
	case CPU_PM_ENTER_FAILED:
		spin_lock(&dsu_pmu->fcm_idle_lock);
		if (dsu_pmu->fcm_idle) {
			dsu_pmu->fcm_idle = false;
			cpu_pm_dsu_pmu_setup(dsu_pmu, cmd);
			dsu_pmu_enable(&dsu_pmu->pmu);
		}
		spin_unlock(&dsu_pmu->fcm_idle_lock);
		break;
	default:
		data->ret = NOTIFY_DONE;
		break;
	}
}

static int cpu_pm_dsu_pmu_notify(struct notifier_block *b, unsigned long cmd,
				 void *v)
{
	struct cpu_pm_dsu_pmu_args data = {
		.dsu_pmu	= container_of(b, struct dsu_pmu, cpu_pm_nb),
		.cmd	= cmd,
		.cpu	= smp_processor_id(),
	};

	cpu_pm_dsu_pmu_common(&data);
	return data.ret;
}

int cpu_pm_dsu_pmu_register(struct dsu_pmu *dsu_pmu __maybe_unused)
{
	if (dsu_pmu == NULL) {
		pr_err("cpu pm dsu pmu register!\n");
		return -EINVAL;
	}

	dsu_pmu->cpu_pm_nb.notifier_call = cpu_pm_dsu_pmu_notify;
	return cpu_pm_register_notifier(&dsu_pmu->cpu_pm_nb);
}

void cpu_pm_dsu_pmu_unregister(struct dsu_pmu *dsu_pmu __maybe_unused)
{
	if (dsu_pmu == NULL) {
		pr_err("cpu pm dsu pmu unregister!\n");
		return;
	}

	cpu_pm_unregister_notifier(&dsu_pmu->cpu_pm_nb);
}
#endif
