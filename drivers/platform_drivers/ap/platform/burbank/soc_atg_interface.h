#ifndef __SOC_ATG_INTERFACE_H__
#define __SOC_ATG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ATG_ATGM0_MODE_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_ATG_ATGM0_WBURST_MODE_ADDR(base) ((base) + (0x004UL))
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x008UL))
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x00cUL))
#define SOC_ATG_ATGM0_WADDR_NUM_ADDR(base) ((base) + (0x010UL))
#define SOC_ATG_ATGM0_WBURST_MODE2_ADDR(base) ((base) + (0x014UL))
#define SOC_ATG_ATGM0_WDATA00_ADDR(base) ((base) + (0x020UL))
#define SOC_ATG_ATGM0_WDATA01_ADDR(base) ((base) + (0x024UL))
#define SOC_ATG_ATGM0_WDATA02_ADDR(base) ((base) + (0x028UL))
#define SOC_ATG_ATGM0_WDATA03_ADDR(base) ((base) + (0x02CUL))
#define SOC_ATG_ATGM0_WDATA10_ADDR(base) ((base) + (0x030UL))
#define SOC_ATG_ATGM0_WDATA11_ADDR(base) ((base) + (0x034UL))
#define SOC_ATG_ATGM0_WDATA12_ADDR(base) ((base) + (0x038UL))
#define SOC_ATG_ATGM0_WDATA13_ADDR(base) ((base) + (0x03CUL))
#define SOC_ATG_ATGM0_WDATA20_ADDR(base) ((base) + (0x040UL))
#define SOC_ATG_ATGM0_WDATA21_ADDR(base) ((base) + (0x044UL))
#define SOC_ATG_ATGM0_WDATA22_ADDR(base) ((base) + (0x048UL))
#define SOC_ATG_ATGM0_WDATA23_ADDR(base) ((base) + (0x04CUL))
#define SOC_ATG_ATGM0_WDATA30_ADDR(base) ((base) + (0x050UL))
#define SOC_ATG_ATGM0_WDATA31_ADDR(base) ((base) + (0x054UL))
#define SOC_ATG_ATGM0_WDATA32_ADDR(base) ((base) + (0x058UL))
#define SOC_ATG_ATGM0_WDATA33_ADDR(base) ((base) + (0x05CUL))
#define SOC_ATG_ATGM0_RBURST_MODE_ADDR(base) ((base) + (0x060UL))
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x064UL))
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x068UL))
#define SOC_ATG_ATGM0_RADDR_NUM_ADDR(base) ((base) + (0x06cUL))
#define SOC_ATG_ATGM0_BURST_FINI_STAT_ADDR(base) ((base) + (0x070UL))
#define SOC_ATG_ATGM0_ACLK_GT_ADDR(base) ((base) + (0x074UL))
#define SOC_ATG_ATGM0_RBURST_MODE2_ADDR(base) ((base) + (0x078UL))
#define SOC_ATG_ATGM1_MODE_CTRL_ADDR(base) ((base) + (0x100UL))
#define SOC_ATG_ATGM1_WBURST_MODE_ADDR(base) ((base) + (0x104UL))
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x108UL))
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x10cUL))
#define SOC_ATG_ATGM1_WADDR_NUM_ADDR(base) ((base) + (0x110UL))
#define SOC_ATG_ATGM1_WBURST_MODE2_ADDR(base) ((base) + (0x114UL))
#define SOC_ATG_ATGM1_WDATA00_ADDR(base) ((base) + (0x120UL))
#define SOC_ATG_ATGM1_WDATA01_ADDR(base) ((base) + (0x124UL))
#define SOC_ATG_ATGM1_WDATA02_ADDR(base) ((base) + (0x128UL))
#define SOC_ATG_ATGM1_WDATA03_ADDR(base) ((base) + (0x12CUL))
#define SOC_ATG_ATGM1_WDATA10_ADDR(base) ((base) + (0x130UL))
#define SOC_ATG_ATGM1_WDATA11_ADDR(base) ((base) + (0x134UL))
#define SOC_ATG_ATGM1_WDATA12_ADDR(base) ((base) + (0x138UL))
#define SOC_ATG_ATGM1_WDATA13_ADDR(base) ((base) + (0x13CUL))
#define SOC_ATG_ATGM1_WDATA20_ADDR(base) ((base) + (0x140UL))
#define SOC_ATG_ATGM1_WDATA21_ADDR(base) ((base) + (0x144UL))
#define SOC_ATG_ATGM1_WDATA22_ADDR(base) ((base) + (0x148UL))
#define SOC_ATG_ATGM1_WDATA23_ADDR(base) ((base) + (0x14CUL))
#define SOC_ATG_ATGM1_WDATA30_ADDR(base) ((base) + (0x150UL))
#define SOC_ATG_ATGM1_WDATA31_ADDR(base) ((base) + (0x154UL))
#define SOC_ATG_ATGM1_WDATA32_ADDR(base) ((base) + (0x158UL))
#define SOC_ATG_ATGM1_WDATA33_ADDR(base) ((base) + (0x15CUL))
#define SOC_ATG_ATGM1_RBURST_MODE_ADDR(base) ((base) + (0x160UL))
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x164UL))
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x168UL))
#define SOC_ATG_ATGM1_RADDR_NUM_ADDR(base) ((base) + (0x16cUL))
#define SOC_ATG_ATGM1_BURST_FINI_STAT_ADDR(base) ((base) + (0x170UL))
#define SOC_ATG_ATGM1_ACLK_GT_ADDR(base) ((base) + (0x174UL))
#define SOC_ATG_ATGM1_RBURST_MODE2_ADDR(base) ((base) + (0x178UL))
#define SOC_ATG_ATGM2_MODE_CTRL_ADDR(base) ((base) + (0x200UL))
#define SOC_ATG_ATGM2_WBURST_MODE_ADDR(base) ((base) + (0x204UL))
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x208UL))
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x20cUL))
#define SOC_ATG_ATGM2_WADDR_NUM_ADDR(base) ((base) + (0x210UL))
#define SOC_ATG_ATGM2_WBURST_MODE2_ADDR(base) ((base) + (0x214UL))
#define SOC_ATG_ATGM2_WDATA00_ADDR(base) ((base) + (0x220UL))
#define SOC_ATG_ATGM2_WDATA01_ADDR(base) ((base) + (0x224UL))
#define SOC_ATG_ATGM2_WDATA02_ADDR(base) ((base) + (0x228UL))
#define SOC_ATG_ATGM2_WDATA03_ADDR(base) ((base) + (0x22CUL))
#define SOC_ATG_ATGM2_WDATA10_ADDR(base) ((base) + (0x230UL))
#define SOC_ATG_ATGM2_WDATA11_ADDR(base) ((base) + (0x234UL))
#define SOC_ATG_ATGM2_WDATA12_ADDR(base) ((base) + (0x238UL))
#define SOC_ATG_ATGM2_WDATA13_ADDR(base) ((base) + (0x23CUL))
#define SOC_ATG_ATGM2_WDATA20_ADDR(base) ((base) + (0x240UL))
#define SOC_ATG_ATGM2_WDATA21_ADDR(base) ((base) + (0x244UL))
#define SOC_ATG_ATGM2_WDATA22_ADDR(base) ((base) + (0x248UL))
#define SOC_ATG_ATGM2_WDATA23_ADDR(base) ((base) + (0x24CUL))
#define SOC_ATG_ATGM2_WDATA30_ADDR(base) ((base) + (0x250UL))
#define SOC_ATG_ATGM2_WDATA31_ADDR(base) ((base) + (0x254UL))
#define SOC_ATG_ATGM2_WDATA32_ADDR(base) ((base) + (0x258UL))
#define SOC_ATG_ATGM2_WDATA33_ADDR(base) ((base) + (0x25CUL))
#define SOC_ATG_ATGM2_RBURST_MODE_ADDR(base) ((base) + (0x260UL))
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x264UL))
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x268UL))
#define SOC_ATG_ATGM2_RADDR_NUM_ADDR(base) ((base) + (0x26cUL))
#define SOC_ATG_ATGM2_BURST_FINI_STAT_ADDR(base) ((base) + (0x270UL))
#define SOC_ATG_ATGM2_ACLK_GT_ADDR(base) ((base) + (0x274UL))
#define SOC_ATG_ATGM2_RBURST_MODE2_ADDR(base) ((base) + (0x278UL))
#define SOC_ATG_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x400UL))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x404UL))
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x408UL))
#define SOC_ATG_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x40CUL))
#define SOC_ATG_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x410UL))
#define SOC_ATG_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x414UL))
#define SOC_ATG_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x418UL))
#define SOC_ATG_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x41CUL))
#define SOC_ATG_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x420UL))
#define SOC_ATG_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x424UL))
#define SOC_ATG_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x428UL))
#define SOC_ATG_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x42CUL))
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x430UL))
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x434UL))
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x438UL))
#define SOC_ATG_ATGS1_RDATA00_ADDR(base) ((base) + (0x440UL))
#define SOC_ATG_ATGS1_RDATA01_ADDR(base) ((base) + (0x444UL))
#define SOC_ATG_ATGS1_RDATA02_ADDR(base) ((base) + (0x448UL))
#define SOC_ATG_ATGS1_RDATA03_ADDR(base) ((base) + (0x44CUL))
#define SOC_ATG_ATGS1_RDATA10_ADDR(base) ((base) + (0x450UL))
#define SOC_ATG_ATGS1_RDATA11_ADDR(base) ((base) + (0x454UL))
#define SOC_ATG_ATGS1_RDATA12_ADDR(base) ((base) + (0x458UL))
#define SOC_ATG_ATGS1_RDATA13_ADDR(base) ((base) + (0x45CUL))
#define SOC_ATG_ATGS1_RDATA20_ADDR(base) ((base) + (0x460UL))
#define SOC_ATG_ATGS1_RDATA21_ADDR(base) ((base) + (0x464UL))
#define SOC_ATG_ATGS1_RDATA22_ADDR(base) ((base) + (0x468UL))
#define SOC_ATG_ATGS1_RDATA23_ADDR(base) ((base) + (0x46CUL))
#define SOC_ATG_ATGS1_RDATA30_ADDR(base) ((base) + (0x470UL))
#define SOC_ATG_ATGS1_RDATA31_ADDR(base) ((base) + (0x474UL))
#define SOC_ATG_ATGS1_RDATA32_ADDR(base) ((base) + (0x478UL))
#define SOC_ATG_ATGS1_RDATA33_ADDR(base) ((base) + (0x47CUL))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x480UL))
#define SOC_ATG_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x484UL))
#define SOC_ATG_ATGS2_MODE_CTRL_ADDR(base) ((base) + (0x500UL))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_ADDR(base) ((base) + (0x504UL))
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x508UL))
#define SOC_ATG_ATGS2_AXI_BUS_STAT_ADDR(base) ((base) + (0x50CUL))
#define SOC_ATG_ATGS2_DDR_RADDR0_ADDR(base) ((base) + (0x510UL))
#define SOC_ATG_ATGS2_DDR_RADDR1_ADDR(base) ((base) + (0x514UL))
#define SOC_ATG_ATGS2_DDR_RADDR2_ADDR(base) ((base) + (0x518UL))
#define SOC_ATG_ATGS2_DDR_RADDR3_ADDR(base) ((base) + (0x51CUL))
#define SOC_ATG_ATGS2_DDR_RADDR4_ADDR(base) ((base) + (0x520UL))
#define SOC_ATG_ATGS2_DDR_RADDR5_ADDR(base) ((base) + (0x524UL))
#define SOC_ATG_ATGS2_DDR_RADDR6_ADDR(base) ((base) + (0x528UL))
#define SOC_ATG_ATGS2_DDR_RADDR7_ADDR(base) ((base) + (0x52CUL))
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ADDR(base) ((base) + (0x530UL))
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ADDR(base) ((base) + (0x534UL))
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_ADDR(base) ((base) + (0x538UL))
#define SOC_ATG_ATGS2_RDATA00_ADDR(base) ((base) + (0x540UL))
#define SOC_ATG_ATGS2_RDATA01_ADDR(base) ((base) + (0x544UL))
#define SOC_ATG_ATGS2_RDATA02_ADDR(base) ((base) + (0x548UL))
#define SOC_ATG_ATGS2_RDATA03_ADDR(base) ((base) + (0x54CUL))
#define SOC_ATG_ATGS2_RDATA10_ADDR(base) ((base) + (0x550UL))
#define SOC_ATG_ATGS2_RDATA11_ADDR(base) ((base) + (0x554UL))
#define SOC_ATG_ATGS2_RDATA12_ADDR(base) ((base) + (0x558UL))
#define SOC_ATG_ATGS2_RDATA13_ADDR(base) ((base) + (0x55CUL))
#define SOC_ATG_ATGS2_RDATA20_ADDR(base) ((base) + (0x560UL))
#define SOC_ATG_ATGS2_RDATA21_ADDR(base) ((base) + (0x564UL))
#define SOC_ATG_ATGS2_RDATA22_ADDR(base) ((base) + (0x568UL))
#define SOC_ATG_ATGS2_RDATA23_ADDR(base) ((base) + (0x56CUL))
#define SOC_ATG_ATGS2_RDATA30_ADDR(base) ((base) + (0x570UL))
#define SOC_ATG_ATGS2_RDATA31_ADDR(base) ((base) + (0x574UL))
#define SOC_ATG_ATGS2_RDATA32_ADDR(base) ((base) + (0x578UL))
#define SOC_ATG_ATGS2_RDATA33_ADDR(base) ((base) + (0x57CUL))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x580UL))
#define SOC_ATG_ATGS2_ACLK_GT_ADDR(base) ((base) + (0x584UL))
#define SOC_ATG_ATGS3_MODE_CTRL_ADDR(base) ((base) + (0x600UL))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_ADDR(base) ((base) + (0x604UL))
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x608UL))
#define SOC_ATG_ATGS3_AXI_BUS_STAT_ADDR(base) ((base) + (0x60CUL))
#define SOC_ATG_ATGS3_DDR_RADDR0_ADDR(base) ((base) + (0x610UL))
#define SOC_ATG_ATGS3_DDR_RADDR1_ADDR(base) ((base) + (0x614UL))
#define SOC_ATG_ATGS3_DDR_RADDR2_ADDR(base) ((base) + (0x618UL))
#define SOC_ATG_ATGS3_DDR_RADDR3_ADDR(base) ((base) + (0x61CUL))
#define SOC_ATG_ATGS3_DDR_RADDR4_ADDR(base) ((base) + (0x620UL))
#define SOC_ATG_ATGS3_DDR_RADDR5_ADDR(base) ((base) + (0x624UL))
#define SOC_ATG_ATGS3_DDR_RADDR6_ADDR(base) ((base) + (0x628UL))
#define SOC_ATG_ATGS3_DDR_RADDR7_ADDR(base) ((base) + (0x62CUL))
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ADDR(base) ((base) + (0x630UL))
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ADDR(base) ((base) + (0x634UL))
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_ADDR(base) ((base) + (0x638UL))
#define SOC_ATG_ATGS3_RDATA00_ADDR(base) ((base) + (0x640UL))
#define SOC_ATG_ATGS3_RDATA01_ADDR(base) ((base) + (0x644UL))
#define SOC_ATG_ATGS3_RDATA02_ADDR(base) ((base) + (0x648UL))
#define SOC_ATG_ATGS3_RDATA03_ADDR(base) ((base) + (0x64CUL))
#define SOC_ATG_ATGS3_RDATA10_ADDR(base) ((base) + (0x650UL))
#define SOC_ATG_ATGS3_RDATA11_ADDR(base) ((base) + (0x654UL))
#define SOC_ATG_ATGS3_RDATA12_ADDR(base) ((base) + (0x658UL))
#define SOC_ATG_ATGS3_RDATA13_ADDR(base) ((base) + (0x65CUL))
#define SOC_ATG_ATGS3_RDATA20_ADDR(base) ((base) + (0x660UL))
#define SOC_ATG_ATGS3_RDATA21_ADDR(base) ((base) + (0x664UL))
#define SOC_ATG_ATGS3_RDATA22_ADDR(base) ((base) + (0x668UL))
#define SOC_ATG_ATGS3_RDATA23_ADDR(base) ((base) + (0x66CUL))
#define SOC_ATG_ATGS3_RDATA30_ADDR(base) ((base) + (0x670UL))
#define SOC_ATG_ATGS3_RDATA31_ADDR(base) ((base) + (0x674UL))
#define SOC_ATG_ATGS3_RDATA32_ADDR(base) ((base) + (0x678UL))
#define SOC_ATG_ATGS3_RDATA33_ADDR(base) ((base) + (0x67CUL))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x680UL))
#define SOC_ATG_ATGS3_ACLK_GT_ADDR(base) ((base) + (0x684UL))
#define SOC_ATG_ATGS4_MODE_CTRL_ADDR(base) ((base) + (0x700UL))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_ADDR(base) ((base) + (0x704UL))
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x708UL))
#define SOC_ATG_ATGS4_AXI_BUS_STAT_ADDR(base) ((base) + (0x70CUL))
#define SOC_ATG_ATGS4_DDR_RADDR0_ADDR(base) ((base) + (0x710UL))
#define SOC_ATG_ATGS4_DDR_RADDR1_ADDR(base) ((base) + (0x714UL))
#define SOC_ATG_ATGS4_DDR_RADDR2_ADDR(base) ((base) + (0x718UL))
#define SOC_ATG_ATGS4_DDR_RADDR3_ADDR(base) ((base) + (0x71CUL))
#define SOC_ATG_ATGS4_DDR_RADDR4_ADDR(base) ((base) + (0x720UL))
#define SOC_ATG_ATGS4_DDR_RADDR5_ADDR(base) ((base) + (0x724UL))
#define SOC_ATG_ATGS4_DDR_RADDR6_ADDR(base) ((base) + (0x728UL))
#define SOC_ATG_ATGS4_DDR_RADDR7_ADDR(base) ((base) + (0x72CUL))
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ADDR(base) ((base) + (0x730UL))
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ADDR(base) ((base) + (0x734UL))
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_ADDR(base) ((base) + (0x738UL))
#define SOC_ATG_ATGS4_RDATA00_ADDR(base) ((base) + (0x740UL))
#define SOC_ATG_ATGS4_RDATA01_ADDR(base) ((base) + (0x744UL))
#define SOC_ATG_ATGS4_RDATA02_ADDR(base) ((base) + (0x748UL))
#define SOC_ATG_ATGS4_RDATA03_ADDR(base) ((base) + (0x74CUL))
#define SOC_ATG_ATGS4_RDATA10_ADDR(base) ((base) + (0x750UL))
#define SOC_ATG_ATGS4_RDATA11_ADDR(base) ((base) + (0x754UL))
#define SOC_ATG_ATGS4_RDATA12_ADDR(base) ((base) + (0x758UL))
#define SOC_ATG_ATGS4_RDATA13_ADDR(base) ((base) + (0x75CUL))
#define SOC_ATG_ATGS4_RDATA20_ADDR(base) ((base) + (0x760UL))
#define SOC_ATG_ATGS4_RDATA21_ADDR(base) ((base) + (0x764UL))
#define SOC_ATG_ATGS4_RDATA22_ADDR(base) ((base) + (0x768UL))
#define SOC_ATG_ATGS4_RDATA23_ADDR(base) ((base) + (0x76CUL))
#define SOC_ATG_ATGS4_RDATA30_ADDR(base) ((base) + (0x770UL))
#define SOC_ATG_ATGS4_RDATA31_ADDR(base) ((base) + (0x774UL))
#define SOC_ATG_ATGS4_RDATA32_ADDR(base) ((base) + (0x778UL))
#define SOC_ATG_ATGS4_RDATA33_ADDR(base) ((base) + (0x77CUL))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x780UL))
#define SOC_ATG_ATGS4_ACLK_GT_ADDR(base) ((base) + (0x784UL))
#define SOC_ATG_ATGS5_MODE_CTRL_ADDR(base) ((base) + (0x800UL))
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_ADDR(base) ((base) + (0x804UL))
#define SOC_ATG_ATGS5_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x808UL))
#define SOC_ATG_ATGS5_AXI_BUS_STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_ATG_ATGS5_DDR_RADDR0_ADDR(base) ((base) + (0x810UL))
#define SOC_ATG_ATGS5_DDR_RADDR1_ADDR(base) ((base) + (0x814UL))
#define SOC_ATG_ATGS5_DDR_RADDR2_ADDR(base) ((base) + (0x818UL))
#define SOC_ATG_ATGS5_DDR_RADDR3_ADDR(base) ((base) + (0x81CUL))
#define SOC_ATG_ATGS5_DDR_RADDR4_ADDR(base) ((base) + (0x820UL))
#define SOC_ATG_ATGS5_DDR_RADDR5_ADDR(base) ((base) + (0x824UL))
#define SOC_ATG_ATGS5_DDR_RADDR6_ADDR(base) ((base) + (0x828UL))
#define SOC_ATG_ATGS5_DDR_RADDR7_ADDR(base) ((base) + (0x82CUL))
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ADDR(base) ((base) + (0x830UL))
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ADDR(base) ((base) + (0x834UL))
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_ADDR(base) ((base) + (0x838UL))
#define SOC_ATG_ATGS5_RDATA00_ADDR(base) ((base) + (0x840UL))
#define SOC_ATG_ATGS5_RDATA01_ADDR(base) ((base) + (0x844UL))
#define SOC_ATG_ATGS5_RDATA02_ADDR(base) ((base) + (0x848UL))
#define SOC_ATG_ATGS5_RDATA03_ADDR(base) ((base) + (0x84CUL))
#define SOC_ATG_ATGS5_RDATA10_ADDR(base) ((base) + (0x850UL))
#define SOC_ATG_ATGS5_RDATA11_ADDR(base) ((base) + (0x854UL))
#define SOC_ATG_ATGS5_RDATA12_ADDR(base) ((base) + (0x858UL))
#define SOC_ATG_ATGS5_RDATA13_ADDR(base) ((base) + (0x85CUL))
#define SOC_ATG_ATGS5_RDATA20_ADDR(base) ((base) + (0x860UL))
#define SOC_ATG_ATGS5_RDATA21_ADDR(base) ((base) + (0x864UL))
#define SOC_ATG_ATGS5_RDATA22_ADDR(base) ((base) + (0x868UL))
#define SOC_ATG_ATGS5_RDATA23_ADDR(base) ((base) + (0x86CUL))
#define SOC_ATG_ATGS5_RDATA30_ADDR(base) ((base) + (0x870UL))
#define SOC_ATG_ATGS5_RDATA31_ADDR(base) ((base) + (0x874UL))
#define SOC_ATG_ATGS5_RDATA32_ADDR(base) ((base) + (0x878UL))
#define SOC_ATG_ATGS5_RDATA33_ADDR(base) ((base) + (0x87CUL))
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x880UL))
#define SOC_ATG_ATGS5_ACLK_GT_ADDR(base) ((base) + (0x884UL))
#define SOC_ATG_ATGS6_MODE_CTRL_ADDR(base) ((base) + (0x900UL))
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_ADDR(base) ((base) + (0x904UL))
#define SOC_ATG_ATGS6_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x908UL))
#define SOC_ATG_ATGS6_AXI_BUS_STAT_ADDR(base) ((base) + (0x90CUL))
#define SOC_ATG_ATGS6_DDR_RADDR0_ADDR(base) ((base) + (0x910UL))
#define SOC_ATG_ATGS6_DDR_RADDR1_ADDR(base) ((base) + (0x914UL))
#define SOC_ATG_ATGS6_DDR_RADDR2_ADDR(base) ((base) + (0x918UL))
#define SOC_ATG_ATGS6_DDR_RADDR3_ADDR(base) ((base) + (0x91CUL))
#define SOC_ATG_ATGS6_DDR_RADDR4_ADDR(base) ((base) + (0x920UL))
#define SOC_ATG_ATGS6_DDR_RADDR5_ADDR(base) ((base) + (0x924UL))
#define SOC_ATG_ATGS6_DDR_RADDR6_ADDR(base) ((base) + (0x928UL))
#define SOC_ATG_ATGS6_DDR_RADDR7_ADDR(base) ((base) + (0x92CUL))
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ADDR(base) ((base) + (0x930UL))
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ADDR(base) ((base) + (0x934UL))
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_ADDR(base) ((base) + (0x938UL))
#define SOC_ATG_ATGS6_RDATA00_ADDR(base) ((base) + (0x940UL))
#define SOC_ATG_ATGS6_RDATA01_ADDR(base) ((base) + (0x944UL))
#define SOC_ATG_ATGS6_RDATA02_ADDR(base) ((base) + (0x948UL))
#define SOC_ATG_ATGS6_RDATA03_ADDR(base) ((base) + (0x94CUL))
#define SOC_ATG_ATGS6_RDATA10_ADDR(base) ((base) + (0x950UL))
#define SOC_ATG_ATGS6_RDATA11_ADDR(base) ((base) + (0x954UL))
#define SOC_ATG_ATGS6_RDATA12_ADDR(base) ((base) + (0x958UL))
#define SOC_ATG_ATGS6_RDATA13_ADDR(base) ((base) + (0x95CUL))
#define SOC_ATG_ATGS6_RDATA20_ADDR(base) ((base) + (0x960UL))
#define SOC_ATG_ATGS6_RDATA21_ADDR(base) ((base) + (0x964UL))
#define SOC_ATG_ATGS6_RDATA22_ADDR(base) ((base) + (0x968UL))
#define SOC_ATG_ATGS6_RDATA23_ADDR(base) ((base) + (0x96CUL))
#define SOC_ATG_ATGS6_RDATA30_ADDR(base) ((base) + (0x970UL))
#define SOC_ATG_ATGS6_RDATA31_ADDR(base) ((base) + (0x974UL))
#define SOC_ATG_ATGS6_RDATA32_ADDR(base) ((base) + (0x978UL))
#define SOC_ATG_ATGS6_RDATA33_ADDR(base) ((base) + (0x97CUL))
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x980UL))
#define SOC_ATG_ATGS6_ACLK_GT_ADDR(base) ((base) + (0x984UL))
#define SOC_ATG_ATGM3_MODE_CTRL_ADDR(base) ((base) + (0xA00UL))
#define SOC_ATG_ATGM3_WBURST_MODE_ADDR(base) ((base) + (0xA04UL))
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xA08UL))
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xA0cUL))
#define SOC_ATG_ATGM3_WADDR_NUM_ADDR(base) ((base) + (0xA10UL))
#define SOC_ATG_ATGM3_WBURST_MODE2_ADDR(base) ((base) + (0xA14UL))
#define SOC_ATG_ATGM3_WDATA00_ADDR(base) ((base) + (0xA20UL))
#define SOC_ATG_ATGM3_WDATA01_ADDR(base) ((base) + (0xA24UL))
#define SOC_ATG_ATGM3_WDATA02_ADDR(base) ((base) + (0xA28UL))
#define SOC_ATG_ATGM3_WDATA03_ADDR(base) ((base) + (0xA2CUL))
#define SOC_ATG_ATGM3_WDATA10_ADDR(base) ((base) + (0xA30UL))
#define SOC_ATG_ATGM3_WDATA11_ADDR(base) ((base) + (0xA34UL))
#define SOC_ATG_ATGM3_WDATA12_ADDR(base) ((base) + (0xA38UL))
#define SOC_ATG_ATGM3_WDATA13_ADDR(base) ((base) + (0xA3CUL))
#define SOC_ATG_ATGM3_WDATA20_ADDR(base) ((base) + (0xA40UL))
#define SOC_ATG_ATGM3_WDATA21_ADDR(base) ((base) + (0xA44UL))
#define SOC_ATG_ATGM3_WDATA22_ADDR(base) ((base) + (0xA48UL))
#define SOC_ATG_ATGM3_WDATA23_ADDR(base) ((base) + (0xA4CUL))
#define SOC_ATG_ATGM3_WDATA30_ADDR(base) ((base) + (0xA50UL))
#define SOC_ATG_ATGM3_WDATA31_ADDR(base) ((base) + (0xA54UL))
#define SOC_ATG_ATGM3_WDATA32_ADDR(base) ((base) + (0xA58UL))
#define SOC_ATG_ATGM3_WDATA33_ADDR(base) ((base) + (0xA5CUL))
#define SOC_ATG_ATGM3_RBURST_MODE_ADDR(base) ((base) + (0xA60UL))
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xA64UL))
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xA68UL))
#define SOC_ATG_ATGM3_RADDR_NUM_ADDR(base) ((base) + (0xA6cUL))
#define SOC_ATG_ATGM3_BURST_FINI_STAT_ADDR(base) ((base) + (0xA70UL))
#define SOC_ATG_ATGM3_ACLK_GT_ADDR(base) ((base) + (0xA74UL))
#define SOC_ATG_ATGM3_RBURST_MODE2_ADDR(base) ((base) + (0xA78UL))
#define SOC_ATG_ATGS7_MODE_CTRL_ADDR(base) ((base) + (0xB00UL))
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_ADDR(base) ((base) + (0xB04UL))
#define SOC_ATG_ATGS7_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0xB08UL))
#define SOC_ATG_ATGS7_AXI_BUS_STAT_ADDR(base) ((base) + (0xB0CUL))
#define SOC_ATG_ATGS7_DDR_RADDR0_ADDR(base) ((base) + (0xB10UL))
#define SOC_ATG_ATGS7_DDR_RADDR1_ADDR(base) ((base) + (0xB14UL))
#define SOC_ATG_ATGS7_DDR_RADDR2_ADDR(base) ((base) + (0xB18UL))
#define SOC_ATG_ATGS7_DDR_RADDR3_ADDR(base) ((base) + (0xB1CUL))
#define SOC_ATG_ATGS7_DDR_RADDR4_ADDR(base) ((base) + (0xB20UL))
#define SOC_ATG_ATGS7_DDR_RADDR5_ADDR(base) ((base) + (0xB24UL))
#define SOC_ATG_ATGS7_DDR_RADDR6_ADDR(base) ((base) + (0xB28UL))
#define SOC_ATG_ATGS7_DDR_RADDR7_ADDR(base) ((base) + (0xB2CUL))
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ADDR(base) ((base) + (0xB30UL))
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ADDR(base) ((base) + (0xB34UL))
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_ADDR(base) ((base) + (0xB38UL))
#define SOC_ATG_ATGS7_RDATA00_ADDR(base) ((base) + (0xB40UL))
#define SOC_ATG_ATGS7_RDATA01_ADDR(base) ((base) + (0xB44UL))
#define SOC_ATG_ATGS7_RDATA02_ADDR(base) ((base) + (0xB48UL))
#define SOC_ATG_ATGS7_RDATA03_ADDR(base) ((base) + (0xB4CUL))
#define SOC_ATG_ATGS7_RDATA10_ADDR(base) ((base) + (0xB50UL))
#define SOC_ATG_ATGS7_RDATA11_ADDR(base) ((base) + (0xB54UL))
#define SOC_ATG_ATGS7_RDATA12_ADDR(base) ((base) + (0xB58UL))
#define SOC_ATG_ATGS7_RDATA13_ADDR(base) ((base) + (0xB5CUL))
#define SOC_ATG_ATGS7_RDATA20_ADDR(base) ((base) + (0xB60UL))
#define SOC_ATG_ATGS7_RDATA21_ADDR(base) ((base) + (0xB64UL))
#define SOC_ATG_ATGS7_RDATA22_ADDR(base) ((base) + (0xB68UL))
#define SOC_ATG_ATGS7_RDATA23_ADDR(base) ((base) + (0xB6CUL))
#define SOC_ATG_ATGS7_RDATA30_ADDR(base) ((base) + (0xB70UL))
#define SOC_ATG_ATGS7_RDATA31_ADDR(base) ((base) + (0xB74UL))
#define SOC_ATG_ATGS7_RDATA32_ADDR(base) ((base) + (0xB78UL))
#define SOC_ATG_ATGS7_RDATA33_ADDR(base) ((base) + (0xB7CUL))
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_ADDR(base) ((base) + (0xB80UL))
#define SOC_ATG_ATGS7_ACLK_GT_ADDR(base) ((base) + (0xB84UL))
#define SOC_ATG_ATGM4_MODE_CTRL_ADDR(base) ((base) + (0xC00UL))
#define SOC_ATG_ATGM4_WBURST_MODE_ADDR(base) ((base) + (0xC04UL))
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xC08UL))
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xC0cUL))
#define SOC_ATG_ATGM4_WADDR_NUM_ADDR(base) ((base) + (0xC10UL))
#define SOC_ATG_ATGM4_WBURST_MODE2_ADDR(base) ((base) + (0xC14UL))
#define SOC_ATG_ATGM4_WDATA00_ADDR(base) ((base) + (0xC20UL))
#define SOC_ATG_ATGM4_WDATA01_ADDR(base) ((base) + (0xC24UL))
#define SOC_ATG_ATGM4_WDATA02_ADDR(base) ((base) + (0xC28UL))
#define SOC_ATG_ATGM4_WDATA03_ADDR(base) ((base) + (0xC2CUL))
#define SOC_ATG_ATGM4_WDATA10_ADDR(base) ((base) + (0xC30UL))
#define SOC_ATG_ATGM4_WDATA11_ADDR(base) ((base) + (0xC34UL))
#define SOC_ATG_ATGM4_WDATA12_ADDR(base) ((base) + (0xC38UL))
#define SOC_ATG_ATGM4_WDATA13_ADDR(base) ((base) + (0xC3CUL))
#define SOC_ATG_ATGM4_WDATA20_ADDR(base) ((base) + (0xC40UL))
#define SOC_ATG_ATGM4_WDATA21_ADDR(base) ((base) + (0xC44UL))
#define SOC_ATG_ATGM4_WDATA22_ADDR(base) ((base) + (0xC48UL))
#define SOC_ATG_ATGM4_WDATA23_ADDR(base) ((base) + (0xC4CUL))
#define SOC_ATG_ATGM4_WDATA30_ADDR(base) ((base) + (0xC50UL))
#define SOC_ATG_ATGM4_WDATA31_ADDR(base) ((base) + (0xC54UL))
#define SOC_ATG_ATGM4_WDATA32_ADDR(base) ((base) + (0xC58UL))
#define SOC_ATG_ATGM4_WDATA33_ADDR(base) ((base) + (0xC5CUL))
#define SOC_ATG_ATGM4_RBURST_MODE_ADDR(base) ((base) + (0xC60UL))
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xC64UL))
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xC68UL))
#define SOC_ATG_ATGM4_RADDR_NUM_ADDR(base) ((base) + (0xC6cUL))
#define SOC_ATG_ATGM4_BURST_FINI_STAT_ADDR(base) ((base) + (0xC70UL))
#define SOC_ATG_ATGM4_ACLK_GT_ADDR(base) ((base) + (0xC74UL))
#define SOC_ATG_ATGM4_RBURST_MODE2_ADDR(base) ((base) + (0xC78UL))
#define SOC_ATG_ATGM5_MODE_CTRL_ADDR(base) ((base) + (0xD00UL))
#define SOC_ATG_ATGM5_WBURST_MODE_ADDR(base) ((base) + (0xD04UL))
#define SOC_ATG_ATGM5_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xD08UL))
#define SOC_ATG_ATGM5_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xD0cUL))
#define SOC_ATG_ATGM5_WADDR_NUM_ADDR(base) ((base) + (0xD10UL))
#define SOC_ATG_ATGM5_WBURST_MODE2_ADDR(base) ((base) + (0xD14UL))
#define SOC_ATG_ATGM5_WDATA00_ADDR(base) ((base) + (0xD20UL))
#define SOC_ATG_ATGM5_WDATA01_ADDR(base) ((base) + (0xD24UL))
#define SOC_ATG_ATGM5_WDATA02_ADDR(base) ((base) + (0xD28UL))
#define SOC_ATG_ATGM5_WDATA03_ADDR(base) ((base) + (0xD2CUL))
#define SOC_ATG_ATGM5_WDATA10_ADDR(base) ((base) + (0xD30UL))
#define SOC_ATG_ATGM5_WDATA11_ADDR(base) ((base) + (0xD34UL))
#define SOC_ATG_ATGM5_WDATA12_ADDR(base) ((base) + (0xD38UL))
#define SOC_ATG_ATGM5_WDATA13_ADDR(base) ((base) + (0xD3CUL))
#define SOC_ATG_ATGM5_WDATA20_ADDR(base) ((base) + (0xD40UL))
#define SOC_ATG_ATGM5_WDATA21_ADDR(base) ((base) + (0xD44UL))
#define SOC_ATG_ATGM5_WDATA22_ADDR(base) ((base) + (0xD48UL))
#define SOC_ATG_ATGM5_WDATA23_ADDR(base) ((base) + (0xD4CUL))
#define SOC_ATG_ATGM5_WDATA30_ADDR(base) ((base) + (0xD50UL))
#define SOC_ATG_ATGM5_WDATA31_ADDR(base) ((base) + (0xD54UL))
#define SOC_ATG_ATGM5_WDATA32_ADDR(base) ((base) + (0xD58UL))
#define SOC_ATG_ATGM5_WDATA33_ADDR(base) ((base) + (0xD5CUL))
#define SOC_ATG_ATGM5_RBURST_MODE_ADDR(base) ((base) + (0xD60UL))
#define SOC_ATG_ATGM5_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xD64UL))
#define SOC_ATG_ATGM5_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xD68UL))
#define SOC_ATG_ATGM5_RADDR_NUM_ADDR(base) ((base) + (0xD6cUL))
#define SOC_ATG_ATGM5_BURST_FINI_STAT_ADDR(base) ((base) + (0xD70UL))
#define SOC_ATG_ATGM5_ACLK_GT_ADDR(base) ((base) + (0xD74UL))
#define SOC_ATG_ATGM5_RBURST_MODE2_ADDR(base) ((base) + (0xD78UL))
#define SOC_ATG_ATGM6_MODE_CTRL_ADDR(base) ((base) + (0xE00UL))
#define SOC_ATG_ATGM6_WBURST_MODE_ADDR(base) ((base) + (0xE04UL))
#define SOC_ATG_ATGM6_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xE08UL))
#define SOC_ATG_ATGM6_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xE0cUL))
#define SOC_ATG_ATGM6_WADDR_NUM_ADDR(base) ((base) + (0xE10UL))
#define SOC_ATG_ATGM6_WBURST_MODE2_ADDR(base) ((base) + (0xE14UL))
#define SOC_ATG_ATGM6_WDATA00_ADDR(base) ((base) + (0xE20UL))
#define SOC_ATG_ATGM6_WDATA01_ADDR(base) ((base) + (0xE24UL))
#define SOC_ATG_ATGM6_WDATA02_ADDR(base) ((base) + (0xE28UL))
#define SOC_ATG_ATGM6_WDATA03_ADDR(base) ((base) + (0xE2CUL))
#define SOC_ATG_ATGM6_WDATA10_ADDR(base) ((base) + (0xE30UL))
#define SOC_ATG_ATGM6_WDATA11_ADDR(base) ((base) + (0xE34UL))
#define SOC_ATG_ATGM6_WDATA12_ADDR(base) ((base) + (0xE38UL))
#define SOC_ATG_ATGM6_WDATA13_ADDR(base) ((base) + (0xE3CUL))
#define SOC_ATG_ATGM6_WDATA20_ADDR(base) ((base) + (0xE40UL))
#define SOC_ATG_ATGM6_WDATA21_ADDR(base) ((base) + (0xE44UL))
#define SOC_ATG_ATGM6_WDATA22_ADDR(base) ((base) + (0xE48UL))
#define SOC_ATG_ATGM6_WDATA23_ADDR(base) ((base) + (0xE4CUL))
#define SOC_ATG_ATGM6_WDATA30_ADDR(base) ((base) + (0xE50UL))
#define SOC_ATG_ATGM6_WDATA31_ADDR(base) ((base) + (0xE54UL))
#define SOC_ATG_ATGM6_WDATA32_ADDR(base) ((base) + (0xE58UL))
#define SOC_ATG_ATGM6_WDATA33_ADDR(base) ((base) + (0xE5CUL))
#define SOC_ATG_ATGM6_RBURST_MODE_ADDR(base) ((base) + (0xE60UL))
#define SOC_ATG_ATGM6_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xE64UL))
#define SOC_ATG_ATGM6_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xE68UL))
#define SOC_ATG_ATGM6_RADDR_NUM_ADDR(base) ((base) + (0xE6cUL))
#define SOC_ATG_ATGM6_BURST_FINI_STAT_ADDR(base) ((base) + (0xE70UL))
#define SOC_ATG_ATGM6_ACLK_GT_ADDR(base) ((base) + (0xE74UL))
#define SOC_ATG_ATGM6_RBURST_MODE2_ADDR(base) ((base) + (0xE78UL))
#define SOC_ATG_ATGM7_MODE_CTRL_ADDR(base) ((base) + (0xF00UL))
#define SOC_ATG_ATGM7_WBURST_MODE_ADDR(base) ((base) + (0xF04UL))
#define SOC_ATG_ATGM7_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xF08UL))
#define SOC_ATG_ATGM7_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xF0cUL))
#define SOC_ATG_ATGM7_WADDR_NUM_ADDR(base) ((base) + (0xF10UL))
#define SOC_ATG_ATGM7_WBURST_MODE2_ADDR(base) ((base) + (0xF14UL))
#define SOC_ATG_ATGM7_WDATA00_ADDR(base) ((base) + (0xF20UL))
#define SOC_ATG_ATGM7_WDATA01_ADDR(base) ((base) + (0xF24UL))
#define SOC_ATG_ATGM7_WDATA02_ADDR(base) ((base) + (0xF28UL))
#define SOC_ATG_ATGM7_WDATA03_ADDR(base) ((base) + (0xF2CUL))
#define SOC_ATG_ATGM7_WDATA10_ADDR(base) ((base) + (0xF30UL))
#define SOC_ATG_ATGM7_WDATA11_ADDR(base) ((base) + (0xF34UL))
#define SOC_ATG_ATGM7_WDATA12_ADDR(base) ((base) + (0xF38UL))
#define SOC_ATG_ATGM7_WDATA13_ADDR(base) ((base) + (0xF3CUL))
#define SOC_ATG_ATGM7_WDATA20_ADDR(base) ((base) + (0xF40UL))
#define SOC_ATG_ATGM7_WDATA21_ADDR(base) ((base) + (0xF44UL))
#define SOC_ATG_ATGM7_WDATA22_ADDR(base) ((base) + (0xF48UL))
#define SOC_ATG_ATGM7_WDATA23_ADDR(base) ((base) + (0xF4CUL))
#define SOC_ATG_ATGM7_WDATA30_ADDR(base) ((base) + (0xF50UL))
#define SOC_ATG_ATGM7_WDATA31_ADDR(base) ((base) + (0xF54UL))
#define SOC_ATG_ATGM7_WDATA32_ADDR(base) ((base) + (0xF58UL))
#define SOC_ATG_ATGM7_WDATA33_ADDR(base) ((base) + (0xF5CUL))
#define SOC_ATG_ATGM7_RBURST_MODE_ADDR(base) ((base) + (0xF60UL))
#define SOC_ATG_ATGM7_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xF64UL))
#define SOC_ATG_ATGM7_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xF68UL))
#define SOC_ATG_ATGM7_RADDR_NUM_ADDR(base) ((base) + (0xF6cUL))
#define SOC_ATG_ATGM7_BURST_FINI_STAT_ADDR(base) ((base) + (0xF70UL))
#define SOC_ATG_ATGM7_ACLK_GT_ADDR(base) ((base) + (0xF74UL))
#define SOC_ATG_ATGM7_RBURST_MODE2_ADDR(base) ((base) + (0xF78UL))
#else
#define SOC_ATG_ATGM0_MODE_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_ATG_ATGM0_WBURST_MODE_ADDR(base) ((base) + (0x004))
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x008))
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x00c))
#define SOC_ATG_ATGM0_WADDR_NUM_ADDR(base) ((base) + (0x010))
#define SOC_ATG_ATGM0_WBURST_MODE2_ADDR(base) ((base) + (0x014))
#define SOC_ATG_ATGM0_WDATA00_ADDR(base) ((base) + (0x020))
#define SOC_ATG_ATGM0_WDATA01_ADDR(base) ((base) + (0x024))
#define SOC_ATG_ATGM0_WDATA02_ADDR(base) ((base) + (0x028))
#define SOC_ATG_ATGM0_WDATA03_ADDR(base) ((base) + (0x02C))
#define SOC_ATG_ATGM0_WDATA10_ADDR(base) ((base) + (0x030))
#define SOC_ATG_ATGM0_WDATA11_ADDR(base) ((base) + (0x034))
#define SOC_ATG_ATGM0_WDATA12_ADDR(base) ((base) + (0x038))
#define SOC_ATG_ATGM0_WDATA13_ADDR(base) ((base) + (0x03C))
#define SOC_ATG_ATGM0_WDATA20_ADDR(base) ((base) + (0x040))
#define SOC_ATG_ATGM0_WDATA21_ADDR(base) ((base) + (0x044))
#define SOC_ATG_ATGM0_WDATA22_ADDR(base) ((base) + (0x048))
#define SOC_ATG_ATGM0_WDATA23_ADDR(base) ((base) + (0x04C))
#define SOC_ATG_ATGM0_WDATA30_ADDR(base) ((base) + (0x050))
#define SOC_ATG_ATGM0_WDATA31_ADDR(base) ((base) + (0x054))
#define SOC_ATG_ATGM0_WDATA32_ADDR(base) ((base) + (0x058))
#define SOC_ATG_ATGM0_WDATA33_ADDR(base) ((base) + (0x05C))
#define SOC_ATG_ATGM0_RBURST_MODE_ADDR(base) ((base) + (0x060))
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x064))
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x068))
#define SOC_ATG_ATGM0_RADDR_NUM_ADDR(base) ((base) + (0x06c))
#define SOC_ATG_ATGM0_BURST_FINI_STAT_ADDR(base) ((base) + (0x070))
#define SOC_ATG_ATGM0_ACLK_GT_ADDR(base) ((base) + (0x074))
#define SOC_ATG_ATGM0_RBURST_MODE2_ADDR(base) ((base) + (0x078))
#define SOC_ATG_ATGM1_MODE_CTRL_ADDR(base) ((base) + (0x100))
#define SOC_ATG_ATGM1_WBURST_MODE_ADDR(base) ((base) + (0x104))
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x108))
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x10c))
#define SOC_ATG_ATGM1_WADDR_NUM_ADDR(base) ((base) + (0x110))
#define SOC_ATG_ATGM1_WBURST_MODE2_ADDR(base) ((base) + (0x114))
#define SOC_ATG_ATGM1_WDATA00_ADDR(base) ((base) + (0x120))
#define SOC_ATG_ATGM1_WDATA01_ADDR(base) ((base) + (0x124))
#define SOC_ATG_ATGM1_WDATA02_ADDR(base) ((base) + (0x128))
#define SOC_ATG_ATGM1_WDATA03_ADDR(base) ((base) + (0x12C))
#define SOC_ATG_ATGM1_WDATA10_ADDR(base) ((base) + (0x130))
#define SOC_ATG_ATGM1_WDATA11_ADDR(base) ((base) + (0x134))
#define SOC_ATG_ATGM1_WDATA12_ADDR(base) ((base) + (0x138))
#define SOC_ATG_ATGM1_WDATA13_ADDR(base) ((base) + (0x13C))
#define SOC_ATG_ATGM1_WDATA20_ADDR(base) ((base) + (0x140))
#define SOC_ATG_ATGM1_WDATA21_ADDR(base) ((base) + (0x144))
#define SOC_ATG_ATGM1_WDATA22_ADDR(base) ((base) + (0x148))
#define SOC_ATG_ATGM1_WDATA23_ADDR(base) ((base) + (0x14C))
#define SOC_ATG_ATGM1_WDATA30_ADDR(base) ((base) + (0x150))
#define SOC_ATG_ATGM1_WDATA31_ADDR(base) ((base) + (0x154))
#define SOC_ATG_ATGM1_WDATA32_ADDR(base) ((base) + (0x158))
#define SOC_ATG_ATGM1_WDATA33_ADDR(base) ((base) + (0x15C))
#define SOC_ATG_ATGM1_RBURST_MODE_ADDR(base) ((base) + (0x160))
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x164))
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x168))
#define SOC_ATG_ATGM1_RADDR_NUM_ADDR(base) ((base) + (0x16c))
#define SOC_ATG_ATGM1_BURST_FINI_STAT_ADDR(base) ((base) + (0x170))
#define SOC_ATG_ATGM1_ACLK_GT_ADDR(base) ((base) + (0x174))
#define SOC_ATG_ATGM1_RBURST_MODE2_ADDR(base) ((base) + (0x178))
#define SOC_ATG_ATGM2_MODE_CTRL_ADDR(base) ((base) + (0x200))
#define SOC_ATG_ATGM2_WBURST_MODE_ADDR(base) ((base) + (0x204))
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_ADDR(base) ((base) + (0x208))
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0x20c))
#define SOC_ATG_ATGM2_WADDR_NUM_ADDR(base) ((base) + (0x210))
#define SOC_ATG_ATGM2_WBURST_MODE2_ADDR(base) ((base) + (0x214))
#define SOC_ATG_ATGM2_WDATA00_ADDR(base) ((base) + (0x220))
#define SOC_ATG_ATGM2_WDATA01_ADDR(base) ((base) + (0x224))
#define SOC_ATG_ATGM2_WDATA02_ADDR(base) ((base) + (0x228))
#define SOC_ATG_ATGM2_WDATA03_ADDR(base) ((base) + (0x22C))
#define SOC_ATG_ATGM2_WDATA10_ADDR(base) ((base) + (0x230))
#define SOC_ATG_ATGM2_WDATA11_ADDR(base) ((base) + (0x234))
#define SOC_ATG_ATGM2_WDATA12_ADDR(base) ((base) + (0x238))
#define SOC_ATG_ATGM2_WDATA13_ADDR(base) ((base) + (0x23C))
#define SOC_ATG_ATGM2_WDATA20_ADDR(base) ((base) + (0x240))
#define SOC_ATG_ATGM2_WDATA21_ADDR(base) ((base) + (0x244))
#define SOC_ATG_ATGM2_WDATA22_ADDR(base) ((base) + (0x248))
#define SOC_ATG_ATGM2_WDATA23_ADDR(base) ((base) + (0x24C))
#define SOC_ATG_ATGM2_WDATA30_ADDR(base) ((base) + (0x250))
#define SOC_ATG_ATGM2_WDATA31_ADDR(base) ((base) + (0x254))
#define SOC_ATG_ATGM2_WDATA32_ADDR(base) ((base) + (0x258))
#define SOC_ATG_ATGM2_WDATA33_ADDR(base) ((base) + (0x25C))
#define SOC_ATG_ATGM2_RBURST_MODE_ADDR(base) ((base) + (0x260))
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_ADDR(base) ((base) + (0x264))
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0x268))
#define SOC_ATG_ATGM2_RADDR_NUM_ADDR(base) ((base) + (0x26c))
#define SOC_ATG_ATGM2_BURST_FINI_STAT_ADDR(base) ((base) + (0x270))
#define SOC_ATG_ATGM2_ACLK_GT_ADDR(base) ((base) + (0x274))
#define SOC_ATG_ATGM2_RBURST_MODE2_ADDR(base) ((base) + (0x278))
#define SOC_ATG_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x400))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x404))
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x408))
#define SOC_ATG_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x40C))
#define SOC_ATG_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x410))
#define SOC_ATG_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x414))
#define SOC_ATG_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x418))
#define SOC_ATG_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x41C))
#define SOC_ATG_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x420))
#define SOC_ATG_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x424))
#define SOC_ATG_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x428))
#define SOC_ATG_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x42C))
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x430))
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x434))
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x438))
#define SOC_ATG_ATGS1_RDATA00_ADDR(base) ((base) + (0x440))
#define SOC_ATG_ATGS1_RDATA01_ADDR(base) ((base) + (0x444))
#define SOC_ATG_ATGS1_RDATA02_ADDR(base) ((base) + (0x448))
#define SOC_ATG_ATGS1_RDATA03_ADDR(base) ((base) + (0x44C))
#define SOC_ATG_ATGS1_RDATA10_ADDR(base) ((base) + (0x450))
#define SOC_ATG_ATGS1_RDATA11_ADDR(base) ((base) + (0x454))
#define SOC_ATG_ATGS1_RDATA12_ADDR(base) ((base) + (0x458))
#define SOC_ATG_ATGS1_RDATA13_ADDR(base) ((base) + (0x45C))
#define SOC_ATG_ATGS1_RDATA20_ADDR(base) ((base) + (0x460))
#define SOC_ATG_ATGS1_RDATA21_ADDR(base) ((base) + (0x464))
#define SOC_ATG_ATGS1_RDATA22_ADDR(base) ((base) + (0x468))
#define SOC_ATG_ATGS1_RDATA23_ADDR(base) ((base) + (0x46C))
#define SOC_ATG_ATGS1_RDATA30_ADDR(base) ((base) + (0x470))
#define SOC_ATG_ATGS1_RDATA31_ADDR(base) ((base) + (0x474))
#define SOC_ATG_ATGS1_RDATA32_ADDR(base) ((base) + (0x478))
#define SOC_ATG_ATGS1_RDATA33_ADDR(base) ((base) + (0x47C))
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x480))
#define SOC_ATG_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x484))
#define SOC_ATG_ATGS2_MODE_CTRL_ADDR(base) ((base) + (0x500))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_ADDR(base) ((base) + (0x504))
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x508))
#define SOC_ATG_ATGS2_AXI_BUS_STAT_ADDR(base) ((base) + (0x50C))
#define SOC_ATG_ATGS2_DDR_RADDR0_ADDR(base) ((base) + (0x510))
#define SOC_ATG_ATGS2_DDR_RADDR1_ADDR(base) ((base) + (0x514))
#define SOC_ATG_ATGS2_DDR_RADDR2_ADDR(base) ((base) + (0x518))
#define SOC_ATG_ATGS2_DDR_RADDR3_ADDR(base) ((base) + (0x51C))
#define SOC_ATG_ATGS2_DDR_RADDR4_ADDR(base) ((base) + (0x520))
#define SOC_ATG_ATGS2_DDR_RADDR5_ADDR(base) ((base) + (0x524))
#define SOC_ATG_ATGS2_DDR_RADDR6_ADDR(base) ((base) + (0x528))
#define SOC_ATG_ATGS2_DDR_RADDR7_ADDR(base) ((base) + (0x52C))
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ADDR(base) ((base) + (0x530))
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ADDR(base) ((base) + (0x534))
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_ADDR(base) ((base) + (0x538))
#define SOC_ATG_ATGS2_RDATA00_ADDR(base) ((base) + (0x540))
#define SOC_ATG_ATGS2_RDATA01_ADDR(base) ((base) + (0x544))
#define SOC_ATG_ATGS2_RDATA02_ADDR(base) ((base) + (0x548))
#define SOC_ATG_ATGS2_RDATA03_ADDR(base) ((base) + (0x54C))
#define SOC_ATG_ATGS2_RDATA10_ADDR(base) ((base) + (0x550))
#define SOC_ATG_ATGS2_RDATA11_ADDR(base) ((base) + (0x554))
#define SOC_ATG_ATGS2_RDATA12_ADDR(base) ((base) + (0x558))
#define SOC_ATG_ATGS2_RDATA13_ADDR(base) ((base) + (0x55C))
#define SOC_ATG_ATGS2_RDATA20_ADDR(base) ((base) + (0x560))
#define SOC_ATG_ATGS2_RDATA21_ADDR(base) ((base) + (0x564))
#define SOC_ATG_ATGS2_RDATA22_ADDR(base) ((base) + (0x568))
#define SOC_ATG_ATGS2_RDATA23_ADDR(base) ((base) + (0x56C))
#define SOC_ATG_ATGS2_RDATA30_ADDR(base) ((base) + (0x570))
#define SOC_ATG_ATGS2_RDATA31_ADDR(base) ((base) + (0x574))
#define SOC_ATG_ATGS2_RDATA32_ADDR(base) ((base) + (0x578))
#define SOC_ATG_ATGS2_RDATA33_ADDR(base) ((base) + (0x57C))
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x580))
#define SOC_ATG_ATGS2_ACLK_GT_ADDR(base) ((base) + (0x584))
#define SOC_ATG_ATGS3_MODE_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_ADDR(base) ((base) + (0x604))
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x608))
#define SOC_ATG_ATGS3_AXI_BUS_STAT_ADDR(base) ((base) + (0x60C))
#define SOC_ATG_ATGS3_DDR_RADDR0_ADDR(base) ((base) + (0x610))
#define SOC_ATG_ATGS3_DDR_RADDR1_ADDR(base) ((base) + (0x614))
#define SOC_ATG_ATGS3_DDR_RADDR2_ADDR(base) ((base) + (0x618))
#define SOC_ATG_ATGS3_DDR_RADDR3_ADDR(base) ((base) + (0x61C))
#define SOC_ATG_ATGS3_DDR_RADDR4_ADDR(base) ((base) + (0x620))
#define SOC_ATG_ATGS3_DDR_RADDR5_ADDR(base) ((base) + (0x624))
#define SOC_ATG_ATGS3_DDR_RADDR6_ADDR(base) ((base) + (0x628))
#define SOC_ATG_ATGS3_DDR_RADDR7_ADDR(base) ((base) + (0x62C))
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ADDR(base) ((base) + (0x630))
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ADDR(base) ((base) + (0x634))
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_ADDR(base) ((base) + (0x638))
#define SOC_ATG_ATGS3_RDATA00_ADDR(base) ((base) + (0x640))
#define SOC_ATG_ATGS3_RDATA01_ADDR(base) ((base) + (0x644))
#define SOC_ATG_ATGS3_RDATA02_ADDR(base) ((base) + (0x648))
#define SOC_ATG_ATGS3_RDATA03_ADDR(base) ((base) + (0x64C))
#define SOC_ATG_ATGS3_RDATA10_ADDR(base) ((base) + (0x650))
#define SOC_ATG_ATGS3_RDATA11_ADDR(base) ((base) + (0x654))
#define SOC_ATG_ATGS3_RDATA12_ADDR(base) ((base) + (0x658))
#define SOC_ATG_ATGS3_RDATA13_ADDR(base) ((base) + (0x65C))
#define SOC_ATG_ATGS3_RDATA20_ADDR(base) ((base) + (0x660))
#define SOC_ATG_ATGS3_RDATA21_ADDR(base) ((base) + (0x664))
#define SOC_ATG_ATGS3_RDATA22_ADDR(base) ((base) + (0x668))
#define SOC_ATG_ATGS3_RDATA23_ADDR(base) ((base) + (0x66C))
#define SOC_ATG_ATGS3_RDATA30_ADDR(base) ((base) + (0x670))
#define SOC_ATG_ATGS3_RDATA31_ADDR(base) ((base) + (0x674))
#define SOC_ATG_ATGS3_RDATA32_ADDR(base) ((base) + (0x678))
#define SOC_ATG_ATGS3_RDATA33_ADDR(base) ((base) + (0x67C))
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x680))
#define SOC_ATG_ATGS3_ACLK_GT_ADDR(base) ((base) + (0x684))
#define SOC_ATG_ATGS4_MODE_CTRL_ADDR(base) ((base) + (0x700))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_ADDR(base) ((base) + (0x704))
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x708))
#define SOC_ATG_ATGS4_AXI_BUS_STAT_ADDR(base) ((base) + (0x70C))
#define SOC_ATG_ATGS4_DDR_RADDR0_ADDR(base) ((base) + (0x710))
#define SOC_ATG_ATGS4_DDR_RADDR1_ADDR(base) ((base) + (0x714))
#define SOC_ATG_ATGS4_DDR_RADDR2_ADDR(base) ((base) + (0x718))
#define SOC_ATG_ATGS4_DDR_RADDR3_ADDR(base) ((base) + (0x71C))
#define SOC_ATG_ATGS4_DDR_RADDR4_ADDR(base) ((base) + (0x720))
#define SOC_ATG_ATGS4_DDR_RADDR5_ADDR(base) ((base) + (0x724))
#define SOC_ATG_ATGS4_DDR_RADDR6_ADDR(base) ((base) + (0x728))
#define SOC_ATG_ATGS4_DDR_RADDR7_ADDR(base) ((base) + (0x72C))
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ADDR(base) ((base) + (0x730))
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ADDR(base) ((base) + (0x734))
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_ADDR(base) ((base) + (0x738))
#define SOC_ATG_ATGS4_RDATA00_ADDR(base) ((base) + (0x740))
#define SOC_ATG_ATGS4_RDATA01_ADDR(base) ((base) + (0x744))
#define SOC_ATG_ATGS4_RDATA02_ADDR(base) ((base) + (0x748))
#define SOC_ATG_ATGS4_RDATA03_ADDR(base) ((base) + (0x74C))
#define SOC_ATG_ATGS4_RDATA10_ADDR(base) ((base) + (0x750))
#define SOC_ATG_ATGS4_RDATA11_ADDR(base) ((base) + (0x754))
#define SOC_ATG_ATGS4_RDATA12_ADDR(base) ((base) + (0x758))
#define SOC_ATG_ATGS4_RDATA13_ADDR(base) ((base) + (0x75C))
#define SOC_ATG_ATGS4_RDATA20_ADDR(base) ((base) + (0x760))
#define SOC_ATG_ATGS4_RDATA21_ADDR(base) ((base) + (0x764))
#define SOC_ATG_ATGS4_RDATA22_ADDR(base) ((base) + (0x768))
#define SOC_ATG_ATGS4_RDATA23_ADDR(base) ((base) + (0x76C))
#define SOC_ATG_ATGS4_RDATA30_ADDR(base) ((base) + (0x770))
#define SOC_ATG_ATGS4_RDATA31_ADDR(base) ((base) + (0x774))
#define SOC_ATG_ATGS4_RDATA32_ADDR(base) ((base) + (0x778))
#define SOC_ATG_ATGS4_RDATA33_ADDR(base) ((base) + (0x77C))
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x780))
#define SOC_ATG_ATGS4_ACLK_GT_ADDR(base) ((base) + (0x784))
#define SOC_ATG_ATGS5_MODE_CTRL_ADDR(base) ((base) + (0x800))
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_ADDR(base) ((base) + (0x804))
#define SOC_ATG_ATGS5_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x808))
#define SOC_ATG_ATGS5_AXI_BUS_STAT_ADDR(base) ((base) + (0x80C))
#define SOC_ATG_ATGS5_DDR_RADDR0_ADDR(base) ((base) + (0x810))
#define SOC_ATG_ATGS5_DDR_RADDR1_ADDR(base) ((base) + (0x814))
#define SOC_ATG_ATGS5_DDR_RADDR2_ADDR(base) ((base) + (0x818))
#define SOC_ATG_ATGS5_DDR_RADDR3_ADDR(base) ((base) + (0x81C))
#define SOC_ATG_ATGS5_DDR_RADDR4_ADDR(base) ((base) + (0x820))
#define SOC_ATG_ATGS5_DDR_RADDR5_ADDR(base) ((base) + (0x824))
#define SOC_ATG_ATGS5_DDR_RADDR6_ADDR(base) ((base) + (0x828))
#define SOC_ATG_ATGS5_DDR_RADDR7_ADDR(base) ((base) + (0x82C))
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ADDR(base) ((base) + (0x830))
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ADDR(base) ((base) + (0x834))
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_ADDR(base) ((base) + (0x838))
#define SOC_ATG_ATGS5_RDATA00_ADDR(base) ((base) + (0x840))
#define SOC_ATG_ATGS5_RDATA01_ADDR(base) ((base) + (0x844))
#define SOC_ATG_ATGS5_RDATA02_ADDR(base) ((base) + (0x848))
#define SOC_ATG_ATGS5_RDATA03_ADDR(base) ((base) + (0x84C))
#define SOC_ATG_ATGS5_RDATA10_ADDR(base) ((base) + (0x850))
#define SOC_ATG_ATGS5_RDATA11_ADDR(base) ((base) + (0x854))
#define SOC_ATG_ATGS5_RDATA12_ADDR(base) ((base) + (0x858))
#define SOC_ATG_ATGS5_RDATA13_ADDR(base) ((base) + (0x85C))
#define SOC_ATG_ATGS5_RDATA20_ADDR(base) ((base) + (0x860))
#define SOC_ATG_ATGS5_RDATA21_ADDR(base) ((base) + (0x864))
#define SOC_ATG_ATGS5_RDATA22_ADDR(base) ((base) + (0x868))
#define SOC_ATG_ATGS5_RDATA23_ADDR(base) ((base) + (0x86C))
#define SOC_ATG_ATGS5_RDATA30_ADDR(base) ((base) + (0x870))
#define SOC_ATG_ATGS5_RDATA31_ADDR(base) ((base) + (0x874))
#define SOC_ATG_ATGS5_RDATA32_ADDR(base) ((base) + (0x878))
#define SOC_ATG_ATGS5_RDATA33_ADDR(base) ((base) + (0x87C))
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x880))
#define SOC_ATG_ATGS5_ACLK_GT_ADDR(base) ((base) + (0x884))
#define SOC_ATG_ATGS6_MODE_CTRL_ADDR(base) ((base) + (0x900))
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_ADDR(base) ((base) + (0x904))
#define SOC_ATG_ATGS6_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x908))
#define SOC_ATG_ATGS6_AXI_BUS_STAT_ADDR(base) ((base) + (0x90C))
#define SOC_ATG_ATGS6_DDR_RADDR0_ADDR(base) ((base) + (0x910))
#define SOC_ATG_ATGS6_DDR_RADDR1_ADDR(base) ((base) + (0x914))
#define SOC_ATG_ATGS6_DDR_RADDR2_ADDR(base) ((base) + (0x918))
#define SOC_ATG_ATGS6_DDR_RADDR3_ADDR(base) ((base) + (0x91C))
#define SOC_ATG_ATGS6_DDR_RADDR4_ADDR(base) ((base) + (0x920))
#define SOC_ATG_ATGS6_DDR_RADDR5_ADDR(base) ((base) + (0x924))
#define SOC_ATG_ATGS6_DDR_RADDR6_ADDR(base) ((base) + (0x928))
#define SOC_ATG_ATGS6_DDR_RADDR7_ADDR(base) ((base) + (0x92C))
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ADDR(base) ((base) + (0x930))
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ADDR(base) ((base) + (0x934))
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_ADDR(base) ((base) + (0x938))
#define SOC_ATG_ATGS6_RDATA00_ADDR(base) ((base) + (0x940))
#define SOC_ATG_ATGS6_RDATA01_ADDR(base) ((base) + (0x944))
#define SOC_ATG_ATGS6_RDATA02_ADDR(base) ((base) + (0x948))
#define SOC_ATG_ATGS6_RDATA03_ADDR(base) ((base) + (0x94C))
#define SOC_ATG_ATGS6_RDATA10_ADDR(base) ((base) + (0x950))
#define SOC_ATG_ATGS6_RDATA11_ADDR(base) ((base) + (0x954))
#define SOC_ATG_ATGS6_RDATA12_ADDR(base) ((base) + (0x958))
#define SOC_ATG_ATGS6_RDATA13_ADDR(base) ((base) + (0x95C))
#define SOC_ATG_ATGS6_RDATA20_ADDR(base) ((base) + (0x960))
#define SOC_ATG_ATGS6_RDATA21_ADDR(base) ((base) + (0x964))
#define SOC_ATG_ATGS6_RDATA22_ADDR(base) ((base) + (0x968))
#define SOC_ATG_ATGS6_RDATA23_ADDR(base) ((base) + (0x96C))
#define SOC_ATG_ATGS6_RDATA30_ADDR(base) ((base) + (0x970))
#define SOC_ATG_ATGS6_RDATA31_ADDR(base) ((base) + (0x974))
#define SOC_ATG_ATGS6_RDATA32_ADDR(base) ((base) + (0x978))
#define SOC_ATG_ATGS6_RDATA33_ADDR(base) ((base) + (0x97C))
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x980))
#define SOC_ATG_ATGS6_ACLK_GT_ADDR(base) ((base) + (0x984))
#define SOC_ATG_ATGM3_MODE_CTRL_ADDR(base) ((base) + (0xA00))
#define SOC_ATG_ATGM3_WBURST_MODE_ADDR(base) ((base) + (0xA04))
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xA08))
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xA0c))
#define SOC_ATG_ATGM3_WADDR_NUM_ADDR(base) ((base) + (0xA10))
#define SOC_ATG_ATGM3_WBURST_MODE2_ADDR(base) ((base) + (0xA14))
#define SOC_ATG_ATGM3_WDATA00_ADDR(base) ((base) + (0xA20))
#define SOC_ATG_ATGM3_WDATA01_ADDR(base) ((base) + (0xA24))
#define SOC_ATG_ATGM3_WDATA02_ADDR(base) ((base) + (0xA28))
#define SOC_ATG_ATGM3_WDATA03_ADDR(base) ((base) + (0xA2C))
#define SOC_ATG_ATGM3_WDATA10_ADDR(base) ((base) + (0xA30))
#define SOC_ATG_ATGM3_WDATA11_ADDR(base) ((base) + (0xA34))
#define SOC_ATG_ATGM3_WDATA12_ADDR(base) ((base) + (0xA38))
#define SOC_ATG_ATGM3_WDATA13_ADDR(base) ((base) + (0xA3C))
#define SOC_ATG_ATGM3_WDATA20_ADDR(base) ((base) + (0xA40))
#define SOC_ATG_ATGM3_WDATA21_ADDR(base) ((base) + (0xA44))
#define SOC_ATG_ATGM3_WDATA22_ADDR(base) ((base) + (0xA48))
#define SOC_ATG_ATGM3_WDATA23_ADDR(base) ((base) + (0xA4C))
#define SOC_ATG_ATGM3_WDATA30_ADDR(base) ((base) + (0xA50))
#define SOC_ATG_ATGM3_WDATA31_ADDR(base) ((base) + (0xA54))
#define SOC_ATG_ATGM3_WDATA32_ADDR(base) ((base) + (0xA58))
#define SOC_ATG_ATGM3_WDATA33_ADDR(base) ((base) + (0xA5C))
#define SOC_ATG_ATGM3_RBURST_MODE_ADDR(base) ((base) + (0xA60))
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xA64))
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xA68))
#define SOC_ATG_ATGM3_RADDR_NUM_ADDR(base) ((base) + (0xA6c))
#define SOC_ATG_ATGM3_BURST_FINI_STAT_ADDR(base) ((base) + (0xA70))
#define SOC_ATG_ATGM3_ACLK_GT_ADDR(base) ((base) + (0xA74))
#define SOC_ATG_ATGM3_RBURST_MODE2_ADDR(base) ((base) + (0xA78))
#define SOC_ATG_ATGS7_MODE_CTRL_ADDR(base) ((base) + (0xB00))
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_ADDR(base) ((base) + (0xB04))
#define SOC_ATG_ATGS7_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0xB08))
#define SOC_ATG_ATGS7_AXI_BUS_STAT_ADDR(base) ((base) + (0xB0C))
#define SOC_ATG_ATGS7_DDR_RADDR0_ADDR(base) ((base) + (0xB10))
#define SOC_ATG_ATGS7_DDR_RADDR1_ADDR(base) ((base) + (0xB14))
#define SOC_ATG_ATGS7_DDR_RADDR2_ADDR(base) ((base) + (0xB18))
#define SOC_ATG_ATGS7_DDR_RADDR3_ADDR(base) ((base) + (0xB1C))
#define SOC_ATG_ATGS7_DDR_RADDR4_ADDR(base) ((base) + (0xB20))
#define SOC_ATG_ATGS7_DDR_RADDR5_ADDR(base) ((base) + (0xB24))
#define SOC_ATG_ATGS7_DDR_RADDR6_ADDR(base) ((base) + (0xB28))
#define SOC_ATG_ATGS7_DDR_RADDR7_ADDR(base) ((base) + (0xB2C))
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ADDR(base) ((base) + (0xB30))
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ADDR(base) ((base) + (0xB34))
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_ADDR(base) ((base) + (0xB38))
#define SOC_ATG_ATGS7_RDATA00_ADDR(base) ((base) + (0xB40))
#define SOC_ATG_ATGS7_RDATA01_ADDR(base) ((base) + (0xB44))
#define SOC_ATG_ATGS7_RDATA02_ADDR(base) ((base) + (0xB48))
#define SOC_ATG_ATGS7_RDATA03_ADDR(base) ((base) + (0xB4C))
#define SOC_ATG_ATGS7_RDATA10_ADDR(base) ((base) + (0xB50))
#define SOC_ATG_ATGS7_RDATA11_ADDR(base) ((base) + (0xB54))
#define SOC_ATG_ATGS7_RDATA12_ADDR(base) ((base) + (0xB58))
#define SOC_ATG_ATGS7_RDATA13_ADDR(base) ((base) + (0xB5C))
#define SOC_ATG_ATGS7_RDATA20_ADDR(base) ((base) + (0xB60))
#define SOC_ATG_ATGS7_RDATA21_ADDR(base) ((base) + (0xB64))
#define SOC_ATG_ATGS7_RDATA22_ADDR(base) ((base) + (0xB68))
#define SOC_ATG_ATGS7_RDATA23_ADDR(base) ((base) + (0xB6C))
#define SOC_ATG_ATGS7_RDATA30_ADDR(base) ((base) + (0xB70))
#define SOC_ATG_ATGS7_RDATA31_ADDR(base) ((base) + (0xB74))
#define SOC_ATG_ATGS7_RDATA32_ADDR(base) ((base) + (0xB78))
#define SOC_ATG_ATGS7_RDATA33_ADDR(base) ((base) + (0xB7C))
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_ADDR(base) ((base) + (0xB80))
#define SOC_ATG_ATGS7_ACLK_GT_ADDR(base) ((base) + (0xB84))
#define SOC_ATG_ATGM4_MODE_CTRL_ADDR(base) ((base) + (0xC00))
#define SOC_ATG_ATGM4_WBURST_MODE_ADDR(base) ((base) + (0xC04))
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xC08))
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xC0c))
#define SOC_ATG_ATGM4_WADDR_NUM_ADDR(base) ((base) + (0xC10))
#define SOC_ATG_ATGM4_WBURST_MODE2_ADDR(base) ((base) + (0xC14))
#define SOC_ATG_ATGM4_WDATA00_ADDR(base) ((base) + (0xC20))
#define SOC_ATG_ATGM4_WDATA01_ADDR(base) ((base) + (0xC24))
#define SOC_ATG_ATGM4_WDATA02_ADDR(base) ((base) + (0xC28))
#define SOC_ATG_ATGM4_WDATA03_ADDR(base) ((base) + (0xC2C))
#define SOC_ATG_ATGM4_WDATA10_ADDR(base) ((base) + (0xC30))
#define SOC_ATG_ATGM4_WDATA11_ADDR(base) ((base) + (0xC34))
#define SOC_ATG_ATGM4_WDATA12_ADDR(base) ((base) + (0xC38))
#define SOC_ATG_ATGM4_WDATA13_ADDR(base) ((base) + (0xC3C))
#define SOC_ATG_ATGM4_WDATA20_ADDR(base) ((base) + (0xC40))
#define SOC_ATG_ATGM4_WDATA21_ADDR(base) ((base) + (0xC44))
#define SOC_ATG_ATGM4_WDATA22_ADDR(base) ((base) + (0xC48))
#define SOC_ATG_ATGM4_WDATA23_ADDR(base) ((base) + (0xC4C))
#define SOC_ATG_ATGM4_WDATA30_ADDR(base) ((base) + (0xC50))
#define SOC_ATG_ATGM4_WDATA31_ADDR(base) ((base) + (0xC54))
#define SOC_ATG_ATGM4_WDATA32_ADDR(base) ((base) + (0xC58))
#define SOC_ATG_ATGM4_WDATA33_ADDR(base) ((base) + (0xC5C))
#define SOC_ATG_ATGM4_RBURST_MODE_ADDR(base) ((base) + (0xC60))
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xC64))
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xC68))
#define SOC_ATG_ATGM4_RADDR_NUM_ADDR(base) ((base) + (0xC6c))
#define SOC_ATG_ATGM4_BURST_FINI_STAT_ADDR(base) ((base) + (0xC70))
#define SOC_ATG_ATGM4_ACLK_GT_ADDR(base) ((base) + (0xC74))
#define SOC_ATG_ATGM4_RBURST_MODE2_ADDR(base) ((base) + (0xC78))
#define SOC_ATG_ATGM5_MODE_CTRL_ADDR(base) ((base) + (0xD00))
#define SOC_ATG_ATGM5_WBURST_MODE_ADDR(base) ((base) + (0xD04))
#define SOC_ATG_ATGM5_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xD08))
#define SOC_ATG_ATGM5_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xD0c))
#define SOC_ATG_ATGM5_WADDR_NUM_ADDR(base) ((base) + (0xD10))
#define SOC_ATG_ATGM5_WBURST_MODE2_ADDR(base) ((base) + (0xD14))
#define SOC_ATG_ATGM5_WDATA00_ADDR(base) ((base) + (0xD20))
#define SOC_ATG_ATGM5_WDATA01_ADDR(base) ((base) + (0xD24))
#define SOC_ATG_ATGM5_WDATA02_ADDR(base) ((base) + (0xD28))
#define SOC_ATG_ATGM5_WDATA03_ADDR(base) ((base) + (0xD2C))
#define SOC_ATG_ATGM5_WDATA10_ADDR(base) ((base) + (0xD30))
#define SOC_ATG_ATGM5_WDATA11_ADDR(base) ((base) + (0xD34))
#define SOC_ATG_ATGM5_WDATA12_ADDR(base) ((base) + (0xD38))
#define SOC_ATG_ATGM5_WDATA13_ADDR(base) ((base) + (0xD3C))
#define SOC_ATG_ATGM5_WDATA20_ADDR(base) ((base) + (0xD40))
#define SOC_ATG_ATGM5_WDATA21_ADDR(base) ((base) + (0xD44))
#define SOC_ATG_ATGM5_WDATA22_ADDR(base) ((base) + (0xD48))
#define SOC_ATG_ATGM5_WDATA23_ADDR(base) ((base) + (0xD4C))
#define SOC_ATG_ATGM5_WDATA30_ADDR(base) ((base) + (0xD50))
#define SOC_ATG_ATGM5_WDATA31_ADDR(base) ((base) + (0xD54))
#define SOC_ATG_ATGM5_WDATA32_ADDR(base) ((base) + (0xD58))
#define SOC_ATG_ATGM5_WDATA33_ADDR(base) ((base) + (0xD5C))
#define SOC_ATG_ATGM5_RBURST_MODE_ADDR(base) ((base) + (0xD60))
#define SOC_ATG_ATGM5_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xD64))
#define SOC_ATG_ATGM5_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xD68))
#define SOC_ATG_ATGM5_RADDR_NUM_ADDR(base) ((base) + (0xD6c))
#define SOC_ATG_ATGM5_BURST_FINI_STAT_ADDR(base) ((base) + (0xD70))
#define SOC_ATG_ATGM5_ACLK_GT_ADDR(base) ((base) + (0xD74))
#define SOC_ATG_ATGM5_RBURST_MODE2_ADDR(base) ((base) + (0xD78))
#define SOC_ATG_ATGM6_MODE_CTRL_ADDR(base) ((base) + (0xE00))
#define SOC_ATG_ATGM6_WBURST_MODE_ADDR(base) ((base) + (0xE04))
#define SOC_ATG_ATGM6_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xE08))
#define SOC_ATG_ATGM6_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xE0c))
#define SOC_ATG_ATGM6_WADDR_NUM_ADDR(base) ((base) + (0xE10))
#define SOC_ATG_ATGM6_WBURST_MODE2_ADDR(base) ((base) + (0xE14))
#define SOC_ATG_ATGM6_WDATA00_ADDR(base) ((base) + (0xE20))
#define SOC_ATG_ATGM6_WDATA01_ADDR(base) ((base) + (0xE24))
#define SOC_ATG_ATGM6_WDATA02_ADDR(base) ((base) + (0xE28))
#define SOC_ATG_ATGM6_WDATA03_ADDR(base) ((base) + (0xE2C))
#define SOC_ATG_ATGM6_WDATA10_ADDR(base) ((base) + (0xE30))
#define SOC_ATG_ATGM6_WDATA11_ADDR(base) ((base) + (0xE34))
#define SOC_ATG_ATGM6_WDATA12_ADDR(base) ((base) + (0xE38))
#define SOC_ATG_ATGM6_WDATA13_ADDR(base) ((base) + (0xE3C))
#define SOC_ATG_ATGM6_WDATA20_ADDR(base) ((base) + (0xE40))
#define SOC_ATG_ATGM6_WDATA21_ADDR(base) ((base) + (0xE44))
#define SOC_ATG_ATGM6_WDATA22_ADDR(base) ((base) + (0xE48))
#define SOC_ATG_ATGM6_WDATA23_ADDR(base) ((base) + (0xE4C))
#define SOC_ATG_ATGM6_WDATA30_ADDR(base) ((base) + (0xE50))
#define SOC_ATG_ATGM6_WDATA31_ADDR(base) ((base) + (0xE54))
#define SOC_ATG_ATGM6_WDATA32_ADDR(base) ((base) + (0xE58))
#define SOC_ATG_ATGM6_WDATA33_ADDR(base) ((base) + (0xE5C))
#define SOC_ATG_ATGM6_RBURST_MODE_ADDR(base) ((base) + (0xE60))
#define SOC_ATG_ATGM6_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xE64))
#define SOC_ATG_ATGM6_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xE68))
#define SOC_ATG_ATGM6_RADDR_NUM_ADDR(base) ((base) + (0xE6c))
#define SOC_ATG_ATGM6_BURST_FINI_STAT_ADDR(base) ((base) + (0xE70))
#define SOC_ATG_ATGM6_ACLK_GT_ADDR(base) ((base) + (0xE74))
#define SOC_ATG_ATGM6_RBURST_MODE2_ADDR(base) ((base) + (0xE78))
#define SOC_ATG_ATGM7_MODE_CTRL_ADDR(base) ((base) + (0xF00))
#define SOC_ATG_ATGM7_WBURST_MODE_ADDR(base) ((base) + (0xF04))
#define SOC_ATG_ATGM7_WBURST_ADDR_LOW_ADDR(base) ((base) + (0xF08))
#define SOC_ATG_ATGM7_WBURST_ADDR_HIGH_ADDR(base) ((base) + (0xF0c))
#define SOC_ATG_ATGM7_WADDR_NUM_ADDR(base) ((base) + (0xF10))
#define SOC_ATG_ATGM7_WBURST_MODE2_ADDR(base) ((base) + (0xF14))
#define SOC_ATG_ATGM7_WDATA00_ADDR(base) ((base) + (0xF20))
#define SOC_ATG_ATGM7_WDATA01_ADDR(base) ((base) + (0xF24))
#define SOC_ATG_ATGM7_WDATA02_ADDR(base) ((base) + (0xF28))
#define SOC_ATG_ATGM7_WDATA03_ADDR(base) ((base) + (0xF2C))
#define SOC_ATG_ATGM7_WDATA10_ADDR(base) ((base) + (0xF30))
#define SOC_ATG_ATGM7_WDATA11_ADDR(base) ((base) + (0xF34))
#define SOC_ATG_ATGM7_WDATA12_ADDR(base) ((base) + (0xF38))
#define SOC_ATG_ATGM7_WDATA13_ADDR(base) ((base) + (0xF3C))
#define SOC_ATG_ATGM7_WDATA20_ADDR(base) ((base) + (0xF40))
#define SOC_ATG_ATGM7_WDATA21_ADDR(base) ((base) + (0xF44))
#define SOC_ATG_ATGM7_WDATA22_ADDR(base) ((base) + (0xF48))
#define SOC_ATG_ATGM7_WDATA23_ADDR(base) ((base) + (0xF4C))
#define SOC_ATG_ATGM7_WDATA30_ADDR(base) ((base) + (0xF50))
#define SOC_ATG_ATGM7_WDATA31_ADDR(base) ((base) + (0xF54))
#define SOC_ATG_ATGM7_WDATA32_ADDR(base) ((base) + (0xF58))
#define SOC_ATG_ATGM7_WDATA33_ADDR(base) ((base) + (0xF5C))
#define SOC_ATG_ATGM7_RBURST_MODE_ADDR(base) ((base) + (0xF60))
#define SOC_ATG_ATGM7_RBURST_ADDR_LOW_ADDR(base) ((base) + (0xF64))
#define SOC_ATG_ATGM7_RBURST_ADDR_HIGH_ADDR(base) ((base) + (0xF68))
#define SOC_ATG_ATGM7_RADDR_NUM_ADDR(base) ((base) + (0xF6c))
#define SOC_ATG_ATGM7_BURST_FINI_STAT_ADDR(base) ((base) + (0xF70))
#define SOC_ATG_ATGM7_ACLK_GT_ADDR(base) ((base) + (0xF74))
#define SOC_ATG_ATGM7_RBURST_MODE2_ADDR(base) ((base) + (0xF78))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM0_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM0_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM0_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM0_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM0_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM0_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM0_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM0_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM0_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM0_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM0_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM0_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM0_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM0_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM0_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM0_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM0_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM0_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM0_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM0_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM0_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM0_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM0_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM0_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM0_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM0_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM0_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM0_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM0_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM0_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM0_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM0_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM0_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM0_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM0_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM0_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM0_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM0_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM0_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM0_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM0_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM0_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM0_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM0_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM0_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM0_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM0_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM0_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM0_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM0_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM0_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM0_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM0_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM0_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM0_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM0_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM0_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM0_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM0_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM0_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM0_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM0_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM0_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM0_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM0_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM0_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM0_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM0_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM0_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM0_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM0_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM0_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM0_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM0_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM0_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM0_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM1_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM1_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM1_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM1_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM1_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM1_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM1_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM1_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM1_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM1_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM1_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM1_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM1_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM1_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM1_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM1_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM1_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM1_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM1_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM1_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM1_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM1_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM1_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM1_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM1_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM1_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM1_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM1_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM1_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM1_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM1_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM1_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM1_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM1_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM1_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM1_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM1_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM1_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM1_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM1_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM1_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM1_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM1_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM1_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM1_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM1_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM1_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM1_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM1_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM1_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM1_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM1_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM1_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM1_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM1_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM1_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM1_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM1_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM1_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM1_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM1_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM1_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM1_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM1_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM1_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM1_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM1_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM1_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM1_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM1_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM1_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM1_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM1_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM1_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM1_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM1_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM2_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM2_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM2_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM2_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM2_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM2_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM2_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM2_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM2_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM2_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM2_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM2_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM2_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM2_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM2_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM2_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM2_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM2_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM2_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM2_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM2_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM2_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM2_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM2_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM2_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM2_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM2_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM2_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM2_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM2_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM2_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM2_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM2_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM2_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM2_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM2_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM2_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM2_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM2_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM2_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM2_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM2_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM2_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM2_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM2_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM2_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM2_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM2_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM2_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM2_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM2_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM2_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM2_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM2_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM2_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM2_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM2_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM2_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM2_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM2_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM2_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM2_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM2_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM2_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM2_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM2_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM2_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM2_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM2_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM2_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM2_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM2_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM2_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM2_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM2_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM2_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS1_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS1_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS1_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS1_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS1_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS1_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS1_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS1_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS1_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS1_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS1_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS1_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS1_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS1_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS1_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS1_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS1_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS1_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS1_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS1_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS1_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS1_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS1_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS1_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS1_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS1_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS1_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS1_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS1_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS1_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS1_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS1_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS1_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS1_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS2_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS2_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS2_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS2_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS2_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS2_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS2_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS2_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS2_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS2_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS2_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS2_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS2_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS2_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS2_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS2_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS2_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS2_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS2_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS2_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS2_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS2_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS2_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS2_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS2_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS2_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS2_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS2_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS2_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS2_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS2_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS2_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS2_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS2_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS2_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS2_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS2_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS2_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS3_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS3_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS3_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS3_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS3_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS3_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS3_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS3_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS3_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS3_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS3_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS3_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS3_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS3_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS3_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS3_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS3_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS3_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS3_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS3_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS3_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS3_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS3_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS3_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS3_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS3_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS3_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS3_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS3_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS3_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS3_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS3_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS3_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS3_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS3_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS3_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS3_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS3_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS4_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS4_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS4_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS4_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS4_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS4_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS4_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS4_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS4_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS4_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS4_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS4_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS4_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS4_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS4_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS4_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS4_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS4_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS4_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS4_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS4_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS4_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS4_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS4_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS4_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS4_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS4_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS4_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS4_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS4_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS4_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS4_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS4_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS4_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS4_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS4_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS4_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS4_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS5_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS5_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS5_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS5_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS5_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS5_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS5_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS5_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS5_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS5_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS5_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS5_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS5_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS5_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS5_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS5_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS5_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS5_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS5_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS5_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS5_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS5_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS5_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS5_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS5_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS5_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS5_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS5_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS5_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS5_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS5_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS5_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS5_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS5_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS5_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS5_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS5_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS5_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS5_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS5_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS5_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS5_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS5_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS5_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS5_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS5_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS6_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS6_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS6_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS6_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS6_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS6_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS6_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS6_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS6_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS6_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS6_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS6_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS6_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS6_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS6_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS6_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS6_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS6_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS6_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS6_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS6_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS6_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS6_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS6_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS6_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS6_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS6_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS6_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS6_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS6_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS6_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS6_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS6_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS6_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS6_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS6_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS6_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS6_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS6_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS6_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS6_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS6_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS6_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS6_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS6_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS6_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM3_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM3_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM3_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM3_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM3_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM3_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM3_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM3_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM3_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM3_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM3_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM3_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM3_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM3_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM3_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM3_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM3_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM3_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM3_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM3_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM3_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM3_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM3_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM3_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM3_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM3_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM3_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM3_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM3_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM3_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM3_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM3_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM3_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM3_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM3_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM3_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM3_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM3_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM3_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM3_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM3_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM3_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM3_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM3_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM3_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM3_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM3_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM3_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM3_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM3_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM3_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM3_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM3_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM3_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM3_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM3_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM3_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM3_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM3_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM3_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM3_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM3_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM3_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM3_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM3_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM3_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM3_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM3_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM3_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM3_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM3_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM3_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM3_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM3_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM3_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM3_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int axi_pend_bypass : 1;
        unsigned int dummy_read_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGS7_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGS7_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGS7_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGS7_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGS7_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG_ATGS7_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG_ATGS7_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG_ATGS7_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG_ATGS7_MODE_CTRL_dummy_read_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int check_rank_num : 3;
        unsigned int check_burst_len : 2;
        unsigned int reserved : 7;
        unsigned int arqos_cfg : 4;
        unsigned int arid_cfg : 16;
    } reg;
} SOC_ATG_ATGS7_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG_ATGS7_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG_ATGS7_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG_ATGS7_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG_ATGS7_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR0_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR1_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR2_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR3_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR4_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR5_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR6_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR7_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR7_ddr_raddr7_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_high : 8;
        unsigned int ddr_raddr1_high : 8;
        unsigned int ddr_raddr2_high : 8;
        unsigned int ddr_raddr3_high : 8;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG_ATGS7_DDR_RADDR_H0_ddr_raddr3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_high : 8;
        unsigned int ddr_raddr5_high : 8;
        unsigned int ddr_raddr6_high : 8;
        unsigned int ddr_raddr7_high : 8;
    } reg;
} SOC_ATG_ATGS7_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG_ATGS7_DDR_RADDR_H1_ddr_raddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_read_stat : 2;
        unsigned int dummyread_left_num : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_ATG_ATGS7_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG_ATGS7_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA00_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA00_rdata00_START (0)
