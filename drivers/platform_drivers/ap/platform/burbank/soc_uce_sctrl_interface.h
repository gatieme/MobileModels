#ifndef __SOC_UCE_SCTRL_INTERFACE_H__
#define __SOC_UCE_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004UL))
#define SOC_UCE_SCTRL_UCE_MCU_ROM_CTRL_ADDR(base) ((base) + (0x008UL))
#define SOC_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00CUL))
#define SOC_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010UL))
#define SOC_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014UL))
#define SOC_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018UL))
#define SOC_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x01CUL))
#define SOC_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020UL))
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030UL))
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034UL))
#define SOC_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038UL))
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040UL))
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044UL))
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ADDR(base) ((base) + (0x048UL))
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ADDR(base) ((base) + (0x04CUL))
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100UL))
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104UL))
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108UL))
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10CUL))
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110UL))
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114UL))
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118UL))
#else
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_ADDR(base) ((base) + (0x000))
#define SOC_UCE_SCTRL_UCE_MCU_STAT_ADDR(base) ((base) + (0x004))
#define SOC_UCE_SCTRL_UCE_MCU_ROM_CTRL_ADDR(base) ((base) + (0x008))
#define SOC_UCE_SCTRL_UCE_MCU_RAM_CTRL_ADDR(base) ((base) + (0x00C))
#define SOC_UCE_SCTRL_UCE_PROG_CTRL_ADDR(base) ((base) + (0x010))
#define SOC_UCE_SCTRL_UCE_PROG_STAT_ADDR(base) ((base) + (0x014))
#define SOC_UCE_SCTRL_UCE_MCU_POR_PC_ADDR(base) ((base) + (0x018))
#define SOC_UCE_SCTRL_UCE_MCU_PC_ADDR(base) ((base) + (0x01C))
#define SOC_UCE_SCTRL_UCE_INT_ADDR(base) ((base) + (0x020))
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_H_ADDR(base) ((base) + (0x030))
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_L_ADDR(base) ((base) + (0x034))
#define SOC_UCE_SCTRL_UCE_ID_ADDR(base) ((base) + (0x038))
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_SADDR_ADDR(base) ((base) + (0x040))
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_EADDR_ADDR(base) ((base) + (0x044))
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ADDR(base) ((base) + (0x048))
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ADDR(base) ((base) + (0x04C))
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_ADDR(base) ((base) + (0x100))
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_ADDR(base) ((base) + (0x104))
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_ADDR(base) ((base) + (0x108))
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_ADDR(base) ((base) + (0x10C))
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_ADDR(base) ((base) + (0x110))
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_ADDR(base) ((base) + (0x114))
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_ADDR(base) ((base) + (0x118))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyupd_wake_en : 1;
        unsigned int uce_mcu_soft_nmi : 1;
        unsigned int uce_wdg_resreq_bypass : 1;
        unsigned int core_wait : 1;
        unsigned int reserved_0 : 1;
        unsigned int wdgclken_bypass : 1;
        unsigned int timclken_bypass : 1;
        unsigned int halt_bypass : 1;
        unsigned int uce_mcu_idle_en : 1;
        unsigned int irq_wake_en : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_SCTRL_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_phyupd_wake_en_END (0)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_START (1)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_soft_nmi_END (1)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_START (2)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_wdg_resreq_bypass_END (2)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_START (3)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_core_wait_END (3)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_wdgclken_bypass_START (5)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_wdgclken_bypass_END (5)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_timclken_bypass_START (6)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_timclken_bypass_END (6)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_halt_bypass_START (7)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_halt_bypass_END (7)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_START (8)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_uce_mcu_idle_en_END (8)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_START (9)
#define SOC_UCE_SCTRL_UCE_MCU_SCTRL_irq_wake_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_mcu_sleeping : 1;
        unsigned int uce_mcu_hard_fault_mode : 1;
        unsigned int uce_mcu_debug : 1;
        unsigned int uce_sc_ra_wr_en : 1;
        unsigned int uce_sc_pc_valid : 1;
        unsigned int uce_in_nmi_hdlr : 1;
        unsigned int uce_rtactive_intr : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_STAT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_sleeping_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_sleeping_END (0)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_hard_fault_mode_START (1)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_hard_fault_mode_END (1)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_debug_START (2)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_mcu_debug_END (2)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_sc_ra_wr_en_START (3)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_sc_ra_wr_en_END (3)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_sc_pc_valid_START (4)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_sc_pc_valid_END (4)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_in_nmi_hdlr_START (5)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_in_nmi_hdlr_END (5)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_rtactive_intr_START (6)
