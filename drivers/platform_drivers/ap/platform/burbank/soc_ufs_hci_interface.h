#ifndef __SOC_UFS_HCI_INTERFACE_H__
#define __SOC_UFS_HCI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_HCI_UFS_CAP_ADDR(base) ((base) + (0x0000UL))
#define SOC_UFS_HCI_UFS_VER_ADDR(base) ((base) + (0x0008UL))
#define SOC_UFS_HCI_UFS_HCPID_ADDR(base) ((base) + (0x0010UL))
#define SOC_UFS_HCI_UFS_HCMID_ADDR(base) ((base) + (0x0014UL))
#define SOC_UFS_HCI_UFS_AHIT_ADDR(base) ((base) + (0x0018UL))
#define SOC_UFS_HCI_UFS_IS_ADDR(base) ((base) + (0x0020UL))
#define SOC_UFS_HCI_UFS_IE_ADDR(base) ((base) + (0x0024UL))
#define SOC_UFS_HCI_UFS_HCS_ADDR(base) ((base) + (0x0030UL))
#define SOC_UFS_HCI_UFS_HCE_ADDR(base) ((base) + (0x0034UL))
#define SOC_UFS_HCI_UFS_UTRIACR_ADDR(base) ((base) + (0x004CUL))
#define SOC_UFS_HCI_UFS_UTPLBA_ADDR(base) ((base) + (0x0050UL))
#define SOC_UFS_HCI_UFS_UTPLBAU_ADDR(base) ((base) + (0x0054UL))
#define SOC_UFS_HCI_UFS_UTRLRSR_ADDR(base) ((base) + (0x0060UL))
#define SOC_UFS_HCI_UFS_UTMRLBA_ADDR(base) ((base) + (0x0070UL))
#define SOC_UFS_HCI_UFS_UTMRLBAU_ADDR(base) ((base) + (0x0074UL))
#define SOC_UFS_HCI_UFS_UTMRLRSR_ADDR(base) ((base) + (0x0080UL))
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_ADDR(base) ((base) + (0x00C0UL))
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_ADDR(base) ((base) + (0x00C4UL))
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_ADDR(base) ((base) + (0x00C8UL))
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_ADDR(base) ((base) + (0x00CCUL))
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_ADDR(base) ((base) + (0x00D0UL))
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_ADDR(base) ((base) + (0x00D4UL))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_ADDR(base) ((base) + (0x00D8UL))
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_ADDR(base) ((base) + (0x00DCUL))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_ADDR(base) ((base) + (0x00E0UL))
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_ADDR(base) ((base) + (0x00E4UL))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_ADDR(base) ((base) + (0x00E8UL))
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_ADDR(base) ((base) + (0x00ECUL))
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_ADDR(base) ((base) + (0x00F4UL))
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_ADDR(base) ((base) + (0x00F8UL))
#define SOC_UFS_HCI_UFS_CCAP_ADDR(base) ((base) + (0x0100UL))
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ADDR(base) ((base) + (0x0104UL))
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ADDR(base) ((base) + (0x0108UL))
#define SOC_UFS_HCI_UFS_IS_INT_SET_ADDR(base) ((base) + (0x010CUL))
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ADDR(base) ((base) + (0x0110UL))
#define SOC_UFS_HCI_UFS_AHIT_EXIT_REQ_ADDR(base) ((base) + (0x0114UL))
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_ADDR(base) ((base) + (0x0118UL))
#define SOC_UFS_HCI_UFS_VS_IE_ADDR(base) ((base) + (0x011CUL))
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_ADDR(base) ((base) + (0x0120UL))
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ADDR(base) ((base) + (0x0130UL))
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ADDR(base) ((base) + (0x0134UL))
#define SOC_UFS_HCI_UFS_H8_STORE_LOAD_DFX_ADDR(base) ((base) + (0x0138UL))
#define SOC_UFS_HCI_UFS_CRG_CLK_GATE_DFX_ADDR(base) ((base) + (0x0378UL))
#define SOC_UFS_HCI_UFS_CFG_IDLE_TIME_THRESHOLD_ADDR(base) ((base) + (0x0390UL))
#define SOC_UFS_HCI_UFS_CFG_RAM_CTRL_ADDR(base) ((base) + (0x039cUL))
#define SOC_UFS_HCI_UFS_CFG_RAM_STATUS_ADDR(base) ((base) + (0x03a0UL))
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ADDR(base) ((base) + (0x003a4UL))
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_ADDR(base) ((base) + (0x003a8UL))
#define SOC_UFS_HCI_UFS_IE_KEY_KDF_EN_ADDR(base) ((base) + (0x03ACUL))
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ADDR(base) ((base) + (0x03b0UL))
#define SOC_UFS_HCI_MPHY_MCU_INIT_DONE_MASH_ADDR(base) ((base) + (0x0414UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_0_ADDR(base,i) ((base) + (0x0500+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_1_ADDR(base,i) ((base) + (0x0504+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_2_ADDR(base,i) ((base) + (0x0508+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_3_ADDR(base,i) ((base) + (0x050C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_4_ADDR(base,i) ((base) + (0x0510+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_5_ADDR(base,i) ((base) + (0x0514+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_6_ADDR(base,i) ((base) + (0x0518+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_7_ADDR(base,i) ((base) + (0x051C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_8_ADDR(base,i) ((base) + (0x0520+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_9_ADDR(base,i) ((base) + (0x0524+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_10_ADDR(base,i) ((base) + (0x0528+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_11_ADDR(base,i) ((base) + (0x052C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_12_ADDR(base,i) ((base) + (0x0530+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_13_ADDR(base,i) ((base) + (0x0534+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_14_ADDR(base,i) ((base) + (0x0538+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_15_ADDR(base,i) ((base) + (0x053C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_ADDR(base,i) ((base) + (0x0540+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_17_ADDR(base,i) ((base) + (0x0544+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_18_ADDR(base,i) ((base) + (0x0548+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_19_ADDR(base,i) ((base) + (0x054C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_20_ADDR(base,i) ((base) + (0x0550+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_21_ADDR(base,i) ((base) + (0x0554+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_22_ADDR(base,i) ((base) + (0x0558+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_23_ADDR(base,i) ((base) + (0x055C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_24_ADDR(base,i) ((base) + (0x0560+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_25_ADDR(base,i) ((base) + (0x0564+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_26_ADDR(base,i) ((base) + (0x0568+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_27_ADDR(base,i) ((base) + (0x056C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_28_ADDR(base,i) ((base) + (0x0570+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_29_ADDR(base,i) ((base) + (0x0574+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_30_ADDR(base,i) ((base) + (0x0578+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_31_ADDR(base,i) ((base) + (0x057C+(i)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_IS_ADDR(base,cn) ((base) + (0x2000+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_IE_ADDR(base,cn) ((base) + (0x2004+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ADDR(base,cn) ((base) + (0x2008+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_HCS_CORE_ADDR(base,cn) ((base) + (0x200C+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_ADDR(base,cn) ((base) + (0x2010+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_UTRLRSR_ADDR(base,cn) ((base) + (0x201C+(cn)*0x80UL))
#else
#define SOC_UFS_HCI_UFS_CAP_ADDR(base) ((base) + (0x0000))
#define SOC_UFS_HCI_UFS_VER_ADDR(base) ((base) + (0x0008))
#define SOC_UFS_HCI_UFS_HCPID_ADDR(base) ((base) + (0x0010))
#define SOC_UFS_HCI_UFS_HCMID_ADDR(base) ((base) + (0x0014))
#define SOC_UFS_HCI_UFS_AHIT_ADDR(base) ((base) + (0x0018))
#define SOC_UFS_HCI_UFS_IS_ADDR(base) ((base) + (0x0020))
#define SOC_UFS_HCI_UFS_IE_ADDR(base) ((base) + (0x0024))
#define SOC_UFS_HCI_UFS_HCS_ADDR(base) ((base) + (0x0030))
#define SOC_UFS_HCI_UFS_HCE_ADDR(base) ((base) + (0x0034))
#define SOC_UFS_HCI_UFS_UTRIACR_ADDR(base) ((base) + (0x004C))
#define SOC_UFS_HCI_UFS_UTPLBA_ADDR(base) ((base) + (0x0050))
#define SOC_UFS_HCI_UFS_UTPLBAU_ADDR(base) ((base) + (0x0054))
#define SOC_UFS_HCI_UFS_UTRLRSR_ADDR(base) ((base) + (0x0060))
#define SOC_UFS_HCI_UFS_UTMRLBA_ADDR(base) ((base) + (0x0070))
#define SOC_UFS_HCI_UFS_UTMRLBAU_ADDR(base) ((base) + (0x0074))
#define SOC_UFS_HCI_UFS_UTMRLRSR_ADDR(base) ((base) + (0x0080))
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_ADDR(base) ((base) + (0x00C0))
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_ADDR(base) ((base) + (0x00C4))
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_ADDR(base) ((base) + (0x00C8))
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_ADDR(base) ((base) + (0x00CC))
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_ADDR(base) ((base) + (0x00D0))
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_ADDR(base) ((base) + (0x00D4))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_ADDR(base) ((base) + (0x00D8))
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_ADDR(base) ((base) + (0x00DC))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_ADDR(base) ((base) + (0x00E0))
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_ADDR(base) ((base) + (0x00E4))
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_ADDR(base) ((base) + (0x00E8))
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_ADDR(base) ((base) + (0x00EC))
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_ADDR(base) ((base) + (0x00F4))
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_ADDR(base) ((base) + (0x00F8))
#define SOC_UFS_HCI_UFS_CCAP_ADDR(base) ((base) + (0x0100))
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ADDR(base) ((base) + (0x0104))
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ADDR(base) ((base) + (0x0108))
#define SOC_UFS_HCI_UFS_IS_INT_SET_ADDR(base) ((base) + (0x010C))
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ADDR(base) ((base) + (0x0110))
#define SOC_UFS_HCI_UFS_AHIT_EXIT_REQ_ADDR(base) ((base) + (0x0114))
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_ADDR(base) ((base) + (0x0118))
#define SOC_UFS_HCI_UFS_VS_IE_ADDR(base) ((base) + (0x011C))
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_ADDR(base) ((base) + (0x0120))
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ADDR(base) ((base) + (0x0130))
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ADDR(base) ((base) + (0x0134))
#define SOC_UFS_HCI_UFS_H8_STORE_LOAD_DFX_ADDR(base) ((base) + (0x0138))
#define SOC_UFS_HCI_UFS_CRG_CLK_GATE_DFX_ADDR(base) ((base) + (0x0378))
#define SOC_UFS_HCI_UFS_CFG_IDLE_TIME_THRESHOLD_ADDR(base) ((base) + (0x0390))
#define SOC_UFS_HCI_UFS_CFG_RAM_CTRL_ADDR(base) ((base) + (0x039c))
#define SOC_UFS_HCI_UFS_CFG_RAM_STATUS_ADDR(base) ((base) + (0x03a0))
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ADDR(base) ((base) + (0x003a4))
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_ADDR(base) ((base) + (0x003a8))
#define SOC_UFS_HCI_UFS_IE_KEY_KDF_EN_ADDR(base) ((base) + (0x03AC))
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ADDR(base) ((base) + (0x03b0))
#define SOC_UFS_HCI_MPHY_MCU_INIT_DONE_MASH_ADDR(base) ((base) + (0x0414))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_0_ADDR(base,i) ((base) + (0x0500+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_1_ADDR(base,i) ((base) + (0x0504+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_2_ADDR(base,i) ((base) + (0x0508+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_3_ADDR(base,i) ((base) + (0x050C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_4_ADDR(base,i) ((base) + (0x0510+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_5_ADDR(base,i) ((base) + (0x0514+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_6_ADDR(base,i) ((base) + (0x0518+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_7_ADDR(base,i) ((base) + (0x051C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_8_ADDR(base,i) ((base) + (0x0520+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_9_ADDR(base,i) ((base) + (0x0524+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_10_ADDR(base,i) ((base) + (0x0528+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_11_ADDR(base,i) ((base) + (0x052C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_12_ADDR(base,i) ((base) + (0x0530+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_13_ADDR(base,i) ((base) + (0x0534+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_14_ADDR(base,i) ((base) + (0x0538+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_15_ADDR(base,i) ((base) + (0x053C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_ADDR(base,i) ((base) + (0x0540+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_17_ADDR(base,i) ((base) + (0x0544+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_18_ADDR(base,i) ((base) + (0x0548+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_19_ADDR(base,i) ((base) + (0x054C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_20_ADDR(base,i) ((base) + (0x0550+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_21_ADDR(base,i) ((base) + (0x0554+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_22_ADDR(base,i) ((base) + (0x0558+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_23_ADDR(base,i) ((base) + (0x055C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_24_ADDR(base,i) ((base) + (0x0560+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_25_ADDR(base,i) ((base) + (0x0564+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_26_ADDR(base,i) ((base) + (0x0568+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_27_ADDR(base,i) ((base) + (0x056C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_28_ADDR(base,i) ((base) + (0x0570+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_29_ADDR(base,i) ((base) + (0x0574+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_30_ADDR(base,i) ((base) + (0x0578+(i)*0x80))
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_31_ADDR(base,i) ((base) + (0x057C+(i)*0x80))
#define SOC_UFS_HCI_UFS_CORE_IS_ADDR(base,cn) ((base) + (0x2000+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_IE_ADDR(base,cn) ((base) + (0x2004+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ADDR(base,cn) ((base) + (0x2008+(cn)*0x80))
#define SOC_UFS_HCI_UFS_HCS_CORE_ADDR(base,cn) ((base) + (0x200C+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_ADDR(base,cn) ((base) + (0x2010+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_UTRLRSR_ADDR(base,cn) ((base) + (0x201C+(cn)*0x80))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_HCI_UFS_UECPA_ADDR(base) ((base) + (0x0038UL))
#define SOC_UFS_HCI_UFS_UECDL_ADDR(base) ((base) + (0x003CUL))
#define SOC_UFS_HCI_UFS_UECN_ADDR(base) ((base) + (0x0040UL))
#define SOC_UFS_HCI_UFS_UECT_ADDR(base) ((base) + (0x0044UL))
#define SOC_UFS_HCI_UFS_UECDME_ADDR(base) ((base) + (0x0048UL))
#define SOC_UFS_HCI_UFS_UTRLDBR_ADDR(base) ((base) + (0x0058UL))
#define SOC_UFS_HCI_UFS_UTRLCLR_ADDR(base) ((base) + (0x005CUL))
#define SOC_UFS_HCI_UFS_UTRLCNR_ADDR(base) ((base) + (0x0064UL))
#define SOC_UFS_HCI_UFS_UTMRLDBR_ADDR(base) ((base) + (0x0078UL))
#define SOC_UFS_HCI_UFS_UTMRLCLR_ADDR(base) ((base) + (0x007CUL))
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_ADDR(base) ((base) + (0x0200UL))
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_ADDR(base) ((base) + (0x0204UL))
#define SOC_UFS_HCI_UFS_TR_TIMEOUT_STATUS_ADDR(base) ((base) + (0x0250UL))
#define SOC_UFS_HCI_UFS_VS_IS_ADDR(base) ((base) + (0x0254UL))
#define SOC_UFS_HCI_UFS_VS_IS_SET_ADDR(base) ((base) + (0x0258UL))
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_ADDR(base) ((base) + (0x025CUL))
#define SOC_UFS_HCI_UFS_DMA1_FIFO_CTRL_ERR_STATUS_ADDR(base) ((base) + (0x0260UL))
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_ADDR(base) ((base) + (0x0264UL))
#define SOC_UFS_HCI_UFS_UTR_OTSD_DBR_DFX_ADDR(base) ((base) + (0x0268UL))
#define SOC_UFS_HCI_UFS_UTMR_OTSD_DBR_DFX_ADDR(base) ((base) + (0x026CUL))
#define SOC_UFS_HCI_UFS_TMRP_DFX0_ADDR(base) ((base) + (0x0270UL))
#define SOC_UFS_HCI_UFS_TMRP_DFX1_ADDR(base) ((base) + (0x0274UL))
#define SOC_UFS_HCI_UFS_TMRP_DFX2_ADDR(base) ((base) + (0x0278UL))
#define SOC_UFS_HCI_UFS_PRDT_DFX0_ADDR(base) ((base) + (0x027CUL))
#define SOC_UFS_HCI_UFS_PRDT_DFX1_ADDR(base) ((base) + (0x0280UL))
#define SOC_UFS_HCI_UFS_PRDT_DFX2_ADDR(base) ((base) + (0x0284UL))
#define SOC_UFS_HCI_UFS_DMA0_DFX0_ADDR(base) ((base) + (0x0288UL))
#define SOC_UFS_HCI_UFS_DMA0_DFX1_ADDR(base) ((base) + (0x028CUL))
#define SOC_UFS_HCI_UFS_TRP_DFX0_ADDR(base) ((base) + (0x0290UL))
#define SOC_UFS_HCI_UFS_TRP_DFX1_ADDR(base) ((base) + (0x0294UL))
#define SOC_UFS_HCI_UFS_TRP_DFX2_ADDR(base) ((base) + (0x0298UL))
#define SOC_UFS_HCI_UFS_TRP_DFX3_ADDR(base) ((base) + (0x029CUL))
#define SOC_UFS_HCI_UFS_TRP_DFX4_ADDR(base) ((base) + (0x02A0UL))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX0_ADDR(base) ((base) + (0x02B0UL))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX1_ADDR(base) ((base) + (0x02B4UL))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX2_ADDR(base) ((base) + (0x02B8UL))
#define SOC_UFS_HCI_UFS_UPIU_SEND_NUM_ADDR(base) ((base) + (0x02BCUL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX0_ADDR(base) ((base) + (0x02C0UL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX1_ADDR(base) ((base) + (0x02C4UL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX2_ADDR(base) ((base) + (0x02C8UL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX3_ADDR(base) ((base) + (0x02CCUL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX4_ADDR(base) ((base) + (0x02D0UL))
#define SOC_UFS_HCI_UFS_UTP_RX_NORM_NUM_ADDR(base) ((base) + (0x02D4UL))
#define SOC_UFS_HCI_UFS_UTP_RX_DISC_NUM_ADDR(base) ((base) + (0x02D8UL))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX5_ADDR(base) ((base) + (0x02DCUL))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX0_ADDR(base) ((base) + (0x02E0UL))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX1_ADDR(base) ((base) + (0x02E4UL))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX2_ADDR(base) ((base) + (0x02E8UL))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX3_ADDR(base) ((base) + (0x02ECUL))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX0_ADDR(base) ((base) + (0x02F0UL))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX1_ADDR(base) ((base) + (0x02F4UL))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX2_ADDR(base) ((base) + (0x02F8UL))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX3_ADDR(base) ((base) + (0x02FCUL))
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0300UL))
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x0304UL))
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0308UL))
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x030CUL))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_DFX_CTRL_ADDR(base) ((base) + (0x0310UL))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_ADDR(base) ((base) + (0x0314UL))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_ACC_CNT_ADDR(base) ((base) + (0x0318UL))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_LOW_ADDR(base) ((base) + (0x031CUL))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_HIG_ADDR(base) ((base) + (0x0320UL))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_DFX_CTRL_ADDR(base) ((base) + (0x0324UL))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_ADDR(base) ((base) + (0x0328UL))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_ACC_CNT_ADDR(base) ((base) + (0x032CUL))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_LOW_ADDR(base) ((base) + (0x0330UL))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_HIG_ADDR(base) ((base) + (0x0334UL))
#define SOC_UFS_HCI_UFS_AXI_MST_WID_OUT_ADDR(base) ((base) + (0x0338UL))
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0340UL))
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x0344UL))
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0348UL))
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x034CUL))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_ADDR(base) ((base) + (0x0350UL))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_REQ_DFX_ADDR(base) ((base) + (0x0354UL))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0358UL))
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_ADDR(base) ((base) + (0x035CUL))
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_ADDR(base) ((base) + (0x0360UL))
#define SOC_UFS_HCI_UFS_FW_WT_TRP_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0364UL))
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0368UL))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX4_ADDR(base) ((base) + (0x0370UL))
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_ADDR(base) ((base) + (0x0374UL))
#define SOC_UFS_HCI_TRP_MCORE_ARB_DFX_ADDR(base) ((base) + (0x03b4UL))
#define SOC_UFS_HCI_TRP_MARB_DBR_DFX_ADDR(base) ((base) + (0x03b8UL))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX0_ADDR(base) ((base) + (0x03bcUL))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX1_ADDR(base) ((base) + (0x03c0UL))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX2_ADDR(base) ((base) + (0x03c4UL))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX0_ADDR(base) ((base) + (0x03c8UL))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX1_ADDR(base) ((base) + (0x03ccUL))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX2_ADDR(base) ((base) + (0x03d0UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_ADDR(base) ((base) + (0x03d4UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_ADDR(base) ((base) + (0x03d8UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_ADDR(base) ((base) + (0x03dcUL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_ADDR(base) ((base) + (0x03e0UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_ADDR(base) ((base) + (0x03e4UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_ADDR(base) ((base) + (0x03e8UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_ADDR(base) ((base) + (0x03ecUL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_ADDR(base) ((base) + (0x03f0UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_ADDR(base) ((base) + (0x03f4UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_ADDR(base) ((base) + (0x03f8UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_ADDR(base) ((base) + (0x03fcUL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_ADDR(base) ((base) + (0x0400UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_ADDR(base) ((base) + (0x0404UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_ADDR(base) ((base) + (0x0408UL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_ADDR(base) ((base) + (0x040cUL))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_ADDR(base) ((base) + (0x0410UL))
#define SOC_UFS_HCI_UFS_CORE_UTRLDBR_ADDR(base,cn) ((base) + (0x2014+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_UTRLCLR_ADDR(base,cn) ((base) + (0x2018+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_UTRLCNR_ADDR(base,cn) ((base) + (0x2020+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_TR_TIMEOUT_STATUS_ADDR(base,cn) ((base) + (0x2024+(cn)*0x80UL))
#define SOC_UFS_HCI_UFS_CORE_UTR_OTSD_DBR_DFX_ADDR(base,cn) ((base) + (0x2028+(cn)*0x80UL))
#else
#define SOC_UFS_HCI_UFS_UECPA_ADDR(base) ((base) + (0x0038))
#define SOC_UFS_HCI_UFS_UECDL_ADDR(base) ((base) + (0x003C))
#define SOC_UFS_HCI_UFS_UECN_ADDR(base) ((base) + (0x0040))
#define SOC_UFS_HCI_UFS_UECT_ADDR(base) ((base) + (0x0044))
#define SOC_UFS_HCI_UFS_UECDME_ADDR(base) ((base) + (0x0048))
#define SOC_UFS_HCI_UFS_UTRLDBR_ADDR(base) ((base) + (0x0058))
#define SOC_UFS_HCI_UFS_UTRLCLR_ADDR(base) ((base) + (0x005C))
#define SOC_UFS_HCI_UFS_UTRLCNR_ADDR(base) ((base) + (0x0064))
#define SOC_UFS_HCI_UFS_UTMRLDBR_ADDR(base) ((base) + (0x0078))
#define SOC_UFS_HCI_UFS_UTMRLCLR_ADDR(base) ((base) + (0x007C))
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_ADDR(base) ((base) + (0x0200))
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_ADDR(base) ((base) + (0x0204))
#define SOC_UFS_HCI_UFS_TR_TIMEOUT_STATUS_ADDR(base) ((base) + (0x0250))
#define SOC_UFS_HCI_UFS_VS_IS_ADDR(base) ((base) + (0x0254))
#define SOC_UFS_HCI_UFS_VS_IS_SET_ADDR(base) ((base) + (0x0258))
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_ADDR(base) ((base) + (0x025C))
#define SOC_UFS_HCI_UFS_DMA1_FIFO_CTRL_ERR_STATUS_ADDR(base) ((base) + (0x0260))
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_ADDR(base) ((base) + (0x0264))
#define SOC_UFS_HCI_UFS_UTR_OTSD_DBR_DFX_ADDR(base) ((base) + (0x0268))
#define SOC_UFS_HCI_UFS_UTMR_OTSD_DBR_DFX_ADDR(base) ((base) + (0x026C))
#define SOC_UFS_HCI_UFS_TMRP_DFX0_ADDR(base) ((base) + (0x0270))
#define SOC_UFS_HCI_UFS_TMRP_DFX1_ADDR(base) ((base) + (0x0274))
#define SOC_UFS_HCI_UFS_TMRP_DFX2_ADDR(base) ((base) + (0x0278))
#define SOC_UFS_HCI_UFS_PRDT_DFX0_ADDR(base) ((base) + (0x027C))
#define SOC_UFS_HCI_UFS_PRDT_DFX1_ADDR(base) ((base) + (0x0280))
#define SOC_UFS_HCI_UFS_PRDT_DFX2_ADDR(base) ((base) + (0x0284))
#define SOC_UFS_HCI_UFS_DMA0_DFX0_ADDR(base) ((base) + (0x0288))
#define SOC_UFS_HCI_UFS_DMA0_DFX1_ADDR(base) ((base) + (0x028C))
#define SOC_UFS_HCI_UFS_TRP_DFX0_ADDR(base) ((base) + (0x0290))
#define SOC_UFS_HCI_UFS_TRP_DFX1_ADDR(base) ((base) + (0x0294))
#define SOC_UFS_HCI_UFS_TRP_DFX2_ADDR(base) ((base) + (0x0298))
#define SOC_UFS_HCI_UFS_TRP_DFX3_ADDR(base) ((base) + (0x029C))
#define SOC_UFS_HCI_UFS_TRP_DFX4_ADDR(base) ((base) + (0x02A0))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX0_ADDR(base) ((base) + (0x02B0))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX1_ADDR(base) ((base) + (0x02B4))
#define SOC_UFS_HCI_UFS_UTP_TX_DFX2_ADDR(base) ((base) + (0x02B8))
#define SOC_UFS_HCI_UFS_UPIU_SEND_NUM_ADDR(base) ((base) + (0x02BC))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX0_ADDR(base) ((base) + (0x02C0))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX1_ADDR(base) ((base) + (0x02C4))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX2_ADDR(base) ((base) + (0x02C8))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX3_ADDR(base) ((base) + (0x02CC))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX4_ADDR(base) ((base) + (0x02D0))
#define SOC_UFS_HCI_UFS_UTP_RX_NORM_NUM_ADDR(base) ((base) + (0x02D4))
#define SOC_UFS_HCI_UFS_UTP_RX_DISC_NUM_ADDR(base) ((base) + (0x02D8))
#define SOC_UFS_HCI_UFS_UTP_RX_DFX5_ADDR(base) ((base) + (0x02DC))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX0_ADDR(base) ((base) + (0x02E0))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX1_ADDR(base) ((base) + (0x02E4))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX2_ADDR(base) ((base) + (0x02E8))
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX3_ADDR(base) ((base) + (0x02EC))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX0_ADDR(base) ((base) + (0x02F0))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX1_ADDR(base) ((base) + (0x02F4))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX2_ADDR(base) ((base) + (0x02F8))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX3_ADDR(base) ((base) + (0x02FC))
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0300))
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x0304))
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0308))
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x030C))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_DFX_CTRL_ADDR(base) ((base) + (0x0310))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_ADDR(base) ((base) + (0x0314))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_ACC_CNT_ADDR(base) ((base) + (0x0318))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_LOW_ADDR(base) ((base) + (0x031C))
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_HIG_ADDR(base) ((base) + (0x0320))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_DFX_CTRL_ADDR(base) ((base) + (0x0324))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_ADDR(base) ((base) + (0x0328))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_ACC_CNT_ADDR(base) ((base) + (0x032C))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_LOW_ADDR(base) ((base) + (0x0330))
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_HIG_ADDR(base) ((base) + (0x0334))
#define SOC_UFS_HCI_UFS_AXI_MST_WID_OUT_ADDR(base) ((base) + (0x0338))
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0340))
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x0344))
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + (0x0348))
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + (0x034C))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_ADDR(base) ((base) + (0x0350))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_REQ_DFX_ADDR(base) ((base) + (0x0354))
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0358))
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_ADDR(base) ((base) + (0x035C))
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_ADDR(base) ((base) + (0x0360))
#define SOC_UFS_HCI_UFS_FW_WT_TRP_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0364))
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_DATA_DFX_ADDR(base) ((base) + (0x0368))
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX4_ADDR(base) ((base) + (0x0370))
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_ADDR(base) ((base) + (0x0374))
#define SOC_UFS_HCI_TRP_MCORE_ARB_DFX_ADDR(base) ((base) + (0x03b4))
#define SOC_UFS_HCI_TRP_MARB_DBR_DFX_ADDR(base) ((base) + (0x03b8))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX0_ADDR(base) ((base) + (0x03bc))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX1_ADDR(base) ((base) + (0x03c0))
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX2_ADDR(base) ((base) + (0x03c4))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX0_ADDR(base) ((base) + (0x03c8))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX1_ADDR(base) ((base) + (0x03cc))
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX2_ADDR(base) ((base) + (0x03d0))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_ADDR(base) ((base) + (0x03d4))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_ADDR(base) ((base) + (0x03d8))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_ADDR(base) ((base) + (0x03dc))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_ADDR(base) ((base) + (0x03e0))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_ADDR(base) ((base) + (0x03e4))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_ADDR(base) ((base) + (0x03e8))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_ADDR(base) ((base) + (0x03ec))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_ADDR(base) ((base) + (0x03f0))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_ADDR(base) ((base) + (0x03f4))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_ADDR(base) ((base) + (0x03f8))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_ADDR(base) ((base) + (0x03fc))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_ADDR(base) ((base) + (0x0400))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_ADDR(base) ((base) + (0x0404))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_ADDR(base) ((base) + (0x0408))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_ADDR(base) ((base) + (0x040c))
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_ADDR(base) ((base) + (0x0410))
#define SOC_UFS_HCI_UFS_CORE_UTRLDBR_ADDR(base,cn) ((base) + (0x2014+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_UTRLCLR_ADDR(base,cn) ((base) + (0x2018+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_UTRLCNR_ADDR(base,cn) ((base) + (0x2020+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_TR_TIMEOUT_STATUS_ADDR(base,cn) ((base) + (0x2024+(cn)*0x80))
#define SOC_UFS_HCI_UFS_CORE_UTR_OTSD_DBR_DFX_ADDR(base,cn) ((base) + (0x2028+(cn)*0x80))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_cap_nutrs : 5;
        unsigned int reserved_0 : 3;
        unsigned int ufs_cap_nortt : 8;
        unsigned int ufs_cap_nutmrs : 3;
        unsigned int reserved_1 : 4;
        unsigned int ufs_cap_autoh8 : 1;
        unsigned int ufs_cap_64as : 1;
        unsigned int ufs_cap_oodds : 1;
        unsigned int ufs_cap_uicdmetms : 1;
        unsigned int reserved_2 : 1;
        unsigned int ufs_cap_cs : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_UFS_HCI_UFS_CAP_UNION;
