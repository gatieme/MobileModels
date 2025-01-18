#ifndef __SOC_IOCR_IOCG_INTERFACE_H__
#define __SOC_IOCR_IOCG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOCR_IOCG_SE_04_ADDR(base) ((base) + (0xF10UL))
#define SOC_IOCR_IOCG_SE_05_ADDR(base) ((base) + (0xF14UL))
#define SOC_IOCR_IOCG_SE_06_ADDR(base) ((base) + (0xF18UL))
#define SOC_IOCR_IOCG_SE_07_ADDR(base) ((base) + (0xF1CUL))
#define SOC_IOCR_IOCG_SE_08_ADDR(base) ((base) + (0xF20UL))
#define SOC_IOCR_IOCG_043_ADDR(base) ((base) + (0x8ACUL))
#define SOC_IOCR_IOCG_044_ADDR(base) ((base) + (0x8B0UL))
#define SOC_IOCR_IOCG_045_ADDR(base) ((base) + (0x8B4UL))
#define SOC_IOCR_IOCG_SE_09_ADDR(base) ((base) + (0xF24UL))
#define SOC_IOCR_IOCG_SE_10_ADDR(base) ((base) + (0xF28UL))
#define SOC_IOCR_IOCG_SE_11_ADDR(base) ((base) + (0xF2CUL))
#define SOC_IOCR_IOCG_SE_12_ADDR(base) ((base) + (0xF30UL))
#define SOC_IOCR_IOCG_046_ADDR(base) ((base) + (0x8B8UL))
#define SOC_IOCR_IOCG_047_ADDR(base) ((base) + (0x8BCUL))
#define SOC_IOCR_IOCG_048_ADDR(base) ((base) + (0x8C0UL))
#define SOC_IOCR_IOCG_049_ADDR(base) ((base) + (0x8C4UL))
#define SOC_IOCR_IOCG_050_ADDR(base) ((base) + (0x8C8UL))
#define SOC_IOCR_IOCG_051_ADDR(base) ((base) + (0x8CCUL))
#define SOC_IOCR_IOCG_052_ADDR(base) ((base) + (0x8D0UL))
#define SOC_IOCR_IOCG_053_ADDR(base) ((base) + (0x8D4UL))
#define SOC_IOCR_IOCG_054_ADDR(base) ((base) + (0x8D8UL))
#define SOC_IOCR_IOCG_055_ADDR(base) ((base) + (0x8DCUL))
#define SOC_IOCR_IOCG_056_ADDR(base) ((base) + (0x8E0UL))
#define SOC_IOCR_IOCG_057_ADDR(base) ((base) + (0x8E4UL))
#define SOC_IOCR_IOCG_058_ADDR(base) ((base) + (0x8E8UL))
#define SOC_IOCR_IOCG_059_ADDR(base) ((base) + (0x8ECUL))
#define SOC_IOCR_IOCG_060_ADDR(base) ((base) + (0x8F0UL))
#define SOC_IOCR_IOCG_061_ADDR(base) ((base) + (0x8F4UL))
#else
#define SOC_IOCR_IOCG_SE_04_ADDR(base) ((base) + (0xF10))
#define SOC_IOCR_IOCG_SE_05_ADDR(base) ((base) + (0xF14))
#define SOC_IOCR_IOCG_SE_06_ADDR(base) ((base) + (0xF18))
#define SOC_IOCR_IOCG_SE_07_ADDR(base) ((base) + (0xF1C))
#define SOC_IOCR_IOCG_SE_08_ADDR(base) ((base) + (0xF20))
#define SOC_IOCR_IOCG_043_ADDR(base) ((base) + (0x8AC))
#define SOC_IOCR_IOCG_044_ADDR(base) ((base) + (0x8B0))
#define SOC_IOCR_IOCG_045_ADDR(base) ((base) + (0x8B4))
#define SOC_IOCR_IOCG_SE_09_ADDR(base) ((base) + (0xF24))
#define SOC_IOCR_IOCG_SE_10_ADDR(base) ((base) + (0xF28))
#define SOC_IOCR_IOCG_SE_11_ADDR(base) ((base) + (0xF2C))
#define SOC_IOCR_IOCG_SE_12_ADDR(base) ((base) + (0xF30))
#define SOC_IOCR_IOCG_046_ADDR(base) ((base) + (0x8B8))
#define SOC_IOCR_IOCG_047_ADDR(base) ((base) + (0x8BC))
#define SOC_IOCR_IOCG_048_ADDR(base) ((base) + (0x8C0))
#define SOC_IOCR_IOCG_049_ADDR(base) ((base) + (0x8C4))
#define SOC_IOCR_IOCG_050_ADDR(base) ((base) + (0x8C8))
#define SOC_IOCR_IOCG_051_ADDR(base) ((base) + (0x8CC))
#define SOC_IOCR_IOCG_052_ADDR(base) ((base) + (0x8D0))
#define SOC_IOCR_IOCG_053_ADDR(base) ((base) + (0x8D4))
#define SOC_IOCR_IOCG_054_ADDR(base) ((base) + (0x8D8))
#define SOC_IOCR_IOCG_055_ADDR(base) ((base) + (0x8DC))
#define SOC_IOCR_IOCG_056_ADDR(base) ((base) + (0x8E0))
#define SOC_IOCR_IOCG_057_ADDR(base) ((base) + (0x8E4))
#define SOC_IOCR_IOCG_058_ADDR(base) ((base) + (0x8E8))
#define SOC_IOCR_IOCG_059_ADDR(base) ((base) + (0x8EC))
#define SOC_IOCR_IOCG_060_ADDR(base) ((base) + (0x8F0))
#define SOC_IOCR_IOCG_061_ADDR(base) ((base) + (0x8F4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_04_pu : 1;
        unsigned int iocg_se_04_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_04_st : 1;
        unsigned int iocg_se_04_ds0 : 1;
        unsigned int iocg_se_04_ds1 : 1;
        unsigned int iocg_se_04_ds2 : 1;
        unsigned int iocg_se_04_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_04_UNION;