#define SOC_ATG_ATGS7_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA01_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA01_rdata01_START (0)
#define SOC_ATG_ATGS7_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA02_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA02_rdata02_START (0)
#define SOC_ATG_ATGS7_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA03_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA03_rdata03_START (0)
#define SOC_ATG_ATGS7_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA10_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA10_rdata10_START (0)
#define SOC_ATG_ATGS7_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA11_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA11_rdata11_START (0)
#define SOC_ATG_ATGS7_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA12_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA12_rdata12_START (0)
#define SOC_ATG_ATGS7_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA13_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA13_rdata13_START (0)
#define SOC_ATG_ATGS7_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA20_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA20_rdata20_START (0)
#define SOC_ATG_ATGS7_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA21_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA21_rdata21_START (0)
#define SOC_ATG_ATGS7_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA22_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA22_rdata22_START (0)
#define SOC_ATG_ATGS7_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA23_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA23_rdata23_START (0)
#define SOC_ATG_ATGS7_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA30_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA30_rdata30_START (0)
#define SOC_ATG_ATGS7_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA31_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA31_rdata31_START (0)
#define SOC_ATG_ATGS7_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA32_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA32_rdata32_START (0)
#define SOC_ATG_ATGS7_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG_ATGS7_RDATA33_UNION;
#endif
#define SOC_ATG_ATGS7_RDATA33_rdata33_START (0)
#define SOC_ATG_ATGS7_RDATA33_rdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arprot_cfg : 3;
        unsigned int reserved_0 : 2;
        unsigned int armid_cfg : 7;
        unsigned int arcache_cfg : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ATG_ATGS7_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG_ATGS7_DDR_CHECK_CFG2_arcache_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_dm_en : 1;
        unsigned int axi_aclk_pt_en : 1;
        unsigned int reserved : 14;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGS7_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGS7_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG_ATGS7_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG_ATGS7_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG_ATGS7_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG_ATGS7_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGS7_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM4_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM4_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM4_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM4_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM4_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM4_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM4_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM4_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM4_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM4_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM4_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM4_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM4_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM4_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM4_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM4_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM4_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM4_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM4_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM4_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM4_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM4_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM4_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM4_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM4_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM4_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM4_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM4_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM4_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM4_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM4_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM4_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM4_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM4_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM4_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM4_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM4_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM4_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM4_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM4_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM4_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM4_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM4_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM4_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM4_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM4_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM4_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM4_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM4_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM4_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM4_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM4_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM4_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM4_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM4_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM4_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM4_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM4_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM4_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM4_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM4_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM4_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM4_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM4_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM4_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM4_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM4_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM4_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM4_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM4_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM4_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM4_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM4_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM4_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM4_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM4_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM5_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM5_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM5_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM5_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM5_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM5_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM5_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM5_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM5_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM5_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM5_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM5_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM5_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM5_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM5_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM5_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM5_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM5_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM5_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM5_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM5_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM5_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM5_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM5_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM5_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM5_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM5_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM5_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM5_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM5_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM5_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM5_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM5_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM5_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM5_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM5_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM5_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM5_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM5_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM5_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM5_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM5_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM5_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM5_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM5_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM5_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM5_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM5_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM5_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM5_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM5_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM5_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM5_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM5_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM5_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM5_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM5_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM5_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM5_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM5_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM5_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM5_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM5_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM5_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM5_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM5_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM5_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM5_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM5_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM5_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM5_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM5_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM5_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM5_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM5_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM5_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM5_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM5_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM5_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM5_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM5_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM5_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM5_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM5_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM5_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM5_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM5_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM6_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM6_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM6_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM6_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM6_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM6_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM6_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM6_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM6_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM6_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM6_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM6_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM6_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM6_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM6_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM6_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM6_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM6_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM6_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM6_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM6_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM6_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM6_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM6_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM6_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM6_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM6_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM6_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM6_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM6_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM6_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM6_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM6_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM6_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM6_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM6_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM6_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM6_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM6_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM6_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM6_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM6_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM6_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM6_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM6_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM6_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM6_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM6_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM6_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM6_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM6_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM6_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM6_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM6_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM6_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM6_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM6_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM6_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM6_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM6_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM6_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM6_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM6_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM6_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM6_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM6_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM6_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM6_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM6_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM6_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM6_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM6_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM6_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM6_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM6_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM6_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM6_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM6_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM6_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM6_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM6_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM6_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM6_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM6_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM6_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM6_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM6_RBURST_MODE2_arcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_test_bypass : 1;
        unsigned int power_test_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM7_MODE_CTRL_UNION;
