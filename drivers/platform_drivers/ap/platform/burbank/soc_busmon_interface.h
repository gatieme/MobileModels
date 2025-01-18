#ifndef __SOC_BUSMON_INTERFACE_H__
#define __SOC_BUSMON_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_BUSMON_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_BUSMON_CTRL_STAT0_ADDR(base) ((base) + (0x0004UL))
#define SOC_BUSMON_SYNC_INTERNAL_ADDR(base) ((base) + (0x0008UL))
#define SOC_BUSMON_TS_INTERNAL_ADDR(base) ((base) + (0x000cUL))
#define SOC_BUSMON_MEM_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_ADDR(base) ((base) + (0x0020UL))
#define SOC_BUSMON_TRIGGER_SETTING0_ADDR(base) ((base) + (0x0024UL))
#define SOC_BUSMON_TRIGGER_SETTING1_ADDR(base) ((base) + (0x0028UL))
#define SOC_BUSMON_TRIGGER_SETTING2_ADDR(base) ((base) + (0x002CUL))
#define SOC_BUSMON_TRIGGER_SETTING3_ADDR(base) ((base) + (0x0030UL))
#define SOC_BUSMON_TRIGGER_SETTING4_ADDR(base) ((base) + (0x0034UL))
#define SOC_BUSMON_TRIGGER_SETTING5_ADDR(base) ((base) + (0x0038UL))
#define SOC_BUSMON_TRIGGER_SETTING6_ADDR(base) ((base) + (0x003CUL))
#define SOC_BUSMON_TRIGGER_SETTING7_ADDR(base) ((base) + (0x0040UL))
#define SOC_BUSMON_TRIGGER_SETTING8_ADDR(base) ((base) + (0x0044UL))
#define SOC_BUSMON_TRIGGER_SETTING9_ADDR(base) ((base) + (0x0048UL))
#define SOC_BUSMON_TRIGGER_SETTING10_ADDR(base) ((base) + (0x004CUL))
#define SOC_BUSMON_TRIGGER_SETTING11_ADDR(base) ((base) + (0x0050UL))
#define SOC_BUSMON_TRIGGER_SETTING12_ADDR(base) ((base) + (0x0054UL))
#define SOC_BUSMON_TRIGGER_SETTING13_ADDR(base) ((base) + (0x0058UL))
#define SOC_BUSMON_TRIGGER_SETTING14_ADDR(base) ((base) + (0x005CUL))
#define SOC_BUSMON_TRIGGER_SETTING15_ADDR(base) ((base) + (0x0060UL))
#define SOC_BUSMON_TRIGGER_SETTING16_ADDR(base) ((base) + (0x0064UL))
#define SOC_BUSMON_TRIGGER_SETTING17_ADDR(base) ((base) + (0x0068UL))
#define SOC_BUSMON_TRIGGER_SETTING18_ADDR(base) ((base) + (0x006CUL))
#define SOC_BUSMON_TRIGGER_SETTING19_ADDR(base) ((base) + (0x0070UL))
#define SOC_BUSMON_TRIGGER_SETTING20_ADDR(base) ((base) + (0x0074UL))
#define SOC_BUSMON_TRIGGER_SETTING21_ADDR(base) ((base) + (0x0078UL))
#define SOC_BUSMON_TRIGGER_SETTING22_ADDR(base) ((base) + (0x007CUL))
#define SOC_BUSMON_TRIGGER_SETTING23_ADDR(base) ((base) + (0x0080UL))
#define SOC_BUSMON_TRIGGER_SETTING24_ADDR(base) ((base) + (0x0084UL))
#define SOC_BUSMON_TRIGGER_SETTING25_ADDR(base) ((base) + (0x0088UL))
#define SOC_BUSMON_TRIGGER_SETTING26_ADDR(base) ((base) + (0x008CUL))
#define SOC_BUSMON_TRIGGER_SETTING27_ADDR(base) ((base) + (0x0090UL))
#define SOC_BUSMON_TRIGGER_TIMER_ADDR(base) ((base) + (0x0094UL))
#define SOC_BUSMON_TRIGGER_RFU_CTRL_ADDR(base) ((base) + (0x0098UL))
#define SOC_BUSMON_TRIGGER_RUF_STAT_ADDR(base) ((base) + (0x009CUL))
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_ADDR(base) ((base) + (0x00A0UL))
#define SOC_BUSMON_SAMPLE_RFU_CTRL_ADDR(base) ((base) + (0x00A4UL))
#define SOC_BUSMON_SAMPLE_RFU_STAT_ADDR(base) ((base) + (0x00A8UL))
#define SOC_BUSMON_STP_CTRL0_ADDR(base) ((base) + (0x00B0UL))
#define SOC_BUSMON_STP_STAT0_ADDR(base) ((base) + (0x00B4UL))
#define SOC_BUSMON_STP_RFU_CTRL_ADDR(base) ((base) + (0x00B8UL))
#define SOC_BUSMON_STP_RFU_STAT_ADDR(base) ((base) + (0x00BCUL))
#define SOC_BUSMON_ATB_CTRL_STAT0_ADDR(base) ((base) + (0x00C0UL))
#else
#define SOC_BUSMON_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_BUSMON_CTRL_STAT0_ADDR(base) ((base) + (0x0004))
#define SOC_BUSMON_SYNC_INTERNAL_ADDR(base) ((base) + (0x0008))
#define SOC_BUSMON_TS_INTERNAL_ADDR(base) ((base) + (0x000c))
#define SOC_BUSMON_MEM_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_ADDR(base) ((base) + (0x0020))
#define SOC_BUSMON_TRIGGER_SETTING0_ADDR(base) ((base) + (0x0024))
#define SOC_BUSMON_TRIGGER_SETTING1_ADDR(base) ((base) + (0x0028))
#define SOC_BUSMON_TRIGGER_SETTING2_ADDR(base) ((base) + (0x002C))
#define SOC_BUSMON_TRIGGER_SETTING3_ADDR(base) ((base) + (0x0030))
#define SOC_BUSMON_TRIGGER_SETTING4_ADDR(base) ((base) + (0x0034))
#define SOC_BUSMON_TRIGGER_SETTING5_ADDR(base) ((base) + (0x0038))
#define SOC_BUSMON_TRIGGER_SETTING6_ADDR(base) ((base) + (0x003C))
#define SOC_BUSMON_TRIGGER_SETTING7_ADDR(base) ((base) + (0x0040))
#define SOC_BUSMON_TRIGGER_SETTING8_ADDR(base) ((base) + (0x0044))
#define SOC_BUSMON_TRIGGER_SETTING9_ADDR(base) ((base) + (0x0048))
#define SOC_BUSMON_TRIGGER_SETTING10_ADDR(base) ((base) + (0x004C))
#define SOC_BUSMON_TRIGGER_SETTING11_ADDR(base) ((base) + (0x0050))
#define SOC_BUSMON_TRIGGER_SETTING12_ADDR(base) ((base) + (0x0054))
#define SOC_BUSMON_TRIGGER_SETTING13_ADDR(base) ((base) + (0x0058))
#define SOC_BUSMON_TRIGGER_SETTING14_ADDR(base) ((base) + (0x005C))
#define SOC_BUSMON_TRIGGER_SETTING15_ADDR(base) ((base) + (0x0060))
#define SOC_BUSMON_TRIGGER_SETTING16_ADDR(base) ((base) + (0x0064))
#define SOC_BUSMON_TRIGGER_SETTING17_ADDR(base) ((base) + (0x0068))
#define SOC_BUSMON_TRIGGER_SETTING18_ADDR(base) ((base) + (0x006C))
#define SOC_BUSMON_TRIGGER_SETTING19_ADDR(base) ((base) + (0x0070))
#define SOC_BUSMON_TRIGGER_SETTING20_ADDR(base) ((base) + (0x0074))
#define SOC_BUSMON_TRIGGER_SETTING21_ADDR(base) ((base) + (0x0078))
#define SOC_BUSMON_TRIGGER_SETTING22_ADDR(base) ((base) + (0x007C))
#define SOC_BUSMON_TRIGGER_SETTING23_ADDR(base) ((base) + (0x0080))
#define SOC_BUSMON_TRIGGER_SETTING24_ADDR(base) ((base) + (0x0084))
#define SOC_BUSMON_TRIGGER_SETTING25_ADDR(base) ((base) + (0x0088))
#define SOC_BUSMON_TRIGGER_SETTING26_ADDR(base) ((base) + (0x008C))
#define SOC_BUSMON_TRIGGER_SETTING27_ADDR(base) ((base) + (0x0090))
#define SOC_BUSMON_TRIGGER_TIMER_ADDR(base) ((base) + (0x0094))
#define SOC_BUSMON_TRIGGER_RFU_CTRL_ADDR(base) ((base) + (0x0098))
#define SOC_BUSMON_TRIGGER_RUF_STAT_ADDR(base) ((base) + (0x009C))
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_ADDR(base) ((base) + (0x00A0))
#define SOC_BUSMON_SAMPLE_RFU_CTRL_ADDR(base) ((base) + (0x00A4))
#define SOC_BUSMON_SAMPLE_RFU_STAT_ADDR(base) ((base) + (0x00A8))
#define SOC_BUSMON_STP_CTRL0_ADDR(base) ((base) + (0x00B0))
#define SOC_BUSMON_STP_STAT0_ADDR(base) ((base) + (0x00B4))
#define SOC_BUSMON_STP_RFU_CTRL_ADDR(base) ((base) + (0x00B8))
#define SOC_BUSMON_STP_RFU_STAT_ADDR(base) ((base) + (0x00BC))
#define SOC_BUSMON_ATB_CTRL_STAT0_ADDR(base) ((base) + (0x00C0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version : 32;
    } reg;
} SOC_BUSMON_VERSION_UNION;
#endif
#define SOC_BUSMON_VERSION_version_START (0)
#define SOC_BUSMON_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start : 1;
        unsigned int stop : 1;
        unsigned int cnt_limit_axi : 3;
        unsigned int cnt_limit_atb : 3;
        unsigned int reserved_0 : 8;
        unsigned int trigger_done : 1;
        unsigned int afifo_overflow : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_BUSMON_CTRL_STAT0_UNION;
