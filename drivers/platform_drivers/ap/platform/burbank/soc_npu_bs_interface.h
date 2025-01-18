#ifndef __SOC_NPU_BS_INTERFACE_H__
#define __SOC_NPU_BS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_BS_BSC_INIT_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_BS_BSC_MAIN_CFG_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_BS_BSC_TSC_CFG_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_BS_BSC_MSBO_CFG_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_BS_BSC_BO_PRI_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_BS_BSC_BO_CNT_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_BS_BSC_BO_CODE_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_BS_BSC_CMD_TO_CNT_LO_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_BS_BSC_CMD_TO_CNT_HI_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_BS_BSC_DEBUG_PAUSE_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_BS_BSC_RESET_OVERHEAD_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_BS_BSC_SECURE_CODE_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_BS_BSC_MAIN_SCH_LITE_CFG_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_BS_BSC_ERROR_CLR_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_BS_BSC_SEC_CTRL_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_BS_BSC_INT_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_BS_BSC_INT_MSK_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_MSK_ADDR(base) ((base) + (0x0054UL))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_MSK_ADDR(base) ((base) + (0x0058UL))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_MSK_ADDR(base) ((base) + (0x005CUL))
#define SOC_NPU_BS_BSC_INT_SET_ADDR(base) ((base) + (0x0060UL))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_SET_ADDR(base) ((base) + (0x0064UL))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_SET_ADDR(base) ((base) + (0x0068UL))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_SET_ADDR(base) ((base) + (0x006CUL))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_ADDR(base) ((base) + (0x0070UL))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_ADDR(base) ((base) + (0x0074UL))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_ADDR(base) ((base) + (0x0078UL))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_MSK_ADDR(base) ((base) + (0x007CUL))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_MSK_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_MSK_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_SET_ADDR(base) ((base) + (0x0088UL))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_SET_ADDR(base) ((base) + (0x008CUL))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_SET_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_SET_ADDR(base) ((base) + (0x0098UL))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_MSK_ADDR(base) ((base) + (0x009CUL))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_SET_ADDR(base) ((base) + (0x00A4UL))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_MSK_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_SET_ADDR(base) ((base) + (0x00B4UL))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_MSK_ADDR(base) ((base) + (0x00B8UL))
#define SOC_NPU_BS_BSC_CORE_CUR_TS_ADDR(base,l) ((base) + ((l)*0x04+0x100UL))
#define SOC_NPU_BS_BSC_CORE_CUR_TS_BM_ADDR(base,l) ((base) + ((l)*0x04+0x180UL))
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_LO_ADDR(base,l) ((base) + ((l)*0x08+0x200UL))
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_HI_ADDR(base,l) ((base) + ((l)*0x08+0x204UL))
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_ADDR(base,l) ((base) + ((l)*0x04+0x300UL))
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_STATUS_ADDR(base) ((base) + (0x0380UL))
#else
#define SOC_NPU_BS_BSC_INIT_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_BS_BSC_MAIN_CFG_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_BS_BSC_TSC_CFG_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_BS_BSC_MSBO_CFG_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_BS_BSC_BO_PRI_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_BS_BSC_BO_CNT_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_BS_BSC_BO_CODE_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_BS_BSC_CMD_TO_CNT_LO_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_BS_BSC_CMD_TO_CNT_HI_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_BS_BSC_DEBUG_PAUSE_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_BS_BSC_RESET_OVERHEAD_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_BS_BSC_SECURE_CODE_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_BS_BSC_MAIN_SCH_LITE_CFG_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_BS_BSC_ERROR_CLR_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_BS_BSC_SEC_CTRL_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_BS_BSC_INT_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_BS_BSC_INT_MSK_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_MSK_ADDR(base) ((base) + (0x0054))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_MSK_ADDR(base) ((base) + (0x0058))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_MSK_ADDR(base) ((base) + (0x005C))
#define SOC_NPU_BS_BSC_INT_SET_ADDR(base) ((base) + (0x0060))
#define SOC_NPU_BS_BSC_TASK_DONE_INT_SET_ADDR(base) ((base) + (0x0064))
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_SET_ADDR(base) ((base) + (0x0068))
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_SET_ADDR(base) ((base) + (0x006C))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_ADDR(base) ((base) + (0x0070))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_ADDR(base) ((base) + (0x0074))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_ADDR(base) ((base) + (0x0078))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_MSK_ADDR(base) ((base) + (0x007C))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_MSK_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_MSK_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_SET_ADDR(base) ((base) + (0x0088))
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_SET_ADDR(base) ((base) + (0x008C))
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_SET_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_SET_ADDR(base) ((base) + (0x0098))
#define SOC_NPU_BS_BSC_TASK_DFX_INT_MSK_ADDR(base) ((base) + (0x009C))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_SET_ADDR(base) ((base) + (0x00A4))
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_MSK_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_SET_ADDR(base) ((base) + (0x00B4))
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_MSK_ADDR(base) ((base) + (0x00B8))
#define SOC_NPU_BS_BSC_CORE_CUR_TS_ADDR(base,l) ((base) + ((l)*0x04+0x100))
#define SOC_NPU_BS_BSC_CORE_CUR_TS_BM_ADDR(base,l) ((base) + ((l)*0x04+0x180))
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_LO_ADDR(base,l) ((base) + ((l)*0x08+0x200))
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_HI_ADDR(base,l) ((base) + ((l)*0x08+0x204))
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_ADDR(base,l) ((base) + ((l)*0x04+0x300))
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_STATUS_ADDR(base) ((base) + (0x0380))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_BS_TS_CFG_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_BS_TS_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_BS_TS_SECURE_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_BS_TS_ALLOC_GOAL_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_BS_TS_ASSIGN_TAB_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_BS_TS_OVR_GOAL_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_BS_TS_OVR_ASSIGN_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_BS_TS_CURRET_CORE_USEAGE_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_BS_TS_STATUS_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_BS_TSC_DFX_CODE_ADDR(base) ((base) + (0x0054UL))
#define SOC_NPU_BS_TSC_TERM_CODE_ADDR(base) ((base) + (0x0058UL))
#define SOC_NPU_BS_TSC_CORE_DEBUG_ADDR(base) ((base) + (0x0060UL))
#define SOC_NPU_BS_TSC_CORE_EXCEPTION_ADDR(base) ((base) + (0x0064UL))
#define SOC_NPU_BS_TSC_CORE_TRAP_ADDR(base) ((base) + (0x0068UL))
#define SOC_NPU_BS_TS_LAST_CORE_ID_ADDR(base) ((base) + (0x0070UL))
#define SOC_NPU_BS_TS_CORE_ID_ADDR(base,l) ((base) + ((l)*0x04+0x80UL))
#define SOC_NPU_BS_TS_PRIORITY_ADDR(base) ((base) + (0x0100UL))
#define SOC_NPU_BS_TS_BW_WEIGHT_ADDR(base) ((base) + (0x0108UL))
#define SOC_NPU_BS_TS_MIN_CORE_ADDR(base) ((base) + (0x010CUL))
#define SOC_NPU_BS_TS_PC_START_LO_ADDR(base) ((base) + (0x0110UL))
#define SOC_NPU_BS_TS_PC_START_HI_ADDR(base) ((base) + (0x0114UL))
#define SOC_NPU_BS_TS_PARAM_BASE_LO_ADDR(base) ((base) + (0x0118UL))
#define SOC_NPU_BS_TS_PARAM_BASE_HI_ADDR(base) ((base) + (0x011CUL))
#define SOC_NPU_BS_TS_SMMU_SUBSID_ADDR(base) ((base) + (0x0120UL))
#define SOC_NPU_BS_TS_TASK_CFG_ADDR(base) ((base) + (0x0124UL))
#define SOC_NPU_BS_TS_BLK_NUM_ADDR(base) ((base) + (0x0128UL))
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_LO_ADDR(base) ((base) + (0x012CUL))
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_HI_ADDR(base) ((base) + (0x0130UL))
#define SOC_NPU_BS_TS_UB_BASE_ADDR(base) ((base) + (0x0134UL))
#define SOC_NPU_BS_TS_DATA_SIZE_ADDR(base) ((base) + (0x0138UL))
#define SOC_NPU_BS_TS_L2_VADDR_BASE_LO_ADDR(base) ((base) + (0x013CUL))
#define SOC_NPU_BS_TS_L2_VADDR_BASE_HI_ADDR(base) ((base) + (0x0140UL))
#define SOC_NPU_BS_TS_L2_REMAP_CFG_ADDR(base) ((base) + (0x0144UL))
#define SOC_NPU_BS_TS_L2_REMAP_ENTRY_ADDR(base,m) ((base) + ((m)*0x04+0x148UL))
#define SOC_NPU_BS_TS_PROFILING_CNT_LO_ADDR(base,k) ((base) + ((k)*0x08+0x300UL))
#define SOC_NPU_BS_TS_PROFILING_CNT_HI_ADDR(base,k) ((base) + ((k)*0x08+0x304UL))
#define SOC_NPU_BS_TS_CYC_CNT_LO_ADDR(base) ((base) + (0x0340UL))
#define SOC_NPU_BS_TS_CYC_CNT_HI_ADDR(base) ((base) + (0x0344UL))
#define SOC_NPU_BS_TS_OV_MIN_CNT_LO_ADDR(base) ((base) + (0x0348UL))
#define SOC_NPU_BS_TS_OV_MIN_CNT_HI_ADDR(base) ((base) + (0x034CUL))
#define SOC_NPU_BS_TS_OV_FLOW_ADDR(base) ((base) + (0x0350UL))
#define SOC_NPU_BS_TS_PROFILING_RANGE_EN_ADDR(base) ((base) + (0x0354UL))
#define SOC_NPU_BS_TS_PROFILING_RANGE_ADDR(base) ((base) + (0x0358UL))
#else
#define SOC_NPU_BS_TS_CFG_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_BS_TS_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_BS_TS_SECURE_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_BS_TS_ALLOC_GOAL_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_BS_TS_ASSIGN_TAB_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_BS_TS_OVR_GOAL_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_BS_TS_OVR_ASSIGN_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_BS_TS_CURRET_CORE_USEAGE_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_BS_TS_STATUS_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_BS_TSC_DFX_CODE_ADDR(base) ((base) + (0x0054))
#define SOC_NPU_BS_TSC_TERM_CODE_ADDR(base) ((base) + (0x0058))
#define SOC_NPU_BS_TSC_CORE_DEBUG_ADDR(base) ((base) + (0x0060))
#define SOC_NPU_BS_TSC_CORE_EXCEPTION_ADDR(base) ((base) + (0x0064))
#define SOC_NPU_BS_TSC_CORE_TRAP_ADDR(base) ((base) + (0x0068))
#define SOC_NPU_BS_TS_LAST_CORE_ID_ADDR(base) ((base) + (0x0070))
#define SOC_NPU_BS_TS_CORE_ID_ADDR(base,l) ((base) + ((l)*0x04+0x80))
#define SOC_NPU_BS_TS_PRIORITY_ADDR(base) ((base) + (0x0100))
#define SOC_NPU_BS_TS_BW_WEIGHT_ADDR(base) ((base) + (0x0108))
#define SOC_NPU_BS_TS_MIN_CORE_ADDR(base) ((base) + (0x010C))
#define SOC_NPU_BS_TS_PC_START_LO_ADDR(base) ((base) + (0x0110))
#define SOC_NPU_BS_TS_PC_START_HI_ADDR(base) ((base) + (0x0114))
#define SOC_NPU_BS_TS_PARAM_BASE_LO_ADDR(base) ((base) + (0x0118))
#define SOC_NPU_BS_TS_PARAM_BASE_HI_ADDR(base) ((base) + (0x011C))
#define SOC_NPU_BS_TS_SMMU_SUBSID_ADDR(base) ((base) + (0x0120))
#define SOC_NPU_BS_TS_TASK_CFG_ADDR(base) ((base) + (0x0124))
#define SOC_NPU_BS_TS_BLK_NUM_ADDR(base) ((base) + (0x0128))
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_LO_ADDR(base) ((base) + (0x012C))
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_HI_ADDR(base) ((base) + (0x0130))
#define SOC_NPU_BS_TS_UB_BASE_ADDR(base) ((base) + (0x0134))
#define SOC_NPU_BS_TS_DATA_SIZE_ADDR(base) ((base) + (0x0138))
#define SOC_NPU_BS_TS_L2_VADDR_BASE_LO_ADDR(base) ((base) + (0x013C))
#define SOC_NPU_BS_TS_L2_VADDR_BASE_HI_ADDR(base) ((base) + (0x0140))
#define SOC_NPU_BS_TS_L2_REMAP_CFG_ADDR(base) ((base) + (0x0144))
#define SOC_NPU_BS_TS_L2_REMAP_ENTRY_ADDR(base,m) ((base) + ((m)*0x04+0x148))
#define SOC_NPU_BS_TS_PROFILING_CNT_LO_ADDR(base,k) ((base) + ((k)*0x08+0x300))
#define SOC_NPU_BS_TS_PROFILING_CNT_HI_ADDR(base,k) ((base) + ((k)*0x08+0x304))
#define SOC_NPU_BS_TS_CYC_CNT_LO_ADDR(base) ((base) + (0x0340))
#define SOC_NPU_BS_TS_CYC_CNT_HI_ADDR(base) ((base) + (0x0344))
#define SOC_NPU_BS_TS_OV_MIN_CNT_LO_ADDR(base) ((base) + (0x0348))
#define SOC_NPU_BS_TS_OV_MIN_CNT_HI_ADDR(base) ((base) + (0x034C))
#define SOC_NPU_BS_TS_OV_FLOW_ADDR(base) ((base) + (0x0350))
#define SOC_NPU_BS_TS_PROFILING_RANGE_EN_ADDR(base) ((base) + (0x0354))
#define SOC_NPU_BS_TS_PROFILING_RANGE_ADDR(base) ((base) + (0x0358))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int initial_seq : 1;
        unsigned int initialized : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_BS_BSC_INIT_UNION;
