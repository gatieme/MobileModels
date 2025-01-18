#ifndef __SOC_IOC_AO_INTERFACE_H__
#define __SOC_IOC_AO_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_AO_IOMG_000_ADDR(base) ((base) + (0x000UL))
#define SOC_IOC_AO_IOMG_001_ADDR(base) ((base) + (0x004UL))
#define SOC_IOC_AO_IOMG_002_ADDR(base) ((base) + (0x008UL))
#define SOC_IOC_AO_IOMG_003_ADDR(base) ((base) + (0x00CUL))
#define SOC_IOC_AO_IOMG_004_ADDR(base) ((base) + (0x010UL))
#define SOC_IOC_AO_IOMG_SE_00_ADDR(base) ((base) + (0x700UL))
#define SOC_IOC_AO_IOMG_005_ADDR(base) ((base) + (0x014UL))
#define SOC_IOC_AO_IOMG_006_ADDR(base) ((base) + (0x018UL))
#define SOC_IOC_AO_IOMG_007_ADDR(base) ((base) + (0x01CUL))
#define SOC_IOC_AO_IOMG_008_ADDR(base) ((base) + (0x020UL))
#define SOC_IOC_AO_IOMG_009_ADDR(base) ((base) + (0x024UL))
#define SOC_IOC_AO_IOMG_010_ADDR(base) ((base) + (0x028UL))
#define SOC_IOC_AO_IOMG_011_ADDR(base) ((base) + (0x02CUL))
#define SOC_IOC_AO_IOMG_012_ADDR(base) ((base) + (0x030UL))
#define SOC_IOC_AO_IOMG_013_ADDR(base) ((base) + (0x034UL))
#define SOC_IOC_AO_IOMG_014_ADDR(base) ((base) + (0x038UL))
#define SOC_IOC_AO_IOMG_015_ADDR(base) ((base) + (0x03CUL))
#define SOC_IOC_AO_IOMG_016_ADDR(base) ((base) + (0x040UL))
#define SOC_IOC_AO_IOMG_017_ADDR(base) ((base) + (0x044UL))
#define SOC_IOC_AO_IOMG_018_ADDR(base) ((base) + (0x048UL))
#define SOC_IOC_AO_IOMG_SE_01_ADDR(base) ((base) + (0x704UL))
#define SOC_IOC_AO_IOMG_SE_02_ADDR(base) ((base) + (0x708UL))
#define SOC_IOC_AO_IOMG_SE_03_ADDR(base) ((base) + (0x70CUL))
#define SOC_IOC_AO_IOMG_SE_04_ADDR(base) ((base) + (0x710UL))
#define SOC_IOC_AO_IOMG_019_ADDR(base) ((base) + (0x04CUL))
#define SOC_IOC_AO_IOMG_020_ADDR(base) ((base) + (0x050UL))
#define SOC_IOC_AO_IOMG_021_ADDR(base) ((base) + (0x054UL))
#define SOC_IOC_AO_IOMG_022_ADDR(base) ((base) + (0x058UL))
#define SOC_IOC_AO_IOMG_023_ADDR(base) ((base) + (0x05CUL))
#define SOC_IOC_AO_IOMG_024_ADDR(base) ((base) + (0x060UL))
#define SOC_IOC_AO_IOMG_SE_05_ADDR(base) ((base) + (0x714UL))
#define SOC_IOC_AO_IOMG_SE_06_ADDR(base) ((base) + (0x718UL))
#define SOC_IOC_AO_IOMG_SE_07_ADDR(base) ((base) + (0x71CUL))
#define SOC_IOC_AO_IOMG_SE_08_ADDR(base) ((base) + (0x720UL))
#define SOC_IOC_AO_IOMG_SE_09_ADDR(base) ((base) + (0x724UL))
#define SOC_IOC_AO_IOMG_SE_10_ADDR(base) ((base) + (0x728UL))
#define SOC_IOC_AO_IOMG_SE_11_ADDR(base) ((base) + (0x72CUL))
#define SOC_IOC_AO_IOMG_SE_12_ADDR(base) ((base) + (0x730UL))
#define SOC_IOC_AO_IOMG_SE_13_ADDR(base) ((base) + (0x734UL))
#define SOC_IOC_AO_IOMG_SE_14_ADDR(base) ((base) + (0x738UL))
#define SOC_IOC_AO_IOMG_SE_15_ADDR(base) ((base) + (0x73CUL))
#define SOC_IOC_AO_IOMG_SE_16_ADDR(base) ((base) + (0x740UL))
#define SOC_IOC_AO_IOMG_SE_17_ADDR(base) ((base) + (0x744UL))
#define SOC_IOC_AO_IOMG_SE_18_ADDR(base) ((base) + (0x748UL))
#define SOC_IOC_AO_IOMG_SE_19_ADDR(base) ((base) + (0x74CUL))
#define SOC_IOC_AO_IOMG_SE_20_ADDR(base) ((base) + (0x750UL))
#define SOC_IOC_AO_IOMG_SE_21_ADDR(base) ((base) + (0x754UL))
#define SOC_IOC_AO_IOMG_SE_22_ADDR(base) ((base) + (0x758UL))
#define SOC_IOC_AO_IOMG_SE_23_ADDR(base) ((base) + (0x75CUL))
#define SOC_IOC_AO_IOMG_SE_24_ADDR(base) ((base) + (0x760UL))
#define SOC_IOC_AO_IOMG_SE_25_ADDR(base) ((base) + (0x764UL))
#define SOC_IOC_AO_IOMG_SE_26_ADDR(base) ((base) + (0x768UL))
#define SOC_IOC_AO_IOMG_SE_27_ADDR(base) ((base) + (0x76CUL))
#define SOC_IOC_AO_IOMG_SE_28_ADDR(base) ((base) + (0x770UL))
#define SOC_IOC_AO_IOMG_SE_29_ADDR(base) ((base) + (0x774UL))
#define SOC_IOC_AO_IOMG_SE_30_ADDR(base) ((base) + (0x778UL))
#define SOC_IOC_AO_IOMG_SE_31_ADDR(base) ((base) + (0x77CUL))
#define SOC_IOC_AO_IOMG_SE_32_ADDR(base) ((base) + (0x780UL))
#define SOC_IOC_AO_IOMG_SE_33_ADDR(base) ((base) + (0x784UL))
#define SOC_IOC_AO_IOMG_SE_34_ADDR(base) ((base) + (0x788UL))
#define SOC_IOC_AO_IOMG_SE_35_ADDR(base) ((base) + (0x78CUL))
#define SOC_IOC_AO_IOMG_SE_36_ADDR(base) ((base) + (0x790UL))
#define SOC_IOC_AO_IOMG_SE_37_ADDR(base) ((base) + (0x794UL))
#define SOC_IOC_AO_IOMG_SE_38_ADDR(base) ((base) + (0x798UL))
#define SOC_IOC_AO_IOMG_SE_39_ADDR(base) ((base) + (0x79CUL))
#define SOC_IOC_AO_IOMG_SE_40_ADDR(base) ((base) + (0x7A0UL))
#define SOC_IOC_AO_IOMG_SE_41_ADDR(base) ((base) + (0x7A4UL))
#define SOC_IOC_AO_IOMG_SE_42_ADDR(base) ((base) + (0x7A8UL))
#define SOC_IOC_AO_IOMG_SE_43_ADDR(base) ((base) + (0x7ACUL))
#define SOC_IOC_AO_IOMG_SE_44_ADDR(base) ((base) + (0x7B0UL))
#define SOC_IOC_AO_IOMG_SE_45_ADDR(base) ((base) + (0x7B4UL))
#define SOC_IOC_AO_IOMG_SE_46_ADDR(base) ((base) + (0x7B8UL))
#define SOC_IOC_AO_IOMG_SE_47_ADDR(base) ((base) + (0x7BCUL))
#define SOC_IOC_AO_IOMG_SE_48_ADDR(base) ((base) + (0x7C0UL))
#define SOC_IOC_AO_IOMG_SE_49_ADDR(base) ((base) + (0x7C4UL))
#define SOC_IOC_AO_IOMG_SE_50_ADDR(base) ((base) + (0x7C8UL))
#define SOC_IOC_AO_IOMG_SE_51_ADDR(base) ((base) + (0x7CCUL))
#define SOC_IOC_AO_IOMG_SE_52_ADDR(base) ((base) + (0x7D0UL))
#define SOC_IOC_AO_IOMG_SE_53_ADDR(base) ((base) + (0x7D4UL))
#define SOC_IOC_AO_IOMG_SE_54_ADDR(base) ((base) + (0x7D8UL))
#define SOC_IOC_AO_IOMG_SE_55_ADDR(base) ((base) + (0x7DCUL))
#define SOC_IOC_AO_IOCG_000_ADDR(base) ((base) + (0x800UL))
#define SOC_IOC_AO_IOCG_001_ADDR(base) ((base) + (0x804UL))
#define SOC_IOC_AO_IOCG_002_ADDR(base) ((base) + (0x808UL))
#define SOC_IOC_AO_IOCG_003_ADDR(base) ((base) + (0x80CUL))
#define SOC_IOC_AO_IOCG_004_ADDR(base) ((base) + (0x810UL))
#define SOC_IOC_AO_IOCG_005_ADDR(base) ((base) + (0x814UL))
#define SOC_IOC_AO_IOCG_006_ADDR(base) ((base) + (0x818UL))
#define SOC_IOC_AO_IOCG_007_ADDR(base) ((base) + (0x81CUL))
#define SOC_IOC_AO_IOCG_008_ADDR(base) ((base) + (0x820UL))
#define SOC_IOC_AO_IOCG_009_ADDR(base) ((base) + (0x824UL))
#define SOC_IOC_AO_IOCG_010_ADDR(base) ((base) + (0x828UL))
#define SOC_IOC_AO_IOCG_011_ADDR(base) ((base) + (0x82CUL))
#define SOC_IOC_AO_IOCG_012_ADDR(base) ((base) + (0x830UL))
#define SOC_IOC_AO_IOCG_SE_00_ADDR(base) ((base) + (0xF00UL))
#define SOC_IOC_AO_IOCG_013_ADDR(base) ((base) + (0x834UL))
#define SOC_IOC_AO_IOCG_014_ADDR(base) ((base) + (0x838UL))
#define SOC_IOC_AO_IOCG_015_ADDR(base) ((base) + (0x83CUL))
#define SOC_IOC_AO_IOCG_016_ADDR(base) ((base) + (0x840UL))
#define SOC_IOC_AO_IOCG_017_ADDR(base) ((base) + (0x844UL))
#define SOC_IOC_AO_IOCG_018_ADDR(base) ((base) + (0x848UL))
#define SOC_IOC_AO_IOCG_019_ADDR(base) ((base) + (0x84CUL))
#define SOC_IOC_AO_IOCG_020_ADDR(base) ((base) + (0x850UL))
#define SOC_IOC_AO_IOCG_021_ADDR(base) ((base) + (0x854UL))
#define SOC_IOC_AO_IOCG_022_ADDR(base) ((base) + (0x858UL))
#define SOC_IOC_AO_IOCG_023_ADDR(base) ((base) + (0x85CUL))
#define SOC_IOC_AO_IOCG_024_ADDR(base) ((base) + (0x860UL))
#define SOC_IOC_AO_IOCG_025_ADDR(base) ((base) + (0x864UL))
#define SOC_IOC_AO_IOCG_026_ADDR(base) ((base) + (0x868UL))
#define SOC_IOC_AO_IOCG_027_ADDR(base) ((base) + (0x86CUL))
#define SOC_IOC_AO_IOCG_028_ADDR(base) ((base) + (0x870UL))
#define SOC_IOC_AO_IOCG_029_ADDR(base) ((base) + (0x874UL))
#define SOC_IOC_AO_IOCG_SE_01_ADDR(base) ((base) + (0xF04UL))
#define SOC_IOC_AO_IOCG_SE_02_ADDR(base) ((base) + (0xF08UL))
#define SOC_IOC_AO_IOCG_SE_03_ADDR(base) ((base) + (0xF0CUL))
#define SOC_IOC_AO_IOCG_SE_04_ADDR(base) ((base) + (0xF10UL))
#define SOC_IOC_AO_IOCG_030_ADDR(base) ((base) + (0x878UL))
#define SOC_IOC_AO_IOCG_031_ADDR(base) ((base) + (0x87CUL))
#define SOC_IOC_AO_IOCG_032_ADDR(base) ((base) + (0x880UL))
#define SOC_IOC_AO_IOCG_033_ADDR(base) ((base) + (0x884UL))
#define SOC_IOC_AO_IOCG_034_ADDR(base) ((base) + (0x888UL))
#define SOC_IOC_AO_IOCG_035_ADDR(base) ((base) + (0x88CUL))
#define SOC_IOC_AO_IOCG_036_ADDR(base) ((base) + (0x890UL))
#define SOC_IOC_AO_IOCG_037_ADDR(base) ((base) + (0x894UL))
#define SOC_IOC_AO_IOCG_038_ADDR(base) ((base) + (0x898UL))
#define SOC_IOC_AO_IOCG_SE_05_ADDR(base) ((base) + (0xF14UL))
#define SOC_IOC_AO_IOCG_SE_06_ADDR(base) ((base) + (0xF18UL))
#define SOC_IOC_AO_IOCG_SE_07_ADDR(base) ((base) + (0xF1CUL))
#define SOC_IOC_AO_IOCG_SE_08_ADDR(base) ((base) + (0xF20UL))
#define SOC_IOC_AO_IOCG_SE_09_ADDR(base) ((base) + (0xF24UL))
#define SOC_IOC_AO_IOCG_SE_10_ADDR(base) ((base) + (0xF28UL))
#define SOC_IOC_AO_IOCG_SE_11_ADDR(base) ((base) + (0xF2CUL))
#define SOC_IOC_AO_IOCG_SE_12_ADDR(base) ((base) + (0xF30UL))
#define SOC_IOC_AO_IOCG_SE_13_ADDR(base) ((base) + (0xF34UL))
#define SOC_IOC_AO_IOCG_SE_14_ADDR(base) ((base) + (0xF38UL))
#define SOC_IOC_AO_IOCG_SE_15_ADDR(base) ((base) + (0xF3CUL))
#define SOC_IOC_AO_IOCG_SE_16_ADDR(base) ((base) + (0xF40UL))
#define SOC_IOC_AO_IOCG_SE_17_ADDR(base) ((base) + (0xF44UL))
#define SOC_IOC_AO_IOCG_SE_18_ADDR(base) ((base) + (0xF48UL))
#define SOC_IOC_AO_IOCG_SE_19_ADDR(base) ((base) + (0xF4CUL))
#define SOC_IOC_AO_IOCG_SE_20_ADDR(base) ((base) + (0xF50UL))
#define SOC_IOC_AO_IOCG_SE_21_ADDR(base) ((base) + (0xF54UL))
#define SOC_IOC_AO_IOCG_SE_22_ADDR(base) ((base) + (0xF58UL))
#define SOC_IOC_AO_IOCG_SE_23_ADDR(base) ((base) + (0xF5CUL))
#define SOC_IOC_AO_IOCG_SE_24_ADDR(base) ((base) + (0xF60UL))
#define SOC_IOC_AO_IOCG_SE_25_ADDR(base) ((base) + (0xF64UL))
#define SOC_IOC_AO_IOCG_SE_26_ADDR(base) ((base) + (0xF68UL))
#define SOC_IOC_AO_IOCG_SE_27_ADDR(base) ((base) + (0xF6CUL))
#define SOC_IOC_AO_IOCG_SE_28_ADDR(base) ((base) + (0xF70UL))
#define SOC_IOC_AO_IOCG_SE_29_ADDR(base) ((base) + (0xF74UL))
#define SOC_IOC_AO_IOCG_SE_30_ADDR(base) ((base) + (0xF78UL))
#define SOC_IOC_AO_IOCG_SE_31_ADDR(base) ((base) + (0xF7CUL))
#define SOC_IOC_AO_IOCG_SE_32_ADDR(base) ((base) + (0xF80UL))
#define SOC_IOC_AO_IOCG_SE_33_ADDR(base) ((base) + (0xF84UL))
#define SOC_IOC_AO_IOCG_SE_34_ADDR(base) ((base) + (0xF88UL))
#define SOC_IOC_AO_IOCG_SE_35_ADDR(base) ((base) + (0xF8CUL))
#define SOC_IOC_AO_IOCG_SE_36_ADDR(base) ((base) + (0xF90UL))
#define SOC_IOC_AO_IOCG_SE_37_ADDR(base) ((base) + (0xF94UL))
#define SOC_IOC_AO_IOCG_SE_38_ADDR(base) ((base) + (0xF98UL))
#define SOC_IOC_AO_IOCG_SE_39_ADDR(base) ((base) + (0xF9CUL))
#define SOC_IOC_AO_IOCG_SE_40_ADDR(base) ((base) + (0xFA0UL))
#define SOC_IOC_AO_IOCG_SE_41_ADDR(base) ((base) + (0xFA4UL))
#define SOC_IOC_AO_IOCG_SE_42_ADDR(base) ((base) + (0xFA8UL))
#define SOC_IOC_AO_IOCG_SE_43_ADDR(base) ((base) + (0xFACUL))
#define SOC_IOC_AO_IOCG_SE_44_ADDR(base) ((base) + (0xFB0UL))
#define SOC_IOC_AO_IOCG_SE_45_ADDR(base) ((base) + (0xFB4UL))
#define SOC_IOC_AO_IOCG_SE_46_ADDR(base) ((base) + (0xFB8UL))
#define SOC_IOC_AO_IOCG_SE_47_ADDR(base) ((base) + (0xFBCUL))
#define SOC_IOC_AO_IOCG_SE_48_ADDR(base) ((base) + (0xFC0UL))
#define SOC_IOC_AO_IOCG_SE_49_ADDR(base) ((base) + (0xFC4UL))
#define SOC_IOC_AO_IOCG_SE_50_ADDR(base) ((base) + (0xFC8UL))
#define SOC_IOC_AO_IOCG_SE_51_ADDR(base) ((base) + (0xFCCUL))
#define SOC_IOC_AO_IOCG_SE_52_ADDR(base) ((base) + (0xFD0UL))
#define SOC_IOC_AO_IOCG_SE_53_ADDR(base) ((base) + (0xFD4UL))
#define SOC_IOC_AO_IOCG_SE_54_ADDR(base) ((base) + (0xFD8UL))
#define SOC_IOC_AO_IOCG_SE_55_ADDR(base) ((base) + (0xFDCUL))
#else
#define SOC_IOC_AO_IOMG_000_ADDR(base) ((base) + (0x000))
#define SOC_IOC_AO_IOMG_001_ADDR(base) ((base) + (0x004))
#define SOC_IOC_AO_IOMG_002_ADDR(base) ((base) + (0x008))
#define SOC_IOC_AO_IOMG_003_ADDR(base) ((base) + (0x00C))
#define SOC_IOC_AO_IOMG_004_ADDR(base) ((base) + (0x010))
#define SOC_IOC_AO_IOMG_SE_00_ADDR(base) ((base) + (0x700))
#define SOC_IOC_AO_IOMG_005_ADDR(base) ((base) + (0x014))
#define SOC_IOC_AO_IOMG_006_ADDR(base) ((base) + (0x018))
#define SOC_IOC_AO_IOMG_007_ADDR(base) ((base) + (0x01C))
#define SOC_IOC_AO_IOMG_008_ADDR(base) ((base) + (0x020))
#define SOC_IOC_AO_IOMG_009_ADDR(base) ((base) + (0x024))
#define SOC_IOC_AO_IOMG_010_ADDR(base) ((base) + (0x028))
#define SOC_IOC_AO_IOMG_011_ADDR(base) ((base) + (0x02C))
#define SOC_IOC_AO_IOMG_012_ADDR(base) ((base) + (0x030))
#define SOC_IOC_AO_IOMG_013_ADDR(base) ((base) + (0x034))
#define SOC_IOC_AO_IOMG_014_ADDR(base) ((base) + (0x038))
#define SOC_IOC_AO_IOMG_015_ADDR(base) ((base) + (0x03C))
#define SOC_IOC_AO_IOMG_016_ADDR(base) ((base) + (0x040))
#define SOC_IOC_AO_IOMG_017_ADDR(base) ((base) + (0x044))
#define SOC_IOC_AO_IOMG_018_ADDR(base) ((base) + (0x048))
#define SOC_IOC_AO_IOMG_SE_01_ADDR(base) ((base) + (0x704))
#define SOC_IOC_AO_IOMG_SE_02_ADDR(base) ((base) + (0x708))
#define SOC_IOC_AO_IOMG_SE_03_ADDR(base) ((base) + (0x70C))
#define SOC_IOC_AO_IOMG_SE_04_ADDR(base) ((base) + (0x710))
#define SOC_IOC_AO_IOMG_019_ADDR(base) ((base) + (0x04C))
#define SOC_IOC_AO_IOMG_020_ADDR(base) ((base) + (0x050))
#define SOC_IOC_AO_IOMG_021_ADDR(base) ((base) + (0x054))
#define SOC_IOC_AO_IOMG_022_ADDR(base) ((base) + (0x058))
#define SOC_IOC_AO_IOMG_023_ADDR(base) ((base) + (0x05C))
#define SOC_IOC_AO_IOMG_024_ADDR(base) ((base) + (0x060))
#define SOC_IOC_AO_IOMG_SE_05_ADDR(base) ((base) + (0x714))
#define SOC_IOC_AO_IOMG_SE_06_ADDR(base) ((base) + (0x718))
#define SOC_IOC_AO_IOMG_SE_07_ADDR(base) ((base) + (0x71C))
#define SOC_IOC_AO_IOMG_SE_08_ADDR(base) ((base) + (0x720))
#define SOC_IOC_AO_IOMG_SE_09_ADDR(base) ((base) + (0x724))
#define SOC_IOC_AO_IOMG_SE_10_ADDR(base) ((base) + (0x728))
#define SOC_IOC_AO_IOMG_SE_11_ADDR(base) ((base) + (0x72C))
#define SOC_IOC_AO_IOMG_SE_12_ADDR(base) ((base) + (0x730))
#define SOC_IOC_AO_IOMG_SE_13_ADDR(base) ((base) + (0x734))
#define SOC_IOC_AO_IOMG_SE_14_ADDR(base) ((base) + (0x738))
#define SOC_IOC_AO_IOMG_SE_15_ADDR(base) ((base) + (0x73C))
#define SOC_IOC_AO_IOMG_SE_16_ADDR(base) ((base) + (0x740))
#define SOC_IOC_AO_IOMG_SE_17_ADDR(base) ((base) + (0x744))
#define SOC_IOC_AO_IOMG_SE_18_ADDR(base) ((base) + (0x748))
#define SOC_IOC_AO_IOMG_SE_19_ADDR(base) ((base) + (0x74C))
#define SOC_IOC_AO_IOMG_SE_20_ADDR(base) ((base) + (0x750))
#define SOC_IOC_AO_IOMG_SE_21_ADDR(base) ((base) + (0x754))
#define SOC_IOC_AO_IOMG_SE_22_ADDR(base) ((base) + (0x758))
#define SOC_IOC_AO_IOMG_SE_23_ADDR(base) ((base) + (0x75C))
#define SOC_IOC_AO_IOMG_SE_24_ADDR(base) ((base) + (0x760))
#define SOC_IOC_AO_IOMG_SE_25_ADDR(base) ((base) + (0x764))
#define SOC_IOC_AO_IOMG_SE_26_ADDR(base) ((base) + (0x768))
#define SOC_IOC_AO_IOMG_SE_27_ADDR(base) ((base) + (0x76C))
#define SOC_IOC_AO_IOMG_SE_28_ADDR(base) ((base) + (0x770))
#define SOC_IOC_AO_IOMG_SE_29_ADDR(base) ((base) + (0x774))
#define SOC_IOC_AO_IOMG_SE_30_ADDR(base) ((base) + (0x778))
#define SOC_IOC_AO_IOMG_SE_31_ADDR(base) ((base) + (0x77C))
#define SOC_IOC_AO_IOMG_SE_32_ADDR(base) ((base) + (0x780))
#define SOC_IOC_AO_IOMG_SE_33_ADDR(base) ((base) + (0x784))
#define SOC_IOC_AO_IOMG_SE_34_ADDR(base) ((base) + (0x788))
#define SOC_IOC_AO_IOMG_SE_35_ADDR(base) ((base) + (0x78C))
#define SOC_IOC_AO_IOMG_SE_36_ADDR(base) ((base) + (0x790))
#define SOC_IOC_AO_IOMG_SE_37_ADDR(base) ((base) + (0x794))
#define SOC_IOC_AO_IOMG_SE_38_ADDR(base) ((base) + (0x798))
#define SOC_IOC_AO_IOMG_SE_39_ADDR(base) ((base) + (0x79C))
#define SOC_IOC_AO_IOMG_SE_40_ADDR(base) ((base) + (0x7A0))
#define SOC_IOC_AO_IOMG_SE_41_ADDR(base) ((base) + (0x7A4))
#define SOC_IOC_AO_IOMG_SE_42_ADDR(base) ((base) + (0x7A8))
#define SOC_IOC_AO_IOMG_SE_43_ADDR(base) ((base) + (0x7AC))
#define SOC_IOC_AO_IOMG_SE_44_ADDR(base) ((base) + (0x7B0))
#define SOC_IOC_AO_IOMG_SE_45_ADDR(base) ((base) + (0x7B4))
#define SOC_IOC_AO_IOMG_SE_46_ADDR(base) ((base) + (0x7B8))
#define SOC_IOC_AO_IOMG_SE_47_ADDR(base) ((base) + (0x7BC))
#define SOC_IOC_AO_IOMG_SE_48_ADDR(base) ((base) + (0x7C0))
#define SOC_IOC_AO_IOMG_SE_49_ADDR(base) ((base) + (0x7C4))
#define SOC_IOC_AO_IOMG_SE_50_ADDR(base) ((base) + (0x7C8))
#define SOC_IOC_AO_IOMG_SE_51_ADDR(base) ((base) + (0x7CC))
#define SOC_IOC_AO_IOMG_SE_52_ADDR(base) ((base) + (0x7D0))
#define SOC_IOC_AO_IOMG_SE_53_ADDR(base) ((base) + (0x7D4))
#define SOC_IOC_AO_IOMG_SE_54_ADDR(base) ((base) + (0x7D8))
#define SOC_IOC_AO_IOMG_SE_55_ADDR(base) ((base) + (0x7DC))
#define SOC_IOC_AO_IOCG_000_ADDR(base) ((base) + (0x800))
#define SOC_IOC_AO_IOCG_001_ADDR(base) ((base) + (0x804))
#define SOC_IOC_AO_IOCG_002_ADDR(base) ((base) + (0x808))
#define SOC_IOC_AO_IOCG_003_ADDR(base) ((base) + (0x80C))
#define SOC_IOC_AO_IOCG_004_ADDR(base) ((base) + (0x810))
#define SOC_IOC_AO_IOCG_005_ADDR(base) ((base) + (0x814))
#define SOC_IOC_AO_IOCG_006_ADDR(base) ((base) + (0x818))
#define SOC_IOC_AO_IOCG_007_ADDR(base) ((base) + (0x81C))
#define SOC_IOC_AO_IOCG_008_ADDR(base) ((base) + (0x820))
#define SOC_IOC_AO_IOCG_009_ADDR(base) ((base) + (0x824))
#define SOC_IOC_AO_IOCG_010_ADDR(base) ((base) + (0x828))
#define SOC_IOC_AO_IOCG_011_ADDR(base) ((base) + (0x82C))
#define SOC_IOC_AO_IOCG_012_ADDR(base) ((base) + (0x830))
#define SOC_IOC_AO_IOCG_SE_00_ADDR(base) ((base) + (0xF00))
#define SOC_IOC_AO_IOCG_013_ADDR(base) ((base) + (0x834))
#define SOC_IOC_AO_IOCG_014_ADDR(base) ((base) + (0x838))
#define SOC_IOC_AO_IOCG_015_ADDR(base) ((base) + (0x83C))
#define SOC_IOC_AO_IOCG_016_ADDR(base) ((base) + (0x840))
#define SOC_IOC_AO_IOCG_017_ADDR(base) ((base) + (0x844))
#define SOC_IOC_AO_IOCG_018_ADDR(base) ((base) + (0x848))
#define SOC_IOC_AO_IOCG_019_ADDR(base) ((base) + (0x84C))
#define SOC_IOC_AO_IOCG_020_ADDR(base) ((base) + (0x850))
#define SOC_IOC_AO_IOCG_021_ADDR(base) ((base) + (0x854))
#define SOC_IOC_AO_IOCG_022_ADDR(base) ((base) + (0x858))
#define SOC_IOC_AO_IOCG_023_ADDR(base) ((base) + (0x85C))
#define SOC_IOC_AO_IOCG_024_ADDR(base) ((base) + (0x860))
#define SOC_IOC_AO_IOCG_025_ADDR(base) ((base) + (0x864))
#define SOC_IOC_AO_IOCG_026_ADDR(base) ((base) + (0x868))
#define SOC_IOC_AO_IOCG_027_ADDR(base) ((base) + (0x86C))
#define SOC_IOC_AO_IOCG_028_ADDR(base) ((base) + (0x870))
#define SOC_IOC_AO_IOCG_029_ADDR(base) ((base) + (0x874))
#define SOC_IOC_AO_IOCG_SE_01_ADDR(base) ((base) + (0xF04))
#define SOC_IOC_AO_IOCG_SE_02_ADDR(base) ((base) + (0xF08))
#define SOC_IOC_AO_IOCG_SE_03_ADDR(base) ((base) + (0xF0C))
#define SOC_IOC_AO_IOCG_SE_04_ADDR(base) ((base) + (0xF10))
#define SOC_IOC_AO_IOCG_030_ADDR(base) ((base) + (0x878))
#define SOC_IOC_AO_IOCG_031_ADDR(base) ((base) + (0x87C))
#define SOC_IOC_AO_IOCG_032_ADDR(base) ((base) + (0x880))
#define SOC_IOC_AO_IOCG_033_ADDR(base) ((base) + (0x884))
#define SOC_IOC_AO_IOCG_034_ADDR(base) ((base) + (0x888))
#define SOC_IOC_AO_IOCG_035_ADDR(base) ((base) + (0x88C))
#define SOC_IOC_AO_IOCG_036_ADDR(base) ((base) + (0x890))
#define SOC_IOC_AO_IOCG_037_ADDR(base) ((base) + (0x894))
#define SOC_IOC_AO_IOCG_038_ADDR(base) ((base) + (0x898))
#define SOC_IOC_AO_IOCG_SE_05_ADDR(base) ((base) + (0xF14))
#define SOC_IOC_AO_IOCG_SE_06_ADDR(base) ((base) + (0xF18))
#define SOC_IOC_AO_IOCG_SE_07_ADDR(base) ((base) + (0xF1C))
#define SOC_IOC_AO_IOCG_SE_08_ADDR(base) ((base) + (0xF20))
#define SOC_IOC_AO_IOCG_SE_09_ADDR(base) ((base) + (0xF24))
#define SOC_IOC_AO_IOCG_SE_10_ADDR(base) ((base) + (0xF28))
#define SOC_IOC_AO_IOCG_SE_11_ADDR(base) ((base) + (0xF2C))
#define SOC_IOC_AO_IOCG_SE_12_ADDR(base) ((base) + (0xF30))
#define SOC_IOC_AO_IOCG_SE_13_ADDR(base) ((base) + (0xF34))
#define SOC_IOC_AO_IOCG_SE_14_ADDR(base) ((base) + (0xF38))
#define SOC_IOC_AO_IOCG_SE_15_ADDR(base) ((base) + (0xF3C))
#define SOC_IOC_AO_IOCG_SE_16_ADDR(base) ((base) + (0xF40))
#define SOC_IOC_AO_IOCG_SE_17_ADDR(base) ((base) + (0xF44))
#define SOC_IOC_AO_IOCG_SE_18_ADDR(base) ((base) + (0xF48))
#define SOC_IOC_AO_IOCG_SE_19_ADDR(base) ((base) + (0xF4C))
#define SOC_IOC_AO_IOCG_SE_20_ADDR(base) ((base) + (0xF50))
#define SOC_IOC_AO_IOCG_SE_21_ADDR(base) ((base) + (0xF54))
#define SOC_IOC_AO_IOCG_SE_22_ADDR(base) ((base) + (0xF58))
#define SOC_IOC_AO_IOCG_SE_23_ADDR(base) ((base) + (0xF5C))
#define SOC_IOC_AO_IOCG_SE_24_ADDR(base) ((base) + (0xF60))
#define SOC_IOC_AO_IOCG_SE_25_ADDR(base) ((base) + (0xF64))
#define SOC_IOC_AO_IOCG_SE_26_ADDR(base) ((base) + (0xF68))
#define SOC_IOC_AO_IOCG_SE_27_ADDR(base) ((base) + (0xF6C))
#define SOC_IOC_AO_IOCG_SE_28_ADDR(base) ((base) + (0xF70))
#define SOC_IOC_AO_IOCG_SE_29_ADDR(base) ((base) + (0xF74))
#define SOC_IOC_AO_IOCG_SE_30_ADDR(base) ((base) + (0xF78))
#define SOC_IOC_AO_IOCG_SE_31_ADDR(base) ((base) + (0xF7C))
#define SOC_IOC_AO_IOCG_SE_32_ADDR(base) ((base) + (0xF80))
#define SOC_IOC_AO_IOCG_SE_33_ADDR(base) ((base) + (0xF84))
#define SOC_IOC_AO_IOCG_SE_34_ADDR(base) ((base) + (0xF88))
#define SOC_IOC_AO_IOCG_SE_35_ADDR(base) ((base) + (0xF8C))
#define SOC_IOC_AO_IOCG_SE_36_ADDR(base) ((base) + (0xF90))
#define SOC_IOC_AO_IOCG_SE_37_ADDR(base) ((base) + (0xF94))
#define SOC_IOC_AO_IOCG_SE_38_ADDR(base) ((base) + (0xF98))
#define SOC_IOC_AO_IOCG_SE_39_ADDR(base) ((base) + (0xF9C))
#define SOC_IOC_AO_IOCG_SE_40_ADDR(base) ((base) + (0xFA0))
#define SOC_IOC_AO_IOCG_SE_41_ADDR(base) ((base) + (0xFA4))
#define SOC_IOC_AO_IOCG_SE_42_ADDR(base) ((base) + (0xFA8))
#define SOC_IOC_AO_IOCG_SE_43_ADDR(base) ((base) + (0xFAC))
#define SOC_IOC_AO_IOCG_SE_44_ADDR(base) ((base) + (0xFB0))
#define SOC_IOC_AO_IOCG_SE_45_ADDR(base) ((base) + (0xFB4))
#define SOC_IOC_AO_IOCG_SE_46_ADDR(base) ((base) + (0xFB8))
#define SOC_IOC_AO_IOCG_SE_47_ADDR(base) ((base) + (0xFBC))
#define SOC_IOC_AO_IOCG_SE_48_ADDR(base) ((base) + (0xFC0))
#define SOC_IOC_AO_IOCG_SE_49_ADDR(base) ((base) + (0xFC4))
#define SOC_IOC_AO_IOCG_SE_50_ADDR(base) ((base) + (0xFC8))
#define SOC_IOC_AO_IOCG_SE_51_ADDR(base) ((base) + (0xFCC))
#define SOC_IOC_AO_IOCG_SE_52_ADDR(base) ((base) + (0xFD0))
#define SOC_IOC_AO_IOCG_SE_53_ADDR(base) ((base) + (0xFD4))
#define SOC_IOC_AO_IOCG_SE_54_ADDR(base) ((base) + (0xFD8))
#define SOC_IOC_AO_IOCG_SE_55_ADDR(base) ((base) + (0xFDC))
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
} SOC_IOC_AO_IOMG_000_UNION;
#endif
#define SOC_IOC_AO_IOMG_000_iomg_000_START (0)
#define SOC_IOC_AO_IOMG_000_iomg_000_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_001 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_001_UNION;
#endif
#define SOC_IOC_AO_IOMG_001_iomg_001_START (0)
#define SOC_IOC_AO_IOMG_001_iomg_001_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_002 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_002_UNION;
#endif
#define SOC_IOC_AO_IOMG_002_iomg_002_START (0)
#define SOC_IOC_AO_IOMG_002_iomg_002_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_003 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_003_UNION;
#endif
#define SOC_IOC_AO_IOMG_003_iomg_003_START (0)
#define SOC_IOC_AO_IOMG_003_iomg_003_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_004 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_004_UNION;
#endif
#define SOC_IOC_AO_IOMG_004_iomg_004_START (0)
#define SOC_IOC_AO_IOMG_004_iomg_004_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_00 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_AO_IOMG_SE_00_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_00_iomg_se_00_START (0)
#define SOC_IOC_AO_IOMG_SE_00_iomg_se_00_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_005 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_005_UNION;
#endif
#define SOC_IOC_AO_IOMG_005_iomg_005_START (0)
#define SOC_IOC_AO_IOMG_005_iomg_005_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_006 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_006_UNION;
#endif
#define SOC_IOC_AO_IOMG_006_iomg_006_START (0)
#define SOC_IOC_AO_IOMG_006_iomg_006_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_007 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_007_UNION;
#endif
#define SOC_IOC_AO_IOMG_007_iomg_007_START (0)
#define SOC_IOC_AO_IOMG_007_iomg_007_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_008 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_008_UNION;
#endif
#define SOC_IOC_AO_IOMG_008_iomg_008_START (0)
#define SOC_IOC_AO_IOMG_008_iomg_008_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_009 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_AO_IOMG_009_UNION;
#endif
#define SOC_IOC_AO_IOMG_009_iomg_009_START (0)
#define SOC_IOC_AO_IOMG_009_iomg_009_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_010 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_AO_IOMG_010_UNION;
#endif
#define SOC_IOC_AO_IOMG_010_iomg_010_START (0)
#define SOC_IOC_AO_IOMG_010_iomg_010_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_011 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_AO_IOMG_011_UNION;
#endif
#define SOC_IOC_AO_IOMG_011_iomg_011_START (0)
#define SOC_IOC_AO_IOMG_011_iomg_011_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_012 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_AO_IOMG_012_UNION;
#endif
#define SOC_IOC_AO_IOMG_012_iomg_012_START (0)
#define SOC_IOC_AO_IOMG_012_iomg_012_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_013 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_013_UNION;
#endif
#define SOC_IOC_AO_IOMG_013_iomg_013_START (0)
#define SOC_IOC_AO_IOMG_013_iomg_013_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_014 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_014_UNION;
#endif
#define SOC_IOC_AO_IOMG_014_iomg_014_START (0)
#define SOC_IOC_AO_IOMG_014_iomg_014_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_015 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_015_UNION;
#endif
#define SOC_IOC_AO_IOMG_015_iomg_015_START (0)
#define SOC_IOC_AO_IOMG_015_iomg_015_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_016 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_016_UNION;
#endif
#define SOC_IOC_AO_IOMG_016_iomg_016_START (0)
#define SOC_IOC_AO_IOMG_016_iomg_016_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_017 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_017_UNION;
#endif
#define SOC_IOC_AO_IOMG_017_iomg_017_START (0)
#define SOC_IOC_AO_IOMG_017_iomg_017_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_018 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_018_UNION;
#endif
#define SOC_IOC_AO_IOMG_018_iomg_018_START (0)
#define SOC_IOC_AO_IOMG_018_iomg_018_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_01 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_01_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_01_iomg_se_01_START (0)
#define SOC_IOC_AO_IOMG_SE_01_iomg_se_01_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_02 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_02_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_02_iomg_se_02_START (0)
#define SOC_IOC_AO_IOMG_SE_02_iomg_se_02_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_03 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_03_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_03_iomg_se_03_START (0)
#define SOC_IOC_AO_IOMG_SE_03_iomg_se_03_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_04 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_04_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_04_iomg_se_04_START (0)
#define SOC_IOC_AO_IOMG_SE_04_iomg_se_04_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_019 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_019_UNION;
#endif
#define SOC_IOC_AO_IOMG_019_iomg_019_START (0)
#define SOC_IOC_AO_IOMG_019_iomg_019_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_020 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_020_UNION;
#endif
#define SOC_IOC_AO_IOMG_020_iomg_020_START (0)
#define SOC_IOC_AO_IOMG_020_iomg_020_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_021 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_021_UNION;
#endif
#define SOC_IOC_AO_IOMG_021_iomg_021_START (0)
#define SOC_IOC_AO_IOMG_021_iomg_021_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_022 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_022_UNION;
#endif
#define SOC_IOC_AO_IOMG_022_iomg_022_START (0)
#define SOC_IOC_AO_IOMG_022_iomg_022_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_023 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_023_UNION;
#endif
#define SOC_IOC_AO_IOMG_023_iomg_023_START (0)
#define SOC_IOC_AO_IOMG_023_iomg_023_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_024 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_024_UNION;
#endif
#define SOC_IOC_AO_IOMG_024_iomg_024_START (0)
#define SOC_IOC_AO_IOMG_024_iomg_024_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_05 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_05_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_05_iomg_se_05_START (0)
#define SOC_IOC_AO_IOMG_SE_05_iomg_se_05_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_06 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_06_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_06_iomg_se_06_START (0)
#define SOC_IOC_AO_IOMG_SE_06_iomg_se_06_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_07 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_07_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_07_iomg_se_07_START (0)
#define SOC_IOC_AO_IOMG_SE_07_iomg_se_07_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_08 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_08_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_08_iomg_se_08_START (0)
#define SOC_IOC_AO_IOMG_SE_08_iomg_se_08_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_09 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_09_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_09_iomg_se_09_START (0)
#define SOC_IOC_AO_IOMG_SE_09_iomg_se_09_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_10 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_10_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_10_iomg_se_10_START (0)
#define SOC_IOC_AO_IOMG_SE_10_iomg_se_10_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_11 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_11_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_11_iomg_se_11_START (0)
#define SOC_IOC_AO_IOMG_SE_11_iomg_se_11_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_12 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_12_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_12_iomg_se_12_START (0)
#define SOC_IOC_AO_IOMG_SE_12_iomg_se_12_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_13 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_13_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_13_iomg_se_13_START (0)
#define SOC_IOC_AO_IOMG_SE_13_iomg_se_13_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_14 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_14_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_14_iomg_se_14_START (0)
#define SOC_IOC_AO_IOMG_SE_14_iomg_se_14_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_15 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_15_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_15_iomg_se_15_START (0)
#define SOC_IOC_AO_IOMG_SE_15_iomg_se_15_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_16 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_16_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_16_iomg_se_16_START (0)
#define SOC_IOC_AO_IOMG_SE_16_iomg_se_16_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_17 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_17_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_17_iomg_se_17_START (0)
#define SOC_IOC_AO_IOMG_SE_17_iomg_se_17_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_18 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_18_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_18_iomg_se_18_START (0)
#define SOC_IOC_AO_IOMG_SE_18_iomg_se_18_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_19 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_19_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_19_iomg_se_19_START (0)
#define SOC_IOC_AO_IOMG_SE_19_iomg_se_19_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_20 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_20_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_20_iomg_se_20_START (0)
#define SOC_IOC_AO_IOMG_SE_20_iomg_se_20_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_21 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_21_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_21_iomg_se_21_START (0)
#define SOC_IOC_AO_IOMG_SE_21_iomg_se_21_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_22 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_22_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_22_iomg_se_22_START (0)
#define SOC_IOC_AO_IOMG_SE_22_iomg_se_22_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_23 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_23_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_23_iomg_se_23_START (0)
#define SOC_IOC_AO_IOMG_SE_23_iomg_se_23_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_24 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_24_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_24_iomg_se_24_START (0)
#define SOC_IOC_AO_IOMG_SE_24_iomg_se_24_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_25 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_25_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_25_iomg_se_25_START (0)
#define SOC_IOC_AO_IOMG_SE_25_iomg_se_25_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_26 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_26_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_26_iomg_se_26_START (0)
#define SOC_IOC_AO_IOMG_SE_26_iomg_se_26_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_27 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_27_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_27_iomg_se_27_START (0)
#define SOC_IOC_AO_IOMG_SE_27_iomg_se_27_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_28 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_28_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_28_iomg_se_28_START (0)
#define SOC_IOC_AO_IOMG_SE_28_iomg_se_28_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_29 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_29_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_29_iomg_se_29_START (0)
#define SOC_IOC_AO_IOMG_SE_29_iomg_se_29_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_30 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_30_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_30_iomg_se_30_START (0)
#define SOC_IOC_AO_IOMG_SE_30_iomg_se_30_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_31 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_31_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_31_iomg_se_31_START (0)
#define SOC_IOC_AO_IOMG_SE_31_iomg_se_31_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_32 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_32_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_32_iomg_se_32_START (0)
#define SOC_IOC_AO_IOMG_SE_32_iomg_se_32_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_33 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_33_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_33_iomg_se_33_START (0)
#define SOC_IOC_AO_IOMG_SE_33_iomg_se_33_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_34 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_34_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_34_iomg_se_34_START (0)
#define SOC_IOC_AO_IOMG_SE_34_iomg_se_34_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_35 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_35_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_35_iomg_se_35_START (0)
#define SOC_IOC_AO_IOMG_SE_35_iomg_se_35_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_36 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_36_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_36_iomg_se_36_START (0)
#define SOC_IOC_AO_IOMG_SE_36_iomg_se_36_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_37 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_37_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_37_iomg_se_37_START (0)
#define SOC_IOC_AO_IOMG_SE_37_iomg_se_37_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_38 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_38_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_38_iomg_se_38_START (0)
#define SOC_IOC_AO_IOMG_SE_38_iomg_se_38_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_39 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_39_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_39_iomg_se_39_START (0)
#define SOC_IOC_AO_IOMG_SE_39_iomg_se_39_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_40 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_40_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_40_iomg_se_40_START (0)
#define SOC_IOC_AO_IOMG_SE_40_iomg_se_40_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_41 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_41_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_41_iomg_se_41_START (0)
#define SOC_IOC_AO_IOMG_SE_41_iomg_se_41_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_42 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_42_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_42_iomg_se_42_START (0)
#define SOC_IOC_AO_IOMG_SE_42_iomg_se_42_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_43 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_43_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_43_iomg_se_43_START (0)
#define SOC_IOC_AO_IOMG_SE_43_iomg_se_43_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_44 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_44_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_44_iomg_se_44_START (0)
#define SOC_IOC_AO_IOMG_SE_44_iomg_se_44_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_45 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_45_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_45_iomg_se_45_START (0)
#define SOC_IOC_AO_IOMG_SE_45_iomg_se_45_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_46 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_46_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_46_iomg_se_46_START (0)
#define SOC_IOC_AO_IOMG_SE_46_iomg_se_46_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_47 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_47_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_47_iomg_se_47_START (0)
#define SOC_IOC_AO_IOMG_SE_47_iomg_se_47_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_48 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_48_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_48_iomg_se_48_START (0)
#define SOC_IOC_AO_IOMG_SE_48_iomg_se_48_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_49 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_49_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_49_iomg_se_49_START (0)
#define SOC_IOC_AO_IOMG_SE_49_iomg_se_49_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_50 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_50_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_50_iomg_se_50_START (0)
#define SOC_IOC_AO_IOMG_SE_50_iomg_se_50_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_51 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_51_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_51_iomg_se_51_START (0)
#define SOC_IOC_AO_IOMG_SE_51_iomg_se_51_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_52 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_IOC_AO_IOMG_SE_52_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_52_iomg_se_52_START (0)
#define SOC_IOC_AO_IOMG_SE_52_iomg_se_52_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_53 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_SE_53_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_53_iomg_se_53_START (0)
#define SOC_IOC_AO_IOMG_SE_53_iomg_se_53_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_54 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_SE_54_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_54_iomg_se_54_START (0)
#define SOC_IOC_AO_IOMG_SE_54_iomg_se_54_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomg_se_55 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_AO_IOMG_SE_55_UNION;
#endif
#define SOC_IOC_AO_IOMG_SE_55_iomg_se_55_START (0)
#define SOC_IOC_AO_IOMG_SE_55_iomg_se_55_END (0)
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
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_000_UNION;
#endif
#define SOC_IOC_AO_IOCG_000_iocg_000_pu_START (0)
#define SOC_IOC_AO_IOCG_000_iocg_000_pu_END (0)
#define SOC_IOC_AO_IOCG_000_iocg_000_pd_START (1)
#define SOC_IOC_AO_IOCG_000_iocg_000_pd_END (1)
#define SOC_IOC_AO_IOCG_000_iocg_000_st_START (3)
#define SOC_IOC_AO_IOCG_000_iocg_000_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int iocg_001_ds0 : 1;
        unsigned int iocg_001_ds1 : 1;
        unsigned int iocg_001_ds2 : 1;
        unsigned int iocg_001_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_001_UNION;