#endif
#define SOC_BUSMON_CTRL_STAT0_start_START (0)
#define SOC_BUSMON_CTRL_STAT0_start_END (0)
#define SOC_BUSMON_CTRL_STAT0_stop_START (1)
#define SOC_BUSMON_CTRL_STAT0_stop_END (1)
#define SOC_BUSMON_CTRL_STAT0_cnt_limit_axi_START (2)
#define SOC_BUSMON_CTRL_STAT0_cnt_limit_axi_END (4)
#define SOC_BUSMON_CTRL_STAT0_cnt_limit_atb_START (5)
#define SOC_BUSMON_CTRL_STAT0_cnt_limit_atb_END (7)
#define SOC_BUSMON_CTRL_STAT0_trigger_done_START (16)
#define SOC_BUSMON_CTRL_STAT0_trigger_done_END (16)
#define SOC_BUSMON_CTRL_STAT0_afifo_overflow_START (17)
#define SOC_BUSMON_CTRL_STAT0_afifo_overflow_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sync_internal : 32;
    } reg;
} SOC_BUSMON_SYNC_INTERNAL_UNION;
#endif
#define SOC_BUSMON_SYNC_INTERNAL_sync_internal_START (0)
#define SOC_BUSMON_SYNC_INTERNAL_sync_internal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_internal : 32;
    } reg;
} SOC_BUSMON_TS_INTERNAL_UNION;
#endif
#define SOC_BUSMON_TS_INTERNAL_ts_internal_START (0)
#define SOC_BUSMON_TS_INTERNAL_ts_internal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_BUSMON_MEM_CTRL_UNION;
#endif
#define SOC_BUSMON_MEM_CTRL_mem_ctrl_d1w2r_START (0)
#define SOC_BUSMON_MEM_CTRL_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trigger_en : 1;
        unsigned int arch_trigger_en : 1;
        unsigned int awch_trigger_en : 1;
        unsigned int rch_trigger_en : 1;
        unsigned int wch_trigger_en : 1;
        unsigned int bch_trigger_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_BUSMON_TRIGGER_CTRL_STAT0_UNION;