#define SOC_UCE_SCTRL_UCE_MCU_STAT_uce_rtactive_intr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bootrom_rom_mem_ctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_ROM_CTRL_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_ROM_CTRL_bootrom_rom_mem_ctrl_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_ROM_CTRL_bootrom_rom_mem_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_ram_ctrl : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_RAM_CTRL_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_RAM_CTRL_uce_ram_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_prog_ctrl : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_PROG_CTRL_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_START (0)
#define SOC_UCE_SCTRL_UCE_PROG_CTRL_uce_prog_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_prog_stat : 8;
        unsigned int dfi_phyupd_req_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_UCE_SCTRL_UCE_PROG_STAT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_START (0)
#define SOC_UCE_SCTRL_UCE_PROG_STAT_uce_prog_stat_END (7)
#define SOC_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_START (8)
#define SOC_UCE_SCTRL_UCE_PROG_STAT_dfi_phyupd_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_por_rst_pc : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_POR_PC_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_POR_PC_mcu_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_pc : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_PC_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_PC_mcu_pc_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_PC_mcu_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_timer0_intr : 1;
        unsigned int uce_timer1_intr : 1;
        unsigned int uce_wdg_intr : 1;
        unsigned int uce_uart_intr : 1;
        unsigned int uce_rtactive_intr : 1;
        unsigned int ddrphy_unlock_intr : 1;
        unsigned int uce_ipc_intr0 : 1;
        unsigned int uce_ipc_intr1 : 1;
        unsigned int uce_ipc_mbx_intr0 : 1;
        unsigned int uce_ipc_mbx_intr1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int dfi_phyupd_intr : 1;
        unsigned int ext_intr : 8;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_UCE_SCTRL_UCE_INT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_INT_uce_timer0_intr_START (0)
