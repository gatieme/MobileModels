#ifndef __SOC_IOCL_IOCG_INTERFACE_H__
#define __SOC_IOCL_IOCG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOCL_IOCG_000_ADDR(base) ((base) + (0x800UL))
#define SOC_IOCL_IOCG_001_ADDR(base) ((base) + (0x804UL))
#define SOC_IOCL_IOCG_002_ADDR(base) ((base) + (0x808UL))
#define SOC_IOCL_IOCG_003_ADDR(base) ((base) + (0x80CUL))
#define SOC_IOCL_IOCG_004_ADDR(base) ((base) + (0x810UL))
#define SOC_IOCL_IOCG_008_ADDR(base) ((base) + (0x820UL))
#define SOC_IOCL_IOCG_009_ADDR(base) ((base) + (0x824UL))
#define SOC_IOCL_IOCG_010_ADDR(base) ((base) + (0x828UL))
#define SOC_IOCL_IOCG_011_ADDR(base) ((base) + (0x82CUL))
#define SOC_IOCL_IOCG_012_ADDR(base) ((base) + (0x830UL))
#define SOC_IOCL_IOCG_013_ADDR(base) ((base) + (0x834UL))
#define SOC_IOCL_IOCG_014_ADDR(base) ((base) + (0x838UL))
#define SOC_IOCL_IOCG_015_ADDR(base) ((base) + (0x83CUL))
#define SOC_IOCL_IOCG_016_ADDR(base) ((base) + (0x840UL))
#define SOC_IOCL_IOCG_017_ADDR(base) ((base) + (0x844UL))
#define SOC_IOCL_IOCG_018_ADDR(base) ((base) + (0x848UL))
#define SOC_IOCL_IOCG_019_ADDR(base) ((base) + (0x84CUL))
#define SOC_IOCL_IOCG_020_ADDR(base) ((base) + (0x850UL))
#define SOC_IOCL_IOCG_SE_00_ADDR(base) ((base) + (0xF00UL))
#define SOC_IOCL_IOCG_021_ADDR(base) ((base) + (0x854UL))
#define SOC_IOCL_IOCG_022_ADDR(base) ((base) + (0x858UL))
#define SOC_IOCL_IOCG_023_ADDR(base) ((base) + (0x85CUL))
#define SOC_IOCL_IOCG_024_ADDR(base) ((base) + (0x860UL))
#define SOC_IOCL_IOCG_025_ADDR(base) ((base) + (0x864UL))
#define SOC_IOCL_IOCG_026_ADDR(base) ((base) + (0x868UL))
#define SOC_IOCL_IOCG_027_ADDR(base) ((base) + (0x86CUL))
#define SOC_IOCL_IOCG_028_ADDR(base) ((base) + (0x870UL))
#define SOC_IOCL_IOCG_029_ADDR(base) ((base) + (0x874UL))
#define SOC_IOCL_IOCG_030_ADDR(base) ((base) + (0x878UL))
#define SOC_IOCL_IOCG_031_ADDR(base) ((base) + (0x87CUL))
#define SOC_IOCL_IOCG_032_ADDR(base) ((base) + (0x880UL))
#define SOC_IOCL_IOCG_033_ADDR(base) ((base) + (0x884UL))
#define SOC_IOCL_IOCG_034_ADDR(base) ((base) + (0x888UL))
#define SOC_IOCL_IOCG_035_ADDR(base) ((base) + (0x88CUL))
#define SOC_IOCL_IOCG_036_ADDR(base) ((base) + (0x890UL))
#define SOC_IOCL_IOCG_037_ADDR(base) ((base) + (0x894UL))
#define SOC_IOCL_IOCG_038_ADDR(base) ((base) + (0x898UL))
#define SOC_IOCL_IOCG_SE_01_ADDR(base) ((base) + (0xF04UL))
#define SOC_IOCL_IOCG_SE_02_ADDR(base) ((base) + (0xF08UL))
#define SOC_IOCL_IOCG_039_ADDR(base) ((base) + (0x89CUL))
#define SOC_IOCL_IOCG_040_ADDR(base) ((base) + (0x8A0UL))
#define SOC_IOCL_IOCG_041_ADDR(base) ((base) + (0x8A4UL))
#define SOC_IOCL_IOCG_SE_03_ADDR(base) ((base) + (0xF0CUL))
#define SOC_IOCL_IOCG_042_ADDR(base) ((base) + (0x8A8UL))
#else
#define SOC_IOCL_IOCG_000_ADDR(base) ((base) + (0x800))
#define SOC_IOCL_IOCG_001_ADDR(base) ((base) + (0x804))
#define SOC_IOCL_IOCG_002_ADDR(base) ((base) + (0x808))
#define SOC_IOCL_IOCG_003_ADDR(base) ((base) + (0x80C))
#define SOC_IOCL_IOCG_004_ADDR(base) ((base) + (0x810))
#define SOC_IOCL_IOCG_008_ADDR(base) ((base) + (0x820))
#define SOC_IOCL_IOCG_009_ADDR(base) ((base) + (0x824))
#define SOC_IOCL_IOCG_010_ADDR(base) ((base) + (0x828))
#define SOC_IOCL_IOCG_011_ADDR(base) ((base) + (0x82C))
#define SOC_IOCL_IOCG_012_ADDR(base) ((base) + (0x830))
#define SOC_IOCL_IOCG_013_ADDR(base) ((base) + (0x834))
#define SOC_IOCL_IOCG_014_ADDR(base) ((base) + (0x838))
#define SOC_IOCL_IOCG_015_ADDR(base) ((base) + (0x83C))
#define SOC_IOCL_IOCG_016_ADDR(base) ((base) + (0x840))
#define SOC_IOCL_IOCG_017_ADDR(base) ((base) + (0x844))
#define SOC_IOCL_IOCG_018_ADDR(base) ((base) + (0x848))
#define SOC_IOCL_IOCG_019_ADDR(base) ((base) + (0x84C))
#define SOC_IOCL_IOCG_020_ADDR(base) ((base) + (0x850))
#define SOC_IOCL_IOCG_SE_00_ADDR(base) ((base) + (0xF00))
#define SOC_IOCL_IOCG_021_ADDR(base) ((base) + (0x854))
#define SOC_IOCL_IOCG_022_ADDR(base) ((base) + (0x858))
#define SOC_IOCL_IOCG_023_ADDR(base) ((base) + (0x85C))
#define SOC_IOCL_IOCG_024_ADDR(base) ((base) + (0x860))
#define SOC_IOCL_IOCG_025_ADDR(base) ((base) + (0x864))
#define SOC_IOCL_IOCG_026_ADDR(base) ((base) + (0x868))
#define SOC_IOCL_IOCG_027_ADDR(base) ((base) + (0x86C))
#define SOC_IOCL_IOCG_028_ADDR(base) ((base) + (0x870))
#define SOC_IOCL_IOCG_029_ADDR(base) ((base) + (0x874))
#define SOC_IOCL_IOCG_030_ADDR(base) ((base) + (0x878))
#define SOC_IOCL_IOCG_031_ADDR(base) ((base) + (0x87C))
#define SOC_IOCL_IOCG_032_ADDR(base) ((base) + (0x880))
#define SOC_IOCL_IOCG_033_ADDR(base) ((base) + (0x884))
#define SOC_IOCL_IOCG_034_ADDR(base) ((base) + (0x888))
#define SOC_IOCL_IOCG_035_ADDR(base) ((base) + (0x88C))
#define SOC_IOCL_IOCG_036_ADDR(base) ((base) + (0x890))
#define SOC_IOCL_IOCG_037_ADDR(base) ((base) + (0x894))
#define SOC_IOCL_IOCG_038_ADDR(base) ((base) + (0x898))
#define SOC_IOCL_IOCG_SE_01_ADDR(base) ((base) + (0xF04))
#define SOC_IOCL_IOCG_SE_02_ADDR(base) ((base) + (0xF08))
#define SOC_IOCL_IOCG_039_ADDR(base) ((base) + (0x89C))
#define SOC_IOCL_IOCG_040_ADDR(base) ((base) + (0x8A0))
#define SOC_IOCL_IOCG_041_ADDR(base) ((base) + (0x8A4))
#define SOC_IOCL_IOCG_SE_03_ADDR(base) ((base) + (0xF0C))
#define SOC_IOCL_IOCG_042_ADDR(base) ((base) + (0x8A8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_000_pu : 1;
        unsigned int iocg_000_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_000_st : 1;
        unsigned int iocg_000_ds0 : 1;
        unsigned int iocg_000_ds1 : 1;
        unsigned int iocg_000_ds2 : 1;
        unsigned int iocg_000_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_000_UNION;
