#include "rainbow.h"

#include <linux/bug.h>
#include <linux/oom.h>
#include <linux/rainbow_reason.h>

#include <asm/esr.h>
#include <asm/ptrace.h>

#include <trace/hooks/fault.h>
#include <trace/hooks/traps.h>
#include <trace/hooks/bug.h>
#include <trace/hooks/mm.h>
#include <trace/hooks/sysrqcrash.h>

static const char * esr_fault_info[] = {
    "ttbr address size fault",
    "level 1 address size fault",
    "level 2 address size fault",
    "level 3 address size fault",
    "level 0 translation fault",
    "level 1 translation fault",
    "level 2 translation fault",
    "level 3 translation fault",
    "unknown 8",
    "level 1 access flag fault",
    "level 2 access flag fault",
    "level 3 access flag fault",
    "unknown 12",
    "level 1 permission fault",
    "level 2 permission fault",
    "level 3 permission fault",
    "synchronous external abort",
    "synchronous tag check fault",
    "unknown 18",
    "unknown 19",
    "level 0 (translation table walk)",
    "level 1 (translation table walk)",
    "level 2 (translation table walk)",
    "level 3 (translation table walk)",
    "synchronous parity or ECC error",
    "unknown 25",
    "unknown 26",
    "unknown 27",
    "level 0 synchronous parity error (translation table walk)",
    "level 1 synchronous parity error (translation table walk)",
    "level 2 synchronous parity error (translation table walk)",
    "level 3 synchronous parity error (translation table walk)",
    "unknown 32",
    "alignment fault",
    "unknown 34",
    "unknown 35",
    "unknown 36",
    "unknown 37",
    "unknown 38",
    "unknown 39",
    "unknown 40",
    "unknown 41",
    "unknown 42",
    "unknown 43",
    "unknown 44",
    "unknown 45",
    "unknown 46",
    "unknown 47",
    "TLB conflict abort",
    "Unsupported atomic hardware update fault",
    "unknown 50",
    "unknown 51",
    "implementation fault (lockdown abort)",
    "implementation fault (unsupported exclusive)",
    "unknown 54",
    "unknown 55",
    "unknown 56",
    "unknown 57",
    "unknown 58",
    "unknown 59",
    "unknown 60",
    "section domain fault",
    "page domain fault",
    "unknown 63"
};

static inline const char * rb_esr_to_fault_info(unsigned int esr)
{
    return esr_fault_info[esr & ESR_ELx_FSC];
}

void rb_handle_die_kernel_fault(void *unused, const char *msg, unsigned long addr,
                                unsigned int esr, struct pt_regs *regs)
{
    if (msg != NULL) {
        rb_sreason_set("%s", msg);
        return;
    }
    rb_sreason_set("unknown_addr");
}

void rb_handle_do_sea(void *unused, unsigned long far,
                      unsigned int esr, struct pt_regs *regs)
{
    rb_sreason_set("SEA");
}

void rb_handle_do_mem_abort(void *unused, unsigned long far,
                            unsigned int esr, struct pt_regs *regs)
{
    const char * info_name;
    if (!user_mode(regs)) {
        info_name = rb_esr_to_fault_info(esr);
        rb_sreason_set("unhandle_fault");
        rb_attach_info_set("Unhandled_fault_%s", info_name);
    }
}

void rb_handle_do_sp_pc_abort(void *unused, unsigned long addr,
                              unsigned int esr, struct pt_regs *regs)
{
    if (!user_mode(regs)) {
        rb_sreason_set("sp_pc_abort");
    }
}

void rb_handle_do_undefinstr(void *unused, struct pt_regs *regs)
{
    if (!user_mode(regs)) {
        rb_sreason_set("undefine_cmd");
        BUG_ON(1);
    }
}

void rb_handle_do_ptrauth_fault(void *unused, struct pt_regs *regs, unsigned int esr)
{
    if (!user_mode(regs)) {
        rb_sreason_set("ptrauth_fault");
        BUG_ON(1);
    }
}

void rb_handle_arm64_serror_panic(void *unused, struct pt_regs *regs, u32 esr)
{
    rb_sreason_set("serror");
}

void rb_handle_report_bug(void *unused, const char *file, unsigned int line, unsigned long bugaddr)
{
    if (file) {
        rb_sreason_set("bug");
        rb_attach_info_set("BUG at %s:%u!", file, line);
    } else {
        rb_sreason_set("bug");
        rb_attach_info_set("BUG unavailable at %p!", (void *)bugaddr);
    }
}

void rb_handle_out_of_memory(void *unused, struct oom_control *oc, int *ret)
{
    if (oc->order == -1) {
        return;
    }

    if (oc->memcg != NULL) {
        return;
    }

    rb_sreason_set("deadlocked_mem");
}

void rb_handle_android_vh_sysrq_crash(void *unused, void *data)
{
    rb_sreason_set("sysrq_crash");
}

void rb_register_vh(void) {
    register_trace_android_rvh_die_kernel_fault(rb_handle_die_kernel_fault, NULL);
    register_trace_android_rvh_do_sea(rb_handle_do_sea, NULL);
    register_trace_android_rvh_do_mem_abort(rb_handle_do_mem_abort, NULL);
    register_trace_android_rvh_do_sp_pc_abort(rb_handle_do_sp_pc_abort, NULL);
    register_trace_android_rvh_do_undefinstr(rb_handle_do_undefinstr, NULL);
    register_trace_android_rvh_do_ptrauth_fault(rb_handle_do_ptrauth_fault, NULL);
    register_trace_android_rvh_arm64_serror_panic(rb_handle_arm64_serror_panic, NULL);
    register_trace_android_rvh_report_bug(rb_handle_report_bug, NULL);
    register_trace_android_vh_sysrq_crash(rb_handle_android_vh_sysrq_crash, NULL);
}
