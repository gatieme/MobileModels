#ifndef __SOC_NPU_L2BUF_INTERFACE_H__
#define __SOC_NPU_L2BUF_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_L2BUF_SMC_LOCK_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_L2BUF_SMC_MEM_LP_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_L2BUF_GCLK_CS_ADDR(base) ((base) + (0x000cUL))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_L2BUF_SMC_CS_IDLE_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_ADDR(base) ((base) + (0x003CUL))
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_ADDR(base) ((base) + (0x0054UL))
#else
#define SOC_NPU_L2BUF_SMC_LOCK_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_L2BUF_SMC_MEM_LP_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_L2BUF_GCLK_CS_ADDR(base) ((base) + (0x000c))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_L2BUF_SMC_CS_IDLE_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_ADDR(base) ((base) + (0x003C))
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_ADDR(base) ((base) + (0x0054))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_lock : 32;
    } reg;
} SOC_NPU_L2BUF_SMC_LOCK_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_LOCK_smc_lock_START (0)
#define SOC_NPU_L2BUF_SMC_LOCK_smc_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_ls_en : 1;
        unsigned int smc_ds_en : 1;
        unsigned int lp_exit_cycle : 6;
        unsigned int lp_enter_cycle : 16;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_L2BUF_SMC_MEM_LP_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_MEM_LP_smc_ls_en_START (0)
#define SOC_NPU_L2BUF_SMC_MEM_LP_smc_ls_en_END (0)
#define SOC_NPU_L2BUF_SMC_MEM_LP_smc_ds_en_START (1)
#define SOC_NPU_L2BUF_SMC_MEM_LP_smc_ds_en_END (1)
#define SOC_NPU_L2BUF_SMC_MEM_LP_lp_exit_cycle_START (2)
#define SOC_NPU_L2BUF_SMC_MEM_LP_lp_exit_cycle_END (7)
#define SOC_NPU_L2BUF_SMC_MEM_LP_lp_enter_cycle_START (8)
#define SOC_NPU_L2BUF_SMC_MEM_LP_lp_enter_cycle_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_s0_clock_disable : 1;
        unsigned int axi_s1_clock_disable : 1;
        unsigned int axi_s2_clock_disable : 1;
        unsigned int axi_s3_clock_disable : 1;
        unsigned int axi_s4_clock_disable : 1;
        unsigned int axi_s5_clock_disable : 1;
        unsigned int axi_s6_clock_disable : 1;
        unsigned int axi_s7_clock_disable : 1;
        unsigned int axi_s8_clock_disable : 1;
        unsigned int axi_s9_clock_disable : 1;
        unsigned int axi_s10_clock_disable : 1;
        unsigned int axi_s11_clock_disable : 1;
        unsigned int axi_s12_clock_disable : 1;
        unsigned int axi_s13_clock_disable : 1;
        unsigned int axi_s14_clock_disable : 1;
        unsigned int axi_s15_clock_disable : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_L2BUF_GCLK_CS_UNION;
