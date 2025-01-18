#ifndef __SOC_MODEM_CRG_INTERFACE_H__
#define __SOC_MODEM_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_MODEM_CRG_CLKEN0_ADDR(base) ((base) + (0x000))
#define SOC_MODEM_CRG_CLKDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MODEM_CRG_CLKSTAT0_ADDR(base) ((base) + (0x008))
#define SOC_MODEM_CRG_CLKCG_STAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MODEM_CRG_CLKEN1_ADDR(base) ((base) + (0x010))
#define SOC_MODEM_CRG_CLKDIS1_ADDR(base) ((base) + (0x014))
#define SOC_MODEM_CRG_CLKSTAT1_ADDR(base) ((base) + (0x018))
#define SOC_MODEM_CRG_CLKCG_STAT1_ADDR(base) ((base) + (0x01C))
#define SOC_MODEM_CRG_SRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_MODEM_CRG_SRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_MODEM_CRG_SRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_MODEM_CRG_SRSTEN1_ADDR(base) ((base) + (0x030))
#define SOC_MODEM_CRG_SRSTDIS1_ADDR(base) ((base) + (0x034))
#define SOC_MODEM_CRG_SRSTSTAT1_ADDR(base) ((base) + (0x038))
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ADDR(base) ((base) + (0x03C))
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_ADDR(base) ((base) + (0x040))
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_ADDR(base) ((base) + (0x044))
#define SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_ADDR(base) ((base) + (0x048))
#define SOC_MODEM_CRG_MDM_ABB_SCPLL0_EN_ADDR(base) ((base) + (0x04C))
#define SOC_MODEM_CRG_DSP0_CLK_SEL_ADDR(base) ((base) + (0x054))
#define SOC_MODEM_CRG_CDSP_CLK_SEL_ADDR(base) ((base) + (0x058))
#define SOC_MODEM_CRG_A9WDT_RSTEN_ADDR(base) ((base) + (0x060))
#define SOC_MODEM_CRG_DSP_DFS_CTRL_ADDR(base) ((base) + (0x64))
#define SOC_MODEM_CRG_CDSP_DFS_CTRL_ADDR(base) ((base) + (0x68))
#define SOC_MODEM_CRG_CLKSW_STAT_ADDR(base) ((base) + (0x6C))
#define SOC_MODEM_CRG_CLKEN2_ADDR(base) ((base) + (0x70))
#define SOC_MODEM_CRG_CLKDIS2_ADDR(base) ((base) + (0x74))
#define SOC_MODEM_CRG_CLKSTAT2_ADDR(base) ((base) + (0x78))
#define SOC_MODEM_CRG_CLKCG_STAT2_ADDR(base) ((base) + (0x7C))
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_ADDR(base) ((base) + (0x200))
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_ADDR(base) ((base) + (0x204))
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_ADDR(base) ((base) + (0x208))
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_ADDR(base) ((base) + (0x20C))
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_ADDR(base) ((base) + (0x210))
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_ADDR(base) ((base) + (0x214))
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_ADDR(base) ((base) + (0x218))
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_ADDR(base) ((base) + (0x21C))
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_ADDR(base) ((base) + (0x220))
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_ADDR(base) ((base) + (0x224))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bbp3_refclk_en : 1;
        unsigned int dsp0_edmac1_clk_en : 1;
        unsigned int dsp0_dbg_clk_en : 1;
        unsigned int bbp0_refclk_en : 1;
        unsigned int bbp2_refclk_en : 1;
        unsigned int ccpu_dbg_clk_en : 1;
        unsigned int dsp0_edmac_clk_en : 1;
        unsigned int mdm_hpm_clk_en : 1;
        unsigned int cicom0_clk_en : 1;
        unsigned int reserved : 1;
        unsigned int dsp0_atb_clk_en : 1;
        unsigned int upacc_clk_en : 1;
        unsigned int sci0_clk_en : 1;
        unsigned int sci1_clk_en : 1;
        unsigned int mdm_uart1_clk_en : 1;
        unsigned int mdm_uart_clk_en : 1;
        unsigned int dfc_clk_en : 1;
        unsigned int cipher_clk_en : 1;
        unsigned int ccpu_edmac_clk_en : 1;
        unsigned int dsp_refclk_en : 1;
        unsigned int ccpu_refclk_en : 1;
        unsigned int rtc_clk_en : 1;
        unsigned int mdm_aximon_clk_en : 1;
        unsigned int ipcm_clk_en : 1;
        unsigned int hdlc_clk_en : 1;
        unsigned int ccpu_edmac1_clk_en : 1;
        unsigned int cicom1_clk_en : 1;
        unsigned int ccpu_psam_clk_en : 1;
        unsigned int ccpu_ipf_clk_en : 1;
        unsigned int peri_refclk_en : 1;
        unsigned int cipher_refclk_en : 1;
        unsigned int bbp1_refclk_en : 1;
    } reg;
} SOC_MODEM_CRG_CLKEN0_UNION;
#endif
#define SOC_MODEM_CRG_CLKEN0_bbp3_refclk_en_START (0)
#define SOC_MODEM_CRG_CLKEN0_bbp3_refclk_en_END (0)
#define SOC_MODEM_CRG_CLKEN0_dsp0_edmac1_clk_en_START (1)
#define SOC_MODEM_CRG_CLKEN0_dsp0_edmac1_clk_en_END (1)
#define SOC_MODEM_CRG_CLKEN0_dsp0_dbg_clk_en_START (2)
#define SOC_MODEM_CRG_CLKEN0_dsp0_dbg_clk_en_END (2)
#define SOC_MODEM_CRG_CLKEN0_bbp0_refclk_en_START (3)
#define SOC_MODEM_CRG_CLKEN0_bbp0_refclk_en_END (3)
#define SOC_MODEM_CRG_CLKEN0_bbp2_refclk_en_START (4)
#define SOC_MODEM_CRG_CLKEN0_bbp2_refclk_en_END (4)
#define SOC_MODEM_CRG_CLKEN0_ccpu_dbg_clk_en_START (5)
#define SOC_MODEM_CRG_CLKEN0_ccpu_dbg_clk_en_END (5)
#define SOC_MODEM_CRG_CLKEN0_dsp0_edmac_clk_en_START (6)
#define SOC_MODEM_CRG_CLKEN0_dsp0_edmac_clk_en_END (6)
#define SOC_MODEM_CRG_CLKEN0_mdm_hpm_clk_en_START (7)
#define SOC_MODEM_CRG_CLKEN0_mdm_hpm_clk_en_END (7)
#define SOC_MODEM_CRG_CLKEN0_cicom0_clk_en_START (8)
#define SOC_MODEM_CRG_CLKEN0_cicom0_clk_en_END (8)
#define SOC_MODEM_CRG_CLKEN0_dsp0_atb_clk_en_START (10)
#define SOC_MODEM_CRG_CLKEN0_dsp0_atb_clk_en_END (10)
#define SOC_MODEM_CRG_CLKEN0_upacc_clk_en_START (11)
#define SOC_MODEM_CRG_CLKEN0_upacc_clk_en_END (11)
#define SOC_MODEM_CRG_CLKEN0_sci0_clk_en_START (12)
#define SOC_MODEM_CRG_CLKEN0_sci0_clk_en_END (12)
#define SOC_MODEM_CRG_CLKEN0_sci1_clk_en_START (13)
#define SOC_MODEM_CRG_CLKEN0_sci1_clk_en_END (13)
#define SOC_MODEM_CRG_CLKEN0_mdm_uart1_clk_en_START (14)
#define SOC_MODEM_CRG_CLKEN0_mdm_uart1_clk_en_END (14)
#define SOC_MODEM_CRG_CLKEN0_mdm_uart_clk_en_START (15)
#define SOC_MODEM_CRG_CLKEN0_mdm_uart_clk_en_END (15)
#define SOC_MODEM_CRG_CLKEN0_dfc_clk_en_START (16)
#define SOC_MODEM_CRG_CLKEN0_dfc_clk_en_END (16)
#define SOC_MODEM_CRG_CLKEN0_cipher_clk_en_START (17)
#define SOC_MODEM_CRG_CLKEN0_cipher_clk_en_END (17)
#define SOC_MODEM_CRG_CLKEN0_ccpu_edmac_clk_en_START (18)
#define SOC_MODEM_CRG_CLKEN0_ccpu_edmac_clk_en_END (18)
#define SOC_MODEM_CRG_CLKEN0_dsp_refclk_en_START (19)
#define SOC_MODEM_CRG_CLKEN0_dsp_refclk_en_END (19)
#define SOC_MODEM_CRG_CLKEN0_ccpu_refclk_en_START (20)
#define SOC_MODEM_CRG_CLKEN0_ccpu_refclk_en_END (20)
#define SOC_MODEM_CRG_CLKEN0_rtc_clk_en_START (21)
#define SOC_MODEM_CRG_CLKEN0_rtc_clk_en_END (21)
#define SOC_MODEM_CRG_CLKEN0_mdm_aximon_clk_en_START (22)
#define SOC_MODEM_CRG_CLKEN0_mdm_aximon_clk_en_END (22)
#define SOC_MODEM_CRG_CLKEN0_ipcm_clk_en_START (23)
#define SOC_MODEM_CRG_CLKEN0_ipcm_clk_en_END (23)
#define SOC_MODEM_CRG_CLKEN0_hdlc_clk_en_START (24)
#define SOC_MODEM_CRG_CLKEN0_hdlc_clk_en_END (24)
#define SOC_MODEM_CRG_CLKEN0_ccpu_edmac1_clk_en_START (25)
#define SOC_MODEM_CRG_CLKEN0_ccpu_edmac1_clk_en_END (25)
#define SOC_MODEM_CRG_CLKEN0_cicom1_clk_en_START (26)
#define SOC_MODEM_CRG_CLKEN0_cicom1_clk_en_END (26)
#define SOC_MODEM_CRG_CLKEN0_ccpu_psam_clk_en_START (27)
#define SOC_MODEM_CRG_CLKEN0_ccpu_psam_clk_en_END (27)
#define SOC_MODEM_CRG_CLKEN0_ccpu_ipf_clk_en_START (28)
#define SOC_MODEM_CRG_CLKEN0_ccpu_ipf_clk_en_END (28)
#define SOC_MODEM_CRG_CLKEN0_peri_refclk_en_START (29)
#define SOC_MODEM_CRG_CLKEN0_peri_refclk_en_END (29)
#define SOC_MODEM_CRG_CLKEN0_cipher_refclk_en_START (30)
#define SOC_MODEM_CRG_CLKEN0_cipher_refclk_en_END (30)
#define SOC_MODEM_CRG_CLKEN0_bbp1_refclk_en_START (31)
#define SOC_MODEM_CRG_CLKEN0_bbp1_refclk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bbp3_refclk_dis : 1;
        unsigned int dsp0_edmac1_clk_dis : 1;
        unsigned int dsp0_dbg_clk_dis : 1;
        unsigned int bbp0_refclk_dis : 1;
        unsigned int bbp2_refclk_dis : 1;
        unsigned int ccpu_dbg_clk_dis : 1;
        unsigned int dsp0_edmac_clk_dis : 1;
        unsigned int mdm_hpm_clk_dis : 1;
        unsigned int cicom0_clk_dis : 1;
        unsigned int rsv : 1;
        unsigned int reserved : 1;
        unsigned int upacc_clk_dis : 1;
        unsigned int sci0_clk_dis : 1;
        unsigned int sci1_clk_dis : 1;
        unsigned int mdm_uart1_clk_dis : 1;
        unsigned int mdm_uart_clk_dis : 1;
        unsigned int dfc_clk_dis : 1;
        unsigned int cipher_clk_dis : 1;
        unsigned int ccpu_edmac_clk_dis : 1;
        unsigned int dsp_refclk_dis : 1;
        unsigned int ccpu_refclk_dis : 1;
        unsigned int rtc_clk_dis : 1;
        unsigned int mdm_aximon_clk_dis : 1;
        unsigned int ipcm_clk_dis : 1;
        unsigned int hdlc_clk_dis : 1;
        unsigned int ccpu_edmac1_clk_dis : 1;
        unsigned int cicom1_clk_dis : 1;
        unsigned int ccpu_psam_clk_dis : 1;
        unsigned int ccpu_ipf_clk_dis : 1;
        unsigned int peri_refclk_dis : 1;
        unsigned int cipher_refclk_dis : 1;
        unsigned int bbp1_refclk_dis : 1;
    } reg;
} SOC_MODEM_CRG_CLKDIS0_UNION;
#endif
#define SOC_MODEM_CRG_CLKDIS0_bbp3_refclk_dis_START (0)
#define SOC_MODEM_CRG_CLKDIS0_bbp3_refclk_dis_END (0)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_edmac1_clk_dis_START (1)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_edmac1_clk_dis_END (1)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_dbg_clk_dis_START (2)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_dbg_clk_dis_END (2)
#define SOC_MODEM_CRG_CLKDIS0_bbp0_refclk_dis_START (3)
#define SOC_MODEM_CRG_CLKDIS0_bbp0_refclk_dis_END (3)
#define SOC_MODEM_CRG_CLKDIS0_bbp2_refclk_dis_START (4)
#define SOC_MODEM_CRG_CLKDIS0_bbp2_refclk_dis_END (4)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_dbg_clk_dis_START (5)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_dbg_clk_dis_END (5)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_edmac_clk_dis_START (6)
#define SOC_MODEM_CRG_CLKDIS0_dsp0_edmac_clk_dis_END (6)
#define SOC_MODEM_CRG_CLKDIS0_mdm_hpm_clk_dis_START (7)
#define SOC_MODEM_CRG_CLKDIS0_mdm_hpm_clk_dis_END (7)
#define SOC_MODEM_CRG_CLKDIS0_cicom0_clk_dis_START (8)
#define SOC_MODEM_CRG_CLKDIS0_cicom0_clk_dis_END (8)
#define SOC_MODEM_CRG_CLKDIS0_rsv_START (9)
#define SOC_MODEM_CRG_CLKDIS0_rsv_END (9)
#define SOC_MODEM_CRG_CLKDIS0_upacc_clk_dis_START (11)
#define SOC_MODEM_CRG_CLKDIS0_upacc_clk_dis_END (11)
#define SOC_MODEM_CRG_CLKDIS0_sci0_clk_dis_START (12)
#define SOC_MODEM_CRG_CLKDIS0_sci0_clk_dis_END (12)
#define SOC_MODEM_CRG_CLKDIS0_sci1_clk_dis_START (13)
#define SOC_MODEM_CRG_CLKDIS0_sci1_clk_dis_END (13)
#define SOC_MODEM_CRG_CLKDIS0_mdm_uart1_clk_dis_START (14)
#define SOC_MODEM_CRG_CLKDIS0_mdm_uart1_clk_dis_END (14)
#define SOC_MODEM_CRG_CLKDIS0_mdm_uart_clk_dis_START (15)
#define SOC_MODEM_CRG_CLKDIS0_mdm_uart_clk_dis_END (15)
#define SOC_MODEM_CRG_CLKDIS0_dfc_clk_dis_START (16)
#define SOC_MODEM_CRG_CLKDIS0_dfc_clk_dis_END (16)
#define SOC_MODEM_CRG_CLKDIS0_cipher_clk_dis_START (17)
#define SOC_MODEM_CRG_CLKDIS0_cipher_clk_dis_END (17)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_edmac_clk_dis_START (18)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_edmac_clk_dis_END (18)
#define SOC_MODEM_CRG_CLKDIS0_dsp_refclk_dis_START (19)
#define SOC_MODEM_CRG_CLKDIS0_dsp_refclk_dis_END (19)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_refclk_dis_START (20)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_refclk_dis_END (20)
#define SOC_MODEM_CRG_CLKDIS0_rtc_clk_dis_START (21)
#define SOC_MODEM_CRG_CLKDIS0_rtc_clk_dis_END (21)
#define SOC_MODEM_CRG_CLKDIS0_mdm_aximon_clk_dis_START (22)
#define SOC_MODEM_CRG_CLKDIS0_mdm_aximon_clk_dis_END (22)
#define SOC_MODEM_CRG_CLKDIS0_ipcm_clk_dis_START (23)
#define SOC_MODEM_CRG_CLKDIS0_ipcm_clk_dis_END (23)
#define SOC_MODEM_CRG_CLKDIS0_hdlc_clk_dis_START (24)
#define SOC_MODEM_CRG_CLKDIS0_hdlc_clk_dis_END (24)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_edmac1_clk_dis_START (25)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_edmac1_clk_dis_END (25)
#define SOC_MODEM_CRG_CLKDIS0_cicom1_clk_dis_START (26)
#define SOC_MODEM_CRG_CLKDIS0_cicom1_clk_dis_END (26)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_psam_clk_dis_START (27)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_psam_clk_dis_END (27)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_ipf_clk_dis_START (28)
#define SOC_MODEM_CRG_CLKDIS0_ccpu_ipf_clk_dis_END (28)
#define SOC_MODEM_CRG_CLKDIS0_peri_refclk_dis_START (29)
#define SOC_MODEM_CRG_CLKDIS0_peri_refclk_dis_END (29)
#define SOC_MODEM_CRG_CLKDIS0_cipher_refclk_dis_START (30)
#define SOC_MODEM_CRG_CLKDIS0_cipher_refclk_dis_END (30)
#define SOC_MODEM_CRG_CLKDIS0_bbp1_refclk_dis_START (31)
#define SOC_MODEM_CRG_CLKDIS0_bbp1_refclk_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bbp3_refclk_status : 1;
        unsigned int dsp0_edmac1_clk_status : 1;
        unsigned int dsp0_dbg_clk_status : 1;
        unsigned int bbp0_refclk_status : 1;
        unsigned int bbp2_refclk_status : 1;
        unsigned int ccpu_dbg_clk_status : 1;
        unsigned int dsp0_edmac_clk_status : 1;
        unsigned int mdm_hpm_clk_status : 1;
        unsigned int cicom0_clk_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int upacc_clk_status : 1;
        unsigned int sci0_clk_status : 1;
        unsigned int sci1_clk_status : 1;
        unsigned int mdm_uart1_clk_status : 1;
        unsigned int mdm_uart_clk_status : 1;
        unsigned int dfc_clk_status : 1;
        unsigned int cipher_clk_status : 1;
        unsigned int ccpu_edmac_clk_status : 1;
        unsigned int dsp_refclk_status : 1;
        unsigned int ccpu_refclk_status : 1;
        unsigned int rtc_clk_status : 1;
        unsigned int mdm_aximon_clk_status : 1;
        unsigned int ipcm_clk_status : 1;
        unsigned int hdlc_clk_status : 1;
        unsigned int ccpu_edmac1_clk_status : 1;
        unsigned int cicom1_clk_status : 1;
        unsigned int ccpu_psam_clk_status : 1;
        unsigned int ccpu_ipf_clk_status : 1;
        unsigned int peri_refclk_status : 1;
        unsigned int cipher_refclk_status : 1;
        unsigned int bbp_refclk_status : 1;
    } reg;
} SOC_MODEM_CRG_CLKSTAT0_UNION;
#endif
#define SOC_MODEM_CRG_CLKSTAT0_bbp3_refclk_status_START (0)
#define SOC_MODEM_CRG_CLKSTAT0_bbp3_refclk_status_END (0)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_edmac1_clk_status_START (1)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_edmac1_clk_status_END (1)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_dbg_clk_status_START (2)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_dbg_clk_status_END (2)
#define SOC_MODEM_CRG_CLKSTAT0_bbp0_refclk_status_START (3)
#define SOC_MODEM_CRG_CLKSTAT0_bbp0_refclk_status_END (3)
#define SOC_MODEM_CRG_CLKSTAT0_bbp2_refclk_status_START (4)
#define SOC_MODEM_CRG_CLKSTAT0_bbp2_refclk_status_END (4)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_dbg_clk_status_START (5)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_dbg_clk_status_END (5)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_edmac_clk_status_START (6)
#define SOC_MODEM_CRG_CLKSTAT0_dsp0_edmac_clk_status_END (6)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_hpm_clk_status_START (7)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_hpm_clk_status_END (7)
#define SOC_MODEM_CRG_CLKSTAT0_cicom0_clk_status_START (8)
#define SOC_MODEM_CRG_CLKSTAT0_cicom0_clk_status_END (8)
#define SOC_MODEM_CRG_CLKSTAT0_upacc_clk_status_START (11)
#define SOC_MODEM_CRG_CLKSTAT0_upacc_clk_status_END (11)
#define SOC_MODEM_CRG_CLKSTAT0_sci0_clk_status_START (12)
#define SOC_MODEM_CRG_CLKSTAT0_sci0_clk_status_END (12)
#define SOC_MODEM_CRG_CLKSTAT0_sci1_clk_status_START (13)
#define SOC_MODEM_CRG_CLKSTAT0_sci1_clk_status_END (13)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_uart1_clk_status_START (14)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_uart1_clk_status_END (14)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_uart_clk_status_START (15)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_uart_clk_status_END (15)
#define SOC_MODEM_CRG_CLKSTAT0_dfc_clk_status_START (16)
#define SOC_MODEM_CRG_CLKSTAT0_dfc_clk_status_END (16)
#define SOC_MODEM_CRG_CLKSTAT0_cipher_clk_status_START (17)
#define SOC_MODEM_CRG_CLKSTAT0_cipher_clk_status_END (17)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_edmac_clk_status_START (18)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_edmac_clk_status_END (18)
#define SOC_MODEM_CRG_CLKSTAT0_dsp_refclk_status_START (19)
#define SOC_MODEM_CRG_CLKSTAT0_dsp_refclk_status_END (19)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_refclk_status_START (20)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_refclk_status_END (20)
#define SOC_MODEM_CRG_CLKSTAT0_rtc_clk_status_START (21)
#define SOC_MODEM_CRG_CLKSTAT0_rtc_clk_status_END (21)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_aximon_clk_status_START (22)
#define SOC_MODEM_CRG_CLKSTAT0_mdm_aximon_clk_status_END (22)
#define SOC_MODEM_CRG_CLKSTAT0_ipcm_clk_status_START (23)
#define SOC_MODEM_CRG_CLKSTAT0_ipcm_clk_status_END (23)
#define SOC_MODEM_CRG_CLKSTAT0_hdlc_clk_status_START (24)
#define SOC_MODEM_CRG_CLKSTAT0_hdlc_clk_status_END (24)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_edmac1_clk_status_START (25)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_edmac1_clk_status_END (25)
#define SOC_MODEM_CRG_CLKSTAT0_cicom1_clk_status_START (26)
#define SOC_MODEM_CRG_CLKSTAT0_cicom1_clk_status_END (26)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_psam_clk_status_START (27)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_psam_clk_status_END (27)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_ipf_clk_status_START (28)
#define SOC_MODEM_CRG_CLKSTAT0_ccpu_ipf_clk_status_END (28)
#define SOC_MODEM_CRG_CLKSTAT0_peri_refclk_status_START (29)
#define SOC_MODEM_CRG_CLKSTAT0_peri_refclk_status_END (29)
#define SOC_MODEM_CRG_CLKSTAT0_cipher_refclk_status_START (30)
#define SOC_MODEM_CRG_CLKSTAT0_cipher_refclk_status_END (30)
#define SOC_MODEM_CRG_CLKSTAT0_bbp_refclk_status_START (31)
#define SOC_MODEM_CRG_CLKSTAT0_bbp_refclk_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bbp3_clkcg_status : 1;
        unsigned int dsp0_edmac1_clkcg_status : 1;
        unsigned int dsp0_dbg_clkcg_status : 1;
        unsigned int bbp0_clkcg_status : 1;
        unsigned int bbp2_clkcg_status : 1;
        unsigned int ccpu_dbg_clkcg_status : 1;
        unsigned int dsp0_edmac_clkcg_status : 1;
        unsigned int hpm_clkcg_status : 1;
        unsigned int cicom0_clkcg_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int upacc_clkcg_status : 1;
        unsigned int sci0_clkcg_status : 1;
        unsigned int sci1_clkcg_status : 1;
        unsigned int mdm_uart1_clkcg_status : 1;
        unsigned int mdm_uart_clkcg_status : 1;
        unsigned int dfc_clkcg_status : 1;
        unsigned int cipher_clkcg_status : 1;
        unsigned int ccpu_edmac_clkcg_status : 1;
        unsigned int dsp_refclkcg_status : 1;
        unsigned int ccpu_refclkcg_status : 1;
        unsigned int rtc_clkcg_status : 1;
        unsigned int mdm_aximon_clkcg_status : 1;
        unsigned int ipcm_clkcg_status : 1;
        unsigned int hdlc_clkcg_status : 1;
        unsigned int ccpu_edmac1_clkcg_status : 1;
        unsigned int cicom1_clkcg_status : 1;
        unsigned int psam_clkcg_status : 1;
        unsigned int ccpu_ipf_clkcg_status : 1;
        unsigned int peri_refclkcg_status : 1;
        unsigned int cipher_refclkcg_status : 1;
        unsigned int bbp_refclkcg_status : 1;
    } reg;
} SOC_MODEM_CRG_CLKCG_STAT0_UNION;
#endif
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp3_clkcg_status_START (0)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp3_clkcg_status_END (0)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_edmac1_clkcg_status_START (1)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_edmac1_clkcg_status_END (1)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_dbg_clkcg_status_START (2)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_dbg_clkcg_status_END (2)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp0_clkcg_status_START (3)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp0_clkcg_status_END (3)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp2_clkcg_status_START (4)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp2_clkcg_status_END (4)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_dbg_clkcg_status_START (5)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_dbg_clkcg_status_END (5)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_edmac_clkcg_status_START (6)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp0_edmac_clkcg_status_END (6)
#define SOC_MODEM_CRG_CLKCG_STAT0_hpm_clkcg_status_START (7)
#define SOC_MODEM_CRG_CLKCG_STAT0_hpm_clkcg_status_END (7)
#define SOC_MODEM_CRG_CLKCG_STAT0_cicom0_clkcg_status_START (8)
#define SOC_MODEM_CRG_CLKCG_STAT0_cicom0_clkcg_status_END (8)
#define SOC_MODEM_CRG_CLKCG_STAT0_upacc_clkcg_status_START (11)
#define SOC_MODEM_CRG_CLKCG_STAT0_upacc_clkcg_status_END (11)
#define SOC_MODEM_CRG_CLKCG_STAT0_sci0_clkcg_status_START (12)
#define SOC_MODEM_CRG_CLKCG_STAT0_sci0_clkcg_status_END (12)
#define SOC_MODEM_CRG_CLKCG_STAT0_sci1_clkcg_status_START (13)
#define SOC_MODEM_CRG_CLKCG_STAT0_sci1_clkcg_status_END (13)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_uart1_clkcg_status_START (14)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_uart1_clkcg_status_END (14)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_uart_clkcg_status_START (15)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_uart_clkcg_status_END (15)
#define SOC_MODEM_CRG_CLKCG_STAT0_dfc_clkcg_status_START (16)
#define SOC_MODEM_CRG_CLKCG_STAT0_dfc_clkcg_status_END (16)
#define SOC_MODEM_CRG_CLKCG_STAT0_cipher_clkcg_status_START (17)
#define SOC_MODEM_CRG_CLKCG_STAT0_cipher_clkcg_status_END (17)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_edmac_clkcg_status_START (18)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_edmac_clkcg_status_END (18)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp_refclkcg_status_START (19)
#define SOC_MODEM_CRG_CLKCG_STAT0_dsp_refclkcg_status_END (19)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_refclkcg_status_START (20)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_refclkcg_status_END (20)
#define SOC_MODEM_CRG_CLKCG_STAT0_rtc_clkcg_status_START (21)
#define SOC_MODEM_CRG_CLKCG_STAT0_rtc_clkcg_status_END (21)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_aximon_clkcg_status_START (22)
#define SOC_MODEM_CRG_CLKCG_STAT0_mdm_aximon_clkcg_status_END (22)
#define SOC_MODEM_CRG_CLKCG_STAT0_ipcm_clkcg_status_START (23)
#define SOC_MODEM_CRG_CLKCG_STAT0_ipcm_clkcg_status_END (23)
#define SOC_MODEM_CRG_CLKCG_STAT0_hdlc_clkcg_status_START (24)
#define SOC_MODEM_CRG_CLKCG_STAT0_hdlc_clkcg_status_END (24)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_edmac1_clkcg_status_START (25)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_edmac1_clkcg_status_END (25)
#define SOC_MODEM_CRG_CLKCG_STAT0_cicom1_clkcg_status_START (26)
#define SOC_MODEM_CRG_CLKCG_STAT0_cicom1_clkcg_status_END (26)
#define SOC_MODEM_CRG_CLKCG_STAT0_psam_clkcg_status_START (27)
#define SOC_MODEM_CRG_CLKCG_STAT0_psam_clkcg_status_END (27)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_ipf_clkcg_status_START (28)
#define SOC_MODEM_CRG_CLKCG_STAT0_ccpu_ipf_clkcg_status_END (28)
#define SOC_MODEM_CRG_CLKCG_STAT0_peri_refclkcg_status_START (29)
#define SOC_MODEM_CRG_CLKCG_STAT0_peri_refclkcg_status_END (29)
#define SOC_MODEM_CRG_CLKCG_STAT0_cipher_refclkcg_status_START (30)
#define SOC_MODEM_CRG_CLKCG_STAT0_cipher_refclkcg_status_END (30)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp_refclkcg_status_START (31)
#define SOC_MODEM_CRG_CLKCG_STAT0_bbp_refclkcg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_clk_en : 10;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dsp0_pd_clk_en : 1;
        unsigned int bbpon_clk_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int drx2soc_timer_clk_en : 1;
        unsigned int rsr_acc_clk_en : 1;
        unsigned int dsp0_wdog_clk_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ccpu_core0_wdog_clk_en : 1;
        unsigned int ccpu_core1_wdog_clk_en : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int noc_ccpu_clk_en : 1;
        unsigned int reserved_7 : 1;
        unsigned int noc_dsp0_clk_en : 1;
        unsigned int bbp2_pd_clk_en : 1;
        unsigned int noc_bbp_clk_en : 1;
        unsigned int bbp_pd_clk_en : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_MODEM_CRG_CLKEN1_UNION;
