#ifndef __SOC_NPU_TBU_TOP_INTERFACE_H__
#define __SOC_NPU_TBU_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x004UL))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_0_ADDR(base) ((base) + (0x10UL))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_0_ADDR(base) ((base) + (0x14UL))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_1_ADDR(base) ((base) + (0x20UL))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_1_ADDR(base) ((base) + (0x24UL))
#else
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x000))
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x004))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_0_ADDR(base) ((base) + (0x10))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_0_ADDR(base) ((base) + (0x14))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_1_ADDR(base) ((base) + (0x20))
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_1_ADDR(base) ((base) + (0x24))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tbu0_soft_rst_req : 1;
        unsigned int tbu1_soft_rst_req : 1;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int tbu0_soft_rst_force_ack : 1;
        unsigned int tbu1_soft_rst_force_ack : 1;
        unsigned int reserved_3 : 21;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu0_soft_rst_req_START (1)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu0_soft_rst_req_END (1)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu1_soft_rst_req_START (2)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu1_soft_rst_req_END (2)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu0_soft_rst_force_ack_START (9)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu0_soft_rst_force_ack_END (9)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu1_soft_rst_force_ack_START (10)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_REQ_tbu1_soft_rst_force_ack_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tbu0_soft_rst_ack : 1;
        unsigned int tbu1_soft_rst_ack : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_tbu0_soft_rst_ack_START (1)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_tbu0_soft_rst_ack_END (1)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_tbu1_soft_rst_ack_START (2)
#define SOC_NPU_TBU_TOP_SMMU_SOFT_RST_ACK_tbu1_soft_rst_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat0_0 : 32;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_0_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_0_tbu_soft_rst_stat0_0_START (0)
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_0_tbu_soft_rst_stat0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat1_0 : 32;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_0_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_0_tbu_soft_rst_stat1_0_START (0)
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_0_tbu_soft_rst_stat1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat0_1 : 32;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_1_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_1_tbu_soft_rst_stat0_1_START (0)
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE0_1_tbu_soft_rst_stat0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat1_1 : 32;
    } reg;
} SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_1_UNION;
#endif
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_1_tbu_soft_rst_stat1_1_START (0)
#define SOC_NPU_TBU_TOP_SMMU_TBU_SOFT_RST_STATE1_1_tbu_soft_rst_stat1_1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
