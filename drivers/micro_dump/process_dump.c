/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:process kinds of abnormal
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>
#include <linux/sched/debug.h>
#include <asm/stacktrace.h>

#ifdef CONFIG_MODULES
#include <linux/module.h>
#include <asm/module.h>
#endif

#define D_STATE_TASK_MAX_NUM	16

#ifdef CONFIG_MTK_AEE_IPANIC
#define REG_NUM 34
/* need sync with atf/v1.x/include/lib/psci/psci.h, make sure not to overlap */
#define PSCI_CORE_REGS_DUMP_AARCH32	0x8400001A
#define PSCI_CORE_REGS_DUMP_AARCH64	0xc400001A
#define REG_FP 29
#define REG_PC 32
#define PSTATE 33
extern struct mrdump_control_block *gmcb;
#endif

struct task_d_attr {
	struct task_struct *tsk;
	unsigned int deep;
};

#ifdef CONFIG_MODULES
struct module_sect_attr {
	struct bin_attribute attr;
	unsigned long address;
};

struct module_sect_attrs {
	struct attribute_group group;
	unsigned int nsections;
	struct module_sect_attr attrs[];
};

int microdump_ko_load_address(unsigned long addr)
{
	struct list_head *modules = NULL;
	struct module *mod = NULL;
	if (addr < module_alloc_base_addr || addr > (module_alloc_base_addr + MODULES_VSIZE)) {
		return -1;
	}

	modules = (void *)common_symbol_lookup_name("modules");
	if (modules == NULL) {
		MD_PRINT("look up module name fail\n");
		return -1;
	}

	list_for_each_entry_rcu(mod, modules, list) {
		if (mod->state == MODULE_STATE_UNFORMED) {
			MD_PRINT("state is unformed\n");
			break;
		}

		if (addr > mod->sect_attrs->attrs[0].address) {
			MD_PRINT("module name:%s load_base_address:%lx", mod->name,
				mod->sect_attrs->attrs[0].address);
			return 0;
		}
	}

	return -1;
}
#endif

enum micro_stack_type {
	MICRO_STACK_TYPE_UNKNOWN,
	MICRO_STACK_TYPE_TASK,
	MICRO_STACK_TYPE_IRQ,
	MICRO_STACK_TYPE_OVERFLOW,
	MICRO_STACK_TYPE_SDEI_NORMAL,
	MICRO_STACK_TYPE_SDEI_CRITICAL,
	MICRO___NR_STACK_TYPES
};

struct micro_stackframe {
	unsigned long fp;
	unsigned long pc;
	DECLARE_BITMAP(stacks_done, MICRO___NR_STACK_TYPES);
	unsigned long prev_fp;
	enum stack_type prev_type;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
	int graph;
#endif
};

static inline void micro_start_backtrace(struct micro_stackframe *frame,
	unsigned long fp, unsigned long pc)
{
	frame->fp = fp;
	frame->pc = pc;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
	frame->graph = 0;
#endif
	bitmap_zero(frame->stacks_done, MICRO___NR_STACK_TYPES);
	frame->prev_fp = 0;
	frame->prev_type = STACK_TYPE_UNKNOWN;
}

static int notrace micro_unwind_frame(struct task_struct *tsk, struct micro_stackframe *frame)
{
	unsigned long fp = frame->fp;
	struct stack_info info;

	if (fp & 0xf)
		return -EINVAL;

	if (!tsk)
		tsk = current;

	if (!common_on_accessible_stack(tsk, fp, 16, &info))
		return -EINVAL;

	if (test_bit(info.type, frame->stacks_done))
		return -EINVAL;
	if (info.type == frame->prev_type) {
		if (fp <= frame->prev_fp)
			return -EINVAL;
	} else {
		set_bit(frame->prev_type, frame->stacks_done);
	}
	frame->fp = READ_ONCE_NOCHECK(*(unsigned long *)(uintptr_t)(fp));
	frame->pc = READ_ONCE_NOCHECK(*(unsigned long *)(uintptr_t)(fp + 8));
	frame->prev_fp = fp;
	frame->prev_type = info.type;

	if (!frame->fp && !frame->pc)
		return -EINVAL;

	return 0;
}
static int backtrace_deep(struct task_struct *tsk)
{
	struct micro_stackframe frame;
	int num = 0;

	if (!try_get_task_stack(tsk)) {
		return -1;
	}
	micro_start_backtrace(&frame, thread_saved_fp(tsk), thread_saved_pc(tsk));
	do {
		num++;
	} while (!micro_unwind_frame(tsk, &frame));
#ifdef CONFIG_HN_MICRODUMP_GKI
	micro_put_task_stack(tsk);
#else
	put_task_stack(tsk);
#endif

	return num;
}

