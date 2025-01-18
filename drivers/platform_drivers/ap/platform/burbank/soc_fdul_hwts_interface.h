#ifndef __SOC_FDUL_HWTS_INTERFACE_H__
#define __SOC_FDUL_HWTS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_HWTS_HWTS_BUSY_ADDR(base) ((base) + (0x0000UL))
#define SOC_FDUL_HWTS_HWTS_CLK_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_FDUL_HWTS_HWTS_RST_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_ADDR(base) ((base) + (0x0018UL))
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_ADDR(base) ((base) + (0x0020UL))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_ADDR(base) ((base) + (0x0030UL))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_ADDR(base) ((base) + (0x0038UL))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_ADDR(base) ((base) + (0x0040UL))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_ADDR(base) ((base) + (0x0048UL))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_ADDR(base) ((base) + (0x0050UL))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_ADDR(base) ((base) + (0x0058UL))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_LO_ADDR(base) ((base) + (0x0060UL))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_HI_ADDR(base) ((base) + (0x0064UL))
#define SOC_FDUL_HWTS_HWTS_BYPASS_ADDR(base) ((base) + (0x0068UL))
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_ADDR(base) ((base) + (0x0070UL))
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_LO_DFX_ADDR(base) ((base) + (0x0078UL))
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_HI_DFX_ADDR(base) ((base) + (0x007cUL))
#define SOC_FDUL_HWTS_HWTS_SQBASE_LO_ADDR(base,n) ((base) + (0x0100+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQBASE_HI_ADDR(base,n) ((base) + (0x0104+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQBASE_LO_ADDR(base,n) ((base) + (0x0108+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQBASE_HI_ADDR(base,n) ((base) + (0x010c+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_CTRL_ADDR(base,n) ((base) + (0x0110+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_CTRL_ADDR(base,n) ((base) + (0x0118+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_STATUS_ADDR(base,n) ((base) + (0x0120+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_ADDR(base,n) ((base) + (0x0128+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_DB_ADDR(base,n) ((base) + (0x0130+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_DB_ADDR(base,n) ((base) + (0x0138+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_ADDR(base,n) ((base) + (0x0140+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_ADDR(base,n) ((base) + (0x0148+0x80*(n)))
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_ADDR(base) ((base) + (0x0200UL))
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_HI_ADDR(base) ((base) + (0x0204UL))
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_LO_ADDR(base) ((base) + (0x0210UL))
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_HI_ADDR(base) ((base) + (0x0214UL))
#define SOC_FDUL_HWTS_DFX_PROFILE_RPTR_CTRL_ADDR(base) ((base) + (0x0218UL))
#define SOC_FDUL_HWTS_DFX_PROFILE_WPTR_CTRL_ADDR(base) ((base) + (0x0220UL))
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_ADDR(base) ((base) + (0x0300UL))
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_HI_ADDR(base) ((base) + (0x0304UL))
#define SOC_FDUL_HWTS_DFX_PCT_BASE_LO_ADDR(base) ((base) + (0x0310UL))
#define SOC_FDUL_HWTS_DFX_PCT_BASE_HI_ADDR(base) ((base) + (0x0314UL))
#define SOC_FDUL_HWTS_DFX_PCT_RPTR_CTRL_ADDR(base) ((base) + (0x0318UL))
#define SOC_FDUL_HWTS_DFX_PCT_WPTR_CTRL_ADDR(base) ((base) + (0x0320UL))
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_ADDR(base) ((base) + (0x0400UL))
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_HI_ADDR(base) ((base) + (0x0404UL))
#define SOC_FDUL_HWTS_DFX_LOG_BASE_LO_ADDR(base) ((base) + (0x0410UL))
#define SOC_FDUL_HWTS_DFX_LOG_BASE_HI_ADDR(base) ((base) + (0x0414UL))
#define SOC_FDUL_HWTS_DFX_LOG_RPTR_CTRL_ADDR(base) ((base) + (0x0418UL))
#define SOC_FDUL_HWTS_DFX_LOG_WPTR_CTRL_ADDR(base) ((base) + (0x0420UL))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_LO_ADDR(base,n) ((base) + (0x0500+(n)*0x80UL))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_HI_ADDR(base,n) ((base) + (0x0504+(n)*0x80UL))
#define SOC_FDUL_HWTS_HWTS_HW_SEMA_ADDR(base) ((base) + (0x0600UL))
#define SOC_FDUL_HWTS_HWTS_GLB_SECURE_ADDR(base) ((base) + (0x1000UL))
#define SOC_FDUL_HWTS_HWTS_SQ_SECURE_ADDR(base,n) ((base) + (0x1010+(n)*0x8UL))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_ADDR(base) ((base) + (0x1030UL))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_ADDR(base) ((base) + (0x1038UL))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_ADDR(base) ((base) + (0x1040UL))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_ADDR(base) ((base) + (0x1048UL))
#define SOC_FDUL_HWTS_AIC_SECURE_SETTING_ADDR(base) ((base) + (0x1080UL))
#else
#define SOC_FDUL_HWTS_HWTS_BUSY_ADDR(base) ((base) + (0x0000))
#define SOC_FDUL_HWTS_HWTS_CLK_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_FDUL_HWTS_HWTS_RST_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_ADDR(base) ((base) + (0x0018))
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_ADDR(base) ((base) + (0x0020))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_ADDR(base) ((base) + (0x0030))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_ADDR(base) ((base) + (0x0038))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_ADDR(base) ((base) + (0x0040))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_ADDR(base) ((base) + (0x0048))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_ADDR(base) ((base) + (0x0050))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_ADDR(base) ((base) + (0x0058))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_LO_ADDR(base) ((base) + (0x0060))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_HI_ADDR(base) ((base) + (0x0064))
#define SOC_FDUL_HWTS_HWTS_BYPASS_ADDR(base) ((base) + (0x0068))
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_ADDR(base) ((base) + (0x0070))
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_LO_DFX_ADDR(base) ((base) + (0x0078))
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_HI_DFX_ADDR(base) ((base) + (0x007c))
#define SOC_FDUL_HWTS_HWTS_SQBASE_LO_ADDR(base,n) ((base) + (0x0100+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQBASE_HI_ADDR(base,n) ((base) + (0x0104+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQBASE_LO_ADDR(base,n) ((base) + (0x0108+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQBASE_HI_ADDR(base,n) ((base) + (0x010c+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_CTRL_ADDR(base,n) ((base) + (0x0110+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_CTRL_ADDR(base,n) ((base) + (0x0118+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_STATUS_ADDR(base,n) ((base) + (0x0120+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_ADDR(base,n) ((base) + (0x0128+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_SQ_DB_ADDR(base,n) ((base) + (0x0130+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_CQ_DB_ADDR(base,n) ((base) + (0x0138+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_ADDR(base,n) ((base) + (0x0140+0x80*(n)))
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_ADDR(base,n) ((base) + (0x0148+0x80*(n)))
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_ADDR(base) ((base) + (0x0200))
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_HI_ADDR(base) ((base) + (0x0204))
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_LO_ADDR(base) ((base) + (0x0210))
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_HI_ADDR(base) ((base) + (0x0214))
#define SOC_FDUL_HWTS_DFX_PROFILE_RPTR_CTRL_ADDR(base) ((base) + (0x0218))
#define SOC_FDUL_HWTS_DFX_PROFILE_WPTR_CTRL_ADDR(base) ((base) + (0x0220))
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_ADDR(base) ((base) + (0x0300))
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_HI_ADDR(base) ((base) + (0x0304))
#define SOC_FDUL_HWTS_DFX_PCT_BASE_LO_ADDR(base) ((base) + (0x0310))
#define SOC_FDUL_HWTS_DFX_PCT_BASE_HI_ADDR(base) ((base) + (0x0314))
#define SOC_FDUL_HWTS_DFX_PCT_RPTR_CTRL_ADDR(base) ((base) + (0x0318))
#define SOC_FDUL_HWTS_DFX_PCT_WPTR_CTRL_ADDR(base) ((base) + (0x0320))
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_ADDR(base) ((base) + (0x0400))
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_HI_ADDR(base) ((base) + (0x0404))
#define SOC_FDUL_HWTS_DFX_LOG_BASE_LO_ADDR(base) ((base) + (0x0410))
#define SOC_FDUL_HWTS_DFX_LOG_BASE_HI_ADDR(base) ((base) + (0x0414))
#define SOC_FDUL_HWTS_DFX_LOG_RPTR_CTRL_ADDR(base) ((base) + (0x0418))
#define SOC_FDUL_HWTS_DFX_LOG_WPTR_CTRL_ADDR(base) ((base) + (0x0420))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_LO_ADDR(base,n) ((base) + (0x0500+(n)*0x80))
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_HI_ADDR(base,n) ((base) + (0x0504+(n)*0x80))
#define SOC_FDUL_HWTS_HWTS_HW_SEMA_ADDR(base) ((base) + (0x0600))
#define SOC_FDUL_HWTS_HWTS_GLB_SECURE_ADDR(base) ((base) + (0x1000))
#define SOC_FDUL_HWTS_HWTS_SQ_SECURE_ADDR(base,n) ((base) + (0x1010+(n)*0x8))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_ADDR(base) ((base) + (0x1030))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_ADDR(base) ((base) + (0x1038))
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_ADDR(base) ((base) + (0x1040))
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_ADDR(base) ((base) + (0x1048))
#define SOC_FDUL_HWTS_AIC_SECURE_SETTING_ADDR(base) ((base) + (0x1080))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hwts_busy : 1;
        unsigned int reserved_0 : 7;
        unsigned int curr_sq_idx : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FDUL_HWTS_HWTS_BUSY_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_BUSY_hwts_busy_START (0)