#endif
#define SOC_NPU_BS_BSC_INIT_initial_seq_START (0)
#define SOC_NPU_BS_BSC_INIT_initial_seq_END (0)
#define SOC_NPU_BS_BSC_INIT_initialized_START (1)
#define SOC_NPU_BS_BSC_INIT_initialized_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_bypass : 1;
        unsigned int aic_secure_mode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_BS_BSC_MAIN_CFG_UNION;
#endif
#define SOC_NPU_BS_BSC_MAIN_CFG_int_bypass_START (0)
#define SOC_NPU_BS_BSC_MAIN_CFG_int_bypass_END (0)
#define SOC_NPU_BS_BSC_MAIN_CFG_aic_secure_mode_START (1)
#define SOC_NPU_BS_BSC_MAIN_CFG_aic_secure_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_cache_invalid : 1;
        unsigned int functional_reset : 1;
        unsigned int fast_path_mode : 1;
        unsigned int icache_preload_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_BS_BSC_TSC_CFG_UNION;
#endif
#define SOC_NPU_BS_BSC_TSC_CFG_force_cache_invalid_START (0)
#define SOC_NPU_BS_BSC_TSC_CFG_force_cache_invalid_END (0)
#define SOC_NPU_BS_BSC_TSC_CFG_functional_reset_START (1)
#define SOC_NPU_BS_BSC_TSC_CFG_functional_reset_END (1)
#define SOC_NPU_BS_BSC_TSC_CFG_fast_path_mode_START (2)
#define SOC_NPU_BS_BSC_TSC_CFG_fast_path_mode_END (2)
#define SOC_NPU_BS_BSC_TSC_CFG_icache_preload_bypass_START (3)
#define SOC_NPU_BS_BSC_TSC_CFG_icache_preload_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stall_allocation : 1;
        unsigned int stall_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int bo_update_mode : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_NPU_BS_BSC_MSBO_CFG_UNION;