#endif
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_trigger_en_START (0)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_trigger_en_END (0)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_arch_trigger_en_START (1)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_arch_trigger_en_END (1)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_awch_trigger_en_START (2)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_awch_trigger_en_END (2)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_rch_trigger_en_START (3)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_rch_trigger_en_END (3)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_wch_trigger_en_START (4)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_wch_trigger_en_END (4)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_bch_trigger_en_START (5)
#define SOC_BUSMON_TRIGGER_CTRL_STAT0_bch_trigger_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_aruser : 16;
        unsigned int ref_arid : 16;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING0_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING0_ref_aruser_START (0)
#define SOC_BUSMON_TRIGGER_SETTING0_ref_aruser_END (15)
#define SOC_BUSMON_TRIGGER_SETTING0_ref_arid_START (16)
#define SOC_BUSMON_TRIGGER_SETTING0_ref_arid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_arlen : 1;
        unsigned int ref_arlen : 4;
        unsigned int trig_arsize : 1;
        unsigned int ref_arsize : 3;
        unsigned int trig_arburst : 1;
        unsigned int ref_arburst : 2;
        unsigned int trig_arlock : 1;
        unsigned int ref_arlock : 2;
        unsigned int trig_arcache : 1;
        unsigned int ref_arcache : 4;
        unsigned int trig_arprot : 1;
        unsigned int ref_arprot : 3;
        unsigned int trig_arvalid : 1;
        unsigned int ref_arvalid : 1;
        unsigned int trig_arready : 1;
        unsigned int ref_arready : 1;
        unsigned int trig_aruser : 1;
        unsigned int trig_arid : 1;
        unsigned int trig_araddr : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING1_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arlen_START (0)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arlen_END (0)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arlen_START (1)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arlen_END (4)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arsize_START (5)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arsize_END (5)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arsize_START (6)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arsize_END (8)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arburst_START (9)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arburst_END (9)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arburst_START (10)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arburst_END (11)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arlock_START (12)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arlock_END (12)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arlock_START (13)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arlock_END (14)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arcache_START (15)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arcache_END (15)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arcache_START (16)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arcache_END (19)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arprot_START (20)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arprot_END (20)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arprot_START (21)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arprot_END (23)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arvalid_START (24)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arvalid_END (24)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arvalid_START (25)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arvalid_END (25)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arready_START (26)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arready_END (26)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arready_START (27)