#define SOC_FDUL_HWTS_HWTS_BUSY_hwts_busy_END (0)
#define SOC_FDUL_HWTS_HWTS_BUSY_curr_sq_idx_START (8)
#define SOC_FDUL_HWTS_HWTS_BUSY_curr_sq_idx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_clk_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_HWTS_CLK_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CLK_CTRL_aic_clk_en_START (0)
#define SOC_FDUL_HWTS_HWTS_CLK_CTRL_aic_clk_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_hw_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_HWTS_RST_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_RST_CTRL_aic_hw_rst_START (0)
#define SOC_FDUL_HWTS_HWTS_RST_CTRL_aic_hw_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hwts_bypass : 1;
        unsigned int hwts_fastpath_en : 1;
        unsigned int hwts_force_icache_invalidate : 1;
        unsigned int hwts_skip_reset : 1;
        unsigned int hwts_disable_icache_invalidate : 1;
        unsigned int reserved_0 : 3;
        unsigned int sq_priority : 1;
        unsigned int reserved_1 : 7;
        unsigned int syscnt_gray : 1;
        unsigned int reserved_2 : 7;
        unsigned int reset_dly_cnt : 8;
    } reg;
} SOC_FDUL_HWTS_HWTS_GLB_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_bypass_START (0)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_bypass_END (0)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_fastpath_en_START (1)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_fastpath_en_END (1)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_force_icache_invalidate_START (2)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_force_icache_invalidate_END (2)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_skip_reset_START (3)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_skip_reset_END (3)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_disable_icache_invalidate_START (4)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_hwts_disable_icache_invalidate_END (4)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_sq_priority_START (8)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_sq_priority_END (8)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_syscnt_gray_START (16)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_syscnt_gray_END (16)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_reset_dly_cnt_START (24)
#define SOC_FDUL_HWTS_HWTS_GLB_CTRL_reset_dly_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_pause : 1;
        unsigned int task_pause : 1;
        unsigned int task_kill : 1;
        unsigned int reserved_0 : 13;
        unsigned int debug_resume : 1;
        unsigned int task_resume : 1;
        unsigned int exception_handled : 1;
        unsigned int task_terminate : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_FDUL_HWTS_HWTS_TASK_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_debug_pause_START (0)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_debug_pause_END (0)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_pause_START (1)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_pause_END (1)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_kill_START (2)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_kill_END (2)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_debug_resume_START (16)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_debug_resume_END (16)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_resume_START (17)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_resume_END (17)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_exception_handled_START (18)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_exception_handled_END (18)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_terminate_START (19)