#endif
#define SOC_IOCL_IOCG_000_iocg_000_pu_START (0)
#define SOC_IOCL_IOCG_000_iocg_000_pu_END (0)
#define SOC_IOCL_IOCG_000_iocg_000_pd_START (1)
#define SOC_IOCL_IOCG_000_iocg_000_pd_END (1)
#define SOC_IOCL_IOCG_000_iocg_000_st_START (3)
#define SOC_IOCL_IOCG_000_iocg_000_st_END (3)
#define SOC_IOCL_IOCG_000_iocg_000_ds0_START (4)
#define SOC_IOCL_IOCG_000_iocg_000_ds0_END (4)
#define SOC_IOCL_IOCG_000_iocg_000_ds1_START (5)
#define SOC_IOCL_IOCG_000_iocg_000_ds1_END (5)
#define SOC_IOCL_IOCG_000_iocg_000_ds2_START (6)
#define SOC_IOCL_IOCG_000_iocg_000_ds2_END (6)
#define SOC_IOCL_IOCG_000_iocg_000_sl_START (7)
#define SOC_IOCL_IOCG_000_iocg_000_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_001_pu : 1;
        unsigned int iocg_001_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_001_st : 1;
        unsigned int iocg_001_ds0 : 1;
        unsigned int iocg_001_ds1 : 1;
        unsigned int iocg_001_ds2 : 1;
        unsigned int iocg_001_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_001_UNION;
#endif
#define SOC_IOCL_IOCG_001_iocg_001_pu_START (0)
#define SOC_IOCL_IOCG_001_iocg_001_pu_END (0)
#define SOC_IOCL_IOCG_001_iocg_001_pd_START (1)
#define SOC_IOCL_IOCG_001_iocg_001_pd_END (1)
#define SOC_IOCL_IOCG_001_iocg_001_st_START (3)
#define SOC_IOCL_IOCG_001_iocg_001_st_END (3)
#define SOC_IOCL_IOCG_001_iocg_001_ds0_START (4)
#define SOC_IOCL_IOCG_001_iocg_001_ds0_END (4)
#define SOC_IOCL_IOCG_001_iocg_001_ds1_START (5)
#define SOC_IOCL_IOCG_001_iocg_001_ds1_END (5)
#define SOC_IOCL_IOCG_001_iocg_001_ds2_START (6)
#define SOC_IOCL_IOCG_001_iocg_001_ds2_END (6)
#define SOC_IOCL_IOCG_001_iocg_001_sl_START (7)
#define SOC_IOCL_IOCG_001_iocg_001_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_002_pu : 1;
        unsigned int iocg_002_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_002_st : 1;
        unsigned int iocg_002_ds0 : 1;
        unsigned int iocg_002_ds1 : 1;
        unsigned int iocg_002_ds2 : 1;
        unsigned int iocg_002_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_002_UNION;
#endif
#define SOC_IOCL_IOCG_002_iocg_002_pu_START (0)
#define SOC_IOCL_IOCG_002_iocg_002_pu_END (0)
#define SOC_IOCL_IOCG_002_iocg_002_pd_START (1)
#define SOC_IOCL_IOCG_002_iocg_002_pd_END (1)
#define SOC_IOCL_IOCG_002_iocg_002_st_START (3)
#define SOC_IOCL_IOCG_002_iocg_002_st_END (3)
#define SOC_IOCL_IOCG_002_iocg_002_ds0_START (4)
#define SOC_IOCL_IOCG_002_iocg_002_ds0_END (4)
#define SOC_IOCL_IOCG_002_iocg_002_ds1_START (5)
#define SOC_IOCL_IOCG_002_iocg_002_ds1_END (5)
#define SOC_IOCL_IOCG_002_iocg_002_ds2_START (6)
#define SOC_IOCL_IOCG_002_iocg_002_ds2_END (6)
#define SOC_IOCL_IOCG_002_iocg_002_sl_START (7)
#define SOC_IOCL_IOCG_002_iocg_002_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_003_pu : 1;
        unsigned int iocg_003_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_003_st : 1;
        unsigned int iocg_003_ds0 : 1;
        unsigned int iocg_003_ds1 : 1;
        unsigned int iocg_003_ds2 : 1;
        unsigned int iocg_003_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_003_UNION;
#endif
#define SOC_IOCL_IOCG_003_iocg_003_pu_START (0)
#define SOC_IOCL_IOCG_003_iocg_003_pu_END (0)
#define SOC_IOCL_IOCG_003_iocg_003_pd_START (1)
#define SOC_IOCL_IOCG_003_iocg_003_pd_END (1)
#define SOC_IOCL_IOCG_003_iocg_003_st_START (3)
#define SOC_IOCL_IOCG_003_iocg_003_st_END (3)
#define SOC_IOCL_IOCG_003_iocg_003_ds0_START (4)
#define SOC_IOCL_IOCG_003_iocg_003_ds0_END (4)
#define SOC_IOCL_IOCG_003_iocg_003_ds1_START (5)
#define SOC_IOCL_IOCG_003_iocg_003_ds1_END (5)
#define SOC_IOCL_IOCG_003_iocg_003_ds2_START (6)
#define SOC_IOCL_IOCG_003_iocg_003_ds2_END (6)
#define SOC_IOCL_IOCG_003_iocg_003_sl_START (7)
#define SOC_IOCL_IOCG_003_iocg_003_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_004_pu : 1;
        unsigned int iocg_004_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_004_st : 1;
        unsigned int iocg_004_ds0 : 1;
        unsigned int iocg_004_ds1 : 1;
        unsigned int iocg_004_ds2 : 1;
        unsigned int iocg_004_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_004_UNION;
#endif
#define SOC_IOCL_IOCG_004_iocg_004_pu_START (0)
#define SOC_IOCL_IOCG_004_iocg_004_pu_END (0)
#define SOC_IOCL_IOCG_004_iocg_004_pd_START (1)
#define SOC_IOCL_IOCG_004_iocg_004_pd_END (1)
#define SOC_IOCL_IOCG_004_iocg_004_st_START (3)
#define SOC_IOCL_IOCG_004_iocg_004_st_END (3)
#define SOC_IOCL_IOCG_004_iocg_004_ds0_START (4)
#define SOC_IOCL_IOCG_004_iocg_004_ds0_END (4)
#define SOC_IOCL_IOCG_004_iocg_004_ds1_START (5)
#define SOC_IOCL_IOCG_004_iocg_004_ds1_END (5)
#define SOC_IOCL_IOCG_004_iocg_004_ds2_START (6)
#define SOC_IOCL_IOCG_004_iocg_004_ds2_END (6)
#define SOC_IOCL_IOCG_004_iocg_004_sl_START (7)
#define SOC_IOCL_IOCG_004_iocg_004_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_008_pu : 1;
        unsigned int iocg_008_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_008_st : 1;
        unsigned int iocg_008_ds0 : 1;
        unsigned int iocg_008_ds1 : 1;
        unsigned int iocg_008_ds2 : 1;
        unsigned int iocg_008_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_008_UNION;
#endif
#define SOC_IOCL_IOCG_008_iocg_008_pu_START (0)
#define SOC_IOCL_IOCG_008_iocg_008_pu_END (0)
#define SOC_IOCL_IOCG_008_iocg_008_pd_START (1)
#define SOC_IOCL_IOCG_008_iocg_008_pd_END (1)
#define SOC_IOCL_IOCG_008_iocg_008_st_START (3)
#define SOC_IOCL_IOCG_008_iocg_008_st_END (3)
#define SOC_IOCL_IOCG_008_iocg_008_ds0_START (4)
#define SOC_IOCL_IOCG_008_iocg_008_ds0_END (4)
#define SOC_IOCL_IOCG_008_iocg_008_ds1_START (5)
#define SOC_IOCL_IOCG_008_iocg_008_ds1_END (5)
#define SOC_IOCL_IOCG_008_iocg_008_ds2_START (6)
#define SOC_IOCL_IOCG_008_iocg_008_ds2_END (6)
#define SOC_IOCL_IOCG_008_iocg_008_sl_START (7)
#define SOC_IOCL_IOCG_008_iocg_008_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_009_pu : 1;
        unsigned int iocg_009_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_009_st : 1;
        unsigned int iocg_009_ds0 : 1;
        unsigned int iocg_009_ds1 : 1;
        unsigned int iocg_009_ds2 : 1;
        unsigned int iocg_009_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_009_UNION;
