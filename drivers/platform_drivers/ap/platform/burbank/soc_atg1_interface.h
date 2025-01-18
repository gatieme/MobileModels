#ifndef __SOC_ATG1_INTERFACE_H__
#define __SOC_ATG1_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ATG1_ATGS0_MODE_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_ADDR(base) ((base) + (0x004UL))
#define SOC_ATG1_ATGS0_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x008UL))
#define SOC_ATG1_ATGS0_AXI_BUS_STAT_ADDR(base) ((base) + (0x00CUL))
#define SOC_ATG1_ATGS0_DDR_RADDR0_ADDR(base) ((base) + (0x010UL))
#define SOC_ATG1_ATGS0_DDR_RADDR1_ADDR(base) ((base) + (0x014UL))
#define SOC_ATG1_ATGS0_DDR_RADDR2_ADDR(base) ((base) + (0x018UL))
#define SOC_ATG1_ATGS0_DDR_RADDR3_ADDR(base) ((base) + (0x01CUL))
#define SOC_ATG1_ATGS0_DDR_RADDR4_ADDR(base) ((base) + (0x020UL))
#define SOC_ATG1_ATGS0_DDR_RADDR5_ADDR(base) ((base) + (0x024UL))
#define SOC_ATG1_ATGS0_DDR_RADDR6_ADDR(base) ((base) + (0x028UL))
#define SOC_ATG1_ATGS0_DDR_RADDR7_ADDR(base) ((base) + (0x02CUL))
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ADDR(base) ((base) + (0x030UL))
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ADDR(base) ((base) + (0x034UL))
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_ADDR(base) ((base) + (0x038UL))
#define SOC_ATG1_ATGS0_RDATA00_ADDR(base) ((base) + (0x040UL))
#define SOC_ATG1_ATGS0_RDATA01_ADDR(base) ((base) + (0x044UL))
#define SOC_ATG1_ATGS0_RDATA02_ADDR(base) ((base) + (0x048UL))
#define SOC_ATG1_ATGS0_RDATA03_ADDR(base) ((base) + (0x04CUL))
#define SOC_ATG1_ATGS0_RDATA10_ADDR(base) ((base) + (0x050UL))
#define SOC_ATG1_ATGS0_RDATA11_ADDR(base) ((base) + (0x054UL))
#define SOC_ATG1_ATGS0_RDATA12_ADDR(base) ((base) + (0x058UL))
#define SOC_ATG1_ATGS0_RDATA13_ADDR(base) ((base) + (0x05CUL))
#define SOC_ATG1_ATGS0_RDATA20_ADDR(base) ((base) + (0x060UL))
#define SOC_ATG1_ATGS0_RDATA21_ADDR(base) ((base) + (0x064UL))
#define SOC_ATG1_ATGS0_RDATA22_ADDR(base) ((base) + (0x068UL))
#define SOC_ATG1_ATGS0_RDATA23_ADDR(base) ((base) + (0x06CUL))
#define SOC_ATG1_ATGS0_RDATA30_ADDR(base) ((base) + (0x070UL))
#define SOC_ATG1_ATGS0_RDATA31_ADDR(base) ((base) + (0x074UL))
#define SOC_ATG1_ATGS0_RDATA32_ADDR(base) ((base) + (0x078UL))
#define SOC_ATG1_ATGS0_RDATA33_ADDR(base) ((base) + (0x07CUL))
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x080UL))
#define SOC_ATG1_ATGS0_ACLK_GT_ADDR(base) ((base) + (0x084UL))
#define SOC_ATG1_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x100UL))
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x104UL))
#define SOC_ATG1_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x108UL))
#define SOC_ATG1_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x10CUL))
#define SOC_ATG1_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x110UL))
#define SOC_ATG1_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x114UL))
#define SOC_ATG1_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x118UL))
#define SOC_ATG1_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x11CUL))
#define SOC_ATG1_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x120UL))
#define SOC_ATG1_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x124UL))
#define SOC_ATG1_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x128UL))
#define SOC_ATG1_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x12CUL))
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x130UL))
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x134UL))
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x138UL))
#define SOC_ATG1_ATGS1_RDATA00_ADDR(base) ((base) + (0x140UL))
#define SOC_ATG1_ATGS1_RDATA01_ADDR(base) ((base) + (0x144UL))
#define SOC_ATG1_ATGS1_RDATA02_ADDR(base) ((base) + (0x148UL))
#define SOC_ATG1_ATGS1_RDATA03_ADDR(base) ((base) + (0x14CUL))
#define SOC_ATG1_ATGS1_RDATA10_ADDR(base) ((base) + (0x150UL))
#define SOC_ATG1_ATGS1_RDATA11_ADDR(base) ((base) + (0x154UL))
#define SOC_ATG1_ATGS1_RDATA12_ADDR(base) ((base) + (0x158UL))
#define SOC_ATG1_ATGS1_RDATA13_ADDR(base) ((base) + (0x15CUL))
#define SOC_ATG1_ATGS1_RDATA20_ADDR(base) ((base) + (0x160UL))
#define SOC_ATG1_ATGS1_RDATA21_ADDR(base) ((base) + (0x164UL))
#define SOC_ATG1_ATGS1_RDATA22_ADDR(base) ((base) + (0x168UL))
#define SOC_ATG1_ATGS1_RDATA23_ADDR(base) ((base) + (0x16CUL))
#define SOC_ATG1_ATGS1_RDATA30_ADDR(base) ((base) + (0x170UL))
#define SOC_ATG1_ATGS1_RDATA31_ADDR(base) ((base) + (0x174UL))
#define SOC_ATG1_ATGS1_RDATA32_ADDR(base) ((base) + (0x178UL))
#define SOC_ATG1_ATGS1_RDATA33_ADDR(base) ((base) + (0x17CUL))
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x180UL))
#define SOC_ATG1_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x184UL))
#else
#define SOC_ATG1_ATGS0_MODE_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_ADDR(base) ((base) + (0x004))
#define SOC_ATG1_ATGS0_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x008))
#define SOC_ATG1_ATGS0_AXI_BUS_STAT_ADDR(base) ((base) + (0x00C))
#define SOC_ATG1_ATGS0_DDR_RADDR0_ADDR(base) ((base) + (0x010))
#define SOC_ATG1_ATGS0_DDR_RADDR1_ADDR(base) ((base) + (0x014))
#define SOC_ATG1_ATGS0_DDR_RADDR2_ADDR(base) ((base) + (0x018))
#define SOC_ATG1_ATGS0_DDR_RADDR3_ADDR(base) ((base) + (0x01C))
#define SOC_ATG1_ATGS0_DDR_RADDR4_ADDR(base) ((base) + (0x020))
#define SOC_ATG1_ATGS0_DDR_RADDR5_ADDR(base) ((base) + (0x024))
#define SOC_ATG1_ATGS0_DDR_RADDR6_ADDR(base) ((base) + (0x028))
#define SOC_ATG1_ATGS0_DDR_RADDR7_ADDR(base) ((base) + (0x02C))
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ADDR(base) ((base) + (0x030))
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ADDR(base) ((base) + (0x034))
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_ADDR(base) ((base) + (0x038))
#define SOC_ATG1_ATGS0_RDATA00_ADDR(base) ((base) + (0x040))
#define SOC_ATG1_ATGS0_RDATA01_ADDR(base) ((base) + (0x044))
#define SOC_ATG1_ATGS0_RDATA02_ADDR(base) ((base) + (0x048))
#define SOC_ATG1_ATGS0_RDATA03_ADDR(base) ((base) + (0x04C))
#define SOC_ATG1_ATGS0_RDATA10_ADDR(base) ((base) + (0x050))
#define SOC_ATG1_ATGS0_RDATA11_ADDR(base) ((base) + (0x054))
#define SOC_ATG1_ATGS0_RDATA12_ADDR(base) ((base) + (0x058))
#define SOC_ATG1_ATGS0_RDATA13_ADDR(base) ((base) + (0x05C))
#define SOC_ATG1_ATGS0_RDATA20_ADDR(base) ((base) + (0x060))
#define SOC_ATG1_ATGS0_RDATA21_ADDR(base) ((base) + (0x064))
#define SOC_ATG1_ATGS0_RDATA22_ADDR(base) ((base) + (0x068))
#define SOC_ATG1_ATGS0_RDATA23_ADDR(base) ((base) + (0x06C))
#define SOC_ATG1_ATGS0_RDATA30_ADDR(base) ((base) + (0x070))
#define SOC_ATG1_ATGS0_RDATA31_ADDR(base) ((base) + (0x074))
#define SOC_ATG1_ATGS0_RDATA32_ADDR(base) ((base) + (0x078))
#define SOC_ATG1_ATGS0_RDATA33_ADDR(base) ((base) + (0x07C))
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x080))
#define SOC_ATG1_ATGS0_ACLK_GT_ADDR(base) ((base) + (0x084))
#define SOC_ATG1_ATGS1_MODE_CTRL_ADDR(base) ((base) + (0x100))
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_ADDR(base) ((base) + (0x104))
#define SOC_ATG1_ATGS1_DDR_CHECK_PERIOD_ADDR(base) ((base) + (0x108))
#define SOC_ATG1_ATGS1_AXI_BUS_STAT_ADDR(base) ((base) + (0x10C))
#define SOC_ATG1_ATGS1_DDR_RADDR0_ADDR(base) ((base) + (0x110))
#define SOC_ATG1_ATGS1_DDR_RADDR1_ADDR(base) ((base) + (0x114))
#define SOC_ATG1_ATGS1_DDR_RADDR2_ADDR(base) ((base) + (0x118))
#define SOC_ATG1_ATGS1_DDR_RADDR3_ADDR(base) ((base) + (0x11C))
#define SOC_ATG1_ATGS1_DDR_RADDR4_ADDR(base) ((base) + (0x120))
#define SOC_ATG1_ATGS1_DDR_RADDR5_ADDR(base) ((base) + (0x124))
#define SOC_ATG1_ATGS1_DDR_RADDR6_ADDR(base) ((base) + (0x128))
#define SOC_ATG1_ATGS1_DDR_RADDR7_ADDR(base) ((base) + (0x12C))
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ADDR(base) ((base) + (0x130))
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ADDR(base) ((base) + (0x134))
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_ADDR(base) ((base) + (0x138))
#define SOC_ATG1_ATGS1_RDATA00_ADDR(base) ((base) + (0x140))
#define SOC_ATG1_ATGS1_RDATA01_ADDR(base) ((base) + (0x144))
#define SOC_ATG1_ATGS1_RDATA02_ADDR(base) ((base) + (0x148))
#define SOC_ATG1_ATGS1_RDATA03_ADDR(base) ((base) + (0x14C))
#define SOC_ATG1_ATGS1_RDATA10_ADDR(base) ((base) + (0x150))
#define SOC_ATG1_ATGS1_RDATA11_ADDR(base) ((base) + (0x154))
#define SOC_ATG1_ATGS1_RDATA12_ADDR(base) ((base) + (0x158))
#define SOC_ATG1_ATGS1_RDATA13_ADDR(base) ((base) + (0x15C))
#define SOC_ATG1_ATGS1_RDATA20_ADDR(base) ((base) + (0x160))
#define SOC_ATG1_ATGS1_RDATA21_ADDR(base) ((base) + (0x164))
#define SOC_ATG1_ATGS1_RDATA22_ADDR(base) ((base) + (0x168))
#define SOC_ATG1_ATGS1_RDATA23_ADDR(base) ((base) + (0x16C))
#define SOC_ATG1_ATGS1_RDATA30_ADDR(base) ((base) + (0x170))
#define SOC_ATG1_ATGS1_RDATA31_ADDR(base) ((base) + (0x174))
#define SOC_ATG1_ATGS1_RDATA32_ADDR(base) ((base) + (0x178))
#define SOC_ATG1_ATGS1_RDATA33_ADDR(base) ((base) + (0x17C))
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_ADDR(base) ((base) + (0x180))
#define SOC_ATG1_ATGS1_ACLK_GT_ADDR(base) ((base) + (0x184))
#endif
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
} SOC_ATG1_ATGS0_MODE_CTRL_UNION;
#endif
#define SOC_ATG1_ATGS0_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG1_ATGS0_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG1_ATGS0_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG1_ATGS0_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG1_ATGS0_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG1_ATGS0_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG1_ATGS0_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG1_ATGS0_MODE_CTRL_dummy_read_bypass_END (3)
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
} SOC_ATG1_ATGS0_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG1_ATGS0_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG1_ATGS0_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG1_ATGS0_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG1_ATGS0_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR0_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR1_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR2_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR3_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR4_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR5_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR6_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG1_ATGS0_DDR_RADDR7_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR7_ddr_raddr7_low_END (31)
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
} SOC_ATG1_ATGS0_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG1_ATGS0_DDR_RADDR_H0_ddr_raddr3_high_END (31)
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
} SOC_ATG1_ATGS0_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG1_ATGS0_DDR_RADDR_H1_ddr_raddr7_high_END (31)
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
} SOC_ATG1_ATGS0_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG1_ATGS0_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA00_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA00_rdata00_START (0)
#define SOC_ATG1_ATGS0_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA01_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA01_rdata01_START (0)
#define SOC_ATG1_ATGS0_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA02_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA02_rdata02_START (0)
#define SOC_ATG1_ATGS0_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA03_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA03_rdata03_START (0)
#define SOC_ATG1_ATGS0_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA10_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA10_rdata10_START (0)
#define SOC_ATG1_ATGS0_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA11_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA11_rdata11_START (0)
#define SOC_ATG1_ATGS0_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA12_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA12_rdata12_START (0)
#define SOC_ATG1_ATGS0_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA13_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA13_rdata13_START (0)
#define SOC_ATG1_ATGS0_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA20_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA20_rdata20_START (0)
#define SOC_ATG1_ATGS0_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA21_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA21_rdata21_START (0)
#define SOC_ATG1_ATGS0_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA22_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA22_rdata22_START (0)
#define SOC_ATG1_ATGS0_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA23_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA23_rdata23_START (0)
#define SOC_ATG1_ATGS0_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA30_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA30_rdata30_START (0)
#define SOC_ATG1_ATGS0_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA31_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA31_rdata31_START (0)
#define SOC_ATG1_ATGS0_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA32_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA32_rdata32_START (0)
#define SOC_ATG1_ATGS0_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG1_ATGS0_RDATA33_UNION;
#endif
#define SOC_ATG1_ATGS0_RDATA33_rdata33_START (0)
#define SOC_ATG1_ATGS0_RDATA33_rdata33_END (31)
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
} SOC_ATG1_ATGS0_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG1_ATGS0_DDR_CHECK_CFG2_arcache_cfg_END (15)
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
} SOC_ATG1_ATGS0_ACLK_GT_UNION;
#endif
#define SOC_ATG1_ATGS0_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG1_ATGS0_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG1_ATGS0_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG1_ATGS0_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG1_ATGS0_ACLK_GT_bitmasken_START (16)
#define SOC_ATG1_ATGS0_ACLK_GT_bitmasken_END (31)
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
} SOC_ATG1_ATGS1_MODE_CTRL_UNION;
#endif
#define SOC_ATG1_ATGS1_MODE_CTRL_power_test_bypass_START (0)
#define SOC_ATG1_ATGS1_MODE_CTRL_power_test_bypass_END (0)
#define SOC_ATG1_ATGS1_MODE_CTRL_power_test_en_START (1)
#define SOC_ATG1_ATGS1_MODE_CTRL_power_test_en_END (1)
#define SOC_ATG1_ATGS1_MODE_CTRL_axi_pend_bypass_START (2)
#define SOC_ATG1_ATGS1_MODE_CTRL_axi_pend_bypass_END (2)
#define SOC_ATG1_ATGS1_MODE_CTRL_dummy_read_bypass_START (3)
#define SOC_ATG1_ATGS1_MODE_CTRL_dummy_read_bypass_END (3)
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
} SOC_ATG1_ATGS1_DDR_CHECK_CFG_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_check_rank_num_START (0)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_check_rank_num_END (2)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_check_burst_len_START (3)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_check_burst_len_END (4)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_arqos_cfg_START (12)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_arqos_cfg_END (15)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_arid_cfg_START (16)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG_arid_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_check_period : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_CHECK_PERIOD_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_START (0)
#define SOC_ATG1_ATGS1_DDR_CHECK_PERIOD_ddr_check_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_outstd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ATG1_ATGS1_AXI_BUS_STAT_UNION;
#endif
#define SOC_ATG1_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_START (0)
#define SOC_ATG1_ATGS1_AXI_BUS_STAT_axi_outstd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr0_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR0_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR0_ddr_raddr0_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR0_ddr_raddr0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr1_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR1_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR1_ddr_raddr1_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR1_ddr_raddr1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr2_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR2_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR2_ddr_raddr2_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR2_ddr_raddr2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr3_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR3_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR3_ddr_raddr3_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR3_ddr_raddr3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr4_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR4_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR4_ddr_raddr4_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR4_ddr_raddr4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr5_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR5_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR5_ddr_raddr5_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR5_ddr_raddr5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr6_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR6_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR6_ddr_raddr6_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR6_ddr_raddr6_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_raddr7_low : 32;
    } reg;
} SOC_ATG1_ATGS1_DDR_RADDR7_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR7_ddr_raddr7_low_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR7_ddr_raddr7_low_END (31)
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
} SOC_ATG1_ATGS1_DDR_RADDR_H0_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr0_high_END (7)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_START (8)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr1_high_END (15)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_START (16)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr2_high_END (23)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_START (24)
#define SOC_ATG1_ATGS1_DDR_RADDR_H0_ddr_raddr3_high_END (31)
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
} SOC_ATG1_ATGS1_DDR_RADDR_H1_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_START (0)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr4_high_END (7)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_START (8)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr5_high_END (15)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_START (16)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr6_high_END (23)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_START (24)
#define SOC_ATG1_ATGS1_DDR_RADDR_H1_ddr_raddr7_high_END (31)
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
} SOC_ATG1_ATGS1_DUMMY_READ_STAT_UNION;
#endif
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_dummy_read_stat_START (0)
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_dummy_read_stat_END (1)
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_dummyread_left_num_START (2)
#define SOC_ATG1_ATGS1_DUMMY_READ_STAT_dummyread_left_num_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata00 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA00_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA00_rdata00_START (0)
#define SOC_ATG1_ATGS1_RDATA00_rdata00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata01 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA01_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA01_rdata01_START (0)
#define SOC_ATG1_ATGS1_RDATA01_rdata01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata02 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA02_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA02_rdata02_START (0)
#define SOC_ATG1_ATGS1_RDATA02_rdata02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata03 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA03_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA03_rdata03_START (0)
#define SOC_ATG1_ATGS1_RDATA03_rdata03_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata10 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA10_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA10_rdata10_START (0)
#define SOC_ATG1_ATGS1_RDATA10_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata11 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA11_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA11_rdata11_START (0)
#define SOC_ATG1_ATGS1_RDATA11_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata12 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA12_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA12_rdata12_START (0)
#define SOC_ATG1_ATGS1_RDATA12_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata13 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA13_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA13_rdata13_START (0)
#define SOC_ATG1_ATGS1_RDATA13_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata20 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA20_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA20_rdata20_START (0)
#define SOC_ATG1_ATGS1_RDATA20_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata21 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA21_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA21_rdata21_START (0)
#define SOC_ATG1_ATGS1_RDATA21_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata22 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA22_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA22_rdata22_START (0)
#define SOC_ATG1_ATGS1_RDATA22_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata23 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA23_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA23_rdata23_START (0)
#define SOC_ATG1_ATGS1_RDATA23_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata30 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA30_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA30_rdata30_START (0)
#define SOC_ATG1_ATGS1_RDATA30_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata31 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA31_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA31_rdata31_START (0)
#define SOC_ATG1_ATGS1_RDATA31_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata32 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA32_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA32_rdata32_START (0)
#define SOC_ATG1_ATGS1_RDATA32_rdata32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata33 : 32;
    } reg;
} SOC_ATG1_ATGS1_RDATA33_UNION;
#endif
#define SOC_ATG1_ATGS1_RDATA33_rdata33_START (0)
#define SOC_ATG1_ATGS1_RDATA33_rdata33_END (31)
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
} SOC_ATG1_ATGS1_DDR_CHECK_CFG2_UNION;
#endif
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_arprot_cfg_START (0)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_arprot_cfg_END (2)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_armid_cfg_START (5)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_armid_cfg_END (11)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_arcache_cfg_START (12)
#define SOC_ATG1_ATGS1_DDR_CHECK_CFG2_arcache_cfg_END (15)
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
} SOC_ATG1_ATGS1_ACLK_GT_UNION;
#endif
#define SOC_ATG1_ATGS1_ACLK_GT_axi_aclk_dm_en_START (0)
#define SOC_ATG1_ATGS1_ACLK_GT_axi_aclk_dm_en_END (0)
#define SOC_ATG1_ATGS1_ACLK_GT_axi_aclk_pt_en_START (1)
#define SOC_ATG1_ATGS1_ACLK_GT_axi_aclk_pt_en_END (1)
#define SOC_ATG1_ATGS1_ACLK_GT_bitmasken_START (16)
#define SOC_ATG1_ATGS1_ACLK_GT_bitmasken_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