#define SOC_UCE_SCTRL_UCE_INT_uce_timer0_intr_END (0)
#define SOC_UCE_SCTRL_UCE_INT_uce_timer1_intr_START (1)
#define SOC_UCE_SCTRL_UCE_INT_uce_timer1_intr_END (1)
#define SOC_UCE_SCTRL_UCE_INT_uce_wdg_intr_START (2)
#define SOC_UCE_SCTRL_UCE_INT_uce_wdg_intr_END (2)
#define SOC_UCE_SCTRL_UCE_INT_uce_uart_intr_START (3)
#define SOC_UCE_SCTRL_UCE_INT_uce_uart_intr_END (3)
#define SOC_UCE_SCTRL_UCE_INT_uce_rtactive_intr_START (4)
#define SOC_UCE_SCTRL_UCE_INT_uce_rtactive_intr_END (4)
#define SOC_UCE_SCTRL_UCE_INT_ddrphy_unlock_intr_START (5)
#define SOC_UCE_SCTRL_UCE_INT_ddrphy_unlock_intr_END (5)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_intr0_START (6)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_intr0_END (6)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_intr1_START (7)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_intr1_END (7)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_mbx_intr0_START (8)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_mbx_intr0_END (8)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_mbx_intr1_START (9)
#define SOC_UCE_SCTRL_UCE_INT_uce_ipc_mbx_intr1_END (9)
#define SOC_UCE_SCTRL_UCE_INT_dfi_phyupd_intr_START (11)
#define SOC_UCE_SCTRL_UCE_INT_dfi_phyupd_intr_END (11)
#define SOC_UCE_SCTRL_UCE_INT_ext_intr_START (12)
#define SOC_UCE_SCTRL_UCE_INT_ext_intr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timestamp_h : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_TIMESTAMP_H_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_START (0)
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_H_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timestamp_l : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_TIMESTAMP_L_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_START (0)
#define SOC_UCE_SCTRL_UCE_TIMESTAMP_L_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uce_id : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UCE_SCTRL_UCE_ID_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_ID_uce_id_START (0)
#define SOC_UCE_SCTRL_UCE_ID_uce_id_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_rgn_start_addr : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_ITCM_SADDR_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_SADDR_itcm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itcm_rgn_end_addr : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_ITCM_EADDR_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_ITCM_EADDR_itcm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ahbm_rgn_start_addr : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_AHBM_SADDR_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ahbm_rgn_start_addr_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_SADDR_ahbm_rgn_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ahbm_rgn_end_addr : 32;
    } reg;
} SOC_UCE_SCTRL_UCE_MCU_AHBM_EADDR_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ahbm_rgn_end_addr_START (0)
#define SOC_UCE_SCTRL_UCE_MCU_AHBM_EADDR_ahbm_rgn_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_ucem3_hclk_en : 1;
        unsigned int gt_ucem3_dapclk_en : 1;
        unsigned int gt_clk_h2hbrg_m_en : 1;
        unsigned int gt_clk_ipc_en : 1;
        unsigned int gt_pclk_uart_en : 1;
        unsigned int gt_clk_uart_en : 1;
        unsigned int gt_clk_timer_en : 1;
        unsigned int gt_clk_wdg_en : 1;
        unsigned int gt_clk_bus_s2p_en : 1;
        unsigned int gt_clk_19p2_s2p_en : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_GT_EN_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_ucem3_hclk_en_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_ucem3_hclk_en_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_ucem3_dapclk_en_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_ucem3_dapclk_en_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_h2hbrg_m_en_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_h2hbrg_m_en_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_ipc_en_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_ipc_en_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_pclk_uart_en_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_pclk_uart_en_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_uart_en_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_uart_en_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer_en_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_timer_en_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_wdg_en_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_wdg_en_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_bus_s2p_en_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_bus_s2p_en_END (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_19p2_s2p_en_START (9)
#define SOC_UCE_SCTRL_UCE_CRG_GT_EN_gt_clk_19p2_s2p_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_ucem3_hclk_dis : 1;
        unsigned int gt_ucem3_dapclk_dis : 1;
        unsigned int gt_clk_h2hbrg_m_dis : 1;
        unsigned int gt_clk_ipc_dis : 1;
        unsigned int gt_pclk_uart_dis : 1;
        unsigned int gt_clk_uart_dis : 1;
        unsigned int gt_clk_timer_dis : 1;
        unsigned int gt_clk_wdg_dis : 1;
        unsigned int gt_clk_bus_s2p_dis : 1;
        unsigned int gt_clk_19p2_s2p_dis : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_GT_DIS_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_ucem3_hclk_dis_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_ucem3_hclk_dis_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_ucem3_dapclk_dis_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_ucem3_dapclk_dis_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_h2hbrg_m_dis_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_h2hbrg_m_dis_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_ipc_dis_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_ipc_dis_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_pclk_uart_dis_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_pclk_uart_dis_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_uart_dis_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_uart_dis_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer_dis_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_timer_dis_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_wdg_dis_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_wdg_dis_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_bus_s2p_dis_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_bus_s2p_dis_END (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_19p2_s2p_dis_START (9)
#define SOC_UCE_SCTRL_UCE_CRG_GT_DIS_gt_clk_19p2_s2p_dis_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_ucem3_hclk_stat : 1;
        unsigned int gt_ucem3_dapclk_stat : 1;
        unsigned int gt_clk_h2hbrg_m_stat : 1;
        unsigned int gt_clk_ipc_stat : 1;
        unsigned int gt_pclk_uart_stat : 1;
        unsigned int gt_clk_uart_stat : 1;
        unsigned int gt_clk_timer_stat : 1;
        unsigned int gt_clk_wdg_stat : 1;
        unsigned int gt_clk_bus_s2p_stat : 1;
        unsigned int gt_clk_19p2_s2p_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_GT_STAT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_ucem3_hclk_stat_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_ucem3_hclk_stat_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_ucem3_dapclk_stat_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_ucem3_dapclk_stat_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_h2hbrg_m_stat_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_h2hbrg_m_stat_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_ipc_stat_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_ipc_stat_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_pclk_uart_stat_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_pclk_uart_stat_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_uart_stat_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_uart_stat_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer_stat_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_timer_stat_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_wdg_stat_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_wdg_stat_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_bus_s2p_stat_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_bus_s2p_stat_END (8)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_19p2_s2p_stat_START (9)
#define SOC_UCE_SCTRL_UCE_CRG_GT_STAT_gt_clk_19p2_s2p_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_ucem3_hclk : 1;
        unsigned int st_ucem3_dapclk : 1;
        unsigned int st_clk_h2hbrg_m : 1;
        unsigned int st_clk_ipc : 1;
        unsigned int st_pclk_uart : 1;
        unsigned int st_clk_uart : 1;
        unsigned int st_clk_timer : 1;
        unsigned int st_clk_timer_p2p_s : 1;
        unsigned int st_clk_wdg : 1;
        unsigned int st_clk_wdg_p2p_s : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_s2p_19p2 : 1;
        unsigned int st_clk_s2p_bus : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_ucem3_hclk_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_ucem3_hclk_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_ucem3_dapclk_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_ucem3_dapclk_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_h2hbrg_m_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_h2hbrg_m_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_ipc_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_ipc_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_uart_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_pclk_uart_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_uart_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_uart_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer_p2p_s_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_timer_p2p_s_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_END (8)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_p2p_s_START (9)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_wdg_p2p_s_END (9)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_19p2_START (12)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_19p2_END (12)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_bus_START (13)
#define SOC_UCE_SCTRL_UCE_CRG_CLK_STAT_st_clk_s2p_bus_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ucem3_sysreset_req_en : 1;
        unsigned int rst_uce_cssys_rst_req_en : 1;
        unsigned int rst_ipc_req_en : 1;
        unsigned int rst_uart_req_en : 1;
        unsigned int rst_wdg_req_en : 1;
        unsigned int rst_wdg_p2p_s_req_en : 1;
        unsigned int rst_timer_req_en : 1;
        unsigned int rst_timer_p2p_s_req_en : 1;
        unsigned int rst_h2hbrg_m_req_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_RST_EN_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_ucem3_sysreset_req_en_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_ucem3_sysreset_req_en_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_cssys_rst_req_en_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_uce_cssys_rst_req_en_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_ipc_req_en_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_ipc_req_en_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_uart_req_en_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_uart_req_en_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_req_en_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_req_en_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_p2p_s_req_en_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_wdg_p2p_s_req_en_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer_req_en_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer_req_en_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer_p2p_s_req_en_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_timer_p2p_s_req_en_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_h2hbrg_m_req_en_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_RST_EN_rst_h2hbrg_m_req_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ucem3_sysreset_req_dis : 1;
        unsigned int rst_uce_cssys_rst_req_dis : 1;
        unsigned int rst_ipc_req_dis : 1;
        unsigned int rst_uart_req_dis : 1;
        unsigned int rst_wdg_req_dis : 1;
        unsigned int rst_wdg_p2p_s_req_dis : 1;
        unsigned int rst_timer_req_dis : 1;
        unsigned int rst_timer_p2p_s_req_dis : 1;
        unsigned int rst_h2hbrg_m_req_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_RST_DIS_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_ucem3_sysreset_req_dis_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_ucem3_sysreset_req_dis_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_cssys_rst_req_dis_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uce_cssys_rst_req_dis_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_ipc_req_dis_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_ipc_req_dis_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uart_req_dis_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_uart_req_dis_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_req_dis_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_req_dis_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_p2p_s_req_dis_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_wdg_p2p_s_req_dis_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer_req_dis_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer_req_dis_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer_p2p_s_req_dis_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_timer_p2p_s_req_dis_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_h2hbrg_m_req_dis_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_RST_DIS_rst_h2hbrg_m_req_dis_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ucem3_sysreset_req_stat : 1;
        unsigned int rst_uce_cssys_rst_req_stat : 1;
        unsigned int rst_ipc_req_stat : 1;
        unsigned int rst_uart_req_stat : 1;
        unsigned int rst_wdg_req_stat : 1;
        unsigned int rst_wdg_p2p_s_req_stat : 1;
        unsigned int rst_timer_req_stat : 1;
        unsigned int rst_timer_p2p_s_req_stat : 1;
        unsigned int rst_h2hbrg_m_req_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_UCE_SCTRL_UCE_CRG_RST_STAT_UNION;
#endif
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_ucem3_sysreset_req_stat_START (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_ucem3_sysreset_req_stat_END (0)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_cssys_rst_req_stat_START (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uce_cssys_rst_req_stat_END (1)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_ipc_req_stat_START (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_ipc_req_stat_END (2)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uart_req_stat_START (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_uart_req_stat_END (3)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_req_stat_START (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_req_stat_END (4)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_p2p_s_req_stat_START (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_wdg_p2p_s_req_stat_END (5)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer_req_stat_START (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer_req_stat_END (6)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer_p2p_s_req_stat_START (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_timer_p2p_s_req_stat_END (7)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_h2hbrg_m_req_stat_START (8)
#define SOC_UCE_SCTRL_UCE_CRG_RST_STAT_rst_h2hbrg_m_req_stat_END (8)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