#endif
#define SOC_IOCL_IOCG_009_iocg_009_pu_START (0)
#define SOC_IOCL_IOCG_009_iocg_009_pu_END (0)
#define SOC_IOCL_IOCG_009_iocg_009_pd_START (1)
#define SOC_IOCL_IOCG_009_iocg_009_pd_END (1)
#define SOC_IOCL_IOCG_009_iocg_009_st_START (3)
#define SOC_IOCL_IOCG_009_iocg_009_st_END (3)
#define SOC_IOCL_IOCG_009_iocg_009_ds0_START (4)
#define SOC_IOCL_IOCG_009_iocg_009_ds0_END (4)
#define SOC_IOCL_IOCG_009_iocg_009_ds1_START (5)
#define SOC_IOCL_IOCG_009_iocg_009_ds1_END (5)
#define SOC_IOCL_IOCG_009_iocg_009_ds2_START (6)
#define SOC_IOCL_IOCG_009_iocg_009_ds2_END (6)
#define SOC_IOCL_IOCG_009_iocg_009_sl_START (7)
#define SOC_IOCL_IOCG_009_iocg_009_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_010_pu : 1;
        unsigned int iocg_010_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_010_st : 1;
        unsigned int iocg_010_ds0 : 1;
        unsigned int iocg_010_ds1 : 1;
        unsigned int iocg_010_ds2 : 1;
        unsigned int iocg_010_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_010_UNION;
#endif
#define SOC_IOCL_IOCG_010_iocg_010_pu_START (0)
#define SOC_IOCL_IOCG_010_iocg_010_pu_END (0)
#define SOC_IOCL_IOCG_010_iocg_010_pd_START (1)
#define SOC_IOCL_IOCG_010_iocg_010_pd_END (1)
#define SOC_IOCL_IOCG_010_iocg_010_st_START (3)
#define SOC_IOCL_IOCG_010_iocg_010_st_END (3)
#define SOC_IOCL_IOCG_010_iocg_010_ds0_START (4)
#define SOC_IOCL_IOCG_010_iocg_010_ds0_END (4)
#define SOC_IOCL_IOCG_010_iocg_010_ds1_START (5)
#define SOC_IOCL_IOCG_010_iocg_010_ds1_END (5)
#define SOC_IOCL_IOCG_010_iocg_010_ds2_START (6)
#define SOC_IOCL_IOCG_010_iocg_010_ds2_END (6)
#define SOC_IOCL_IOCG_010_iocg_010_sl_START (7)
#define SOC_IOCL_IOCG_010_iocg_010_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_011_pu : 1;
        unsigned int iocg_011_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_011_st : 1;
        unsigned int iocg_011_ds0 : 1;
        unsigned int iocg_011_ds1 : 1;
        unsigned int iocg_011_ds2 : 1;
        unsigned int iocg_011_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_011_UNION;
#endif
#define SOC_IOCL_IOCG_011_iocg_011_pu_START (0)
#define SOC_IOCL_IOCG_011_iocg_011_pu_END (0)
#define SOC_IOCL_IOCG_011_iocg_011_pd_START (1)
#define SOC_IOCL_IOCG_011_iocg_011_pd_END (1)
#define SOC_IOCL_IOCG_011_iocg_011_st_START (3)
#define SOC_IOCL_IOCG_011_iocg_011_st_END (3)
#define SOC_IOCL_IOCG_011_iocg_011_ds0_START (4)
#define SOC_IOCL_IOCG_011_iocg_011_ds0_END (4)
#define SOC_IOCL_IOCG_011_iocg_011_ds1_START (5)
#define SOC_IOCL_IOCG_011_iocg_011_ds1_END (5)
#define SOC_IOCL_IOCG_011_iocg_011_ds2_START (6)
#define SOC_IOCL_IOCG_011_iocg_011_ds2_END (6)
#define SOC_IOCL_IOCG_011_iocg_011_sl_START (7)
#define SOC_IOCL_IOCG_011_iocg_011_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_012_pu : 1;
        unsigned int iocg_012_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_012_st : 1;
        unsigned int iocg_012_ds0 : 1;
        unsigned int iocg_012_ds1 : 1;
        unsigned int iocg_012_ds2 : 1;
        unsigned int iocg_012_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_012_UNION;
#endif
#define SOC_IOCL_IOCG_012_iocg_012_pu_START (0)
#define SOC_IOCL_IOCG_012_iocg_012_pu_END (0)
#define SOC_IOCL_IOCG_012_iocg_012_pd_START (1)
#define SOC_IOCL_IOCG_012_iocg_012_pd_END (1)
#define SOC_IOCL_IOCG_012_iocg_012_st_START (3)
#define SOC_IOCL_IOCG_012_iocg_012_st_END (3)
#define SOC_IOCL_IOCG_012_iocg_012_ds0_START (4)
#define SOC_IOCL_IOCG_012_iocg_012_ds0_END (4)
#define SOC_IOCL_IOCG_012_iocg_012_ds1_START (5)
#define SOC_IOCL_IOCG_012_iocg_012_ds1_END (5)
#define SOC_IOCL_IOCG_012_iocg_012_ds2_START (6)
#define SOC_IOCL_IOCG_012_iocg_012_ds2_END (6)
#define SOC_IOCL_IOCG_012_iocg_012_sl_START (7)
#define SOC_IOCL_IOCG_012_iocg_012_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_013_pu : 1;
        unsigned int iocg_013_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_013_st : 1;
        unsigned int iocg_013_ds0 : 1;
        unsigned int iocg_013_ds1 : 1;
        unsigned int iocg_013_ds2 : 1;
        unsigned int iocg_013_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_013_UNION;
#endif
#define SOC_IOCL_IOCG_013_iocg_013_pu_START (0)
#define SOC_IOCL_IOCG_013_iocg_013_pu_END (0)
#define SOC_IOCL_IOCG_013_iocg_013_pd_START (1)
#define SOC_IOCL_IOCG_013_iocg_013_pd_END (1)
#define SOC_IOCL_IOCG_013_iocg_013_st_START (3)
#define SOC_IOCL_IOCG_013_iocg_013_st_END (3)
#define SOC_IOCL_IOCG_013_iocg_013_ds0_START (4)
#define SOC_IOCL_IOCG_013_iocg_013_ds0_END (4)
#define SOC_IOCL_IOCG_013_iocg_013_ds1_START (5)
#define SOC_IOCL_IOCG_013_iocg_013_ds1_END (5)
#define SOC_IOCL_IOCG_013_iocg_013_ds2_START (6)
#define SOC_IOCL_IOCG_013_iocg_013_ds2_END (6)
#define SOC_IOCL_IOCG_013_iocg_013_sl_START (7)
#define SOC_IOCL_IOCG_013_iocg_013_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_014_pu : 1;
        unsigned int iocg_014_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_014_st : 1;
        unsigned int iocg_014_ds0 : 1;
        unsigned int iocg_014_ds1 : 1;
        unsigned int iocg_014_ds2 : 1;
        unsigned int iocg_014_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_014_UNION;
#endif
#define SOC_IOCL_IOCG_014_iocg_014_pu_START (0)
#define SOC_IOCL_IOCG_014_iocg_014_pu_END (0)
#define SOC_IOCL_IOCG_014_iocg_014_pd_START (1)
#define SOC_IOCL_IOCG_014_iocg_014_pd_END (1)
#define SOC_IOCL_IOCG_014_iocg_014_st_START (3)
#define SOC_IOCL_IOCG_014_iocg_014_st_END (3)
#define SOC_IOCL_IOCG_014_iocg_014_ds0_START (4)
#define SOC_IOCL_IOCG_014_iocg_014_ds0_END (4)
#define SOC_IOCL_IOCG_014_iocg_014_ds1_START (5)
#define SOC_IOCL_IOCG_014_iocg_014_ds1_END (5)
#define SOC_IOCL_IOCG_014_iocg_014_ds2_START (6)
#define SOC_IOCL_IOCG_014_iocg_014_ds2_END (6)
#define SOC_IOCL_IOCG_014_iocg_014_sl_START (7)
#define SOC_IOCL_IOCG_014_iocg_014_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_015_pu : 1;
        unsigned int iocg_015_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_015_st : 1;
        unsigned int iocg_015_ds0 : 1;
        unsigned int iocg_015_ds1 : 1;
        unsigned int iocg_015_ds2 : 1;
        unsigned int iocg_015_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_015_UNION;
