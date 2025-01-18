#ifndef __SOC_NPU_TCU_TOP_INTERFACE_H__
#define __SOC_NPU_TCU_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x004UL))
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE0_ADDR(base) ((base) + (0x08UL))
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE1_ADDR(base) ((base) + (0x0CUL))
#else
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x000))
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x004))
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE0_ADDR(base) ((base) + (0x08))
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE1_ADDR(base) ((base) + (0x0C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 5;
        unsigned int tcu_soft_rst_force_ack : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 21;
    } reg;
} SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_UNION;
#endif
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_tcu_soft_rst_req_START (0)
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_tcu_soft_rst_req_END (0)
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_tcu_soft_rst_force_ack_START (8)
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_REQ_tcu_soft_rst_force_ack_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 29;
    } reg;
} SOC_NPU_TCU_TOP_SMMU_SOFT_RST_ACK_UNION;
#endif
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_ACK_tcu_soft_rst_ack_START (0)
#define SOC_NPU_TCU_TOP_SMMU_SOFT_RST_ACK_tcu_soft_rst_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_stat0 : 32;
    } reg;
} SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE0_UNION;
#endif
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE0_tcu_soft_rst_stat0_START (0)
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE0_tcu_soft_rst_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_stat1 : 32;
    } reg;
} SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE1_UNION;
#endif
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE1_tcu_soft_rst_stat1_START (0)
#define SOC_NPU_TCU_TOP_SMMU_TCU_SOFT_RST_STATE1_tcu_soft_rst_stat1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
