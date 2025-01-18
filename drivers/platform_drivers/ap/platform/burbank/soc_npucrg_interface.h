#ifndef __SOC_NPUCRG_INTERFACE_H__
#define __SOC_NPUCRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPUCRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_NPUCRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_NPUCRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_NPUCRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_NPUCRG_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_NPUCRG_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_NPUCRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_NPUCRG_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_NPUCRG_PERRSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_NPUCRG_PERRSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_NPUCRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_NPUCRG_PERRSTEN1_ADDR(base) ((base) + (0x02cUL))
#define SOC_NPUCRG_PERRSTDIS1_ADDR(base) ((base) + (0x030UL))
#define SOC_NPUCRG_PERRSTSTAT1_ADDR(base) ((base) + (0x034UL))
#define SOC_NPUCRG_CLKDIV0_ADDR(base) ((base) + (0x040UL))
#define SOC_NPUCRG_CLKDIV1_ADDR(base) ((base) + (0x048UL))
#define SOC_NPUCRG_PERI_STAT0_ADDR(base) ((base) + (0x060UL))
#define SOC_NPUCRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x070UL))
#define SOC_NPUCRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x080UL))
#define SOC_NPUCRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x084UL))
#define SOC_NPUCRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x088UL))
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x08CUL))
#define SOC_NPUCRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x090UL))
#define SOC_NPUCRG_PEREN2_ADDR(base) ((base) + (0x100UL))
#define SOC_NPUCRG_PERDIS2_ADDR(base) ((base) + (0x104UL))
#define SOC_NPUCRG_PERCLKEN2_ADDR(base) ((base) + (0x108UL))
#define SOC_NPUCRG_PERSTAT2_ADDR(base) ((base) + (0x10CUL))
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500UL))
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504UL))
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508UL))
#else
#define SOC_NPUCRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_NPUCRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_NPUCRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_NPUCRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_NPUCRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_NPUCRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_NPUCRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_NPUCRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_NPUCRG_PERRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_NPUCRG_PERRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_NPUCRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_NPUCRG_PERRSTEN1_ADDR(base) ((base) + (0x02c))
#define SOC_NPUCRG_PERRSTDIS1_ADDR(base) ((base) + (0x030))
#define SOC_NPUCRG_PERRSTSTAT1_ADDR(base) ((base) + (0x034))
#define SOC_NPUCRG_CLKDIV0_ADDR(base) ((base) + (0x040))
#define SOC_NPUCRG_CLKDIV1_ADDR(base) ((base) + (0x048))
#define SOC_NPUCRG_PERI_STAT0_ADDR(base) ((base) + (0x060))
#define SOC_NPUCRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x070))
#define SOC_NPUCRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x080))
#define SOC_NPUCRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x084))
#define SOC_NPUCRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x088))
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x08C))
#define SOC_NPUCRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x090))
#define SOC_NPUCRG_PEREN2_ADDR(base) ((base) + (0x100))
#define SOC_NPUCRG_PERDIS2_ADDR(base) ((base) + (0x104))
#define SOC_NPUCRG_PERCLKEN2_ADDR(base) ((base) + (0x108))
#define SOC_NPUCRG_PERSTAT2_ADDR(base) ((base) + (0x10C))
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500))
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504))
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ai_core0 : 1;
        unsigned int gt_clk_axi : 1;
        unsigned int gt_clk_fcm_periph : 1;
        unsigned int gt_pclkdbg_ai_core0 : 1;
        unsigned int gt_clk_npu2dmss_adb_slv : 1;
        unsigned int gt_clk_sram : 1;
        unsigned int gt_clk_db : 1;
        unsigned int gt_clk_bs : 1;
        unsigned int gt_clk_fcm_gic : 1;
        unsigned int gt_clk_fcm_scu : 1;
        unsigned int gt_atclk_ai_core0_brg : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_bus_monitor : 1;
        unsigned int gt_clk_fcm_atb : 1;
        unsigned int gt_pclkdbg_npu_fcm : 1;
        unsigned int gt_clk_fcm_tscpu : 1;
        unsigned int gt_clk_sysdma_smmu : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_npu2aicore_cfg : 1;
        unsigned int gt_clk_npu_sysdma : 1;
        unsigned int gt_clk_fcm_aicpu : 1;
        unsigned int gt_clk_npu_l2buf : 1;
        unsigned int gt_clk_noc_sysdma2npu : 1;
        unsigned int gt_clk_noc_tcu2npu : 1;
        unsigned int gt_clk_noc_npu2npucpu_cfg : 1;
        unsigned int gt_clk_noc_npucpu2npu : 1;
        unsigned int gt_clk_noc_npu2aicore_cfg : 1;
        unsigned int gt_clk_noc_aicore2npu : 1;
        unsigned int gt_clk_npu_tidm : 1;
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_npu_top_gic_adb_stream : 1;
    } reg;
} SOC_NPUCRG_PEREN0_UNION;
#endif
#define SOC_NPUCRG_PEREN0_gt_clk_ai_core0_START (0)
#define SOC_NPUCRG_PEREN0_gt_clk_ai_core0_END (0)
#define SOC_NPUCRG_PEREN0_gt_clk_axi_START (1)
#define SOC_NPUCRG_PEREN0_gt_clk_axi_END (1)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_periph_START (2)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_periph_END (2)
#define SOC_NPUCRG_PEREN0_gt_pclkdbg_ai_core0_START (3)
#define SOC_NPUCRG_PEREN0_gt_pclkdbg_ai_core0_END (3)
#define SOC_NPUCRG_PEREN0_gt_clk_npu2dmss_adb_slv_START (4)
#define SOC_NPUCRG_PEREN0_gt_clk_npu2dmss_adb_slv_END (4)
#define SOC_NPUCRG_PEREN0_gt_clk_sram_START (5)
#define SOC_NPUCRG_PEREN0_gt_clk_sram_END (5)
#define SOC_NPUCRG_PEREN0_gt_clk_db_START (6)
#define SOC_NPUCRG_PEREN0_gt_clk_db_END (6)
#define SOC_NPUCRG_PEREN0_gt_clk_bs_START (7)
#define SOC_NPUCRG_PEREN0_gt_clk_bs_END (7)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_gic_START (8)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_gic_END (8)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_scu_START (9)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_scu_END (9)
#define SOC_NPUCRG_PEREN0_gt_atclk_ai_core0_brg_START (10)
#define SOC_NPUCRG_PEREN0_gt_atclk_ai_core0_brg_END (10)
#define SOC_NPUCRG_PEREN0_gt_clk_bus_monitor_START (12)
#define SOC_NPUCRG_PEREN0_gt_clk_bus_monitor_END (12)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_atb_START (13)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_atb_END (13)
#define SOC_NPUCRG_PEREN0_gt_pclkdbg_npu_fcm_START (14)
#define SOC_NPUCRG_PEREN0_gt_pclkdbg_npu_fcm_END (14)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_tscpu_START (15)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_tscpu_END (15)
#define SOC_NPUCRG_PEREN0_gt_clk_sysdma_smmu_START (16)
#define SOC_NPUCRG_PEREN0_gt_clk_sysdma_smmu_END (16)
#define SOC_NPUCRG_PEREN0_gt_clk_aicore_smmu_START (17)
#define SOC_NPUCRG_PEREN0_gt_clk_aicore_smmu_END (17)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_hpm_START (18)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_hpm_END (18)
#define SOC_NPUCRG_PEREN0_gt_clk_npu2aicore_cfg_START (19)
#define SOC_NPUCRG_PEREN0_gt_clk_npu2aicore_cfg_END (19)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_sysdma_START (20)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_sysdma_END (20)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_aicpu_START (21)
#define SOC_NPUCRG_PEREN0_gt_clk_fcm_aicpu_END (21)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_l2buf_START (22)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_l2buf_END (22)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_sysdma2npu_START (23)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_sysdma2npu_END (23)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_tcu2npu_START (24)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_tcu2npu_END (24)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npu2npucpu_cfg_START (25)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npu2npucpu_cfg_END (25)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npucpu2npu_START (26)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npucpu2npu_END (26)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npu2aicore_cfg_START (27)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_npu2aicore_cfg_END (27)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PEREN0_gt_clk_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_tidm_START (29)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_tidm_END (29)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_pa_START (30)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_pa_END (30)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_top_gic_adb_stream_START (31)
#define SOC_NPUCRG_PEREN0_gt_clk_npu_top_gic_adb_stream_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ai_core0 : 1;
        unsigned int gt_clk_axi : 1;
        unsigned int gt_clk_fcm_periph : 1;
        unsigned int gt_pclkdbg_ai_core0 : 1;
        unsigned int gt_clk_npu2dmss_adb_slv : 1;
        unsigned int gt_clk_sram : 1;
        unsigned int gt_clk_db : 1;
        unsigned int gt_clk_bs : 1;
        unsigned int gt_clk_fcm_gic : 1;
        unsigned int gt_clk_fcm_scu : 1;
        unsigned int gt_atclk_ai_core0_brg : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_bus_monitor : 1;
        unsigned int gt_clk_fcm_atb : 1;
        unsigned int gt_pclkdbg_npu_fcm : 1;
        unsigned int gt_clk_fcm_tscpu : 1;
        unsigned int gt_clk_sysdma_smmu : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_npu2aicore_cfg : 1;
        unsigned int gt_clk_npu_sysdma : 1;
        unsigned int gt_clk_fcm_aicpu : 1;
        unsigned int gt_clk_npu_l2buf : 1;
        unsigned int gt_clk_noc_sysdma2npu : 1;
        unsigned int gt_clk_noc_tcu2npu : 1;
        unsigned int gt_clk_noc_npu2npucpu_cfg : 1;
        unsigned int gt_clk_noc_npucpu2npu : 1;
        unsigned int gt_clk_noc_npu2aicore_cfg : 1;
        unsigned int gt_clk_noc_aicore2npu : 1;
        unsigned int gt_clk_npu_tidm : 1;
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_npu_top_gic_adb_stream : 1;
    } reg;
} SOC_NPUCRG_PERDIS0_UNION;
#endif
#define SOC_NPUCRG_PERDIS0_gt_clk_ai_core0_START (0)
#define SOC_NPUCRG_PERDIS0_gt_clk_ai_core0_END (0)
#define SOC_NPUCRG_PERDIS0_gt_clk_axi_START (1)
#define SOC_NPUCRG_PERDIS0_gt_clk_axi_END (1)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_periph_START (2)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_periph_END (2)
#define SOC_NPUCRG_PERDIS0_gt_pclkdbg_ai_core0_START (3)
#define SOC_NPUCRG_PERDIS0_gt_pclkdbg_ai_core0_END (3)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu2dmss_adb_slv_START (4)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu2dmss_adb_slv_END (4)
#define SOC_NPUCRG_PERDIS0_gt_clk_sram_START (5)
#define SOC_NPUCRG_PERDIS0_gt_clk_sram_END (5)
#define SOC_NPUCRG_PERDIS0_gt_clk_db_START (6)
#define SOC_NPUCRG_PERDIS0_gt_clk_db_END (6)
#define SOC_NPUCRG_PERDIS0_gt_clk_bs_START (7)
#define SOC_NPUCRG_PERDIS0_gt_clk_bs_END (7)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_gic_START (8)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_gic_END (8)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_scu_START (9)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_scu_END (9)
#define SOC_NPUCRG_PERDIS0_gt_atclk_ai_core0_brg_START (10)
#define SOC_NPUCRG_PERDIS0_gt_atclk_ai_core0_brg_END (10)
#define SOC_NPUCRG_PERDIS0_gt_clk_bus_monitor_START (12)
#define SOC_NPUCRG_PERDIS0_gt_clk_bus_monitor_END (12)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_atb_START (13)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_atb_END (13)
#define SOC_NPUCRG_PERDIS0_gt_pclkdbg_npu_fcm_START (14)
#define SOC_NPUCRG_PERDIS0_gt_pclkdbg_npu_fcm_END (14)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_tscpu_START (15)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_tscpu_END (15)
#define SOC_NPUCRG_PERDIS0_gt_clk_sysdma_smmu_START (16)
#define SOC_NPUCRG_PERDIS0_gt_clk_sysdma_smmu_END (16)
#define SOC_NPUCRG_PERDIS0_gt_clk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERDIS0_gt_clk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_hpm_START (18)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_hpm_END (18)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu2aicore_cfg_START (19)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu2aicore_cfg_END (19)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_sysdma_START (20)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_sysdma_END (20)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_aicpu_START (21)
#define SOC_NPUCRG_PERDIS0_gt_clk_fcm_aicpu_END (21)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_l2buf_START (22)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_l2buf_END (22)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_sysdma2npu_START (23)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_sysdma2npu_END (23)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_tcu2npu_START (24)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_tcu2npu_END (24)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npu2npucpu_cfg_START (25)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npu2npucpu_cfg_END (25)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npucpu2npu_START (26)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npucpu2npu_END (26)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npu2aicore_cfg_START (27)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_npu2aicore_cfg_END (27)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERDIS0_gt_clk_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_tidm_START (29)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_tidm_END (29)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_pa_START (30)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_pa_END (30)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_top_gic_adb_stream_START (31)
#define SOC_NPUCRG_PERDIS0_gt_clk_npu_top_gic_adb_stream_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ai_core0 : 1;
        unsigned int gt_clk_axi : 1;
        unsigned int gt_clk_fcm_periph : 1;
        unsigned int gt_pclkdbg_ai_core0 : 1;
        unsigned int gt_clk_npu2dmss_adb_slv : 1;
        unsigned int gt_clk_sram : 1;
        unsigned int gt_clk_db : 1;
        unsigned int gt_clk_bs : 1;
        unsigned int gt_clk_fcm_gic : 1;
        unsigned int gt_clk_fcm_scu : 1;
        unsigned int gt_atclk_ai_core0_brg : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_bus_monitor : 1;
        unsigned int gt_clk_fcm_atb : 1;
        unsigned int gt_pclkdbg_npu_fcm : 1;
        unsigned int gt_clk_fcm_tscpu : 1;
        unsigned int gt_clk_sysdma_smmu : 1;
        unsigned int gt_clk_aicore_smmu : 1;
        unsigned int gt_clk_npu_hpm : 1;
        unsigned int gt_clk_npu2aicore_cfg : 1;
        unsigned int gt_clk_npu_sysdma : 1;
        unsigned int gt_clk_fcm_aicpu : 1;
        unsigned int gt_clk_npu_l2buf : 1;
        unsigned int gt_clk_noc_sysdma2npu : 1;
        unsigned int gt_clk_noc_tcu2npu : 1;
        unsigned int gt_clk_noc_npu2npucpu_cfg : 1;
        unsigned int gt_clk_noc_npucpu2npu : 1;
        unsigned int gt_clk_noc_npu2aicore_cfg : 1;
        unsigned int gt_clk_noc_aicore2npu : 1;
        unsigned int gt_clk_npu_tidm : 1;
        unsigned int gt_clk_npu_pa : 1;
        unsigned int gt_clk_npu_top_gic_adb_stream : 1;
    } reg;
} SOC_NPUCRG_PERCLKEN0_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN0_gt_clk_ai_core0_START (0)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_ai_core0_END (0)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_axi_START (1)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_axi_END (1)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_periph_START (2)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_periph_END (2)
#define SOC_NPUCRG_PERCLKEN0_gt_pclkdbg_ai_core0_START (3)
#define SOC_NPUCRG_PERCLKEN0_gt_pclkdbg_ai_core0_END (3)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu2dmss_adb_slv_START (4)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu2dmss_adb_slv_END (4)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_sram_START (5)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_sram_END (5)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_db_START (6)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_db_END (6)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_bs_START (7)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_bs_END (7)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_gic_START (8)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_gic_END (8)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_scu_START (9)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_scu_END (9)
#define SOC_NPUCRG_PERCLKEN0_gt_atclk_ai_core0_brg_START (10)
#define SOC_NPUCRG_PERCLKEN0_gt_atclk_ai_core0_brg_END (10)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_bus_monitor_START (12)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_bus_monitor_END (12)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_atb_START (13)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_atb_END (13)
#define SOC_NPUCRG_PERCLKEN0_gt_pclkdbg_npu_fcm_START (14)
#define SOC_NPUCRG_PERCLKEN0_gt_pclkdbg_npu_fcm_END (14)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_tscpu_START (15)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_tscpu_END (15)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_sysdma_smmu_START (16)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_sysdma_smmu_END (16)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_hpm_START (18)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_hpm_END (18)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu2aicore_cfg_START (19)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu2aicore_cfg_END (19)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_sysdma_START (20)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_sysdma_END (20)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_aicpu_START (21)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_fcm_aicpu_END (21)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_l2buf_START (22)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_l2buf_END (22)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_sysdma2npu_START (23)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_sysdma2npu_END (23)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_tcu2npu_START (24)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_tcu2npu_END (24)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npu2npucpu_cfg_START (25)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npu2npucpu_cfg_END (25)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npucpu2npu_START (26)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npucpu2npu_END (26)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npu2aicore_cfg_START (27)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_npu2aicore_cfg_END (27)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_tidm_START (29)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_tidm_END (29)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_pa_START (30)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_pa_END (30)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_top_gic_adb_stream_START (31)
#define SOC_NPUCRG_PERCLKEN0_gt_clk_npu_top_gic_adb_stream_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_ai_core0 : 1;
        unsigned int st_clk_axi : 1;
        unsigned int st_clk_fcm_periph : 1;
        unsigned int st_pclkdbg_ai_core0 : 1;
        unsigned int st_clk_npu2dmss_adb_slv : 1;
        unsigned int st_clk_sram : 1;
        unsigned int st_clk_db : 1;
        unsigned int st_clk_bs : 1;
        unsigned int st_clk_fcm_gic : 1;
        unsigned int st_clk_fcm_scu : 1;
        unsigned int st_atclk_ai_core0_brg : 1;
        unsigned int reserved : 1;
        unsigned int st_clk_bus_monitor : 1;
        unsigned int st_clk_fcm_atb : 1;
        unsigned int st_pclkdbg_npu_fcm : 1;
        unsigned int st_clk_fcm_tscpu : 1;
        unsigned int st_clk_sysdma_smmu : 1;
        unsigned int st_clk_aicore_smmu : 1;
        unsigned int st_clk_npu_hpm : 1;
        unsigned int st_clk_npu2aicore_cfg : 1;
        unsigned int st_clk_npu_sysdma : 1;
        unsigned int st_clk_fcm_aicpu : 1;
        unsigned int st_clk_npu_l2buf : 1;
        unsigned int st_clk_noc_sysdma2npu : 1;
        unsigned int st_clk_noc_tcu2npu : 1;
        unsigned int st_clk_noc_npu2npucpu_cfg : 1;
        unsigned int st_clk_noc_npucpu2npu : 1;
        unsigned int st_clk_noc_npu2aicore_cfg : 1;
        unsigned int st_clk_noc_aicore2npu : 1;
        unsigned int st_clk_npu_tidm : 1;
        unsigned int st_clk_npu_pa : 1;
        unsigned int st_clk_npu_top_gic_adb_stream : 1;
    } reg;
} SOC_NPUCRG_PERSTAT0_UNION;
#endif
#define SOC_NPUCRG_PERSTAT0_st_clk_ai_core0_START (0)
#define SOC_NPUCRG_PERSTAT0_st_clk_ai_core0_END (0)
#define SOC_NPUCRG_PERSTAT0_st_clk_axi_START (1)
#define SOC_NPUCRG_PERSTAT0_st_clk_axi_END (1)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_periph_START (2)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_periph_END (2)
#define SOC_NPUCRG_PERSTAT0_st_pclkdbg_ai_core0_START (3)
#define SOC_NPUCRG_PERSTAT0_st_pclkdbg_ai_core0_END (3)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu2dmss_adb_slv_START (4)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu2dmss_adb_slv_END (4)
#define SOC_NPUCRG_PERSTAT0_st_clk_sram_START (5)
#define SOC_NPUCRG_PERSTAT0_st_clk_sram_END (5)
#define SOC_NPUCRG_PERSTAT0_st_clk_db_START (6)
#define SOC_NPUCRG_PERSTAT0_st_clk_db_END (6)
#define SOC_NPUCRG_PERSTAT0_st_clk_bs_START (7)
#define SOC_NPUCRG_PERSTAT0_st_clk_bs_END (7)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_gic_START (8)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_gic_END (8)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_scu_START (9)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_scu_END (9)
#define SOC_NPUCRG_PERSTAT0_st_atclk_ai_core0_brg_START (10)
#define SOC_NPUCRG_PERSTAT0_st_atclk_ai_core0_brg_END (10)
#define SOC_NPUCRG_PERSTAT0_st_clk_bus_monitor_START (12)
#define SOC_NPUCRG_PERSTAT0_st_clk_bus_monitor_END (12)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_atb_START (13)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_atb_END (13)
#define SOC_NPUCRG_PERSTAT0_st_pclkdbg_npu_fcm_START (14)
#define SOC_NPUCRG_PERSTAT0_st_pclkdbg_npu_fcm_END (14)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_tscpu_START (15)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_tscpu_END (15)
#define SOC_NPUCRG_PERSTAT0_st_clk_sysdma_smmu_START (16)
#define SOC_NPUCRG_PERSTAT0_st_clk_sysdma_smmu_END (16)
#define SOC_NPUCRG_PERSTAT0_st_clk_aicore_smmu_START (17)
#define SOC_NPUCRG_PERSTAT0_st_clk_aicore_smmu_END (17)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_hpm_START (18)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_hpm_END (18)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu2aicore_cfg_START (19)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu2aicore_cfg_END (19)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_sysdma_START (20)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_sysdma_END (20)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_aicpu_START (21)
#define SOC_NPUCRG_PERSTAT0_st_clk_fcm_aicpu_END (21)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_l2buf_START (22)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_l2buf_END (22)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_sysdma2npu_START (23)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_sysdma2npu_END (23)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_tcu2npu_START (24)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_tcu2npu_END (24)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npu2npucpu_cfg_START (25)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npu2npucpu_cfg_END (25)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npucpu2npu_START (26)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npucpu2npu_END (26)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npu2aicore_cfg_START (27)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_npu2aicore_cfg_END (27)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERSTAT0_st_clk_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_tidm_START (29)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_tidm_END (29)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_pa_START (30)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_pa_END (30)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_top_gic_adb_stream_START (31)
#define SOC_NPUCRG_PERSTAT0_st_clk_npu_top_gic_adb_stream_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_sysdma_smmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_sysdma : 1;
        unsigned int gt_pclk_npu_l2buf : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_ipc_ns : 1;
        unsigned int gt_pclk_npu_ipc_s : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_clk_ts_wdog : 1;
        unsigned int gt_clk_ts_timer : 1;
        unsigned int gt_clk_ai_wdog : 1;
        unsigned int gt_clk_ai_timer : 1;
        unsigned int gt_pclk_atgs : 1;
        unsigned int gt_pclk_atgm : 1;
        unsigned int gt_pclk_tcu_smmu : 1;
        unsigned int gt_clk_tcu_smmu : 1;
        unsigned int gt_clk_npucpu_its : 1;
        unsigned int gt_clk_npucpu_hpm : 1;
        unsigned int gt_clk_npucpu_tidm : 1;
        unsigned int gt_clk_npucpu_pa : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_NPUCRG_PEREN1_UNION;