#endif
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_pu_START (0)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_pu_END (0)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_pd_START (1)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_pd_END (1)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_st_START (3)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_st_END (3)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds0_START (4)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds0_END (4)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds1_START (5)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds1_END (5)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds2_START (6)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_ds2_END (6)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_sl_START (7)
#define SOC_IOCR_IOCG_SE_04_iocg_se_04_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_05_pu : 1;
        unsigned int iocg_se_05_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_05_st : 1;
        unsigned int iocg_se_05_ds0 : 1;
        unsigned int iocg_se_05_ds1 : 1;
        unsigned int iocg_se_05_ds2 : 1;
        unsigned int iocg_se_05_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_05_UNION;
#endif
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_pu_START (0)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_pu_END (0)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_pd_START (1)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_pd_END (1)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_st_START (3)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_st_END (3)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds0_START (4)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds0_END (4)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds1_START (5)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds1_END (5)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds2_START (6)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_ds2_END (6)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_sl_START (7)
#define SOC_IOCR_IOCG_SE_05_iocg_se_05_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_06_pu : 1;
        unsigned int iocg_se_06_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_06_st : 1;
        unsigned int iocg_se_06_ds0 : 1;
        unsigned int iocg_se_06_ds1 : 1;
        unsigned int iocg_se_06_ds2 : 1;
        unsigned int iocg_se_06_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_06_UNION;
#endif
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_pu_START (0)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_pu_END (0)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_pd_START (1)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_pd_END (1)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_st_START (3)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_st_END (3)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds0_START (4)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds0_END (4)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds1_START (5)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds1_END (5)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds2_START (6)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_ds2_END (6)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_sl_START (7)
#define SOC_IOCR_IOCG_SE_06_iocg_se_06_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_07_pu : 1;
        unsigned int iocg_se_07_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_07_st : 1;
        unsigned int iocg_se_07_ds0 : 1;
        unsigned int iocg_se_07_ds1 : 1;
        unsigned int iocg_se_07_ds2 : 1;
        unsigned int iocg_se_07_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_07_UNION;
#endif
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_pu_START (0)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_pu_END (0)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_pd_START (1)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_pd_END (1)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_st_START (3)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_st_END (3)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds0_START (4)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds0_END (4)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds1_START (5)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds1_END (5)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds2_START (6)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_ds2_END (6)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_sl_START (7)
#define SOC_IOCR_IOCG_SE_07_iocg_se_07_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_08_pu : 1;
        unsigned int iocg_se_08_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_08_st : 1;
        unsigned int iocg_se_08_ds0 : 1;
        unsigned int iocg_se_08_ds1 : 1;
        unsigned int iocg_se_08_ds2 : 1;
        unsigned int iocg_se_08_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_08_UNION;
#endif
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_pu_START (0)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_pu_END (0)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_pd_START (1)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_pd_END (1)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_st_START (3)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_st_END (3)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds0_START (4)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds0_END (4)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds1_START (5)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds1_END (5)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds2_START (6)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_ds2_END (6)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_sl_START (7)
#define SOC_IOCR_IOCG_SE_08_iocg_se_08_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_043_pu : 1;
        unsigned int iocg_043_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_043_st : 1;
        unsigned int iocg_043_ds0 : 1;
        unsigned int iocg_043_ds1 : 1;
        unsigned int iocg_043_ds2 : 1;
        unsigned int iocg_043_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_043_UNION;
