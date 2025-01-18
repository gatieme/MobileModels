#ifndef __SOC_HIPACKPHY_INTERFACE_H__
#define __SOC_HIPACKPHY_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACKPHY_REVISION_ADDR(base) ((base) + (0x000UL))
#define SOC_HIPACKPHY_PHYINITCTRL_ADDR(base) ((base) + (0x004UL))
#define SOC_HIPACKPHY_PHYINITSTATUS_ADDR(base) ((base) + (0x008UL))
#define SOC_HIPACKPHY_PHYCLKGATED_ADDR(base) ((base) + (0x000CUL))
#define SOC_HIPACKPHY_PHYTIMER0_ADDR(base) ((base) + (0x010UL))
#define SOC_HIPACKPHY_PHYTIMER1_ADDR(base) ((base) + (0x014UL))
#define SOC_HIPACKPHY_PLLCTRL_ADDR(base) ((base) + (0x018UL))
#define SOC_HIPACKPHY_PLLTIMER_ADDR(base) ((base) + (0x01CUL))
#define SOC_HIPACKPHY_DLYMEASCTRL_ADDR(base) ((base) + (0x020UL))
#define SOC_HIPACKPHY_IMPCTRL_ADDR(base) ((base) + (0x024UL))
#define SOC_HIPACKPHY_IMPSTATUS_ADDR(base) ((base) + (0x028UL))
#define SOC_HIPACKPHY_DRAMCFG_ADDR(base) ((base) + (0x02CUL))
#define SOC_HIPACKPHY_DRAMTIMER0_ADDR(base) ((base) + (0x030UL))
#define SOC_HIPACKPHY_DRAMTIMER1_ADDR(base) ((base) + (0x034UL))
#define SOC_HIPACKPHY_DRAMTIMER2_ADDR(base) ((base) + (0x038UL))
#define SOC_HIPACKPHY_DRAMTIMER3_ADDR(base) ((base) + (0x03CUL))
#define SOC_HIPACKPHY_DRAMTIMER4_ADDR(base) ((base) + (0x040UL))
#define SOC_HIPACKPHY_ODTCR_ADDR(base) ((base) + (0x044UL))
#define SOC_HIPACKPHY_TRAINCTRL0_ADDR(base) ((base) + (0x048UL))
#define SOC_HIPACKPHY_RANKEN_ADDR(base) ((base) + (0x04CUL))
#define SOC_HIPACKPHY_TRAINMADDR_ADDR(base) ((base) + (0x0050UL))
#define SOC_HIPACKPHY_BISTCTRL_ADDR(base) ((base) + (0x0054UL))
#define SOC_HIPACKPHY_BISTDATA0_ADDR(base) ((base) + (0x0058UL))
#define SOC_HIPACKPHY_BISTDATA1_ADDR(base) ((base) + (0x005CUL))
#define SOC_HIPACKPHY_BISTSTATUS_ADDR(base) ((base) + (0x0060UL))
#define SOC_HIPACKPHY_MODEREG01_ADDR(base) ((base) + (0x0064UL))
#define SOC_HIPACKPHY_MODEREG23_ADDR(base) ((base) + (0x0068UL))
#define SOC_HIPACKPHY_DETPATTERN_ADDR(base) ((base) + (0x006CUL))
#define SOC_HIPACKPHY_MISC_ADDR(base) ((base) + (0x0070UL))
#define SOC_HIPACKPHY_RNK2RNK_ADDR(base) ((base) + (0x0074UL))
#define SOC_HIPACKPHY_PHYCTRL0_ADDR(base) ((base) + (0x0078UL))
#define SOC_HIPACKPHY_PHYDBG_ADDR(base) ((base) + (0x007CUL))
#define SOC_HIPACKPHY_RETCTRL0_ADDR(base) ((base) + (0x0080UL))
#define SOC_HIPACKPHY_DMSEL_ADDR(base) ((base) + (0x0084UL))
#define SOC_HIPACKPHY_TRAINCTRL8_ADDR(base) ((base) + (0x0088UL))
#define SOC_HIPACKPHY_LPCTRL2_ADDR(base) ((base) + (0x008CUL))
#define SOC_HIPACKPHY_TRAINCTRL9_ADDR(base) ((base) + (0x0090UL))
#define SOC_HIPACKPHY_TRAINCTRL10_ADDR(base) ((base) + (0x094UL))
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_ADDR(base) ((base) + (0x0098UL))
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_ADDR(base) ((base) + (0x009CUL))
#define SOC_HIPACKPHY_SWTMODE_ADDR(base) ((base) + (0x00A0UL))
#define SOC_HIPACKPHY_SWTWLDQS_ADDR(base) ((base) + (0x00A4UL))
#define SOC_HIPACKPHY_SWTRLT_ADDR(base) ((base) + (0x00A8UL))
#define SOC_HIPACKPHY_PHYRSCTRL_ADDR(base) ((base) + (0x0B0UL))
#define SOC_HIPACKPHY_BISTCTRL2_ADDR(base) ((base) + (0x00B4UL))
#define SOC_HIPACKPHY_TRAINMADDRTG1_ADDR(base) ((base) + (0x00B8UL))
#define SOC_HIPACKPHY_DRAMTIMER5_ADDR(base) ((base) + (0x0BCUL))
#define SOC_HIPACKPHY_VREFTCTRL_ADDR(base) ((base) + (0x00C0UL))
#define SOC_HIPACKPHY_DVRFTCTRL_ADDR(base) ((base) + (0x00C4UL))
#define SOC_HIPACKPHY_HVRFTCTRL_ADDR(base) ((base) + (0x00C8UL))
#define SOC_HIPACKPHY_TRAINCTRL1_ADDR(base) ((base) + (0x00D0UL))
#define SOC_HIPACKPHY_TRAINCTRL2_ADDR(base) ((base) + (0x00D4UL))
#define SOC_HIPACKPHY_REGBANKCTRL_ADDR(base) ((base) + (0x00D8UL))
#define SOC_HIPACKPHY_TRAINCTRL3_ADDR(base) ((base) + (0x00DCUL))
#define SOC_HIPACKPHY_MODEREG45_ADDR(base) ((base) + (0x00E0UL))
#define SOC_HIPACKPHY_MODEREG67_ADDR(base) ((base) + (0x00E4UL))
#define SOC_HIPACKPHY_TRAINCTRL6_ADDR(base) ((base) + (0x0E8UL))
#define SOC_HIPACKPHY_DETPATINDEX_ADDR(base) ((base) + (0x00ECUL))
#define SOC_HIPACKPHY_TRAINSTEP0_ADDR(base) ((base) + (0x00F4UL))
#define SOC_HIPACKPHY_TRAINSTEP1_ADDR(base) ((base) + (0x00F8UL))
#define SOC_HIPACKPHY_TRAINSTEP2_ADDR(base) ((base) + (0x00FCUL))
#define SOC_HIPACKPHY_ACBISTCTRL0_ADDR(base) ((base) + (0x100UL))
#define SOC_HIPACKPHY_ACBISTCTRL1_ADDR(base) ((base) + (0x104UL))
#define SOC_HIPACKPHY_ACBISTSTS0_ADDR(base) ((base) + (0x108UL))
#define SOC_HIPACKPHY_ACBISTSTS1_ADDR(base) ((base) + (0x10CUL))
#define SOC_HIPACKPHY_WDXBOUND_DFS_ADDR(base) ((base) + (0x110UL))
#define SOC_HIPACKPHY_TRAINCTRL4_ADDR(base) ((base) + (0x114UL))
#define SOC_HIPACKPHY_TRAINCTRL5_ADDR(base) ((base) + (0x118UL))
#define SOC_HIPACKPHY_TRAINCTRL7_ADDR(base) ((base) + (0x11CUL))
#define SOC_HIPACKPHY_ACCMDBDL0_ADDR(base) ((base) + (0x120UL))
#define SOC_HIPACKPHY_IMPOFFSET_ADDR(base) ((base) + (0x124UL))
#define SOC_HIPACKPHY_ACCMDBDL2_ADDR(base) ((base) + (0x128UL))
#define SOC_HIPACKPHY_ACCMDBDL3_ADDR(base) ((base) + (0x12CUL))
#define SOC_HIPACKPHY_ACCMDBDL5_ADDR(base) ((base) + (0x134UL))
#define SOC_HIPACKPHY_ACCMDBDL6_ADDR(base) ((base) + (0x138UL))
#define SOC_HIPACKPHY_ACCMDBDL7_ADDR(base) ((base) + (0x13CUL))
#define SOC_HIPACKPHY_ACADDRBDL0_ADDR(base) ((base) + (0x140UL))
#define SOC_HIPACKPHY_ACADDRBDL1_ADDR(base) ((base) + (0x144UL))
#define SOC_HIPACKPHY_ACADDRBDL2_ADDR(base) ((base) + (0x148UL))
#define SOC_HIPACKPHY_ACADDRBDL3_ADDR(base) ((base) + (0x14CUL))
#define SOC_HIPACKPHY_ACADDRBDL4_ADDR(base) ((base) + (0x150UL))
#define SOC_HIPACKPHY_ACADDRBDL5_ADDR(base) ((base) + (0x154UL))
#define SOC_HIPACKPHY_ACADDRBDL6_ADDR(base) ((base) + (0x158UL))
#define SOC_HIPACKPHY_ACADDRBDL7_ADDR(base) ((base) + (0x15CUL))
#define SOC_HIPACKPHY_ACADDRBDL8_ADDR(base) ((base) + (0x160UL))
#define SOC_HIPACKPHY_ACADDRBDL9_ADDR(base) ((base) + (0x164UL))
#define SOC_HIPACKPHY_ACBISTCTRL2_ADDR(base) ((base) + (0x168UL))
#define SOC_HIPACKPHY_PLLJTMT_ADDR(base) ((base) + (0x16CUL))
#define SOC_HIPACKPHY_IMP_CTRL1_ADDR(base) ((base) + (0x170UL))
#define SOC_HIPACKPHY_IMP_STATUS1_ADDR(base) ((base) + (0x174UL))
#define SOC_HIPACKPHY_IMP_OUT_ADDR(base) ((base) + (0x178UL))
#define SOC_HIPACKPHY_TRAINCTRL11_ADDR(base) ((base) + (0x017CUL))
#define SOC_HIPACKPHY_FASTGDSRESULT0_ADDR(base) ((base) + (0x0180UL))
#define SOC_HIPACKPHY_FASTGDSRESULT1_ADDR(base) ((base) + (0x0184UL))
#define SOC_HIPACKPHY_FASTGTRESULT_ADDR(base) ((base) + (0x0188UL))
#define SOC_HIPACKPHY_TRKDBG_ADDR(base) ((base) + (0x18CUL))
#define SOC_HIPACKPHY_PACKDEBUG_ADDR(base) ((base) + (0x190UL))
#define SOC_HIPACKPHY_ACPHYRSVDC_ADDR(base) ((base) + (0x0194UL))
#define SOC_HIPACKPHY_ACPHYRSVDS_ADDR(base) ((base) + (0x0198UL))
#define SOC_HIPACKPHY_SWMRRDATA_ADDR(base) ((base) + (0x019CUL))
#define SOC_HIPACKPHY_WCKCTRL0_ADDR(base) ((base) + (0x1A0UL))
#define SOC_HIPACKPHY_WCKCTRL1_ADDR(base) ((base) + (0x1A4UL))
#define SOC_HIPACKPHY_DEVMODECFG_ADDR(base) ((base) + (0x01A8UL))
#define SOC_HIPACKPHY_LPCTRL3_ADDR(base) ((base) + (0x01ACUL))
#define SOC_HIPACKPHY_WCKCTRL2_ADDR(base) ((base) + (0x01B0UL))
#define SOC_HIPACKPHY_CATBDLBOUND_ADDR(base) ((base) + (0x01B4UL))
#define SOC_HIPACKPHY_CATSWAPINDEX_ADDR(base) ((base) + (0x01B8UL))
#define SOC_HIPACKPHY_CATSWAPSEL_ADDR(base) ((base) + (0x01BCUL))
#define SOC_HIPACKPHY_CATTIMER0_ADDR(base) ((base) + (0x01C0UL))
#define SOC_HIPACKPHY_CATTIMER1_ADDR(base) ((base) + (0x01C4UL))
#define SOC_HIPACKPHY_CATCONFIG_ADDR(base) ((base) + (0x01C8UL))
#define SOC_HIPACKPHY_CATRESULT_ADDR(base) ((base) + (0x01CCUL))
#define SOC_HIPACKPHY_PHYDQRESULT_ADDR(base) ((base) + (0x01D0UL))
#define SOC_HIPACKPHY_ADDRPHBOUND_ADDR(base) ((base) + (0x01D4UL))
#define SOC_HIPACKPHY_SWCATPATTERN_P_ADDR(base) ((base) + (0x01D8UL))
#define SOC_HIPACKPHY_PACKDEBUG1_ADDR(base) ((base) + (0x01DCUL))
#define SOC_HIPACKPHY_MRS_SEQ_PROG_ADDR(base) ((base) + (0x01E0UL))
#define SOC_HIPACKPHY_LPCTRL_ADDR(base) ((base) + (0x01E4UL))
#define SOC_HIPACKPHY_TRAINCTRL12_ADDR(base) ((base) + (0x01E8UL))
#define SOC_HIPACKPHY_CATCONFIG1_ADDR(base) ((base) + (0x01ECUL))
#define SOC_HIPACKPHY_AHVREFT_STATUS_ADDR(base) ((base) + (0x1F0UL))
#define SOC_HIPACKPHY_ADVREF_STATUS_ADDR(base) ((base) + (0x1F4UL))
#define SOC_HIPACKPHY_DLYMEASCTRL1_ADDR(base) ((base) + (0x1F8UL))
#define SOC_HIPACKPHY_DFIMISCCTRL_ADDR(base) ((base) + (0x1FCUL))
#define SOC_HIPACKPHY_DXNBISTCTRL_ADDR(base,n) ((base) + (0x200+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNBISTSTS_ADDR(base,n) ((base) + (0x204+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNCTRL_ADDR(base,n) ((base) + (0x208+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWECCBDL_ADDR(base,m,n) ((base) + (0x20C+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQNBDL0_ADDR(base,m,n) ((base) + (0x210+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQNBDL1_ADDR(base,m,n) ((base) + (0x214+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQNBDL2_ADDR(base,m,n) ((base) + (0x218+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQNBDL0_ADDR(base,m,n,l) ((base) + (0x21C+(l)*0x800+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQNBDL1_ADDR(base,m,n,l) ((base) + (0x220+(l)*0x800+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQNBDL2_ADDR(base,m,n,l) ((base) + (0x224+(l)*0x800+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNOEBDL_ADDR(base,m,n) ((base) + (0x228+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQSDLY_ADDR(base,n) ((base) + (0x22C+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQSDLY_ADDR(base,m,n) ((base) + (0x230+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQDLY_ADDR(base,m,n) ((base) + (0x234+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWLSL_ADDR(base,m,n) ((base) + (0x238+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNGDS_ADDR(base,m,n) ((base) + (0x23C+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQSGDLY_ADDR(base,m,n) ((base) + (0x240+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQNLB0_ADDR(base,n) ((base) + (0x244+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_ADDR(base,n) ((base) + (0x248+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNRDBOUND_ADDR(base,n) ((base) + (0x250+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWRBOUND_ADDR(base,n) ((base) + (0x254+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNWDQNLB1_ADDR(base,n) ((base) + (0x25C+(n)*0x80UL))
#define SOC_HIPACKPHY_DXDEBUG0_ADDR(base,n) ((base) + (0x268+(n)*0x80UL))
#define SOC_HIPACKPHY_DXDEBUG1_ADDR(base,n) ((base) + (0x26C+(n)*0x80UL))
#define SOC_HIPACKPHY_DVREFT_STATUS_ADDR(base,n) ((base) + (0x270+(n)*0x80UL))
#define SOC_HIPACKPHY_HVREFT_STATUS_ADDR(base,m,n) ((base) + (0x274+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_DXNTRACKSTATUS_ADDR(base,m,n,l) ((base) + (0x278+(l)*0x800+(m)*0x400+(n)*0x80UL))
#define SOC_HIPACKPHY_VREFT_BOUND_ADDR(base,n) ((base) + (0x27C+(n)*0x80UL))
#define SOC_HIPACKPHY_PLLSTATUS_ADDR(base) ((base) + (0x00ACUL))
#define SOC_HIPACKPHY_BISTCTRL1_ADDR(base) ((base) + (0x00F0UL))
#define SOC_HIPACKPHY_DETPATTERN1_ADDR(base) ((base) + (0x00CCUL))
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_ADDR(base) ((base) + (0x130UL))
#else
#define SOC_HIPACKPHY_REVISION_ADDR(base) ((base) + (0x000))
#define SOC_HIPACKPHY_PHYINITCTRL_ADDR(base) ((base) + (0x004))
#define SOC_HIPACKPHY_PHYINITSTATUS_ADDR(base) ((base) + (0x008))
#define SOC_HIPACKPHY_PHYCLKGATED_ADDR(base) ((base) + (0x000C))
#define SOC_HIPACKPHY_PHYTIMER0_ADDR(base) ((base) + (0x010))
#define SOC_HIPACKPHY_PHYTIMER1_ADDR(base) ((base) + (0x014))
#define SOC_HIPACKPHY_PLLCTRL_ADDR(base) ((base) + (0x018))
#define SOC_HIPACKPHY_PLLTIMER_ADDR(base) ((base) + (0x01C))
#define SOC_HIPACKPHY_DLYMEASCTRL_ADDR(base) ((base) + (0x020))
#define SOC_HIPACKPHY_IMPCTRL_ADDR(base) ((base) + (0x024))
#define SOC_HIPACKPHY_IMPSTATUS_ADDR(base) ((base) + (0x028))
#define SOC_HIPACKPHY_DRAMCFG_ADDR(base) ((base) + (0x02C))
#define SOC_HIPACKPHY_DRAMTIMER0_ADDR(base) ((base) + (0x030))
#define SOC_HIPACKPHY_DRAMTIMER1_ADDR(base) ((base) + (0x034))
#define SOC_HIPACKPHY_DRAMTIMER2_ADDR(base) ((base) + (0x038))
#define SOC_HIPACKPHY_DRAMTIMER3_ADDR(base) ((base) + (0x03C))
#define SOC_HIPACKPHY_DRAMTIMER4_ADDR(base) ((base) + (0x040))
#define SOC_HIPACKPHY_ODTCR_ADDR(base) ((base) + (0x044))
#define SOC_HIPACKPHY_TRAINCTRL0_ADDR(base) ((base) + (0x048))
#define SOC_HIPACKPHY_RANKEN_ADDR(base) ((base) + (0x04C))
#define SOC_HIPACKPHY_TRAINMADDR_ADDR(base) ((base) + (0x0050))
#define SOC_HIPACKPHY_BISTCTRL_ADDR(base) ((base) + (0x0054))
#define SOC_HIPACKPHY_BISTDATA0_ADDR(base) ((base) + (0x0058))
#define SOC_HIPACKPHY_BISTDATA1_ADDR(base) ((base) + (0x005C))
#define SOC_HIPACKPHY_BISTSTATUS_ADDR(base) ((base) + (0x0060))
#define SOC_HIPACKPHY_MODEREG01_ADDR(base) ((base) + (0x0064))
#define SOC_HIPACKPHY_MODEREG23_ADDR(base) ((base) + (0x0068))
#define SOC_HIPACKPHY_DETPATTERN_ADDR(base) ((base) + (0x006C))
#define SOC_HIPACKPHY_MISC_ADDR(base) ((base) + (0x0070))
#define SOC_HIPACKPHY_RNK2RNK_ADDR(base) ((base) + (0x0074))
#define SOC_HIPACKPHY_PHYCTRL0_ADDR(base) ((base) + (0x0078))
#define SOC_HIPACKPHY_PHYDBG_ADDR(base) ((base) + (0x007C))
#define SOC_HIPACKPHY_RETCTRL0_ADDR(base) ((base) + (0x0080))
#define SOC_HIPACKPHY_DMSEL_ADDR(base) ((base) + (0x0084))
#define SOC_HIPACKPHY_TRAINCTRL8_ADDR(base) ((base) + (0x0088))
#define SOC_HIPACKPHY_LPCTRL2_ADDR(base) ((base) + (0x008C))
#define SOC_HIPACKPHY_TRAINCTRL9_ADDR(base) ((base) + (0x0090))
#define SOC_HIPACKPHY_TRAINCTRL10_ADDR(base) ((base) + (0x094))
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_ADDR(base) ((base) + (0x0098))
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_ADDR(base) ((base) + (0x009C))
#define SOC_HIPACKPHY_SWTMODE_ADDR(base) ((base) + (0x00A0))
#define SOC_HIPACKPHY_SWTWLDQS_ADDR(base) ((base) + (0x00A4))
#define SOC_HIPACKPHY_SWTRLT_ADDR(base) ((base) + (0x00A8))
#define SOC_HIPACKPHY_PHYRSCTRL_ADDR(base) ((base) + (0x0B0))
#define SOC_HIPACKPHY_BISTCTRL2_ADDR(base) ((base) + (0x00B4))
#define SOC_HIPACKPHY_TRAINMADDRTG1_ADDR(base) ((base) + (0x00B8))
#define SOC_HIPACKPHY_DRAMTIMER5_ADDR(base) ((base) + (0x0BC))
#define SOC_HIPACKPHY_VREFTCTRL_ADDR(base) ((base) + (0x00C0))
#define SOC_HIPACKPHY_DVRFTCTRL_ADDR(base) ((base) + (0x00C4))
#define SOC_HIPACKPHY_HVRFTCTRL_ADDR(base) ((base) + (0x00C8))
#define SOC_HIPACKPHY_TRAINCTRL1_ADDR(base) ((base) + (0x00D0))
#define SOC_HIPACKPHY_TRAINCTRL2_ADDR(base) ((base) + (0x00D4))
#define SOC_HIPACKPHY_REGBANKCTRL_ADDR(base) ((base) + (0x00D8))
#define SOC_HIPACKPHY_TRAINCTRL3_ADDR(base) ((base) + (0x00DC))
#define SOC_HIPACKPHY_MODEREG45_ADDR(base) ((base) + (0x00E0))
#define SOC_HIPACKPHY_MODEREG67_ADDR(base) ((base) + (0x00E4))
#define SOC_HIPACKPHY_TRAINCTRL6_ADDR(base) ((base) + (0x0E8))
#define SOC_HIPACKPHY_DETPATINDEX_ADDR(base) ((base) + (0x00EC))
#define SOC_HIPACKPHY_TRAINSTEP0_ADDR(base) ((base) + (0x00F4))
#define SOC_HIPACKPHY_TRAINSTEP1_ADDR(base) ((base) + (0x00F8))
#define SOC_HIPACKPHY_TRAINSTEP2_ADDR(base) ((base) + (0x00FC))
#define SOC_HIPACKPHY_ACBISTCTRL0_ADDR(base) ((base) + (0x100))
#define SOC_HIPACKPHY_ACBISTCTRL1_ADDR(base) ((base) + (0x104))
#define SOC_HIPACKPHY_ACBISTSTS0_ADDR(base) ((base) + (0x108))
#define SOC_HIPACKPHY_ACBISTSTS1_ADDR(base) ((base) + (0x10C))
#define SOC_HIPACKPHY_WDXBOUND_DFS_ADDR(base) ((base) + (0x110))
#define SOC_HIPACKPHY_TRAINCTRL4_ADDR(base) ((base) + (0x114))
#define SOC_HIPACKPHY_TRAINCTRL5_ADDR(base) ((base) + (0x118))
#define SOC_HIPACKPHY_TRAINCTRL7_ADDR(base) ((base) + (0x11C))
#define SOC_HIPACKPHY_ACCMDBDL0_ADDR(base) ((base) + (0x120))
#define SOC_HIPACKPHY_IMPOFFSET_ADDR(base) ((base) + (0x124))
#define SOC_HIPACKPHY_ACCMDBDL2_ADDR(base) ((base) + (0x128))
#define SOC_HIPACKPHY_ACCMDBDL3_ADDR(base) ((base) + (0x12C))
#define SOC_HIPACKPHY_ACCMDBDL5_ADDR(base) ((base) + (0x134))
#define SOC_HIPACKPHY_ACCMDBDL6_ADDR(base) ((base) + (0x138))
#define SOC_HIPACKPHY_ACCMDBDL7_ADDR(base) ((base) + (0x13C))
#define SOC_HIPACKPHY_ACADDRBDL0_ADDR(base) ((base) + (0x140))
#define SOC_HIPACKPHY_ACADDRBDL1_ADDR(base) ((base) + (0x144))
#define SOC_HIPACKPHY_ACADDRBDL2_ADDR(base) ((base) + (0x148))
#define SOC_HIPACKPHY_ACADDRBDL3_ADDR(base) ((base) + (0x14C))
#define SOC_HIPACKPHY_ACADDRBDL4_ADDR(base) ((base) + (0x150))
#define SOC_HIPACKPHY_ACADDRBDL5_ADDR(base) ((base) + (0x154))
#define SOC_HIPACKPHY_ACADDRBDL6_ADDR(base) ((base) + (0x158))
#define SOC_HIPACKPHY_ACADDRBDL7_ADDR(base) ((base) + (0x15C))
#define SOC_HIPACKPHY_ACADDRBDL8_ADDR(base) ((base) + (0x160))
#define SOC_HIPACKPHY_ACADDRBDL9_ADDR(base) ((base) + (0x164))
#define SOC_HIPACKPHY_ACBISTCTRL2_ADDR(base) ((base) + (0x168))
#define SOC_HIPACKPHY_PLLJTMT_ADDR(base) ((base) + (0x16C))
#define SOC_HIPACKPHY_IMP_CTRL1_ADDR(base) ((base) + (0x170))
#define SOC_HIPACKPHY_IMP_STATUS1_ADDR(base) ((base) + (0x174))
#define SOC_HIPACKPHY_IMP_OUT_ADDR(base) ((base) + (0x178))
#define SOC_HIPACKPHY_TRAINCTRL11_ADDR(base) ((base) + (0x017C))
#define SOC_HIPACKPHY_FASTGDSRESULT0_ADDR(base) ((base) + (0x0180))
#define SOC_HIPACKPHY_FASTGDSRESULT1_ADDR(base) ((base) + (0x0184))
#define SOC_HIPACKPHY_FASTGTRESULT_ADDR(base) ((base) + (0x0188))
#define SOC_HIPACKPHY_TRKDBG_ADDR(base) ((base) + (0x18C))
#define SOC_HIPACKPHY_PACKDEBUG_ADDR(base) ((base) + (0x190))
#define SOC_HIPACKPHY_ACPHYRSVDC_ADDR(base) ((base) + (0x0194))
#define SOC_HIPACKPHY_ACPHYRSVDS_ADDR(base) ((base) + (0x0198))
#define SOC_HIPACKPHY_SWMRRDATA_ADDR(base) ((base) + (0x019C))
#define SOC_HIPACKPHY_WCKCTRL0_ADDR(base) ((base) + (0x1A0))
#define SOC_HIPACKPHY_WCKCTRL1_ADDR(base) ((base) + (0x1A4))
#define SOC_HIPACKPHY_DEVMODECFG_ADDR(base) ((base) + (0x01A8))
#define SOC_HIPACKPHY_LPCTRL3_ADDR(base) ((base) + (0x01AC))
#define SOC_HIPACKPHY_WCKCTRL2_ADDR(base) ((base) + (0x01B0))
#define SOC_HIPACKPHY_CATBDLBOUND_ADDR(base) ((base) + (0x01B4))
#define SOC_HIPACKPHY_CATSWAPINDEX_ADDR(base) ((base) + (0x01B8))
#define SOC_HIPACKPHY_CATSWAPSEL_ADDR(base) ((base) + (0x01BC))
#define SOC_HIPACKPHY_CATTIMER0_ADDR(base) ((base) + (0x01C0))
#define SOC_HIPACKPHY_CATTIMER1_ADDR(base) ((base) + (0x01C4))
#define SOC_HIPACKPHY_CATCONFIG_ADDR(base) ((base) + (0x01C8))
#define SOC_HIPACKPHY_CATRESULT_ADDR(base) ((base) + (0x01CC))
#define SOC_HIPACKPHY_PHYDQRESULT_ADDR(base) ((base) + (0x01D0))
#define SOC_HIPACKPHY_ADDRPHBOUND_ADDR(base) ((base) + (0x01D4))
#define SOC_HIPACKPHY_SWCATPATTERN_P_ADDR(base) ((base) + (0x01D8))
#define SOC_HIPACKPHY_PACKDEBUG1_ADDR(base) ((base) + (0x01DC))
#define SOC_HIPACKPHY_MRS_SEQ_PROG_ADDR(base) ((base) + (0x01E0))
#define SOC_HIPACKPHY_LPCTRL_ADDR(base) ((base) + (0x01E4))
#define SOC_HIPACKPHY_TRAINCTRL12_ADDR(base) ((base) + (0x01E8))
#define SOC_HIPACKPHY_CATCONFIG1_ADDR(base) ((base) + (0x01EC))
#define SOC_HIPACKPHY_AHVREFT_STATUS_ADDR(base) ((base) + (0x1F0))
#define SOC_HIPACKPHY_ADVREF_STATUS_ADDR(base) ((base) + (0x1F4))
#define SOC_HIPACKPHY_DLYMEASCTRL1_ADDR(base) ((base) + (0x1F8))
#define SOC_HIPACKPHY_DFIMISCCTRL_ADDR(base) ((base) + (0x1FC))
#define SOC_HIPACKPHY_DXNBISTCTRL_ADDR(base,n) ((base) + (0x200+(n)*0x80))
#define SOC_HIPACKPHY_DXNBISTSTS_ADDR(base,n) ((base) + (0x204+(n)*0x80))
#define SOC_HIPACKPHY_DXNCTRL_ADDR(base,n) ((base) + (0x208+(n)*0x80))
#define SOC_HIPACKPHY_DXNWECCBDL_ADDR(base,m,n) ((base) + (0x20C+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQNBDL0_ADDR(base,m,n) ((base) + (0x210+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQNBDL1_ADDR(base,m,n) ((base) + (0x214+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQNBDL2_ADDR(base,m,n) ((base) + (0x218+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQNBDL0_ADDR(base,m,n,l) ((base) + (0x21C+(l)*0x800+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQNBDL1_ADDR(base,m,n,l) ((base) + (0x220+(l)*0x800+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQNBDL2_ADDR(base,m,n,l) ((base) + (0x224+(l)*0x800+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNOEBDL_ADDR(base,m,n) ((base) + (0x228+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQSDLY_ADDR(base,n) ((base) + (0x22C+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQSDLY_ADDR(base,m,n) ((base) + (0x230+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQDLY_ADDR(base,m,n) ((base) + (0x234+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWLSL_ADDR(base,m,n) ((base) + (0x238+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNGDS_ADDR(base,m,n) ((base) + (0x23C+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQSGDLY_ADDR(base,m,n) ((base) + (0x240+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQNLB0_ADDR(base,n) ((base) + (0x244+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_ADDR(base,n) ((base) + (0x248+(n)*0x80))
#define SOC_HIPACKPHY_DXNRDBOUND_ADDR(base,n) ((base) + (0x250+(n)*0x80))
#define SOC_HIPACKPHY_DXNWRBOUND_ADDR(base,n) ((base) + (0x254+(n)*0x80))
#define SOC_HIPACKPHY_DXNWDQNLB1_ADDR(base,n) ((base) + (0x25C+(n)*0x80))
#define SOC_HIPACKPHY_DXDEBUG0_ADDR(base,n) ((base) + (0x268+(n)*0x80))
#define SOC_HIPACKPHY_DXDEBUG1_ADDR(base,n) ((base) + (0x26C+(n)*0x80))
#define SOC_HIPACKPHY_DVREFT_STATUS_ADDR(base,n) ((base) + (0x270+(n)*0x80))
#define SOC_HIPACKPHY_HVREFT_STATUS_ADDR(base,m,n) ((base) + (0x274+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_DXNTRACKSTATUS_ADDR(base,m,n,l) ((base) + (0x278+(l)*0x800+(m)*0x400+(n)*0x80))
#define SOC_HIPACKPHY_VREFT_BOUND_ADDR(base,n) ((base) + (0x27C+(n)*0x80))
#define SOC_HIPACKPHY_PLLSTATUS_ADDR(base) ((base) + (0x00AC))
#define SOC_HIPACKPHY_BISTCTRL1_ADDR(base) ((base) + (0x00F0))
#define SOC_HIPACKPHY_DETPATTERN1_ADDR(base) ((base) + (0x00CC))
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_ADDR(base) ((base) + (0x130))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACKPHY_UC_TRCTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_HIPACKPHY_UC_TROPCTRL_ADDR(base) ((base) + (0x004UL))
#define SOC_HIPACKPHY_UC_DTRSTSP_ADDR(base) ((base) + (0x008UL))
#define SOC_HIPACKPHY_UC_TRSTATUS_ADDR(base) ((base) + (0x00CUL))
#define SOC_HIPACKPHY_UC_CMDQCTRL_ADDR(base) ((base) + (0x010UL))
#define SOC_HIPACKPHY_UC_APB_CAS_ADDR(base) ((base) + (0x020UL))
#define SOC_HIPACKPHY_UC_APB_WDATA_ADDR(base) ((base) + (0x024UL))
#define SOC_HIPACKPHY_UC_APB_RDATA_ADDR(base) ((base) + (0x028UL))
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_ADDR(base) ((base) + (0x030UL))
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + (0x034UL))
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_ADDR(base) ((base) + (0x038UL))
#define SOC_HIPACKPHY_UC_WDQPHAUC_ADDR(base) ((base) + (0x040UL))
#define SOC_HIPACKPHY_UC_WDQSPHAUC_ADDR(base) ((base) + (0x048UL))
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_ADDR(base) ((base) + (0x04CUL))
#define SOC_HIPACKPHY_UC_WDLYOP_ADDR(base) ((base) + (0x050UL))
#define SOC_HIPACKPHY_UC_RDQSAUC_ADDR(base) ((base) + (0x080UL))
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_ADDR(base) ((base) + (0x084UL))
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_ADDR(base) ((base) + (0x088UL))
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_ADDR(base) ((base) + (0x08CUL))
#define SOC_HIPACKPHY_UC_RGDSAUC_ADDR(base) ((base) + (0x090UL))
#define SOC_HIPACKPHY_UC_RDLYOP_ADDR(base) ((base) + (0x094UL))
#define SOC_HIPACKPHY_UCSWTMODE_ADDR(base) ((base) + (0x0A0UL))
#define SOC_HIPACKPHY_UCSWTWLDQS_ADDR(base) ((base) + (0x0A4UL))
#define SOC_HIPACKPHY_UC_SWTRLT_ADDR(base) ((base) + (0x0A8UL))
#define SOC_HIPACKPHY_UCSWMRRDATA_ADDR(base) ((base) + (0x0ACUL))
#define SOC_HIPACKPHY_UCCATCONFIG_ADDR(base) ((base) + (0x0B0UL))
#define SOC_HIPACKPHY_UCPHYDQRESULT_ADDR(base) ((base) + (0x0B8UL))
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_ADDR(base) ((base) + (0x0BCUL))
#define SOC_HIPACKPHY_UCFASTGDSRLT0_ADDR(base) ((base) + (0x0C4UL))
#define SOC_HIPACKPHY_UCFASTGDSRLT1_ADDR(base) ((base) + (0x0C8UL))
#define SOC_HIPACKPHY_UCFASTGTRLT_ADDR(base) ((base) + (0x0CCUL))
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_ADDR(base) ((base) + (0x0D0UL))
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG0_ADDR(base) ((base) + (0x0D4UL))
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG1_ADDR(base) ((base) + (0x0D8UL))
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_ADDR(base) ((base) + (0x0DCUL))
#define SOC_HIPACKPHY_UCDBG_PERBIT0_ADDR(base) ((base) + (0x0E0UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT1_ADDR(base) ((base) + (0x0E4UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT2_ADDR(base) ((base) + (0x0E8UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT3_ADDR(base) ((base) + (0x0ECUL))
#define SOC_HIPACKPHY_UCDBG_PERBIT4_ADDR(base) ((base) + (0x0F0UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT5_ADDR(base) ((base) + (0x0F4UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT6_ADDR(base) ((base) + (0x0F8UL))
#define SOC_HIPACKPHY_UCDBG_PERBIT7_ADDR(base) ((base) + (0x0FCUL))
#define SOC_HIPACKPHY_UC_WDQNAUC_ADDR(base,n) ((base) + (0x100 + (n) * 0x80UL))
#define SOC_HIPACKPHY_UC_RDQNAUC_ADDR(base,n) ((base) + (0x104 + (n) * 0x80UL))
#define SOC_HIPACKPHY_UC_DTRSTS_ADDR(base,n) ((base) + (0x108 + (n) * 0x80UL))
#define SOC_HIPACKPHY_UC_WDQNAUC2_ADDR(base,n) ((base) + (0x10C + (n) * 0x80UL))
#define SOC_HIPACKPHY_UC_RDQNAUC2_ADDR(base,n) ((base) + (0x110 + (n) * 0x80UL))
#else
#define SOC_HIPACKPHY_UC_TRCTRL_ADDR(base) ((base) + (0x000))
#define SOC_HIPACKPHY_UC_TROPCTRL_ADDR(base) ((base) + (0x004))
#define SOC_HIPACKPHY_UC_DTRSTSP_ADDR(base) ((base) + (0x008))
#define SOC_HIPACKPHY_UC_TRSTATUS_ADDR(base) ((base) + (0x00C))
#define SOC_HIPACKPHY_UC_CMDQCTRL_ADDR(base) ((base) + (0x010))
#define SOC_HIPACKPHY_UC_APB_CAS_ADDR(base) ((base) + (0x020))
#define SOC_HIPACKPHY_UC_APB_WDATA_ADDR(base) ((base) + (0x024))
#define SOC_HIPACKPHY_UC_APB_RDATA_ADDR(base) ((base) + (0x028))
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_ADDR(base) ((base) + (0x030))
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_ADDR(base) ((base) + (0x034))
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_ADDR(base) ((base) + (0x038))
#define SOC_HIPACKPHY_UC_WDQPHAUC_ADDR(base) ((base) + (0x040))
#define SOC_HIPACKPHY_UC_WDQSPHAUC_ADDR(base) ((base) + (0x048))
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_ADDR(base) ((base) + (0x04C))
#define SOC_HIPACKPHY_UC_WDLYOP_ADDR(base) ((base) + (0x050))
#define SOC_HIPACKPHY_UC_RDQSAUC_ADDR(base) ((base) + (0x080))
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_ADDR(base) ((base) + (0x084))
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_ADDR(base) ((base) + (0x088))
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_ADDR(base) ((base) + (0x08C))
#define SOC_HIPACKPHY_UC_RGDSAUC_ADDR(base) ((base) + (0x090))
#define SOC_HIPACKPHY_UC_RDLYOP_ADDR(base) ((base) + (0x094))
#define SOC_HIPACKPHY_UCSWTMODE_ADDR(base) ((base) + (0x0A0))
#define SOC_HIPACKPHY_UCSWTWLDQS_ADDR(base) ((base) + (0x0A4))
#define SOC_HIPACKPHY_UC_SWTRLT_ADDR(base) ((base) + (0x0A8))
#define SOC_HIPACKPHY_UCSWMRRDATA_ADDR(base) ((base) + (0x0AC))
#define SOC_HIPACKPHY_UCCATCONFIG_ADDR(base) ((base) + (0x0B0))
#define SOC_HIPACKPHY_UCPHYDQRESULT_ADDR(base) ((base) + (0x0B8))
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_ADDR(base) ((base) + (0x0BC))
#define SOC_HIPACKPHY_UCFASTGDSRLT0_ADDR(base) ((base) + (0x0C4))
#define SOC_HIPACKPHY_UCFASTGDSRLT1_ADDR(base) ((base) + (0x0C8))
#define SOC_HIPACKPHY_UCFASTGTRLT_ADDR(base) ((base) + (0x0CC))
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_ADDR(base) ((base) + (0x0D0))
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG0_ADDR(base) ((base) + (0x0D4))
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG1_ADDR(base) ((base) + (0x0D8))
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_ADDR(base) ((base) + (0x0DC))
#define SOC_HIPACKPHY_UCDBG_PERBIT0_ADDR(base) ((base) + (0x0E0))
#define SOC_HIPACKPHY_UCDBG_PERBIT1_ADDR(base) ((base) + (0x0E4))
#define SOC_HIPACKPHY_UCDBG_PERBIT2_ADDR(base) ((base) + (0x0E8))
#define SOC_HIPACKPHY_UCDBG_PERBIT3_ADDR(base) ((base) + (0x0EC))
#define SOC_HIPACKPHY_UCDBG_PERBIT4_ADDR(base) ((base) + (0x0F0))
#define SOC_HIPACKPHY_UCDBG_PERBIT5_ADDR(base) ((base) + (0x0F4))
#define SOC_HIPACKPHY_UCDBG_PERBIT6_ADDR(base) ((base) + (0x0F8))
#define SOC_HIPACKPHY_UCDBG_PERBIT7_ADDR(base) ((base) + (0x0FC))
#define SOC_HIPACKPHY_UC_WDQNAUC_ADDR(base,n) ((base) + (0x100 + (n) * 0x80))
#define SOC_HIPACKPHY_UC_RDQNAUC_ADDR(base,n) ((base) + (0x104 + (n) * 0x80))
#define SOC_HIPACKPHY_UC_DTRSTS_ADDR(base,n) ((base) + (0x108 + (n) * 0x80))
#define SOC_HIPACKPHY_UC_WDQNAUC2_ADDR(base,n) ((base) + (0x10C + (n) * 0x80))
#define SOC_HIPACKPHY_UC_RDQNAUC2_ADDR(base,n) ((base) + (0x110 + (n) * 0x80))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACKPHY_ACCTRL_TRX0_ADDR(base) ((base) + (0x000UL))
#define SOC_HIPACKPHY_ACCTRL_TRX1_ADDR(base) ((base) + (0x004UL))
#define SOC_HIPACKPHY_ACCTL_BYPASS_ADDR(base) ((base) + (0x008UL))
#define SOC_HIPACKPHY_AC_IECTRL0_ADDR(base) ((base) + (0x00CUL))
#define SOC_HIPACKPHY_AC_IECTRL1_ADDR(base) ((base) + (0x010UL))
#define SOC_HIPACKPHY_AC_RX_SET_ADDR(base) ((base) + (0x014UL))
#define SOC_HIPACKPHY_AC_RX_SET1_ADDR(base) ((base) + (0x018UL))
#define SOC_HIPACKPHY_AC_IOMODE_ADDR(base) ((base) + (0x01CUL))
#define SOC_HIPACKPHY_AC_IOREFCTRL0_ADDR(base) ((base) + (0x020UL))
#define SOC_HIPACKPHY_AC_IOREFCTRL1_ADDR(base) ((base) + (0x024UL))
#define SOC_HIPACKPHY_AC_IOREFCTRL2_ADDR(base) ((base) + (0x028UL))
#define SOC_HIPACKPHY_AC_IOEQCTRL0_ADDR(base) ((base) + (0x02CUL))
#define SOC_HIPACKPHY_AC_IOEQCTRL1_ADDR(base) ((base) + (0x030UL))
#define SOC_HIPACKPHY_AC_IOEQCTRL2_ADDR(base) ((base) + (0x034UL))
#define SOC_HIPACKPHY_AC_IOEQCTRL3_ADDR(base) ((base) + (0x038UL))
#define SOC_HIPACKPHY_AC_PECTRL0_ADDR(base) ((base) + (0x03CUL))
#define SOC_HIPACKPHY_AC_PECTRL1_ADDR(base) ((base) + (0x040UL))
#define SOC_HIPACKPHY_AC_PUPDCTRL_ADDR(base) ((base) + (0x044UL))
#define SOC_HIPACKPHY_AC_RONCTRL0_ADDR(base) ((base) + (0x048UL))
#define SOC_HIPACKPHY_AC_RONCTRL1_ADDR(base) ((base) + (0x04CUL))
#define SOC_HIPACKPHY_AC_ODTCTRL0_ADDR(base) ((base) + (0x050UL))
#define SOC_HIPACKPHY_AC_ODTCTRL1_ADDR(base) ((base) + (0x054UL))
#define SOC_HIPACKPHY_AC_ODTCTRL2_ADDR(base) ((base) + (0x058UL))
#define SOC_HIPACKPHY_AC_ODTCTRL3_ADDR(base) ((base) + (0x05CUL))
#define SOC_HIPACKPHY_AC_TESTCTRL0_ADDR(base) ((base) + (0x060UL))
#define SOC_HIPACKPHY_AC_TESTCTRL1_ADDR(base) ((base) + (0x064UL))
#define SOC_HIPACKPHY_AC_TESTCTRL2_ADDR(base) ((base) + (0x068UL))
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_ADDR(base) ((base) + (0x06CUL))
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_ADDR(base) ((base) + (0x070UL))
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_ADDR(base) ((base) + (0x074UL))
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_ADDR(base) ((base) + (0x078UL))
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_ADDR(base) ((base) + (0x07CUL))
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_ADDR(base) ((base) + (0x080UL))
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_ADDR(base) ((base) + (0x084UL))
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_ADDR(base) ((base) + (0x088UL))
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_ADDR(base) ((base) + (0x08CUL))
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_ADDR(base) ((base) + (0x090UL))
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_ADDR(base) ((base) + (0x094UL))
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_ADDR(base) ((base) + (0x098UL))
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_ADDR(base) ((base) + (0x09CUL))
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_ADDR(base) ((base) + (0x0A0UL))
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_ADDR(base) ((base) + (0x0A4UL))
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_ADDR(base) ((base) + (0x0A8UL))
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_ADDR(base) ((base) + (0x0ACUL))
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_ADDR(base) ((base) + (0x0B0UL))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_ADDR(base) ((base) + (0x0B4UL))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_ADDR(base) ((base) + (0x0B8UL))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_ADDR(base) ((base) + (0x0BCUL))
#define SOC_HIPACKPHY_AC_DLL_CODE_ADDR(base) ((base) + (0x0C0UL))
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_ADDR(base) ((base) + (0x0C4UL))
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_ADDR(base) ((base) + (0x0C8UL))
#define SOC_HIPACKPHY_AC_BDL_CTRL0_ADDR(base) ((base) + (0x0CCUL))
#define SOC_HIPACKPHY_AC_BDL_CTRL1_ADDR(base) ((base) + (0x0D0UL))
#define SOC_HIPACKPHY_AC_BDL_CTRL2_ADDR(base) ((base) + (0x0D4UL))
#define SOC_HIPACKPHY_AC_BDL_CTRL3_ADDR(base) ((base) + (0x0D8UL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_ADDR(base) ((base) + (0x0DCUL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_ADDR(base) ((base) + (0x0E0UL))
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_ADDR(base) ((base) + (0x0E4UL))
#define SOC_HIPACKPHY_AC_IOEQCTRL4_ADDR(base) ((base) + (0x0E8UL))
#define SOC_HIPACKPHY_AC_IOEQCTRL5_ADDR(base) ((base) + (0x0ECUL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_ADDR(base) ((base) + (0x0F0UL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_ADDR(base) ((base) + (0x0F4UL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_ADDR(base) ((base) + (0x0F8UL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_ADDR(base) ((base) + (0x0FCUL))
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_ADDR(base) ((base) + (0x100UL))
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_ADDR(base) ((base) + (0x104UL))
#define SOC_HIPACKPHY_AC_PLL_DBG_A_ADDR(base) ((base) + (0x108UL))
#define SOC_HIPACKPHY_AC_PLL_DBG_B_ADDR(base) ((base) + (0x10CUL))
#define SOC_HIPACKPHY_AC_CTRL_1_ADDR(base) ((base) + (0x110UL))
#define SOC_HIPACKPHY_AC_REV_REG_0_ADDR(base) ((base) + (0x114UL))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_0_ADDR(base) ((base) + (0x118UL))
#define SOC_HIPACKPHY_AC_REV_REG_1_ADDR(base) ((base) + (0x11CUL))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_1_ADDR(base) ((base) + (0x120UL))
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_ADDR(base) ((base) + (0x124UL))
#define SOC_HIPACKPHY_AC_REV_REG_2_ADDR(base) ((base) + (0x128UL))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_2_ADDR(base) ((base) + (0x12CUL))
#else
#define SOC_HIPACKPHY_ACCTRL_TRX0_ADDR(base) ((base) + (0x000))
#define SOC_HIPACKPHY_ACCTRL_TRX1_ADDR(base) ((base) + (0x004))
#define SOC_HIPACKPHY_ACCTL_BYPASS_ADDR(base) ((base) + (0x008))
#define SOC_HIPACKPHY_AC_IECTRL0_ADDR(base) ((base) + (0x00C))
#define SOC_HIPACKPHY_AC_IECTRL1_ADDR(base) ((base) + (0x010))
#define SOC_HIPACKPHY_AC_RX_SET_ADDR(base) ((base) + (0x014))
#define SOC_HIPACKPHY_AC_RX_SET1_ADDR(base) ((base) + (0x018))
#define SOC_HIPACKPHY_AC_IOMODE_ADDR(base) ((base) + (0x01C))
#define SOC_HIPACKPHY_AC_IOREFCTRL0_ADDR(base) ((base) + (0x020))
#define SOC_HIPACKPHY_AC_IOREFCTRL1_ADDR(base) ((base) + (0x024))
#define SOC_HIPACKPHY_AC_IOREFCTRL2_ADDR(base) ((base) + (0x028))
#define SOC_HIPACKPHY_AC_IOEQCTRL0_ADDR(base) ((base) + (0x02C))
#define SOC_HIPACKPHY_AC_IOEQCTRL1_ADDR(base) ((base) + (0x030))
#define SOC_HIPACKPHY_AC_IOEQCTRL2_ADDR(base) ((base) + (0x034))
#define SOC_HIPACKPHY_AC_IOEQCTRL3_ADDR(base) ((base) + (0x038))
#define SOC_HIPACKPHY_AC_PECTRL0_ADDR(base) ((base) + (0x03C))
#define SOC_HIPACKPHY_AC_PECTRL1_ADDR(base) ((base) + (0x040))
#define SOC_HIPACKPHY_AC_PUPDCTRL_ADDR(base) ((base) + (0x044))
#define SOC_HIPACKPHY_AC_RONCTRL0_ADDR(base) ((base) + (0x048))
#define SOC_HIPACKPHY_AC_RONCTRL1_ADDR(base) ((base) + (0x04C))
#define SOC_HIPACKPHY_AC_ODTCTRL0_ADDR(base) ((base) + (0x050))
#define SOC_HIPACKPHY_AC_ODTCTRL1_ADDR(base) ((base) + (0x054))
#define SOC_HIPACKPHY_AC_ODTCTRL2_ADDR(base) ((base) + (0x058))
#define SOC_HIPACKPHY_AC_ODTCTRL3_ADDR(base) ((base) + (0x05C))
#define SOC_HIPACKPHY_AC_TESTCTRL0_ADDR(base) ((base) + (0x060))
#define SOC_HIPACKPHY_AC_TESTCTRL1_ADDR(base) ((base) + (0x064))
#define SOC_HIPACKPHY_AC_TESTCTRL2_ADDR(base) ((base) + (0x068))
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_ADDR(base) ((base) + (0x06C))
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_ADDR(base) ((base) + (0x070))
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_ADDR(base) ((base) + (0x074))
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_ADDR(base) ((base) + (0x078))
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_ADDR(base) ((base) + (0x07C))
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_ADDR(base) ((base) + (0x080))
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_ADDR(base) ((base) + (0x084))
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_ADDR(base) ((base) + (0x088))
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_ADDR(base) ((base) + (0x08C))
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_ADDR(base) ((base) + (0x090))
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_ADDR(base) ((base) + (0x094))
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_ADDR(base) ((base) + (0x098))
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_ADDR(base) ((base) + (0x09C))
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_ADDR(base) ((base) + (0x0A0))
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_ADDR(base) ((base) + (0x0A4))
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_ADDR(base) ((base) + (0x0A8))
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_ADDR(base) ((base) + (0x0AC))
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_ADDR(base) ((base) + (0x0B0))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_ADDR(base) ((base) + (0x0B4))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_ADDR(base) ((base) + (0x0B8))
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_ADDR(base) ((base) + (0x0BC))
#define SOC_HIPACKPHY_AC_DLL_CODE_ADDR(base) ((base) + (0x0C0))
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_ADDR(base) ((base) + (0x0C4))
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_ADDR(base) ((base) + (0x0C8))
#define SOC_HIPACKPHY_AC_BDL_CTRL0_ADDR(base) ((base) + (0x0CC))
#define SOC_HIPACKPHY_AC_BDL_CTRL1_ADDR(base) ((base) + (0x0D0))
#define SOC_HIPACKPHY_AC_BDL_CTRL2_ADDR(base) ((base) + (0x0D4))
#define SOC_HIPACKPHY_AC_BDL_CTRL3_ADDR(base) ((base) + (0x0D8))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_ADDR(base) ((base) + (0x0DC))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_ADDR(base) ((base) + (0x0E0))
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_ADDR(base) ((base) + (0x0E4))
#define SOC_HIPACKPHY_AC_IOEQCTRL4_ADDR(base) ((base) + (0x0E8))
#define SOC_HIPACKPHY_AC_IOEQCTRL5_ADDR(base) ((base) + (0x0EC))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_ADDR(base) ((base) + (0x0F0))
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_ADDR(base) ((base) + (0x0F4))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_ADDR(base) ((base) + (0x0F8))
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_ADDR(base) ((base) + (0x0FC))
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_ADDR(base) ((base) + (0x100))
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_ADDR(base) ((base) + (0x104))
#define SOC_HIPACKPHY_AC_PLL_DBG_A_ADDR(base) ((base) + (0x108))
#define SOC_HIPACKPHY_AC_PLL_DBG_B_ADDR(base) ((base) + (0x10C))
#define SOC_HIPACKPHY_AC_CTRL_1_ADDR(base) ((base) + (0x110))
#define SOC_HIPACKPHY_AC_REV_REG_0_ADDR(base) ((base) + (0x114))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_0_ADDR(base) ((base) + (0x118))
#define SOC_HIPACKPHY_AC_REV_REG_1_ADDR(base) ((base) + (0x11C))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_1_ADDR(base) ((base) + (0x120))
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_ADDR(base) ((base) + (0x124))
#define SOC_HIPACKPHY_AC_REV_REG_2_ADDR(base) ((base) + (0x128))
#define SOC_HIPACKPHY_AC_REV_REG_OUT_2_ADDR(base) ((base) + (0x12C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACKPHY_DXCTRL_TRX0_ADDR(base) ((base) + (0x200UL))
#define SOC_HIPACKPHY_DXCTRL_TRX1_ADDR(base,n) ((base) + (0x204+(n)*0x100UL))
#define SOC_HIPACKPHY_DXCTL_BYPASS_ADDR(base,n) ((base) + (0x208+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IECTRL0_ADDR(base,n) ((base) + (0x20C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RX_SET_ADDR(base,n) ((base) + (0x210+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOMODE_ADDR(base,n) ((base) + (0x214+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOREFCTRL0_ADDR(base,n) ((base) + (0x218+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOREFCTRL1_ADDR(base,n) ((base) + (0x21C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOREFCTRL2_ADDR(base,n) ((base) + (0x220+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOEQCTRL0_ADDR(base,n) ((base) + (0x224+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOEQCTRL1_ADDR(base,n) ((base) + (0x228+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOEQCTRL2_ADDR(base,n) ((base) + (0x22c+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOEQCTRL3_ADDR(base,n) ((base) + (0x230+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_PECTRL0_ADDR(base,n) ((base) + (0x234+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_PECTRL1_ADDR(base,n) ((base) + (0x238+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RONCTRL0_ADDR(base,n) ((base) + (0x23C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RONCTRL1_ADDR(base,n) ((base) + (0x240+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_ODTCTRL1_ADDR(base,n) ((base) + (0x244+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_ODTCTRL2_ADDR(base,n) ((base) + (0x248+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TESTCTRL0_ADDR(base,n) ((base) + (0x24C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TESTCTRL1_ADDR(base,n) ((base) + (0x250+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TESTCTRL2_ADDR(base,n) ((base) + (0x254+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_IOEQCTRL4_ADDR(base,n) ((base) + (0x258+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + (0x25C+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + (0x260+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + (0x264+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + (0x268+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + (0x26C+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + (0x270+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + (0x274+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + (0x278+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + (0x27C+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + (0x280+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + (0x284+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + (0x288+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + (0x28C+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + (0x290+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + (0x294+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + (0x298+(m)*0x40+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_ADDR(base,n) ((base) + (0x2DC+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_ADDR(base,n) ((base) + (0x2E0+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_ADDR(base,n) ((base) + (0x2E4+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_TRACK_ERR_ADDR(base,m,n) ((base) + (0x2E8+(m)*0x4+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_ADDR(base,m,n) ((base) + (0x2F0+(m)*0x8+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_ADDR(base,m,n) ((base) + (0x2F4+(m)*0x8+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_ADDR(base,n) ((base) + (0x400+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_OEBDL_CTL1_ADDR(base,n) ((base) + (0x404+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_DQS_DCC_ADDR(base,n) ((base) + (0x408+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_ADDR(base,n) ((base) + (0x40C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_GATE_ERR_ADDR(base,n) ((base) + (0x410+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_ADDR(base,n) ((base) + (0x414+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_ADDR(base,n) ((base) + (0x418+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_ADDR(base,n) ((base) + (0x41C+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_ADDR(base,n) ((base) + (0x420+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_ADDR(base,n) ((base) + (0x424+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_ADDR(base,n) ((base) + (0x428+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_ADDR(base,m,n) ((base) + (0x430+(m)*0x8+(n)*0x100UL))
#define SOC_HIPACKPHY_DX_DM_MARGIN_EXT_ADDR(base,m,n) ((base) + (0x434+(m)*0x8+(n)*0x100UL))
#else
#define SOC_HIPACKPHY_DXCTRL_TRX0_ADDR(base) ((base) + (0x200))
#define SOC_HIPACKPHY_DXCTRL_TRX1_ADDR(base,n) ((base) + (0x204+(n)*0x100))
#define SOC_HIPACKPHY_DXCTL_BYPASS_ADDR(base,n) ((base) + (0x208+(n)*0x100))
#define SOC_HIPACKPHY_DX_IECTRL0_ADDR(base,n) ((base) + (0x20C+(n)*0x100))
#define SOC_HIPACKPHY_DX_RX_SET_ADDR(base,n) ((base) + (0x210+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOMODE_ADDR(base,n) ((base) + (0x214+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOREFCTRL0_ADDR(base,n) ((base) + (0x218+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOREFCTRL1_ADDR(base,n) ((base) + (0x21C+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOREFCTRL2_ADDR(base,n) ((base) + (0x220+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOEQCTRL0_ADDR(base,n) ((base) + (0x224+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOEQCTRL1_ADDR(base,n) ((base) + (0x228+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOEQCTRL2_ADDR(base,n) ((base) + (0x22c+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOEQCTRL3_ADDR(base,n) ((base) + (0x230+(n)*0x100))
#define SOC_HIPACKPHY_DX_PECTRL0_ADDR(base,n) ((base) + (0x234+(n)*0x100))
#define SOC_HIPACKPHY_DX_PECTRL1_ADDR(base,n) ((base) + (0x238+(n)*0x100))
#define SOC_HIPACKPHY_DX_RONCTRL0_ADDR(base,n) ((base) + (0x23C+(n)*0x100))
#define SOC_HIPACKPHY_DX_RONCTRL1_ADDR(base,n) ((base) + (0x240+(n)*0x100))
#define SOC_HIPACKPHY_DX_ODTCTRL1_ADDR(base,n) ((base) + (0x244+(n)*0x100))
#define SOC_HIPACKPHY_DX_ODTCTRL2_ADDR(base,n) ((base) + (0x248+(n)*0x100))
#define SOC_HIPACKPHY_DX_TESTCTRL0_ADDR(base,n) ((base) + (0x24C+(n)*0x100))
#define SOC_HIPACKPHY_DX_TESTCTRL1_ADDR(base,n) ((base) + (0x250+(n)*0x100))
#define SOC_HIPACKPHY_DX_TESTCTRL2_ADDR(base,n) ((base) + (0x254+(n)*0x100))
#define SOC_HIPACKPHY_DX_IOEQCTRL4_ADDR(base,n) ((base) + (0x258+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + (0x25C+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + (0x260+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + (0x264+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + (0x268+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + (0x26C+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + (0x270+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + (0x274+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + (0x278+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_ADDR(base,m,n) ((base) + (0x27C+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_ADDR(base,m,n) ((base) + (0x280+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_ADDR(base,m,n) ((base) + (0x284+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_ADDR(base,m,n) ((base) + (0x288+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_ADDR(base,m,n) ((base) + (0x28C+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_ADDR(base,m,n) ((base) + (0x290+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_ADDR(base,m,n) ((base) + (0x294+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_ADDR(base,m,n) ((base) + (0x298+(m)*0x40+(n)*0x100))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_ADDR(base,n) ((base) + (0x2DC+(n)*0x100))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_ADDR(base,n) ((base) + (0x2E0+(n)*0x100))
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_ADDR(base,n) ((base) + (0x2E4+(n)*0x100))
#define SOC_HIPACKPHY_DX_TRACK_ERR_ADDR(base,m,n) ((base) + (0x2E8+(m)*0x4+(n)*0x100))
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_ADDR(base,m,n) ((base) + (0x2F0+(m)*0x8+(n)*0x100))
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_ADDR(base,m,n) ((base) + (0x2F4+(m)*0x8+(n)*0x100))
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_ADDR(base,n) ((base) + (0x400+(n)*0x100))
#define SOC_HIPACKPHY_DX_OEBDL_CTL1_ADDR(base,n) ((base) + (0x404+(n)*0x100))
#define SOC_HIPACKPHY_DX_DQS_DCC_ADDR(base,n) ((base) + (0x408+(n)*0x100))
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_ADDR(base,n) ((base) + (0x40C+(n)*0x100))
#define SOC_HIPACKPHY_DX_GATE_ERR_ADDR(base,n) ((base) + (0x410+(n)*0x100))
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_ADDR(base,n) ((base) + (0x414+(n)*0x100))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_ADDR(base,n) ((base) + (0x418+(n)*0x100))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_ADDR(base,n) ((base) + (0x41C+(n)*0x100))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_ADDR(base,n) ((base) + (0x420+(n)*0x100))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_ADDR(base,n) ((base) + (0x424+(n)*0x100))
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_ADDR(base,n) ((base) + (0x428+(n)*0x100))
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_ADDR(base,m,n) ((base) + (0x430+(m)*0x8+(n)*0x100))
#define SOC_HIPACKPHY_DX_DM_MARGIN_EXT_ADDR(base,m,n) ((base) + (0x434+(m)*0x8+(n)*0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int minor : 8;
        unsigned int major : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_REVISION_UNION;
#endif
#define SOC_HIPACKPHY_REVISION_minor_START (0)
#define SOC_HIPACKPHY_REVISION_minor_END (7)
#define SOC_HIPACKPHY_REVISION_major_START (8)
#define SOC_HIPACKPHY_REVISION_major_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int init_en : 1;
        unsigned int pll_init_en : 1;
        unsigned int dlymeas_en : 1;
        unsigned int zcal_en : 1;
        unsigned int wl_en : 1;
        unsigned int gt_en : 1;
        unsigned int gdst_en : 1;
        unsigned int wl2_en : 1;
        unsigned int rdet_en : 1;
        unsigned int wdet_en : 1;
        unsigned int dram_init_en : 1;
        unsigned int cat_en : 1;
        unsigned int dram_rst : 1;
        unsigned int phy_rst : 1;
        unsigned int pack_rst : 1;
        unsigned int phyconn_rst : 1;
        unsigned int dvreft_en : 1;
        unsigned int hvreft_en : 1;
        unsigned int dxdvrefs_en : 1;
        unsigned int acdvreft_en : 1;
        unsigned int achvreft_en : 1;
        unsigned int acdvrefs_en : 1;
        unsigned int cst_en : 1;
        unsigned int jtmt_en : 1;
        unsigned int pic_refret_rd : 1;
        unsigned int pic_refret_wr : 1;
        unsigned int pic_refret_sft : 1;
        unsigned int sw_q_rst : 1;
        unsigned int reserved : 2;
        unsigned int pic_phyupd_req : 1;
        unsigned int ctl_cke_bypass : 1;
    } reg;
} SOC_HIPACKPHY_PHYINITCTRL_UNION;
#endif
#define SOC_HIPACKPHY_PHYINITCTRL_init_en_START (0)
#define SOC_HIPACKPHY_PHYINITCTRL_init_en_END (0)
#define SOC_HIPACKPHY_PHYINITCTRL_pll_init_en_START (1)
#define SOC_HIPACKPHY_PHYINITCTRL_pll_init_en_END (1)
#define SOC_HIPACKPHY_PHYINITCTRL_dlymeas_en_START (2)
#define SOC_HIPACKPHY_PHYINITCTRL_dlymeas_en_END (2)
#define SOC_HIPACKPHY_PHYINITCTRL_zcal_en_START (3)
#define SOC_HIPACKPHY_PHYINITCTRL_zcal_en_END (3)
#define SOC_HIPACKPHY_PHYINITCTRL_wl_en_START (4)
#define SOC_HIPACKPHY_PHYINITCTRL_wl_en_END (4)
#define SOC_HIPACKPHY_PHYINITCTRL_gt_en_START (5)
#define SOC_HIPACKPHY_PHYINITCTRL_gt_en_END (5)
#define SOC_HIPACKPHY_PHYINITCTRL_gdst_en_START (6)
#define SOC_HIPACKPHY_PHYINITCTRL_gdst_en_END (6)
#define SOC_HIPACKPHY_PHYINITCTRL_wl2_en_START (7)
#define SOC_HIPACKPHY_PHYINITCTRL_wl2_en_END (7)
#define SOC_HIPACKPHY_PHYINITCTRL_rdet_en_START (8)
#define SOC_HIPACKPHY_PHYINITCTRL_rdet_en_END (8)
#define SOC_HIPACKPHY_PHYINITCTRL_wdet_en_START (9)
#define SOC_HIPACKPHY_PHYINITCTRL_wdet_en_END (9)
#define SOC_HIPACKPHY_PHYINITCTRL_dram_init_en_START (10)
#define SOC_HIPACKPHY_PHYINITCTRL_dram_init_en_END (10)
#define SOC_HIPACKPHY_PHYINITCTRL_cat_en_START (11)
#define SOC_HIPACKPHY_PHYINITCTRL_cat_en_END (11)
#define SOC_HIPACKPHY_PHYINITCTRL_dram_rst_START (12)
#define SOC_HIPACKPHY_PHYINITCTRL_dram_rst_END (12)
#define SOC_HIPACKPHY_PHYINITCTRL_phy_rst_START (13)
#define SOC_HIPACKPHY_PHYINITCTRL_phy_rst_END (13)
#define SOC_HIPACKPHY_PHYINITCTRL_pack_rst_START (14)
#define SOC_HIPACKPHY_PHYINITCTRL_pack_rst_END (14)
#define SOC_HIPACKPHY_PHYINITCTRL_phyconn_rst_START (15)
#define SOC_HIPACKPHY_PHYINITCTRL_phyconn_rst_END (15)
#define SOC_HIPACKPHY_PHYINITCTRL_dvreft_en_START (16)
#define SOC_HIPACKPHY_PHYINITCTRL_dvreft_en_END (16)
#define SOC_HIPACKPHY_PHYINITCTRL_hvreft_en_START (17)
#define SOC_HIPACKPHY_PHYINITCTRL_hvreft_en_END (17)
#define SOC_HIPACKPHY_PHYINITCTRL_dxdvrefs_en_START (18)
#define SOC_HIPACKPHY_PHYINITCTRL_dxdvrefs_en_END (18)
#define SOC_HIPACKPHY_PHYINITCTRL_acdvreft_en_START (19)
#define SOC_HIPACKPHY_PHYINITCTRL_acdvreft_en_END (19)
#define SOC_HIPACKPHY_PHYINITCTRL_achvreft_en_START (20)
#define SOC_HIPACKPHY_PHYINITCTRL_achvreft_en_END (20)
#define SOC_HIPACKPHY_PHYINITCTRL_acdvrefs_en_START (21)
#define SOC_HIPACKPHY_PHYINITCTRL_acdvrefs_en_END (21)
#define SOC_HIPACKPHY_PHYINITCTRL_cst_en_START (22)
#define SOC_HIPACKPHY_PHYINITCTRL_cst_en_END (22)
#define SOC_HIPACKPHY_PHYINITCTRL_jtmt_en_START (23)
#define SOC_HIPACKPHY_PHYINITCTRL_jtmt_en_END (23)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_rd_START (24)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_rd_END (24)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_wr_START (25)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_wr_END (25)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_sft_START (26)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_refret_sft_END (26)
#define SOC_HIPACKPHY_PHYINITCTRL_sw_q_rst_START (27)
#define SOC_HIPACKPHY_PHYINITCTRL_sw_q_rst_END (27)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_phyupd_req_START (30)
#define SOC_HIPACKPHY_PHYINITCTRL_pic_phyupd_req_END (30)
#define SOC_HIPACKPHY_PHYINITCTRL_ctl_cke_bypass_START (31)
#define SOC_HIPACKPHY_PHYINITCTRL_ctl_cke_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wl2wdet_err : 1;
        unsigned int pll_lock_err : 1;
        unsigned int dlymeas_err : 1;
        unsigned int zcal_err : 1;
        unsigned int wl_err : 1;
        unsigned int gt_err : 1;
        unsigned int gdst_err : 1;
        unsigned int wl2_err : 1;
        unsigned int rdet_err : 1;
        unsigned int wdet_err : 1;
        unsigned int cat_err : 1;
        unsigned int fst_rdet_wrg : 1;
        unsigned int fst_rdet_err : 1;
        unsigned int wdert_wrg : 1;
        unsigned int wdert_err : 1;
        unsigned int reserved_0 : 7;
        unsigned int cst_err : 1;
        unsigned int reserved_1 : 5;
        unsigned int zcal_idle : 1;
        unsigned int dfi_phyupd_ack : 1;
        unsigned int dfi_phyupd_req : 1;
        unsigned int retrain_active : 1;
    } reg;
} SOC_HIPACKPHY_PHYINITSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_PHYINITSTATUS_wl2wdet_err_START (0)
#define SOC_HIPACKPHY_PHYINITSTATUS_wl2wdet_err_END (0)
#define SOC_HIPACKPHY_PHYINITSTATUS_pll_lock_err_START (1)
#define SOC_HIPACKPHY_PHYINITSTATUS_pll_lock_err_END (1)
#define SOC_HIPACKPHY_PHYINITSTATUS_dlymeas_err_START (2)
#define SOC_HIPACKPHY_PHYINITSTATUS_dlymeas_err_END (2)
#define SOC_HIPACKPHY_PHYINITSTATUS_zcal_err_START (3)
#define SOC_HIPACKPHY_PHYINITSTATUS_zcal_err_END (3)
#define SOC_HIPACKPHY_PHYINITSTATUS_wl_err_START (4)
#define SOC_HIPACKPHY_PHYINITSTATUS_wl_err_END (4)
#define SOC_HIPACKPHY_PHYINITSTATUS_gt_err_START (5)
#define SOC_HIPACKPHY_PHYINITSTATUS_gt_err_END (5)
#define SOC_HIPACKPHY_PHYINITSTATUS_gdst_err_START (6)
#define SOC_HIPACKPHY_PHYINITSTATUS_gdst_err_END (6)
#define SOC_HIPACKPHY_PHYINITSTATUS_wl2_err_START (7)
#define SOC_HIPACKPHY_PHYINITSTATUS_wl2_err_END (7)
#define SOC_HIPACKPHY_PHYINITSTATUS_rdet_err_START (8)
#define SOC_HIPACKPHY_PHYINITSTATUS_rdet_err_END (8)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdet_err_START (9)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdet_err_END (9)
#define SOC_HIPACKPHY_PHYINITSTATUS_cat_err_START (10)
#define SOC_HIPACKPHY_PHYINITSTATUS_cat_err_END (10)
#define SOC_HIPACKPHY_PHYINITSTATUS_fst_rdet_wrg_START (11)
#define SOC_HIPACKPHY_PHYINITSTATUS_fst_rdet_wrg_END (11)
#define SOC_HIPACKPHY_PHYINITSTATUS_fst_rdet_err_START (12)
#define SOC_HIPACKPHY_PHYINITSTATUS_fst_rdet_err_END (12)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdert_wrg_START (13)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdert_wrg_END (13)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdert_err_START (14)
#define SOC_HIPACKPHY_PHYINITSTATUS_wdert_err_END (14)
#define SOC_HIPACKPHY_PHYINITSTATUS_cst_err_START (22)
#define SOC_HIPACKPHY_PHYINITSTATUS_cst_err_END (22)
#define SOC_HIPACKPHY_PHYINITSTATUS_zcal_idle_START (28)
#define SOC_HIPACKPHY_PHYINITSTATUS_zcal_idle_END (28)
#define SOC_HIPACKPHY_PHYINITSTATUS_dfi_phyupd_ack_START (29)
#define SOC_HIPACKPHY_PHYINITSTATUS_dfi_phyupd_ack_END (29)
#define SOC_HIPACKPHY_PHYINITSTATUS_dfi_phyupd_req_START (30)
#define SOC_HIPACKPHY_PHYINITSTATUS_dfi_phyupd_req_END (30)
#define SOC_HIPACKPHY_PHYINITSTATUS_retrain_active_START (31)
#define SOC_HIPACKPHY_PHYINITSTATUS_retrain_active_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dx_phy_clkgated : 4;
        unsigned int reserved_0 : 4;
        unsigned int ac_phy_clkgated : 1;
        unsigned int ck_phy_clkgated : 4;
        unsigned int dx_phgated_en : 1;
        unsigned int dx_phclkgated : 1;
        unsigned int dx_phgated_men : 1;
        unsigned int cfg_tx_gcnt : 8;
        unsigned int cfg_ca_gcnt : 4;
        unsigned int reserved_1 : 1;
        unsigned int cfg_dlymeas_gated : 1;
        unsigned int cfg_gcken_ca_rs : 1;
        unsigned int byp_pll_lock : 1;
    } reg;
} SOC_HIPACKPHY_PHYCLKGATED_UNION;
#endif
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phy_clkgated_START (0)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phy_clkgated_END (3)
#define SOC_HIPACKPHY_PHYCLKGATED_ac_phy_clkgated_START (8)
#define SOC_HIPACKPHY_PHYCLKGATED_ac_phy_clkgated_END (8)
#define SOC_HIPACKPHY_PHYCLKGATED_ck_phy_clkgated_START (9)
#define SOC_HIPACKPHY_PHYCLKGATED_ck_phy_clkgated_END (12)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phgated_en_START (13)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phgated_en_END (13)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phclkgated_START (14)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phclkgated_END (14)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phgated_men_START (15)
#define SOC_HIPACKPHY_PHYCLKGATED_dx_phgated_men_END (15)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_tx_gcnt_START (16)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_tx_gcnt_END (23)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_ca_gcnt_START (24)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_ca_gcnt_END (27)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_dlymeas_gated_START (29)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_dlymeas_gated_END (29)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_gcken_ca_rs_START (30)
#define SOC_HIPACKPHY_PHYCLKGATED_cfg_gcken_ca_rs_END (30)
#define SOC_HIPACKPHY_PHYCLKGATED_byp_pll_lock_START (31)
#define SOC_HIPACKPHY_PHYCLKGATED_byp_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_dram_reset : 8;
        unsigned int reserved : 4;
        unsigned int t_dram_cke_high : 20;
    } reg;
} SOC_HIPACKPHY_PHYTIMER0_UNION;
#endif
#define SOC_HIPACKPHY_PHYTIMER0_t_dram_reset_START (0)
#define SOC_HIPACKPHY_PHYTIMER0_t_dram_reset_END (7)
#define SOC_HIPACKPHY_PHYTIMER0_t_dram_cke_high_START (12)
#define SOC_HIPACKPHY_PHYTIMER0_t_dram_cke_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_dram_cke_low : 20;
        unsigned int reserved : 8;
        unsigned int tckelck : 4;
    } reg;
} SOC_HIPACKPHY_PHYTIMER1_UNION;
#endif
#define SOC_HIPACKPHY_PHYTIMER1_t_dram_cke_low_START (0)
#define SOC_HIPACKPHY_PHYTIMER1_t_dram_cke_low_END (19)
#define SOC_HIPACKPHY_PHYTIMER1_tckelck_START (28)
#define SOC_HIPACKPHY_PHYTIMER1_tckelck_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_pwdn : 3;
        unsigned int reserved_0 : 13;
        unsigned int lv3_pllpd_deassert_time : 4;
        unsigned int reserved_1 : 4;
        unsigned int dx_pll_powerdown_23 : 2;
        unsigned int reserved_2 : 2;
        unsigned int dx_pll_powerdown_47 : 4;
    } reg;
} SOC_HIPACKPHY_PLLCTRL_UNION;
#endif
#define SOC_HIPACKPHY_PLLCTRL_pll_pwdn_START (0)
#define SOC_HIPACKPHY_PLLCTRL_pll_pwdn_END (2)
#define SOC_HIPACKPHY_PLLCTRL_lv3_pllpd_deassert_time_START (16)
#define SOC_HIPACKPHY_PLLCTRL_lv3_pllpd_deassert_time_END (19)
#define SOC_HIPACKPHY_PLLCTRL_dx_pll_powerdown_23_START (24)
#define SOC_HIPACKPHY_PLLCTRL_dx_pll_powerdown_23_END (25)
#define SOC_HIPACKPHY_PLLCTRL_dx_pll_powerdown_47_START (28)
#define SOC_HIPACKPHY_PLLCTRL_dx_pll_powerdown_47_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_pll_rst : 8;
        unsigned int reserved : 8;
        unsigned int t_pll_lock : 16;
    } reg;
} SOC_HIPACKPHY_PLLTIMER_UNION;
#endif
#define SOC_HIPACKPHY_PLLTIMER_t_pll_rst_START (0)
#define SOC_HIPACKPHY_PLLTIMER_t_pll_rst_END (7)
#define SOC_HIPACKPHY_PLLTIMER_t_pll_lock_START (16)
#define SOC_HIPACKPHY_PLLTIMER_t_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dly_meas_type : 1;
        unsigned int dly_track_type : 1;
        unsigned int dlytrack_dqsgth : 2;
        unsigned int dynamic_dqsgen : 1;
        unsigned int dynamic_dqsen : 1;
        unsigned int dly_meas_type_2T : 2;
        unsigned int dly_track_limit : 7;
        unsigned int dynamic_dqsg_ph_only : 1;
        unsigned int dynamic_dqsg_ph_dis : 1;
        unsigned int dynamic_dqs_cyc_dis : 1;
        unsigned int dynamic_dqsbdl30_dis : 1;
        unsigned int cfg_dyn_track_upt_mode : 1;
        unsigned int dlytrack_dqsth : 2;
        unsigned int dlytrack_dqsg_tap : 2;
        unsigned int dlytrack_dqs_tap : 2;
        unsigned int dlytrack_cyc_tap : 4;
        unsigned int rdqsg_mondly_type : 2;
    } reg;
} SOC_HIPACKPHY_DLYMEASCTRL_UNION;
#endif
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_meas_type_START (0)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_meas_type_END (0)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_track_type_START (1)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_track_type_END (1)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsgth_START (2)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsgth_END (3)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsgen_START (4)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsgen_END (4)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsen_START (5)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsen_END (5)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_meas_type_2T_START (6)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_meas_type_2T_END (7)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_track_limit_START (8)
#define SOC_HIPACKPHY_DLYMEASCTRL_dly_track_limit_END (14)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsg_ph_only_START (15)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsg_ph_only_END (15)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsg_ph_dis_START (16)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsg_ph_dis_END (16)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqs_cyc_dis_START (17)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqs_cyc_dis_END (17)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsbdl30_dis_START (18)
#define SOC_HIPACKPHY_DLYMEASCTRL_dynamic_dqsbdl30_dis_END (18)
#define SOC_HIPACKPHY_DLYMEASCTRL_cfg_dyn_track_upt_mode_START (19)
#define SOC_HIPACKPHY_DLYMEASCTRL_cfg_dyn_track_upt_mode_END (19)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsth_START (20)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsth_END (21)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsg_tap_START (22)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqsg_tap_END (23)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqs_tap_START (24)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_dqs_tap_END (25)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_cyc_tap_START (26)
#define SOC_HIPACKPHY_DLYMEASCTRL_dlytrack_cyc_tap_END (29)
#define SOC_HIPACKPHY_DLYMEASCTRL_rdqsg_mondly_type_START (30)
#define SOC_HIPACKPHY_DLYMEASCTRL_rdqsg_mondly_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int zcomp_rsp_dly : 6;
        unsigned int tzcomp_upddly : 6;
        unsigned int zcomp_num : 4;
        unsigned int zcalrt_range : 8;
        unsigned int zcal_result_sel : 1;
        unsigned int zcal_nlatch_inv : 1;
        unsigned int zcal_platch_inv : 1;
        unsigned int zcal_pnsequence : 1;
        unsigned int zcal_errstopup : 1;
        unsigned int zcalrt_updckelh_dis : 1;
        unsigned int zcalrt_en : 1;
        unsigned int zcfuzzy_en : 1;
    } reg;
} SOC_HIPACKPHY_IMPCTRL_UNION;
#endif
#define SOC_HIPACKPHY_IMPCTRL_zcomp_rsp_dly_START (0)
#define SOC_HIPACKPHY_IMPCTRL_zcomp_rsp_dly_END (5)
#define SOC_HIPACKPHY_IMPCTRL_tzcomp_upddly_START (6)
#define SOC_HIPACKPHY_IMPCTRL_tzcomp_upddly_END (11)
#define SOC_HIPACKPHY_IMPCTRL_zcomp_num_START (12)
#define SOC_HIPACKPHY_IMPCTRL_zcomp_num_END (15)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_range_START (16)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_range_END (23)
#define SOC_HIPACKPHY_IMPCTRL_zcal_result_sel_START (24)
#define SOC_HIPACKPHY_IMPCTRL_zcal_result_sel_END (24)
#define SOC_HIPACKPHY_IMPCTRL_zcal_nlatch_inv_START (25)
#define SOC_HIPACKPHY_IMPCTRL_zcal_nlatch_inv_END (25)
#define SOC_HIPACKPHY_IMPCTRL_zcal_platch_inv_START (26)
#define SOC_HIPACKPHY_IMPCTRL_zcal_platch_inv_END (26)
#define SOC_HIPACKPHY_IMPCTRL_zcal_pnsequence_START (27)
#define SOC_HIPACKPHY_IMPCTRL_zcal_pnsequence_END (27)
#define SOC_HIPACKPHY_IMPCTRL_zcal_errstopup_START (28)
#define SOC_HIPACKPHY_IMPCTRL_zcal_errstopup_END (28)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_updckelh_dis_START (29)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_updckelh_dis_END (29)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_en_START (30)
#define SOC_HIPACKPHY_IMPCTRL_zcalrt_en_END (30)
#define SOC_HIPACKPHY_IMPCTRL_zcfuzzy_en_START (31)
#define SOC_HIPACKPHY_IMPCTRL_zcfuzzy_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int zcode_ndrv : 6;
        unsigned int swrt_ndrv_update : 1;
        unsigned int ndrv_cal_result : 1;
        unsigned int zcode_ndrv_cal : 7;
        unsigned int swrt_pdrv_update : 1;
        unsigned int zcode_pdrv : 7;
        unsigned int pdrv_cal_result : 1;
        unsigned int zcode_pdrv_cal : 8;
    } reg;
} SOC_HIPACKPHY_IMPSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_IMPSTATUS_zcode_ndrv_START (0)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_ndrv_END (5)
#define SOC_HIPACKPHY_IMPSTATUS_swrt_ndrv_update_START (6)
#define SOC_HIPACKPHY_IMPSTATUS_swrt_ndrv_update_END (6)
#define SOC_HIPACKPHY_IMPSTATUS_ndrv_cal_result_START (7)
#define SOC_HIPACKPHY_IMPSTATUS_ndrv_cal_result_END (7)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_ndrv_cal_START (8)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_ndrv_cal_END (14)
#define SOC_HIPACKPHY_IMPSTATUS_swrt_pdrv_update_START (15)
#define SOC_HIPACKPHY_IMPSTATUS_swrt_pdrv_update_END (15)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_pdrv_START (16)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_pdrv_END (22)
#define SOC_HIPACKPHY_IMPSTATUS_pdrv_cal_result_START (23)
#define SOC_HIPACKPHY_IMPSTATUS_pdrv_cal_result_END (23)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_pdrv_cal_START (24)
#define SOC_HIPACKPHY_IMPSTATUS_zcode_pdrv_cal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dram_type : 3;
        unsigned int dram_type_exd : 1;
        unsigned int nosra : 1;
        unsigned int ma2t : 1;
        unsigned int maddr_mir : 1;
        unsigned int lpddr23_mrw11_en : 1;
        unsigned int lpddr23_pre_en : 1;
        unsigned int lpddr23_mrw1617_en : 1;
        unsigned int lpddr23_zqc_en : 1;
        unsigned int lpddr23_mrw_rst_ca3t : 1;
        unsigned int lpddr23_early_cat_en : 1;
        unsigned int ddr4par_en : 1;
        unsigned int mrs_seq_prog_en : 1;
        unsigned int lpddr5_blen : 1;
        unsigned int cfg_tppd : 3;
        unsigned int reserved_0 : 5;
        unsigned int zqc_latch_only : 1;
        unsigned int reserved_1 : 1;
        unsigned int zqc_ranken : 2;
        unsigned int cfg_lp4_R17en : 2;
        unsigned int cfg_lp4_R18en : 2;
    } reg;
} SOC_HIPACKPHY_DRAMCFG_UNION;
#endif
#define SOC_HIPACKPHY_DRAMCFG_dram_type_START (0)
#define SOC_HIPACKPHY_DRAMCFG_dram_type_END (2)
#define SOC_HIPACKPHY_DRAMCFG_dram_type_exd_START (3)
#define SOC_HIPACKPHY_DRAMCFG_dram_type_exd_END (3)
#define SOC_HIPACKPHY_DRAMCFG_nosra_START (4)
#define SOC_HIPACKPHY_DRAMCFG_nosra_END (4)
#define SOC_HIPACKPHY_DRAMCFG_ma2t_START (5)
#define SOC_HIPACKPHY_DRAMCFG_ma2t_END (5)
#define SOC_HIPACKPHY_DRAMCFG_maddr_mir_START (6)
#define SOC_HIPACKPHY_DRAMCFG_maddr_mir_END (6)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw11_en_START (7)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw11_en_END (7)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_pre_en_START (8)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_pre_en_END (8)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw1617_en_START (9)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw1617_en_END (9)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_zqc_en_START (10)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_zqc_en_END (10)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw_rst_ca3t_START (11)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_mrw_rst_ca3t_END (11)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_early_cat_en_START (12)
#define SOC_HIPACKPHY_DRAMCFG_lpddr23_early_cat_en_END (12)
#define SOC_HIPACKPHY_DRAMCFG_ddr4par_en_START (13)
#define SOC_HIPACKPHY_DRAMCFG_ddr4par_en_END (13)
#define SOC_HIPACKPHY_DRAMCFG_mrs_seq_prog_en_START (14)
#define SOC_HIPACKPHY_DRAMCFG_mrs_seq_prog_en_END (14)
#define SOC_HIPACKPHY_DRAMCFG_lpddr5_blen_START (15)
#define SOC_HIPACKPHY_DRAMCFG_lpddr5_blen_END (15)
#define SOC_HIPACKPHY_DRAMCFG_cfg_tppd_START (16)
#define SOC_HIPACKPHY_DRAMCFG_cfg_tppd_END (18)
#define SOC_HIPACKPHY_DRAMCFG_zqc_latch_only_START (24)
#define SOC_HIPACKPHY_DRAMCFG_zqc_latch_only_END (24)
#define SOC_HIPACKPHY_DRAMCFG_zqc_ranken_START (26)
#define SOC_HIPACKPHY_DRAMCFG_zqc_ranken_END (27)
#define SOC_HIPACKPHY_DRAMCFG_cfg_lp4_R17en_START (28)
#define SOC_HIPACKPHY_DRAMCFG_cfg_lp4_R17en_END (29)
#define SOC_HIPACKPHY_DRAMCFG_cfg_lp4_R18en_START (30)
#define SOC_HIPACKPHY_DRAMCFG_cfg_lp4_R18en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_rtp : 4;
        unsigned int t_wtr : 4;
        unsigned int t_rp : 4;
        unsigned int t_rcd : 4;
        unsigned int t_ras : 6;
        unsigned int t_rrd : 4;
        unsigned int t_rc : 6;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER0_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER0_t_rtp_START (0)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rtp_END (3)
#define SOC_HIPACKPHY_DRAMTIMER0_t_wtr_START (4)
#define SOC_HIPACKPHY_DRAMTIMER0_t_wtr_END (7)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rp_START (8)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rp_END (11)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rcd_START (12)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rcd_END (15)
#define SOC_HIPACKPHY_DRAMTIMER0_t_ras_START (16)
#define SOC_HIPACKPHY_DRAMTIMER0_t_ras_END (21)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rrd_START (22)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rrd_END (25)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rc_START (26)
#define SOC_HIPACKPHY_DRAMTIMER0_t_rc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_mrd : 4;
        unsigned int t_mod : 5;
        unsigned int t_faw : 6;
        unsigned int reserved : 1;
        unsigned int t_rfc : 9;
        unsigned int t_rtw : 7;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER1_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER1_t_mrd_START (0)
#define SOC_HIPACKPHY_DRAMTIMER1_t_mrd_END (3)
#define SOC_HIPACKPHY_DRAMTIMER1_t_mod_START (4)
#define SOC_HIPACKPHY_DRAMTIMER1_t_mod_END (8)
#define SOC_HIPACKPHY_DRAMTIMER1_t_faw_START (9)
#define SOC_HIPACKPHY_DRAMTIMER1_t_faw_END (14)
#define SOC_HIPACKPHY_DRAMTIMER1_t_rfc_START (16)
#define SOC_HIPACKPHY_DRAMTIMER1_t_rfc_END (24)
#define SOC_HIPACKPHY_DRAMTIMER1_t_rtw_START (25)
#define SOC_HIPACKPHY_DRAMTIMER1_t_rtw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_xs : 10;
        unsigned int t_xp : 5;
        unsigned int reserved_0: 1;
        unsigned int t_cke : 4;
        unsigned int t_dllk : 10;
        unsigned int reserved_1: 1;
        unsigned int t_ccd : 1;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER2_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER2_t_xs_START (0)
#define SOC_HIPACKPHY_DRAMTIMER2_t_xs_END (9)
#define SOC_HIPACKPHY_DRAMTIMER2_t_xp_START (10)
#define SOC_HIPACKPHY_DRAMTIMER2_t_xp_END (14)
#define SOC_HIPACKPHY_DRAMTIMER2_t_cke_START (16)
#define SOC_HIPACKPHY_DRAMTIMER2_t_cke_END (19)
#define SOC_HIPACKPHY_DRAMTIMER2_t_dllk_START (20)
#define SOC_HIPACKPHY_DRAMTIMER2_t_dllk_END (29)
#define SOC_HIPACKPHY_DRAMTIMER2_t_ccd_START (31)
#define SOC_HIPACKPHY_DRAMTIMER2_t_ccd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_zcal : 10;
        unsigned int t_init5 : 14;
        unsigned int tdshtrain : 4;
        unsigned int t_wr : 4;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER3_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER3_t_zcal_START (0)
#define SOC_HIPACKPHY_DRAMTIMER3_t_zcal_END (9)
#define SOC_HIPACKPHY_DRAMTIMER3_t_init5_START (10)
#define SOC_HIPACKPHY_DRAMTIMER3_t_init5_END (23)
#define SOC_HIPACKPHY_DRAMTIMER3_tdshtrain_START (24)
#define SOC_HIPACKPHY_DRAMTIMER3_tdshtrain_END (27)
#define SOC_HIPACKPHY_DRAMTIMER3_t_wr_START (28)
#define SOC_HIPACKPHY_DRAMTIMER3_t_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_wlmrd : 6;
        unsigned int t_wr_ext : 1;
        unsigned int t_wlo : 5;
        unsigned int t_odt : 4;
        unsigned int t_ccd_s : 4;
        unsigned int t_vref : 3;
        unsigned int reserved : 1;
        unsigned int t_odton : 4;
        unsigned int t_ccd_ddr4 : 4;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER4_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER4_t_wlmrd_START (0)
#define SOC_HIPACKPHY_DRAMTIMER4_t_wlmrd_END (5)
#define SOC_HIPACKPHY_DRAMTIMER4_t_wr_ext_START (6)
#define SOC_HIPACKPHY_DRAMTIMER4_t_wr_ext_END (6)
#define SOC_HIPACKPHY_DRAMTIMER4_t_wlo_START (7)
#define SOC_HIPACKPHY_DRAMTIMER4_t_wlo_END (11)
#define SOC_HIPACKPHY_DRAMTIMER4_t_odt_START (12)
#define SOC_HIPACKPHY_DRAMTIMER4_t_odt_END (15)
#define SOC_HIPACKPHY_DRAMTIMER4_t_ccd_s_START (16)
#define SOC_HIPACKPHY_DRAMTIMER4_t_ccd_s_END (19)
#define SOC_HIPACKPHY_DRAMTIMER4_t_vref_START (20)
#define SOC_HIPACKPHY_DRAMTIMER4_t_vref_END (22)
#define SOC_HIPACKPHY_DRAMTIMER4_t_odton_START (24)
#define SOC_HIPACKPHY_DRAMTIMER4_t_odton_END (27)
#define SOC_HIPACKPHY_DRAMTIMER4_t_ccd_ddr4_START (28)
#define SOC_HIPACKPHY_DRAMTIMER4_t_ccd_ddr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wodt_rank0 : 4;
        unsigned int wodt_rank1 : 4;
        unsigned int wodt_rank2 : 4;
        unsigned int wodt_rank3 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_ODTCR_UNION;
#endif
#define SOC_HIPACKPHY_ODTCR_wodt_rank0_START (0)
#define SOC_HIPACKPHY_ODTCR_wodt_rank0_END (3)
#define SOC_HIPACKPHY_ODTCR_wodt_rank1_START (4)
#define SOC_HIPACKPHY_ODTCR_wodt_rank1_END (7)
#define SOC_HIPACKPHY_ODTCR_wodt_rank2_START (8)
#define SOC_HIPACKPHY_ODTCR_wodt_rank2_END (11)
#define SOC_HIPACKPHY_ODTCR_wodt_rank3_START (12)
#define SOC_HIPACKPHY_ODTCR_wodt_rank3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtr_rank : 4;
        unsigned int dqsgsl_mrgn : 8;
        unsigned int busy_en_cnt : 4;
        unsigned int wl_ph_delta : 6;
        unsigned int gtfback_en : 1;
        unsigned int gdsrten : 1;
        unsigned int gtdsdly : 6;
        unsigned int dtrerrstop : 1;
        unsigned int detskipeyop : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL0_dtr_rank_START (0)
#define SOC_HIPACKPHY_TRAINCTRL0_dtr_rank_END (3)
#define SOC_HIPACKPHY_TRAINCTRL0_dqsgsl_mrgn_START (4)
#define SOC_HIPACKPHY_TRAINCTRL0_dqsgsl_mrgn_END (11)
#define SOC_HIPACKPHY_TRAINCTRL0_busy_en_cnt_START (12)
#define SOC_HIPACKPHY_TRAINCTRL0_busy_en_cnt_END (15)
#define SOC_HIPACKPHY_TRAINCTRL0_wl_ph_delta_START (16)
#define SOC_HIPACKPHY_TRAINCTRL0_wl_ph_delta_END (21)
#define SOC_HIPACKPHY_TRAINCTRL0_gtfback_en_START (22)
#define SOC_HIPACKPHY_TRAINCTRL0_gtfback_en_END (22)
#define SOC_HIPACKPHY_TRAINCTRL0_gdsrten_START (23)
#define SOC_HIPACKPHY_TRAINCTRL0_gdsrten_END (23)
#define SOC_HIPACKPHY_TRAINCTRL0_gtdsdly_START (24)
#define SOC_HIPACKPHY_TRAINCTRL0_gtdsdly_END (29)
#define SOC_HIPACKPHY_TRAINCTRL0_dtrerrstop_START (30)
#define SOC_HIPACKPHY_TRAINCTRL0_dtrerrstop_END (30)
#define SOC_HIPACKPHY_TRAINCTRL0_detskipeyop_START (31)
#define SOC_HIPACKPHY_TRAINCTRL0_detskipeyop_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rank_en : 16;
        unsigned int dtbank : 3;
        unsigned int reserved_0 : 1;
        unsigned int dtbankgrp : 3;
        unsigned int reserved_1 : 1;
        unsigned int dtbank_tg1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int dtbankgrp_tg1 : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_HIPACKPHY_RANKEN_UNION;
#endif
#define SOC_HIPACKPHY_RANKEN_rank_en_START (0)
#define SOC_HIPACKPHY_RANKEN_rank_en_END (15)
#define SOC_HIPACKPHY_RANKEN_dtbank_START (16)
#define SOC_HIPACKPHY_RANKEN_dtbank_END (18)
#define SOC_HIPACKPHY_RANKEN_dtbankgrp_START (20)
#define SOC_HIPACKPHY_RANKEN_dtbankgrp_END (22)
#define SOC_HIPACKPHY_RANKEN_dtbank_tg1_START (24)
#define SOC_HIPACKPHY_RANKEN_dtbank_tg1_END (26)
#define SOC_HIPACKPHY_RANKEN_dtbankgrp_tg1_START (28)
#define SOC_HIPACKPHY_RANKEN_dtbankgrp_tg1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtcol : 12;
        unsigned int dtrow : 20;
    } reg;
} SOC_HIPACKPHY_TRAINMADDR_UNION;
#endif
#define SOC_HIPACKPHY_TRAINMADDR_dtcol_START (0)
#define SOC_HIPACKPHY_TRAINMADDR_dtcol_END (11)
#define SOC_HIPACKPHY_TRAINMADDR_dtrow_START (12)
#define SOC_HIPACKPHY_TRAINMADDR_dtrow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_op : 2;
        unsigned int reserved_0 : 1;
        unsigned int dxlpbk_wlmode : 1;
        unsigned int bist_mode : 3;
        unsigned int reserved_1 : 1;
        unsigned int bist_pat : 3;
        unsigned int sso_bist_cnt : 3;
        unsigned int rnk_sw_op : 1;
        unsigned int dfi_phyupd_disable : 1;
        unsigned int bist_fail_stop : 8;
        unsigned int rnk_sw_mode : 1;
        unsigned int brst_cnt : 7;
    } reg;
} SOC_HIPACKPHY_BISTCTRL_UNION;
#endif
#define SOC_HIPACKPHY_BISTCTRL_bist_op_START (0)
#define SOC_HIPACKPHY_BISTCTRL_bist_op_END (1)
#define SOC_HIPACKPHY_BISTCTRL_dxlpbk_wlmode_START (3)
#define SOC_HIPACKPHY_BISTCTRL_dxlpbk_wlmode_END (3)
#define SOC_HIPACKPHY_BISTCTRL_bist_mode_START (4)
#define SOC_HIPACKPHY_BISTCTRL_bist_mode_END (6)
#define SOC_HIPACKPHY_BISTCTRL_bist_pat_START (8)
#define SOC_HIPACKPHY_BISTCTRL_bist_pat_END (10)
#define SOC_HIPACKPHY_BISTCTRL_sso_bist_cnt_START (11)
#define SOC_HIPACKPHY_BISTCTRL_sso_bist_cnt_END (13)
#define SOC_HIPACKPHY_BISTCTRL_rnk_sw_op_START (14)
#define SOC_HIPACKPHY_BISTCTRL_rnk_sw_op_END (14)
#define SOC_HIPACKPHY_BISTCTRL_dfi_phyupd_disable_START (15)
#define SOC_HIPACKPHY_BISTCTRL_dfi_phyupd_disable_END (15)
#define SOC_HIPACKPHY_BISTCTRL_bist_fail_stop_START (16)
#define SOC_HIPACKPHY_BISTCTRL_bist_fail_stop_END (23)
#define SOC_HIPACKPHY_BISTCTRL_rnk_sw_mode_START (24)
#define SOC_HIPACKPHY_BISTCTRL_rnk_sw_mode_END (24)
#define SOC_HIPACKPHY_BISTCTRL_brst_cnt_START (25)
#define SOC_HIPACKPHY_BISTCTRL_brst_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_data_b0 : 8;
        unsigned int bist_data_b1 : 8;
        unsigned int bist_data_b2 : 8;
        unsigned int bist_data_b3 : 8;
    } reg;
} SOC_HIPACKPHY_BISTDATA0_UNION;
#endif
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b0_START (0)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b0_END (7)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b1_START (8)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b1_END (15)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b2_START (16)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b2_END (23)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b3_START (24)
#define SOC_HIPACKPHY_BISTDATA0_bist_data_b3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_data_b4 : 8;
        unsigned int bist_data_b5 : 8;
        unsigned int bist_data_b6 : 8;
        unsigned int bist_data_b7 : 8;
    } reg;
} SOC_HIPACKPHY_BISTDATA1_UNION;
#endif
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b4_START (0)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b4_END (7)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b5_START (8)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b5_END (15)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b6_START (16)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b6_END (23)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b7_START (24)
#define SOC_HIPACKPHY_BISTDATA1_bist_data_b7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_done : 1;
        unsigned int bist_acerr : 1;
        unsigned int bist_dxerr : 1;
        unsigned int ac_lpbk_dvalid_no_come : 1;
        unsigned int dx_lpbk_dvalid_no_come : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HIPACKPHY_BISTSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_BISTSTATUS_bist_done_START (0)
#define SOC_HIPACKPHY_BISTSTATUS_bist_done_END (0)
#define SOC_HIPACKPHY_BISTSTATUS_bist_acerr_START (1)
#define SOC_HIPACKPHY_BISTSTATUS_bist_acerr_END (1)
#define SOC_HIPACKPHY_BISTSTATUS_bist_dxerr_START (2)
#define SOC_HIPACKPHY_BISTSTATUS_bist_dxerr_END (2)
#define SOC_HIPACKPHY_BISTSTATUS_ac_lpbk_dvalid_no_come_START (3)
#define SOC_HIPACKPHY_BISTSTATUS_ac_lpbk_dvalid_no_come_END (3)
#define SOC_HIPACKPHY_BISTSTATUS_dx_lpbk_dvalid_no_come_START (4)
#define SOC_HIPACKPHY_BISTSTATUS_dx_lpbk_dvalid_no_come_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mr0 : 16;
        unsigned int mr1 : 16;
    } reg;
} SOC_HIPACKPHY_MODEREG01_UNION;
#endif
#define SOC_HIPACKPHY_MODEREG01_mr0_START (0)
#define SOC_HIPACKPHY_MODEREG01_mr0_END (15)
#define SOC_HIPACKPHY_MODEREG01_mr1_START (16)
#define SOC_HIPACKPHY_MODEREG01_mr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mr2 : 16;
        unsigned int mr3 : 16;
    } reg;
} SOC_HIPACKPHY_MODEREG23_UNION;
#endif
#define SOC_HIPACKPHY_MODEREG23_mr2_START (0)
#define SOC_HIPACKPHY_MODEREG23_mr2_END (15)
#define SOC_HIPACKPHY_MODEREG23_mr3_START (16)
#define SOC_HIPACKPHY_MODEREG23_mr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int det_pat_pat : 32;
    } reg;
} SOC_HIPACKPHY_DETPATTERN_UNION;
#endif
#define SOC_HIPACKPHY_DETPATTERN_det_pat_pat_START (0)
#define SOC_HIPACKPHY_DETPATTERN_det_pat_pat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_wl : 8;
        unsigned int cfg_rl : 8;
        unsigned int scramb_en : 1;
        unsigned int addr_toggle : 1;
        unsigned int addr_delay : 1;
        unsigned int cfg_dlyupd : 1;
        unsigned int swap_en : 3;
        unsigned int ba_addr_scramb_en_lp4_r : 1;
        unsigned int cfg_dev_mode : 1;
        unsigned int swapdm_en : 2;
        unsigned int swapwl_en : 3;
        unsigned int cfg_cov_ac : 1;
        unsigned int cfg_serdes_rx_en : 1;
    } reg;
} SOC_HIPACKPHY_MISC_UNION;
#endif
#define SOC_HIPACKPHY_MISC_cfg_wl_START (0)
#define SOC_HIPACKPHY_MISC_cfg_wl_END (7)
#define SOC_HIPACKPHY_MISC_cfg_rl_START (8)
#define SOC_HIPACKPHY_MISC_cfg_rl_END (15)
#define SOC_HIPACKPHY_MISC_scramb_en_START (16)
#define SOC_HIPACKPHY_MISC_scramb_en_END (16)
#define SOC_HIPACKPHY_MISC_addr_toggle_START (17)
#define SOC_HIPACKPHY_MISC_addr_toggle_END (17)
#define SOC_HIPACKPHY_MISC_addr_delay_START (18)
#define SOC_HIPACKPHY_MISC_addr_delay_END (18)
#define SOC_HIPACKPHY_MISC_cfg_dlyupd_START (19)
#define SOC_HIPACKPHY_MISC_cfg_dlyupd_END (19)
#define SOC_HIPACKPHY_MISC_swap_en_START (20)
#define SOC_HIPACKPHY_MISC_swap_en_END (22)
#define SOC_HIPACKPHY_MISC_ba_addr_scramb_en_lp4_r_START (23)
#define SOC_HIPACKPHY_MISC_ba_addr_scramb_en_lp4_r_END (23)
#define SOC_HIPACKPHY_MISC_cfg_dev_mode_START (24)
#define SOC_HIPACKPHY_MISC_cfg_dev_mode_END (24)
#define SOC_HIPACKPHY_MISC_swapdm_en_START (25)
#define SOC_HIPACKPHY_MISC_swapdm_en_END (26)
#define SOC_HIPACKPHY_MISC_swapwl_en_START (27)
#define SOC_HIPACKPHY_MISC_swapwl_en_END (29)
#define SOC_HIPACKPHY_MISC_cfg_cov_ac_START (30)
#define SOC_HIPACKPHY_MISC_cfg_cov_ac_END (30)
#define SOC_HIPACKPHY_MISC_cfg_serdes_rx_en_START (31)
#define SOC_HIPACKPHY_MISC_cfg_serdes_rx_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trnkwtw : 5;
        unsigned int trnkrtr : 5;
        unsigned int trnkrtw : 5;
        unsigned int trnkwtr : 5;
        unsigned int reserved_0: 7;
        unsigned int trnkx2 : 1;
        unsigned int reserved_1: 1;
        unsigned int dfi2iomap : 3;
    } reg;
} SOC_HIPACKPHY_RNK2RNK_UNION;
#endif
#define SOC_HIPACKPHY_RNK2RNK_trnkwtw_START (0)
#define SOC_HIPACKPHY_RNK2RNK_trnkwtw_END (4)
#define SOC_HIPACKPHY_RNK2RNK_trnkrtr_START (5)
#define SOC_HIPACKPHY_RNK2RNK_trnkrtr_END (9)
#define SOC_HIPACKPHY_RNK2RNK_trnkrtw_START (10)
#define SOC_HIPACKPHY_RNK2RNK_trnkrtw_END (14)
#define SOC_HIPACKPHY_RNK2RNK_trnkwtr_START (15)
#define SOC_HIPACKPHY_RNK2RNK_trnkwtr_END (19)
#define SOC_HIPACKPHY_RNK2RNK_trnkx2_START (27)
#define SOC_HIPACKPHY_RNK2RNK_trnkx2_END (27)
#define SOC_HIPACKPHY_RNK2RNK_dfi2iomap_START (29)
#define SOC_HIPACKPHY_RNK2RNK_dfi2iomap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reg_sel_dficlk_rx : 1;
        unsigned int sel_pos_rx : 1;
        unsigned int lp_ck_sel : 2;
        unsigned int reserved_1 : 2;
        unsigned int cmdoen : 1;
        unsigned int ckoen : 3;
        unsigned int ckeoen : 1;
        unsigned int csoen : 1;
        unsigned int resetoen : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_HIPACKPHY_PHYCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_PHYCTRL0_reg_sel_dficlk_rx_START (1)
#define SOC_HIPACKPHY_PHYCTRL0_reg_sel_dficlk_rx_END (1)
#define SOC_HIPACKPHY_PHYCTRL0_sel_pos_rx_START (2)
#define SOC_HIPACKPHY_PHYCTRL0_sel_pos_rx_END (2)
#define SOC_HIPACKPHY_PHYCTRL0_lp_ck_sel_START (3)
#define SOC_HIPACKPHY_PHYCTRL0_lp_ck_sel_END (4)
#define SOC_HIPACKPHY_PHYCTRL0_cmdoen_START (7)
#define SOC_HIPACKPHY_PHYCTRL0_cmdoen_END (7)
#define SOC_HIPACKPHY_PHYCTRL0_ckoen_START (8)
#define SOC_HIPACKPHY_PHYCTRL0_ckoen_END (10)
#define SOC_HIPACKPHY_PHYCTRL0_ckeoen_START (11)
#define SOC_HIPACKPHY_PHYCTRL0_ckeoen_END (11)
#define SOC_HIPACKPHY_PHYCTRL0_csoen_START (12)
#define SOC_HIPACKPHY_PHYCTRL0_csoen_END (12)
#define SOC_HIPACKPHY_PHYCTRL0_resetoen_START (13)
#define SOC_HIPACKPHY_PHYCTRL0_resetoen_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dqs_gated_error_r : 8;
        unsigned int dqs_gated_error : 8;
        unsigned int dqsb_gated_error_r : 8;
        unsigned int dqsb_gated_error : 8;
    } reg;
} SOC_HIPACKPHY_PHYDBG_UNION;
#endif
#define SOC_HIPACKPHY_PHYDBG_dqs_gated_error_r_START (0)
#define SOC_HIPACKPHY_PHYDBG_dqs_gated_error_r_END (7)
#define SOC_HIPACKPHY_PHYDBG_dqs_gated_error_START (8)
#define SOC_HIPACKPHY_PHYDBG_dqs_gated_error_END (15)
#define SOC_HIPACKPHY_PHYDBG_dqsb_gated_error_r_START (16)
#define SOC_HIPACKPHY_PHYDBG_dqsb_gated_error_r_END (23)
#define SOC_HIPACKPHY_PHYDBG_dqsb_gated_error_START (24)
#define SOC_HIPACKPHY_PHYDBG_dqsb_gated_error_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyupd_resp : 13;
        unsigned int retrain_en : 1;
        unsigned int gtrten : 1;
        unsigned int rderten : 1;
        unsigned int retrain_thrd : 16;
    } reg;
} SOC_HIPACKPHY_RETCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_RETCTRL0_phyupd_resp_START (0)
#define SOC_HIPACKPHY_RETCTRL0_phyupd_resp_END (12)
#define SOC_HIPACKPHY_RETCTRL0_retrain_en_START (13)
#define SOC_HIPACKPHY_RETCTRL0_retrain_en_END (13)
#define SOC_HIPACKPHY_RETCTRL0_gtrten_START (14)
#define SOC_HIPACKPHY_RETCTRL0_gtrten_END (14)
#define SOC_HIPACKPHY_RETCTRL0_rderten_START (15)
#define SOC_HIPACKPHY_RETCTRL0_rderten_END (15)
#define SOC_HIPACKPHY_RETCTRL0_retrain_thrd_START (16)
#define SOC_HIPACKPHY_RETCTRL0_retrain_thrd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dxctl_dmswap_sel : 4;
        unsigned int rt_onebyone : 1;
        unsigned int fast_wl2_en : 1;
        unsigned int wlpulsecnt : 2;
        unsigned int tphy_wrdata : 1;
        unsigned int ddr4_dm_inv_en : 1;
        unsigned int wlpulsecnt_exd : 3;
        unsigned int phystop_en : 1;
        unsigned int phyupd_type_nopre : 2;
        unsigned int phyupd_type_pre : 2;
        unsigned int packdbgout : 1;
        unsigned int pllphhalfbdlen : 1;
        unsigned int pllphsel : 2;
        unsigned int wlexitmode : 1;
        unsigned int bl32atonthefly : 1;
        unsigned int swapdfibyte_en : 3;
        unsigned int swapaddr_en : 3;
        unsigned int tphy_wrdata_ext : 2;
    } reg;
} SOC_HIPACKPHY_DMSEL_UNION;
#endif
#define SOC_HIPACKPHY_DMSEL_dxctl_dmswap_sel_START (0)
#define SOC_HIPACKPHY_DMSEL_dxctl_dmswap_sel_END (3)
#define SOC_HIPACKPHY_DMSEL_rt_onebyone_START (4)
#define SOC_HIPACKPHY_DMSEL_rt_onebyone_END (4)
#define SOC_HIPACKPHY_DMSEL_fast_wl2_en_START (5)
#define SOC_HIPACKPHY_DMSEL_fast_wl2_en_END (5)
#define SOC_HIPACKPHY_DMSEL_wlpulsecnt_START (6)
#define SOC_HIPACKPHY_DMSEL_wlpulsecnt_END (7)
#define SOC_HIPACKPHY_DMSEL_tphy_wrdata_START (8)
#define SOC_HIPACKPHY_DMSEL_tphy_wrdata_END (8)
#define SOC_HIPACKPHY_DMSEL_ddr4_dm_inv_en_START (9)
#define SOC_HIPACKPHY_DMSEL_ddr4_dm_inv_en_END (9)
#define SOC_HIPACKPHY_DMSEL_wlpulsecnt_exd_START (10)
#define SOC_HIPACKPHY_DMSEL_wlpulsecnt_exd_END (12)
#define SOC_HIPACKPHY_DMSEL_phystop_en_START (13)
#define SOC_HIPACKPHY_DMSEL_phystop_en_END (13)
#define SOC_HIPACKPHY_DMSEL_phyupd_type_nopre_START (14)
#define SOC_HIPACKPHY_DMSEL_phyupd_type_nopre_END (15)
#define SOC_HIPACKPHY_DMSEL_phyupd_type_pre_START (16)
#define SOC_HIPACKPHY_DMSEL_phyupd_type_pre_END (17)
#define SOC_HIPACKPHY_DMSEL_packdbgout_START (18)
#define SOC_HIPACKPHY_DMSEL_packdbgout_END (18)
#define SOC_HIPACKPHY_DMSEL_pllphhalfbdlen_START (19)
#define SOC_HIPACKPHY_DMSEL_pllphhalfbdlen_END (19)
#define SOC_HIPACKPHY_DMSEL_pllphsel_START (20)
#define SOC_HIPACKPHY_DMSEL_pllphsel_END (21)
#define SOC_HIPACKPHY_DMSEL_wlexitmode_START (22)
#define SOC_HIPACKPHY_DMSEL_wlexitmode_END (22)
#define SOC_HIPACKPHY_DMSEL_bl32atonthefly_START (23)
#define SOC_HIPACKPHY_DMSEL_bl32atonthefly_END (23)
#define SOC_HIPACKPHY_DMSEL_swapdfibyte_en_START (24)
#define SOC_HIPACKPHY_DMSEL_swapdfibyte_en_END (26)
#define SOC_HIPACKPHY_DMSEL_swapaddr_en_START (27)
#define SOC_HIPACKPHY_DMSEL_swapaddr_en_END (29)
#define SOC_HIPACKPHY_DMSEL_tphy_wrdata_ext_START (30)
#define SOC_HIPACKPHY_DMSEL_tphy_wrdata_ext_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trainctl_donewait : 3;
        unsigned int nomrs4rdet : 1;
        unsigned int nopre4wl : 1;
        unsigned int radix3sel : 2;
        unsigned int reserved : 1;
        unsigned int wdert_shift_step : 6;
        unsigned int lpbk_gt_rden_type : 1;
        unsigned int gtrt_ph_reload_type : 1;
        unsigned int empty_time : 4;
        unsigned int cdgc_done_cnt : 4;
        unsigned int det_rstpost_time : 4;
        unsigned int det_sstrstphy_time : 4;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL8_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL8_trainctl_donewait_START (0)
#define SOC_HIPACKPHY_TRAINCTRL8_trainctl_donewait_END (2)
#define SOC_HIPACKPHY_TRAINCTRL8_nomrs4rdet_START (3)
#define SOC_HIPACKPHY_TRAINCTRL8_nomrs4rdet_END (3)
#define SOC_HIPACKPHY_TRAINCTRL8_nopre4wl_START (4)
#define SOC_HIPACKPHY_TRAINCTRL8_nopre4wl_END (4)
#define SOC_HIPACKPHY_TRAINCTRL8_radix3sel_START (5)
#define SOC_HIPACKPHY_TRAINCTRL8_radix3sel_END (6)
#define SOC_HIPACKPHY_TRAINCTRL8_wdert_shift_step_START (8)
#define SOC_HIPACKPHY_TRAINCTRL8_wdert_shift_step_END (13)
#define SOC_HIPACKPHY_TRAINCTRL8_lpbk_gt_rden_type_START (14)
#define SOC_HIPACKPHY_TRAINCTRL8_lpbk_gt_rden_type_END (14)
#define SOC_HIPACKPHY_TRAINCTRL8_gtrt_ph_reload_type_START (15)
#define SOC_HIPACKPHY_TRAINCTRL8_gtrt_ph_reload_type_END (15)
#define SOC_HIPACKPHY_TRAINCTRL8_empty_time_START (16)
#define SOC_HIPACKPHY_TRAINCTRL8_empty_time_END (19)
#define SOC_HIPACKPHY_TRAINCTRL8_cdgc_done_cnt_START (20)
#define SOC_HIPACKPHY_TRAINCTRL8_cdgc_done_cnt_END (23)
#define SOC_HIPACKPHY_TRAINCTRL8_det_rstpost_time_START (24)
#define SOC_HIPACKPHY_TRAINCTRL8_det_rstpost_time_END (27)
#define SOC_HIPACKPHY_TRAINCTRL8_det_sstrstphy_time_START (28)
#define SOC_HIPACKPHY_TRAINCTRL8_det_sstrstphy_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mc_wrcmd_xgated_en : 1;
        unsigned int WCKgated_phy_hw_en : 1;
        unsigned int RXgated_phy_hw_en : 1;
        unsigned int TXgated_phy_hw_en : 1;
        unsigned int Xgated_dig_pstmrg : 4;
        unsigned int Xgated_dig_premrg : 4;
        unsigned int RXgated_phy_pstmrg : 4;
        unsigned int RXgated_phy_premrg : 4;
        unsigned int TXgated_phy_pstmrg : 4;
        unsigned int TXgated_phy_premrg : 5;
        unsigned int Xgated_dig_hw_en : 1;
        unsigned int Xgated_dig_legacy : 1;
        unsigned int Xgated_phy_legacy : 1;
    } reg;
} SOC_HIPACKPHY_LPCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_LPCTRL2_mc_wrcmd_xgated_en_START (0)
#define SOC_HIPACKPHY_LPCTRL2_mc_wrcmd_xgated_en_END (0)
#define SOC_HIPACKPHY_LPCTRL2_WCKgated_phy_hw_en_START (1)
#define SOC_HIPACKPHY_LPCTRL2_WCKgated_phy_hw_en_END (1)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_hw_en_START (2)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_hw_en_END (2)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_hw_en_START (3)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_hw_en_END (3)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_pstmrg_START (4)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_pstmrg_END (7)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_premrg_START (8)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_premrg_END (11)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_pstmrg_START (12)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_pstmrg_END (15)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_premrg_START (16)
#define SOC_HIPACKPHY_LPCTRL2_RXgated_phy_premrg_END (19)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_pstmrg_START (20)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_pstmrg_END (23)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_premrg_START (24)
#define SOC_HIPACKPHY_LPCTRL2_TXgated_phy_premrg_END (28)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_hw_en_START (29)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_hw_en_END (29)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_legacy_START (30)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_dig_legacy_END (30)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_phy_legacy_START (31)
#define SOC_HIPACKPHY_LPCTRL2_Xgated_phy_legacy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gds_margin_sel : 3;
        unsigned int byp_gate : 1;
        unsigned int dbi_in_pipe_en : 1;
        unsigned int cfg_gds_max_7 : 1;
        unsigned int alu_done_cyc : 1;
        unsigned int reserved_0 : 1;
        unsigned int one_phase_code : 6;
        unsigned int reserved_1 : 1;
        unsigned int rt_ehandle_en : 1;
        unsigned int wdert_check_step : 6;
        unsigned int wdert_bdl_shift_step : 2;
        unsigned int row_react_period_offset : 2;
        unsigned int wdert_bdl_check_step : 2;
        unsigned int train_reset_time : 4;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL9_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL9_gds_margin_sel_START (0)
#define SOC_HIPACKPHY_TRAINCTRL9_gds_margin_sel_END (2)
#define SOC_HIPACKPHY_TRAINCTRL9_byp_gate_START (3)
#define SOC_HIPACKPHY_TRAINCTRL9_byp_gate_END (3)
#define SOC_HIPACKPHY_TRAINCTRL9_dbi_in_pipe_en_START (4)
#define SOC_HIPACKPHY_TRAINCTRL9_dbi_in_pipe_en_END (4)
#define SOC_HIPACKPHY_TRAINCTRL9_cfg_gds_max_7_START (5)
#define SOC_HIPACKPHY_TRAINCTRL9_cfg_gds_max_7_END (5)
#define SOC_HIPACKPHY_TRAINCTRL9_alu_done_cyc_START (6)
#define SOC_HIPACKPHY_TRAINCTRL9_alu_done_cyc_END (6)
#define SOC_HIPACKPHY_TRAINCTRL9_one_phase_code_START (8)
#define SOC_HIPACKPHY_TRAINCTRL9_one_phase_code_END (13)
#define SOC_HIPACKPHY_TRAINCTRL9_rt_ehandle_en_START (15)
#define SOC_HIPACKPHY_TRAINCTRL9_rt_ehandle_en_END (15)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_check_step_START (16)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_check_step_END (21)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_bdl_shift_step_START (22)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_bdl_shift_step_END (23)
#define SOC_HIPACKPHY_TRAINCTRL9_row_react_period_offset_START (24)
#define SOC_HIPACKPHY_TRAINCTRL9_row_react_period_offset_END (25)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_bdl_check_step_START (26)
#define SOC_HIPACKPHY_TRAINCTRL9_wdert_bdl_check_step_END (27)
#define SOC_HIPACKPHY_TRAINCTRL9_train_reset_time_START (28)
#define SOC_HIPACKPHY_TRAINCTRL9_train_reset_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dqsgrt_shft : 6;
        unsigned int reserved_0 : 2;
        unsigned int dqsgrt_chk : 6;
        unsigned int reserved_1 : 2;
        unsigned int dyn_dqsgbdl_trans : 8;
        unsigned int wdet_trysamp_num : 3;
        unsigned int reserved_2 : 1;
        unsigned int rdet_trysamp_num : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL10_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL10_dqsgrt_shft_START (0)
#define SOC_HIPACKPHY_TRAINCTRL10_dqsgrt_shft_END (5)
#define SOC_HIPACKPHY_TRAINCTRL10_dqsgrt_chk_START (8)
#define SOC_HIPACKPHY_TRAINCTRL10_dqsgrt_chk_END (13)
#define SOC_HIPACKPHY_TRAINCTRL10_dyn_dqsgbdl_trans_START (16)
#define SOC_HIPACKPHY_TRAINCTRL10_dyn_dqsgbdl_trans_END (23)
#define SOC_HIPACKPHY_TRAINCTRL10_wdet_trysamp_num_START (24)
#define SOC_HIPACKPHY_TRAINCTRL10_wdet_trysamp_num_END (26)
#define SOC_HIPACKPHY_TRAINCTRL10_rdet_trysamp_num_START (28)
#define SOC_HIPACKPHY_TRAINCTRL10_rdet_trysamp_num_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lock_timer_latch : 24;
        unsigned int reserved_0 : 4;
        unsigned int pll_init_ac_dis : 1;
        unsigned int pll_init_dx_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int ac_pll_lock : 1;
    } reg;
} SOC_HIPACKPHY_PHYPLLCTRL_AC_UNION;
#endif
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_lock_timer_latch_START (0)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_lock_timer_latch_END (23)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_pll_init_ac_dis_START (28)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_pll_init_ac_dis_END (28)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_pll_init_dx_dis_START (29)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_pll_init_dx_dis_END (29)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_ac_pll_lock_START (31)
#define SOC_HIPACKPHY_PHYPLLCTRL_AC_ac_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dx_pll_test : 16;
        unsigned int reserved : 14;
        unsigned int dx_pll_lock : 2;
    } reg;
} SOC_HIPACKPHY_PHYPLLCTRL_DX_UNION;
#endif
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_dx_pll_test_START (0)
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_dx_pll_test_END (15)
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_dx_pll_lock_START (30)
#define SOC_HIPACKPHY_PHYPLLCTRL_DX_dx_pll_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_wlmode : 1;
        unsigned int sw_gtmode : 1;
        unsigned int reserved_0 : 2;
        unsigned int sw_wlmodeb : 8;
        unsigned int reserved_1 : 4;
        unsigned int sw_dxctl_ie_dq : 8;
        unsigned int sw_dxctl_ie_dq_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int swop_prewrite : 1;
        unsigned int swop_rdtest : 1;
        unsigned int sw_rdfifo_push_block : 1;
        unsigned int sw_dvalid_block : 1;
        unsigned int sw_csgated : 1;
        unsigned int wl_wdqs_gated : 1;
    } reg;
} SOC_HIPACKPHY_SWTMODE_UNION;
#endif
#define SOC_HIPACKPHY_SWTMODE_sw_wlmode_START (0)
#define SOC_HIPACKPHY_SWTMODE_sw_wlmode_END (0)
#define SOC_HIPACKPHY_SWTMODE_sw_gtmode_START (1)
#define SOC_HIPACKPHY_SWTMODE_sw_gtmode_END (1)
#define SOC_HIPACKPHY_SWTMODE_sw_wlmodeb_START (4)
#define SOC_HIPACKPHY_SWTMODE_sw_wlmodeb_END (11)
#define SOC_HIPACKPHY_SWTMODE_sw_dxctl_ie_dq_START (16)
#define SOC_HIPACKPHY_SWTMODE_sw_dxctl_ie_dq_END (23)
#define SOC_HIPACKPHY_SWTMODE_sw_dxctl_ie_dq_mode_START (24)
#define SOC_HIPACKPHY_SWTMODE_sw_dxctl_ie_dq_mode_END (24)
#define SOC_HIPACKPHY_SWTMODE_swop_prewrite_START (26)
#define SOC_HIPACKPHY_SWTMODE_swop_prewrite_END (26)
#define SOC_HIPACKPHY_SWTMODE_swop_rdtest_START (27)
#define SOC_HIPACKPHY_SWTMODE_swop_rdtest_END (27)
#define SOC_HIPACKPHY_SWTMODE_sw_rdfifo_push_block_START (28)
#define SOC_HIPACKPHY_SWTMODE_sw_rdfifo_push_block_END (28)
#define SOC_HIPACKPHY_SWTMODE_sw_dvalid_block_START (29)
#define SOC_HIPACKPHY_SWTMODE_sw_dvalid_block_END (29)
#define SOC_HIPACKPHY_SWTMODE_sw_csgated_START (30)
#define SOC_HIPACKPHY_SWTMODE_sw_csgated_END (30)
#define SOC_HIPACKPHY_SWTMODE_wl_wdqs_gated_START (31)
#define SOC_HIPACKPHY_SWTMODE_wl_wdqs_gated_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_wl_dqs : 1;
        unsigned int reserved : 2;
        unsigned int sw_mrw_format : 1;
        unsigned int sw_mrw_cs : 2;
        unsigned int sw_mrw_rw : 1;
        unsigned int sw_mrw_req : 1;
        unsigned int sw_mrw_ma : 8;
        unsigned int sw_mrw_op : 16;
    } reg;
} SOC_HIPACKPHY_SWTWLDQS_UNION;
#endif
#define SOC_HIPACKPHY_SWTWLDQS_sw_wl_dqs_START (0)
#define SOC_HIPACKPHY_SWTWLDQS_sw_wl_dqs_END (0)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_format_START (3)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_format_END (3)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_cs_START (4)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_cs_END (5)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_rw_START (6)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_rw_END (6)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_req_START (7)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_req_END (7)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_ma_START (8)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_ma_END (15)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_op_START (16)
#define SOC_HIPACKPHY_SWTWLDQS_sw_mrw_op_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wl_dq_result : 8;
        unsigned int gt_result : 8;
        unsigned int gds_result : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPACKPHY_SWTRLT_UNION;
#endif
#define SOC_HIPACKPHY_SWTRLT_wl_dq_result_START (0)
#define SOC_HIPACKPHY_SWTRLT_wl_dq_result_END (7)
#define SOC_HIPACKPHY_SWTRLT_gt_result_START (8)
#define SOC_HIPACKPHY_SWTRLT_gt_result_END (15)
#define SOC_HIPACKPHY_SWTRLT_gds_result_START (16)
#define SOC_HIPACKPHY_SWTRLT_gds_result_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rs_rstcont_passthrough : 4;
        unsigned int reserved_0 : 2;
        unsigned int rs_rst_passthrough : 4;
        unsigned int reserved_1 : 2;
        unsigned int rs_passthrough : 4;
        unsigned int reserved_2 : 2;
        unsigned int rs_rs_passthrough : 4;
        unsigned int reserved_3 : 6;
        unsigned int rsneg_rstcont_passthrough : 1;
        unsigned int rsneg_rst_passthrough : 1;
        unsigned int rsneg_passthrough : 1;
        unsigned int rx_rsneg_passthrough : 1;
    } reg;
} SOC_HIPACKPHY_PHYRSCTRL_UNION;
#endif
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rstcont_passthrough_START (0)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rstcont_passthrough_END (3)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rst_passthrough_START (6)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rst_passthrough_END (9)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_passthrough_START (12)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_passthrough_END (15)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rs_passthrough_START (18)
#define SOC_HIPACKPHY_PHYRSCTRL_rs_rs_passthrough_END (21)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_rstcont_passthrough_START (28)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_rstcont_passthrough_END (28)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_rst_passthrough_START (29)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_rst_passthrough_END (29)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_passthrough_START (30)
#define SOC_HIPACKPHY_PHYRSCTRL_rsneg_passthrough_END (30)
#define SOC_HIPACKPHY_PHYRSCTRL_rx_rsneg_passthrough_START (31)
#define SOC_HIPACKPHY_PHYRSCTRL_rx_rsneg_passthrough_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int final_scan_col_cnt_r : 12;
        unsigned int final_scan_row_cnt_r : 20;
    } reg;
} SOC_HIPACKPHY_BISTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_BISTCTRL2_final_scan_col_cnt_r_START (0)
#define SOC_HIPACKPHY_BISTCTRL2_final_scan_col_cnt_r_END (11)
#define SOC_HIPACKPHY_BISTCTRL2_final_scan_row_cnt_r_START (12)
#define SOC_HIPACKPHY_BISTCTRL2_final_scan_row_cnt_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtcol_tg1 : 12;
        unsigned int dtrow_tg1 : 20;
    } reg;
} SOC_HIPACKPHY_TRAINMADDRTG1_UNION;
#endif
#define SOC_HIPACKPHY_TRAINMADDRTG1_dtcol_tg1_START (0)
#define SOC_HIPACKPHY_TRAINMADDRTG1_dtcol_tg1_END (11)
#define SOC_HIPACKPHY_TRAINMADDRTG1_dtrow_tg1_START (12)
#define SOC_HIPACKPHY_TRAINMADDRTG1_dtrow_tg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_wl : 8;
        unsigned int t_odton_h : 4;
        unsigned int t_ccd_s_lp5 : 4;
        unsigned int t_rl : 8;
        unsigned int t_ccd_x_lp5 : 4;
        unsigned int tcsh : 3;
        unsigned int reserved : 1;
    } reg;
} SOC_HIPACKPHY_DRAMTIMER5_UNION;
#endif
#define SOC_HIPACKPHY_DRAMTIMER5_t_wl_START (0)
#define SOC_HIPACKPHY_DRAMTIMER5_t_wl_END (7)
#define SOC_HIPACKPHY_DRAMTIMER5_t_odton_h_START (8)
#define SOC_HIPACKPHY_DRAMTIMER5_t_odton_h_END (11)
#define SOC_HIPACKPHY_DRAMTIMER5_t_ccd_s_lp5_START (12)
#define SOC_HIPACKPHY_DRAMTIMER5_t_ccd_s_lp5_END (15)
#define SOC_HIPACKPHY_DRAMTIMER5_t_rl_START (16)
#define SOC_HIPACKPHY_DRAMTIMER5_t_rl_END (23)
#define SOC_HIPACKPHY_DRAMTIMER5_t_ccd_x_lp5_START (24)
#define SOC_HIPACKPHY_DRAMTIMER5_t_ccd_x_lp5_END (27)
#define SOC_HIPACKPHY_DRAMTIMER5_tcsh_START (28)
#define SOC_HIPACKPHY_DRAMTIMER5_tcsh_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vreft_bist_runtime : 8;
        unsigned int vreft_dlyupwait : 4;
        unsigned int vreft_hor_update : 1;
        unsigned int DCC_en : 1;
        unsigned int vreft_method2 : 1;
        unsigned int vreft_dborg : 1;
        unsigned int vreft_bist_pass_cnt : 5;
        unsigned int vreft_no_dec : 1;
        unsigned int vreft_3_direction : 1;
        unsigned int vrefrt : 1;
        unsigned int vref_track_en : 1;
        unsigned int check_ok_cond : 1;
        unsigned int vref_track_method : 1;
        unsigned int vreft_dummy_reg : 2;
        unsigned int t_vref_host : 3;
    } reg;
} SOC_HIPACKPHY_VREFTCTRL_UNION;
#endif
#define SOC_HIPACKPHY_VREFTCTRL_vreft_bist_runtime_START (0)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_bist_runtime_END (7)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dlyupwait_START (8)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dlyupwait_END (11)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_hor_update_START (12)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_hor_update_END (12)
#define SOC_HIPACKPHY_VREFTCTRL_DCC_en_START (13)
#define SOC_HIPACKPHY_VREFTCTRL_DCC_en_END (13)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_method2_START (14)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_method2_END (14)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dborg_START (15)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dborg_END (15)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_bist_pass_cnt_START (16)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_bist_pass_cnt_END (20)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_no_dec_START (21)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_no_dec_END (21)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_3_direction_START (22)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_3_direction_END (22)
#define SOC_HIPACKPHY_VREFTCTRL_vrefrt_START (23)
#define SOC_HIPACKPHY_VREFTCTRL_vrefrt_END (23)
#define SOC_HIPACKPHY_VREFTCTRL_vref_track_en_START (24)
#define SOC_HIPACKPHY_VREFTCTRL_vref_track_en_END (24)
#define SOC_HIPACKPHY_VREFTCTRL_check_ok_cond_START (25)
#define SOC_HIPACKPHY_VREFTCTRL_check_ok_cond_END (25)
#define SOC_HIPACKPHY_VREFTCTRL_vref_track_method_START (26)
#define SOC_HIPACKPHY_VREFTCTRL_vref_track_method_END (26)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dummy_reg_START (27)
#define SOC_HIPACKPHY_VREFTCTRL_vreft_dummy_reg_END (28)
#define SOC_HIPACKPHY_VREFTCTRL_t_vref_host_START (29)
#define SOC_HIPACKPHY_VREFTCTRL_t_vref_host_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dvreft_maxv : 7;
        unsigned int reserved_0 : 1;
        unsigned int dvreft_minv : 7;
        unsigned int reserved_1 : 1;
        unsigned int dvreft_step : 6;
        unsigned int reserved_2 : 2;
        unsigned int dvreft_hckpts : 6;
        unsigned int reserved_3 : 1;
        unsigned int pdaen : 1;
    } reg;
} SOC_HIPACKPHY_DVRFTCTRL_UNION;
#endif
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_maxv_START (0)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_maxv_END (6)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_minv_START (8)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_minv_END (14)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_step_START (16)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_step_END (21)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_hckpts_START (24)
#define SOC_HIPACKPHY_DVRFTCTRL_dvreft_hckpts_END (29)
#define SOC_HIPACKPHY_DVRFTCTRL_pdaen_START (31)
#define SOC_HIPACKPHY_DVRFTCTRL_pdaen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hvreft_maxv : 7;
        unsigned int reserved_0 : 1;
        unsigned int hvreft_minv : 7;
        unsigned int reserved_1 : 1;
        unsigned int hvreft_step : 6;
        unsigned int hvreft_hckpts : 6;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_HIPACKPHY_HVRFTCTRL_UNION;
#endif
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_maxv_START (0)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_maxv_END (6)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_minv_START (8)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_minv_END (14)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_step_START (16)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_step_END (21)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_hckpts_START (22)
#define SOC_HIPACKPHY_HVRFTCTRL_hvreft_hckpts_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdet_samp_num : 8;
        unsigned int cfg_fast_rdet_cnt : 3;
        unsigned int wdet_ct_dqs_en : 1;
        unsigned int wrdet_av_en : 1;
        unsigned int wdet_rbs_en : 1;
        unsigned int wdet_ds_en : 1;
        unsigned int wdet_lbs_en : 1;
        unsigned int rdet_samp_num : 8;
        unsigned int cfg_wdert_hyp_mode_sel : 1;
        unsigned int fast_rdet_en : 1;
        unsigned int rdet_dq_evenodd_en : 1;
        unsigned int rdet_ct_dqs_en : 1;
        unsigned int rdet_av_en : 1;
        unsigned int rdet_rbs_en : 1;
        unsigned int rdet_ds_en : 1;
        unsigned int rdet_lbs_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_samp_num_START (0)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_samp_num_END (7)
#define SOC_HIPACKPHY_TRAINCTRL1_cfg_fast_rdet_cnt_START (8)
#define SOC_HIPACKPHY_TRAINCTRL1_cfg_fast_rdet_cnt_END (10)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_ct_dqs_en_START (11)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_ct_dqs_en_END (11)
#define SOC_HIPACKPHY_TRAINCTRL1_wrdet_av_en_START (12)
#define SOC_HIPACKPHY_TRAINCTRL1_wrdet_av_en_END (12)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_rbs_en_START (13)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_rbs_en_END (13)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_ds_en_START (14)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_ds_en_END (14)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_lbs_en_START (15)
#define SOC_HIPACKPHY_TRAINCTRL1_wdet_lbs_en_END (15)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_samp_num_START (16)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_samp_num_END (23)
#define SOC_HIPACKPHY_TRAINCTRL1_cfg_wdert_hyp_mode_sel_START (24)
#define SOC_HIPACKPHY_TRAINCTRL1_cfg_wdert_hyp_mode_sel_END (24)
#define SOC_HIPACKPHY_TRAINCTRL1_fast_rdet_en_START (25)
#define SOC_HIPACKPHY_TRAINCTRL1_fast_rdet_en_END (25)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_dq_evenodd_en_START (26)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_dq_evenodd_en_END (26)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_ct_dqs_en_START (27)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_ct_dqs_en_END (27)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_av_en_START (28)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_av_en_END (28)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_rbs_en_START (29)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_rbs_en_END (29)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_ds_en_START (30)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_ds_en_END (30)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_lbs_en_START (31)
#define SOC_HIPACKPHY_TRAINCTRL1_rdet_lbs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mrr_pat_A : 8;
        unsigned int mrr_pat_B : 8;
        unsigned int mrr_pat_mask : 8;
        unsigned int rbound_sfal_en : 1;
        unsigned int fast_gt_en : 1;
        unsigned int fast_gdst_en : 1;
        unsigned int mrr_bl4 : 1;
        unsigned int mrr_pat_order : 3;
        unsigned int rdet_method_sel : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_A_START (0)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_A_END (7)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_B_START (8)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_B_END (15)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_mask_START (16)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_mask_END (23)
#define SOC_HIPACKPHY_TRAINCTRL2_rbound_sfal_en_START (24)
#define SOC_HIPACKPHY_TRAINCTRL2_rbound_sfal_en_END (24)
#define SOC_HIPACKPHY_TRAINCTRL2_fast_gt_en_START (25)
#define SOC_HIPACKPHY_TRAINCTRL2_fast_gt_en_END (25)
#define SOC_HIPACKPHY_TRAINCTRL2_fast_gdst_en_START (26)
#define SOC_HIPACKPHY_TRAINCTRL2_fast_gdst_en_END (26)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_bl4_START (27)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_bl4_END (27)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_order_START (28)
#define SOC_HIPACKPHY_TRAINCTRL2_mrr_pat_order_END (30)
#define SOC_HIPACKPHY_TRAINCTRL2_rdet_method_sel_START (31)
#define SOC_HIPACKPHY_TRAINCTRL2_rdet_method_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_sel : 2;
        unsigned int op_sel : 2;
        unsigned int sync_src_sel : 2;
        unsigned int sync_tar_sel : 2;
        unsigned int shadow_sync_en : 1;
        unsigned int hw_opsel_seq : 1;
        unsigned int reserved : 21;
        unsigned int opsel_chg : 1;
    } reg;
} SOC_HIPACKPHY_REGBANKCTRL_UNION;
#endif
#define SOC_HIPACKPHY_REGBANKCTRL_wr_sel_START (0)
#define SOC_HIPACKPHY_REGBANKCTRL_wr_sel_END (1)
#define SOC_HIPACKPHY_REGBANKCTRL_op_sel_START (2)
#define SOC_HIPACKPHY_REGBANKCTRL_op_sel_END (3)
#define SOC_HIPACKPHY_REGBANKCTRL_sync_src_sel_START (4)
#define SOC_HIPACKPHY_REGBANKCTRL_sync_src_sel_END (5)
#define SOC_HIPACKPHY_REGBANKCTRL_sync_tar_sel_START (6)
#define SOC_HIPACKPHY_REGBANKCTRL_sync_tar_sel_END (7)
#define SOC_HIPACKPHY_REGBANKCTRL_shadow_sync_en_START (8)
#define SOC_HIPACKPHY_REGBANKCTRL_shadow_sync_en_END (8)
#define SOC_HIPACKPHY_REGBANKCTRL_hw_opsel_seq_START (9)
#define SOC_HIPACKPHY_REGBANKCTRL_hw_opsel_seq_END (9)
#define SOC_HIPACKPHY_REGBANKCTRL_opsel_chg_START (31)
#define SOC_HIPACKPHY_REGBANKCTRL_opsel_chg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_wlresult_inv : 1;
        unsigned int cfg_msp_train_active : 1;
        unsigned int cfg_msp_train_en : 1;
        unsigned int rg_msp2xratio : 1;
        unsigned int cfg_internal_mcu_sel : 1;
        unsigned int det_bist_method_en : 1;
        unsigned int wdet_dbi_en : 1;
        unsigned int cfg_wdet2pat_en : 1;
        unsigned int chk_step_adj : 1;
        unsigned int chk_step_margin : 1;
        unsigned int mpcfifo_only_read_repeat : 1;
        unsigned int rdert_mpcfifo : 1;
        unsigned int wderten : 1;
        unsigned int wdet_rank_en : 1;
        unsigned int wrenrkswen : 1;
        unsigned int nopre4wrdet : 1;
        unsigned int gdsrt_backtap : 3;
        unsigned int rdet_rank_en : 1;
        unsigned int rdet_dbi_en : 1;
        unsigned int cat_pat_toggle_en : 1;
        unsigned int rpt_mode_en : 1;
        unsigned int wdet_method_sel : 1;
        unsigned int fast_gt_cnt : 5;
        unsigned int cfg_upd_scandq_en : 1;
        unsigned int rdet_fcomp_en : 1;
        unsigned int exd_gtres_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL3_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_wlresult_inv_START (0)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_wlresult_inv_END (0)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_msp_train_active_START (1)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_msp_train_active_END (1)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_msp_train_en_START (2)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_msp_train_en_END (2)
#define SOC_HIPACKPHY_TRAINCTRL3_rg_msp2xratio_START (3)
#define SOC_HIPACKPHY_TRAINCTRL3_rg_msp2xratio_END (3)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_internal_mcu_sel_START (4)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_internal_mcu_sel_END (4)
#define SOC_HIPACKPHY_TRAINCTRL3_det_bist_method_en_START (5)
#define SOC_HIPACKPHY_TRAINCTRL3_det_bist_method_en_END (5)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_dbi_en_START (6)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_dbi_en_END (6)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_wdet2pat_en_START (7)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_wdet2pat_en_END (7)
#define SOC_HIPACKPHY_TRAINCTRL3_chk_step_adj_START (8)
#define SOC_HIPACKPHY_TRAINCTRL3_chk_step_adj_END (8)
#define SOC_HIPACKPHY_TRAINCTRL3_chk_step_margin_START (9)
#define SOC_HIPACKPHY_TRAINCTRL3_chk_step_margin_END (9)
#define SOC_HIPACKPHY_TRAINCTRL3_mpcfifo_only_read_repeat_START (10)
#define SOC_HIPACKPHY_TRAINCTRL3_mpcfifo_only_read_repeat_END (10)
#define SOC_HIPACKPHY_TRAINCTRL3_rdert_mpcfifo_START (11)
#define SOC_HIPACKPHY_TRAINCTRL3_rdert_mpcfifo_END (11)
#define SOC_HIPACKPHY_TRAINCTRL3_wderten_START (12)
#define SOC_HIPACKPHY_TRAINCTRL3_wderten_END (12)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_rank_en_START (13)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_rank_en_END (13)
#define SOC_HIPACKPHY_TRAINCTRL3_wrenrkswen_START (14)
#define SOC_HIPACKPHY_TRAINCTRL3_wrenrkswen_END (14)
#define SOC_HIPACKPHY_TRAINCTRL3_nopre4wrdet_START (15)
#define SOC_HIPACKPHY_TRAINCTRL3_nopre4wrdet_END (15)
#define SOC_HIPACKPHY_TRAINCTRL3_gdsrt_backtap_START (16)
#define SOC_HIPACKPHY_TRAINCTRL3_gdsrt_backtap_END (18)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_rank_en_START (19)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_rank_en_END (19)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_dbi_en_START (20)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_dbi_en_END (20)
#define SOC_HIPACKPHY_TRAINCTRL3_cat_pat_toggle_en_START (21)
#define SOC_HIPACKPHY_TRAINCTRL3_cat_pat_toggle_en_END (21)
#define SOC_HIPACKPHY_TRAINCTRL3_rpt_mode_en_START (22)
#define SOC_HIPACKPHY_TRAINCTRL3_rpt_mode_en_END (22)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_method_sel_START (23)
#define SOC_HIPACKPHY_TRAINCTRL3_wdet_method_sel_END (23)
#define SOC_HIPACKPHY_TRAINCTRL3_fast_gt_cnt_START (24)
#define SOC_HIPACKPHY_TRAINCTRL3_fast_gt_cnt_END (28)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_upd_scandq_en_START (29)
#define SOC_HIPACKPHY_TRAINCTRL3_cfg_upd_scandq_en_END (29)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_fcomp_en_START (30)
#define SOC_HIPACKPHY_TRAINCTRL3_rdet_fcomp_en_END (30)
#define SOC_HIPACKPHY_TRAINCTRL3_exd_gtres_en_START (31)
#define SOC_HIPACKPHY_TRAINCTRL3_exd_gtres_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mr4 : 16;
        unsigned int mr5 : 16;
    } reg;
} SOC_HIPACKPHY_MODEREG45_UNION;
#endif
#define SOC_HIPACKPHY_MODEREG45_mr4_START (0)
#define SOC_HIPACKPHY_MODEREG45_mr4_END (15)
#define SOC_HIPACKPHY_MODEREG45_mr5_START (16)
#define SOC_HIPACKPHY_MODEREG45_mr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mr6 : 16;
        unsigned int mr7 : 16;
    } reg;
} SOC_HIPACKPHY_MODEREG67_UNION;
#endif
#define SOC_HIPACKPHY_MODEREG67_mr6_START (0)
#define SOC_HIPACKPHY_MODEREG67_mr6_END (15)
#define SOC_HIPACKPHY_MODEREG67_mr7_START (16)
#define SOC_HIPACKPHY_MODEREG67_mr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phyupdtimer : 16;
        unsigned int cfg_reg_sync_cnt : 4;
        unsigned int cat_re_deskew_en : 1;
        unsigned int det_re_deskew_en : 1;
        unsigned int half_ph_bdl_en : 1;
        unsigned int bdlcarry_done : 1;
        unsigned int row_react_period : 8;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL6_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL6_phyupdtimer_START (0)
#define SOC_HIPACKPHY_TRAINCTRL6_phyupdtimer_END (15)
#define SOC_HIPACKPHY_TRAINCTRL6_cfg_reg_sync_cnt_START (16)
#define SOC_HIPACKPHY_TRAINCTRL6_cfg_reg_sync_cnt_END (19)
#define SOC_HIPACKPHY_TRAINCTRL6_cat_re_deskew_en_START (20)
#define SOC_HIPACKPHY_TRAINCTRL6_cat_re_deskew_en_END (20)
#define SOC_HIPACKPHY_TRAINCTRL6_det_re_deskew_en_START (21)
#define SOC_HIPACKPHY_TRAINCTRL6_det_re_deskew_en_END (21)
#define SOC_HIPACKPHY_TRAINCTRL6_half_ph_bdl_en_START (22)
#define SOC_HIPACKPHY_TRAINCTRL6_half_ph_bdl_en_END (22)
#define SOC_HIPACKPHY_TRAINCTRL6_bdlcarry_done_START (23)
#define SOC_HIPACKPHY_TRAINCTRL6_bdlcarry_done_END (23)
#define SOC_HIPACKPHY_TRAINCTRL6_row_react_period_START (24)
#define SOC_HIPACKPHY_TRAINCTRL6_row_react_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int det_pat_index : 4;
        unsigned int det_pat_alt_index : 3;
        unsigned int det_pat_alt_enable : 1;
        unsigned int det_pat_dir : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPACKPHY_DETPATINDEX_UNION;
#endif
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_index_START (0)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_index_END (3)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_alt_index_START (4)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_alt_index_END (6)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_alt_enable_START (7)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_alt_enable_END (7)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_dir_START (8)
#define SOC_HIPACKPHY_DETPATINDEX_det_pat_dir_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdet_ph_fine_step : 3;
        unsigned int reserved_0 : 1;
        unsigned int cat_ph_fine_step : 3;
        unsigned int reserved_1 : 1;
        unsigned int gt_ph_fine_step : 3;
        unsigned int reserved_2 : 1;
        unsigned int wl_ph_fine_step : 3;
        unsigned int reserved_3 : 1;
        unsigned int gt_bdl_step : 4;
        unsigned int gt_ph_step : 4;
        unsigned int wl_bdl_step : 4;
        unsigned int wl_ph_step : 4;
    } reg;
} SOC_HIPACKPHY_TRAINSTEP0_UNION;
#endif
#define SOC_HIPACKPHY_TRAINSTEP0_wdet_ph_fine_step_START (0)
#define SOC_HIPACKPHY_TRAINSTEP0_wdet_ph_fine_step_END (2)
#define SOC_HIPACKPHY_TRAINSTEP0_cat_ph_fine_step_START (4)
#define SOC_HIPACKPHY_TRAINSTEP0_cat_ph_fine_step_END (6)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_ph_fine_step_START (8)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_ph_fine_step_END (10)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_ph_fine_step_START (12)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_ph_fine_step_END (14)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_bdl_step_START (16)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_bdl_step_END (19)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_ph_step_START (20)
#define SOC_HIPACKPHY_TRAINSTEP0_gt_ph_step_END (23)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_bdl_step_START (24)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_bdl_step_END (27)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_ph_step_START (28)
#define SOC_HIPACKPHY_TRAINSTEP0_wl_ph_step_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cat_bdl_step : 4;
        unsigned int cat_ph_step : 4;
        unsigned int cat_lb_backtap : 5;
        unsigned int reserved_0 : 3;
        unsigned int cat_rb_backtap : 5;
        unsigned int reserved_1 : 1;
        unsigned int cat_open_bdl_jstep : 4;
        unsigned int cat_open_ph_jstep : 5;
        unsigned int cat_eye_open_jump_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINSTEP1_UNION;
#endif
#define SOC_HIPACKPHY_TRAINSTEP1_cat_bdl_step_START (0)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_bdl_step_END (3)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_ph_step_START (4)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_ph_step_END (7)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_lb_backtap_START (8)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_lb_backtap_END (12)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_rb_backtap_START (16)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_rb_backtap_END (20)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_open_bdl_jstep_START (22)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_open_bdl_jstep_END (25)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_open_ph_jstep_START (26)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_open_ph_jstep_END (30)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_eye_open_jump_en_START (31)
#define SOC_HIPACKPHY_TRAINSTEP1_cat_eye_open_jump_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdet_bdl_step : 4;
        unsigned int wdet_ph_step : 4;
        unsigned int wdet_lb_backtap : 5;
        unsigned int reserved_0 : 3;
        unsigned int wdet_rb_backtap : 5;
        unsigned int reserved_1 : 1;
        unsigned int wdet_open_bdl_jstep : 4;
        unsigned int wdet_open_ph_jstep : 5;
        unsigned int det_eye_open_jump_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINSTEP2_UNION;
#endif
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_bdl_step_START (0)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_bdl_step_END (3)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_ph_step_START (4)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_ph_step_END (7)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_lb_backtap_START (8)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_lb_backtap_END (12)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_rb_backtap_START (16)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_rb_backtap_END (20)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_open_bdl_jstep_START (22)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_open_bdl_jstep_END (25)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_open_ph_jstep_START (26)
#define SOC_HIPACKPHY_TRAINSTEP2_wdet_open_ph_jstep_END (30)
#define SOC_HIPACKPHY_TRAINSTEP2_det_eye_open_jump_en_START (31)
#define SOC_HIPACKPHY_TRAINSTEP2_det_eye_open_jump_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_cmp_mask : 16;
        unsigned int ba_cmp_mask : 3;
        unsigned int we_cmp_mask : 1;
        unsigned int cas_cmp_mask : 1;
        unsigned int ras_cmp_mask : 1;
        unsigned int cs_cmp_mask : 4;
        unsigned int rst_cmp_mask : 1;
        unsigned int acbist_en : 1;
        unsigned int aclpbk_tg : 1;
        unsigned int ac_rdffsel : 3;
    } reg;
} SOC_HIPACKPHY_ACBISTCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_ACBISTCTRL0_addr_cmp_mask_START (0)
#define SOC_HIPACKPHY_ACBISTCTRL0_addr_cmp_mask_END (15)
#define SOC_HIPACKPHY_ACBISTCTRL0_ba_cmp_mask_START (16)
#define SOC_HIPACKPHY_ACBISTCTRL0_ba_cmp_mask_END (18)
#define SOC_HIPACKPHY_ACBISTCTRL0_we_cmp_mask_START (19)
#define SOC_HIPACKPHY_ACBISTCTRL0_we_cmp_mask_END (19)
#define SOC_HIPACKPHY_ACBISTCTRL0_cas_cmp_mask_START (20)
#define SOC_HIPACKPHY_ACBISTCTRL0_cas_cmp_mask_END (20)
#define SOC_HIPACKPHY_ACBISTCTRL0_ras_cmp_mask_START (21)
#define SOC_HIPACKPHY_ACBISTCTRL0_ras_cmp_mask_END (21)
#define SOC_HIPACKPHY_ACBISTCTRL0_cs_cmp_mask_START (22)
#define SOC_HIPACKPHY_ACBISTCTRL0_cs_cmp_mask_END (25)
#define SOC_HIPACKPHY_ACBISTCTRL0_rst_cmp_mask_START (26)
#define SOC_HIPACKPHY_ACBISTCTRL0_rst_cmp_mask_END (26)
#define SOC_HIPACKPHY_ACBISTCTRL0_acbist_en_START (27)
#define SOC_HIPACKPHY_ACBISTCTRL0_acbist_en_END (27)
#define SOC_HIPACKPHY_ACBISTCTRL0_aclpbk_tg_START (28)
#define SOC_HIPACKPHY_ACBISTCTRL0_aclpbk_tg_END (28)
#define SOC_HIPACKPHY_ACBISTCTRL0_ac_rdffsel_START (29)
#define SOC_HIPACKPHY_ACBISTCTRL0_ac_rdffsel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int odt_cmp_mask : 4;
        unsigned int cke_cmp_mask : 4;
        unsigned int ac_lfsr_seed : 8;
        unsigned int par_cmp_mask : 1;
        unsigned int bg1_cmp_mask : 1;
        unsigned int act_cmp_mask : 1;
        unsigned int prbs_mode : 1;
        unsigned int addro_fp : 1;
        unsigned int cso_fp : 1;
        unsigned int ckeo_fp : 1;
        unsigned int cso_cmp_msk : 4;
        unsigned int ckeo_cmp_msk : 4;
        unsigned int cso_cke0_p1_cmp_msk : 1;
    } reg;
} SOC_HIPACKPHY_ACBISTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_ACBISTCTRL1_odt_cmp_mask_START (0)
#define SOC_HIPACKPHY_ACBISTCTRL1_odt_cmp_mask_END (3)
#define SOC_HIPACKPHY_ACBISTCTRL1_cke_cmp_mask_START (4)
#define SOC_HIPACKPHY_ACBISTCTRL1_cke_cmp_mask_END (7)
#define SOC_HIPACKPHY_ACBISTCTRL1_ac_lfsr_seed_START (8)
#define SOC_HIPACKPHY_ACBISTCTRL1_ac_lfsr_seed_END (15)
#define SOC_HIPACKPHY_ACBISTCTRL1_par_cmp_mask_START (16)
#define SOC_HIPACKPHY_ACBISTCTRL1_par_cmp_mask_END (16)
#define SOC_HIPACKPHY_ACBISTCTRL1_bg1_cmp_mask_START (17)
#define SOC_HIPACKPHY_ACBISTCTRL1_bg1_cmp_mask_END (17)
#define SOC_HIPACKPHY_ACBISTCTRL1_act_cmp_mask_START (18)
#define SOC_HIPACKPHY_ACBISTCTRL1_act_cmp_mask_END (18)
#define SOC_HIPACKPHY_ACBISTCTRL1_prbs_mode_START (19)
#define SOC_HIPACKPHY_ACBISTCTRL1_prbs_mode_END (19)
#define SOC_HIPACKPHY_ACBISTCTRL1_addro_fp_START (20)
#define SOC_HIPACKPHY_ACBISTCTRL1_addro_fp_END (20)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_fp_START (21)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_fp_END (21)
#define SOC_HIPACKPHY_ACBISTCTRL1_ckeo_fp_START (22)
#define SOC_HIPACKPHY_ACBISTCTRL1_ckeo_fp_END (22)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_cmp_msk_START (23)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_cmp_msk_END (26)
#define SOC_HIPACKPHY_ACBISTCTRL1_ckeo_cmp_msk_START (27)
#define SOC_HIPACKPHY_ACBISTCTRL1_ckeo_cmp_msk_END (30)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_cke0_p1_cmp_msk_START (31)
#define SOC_HIPACKPHY_ACBISTCTRL1_cso_cke0_p1_cmp_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_e_bist_err : 16;
        unsigned int ba_bist_err : 3;
        unsigned int we_bist_err : 1;
        unsigned int cas_bist_err : 1;
        unsigned int ras_bist_err : 1;
        unsigned int cs_e_bist_err : 4;
        unsigned int rst_bist_err : 1;
        unsigned int par_bist_err : 1;
        unsigned int bg1_bist_err : 1;
        unsigned int act_bist_err : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_ACBISTSTS0_UNION;
#endif
#define SOC_HIPACKPHY_ACBISTSTS0_addr_e_bist_err_START (0)
#define SOC_HIPACKPHY_ACBISTSTS0_addr_e_bist_err_END (15)
#define SOC_HIPACKPHY_ACBISTSTS0_ba_bist_err_START (16)
#define SOC_HIPACKPHY_ACBISTSTS0_ba_bist_err_END (18)
#define SOC_HIPACKPHY_ACBISTSTS0_we_bist_err_START (19)
#define SOC_HIPACKPHY_ACBISTSTS0_we_bist_err_END (19)
#define SOC_HIPACKPHY_ACBISTSTS0_cas_bist_err_START (20)
#define SOC_HIPACKPHY_ACBISTSTS0_cas_bist_err_END (20)
#define SOC_HIPACKPHY_ACBISTSTS0_ras_bist_err_START (21)
#define SOC_HIPACKPHY_ACBISTSTS0_ras_bist_err_END (21)
#define SOC_HIPACKPHY_ACBISTSTS0_cs_e_bist_err_START (22)
#define SOC_HIPACKPHY_ACBISTSTS0_cs_e_bist_err_END (25)
#define SOC_HIPACKPHY_ACBISTSTS0_rst_bist_err_START (26)
#define SOC_HIPACKPHY_ACBISTSTS0_rst_bist_err_END (26)
#define SOC_HIPACKPHY_ACBISTSTS0_par_bist_err_START (27)
#define SOC_HIPACKPHY_ACBISTSTS0_par_bist_err_END (27)
#define SOC_HIPACKPHY_ACBISTSTS0_bg1_bist_err_START (28)
#define SOC_HIPACKPHY_ACBISTSTS0_bg1_bist_err_END (28)
#define SOC_HIPACKPHY_ACBISTSTS0_act_bist_err_START (29)
#define SOC_HIPACKPHY_ACBISTSTS0_act_bist_err_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int odt_bist_err : 4;
        unsigned int cke_e_bist_err : 4;
        unsigned int cs_o_bist_err : 4;
        unsigned int cke_o_bist_err : 4;
        unsigned int addr_o_bist_err : 16;
    } reg;
} SOC_HIPACKPHY_ACBISTSTS1_UNION;
#endif
#define SOC_HIPACKPHY_ACBISTSTS1_odt_bist_err_START (0)
#define SOC_HIPACKPHY_ACBISTSTS1_odt_bist_err_END (3)
#define SOC_HIPACKPHY_ACBISTSTS1_cke_e_bist_err_START (4)
#define SOC_HIPACKPHY_ACBISTSTS1_cke_e_bist_err_END (7)
#define SOC_HIPACKPHY_ACBISTSTS1_cs_o_bist_err_START (8)
#define SOC_HIPACKPHY_ACBISTSTS1_cs_o_bist_err_END (11)
#define SOC_HIPACKPHY_ACBISTSTS1_cke_o_bist_err_START (12)
#define SOC_HIPACKPHY_ACBISTSTS1_cke_o_bist_err_END (15)
#define SOC_HIPACKPHY_ACBISTSTS1_addr_o_bist_err_START (16)
#define SOC_HIPACKPHY_ACBISTSTS1_addr_o_bist_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdqphase_left_bytelane0 : 8;
        unsigned int wdqphase_left_bytelane1 : 8;
        unsigned int wdq0bdl_left_bytelane0 : 8;
        unsigned int wdq0bdl_left_bytelane1 : 8;
    } reg;
} SOC_HIPACKPHY_WDXBOUND_DFS_UNION;
#endif
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdqphase_left_bytelane0_START (0)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdqphase_left_bytelane0_END (7)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdqphase_left_bytelane1_START (8)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdqphase_left_bytelane1_END (15)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdq0bdl_left_bytelane0_START (16)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdq0bdl_left_bytelane0_END (23)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdq0bdl_left_bytelane1_START (24)
#define SOC_HIPACKPHY_WDXBOUND_DFS_wdq0bdl_left_bytelane1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rg_msp4xratio : 1;
        unsigned int gtfback_inf_clr_en : 1;
        unsigned int gt_90BDL_step_en : 1;
        unsigned int gt_BPT_step_en : 1;
        unsigned int dqsg_track_limit : 7;
        unsigned int rdert_bdl_mode : 1;
        unsigned int rdet_lb_backtap : 4;
        unsigned int rdet_rb_backtap : 9;
        unsigned int IsBypMode : 1;
        unsigned int rdert_comp_en : 1;
        unsigned int fast_shift_step : 2;
        unsigned int fast_check_step : 2;
        unsigned int rdet_dq_rank_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL4_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL4_rg_msp4xratio_START (0)
#define SOC_HIPACKPHY_TRAINCTRL4_rg_msp4xratio_END (0)
#define SOC_HIPACKPHY_TRAINCTRL4_gtfback_inf_clr_en_START (1)
#define SOC_HIPACKPHY_TRAINCTRL4_gtfback_inf_clr_en_END (1)
#define SOC_HIPACKPHY_TRAINCTRL4_gt_90BDL_step_en_START (2)
#define SOC_HIPACKPHY_TRAINCTRL4_gt_90BDL_step_en_END (2)
#define SOC_HIPACKPHY_TRAINCTRL4_gt_BPT_step_en_START (3)
#define SOC_HIPACKPHY_TRAINCTRL4_gt_BPT_step_en_END (3)
#define SOC_HIPACKPHY_TRAINCTRL4_dqsg_track_limit_START (4)
#define SOC_HIPACKPHY_TRAINCTRL4_dqsg_track_limit_END (10)
#define SOC_HIPACKPHY_TRAINCTRL4_rdert_bdl_mode_START (11)
#define SOC_HIPACKPHY_TRAINCTRL4_rdert_bdl_mode_END (11)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_lb_backtap_START (12)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_lb_backtap_END (15)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_rb_backtap_START (16)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_rb_backtap_END (24)
#define SOC_HIPACKPHY_TRAINCTRL4_IsBypMode_START (25)
#define SOC_HIPACKPHY_TRAINCTRL4_IsBypMode_END (25)
#define SOC_HIPACKPHY_TRAINCTRL4_rdert_comp_en_START (26)
#define SOC_HIPACKPHY_TRAINCTRL4_rdert_comp_en_END (26)
#define SOC_HIPACKPHY_TRAINCTRL4_fast_shift_step_START (27)
#define SOC_HIPACKPHY_TRAINCTRL4_fast_shift_step_END (28)
#define SOC_HIPACKPHY_TRAINCTRL4_fast_check_step_START (29)
#define SOC_HIPACKPHY_TRAINCTRL4_fast_check_step_END (30)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_dq_rank_en_START (31)
#define SOC_HIPACKPHY_TRAINCTRL4_rdet_dq_rank_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlym_dummyrd_cnt : 4;
        unsigned int rdet_bdl_step : 2;
        unsigned int rdet_ph_step : 2;
        unsigned int rdet_open_jstep : 4;
        unsigned int tdvalid_wt : 5;
        unsigned int tdvalid_pol_en : 1;
        unsigned int wldqsen : 1;
        unsigned int trainctl_nopostpre : 1;
        unsigned int wdet_mpc_cnt : 4;
        unsigned int cal_alt_num : 3;
        unsigned int dmyrd_onetime : 3;
        unsigned int reserved : 1;
        unsigned int wdert_bdl_mode : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL5_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL5_dlym_dummyrd_cnt_START (0)
#define SOC_HIPACKPHY_TRAINCTRL5_dlym_dummyrd_cnt_END (3)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_bdl_step_START (4)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_bdl_step_END (5)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_ph_step_START (6)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_ph_step_END (7)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_open_jstep_START (8)
#define SOC_HIPACKPHY_TRAINCTRL5_rdet_open_jstep_END (11)
#define SOC_HIPACKPHY_TRAINCTRL5_tdvalid_wt_START (12)
#define SOC_HIPACKPHY_TRAINCTRL5_tdvalid_wt_END (16)
#define SOC_HIPACKPHY_TRAINCTRL5_tdvalid_pol_en_START (17)
#define SOC_HIPACKPHY_TRAINCTRL5_tdvalid_pol_en_END (17)
#define SOC_HIPACKPHY_TRAINCTRL5_wldqsen_START (18)
#define SOC_HIPACKPHY_TRAINCTRL5_wldqsen_END (18)
#define SOC_HIPACKPHY_TRAINCTRL5_trainctl_nopostpre_START (19)
#define SOC_HIPACKPHY_TRAINCTRL5_trainctl_nopostpre_END (19)
#define SOC_HIPACKPHY_TRAINCTRL5_wdet_mpc_cnt_START (20)
#define SOC_HIPACKPHY_TRAINCTRL5_wdet_mpc_cnt_END (23)
#define SOC_HIPACKPHY_TRAINCTRL5_cal_alt_num_START (24)
#define SOC_HIPACKPHY_TRAINCTRL5_cal_alt_num_END (26)
#define SOC_HIPACKPHY_TRAINCTRL5_dmyrd_onetime_START (27)
#define SOC_HIPACKPHY_TRAINCTRL5_dmyrd_onetime_END (29)
#define SOC_HIPACKPHY_TRAINCTRL5_wdert_bdl_mode_START (31)
#define SOC_HIPACKPHY_TRAINCTRL5_wdert_bdl_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mr0_cl_m2 : 4;
        unsigned int dlymeas_upd_rdqsbdl_en : 1;
        unsigned int wlsyncrank_en : 1;
        unsigned int gt_rdbi_handle_en : 1;
        unsigned int gdsrt_mrank_en : 1;
        unsigned int cfg_rl_rdbi_off : 4;
        unsigned int fast_dqsgsl_mrgn : 8;
        unsigned int dlymeas_update_async_mode : 1;
        unsigned int wl_wren_one_rank_handle : 1;
        unsigned int wdqsX_just_one_rank : 1;
        unsigned int dynatrk_rdqsg_ph_step_sel : 1;
        unsigned int dynatrk_rdqsg_cnt_clr_en : 1;
        unsigned int dynatrk_rdqs_cnt_clr_en : 1;
        unsigned int fast_gt_step_sel : 1;
        unsigned int wl_wdqdmbdl_dis : 1;
        unsigned int gds_2rank_en : 1;
        unsigned int trainctl_gtrnowait : 1;
        unsigned int rpt_nomrs : 1;
        unsigned int info_full_tccd_sel : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL7_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL7_mr0_cl_m2_START (0)
#define SOC_HIPACKPHY_TRAINCTRL7_mr0_cl_m2_END (3)
#define SOC_HIPACKPHY_TRAINCTRL7_dlymeas_upd_rdqsbdl_en_START (4)
#define SOC_HIPACKPHY_TRAINCTRL7_dlymeas_upd_rdqsbdl_en_END (4)
#define SOC_HIPACKPHY_TRAINCTRL7_wlsyncrank_en_START (5)
#define SOC_HIPACKPHY_TRAINCTRL7_wlsyncrank_en_END (5)
#define SOC_HIPACKPHY_TRAINCTRL7_gt_rdbi_handle_en_START (6)
#define SOC_HIPACKPHY_TRAINCTRL7_gt_rdbi_handle_en_END (6)
#define SOC_HIPACKPHY_TRAINCTRL7_gdsrt_mrank_en_START (7)
#define SOC_HIPACKPHY_TRAINCTRL7_gdsrt_mrank_en_END (7)
#define SOC_HIPACKPHY_TRAINCTRL7_cfg_rl_rdbi_off_START (8)
#define SOC_HIPACKPHY_TRAINCTRL7_cfg_rl_rdbi_off_END (11)
#define SOC_HIPACKPHY_TRAINCTRL7_fast_dqsgsl_mrgn_START (12)
#define SOC_HIPACKPHY_TRAINCTRL7_fast_dqsgsl_mrgn_END (19)
#define SOC_HIPACKPHY_TRAINCTRL7_dlymeas_update_async_mode_START (20)
#define SOC_HIPACKPHY_TRAINCTRL7_dlymeas_update_async_mode_END (20)
#define SOC_HIPACKPHY_TRAINCTRL7_wl_wren_one_rank_handle_START (21)
#define SOC_HIPACKPHY_TRAINCTRL7_wl_wren_one_rank_handle_END (21)
#define SOC_HIPACKPHY_TRAINCTRL7_wdqsX_just_one_rank_START (22)
#define SOC_HIPACKPHY_TRAINCTRL7_wdqsX_just_one_rank_END (22)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqsg_ph_step_sel_START (23)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqsg_ph_step_sel_END (23)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqsg_cnt_clr_en_START (24)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqsg_cnt_clr_en_END (24)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqs_cnt_clr_en_START (25)
#define SOC_HIPACKPHY_TRAINCTRL7_dynatrk_rdqs_cnt_clr_en_END (25)
#define SOC_HIPACKPHY_TRAINCTRL7_fast_gt_step_sel_START (26)
#define SOC_HIPACKPHY_TRAINCTRL7_fast_gt_step_sel_END (26)
#define SOC_HIPACKPHY_TRAINCTRL7_wl_wdqdmbdl_dis_START (27)
#define SOC_HIPACKPHY_TRAINCTRL7_wl_wdqdmbdl_dis_END (27)
#define SOC_HIPACKPHY_TRAINCTRL7_gds_2rank_en_START (28)
#define SOC_HIPACKPHY_TRAINCTRL7_gds_2rank_en_END (28)
#define SOC_HIPACKPHY_TRAINCTRL7_trainctl_gtrnowait_START (29)
#define SOC_HIPACKPHY_TRAINCTRL7_trainctl_gtrnowait_END (29)
#define SOC_HIPACKPHY_TRAINCTRL7_rpt_nomrs_START (30)
#define SOC_HIPACKPHY_TRAINCTRL7_rpt_nomrs_END (30)
#define SOC_HIPACKPHY_TRAINCTRL7_info_full_tccd_sel_START (31)
#define SOC_HIPACKPHY_TRAINCTRL7_info_full_tccd_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd1tph_right : 8;
        unsigned int cmd1tph_left : 8;
        unsigned int cmd1tph : 8;
        unsigned int cmd1tph_a_ori : 8;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL0_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_right_START (0)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_right_END (7)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_left_START (8)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_left_END (15)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_START (16)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_END (23)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_a_ori_START (24)
#define SOC_HIPACKPHY_ACCMDBDL0_cmd1tph_a_ori_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int zcal_noffset_en : 1;
        unsigned int zcal_poffset_en : 1;
        unsigned int zcal_nadd : 1;
        unsigned int zcal_padd : 1;
        unsigned int zlat_noffset_en : 1;
        unsigned int zlat_poffset_en : 1;
        unsigned int zlat_nadd : 1;
        unsigned int zlat_padd : 1;
        unsigned int zcal_noffset : 4;
        unsigned int zcal_poffset : 4;
        unsigned int zlat_noffset : 4;
        unsigned int zlat_poffset : 4;
        unsigned int zcal_regout_sel : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HIPACKPHY_IMPOFFSET_UNION;
#endif
#define SOC_HIPACKPHY_IMPOFFSET_zcal_noffset_en_START (0)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_noffset_en_END (0)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_poffset_en_START (1)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_poffset_en_END (1)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_nadd_START (2)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_nadd_END (2)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_padd_START (3)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_padd_END (3)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_noffset_en_START (4)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_noffset_en_END (4)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_poffset_en_START (5)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_poffset_en_END (5)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_nadd_START (6)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_nadd_END (6)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_padd_START (7)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_padd_END (7)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_noffset_START (8)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_noffset_END (11)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_poffset_START (12)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_poffset_END (15)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_noffset_START (16)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_noffset_END (19)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_poffset_START (20)
#define SOC_HIPACKPHY_IMPOFFSET_zlat_poffset_END (23)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_regout_sel_START (24)
#define SOC_HIPACKPHY_IMPOFFSET_zcal_regout_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cs0_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int cke0_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL2_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL2_cs0_bdl_START (0)
#define SOC_HIPACKPHY_ACCMDBDL2_cs0_bdl_END (9)
#define SOC_HIPACKPHY_ACCMDBDL2_cke0_bdl_START (16)
#define SOC_HIPACKPHY_ACCMDBDL2_cke0_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cs1_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int cke1_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL3_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL3_cs1_bdl_START (0)
#define SOC_HIPACKPHY_ACCMDBDL3_cs1_bdl_END (9)
#define SOC_HIPACKPHY_ACCMDBDL3_cke1_bdl_START (16)
#define SOC_HIPACKPHY_ACCMDBDL3_cke1_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_msp430_ctrl0 : 32;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL5_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL5_reg_msp430_ctrl0_START (0)
#define SOC_HIPACKPHY_ACCMDBDL5_reg_msp430_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int we_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int cas_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL6_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL6_we_bdl_START (0)
#define SOC_HIPACKPHY_ACCMDBDL6_we_bdl_END (9)
#define SOC_HIPACKPHY_ACCMDBDL6_cas_bdl_START (16)
#define SOC_HIPACKPHY_ACCMDBDL6_cas_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ras_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int resetn_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_ACCMDBDL7_UNION;
#endif
#define SOC_HIPACKPHY_ACCMDBDL7_ras_bdl_START (0)
#define SOC_HIPACKPHY_ACCMDBDL7_ras_bdl_END (9)
#define SOC_HIPACKPHY_ACCMDBDL7_resetn_bdl_START (16)
#define SOC_HIPACKPHY_ACCMDBDL7_resetn_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr0_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int addr1_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL0_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL0_addr0_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL0_addr0_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL0_addr1_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL0_addr1_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr2_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int addr3_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL1_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL1_addr2_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL1_addr2_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL1_addr3_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL1_addr3_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr4_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int addr5_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL2_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL2_addr4_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL2_addr4_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL2_addr5_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL2_addr5_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr6_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int addr7_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL3_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL3_addr6_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL3_addr6_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL3_addr7_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL3_addr7_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr8_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int addr9_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL4_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL4_addr8_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL4_addr8_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL4_addr9_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL4_addr9_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr10_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int addr11_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL5_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL5_addr10_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL5_addr10_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL5_addr11_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL5_addr11_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr12_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int addr13_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL6_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL6_addr12_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL6_addr12_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL6_addr13_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL6_addr13_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr14_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int addr15_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL7_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL7_addr14_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL7_addr14_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL7_addr15_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL7_addr15_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ba0_bdl : 10;
        unsigned int reserved_0: 6;
        unsigned int ba1_bdl : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL8_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL8_ba0_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL8_ba0_bdl_END (9)
#define SOC_HIPACKPHY_ACADDRBDL8_ba1_bdl_START (16)
#define SOC_HIPACKPHY_ACADDRBDL8_ba1_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ba2_bdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPACKPHY_ACADDRBDL9_UNION;
#endif
#define SOC_HIPACKPHY_ACADDRBDL9_ba2_bdl_START (0)
#define SOC_HIPACKPHY_ACADDRBDL9_ba2_bdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_lpbk_data_sl : 2;
        unsigned int cfg_prbs_mode : 1;
        unsigned int reserved : 27;
        unsigned int aclpbk_cmdlp_mode : 1;
        unsigned int acbst_odd_main_msk : 1;
    } reg;
} SOC_HIPACKPHY_ACBISTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_ACBISTCTRL2_ac_lpbk_data_sl_START (0)
#define SOC_HIPACKPHY_ACBISTCTRL2_ac_lpbk_data_sl_END (1)
#define SOC_HIPACKPHY_ACBISTCTRL2_cfg_prbs_mode_START (2)
#define SOC_HIPACKPHY_ACBISTCTRL2_cfg_prbs_mode_END (2)
#define SOC_HIPACKPHY_ACBISTCTRL2_aclpbk_cmdlp_mode_START (30)
#define SOC_HIPACKPHY_ACBISTCTRL2_aclpbk_cmdlp_mode_END (30)
#define SOC_HIPACKPHY_ACBISTCTRL2_acbst_odd_main_msk_START (31)
#define SOC_HIPACKPHY_ACBISTCTRL2_acbst_odd_main_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jtmt_period : 6;
        unsigned int jtmt_err : 1;
        unsigned int jtmt_loop_en : 1;
        unsigned int jtmt_period_limit : 6;
        unsigned int jtmt_period_latch : 1;
        unsigned int reserved_0 : 1;
        unsigned int cfg_pll_test_mode : 8;
        unsigned int jtmt_clkbdl_ub : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_HIPACKPHY_PLLJTMT_UNION;
#endif
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_START (0)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_END (5)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_err_START (6)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_err_END (6)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_loop_en_START (7)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_loop_en_END (7)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_limit_START (8)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_limit_END (13)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_latch_START (14)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_period_latch_END (14)
#define SOC_HIPACKPHY_PLLJTMT_cfg_pll_test_mode_START (16)
#define SOC_HIPACKPHY_PLLJTMT_cfg_pll_test_mode_END (23)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_clkbdl_ub_START (24)
#define SOC_HIPACKPHY_PLLJTMT_jtmt_clkbdl_ub_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_vddq_cal_mode : 3;
        unsigned int dx_vddq_cal_mode : 3;
        unsigned int sw_zq_mode : 3;
        unsigned int sw_ac_zq_sel : 1;
        unsigned int sw_zq_dx_out_en : 1;
        unsigned int sw_zq_ac_out_en : 1;
        unsigned int sw_zq_select : 1;
        unsigned int sw_zq_enable : 1;
        unsigned int sw_zq_reset : 1;
        unsigned int sw_zqcal_en : 1;
        unsigned int zcal_sel : 1;
        unsigned int zcal_tie_lsb : 1;
        unsigned int zcal_ndrv_regsel : 1;
        unsigned int zcal_pdrv_regsel : 1;
        unsigned int acctl_ndrv_regsel : 1;
        unsigned int acctl_pdrv_regsel : 1;
        unsigned int ac_vddq_cal_en : 1;
        unsigned int cfg_pdrv_msb_dummy : 1;
        unsigned int zcal_en_count : 4;
        unsigned int cfg_tzcomp_prep : 3;
        unsigned int zcomp_result : 1;
    } reg;
} SOC_HIPACKPHY_IMP_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_IMP_CTRL1_ac_vddq_cal_mode_START (0)
#define SOC_HIPACKPHY_IMP_CTRL1_ac_vddq_cal_mode_END (2)
#define SOC_HIPACKPHY_IMP_CTRL1_dx_vddq_cal_mode_START (3)
#define SOC_HIPACKPHY_IMP_CTRL1_dx_vddq_cal_mode_END (5)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_mode_START (6)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_mode_END (8)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_ac_zq_sel_START (9)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_ac_zq_sel_END (9)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_dx_out_en_START (10)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_dx_out_en_END (10)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_ac_out_en_START (11)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_ac_out_en_END (11)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_select_START (12)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_select_END (12)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_enable_START (13)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_enable_END (13)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_reset_START (14)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zq_reset_END (14)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zqcal_en_START (15)
#define SOC_HIPACKPHY_IMP_CTRL1_sw_zqcal_en_END (15)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_sel_START (16)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_sel_END (16)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_tie_lsb_START (17)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_tie_lsb_END (17)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_ndrv_regsel_START (18)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_ndrv_regsel_END (18)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_pdrv_regsel_START (19)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_pdrv_regsel_END (19)
#define SOC_HIPACKPHY_IMP_CTRL1_acctl_ndrv_regsel_START (20)
#define SOC_HIPACKPHY_IMP_CTRL1_acctl_ndrv_regsel_END (20)
#define SOC_HIPACKPHY_IMP_CTRL1_acctl_pdrv_regsel_START (21)
#define SOC_HIPACKPHY_IMP_CTRL1_acctl_pdrv_regsel_END (21)
#define SOC_HIPACKPHY_IMP_CTRL1_ac_vddq_cal_en_START (22)
#define SOC_HIPACKPHY_IMP_CTRL1_ac_vddq_cal_en_END (22)
#define SOC_HIPACKPHY_IMP_CTRL1_cfg_pdrv_msb_dummy_START (23)
#define SOC_HIPACKPHY_IMP_CTRL1_cfg_pdrv_msb_dummy_END (23)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_en_count_START (24)
#define SOC_HIPACKPHY_IMP_CTRL1_zcal_en_count_END (27)
#define SOC_HIPACKPHY_IMP_CTRL1_cfg_tzcomp_prep_START (28)
#define SOC_HIPACKPHY_IMP_CTRL1_cfg_tzcomp_prep_END (30)
#define SOC_HIPACKPHY_IMP_CTRL1_zcomp_result_START (31)
#define SOC_HIPACKPHY_IMP_CTRL1_zcomp_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acctl_ndrv_cal : 7;
        unsigned int reserved_0 : 1;
        unsigned int acctl_pdrv_cal : 8;
        unsigned int acctl_ndrv_latch : 6;
        unsigned int reserved_1 : 2;
        unsigned int acctl_pdrv_latch : 7;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_HIPACKPHY_IMP_STATUS1_UNION;
#endif
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_ndrv_cal_START (0)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_ndrv_cal_END (6)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_pdrv_cal_START (8)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_pdrv_cal_END (15)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_ndrv_latch_START (16)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_ndrv_latch_END (21)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_pdrv_latch_START (24)
#define SOC_HIPACKPHY_IMP_STATUS1_acctl_pdrv_latch_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ioctl_dx_ndrv_out : 6;
        unsigned int reserved_0 : 2;
        unsigned int ioctl_dx_pdrv_out : 7;
        unsigned int reserved_1 : 1;
        unsigned int ioctl_ac_ndrv_out : 6;
        unsigned int reserved_2 : 2;
        unsigned int ioctl_ac_pdrv_out : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_HIPACKPHY_IMP_OUT_UNION;
#endif
#define SOC_HIPACKPHY_IMP_OUT_ioctl_dx_ndrv_out_START (0)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_dx_ndrv_out_END (5)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_dx_pdrv_out_START (8)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_dx_pdrv_out_END (14)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_ac_ndrv_out_START (16)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_ac_ndrv_out_END (21)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_ac_pdrv_out_START (24)
#define SOC_HIPACKPHY_IMP_OUT_ioctl_ac_pdrv_out_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rpat_cnt_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int wpat_cnt_num : 6;
        unsigned int reserved_1 : 1;
        unsigned int cfg_wecct_en : 1;
        unsigned int rpat_cnt_num_open : 6;
        unsigned int reserved_2 : 2;
        unsigned int wpat_cnt_num_open : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL11_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL11_rpat_cnt_num_START (0)
#define SOC_HIPACKPHY_TRAINCTRL11_rpat_cnt_num_END (5)
#define SOC_HIPACKPHY_TRAINCTRL11_wpat_cnt_num_START (8)
#define SOC_HIPACKPHY_TRAINCTRL11_wpat_cnt_num_END (13)
#define SOC_HIPACKPHY_TRAINCTRL11_cfg_wecct_en_START (15)
#define SOC_HIPACKPHY_TRAINCTRL11_cfg_wecct_en_END (15)
#define SOC_HIPACKPHY_TRAINCTRL11_rpat_cnt_num_open_START (16)
#define SOC_HIPACKPHY_TRAINCTRL11_rpat_cnt_num_open_END (21)
#define SOC_HIPACKPHY_TRAINCTRL11_wpat_cnt_num_open_START (24)
#define SOC_HIPACKPHY_TRAINCTRL11_wpat_cnt_num_open_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_HIPACKPHY_FASTGDSRESULT0_UNION;
#endif
#define SOC_HIPACKPHY_FASTGDSRESULT0_fast_gds_result_START (0)
#define SOC_HIPACKPHY_FASTGDSRESULT0_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_HIPACKPHY_FASTGDSRESULT1_UNION;
#endif
#define SOC_HIPACKPHY_FASTGDSRESULT1_fast_gds_result_START (0)
#define SOC_HIPACKPHY_FASTGDSRESULT1_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gt_decgress : 8;
        unsigned int fast_gt_incgress : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_FASTGTRESULT_UNION;
#endif
#define SOC_HIPACKPHY_FASTGTRESULT_fast_gt_decgress_START (0)
#define SOC_HIPACKPHY_FASTGTRESULT_fast_gt_decgress_END (7)
#define SOC_HIPACKPHY_FASTGTRESULT_fast_gt_incgress_START (8)
#define SOC_HIPACKPHY_FASTGTRESULT_fast_gt_incgress_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_rdata : 32;
    } reg;
} SOC_HIPACKPHY_TRKDBG_UNION;
#endif
#define SOC_HIPACKPHY_TRKDBG_trkdbg_rdata_START (0)
#define SOC_HIPACKPHY_TRKDBG_trkdbg_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int det_err_state : 8;
        unsigned int cat_err_state : 6;
        unsigned int status_lowpri_peek : 1;
        unsigned int err_state_peek : 1;
        unsigned int cdgc_cmpres : 9;
        unsigned int packcnt_clr : 1;
        unsigned int dxndqnlb_sel : 2;
        unsigned int cdgc_cmpres_sel : 3;
        unsigned int bound_info_clr_en : 1;
    } reg;
} SOC_HIPACKPHY_PACKDEBUG_UNION;
#endif
#define SOC_HIPACKPHY_PACKDEBUG_det_err_state_START (0)
#define SOC_HIPACKPHY_PACKDEBUG_det_err_state_END (7)
#define SOC_HIPACKPHY_PACKDEBUG_cat_err_state_START (8)
#define SOC_HIPACKPHY_PACKDEBUG_cat_err_state_END (13)
#define SOC_HIPACKPHY_PACKDEBUG_status_lowpri_peek_START (14)
#define SOC_HIPACKPHY_PACKDEBUG_status_lowpri_peek_END (14)
#define SOC_HIPACKPHY_PACKDEBUG_err_state_peek_START (15)
#define SOC_HIPACKPHY_PACKDEBUG_err_state_peek_END (15)
#define SOC_HIPACKPHY_PACKDEBUG_cdgc_cmpres_START (16)
#define SOC_HIPACKPHY_PACKDEBUG_cdgc_cmpres_END (24)
#define SOC_HIPACKPHY_PACKDEBUG_packcnt_clr_START (25)
#define SOC_HIPACKPHY_PACKDEBUG_packcnt_clr_END (25)
#define SOC_HIPACKPHY_PACKDEBUG_dxndqnlb_sel_START (26)
#define SOC_HIPACKPHY_PACKDEBUG_dxndqnlb_sel_END (27)
#define SOC_HIPACKPHY_PACKDEBUG_cdgc_cmpres_sel_START (28)
#define SOC_HIPACKPHY_PACKDEBUG_cdgc_cmpres_sel_END (30)
#define SOC_HIPACKPHY_PACKDEBUG_bound_info_clr_en_START (31)
#define SOC_HIPACKPHY_PACKDEBUG_bound_info_clr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_wdet_en : 1;
        unsigned int ph_mask_en : 1;
        unsigned int wdet_lb_ctdone_stop : 1;
        unsigned int rdet_lb_ctdone_stop : 1;
        unsigned int wdet_byp_mode : 1;
        unsigned int non_odt_mode_en : 1;
        unsigned int trkdbg_ro_sel : 4;
        unsigned int dyn_track_trans_en : 1;
        unsigned int mc_eff_blk_dis : 1;
        unsigned int ac_rsv_control_13_12 : 2;
        unsigned int pack_mc_sel_dis : 1;
        unsigned int ac_rsv_control_15 : 1;
        unsigned int wdet_ave_comp_en : 1;
        unsigned int wdet_rb2nd_fine_en : 1;
        unsigned int apb_err_type : 1;
        unsigned int wopen_ovflow_handle : 1;
        unsigned int lp4_mrw_sp_dec_en : 1;
        unsigned int acctl_drv_sel : 1;
        unsigned int cat_eyeopen_fclr_en : 1;
        unsigned int wl_mode_tx_gated_en : 1;
        unsigned int non_odt_ndrv : 6;
        unsigned int phyupdtimer_clr_en : 1;
        unsigned int aclpbkmode_exd_en : 1;
    } reg;
} SOC_HIPACKPHY_ACPHYRSVDC_UNION;
#endif
#define SOC_HIPACKPHY_ACPHYRSVDC_fast_wdet_en_START (0)
#define SOC_HIPACKPHY_ACPHYRSVDC_fast_wdet_en_END (0)
#define SOC_HIPACKPHY_ACPHYRSVDC_ph_mask_en_START (1)
#define SOC_HIPACKPHY_ACPHYRSVDC_ph_mask_en_END (1)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_lb_ctdone_stop_START (2)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_lb_ctdone_stop_END (2)
#define SOC_HIPACKPHY_ACPHYRSVDC_rdet_lb_ctdone_stop_START (3)
#define SOC_HIPACKPHY_ACPHYRSVDC_rdet_lb_ctdone_stop_END (3)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_byp_mode_START (4)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_byp_mode_END (4)
#define SOC_HIPACKPHY_ACPHYRSVDC_non_odt_mode_en_START (5)
#define SOC_HIPACKPHY_ACPHYRSVDC_non_odt_mode_en_END (5)
#define SOC_HIPACKPHY_ACPHYRSVDC_trkdbg_ro_sel_START (6)
#define SOC_HIPACKPHY_ACPHYRSVDC_trkdbg_ro_sel_END (9)
#define SOC_HIPACKPHY_ACPHYRSVDC_dyn_track_trans_en_START (10)
#define SOC_HIPACKPHY_ACPHYRSVDC_dyn_track_trans_en_END (10)
#define SOC_HIPACKPHY_ACPHYRSVDC_mc_eff_blk_dis_START (11)
#define SOC_HIPACKPHY_ACPHYRSVDC_mc_eff_blk_dis_END (11)
#define SOC_HIPACKPHY_ACPHYRSVDC_ac_rsv_control_13_12_START (12)
#define SOC_HIPACKPHY_ACPHYRSVDC_ac_rsv_control_13_12_END (13)
#define SOC_HIPACKPHY_ACPHYRSVDC_pack_mc_sel_dis_START (14)
#define SOC_HIPACKPHY_ACPHYRSVDC_pack_mc_sel_dis_END (14)
#define SOC_HIPACKPHY_ACPHYRSVDC_ac_rsv_control_15_START (15)
#define SOC_HIPACKPHY_ACPHYRSVDC_ac_rsv_control_15_END (15)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_ave_comp_en_START (16)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_ave_comp_en_END (16)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_rb2nd_fine_en_START (17)
#define SOC_HIPACKPHY_ACPHYRSVDC_wdet_rb2nd_fine_en_END (17)
#define SOC_HIPACKPHY_ACPHYRSVDC_apb_err_type_START (18)
#define SOC_HIPACKPHY_ACPHYRSVDC_apb_err_type_END (18)
#define SOC_HIPACKPHY_ACPHYRSVDC_wopen_ovflow_handle_START (19)
#define SOC_HIPACKPHY_ACPHYRSVDC_wopen_ovflow_handle_END (19)
#define SOC_HIPACKPHY_ACPHYRSVDC_lp4_mrw_sp_dec_en_START (20)
#define SOC_HIPACKPHY_ACPHYRSVDC_lp4_mrw_sp_dec_en_END (20)
#define SOC_HIPACKPHY_ACPHYRSVDC_acctl_drv_sel_START (21)
#define SOC_HIPACKPHY_ACPHYRSVDC_acctl_drv_sel_END (21)
#define SOC_HIPACKPHY_ACPHYRSVDC_cat_eyeopen_fclr_en_START (22)
#define SOC_HIPACKPHY_ACPHYRSVDC_cat_eyeopen_fclr_en_END (22)
#define SOC_HIPACKPHY_ACPHYRSVDC_wl_mode_tx_gated_en_START (23)
#define SOC_HIPACKPHY_ACPHYRSVDC_wl_mode_tx_gated_en_END (23)
#define SOC_HIPACKPHY_ACPHYRSVDC_non_odt_ndrv_START (24)
#define SOC_HIPACKPHY_ACPHYRSVDC_non_odt_ndrv_END (29)
#define SOC_HIPACKPHY_ACPHYRSVDC_phyupdtimer_clr_en_START (30)
#define SOC_HIPACKPHY_ACPHYRSVDC_phyupdtimer_clr_en_END (30)
#define SOC_HIPACKPHY_ACPHYRSVDC_aclpbkmode_exd_en_START (31)
#define SOC_HIPACKPHY_ACPHYRSVDC_aclpbkmode_exd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_msp430_ctrl1 : 32;
    } reg;
} SOC_HIPACKPHY_ACPHYRSVDS_UNION;
#endif
#define SOC_HIPACKPHY_ACPHYRSVDS_reg_msp430_ctrl1_START (0)
#define SOC_HIPACKPHY_ACPHYRSVDS_reg_msp430_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_mrr_data_selected : 16;
        unsigned int reserved_0 : 8;
        unsigned int sw_mrr_data_byte_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_mrr_data_burst_sel : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HIPACKPHY_SWMRRDATA_UNION;
#endif
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_selected_START (0)
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_selected_END (15)
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_byte_sel_START (24)
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_byte_sel_END (26)
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_burst_sel_START (28)
#define SOC_HIPACKPHY_SWMRRDATA_sw_mrr_data_burst_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tWCKENL_RD : 8;
        unsigned int tWCKENL_WR : 8;
        unsigned int tWCKENL_FS : 8;
        unsigned int reserved : 1;
        unsigned int wckenrkswen_type : 1;
        unsigned int wckenrkswen : 1;
        unsigned int wck_free_run : 1;
        unsigned int ctl_wck_bypass : 1;
        unsigned int wcksync_mode : 1;
        unsigned int wck2ck_ratio2 : 1;
        unsigned int bl32_bubble : 1;
    } reg;
} SOC_HIPACKPHY_WCKCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_RD_START (0)
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_RD_END (7)
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_WR_START (8)
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_WR_END (15)
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_FS_START (16)
#define SOC_HIPACKPHY_WCKCTRL0_tWCKENL_FS_END (23)
#define SOC_HIPACKPHY_WCKCTRL0_wckenrkswen_type_START (25)
#define SOC_HIPACKPHY_WCKCTRL0_wckenrkswen_type_END (25)
#define SOC_HIPACKPHY_WCKCTRL0_wckenrkswen_START (26)
#define SOC_HIPACKPHY_WCKCTRL0_wckenrkswen_END (26)
#define SOC_HIPACKPHY_WCKCTRL0_wck_free_run_START (27)
#define SOC_HIPACKPHY_WCKCTRL0_wck_free_run_END (27)
#define SOC_HIPACKPHY_WCKCTRL0_ctl_wck_bypass_START (28)
#define SOC_HIPACKPHY_WCKCTRL0_ctl_wck_bypass_END (28)
#define SOC_HIPACKPHY_WCKCTRL0_wcksync_mode_START (29)
#define SOC_HIPACKPHY_WCKCTRL0_wcksync_mode_END (29)
#define SOC_HIPACKPHY_WCKCTRL0_wck2ck_ratio2_START (30)
#define SOC_HIPACKPHY_WCKCTRL0_wck2ck_ratio2_END (30)
#define SOC_HIPACKPHY_WCKCTRL0_bl32_bubble_START (31)
#define SOC_HIPACKPHY_WCKCTRL0_bl32_bubble_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tWCKPRE_TG_RD : 8;
        unsigned int tWCKPRE_TG_WR : 8;
        unsigned int tWCKPRE_Static : 8;
        unsigned int tWCKPST_IND : 2;
        unsigned int reserved : 1;
        unsigned int WCK_offset : 5;
    } reg;
} SOC_HIPACKPHY_WCKCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_TG_RD_START (0)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_TG_RD_END (7)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_TG_WR_START (8)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_TG_WR_END (15)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_Static_START (16)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPRE_Static_END (23)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPST_IND_START (24)
#define SOC_HIPACKPHY_WCKCTRL1_tWCKPST_IND_END (25)
#define SOC_HIPACKPHY_WCKCTRL1_WCK_offset_START (27)
#define SOC_HIPACKPHY_WCKCTRL1_WCK_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int gt_trace_en : 1;
        unsigned int gt_trace_go : 1;
        unsigned int devmode_dbg_ptr : 4;
        unsigned int devmode_dbg_wen : 1;
        unsigned int devmode_rw_switch : 1;
        unsigned int devmode_dir_ptr : 8;
    } reg;
} SOC_HIPACKPHY_DEVMODECFG_UNION;
#endif
#define SOC_HIPACKPHY_DEVMODECFG_gt_trace_en_START (16)
#define SOC_HIPACKPHY_DEVMODECFG_gt_trace_en_END (16)
#define SOC_HIPACKPHY_DEVMODECFG_gt_trace_go_START (17)
#define SOC_HIPACKPHY_DEVMODECFG_gt_trace_go_END (17)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dbg_ptr_START (18)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dbg_ptr_END (21)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dbg_wen_START (22)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dbg_wen_END (22)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_rw_switch_START (23)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_rw_switch_END (23)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dir_ptr_START (24)
#define SOC_HIPACKPHY_DEVMODECFG_devmode_dir_ptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gcken_jtmt : 1;
        unsigned int gcken_phyinit : 1;
        unsigned int gcken_aref : 1;
        unsigned int gcken_reg_sync_upd : 1;
        unsigned int gcken_dly_mng : 1;
        unsigned int gckdis_mc : 1;
        unsigned int gcken_rdaligh : 1;
        unsigned int lp_phy_gcken_ext_cnt : 3;
        unsigned int reserved_0 : 1;
        unsigned int phy_clkg_oe_tsys_dis : 1;
        unsigned int WCKgated_dig_hw_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int devmode_dbg_data : 18;
    } reg;
} SOC_HIPACKPHY_LPCTRL3_UNION;
#endif
#define SOC_HIPACKPHY_LPCTRL3_gcken_jtmt_START (0)
#define SOC_HIPACKPHY_LPCTRL3_gcken_jtmt_END (0)
#define SOC_HIPACKPHY_LPCTRL3_gcken_phyinit_START (1)
#define SOC_HIPACKPHY_LPCTRL3_gcken_phyinit_END (1)
#define SOC_HIPACKPHY_LPCTRL3_gcken_aref_START (2)
#define SOC_HIPACKPHY_LPCTRL3_gcken_aref_END (2)
#define SOC_HIPACKPHY_LPCTRL3_gcken_reg_sync_upd_START (3)
#define SOC_HIPACKPHY_LPCTRL3_gcken_reg_sync_upd_END (3)
#define SOC_HIPACKPHY_LPCTRL3_gcken_dly_mng_START (4)
#define SOC_HIPACKPHY_LPCTRL3_gcken_dly_mng_END (4)
#define SOC_HIPACKPHY_LPCTRL3_gckdis_mc_START (5)
#define SOC_HIPACKPHY_LPCTRL3_gckdis_mc_END (5)
#define SOC_HIPACKPHY_LPCTRL3_gcken_rdaligh_START (6)
#define SOC_HIPACKPHY_LPCTRL3_gcken_rdaligh_END (6)
#define SOC_HIPACKPHY_LPCTRL3_lp_phy_gcken_ext_cnt_START (7)
#define SOC_HIPACKPHY_LPCTRL3_lp_phy_gcken_ext_cnt_END (9)
#define SOC_HIPACKPHY_LPCTRL3_phy_clkg_oe_tsys_dis_START (11)
#define SOC_HIPACKPHY_LPCTRL3_phy_clkg_oe_tsys_dis_END (11)
#define SOC_HIPACKPHY_LPCTRL3_WCKgated_dig_hw_en_START (12)
#define SOC_HIPACKPHY_LPCTRL3_WCKgated_dig_hw_en_END (12)
#define SOC_HIPACKPHY_LPCTRL3_devmode_dbg_data_START (14)
#define SOC_HIPACKPHY_LPCTRL3_devmode_dbg_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pst_forb_cas_cnt : 3;
        unsigned int reserved_0 : 1;
        unsigned int pre_forb_cas_cnt : 3;
        unsigned int reserved_1 : 1;
        unsigned int cfg_ckdata_tick_sel : 1;
        unsigned int wck_is_sync : 1;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_HIPACKPHY_WCKCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_WCKCTRL2_pst_forb_cas_cnt_START (0)
#define SOC_HIPACKPHY_WCKCTRL2_pst_forb_cas_cnt_END (2)
#define SOC_HIPACKPHY_WCKCTRL2_pre_forb_cas_cnt_START (4)
#define SOC_HIPACKPHY_WCKCTRL2_pre_forb_cas_cnt_END (6)
#define SOC_HIPACKPHY_WCKCTRL2_cfg_ckdata_tick_sel_START (8)
#define SOC_HIPACKPHY_WCKCTRL2_cfg_ckdata_tick_sel_END (8)
#define SOC_HIPACKPHY_WCKCTRL2_wck_is_sync_START (9)
#define SOC_HIPACKPHY_WCKCTRL2_wck_is_sync_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addrbdl_a_right : 10;
        unsigned int reserved_0 : 2;
        unsigned int addrbdl_bound_sel : 4;
        unsigned int addrbdl_a_left : 10;
        unsigned int reserved_1 : 5;
        unsigned int cat_ave_comp_flag : 1;
    } reg;
} SOC_HIPACKPHY_CATBDLBOUND_UNION;
#endif
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_a_right_START (0)
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_a_right_END (9)
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_bound_sel_START (12)
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_bound_sel_END (15)
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_a_left_START (16)
#define SOC_HIPACKPHY_CATBDLBOUND_addrbdl_a_left_END (25)
#define SOC_HIPACKPHY_CATBDLBOUND_cat_ave_comp_flag_START (31)
#define SOC_HIPACKPHY_CATBDLBOUND_cat_ave_comp_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cat_swap_index : 4;
        unsigned int reserved_0 : 8;
        unsigned int cfg_enh_exit_mrop : 8;
        unsigned int cfg_enh_entr_mrop : 8;
        unsigned int reserved_1 : 3;
        unsigned int cat_swap_legacy : 1;
    } reg;
} SOC_HIPACKPHY_CATSWAPINDEX_UNION;
#endif
#define SOC_HIPACKPHY_CATSWAPINDEX_cat_swap_index_START (0)
#define SOC_HIPACKPHY_CATSWAPINDEX_cat_swap_index_END (3)
#define SOC_HIPACKPHY_CATSWAPINDEX_cfg_enh_exit_mrop_START (12)
#define SOC_HIPACKPHY_CATSWAPINDEX_cfg_enh_exit_mrop_END (19)
#define SOC_HIPACKPHY_CATSWAPINDEX_cfg_enh_entr_mrop_START (20)
#define SOC_HIPACKPHY_CATSWAPINDEX_cfg_enh_entr_mrop_END (27)
#define SOC_HIPACKPHY_CATSWAPINDEX_cat_swap_legacy_START (31)
#define SOC_HIPACKPHY_CATSWAPINDEX_cat_swap_legacy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cat_swap_sel : 32;
    } reg;
} SOC_HIPACKPHY_CATSWAPSEL_UNION;
#endif
#define SOC_HIPACKPHY_CATSWAPSEL_cat_swap_sel_START (0)
#define SOC_HIPACKPHY_CATSWAPSEL_cat_swap_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcackel : 6;
        unsigned int tcacd_exd : 2;
        unsigned int tcaent : 8;
        unsigned int tcacd : 8;
        unsigned int tcackeh : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_CATTIMER0_UNION;
#endif
#define SOC_HIPACKPHY_CATTIMER0_tcackel_START (0)
#define SOC_HIPACKPHY_CATTIMER0_tcackel_END (5)
#define SOC_HIPACKPHY_CATTIMER0_tcacd_exd_START (6)
#define SOC_HIPACKPHY_CATTIMER0_tcacd_exd_END (7)
#define SOC_HIPACKPHY_CATTIMER0_tcaent_START (8)
#define SOC_HIPACKPHY_CATTIMER0_tcaent_END (15)
#define SOC_HIPACKPHY_CATTIMER0_tcacd_START (16)
#define SOC_HIPACKPHY_CATTIMER0_tcacd_END (23)
#define SOC_HIPACKPHY_CATTIMER0_tcackeh_START (24)
#define SOC_HIPACKPHY_CATTIMER0_tcackeh_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcaext : 8;
        unsigned int tmrz : 6;
        unsigned int reserved_0: 2;
        unsigned int tadr : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_CATTIMER1_UNION;
#endif
#define SOC_HIPACKPHY_CATTIMER1_tcaext_START (0)
#define SOC_HIPACKPHY_CATTIMER1_tcaext_END (7)
#define SOC_HIPACKPHY_CATTIMER1_tmrz_START (8)
#define SOC_HIPACKPHY_CATTIMER1_tmrz_END (13)
#define SOC_HIPACKPHY_CATTIMER1_tadr_START (16)
#define SOC_HIPACKPHY_CATTIMER1_tadr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ca_samp_num_bdl : 8;
        unsigned int ca_samp_num_ph : 8;
        unsigned int sw_cat_eyet : 1;
        unsigned int cat_openeye_en : 1;
        unsigned int cat_cat_phydq_sel : 1;
        unsigned int cat_restore_en : 1;
        unsigned int cat_ave_comp_en : 1;
        unsigned int cat_rb2nd_fine_en : 1;
        unsigned int sw_cst_mode : 1;
        unsigned int reserved : 1;
        unsigned int sw_cat_mrw42 : 1;
        unsigned int sw_cat_mrw48 : 1;
        unsigned int sw_cat_mrw41 : 1;
        unsigned int sw_cat_strobe : 1;
        unsigned int sw_cat_cke_high : 1;
        unsigned int sw_cat_cke_low : 1;
        unsigned int sw_cat_dqvalid : 1;
        unsigned int sw_cat_en : 1;
    } reg;
} SOC_HIPACKPHY_CATCONFIG_UNION;
#endif
#define SOC_HIPACKPHY_CATCONFIG_ca_samp_num_bdl_START (0)
#define SOC_HIPACKPHY_CATCONFIG_ca_samp_num_bdl_END (7)
#define SOC_HIPACKPHY_CATCONFIG_ca_samp_num_ph_START (8)
#define SOC_HIPACKPHY_CATCONFIG_ca_samp_num_ph_END (15)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_eyet_START (16)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_eyet_END (16)
#define SOC_HIPACKPHY_CATCONFIG_cat_openeye_en_START (17)
#define SOC_HIPACKPHY_CATCONFIG_cat_openeye_en_END (17)
#define SOC_HIPACKPHY_CATCONFIG_cat_cat_phydq_sel_START (18)
#define SOC_HIPACKPHY_CATCONFIG_cat_cat_phydq_sel_END (18)
#define SOC_HIPACKPHY_CATCONFIG_cat_restore_en_START (19)
#define SOC_HIPACKPHY_CATCONFIG_cat_restore_en_END (19)
#define SOC_HIPACKPHY_CATCONFIG_cat_ave_comp_en_START (20)
#define SOC_HIPACKPHY_CATCONFIG_cat_ave_comp_en_END (20)
#define SOC_HIPACKPHY_CATCONFIG_cat_rb2nd_fine_en_START (21)
#define SOC_HIPACKPHY_CATCONFIG_cat_rb2nd_fine_en_END (21)
#define SOC_HIPACKPHY_CATCONFIG_sw_cst_mode_START (22)
#define SOC_HIPACKPHY_CATCONFIG_sw_cst_mode_END (22)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw42_START (24)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw42_END (24)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw48_START (25)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw48_END (25)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw41_START (26)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_mrw41_END (26)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_strobe_START (27)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_strobe_END (27)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_cke_high_START (28)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_cke_high_END (28)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_cke_low_START (29)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_cke_low_END (29)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_dqvalid_START (30)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_dqvalid_END (30)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_en_START (31)
#define SOC_HIPACKPHY_CATCONFIG_sw_cat_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cat_reault : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPACKPHY_CATRESULT_UNION;
#endif
#define SOC_HIPACKPHY_CATRESULT_cat_reault_START (0)
#define SOC_HIPACKPHY_CATRESULT_cat_reault_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_dq_result : 32;
    } reg;
} SOC_HIPACKPHY_PHYDQRESULT_UNION;
#endif
#define SOC_HIPACKPHY_PHYDQRESULT_phy_dq_result_START (0)
#define SOC_HIPACKPHY_PHYDQRESULT_phy_dq_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addrph_a_right : 8;
        unsigned int addrph_a_left : 8;
        unsigned int addrph_a : 8;
        unsigned int addrph_a_ori : 8;
    } reg;
} SOC_HIPACKPHY_ADDRPHBOUND_UNION;
#endif
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_right_START (0)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_right_END (7)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_left_START (8)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_left_END (15)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_START (16)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_END (23)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_ori_START (24)
#define SOC_HIPACKPHY_ADDRPHBOUND_addrph_a_ori_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_cat_pat_p : 10;
        unsigned int reserved_0 : 6;
        unsigned int sw_cat_pat_n : 10;
        unsigned int reserved_1 : 5;
        unsigned int cfg_cat_wck_tg_mask : 1;
    } reg;
} SOC_HIPACKPHY_SWCATPATTERN_P_UNION;
#endif
#define SOC_HIPACKPHY_SWCATPATTERN_P_sw_cat_pat_p_START (0)
#define SOC_HIPACKPHY_SWCATPATTERN_P_sw_cat_pat_p_END (9)
#define SOC_HIPACKPHY_SWCATPATTERN_P_sw_cat_pat_n_START (16)
#define SOC_HIPACKPHY_SWCATPATTERN_P_sw_cat_pat_n_END (25)
#define SOC_HIPACKPHY_SWCATPATTERN_P_cfg_cat_wck_tg_mask_START (31)
#define SOC_HIPACKPHY_SWCATPATTERN_P_cfg_cat_wck_tg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int packdbg1_info : 28;
        unsigned int packdbg1_sel : 4;
    } reg;
} SOC_HIPACKPHY_PACKDEBUG1_UNION;
#endif
#define SOC_HIPACKPHY_PACKDEBUG1_packdbg1_info_START (0)
#define SOC_HIPACKPHY_PACKDEBUG1_packdbg1_info_END (27)
#define SOC_HIPACKPHY_PACKDEBUG1_packdbg1_sel_START (28)
#define SOC_HIPACKPHY_PACKDEBUG1_packdbg1_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mrs_seq_prog : 32;
    } reg;
} SOC_HIPACKPHY_MRS_SEQ_PROG_UNION;
#endif
#define SOC_HIPACKPHY_MRS_SEQ_PROG_mrs_seq_prog_START (0)
#define SOC_HIPACKPHY_MRS_SEQ_PROG_mrs_seq_prog_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_dram_clk_enable : 4;
        unsigned int t_dram_clk_disable : 4;
        unsigned int t_wakeup_thrd_lv3 : 4;
        unsigned int t_resp : 4;
        unsigned int lp_pll_powerdown_disable : 1;
        unsigned int lp_dx_phy_phgated_disable : 1;
        unsigned int lp_dx_phy_clkgated_disable : 1;
        unsigned int lp_ac_phy_clkgated_disable : 1;
        unsigned int lp_cmdoen_disable : 1;
        unsigned int t_wakeup_thrd_lv2 : 4;
        unsigned int gcken_dxbist : 1;
        unsigned int gcken_acbist : 1;
        unsigned int gcken_retrain : 1;
        unsigned int gcken_dtrain : 1;
        unsigned int gcken_dinit : 1;
        unsigned int gcken_dfi_main : 1;
        unsigned int gcken_auto_en : 1;
    } reg;
} SOC_HIPACKPHY_LPCTRL_UNION;
#endif
#define SOC_HIPACKPHY_LPCTRL_t_dram_clk_enable_START (0)
#define SOC_HIPACKPHY_LPCTRL_t_dram_clk_enable_END (3)
#define SOC_HIPACKPHY_LPCTRL_t_dram_clk_disable_START (4)
#define SOC_HIPACKPHY_LPCTRL_t_dram_clk_disable_END (7)
#define SOC_HIPACKPHY_LPCTRL_t_wakeup_thrd_lv3_START (8)
#define SOC_HIPACKPHY_LPCTRL_t_wakeup_thrd_lv3_END (11)
#define SOC_HIPACKPHY_LPCTRL_t_resp_START (12)
#define SOC_HIPACKPHY_LPCTRL_t_resp_END (15)
#define SOC_HIPACKPHY_LPCTRL_lp_pll_powerdown_disable_START (16)
#define SOC_HIPACKPHY_LPCTRL_lp_pll_powerdown_disable_END (16)
#define SOC_HIPACKPHY_LPCTRL_lp_dx_phy_phgated_disable_START (17)
#define SOC_HIPACKPHY_LPCTRL_lp_dx_phy_phgated_disable_END (17)
#define SOC_HIPACKPHY_LPCTRL_lp_dx_phy_clkgated_disable_START (18)
#define SOC_HIPACKPHY_LPCTRL_lp_dx_phy_clkgated_disable_END (18)
#define SOC_HIPACKPHY_LPCTRL_lp_ac_phy_clkgated_disable_START (19)
#define SOC_HIPACKPHY_LPCTRL_lp_ac_phy_clkgated_disable_END (19)
#define SOC_HIPACKPHY_LPCTRL_lp_cmdoen_disable_START (20)
#define SOC_HIPACKPHY_LPCTRL_lp_cmdoen_disable_END (20)
#define SOC_HIPACKPHY_LPCTRL_t_wakeup_thrd_lv2_START (21)
#define SOC_HIPACKPHY_LPCTRL_t_wakeup_thrd_lv2_END (24)
#define SOC_HIPACKPHY_LPCTRL_gcken_dxbist_START (25)
#define SOC_HIPACKPHY_LPCTRL_gcken_dxbist_END (25)
#define SOC_HIPACKPHY_LPCTRL_gcken_acbist_START (26)
#define SOC_HIPACKPHY_LPCTRL_gcken_acbist_END (26)
#define SOC_HIPACKPHY_LPCTRL_gcken_retrain_START (27)
#define SOC_HIPACKPHY_LPCTRL_gcken_retrain_END (27)
#define SOC_HIPACKPHY_LPCTRL_gcken_dtrain_START (28)
#define SOC_HIPACKPHY_LPCTRL_gcken_dtrain_END (28)
#define SOC_HIPACKPHY_LPCTRL_gcken_dinit_START (29)
#define SOC_HIPACKPHY_LPCTRL_gcken_dinit_END (29)
#define SOC_HIPACKPHY_LPCTRL_gcken_dfi_main_START (30)
#define SOC_HIPACKPHY_LPCTRL_gcken_dfi_main_END (30)
#define SOC_HIPACKPHY_LPCTRL_gcken_auto_en_START (31)
#define SOC_HIPACKPHY_LPCTRL_gcken_auto_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wl_falledge_ph_jstep_r : 5;
        unsigned int wl_falledge_ph_step_r : 5;
        unsigned int wl_falledge_bdl_jstep_r : 8;
        unsigned int cfg_wetwl2_en_r : 1;
        unsigned int wl_falledge_overflow_en_r : 1;
        unsigned int cfg_wetwl2_dqs_sel_r : 4;
        unsigned int cfg_wetwl2_bdl_en_r : 1;
        unsigned int cfg_wren_dq_vmask_dis : 1;
        unsigned int reserved : 2;
        unsigned int cat_av_en : 1;
        unsigned int cat_rbs_en : 1;
        unsigned int cat_ds_en : 1;
        unsigned int cat_lbs_en : 1;
    } reg;
} SOC_HIPACKPHY_TRAINCTRL12_UNION;
#endif
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_ph_jstep_r_START (0)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_ph_jstep_r_END (4)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_ph_step_r_START (5)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_ph_step_r_END (9)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_bdl_jstep_r_START (10)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_bdl_jstep_r_END (17)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_en_r_START (18)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_en_r_END (18)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_overflow_en_r_START (19)
#define SOC_HIPACKPHY_TRAINCTRL12_wl_falledge_overflow_en_r_END (19)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_dqs_sel_r_START (20)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_dqs_sel_r_END (23)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_bdl_en_r_START (24)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wetwl2_bdl_en_r_END (24)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wren_dq_vmask_dis_START (25)
#define SOC_HIPACKPHY_TRAINCTRL12_cfg_wren_dq_vmask_dis_END (25)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_av_en_START (28)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_av_en_END (28)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_rbs_en_START (29)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_rbs_en_END (29)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_ds_en_START (30)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_ds_en_END (30)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_lbs_en_START (31)
#define SOC_HIPACKPHY_TRAINCTRL12_cat_lbs_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cst_halfTpulse_mrgn : 5;
        unsigned int reserved_0 : 2;
        unsigned int cbt_csgated_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int cbt_dq_latch_mode : 2;
        unsigned int lp4_cbt_mode_type : 2;
        unsigned int reserved_2 : 2;
        unsigned int wl_mode_dq_pd_en : 1;
        unsigned int wl_mode_dq_pd_sel : 1;
        unsigned int reserved_3 : 1;
        unsigned int fast_wl2_cmp_dis : 1;
        unsigned int cst_ph_method : 1;
        unsigned int cst_halfTpulse_post : 1;
        unsigned int nopre4cat : 1;
        unsigned int cfg_cat_scanca_en : 1;
        unsigned int lp4_cbt_vrefset_sel : 2;
        unsigned int reserved_4 : 1;
        unsigned int lp4_cbt_dqx8_sel : 1;
        unsigned int cat_fulltime_tg_en : 1;
        unsigned int phydq_latch_en : 1;
        unsigned int cst_capat_extend_en : 1;
        unsigned int cst_halfTpulse_en : 1;
    } reg;
} SOC_HIPACKPHY_CATCONFIG1_UNION;
#endif
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_mrgn_START (0)
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_mrgn_END (4)
#define SOC_HIPACKPHY_CATCONFIG1_cbt_csgated_en_START (7)
#define SOC_HIPACKPHY_CATCONFIG1_cbt_csgated_en_END (7)
#define SOC_HIPACKPHY_CATCONFIG1_cbt_dq_latch_mode_START (10)
#define SOC_HIPACKPHY_CATCONFIG1_cbt_dq_latch_mode_END (11)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_mode_type_START (12)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_mode_type_END (13)
#define SOC_HIPACKPHY_CATCONFIG1_wl_mode_dq_pd_en_START (16)
#define SOC_HIPACKPHY_CATCONFIG1_wl_mode_dq_pd_en_END (16)
#define SOC_HIPACKPHY_CATCONFIG1_wl_mode_dq_pd_sel_START (17)
#define SOC_HIPACKPHY_CATCONFIG1_wl_mode_dq_pd_sel_END (17)
#define SOC_HIPACKPHY_CATCONFIG1_fast_wl2_cmp_dis_START (19)
#define SOC_HIPACKPHY_CATCONFIG1_fast_wl2_cmp_dis_END (19)
#define SOC_HIPACKPHY_CATCONFIG1_cst_ph_method_START (20)
#define SOC_HIPACKPHY_CATCONFIG1_cst_ph_method_END (20)
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_post_START (21)
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_post_END (21)
#define SOC_HIPACKPHY_CATCONFIG1_nopre4cat_START (22)
#define SOC_HIPACKPHY_CATCONFIG1_nopre4cat_END (22)
#define SOC_HIPACKPHY_CATCONFIG1_cfg_cat_scanca_en_START (23)
#define SOC_HIPACKPHY_CATCONFIG1_cfg_cat_scanca_en_END (23)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_vrefset_sel_START (24)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_vrefset_sel_END (25)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_dqx8_sel_START (27)
#define SOC_HIPACKPHY_CATCONFIG1_lp4_cbt_dqx8_sel_END (27)
#define SOC_HIPACKPHY_CATCONFIG1_cat_fulltime_tg_en_START (28)
#define SOC_HIPACKPHY_CATCONFIG1_cat_fulltime_tg_en_END (28)
#define SOC_HIPACKPHY_CATCONFIG1_phydq_latch_en_START (29)
#define SOC_HIPACKPHY_CATCONFIG1_phydq_latch_en_END (29)
#define SOC_HIPACKPHY_CATCONFIG1_cst_capat_extend_en_START (30)
#define SOC_HIPACKPHY_CATCONFIG1_cst_capat_extend_en_END (30)
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_en_START (31)
#define SOC_HIPACKPHY_CATCONFIG1_cst_halfTpulse_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vrftres_ahvref : 7;
        unsigned int vrftres_ahvref_lb : 7;
        unsigned int vrftres_ahvref_ub : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_HIPACKPHY_AHVREFT_STATUS_UNION;
#endif
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_START (0)
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_END (6)
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_lb_START (7)
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_lb_END (13)
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_ub_START (14)
#define SOC_HIPACKPHY_AHVREFT_STATUS_vrftres_ahvref_ub_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_vrftres_dvref : 7;
        unsigned int reserved_0 : 1;
        unsigned int ac_vrftres_dvref_lb : 7;
        unsigned int reserved_1 : 1;
        unsigned int ac_vrftres_dvref_ub : 7;
        unsigned int reserved_2 : 6;
        unsigned int cfg_dvrefs_dq_type : 1;
        unsigned int cfg_dvrefs_nopre : 1;
        unsigned int ac_vreftres_set_type : 1;
    } reg;
} SOC_HIPACKPHY_ADVREF_STATUS_UNION;
#endif
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_START (0)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_END (6)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_lb_START (8)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_lb_END (14)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_ub_START (16)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vrftres_dvref_ub_END (22)
#define SOC_HIPACKPHY_ADVREF_STATUS_cfg_dvrefs_dq_type_START (29)
#define SOC_HIPACKPHY_ADVREF_STATUS_cfg_dvrefs_dq_type_END (29)
#define SOC_HIPACKPHY_ADVREF_STATUS_cfg_dvrefs_nopre_START (30)
#define SOC_HIPACKPHY_ADVREF_STATUS_cfg_dvrefs_nopre_END (30)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vreftres_set_type_START (31)
#define SOC_HIPACKPHY_ADVREF_STATUS_ac_vreftres_set_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int perbit_track_limit_r : 7;
        unsigned int reserved : 11;
        unsigned int auto_track_sw_en : 1;
        unsigned int phy_autoref_en : 1;
        unsigned int perbit_hipri_en_r : 1;
        unsigned int perbit_lowpri_en_r : 1;
        unsigned int perbit_flag_clr_r : 1;
        unsigned int dynatrk_perbit_cnt_clr_en_r : 1;
        unsigned int dlytrack_perbit_tap_r : 2;
        unsigned int perbit_track_model_sel_r : 1;
        unsigned int perbit_PN_track_en_r : 1;
        unsigned int dynamic_perbit_en_r : 1;
        unsigned int dynamic_dqsg_pri_en_r : 1;
        unsigned int dynamic_dqsg_hipri_en_r : 1;
        unsigned int dlytrack_dqsg_method_sel_r : 1;
    } reg;
} SOC_HIPACKPHY_DLYMEASCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_track_limit_r_START (0)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_track_limit_r_END (6)
#define SOC_HIPACKPHY_DLYMEASCTRL1_auto_track_sw_en_START (18)
#define SOC_HIPACKPHY_DLYMEASCTRL1_auto_track_sw_en_END (18)
#define SOC_HIPACKPHY_DLYMEASCTRL1_phy_autoref_en_START (19)
#define SOC_HIPACKPHY_DLYMEASCTRL1_phy_autoref_en_END (19)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_hipri_en_r_START (20)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_hipri_en_r_END (20)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_lowpri_en_r_START (21)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_lowpri_en_r_END (21)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_flag_clr_r_START (22)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_flag_clr_r_END (22)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynatrk_perbit_cnt_clr_en_r_START (23)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynatrk_perbit_cnt_clr_en_r_END (23)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dlytrack_perbit_tap_r_START (24)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dlytrack_perbit_tap_r_END (25)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_track_model_sel_r_START (26)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_track_model_sel_r_END (26)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_PN_track_en_r_START (27)
#define SOC_HIPACKPHY_DLYMEASCTRL1_perbit_PN_track_en_r_END (27)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_perbit_en_r_START (28)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_perbit_en_r_END (28)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_dqsg_pri_en_r_START (29)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_dqsg_pri_en_r_END (29)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_dqsg_hipri_en_r_START (30)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dynamic_dqsg_hipri_en_r_END (30)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dlytrack_dqsg_method_sel_r_START (31)
#define SOC_HIPACKPHY_DLYMEASCTRL1_dlytrack_dqsg_method_sel_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_lpwakeup_fg : 5;
        unsigned int dfi_adrbits_sel_ddr4 : 1;
        unsigned int lp_csoen_disable : 1;
        unsigned int pack1t4_phy1t2_trans_en : 1;
        unsigned int cfg_rx_gcnt : 8;
        unsigned int reserved_0 : 4;
        unsigned int tlp_lv2_OE_resume : 4;
        unsigned int pack1t2_phy1t1_trans_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int rt_dis_ack : 1;
        unsigned int rt_dis_req : 1;
        unsigned int reserved_2 : 2;
        unsigned int gcken_apb_ctrlreg : 1;
        unsigned int gcken_apb_auto_en : 1;
    } reg;
} SOC_HIPACKPHY_DFIMISCCTRL_UNION;
#endif
#define SOC_HIPACKPHY_DFIMISCCTRL_t_lpwakeup_fg_START (0)
#define SOC_HIPACKPHY_DFIMISCCTRL_t_lpwakeup_fg_END (4)
#define SOC_HIPACKPHY_DFIMISCCTRL_dfi_adrbits_sel_ddr4_START (5)
#define SOC_HIPACKPHY_DFIMISCCTRL_dfi_adrbits_sel_ddr4_END (5)
#define SOC_HIPACKPHY_DFIMISCCTRL_lp_csoen_disable_START (6)
#define SOC_HIPACKPHY_DFIMISCCTRL_lp_csoen_disable_END (6)
#define SOC_HIPACKPHY_DFIMISCCTRL_pack1t4_phy1t2_trans_en_START (7)
#define SOC_HIPACKPHY_DFIMISCCTRL_pack1t4_phy1t2_trans_en_END (7)
#define SOC_HIPACKPHY_DFIMISCCTRL_cfg_rx_gcnt_START (8)
#define SOC_HIPACKPHY_DFIMISCCTRL_cfg_rx_gcnt_END (15)
#define SOC_HIPACKPHY_DFIMISCCTRL_tlp_lv2_OE_resume_START (20)
#define SOC_HIPACKPHY_DFIMISCCTRL_tlp_lv2_OE_resume_END (23)
#define SOC_HIPACKPHY_DFIMISCCTRL_pack1t2_phy1t1_trans_en_START (24)
#define SOC_HIPACKPHY_DFIMISCCTRL_pack1t2_phy1t1_trans_en_END (24)
#define SOC_HIPACKPHY_DFIMISCCTRL_rt_dis_ack_START (26)
#define SOC_HIPACKPHY_DFIMISCCTRL_rt_dis_ack_END (26)
#define SOC_HIPACKPHY_DFIMISCCTRL_rt_dis_req_START (27)
#define SOC_HIPACKPHY_DFIMISCCTRL_rt_dis_req_END (27)
#define SOC_HIPACKPHY_DFIMISCCTRL_gcken_apb_ctrlreg_START (30)
#define SOC_HIPACKPHY_DFIMISCCTRL_gcken_apb_ctrlreg_END (30)
#define SOC_HIPACKPHY_DFIMISCCTRL_gcken_apb_auto_en_START (31)
#define SOC_HIPACKPHY_DFIMISCCTRL_gcken_apb_auto_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_en : 1;
        unsigned int prbs_inv_lsb : 7;
        unsigned int dq_cmp_mask : 8;
        unsigned int dqm_cmp_mask : 1;
        unsigned int prbs_mode : 2;
        unsigned int prbs_inv_msb : 2;
        unsigned int reserved : 3;
        unsigned int lfsr_seed : 8;
    } reg;
} SOC_HIPACKPHY_DXNBISTCTRL_UNION;
#endif
#define SOC_HIPACKPHY_DXNBISTCTRL_bist_en_START (0)
#define SOC_HIPACKPHY_DXNBISTCTRL_bist_en_END (0)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_inv_lsb_START (1)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_inv_lsb_END (7)
#define SOC_HIPACKPHY_DXNBISTCTRL_dq_cmp_mask_START (8)
#define SOC_HIPACKPHY_DXNBISTCTRL_dq_cmp_mask_END (15)
#define SOC_HIPACKPHY_DXNBISTCTRL_dqm_cmp_mask_START (16)
#define SOC_HIPACKPHY_DXNBISTCTRL_dqm_cmp_mask_END (16)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_mode_START (17)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_mode_END (18)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_inv_msb_START (19)
#define SOC_HIPACKPHY_DXNBISTCTRL_prbs_inv_msb_END (20)
#define SOC_HIPACKPHY_DXNBISTCTRL_lfsr_seed_START (24)
#define SOC_HIPACKPHY_DXNBISTCTRL_lfsr_seed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dq_cmp_rerr : 8;
        unsigned int dq_cmp_ferr : 8;
        unsigned int dqm_cmp_rerr : 1;
        unsigned int dqm_cmp_ferr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_HIPACKPHY_DXNBISTSTS_UNION;
#endif
#define SOC_HIPACKPHY_DXNBISTSTS_dq_cmp_rerr_START (0)
#define SOC_HIPACKPHY_DXNBISTSTS_dq_cmp_rerr_END (7)
#define SOC_HIPACKPHY_DXNBISTSTS_dq_cmp_ferr_START (8)
#define SOC_HIPACKPHY_DXNBISTSTS_dq_cmp_ferr_END (15)
#define SOC_HIPACKPHY_DXNBISTSTS_dqm_cmp_rerr_START (16)
#define SOC_HIPACKPHY_DXNBISTSTS_dqm_cmp_rerr_END (16)
#define SOC_HIPACKPHY_DXNBISTSTS_dqm_cmp_ferr_START (17)
#define SOC_HIPACKPHY_DXNBISTSTS_dqm_cmp_ferr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bl_dis : 1;
        unsigned int dm_dis : 1;
        unsigned int reserved_0 : 3;
        unsigned int underflow_dqs : 1;
        unsigned int overflow_dqs : 1;
        unsigned int gck_dbi_autoen : 1;
        unsigned int dbi_write_mode : 2;
        unsigned int dbi_read_en : 2;
        unsigned int dbi_write_en : 2;
        unsigned int dbi_polarity : 1;
        unsigned int wdbi_mask_en : 1;
        unsigned int wdbi_mask_data : 8;
        unsigned int wl_falledge_adj_en_r : 1;
        unsigned int wl_falledge_pre_bdl_r : 1;
        unsigned int wl_rise_edge_r : 1;
        unsigned int wl_fall_edge_r : 1;
        unsigned int wetwl2_done_r : 1;
        unsigned int wetwl2_dbchk_err_r : 1;
        unsigned int wetwl2_err_r : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_HIPACKPHY_DXNCTRL_UNION;
#endif
#define SOC_HIPACKPHY_DXNCTRL_bl_dis_START (0)
#define SOC_HIPACKPHY_DXNCTRL_bl_dis_END (0)
#define SOC_HIPACKPHY_DXNCTRL_dm_dis_START (1)
#define SOC_HIPACKPHY_DXNCTRL_dm_dis_END (1)
#define SOC_HIPACKPHY_DXNCTRL_underflow_dqs_START (5)
#define SOC_HIPACKPHY_DXNCTRL_underflow_dqs_END (5)
#define SOC_HIPACKPHY_DXNCTRL_overflow_dqs_START (6)
#define SOC_HIPACKPHY_DXNCTRL_overflow_dqs_END (6)
#define SOC_HIPACKPHY_DXNCTRL_gck_dbi_autoen_START (7)
#define SOC_HIPACKPHY_DXNCTRL_gck_dbi_autoen_END (7)
#define SOC_HIPACKPHY_DXNCTRL_dbi_write_mode_START (8)
#define SOC_HIPACKPHY_DXNCTRL_dbi_write_mode_END (9)
#define SOC_HIPACKPHY_DXNCTRL_dbi_read_en_START (10)
#define SOC_HIPACKPHY_DXNCTRL_dbi_read_en_END (11)
#define SOC_HIPACKPHY_DXNCTRL_dbi_write_en_START (12)
#define SOC_HIPACKPHY_DXNCTRL_dbi_write_en_END (13)
#define SOC_HIPACKPHY_DXNCTRL_dbi_polarity_START (14)
#define SOC_HIPACKPHY_DXNCTRL_dbi_polarity_END (14)
#define SOC_HIPACKPHY_DXNCTRL_wdbi_mask_en_START (15)
#define SOC_HIPACKPHY_DXNCTRL_wdbi_mask_en_END (15)
#define SOC_HIPACKPHY_DXNCTRL_wdbi_mask_data_START (16)
#define SOC_HIPACKPHY_DXNCTRL_wdbi_mask_data_END (23)
#define SOC_HIPACKPHY_DXNCTRL_wl_falledge_adj_en_r_START (24)
#define SOC_HIPACKPHY_DXNCTRL_wl_falledge_adj_en_r_END (24)
#define SOC_HIPACKPHY_DXNCTRL_wl_falledge_pre_bdl_r_START (25)
#define SOC_HIPACKPHY_DXNCTRL_wl_falledge_pre_bdl_r_END (25)
#define SOC_HIPACKPHY_DXNCTRL_wl_rise_edge_r_START (26)
#define SOC_HIPACKPHY_DXNCTRL_wl_rise_edge_r_END (26)
#define SOC_HIPACKPHY_DXNCTRL_wl_fall_edge_r_START (27)
#define SOC_HIPACKPHY_DXNCTRL_wl_fall_edge_r_END (27)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_done_r_START (28)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_done_r_END (28)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_dbchk_err_r_START (29)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_dbchk_err_r_END (29)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_err_r_START (30)
#define SOC_HIPACKPHY_DXNCTRL_wetwl2_err_r_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int weccbdl : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPACKPHY_DXNWECCBDL_UNION;
#endif
#define SOC_HIPACKPHY_DXNWECCBDL_weccbdl_START (0)
#define SOC_HIPACKPHY_DXNWECCBDL_weccbdl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdq0bdl : 8;
        unsigned int wdq1bdl : 8;
        unsigned int wdq2bdl : 8;
        unsigned int wdq3bdl : 8;
    } reg;
} SOC_HIPACKPHY_DXNWDQNBDL0_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq0bdl_START (0)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq0bdl_END (7)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq1bdl_START (8)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq1bdl_END (15)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq2bdl_START (16)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq2bdl_END (23)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq3bdl_START (24)
#define SOC_HIPACKPHY_DXNWDQNBDL0_wdq3bdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdq4bdl : 8;
        unsigned int wdq5bdl : 8;
        unsigned int wdq6bdl : 8;
        unsigned int wdq7bdl : 8;
    } reg;
} SOC_HIPACKPHY_DXNWDQNBDL1_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq4bdl_START (0)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq4bdl_END (7)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq5bdl_START (8)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq5bdl_END (15)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq6bdl_START (16)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq6bdl_END (23)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq7bdl_START (24)
#define SOC_HIPACKPHY_DXNWDQNBDL1_wdq7bdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdmbdl : 8;
        unsigned int wdmbdl_msb : 2;
        unsigned int reserved : 6;
        unsigned int wdqnbdl_msb : 16;
    } reg;
} SOC_HIPACKPHY_DXNWDQNBDL2_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdmbdl_START (0)
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdmbdl_END (7)
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdmbdl_msb_START (8)
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdmbdl_msb_END (9)
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdqnbdl_msb_START (16)
#define SOC_HIPACKPHY_DXNWDQNBDL2_wdqnbdl_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdq0bdl : 8;
        unsigned int rdq1bdl : 8;
        unsigned int rdq2bdl : 8;
        unsigned int rdq3bdl : 8;
    } reg;
} SOC_HIPACKPHY_DXNRDQNBDL0_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq0bdl_START (0)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq0bdl_END (7)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq1bdl_START (8)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq1bdl_END (15)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq2bdl_START (16)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq2bdl_END (23)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq3bdl_START (24)
#define SOC_HIPACKPHY_DXNRDQNBDL0_rdq3bdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdq4bdl : 8;
        unsigned int rdq5bdl : 8;
        unsigned int rdq6bdl : 8;
        unsigned int rdq7bdl : 8;
    } reg;
} SOC_HIPACKPHY_DXNRDQNBDL1_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq4bdl_START (0)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq4bdl_END (7)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq5bdl_START (8)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq5bdl_END (15)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq6bdl_START (16)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq6bdl_END (23)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq7bdl_START (24)
#define SOC_HIPACKPHY_DXNRDQNBDL1_rdq7bdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdmbdl : 8;
        unsigned int rdmbdl_msb : 2;
        unsigned int reserved : 6;
        unsigned int rdqnbdl_msb : 16;
    } reg;
} SOC_HIPACKPHY_DXNRDQNBDL2_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdmbdl_START (0)
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdmbdl_END (7)
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdmbdl_msb_START (8)
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdmbdl_msb_END (9)
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdqnbdl_msb_START (16)
#define SOC_HIPACKPHY_DXNRDQNBDL2_rdqnbdl_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oen_bdl : 10;
        unsigned int reserved_0 : 6;
        unsigned int wdqsoe_bdl : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_DXNOEBDL_UNION;
#endif
#define SOC_HIPACKPHY_DXNOEBDL_oen_bdl_START (0)
#define SOC_HIPACKPHY_DXNOEBDL_oen_bdl_END (9)
#define SOC_HIPACKPHY_DXNOEBDL_wdqsoe_bdl_START (16)
#define SOC_HIPACKPHY_DXNOEBDL_wdqsoe_bdl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdqsbdl : 10;
        unsigned int reserved_0: 6;
        unsigned int rdqscyc : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HIPACKPHY_DXNRDQSDLY_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQSDLY_rdqsbdl_START (0)
#define SOC_HIPACKPHY_DXNRDQSDLY_rdqsbdl_END (9)
#define SOC_HIPACKPHY_DXNRDQSDLY_rdqscyc_START (16)
#define SOC_HIPACKPHY_DXNRDQSDLY_rdqscyc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdqsbdl : 8;
        unsigned int wdqsphase : 6;
        unsigned int reserved : 16;
        unsigned int wdqsbdl_msb : 2;
    } reg;
} SOC_HIPACKPHY_DXNWDQSDLY_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsbdl_START (0)
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsbdl_END (7)
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsphase_START (8)
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsphase_END (13)
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsbdl_msb_START (30)
#define SOC_HIPACKPHY_DXNWDQSDLY_wdqsbdl_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int wdqphase : 8;
        unsigned int reserved_1: 16;
    } reg;
} SOC_HIPACKPHY_DXNWDQDLY_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQDLY_wdqphase_START (8)
#define SOC_HIPACKPHY_DXNWDQDLY_wdqphase_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int wlsl : 2;
        unsigned int reserved_1: 14;
    } reg;
} SOC_HIPACKPHY_DXNWLSL_UNION;
#endif
#define SOC_HIPACKPHY_DXNWLSL_wlsl_START (16)
#define SOC_HIPACKPHY_DXNWLSL_wlsl_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gds : 4;
        unsigned int reserved_0 : 12;
        unsigned int org_rdqsgph : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_DXNGDS_UNION;
#endif
#define SOC_HIPACKPHY_DXNGDS_gds_START (0)
#define SOC_HIPACKPHY_DXNGDS_gds_END (3)
#define SOC_HIPACKPHY_DXNGDS_org_rdqsgph_START (16)
#define SOC_HIPACKPHY_DXNGDS_org_rdqsgph_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdqsgbdl : 8;
        unsigned int reserved_0 : 1;
        unsigned int rdqsgphase : 10;
        unsigned int rdqsgbdl_msb : 2;
        unsigned int reserved_1 : 1;
        unsigned int rdqsgtxbdl_msb : 2;
        unsigned int rdqsgtxbdl : 8;
    } reg;
} SOC_HIPACKPHY_DXNRDQSGDLY_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgbdl_START (0)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgbdl_END (7)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgphase_START (9)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgphase_END (18)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgbdl_msb_START (19)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgbdl_msb_END (20)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgtxbdl_msb_START (22)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgtxbdl_msb_END (23)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgtxbdl_START (24)
#define SOC_HIPACKPHY_DXNRDQSGDLY_rdqsgtxbdl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdq0bdl_left : 8;
        unsigned int wdq1bdl_left : 8;
        unsigned int wdq2bdl_left : 8;
        unsigned int wdq3bdl_left : 8;
    } reg;
} SOC_HIPACKPHY_DXNWDQNLB0_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq0bdl_left_START (0)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq0bdl_left_END (7)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq1bdl_left_START (8)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq1bdl_left_END (15)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq2bdl_left_START (16)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq2bdl_left_END (23)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq3bdl_left_START (24)
#define SOC_HIPACKPHY_DXNWDQNLB0_wdq3bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdqsbdl30 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bdl_mondly : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_DXNRDQSDLYSUB_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_rdqsbdl30_START (0)
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_rdqsbdl30_END (9)
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_bdl_mondly_START (16)
#define SOC_HIPACKPHY_DXNRDQSDLYSUB_bdl_mondly_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdqsbdl_right : 10;
        unsigned int reserved_0 : 6;
        unsigned int rdqsbdl_left : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_DXNRDBOUND_UNION;
#endif
#define SOC_HIPACKPHY_DXNRDBOUND_rdqsbdl_right_START (0)
#define SOC_HIPACKPHY_DXNRDBOUND_rdqsbdl_right_END (9)
#define SOC_HIPACKPHY_DXNRDBOUND_rdqsbdl_left_START (16)
#define SOC_HIPACKPHY_DXNRDBOUND_rdqsbdl_left_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdqphase_right : 8;
        unsigned int reserved_0 : 4;
        unsigned int wdet_ave_comp_flag : 1;
        unsigned int reserved_1 : 3;
        unsigned int wdqphase_left : 8;
        unsigned int wdq0bdl_left : 8;
    } reg;
} SOC_HIPACKPHY_DXNWRBOUND_UNION;
#endif
#define SOC_HIPACKPHY_DXNWRBOUND_wdqphase_right_START (0)
#define SOC_HIPACKPHY_DXNWRBOUND_wdqphase_right_END (7)
#define SOC_HIPACKPHY_DXNWRBOUND_wdet_ave_comp_flag_START (12)
#define SOC_HIPACKPHY_DXNWRBOUND_wdet_ave_comp_flag_END (12)
#define SOC_HIPACKPHY_DXNWRBOUND_wdqphase_left_START (16)
#define SOC_HIPACKPHY_DXNWRBOUND_wdqphase_left_END (23)
#define SOC_HIPACKPHY_DXNWRBOUND_wdq0bdl_left_START (24)
#define SOC_HIPACKPHY_DXNWRBOUND_wdq0bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdq4bdl_left : 8;
        unsigned int wdq5bdl_left : 8;
        unsigned int wdq6bdl_left : 8;
        unsigned int wdq7bdl_left : 8;
    } reg;
} SOC_HIPACKPHY_DXNWDQNLB1_UNION;
#endif
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq4bdl_left_START (0)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq4bdl_left_END (7)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq5bdl_left_START (8)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq5bdl_left_END (15)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq6bdl_left_START (16)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq6bdl_left_END (23)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq7bdl_left_START (24)
#define SOC_HIPACKPHY_DXNWDQNLB1_wdq7bdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdmbdl_msb_left : 16;
        unsigned int dqs0_gold : 16;
    } reg;
} SOC_HIPACKPHY_DXDEBUG0_UNION;
#endif
#define SOC_HIPACKPHY_DXDEBUG0_wdmbdl_msb_left_START (0)
#define SOC_HIPACKPHY_DXDEBUG0_wdmbdl_msb_left_END (15)
#define SOC_HIPACKPHY_DXDEBUG0_dqs0_gold_START (16)
#define SOC_HIPACKPHY_DXDEBUG0_dqs0_gold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dqs0b : 16;
        unsigned int dqs0 : 16;
    } reg;
} SOC_HIPACKPHY_DXDEBUG1_UNION;
#endif
#define SOC_HIPACKPHY_DXDEBUG1_dqs0b_START (0)
#define SOC_HIPACKPHY_DXDEBUG1_dqs0b_END (15)
#define SOC_HIPACKPHY_DXDEBUG1_dqs0_START (16)
#define SOC_HIPACKPHY_DXDEBUG1_dqs0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vrftres_dvref : 7;
        unsigned int reserved_0 : 1;
        unsigned int vrftres_dvref_lb : 7;
        unsigned int reserved_1 : 1;
        unsigned int vrftres_dvref_ub : 7;
        unsigned int reserved_2 : 1;
        unsigned int wdmbdl_left : 8;
    } reg;
} SOC_HIPACKPHY_DVREFT_STATUS_UNION;
#endif
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_START (0)
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_END (6)
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_lb_START (8)
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_lb_END (14)
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_ub_START (16)
#define SOC_HIPACKPHY_DVREFT_STATUS_vrftres_dvref_ub_END (22)
#define SOC_HIPACKPHY_DVREFT_STATUS_wdmbdl_left_START (24)
#define SOC_HIPACKPHY_DVREFT_STATUS_wdmbdl_left_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vrftres_hvref : 7;
        unsigned int vrftres_hvref_lb : 7;
        unsigned int vrftres_dvref_ub : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_HIPACKPHY_HVREFT_STATUS_UNION;
#endif
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_hvref_START (0)
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_hvref_END (6)
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_hvref_lb_START (7)
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_hvref_lb_END (13)
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_dvref_ub_START (14)
#define SOC_HIPACKPHY_HVREFT_STATUS_vrftres_dvref_ub_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int underflow_dq : 8;
        unsigned int overflow_dq : 8;
        unsigned int underflow_dm : 1;
        unsigned int overflow_dm : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_HIPACKPHY_DXNTRACKSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_DXNTRACKSTATUS_underflow_dq_START (0)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_underflow_dq_END (7)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_overflow_dq_START (8)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_overflow_dq_END (15)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_underflow_dm_START (16)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_underflow_dm_END (16)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_overflow_dm_START (17)
#define SOC_HIPACKPHY_DXNTRACKSTATUS_overflow_dm_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vreft_bist_rb : 10;
        unsigned int reserved_0 : 6;
        unsigned int vreft_bist_lb : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HIPACKPHY_VREFT_BOUND_UNION;
#endif
#define SOC_HIPACKPHY_VREFT_BOUND_vreft_bist_rb_START (0)
#define SOC_HIPACKPHY_VREFT_BOUND_vreft_bist_rb_END (9)
#define SOC_HIPACKPHY_VREFT_BOUND_vreft_bist_lb_START (16)
#define SOC_HIPACKPHY_VREFT_BOUND_vreft_bist_lb_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_lock_err_th : 4;
        unsigned int pll_lock_err_en : 1;
        unsigned int pll_lock_err_clr : 1;
        unsigned int pll_lock_err_cnt_r : 4;
        unsigned int bgdlymeas_int_en : 1;
        unsigned int dvalid_err_int_en : 1;
        unsigned int gate_err_int_en : 1;
        unsigned int gate_err_int_clr : 1;
        unsigned int gate_err_int_type : 1;
        unsigned int jtmt_error_int_en : 1;
        unsigned int wdert_err_int_en : 1;
        unsigned int pll_lock_lp_err_en : 1;
        unsigned int dfi_sel_err_en : 1;
        unsigned int dfi_sel_err_clr : 1;
        unsigned int zcal_err_int_en : 1;
        unsigned int reserved : 2;
        unsigned int zcal_err_int : 1;
        unsigned int bgdlymeas_int : 1;
        unsigned int dvalid_err_int : 1;
        unsigned int jtmt_error_int : 1;
        unsigned int pll_unlock_int_lp : 1;
        unsigned int dfi_sel_err_int : 1;
        unsigned int wdert_err_int : 1;
        unsigned int gate_err_int : 1;
        unsigned int pll_unlock_int : 1;
    } reg;
} SOC_HIPACKPHY_PLLSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_th_START (0)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_th_END (3)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_en_START (4)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_en_END (4)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_clr_START (5)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_clr_END (5)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_cnt_r_START (6)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_err_cnt_r_END (9)
#define SOC_HIPACKPHY_PLLSTATUS_bgdlymeas_int_en_START (10)
#define SOC_HIPACKPHY_PLLSTATUS_bgdlymeas_int_en_END (10)
#define SOC_HIPACKPHY_PLLSTATUS_dvalid_err_int_en_START (11)
#define SOC_HIPACKPHY_PLLSTATUS_dvalid_err_int_en_END (11)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_en_START (12)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_en_END (12)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_clr_START (13)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_clr_END (13)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_type_START (14)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_type_END (14)
#define SOC_HIPACKPHY_PLLSTATUS_jtmt_error_int_en_START (15)
#define SOC_HIPACKPHY_PLLSTATUS_jtmt_error_int_en_END (15)
#define SOC_HIPACKPHY_PLLSTATUS_wdert_err_int_en_START (16)
#define SOC_HIPACKPHY_PLLSTATUS_wdert_err_int_en_END (16)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_lp_err_en_START (17)
#define SOC_HIPACKPHY_PLLSTATUS_pll_lock_lp_err_en_END (17)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_en_START (18)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_en_END (18)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_clr_START (19)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_clr_END (19)
#define SOC_HIPACKPHY_PLLSTATUS_zcal_err_int_en_START (20)
#define SOC_HIPACKPHY_PLLSTATUS_zcal_err_int_en_END (20)
#define SOC_HIPACKPHY_PLLSTATUS_zcal_err_int_START (23)
#define SOC_HIPACKPHY_PLLSTATUS_zcal_err_int_END (23)
#define SOC_HIPACKPHY_PLLSTATUS_bgdlymeas_int_START (24)
#define SOC_HIPACKPHY_PLLSTATUS_bgdlymeas_int_END (24)
#define SOC_HIPACKPHY_PLLSTATUS_dvalid_err_int_START (25)
#define SOC_HIPACKPHY_PLLSTATUS_dvalid_err_int_END (25)
#define SOC_HIPACKPHY_PLLSTATUS_jtmt_error_int_START (26)
#define SOC_HIPACKPHY_PLLSTATUS_jtmt_error_int_END (26)
#define SOC_HIPACKPHY_PLLSTATUS_pll_unlock_int_lp_START (27)
#define SOC_HIPACKPHY_PLLSTATUS_pll_unlock_int_lp_END (27)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_int_START (28)
#define SOC_HIPACKPHY_PLLSTATUS_dfi_sel_err_int_END (28)
#define SOC_HIPACKPHY_PLLSTATUS_wdert_err_int_START (29)
#define SOC_HIPACKPHY_PLLSTATUS_wdert_err_int_END (29)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_START (30)
#define SOC_HIPACKPHY_PLLSTATUS_gate_err_int_END (30)
#define SOC_HIPACKPHY_PLLSTATUS_pll_unlock_int_START (31)
#define SOC_HIPACKPHY_PLLSTATUS_pll_unlock_int_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mpc_en_r : 1;
        unsigned int bstpatsel_dm_r : 3;
        unsigned int bstdat_dm_r : 2;
        unsigned int mpc_type_r : 1;
        unsigned int mpc_num_prewrite_r : 3;
        unsigned int mem_scan_test_en_r : 1;
        unsigned int bist_idle_insert_en_r : 1;
        unsigned int idle_start_bound_r : 7;
        unsigned int prbs4_pat_shift_mode : 3;
        unsigned int mpc_fifo_max_dp_ind : 2;
        unsigned int bstdat_indx : 2;
        unsigned int reserved : 1;
        unsigned int mem_scan_once_r : 1;
        unsigned int dxlpbk_cmpdis_cnt : 4;
    } reg;
} SOC_HIPACKPHY_BISTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_BISTCTRL1_mpc_en_r_START (0)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_en_r_END (0)
#define SOC_HIPACKPHY_BISTCTRL1_bstpatsel_dm_r_START (1)
#define SOC_HIPACKPHY_BISTCTRL1_bstpatsel_dm_r_END (3)
#define SOC_HIPACKPHY_BISTCTRL1_bstdat_dm_r_START (4)
#define SOC_HIPACKPHY_BISTCTRL1_bstdat_dm_r_END (5)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_type_r_START (6)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_type_r_END (6)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_num_prewrite_r_START (7)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_num_prewrite_r_END (9)
#define SOC_HIPACKPHY_BISTCTRL1_mem_scan_test_en_r_START (10)
#define SOC_HIPACKPHY_BISTCTRL1_mem_scan_test_en_r_END (10)
#define SOC_HIPACKPHY_BISTCTRL1_bist_idle_insert_en_r_START (11)
#define SOC_HIPACKPHY_BISTCTRL1_bist_idle_insert_en_r_END (11)
#define SOC_HIPACKPHY_BISTCTRL1_idle_start_bound_r_START (12)
#define SOC_HIPACKPHY_BISTCTRL1_idle_start_bound_r_END (18)
#define SOC_HIPACKPHY_BISTCTRL1_prbs4_pat_shift_mode_START (19)
#define SOC_HIPACKPHY_BISTCTRL1_prbs4_pat_shift_mode_END (21)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_fifo_max_dp_ind_START (22)
#define SOC_HIPACKPHY_BISTCTRL1_mpc_fifo_max_dp_ind_END (23)
#define SOC_HIPACKPHY_BISTCTRL1_bstdat_indx_START (24)
#define SOC_HIPACKPHY_BISTCTRL1_bstdat_indx_END (25)
#define SOC_HIPACKPHY_BISTCTRL1_mem_scan_once_r_START (27)
#define SOC_HIPACKPHY_BISTCTRL1_mem_scan_once_r_END (27)
#define SOC_HIPACKPHY_BISTCTRL1_dxlpbk_cmpdis_cnt_START (28)
#define SOC_HIPACKPHY_BISTCTRL1_dxlpbk_cmpdis_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int det_pat_alt : 32;
    } reg;
} SOC_HIPACKPHY_DETPATTERN1_UNION;
#endif
#define SOC_HIPACKPHY_DETPATTERN1_det_pat_alt_START (0)
#define SOC_HIPACKPHY_DETPATTERN1_det_pat_alt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mask_pattern : 4;
        unsigned int addr : 13;
        unsigned int err_req_cnt : 15;
    } reg;
} SOC_HIPACKPHY_APB_WR_MASK_INFO_UNION;
#endif
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_mask_pattern_START (0)
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_mask_pattern_END (3)
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_addr_START (4)
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_addr_END (16)
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_err_req_cnt_START (17)
#define SOC_HIPACKPHY_APB_WR_MASK_INFO_err_req_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uc_mode_en : 1;
        unsigned int uc_regif_wst : 1;
        unsigned int uc_rt_populate : 2;
        unsigned int uc_rw_pte_en : 1;
        unsigned int uc_mode_en_bg : 1;
        unsigned int reserved_0 : 1;
        unsigned int carry_status_type : 1;
        unsigned int phycnt_rst_type : 1;
        unsigned int reserved_1 : 11;
        unsigned int status_lowpri_peek : 1;
        unsigned int trkdbg_ctl_aref_active : 1;
        unsigned int trkdbg_dlymeas_gated : 1;
        unsigned int reserved_2 : 1;
        unsigned int trkdbg_dyna_hiprirdqsgen : 1;
        unsigned int trkdbg_dyna_prirdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsgen : 1;
        unsigned int trkdbg_dyna_rdqsen : 1;
        unsigned int trkdbg_rdqsg_get : 1;
        unsigned int trkdbg_rdqs_get : 1;
        unsigned int pte_phyupd_req : 1;
        unsigned int uc_rowact_type : 1;
    } reg;
} SOC_HIPACKPHY_UC_TRCTRL_UNION;
#endif
#define SOC_HIPACKPHY_UC_TRCTRL_uc_mode_en_START (0)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_mode_en_END (0)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_regif_wst_START (1)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_regif_wst_END (1)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rt_populate_START (2)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rt_populate_END (3)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rw_pte_en_START (4)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rw_pte_en_END (4)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_mode_en_bg_START (5)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_mode_en_bg_END (5)
#define SOC_HIPACKPHY_UC_TRCTRL_carry_status_type_START (7)
#define SOC_HIPACKPHY_UC_TRCTRL_carry_status_type_END (7)
#define SOC_HIPACKPHY_UC_TRCTRL_phycnt_rst_type_START (8)
#define SOC_HIPACKPHY_UC_TRCTRL_phycnt_rst_type_END (8)
#define SOC_HIPACKPHY_UC_TRCTRL_status_lowpri_peek_START (20)
#define SOC_HIPACKPHY_UC_TRCTRL_status_lowpri_peek_END (20)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_ctl_aref_active_START (21)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_ctl_aref_active_END (21)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dlymeas_gated_START (22)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dlymeas_gated_END (22)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_START (24)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_hiprirdqsgen_END (24)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_prirdqsgen_START (25)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_prirdqsgen_END (25)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_rdqsgen_START (26)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_rdqsgen_END (26)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_rdqsen_START (27)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_dyna_rdqsen_END (27)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_rdqsg_get_START (28)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_rdqsg_get_END (28)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_rdqs_get_START (29)
#define SOC_HIPACKPHY_UC_TRCTRL_trkdbg_rdqs_get_END (29)
#define SOC_HIPACKPHY_UC_TRCTRL_pte_phyupd_req_START (30)
#define SOC_HIPACKPHY_UC_TRCTRL_pte_phyupd_req_END (30)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rowact_type_START (31)
#define SOC_HIPACKPHY_UC_TRCTRL_uc_rowact_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int detop_active : 1;
        unsigned int detop_preca : 1;
        unsigned int reserved_0 : 2;
        unsigned int detop_prewrite : 1;
        unsigned int detop_rdtest : 1;
        unsigned int detop_rwtest : 1;
        unsigned int detop_preca_post : 1;
        unsigned int reserved_1 : 8;
        unsigned int phycnt_rst : 1;
        unsigned int wl2op_active : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_HIPACKPHY_UC_TROPCTRL_UNION;
#endif
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_active_START (0)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_active_END (0)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_preca_START (1)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_preca_END (1)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_prewrite_START (4)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_prewrite_END (4)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_rdtest_START (5)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_rdtest_END (5)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_rwtest_START (6)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_rwtest_END (6)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_preca_post_START (7)
#define SOC_HIPACKPHY_UC_TROPCTRL_detop_preca_post_END (7)
#define SOC_HIPACKPHY_UC_TROPCTRL_phycnt_rst_START (16)
#define SOC_HIPACKPHY_UC_TROPCTRL_phycnt_rst_END (16)
#define SOC_HIPACKPHY_UC_TROPCTRL_wl2op_active_START (17)
#define SOC_HIPACKPHY_UC_TROPCTRL_wl2op_active_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtrain_active : 1;
        unsigned int reserved : 14;
        unsigned int comb_cary_status : 1;
        unsigned int det_all_passed : 4;
        unsigned int det_any_passed : 4;
        unsigned int det_all_failed : 4;
        unsigned int det_any_failed : 4;
    } reg;
} SOC_HIPACKPHY_UC_DTRSTSP_UNION;
#endif
#define SOC_HIPACKPHY_UC_DTRSTSP_dtrain_active_START (0)
#define SOC_HIPACKPHY_UC_DTRSTSP_dtrain_active_END (0)
#define SOC_HIPACKPHY_UC_DTRSTSP_comb_cary_status_START (15)
#define SOC_HIPACKPHY_UC_DTRSTSP_comb_cary_status_END (15)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_all_passed_START (16)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_all_passed_END (19)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_any_passed_START (20)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_any_passed_END (23)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_all_failed_START (24)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_all_failed_END (27)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_any_failed_START (28)
#define SOC_HIPACKPHY_UC_DTRSTSP_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uc_rtactive : 2;
        unsigned int reserved : 28;
        unsigned int pd_in_retrain : 1;
        unsigned int uc_int_msk : 1;
    } reg;
} SOC_HIPACKPHY_UC_TRSTATUS_UNION;
#endif
#define SOC_HIPACKPHY_UC_TRSTATUS_uc_rtactive_START (0)
#define SOC_HIPACKPHY_UC_TRSTATUS_uc_rtactive_END (1)
#define SOC_HIPACKPHY_UC_TRSTATUS_pd_in_retrain_START (30)
#define SOC_HIPACKPHY_UC_TRSTATUS_pd_in_retrain_END (30)
#define SOC_HIPACKPHY_UC_TRSTATUS_uc_int_msk_START (31)
#define SOC_HIPACKPHY_UC_TRSTATUS_uc_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdq_byp_mode : 1;
        unsigned int cmdq_flush : 1;
        unsigned int reserved_0 : 2;
        unsigned int cmdq_rd_flush_mode : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_HIPACKPHY_UC_CMDQCTRL_UNION;
#endif
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_byp_mode_START (0)
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_byp_mode_END (0)
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_flush_START (1)
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_flush_END (1)
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_rd_flush_mode_START (4)
#define SOC_HIPACKPHY_UC_CMDQCTRL_cmdq_rd_flush_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_done_bit : 1;
        unsigned int pte_regrdy : 1;
        unsigned int reseved : 14;
        unsigned int apb_paddr : 15;
        unsigned int apb_write : 1;
    } reg;
} SOC_HIPACKPHY_UC_APB_CAS_UNION;
#endif
#define SOC_HIPACKPHY_UC_APB_CAS_apb_done_bit_START (0)
#define SOC_HIPACKPHY_UC_APB_CAS_apb_done_bit_END (0)
#define SOC_HIPACKPHY_UC_APB_CAS_pte_regrdy_START (1)
#define SOC_HIPACKPHY_UC_APB_CAS_pte_regrdy_END (1)
#define SOC_HIPACKPHY_UC_APB_CAS_reseved_START (2)
#define SOC_HIPACKPHY_UC_APB_CAS_reseved_END (15)
#define SOC_HIPACKPHY_UC_APB_CAS_apb_paddr_START (16)
#define SOC_HIPACKPHY_UC_APB_CAS_apb_paddr_END (30)
#define SOC_HIPACKPHY_UC_APB_CAS_apb_write_START (31)
#define SOC_HIPACKPHY_UC_APB_CAS_apb_write_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_wdata : 32;
    } reg;
} SOC_HIPACKPHY_UC_APB_WDATA_UNION;
#endif
#define SOC_HIPACKPHY_UC_APB_WDATA_apb_wdata_START (0)
#define SOC_HIPACKPHY_UC_APB_WDATA_apb_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_rdata : 32;
    } reg;
} SOC_HIPACKPHY_UC_APB_RDATA_UNION;
#endif
#define SOC_HIPACKPHY_UC_APB_RDATA_apb_rdata_START (0)
#define SOC_HIPACKPHY_UC_APB_RDATA_apb_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved_0 : 4;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int phase_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_HIPACKPHY_UC_ADDRPH_A_AUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_alu_operand_END (11)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_carry_status_END (17)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_phase_sel_START (24)
#define SOC_HIPACKPHY_UC_ADDRPH_A_AUC_phase_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int addrbdl_a_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_addrbdl_a_sel_START (24)
#define SOC_HIPACKPHY_UC_ADDRBDL_A_AUC_addrbdl_a_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_0 : 2;
        unsigned int carry_status : 2;
        unsigned int reserved_1 : 6;
        unsigned int csbdl_sel : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_HIPACKPHY_UC_CSRBDL_AUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_carry_status_END (17)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_csbdl_sel_START (24)
#define SOC_HIPACKPHY_UC_CSRBDL_AUC_csbdl_sel_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 8;
        unsigned int reserved : 4;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_WDQPHAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDQPHAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_WDQPHAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_WDQPHAUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_WDQPHAUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_WDQPHAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_WDQPHAUC_alu_operand_END (11)
#define SOC_HIPACKPHY_UC_WDQPHAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_WDQPHAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_WDQPHAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_WDQPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 6;
        unsigned int reserved_1 : 6;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_WDQSPHAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDQSPHAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_alu_operand_END (9)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_WDQSPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_WDQSBDLAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_WDQSBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdly_store : 1;
        unsigned int reserved_0 : 19;
        unsigned int acdly_store : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_HIPACKPHY_UC_WDLYOP_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDLYOP_wdly_store_START (0)
#define SOC_HIPACKPHY_UC_WDLYOP_wdly_store_END (0)
#define SOC_HIPACKPHY_UC_WDLYOP_acdly_store_START (20)
#define SOC_HIPACKPHY_UC_WDLYOP_acdly_store_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RDQSAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQSAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RDQSAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RDQSAUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_RDQSAUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_RDQSAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RDQSAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_RDQSAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_RDQSAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_RDQSAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_RDQSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RDQSGTXAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_RDQSGTXAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RDQSGPHAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_RDQSGPHAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_1 : 2;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RDQSGBDLAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_RDQSGBDLAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int reserved_0 : 1;
        unsigned int alu_operand : 4;
        unsigned int reserved_1 : 8;
        unsigned int carry_status : 8;
        unsigned int data8_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RGDSAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RGDSAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RGDSAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RGDSAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RGDSAUC_alu_operand_END (7)
#define SOC_HIPACKPHY_UC_RGDSAUC_carry_status_START (16)
#define SOC_HIPACKPHY_UC_RGDSAUC_carry_status_END (23)
#define SOC_HIPACKPHY_UC_RGDSAUC_data8_sel_START (24)
#define SOC_HIPACKPHY_UC_RGDSAUC_data8_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdly_store : 1;
        unsigned int reserved : 15;
        unsigned int operandz : 16;
    } reg;
} SOC_HIPACKPHY_UC_RDLYOP_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDLYOP_rdly_store_START (0)
#define SOC_HIPACKPHY_UC_RDLYOP_rdly_store_END (0)
#define SOC_HIPACKPHY_UC_RDLYOP_operandz_START (16)
#define SOC_HIPACKPHY_UC_RDLYOP_operandz_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_wlmode : 1;
        unsigned int sw_gtmode : 1;
        unsigned int reserved_0 : 2;
        unsigned int sw_wlmodeb : 8;
        unsigned int reserved_1 : 4;
        unsigned int sw_dxctl_ie_dq : 8;
        unsigned int sw_dxctl_ie_dq_mode : 1;
        unsigned int reserved_2 : 3;
        unsigned int sw_rdfifo_push_block : 1;
        unsigned int sw_dvalid_block : 1;
        unsigned int sw_csgated : 1;
        unsigned int wl_wdqs_gated : 1;
    } reg;
} SOC_HIPACKPHY_UCSWTMODE_UNION;
#endif
#define SOC_HIPACKPHY_UCSWTMODE_sw_wlmode_START (0)
#define SOC_HIPACKPHY_UCSWTMODE_sw_wlmode_END (0)
#define SOC_HIPACKPHY_UCSWTMODE_sw_gtmode_START (1)
#define SOC_HIPACKPHY_UCSWTMODE_sw_gtmode_END (1)
#define SOC_HIPACKPHY_UCSWTMODE_sw_wlmodeb_START (4)
#define SOC_HIPACKPHY_UCSWTMODE_sw_wlmodeb_END (11)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dxctl_ie_dq_START (16)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dxctl_ie_dq_END (23)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dxctl_ie_dq_mode_START (24)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dxctl_ie_dq_mode_END (24)
#define SOC_HIPACKPHY_UCSWTMODE_sw_rdfifo_push_block_START (28)
#define SOC_HIPACKPHY_UCSWTMODE_sw_rdfifo_push_block_END (28)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dvalid_block_START (29)
#define SOC_HIPACKPHY_UCSWTMODE_sw_dvalid_block_END (29)
#define SOC_HIPACKPHY_UCSWTMODE_sw_csgated_START (30)
#define SOC_HIPACKPHY_UCSWTMODE_sw_csgated_END (30)
#define SOC_HIPACKPHY_UCSWTMODE_wl_wdqs_gated_START (31)
#define SOC_HIPACKPHY_UCSWTMODE_wl_wdqs_gated_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_wl_dqs : 1;
        unsigned int reserved : 2;
        unsigned int sw_mrw_format : 1;
        unsigned int sw_mrw_cs : 2;
        unsigned int sw_mrw_rw : 1;
        unsigned int sw_mrw_req : 1;
        unsigned int sw_mrw_ma : 8;
        unsigned int sw_mrw_op : 16;
    } reg;
} SOC_HIPACKPHY_UCSWTWLDQS_UNION;
#endif
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_wl_dqs_START (0)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_wl_dqs_END (0)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_format_START (3)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_format_END (3)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_cs_START (4)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_cs_END (5)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_rw_START (6)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_rw_END (6)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_req_START (7)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_req_END (7)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_ma_START (8)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_ma_END (15)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_op_START (16)
#define SOC_HIPACKPHY_UCSWTWLDQS_sw_mrw_op_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wl_dq_result : 8;
        unsigned int gt_result : 8;
        unsigned int gds_result : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPACKPHY_UC_SWTRLT_UNION;
#endif
#define SOC_HIPACKPHY_UC_SWTRLT_wl_dq_result_START (0)
#define SOC_HIPACKPHY_UC_SWTRLT_wl_dq_result_END (7)
#define SOC_HIPACKPHY_UC_SWTRLT_gt_result_START (8)
#define SOC_HIPACKPHY_UC_SWTRLT_gt_result_END (15)
#define SOC_HIPACKPHY_UC_SWTRLT_gds_result_START (16)
#define SOC_HIPACKPHY_UC_SWTRLT_gds_result_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_mrr_data_selected : 16;
        unsigned int reserved_0 : 3;
        unsigned int sw_cas_off_type : 1;
        unsigned int sw_cas_cs : 2;
        unsigned int sw_cas_off_req : 1;
        unsigned int sw_cas_fs_req : 1;
        unsigned int sw_mrr_data_byte_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_mrr_data_burst_sel : 2;
        unsigned int sw_enhrdqs_exit_req : 1;
        unsigned int sw_enhrdqs_entry_req : 1;
    } reg;
} SOC_HIPACKPHY_UCSWMRRDATA_UNION;
#endif
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_selected_START (0)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_selected_END (15)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_off_type_START (19)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_off_type_END (19)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_cs_START (20)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_cs_END (21)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_off_req_START (22)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_off_req_END (22)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_fs_req_START (23)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_cas_fs_req_END (23)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_byte_sel_START (24)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_byte_sel_END (26)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_burst_sel_START (28)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_mrr_data_burst_sel_END (29)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_enhrdqs_exit_req_START (30)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_enhrdqs_exit_req_END (30)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_enhrdqs_entry_req_START (31)
#define SOC_HIPACKPHY_UCSWMRRDATA_sw_enhrdqs_entry_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int sw_cat_eyet : 1;
        unsigned int reserved_1 : 5;
        unsigned int sw_cst_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int sw_cat_mrw42 : 1;
        unsigned int sw_cat_mrw48 : 1;
        unsigned int sw_cat_mrw41 : 1;
        unsigned int sw_cat_strobe : 1;
        unsigned int sw_cat_cke_high : 1;
        unsigned int sw_cat_cke_low : 1;
        unsigned int sw_cat_dqvalid : 1;
        unsigned int sw_cat_en : 1;
    } reg;
} SOC_HIPACKPHY_UCCATCONFIG_UNION;
#endif
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_eyet_START (16)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_eyet_END (16)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cst_mode_START (22)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cst_mode_END (22)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw42_START (24)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw42_END (24)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw48_START (25)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw48_END (25)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw41_START (26)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_mrw41_END (26)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_strobe_START (27)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_strobe_END (27)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_cke_high_START (28)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_cke_high_END (28)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_cke_low_START (29)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_cke_low_END (29)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_dqvalid_START (30)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_dqvalid_END (30)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_en_START (31)
#define SOC_HIPACKPHY_UCCATCONFIG_sw_cat_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_dq_result : 32;
    } reg;
} SOC_HIPACKPHY_UCPHYDQRESULT_UNION;
#endif
#define SOC_HIPACKPHY_UCPHYDQRESULT_phy_dq_result_START (0)
#define SOC_HIPACKPHY_UCPHYDQRESULT_phy_dq_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uc_sw_cat_pat_p : 10;
        unsigned int reserved_0 : 6;
        unsigned int uc_sw_cat_pat_n : 10;
        unsigned int reserved_1 : 5;
        unsigned int uc_cat_wck_tg_mask : 1;
    } reg;
} SOC_HIPACKPHY_UCSWCATPATTERN_P_UNION;
#endif
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_sw_cat_pat_p_START (0)
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_sw_cat_pat_p_END (9)
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_sw_cat_pat_n_START (16)
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_sw_cat_pat_n_END (25)
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_START (31)
#define SOC_HIPACKPHY_UCSWCATPATTERN_P_uc_cat_wck_tg_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_HIPACKPHY_UCFASTGDSRLT0_UNION;
#endif
#define SOC_HIPACKPHY_UCFASTGDSRLT0_fast_gds_result_START (0)
#define SOC_HIPACKPHY_UCFASTGDSRLT0_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gds_result : 32;
    } reg;
} SOC_HIPACKPHY_UCFASTGDSRLT1_UNION;
#endif
#define SOC_HIPACKPHY_UCFASTGDSRLT1_fast_gds_result_START (0)
#define SOC_HIPACKPHY_UCFASTGDSRLT1_fast_gds_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fast_gt_decgress : 8;
        unsigned int fast_gt_incgress : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_UCFASTGTRLT_UNION;
#endif
#define SOC_HIPACKPHY_UCFASTGTRLT_fast_gt_decgress_START (0)
#define SOC_HIPACKPHY_UCFASTGTRLT_fast_gt_decgress_END (7)
#define SOC_HIPACKPHY_UCFASTGTRLT_fast_gt_incgress_START (8)
#define SOC_HIPACKPHY_UCFASTGTRLT_fast_gt_incgress_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_rdqs_status : 16;
        unsigned int trkdbg_rdqs_pristatus : 16;
    } reg;
} SOC_HIPACKPHY_UCTRKDBG_RDQS_UNION;
#endif
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_trkdbg_rdqs_status_START (0)
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_trkdbg_rdqs_status_END (15)
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_START (16)
#define SOC_HIPACKPHY_UCTRKDBG_RDQS_trkdbg_rdqs_pristatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_rdqsg_status : 32;
    } reg;
} SOC_HIPACKPHY_UCTRKDBG_RDQSG0_UNION;
#endif
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_START (0)
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG0_trkdbg_rdqsg_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_rdqsg_status_ph : 32;
    } reg;
} SOC_HIPACKPHY_UCTRKDBG_RDQSG1_UNION;
#endif
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_START (0)
#define SOC_HIPACKPHY_UCTRKDBG_RDQSG1_trkdbg_rdqsg_status_ph_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int phy_dqsg_stop : 8;
        unsigned int phy_dqs_stop : 8;
        unsigned int trkdbg_vref_status : 16;
    } reg;
} SOC_HIPACKPHY_UCDBG_PHYSTOP_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_phy_dqsg_stop_START (0)
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_phy_dqsg_stop_END (7)
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_phy_dqs_stop_START (8)
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_phy_dqs_stop_END (15)
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_trkdbg_vref_status_START (16)
#define SOC_HIPACKPHY_UCDBG_PHYSTOP_trkdbg_vref_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dm_rdata : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT0_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT0_trkdbg_perbit_dm_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata1 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT1_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT1_trkdbg_perbit_dq_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata2 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT2_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT2_trkdbg_perbit_dq_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata3 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT3_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT3_trkdbg_perbit_dq_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata4 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT4_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT4_trkdbg_perbit_dq_rdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dm_rdata1 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT5_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT5_trkdbg_perbit_dm_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata5 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT6_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT6_trkdbg_perbit_dq_rdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trkdbg_perbit_dq_rdata6 : 32;
    } reg;
} SOC_HIPACKPHY_UCDBG_PERBIT7_UNION;
#endif
#define SOC_HIPACKPHY_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_START (0)
#define SOC_HIPACKPHY_UCDBG_PERBIT7_trkdbg_perbit_dq_rdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int reserved_0 : 1;
        unsigned int wdm_sel : 1;
        unsigned int wecc_sel : 1;
        unsigned int reserved_1 : 7;
        unsigned int wdqn_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_WDQNAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDQNAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_WDQNAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_WDQNAUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_WDQNAUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_WDQNAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_WDQNAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_WDQNAUC_wdm_sel_START (15)
#define SOC_HIPACKPHY_UC_WDQNAUC_wdm_sel_END (15)
#define SOC_HIPACKPHY_UC_WDQNAUC_wecc_sel_START (16)
#define SOC_HIPACKPHY_UC_WDQNAUC_wecc_sel_END (16)
#define SOC_HIPACKPHY_UC_WDQNAUC_wdqn_sel_START (24)
#define SOC_HIPACKPHY_UC_WDQNAUC_wdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alu_operator : 3;
        unsigned int src_sel : 1;
        unsigned int alu_operand : 10;
        unsigned int even_odd : 1;
        unsigned int rdbi_sel : 1;
        unsigned int reserved : 8;
        unsigned int rdqn_sel : 8;
    } reg;
} SOC_HIPACKPHY_UC_RDQNAUC_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQNAUC_alu_operator_START (0)
#define SOC_HIPACKPHY_UC_RDQNAUC_alu_operator_END (2)
#define SOC_HIPACKPHY_UC_RDQNAUC_src_sel_START (3)
#define SOC_HIPACKPHY_UC_RDQNAUC_src_sel_END (3)
#define SOC_HIPACKPHY_UC_RDQNAUC_alu_operand_START (4)
#define SOC_HIPACKPHY_UC_RDQNAUC_alu_operand_END (13)
#define SOC_HIPACKPHY_UC_RDQNAUC_even_odd_START (14)
#define SOC_HIPACKPHY_UC_RDQNAUC_even_odd_END (14)
#define SOC_HIPACKPHY_UC_RDQNAUC_rdbi_sel_START (15)
#define SOC_HIPACKPHY_UC_RDQNAUC_rdbi_sel_END (15)
#define SOC_HIPACKPHY_UC_RDQNAUC_rdqn_sel_START (24)
#define SOC_HIPACKPHY_UC_RDQNAUC_rdqn_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtrain_active : 1;
        unsigned int dm_cmpres_even : 1;
        unsigned int dm_cmpres_odd : 1;
        unsigned int dm_cmpres : 1;
        unsigned int dq_cmpres_even : 8;
        unsigned int dq_cmpres_odd : 8;
        unsigned int cmpres : 8;
        unsigned int det_all_passed : 1;
        unsigned int det_any_passed : 1;
        unsigned int det_all_failed : 1;
        unsigned int det_any_failed : 1;
    } reg;
} SOC_HIPACKPHY_UC_DTRSTS_UNION;
#endif
#define SOC_HIPACKPHY_UC_DTRSTS_dtrain_active_START (0)
#define SOC_HIPACKPHY_UC_DTRSTS_dtrain_active_END (0)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_even_START (1)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_even_END (1)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_odd_START (2)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_odd_END (2)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_START (3)
#define SOC_HIPACKPHY_UC_DTRSTS_dm_cmpres_END (3)
#define SOC_HIPACKPHY_UC_DTRSTS_dq_cmpres_even_START (4)
#define SOC_HIPACKPHY_UC_DTRSTS_dq_cmpres_even_END (11)
#define SOC_HIPACKPHY_UC_DTRSTS_dq_cmpres_odd_START (12)
#define SOC_HIPACKPHY_UC_DTRSTS_dq_cmpres_odd_END (19)
#define SOC_HIPACKPHY_UC_DTRSTS_cmpres_START (20)
#define SOC_HIPACKPHY_UC_DTRSTS_cmpres_END (27)
#define SOC_HIPACKPHY_UC_DTRSTS_det_all_passed_START (28)
#define SOC_HIPACKPHY_UC_DTRSTS_det_all_passed_END (28)
#define SOC_HIPACKPHY_UC_DTRSTS_det_any_passed_START (29)
#define SOC_HIPACKPHY_UC_DTRSTS_det_any_passed_END (29)
#define SOC_HIPACKPHY_UC_DTRSTS_det_all_failed_START (30)
#define SOC_HIPACKPHY_UC_DTRSTS_det_all_failed_END (30)
#define SOC_HIPACKPHY_UC_DTRSTS_det_any_failed_START (31)
#define SOC_HIPACKPHY_UC_DTRSTS_det_any_failed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdq_carry : 8;
        unsigned int wdbi_carry : 1;
        unsigned int wecc_carry : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_HIPACKPHY_UC_WDQNAUC2_UNION;
#endif
#define SOC_HIPACKPHY_UC_WDQNAUC2_wdq_carry_START (0)
#define SOC_HIPACKPHY_UC_WDQNAUC2_wdq_carry_END (7)
#define SOC_HIPACKPHY_UC_WDQNAUC2_wdbi_carry_START (8)
#define SOC_HIPACKPHY_UC_WDQNAUC2_wdbi_carry_END (8)
#define SOC_HIPACKPHY_UC_WDQNAUC2_wecc_carry_START (9)
#define SOC_HIPACKPHY_UC_WDQNAUC2_wecc_carry_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdq_carry : 8;
        unsigned int rdbi_carry : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_HIPACKPHY_UC_RDQNAUC2_UNION;
#endif
#define SOC_HIPACKPHY_UC_RDQNAUC2_rdq_carry_START (0)
#define SOC_HIPACKPHY_UC_RDQNAUC2_rdq_carry_END (7)
#define SOC_HIPACKPHY_UC_RDQNAUC2_rdbi_carry_START (8)
#define SOC_HIPACKPHY_UC_RDQNAUC2_rdbi_carry_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RG_PTX : 2;
        unsigned int ac_dqs_offset : 3;
        unsigned int ac_dq_offset : 3;
        unsigned int reserved_0 : 1;
        unsigned int ac_dummy_offset : 3;
        unsigned int lp_ckoen_disable_phy : 1;
        unsigned int gated_txbdl_on_dclk : 1;
        unsigned int cfg_tx_gcken : 1;
        unsigned int lp_csoen_disable_phy : 1;
        unsigned int AC_IO_CK_VREF_EN : 1;
        unsigned int acctl_lp5ck_en : 1;
        unsigned int lpbk_dqs_wck_sel : 1;
        unsigned int cs_cke_swap_en : 1;
        unsigned int AC_RG_TX_CKE_EN : 2;
        unsigned int acctl_rx_cke_en : 2;
        unsigned int ac_lpbk_ls : 3;
        unsigned int AC_IO_ADDR_VREF_EN : 1;
        unsigned int AC_IO_CS_VREF_EN : 1;
        unsigned int reg_ckdata_tick_sel : 1;
        unsigned int refsel_table_sel_ac : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_HIPACKPHY_ACCTRL_TRX0_UNION;
#endif
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_RG_PTX_START (0)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_RG_PTX_END (1)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dqs_offset_START (2)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dqs_offset_END (4)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dq_offset_START (5)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dq_offset_END (7)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dummy_offset_START (9)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_dummy_offset_END (11)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lp_ckoen_disable_phy_START (12)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lp_ckoen_disable_phy_END (12)
#define SOC_HIPACKPHY_ACCTRL_TRX0_gated_txbdl_on_dclk_START (13)
#define SOC_HIPACKPHY_ACCTRL_TRX0_gated_txbdl_on_dclk_END (13)
#define SOC_HIPACKPHY_ACCTRL_TRX0_cfg_tx_gcken_START (14)
#define SOC_HIPACKPHY_ACCTRL_TRX0_cfg_tx_gcken_END (14)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lp_csoen_disable_phy_START (15)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lp_csoen_disable_phy_END (15)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_CK_VREF_EN_START (16)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_CK_VREF_EN_END (16)
#define SOC_HIPACKPHY_ACCTRL_TRX0_acctl_lp5ck_en_START (17)
#define SOC_HIPACKPHY_ACCTRL_TRX0_acctl_lp5ck_en_END (17)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lpbk_dqs_wck_sel_START (18)
#define SOC_HIPACKPHY_ACCTRL_TRX0_lpbk_dqs_wck_sel_END (18)
#define SOC_HIPACKPHY_ACCTRL_TRX0_cs_cke_swap_en_START (19)
#define SOC_HIPACKPHY_ACCTRL_TRX0_cs_cke_swap_en_END (19)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_RG_TX_CKE_EN_START (20)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_RG_TX_CKE_EN_END (21)
#define SOC_HIPACKPHY_ACCTRL_TRX0_acctl_rx_cke_en_START (22)
#define SOC_HIPACKPHY_ACCTRL_TRX0_acctl_rx_cke_en_END (23)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_lpbk_ls_START (24)
#define SOC_HIPACKPHY_ACCTRL_TRX0_ac_lpbk_ls_END (26)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_ADDR_VREF_EN_START (27)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_ADDR_VREF_EN_END (27)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_CS_VREF_EN_START (28)
#define SOC_HIPACKPHY_ACCTRL_TRX0_AC_IO_CS_VREF_EN_END (28)
#define SOC_HIPACKPHY_ACCTRL_TRX0_reg_ckdata_tick_sel_START (29)
#define SOC_HIPACKPHY_ACCTRL_TRX0_reg_ckdata_tick_sel_END (29)
#define SOC_HIPACKPHY_ACCTRL_TRX0_refsel_table_sel_ac_START (30)
#define SOC_HIPACKPHY_ACCTRL_TRX0_refsel_table_sel_ac_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acctl_rx_en : 9;
        unsigned int acctl_ck_en : 1;
        unsigned int reserved_0 : 4;
        unsigned int acctl_reset_o : 1;
        unsigned int reserved_1 : 1;
        unsigned int AC_RG_TX_EN : 9;
        unsigned int reserved_2 : 4;
        unsigned int cfg_rxfifo_rstn : 1;
        unsigned int reserved_3 : 1;
        unsigned int cfg_dev_mode : 1;
    } reg;
} SOC_HIPACKPHY_ACCTRL_TRX1_UNION;
#endif
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_rx_en_START (0)
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_rx_en_END (8)
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_ck_en_START (9)
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_ck_en_END (9)
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_reset_o_START (14)
#define SOC_HIPACKPHY_ACCTRL_TRX1_acctl_reset_o_END (14)
#define SOC_HIPACKPHY_ACCTRL_TRX1_AC_RG_TX_EN_START (16)
#define SOC_HIPACKPHY_ACCTRL_TRX1_AC_RG_TX_EN_END (24)
#define SOC_HIPACKPHY_ACCTRL_TRX1_cfg_rxfifo_rstn_START (29)
#define SOC_HIPACKPHY_ACCTRL_TRX1_cfg_rxfifo_rstn_END (29)
#define SOC_HIPACKPHY_ACCTRL_TRX1_cfg_dev_mode_START (31)
#define SOC_HIPACKPHY_ACCTRL_TRX1_cfg_dev_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acctl_rx_bypass_en : 8;
        unsigned int acctl_rxclk_inv : 1;
        unsigned int reserved_0 : 16;
        unsigned int acctl_txclk_inv : 1;
        unsigned int reserved_1 : 2;
        unsigned int acctl_rx_cke_bypass_en : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HIPACKPHY_ACCTL_BYPASS_UNION;
#endif
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rx_bypass_en_START (0)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rx_bypass_en_END (7)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rxclk_inv_START (8)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rxclk_inv_END (8)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_txclk_inv_START (25)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_txclk_inv_END (25)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rx_cke_bypass_en_START (28)
#define SOC_HIPACKPHY_ACCTL_BYPASS_acctl_rx_cke_bypass_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_BIAS_EN : 11;
        unsigned int reg_CKE_RG_PGX : 6;
        unsigned int reg_CKE_RG_NGX : 6;
        unsigned int reserved : 9;
    } reg;
} SOC_HIPACKPHY_AC_IECTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_IECTRL0_AC_BIAS_EN_START (0)
#define SOC_HIPACKPHY_AC_IECTRL0_AC_BIAS_EN_END (10)
#define SOC_HIPACKPHY_AC_IECTRL0_reg_CKE_RG_PGX_START (11)
#define SOC_HIPACKPHY_AC_IECTRL0_reg_CKE_RG_PGX_END (16)
#define SOC_HIPACKPHY_AC_IECTRL0_reg_CKE_RG_NGX_START (17)
#define SOC_HIPACKPHY_AC_IECTRL0_reg_CKE_RG_NGX_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_CK_RG_EQ_RP : 6;
        unsigned int reserved_0 : 2;
        unsigned int reg_CK_RG_EQ_C : 5;
        unsigned int reserved_1 : 3;
        unsigned int AC_IE : 11;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_HIPACKPHY_AC_IECTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_IECTRL1_reg_CK_RG_EQ_RP_START (0)
#define SOC_HIPACKPHY_AC_IECTRL1_reg_CK_RG_EQ_RP_END (5)
#define SOC_HIPACKPHY_AC_IECTRL1_reg_CK_RG_EQ_C_START (8)
#define SOC_HIPACKPHY_AC_IECTRL1_reg_CK_RG_EQ_C_END (12)
#define SOC_HIPACKPHY_AC_IECTRL1_AC_IE_START (16)
#define SOC_HIPACKPHY_AC_IECTRL1_AC_IE_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_SE_CLKD_4_7 : 4;
        unsigned int reserved_0 : 4;
        unsigned int AC_SE_CLKD : 4;
        unsigned int reserved_1 : 3;
        unsigned int reg_AC_DA_SIG_SW : 1;
        unsigned int reg_AC_RG_PRESET_DQS : 2;
        unsigned int reg_AC_DA_OE_OPTION : 1;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_HIPACKPHY_AC_RX_SET_UNION;
#endif
#define SOC_HIPACKPHY_AC_RX_SET_AC_SE_CLKD_4_7_START (0)
#define SOC_HIPACKPHY_AC_RX_SET_AC_SE_CLKD_4_7_END (3)
#define SOC_HIPACKPHY_AC_RX_SET_AC_SE_CLKD_START (8)
#define SOC_HIPACKPHY_AC_RX_SET_AC_SE_CLKD_END (11)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_DA_SIG_SW_START (15)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_DA_SIG_SW_END (15)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_RG_PRESET_DQS_START (16)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_RG_PRESET_DQS_END (17)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_DA_OE_OPTION_START (18)
#define SOC_HIPACKPHY_AC_RX_SET_reg_AC_DA_OE_OPTION_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RT_UPDNCOUNT : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_DATA_NU_DE : 3;
        unsigned int reserved_1 : 9;
        unsigned int AC_RX_PRESET_DQ : 2;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_HIPACKPHY_AC_RX_SET1_UNION;
#endif
#define SOC_HIPACKPHY_AC_RX_SET1_AC_RT_UPDNCOUNT_START (0)
#define SOC_HIPACKPHY_AC_RX_SET1_AC_RT_UPDNCOUNT_END (2)
#define SOC_HIPACKPHY_AC_RX_SET1_AC_DATA_NU_DE_START (4)
#define SOC_HIPACKPHY_AC_RX_SET1_AC_DATA_NU_DE_END (6)
#define SOC_HIPACKPHY_AC_RX_SET1_AC_RX_PRESET_DQ_START (16)
#define SOC_HIPACKPHY_AC_RX_SET1_AC_RX_PRESET_DQ_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_MODE0 : 2;
        unsigned int AC_IO_MODE1 : 2;
        unsigned int AC_IO_MODE2 : 2;
        unsigned int AC_IO_MODE3 : 2;
        unsigned int AC_IO_MODE4 : 2;
        unsigned int AC_IO_MODE5 : 2;
        unsigned int AC_IO_MODE6 : 2;
        unsigned int AC_IO_MODE7 : 2;
        unsigned int AC_IO_MODE8 : 2;
        unsigned int AC_IO_MODE9 : 2;
        unsigned int reserved_0 : 4;
        unsigned int AC_IO_RXMODE : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_TXMODE : 2;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HIPACKPHY_AC_IOMODE_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE0_START (0)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE0_END (1)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE1_START (2)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE1_END (3)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE2_START (4)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE2_END (5)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE3_START (6)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE3_END (7)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE4_START (8)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE4_END (9)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE5_START (10)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE5_END (11)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE6_START (12)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE6_END (13)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE7_START (14)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE7_END (15)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE8_START (16)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE8_END (17)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE9_START (18)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_MODE9_END (19)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_RXMODE_START (24)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_RXMODE_END (26)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_TXMODE_START (28)
#define SOC_HIPACKPHY_AC_IOMODE_AC_IO_TXMODE_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_REFRANGE0 : 4;
        unsigned int AC_IO_REFRANGE1 : 4;
        unsigned int AC_IO_REFRANGE2 : 4;
        unsigned int AC_IO_REFRANGE3 : 4;
        unsigned int AC_IO_REFRANGE4 : 4;
        unsigned int AC_IO_REFRANGE5 : 4;
        unsigned int AC_IO_REFRANGE6 : 4;
        unsigned int AC_IO_REFRANGE7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_IOREFCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE0_START (0)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE0_END (3)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE1_START (4)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE1_END (7)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE2_START (8)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE2_END (11)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE3_START (12)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE3_END (15)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE4_START (16)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE4_END (19)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE5_START (20)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE5_END (23)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE6_START (24)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE6_END (27)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE7_START (28)
#define SOC_HIPACKPHY_AC_IOREFCTRL0_AC_IO_REFRANGE7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_REFRANGE8 : 4;
        unsigned int AC_IO_REFRANGE9 : 4;
        unsigned int AC_IO_REFRANGE10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_IOREFCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE8_START (0)
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE8_END (3)
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE9_START (4)
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE9_END (7)
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE10_START (8)
#define SOC_HIPACKPHY_AC_IOREFCTRL1_AC_IO_REFRANGE10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_REFSEL0 : 2;
        unsigned int AC_IO_REFSEL1 : 2;
        unsigned int AC_IO_REFSEL2 : 2;
        unsigned int AC_IO_REFSEL3 : 2;
        unsigned int AC_IO_REFSEL4 : 2;
        unsigned int AC_IO_REFSEL5 : 2;
        unsigned int AC_IO_REFSEL6 : 2;
        unsigned int AC_IO_REFSEL7 : 2;
        unsigned int AC_IO_REFSEL8 : 2;
        unsigned int AC_IO_REFSEL9 : 2;
        unsigned int AC_IO_REFSEL10 : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_HIPACKPHY_AC_IOREFCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL0_START (0)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL0_END (1)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL1_START (2)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL1_END (3)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL2_START (4)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL2_END (5)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL3_START (6)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL3_END (7)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL4_START (8)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL4_END (9)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL5_START (10)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL5_END (11)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL6_START (12)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL6_END (13)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL7_START (14)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL7_END (15)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL8_START (16)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL8_END (17)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL9_START (18)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL9_END (19)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL10_START (20)
#define SOC_HIPACKPHY_AC_IOREFCTRL2_AC_IO_REFSEL10_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_C0 : 8;
        unsigned int AC_IO_EQ_C1 : 8;
        unsigned int AC_IO_EQ_C2 : 8;
        unsigned int AC_IO_EQ_C3 : 8;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C0_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C0_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C1_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C1_END (15)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C2_START (16)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C2_END (23)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C3_START (24)
#define SOC_HIPACKPHY_AC_IOEQCTRL0_AC_IO_EQ_C3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_C4 : 8;
        unsigned int AC_IO_EQ_C5 : 8;
        unsigned int AC_IO_EQ_C6 : 8;
        unsigned int AC_IO_EQ_C7 : 8;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C4_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C4_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C5_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C5_END (15)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C6_START (16)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C6_END (23)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C7_START (24)
#define SOC_HIPACKPHY_AC_IOEQCTRL1_AC_IO_EQ_C7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_RP0 : 8;
        unsigned int AC_IO_EQ_RP1 : 8;
        unsigned int AC_IO_EQ_RP2 : 8;
        unsigned int AC_IO_EQ_RP3 : 8;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP0_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP0_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP1_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP1_END (15)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP2_START (16)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP2_END (23)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP3_START (24)
#define SOC_HIPACKPHY_AC_IOEQCTRL2_AC_IO_EQ_RP3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_RP4 : 8;
        unsigned int AC_IO_EQ_RP5 : 8;
        unsigned int AC_IO_EQ_RP6 : 8;
        unsigned int AC_IO_EQ_RP7 : 8;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP4_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP4_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP5_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP5_END (15)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP6_START (16)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP6_END (23)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP7_START (24)
#define SOC_HIPACKPHY_AC_IOEQCTRL3_AC_IO_EQ_RP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_PE_C0 : 3;
        unsigned int AC_IO_PRE_EN0 : 1;
        unsigned int AC_IO_PE_C1 : 3;
        unsigned int AC_IO_PRE_EN1 : 1;
        unsigned int AC_IO_PE_C2 : 3;
        unsigned int AC_IO_PRE_EN2 : 1;
        unsigned int AC_IO_PE_C3 : 3;
        unsigned int AC_IO_PRE_EN3 : 1;
        unsigned int AC_IO_PE_C4 : 3;
        unsigned int AC_IO_PRE_EN4 : 1;
        unsigned int AC_IO_PE_C5 : 3;
        unsigned int AC_IO_PRE_EN5 : 1;
        unsigned int AC_IO_PE_C6 : 3;
        unsigned int AC_IO_PRE_EN6 : 1;
        unsigned int AC_IO_PE_C7 : 3;
        unsigned int AC_IO_PRE_EN7 : 1;
    } reg;
} SOC_HIPACKPHY_AC_PECTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C0_START (0)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C0_END (2)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN0_START (3)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN0_END (3)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C1_START (4)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C1_END (6)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN1_START (7)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN1_END (7)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C2_START (8)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C2_END (10)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN2_START (11)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN2_END (11)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C3_START (12)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C3_END (14)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN3_START (15)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN3_END (15)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C4_START (16)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C4_END (18)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN4_START (19)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN4_END (19)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C5_START (20)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C5_END (22)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN5_START (23)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN5_END (23)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C6_START (24)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C6_END (26)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN6_START (27)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN6_END (27)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C7_START (28)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PE_C7_END (30)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN7_START (31)
#define SOC_HIPACKPHY_AC_PECTRL0_AC_IO_PRE_EN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_PE_C8 : 3;
        unsigned int AC_IO_PRE_EN8 : 1;
        unsigned int AC_IO_PE_C9 : 3;
        unsigned int AC_IO_PRE_EN9 : 1;
        unsigned int AC_IO_PE_C10 : 3;
        unsigned int AC_IO_PRE_EN10 : 1;
        unsigned int AC_IO_PRE_EN0_1 : 1;
        unsigned int AC_IO_PRE_EN1_1 : 1;
        unsigned int AC_IO_PRE_EN2_1 : 1;
        unsigned int AC_IO_PRE_EN3_1 : 1;
        unsigned int AC_IO_PRE_EN4_1 : 1;
        unsigned int AC_IO_PRE_EN5_1 : 1;
        unsigned int AC_IO_PRE_EN6_1 : 1;
        unsigned int AC_IO_PRE_EN7_1 : 1;
        unsigned int AC_IO_PRE_EN8_1 : 1;
        unsigned int AC_IO_PRE_EN9_1 : 1;
        unsigned int AC_IO_PRE_EN10_1 : 1;
        unsigned int AC_IO_PUPDEN_CK : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPACKPHY_AC_PECTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C8_START (0)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C8_END (2)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN8_START (3)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN8_END (3)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C9_START (4)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C9_END (6)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN9_START (7)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN9_END (7)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C10_START (8)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PE_C10_END (10)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN10_START (11)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN10_END (11)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN0_1_START (12)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN0_1_END (12)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN1_1_START (13)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN1_1_END (13)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN2_1_START (14)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN2_1_END (14)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN3_1_START (15)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN3_1_END (15)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN4_1_START (16)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN4_1_END (16)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN5_1_START (17)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN5_1_END (17)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN6_1_START (18)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN6_1_END (18)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN7_1_START (19)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN7_1_END (19)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN8_1_START (20)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN8_1_END (20)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN9_1_START (21)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN9_1_END (21)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN10_1_START (22)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PRE_EN10_1_END (22)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PUPDEN_CK_START (23)
#define SOC_HIPACKPHY_AC_PECTRL1_AC_IO_PUPDEN_CK_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_PULLDN0 : 1;
        unsigned int AC_IO_PULLDN1 : 1;
        unsigned int AC_IO_PULLDN2 : 1;
        unsigned int AC_IO_PULLDN3 : 1;
        unsigned int AC_IO_PULLDN4 : 1;
        unsigned int AC_IO_PULLDN5 : 1;
        unsigned int AC_IO_PULLDN6 : 1;
        unsigned int AC_IO_PULLDN7 : 1;
        unsigned int AC_IO_PULLDN8 : 1;
        unsigned int AC_IO_PULLDN9 : 1;
        unsigned int AC_IO_PULLDN10 : 1;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_PUPDMODE : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_HIPACKPHY_AC_PUPDCTRL_UNION;
#endif
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN0_START (0)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN0_END (0)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN1_START (1)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN1_END (1)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN2_START (2)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN2_END (2)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN3_START (3)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN3_END (3)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN4_START (4)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN4_END (4)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN5_START (5)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN5_END (5)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN6_START (6)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN6_END (6)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN7_START (7)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN7_END (7)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN8_START (8)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN8_END (8)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN9_START (9)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN9_END (9)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN10_START (10)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PULLDN10_END (10)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PUPDMODE_START (16)
#define SOC_HIPACKPHY_AC_PUPDCTRL_AC_IO_PUPDMODE_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_RONSEL0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_RONSEL1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_RONSEL2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_RONSEL3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int AC_IO_RONSEL4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int AC_IO_RONSEL5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int AC_IO_RONSEL6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int AC_IO_RONSEL7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_HIPACKPHY_AC_RONCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL0_START (0)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL0_END (2)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL1_START (4)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL1_END (6)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL2_START (8)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL2_END (10)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL3_START (12)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL3_END (14)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL4_START (16)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL4_END (18)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL5_START (20)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL5_END (22)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL6_START (24)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL6_END (26)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL7_START (28)
#define SOC_HIPACKPHY_AC_RONCTRL0_AC_IO_RONSEL7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_RONSEL8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_RONBSEL : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_RONSEL9 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_RONSEL10 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_HIPACKPHY_AC_RONCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL8_START (0)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL8_END (2)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONBSEL_START (4)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONBSEL_END (6)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL9_START (8)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL9_END (10)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL10_START (12)
#define SOC_HIPACKPHY_AC_RONCTRL1_AC_IO_RONSEL10_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_REG_ODTEN : 1;
        unsigned int reserved_0 : 15;
        unsigned int AC_IO_ODTTEST : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_HIPACKPHY_AC_ODTCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_ODTCTRL0_AC_IO_REG_ODTEN_START (0)
#define SOC_HIPACKPHY_AC_ODTCTRL0_AC_IO_REG_ODTEN_END (0)
#define SOC_HIPACKPHY_AC_ODTCTRL0_AC_IO_ODTTEST_START (16)
#define SOC_HIPACKPHY_AC_ODTCTRL0_AC_IO_ODTTEST_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_ODTEN : 11;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_TODTEN : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_HIPACKPHY_AC_ODTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_ODTCTRL1_AC_IO_ODTEN_START (0)
#define SOC_HIPACKPHY_AC_ODTCTRL1_AC_IO_ODTEN_END (10)
#define SOC_HIPACKPHY_AC_ODTCTRL1_AC_IO_TODTEN_START (16)
#define SOC_HIPACKPHY_AC_ODTCTRL1_AC_IO_TODTEN_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_ODTSEL0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_ODTSEL1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_ODTSEL2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int AC_IO_ODTSEL3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int AC_IO_ODTSEL4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int AC_IO_ODTSEL5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int AC_IO_ODTSEL6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int AC_IO_ODTSEL7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_HIPACKPHY_AC_ODTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL0_START (0)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL0_END (2)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL1_START (4)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL1_END (6)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL2_START (8)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL2_END (10)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL3_START (12)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL3_END (14)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL4_START (16)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL4_END (18)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL5_START (20)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL5_END (22)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL6_START (24)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL6_END (26)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL7_START (28)
#define SOC_HIPACKPHY_AC_ODTCTRL2_AC_IO_ODTSEL7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_ODTSEL8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int AC_IO_ODTSEL9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int AC_IO_ODTSEL10 : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_HIPACKPHY_AC_ODTCTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL8_START (0)
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL8_END (2)
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL9_START (4)
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL9_END (6)
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL10_START (8)
#define SOC_HIPACKPHY_AC_ODTCTRL3_AC_IO_ODTSEL10_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_IOTEST : 11;
        unsigned int reserved_0 : 5;
        unsigned int AC_IO_IETEST : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_HIPACKPHY_AC_TESTCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_TESTCTRL0_AC_IO_IOTEST_START (0)
#define SOC_HIPACKPHY_AC_TESTCTRL0_AC_IO_IOTEST_END (10)
#define SOC_HIPACKPHY_AC_TESTCTRL0_AC_IO_IETEST_START (16)
#define SOC_HIPACKPHY_AC_TESTCTRL0_AC_IO_IETEST_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_TE : 11;
        unsigned int reserved_0: 5;
        unsigned int AC_IO_TI : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_HIPACKPHY_AC_TESTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_TESTCTRL1_AC_IO_TE_START (0)
#define SOC_HIPACKPHY_AC_TESTCTRL1_AC_IO_TE_END (10)
#define SOC_HIPACKPHY_AC_TESTCTRL1_AC_IO_TI_START (16)
#define SOC_HIPACKPHY_AC_TESTCTRL1_AC_IO_TI_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_TIE : 11;
        unsigned int reserved_0: 5;
        unsigned int AC_IO_TO : 11;
        unsigned int reserved_1: 4;
        unsigned int AC_IO_NE : 1;
    } reg;
} SOC_HIPACKPHY_AC_TESTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_TIE_START (0)
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_TIE_END (10)
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_TO_START (16)
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_TO_END (26)
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_NE_START (31)
#define SOC_HIPACKPHY_AC_TESTCTRL2_AC_IO_NE_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_freq_det_ref_div_cnt : 7;
        unsigned int reg_freq_det_enable : 1;
        unsigned int reg_o_freq_det_done : 1;
        unsigned int reg_o_freq_det_count_value : 12;
        unsigned int RG_SQ_DI_WCK : 3;
        unsigned int RG_SQ_DI_DQS : 3;
        unsigned int reserved : 1;
        unsigned int SE_CLKD_WCK : 4;
    } reg;
} SOC_HIPACKPHY_DLL_DCC_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_freq_det_ref_div_cnt_START (0)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_freq_det_ref_div_cnt_END (6)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_freq_det_enable_START (7)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_freq_det_enable_END (7)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_o_freq_det_done_START (8)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_o_freq_det_done_END (8)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_o_freq_det_count_value_START (9)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_reg_o_freq_det_count_value_END (20)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_RG_SQ_DI_WCK_START (21)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_RG_SQ_DI_WCK_END (23)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_RG_SQ_DI_DQS_START (24)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_RG_SQ_DI_DQS_END (26)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_SE_CLKD_WCK_START (28)
#define SOC_HIPACKPHY_DLL_DCC_CTRL0_SE_CLKD_WCK_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DLL_EN : 1;
        unsigned int DLL_PRE_DIV : 2;
        unsigned int DLL_RG_CLK_DIV : 1;
        unsigned int DLL_DOUT : 1;
        unsigned int reserved_0 : 2;
        unsigned int DLL_RSTN : 1;
        unsigned int DLL_MASK : 2;
        unsigned int RG_SQ_DI_CK : 3;
        unsigned int reserved_1 : 2;
        unsigned int EN_SP_WCK : 1;
        unsigned int DLL_INITIAL : 10;
        unsigned int SE_CLKD_DQS : 4;
        unsigned int EN_SP_DQS : 1;
        unsigned int reg_freq_det_free_run_en : 1;
    } reg;
} SOC_HIPACKPHY_DLL_DCC_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_EN_START (0)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_EN_END (0)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_PRE_DIV_START (1)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_PRE_DIV_END (2)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_RG_CLK_DIV_START (3)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_RG_CLK_DIV_END (3)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_DOUT_START (4)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_DOUT_END (4)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_RSTN_START (7)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_RSTN_END (7)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_MASK_START (8)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_MASK_END (9)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_RG_SQ_DI_CK_START (10)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_RG_SQ_DI_CK_END (12)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_EN_SP_WCK_START (15)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_EN_SP_WCK_END (15)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_INITIAL_START (16)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_DLL_INITIAL_END (25)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_SE_CLKD_DQS_START (26)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_SE_CLKD_DQS_END (29)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_EN_SP_DQS_START (30)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_EN_SP_DQS_END (30)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_reg_freq_det_free_run_en_START (31)
#define SOC_HIPACKPHY_DLL_DCC_CTRL1_reg_freq_det_free_run_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_P_DN0 : 4;
        unsigned int AC_TX_DCC_P_DN1 : 4;
        unsigned int AC_TX_DCC_P_DN2 : 4;
        unsigned int AC_TX_DCC_P_DN3 : 4;
        unsigned int AC_TX_DCC_P_DN4 : 4;
        unsigned int AC_TX_DCC_P_DN5 : 4;
        unsigned int AC_TX_DCC_P_DN6 : 4;
        unsigned int AC_TX_DCC_P_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN0_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN0_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN1_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN1_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN2_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN2_END (11)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN3_START (12)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN3_END (15)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN4_START (16)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN4_END (19)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN5_START (20)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN5_END (23)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN6_START (24)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN6_END (27)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN7_START (28)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL0_AC_TX_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_P_DN8 : 4;
        unsigned int AC_TX_DCC_P_DN9 : 4;
        unsigned int AC_TX_DCC_P_DN10 : 4;
        unsigned int reg_freq_det_th : 12;
        unsigned int reg_freq_det_th_mrg : 8;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN8_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN8_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN9_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN9_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN10_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_AC_TX_DCC_P_DN10_END (11)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_START (12)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_END (23)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_mrg_START (24)
#define SOC_HIPACKPHY_AC_TXDCC_PDN_CTRL1_reg_freq_det_th_mrg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_N_DN0 : 4;
        unsigned int AC_TX_DCC_N_DN1 : 4;
        unsigned int AC_TX_DCC_N_DN2 : 4;
        unsigned int AC_TX_DCC_N_DN3 : 4;
        unsigned int AC_TX_DCC_N_DN4 : 4;
        unsigned int AC_TX_DCC_N_DN5 : 4;
        unsigned int AC_TX_DCC_N_DN6 : 4;
        unsigned int AC_TX_DCC_N_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN0_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN0_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN1_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN1_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN2_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN2_END (11)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN3_START (12)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN3_END (15)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN4_START (16)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN4_END (19)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN5_START (20)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN5_END (23)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN6_START (24)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN6_END (27)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN7_START (28)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL2_AC_TX_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_N_DN8 : 4;
        unsigned int AC_TX_DCC_N_DN9 : 4;
        unsigned int AC_TX_DCC_N_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN8_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN8_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN9_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN9_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN10_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_NDN_CTRL3_AC_TX_DCC_N_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_P_UP0 : 4;
        unsigned int AC_TX_DCC_P_UP1 : 4;
        unsigned int AC_TX_DCC_P_UP2 : 4;
        unsigned int AC_TX_DCC_P_UP3 : 4;
        unsigned int AC_TX_DCC_P_UP4 : 4;
        unsigned int AC_TX_DCC_P_UP5 : 4;
        unsigned int AC_TX_DCC_P_UP6 : 4;
        unsigned int AC_TX_DCC_P_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP0_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP0_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP1_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP1_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP2_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP2_END (11)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP3_START (12)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP3_END (15)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP4_START (16)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP4_END (19)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP5_START (20)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP5_END (23)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP6_START (24)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP6_END (27)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP7_START (28)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL0_AC_TX_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_P_UP8 : 4;
        unsigned int AC_TX_DCC_P_UP9 : 4;
        unsigned int AC_TX_DCC_P_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP8_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP8_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP9_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP9_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP10_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_PUP_CTRL1_AC_TX_DCC_P_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_N_UP0 : 4;
        unsigned int AC_TX_DCC_N_UP1 : 4;
        unsigned int AC_TX_DCC_N_UP2 : 4;
        unsigned int AC_TX_DCC_N_UP3 : 4;
        unsigned int AC_TX_DCC_N_UP4 : 4;
        unsigned int AC_TX_DCC_N_UP5 : 4;
        unsigned int AC_TX_DCC_N_UP6 : 4;
        unsigned int AC_TX_DCC_N_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP0_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP0_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP1_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP1_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP2_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP2_END (11)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP3_START (12)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP3_END (15)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP4_START (16)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP4_END (19)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP5_START (20)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP5_END (23)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP6_START (24)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP6_END (27)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP7_START (28)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL2_AC_TX_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_TX_DCC_N_UP8 : 4;
        unsigned int AC_TX_DCC_N_UP9 : 4;
        unsigned int AC_TX_DCC_N_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP8_START (0)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP8_END (3)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP9_START (4)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP9_END (7)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP10_START (8)
#define SOC_HIPACKPHY_AC_TXDCC_NUP_CTRL3_AC_TX_DCC_N_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_P_DN0 : 4;
        unsigned int AC_RX_DCC_P_DN1 : 4;
        unsigned int AC_RX_DCC_P_DN2 : 4;
        unsigned int AC_RX_DCC_P_DN3 : 4;
        unsigned int AC_RX_DCC_P_DN4 : 4;
        unsigned int AC_RX_DCC_P_DN5 : 4;
        unsigned int AC_RX_DCC_P_DN6 : 4;
        unsigned int AC_RX_DCC_P_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN0_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN0_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN1_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN1_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN2_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN2_END (11)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN3_START (12)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN3_END (15)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN4_START (16)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN4_END (19)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN5_START (20)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN5_END (23)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN6_START (24)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN6_END (27)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN7_START (28)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL0_AC_RX_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_P_DN8 : 4;
        unsigned int AC_RX_DCC_P_DN9 : 4;
        unsigned int AC_RX_DCC_P_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN8_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN8_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN9_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN9_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN10_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_PDN_CTRL1_AC_RX_DCC_P_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_N_DN0 : 4;
        unsigned int AC_RX_DCC_N_DN1 : 4;
        unsigned int AC_RX_DCC_N_DN2 : 4;
        unsigned int AC_RX_DCC_N_DN3 : 4;
        unsigned int AC_RX_DCC_N_DN4 : 4;
        unsigned int AC_RX_DCC_N_DN5 : 4;
        unsigned int AC_RX_DCC_N_DN6 : 4;
        unsigned int AC_RX_DCC_N_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN0_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN0_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN1_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN1_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN2_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN2_END (11)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN3_START (12)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN3_END (15)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN4_START (16)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN4_END (19)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN5_START (20)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN5_END (23)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN6_START (24)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN6_END (27)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN7_START (28)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL2_AC_RX_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_N_DN8 : 4;
        unsigned int AC_RX_DCC_N_DN9 : 4;
        unsigned int AC_RX_DCC_N_DN10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN8_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN8_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN9_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN9_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN10_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_NDN_CTRL3_AC_RX_DCC_N_DN10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_P_UP0 : 4;
        unsigned int AC_RX_DCC_P_UP1 : 4;
        unsigned int AC_RX_DCC_P_UP2 : 4;
        unsigned int AC_RX_DCC_P_UP3 : 4;
        unsigned int AC_RX_DCC_P_UP4 : 4;
        unsigned int AC_RX_DCC_P_UP5 : 4;
        unsigned int AC_RX_DCC_P_UP6 : 4;
        unsigned int AC_RX_DCC_P_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP0_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP0_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP1_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP1_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP2_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP2_END (11)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP3_START (12)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP3_END (15)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP4_START (16)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP4_END (19)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP5_START (20)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP5_END (23)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP6_START (24)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP6_END (27)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP7_START (28)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL0_AC_RX_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_P_UP8 : 4;
        unsigned int AC_RX_DCC_P_UP9 : 4;
        unsigned int AC_RX_DCC_P_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP8_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP8_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP9_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP9_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP10_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_PUP_CTRL1_AC_RX_DCC_P_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_N_UP0 : 4;
        unsigned int AC_RX_DCC_N_UP1 : 4;
        unsigned int AC_RX_DCC_N_UP2 : 4;
        unsigned int AC_RX_DCC_N_UP3 : 4;
        unsigned int AC_RX_DCC_N_UP4 : 4;
        unsigned int AC_RX_DCC_N_UP5 : 4;
        unsigned int AC_RX_DCC_N_UP6 : 4;
        unsigned int AC_RX_DCC_N_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP0_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP0_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP1_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP1_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP2_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP2_END (11)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP3_START (12)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP3_END (15)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP4_START (16)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP4_END (19)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP5_START (20)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP5_END (23)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP6_START (24)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP6_END (27)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP7_START (28)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL2_AC_RX_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RX_DCC_N_UP8 : 4;
        unsigned int AC_RX_DCC_N_UP9 : 4;
        unsigned int AC_RX_DCC_N_UP10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP8_START (0)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP8_END (3)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP9_START (4)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP9_END (7)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP10_START (8)
#define SOC_HIPACKPHY_AC_RXDCC_NUP_CTRL3_AC_RX_DCC_N_UP10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RG_TEST0 : 8;
        unsigned int AC_RG_TEST1 : 8;
        unsigned int AC_RG_TEST2 : 8;
        unsigned int AC_RG_TEST3 : 8;
    } reg;
} SOC_HIPACKPHY_AC_RG_TEST_CTL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST0_START (0)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST0_END (7)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST1_START (8)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST1_END (15)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST2_START (16)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST2_END (23)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST3_START (24)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL0_AC_RG_TEST3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RG_TEST4 : 8;
        unsigned int AC_RG_TEST5 : 8;
        unsigned int AC_RG_TEST6 : 8;
        unsigned int AC_RG_TEST7 : 8;
    } reg;
} SOC_HIPACKPHY_AC_RG_TEST_CTL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST4_START (0)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST4_END (7)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST5_START (8)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST5_END (15)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST6_START (16)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST6_END (23)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST7_START (24)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL1_AC_RG_TEST7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_RG_TEST8 : 8;
        unsigned int AC_RG_TEST9 : 8;
        unsigned int AC_RG_TEST10 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPACKPHY_AC_RG_TEST_CTL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST8_START (0)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST8_END (7)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST9_START (8)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST9_END (15)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST10_START (16)
#define SOC_HIPACKPHY_AC_RG_TEST_CTL2_AC_RG_TEST10_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DLL_MEA_CODE : 10;
        unsigned int DLL_MEA_DONE : 1;
        unsigned int DLL_MEA_EN : 1;
        unsigned int DLL_cfg_match_0 : 1;
        unsigned int DLL_cfg_match_1 : 1;
        unsigned int DLL_MEA_GCKEN : 1;
        unsigned int DLL_cfg_mulsmp_en : 1;
        unsigned int DLL_cfg_cstep : 4;
        unsigned int DLL_cfg_timer : 3;
        unsigned int reserved : 9;
    } reg;
} SOC_HIPACKPHY_AC_DLL_CODE_UNION;
#endif
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_CODE_START (0)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_CODE_END (9)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_DONE_START (10)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_DONE_END (10)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_EN_START (11)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_EN_END (11)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_match_0_START (12)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_match_0_END (12)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_match_1_START (13)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_match_1_END (13)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_GCKEN_START (14)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_MEA_GCKEN_END (14)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_mulsmp_en_START (15)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_mulsmp_en_END (15)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_cstep_START (16)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_cstep_END (19)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_timer_START (20)
#define SOC_HIPACKPHY_AC_DLL_CODE_DLL_cfg_timer_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ZQ_OFFSETK : 4;
        unsigned int SFIO_MODE : 3;
        unsigned int reg_ZQ_OFFSETK_EN : 1;
        unsigned int SFIO_PULLDN : 3;
        unsigned int reg_ZQ_COMPIN_SWAP : 1;
        unsigned int SFIO_IOTEST : 3;
        unsigned int reserved_0 : 1;
        unsigned int SFIO_IETEST : 3;
        unsigned int reserved_1 : 1;
        unsigned int SFIO_TI : 3;
        unsigned int reserved_2 : 1;
        unsigned int SFIO_TE : 3;
        unsigned int reserved_3 : 1;
        unsigned int SFIO_TIE : 3;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_HIPACKPHY_AC_SFIO_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_START (0)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_END (3)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_MODE_START (4)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_MODE_END (6)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_EN_START (7)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_OFFSETK_EN_END (7)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_PULLDN_START (8)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_PULLDN_END (10)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_COMPIN_SWAP_START (11)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_reg_ZQ_COMPIN_SWAP_END (11)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_IOTEST_START (12)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_IOTEST_END (14)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_IETEST_START (16)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_IETEST_END (18)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TI_START (20)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TI_END (22)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TE_START (24)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TE_END (26)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TIE_START (28)
#define SOC_HIPACKPHY_AC_SFIO_CTRL0_SFIO_TIE_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SFIO_RONSEL : 9;
        unsigned int reserved_0 : 7;
        unsigned int SFIO_TO : 3;
        unsigned int reserved_1 : 12;
        unsigned int reg_ZQ_EN : 1;
    } reg;
} SOC_HIPACKPHY_AC_SFIO_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_SFIO_RONSEL_START (0)
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_SFIO_RONSEL_END (8)
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_SFIO_TO_START (16)
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_SFIO_TO_END (18)
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_reg_ZQ_EN_START (31)
#define SOC_HIPACKPHY_AC_SFIO_CTRL1_reg_ZQ_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxaddr0_bdl : 10;
        unsigned int rxaddr1_bdl : 10;
        unsigned int rxaddr2_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_AC_BDL_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr0_bdl_START (0)
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr0_bdl_END (9)
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr1_bdl_START (10)
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr1_bdl_END (19)
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr2_bdl_START (20)
#define SOC_HIPACKPHY_AC_BDL_CTRL0_rxaddr2_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxaddr3_bdl : 10;
        unsigned int rxaddr4_bdl : 10;
        unsigned int rxaddr5_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_AC_BDL_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr3_bdl_START (0)
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr3_bdl_END (9)
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr4_bdl_START (10)
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr4_bdl_END (19)
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr5_bdl_START (20)
#define SOC_HIPACKPHY_AC_BDL_CTRL1_rxaddr5_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ck_bdl : 10;
        unsigned int rxck_bdl : 10;
        unsigned int rxcs0_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_AC_BDL_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_AC_BDL_CTRL2_ck_bdl_START (0)
#define SOC_HIPACKPHY_AC_BDL_CTRL2_ck_bdl_END (9)
#define SOC_HIPACKPHY_AC_BDL_CTRL2_rxck_bdl_START (10)
#define SOC_HIPACKPHY_AC_BDL_CTRL2_rxck_bdl_END (19)
#define SOC_HIPACKPHY_AC_BDL_CTRL2_rxcs0_bdl_START (20)
#define SOC_HIPACKPHY_AC_BDL_CTRL2_rxcs0_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxcs1_bdl : 10;
        unsigned int rxcke0_bdl : 10;
        unsigned int rxcke1_bdl : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_AC_BDL_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcs1_bdl_START (0)
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcs1_bdl_END (9)
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcke0_bdl_START (10)
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcke0_bdl_END (19)
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcke1_bdl_START (20)
#define SOC_HIPACKPHY_AC_BDL_CTRL3_rxcke1_bdl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PLL_EN_BIAS_A : 1;
        unsigned int reserved_0 : 3;
        unsigned int RG_PLL_LPF_R_A : 2;
        unsigned int RG_PLL_PLL_POSDIV_A : 9;
        unsigned int RG_PLL_DLL_POSDIV_A : 9;
        unsigned int RG_PLL_PREDIV_A : 3;
        unsigned int RG_SSC_resetn_A : 1;
        unsigned int reserved_1 : 1;
        unsigned int EN_PLL_LOAD_BAND_EN_A : 1;
        unsigned int RG_SSC_resetj_A : 1;
        unsigned int RG_SSC_resetsj_A : 1;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_A_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_PLL_EN_BIAS_A_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_PLL_EN_BIAS_A_END (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_LPF_R_A_START (4)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_LPF_R_A_END (5)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_PLL_POSDIV_A_START (6)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_PLL_POSDIV_A_END (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_DLL_POSDIV_A_START (15)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_DLL_POSDIV_A_END (23)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_PREDIV_A_START (24)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_PLL_PREDIV_A_END (26)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetn_A_START (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetn_A_END (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_EN_PLL_LOAD_BAND_EN_A_START (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_EN_PLL_LOAD_BAND_EN_A_END (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetj_A_START (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetj_A_END (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetsj_A_START (31)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A_RG_SSC_resetsj_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PLL_EN_BIAS_B : 1;
        unsigned int reserved_0 : 3;
        unsigned int RG_PLL_LPF_R_B : 2;
        unsigned int RG_PLL_PLL_POSDIV_B : 9;
        unsigned int RG_PLL_DLL_POSDIV_B : 9;
        unsigned int RG_PLL_PREDIV_B : 3;
        unsigned int RG_SSC_resetn_B : 1;
        unsigned int reserved_1 : 1;
        unsigned int EN_PLL_LOAD_BAND_EN_B : 1;
        unsigned int RG_SSC_resetj_B : 1;
        unsigned int RG_SSC_resetsj_B : 1;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_B_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_PLL_EN_BIAS_B_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_PLL_EN_BIAS_B_END (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_LPF_R_B_START (4)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_LPF_R_B_END (5)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_PLL_POSDIV_B_START (6)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_PLL_POSDIV_B_END (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_DLL_POSDIV_B_START (15)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_DLL_POSDIV_B_END (23)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_PREDIV_B_START (24)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_PLL_PREDIV_B_END (26)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetn_B_START (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetn_B_END (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_EN_PLL_LOAD_BAND_EN_B_START (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_EN_PLL_LOAD_BAND_EN_B_END (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetj_B_START (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetj_B_END (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetsj_B_START (31)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B_RG_SSC_resetsj_B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_gate_en : 1;
        unsigned int phyclk_gate_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_UNION;
#endif
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_pll_gate_en_START (0)
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_pll_gate_en_END (0)
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_phyclk_gate_en_START (1)
#define SOC_HIPACKPHY_AC_PHYCLK_GATECTRL_phyclk_gate_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_C8 : 8;
        unsigned int AC_IO_EQ_C9 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL4_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL4_AC_IO_EQ_C8_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL4_AC_IO_EQ_C8_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL4_AC_IO_EQ_C9_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL4_AC_IO_EQ_C9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AC_IO_EQ_RP8 : 8;
        unsigned int AC_IO_EQ_RP9 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_AC_IOEQCTRL5_UNION;
#endif
#define SOC_HIPACKPHY_AC_IOEQCTRL5_AC_IO_EQ_RP8_START (0)
#define SOC_HIPACKPHY_AC_IOEQCTRL5_AC_IO_EQ_RP8_END (7)
#define SOC_HIPACKPHY_AC_IOEQCTRL5_AC_IO_EQ_RP9_START (8)
#define SOC_HIPACKPHY_AC_IOEQCTRL5_AC_IO_EQ_RP9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_DMY_CTR_A : 10;
        unsigned int RG_SSC_r_triangular_sel_A : 1;
        unsigned int RG_SSC_r_ups_en_A : 1;
        unsigned int RG_SSC_r_frac_en_A : 1;
        unsigned int RG_SSC_r_sdmtype_A : 1;
        unsigned int RG_KBAN_BAND_A : 12;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_A2_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_DMY_CTR_A_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_DMY_CTR_A_END (9)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_triangular_sel_A_START (10)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_triangular_sel_A_END (10)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_ups_en_A_START (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_ups_en_A_END (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_frac_en_A_START (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_frac_en_A_END (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_sdmtype_A_START (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_SSC_r_sdmtype_A_END (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_KBAN_BAND_A_START (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A2_RG_KBAN_BAND_A_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_SSC_r_triinc_A : 8;
        unsigned int RG_SSC_r_div_frac_A : 8;
        unsigned int RG_SSC_r_spreadmax_A : 8;
        unsigned int RG_SSC_r_sscdivnum_A : 4;
        unsigned int RG_SSC_r_sscdiv_en_A : 1;
        unsigned int RG_SSC_r_prbs3_en_A : 1;
        unsigned int RG_SSC_r_prbs2_en_A : 1;
        unsigned int RG_SSC_r_prbs1_en_A : 1;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_A3_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_triinc_A_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_triinc_A_END (7)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_div_frac_A_START (8)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_div_frac_A_END (15)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_spreadmax_A_START (16)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_spreadmax_A_END (23)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdivnum_A_START (24)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdivnum_A_END (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdiv_en_A_START (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_sscdiv_en_A_END (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs3_en_A_START (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs3_en_A_END (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs2_en_A_START (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs2_en_A_END (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs1_en_A_START (31)
#define SOC_HIPACKPHY_AC_PLL_CTRL_A3_RG_SSC_r_prbs1_en_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_DMY_CTR_B : 10;
        unsigned int RG_SSC_r_triangular_sel_B : 1;
        unsigned int RG_SSC_r_ups_en_B : 1;
        unsigned int RG_SSC_r_frac_en_B : 1;
        unsigned int RG_SSC_r_sdmtype_B : 1;
        unsigned int RG_KBAN_BAND_B : 12;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_B2_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_DMY_CTR_B_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_DMY_CTR_B_END (9)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_triangular_sel_B_START (10)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_triangular_sel_B_END (10)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_ups_en_B_START (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_ups_en_B_END (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_frac_en_B_START (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_frac_en_B_END (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_sdmtype_B_START (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_SSC_r_sdmtype_B_END (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_KBAN_BAND_B_START (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B2_RG_KBAN_BAND_B_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_SSC_r_triinc_B : 8;
        unsigned int RG_SSC_r_div_frac_B : 8;
        unsigned int RG_SSC_r_spreadmax_B : 8;
        unsigned int RG_SSC_r_sscdivnum_B : 4;
        unsigned int RG_SSC_r_sscdiv_en_B : 1;
        unsigned int RG_SSC_r_prbs3_en_B : 1;
        unsigned int RG_SSC_r_prbs2_en_B : 1;
        unsigned int RG_SSC_r_prbs1_en_B : 1;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_B3_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_triinc_B_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_triinc_B_END (7)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_div_frac_B_START (8)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_div_frac_B_END (15)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_spreadmax_B_START (16)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_spreadmax_B_END (23)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdivnum_B_START (24)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdivnum_B_END (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdiv_en_B_START (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_sscdiv_en_B_END (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs3_en_B_START (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs3_en_B_END (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs2_en_B_START (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs2_en_B_END (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs1_en_B_START (31)
#define SOC_HIPACKPHY_AC_PLL_CTRL_B3_RG_SSC_r_prbs1_en_B_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_SSC_r_div_int_A : 11;
        unsigned int RG_SSC_r_fracssc_en_A : 1;
        unsigned int RG_SSC_r_spread_en_A : 1;
        unsigned int PLL_LOCK_A : 1;
        unsigned int PLL_EN_A : 1;
        unsigned int reserved_0 : 1;
        unsigned int RG_SSC_r_div_int_B : 11;
        unsigned int RG_SSC_r_fracssc_en_B : 1;
        unsigned int RG_SSC_r_spread_en_B : 1;
        unsigned int PLL_LOCK_B : 1;
        unsigned int PLL_EN_B : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_HIPACKPHY_AC_PLL_CTRL_AB_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_A_START (0)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_A_END (10)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_A_START (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_A_END (11)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_A_START (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_A_END (12)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_LOCK_A_START (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_LOCK_A_END (13)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_EN_A_START (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_EN_A_END (14)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_B_START (16)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_div_int_B_END (26)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_B_START (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_fracssc_en_B_END (27)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_B_START (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_RG_SSC_r_spread_en_B_END (28)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_LOCK_B_START (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_LOCK_B_END (29)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_EN_B_START (30)
#define SOC_HIPACKPHY_AC_PLL_CTRL_AB_PLL_EN_B_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RG_PLL_RESERVE_B : 16;
        unsigned int RG_PLL_RESERVE_A : 16;
    } reg;
} SOC_HIPACKPHY_AC_PLL_RSV_CTRL_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_RG_PLL_RESERVE_B_START (0)
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_RG_PLL_RESERVE_B_END (15)
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_RG_PLL_RESERVE_A_START (16)
#define SOC_HIPACKPHY_AC_PLL_RSV_CTRL_RG_PLL_RESERVE_A_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AD_SSC_div_mode_dbgo_A : 17;
        unsigned int AD_PLL_BAND_A : 9;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPACKPHY_AC_PLL_DBG_A_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_DBG_A_AD_SSC_div_mode_dbgo_A_START (0)
#define SOC_HIPACKPHY_AC_PLL_DBG_A_AD_SSC_div_mode_dbgo_A_END (16)
#define SOC_HIPACKPHY_AC_PLL_DBG_A_AD_PLL_BAND_A_START (17)
#define SOC_HIPACKPHY_AC_PLL_DBG_A_AD_PLL_BAND_A_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AD_SSC_div_mode_dbgo_B : 17;
        unsigned int AD_PLL_BAND_B : 9;
        unsigned int reserved : 6;
    } reg;
} SOC_HIPACKPHY_AC_PLL_DBG_B_UNION;
#endif
#define SOC_HIPACKPHY_AC_PLL_DBG_B_AD_SSC_div_mode_dbgo_B_START (0)
#define SOC_HIPACKPHY_AC_PLL_DBG_B_AD_SSC_div_mode_dbgo_B_END (16)
#define SOC_HIPACKPHY_AC_PLL_DBG_B_AD_PLL_BAND_B_START (17)
#define SOC_HIPACKPHY_AC_PLL_DBG_B_AD_PLL_BAND_B_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_dbg_sel : 3;
        unsigned int reg_dbg_mode : 1;
        unsigned int reg_acctl_csoe_gated : 1;
        unsigned int reg_acctl_ckeoe_gated : 1;
        unsigned int reg_bdl_sw_rst : 1;
        unsigned int reg_dlyline_gate_bypass : 1;
        unsigned int reg_bypclk_gated_bypass : 1;
        unsigned int reg_non_ovlp_en : 1;
        unsigned int reg_acctl_addroe_gated : 6;
        unsigned int reg_pll_lock_en : 1;
        unsigned int reg_pll_lock_sel : 1;
        unsigned int reserved : 9;
        unsigned int reg_gds_rank_en : 1;
        unsigned int reg_odten_sel : 1;
        unsigned int reg_ac_lpbk_en : 1;
        unsigned int reg_phgck_rst : 1;
        unsigned int reg_dqs_pupd_mask : 1;
    } reg;
} SOC_HIPACKPHY_AC_CTRL_1_UNION;
#endif
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dbg_sel_START (0)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dbg_sel_END (2)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dbg_mode_START (3)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dbg_mode_END (3)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_csoe_gated_START (4)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_csoe_gated_END (4)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_ckeoe_gated_START (5)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_ckeoe_gated_END (5)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_bdl_sw_rst_START (6)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_bdl_sw_rst_END (6)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dlyline_gate_bypass_START (7)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dlyline_gate_bypass_END (7)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_bypclk_gated_bypass_START (8)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_bypclk_gated_bypass_END (8)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_non_ovlp_en_START (9)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_non_ovlp_en_END (9)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_addroe_gated_START (10)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_acctl_addroe_gated_END (15)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_pll_lock_en_START (16)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_pll_lock_en_END (16)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_pll_lock_sel_START (17)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_pll_lock_sel_END (17)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_gds_rank_en_START (27)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_gds_rank_en_END (27)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_odten_sel_START (28)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_odten_sel_END (28)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_ac_lpbk_en_START (29)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_ac_lpbk_en_END (29)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_phgck_rst_START (30)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_phgck_rst_END (30)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dqs_pupd_mask_START (31)
#define SOC_HIPACKPHY_AC_CTRL_1_reg_dqs_pupd_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_0 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_0_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_0_ac_rev_reg_0_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_0_ac_rev_reg_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_out_0 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_OUT_0_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_OUT_0_ac_rev_reg_out_0_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_OUT_0_ac_rev_reg_out_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_1 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_1_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_1_ac_rev_reg_1_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_1_ac_rev_reg_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_out_1 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_OUT_1_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_OUT_1_ac_rev_reg_out_1_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_OUT_1_ac_rev_reg_out_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ac_txadr_gcken : 1;
        unsigned int reg_ac_txcs_gcken : 1;
        unsigned int reg_ac_txcke_gcken : 1;
        unsigned int reg_ac_txck_gcken : 1;
        unsigned int reg_ac_txadr_phcfg : 2;
        unsigned int reg_ac_txcs_phcfg : 2;
        unsigned int reg_ac_txcke_phcfg : 2;
        unsigned int reg_ac_txck_phcfg : 2;
        unsigned int reg_ac_phcfg_auto : 1;
        unsigned int reg_ac_rx_gcken : 1;
        unsigned int reg_apb_static_reg_gcken : 1;
        unsigned int reg_pll_gate_auto_en : 1;
        unsigned int reg_pll_gate_timer : 8;
        unsigned int reg_8x_gcken : 1;
        unsigned int reserved : 4;
        unsigned int reg_ac_tx_cs_mask : 2;
        unsigned int reg_ac_tx_ck_mask : 1;
    } reg;
} SOC_HIPACKPHY_AC_GCKEN_CTRL_UNION;
#endif
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txadr_gcken_START (0)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txadr_gcken_END (0)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcs_gcken_START (1)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcs_gcken_END (1)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcke_gcken_START (2)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcke_gcken_END (2)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txck_gcken_START (3)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txck_gcken_END (3)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txadr_phcfg_START (4)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txadr_phcfg_END (5)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcs_phcfg_START (6)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcs_phcfg_END (7)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcke_phcfg_START (8)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txcke_phcfg_END (9)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txck_phcfg_START (10)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_txck_phcfg_END (11)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_phcfg_auto_START (12)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_phcfg_auto_END (12)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_rx_gcken_START (13)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_rx_gcken_END (13)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_apb_static_reg_gcken_START (14)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_apb_static_reg_gcken_END (14)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_pll_gate_auto_en_START (15)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_pll_gate_auto_en_END (15)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_pll_gate_timer_START (16)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_pll_gate_timer_END (23)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_8x_gcken_START (24)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_8x_gcken_END (24)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_tx_cs_mask_START (29)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_tx_cs_mask_END (30)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_tx_ck_mask_START (31)
#define SOC_HIPACKPHY_AC_GCKEN_CTRL_reg_ac_tx_ck_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_2 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_2_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_2_ac_rev_reg_2_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_2_ac_rev_reg_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ac_rev_reg_out_2 : 32;
    } reg;
} SOC_HIPACKPHY_AC_REV_REG_OUT_2_UNION;
#endif
#define SOC_HIPACKPHY_AC_REV_REG_OUT_2_ac_rev_reg_out_2_START (0)
#define SOC_HIPACKPHY_AC_REV_REG_OUT_2_ac_rev_reg_out_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_RG_PTX : 2;
        unsigned int reserved_0 : 2;
        unsigned int gcken_dx_phy_dyn_track_auto : 1;
        unsigned int rxdqs_inv_b0 : 1;
        unsigned int rxdqs_inv_b1 : 1;
        unsigned int cfg_gcken_dx_phy_dyn_track : 1;
        unsigned int cfg_upd_duty_mode : 4;
        unsigned int wdqs_single_mode : 1;
        unsigned int wr_pst_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int wr_pre_en : 2;
        unsigned int cfg_upd_track_gate_margin_en : 1;
        unsigned int cfg_upd_track_dq_margin_en : 1;
        unsigned int cfg_dyn_update_count_val : 3;
        unsigned int cfg_rank0_only : 1;
        unsigned int tx_dqs_inv_b0 : 1;
        unsigned int tx_dqs_inv_b1 : 1;
        unsigned int pll_switch : 2;
        unsigned int dll_in_sel : 2;
        unsigned int reg_dcc_track_rank_en : 1;
        unsigned int dqsg_track_flag_valid_en : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_HIPACKPHY_DXCTRL_TRX0_UNION;
#endif
#define SOC_HIPACKPHY_DXCTRL_TRX0_DX_RG_PTX_START (0)
#define SOC_HIPACKPHY_DXCTRL_TRX0_DX_RG_PTX_END (1)
#define SOC_HIPACKPHY_DXCTRL_TRX0_gcken_dx_phy_dyn_track_auto_START (4)
#define SOC_HIPACKPHY_DXCTRL_TRX0_gcken_dx_phy_dyn_track_auto_END (4)
#define SOC_HIPACKPHY_DXCTRL_TRX0_rxdqs_inv_b0_START (5)
#define SOC_HIPACKPHY_DXCTRL_TRX0_rxdqs_inv_b0_END (5)
#define SOC_HIPACKPHY_DXCTRL_TRX0_rxdqs_inv_b1_START (6)
#define SOC_HIPACKPHY_DXCTRL_TRX0_rxdqs_inv_b1_END (6)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_gcken_dx_phy_dyn_track_START (7)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_gcken_dx_phy_dyn_track_END (7)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_duty_mode_START (8)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_duty_mode_END (11)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wdqs_single_mode_START (12)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wdqs_single_mode_END (12)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wr_pst_en_START (13)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wr_pst_en_END (13)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wr_pre_en_START (15)
#define SOC_HIPACKPHY_DXCTRL_TRX0_wr_pre_en_END (16)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_track_gate_margin_en_START (17)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_track_gate_margin_en_END (17)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_track_dq_margin_en_START (18)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_upd_track_dq_margin_en_END (18)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_dyn_update_count_val_START (19)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_dyn_update_count_val_END (21)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_rank0_only_START (22)
#define SOC_HIPACKPHY_DXCTRL_TRX0_cfg_rank0_only_END (22)
#define SOC_HIPACKPHY_DXCTRL_TRX0_tx_dqs_inv_b0_START (23)
#define SOC_HIPACKPHY_DXCTRL_TRX0_tx_dqs_inv_b0_END (23)
#define SOC_HIPACKPHY_DXCTRL_TRX0_tx_dqs_inv_b1_START (24)
#define SOC_HIPACKPHY_DXCTRL_TRX0_tx_dqs_inv_b1_END (24)
#define SOC_HIPACKPHY_DXCTRL_TRX0_pll_switch_START (25)
#define SOC_HIPACKPHY_DXCTRL_TRX0_pll_switch_END (26)
#define SOC_HIPACKPHY_DXCTRL_TRX0_dll_in_sel_START (27)
#define SOC_HIPACKPHY_DXCTRL_TRX0_dll_in_sel_END (28)
#define SOC_HIPACKPHY_DXCTRL_TRX0_reg_dcc_track_rank_en_START (29)
#define SOC_HIPACKPHY_DXCTRL_TRX0_reg_dcc_track_rank_en_END (29)
#define SOC_HIPACKPHY_DXCTRL_TRX0_dqsg_track_flag_valid_en_START (30)
#define SOC_HIPACKPHY_DXCTRL_TRX0_dqsg_track_flag_valid_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dxctl_rx_en : 12;
        unsigned int dqs_oe_extend : 3;
        unsigned int DX_RG_TX_EN : 11;
        unsigned int dq_oe_extend : 3;
        unsigned int DX_IO_RXMODE_3_5 : 3;
    } reg;
} SOC_HIPACKPHY_DXCTRL_TRX1_UNION;
#endif
#define SOC_HIPACKPHY_DXCTRL_TRX1_dxctl_rx_en_START (0)
#define SOC_HIPACKPHY_DXCTRL_TRX1_dxctl_rx_en_END (11)
#define SOC_HIPACKPHY_DXCTRL_TRX1_dqs_oe_extend_START (12)
#define SOC_HIPACKPHY_DXCTRL_TRX1_dqs_oe_extend_END (14)
#define SOC_HIPACKPHY_DXCTRL_TRX1_DX_RG_TX_EN_START (15)
#define SOC_HIPACKPHY_DXCTRL_TRX1_DX_RG_TX_EN_END (25)
#define SOC_HIPACKPHY_DXCTRL_TRX1_dq_oe_extend_START (26)
#define SOC_HIPACKPHY_DXCTRL_TRX1_dq_oe_extend_END (28)
#define SOC_HIPACKPHY_DXCTRL_TRX1_DX_IO_RXMODE_3_5_START (29)
#define SOC_HIPACKPHY_DXCTRL_TRX1_DX_IO_RXMODE_3_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dxctl_rx_bypass_en : 9;
        unsigned int DX_IO_DQ_VREF_EN : 1;
        unsigned int DX_IO_DQS_VREF_EN : 1;
        unsigned int DX_IO_WCK_VREF_EN : 1;
        unsigned int dxctl_wren_rank_phase_offset : 4;
        unsigned int dxctl_wren_rank_mask_offset : 4;
        unsigned int DX_BIAS_EN : 12;
    } reg;
} SOC_HIPACKPHY_DXCTL_BYPASS_UNION;
#endif
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_rx_bypass_en_START (0)
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_rx_bypass_en_END (8)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_DQ_VREF_EN_START (9)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_DQ_VREF_EN_END (9)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_DQS_VREF_EN_START (10)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_DQS_VREF_EN_END (10)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_WCK_VREF_EN_START (11)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_IO_WCK_VREF_EN_END (11)
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_wren_rank_phase_offset_START (12)
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_wren_rank_phase_offset_END (15)
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_wren_rank_mask_offset_START (16)
#define SOC_HIPACKPHY_DXCTL_BYPASS_dxctl_wren_rank_mask_offset_END (19)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_BIAS_EN_START (20)
#define SOC_HIPACKPHY_DXCTL_BYPASS_DX_BIAS_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_DQS_RG_EQ_C : 5;
        unsigned int reg_WCK_RG_EQ_C : 5;
        unsigned int reserved_0 : 1;
        unsigned int dxctl_rx_ie_extend : 4;
        unsigned int reg_DQS_RG_EQ_RP : 6;
        unsigned int reg_WCK_RG_EQ_RP : 6;
        unsigned int reserved_1 : 1;
        unsigned int ie_extend : 4;
    } reg;
} SOC_HIPACKPHY_DX_IECTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_IECTRL0_reg_DQS_RG_EQ_C_START (0)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_DQS_RG_EQ_C_END (4)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_WCK_RG_EQ_C_START (5)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_WCK_RG_EQ_C_END (9)
#define SOC_HIPACKPHY_DX_IECTRL0_dxctl_rx_ie_extend_START (11)
#define SOC_HIPACKPHY_DX_IECTRL0_dxctl_rx_ie_extend_END (14)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_DQS_RG_EQ_RP_START (15)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_DQS_RG_EQ_RP_END (20)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_WCK_RG_EQ_RP_START (21)
#define SOC_HIPACKPHY_DX_IECTRL0_reg_WCK_RG_EQ_RP_END (26)
#define SOC_HIPACKPHY_DX_IECTRL0_ie_extend_START (28)
#define SOC_HIPACKPHY_DX_IECTRL0_ie_extend_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_SE_CLKD_4_7 : 4;
        unsigned int DX_RX_PRESET_DQ : 2;
        unsigned int reserved_0 : 1;
        unsigned int DX_IE_SEL_11 : 1;
        unsigned int DX_SE_CLKD : 4;
        unsigned int DX_IO_TXMODE_2_3 : 2;
        unsigned int reserved_1 : 1;
        unsigned int DX_RG_TX_EN_11 : 1;
        unsigned int reg_DA_PREAM_TM_WCK : 2;
        unsigned int reserved_2 : 1;
        unsigned int refsel_table_sel : 1;
        unsigned int dummy_oe_aux : 1;
        unsigned int reg_DA_PREAM_TM_DQS : 2;
        unsigned int reg_dx_lpbk_sel_dmy : 1;
        unsigned int dxctl_wck_rank_phase_offset : 4;
        unsigned int dxctl_wck_rank_mask_offset : 4;
    } reg;
} SOC_HIPACKPHY_DX_RX_SET_UNION;
#endif
#define SOC_HIPACKPHY_DX_RX_SET_DX_SE_CLKD_4_7_START (0)
#define SOC_HIPACKPHY_DX_RX_SET_DX_SE_CLKD_4_7_END (3)
#define SOC_HIPACKPHY_DX_RX_SET_DX_RX_PRESET_DQ_START (4)
#define SOC_HIPACKPHY_DX_RX_SET_DX_RX_PRESET_DQ_END (5)
#define SOC_HIPACKPHY_DX_RX_SET_DX_IE_SEL_11_START (7)
#define SOC_HIPACKPHY_DX_RX_SET_DX_IE_SEL_11_END (7)
#define SOC_HIPACKPHY_DX_RX_SET_DX_SE_CLKD_START (8)
#define SOC_HIPACKPHY_DX_RX_SET_DX_SE_CLKD_END (11)
#define SOC_HIPACKPHY_DX_RX_SET_DX_IO_TXMODE_2_3_START (12)
#define SOC_HIPACKPHY_DX_RX_SET_DX_IO_TXMODE_2_3_END (13)
#define SOC_HIPACKPHY_DX_RX_SET_DX_RG_TX_EN_11_START (15)
#define SOC_HIPACKPHY_DX_RX_SET_DX_RG_TX_EN_11_END (15)
#define SOC_HIPACKPHY_DX_RX_SET_reg_DA_PREAM_TM_WCK_START (16)
#define SOC_HIPACKPHY_DX_RX_SET_reg_DA_PREAM_TM_WCK_END (17)
#define SOC_HIPACKPHY_DX_RX_SET_refsel_table_sel_START (19)
#define SOC_HIPACKPHY_DX_RX_SET_refsel_table_sel_END (19)
#define SOC_HIPACKPHY_DX_RX_SET_dummy_oe_aux_START (20)
#define SOC_HIPACKPHY_DX_RX_SET_dummy_oe_aux_END (20)
#define SOC_HIPACKPHY_DX_RX_SET_reg_DA_PREAM_TM_DQS_START (21)
#define SOC_HIPACKPHY_DX_RX_SET_reg_DA_PREAM_TM_DQS_END (22)
#define SOC_HIPACKPHY_DX_RX_SET_reg_dx_lpbk_sel_dmy_START (23)
#define SOC_HIPACKPHY_DX_RX_SET_reg_dx_lpbk_sel_dmy_END (23)
#define SOC_HIPACKPHY_DX_RX_SET_dxctl_wck_rank_phase_offset_START (24)
#define SOC_HIPACKPHY_DX_RX_SET_dxctl_wck_rank_phase_offset_END (27)
#define SOC_HIPACKPHY_DX_RX_SET_dxctl_wck_rank_mask_offset_START (28)
#define SOC_HIPACKPHY_DX_RX_SET_dxctl_wck_rank_mask_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_MODE0 : 2;
        unsigned int DX_IO_MODE1 : 2;
        unsigned int DX_IO_MODE2 : 2;
        unsigned int DX_IO_MODE3 : 2;
        unsigned int DX_IO_MODE4 : 2;
        unsigned int DX_IO_MODE5 : 2;
        unsigned int DX_IO_MODE6 : 2;
        unsigned int DX_IO_MODE7 : 2;
        unsigned int DX_IO_MODE8 : 2;
        unsigned int DX_IO_MODE9 : 2;
        unsigned int DX_IO_RXMODE : 3;
        unsigned int DX_IO_TXMODE : 2;
        unsigned int DX_RT_UPDNCOUNT : 3;
        unsigned int DX_DATA_NU_DE : 3;
        unsigned int lp5dqs_oe_gate : 1;
    } reg;
} SOC_HIPACKPHY_DX_IOMODE_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE0_START (0)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE0_END (1)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE1_START (2)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE1_END (3)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE2_START (4)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE2_END (5)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE3_START (6)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE3_END (7)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE4_START (8)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE4_END (9)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE5_START (10)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE5_END (11)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE6_START (12)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE6_END (13)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE7_START (14)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE7_END (15)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE8_START (16)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE8_END (17)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE9_START (18)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_MODE9_END (19)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_RXMODE_START (20)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_RXMODE_END (22)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_TXMODE_START (23)
#define SOC_HIPACKPHY_DX_IOMODE_DX_IO_TXMODE_END (24)
#define SOC_HIPACKPHY_DX_IOMODE_DX_RT_UPDNCOUNT_START (25)
#define SOC_HIPACKPHY_DX_IOMODE_DX_RT_UPDNCOUNT_END (27)
#define SOC_HIPACKPHY_DX_IOMODE_DX_DATA_NU_DE_START (28)
#define SOC_HIPACKPHY_DX_IOMODE_DX_DATA_NU_DE_END (30)
#define SOC_HIPACKPHY_DX_IOMODE_lp5dqs_oe_gate_START (31)
#define SOC_HIPACKPHY_DX_IOMODE_lp5dqs_oe_gate_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_REFRANGE0 : 4;
        unsigned int DX_IO_REFRANGE1 : 4;
        unsigned int DX_IO_REFRANGE2 : 4;
        unsigned int DX_IO_REFRANGE3 : 4;
        unsigned int DX_IO_REFRANGE4 : 4;
        unsigned int DX_IO_REFRANGE5 : 4;
        unsigned int DX_IO_REFRANGE6 : 4;
        unsigned int DX_IO_REFRANGE7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_IOREFCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE0_START (0)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE0_END (3)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE1_START (4)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE1_END (7)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE2_START (8)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE2_END (11)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE3_START (12)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE3_END (15)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE4_START (16)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE4_END (19)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE5_START (20)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE5_END (23)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE6_START (24)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE6_END (27)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE7_START (28)
#define SOC_HIPACKPHY_DX_IOREFCTRL0_DX_IO_REFRANGE7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_REFRANGE8 : 4;
        unsigned int DX_IO_REFRANGE9 : 4;
        unsigned int DX_IO_REFRANGE10 : 4;
        unsigned int DX_IO_REFRANGE11 : 4;
        unsigned int dx_wck_offset : 3;
        unsigned int dx_wck_oe_extend : 3;
        unsigned int rxwck_bdl_b0_all_rank : 9;
        unsigned int DA_GTC_EN : 1;
    } reg;
} SOC_HIPACKPHY_DX_IOREFCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE8_START (0)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE8_END (3)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE9_START (4)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE9_END (7)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE10_START (8)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE10_END (11)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE11_START (12)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DX_IO_REFRANGE11_END (15)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_dx_wck_offset_START (16)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_dx_wck_offset_END (18)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_dx_wck_oe_extend_START (19)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_dx_wck_oe_extend_END (21)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_rxwck_bdl_b0_all_rank_START (22)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_rxwck_bdl_b0_all_rank_END (30)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DA_GTC_EN_START (31)
#define SOC_HIPACKPHY_DX_IOREFCTRL1_DA_GTC_EN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_REFSEL0 : 2;
        unsigned int DX_IO_REFSEL1 : 2;
        unsigned int DX_IO_REFSEL2 : 2;
        unsigned int DX_IO_REFSEL3 : 2;
        unsigned int DX_IO_REFSEL4 : 2;
        unsigned int DX_IO_REFSEL5 : 2;
        unsigned int DX_IO_REFSEL6 : 2;
        unsigned int DX_IO_REFSEL7 : 2;
        unsigned int DX_IO_REFSEL8 : 2;
        unsigned int DX_IO_REFSEL9 : 2;
        unsigned int DX_IO_REFSEL10 : 2;
        unsigned int DX_IO_REFSEL11 : 2;
        unsigned int AD_GTCOUT : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOREFCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL0_START (0)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL0_END (1)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL1_START (2)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL1_END (3)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL2_START (4)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL2_END (5)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL3_START (6)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL3_END (7)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL4_START (8)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL4_END (9)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL5_START (10)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL5_END (11)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL6_START (12)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL6_END (13)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL7_START (14)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL7_END (15)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL8_START (16)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL8_END (17)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL9_START (18)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL9_END (19)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL10_START (20)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL10_END (21)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL11_START (22)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_DX_IO_REFSEL11_END (23)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_AD_GTCOUT_START (24)
#define SOC_HIPACKPHY_DX_IOREFCTRL2_AD_GTCOUT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_EQ_C0 : 8;
        unsigned int DX_IO_EQ_C1 : 8;
        unsigned int DX_IO_EQ_C2 : 8;
        unsigned int DX_IO_EQ_C3 : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOEQCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C0_START (0)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C0_END (7)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C1_START (8)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C1_END (15)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C2_START (16)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C2_END (23)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C3_START (24)
#define SOC_HIPACKPHY_DX_IOEQCTRL0_DX_IO_EQ_C3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_EQ_C4 : 8;
        unsigned int DX_IO_EQ_C5 : 8;
        unsigned int DX_IO_EQ_C6 : 8;
        unsigned int DX_IO_EQ_C7 : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOEQCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C4_START (0)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C4_END (7)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C5_START (8)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C5_END (15)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C6_START (16)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C6_END (23)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C7_START (24)
#define SOC_HIPACKPHY_DX_IOEQCTRL1_DX_IO_EQ_C7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_EQ_RP0 : 8;
        unsigned int DX_IO_EQ_RP1 : 8;
        unsigned int DX_IO_EQ_RP2 : 8;
        unsigned int DX_IO_EQ_RP3 : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOEQCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP0_START (0)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP0_END (7)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP1_START (8)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP1_END (15)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP2_START (16)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP2_END (23)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP3_START (24)
#define SOC_HIPACKPHY_DX_IOEQCTRL2_DX_IO_EQ_RP3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_EQ_RP4 : 8;
        unsigned int DX_IO_EQ_RP5 : 8;
        unsigned int DX_IO_EQ_RP6 : 8;
        unsigned int DX_IO_EQ_RP7 : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOEQCTRL3_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP4_START (0)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP4_END (7)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP5_START (8)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP5_END (15)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP6_START (16)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP6_END (23)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP7_START (24)
#define SOC_HIPACKPHY_DX_IOEQCTRL3_DX_IO_EQ_RP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_PE_C0 : 3;
        unsigned int DX_IO_PRE_EN0 : 1;
        unsigned int DX_IO_PE_C1 : 3;
        unsigned int DX_IO_PRE_EN1 : 1;
        unsigned int DX_IO_PE_C2 : 3;
        unsigned int DX_IO_PRE_EN2 : 1;
        unsigned int DX_IO_PE_C3 : 3;
        unsigned int DX_IO_PRE_EN3 : 1;
        unsigned int DX_IO_PE_C4 : 3;
        unsigned int DX_IO_PRE_EN4 : 1;
        unsigned int DX_IO_PE_C5 : 3;
        unsigned int DX_IO_PRE_EN5 : 1;
        unsigned int DX_IO_PE_C6 : 3;
        unsigned int DX_IO_PRE_EN6 : 1;
        unsigned int DX_IO_PE_C7 : 3;
        unsigned int DX_IO_PRE_EN7 : 1;
    } reg;
} SOC_HIPACKPHY_DX_PECTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C0_START (0)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C0_END (2)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN0_START (3)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN0_END (3)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C1_START (4)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C1_END (6)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN1_START (7)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN1_END (7)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C2_START (8)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C2_END (10)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN2_START (11)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN2_END (11)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C3_START (12)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C3_END (14)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN3_START (15)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN3_END (15)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C4_START (16)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C4_END (18)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN4_START (19)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN4_END (19)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C5_START (20)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C5_END (22)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN5_START (23)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN5_END (23)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C6_START (24)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C6_END (26)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN6_START (27)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN6_END (27)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C7_START (28)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PE_C7_END (30)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN7_START (31)
#define SOC_HIPACKPHY_DX_PECTRL0_DX_IO_PRE_EN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_PE_C8 : 3;
        unsigned int DX_IO_PRE_EN8 : 1;
        unsigned int DX_IO_PE_C9 : 3;
        unsigned int DX_IO_PRE_EN9 : 1;
        unsigned int DX_IO_PE_C10 : 3;
        unsigned int DX_IO_PRE_EN10 : 1;
        unsigned int DX_IO_PE_C11 : 3;
        unsigned int DX_IO_PRE_EN11 : 1;
        unsigned int DX_IO_RONSEL11 : 3;
        unsigned int DX_IO_RONBSEL_3_5 : 3;
        unsigned int dxctl_rden_dfi_offset : 3;
        unsigned int dxctl_rden_fifo_offset : 3;
        unsigned int dxctl_rden_rank_offset : 4;
    } reg;
} SOC_HIPACKPHY_DX_PECTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C8_START (0)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C8_END (2)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN8_START (3)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN8_END (3)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C9_START (4)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C9_END (6)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN9_START (7)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN9_END (7)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C10_START (8)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C10_END (10)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN10_START (11)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN10_END (11)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C11_START (12)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PE_C11_END (14)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN11_START (15)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_PRE_EN11_END (15)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_RONSEL11_START (16)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_RONSEL11_END (18)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_RONBSEL_3_5_START (19)
#define SOC_HIPACKPHY_DX_PECTRL1_DX_IO_RONBSEL_3_5_END (21)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_dfi_offset_START (22)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_dfi_offset_END (24)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_fifo_offset_START (25)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_fifo_offset_END (27)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_rank_offset_START (28)
#define SOC_HIPACKPHY_DX_PECTRL1_dxctl_rden_rank_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_RONSEL0 : 3;
        unsigned int DX_IO_PULLDN0 : 1;
        unsigned int DX_IO_RONSEL1 : 3;
        unsigned int DX_IO_PULLDN1 : 1;
        unsigned int DX_IO_RONSEL2 : 3;
        unsigned int DX_IO_PULLDN2 : 1;
        unsigned int DX_IO_RONSEL3 : 3;
        unsigned int DX_IO_PULLDN3 : 1;
        unsigned int DX_IO_RONSEL4 : 3;
        unsigned int DX_IO_PULLDN4 : 1;
        unsigned int DX_IO_RONSEL5 : 3;
        unsigned int DX_IO_PULLDN5 : 1;
        unsigned int DX_IO_RONSEL6 : 3;
        unsigned int DX_IO_PULLDN6 : 1;
        unsigned int DX_IO_RONSEL7 : 3;
        unsigned int DX_IO_PULLDN7 : 1;
    } reg;
} SOC_HIPACKPHY_DX_RONCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL0_START (0)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL0_END (2)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN0_START (3)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN0_END (3)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL1_START (4)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL1_END (6)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN1_START (7)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN1_END (7)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL2_START (8)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL2_END (10)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN2_START (11)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN2_END (11)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL3_START (12)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL3_END (14)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN3_START (15)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN3_END (15)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL4_START (16)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL4_END (18)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN4_START (19)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN4_END (19)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL5_START (20)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL5_END (22)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN5_START (23)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN5_END (23)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL6_START (24)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL6_END (26)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN6_START (27)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN6_END (27)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL7_START (28)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_RONSEL7_END (30)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN7_START (31)
#define SOC_HIPACKPHY_DX_RONCTRL0_DX_IO_PULLDN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_RONSEL8 : 3;
        unsigned int DX_IO_PULLDN8 : 1;
        unsigned int DX_IO_RONSEL9 : 3;
        unsigned int DX_IO_PULLDN9 : 1;
        unsigned int DX_IO_RONSEL10 : 3;
        unsigned int DX_IO_PULLDN10 : 1;
        unsigned int DX_IO_RONBSEL : 3;
        unsigned int DX_IO_PULLDN11 : 1;
        unsigned int DX_IO_PUPDMODE_DQS : 2;
        unsigned int DX_IO_REG_ODTEN : 1;
        unsigned int DX_IO_ODTEN : 12;
        unsigned int DX_IO_TODTEN_11 : 1;
    } reg;
} SOC_HIPACKPHY_DX_RONCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL8_START (0)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL8_END (2)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN8_START (3)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN8_END (3)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL9_START (4)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL9_END (6)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN9_START (7)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN9_END (7)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL10_START (8)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONSEL10_END (10)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN10_START (11)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN10_END (11)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONBSEL_START (12)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_RONBSEL_END (14)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN11_START (15)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PULLDN11_END (15)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PUPDMODE_DQS_START (16)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_PUPDMODE_DQS_END (17)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_REG_ODTEN_START (18)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_REG_ODTEN_END (18)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_ODTEN_START (19)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_ODTEN_END (30)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_TODTEN_11_START (31)
#define SOC_HIPACKPHY_DX_RONCTRL1_DX_IO_TODTEN_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_ODTSEL0 : 3;
        unsigned int DX_IO_ODTSEL1 : 3;
        unsigned int DX_IO_ODTSEL2 : 3;
        unsigned int DX_IO_ODTSEL3 : 3;
        unsigned int DX_IO_ODTSEL4 : 3;
        unsigned int DX_IO_ODTSEL5 : 3;
        unsigned int DX_IO_ODTSEL6 : 3;
        unsigned int DX_IO_ODTSEL7 : 3;
        unsigned int DX_IO_ODTSEL11 : 3;
        unsigned int rxwck_bdl_b0_all_rank_msb : 1;
        unsigned int dxctl_wren_rank_offset : 4;
    } reg;
} SOC_HIPACKPHY_DX_ODTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL0_START (0)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL0_END (2)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL1_START (3)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL1_END (5)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL2_START (6)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL2_END (8)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL3_START (9)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL3_END (11)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL4_START (12)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL4_END (14)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL5_START (15)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL5_END (17)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL6_START (18)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL6_END (20)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL7_START (21)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL7_END (23)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL11_START (24)
#define SOC_HIPACKPHY_DX_ODTCTRL1_DX_IO_ODTSEL11_END (26)
#define SOC_HIPACKPHY_DX_ODTCTRL1_rxwck_bdl_b0_all_rank_msb_START (27)
#define SOC_HIPACKPHY_DX_ODTCTRL1_rxwck_bdl_b0_all_rank_msb_END (27)
#define SOC_HIPACKPHY_DX_ODTCTRL1_dxctl_wren_rank_offset_START (28)
#define SOC_HIPACKPHY_DX_ODTCTRL1_dxctl_wren_rank_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_ODTSEL8 : 3;
        unsigned int DX_IO_ODTSEL9 : 3;
        unsigned int DX_IO_ODTSEL10 : 3;
        unsigned int DX_IO_TODTEN : 11;
        unsigned int DX_IO_ODTTEST : 12;
    } reg;
} SOC_HIPACKPHY_DX_ODTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL8_START (0)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL8_END (2)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL9_START (3)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL9_END (5)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL10_START (6)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTSEL10_END (8)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_TODTEN_START (9)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_TODTEN_END (19)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTTEST_START (20)
#define SOC_HIPACKPHY_DX_ODTCTRL2_DX_IO_ODTTEST_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_IOTEST : 12;
        unsigned int dummy_wen_offset : 3;
        unsigned int cfg_tx_gcken : 1;
        unsigned int DX_IO_IETEST : 12;
        unsigned int dummy_extend : 3;
        unsigned int reg_wdqs_iotest : 1;
    } reg;
} SOC_HIPACKPHY_DX_TESTCTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_TESTCTRL0_DX_IO_IOTEST_START (0)
#define SOC_HIPACKPHY_DX_TESTCTRL0_DX_IO_IOTEST_END (11)
#define SOC_HIPACKPHY_DX_TESTCTRL0_dummy_wen_offset_START (12)
#define SOC_HIPACKPHY_DX_TESTCTRL0_dummy_wen_offset_END (14)
#define SOC_HIPACKPHY_DX_TESTCTRL0_cfg_tx_gcken_START (15)
#define SOC_HIPACKPHY_DX_TESTCTRL0_cfg_tx_gcken_END (15)
#define SOC_HIPACKPHY_DX_TESTCTRL0_DX_IO_IETEST_START (16)
#define SOC_HIPACKPHY_DX_TESTCTRL0_DX_IO_IETEST_END (27)
#define SOC_HIPACKPHY_DX_TESTCTRL0_dummy_extend_START (28)
#define SOC_HIPACKPHY_DX_TESTCTRL0_dummy_extend_END (30)
#define SOC_HIPACKPHY_DX_TESTCTRL0_reg_wdqs_iotest_START (31)
#define SOC_HIPACKPHY_DX_TESTCTRL0_reg_wdqs_iotest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_TE : 12;
        unsigned int dummy_t_extend : 3;
        unsigned int RG_ECC_HZ : 1;
        unsigned int DX_IO_TI : 12;
        unsigned int rank_sw_gate_length : 4;
    } reg;
} SOC_HIPACKPHY_DX_TESTCTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_TESTCTRL1_DX_IO_TE_START (0)
#define SOC_HIPACKPHY_DX_TESTCTRL1_DX_IO_TE_END (11)
#define SOC_HIPACKPHY_DX_TESTCTRL1_dummy_t_extend_START (12)
#define SOC_HIPACKPHY_DX_TESTCTRL1_dummy_t_extend_END (14)
#define SOC_HIPACKPHY_DX_TESTCTRL1_RG_ECC_HZ_START (15)
#define SOC_HIPACKPHY_DX_TESTCTRL1_RG_ECC_HZ_END (15)
#define SOC_HIPACKPHY_DX_TESTCTRL1_DX_IO_TI_START (16)
#define SOC_HIPACKPHY_DX_TESTCTRL1_DX_IO_TI_END (27)
#define SOC_HIPACKPHY_DX_TESTCTRL1_rank_sw_gate_length_START (28)
#define SOC_HIPACKPHY_DX_TESTCTRL1_rank_sw_gate_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_TIE : 12;
        unsigned int dummy_wen_extend : 3;
        unsigned int reserved_0 : 1;
        unsigned int DX_IO_TO : 11;
        unsigned int dummy_wen_t_extend : 3;
        unsigned int reserved_1 : 1;
        unsigned int DX_IO_NE : 1;
    } reg;
} SOC_HIPACKPHY_DX_TESTCTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_TIE_START (0)
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_TIE_END (11)
#define SOC_HIPACKPHY_DX_TESTCTRL2_dummy_wen_extend_START (12)
#define SOC_HIPACKPHY_DX_TESTCTRL2_dummy_wen_extend_END (14)
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_TO_START (16)
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_TO_END (26)
#define SOC_HIPACKPHY_DX_TESTCTRL2_dummy_wen_t_extend_START (27)
#define SOC_HIPACKPHY_DX_TESTCTRL2_dummy_wen_t_extend_END (29)
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_NE_START (31)
#define SOC_HIPACKPHY_DX_TESTCTRL2_DX_IO_NE_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_EQ_C8 : 8;
        unsigned int DX_IO_EQ_RP8 : 8;
        unsigned int DX_IO_EQ_C9 : 8;
        unsigned int DX_IO_EQ_RP9 : 8;
    } reg;
} SOC_HIPACKPHY_DX_IOEQCTRL4_UNION;
#endif
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_C8_START (0)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_C8_END (7)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_RP8_START (8)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_RP8_END (15)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_C9_START (16)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_C9_END (23)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_RP9_START (24)
#define SOC_HIPACKPHY_DX_IOEQCTRL4_DX_IO_EQ_RP9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_P_DN0 : 4;
        unsigned int TX_RG_DCC_P_DN1 : 4;
        unsigned int TX_RG_DCC_P_DN2 : 4;
        unsigned int TX_RG_DCC_P_DN3 : 4;
        unsigned int TX_RG_DCC_P_DN4 : 4;
        unsigned int TX_RG_DCC_P_DN5 : 4;
        unsigned int TX_RG_DCC_P_DN6 : 4;
        unsigned int TX_RG_DCC_P_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN0_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN0_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN1_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN1_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN2_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN2_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN3_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN3_END (15)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN4_START (16)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN4_END (19)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN5_START (20)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN5_END (23)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN6_START (24)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN6_END (27)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN7_START (28)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL0_TX_RG_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_P_DN8 : 4;
        unsigned int TX_RG_DCC_P_DN9 : 4;
        unsigned int TX_RG_DCC_P_DN10 : 4;
        unsigned int TX_RG_DCC_P_DN11 : 4;
        unsigned int cfg_rdqsg_offset : 2;
        unsigned int cfg_wdq_offset : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN8_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN8_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN9_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN9_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN10_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN10_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN11_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_TX_RG_DCC_P_DN11_END (15)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_cfg_rdqsg_offset_START (16)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_cfg_rdqsg_offset_END (17)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_cfg_wdq_offset_START (18)
#define SOC_HIPACKPHY_DX_TXDCC_PDN_CTRL1_cfg_wdq_offset_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_N_DN0 : 4;
        unsigned int TX_RG_DCC_N_DN1 : 4;
        unsigned int TX_RG_DCC_N_DN2 : 4;
        unsigned int TX_RG_DCC_N_DN3 : 4;
        unsigned int TX_RG_DCC_N_DN4 : 4;
        unsigned int TX_RG_DCC_N_DN5 : 4;
        unsigned int TX_RG_DCC_N_DN6 : 4;
        unsigned int TX_RG_DCC_N_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN0_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN0_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN1_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN1_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN2_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN2_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN3_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN3_END (15)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN4_START (16)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN4_END (19)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN5_START (20)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN5_END (23)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN6_START (24)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN6_END (27)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN7_START (28)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL2_TX_RG_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_N_DN8 : 4;
        unsigned int TX_RG_DCC_N_DN9 : 4;
        unsigned int TX_RG_DCC_N_DN10 : 4;
        unsigned int TX_RG_DCC_N_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN8_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN8_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN9_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN9_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN10_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN10_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN11_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_NDN_CTRL3_TX_RG_DCC_N_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_P_UP0 : 4;
        unsigned int TX_RG_DCC_P_UP1 : 4;
        unsigned int TX_RG_DCC_P_UP2 : 4;
        unsigned int TX_RG_DCC_P_UP3 : 4;
        unsigned int TX_RG_DCC_P_UP4 : 4;
        unsigned int TX_RG_DCC_P_UP5 : 4;
        unsigned int TX_RG_DCC_P_UP6 : 4;
        unsigned int TX_RG_DCC_P_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP0_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP0_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP1_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP1_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP2_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP2_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP3_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP3_END (15)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP4_START (16)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP4_END (19)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP5_START (20)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP5_END (23)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP6_START (24)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP6_END (27)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP7_START (28)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL0_TX_RG_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_P_UP8 : 4;
        unsigned int TX_RG_DCC_P_UP9 : 4;
        unsigned int TX_RG_DCC_P_UP10 : 4;
        unsigned int TX_RG_DCC_P_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP8_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP8_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP9_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP9_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP10_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP10_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP11_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_PUP_CTRL1_TX_RG_DCC_P_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_N_UP0 : 4;
        unsigned int TX_RG_DCC_N_UP1 : 4;
        unsigned int TX_RG_DCC_N_UP2 : 4;
        unsigned int TX_RG_DCC_N_UP3 : 4;
        unsigned int TX_RG_DCC_N_UP4 : 4;
        unsigned int TX_RG_DCC_N_UP5 : 4;
        unsigned int TX_RG_DCC_N_UP6 : 4;
        unsigned int TX_RG_DCC_N_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP0_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP0_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP1_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP1_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP2_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP2_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP3_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP3_END (15)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP4_START (16)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP4_END (19)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP5_START (20)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP5_END (23)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP6_START (24)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP6_END (27)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP7_START (28)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL2_TX_RG_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TX_RG_DCC_N_UP8 : 4;
        unsigned int TX_RG_DCC_N_UP9 : 4;
        unsigned int TX_RG_DCC_N_UP10 : 4;
        unsigned int TX_RG_DCC_N_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP8_START (0)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP8_END (3)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP9_START (4)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP9_END (7)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP10_START (8)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP10_END (11)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP11_START (12)
#define SOC_HIPACKPHY_DX_TXDCC_NUP_CTRL3_TX_RG_DCC_N_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_P_DN0 : 4;
        unsigned int RX_RG_DCC_P_DN1 : 4;
        unsigned int RX_RG_DCC_P_DN2 : 4;
        unsigned int RX_RG_DCC_P_DN3 : 4;
        unsigned int RX_RG_DCC_P_DN4 : 4;
        unsigned int RX_RG_DCC_P_DN5 : 4;
        unsigned int RX_RG_DCC_P_DN6 : 4;
        unsigned int RX_RG_DCC_P_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN0_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN0_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN1_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN1_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN2_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN2_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN3_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN3_END (15)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN4_START (16)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN4_END (19)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN5_START (20)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN5_END (23)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN6_START (24)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN6_END (27)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN7_START (28)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL0_RX_RG_DCC_P_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_P_DN8 : 4;
        unsigned int RX_RG_DCC_P_DN9 : 4;
        unsigned int RX_RG_DCC_P_DN10 : 4;
        unsigned int RX_RG_DCC_P_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN8_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN8_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN9_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN9_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN10_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN10_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN11_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_PDN_CTRL1_RX_RG_DCC_P_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_N_DN0 : 4;
        unsigned int RX_RG_DCC_N_DN1 : 4;
        unsigned int RX_RG_DCC_N_DN2 : 4;
        unsigned int RX_RG_DCC_N_DN3 : 4;
        unsigned int RX_RG_DCC_N_DN4 : 4;
        unsigned int RX_RG_DCC_N_DN5 : 4;
        unsigned int RX_RG_DCC_N_DN6 : 4;
        unsigned int RX_RG_DCC_N_DN7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN0_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN0_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN1_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN1_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN2_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN2_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN3_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN3_END (15)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN4_START (16)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN4_END (19)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN5_START (20)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN5_END (23)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN6_START (24)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN6_END (27)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN7_START (28)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL2_RX_RG_DCC_N_DN7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_N_DN8 : 4;
        unsigned int RX_RG_DCC_N_DN9 : 4;
        unsigned int RX_RG_DCC_N_DN10 : 4;
        unsigned int RX_RG_DCC_N_DN11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN8_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN8_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN9_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN9_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN10_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN10_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN11_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_NDN_CTRL3_RX_RG_DCC_N_DN11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_P_UP0 : 4;
        unsigned int RX_RG_DCC_P_UP1 : 4;
        unsigned int RX_RG_DCC_P_UP2 : 4;
        unsigned int RX_RG_DCC_P_UP3 : 4;
        unsigned int RX_RG_DCC_P_UP4 : 4;
        unsigned int RX_RG_DCC_P_UP5 : 4;
        unsigned int RX_RG_DCC_P_UP6 : 4;
        unsigned int RX_RG_DCC_P_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP0_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP0_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP1_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP1_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP2_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP2_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP3_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP3_END (15)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP4_START (16)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP4_END (19)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP5_START (20)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP5_END (23)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP6_START (24)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP6_END (27)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP7_START (28)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL0_RX_RG_DCC_P_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_P_UP8 : 4;
        unsigned int RX_RG_DCC_P_UP9 : 4;
        unsigned int RX_RG_DCC_P_UP10 : 4;
        unsigned int RX_RG_DCC_P_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP8_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP8_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP9_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP9_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP10_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP10_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP11_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_PUP_CTRL1_RX_RG_DCC_P_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_N_UP0 : 4;
        unsigned int RX_RG_DCC_N_UP1 : 4;
        unsigned int RX_RG_DCC_N_UP2 : 4;
        unsigned int RX_RG_DCC_N_UP3 : 4;
        unsigned int RX_RG_DCC_N_UP4 : 4;
        unsigned int RX_RG_DCC_N_UP5 : 4;
        unsigned int RX_RG_DCC_N_UP6 : 4;
        unsigned int RX_RG_DCC_N_UP7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP0_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP0_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP1_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP1_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP2_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP2_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP3_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP3_END (15)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP4_START (16)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP4_END (19)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP5_START (20)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP5_END (23)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP6_START (24)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP6_END (27)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP7_START (28)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL2_RX_RG_DCC_N_UP7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RX_RG_DCC_N_UP8 : 4;
        unsigned int RX_RG_DCC_N_UP9 : 4;
        unsigned int RX_RG_DCC_N_UP10 : 4;
        unsigned int RX_RG_DCC_N_UP11 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_UNION;
#endif
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP8_START (0)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP8_END (3)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP9_START (4)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP9_END (7)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP10_START (8)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP10_END (11)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP11_START (12)
#define SOC_HIPACKPHY_DX_RXDCC_NUP_CTRL3_RX_RG_DCC_N_UP11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_RG_TEST0 : 8;
        unsigned int DX_RG_TEST1 : 8;
        unsigned int DX_RG_TEST2 : 8;
        unsigned int DX_RG_TEST3 : 8;
    } reg;
} SOC_HIPACKPHY_DX_RG_TEST_CTL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST0_START (0)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST0_END (7)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST1_START (8)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST1_END (15)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST2_START (16)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST2_END (23)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST3_START (24)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL0_DX_RG_TEST3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_RG_TEST4 : 8;
        unsigned int DX_RG_TEST5 : 8;
        unsigned int DX_RG_TEST6 : 8;
        unsigned int DX_RG_TEST7 : 8;
    } reg;
} SOC_HIPACKPHY_DX_RG_TEST_CTL1_UNION;
#endif
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST4_START (0)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST4_END (7)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST5_START (8)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST5_END (15)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST6_START (16)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST6_END (23)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST7_START (24)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL1_DX_RG_TEST7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_RG_TEST8 : 8;
        unsigned int DX_RG_TEST9 : 8;
        unsigned int DX_RG_TEST10 : 8;
        unsigned int DX_RG_TEST11 : 8;
    } reg;
} SOC_HIPACKPHY_DX_RG_TEST_CTL2_UNION;
#endif
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST8_START (0)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST8_END (7)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST9_START (8)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST9_END (15)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST10_START (16)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST10_END (23)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST11_START (24)
#define SOC_HIPACKPHY_DX_RG_TEST_CTL2_DX_RG_TEST11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int err_dq_margin_0 : 1;
        unsigned int err_dq_margin_1 : 1;
        unsigned int err_dq_margin_2 : 1;
        unsigned int err_dq_margin_3 : 1;
        unsigned int err_dq_margin_4 : 1;
        unsigned int err_dq_margin_5 : 1;
        unsigned int err_dq_margin_6 : 1;
        unsigned int err_dq_margin_7 : 1;
        unsigned int err_dq_margin_8 : 1;
        unsigned int err_dyn_duty : 1;
        unsigned int err_gate_margin : 1;
        unsigned int cfg_upd_dm_track_de_en_f : 1;
        unsigned int cfg_upd_dm_track_de_en : 1;
        unsigned int cfg_upd_dq_track_de_en_f : 1;
        unsigned int cfg_upd_dq_track_de_en : 1;
        unsigned int cfg_upd_track_gate_en : 1;
        unsigned int gate_margin : 8;
        unsigned int dq_margin_8 : 8;
    } reg;
} SOC_HIPACKPHY_DX_TRACK_ERR_UNION;
#endif
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_0_START (0)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_0_END (0)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_1_START (1)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_1_END (1)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_2_START (2)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_2_END (2)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_3_START (3)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_3_END (3)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_4_START (4)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_4_END (4)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_5_START (5)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_5_END (5)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_6_START (6)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_6_END (6)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_7_START (7)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_7_END (7)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_8_START (8)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dq_margin_8_END (8)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dyn_duty_START (9)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_dyn_duty_END (9)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_gate_margin_START (10)
#define SOC_HIPACKPHY_DX_TRACK_ERR_err_gate_margin_END (10)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_f_START (11)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_f_END (11)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_START (12)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dm_track_de_en_END (12)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_f_START (13)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_f_END (13)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_START (14)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_dq_track_de_en_END (14)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_track_gate_en_START (15)
#define SOC_HIPACKPHY_DX_TRACK_ERR_cfg_upd_track_gate_en_END (15)
#define SOC_HIPACKPHY_DX_TRACK_ERR_gate_margin_START (16)
#define SOC_HIPACKPHY_DX_TRACK_ERR_gate_margin_END (23)
#define SOC_HIPACKPHY_DX_TRACK_ERR_dq_margin_8_START (24)
#define SOC_HIPACKPHY_DX_TRACK_ERR_dq_margin_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dq_margin_0 : 8;
        unsigned int dq_margin_1 : 8;
        unsigned int dq_margin_2 : 8;
        unsigned int dq_margin_3 : 8;
    } reg;
} SOC_HIPACKPHY_DX_DQ_MARGIN0_UNION;
#endif
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_0_START (0)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_0_END (7)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_1_START (8)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_1_END (15)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_2_START (16)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_2_END (23)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_3_START (24)
#define SOC_HIPACKPHY_DX_DQ_MARGIN0_dq_margin_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dq_margin_4 : 8;
        unsigned int dq_margin_5 : 8;
        unsigned int dq_margin_6 : 8;
        unsigned int dq_margin_7 : 8;
    } reg;
} SOC_HIPACKPHY_DX_DQ_MARGIN1_UNION;
#endif
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_4_START (0)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_4_END (7)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_5_START (8)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_5_END (15)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_6_START (16)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_6_END (23)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_7_START (24)
#define SOC_HIPACKPHY_DX_DQ_MARGIN1_dq_margin_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 20;
        unsigned int dxctl_wck_rank_offset : 4;
        unsigned int rst_g_len : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_HIPACKPHY_DX_OEBDL_CTL0_UNION;
#endif
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_START (20)
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_dxctl_wck_rank_offset_END (23)
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_rst_g_len_START (24)
#define SOC_HIPACKPHY_DX_OEBDL_CTL0_rst_g_len_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_HIPACKPHY_DX_OEBDL_CTL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DIT_DQS_REG : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HIPACKPHY_DX_DQS_DCC_UNION;
#endif
#define SOC_HIPACKPHY_DX_DQS_DCC_DIT_DQS_REG_START (0)
#define SOC_HIPACKPHY_DX_DQS_DCC_DIT_DQS_REG_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DX_IO_PRE_EN0_1 : 1;
        unsigned int DX_IO_PRE_EN1_1 : 1;
        unsigned int DX_IO_PRE_EN2_1 : 1;
        unsigned int DX_IO_PRE_EN3_1 : 1;
        unsigned int DX_IO_PRE_EN4_1 : 1;
        unsigned int DX_IO_PRE_EN5_1 : 1;
        unsigned int DX_IO_PRE_EN6_1 : 1;
        unsigned int DX_IO_PRE_EN7_1 : 1;
        unsigned int DX_IO_PRE_EN8_1 : 1;
        unsigned int DX_IO_PRE_EN9_1 : 1;
        unsigned int DX_IO_PRE_EN10_1 : 1;
        unsigned int DX_IO_PRE_EN11_1 : 1;
        unsigned int DX_IO_PUPDEN_DQS : 1;
        unsigned int DX_IO_PUPDEN_WCK : 1;
        unsigned int DX_IO_PUPDMODE_WCK : 2;
        unsigned int reg_fast_gt_en : 1;
        unsigned int reg_DX_WCK_DA_SIG_SW : 1;
        unsigned int reg_DX_WCK_RG_PRESET_DQS : 2;
        unsigned int reg_DX_WCK_DA_OE_OPTION : 1;
        unsigned int reserved_0 : 3;
        unsigned int reg_DX_DQS_DA_SIG_SW : 1;
        unsigned int reg_DX_DQS_RG_PRESET_DQS : 2;
        unsigned int reg_DX_DQS_DA_OE_OPTION : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_HIPACKPHY_DX_PRE_EN_BIT1_UNION;
#endif
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN0_1_START (0)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN0_1_END (0)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN1_1_START (1)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN1_1_END (1)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN2_1_START (2)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN2_1_END (2)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN3_1_START (3)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN3_1_END (3)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN4_1_START (4)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN4_1_END (4)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN5_1_START (5)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN5_1_END (5)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN6_1_START (6)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN6_1_END (6)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN7_1_START (7)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN7_1_END (7)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN8_1_START (8)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN8_1_END (8)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN9_1_START (9)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN9_1_END (9)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN10_1_START (10)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN10_1_END (10)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN11_1_START (11)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PRE_EN11_1_END (11)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_DQS_START (12)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_DQS_END (12)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_WCK_START (13)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDEN_WCK_END (13)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDMODE_WCK_START (14)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_DX_IO_PUPDMODE_WCK_END (15)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_fast_gt_en_START (16)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_fast_gt_en_END (16)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_SIG_SW_START (17)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_SIG_SW_END (17)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_RG_PRESET_DQS_START (18)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_RG_PRESET_DQS_END (19)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_OE_OPTION_START (20)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_WCK_DA_OE_OPTION_END (20)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_SIG_SW_START (24)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_SIG_SW_END (24)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_RG_PRESET_DQS_START (25)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_RG_PRESET_DQS_END (26)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_OE_OPTION_START (27)
#define SOC_HIPACKPHY_DX_PRE_EN_BIT1_reg_DX_DQS_DA_OE_OPTION_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rden_stable_thrshld : 8;
        unsigned int rden_stable_max : 8;
        unsigned int gate_err_en : 1;
        unsigned int gate_err_int : 1;
        unsigned int gate_to_int : 1;
        unsigned int gate_uf_int : 1;
        unsigned int rden_lat_gate_num : 3;
        unsigned int reserved_0 : 1;
        unsigned int rden_gate_offset : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_HIPACKPHY_DX_GATE_ERR_UNION;
#endif
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_stable_thrshld_START (0)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_stable_thrshld_END (7)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_stable_max_START (8)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_stable_max_END (15)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_err_en_START (16)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_err_en_END (16)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_err_int_START (17)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_err_int_END (17)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_to_int_START (18)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_to_int_END (18)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_uf_int_START (19)
#define SOC_HIPACKPHY_DX_GATE_ERR_gate_uf_int_END (19)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_lat_gate_num_START (20)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_lat_gate_num_END (22)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_gate_offset_START (24)
#define SOC_HIPACKPHY_DX_GATE_ERR_rden_gate_offset_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_dx_txdqm_gcken : 1;
        unsigned int reg_dx_txdqs_gcken : 1;
        unsigned int reg_dx_txwck_gcken : 1;
        unsigned int reg_dx_txdmy_gcken : 1;
        unsigned int reg_dx_txdqm_phcfg : 2;
        unsigned int reg_dx_txdqs_phcfg : 2;
        unsigned int reg_dx_txwck_phcfg : 2;
        unsigned int reg_dx_txdmy_phcfg : 2;
        unsigned int reg_dx_phcfg_auto : 1;
        unsigned int reg_dx_rx_gcken : 1;
        unsigned int reserved : 6;
        unsigned int reg_dx_tx_dqm_mask : 9;
        unsigned int reg_dx_tx_dmy_mask : 1;
        unsigned int reg_dx_tx_dqs_mask : 1;
        unsigned int reg_dx_tx_wck_mask : 1;
    } reg;
} SOC_HIPACKPHY_DX_GCKEN_CTRL_UNION;
#endif
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqm_gcken_START (0)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqm_gcken_END (0)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqs_gcken_START (1)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqs_gcken_END (1)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txwck_gcken_START (2)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txwck_gcken_END (2)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdmy_gcken_START (3)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdmy_gcken_END (3)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqm_phcfg_START (4)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqm_phcfg_END (5)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqs_phcfg_START (6)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdqs_phcfg_END (7)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txwck_phcfg_START (8)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txwck_phcfg_END (9)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdmy_phcfg_START (10)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_txdmy_phcfg_END (11)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_phcfg_auto_START (12)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_phcfg_auto_END (12)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_rx_gcken_START (13)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_rx_gcken_END (13)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dqm_mask_START (20)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dqm_mask_END (28)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dmy_mask_START (29)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dmy_mask_END (29)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dqs_mask_START (30)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_dqs_mask_END (30)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_wck_mask_START (31)
#define SOC_HIPACKPHY_DX_GCKEN_CTRL_reg_dx_tx_wck_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_RG_OFFSET_K_EN_DQ : 1;
        unsigned int reg_RG_OFFSET_K_EN_DMY : 1;
        unsigned int reg_RG_XRANK_DMY : 3;
        unsigned int reg_RG_XRANK_DM : 3;
        unsigned int reg_DA_OFFSET_DMY_rank0 : 5;
        unsigned int reg_DA_OFFSET_DMY_rank1 : 5;
        unsigned int reg_DA_OFFSET_DM_rank0 : 5;
        unsigned int reg_DA_OFFSET_DM_rank1 : 5;
        unsigned int reg_RG_XRANK_K_EN_DQ : 1;
        unsigned int reg_RG_XRANK_K_EN_DMY : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_DX_XRANK_CTRL_0_UNION;
#endif
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DQ_START (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DQ_END (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DMY_START (1)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_OFFSET_K_EN_DMY_END (1)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DMY_START (2)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DMY_END (4)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DM_START (5)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_DM_END (7)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank0_START (8)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank0_END (12)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank1_START (13)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DMY_rank1_END (17)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank0_START (18)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank0_END (22)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank1_START (23)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_DA_OFFSET_DM_rank1_END (27)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DQ_START (28)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DQ_END (28)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DMY_START (29)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_0_reg_RG_XRANK_K_EN_DMY_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_RG_XRANK_DQ0 : 3;
        unsigned int reg_RG_XRANK_DQ1 : 3;
        unsigned int reg_RG_XRANK_DQ2 : 3;
        unsigned int reg_RG_XRANK_DQ3 : 3;
        unsigned int reg_RG_XRANK_DQ4 : 3;
        unsigned int reg_RG_XRANK_DQ5 : 3;
        unsigned int reg_RG_XRANK_DQ6 : 3;
        unsigned int reg_RG_XRANK_DQ7 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_HIPACKPHY_DX_XRANK_CTRL_1_UNION;
#endif
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ0_START (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ0_END (2)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ1_START (3)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ1_END (5)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ2_START (6)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ2_END (8)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ3_START (9)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ3_END (11)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ4_START (12)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ4_END (14)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ5_START (15)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ5_END (17)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ6_START (18)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ6_END (20)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ7_START (21)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_1_reg_RG_XRANK_DQ7_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_DA_OFFSET_DQ0_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ0_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ1_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ1_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ2_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ2_rank1 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_DX_XRANK_CTRL_2_UNION;
#endif
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank0_START (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank0_END (4)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank1_START (5)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ0_rank1_END (9)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank0_START (10)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank0_END (14)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank1_START (15)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ1_rank1_END (19)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank0_START (20)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank0_END (24)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank1_START (25)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_2_reg_DA_OFFSET_DQ2_rank1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_DA_OFFSET_DQ3_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ3_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ4_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ4_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ5_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ5_rank1 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_HIPACKPHY_DX_XRANK_CTRL_3_UNION;
#endif
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank0_START (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank0_END (4)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank1_START (5)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ3_rank1_END (9)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank0_START (10)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank0_END (14)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank1_START (15)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ4_rank1_END (19)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank0_START (20)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank0_END (24)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank1_START (25)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_3_reg_DA_OFFSET_DQ5_rank1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_DA_OFFSET_DQ6_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ6_rank1 : 5;
        unsigned int reg_DA_OFFSET_DQ7_rank0 : 5;
        unsigned int reg_DA_OFFSET_DQ7_rank1 : 5;
        unsigned int reserved : 12;
    } reg;
} SOC_HIPACKPHY_DX_XRANK_CTRL_4_UNION;
#endif
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank0_START (0)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank0_END (4)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank1_START (5)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ6_rank1_END (9)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank0_START (10)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank0_END (14)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank1_START (15)
#define SOC_HIPACKPHY_DX_XRANK_CTRL_4_reg_DA_OFFSET_DQ7_rank1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dq_margin_ext_0 : 4;
        unsigned int dq_margin_ext_1 : 4;
        unsigned int dq_margin_ext_2 : 4;
        unsigned int dq_margin_ext_3 : 4;
        unsigned int dq_margin_ext_4 : 4;
        unsigned int dq_margin_ext_5 : 4;
        unsigned int dq_margin_ext_6 : 4;
        unsigned int dq_margin_ext_7 : 4;
    } reg;
} SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_UNION;
#endif
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_0_START (0)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_0_END (3)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_1_START (4)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_1_END (7)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_2_START (8)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_2_END (11)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_3_START (12)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_3_END (15)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_4_START (16)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_4_END (19)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_5_START (20)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_5_END (23)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_6_START (24)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_6_END (27)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_7_START (28)
#define SOC_HIPACKPHY_DX_DQ_MARGIN_EXT_dq_margin_ext_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dq_margin_ext_8 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HIPACKPHY_DX_DM_MARGIN_EXT_UNION;
#endif
#define SOC_HIPACKPHY_DX_DM_MARGIN_EXT_dq_margin_ext_8_START (0)
#define SOC_HIPACKPHY_DX_DM_MARGIN_EXT_dq_margin_ext_8_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