static void replace_min_value(struct task_d_attr param[], unsigned int length,
	unsigned int deep, struct task_struct *task)
{
	int deep_temp = deep;
	int index_temp = -1;
	int i;
	for (i = 0; i < length; i++) {
		if (deep_temp > param[i].deep) {
			index_temp = i;
			deep_temp = param[i].deep;
		}
	}

	if (index_temp != -1) {
		param[index_temp].deep = deep;
		param[index_temp].tsk = task;
	}
}

void microdump_crucial_process_dump(void)
{
	struct task_struct *g, *task;
	pid_t system_server_id = 0;
	char task_state;

	for_each_process_thread(g, task) {
		if (!strcmp(task->comm, "system_server")) {
			task_state = task_state_to_char(task);
			system_server_id = task->pid;
			MD_PRINT("task pid: %d, name: %s, state: %c, last_arrival: %llu\n",
				task->pid, task->comm, task_state, task->sched_info.last_arrival);
			common_show_stack(task, NULL, KERN_INFO);
		}
		if (!strcmp(task->comm, "watchdog")) {
			if (task->tgid == system_server_id) {
				task_state = task_state_to_char(task);
				MD_PRINT("task pid: %d, name: %s, state: %c, last_arrival: %llu\n",
				task->pid, task->comm, task_state, task->sched_info.last_arrival);
				common_show_stack(task, NULL, KERN_INFO);
			}
		}
	}
}

#ifdef CONFIG_MTK_AEE_IPANIC
/*
 * Compared to function unwind_frame,this function
 * does not have on_accessible_stack check and no task arg.
 */
static int notrace unwind_frame_nosafe(struct stackframe *frame)
{
	unsigned long fp = frame->fp;

	if (fp & 0xf)
		return -EINVAL;

	frame->fp = READ_ONCE_NOCHECK(*(unsigned long *)(fp));
	frame->pc = READ_ONCE_NOCHECK(*(unsigned long *)(fp + 8));

	if (!frame->fp || !frame->pc)
		return -EINVAL;

	return 0;
}

static void print_backtrace(unsigned long *reg)
{
	struct stackframe frame;

	frame.fp = reg[REG_FP];
	frame.pc = reg[REG_PC];

	MD_PRINT("Call trace:\n");
	do {
		MD_PRINT(" %pS\n", (void *)(uintptr_t)frame.pc);
	} while (!unwind_frame_nosafe(&frame));
}

static void print_regs(int cpu, unsigned long *reg, struct aarch64_ctrl_regs *creg)
{
	unsigned int i;

	MD_PRINT("cpu%d-regs:\n", cpu);
	for (i = 0; i < REG_NUM; i++) {
		if (i % 8 == 0)
			MD_PRINT("x%d:", i);
		pr_cont("0x%016lx ", reg[i]);
	}
	microdump_corereg_pstate(reg[PSTATE]);
	MD_PRINT("sctlr_el1:%016llx tcr_el1:%016llx ttbr0_el1:%016llx"
		" ttbr1_el1:%016llx sp_el0:%016llx sp_el1:%016llx\n",
		creg->sctlr_el1, creg->tcr_el1, creg->ttbr0_el1,
		creg->ttbr1_el1, creg->sp_el[0], creg->sp_el[1]);
}
#endif

