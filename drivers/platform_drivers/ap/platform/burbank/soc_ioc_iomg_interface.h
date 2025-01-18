#ifndef __SOC_IOC_IOMG_INTERFACE_H__
#define __SOC_IOC_IOMG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_IOMG_000_ADDR(base) ((base) + (0x000UL))
#define SOC_IOC_IOMG_001_ADDR(base) ((base) + (0x004UL))
#define SOC_IOC_IOMG_002_ADDR(base) ((base) + (0x008UL))
#define SOC_IOC_IOMG_003_ADDR(base) ((base) + (0x00CUL))
#define SOC_IOC_IOMG_004_ADDR(base) ((base) + (0x010UL))
#define SOC_IOC_IOMG_005_ADDR(base) ((base) + (0x014UL))
#define SOC_IOC_IOMG_006_ADDR(base) ((base) + (0x018UL))
#define SOC_IOC_IOMG_007_ADDR(base) ((base) + (0x01CUL))
#define SOC_IOC_IOMG_008_ADDR(base) ((base) + (0x020UL))
#define SOC_IOC_IOMG_009_ADDR(base) ((base) + (0x024UL))
#define SOC_IOC_IOMG_010_ADDR(base) ((base) + (0x028UL))
#define SOC_IOC_IOMG_011_ADDR(base) ((base) + (0x02CUL))
#define SOC_IOC_IOMG_012_ADDR(base) ((base) + (0x030UL))
#define SOC_IOC_IOMG_013_ADDR(base) ((base) + (0x034UL))
#define SOC_IOC_IOMG_014_ADDR(base) ((base) + (0x038UL))
#define SOC_IOC_IOMG_015_ADDR(base) ((base) + (0x03CUL))
#define SOC_IOC_IOMG_016_ADDR(base) ((base) + (0x040UL))
#define SOC_IOC_IOMG_017_ADDR(base) ((base) + (0x044UL))
#define SOC_IOC_IOMG_018_ADDR(base) ((base) + (0x048UL))
#define SOC_IOC_IOMG_019_ADDR(base) ((base) + (0x04CUL))
#define SOC_IOC_IOMG_SE_00_ADDR(base) ((base) + (0x700UL))
#define SOC_IOC_IOMG_020_ADDR(base) ((base) + (0x050UL))
#define SOC_IOC_IOMG_021_ADDR(base) ((base) + (0x054UL))
#define SOC_IOC_IOMG_022_ADDR(base) ((base) + (0x058UL))
#define SOC_IOC_IOMG_023_ADDR(base) ((base) + (0x05CUL))
#define SOC_IOC_IOMG_024_ADDR(base) ((base) + (0x060UL))
#define SOC_IOC_IOMG_025_ADDR(base) ((base) + (0x064UL))
#define SOC_IOC_IOMG_026_ADDR(base) ((base) + (0x068UL))
#define SOC_IOC_IOMG_027_ADDR(base) ((base) + (0x06CUL))
#define SOC_IOC_IOMG_028_ADDR(base) ((base) + (0x070UL))
#define SOC_IOC_IOMG_029_ADDR(base) ((base) + (0x074UL))
#define SOC_IOC_IOMG_030_ADDR(base) ((base) + (0x078UL))
#define SOC_IOC_IOMG_031_ADDR(base) ((base) + (0x07CUL))
#define SOC_IOC_IOMG_032_ADDR(base) ((base) + (0x080UL))
#define SOC_IOC_IOMG_033_ADDR(base) ((base) + (0x084UL))
#define SOC_IOC_IOMG_034_ADDR(base) ((base) + (0x088UL))
#define SOC_IOC_IOMG_035_ADDR(base) ((base) + (0x08CUL))
#define SOC_IOC_IOMG_036_ADDR(base) ((base) + (0x090UL))
#define SOC_IOC_IOMG_037_ADDR(base) ((base) + (0x094UL))
#define SOC_IOC_IOMG_SE_01_ADDR(base) ((base) + (0x704UL))
#define SOC_IOC_IOMG_SE_02_ADDR(base) ((base) + (0x708UL))
#define SOC_IOC_IOMG_038_ADDR(base) ((base) + (0x098UL))
#define SOC_IOC_IOMG_039_ADDR(base) ((base) + (0x09CUL))
#define SOC_IOC_IOMG_040_ADDR(base) ((base) + (0x0A0UL))
#define SOC_IOC_IOMG_SE_03_ADDR(base) ((base) + (0x70CUL))
#define SOC_IOC_IOMG_041_ADDR(base) ((base) + (0x0A4UL))
#define SOC_IOC_IOMG_SE_04_ADDR(base) ((base) + (0x710UL))
#define SOC_IOC_IOMG_SE_05_ADDR(base) ((base) + (0x714UL))
#define SOC_IOC_IOMG_SE_06_ADDR(base) ((base) + (0x718UL))
#define SOC_IOC_IOMG_SE_07_ADDR(base) ((base) + (0x71CUL))
#define SOC_IOC_IOMG_SE_08_ADDR(base) ((base) + (0x720UL))
#define SOC_IOC_IOMG_042_ADDR(base) ((base) + (0x0A8UL))
#define SOC_IOC_IOMG_043_ADDR(base) ((base) + (0x0ACUL))
#define SOC_IOC_IOMG_044_ADDR(base) ((base) + (0x0B0UL))
#define SOC_IOC_IOMG_SE_09_ADDR(base) ((base) + (0x724UL))
#define SOC_IOC_IOMG_SE_10_ADDR(base) ((base) + (0x728UL))
#define SOC_IOC_IOMG_SE_11_ADDR(base) ((base) + (0x72CUL))
#define SOC_IOC_IOMG_SE_12_ADDR(base) ((base) + (0x730UL))
#define SOC_IOC_IOMG_045_ADDR(base) ((base) + (0x0B4UL))
#define SOC_IOC_IOMG_046_ADDR(base) ((base) + (0x0B8UL))
#define SOC_IOC_IOMG_047_ADDR(base) ((base) + (0x0BCUL))
#define SOC_IOC_IOMG_048_ADDR(base) ((base) + (0x0C0UL))
#define SOC_IOC_IOMG_049_ADDR(base) ((base) + (0x0C4UL))
#define SOC_IOC_IOMG_050_ADDR(base) ((base) + (0x0C8UL))
#define SOC_IOC_IOMG_051_ADDR(base) ((base) + (0x0CCUL))
#define SOC_IOC_IOMG_052_ADDR(base) ((base) + (0x0D0UL))
#define SOC_IOC_IOMG_053_ADDR(base) ((base) + (0x0D4UL))
#define SOC_IOC_IOMG_054_ADDR(base) ((base) + (0x0D8UL))
#define SOC_IOC_IOMG_055_ADDR(base) ((base) + (0x0DCUL))
#define SOC_IOC_IOMG_056_ADDR(base) ((base) + (0x0E0UL))
#define SOC_IOC_IOMG_057_ADDR(base) ((base) + (0x0E4UL))
#define SOC_IOC_IOMG_058_ADDR(base) ((base) + (0x0E8UL))
#define SOC_IOC_IOMG_059_ADDR(base) ((base) + (0x0ECUL))
#define SOC_IOC_IOCG_005_ADDR(base) ((base) + (0x814UL))
#define SOC_IOC_IOCG_006_ADDR(base) ((base) + (0x818UL))
#define SOC_IOC_IOCG_007_ADDR(base) ((base) + (0x81CUL))
#else
#define SOC_IOC_IOMG_000_ADDR(base) ((base) + (0x000))
#define SOC_IOC_IOMG_001_ADDR(base) ((base) + (0x004))
#define SOC_IOC_IOMG_002_ADDR(base) ((base) + (0x008))
#define SOC_IOC_IOMG_003_ADDR(base) ((base) + (0x00C))
#define SOC_IOC_IOMG_004_ADDR(base) ((base) + (0x010))
#define SOC_IOC_IOMG_005_ADDR(base) ((base) + (0x014))
#define SOC_IOC_IOMG_006_ADDR(base) ((base) + (0x018))
#define SOC_IOC_IOMG_007_ADDR(base) ((base) + (0x01C))
#define SOC_IOC_IOMG_008_ADDR(base) ((base) + (0x020))
#define SOC_IOC_IOMG_009_ADDR(base) ((base) + (0x024))
#define SOC_IOC_IOMG_010_ADDR(base) ((base) + (0x028))
#define SOC_IOC_IOMG_011_ADDR(base) ((base) + (0x02C))
#define SOC_IOC_IOMG_012_ADDR(base) ((base) + (0x030))
#define SOC_IOC_IOMG_013_ADDR(base) ((base) + (0x034))
#define SOC_IOC_IOMG_014_ADDR(base) ((base) + (0x038))
#define SOC_IOC_IOMG_015_ADDR(base) ((base) + (0x03C))
#define SOC_IOC_IOMG_016_ADDR(base) ((base) + (0x040))
#define SOC_IOC_IOMG_017_ADDR(base) ((base) + (0x044))
#define SOC_IOC_IOMG_018_ADDR(base) ((base) + (0x048))
#define SOC_IOC_IOMG_019_ADDR(base) ((base) + (0x04C))
#define SOC_IOC_IOMG_SE_00_ADDR(base) ((base) + (0x700))
#define SOC_IOC_IOMG_020_ADDR(base) ((base) + (0x050))
#define SOC_IOC_IOMG_021_ADDR(base) ((base) + (0x054))
#define SOC_IOC_IOMG_022_ADDR(base) ((base) + (0x058))
#define SOC_IOC_IOMG_023_ADDR(base) ((base) + (0x05C))
#define SOC_IOC_IOMG_024_ADDR(base) ((base) + (0x060))
#define SOC_IOC_IOMG_025_ADDR(base) ((base) + (0x064))
#define SOC_IOC_IOMG_026_ADDR(base) ((base) + (0x068))
#define SOC_IOC_IOMG_027_ADDR(base) ((base) + (0x06C))
#define SOC_IOC_IOMG_028_ADDR(base) ((base) + (0x070))
#define SOC_IOC_IOMG_029_ADDR(base) ((base) + (0x074))
#define SOC_IOC_IOMG_030_ADDR(base) ((base) + (0x078))
#define SOC_IOC_IOMG_031_ADDR(base) ((base) + (0x07C))
#define SOC_IOC_IOMG_032_ADDR(base) ((base) + (0x080))
#define SOC_IOC_IOMG_033_ADDR(base) ((base) + (0x084))
#define SOC_IOC_IOMG_034_ADDR(base) ((base) + (0x088))
#define SOC_IOC_IOMG_035_ADDR(base) ((base) + (0x08C))
#define SOC_IOC_IOMG_036_ADDR(base) ((base) + (0x090))
#define SOC_IOC_IOMG_037_ADDR(base) ((base) + (0x094))
#define SOC_IOC_IOMG_SE_01_ADDR(base) ((base) + (0x704))
#define SOC_IOC_IOMG_SE_02_ADDR(base) ((base) + (0x708))
#define SOC_IOC_IOMG_038_ADDR(base) ((base) + (0x098))
#define SOC_IOC_IOMG_039_ADDR(base) ((base) + (0x09C))
#define SOC_IOC_IOMG_040_ADDR(base) ((base) + (0x0A0))
#define SOC_IOC_IOMG_SE_03_ADDR(base) ((base) + (0x70C))
#define SOC_IOC_IOMG_041_ADDR(base) ((base) + (0x0A4))
#define SOC_IOC_IOMG_SE_04_ADDR(base) ((base) + (0x710))
#define SOC_IOC_IOMG_SE_05_ADDR(base) ((base) + (0x714))
#define SOC_IOC_IOMG_SE_06_ADDR(base) ((base) + (0x718))
#define SOC_IOC_IOMG_SE_07_ADDR(base) ((base) + (0x71C))
#define SOC_IOC_IOMG_SE_08_ADDR(base) ((base) + (0x720))
#define SOC_IOC_IOMG_042_ADDR(base) ((base) + (0x0A8))
#define SOC_IOC_IOMG_043_ADDR(base) ((base) + (0x0AC))
#define SOC_IOC_IOMG_044_ADDR(base) ((base) + (0x0B0))
#define SOC_IOC_IOMG_SE_09_ADDR(base) ((base) + (0x724))
#define SOC_IOC_IOMG_SE_10_ADDR(base) ((base) + (0x728))
#define SOC_IOC_IOMG_SE_11_ADDR(base) ((base) + (0x72C))
#define SOC_IOC_IOMG_SE_12_ADDR(base) ((base) + (0x730))
#define SOC_IOC_IOMG_045_ADDR(base) ((base) + (0x0B4))
#define SOC_IOC_IOMG_046_ADDR(base) ((base) + (0x0B8))
#define SOC_IOC_IOMG_047_ADDR(base) ((base) + (0x0BC))
#define SOC_IOC_IOMG_048_ADDR(base) ((base) + (0x0C0))
#define SOC_IOC_IOMG_049_ADDR(base) ((base) + (0x0C4))
#define SOC_IOC_IOMG_050_ADDR(base) ((base) + (0x0C8))
#define SOC_IOC_IOMG_051_ADDR(base) ((base) + (0x0CC))
#define SOC_IOC_IOMG_052_ADDR(base) ((base) + (0x0D0))
#define SOC_IOC_IOMG_053_ADDR(base) ((base) + (0x0D4))
#define SOC_IOC_IOMG_054_ADDR(base) ((base) + (0x0D8))
#define SOC_IOC_IOMG_055_ADDR(base) ((base) + (0x0DC))
#define SOC_IOC_IOMG_056_ADDR(base) ((base) + (0x0E0))
#define SOC_IOC_IOMG_057_ADDR(base) ((base) + (0x0E4))
#define SOC_IOC_IOMG_058_ADDR(base) ((base) + (0x0E8))
#define SOC_IOC_IOMG_059_ADDR(base) ((base) + (0x0EC))
#define SOC_IOC_IOCG_005_ADDR(base) ((base) + (0x814))
#define SOC_IOC_IOCG_006_ADDR(base) ((base) + (0x818))
#define SOC_IOC_IOCG_007_ADDR(base) ((base) + (0x81C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_000 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_000_UNION;
#endif
#define SOC_IOC_IOMG_000_iomg_000_START (0)
#define SOC_IOC_IOMG_000_iomg_000_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_001 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_001_UNION;
#endif
#define SOC_IOC_IOMG_001_iomg_001_START (0)
#define SOC_IOC_IOMG_001_iomg_001_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_002 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_002_UNION;
#endif
#define SOC_IOC_IOMG_002_iomg_002_START (0)
#define SOC_IOC_IOMG_002_iomg_002_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_003 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_003_UNION;
#endif
#define SOC_IOC_IOMG_003_iomg_003_START (0)
#define SOC_IOC_IOMG_003_iomg_003_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_004 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_004_UNION;
#endif
#define SOC_IOC_IOMG_004_iomg_004_START (0)
#define SOC_IOC_IOMG_004_iomg_004_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_005 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_005_UNION;
#endif
#define SOC_IOC_IOMG_005_iomg_005_START (0)
#define SOC_IOC_IOMG_005_iomg_005_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_006 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_006_UNION;
#endif
#define SOC_IOC_IOMG_006_iomg_006_START (0)
#define SOC_IOC_IOMG_006_iomg_006_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_007 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_007_UNION;
#endif
#define SOC_IOC_IOMG_007_iomg_007_START (0)
#define SOC_IOC_IOMG_007_iomg_007_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_008 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_008_UNION;
#endif
#define SOC_IOC_IOMG_008_iomg_008_START (0)
#define SOC_IOC_IOMG_008_iomg_008_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_009 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_009_UNION;
#endif
#define SOC_IOC_IOMG_009_iomg_009_START (0)
#define SOC_IOC_IOMG_009_iomg_009_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_010 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_010_UNION;
#endif
#define SOC_IOC_IOMG_010_iomg_010_START (0)
#define SOC_IOC_IOMG_010_iomg_010_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_011 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_011_UNION;
#endif
#define SOC_IOC_IOMG_011_iomg_011_START (0)
#define SOC_IOC_IOMG_011_iomg_011_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_012 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_012_UNION;
#endif
#define SOC_IOC_IOMG_012_iomg_012_START (0)
#define SOC_IOC_IOMG_012_iomg_012_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_013 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_013_UNION;
#endif
#define SOC_IOC_IOMG_013_iomg_013_START (0)
#define SOC_IOC_IOMG_013_iomg_013_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_014 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_014_UNION;
#endif
#define SOC_IOC_IOMG_014_iomg_014_START (0)
#define SOC_IOC_IOMG_014_iomg_014_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_015 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_015_UNION;
#endif
#define SOC_IOC_IOMG_015_iomg_015_START (0)
#define SOC_IOC_IOMG_015_iomg_015_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_016 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_016_UNION;
#endif
#define SOC_IOC_IOMG_016_iomg_016_START (0)
#define SOC_IOC_IOMG_016_iomg_016_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_017 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_017_UNION;
#endif
#define SOC_IOC_IOMG_017_iomg_017_START (0)
#define SOC_IOC_IOMG_017_iomg_017_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_018 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_018_UNION;
#endif
#define SOC_IOC_IOMG_018_iomg_018_START (0)
#define SOC_IOC_IOMG_018_iomg_018_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_019 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_019_UNION;
#endif
#define SOC_IOC_IOMG_019_iomg_019_START (0)
#define SOC_IOC_IOMG_019_iomg_019_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_00 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_IOMG_SE_00_UNION;
#endif
#define SOC_IOC_IOMG_SE_00_iomg_se_00_START (0)
#define SOC_IOC_IOMG_SE_00_iomg_se_00_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_020 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_020_UNION;
#endif
#define SOC_IOC_IOMG_020_iomg_020_START (0)
#define SOC_IOC_IOMG_020_iomg_020_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_021 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_021_UNION;
#endif
#define SOC_IOC_IOMG_021_iomg_021_START (0)
#define SOC_IOC_IOMG_021_iomg_021_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_022 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_022_UNION;
#endif
#define SOC_IOC_IOMG_022_iomg_022_START (0)
#define SOC_IOC_IOMG_022_iomg_022_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_023 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_023_UNION;
#endif
#define SOC_IOC_IOMG_023_iomg_023_START (0)
#define SOC_IOC_IOMG_023_iomg_023_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_024 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_024_UNION;
#endif
#define SOC_IOC_IOMG_024_iomg_024_START (0)
#define SOC_IOC_IOMG_024_iomg_024_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_025 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_025_UNION;
#endif
#define SOC_IOC_IOMG_025_iomg_025_START (0)
#define SOC_IOC_IOMG_025_iomg_025_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_026 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_026_UNION;
#endif
#define SOC_IOC_IOMG_026_iomg_026_START (0)
#define SOC_IOC_IOMG_026_iomg_026_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_027 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_027_UNION;
#endif
#define SOC_IOC_IOMG_027_iomg_027_START (0)
#define SOC_IOC_IOMG_027_iomg_027_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_028 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_028_UNION;
#endif
#define SOC_IOC_IOMG_028_iomg_028_START (0)
#define SOC_IOC_IOMG_028_iomg_028_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_029 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_029_UNION;
#endif
#define SOC_IOC_IOMG_029_iomg_029_START (0)
#define SOC_IOC_IOMG_029_iomg_029_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_030 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_030_UNION;
#endif
#define SOC_IOC_IOMG_030_iomg_030_START (0)
#define SOC_IOC_IOMG_030_iomg_030_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_031 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_031_UNION;
#endif
#define SOC_IOC_IOMG_031_iomg_031_START (0)
#define SOC_IOC_IOMG_031_iomg_031_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_032 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_032_UNION;
#endif
#define SOC_IOC_IOMG_032_iomg_032_START (0)
#define SOC_IOC_IOMG_032_iomg_032_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_033 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_033_UNION;
#endif
#define SOC_IOC_IOMG_033_iomg_033_START (0)
#define SOC_IOC_IOMG_033_iomg_033_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_034 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_034_UNION;
#endif
#define SOC_IOC_IOMG_034_iomg_034_START (0)
#define SOC_IOC_IOMG_034_iomg_034_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_035 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_035_UNION;
#endif
#define SOC_IOC_IOMG_035_iomg_035_START (0)
#define SOC_IOC_IOMG_035_iomg_035_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_036 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_036_UNION;
#endif
#define SOC_IOC_IOMG_036_iomg_036_START (0)
#define SOC_IOC_IOMG_036_iomg_036_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_037 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_037_UNION;
#endif
#define SOC_IOC_IOMG_037_iomg_037_START (0)
#define SOC_IOC_IOMG_037_iomg_037_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_01 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_01_UNION;
#endif
#define SOC_IOC_IOMG_SE_01_iomg_se_01_START (0)
#define SOC_IOC_IOMG_SE_01_iomg_se_01_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_02 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_02_UNION;
#endif
#define SOC_IOC_IOMG_SE_02_iomg_se_02_START (0)
#define SOC_IOC_IOMG_SE_02_iomg_se_02_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_038 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_038_UNION;
#endif
#define SOC_IOC_IOMG_038_iomg_038_START (0)
#define SOC_IOC_IOMG_038_iomg_038_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_039 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_039_UNION;
#endif
#define SOC_IOC_IOMG_039_iomg_039_START (0)
#define SOC_IOC_IOMG_039_iomg_039_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_040 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_040_UNION;
#endif
#define SOC_IOC_IOMG_040_iomg_040_START (0)
#define SOC_IOC_IOMG_040_iomg_040_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_03 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_03_UNION;
#endif
#define SOC_IOC_IOMG_SE_03_iomg_se_03_START (0)
#define SOC_IOC_IOMG_SE_03_iomg_se_03_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_041 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_041_UNION;
#endif
#define SOC_IOC_IOMG_041_iomg_041_START (0)
#define SOC_IOC_IOMG_041_iomg_041_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_04 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_04_UNION;
#endif
#define SOC_IOC_IOMG_SE_04_iomg_se_04_START (0)
#define SOC_IOC_IOMG_SE_04_iomg_se_04_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_05 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_05_UNION;
#endif
#define SOC_IOC_IOMG_SE_05_iomg_se_05_START (0)
#define SOC_IOC_IOMG_SE_05_iomg_se_05_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_06 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_06_UNION;
#endif
#define SOC_IOC_IOMG_SE_06_iomg_se_06_START (0)
#define SOC_IOC_IOMG_SE_06_iomg_se_06_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_07 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_07_UNION;
#endif
#define SOC_IOC_IOMG_SE_07_iomg_se_07_START (0)
#define SOC_IOC_IOMG_SE_07_iomg_se_07_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_08 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_08_UNION;
#endif
#define SOC_IOC_IOMG_SE_08_iomg_se_08_START (0)
#define SOC_IOC_IOMG_SE_08_iomg_se_08_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_042 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_042_UNION;
#endif
#define SOC_IOC_IOMG_042_iomg_042_START (0)
#define SOC_IOC_IOMG_042_iomg_042_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_043 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_043_UNION;
#endif
#define SOC_IOC_IOMG_043_iomg_043_START (0)
#define SOC_IOC_IOMG_043_iomg_043_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_044 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_044_UNION;
#endif
#define SOC_IOC_IOMG_044_iomg_044_START (0)
#define SOC_IOC_IOMG_044_iomg_044_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_09 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_09_UNION;
#endif
#define SOC_IOC_IOMG_SE_09_iomg_se_09_START (0)
#define SOC_IOC_IOMG_SE_09_iomg_se_09_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_10 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_10_UNION;
#endif
#define SOC_IOC_IOMG_SE_10_iomg_se_10_START (0)
#define SOC_IOC_IOMG_SE_10_iomg_se_10_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_11 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_11_UNION;
#endif
#define SOC_IOC_IOMG_SE_11_iomg_se_11_START (0)
#define SOC_IOC_IOMG_SE_11_iomg_se_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_12 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_SE_12_UNION;
#endif
#define SOC_IOC_IOMG_SE_12_iomg_se_12_START (0)
#define SOC_IOC_IOMG_SE_12_iomg_se_12_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_045 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_045_UNION;
#endif
#define SOC_IOC_IOMG_045_iomg_045_START (0)
#define SOC_IOC_IOMG_045_iomg_045_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_046 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_046_UNION;
#endif
#define SOC_IOC_IOMG_046_iomg_046_START (0)
#define SOC_IOC_IOMG_046_iomg_046_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_047 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_IOMG_047_UNION;
#endif
#define SOC_IOC_IOMG_047_iomg_047_START (0)
#define SOC_IOC_IOMG_047_iomg_047_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_048 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_048_UNION;
#endif
#define SOC_IOC_IOMG_048_iomg_048_START (0)
#define SOC_IOC_IOMG_048_iomg_048_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_049 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_049_UNION;
#endif
#define SOC_IOC_IOMG_049_iomg_049_START (0)
#define SOC_IOC_IOMG_049_iomg_049_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_050 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_050_UNION;
#endif
#define SOC_IOC_IOMG_050_iomg_050_START (0)
#define SOC_IOC_IOMG_050_iomg_050_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_051 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_051_UNION;
#endif
#define SOC_IOC_IOMG_051_iomg_051_START (0)
#define SOC_IOC_IOMG_051_iomg_051_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_052 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_052_UNION;
#endif
#define SOC_IOC_IOMG_052_iomg_052_START (0)
#define SOC_IOC_IOMG_052_iomg_052_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_053 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_053_UNION;
#endif
#define SOC_IOC_IOMG_053_iomg_053_START (0)
#define SOC_IOC_IOMG_053_iomg_053_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_054 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_054_UNION;
#endif
#define SOC_IOC_IOMG_054_iomg_054_START (0)
#define SOC_IOC_IOMG_054_iomg_054_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_055 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_055_UNION;
#endif
#define SOC_IOC_IOMG_055_iomg_055_START (0)
#define SOC_IOC_IOMG_055_iomg_055_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_056 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_IOMG_056_UNION;
#endif
#define SOC_IOC_IOMG_056_iomg_056_START (0)
#define SOC_IOC_IOMG_056_iomg_056_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_057 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_IOMG_057_UNION;
#endif
#define SOC_IOC_IOMG_057_iomg_057_START (0)
#define SOC_IOC_IOMG_057_iomg_057_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_058 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_058_UNION;
#endif
#define SOC_IOC_IOMG_058_iomg_058_START (0)
#define SOC_IOC_IOMG_058_iomg_058_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_059 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_IOMG_059_UNION;
#endif
#define SOC_IOC_IOMG_059_iomg_059_START (0)
#define SOC_IOC_IOMG_059_iomg_059_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_005_pu : 1;
        unsigned int iocg_005_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_005_st : 1;
        unsigned int iocg_005_ds0 : 1;
        unsigned int iocg_005_ds1 : 1;
        unsigned int iocg_005_ds2 : 1;
        unsigned int iocg_005_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_IOCG_005_UNION;
