#ifndef __SOC_DDRC_DMC_INTERFACE_H__
#define __SOC_DDRC_DMC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_ADDR(base) ((base) + (0x000UL))
#define SOC_DDRC_DMC_DDRC_CTRL_INIT_ADDR(base) ((base) + (0x004UL))
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_ADDR(base) ((base) + (0x008UL))
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_ADDR(base) ((base) + (0x00CUL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_ADDR(base) ((base) + (0x01CUL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_ADDR(base) ((base) + (0x020UL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_ADDR(base) ((base) + (0x024UL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_ADDR(base) ((base) + (0x028UL))
#define SOC_DDRC_DMC_DDRC_CFG_LP0_ADDR(base) ((base) + (0x030UL))
#define SOC_DDRC_DMC_DDRC_CFG_LP1_ADDR(base) ((base) + (0x034UL))
#define SOC_DDRC_DMC_DDRC_CFG_LP2_ADDR(base) ((base) + (0x038UL))
#define SOC_DDRC_DMC_DDRC_CFG_LP3_ADDR(base) ((base) + (0x03CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SREF_ADDR(base) ((base) + (0x040UL))
#define SOC_DDRC_DMC_DDRC_CFG_PD_ADDR(base) ((base) + (0x048UL))
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_ADDR(base) ((base) + (0x050UL))
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_ADDR(base) ((base) + (0x054UL))
#define SOC_DDRC_DMC_DDRC_CFG_PBR_ADDR(base) ((base) + (0x058UL))
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_ADDR(base) ((base) + (0x060UL))
#define SOC_DDRC_DMC_DDRC_CFG_RH_ADDR(base) ((base) + (0x064UL))
#define SOC_DDRC_DMC_DDRC_CFG_RH1_ADDR(base) ((base) + (0x068UL))
#define SOC_DDRC_DMC_DDRC_CFG_RH2_ADDR(base) ((base) + (0x06cUL))
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_ADDR(base) ((base) + (0x070UL))
#define SOC_DDRC_DMC_DDRC_CFG_OSC1_ADDR(base) ((base) + (0x074UL))
#define SOC_DDRC_DMC_DDRC_CFG_OSC2_ADDR(base) ((base) + (0x078UL))
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ADDR(base) ((base) + (0x080UL))
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_ADDR(base) ((base) + (0x084UL))
#define SOC_DDRC_DMC_DDRC_CFG_TMON_ADDR(base) ((base) + (0x090UL))
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_ADDR(base) ((base) + (0x094UL))
#define SOC_DDRC_DMC_DDRC_CFG_REC0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_DDRC_DMC_DDRC_CFG_REC1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_DDRC_DMC_DDRC_CFG_REC2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_DDRC_DMC_DDRC_CFG_REC3_ADDR(base) ((base) + (0x0ACUL))
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_ADDR(base) ((base) + (0x0C0UL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_ADDR(base) ((base) + (0x100UL))
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_ADDR(base,grps) ((base) + (0x110+0x4*(grps)))
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_ADDR(base) ((base) + (0x120UL))
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_ADDR(base) ((base) + (0x124UL))
#define SOC_DDRC_DMC_DDRC_CFG_FSP_OP_ADDR(base) ((base) + (0x128UL))
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_ADDR(base) ((base) + (0x12CUL))
#define SOC_DDRC_DMC_DDRC_CFG_OFREQ_ADDR(base) ((base) + (0x130UL))
#define SOC_DDRC_DMC_DDRC_CFG_DMCLVL_ADDR(base) ((base) + (0x140UL))
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_ADDR(base) ((base) + (0x144UL))
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT1_ADDR(base) ((base) + (0x148UL))
#define SOC_DDRC_DMC_DDRC_CFG_QOS_ADDR(base) ((base) + (0x14CUL))
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_ADDR(base) ((base) + (0x154UL))
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_ADDR(base) ((base) + (0x15CUL))
#define SOC_DDRC_DMC_DDRC_CFG_PAGE1_ADDR(base) ((base) + (0x160UL))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_ADDR(base) ((base) + (0x168UL))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_ADDR(base) ((base) + (0x16CUL))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_ADDR(base) ((base) + (0x170UL))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_ADDR(base) ((base) + (0x174UL))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_ADDR(base) ((base) + (0x178UL))
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_ADDR(base) ((base) + (0x180UL))
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_ADDR(base) ((base) + (0x1A0UL))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT0_ADDR(base) ((base) + (0x1A4UL))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_ADDR(base) ((base) + (0x1ACUL))
#define SOC_DDRC_DMC_DDRC_CFG_PHY_DLY_ADDR(base) ((base) + (0x1B4UL))
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_ADDR(base,rnks) ((base) + (0x1C0+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_CFG_ODT_ADDR(base) ((base) + (0x1E0UL))
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_ADDR(base) ((base) + (0x1E4UL))
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_ADDR(base) ((base) + (0x1E8UL))
#define SOC_DDRC_DMC_DDRC_CFG_CA_ADDR(base) ((base) + (0x200UL))
#define SOC_DDRC_DMC_DDRC_CA_KEY0_ADDR(base) ((base) + (0x204UL))
#define SOC_DDRC_DMC_DDRC_CA_KEY1_ADDR(base) ((base) + (0x208UL))
#define SOC_DDRC_DMC_DDRC_RST_RINT_ADDR(base) ((base) + (0x210UL))
#define SOC_DDRC_DMC_DDRC_RST_INTSTS_ADDR(base) ((base) + (0x214UL))
#define SOC_DDRC_DMC_DDRC_CFG_EPS_RD_ADDR(base) ((base) + (0x21cUL))
#define SOC_DDRC_DMC_DDRC_CFG_EPS_WR_ADDR(base) ((base) + (0x220UL))
#define SOC_DDRC_DMC_DDRC_EPS_KEY0_ADDR(base) ((base) + (0x224UL))
#define SOC_DDRC_DMC_DDRC_EPS_KEY1_ADDR(base) ((base) + (0x228UL))
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_ADDR(base) ((base) + (0x22CUL))
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_ADDR(base) ((base) + (0x240UL))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ADDR(base) ((base) + (0x244UL))
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_ADDR(base) ((base) + (0x248UL))
#define SOC_DDRC_DMC_DDRC_CFG_ECC_ADDR(base) ((base) + (0x260UL))
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_ADDR(base) ((base) + (0x270UL))
#define SOC_DDRC_DMC_DDRC_CFG_DBI_ADDR(base) ((base) + (0x274UL))
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_ADDR(base) ((base) + (0x278UL))
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_ADDR(base) ((base) + (0x27CUL))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ADDR(base) ((base) + (0x280UL))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_ADDR(base) ((base) + (0x284UL))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_ADDR(base) ((base) + (0x288UL))
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_ADDR(base,blanes) ((base) + (0x290+0x8*(blanes)))
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_ADDR(base,blanes) ((base) + (0x294+0x8*(blanes)))
#define SOC_DDRC_DMC_DDRC_CFG_DDR5_TMP_ADDR(base) ((base) + (0x2F0UL))
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_ADDR(base) ((base) + (0x2F4UL))
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_ADDR(base) ((base) + (0x2F8UL))
#else
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_ADDR(base) ((base) + (0x000))
#define SOC_DDRC_DMC_DDRC_CTRL_INIT_ADDR(base) ((base) + (0x004))
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_ADDR(base) ((base) + (0x008))
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_ADDR(base) ((base) + (0x00C))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_ADDR(base) ((base) + (0x01C))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_ADDR(base) ((base) + (0x020))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_ADDR(base) ((base) + (0x024))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_ADDR(base) ((base) + (0x028))
#define SOC_DDRC_DMC_DDRC_CFG_LP0_ADDR(base) ((base) + (0x030))
#define SOC_DDRC_DMC_DDRC_CFG_LP1_ADDR(base) ((base) + (0x034))
#define SOC_DDRC_DMC_DDRC_CFG_LP2_ADDR(base) ((base) + (0x038))
#define SOC_DDRC_DMC_DDRC_CFG_LP3_ADDR(base) ((base) + (0x03C))
#define SOC_DDRC_DMC_DDRC_CFG_SREF_ADDR(base) ((base) + (0x040))
#define SOC_DDRC_DMC_DDRC_CFG_PD_ADDR(base) ((base) + (0x048))
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_ADDR(base) ((base) + (0x050))
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_ADDR(base) ((base) + (0x054))
#define SOC_DDRC_DMC_DDRC_CFG_PBR_ADDR(base) ((base) + (0x058))
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_ADDR(base) ((base) + (0x060))
#define SOC_DDRC_DMC_DDRC_CFG_RH_ADDR(base) ((base) + (0x064))
#define SOC_DDRC_DMC_DDRC_CFG_RH1_ADDR(base) ((base) + (0x068))
#define SOC_DDRC_DMC_DDRC_CFG_RH2_ADDR(base) ((base) + (0x06c))
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_ADDR(base) ((base) + (0x070))
#define SOC_DDRC_DMC_DDRC_CFG_OSC1_ADDR(base) ((base) + (0x074))
#define SOC_DDRC_DMC_DDRC_CFG_OSC2_ADDR(base) ((base) + (0x078))
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ADDR(base) ((base) + (0x080))
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_ADDR(base) ((base) + (0x084))
#define SOC_DDRC_DMC_DDRC_CFG_TMON_ADDR(base) ((base) + (0x090))
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_ADDR(base) ((base) + (0x094))
#define SOC_DDRC_DMC_DDRC_CFG_REC0_ADDR(base) ((base) + (0x0A0))
#define SOC_DDRC_DMC_DDRC_CFG_REC1_ADDR(base) ((base) + (0x0A4))
#define SOC_DDRC_DMC_DDRC_CFG_REC2_ADDR(base) ((base) + (0x0A8))
#define SOC_DDRC_DMC_DDRC_CFG_REC3_ADDR(base) ((base) + (0x0AC))
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_ADDR(base) ((base) + (0x0C0))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_ADDR(base) ((base) + (0x100))
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_ADDR(base,grps) ((base) + (0x110+0x4*(grps)))
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_ADDR(base) ((base) + (0x120))
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_ADDR(base) ((base) + (0x124))
#define SOC_DDRC_DMC_DDRC_CFG_FSP_OP_ADDR(base) ((base) + (0x128))
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_ADDR(base) ((base) + (0x12C))
#define SOC_DDRC_DMC_DDRC_CFG_OFREQ_ADDR(base) ((base) + (0x130))
#define SOC_DDRC_DMC_DDRC_CFG_DMCLVL_ADDR(base) ((base) + (0x140))
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_ADDR(base) ((base) + (0x144))
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT1_ADDR(base) ((base) + (0x148))
#define SOC_DDRC_DMC_DDRC_CFG_QOS_ADDR(base) ((base) + (0x14C))
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_ADDR(base) ((base) + (0x154))
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_ADDR(base) ((base) + (0x15C))
#define SOC_DDRC_DMC_DDRC_CFG_PAGE1_ADDR(base) ((base) + (0x160))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_ADDR(base) ((base) + (0x168))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_ADDR(base) ((base) + (0x16C))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_ADDR(base) ((base) + (0x170))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_ADDR(base) ((base) + (0x174))
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_ADDR(base) ((base) + (0x178))
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_ADDR(base) ((base) + (0x180))
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_ADDR(base) ((base) + (0x1A0))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT0_ADDR(base) ((base) + (0x1A4))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_ADDR(base) ((base) + (0x1AC))
#define SOC_DDRC_DMC_DDRC_CFG_PHY_DLY_ADDR(base) ((base) + (0x1B4))
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_ADDR(base,rnks) ((base) + (0x1C0+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_CFG_ODT_ADDR(base) ((base) + (0x1E0))
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_ADDR(base) ((base) + (0x1E4))
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_ADDR(base) ((base) + (0x1E8))
#define SOC_DDRC_DMC_DDRC_CFG_CA_ADDR(base) ((base) + (0x200))
#define SOC_DDRC_DMC_DDRC_CA_KEY0_ADDR(base) ((base) + (0x204))
#define SOC_DDRC_DMC_DDRC_CA_KEY1_ADDR(base) ((base) + (0x208))
#define SOC_DDRC_DMC_DDRC_RST_RINT_ADDR(base) ((base) + (0x210))
#define SOC_DDRC_DMC_DDRC_RST_INTSTS_ADDR(base) ((base) + (0x214))
#define SOC_DDRC_DMC_DDRC_CFG_EPS_RD_ADDR(base) ((base) + (0x21c))
#define SOC_DDRC_DMC_DDRC_CFG_EPS_WR_ADDR(base) ((base) + (0x220))
#define SOC_DDRC_DMC_DDRC_EPS_KEY0_ADDR(base) ((base) + (0x224))
#define SOC_DDRC_DMC_DDRC_EPS_KEY1_ADDR(base) ((base) + (0x228))
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_ADDR(base) ((base) + (0x22C))
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_ADDR(base) ((base) + (0x240))
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ADDR(base) ((base) + (0x244))
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_ADDR(base) ((base) + (0x248))
#define SOC_DDRC_DMC_DDRC_CFG_ECC_ADDR(base) ((base) + (0x260))
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_ADDR(base) ((base) + (0x270))
#define SOC_DDRC_DMC_DDRC_CFG_DBI_ADDR(base) ((base) + (0x274))
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_ADDR(base) ((base) + (0x278))
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_ADDR(base) ((base) + (0x27C))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ADDR(base) ((base) + (0x280))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_ADDR(base) ((base) + (0x284))
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_ADDR(base) ((base) + (0x288))
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_ADDR(base,blanes) ((base) + (0x290+0x8*(blanes)))
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_ADDR(base,blanes) ((base) + (0x294+0x8*(blanes)))
#define SOC_DDRC_DMC_DDRC_CFG_DDR5_TMP_ADDR(base) ((base) + (0x2F0))
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_ADDR(base) ((base) + (0x2F4))
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_ADDR(base) ((base) + (0x2F8))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_ADDR(base,fsps) ((base) + (0x300+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_ADDR(base,fsps) ((base) + (0x304+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_ADDR(base,fsps) ((base) + (0x308+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_ADDR(base,fsps) ((base) + (0x30c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_ADDR(base,fsps) ((base) + (0x310+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_ADDR(base,fsps) ((base) + (0x314+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_ADDR(base,fsps) ((base) + (0x318+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_ADDR(base,fsps) ((base) + (0x31c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_ADDR(base,fsps) ((base) + (0x320+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_ADDR(base,fsps) ((base) + (0x324+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_ADDR(base,fsps) ((base) + (0x328+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_ADDR(base,fsps) ((base) + (0x32c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_ADDR(base,fsps) ((base) + (0x330+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_ADDR(base,fsps) ((base) + (0x334+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_ADDR(base,fsps) ((base) + (0x338+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_ADDR(base,fsps) ((base) + (0x33c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_ADDR(base,fsps) ((base) + (0x340+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_ADDR(base,fsps) ((base) + (0x344+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_ADDR(base,fsps) ((base) + (0x348+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_ADDR(base,fsps) ((base) + (0x34c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_ADDR(base,fsps) ((base) + (0x350+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_ADDR(base,fsps) ((base) + (0x354+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_ADDR(base,fsps) ((base) + (0x358+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_ADDR(base,fsps) ((base) + (0x35c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_ADDR(base,fsps) ((base) + (0x360+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ADDR(base,fsps) ((base) + (0x364+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_ADDR(base,fsps) ((base) + (0x368+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_ADDR(base,fsps) ((base) + (0x36c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ADDR(base,fsps) ((base) + (0x370+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ADDR(base,fsps) ((base) + (0x374+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_ADDR(base,fsps) ((base) + (0x378+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_ADDR(base,fsps) ((base) + (0x37c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_ADDR(base,fsps) ((base) + (0x380+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_ADDR(base,fsps) ((base) + (0x384+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_ADDR(base,fsps) ((base) + (0x388+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_INTMSK0_ADDR(base) ((base) + (0x500UL))
#define SOC_DDRC_DMC_DDRC_INTMSK1_ADDR(base) ((base) + (0x504UL))
#define SOC_DDRC_DMC_DDRC_RINT0_ADDR(base) ((base) + (0x508UL))
#define SOC_DDRC_DMC_DDRC_RINT1_ADDR(base) ((base) + (0x50CUL))
#define SOC_DDRC_DMC_DDRC_INTSTS0_ADDR(base) ((base) + (0x510UL))
#define SOC_DDRC_DMC_DDRC_INTSTS1_ADDR(base) ((base) + (0x514UL))
#define SOC_DDRC_DMC_DDRC_INTMSK2_ADDR(base) ((base) + (0x518UL))
#define SOC_DDRC_DMC_DDRC_RINT2_ADDR(base) ((base) + (0x51CUL))
#define SOC_DDRC_DMC_DDRC_INTSTS2_ADDR(base) ((base) + (0x520UL))
#define SOC_DDRC_DMC_DDRC_CTRL_SFC_ADDR(base) ((base) + (0x530UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR(base) ((base) + (0x534UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_ADDR(base) ((base) + (0x538UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR0_ADDR(base) ((base) + (0x53CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR1_ADDR(base) ((base) + (0x540UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_ADDR(base) ((base) + (0x544UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_ADDR(base) ((base) + (0x548UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WDATA_ADDR(base) ((base) + (0x54CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WCTRL_ADDR(base) ((base) + (0x550UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK0_ADDR(base) ((base) + (0x554UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK1_ADDR(base) ((base) + (0x558UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_ADDR(base) ((base) + (0x55CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_ADDR(base) ((base) + (0x560UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_ADDR(base) ((base) + (0x564UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ADDR(base) ((base) + (0x580UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_RCTRL_ADDR(base) ((base) + (0x584UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA0_DBI_ADDR(base) ((base) + (0x588UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA1_DBI_ADDR(base) ((base) + (0x58CUL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_ADDR(base) ((base) + (0x590UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD0_ADDR(base) ((base) + (0x594UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD1_ADDR(base) ((base) + (0x598UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_ADDR(base) ((base) + (0x600UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_LOOP_CTRL_ADDR(base) ((base) + (0x604UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_BER_RD_RPT_ADDR(base) ((base) + (0x608UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_ADDR(base) ((base) + (0x60CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_ADDR(base) ((base) + (0x610UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_ADDR(base) ((base) + (0x614UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_ADDR(base) ((base) + (0x620UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_PTR_ADDR(base) ((base) + (0x624UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_ADDR(base) ((base) + (0x628UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_PTR_ADDR(base) ((base) + (0x62CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED_ADDR(base) ((base) + (0x634UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED1_ADDR(base) ((base) + (0x638UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED2_ADDR(base) ((base) + (0x63CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED3_ADDR(base) ((base) + (0x640UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED4_ADDR(base) ((base) + (0x644UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED5_ADDR(base) ((base) + (0x648UL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED6_ADDR(base) ((base) + (0x64CUL))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED7_ADDR(base) ((base) + (0x650UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_0_ADDR(base) ((base) + (0x654UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_1_ADDR(base) ((base) + (0x658UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_2_ADDR(base) ((base) + (0x65CUL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_0_ADDR(base) ((base) + (0x660UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_1_ADDR(base) ((base) + (0x664UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_2_ADDR(base) ((base) + (0x668UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_NIB_ERR_ADDR(base) ((base) + (0x66CUL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_BYTE_ERR_ADDR(base) ((base) + (0x670UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ANY_ERR_ADDR(base) ((base) + (0x674UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_ADDR(base) ((base) + (0x678UL))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ERR_NUM_ADDR(base) ((base) + (0x67CUL))
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PAT_ADDR(base) ((base) + (0x680UL))
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PTR_ADDR(base) ((base) + (0x684UL))
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_ADDR(base) ((base) + (0x68CUL))
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ADDR(base) ((base) + (0x6B0UL))
#else
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_ADDR(base,fsps) ((base) + (0x300+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_ADDR(base,fsps) ((base) + (0x304+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_ADDR(base,fsps) ((base) + (0x308+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_ADDR(base,fsps) ((base) + (0x30c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_ADDR(base,fsps) ((base) + (0x310+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_ADDR(base,fsps) ((base) + (0x314+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_ADDR(base,fsps) ((base) + (0x318+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_ADDR(base,fsps) ((base) + (0x31c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_ADDR(base,fsps) ((base) + (0x320+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_ADDR(base,fsps) ((base) + (0x324+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_ADDR(base,fsps) ((base) + (0x328+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_ADDR(base,fsps) ((base) + (0x32c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_ADDR(base,fsps) ((base) + (0x330+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_ADDR(base,fsps) ((base) + (0x334+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_ADDR(base,fsps) ((base) + (0x338+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_ADDR(base,fsps) ((base) + (0x33c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_ADDR(base,fsps) ((base) + (0x340+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_ADDR(base,fsps) ((base) + (0x344+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_ADDR(base,fsps) ((base) + (0x348+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_ADDR(base,fsps) ((base) + (0x34c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_ADDR(base,fsps) ((base) + (0x350+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_ADDR(base,fsps) ((base) + (0x354+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_ADDR(base,fsps) ((base) + (0x358+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_ADDR(base,fsps) ((base) + (0x35c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_ADDR(base,fsps) ((base) + (0x360+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ADDR(base,fsps) ((base) + (0x364+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_ADDR(base,fsps) ((base) + (0x368+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_ADDR(base,fsps) ((base) + (0x36c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ADDR(base,fsps) ((base) + (0x370+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ADDR(base,fsps) ((base) + (0x374+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_ADDR(base,fsps) ((base) + (0x378+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_ADDR(base,fsps) ((base) + (0x37c+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_ADDR(base,fsps) ((base) + (0x380+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_ADDR(base,fsps) ((base) + (0x384+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_ADDR(base,fsps) ((base) + (0x388+0xA0*(fsps)))
#define SOC_DDRC_DMC_DDRC_INTMSK0_ADDR(base) ((base) + (0x500))
#define SOC_DDRC_DMC_DDRC_INTMSK1_ADDR(base) ((base) + (0x504))
#define SOC_DDRC_DMC_DDRC_RINT0_ADDR(base) ((base) + (0x508))
#define SOC_DDRC_DMC_DDRC_RINT1_ADDR(base) ((base) + (0x50C))
#define SOC_DDRC_DMC_DDRC_INTSTS0_ADDR(base) ((base) + (0x510))
#define SOC_DDRC_DMC_DDRC_INTSTS1_ADDR(base) ((base) + (0x514))
#define SOC_DDRC_DMC_DDRC_INTMSK2_ADDR(base) ((base) + (0x518))
#define SOC_DDRC_DMC_DDRC_RINT2_ADDR(base) ((base) + (0x51C))
#define SOC_DDRC_DMC_DDRC_INTSTS2_ADDR(base) ((base) + (0x520))
#define SOC_DDRC_DMC_DDRC_CTRL_SFC_ADDR(base) ((base) + (0x530))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR(base) ((base) + (0x534))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_ADDR(base) ((base) + (0x538))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR0_ADDR(base) ((base) + (0x53C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR1_ADDR(base) ((base) + (0x540))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_ADDR(base) ((base) + (0x544))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_ADDR(base) ((base) + (0x548))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WDATA_ADDR(base) ((base) + (0x54C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WCTRL_ADDR(base) ((base) + (0x550))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK0_ADDR(base) ((base) + (0x554))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK1_ADDR(base) ((base) + (0x558))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_ADDR(base) ((base) + (0x55C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_ADDR(base) ((base) + (0x560))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_ADDR(base) ((base) + (0x564))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ADDR(base) ((base) + (0x580))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_RCTRL_ADDR(base) ((base) + (0x584))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA0_DBI_ADDR(base) ((base) + (0x588))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA1_DBI_ADDR(base) ((base) + (0x58C))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_ADDR(base) ((base) + (0x590))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD0_ADDR(base) ((base) + (0x594))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD1_ADDR(base) ((base) + (0x598))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_LOOP_CTRL_ADDR(base) ((base) + (0x604))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_BER_RD_RPT_ADDR(base) ((base) + (0x608))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_ADDR(base) ((base) + (0x60C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_ADDR(base) ((base) + (0x610))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_ADDR(base) ((base) + (0x614))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_ADDR(base) ((base) + (0x620))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_PTR_ADDR(base) ((base) + (0x624))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_ADDR(base) ((base) + (0x628))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_PTR_ADDR(base) ((base) + (0x62C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED_ADDR(base) ((base) + (0x634))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED1_ADDR(base) ((base) + (0x638))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED2_ADDR(base) ((base) + (0x63C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED3_ADDR(base) ((base) + (0x640))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED4_ADDR(base) ((base) + (0x644))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED5_ADDR(base) ((base) + (0x648))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED6_ADDR(base) ((base) + (0x64C))
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED7_ADDR(base) ((base) + (0x650))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_0_ADDR(base) ((base) + (0x654))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_1_ADDR(base) ((base) + (0x658))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_2_ADDR(base) ((base) + (0x65C))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_0_ADDR(base) ((base) + (0x660))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_1_ADDR(base) ((base) + (0x664))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_2_ADDR(base) ((base) + (0x668))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_NIB_ERR_ADDR(base) ((base) + (0x66C))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_BYTE_ERR_ADDR(base) ((base) + (0x670))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ANY_ERR_ADDR(base) ((base) + (0x674))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_ADDR(base) ((base) + (0x678))
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ERR_NUM_ADDR(base) ((base) + (0x67C))
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PAT_ADDR(base) ((base) + (0x680))
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PTR_ADDR(base) ((base) + (0x684))
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_ADDR(base) ((base) + (0x68C))
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ADDR(base) ((base) + (0x6B0))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ADDR_ADDR(base) ((base) + (0x700UL))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_HADDR_ADDR(base) ((base) + (0x704UL))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_ADDR(base) ((base) + (0x708UL))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_ADDR(base) ((base) + (0x70CUL))
#define SOC_DDRC_DMC_DDRC_REF_RATE_ADDR(base) ((base) + (0x720UL))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_ADDR(base) ((base) + (0x724UL))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_ADDR(base) ((base) + (0x728UL))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_ADDR(base) ((base) + (0x72CUL))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_ADDR(base) ((base) + (0x730UL))
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900UL))
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_ADDR(base) ((base) + (0x904UL))
#define SOC_DDRC_DMC_DDRC_CFG_DATMIN_ADDR(base) ((base) + (0x908UL))
#define SOC_DDRC_DMC_DDRC_CFG_DATMAX_ADDR(base) ((base) + (0x90CUL))
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_ADDR(base) ((base) + (0x910UL))
#define SOC_DDRC_DMC_DDRC_CFG_DAT_SCMAX_ADDR(base) ((base) + (0x914UL))
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918UL))
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_ADDR(base) ((base) + (0x91CUL))
#define SOC_DDRC_DMC_DDRC_CFG_CMDMIN_ADDR(base) ((base) + (0x920UL))
#define SOC_DDRC_DMC_DDRC_CFG_CMDMAX_ADDR(base) ((base) + (0x924UL))
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_ADDR(base) ((base) + (0x928UL))
#define SOC_DDRC_DMC_DDRC_CFG_CMD_SCMAX_ADDR(base) ((base) + (0x92CUL))
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_ADDR(base) ((base) + (0x930UL))
#define SOC_DDRC_DMC_DDRC_CFG_PERF_ADDR(base) ((base) + (0x934UL))
#define SOC_DDRC_DMC_DDRC_CFG_STAID_ADDR(base) ((base) + (0x938UL))
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_ADDR(base) ((base) + (0x93CUL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WR_ADDR(base) ((base) + (0x940UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RD_ADDR(base) ((base) + (0x944UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WCMD_ADDR(base) ((base) + (0x948UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RCMD_ADDR(base) ((base) + (0x94CUL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WR_ADDR(base) ((base) + (0x950UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RD_ADDR(base) ((base) + (0x954UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WCMD_ADDR(base) ((base) + (0x958UL))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RCMD_ADDR(base) ((base) + (0x95CUL))
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_ADDR(base) ((base) + (0x960UL))
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT1_ADDR(base) ((base) + (0x964UL))
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_ADDR(base) ((base) + (0x968UL))
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT1_ADDR(base) ((base) + (0x96CUL))
#define SOC_DDRC_DMC_DDRC_HIS_INHERE_RLAT_CNT_ADDR(base) ((base) + (0x970UL))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_SUM_ADDR(base) ((base) + (0x974UL))
#define SOC_DDRC_DMC_DDRC_HIS_DAT_SUM_ADDR(base) ((base) + (0x978UL))
#define SOC_DDRC_DMC_DDRC_HIS_PRE_CMD_ADDR(base) ((base) + (0x97CUL))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_CMD_ADDR(base) ((base) + (0x980UL))
#define SOC_DDRC_DMC_DDRC_HIS_BNK_CHG_ADDR(base) ((base) + (0x984UL))
#define SOC_DDRC_DMC_DDRC_HIS_RNK_CHG_ADDR(base) ((base) + (0x988UL))
#define SOC_DDRC_DMC_DDRC_HIS_RW_CHG_ADDR(base) ((base) + (0x98CUL))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_BL32_ADDR(base) ((base) + (0x990UL))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_BL32_ADDR(base) ((base) + (0x994UL))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_ADDR(base) ((base) + (0x998UL))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_ADDR(base) ((base) + (0x99CUL))
#define SOC_DDRC_DMC_DDRC_HIS_REF_CMD_ADDR(base) ((base) + (0x9A0UL))
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_ADDR(base) ((base) + (0x9B0UL))
#define SOC_DDRC_DMC_DDRC_HIS_NLS_WIN_CNT_ADDR(base) ((base) + (0x9B4UL))
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_ADDR(base) ((base) + (0x9B8UL))
#define SOC_DDRC_DMC_DDRC_HIS_AS_CNT_ADDR(base) ((base) + (0x9C0UL))
#define SOC_DDRC_DMC_DDRC_HIS_B3_CNT_ADDR(base) ((base) + (0x9C4UL))
#define SOC_DDRC_DMC_DDRC_HIS_BCAST_CNT_ADDR(base) ((base) + (0x9C8UL))
#define SOC_DDRC_DMC_DDRC_HIS_WX_CNT_ADDR(base) ((base) + (0x9CCUL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD0_ADDR(base) ((base) + (0x9D0UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD1_ADDR(base) ((base) + (0x9D4UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD2_ADDR(base) ((base) + (0x9D8UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD3_ADDR(base) ((base) + (0x9DCUL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD4_ADDR(base) ((base) + (0x9E0UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD5_ADDR(base) ((base) + (0x9E4UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD6_ADDR(base) ((base) + (0x9E8UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD7_ADDR(base) ((base) + (0x9ECUL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD0_ADDR(base) ((base) + (0x9F0UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD1_ADDR(base) ((base) + (0x9F4UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD2_ADDR(base) ((base) + (0x9F8UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD3_ADDR(base) ((base) + (0x9FCUL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD4_ADDR(base) ((base) + (0xA00UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD5_ADDR(base) ((base) + (0xA04UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD6_ADDR(base) ((base) + (0xA08UL))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD7_ADDR(base) ((base) + (0xA0CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_ADDR(base) ((base) + (0xA10UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_ADDR(base) ((base) + (0xA14UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_ADDR(base) ((base) + (0xA18UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_ADDR(base) ((base) + (0xA1CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_ADDR(base) ((base) + (0xA20UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_ADDR(base) ((base) + (0xA24UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_ADDR(base) ((base) + (0xA28UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_ADDR(base) ((base) + (0xA2CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN0_ADDR(base) ((base) + (0xA30UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX0_ADDR(base) ((base) + (0xA34UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_ADDR(base) ((base) + (0xA38UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX0_ADDR(base) ((base) + (0xA3CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_ADDR(base) ((base) + (0xA40UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN1_ADDR(base) ((base) + (0xA44UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX1_ADDR(base) ((base) + (0xA48UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_ADDR(base) ((base) + (0xA4CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX1_ADDR(base) ((base) + (0xA50UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_ADDR(base) ((base) + (0xA54UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN2_ADDR(base) ((base) + (0xA58UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX2_ADDR(base) ((base) + (0xA5CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_ADDR(base) ((base) + (0xA60UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX2_ADDR(base) ((base) + (0xA64UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_ADDR(base) ((base) + (0xA68UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN3_ADDR(base) ((base) + (0xA6CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX3_ADDR(base) ((base) + (0xA70UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_ADDR(base) ((base) + (0xA74UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX3_ADDR(base) ((base) + (0xA78UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_ADDR(base) ((base) + (0xA7CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN4_ADDR(base) ((base) + (0xA80UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX4_ADDR(base) ((base) + (0xA84UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_ADDR(base) ((base) + (0xA88UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX4_ADDR(base) ((base) + (0xA8CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_ADDR(base) ((base) + (0xA90UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN5_ADDR(base) ((base) + (0xA94UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX5_ADDR(base) ((base) + (0xA98UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_ADDR(base) ((base) + (0xA9CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX5_ADDR(base) ((base) + (0xAA0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_ADDR(base) ((base) + (0xAA4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN6_ADDR(base) ((base) + (0xAA8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX6_ADDR(base) ((base) + (0xAACUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_ADDR(base) ((base) + (0xAB0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX6_ADDR(base) ((base) + (0xAB4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_ADDR(base) ((base) + (0xAB8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN7_ADDR(base) ((base) + (0xABCUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX7_ADDR(base) ((base) + (0xAC0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_ADDR(base) ((base) + (0xAC4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX7_ADDR(base) ((base) + (0xAC8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_ADDR(base) ((base) + (0xACCUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN8_ADDR(base) ((base) + (0xAD0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX8_ADDR(base) ((base) + (0xAD4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_ADDR(base) ((base) + (0xAD8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX8_ADDR(base) ((base) + (0xADCUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_ADDR(base) ((base) + (0xAE0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN9_ADDR(base) ((base) + (0xAE4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX9_ADDR(base) ((base) + (0xAE8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_ADDR(base) ((base) + (0xAECUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX9_ADDR(base) ((base) + (0xAF0UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_ADDR(base) ((base) + (0xAF4UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN10_ADDR(base) ((base) + (0xAF8UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX10_ADDR(base) ((base) + (0xAFCUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_ADDR(base) ((base) + (0xB00UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX10_ADDR(base) ((base) + (0xB04UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_ADDR(base) ((base) + (0xB08UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN11_ADDR(base) ((base) + (0xB0CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX11_ADDR(base) ((base) + (0xB10UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_ADDR(base) ((base) + (0xB14UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX11_ADDR(base) ((base) + (0xB18UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES0_ADDR(base) ((base) + (0xB1CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES1_ADDR(base) ((base) + (0xB20UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES2_ADDR(base) ((base) + (0xB24UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES3_ADDR(base) ((base) + (0xB28UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES4_ADDR(base) ((base) + (0xB2CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES5_ADDR(base) ((base) + (0xB30UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES6_ADDR(base) ((base) + (0xB34UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES7_ADDR(base) ((base) + (0xB38UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES8_ADDR(base) ((base) + (0xB3CUL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES9_ADDR(base) ((base) + (0xB40UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES10_ADDR(base) ((base) + (0xB44UL))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES11_ADDR(base) ((base) + (0xB48UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_CNT_ADDR(base) ((base) + (0xB4CUL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_CNT_ADDR(base) ((base) + (0xB50UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_NUM_ADDR(base) ((base) + (0xB54UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_NUM_ADDR(base) ((base) + (0xB58UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PD_NUM_ADDR(base) ((base) + (0xB5CUL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PD_NUM_ADDR(base) ((base) + (0xB60UL))
#define SOC_DDRC_DMC_DDRC_HIS_LP_NUM_ADDR(base) ((base) + (0xB64UL))
#define SOC_DDRC_DMC_DDRC_HIS_MERGE_NUM_ADDR(base) ((base) + (0xB68UL))
#define SOC_DDRC_DMC_DDRC_HIS_FORWARD_NUM_ADDR(base) ((base) + (0xB6CUL))
#define SOC_DDRC_DMC_DDRC_HIS_TO_NUM_ADDR(base) ((base) + (0xB70UL))
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_ADDR(base) ((base) + (0xB74UL))
#define SOC_DDRC_DMC_DDRC_HIS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB78UL))
#define SOC_DDRC_DMC_DDRC_HIS_ROWHIT_NUM_ADDR(base) ((base) + (0xB7CUL))
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK0_NUM_ADDR(base) ((base) + (0xB80UL))
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK1_NUM_ADDR(base) ((base) + (0xB84UL))
#define SOC_DDRC_DMC_DDRC_HIS_AP_NUM_ADDR(base) ((base) + (0xB88UL))
#define SOC_DDRC_DMC_DDRC_HIS_DFS_NUM_ADDR(base) ((base) + (0xB90UL))
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_NUM_ADDR(base) ((base) + (0xB94UL))
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_ADDR(base) ((base) + (0xB98UL))
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_ADDR(base) ((base) + (0xB9CUL))
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_CLR_ADDR(base) ((base) + (0xBA0UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PREALL_NUM_ADDR(base) ((base) + (0xBA4UL))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PREALL_NUM_ADDR(base) ((base) + (0xBA8UL))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_NUM_ADDR(base) ((base) + (0xBACUL))
#define SOC_DDRC_DMC_DDRC_HIS_ID_NM_NUM_ADDR(base) ((base) + (0xBB0UL))
#define SOC_DDRC_DMC_DDRC_HIS_BYACT_NUM_ADDR(base) ((base) + (0xBB4UL))
#define SOC_DDRC_DMC_DDRC_HIS_BYRD_NUM_ADDR(base) ((base) + (0xBB8UL))
#define SOC_DDRC_DMC_DDRC_HIS_ADCONF_NUM_ADDR(base) ((base) + (0xBBCUL))
#define SOC_DDRC_DMC_DDRC_HIS_IDCONF_NUM_ADDR(base) ((base) + (0xBC0UL))
#define SOC_DDRC_DMC_DDRC_HIS_GRP_ROWHIT_NUM_ADDR(base) ((base) + (0xBC4UL))
#define SOC_DDRC_DMC_DDRC_HIS_WRITE_ALLONE_NUM_ADDR(base) ((base) + (0xBC8UL))
#define SOC_DDRC_DMC_DDRC_HIS_WPAT_ALL_ONE_ADDR(base) ((base) + (0xBCCUL))
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK0_CNT_ADDR(base) ((base) + (0xBD0UL))
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK1_CNT_ADDR(base) ((base) + (0xBD4UL))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK0_CNT_ADDR(base) ((base) + (0xBD8UL))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK1_CNT_ADDR(base) ((base) + (0xBDCUL))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK0_CNT_ADDR(base) ((base) + (0xBE0UL))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK1_CNT_ADDR(base) ((base) + (0xBE4UL))
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_ADDR(base) ((base) + (0xC00UL))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_ADDR(base) ((base) + (0xC04UL))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_ADDR(base) ((base) + (0xC08UL))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_ADDR(base) ((base) + (0xC0CUL))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST0_ADDR(base) ((base) + (0xC10UL))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST1_ADDR(base) ((base) + (0xC14UL))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST2_ADDR(base) ((base) + (0xC18UL))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST3_ADDR(base) ((base) + (0xC1CUL))
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_ADDR(base) ((base) + (0xC20UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_ADDR(base) ((base) + (0xC24UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_ADDR(base) ((base) + (0xC28UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_ADDR(base) ((base) + (0xC2CUL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_ADDR(base) ((base) + (0xC30UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_ADDR(base) ((base) + (0xC34UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_ADDR(base) ((base) + (0xC38UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT14_ADDR(base) ((base) + (0xC3CUL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_ADDR(base) ((base) + (0xC40UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_ADDR(base) ((base) + (0xC44UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_ADDR(base) ((base) + (0xC48UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_ADDR(base) ((base) + (0xC4CUL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_ADDR(base) ((base) + (0xC50UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_ADDR(base) ((base) + (0xC54UL))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ADDR(base) ((base) + (0xC58UL))
#define SOC_DDRC_DMC_STAT12_ADDR(base) ((base) + (0xC5CUL))
#define SOC_DDRC_DMC_DDRC_REC_STAT0_ADDR(base) ((base) + (0xC60UL))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_ADDR(base) ((base) + (0xC64UL))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_ADDR(base) ((base) + (0xC68UL))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_ADDR(base) ((base) + (0xC6CUL))
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_ADDR(base) ((base) + (0xC70UL))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_ADDR(base,rnks) ((base) + (0xC7C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_ADDR(base,rnks) ((base) + (0xC8C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_ADDR(base,rnks) ((base) + (0xC9C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_ADDR(base,rnks) ((base) + (0xCAC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_ADDR(base,rnks) ((base) + (0xCBC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_ADDR(base,rnks) ((base) + (0xCCC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OPENPAGE_TIME_ADDR(base) ((base) + (0xCDCUL))
#define SOC_DDRC_DMC_DDRC_GRP_STAT_ADDR(base) ((base) + (0xCE0UL))
#define SOC_DDRC_DMC_DDRC_HIS_CLK_OFF_ADDR(base) ((base) + (0xD00UL))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_ADDR(base) ((base) + (0xD04UL))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK1_ADDR(base) ((base) + (0xD08UL))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK2_ADDR(base) ((base) + (0xD0CUL))
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_ADDR(base) ((base) + (0xD10UL))
#define SOC_DDRC_DMC_DDRC_HIS_EC1_ADDR(base) ((base) + (0xD14UL))
#define SOC_DDRC_DMC_DDRC_HIS_EC0_ADDR(base) ((base) + (0xD18UL))
#define SOC_DDRC_DMC_DDRC_HIS_FSP_STATE_ADDR(base) ((base) + (0xD1CUL))
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_ADDR(base) ((base) + (0xD20UL))
#define SOC_DDRC_DMC_DDRC_HIS_WRDATA_OVER_ADDR(base) ((base) + (0xD24UL))
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_ADDR(base) ((base) + (0xD28UL))
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF0_ADDR(base) ((base) + (0xD2CUL))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF3_ADDR(base) ((base) + (0xD30UL))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF2_ADDR(base) ((base) + (0xD34UL))
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF1_ADDR(base) ((base) + (0xD38UL))
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF0_ADDR(base) ((base) + (0xD3CUL))
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_ADDR(base) ((base) + (0xD40UL))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_ADDR(base) ((base) + (0xD44UL))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_ADDR(base) ((base) + (0xD48UL))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD0_ADDR(base) ((base) + (0xD4CUL))
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_ADDR(base) ((base) + (0xD50UL))
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_ADDR(base) ((base) + (0xD54UL))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_ADDR(base) ((base) + (0xD58UL))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_HADDR_ADDR(base) ((base) + (0xD5CUL))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_ADDR_ADDR(base) ((base) + (0xD60UL))
#else
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ADDR_ADDR(base) ((base) + (0x700))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_HADDR_ADDR(base) ((base) + (0x704))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_ADDR(base) ((base) + (0x708))
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_ADDR(base) ((base) + (0x70C))
#define SOC_DDRC_DMC_DDRC_REF_RATE_ADDR(base) ((base) + (0x720))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_ADDR(base) ((base) + (0x724))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_ADDR(base) ((base) + (0x728))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_ADDR(base) ((base) + (0x72C))
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_ADDR(base) ((base) + (0x730))
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900))
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_ADDR(base) ((base) + (0x904))
#define SOC_DDRC_DMC_DDRC_CFG_DATMIN_ADDR(base) ((base) + (0x908))
#define SOC_DDRC_DMC_DDRC_CFG_DATMAX_ADDR(base) ((base) + (0x90C))
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_ADDR(base) ((base) + (0x910))
#define SOC_DDRC_DMC_DDRC_CFG_DAT_SCMAX_ADDR(base) ((base) + (0x914))
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918))
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_ADDR(base) ((base) + (0x91C))
#define SOC_DDRC_DMC_DDRC_CFG_CMDMIN_ADDR(base) ((base) + (0x920))
#define SOC_DDRC_DMC_DDRC_CFG_CMDMAX_ADDR(base) ((base) + (0x924))
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_ADDR(base) ((base) + (0x928))
#define SOC_DDRC_DMC_DDRC_CFG_CMD_SCMAX_ADDR(base) ((base) + (0x92C))
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_ADDR(base) ((base) + (0x930))
#define SOC_DDRC_DMC_DDRC_CFG_PERF_ADDR(base) ((base) + (0x934))
#define SOC_DDRC_DMC_DDRC_CFG_STAID_ADDR(base) ((base) + (0x938))
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_ADDR(base) ((base) + (0x93C))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WR_ADDR(base) ((base) + (0x940))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RD_ADDR(base) ((base) + (0x944))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WCMD_ADDR(base) ((base) + (0x948))
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RCMD_ADDR(base) ((base) + (0x94C))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WR_ADDR(base) ((base) + (0x950))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RD_ADDR(base) ((base) + (0x954))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WCMD_ADDR(base) ((base) + (0x958))
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RCMD_ADDR(base) ((base) + (0x95C))
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_ADDR(base) ((base) + (0x960))
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT1_ADDR(base) ((base) + (0x964))
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_ADDR(base) ((base) + (0x968))
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT1_ADDR(base) ((base) + (0x96C))
#define SOC_DDRC_DMC_DDRC_HIS_INHERE_RLAT_CNT_ADDR(base) ((base) + (0x970))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_SUM_ADDR(base) ((base) + (0x974))
#define SOC_DDRC_DMC_DDRC_HIS_DAT_SUM_ADDR(base) ((base) + (0x978))
#define SOC_DDRC_DMC_DDRC_HIS_PRE_CMD_ADDR(base) ((base) + (0x97C))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_CMD_ADDR(base) ((base) + (0x980))
#define SOC_DDRC_DMC_DDRC_HIS_BNK_CHG_ADDR(base) ((base) + (0x984))
#define SOC_DDRC_DMC_DDRC_HIS_RNK_CHG_ADDR(base) ((base) + (0x988))
#define SOC_DDRC_DMC_DDRC_HIS_RW_CHG_ADDR(base) ((base) + (0x98C))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_BL32_ADDR(base) ((base) + (0x990))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_BL32_ADDR(base) ((base) + (0x994))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_ADDR(base) ((base) + (0x998))
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_ADDR(base) ((base) + (0x99C))
#define SOC_DDRC_DMC_DDRC_HIS_REF_CMD_ADDR(base) ((base) + (0x9A0))
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_ADDR(base) ((base) + (0x9B0))
#define SOC_DDRC_DMC_DDRC_HIS_NLS_WIN_CNT_ADDR(base) ((base) + (0x9B4))
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_ADDR(base) ((base) + (0x9B8))
#define SOC_DDRC_DMC_DDRC_HIS_AS_CNT_ADDR(base) ((base) + (0x9C0))
#define SOC_DDRC_DMC_DDRC_HIS_B3_CNT_ADDR(base) ((base) + (0x9C4))
#define SOC_DDRC_DMC_DDRC_HIS_BCAST_CNT_ADDR(base) ((base) + (0x9C8))
#define SOC_DDRC_DMC_DDRC_HIS_WX_CNT_ADDR(base) ((base) + (0x9CC))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD0_ADDR(base) ((base) + (0x9D0))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD1_ADDR(base) ((base) + (0x9D4))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD2_ADDR(base) ((base) + (0x9D8))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD3_ADDR(base) ((base) + (0x9DC))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD4_ADDR(base) ((base) + (0x9E0))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD5_ADDR(base) ((base) + (0x9E4))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD6_ADDR(base) ((base) + (0x9E8))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD7_ADDR(base) ((base) + (0x9EC))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD0_ADDR(base) ((base) + (0x9F0))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD1_ADDR(base) ((base) + (0x9F4))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD2_ADDR(base) ((base) + (0x9F8))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD3_ADDR(base) ((base) + (0x9FC))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD4_ADDR(base) ((base) + (0xA00))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD5_ADDR(base) ((base) + (0xA04))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD6_ADDR(base) ((base) + (0xA08))
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD7_ADDR(base) ((base) + (0xA0C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_ADDR(base) ((base) + (0xA10))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_ADDR(base) ((base) + (0xA14))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_ADDR(base) ((base) + (0xA18))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_ADDR(base) ((base) + (0xA1C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_ADDR(base) ((base) + (0xA20))
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_ADDR(base) ((base) + (0xA24))
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_ADDR(base) ((base) + (0xA28))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_ADDR(base) ((base) + (0xA2C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN0_ADDR(base) ((base) + (0xA30))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX0_ADDR(base) ((base) + (0xA34))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_ADDR(base) ((base) + (0xA38))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX0_ADDR(base) ((base) + (0xA3C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_ADDR(base) ((base) + (0xA40))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN1_ADDR(base) ((base) + (0xA44))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX1_ADDR(base) ((base) + (0xA48))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_ADDR(base) ((base) + (0xA4C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX1_ADDR(base) ((base) + (0xA50))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_ADDR(base) ((base) + (0xA54))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN2_ADDR(base) ((base) + (0xA58))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX2_ADDR(base) ((base) + (0xA5C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_ADDR(base) ((base) + (0xA60))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX2_ADDR(base) ((base) + (0xA64))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_ADDR(base) ((base) + (0xA68))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN3_ADDR(base) ((base) + (0xA6C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX3_ADDR(base) ((base) + (0xA70))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_ADDR(base) ((base) + (0xA74))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX3_ADDR(base) ((base) + (0xA78))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_ADDR(base) ((base) + (0xA7C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN4_ADDR(base) ((base) + (0xA80))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX4_ADDR(base) ((base) + (0xA84))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_ADDR(base) ((base) + (0xA88))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX4_ADDR(base) ((base) + (0xA8C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_ADDR(base) ((base) + (0xA90))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN5_ADDR(base) ((base) + (0xA94))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX5_ADDR(base) ((base) + (0xA98))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_ADDR(base) ((base) + (0xA9C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX5_ADDR(base) ((base) + (0xAA0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_ADDR(base) ((base) + (0xAA4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN6_ADDR(base) ((base) + (0xAA8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX6_ADDR(base) ((base) + (0xAAC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_ADDR(base) ((base) + (0xAB0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX6_ADDR(base) ((base) + (0xAB4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_ADDR(base) ((base) + (0xAB8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN7_ADDR(base) ((base) + (0xABC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX7_ADDR(base) ((base) + (0xAC0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_ADDR(base) ((base) + (0xAC4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX7_ADDR(base) ((base) + (0xAC8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_ADDR(base) ((base) + (0xACC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN8_ADDR(base) ((base) + (0xAD0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX8_ADDR(base) ((base) + (0xAD4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_ADDR(base) ((base) + (0xAD8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX8_ADDR(base) ((base) + (0xADC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_ADDR(base) ((base) + (0xAE0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN9_ADDR(base) ((base) + (0xAE4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX9_ADDR(base) ((base) + (0xAE8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_ADDR(base) ((base) + (0xAEC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX9_ADDR(base) ((base) + (0xAF0))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_ADDR(base) ((base) + (0xAF4))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN10_ADDR(base) ((base) + (0xAF8))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX10_ADDR(base) ((base) + (0xAFC))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_ADDR(base) ((base) + (0xB00))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX10_ADDR(base) ((base) + (0xB04))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_ADDR(base) ((base) + (0xB08))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN11_ADDR(base) ((base) + (0xB0C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX11_ADDR(base) ((base) + (0xB10))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_ADDR(base) ((base) + (0xB14))
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX11_ADDR(base) ((base) + (0xB18))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES0_ADDR(base) ((base) + (0xB1C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES1_ADDR(base) ((base) + (0xB20))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES2_ADDR(base) ((base) + (0xB24))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES3_ADDR(base) ((base) + (0xB28))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES4_ADDR(base) ((base) + (0xB2C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES5_ADDR(base) ((base) + (0xB30))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES6_ADDR(base) ((base) + (0xB34))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES7_ADDR(base) ((base) + (0xB38))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES8_ADDR(base) ((base) + (0xB3C))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES9_ADDR(base) ((base) + (0xB40))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES10_ADDR(base) ((base) + (0xB44))
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES11_ADDR(base) ((base) + (0xB48))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_CNT_ADDR(base) ((base) + (0xB4C))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_CNT_ADDR(base) ((base) + (0xB50))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_NUM_ADDR(base) ((base) + (0xB54))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_NUM_ADDR(base) ((base) + (0xB58))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PD_NUM_ADDR(base) ((base) + (0xB5C))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PD_NUM_ADDR(base) ((base) + (0xB60))
#define SOC_DDRC_DMC_DDRC_HIS_LP_NUM_ADDR(base) ((base) + (0xB64))
#define SOC_DDRC_DMC_DDRC_HIS_MERGE_NUM_ADDR(base) ((base) + (0xB68))
#define SOC_DDRC_DMC_DDRC_HIS_FORWARD_NUM_ADDR(base) ((base) + (0xB6C))
#define SOC_DDRC_DMC_DDRC_HIS_TO_NUM_ADDR(base) ((base) + (0xB70))
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_ADDR(base) ((base) + (0xB74))
#define SOC_DDRC_DMC_DDRC_HIS_RHIT_BREAK_NUM_ADDR(base) ((base) + (0xB78))
#define SOC_DDRC_DMC_DDRC_HIS_ROWHIT_NUM_ADDR(base) ((base) + (0xB7C))
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK0_NUM_ADDR(base) ((base) + (0xB80))
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK1_NUM_ADDR(base) ((base) + (0xB84))
#define SOC_DDRC_DMC_DDRC_HIS_AP_NUM_ADDR(base) ((base) + (0xB88))
#define SOC_DDRC_DMC_DDRC_HIS_DFS_NUM_ADDR(base) ((base) + (0xB90))
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_NUM_ADDR(base) ((base) + (0xB94))
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_ADDR(base) ((base) + (0xB98))
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_ADDR(base) ((base) + (0xB9C))
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_CLR_ADDR(base) ((base) + (0xBA0))
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PREALL_NUM_ADDR(base) ((base) + (0xBA4))
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PREALL_NUM_ADDR(base) ((base) + (0xBA8))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_NUM_ADDR(base) ((base) + (0xBAC))
#define SOC_DDRC_DMC_DDRC_HIS_ID_NM_NUM_ADDR(base) ((base) + (0xBB0))
#define SOC_DDRC_DMC_DDRC_HIS_BYACT_NUM_ADDR(base) ((base) + (0xBB4))
#define SOC_DDRC_DMC_DDRC_HIS_BYRD_NUM_ADDR(base) ((base) + (0xBB8))
#define SOC_DDRC_DMC_DDRC_HIS_ADCONF_NUM_ADDR(base) ((base) + (0xBBC))
#define SOC_DDRC_DMC_DDRC_HIS_IDCONF_NUM_ADDR(base) ((base) + (0xBC0))
#define SOC_DDRC_DMC_DDRC_HIS_GRP_ROWHIT_NUM_ADDR(base) ((base) + (0xBC4))
#define SOC_DDRC_DMC_DDRC_HIS_WRITE_ALLONE_NUM_ADDR(base) ((base) + (0xBC8))
#define SOC_DDRC_DMC_DDRC_HIS_WPAT_ALL_ONE_ADDR(base) ((base) + (0xBCC))
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK0_CNT_ADDR(base) ((base) + (0xBD0))
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK1_CNT_ADDR(base) ((base) + (0xBD4))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK0_CNT_ADDR(base) ((base) + (0xBD8))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK1_CNT_ADDR(base) ((base) + (0xBDC))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK0_CNT_ADDR(base) ((base) + (0xBE0))
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK1_CNT_ADDR(base) ((base) + (0xBE4))
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_ADDR(base) ((base) + (0xC00))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_ADDR(base) ((base) + (0xC04))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_ADDR(base) ((base) + (0xC08))
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_ADDR(base) ((base) + (0xC0C))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST0_ADDR(base) ((base) + (0xC10))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST1_ADDR(base) ((base) + (0xC14))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST2_ADDR(base) ((base) + (0xC18))
#define SOC_DDRC_DMC_DDRC_CURR_EXECST3_ADDR(base) ((base) + (0xC1C))
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_ADDR(base) ((base) + (0xC20))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_ADDR(base) ((base) + (0xC24))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_ADDR(base) ((base) + (0xC28))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_ADDR(base) ((base) + (0xC2C))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_ADDR(base) ((base) + (0xC30))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_ADDR(base) ((base) + (0xC34))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_ADDR(base) ((base) + (0xC38))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT14_ADDR(base) ((base) + (0xC3C))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_ADDR(base) ((base) + (0xC40))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_ADDR(base) ((base) + (0xC44))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_ADDR(base) ((base) + (0xC48))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_ADDR(base) ((base) + (0xC4C))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_ADDR(base) ((base) + (0xC50))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_ADDR(base) ((base) + (0xC54))
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ADDR(base) ((base) + (0xC58))
#define SOC_DDRC_DMC_STAT12_ADDR(base) ((base) + (0xC5C))
#define SOC_DDRC_DMC_DDRC_REC_STAT0_ADDR(base) ((base) + (0xC60))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_ADDR(base) ((base) + (0xC64))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_ADDR(base) ((base) + (0xC68))
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_ADDR(base) ((base) + (0xC6C))
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_ADDR(base) ((base) + (0xC70))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_ADDR(base,rnks) ((base) + (0xC7C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_ADDR(base,rnks) ((base) + (0xC8C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_ADDR(base,rnks) ((base) + (0xC9C+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_ADDR(base,rnks) ((base) + (0xCAC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_ADDR(base,rnks) ((base) + (0xCBC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_ADDR(base,rnks) ((base) + (0xCCC+0x4*(rnks)))
#define SOC_DDRC_DMC_DDRC_OPENPAGE_TIME_ADDR(base) ((base) + (0xCDC))
#define SOC_DDRC_DMC_DDRC_GRP_STAT_ADDR(base) ((base) + (0xCE0))
#define SOC_DDRC_DMC_DDRC_HIS_CLK_OFF_ADDR(base) ((base) + (0xD00))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_ADDR(base) ((base) + (0xD04))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK1_ADDR(base) ((base) + (0xD08))
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK2_ADDR(base) ((base) + (0xD0C))
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_ADDR(base) ((base) + (0xD10))
#define SOC_DDRC_DMC_DDRC_HIS_EC1_ADDR(base) ((base) + (0xD14))
#define SOC_DDRC_DMC_DDRC_HIS_EC0_ADDR(base) ((base) + (0xD18))
#define SOC_DDRC_DMC_DDRC_HIS_FSP_STATE_ADDR(base) ((base) + (0xD1C))
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_ADDR(base) ((base) + (0xD20))
#define SOC_DDRC_DMC_DDRC_HIS_WRDATA_OVER_ADDR(base) ((base) + (0xD24))
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_ADDR(base) ((base) + (0xD28))
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF0_ADDR(base) ((base) + (0xD2C))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF3_ADDR(base) ((base) + (0xD30))
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF2_ADDR(base) ((base) + (0xD34))
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF1_ADDR(base) ((base) + (0xD38))
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF0_ADDR(base) ((base) + (0xD3C))
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_ADDR(base) ((base) + (0xD40))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_ADDR(base) ((base) + (0xD44))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_ADDR(base) ((base) + (0xD48))
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD0_ADDR(base) ((base) + (0xD4C))
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_ADDR(base) ((base) + (0xD50))
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_ADDR(base) ((base) + (0xD54))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_ADDR(base) ((base) + (0xD58))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_HADDR_ADDR(base) ((base) + (0xD5C))
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_ADDR_ADDR(base) ((base) + (0xD60))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_req : 1;
        unsigned int sref_done : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_SREF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_sref_req_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_sref_req_END (0)
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_sref_done_START (1)
#define SOC_DDRC_DMC_DDRC_CTRL_SREF_sref_done_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfi_init_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_INIT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_INIT_dfi_init_start_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_INIT_dfi_init_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_bp_start : 1;
        unsigned int soft_bp_ok : 1;
        unsigned int rbp_opt : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_SFBP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_soft_bp_start_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_soft_bp_start_END (0)
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_soft_bp_ok_START (1)
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_soft_bp_ok_END (1)
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_rbp_opt_START (2)
#define SOC_DDRC_DMC_DDRC_CTRL_SFBP_rbp_opt_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_rst_n : 1;
        unsigned int init_cke_cs_value : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_DDRRST_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_ddr_rst_n_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_ddr_rst_n_END (0)
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_init_cke_cs_value_START (1)
#define SOC_DDRC_DMC_DDRC_CTRL_DDRRST_init_cke_cs_value_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_en_o : 8;
        unsigned int pd_en : 8;
        unsigned int pd_exit_opt : 1;
        unsigned int pdx_byp_uni : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_o_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_o_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_en_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_exit_opt_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pd_exit_opt_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pdx_byp_uni_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC3_pdx_byp_uni_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int zqc_en : 8;
        unsigned int zqbg_en : 8;
        unsigned int aref_en : 8;
        unsigned int rh_en : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_zqc_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_zqc_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_zqbg_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_zqbg_en_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_aref_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_aref_en_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_rh_en_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC0_rh_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_en : 8;
        unsigned int dummy_rd_en : 8;
        unsigned int osc_i_en : 8;
        unsigned int osc_o_en : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_tmon_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_tmon_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_dummy_rd_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_dummy_rd_en_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_i_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_i_en_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_o_en_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC1_osc_o_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank_disable : 8;
        unsigned int lp_en : 1;
        unsigned int fast_pd_en : 1;
        unsigned int sync_impact_other : 1;
        unsigned int reserved : 1;
        unsigned int zq_master : 4;
        unsigned int asref_en : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_rank_disable_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_rank_disable_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_lp_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_lp_en_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pd_en_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_fast_pd_en_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_sync_impact_other_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_sync_impact_other_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_zq_master_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_zq_master_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_FUNC2_asref_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_soft_en : 1;
        unsigned int lp_ack : 1;
        unsigned int reserved_0 : 2;
        unsigned int tlp_wakeup : 4;
        unsigned int tlp_resp : 4;
        unsigned int t_wcke : 4;
        unsigned int sys_lp_prd : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LP0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LP0_lp_soft_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_lp_soft_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_lp_ack_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_lp_ack_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_tlp_wakeup_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_tlp_wakeup_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_tlp_resp_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_tlp_resp_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_t_wcke_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_t_wcke_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_sys_lp_prd_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_LP0_sys_lp_prd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dyn_lp_wakeup_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int tlp_wakeup_l3 : 4;
        unsigned int reserved_1 : 4;
        unsigned int tlp_wakeup_l2 : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LP1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LP1_dyn_lp_wakeup_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP1_dyn_lp_wakeup_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP1_tlp_wakeup_l3_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_LP1_tlp_wakeup_l3_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_LP1_tlp_wakeup_l2_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_LP1_tlp_wakeup_l2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_l2_idle : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LP2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LP2_lp_l2_idle_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP2_lp_l2_idle_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_l3_idle : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LP3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LP3_lp_l3_idle_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LP3_lp_l3_idle_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_cc : 1;
        unsigned int sref_pd : 1;
        unsigned int sref_flush_en : 1;
        unsigned int clk_switch : 1;
        unsigned int sref_bp_en : 1;
        unsigned int dfs_bp_cmdin : 1;
        unsigned int sref_dsm : 1;
        unsigned int asref_prd : 12;
        unsigned int reserved_0 : 4;
        unsigned int allow_csysreq : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SREF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_cc_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_cc_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_pd_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_pd_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_flush_en_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_flush_en_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_clk_switch_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_clk_switch_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_bp_en_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_bp_en_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_dfs_bp_cmdin_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_dfs_bp_cmdin_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_dsm_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_sref_dsm_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_asref_prd_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_asref_prd_END (18)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_allow_csysreq_START (23)
#define SOC_DDRC_DMC_DDRC_CFG_SREF_allow_csysreq_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_cc : 1;
        unsigned int reserved_0 : 3;
        unsigned int pd_prd : 12;
        unsigned int t_clk_cke : 4;
        unsigned int pd_odt_ddr5 : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_cc_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_cc_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_prd_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_prd_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_PD_t_clk_cke_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_PD_t_clk_cke_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_odt_ddr5_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_PD_pd_odt_ddr5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aref_opt : 1;
        unsigned int aref_alarm_en : 1;
        unsigned int aref_comp : 1;
        unsigned int modified_mode : 1;
        unsigned int pstpnd_level : 4;
        unsigned int aref_alarm_num : 8;
        unsigned int phyupd_level : 4;
        unsigned int aref_rate : 5;
        unsigned int reserved : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_AREF0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_opt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_opt_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_alarm_en_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_alarm_en_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_comp_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_comp_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_modified_mode_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_modified_mode_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_pstpnd_level_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_pstpnd_level_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_alarm_num_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_alarm_num_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_phyupd_level_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_phyupd_level_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_rate_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_AREF0_aref_rate_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trefi : 11;
        unsigned int reserved : 5;
        unsigned int rf_rate_ctrl : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_AREF1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_trefi_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_trefi_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_rf_rate_ctrl_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_AREF1_rf_rate_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sbr_idle_en : 1;
        unsigned int sbr_weight_mode : 2;
        unsigned int reserved_0 : 1;
        unsigned int sbr_frcst_num : 5;
        unsigned int sbr_sbpre_en : 1;
        unsigned int sbr_req_mode : 2;
        unsigned int sbr_bank_num : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PBR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_idle_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_idle_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_weight_mode_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_weight_mode_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_frcst_num_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_frcst_num_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_sbpre_en_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_sbpre_en_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_req_mode_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_req_mode_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_bank_num_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_PBR_sbr_bank_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzq_prd : 28;
        unsigned int zq_ch_mode : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_ZQ_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_tzq_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_tzq_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_zq_ch_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_ZQ_zq_ch_mode_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raaimt : 8;
        unsigned int raammt : 12;
        unsigned int raa_dec_mode : 2;
        unsigned int rh_sft_en : 1;
        unsigned int raainq_babg : 5;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RH_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RH_raaimt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raaimt_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raammt_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raammt_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raa_dec_mode_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raa_dec_mode_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_RH_rh_sft_en_START (22)
#define SOC_DDRC_DMC_DDRC_CFG_RH_rh_sft_en_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raainq_babg_START (23)
#define SOC_DDRC_DMC_DDRC_CFG_RH_raainq_babg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raaimt_ref_dec : 10;
        unsigned int raaimt_rfm_dec : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RH1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RH1_raaimt_ref_dec_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RH1_raaimt_ref_dec_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_RH1_raaimt_rfm_dec_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_RH1_raaimt_rfm_dec_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rh_rate_en : 1;
        unsigned int rh_rate_ctrl : 16;
        unsigned int reserved : 15;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RH2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RH2_rh_rate_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RH2_rh_rate_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_RH2_rh_rate_ctrl_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_RH2_rh_rate_ctrl_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_prd : 28;
        unsigned int osc_retrain_en : 1;
        unsigned int osc_for_x8 : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_OSC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_retrain_en_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_retrain_en_END (28)
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_for_x8_START (29)
#define SOC_DDRC_DMC_DDRC_CFG_OSC0_osc_for_x8_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int osc_o_threshold : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_OSC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_OSC1_osc_o_threshold_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_OSC1_osc_o_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int osc_i_threshold : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_OSC2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_OSC2_osc_i_threshold_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_OSC2_osc_i_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ret_cmd_type : 1;
        unsigned int reserved_0 : 3;
        unsigned int ret_mpc_cnt : 4;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ret_cmd_type_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ret_cmd_type_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ret_mpc_cnt_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD0_ret_mpc_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_rd_prd : 28;
        unsigned int dummy_rd_mode : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_dummy_rd_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_dummy_rd_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_dummy_rd_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_DUM_RD1_dummy_rd_mode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_prd : 28;
        unsigned int use_tuf : 1;
        unsigned int tmon_for_x8 : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TMON_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TMON_tmon_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TMON_tmon_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_TMON_use_tuf_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TMON_use_tuf_END (28)
#define SOC_DDRC_DMC_DDRC_CFG_TMON_tmon_for_x8_START (29)
#define SOC_DDRC_DMC_DDRC_CFG_TMON_tmon_for_x8_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int phy_zqen : 1;
        unsigned int reserved_1 : 7;
        unsigned int phy_upden : 1;
        unsigned int reserved_2 : 11;
        unsigned int phyupd_n_pre : 1;
        unsigned int reserved_3 : 3;
        unsigned int phyupd_n_pre_type : 2;
        unsigned int phyupd_do_sfc : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PHYUPD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phy_zqen_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phy_zqen_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phy_upden_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phy_upden_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_END (24)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_type_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_n_pre_type_END (29)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_do_sfc_START (30)
#define SOC_DDRC_DMC_DDRC_CFG_PHYUPD_phyupd_do_sfc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rec_on : 1;
        unsigned int rec_resend_off : 1;
        unsigned int rec_dmc_wl : 4;
        unsigned int rec_release_int_st : 1;
        unsigned int rec_fifo_on : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_REC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_on_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_on_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_resend_off_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_resend_off_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_dmc_wl_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_dmc_wl_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_release_int_st_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_release_int_st_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_fifo_on_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_REC0_rec_fifo_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rec_wcrc_ptr : 8;
        unsigned int rec_ca_err_ptr : 8;
        unsigned int rec_wcrc_wd_ptr : 8;
        unsigned int rec_wait_wd : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_REC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wcrc_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wcrc_ptr_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_ca_err_ptr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_ca_err_ptr_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wcrc_wd_ptr_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wcrc_wd_ptr_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wait_wd_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_REC1_rec_wait_wd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rec_timer0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_REC2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_REC2_rec_timer0_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_REC2_rec_timer0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rec_trank : 5;
        unsigned int rec_crc_alrt_pw : 8;
        unsigned int rec_stuck_count : 9;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_REC3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_trank_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_trank_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_crc_alrt_pw_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_crc_alrt_pw_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_stuck_count_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_REC3_rec_stuck_count_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_small_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tmon_small_prd : 4;
        unsigned int dum_small_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int dum_small_prd : 4;
        unsigned int osc_small_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int osc_small_prd : 4;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_tmon_small_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_tmon_small_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_tmon_small_prd_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_tmon_small_prd_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_dum_small_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_dum_small_en_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_dum_small_prd_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_dum_small_prd_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_osc_small_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_osc_small_en_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_osc_small_prd_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_SMALL_PRD_osc_small_prd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grp_ap_en : 1;
        unsigned int enhan_ap_en : 1;
        unsigned int apre_en : 1;
        unsigned int forward_en : 1;
        unsigned int merge_en : 1;
        unsigned int tccdl_wr_mode : 1;
        unsigned int priadpt_en : 1;
        unsigned int addr_push_en : 1;
        unsigned int mid_push_en : 1;
        unsigned int page_adpt_en : 1;
        unsigned int page_timeout_en : 1;
        unsigned int pbr_en : 1;
        unsigned int timeout_en : 1;
        unsigned int byp_act_en : 1;
        unsigned int byp_rd_en : 1;
        unsigned int save_pre_en : 1;
        unsigned int rd_intlv_en : 1;
        unsigned int wr_intlv_en : 1;
        unsigned int soft_idcmp_en : 1;
        unsigned int monitor_data_mode : 1;
        unsigned int lvl2_lru_en : 1;
        unsigned int grp_swit_fast : 1;
        unsigned int wckpst_as_sync : 1;
        unsigned int new_cmd_req_en : 1;
        unsigned int addr_mode : 3;
        unsigned int rdata_intlv_mode : 2;
        unsigned int bg_intlv_opt : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_grp_ap_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_grp_ap_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_enhan_ap_en_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_enhan_ap_en_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_apre_en_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_apre_en_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_forward_en_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_forward_en_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_merge_en_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_merge_en_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_tccdl_wr_mode_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_tccdl_wr_mode_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_priadpt_en_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_priadpt_en_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_addr_push_en_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_addr_push_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_mid_push_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_mid_push_en_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_page_adpt_en_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_page_adpt_en_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_page_timeout_en_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_page_timeout_en_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_pbr_en_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_pbr_en_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_timeout_en_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_timeout_en_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_byp_act_en_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_byp_act_en_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_byp_rd_en_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_byp_rd_en_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_save_pre_en_START (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_save_pre_en_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_rd_intlv_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_rd_intlv_en_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_wr_intlv_en_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_wr_intlv_en_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_soft_idcmp_en_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_soft_idcmp_en_END (18)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_monitor_data_mode_START (19)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_monitor_data_mode_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_lvl2_lru_en_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_lvl2_lru_en_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_grp_swit_fast_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_grp_swit_fast_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_wckpst_as_sync_START (22)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_wckpst_as_sync_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_new_cmd_req_en_START (23)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_new_cmd_req_en_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_addr_mode_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_addr_mode_END (26)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_rdata_intlv_mode_START (27)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_rdata_intlv_mode_END (28)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_bg_intlv_opt_START (29)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_bg_intlv_opt_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_col : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_row : 3;
        unsigned int reserved_1 : 1;
        unsigned int mem_bank : 2;
        unsigned int mem_bankgroup : 2;
        unsigned int lg_rank : 2;
        unsigned int rank : 2;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RNKVOL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_col_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_col_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_row_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_row_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_bank_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_bank_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_bankgroup_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_mem_bankgroup_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_lg_rank_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_lg_rank_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_rank_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_RNKVOL_rank_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dram_type : 4;
        unsigned int mem_width : 2;
        unsigned int lp5_8b_mode : 1;
        unsigned int rank_mirr : 1;
        unsigned int ddr5_2n_mode : 1;
        unsigned int wmsk_mode : 2;
        unsigned int reserved_0 : 5;
        unsigned int lp4_r17_en : 4;
        unsigned int lp4_r18_high : 1;
        unsigned int allow_cmdin : 1;
        unsigned int enhance_push : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_dram_type_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_dram_type_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_mem_width_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_mem_width_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp5_8b_mode_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp5_8b_mode_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_rank_mirr_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_rank_mirr_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_ddr5_2n_mode_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_ddr5_2n_mode_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_wmsk_mode_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_wmsk_mode_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp4_r17_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp4_r17_en_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp4_r18_high_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_lp4_r18_high_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_allow_cmdin_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_allow_cmdin_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_enhance_push_START (22)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE0_enhance_push_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wck_on : 1;
        unsigned int writex_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int wrx_bg_time : 1;
        unsigned int wrx_pattern : 8;
        unsigned int cw_ddr5 : 1;
        unsigned int wr_seamless_en : 1;
        unsigned int rd_seamless_en : 1;
        unsigned int cas_bc_en : 1;
        unsigned int fulltog_en : 1;
        unsigned int wckpst_mask : 1;
        unsigned int wck_invld_en : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wck_on_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wck_on_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_writex_en_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_writex_en_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wrx_bg_time_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wrx_bg_time_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wrx_pattern_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wrx_pattern_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_cw_ddr5_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_cw_ddr5_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wr_seamless_en_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wr_seamless_en_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_rd_seamless_en_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_rd_seamless_en_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_cas_bc_en_START (15)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_cas_bc_en_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_fulltog_en_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_fulltog_en_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wckpst_mask_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wckpst_mask_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wck_invld_en_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_DDRMODE1_wck_invld_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fsp_op : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_FSP_OP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_FSP_OP_fsp_op_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_FSP_OP_fsp_op_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mirror : 1;
        unsigned int parity_en : 1;
        unsigned int par_dly : 1;
        unsigned int rcd_sdr_mode : 1;
        unsigned int cke_share_map : 2;
        unsigned int reserved_0 : 2;
        unsigned int dimm_sch_gap_rd : 6;
        unsigned int dimm_sch_gap_wr : 6;
        unsigned int rcd_pass_through : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DIMM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_addr_mirror_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_addr_mirror_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_parity_en_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_parity_en_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_par_dly_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_par_dly_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_rcd_sdr_mode_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_rcd_sdr_mode_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_cke_share_map_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_cke_share_map_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_dimm_sch_gap_rd_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_dimm_sch_gap_rd_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_dimm_sch_gap_wr_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_dimm_sch_gap_wr_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_rcd_pass_through_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_DIMM_rcd_pass_through_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ofreq_tick_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_OFREQ_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_OFREQ_ofreq_tick_on_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_OFREQ_ofreq_tick_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int que_level : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DMCLVL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DMCLVL_que_level_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DMCLVL_que_level_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tout_dis : 1;
        unsigned int tout_less_pri : 1;
        unsigned int tout_less_hightout : 1;
        unsigned int tout_prior_lowpri : 1;
        unsigned int reserved_0 : 4;
        unsigned int tout_level_en : 1;
        unsigned int tout_level : 6;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_dis_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_dis_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_less_pri_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_less_pri_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_less_hightout_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_less_hightout_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_prior_lowpri_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_prior_lowpri_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_level_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_level_en_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_level_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT0_tout_level_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeoutprd : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMEOUT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT1_timeoutprd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMEOUT1_timeoutprd_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int priadpt : 4;
        unsigned int reserved_0: 4;
        unsigned int adpt_zoom : 8;
        unsigned int reserved_1: 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_QOS_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_QOS_priadpt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_QOS_priadpt_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_QOS_adpt_zoom_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_QOS_adpt_zoom_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rhit_break_en : 1;
        unsigned int rhit_break_level : 7;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RHIT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_rhit_break_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_rhit_break_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_rhit_break_level_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_RHIT_rhit_break_level_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_ppc_th : 8;
        unsigned int page_opc_th : 8;
        unsigned int page_win_size : 8;
        unsigned int page_win_mode : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PAGE0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_ppc_th_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_ppc_th_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_opc_th_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_opc_th_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_win_size_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_win_size_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_win_mode_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE0_page_win_mode_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int openpage_time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PAGE1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PAGE1_openpage_time_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PAGE1_openpage_time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grp_rw_en : 1;
        unsigned int grp_rank_en : 1;
        unsigned int grp_flat_en : 1;
        unsigned int grp_break_rhit : 1;
        unsigned int reserved_0 : 4;
        unsigned int serial_rlevell : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_GROUP0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_rw_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_rw_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_rank_en_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_rank_en_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_flat_en_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_flat_en_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_break_rhit_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_grp_break_rhit_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_serial_rlevell_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP0_serial_rlevell_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int engrp_level : 7;
        unsigned int exgrp_level : 7;
        unsigned int switch_level : 7;
        unsigned int serial_rlevelh : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_GROUP1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_engrp_level_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_engrp_level_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_exgrp_level_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_exgrp_level_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_switch_level_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_switch_level_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_serial_rlevelh_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP1_serial_rlevelh_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int serial_wlevell : 7;
        unsigned int serial_wlevelh : 7;
        unsigned int cmd_wlevell : 7;
        unsigned int cmd_wlevelh : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_GROUP2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_serial_wlevell_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_serial_wlevell_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_serial_wlevelh_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_serial_wlevelh_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_cmd_wlevell_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_cmd_wlevell_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_cmd_wlevelh_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP2_cmd_wlevelh_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rankserial_rlevell : 7;
        unsigned int rankserial_rlevelh : 7;
        unsigned int rankcmd_rlevel : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_GROUP3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankserial_rlevell_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankserial_rlevell_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankserial_rlevelh_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankserial_rlevelh_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankcmd_rlevel_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP3_rankcmd_rlevel_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rankserial_wlevell : 7;
        unsigned int rankserial_wlevelh : 7;
        unsigned int rankcmd_wlevel : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_GROUP4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankserial_wlevell_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankserial_wlevell_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankserial_wlevelh_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankserial_wlevelh_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankcmd_wlevel_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_GROUP4_rankcmd_wlevel_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrcmd_converge_lvl : 7;
        unsigned int reserved_0 : 17;
        unsigned int in_converge : 1;
        unsigned int reserved_1 : 3;
        unsigned int wrconverge_pri7_en : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_WR_CONVERGE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_wrcmd_converge_lvl_START (0)
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_wrcmd_converge_lvl_END (6)
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_in_converge_START (24)
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_in_converge_END (24)
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_wrconverge_pri7_en_START (28)
#define SOC_DDRC_DMC_DDRC_WR_CONVERGE_wrconverge_pri7_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_2t_en : 1;
        unsigned int cs_2t_pos : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CMD2T_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_cmd_2t_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_cmd_2t_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_cs_2t_pos_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_CMD2T_cs_2t_pos_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyif_tim_oven : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DFI_LAT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT0_phyif_tim_oven_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT0_phyif_tim_oven_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int twrcslat : 4;
        unsigned int trdcslat : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_twrcslat_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_twrcslat_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_trdcslat_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT2_trdcslat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_pipe_num : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PHY_DLY_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PHY_DLY_ac_pipe_num_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PHY_DLY_ac_pipe_num_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wodt : 8;
        unsigned int reserved_0: 8;
        unsigned int rodt : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_ODT_EN_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_wodt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_wodt_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_rodt_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_EN_rodt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_odt : 16;
        unsigned int trodt_ext : 4;
        unsigned int twodt_ext : 4;
        unsigned int func_odt_en : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_ODT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_ODT_ca_odt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_ca_odt_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_trodt_ext_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_trodt_ext_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_twodt_ext_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_twodt_ext_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_func_odt_en_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_ODT_func_odt_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wait_time : 7;
        unsigned int wait_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_wait_time_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_wait_time_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_wait_en_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_WAIT_TIM_wait_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int par_err_inj : 1;
        unsigned int par_inject_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int par_inject_num : 4;
        unsigned int par_inject_cmd : 8;
        unsigned int par_inject_pos : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_err_inj_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_err_inj_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_mask_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_mask_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_num_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_num_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_cmd_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_cmd_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_pos_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_PAR_ERRINJ_par_inject_pos_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_wr_en : 4;
        unsigned int ca_rd_en : 4;
        unsigned int rst_int_mask : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CA_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CA_ca_wr_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CA_ca_wr_en_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_CA_ca_rd_en_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_CA_ca_rd_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_CA_rst_int_mask_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CA_rst_int_mask_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_key0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CA_KEY0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CA_KEY0_ca_key0_START (0)
#define SOC_DDRC_DMC_DDRC_CA_KEY0_ca_key0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_key1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CA_KEY1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CA_KEY1_ca_key1_START (0)
#define SOC_DDRC_DMC_DDRC_CA_KEY1_ca_key1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_rint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_RST_RINT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RST_RINT_rst_rint_START (0)
#define SOC_DDRC_DMC_DDRC_RST_RINT_rst_rint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_intsts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_RST_INTSTS_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RST_INTSTS_rst_intsts_START (0)
#define SOC_DDRC_DMC_DDRC_RST_INTSTS_rst_intsts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eps_rd_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_EPS_RD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_EPS_RD_eps_rd_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_EPS_RD_eps_rd_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eps_wr_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_EPS_WR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_EPS_WR_eps_wr_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_EPS_WR_eps_wr_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eps_key0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_EPS_KEY0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_EPS_KEY0_eps_key0_START (0)
#define SOC_DDRC_DMC_DDRC_EPS_KEY0_eps_key0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eps_key1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_EPS_KEY1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_EPS_KEY1_eps_key1_START (0)
#define SOC_DDRC_DMC_DDRC_EPS_KEY1_eps_key1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oneop_chg_caeps : 1;
        unsigned int reserved_0 : 7;
        unsigned int oneop_chg_ca_ok : 1;
        unsigned int oneop_chg_eps_ok : 1;
        unsigned int oneop_chg_cawr_ok : 1;
        unsigned int oneop_chg_epswr_ok : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CHG_CAEPS_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_caeps_START (0)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_caeps_END (0)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_ca_ok_START (8)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_ca_ok_END (8)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_eps_ok_START (9)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_eps_ok_END (9)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_cawr_ok_START (10)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_cawr_ok_END (10)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_epswr_ok_START (11)
#define SOC_DDRC_DMC_DDRC_CHG_CAEPS_oneop_chg_epswr_ok_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sys_gt_en : 1;
        unsigned int stat_clkon : 1;
        unsigned int cmd_clkon : 1;
        unsigned int data_clkon : 1;
        unsigned int func_clkon : 1;
        unsigned int global_clkon : 1;
        unsigned int pclk_clkon : 1;
        unsigned int preque_clkon : 1;
        unsigned int table_clkon : 1;
        unsigned int slt_clkon : 1;
        unsigned int lvl_clkon : 1;
        unsigned int dmcphy_clkon : 1;
        unsigned int lc_clkon : 1;
        unsigned int exec_clkon : 1;
        unsigned int pstque_clkon : 1;
        unsigned int ca_clkon : 1;
        unsigned int dfi_gate_clkon : 1;
        unsigned int pcfg_clkon : 1;
        unsigned int lecc_clkon : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CLKON_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_sys_gt_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_sys_gt_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_stat_clkon_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_stat_clkon_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_cmd_clkon_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_cmd_clkon_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_data_clkon_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_data_clkon_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_func_clkon_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_func_clkon_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_global_clkon_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_global_clkon_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pclk_clkon_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pclk_clkon_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_preque_clkon_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_preque_clkon_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_table_clkon_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_table_clkon_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_slt_clkon_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_slt_clkon_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lvl_clkon_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lvl_clkon_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_dmcphy_clkon_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_dmcphy_clkon_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lc_clkon_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lc_clkon_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_exec_clkon_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_exec_clkon_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pstque_clkon_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pstque_clkon_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_ca_clkon_START (15)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_ca_clkon_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_dfi_gate_clkon_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_dfi_gate_clkon_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pcfg_clkon_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_pcfg_clkon_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lecc_clkon_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_CLKON_lecc_clkon_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_pd_en : 1;
        unsigned int soft_ram_sd : 1;
        unsigned int soft_ram_ds : 1;
        unsigned int reserved_0 : 1;
        unsigned int dfi_gate_en : 1;
        unsigned int ac_phy_gate_en : 1;
        unsigned int wdata_phy_gate_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int lc_gate_cnt_en : 1;
        unsigned int lc_gate_cnt : 10;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ram_pd_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ram_pd_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_soft_ram_sd_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_soft_ram_sd_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_soft_ram_ds_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_soft_ram_ds_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_dfi_gate_en_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_dfi_gate_en_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_en_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_ac_phy_gate_en_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_wdata_phy_gate_en_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_wdata_phy_gate_en_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_en_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_en_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_WORKMODE_P_lc_gate_cnt_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfi_gate_cmd_ext_cnt : 5;
        unsigned int dfi_gate_wr_ext_cnt : 5;
        unsigned int dfi_gate_rd_ext_cnt : 5;
        unsigned int ac_phy_gate_ext_cnt : 5;
        unsigned int counter_rd_ext : 5;
        unsigned int counter_wr_ext : 6;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_LPGATE_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_cmd_ext_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_cmd_ext_cnt_END (4)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_wr_ext_cnt_START (5)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_wr_ext_cnt_END (9)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_rd_ext_cnt_START (10)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_dfi_gate_rd_ext_cnt_END (14)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_ac_phy_gate_ext_cnt_START (15)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_ac_phy_gate_ext_cnt_END (19)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_counter_rd_ext_START (20)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_counter_rd_ext_END (24)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_counter_wr_ext_START (25)
#define SOC_DDRC_DMC_DDRC_LPGATE_CNT_counter_wr_ext_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_dev_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_ECC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_ECC_ecc_dev_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_ECC_ecc_dev_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scramb_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int scramb_seed_sort : 3;
        unsigned int scramb_seed_type : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SCRAMB_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_seed_sort_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_seed_sort_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_seed_type_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_SCRAMB_scramb_seed_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmi_pattern : 8;
        unsigned int dbi_low_act : 1;
        unsigned int mrr_dbi_byp : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DBI_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DBI_dmi_pattern_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DBI_dmi_pattern_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DBI_dbi_low_act_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DBI_dbi_low_act_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_DBI_mrr_dbi_byp_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_DBI_mrr_dbi_byp_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mrr_map : 24;
        unsigned int mrr_byte : 5;
        unsigned int mrr_training : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_map_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_map_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_byte_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_byte_END (28)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_training_START (29)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP_mrr_training_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mrr_map1 : 24;
        unsigned int mrr_byte1 : 5;
        unsigned int reserved : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_mrr_map1_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_mrr_map1_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_mrr_byte1_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_MRR_MAP1_mrr_byte1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_format : 5;
        unsigned int crc_sdr : 1;
        unsigned int crc_gen_en : 1;
        unsigned int crc_chk_en : 1;
        unsigned int crc_err_set : 1;
        unsigned int crc_chk_bypass : 1;
        unsigned int crc_drop_dis : 1;
        unsigned int crc_chk_bktobk : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CRC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_format_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_format_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_sdr_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_sdr_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_gen_en_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_gen_en_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_en_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_err_set_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_err_set_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_bypass_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_bypass_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_drop_dis_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_drop_dis_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_bktobk_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_crc_chk_bktobk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_err_inj : 1;
        unsigned int crc_err_inj_rd : 1;
        unsigned int reserved_0 : 2;
        unsigned int crc_inject_dm : 1;
        unsigned int reserved_1 : 3;
        unsigned int crc_inject_pat : 8;
        unsigned int crc_inject_num : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_rd_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_err_inj_rd_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_dm_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_dm_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_pat_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_pat_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_num_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ0_crc_inject_num_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_inject_burst : 4;
        unsigned int crc_inject_bl : 18;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_burst_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_burst_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_bl_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_CRC_ERRINJ1_crc_inject_bl_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edxn_dq0_map : 3;
        unsigned int reserved_0 : 1;
        unsigned int edxn_dq1_map : 3;
        unsigned int reserved_1 : 1;
        unsigned int edxn_dq2_map : 3;
        unsigned int reserved_2 : 1;
        unsigned int edxn_dq3_map : 3;
        unsigned int reserved_3 : 1;
        unsigned int edxn_dq4_map : 3;
        unsigned int reserved_4 : 1;
        unsigned int edxn_dq5_map : 3;
        unsigned int reserved_5 : 1;
        unsigned int edxn_dq6_map : 3;
        unsigned int reserved_6 : 1;
        unsigned int edxn_dq7_map : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq0_map_START (0)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq0_map_END (2)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq1_map_START (4)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq1_map_END (6)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq2_map_START (8)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq2_map_END (10)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq3_map_START (12)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq3_map_END (14)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq4_map_START (16)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq4_map_END (18)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq5_map_START (20)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq5_map_END (22)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq6_map_START (24)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq6_map_END (26)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq7_map_START (28)
#define SOC_DDRC_DMC_DDRC_CRC_EDXN_DQMAP_edxn_dq7_map_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int odxn_dq0_map : 3;
        unsigned int reserved_0 : 1;
        unsigned int odxn_dq1_map : 3;
        unsigned int reserved_1 : 1;
        unsigned int odxn_dq2_map : 3;
        unsigned int reserved_2 : 1;
        unsigned int odxn_dq3_map : 3;
        unsigned int reserved_3 : 1;
        unsigned int odxn_dq4_map : 3;
        unsigned int reserved_4 : 1;
        unsigned int odxn_dq5_map : 3;
        unsigned int reserved_5 : 1;
        unsigned int odxn_dq6_map : 3;
        unsigned int reserved_6 : 1;
        unsigned int odxn_dq7_map : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq0_map_START (0)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq0_map_END (2)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq1_map_START (4)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq1_map_END (6)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq2_map_START (8)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq2_map_END (10)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq3_map_START (12)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq3_map_END (14)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq4_map_START (16)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq4_map_END (18)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq5_map_START (20)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq5_map_END (22)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq6_map_START (24)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq6_map_END (26)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq7_map_START (28)
#define SOC_DDRC_DMC_DDRC_CRC_ODXN_DQMAP_odxn_dq7_map_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr5_otf_act_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DDR5_TMP_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DDR5_TMP_ddr5_otf_act_mode_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DDR5_TMP_ddr5_otf_act_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lecc_inj_pat : 8;
        unsigned int inj_bt : 2;
        unsigned int rdata_inj_en : 1;
        unsigned int wrmask_inj_en : 1;
        unsigned int wrdata_inj_en : 1;
        unsigned int chk_rd_en : 1;
        unsigned int chk_wr_en : 1;
        unsigned int lecc_obit_cnt_clr : 1;
        unsigned int lecc_obit_thres : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_inj_pat_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_inj_pat_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_inj_bt_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_inj_bt_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_rdata_inj_en_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_rdata_inj_en_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_wrmask_inj_en_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_wrmask_inj_en_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_wrdata_inj_en_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_wrdata_inj_en_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_chk_rd_en_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_chk_rd_en_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_chk_wr_en_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_chk_wr_en_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_cnt_clr_START (15)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_cnt_clr_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_thres_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL0_lecc_obit_thres_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lecc_inj_num : 5;
        unsigned int lecc_burst : 4;
        unsigned int err_inf_clr : 1;
        unsigned int err_inj_mode : 1;
        unsigned int wecc_inj_en : 1;
        unsigned int wmsk_ecc_inj_en : 1;
        unsigned int recc_inj_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_lecc_inj_num_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_lecc_inj_num_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_lecc_burst_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_lecc_burst_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_err_inf_clr_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_err_inf_clr_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_err_inj_mode_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_err_inj_mode_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_wecc_inj_en_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_wecc_inj_en_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_wmsk_ecc_inj_en_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_wmsk_ecc_inj_en_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_recc_inj_en_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_LECC_CTRL1_recc_inj_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_ratio : 2;
        unsigned int brstlen : 2;
        unsigned int wr_otf_en : 1;
        unsigned int rd_otf_en : 1;
        unsigned int rd_dbi_en : 1;
        unsigned int wr_dbi_en : 1;
        unsigned int aref_ch_mode : 1;
        unsigned int bg_mode : 1;
        unsigned int lp5_ofreq_phase : 1;
        unsigned int lp5_ofreq_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_clk_ratio_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_clk_ratio_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_brstlen_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_brstlen_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_wr_otf_en_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_wr_otf_en_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_rd_otf_en_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_rd_otf_en_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_rd_dbi_en_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_rd_dbi_en_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_wr_dbi_en_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_wr_dbi_en_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_aref_ch_mode_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_aref_ch_mode_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_bg_mode_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_bg_mode_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_phase_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_phase_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_en_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_DDRVMODE_lp5_ofreq_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tfaw : 7;
        unsigned int tpbr2act : 7;
        unsigned int reserved_0: 2;
        unsigned int trrd : 5;
        unsigned int trrd_l : 5;
        unsigned int tact2pbr : 5;
        unsigned int reserved_1: 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tfaw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tfaw_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tpbr2act_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tpbr2act_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_trrd_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_trrd_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_trrd_l_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_trrd_l_END (25)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tact2pbr_START (26)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING0_tact2pbr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trfc_pb : 9;
        unsigned int reserved_0: 1;
        unsigned int trfc_ab : 10;
        unsigned int tpbr2pbr : 8;
        unsigned int reserved_1: 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_trfc_pb_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_trfc_pb_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_trfc_ab_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_trfc_ab_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_tpbr2pbr_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING1_tpbr2pbr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tras : 7;
        unsigned int reserved_0: 1;
        unsigned int twr : 7;
        unsigned int reserved_1: 1;
        unsigned int trp_pb : 6;
        unsigned int reserved_2: 2;
        unsigned int tppd : 4;
        unsigned int reserved_3: 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_tras_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_tras_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_twr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_twr_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_trp_pb_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_trp_pb_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_tppd_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING2_tppd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trtp : 5;
        unsigned int reserved_0: 3;
        unsigned int trp_ab : 6;
        unsigned int reserved_1: 5;
        unsigned int nwr : 7;
        unsigned int nrtp : 5;
        unsigned int reserved_2: 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_trtp_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_trtp_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_trp_ab_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_trp_ab_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_nwr_START (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_nwr_END (25)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_nrtp_START (26)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING3_nrtp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trcd : 6;
        unsigned int reserved_0: 2;
        unsigned int twtr : 5;
        unsigned int reserved_1: 3;
        unsigned int twtr_l : 5;
        unsigned int reserved_2: 3;
        unsigned int trtw : 4;
        unsigned int reserved_3: 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_trcd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_trcd_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_twtr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_twtr_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_twtr_l_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_twtr_l_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_trtw_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING4_trtw_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tccdmw16 : 6;
        unsigned int tccdmw32 : 6;
        unsigned int tccd_l : 5;
        unsigned int tccd : 5;
        unsigned int tccd_nsr : 5;
        unsigned int tccd_nsw : 5;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccdmw16_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccdmw16_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccdmw32_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccdmw32_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_l_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_l_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_nsr_START (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_nsr_END (26)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_nsw_START (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING5_tccd_nsw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcl : 6;
        unsigned int reserved_0: 2;
        unsigned int twl : 6;
        unsigned int reserved_1: 2;
        unsigned int tdqsckmax : 4;
        unsigned int tdqsck : 4;
        unsigned int reserved_2: 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tcl_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tcl_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_twl_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_twl_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tdqsckmax_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tdqsckmax_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tdqsck_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING6_tdqsck_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wck2dqo_max : 2;
        unsigned int t7p5ns_8ck : 5;
        unsigned int reserved : 5;
        unsigned int wck_pst : 4;
        unsigned int wr_pre : 4;
        unsigned int rd_pre : 4;
        unsigned int wr_pst : 4;
        unsigned int rd_pst : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wck2dqo_max_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wck2dqo_max_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_t7p5ns_8ck_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_t7p5ns_8ck_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wck_pst_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wck_pst_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wr_pre_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wr_pre_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_rd_pre_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_rd_pre_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wr_pst_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_wr_pst_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_rd_pst_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING7_rd_pst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int twckenl_wr : 4;
        unsigned int reserved_0 : 4;
        unsigned int twckenl_rd : 4;
        unsigned int reserved_1 : 4;
        unsigned int twckpre_static : 4;
        unsigned int reserved_2 : 4;
        unsigned int twckenl_fs : 4;
        unsigned int cas_off_tim : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_wr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_wr_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_rd_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_rd_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckpre_static_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckpre_static_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_fs_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_twckenl_fs_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_cas_off_tim_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING8_cas_off_tim_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmrw : 6;
        unsigned int trfmab : 10;
        unsigned int tmrr : 6;
        unsigned int tmrd : 6;
        unsigned int cas_fs2off_tim : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrw_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_trfmab_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_trfmab_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrr_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrr_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrd_START (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_tmrd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_cas_fs2off_tim_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING9_cas_fs2off_tim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tckckel : 5;
        unsigned int reserved_0: 3;
        unsigned int tckckeh : 5;
        unsigned int reserved_1: 3;
        unsigned int tsr : 6;
        unsigned int reserved_2: 2;
        unsigned int txsr : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tckckel_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tckckel_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tckckeh_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tckckeh_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tsr_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_tsr_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_txsr_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING10_txsr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcmdcke : 4;
        unsigned int tcspd : 5;
        unsigned int reserved_0: 7;
        unsigned int tescke : 4;
        unsigned int reserved_1: 4;
        unsigned int tckehcmd : 5;
        unsigned int reserved_2: 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tcmdcke_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tcmdcke_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tcspd_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tcspd_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tescke_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tescke_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tckehcmd_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING11_tckehcmd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int txp : 5;
        unsigned int reserved_0 : 3;
        unsigned int tcke : 5;
        unsigned int reserved_1 : 1;
        unsigned int tcsh : 13;
        unsigned int tcsl : 3;
        unsigned int tca2cs_pre : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING12_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_txp_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_txp_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcke_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcke_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcsh_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcsh_END (26)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcsl_START (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tcsl_END (29)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tca2cs_pre_START (30)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING12_tca2cs_pre_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzqcal : 12;
        unsigned int reserved_0: 4;
        unsigned int tzqlat : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING13_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_tzqcal_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_tzqcal_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_tzqlat_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING13_tzqlat_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wodt_on : 1;
        unsigned int reserved_0 : 15;
        unsigned int odtlon : 5;
        unsigned int reserved_1 : 3;
        unsigned int todton_min : 4;
        unsigned int todtoff_max : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING14_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_wodt_on_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_wodt_on_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_odtlon_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_odtlon_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_todton_min_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_todton_min_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_todtoff_max_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING14_todtoff_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rnk_twtr : 5;
        unsigned int reserved_0: 3;
        unsigned int rnk_trtw : 5;
        unsigned int reserved_1: 3;
        unsigned int rnk_twtw : 5;
        unsigned int reserved_2: 3;
        unsigned int rnk_trtr : 5;
        unsigned int reserved_3: 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIMING15_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_twtr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_twtr_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_trtw_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_trtw_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_twtw_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_twtw_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_trtr_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIMING15_rnk_trtr_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_o_run_time : 16;
        unsigned int osc_i_run_time : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_osc_o_run_time_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_osc_o_run_time_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_osc_i_run_time_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC0_osc_i_run_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tosco_o : 8;
        unsigned int tosco_i : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_tosco_o_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_tosco_o_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_tosco_i_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_OSC1_tosco_i_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tsd2ds : 5;
        unsigned int tdslpwk2clk : 7;
        unsigned int reserved : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_RAM_PD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_tsd2ds_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_tsd2ds_END (4)
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_tdslpwk2clk_START (5)
#define SOC_DDRC_DMC_DDRC_CFG_RAM_PD_tdslpwk2clk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trmrw : 7;
        unsigned int reserved_0: 1;
        unsigned int trapmrw : 7;
        unsigned int reserved_1: 1;
        unsigned int trtrrd : 7;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 5;
        unsigned int reserved_4: 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trmrw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trmrw_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trapmrw_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trapmrw_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trtrrd_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK0_trtrrd_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int twmrw : 7;
        unsigned int reserved_0: 1;
        unsigned int twapmrw : 7;
        unsigned int reserved_1: 1;
        unsigned int twrwtr : 7;
        unsigned int reserved_2: 1;
        unsigned int cmdtwtr_l : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twmrw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twmrw_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twapmrw_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twapmrw_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twrwtr_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_twrwtr_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_cmdtwtr_l_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK1_cmdtwtr_l_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmrri : 6;
        unsigned int reserved_0: 2;
        unsigned int tmpcwr : 6;
        unsigned int reserved_1: 10;
        unsigned int trtmrr : 6;
        unsigned int reserved_2: 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_tmrri_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_tmrri_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_tmpcwr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_tmpcwr_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_trtmrr_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK2_trtmrr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trtpd : 7;
        unsigned int reserved_0: 1;
        unsigned int cmdtwtr : 7;
        unsigned int reserved_1: 1;
        unsigned int cmdtrtw : 7;
        unsigned int reserved_2: 1;
        unsigned int cmdnrtp : 6;
        unsigned int reserved_3: 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_trtpd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_trtpd_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdtwtr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdtwtr_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdtrtw_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdtrtw_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdnrtp_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK3_cmdnrtp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdnwr : 7;
        unsigned int reserved_0: 1;
        unsigned int cmdtwr : 7;
        unsigned int reserved_1: 1;
        unsigned int twr_func : 7;
        unsigned int reserved_2: 1;
        unsigned int cmdtrtp : 6;
        unsigned int reserved_3: 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdnwr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdnwr_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdtwr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdtwr_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_twr_func_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_twr_func_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdtrtp_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK4_cmdtrtp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ranktwtw : 7;
        unsigned int reserved_0: 1;
        unsigned int ranktwtr : 7;
        unsigned int reserved_1: 1;
        unsigned int ranktrtr : 7;
        unsigned int reserved_2: 1;
        unsigned int ranktrtw : 7;
        unsigned int reserved_3: 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktwtw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktwtw_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktwtr_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktwtr_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktrtr_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktrtr_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktrtw_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK5_ranktrtw_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wsync_tim : 6;
        unsigned int reserved_0: 2;
        unsigned int rsync_tim : 6;
        unsigned int reserved_1: 2;
        unsigned int wsync_otf : 6;
        unsigned int reserved_2: 2;
        unsigned int rsync_otf : 6;
        unsigned int reserved_3: 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_wsync_tim_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_wsync_tim_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_rsync_tim_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_rsync_tim_END (13)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_wsync_otf_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_wsync_otf_END (21)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_rsync_otf_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK6_rsync_otf_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trc : 8;
        unsigned int reserved_0: 8;
        unsigned int wck_shift : 3;
        unsigned int wck_dir : 1;
        unsigned int cmdtrtw_l : 7;
        unsigned int reserved_1: 1;
        unsigned int rl_rd_pre : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_trc_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_trc_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_wck_shift_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_wck_shift_END (18)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_wck_dir_START (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_wck_dir_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_cmdtrtw_l_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_cmdtrtw_l_END (26)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_rl_rd_pre_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK7_rl_rd_pre_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ranktwtw_bc : 7;
        unsigned int reserved_0 : 1;
        unsigned int ranktwtr_bc : 7;
        unsigned int reserved_1 : 1;
        unsigned int ranktrtr_bc : 7;
        unsigned int reserved_2 : 1;
        unsigned int ranktrtw_bc : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktwtw_bc_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktwtw_bc_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktwtr_bc_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktwtr_bc_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktrtr_bc_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktrtr_bc_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktrtw_bc_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK8_ranktrtw_bc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ranktwtw_bc_otf : 7;
        unsigned int reserved_0 : 1;
        unsigned int ranktwtr_bc_otf : 7;
        unsigned int reserved_1 : 1;
        unsigned int ranktrtr_bc_otf : 7;
        unsigned int reserved_2 : 1;
        unsigned int ranktrtw_bc_otf : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktwtw_bc_otf_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktwtw_bc_otf_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktwtr_bc_otf_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktwtr_bc_otf_END (14)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktrtr_bc_otf_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktrtr_bc_otf_END (22)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktrtw_bc_otf_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK9_ranktrtw_bc_otf_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tccdmw_4bl : 6;
        unsigned int tccdmw_2p5bl : 6;
        unsigned int tccdmw_1bl : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_4bl_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_4bl_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_2p5bl_START (6)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_2p5bl_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_1bl_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_TIM_BAK10_tccdmw_1bl_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int fulltog_prd_rd : 7;
        unsigned int fulltog_prd_rd_otf : 7;
        unsigned int fulltog_prd_wr : 7;
        unsigned int fulltog_prd_wr_otf : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_otf_START (11)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_rd_otf_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_END (24)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_otf_START (25)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK0_fulltog_prd_wr_otf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wck_invld : 4;
        unsigned int wck_invld_ext : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_wck_invld_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_wck_invld_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_wck_invld_ext_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_WCK_BAK1_wck_invld_ext_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyif_tim_wck : 8;
        unsigned int phyif_tim_wodt : 8;
        unsigned int phyif_tim_rodt : 8;
        unsigned int phyif_tim_wden : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wck_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wck_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wodt_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wodt_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_rodt_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_rodt_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wden_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT5_phyif_tim_wden_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyif_tim_wdcs : 8;
        unsigned int phyif_tim_wdda : 8;
        unsigned int phyif_tim_rden : 8;
        unsigned int phyif_tim_rdcs : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdcs_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdcs_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdda_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_wdda_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rden_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rden_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rdcs_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_DFI_LAT6_phyif_tim_rdcs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdtimeout_int_mask : 1;
        unsigned int aref_alarm_int_mask : 1;
        unsigned int osc_o_overflow_int_mask : 1;
        unsigned int osc_i_overflow_int_mask : 1;
        unsigned int sbram_merr_int_mask : 1;
        unsigned int recram_merr_int_mask : 1;
        unsigned int rpram_merr_int_mask : 1;
        unsigned int rec_derr_int_mask : 1;
        unsigned int rec_col_int_mask : 1;
        unsigned int rec_unsup_int_mask : 1;
        unsigned int monram_merr_int_mask : 1;
        unsigned int reserved : 1;
        unsigned int tmon_err_int_mask : 8;
        unsigned int merr_int_mask : 1;
        unsigned int sref_err_int_mask : 1;
        unsigned int dimm_parity_int_mask : 1;
        unsigned int rec_alert_int_mask : 1;
        unsigned int crc_rderr_int_mask : 1;
        unsigned int wsram_merr_int_mask : 1;
        unsigned int osc_o_ovth_int_mask : 1;
        unsigned int osc_i_ovth_int_mask : 1;
        unsigned int rcmdre_int_mask : 1;
        unsigned int phyram_int_mask : 1;
        unsigned int dis_rnk_int_mask : 1;
        unsigned int lecc_merr_int_mask : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_INTMSK0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTMSK0_rdtimeout_int_mask_START (0)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rdtimeout_int_mask_END (0)
#define SOC_DDRC_DMC_DDRC_INTMSK0_aref_alarm_int_mask_START (1)
#define SOC_DDRC_DMC_DDRC_INTMSK0_aref_alarm_int_mask_END (1)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_o_overflow_int_mask_START (2)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_o_overflow_int_mask_END (2)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_i_overflow_int_mask_START (3)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_i_overflow_int_mask_END (3)
#define SOC_DDRC_DMC_DDRC_INTMSK0_sbram_merr_int_mask_START (4)
#define SOC_DDRC_DMC_DDRC_INTMSK0_sbram_merr_int_mask_END (4)
#define SOC_DDRC_DMC_DDRC_INTMSK0_recram_merr_int_mask_START (5)
#define SOC_DDRC_DMC_DDRC_INTMSK0_recram_merr_int_mask_END (5)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rpram_merr_int_mask_START (6)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rpram_merr_int_mask_END (6)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_derr_int_mask_START (7)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_derr_int_mask_END (7)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_col_int_mask_START (8)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_col_int_mask_END (8)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_unsup_int_mask_START (9)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_unsup_int_mask_END (9)
#define SOC_DDRC_DMC_DDRC_INTMSK0_monram_merr_int_mask_START (10)
#define SOC_DDRC_DMC_DDRC_INTMSK0_monram_merr_int_mask_END (10)
#define SOC_DDRC_DMC_DDRC_INTMSK0_tmon_err_int_mask_START (12)
#define SOC_DDRC_DMC_DDRC_INTMSK0_tmon_err_int_mask_END (19)
#define SOC_DDRC_DMC_DDRC_INTMSK0_merr_int_mask_START (20)
#define SOC_DDRC_DMC_DDRC_INTMSK0_merr_int_mask_END (20)
#define SOC_DDRC_DMC_DDRC_INTMSK0_sref_err_int_mask_START (21)
#define SOC_DDRC_DMC_DDRC_INTMSK0_sref_err_int_mask_END (21)
#define SOC_DDRC_DMC_DDRC_INTMSK0_dimm_parity_int_mask_START (22)
#define SOC_DDRC_DMC_DDRC_INTMSK0_dimm_parity_int_mask_END (22)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_alert_int_mask_START (23)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rec_alert_int_mask_END (23)
#define SOC_DDRC_DMC_DDRC_INTMSK0_crc_rderr_int_mask_START (24)
#define SOC_DDRC_DMC_DDRC_INTMSK0_crc_rderr_int_mask_END (24)
#define SOC_DDRC_DMC_DDRC_INTMSK0_wsram_merr_int_mask_START (25)
#define SOC_DDRC_DMC_DDRC_INTMSK0_wsram_merr_int_mask_END (25)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_o_ovth_int_mask_START (26)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_o_ovth_int_mask_END (26)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_i_ovth_int_mask_START (27)
#define SOC_DDRC_DMC_DDRC_INTMSK0_osc_i_ovth_int_mask_END (27)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rcmdre_int_mask_START (28)
#define SOC_DDRC_DMC_DDRC_INTMSK0_rcmdre_int_mask_END (28)
#define SOC_DDRC_DMC_DDRC_INTMSK0_phyram_int_mask_START (29)
#define SOC_DDRC_DMC_DDRC_INTMSK0_phyram_int_mask_END (29)
#define SOC_DDRC_DMC_DDRC_INTMSK0_dis_rnk_int_mask_START (30)
#define SOC_DDRC_DMC_DDRC_INTMSK0_dis_rnk_int_mask_END (30)
#define SOC_DDRC_DMC_DDRC_INTMSK0_lecc_merr_int_mask_START (31)
#define SOC_DDRC_DMC_DDRC_INTMSK0_lecc_merr_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_upd_int_mask : 8;
        unsigned int osc_o_rd_int_mask : 1;
        unsigned int osc_i_rd_int_mask : 1;
        unsigned int flux_int_mask : 1;
        unsigned int stacmd_min_int_mask : 1;
        unsigned int stacmd_max_int_mask : 1;
        unsigned int stadat_min_int_mask : 1;
        unsigned int stadat_max_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int serr_int_mask : 1;
        unsigned int wsram_serr_int_mask : 1;
        unsigned int sbram_serr_int_mask : 1;
        unsigned int rpram_serr_int_mask : 1;
        unsigned int recram_serr_int_mask : 1;
        unsigned int monram_serr_int_mask : 1;
        unsigned int raammt_int_mask : 1;
        unsigned int raaimt_int_mask : 1;
        unsigned int lecc_serr_int_mask : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_INTMSK1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTMSK1_tmon_upd_int_mask_START (0)
#define SOC_DDRC_DMC_DDRC_INTMSK1_tmon_upd_int_mask_END (7)
#define SOC_DDRC_DMC_DDRC_INTMSK1_osc_o_rd_int_mask_START (8)
#define SOC_DDRC_DMC_DDRC_INTMSK1_osc_o_rd_int_mask_END (8)
#define SOC_DDRC_DMC_DDRC_INTMSK1_osc_i_rd_int_mask_START (9)
#define SOC_DDRC_DMC_DDRC_INTMSK1_osc_i_rd_int_mask_END (9)
#define SOC_DDRC_DMC_DDRC_INTMSK1_flux_int_mask_START (10)
#define SOC_DDRC_DMC_DDRC_INTMSK1_flux_int_mask_END (10)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stacmd_min_int_mask_START (11)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stacmd_min_int_mask_END (11)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stacmd_max_int_mask_START (12)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stacmd_max_int_mask_END (12)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stadat_min_int_mask_START (13)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stadat_min_int_mask_END (13)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stadat_max_int_mask_START (14)
#define SOC_DDRC_DMC_DDRC_INTMSK1_stadat_max_int_mask_END (14)
#define SOC_DDRC_DMC_DDRC_INTMSK1_serr_int_mask_START (16)
#define SOC_DDRC_DMC_DDRC_INTMSK1_serr_int_mask_END (16)
#define SOC_DDRC_DMC_DDRC_INTMSK1_wsram_serr_int_mask_START (17)
#define SOC_DDRC_DMC_DDRC_INTMSK1_wsram_serr_int_mask_END (17)
#define SOC_DDRC_DMC_DDRC_INTMSK1_sbram_serr_int_mask_START (18)
#define SOC_DDRC_DMC_DDRC_INTMSK1_sbram_serr_int_mask_END (18)
#define SOC_DDRC_DMC_DDRC_INTMSK1_rpram_serr_int_mask_START (19)
#define SOC_DDRC_DMC_DDRC_INTMSK1_rpram_serr_int_mask_END (19)
#define SOC_DDRC_DMC_DDRC_INTMSK1_recram_serr_int_mask_START (20)
#define SOC_DDRC_DMC_DDRC_INTMSK1_recram_serr_int_mask_END (20)
#define SOC_DDRC_DMC_DDRC_INTMSK1_monram_serr_int_mask_START (21)
#define SOC_DDRC_DMC_DDRC_INTMSK1_monram_serr_int_mask_END (21)
#define SOC_DDRC_DMC_DDRC_INTMSK1_raammt_int_mask_START (22)
#define SOC_DDRC_DMC_DDRC_INTMSK1_raammt_int_mask_END (22)
#define SOC_DDRC_DMC_DDRC_INTMSK1_raaimt_int_mask_START (23)
#define SOC_DDRC_DMC_DDRC_INTMSK1_raaimt_int_mask_END (23)
#define SOC_DDRC_DMC_DDRC_INTMSK1_lecc_serr_int_mask_START (24)
#define SOC_DDRC_DMC_DDRC_INTMSK1_lecc_serr_int_mask_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdtimeout_rint : 1;
        unsigned int aref_alarm_rint : 1;
        unsigned int osc_o_overflow_rint : 1;
        unsigned int osc_i_overflow_rint : 1;
        unsigned int sbram_merr_rint : 1;
        unsigned int recram_merr_rint : 1;
        unsigned int rpram_merr_rint : 1;
        unsigned int rec_derr_rint : 1;
        unsigned int rec_col_rint : 1;
        unsigned int rec_unsup_rint : 1;
        unsigned int monram_merr_rint : 1;
        unsigned int reserved : 1;
        unsigned int tmon_err_rint : 8;
        unsigned int merr_rint : 1;
        unsigned int sref_err_rint : 1;
        unsigned int dimm_parity_rint : 1;
        unsigned int rec_alert_rint : 1;
        unsigned int crc_rderr_rint : 1;
        unsigned int wsram_merr_rint : 1;
        unsigned int osc_o_ovth_rint : 1;
        unsigned int osc_i_ovth_rint : 1;
        unsigned int rcmdre_rint : 1;
        unsigned int phyram_rint : 1;
        unsigned int dis_rnk_rint : 1;
        unsigned int lecc_merr_rint : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_RINT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RINT0_rdtimeout_rint_START (0)
#define SOC_DDRC_DMC_DDRC_RINT0_rdtimeout_rint_END (0)
#define SOC_DDRC_DMC_DDRC_RINT0_aref_alarm_rint_START (1)
#define SOC_DDRC_DMC_DDRC_RINT0_aref_alarm_rint_END (1)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_o_overflow_rint_START (2)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_o_overflow_rint_END (2)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_i_overflow_rint_START (3)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_i_overflow_rint_END (3)
#define SOC_DDRC_DMC_DDRC_RINT0_sbram_merr_rint_START (4)
#define SOC_DDRC_DMC_DDRC_RINT0_sbram_merr_rint_END (4)
#define SOC_DDRC_DMC_DDRC_RINT0_recram_merr_rint_START (5)
#define SOC_DDRC_DMC_DDRC_RINT0_recram_merr_rint_END (5)
#define SOC_DDRC_DMC_DDRC_RINT0_rpram_merr_rint_START (6)
#define SOC_DDRC_DMC_DDRC_RINT0_rpram_merr_rint_END (6)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_derr_rint_START (7)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_derr_rint_END (7)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_col_rint_START (8)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_col_rint_END (8)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_unsup_rint_START (9)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_unsup_rint_END (9)
#define SOC_DDRC_DMC_DDRC_RINT0_monram_merr_rint_START (10)
#define SOC_DDRC_DMC_DDRC_RINT0_monram_merr_rint_END (10)
#define SOC_DDRC_DMC_DDRC_RINT0_tmon_err_rint_START (12)
#define SOC_DDRC_DMC_DDRC_RINT0_tmon_err_rint_END (19)
#define SOC_DDRC_DMC_DDRC_RINT0_merr_rint_START (20)
#define SOC_DDRC_DMC_DDRC_RINT0_merr_rint_END (20)
#define SOC_DDRC_DMC_DDRC_RINT0_sref_err_rint_START (21)
#define SOC_DDRC_DMC_DDRC_RINT0_sref_err_rint_END (21)
#define SOC_DDRC_DMC_DDRC_RINT0_dimm_parity_rint_START (22)
#define SOC_DDRC_DMC_DDRC_RINT0_dimm_parity_rint_END (22)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_alert_rint_START (23)
#define SOC_DDRC_DMC_DDRC_RINT0_rec_alert_rint_END (23)
#define SOC_DDRC_DMC_DDRC_RINT0_crc_rderr_rint_START (24)
#define SOC_DDRC_DMC_DDRC_RINT0_crc_rderr_rint_END (24)
#define SOC_DDRC_DMC_DDRC_RINT0_wsram_merr_rint_START (25)
#define SOC_DDRC_DMC_DDRC_RINT0_wsram_merr_rint_END (25)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_o_ovth_rint_START (26)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_o_ovth_rint_END (26)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_i_ovth_rint_START (27)
#define SOC_DDRC_DMC_DDRC_RINT0_osc_i_ovth_rint_END (27)
#define SOC_DDRC_DMC_DDRC_RINT0_rcmdre_rint_START (28)
#define SOC_DDRC_DMC_DDRC_RINT0_rcmdre_rint_END (28)
#define SOC_DDRC_DMC_DDRC_RINT0_phyram_rint_START (29)
#define SOC_DDRC_DMC_DDRC_RINT0_phyram_rint_END (29)
#define SOC_DDRC_DMC_DDRC_RINT0_dis_rnk_rint_START (30)
#define SOC_DDRC_DMC_DDRC_RINT0_dis_rnk_rint_END (30)
#define SOC_DDRC_DMC_DDRC_RINT0_lecc_merr_rint_START (31)
#define SOC_DDRC_DMC_DDRC_RINT0_lecc_merr_rint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_upd_rint : 8;
        unsigned int osc_o_rd_rint : 1;
        unsigned int osc_i_rd_rint : 1;
        unsigned int flux_rint : 1;
        unsigned int stacmd_min_rint : 1;
        unsigned int stacmd_max_rint : 1;
        unsigned int stadat_min_rint : 1;
        unsigned int stadat_max_rint : 1;
        unsigned int reserved_0 : 1;
        unsigned int serr_rint : 1;
        unsigned int wsram_serr_rint : 1;
        unsigned int sbram_serr_rint : 1;
        unsigned int rpram_serr_rint : 1;
        unsigned int recram_serr_rint : 1;
        unsigned int monram_serr_rint : 1;
        unsigned int raammt_rint : 1;
        unsigned int raaimt_rint : 1;
        unsigned int lecc_serr_rint : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_RINT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RINT1_tmon_upd_rint_START (0)
#define SOC_DDRC_DMC_DDRC_RINT1_tmon_upd_rint_END (7)
#define SOC_DDRC_DMC_DDRC_RINT1_osc_o_rd_rint_START (8)
#define SOC_DDRC_DMC_DDRC_RINT1_osc_o_rd_rint_END (8)
#define SOC_DDRC_DMC_DDRC_RINT1_osc_i_rd_rint_START (9)
#define SOC_DDRC_DMC_DDRC_RINT1_osc_i_rd_rint_END (9)
#define SOC_DDRC_DMC_DDRC_RINT1_flux_rint_START (10)
#define SOC_DDRC_DMC_DDRC_RINT1_flux_rint_END (10)
#define SOC_DDRC_DMC_DDRC_RINT1_stacmd_min_rint_START (11)
#define SOC_DDRC_DMC_DDRC_RINT1_stacmd_min_rint_END (11)
#define SOC_DDRC_DMC_DDRC_RINT1_stacmd_max_rint_START (12)
#define SOC_DDRC_DMC_DDRC_RINT1_stacmd_max_rint_END (12)
#define SOC_DDRC_DMC_DDRC_RINT1_stadat_min_rint_START (13)
#define SOC_DDRC_DMC_DDRC_RINT1_stadat_min_rint_END (13)
#define SOC_DDRC_DMC_DDRC_RINT1_stadat_max_rint_START (14)
#define SOC_DDRC_DMC_DDRC_RINT1_stadat_max_rint_END (14)
#define SOC_DDRC_DMC_DDRC_RINT1_serr_rint_START (16)
#define SOC_DDRC_DMC_DDRC_RINT1_serr_rint_END (16)
#define SOC_DDRC_DMC_DDRC_RINT1_wsram_serr_rint_START (17)
#define SOC_DDRC_DMC_DDRC_RINT1_wsram_serr_rint_END (17)
#define SOC_DDRC_DMC_DDRC_RINT1_sbram_serr_rint_START (18)
#define SOC_DDRC_DMC_DDRC_RINT1_sbram_serr_rint_END (18)
#define SOC_DDRC_DMC_DDRC_RINT1_rpram_serr_rint_START (19)
#define SOC_DDRC_DMC_DDRC_RINT1_rpram_serr_rint_END (19)
#define SOC_DDRC_DMC_DDRC_RINT1_recram_serr_rint_START (20)
#define SOC_DDRC_DMC_DDRC_RINT1_recram_serr_rint_END (20)
#define SOC_DDRC_DMC_DDRC_RINT1_monram_serr_rint_START (21)
#define SOC_DDRC_DMC_DDRC_RINT1_monram_serr_rint_END (21)
#define SOC_DDRC_DMC_DDRC_RINT1_raammt_rint_START (22)
#define SOC_DDRC_DMC_DDRC_RINT1_raammt_rint_END (22)
#define SOC_DDRC_DMC_DDRC_RINT1_raaimt_rint_START (23)
#define SOC_DDRC_DMC_DDRC_RINT1_raaimt_rint_END (23)
#define SOC_DDRC_DMC_DDRC_RINT1_lecc_serr_rint_START (24)
#define SOC_DDRC_DMC_DDRC_RINT1_lecc_serr_rint_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdtimeout_intsts : 1;
        unsigned int aref_alarm_intsts : 1;
        unsigned int osc_o_overflow_intsts : 1;
        unsigned int osc_i_overflow_intsts : 1;
        unsigned int sbram_merr_intsts : 1;
        unsigned int recram_merr_intsts : 1;
        unsigned int rpram_merr_intsts : 1;
        unsigned int rec_derr_intsts : 1;
        unsigned int rec_col_intsts : 1;
        unsigned int rec_unsup_intsts : 1;
        unsigned int monram_merr_intsts : 1;
        unsigned int reserved : 1;
        unsigned int tmon_err_intsts : 8;
        unsigned int merr_intsts : 1;
        unsigned int sref_err_intsts : 1;
        unsigned int dimm_parity_intsts : 1;
        unsigned int rec_alert_intsts : 1;
        unsigned int crc_rderr_intsts : 1;
        unsigned int wsram_merr_intsts : 1;
        unsigned int osc_o_ovth_intsts : 1;
        unsigned int osc_i_ovth_intsts : 1;
        unsigned int rcmdre_intsts : 1;
        unsigned int phyram_intsts : 1;
        unsigned int dis_rnk_intsts : 1;
        unsigned int lecc_merr_intsts : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_INTSTS0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTSTS0_rdtimeout_intsts_START (0)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rdtimeout_intsts_END (0)
#define SOC_DDRC_DMC_DDRC_INTSTS0_aref_alarm_intsts_START (1)
#define SOC_DDRC_DMC_DDRC_INTSTS0_aref_alarm_intsts_END (1)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_o_overflow_intsts_START (2)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_o_overflow_intsts_END (2)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_i_overflow_intsts_START (3)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_i_overflow_intsts_END (3)
#define SOC_DDRC_DMC_DDRC_INTSTS0_sbram_merr_intsts_START (4)
#define SOC_DDRC_DMC_DDRC_INTSTS0_sbram_merr_intsts_END (4)
#define SOC_DDRC_DMC_DDRC_INTSTS0_recram_merr_intsts_START (5)
#define SOC_DDRC_DMC_DDRC_INTSTS0_recram_merr_intsts_END (5)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rpram_merr_intsts_START (6)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rpram_merr_intsts_END (6)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_derr_intsts_START (7)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_derr_intsts_END (7)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_col_intsts_START (8)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_col_intsts_END (8)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_unsup_intsts_START (9)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_unsup_intsts_END (9)
#define SOC_DDRC_DMC_DDRC_INTSTS0_monram_merr_intsts_START (10)
#define SOC_DDRC_DMC_DDRC_INTSTS0_monram_merr_intsts_END (10)
#define SOC_DDRC_DMC_DDRC_INTSTS0_tmon_err_intsts_START (12)
#define SOC_DDRC_DMC_DDRC_INTSTS0_tmon_err_intsts_END (19)
#define SOC_DDRC_DMC_DDRC_INTSTS0_merr_intsts_START (20)
#define SOC_DDRC_DMC_DDRC_INTSTS0_merr_intsts_END (20)
#define SOC_DDRC_DMC_DDRC_INTSTS0_sref_err_intsts_START (21)
#define SOC_DDRC_DMC_DDRC_INTSTS0_sref_err_intsts_END (21)
#define SOC_DDRC_DMC_DDRC_INTSTS0_dimm_parity_intsts_START (22)
#define SOC_DDRC_DMC_DDRC_INTSTS0_dimm_parity_intsts_END (22)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_alert_intsts_START (23)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rec_alert_intsts_END (23)
#define SOC_DDRC_DMC_DDRC_INTSTS0_crc_rderr_intsts_START (24)
#define SOC_DDRC_DMC_DDRC_INTSTS0_crc_rderr_intsts_END (24)
#define SOC_DDRC_DMC_DDRC_INTSTS0_wsram_merr_intsts_START (25)
#define SOC_DDRC_DMC_DDRC_INTSTS0_wsram_merr_intsts_END (25)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_o_ovth_intsts_START (26)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_o_ovth_intsts_END (26)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_i_ovth_intsts_START (27)
#define SOC_DDRC_DMC_DDRC_INTSTS0_osc_i_ovth_intsts_END (27)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rcmdre_intsts_START (28)
#define SOC_DDRC_DMC_DDRC_INTSTS0_rcmdre_intsts_END (28)
#define SOC_DDRC_DMC_DDRC_INTSTS0_phyram_intsts_START (29)
#define SOC_DDRC_DMC_DDRC_INTSTS0_phyram_intsts_END (29)
#define SOC_DDRC_DMC_DDRC_INTSTS0_dis_rnk_intsts_START (30)
#define SOC_DDRC_DMC_DDRC_INTSTS0_dis_rnk_intsts_END (30)
#define SOC_DDRC_DMC_DDRC_INTSTS0_lecc_merr_intsts_START (31)
#define SOC_DDRC_DMC_DDRC_INTSTS0_lecc_merr_intsts_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_upd_intsts : 8;
        unsigned int osc_o_rd_intsts : 1;
        unsigned int osc_i_rd_intsts : 1;
        unsigned int flux_intsts : 1;
        unsigned int stacmd_min_intsts : 1;
        unsigned int stacmd_max_intsts : 1;
        unsigned int stadat_min_intsts : 1;
        unsigned int stadat_max_intsts : 1;
        unsigned int reserved_0 : 1;
        unsigned int serr_intsts : 1;
        unsigned int wsram_serr_intsts : 1;
        unsigned int sbram_serr_intsts : 1;
        unsigned int rpram_serr_intsts : 1;
        unsigned int recram_serr_intsts : 1;
        unsigned int monram_serr_intsts : 1;
        unsigned int raammt_intsts : 1;
        unsigned int raaimt_intsts : 1;
        unsigned int lecc_serr_intsts : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_DDRC_DMC_DDRC_INTSTS1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTSTS1_tmon_upd_intsts_START (0)
#define SOC_DDRC_DMC_DDRC_INTSTS1_tmon_upd_intsts_END (7)
#define SOC_DDRC_DMC_DDRC_INTSTS1_osc_o_rd_intsts_START (8)
#define SOC_DDRC_DMC_DDRC_INTSTS1_osc_o_rd_intsts_END (8)
#define SOC_DDRC_DMC_DDRC_INTSTS1_osc_i_rd_intsts_START (9)
#define SOC_DDRC_DMC_DDRC_INTSTS1_osc_i_rd_intsts_END (9)
#define SOC_DDRC_DMC_DDRC_INTSTS1_flux_intsts_START (10)
#define SOC_DDRC_DMC_DDRC_INTSTS1_flux_intsts_END (10)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stacmd_min_intsts_START (11)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stacmd_min_intsts_END (11)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stacmd_max_intsts_START (12)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stacmd_max_intsts_END (12)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stadat_min_intsts_START (13)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stadat_min_intsts_END (13)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stadat_max_intsts_START (14)
#define SOC_DDRC_DMC_DDRC_INTSTS1_stadat_max_intsts_END (14)
#define SOC_DDRC_DMC_DDRC_INTSTS1_serr_intsts_START (16)
#define SOC_DDRC_DMC_DDRC_INTSTS1_serr_intsts_END (16)
#define SOC_DDRC_DMC_DDRC_INTSTS1_wsram_serr_intsts_START (17)
#define SOC_DDRC_DMC_DDRC_INTSTS1_wsram_serr_intsts_END (17)
#define SOC_DDRC_DMC_DDRC_INTSTS1_sbram_serr_intsts_START (18)
#define SOC_DDRC_DMC_DDRC_INTSTS1_sbram_serr_intsts_END (18)
#define SOC_DDRC_DMC_DDRC_INTSTS1_rpram_serr_intsts_START (19)
#define SOC_DDRC_DMC_DDRC_INTSTS1_rpram_serr_intsts_END (19)
#define SOC_DDRC_DMC_DDRC_INTSTS1_recram_serr_intsts_START (20)
#define SOC_DDRC_DMC_DDRC_INTSTS1_recram_serr_intsts_END (20)
#define SOC_DDRC_DMC_DDRC_INTSTS1_monram_serr_intsts_START (21)
#define SOC_DDRC_DMC_DDRC_INTSTS1_monram_serr_intsts_END (21)
#define SOC_DDRC_DMC_DDRC_INTSTS1_raammt_intsts_START (22)
#define SOC_DDRC_DMC_DDRC_INTSTS1_raammt_intsts_END (22)
#define SOC_DDRC_DMC_DDRC_INTSTS1_raaimt_intsts_START (23)
#define SOC_DDRC_DMC_DDRC_INTSTS1_raaimt_intsts_END (23)
#define SOC_DDRC_DMC_DDRC_INTSTS1_lecc_serr_intsts_START (24)
#define SOC_DDRC_DMC_DDRC_INTSTS1_lecc_serr_intsts_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stamid_min_int_mask0 : 1;
        unsigned int stamid_max_int_mask0 : 1;
        unsigned int stamid_min_int_mask1 : 1;
        unsigned int stamid_max_int_mask1 : 1;
        unsigned int stamid_min_int_mask2 : 1;
        unsigned int stamid_max_int_mask2 : 1;
        unsigned int stamid_min_int_mask3 : 1;
        unsigned int stamid_max_int_mask3 : 1;
        unsigned int stamid_min_int_mask4 : 1;
        unsigned int stamid_max_int_mask4 : 1;
        unsigned int stamid_min_int_mask5 : 1;
        unsigned int stamid_max_int_mask5 : 1;
        unsigned int stamid_min_int_mask6 : 1;
        unsigned int stamid_max_int_mask6 : 1;
        unsigned int stamid_min_int_mask7 : 1;
        unsigned int stamid_max_int_mask7 : 1;
        unsigned int stamid_min_int_mask8 : 1;
        unsigned int stamid_max_int_mask8 : 1;
        unsigned int stamid_min_int_mask9 : 1;
        unsigned int stamid_max_int_mask9 : 1;
        unsigned int stamid_min_int_mask10 : 1;
        unsigned int stamid_max_int_mask10 : 1;
        unsigned int stamid_min_int_mask11 : 1;
        unsigned int stamid_max_int_mask11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_INTMSK2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask0_START (0)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask0_END (0)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask0_START (1)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask0_END (1)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask1_START (2)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask1_END (2)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask1_START (3)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask1_END (3)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask2_START (4)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask2_END (4)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask2_START (5)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask2_END (5)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask3_START (6)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask3_END (6)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask3_START (7)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask3_END (7)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask4_START (8)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask4_END (8)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask4_START (9)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask4_END (9)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask5_START (10)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask5_END (10)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask5_START (11)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask5_END (11)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask6_START (12)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask6_END (12)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask6_START (13)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask6_END (13)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask7_START (14)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask7_END (14)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask7_START (15)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask7_END (15)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask8_START (16)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask8_END (16)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask8_START (17)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask8_END (17)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask9_START (18)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask9_END (18)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask9_START (19)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask9_END (19)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask10_START (20)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask10_END (20)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask10_START (21)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask10_END (21)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask11_START (22)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_min_int_mask11_END (22)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask11_START (23)
#define SOC_DDRC_DMC_DDRC_INTMSK2_stamid_max_int_mask11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stamid_min_rint0 : 1;
        unsigned int stamid_max_rint0 : 1;
        unsigned int stamid_min_rint1 : 1;
        unsigned int stamid_max_rint1 : 1;
        unsigned int stamid_min_rint2 : 1;
        unsigned int stamid_max_rint2 : 1;
        unsigned int stamid_min_rint3 : 1;
        unsigned int stamid_max_rint3 : 1;
        unsigned int stamid_min_rint4 : 1;
        unsigned int stamid_max_rint4 : 1;
        unsigned int stamid_min_rint5 : 1;
        unsigned int stamid_max_rint5 : 1;
        unsigned int stamid_min_rint6 : 1;
        unsigned int stamid_max_rint6 : 1;
        unsigned int stamid_min_rint7 : 1;
        unsigned int stamid_max_rint7 : 1;
        unsigned int stamid_min_rint8 : 1;
        unsigned int stamid_max_rint8 : 1;
        unsigned int stamid_min_rint9 : 1;
        unsigned int stamid_max_rint9 : 1;
        unsigned int stamid_min_rint10 : 1;
        unsigned int stamid_max_rint10 : 1;
        unsigned int stamid_min_rint11 : 1;
        unsigned int stamid_max_rint11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_RINT2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint0_START (0)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint0_END (0)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint0_START (1)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint0_END (1)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint1_START (2)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint1_END (2)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint1_START (3)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint1_END (3)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint2_START (4)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint2_END (4)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint2_START (5)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint2_END (5)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint3_START (6)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint3_END (6)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint3_START (7)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint3_END (7)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint4_START (8)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint4_END (8)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint4_START (9)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint4_END (9)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint5_START (10)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint5_END (10)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint5_START (11)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint5_END (11)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint6_START (12)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint6_END (12)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint6_START (13)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint6_END (13)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint7_START (14)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint7_END (14)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint7_START (15)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint7_END (15)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint8_START (16)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint8_END (16)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint8_START (17)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint8_END (17)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint9_START (18)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint9_END (18)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint9_START (19)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint9_END (19)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint10_START (20)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint10_END (20)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint10_START (21)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint10_END (21)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint11_START (22)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_min_rint11_END (22)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint11_START (23)
#define SOC_DDRC_DMC_DDRC_RINT2_stamid_max_rint11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stamid_min_intsts0 : 1;
        unsigned int stamid_max_intsts0 : 1;
        unsigned int stamid_min_intsts1 : 1;
        unsigned int stamid_max_intsts1 : 1;
        unsigned int stamid_min_intsts2 : 1;
        unsigned int stamid_max_intsts2 : 1;
        unsigned int stamid_min_intsts3 : 1;
        unsigned int stamid_max_intsts3 : 1;
        unsigned int stamid_min_intsts4 : 1;
        unsigned int stamid_max_intsts4 : 1;
        unsigned int stamid_min_intsts5 : 1;
        unsigned int stamid_max_intsts5 : 1;
        unsigned int stamid_min_intsts6 : 1;
        unsigned int stamid_max_intsts6 : 1;
        unsigned int stamid_min_intsts7 : 1;
        unsigned int stamid_max_intsts7 : 1;
        unsigned int stamid_min_intsts8 : 1;
        unsigned int stamid_max_intsts8 : 1;
        unsigned int stamid_min_intsts9 : 1;
        unsigned int stamid_max_intsts9 : 1;
        unsigned int stamid_min_intsts10 : 1;
        unsigned int stamid_max_intsts10 : 1;
        unsigned int stamid_min_intsts11 : 1;
        unsigned int stamid_max_intsts11 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_INTSTS2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts0_START (0)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts0_END (0)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts0_START (1)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts0_END (1)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts1_START (2)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts1_END (2)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts1_START (3)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts1_END (3)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts2_START (4)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts2_END (4)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts2_START (5)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts2_END (5)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts3_START (6)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts3_END (6)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts3_START (7)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts3_END (7)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts4_START (8)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts4_END (8)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts4_START (9)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts4_END (9)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts5_START (10)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts5_END (10)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts5_START (11)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts5_END (11)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts6_START (12)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts6_END (12)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts6_START (13)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts6_END (13)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts7_START (14)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts7_END (14)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts7_START (15)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts7_END (15)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts8_START (16)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts8_END (16)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts8_START (17)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts8_END (17)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts9_START (18)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts9_END (18)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts9_START (19)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts9_END (19)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts10_START (20)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts10_END (20)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts10_START (21)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts10_END (21)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts11_START (22)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_min_intsts11_END (22)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts11_START (23)
#define SOC_DDRC_DMC_DDRC_INTSTS2_stamid_max_intsts11_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_SFC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_SFC_cmd_req_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_SFC_cmd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_que_rptr : 8;
        unsigned int infinite_loop : 1;
        unsigned int sfc_que_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int cmd_mrs : 4;
        unsigned int sfc_all_rnk_bp : 1;
        unsigned int sfc_soft_pat : 1;
        unsigned int sfc_col_incr : 1;
        unsigned int sfc_state_idle : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_que_rptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_que_rptr_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_infinite_loop_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_infinite_loop_END (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_que_clr_START (9)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_que_clr_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_cmd_mrs_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_cmd_mrs_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_all_rnk_bp_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_all_rnk_bp_END (16)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_soft_pat_START (17)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_soft_pat_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_col_incr_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_col_incr_END (18)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_state_idle_START (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_sfc_state_idle_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wait_tlast : 8;
        unsigned int wait_reserv : 8;
        unsigned int wait_reserv1 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_tlast_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_tlast_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_reserv_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_reserv_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_reserv1_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_TIM_wait_reserv1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmd_que0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR0_sfc_cmd_que0_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR0_sfc_cmd_que0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmd_que1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR1_sfc_cmd_que1_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR1_sfc_cmd_que1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_col : 11;
        unsigned int reserved_0 : 3;
        unsigned int sfc_ban_addr_a : 5;
        unsigned int sfc_ban_addr_b : 5;
        unsigned int sfc_lr : 3;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_col_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_col_END (10)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_ban_addr_a_START (14)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_ban_addr_a_END (18)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_ban_addr_b_START (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_ban_addr_b_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_lr_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR2_sfc_lr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_row : 18;
        unsigned int sfc_rank : 8;
        unsigned int reserved : 6;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_sfc_row_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_sfc_row_END (17)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_sfc_rank_START (18)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_ADDR3_sfc_rank_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdata : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_WDATA_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WDATA_wdata_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WDATA_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_wdata_ptr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_WCTRL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WCTRL_sfc_wdata_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WCTRL_sfc_wdata_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_mask0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_MASK0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK0_sfc_mask0_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK0_sfc_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_mask1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_MASK1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK1_sfc_mask1_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MASK1_sfc_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmpc_cs : 4;
        unsigned int tmpc_hold : 4;
        unsigned int tmpc_setup : 4;
        unsigned int mpc_mode : 1;
        unsigned int tmpc_delay : 7;
        unsigned int cs_toggle_en : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_cs_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_cs_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_hold_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_hold_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_setup_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_setup_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_mpc_mode_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_mpc_mode_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_delay_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_tmpc_delay_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_cs_toggle_en_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_MPC_cs_toggle_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcatm_entry : 7;
        unsigned int tcatm_exit : 6;
        unsigned int tcatm_valid : 7;
        unsigned int tcatm_cs_exit : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_entry_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_entry_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_exit_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_exit_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_valid_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_valid_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_cs_exit_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CATIME_tcatm_cs_exit_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcstm_entry : 7;
        unsigned int tcstm_exit : 6;
        unsigned int tcstm_valid : 7;
        unsigned int multi_nop_mode : 1;
        unsigned int cstm_nop_mode : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_entry_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_entry_END (6)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_exit_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_exit_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_valid_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_tcstm_valid_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_multi_nop_mode_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_multi_nop_mode_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_cstm_nop_mode_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CSTIME_cstm_nop_mode_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_rdata_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_rdata_ptr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_RCTRL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_RCTRL_sfc_rdata_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_RCTRL_sfc_rdata_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata0_dbi : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA0_DBI_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA0_DBI_rdata0_dbi_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA0_DBI_rdata0_dbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata1_dbi : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA1_DBI_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA1_DBI_rdata1_dbi_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA1_DBI_rdata1_dbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdata_ecc_dbi : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_rdata_ecc_dbi_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_RDATA_ECC_DBI_rdata_ecc_dbi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmd_out0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_CMD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD0_sfc_cmd_out0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD0_sfc_cmd_out0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmd_out1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_CMD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD1_sfc_cmd_out1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_CMD1_sfc_cmd_out1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_ext_cmd : 1;
        unsigned int reserved_0 : 1;
        unsigned int sfc_err_stop : 1;
        unsigned int sfc_que_ptr_back : 1;
        unsigned int reserved_1 : 3;
        unsigned int sfc_ber_infinite : 1;
        unsigned int reserved_2 : 18;
        unsigned int last_flag : 6;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_ext_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_ext_cmd_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_err_stop_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_err_stop_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_que_ptr_back_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_que_ptr_back_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_ber_infinite_START (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_sfc_ber_infinite_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_last_flag_START (26)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_EXTCMD_CTRL_last_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_lp_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_LOOP_CTRL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_LOOP_CTRL_sfc_lp_num_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_LOOP_CTRL_sfc_lp_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_ber_rd_rpt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_BER_RD_RPT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_BER_RD_RPT_sfc_ber_rd_rpt_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_BER_RD_RPT_sfc_ber_rd_rpt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_head_cut : 10;
        unsigned int sfc_tail_cut : 10;
        unsigned int sfc_cut : 11;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_head_cut_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_head_cut_END (9)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_tail_cut_START (10)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_tail_cut_END (19)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_cut_START (20)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_HEAD_TAIL_CUT_sfc_cut_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_res_env_prd : 6;
        unsigned int reserved_0 : 2;
        unsigned int sfc_clk_pat_prd : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_sfc_res_env_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_sfc_res_env_prd_END (5)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_sfc_clk_pat_prd_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_PRD_sfc_clk_pat_prd_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wl_strb_pw : 8;
        unsigned int wl2_dqs_ext : 4;
        unsigned int wl_wr_en : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl_strb_pw_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl_strb_pw_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl2_dqs_ext_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl2_dqs_ext_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl_wr_en_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_WL_CTRL_wl_wr_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_pat_sel_data : 30;
        unsigned int sfc_env_init_val : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_sfc_pat_sel_data_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_sfc_pat_sel_data_END (29)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_sfc_env_init_val_START (30)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_sfc_env_init_val_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_pat_sel_ptr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_PTR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_PTR_sfc_pat_sel_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_PAT_SEL_PTR_sfc_pat_sel_ptr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmp_mask_data : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_sfc_cmp_mask_data_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_sfc_cmp_mask_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_cmp_mask_ptr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_PTR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_PTR_sfc_cmp_mask_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_CMP_MASK_PTR_sfc_cmp_mask_ptr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED_sfc_init_seed_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED_sfc_init_seed_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed1 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED1_sfc_init_seed1_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED1_sfc_init_seed1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed2 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED2_sfc_init_seed2_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED2_sfc_init_seed2_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED3_sfc_init_seed3_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED3_sfc_init_seed3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed4 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED4_sfc_init_seed4_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED4_sfc_init_seed4_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed5 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED5_sfc_init_seed5_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED5_sfc_init_seed5_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed6 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED6_sfc_init_seed6_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED6_sfc_init_seed6_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_init_seed7 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED7_sfc_init_seed7_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_SFC_INIT_SEED7_sfc_init_seed7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_pos_err_0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_0_sfc_dqs_pos_err_0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_0_sfc_dqs_pos_err_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_pos_err_1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_1_sfc_dqs_pos_err_1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_1_sfc_dqs_pos_err_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_pos_err_2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_2_sfc_dqs_pos_err_2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_POS_ERR_2_sfc_dqs_pos_err_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_neg_err_0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_0_sfc_dqs_neg_err_0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_0_sfc_dqs_neg_err_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_neg_err_1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_1_sfc_dqs_neg_err_1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_1_sfc_dqs_neg_err_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_dqs_neg_err_2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_2_sfc_dqs_neg_err_2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_DQS_NEG_ERR_2_sfc_dqs_neg_err_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_per_nib_err : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_PER_NIB_ERR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_NIB_ERR_sfc_per_nib_err_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_NIB_ERR_sfc_per_nib_err_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_per_byte_err : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_PER_BYTE_ERR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_BYTE_ERR_sfc_per_byte_err_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_PER_BYTE_ERR_sfc_per_byte_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_any_err : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_ANY_ERR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ANY_ERR_sfc_any_err_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ANY_ERR_sfc_any_err_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_que_cur_ptr : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_cur_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_QUE_CUR_PTR_sfc_que_cur_ptr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_err_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SFC_ERR_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ERR_NUM_sfc_err_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SFC_ERR_NUM_sfc_err_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_isi_data : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PAT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PAT_ac_isi_data_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PAT_ac_isi_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_isi_ptr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PTR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PTR_ac_isi_ptr_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_AC_ISI_PTR_ac_isi_ptr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_mon_rd_bg : 4;
        unsigned int sfc_mon_rd_rank : 8;
        unsigned int sfc_mon_rd : 1;
        unsigned int mon_row : 8;
        unsigned int mon_en : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_bg_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_bg_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_rank_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_rank_END (11)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_START (12)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_sfc_mon_rd_END (12)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_mon_row_START (13)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_mon_row_END (20)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_mon_en_START (21)
#define SOC_DDRC_DMC_DDRC_CFG_MON_WDATA_mon_en_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_train_en : 1;
        unsigned int device_ca_train : 1;
        unsigned int rcd_ddr_ca_train : 1;
        unsigned int rcd_sdr_qca_train : 1;
        unsigned int sfc_ca_sel : 4;
        unsigned int ca_train_cs_pat : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ca_train_en_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ca_train_en_END (0)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_device_ca_train_START (1)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_device_ca_train_END (1)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_rcd_ddr_ca_train_START (2)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_rcd_ddr_ca_train_END (2)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_rcd_sdr_qca_train_START (3)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_rcd_sdr_qca_train_END (3)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_sfc_ca_sel_START (4)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_sfc_ca_sel_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ca_train_cs_pat_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CA_TRAIN_ca_train_cs_pat_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rerr_addr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RERR_ADDR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ADDR_rerr_addr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ADDR_rerr_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rerr_haddr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RERR_HADDR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RERR_HADDR_rerr_haddr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_HADDR_rerr_haddr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rerr_id : 31;
        unsigned int rerr_type : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RERR_ID_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_rerr_id_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_rerr_id_END (30)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_rerr_type_START (31)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_ID_rerr_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rerr_clr : 1;
        unsigned int reserved : 15;
        unsigned int rerr_cnt : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_rerr_clr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_rerr_clr_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_rerr_cnt_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_RERR_CLR_rerr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_rf_rate : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_REF_RATE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_REF_RATE_tmon_rf_rate_START (0)
#define SOC_DDRC_DMC_DDRC_REF_RATE_tmon_rf_rate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_err_rank0 : 8;
        unsigned int tmon_err_rank1 : 8;
        unsigned int tmon_err_rank2 : 8;
        unsigned int tmon_err_rank3 : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank0_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank1_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank1_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank2_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank2_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank3_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_tmon_err_rank3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_err_rank0_bf : 8;
        unsigned int tmon_err_rank1_bf : 8;
        unsigned int tmon_err_rank2_bf : 8;
        unsigned int tmon_err_rank3_bf : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank0_bf_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank0_bf_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank1_bf_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank1_bf_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank2_bf_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank2_bf_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank3_bf_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_BF_tmon_err_rank3_bf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_err_x8h_rank0 : 8;
        unsigned int tmon_err_x8h_rank1 : 8;
        unsigned int tmon_err_x8h_rank2 : 8;
        unsigned int tmon_err_x8h_rank3 : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank0_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank1_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank1_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank2_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank2_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank3_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_XH8_tmon_err_x8h_rank3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_err_x8h_rank0_bf : 8;
        unsigned int tmon_err_x8h_rank1_bf : 8;
        unsigned int tmon_err_x8h_rank2_bf : 8;
        unsigned int tmon_err_x8h_rank3_bf : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank0_bf_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank0_bf_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank1_bf_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank1_bf_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank2_bf_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank2_bf_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank3_bf_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_TMON_ERR_X8H_BF_tmon_err_x8h_rank3_bf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dat_stat_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_STADAT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_dat_stat_en_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_dat_stat_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dat_stat_prd : 28;
        unsigned int dat_stat_mode : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_STADAT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_dat_stat_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_dat_stat_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_dat_stat_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_STADAT_dat_stat_mode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_dat_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DATMIN_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DATMIN_dmc_dat_min_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DATMIN_dmc_dat_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_dat_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DATMAX_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DATMAX_dmc_dat_max_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DATMAX_dmc_dat_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_dat_minth : 8;
        unsigned int dmc_dat_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DATTH_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_dmc_dat_minth_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_dmc_dat_minth_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_dmc_dat_maxth_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_DATTH_dmc_dat_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_dat_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_DAT_SCMAX_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_DAT_SCMAX_dmc_dat_scmax_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_DAT_SCMAX_dmc_dat_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int load_stat_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_STACMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_load_stat_en_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_load_stat_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int load_stat_prd : 28;
        unsigned int load_stat_mode : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_STACMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_load_stat_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_load_stat_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_load_stat_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_STACMD_load_stat_mode_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_min : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CMDMIN_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CMDMIN_dmc_cmd_min_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMDMIN_dmc_cmd_min_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_max : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CMDMAX_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CMDMAX_dmc_cmd_max_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMDMAX_dmc_cmd_max_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_minth : 8;
        unsigned int dmc_cmd_maxth : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CMDTH_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_dmc_cmd_minth_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_dmc_cmd_minth_END (7)
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_dmc_cmd_maxth_START (8)
#define SOC_DDRC_DMC_DDRC_CFG_CMDTH_dmc_cmd_maxth_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_scmax : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_CMD_SCMAX_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_CMD_SCMAX_dmc_cmd_scmax_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_CMD_SCMAX_dmc_cmd_scmax_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int perf_en : 1;
        unsigned int prd_sel : 1;
        unsigned int wup_val : 4;
        unsigned int clr_prd_val : 4;
        unsigned int reserved : 22;
    } reg;
} SOC_DDRC_DMC_DDRC_CTRL_PERF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_perf_en_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_perf_en_END (0)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_prd_sel_START (1)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_prd_sel_END (1)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_wup_val_START (2)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_wup_val_END (5)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_clr_prd_val_START (6)
#define SOC_DDRC_DMC_DDRC_CTRL_PERF_clr_prd_val_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int perf_prd : 28;
        unsigned int perf_mode : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_PERF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_PERF_perf_prd_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_PERF_perf_prd_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_PERF_perf_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_PERF_perf_mode_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_id : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_STAID_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_STAID_sta_id_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_STAID_sta_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_idmask : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_sta_idmask_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_sta_idmask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_wr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUX_WR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WR_flux_wr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WR_flux_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_rd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUX_RD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RD_flux_rd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RD_flux_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_wr_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUX_WCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WCMD_flux_wr_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_WCMD_flux_wr_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_rd_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUX_RCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RCMD_flux_rd_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUX_RCMD_flux_rd_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fluxid_wr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUXID_WR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WR_fluxid_wr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WR_fluxid_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fluxid_rd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUXID_RD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RD_fluxid_rd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RD_fluxid_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fluxid_wr_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUXID_WCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WCMD_fluxid_wr_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_WCMD_fluxid_wr_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fluxid_rd_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FLUXID_RCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RCMD_fluxid_rd_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FLUXID_RCMD_fluxid_rd_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlatcnt_min : 16;
        unsigned int wlatcnt_max : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_wlatcnt_min_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_wlatcnt_min_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_wlatcnt_max_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT0_wlatcnt_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlatcnt_all : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WLATCNT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT1_wlatcnt_all_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WLATCNT1_wlatcnt_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rlatcnt_min : 16;
        unsigned int rlatcnt_max : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_rlatcnt_min_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_rlatcnt_min_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_rlatcnt_max_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT0_rlatcnt_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rlatcnt_all : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RLATCNT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT1_rlatcnt_all_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RLATCNT1_rlatcnt_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inhere_rlatcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_INHERE_RLAT_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_INHERE_RLAT_CNT_inhere_rlatcnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_INHERE_RLAT_CNT_inhere_rlatcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_sum : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CMD_SUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CMD_SUM_dmc_cmd_sum_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CMD_SUM_dmc_cmd_sum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_dat_sum : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DAT_SUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DAT_SUM_dmc_dat_sum_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DAT_SUM_dmc_dat_sum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_pre_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PRE_CMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PRE_CMD_dmc_pre_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PRE_CMD_dmc_pre_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_act_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ACT_CMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ACT_CMD_dmc_act_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ACT_CMD_dmc_act_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_bnk_chg : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_BNK_CHG_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_BNK_CHG_dmc_bnk_chg_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_BNK_CHG_dmc_bnk_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_rnk_chg : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RNK_CHG_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RNK_CHG_dmc_rnk_chg_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RNK_CHG_dmc_rnk_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_rw_chg : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RW_CHG_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RW_CHG_dmc_rw_chg_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RW_CHG_dmc_rw_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_rcmd_bl32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_BL32_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_BL32_ddr_rcmd_bl32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_BL32_ddr_rcmd_bl32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_wcmd_bl32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_BL32_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_BL32_ddr_wcmd_bl32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_BL32_ddr_wcmd_bl32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_rcmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_ddr_rcmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DDR_RCMD_ddr_rcmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_wcmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_ddr_wcmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DDR_WCMD_ddr_wcmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_cmd : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_REF_CMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_REF_CMD_ref_cmd_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_REF_CMD_ref_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nls_win_lvl : 16;
        unsigned int nls_cmd_lvl : 8;
        unsigned int nls_pri_lvl : 4;
        unsigned int nls_win_mode : 1;
        unsigned int nls_cnt_clr : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_win_lvl_START (0)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_win_lvl_END (15)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_cmd_lvl_START (16)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_cmd_lvl_END (23)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_pri_lvl_START (24)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_pri_lvl_END (27)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_win_mode_START (28)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_win_mode_END (28)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_cnt_clr_START (29)
#define SOC_DDRC_DMC_DDRC_CFG_NLS_CFG_nls_cnt_clr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nls_win_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_NLS_WIN_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_NLS_WIN_CNT_nls_win_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_NLS_WIN_CNT_nls_win_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nls_pat_cnt : 12;
        unsigned int nls_cmd_cnt : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_nls_pat_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_nls_pat_cnt_END (11)
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_nls_cmd_cnt_START (12)
#define SOC_DDRC_DMC_DDRC_HIS_NLS_CMD_CNT_nls_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int autosync_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_AS_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_AS_CNT_autosync_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_AS_CNT_autosync_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cb3_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_B3_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_B3_CNT_cb3_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_B3_CNT_cb3_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bcast_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_BCAST_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_BCAST_CNT_bcast_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_BCAST_CNT_bcast_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int writex_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WX_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WX_CNT_writex_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WX_CNT_writex_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_rdcmd0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD0_dif_bg_rank0_rdcmd0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD0_dif_bg_rank0_rdcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_rdcmd1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD1_dif_bg_rank0_rdcmd1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD1_dif_bg_rank0_rdcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_rdcmd2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD2_dif_bg_rank0_rdcmd2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD2_dif_bg_rank0_rdcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_rdcmd3 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD3_dif_bg_rank0_rdcmd3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD3_dif_bg_rank0_rdcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_rdcmd0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD4_dif_bg_rank1_rdcmd0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD4_dif_bg_rank1_rdcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_rdcmd1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD5_dif_bg_rank1_rdcmd1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD5_dif_bg_rank1_rdcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_rdcmd2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD6_dif_bg_rank1_rdcmd2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD6_dif_bg_rank1_rdcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_rdcmd3 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD7_dif_bg_rank1_rdcmd3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_RDCMD7_dif_bg_rank1_rdcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_wrcmd0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD0_dif_bg_rank0_wrcmd0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD0_dif_bg_rank0_wrcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_wrcmd1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD1_dif_bg_rank0_wrcmd1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD1_dif_bg_rank0_wrcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_wrcmd2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD2_dif_bg_rank0_wrcmd2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD2_dif_bg_rank0_wrcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank0_wrcmd3 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD3_dif_bg_rank0_wrcmd3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD3_dif_bg_rank0_wrcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_wrcmd0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD4_dif_bg_rank1_wrcmd0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD4_dif_bg_rank1_wrcmd0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_wrcmd1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD5_dif_bg_rank1_wrcmd1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD5_dif_bg_rank1_wrcmd1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_wrcmd2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD6_dif_bg_rank1_wrcmd2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD6_dif_bg_rank1_wrcmd2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dif_bg_rank1_wrcmd3 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD7_dif_bg_rank1_wrcmd3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DIF_BG_WRCMD7_dif_bg_rank1_wrcmd3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min0 : 7;
        unsigned int mid_max0 : 7;
        unsigned int mid_min1 : 7;
        unsigned int mid_max1 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_min0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_min0_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_max0_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_max0_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_min1_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_min1_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_max1_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN0_mid_max1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min2 : 7;
        unsigned int mid_max2 : 7;
        unsigned int mid_min3 : 7;
        unsigned int mid_max3 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_min2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_min2_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_max2_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_max2_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_min3_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_min3_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_max3_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN1_mid_max3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min4 : 7;
        unsigned int mid_max4 : 7;
        unsigned int mid_min5 : 7;
        unsigned int mid_max5 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_min4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_min4_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_max4_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_max4_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_min5_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_min5_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_max5_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN2_mid_max5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min6 : 7;
        unsigned int mid_max6 : 7;
        unsigned int mid_min7 : 7;
        unsigned int mid_max7 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_min6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_min6_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_max6_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_max6_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_min7_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_min7_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_max7_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN3_mid_max7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min8 : 7;
        unsigned int mid_max8 : 7;
        unsigned int mid_min9 : 7;
        unsigned int mid_max9 : 7;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_min8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_min8_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_max8_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_max8_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_min9_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_min9_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_max9_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN4_mid_max9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_min10 : 7;
        unsigned int mid_max10 : 7;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_mid_min10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_mid_min10_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_mid_max10_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_RAN5_mid_max10_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_sta_en0 : 1;
        unsigned int mid_sta_en1 : 1;
        unsigned int mid_sta_en2 : 1;
        unsigned int mid_sta_en3 : 1;
        unsigned int mid_sta_en4 : 1;
        unsigned int mid_sta_en5 : 1;
        unsigned int mid_sta_en6 : 1;
        unsigned int mid_sta_en7 : 1;
        unsigned int mid_sta_en8 : 1;
        unsigned int mid_sta_en9 : 1;
        unsigned int mid_sta_en10 : 1;
        unsigned int mid_sta_en11 : 1;
        unsigned int reserved_0 : 4;
        unsigned int mid_sta_clr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en0_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en1_START (1)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en1_END (1)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en2_START (2)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en2_END (2)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en3_START (3)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en3_END (3)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en4_START (4)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en4_END (4)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en5_START (5)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en5_END (5)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en6_START (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en6_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en7_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en7_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en8_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en8_END (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en9_START (9)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en9_END (9)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en10_START (10)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en10_END (10)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en11_START (11)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_en11_END (11)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_clr_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_MID_EN_CLR_mid_sta_clr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd0 : 28;
        unsigned int mid_fluxstat_mode0 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_mid_fluxstat_prd0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_mid_fluxstat_prd0_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_mid_fluxstat_mode0_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD0_mid_fluxstat_mode0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min0 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN0_mid_fluxstat_min0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN0_mid_fluxstat_min0_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max0 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX0_mid_fluxstat_max0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX0_mid_fluxstat_max0_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth0 : 8;
        unsigned int mid_flux_maxth0 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_mid_flux_minth0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_mid_flux_minth0_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_mid_flux_maxth0_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH0_mid_flux_maxth0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax0 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX0_mid_flux_scmax0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX0_mid_flux_scmax0_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd1 : 28;
        unsigned int mid_fluxstat_mode1 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_mid_fluxstat_prd1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_mid_fluxstat_prd1_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_mid_fluxstat_mode1_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD1_mid_fluxstat_mode1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min1 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN1_mid_fluxstat_min1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN1_mid_fluxstat_min1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max1 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX1_mid_fluxstat_max1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX1_mid_fluxstat_max1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth1 : 8;
        unsigned int mid_flux_maxth1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_mid_flux_minth1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_mid_flux_minth1_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_mid_flux_maxth1_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH1_mid_flux_maxth1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax1 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX1_mid_flux_scmax1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX1_mid_flux_scmax1_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd2 : 28;
        unsigned int mid_fluxstat_mode2 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_mid_fluxstat_prd2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_mid_fluxstat_prd2_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_mid_fluxstat_mode2_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD2_mid_fluxstat_mode2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min2 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN2_mid_fluxstat_min2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN2_mid_fluxstat_min2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max2 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX2_mid_fluxstat_max2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX2_mid_fluxstat_max2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth2 : 8;
        unsigned int mid_flux_maxth2 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_mid_flux_minth2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_mid_flux_minth2_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_mid_flux_maxth2_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH2_mid_flux_maxth2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax2 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX2_mid_flux_scmax2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX2_mid_flux_scmax2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd3 : 28;
        unsigned int mid_fluxstat_mode3 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_mid_fluxstat_prd3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_mid_fluxstat_prd3_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_mid_fluxstat_mode3_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD3_mid_fluxstat_mode3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min3 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN3_mid_fluxstat_min3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN3_mid_fluxstat_min3_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max3 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX3_mid_fluxstat_max3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX3_mid_fluxstat_max3_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth3 : 8;
        unsigned int mid_flux_maxth3 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_mid_flux_minth3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_mid_flux_minth3_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_mid_flux_maxth3_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH3_mid_flux_maxth3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax3 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX3_mid_flux_scmax3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX3_mid_flux_scmax3_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd4 : 28;
        unsigned int mid_fluxstat_mode4 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_mid_fluxstat_prd4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_mid_fluxstat_prd4_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_mid_fluxstat_mode4_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD4_mid_fluxstat_mode4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min4 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN4_mid_fluxstat_min4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN4_mid_fluxstat_min4_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max4 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX4_mid_fluxstat_max4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX4_mid_fluxstat_max4_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth4 : 8;
        unsigned int mid_flux_maxth4 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_mid_flux_minth4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_mid_flux_minth4_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_mid_flux_maxth4_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH4_mid_flux_maxth4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax4 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX4_mid_flux_scmax4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX4_mid_flux_scmax4_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd5 : 28;
        unsigned int mid_fluxstat_mode5 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_mid_fluxstat_prd5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_mid_fluxstat_prd5_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_mid_fluxstat_mode5_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD5_mid_fluxstat_mode5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min5 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN5_mid_fluxstat_min5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN5_mid_fluxstat_min5_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max5 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX5_mid_fluxstat_max5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX5_mid_fluxstat_max5_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth5 : 8;
        unsigned int mid_flux_maxth5 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_mid_flux_minth5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_mid_flux_minth5_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_mid_flux_maxth5_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH5_mid_flux_maxth5_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax5 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX5_mid_flux_scmax5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX5_mid_flux_scmax5_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd6 : 28;
        unsigned int mid_fluxstat_mode6 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_mid_fluxstat_prd6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_mid_fluxstat_prd6_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_mid_fluxstat_mode6_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD6_mid_fluxstat_mode6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min6 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN6_mid_fluxstat_min6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN6_mid_fluxstat_min6_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max6 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX6_mid_fluxstat_max6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX6_mid_fluxstat_max6_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth6 : 8;
        unsigned int mid_flux_maxth6 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_mid_flux_minth6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_mid_flux_minth6_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_mid_flux_maxth6_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH6_mid_flux_maxth6_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax6 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX6_mid_flux_scmax6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX6_mid_flux_scmax6_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd7 : 28;
        unsigned int mid_fluxstat_mode7 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_mid_fluxstat_prd7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_mid_fluxstat_prd7_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_mid_fluxstat_mode7_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD7_mid_fluxstat_mode7_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min7 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN7_mid_fluxstat_min7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN7_mid_fluxstat_min7_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max7 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX7_mid_fluxstat_max7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX7_mid_fluxstat_max7_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth7 : 8;
        unsigned int mid_flux_maxth7 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_mid_flux_minth7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_mid_flux_minth7_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_mid_flux_maxth7_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH7_mid_flux_maxth7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax7 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX7_mid_flux_scmax7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX7_mid_flux_scmax7_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd8 : 28;
        unsigned int mid_fluxstat_mode8 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_mid_fluxstat_prd8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_mid_fluxstat_prd8_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_mid_fluxstat_mode8_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD8_mid_fluxstat_mode8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min8 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN8_mid_fluxstat_min8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN8_mid_fluxstat_min8_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max8 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX8_mid_fluxstat_max8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX8_mid_fluxstat_max8_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth8 : 8;
        unsigned int mid_flux_maxth8 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_mid_flux_minth8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_mid_flux_minth8_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_mid_flux_maxth8_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH8_mid_flux_maxth8_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax8 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX8_mid_flux_scmax8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX8_mid_flux_scmax8_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd9 : 28;
        unsigned int mid_fluxstat_mode9 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_mid_fluxstat_prd9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_mid_fluxstat_prd9_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_mid_fluxstat_mode9_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD9_mid_fluxstat_mode9_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min9 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN9_mid_fluxstat_min9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN9_mid_fluxstat_min9_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max9 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX9_mid_fluxstat_max9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX9_mid_fluxstat_max9_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth9 : 8;
        unsigned int mid_flux_maxth9 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_mid_flux_minth9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_mid_flux_minth9_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_mid_flux_maxth9_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH9_mid_flux_maxth9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax9 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX9_mid_flux_scmax9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX9_mid_flux_scmax9_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd10 : 28;
        unsigned int mid_fluxstat_mode10 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_mid_fluxstat_prd10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_mid_fluxstat_prd10_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_mid_fluxstat_mode10_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD10_mid_fluxstat_mode10_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min10 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN10_mid_fluxstat_min10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN10_mid_fluxstat_min10_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max10 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX10_mid_fluxstat_max10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX10_mid_fluxstat_max10_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth10 : 8;
        unsigned int mid_flux_maxth10 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_mid_flux_minth10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_mid_flux_minth10_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_mid_flux_maxth10_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH10_mid_flux_maxth10_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax10 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX10_mid_flux_scmax10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX10_mid_flux_scmax10_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_prd11 : 28;
        unsigned int mid_fluxstat_mode11 : 2;
        unsigned int reserved : 2;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_mid_fluxstat_prd11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_mid_fluxstat_prd11_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_mid_fluxstat_mode11_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_MODE_PRD11_mid_fluxstat_mode11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_min11 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN11_mid_fluxstat_min11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MIN11_mid_fluxstat_min11_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_fluxstat_max11 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX11_mid_fluxstat_max11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_CNT_MAX11_mid_fluxstat_max11_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_minth11 : 8;
        unsigned int mid_flux_maxth11 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_mid_flux_minth11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_mid_flux_minth11_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_mid_flux_maxth11_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_TH11_mid_flux_maxth11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_scmax11 : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX11_mid_flux_scmax11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_FLUX_SCMAX11_mid_flux_scmax11_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt0 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES0_mid_flux_cnt0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES0_mid_flux_cnt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES1_mid_flux_cnt1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES1_mid_flux_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES2_mid_flux_cnt2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES2_mid_flux_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt3 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES3_mid_flux_cnt3_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES3_mid_flux_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt4 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES4_mid_flux_cnt4_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES4_mid_flux_cnt4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt5 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES5_mid_flux_cnt5_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES5_mid_flux_cnt5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt6 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES6_mid_flux_cnt6_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES6_mid_flux_cnt6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt7 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES7_mid_flux_cnt7_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES7_mid_flux_cnt7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt8 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES8_mid_flux_cnt8_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES8_mid_flux_cnt8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt9 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES9_mid_flux_cnt9_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES9_mid_flux_cnt9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt10 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES10_mid_flux_cnt10_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES10_mid_flux_cnt10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flux_cnt11 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES11_mid_flux_cnt11_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MID_STAT_RES11_mid_flux_cnt11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank0_asref_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_CNT_rank0_asref_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_CNT_rank0_asref_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank1_asref_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_CNT_rank1_asref_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_CNT_rank1_asref_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank0_asref_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_NUM_rank0_asref_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_ASREF_NUM_rank0_asref_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank1_asref_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_NUM_rank1_asref_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_ASREF_NUM_rank1_asref_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank0_pd_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK0_PD_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PD_NUM_rank0_pd_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PD_NUM_rank0_pd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank1_pd_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK1_PD_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PD_NUM_rank1_pd_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PD_NUM_rank1_pd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_LP_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_LP_NUM_lp_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_LP_NUM_lp_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int merge_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_MERGE_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_MERGE_NUM_merge_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_MERGE_NUM_merge_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int forward_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FORWARD_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FORWARD_NUM_forward_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FORWARD_NUM_forward_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TO_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TO_NUM_timeout_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TO_NUM_timeout_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_to_mid : 7;
        unsigned int sta_mid_msk : 7;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_TO_MID_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_sta_to_mid_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_sta_to_mid_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_sta_mid_msk_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_TO_MID_sta_mid_msk_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rhit_break_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RHIT_BREAK_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RHIT_BREAK_NUM_rhit_break_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RHIT_BREAK_NUM_rhit_break_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rhit_cmd_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ROWHIT_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ROWHIT_NUM_rhit_cmd_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ROWHIT_NUM_rhit_cmd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pbr_success_rank0_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PBR_RANK0_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK0_NUM_pbr_success_rank0_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK0_NUM_pbr_success_rank0_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pbr_success_rank1_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PBR_RANK1_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK1_NUM_pbr_success_rank1_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PBR_RANK1_NUM_pbr_success_rank1_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ap_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_AP_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_AP_NUM_ap_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_AP_NUM_ap_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfs_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_DFS_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_DFS_NUM_dfs_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_DFS_NUM_dfs_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WRAP_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_NUM_wrap_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_NUM_wrap_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_mid : 7;
        unsigned int wrap_mid_mask : 7;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_wrap_mid_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_wrap_mid_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_wrap_mid_mask_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_WRAP_MID_wrap_mid_mask_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk1x_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_clk1x_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_clk1x_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk1x_num_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_CLR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_CLR_clk1x_num_clear_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CLK1X_NUM_CLR_clk1x_num_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank0_preall_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK0_PREALL_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PREALL_NUM_rank0_preall_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK0_PREALL_NUM_rank0_preall_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank1_preall_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_RANK1_PREALL_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PREALL_NUM_rank1_preall_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_RANK1_PREALL_NUM_rank1_preall_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_err_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_NUM_sref_err_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_NUM_sref_err_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int id_nmatch_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ID_NM_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ID_NM_NUM_id_nmatch_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ID_NM_NUM_id_nmatch_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int byact_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_BYACT_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_BYACT_NUM_byact_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_BYACT_NUM_byact_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int byrd_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_BYRD_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_BYRD_NUM_byrd_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_BYRD_NUM_byrd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adconf_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ADCONF_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ADCONF_NUM_adconf_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ADCONF_NUM_adconf_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idconf_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_IDCONF_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_IDCONF_NUM_idconf_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_IDCONF_NUM_idconf_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grp_rhit_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_GRP_ROWHIT_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_GRP_ROWHIT_NUM_grp_rhit_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_GRP_ROWHIT_NUM_grp_rhit_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wcmd_allone_num : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WRITE_ALLONE_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WRITE_ALLONE_NUM_wcmd_allone_num_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WRITE_ALLONE_NUM_wcmd_allone_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int all_one_wpat : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WPAT_ALL_ONE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WPAT_ALL_ONE_all_one_wpat_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WPAT_ALL_ONE_all_one_wpat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_rnk0_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PD_RANK0_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK0_CNT_pd_rnk0_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK0_CNT_pd_rnk0_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_rnk1_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PD_RANK1_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK1_CNT_pd_rnk1_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PD_RANK1_CNT_pd_rnk1_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int act_pd_rnk0_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK0_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK0_CNT_act_pd_rnk0_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK0_CNT_act_pd_rnk0_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int act_pd_rnk1_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK1_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK1_CNT_act_pd_rnk1_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ACT_PD_RANK1_CNT_act_pd_rnk1_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int act_npd_rnk0_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK0_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK0_CNT_act_npd_rnk0_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK0_CNT_act_npd_rnk0_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int act_npd_rnk1_cnt : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK1_CNT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK1_CNT_act_npd_rnk1_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ACT_NPD_RANK1_CNT_act_npd_rnk1_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int busy_dmc : 1;
        unsigned int busy_rec : 1;
        unsigned int func_bp_suc : 8;
        unsigned int func_bp_suc_all : 1;
        unsigned int busy_rec_intr : 1;
        unsigned int reserved : 4;
        unsigned int busy_func : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_STATUS_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_dmc_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_dmc_END (0)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_rec_START (1)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_rec_END (1)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_func_bp_suc_START (2)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_func_bp_suc_END (9)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_func_bp_suc_all_START (10)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_func_bp_suc_all_END (10)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_rec_intr_START (11)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_rec_intr_END (11)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_func_START (16)
#define SOC_DDRC_DMC_DDRC_CURR_STATUS_busy_func_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_sref : 1;
        unsigned int in_srdsm : 1;
        unsigned int in_zq : 1;
        unsigned int reserved_0 : 2;
        unsigned int dfi_init_complete : 1;
        unsigned int reserved_1 : 2;
        unsigned int aref_opt_stat : 1;
        unsigned int reserved_2 : 3;
        unsigned int in_sfc : 1;
        unsigned int reserved_3 : 3;
        unsigned int rh_state : 8;
        unsigned int in_rh : 4;
        unsigned int in_phyupd : 1;
        unsigned int in_srpd : 1;
        unsigned int in_ram_pd : 1;
        unsigned int aref_intlv_mode_stat : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_FUNC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_sref_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_sref_END (0)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_srdsm_START (1)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_srdsm_END (1)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_zq_START (2)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_zq_END (2)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_dfi_init_complete_START (5)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_dfi_init_complete_END (5)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_aref_opt_stat_START (8)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_aref_opt_stat_END (8)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_sfc_START (12)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_sfc_END (12)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_rh_state_START (16)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_rh_state_END (23)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_rh_START (24)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_rh_END (27)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_phyupd_START (28)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_phyupd_END (28)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_srpd_START (29)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_srpd_END (29)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_ram_pd_START (30)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_in_ram_pd_END (30)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_aref_intlv_mode_stat_START (31)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC0_aref_intlv_mode_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_pd : 4;
        unsigned int in_tmon : 4;
        unsigned int in_osc_io : 4;
        unsigned int in_aref : 4;
        unsigned int in_asref : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_FUNC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_pd_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_pd_END (3)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_tmon_START (4)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_tmon_END (7)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_osc_io_START (8)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_osc_io_END (11)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_aref_START (12)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_aref_END (15)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_asref_START (16)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC1_in_asref_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_dummy_rd : 16;
        unsigned int in_osc : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_FUNC2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_in_dummy_rd_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_in_dummy_rd_END (15)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_in_osc_START (16)
#define SOC_DDRC_DMC_DDRC_CURR_FUNC2_in_osc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cv00_31 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_EXECST0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_EXECST0_dmc_cv00_31_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_EXECST0_dmc_cv00_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cv32_63 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_EXECST1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_EXECST1_dmc_cv32_63_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_EXECST1_dmc_cv32_63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_ct00_31 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_EXECST2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_EXECST2_dmc_ct00_31_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_EXECST2_dmc_ct00_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_ct32_63 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_EXECST3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_EXECST3_dmc_ct32_63_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_EXECST3_dmc_ct32_63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wgntfifo_e : 1;
        unsigned int wgntfifo_f : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_wgntfifo_e_START (0)
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_wgntfifo_e_END (0)
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_wgntfifo_f_START (1)
#define SOC_DDRC_DMC_DDRC_CURR_WGFIFOST_wgntfifo_f_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aref_fmain_ref_req : 4;
        unsigned int fmain_aref_ack : 4;
        unsigned int fmain_sref_ref_vld : 4;
        unsigned int reserved : 4;
        unsigned int pstpnd_cnt_rnk0 : 4;
        unsigned int pstpnd_cnt_rnk1 : 4;
        unsigned int pstpnd_cnt_rnk2 : 4;
        unsigned int pstpnd_cnt_rnk3 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_aref_fmain_ref_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_aref_fmain_ref_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_fmain_aref_ack_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_fmain_aref_ack_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_fmain_sref_ref_vld_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_fmain_sref_ref_vld_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk0_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk0_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk1_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk1_END (23)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk2_START (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk2_END (27)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk3_START (28)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT0_pstpnd_cnt_rnk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_fmain_sre_req : 4;
        unsigned int sref_fmain_srx_req : 4;
        unsigned int fmain_sre_ack : 4;
        unsigned int fmain_srx_ack : 4;
        unsigned int phyupd_in_max : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_sref_fmain_sre_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_sref_fmain_sre_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_sref_fmain_srx_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_sref_fmain_srx_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_fmain_sre_ack_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_fmain_sre_ack_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_fmain_srx_ack_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_fmain_srx_ack_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_phyupd_in_max_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT1_phyupd_in_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_fmain_pdex_req : 4;
        unsigned int fmain_pd_exit_req : 4;
        unsigned int fmain_pd_ack : 4;
        unsigned int pd_farb_cke : 4;
        unsigned int phyupd_out_max : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_pd_fmain_pdex_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_pd_fmain_pdex_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_fmain_pd_exit_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_fmain_pd_exit_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_fmain_pd_ack_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_fmain_pd_ack_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_pd_farb_cke_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_pd_farb_cke_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_phyupd_out_max_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT2_phyupd_out_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sfc_fmain_req : 4;
        unsigned int fmain_sfc_ack : 4;
        unsigned int reserved : 4;
        unsigned int func_bp_max_rnk0 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_sfc_fmain_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_sfc_fmain_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_fmain_sfc_ack_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_fmain_sfc_ack_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_func_bp_max_rnk0_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT3_func_bp_max_rnk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyupd_fmain_bp_req : 4;
        unsigned int phyupd_fmain_pre_req : 4;
        unsigned int fmain_phyupd_bp_ack : 4;
        unsigned int func_bp_max_rnk1 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT4_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_phyupd_fmain_bp_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_phyupd_fmain_bp_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_phyupd_fmain_pre_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_phyupd_fmain_pre_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_fmain_phyupd_bp_ack_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_fmain_phyupd_bp_ack_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_func_bp_max_rnk1_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT4_func_bp_max_rnk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rh_fmain_ref_req : 4;
        unsigned int fmain_rh_ack : 4;
        unsigned int reserved : 4;
        unsigned int func_bp_max_rnk2 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT13_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_rh_fmain_ref_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_rh_fmain_ref_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_fmain_rh_ack_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_fmain_rh_ack_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_func_bp_max_rnk2_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT13_func_bp_max_rnk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int func_bp_max_rnk3 : 20;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT14_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT14_func_bp_max_rnk3_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT14_func_bp_max_rnk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int zq_fmain_zqstart_req : 4;
        unsigned int zq_fmain_zqlatch_req : 4;
        unsigned int fmain_zq_zqstart_ack : 4;
        unsigned int fmain_zq_zqlatch_ack : 4;
        unsigned int fun_main_state0 : 4;
        unsigned int fun_main_state1 : 4;
        unsigned int fun_main_state2 : 4;
        unsigned int fun_main_state3 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT5_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_zq_fmain_zqstart_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_zq_fmain_zqstart_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_zq_fmain_zqlatch_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_zq_fmain_zqlatch_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fmain_zq_zqstart_ack_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fmain_zq_zqstart_ack_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fmain_zq_zqlatch_ack_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fmain_zq_zqlatch_ack_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state0_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state0_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state1_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state1_END (23)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state2_START (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state2_END (27)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state3_START (28)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT5_fun_main_state3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_fmain_oscmpc_req : 4;
        unsigned int osc_fmain_oscmrr_req : 4;
        unsigned int fmain_osc_oscmpc_ack : 4;
        unsigned int fmain_osc_oscmrr_ack : 4;
        unsigned int lp_state : 3;
        unsigned int fexec_state : 2;
        unsigned int reserved : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT6_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_osc_fmain_oscmpc_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_osc_fmain_oscmpc_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_osc_fmain_oscmrr_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_osc_fmain_oscmrr_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fmain_osc_oscmpc_ack_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fmain_osc_oscmpc_ack_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fmain_osc_oscmrr_ack_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fmain_osc_oscmrr_ack_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_lp_state_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_lp_state_END (18)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fexec_state_START (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT6_fexec_state_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dum_fmain_mrr_req : 4;
        unsigned int dum_fmain_mpc_req : 4;
        unsigned int ret_fmain_mpc_req : 4;
        unsigned int fmain_dum_ack : 4;
        unsigned int fmain_ret_ack : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT7_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_dum_fmain_mrr_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_dum_fmain_mrr_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_dum_fmain_mpc_req_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_dum_fmain_mpc_req_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_ret_fmain_mpc_req_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_ret_fmain_mpc_req_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_fmain_dum_ack_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_fmain_dum_ack_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_fmain_ret_ack_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT7_fmain_ret_ack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_fmain_mrr_req : 4;
        unsigned int fmain_tmon_ack : 4;
        unsigned int reserved : 8;
        unsigned int sref_state_rnk0 : 4;
        unsigned int sref_state_rnk1 : 4;
        unsigned int sref_state_rnk2 : 4;
        unsigned int sref_state_rnk3 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT8_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_tmon_fmain_mrr_req_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_tmon_fmain_mrr_req_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_fmain_tmon_ack_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_fmain_tmon_ack_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk0_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk0_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk1_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk1_END (23)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk2_START (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk2_END (27)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk3_START (28)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT8_sref_state_rnk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aref_state_rnk0 : 4;
        unsigned int aref_state_rnk1 : 4;
        unsigned int aref_state_rnk2 : 4;
        unsigned int aref_state_rnk3 : 4;
        unsigned int dumrd_state_rnk0 : 4;
        unsigned int dumrd_state_rnk1 : 4;
        unsigned int dumrd_state_rnk2 : 4;
        unsigned int dumrd_state_rnk3 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT9_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk0_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk0_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk1_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk1_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk2_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk2_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk3_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_aref_state_rnk3_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk0_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk0_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk1_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk1_END (23)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk2_START (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk2_END (27)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk3_START (28)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT9_dumrd_state_rnk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pd_state_rnk0 : 4;
        unsigned int pd_state_rnk1 : 4;
        unsigned int pd_state_rnk2 : 4;
        unsigned int pd_state_rnk3 : 4;
        unsigned int osc_state_rnk0 : 4;
        unsigned int osc_state_rnk1 : 4;
        unsigned int osc_state_rnk2 : 4;
        unsigned int osc_state_rnk3 : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT10_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk0_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk0_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk1_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk1_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk2_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk2_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk3_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_pd_state_rnk3_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk0_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk0_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk1_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk1_END (23)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk2_START (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk2_END (27)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk3_START (28)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT10_osc_state_rnk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tmon_state_rnk0 : 4;
        unsigned int tmon_state_rnk1 : 4;
        unsigned int tmon_state_rnk2 : 4;
        unsigned int tmon_state_rnk3 : 4;
        unsigned int ocfg_zq_state : 4;
        unsigned int ocfg_sfc_state : 5;
        unsigned int ocfg_phyupd_state : 4;
        unsigned int reserved : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_FUNC_STAT11_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk0_START (0)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk0_END (3)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk1_START (4)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk1_END (7)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk2_START (8)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk2_END (11)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk3_START (12)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_tmon_state_rnk3_END (15)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_zq_state_START (16)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_zq_state_END (19)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_sfc_state_START (20)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_sfc_state_END (24)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_phyupd_state_START (25)
#define SOC_DDRC_DMC_DDRC_FUNC_STAT11_ocfg_phyupd_state_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sb_fifo_full : 1;
        unsigned int sb_fifo_empty : 1;
        unsigned int rp_fifo_full : 1;
        unsigned int rp_fifo_empty : 1;
        unsigned int phy_fifo_full : 1;
        unsigned int phy_fifo_empty : 1;
        unsigned int lecc_fifo_full : 1;
        unsigned int lecc_fifo_empty : 1;
        unsigned int reserved_0 : 8;
        unsigned int timeout_cnt : 7;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_DDRC_DMC_STAT12_UNION;
#endif
#define SOC_DDRC_DMC_STAT12_sb_fifo_full_START (0)
#define SOC_DDRC_DMC_STAT12_sb_fifo_full_END (0)
#define SOC_DDRC_DMC_STAT12_sb_fifo_empty_START (1)
#define SOC_DDRC_DMC_STAT12_sb_fifo_empty_END (1)
#define SOC_DDRC_DMC_STAT12_rp_fifo_full_START (2)
#define SOC_DDRC_DMC_STAT12_rp_fifo_full_END (2)
#define SOC_DDRC_DMC_STAT12_rp_fifo_empty_START (3)
#define SOC_DDRC_DMC_STAT12_rp_fifo_empty_END (3)
#define SOC_DDRC_DMC_STAT12_phy_fifo_full_START (4)
#define SOC_DDRC_DMC_STAT12_phy_fifo_full_END (4)
#define SOC_DDRC_DMC_STAT12_phy_fifo_empty_START (5)
#define SOC_DDRC_DMC_STAT12_phy_fifo_empty_END (5)
#define SOC_DDRC_DMC_STAT12_lecc_fifo_full_START (6)
#define SOC_DDRC_DMC_STAT12_lecc_fifo_full_END (6)
#define SOC_DDRC_DMC_STAT12_lecc_fifo_empty_START (7)
#define SOC_DDRC_DMC_STAT12_lecc_fifo_empty_END (7)
#define SOC_DDRC_DMC_STAT12_timeout_cnt_START (16)
#define SOC_DDRC_DMC_STAT12_timeout_cnt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rec_alrt_cnt : 10;
        unsigned int rec_ca_rsnd_cnt : 7;
        unsigned int rec_wcrc_rsnd_cnt : 7;
        unsigned int rec_rcrc_rsnd_cnt : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_DDRC_DMC_DDRC_REC_STAT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_alrt_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_alrt_cnt_END (9)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_ca_rsnd_cnt_START (10)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_ca_rsnd_cnt_END (16)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_wcrc_rsnd_cnt_START (17)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_wcrc_rsnd_cnt_END (23)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_rcrc_rsnd_cnt_START (24)
#define SOC_DDRC_DMC_DDRC_REC_STAT0_rec_rcrc_rsnd_cnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mddrc_dmc_version : 16;
        unsigned int mddrc_dmc_width : 4;
        unsigned int reserved : 4;
        unsigned int mddrc_cfifo_num : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_version_START (0)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_version_END (15)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_width_START (16)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_dmc_width_END (19)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_cfifo_num_START (24)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG0_mddrc_cfifo_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mddrc_rank_num : 4;
        unsigned int mddrc_addr_width : 4;
        unsigned int mddrc_phy_type : 8;
        unsigned int mddrc_bank_xor_pos : 5;
        unsigned int reserved : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_rank_num_START (0)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_rank_num_END (3)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_addr_width_START (4)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_addr_width_END (7)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_phy_type_START (8)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_phy_type_END (15)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_bank_xor_pos_START (16)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG1_mddrc_bank_xor_pos_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mddrc_phy_in_flop : 1;
        unsigned int mddrc_debug_bus : 1;
        unsigned int mddrc_dasw_pipe_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_phy_in_flop_START (0)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_phy_in_flop_END (0)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_debug_bus_START (1)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_debug_bus_END (1)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_dasw_pipe_en_START (2)
#define SOC_DDRC_DMC_DDRC_TEST_RTL_CFG2_mddrc_dasw_pipe_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raa_cnt_rnk0 : 12;
        unsigned int raa_cnt_rnk1 : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk0_START (0)
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk0_END (11)
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk1_START (12)
#define SOC_DDRC_DMC_DDRC_RH_RAACNT_STAT0_raa_cnt_rnk1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_o_count : 16;
        unsigned int osc_o_count_base : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_COUNT0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_osc_o_count_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_osc_o_count_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_osc_o_count_base_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT0_osc_o_count_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_i_count : 16;
        unsigned int osc_i_count_base : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_COUNT1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_osc_i_count_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_osc_i_count_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_osc_i_count_base_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT1_osc_i_count_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_o_count_x8h : 16;
        unsigned int osc_o_count_x8h_base : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_COUNT2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_osc_o_count_x8h_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_osc_o_count_x8h_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_osc_o_count_x8h_base_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT2_osc_o_count_x8h_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_i_count_x8h : 16;
        unsigned int osc_i_count_x8h_base : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_COUNT3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_osc_i_count_x8h_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_osc_i_count_x8h_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_osc_i_count_x8h_base_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_COUNT3_osc_i_count_x8h_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_o_count_base_rd : 16;
        unsigned int osc_i_count_base_rd : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_BASE_RD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_osc_o_count_base_rd_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_osc_o_count_base_rd_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_osc_i_count_base_rd_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD_osc_i_count_base_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int osc_o_count_x8h_base_rd : 16;
        unsigned int osc_i_count_x8h_base_rd : 16;
    } reg;
} SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_osc_o_count_x8h_base_rd_START (0)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_osc_o_count_x8h_base_rd_END (15)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_osc_i_count_x8h_base_rd_START (16)
#define SOC_DDRC_DMC_DDRC_OSC_BASE_RD1_osc_i_count_x8h_base_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adpt_openpage_time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_DDRC_DMC_DDRC_OPENPAGE_TIME_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_OPENPAGE_TIME_adpt_openpage_time_START (0)
#define SOC_DDRC_DMC_DDRC_OPENPAGE_TIME_adpt_openpage_time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_group : 1;
        unsigned int in_grp_rw : 1;
        unsigned int in_grp_rank : 2;
        unsigned int reserved_0 : 4;
        unsigned int stat_serial_rcnt : 7;
        unsigned int stat_serial_wcnt : 7;
        unsigned int stat_serial_rankcnt : 7;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_GRP_STAT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_group_START (0)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_group_END (0)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_grp_rw_START (1)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_grp_rw_END (1)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_grp_rank_START (2)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_in_grp_rank_END (3)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_rcnt_START (8)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_rcnt_END (14)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_wcnt_START (15)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_wcnt_END (21)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_rankcnt_START (22)
#define SOC_DDRC_DMC_DDRC_GRP_STAT_stat_serial_rankcnt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_glbclk_swi : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CLK_OFF_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CLK_OFF_dfx_glbclk_swi_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CLK_OFF_dfx_glbclk_swi_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sb_fifo_clk_en : 1;
        unsigned int rp_fifo_clk_en : 1;
        unsigned int dfi_access_clk_en : 1;
        unsigned int glb_clk_en : 1;
        unsigned int dmc_pd_gt1 : 1;
        unsigned int dmc_pd_gt0 : 1;
        unsigned int funlc_clk_en : 1;
        unsigned int fexec_clk_en : 1;
        unsigned int zq_clk_en : 1;
        unsigned int sfc_clk_en : 1;
        unsigned int phyupd_clk_en : 1;
        unsigned int lp_clk_en : 1;
        unsigned int lvl2_clk_en : 1;
        unsigned int intleav_clk_en : 1;
        unsigned int exc_clk_en1 : 1;
        unsigned int exc_clk_en0 : 1;
        unsigned int tb_clk_en : 1;
        unsigned int pstque_clk_en : 1;
        unsigned int pre_clk_en : 1;
        unsigned int lc_clk_en : 1;
        unsigned int ws_clk_en : 1;
        unsigned int stat_clk_en : 1;
        unsigned int stadat_clk_en : 1;
        unsigned int stacmd_clk_en : 1;
        unsigned int reg_clk_en : 1;
        unsigned int pcfg_clk_en : 1;
        unsigned int dmcphy_clk_en : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_sb_fifo_clk_en_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_sb_fifo_clk_en_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_rp_fifo_clk_en_START (1)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_rp_fifo_clk_en_END (1)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dfi_access_clk_en_START (2)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dfi_access_clk_en_END (2)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_glb_clk_en_START (3)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_glb_clk_en_END (3)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmc_pd_gt1_START (4)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmc_pd_gt1_END (4)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmc_pd_gt0_START (5)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmc_pd_gt0_END (5)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_funlc_clk_en_START (6)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_funlc_clk_en_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_fexec_clk_en_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_fexec_clk_en_END (7)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_zq_clk_en_START (8)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_zq_clk_en_END (8)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_sfc_clk_en_START (9)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_sfc_clk_en_END (9)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_phyupd_clk_en_START (10)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_phyupd_clk_en_END (10)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lp_clk_en_START (11)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lp_clk_en_END (11)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lvl2_clk_en_START (12)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lvl2_clk_en_END (12)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_intleav_clk_en_START (13)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_intleav_clk_en_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en1_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en1_END (14)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en0_START (15)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_exc_clk_en0_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_tb_clk_en_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_tb_clk_en_END (16)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pstque_clk_en_START (17)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pstque_clk_en_END (17)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pre_clk_en_START (18)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pre_clk_en_END (18)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lc_clk_en_START (19)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_lc_clk_en_END (19)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_ws_clk_en_START (20)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_ws_clk_en_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stat_clk_en_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stat_clk_en_END (21)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stadat_clk_en_START (22)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stadat_clk_en_END (22)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stacmd_clk_en_START (23)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_stacmd_clk_en_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_reg_clk_en_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_reg_clk_en_END (24)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pcfg_clk_en_START (25)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_pcfg_clk_en_END (25)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmcphy_clk_en_START (26)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK0_dmcphy_clk_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slt_gt_en_h32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_GATE_CLK1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK1_slt_gt_en_h32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK1_slt_gt_en_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slt_gt_en_l32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_GATE_CLK2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK2_slt_gt_en_l32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_GATE_CLK2_slt_gt_en_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int que_wrcmd_num_rank0 : 7;
        unsigned int que_wrcmd_num_rank1 : 7;
        unsigned int que_rdcmd_num_rank0 : 7;
        unsigned int que_rdcmd_num_rank1 : 7;
        unsigned int que_empty : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_wrcmd_num_rank0_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_wrcmd_num_rank0_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_wrcmd_num_rank1_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_wrcmd_num_rank1_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_rdcmd_num_rank0_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_rdcmd_num_rank0_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_rdcmd_num_rank1_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_rdcmd_num_rank1_END (27)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_empty_START (28)
#define SOC_DDRC_DMC_DDRC_HIS_QUECMD_NUM_que_empty_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_reg1 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_EC1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_EC1_ec_reg1_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_EC1_ec_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_reg2 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_EC0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_EC0_ec_reg2_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_EC0_ec_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcfg_fsp_op : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_FSP_STATE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_FSP_STATE_pcfg_fsp_op_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_FSP_STATE_pcfg_fsp_op_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rbuf_dmc_rport_bp : 20;
        unsigned int func_sch_hold : 1;
        unsigned int rp_quc_rfifo_full : 1;
        unsigned int resp_dmc_bp : 1;
        unsigned int pr_quc_sref_pending : 1;
        unsigned int func_quc_bp : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_BP_STATE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_rbuf_dmc_rport_bp_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_rbuf_dmc_rport_bp_END (19)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_func_sch_hold_START (20)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_func_sch_hold_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_rp_quc_rfifo_full_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_rp_quc_rfifo_full_END (21)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_resp_dmc_bp_START (22)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_resp_dmc_bp_END (22)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_pr_quc_sref_pending_START (23)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_pr_quc_sref_pending_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_func_quc_bp_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_BP_STATE_func_quc_bp_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int all_write_cmd_len : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_WRDATA_OVER_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_WRDATA_OVER_all_write_cmd_len_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_WRDATA_OVER_all_write_cmd_len_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_mid : 7;
        unsigned int dmc_cmd_id : 12;
        unsigned int dmc_cmd_wrap : 1;
        unsigned int dmc_cmd_type : 1;
        unsigned int dmc_wdata_full : 1;
        unsigned int dmc_wdata_valid : 1;
        unsigned int dmc_rdata_valid : 1;
        unsigned int dmc_rdata_accept : 1;
        unsigned int dmc_cmd_valid : 1;
        unsigned int dmc_cmd_full : 1;
        unsigned int dmc_cmd_haddr : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_mid_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_mid_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_id_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_id_END (18)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_wrap_START (19)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_wrap_END (19)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_type_START (20)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_type_END (20)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_wdata_full_START (21)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_wdata_full_END (21)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_wdata_valid_START (22)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_wdata_valid_END (22)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_rdata_valid_START (23)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_rdata_valid_END (23)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_rdata_accept_START (24)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_rdata_accept_END (24)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_valid_START (25)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_valid_END (25)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_full_START (26)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_full_END (26)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_haddr_START (27)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF1_dmc_cmd_haddr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmc_cmd_addr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF0_dmc_cmd_addr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_IFCMD_INF0_dmc_cmd_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idconf_vld_h32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CMD_CONF3_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF3_idconf_vld_h32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF3_idconf_vld_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idconf_vld_l32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CMD_CONF2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF2_idconf_vld_l32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CMD_CONF2_idconf_vld_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adconf_vld_h32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF1_adconf_vld_h32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF1_adconf_vld_h32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adconf_vld_l32 : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF0_adconf_vld_l32_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_ADDR_CONF0_adconf_vld_l32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reram_one_bit_err : 1;
        unsigned int wdffram_one_bit_err : 1;
        unsigned int sbram_one_bit_err : 1;
        unsigned int rpram_one_bit_err : 1;
        unsigned int phyram_one_bit_err : 1;
        unsigned int monram_one_bit_err : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_reram_one_bit_err_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_reram_one_bit_err_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_wdffram_one_bit_err_START (1)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_wdffram_one_bit_err_END (1)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_sbram_one_bit_err_START (2)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_sbram_one_bit_err_END (2)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_rpram_one_bit_err_START (3)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_rpram_one_bit_err_END (3)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_phyram_one_bit_err_START (4)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_phyram_one_bit_err_END (4)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_monram_one_bit_err_START (5)
#define SOC_DDRC_DMC_DDRC_HIS_SRAM_COR_RES_monram_one_bit_err_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_err_type : 1;
        unsigned int sref_err_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_type_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_type_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_clr_START (1)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD2_sref_err_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_err_haddr : 1;
        unsigned int sref_err_id : 31;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_haddr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_haddr_END (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_id_START (1)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD1_sref_err_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sref_err_addr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD0_sref_err_addr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_SREF_ERR_CMD0_sref_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cas_wck2ck_sync_vld : 4;
        unsigned int cas_wck2ck_sync_cnt0 : 6;
        unsigned int cas_wck2ck_sync_cnt1 : 6;
        unsigned int cas_wck_on : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_vld_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_vld_END (3)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt0_START (4)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt0_END (9)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt1_START (10)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck2ck_sync_cnt1_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck_on_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_CAS_SYNC_cas_wck_on_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tphy_wdata_lat : 7;
        unsigned int tphy_wdata_en_lat : 7;
        unsigned int tphy_rden : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_wdata_lat_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_wdata_lat_END (6)
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_wdata_en_lat_START (7)
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_wdata_en_lat_END (13)
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_rden_START (14)
#define SOC_DDRC_DMC_DDRC_HIS_PHYIF_RES0_tphy_rden_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lecc_obit_cnt : 16;
        unsigned int err_inj_done : 2;
        unsigned int lecc_res : 9;
        unsigned int bytelane : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_lecc_obit_cnt_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_lecc_obit_cnt_END (15)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_err_inj_done_START (16)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_err_inj_done_END (17)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_lecc_res_START (18)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_lecc_res_END (26)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_bytelane_START (27)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_STATE_bytelane_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lecc_err_haddr : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_HADDR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_err_haddr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_HADDR_lecc_err_haddr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lecc_err_addr : 32;
    } reg;
} SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_ADDR_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_ADDR_lecc_err_addr_START (0)
#define SOC_DDRC_DMC_DDRC_HIS_LECC_ERR_ADDR_lecc_err_addr_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