#endif
#define SOC_NPU_L2BUF_GCLK_CS_axi_s0_clock_disable_START (0)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s0_clock_disable_END (0)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s1_clock_disable_START (1)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s1_clock_disable_END (1)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s2_clock_disable_START (2)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s2_clock_disable_END (2)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s3_clock_disable_START (3)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s3_clock_disable_END (3)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s4_clock_disable_START (4)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s4_clock_disable_END (4)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s5_clock_disable_START (5)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s5_clock_disable_END (5)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s6_clock_disable_START (6)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s6_clock_disable_END (6)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s7_clock_disable_START (7)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s7_clock_disable_END (7)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s8_clock_disable_START (8)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s8_clock_disable_END (8)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s9_clock_disable_START (9)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s9_clock_disable_END (9)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s10_clock_disable_START (10)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s10_clock_disable_END (10)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s11_clock_disable_START (11)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s11_clock_disable_END (11)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s12_clock_disable_START (12)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s12_clock_disable_END (12)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s13_clock_disable_START (13)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s13_clock_disable_END (13)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s14_clock_disable_START (14)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s14_clock_disable_END (14)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s15_clock_disable_START (15)
#define SOC_NPU_L2BUF_GCLK_CS_axi_s15_clock_disable_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs0_wcmd_cnt_1st : 4;
        unsigned int dfx_cs0_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs1_wcmd_cnt_1st : 4;
        unsigned int dfx_cs1_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs2_wcmd_cnt_1st : 4;
        unsigned int dfx_cs2_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs3_wcmd_cnt_1st : 4;
        unsigned int dfx_cs3_wcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs0_wcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs0_wcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs0_wcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs0_wcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs1_wcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs1_wcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs1_wcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs1_wcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs2_wcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs2_wcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs2_wcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs2_wcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs3_wcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs3_wcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs3_wcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_1ST_dfx_cs3_wcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs4_wcmd_cnt_1st : 4;
        unsigned int dfx_cs4_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs5_wcmd_cnt_1st : 4;
        unsigned int dfx_cs5_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs6_wcmd_cnt_1st : 4;
        unsigned int dfx_cs6_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs7_wcmd_cnt_1st : 4;
        unsigned int dfx_cs7_wcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs4_wcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs4_wcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs4_wcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs4_wcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs5_wcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs5_wcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs5_wcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs5_wcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs6_wcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs6_wcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs6_wcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs6_wcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs7_wcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs7_wcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs7_wcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_2ND_dfx_cs7_wcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs8_wcmd_cnt_1st : 4;
        unsigned int dfx_cs8_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs9_wcmd_cnt_1st : 4;
        unsigned int dfx_cs9_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs10_wcmd_cnt_1st : 4;
        unsigned int dfx_cs10_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs11_wcmd_cnt_1st : 4;
        unsigned int dfx_cs11_wcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs8_wcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs8_wcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs8_wcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs8_wcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs9_wcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs9_wcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs9_wcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs9_wcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs10_wcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs10_wcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs10_wcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs10_wcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs11_wcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs11_wcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs11_wcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_3RD_dfx_cs11_wcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs12_wcmd_cnt_1st : 4;
        unsigned int dfx_cs12_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs13_wcmd_cnt_1st : 4;
        unsigned int dfx_cs13_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs14_wcmd_cnt_1st : 4;
        unsigned int dfx_cs14_wcmd_cnt_2nd : 4;
        unsigned int dfx_cs15_wcmd_cnt_1st : 4;
        unsigned int dfx_cs15_wcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs12_wcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs12_wcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs12_wcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs12_wcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs13_wcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs13_wcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs13_wcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs13_wcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs14_wcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs14_wcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs14_wcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs14_wcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs15_wcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs15_wcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs15_wcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_WCMD_CNT_4TH_dfx_cs15_wcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs0_rcmd_cnt_1st : 4;
        unsigned int dfx_cs0_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs1_rcmd_cnt_1st : 4;
        unsigned int dfx_cs1_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs2_rcmd_cnt_1st : 4;
        unsigned int dfx_cs2_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs3_rcmd_cnt_1st : 4;
        unsigned int dfx_cs3_rcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs0_rcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs0_rcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs0_rcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs0_rcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs1_rcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs1_rcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs1_rcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs1_rcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs2_rcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs2_rcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs2_rcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs2_rcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs3_rcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs3_rcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs3_rcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_1ST_dfx_cs3_rcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs4_rcmd_cnt_1st : 4;
        unsigned int dfx_cs4_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs5_rcmd_cnt_1st : 4;
        unsigned int dfx_cs5_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs6_rcmd_cnt_1st : 4;
        unsigned int dfx_cs6_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs7_rcmd_cnt_1st : 4;
        unsigned int dfx_cs7_rcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs4_rcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs4_rcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs4_rcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs4_rcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs5_rcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs5_rcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs5_rcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs5_rcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs6_rcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs6_rcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs6_rcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs6_rcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs7_rcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs7_rcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs7_rcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_2ND_dfx_cs7_rcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs8_rcmd_cnt_1st : 4;
        unsigned int dfx_cs8_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs9_rcmd_cnt_1st : 4;
        unsigned int dfx_cs9_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs10_rcmd_cnt_1st : 4;
        unsigned int dfx_cs10_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs11_rcmd_cnt_1st : 4;
        unsigned int dfx_cs11_rcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs8_rcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs8_rcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs8_rcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs8_rcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs9_rcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs9_rcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs9_rcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs9_rcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs10_rcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs10_rcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs10_rcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs10_rcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs11_rcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs11_rcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs11_rcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_3RD_dfx_cs11_rcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs12_rcmd_cnt_1st : 4;
        unsigned int dfx_cs12_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs13_rcmd_cnt_1st : 4;
        unsigned int dfx_cs13_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs14_rcmd_cnt_1st : 4;
        unsigned int dfx_cs14_rcmd_cnt_2nd : 4;
        unsigned int dfx_cs15_rcmd_cnt_1st : 4;
        unsigned int dfx_cs15_rcmd_cnt_2nd : 4;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs12_rcmd_cnt_1st_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs12_rcmd_cnt_1st_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs12_rcmd_cnt_2nd_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs12_rcmd_cnt_2nd_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs13_rcmd_cnt_1st_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs13_rcmd_cnt_1st_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs13_rcmd_cnt_2nd_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs13_rcmd_cnt_2nd_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs14_rcmd_cnt_1st_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs14_rcmd_cnt_1st_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs14_rcmd_cnt_2nd_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs14_rcmd_cnt_2nd_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs15_rcmd_cnt_1st_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs15_rcmd_cnt_1st_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs15_rcmd_cnt_2nd_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_RCMD_CNT_4TH_dfx_cs15_rcmd_cnt_2nd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs0_idle : 1;
        unsigned int dfx_cs1_idle : 1;
        unsigned int dfx_cs2_idle : 1;
        unsigned int dfx_cs3_idle : 1;
        unsigned int dfx_cs4_idle : 1;
        unsigned int dfx_cs5_idle : 1;
        unsigned int dfx_cs6_idle : 1;
        unsigned int dfx_cs7_idle : 1;
        unsigned int dfx_cs8_idle : 1;
        unsigned int dfx_cs9_idle : 1;
        unsigned int dfx_cs10_idle : 1;
        unsigned int dfx_cs11_idle : 1;
        unsigned int dfx_cs12_idle : 1;
        unsigned int dfx_cs13_idle : 1;
        unsigned int dfx_cs14_idle : 1;
        unsigned int dfx_cs15_idle : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_L2BUF_SMC_CS_IDLE_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs0_idle_START (0)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs0_idle_END (0)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs1_idle_START (1)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs1_idle_END (1)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs2_idle_START (2)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs2_idle_END (2)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs3_idle_START (3)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs3_idle_END (3)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs4_idle_START (4)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs4_idle_END (4)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs5_idle_START (5)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs5_idle_END (5)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs6_idle_START (6)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs6_idle_END (6)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs7_idle_START (7)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs7_idle_END (7)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs8_idle_START (8)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs8_idle_END (8)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs9_idle_START (9)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs9_idle_END (9)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs10_idle_START (10)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs10_idle_END (10)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs11_idle_START (11)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs11_idle_END (11)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs12_idle_START (12)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs12_idle_END (12)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs13_idle_START (13)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs13_idle_END (13)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs14_idle_START (14)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs14_idle_END (14)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs15_idle_START (15)