#endif
#define SOC_IOCL_IOCG_015_iocg_015_pu_START (0)
#define SOC_IOCL_IOCG_015_iocg_015_pu_END (0)
#define SOC_IOCL_IOCG_015_iocg_015_pd_START (1)
#define SOC_IOCL_IOCG_015_iocg_015_pd_END (1)
#define SOC_IOCL_IOCG_015_iocg_015_st_START (3)
#define SOC_IOCL_IOCG_015_iocg_015_st_END (3)
#define SOC_IOCL_IOCG_015_iocg_015_ds0_START (4)
#define SOC_IOCL_IOCG_015_iocg_015_ds0_END (4)
#define SOC_IOCL_IOCG_015_iocg_015_ds1_START (5)
#define SOC_IOCL_IOCG_015_iocg_015_ds1_END (5)
#define SOC_IOCL_IOCG_015_iocg_015_ds2_START (6)
#define SOC_IOCL_IOCG_015_iocg_015_ds2_END (6)
#define SOC_IOCL_IOCG_015_iocg_015_sl_START (7)
#define SOC_IOCL_IOCG_015_iocg_015_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_016_pu : 1;
        unsigned int iocg_016_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_016_st : 1;
        unsigned int iocg_016_ds0 : 1;
        unsigned int iocg_016_ds1 : 1;
        unsigned int iocg_016_ds2 : 1;
        unsigned int iocg_016_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_016_UNION;
#endif
#define SOC_IOCL_IOCG_016_iocg_016_pu_START (0)
#define SOC_IOCL_IOCG_016_iocg_016_pu_END (0)
#define SOC_IOCL_IOCG_016_iocg_016_pd_START (1)
#define SOC_IOCL_IOCG_016_iocg_016_pd_END (1)
#define SOC_IOCL_IOCG_016_iocg_016_st_START (3)
#define SOC_IOCL_IOCG_016_iocg_016_st_END (3)
#define SOC_IOCL_IOCG_016_iocg_016_ds0_START (4)
#define SOC_IOCL_IOCG_016_iocg_016_ds0_END (4)
#define SOC_IOCL_IOCG_016_iocg_016_ds1_START (5)
#define SOC_IOCL_IOCG_016_iocg_016_ds1_END (5)
#define SOC_IOCL_IOCG_016_iocg_016_ds2_START (6)
#define SOC_IOCL_IOCG_016_iocg_016_ds2_END (6)
#define SOC_IOCL_IOCG_016_iocg_016_sl_START (7)
#define SOC_IOCL_IOCG_016_iocg_016_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_017_pu : 1;
        unsigned int iocg_017_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_017_st : 1;
        unsigned int iocg_017_ds0 : 1;
        unsigned int iocg_017_ds1 : 1;
        unsigned int iocg_017_ds2 : 1;
        unsigned int iocg_017_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_017_UNION;
#endif
#define SOC_IOCL_IOCG_017_iocg_017_pu_START (0)
#define SOC_IOCL_IOCG_017_iocg_017_pu_END (0)
#define SOC_IOCL_IOCG_017_iocg_017_pd_START (1)
#define SOC_IOCL_IOCG_017_iocg_017_pd_END (1)
#define SOC_IOCL_IOCG_017_iocg_017_st_START (3)
#define SOC_IOCL_IOCG_017_iocg_017_st_END (3)
#define SOC_IOCL_IOCG_017_iocg_017_ds0_START (4)
#define SOC_IOCL_IOCG_017_iocg_017_ds0_END (4)
#define SOC_IOCL_IOCG_017_iocg_017_ds1_START (5)
#define SOC_IOCL_IOCG_017_iocg_017_ds1_END (5)
#define SOC_IOCL_IOCG_017_iocg_017_ds2_START (6)
#define SOC_IOCL_IOCG_017_iocg_017_ds2_END (6)
#define SOC_IOCL_IOCG_017_iocg_017_sl_START (7)
#define SOC_IOCL_IOCG_017_iocg_017_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_018_pu : 1;
        unsigned int iocg_018_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_018_st : 1;
        unsigned int iocg_018_ds0 : 1;
        unsigned int iocg_018_ds1 : 1;
        unsigned int iocg_018_ds2 : 1;
        unsigned int iocg_018_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_018_UNION;
#endif
#define SOC_IOCL_IOCG_018_iocg_018_pu_START (0)
#define SOC_IOCL_IOCG_018_iocg_018_pu_END (0)
#define SOC_IOCL_IOCG_018_iocg_018_pd_START (1)
#define SOC_IOCL_IOCG_018_iocg_018_pd_END (1)
#define SOC_IOCL_IOCG_018_iocg_018_st_START (3)
#define SOC_IOCL_IOCG_018_iocg_018_st_END (3)
#define SOC_IOCL_IOCG_018_iocg_018_ds0_START (4)
#define SOC_IOCL_IOCG_018_iocg_018_ds0_END (4)
#define SOC_IOCL_IOCG_018_iocg_018_ds1_START (5)
#define SOC_IOCL_IOCG_018_iocg_018_ds1_END (5)
#define SOC_IOCL_IOCG_018_iocg_018_ds2_START (6)
#define SOC_IOCL_IOCG_018_iocg_018_ds2_END (6)
#define SOC_IOCL_IOCG_018_iocg_018_sl_START (7)
#define SOC_IOCL_IOCG_018_iocg_018_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_019_pu : 1;
        unsigned int iocg_019_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_019_st : 1;
        unsigned int iocg_019_ds0 : 1;
        unsigned int iocg_019_ds1 : 1;
        unsigned int iocg_019_ds2 : 1;
        unsigned int iocg_019_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_019_UNION;
#endif
#define SOC_IOCL_IOCG_019_iocg_019_pu_START (0)
#define SOC_IOCL_IOCG_019_iocg_019_pu_END (0)
#define SOC_IOCL_IOCG_019_iocg_019_pd_START (1)
#define SOC_IOCL_IOCG_019_iocg_019_pd_END (1)
#define SOC_IOCL_IOCG_019_iocg_019_st_START (3)
#define SOC_IOCL_IOCG_019_iocg_019_st_END (3)
#define SOC_IOCL_IOCG_019_iocg_019_ds0_START (4)
#define SOC_IOCL_IOCG_019_iocg_019_ds0_END (4)
#define SOC_IOCL_IOCG_019_iocg_019_ds1_START (5)
#define SOC_IOCL_IOCG_019_iocg_019_ds1_END (5)
#define SOC_IOCL_IOCG_019_iocg_019_ds2_START (6)
#define SOC_IOCL_IOCG_019_iocg_019_ds2_END (6)
#define SOC_IOCL_IOCG_019_iocg_019_sl_START (7)
#define SOC_IOCL_IOCG_019_iocg_019_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_020_pu : 1;
        unsigned int iocg_020_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_020_st : 1;
        unsigned int iocg_020_ds0 : 1;
        unsigned int iocg_020_ds1 : 1;
        unsigned int iocg_020_ds2 : 1;
        unsigned int iocg_020_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_020_UNION;
#endif
#define SOC_IOCL_IOCG_020_iocg_020_pu_START (0)
#define SOC_IOCL_IOCG_020_iocg_020_pu_END (0)
#define SOC_IOCL_IOCG_020_iocg_020_pd_START (1)
#define SOC_IOCL_IOCG_020_iocg_020_pd_END (1)
#define SOC_IOCL_IOCG_020_iocg_020_st_START (3)
#define SOC_IOCL_IOCG_020_iocg_020_st_END (3)
#define SOC_IOCL_IOCG_020_iocg_020_ds0_START (4)
#define SOC_IOCL_IOCG_020_iocg_020_ds0_END (4)
#define SOC_IOCL_IOCG_020_iocg_020_ds1_START (5)
#define SOC_IOCL_IOCG_020_iocg_020_ds1_END (5)
#define SOC_IOCL_IOCG_020_iocg_020_ds2_START (6)
#define SOC_IOCL_IOCG_020_iocg_020_ds2_END (6)
#define SOC_IOCL_IOCG_020_iocg_020_sl_START (7)
#define SOC_IOCL_IOCG_020_iocg_020_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_00_pu : 1;
        unsigned int iocg_se_00_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_00_st : 1;
        unsigned int iocg_se_00_ds0 : 1;
        unsigned int iocg_se_00_ds1 : 1;
        unsigned int iocg_se_00_ds2 : 1;
        unsigned int iocg_se_00_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_SE_00_UNION;