#endif
#define SOC_NPU_BS_BSC_MSBO_CFG_stall_allocation_START (0)
#define SOC_NPU_BS_BSC_MSBO_CFG_stall_allocation_END (0)
#define SOC_NPU_BS_BSC_MSBO_CFG_stall_en_START (1)
#define SOC_NPU_BS_BSC_MSBO_CFG_stall_en_END (1)
#define SOC_NPU_BS_BSC_MSBO_CFG_bo_update_mode_START (3)
#define SOC_NPU_BS_BSC_MSBO_CFG_bo_update_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sp_level : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_BS_BSC_BO_PRI_UNION;
#endif
#define SOC_NPU_BS_BSC_BO_PRI_sp_level_START (0)
#define SOC_NPU_BS_BSC_BO_PRI_sp_level_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bo_timeout_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_BS_BSC_BO_CNT_UNION;
#endif
#define SOC_NPU_BS_BSC_BO_CNT_bo_timeout_cnt_START (0)
#define SOC_NPU_BS_BSC_BO_CNT_bo_timeout_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bo_code : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_BSC_BO_CODE_UNION;
#endif
#define SOC_NPU_BS_BSC_BO_CODE_bo_code_START (0)
#define SOC_NPU_BS_BSC_BO_CODE_bo_code_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tsc_timeout_cnt_lo : 32;
    } reg;
} SOC_NPU_BS_BSC_CMD_TO_CNT_LO_UNION;
#endif
#define SOC_NPU_BS_BSC_CMD_TO_CNT_LO_tsc_timeout_cnt_lo_START (0)
#define SOC_NPU_BS_BSC_CMD_TO_CNT_LO_tsc_timeout_cnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tsc_timeout_cnt_hi : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_BSC_CMD_TO_CNT_HI_UNION;
#endif
#define SOC_NPU_BS_BSC_CMD_TO_CNT_HI_tsc_timeout_cnt_hi_START (0)
#define SOC_NPU_BS_BSC_CMD_TO_CNT_HI_tsc_timeout_cnt_hi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bsc_debug_pause : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_BSC_DEBUG_PAUSE_UNION;
#endif
#define SOC_NPU_BS_BSC_DEBUG_PAUSE_bsc_debug_pause_START (0)
#define SOC_NPU_BS_BSC_DEBUG_PAUSE_bsc_debug_pause_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reset_overhead : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_BSC_RESET_OVERHEAD_UNION;
#endif
#define SOC_NPU_BS_BSC_RESET_OVERHEAD_reset_overhead_START (0)
#define SOC_NPU_BS_BSC_RESET_OVERHEAD_reset_overhead_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure_code : 32;
    } reg;
} SOC_NPU_BS_BSC_SECURE_CODE_UNION;
#endif
#define SOC_NPU_BS_BSC_SECURE_CODE_secure_code_START (0)
#define SOC_NPU_BS_BSC_SECURE_CODE_secure_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ping_pong_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_BSC_MAIN_SCH_LITE_CFG_UNION;
#endif
#define SOC_NPU_BS_BSC_MAIN_SCH_LITE_CFG_ping_pong_mode_START (0)
#define SOC_NPU_BS_BSC_MAIN_SCH_LITE_CFG_ping_pong_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int error_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_BSC_ERROR_CLR_UNION;
#endif
#define SOC_NPU_BS_BSC_ERROR_CLR_error_clear_START (0)
#define SOC_NPU_BS_BSC_ERROR_CLR_error_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bs_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_BSC_SEC_CTRL_UNION;
#endif
#define SOC_NPU_BS_BSC_SEC_CTRL_bs_sec_en_START (0)
#define SOC_NPU_BS_BSC_SEC_CTRL_bs_sec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bo_done : 1;
        unsigned int bo_exception : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_disable : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_NPU_BS_BSC_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_INT_bo_done_START (0)