#endif
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nutrs_START (00)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nutrs_END (04)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nortt_START (08)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nortt_END (15)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nutmrs_START (16)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_nutmrs_END (18)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_autoh8_START (23)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_autoh8_END (23)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_64as_START (24)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_64as_END (24)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_oodds_START (25)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_oodds_END (25)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_uicdmetms_START (26)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_uicdmetms_END (26)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_cs_START (28)
#define SOC_UFS_HCI_UFS_CAP_ufs_cap_cs_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_ver_vs : 4;
        unsigned int ufs_ver_mnr : 4;
        unsigned int ufs_ver_mjr : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_VER_UNION;
#endif
#define SOC_UFS_HCI_UFS_VER_ufs_ver_vs_START (00)
#define SOC_UFS_HCI_UFS_VER_ufs_ver_vs_END (03)
#define SOC_UFS_HCI_UFS_VER_ufs_ver_mnr_START (04)
#define SOC_UFS_HCI_UFS_VER_ufs_ver_mnr_END (07)
#define SOC_UFS_HCI_UFS_VER_ufs_ver_mjr_START (08)
#define SOC_UFS_HCI_UFS_VER_ufs_ver_mjr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hcpid : 32;
    } reg;
} SOC_UFS_HCI_UFS_HCPID_UNION;
#endif
#define SOC_UFS_HCI_UFS_HCPID_ufs_hcpid_START (00)
#define SOC_UFS_HCI_UFS_HCPID_ufs_hcpid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hcmid_mic : 8;
        unsigned int ufs_hcmid_bi : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_HCMID_UNION;
