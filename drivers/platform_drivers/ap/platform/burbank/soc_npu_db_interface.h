#ifndef __SOC_NPU_DB_INTERFACE_H__
#define __SOC_NPU_DB_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_DB_DB_INT_SUMMARY_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_DB_DB_INT_MASK0_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_DB_DB_INT_MASK1_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_DB_DB_INT_MASK2_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_DB_DB_INT_MASK3_ADDR(base) ((base) + (0x002cUL))
#define SOC_NPU_DB_DB_INT_STATUS0_ADDR(base) ((base) + (0x00a0UL))
#define SOC_NPU_DB_DB_INT_STATUS1_ADDR(base) ((base) + (0x00a4UL))
#define SOC_NPU_DB_DB_INT_STATUS2_ADDR(base) ((base) + (0x00a8UL))
#define SOC_NPU_DB_DB_INT_STATUS3_ADDR(base) ((base) + (0x00acUL))
#define SOC_NPU_DB_DB_SEC_CTRL_ADDR(base) ((base) + (0x0200UL))
#else
#define SOC_NPU_DB_DB_INT_SUMMARY_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_DB_DB_INT_MASK0_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_DB_DB_INT_MASK1_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_DB_DB_INT_MASK2_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_DB_DB_INT_MASK3_ADDR(base) ((base) + (0x002c))
#define SOC_NPU_DB_DB_INT_STATUS0_ADDR(base) ((base) + (0x00a0))
#define SOC_NPU_DB_DB_INT_STATUS1_ADDR(base) ((base) + (0x00a4))
#define SOC_NPU_DB_DB_INT_STATUS2_ADDR(base) ((base) + (0x00a8))
#define SOC_NPU_DB_DB_INT_STATUS3_ADDR(base) ((base) + (0x00ac))
#define SOC_NPU_DB_DB_SEC_CTRL_ADDR(base) ((base) + (0x0200))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_summary : 32;
    } reg;
} SOC_NPU_DB_DB_INT_SUMMARY_UNION;
#endif
#define SOC_NPU_DB_DB_INT_SUMMARY_db_int_summary_START (0)
#define SOC_NPU_DB_DB_INT_SUMMARY_db_int_summary_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_mask0 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK0_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK0_db_int_mask0_START (0)
#define SOC_NPU_DB_DB_INT_MASK0_db_int_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_mask1 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK1_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK1_db_int_mask1_START (0)
#define SOC_NPU_DB_DB_INT_MASK1_db_int_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_mask2 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK2_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK2_db_int_mask2_START (0)
#define SOC_NPU_DB_DB_INT_MASK2_db_int_mask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_mask3 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK3_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK3_db_int_mask3_START (0)
#define SOC_NPU_DB_DB_INT_MASK3_db_int_mask3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_status0 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS0_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS0_db_int_status0_START (0)
#define SOC_NPU_DB_DB_INT_STATUS0_db_int_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_status1 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS1_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS1_db_int_status1_START (0)
#define SOC_NPU_DB_DB_INT_STATUS1_db_int_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_status2 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS2_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS2_db_int_status2_START (0)
#define SOC_NPU_DB_DB_INT_STATUS2_db_int_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_int_status3 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS3_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS3_db_int_status3_START (0)
#define SOC_NPU_DB_DB_INT_STATUS3_db_int_status3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int db_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_DB_DB_SEC_CTRL_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_CTRL_db_sec_en_START (0)
#define SOC_NPU_DB_DB_SEC_CTRL_db_sec_en_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
