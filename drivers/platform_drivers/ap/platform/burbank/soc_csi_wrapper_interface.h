#ifndef __SOC_CSI_WRAPPER_INTERFACE_H__
#define __SOC_CSI_WRAPPER_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_ADDR(base) ((base) + (0x0))
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_ADDR(base) ((base) + (0x4))
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_ADDR(base) ((base) + (0x8))
#define SOC_CSI_WRAPPER_CSI_RESET_0_ADDR(base) ((base) + (0xC))
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ADDR(base) ((base) + (0x10))
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ADDR(base) ((base) + (0x14))
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ADDR(base) ((base) + (0x18))
#define SOC_CSI_WRAPPER_PHY_CSI_A_ADDR(base) ((base) + (0x1C))
#define SOC_CSI_WRAPPER_PHY_CSI_B_ADDR(base) ((base) + (0x20))
#define SOC_CSI_WRAPPER_PHY_CSI_C_ADDR(base) ((base) + (0x24))
#define SOC_CSI_WRAPPER_CSI_CGR_1_ADDR(base) ((base) + (0x400))
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_ADDR(base) ((base) + (0x404))
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_ADDR(base) ((base) + (0x408))
#define SOC_CSI_WRAPPER_CSI_RESET_1_ADDR(base) ((base) + (0x40C))
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ADDR(base) ((base) + (0x410))
#define SOC_CSI_WRAPPER_PHY_CSI_D_ADDR(base) ((base) + (0x414))
#define SOC_CSI_WRAPPER_CSI_CGR_2_ADDR(base) ((base) + (0x500))
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_ADDR(base) ((base) + (0x504))
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_ADDR(base) ((base) + (0x508))
#define SOC_CSI_WRAPPER_CSI_RESET_2_ADDR(base) ((base) + (0x50C))
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ADDR(base) ((base) + (0x510))
#define SOC_CSI_WRAPPER_PHY_CSI_E_ADDR(base) ((base) + (0x514))
#define SOC_CSI_WRAPPER_CSIA_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_CSI_WRAPPER_CSIB_CTRL_ADDR(base) ((base) + (0x604))
#define SOC_CSI_WRAPPER_CSIC_CTRL_ADDR(base) ((base) + (0x608))
#define SOC_CSI_WRAPPER_CSID_CTRL_ADDR(base) ((base) + (0x60C))
#define SOC_CSI_WRAPPER_CSIE_CTRL_ADDR(base) ((base) + (0x610))
#define SOC_CSI_WRAPPER_CSI_DBG_ADDR(base) ((base) + (0x800))
#define SOC_CSI_WRAPPER_CSIA_DBG_ADDR(base) ((base) + (0x804))
#define SOC_CSI_WRAPPER_CSIB_DBG_ADDR(base) ((base) + (0x808))
#define SOC_CSI_WRAPPER_CSIC_DBG_ADDR(base) ((base) + (0x80C))
#define SOC_CSI_WRAPPER_CSID_DBG_ADDR(base) ((base) + (0x810))
#define SOC_CSI_WRAPPER_CSIE_DBG_ADDR(base) ((base) + (0x814))
#define SOC_CSI_WRAPPER_S_ADDR(base) ((base) + (0xC00))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_rst_csia : 1;
        unsigned int soft_rst_csib : 1;
        unsigned int soft_rst_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_0_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int rxinvalidcodehs_0 : 1;
        unsigned int rxinvalidcodehs_1 : 1;
        unsigned int rxinvalidcodehs_2 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_A_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_0_START (17)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_0_END (17)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_1_START (18)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_1_END (18)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_2_START (19)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_rxinvalidcodehs_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int rxinvalidcodehs_0 : 1;
        unsigned int rxinvalidcodehs_1 : 1;
        unsigned int rxinvalidcodehs_2 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_B_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_0_START (17)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_0_END (17)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_1_START (18)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_1_END (18)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_2_START (19)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_rxinvalidcodehs_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int rxinvalidcodehs_0 : 1;
        unsigned int rxinvalidcodehs_1 : 1;
        unsigned int rxinvalidcodehs_2 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_C_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_0_START (17)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_0_END (17)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_1_START (18)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_1_END (18)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_2_START (19)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_rxinvalidcodehs_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_rx_dbg_out : 24;
        unsigned int phy_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_A_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_A_phy_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_A_phy_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_A_phy_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_A_phy_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_rx_dbg_out : 24;
        unsigned int phy_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_B_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_B_phy_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_B_phy_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_B_phy_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_B_phy_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_rx_dbg_out : 24;
        unsigned int phy_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_C_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_C_phy_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_C_phy_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_C_phy_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_C_phy_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_rst_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_1_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_1_soft_rst_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_1_soft_rst_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int rxinvalidcodehs_0 : 1;
        unsigned int rxinvalidcodehs_1 : 1;
        unsigned int rxinvalidcodehs_2 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_D_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_0_START (17)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_0_END (17)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_1_START (18)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_1_END (18)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_2_START (19)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_rxinvalidcodehs_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_rx_dbg_out : 24;
        unsigned int phy_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_D_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_D_phy_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_D_phy_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_D_phy_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_D_phy_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_rst_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_2_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_2_soft_rst_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_2_soft_rst_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int rxinvalidcodehs_0 : 1;
        unsigned int rxinvalidcodehs_1 : 1;
        unsigned int rxinvalidcodehs_2 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_E_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_0_START (17)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_0_END (17)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_1_START (18)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_1_END (18)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_2_START (19)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_rxinvalidcodehs_2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_rx_dbg_out : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_E_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_E_phy_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_E_phy_rx_dbg_out_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 25;
        unsigned int hicsi_sel : 1;
        unsigned int csia_en : 1;
        unsigned int csia_sensor : 1;
        unsigned int csia_cdphy_sensor_connection : 1;
        unsigned int csia_cdphy_master : 1;
        unsigned int csia_cdphy_source : 2;
    } reg;
} SOC_CSI_WRAPPER_CSIA_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIA_CTRL_hicsi_sel_START (25)
#define SOC_CSI_WRAPPER_CSIA_CTRL_hicsi_sel_END (25)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_en_START (26)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_en_END (26)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_sensor_START (27)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_sensor_END (27)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_sensor_connection_START (28)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_sensor_connection_END (28)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_master_START (29)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_master_END (29)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_source_START (30)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 26;
        unsigned int csib_en : 1;
        unsigned int csib_sensor : 1;
        unsigned int csib_cdphy_sensor_connection : 1;
        unsigned int csib_cdphy_master : 1;
        unsigned int csib_cdphy_source : 2;
    } reg;
} SOC_CSI_WRAPPER_CSIB_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_en_START (26)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_en_END (26)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_sensor_START (27)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_sensor_END (27)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_sensor_connection_START (28)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_sensor_connection_END (28)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_master_START (29)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_master_END (29)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_source_START (30)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 26;
        unsigned int csic_en : 1;
        unsigned int csic_sensor : 1;
        unsigned int csic_cdphy_sensor_connection : 1;
        unsigned int csic_cdphy_master : 1;
        unsigned int csic_cdphy_source : 2;
    } reg;
} SOC_CSI_WRAPPER_CSIC_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_en_START (26)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_en_END (26)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_sensor_START (27)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_sensor_END (27)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_sensor_connection_START (28)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_sensor_connection_END (28)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_master_START (29)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_master_END (29)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_source_START (30)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 25;
        unsigned int fp_fd_sel : 1;
        unsigned int csid_en : 1;
        unsigned int csid_sensor : 1;
        unsigned int csid_cdphy_sensor_connection : 1;
        unsigned int csid_cdphy_master : 1;
        unsigned int csid_cdphy_source : 2;
    } reg;
} SOC_CSI_WRAPPER_CSID_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSID_CTRL_fp_fd_sel_START (25)
#define SOC_CSI_WRAPPER_CSID_CTRL_fp_fd_sel_END (25)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_en_START (26)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_en_END (26)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_sensor_START (27)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_sensor_END (27)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_sensor_connection_START (28)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_sensor_connection_END (28)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_master_START (29)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_master_END (29)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_source_START (30)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int phyd_cfg_clk_mux : 1;
        unsigned int phya_cfg_clk_mux : 1;
        unsigned int ipi_cfg_dt : 6;
        unsigned int ipi_cfg_vc : 2;
        unsigned int csie_en : 1;
        unsigned int csie_sensor : 1;
        unsigned int csie_cdphy_sensor_connection : 1;
        unsigned int csie_cdphy_master : 1;
        unsigned int csie_cdphy_source : 2;
    } reg;
} SOC_CSI_WRAPPER_CSIE_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIE_CTRL_phyd_cfg_clk_mux_START (16)
#define SOC_CSI_WRAPPER_CSIE_CTRL_phyd_cfg_clk_mux_END (16)
#define SOC_CSI_WRAPPER_CSIE_CTRL_phya_cfg_clk_mux_START (17)
#define SOC_CSI_WRAPPER_CSIE_CTRL_phya_cfg_clk_mux_END (17)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_dt_START (18)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_dt_END (23)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_vc_START (24)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_vc_END (25)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_en_START (26)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_en_END (26)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_sensor_START (27)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_sensor_END (27)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_sensor_connection_START (28)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_sensor_connection_END (28)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_master_START (29)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_master_END (29)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_source_START (30)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csi_debug_en : 1;
        unsigned int csia_overflow : 1;
        unsigned int csib_overflow : 1;
        unsigned int csic_overflow : 1;
        unsigned int csid_overflow : 1;
        unsigned int csie_overflow : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CSI_WRAPPER_CSI_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_DBG_csi_debug_en_START (0)
