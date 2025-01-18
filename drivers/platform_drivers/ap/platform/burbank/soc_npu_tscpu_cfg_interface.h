#ifndef __SOC_NPU_TSCPU_CFG_INTERFACE_H__
#define __SOC_NPU_TSCPU_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_ADDR(base) ((base) + (0x100UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL1_ADDR(base) ((base) + (0x104UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ADDR(base) ((base) + (0x108UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_ADDR(base) ((base) + (0x10CUL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL4_ADDR(base) ((base) + (0x110UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_ADDR(base) ((base) + (0x114UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL6_ADDR(base) ((base) + (0x118UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL7_ADDR(base) ((base) + (0x11CUL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL8_ADDR(base) ((base) + (0x120UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL9_ADDR(base) ((base) + (0x124UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT5_ADDR(base) ((base) + (0x214UL))
#else
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_ADDR(base) ((base) + (0x100))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL1_ADDR(base) ((base) + (0x104))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ADDR(base) ((base) + (0x108))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_ADDR(base) ((base) + (0x10C))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL4_ADDR(base) ((base) + (0x110))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_ADDR(base) ((base) + (0x114))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL6_ADDR(base) ((base) + (0x118))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL7_ADDR(base) ((base) + (0x11C))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL8_ADDR(base) ((base) + (0x120))
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL9_ADDR(base) ((base) + (0x124))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT5_ADDR(base) ((base) + (0x214))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aa64naa32 : 1;
        unsigned int vinithi : 1;
        unsigned int ananke_stretch_l2ramclk_en : 1;
        unsigned int wdog_halt_en : 1;
        unsigned int timer_halt_en : 1;
        unsigned int reserved : 19;
        unsigned int rvbaraddr_high : 8;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_aa64naa32_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_aa64naa32_END (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_vinithi_START (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_vinithi_END (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_ananke_stretch_l2ramclk_en_START (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_ananke_stretch_l2ramclk_en_END (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_wdog_halt_en_START (3)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_wdog_halt_en_END (3)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_timer_halt_en_START (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_timer_halt_en_END (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_rvbaraddr_high_START (24)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL0_rvbaraddr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int rvbaraddr : 30;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL1_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL1_rvbaraddr_START (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL1_rvbaraddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke_core_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int ananke_core_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int ananke_core_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int ananke_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_normal_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_normal_END (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_sd_START (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_sd_END (6)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_dslp_START (8)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_dslp_END (10)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_slp_START (12)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL2_ananke_core_mem_ctl_slp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core1_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core1_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core1_mem_ctrl_from_sys : 3;
        unsigned int core1_p_channel_enable : 1;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_p_channel_init_pstate_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_p_channel_init_pstate_END (5)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_pstate_from_sys_START (16)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_pstate_from_sys_END (21)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_preq_from_sys_START (24)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_preq_from_sys_END (24)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_mem_ctrl_from_sys_START (28)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_mem_ctrl_from_sys_END (30)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_p_channel_enable_START (31)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL3_core1_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_pchannel_wait_cycle_DSLP : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL4_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL4_core1_pchannel_wait_cycle_DSLP_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL4_core1_pchannel_wait_cycle_DSLP_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hc_mem_adjust : 12;
        unsigned int hd_mem_adjust : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_hc_mem_adjust_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_hc_mem_adjust_END (11)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_hd_mem_adjust_START (12)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL5_hd_mem_adjust_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_mem_adjust : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL6_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL6_tp_mem_adjust_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_CTRL6_tp_mem_adjust_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_CTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int custom_wfi : 1;
        unsigned int custom_wfe : 1;
        unsigned int dbgack : 1;
        unsigned int coreinstrrun : 1;
        unsigned int coreinstrret : 1;
        unsigned int core_idle : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_custom_wfi_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_custom_wfi_END (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_custom_wfe_START (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_custom_wfe_END (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_dbgack_START (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_dbgack_END (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_coreinstrrun_START (3)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_coreinstrrun_END (3)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_coreinstrret_START (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_coreinstrret_END (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_core_idle_START (5)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT0_core_idle_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 6;
        unsigned int reserved_1 : 2;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_paccept_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_paccept_END (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pdeny_START (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pdeny_END (1)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_preq_START (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_preq_END (2)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pstate_START (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pstate_END (9)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pactive_START (12)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT1_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state_fsm : 4;
        unsigned int core_pstate_fsm : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_current_state_fsm_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_current_state_fsm_END (3)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_core_pstate_fsm_START (4)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT2_core_pstate_fsm_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int core_paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int core_pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_UNION;
#endif
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_pactive_to_sys_START (0)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_pactive_to_sys_END (17)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_paccept_to_sys_START (20)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_paccept_to_sys_END (20)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_pdeny_to_sys_START (24)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_pdeny_to_sys_END (24)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_can_pd_START (28)
#define SOC_NPU_TSCPU_CFG_TS_CPU_STAT3_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TSCPU_CFG_TS_CPU_STAT5_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