#endif
#define SOC_IOCR_IOCG_043_iocg_043_pu_START (0)
#define SOC_IOCR_IOCG_043_iocg_043_pu_END (0)
#define SOC_IOCR_IOCG_043_iocg_043_pd_START (1)
#define SOC_IOCR_IOCG_043_iocg_043_pd_END (1)
#define SOC_IOCR_IOCG_043_iocg_043_st_START (3)
#define SOC_IOCR_IOCG_043_iocg_043_st_END (3)
#define SOC_IOCR_IOCG_043_iocg_043_ds0_START (4)
#define SOC_IOCR_IOCG_043_iocg_043_ds0_END (4)
#define SOC_IOCR_IOCG_043_iocg_043_ds1_START (5)
#define SOC_IOCR_IOCG_043_iocg_043_ds1_END (5)
#define SOC_IOCR_IOCG_043_iocg_043_ds2_START (6)
#define SOC_IOCR_IOCG_043_iocg_043_ds2_END (6)
#define SOC_IOCR_IOCG_043_iocg_043_sl_START (7)
#define SOC_IOCR_IOCG_043_iocg_043_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_044_pu : 1;
        unsigned int iocg_044_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_044_st : 1;
        unsigned int iocg_044_ds0 : 1;
        unsigned int iocg_044_ds1 : 1;
        unsigned int iocg_044_ds2 : 1;
        unsigned int iocg_044_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_044_UNION;
#endif
#define SOC_IOCR_IOCG_044_iocg_044_pu_START (0)
#define SOC_IOCR_IOCG_044_iocg_044_pu_END (0)
#define SOC_IOCR_IOCG_044_iocg_044_pd_START (1)
#define SOC_IOCR_IOCG_044_iocg_044_pd_END (1)
#define SOC_IOCR_IOCG_044_iocg_044_st_START (3)
#define SOC_IOCR_IOCG_044_iocg_044_st_END (3)
#define SOC_IOCR_IOCG_044_iocg_044_ds0_START (4)
#define SOC_IOCR_IOCG_044_iocg_044_ds0_END (4)
#define SOC_IOCR_IOCG_044_iocg_044_ds1_START (5)
#define SOC_IOCR_IOCG_044_iocg_044_ds1_END (5)
#define SOC_IOCR_IOCG_044_iocg_044_ds2_START (6)
#define SOC_IOCR_IOCG_044_iocg_044_ds2_END (6)
#define SOC_IOCR_IOCG_044_iocg_044_sl_START (7)
#define SOC_IOCR_IOCG_044_iocg_044_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_045_pu : 1;
        unsigned int iocg_045_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_045_st : 1;
        unsigned int iocg_045_ds0 : 1;
        unsigned int iocg_045_ds1 : 1;
        unsigned int iocg_045_ds2 : 1;
        unsigned int iocg_045_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_045_UNION;
#endif
#define SOC_IOCR_IOCG_045_iocg_045_pu_START (0)
#define SOC_IOCR_IOCG_045_iocg_045_pu_END (0)
#define SOC_IOCR_IOCG_045_iocg_045_pd_START (1)
#define SOC_IOCR_IOCG_045_iocg_045_pd_END (1)
#define SOC_IOCR_IOCG_045_iocg_045_st_START (3)
#define SOC_IOCR_IOCG_045_iocg_045_st_END (3)
#define SOC_IOCR_IOCG_045_iocg_045_ds0_START (4)
#define SOC_IOCR_IOCG_045_iocg_045_ds0_END (4)
#define SOC_IOCR_IOCG_045_iocg_045_ds1_START (5)
#define SOC_IOCR_IOCG_045_iocg_045_ds1_END (5)
#define SOC_IOCR_IOCG_045_iocg_045_ds2_START (6)
#define SOC_IOCR_IOCG_045_iocg_045_ds2_END (6)
#define SOC_IOCR_IOCG_045_iocg_045_sl_START (7)
#define SOC_IOCR_IOCG_045_iocg_045_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_09_pu : 1;
        unsigned int iocg_se_09_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_09_st : 1;
        unsigned int iocg_se_09_ds0 : 1;
        unsigned int iocg_se_09_ds1 : 1;
        unsigned int iocg_se_09_ds2 : 1;
        unsigned int iocg_se_09_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_09_UNION;
#endif
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_pu_START (0)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_pu_END (0)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_pd_START (1)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_pd_END (1)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_st_START (3)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_st_END (3)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds0_START (4)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds0_END (4)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds1_START (5)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds1_END (5)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds2_START (6)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_ds2_END (6)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_sl_START (7)
#define SOC_IOCR_IOCG_SE_09_iocg_se_09_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_10_pu : 1;
        unsigned int iocg_se_10_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_10_st : 1;
        unsigned int iocg_se_10_ds0 : 1;
        unsigned int iocg_se_10_ds1 : 1;
        unsigned int iocg_se_10_ds2 : 1;
        unsigned int iocg_se_10_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_10_UNION;