#define SOC_CSI_WRAPPER_CSI_DBG_csi_debug_en_END (0)
#define SOC_CSI_WRAPPER_CSI_DBG_csia_overflow_START (1)
#define SOC_CSI_WRAPPER_CSI_DBG_csia_overflow_END (1)
#define SOC_CSI_WRAPPER_CSI_DBG_csib_overflow_START (2)
#define SOC_CSI_WRAPPER_CSI_DBG_csib_overflow_END (2)
#define SOC_CSI_WRAPPER_CSI_DBG_csic_overflow_START (3)
#define SOC_CSI_WRAPPER_CSI_DBG_csic_overflow_END (3)
#define SOC_CSI_WRAPPER_CSI_DBG_csid_overflow_START (4)
#define SOC_CSI_WRAPPER_CSI_DBG_csid_overflow_END (4)
#define SOC_CSI_WRAPPER_CSI_DBG_csie_overflow_START (5)
#define SOC_CSI_WRAPPER_CSI_DBG_csie_overflow_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcnt : 13;
        unsigned int hcnt_max : 13;
        unsigned int v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIA_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIA_DBG_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIA_DBG_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIA_DBG_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIA_DBG_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIA_DBG_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIA_DBG_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcnt : 13;
        unsigned int hcnt_max : 13;
        unsigned int v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIB_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIB_DBG_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIB_DBG_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIB_DBG_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIB_DBG_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIB_DBG_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIB_DBG_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcnt : 13;
        unsigned int hcnt_max : 13;
        unsigned int v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIC_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIC_DBG_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIC_DBG_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIC_DBG_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIC_DBG_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIC_DBG_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIC_DBG_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcnt : 13;
        unsigned int hcnt_max : 13;
        unsigned int v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSID_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSID_DBG_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSID_DBG_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSID_DBG_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSID_DBG_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSID_DBG_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSID_DBG_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hcnt : 13;
        unsigned int hcnt_max : 13;
        unsigned int v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIE_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIE_DBG_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIE_DBG_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIE_DBG_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIE_DBG_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIE_DBG_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIE_DBG_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csi_abc_secure : 1;
        unsigned int csi_d_secure : 1;
        unsigned int csi_e_secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_CSI_WRAPPER_S_UNION;
#endif
#define SOC_CSI_WRAPPER_S_csi_abc_secure_START (0)
#define SOC_CSI_WRAPPER_S_csi_abc_secure_END (0)
#define SOC_CSI_WRAPPER_S_csi_d_secure_START (1)
#define SOC_CSI_WRAPPER_S_csi_d_secure_END (1)
#define SOC_CSI_WRAPPER_S_csi_e_secure_START (2)
#define SOC_CSI_WRAPPER_S_csi_e_secure_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
