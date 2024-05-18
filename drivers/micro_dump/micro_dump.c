/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>
#include <linux/nmi.h>

#define USER_REG_NUM_MAX		12
#define KERNEL_REG_NUM_MAX		29

static atomic_t g_has_panic = ATOMIC_INIT(-1);
static atomic_t g_has_die   = ATOMIC_INIT(-1);

struct global_exp_ctrl g_exp_ctrl;

struct fault_reson_data {
	const char *str;
	unsigned long type;
};

static const struct fault_reson_data g_fault_reason[] = {
	{"BUG",								SUB_TYPE_BUG},
	{"BRK handler",							SUB_TYPE_BUG},
	{"Hang",							SUB_TYPE_HANG_DETECT},
	{"hung",							SUB_TYPE_HUNG_TASK},
	{"synchronous external abort",					SUB_TYPE_SEA},
	{"SP/PC alignment exception",					SUB_TYPE_SP_PC},
	{"Oops",							DIE_TYPE_DABT},
	{"unknow direct panic",						DIE_TYPE_UNKNOWN},
	{"HWT",								SUB_TYPE_WDT},
	{"CFI",								SUB_TYPE_UNDEFINE_INSTR},
	{"sysrq triggered crash",					SUB_TYPE_TRIGGER},
};

static void touch_watchdog()
{
	touch_nmi_watchdog();
}

static void asm_get_regs(struct pt_regs *regs)
{
	struct pt_regs *p;

	if (!regs)
		return;

	p = regs;

	asm volatile(
	"stp	x0, x1, [%0, #16 * 0]\n"
	"stp	x2, x3, [%0, #16 * 1]\n"
	"stp	x4, x5, [%0, #16 * 2]\n"
	"stp	x6, x7, [%0, #16 * 3]\n"
	"stp	x8, x9, [%0, #16 * 4]\n"
	"stp	x10, x11, [%0, #16 * 5]\n"
	"stp	x12, x13, [%0, #16 * 6]\n"
	"stp	x14, x15, [%0, #16 * 7]\n"
	"stp	x16, x17, [%0, #16 * 8]\n"
	"stp	x18, x19, [%0, #16 * 9]\n"
	"stp	x20, x21, [%0, #16 * 10]\n"
	"stp	x22, x23, [%0, #16 * 11]\n"
	"stp	x24, x25, [%0, #16 * 12]\n"
	"stp	x26, x27, [%0, #16 * 13]\n"
	"stp	x28, x29, [%0, #16 * 14]\n"
	"stp	x30, x29, [%0, #16 * 15]\n"
	"stp	x30, x30, [%0, #16 * 16]\n"
	::"r"(p):"memory");
}

static inline char pstate_flag(bool bit_set, char set, char clear)
{
	return bit_set ? set : clear;
}

#define MEM_RANGE (128)
static void microdump_print_pstate(struct pt_regs *regs)
{
	unsigned long pstate = regs->pstate;

	if (compat_user_mode(regs)) {
		MD_PRINT("pstate: %08llx (%c%c%c%c %c %s %s %c%c%c)\n",
			pstate,
			pstate_flag(pstate & PSR_AA32_N_BIT, 'N', 'n'),
			pstate_flag(pstate & PSR_AA32_Z_BIT, 'Z', 'z'),
			pstate_flag(pstate & PSR_AA32_C_BIT, 'C', 'c'),
			pstate_flag(pstate & PSR_AA32_V_BIT, 'V', 'v'),
			pstate_flag(pstate & PSR_AA32_Q_BIT, 'Q', 'q'),
			(pstate & PSR_AA32_T_BIT) ? "T32" : "A32",
			(pstate & PSR_AA32_E_BIT) ? "BE" : "LE",
			pstate_flag(pstate & PSR_AA32_A_BIT, 'A', 'a'),
			pstate_flag(pstate & PSR_AA32_I_BIT, 'I', 'i'),
			pstate_flag(pstate & PSR_AA32_F_BIT, 'F', 'f'));
	} else {
		MD_PRINT("pstate: %08llx (%c%c%c%c %c%c%c%c %cPAN %cUAO)\n",
			pstate,
			pstate_flag(pstate & PSR_N_BIT, 'N', 'n'),
			pstate_flag(pstate & PSR_Z_BIT, 'Z', 'z'),
			pstate_flag(pstate & PSR_C_BIT, 'C', 'c'),
			pstate_flag(pstate & PSR_V_BIT, 'V', 'v'),
			pstate_flag(pstate & PSR_D_BIT, 'D', 'd'),
			pstate_flag(pstate & PSR_A_BIT, 'A', 'a'),
			pstate_flag(pstate & PSR_I_BIT, 'I', 'i'),
			pstate_flag(pstate & PSR_F_BIT, 'F', 'f'),
			pstate_flag(pstate & PSR_PAN_BIT, '+', '-'),
			pstate_flag(pstate & PSR_UAO_BIT, '+', '-'));
	}
}