#endif
#define SOC_ATG_ATGM7_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG_ATGM7_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG_ATGM7_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG_ATGM7_MODE_CTRL_power_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awlen_cfg : 3;
        unsigned int wburst_en : 1;
        unsigned int wmode : 1;
        unsigned int wgap_time : 11;
        unsigned int wr_in_order : 1;
        unsigned int awid_set : 6;
        unsigned int awmid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM7_WBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM7_WBURST_MODE_awlen_cfg_START (0)
#define SOC_ATG_ATGM7_WBURST_MODE_awlen_cfg_END (2)
#define SOC_ATG_ATGM7_WBURST_MODE_wburst_en_START (3)
#define SOC_ATG_ATGM7_WBURST_MODE_wburst_en_END (3)
#define SOC_ATG_ATGM7_WBURST_MODE_wmode_START (4)
#define SOC_ATG_ATGM7_WBURST_MODE_wmode_END (4)
#define SOC_ATG_ATGM7_WBURST_MODE_wgap_time_START (5)
#define SOC_ATG_ATGM7_WBURST_MODE_wgap_time_END (15)
#define SOC_ATG_ATGM7_WBURST_MODE_wr_in_order_START (16)
#define SOC_ATG_ATGM7_WBURST_MODE_wr_in_order_END (16)
#define SOC_ATG_ATGM7_WBURST_MODE_awid_set_START (17)
#define SOC_ATG_ATGM7_WBURST_MODE_awid_set_END (22)
#define SOC_ATG_ATGM7_WBURST_MODE_awmid_cfg_START (23)
#define SOC_ATG_ATGM7_WBURST_MODE_awmid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM7_WBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM7_WBURST_ADDR_LOW_awaddr_cfg_low_START (0)
#define SOC_ATG_ATGM7_WBURST_ADDR_LOW_awaddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM7_WBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM7_WBURST_ADDR_HIGH_awaddr_cfg_high_START (0)
#define SOC_ATG_ATGM7_WBURST_ADDR_HIGH_awaddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int waddr_num : 32;
    } reg;
} SOC_ATG_ATGM7_WADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM7_WADDR_NUM_waddr_num_START (0)
#define SOC_ATG_ATGM7_WADDR_NUM_waddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM7_WBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM7_WBURST_MODE2_awcache_cfg_START (0)
#define SOC_ATG_ATGM7_WBURST_MODE2_awcache_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata00 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA00_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA00_wdata00_START (0)
#define SOC_ATG_ATGM7_WDATA00_wdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata01 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA01_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA01_wdata01_START (0)
#define SOC_ATG_ATGM7_WDATA01_wdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata02 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA02_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA02_wdata02_START (0)
#define SOC_ATG_ATGM7_WDATA02_wdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata03 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA03_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA03_wdata03_START (0)
#define SOC_ATG_ATGM7_WDATA03_wdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata10 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA10_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA10_wdata10_START (0)
#define SOC_ATG_ATGM7_WDATA10_wdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata11 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA11_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA11_wdata11_START (0)
#define SOC_ATG_ATGM7_WDATA11_wdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata12 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA12_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA12_wdata12_START (0)
#define SOC_ATG_ATGM7_WDATA12_wdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata13 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA13_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA13_wdata13_START (0)
#define SOC_ATG_ATGM7_WDATA13_wdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata20 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA20_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA20_wdata20_START (0)
#define SOC_ATG_ATGM7_WDATA20_wdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata21 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA21_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA21_wdata21_START (0)
#define SOC_ATG_ATGM7_WDATA21_wdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata22 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA22_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA22_wdata22_START (0)
#define SOC_ATG_ATGM7_WDATA22_wdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata23 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA23_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA23_wdata23_START (0)
#define SOC_ATG_ATGM7_WDATA23_wdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata30 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA30_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA30_wdata30_START (0)
#define SOC_ATG_ATGM7_WDATA30_wdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata31 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA31_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA31_wdata31_START (0)
#define SOC_ATG_ATGM7_WDATA31_wdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata32 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA32_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA32_wdata32_START (0)
#define SOC_ATG_ATGM7_WDATA32_wdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata33 : 32;
    } reg;
} SOC_ATG_ATGM7_WDATA33_UNION;
#endif
#define SOC_ATG_ATGM7_WDATA33_wdata33_START (0)
#define SOC_ATG_ATGM7_WDATA33_wdata33_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arlen_cfg : 3;
        unsigned int rburst_en : 1;
        unsigned int rmode : 1;
        unsigned int rgap_time : 11;
        unsigned int rd_in_order : 1;
        unsigned int arid_set : 6;
        unsigned int armid_cfg : 7;
        unsigned int reserved : 2;
    } reg;
} SOC_ATG_ATGM7_RBURST_MODE_UNION;
#endif
#define SOC_ATG_ATGM7_RBURST_MODE_arlen_cfg_START (0)
#define SOC_ATG_ATGM7_RBURST_MODE_arlen_cfg_END (2)
#define SOC_ATG_ATGM7_RBURST_MODE_rburst_en_START (3)
#define SOC_ATG_ATGM7_RBURST_MODE_rburst_en_END (3)
#define SOC_ATG_ATGM7_RBURST_MODE_rmode_START (4)
#define SOC_ATG_ATGM7_RBURST_MODE_rmode_END (4)
#define SOC_ATG_ATGM7_RBURST_MODE_rgap_time_START (5)
#define SOC_ATG_ATGM7_RBURST_MODE_rgap_time_END (15)
#define SOC_ATG_ATGM7_RBURST_MODE_rd_in_order_START (16)
#define SOC_ATG_ATGM7_RBURST_MODE_rd_in_order_END (16)
#define SOC_ATG_ATGM7_RBURST_MODE_arid_set_START (17)
#define SOC_ATG_ATGM7_RBURST_MODE_arid_set_END (22)
#define SOC_ATG_ATGM7_RBURST_MODE_armid_cfg_START (23)
#define SOC_ATG_ATGM7_RBURST_MODE_armid_cfg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_low : 32;
    } reg;
} SOC_ATG_ATGM7_RBURST_ADDR_LOW_UNION;
#endif
#define SOC_ATG_ATGM7_RBURST_ADDR_LOW_araddr_cfg_low_START (0)
#define SOC_ATG_ATGM7_RBURST_ADDR_LOW_araddr_cfg_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_cfg_high : 32;
    } reg;
} SOC_ATG_ATGM7_RBURST_ADDR_HIGH_UNION;
#endif
#define SOC_ATG_ATGM7_RBURST_ADDR_HIGH_araddr_cfg_high_START (0)
#define SOC_ATG_ATGM7_RBURST_ADDR_HIGH_araddr_cfg_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raddr_num : 32;
    } reg;
} SOC_ATG_ATGM7_RADDR_NUM_UNION;
#endif
#define SOC_ATG_ATGM7_RADDR_NUM_raddr_num_START (0)
#define SOC_ATG_ATGM7_RADDR_NUM_raddr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_finish_stat : 1;
        unsigned int wcmd_finish_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ATG_ATGM7_BURST_FINI_STAT_UNION;
#endif
#define SOC_ATG_ATGM7_BURST_FINI_STAT_rcmd_finish_stat_START (0)
#define SOC_ATG_ATGM7_BURST_FINI_STAT_rcmd_finish_stat_END (0)
#define SOC_ATG_ATGM7_BURST_FINI_STAT_wcmd_finish_stat_START (1)
#define SOC_ATG_ATGM7_BURST_FINI_STAT_wcmd_finish_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_aclk_en : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_ATG_ATGM7_ACLK_GT_UNION;
#endif
#define SOC_ATG_ATGM7_ACLK_GT_axi_aclk_en_START (0)
#define SOC_ATG_ATGM7_ACLK_GT_axi_aclk_en_END (0)
#define SOC_ATG_ATGM7_ACLK_GT_bitmasken_START (16)
#define SOC_ATG_ATGM7_ACLK_GT_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_ATG_ATGM7_RBURST_MODE2_UNION;
#endif
#define SOC_ATG_ATGM7_RBURST_MODE2_arcache_cfg_START (0)
#define SOC_ATG_ATGM7_RBURST_MODE2_arcache_cfg_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