#endif
#define SOC_UFS_HCI_UFS_HCMID_ufs_hcmid_mic_START (00)
#define SOC_UFS_HCI_UFS_HCMID_ufs_hcmid_mic_END (07)
#define SOC_UFS_HCI_UFS_HCMID_ufs_hcmid_bi_START (08)
#define SOC_UFS_HCI_UFS_HCMID_ufs_hcmid_bi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_ahit_ah8itv : 10;
        unsigned int ufs_ahit_ts : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_UFS_HCI_UFS_AHIT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AHIT_ufs_ahit_ah8itv_START (00)
#define SOC_UFS_HCI_UFS_AHIT_ufs_ahit_ah8itv_END (09)
#define SOC_UFS_HCI_UFS_AHIT_ufs_ahit_ts_START (10)
#define SOC_UFS_HCI_UFS_AHIT_ufs_ahit_ts_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_is_utrcs : 1;
        unsigned int ufs_is_udepri : 1;
        unsigned int ufs_is_ue : 1;
        unsigned int ufs_is_utms : 1;
        unsigned int ufs_is_upms : 1;
        unsigned int ufs_is_uhxs : 1;
        unsigned int ufs_is_uhes : 1;
        unsigned int ufs_is_ulls : 1;
        unsigned int ufs_is_ulss : 1;
        unsigned int ufs_is_utmrcs : 1;
        unsigned int ufs_is_uccs : 1;
        unsigned int ufs_is_dfes : 1;
        unsigned int ufs_is_utpes : 1;
        unsigned int reserved_0 : 3;
        unsigned int ufs_is_hcfes : 1;
        unsigned int ufs_is_sbfes : 1;
        unsigned int ufs_is_cefes : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_UFS_HCI_UFS_IS_UNION;
#endif
#define SOC_UFS_HCI_UFS_IS_ufs_is_utrcs_START (0)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utrcs_END (0)
#define SOC_UFS_HCI_UFS_IS_ufs_is_udepri_START (1)
#define SOC_UFS_HCI_UFS_IS_ufs_is_udepri_END (1)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ue_START (2)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ue_END (2)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utms_START (3)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utms_END (3)
#define SOC_UFS_HCI_UFS_IS_ufs_is_upms_START (4)
#define SOC_UFS_HCI_UFS_IS_ufs_is_upms_END (4)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uhxs_START (5)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uhxs_END (5)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uhes_START (6)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uhes_END (6)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ulls_START (7)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ulls_END (7)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ulss_START (8)
#define SOC_UFS_HCI_UFS_IS_ufs_is_ulss_END (8)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utmrcs_START (9)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utmrcs_END (9)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uccs_START (10)
#define SOC_UFS_HCI_UFS_IS_ufs_is_uccs_END (10)
#define SOC_UFS_HCI_UFS_IS_ufs_is_dfes_START (11)
#define SOC_UFS_HCI_UFS_IS_ufs_is_dfes_END (11)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utpes_START (12)
#define SOC_UFS_HCI_UFS_IS_ufs_is_utpes_END (12)
#define SOC_UFS_HCI_UFS_IS_ufs_is_hcfes_START (16)
#define SOC_UFS_HCI_UFS_IS_ufs_is_hcfes_END (16)
#define SOC_UFS_HCI_UFS_IS_ufs_is_sbfes_START (17)
#define SOC_UFS_HCI_UFS_IS_ufs_is_sbfes_END (17)
#define SOC_UFS_HCI_UFS_IS_ufs_is_cefes_START (18)
#define SOC_UFS_HCI_UFS_IS_ufs_is_cefes_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_ie_utrce : 1;
        unsigned int ufs_ie_udeprie : 1;
        unsigned int ufs_ie_uee : 1;
        unsigned int ufs_ie_utmse : 1;
        unsigned int ufs_ie_upmse : 1;
        unsigned int ufs_ie_uhxse : 1;
        unsigned int ufs_ie_uhese : 1;
        unsigned int ufs_ie_ullse : 1;
        unsigned int ufs_ie_ulsse : 1;
        unsigned int ufs_ie_utmrce : 1;
        unsigned int ufs_ie_ucce : 1;
        unsigned int ufs_ie_dfee : 1;
        unsigned int ufs_ie_utpee : 1;
        unsigned int reserved_0 : 3;
        unsigned int ufs_ie_hcfee : 1;
        unsigned int ufs_ie_sbfee : 1;
        unsigned int ufs_ie_cefee : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_UFS_HCI_UFS_IE_UNION;
#endif
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utrce_START (0)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utrce_END (0)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_udeprie_START (1)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_udeprie_END (1)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uee_START (2)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uee_END (2)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utmse_START (3)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utmse_END (3)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_upmse_START (4)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_upmse_END (4)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uhxse_START (5)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uhxse_END (5)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uhese_START (6)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_uhese_END (6)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ullse_START (7)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ullse_END (7)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ulsse_START (8)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ulsse_END (8)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utmrce_START (9)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utmrce_END (9)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ucce_START (10)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_ucce_END (10)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_dfee_START (11)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_dfee_END (11)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utpee_START (12)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_utpee_END (12)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_hcfee_START (16)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_hcfee_END (16)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_sbfee_START (17)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_sbfee_END (17)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_cefee_START (18)
#define SOC_UFS_HCI_UFS_IE_ufs_ie_cefee_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hcs_dp : 1;
        unsigned int ufs_hcs_utrlrdy : 1;
        unsigned int ufs_hcs_utmrlrdy : 1;
        unsigned int ufs_hcs_ucrdy : 1;
        unsigned int reserved_0 : 4;
        unsigned int ufs_hcs_upmcrs : 3;
        unsigned int reserved_1 : 1;
        unsigned int ufs_hcs_utpec : 4;
        unsigned int ufs_hcs_ttagutpe : 8;
        unsigned int ufs_hcs_tlunutpe : 8;
    } reg;
} SOC_UFS_HCI_UFS_HCS_UNION;
#endif
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_dp_START (0)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_dp_END (0)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utrlrdy_START (1)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utrlrdy_END (1)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utmrlrdy_START (2)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utmrlrdy_END (2)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_ucrdy_START (3)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_ucrdy_END (3)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_upmcrs_START (08)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_upmcrs_END (10)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utpec_START (12)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_utpec_END (15)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_ttagutpe_START (16)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_ttagutpe_END (23)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_tlunutpe_START (24)
#define SOC_UFS_HCI_UFS_HCS_ufs_hcs_tlunutpe_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hce_hce : 1;
        unsigned int ufs_hce_cge : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_HCE_UNION;