#endif
#define SOC_MODEM_CRG_CLKEN1_mdm_timer_clk_en_START (0)
#define SOC_MODEM_CRG_CLKEN1_mdm_timer_clk_en_END (9)
#define SOC_MODEM_CRG_CLKEN1_dsp0_pd_clk_en_START (12)
#define SOC_MODEM_CRG_CLKEN1_dsp0_pd_clk_en_END (12)
#define SOC_MODEM_CRG_CLKEN1_bbpon_clk_en_START (13)
#define SOC_MODEM_CRG_CLKEN1_bbpon_clk_en_END (13)
#define SOC_MODEM_CRG_CLKEN1_drx2soc_timer_clk_en_START (15)
#define SOC_MODEM_CRG_CLKEN1_drx2soc_timer_clk_en_END (15)
#define SOC_MODEM_CRG_CLKEN1_rsr_acc_clk_en_START (16)
#define SOC_MODEM_CRG_CLKEN1_rsr_acc_clk_en_END (16)
#define SOC_MODEM_CRG_CLKEN1_dsp0_wdog_clk_en_START (17)
#define SOC_MODEM_CRG_CLKEN1_dsp0_wdog_clk_en_END (17)
#define SOC_MODEM_CRG_CLKEN1_ccpu_core0_wdog_clk_en_START (20)
#define SOC_MODEM_CRG_CLKEN1_ccpu_core0_wdog_clk_en_END (20)
#define SOC_MODEM_CRG_CLKEN1_ccpu_core1_wdog_clk_en_START (21)
#define SOC_MODEM_CRG_CLKEN1_ccpu_core1_wdog_clk_en_END (21)
#define SOC_MODEM_CRG_CLKEN1_noc_ccpu_clk_en_START (24)
#define SOC_MODEM_CRG_CLKEN1_noc_ccpu_clk_en_END (24)
#define SOC_MODEM_CRG_CLKEN1_noc_dsp0_clk_en_START (26)
#define SOC_MODEM_CRG_CLKEN1_noc_dsp0_clk_en_END (26)
#define SOC_MODEM_CRG_CLKEN1_bbp2_pd_clk_en_START (27)
#define SOC_MODEM_CRG_CLKEN1_bbp2_pd_clk_en_END (27)
#define SOC_MODEM_CRG_CLKEN1_noc_bbp_clk_en_START (28)
#define SOC_MODEM_CRG_CLKEN1_noc_bbp_clk_en_END (28)
#define SOC_MODEM_CRG_CLKEN1_bbp_pd_clk_en_START (29)
#define SOC_MODEM_CRG_CLKEN1_bbp_pd_clk_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_clk_dis : 10;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dsp0_pd_clk_dis : 1;
        unsigned int bbpon_clk_dis : 1;
        unsigned int reserved_2 : 1;
        unsigned int drx2soc_timer_clk_dis : 1;
        unsigned int rsr_acc_clk_dis : 1;
        unsigned int dsp0_wdog_clk_dis : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ccpu_core0_wdog_clk_dis : 1;
        unsigned int ccpu_core1_wdog_clk_dis : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int noc_ccpu_clk_dis : 1;
        unsigned int reserved_7 : 1;
        unsigned int noc_dsp0_clk_dis : 1;
        unsigned int bbp2_pd_clk_dis : 1;
        unsigned int noc_bbp_clk_dis : 1;
        unsigned int bbp_pd_clk_dis : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_MODEM_CRG_CLKDIS1_UNION;