#endif
#define SOC_IOC_IOCG_005_iocg_005_pu_START (0)
#define SOC_IOC_IOCG_005_iocg_005_pu_END (0)
#define SOC_IOC_IOCG_005_iocg_005_pd_START (1)
#define SOC_IOC_IOCG_005_iocg_005_pd_END (1)
#define SOC_IOC_IOCG_005_iocg_005_st_START (3)
#define SOC_IOC_IOCG_005_iocg_005_st_END (3)
#define SOC_IOC_IOCG_005_iocg_005_ds0_START (4)
#define SOC_IOC_IOCG_005_iocg_005_ds0_END (4)
#define SOC_IOC_IOCG_005_iocg_005_ds1_START (5)
#define SOC_IOC_IOCG_005_iocg_005_ds1_END (5)
#define SOC_IOC_IOCG_005_iocg_005_ds2_START (6)
#define SOC_IOC_IOCG_005_iocg_005_ds2_END (6)
#define SOC_IOC_IOCG_005_iocg_005_sl_START (7)
#define SOC_IOC_IOCG_005_iocg_005_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_006_pu : 1;
        unsigned int iocg_006_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_006_st : 1;
        unsigned int iocg_006_ds0 : 1;
        unsigned int iocg_006_ds1 : 1;
        unsigned int iocg_006_ds2 : 1;
        unsigned int iocg_006_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_IOCG_006_UNION;