#define SOC_BUSMON_TRIGGER_SETTING1_ref_arready_END (27)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_aruser_START (28)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_aruser_END (28)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arid_START (29)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_arid_END (29)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_araddr_START (30)
#define SOC_BUSMON_TRIGGER_SETTING1_trig_araddr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_araddr_lo : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING2_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING2_ref_araddr_lo_START (0)
#define SOC_BUSMON_TRIGGER_SETTING2_ref_araddr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_araddr_hi : 16;
        unsigned int ref_aruser_hi : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING3_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING3_ref_araddr_hi_START (0)
#define SOC_BUSMON_TRIGGER_SETTING3_ref_araddr_hi_END (15)
#define SOC_BUSMON_TRIGGER_SETTING3_ref_aruser_hi_START (16)
#define SOC_BUSMON_TRIGGER_SETTING3_ref_aruser_hi_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_awuser : 16;
        unsigned int ref_awid : 16;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING4_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING4_ref_awuser_START (0)
#define SOC_BUSMON_TRIGGER_SETTING4_ref_awuser_END (15)
#define SOC_BUSMON_TRIGGER_SETTING4_ref_awid_START (16)
#define SOC_BUSMON_TRIGGER_SETTING4_ref_awid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_awlen : 1;
        unsigned int ref_awlen : 4;
        unsigned int trig_awsize : 1;
        unsigned int ref_awsize : 3;
        unsigned int trig_awburst : 1;
        unsigned int ref_awburst : 2;
        unsigned int trig_awlock : 1;
        unsigned int ref_awlock : 2;
        unsigned int trig_awcache : 1;
        unsigned int ref_awcache : 4;
        unsigned int trig_awprot : 1;
        unsigned int ref_awprot : 3;
        unsigned int trig_awvalid : 1;
        unsigned int ref_awvalid : 1;
        unsigned int trig_awready : 1;
        unsigned int ref_awready : 1;
        unsigned int trig_awuser : 1;
        unsigned int trig_awid : 1;
        unsigned int trig_awaddr : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING5_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awlen_START (0)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awlen_END (0)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awlen_START (1)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awlen_END (4)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awsize_START (5)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awsize_END (5)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awsize_START (6)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awsize_END (8)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awburst_START (9)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awburst_END (9)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awburst_START (10)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awburst_END (11)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awlock_START (12)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awlock_END (12)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awlock_START (13)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awlock_END (14)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awcache_START (15)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awcache_END (15)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awcache_START (16)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awcache_END (19)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awprot_START (20)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awprot_END (20)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awprot_START (21)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awprot_END (23)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awvalid_START (24)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awvalid_END (24)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awvalid_START (25)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awvalid_END (25)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awready_START (26)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awready_END (26)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awready_START (27)