#endif
#define SOC_NPUCRG_PEREN1_gt_pclk_sysdma_smmu_START (0)
#define SOC_NPUCRG_PEREN1_gt_pclk_sysdma_smmu_END (0)
#define SOC_NPUCRG_PEREN1_gt_pclk_aicore_smmu_START (1)
#define SOC_NPUCRG_PEREN1_gt_pclk_aicore_smmu_END (1)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_sysdma_START (2)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_sysdma_END (2)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_l2buf_START (3)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_l2buf_END (3)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_uart_START (4)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_uart_END (4)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_ipc_ns_START (5)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_ipc_ns_END (5)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_ipc_s_START (6)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_ipc_s_END (6)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_hw_exp_irq_START (7)
#define SOC_NPUCRG_PEREN1_gt_pclk_npu_hw_exp_irq_END (7)
#define SOC_NPUCRG_PEREN1_gt_pclk_autodiv_npubus_START (8)
#define SOC_NPUCRG_PEREN1_gt_pclk_autodiv_npubus_END (8)
#define SOC_NPUCRG_PEREN1_gt_pclk_autodiv_npubus_cfg_START (9)
#define SOC_NPUCRG_PEREN1_gt_pclk_autodiv_npubus_cfg_END (9)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_wdog_START (10)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_wdog_END (10)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_timer_START (11)
#define SOC_NPUCRG_PEREN1_gt_clk_ts_timer_END (11)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_wdog_START (12)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_wdog_END (12)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_timer_START (13)
#define SOC_NPUCRG_PEREN1_gt_clk_ai_timer_END (13)
#define SOC_NPUCRG_PEREN1_gt_pclk_atgs_START (14)
#define SOC_NPUCRG_PEREN1_gt_pclk_atgs_END (14)
#define SOC_NPUCRG_PEREN1_gt_pclk_atgm_START (15)
#define SOC_NPUCRG_PEREN1_gt_pclk_atgm_END (15)
#define SOC_NPUCRG_PEREN1_gt_pclk_tcu_smmu_START (16)
#define SOC_NPUCRG_PEREN1_gt_pclk_tcu_smmu_END (16)
#define SOC_NPUCRG_PEREN1_gt_clk_tcu_smmu_START (17)
#define SOC_NPUCRG_PEREN1_gt_clk_tcu_smmu_END (17)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_its_START (18)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_its_END (18)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_hpm_START (19)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_hpm_END (19)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_tidm_START (20)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_tidm_END (20)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_pa_START (21)
#define SOC_NPUCRG_PEREN1_gt_clk_npucpu_pa_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_sysdma_smmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_sysdma : 1;
        unsigned int gt_pclk_npu_l2buf : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_ipc_ns : 1;
        unsigned int gt_pclk_npu_ipc_s : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_clk_ts_wdog : 1;
        unsigned int gt_clk_ts_timer : 1;
        unsigned int gt_clk_ai_wdog : 1;
        unsigned int gt_clk_ai_timer : 1;
        unsigned int gt_pclk_atgs : 1;
        unsigned int gt_pclk_atgm : 1;
        unsigned int gt_pclk_tcu_smmu : 1;
        unsigned int gt_clk_tcu_smmu : 1;
        unsigned int gt_clk_npucpu_its : 1;
        unsigned int gt_clk_npucpu_hpm : 1;
        unsigned int gt_clk_npucpu_tidm : 1;
        unsigned int gt_clk_npucpu_pa : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_NPUCRG_PERDIS1_UNION;