#endif
#define SOC_IOC_IOCG_006_iocg_006_pu_START (0)
#define SOC_IOC_IOCG_006_iocg_006_pu_END (0)
#define SOC_IOC_IOCG_006_iocg_006_pd_START (1)
#define SOC_IOC_IOCG_006_iocg_006_pd_END (1)
#define SOC_IOC_IOCG_006_iocg_006_st_START (3)
#define SOC_IOC_IOCG_006_iocg_006_st_END (3)
#define SOC_IOC_IOCG_006_iocg_006_ds0_START (4)
#define SOC_IOC_IOCG_006_iocg_006_ds0_END (4)
#define SOC_IOC_IOCG_006_iocg_006_ds1_START (5)
#define SOC_IOC_IOCG_006_iocg_006_ds1_END (5)
#define SOC_IOC_IOCG_006_iocg_006_ds2_START (6)
#define SOC_IOC_IOCG_006_iocg_006_ds2_END (6)
#define SOC_IOC_IOCG_006_iocg_006_sl_START (7)
#define SOC_IOC_IOCG_006_iocg_006_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_007_pu : 1;
        unsigned int iocg_007_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_007_st : 1;
        unsigned int iocg_007_ds0 : 1;
        unsigned int iocg_007_ds1 : 1;
        unsigned int iocg_007_ds2 : 1;
        unsigned int iocg_007_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_IOCG_007_UNION;
#endif
#define SOC_IOC_IOCG_007_iocg_007_pu_START (0)
#define SOC_IOC_IOCG_007_iocg_007_pu_END (0)
#define SOC_IOC_IOCG_007_iocg_007_pd_START (1)
#define SOC_IOC_IOCG_007_iocg_007_pd_END (1)
#define SOC_IOC_IOCG_007_iocg_007_st_START (3)
#define SOC_IOC_IOCG_007_iocg_007_st_END (3)
#define SOC_IOC_IOCG_007_iocg_007_ds0_START (4)
#define SOC_IOC_IOCG_007_iocg_007_ds0_END (4)
#define SOC_IOC_IOCG_007_iocg_007_ds1_START (5)
#define SOC_IOC_IOCG_007_iocg_007_ds1_END (5)
#define SOC_IOC_IOCG_007_iocg_007_ds2_START (6)
#define SOC_IOC_IOCG_007_iocg_007_ds2_END (6)
#define SOC_IOC_IOCG_007_iocg_007_sl_START (7)
#define SOC_IOC_IOCG_007_iocg_007_sl_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