#endif
#define SOC_IOC_AO_IOCG_001_iocg_001_ds0_START (4)
#define SOC_IOC_AO_IOCG_001_iocg_001_ds0_END (4)
#define SOC_IOC_AO_IOCG_001_iocg_001_ds1_START (5)
#define SOC_IOC_AO_IOCG_001_iocg_001_ds1_END (5)
#define SOC_IOC_AO_IOCG_001_iocg_001_ds2_START (6)
#define SOC_IOC_AO_IOCG_001_iocg_001_ds2_END (6)
#define SOC_IOC_AO_IOCG_001_iocg_001_sl_START (7)
#define SOC_IOC_AO_IOCG_001_iocg_001_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int iocg_002_ds0 : 1;
        unsigned int iocg_002_ds1 : 1;
        unsigned int iocg_002_ds2 : 1;
        unsigned int iocg_002_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_002_UNION;
#endif
#define SOC_IOC_AO_IOCG_002_iocg_002_ds0_START (4)
#define SOC_IOC_AO_IOCG_002_iocg_002_ds0_END (4)
#define SOC_IOC_AO_IOCG_002_iocg_002_ds1_START (5)
#define SOC_IOC_AO_IOCG_002_iocg_002_ds1_END (5)
#define SOC_IOC_AO_IOCG_002_iocg_002_ds2_START (6)
#define SOC_IOC_AO_IOCG_002_iocg_002_ds2_END (6)
#define SOC_IOC_AO_IOCG_002_iocg_002_sl_START (7)
#define SOC_IOC_AO_IOCG_002_iocg_002_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int iocg_003_ds0 : 1;
        unsigned int iocg_003_ds1 : 1;
        unsigned int iocg_003_ds2 : 1;
        unsigned int iocg_003_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_003_UNION;