void microdump_corereg_pstate(unsigned long pstate)
{
	struct pt_regs regs;

	regs.pstate = pstate;
	microdump_print_pstate(&regs);
}

static void microdump_show_regs(struct pt_regs *regs)
{
	int i;
	int top_reg;
	unsigned long lr;
	unsigned long sp;

	if (compat_user_mode(regs)) {
		lr = regs->compat_lr;
		sp = regs->compat_sp;
		top_reg = USER_REG_NUM_MAX;
	} else {
		lr = regs->regs[30]; // 30: ARM64 PLR register
		sp = regs->sp;
		top_reg = KERNEL_REG_NUM_MAX;
	}

	microdump_print_pstate(regs);

	if (!user_mode(regs)) {
		MD_PRINT("pc : [0x%lx] %pS\n", regs->pc, (void *)regs->pc);
		MD_PRINT("lr : [0x%lx] %pS\n", lr, (void *)lr);
	}

	MD_PRINT("sp : %016llx\n", sp);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
	if (system_uses_irq_prio_masking())
		MD_PRINT("pmr_save: %08llx\n", regs->pmr_save);
#endif
	i = top_reg;

	while (i >= 1) {
		MD_PRINT("x%-2d: %016llx x%-2d: %016llx\n", i, regs->regs[i], i - 1, regs->regs[i - 1]);
		i -= 2; // 2:print 2 reg in one loop
	}
}

static bool has_die(void)
{
	return atomic_read(&g_has_die) != -1;
}

static inline bool is_el1_permission_fault(unsigned long addr, unsigned int esr,
	struct pt_regs *regs)
{
	unsigned int ec = ESR_ELx_EC(esr);
	unsigned int fsc_type = esr & ESR_ELx_FSC_TYPE;

	if (ec != ESR_ELx_EC_DABT_CUR && ec != ESR_ELx_EC_IABT_CUR)
		return false;

	if (fsc_type == ESR_ELx_FSC_PERM)
		return true;

	return false;
}

static bool is_el1_instr_abort(unsigned int esr)
{
	return ESR_ELx_EC(esr) == ESR_ELx_EC_IABT_CUR;
}

static unsigned long dabt_kernel_fault(unsigned long addr, unsigned int esr,
		struct pt_regs *regs)
{
	const char *msg = NULL;

	if (is_el1_permission_fault(addr, esr, regs)) {
		if (esr & ESR_ELx_WNR) {
			msg = "write to read-only memory";
			return SUB_TYPE_RW_ONLY;
		} else if (is_el1_instr_abort(esr)) {
			msg = "execute from non-executable memory";
			return SUB_TYPE_UNEXCUTE;
		} else {
			msg = "read from unreadable memory";
			return SUB_TYPE_UNREADABLE;
		}
	} else if (addr < PAGE_SIZE) {
		msg = "NULL pointer dereference";
		return SUB_TYPE_NULL_POINT;
	} else {
		msg = "paging request";
		return SUB_TYPE_PAGE_REQ;
	}

	if (!msg) {
		msg = "unknown_addr";
		return SUB_TYPE_UNKNOWN_ADDR;
	}
}

static unsigned long fault_reason(const char *str)
{
	int i;
	for (i = 0; i < (sizeof(g_fault_reason) / sizeof(g_fault_reason[0])); i++) {
		if (strstr(str, g_fault_reason[i].str) != NULL) {
			return g_fault_reason[i].type;
		}
	}
	return DIE_TYPE_UNKNOWN;
}