#endif
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_pu_START (0)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_pu_END (0)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_pd_START (1)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_pd_END (1)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_st_START (3)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_st_END (3)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds0_START (4)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds0_END (4)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds1_START (5)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds1_END (5)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds2_START (6)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_ds2_END (6)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_sl_START (7)
#define SOC_IOCR_IOCG_SE_10_iocg_se_10_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_11_pu : 1;
        unsigned int iocg_se_11_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_11_st : 1;
        unsigned int iocg_se_11_ds0 : 1;
        unsigned int iocg_se_11_ds1 : 1;
        unsigned int iocg_se_11_ds2 : 1;
        unsigned int iocg_se_11_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_11_UNION;
#endif
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_pu_START (0)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_pu_END (0)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_pd_START (1)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_pd_END (1)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_st_START (3)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_st_END (3)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds0_START (4)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds0_END (4)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds1_START (5)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds1_END (5)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds2_START (6)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_ds2_END (6)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_sl_START (7)
#define SOC_IOCR_IOCG_SE_11_iocg_se_11_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_12_pu : 1;
        unsigned int iocg_se_12_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_12_st : 1;
        unsigned int iocg_se_12_ds0 : 1;
        unsigned int iocg_se_12_ds1 : 1;
        unsigned int iocg_se_12_ds2 : 1;
        unsigned int iocg_se_12_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_SE_12_UNION;
#endif
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_pu_START (0)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_pu_END (0)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_pd_START (1)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_pd_END (1)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_st_START (3)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_st_END (3)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds0_START (4)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds0_END (4)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds1_START (5)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds1_END (5)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds2_START (6)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_ds2_END (6)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_sl_START (7)
#define SOC_IOCR_IOCG_SE_12_iocg_se_12_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_046_pu : 1;
        unsigned int iocg_046_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_046_st : 1;
        unsigned int iocg_046_ds0 : 1;
        unsigned int iocg_046_ds1 : 1;
        unsigned int iocg_046_ds2 : 1;
        unsigned int iocg_046_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_046_UNION;
#endif
#define SOC_IOCR_IOCG_046_iocg_046_pu_START (0)
#define SOC_IOCR_IOCG_046_iocg_046_pu_END (0)
#define SOC_IOCR_IOCG_046_iocg_046_pd_START (1)
#define SOC_IOCR_IOCG_046_iocg_046_pd_END (1)
#define SOC_IOCR_IOCG_046_iocg_046_st_START (3)
#define SOC_IOCR_IOCG_046_iocg_046_st_END (3)
#define SOC_IOCR_IOCG_046_iocg_046_ds0_START (4)
#define SOC_IOCR_IOCG_046_iocg_046_ds0_END (4)
#define SOC_IOCR_IOCG_046_iocg_046_ds1_START (5)
#define SOC_IOCR_IOCG_046_iocg_046_ds1_END (5)
#define SOC_IOCR_IOCG_046_iocg_046_ds2_START (6)
#define SOC_IOCR_IOCG_046_iocg_046_ds2_END (6)
#define SOC_IOCR_IOCG_046_iocg_046_sl_START (7)
#define SOC_IOCR_IOCG_046_iocg_046_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_047_pu : 1;
        unsigned int iocg_047_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_047_st : 1;
        unsigned int iocg_047_ds0 : 1;
        unsigned int iocg_047_ds1 : 1;
        unsigned int iocg_047_ds2 : 1;
        unsigned int iocg_047_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_047_UNION;
#endif
#define SOC_IOCR_IOCG_047_iocg_047_pu_START (0)
#define SOC_IOCR_IOCG_047_iocg_047_pu_END (0)
#define SOC_IOCR_IOCG_047_iocg_047_pd_START (1)
#define SOC_IOCR_IOCG_047_iocg_047_pd_END (1)
#define SOC_IOCR_IOCG_047_iocg_047_st_START (3)
#define SOC_IOCR_IOCG_047_iocg_047_st_END (3)
#define SOC_IOCR_IOCG_047_iocg_047_ds0_START (4)
#define SOC_IOCR_IOCG_047_iocg_047_ds0_END (4)
#define SOC_IOCR_IOCG_047_iocg_047_ds1_START (5)
#define SOC_IOCR_IOCG_047_iocg_047_ds1_END (5)
#define SOC_IOCR_IOCG_047_iocg_047_ds2_START (6)
#define SOC_IOCR_IOCG_047_iocg_047_ds2_END (6)
#define SOC_IOCR_IOCG_047_iocg_047_sl_START (7)
#define SOC_IOCR_IOCG_047_iocg_047_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_048_pu : 1;
        unsigned int iocg_048_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_048_st : 1;
        unsigned int iocg_048_ds0 : 1;
        unsigned int iocg_048_ds1 : 1;
        unsigned int iocg_048_ds2 : 1;
        unsigned int iocg_048_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_048_UNION;
