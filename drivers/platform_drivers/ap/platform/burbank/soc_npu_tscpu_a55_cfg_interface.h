#ifndef __SOC_NPU_TSCPU_A55_CFG_INTERFACE_H__
#define __SOC_NPU_TSCPU_A55_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_CLR_CFG_REG_ADDR(base) ((base) + (0x874UL))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_LO_ADDR(base) ((base) + (0xC80UL))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_HI_ADDR(base) ((base) + (0xC84UL))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_LO_ADDR(base) ((base) + (0xC88UL))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_HI_ADDR(base) ((base) + (0xC8CUL))
#else
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_CLR_CFG_REG_ADDR(base) ((base) + (0x874))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_LO_ADDR(base) ((base) + (0xC80))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_HI_ADDR(base) ((base) + (0xC84))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_LO_ADDR(base) ((base) + (0xC88))
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_HI_ADDR(base) ((base) + (0xC8C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latch_debug_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_CLR_CFG_REG_UNION;
#endif
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_CLR_CFG_REG_latch_debug_en_START (0)
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_CLR_CFG_REG_latch_debug_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_pc_low : 32;
    } reg;
} SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_LO_UNION;
#endif
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_LO_core_pc_low_START (0)
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_LO_core_pc_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_pc_high : 32;
    } reg;
} SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_HI_UNION;
#endif
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_HI_core_pc_high_START (0)
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_PC_HI_core_pc_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_sp_low : 32;
    } reg;
} SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_LO_UNION;
#endif
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_LO_core_sp_low_START (0)
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_LO_core_sp_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_sp_high : 32;
    } reg;
} SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_HI_UNION;
#endif
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_HI_core_sp_high_START (0)
#define SOC_NPU_TSCPU_A55_CFG_ANANKE_DBG_SP_HI_core_sp_high_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