#endif
#define SOC_NPUCRG_PERDIS1_gt_pclk_sysdma_smmu_START (0)
#define SOC_NPUCRG_PERDIS1_gt_pclk_sysdma_smmu_END (0)
#define SOC_NPUCRG_PERDIS1_gt_pclk_aicore_smmu_START (1)
#define SOC_NPUCRG_PERDIS1_gt_pclk_aicore_smmu_END (1)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_sysdma_START (2)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_sysdma_END (2)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_l2buf_START (3)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_l2buf_END (3)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_uart_START (4)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_uart_END (4)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_ipc_ns_START (5)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_ipc_ns_END (5)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_ipc_s_START (6)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_ipc_s_END (6)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_hw_exp_irq_START (7)
#define SOC_NPUCRG_PERDIS1_gt_pclk_npu_hw_exp_irq_END (7)
#define SOC_NPUCRG_PERDIS1_gt_pclk_autodiv_npubus_START (8)
#define SOC_NPUCRG_PERDIS1_gt_pclk_autodiv_npubus_END (8)
#define SOC_NPUCRG_PERDIS1_gt_pclk_autodiv_npubus_cfg_START (9)
#define SOC_NPUCRG_PERDIS1_gt_pclk_autodiv_npubus_cfg_END (9)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_wdog_START (10)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_wdog_END (10)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_timer_START (11)
#define SOC_NPUCRG_PERDIS1_gt_clk_ts_timer_END (11)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_wdog_START (12)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_wdog_END (12)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_timer_START (13)
#define SOC_NPUCRG_PERDIS1_gt_clk_ai_timer_END (13)
#define SOC_NPUCRG_PERDIS1_gt_pclk_atgs_START (14)
#define SOC_NPUCRG_PERDIS1_gt_pclk_atgs_END (14)
#define SOC_NPUCRG_PERDIS1_gt_pclk_atgm_START (15)
#define SOC_NPUCRG_PERDIS1_gt_pclk_atgm_END (15)
#define SOC_NPUCRG_PERDIS1_gt_pclk_tcu_smmu_START (16)
#define SOC_NPUCRG_PERDIS1_gt_pclk_tcu_smmu_END (16)
#define SOC_NPUCRG_PERDIS1_gt_clk_tcu_smmu_START (17)
#define SOC_NPUCRG_PERDIS1_gt_clk_tcu_smmu_END (17)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_its_START (18)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_its_END (18)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_hpm_START (19)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_hpm_END (19)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_tidm_START (20)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_tidm_END (20)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_pa_START (21)
#define SOC_NPUCRG_PERDIS1_gt_clk_npucpu_pa_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_sysdma_smmu : 1;
        unsigned int gt_pclk_aicore_smmu : 1;
        unsigned int gt_pclk_npu_sysdma : 1;
        unsigned int gt_pclk_npu_l2buf : 1;
        unsigned int gt_pclk_npu_uart : 1;
        unsigned int gt_pclk_npu_ipc_ns : 1;
        unsigned int gt_pclk_npu_ipc_s : 1;
        unsigned int gt_pclk_npu_hw_exp_irq : 1;
        unsigned int gt_pclk_autodiv_npubus : 1;
        unsigned int gt_pclk_autodiv_npubus_cfg : 1;
        unsigned int gt_clk_ts_wdog : 1;
        unsigned int gt_clk_ts_timer : 1;
        unsigned int gt_clk_ai_wdog : 1;
        unsigned int gt_clk_ai_timer : 1;
        unsigned int gt_pclk_atgs : 1;
        unsigned int gt_pclk_atgm : 1;
        unsigned int gt_pclk_tcu_smmu : 1;
        unsigned int gt_clk_tcu_smmu : 1;
        unsigned int gt_clk_npucpu_its : 1;
        unsigned int gt_clk_npucpu_hpm : 1;
        unsigned int gt_clk_npucpu_tidm : 1;
        unsigned int gt_clk_npucpu_pa : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_NPUCRG_PERCLKEN1_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_sysdma_smmu_START (0)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_sysdma_smmu_END (0)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_aicore_smmu_START (1)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_aicore_smmu_END (1)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_sysdma_START (2)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_sysdma_END (2)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_l2buf_START (3)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_l2buf_END (3)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_uart_START (4)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_uart_END (4)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_ipc_ns_START (5)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_ipc_ns_END (5)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_ipc_s_START (6)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_ipc_s_END (6)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_hw_exp_irq_START (7)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_npu_hw_exp_irq_END (7)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_autodiv_npubus_START (8)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_autodiv_npubus_END (8)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_autodiv_npubus_cfg_START (9)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_autodiv_npubus_cfg_END (9)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_wdog_START (10)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_wdog_END (10)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_timer_START (11)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ts_timer_END (11)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_wdog_START (12)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_wdog_END (12)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_timer_START (13)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_ai_timer_END (13)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_atgs_START (14)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_atgs_END (14)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_atgm_START (15)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_atgm_END (15)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_tcu_smmu_START (16)