#endif
#define SOC_IOCR_IOCG_048_iocg_048_pu_START (0)
#define SOC_IOCR_IOCG_048_iocg_048_pu_END (0)
#define SOC_IOCR_IOCG_048_iocg_048_pd_START (1)
#define SOC_IOCR_IOCG_048_iocg_048_pd_END (1)
#define SOC_IOCR_IOCG_048_iocg_048_st_START (3)
#define SOC_IOCR_IOCG_048_iocg_048_st_END (3)
#define SOC_IOCR_IOCG_048_iocg_048_ds0_START (4)
#define SOC_IOCR_IOCG_048_iocg_048_ds0_END (4)
#define SOC_IOCR_IOCG_048_iocg_048_ds1_START (5)
#define SOC_IOCR_IOCG_048_iocg_048_ds1_END (5)
#define SOC_IOCR_IOCG_048_iocg_048_ds2_START (6)
#define SOC_IOCR_IOCG_048_iocg_048_ds2_END (6)
#define SOC_IOCR_IOCG_048_iocg_048_sl_START (7)
#define SOC_IOCR_IOCG_048_iocg_048_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_049_pu : 1;
        unsigned int iocg_049_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_049_st : 1;
        unsigned int iocg_049_ds0 : 1;
        unsigned int iocg_049_ds1 : 1;
        unsigned int iocg_049_ds2 : 1;
        unsigned int iocg_049_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_049_UNION;
#endif
#define SOC_IOCR_IOCG_049_iocg_049_pu_START (0)
#define SOC_IOCR_IOCG_049_iocg_049_pu_END (0)
#define SOC_IOCR_IOCG_049_iocg_049_pd_START (1)
#define SOC_IOCR_IOCG_049_iocg_049_pd_END (1)
#define SOC_IOCR_IOCG_049_iocg_049_st_START (3)
#define SOC_IOCR_IOCG_049_iocg_049_st_END (3)
#define SOC_IOCR_IOCG_049_iocg_049_ds0_START (4)
#define SOC_IOCR_IOCG_049_iocg_049_ds0_END (4)
#define SOC_IOCR_IOCG_049_iocg_049_ds1_START (5)
#define SOC_IOCR_IOCG_049_iocg_049_ds1_END (5)
#define SOC_IOCR_IOCG_049_iocg_049_ds2_START (6)
#define SOC_IOCR_IOCG_049_iocg_049_ds2_END (6)
#define SOC_IOCR_IOCG_049_iocg_049_sl_START (7)
#define SOC_IOCR_IOCG_049_iocg_049_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_050_pu : 1;
        unsigned int iocg_050_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_050_st : 1;
        unsigned int iocg_050_ds0 : 1;
        unsigned int iocg_050_ds1 : 1;
        unsigned int iocg_050_ds2 : 1;
        unsigned int iocg_050_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_050_UNION;
#endif
#define SOC_IOCR_IOCG_050_iocg_050_pu_START (0)
#define SOC_IOCR_IOCG_050_iocg_050_pu_END (0)
#define SOC_IOCR_IOCG_050_iocg_050_pd_START (1)
#define SOC_IOCR_IOCG_050_iocg_050_pd_END (1)
#define SOC_IOCR_IOCG_050_iocg_050_st_START (3)
#define SOC_IOCR_IOCG_050_iocg_050_st_END (3)
#define SOC_IOCR_IOCG_050_iocg_050_ds0_START (4)
#define SOC_IOCR_IOCG_050_iocg_050_ds0_END (4)
#define SOC_IOCR_IOCG_050_iocg_050_ds1_START (5)
#define SOC_IOCR_IOCG_050_iocg_050_ds1_END (5)
#define SOC_IOCR_IOCG_050_iocg_050_ds2_START (6)
#define SOC_IOCR_IOCG_050_iocg_050_ds2_END (6)
#define SOC_IOCR_IOCG_050_iocg_050_sl_START (7)
#define SOC_IOCR_IOCG_050_iocg_050_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_051_pu : 1;
        unsigned int iocg_051_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_051_st : 1;
        unsigned int iocg_051_ds0 : 1;
        unsigned int iocg_051_ds1 : 1;
        unsigned int iocg_051_ds2 : 1;
        unsigned int iocg_051_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_051_UNION;