void microdump_on_core_process_dump(void)
{
	struct task_struct *task = NULL;
	char task_state;
	int i;
#ifdef CONFIG_MTK_AEE_IPANIC
	unsigned long *arm64_reg;
	struct aarch64_ctrl_regs *arm64_creg;
	struct mrdump_control_block *mcb;
	struct arm_smccc_res res;
	bool stored = false;

	arm_smccc_smc(PSCI_CORE_REGS_DUMP_AARCH64, 0, 0, 0, 0, 0, 0, 0, &res);
	if ((res.a0 == 0) && (gmcb != NULL)) {
		stored = true;
		mcb = gmcb;
		MD_PRINT("gmcb and smc_call is ok, will dump backtrace dump regs\n");
	}
#endif

	for (i = 0; i < MICRO_CPU_NR; i++) {
		struct rq *rq;
		rq = cpu_rq(i);
		if (!rq)
			continue;
		task = rq->curr;

		if (task) {
			task_state = task_state_to_char(task);
			MD_PRINT("task pid: %d, name: %s, state:%c, task address: 0x%lx on CPU-%d\n",
				task->pid, task->comm, task_state, task, i);
#ifdef CONFIG_MTK_AEE_IPANIC
			/*
			 * Because the current process has been to atf to save the registers of each core,
			 * its pc value belongs to atf, so pc and fp cannot be used to print the stack,
			 * other use microdump_print_regs.
			 */
			if (task == current)
#endif
				common_show_stack(task, NULL, KERN_INFO);

			switch (task_state) {
			case 'D':
			case 'S':
			case 'T':
			case 't':
			case 'I':
				microdump_stack_by_sp((unsigned long)(task->thread.cpu_context.sp), task,
#ifdef CONFIG_SHADOW_CALL_STACK
				(unsigned long) (task->thread_info.scs_sp)
#else
				0UL
#endif
				);
				break;
			case 'R':
#ifdef CONFIG_MTK_AEE_IPANIC
				if (stored && (task != current)) {
					arm64_reg = (unsigned long *)&mcb->crash_record.cpu_reg[i].arm64_reg.arm64_regs;
					arm64_creg = &mcb->crash_record.cpu_reg[i].arm64_reg.arm64_creg;
					print_backtrace(arm64_reg);
					print_regs(i, arm64_reg, arm64_creg);
					microdump_stack_by_sp(arm64_reg[REG_FP], task,
#ifdef CONFIG_SHADOW_CALL_STACK
					(unsigned long) (task->thread_info.scs_sp)
#else
					0UL
#endif
					);
				} else {
					microdump_stack_by_task(task);
				}
#else
				microdump_stack_by_task(task);
#endif
				break;
			default:
				break;
			}
			microdump_byte_dump_checked((uintptr_t)task, 0, sizeof(struct task_struct), NULL);
		}
	}
}

void microdump_D_state_process_dump(void)
{
	struct task_struct *task = NULL;
	char task_state;
	int index = 0;
	int deep_temp;
	int i;
	struct task_d_attr task_attr[D_STATE_TASK_MAX_NUM];

	for_each_process(task) {
		task_state = task_state_to_char(task);
		if (task_state == 'D') {
			deep_temp = backtrace_deep(task);
			if (deep_temp == -1) {
				continue;
			}
			if (index < D_STATE_TASK_MAX_NUM) {
				task_attr[index].tsk = task;
				task_attr[index].deep = deep_temp;
				index++;
			} else {
				replace_min_value(task_attr, D_STATE_TASK_MAX_NUM, deep_temp, task);
			}
		}
	}

	for (i = 0; i < index; i++) {
		if (task_attr[i].deep != 0) {
			MD_PRINT("D task pid: %d, name: %s, task address: 0x%lx\n",
				task_attr[i].tsk->pid, task_attr[i].tsk->comm, task_attr[i].tsk);
			common_show_stack(task, NULL, KERN_INFO);

			microdump_stack_by_sp((unsigned long)(task_attr[i].tsk->thread.cpu_context.sp),
				task_attr[i].tsk,
#ifdef CONFIG_SHADOW_CALL_STACK
				(unsigned long)(task_attr[i].tsk->thread_info.scs_sp)
#else
				(unsigned long) 0
#endif
			);
		}
	}
}

void microdump_relation_process_dump(void)
{
	MD_PRINT("%s: start here\n", __func__);
	microdump_hungtask_stack();
}

void microdump_task_struct_dump(struct task_struct *task)
{
	if (!task)
		return;

	if (!microdump_check_addr_valid((unsigned long)(uintptr_t)task))
		return;

	MD_PRINT("task: %s,pid %d,task_struct 0x%lx\n", task->comm, task->pid, task);
	microdump_page_dump_checked((unsigned long)(uintptr_t)task, TASK_MULTIPLE_PAGE_SIZE, NULL);
}