#endif
#define SOC_MODEM_CRG_CLKDIS1_mdm_timer_clk_dis_START (0)
#define SOC_MODEM_CRG_CLKDIS1_mdm_timer_clk_dis_END (9)
#define SOC_MODEM_CRG_CLKDIS1_dsp0_pd_clk_dis_START (12)
#define SOC_MODEM_CRG_CLKDIS1_dsp0_pd_clk_dis_END (12)
#define SOC_MODEM_CRG_CLKDIS1_bbpon_clk_dis_START (13)
#define SOC_MODEM_CRG_CLKDIS1_bbpon_clk_dis_END (13)
#define SOC_MODEM_CRG_CLKDIS1_drx2soc_timer_clk_dis_START (15)
#define SOC_MODEM_CRG_CLKDIS1_drx2soc_timer_clk_dis_END (15)
#define SOC_MODEM_CRG_CLKDIS1_rsr_acc_clk_dis_START (16)
#define SOC_MODEM_CRG_CLKDIS1_rsr_acc_clk_dis_END (16)
#define SOC_MODEM_CRG_CLKDIS1_dsp0_wdog_clk_dis_START (17)
#define SOC_MODEM_CRG_CLKDIS1_dsp0_wdog_clk_dis_END (17)
#define SOC_MODEM_CRG_CLKDIS1_ccpu_core0_wdog_clk_dis_START (20)
#define SOC_MODEM_CRG_CLKDIS1_ccpu_core0_wdog_clk_dis_END (20)
#define SOC_MODEM_CRG_CLKDIS1_ccpu_core1_wdog_clk_dis_START (21)
#define SOC_MODEM_CRG_CLKDIS1_ccpu_core1_wdog_clk_dis_END (21)
#define SOC_MODEM_CRG_CLKDIS1_noc_ccpu_clk_dis_START (24)
#define SOC_MODEM_CRG_CLKDIS1_noc_ccpu_clk_dis_END (24)
#define SOC_MODEM_CRG_CLKDIS1_noc_dsp0_clk_dis_START (26)
#define SOC_MODEM_CRG_CLKDIS1_noc_dsp0_clk_dis_END (26)
#define SOC_MODEM_CRG_CLKDIS1_bbp2_pd_clk_dis_START (27)
#define SOC_MODEM_CRG_CLKDIS1_bbp2_pd_clk_dis_END (27)
#define SOC_MODEM_CRG_CLKDIS1_noc_bbp_clk_dis_START (28)
#define SOC_MODEM_CRG_CLKDIS1_noc_bbp_clk_dis_END (28)
#define SOC_MODEM_CRG_CLKDIS1_bbp_pd_clk_dis_START (29)
#define SOC_MODEM_CRG_CLKDIS1_bbp_pd_clk_dis_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_clk_status : 10;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dsp0_pd_clk_status : 1;
        unsigned int bbpon_clk_status : 1;
        unsigned int reserved_2 : 1;
        unsigned int drx2soc_timer_clk_status : 1;
        unsigned int rsr_acc_clk_status : 1;
        unsigned int dsp0_wdog_clk_status : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ccpu_core0_wdog_clk_status : 1;
        unsigned int ccpu_core1_wdog_clk_status : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int noc_ccpu_clk_status : 1;
        unsigned int noc_dsp0_clk_status : 1;
        unsigned int noc_dsp1_clk_status : 1;
        unsigned int bbp2_pd_clk_status : 1;
        unsigned int noc_bbp_clk_status : 1;
        unsigned int bbp_pd_clk_status : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_MODEM_CRG_CLKSTAT1_UNION;