#endif
#define SOC_IOCR_IOCG_051_iocg_051_pu_START (0)
#define SOC_IOCR_IOCG_051_iocg_051_pu_END (0)
#define SOC_IOCR_IOCG_051_iocg_051_pd_START (1)
#define SOC_IOCR_IOCG_051_iocg_051_pd_END (1)
#define SOC_IOCR_IOCG_051_iocg_051_st_START (3)
#define SOC_IOCR_IOCG_051_iocg_051_st_END (3)
#define SOC_IOCR_IOCG_051_iocg_051_ds0_START (4)
#define SOC_IOCR_IOCG_051_iocg_051_ds0_END (4)
#define SOC_IOCR_IOCG_051_iocg_051_ds1_START (5)
#define SOC_IOCR_IOCG_051_iocg_051_ds1_END (5)
#define SOC_IOCR_IOCG_051_iocg_051_ds2_START (6)
#define SOC_IOCR_IOCG_051_iocg_051_ds2_END (6)
#define SOC_IOCR_IOCG_051_iocg_051_sl_START (7)
#define SOC_IOCR_IOCG_051_iocg_051_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_052_pu : 1;
        unsigned int iocg_052_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_052_st : 1;
        unsigned int iocg_052_ds0 : 1;
        unsigned int iocg_052_ds1 : 1;
        unsigned int iocg_052_ds2 : 1;
        unsigned int iocg_052_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_052_UNION;
#endif
#define SOC_IOCR_IOCG_052_iocg_052_pu_START (0)
#define SOC_IOCR_IOCG_052_iocg_052_pu_END (0)
#define SOC_IOCR_IOCG_052_iocg_052_pd_START (1)
#define SOC_IOCR_IOCG_052_iocg_052_pd_END (1)
#define SOC_IOCR_IOCG_052_iocg_052_st_START (3)
#define SOC_IOCR_IOCG_052_iocg_052_st_END (3)
#define SOC_IOCR_IOCG_052_iocg_052_ds0_START (4)
#define SOC_IOCR_IOCG_052_iocg_052_ds0_END (4)
#define SOC_IOCR_IOCG_052_iocg_052_ds1_START (5)
#define SOC_IOCR_IOCG_052_iocg_052_ds1_END (5)
#define SOC_IOCR_IOCG_052_iocg_052_ds2_START (6)
#define SOC_IOCR_IOCG_052_iocg_052_ds2_END (6)
#define SOC_IOCR_IOCG_052_iocg_052_sl_START (7)
#define SOC_IOCR_IOCG_052_iocg_052_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_053_pu : 1;
        unsigned int iocg_053_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_053_st : 1;
        unsigned int iocg_053_ds0 : 1;
        unsigned int iocg_053_ds1 : 1;
        unsigned int iocg_053_ds2 : 1;
        unsigned int iocg_053_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_053_UNION;
#endif
#define SOC_IOCR_IOCG_053_iocg_053_pu_START (0)
#define SOC_IOCR_IOCG_053_iocg_053_pu_END (0)
#define SOC_IOCR_IOCG_053_iocg_053_pd_START (1)
#define SOC_IOCR_IOCG_053_iocg_053_pd_END (1)
#define SOC_IOCR_IOCG_053_iocg_053_st_START (3)
#define SOC_IOCR_IOCG_053_iocg_053_st_END (3)
#define SOC_IOCR_IOCG_053_iocg_053_ds0_START (4)
#define SOC_IOCR_IOCG_053_iocg_053_ds0_END (4)
#define SOC_IOCR_IOCG_053_iocg_053_ds1_START (5)
#define SOC_IOCR_IOCG_053_iocg_053_ds1_END (5)
#define SOC_IOCR_IOCG_053_iocg_053_ds2_START (6)
#define SOC_IOCR_IOCG_053_iocg_053_ds2_END (6)
#define SOC_IOCR_IOCG_053_iocg_053_sl_START (7)
#define SOC_IOCR_IOCG_053_iocg_053_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_054_pu : 1;
        unsigned int iocg_054_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_054_st : 1;
        unsigned int iocg_054_ds0 : 1;
        unsigned int iocg_054_ds1 : 1;
        unsigned int iocg_054_ds2 : 1;
        unsigned int iocg_054_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_054_UNION;