static unsigned long analyse_kernel_fault(const char *str, unsigned long addr,
	unsigned int esr, struct pt_regs *regs)
{
	unsigned long type = SUB_TYPE_OTHER_DIE;

	if (str)
		type = fault_reason(str);

	if ((type & DIE_TYPE_DABT) || (type == DIE_TYPE_UNKNOWN)) {
		type = dabt_kernel_fault(addr, esr, regs);
	}

	return (type == DIE_TYPE_UNKNOWN) ? SUB_TYPE_OTHER_DIE : type;
}

static unsigned long analyse_kernel_panic(const char *str)
{
	unsigned long type = SUB_TYPE_OTHER_PANIC;

	if (str) {
		type = fault_reason(str);
	}

	return (type == DIE_TYPE_UNKNOWN) ? SUB_TYPE_OTHER_PANIC : type;
}

static int ddr_reverse_probe(void)
{
	return 0;
}

static policy_func get_cloud_policy(unsigned long die_type)
{
	return NULL;
}

void micro_dump_entry(void)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
	mm_segment_t fs;
#endif
	int res;
	int reverse;
	policy_func func;

	MD_PRINT("<<<<<<< micro dump to log_buf start has_die=%d, has_panic=%d \n",
		atomic_read(&g_has_die), atomic_read(&g_has_panic));

	if (g_exp_ctrl.error_type == DIE_TYPE_UNKNOWN) {
		MD_PRINT("unknow error type ,exit!\n");
		return;
	}

	reverse = ddr_reverse_probe();
	if (reverse) {
		reverse_policy(g_exp_ctrl.error_type);
		MD_PRINT("memory reverse error type!\n");
		return;
	}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
	fs = get_fs();
	set_fs(KERNEL_DS);
#endif

	func = get_cloud_policy(g_exp_ctrl.error_type);
	if (func) {
		res = func(g_exp_ctrl.error_type);
		if (res != 0)
			goto out;
	}

	func = microdump_get_policy(g_exp_ctrl.error_type);
	if (func) {
		res = func(g_exp_ctrl.error_type);
		if (res != 0)
			goto out;
	}

out:
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
	set_fs(fs);
#endif
	MD_PRINT(">>>>>>> micro dump to log_buf end\n");
}

static void micro_dump_reason_set(const char *reason, unsigned long die_type, void *arg)
{
	if (g_exp_ctrl.error_type != DIE_TYPE_UNKNOWN &&
		g_exp_ctrl.error_type != SUB_TYPE_OTHER_PANIC &&
		g_exp_ctrl.error_type != SUB_TYPE_OTHER_DIE) {
		MD_PRINT("error reason has set: %s, new type=%lx, old type=%lx\n", reason, die_type,
			g_exp_ctrl.error_type);
		return;
	}

	MD_PRINT("set error reason: %s, type=%lx\n", reason, die_type);
	g_exp_ctrl.error_type = die_type;
}

static int die_callback(struct notifier_block *self, unsigned long cmd, void *ptr)
{
	unsigned long type;
	const char *reason;
	struct die_args *dargs = (struct die_args *)ptr;

	reason = dargs->str;
	if (atomic_inc_and_test(&g_has_die)) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
		type = analyse_kernel_fault(reason, dargs->regs->sdei_ttbr1, dargs->err, dargs->regs);
#else
		type = analyse_kernel_fault(reason, dargs->regs->orig_addr_limit, dargs->err, dargs->regs);
#endif
		micro_dump_reason_set(reason, type, NULL);
		g_exp_ctrl.die_cpu = raw_smp_processor_id();
		MD_PRINT("die_callback, error type is: 0x%lx \n", type);

		if (dargs && dargs->regs) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0))
			g_exp_ctrl.addr = dargs->regs->sdei_ttbr1;
#else
			g_exp_ctrl.addr = dargs->regs->orig_addr_limit;