#endif
#define SOC_UFS_HCI_UFS_HCE_ufs_hce_hce_START (0)
#define SOC_UFS_HCI_UFS_HCE_ufs_hce_hce_END (0)
#define SOC_UFS_HCI_UFS_HCE_ufs_hce_cge_START (1)
#define SOC_UFS_HCI_UFS_HCE_ufs_hce_cge_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utriacr_iatoval : 8;
        unsigned int ufs_utriacr_iacth : 5;
        unsigned int reserved_0 : 3;
        unsigned int ufs_utriacr_ctr : 1;
        unsigned int reserved_1 : 3;
        unsigned int ufs_utriacr_iasb : 1;
        unsigned int reserved_2 : 3;
        unsigned int ufs_utriacr_iapwen : 1;
        unsigned int reserved_3 : 6;
        unsigned int ufs_utriacr_iaen : 1;
    } reg;
} SOC_UFS_HCI_UFS_UTRIACR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iatoval_START (0)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iatoval_END (7)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iacth_START (08)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iacth_END (12)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_ctr_START (16)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_ctr_END (16)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iasb_START (20)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iasb_END (20)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iapwen_START (24)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iapwen_END (24)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iaen_START (31)
#define SOC_UFS_HCI_UFS_UTRIACR_ufs_utriacr_iaen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int ufs_utplbal : 22;
    } reg;
} SOC_UFS_HCI_UFS_UTPLBA_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTPLBA_ufs_utplbal_START (10)
#define SOC_UFS_HCI_UFS_UTPLBA_ufs_utplbal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utplbau : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTPLBAU_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTPLBAU_ufs_utplbau_START (00)
#define SOC_UFS_HCI_UFS_UTPLBAU_ufs_utplbau_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utrlrsr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_UTRLRSR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTRLRSR_ufs_utrlrsr_START (0)
#define SOC_UFS_HCI_UFS_UTRLRSR_ufs_utrlrsr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int cfg_utmrlba : 22;
    } reg;
} SOC_UFS_HCI_UFS_UTMRLBA_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMRLBA_cfg_utmrlba_START (10)
#define SOC_UFS_HCI_UFS_UTMRLBA_cfg_utmrlba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_utmrlbau : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTMRLBAU_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMRLBAU_cfg_utmrlbau_START (00)
#define SOC_UFS_HCI_UFS_UTMRLBAU_cfg_utmrlbau_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_utmrlrsr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_UTMRLRSR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMRLRSR_cfg_utmrlrsr_START (0)
#define SOC_UFS_HCI_UFS_UTMRLRSR_cfg_utmrlrsr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_tm_header_chk_en : 1;
        unsigned int cfg_utr_qos_en : 1;
        unsigned int cfg_prd_fetch_threshold : 3;
        unsigned int cfg_dma0_max_burst : 2;
        unsigned int cfg_dma1_max_burst : 2;
        unsigned int reserved_0 : 1;
        unsigned int dma1_wvalid_mode_cfg : 1;
        unsigned int cfg_inbound_upiu_iid_chk_en : 1;
        unsigned int cfg_rx_cport_idle_timeout_trsh : 8;
        unsigned int cfg_rx_cport_idle_chk_en : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_UFS_HCI_UFS_PROC_MODE_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_tm_header_chk_en_START (0)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_tm_header_chk_en_END (0)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_utr_qos_en_START (1)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_utr_qos_en_END (1)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_prd_fetch_threshold_START (02)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_prd_fetch_threshold_END (04)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_dma0_max_burst_START (05)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_dma0_max_burst_END (06)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_dma1_max_burst_START (07)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_dma1_max_burst_END (08)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_dma1_wvalid_mode_cfg_START (10)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_dma1_wvalid_mode_cfg_END (10)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_inbound_upiu_iid_chk_en_START (11)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_inbound_upiu_iid_chk_en_END (11)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_rx_cport_idle_timeout_trsh_START (12)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_rx_cport_idle_timeout_trsh_END (19)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_rx_cport_idle_chk_en_START (20)
#define SOC_UFS_HCI_UFS_PROC_MODE_CFG_cfg_rx_cport_idle_chk_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_doorbell_0_qos : 4;
        unsigned int cfg_doorbell_1_qos : 4;
        unsigned int cfg_doorbell_2_qos : 4;
        unsigned int cfg_doorbell_3_qos : 4;
        unsigned int cfg_doorbell_4_qos : 4;
        unsigned int cfg_doorbell_5_qos : 4;
        unsigned int cfg_doorbell_6_qos : 4;
        unsigned int cfg_doorbell_7_qos : 4;
    } reg;
} SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_UNION;
#endif
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_0_qos_START (00)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_0_qos_END (03)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_1_qos_START (04)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_1_qos_END (07)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_2_qos_START (08)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_2_qos_END (11)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_3_qos_START (12)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_3_qos_END (15)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_4_qos_START (16)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_4_qos_END (19)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_5_qos_START (20)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_5_qos_END (23)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_6_qos_START (24)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_6_qos_END (27)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_7_qos_START (28)
#define SOC_UFS_HCI_UFS_DOORBELL_0_7_QOS_cfg_doorbell_7_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_doorbell_8_qos : 4;
        unsigned int cfg_doorbell_9_qos : 4;
        unsigned int cfg_doorbell_10_qos : 4;
        unsigned int cfg_doorbell_11_qos : 4;
        unsigned int cfg_doorbell_12_qos : 4;
        unsigned int cfg_doorbell_13_qos : 4;
        unsigned int cfg_doorbell_14_qos : 4;
        unsigned int cfg_doorbell_15_qos : 4;
    } reg;
} SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_UNION;
#endif
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_8_qos_START (00)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_8_qos_END (03)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_9_qos_START (04)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_9_qos_END (07)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_10_qos_START (08)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_10_qos_END (11)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_11_qos_START (12)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_11_qos_END (15)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_12_qos_START (16)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_12_qos_END (19)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_13_qos_START (20)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_13_qos_END (23)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_14_qos_START (24)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_14_qos_END (27)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_15_qos_START (28)
#define SOC_UFS_HCI_UFS_DOORBELL_8_15_QOS_cfg_doorbell_15_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_doorbell_16_qos : 4;
        unsigned int cfg_doorbell_17_qos : 4;
        unsigned int cfg_doorbell_18_qos : 4;
        unsigned int cfg_doorbell_19_qos : 4;
        unsigned int cfg_doorbell_20_qos : 4;
        unsigned int cfg_doorbell_21_qos : 4;
        unsigned int cfg_doorbell_22_qos : 4;
        unsigned int cfg_doorbell_23_qos : 4;
    } reg;
} SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_UNION;
#endif
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_16_qos_START (00)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_16_qos_END (03)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_17_qos_START (04)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_17_qos_END (07)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_18_qos_START (08)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_18_qos_END (11)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_19_qos_START (12)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_19_qos_END (15)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_20_qos_START (16)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_20_qos_END (19)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_21_qos_START (20)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_21_qos_END (23)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_22_qos_START (24)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_22_qos_END (27)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_23_qos_START (28)
#define SOC_UFS_HCI_UFS_DOORBELL_16_23_QOS_cfg_doorbell_23_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_doorbell_24_qos : 4;
        unsigned int cfg_doorbell_25_qos : 4;
        unsigned int cfg_doorbell_26_qos : 4;
        unsigned int cfg_doorbell_27_qos : 4;
        unsigned int cfg_doorbell_28_qos : 4;
        unsigned int cfg_doorbell_29_qos : 4;
        unsigned int cfg_doorbell_30_qos : 4;
        unsigned int cfg_doorbell_31_qos : 4;
    } reg;
} SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_UNION;
#endif
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_24_qos_START (00)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_24_qos_END (03)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_25_qos_START (04)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_25_qos_END (07)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_26_qos_START (08)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_26_qos_END (11)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_27_qos_START (12)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_27_qos_END (15)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_28_qos_START (16)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_28_qos_END (19)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_29_qos_START (20)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_29_qos_END (23)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_30_qos_START (24)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_30_qos_END (27)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_31_qos_START (28)
#define SOC_UFS_HCI_UFS_DOORBELL_24_31_QOS_cfg_doorbell_31_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_outstand_arb_num : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_outstand_total : 5;
        unsigned int cfg_outstand_total_en : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_arb_num_START (00)
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_arb_num_END (04)
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_total_START (08)
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_total_END (12)
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_total_en_START (13)
#define SOC_UFS_HCI_UFS_TR_OUTSTANDING_NUM_cfg_outstand_total_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_outstand_qos0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_outstand_qos1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_outstand_qos2 : 5;
        unsigned int reserved_2 : 3;
        unsigned int cfg_outstand_qos3 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos0_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos0_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos1_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos1_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos2_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos2_END (20)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos3_START (24)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_OUTSTANDING_cfg_outstand_qos3_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_outstand_qos4 : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_outstand_qos5 : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_outstand_qos6 : 5;
        unsigned int reserved_2 : 3;
        unsigned int cfg_outstand_qos7 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos4_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos4_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos5_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos5_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos6_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos6_END (20)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos7_START (24)
#define SOC_UFS_HCI_UFS_TR_QOS_4_7_OUTSTANDING_cfg_outstand_qos7_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_outstand_qos0_promote : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_outstand_qos1_promote : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_outstand_qos2_promote : 5;
        unsigned int reserved_2 : 3;
        unsigned int cfg_outstand_qos3_promote : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos0_promote_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos0_promote_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos1_promote_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos1_promote_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos2_promote_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos2_promote_END (20)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos3_promote_START (24)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_PROMOTE_cfg_outstand_qos3_promote_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_outstand_qos4_promote : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_outstand_qos5_promote : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_outstand_qos6_promote : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos4_promote_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos4_promote_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos5_promote_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos5_promote_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos6_promote_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_PROMOTE_cfg_outstand_qos6_promote_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_qos0_increase : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_qos1_increase : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_qos2_increase : 5;
        unsigned int reserved_2 : 3;
        unsigned int cfg_qos3_increase : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos0_increase_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos0_increase_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos1_increase_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos1_increase_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos2_increase_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos2_increase_END (20)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos3_increase_START (24)
#define SOC_UFS_HCI_UFS_TR_QOS_0_3_INCREASE_cfg_qos3_increase_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_qos4_increase : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_qos5_increase : 5;
        unsigned int reserved_1 : 3;
        unsigned int cfg_qos6_increase : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos4_increase_START (00)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos4_increase_END (04)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos5_increase_START (08)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos5_increase_END (12)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos6_increase_START (16)
#define SOC_UFS_HCI_UFS_TR_QOS_4_6_INCREASE_cfg_qos6_increase_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_ufs_axi_wr_user0 : 8;
        unsigned int cfg_ufs_axi_wr_user1 : 8;
        unsigned int cfg_ufs_axi_rd_user0 : 8;
        unsigned int cfg_ufs_axi_rd_user1 : 8;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user0_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user0_END (7)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user1_START (8)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user1_END (15)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user0_START (16)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user0_END (23)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user1_START (24)
#define SOC_UFS_HCI_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_rx_ost_num_cfg : 4;
        unsigned int dma1_rx_ost_num_cfg : 4;
        unsigned int dma0_tx_ost_num_cfg : 4;
        unsigned int dma1_tx_ost_num_cfg : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma0_rx_ost_num_cfg_START (0)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma0_rx_ost_num_cfg_END (3)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma1_rx_ost_num_cfg_START (4)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma1_rx_ost_num_cfg_END (7)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma0_tx_ost_num_cfg_START (8)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma0_tx_ost_num_cfg_END (11)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma1_tx_ost_num_cfg_START (12)