#define SOC_BUSMON_TRIGGER_SETTING5_ref_awready_END (27)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awuser_START (28)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awuser_END (28)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awid_START (29)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awid_END (29)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awaddr_START (30)
#define SOC_BUSMON_TRIGGER_SETTING5_trig_awaddr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_awaddr_lo : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING6_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING6_ref_awaddr_lo_START (0)
#define SOC_BUSMON_TRIGGER_SETTING6_ref_awaddr_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_awaddr_hi : 16;
        unsigned int ref_awuser_hi : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING7_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING7_ref_awaddr_hi_START (0)
#define SOC_BUSMON_TRIGGER_SETTING7_ref_awaddr_hi_END (15)
#define SOC_BUSMON_TRIGGER_SETTING7_ref_awuser_hi_START (16)
#define SOC_BUSMON_TRIGGER_SETTING7_ref_awuser_hi_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_rid : 1;
        unsigned int ref_rid : 16;
        unsigned int trig_rresp : 1;
        unsigned int ref_rresp : 2;
        unsigned int trig_rvalid : 1;
        unsigned int ref_rvalid : 1;
        unsigned int trig_rready : 1;
        unsigned int ref_rready : 1;
        unsigned int trig_rlast : 1;
        unsigned int ref_rlast : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING8_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rid_START (0)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rid_END (0)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rid_START (1)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rid_END (16)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rresp_START (17)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rresp_END (17)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rresp_START (18)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rresp_END (19)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rvalid_START (20)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rvalid_END (20)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rvalid_START (21)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rvalid_END (21)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rready_START (22)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rready_END (22)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rready_START (23)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rready_END (23)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rlast_START (24)
#define SOC_BUSMON_TRIGGER_SETTING8_trig_rlast_END (24)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rlast_START (25)
#define SOC_BUSMON_TRIGGER_SETTING8_ref_rlast_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_rdata0 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING9_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING9_ref_rdata0_START (0)
#define SOC_BUSMON_TRIGGER_SETTING9_ref_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_rdata1 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING10_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING10_ref_rdata1_START (0)
#define SOC_BUSMON_TRIGGER_SETTING10_ref_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_rdata2 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING11_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING11_ref_rdata2_START (0)
#define SOC_BUSMON_TRIGGER_SETTING11_ref_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_rdata3 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING12_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING12_ref_rdata3_START (0)
#define SOC_BUSMON_TRIGGER_SETTING12_ref_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_rdata0 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING13_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING13_trig_rdata0_START (0)
#define SOC_BUSMON_TRIGGER_SETTING13_trig_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_rdata1 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING14_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING14_trig_rdata1_START (0)
#define SOC_BUSMON_TRIGGER_SETTING14_trig_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_rdata2 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING15_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING15_trig_rdata2_START (0)
#define SOC_BUSMON_TRIGGER_SETTING15_trig_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_rdata3 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING16_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING16_trig_rdata3_START (0)
#define SOC_BUSMON_TRIGGER_SETTING16_trig_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wid : 1;
        unsigned int ref_wid : 16;
        unsigned int trig_wvalid : 1;
        unsigned int ref_wvalid : 1;
        unsigned int trig_wready : 1;
        unsigned int ref_wready : 1;
        unsigned int trig_wlast : 1;
        unsigned int ref_wlast : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING17_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wid_START (0)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wid_END (0)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wid_START (1)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wid_END (16)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wvalid_START (17)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wvalid_END (17)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wvalid_START (18)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wvalid_END (18)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wready_START (19)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wready_END (19)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wready_START (20)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wready_END (20)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wlast_START (21)