#endif
#define SOC_MODEM_CRG_CLKSTAT1_mdm_timer_clk_status_START (0)
#define SOC_MODEM_CRG_CLKSTAT1_mdm_timer_clk_status_END (9)
#define SOC_MODEM_CRG_CLKSTAT1_dsp0_pd_clk_status_START (12)
#define SOC_MODEM_CRG_CLKSTAT1_dsp0_pd_clk_status_END (12)
#define SOC_MODEM_CRG_CLKSTAT1_bbpon_clk_status_START (13)
#define SOC_MODEM_CRG_CLKSTAT1_bbpon_clk_status_END (13)
#define SOC_MODEM_CRG_CLKSTAT1_drx2soc_timer_clk_status_START (15)
#define SOC_MODEM_CRG_CLKSTAT1_drx2soc_timer_clk_status_END (15)
#define SOC_MODEM_CRG_CLKSTAT1_rsr_acc_clk_status_START (16)
#define SOC_MODEM_CRG_CLKSTAT1_rsr_acc_clk_status_END (16)
#define SOC_MODEM_CRG_CLKSTAT1_dsp0_wdog_clk_status_START (17)
#define SOC_MODEM_CRG_CLKSTAT1_dsp0_wdog_clk_status_END (17)
#define SOC_MODEM_CRG_CLKSTAT1_ccpu_core0_wdog_clk_status_START (20)
#define SOC_MODEM_CRG_CLKSTAT1_ccpu_core0_wdog_clk_status_END (20)
#define SOC_MODEM_CRG_CLKSTAT1_ccpu_core1_wdog_clk_status_START (21)
#define SOC_MODEM_CRG_CLKSTAT1_ccpu_core1_wdog_clk_status_END (21)
#define SOC_MODEM_CRG_CLKSTAT1_noc_ccpu_clk_status_START (24)
#define SOC_MODEM_CRG_CLKSTAT1_noc_ccpu_clk_status_END (24)
#define SOC_MODEM_CRG_CLKSTAT1_noc_dsp0_clk_status_START (25)
#define SOC_MODEM_CRG_CLKSTAT1_noc_dsp0_clk_status_END (25)
#define SOC_MODEM_CRG_CLKSTAT1_noc_dsp1_clk_status_START (26)
#define SOC_MODEM_CRG_CLKSTAT1_noc_dsp1_clk_status_END (26)
#define SOC_MODEM_CRG_CLKSTAT1_bbp2_pd_clk_status_START (27)
#define SOC_MODEM_CRG_CLKSTAT1_bbp2_pd_clk_status_END (27)
#define SOC_MODEM_CRG_CLKSTAT1_noc_bbp_clk_status_START (28)
#define SOC_MODEM_CRG_CLKSTAT1_noc_bbp_clk_status_END (28)
#define SOC_MODEM_CRG_CLKSTAT1_bbp_pd_clk_status_START (29)
#define SOC_MODEM_CRG_CLKSTAT1_bbp_pd_clk_status_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_clkcg_status : 10;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dsp0_pd_clkcg_status : 1;
        unsigned int bbpon_clkcg_status : 1;
        unsigned int reserved_2 : 1;
        unsigned int drx2soc_timer_clkcg_status : 1;
        unsigned int rsr_acc_clkcg_status : 1;
        unsigned int dsp0_wdog_clkcg_status : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ccpu_core0_wdog_clkcg_status : 1;
        unsigned int ccpu_core1_wdog_clkcg_status : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int noc_ccpu_clkcg_status : 1;
        unsigned int rsv : 1;
        unsigned int noc_dsp0_clkcg_status : 1;
        unsigned int bbp2_pd_clkcg_status : 1;
        unsigned int noc_bbp_clkcg_status : 1;
        unsigned int bbp0_pd_clkcg_status : 1;
        unsigned int bbp1_pd_clkcg_status : 1;
        unsigned int bbp3_pd_clkcg_status : 1;
    } reg;
} SOC_MODEM_CRG_CLKCG_STAT1_UNION;
#endif
#define SOC_MODEM_CRG_CLKCG_STAT1_mdm_timer_clkcg_status_START (0)
#define SOC_MODEM_CRG_CLKCG_STAT1_mdm_timer_clkcg_status_END (9)
#define SOC_MODEM_CRG_CLKCG_STAT1_dsp0_pd_clkcg_status_START (12)
#define SOC_MODEM_CRG_CLKCG_STAT1_dsp0_pd_clkcg_status_END (12)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbpon_clkcg_status_START (13)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbpon_clkcg_status_END (13)
#define SOC_MODEM_CRG_CLKCG_STAT1_drx2soc_timer_clkcg_status_START (15)
#define SOC_MODEM_CRG_CLKCG_STAT1_drx2soc_timer_clkcg_status_END (15)
#define SOC_MODEM_CRG_CLKCG_STAT1_rsr_acc_clkcg_status_START (16)
#define SOC_MODEM_CRG_CLKCG_STAT1_rsr_acc_clkcg_status_END (16)
#define SOC_MODEM_CRG_CLKCG_STAT1_dsp0_wdog_clkcg_status_START (17)
#define SOC_MODEM_CRG_CLKCG_STAT1_dsp0_wdog_clkcg_status_END (17)
#define SOC_MODEM_CRG_CLKCG_STAT1_ccpu_core0_wdog_clkcg_status_START (20)
#define SOC_MODEM_CRG_CLKCG_STAT1_ccpu_core0_wdog_clkcg_status_END (20)
#define SOC_MODEM_CRG_CLKCG_STAT1_ccpu_core1_wdog_clkcg_status_START (21)
#define SOC_MODEM_CRG_CLKCG_STAT1_ccpu_core1_wdog_clkcg_status_END (21)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_ccpu_clkcg_status_START (24)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_ccpu_clkcg_status_END (24)
#define SOC_MODEM_CRG_CLKCG_STAT1_rsv_START (25)
#define SOC_MODEM_CRG_CLKCG_STAT1_rsv_END (25)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_dsp0_clkcg_status_START (26)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_dsp0_clkcg_status_END (26)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp2_pd_clkcg_status_START (27)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp2_pd_clkcg_status_END (27)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_bbp_clkcg_status_START (28)
#define SOC_MODEM_CRG_CLKCG_STAT1_noc_bbp_clkcg_status_END (28)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp0_pd_clkcg_status_START (29)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp0_pd_clkcg_status_END (29)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp1_pd_clkcg_status_START (30)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp1_pd_clkcg_status_END (30)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp3_pd_clkcg_status_START (31)
#define SOC_MODEM_CRG_CLKCG_STAT1_bbp3_pd_clkcg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int rtc_srst_en : 1;
        unsigned int dfc_srst_en : 1;
        unsigned int ccpu_noc_srst_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int drx2soc_timer_srst_en : 1;
        unsigned int ccpu_core0_srst_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int ccpu_peri_srst_en : 1;
        unsigned int ccpu_scu_srst_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int ccpu_wd0_srst_en : 1;
        unsigned int ccpu_l2c_srst_en : 1;
        unsigned int ccpu_core1_srst_en : 1;
        unsigned int power_mon0_srst_en : 1;
        unsigned int ccpu_pd_srst_en : 1;
        unsigned int power_mon1_srst_en : 1;
        unsigned int power_mon2_srst_en : 1;
        unsigned int power_mon3_srst_en : 1;
        unsigned int hdlc_srst_en : 1;
        unsigned int upacc_srst_en : 1;
        unsigned int rsr_acc_srst_en : 1;
        unsigned int mdm_amon_srst_async_en : 1;
        unsigned int mdm_uart1_srst_en : 1;
        unsigned int mdm_uart_srst_en : 1;
        unsigned int mdm_edmac_srst_en : 1;
        unsigned int mdm_edmac1_srst_en : 1;
        unsigned int cicom0_srst_en : 1;
        unsigned int cicom1_srst_en : 1;
        unsigned int mdm_amon_srst_en : 1;
        unsigned int cipher_srst_en : 1;
        unsigned int hpm_srst_en : 1;
    } reg;
} SOC_MODEM_CRG_SRSTEN0_UNION;
#endif
#define SOC_MODEM_CRG_SRSTEN0_rtc_srst_en_START (1)
#define SOC_MODEM_CRG_SRSTEN0_rtc_srst_en_END (1)
#define SOC_MODEM_CRG_SRSTEN0_dfc_srst_en_START (2)
#define SOC_MODEM_CRG_SRSTEN0_dfc_srst_en_END (2)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_noc_srst_en_START (3)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_noc_srst_en_END (3)
#define SOC_MODEM_CRG_SRSTEN0_drx2soc_timer_srst_en_START (5)
#define SOC_MODEM_CRG_SRSTEN0_drx2soc_timer_srst_en_END (5)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_core0_srst_en_START (6)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_core0_srst_en_END (6)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_peri_srst_en_START (8)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_peri_srst_en_END (8)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_scu_srst_en_START (9)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_scu_srst_en_END (9)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_wd0_srst_en_START (11)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_wd0_srst_en_END (11)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_l2c_srst_en_START (12)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_l2c_srst_en_END (12)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_core1_srst_en_START (13)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_core1_srst_en_END (13)
#define SOC_MODEM_CRG_SRSTEN0_power_mon0_srst_en_START (14)
#define SOC_MODEM_CRG_SRSTEN0_power_mon0_srst_en_END (14)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_pd_srst_en_START (15)
#define SOC_MODEM_CRG_SRSTEN0_ccpu_pd_srst_en_END (15)
#define SOC_MODEM_CRG_SRSTEN0_power_mon1_srst_en_START (16)
#define SOC_MODEM_CRG_SRSTEN0_power_mon1_srst_en_END (16)
#define SOC_MODEM_CRG_SRSTEN0_power_mon2_srst_en_START (17)
#define SOC_MODEM_CRG_SRSTEN0_power_mon2_srst_en_END (17)
#define SOC_MODEM_CRG_SRSTEN0_power_mon3_srst_en_START (18)
#define SOC_MODEM_CRG_SRSTEN0_power_mon3_srst_en_END (18)
#define SOC_MODEM_CRG_SRSTEN0_hdlc_srst_en_START (19)
#define SOC_MODEM_CRG_SRSTEN0_hdlc_srst_en_END (19)
#define SOC_MODEM_CRG_SRSTEN0_upacc_srst_en_START (20)
#define SOC_MODEM_CRG_SRSTEN0_upacc_srst_en_END (20)
#define SOC_MODEM_CRG_SRSTEN0_rsr_acc_srst_en_START (21)
#define SOC_MODEM_CRG_SRSTEN0_rsr_acc_srst_en_END (21)
#define SOC_MODEM_CRG_SRSTEN0_mdm_amon_srst_async_en_START (22)
#define SOC_MODEM_CRG_SRSTEN0_mdm_amon_srst_async_en_END (22)
#define SOC_MODEM_CRG_SRSTEN0_mdm_uart1_srst_en_START (23)
#define SOC_MODEM_CRG_SRSTEN0_mdm_uart1_srst_en_END (23)
#define SOC_MODEM_CRG_SRSTEN0_mdm_uart_srst_en_START (24)
#define SOC_MODEM_CRG_SRSTEN0_mdm_uart_srst_en_END (24)
#define SOC_MODEM_CRG_SRSTEN0_mdm_edmac_srst_en_START (25)
#define SOC_MODEM_CRG_SRSTEN0_mdm_edmac_srst_en_END (25)
#define SOC_MODEM_CRG_SRSTEN0_mdm_edmac1_srst_en_START (26)
#define SOC_MODEM_CRG_SRSTEN0_mdm_edmac1_srst_en_END (26)
#define SOC_MODEM_CRG_SRSTEN0_cicom0_srst_en_START (27)
#define SOC_MODEM_CRG_SRSTEN0_cicom0_srst_en_END (27)
#define SOC_MODEM_CRG_SRSTEN0_cicom1_srst_en_START (28)
#define SOC_MODEM_CRG_SRSTEN0_cicom1_srst_en_END (28)
#define SOC_MODEM_CRG_SRSTEN0_mdm_amon_srst_en_START (29)
#define SOC_MODEM_CRG_SRSTEN0_mdm_amon_srst_en_END (29)
#define SOC_MODEM_CRG_SRSTEN0_cipher_srst_en_START (30)
#define SOC_MODEM_CRG_SRSTEN0_cipher_srst_en_END (30)
#define SOC_MODEM_CRG_SRSTEN0_hpm_srst_en_START (31)
#define SOC_MODEM_CRG_SRSTEN0_hpm_srst_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int rtc_srst_dis : 1;
        unsigned int dfc_srst_dis : 1;
        unsigned int ccpu_noc_srst_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int drx2soc_timer_srst_dis : 1;
        unsigned int ccpu_cpu_srst_dis : 1;
        unsigned int ccpu_dbg_srst_dis : 1;
        unsigned int ccpu_peri_srst_dis : 1;
        unsigned int ccpu_scu_srst_dis : 1;
        unsigned int ccpu_ptm_srst_dis : 1;
        unsigned int ccpu_wd_srst_dis : 1;
        unsigned int ccpu_l2c_srst_dis : 1;
        unsigned int ccpu_core1_srst_dis : 1;
        unsigned int power_mon0_srst_dis : 1;
        unsigned int ccpu_pd_srst_dis : 1;
        unsigned int power_mon1_srst_dis : 1;
        unsigned int power_mon2_srst_dis : 1;
        unsigned int power_mon3_srst_dis : 1;
        unsigned int hdlc_srst_dis : 1;
        unsigned int upacc_srst_dis : 1;
        unsigned int rsr_acc_srst_dis : 1;
        unsigned int mdm_amon_srst_async_dis : 1;
        unsigned int mdm_uart1_srst_dis : 1;
        unsigned int uart_srst_dis : 1;
        unsigned int mdm_edmac_srst_dis : 1;
        unsigned int mdm_edmac1_srst_dis : 1;
        unsigned int cicom0_srst_dis : 1;
        unsigned int cicom1_srst_dis : 1;
        unsigned int amon_srst_dis : 1;
        unsigned int cipher_srst_dis : 1;
        unsigned int hpm_srst_dis : 1;
    } reg;
} SOC_MODEM_CRG_SRSTDIS0_UNION;
#endif
#define SOC_MODEM_CRG_SRSTDIS0_rtc_srst_dis_START (1)
#define SOC_MODEM_CRG_SRSTDIS0_rtc_srst_dis_END (1)
#define SOC_MODEM_CRG_SRSTDIS0_dfc_srst_dis_START (2)
#define SOC_MODEM_CRG_SRSTDIS0_dfc_srst_dis_END (2)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_noc_srst_dis_START (3)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_noc_srst_dis_END (3)
#define SOC_MODEM_CRG_SRSTDIS0_drx2soc_timer_srst_dis_START (5)
#define SOC_MODEM_CRG_SRSTDIS0_drx2soc_timer_srst_dis_END (5)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_cpu_srst_dis_START (6)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_cpu_srst_dis_END (6)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_dbg_srst_dis_START (7)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_dbg_srst_dis_END (7)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_peri_srst_dis_START (8)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_peri_srst_dis_END (8)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_scu_srst_dis_START (9)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_scu_srst_dis_END (9)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_ptm_srst_dis_START (10)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_ptm_srst_dis_END (10)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_wd_srst_dis_START (11)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_wd_srst_dis_END (11)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_l2c_srst_dis_START (12)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_l2c_srst_dis_END (12)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_core1_srst_dis_START (13)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_core1_srst_dis_END (13)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon0_srst_dis_START (14)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon0_srst_dis_END (14)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_pd_srst_dis_START (15)
#define SOC_MODEM_CRG_SRSTDIS0_ccpu_pd_srst_dis_END (15)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon1_srst_dis_START (16)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon1_srst_dis_END (16)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon2_srst_dis_START (17)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon2_srst_dis_END (17)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon3_srst_dis_START (18)
#define SOC_MODEM_CRG_SRSTDIS0_power_mon3_srst_dis_END (18)
#define SOC_MODEM_CRG_SRSTDIS0_hdlc_srst_dis_START (19)
#define SOC_MODEM_CRG_SRSTDIS0_hdlc_srst_dis_END (19)
#define SOC_MODEM_CRG_SRSTDIS0_upacc_srst_dis_START (20)
#define SOC_MODEM_CRG_SRSTDIS0_upacc_srst_dis_END (20)
#define SOC_MODEM_CRG_SRSTDIS0_rsr_acc_srst_dis_START (21)
#define SOC_MODEM_CRG_SRSTDIS0_rsr_acc_srst_dis_END (21)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_amon_srst_async_dis_START (22)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_amon_srst_async_dis_END (22)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_uart1_srst_dis_START (23)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_uart1_srst_dis_END (23)
#define SOC_MODEM_CRG_SRSTDIS0_uart_srst_dis_START (24)
#define SOC_MODEM_CRG_SRSTDIS0_uart_srst_dis_END (24)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_edmac_srst_dis_START (25)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_edmac_srst_dis_END (25)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_edmac1_srst_dis_START (26)
#define SOC_MODEM_CRG_SRSTDIS0_mdm_edmac1_srst_dis_END (26)
#define SOC_MODEM_CRG_SRSTDIS0_cicom0_srst_dis_START (27)
#define SOC_MODEM_CRG_SRSTDIS0_cicom0_srst_dis_END (27)
#define SOC_MODEM_CRG_SRSTDIS0_cicom1_srst_dis_START (28)
#define SOC_MODEM_CRG_SRSTDIS0_cicom1_srst_dis_END (28)
#define SOC_MODEM_CRG_SRSTDIS0_amon_srst_dis_START (29)
#define SOC_MODEM_CRG_SRSTDIS0_amon_srst_dis_END (29)
#define SOC_MODEM_CRG_SRSTDIS0_cipher_srst_dis_START (30)
#define SOC_MODEM_CRG_SRSTDIS0_cipher_srst_dis_END (30)
#define SOC_MODEM_CRG_SRSTDIS0_hpm_srst_dis_START (31)
#define SOC_MODEM_CRG_SRSTDIS0_hpm_srst_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int rtc_srst_status : 1;
        unsigned int dfc_srst_status : 1;
        unsigned int ccpu_noc_srst_status : 1;
        unsigned int reserved_1 : 1;
        unsigned int drx2soc_timer_srst_status : 1;
        unsigned int ccpu_cpu_srst_status : 1;
        unsigned int ccpu_dbg_srst_status : 1;
        unsigned int ccpu_peri_srst_status : 1;
        unsigned int ccpu_scu_srst_status : 1;
        unsigned int ccpu_ptm_srst_status : 1;
        unsigned int ccpu_wd_srst_status : 1;
        unsigned int ccpu_l2c_srst_status : 1;
        unsigned int ccpu_core1_srst_status : 1;
        unsigned int power_mon0_srst_status : 1;
        unsigned int ccpu_pd_srst_status : 1;
        unsigned int power_mon1_srst_status : 1;
        unsigned int power_mon2_srst_status : 1;
        unsigned int power_mon3_srst_status : 1;
        unsigned int hdlc_srst_status : 1;
        unsigned int upacc_srst_status : 1;
        unsigned int rsr_acc_srst_status : 1;
        unsigned int mdm_amon_srst_async_status : 1;
        unsigned int uart1_srst_status : 1;
        unsigned int uart_srst_status : 1;
        unsigned int mdm_edmac_srst_status : 1;
        unsigned int mdm_edmac1_srst_status : 1;
        unsigned int cicom0_srst_status : 1;
        unsigned int cicom1_srst_status : 1;
        unsigned int amon_srst_status : 1;
        unsigned int cipher_srst_status : 1;
        unsigned int hpm_srst_status : 1;
    } reg;
} SOC_MODEM_CRG_SRSTSTAT0_UNION;
#endif
#define SOC_MODEM_CRG_SRSTSTAT0_rtc_srst_status_START (1)
#define SOC_MODEM_CRG_SRSTSTAT0_rtc_srst_status_END (1)
#define SOC_MODEM_CRG_SRSTSTAT0_dfc_srst_status_START (2)
#define SOC_MODEM_CRG_SRSTSTAT0_dfc_srst_status_END (2)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_noc_srst_status_START (3)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_noc_srst_status_END (3)
#define SOC_MODEM_CRG_SRSTSTAT0_drx2soc_timer_srst_status_START (5)
#define SOC_MODEM_CRG_SRSTSTAT0_drx2soc_timer_srst_status_END (5)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_cpu_srst_status_START (6)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_cpu_srst_status_END (6)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_dbg_srst_status_START (7)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_dbg_srst_status_END (7)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_peri_srst_status_START (8)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_peri_srst_status_END (8)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_scu_srst_status_START (9)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_scu_srst_status_END (9)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_ptm_srst_status_START (10)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_ptm_srst_status_END (10)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_wd_srst_status_START (11)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_wd_srst_status_END (11)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_l2c_srst_status_START (12)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_l2c_srst_status_END (12)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_core1_srst_status_START (13)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_core1_srst_status_END (13)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon0_srst_status_START (14)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon0_srst_status_END (14)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_pd_srst_status_START (15)
#define SOC_MODEM_CRG_SRSTSTAT0_ccpu_pd_srst_status_END (15)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon1_srst_status_START (16)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon1_srst_status_END (16)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon2_srst_status_START (17)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon2_srst_status_END (17)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon3_srst_status_START (18)
#define SOC_MODEM_CRG_SRSTSTAT0_power_mon3_srst_status_END (18)
#define SOC_MODEM_CRG_SRSTSTAT0_hdlc_srst_status_START (19)
#define SOC_MODEM_CRG_SRSTSTAT0_hdlc_srst_status_END (19)
#define SOC_MODEM_CRG_SRSTSTAT0_upacc_srst_status_START (20)
#define SOC_MODEM_CRG_SRSTSTAT0_upacc_srst_status_END (20)
#define SOC_MODEM_CRG_SRSTSTAT0_rsr_acc_srst_status_START (21)
#define SOC_MODEM_CRG_SRSTSTAT0_rsr_acc_srst_status_END (21)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_amon_srst_async_status_START (22)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_amon_srst_async_status_END (22)
#define SOC_MODEM_CRG_SRSTSTAT0_uart1_srst_status_START (23)
#define SOC_MODEM_CRG_SRSTSTAT0_uart1_srst_status_END (23)
#define SOC_MODEM_CRG_SRSTSTAT0_uart_srst_status_START (24)
#define SOC_MODEM_CRG_SRSTSTAT0_uart_srst_status_END (24)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_edmac_srst_status_START (25)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_edmac_srst_status_END (25)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_edmac1_srst_status_START (26)
#define SOC_MODEM_CRG_SRSTSTAT0_mdm_edmac1_srst_status_END (26)
#define SOC_MODEM_CRG_SRSTSTAT0_cicom0_srst_status_START (27)
#define SOC_MODEM_CRG_SRSTSTAT0_cicom0_srst_status_END (27)
#define SOC_MODEM_CRG_SRSTSTAT0_cicom1_srst_status_START (28)
#define SOC_MODEM_CRG_SRSTSTAT0_cicom1_srst_status_END (28)
#define SOC_MODEM_CRG_SRSTSTAT0_amon_srst_status_START (29)
#define SOC_MODEM_CRG_SRSTSTAT0_amon_srst_status_END (29)
#define SOC_MODEM_CRG_SRSTSTAT0_cipher_srst_status_START (30)
#define SOC_MODEM_CRG_SRSTSTAT0_cipher_srst_status_END (30)
#define SOC_MODEM_CRG_SRSTSTAT0_hpm_srst_status_START (31)
#define SOC_MODEM_CRG_SRSTSTAT0_hpm_srst_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_srst_en : 10;
        unsigned int dsp0_pd_srst_en : 1;
        unsigned int dsp0_core_srst_en : 1;
        unsigned int dsp0_dbg_srst_en : 1;
        unsigned int ccpu_wd1_srst_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dsp0_noc_srst_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int bbp_noc_srst_en : 1;
        unsigned int ccpu_dbg0_srst_en : 1;
        unsigned int ccpu_dbg1_srst_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_etm0_srst_en : 1;
        unsigned int ccpu_etm1_srst_en : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ccpu_ct_srst_en : 1;
        unsigned int reserved_8 : 1;
        unsigned int bbc_srst_en : 1;
        unsigned int abb_srst_en : 1;
    } reg;
} SOC_MODEM_CRG_SRSTEN1_UNION;
#endif
#define SOC_MODEM_CRG_SRSTEN1_mdm_timer_srst_en_START (0)
#define SOC_MODEM_CRG_SRSTEN1_mdm_timer_srst_en_END (9)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_pd_srst_en_START (10)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_pd_srst_en_END (10)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_core_srst_en_START (11)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_core_srst_en_END (11)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_dbg_srst_en_START (12)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_dbg_srst_en_END (12)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_wd1_srst_en_START (13)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_wd1_srst_en_END (13)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_noc_srst_en_START (17)
#define SOC_MODEM_CRG_SRSTEN1_dsp0_noc_srst_en_END (17)
#define SOC_MODEM_CRG_SRSTEN1_bbp_noc_srst_en_START (19)
#define SOC_MODEM_CRG_SRSTEN1_bbp_noc_srst_en_END (19)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_dbg0_srst_en_START (20)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_dbg0_srst_en_END (20)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_dbg1_srst_en_START (21)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_dbg1_srst_en_END (21)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_etm0_srst_en_START (24)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_etm0_srst_en_END (24)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_etm1_srst_en_START (25)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_etm1_srst_en_END (25)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_ct_srst_en_START (28)
#define SOC_MODEM_CRG_SRSTEN1_ccpu_ct_srst_en_END (28)
#define SOC_MODEM_CRG_SRSTEN1_bbc_srst_en_START (30)
#define SOC_MODEM_CRG_SRSTEN1_bbc_srst_en_END (30)
#define SOC_MODEM_CRG_SRSTEN1_abb_srst_en_START (31)
#define SOC_MODEM_CRG_SRSTEN1_abb_srst_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_srst_dis : 10;
        unsigned int dsp0_pd_srst_dis : 1;
        unsigned int dsp0_core_srst_dis : 1;
        unsigned int dsp0_dbg_srst_dis : 1;
        unsigned int ccpu_wd1_srst_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dsp0_noc_srst_dis : 1;
        unsigned int reserved_3 : 1;
        unsigned int bbp_boc_srst_dis : 1;
        unsigned int ccpu_dbg0_srst_dis : 1;
        unsigned int ccpu_dbg1_srst_dis : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_etm0_srst_dis : 1;
        unsigned int ccpu_etm1_srst_dis : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ccpu_ct_srst_dis : 1;
        unsigned int reserved_8 : 1;
        unsigned int bbc_srst_dis : 1;
        unsigned int abb_srst_dis : 1;
    } reg;
} SOC_MODEM_CRG_SRSTDIS1_UNION;
#endif
#define SOC_MODEM_CRG_SRSTDIS1_mdm_timer_srst_dis_START (0)
#define SOC_MODEM_CRG_SRSTDIS1_mdm_timer_srst_dis_END (9)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_pd_srst_dis_START (10)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_pd_srst_dis_END (10)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_core_srst_dis_START (11)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_core_srst_dis_END (11)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_dbg_srst_dis_START (12)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_dbg_srst_dis_END (12)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_wd1_srst_dis_START (13)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_wd1_srst_dis_END (13)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_noc_srst_dis_START (17)
#define SOC_MODEM_CRG_SRSTDIS1_dsp0_noc_srst_dis_END (17)
#define SOC_MODEM_CRG_SRSTDIS1_bbp_boc_srst_dis_START (19)
#define SOC_MODEM_CRG_SRSTDIS1_bbp_boc_srst_dis_END (19)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_dbg0_srst_dis_START (20)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_dbg0_srst_dis_END (20)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_dbg1_srst_dis_START (21)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_dbg1_srst_dis_END (21)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_etm0_srst_dis_START (24)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_etm0_srst_dis_END (24)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_etm1_srst_dis_START (25)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_etm1_srst_dis_END (25)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_ct_srst_dis_START (28)
#define SOC_MODEM_CRG_SRSTDIS1_ccpu_ct_srst_dis_END (28)
#define SOC_MODEM_CRG_SRSTDIS1_bbc_srst_dis_START (30)
#define SOC_MODEM_CRG_SRSTDIS1_bbc_srst_dis_END (30)
#define SOC_MODEM_CRG_SRSTDIS1_abb_srst_dis_START (31)
#define SOC_MODEM_CRG_SRSTDIS1_abb_srst_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdm_timer_srst_status : 10;
        unsigned int dsp0_pd_srst_status : 1;
        unsigned int dsp0_core_srst_status : 1;
        unsigned int dsp0_dbg_srst_status : 1;
        unsigned int ccpu_wd1_srst_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dsp0_noc_srst_status : 1;
        unsigned int reserved_3 : 1;
        unsigned int bbp_boc_srst_status : 1;
        unsigned int ccpu_dbg0_srst_status : 1;
        unsigned int ccpu_dbg1_srst_status : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_etm0_srst_status : 1;
        unsigned int ccpu_etm1_srst_status : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ccpu_ct_srst_status : 1;
        unsigned int reserved_8 : 1;
        unsigned int bbc_srst_status : 1;
        unsigned int abb_srst_status : 1;
    } reg;
} SOC_MODEM_CRG_SRSTSTAT1_UNION;
#endif
#define SOC_MODEM_CRG_SRSTSTAT1_mdm_timer_srst_status_START (0)
#define SOC_MODEM_CRG_SRSTSTAT1_mdm_timer_srst_status_END (9)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_pd_srst_status_START (10)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_pd_srst_status_END (10)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_core_srst_status_START (11)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_core_srst_status_END (11)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_dbg_srst_status_START (12)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_dbg_srst_status_END (12)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_wd1_srst_status_START (13)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_wd1_srst_status_END (13)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_noc_srst_status_START (17)
#define SOC_MODEM_CRG_SRSTSTAT1_dsp0_noc_srst_status_END (17)
#define SOC_MODEM_CRG_SRSTSTAT1_bbp_boc_srst_status_START (19)
#define SOC_MODEM_CRG_SRSTSTAT1_bbp_boc_srst_status_END (19)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_dbg0_srst_status_START (20)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_dbg0_srst_status_END (20)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_dbg1_srst_status_START (21)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_dbg1_srst_status_END (21)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_etm0_srst_status_START (24)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_etm0_srst_status_END (24)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_etm1_srst_status_START (25)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_etm1_srst_status_END (25)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_ct_srst_status_START (28)
#define SOC_MODEM_CRG_SRSTSTAT1_ccpu_ct_srst_status_END (28)
#define SOC_MODEM_CRG_SRSTSTAT1_bbc_srst_status_START (30)
#define SOC_MODEM_CRG_SRSTSTAT1_bbc_srst_status_END (30)
#define SOC_MODEM_CRG_SRSTSTAT1_abb_srst_status_START (31)
#define SOC_MODEM_CRG_SRSTSTAT1_abb_srst_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_div_num : 4;
        unsigned int ccpu_m0_freqmode : 1;
        unsigned int reserved_0 : 3;
        unsigned int ccpu_m1_freqmode : 1;
        unsigned int reserved_1 : 3;
        unsigned int ccpu_m2_freqmode : 1;
        unsigned int reserved_2 : 3;
        unsigned int lp_ccpu_div_num : 5;
        unsigned int reserved_3 : 3;
        unsigned int ccpu_wfi_en : 1;
        unsigned int reserved_4 : 3;
        unsigned int ccpu_clksw_req : 2;
        unsigned int reserved_5 : 2;
    } reg;
} SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_UNION;
#endif
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_div_num_START (0)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_div_num_END (3)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m0_freqmode_START (4)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m0_freqmode_END (4)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m1_freqmode_START (8)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m1_freqmode_END (8)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m2_freqmode_START (12)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_m2_freqmode_END (12)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_lp_ccpu_div_num_START (16)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_lp_ccpu_div_num_END (20)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_wfi_en_START (24)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_wfi_en_END (24)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_clksw_req_START (28)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV0_ccpu_clksw_req_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slowbus_clksw_req : 2;
        unsigned int reserved_0 : 1;
        unsigned int slowbus_apb_freqmode : 1;
        unsigned int slowbus_div_num : 4;
        unsigned int slowbus_lp_div_num : 5;
        unsigned int reserved_1 : 2;
        unsigned int slowbus_dfs_en : 1;
        unsigned int fastbus_clksw_req : 2;
        unsigned int reserved_2 : 2;
        unsigned int fastbus_div_num : 4;
        unsigned int fastbus_lp_div_num : 5;
        unsigned int reserved_3 : 2;
        unsigned int fastbus_dfs_en : 1;
    } reg;
} SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_UNION;
#endif
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_clksw_req_START (0)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_clksw_req_END (1)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_apb_freqmode_START (3)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_apb_freqmode_END (3)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_div_num_START (4)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_div_num_END (7)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_lp_div_num_START (8)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_lp_div_num_END (12)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_dfs_en_START (15)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_slowbus_dfs_en_END (15)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_clksw_req_START (16)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_clksw_req_END (17)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_div_num_START (20)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_div_num_END (23)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_lp_div_num_START (24)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_lp_div_num_END (28)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_dfs_en_START (31)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV1_fastbus_dfs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int dsp0_clk_div_num : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 1;
        unsigned int cdsp_dfs_en : 1;
        unsigned int dsp0_dfs_en : 1;
        unsigned int dsp0_freqmode : 1;
        unsigned int lp_dsp0_clk_div_num : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
    } reg;
} SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_UNION;
#endif
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_clk_div_num_START (8)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_clk_div_num_END (11)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_cdsp_dfs_en_START (17)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_cdsp_dfs_en_END (17)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_dfs_en_START (18)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_dfs_en_END (18)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_freqmode_START (19)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_dsp0_freqmode_END (19)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_lp_dsp0_clk_div_num_START (20)
#define SOC_MODEM_CRG_MDM_PERI_CLK_DIV2_lp_dsp0_clk_div_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_idle_wait_cnt : 16;
        unsigned int glb_idle_wait_cnt : 16;
    } reg;
} SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_UNION;
#endif
#define SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_ccpu_idle_wait_cnt_START (0)
#define SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_ccpu_idle_wait_cnt_END (15)
#define SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_glb_idle_wait_cnt_START (16)
#define SOC_MODEM_CRG_MDM_PERI_DFS_CTRL_glb_idle_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int abb_scpll0_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_MODEM_CRG_MDM_ABB_SCPLL0_EN_UNION;
#endif
#define SOC_MODEM_CRG_MDM_ABB_SCPLL0_EN_abb_scpll0_en_START (0)
#define SOC_MODEM_CRG_MDM_ABB_SCPLL0_EN_abb_scpll0_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp0_clksw_req : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MODEM_CRG_DSP0_CLK_SEL_UNION;
#endif
#define SOC_MODEM_CRG_DSP0_CLK_SEL_dsp0_clksw_req_START (0)
#define SOC_MODEM_CRG_DSP0_CLK_SEL_dsp0_clksw_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 30;
    } reg;
} SOC_MODEM_CRG_CDSP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 20;
        unsigned int sc_ccpu_wdt0_rst_en : 1;
        unsigned int sc_ccpu_wdt1_rst_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 5;
    } reg;
} SOC_MODEM_CRG_A9WDT_RSTEN_UNION;
#endif
#define SOC_MODEM_CRG_A9WDT_RSTEN_sc_ccpu_wdt0_rst_en_START (20)
#define SOC_MODEM_CRG_A9WDT_RSTEN_sc_ccpu_wdt0_rst_en_END (20)
#define SOC_MODEM_CRG_A9WDT_RSTEN_sc_ccpu_wdt1_rst_en_START (21)
#define SOC_MODEM_CRG_A9WDT_RSTEN_sc_ccpu_wdt1_rst_en_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int dsp0_idle_wait_cnt : 16;
    } reg;
} SOC_MODEM_CRG_DSP_DFS_CTRL_UNION;
#endif
#define SOC_MODEM_CRG_DSP_DFS_CTRL_dsp0_idle_wait_cnt_START (16)
#define SOC_MODEM_CRG_DSP_DFS_CTRL_dsp0_idle_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MODEM_CRG_CDSP_DFS_CTRL_UNION;
#endif
#define SOC_MODEM_CRG_CDSP_DFS_CTRL_rsv_START (0)
#define SOC_MODEM_CRG_CDSP_DFS_CTRL_rsv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp0_clk_sel_stat : 3;
        unsigned int ccpu_clk_sel_stat : 3;
        unsigned int fast_clk_sel_stat : 3;
        unsigned int slow_clk_sel_stat : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_MODEM_CRG_CLKSW_STAT_UNION;