#define SOC_UFS_HCI_UFS_DMAC_OUTSTANDING_CFG_dma1_tx_ost_num_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_ccap_nutrs : 8;
        unsigned int ufs_ccap_cfgc : 8;
        unsigned int reserved : 8;
        unsigned int ufs_ccap_cfgptr : 8;
    } reg;
} SOC_UFS_HCI_UFS_CCAP_UNION;
#endif
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_nutrs_START (00)
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_nutrs_END (07)
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_cfgc_START (08)
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_cfgc_END (15)
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_cfgptr_START (24)
#define SOC_UFS_HCI_UFS_CCAP_ufs_ccap_cfgptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_cryptocap_0_algid : 8;
        unsigned int ufs_cryptocap_0_sudsb : 8;
        unsigned int cryptocap_0_ks : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCAP_0_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ufs_cryptocap_0_algid_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ufs_cryptocap_0_algid_END (07)
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ufs_cryptocap_0_sudsb_START (08)
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_ufs_cryptocap_0_sudsb_END (15)
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_cryptocap_0_ks_START (16)
#define SOC_UFS_HCI_UFS_CRYPTOCAP_0_cryptocap_0_ks_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufshc_sysclk_cg_sw_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int ufshc_utp_tx_cryptokey_cg_sw_en : 1;
        unsigned int ufshc_utp_rx_cryptokey_cg_sw_en : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_UFS_HCI_UFS_BLOCK_CG_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_sysclk_cg_sw_en_START (0)
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_sysclk_cg_sw_en_END (0)
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_utp_tx_cryptokey_cg_sw_en_START (2)
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_utp_tx_cryptokey_cg_sw_en_END (2)
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_utp_rx_cryptokey_cg_sw_en_START (3)
#define SOC_UFS_HCI_UFS_BLOCK_CG_CFG_ufshc_utp_rx_cryptokey_cg_sw_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_is_utrces_sw_sim : 1;
        unsigned int ufs_is_udepries_sw_sim : 1;
        unsigned int ufs_is_uees_sw_sim : 1;
        unsigned int ufs_is_utms_sw_sim : 1;
        unsigned int ufs_is_upms_sw_sim : 1;
        unsigned int ufs_is_uhxs_sw_sim : 1;
        unsigned int ufs_is_uhes_sw_sim : 1;
        unsigned int ufs_is_ulls_sw_sim : 1;
        unsigned int ufs_is_ulss_sw_sim : 1;
        unsigned int ufs_is_utmrces_sw_sim : 1;
        unsigned int ufs_is_ucces_sw_sim : 1;
        unsigned int ufs_is_dfes_sw_sim : 1;
        unsigned int ufs_is_utpes_sw_sim : 1;
        unsigned int reserved_0 : 3;
        unsigned int ufs_is_hcfes_sw_sim : 1;
        unsigned int ufs_is_sbfes_sw_sim : 1;
        unsigned int ufs_is_cefes_sw_sim : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_UFS_HCI_UFS_IS_INT_SET_UNION;
#endif
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utrces_sw_sim_START (0)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utrces_sw_sim_END (0)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_udepries_sw_sim_START (1)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_udepries_sw_sim_END (1)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uees_sw_sim_START (2)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uees_sw_sim_END (2)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utms_sw_sim_START (3)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utms_sw_sim_END (3)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_upms_sw_sim_START (4)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_upms_sw_sim_END (4)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uhxs_sw_sim_START (5)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uhxs_sw_sim_END (5)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uhes_sw_sim_START (6)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_uhes_sw_sim_END (6)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ulls_sw_sim_START (7)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ulls_sw_sim_END (7)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ulss_sw_sim_START (8)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ulss_sw_sim_END (8)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utmrces_sw_sim_START (9)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utmrces_sw_sim_END (9)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ucces_sw_sim_START (10)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_ucces_sw_sim_END (10)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_dfes_sw_sim_START (11)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_dfes_sw_sim_END (11)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utpes_sw_sim_START (12)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_utpes_sw_sim_END (12)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_hcfes_sw_sim_START (16)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_hcfes_sw_sim_END (16)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_sbfes_sw_sim_START (17)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_sbfes_sw_sim_END (17)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_cefes_sw_sim_START (18)
#define SOC_UFS_HCI_UFS_IS_INT_SET_ufs_is_cefes_sw_sim_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_auto_hib_en : 1;
        unsigned int ufs_hibernate_exit_mode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_AHIT_CTRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ufs_auto_hib_en_START (00)
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ufs_auto_hib_en_END (00)
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ufs_hibernate_exit_mode_START (01)
#define SOC_UFS_HCI_UFS_AHIT_CTRL_ufs_hibernate_exit_mode_END (01)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hibernate_exit : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_AHIT_EXIT_REQ_UNION;
#endif
#define SOC_UFS_HCI_UFS_AHIT_EXIT_REQ_ufs_hibernate_exit_START (00)
#define SOC_UFS_HCI_UFS_AHIT_EXIT_REQ_ufs_hibernate_exit_END (00)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_io_timeout_trsh : 7;
        unsigned int reserved_0 : 1;
        unsigned int cfg_io_timeout_check_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_UNION;
#endif
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_cfg_io_timeout_trsh_START (00)
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_cfg_io_timeout_trsh_END (06)
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_cfg_io_timeout_check_en_START (08)
#define SOC_UFS_HCI_UFS_IO_TIMEOUT_CHECK_cfg_io_timeout_check_en_END (08)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_ie_io_timeout_ind : 1;
        unsigned int ufs_ie_ufshc_idle_timeout_ind : 1;
        unsigned int ufs_ie_no_som_frm_ind : 1;
        unsigned int ufs_ie_size0_frm_ind : 1;
        unsigned int ufs_ie_unknown_frm_ind : 1;
        unsigned int ufs_ie_err_frm_ind : 1;
        unsigned int ufs_ie_utp_tx_fifo_ctrl_err_int : 1;
        unsigned int ufs_ie_utp_tx_cport_err_int : 1;
        unsigned int ufs_ie_dma1_fifo_ctrl_err_int : 1;
        unsigned int ufs_ie_dma1_tx_axi_err_int : 1;
        unsigned int ufs_ie_dma1_rx_axi_err_int : 1;
        unsigned int ufs_ie_dma0_tx_axi_err_int : 1;
        unsigned int ufs_ie_dma0_rx_axi_err_int : 1;
        unsigned int ufs_ie_ah8_enter_req_cnf_failed_int : 1;
        unsigned int ufs_ie_ah8_exit_req_cnf_failed_int : 1;
        unsigned int ufs_ie_rx_cport_idle_timeout_int : 1;
        unsigned int ufs_ie_read_complete_interrupt : 1;
        unsigned int ufs_ie_write_complete_interrupt : 1;
        unsigned int ufs_ie_ah8_exit_interrupt : 1;
        unsigned int ufs_ie_idle_prejudge_interrupt : 1;
        unsigned int ufs_ie_ahb_err_interrupt : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_UFS_HCI_UFS_VS_IE_UNION;
#endif
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_io_timeout_ind_START (0)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_io_timeout_ind_END (0)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ufshc_idle_timeout_ind_START (1)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ufshc_idle_timeout_ind_END (1)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_no_som_frm_ind_START (2)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_no_som_frm_ind_END (2)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_size0_frm_ind_START (3)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_size0_frm_ind_END (3)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_unknown_frm_ind_START (4)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_unknown_frm_ind_END (4)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_err_frm_ind_START (5)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_err_frm_ind_END (5)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_utp_tx_fifo_ctrl_err_int_START (6)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_utp_tx_fifo_ctrl_err_int_END (6)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_utp_tx_cport_err_int_START (7)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_utp_tx_cport_err_int_END (7)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_fifo_ctrl_err_int_START (8)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_fifo_ctrl_err_int_END (8)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_tx_axi_err_int_START (9)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_tx_axi_err_int_END (9)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_rx_axi_err_int_START (10)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma1_rx_axi_err_int_END (10)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma0_tx_axi_err_int_START (11)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma0_tx_axi_err_int_END (11)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma0_rx_axi_err_int_START (12)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_dma0_rx_axi_err_int_END (12)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_enter_req_cnf_failed_int_START (13)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_enter_req_cnf_failed_int_END (13)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_exit_req_cnf_failed_int_START (14)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_exit_req_cnf_failed_int_END (14)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_rx_cport_idle_timeout_int_START (15)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_rx_cport_idle_timeout_int_END (15)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_read_complete_interrupt_START (16)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_read_complete_interrupt_END (16)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_write_complete_interrupt_START (17)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_write_complete_interrupt_END (17)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_exit_interrupt_START (18)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ah8_exit_interrupt_END (18)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_idle_prejudge_interrupt_START (19)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_idle_prejudge_interrupt_END (19)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ahb_err_interrupt_START (20)
#define SOC_UFS_HCI_UFS_VS_IE_ufs_ie_ahb_err_interrupt_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_norm_stat_sel : 4;
        unsigned int utp_rx_disc_stat_sel : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_utp_rx_norm_stat_sel_START (00)
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_utp_rx_norm_stat_sel_END (03)
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_utp_rx_disc_stat_sel_START (04)
#define SOC_UFS_HCI_UFS_UTP_RX_STATISTIC_CFG_utp_rx_disc_stat_sel_END (06)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hc_ah8_state : 8;
        unsigned int ufs_ah8_exit_status : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_UFS_HCI_UFS_AUTO_H8_STATE_UNION;
#endif
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ufs_hc_ah8_state_START (00)
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ufs_hc_ah8_state_END (07)
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ufs_ah8_exit_status_START (08)
#define SOC_UFS_HCI_UFS_AUTO_H8_STATE_ufs_ah8_exit_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_hce_proc_dfx : 8;
        unsigned int ufs_ah8_proc_dfx : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ufs_hce_proc_dfx_START (00)
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ufs_hce_proc_dfx_END (07)
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ufs_ah8_proc_dfx_START (08)
#define SOC_UFS_HCI_UFS_CFG_AO_FUNC_DFX_ufs_ah8_proc_dfx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h8_store_load_dfx : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_UFS_HCI_UFS_H8_STORE_LOAD_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_H8_STORE_LOAD_DFX_h8_store_load_dfx_START (00)
#define SOC_UFS_HCI_UFS_H8_STORE_LOAD_DFX_h8_store_load_dfx_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_crg_crypt_cg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_UFS_HCI_UFS_CRG_CLK_GATE_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRG_CLK_GATE_DFX_cfg_crg_crypt_cg_en_START (0)
#define SOC_UFS_HCI_UFS_CRG_CLK_GATE_DFX_cfg_crg_crypt_cg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_idle_timer_threshold : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_UFS_HCI_UFS_CFG_IDLE_TIME_THRESHOLD_UNION;
#endif
#define SOC_UFS_HCI_UFS_CFG_IDLE_TIME_THRESHOLD_ufs_idle_timer_threshold_START (00)
#define SOC_UFS_HCI_UFS_CFG_IDLE_TIME_THRESHOLD_ufs_idle_timer_threshold_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_cfg_ram_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_CFG_RAM_CTRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_CFG_RAM_CTRL_ufs_cfg_ram_ctrl_START (00)
#define SOC_UFS_HCI_UFS_CFG_RAM_CTRL_ufs_cfg_ram_ctrl_END (01)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_cfg_ram_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_CFG_RAM_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_CFG_RAM_STATUS_ufs_cfg_ram_status_START (00)
#define SOC_UFS_HCI_UFS_CFG_RAM_STATUS_ufs_cfg_ram_status_END (01)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_idle_enable : 2;
        unsigned int ufs_idle_status : 1;
        unsigned int ufs_unipro_idle_ind : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_UNION;
#endif
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_idle_enable_START (00)
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_idle_enable_END (01)
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_idle_status_START (02)
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_idle_status_END (02)
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_unipro_idle_ind_START (03)
#define SOC_UFS_HCI_UFS_CFG_IDLE_ENABLE_ufs_unipro_idle_ind_END (03)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trp_reservebit_check : 1;
        unsigned int cfg_trp_crypto_no_read_write_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_TRP_CHECK_EN_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_cfg_trp_reservebit_check_START (0)
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_cfg_trp_reservebit_check_END (0)
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_cfg_trp_crypto_no_read_write_mask_START (1)
#define SOC_UFS_HCI_UFS_TRP_CHECK_EN_cfg_trp_crypto_no_read_write_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trp_kdf_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_IE_KEY_KDF_EN_UNION;
#endif
#define SOC_UFS_HCI_UFS_IE_KEY_KDF_EN_cfg_trp_kdf_en_START (0)
#define SOC_UFS_HCI_UFS_IE_KEY_KDF_EN_cfg_trp_kdf_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_mcore_arb_timeout_thsh : 4;
        unsigned int ufs_mcore_arb_timeout_ts : 3;
        unsigned int reserved_0 : 9;
        unsigned int cfg_mcore_bypass_en : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_UNION;