#define SOC_NPU_L2BUF_SMC_CS_IDLE_dfx_cs15_idle_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs0_bfifo_cnt : 2;
        unsigned int dfx_cs1_bfifo_cnt : 2;
        unsigned int dfx_cs2_bfifo_cnt : 2;
        unsigned int dfx_cs3_bfifo_cnt : 2;
        unsigned int dfx_cs4_bfifo_cnt : 2;
        unsigned int dfx_cs5_bfifo_cnt : 2;
        unsigned int dfx_cs6_bfifo_cnt : 2;
        unsigned int dfx_cs7_bfifo_cnt : 2;
        unsigned int dfx_cs8_bfifo_cnt : 2;
        unsigned int dfx_cs9_bfifo_cnt : 2;
        unsigned int dfx_cs10_bfifo_cnt : 2;
        unsigned int dfx_cs11_bfifo_cnt : 2;
        unsigned int dfx_cs12_bfifo_cnt : 2;
        unsigned int dfx_cs13_bfifo_cnt : 2;
        unsigned int dfx_cs14_bfifo_cnt : 2;
        unsigned int dfx_cs15_bfifo_cnt : 2;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs0_bfifo_cnt_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs0_bfifo_cnt_END (1)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs1_bfifo_cnt_START (2)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs1_bfifo_cnt_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs2_bfifo_cnt_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs2_bfifo_cnt_END (5)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs3_bfifo_cnt_START (6)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs3_bfifo_cnt_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs4_bfifo_cnt_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs4_bfifo_cnt_END (9)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs5_bfifo_cnt_START (10)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs5_bfifo_cnt_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs6_bfifo_cnt_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs6_bfifo_cnt_END (13)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs7_bfifo_cnt_START (14)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs7_bfifo_cnt_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs8_bfifo_cnt_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs8_bfifo_cnt_END (17)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs9_bfifo_cnt_START (18)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs9_bfifo_cnt_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs10_bfifo_cnt_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs10_bfifo_cnt_END (21)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs11_bfifo_cnt_START (22)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs11_bfifo_cnt_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs12_bfifo_cnt_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs12_bfifo_cnt_END (25)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs13_bfifo_cnt_START (26)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs13_bfifo_cnt_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs14_bfifo_cnt_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs14_bfifo_cnt_END (29)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs15_bfifo_cnt_START (30)