#define SOC_NPU_BS_BSC_INT_bo_done_END (0)
#define SOC_NPU_BS_BSC_INT_bo_exception_START (1)
#define SOC_NPU_BS_BSC_INT_bo_exception_END (1)
#define SOC_NPU_BS_BSC_INT_core_disable_START (3)
#define SOC_NPU_BS_BSC_INT_core_disable_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DONE_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DONE_INT_task_done_START (0)
#define SOC_NPU_BS_BSC_TASK_DONE_INT_task_done_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_debug : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DEBUG_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_task_debug_START (0)
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_task_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_exception : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_task_exception_START (0)
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_task_exception_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bo_done_int_msk : 1;
        unsigned int bo_exception_int_msk : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_disable_int_msk : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_NPU_BS_BSC_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_INT_MSK_bo_done_int_msk_START (0)
#define SOC_NPU_BS_BSC_INT_MSK_bo_done_int_msk_END (0)
#define SOC_NPU_BS_BSC_INT_MSK_bo_exception_int_msk_START (1)
#define SOC_NPU_BS_BSC_INT_MSK_bo_exception_int_msk_END (1)
#define SOC_NPU_BS_BSC_INT_MSK_core_disable_int_msk_START (3)
#define SOC_NPU_BS_BSC_INT_MSK_core_disable_int_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DONE_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DONE_INT_MSK_task_done_int_msk_START (0)
#define SOC_NPU_BS_BSC_TASK_DONE_INT_MSK_task_done_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_debug_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DEBUG_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_MSK_task_debug_int_msk_START (0)
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_MSK_task_debug_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_exception_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_MSK_task_exception_int_msk_START (0)
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_MSK_task_exception_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bo_done_int_set : 1;
        unsigned int bo_exception_int_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_disable_int_set : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_NPU_BS_BSC_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_INT_SET_bo_done_int_set_START (0)