#define SOC_NPUCRG_PERCLKEN1_gt_pclk_tcu_smmu_END (16)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_tcu_smmu_START (17)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_tcu_smmu_END (17)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_its_START (18)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_its_END (18)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_hpm_START (19)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_hpm_END (19)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_tidm_START (20)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_tidm_END (20)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_pa_START (21)
#define SOC_NPUCRG_PERCLKEN1_gt_clk_npucpu_pa_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_sysdma_smmu : 1;
        unsigned int st_pclk_aicore_smmu : 1;
        unsigned int st_pclk_npu_sysdma : 1;
        unsigned int st_pclk_npu_l2buf : 1;
        unsigned int st_pclk_npu_uart : 1;
        unsigned int st_pclk_npu_ipc_ns : 1;
        unsigned int st_pclk_npu_ipc_s : 1;
        unsigned int st_pclk_npu_hw_exp_irq : 1;
        unsigned int st_pclk_autodiv_npubus : 1;
        unsigned int st_pclk_autodiv_npubus_cfg : 1;
        unsigned int st_clk_ts_wdog : 1;
        unsigned int st_clk_ts_timer : 1;
        unsigned int st_clk_ai_wdog : 1;
        unsigned int st_clk_ai_timer : 1;
        unsigned int st_pclk_atgs : 1;
        unsigned int st_pclk_atgm : 1;
        unsigned int st_pclk_tcu_smmu : 1;
        unsigned int st_clk_tcu_smmu : 1;
        unsigned int st_clk_npucpu_its : 1;
        unsigned int st_clk_npucpu_hpm : 1;
        unsigned int st_clk_npucpu_tidm : 1;
        unsigned int st_clk_npucpu_pa : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_NPUCRG_PERSTAT1_UNION;