#endif
#define SOC_MODEM_CRG_CLKSW_STAT_dsp0_clk_sel_stat_START (0)
#define SOC_MODEM_CRG_CLKSW_STAT_dsp0_clk_sel_stat_END (2)
#define SOC_MODEM_CRG_CLKSW_STAT_ccpu_clk_sel_stat_START (3)
#define SOC_MODEM_CRG_CLKSW_STAT_ccpu_clk_sel_stat_END (5)
#define SOC_MODEM_CRG_CLKSW_STAT_fast_clk_sel_stat_START (6)
#define SOC_MODEM_CRG_CLKSW_STAT_fast_clk_sel_stat_END (8)
#define SOC_MODEM_CRG_CLKSW_STAT_slow_clk_sel_stat_START (9)
#define SOC_MODEM_CRG_CLKSW_STAT_slow_clk_sel_stat_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_pd_clk_en : 1;
        unsigned int ccpu_core0_clk_en : 1;
        unsigned int ccpu_core1_clk_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ccpu_core0_etm_clk_en : 1;
        unsigned int ccpu_core1_etm_clk_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ccpu_core0_dbg_clk_en : 1;
        unsigned int ccpu_core1_dbg_clk_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_core_ct_clk_en : 1;
        unsigned int reserved_6 : 14;
        unsigned int power_monitor_clk_en : 4;
    } reg;
} SOC_MODEM_CRG_CLKEN2_UNION;
#endif
#define SOC_MODEM_CRG_CLKEN2_ccpu_pd_clk_en_START (0)
#define SOC_MODEM_CRG_CLKEN2_ccpu_pd_clk_en_END (0)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_clk_en_START (1)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_clk_en_END (1)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_clk_en_START (2)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_clk_en_END (2)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_etm_clk_en_START (5)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_etm_clk_en_END (5)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_etm_clk_en_START (6)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_etm_clk_en_END (6)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_dbg_clk_en_START (9)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core0_dbg_clk_en_END (9)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_dbg_clk_en_START (10)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core1_dbg_clk_en_END (10)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core_ct_clk_en_START (13)
#define SOC_MODEM_CRG_CLKEN2_ccpu_core_ct_clk_en_END (13)
#define SOC_MODEM_CRG_CLKEN2_power_monitor_clk_en_START (28)
#define SOC_MODEM_CRG_CLKEN2_power_monitor_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_pd_clk_dis : 1;
        unsigned int ccpu_core0_clk_dis : 1;
        unsigned int ccpu_core1_clk_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ccpu_core0_etm_clk_dis : 1;
        unsigned int ccpu_core1_etm_clk_dis : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ccpu_core0_dbg_clk_dis : 1;
        unsigned int ccpu_core1_dbg_clk_dis : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_core_ct_clk_dis : 1;
        unsigned int reserved_6 : 14;
        unsigned int power_monitor_clk_dis : 4;
    } reg;
} SOC_MODEM_CRG_CLKDIS2_UNION;
#endif
#define SOC_MODEM_CRG_CLKDIS2_ccpu_pd_clk_dis_START (0)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_pd_clk_dis_END (0)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_clk_dis_START (1)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_clk_dis_END (1)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_clk_dis_START (2)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_clk_dis_END (2)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_etm_clk_dis_START (5)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_etm_clk_dis_END (5)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_etm_clk_dis_START (6)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_etm_clk_dis_END (6)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_dbg_clk_dis_START (9)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core0_dbg_clk_dis_END (9)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_dbg_clk_dis_START (10)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core1_dbg_clk_dis_END (10)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core_ct_clk_dis_START (13)
#define SOC_MODEM_CRG_CLKDIS2_ccpu_core_ct_clk_dis_END (13)
#define SOC_MODEM_CRG_CLKDIS2_power_monitor_clk_dis_START (28)
#define SOC_MODEM_CRG_CLKDIS2_power_monitor_clk_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_pd_clkcg_status : 1;
        unsigned int ccpu_core0_clkcg_status : 1;
        unsigned int ccpu_core1_clkcg_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ccpu_core0_etm_clkcg_status : 1;
        unsigned int ccpu_core1_etm_clkcg_status : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ccpu_core0_dbg_clkcg_status : 1;
        unsigned int ccpu_core1_dbg_clkcg_status : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_core_ct_clkcg_status : 1;
        unsigned int reserved_6 : 14;
        unsigned int power_monitor_clk_status : 4;
    } reg;
} SOC_MODEM_CRG_CLKSTAT2_UNION;
#endif
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_pd_clkcg_status_START (0)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_pd_clkcg_status_END (0)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_clkcg_status_START (1)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_clkcg_status_END (1)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_clkcg_status_START (2)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_clkcg_status_END (2)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_etm_clkcg_status_START (5)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_etm_clkcg_status_END (5)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_etm_clkcg_status_START (6)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_etm_clkcg_status_END (6)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_dbg_clkcg_status_START (9)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core0_dbg_clkcg_status_END (9)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_dbg_clkcg_status_START (10)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core1_dbg_clkcg_status_END (10)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core_ct_clkcg_status_START (13)
#define SOC_MODEM_CRG_CLKSTAT2_ccpu_core_ct_clkcg_status_END (13)
#define SOC_MODEM_CRG_CLKSTAT2_power_monitor_clk_status_START (28)
#define SOC_MODEM_CRG_CLKSTAT2_power_monitor_clk_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccpu_pd_clk_stat : 1;
        unsigned int ccpu_core0_clk_stat : 1;
        unsigned int ccpu_core1_clk_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ccpu_core0_etm_clk_stat : 1;
        unsigned int ccpu_core1_etm_clk_stat : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ccpu_core0_dbg_clk_stat : 1;
        unsigned int ccpu_core1_dbg_clk_stat : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ccpu_core_ct_clk_stat : 1;
        unsigned int reserved_6 : 14;
        unsigned int power_monitor_clkcg_status : 4;
    } reg;
} SOC_MODEM_CRG_CLKCG_STAT2_UNION;
#endif
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_pd_clk_stat_START (0)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_pd_clk_stat_END (0)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_clk_stat_START (1)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_clk_stat_END (1)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_clk_stat_START (2)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_clk_stat_END (2)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_etm_clk_stat_START (5)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_etm_clk_stat_END (5)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_etm_clk_stat_START (6)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_etm_clk_stat_END (6)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_dbg_clk_stat_START (9)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core0_dbg_clk_stat_END (9)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_dbg_clk_stat_START (10)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core1_dbg_clk_stat_END (10)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core_ct_clk_stat_START (13)
#define SOC_MODEM_CRG_CLKCG_STAT2_ccpu_core_ct_clk_stat_END (13)
#define SOC_MODEM_CRG_CLKCG_STAT2_power_monitor_clkcg_status_START (28)
#define SOC_MODEM_CRG_CLKCG_STAT2_power_monitor_clkcg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_en : 1;
        unsigned int pll_bp : 1;
        unsigned int pll_refdiv : 6;
        unsigned int pll_intprog : 12;
        unsigned int pll_postdiv1 : 3;
        unsigned int pll_postdiv2 : 3;
        unsigned int pll_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_A9PLL_CFG0_UNION;