#endif
#define SOC_IOCR_IOCG_054_iocg_054_pu_START (0)
#define SOC_IOCR_IOCG_054_iocg_054_pu_END (0)
#define SOC_IOCR_IOCG_054_iocg_054_pd_START (1)
#define SOC_IOCR_IOCG_054_iocg_054_pd_END (1)
#define SOC_IOCR_IOCG_054_iocg_054_st_START (3)
#define SOC_IOCR_IOCG_054_iocg_054_st_END (3)
#define SOC_IOCR_IOCG_054_iocg_054_ds0_START (4)
#define SOC_IOCR_IOCG_054_iocg_054_ds0_END (4)
#define SOC_IOCR_IOCG_054_iocg_054_ds1_START (5)
#define SOC_IOCR_IOCG_054_iocg_054_ds1_END (5)
#define SOC_IOCR_IOCG_054_iocg_054_ds2_START (6)
#define SOC_IOCR_IOCG_054_iocg_054_ds2_END (6)
#define SOC_IOCR_IOCG_054_iocg_054_sl_START (7)
#define SOC_IOCR_IOCG_054_iocg_054_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_055_pu : 1;
        unsigned int iocg_055_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_055_st : 1;
        unsigned int iocg_055_ds0 : 1;
        unsigned int iocg_055_ds1 : 1;
        unsigned int iocg_055_ds2 : 1;
        unsigned int iocg_055_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_055_UNION;
#endif
#define SOC_IOCR_IOCG_055_iocg_055_pu_START (0)
#define SOC_IOCR_IOCG_055_iocg_055_pu_END (0)
#define SOC_IOCR_IOCG_055_iocg_055_pd_START (1)
#define SOC_IOCR_IOCG_055_iocg_055_pd_END (1)
#define SOC_IOCR_IOCG_055_iocg_055_st_START (3)
#define SOC_IOCR_IOCG_055_iocg_055_st_END (3)
#define SOC_IOCR_IOCG_055_iocg_055_ds0_START (4)
#define SOC_IOCR_IOCG_055_iocg_055_ds0_END (4)
#define SOC_IOCR_IOCG_055_iocg_055_ds1_START (5)
#define SOC_IOCR_IOCG_055_iocg_055_ds1_END (5)
#define SOC_IOCR_IOCG_055_iocg_055_ds2_START (6)
#define SOC_IOCR_IOCG_055_iocg_055_ds2_END (6)
#define SOC_IOCR_IOCG_055_iocg_055_sl_START (7)
#define SOC_IOCR_IOCG_055_iocg_055_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_056_pu : 1;
        unsigned int iocg_056_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_056_st : 1;
        unsigned int iocg_056_ds0 : 1;
        unsigned int iocg_056_ds1 : 1;
        unsigned int iocg_056_ds2 : 1;
        unsigned int iocg_056_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_056_UNION;
#endif
#define SOC_IOCR_IOCG_056_iocg_056_pu_START (0)
#define SOC_IOCR_IOCG_056_iocg_056_pu_END (0)
#define SOC_IOCR_IOCG_056_iocg_056_pd_START (1)
#define SOC_IOCR_IOCG_056_iocg_056_pd_END (1)
#define SOC_IOCR_IOCG_056_iocg_056_st_START (3)
#define SOC_IOCR_IOCG_056_iocg_056_st_END (3)
#define SOC_IOCR_IOCG_056_iocg_056_ds0_START (4)
#define SOC_IOCR_IOCG_056_iocg_056_ds0_END (4)
#define SOC_IOCR_IOCG_056_iocg_056_ds1_START (5)
#define SOC_IOCR_IOCG_056_iocg_056_ds1_END (5)
#define SOC_IOCR_IOCG_056_iocg_056_ds2_START (6)
#define SOC_IOCR_IOCG_056_iocg_056_ds2_END (6)
#define SOC_IOCR_IOCG_056_iocg_056_sl_START (7)
#define SOC_IOCR_IOCG_056_iocg_056_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_057_pu : 1;
        unsigned int iocg_057_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_057_st : 1;
        unsigned int iocg_057_ds0 : 1;
        unsigned int iocg_057_ds1 : 1;
        unsigned int iocg_057_ds2 : 1;
        unsigned int iocg_057_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_057_UNION;
#endif
#define SOC_IOCR_IOCG_057_iocg_057_pu_START (0)
#define SOC_IOCR_IOCG_057_iocg_057_pu_END (0)
#define SOC_IOCR_IOCG_057_iocg_057_pd_START (1)
#define SOC_IOCR_IOCG_057_iocg_057_pd_END (1)
#define SOC_IOCR_IOCG_057_iocg_057_st_START (3)
#define SOC_IOCR_IOCG_057_iocg_057_st_END (3)
#define SOC_IOCR_IOCG_057_iocg_057_ds0_START (4)
#define SOC_IOCR_IOCG_057_iocg_057_ds0_END (4)
#define SOC_IOCR_IOCG_057_iocg_057_ds1_START (5)
#define SOC_IOCR_IOCG_057_iocg_057_ds1_END (5)
#define SOC_IOCR_IOCG_057_iocg_057_ds2_START (6)
#define SOC_IOCR_IOCG_057_iocg_057_ds2_END (6)
#define SOC_IOCR_IOCG_057_iocg_057_sl_START (7)
#define SOC_IOCR_IOCG_057_iocg_057_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_058_pu : 1;
        unsigned int iocg_058_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_058_st : 1;
        unsigned int iocg_058_ds0 : 1;
        unsigned int iocg_058_ds1 : 1;
        unsigned int iocg_058_ds2 : 1;
        unsigned int iocg_058_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_058_UNION;