#define SOC_NPU_BS_BSC_INT_SET_bo_done_int_set_END (0)
#define SOC_NPU_BS_BSC_INT_SET_bo_exception_int_set_START (1)
#define SOC_NPU_BS_BSC_INT_SET_bo_exception_int_set_END (1)
#define SOC_NPU_BS_BSC_INT_SET_core_disable_int_set_START (3)
#define SOC_NPU_BS_BSC_INT_SET_core_disable_int_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_done_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DONE_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DONE_INT_SET_task_done_int_set_START (0)
#define SOC_NPU_BS_BSC_TASK_DONE_INT_SET_task_done_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_debug_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DEBUG_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_SET_task_debug_int_set_START (0)
#define SOC_NPU_BS_BSC_TASK_DEBUG_INT_SET_task_debug_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_exception_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_SET_task_exception_int_set_START (0)
#define SOC_NPU_BS_BSC_TASK_EXCEPTION_INT_SET_task_exception_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_done : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DONE_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_core_done_START (0)
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_core_done_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_debug : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DEBUG_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_core_debug_START (0)
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_core_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_exception : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_core_exception_START (0)
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_core_exception_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_done_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DONE_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_MSK_core_done_int_msk_START (0)
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_MSK_core_done_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_debug_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DEBUG_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_MSK_core_debug_int_msk_START (0)
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_MSK_core_debug_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_exception_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_MSK_core_exception_int_msk_START (0)
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_MSK_core_exception_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_done_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DONE_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_SET_core_done_int_set_START (0)
#define SOC_NPU_BS_BSC_AICORE_DONE_INT_SET_core_done_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_debug_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_DEBUG_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_SET_core_debug_int_set_START (0)
#define SOC_NPU_BS_BSC_AICORE_DEBUG_INT_SET_core_debug_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_exception_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_SET_core_exception_int_set_START (0)
#define SOC_NPU_BS_BSC_AICORE_EXCEPTION_INT_SET_core_exception_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_dfx : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DFX_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DFX_INT_task_dfx_START (0)
#define SOC_NPU_BS_BSC_TASK_DFX_INT_task_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_dfx_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DFX_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DFX_INT_SET_task_dfx_int_set_START (0)
#define SOC_NPU_BS_BSC_TASK_DFX_INT_SET_task_dfx_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_dfx_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_DFX_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_DFX_INT_MSK_task_dfx_int_msk_START (0)
#define SOC_NPU_BS_BSC_TASK_DFX_INT_MSK_task_dfx_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_paused : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_PAUSED_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_task_paused_START (0)
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_task_paused_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_paused_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_PAUSED_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_SET_task_paused_int_set_START (0)
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_SET_task_paused_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_paused_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_TASK_PAUSED_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_MSK_task_paused_int_msk_START (0)
#define SOC_NPU_BS_BSC_TASK_PAUSED_INT_MSK_task_paused_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_trap : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_TRAP_INT_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_core_trap_START (0)
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_core_trap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_trap_int_set : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_TRAP_INT_SET_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_SET_core_trap_int_set_START (0)
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_SET_core_trap_int_set_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_trap_int_msk : 32;
    } reg;
} SOC_NPU_BS_BSC_AICORE_TRAP_INT_MSK_UNION;
#endif
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_MSK_core_trap_int_msk_START (0)
#define SOC_NPU_BS_BSC_AICORE_TRAP_INT_MSK_core_trap_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_cur_task : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_BS_BSC_CORE_CUR_TS_UNION;
#endif
#define SOC_NPU_BS_BSC_CORE_CUR_TS_core_cur_task_START (0)
#define SOC_NPU_BS_BSC_CORE_CUR_TS_core_cur_task_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_cur_task_bm : 32;
    } reg;
} SOC_NPU_BS_BSC_CORE_CUR_TS_BM_UNION;
#endif
#define SOC_NPU_BS_BSC_CORE_CUR_TS_BM_core_cur_task_bm_START (0)
#define SOC_NPU_BS_BSC_CORE_CUR_TS_BM_core_cur_task_bm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_core_addr_lo : 32;
    } reg;
} SOC_NPU_BS_BSC_PHY_CORE_ADR_LO_UNION;
#endif
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_LO_phy_core_addr_lo_START (0)
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_LO_phy_core_addr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_core_addr_hi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_BS_BSC_PHY_CORE_ADR_HI_UNION;
#endif
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_HI_phy_core_addr_hi_START (0)
#define SOC_NPU_BS_BSC_PHY_CORE_ADR_HI_phy_core_addr_hi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_core_id : 6;
        unsigned int vir_core_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int group_num : 2;
        unsigned int reserved_1 : 6;
        unsigned int core_error_code : 4;
        unsigned int core_error : 1;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_NPU_BS_BSC_VIRTUAL_CORE_UNION;