#endif
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_en_START (0)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_en_END (0)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_bp_START (1)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_bp_END (1)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_refdiv_START (2)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_refdiv_END (7)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_intprog_START (8)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_intprog_END (19)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_postdiv1_START (20)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_postdiv1_END (22)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_postdiv2_START (23)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_postdiv2_END (25)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_lock_START (26)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG0_pll_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_fracdiv : 24;
        unsigned int pll_int_mod : 1;
        unsigned int pll_cfg_vld : 1;
        unsigned int pll_clk_enable : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_A9PLL_CFG1_UNION;
#endif
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_fracdiv_START (0)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_fracdiv_END (23)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_int_mod_START (24)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_int_mod_END (24)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_cfg_vld_START (25)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_cfg_vld_END (25)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_clk_enable_START (26)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG1_pll_clk_enable_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_ssc_reset : 1;
        unsigned int pll_ssc_disable : 1;
        unsigned int pll_ssc_downspread : 1;
        unsigned int pll_ssc_spread : 3;
        unsigned int pll_ssc_divval : 4;
        unsigned int reserved : 22;
    } reg;
} SOC_MODEM_CRG_CRG_A9PLL_CFG2_UNION;
#endif
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_reset_START (0)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_reset_END (0)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_disable_START (1)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_disable_END (1)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_downspread_START (2)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_downspread_END (2)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_spread_START (3)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_spread_END (5)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_divval_START (6)
#define SOC_MODEM_CRG_CRG_A9PLL_CFG2_pll_ssc_divval_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_en : 1;
        unsigned int pll_bp : 1;
        unsigned int pll_refdiv : 6;
        unsigned int pll_intprog : 12;
        unsigned int pll_postdiv1 : 3;
        unsigned int pll_postdiv2 : 3;
        unsigned int pll_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_DSPPLL_CFG0_UNION;