#define SOC_BUSMON_TRIGGER_SETTING17_trig_wlast_END (21)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wlast_START (22)
#define SOC_BUSMON_TRIGGER_SETTING17_ref_wlast_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_wdata0 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING18_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING18_ref_wdata0_START (0)
#define SOC_BUSMON_TRIGGER_SETTING18_ref_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_wdata1 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING19_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING19_ref_wdata1_START (0)
#define SOC_BUSMON_TRIGGER_SETTING19_ref_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_wdata2 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING20_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING20_ref_wdata2_START (0)
#define SOC_BUSMON_TRIGGER_SETTING20_ref_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_wdata3 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING21_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING21_ref_wdata3_START (0)
#define SOC_BUSMON_TRIGGER_SETTING21_ref_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wdata0 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING22_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING22_trig_wdata0_START (0)
#define SOC_BUSMON_TRIGGER_SETTING22_trig_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wdata1 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING23_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING23_trig_wdata1_START (0)
#define SOC_BUSMON_TRIGGER_SETTING23_trig_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wdata2 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING24_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING24_trig_wdata2_START (0)
#define SOC_BUSMON_TRIGGER_SETTING24_trig_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wdata3 : 32;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING25_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING25_trig_wdata3_START (0)
#define SOC_BUSMON_TRIGGER_SETTING25_trig_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_wstrb : 1;
        unsigned int ref_wstrb : 16;
        unsigned int reserved : 15;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING26_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING26_trig_wstrb_START (0)
#define SOC_BUSMON_TRIGGER_SETTING26_trig_wstrb_END (0)
#define SOC_BUSMON_TRIGGER_SETTING26_ref_wstrb_START (1)
#define SOC_BUSMON_TRIGGER_SETTING26_ref_wstrb_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trig_bid : 1;
        unsigned int ref_bid : 16;
        unsigned int trig_bresp : 1;
        unsigned int ref_bresp : 2;
        unsigned int trig_bvalid : 1;
        unsigned int ref_bvalid : 1;
        unsigned int trig_bready : 1;
        unsigned int ref_bready : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_BUSMON_TRIGGER_SETTING27_UNION;
#endif
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bid_START (0)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bid_END (0)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bid_START (1)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bid_END (16)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bresp_START (17)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bresp_END (17)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bresp_START (18)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bresp_END (19)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bvalid_START (20)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bvalid_END (20)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bvalid_START (21)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bvalid_END (21)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bready_START (22)
#define SOC_BUSMON_TRIGGER_SETTING27_trig_bready_END (22)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bready_START (23)
#define SOC_BUSMON_TRIGGER_SETTING27_ref_bready_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trigger_timer_any : 16;
        unsigned int trigger_timer_data : 16;
    } reg;
} SOC_BUSMON_TRIGGER_TIMER_UNION;
#endif
#define SOC_BUSMON_TRIGGER_TIMER_trigger_timer_any_START (0)
#define SOC_BUSMON_TRIGGER_TIMER_trigger_timer_any_END (15)
#define SOC_BUSMON_TRIGGER_TIMER_trigger_timer_data_START (16)
#define SOC_BUSMON_TRIGGER_TIMER_trigger_timer_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trigger_rfu_ctrl : 32;
    } reg;
} SOC_BUSMON_TRIGGER_RFU_CTRL_UNION;
#endif
#define SOC_BUSMON_TRIGGER_RFU_CTRL_trigger_rfu_ctrl_START (0)
#define SOC_BUSMON_TRIGGER_RFU_CTRL_trigger_rfu_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trigger_rfu_stat : 32;
    } reg;
} SOC_BUSMON_TRIGGER_RUF_STAT_UNION;
#endif
#define SOC_BUSMON_TRIGGER_RUF_STAT_trigger_rfu_stat_START (0)
#define SOC_BUSMON_TRIGGER_RUF_STAT_trigger_rfu_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_raw : 1;
        unsigned int force_raw_ar : 1;
        unsigned int force_raw_aw : 1;
        unsigned int force_raw_r : 1;
        unsigned int force_raw_w : 1;
        unsigned int force_raw_b : 1;
        unsigned int sample_rd_en : 1;
        unsigned int sample_wd_en : 1;
        unsigned int burst_msk : 1;
        unsigned int lock_msk : 1;
        unsigned int prot_msk : 1;
        unsigned int size_msk : 1;
        unsigned int len_msk : 1;
        unsigned int cache_msk : 1;
        unsigned int user_msk : 1;
        unsigned int id_msk : 1;
        unsigned int wstrb_msk : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_BUSMON_SAMPLE_CTRL_STAT0_UNION;