#endif
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ufs_mcore_arb_timeout_thsh_START (00)
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ufs_mcore_arb_timeout_thsh_END (03)
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ufs_mcore_arb_timeout_ts_START (04)
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_ufs_mcore_arb_timeout_ts_END (06)
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_cfg_mcore_bypass_en_START (16)
#define SOC_UFS_HCI_UFS_MUTILQ_ARB_TO_THSH_cfg_mcore_bypass_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mphy_mcu_init_done_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_MPHY_MCU_INIT_DONE_MASH_UNION;
#endif
#define SOC_UFS_HCI_MPHY_MCU_INIT_DONE_MASH_mphy_mcu_init_done_mask_START (0)
#define SOC_UFS_HCI_MPHY_MCU_INIT_DONE_MASH_mphy_mcu_init_done_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_0_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_0_cfg_cryptokey_0_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_0_cfg_cryptokey_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_1_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_1_cfg_cryptokey_1_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_1_cfg_cryptokey_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_2_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_2_cfg_cryptokey_2_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_2_cfg_cryptokey_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_3 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_3_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_3_cfg_cryptokey_3_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_3_cfg_cryptokey_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_4 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_4_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_4_cfg_cryptokey_4_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_4_cfg_cryptokey_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_5 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_5_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_5_cfg_cryptokey_5_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_5_cfg_cryptokey_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_6 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_6_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_6_cfg_cryptokey_6_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_6_cfg_cryptokey_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_7 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_7_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_7_cfg_cryptokey_7_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_7_cfg_cryptokey_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_8 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_8_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_8_cfg_cryptokey_8_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_8_cfg_cryptokey_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_9 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_9_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_9_cfg_cryptokey_9_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_9_cfg_cryptokey_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_10 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_10_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_10_cfg_cryptokey_10_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_10_cfg_cryptokey_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_11 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_11_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_11_cfg_cryptokey_11_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_11_cfg_cryptokey_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_12 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_12_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_12_cfg_cryptokey_12_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_12_cfg_cryptokey_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_13 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_13_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_13_cfg_cryptokey_13_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_13_cfg_cryptokey_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_14 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_14_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_14_cfg_cryptokey_14_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_14_cfg_cryptokey_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_15 : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_15_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_15_cfg_cryptokey_15_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_15_cfg_cryptokey_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cryptokey_dusize : 8;
        unsigned int cfg_cryptokey_capidx : 8;
        unsigned int reserved : 15;
        unsigned int cfg_cryptokey_cfge : 1;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_UNION;
#endif
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_dusize_START (00)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_dusize_END (07)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_capidx_START (08)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_capidx_END (15)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_cfge_START (31)
#define SOC_UFS_HCI_UFS_CRYPTOCFG_i_16_cfg_cryptokey_cfge_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_HCI_UFS_CRYPTOCFG_i_31_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_is_utrcs : 1;
        unsigned int ufs_core_is_io_timeout : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_CORE_IS_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_IS_ufs_core_is_utrcs_START (0)
#define SOC_UFS_HCI_UFS_CORE_IS_ufs_core_is_utrcs_END (0)
#define SOC_UFS_HCI_UFS_CORE_IS_ufs_core_is_io_timeout_START (1)
#define SOC_UFS_HCI_UFS_CORE_IS_ufs_core_is_io_timeout_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_ie_utrce : 1;
        unsigned int ufs_core_ie_io_timeout : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_CORE_IE_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_IE_ufs_core_ie_utrce_START (0)
#define SOC_UFS_HCI_UFS_CORE_IE_ufs_core_ie_utrce_END (0)
#define SOC_UFS_HCI_UFS_CORE_IE_ufs_core_ie_io_timeout_START (1)
#define SOC_UFS_HCI_UFS_CORE_IE_ufs_core_ie_io_timeout_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_is_utrces_sw_sim : 1;
        unsigned int ufs_core_is_io_timeout_sim : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_CORE_IS_INT_SET_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ufs_core_is_utrces_sw_sim_START (0)
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ufs_core_is_utrces_sw_sim_END (0)
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ufs_core_is_io_timeout_sim_START (1)
#define SOC_UFS_HCI_UFS_CORE_IS_INT_SET_ufs_core_is_io_timeout_sim_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_hcs_dp : 1;
        unsigned int ufs_core_hcs_utrlrdy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_HCS_CORE_UNION;
#endif
#define SOC_UFS_HCI_UFS_HCS_CORE_ufs_core_hcs_dp_START (0)
#define SOC_UFS_HCI_UFS_HCS_CORE_ufs_core_hcs_dp_END (0)
#define SOC_UFS_HCI_UFS_HCS_CORE_ufs_core_hcs_utrlrdy_START (1)
#define SOC_UFS_HCI_UFS_HCS_CORE_ufs_core_hcs_utrlrdy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_core_doorbell_0_qos : 4;
        unsigned int cfg_core_doorbell_1_qos : 4;
        unsigned int cfg_core_doorbell_2_qos : 4;
        unsigned int cfg_core_doorbell_3_qos : 4;
        unsigned int cfg_core_doorbell_4_qos : 4;
        unsigned int cfg_core_doorbell_5_qos : 4;
        unsigned int cfg_core_doorbell_6_qos : 4;
        unsigned int cfg_core_doorbell_7_qos : 4;
    } reg;
} SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_0_qos_START (00)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_0_qos_END (03)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_1_qos_START (04)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_1_qos_END (07)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_2_qos_START (08)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_2_qos_END (11)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_3_qos_START (12)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_3_qos_END (15)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_4_qos_START (16)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_4_qos_END (19)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_5_qos_START (20)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_5_qos_END (23)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_6_qos_START (24)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_6_qos_END (27)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_7_qos_START (28)
#define SOC_UFS_HCI_UFS_CORE_DOORBELL_QOS_cfg_core_doorbell_7_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_utrlrsr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_CORE_UTRLRSR_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_UTRLRSR_ufs_core_utrlrsr_START (0)
#define SOC_UFS_HCI_UFS_CORE_UTRLRSR_ufs_core_utrlrsr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_uecpa_ec : 5;
        unsigned int reserved : 26;
        unsigned int ufs_uecpa_err : 1;
    } reg;
} SOC_UFS_HCI_UFS_UECPA_UNION;
#endif
#define SOC_UFS_HCI_UFS_UECPA_ufs_uecpa_ec_START (00)
#define SOC_UFS_HCI_UFS_UECPA_ufs_uecpa_ec_END (04)
#define SOC_UFS_HCI_UFS_UECPA_ufs_uecpa_err_START (31)
#define SOC_UFS_HCI_UFS_UECPA_ufs_uecpa_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_uecdl_ec : 16;
        unsigned int reserved : 15;
        unsigned int ufs_uecdl_err : 1;
    } reg;
} SOC_UFS_HCI_UFS_UECDL_UNION;
#endif
#define SOC_UFS_HCI_UFS_UECDL_ufs_uecdl_ec_START (00)
#define SOC_UFS_HCI_UFS_UECDL_ufs_uecdl_ec_END (15)
#define SOC_UFS_HCI_UFS_UECDL_ufs_uecdl_err_START (31)
#define SOC_UFS_HCI_UFS_UECDL_ufs_uecdl_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_uecn_ec : 3;
        unsigned int reserved : 28;
        unsigned int ufs_uecn_err : 1;
    } reg;
} SOC_UFS_HCI_UFS_UECN_UNION;
#endif
#define SOC_UFS_HCI_UFS_UECN_ufs_uecn_ec_START (00)
#define SOC_UFS_HCI_UFS_UECN_ufs_uecn_ec_END (02)
#define SOC_UFS_HCI_UFS_UECN_ufs_uecn_err_START (31)
#define SOC_UFS_HCI_UFS_UECN_ufs_uecn_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_uect_ec : 7;
        unsigned int reserved : 24;
        unsigned int ufs_uect_err : 1;
    } reg;
} SOC_UFS_HCI_UFS_UECT_UNION;
#endif
#define SOC_UFS_HCI_UFS_UECT_ufs_uect_ec_START (00)
#define SOC_UFS_HCI_UFS_UECT_ufs_uect_ec_END (06)
#define SOC_UFS_HCI_UFS_UECT_ufs_uect_err_START (31)
#define SOC_UFS_HCI_UFS_UECT_ufs_uect_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_uecdme_ec : 4;
        unsigned int reserved : 27;
        unsigned int ufs_uecdme_err : 1;
    } reg;
} SOC_UFS_HCI_UFS_UECDME_UNION;
#endif
#define SOC_UFS_HCI_UFS_UECDME_ufs_uecdme_ec_START (00)
#define SOC_UFS_HCI_UFS_UECDME_ufs_uecdme_ec_END (03)
#define SOC_UFS_HCI_UFS_UECDME_ufs_uecdme_err_START (31)
#define SOC_UFS_HCI_UFS_UECDME_ufs_uecdme_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utrldbr : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTRLDBR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTRLDBR_ufs_utrldbr_START (00)
#define SOC_UFS_HCI_UFS_UTRLDBR_ufs_utrldbr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utrlclr : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTRLCLR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTRLCLR_ufs_utrlclr_START (00)
#define SOC_UFS_HCI_UFS_UTRLCLR_ufs_utrlclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_utrlcnr : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTRLCNR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTRLCNR_ufs_utrlcnr_START (00)
#define SOC_UFS_HCI_UFS_UTRLCNR_ufs_utrlcnr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_utmrldbr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_UTMRLDBR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMRLDBR_cfg_utmrldbr_START (0)
#define SOC_UFS_HCI_UFS_UTMRLDBR_cfg_utmrldbr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_utmrlclr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_UTMRLCLR_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMRLCLR_cfg_utmrlclr_START (0)
#define SOC_UFS_HCI_UFS_UTMRLCLR_cfg_utmrlclr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_tx_press_cfg : 1;
        unsigned int utp_rx_press_cfg : 1;
        unsigned int dma1_tx_press_cfg : 1;
        unsigned int dma1_rx_press_cfg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_HCI_UFS_HW_PRESS_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_utp_tx_press_cfg_START (0)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_utp_tx_press_cfg_END (0)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_utp_rx_press_cfg_START (1)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_utp_rx_press_cfg_END (1)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_dma1_tx_press_cfg_START (2)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_dma1_tx_press_cfg_END (2)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_dma1_rx_press_cfg_START (3)
#define SOC_UFS_HCI_UFS_HW_PRESS_CFG_dma1_rx_press_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_invld_cmd_type_inject_en : 1;
        unsigned int cfg_invld_tm_type_inject_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_UNION;
#endif
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_cfg_invld_cmd_type_inject_en_START (0)
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_cfg_invld_cmd_type_inject_en_END (0)
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_cfg_invld_tm_type_inject_en_START (1)
#define SOC_UFS_HCI_UFS_HW_ERR_INJECT_CFG_cfg_invld_tm_type_inject_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_proc_timeout : 32;
    } reg;
} SOC_UFS_HCI_UFS_TR_TIMEOUT_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_TR_TIMEOUT_STATUS_cmd_proc_timeout_START (0)
#define SOC_UFS_HCI_UFS_TR_TIMEOUT_STATUS_cmd_proc_timeout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_is_io_timeout : 1;
        unsigned int ufs_is_ufshc_idle_timeout : 1;
        unsigned int no_som_frm_ind : 1;
        unsigned int size0_frm_ind : 1;
        unsigned int unknown_frm_ind : 1;
        unsigned int err_frm_ind : 1;
        unsigned int utp_tx_fifo_ctrl_err_int : 1;
        unsigned int utp_tx_cport_err_int : 1;
        unsigned int dma1_fifo_ctrl_err_int : 1;
        unsigned int dma1_tx_axi_err_int : 1;
        unsigned int dma1_rx_axi_err_int : 1;
        unsigned int dma0_tx_axi_err_int : 1;
        unsigned int dma0_rx_axi_err_int : 1;
        unsigned int ah8_enter_req_cnf_failed_int : 1;
        unsigned int ah8_exit_req_cnf_failed_int : 1;
        unsigned int ufs_rx_cport_idle_timeout_int : 1;
        unsigned int ufs_read_complete_interrupt : 1;
        unsigned int ufs_write_complete_interrupt : 1;
        unsigned int ufs_ah8_exit_interrupt : 1;
        unsigned int ufs_idle_prejudge_interrupt : 1;
        unsigned int ufs_ahb_err_interrupt : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_UFS_HCI_UFS_VS_IS_UNION;
