#ifndef __SOC_MMC0_HIUSB2RV100_INTERFACE_H__
#define __SOC_MMC0_HIUSB2RV100_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_ADDR(base) ((base) + (0x0004UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_ADDR(base) ((base) + (0x0008UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_ADDR(base) ((base) + (0x000CUL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_ADDR(base) ((base) + (0x0010UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_ADDR(base) ((base) + (0x0014UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_ADDR(base) ((base) + (0x0018UL))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_ADDR(base) ((base) + (0x001CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_ADDR(base) ((base) + (0x0020UL))
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_ADDR(base) ((base) + (0x0024UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_ADDR(base) ((base) + (0x0028UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_ADDR(base) ((base) + (0x002CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_ADDR(base) ((base) + (0x0030UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_ADDR(base) ((base) + (0x0034UL))
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_ADDR(base) ((base) + (0x0038UL))
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_ADDR(base) ((base) + (0x003CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_ADDR(base) ((base) + (0x0040UL))
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_ADDR(base) ((base) + (0x0044UL))
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_ADDR(base) ((base) + (0x0048UL))
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_ADDR(base) ((base) + (0x004CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_ADDR(base) ((base) + (0x0050UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_ADDR(base) ((base) + (0x0054UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP1_CFG_ADDR(base) ((base) + (0x0058UL))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP2_CFG_ADDR(base) ((base) + (0x005CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_ADDR(base) ((base) + (0x0060UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ADDR(base) ((base) + (0x0064UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_ADDR(base) ((base) + (0x0068UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_ADDR(base) ((base) + (0x006CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_ADDR(base) ((base) + (0x0070UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_ADDR(base) ((base) + (0x0074UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_ADDR(base) ((base) + (0x0078UL))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD7_CFG_ADDR(base) ((base) + (0x007CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_ADDR(base) ((base) + (0x0080UL))
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ADDR(base) ((base) + (0x0084UL))
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_ADDR(base) ((base) + (0x0088UL))
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_ADDR(base) ((base) + (0x008CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_ADDR(base) ((base) + (0x0090UL))
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_ADDR(base) ((base) + (0x0094UL))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC0_ADDR(base) ((base) + (0x0098UL))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC1_ADDR(base) ((base) + (0x009CUL))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC2_ADDR(base) ((base) + (0x00A0UL))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC3_ADDR(base) ((base) + (0x00A4UL))
#define SOC_MMC0_HiUSB2RV100_RSV_R_EC0_ADDR(base) ((base) + (0x00A8UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_ADDR(base) ((base) + (0x0100UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST0_ADDR(base) ((base) + (0x0104UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST1_ADDR(base) ((base) + (0x0108UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST2_ADDR(base) ((base) + (0x010CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST3_ADDR(base) ((base) + (0x0110UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST4_ADDR(base) ((base) + (0x0114UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST5_ADDR(base) ((base) + (0x0118UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST6_ADDR(base) ((base) + (0x011CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST7_ADDR(base) ((base) + (0x0120UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST8_ADDR(base) ((base) + (0x0124UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST9_ADDR(base) ((base) + (0x0128UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST10_ADDR(base) ((base) + (0x012CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST11_ADDR(base) ((base) + (0x0130UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST12_ADDR(base) ((base) + (0x0134UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST13_ADDR(base) ((base) + (0x0138UL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST14_ADDR(base) ((base) + (0x013CUL))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST15_ADDR(base) ((base) + (0x0140UL))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_ADDR(base) ((base) + (0x0180UL))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL0_ADDR(base) ((base) + (0x0184UL))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_ADDR(base) ((base) + (0x0188UL))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_ADDR(base) ((base) + (0x018CUL))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_ADDR(base) ((base) + (0x0190UL))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_ADDR(base) ((base) + (0x0194UL))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_ADDR(base) ((base) + (0x0198UL))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL23_ADDR(base) ((base) + (0x019CUL))
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_ADDR(base) ((base) + (0x01A0UL))
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_ADDR(base) ((base) + (0x01A8UL))
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_ADDR(base) ((base) + (0x01B4UL))
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_ADDR(base) ((base) + (0x01BCUL))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG1_ADDR(base) ((base) + (0x01C0UL))
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_ADDR(base) ((base) + (0x01C4UL))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_ADDR(base) ((base) + (0x01C8UL))
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_ADDR(base) ((base) + (0x01CCUL))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG2_ADDR(base) ((base) + (0x01D0UL))
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_ADDR(base) ((base) + (0x01D4UL))
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG1_ADDR(base) ((base) + (0x01D8UL))
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_ADDR(base) ((base) + (0x01DCUL))
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_ADDR(base) ((base) + (0x01E0UL))
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_ADDR(base) ((base) + (0x01E4UL))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG0_ADDR(base) ((base) + (0x01E8UL))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG1_ADDR(base) ((base) + (0x01ECUL))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG2_ADDR(base) ((base) + (0x01F0UL))
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG0_ADDR(base) ((base) + (0x01F4UL))
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG1_ADDR(base) ((base) + (0x01F8UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL0_ADDR(base) ((base) + (0x01FCUL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_ADDR(base) ((base) + (0x0200UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_ADDR(base) ((base) + (0x0204UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_ADDR(base) ((base) + (0x0208UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL4_ADDR(base) ((base) + (0x020CUL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_ADDR(base) ((base) + (0x0210UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_ADDR(base) ((base) + (0x0214UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL7_ADDR(base) ((base) + (0x0218UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL8_ADDR(base) ((base) + (0x021CUL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL9_ADDR(base) ((base) + (0x0220UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL10_ADDR(base) ((base) + (0x0224UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL11_ADDR(base) ((base) + (0x0228UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL12_ADDR(base) ((base) + (0x022CUL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_ADDR(base) ((base) + (0x0230UL))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL14_ADDR(base) ((base) + (0x0234UL))
#define SOC_MMC0_HiUSB2RV100_BIST_DEBUG_ADDR(base) ((base) + (0x0238UL))
#define SOC_MMC0_HiUSB2RV100_DBG_IO_CFG_ADDR(base) ((base) + (0x023CUL))
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD0_ADDR(base) ((base) + (0x0240UL))
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD1_ADDR(base) ((base) + (0x0244UL))
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD0_ADDR(base) ((base) + (0x0248UL))
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD1_ADDR(base) ((base) + (0x024CUL))
#define SOC_MMC0_HiUSB2RV100_DBG_OPMODE_RCD_ADDR(base) ((base) + (0x0250UL))
#define SOC_MMC0_HiUSB2RV100_DBG_XCVRSELECT_RCD_ADDR(base) ((base) + (0x0254UL))
#define SOC_MMC0_HiUSB2RV100_DBG_DISCONNECT_RCD_ADDR(base) ((base) + (0x0258UL))
#define SOC_MMC0_HiUSB2RV100_DBG_TERMSELECT_RCD_ADDR(base) ((base) + (0x025CUL))
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_ADDR(base) ((base) + (0x0260UL))
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_ADDR(base) ((base) + (0x0264UL))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_ADDR(base) ((base) + (0x0268UL))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER1_ADDR(base) ((base) + (0x026CUL))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_ADDR(base) ((base) + (0x0270UL))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_ADDR(base) ((base) + (0x0274UL))
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_ADDR(base) ((base) + (0x0278UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_ADDR(base) ((base) + (0x027CUL))
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_ADDR(base) ((base) + (0x0280UL))
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_ADDR(base) ((base) + (0x0284UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_ADDR(base) ((base) + (0x0288UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_ADDR(base) ((base) + (0x028CUL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_ADDR(base) ((base) + (0x0290UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_ADDR(base) ((base) + (0x0294UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG3_ADDR(base) ((base) + (0x0298UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG4_ADDR(base) ((base) + (0x029CUL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG5_ADDR(base) ((base) + (0x02A0UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG6_ADDR(base) ((base) + (0x02A4UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG7_ADDR(base) ((base) + (0x02A8UL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG8_ADDR(base) ((base) + (0x02ACUL))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG9_ADDR(base) ((base) + (0x02B0UL))
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_ADDR(base) ((base) + (0x02B4UL))
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_ADDR(base) ((base) + (0x02B8UL))
#else
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_ADDR(base) ((base) + (0x0004))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_ADDR(base) ((base) + (0x0008))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_ADDR(base) ((base) + (0x000C))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_ADDR(base) ((base) + (0x0010))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_ADDR(base) ((base) + (0x0014))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_ADDR(base) ((base) + (0x0018))
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_ADDR(base) ((base) + (0x001C))
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_ADDR(base) ((base) + (0x0020))
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_ADDR(base) ((base) + (0x0024))
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_ADDR(base) ((base) + (0x0028))
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_ADDR(base) ((base) + (0x002C))
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_ADDR(base) ((base) + (0x0030))
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_ADDR(base) ((base) + (0x0034))
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_ADDR(base) ((base) + (0x0038))
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_ADDR(base) ((base) + (0x003C))
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_ADDR(base) ((base) + (0x0040))
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_ADDR(base) ((base) + (0x0044))
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_ADDR(base) ((base) + (0x0048))
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_ADDR(base) ((base) + (0x004C))
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_ADDR(base) ((base) + (0x0050))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_ADDR(base) ((base) + (0x0054))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP1_CFG_ADDR(base) ((base) + (0x0058))
#define SOC_MMC0_HiUSB2RV100_ANA_TOP2_CFG_ADDR(base) ((base) + (0x005C))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_ADDR(base) ((base) + (0x0060))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ADDR(base) ((base) + (0x0064))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_ADDR(base) ((base) + (0x0068))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_ADDR(base) ((base) + (0x006C))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_ADDR(base) ((base) + (0x0070))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_ADDR(base) ((base) + (0x0074))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_ADDR(base) ((base) + (0x0078))
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD7_CFG_ADDR(base) ((base) + (0x007C))
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_ADDR(base) ((base) + (0x0080))
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ADDR(base) ((base) + (0x0084))
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_ADDR(base) ((base) + (0x0088))
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_ADDR(base) ((base) + (0x008C))
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_ADDR(base) ((base) + (0x0090))
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_ADDR(base) ((base) + (0x0094))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC0_ADDR(base) ((base) + (0x0098))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC1_ADDR(base) ((base) + (0x009C))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC2_ADDR(base) ((base) + (0x00A0))
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC3_ADDR(base) ((base) + (0x00A4))
#define SOC_MMC0_HiUSB2RV100_RSV_R_EC0_ADDR(base) ((base) + (0x00A8))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_ADDR(base) ((base) + (0x0100))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST0_ADDR(base) ((base) + (0x0104))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST1_ADDR(base) ((base) + (0x0108))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST2_ADDR(base) ((base) + (0x010C))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST3_ADDR(base) ((base) + (0x0110))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST4_ADDR(base) ((base) + (0x0114))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST5_ADDR(base) ((base) + (0x0118))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST6_ADDR(base) ((base) + (0x011C))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST7_ADDR(base) ((base) + (0x0120))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST8_ADDR(base) ((base) + (0x0124))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST9_ADDR(base) ((base) + (0x0128))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST10_ADDR(base) ((base) + (0x012C))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST11_ADDR(base) ((base) + (0x0130))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST12_ADDR(base) ((base) + (0x0134))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST13_ADDR(base) ((base) + (0x0138))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST14_ADDR(base) ((base) + (0x013C))
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST15_ADDR(base) ((base) + (0x0140))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_ADDR(base) ((base) + (0x0180))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL0_ADDR(base) ((base) + (0x0184))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_ADDR(base) ((base) + (0x0188))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_ADDR(base) ((base) + (0x018C))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_ADDR(base) ((base) + (0x0190))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_ADDR(base) ((base) + (0x0194))
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_ADDR(base) ((base) + (0x0198))
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL23_ADDR(base) ((base) + (0x019C))
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_ADDR(base) ((base) + (0x01A0))
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_ADDR(base) ((base) + (0x01A4))
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_ADDR(base) ((base) + (0x01A8))
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_ADDR(base) ((base) + (0x01AC))
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_ADDR(base) ((base) + (0x01B0))
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_ADDR(base) ((base) + (0x01B4))
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_ADDR(base) ((base) + (0x01B8))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_ADDR(base) ((base) + (0x01BC))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG1_ADDR(base) ((base) + (0x01C0))
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_ADDR(base) ((base) + (0x01C4))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_ADDR(base) ((base) + (0x01C8))
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_ADDR(base) ((base) + (0x01CC))
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG2_ADDR(base) ((base) + (0x01D0))
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_ADDR(base) ((base) + (0x01D4))
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG1_ADDR(base) ((base) + (0x01D8))
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_ADDR(base) ((base) + (0x01DC))
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_ADDR(base) ((base) + (0x01E0))
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_ADDR(base) ((base) + (0x01E4))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG0_ADDR(base) ((base) + (0x01E8))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG1_ADDR(base) ((base) + (0x01EC))
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG2_ADDR(base) ((base) + (0x01F0))
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG0_ADDR(base) ((base) + (0x01F4))
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG1_ADDR(base) ((base) + (0x01F8))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL0_ADDR(base) ((base) + (0x01FC))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_ADDR(base) ((base) + (0x0200))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_ADDR(base) ((base) + (0x0204))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_ADDR(base) ((base) + (0x0208))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL4_ADDR(base) ((base) + (0x020C))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_ADDR(base) ((base) + (0x0210))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_ADDR(base) ((base) + (0x0214))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL7_ADDR(base) ((base) + (0x0218))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL8_ADDR(base) ((base) + (0x021C))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL9_ADDR(base) ((base) + (0x0220))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL10_ADDR(base) ((base) + (0x0224))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL11_ADDR(base) ((base) + (0x0228))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL12_ADDR(base) ((base) + (0x022C))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_ADDR(base) ((base) + (0x0230))
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL14_ADDR(base) ((base) + (0x0234))
#define SOC_MMC0_HiUSB2RV100_BIST_DEBUG_ADDR(base) ((base) + (0x0238))
#define SOC_MMC0_HiUSB2RV100_DBG_IO_CFG_ADDR(base) ((base) + (0x023C))
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD0_ADDR(base) ((base) + (0x0240))
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD1_ADDR(base) ((base) + (0x0244))
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD0_ADDR(base) ((base) + (0x0248))
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD1_ADDR(base) ((base) + (0x024C))
#define SOC_MMC0_HiUSB2RV100_DBG_OPMODE_RCD_ADDR(base) ((base) + (0x0250))
#define SOC_MMC0_HiUSB2RV100_DBG_XCVRSELECT_RCD_ADDR(base) ((base) + (0x0254))
#define SOC_MMC0_HiUSB2RV100_DBG_DISCONNECT_RCD_ADDR(base) ((base) + (0x0258))
#define SOC_MMC0_HiUSB2RV100_DBG_TERMSELECT_RCD_ADDR(base) ((base) + (0x025C))
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_ADDR(base) ((base) + (0x0260))
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_ADDR(base) ((base) + (0x0264))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_ADDR(base) ((base) + (0x0268))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER1_ADDR(base) ((base) + (0x026C))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_ADDR(base) ((base) + (0x0270))
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_ADDR(base) ((base) + (0x0274))
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_ADDR(base) ((base) + (0x0278))
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_ADDR(base) ((base) + (0x027C))
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_ADDR(base) ((base) + (0x0280))
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_ADDR(base) ((base) + (0x0284))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_ADDR(base) ((base) + (0x0288))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_ADDR(base) ((base) + (0x028C))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_ADDR(base) ((base) + (0x0290))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_ADDR(base) ((base) + (0x0294))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG3_ADDR(base) ((base) + (0x0298))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG4_ADDR(base) ((base) + (0x029C))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG5_ADDR(base) ((base) + (0x02A0))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG6_ADDR(base) ((base) + (0x02A4))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG7_ADDR(base) ((base) + (0x02A8))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG8_ADDR(base) ((base) + (0x02AC))
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG9_ADDR(base) ((base) + (0x02B0))
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_ADDR(base) ((base) + (0x02B4))
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_ADDR(base) ((base) + (0x02B8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short minor_revision : 4;
        unsigned short major_revision : 4;
        unsigned short tech_node : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_VERSION_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_minor_revision_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_minor_revision_END (3)
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_major_revision_START (4)
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_major_revision_END (7)
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_tech_node_START (8)
#define SOC_MMC0_HiUSB2RV100_PHY_VERSION_tech_node_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short suspend_n_ovrd : 1;
        unsigned short suspend_n_ovrd_en : 1;
        unsigned short sleep_n_ovrd : 1;
        unsigned short sleep_n_ovrd_en : 1;
        unsigned short port_reset_ovrd : 1;
        unsigned short port_reset_ovrd_en : 1;
        unsigned short reserved : 10;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_suspend_n_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_suspend_n_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_suspend_n_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_suspend_n_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_sleep_n_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_sleep_n_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_sleep_n_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_sleep_n_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_port_reset_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_port_reset_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_port_reset_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL0_port_reset_ovrd_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short termselect_ovrd : 1;
        unsigned short termselect_ovrd_en : 1;
        unsigned short xcvrselect_ovrd : 2;
        unsigned short xcvrselect_ovrd_en : 1;
        unsigned short dppulldown_ovrd : 1;
        unsigned short dppulldown_ovrd_en : 1;
        unsigned short dmpulldown_ovrd : 1;
        unsigned short dmpulldown_ovrd_en : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_termselect_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_termselect_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_termselect_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_termselect_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_xcvrselect_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_xcvrselect_ovrd_END (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_xcvrselect_ovrd_en_START (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_xcvrselect_ovrd_en_END (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dppulldown_ovrd_START (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dppulldown_ovrd_END (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dppulldown_ovrd_en_START (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dppulldown_ovrd_en_END (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dmpulldown_ovrd_START (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dmpulldown_ovrd_END (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dmpulldown_ovrd_en_START (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL1_dmpulldown_ovrd_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short txbitstuffen_ovrd : 1;
        unsigned short txbitstuffen_ovrd_en : 1;
        unsigned short tx_valid_ovrd : 1;
        unsigned short tx_valid_ovrd_en : 1;
        unsigned short txdata_ovrd : 8;
        unsigned short txdata_ovrd_en : 1;
        unsigned short opmode_ovrd : 2;
        unsigned short opmode_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txbitstuffen_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txbitstuffen_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txbitstuffen_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txbitstuffen_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_tx_valid_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_tx_valid_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_tx_valid_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_tx_valid_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txdata_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txdata_ovrd_END (11)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txdata_ovrd_en_START (12)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_txdata_ovrd_en_END (12)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_opmode_ovrd_START (13)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_opmode_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_opmode_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL2_opmode_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short linestate_ovrd : 2;
        unsigned short linestate_ovrd_en : 1;
        unsigned short hostdisconnect_ovrd : 1;
        unsigned short hostdisconnect_ovrd_en : 1;
        unsigned short fsls_serial_mode_ovrd : 1;
        unsigned short fsls_serial_mode_ovrd_en : 1;
        unsigned short rxdata_ovrd : 8;
        unsigned short rxdata_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_linestate_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_linestate_ovrd_END (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_linestate_ovrd_en_START (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_linestate_ovrd_en_END (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_hostdisconnect_ovrd_START (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_hostdisconnect_ovrd_END (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_hostdisconnect_ovrd_en_START (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_hostdisconnect_ovrd_en_END (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_fsls_serial_mode_ovrd_START (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_fsls_serial_mode_ovrd_END (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_fsls_serial_mode_ovrd_en_START (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_fsls_serial_mode_ovrd_en_END (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_rxdata_ovrd_START (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_rxdata_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_rxdata_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL3_rxdata_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rxerror_ovrd : 1;
        unsigned short rxerror_ovrd_en : 1;
        unsigned short rxactive_ovrd : 1;
        unsigned short rxactive_ovrd_en : 1;
        unsigned short rxvalid_ovrd : 1;
        unsigned short rxvalid_ovrd_en : 1;
        unsigned short txready_ovrd : 1;
        unsigned short txready_ovrd_en : 1;
        unsigned short txbitstuffen_h_ovrd : 1;
        unsigned short txbitstuffen_h_ovrd_en : 1;
        unsigned short fsls_txse0_ovrd : 1;
        unsigned short fsls_txse0_ovrd_en : 1;
        unsigned short fsls_txdata_ovrd : 1;
        unsigned short fsls_txdata_ovrd_en : 1;
        unsigned short fsls_txenablen_ovrd : 1;
        unsigned short fsls_txenablen_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxerror_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxerror_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxerror_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxerror_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxactive_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxactive_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxactive_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxactive_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxvalid_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxvalid_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxvalid_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_rxvalid_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txready_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txready_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txready_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txready_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txbitstuffen_h_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txbitstuffen_h_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txbitstuffen_h_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_txbitstuffen_h_ovrd_en_END (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txse0_ovrd_START (10)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txse0_ovrd_END (10)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txse0_ovrd_en_START (11)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txse0_ovrd_en_END (11)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txdata_ovrd_START (12)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txdata_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txdata_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txdata_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txenablen_ovrd_START (14)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txenablen_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txenablen_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL4_fsls_txenablen_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short txdata_h_ovrd : 8;
        unsigned short txdata_h_ovrd_en : 1;
        unsigned short tx_valid_h_ovrd : 1;
        unsigned short tx_valid_h_ovrd_en : 1;
        unsigned short databus_ovrd : 1;
        unsigned short databus_ovrd_en : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_txdata_h_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_txdata_h_ovrd_END (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_txdata_h_ovrd_en_START (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_txdata_h_ovrd_en_END (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_tx_valid_h_ovrd_START (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_tx_valid_h_ovrd_END (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_tx_valid_h_ovrd_en_START (10)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_tx_valid_h_ovrd_en_END (10)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_databus_ovrd_START (11)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_databus_ovrd_END (11)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_databus_ovrd_en_START (12)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL5_databus_ovrd_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rxdata_h_ovrd : 8;
        unsigned short rxdata_h_ovrd_en : 1;
        unsigned short rx_valid_h_ovrd : 1;
        unsigned short rx_valid_h_ovrd_en : 1;
        unsigned short reserved : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rxdata_h_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rxdata_h_ovrd_END (7)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rxdata_h_ovrd_en_START (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rxdata_h_ovrd_en_END (8)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rx_valid_h_ovrd_START (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rx_valid_h_ovrd_END (9)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rx_valid_h_ovrd_en_START (10)
#define SOC_MMC0_HiUSB2RV100_UTMI_OVRD_CTRL6_rx_valid_h_ovrd_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_bg_soft_en : 1;
        unsigned short d2a_bg_detec_en : 1;
        unsigned short d2a_bg_tst : 2;
        unsigned short d2a_bg_mt_tune : 3;
        unsigned short d2a_bg_mt_en : 1;
        unsigned short d2a_ldo_vref_tune : 3;
        unsigned short d2a_bg_tx_vref_tune : 4;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_soft_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_soft_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_detec_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_detec_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_tst_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_tst_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_mt_tune_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_mt_tune_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_mt_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_mt_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_ldo_vref_tune_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_ldo_vref_tune_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_tx_vref_tune_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_BGR_CFG_d2a_bg_tx_vref_tune_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_ldo_tst_en : 1;
        unsigned short d2a_topldo_test : 2;
        unsigned short d2a_topldo_trim : 2;
        unsigned short d2a_ldo_div_test_en : 1;
        unsigned short d2a_ldo_div_sel : 2;
        unsigned short d2a_ldo_div_power_sw_en : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_tst_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_tst_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_topldo_test_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_topldo_test_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_topldo_trim_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_topldo_trim_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_test_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_test_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_sel_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_sel_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_power_sw_en_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_LDO_TX_d2a_ldo_div_power_sw_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_tx_hs_drvcap_main_selh : 2;
        unsigned short d2a_tx_hs_de_en : 1;
        unsigned short reserved_0 : 1;
        unsigned short d2a_tx_hs_main_ibsel : 6;
        unsigned short d2a_tx_hs_de_ibsel : 4;
        unsigned short d2a_tx_hs_drvcap_de_selh : 1;
        unsigned short reserved_1 : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_drvcap_main_selh_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_drvcap_main_selh_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_de_en_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_de_en_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_main_ibsel_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_main_ibsel_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_de_ibsel_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_de_ibsel_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_drvcap_de_selh_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_TX0_CFG_d2a_tx_hs_drvcap_de_selh_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_tx_hs_drvcap_main_sel : 4;
        unsigned short d2a_tx_hs_drvcap_de_sel : 4;
        unsigned short reserved : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_d2a_tx_hs_drvcap_main_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_d2a_tx_hs_drvcap_main_sel_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_d2a_tx_hs_drvcap_de_sel_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_TX1_CFG_d2a_tx_hs_drvcap_de_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_tx_fls_rtp_cal_ovrd : 6;
        unsigned short d2a_tx_rtn_ovrd : 6;
        unsigned short d2a_tx_fls_rtp_cal_ovrd_en : 1;
        unsigned short d2a_tx_rtn_ovrd_en : 1;
        unsigned short tx_fls_sr_slow_ovrd_en : 1;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_fls_rtp_cal_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_fls_rtp_cal_ovrd_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_rtn_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_rtn_ovrd_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_fls_rtp_cal_ovrd_en_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_fls_rtp_cal_ovrd_en_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_rtn_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_d2a_tx_rtn_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_tx_fls_sr_slow_ovrd_en_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_TX2_CFG_tx_fls_sr_slow_ovrd_en_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_tx_test : 8;
        unsigned short cfg_tx_fls_clkdivby2 : 1;
        unsigned short cfg_tx_fls_clkdivby4 : 1;
        unsigned short cfg_tx_fls_sr_selslow : 1;
        unsigned short tx_code_sel_ovrd : 2;
        unsigned short tx_code_sel_ovrd_en : 1;
        unsigned short tx_fls_clkdivby4_ovrd_en : 1;
        unsigned short tx_fls_clkdivby2_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_d2a_tx_test_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_d2a_tx_test_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_clkdivby2_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_clkdivby2_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_clkdivby4_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_clkdivby4_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_sr_selslow_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_cfg_tx_fls_sr_selslow_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_code_sel_ovrd_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_code_sel_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_code_sel_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_code_sel_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_fls_clkdivby4_ovrd_en_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_fls_clkdivby4_ovrd_en_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_fls_clkdivby2_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_TX3_CFG_tx_fls_clkdivby2_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_rx_sq_filter_en : 1;
        unsigned short d2a_rx_hs_clk180_en : 1;
        unsigned short d2a_rx_selfbias_en : 1;
        unsigned short d2a_rx_hs_buf_sel : 2;
        unsigned short d2a_rx_sq_bias_sel : 2;
        unsigned short d2a_rx_sq_il_sel : 4;
        unsigned short d2a_rx_sq_in_sel : 1;
        unsigned short reserved_0 : 2;
        unsigned short d2a_rx_test_vref_sel : 1;
        unsigned short reserved_1 : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_filter_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_filter_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_hs_clk180_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_hs_clk180_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_selfbias_en_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_selfbias_en_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_hs_buf_sel_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_hs_buf_sel_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_bias_sel_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_bias_sel_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_il_sel_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_il_sel_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_in_sel_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_sq_in_sel_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_test_vref_sel_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_RX0_CFG_d2a_rx_test_vref_sel_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_rx_disc_il_sel : 3;
        unsigned short reserved_0 : 2;
        unsigned short d2a_rx_hs_valid_delay_sel : 2;
        unsigned short reserved_1 : 1;
        unsigned short d2a_rx_src_vref_sel : 2;
        unsigned short d2a_rx_tst_sel : 3;
        unsigned short d2a_rx_tst_en : 1;
        unsigned short reserved_2 : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_disc_il_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_disc_il_sel_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_hs_valid_delay_sel_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_hs_valid_delay_sel_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_src_vref_sel_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_src_vref_sel_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_tst_sel_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_tst_sel_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_tst_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_RX1_CFG_d2a_rx_tst_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_rx_hs_path_en : 1;
        unsigned short d2a_rx_vbus_vref : 2;
        unsigned short d2a_rx_dcd_vref_sel : 2;
        unsigned short reserved : 11;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_hs_path_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_hs_path_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_vbus_vref_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_vbus_vref_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_dcd_vref_sel_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_RX2_CFG_d2a_rx_dcd_vref_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_vco_st_pd : 1;
        unsigned short d2a_vco_st_mcu_en : 1;
        unsigned short d2a_pll_fastlock_pd : 1;
        unsigned short d2a_pll_fastlock_sel : 2;
        unsigned short d2a_pll_ref_div_ovrd_en : 1;
        unsigned short d2a_pll_ref_div_ovrd : 2;
        unsigned short d2a_pll_fb_div_ovrd_en : 1;
        unsigned short d2a_pll_fb_div_ovrd : 6;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_vco_st_pd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_vco_st_pd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_vco_st_mcu_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_vco_st_mcu_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fastlock_pd_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fastlock_pd_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fastlock_sel_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fastlock_sel_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_ref_div_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_ref_div_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_ref_div_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_ref_div_ovrd_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fb_div_ovrd_en_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fb_div_ovrd_en_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fb_div_ovrd_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL0_CFG_d2a_pll_fb_div_ovrd_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_pll_test_en : 1;
        unsigned short d2a_pll_test_sel : 3;
        unsigned short d2a_pll_en_lckdet : 1;
        unsigned short d2a_pll_force_lock : 1;
        unsigned short d2a_pll_cp : 4;
        unsigned short a2d_pll_lock : 1;
        unsigned short a2d_pll_lock_dbg : 1;
        unsigned short a2d_pll_lock_dbg_clr : 1;
        unsigned short d2a_pll_fb_div_sel : 1;
        unsigned short reserved : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_test_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_test_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_test_sel_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_test_sel_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_en_lckdet_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_en_lckdet_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_force_lock_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_force_lock_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_cp_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_cp_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_dbg_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_dbg_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_dbg_clr_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_a2d_pll_lock_dbg_clr_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_fb_div_sel_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_PLL1_CFG_d2a_pll_fb_div_sel_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_vbus_det_en : 1;
        unsigned short d2a_bc12_det_en : 1;
        unsigned short d2a_data_src_en : 1;
        unsigned short d2a_dcd_det_en : 1;
        unsigned short d2a_rx_charge_sel : 1;
        unsigned short a2d_charge_det : 1;
        unsigned short a2d_otgsessvid : 1;
        unsigned short a2d_fsvplus : 1;
        unsigned short a2d_fsvminus : 1;
        unsigned short vbus_det_sel : 1;
        unsigned short vbus_deb_sel : 2;
        unsigned short d2a_rx_idp_sink_en : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_vbus_det_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_vbus_det_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_bc12_det_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_bc12_det_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_data_src_en_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_data_src_en_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_dcd_det_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_dcd_det_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_rx_charge_sel_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_rx_charge_sel_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_charge_det_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_charge_det_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_otgsessvid_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_otgsessvid_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_fsvplus_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_fsvplus_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_fsvminus_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_a2d_fsvminus_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_vbus_det_sel_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_vbus_det_sel_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_vbus_deb_sel_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_vbus_deb_sel_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_rx_idp_sink_en_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_BC12_CFG_d2a_rx_idp_sink_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_vpbias_vsel : 2;
        unsigned short d2a_vpbias_isel : 2;
        unsigned short reserved : 12;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_d2a_vpbias_vsel_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_d2a_vpbias_vsel_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_d2a_vpbias_isel_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_BIAS_CFG_d2a_vpbias_isel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_atp_sel : 2;
        unsigned short d2a_cktst_sel : 1;
        unsigned short a2d_clktst : 1;
        unsigned short d2a_rt_code_fb_sel : 1;
        unsigned short reserved : 11;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_atp_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_atp_sel_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_cktst_sel_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_cktst_sel_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_a2d_clktst_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_a2d_clktst_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_rt_code_fb_sel_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP0_CFG_d2a_rt_code_fb_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_ana_port_resv : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TOP1_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TOP1_CFG_d2a_ana_port_resv_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP1_CFG_d2a_ana_port_resv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_ana_common_resv : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_TOP2_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_TOP2_CFG_d2a_ana_common_resv_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_TOP2_CFG_d2a_ana_common_resv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_fls_en_ovrd : 1;
        unsigned short tx_fls_en_ovrd_en : 1;
        unsigned short tx_fls_dm_ovrd : 1;
        unsigned short tx_fls_dm_ovrd_en : 1;
        unsigned short tx_fls_dp_ovrd : 1;
        unsigned short tx_fls_dp_ovrd_en : 1;
        unsigned short tx_hs_chirp_en_ovrd : 1;
        unsigned short tx_hs_chirp_en_ovrd_en : 1;
        unsigned short tx_hs_prec_en_ovrd : 1;
        unsigned short tx_hs_prec_en_ovrd_en : 1;
        unsigned short tx_hs_driver_en_ovrd : 1;
        unsigned short tx_hs_driver_en_ovrd_en : 1;
        unsigned short tx_hs_cur_en_ovrd : 1;
        unsigned short tx_hs_cur_en_ovrd_en : 1;
        unsigned short tx_hs_din_ovrd : 1;
        unsigned short tx_hs_din_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_en_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_en_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_en_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_en_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dm_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dm_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dm_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dm_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dp_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dp_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dp_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_fls_dp_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_chirp_en_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_chirp_en_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_chirp_en_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_chirp_en_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_prec_en_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_prec_en_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_prec_en_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_prec_en_ovrd_en_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_driver_en_ovrd_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_driver_en_ovrd_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_driver_en_ovrd_en_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_driver_en_ovrd_en_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_cur_en_ovrd_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_cur_en_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_cur_en_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_cur_en_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_din_ovrd_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_din_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_din_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD0_CFG_tx_hs_din_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_fls_ase0_en_ovrd : 1;
        unsigned short tx_fls_ase0_en_ovrd_en : 1;
        unsigned short ldo_en_ovrd : 1;
        unsigned short ldo_en_ovrd_en : 1;
        unsigned short bg_en_ovrd : 1;
        unsigned short bg_en_ovrd_en : 1;
        unsigned short pll_en_ovrd : 1;
        unsigned short pll_en_ovrd_en : 1;
        unsigned short ldo_div_en_ovrd : 1;
        unsigned short ldo_div_en_ovrd_en : 1;
        unsigned short reserved : 6;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_tx_fls_ase0_en_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_tx_fls_ase0_en_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_tx_fls_ase0_en_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_tx_fls_ase0_en_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_en_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_en_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_en_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_en_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_bg_en_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_bg_en_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_bg_en_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_bg_en_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_pll_en_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_pll_en_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_pll_en_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_pll_en_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_div_en_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_div_en_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_div_en_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD1_CFG_ldo_div_en_ovrd_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short data_valid_ovrd : 1;
        unsigned short data_valid_ovrd_en : 1;
        unsigned short sedm_ovrd : 1;
        unsigned short sedm_ovrd_en : 1;
        unsigned short sedp_ovrd : 1;
        unsigned short sedp_ovrd_en : 1;
        unsigned short fls_dfrx_en_ovrd : 1;
        unsigned short fls_dfrx_en_ovrd_en : 1;
        unsigned short disconnect_en_ovrd : 1;
        unsigned short disconnect_en_ovrd_en : 1;
        unsigned short rx_hs_en_ovrd : 1;
        unsigned short rx_hs_en_ovrd_en : 1;
        unsigned short rx_sq_en_ovrd : 1;
        unsigned short rx_sq_en_ovrd_en : 1;
        unsigned short rx_fls_serx_en_ovrd : 1;
        unsigned short rx_fls_serx_en_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_data_valid_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_data_valid_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_data_valid_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_data_valid_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedm_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedm_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedm_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedm_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedp_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedp_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedp_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_sedp_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_fls_dfrx_en_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_fls_dfrx_en_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_fls_dfrx_en_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_fls_dfrx_en_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_disconnect_en_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_disconnect_en_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_disconnect_en_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_disconnect_en_ovrd_en_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_hs_en_ovrd_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_hs_en_ovrd_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_hs_en_ovrd_en_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_hs_en_ovrd_en_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_sq_en_ovrd_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_sq_en_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_sq_en_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_sq_en_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_fls_serx_en_ovrd_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_fls_serx_en_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_fls_serx_en_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD2_CFG_rx_fls_serx_en_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short reserved_0 : 4;
        unsigned short rx_en_ovrd : 1;
        unsigned short rx_en_ovrd_en : 1;
        unsigned short topldo_pd_ovrd_en : 1;
        unsigned short topldo_pd_ovrd : 1;
        unsigned short reserved_1 : 2;
        unsigned short fsel_ovrd : 3;
        unsigned short fsel_ovrd_en : 1;
        unsigned short commononn_ovrd : 1;
        unsigned short commononn_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_rx_en_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_rx_en_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_rx_en_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_rx_en_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_topldo_pd_ovrd_en_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_topldo_pd_ovrd_en_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_topldo_pd_ovrd_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_topldo_pd_ovrd_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_fsel_ovrd_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_fsel_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_fsel_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_fsel_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_commononn_ovrd_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_commononn_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_commononn_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD3_CFG_commononn_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short vpbias_en_ovrd : 1;
        unsigned short vpbias_en_ovrd_en : 1;
        unsigned short vpbias_test_en_ovrd : 1;
        unsigned short vpbias_test_en_ovrd_en : 1;
        unsigned short tx_fls_rstb_ovrd : 1;
        unsigned short tx_fls_rstb_ovrd_en : 1;
        unsigned short tx_hs_op_en_ovrd : 1;
        unsigned short tx_hs_op_en_ovrd_en : 1;
        unsigned short tx_hs_reset_ovrd : 1;
        unsigned short tx_hs_reset_ovrd_en : 1;
        unsigned short reserved : 6;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_en_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_en_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_en_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_en_ovrd_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_test_en_ovrd_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_test_en_ovrd_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_test_en_ovrd_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_vpbias_test_en_ovrd_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_fls_rstb_ovrd_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_fls_rstb_ovrd_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_fls_rstb_ovrd_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_fls_rstb_ovrd_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_op_en_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_op_en_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_op_en_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_op_en_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_reset_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_reset_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_reset_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD4_CFG_tx_hs_reset_ovrd_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rtune_en_ovrd : 1;
        unsigned short rtune_en_ovrd_en : 1;
        unsigned short reserved : 14;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_rtune_en_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_rtune_en_ovrd_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_rtune_en_ovrd_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD5_CFG_rtune_en_ovrd_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short reserved : 6;
        unsigned short topldo_por_ovrd : 1;
        unsigned short topldo_por_ovrd_en : 1;
        unsigned short dm_pulldown_ovrd : 1;
        unsigned short dm_pulldown_ovrd_en : 1;
        unsigned short dp_pulldown_ovrd : 1;
        unsigned short dp_pulldown_ovrd_en : 1;
        unsigned short dm_pullup_ovrd : 1;
        unsigned short dm_pullup_ovrd_en : 1;
        unsigned short dp_pullup_ovrd : 1;
        unsigned short dp_pullup_ovrd_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_topldo_por_ovrd_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_topldo_por_ovrd_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_topldo_por_ovrd_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_topldo_por_ovrd_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pulldown_ovrd_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pulldown_ovrd_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pulldown_ovrd_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pulldown_ovrd_en_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pulldown_ovrd_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pulldown_ovrd_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pulldown_ovrd_en_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pulldown_ovrd_en_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pullup_ovrd_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pullup_ovrd_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pullup_ovrd_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dm_pullup_ovrd_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pullup_ovrd_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pullup_ovrd_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pullup_ovrd_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD6_CFG_dp_pullup_ovrd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short a2d_hsdout : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_OVRD7_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD7_CFG_a2d_hsdout_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_OVRD7_CFG_a2d_hsdout_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cfg_rtun_code_ovrd : 6;
        unsigned short cfg_rtun_code_ovrd_en : 1;
        unsigned short rtun_realtime_host_en : 1;
        unsigned short rtun_realtime_device_en : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_cfg_rtun_code_ovrd_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_cfg_rtun_code_ovrd_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_cfg_rtun_code_ovrd_en_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_cfg_rtun_code_ovrd_en_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_rtun_realtime_host_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_rtun_realtime_host_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_rtun_realtime_device_en_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUNING_OVRD_CFG_rtun_realtime_device_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short ana_pwrdn_done : 1;
        unsigned short ana_pwrup_done : 1;
        unsigned short a2d_rtout : 6;
        unsigned short a2d_rt_done : 1;
        unsigned short a2d_fls_dfrx_data : 1;
        unsigned short a2d_hs_disconnect : 1;
        unsigned short a2d_squelch : 1;
        unsigned short a2d_sedm : 1;
        unsigned short a2d_sedp : 1;
        unsigned short a2d_data_vld : 1;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ana_pwrdn_done_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ana_pwrdn_done_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ana_pwrup_done_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_ana_pwrup_done_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_rtout_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_rtout_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_rt_done_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_rt_done_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_fls_dfrx_data_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_fls_dfrx_data_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_hs_disconnect_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_hs_disconnect_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_squelch_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_squelch_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_sedm_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_sedm_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_sedp_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_sedp_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_data_vld_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_RO_a2d_data_vld_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_ldo_en : 1;
        unsigned short d2a_bg_en : 1;
        unsigned short d2a_pll_en : 1;
        unsigned short d2a_rx_en : 1;
        unsigned short d2a_fls_dfrx_en : 1;
        unsigned short d2a_fls_serx_en : 1;
        unsigned short d2a_tx_hs_op_en : 1;
        unsigned short d2a_vpbias_en : 1;
        unsigned short d2a_en_rt : 1;
        unsigned short d2a_rx_sq_en : 1;
        unsigned short d2a_rx_hs_en : 1;
        unsigned short d2a_tx_fls_sr_selslow : 1;
        unsigned short d2a_tx_fls_clkdivby4 : 1;
        unsigned short d2a_tx_fls_clkdivby2 : 1;
        unsigned short d2a_tx_fls_ase0_en : 1;
        unsigned short d2a_tx_fls_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_ldo_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_ldo_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_bg_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_bg_en_END (1)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_pll_en_START (2)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_pll_en_END (2)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_en_START (3)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_en_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_fls_dfrx_en_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_fls_dfrx_en_END (4)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_fls_serx_en_START (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_fls_serx_en_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_hs_op_en_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_hs_op_en_END (6)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_vpbias_en_START (7)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_vpbias_en_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_en_rt_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_en_rt_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_sq_en_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_sq_en_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_hs_en_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_rx_hs_en_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_sr_selslow_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_sr_selslow_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_clkdivby4_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_clkdivby4_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_clkdivby2_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_clkdivby2_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_ase0_en_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_ase0_en_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_en_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_PWRUP_R1_d2a_tx_fls_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rtun_sft_cfg : 4;
        unsigned short dbg_rtuning_data : 6;
        unsigned short d2a_tx_hs_chirp_en : 1;
        unsigned short d2a_tx_hs_reset : 1;
        unsigned short d2a_tx_fls_rstb : 1;
        unsigned short a2d_topldo_por : 1;
        unsigned short d2a_tx_fls_dm : 1;
        unsigned short d2a_tx_fls_dp : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_rtun_sft_cfg_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_rtun_sft_cfg_END (3)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_dbg_rtuning_data_START (4)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_dbg_rtuning_data_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_hs_chirp_en_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_hs_chirp_en_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_hs_reset_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_hs_reset_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_rstb_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_rstb_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_a2d_topldo_por_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_a2d_topldo_por_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_dm_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_dm_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_dp_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_RTUN_SFT_CFG_d2a_tx_fls_dp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_tx_fls_rtp_cal : 6;
        unsigned short d2a_tx_rtn : 6;
        unsigned short d2a_tx_hs_prec_en : 1;
        unsigned short d2a_tx_hs_driver_en : 1;
        unsigned short d2a_tx_hs_cur_en : 1;
        unsigned short d2a_tx_hs_din : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_fls_rtp_cal_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_fls_rtp_cal_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_rtn_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_rtn_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_prec_en_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_prec_en_END (12)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_driver_en_START (13)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_driver_en_END (13)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_cur_en_START (14)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_cur_en_END (14)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_din_START (15)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO_d2a_tx_hs_din_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d2a_pll_fb_div : 6;
        unsigned short d2a_pll_ref_div : 2;
        unsigned short d2a_dp_pullup : 1;
        unsigned short d2a_dm_pullup : 1;
        unsigned short d2a_dp_pulldown : 1;
        unsigned short d2a_dm_pulldown : 1;
        unsigned short d2a_ldo_div_en : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_pll_fb_div_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_pll_fb_div_END (5)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_pll_ref_div_START (6)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_pll_ref_div_END (7)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dp_pullup_START (8)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dp_pullup_END (8)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dm_pullup_START (9)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dm_pullup_END (9)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dp_pulldown_START (10)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dp_pulldown_END (10)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dm_pulldown_START (11)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_dm_pulldown_END (11)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_ldo_div_en_START (12)
#define SOC_MMC0_HiUSB2RV100_ANA_DBG_RO1_d2a_ldo_div_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rsv_w_ec0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_RSV_W_EC0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC0_rsv_w_ec0_START (0)
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC0_rsv_w_ec0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rsv_w_ec1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_RSV_W_EC1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC1_rsv_w_ec1_START (0)
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC1_rsv_w_ec1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rsv_w_ec2 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_RSV_W_EC2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC2_rsv_w_ec2_START (0)
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC2_rsv_w_ec2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rsv_w_ec3 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_RSV_W_EC3_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC3_rsv_w_ec3_START (0)
#define SOC_MMC0_HiUSB2RV100_RSV_W_EC3_rsv_w_ec3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rsv_r_ec1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_RSV_R_EC0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RSV_R_EC0_rsv_r_ec1_START (0)
#define SOC_MMC0_HiUSB2RV100_RSV_R_EC0_rsv_r_ec1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_eye_shift_en : 1;
        unsigned short eye_test_en : 1;
        unsigned short reserved : 14;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_bist_eye_shift_en_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_bist_eye_shift_en_END (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_eye_test_en_START (1)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST_EN_eye_test_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST0_eye_test0_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST0_eye_test0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST1_eye_test1_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST1_eye_test1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test2 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST2_eye_test2_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST2_eye_test2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test3 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST3_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST3_eye_test3_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST3_eye_test3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test4 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST4_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST4_eye_test4_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST4_eye_test4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test5 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST5_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST5_eye_test5_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST5_eye_test5_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test6 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST6_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST6_eye_test6_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST6_eye_test6_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test7 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST7_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST7_eye_test7_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST7_eye_test7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test8 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST8_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST8_eye_test8_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST8_eye_test8_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test9 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST9_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST9_eye_test9_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST9_eye_test9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test10 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST10_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST10_eye_test10_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST10_eye_test10_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test11 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST11_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST11_eye_test11_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST11_eye_test11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test12 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST12_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST12_eye_test12_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST12_eye_test12_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test13 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST13_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST13_eye_test13_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST13_eye_test13_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test14 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST14_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST14_eye_test14_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST14_eye_test14_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short eye_test15 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST15_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST15_eye_test15_START (0)
#define SOC_MMC0_HiUSB2RV100_ANA_EYE_TEST15_eye_test15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_idle_cnt_ls : 8;
        unsigned short tx_idle_cnt_fs : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_tx_idle_cnt_ls_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_tx_idle_cnt_ls_END (7)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_tx_idle_cnt_fs_START (8)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL_tx_idle_cnt_fs_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cfg_soft_rst_timer : 6;
        unsigned short reserved : 10;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL0_cfg_soft_rst_timer_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL0_cfg_soft_rst_timer_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rg_test_atop_31 : 1;
        unsigned short ck_usable_sel : 1;
        unsigned short rg_soft_rstn_val : 1;
        unsigned short rg_soft_rstn_cfg : 1;
        unsigned short rg_preamble_srst_cfg : 1;
        unsigned short rg_pll_lock_val : 1;
        unsigned short rg_pll_lock_cfg : 1;
        unsigned short abort1_timer_cfg : 5;
        unsigned short phy_utmi_ckgt_en : 1;
        unsigned short phy_utmi_ckgt_ovrd : 1;
        unsigned short phy_fclk_ckgt_en : 1;
        unsigned short phy_fclk_ckgt_ovrd : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_test_atop_31_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_test_atop_31_END (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_ck_usable_sel_START (1)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_ck_usable_sel_END (1)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_soft_rstn_val_START (2)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_soft_rstn_val_END (2)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_soft_rstn_cfg_START (3)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_soft_rstn_cfg_END (3)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_preamble_srst_cfg_START (4)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_preamble_srst_cfg_END (4)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_pll_lock_val_START (5)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_pll_lock_val_END (5)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_pll_lock_cfg_START (6)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_rg_pll_lock_cfg_END (6)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_abort1_timer_cfg_START (7)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_abort1_timer_cfg_END (11)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_utmi_ckgt_en_START (12)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_utmi_ckgt_en_END (12)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_utmi_ckgt_ovrd_START (13)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_utmi_ckgt_ovrd_END (13)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_fclk_ckgt_en_START (14)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_fclk_ckgt_en_END (14)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_fclk_ckgt_ovrd_START (15)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL1_phy_fclk_ckgt_ovrd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rg_hsdll_ckgt : 1;
        unsigned short rg_hsdll_ckgt_cfg : 1;
        unsigned short rg_phy_utmi_ckgt : 1;
        unsigned short rg_phy_utmi_ckgt_cfg : 1;
        unsigned short rg_phy_rx_ckgt : 1;
        unsigned short rg_phy_rx_ckgt_cfg : 1;
        unsigned short rg_phy_tx_ckgt : 1;
        unsigned short rg_phy_tx_ckgt_cfg : 1;
        unsigned short rg_hs_disc_ckgt : 1;
        unsigned short rg_hs_disc_ckgt_cfg : 1;
        unsigned short rg_fsdll_ckgt : 1;
        unsigned short rg_fsdll_ckgt_cfg : 1;
        unsigned short fsls_idle_timer_cfg : 4;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hsdll_ckgt_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hsdll_ckgt_END (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hsdll_ckgt_cfg_START (1)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hsdll_ckgt_cfg_END (1)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_utmi_ckgt_START (2)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_utmi_ckgt_END (2)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_utmi_ckgt_cfg_START (3)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_utmi_ckgt_cfg_END (3)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_rx_ckgt_START (4)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_rx_ckgt_END (4)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_rx_ckgt_cfg_START (5)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_rx_ckgt_cfg_END (5)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_tx_ckgt_START (6)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_tx_ckgt_END (6)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_tx_ckgt_cfg_START (7)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_phy_tx_ckgt_cfg_END (7)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hs_disc_ckgt_START (8)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hs_disc_ckgt_END (8)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hs_disc_ckgt_cfg_START (9)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_hs_disc_ckgt_cfg_END (9)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_fsdll_ckgt_START (10)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_fsdll_ckgt_END (10)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_fsdll_ckgt_cfg_START (11)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_rg_fsdll_ckgt_cfg_END (11)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_fsls_idle_timer_cfg_START (12)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL22_fsls_idle_timer_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short esbuf_gap_err_cnt : 8;
        unsigned short esbuf_rd_err_cnt : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_esbuf_gap_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_esbuf_gap_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_esbuf_rd_err_cnt_START (8)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG0_esbuf_rd_err_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short esbuf_wr_err_cnt : 8;
        unsigned short esbuf_state_clr : 1;
        unsigned short reserved : 2;
        unsigned short esbuf_pkt_gap_cfg : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_wr_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_wr_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_state_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_state_clr_END (8)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_pkt_gap_cfg_START (11)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG1_esbuf_pkt_gap_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hsdll_threshold : 3;
        unsigned short hsdll_lock_phase : 4;
        unsigned short hsdll_one_ui_filter_en : 1;
        unsigned short esbuf_depth_cfg : 3;
        unsigned short reserved : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_threshold_START (0)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_threshold_END (2)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_lock_phase_START (3)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_lock_phase_END (6)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_one_ui_filter_en_START (7)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_hsdll_one_ui_filter_en_END (7)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_esbuf_depth_cfg_START (8)
#define SOC_MMC0_HiUSB2RV100_HSDLL_CFG2_esbuf_depth_cfg_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hubsetup_cnt_val : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL23_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL23_hubsetup_cnt_val_START (0)
#define SOC_MMC0_HiUSB2RV100_PHY_DIG_CTRL23_hubsetup_cnt_val_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_sm_cur_st : 8;
        unsigned short rx_sm_cur_st : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_DIG_STATUS0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_tx_sm_cur_st_START (0)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_tx_sm_cur_st_END (7)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_rx_sm_cur_st_START (8)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS0_rx_sm_cur_st_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_opmode_sel : 1;
        unsigned short hs_disc_cnt : 3;
        unsigned short rg_host_disc_val : 1;
        unsigned short rg_host_disc_cfg : 1;
        unsigned short reserved_0 : 2;
        unsigned short rx_active_cfg : 1;
        unsigned short rx_preamble_polar : 1;
        unsigned short reserved_1 : 6;
    } reg;
} SOC_MMC0_HiUSB2RV100_DIG_STATUS1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_tx_opmode_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_tx_opmode_sel_END (0)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_hs_disc_cnt_START (1)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_hs_disc_cnt_END (3)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rg_host_disc_val_START (4)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rg_host_disc_val_END (4)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rg_host_disc_cfg_START (5)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rg_host_disc_cfg_END (5)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rx_active_cfg_START (8)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rx_active_cfg_END (8)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rx_preamble_polar_START (9)
#define SOC_MMC0_HiUSB2RV100_DIG_STATUS1_rx_preamble_polar_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_m_value : 6;
        unsigned short hs_n_value : 3;
        unsigned short fsls_m_value : 4;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_hs_m_value_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_hs_m_value_END (5)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_hs_n_value_START (6)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_hs_n_value_END (8)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_fsls_m_value_START (9)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_DET_CFG_fsls_m_value_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_stf_err_cnt : 8;
        unsigned short rx_stf_err_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_rx_stf_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_rx_stf_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_rx_stf_err_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_RX_STUFF_ERR_CNT_rx_stf_err_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_sync_err_cnt : 12;
        unsigned short rx_sync_err_cnt_clr : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_rx_sync_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_rx_sync_err_cnt_END (11)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_rx_sync_err_cnt_clr_START (12)
#define SOC_MMC0_HiUSB2RV100_RX_SYNC_ERR_CNT_rx_sync_err_cnt_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_eop_err_cnt : 8;
        unsigned short rx_eop_err_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_rx_eop_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_rx_eop_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_rx_eop_err_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_RX_EOP_ERR_CNT_rx_eop_err_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_byte_err_cnt : 12;
        unsigned short rx_byte_err_cnt_clr : 1;
        unsigned short ls_byte_err_rpt_en : 1;
        unsigned short fs_byte_err_rpt_en : 1;
        unsigned short hs_byte_err_rpt_en : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_rx_byte_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_rx_byte_err_cnt_END (11)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_rx_byte_err_cnt_clr_START (12)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_rx_byte_err_cnt_clr_END (12)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_ls_byte_err_rpt_en_START (13)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_ls_byte_err_rpt_en_END (13)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_fs_byte_err_rpt_en_START (14)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_fs_byte_err_rpt_en_END (14)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_hs_byte_err_rpt_en_START (15)
#define SOC_MMC0_HiUSB2RV100_RX_BYTE_CHK_CFG_hs_byte_err_rpt_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short fs_max_pktsize : 11;
        unsigned short rx_fs_reduce_end_delay : 1;
        unsigned short rx_ls_reduce_end_delay : 1;
        unsigned short byte_err_cfg : 1;
        unsigned short reserved : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_fs_max_pktsize_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_fs_max_pktsize_END (10)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_rx_fs_reduce_end_delay_START (11)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_rx_fs_reduce_end_delay_END (11)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_rx_ls_reduce_end_delay_START (12)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_rx_ls_reduce_end_delay_END (12)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_byte_err_cfg_START (13)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG0_byte_err_cfg_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_max_pktsize : 11;
        unsigned short reserved : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG1_hs_max_pktsize_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG1_hs_max_pktsize_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_fsls_pktgap_err_cnt : 8;
        unsigned short rx_fsls_pktgap_err_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_rx_fsls_pktgap_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_rx_fsls_pktgap_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_rx_fsls_pktgap_err_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_RX_FSLS_PKTGAP_CNT_rx_fsls_pktgap_err_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_pktsize_err_cnt : 8;
        unsigned short rx_pktsize_err_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_rx_pktsize_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_rx_pktsize_err_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_rx_pktsize_err_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_ERR_CNT_rx_pktsize_err_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short rx_err_cnt : 12;
        unsigned short rx_err_cnt_clr : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_rx_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_rx_err_cnt_END (11)
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_rx_err_cnt_clr_START (12)
#define SOC_MMC0_HiUSB2RV100_RX_ERR_CNT_rx_err_cnt_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short ls_max_pktsize : 11;
        unsigned short reserved : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG2_ls_max_pktsize_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_PKTSIZE_CHK_CFG2_ls_max_pktsize_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_bad_pid_cnt : 8;
        unsigned short tx_bad_pid_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_tx_bad_pid_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_tx_bad_pid_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_tx_bad_pid_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG0_tx_bad_pid_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_bad_pid_value : 8;
        unsigned short reserved : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG1_tx_bad_pid_value_START (0)
#define SOC_MMC0_HiUSB2RV100_TX_PID_CHK_CFG1_tx_bad_pid_value_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_err_rpt_cnt : 8;
        unsigned short tx_err_rpt_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_tx_err_rpt_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_tx_err_rpt_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_tx_err_rpt_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_TX_ERR_RPT_CNT_tx_err_rpt_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_linestate_filter_sel : 2;
        unsigned short hs_linestate_delay_sel : 1;
        unsigned short hs_sync_det : 6;
        unsigned short fls_sync_det : 6;
        unsigned short transfer_flag : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_linestate_filter_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_linestate_filter_sel_END (1)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_linestate_delay_sel_START (2)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_linestate_delay_sel_END (2)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_sync_det_START (3)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_hs_sync_det_END (8)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_fls_sync_det_START (9)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_fls_sync_det_END (14)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_transfer_flag_START (15)
#define SOC_MMC0_HiUSB2RV100_SIG_PROC_CFG_transfer_flag_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short d_pll_lock : 1;
        unsigned short lock_det_sel : 1;
        unsigned short reserved : 14;
    } reg;
} SOC_MMC0_HiUSB2RV100_CKDT_STS_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_d_pll_lock_START (0)
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_d_pll_lock_END (0)
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_lock_det_sel_START (1)
#define SOC_MMC0_HiUSB2RV100_CKDT_STS_lock_det_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_ckdt_upper_cnt : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CKDT_CFG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG0_hs_ckdt_upper_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG0_hs_ckdt_upper_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_ckdt_lower_cnt : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CKDT_CFG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG1_hs_ckdt_lower_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG1_hs_ckdt_lower_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short ref_ck_cnt : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CKDT_CFG2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG2_ref_ck_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_CKDT_CFG2_ref_ck_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short lock_det_n : 13;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG0_lock_det_n_START (0)
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG0_lock_det_n_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short lock_det_m : 7;
        unsigned short reserved : 9;
    } reg;
} SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG1_lock_det_m_START (0)
#define SOC_MMC0_HiUSB2RV100_LOCK_DET_CFG1_lock_det_m_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_en : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL0_bist_en_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL0_bist_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_cycle : 11;
        unsigned short bist_mode : 1;
        unsigned short bist_opmode : 2;
        unsigned short bist_speed : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_cycle_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_cycle_END (10)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_mode_START (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_mode_END (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_opmode_START (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_opmode_END (13)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_speed_START (14)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL1_bist_speed_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_rx_pktlen : 11;
        unsigned short bist_result_mode : 1;
        unsigned short bist_repeat : 1;
        unsigned short bist_timeout_en : 1;
        unsigned short bist_testburnin : 1;
        unsigned short bist_loopbackenb : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_rx_pktlen_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_rx_pktlen_END (10)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_result_mode_START (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_result_mode_END (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_repeat_START (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_repeat_END (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_timeout_en_START (13)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_timeout_en_END (13)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_testburnin_START (14)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_testburnin_END (14)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_loopbackenb_START (15)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL2_bist_loopbackenb_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_err_data_cycle : 11;
        unsigned short bist_controller_en : 1;
        unsigned short reserved : 4;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL3_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_bist_err_data_cycle_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_bist_err_data_cycle_END (10)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_bist_controller_en_START (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL3_bist_controller_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_err_data : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL4_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL4_bist_err_data_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL4_bist_err_data_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_finish : 1;
        unsigned short reserved_0 : 1;
        unsigned short bist_result : 1;
        unsigned short bist_rxerr : 1;
        unsigned short bist_packet_chk_err : 1;
        unsigned short bist_data_chk_err : 1;
        unsigned short bist_active : 1;
        unsigned short reserved_1 : 9;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL5_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_finish_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_finish_END (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_result_START (2)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_result_END (2)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_rxerr_START (3)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_rxerr_END (3)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_packet_chk_err_START (4)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_packet_chk_err_END (4)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_data_chk_err_START (5)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_data_chk_err_END (5)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_active_START (6)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL5_bist_active_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_patt_sel : 5;
        unsigned short bist_databus : 1;
        unsigned short prbs_err_inj_position : 4;
        unsigned short reserved_0 : 1;
        unsigned short prbs_err_inj_once : 1;
        unsigned short prbs_err_inj_en : 1;
        unsigned short reserved_1 : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL6_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_patt_sel_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_patt_sel_END (4)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_bist_databus_START (5)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_bist_databus_END (5)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_position_START (6)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_position_END (9)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_once_START (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_once_END (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_en_START (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL6_prbs_err_inj_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_cust_patt_0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL7_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL7_prbs_cust_patt_0_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL7_prbs_cust_patt_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_cust_patt_1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL8_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL8_prbs_cust_patt_1_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL8_prbs_cust_patt_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_cust_patt_2 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL9_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL9_prbs_cust_patt_2_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL9_prbs_cust_patt_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_cust_patt_3 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL10_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL10_prbs_cust_patt_3_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL10_prbs_cust_patt_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_chk_mask : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL11_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL11_prbs_chk_mask_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL11_prbs_chk_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_burnin_code : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL12_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL12_prbs_burnin_code_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL12_prbs_burnin_code_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_err_cnt : 11;
        unsigned short prbs_err_pulse : 1;
        unsigned short prbs_err_state : 1;
        unsigned short prbs_read_strobe : 1;
        unsigned short prbs_chk_mode : 1;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL13_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_cnt_END (10)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_pulse_START (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_pulse_END (11)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_state_START (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_err_state_END (12)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_read_strobe_START (13)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_read_strobe_END (13)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_chk_mode_START (14)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL13_prbs_chk_mode_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short prbs_err_curr : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_CTRL14_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL14_prbs_err_curr_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_CTRL14_prbs_err_curr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short bist_err_loop : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_BIST_DEBUG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_BIST_DEBUG_bist_err_loop_START (0)
#define SOC_MMC0_HiUSB2RV100_BIST_DEBUG_bist_err_loop_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short test_bus_cfg : 8;
        unsigned short reserved : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_IO_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_IO_CFG_test_bus_cfg_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_IO_CFG_test_bus_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_sm_cur_st_rcd0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD0_tx_sm_cur_st_rcd0_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD0_tx_sm_cur_st_rcd0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short tx_sm_cur_st_rcd1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD1_tx_sm_cur_st_rcd1_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_TX_SM_RCD1_tx_sm_cur_st_rcd1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_rx_sm_rcd0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD0_dbg_rx_sm_rcd0_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD0_dbg_rx_sm_rcd0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_rx_sm_rcd1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD1_dbg_rx_sm_rcd1_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_RX_SM_RCD1_dbg_rx_sm_rcd1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_opmode_rcd : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_OPMODE_RCD_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_OPMODE_RCD_dbg_opmode_rcd_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_OPMODE_RCD_dbg_opmode_rcd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_xcvrselect_rcd : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_XCVRSELECT_RCD_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_XCVRSELECT_RCD_dbg_xcvrselect_rcd_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_XCVRSELECT_RCD_dbg_xcvrselect_rcd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_disconnect_rcd : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_DISCONNECT_RCD_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_DISCONNECT_RCD_dbg_disconnect_rcd_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_DISCONNECT_RCD_dbg_disconnect_rcd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_termselect_rcd : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_TERMSELECT_RCD_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_TERMSELECT_RCD_dbg_termselect_rcd_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_TERMSELECT_RCD_dbg_termselect_rcd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_linestate_j_rcd : 8;
        unsigned short dbg_linestate_k_rcd : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_dbg_linestate_j_rcd_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_dbg_linestate_j_rcd_END (7)
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_dbg_linestate_k_rcd_START (8)
#define SOC_MMC0_HiUSB2RV100_DBG_LINESTATE_dbg_linestate_k_rcd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short pll_lock_tog_cnt : 4;
        unsigned short dbg_sof_cnt : 4;
        unsigned short pll_lock_tog_cnt_clr : 1;
        unsigned short reserved : 7;
    } reg;
} SOC_MMC0_HiUSB2RV100_DBG_PLL_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_pll_lock_tog_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_pll_lock_tog_cnt_END (3)
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_dbg_sof_cnt_START (4)
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_dbg_sof_cnt_END (7)
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_pll_lock_tog_cnt_clr_START (8)
#define SOC_MMC0_HiUSB2RV100_DBG_PLL_pll_lock_tog_cnt_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short filter_length : 13;
        unsigned short filter_en : 1;
        unsigned short reserved : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_filter_length_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_filter_length_END (12)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_filter_en_START (13)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER0_filter_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short filter_th : 8;
        unsigned short reserved : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER1_filter_th_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FILTER1_filter_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_cfg_rough3 : 4;
        unsigned short cdr_cfg_rough2 : 4;
        unsigned short cdr_cfg_rough1 : 4;
        unsigned short cdr_cfg_rough0 : 4;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough3_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough3_END (3)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough2_START (4)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough2_END (7)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough1_START (8)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough1_END (11)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough0_START (12)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_ROUGH_cdr_cfg_rough0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_edge_throd : 4;
        unsigned short cdr_edge_action : 1;
        unsigned short cdr_edge_abn : 1;
        unsigned short cdr_edge_abn_clr : 1;
        unsigned short reserved : 9;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_throd_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_throd_END (3)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_action_START (4)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_action_END (4)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_abn_START (5)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_abn_END (5)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_abn_clr_START (6)
#define SOC_MMC0_HiUSB2RV100_CDR_CFG_FINE_cdr_edge_abn_clr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_fine_zero_cfg : 13;
        unsigned short cdr_unlock_abn : 1;
        unsigned short cdr_unlock_abn_clr : 1;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_fine_zero_cfg_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_fine_zero_cfg_END (12)
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_unlock_abn_START (13)
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_unlock_abn_END (13)
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_unlock_abn_clr_START (14)
#define SOC_MMC0_HiUSB2RV100_CDR_ZERRO_CFG_cdr_unlock_abn_clr_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_data_err_throd : 13;
        unsigned short cdr_data_err : 1;
        unsigned short cdr_data_err_clr : 1;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_throd_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_throd_END (12)
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_START (13)
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_END (13)
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_clr_START (14)
#define SOC_MMC0_HiUSB2RV100_CDR_DATA_ERR_cdr_data_err_clr_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_lut_err_cnt : 5;
        unsigned short cdr_lut_err_cnt_clr : 1;
        unsigned short cdr_zero_err_cnt : 5;
        unsigned short cdr_zero_err_cnt_clr : 1;
        unsigned short reserved : 4;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_lut_err_cnt_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_lut_err_cnt_END (4)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_lut_err_cnt_clr_START (5)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_lut_err_cnt_clr_END (5)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_zero_err_cnt_START (6)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_zero_err_cnt_END (10)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_zero_err_cnt_clr_START (11)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL0_cdr_zero_err_cnt_clr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short cdr_unlock_throd : 5;
        unsigned short cdr_sync_err : 1;
        unsigned short cdr_sync_err_clr : 1;
        unsigned short cdr_adj_err_cnt : 5;
        unsigned short cdr_adj_err_cnt_clr : 1;
        unsigned short reserved : 3;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_unlock_throd_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_unlock_throd_END (4)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_sync_err_START (5)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_sync_err_END (5)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_sync_err_clr_START (6)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_sync_err_clr_END (6)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_adj_err_cnt_START (7)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_adj_err_cnt_END (11)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_adj_err_cnt_clr_START (12)
#define SOC_MMC0_HiUSB2RV100_CDR_ABNORMAL1_cdr_adj_err_cnt_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_vld_cnt_cfg : 13;
        unsigned short cdr_dbg_en : 1;
        unsigned short reserved : 2;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_dbg_vld_cnt_cfg_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_dbg_vld_cnt_cfg_END (12)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_cdr_dbg_en_START (13)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG_CNT_cdr_dbg_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_rd_addr : 5;
        unsigned short dbg_wr_addr : 6;
        unsigned short dbg_drop_acc_phase : 5;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_rd_addr_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_rd_addr_END (4)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_wr_addr_START (5)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_wr_addr_END (10)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_drop_acc_phase_START (11)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG0_dbg_drop_acc_phase_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_optr : 7;
        unsigned short dbg_iptr : 3;
        unsigned short dbg_insert_acc_phase : 5;
        unsigned short reserved : 1;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_optr_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_optr_END (6)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_iptr_START (7)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_iptr_END (9)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_insert_acc_phase_START (10)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG1_dbg_insert_acc_phase_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_actual_phase : 7;
        unsigned short optr_met_cfg : 1;
        unsigned short reserved : 8;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_dbg_actual_phase_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_dbg_actual_phase_END (6)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_optr_met_cfg_START (7)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG2_optr_met_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_fine_data : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG3_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG3_dbg_fine_data_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG3_dbg_fine_data_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer0 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG4_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG4_dbg_buffer0_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG4_dbg_buffer0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer1 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG5_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG5_dbg_buffer1_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG5_dbg_buffer1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer2 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG6_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG6_dbg_buffer2_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG6_dbg_buffer2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer3 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG7_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG7_dbg_buffer3_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG7_dbg_buffer3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer4 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG8_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG8_dbg_buffer4_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG8_dbg_buffer4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short dbg_buffer5 : 16;
    } reg;
} SOC_MMC0_HiUSB2RV100_CDR_DEBUG9_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG9_dbg_buffer5_START (0)
#define SOC_MMC0_HiUSB2RV100_CDR_DEBUG9_dbg_buffer5_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short hs_toggle_timer_cfg : 4;
        unsigned short hs_toggle_cnt_cfg : 4;
        unsigned short fs_toggle_timer_cfg : 4;
        unsigned short fs_toggle_cnt_cfg : 4;
    } reg;
} SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_hs_toggle_timer_cfg_START (0)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_hs_toggle_timer_cfg_END (3)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_hs_toggle_cnt_cfg_START (4)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_hs_toggle_cnt_cfg_END (7)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_fs_toggle_timer_cfg_START (8)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_fs_toggle_timer_cfg_END (11)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_fs_toggle_cnt_cfg_START (12)
#define SOC_MMC0_HiUSB2RV100_RX_DBG_CFG_fs_toggle_cnt_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned short value;
    struct
    {
        unsigned short clk_dbg_sel0 : 3;
        unsigned short clk_dbg_sel1 : 3;
        unsigned short reserved : 10;
    } reg;
} SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_UNION;
#endif
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_clk_dbg_sel0_START (0)
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_clk_dbg_sel0_END (2)
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_clk_dbg_sel1_START (3)
#define SOC_MMC0_HiUSB2RV100_CLK_DBG_CFG_clk_dbg_sel1_END (5)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