#endif
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_START (0)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_END (0)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_ar_START (1)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_ar_END (1)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_aw_START (2)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_aw_END (2)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_r_START (3)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_r_END (3)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_w_START (4)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_w_END (4)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_b_START (5)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_force_raw_b_END (5)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_sample_rd_en_START (6)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_sample_rd_en_END (6)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_sample_wd_en_START (7)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_sample_wd_en_END (7)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_burst_msk_START (8)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_burst_msk_END (8)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_lock_msk_START (9)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_lock_msk_END (9)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_prot_msk_START (10)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_prot_msk_END (10)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_size_msk_START (11)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_size_msk_END (11)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_len_msk_START (12)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_len_msk_END (12)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_cache_msk_START (13)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_cache_msk_END (13)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_user_msk_START (14)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_user_msk_END (14)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_id_msk_START (15)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_id_msk_END (15)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_wstrb_msk_START (16)
#define SOC_BUSMON_SAMPLE_CTRL_STAT0_wstrb_msk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_rfu_ctrl : 32;
    } reg;
} SOC_BUSMON_SAMPLE_RFU_CTRL_UNION;
#endif
#define SOC_BUSMON_SAMPLE_RFU_CTRL_sample_rfu_ctrl_START (0)
#define SOC_BUSMON_SAMPLE_RFU_CTRL_sample_rfu_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_rfu_stat : 32;
    } reg;
} SOC_BUSMON_SAMPLE_RFU_STAT_UNION;
#endif
#define SOC_BUSMON_SAMPLE_RFU_STAT_sample_rfu_stat_START (0)
#define SOC_BUSMON_SAMPLE_RFU_STAT_sample_rfu_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stp_ext : 1;
        unsigned int ts_fmt : 3;
        unsigned int is_le : 1;
        unsigned int version_pd : 6;
        unsigned int stp_version : 1;
        unsigned int ts_len : 4;
        unsigned int out_data_inv : 1;
        unsigned int stp_inv_en : 1;
        unsigned int stream_inv_en : 1;
        unsigned int indata_inv_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_BUSMON_STP_CTRL0_UNION;
#endif
#define SOC_BUSMON_STP_CTRL0_stp_ext_START (0)
#define SOC_BUSMON_STP_CTRL0_stp_ext_END (0)
#define SOC_BUSMON_STP_CTRL0_ts_fmt_START (1)
#define SOC_BUSMON_STP_CTRL0_ts_fmt_END (3)
#define SOC_BUSMON_STP_CTRL0_is_le_START (4)
#define SOC_BUSMON_STP_CTRL0_is_le_END (4)
#define SOC_BUSMON_STP_CTRL0_version_pd_START (5)
#define SOC_BUSMON_STP_CTRL0_version_pd_END (10)
#define SOC_BUSMON_STP_CTRL0_stp_version_START (11)
#define SOC_BUSMON_STP_CTRL0_stp_version_END (11)
#define SOC_BUSMON_STP_CTRL0_ts_len_START (12)
#define SOC_BUSMON_STP_CTRL0_ts_len_END (15)
#define SOC_BUSMON_STP_CTRL0_out_data_inv_START (16)
#define SOC_BUSMON_STP_CTRL0_out_data_inv_END (16)
#define SOC_BUSMON_STP_CTRL0_stp_inv_en_START (17)
#define SOC_BUSMON_STP_CTRL0_stp_inv_en_END (17)
#define SOC_BUSMON_STP_CTRL0_stream_inv_en_START (18)
#define SOC_BUSMON_STP_CTRL0_stream_inv_en_END (18)
#define SOC_BUSMON_STP_CTRL0_indata_inv_en_START (19)
#define SOC_BUSMON_STP_CTRL0_indata_inv_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_BUSMON_STP_STAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stp_rfu_ctrl : 32;
    } reg;
} SOC_BUSMON_STP_RFU_CTRL_UNION;
#endif
#define SOC_BUSMON_STP_RFU_CTRL_stp_rfu_ctrl_START (0)
#define SOC_BUSMON_STP_RFU_CTRL_stp_rfu_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stp_rfu_stat : 32;
    } reg;
} SOC_BUSMON_STP_RFU_STAT_UNION;
#endif
#define SOC_BUSMON_STP_RFU_STAT_stp_rfu_stat_START (0)
#define SOC_BUSMON_STP_RFU_STAT_stp_rfu_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_atid : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_BUSMON_ATB_CTRL_STAT0_UNION;
#endif
#define SOC_BUSMON_ATB_CTRL_STAT0_cfg_atid_START (0)
#define SOC_BUSMON_ATB_CTRL_STAT0_cfg_atid_END (6)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