#endif
#define SOC_UFS_HCI_UFS_VS_IS_ufs_is_io_timeout_START (0)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_is_io_timeout_END (0)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_is_ufshc_idle_timeout_START (1)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_is_ufshc_idle_timeout_END (1)
#define SOC_UFS_HCI_UFS_VS_IS_no_som_frm_ind_START (2)
#define SOC_UFS_HCI_UFS_VS_IS_no_som_frm_ind_END (2)
#define SOC_UFS_HCI_UFS_VS_IS_size0_frm_ind_START (3)
#define SOC_UFS_HCI_UFS_VS_IS_size0_frm_ind_END (3)
#define SOC_UFS_HCI_UFS_VS_IS_unknown_frm_ind_START (4)
#define SOC_UFS_HCI_UFS_VS_IS_unknown_frm_ind_END (4)
#define SOC_UFS_HCI_UFS_VS_IS_err_frm_ind_START (5)
#define SOC_UFS_HCI_UFS_VS_IS_err_frm_ind_END (5)
#define SOC_UFS_HCI_UFS_VS_IS_utp_tx_fifo_ctrl_err_int_START (6)
#define SOC_UFS_HCI_UFS_VS_IS_utp_tx_fifo_ctrl_err_int_END (6)
#define SOC_UFS_HCI_UFS_VS_IS_utp_tx_cport_err_int_START (7)
#define SOC_UFS_HCI_UFS_VS_IS_utp_tx_cport_err_int_END (7)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_fifo_ctrl_err_int_START (8)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_fifo_ctrl_err_int_END (8)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_tx_axi_err_int_START (9)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_tx_axi_err_int_END (9)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_rx_axi_err_int_START (10)
#define SOC_UFS_HCI_UFS_VS_IS_dma1_rx_axi_err_int_END (10)
#define SOC_UFS_HCI_UFS_VS_IS_dma0_tx_axi_err_int_START (11)
#define SOC_UFS_HCI_UFS_VS_IS_dma0_tx_axi_err_int_END (11)
#define SOC_UFS_HCI_UFS_VS_IS_dma0_rx_axi_err_int_START (12)
#define SOC_UFS_HCI_UFS_VS_IS_dma0_rx_axi_err_int_END (12)
#define SOC_UFS_HCI_UFS_VS_IS_ah8_enter_req_cnf_failed_int_START (13)
#define SOC_UFS_HCI_UFS_VS_IS_ah8_enter_req_cnf_failed_int_END (13)
#define SOC_UFS_HCI_UFS_VS_IS_ah8_exit_req_cnf_failed_int_START (14)
#define SOC_UFS_HCI_UFS_VS_IS_ah8_exit_req_cnf_failed_int_END (14)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_rx_cport_idle_timeout_int_START (15)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_rx_cport_idle_timeout_int_END (15)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_read_complete_interrupt_START (16)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_read_complete_interrupt_END (16)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_write_complete_interrupt_START (17)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_write_complete_interrupt_END (17)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_ah8_exit_interrupt_START (18)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_ah8_exit_interrupt_END (18)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_idle_prejudge_interrupt_START (19)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_idle_prejudge_interrupt_END (19)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_ahb_err_interrupt_START (20)
#define SOC_UFS_HCI_UFS_VS_IS_ufs_ahb_err_interrupt_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_is_io_timeout_sim : 1;
        unsigned int ufs_is_ufshc_idle_timeout_sim : 1;
        unsigned int no_som_frm_ind_sim : 1;
        unsigned int size0_frm_ind_sim : 1;
        unsigned int unknown_frm_ind_sim : 1;
        unsigned int err_frm_ind_sim : 1;
        unsigned int utp_tx_fifo_ctrl_err_int_sim : 1;
        unsigned int utp_tx_cport_err_int_sim : 1;
        unsigned int dma1_fifo_ctrl_err_int_sim : 1;
        unsigned int dma1_tx_axi_err_int_sim : 1;
        unsigned int dma1_rx_axi_err_int_sim : 1;
        unsigned int dma0_tx_axi_err_int_sim : 1;
        unsigned int dma0_rx_axi_err_int_sim : 1;
        unsigned int ah8_enter_req_cnf_failed_int_sim : 1;
        unsigned int ah8_exit_req_cnf_failed_int_sim : 1;
        unsigned int ufs_rx_cport_idle_timeout_int_sim : 1;
        unsigned int ufs_read_complete_interrupt_sim : 1;
        unsigned int ufs_write_complete_interrupt_sim : 1;
        unsigned int ufs_ah8_exit_interrupt_sim : 1;
        unsigned int ufs_idle_prejudge_interrupt_sim : 1;
        unsigned int ufs_ahb_err_interrupt_sim : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_UFS_HCI_UFS_VS_IS_SET_UNION;
#endif
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_is_io_timeout_sim_START (0)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_is_io_timeout_sim_END (0)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_is_ufshc_idle_timeout_sim_START (1)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_is_ufshc_idle_timeout_sim_END (1)
#define SOC_UFS_HCI_UFS_VS_IS_SET_no_som_frm_ind_sim_START (2)
#define SOC_UFS_HCI_UFS_VS_IS_SET_no_som_frm_ind_sim_END (2)
#define SOC_UFS_HCI_UFS_VS_IS_SET_size0_frm_ind_sim_START (3)
#define SOC_UFS_HCI_UFS_VS_IS_SET_size0_frm_ind_sim_END (3)
#define SOC_UFS_HCI_UFS_VS_IS_SET_unknown_frm_ind_sim_START (4)
#define SOC_UFS_HCI_UFS_VS_IS_SET_unknown_frm_ind_sim_END (4)
#define SOC_UFS_HCI_UFS_VS_IS_SET_err_frm_ind_sim_START (5)
#define SOC_UFS_HCI_UFS_VS_IS_SET_err_frm_ind_sim_END (5)
#define SOC_UFS_HCI_UFS_VS_IS_SET_utp_tx_fifo_ctrl_err_int_sim_START (6)
#define SOC_UFS_HCI_UFS_VS_IS_SET_utp_tx_fifo_ctrl_err_int_sim_END (6)
#define SOC_UFS_HCI_UFS_VS_IS_SET_utp_tx_cport_err_int_sim_START (7)
#define SOC_UFS_HCI_UFS_VS_IS_SET_utp_tx_cport_err_int_sim_END (7)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_fifo_ctrl_err_int_sim_START (8)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_fifo_ctrl_err_int_sim_END (8)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_tx_axi_err_int_sim_START (9)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_tx_axi_err_int_sim_END (9)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_rx_axi_err_int_sim_START (10)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma1_rx_axi_err_int_sim_END (10)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma0_tx_axi_err_int_sim_START (11)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma0_tx_axi_err_int_sim_END (11)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma0_rx_axi_err_int_sim_START (12)
#define SOC_UFS_HCI_UFS_VS_IS_SET_dma0_rx_axi_err_int_sim_END (12)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ah8_enter_req_cnf_failed_int_sim_START (13)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ah8_enter_req_cnf_failed_int_sim_END (13)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ah8_exit_req_cnf_failed_int_sim_START (14)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ah8_exit_req_cnf_failed_int_sim_END (14)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_rx_cport_idle_timeout_int_sim_START (15)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_rx_cport_idle_timeout_int_sim_END (15)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_read_complete_interrupt_sim_START (16)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_read_complete_interrupt_sim_END (16)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_write_complete_interrupt_sim_START (17)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_write_complete_interrupt_sim_END (17)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_ah8_exit_interrupt_sim_START (18)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_ah8_exit_interrupt_sim_END (18)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_idle_prejudge_interrupt_sim_START (19)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_idle_prejudge_interrupt_sim_END (19)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_ahb_err_interrupt_sim_START (20)
#define SOC_UFS_HCI_UFS_VS_IS_SET_ufs_ahb_err_interrupt_sim_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_tx_fifo_ctrl_err_sta : 17;
        unsigned int utp_tx_cport_err_sta : 3;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_utp_tx_fifo_ctrl_err_sta_START (0)
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_utp_tx_fifo_ctrl_err_sta_END (16)
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_utp_tx_cport_err_sta_START (17)
#define SOC_UFS_HCI_UFS_UTP_TX_ERR_STATUS_utp_tx_cport_err_sta_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_fifo_ctrl_err_sta : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_FIFO_CTRL_ERR_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_FIFO_CTRL_ERR_STATUS_dma1_fifo_ctrl_err_sta_START (0)
#define SOC_UFS_HCI_UFS_DMA1_FIFO_CTRL_ERR_STATUS_dma1_fifo_ctrl_err_sta_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utr_stop_status : 1;
        unsigned int utmr_stop_status : 1;
        unsigned int cfg_trp_abt_req : 1;
        unsigned int cfg_tmrp_abt_req : 1;
        unsigned int utr_core_stop_status : 8;
        unsigned int reserved : 20;
    } reg;
} SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utr_stop_status_START (0)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utr_stop_status_END (0)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utmr_stop_status_START (1)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utmr_stop_status_END (1)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_cfg_trp_abt_req_START (2)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_cfg_trp_abt_req_END (2)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_cfg_tmrp_abt_req_START (3)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_cfg_tmrp_abt_req_END (3)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utr_core_stop_status_START (4)
#define SOC_UFS_HCI_UFS_UTR_UTMR_STOP_STATUS_utr_core_stop_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utr_otsd_dbr_dfx : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTR_OTSD_DBR_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTR_OTSD_DBR_DFX_utr_otsd_dbr_dfx_START (0)
#define SOC_UFS_HCI_UFS_UTR_OTSD_DBR_DFX_utr_otsd_dbr_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utmr_otsd_dbr_dfx : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_UTMR_OTSD_DBR_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTMR_OTSD_DBR_DFX_utmr_otsd_dbr_dfx_START (0)
#define SOC_UFS_HCI_UFS_UTMR_OTSD_DBR_DFX_utmr_otsd_dbr_dfx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmrp_cfg_others_dfx : 32;
    } reg;
} SOC_UFS_HCI_UFS_TMRP_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_TMRP_DFX0_tmrp_cfg_others_dfx_START (0)
#define SOC_UFS_HCI_UFS_TMRP_DFX0_tmrp_cfg_others_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmrp_cfg_io_status_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_TMRP_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_TMRP_DFX1_tmrp_cfg_io_status_dfx1_START (0)
#define SOC_UFS_HCI_UFS_TMRP_DFX1_tmrp_cfg_io_status_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmrp_cfg_io_status_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_TMRP_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_TMRP_DFX2_tmrp_cfg_io_status_dfx2_START (0)
#define SOC_UFS_HCI_UFS_TMRP_DFX2_tmrp_cfg_io_status_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prdt_cfg_status_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_PRDT_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_PRDT_DFX0_prdt_cfg_status_dfx0_START (0)
#define SOC_UFS_HCI_UFS_PRDT_DFX0_prdt_cfg_status_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prdt_cfg_status_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_PRDT_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_PRDT_DFX1_prdt_cfg_status_dfx1_START (0)
#define SOC_UFS_HCI_UFS_PRDT_DFX1_prdt_cfg_status_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prdt_cfg_status_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_PRDT_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_PRDT_DFX2_prdt_cfg_status_dfx2_START (0)
#define SOC_UFS_HCI_UFS_PRDT_DFX2_prdt_cfg_status_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_cfg_status_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_DFX0_dma0_cfg_status_dfx0_START (0)
#define SOC_UFS_HCI_UFS_DMA0_DFX0_dma0_cfg_status_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_cfg_status_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_DFX1_dma0_cfg_status_dfx1_START (0)
#define SOC_UFS_HCI_UFS_DMA0_DFX1_dma0_cfg_status_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trp_0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_TRP_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_DFX0_dfx_trp_0_START (0)
#define SOC_UFS_HCI_UFS_TRP_DFX0_dfx_trp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trp_1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_TRP_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_DFX1_dfx_trp_1_START (0)
#define SOC_UFS_HCI_UFS_TRP_DFX1_dfx_trp_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trp_2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_TRP_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_DFX2_dfx_trp_2_START (0)
#define SOC_UFS_HCI_UFS_TRP_DFX2_dfx_trp_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trp_3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_TRP_DFX3_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_DFX3_dfx_trp_3_START (00)
#define SOC_UFS_HCI_UFS_TRP_DFX3_dfx_trp_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trp_4 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_UFS_HCI_UFS_TRP_DFX4_UNION;
#endif
#define SOC_UFS_HCI_UFS_TRP_DFX4_dfx_trp_4_START (00)
#define SOC_UFS_HCI_UFS_TRP_DFX4_dfx_trp_4_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_tx_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_TX_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_TX_DFX0_utp_tx_dfx0_START (0)
#define SOC_UFS_HCI_UFS_UTP_TX_DFX0_utp_tx_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_tx_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_TX_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_TX_DFX1_utp_tx_dfx1_START (0)
#define SOC_UFS_HCI_UFS_UTP_TX_DFX1_utp_tx_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_tx_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_TX_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_TX_DFX2_utp_tx_dfx2_START (0)
#define SOC_UFS_HCI_UFS_UTP_TX_DFX2_utp_tx_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int upiu_send_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_UPIU_SEND_NUM_UNION;
#endif
#define SOC_UFS_HCI_UFS_UPIU_SEND_NUM_upiu_send_num_START (00)
#define SOC_UFS_HCI_UFS_UPIU_SEND_NUM_upiu_send_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX0_utp_rx_dfx0_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX0_utp_rx_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX1_utp_rx_dfx1_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX1_utp_rx_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX2_utp_rx_dfx2_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX2_utp_rx_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx3 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX3_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX3_utp_rx_dfx3_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX3_utp_rx_dfx3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx4 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX4_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX4_utp_rx_dfx4_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX4_utp_rx_dfx4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_norm_stat_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_NORM_NUM_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_NORM_NUM_utp_rx_norm_stat_num_START (00)
#define SOC_UFS_HCI_UFS_UTP_RX_NORM_NUM_utp_rx_norm_stat_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_disc_stat_num : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DISC_NUM_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DISC_NUM_utp_rx_disc_stat_num_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DISC_NUM_utp_rx_disc_stat_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int utp_rx_dfx5 : 32;
    } reg;
} SOC_UFS_HCI_UFS_UTP_RX_DFX5_UNION;
#endif
#define SOC_UFS_HCI_UFS_UTP_RX_DFX5_utp_rx_dfx5_START (0)
#define SOC_UFS_HCI_UFS_UTP_RX_DFX5_utp_rx_dfx5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX0_dma1_tx_dfx0_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX0_dma1_tx_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX1_dma1_tx_dfx1_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX1_dma1_tx_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX2_dma1_tx_dfx2_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX2_dma1_tx_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_dfx3 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_DFX3_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX3_dma1_tx_dfx3_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_DFX3_dma1_tx_dfx3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_DFX0_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX0_dma1_rx_dfx0_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX0_dma1_rx_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_DFX1_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX1_dma1_rx_dfx1_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX1_dma1_rx_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_DFX2_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX2_dma1_rx_dfx2_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX2_dma1_rx_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_dfx3 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_DFX3_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX3_dma1_rx_dfx3_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX3_dma1_rx_dfx3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_axi_err_addrl : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRL_dma1_rx_axi_err_addrl_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRL_dma1_rx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_rx_axi_err_addru : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRU_dma1_rx_axi_err_addru_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_AXI_ERR_ADDRU_dma1_rx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_axi_err_addrl : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRL_dma1_tx_axi_err_addrl_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRL_dma1_tx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma1_tx_axi_err_addru : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRU_dma1_tx_axi_err_addru_START (0)
#define SOC_UFS_HCI_UFS_DMA1_TX_AXI_ERR_ADDRU_dma1_tx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WR_DFX_CTRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WR_DFX_CTRL_mst_dfx_wr_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_DFX_CTRL_mst_dfx_wr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr_latcy_avg : 16;
        unsigned int mst_dfx_wr_latcy_max : 16;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_mst_dfx_wr_latcy_avg_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_mst_dfx_wr_latcy_avg_END (15)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_mst_dfx_wr_latcy_max_START (16)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_LACTY_CNT_mst_dfx_wr_latcy_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr_acc : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WR_ACC_CNT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WR_ACC_CNT_mst_dfx_wr_acc_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_ACC_CNT_mst_dfx_wr_acc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr_otd_low : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_LOW_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_LOW_mst_dfx_wr_otd_low_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_LOW_mst_dfx_wr_otd_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr_otd_hig : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_HIG_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_HIG_mst_dfx_wr_otd_hig_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WR_OTD_HIG_mst_dfx_wr_otd_hig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_rd : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_RD_DFX_CTRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_RD_DFX_CTRL_mst_dfx_rd_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_DFX_CTRL_mst_dfx_rd_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_rd_latcy_avg : 16;
        unsigned int mst_dfx_rd_latcy_max : 16;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_mst_dfx_rd_latcy_avg_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_mst_dfx_rd_latcy_avg_END (15)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_mst_dfx_rd_latcy_max_START (16)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_LACTY_CNT_mst_dfx_rd_latcy_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_rd_acc : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_RD_ACC_CNT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_RD_ACC_CNT_mst_dfx_rd_acc_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_ACC_CNT_mst_dfx_rd_acc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_rd_otd_low : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_LOW_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_LOW_mst_dfx_rd_otd_low_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_LOW_mst_dfx_rd_otd_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_rd_otd_hig : 32;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_HIG_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_HIG_mst_dfx_rd_otd_hig_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_RD_OTD_HIG_mst_dfx_rd_otd_hig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufc_wid_m : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_WID_OUT_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_WID_OUT_ufc_wid_m_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_WID_OUT_ufc_wid_m_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_rx_axi_err_addrl : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRL_dma0_rx_axi_err_addrl_START (0)
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRL_dma0_rx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_rx_axi_err_addru : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRU_dma0_rx_axi_err_addru_START (0)
#define SOC_UFS_HCI_UFS_DMA0_RX_AXI_ERR_ADDRU_dma0_rx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_tx_axi_err_addrl : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRL_dma0_tx_axi_err_addrl_START (0)
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRL_dma0_tx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma0_tx_axi_err_addru : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRU_dma0_tx_axi_err_addru_START (0)
#define SOC_UFS_HCI_UFS_DMA0_TX_AXI_ERR_ADDRU_dma0_tx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fw_prdt_sram_rd_req : 1;
        unsigned int fw_prdt_sram_rd_addr : 11;
        unsigned int reserved : 20;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_fw_prdt_sram_rd_req_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_fw_prdt_sram_rd_req_END (0)
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_fw_prdt_sram_rd_addr_START (1)
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_CFG_DFX_fw_prdt_sram_rd_addr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_prdt_sram_rd_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_REQ_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_REQ_DFX_cfg_prdt_sram_rd_req_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_REQ_DFX_cfg_prdt_sram_rd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fw_prdt_sram_rd_data : 32;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_DATA_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_DATA_DFX_fw_prdt_sram_rd_data_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_PRDT_SRAM_DATA_DFX_fw_prdt_sram_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fw_trp_sram_rd_req : 1;
        unsigned int fw_trp_sram_wt_req : 1;
        unsigned int fw_trp_sram_wr_addr : 14;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_rd_req_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_rd_req_END (0)
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_wt_req_START (1)
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_wt_req_END (1)
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_wr_addr_START (2)
#define SOC_UFS_HCI_UFS_FW_RD_WT_TRP_SRAM_CFG_DFX_fw_trp_sram_wr_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trp_sram_rd_req : 1;
        unsigned int cfg_trp_sram_wt_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_cfg_trp_sram_rd_req_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_cfg_trp_sram_rd_req_END (0)
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_cfg_trp_sram_wt_req_START (1)
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_REQ_DFX_cfg_trp_sram_wt_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_ctx_wdata : 32;
    } reg;
} SOC_UFS_HCI_UFS_FW_WT_TRP_SRAM_DATA_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_WT_TRP_SRAM_DATA_DFX_cfg_ctx_wdata_START (0)
#define SOC_UFS_HCI_UFS_FW_WT_TRP_SRAM_DATA_DFX_cfg_ctx_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fw_trp_sram_rd_data : 32;
    } reg;
} SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_DATA_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_DATA_DFX_fw_trp_sram_rd_data_START (0)
#define SOC_UFS_HCI_UFS_FW_RD_TRP_SRAM_DATA_DFX_fw_trp_sram_rd_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_dma1_rx_dfx4 : 32;
    } reg;
} SOC_UFS_HCI_UFS_DMA1_RX_DFX4_UNION;
#endif
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX4_ufs_dma1_rx_dfx4_START (0)
#define SOC_UFS_HCI_UFS_DMA1_RX_DFX4_ufs_dma1_rx_dfx4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_dfx_wr_acc_clr : 1;
        unsigned int mst_dfx_wr_latcy_clr : 1;
        unsigned int mst_dfx_rd_acc_clr : 1;
        unsigned int mst_dfx_rd_latcy_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_UNION;