#endif
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_en_START (0)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_en_END (0)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_bp_START (1)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_bp_END (1)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_refdiv_START (2)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_refdiv_END (7)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_intprog_START (8)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_intprog_END (19)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_postdiv1_START (20)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_postdiv1_END (22)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_postdiv2_START (23)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_postdiv2_END (25)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_lock_START (26)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG0_pll_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_fracdiv : 24;
        unsigned int pll_int_mod : 1;
        unsigned int pll_cfg_vld : 1;
        unsigned int pll_clk_gt : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_DSPPLL_CFG1_UNION;
#endif
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_fracdiv_START (0)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_fracdiv_END (23)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_int_mod_START (24)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_int_mod_END (24)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_cfg_vld_START (25)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_cfg_vld_END (25)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_clk_gt_START (26)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG1_pll_clk_gt_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_ssc_reset : 1;
        unsigned int pll_ssc_disable : 1;
        unsigned int pll_ssc_downspread : 1;
        unsigned int pll_ssc_spread : 3;
        unsigned int pll_ssc_divval : 4;
        unsigned int reserved : 22;
    } reg;
} SOC_MODEM_CRG_CRG_DSPPLL_CFG2_UNION;
#endif
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_reset_START (0)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_reset_END (0)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_disable_START (1)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_disable_END (1)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_downspread_START (2)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_downspread_END (2)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_spread_START (3)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_spread_END (5)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_divval_START (6)
#define SOC_MODEM_CRG_CRG_DSPPLL_CFG2_pll_ssc_divval_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scpll0_lock : 1;
        unsigned int scpll1_lock : 1;
        unsigned int scpll2_lock : 1;
        unsigned int scpll3_lock : 1;
        unsigned int scpll4_lock : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MODEM_CRG_CRG_SCPLL_STATE_UNION;