#endif
#define SOC_NPUCRG_PERSTAT1_st_pclk_sysdma_smmu_START (0)
#define SOC_NPUCRG_PERSTAT1_st_pclk_sysdma_smmu_END (0)
#define SOC_NPUCRG_PERSTAT1_st_pclk_aicore_smmu_START (1)
#define SOC_NPUCRG_PERSTAT1_st_pclk_aicore_smmu_END (1)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_sysdma_START (2)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_sysdma_END (2)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_l2buf_START (3)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_l2buf_END (3)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_uart_START (4)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_uart_END (4)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_ipc_ns_START (5)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_ipc_ns_END (5)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_ipc_s_START (6)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_ipc_s_END (6)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_hw_exp_irq_START (7)
#define SOC_NPUCRG_PERSTAT1_st_pclk_npu_hw_exp_irq_END (7)
#define SOC_NPUCRG_PERSTAT1_st_pclk_autodiv_npubus_START (8)
#define SOC_NPUCRG_PERSTAT1_st_pclk_autodiv_npubus_END (8)
#define SOC_NPUCRG_PERSTAT1_st_pclk_autodiv_npubus_cfg_START (9)
#define SOC_NPUCRG_PERSTAT1_st_pclk_autodiv_npubus_cfg_END (9)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_wdog_START (10)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_wdog_END (10)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_timer_START (11)
#define SOC_NPUCRG_PERSTAT1_st_clk_ts_timer_END (11)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_wdog_START (12)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_wdog_END (12)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_timer_START (13)
#define SOC_NPUCRG_PERSTAT1_st_clk_ai_timer_END (13)
#define SOC_NPUCRG_PERSTAT1_st_pclk_atgs_START (14)
#define SOC_NPUCRG_PERSTAT1_st_pclk_atgs_END (14)
#define SOC_NPUCRG_PERSTAT1_st_pclk_atgm_START (15)
#define SOC_NPUCRG_PERSTAT1_st_pclk_atgm_END (15)
#define SOC_NPUCRG_PERSTAT1_st_pclk_tcu_smmu_START (16)
#define SOC_NPUCRG_PERSTAT1_st_pclk_tcu_smmu_END (16)
#define SOC_NPUCRG_PERSTAT1_st_clk_tcu_smmu_START (17)
#define SOC_NPUCRG_PERSTAT1_st_clk_tcu_smmu_END (17)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_its_START (18)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_its_END (18)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_hpm_START (19)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_hpm_END (19)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_tidm_START (20)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_tidm_END (20)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_pa_START (21)
#define SOC_NPUCRG_PERSTAT1_st_clk_npucpu_pa_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ai_core0 : 1;
        unsigned int ip_rst_npu_tidm : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_sysdma_smmu : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_fcm_scu : 1;
        unsigned int ip_rst_npu_cpu_subsys : 1;
        unsigned int ip_rst_npu2dmss_adb_slv : 1;
        unsigned int ip_rst_pdbg_npu_fcm : 1;
        unsigned int ip_rst_pdbg_ai_core0 : 1;
        unsigned int ip_rst_fcm_tscpu : 1;
        unsigned int ip_rst_por_fcm_tscpu : 1;
        unsigned int ip_rst_fcm_aicpu : 1;
        unsigned int ip_rst_por_fcm_aicpu : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_rst_npu_top_gic : 1;
        unsigned int ip_rst_npu_top_gic_dbg : 1;
        unsigned int ip_rst_fsm_tscpu : 1;
        unsigned int ip_rst_fsm_aicpu : 1;
        unsigned int ip_rst_fsm_fcm : 1;
        unsigned int ip_rst_fcm_periph : 1;
        unsigned int ip_rst_npu_l2buf : 1;
        unsigned int ip_rst_npu_sysdma : 1;
        unsigned int ip_rst_npu_top_gic_adb_stream : 1;
        unsigned int ip_rst_npu_cssys : 1;
        unsigned int ip_rst_fcm_gic : 1;
        unsigned int ip_rst_noc_sysdma2npu : 1;
        unsigned int ip_rst_noc_npucpu2npu : 1;
        unsigned int ip_rst_noc_aicore2npu : 1;
        unsigned int ip_rst_npucpu_hpm : 1;
        unsigned int ip_rst_npucpu_tidm : 1;
        unsigned int ip_rst_npucpu_pa : 1;
    } reg;
} SOC_NPUCRG_PERRSTEN0_UNION;
#endif
#define SOC_NPUCRG_PERRSTEN0_ip_rst_ai_core0_START (0)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_ai_core0_END (0)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_tidm_START (1)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_tidm_END (1)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_pa_START (2)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_pa_END (2)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_sysdma_smmu_START (3)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_sysdma_smmu_END (3)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_smmu_START (4)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_aicore_smmu_END (4)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_scu_START (5)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_scu_END (5)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_cpu_subsys_START (6)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_cpu_subsys_END (6)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu2dmss_adb_slv_START (7)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu2dmss_adb_slv_END (7)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_pdbg_npu_fcm_START (8)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_pdbg_npu_fcm_END (8)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_pdbg_ai_core0_START (9)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_pdbg_ai_core0_END (9)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_tscpu_START (10)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_tscpu_END (10)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_por_fcm_tscpu_START (11)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_por_fcm_tscpu_END (11)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_aicpu_START (12)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_aicpu_END (12)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_por_fcm_aicpu_START (13)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_por_fcm_aicpu_END (13)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_hpm_START (14)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_hpm_END (14)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_START (15)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_END (15)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_dbg_START (16)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_dbg_END (16)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_tscpu_START (17)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_tscpu_END (17)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_aicpu_START (18)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_aicpu_END (18)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_fcm_START (19)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fsm_fcm_END (19)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_periph_START (20)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_periph_END (20)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_l2buf_START (21)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_l2buf_END (21)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_sysdma_START (22)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_sysdma_END (22)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_adb_stream_START (23)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_top_gic_adb_stream_END (23)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_cssys_START (24)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npu_cssys_END (24)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_gic_START (25)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_fcm_gic_END (25)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_sysdma2npu_START (26)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_sysdma2npu_END (26)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_npucpu2npu_START (27)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_npucpu2npu_END (27)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_hpm_START (29)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_hpm_END (29)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_tidm_START (30)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_tidm_END (30)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_pa_START (31)
#define SOC_NPUCRG_PERRSTEN0_ip_rst_npucpu_pa_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ai_core0 : 1;
        unsigned int ip_rst_npu_tidm : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_sysdma_smmu : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_fcm_scu : 1;
        unsigned int ip_rst_npu_cpu_subsys : 1;
        unsigned int ip_rst_npu2dmss_adb_slv : 1;
        unsigned int ip_rst_pdbg_npu_fcm : 1;
        unsigned int ip_rst_pdbg_ai_core0 : 1;
        unsigned int ip_rst_fcm_tscpu : 1;
        unsigned int ip_rst_por_fcm_tscpu : 1;
        unsigned int ip_rst_fcm_aicpu : 1;
        unsigned int ip_rst_por_fcm_aicpu : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_rst_npu_top_gic : 1;
        unsigned int ip_rst_npu_top_gic_dbg : 1;
        unsigned int ip_rst_fsm_tscpu : 1;
        unsigned int ip_rst_fsm_aicpu : 1;
        unsigned int ip_rst_fsm_fcm : 1;
        unsigned int ip_rst_fcm_periph : 1;
        unsigned int ip_rst_npu_l2buf : 1;
        unsigned int ip_rst_npu_sysdma : 1;
        unsigned int ip_rst_npu_top_gic_adb_stream : 1;
        unsigned int ip_rst_npu_cssys : 1;
        unsigned int ip_rst_fcm_gic : 1;
        unsigned int ip_rst_noc_sysdma2npu : 1;
        unsigned int ip_rst_noc_npucpu2npu : 1;
        unsigned int ip_rst_noc_aicore2npu : 1;
        unsigned int ip_rst_npucpu_hpm : 1;
        unsigned int ip_rst_npucpu_tidm : 1;
        unsigned int ip_rst_npucpu_pa : 1;
    } reg;
} SOC_NPUCRG_PERRSTDIS0_UNION;
#endif
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_ai_core0_START (0)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_ai_core0_END (0)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_tidm_START (1)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_tidm_END (1)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_pa_START (2)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_pa_END (2)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_sysdma_smmu_START (3)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_sysdma_smmu_END (3)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_smmu_START (4)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_aicore_smmu_END (4)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_scu_START (5)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_scu_END (5)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_cpu_subsys_START (6)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_cpu_subsys_END (6)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu2dmss_adb_slv_START (7)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu2dmss_adb_slv_END (7)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_pdbg_npu_fcm_START (8)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_pdbg_npu_fcm_END (8)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_pdbg_ai_core0_START (9)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_pdbg_ai_core0_END (9)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_tscpu_START (10)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_tscpu_END (10)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_por_fcm_tscpu_START (11)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_por_fcm_tscpu_END (11)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_aicpu_START (12)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_aicpu_END (12)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_por_fcm_aicpu_START (13)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_por_fcm_aicpu_END (13)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_hpm_START (14)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_hpm_END (14)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_START (15)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_END (15)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_dbg_START (16)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_dbg_END (16)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_tscpu_START (17)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_tscpu_END (17)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_aicpu_START (18)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_aicpu_END (18)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_fcm_START (19)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fsm_fcm_END (19)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_periph_START (20)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_periph_END (20)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_l2buf_START (21)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_l2buf_END (21)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_sysdma_START (22)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_sysdma_END (22)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_adb_stream_START (23)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_top_gic_adb_stream_END (23)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_cssys_START (24)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npu_cssys_END (24)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_gic_START (25)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_fcm_gic_END (25)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_sysdma2npu_START (26)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_sysdma2npu_END (26)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_npucpu2npu_START (27)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_npucpu2npu_END (27)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_hpm_START (29)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_hpm_END (29)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_tidm_START (30)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_tidm_END (30)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_pa_START (31)
#define SOC_NPUCRG_PERRSTDIS0_ip_rst_npucpu_pa_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ai_core0 : 1;
        unsigned int ip_rst_npu_tidm : 1;
        unsigned int ip_rst_npu_pa : 1;
        unsigned int ip_rst_sysdma_smmu : 1;
        unsigned int ip_rst_aicore_smmu : 1;
        unsigned int ip_rst_fcm_scu : 1;
        unsigned int ip_rst_npu_cpu_subsys : 1;
        unsigned int ip_rst_npu2dmss_adb_slv : 1;
        unsigned int ip_rst_pdbg_npu_fcm : 1;
        unsigned int ip_rst_pdbg_ai_core0 : 1;
        unsigned int ip_rst_fcm_tscpu : 1;
        unsigned int ip_rst_por_fcm_tscpu : 1;
        unsigned int ip_rst_fcm_aicpu : 1;
        unsigned int ip_rst_por_fcm_aicpu : 1;
        unsigned int ip_rst_npu_hpm : 1;
        unsigned int ip_rst_npu_top_gic : 1;
        unsigned int ip_rst_npu_top_gic_dbg : 1;
        unsigned int ip_rst_fsm_tscpu : 1;
        unsigned int ip_rst_fsm_aicpu : 1;
        unsigned int ip_rst_fsm_fcm : 1;
        unsigned int ip_rst_fcm_periph : 1;
        unsigned int ip_rst_npu_l2buf : 1;
        unsigned int ip_rst_npu_sysdma : 1;
        unsigned int ip_rst_npu_top_gic_adb_stream : 1;
        unsigned int ip_rst_npu_cssys : 1;
        unsigned int ip_rst_fcm_gic : 1;
        unsigned int ip_rst_noc_sysdma2npu : 1;
        unsigned int ip_rst_noc_npucpu2npu : 1;
        unsigned int ip_rst_noc_aicore2npu : 1;
        unsigned int ip_rst_npucpu_hpm : 1;
        unsigned int ip_rst_npucpu_tidm : 1;
        unsigned int ip_rst_npucpu_pa : 1;
    } reg;
} SOC_NPUCRG_PERRSTSTAT0_UNION;
#endif
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_ai_core0_START (0)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_ai_core0_END (0)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_tidm_START (1)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_tidm_END (1)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_pa_START (2)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_pa_END (2)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_sysdma_smmu_START (3)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_sysdma_smmu_END (3)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_smmu_START (4)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_aicore_smmu_END (4)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_scu_START (5)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_scu_END (5)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_cpu_subsys_START (6)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_cpu_subsys_END (6)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu2dmss_adb_slv_START (7)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu2dmss_adb_slv_END (7)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_pdbg_npu_fcm_START (8)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_pdbg_npu_fcm_END (8)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_pdbg_ai_core0_START (9)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_pdbg_ai_core0_END (9)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_tscpu_START (10)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_tscpu_END (10)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_por_fcm_tscpu_START (11)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_por_fcm_tscpu_END (11)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_aicpu_START (12)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_aicpu_END (12)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_por_fcm_aicpu_START (13)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_por_fcm_aicpu_END (13)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_hpm_START (14)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_hpm_END (14)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_START (15)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_END (15)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_dbg_START (16)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_dbg_END (16)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_tscpu_START (17)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_tscpu_END (17)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_aicpu_START (18)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_aicpu_END (18)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_fcm_START (19)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fsm_fcm_END (19)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_periph_START (20)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_periph_END (20)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_l2buf_START (21)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_l2buf_END (21)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_sysdma_START (22)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_sysdma_END (22)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_adb_stream_START (23)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_top_gic_adb_stream_END (23)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_cssys_START (24)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npu_cssys_END (24)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_gic_START (25)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_fcm_gic_END (25)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_sysdma2npu_START (26)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_sysdma2npu_END (26)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_npucpu2npu_START (27)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_npucpu2npu_END (27)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_aicore2npu_START (28)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_noc_aicore2npu_END (28)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_hpm_START (29)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_hpm_END (29)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_tidm_START (30)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_tidm_END (30)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_pa_START (31)
#define SOC_NPUCRG_PERRSTSTAT0_ip_rst_npucpu_pa_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_npu_sysdma : 1;
        unsigned int ip_prst_npu_l2buf : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_ipc_ns : 1;
        unsigned int ip_prst_npu_ipc_s : 1;
        unsigned int ip_rst_ts_wdog : 1;
        unsigned int ip_rst_ts_timer : 1;
        unsigned int ip_rst_ai_wdog : 1;
        unsigned int ip_rst_ai_timer : 1;
        unsigned int ip_rst_sram : 1;
        unsigned int ip_rst_db : 1;
        unsigned int ip_rst_bs : 1;
        unsigned int ip_prst_sysdma_smmu : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_atgs : 1;
        unsigned int ip_prst_atgm : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_rst_npucpu_its : 1;
        unsigned int ip_prst_tcu_smmu : 1;
        unsigned int ip_rst_tcu_smmu : 1;
        unsigned int ip_rst_noc_tcu2npu : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
    } reg;
} SOC_NPUCRG_PERRSTEN1_UNION;
#endif
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_sysdma_START (1)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_sysdma_END (1)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_l2buf_START (2)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_l2buf_END (2)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_uart_START (3)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_uart_END (3)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_ipc_ns_START (4)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_ipc_ns_END (4)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_ipc_s_START (5)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_ipc_s_END (5)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_wdog_START (6)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_wdog_END (6)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_timer_START (7)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ts_timer_END (7)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_wdog_START (8)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_wdog_END (8)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_timer_START (9)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_ai_timer_END (9)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_sram_START (10)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_sram_END (10)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_db_START (11)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_db_END (11)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_bs_START (12)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_bs_END (12)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_sysdma_smmu_START (13)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_sysdma_smmu_END (13)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_aicore_smmu_START (14)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_aicore_smmu_END (14)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_atgs_START (15)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_atgs_END (15)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_atgm_START (16)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_atgm_END (16)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_hw_exp_irq_START (18)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_npu_hw_exp_irq_END (18)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npucpu_its_START (19)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_npucpu_its_END (19)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_tcu_smmu_START (20)
#define SOC_NPUCRG_PERRSTEN1_ip_prst_tcu_smmu_END (20)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_tcu_smmu_START (21)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_tcu_smmu_END (21)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_noc_tcu2npu_START (22)
#define SOC_NPUCRG_PERRSTEN1_ip_rst_noc_tcu2npu_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_npu_sysdma : 1;
        unsigned int ip_prst_npu_l2buf : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_ipc_ns : 1;
        unsigned int ip_prst_npu_ipc_s : 1;
        unsigned int ip_rst_ts_wdog : 1;
        unsigned int ip_rst_ts_timer : 1;
        unsigned int ip_rst_ai_wdog : 1;
        unsigned int ip_rst_ai_timer : 1;
        unsigned int ip_rst_sram : 1;
        unsigned int ip_rst_db : 1;
        unsigned int ip_rst_bs : 1;
        unsigned int ip_prst_sysdma_smmu : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_atgs : 1;
        unsigned int ip_prst_atgm : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_rst_npucpu_its : 1;
        unsigned int ip_prst_tcu_smmu : 1;
        unsigned int ip_rst_tcu_smmu : 1;
        unsigned int ip_rst_noc_tcu2npu : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
    } reg;
} SOC_NPUCRG_PERRSTDIS1_UNION;
#endif
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_sysdma_START (1)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_sysdma_END (1)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_l2buf_START (2)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_l2buf_END (2)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_uart_START (3)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_uart_END (3)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_ipc_ns_START (4)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_ipc_ns_END (4)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_ipc_s_START (5)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_ipc_s_END (5)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_wdog_START (6)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_wdog_END (6)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_timer_START (7)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ts_timer_END (7)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_wdog_START (8)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_wdog_END (8)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_timer_START (9)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_ai_timer_END (9)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_sram_START (10)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_sram_END (10)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_db_START (11)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_db_END (11)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_bs_START (12)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_bs_END (12)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_sysdma_smmu_START (13)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_sysdma_smmu_END (13)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_aicore_smmu_START (14)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_aicore_smmu_END (14)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_atgs_START (15)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_atgs_END (15)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_atgm_START (16)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_atgm_END (16)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_hw_exp_irq_START (18)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_npu_hw_exp_irq_END (18)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npucpu_its_START (19)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_npucpu_its_END (19)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_tcu_smmu_START (20)
#define SOC_NPUCRG_PERRSTDIS1_ip_prst_tcu_smmu_END (20)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_tcu_smmu_START (21)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_tcu_smmu_END (21)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_noc_tcu2npu_START (22)
#define SOC_NPUCRG_PERRSTDIS1_ip_rst_noc_tcu2npu_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_npu_sysdma : 1;
        unsigned int ip_prst_npu_l2buf : 1;
        unsigned int ip_prst_npu_uart : 1;
        unsigned int ip_prst_npu_ipc_ns : 1;
        unsigned int ip_prst_npu_ipc_s : 1;
        unsigned int ip_rst_ts_wdog : 1;
        unsigned int ip_rst_ts_timer : 1;
        unsigned int ip_rst_ai_wdog : 1;
        unsigned int ip_rst_ai_timer : 1;
        unsigned int ip_rst_sram : 1;
        unsigned int ip_rst_db : 1;
        unsigned int ip_rst_bs : 1;
        unsigned int ip_prst_sysdma_smmu : 1;
        unsigned int ip_prst_aicore_smmu : 1;
        unsigned int ip_prst_atgs : 1;
        unsigned int ip_prst_atgm : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_npu_hw_exp_irq : 1;
        unsigned int ip_rst_npucpu_its : 1;
        unsigned int ip_prst_tcu_smmu : 1;
        unsigned int ip_rst_tcu_smmu : 1;
        unsigned int ip_rst_noc_tcu2npu : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 6;
    } reg;
} SOC_NPUCRG_PERRSTSTAT1_UNION;
#endif
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_sysdma_START (1)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_sysdma_END (1)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_l2buf_START (2)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_l2buf_END (2)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_uart_START (3)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_uart_END (3)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_ipc_ns_START (4)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_ipc_ns_END (4)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_ipc_s_START (5)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_ipc_s_END (5)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_wdog_START (6)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_wdog_END (6)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_timer_START (7)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ts_timer_END (7)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_wdog_START (8)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_wdog_END (8)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_timer_START (9)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_ai_timer_END (9)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_sram_START (10)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_sram_END (10)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_db_START (11)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_db_END (11)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_bs_START (12)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_bs_END (12)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_sysdma_smmu_START (13)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_sysdma_smmu_END (13)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_aicore_smmu_START (14)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_aicore_smmu_END (14)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_atgs_START (15)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_atgs_END (15)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_atgm_START (16)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_atgm_END (16)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_hw_exp_irq_START (18)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_npu_hw_exp_irq_END (18)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npucpu_its_START (19)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_npucpu_its_END (19)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_tcu_smmu_START (20)
#define SOC_NPUCRG_PERRSTSTAT1_ip_prst_tcu_smmu_END (20)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_tcu_smmu_START (21)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_tcu_smmu_END (21)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_noc_tcu2npu_START (22)
#define SOC_NPUCRG_PERRSTSTAT1_ip_rst_noc_tcu2npu_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 4;
        unsigned int div_clk_fcm_periph : 2;
        unsigned int reserved_2 : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV0_UNION;
