#ifndef __SOC_DP_MONITOR_INTERFACE_H__
#define __SOC_DP_MONITOR_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DP_MONITOR_DPM_CTRL_EN_ADDR(base) ((base) + (0x000UL))
#define SOC_DP_MONITOR_SDPM_ENABLE_ADDR(base) ((base) + (0x004UL))
#define SOC_DP_MONITOR_SG_DDPM_EN_ADDR(base) ((base) + (0x008UL))
#define SOC_DP_MONITOR_DPM_ENABLE_ADDR(base) ((base) + (0x00CUL))
#define SOC_DP_MONITOR_SHIFT_BIT_ADDR(base) ((base) + (0x010UL))
#define SOC_DP_MONITOR_VOLT_ADDR(base) ((base) + (0x014UL))
#define SOC_DP_MONITOR_DVFS_CFG_APB_ADDR(base) ((base) + (0x018UL))
#define SOC_DP_MONITOR_SOFT_PULSE_ADDR(base) ((base) + (0x01CUL))
#define SOC_DP_MONITOR_VOLT_GEAR_ADDR(base,VOLT_GEAR) ((base) + (0x020+0x4*(VOLT_GEAR)))
#define SOC_DP_MONITOR_STA_VOLT_PARAM_ADDR(base,FX1_NUM) ((base) + (0x040+0x4*(FX1_NUM)))
#define SOC_DP_MONITOR_FX2_CONST_ADDR(base,FX2_VAR_NUM) ((base) + (0x080+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_FX2_VAR1_ADDR(base,FX2_VAR_NUM) ((base) + (0x0A0+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_FX2_VAR2_ADDR(base,FX2_VAR_NUM) ((base) + (0x0C0+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_SIG_POWER_PARAM_ADDR(base,P_NUM) ((base) + (0x0E0+0x4*(P_NUM)))
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_ADDR(base,DPM_NUM) ((base) + (0x260+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_FX2_RESULT_SNAP_ADDR(base,DPM_NUM) ((base) + (0x2B0+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_FINAL_STA_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x300+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_ACC_DPM_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x340+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_ACC_DYN_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x380+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_DPM_COUNTER_PMU_ADDR(base,DPM_NUM,PMU_CNT) ((base) + (0x3C0+0x4*(PMU_CNT)+0x60*(DPM_NUM)))
#define SOC_DP_MONITOR_DPM_COUNTER_ICG_ADDR(base,DPM_NUM,ICG_CNT) ((base) + (0x9C0+0x4*(ICG_CNT)+0xA0*(DPM_NUM)))
#define SOC_DP_MONITOR_ICG_READ_READY_APB_ADDR(base,DPM_NUM) ((base) + (0x13C0+0x4*(DPM_NUM)))
#else
#define SOC_DP_MONITOR_DPM_CTRL_EN_ADDR(base) ((base) + (0x000))
#define SOC_DP_MONITOR_SDPM_ENABLE_ADDR(base) ((base) + (0x004))
#define SOC_DP_MONITOR_SG_DDPM_EN_ADDR(base) ((base) + (0x008))
#define SOC_DP_MONITOR_DPM_ENABLE_ADDR(base) ((base) + (0x00C))
#define SOC_DP_MONITOR_SHIFT_BIT_ADDR(base) ((base) + (0x010))
#define SOC_DP_MONITOR_VOLT_ADDR(base) ((base) + (0x014))
#define SOC_DP_MONITOR_DVFS_CFG_APB_ADDR(base) ((base) + (0x018))
#define SOC_DP_MONITOR_SOFT_PULSE_ADDR(base) ((base) + (0x01C))
#define SOC_DP_MONITOR_VOLT_GEAR_ADDR(base,VOLT_GEAR) ((base) + (0x020+0x4*(VOLT_GEAR)))
#define SOC_DP_MONITOR_STA_VOLT_PARAM_ADDR(base,FX1_NUM) ((base) + (0x040+0x4*(FX1_NUM)))
#define SOC_DP_MONITOR_FX2_CONST_ADDR(base,FX2_VAR_NUM) ((base) + (0x080+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_FX2_VAR1_ADDR(base,FX2_VAR_NUM) ((base) + (0x0A0+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_FX2_VAR2_ADDR(base,FX2_VAR_NUM) ((base) + (0x0C0+0x4*(FX2_VAR_NUM)))
#define SOC_DP_MONITOR_SIG_POWER_PARAM_ADDR(base,P_NUM) ((base) + (0x0E0+0x4*(P_NUM)))
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_ADDR(base,DPM_NUM) ((base) + (0x260+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_FX2_RESULT_SNAP_ADDR(base,DPM_NUM) ((base) + (0x2B0+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_FINAL_STA_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x300+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_ACC_DPM_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x340+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_ACC_DYN_ENERGY_SNAP_ADDR(base,DPM_NUM) ((base) + (0x380+0x4*(DPM_NUM)))
#define SOC_DP_MONITOR_DPM_COUNTER_PMU_ADDR(base,DPM_NUM,PMU_CNT) ((base) + (0x3C0+0x4*(PMU_CNT)+0x60*(DPM_NUM)))
#define SOC_DP_MONITOR_DPM_COUNTER_ICG_ADDR(base,DPM_NUM,ICG_CNT) ((base) + (0x9C0+0x4*(ICG_CNT)+0xA0*(DPM_NUM)))
#define SOC_DP_MONITOR_ICG_READ_READY_APB_ADDR(base,DPM_NUM) ((base) + (0x13C0+0x4*(DPM_NUM)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rs_cg_bypass : 1;
        unsigned int sync_cg_off : 1;
        unsigned int apb_read_cnt_en : 1;
        unsigned int icg_counter_en : 1;
        unsigned int pmu_counter_en : 1;
        unsigned int sdpm_only_en : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DP_MONITOR_DPM_CTRL_EN_UNION;
#endif
#define SOC_DP_MONITOR_DPM_CTRL_EN_rs_cg_bypass_START (0)
#define SOC_DP_MONITOR_DPM_CTRL_EN_rs_cg_bypass_END (0)
#define SOC_DP_MONITOR_DPM_CTRL_EN_sync_cg_off_START (1)
#define SOC_DP_MONITOR_DPM_CTRL_EN_sync_cg_off_END (1)
#define SOC_DP_MONITOR_DPM_CTRL_EN_apb_read_cnt_en_START (2)
#define SOC_DP_MONITOR_DPM_CTRL_EN_apb_read_cnt_en_END (2)
#define SOC_DP_MONITOR_DPM_CTRL_EN_icg_counter_en_START (3)
#define SOC_DP_MONITOR_DPM_CTRL_EN_icg_counter_en_END (3)
#define SOC_DP_MONITOR_DPM_CTRL_EN_pmu_counter_en_START (4)
#define SOC_DP_MONITOR_DPM_CTRL_EN_pmu_counter_en_END (4)
#define SOC_DP_MONITOR_DPM_CTRL_EN_sdpm_only_en_START (5)
#define SOC_DP_MONITOR_DPM_CTRL_EN_sdpm_only_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdpm_enable : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MONITOR_SDPM_ENABLE_UNION;
#endif
#define SOC_DP_MONITOR_SDPM_ENABLE_sdpm_enable_START (0)
#define SOC_DP_MONITOR_SDPM_ENABLE_sdpm_enable_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sg_ddpm_en : 8;
        unsigned int volt_code_apb : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MONITOR_SG_DDPM_EN_UNION;
#endif
#define SOC_DP_MONITOR_SG_DDPM_EN_sg_ddpm_en_START (0)
#define SOC_DP_MONITOR_SG_DDPM_EN_sg_ddpm_en_END (7)
#define SOC_DP_MONITOR_SG_DDPM_EN_volt_code_apb_START (8)
#define SOC_DP_MONITOR_SG_DDPM_EN_volt_code_apb_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int monitor_ctrl_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MONITOR_DPM_ENABLE_UNION;
#endif
#define SOC_DP_MONITOR_DPM_ENABLE_monitor_ctrl_en_START (0)
#define SOC_DP_MONITOR_DPM_ENABLE_monitor_ctrl_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cnt_init_dyn : 9;
        unsigned int dyn_shift_bit : 4;
        unsigned int sdpm_shift_bit : 5;
        unsigned int volt_temp_var_shift : 4;
        unsigned int cfg_cnt_init_sta : 9;
        unsigned int reserved : 1;
    } reg;
} SOC_DP_MONITOR_SHIFT_BIT_UNION;
#endif
#define SOC_DP_MONITOR_SHIFT_BIT_cfg_cnt_init_dyn_START (0)
#define SOC_DP_MONITOR_SHIFT_BIT_cfg_cnt_init_dyn_END (8)
#define SOC_DP_MONITOR_SHIFT_BIT_dyn_shift_bit_START (9)
#define SOC_DP_MONITOR_SHIFT_BIT_dyn_shift_bit_END (12)
#define SOC_DP_MONITOR_SHIFT_BIT_sdpm_shift_bit_START (13)
#define SOC_DP_MONITOR_SHIFT_BIT_sdpm_shift_bit_END (17)
#define SOC_DP_MONITOR_SHIFT_BIT_volt_temp_var_shift_START (18)
#define SOC_DP_MONITOR_SHIFT_BIT_volt_temp_var_shift_END (21)
#define SOC_DP_MONITOR_SHIFT_BIT_cfg_cnt_init_sta_START (22)
#define SOC_DP_MONITOR_SHIFT_BIT_cfg_cnt_init_sta_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int volt_param_a : 4;
        unsigned int volt_param_b : 10;
        unsigned int reserved : 18;
    } reg;
} SOC_DP_MONITOR_VOLT_UNION;
#endif
#define SOC_DP_MONITOR_VOLT_volt_param_a_START (0)
#define SOC_DP_MONITOR_VOLT_volt_param_a_END (3)
#define SOC_DP_MONITOR_VOLT_volt_param_b_START (4)
#define SOC_DP_MONITOR_VOLT_volt_param_b_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_cfg_apb : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_DP_MONITOR_DVFS_CFG_APB_UNION;
#endif
#define SOC_DP_MONITOR_DVFS_CFG_APB_dvfs_cfg_apb_START (0)
#define SOC_DP_MONITOR_DVFS_CFG_APB_dvfs_cfg_apb_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_cnt_pulse : 1;
        unsigned int soft_energy_pulse : 1;
        unsigned int snapshot_soft_pulse : 1;
        unsigned int freq_update_soft_pulse : 1;
        unsigned int volt_update_soft_pulse : 1;
        unsigned int fsm_update_soft_pulse : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DP_MONITOR_SOFT_PULSE_UNION;
#endif
#define SOC_DP_MONITOR_SOFT_PULSE_soft_cnt_pulse_START (0)
#define SOC_DP_MONITOR_SOFT_PULSE_soft_cnt_pulse_END (0)
#define SOC_DP_MONITOR_SOFT_PULSE_soft_energy_pulse_START (1)
#define SOC_DP_MONITOR_SOFT_PULSE_soft_energy_pulse_END (1)
#define SOC_DP_MONITOR_SOFT_PULSE_snapshot_soft_pulse_START (2)
#define SOC_DP_MONITOR_SOFT_PULSE_snapshot_soft_pulse_END (2)
#define SOC_DP_MONITOR_SOFT_PULSE_freq_update_soft_pulse_START (3)
#define SOC_DP_MONITOR_SOFT_PULSE_freq_update_soft_pulse_END (3)
#define SOC_DP_MONITOR_SOFT_PULSE_volt_update_soft_pulse_START (4)
#define SOC_DP_MONITOR_SOFT_PULSE_volt_update_soft_pulse_END (4)
#define SOC_DP_MONITOR_SOFT_PULSE_fsm_update_soft_pulse_START (5)
#define SOC_DP_MONITOR_SOFT_PULSE_fsm_update_soft_pulse_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int volt_gear : 32;
    } reg;
} SOC_DP_MONITOR_VOLT_GEAR_UNION;
#endif
#define SOC_DP_MONITOR_VOLT_GEAR_volt_gear_START (0)
#define SOC_DP_MONITOR_VOLT_GEAR_volt_gear_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_volt_param_apb : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_DP_MONITOR_STA_VOLT_PARAM_UNION;
#endif
#define SOC_DP_MONITOR_STA_VOLT_PARAM_sta_volt_param_apb_START (0)
#define SOC_DP_MONITOR_STA_VOLT_PARAM_sta_volt_param_apb_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fx2_const_apb : 32;
    } reg;
} SOC_DP_MONITOR_FX2_CONST_UNION;
#endif
#define SOC_DP_MONITOR_FX2_CONST_fx2_const_apb_START (0)
#define SOC_DP_MONITOR_FX2_CONST_fx2_const_apb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fx2_var1_apb : 32;
    } reg;
} SOC_DP_MONITOR_FX2_VAR1_UNION;
#endif
#define SOC_DP_MONITOR_FX2_VAR1_fx2_var1_apb_START (0)
#define SOC_DP_MONITOR_FX2_VAR1_fx2_var1_apb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fx2_var2_apb : 32;
    } reg;
} SOC_DP_MONITOR_FX2_VAR2_UNION;
#endif
#define SOC_DP_MONITOR_FX2_VAR2_fx2_var2_apb_START (0)
#define SOC_DP_MONITOR_FX2_VAR2_fx2_var2_apb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sig_power_param : 32;
    } reg;
} SOC_DP_MONITOR_SIG_POWER_PARAM_UNION;
#endif
#define SOC_DP_MONITOR_SIG_POWER_PARAM_sig_power_param_START (0)
#define SOC_DP_MONITOR_SIG_POWER_PARAM_sig_power_param_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_volt_snap : 11;
        unsigned int cur_temp_snap : 9;
        unsigned int reserved : 12;
    } reg;
} SOC_DP_MONITOR_VOLT_TEMP_SNAP_UNION;
#endif
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_cur_volt_snap_START (0)
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_cur_volt_snap_END (10)
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_cur_temp_snap_START (11)
#define SOC_DP_MONITOR_VOLT_TEMP_SNAP_cur_temp_snap_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fx2_result_snap : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_DP_MONITOR_FX2_RESULT_SNAP_UNION;
#endif
#define SOC_DP_MONITOR_FX2_RESULT_SNAP_fx2_result_snap_START (0)
#define SOC_DP_MONITOR_FX2_RESULT_SNAP_fx2_result_snap_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int final_sta_energy_snap : 32;
    } reg;
} SOC_DP_MONITOR_FINAL_STA_ENERGY_SNAP_UNION;
#endif
#define SOC_DP_MONITOR_FINAL_STA_ENERGY_SNAP_final_sta_energy_snap_START (0)
#define SOC_DP_MONITOR_FINAL_STA_ENERGY_SNAP_final_sta_energy_snap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acc_dpm_energy_apb : 32;
    } reg;
} SOC_DP_MONITOR_ACC_DPM_ENERGY_SNAP_UNION;
#endif
#define SOC_DP_MONITOR_ACC_DPM_ENERGY_SNAP_acc_dpm_energy_apb_START (0)
#define SOC_DP_MONITOR_ACC_DPM_ENERGY_SNAP_acc_dpm_energy_apb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acc_dyn_energy_apb : 32;
    } reg;
} SOC_DP_MONITOR_ACC_DYN_ENERGY_SNAP_UNION;
#endif
#define SOC_DP_MONITOR_ACC_DYN_ENERGY_SNAP_acc_dyn_energy_apb_START (0)
#define SOC_DP_MONITOR_ACC_DYN_ENERGY_SNAP_acc_dyn_energy_apb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpm_counter_pmu : 32;
    } reg;
} SOC_DP_MONITOR_DPM_COUNTER_PMU_UNION;
#endif
#define SOC_DP_MONITOR_DPM_COUNTER_PMU_dpm_counter_pmu_START (0)
#define SOC_DP_MONITOR_DPM_COUNTER_PMU_dpm_counter_pmu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpm_counter_icg : 32;
    } reg;
} SOC_DP_MONITOR_DPM_COUNTER_ICG_UNION;
#endif
#define SOC_DP_MONITOR_DPM_COUNTER_ICG_dpm_counter_icg_START (0)
#define SOC_DP_MONITOR_DPM_COUNTER_ICG_dpm_counter_icg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icg_read_ready_apb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DP_MONITOR_ICG_READ_READY_APB_UNION;
#endif
#define SOC_DP_MONITOR_ICG_READ_READY_APB_icg_read_ready_apb_START (0)
#define SOC_DP_MONITOR_ICG_READ_READY_APB_icg_read_ready_apb_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