#endif
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_pu_START (0)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_pu_END (0)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_pd_START (1)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_pd_END (1)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_st_START (3)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_st_END (3)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds0_START (4)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds0_END (4)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds1_START (5)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds1_END (5)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds2_START (6)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_ds2_END (6)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_sl_START (7)
#define SOC_IOCL_IOCG_SE_00_iocg_se_00_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_021_pu : 1;
        unsigned int iocg_021_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_021_st : 1;
        unsigned int iocg_021_ds0 : 1;
        unsigned int iocg_021_ds1 : 1;
        unsigned int iocg_021_ds2 : 1;
        unsigned int iocg_021_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_021_UNION;
#endif
#define SOC_IOCL_IOCG_021_iocg_021_pu_START (0)
#define SOC_IOCL_IOCG_021_iocg_021_pu_END (0)
#define SOC_IOCL_IOCG_021_iocg_021_pd_START (1)
#define SOC_IOCL_IOCG_021_iocg_021_pd_END (1)
#define SOC_IOCL_IOCG_021_iocg_021_st_START (3)
#define SOC_IOCL_IOCG_021_iocg_021_st_END (3)
#define SOC_IOCL_IOCG_021_iocg_021_ds0_START (4)
#define SOC_IOCL_IOCG_021_iocg_021_ds0_END (4)
#define SOC_IOCL_IOCG_021_iocg_021_ds1_START (5)
#define SOC_IOCL_IOCG_021_iocg_021_ds1_END (5)
#define SOC_IOCL_IOCG_021_iocg_021_ds2_START (6)
#define SOC_IOCL_IOCG_021_iocg_021_ds2_END (6)
#define SOC_IOCL_IOCG_021_iocg_021_sl_START (7)
#define SOC_IOCL_IOCG_021_iocg_021_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_022_pu : 1;
        unsigned int iocg_022_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_022_st : 1;
        unsigned int iocg_022_ds0 : 1;
        unsigned int iocg_022_ds1 : 1;
        unsigned int iocg_022_ds2 : 1;
        unsigned int iocg_022_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_022_UNION;
#endif
#define SOC_IOCL_IOCG_022_iocg_022_pu_START (0)
#define SOC_IOCL_IOCG_022_iocg_022_pu_END (0)
#define SOC_IOCL_IOCG_022_iocg_022_pd_START (1)
#define SOC_IOCL_IOCG_022_iocg_022_pd_END (1)
#define SOC_IOCL_IOCG_022_iocg_022_st_START (3)
#define SOC_IOCL_IOCG_022_iocg_022_st_END (3)
#define SOC_IOCL_IOCG_022_iocg_022_ds0_START (4)
#define SOC_IOCL_IOCG_022_iocg_022_ds0_END (4)
#define SOC_IOCL_IOCG_022_iocg_022_ds1_START (5)
#define SOC_IOCL_IOCG_022_iocg_022_ds1_END (5)
#define SOC_IOCL_IOCG_022_iocg_022_ds2_START (6)
#define SOC_IOCL_IOCG_022_iocg_022_ds2_END (6)
#define SOC_IOCL_IOCG_022_iocg_022_sl_START (7)
#define SOC_IOCL_IOCG_022_iocg_022_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_023_pu : 1;
        unsigned int iocg_023_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_023_st : 1;
        unsigned int iocg_023_ds0 : 1;
        unsigned int iocg_023_ds1 : 1;
        unsigned int iocg_023_ds2 : 1;
        unsigned int iocg_023_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_023_UNION;
#endif
#define SOC_IOCL_IOCG_023_iocg_023_pu_START (0)
#define SOC_IOCL_IOCG_023_iocg_023_pu_END (0)
#define SOC_IOCL_IOCG_023_iocg_023_pd_START (1)
#define SOC_IOCL_IOCG_023_iocg_023_pd_END (1)
#define SOC_IOCL_IOCG_023_iocg_023_st_START (3)
#define SOC_IOCL_IOCG_023_iocg_023_st_END (3)
#define SOC_IOCL_IOCG_023_iocg_023_ds0_START (4)
#define SOC_IOCL_IOCG_023_iocg_023_ds0_END (4)
#define SOC_IOCL_IOCG_023_iocg_023_ds1_START (5)
#define SOC_IOCL_IOCG_023_iocg_023_ds1_END (5)
#define SOC_IOCL_IOCG_023_iocg_023_ds2_START (6)
#define SOC_IOCL_IOCG_023_iocg_023_ds2_END (6)
#define SOC_IOCL_IOCG_023_iocg_023_sl_START (7)
#define SOC_IOCL_IOCG_023_iocg_023_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_024_pu : 1;
        unsigned int iocg_024_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_024_st : 1;
        unsigned int iocg_024_ds0 : 1;
        unsigned int iocg_024_ds1 : 1;
        unsigned int iocg_024_ds2 : 1;
        unsigned int iocg_024_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_024_UNION;
#endif
#define SOC_IOCL_IOCG_024_iocg_024_pu_START (0)
#define SOC_IOCL_IOCG_024_iocg_024_pu_END (0)
#define SOC_IOCL_IOCG_024_iocg_024_pd_START (1)
#define SOC_IOCL_IOCG_024_iocg_024_pd_END (1)
#define SOC_IOCL_IOCG_024_iocg_024_st_START (3)
#define SOC_IOCL_IOCG_024_iocg_024_st_END (3)
#define SOC_IOCL_IOCG_024_iocg_024_ds0_START (4)
#define SOC_IOCL_IOCG_024_iocg_024_ds0_END (4)
#define SOC_IOCL_IOCG_024_iocg_024_ds1_START (5)
#define SOC_IOCL_IOCG_024_iocg_024_ds1_END (5)
#define SOC_IOCL_IOCG_024_iocg_024_ds2_START (6)
#define SOC_IOCL_IOCG_024_iocg_024_ds2_END (6)
#define SOC_IOCL_IOCG_024_iocg_024_sl_START (7)
#define SOC_IOCL_IOCG_024_iocg_024_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_025_pu : 1;
        unsigned int iocg_025_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_025_st : 1;
        unsigned int iocg_025_ds0 : 1;
        unsigned int iocg_025_ds1 : 1;
        unsigned int iocg_025_ds2 : 1;
        unsigned int iocg_025_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_025_UNION;
#endif
#define SOC_IOCL_IOCG_025_iocg_025_pu_START (0)
#define SOC_IOCL_IOCG_025_iocg_025_pu_END (0)
#define SOC_IOCL_IOCG_025_iocg_025_pd_START (1)
#define SOC_IOCL_IOCG_025_iocg_025_pd_END (1)
#define SOC_IOCL_IOCG_025_iocg_025_st_START (3)
#define SOC_IOCL_IOCG_025_iocg_025_st_END (3)
#define SOC_IOCL_IOCG_025_iocg_025_ds0_START (4)
#define SOC_IOCL_IOCG_025_iocg_025_ds0_END (4)
#define SOC_IOCL_IOCG_025_iocg_025_ds1_START (5)
#define SOC_IOCL_IOCG_025_iocg_025_ds1_END (5)
#define SOC_IOCL_IOCG_025_iocg_025_ds2_START (6)
#define SOC_IOCL_IOCG_025_iocg_025_ds2_END (6)
#define SOC_IOCL_IOCG_025_iocg_025_sl_START (7)
#define SOC_IOCL_IOCG_025_iocg_025_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_026_pu : 1;
        unsigned int iocg_026_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_026_st : 1;
        unsigned int iocg_026_ds0 : 1;
        unsigned int iocg_026_ds1 : 1;
        unsigned int iocg_026_ds2 : 1;
        unsigned int iocg_026_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_026_UNION;