#endif
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_phy_core_id_START (0)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_phy_core_id_END (5)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_vir_core_en_START (6)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_vir_core_en_END (6)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_group_num_START (8)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_group_num_END (9)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_core_error_code_START (16)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_core_error_code_END (19)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_core_error_START (20)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_core_error_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vir_core_valid : 32;
    } reg;
} SOC_NPU_BS_BSC_VIRTUAL_CORE_STATUS_UNION;
#endif
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_STATUS_vir_core_valid_START (0)
#define SOC_NPU_BS_BSC_VIRTUAL_CORE_STATUS_vir_core_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int taskslot_en : 1;
        unsigned int profiling_en : 1;
        unsigned int override_mode : 2;
        unsigned int reserved_0 : 4;
        unsigned int dfx_mode_en : 1;
        unsigned int reserved_1 : 7;
        unsigned int dependent_en : 1;
        unsigned int reserved_2 : 7;
        unsigned int dependent_task_slot_id : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_BS_TS_CFG_UNION;
#endif
#define SOC_NPU_BS_TS_CFG_taskslot_en_START (0)
#define SOC_NPU_BS_TS_CFG_taskslot_en_END (0)
#define SOC_NPU_BS_TS_CFG_profiling_en_START (1)
#define SOC_NPU_BS_TS_CFG_profiling_en_END (1)
#define SOC_NPU_BS_TS_CFG_override_mode_START (2)
#define SOC_NPU_BS_TS_CFG_override_mode_END (3)
#define SOC_NPU_BS_TS_CFG_dfx_mode_en_START (8)
#define SOC_NPU_BS_TS_CFG_dfx_mode_en_END (8)
#define SOC_NPU_BS_TS_CFG_dependent_en_START (16)
#define SOC_NPU_BS_TS_CFG_dependent_en_END (16)
#define SOC_NPU_BS_TS_CFG_dependent_task_slot_id_START (24)
#define SOC_NPU_BS_TS_CFG_dependent_task_slot_id_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_resume : 1;
        unsigned int excpetion_handled : 1;
        unsigned int task_kill : 1;
        unsigned int debug_pause : 1;
        unsigned int task_pause : 1;
        unsigned int task_pause_resume : 1;
        unsigned int dfx_resume : 1;
        unsigned int task_terminate : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_TS_CTRL_UNION;
#endif
#define SOC_NPU_BS_TS_CTRL_debug_resume_START (0)
#define SOC_NPU_BS_TS_CTRL_debug_resume_END (0)
#define SOC_NPU_BS_TS_CTRL_excpetion_handled_START (1)
#define SOC_NPU_BS_TS_CTRL_excpetion_handled_END (1)
#define SOC_NPU_BS_TS_CTRL_task_kill_START (2)
#define SOC_NPU_BS_TS_CTRL_task_kill_END (2)
#define SOC_NPU_BS_TS_CTRL_debug_pause_START (3)
#define SOC_NPU_BS_TS_CTRL_debug_pause_END (3)
#define SOC_NPU_BS_TS_CTRL_task_pause_START (4)
#define SOC_NPU_BS_TS_CTRL_task_pause_END (4)
#define SOC_NPU_BS_TS_CTRL_task_pause_resume_START (5)
#define SOC_NPU_BS_TS_CTRL_task_pause_resume_END (5)
#define SOC_NPU_BS_TS_CTRL_dfx_resume_START (6)
#define SOC_NPU_BS_TS_CTRL_dfx_resume_END (6)
#define SOC_NPU_BS_TS_CTRL_task_terminate_START (7)
#define SOC_NPU_BS_TS_CTRL_task_terminate_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_secure : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_BS_TS_SECURE_UNION;
#endif
#define SOC_NPU_BS_TS_SECURE_ts_secure_START (0)
#define SOC_NPU_BS_TS_SECURE_ts_secure_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alloc_goal : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_BS_TS_ALLOC_GOAL_UNION;
#endif
#define SOC_NPU_BS_TS_ALLOC_GOAL_alloc_goal_START (0)
#define SOC_NPU_BS_TS_ALLOC_GOAL_alloc_goal_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_assign : 32;
    } reg;
} SOC_NPU_BS_TS_ASSIGN_TAB_UNION;
#endif
#define SOC_NPU_BS_TS_ASSIGN_TAB_core_assign_START (0)
#define SOC_NPU_BS_TS_ASSIGN_TAB_core_assign_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alloc_goal_override : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_BS_TS_OVR_GOAL_UNION;
#endif
#define SOC_NPU_BS_TS_OVR_GOAL_alloc_goal_override_START (0)
#define SOC_NPU_BS_TS_OVR_GOAL_alloc_goal_override_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_assign_override : 32;
    } reg;
} SOC_NPU_BS_TS_OVR_ASSIGN_UNION;
#endif
#define SOC_NPU_BS_TS_OVR_ASSIGN_core_assign_override_START (0)
#define SOC_NPU_BS_TS_OVR_ASSIGN_core_assign_override_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_core_usage : 32;
    } reg;
} SOC_NPU_BS_TS_CURRET_CORE_USEAGE_UNION;
#endif
#define SOC_NPU_BS_TS_CURRET_CORE_USEAGE_cur_core_usage_START (0)
#define SOC_NPU_BS_TS_CURRET_CORE_USEAGE_cur_core_usage_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kick_state : 2;
        unsigned int reserved_0 : 6;
        unsigned int tsc_state : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_NPU_BS_TS_STATUS_UNION;