#endif
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_wr_acc_clr_START (0)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_wr_acc_clr_END (0)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_wr_latcy_clr_START (1)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_wr_latcy_clr_END (1)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_rd_acc_clr_START (2)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_rd_acc_clr_END (2)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_rd_latcy_clr_START (3)
#define SOC_UFS_HCI_UFS_AXI_MST_DFX_CLR_mst_dfx_rd_latcy_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_mcore_arb_dfx : 32;
    } reg;
} SOC_UFS_HCI_TRP_MCORE_ARB_DFX_UNION;
#endif
#define SOC_UFS_HCI_TRP_MCORE_ARB_DFX_trp_mcore_arb_dfx_START (0)
#define SOC_UFS_HCI_TRP_MCORE_ARB_DFX_trp_mcore_arb_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_dbr_dfx : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_DBR_DFX_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_DBR_DFX_trp_marb_dbr_dfx_START (0)
#define SOC_UFS_HCI_TRP_MARB_DBR_DFX_trp_marb_dbr_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_dbr_new_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX0_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX0_trp_marb_dbr_new_dfx0_START (0)
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX0_trp_marb_dbr_new_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_dbr_new_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX1_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX1_trp_marb_dbr_new_dfx1_START (0)
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX1_trp_marb_dbr_new_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_dbr_new_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX2_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX2_trp_marb_dbr_new_dfx2_START (0)
#define SOC_UFS_HCI_TRP_MARB_DBR_NEW_DFX2_trp_marb_dbr_new_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_clr_msk_dfx0 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX0_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX0_trp_marb_clr_msk_dfx0_START (0)
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX0_trp_marb_clr_msk_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_clr_msk_dfx1 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX1_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX1_trp_marb_clr_msk_dfx1_START (0)
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX1_trp_marb_clr_msk_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trp_marb_clr_msk_dfx2 : 32;
    } reg;
} SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX2_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX2_trp_marb_clr_msk_dfx2_START (0)
#define SOC_UFS_HCI_TRP_MARB_CLR_MSK_DFX2_trp_marb_clr_msk_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_0_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_1_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_marb_utrldbr_0_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_marb_utrldbr_0_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_marb_utrldbr_1_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_1_0_MSG_marb_utrldbr_1_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_2_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_3_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_marb_utrldbr_2_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_marb_utrldbr_2_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_marb_utrldbr_3_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_3_2_MSG_marb_utrldbr_3_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_4_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_5_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_marb_utrldbr_4_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_marb_utrldbr_4_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_marb_utrldbr_5_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_5_4_MSG_marb_utrldbr_5_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_6_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_7_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_marb_utrldbr_6_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_marb_utrldbr_6_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_marb_utrldbr_7_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_7_6_MSG_marb_utrldbr_7_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_8_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_9_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_marb_utrldbr_8_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_marb_utrldbr_8_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_marb_utrldbr_9_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_9_8_MSG_marb_utrldbr_9_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_10_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_11_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_marb_utrldbr_10_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_marb_utrldbr_10_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_marb_utrldbr_11_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_11_10_MSG_marb_utrldbr_11_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_12_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_13_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_marb_utrldbr_12_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_marb_utrldbr_12_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_marb_utrldbr_13_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_13_12_MSG_marb_utrldbr_13_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_14_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_15_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_marb_utrldbr_14_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_marb_utrldbr_14_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_marb_utrldbr_15_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_15_14_MSG_marb_utrldbr_15_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_16_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_17_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_marb_utrldbr_16_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_marb_utrldbr_16_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_marb_utrldbr_17_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_17_16_MSG_marb_utrldbr_17_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_18_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_19_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_marb_utrldbr_18_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_marb_utrldbr_18_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_marb_utrldbr_19_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_19_18_MSG_marb_utrldbr_19_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_20_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_21_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_marb_utrldbr_20_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_marb_utrldbr_20_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_marb_utrldbr_21_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_21_20_MSG_marb_utrldbr_21_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_22_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_23_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_marb_utrldbr_22_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_marb_utrldbr_22_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_marb_utrldbr_23_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_23_22_MSG_marb_utrldbr_23_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_24_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_25_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_marb_utrldbr_24_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_marb_utrldbr_24_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_marb_utrldbr_25_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_25_24_MSG_marb_utrldbr_25_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_26_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_27_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_marb_utrldbr_26_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_marb_utrldbr_26_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_marb_utrldbr_27_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_27_26_MSG_marb_utrldbr_27_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_28_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_29_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_marb_utrldbr_28_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_marb_utrldbr_28_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_marb_utrldbr_29_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_29_28_MSG_marb_utrldbr_29_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int marb_utrldbr_30_msg : 13;
        unsigned int reserved_0 : 3;
        unsigned int marb_utrldbr_31_msg : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_UNION;
#endif
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_marb_utrldbr_30_msg_START (00)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_marb_utrldbr_30_msg_END (12)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_marb_utrldbr_31_msg_START (16)
#define SOC_UFS_HCI_TRP_MARB_UTRLDBR_31_30_MSG_marb_utrldbr_31_msg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_utrldbr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_CORE_UTRLDBR_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_UTRLDBR_ufs_core_utrldbr_START (0)
#define SOC_UFS_HCI_UFS_CORE_UTRLDBR_ufs_core_utrldbr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_utrlclr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_CORE_UTRLCLR_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_UTRLCLR_ufs_core_utrlclr_START (0)
#define SOC_UFS_HCI_UFS_CORE_UTRLCLR_ufs_core_utrlclr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ufs_core_utrlcnr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_CORE_UTRLCNR_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_UTRLCNR_ufs_core_utrlcnr_START (0)
#define SOC_UFS_HCI_UFS_CORE_UTRLCNR_ufs_core_utrlcnr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_cmd_proc_timeout : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_CORE_TR_TIMEOUT_STATUS_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_TR_TIMEOUT_STATUS_core_cmd_proc_timeout_START (00)
#define SOC_UFS_HCI_UFS_CORE_TR_TIMEOUT_STATUS_core_cmd_proc_timeout_END (07)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_utr_otsd_dbr_dfx : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_HCI_UFS_CORE_UTR_OTSD_DBR_DFX_UNION;
#endif
#define SOC_UFS_HCI_UFS_CORE_UTR_OTSD_DBR_DFX_core_utr_otsd_dbr_dfx_START (00)
#define SOC_UFS_HCI_UFS_CORE_UTR_OTSD_DBR_DFX_core_utr_otsd_dbr_dfx_END (07)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