#endif
#define SOC_IOCR_IOCG_058_iocg_058_pu_START (0)
#define SOC_IOCR_IOCG_058_iocg_058_pu_END (0)
#define SOC_IOCR_IOCG_058_iocg_058_pd_START (1)
#define SOC_IOCR_IOCG_058_iocg_058_pd_END (1)
#define SOC_IOCR_IOCG_058_iocg_058_st_START (3)
#define SOC_IOCR_IOCG_058_iocg_058_st_END (3)
#define SOC_IOCR_IOCG_058_iocg_058_ds0_START (4)
#define SOC_IOCR_IOCG_058_iocg_058_ds0_END (4)
#define SOC_IOCR_IOCG_058_iocg_058_ds1_START (5)
#define SOC_IOCR_IOCG_058_iocg_058_ds1_END (5)
#define SOC_IOCR_IOCG_058_iocg_058_ds2_START (6)
#define SOC_IOCR_IOCG_058_iocg_058_ds2_END (6)
#define SOC_IOCR_IOCG_058_iocg_058_sl_START (7)
#define SOC_IOCR_IOCG_058_iocg_058_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_059_pu : 1;
        unsigned int iocg_059_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_059_st : 1;
        unsigned int iocg_059_ds0 : 1;
        unsigned int iocg_059_ds1 : 1;
        unsigned int iocg_059_ds2 : 1;
        unsigned int iocg_059_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_059_UNION;
#endif
#define SOC_IOCR_IOCG_059_iocg_059_pu_START (0)
#define SOC_IOCR_IOCG_059_iocg_059_pu_END (0)
#define SOC_IOCR_IOCG_059_iocg_059_pd_START (1)
#define SOC_IOCR_IOCG_059_iocg_059_pd_END (1)
#define SOC_IOCR_IOCG_059_iocg_059_st_START (3)
#define SOC_IOCR_IOCG_059_iocg_059_st_END (3)
#define SOC_IOCR_IOCG_059_iocg_059_ds0_START (4)
#define SOC_IOCR_IOCG_059_iocg_059_ds0_END (4)
#define SOC_IOCR_IOCG_059_iocg_059_ds1_START (5)
#define SOC_IOCR_IOCG_059_iocg_059_ds1_END (5)
#define SOC_IOCR_IOCG_059_iocg_059_ds2_START (6)
#define SOC_IOCR_IOCG_059_iocg_059_ds2_END (6)
#define SOC_IOCR_IOCG_059_iocg_059_sl_START (7)
#define SOC_IOCR_IOCG_059_iocg_059_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_060_pu : 1;
        unsigned int iocg_060_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_060_st : 1;
        unsigned int iocg_060_ds0 : 1;
        unsigned int iocg_060_ds1 : 1;
        unsigned int iocg_060_ds2 : 1;
        unsigned int iocg_060_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCR_IOCG_060_UNION;
#endif
#define SOC_IOCR_IOCG_060_iocg_060_pu_START (0)
#define SOC_IOCR_IOCG_060_iocg_060_pu_END (0)
#define SOC_IOCR_IOCG_060_iocg_060_pd_START (1)
#define SOC_IOCR_IOCG_060_iocg_060_pd_END (1)
#define SOC_IOCR_IOCG_060_iocg_060_st_START (3)
#define SOC_IOCR_IOCG_060_iocg_060_st_END (3)
#define SOC_IOCR_IOCG_060_iocg_060_ds0_START (4)
#define SOC_IOCR_IOCG_060_iocg_060_ds0_END (4)
#define SOC_IOCR_IOCG_060_iocg_060_ds1_START (5)
#define SOC_IOCR_IOCG_060_iocg_060_ds1_END (5)
#define SOC_IOCR_IOCG_060_iocg_060_ds2_START (6)
#define SOC_IOCR_IOCG_060_iocg_060_ds2_END (6)
#define SOC_IOCR_IOCG_060_iocg_060_sl_START (7)
#define SOC_IOCR_IOCG_060_iocg_060_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_061_pu : 1;
        unsigned int iocg_061_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_061_st : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOCR_IOCG_061_UNION;
#endif
#define SOC_IOCR_IOCG_061_iocg_061_pu_START (0)
#define SOC_IOCR_IOCG_061_iocg_061_pu_END (0)
#define SOC_IOCR_IOCG_061_iocg_061_pd_START (1)
#define SOC_IOCR_IOCG_061_iocg_061_pd_END (1)
#define SOC_IOCR_IOCG_061_iocg_061_st_START (3)
#define SOC_IOCR_IOCG_061_iocg_061_st_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