#endif
			g_exp_ctrl.task = current;
			MD_PRINT("die_callback, task.comm:%s, task.pid:%d, stack:0x%lx \n",
				g_exp_ctrl.task->comm, g_exp_ctrl.task->pid, g_exp_ctrl.task->stack);
			crash_setup_regs(&g_exp_ctrl.regs, dargs->regs);

			if (!interrupts_enabled(dargs->regs))
				g_exp_ctrl.die_in_irq = 1;
			microdump_show_regs(&g_exp_ctrl.regs);
			dump_stack();
		}
	} else {
		MD_PRINT("die_callback has called by cpu:%d, it must be double die in die flow.\n",
			g_exp_ctrl.die_cpu);
	}

	return NOTIFY_DONE;
}

static int panic_callback(struct notifier_block *self, unsigned long cmd, void *ptr)
{
	unsigned long type = DIE_TYPE_UNKNOWN;
	const char *reason = ptr;

	if (atomic_inc_and_test(&g_has_panic)) {
		if (g_exp_ctrl.error_type == DIE_TYPE_UNKNOWN ||
			g_exp_ctrl.error_type == SUB_TYPE_OTHER_DIE) {
			type = analyse_kernel_panic(reason);
			micro_dump_reason_set(reason, type, NULL);
		}

		if (!has_die()) { // no die flow, direct panic flow, so need save regs by asm manully
			asm_get_regs(&g_exp_ctrl.regs);
			g_exp_ctrl.task = current;
			MD_PRINT("panic_callback, task.comm:%s, task.pid:%d, stack:0x%lx \n",
				g_exp_ctrl.task->comm, g_exp_ctrl.task->pid, g_exp_ctrl.task->stack);
			microdump_show_regs(&g_exp_ctrl.regs);
			dump_stack();
		}

		g_exp_ctrl.panic_cpu = raw_smp_processor_id();
		MD_PRINT("panic_callback, error type is: 0x%lx \n", type);
		touch_watchdog();
		micro_dump_entry();
	} else {
		MD_PRINT("panic_callback has called by cpu:%d, it must be double panic in panic flow.\n",
			g_exp_ctrl.panic_cpu);
		dump_stack();
	}

	return NOTIFY_DONE;
}

static struct notifier_block g_die_blk = {
	.notifier_call = die_callback,
	.priority = INT_MAX,
};

static struct notifier_block g_panic_blk = {
	.notifier_call = panic_callback,
	.priority = INT_MAX,
};

#ifdef CONFIG_MTK_AEE_IPANIC
struct mrdump_control_block *gmcb;
static int micro_mrdump_parse_chosen(struct mrdump_params *mparams)
{
	struct device_node *node;
	u32 reg[2];

	memset_s(mparams, sizeof(struct mrdump_params), 0, sizeof(struct mrdump_params));
	node = of_find_node_by_path("/chosen");
	if (node) {
		if (of_property_read_u32_array(node, "mrdump,cblock",
			reg, ARRAY_SIZE(reg)) == 0) {
			mparams->cb_addr = reg[0];
			mparams->cb_size = reg[1];
			MD_PRINT("%s: mrdump_cbaddr=%x, mrdump_cbsize=%x\n",
				__func__, mparams->cb_addr, mparams->cb_size);
		}
		return 0;
	}
	of_node_put(node);
	MD_PRINT("%s: Can't find chosen node\n", __func__);

	return -1;
}
#endif

static int debug_register_init(void)
{
#ifdef CONFIG_MTK_AEE_IPANIC
	struct mrdump_params mparams = {};

	micro_mrdump_parse_chosen(&mparams);
	gmcb = ioremap_wc(mparams.cb_addr, mparams.cb_size);
	if (gmcb == NULL)
		MD_PRINT("%s gmcb init failed\n", __func__);
#endif

	g_exp_ctrl.print_func = print_to_console;

	MD_PRINT("debug_register_init microdump  init\n");
	register_die_notifier(&g_die_blk);
	atomic_notifier_chain_register(&panic_notifier_list, &g_panic_blk);

	return 0;
}

static int __init microdump_init(void)
{
	debug_register_init();
	common_symbol_init();
	return 0;
}

#ifdef CONFIG_HN_MICRODUMP_GKI
module_init(microdump_init);
MODULE_IMPORT_NS(MINIDUMP);
#else
late_initcall(debug_register_init);
#endif
MODULE_DESCRIPTION("kernel micro dump for honor");
MODULE_LICENSE("GPL v2");