#endif
#define SOC_NPUCRG_CLKDIV0_div_clk_fcm_periph_START (6)
#define SOC_NPUCRG_CLKDIV0_div_clk_fcm_periph_END (7)
#define SOC_NPUCRG_CLKDIV0_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_fcm_periph : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_CLKDIV1_UNION;
#endif
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_fcm_periph_START (1)
#define SOC_NPUCRG_CLKDIV1_sc_gt_clk_fcm_periph_END (1)
#define SOC_NPUCRG_CLKDIV1_bitmasken_START (16)
#define SOC_NPUCRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_fcm_periph_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 29;
    } reg;
} SOC_NPUCRG_PERI_STAT0_UNION;
#endif
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_fcm_periph_div_START (0)
#define SOC_NPUCRG_PERI_STAT0_swdone_clk_fcm_periph_div_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sysdma_smmu_clkrst_bypass : 1;
        unsigned int aicore_smmu_clkrst_bypass : 1;
        unsigned int npu_sysdma_clkrst_bypass : 1;
        unsigned int npu_l2buf_clkrst_bypass : 1;
        unsigned int npu_uart_clkrst_bypass : 1;
        unsigned int npu_ipc_ns_clkrst_bypass : 1;
        unsigned int npu_ipc_s_clkrst_bypass : 1;
        unsigned int tcu_smmu_clkrst_bypass : 1;
        unsigned int npu_irq_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_NPUCRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_NPUCRG_IPCLKRST_BYPASS_sysdma_smmu_clkrst_bypass_START (0)
