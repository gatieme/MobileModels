#ifndef __SOC_FDUL_MINIISP_CVDR_INTERFACE_H__
#define __SOC_FDUL_MINIISP_CVDR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_ADDR(base) ((base) + (0x0))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_ADDR(base) ((base) + (0x4))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_ADDR(base) ((base) + (0x8))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_ADDR(base) ((base) + (0xcUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_ADDR(base) ((base) + (0x10UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_ADDR(base) ((base) + (0x14UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RO_ADDR(base) ((base) + (0x20UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RW_ADDR(base) ((base) + (0x24UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_ADDR(base) ((base) + (0x30UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_FS_0_ADDR(base) ((base) + (0x34UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_ADDR(base) ((base) + (0x38UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_ADDR(base) ((base) + (0x3cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_ADDR(base) ((base) + (0x830UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_ADDR(base) ((base) + (0xa30UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_ADDR(base) ((base) + (0xa34UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_ADDR(base) ((base) + (0xa38UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_FS_0_ADDR(base) ((base) + (0xa3cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_ADDR(base) ((base) + (0xa40UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_ADDR(base) ((base) + (0xa44UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_DEBUG_0_ADDR(base) ((base) + (0xa4cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_ADDR(base) ((base) + (0x1230UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_0_ADDR(base) ((base) + (0x1d30UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_1_ADDR(base) ((base) + (0x1d34UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_2_ADDR(base) ((base) + (0x1d38UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_3_ADDR(base) ((base) + (0x1d3cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_DEBUG_0_ADDR(base) ((base) + (0x1d40UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_0_ADDR(base) ((base) + (0x1f40UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_1_ADDR(base) ((base) + (0x1f44UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_2_ADDR(base) ((base) + (0x1f48UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_3_ADDR(base) ((base) + (0x1f4cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_4_ADDR(base) ((base) + (0x1f50UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_5_ADDR(base) ((base) + (0x1f54UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_6_ADDR(base) ((base) + (0x1f58UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_7_ADDR(base) ((base) + (0x1f5cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_8_ADDR(base) ((base) + (0x1f60UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_9_ADDR(base) ((base) + (0x1f64UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_10_ADDR(base) ((base) + (0x1f68UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_11_ADDR(base) ((base) + (0x1f6cUL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_12_ADDR(base) ((base) + (0x1f70UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_13_ADDR(base) ((base) + (0x1f74UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_14_ADDR(base) ((base) + (0x1f78UL))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_15_ADDR(base) ((base) + (0x1f7cUL))
#else
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_ADDR(base) ((base) + (0x0))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_ADDR(base) ((base) + (0x4))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_ADDR(base) ((base) + (0x8))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_ADDR(base) ((base) + (0xc))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_ADDR(base) ((base) + (0x10))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_ADDR(base) ((base) + (0x14))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RO_ADDR(base) ((base) + (0x20))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RW_ADDR(base) ((base) + (0x24))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_ADDR(base) ((base) + (0x30))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_FS_0_ADDR(base) ((base) + (0x34))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_ADDR(base) ((base) + (0x38))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_ADDR(base) ((base) + (0x3c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_ADDR(base) ((base) + (0x830))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_ADDR(base) ((base) + (0xa30))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_ADDR(base) ((base) + (0xa34))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_ADDR(base) ((base) + (0xa38))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_FS_0_ADDR(base) ((base) + (0xa3c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_ADDR(base) ((base) + (0xa40))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_ADDR(base) ((base) + (0xa44))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_DEBUG_0_ADDR(base) ((base) + (0xa4c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_ADDR(base) ((base) + (0x1230))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_0_ADDR(base) ((base) + (0x1d30))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_1_ADDR(base) ((base) + (0x1d34))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_2_ADDR(base) ((base) + (0x1d38))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_3_ADDR(base) ((base) + (0x1d3c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_DEBUG_0_ADDR(base) ((base) + (0x1d40))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_0_ADDR(base) ((base) + (0x1f40))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_1_ADDR(base) ((base) + (0x1f44))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_2_ADDR(base) ((base) + (0x1f48))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_3_ADDR(base) ((base) + (0x1f4c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_4_ADDR(base) ((base) + (0x1f50))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_5_ADDR(base) ((base) + (0x1f54))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_6_ADDR(base) ((base) + (0x1f58))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_7_ADDR(base) ((base) + (0x1f5c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_8_ADDR(base) ((base) + (0x1f60))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_9_ADDR(base) ((base) + (0x1f64))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_10_ADDR(base) ((base) + (0x1f68))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_11_ADDR(base) ((base) + (0x1f6c))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_12_ADDR(base) ((base) + (0x1f70))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_13_ADDR(base) ((base) + (0x1f74))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_14_ADDR(base) ((base) + (0x1f78))
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_15_ADDR(base) ((base) + (0x1f7c))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axiwrite_du_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int du_threshold_reached : 8;
        unsigned int max_axiread_id : 5;
        unsigned int reserved_1 : 3;
        unsigned int max_axiwrite_id : 5;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_axiwrite_du_threshold_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_axiwrite_du_threshold_END (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_du_threshold_reached_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_du_threshold_reached_END (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_max_axiread_id_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_max_axiread_id_END (20)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_max_axiwrite_id_START (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_CFG_max_axiwrite_id_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int rd_peak_en : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_wr_peak_en_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_wr_peak_en_END (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_rd_peak_en_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_EN_rd_peak_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak : 8;
        unsigned int rd_peak : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_wr_peak_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_wr_peak_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_rd_peak_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_DEBUG_rd_peak_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_qos_threshold_01_stop : 4;
        unsigned int wr_qos_threshold_01_start : 4;
        unsigned int wr_qos_threshold_10_stop : 4;
        unsigned int wr_qos_threshold_10_start : 4;
        unsigned int wr_qos_threshold_11_stop : 4;
        unsigned int wr_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int wr_qos_min : 2;
        unsigned int wr_qos_max : 2;
        unsigned int wr_qos_sr : 2;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_END (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_START (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_END (11)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_START (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_END (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_END (19)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_START (20)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_END (23)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_min_START (26)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_min_END (27)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_max_START (28)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_max_END (29)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_sr_START (30)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_WR_QOS_CFG_wr_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_qos_threshold_01_stop : 4;
        unsigned int rd_qos_threshold_01_start : 4;
        unsigned int rd_qos_threshold_10_stop : 4;
        unsigned int rd_qos_threshold_10_start : 4;
        unsigned int rd_qos_threshold_11_stop : 4;
        unsigned int rd_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int rd_qos_min : 2;
        unsigned int rd_qos_max : 2;
        unsigned int rd_qos_sr : 2;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_END (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_START (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_END (11)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_START (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_END (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_END (19)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_START (20)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_END (23)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_min_START (26)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_min_END (27)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_max_START (28)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_max_END (29)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_sr_START (30)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_CVDR_RD_QOS_CFG_rd_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_vprd_clk_on : 1;
        unsigned int force_vpwr_clk_on : 1;
        unsigned int force_nrrd_clk_on : 1;
        unsigned int force_nrwr_clk_on : 1;
        unsigned int force_axi_rd_clk_on : 1;
        unsigned int force_axi_wr_clk_on : 1;
        unsigned int force_du_rd_clk_on : 1;
        unsigned int force_du_wr_clk_on : 1;
        unsigned int force_cfg_clk_on : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_vprd_clk_on_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_vprd_clk_on_END (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_vpwr_clk_on_START (1)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_vpwr_clk_on_END (1)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_nrrd_clk_on_START (2)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_nrrd_clk_on_END (2)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_nrwr_clk_on_START (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_nrwr_clk_on_END (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_axi_rd_clk_on_START (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_axi_rd_clk_on_END (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_axi_wr_clk_on_START (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_axi_wr_clk_on_END (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_du_rd_clk_on_START (6)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_du_rd_clk_on_END (6)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_du_wr_clk_on_START (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_du_wr_clk_on_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_cfg_clk_on_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_FORCE_CLK_force_cfg_clk_on_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_ro : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RO_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RO_other_ro_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RO_other_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_rw : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RW_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RW_other_rw_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_OTHER_RW_other_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_0 : 5;
        unsigned int vpwr_pixel_expansion_0 : 1;
        unsigned int reserved : 7;
        unsigned int vpwr_last_page_0 : 19;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_pixel_format_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_pixel_format_0_END (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_pixel_expansion_0_START (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_pixel_expansion_0_END (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_last_page_0_START (13)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_CFG_0_vpwr_last_page_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int vpwr_address_frame_start_0 : 30;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_FS_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_START (2)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_0 : 11;
        unsigned int vpwr_line_start_wstrb_0 : 4;
        unsigned int vpwr_line_wrap_0 : 14;
        unsigned int reserved : 3;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_stride_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_stride_0_END (10)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_start_wstrb_0_START (11)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_start_wstrb_0_END (14)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_START (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int vp_wr_stop_enable_du_threshold_reached_0 : 1;
        unsigned int vp_wr_stop_enable_flux_ctrl_0 : 1;
        unsigned int vp_wr_stop_enable_pressure_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int vp_wr_stop_ok_0 : 1;
        unsigned int vp_wr_stop_0 : 1;
        unsigned int reserved_2 : 5;
        unsigned int vpwr_prefetch_bypass_0 : 1;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_du_threshold_reached_0_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_du_threshold_reached_0_END (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_flux_ctrl_0_START (17)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_flux_ctrl_0_END (17)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_pressure_0_START (18)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_enable_pressure_0_END (18)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_ok_0_START (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_ok_0_END (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_0_START (25)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vp_wr_stop_0_END (25)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vpwr_prefetch_bypass_0_START (31)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_IF_CFG_0_vpwr_prefetch_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_0 : 4;
        unsigned int vpwr_access_limiter_1_0 : 4;
        unsigned int vpwr_access_limiter_2_0 : 4;
        unsigned int vpwr_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_END (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_START (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_END (11)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_START (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_END (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_START (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_0 : 5;
        unsigned int vprd_pixel_expansion_0 : 1;
        unsigned int vprd_allocated_du_0 : 5;
        unsigned int reserved : 2;
        unsigned int vprd_last_page_0 : 19;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_pixel_format_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_pixel_format_0_END (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_pixel_expansion_0_START (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_pixel_expansion_0_END (5)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_allocated_du_0_START (6)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_allocated_du_0_END (10)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_last_page_0_START (13)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_CFG_0_vprd_last_page_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_vprd_line_size_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_vprd_line_size_0_END (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_vprd_horizontal_blanking_0_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_LWG_0_vprd_horizontal_blanking_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_vprd_frame_size_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_vprd_frame_size_0_END (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_vprd_vertical_blanking_0_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_FHG_0_vprd_vertical_blanking_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int vprd_axi_frame_start_0 : 30;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_FS_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_FS_0_vprd_axi_frame_start_0_START (2)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_FS_0_vprd_axi_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int vprd_line_wrap_0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_vprd_line_stride_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_vprd_line_stride_0_END (10)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_vprd_line_wrap_0_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_AXI_LINE_0_vprd_line_wrap_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int vp_rd_stop_enable_du_threshold_reached_0 : 1;
        unsigned int vp_rd_stop_enable_flux_ctrl_0 : 1;
        unsigned int vp_rd_stop_enable_pressure_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int vp_rd_stop_ok_0 : 1;
        unsigned int vp_rd_stop_0 : 1;
        unsigned int reserved_2 : 5;
        unsigned int vprd_prefetch_bypass_0 : 1;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_du_threshold_reached_0_START (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_du_threshold_reached_0_END (16)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_flux_ctrl_0_START (17)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_flux_ctrl_0_END (17)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_pressure_0_START (18)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_enable_pressure_0_END (18)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_ok_0_START (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_ok_0_END (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_0_START (25)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vp_rd_stop_0_END (25)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vprd_prefetch_bypass_0_START (31)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_IF_CFG_0_vprd_prefetch_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_0 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_DEBUG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_DEBUG_0_vp_rd_debug_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_RD_DEBUG_0_vp_rd_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_0 : 4;
        unsigned int vprd_access_limiter_1_0 : 4;
        unsigned int vprd_access_limiter_2_0 : 4;
        unsigned int vprd_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_0_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_0_0_END (3)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_1_0_START (4)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_1_0_END (7)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_2_0_START (8)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_2_0_END (11)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_3_0_START (12)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_3_0_END (15)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_reload_0_START (24)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_LIMITER_VP_RD_0_vprd_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_0 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_0_spare_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_0_spare_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_1 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_1_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_1_spare_1_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_1_spare_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_2 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_2_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_2_spare_2_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_2_spare_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_3 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_3_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_3_spare_3_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_SPARE_3_spare_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_0 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_DEBUG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_DEBUG_0_vp_wr_debug_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_VP_WR_DEBUG_0_vp_wr_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_0 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_0_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_0_debug_0_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_0_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_1 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_1_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_1_debug_1_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_1_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_2 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_2_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_2_debug_2_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_2_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_3 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_3_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_3_debug_3_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_3_debug_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_4 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_4_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_4_debug_4_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_4_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_5 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_5_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_5_debug_5_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_5_debug_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_6 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_6_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_6_debug_6_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_6_debug_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_7 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_7_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_7_debug_7_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_7_debug_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_8 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_8_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_8_debug_8_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_8_debug_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_9 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_9_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_9_debug_9_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_9_debug_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_10 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_10_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_10_debug_10_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_10_debug_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_11 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_11_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_11_debug_11_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_11_debug_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_12 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_12_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_12_debug_12_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_12_debug_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_13 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_13_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_13_debug_13_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_13_debug_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_14 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_14_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_14_debug_14_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_14_debug_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_15 : 32;
    } reg;
} SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_15_UNION;
#endif
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_15_debug_15_START (0)
#define SOC_FDUL_MINIISP_CVDR_MINIISP_DEBUG_15_debug_15_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