#endif
#define SOC_IOC_AO_IOCG_003_iocg_003_ds0_START (4)
#define SOC_IOC_AO_IOCG_003_iocg_003_ds0_END (4)
#define SOC_IOC_AO_IOCG_003_iocg_003_ds1_START (5)
#define SOC_IOC_AO_IOCG_003_iocg_003_ds1_END (5)
#define SOC_IOC_AO_IOCG_003_iocg_003_ds2_START (6)
#define SOC_IOC_AO_IOCG_003_iocg_003_ds2_END (6)
#define SOC_IOC_AO_IOCG_003_iocg_003_sl_START (7)
#define SOC_IOC_AO_IOCG_003_iocg_003_sl_END (7)
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
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_004_UNION;
#endif
#define SOC_IOC_AO_IOCG_004_iocg_004_pu_START (0)
#define SOC_IOC_AO_IOCG_004_iocg_004_pu_END (0)
#define SOC_IOC_AO_IOCG_004_iocg_004_pd_START (1)
#define SOC_IOC_AO_IOCG_004_iocg_004_pd_END (1)
#define SOC_IOC_AO_IOCG_004_iocg_004_st_START (3)
#define SOC_IOC_AO_IOCG_004_iocg_004_st_END (3)
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
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_005_UNION;
#endif
#define SOC_IOC_AO_IOCG_005_iocg_005_pu_START (0)
#define SOC_IOC_AO_IOCG_005_iocg_005_pu_END (0)
#define SOC_IOC_AO_IOCG_005_iocg_005_pd_START (1)
#define SOC_IOC_AO_IOCG_005_iocg_005_pd_END (1)
#define SOC_IOC_AO_IOCG_005_iocg_005_st_START (3)
#define SOC_IOC_AO_IOCG_005_iocg_005_st_END (3)
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
} SOC_IOC_AO_IOCG_006_UNION;
#endif
#define SOC_IOC_AO_IOCG_006_iocg_006_pu_START (0)
#define SOC_IOC_AO_IOCG_006_iocg_006_pu_END (0)
#define SOC_IOC_AO_IOCG_006_iocg_006_pd_START (1)
#define SOC_IOC_AO_IOCG_006_iocg_006_pd_END (1)
#define SOC_IOC_AO_IOCG_006_iocg_006_st_START (3)
#define SOC_IOC_AO_IOCG_006_iocg_006_st_END (3)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds0_START (4)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds0_END (4)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds1_START (5)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds1_END (5)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds2_START (6)
#define SOC_IOC_AO_IOCG_006_iocg_006_ds2_END (6)
#define SOC_IOC_AO_IOCG_006_iocg_006_sl_START (7)
#define SOC_IOC_AO_IOCG_006_iocg_006_sl_END (7)
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
} SOC_IOC_AO_IOCG_007_UNION;
#endif
#define SOC_IOC_AO_IOCG_007_iocg_007_pu_START (0)
#define SOC_IOC_AO_IOCG_007_iocg_007_pu_END (0)
#define SOC_IOC_AO_IOCG_007_iocg_007_pd_START (1)
#define SOC_IOC_AO_IOCG_007_iocg_007_pd_END (1)
#define SOC_IOC_AO_IOCG_007_iocg_007_st_START (3)
#define SOC_IOC_AO_IOCG_007_iocg_007_st_END (3)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds0_START (4)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds0_END (4)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds1_START (5)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds1_END (5)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds2_START (6)
#define SOC_IOC_AO_IOCG_007_iocg_007_ds2_END (6)
#define SOC_IOC_AO_IOCG_007_iocg_007_sl_START (7)
#define SOC_IOC_AO_IOCG_007_iocg_007_sl_END (7)
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
} SOC_IOC_AO_IOCG_008_UNION;
#endif
#define SOC_IOC_AO_IOCG_008_iocg_008_pu_START (0)
#define SOC_IOC_AO_IOCG_008_iocg_008_pu_END (0)
#define SOC_IOC_AO_IOCG_008_iocg_008_pd_START (1)
#define SOC_IOC_AO_IOCG_008_iocg_008_pd_END (1)
#define SOC_IOC_AO_IOCG_008_iocg_008_st_START (3)
#define SOC_IOC_AO_IOCG_008_iocg_008_st_END (3)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds0_START (4)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds0_END (4)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds1_START (5)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds1_END (5)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds2_START (6)
#define SOC_IOC_AO_IOCG_008_iocg_008_ds2_END (6)
#define SOC_IOC_AO_IOCG_008_iocg_008_sl_START (7)
#define SOC_IOC_AO_IOCG_008_iocg_008_sl_END (7)
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
} SOC_IOC_AO_IOCG_009_UNION;
#endif
#define SOC_IOC_AO_IOCG_009_iocg_009_pu_START (0)
#define SOC_IOC_AO_IOCG_009_iocg_009_pu_END (0)
#define SOC_IOC_AO_IOCG_009_iocg_009_pd_START (1)
#define SOC_IOC_AO_IOCG_009_iocg_009_pd_END (1)
#define SOC_IOC_AO_IOCG_009_iocg_009_st_START (3)
#define SOC_IOC_AO_IOCG_009_iocg_009_st_END (3)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds0_START (4)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds0_END (4)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds1_START (5)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds1_END (5)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds2_START (6)
#define SOC_IOC_AO_IOCG_009_iocg_009_ds2_END (6)
#define SOC_IOC_AO_IOCG_009_iocg_009_sl_START (7)
#define SOC_IOC_AO_IOCG_009_iocg_009_sl_END (7)
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
} SOC_IOC_AO_IOCG_010_UNION;
#endif
#define SOC_IOC_AO_IOCG_010_iocg_010_pu_START (0)
#define SOC_IOC_AO_IOCG_010_iocg_010_pu_END (0)
#define SOC_IOC_AO_IOCG_010_iocg_010_pd_START (1)
#define SOC_IOC_AO_IOCG_010_iocg_010_pd_END (1)
#define SOC_IOC_AO_IOCG_010_iocg_010_st_START (3)
#define SOC_IOC_AO_IOCG_010_iocg_010_st_END (3)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds0_START (4)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds0_END (4)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds1_START (5)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds1_END (5)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds2_START (6)
#define SOC_IOC_AO_IOCG_010_iocg_010_ds2_END (6)
#define SOC_IOC_AO_IOCG_010_iocg_010_sl_START (7)
#define SOC_IOC_AO_IOCG_010_iocg_010_sl_END (7)
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
} SOC_IOC_AO_IOCG_011_UNION;
#endif
#define SOC_IOC_AO_IOCG_011_iocg_011_pu_START (0)
#define SOC_IOC_AO_IOCG_011_iocg_011_pu_END (0)
#define SOC_IOC_AO_IOCG_011_iocg_011_pd_START (1)
#define SOC_IOC_AO_IOCG_011_iocg_011_pd_END (1)
#define SOC_IOC_AO_IOCG_011_iocg_011_st_START (3)
#define SOC_IOC_AO_IOCG_011_iocg_011_st_END (3)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds0_START (4)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds0_END (4)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds1_START (5)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds1_END (5)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds2_START (6)
#define SOC_IOC_AO_IOCG_011_iocg_011_ds2_END (6)
#define SOC_IOC_AO_IOCG_011_iocg_011_sl_START (7)
#define SOC_IOC_AO_IOCG_011_iocg_011_sl_END (7)
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
} SOC_IOC_AO_IOCG_012_UNION;
#endif
#define SOC_IOC_AO_IOCG_012_iocg_012_pu_START (0)
#define SOC_IOC_AO_IOCG_012_iocg_012_pu_END (0)
#define SOC_IOC_AO_IOCG_012_iocg_012_pd_START (1)
#define SOC_IOC_AO_IOCG_012_iocg_012_pd_END (1)
#define SOC_IOC_AO_IOCG_012_iocg_012_st_START (3)
#define SOC_IOC_AO_IOCG_012_iocg_012_st_END (3)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds0_START (4)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds0_END (4)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds1_START (5)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds1_END (5)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds2_START (6)
#define SOC_IOC_AO_IOCG_012_iocg_012_ds2_END (6)
#define SOC_IOC_AO_IOCG_012_iocg_012_sl_START (7)
#define SOC_IOC_AO_IOCG_012_iocg_012_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_00_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_st_START (3)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_st_END (3)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_00_iocg_se_00_sl_END (7)
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
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_013_UNION;
#endif
#define SOC_IOC_AO_IOCG_013_iocg_013_pu_START (0)
#define SOC_IOC_AO_IOCG_013_iocg_013_pu_END (0)
#define SOC_IOC_AO_IOCG_013_iocg_013_pd_START (1)
#define SOC_IOC_AO_IOCG_013_iocg_013_pd_END (1)
#define SOC_IOC_AO_IOCG_013_iocg_013_st_START (3)
#define SOC_IOC_AO_IOCG_013_iocg_013_st_END (3)
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
        unsigned int reserved_1 : 28;
    } reg;
} SOC_IOC_AO_IOCG_014_UNION;
#endif
#define SOC_IOC_AO_IOCG_014_iocg_014_pu_START (0)
#define SOC_IOC_AO_IOCG_014_iocg_014_pu_END (0)
#define SOC_IOC_AO_IOCG_014_iocg_014_pd_START (1)
#define SOC_IOC_AO_IOCG_014_iocg_014_pd_END (1)
#define SOC_IOC_AO_IOCG_014_iocg_014_st_START (3)
#define SOC_IOC_AO_IOCG_014_iocg_014_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int iocg_015_ds0 : 1;
        unsigned int iocg_015_ds1 : 1;
        unsigned int iocg_015_ds2 : 1;
        unsigned int iocg_015_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_015_UNION;