#endif
#define SOC_IOCL_IOCG_026_iocg_026_pu_START (0)
#define SOC_IOCL_IOCG_026_iocg_026_pu_END (0)
#define SOC_IOCL_IOCG_026_iocg_026_pd_START (1)
#define SOC_IOCL_IOCG_026_iocg_026_pd_END (1)
#define SOC_IOCL_IOCG_026_iocg_026_st_START (3)
#define SOC_IOCL_IOCG_026_iocg_026_st_END (3)
#define SOC_IOCL_IOCG_026_iocg_026_ds0_START (4)
#define SOC_IOCL_IOCG_026_iocg_026_ds0_END (4)
#define SOC_IOCL_IOCG_026_iocg_026_ds1_START (5)
#define SOC_IOCL_IOCG_026_iocg_026_ds1_END (5)
#define SOC_IOCL_IOCG_026_iocg_026_ds2_START (6)
#define SOC_IOCL_IOCG_026_iocg_026_ds2_END (6)
#define SOC_IOCL_IOCG_026_iocg_026_sl_START (7)
#define SOC_IOCL_IOCG_026_iocg_026_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_027_pu : 1;
        unsigned int iocg_027_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_027_st : 1;
        unsigned int iocg_027_ds0 : 1;
        unsigned int iocg_027_ds1 : 1;
        unsigned int iocg_027_ds2 : 1;
        unsigned int iocg_027_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_027_UNION;
#endif
#define SOC_IOCL_IOCG_027_iocg_027_pu_START (0)
#define SOC_IOCL_IOCG_027_iocg_027_pu_END (0)
#define SOC_IOCL_IOCG_027_iocg_027_pd_START (1)
#define SOC_IOCL_IOCG_027_iocg_027_pd_END (1)
#define SOC_IOCL_IOCG_027_iocg_027_st_START (3)
#define SOC_IOCL_IOCG_027_iocg_027_st_END (3)
#define SOC_IOCL_IOCG_027_iocg_027_ds0_START (4)
#define SOC_IOCL_IOCG_027_iocg_027_ds0_END (4)
#define SOC_IOCL_IOCG_027_iocg_027_ds1_START (5)
#define SOC_IOCL_IOCG_027_iocg_027_ds1_END (5)
#define SOC_IOCL_IOCG_027_iocg_027_ds2_START (6)
#define SOC_IOCL_IOCG_027_iocg_027_ds2_END (6)
#define SOC_IOCL_IOCG_027_iocg_027_sl_START (7)
#define SOC_IOCL_IOCG_027_iocg_027_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_028_pu : 1;
        unsigned int iocg_028_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_028_st : 1;
        unsigned int iocg_028_ds0 : 1;
        unsigned int iocg_028_ds1 : 1;
        unsigned int iocg_028_ds2 : 1;
        unsigned int iocg_028_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_028_UNION;
#endif
#define SOC_IOCL_IOCG_028_iocg_028_pu_START (0)
#define SOC_IOCL_IOCG_028_iocg_028_pu_END (0)
#define SOC_IOCL_IOCG_028_iocg_028_pd_START (1)
#define SOC_IOCL_IOCG_028_iocg_028_pd_END (1)
#define SOC_IOCL_IOCG_028_iocg_028_st_START (3)
#define SOC_IOCL_IOCG_028_iocg_028_st_END (3)
#define SOC_IOCL_IOCG_028_iocg_028_ds0_START (4)
#define SOC_IOCL_IOCG_028_iocg_028_ds0_END (4)
#define SOC_IOCL_IOCG_028_iocg_028_ds1_START (5)
#define SOC_IOCL_IOCG_028_iocg_028_ds1_END (5)
#define SOC_IOCL_IOCG_028_iocg_028_ds2_START (6)
#define SOC_IOCL_IOCG_028_iocg_028_ds2_END (6)
#define SOC_IOCL_IOCG_028_iocg_028_sl_START (7)
#define SOC_IOCL_IOCG_028_iocg_028_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_029_pu : 1;
        unsigned int iocg_029_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_029_st : 1;
        unsigned int iocg_029_ds0 : 1;
        unsigned int iocg_029_ds1 : 1;
        unsigned int iocg_029_ds2 : 1;
        unsigned int iocg_029_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_029_UNION;
#endif
#define SOC_IOCL_IOCG_029_iocg_029_pu_START (0)
#define SOC_IOCL_IOCG_029_iocg_029_pu_END (0)
#define SOC_IOCL_IOCG_029_iocg_029_pd_START (1)
#define SOC_IOCL_IOCG_029_iocg_029_pd_END (1)
#define SOC_IOCL_IOCG_029_iocg_029_st_START (3)
#define SOC_IOCL_IOCG_029_iocg_029_st_END (3)
#define SOC_IOCL_IOCG_029_iocg_029_ds0_START (4)
#define SOC_IOCL_IOCG_029_iocg_029_ds0_END (4)
#define SOC_IOCL_IOCG_029_iocg_029_ds1_START (5)
#define SOC_IOCL_IOCG_029_iocg_029_ds1_END (5)
#define SOC_IOCL_IOCG_029_iocg_029_ds2_START (6)
#define SOC_IOCL_IOCG_029_iocg_029_ds2_END (6)
#define SOC_IOCL_IOCG_029_iocg_029_sl_START (7)
#define SOC_IOCL_IOCG_029_iocg_029_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_030_pu : 1;
        unsigned int iocg_030_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_030_st : 1;
        unsigned int iocg_030_ds0 : 1;
        unsigned int iocg_030_ds1 : 1;
        unsigned int iocg_030_ds2 : 1;
        unsigned int iocg_030_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_030_UNION;
#endif
#define SOC_IOCL_IOCG_030_iocg_030_pu_START (0)
#define SOC_IOCL_IOCG_030_iocg_030_pu_END (0)
#define SOC_IOCL_IOCG_030_iocg_030_pd_START (1)
#define SOC_IOCL_IOCG_030_iocg_030_pd_END (1)
#define SOC_IOCL_IOCG_030_iocg_030_st_START (3)
#define SOC_IOCL_IOCG_030_iocg_030_st_END (3)
#define SOC_IOCL_IOCG_030_iocg_030_ds0_START (4)
#define SOC_IOCL_IOCG_030_iocg_030_ds0_END (4)
#define SOC_IOCL_IOCG_030_iocg_030_ds1_START (5)
#define SOC_IOCL_IOCG_030_iocg_030_ds1_END (5)
#define SOC_IOCL_IOCG_030_iocg_030_ds2_START (6)
#define SOC_IOCL_IOCG_030_iocg_030_ds2_END (6)
#define SOC_IOCL_IOCG_030_iocg_030_sl_START (7)
#define SOC_IOCL_IOCG_030_iocg_030_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_031_pu : 1;
        unsigned int iocg_031_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_031_st : 1;
        unsigned int iocg_031_ds0 : 1;
        unsigned int iocg_031_ds1 : 1;
        unsigned int iocg_031_ds2 : 1;
        unsigned int iocg_031_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_031_UNION;
#endif
#define SOC_IOCL_IOCG_031_iocg_031_pu_START (0)
#define SOC_IOCL_IOCG_031_iocg_031_pu_END (0)
#define SOC_IOCL_IOCG_031_iocg_031_pd_START (1)
#define SOC_IOCL_IOCG_031_iocg_031_pd_END (1)
#define SOC_IOCL_IOCG_031_iocg_031_st_START (3)
#define SOC_IOCL_IOCG_031_iocg_031_st_END (3)
#define SOC_IOCL_IOCG_031_iocg_031_ds0_START (4)
#define SOC_IOCL_IOCG_031_iocg_031_ds0_END (4)
#define SOC_IOCL_IOCG_031_iocg_031_ds1_START (5)
#define SOC_IOCL_IOCG_031_iocg_031_ds1_END (5)
#define SOC_IOCL_IOCG_031_iocg_031_ds2_START (6)
#define SOC_IOCL_IOCG_031_iocg_031_ds2_END (6)
#define SOC_IOCL_IOCG_031_iocg_031_sl_START (7)
#define SOC_IOCL_IOCG_031_iocg_031_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_032_pu : 1;
        unsigned int iocg_032_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_032_st : 1;
        unsigned int iocg_032_ds0 : 1;
        unsigned int iocg_032_ds1 : 1;
        unsigned int iocg_032_ds2 : 1;
        unsigned int iocg_032_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_032_UNION;
