#ifndef __SOC_CS_REPLICATOR_INTERFACE_H__
#define __SOC_CS_REPLICATOR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_ADDR(base) ((base) + (0x000UL))
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_ADDR(base) ((base) + (0x004UL))
#define SOC_CS_REPLICATOR_REPLICATOR_LAR_ADDR(base) ((base) + (0xFB0UL))
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_ADDR(base) ((base) + (0xFB4UL))
#else
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_ADDR(base) ((base) + (0x000))
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_ADDR(base) ((base) + (0x004))
#define SOC_CS_REPLICATOR_REPLICATOR_LAR_ADDR(base) ((base) + (0xFB0))
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_ADDR(base) ((base) + (0xFB4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int id0_0_f : 1;
        unsigned int id0_10_1f : 1;
        unsigned int id0_20_2f : 1;
        unsigned int id0_30_3f : 1;
        unsigned int id0_40_4f : 1;
        unsigned int id0_50_5f : 1;
        unsigned int id0_60_6f : 1;
        unsigned int id0_70_7f : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_UNION;
#endif
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_0_f_START (0)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_0_f_END (0)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_10_1f_START (1)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_10_1f_END (1)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_20_2f_START (2)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_20_2f_END (2)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_30_3f_START (3)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_30_3f_END (3)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_40_4f_START (4)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_40_4f_END (4)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_50_5f_START (5)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_50_5f_END (5)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_60_6f_START (6)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_60_6f_END (6)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_70_7f_START (7)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER0_REG_id0_70_7f_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int id1_0_f : 1;
        unsigned int id1_10_1f : 1;
        unsigned int id1_20_2f : 1;
        unsigned int id1_30_3f : 1;
        unsigned int id1_40_4f : 1;
        unsigned int id1_50_5f : 1;
        unsigned int id1_60_6f : 1;
        unsigned int id1_70_7f : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_UNION;
#endif
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_0_f_START (0)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_0_f_END (0)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_10_1f_START (1)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_10_1f_END (1)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_20_2f_START (2)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_20_2f_END (2)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_30_3f_START (3)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_30_3f_END (3)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_40_4f_START (4)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_40_4f_END (4)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_50_5f_START (5)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_50_5f_END (5)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_60_6f_START (6)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_60_6f_END (6)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_70_7f_START (7)
#define SOC_CS_REPLICATOR_REPLICATOR_IDFILTER1_REG_id1_70_7f_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key : 32;
    } reg;
} SOC_CS_REPLICATOR_REPLICATOR_LAR_UNION;
#endif
#define SOC_CS_REPLICATOR_REPLICATOR_LAR_key_START (0)
#define SOC_CS_REPLICATOR_REPLICATOR_LAR_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sli : 1;
        unsigned int slk : 1;
        unsigned int ntt : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CS_REPLICATOR_REPLICATOR_LSR_UNION;
#endif
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_sli_START (0)
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_sli_END (0)
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_slk_START (1)
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_slk_END (1)
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_ntt_START (2)
#define SOC_CS_REPLICATOR_REPLICATOR_LSR_ntt_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