#endif
#define SOC_IOC_AO_IOCG_015_iocg_015_ds0_START (4)
#define SOC_IOC_AO_IOCG_015_iocg_015_ds0_END (4)
#define SOC_IOC_AO_IOCG_015_iocg_015_ds1_START (5)
#define SOC_IOC_AO_IOCG_015_iocg_015_ds1_END (5)
#define SOC_IOC_AO_IOCG_015_iocg_015_ds2_START (6)
#define SOC_IOC_AO_IOCG_015_iocg_015_ds2_END (6)
#define SOC_IOC_AO_IOCG_015_iocg_015_sl_START (7)
#define SOC_IOC_AO_IOCG_015_iocg_015_sl_END (7)
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
} SOC_IOC_AO_IOCG_016_UNION;
#endif
#define SOC_IOC_AO_IOCG_016_iocg_016_pu_START (0)
#define SOC_IOC_AO_IOCG_016_iocg_016_pu_END (0)
#define SOC_IOC_AO_IOCG_016_iocg_016_pd_START (1)
#define SOC_IOC_AO_IOCG_016_iocg_016_pd_END (1)
#define SOC_IOC_AO_IOCG_016_iocg_016_st_START (3)
#define SOC_IOC_AO_IOCG_016_iocg_016_st_END (3)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds0_START (4)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds0_END (4)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds1_START (5)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds1_END (5)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds2_START (6)
#define SOC_IOC_AO_IOCG_016_iocg_016_ds2_END (6)
#define SOC_IOC_AO_IOCG_016_iocg_016_sl_START (7)
#define SOC_IOC_AO_IOCG_016_iocg_016_sl_END (7)
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
} SOC_IOC_AO_IOCG_017_UNION;
#endif
#define SOC_IOC_AO_IOCG_017_iocg_017_pu_START (0)
#define SOC_IOC_AO_IOCG_017_iocg_017_pu_END (0)
#define SOC_IOC_AO_IOCG_017_iocg_017_pd_START (1)
#define SOC_IOC_AO_IOCG_017_iocg_017_pd_END (1)
#define SOC_IOC_AO_IOCG_017_iocg_017_st_START (3)
#define SOC_IOC_AO_IOCG_017_iocg_017_st_END (3)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds0_START (4)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds0_END (4)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds1_START (5)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds1_END (5)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds2_START (6)
#define SOC_IOC_AO_IOCG_017_iocg_017_ds2_END (6)
#define SOC_IOC_AO_IOCG_017_iocg_017_sl_START (7)
#define SOC_IOC_AO_IOCG_017_iocg_017_sl_END (7)
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
} SOC_IOC_AO_IOCG_018_UNION;
#endif
#define SOC_IOC_AO_IOCG_018_iocg_018_pu_START (0)
#define SOC_IOC_AO_IOCG_018_iocg_018_pu_END (0)
#define SOC_IOC_AO_IOCG_018_iocg_018_pd_START (1)
#define SOC_IOC_AO_IOCG_018_iocg_018_pd_END (1)
#define SOC_IOC_AO_IOCG_018_iocg_018_st_START (3)
#define SOC_IOC_AO_IOCG_018_iocg_018_st_END (3)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds0_START (4)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds0_END (4)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds1_START (5)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds1_END (5)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds2_START (6)
#define SOC_IOC_AO_IOCG_018_iocg_018_ds2_END (6)
#define SOC_IOC_AO_IOCG_018_iocg_018_sl_START (7)
#define SOC_IOC_AO_IOCG_018_iocg_018_sl_END (7)
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
} SOC_IOC_AO_IOCG_019_UNION;
#endif
#define SOC_IOC_AO_IOCG_019_iocg_019_pu_START (0)
#define SOC_IOC_AO_IOCG_019_iocg_019_pu_END (0)
#define SOC_IOC_AO_IOCG_019_iocg_019_pd_START (1)
#define SOC_IOC_AO_IOCG_019_iocg_019_pd_END (1)
#define SOC_IOC_AO_IOCG_019_iocg_019_st_START (3)
#define SOC_IOC_AO_IOCG_019_iocg_019_st_END (3)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds0_START (4)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds0_END (4)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds1_START (5)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds1_END (5)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds2_START (6)
#define SOC_IOC_AO_IOCG_019_iocg_019_ds2_END (6)
#define SOC_IOC_AO_IOCG_019_iocg_019_sl_START (7)
#define SOC_IOC_AO_IOCG_019_iocg_019_sl_END (7)
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
} SOC_IOC_AO_IOCG_020_UNION;
#endif
#define SOC_IOC_AO_IOCG_020_iocg_020_pu_START (0)
#define SOC_IOC_AO_IOCG_020_iocg_020_pu_END (0)
#define SOC_IOC_AO_IOCG_020_iocg_020_pd_START (1)
#define SOC_IOC_AO_IOCG_020_iocg_020_pd_END (1)
#define SOC_IOC_AO_IOCG_020_iocg_020_st_START (3)
#define SOC_IOC_AO_IOCG_020_iocg_020_st_END (3)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds0_START (4)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds0_END (4)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds1_START (5)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds1_END (5)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds2_START (6)
#define SOC_IOC_AO_IOCG_020_iocg_020_ds2_END (6)
#define SOC_IOC_AO_IOCG_020_iocg_020_sl_START (7)
#define SOC_IOC_AO_IOCG_020_iocg_020_sl_END (7)
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
} SOC_IOC_AO_IOCG_021_UNION;
#endif
#define SOC_IOC_AO_IOCG_021_iocg_021_pu_START (0)
#define SOC_IOC_AO_IOCG_021_iocg_021_pu_END (0)
#define SOC_IOC_AO_IOCG_021_iocg_021_pd_START (1)
#define SOC_IOC_AO_IOCG_021_iocg_021_pd_END (1)
#define SOC_IOC_AO_IOCG_021_iocg_021_st_START (3)
#define SOC_IOC_AO_IOCG_021_iocg_021_st_END (3)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds0_START (4)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds0_END (4)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds1_START (5)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds1_END (5)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds2_START (6)
#define SOC_IOC_AO_IOCG_021_iocg_021_ds2_END (6)
#define SOC_IOC_AO_IOCG_021_iocg_021_sl_START (7)
#define SOC_IOC_AO_IOCG_021_iocg_021_sl_END (7)
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
} SOC_IOC_AO_IOCG_022_UNION;
#endif
#define SOC_IOC_AO_IOCG_022_iocg_022_pu_START (0)
#define SOC_IOC_AO_IOCG_022_iocg_022_pu_END (0)
#define SOC_IOC_AO_IOCG_022_iocg_022_pd_START (1)
#define SOC_IOC_AO_IOCG_022_iocg_022_pd_END (1)
#define SOC_IOC_AO_IOCG_022_iocg_022_st_START (3)
#define SOC_IOC_AO_IOCG_022_iocg_022_st_END (3)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds0_START (4)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds0_END (4)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds1_START (5)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds1_END (5)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds2_START (6)
#define SOC_IOC_AO_IOCG_022_iocg_022_ds2_END (6)
#define SOC_IOC_AO_IOCG_022_iocg_022_sl_START (7)
#define SOC_IOC_AO_IOCG_022_iocg_022_sl_END (7)
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
} SOC_IOC_AO_IOCG_023_UNION;
#endif
#define SOC_IOC_AO_IOCG_023_iocg_023_pu_START (0)
#define SOC_IOC_AO_IOCG_023_iocg_023_pu_END (0)
#define SOC_IOC_AO_IOCG_023_iocg_023_pd_START (1)
#define SOC_IOC_AO_IOCG_023_iocg_023_pd_END (1)
#define SOC_IOC_AO_IOCG_023_iocg_023_st_START (3)
#define SOC_IOC_AO_IOCG_023_iocg_023_st_END (3)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds0_START (4)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds0_END (4)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds1_START (5)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds1_END (5)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds2_START (6)
#define SOC_IOC_AO_IOCG_023_iocg_023_ds2_END (6)
#define SOC_IOC_AO_IOCG_023_iocg_023_sl_START (7)
#define SOC_IOC_AO_IOCG_023_iocg_023_sl_END (7)
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
} SOC_IOC_AO_IOCG_024_UNION;
#endif
#define SOC_IOC_AO_IOCG_024_iocg_024_pu_START (0)
#define SOC_IOC_AO_IOCG_024_iocg_024_pu_END (0)
#define SOC_IOC_AO_IOCG_024_iocg_024_pd_START (1)
#define SOC_IOC_AO_IOCG_024_iocg_024_pd_END (1)
#define SOC_IOC_AO_IOCG_024_iocg_024_st_START (3)
#define SOC_IOC_AO_IOCG_024_iocg_024_st_END (3)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds0_START (4)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds0_END (4)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds1_START (5)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds1_END (5)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds2_START (6)
#define SOC_IOC_AO_IOCG_024_iocg_024_ds2_END (6)
#define SOC_IOC_AO_IOCG_024_iocg_024_sl_START (7)
#define SOC_IOC_AO_IOCG_024_iocg_024_sl_END (7)
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
} SOC_IOC_AO_IOCG_025_UNION;
#endif
#define SOC_IOC_AO_IOCG_025_iocg_025_pu_START (0)
#define SOC_IOC_AO_IOCG_025_iocg_025_pu_END (0)
#define SOC_IOC_AO_IOCG_025_iocg_025_pd_START (1)
#define SOC_IOC_AO_IOCG_025_iocg_025_pd_END (1)
#define SOC_IOC_AO_IOCG_025_iocg_025_st_START (3)
#define SOC_IOC_AO_IOCG_025_iocg_025_st_END (3)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds0_START (4)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds0_END (4)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds1_START (5)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds1_END (5)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds2_START (6)
#define SOC_IOC_AO_IOCG_025_iocg_025_ds2_END (6)
#define SOC_IOC_AO_IOCG_025_iocg_025_sl_START (7)
#define SOC_IOC_AO_IOCG_025_iocg_025_sl_END (7)
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
} SOC_IOC_AO_IOCG_026_UNION;
#endif
#define SOC_IOC_AO_IOCG_026_iocg_026_pu_START (0)
#define SOC_IOC_AO_IOCG_026_iocg_026_pu_END (0)
#define SOC_IOC_AO_IOCG_026_iocg_026_pd_START (1)
#define SOC_IOC_AO_IOCG_026_iocg_026_pd_END (1)
#define SOC_IOC_AO_IOCG_026_iocg_026_st_START (3)
#define SOC_IOC_AO_IOCG_026_iocg_026_st_END (3)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds0_START (4)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds0_END (4)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds1_START (5)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds1_END (5)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds2_START (6)
#define SOC_IOC_AO_IOCG_026_iocg_026_ds2_END (6)
#define SOC_IOC_AO_IOCG_026_iocg_026_sl_START (7)
#define SOC_IOC_AO_IOCG_026_iocg_026_sl_END (7)
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
} SOC_IOC_AO_IOCG_027_UNION;
#endif
#define SOC_IOC_AO_IOCG_027_iocg_027_pu_START (0)
#define SOC_IOC_AO_IOCG_027_iocg_027_pu_END (0)
#define SOC_IOC_AO_IOCG_027_iocg_027_pd_START (1)
#define SOC_IOC_AO_IOCG_027_iocg_027_pd_END (1)
#define SOC_IOC_AO_IOCG_027_iocg_027_st_START (3)
#define SOC_IOC_AO_IOCG_027_iocg_027_st_END (3)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds0_START (4)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds0_END (4)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds1_START (5)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds1_END (5)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds2_START (6)
#define SOC_IOC_AO_IOCG_027_iocg_027_ds2_END (6)
#define SOC_IOC_AO_IOCG_027_iocg_027_sl_START (7)
#define SOC_IOC_AO_IOCG_027_iocg_027_sl_END (7)
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
} SOC_IOC_AO_IOCG_028_UNION;
#endif
#define SOC_IOC_AO_IOCG_028_iocg_028_pu_START (0)
#define SOC_IOC_AO_IOCG_028_iocg_028_pu_END (0)
#define SOC_IOC_AO_IOCG_028_iocg_028_pd_START (1)
#define SOC_IOC_AO_IOCG_028_iocg_028_pd_END (1)
#define SOC_IOC_AO_IOCG_028_iocg_028_st_START (3)
#define SOC_IOC_AO_IOCG_028_iocg_028_st_END (3)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds0_START (4)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds0_END (4)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds1_START (5)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds1_END (5)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds2_START (6)
#define SOC_IOC_AO_IOCG_028_iocg_028_ds2_END (6)
#define SOC_IOC_AO_IOCG_028_iocg_028_sl_START (7)
#define SOC_IOC_AO_IOCG_028_iocg_028_sl_END (7)
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
} SOC_IOC_AO_IOCG_029_UNION;
#endif
#define SOC_IOC_AO_IOCG_029_iocg_029_pu_START (0)
#define SOC_IOC_AO_IOCG_029_iocg_029_pu_END (0)
#define SOC_IOC_AO_IOCG_029_iocg_029_pd_START (1)
#define SOC_IOC_AO_IOCG_029_iocg_029_pd_END (1)
#define SOC_IOC_AO_IOCG_029_iocg_029_st_START (3)
#define SOC_IOC_AO_IOCG_029_iocg_029_st_END (3)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds0_START (4)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds0_END (4)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds1_START (5)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds1_END (5)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds2_START (6)
#define SOC_IOC_AO_IOCG_029_iocg_029_ds2_END (6)
#define SOC_IOC_AO_IOCG_029_iocg_029_sl_START (7)
#define SOC_IOC_AO_IOCG_029_iocg_029_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_01_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_st_START (3)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_st_END (3)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_01_iocg_se_01_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_02_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_st_START (3)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_st_END (3)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_02_iocg_se_02_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_03_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_st_START (3)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_st_END (3)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_03_iocg_se_03_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_04_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_st_START (3)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_st_END (3)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_04_iocg_se_04_sl_END (7)
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
} SOC_IOC_AO_IOCG_030_UNION;
#endif
#define SOC_IOC_AO_IOCG_030_iocg_030_pu_START (0)
#define SOC_IOC_AO_IOCG_030_iocg_030_pu_END (0)
#define SOC_IOC_AO_IOCG_030_iocg_030_pd_START (1)
#define SOC_IOC_AO_IOCG_030_iocg_030_pd_END (1)
#define SOC_IOC_AO_IOCG_030_iocg_030_st_START (3)
#define SOC_IOC_AO_IOCG_030_iocg_030_st_END (3)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds0_START (4)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds0_END (4)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds1_START (5)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds1_END (5)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds2_START (6)
#define SOC_IOC_AO_IOCG_030_iocg_030_ds2_END (6)
#define SOC_IOC_AO_IOCG_030_iocg_030_sl_START (7)
#define SOC_IOC_AO_IOCG_030_iocg_030_sl_END (7)
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
} SOC_IOC_AO_IOCG_031_UNION;
#endif
#define SOC_IOC_AO_IOCG_031_iocg_031_pu_START (0)
#define SOC_IOC_AO_IOCG_031_iocg_031_pu_END (0)
#define SOC_IOC_AO_IOCG_031_iocg_031_pd_START (1)
#define SOC_IOC_AO_IOCG_031_iocg_031_pd_END (1)
#define SOC_IOC_AO_IOCG_031_iocg_031_st_START (3)
#define SOC_IOC_AO_IOCG_031_iocg_031_st_END (3)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds0_START (4)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds0_END (4)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds1_START (5)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds1_END (5)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds2_START (6)
#define SOC_IOC_AO_IOCG_031_iocg_031_ds2_END (6)
#define SOC_IOC_AO_IOCG_031_iocg_031_sl_START (7)
#define SOC_IOC_AO_IOCG_031_iocg_031_sl_END (7)
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
} SOC_IOC_AO_IOCG_032_UNION;
#endif
#define SOC_IOC_AO_IOCG_032_iocg_032_pu_START (0)
#define SOC_IOC_AO_IOCG_032_iocg_032_pu_END (0)
#define SOC_IOC_AO_IOCG_032_iocg_032_pd_START (1)
#define SOC_IOC_AO_IOCG_032_iocg_032_pd_END (1)
#define SOC_IOC_AO_IOCG_032_iocg_032_st_START (3)
#define SOC_IOC_AO_IOCG_032_iocg_032_st_END (3)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds0_START (4)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds0_END (4)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds1_START (5)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds1_END (5)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds2_START (6)
#define SOC_IOC_AO_IOCG_032_iocg_032_ds2_END (6)
#define SOC_IOC_AO_IOCG_032_iocg_032_sl_START (7)
#define SOC_IOC_AO_IOCG_032_iocg_032_sl_END (7)
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
} SOC_IOC_AO_IOCG_033_UNION;
#endif
#define SOC_IOC_AO_IOCG_033_iocg_033_pu_START (0)
#define SOC_IOC_AO_IOCG_033_iocg_033_pu_END (0)
#define SOC_IOC_AO_IOCG_033_iocg_033_pd_START (1)
#define SOC_IOC_AO_IOCG_033_iocg_033_pd_END (1)
#define SOC_IOC_AO_IOCG_033_iocg_033_st_START (3)
#define SOC_IOC_AO_IOCG_033_iocg_033_st_END (3)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds0_START (4)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds0_END (4)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds1_START (5)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds1_END (5)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds2_START (6)
#define SOC_IOC_AO_IOCG_033_iocg_033_ds2_END (6)
#define SOC_IOC_AO_IOCG_033_iocg_033_sl_START (7)
#define SOC_IOC_AO_IOCG_033_iocg_033_sl_END (7)
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
} SOC_IOC_AO_IOCG_034_UNION;
#endif
#define SOC_IOC_AO_IOCG_034_iocg_034_pu_START (0)
#define SOC_IOC_AO_IOCG_034_iocg_034_pu_END (0)
#define SOC_IOC_AO_IOCG_034_iocg_034_pd_START (1)
#define SOC_IOC_AO_IOCG_034_iocg_034_pd_END (1)
#define SOC_IOC_AO_IOCG_034_iocg_034_st_START (3)
#define SOC_IOC_AO_IOCG_034_iocg_034_st_END (3)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds0_START (4)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds0_END (4)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds1_START (5)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds1_END (5)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds2_START (6)
#define SOC_IOC_AO_IOCG_034_iocg_034_ds2_END (6)
#define SOC_IOC_AO_IOCG_034_iocg_034_sl_START (7)
#define SOC_IOC_AO_IOCG_034_iocg_034_sl_END (7)
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
} SOC_IOC_AO_IOCG_035_UNION;
#endif
#define SOC_IOC_AO_IOCG_035_iocg_035_pu_START (0)
#define SOC_IOC_AO_IOCG_035_iocg_035_pu_END (0)
#define SOC_IOC_AO_IOCG_035_iocg_035_pd_START (1)
#define SOC_IOC_AO_IOCG_035_iocg_035_pd_END (1)
#define SOC_IOC_AO_IOCG_035_iocg_035_st_START (3)
#define SOC_IOC_AO_IOCG_035_iocg_035_st_END (3)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds0_START (4)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds0_END (4)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds1_START (5)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds1_END (5)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds2_START (6)
#define SOC_IOC_AO_IOCG_035_iocg_035_ds2_END (6)
#define SOC_IOC_AO_IOCG_035_iocg_035_sl_START (7)
#define SOC_IOC_AO_IOCG_035_iocg_035_sl_END (7)
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
} SOC_IOC_AO_IOCG_036_UNION;
#endif
#define SOC_IOC_AO_IOCG_036_iocg_036_pu_START (0)
#define SOC_IOC_AO_IOCG_036_iocg_036_pu_END (0)
#define SOC_IOC_AO_IOCG_036_iocg_036_pd_START (1)
#define SOC_IOC_AO_IOCG_036_iocg_036_pd_END (1)
#define SOC_IOC_AO_IOCG_036_iocg_036_st_START (3)
#define SOC_IOC_AO_IOCG_036_iocg_036_st_END (3)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds0_START (4)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds0_END (4)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds1_START (5)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds1_END (5)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds2_START (6)
#define SOC_IOC_AO_IOCG_036_iocg_036_ds2_END (6)
#define SOC_IOC_AO_IOCG_036_iocg_036_sl_START (7)
#define SOC_IOC_AO_IOCG_036_iocg_036_sl_END (7)
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
} SOC_IOC_AO_IOCG_037_UNION;
#endif
#define SOC_IOC_AO_IOCG_037_iocg_037_pu_START (0)
#define SOC_IOC_AO_IOCG_037_iocg_037_pu_END (0)
#define SOC_IOC_AO_IOCG_037_iocg_037_pd_START (1)
#define SOC_IOC_AO_IOCG_037_iocg_037_pd_END (1)
#define SOC_IOC_AO_IOCG_037_iocg_037_st_START (3)
#define SOC_IOC_AO_IOCG_037_iocg_037_st_END (3)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds0_START (4)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds0_END (4)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds1_START (5)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds1_END (5)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds2_START (6)
#define SOC_IOC_AO_IOCG_037_iocg_037_ds2_END (6)
#define SOC_IOC_AO_IOCG_037_iocg_037_sl_START (7)
#define SOC_IOC_AO_IOCG_037_iocg_037_sl_END (7)
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
} SOC_IOC_AO_IOCG_038_UNION;
#endif
#define SOC_IOC_AO_IOCG_038_iocg_038_pu_START (0)
#define SOC_IOC_AO_IOCG_038_iocg_038_pu_END (0)
#define SOC_IOC_AO_IOCG_038_iocg_038_pd_START (1)
#define SOC_IOC_AO_IOCG_038_iocg_038_pd_END (1)
#define SOC_IOC_AO_IOCG_038_iocg_038_st_START (3)
#define SOC_IOC_AO_IOCG_038_iocg_038_st_END (3)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds0_START (4)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds0_END (4)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds1_START (5)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds1_END (5)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds2_START (6)
#define SOC_IOC_AO_IOCG_038_iocg_038_ds2_END (6)
#define SOC_IOC_AO_IOCG_038_iocg_038_sl_START (7)
#define SOC_IOC_AO_IOCG_038_iocg_038_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_05_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_st_START (3)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_st_END (3)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_05_iocg_se_05_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_06_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_st_START (3)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_st_END (3)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_06_iocg_se_06_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_07_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_st_START (3)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_st_END (3)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_07_iocg_se_07_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_08_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_st_START (3)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_st_END (3)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_08_iocg_se_08_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_09_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_st_START (3)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_st_END (3)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_09_iocg_se_09_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_10_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_st_START (3)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_st_END (3)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_10_iocg_se_10_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_11_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_st_START (3)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_st_END (3)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_11_iocg_se_11_sl_END (7)
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
} SOC_IOC_AO_IOCG_SE_12_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_st_START (3)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_st_END (3)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_12_iocg_se_12_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_13_pu : 1;
        unsigned int iocg_se_13_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_13_st : 1;
        unsigned int iocg_se_13_ds0 : 1;
        unsigned int iocg_se_13_ds1 : 1;
        unsigned int iocg_se_13_ds2 : 1;
        unsigned int iocg_se_13_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_13_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_st_START (3)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_st_END (3)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_13_iocg_se_13_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_14_pu : 1;
        unsigned int iocg_se_14_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_14_st : 1;
        unsigned int iocg_se_14_ds0 : 1;
        unsigned int iocg_se_14_ds1 : 1;
        unsigned int iocg_se_14_ds2 : 1;
        unsigned int iocg_se_14_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_14_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_st_START (3)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_st_END (3)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_14_iocg_se_14_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_15_pu : 1;
        unsigned int iocg_se_15_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_15_st : 1;
        unsigned int iocg_se_15_ds0 : 1;
        unsigned int iocg_se_15_ds1 : 1;
        unsigned int iocg_se_15_ds2 : 1;
        unsigned int iocg_se_15_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_15_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_st_START (3)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_st_END (3)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_15_iocg_se_15_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_16_pu : 1;
        unsigned int iocg_se_16_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_16_st : 1;
        unsigned int iocg_se_16_ds0 : 1;
        unsigned int iocg_se_16_ds1 : 1;
        unsigned int iocg_se_16_ds2 : 1;
        unsigned int iocg_se_16_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_16_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_st_START (3)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_st_END (3)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_16_iocg_se_16_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_17_pu : 1;
        unsigned int iocg_se_17_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_17_st : 1;
        unsigned int iocg_se_17_ds0 : 1;
        unsigned int iocg_se_17_ds1 : 1;
        unsigned int iocg_se_17_ds2 : 1;
        unsigned int iocg_se_17_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_17_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_st_START (3)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_st_END (3)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_17_iocg_se_17_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_18_pu : 1;
        unsigned int iocg_se_18_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_18_st : 1;
        unsigned int iocg_se_18_ds0 : 1;
        unsigned int iocg_se_18_ds1 : 1;
        unsigned int iocg_se_18_ds2 : 1;
        unsigned int iocg_se_18_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_18_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_st_START (3)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_st_END (3)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_18_iocg_se_18_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_19_pu : 1;
        unsigned int iocg_se_19_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_19_st : 1;
        unsigned int iocg_se_19_ds0 : 1;
        unsigned int iocg_se_19_ds1 : 1;
        unsigned int iocg_se_19_ds2 : 1;
        unsigned int iocg_se_19_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_19_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_st_START (3)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_st_END (3)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_19_iocg_se_19_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_20_pu : 1;
        unsigned int iocg_se_20_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_20_st : 1;
        unsigned int iocg_se_20_ds0 : 1;
        unsigned int iocg_se_20_ds1 : 1;
        unsigned int iocg_se_20_ds2 : 1;
        unsigned int iocg_se_20_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_20_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_st_START (3)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_st_END (3)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_20_iocg_se_20_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_21_pu : 1;
        unsigned int iocg_se_21_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_21_st : 1;
        unsigned int iocg_se_21_ds0 : 1;
        unsigned int iocg_se_21_ds1 : 1;
        unsigned int iocg_se_21_ds2 : 1;
        unsigned int iocg_se_21_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_21_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_st_START (3)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_st_END (3)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_21_iocg_se_21_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_22_pu : 1;
        unsigned int iocg_se_22_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_22_st : 1;
        unsigned int iocg_se_22_ds0 : 1;
        unsigned int iocg_se_22_ds1 : 1;
        unsigned int iocg_se_22_ds2 : 1;
        unsigned int iocg_se_22_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_22_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_st_START (3)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_st_END (3)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_22_iocg_se_22_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_23_pu : 1;
        unsigned int iocg_se_23_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_23_st : 1;
        unsigned int iocg_se_23_ds0 : 1;
        unsigned int iocg_se_23_ds1 : 1;
        unsigned int iocg_se_23_ds2 : 1;
        unsigned int iocg_se_23_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_23_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_st_START (3)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_st_END (3)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_23_iocg_se_23_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_24_pu : 1;
        unsigned int iocg_se_24_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_24_st : 1;
        unsigned int iocg_se_24_ds0 : 1;
        unsigned int iocg_se_24_ds1 : 1;
        unsigned int iocg_se_24_ds2 : 1;
        unsigned int iocg_se_24_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_24_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_st_START (3)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_st_END (3)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_24_iocg_se_24_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_25_pu : 1;
        unsigned int iocg_se_25_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_25_st : 1;
        unsigned int iocg_se_25_ds0 : 1;
        unsigned int iocg_se_25_ds1 : 1;
        unsigned int iocg_se_25_ds2 : 1;
        unsigned int iocg_se_25_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_25_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_st_START (3)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_st_END (3)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_25_iocg_se_25_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_26_pu : 1;
        unsigned int iocg_se_26_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_26_st : 1;
        unsigned int iocg_se_26_ds0 : 1;
        unsigned int iocg_se_26_ds1 : 1;
        unsigned int iocg_se_26_ds2 : 1;
        unsigned int iocg_se_26_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_26_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_st_START (3)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_st_END (3)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_26_iocg_se_26_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_27_pu : 1;
        unsigned int iocg_se_27_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_27_st : 1;
        unsigned int iocg_se_27_ds0 : 1;
        unsigned int iocg_se_27_ds1 : 1;
        unsigned int iocg_se_27_ds2 : 1;
        unsigned int iocg_se_27_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_27_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_st_START (3)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_st_END (3)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_27_iocg_se_27_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_28_pu : 1;
        unsigned int iocg_se_28_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_28_st : 1;
        unsigned int iocg_se_28_ds0 : 1;
        unsigned int iocg_se_28_ds1 : 1;
        unsigned int iocg_se_28_ds2 : 1;
        unsigned int iocg_se_28_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_28_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_st_START (3)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_st_END (3)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_28_iocg_se_28_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_29_pu : 1;
        unsigned int iocg_se_29_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_29_st : 1;
        unsigned int iocg_se_29_ds0 : 1;
        unsigned int iocg_se_29_ds1 : 1;
        unsigned int iocg_se_29_ds2 : 1;
        unsigned int iocg_se_29_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_29_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_st_START (3)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_st_END (3)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_29_iocg_se_29_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_30_pu : 1;
        unsigned int iocg_se_30_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_30_st : 1;
        unsigned int iocg_se_30_ds0 : 1;
        unsigned int iocg_se_30_ds1 : 1;
        unsigned int iocg_se_30_ds2 : 1;
        unsigned int iocg_se_30_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_30_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_st_START (3)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_st_END (3)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_30_iocg_se_30_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_31_pu : 1;
        unsigned int iocg_se_31_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_31_st : 1;
        unsigned int iocg_se_31_ds0 : 1;
        unsigned int iocg_se_31_ds1 : 1;
        unsigned int iocg_se_31_ds2 : 1;
        unsigned int iocg_se_31_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_31_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_st_START (3)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_st_END (3)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_31_iocg_se_31_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_32_pu : 1;
        unsigned int iocg_se_32_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_32_st : 1;
        unsigned int iocg_se_32_ds0 : 1;
        unsigned int iocg_se_32_ds1 : 1;
        unsigned int iocg_se_32_ds2 : 1;
        unsigned int iocg_se_32_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_32_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_st_START (3)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_st_END (3)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_32_iocg_se_32_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_33_pu : 1;
        unsigned int iocg_se_33_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_33_st : 1;
        unsigned int iocg_se_33_ds0 : 1;
        unsigned int iocg_se_33_ds1 : 1;
        unsigned int iocg_se_33_ds2 : 1;
        unsigned int iocg_se_33_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_33_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_st_START (3)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_st_END (3)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_33_iocg_se_33_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_34_pu : 1;
        unsigned int iocg_se_34_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_34_st : 1;
        unsigned int iocg_se_34_ds0 : 1;
        unsigned int iocg_se_34_ds1 : 1;
        unsigned int iocg_se_34_ds2 : 1;
        unsigned int iocg_se_34_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_34_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_st_START (3)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_st_END (3)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_34_iocg_se_34_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_35_pu : 1;
        unsigned int iocg_se_35_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_35_st : 1;
        unsigned int iocg_se_35_ds0 : 1;
        unsigned int iocg_se_35_ds1 : 1;
        unsigned int iocg_se_35_ds2 : 1;
        unsigned int iocg_se_35_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_35_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_st_START (3)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_st_END (3)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_35_iocg_se_35_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_36_pu : 1;
        unsigned int iocg_se_36_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_36_st : 1;
        unsigned int iocg_se_36_ds0 : 1;
        unsigned int iocg_se_36_ds1 : 1;
        unsigned int iocg_se_36_ds2 : 1;
        unsigned int iocg_se_36_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_36_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_st_START (3)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_st_END (3)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_36_iocg_se_36_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_37_pu : 1;
        unsigned int iocg_se_37_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_37_st : 1;
        unsigned int iocg_se_37_ds0 : 1;
        unsigned int iocg_se_37_ds1 : 1;
        unsigned int iocg_se_37_ds2 : 1;
        unsigned int iocg_se_37_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_37_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_st_START (3)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_st_END (3)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_37_iocg_se_37_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_38_pu : 1;
        unsigned int iocg_se_38_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_38_st : 1;
        unsigned int iocg_se_38_ds0 : 1;
        unsigned int iocg_se_38_ds1 : 1;
        unsigned int iocg_se_38_ds2 : 1;
        unsigned int iocg_se_38_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_38_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_st_START (3)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_st_END (3)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_38_iocg_se_38_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_39_pu : 1;
        unsigned int iocg_se_39_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_39_st : 1;
        unsigned int iocg_se_39_ds0 : 1;
        unsigned int iocg_se_39_ds1 : 1;
        unsigned int iocg_se_39_ds2 : 1;
        unsigned int iocg_se_39_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_39_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_st_START (3)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_st_END (3)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_39_iocg_se_39_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_40_pu : 1;
        unsigned int iocg_se_40_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_40_st : 1;
        unsigned int iocg_se_40_ds0 : 1;
        unsigned int iocg_se_40_ds1 : 1;
        unsigned int iocg_se_40_ds2 : 1;
        unsigned int iocg_se_40_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_40_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_st_START (3)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_st_END (3)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_40_iocg_se_40_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_41_pu : 1;
        unsigned int iocg_se_41_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_41_st : 1;
        unsigned int iocg_se_41_ds0 : 1;
        unsigned int iocg_se_41_ds1 : 1;
        unsigned int iocg_se_41_ds2 : 1;
        unsigned int iocg_se_41_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_41_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_st_START (3)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_st_END (3)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_41_iocg_se_41_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_42_pu : 1;
        unsigned int iocg_se_42_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_42_st : 1;
        unsigned int iocg_se_42_ds0 : 1;
        unsigned int iocg_se_42_ds1 : 1;
        unsigned int iocg_se_42_ds2 : 1;
        unsigned int iocg_se_42_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_42_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_st_START (3)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_st_END (3)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_42_iocg_se_42_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_43_pu : 1;
        unsigned int iocg_se_43_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_43_st : 1;
        unsigned int iocg_se_43_ds0 : 1;
        unsigned int iocg_se_43_ds1 : 1;
        unsigned int iocg_se_43_ds2 : 1;
        unsigned int iocg_se_43_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_43_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_st_START (3)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_st_END (3)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_43_iocg_se_43_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_44_pu : 1;
        unsigned int iocg_se_44_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_44_st : 1;
        unsigned int iocg_se_44_ds0 : 1;
        unsigned int iocg_se_44_ds1 : 1;
        unsigned int iocg_se_44_ds2 : 1;
        unsigned int iocg_se_44_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_44_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_st_START (3)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_st_END (3)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_44_iocg_se_44_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_45_pu : 1;
        unsigned int iocg_se_45_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_45_st : 1;
        unsigned int iocg_se_45_ds0 : 1;
        unsigned int iocg_se_45_ds1 : 1;
        unsigned int iocg_se_45_ds2 : 1;
        unsigned int iocg_se_45_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_45_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_st_START (3)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_st_END (3)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_45_iocg_se_45_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_46_pu : 1;
        unsigned int iocg_se_46_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_46_st : 1;
        unsigned int iocg_se_46_ds0 : 1;
        unsigned int iocg_se_46_ds1 : 1;
        unsigned int iocg_se_46_ds2 : 1;
        unsigned int iocg_se_46_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_46_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_st_START (3)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_st_END (3)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_46_iocg_se_46_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_47_pu : 1;
        unsigned int iocg_se_47_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_47_st : 1;
        unsigned int iocg_se_47_ds0 : 1;
        unsigned int iocg_se_47_ds1 : 1;
        unsigned int iocg_se_47_ds2 : 1;
        unsigned int iocg_se_47_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_47_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_st_START (3)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_st_END (3)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_47_iocg_se_47_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_48_pu : 1;
        unsigned int iocg_se_48_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_48_st : 1;
        unsigned int iocg_se_48_ds0 : 1;
        unsigned int iocg_se_48_ds1 : 1;
        unsigned int iocg_se_48_ds2 : 1;
        unsigned int iocg_se_48_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_48_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_st_START (3)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_st_END (3)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_48_iocg_se_48_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_49_pu : 1;
        unsigned int iocg_se_49_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_49_st : 1;
        unsigned int iocg_se_49_ds0 : 1;
        unsigned int iocg_se_49_ds1 : 1;
        unsigned int iocg_se_49_ds2 : 1;
        unsigned int iocg_se_49_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_49_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_st_START (3)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_st_END (3)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_49_iocg_se_49_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_50_pu : 1;
        unsigned int iocg_se_50_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_50_st : 1;
        unsigned int iocg_se_50_ds0 : 1;
        unsigned int iocg_se_50_ds1 : 1;
        unsigned int iocg_se_50_ds2 : 1;
        unsigned int iocg_se_50_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_50_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_st_START (3)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_st_END (3)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_50_iocg_se_50_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_51_pu : 1;
        unsigned int iocg_se_51_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_51_st : 1;
        unsigned int iocg_se_51_ds0 : 1;
        unsigned int iocg_se_51_ds1 : 1;
        unsigned int iocg_se_51_ds2 : 1;
        unsigned int iocg_se_51_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_51_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_st_START (3)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_st_END (3)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_51_iocg_se_51_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_52_pu : 1;
        unsigned int iocg_se_52_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_52_st : 1;
        unsigned int iocg_se_52_ds0 : 1;
        unsigned int iocg_se_52_ds1 : 1;
        unsigned int iocg_se_52_ds2 : 1;
        unsigned int iocg_se_52_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_52_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_st_START (3)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_st_END (3)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_52_iocg_se_52_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_53_pu : 1;
        unsigned int iocg_se_53_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_53_st : 1;
        unsigned int iocg_se_53_ds0 : 1;
        unsigned int iocg_se_53_ds1 : 1;
        unsigned int iocg_se_53_ds2 : 1;
        unsigned int iocg_se_53_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_53_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_st_START (3)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_st_END (3)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_53_iocg_se_53_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_54_pu : 1;
        unsigned int iocg_se_54_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_54_st : 1;
        unsigned int iocg_se_54_ds0 : 1;
        unsigned int iocg_se_54_ds1 : 1;
        unsigned int iocg_se_54_ds2 : 1;
        unsigned int iocg_se_54_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_54_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_st_START (3)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_st_END (3)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_54_iocg_se_54_sl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iocg_se_55_pu : 1;
        unsigned int iocg_se_55_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_55_st : 1;
        unsigned int iocg_se_55_ds0 : 1;
        unsigned int iocg_se_55_ds1 : 1;
        unsigned int iocg_se_55_ds2 : 1;
        unsigned int iocg_se_55_sl : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOC_AO_IOCG_SE_55_UNION;
#endif
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pu_START (0)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pu_END (0)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pd_START (1)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_pd_END (1)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_st_START (3)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_st_END (3)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds0_START (4)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds0_END (4)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds1_START (5)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds1_END (5)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds2_START (6)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_ds2_END (6)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_sl_START (7)
#define SOC_IOC_AO_IOCG_SE_55_iocg_se_55_sl_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