#endif
#define SOC_IOCL_IOCG_032_iocg_032_pu_START (0)
#define SOC_IOCL_IOCG_032_iocg_032_pu_END (0)
#define SOC_IOCL_IOCG_032_iocg_032_pd_START (1)
#define SOC_IOCL_IOCG_032_iocg_032_pd_END (1)
#define SOC_IOCL_IOCG_032_iocg_032_st_START (3)
#define SOC_IOCL_IOCG_032_iocg_032_st_END (3)
#define SOC_IOCL_IOCG_032_iocg_032_ds0_START (4)
#define SOC_IOCL_IOCG_032_iocg_032_ds0_END (4)
#define SOC_IOCL_IOCG_032_iocg_032_ds1_START (5)
#define SOC_IOCL_IOCG_032_iocg_032_ds1_END (5)
#define SOC_IOCL_IOCG_032_iocg_032_ds2_START (6)
#define SOC_IOCL_IOCG_032_iocg_032_ds2_END (6)
#define SOC_IOCL_IOCG_032_iocg_032_sl_START (7)
#define SOC_IOCL_IOCG_032_iocg_032_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_033_pu : 1;
        unsigned int iocg_033_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_033_st : 1;
        unsigned int iocg_033_ds0 : 1;
        unsigned int iocg_033_ds1 : 1;
        unsigned int iocg_033_ds2 : 1;
        unsigned int iocg_033_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_033_UNION;
#endif
#define SOC_IOCL_IOCG_033_iocg_033_pu_START (0)
#define SOC_IOCL_IOCG_033_iocg_033_pu_END (0)
#define SOC_IOCL_IOCG_033_iocg_033_pd_START (1)
#define SOC_IOCL_IOCG_033_iocg_033_pd_END (1)
#define SOC_IOCL_IOCG_033_iocg_033_st_START (3)
#define SOC_IOCL_IOCG_033_iocg_033_st_END (3)
#define SOC_IOCL_IOCG_033_iocg_033_ds0_START (4)
#define SOC_IOCL_IOCG_033_iocg_033_ds0_END (4)
#define SOC_IOCL_IOCG_033_iocg_033_ds1_START (5)
#define SOC_IOCL_IOCG_033_iocg_033_ds1_END (5)
#define SOC_IOCL_IOCG_033_iocg_033_ds2_START (6)
#define SOC_IOCL_IOCG_033_iocg_033_ds2_END (6)
#define SOC_IOCL_IOCG_033_iocg_033_sl_START (7)
#define SOC_IOCL_IOCG_033_iocg_033_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_034_pu : 1;
        unsigned int iocg_034_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_034_st : 1;
        unsigned int iocg_034_ds0 : 1;
        unsigned int iocg_034_ds1 : 1;
        unsigned int iocg_034_ds2 : 1;
        unsigned int iocg_034_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_034_UNION;
#endif
#define SOC_IOCL_IOCG_034_iocg_034_pu_START (0)
#define SOC_IOCL_IOCG_034_iocg_034_pu_END (0)
#define SOC_IOCL_IOCG_034_iocg_034_pd_START (1)
#define SOC_IOCL_IOCG_034_iocg_034_pd_END (1)
#define SOC_IOCL_IOCG_034_iocg_034_st_START (3)
#define SOC_IOCL_IOCG_034_iocg_034_st_END (3)
#define SOC_IOCL_IOCG_034_iocg_034_ds0_START (4)
#define SOC_IOCL_IOCG_034_iocg_034_ds0_END (4)
#define SOC_IOCL_IOCG_034_iocg_034_ds1_START (5)
#define SOC_IOCL_IOCG_034_iocg_034_ds1_END (5)
#define SOC_IOCL_IOCG_034_iocg_034_ds2_START (6)
#define SOC_IOCL_IOCG_034_iocg_034_ds2_END (6)
#define SOC_IOCL_IOCG_034_iocg_034_sl_START (7)
#define SOC_IOCL_IOCG_034_iocg_034_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_035_pu : 1;
        unsigned int iocg_035_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_035_st : 1;
        unsigned int iocg_035_ds0 : 1;
        unsigned int iocg_035_ds1 : 1;
        unsigned int iocg_035_ds2 : 1;
        unsigned int iocg_035_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_035_UNION;
#endif
#define SOC_IOCL_IOCG_035_iocg_035_pu_START (0)
#define SOC_IOCL_IOCG_035_iocg_035_pu_END (0)
#define SOC_IOCL_IOCG_035_iocg_035_pd_START (1)
#define SOC_IOCL_IOCG_035_iocg_035_pd_END (1)
#define SOC_IOCL_IOCG_035_iocg_035_st_START (3)
#define SOC_IOCL_IOCG_035_iocg_035_st_END (3)
#define SOC_IOCL_IOCG_035_iocg_035_ds0_START (4)
#define SOC_IOCL_IOCG_035_iocg_035_ds0_END (4)
#define SOC_IOCL_IOCG_035_iocg_035_ds1_START (5)
#define SOC_IOCL_IOCG_035_iocg_035_ds1_END (5)
#define SOC_IOCL_IOCG_035_iocg_035_ds2_START (6)
#define SOC_IOCL_IOCG_035_iocg_035_ds2_END (6)
#define SOC_IOCL_IOCG_035_iocg_035_sl_START (7)
#define SOC_IOCL_IOCG_035_iocg_035_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_036_pu : 1;
        unsigned int iocg_036_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_036_st : 1;
        unsigned int iocg_036_ds0 : 1;
        unsigned int iocg_036_ds1 : 1;
        unsigned int iocg_036_ds2 : 1;
        unsigned int iocg_036_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_036_UNION;
#endif
#define SOC_IOCL_IOCG_036_iocg_036_pu_START (0)
#define SOC_IOCL_IOCG_036_iocg_036_pu_END (0)
#define SOC_IOCL_IOCG_036_iocg_036_pd_START (1)
#define SOC_IOCL_IOCG_036_iocg_036_pd_END (1)
#define SOC_IOCL_IOCG_036_iocg_036_st_START (3)
#define SOC_IOCL_IOCG_036_iocg_036_st_END (3)
#define SOC_IOCL_IOCG_036_iocg_036_ds0_START (4)
#define SOC_IOCL_IOCG_036_iocg_036_ds0_END (4)
#define SOC_IOCL_IOCG_036_iocg_036_ds1_START (5)
#define SOC_IOCL_IOCG_036_iocg_036_ds1_END (5)
#define SOC_IOCL_IOCG_036_iocg_036_ds2_START (6)
#define SOC_IOCL_IOCG_036_iocg_036_ds2_END (6)
#define SOC_IOCL_IOCG_036_iocg_036_sl_START (7)
#define SOC_IOCL_IOCG_036_iocg_036_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_037_pu : 1;
        unsigned int iocg_037_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_037_st : 1;
        unsigned int iocg_037_ds0 : 1;
        unsigned int iocg_037_ds1 : 1;
        unsigned int iocg_037_ds2 : 1;
        unsigned int iocg_037_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_037_UNION;
#endif
#define SOC_IOCL_IOCG_037_iocg_037_pu_START (0)
#define SOC_IOCL_IOCG_037_iocg_037_pu_END (0)
#define SOC_IOCL_IOCG_037_iocg_037_pd_START (1)
#define SOC_IOCL_IOCG_037_iocg_037_pd_END (1)
#define SOC_IOCL_IOCG_037_iocg_037_st_START (3)
#define SOC_IOCL_IOCG_037_iocg_037_st_END (3)
#define SOC_IOCL_IOCG_037_iocg_037_ds0_START (4)
#define SOC_IOCL_IOCG_037_iocg_037_ds0_END (4)
#define SOC_IOCL_IOCG_037_iocg_037_ds1_START (5)
#define SOC_IOCL_IOCG_037_iocg_037_ds1_END (5)
#define SOC_IOCL_IOCG_037_iocg_037_ds2_START (6)
#define SOC_IOCL_IOCG_037_iocg_037_ds2_END (6)
#define SOC_IOCL_IOCG_037_iocg_037_sl_START (7)
#define SOC_IOCL_IOCG_037_iocg_037_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_038_pu : 1;
        unsigned int iocg_038_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_038_st : 1;
        unsigned int iocg_038_ds0 : 1;
        unsigned int iocg_038_ds1 : 1;
        unsigned int iocg_038_ds2 : 1;
        unsigned int iocg_038_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_038_UNION;