#define SOC_NPUCRG_IPCLKRST_BYPASS_sysdma_smmu_clkrst_bypass_END (0)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_smmu_clkrst_bypass_START (1)
#define SOC_NPUCRG_IPCLKRST_BYPASS_aicore_smmu_clkrst_bypass_END (1)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_sysdma_clkrst_bypass_START (2)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_sysdma_clkrst_bypass_END (2)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_l2buf_clkrst_bypass_START (3)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_l2buf_clkrst_bypass_END (3)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_uart_clkrst_bypass_START (4)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_uart_clkrst_bypass_END (4)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_ipc_ns_clkrst_bypass_START (5)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_ipc_ns_clkrst_bypass_END (5)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_ipc_s_clkrst_bypass_START (6)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_ipc_s_clkrst_bypass_END (6)
#define SOC_NPUCRG_IPCLKRST_BYPASS_tcu_smmu_clkrst_bypass_START (7)
#define SOC_NPUCRG_IPCLKRST_BYPASS_tcu_smmu_clkrst_bypass_END (7)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_irq_clkrst_bypass_START (8)
#define SOC_NPUCRG_IPCLKRST_BYPASS_npu_irq_clkrst_bypass_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int npubus_noc_tcu_smmu_bypass : 1;
        unsigned int npubus_noc_ddrc_bypass : 1;
        unsigned int npubus_noc_l2buffer_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int npubus_noc_sysdma_mst_bypass : 1;
        unsigned int npubus_noc_npucpu_mst_bypass : 1;
        unsigned int reserved_3 : 1;
        unsigned int npubus_noc_aicore_mst_bypass : 1;
        unsigned int npubus_noc_sys2npubus_cfg_bypass : 1;
        unsigned int npubus_noc_npu2cfgbus_cfg_bypass : 1;
        unsigned int npubus_noc_npubus_cfg_bypass : 1;
        unsigned int npubus_noc_npugic_cfg_bypass : 1;
        unsigned int npubus_noc_npucpu_cfg_bypass : 1;
        unsigned int npubus_noc_aicore_cfg_bypass : 1;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_tcu_smmu_bypass_START (2)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_tcu_smmu_bypass_END (2)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_ddrc_bypass_START (3)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_ddrc_bypass_END (3)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_l2buffer_bypass_START (4)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_l2buffer_bypass_END (4)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_sysdma_mst_bypass_START (6)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_sysdma_mst_bypass_END (6)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npucpu_mst_bypass_START (7)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npucpu_mst_bypass_END (7)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_aicore_mst_bypass_START (9)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_aicore_mst_bypass_END (9)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_sys2npubus_cfg_bypass_START (10)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_sys2npubus_cfg_bypass_END (10)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npu2cfgbus_cfg_bypass_START (11)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npu2cfgbus_cfg_bypass_END (11)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npubus_cfg_bypass_START (12)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npubus_cfg_bypass_END (12)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npugic_cfg_bypass_START (13)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npugic_cfg_bypass_END (13)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npucpu_cfg_bypass_START (14)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_npucpu_cfg_bypass_END (14)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_aicore_cfg_bypass_START (15)