#endif
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll0_lock_START (0)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll0_lock_END (0)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll1_lock_START (1)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll1_lock_END (1)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll2_lock_START (2)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll2_lock_END (2)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll3_lock_START (3)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll3_lock_END (3)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll4_lock_START (4)
#define SOC_MODEM_CRG_CRG_SCPLL_STATE_scpll4_lock_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_en : 1;
        unsigned int pll_bp : 1;
        unsigned int pll_refdiv : 6;
        unsigned int pll_intprog : 12;
        unsigned int pll_postdiv1 : 3;
        unsigned int pll_postdiv2 : 3;
        unsigned int pll_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_BBPPLL_CFG0_UNION;
#endif
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_en_START (0)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_en_END (0)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_bp_START (1)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_bp_END (1)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_refdiv_START (2)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_refdiv_END (7)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_intprog_START (8)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_intprog_END (19)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_postdiv1_START (20)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_postdiv1_END (22)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_postdiv2_START (23)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_postdiv2_END (25)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_lock_START (26)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG0_pll_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_fracdiv : 24;
        unsigned int pll_int_mod : 1;
        unsigned int pll_cfg_vld : 1;
        unsigned int pll_clk_enable : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_MODEM_CRG_CRG_BBPPLL_CFG1_UNION;
#endif
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_fracdiv_START (0)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_fracdiv_END (23)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_int_mod_START (24)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_int_mod_END (24)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_cfg_vld_START (25)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_cfg_vld_END (25)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_clk_enable_START (26)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG1_pll_clk_enable_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_ssc_reset : 1;
        unsigned int pll_ssc_disable : 1;
        unsigned int pll_ssc_downspread : 1;
        unsigned int pll_ssc_spread : 3;
        unsigned int pll_ssc_divval : 4;
        unsigned int reserved : 22;
    } reg;
} SOC_MODEM_CRG_CRG_BBPPLL_CFG2_UNION;
#endif
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_reset_START (0)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_reset_END (0)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_disable_START (1)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_disable_END (1)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_downspread_START (2)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_downspread_END (2)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_spread_START (3)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_spread_END (5)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_divval_START (6)
#define SOC_MODEM_CRG_CRG_BBPPLL_CFG2_pll_ssc_divval_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