#endif
#define SOC_IOCL_IOCG_038_iocg_038_pu_START (0)
#define SOC_IOCL_IOCG_038_iocg_038_pu_END (0)
#define SOC_IOCL_IOCG_038_iocg_038_pd_START (1)
#define SOC_IOCL_IOCG_038_iocg_038_pd_END (1)
#define SOC_IOCL_IOCG_038_iocg_038_st_START (3)
#define SOC_IOCL_IOCG_038_iocg_038_st_END (3)
#define SOC_IOCL_IOCG_038_iocg_038_ds0_START (4)
#define SOC_IOCL_IOCG_038_iocg_038_ds0_END (4)
#define SOC_IOCL_IOCG_038_iocg_038_ds1_START (5)
#define SOC_IOCL_IOCG_038_iocg_038_ds1_END (5)
#define SOC_IOCL_IOCG_038_iocg_038_ds2_START (6)
#define SOC_IOCL_IOCG_038_iocg_038_ds2_END (6)
#define SOC_IOCL_IOCG_038_iocg_038_sl_START (7)
#define SOC_IOCL_IOCG_038_iocg_038_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_01_pu : 1;
        unsigned int iocg_se_01_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_01_st : 1;
        unsigned int iocg_se_01_ds0 : 1;
        unsigned int iocg_se_01_ds1 : 1;
        unsigned int iocg_se_01_ds2 : 1;
        unsigned int iocg_se_01_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_SE_01_UNION;
#endif
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_pu_START (0)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_pu_END (0)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_pd_START (1)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_pd_END (1)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_st_START (3)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_st_END (3)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds0_START (4)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds0_END (4)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds1_START (5)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds1_END (5)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds2_START (6)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_ds2_END (6)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_sl_START (7)
#define SOC_IOCL_IOCG_SE_01_iocg_se_01_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_02_pu : 1;
        unsigned int iocg_se_02_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_02_st : 1;
        unsigned int iocg_se_02_ds0 : 1;
        unsigned int iocg_se_02_ds1 : 1;
        unsigned int iocg_se_02_ds2 : 1;
        unsigned int iocg_se_02_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_SE_02_UNION;
#endif
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_pu_START (0)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_pu_END (0)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_pd_START (1)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_pd_END (1)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_st_START (3)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_st_END (3)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds0_START (4)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds0_END (4)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds1_START (5)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds1_END (5)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds2_START (6)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_ds2_END (6)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_sl_START (7)
#define SOC_IOCL_IOCG_SE_02_iocg_se_02_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_039_pu : 1;
        unsigned int iocg_039_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_039_st : 1;
        unsigned int iocg_039_ds0 : 1;
        unsigned int iocg_039_ds1 : 1;
        unsigned int iocg_039_ds2 : 1;
        unsigned int iocg_039_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_039_UNION;
#endif
#define SOC_IOCL_IOCG_039_iocg_039_pu_START (0)
#define SOC_IOCL_IOCG_039_iocg_039_pu_END (0)
#define SOC_IOCL_IOCG_039_iocg_039_pd_START (1)
#define SOC_IOCL_IOCG_039_iocg_039_pd_END (1)
#define SOC_IOCL_IOCG_039_iocg_039_st_START (3)
#define SOC_IOCL_IOCG_039_iocg_039_st_END (3)
#define SOC_IOCL_IOCG_039_iocg_039_ds0_START (4)
#define SOC_IOCL_IOCG_039_iocg_039_ds0_END (4)
#define SOC_IOCL_IOCG_039_iocg_039_ds1_START (5)
#define SOC_IOCL_IOCG_039_iocg_039_ds1_END (5)
#define SOC_IOCL_IOCG_039_iocg_039_ds2_START (6)
#define SOC_IOCL_IOCG_039_iocg_039_ds2_END (6)
#define SOC_IOCL_IOCG_039_iocg_039_sl_START (7)
#define SOC_IOCL_IOCG_039_iocg_039_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_040_pu : 1;
        unsigned int iocg_040_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_040_st : 1;
        unsigned int iocg_040_ds0 : 1;
        unsigned int iocg_040_ds1 : 1;
        unsigned int iocg_040_ds2 : 1;
        unsigned int iocg_040_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_040_UNION;
#endif
#define SOC_IOCL_IOCG_040_iocg_040_pu_START (0)
#define SOC_IOCL_IOCG_040_iocg_040_pu_END (0)
#define SOC_IOCL_IOCG_040_iocg_040_pd_START (1)
#define SOC_IOCL_IOCG_040_iocg_040_pd_END (1)
#define SOC_IOCL_IOCG_040_iocg_040_st_START (3)
#define SOC_IOCL_IOCG_040_iocg_040_st_END (3)
#define SOC_IOCL_IOCG_040_iocg_040_ds0_START (4)
#define SOC_IOCL_IOCG_040_iocg_040_ds0_END (4)
#define SOC_IOCL_IOCG_040_iocg_040_ds1_START (5)
#define SOC_IOCL_IOCG_040_iocg_040_ds1_END (5)
#define SOC_IOCL_IOCG_040_iocg_040_ds2_START (6)
#define SOC_IOCL_IOCG_040_iocg_040_ds2_END (6)
#define SOC_IOCL_IOCG_040_iocg_040_sl_START (7)
#define SOC_IOCL_IOCG_040_iocg_040_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_041_pu : 1;
        unsigned int iocg_041_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_041_st : 1;
        unsigned int iocg_041_ds0 : 1;
        unsigned int iocg_041_ds1 : 1;
        unsigned int iocg_041_ds2 : 1;
        unsigned int iocg_041_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_041_UNION;
#endif
#define SOC_IOCL_IOCG_041_iocg_041_pu_START (0)
#define SOC_IOCL_IOCG_041_iocg_041_pu_END (0)
#define SOC_IOCL_IOCG_041_iocg_041_pd_START (1)
#define SOC_IOCL_IOCG_041_iocg_041_pd_END (1)
#define SOC_IOCL_IOCG_041_iocg_041_st_START (3)
#define SOC_IOCL_IOCG_041_iocg_041_st_END (3)
#define SOC_IOCL_IOCG_041_iocg_041_ds0_START (4)
#define SOC_IOCL_IOCG_041_iocg_041_ds0_END (4)
#define SOC_IOCL_IOCG_041_iocg_041_ds1_START (5)
#define SOC_IOCL_IOCG_041_iocg_041_ds1_END (5)
#define SOC_IOCL_IOCG_041_iocg_041_ds2_START (6)
#define SOC_IOCL_IOCG_041_iocg_041_ds2_END (6)
#define SOC_IOCL_IOCG_041_iocg_041_sl_START (7)
#define SOC_IOCL_IOCG_041_iocg_041_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_03_pu : 1;
        unsigned int iocg_se_03_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_03_st : 1;
        unsigned int iocg_se_03_ds0 : 1;
        unsigned int iocg_se_03_ds1 : 1;
        unsigned int iocg_se_03_ds2 : 1;
        unsigned int iocg_se_03_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_SE_03_UNION;
#endif
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_pu_START (0)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_pu_END (0)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_pd_START (1)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_pd_END (1)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_st_START (3)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_st_END (3)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds0_START (4)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds0_END (4)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds1_START (5)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds1_END (5)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds2_START (6)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_ds2_END (6)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_sl_START (7)
#define SOC_IOCL_IOCG_SE_03_iocg_se_03_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_042_pu : 1;
        unsigned int iocg_042_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_042_st : 1;
        unsigned int iocg_042_ds0 : 1;
        unsigned int iocg_042_ds1 : 1;
        unsigned int iocg_042_ds2 : 1;
        unsigned int iocg_042_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOCL_IOCG_042_UNION;
#endif
#define SOC_IOCL_IOCG_042_iocg_042_pu_START (0)
#define SOC_IOCL_IOCG_042_iocg_042_pu_END (0)
#define SOC_IOCL_IOCG_042_iocg_042_pd_START (1)
#define SOC_IOCL_IOCG_042_iocg_042_pd_END (1)
#define SOC_IOCL_IOCG_042_iocg_042_st_START (3)
#define SOC_IOCL_IOCG_042_iocg_042_st_END (3)
#define SOC_IOCL_IOCG_042_iocg_042_ds0_START (4)
#define SOC_IOCL_IOCG_042_iocg_042_ds0_END (4)
#define SOC_IOCL_IOCG_042_iocg_042_ds1_START (5)
#define SOC_IOCL_IOCG_042_iocg_042_ds1_END (5)
#define SOC_IOCL_IOCG_042_iocg_042_ds2_START (6)
#define SOC_IOCL_IOCG_042_iocg_042_ds2_END (6)
#define SOC_IOCL_IOCG_042_iocg_042_sl_START (7)
#define SOC_IOCL_IOCG_042_iocg_042_sl_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
