/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump policy function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

static struct struct_policy micro_policy[] = {
	{
		.name = "DABT",
		.func = dabt_policy
	},
	{
		.name = "HUNG",
		.func = hung_policy
	},
	{
		.name = "UNINSTR",
		.func = undefinstr_policy
	},
	{
		.name = "SUBSYS",
		.func = subsys_policy
	},
	{
		.name = "ASSERT",
		.func = assert_policy
	},
	{
		.name = "OUTMEM",
		.func = outmem_policy
	},
	{
		.name = "BUS",
		.func = bus_policy
	},
	{
		.name = "UNKNOW",
		.func = unknow_policy
	},
};

static const unsigned long micro_policy_index[] = {
	DIE_TYPE_DABT,
	DIE_TYPE_HUNG,
	DIE_TYPE_UNDEFINE_INSTR,
	DIE_TYPE_SUBSYS,
	DIE_TYPE_ASSERT,
	DIE_TYPE_OOM,
	DIE_TYPE_BUS,
	DIE_TYPE_UNKNOWN
};

policy_func microdump_get_policy(unsigned long error_type)
{
	int i;
	int len = sizeof(micro_policy_index) / sizeof(unsigned long);

	for (i = 0; i < len; i++) {
		if (error_type & micro_policy_index[i]) {
			return micro_policy[i].func;
		}
	}
	return NULL;
}

static void dabt_policy_local_stack_dump()
{
	if (is_stack_ptr(g_exp_ctrl.regs.sp, (unsigned long)g_exp_ctrl.task->stack)) {
		microdump_stack_local_var(g_exp_ctrl.regs.regs[FP_REGISTER], g_exp_ctrl.task->stack, MAX_STACK_FRAME);
	} else {
		microdump_stack_local_irq(g_exp_ctrl.regs.regs[FP_REGISTER]);
		microdump_stack_local_var(g_exp_ctrl.task->thread.cpu_context.fp, g_exp_ctrl.task->stack, MAX_STACK_FRAME);
	}
}

static void dump_core_irqstack()
{
	int i;
	for (i = 0; i < MICRO_CPU_NR; i++) {
		microdump_cpu_irqstack(i);
	}
}

int dabt_policy(unsigned long type)
{
	switch (type) {
	case SUB_TYPE_RW_ONLY:
	case SUB_TYPE_UNREADABLE:
	case SUB_TYPE_NULL_POINT:
	case SUB_TYPE_PAGE_REQ:
		bitflip_sub_type_dabt();
	case SUB_TYPE_SP_PC:
		microdump_register_dump();
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		dabt_policy_local_stack_dump();
		break;
	case SUB_TYPE_UNHANDLE:
	case SUB_TYPE_UNKNOWN_ADDR:
		bitflip_sub_type_dabt();
	default:
		microdump_stack_by_task(g_exp_ctrl.task);
		microdump_register_dump();
		break;
	}
	return 0;
}

int hung_policy(unsigned long type)
{
	switch (type) {
	case SUB_TYPE_HUNG_TASK:
		microdump_relation_process_dump();
		microdump_hungtask_lock_dump();
		microdump_irq_dump();
		microdump_on_core_process_dump();
		dump_core_irqstack();
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
		microdump_sched_dump();
#endif
		break;
	case SUB_TYPE_HANG_DETECT:
		microdump_crucial_process_dump();
		microdump_on_core_process_dump();
		break;
	case SUB_TYPE_WDT:
		microdump_irq_dump();
		microdump_on_core_process_dump();
		dump_core_irqstack();
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0)
		microdump_sched_dump();
#endif
		break;
	default:
		microdump_D_state_process_dump();
		break;
	}
	return 0;
}

int undefinstr_policy(unsigned long type)
{
	switch (type) {
	case SUB_TYPE_UNDEFINE_INSTR:
		if (g_exp_ctrl.regs.sp != 0) {
			microdump_register_dump();
			if (microdump_check_addr_valid(g_exp_ctrl.regs.sp)) {
				microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
			} else {
				microdump_stack_by_task(g_exp_ctrl.task);
			}

			if (microdump_check_addr_valid(g_exp_ctrl.regs.regs[SCS_REGISTER])) {
#ifdef CONFIG_SHADOW_CALL_STACK
				microdump_print_scs_x18(g_exp_ctrl.regs.regs[SCS_REGISTER]);
#endif
			} else {
#ifdef CONFIG_SHADOW_CALL_STACK
				microdump_print_scs_task(g_exp_ctrl.task);
#endif
			}
		} else {
			microdump_stack_by_task(g_exp_ctrl.task);
#ifdef CONFIG_SHADOW_CALL_STACK
			microdump_print_scs_task(g_exp_ctrl.task);
#endif
		}
		break;
	default:
		break;
	}
	return 0;
}

int subsys_policy(unsigned long type)
{
	switch (type) {
#ifdef CONFIG_ARCH_QCOM
	case SUB_TYPE_ADSP:
	{
	}
	case SUB_TYPE_RPM:
	{
	}
#endif
#ifdef CONFIG_ARCH_MTK
	case SUB_TYPE_SSPM:
	{
	}
	case SUB_TYPE_SCP:
	{
	}
#endif
	default:
	{
		break;
	}
	}
	return 0;
}

int assert_policy(unsigned long type)
{
	switch (type) {
	case SUB_TYPE_BUG_ON:
		microdump_register_dump();
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		dabt_policy_local_stack_dump();
		break;
	case SUB_TYPE_BUG:
		microdump_register_dump();
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		dabt_policy_local_stack_dump();
		break;
	case SUB_TYPE_TRIGGER:
		// sysrq-trigger by c
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		break;
	case SUB_TYPE_MANUAL_TRIGGER:
		microdump_D_state_process_dump();
		break;
	case SUB_TYPE_OTHER_PANIC:
		// just a panic, no die flow, so need save regs by asm manully
		microdump_register_dump();
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		dabt_policy_local_stack_dump();
		break;
	case SUB_TYPE_OTHER_DIE:
		// die with unknow type
		microdump_register_dump();
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
		dabt_policy_local_stack_dump();
		break;
	default:
		break;
	}
	return 0;
}

int outmem_policy(unsigned long type)
{
	return 0;
}

int bus_policy(unsigned long type)
{
	switch (type) {
	case SUB_TYPE_SEA:
		microdump_stack_by_sp(g_exp_ctrl.regs.sp, g_exp_ctrl.task, g_exp_ctrl.regs.regs[SCS_REGISTER]);
#ifdef CONFIG_SHADOW_CALL_STACK
		if (g_exp_ctrl.regs.regs[SCS_REGISTER] != 0) {
			if (microdump_check_addr_valid(g_exp_ctrl.regs.regs[SCS_REGISTER])) {
				microdump_print_scs_x18(g_exp_ctrl.regs.regs[SCS_REGISTER]);
			} else {
				microdump_print_scs_task(g_exp_ctrl.task);
			}
		} else {
			microdump_print_scs_task(g_exp_ctrl.task);
		}
#endif
		break;
	default:
		break;
	}
	return 0;
}

int unknow_policy(unsigned long type)
{
	return 0;
}

int cloud_policy(unsigned long type)
{
	return 0;
}

int reverse_policy(unsigned long type)
{
	return 0;
}