#endif
#define SOC_NPU_BS_TS_STATUS_kick_state_START (0)
#define SOC_NPU_BS_TS_STATUS_kick_state_END (1)
#define SOC_NPU_BS_TS_STATUS_tsc_state_START (8)
#define SOC_NPU_BS_TS_STATUS_tsc_state_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_code : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_TSC_DFX_CODE_UNION;
#endif
#define SOC_NPU_BS_TSC_DFX_CODE_dfx_code_START (0)
#define SOC_NPU_BS_TSC_DFX_CODE_dfx_code_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int term_code : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_TSC_TERM_CODE_UNION;
#endif
#define SOC_NPU_BS_TSC_TERM_CODE_term_code_START (0)
#define SOC_NPU_BS_TSC_TERM_CODE_term_code_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_bitmap : 32;
    } reg;
} SOC_NPU_BS_TSC_CORE_DEBUG_UNION;
#endif
#define SOC_NPU_BS_TSC_CORE_DEBUG_debug_bitmap_START (0)
#define SOC_NPU_BS_TSC_CORE_DEBUG_debug_bitmap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exception_bitmap : 32;
    } reg;
} SOC_NPU_BS_TSC_CORE_EXCEPTION_UNION;
#endif
#define SOC_NPU_BS_TSC_CORE_EXCEPTION_exception_bitmap_START (0)
#define SOC_NPU_BS_TSC_CORE_EXCEPTION_exception_bitmap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trap_bitmap : 32;
    } reg;
} SOC_NPU_BS_TSC_CORE_TRAP_UNION;
#endif
#define SOC_NPU_BS_TSC_CORE_TRAP_trap_bitmap_START (0)
#define SOC_NPU_BS_TSC_CORE_TRAP_trap_bitmap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int next_block_id : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_BS_TS_LAST_CORE_ID_UNION;
#endif
#define SOC_NPU_BS_TS_LAST_CORE_ID_next_block_id_START (0)
#define SOC_NPU_BS_TS_LAST_CORE_ID_next_block_id_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_block_id : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_NPU_BS_TS_CORE_ID_UNION;
#endif
#define SOC_NPU_BS_TS_CORE_ID_cur_block_id_START (0)
#define SOC_NPU_BS_TS_CORE_ID_cur_block_id_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_priority : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_BS_TS_PRIORITY_UNION;
#endif
#define SOC_NPU_BS_TS_PRIORITY_task_priority_START (0)
#define SOC_NPU_BS_TS_PRIORITY_task_priority_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_weight : 3;
        unsigned int reserved_0 : 13;
        unsigned int hbm_weight : 3;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_NPU_BS_TS_BW_WEIGHT_UNION;