#define SOC_FDUL_HWTS_HWTS_TASK_CTRL_task_terminate_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_done : 1;
        unsigned int sqe_pre_paused : 1;
        unsigned int sqe_post_paused : 1;
        unsigned int cq_full : 1;
        unsigned int task_paused : 1;
        unsigned int reserved_0 : 3;
        unsigned int aic_debug : 1;
        unsigned int debug_paused : 1;
        unsigned int reserved_1 : 6;
        unsigned int profile_almost_full : 1;
        unsigned int pc_trace_almost_full : 1;
        unsigned int hwts_log_almost_full : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_FDUL_HWTS_HWTS_INTERRUPT_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_aic_done_START (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_aic_done_END (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_sqe_pre_paused_START (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_sqe_pre_paused_END (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_sqe_post_paused_START (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_sqe_post_paused_END (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_cq_full_START (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_cq_full_END (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_task_paused_START (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_task_paused_END (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_aic_debug_START (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_aic_debug_END (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_debug_paused_START (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_debug_paused_END (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_profile_almost_full_START (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_profile_almost_full_END (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_pc_trace_almost_full_START (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_pc_trace_almost_full_END (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_hwts_log_almost_full_START (18)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_hwts_log_almost_full_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_error : 1;
        unsigned int task_timeout : 1;
        unsigned int bus_error : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_aic_error_START (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_aic_error_END (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_task_timeout_START (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_task_timeout_END (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_bus_error_START (2)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_bus_error_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_done_mask : 1;
        unsigned int sqe_pre_paused_mask : 1;
        unsigned int sqe_post_paused_mask : 1;
        unsigned int cq_full_mask : 1;
        unsigned int task_paused_mask : 1;
        unsigned int reserved_0 : 3;
        unsigned int aic_debug_mask : 1;
        unsigned int debug_paused_mask : 1;
        unsigned int reserved_1 : 6;
        unsigned int profile_almost_full_mask : 1;
        unsigned int pc_trace_almost_full_mask : 1;
        unsigned int hwts_log_almost_full_mask : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_aic_done_mask_START (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_aic_done_mask_END (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_sqe_pre_paused_mask_START (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_sqe_pre_paused_mask_END (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_sqe_post_paused_mask_START (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_sqe_post_paused_mask_END (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_cq_full_mask_START (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_cq_full_mask_END (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_task_paused_mask_START (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_task_paused_mask_END (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_aic_debug_mask_START (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_aic_debug_mask_END (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_debug_paused_mask_START (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_debug_paused_mask_END (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_profile_almost_full_mask_START (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_profile_almost_full_mask_END (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_pc_trace_almost_full_mask_START (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_pc_trace_almost_full_mask_END (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_hwts_log_almost_full_mask_START (18)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_MASK_hwts_log_almost_full_mask_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_error_mask : 1;
        unsigned int task_timeout_mask : 1;
        unsigned int bus_error_mask : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_aic_error_mask_START (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_aic_error_mask_END (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_task_timeout_mask_START (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_task_timeout_mask_END (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_bus_error_mask_START (2)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_MASK_bus_error_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_done_force : 1;
        unsigned int sqe_pre_paused_force : 1;
        unsigned int sqe_post_paused_force : 1;
        unsigned int cq_full_force : 1;
        unsigned int task_paused_force : 1;
        unsigned int reserved_0 : 3;
        unsigned int aic_debug_force : 1;
        unsigned int debug_paused_force : 1;
        unsigned int reserved_1 : 6;
        unsigned int profile_almost_full_force : 1;
        unsigned int pc_trace_almost_full_force : 1;
        unsigned int hwts_log_almost_full_force : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_aic_done_force_START (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_aic_done_force_END (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_sqe_pre_paused_force_START (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_sqe_pre_paused_force_END (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_sqe_post_paused_force_START (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_sqe_post_paused_force_END (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_cq_full_force_START (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_cq_full_force_END (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_task_paused_force_START (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_task_paused_force_END (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_aic_debug_force_START (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_aic_debug_force_END (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_debug_paused_force_START (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_debug_paused_force_END (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_profile_almost_full_force_START (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_profile_almost_full_force_END (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_pc_trace_almost_full_force_START (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_pc_trace_almost_full_force_END (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_hwts_log_almost_full_force_START (18)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_FORCE_hwts_log_almost_full_force_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_error_force : 1;
        unsigned int task_timeout_force : 1;
        unsigned int bus_error_force : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_aic_error_force_START (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_aic_error_force_END (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_task_timeout_force_START (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_task_timeout_force_END (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_bus_error_force_START (2)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_FORCE_bus_error_force_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_timeout_threshold_lo : 32;
    } reg;
} SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_LO_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_LO_task_timeout_threshold_lo_START (0)
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_LO_task_timeout_threshold_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_timeout_threshold_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_HI_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_HI_task_timeout_threshold_hi_START (0)
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_HI_task_timeout_threshold_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_code : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_HWTS_BYPASS_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_BYPASS_bypass_code_START (0)
#define SOC_FDUL_HWTS_HWTS_BYPASS_bypass_code_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_mode_done_latched : 1;
        unsigned int dbg_mode_exception_latched : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_dbg_mode_done_latched_START (0)
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_dbg_mode_done_latched_END (0)
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_dbg_mode_exception_latched_START (1)
#define SOC_FDUL_HWTS_HWTS_MAIN_FSM_DFX_dbg_mode_exception_latched_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bus_err_addr_lo : 32;
    } reg;
} SOC_FDUL_HWTS_HWTS_BUS_ERROR_LO_DFX_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_LO_DFX_bus_err_addr_lo_START (0)
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_LO_DFX_bus_err_addr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bus_err_addr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_HWTS_BUS_ERROR_HI_DFX_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_HI_DFX_bus_err_addr_hi_START (0)
#define SOC_FDUL_HWTS_HWTS_BUS_ERROR_HI_DFX_bus_err_addr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_base_addr_lo : 32;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQBASE_LO_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQBASE_LO_sq_base_addr_lo_START (0)
#define SOC_FDUL_HWTS_HWTS_SQBASE_LO_sq_base_addr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_base_addr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQBASE_HI_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQBASE_HI_sq_base_addr_hi_START (0)
#define SOC_FDUL_HWTS_HWTS_SQBASE_HI_sq_base_addr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_base_addr_lo : 32;
    } reg;
} SOC_FDUL_HWTS_HWTS_CQBASE_LO_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CQBASE_LO_cq_base_addr_lo_START (0)
#define SOC_FDUL_HWTS_HWTS_CQBASE_LO_cq_base_addr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_base_addr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_HWTS_CQBASE_HI_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CQBASE_HI_cq_base_addr_hi_START (0)
#define SOC_FDUL_HWTS_HWTS_CQBASE_HI_cq_base_addr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_length : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQ_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQ_CTRL_sq_length_START (0)
#define SOC_FDUL_HWTS_HWTS_SQ_CTRL_sq_length_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_length : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_FDUL_HWTS_HWTS_CQ_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CQ_CTRL_cq_length_START (0)
#define SOC_FDUL_HWTS_HWTS_CQ_CTRL_cq_length_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_head : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQ_STATUS_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQ_STATUS_sq_head_START (0)
#define SOC_FDUL_HWTS_HWTS_SQ_STATUS_sq_head_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_tail : 12;
        unsigned int reserved_0: 4;
        unsigned int phase_bit : 1;
        unsigned int reserved_1: 15;
    } reg;
} SOC_FDUL_HWTS_HWTS_CQ_STATUS_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_cq_tail_START (0)
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_cq_tail_END (11)
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_phase_bit_START (16)
#define SOC_FDUL_HWTS_HWTS_CQ_STATUS_phase_bit_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_tail : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQ_DB_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQ_DB_sq_tail_START (0)
#define SOC_FDUL_HWTS_HWTS_SQ_DB_sq_tail_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_head : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FDUL_HWTS_HWTS_CQ_DB_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_CQ_DB_cq_head_START (0)
#define SOC_FDUL_HWTS_HWTS_CQ_DB_cq_head_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_cq_reset : 1;
        unsigned int prefetch_clear : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_HWTS_HWTS_DB_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_sq_cq_reset_START (0)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_sq_cq_reset_END (0)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_prefetch_clear_START (1)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_prefetch_clear_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_cq_reset_latched : 1;
        unsigned int prefetch_clear_latched : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_sq_cq_reset_latched_START (0)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_sq_cq_reset_latched_END (0)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_prefetch_clear_latched_START (1)
#define SOC_FDUL_HWTS_HWTS_DB_CTRL_DFX_prefetch_clear_latched_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_en : 1;
        unsigned int reserved : 15;
        unsigned int profile_buf_len : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_profile_en_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_profile_en_END (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_profile_buf_len_START (16)
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_LO_profile_buf_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_af_threshold : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_CTRL_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_HI_profile_af_threshold_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_CTRL_HI_profile_af_threshold_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_base_lo : 32;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_BASE_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_LO_profile_base_lo_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_LO_profile_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_base_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_BASE_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_HI_profile_base_hi_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_BASE_HI_profile_base_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_rd_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_RPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_RPTR_CTRL_profile_rd_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_RPTR_CTRL_profile_rd_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_wr_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PROFILE_WPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PROFILE_WPTR_CTRL_profile_wr_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_PROFILE_WPTR_CTRL_profile_wr_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_en : 1;
        unsigned int reserved : 15;
        unsigned int pct_buf_len : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_pct_en_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_pct_en_END (0)
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_pct_buf_len_START (16)
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_LO_pct_buf_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_af_threshold : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_CTRL_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_HI_pct_af_threshold_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_CTRL_HI_pct_af_threshold_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_base_lo : 32;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_BASE_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_BASE_LO_pct_base_lo_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_BASE_LO_pct_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_base_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_BASE_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_BASE_HI_pct_base_hi_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_BASE_HI_pct_base_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_rd_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_RPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_RPTR_CTRL_pct_rd_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_RPTR_CTRL_pct_rd_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pct_wr_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_PCT_WPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_PCT_WPTR_CTRL_pct_wr_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_PCT_WPTR_CTRL_pct_wr_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_en : 1;
        unsigned int log_per_block_timestamp : 1;
        unsigned int log_per_block_pmu_cnt : 1;
        unsigned int reserved : 13;
        unsigned int log_buf_len : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_en_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_en_END (0)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_per_block_timestamp_START (1)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_per_block_timestamp_END (1)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_per_block_pmu_cnt_START (2)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_per_block_pmu_cnt_END (2)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_buf_len_START (16)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_LO_log_buf_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_af_threshold : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_CTRL_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_HI_log_af_threshold_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_CTRL_HI_log_af_threshold_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_base_lo : 32;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_BASE_LO_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_BASE_LO_log_base_lo_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_BASE_LO_log_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_base_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_BASE_HI_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_BASE_HI_log_base_hi_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_BASE_HI_log_base_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_rd_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_RPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_RPTR_CTRL_log_rd_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_RPTR_CTRL_log_rd_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log_wr_ptr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_HWTS_DFX_LOG_WPTR_CTRL_UNION;
#endif
#define SOC_FDUL_HWTS_DFX_LOG_WPTR_CTRL_log_wr_ptr_START (0)
#define SOC_FDUL_HWTS_DFX_LOG_WPTR_CTRL_log_wr_ptr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_timeout_cnt_lo : 32;
    } reg;
} SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_LO_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_LO_task_timeout_cnt_lo_START (0)
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_LO_task_timeout_cnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_timeout_cnt_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_HI_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_HI_task_timeout_cnt_hi_START (0)
#define SOC_FDUL_HWTS_HWTS_TASK_TIMEOUT_CNT_HI_task_timeout_cnt_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_sema : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_HWTS_HW_SEMA_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_HW_SEMA_hw_sema_START (0)
#define SOC_FDUL_HWTS_HWTS_HW_SEMA_hw_sema_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure_clear_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_HWTS_GLB_SECURE_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_GLB_SECURE_secure_clear_bypass_START (0)
#define SOC_FDUL_HWTS_HWTS_GLB_SECURE_secure_clear_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_secure_state : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_HWTS_SQ_SECURE_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_SQ_SECURE_sq_secure_state_START (0)
#define SOC_FDUL_HWTS_HWTS_SQ_SECURE_sq_secure_state_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_done_sec : 1;
        unsigned int sqe_pre_paused_sec : 1;
        unsigned int sqe_post_paused_sec : 1;
        unsigned int cq_full_sec : 1;
        unsigned int task_paused_sec : 1;
        unsigned int reserved_0 : 3;
        unsigned int aic_debug_sec : 1;
        unsigned int debug_paused_sec : 1;
        unsigned int reserved_1 : 6;
        unsigned int profile_almost_full_sec : 1;
        unsigned int pc_trace_almost_full_sec : 1;
        unsigned int hwts_log_almost_full_sec : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_aic_done_sec_START (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_aic_done_sec_END (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_sqe_pre_paused_sec_START (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_sqe_pre_paused_sec_END (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_sqe_post_paused_sec_START (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_sqe_post_paused_sec_END (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_cq_full_sec_START (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_cq_full_sec_END (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_task_paused_sec_START (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_task_paused_sec_END (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_aic_debug_sec_START (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_aic_debug_sec_END (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_debug_paused_sec_START (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_debug_paused_sec_END (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_profile_almost_full_sec_START (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_profile_almost_full_sec_END (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_pc_trace_almost_full_sec_START (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_pc_trace_almost_full_sec_END (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_hwts_log_almost_full_sec_START (18)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_hwts_log_almost_full_sec_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_error_sec : 1;
        unsigned int task_timeout_sec : 1;
        unsigned int bus_error_sec : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_aic_error_sec_START (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_aic_error_sec_END (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_task_timeout_sec_START (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_task_timeout_sec_END (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_bus_error_sec_START (2)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_bus_error_sec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_done_sec_mask : 1;
        unsigned int sqe_pre_paused_sec_mask : 1;
        unsigned int sqe_post_paused_sec_mask : 1;
        unsigned int cq_full_sec_mask : 1;
        unsigned int task_paused_sec_mask : 1;
        unsigned int reserved_0 : 3;
        unsigned int aic_debug_sec_mask : 1;
        unsigned int debug_paused_sec_mask : 1;
        unsigned int reserved_1 : 6;
        unsigned int profile_almost_full_sec_mask : 1;
        unsigned int pc_trace_almost_full_sec_mask : 1;
        unsigned int hwts_log_almost_full_sec_mask : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_aic_done_sec_mask_START (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_aic_done_sec_mask_END (0)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_sqe_pre_paused_sec_mask_START (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_sqe_pre_paused_sec_mask_END (1)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_sqe_post_paused_sec_mask_START (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_sqe_post_paused_sec_mask_END (2)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_cq_full_sec_mask_START (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_cq_full_sec_mask_END (3)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_task_paused_sec_mask_START (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_task_paused_sec_mask_END (4)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_aic_debug_sec_mask_START (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_aic_debug_sec_mask_END (8)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_debug_paused_sec_mask_START (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_debug_paused_sec_mask_END (9)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_profile_almost_full_sec_mask_START (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_profile_almost_full_sec_mask_END (16)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_pc_trace_almost_full_sec_mask_START (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_pc_trace_almost_full_sec_mask_END (17)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_hwts_log_almost_full_sec_mask_START (18)
#define SOC_FDUL_HWTS_HWTS_INTERRUPT_SEC_MASK_hwts_log_almost_full_sec_mask_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_error_sec_mask : 1;
        unsigned int task_timeout_sec_mask : 1;
        unsigned int bus_error_sec_mask : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_UNION;
#endif
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_aic_error_sec_mask_START (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_aic_error_sec_mask_END (0)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_task_timeout_sec_mask_START (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_task_timeout_sec_mask_END (1)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_bus_error_sec_mask_START (2)
#define SOC_FDUL_HWTS_HWTS_ERROR_INTERRUPT_SEC_MASK_bus_error_sec_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_AIC_SECURE_SETTING_UNION;
#endif
#define SOC_FDUL_HWTS_AIC_SECURE_SETTING_aic_sec_en_START (0)
#define SOC_FDUL_HWTS_AIC_SECURE_SETTING_aic_sec_en_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
