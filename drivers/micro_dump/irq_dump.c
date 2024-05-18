/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

#include <linux/rcupdate.h>
#include <linux/cpumask.h>
#include <linux/percpu-defs.h>
#include <linux/irq.h>
#include <linux/irqdesc.h>
#include <linux/printk.h>
#include <linux/sched.h>

#ifndef ACTUAL_NR_IRQS
#define ACTUAL_NR_IRQS nr_irqs
#endif

void microdump_cpu_irqstack(int cpu)
{
	struct microdump_page_info info = {0};
	unsigned long irq_stk;
	int i;
	int dump_pages = TASK_MULTIPLE_PAGE_SIZE >> 1; // just dump 2 pages for irq stack;

	if (cpu < 0 || cpu > MICRO_CPU_NR)
		return;
	irq_stk = (unsigned long)per_cpu(micro_irq_stack_ptr, cpu) +
		(TASK_MULTIPLE_PAGE_SIZE - dump_pages) * PAGE_SIZE;

	for (i = 0; i < dump_pages; i++) {
		if (microdump_check_addr_valid(irq_stk)) {
			info.type = TYPE_STACK;
			info.start_vir_addr = irq_stk + i * PAGE_SIZE;
			MD_PRINT("%s irqstack cpu:%d , stack=0x%lx\n", __func__, cpu, irq_stk);
			microdump_page_dump_checked(irq_stk + i * PAGE_SIZE,
				dump_pages - i, &info);
			break;
		}
	}
}

void microdump_irq_dump(void)
{
	int i;
	int j;
	const char *act = NULL;
	struct irqaction *action;
	struct irq_desc *desc;
	unsigned long irq_count;
	unsigned long long start_ts;
	unsigned long long end_ts;
	unsigned long long duration;
	unsigned long msec_rem;

	MD_PRINT("irqs info:\n");
	start_ts = sched_clock();
	for (i = 1; i < ACTUAL_NR_IRQS; ++i) {
		rcu_read_lock();
		desc = irq_to_desc(i);
		act = NULL;
		irq_count = 0;

		if (!desc) {
			MD_PRINT("%s for irq id %d failed\n", __func__, i);
			rcu_read_unlock();
			continue;
		}

		action = desc->action;
		if (action)
			act = action->name;

		if (act != NULL) {
			for_each_present_cpu(j)
				irq_count += desc->kstat_irqs ? *per_cpu_ptr(desc->kstat_irqs, j) : 0;

			if (irq_count > 0) {
				MD_PRINT("irq %d: ", i);
				for_each_present_cpu(j)
					pr_cont("%d, ", desc->kstat_irqs ? *per_cpu_ptr(desc->kstat_irqs, j) : 0);
				pr_cont("%s\n", act);
			}
		}

		rcu_read_unlock();
	}
	end_ts = sched_clock();
	duration = end_ts - start_ts;
	msec_rem = do_div(duration, NSEC_PER_MSEC);
	MD_PRINT("irqs info printing take %llu.%06lums\n", duration, msec_rem);
}