#endif
#define SOC_NPU_BS_TS_BW_WEIGHT_l2_weight_START (0)
#define SOC_NPU_BS_TS_BW_WEIGHT_l2_weight_END (2)
#define SOC_NPU_BS_TS_BW_WEIGHT_hbm_weight_START (16)
#define SOC_NPU_BS_TS_BW_WEIGHT_hbm_weight_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int min_num_core : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_BS_TS_MIN_CORE_UNION;
#endif
#define SOC_NPU_BS_TS_MIN_CORE_min_num_core_START (0)
#define SOC_NPU_BS_TS_MIN_CORE_min_num_core_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_start_lo : 32;
    } reg;
} SOC_NPU_BS_TS_PC_START_LO_UNION;
#endif
#define SOC_NPU_BS_TS_PC_START_LO_pc_start_lo_START (0)
#define SOC_NPU_BS_TS_PC_START_LO_pc_start_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pc_start_hi : 16;
        unsigned int reserved : 12;
        unsigned int ifu_preload_cnt : 4;
    } reg;
} SOC_NPU_BS_TS_PC_START_HI_UNION;
#endif
#define SOC_NPU_BS_TS_PC_START_HI_pc_start_hi_START (0)
#define SOC_NPU_BS_TS_PC_START_HI_pc_start_hi_END (15)
#define SOC_NPU_BS_TS_PC_START_HI_ifu_preload_cnt_START (28)
#define SOC_NPU_BS_TS_PC_START_HI_ifu_preload_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int param_base_lo : 32;
    } reg;
} SOC_NPU_BS_TS_PARAM_BASE_LO_UNION;
#endif
#define SOC_NPU_BS_TS_PARAM_BASE_LO_param_base_lo_START (0)
#define SOC_NPU_BS_TS_PARAM_BASE_LO_param_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int param_base_hi : 32;
    } reg;
} SOC_NPU_BS_TS_PARAM_BASE_HI_UNION;
#endif
#define SOC_NPU_BS_TS_PARAM_BASE_HI_param_base_hi_START (0)
#define SOC_NPU_BS_TS_PARAM_BASE_HI_param_base_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_ssid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_BS_TS_SMMU_SUBSID_UNION;
#endif
#define SOC_NPU_BS_TS_SMMU_SUBSID_smmu_ssid_START (0)
#define SOC_NPU_BS_TS_SMMU_SUBSID_smmu_ssid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_in_main : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_TS_TASK_CFG_UNION;
#endif
#define SOC_NPU_BS_TS_TASK_CFG_l2_in_main_START (0)
#define SOC_NPU_BS_TS_TASK_CFG_l2_in_main_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_dim : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_BS_TS_BLK_NUM_UNION;
#endif
#define SOC_NPU_BS_TS_BLK_NUM_blk_dim_START (0)
#define SOC_NPU_BS_TS_BLK_NUM_blk_dim_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_main_base_lo : 32;
    } reg;
} SOC_NPU_BS_TS_DATA_MAIN_BASE_LO_UNION;
#endif
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_LO_data_main_base_lo_START (0)
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_LO_data_main_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_main_base_hi : 32;
    } reg;
} SOC_NPU_BS_TS_DATA_MAIN_BASE_HI_UNION;
#endif
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_HI_data_main_base_hi_START (0)
#define SOC_NPU_BS_TS_DATA_MAIN_BASE_HI_data_main_base_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ub_base : 32;
    } reg;
} SOC_NPU_BS_TS_UB_BASE_UNION;
#endif
#define SOC_NPU_BS_TS_UB_BASE_ub_base_START (0)
#define SOC_NPU_BS_TS_UB_BASE_ub_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_size : 32;
    } reg;
} SOC_NPU_BS_TS_DATA_SIZE_UNION;
#endif
#define SOC_NPU_BS_TS_DATA_SIZE_data_size_START (0)
#define SOC_NPU_BS_TS_DATA_SIZE_data_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_vaddr_base_lo : 32;
    } reg;
} SOC_NPU_BS_TS_L2_VADDR_BASE_LO_UNION;
#endif
#define SOC_NPU_BS_TS_L2_VADDR_BASE_LO_l2_vaddr_base_lo_START (0)
#define SOC_NPU_BS_TS_L2_VADDR_BASE_LO_l2_vaddr_base_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_vaddr_base_hi : 32;
    } reg;
} SOC_NPU_BS_TS_L2_VADDR_BASE_HI_UNION;
#endif
#define SOC_NPU_BS_TS_L2_VADDR_BASE_HI_l2_vaddr_base_hi_START (0)
#define SOC_NPU_BS_TS_L2_VADDR_BASE_HI_l2_vaddr_base_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_page_valid : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_BS_TS_L2_REMAP_CFG_UNION;
#endif
#define SOC_NPU_BS_TS_L2_REMAP_CFG_num_page_valid_START (0)
#define SOC_NPU_BS_TS_L2_REMAP_CFG_num_page_valid_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_remap_addr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_BS_TS_L2_REMAP_ENTRY_UNION;
#endif
#define SOC_NPU_BS_TS_L2_REMAP_ENTRY_l2_remap_addr_START (0)
#define SOC_NPU_BS_TS_L2_REMAP_ENTRY_l2_remap_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profiling_cnt_lo : 32;
    } reg;
} SOC_NPU_BS_TS_PROFILING_CNT_LO_UNION;
#endif
#define SOC_NPU_BS_TS_PROFILING_CNT_LO_profiling_cnt_lo_START (0)
#define SOC_NPU_BS_TS_PROFILING_CNT_LO_profiling_cnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profiling_cnt_hi : 32;
    } reg;
} SOC_NPU_BS_TS_PROFILING_CNT_HI_UNION;
#endif
#define SOC_NPU_BS_TS_PROFILING_CNT_HI_profiling_cnt_hi_START (0)
#define SOC_NPU_BS_TS_PROFILING_CNT_HI_profiling_cnt_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profiling_cyc_cnt_lo : 32;
    } reg;
} SOC_NPU_BS_TS_CYC_CNT_LO_UNION;
#endif
#define SOC_NPU_BS_TS_CYC_CNT_LO_profiling_cyc_cnt_lo_START (0)
#define SOC_NPU_BS_TS_CYC_CNT_LO_profiling_cyc_cnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profiling_cyc_cnt_hi : 32;
    } reg;
} SOC_NPU_BS_TS_CYC_CNT_HI_UNION;
#endif
#define SOC_NPU_BS_TS_CYC_CNT_HI_profiling_cyc_cnt_hi_START (0)
#define SOC_NPU_BS_TS_CYC_CNT_HI_profiling_cyc_cnt_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int overflow_cyc_cnt_lo : 32;
    } reg;
} SOC_NPU_BS_TS_OV_MIN_CNT_LO_UNION;
#endif
#define SOC_NPU_BS_TS_OV_MIN_CNT_LO_overflow_cyc_cnt_lo_START (0)
#define SOC_NPU_BS_TS_OV_MIN_CNT_LO_overflow_cyc_cnt_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int overflow_cyc_cnt_hi : 32;
    } reg;
} SOC_NPU_BS_TS_OV_MIN_CNT_HI_UNION;
#endif
#define SOC_NPU_BS_TS_OV_MIN_CNT_HI_overflow_cyc_cnt_hi_START (0)
#define SOC_NPU_BS_TS_OV_MIN_CNT_HI_overflow_cyc_cnt_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int overflow_occur : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_TS_OV_FLOW_UNION;
#endif
#define SOC_NPU_BS_TS_OV_FLOW_overflow_occur_START (0)
#define SOC_NPU_BS_TS_OV_FLOW_overflow_occur_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profiling_range_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_BS_TS_PROFILING_RANGE_EN_UNION;
#endif
#define SOC_NPU_BS_TS_PROFILING_RANGE_EN_profiling_range_en_START (0)
#define SOC_NPU_BS_TS_PROFILING_RANGE_EN_profiling_range_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int profile_start_blk_num : 16;
        unsigned int profile_stop_blk_num : 16;
    } reg;
} SOC_NPU_BS_TS_PROFILING_RANGE_UNION;
#endif
#define SOC_NPU_BS_TS_PROFILING_RANGE_profile_start_blk_num_START (0)
#define SOC_NPU_BS_TS_PROFILING_RANGE_profile_start_blk_num_END (15)
#define SOC_NPU_BS_TS_PROFILING_RANGE_profile_stop_blk_num_START (16)
#define SOC_NPU_BS_TS_PROFILING_RANGE_profile_stop_blk_num_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