#define SOC_NPU_L2BUF_SMC_DFX_BFIFO_CNT0_dfx_cs15_bfifo_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cs0_rdfifo_cnt : 2;
        unsigned int dfx_cs1_rdfifo_cnt : 2;
        unsigned int dfx_cs2_rdfifo_cnt : 2;
        unsigned int dfx_cs3_rdfifo_cnt : 2;
        unsigned int dfx_cs4_rdfifo_cnt : 2;
        unsigned int dfx_cs5_rdfifo_cnt : 2;
        unsigned int dfx_cs6_rdfifo_cnt : 2;
        unsigned int dfx_cs7_rdfifo_cnt : 2;
        unsigned int dfx_cs8_rdfifo_cnt : 2;
        unsigned int dfx_cs9_rdfifo_cnt : 2;
        unsigned int dfx_cs10_rdfifo_cnt : 2;
        unsigned int dfx_cs11_rdfifo_cnt : 2;
        unsigned int dfx_cs12_rdfifo_cnt : 2;
        unsigned int dfx_cs13_rdfifo_cnt : 2;
        unsigned int dfx_cs14_rdfifo_cnt : 2;
        unsigned int dfx_cs15_rdfifo_cnt : 2;
    } reg;
} SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs0_rdfifo_cnt_START (0)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs0_rdfifo_cnt_END (1)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs1_rdfifo_cnt_START (2)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs1_rdfifo_cnt_END (3)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs2_rdfifo_cnt_START (4)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs2_rdfifo_cnt_END (5)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs3_rdfifo_cnt_START (6)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs3_rdfifo_cnt_END (7)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs4_rdfifo_cnt_START (8)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs4_rdfifo_cnt_END (9)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs5_rdfifo_cnt_START (10)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs5_rdfifo_cnt_END (11)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs6_rdfifo_cnt_START (12)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs6_rdfifo_cnt_END (13)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs7_rdfifo_cnt_START (14)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs7_rdfifo_cnt_END (15)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs8_rdfifo_cnt_START (16)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs8_rdfifo_cnt_END (17)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs9_rdfifo_cnt_START (18)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs9_rdfifo_cnt_END (19)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs10_rdfifo_cnt_START (20)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs10_rdfifo_cnt_END (21)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs11_rdfifo_cnt_START (22)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs11_rdfifo_cnt_END (23)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs12_rdfifo_cnt_START (24)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs12_rdfifo_cnt_END (25)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs13_rdfifo_cnt_START (26)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs13_rdfifo_cnt_END (27)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs14_rdfifo_cnt_START (28)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs14_rdfifo_cnt_END (29)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs15_rdfifo_cnt_START (30)
#define SOC_NPU_L2BUF_SMC_DFX_RDFIFO_CNT1_dfx_cs15_rdfifo_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_int0_sram0 : 2;
        unsigned int st_int0_sram1 : 2;
        unsigned int st_int1_sram0 : 2;
        unsigned int st_int1_sram1 : 2;
        unsigned int st_int2_sram0 : 2;
        unsigned int st_int2_sram1 : 2;
        unsigned int st_int3_sram0 : 2;
        unsigned int st_int3_sram1 : 2;
        unsigned int st_int4_sram0 : 2;
        unsigned int st_int4_sram1 : 2;
        unsigned int st_int5_sram0 : 2;
        unsigned int st_int5_sram1 : 2;
        unsigned int st_int6_sram0 : 2;
        unsigned int st_int6_sram1 : 2;
        unsigned int st_int7_sram0 : 2;
        unsigned int st_int7_sram1 : 2;
    } reg;
} SOC_NPU_L2BUF_SP_SRAM_STATE0_UNION;
#endif
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int0_sram0_START (0)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int0_sram0_END (1)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int0_sram1_START (2)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int0_sram1_END (3)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int1_sram0_START (4)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int1_sram0_END (5)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int1_sram1_START (6)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int1_sram1_END (7)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int2_sram0_START (8)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int2_sram0_END (9)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int2_sram1_START (10)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int2_sram1_END (11)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int3_sram0_START (12)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int3_sram0_END (13)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int3_sram1_START (14)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int3_sram1_END (15)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int4_sram0_START (16)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int4_sram0_END (17)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int4_sram1_START (18)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int4_sram1_END (19)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int5_sram0_START (20)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int5_sram0_END (21)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int5_sram1_START (22)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int5_sram1_END (23)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int6_sram0_START (24)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int6_sram0_END (25)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int6_sram1_START (26)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int6_sram1_END (27)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int7_sram0_START (28)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int7_sram0_END (29)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int7_sram1_START (30)
#define SOC_NPU_L2BUF_SP_SRAM_STATE0_st_int7_sram1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_int8_sram0 : 2;
        unsigned int st_int8_sram1 : 2;
        unsigned int st_int9_sram0 : 2;
        unsigned int st_int9_sram1 : 2;
        unsigned int st_int10_sram0 : 2;
        unsigned int st_int10_sram1 : 2;
        unsigned int st_int11_sram0 : 2;
        unsigned int st_int11_sram1 : 2;
        unsigned int st_int12_sram0 : 2;
        unsigned int st_int12_sram1 : 2;
        unsigned int st_int13_sram0 : 2;
        unsigned int st_int13_sram1 : 2;
        unsigned int st_int14_sram0 : 2;
        unsigned int st_int14_sram1 : 2;
        unsigned int st_int15_sram0 : 2;
        unsigned int st_int15_sram1 : 2;
    } reg;
} SOC_NPU_L2BUF_SP_SRAM_STATE1_UNION;
#endif
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int8_sram0_START (0)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int8_sram0_END (1)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int8_sram1_START (2)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int8_sram1_END (3)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int9_sram0_START (4)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int9_sram0_END (5)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int9_sram1_START (6)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int9_sram1_END (7)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int10_sram0_START (8)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int10_sram0_END (9)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int10_sram1_START (10)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int10_sram1_END (11)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int11_sram0_START (12)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int11_sram0_END (13)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int11_sram1_START (14)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int11_sram1_END (15)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int12_sram0_START (16)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int12_sram0_END (17)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int12_sram1_START (18)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int12_sram1_END (19)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int13_sram0_START (20)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int13_sram0_END (21)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int13_sram1_START (22)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int13_sram1_END (23)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int14_sram0_START (24)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int14_sram0_END (25)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int14_sram1_START (26)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int14_sram1_END (27)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int15_sram0_START (28)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int15_sram0_END (29)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int15_sram1_START (30)
#define SOC_NPU_L2BUF_SP_SRAM_STATE1_st_int15_sram1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_lp_hw_sf : 1;
        unsigned int sf_lp_slp_access_rcd : 1;
        unsigned int sf_lp_exit_cycle : 6;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_L2BUF_SMC_LP_HW_SF_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_smc_lp_hw_sf_START (0)
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_smc_lp_hw_sf_END (0)
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_sf_lp_slp_access_rcd_START (1)
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_sf_lp_slp_access_rcd_END (1)
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_sf_lp_exit_cycle_START (2)
#define SOC_NPU_L2BUF_SMC_LP_HW_SF_sf_lp_exit_cycle_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_int0_sram0_dslp : 1;
        unsigned int smc_int0_sram1_dslp : 1;
        unsigned int smc_int1_sram0_dslp : 1;
        unsigned int smc_int1_sram1_dslp : 1;
        unsigned int smc_int2_sram0_dslp : 1;
        unsigned int smc_int2_sram1_dslp : 1;
        unsigned int smc_int3_sram0_dslp : 1;
        unsigned int smc_int3_sram1_dslp : 1;
        unsigned int smc_int4_sram0_dslp : 1;
        unsigned int smc_int4_sram1_dslp : 1;
        unsigned int smc_int5_sram0_dslp : 1;
        unsigned int smc_int5_sram1_dslp : 1;
        unsigned int smc_int6_sram0_dslp : 1;
        unsigned int smc_int6_sram1_dslp : 1;
        unsigned int smc_int7_sram0_dslp : 1;
        unsigned int smc_int7_sram1_dslp : 1;
        unsigned int smc_int8_sram0_dslp : 1;
        unsigned int smc_int8_sram1_dslp : 1;
        unsigned int smc_int9_sram0_dslp : 1;
        unsigned int smc_int9_sram1_dslp : 1;
        unsigned int smc_int10_sram0_dslp : 1;
        unsigned int smc_int10_sram1_dslp : 1;
        unsigned int smc_int11_sram0_dslp : 1;
        unsigned int smc_int11_sram1_dslp : 1;
        unsigned int smc_int12_sram0_dslp : 1;
        unsigned int smc_int12_sram1_dslp : 1;
        unsigned int smc_int13_sram0_dslp : 1;
        unsigned int smc_int13_sram1_dslp : 1;
        unsigned int smc_int14_sram0_dslp : 1;
        unsigned int smc_int14_sram1_dslp : 1;
        unsigned int smc_int15_sram0_dslp : 1;
        unsigned int smc_int15_sram1_dslp : 1;
    } reg;
} SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int0_sram0_dslp_START (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int0_sram0_dslp_END (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int0_sram1_dslp_START (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int0_sram1_dslp_END (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int1_sram0_dslp_START (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int1_sram0_dslp_END (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int1_sram1_dslp_START (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int1_sram1_dslp_END (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int2_sram0_dslp_START (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int2_sram0_dslp_END (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int2_sram1_dslp_START (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int2_sram1_dslp_END (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int3_sram0_dslp_START (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int3_sram0_dslp_END (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int3_sram1_dslp_START (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int3_sram1_dslp_END (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int4_sram0_dslp_START (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int4_sram0_dslp_END (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int4_sram1_dslp_START (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int4_sram1_dslp_END (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int5_sram0_dslp_START (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int5_sram0_dslp_END (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int5_sram1_dslp_START (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int5_sram1_dslp_END (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int6_sram0_dslp_START (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int6_sram0_dslp_END (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int6_sram1_dslp_START (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int6_sram1_dslp_END (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int7_sram0_dslp_START (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int7_sram0_dslp_END (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int7_sram1_dslp_START (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int7_sram1_dslp_END (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int8_sram0_dslp_START (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int8_sram0_dslp_END (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int8_sram1_dslp_START (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int8_sram1_dslp_END (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int9_sram0_dslp_START (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int9_sram0_dslp_END (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int9_sram1_dslp_START (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int9_sram1_dslp_END (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int10_sram0_dslp_START (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int10_sram0_dslp_END (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int10_sram1_dslp_START (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int10_sram1_dslp_END (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int11_sram0_dslp_START (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int11_sram0_dslp_END (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int11_sram1_dslp_START (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int11_sram1_dslp_END (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int12_sram0_dslp_START (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int12_sram0_dslp_END (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int12_sram1_dslp_START (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int12_sram1_dslp_END (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int13_sram0_dslp_START (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int13_sram0_dslp_END (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int13_sram1_dslp_START (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int13_sram1_dslp_END (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int14_sram0_dslp_START (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int14_sram0_dslp_END (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int14_sram1_dslp_START (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int14_sram1_dslp_END (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int15_sram0_dslp_START (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int15_sram0_dslp_END (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int15_sram1_dslp_START (31)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_DSLP_smc_int15_sram1_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_int0_sram0_lslp : 1;
        unsigned int smc_int0_sram1_lslp : 1;
        unsigned int smc_int1_sram0_lslp : 1;
        unsigned int smc_int1_sram1_lslp : 1;
        unsigned int smc_int2_sram0_lslp : 1;
        unsigned int smc_int2_sram1_lslp : 1;
        unsigned int smc_int3_sram0_lslp : 1;
        unsigned int smc_int3_sram1_lslp : 1;
        unsigned int smc_int4_sram0_lslp : 1;
        unsigned int smc_int4_sram1_lslp : 1;
        unsigned int smc_int5_sram0_lslp : 1;
        unsigned int smc_int5_sram1_lslp : 1;
        unsigned int smc_int6_sram0_lslp : 1;
        unsigned int smc_int6_sram1_lslp : 1;
        unsigned int smc_int7_sram0_lslp : 1;
        unsigned int smc_int7_sram1_lslp : 1;
        unsigned int smc_int8_sram0_lslp : 1;
        unsigned int smc_int8_sram1_lslp : 1;
        unsigned int smc_int9_sram0_lslp : 1;
        unsigned int smc_int9_sram1_lslp : 1;
        unsigned int smc_int10_sram0_lslp : 1;
        unsigned int smc_int10_sram1_lslp : 1;
        unsigned int smc_int11_sram0_lslp : 1;
        unsigned int smc_int11_sram1_lslp : 1;
        unsigned int smc_int12_sram0_lslp : 1;
        unsigned int smc_int12_sram1_lslp : 1;
        unsigned int smc_int13_sram0_lslp : 1;
        unsigned int smc_int13_sram1_lslp : 1;
        unsigned int smc_int14_sram0_lslp : 1;
        unsigned int smc_int14_sram1_lslp : 1;
        unsigned int smc_int15_sram0_lslp : 1;
        unsigned int smc_int15_sram1_lslp : 1;
    } reg;
} SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int0_sram0_lslp_START (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int0_sram0_lslp_END (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int0_sram1_lslp_START (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int0_sram1_lslp_END (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int1_sram0_lslp_START (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int1_sram0_lslp_END (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int1_sram1_lslp_START (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int1_sram1_lslp_END (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int2_sram0_lslp_START (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int2_sram0_lslp_END (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int2_sram1_lslp_START (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int2_sram1_lslp_END (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int3_sram0_lslp_START (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int3_sram0_lslp_END (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int3_sram1_lslp_START (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int3_sram1_lslp_END (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int4_sram0_lslp_START (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int4_sram0_lslp_END (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int4_sram1_lslp_START (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int4_sram1_lslp_END (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int5_sram0_lslp_START (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int5_sram0_lslp_END (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int5_sram1_lslp_START (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int5_sram1_lslp_END (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int6_sram0_lslp_START (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int6_sram0_lslp_END (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int6_sram1_lslp_START (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int6_sram1_lslp_END (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int7_sram0_lslp_START (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int7_sram0_lslp_END (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int7_sram1_lslp_START (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int7_sram1_lslp_END (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int8_sram0_lslp_START (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int8_sram0_lslp_END (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int8_sram1_lslp_START (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int8_sram1_lslp_END (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int9_sram0_lslp_START (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int9_sram0_lslp_END (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int9_sram1_lslp_START (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int9_sram1_lslp_END (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int10_sram0_lslp_START (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int10_sram0_lslp_END (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int10_sram1_lslp_START (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int10_sram1_lslp_END (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int11_sram0_lslp_START (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int11_sram0_lslp_END (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int11_sram1_lslp_START (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int11_sram1_lslp_END (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int12_sram0_lslp_START (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int12_sram0_lslp_END (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int12_sram1_lslp_START (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int12_sram1_lslp_END (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int13_sram0_lslp_START (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int13_sram0_lslp_END (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int13_sram1_lslp_START (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int13_sram1_lslp_END (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int14_sram0_lslp_START (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int14_sram0_lslp_END (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int14_sram1_lslp_START (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int14_sram1_lslp_END (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int15_sram0_lslp_START (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int15_sram0_lslp_END (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int15_sram1_lslp_START (31)
#define SOC_NPU_L2BUF_SMC_SRAM_SF_LSLP_smc_int15_sram1_lslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smc_int0_sram0_slp_access : 1;
        unsigned int smc_int0_sram1_slp_access : 1;
        unsigned int smc_int1_sram0_slp_access : 1;
        unsigned int smc_int1_sram1_slp_access : 1;
        unsigned int smc_int2_sram0_slp_access : 1;
        unsigned int smc_int2_sram1_slp_access : 1;
        unsigned int smc_int3_sram0_slp_access : 1;
        unsigned int smc_int3_sram1_slp_access : 1;
        unsigned int smc_int4_sram0_slp_access : 1;
        unsigned int smc_int4_sram1_slp_access : 1;
        unsigned int smc_int5_sram0_slp_access : 1;
        unsigned int smc_int5_sram1_slp_access : 1;
        unsigned int smc_int6_sram0_slp_access : 1;
        unsigned int smc_int6_sram1_slp_access : 1;
        unsigned int smc_int7_sram0_slp_access : 1;
        unsigned int smc_int7_sram1_slp_access : 1;
        unsigned int smc_int8_sram0_slp_access : 1;
        unsigned int smc_int8_sram1_slp_access : 1;
        unsigned int smc_int9_sram0_slp_access : 1;
        unsigned int smc_int9_sram1_slp_access : 1;
        unsigned int smc_int10_sram0_slp_access : 1;
        unsigned int smc_int10_sram1_slp_access : 1;
        unsigned int smc_int11_sram0_slp_access : 1;
        unsigned int smc_int11_sram1_slp_access : 1;
        unsigned int smc_int12_sram0_slp_access : 1;
        unsigned int smc_int12_sram1_slp_access : 1;
        unsigned int smc_int13_sram0_slp_access : 1;
        unsigned int smc_int13_sram1_slp_access : 1;
        unsigned int smc_int14_sram0_slp_access : 1;
        unsigned int smc_int14_sram1_slp_access : 1;
        unsigned int smc_int15_sram0_slp_access : 1;
        unsigned int smc_int15_sram1_slp_access : 1;
    } reg;
} SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_UNION;
#endif
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int0_sram0_slp_access_START (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int0_sram0_slp_access_END (0)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int0_sram1_slp_access_START (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int0_sram1_slp_access_END (1)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int1_sram0_slp_access_START (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int1_sram0_slp_access_END (2)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int1_sram1_slp_access_START (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int1_sram1_slp_access_END (3)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int2_sram0_slp_access_START (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int2_sram0_slp_access_END (4)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int2_sram1_slp_access_START (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int2_sram1_slp_access_END (5)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int3_sram0_slp_access_START (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int3_sram0_slp_access_END (6)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int3_sram1_slp_access_START (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int3_sram1_slp_access_END (7)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int4_sram0_slp_access_START (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int4_sram0_slp_access_END (8)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int4_sram1_slp_access_START (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int4_sram1_slp_access_END (9)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int5_sram0_slp_access_START (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int5_sram0_slp_access_END (10)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int5_sram1_slp_access_START (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int5_sram1_slp_access_END (11)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int6_sram0_slp_access_START (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int6_sram0_slp_access_END (12)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int6_sram1_slp_access_START (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int6_sram1_slp_access_END (13)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int7_sram0_slp_access_START (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int7_sram0_slp_access_END (14)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int7_sram1_slp_access_START (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int7_sram1_slp_access_END (15)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int8_sram0_slp_access_START (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int8_sram0_slp_access_END (16)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int8_sram1_slp_access_START (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int8_sram1_slp_access_END (17)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int9_sram0_slp_access_START (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int9_sram0_slp_access_END (18)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int9_sram1_slp_access_START (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int9_sram1_slp_access_END (19)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int10_sram0_slp_access_START (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int10_sram0_slp_access_END (20)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int10_sram1_slp_access_START (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int10_sram1_slp_access_END (21)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int11_sram0_slp_access_START (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int11_sram0_slp_access_END (22)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int11_sram1_slp_access_START (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int11_sram1_slp_access_END (23)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int12_sram0_slp_access_START (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int12_sram0_slp_access_END (24)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int12_sram1_slp_access_START (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int12_sram1_slp_access_END (25)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int13_sram0_slp_access_START (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int13_sram0_slp_access_END (26)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int13_sram1_slp_access_START (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int13_sram1_slp_access_END (27)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int14_sram0_slp_access_START (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int14_sram0_slp_access_END (28)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int14_sram1_slp_access_START (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int14_sram1_slp_access_END (29)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int15_sram0_slp_access_START (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int15_sram0_slp_access_END (30)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int15_sram1_slp_access_START (31)
#define SOC_NPU_L2BUF_SMC_SRAM_SLP_ACCESS_smc_int15_sram1_slp_access_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