#define SOC_NPUCRG_PERI_AUTODIV0_npubus_noc_aicore_cfg_bypass_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npubus_cfg_div_auto_reduce_bypass : 1;
        unsigned int npubus_cfg_auto_waitcfg_in : 10;
        unsigned int npubus_cfg_auto_waitcfg_out : 10;
        unsigned int npubus_cfg_div_auto_cfg : 6;
        unsigned int npubus_cfg_npubus_relate_auto_reduce_bypass : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_in_END (10)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_out_START (11)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_div_auto_cfg_END (26)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_npubus_relate_auto_reduce_bypass_START (27)
#define SOC_NPUCRG_PERI_AUTODIV1_npubus_cfg_npubus_relate_auto_reduce_bypass_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npubus_div_auto_reduce_bypass : 1;
        unsigned int npubus_auto_waitcfg_in : 10;
        unsigned int npubus_auto_waitcfg_out : 10;
        unsigned int npubus_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_reduce_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_reduce_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_in_START (1)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_in_END (10)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_out_START (11)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_auto_waitcfg_out_END (20)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_cfg_START (21)
#define SOC_NPUCRG_PERI_AUTODIV2_npubus_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int autodiv_npubus_stat : 1;
        unsigned int autodiv_npubus_cfg_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_START (0)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_END (0)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_START (1)
#define SOC_NPUCRG_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npubus_cfg_sysdma_mst_bypass : 1;
        unsigned int npubus_cfg_npucpu_mst_bypass : 1;
        unsigned int npubus_cfg_aicore_mst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int npubus_cfg_sys2npubus_cfg_bypass : 1;
        unsigned int npubus_cfg_npu2cfgbus_cfg_bypass : 1;
        unsigned int npubus_cfg_npubus_cfg_bypass : 1;
        unsigned int npubus_cfg_npugic_cfg_bypass : 1;
        unsigned int npubus_cfg_npucpu_cfg_bypass : 1;
        unsigned int npubus_cfg_aicore_cfg_bypass : 1;
        unsigned int reserved_7 : 16;
    } reg;
} SOC_NPUCRG_PERI_AUTODIV3_UNION;
#endif
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_sysdma_mst_bypass_START (0)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_sysdma_mst_bypass_END (0)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npucpu_mst_bypass_START (1)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npucpu_mst_bypass_END (1)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_aicore_mst_bypass_START (2)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_aicore_mst_bypass_END (2)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_sys2npubus_cfg_bypass_START (10)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_sys2npubus_cfg_bypass_END (10)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npu2cfgbus_cfg_bypass_START (11)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npu2cfgbus_cfg_bypass_END (11)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npubus_cfg_bypass_START (12)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npubus_cfg_bypass_END (12)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npugic_cfg_bypass_START (13)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npugic_cfg_bypass_END (13)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npucpu_cfg_bypass_START (14)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_npucpu_cfg_bypass_END (14)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_aicore_cfg_bypass_START (15)
#define SOC_NPUCRG_PERI_AUTODIV3_npubus_cfg_aicore_cfg_bypass_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
    } reg;
} SOC_NPUCRG_PEREN2_UNION;
#endif
#define SOC_NPUCRG_PEREN2_gt_clk_apb_START (0)
#define SOC_NPUCRG_PEREN2_gt_clk_apb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
    } reg;
} SOC_NPUCRG_PERDIS2_UNION;
#endif
#define SOC_NPUCRG_PERDIS2_gt_clk_apb_START (0)
#define SOC_NPUCRG_PERDIS2_gt_clk_apb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
    } reg;
} SOC_NPUCRG_PERCLKEN2_UNION;
#endif
#define SOC_NPUCRG_PERCLKEN2_gt_clk_apb_START (0)
#define SOC_NPUCRG_PERCLKEN2_gt_clk_apb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_apb : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
    } reg;
} SOC_NPUCRG_PERSTAT2_UNION;
#endif
#define SOC_NPUCRG_PERSTAT2_st_clk_apb_START (0)
#define SOC_NPUCRG_PERSTAT2_st_clk_apb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_aicore_nonidle_pend : 1;
        unsigned int intr_mask_npucpu_nonidle_pend : 1;
        unsigned int intr_mask_sysdma_nonidle_pend : 1;
        unsigned int intr_mask_tcu_nonidle_pend : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_aicore_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_aicore_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_npucpu_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_npucpu_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_sysdma_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_sysdma_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_tcu_nonidle_pend_END (3)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_NPUCRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_aicore_nonidle_pend : 1;
        unsigned int intr_clr_npucpu_nonidle_pend : 1;
        unsigned int intr_clr_sysdma_nonidle_pend : 1;
        unsigned int intr_clr_tcu_nonidle_pend : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_aicore_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_aicore_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_npucpu_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_npucpu_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_sysdma_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_sysdma_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_tcu_nonidle_pend_END (3)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_NPUCRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_aicore_nonidle_pend : 1;
        unsigned int intr_stat_npucpu_nonidle_pend : 1;
        unsigned int intr_stat_sysdma_nonidle_pend : 1;
        unsigned int intr_stat_tcu_nonidle_pend : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_aicore_nonidle_pend_START (0)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_aicore_nonidle_pend_END (0)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npucpu_nonidle_pend_START (1)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npucpu_nonidle_pend_END (1)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_sysdma_nonidle_pend_START (2)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_sysdma_nonidle_pend_END (2)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_tcu_nonidle_pend_START (3)
#define SOC_NPUCRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_tcu_nonidle_pend_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
