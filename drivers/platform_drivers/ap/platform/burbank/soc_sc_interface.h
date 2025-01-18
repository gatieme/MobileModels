#ifndef __SOC_SC_INTERFACE_H__
#define __SOC_SC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SC_GLB_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_SC_GLB_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_SC_GLB_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_SC_GLB_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_SC_GLB_WAY_EN_ADDR(base) ((base) + (0x0080UL))
#define SOC_SC_GLB_QOS_CTRL_URGT_ADDR(base) ((base) + (0x0100UL))
#define SOC_SC_GLB_QOS_CTRL_EV_ADDR(base) ((base) + (0x0104UL))
#define SOC_SC_GLB_QOS_CTRL_SCH_ADDR(base) ((base) + (0x0108UL))
#define SOC_SC_GLB_SCQ_CTRL0_ADDR(base) ((base) + (0x0140UL))
#define SOC_SC_GLB_SCQ_CTRL1_ADDR(base) ((base) + (0x0144UL))
#define SOC_SC_GLB_CFC0_ADDR(base) ((base) + (0x0180UL))
#define SOC_SC_GLB_CFC1_ADDR(base) ((base) + (0x0184UL))
#define SOC_SC_GLB_CKG_BYP_ADDR(base) ((base) + (0x0800UL))
#define SOC_SC_GLB_CKG_EXT_ADDR(base) ((base) + (0x0804UL))
#define SOC_SC_GLB_FUNC_BYP_ADDR(base) ((base) + (0x0808UL))
#define SOC_SC_GLB_PARAM_OVRD_ADDR(base) ((base) + (0x080CUL))
#define SOC_SC_GLB_PMU_CTRL_ADDR(base) ((base) + (0x0820UL))
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_ADDR(base) ((base) + (0x0824UL))
#define SOC_SC_CFG_GID_SEC_ATTR_S_ADDR(base,gid_idx) ((base) + (0x1000+(gid_idx)*0x4UL))
#define SOC_SC_GLB_ALLC_PLC_S_ADDR(base) ((base) + (0x1100UL))
#define SOC_SC_GLB_SCB_EN_S_ADDR(base) ((base) + (0x1104UL))
#define SOC_SC_GLB_MEM_LP_SLP_S_ADDR(base) ((base) + (0x1200UL))
#define SOC_SC_GLB_MEM_LP_STA0_S_ADDR(base) ((base) + (0x1210UL))
#define SOC_SC_GLB_MEM_LP_STA1_S_ADDR(base) ((base) + (0x1214UL))
#define SOC_SC_GLB_MEM_LP_STA2_S_ADDR(base) ((base) + (0x1218UL))
#define SOC_SC_GLB_MEM_LP_PARAM_S_ADDR(base) ((base) + (0x121CUL))
#define SOC_SC_GLB_FUNC_BYP_S_ADDR(base) ((base) + (0x1280UL))
#define SOC_SC_GLB_DUMMY_RW0_S_ADDR(base) ((base) + (0x1284UL))
#define SOC_SC_GLB_DUMMY_RW1_S_ADDR(base) ((base) + (0x1288UL))
#define SOC_SC_GLB_DUMMY_RO0_S_ADDR(base) ((base) + (0x128CUL))
#define SOC_SC_GLB_DUMMY_RO1_S_ADDR(base) ((base) + (0x1290UL))
#define SOC_SC_CFG_INT_STATUS_ADDR(base) ((base) + (0x2000UL))
#define SOC_SC_CMO_CFG_INT_INI_ADDR(base) ((base) + (0x2004UL))
#define SOC_SC_CMO_CFG_INT_EN_ADDR(base) ((base) + (0x2008UL))
#define SOC_SC_CMO_CFG_INT_CLR_ADDR(base) ((base) + (0x200CUL))
#define SOC_SC_CFG_CMO_QUEUE_CNT_ADDR(base) ((base) + (0x2018UL))
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_ADDR(base) ((base) + (0x2020UL))
#define SOC_SC_CFG_READY_WAIT_TIME_ADDR(base) ((base) + (0x2030UL))
#define SOC_SC_CFG_CMO_ERR_CMD_L_ADDR(base) ((base) + (0x2058UL))
#define SOC_SC_CFG_CMO_ERR_CMD_H_ADDR(base) ((base) + (0x205CUL))
#define SOC_SC_CFG_DFX_DISTR_ADDR(base) ((base) + (0x2078UL))
#define SOC_SC_CFG_CMO_STATUS_ADDR(base,cmo_st) ((base) + (0x2100+(cmo_st)*0x4UL))
#define SOC_SC_CFG_CMO_CLEAR_ADDR(base,cmo_st) ((base) + (0x2200+(cmo_st)*0x4UL))
#define SOC_SC_CFG_NON_SECURITY_CFG_S_ADDR(base) ((base) + (0x3000UL))
#define SOC_SC_CFG_ALLOW_MID_S_ADDR(base) ((base) + (0x3010UL))
#define SOC_SC_CFG_CMO_SET_S_ADDR(base) ((base) + (0x3100UL))
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_ADDR(base) ((base) + (0x3014UL))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_ADDR(base) ((base) + (0x3018UL))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_ADDR(base) ((base) + (0x301CUL))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_ADDR(base) ((base) + (0x3020UL))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_ADDR(base) ((base) + (0x3024UL))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_ADDR(base) ((base) + (0x3028UL))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_ADDR(base) ((base) + (0x302CUL))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_ADDR(base) ((base) + (0x3030UL))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_ADDR(base) ((base) + (0x3034UL))
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_ADDR(base) ((base) + (0x3038UL))
#define SOC_SC_CFG_JTAG_SUPER_ACCESS_ADDR(base) ((base) + (0x3FFCUL))
#define SOC_SC_GID_QUOTA_ADDR(base,gid_idx) ((base) + (0x4000+(gid_idx)*0x100UL))
#define SOC_SC_GID_WAY_ALLC_ADDR(base,gid_idx) ((base) + (0x4004+(gid_idx)*0x100UL))
#define SOC_SC_GID_ALLC_PLC_ADDR(base,gid_idx) ((base) + (0x4008+(gid_idx)*0x100UL))
#define SOC_SC_GID_MID_FLT0_ADDR(base,gid_idx) ((base) + (0x400C+(gid_idx)*0x100UL))
#define SOC_SC_GID_MID_FLT1_ADDR(base,gid_idx) ((base) + (0x4010+(gid_idx)*0x100UL))
#define SOC_SC_CMO_CMD_L_ADDR(base) ((base) + (0x5000UL))
#define SOC_SC_CMO_CMD_H_ADDR(base) ((base) + (0x5004UL))
#define SOC_SC_SLC_PERF_MUX_MODE_ADDR(base,slc_idx) ((base) + (0x6000+(slc_idx)*0x400UL))
#define SOC_SC_SLC_CM_CNT_EN_ADDR(base,slc_idxa) ((base) + (0x6004+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_CM_CNT_MUX0_ADDR(base,slc_idxa) ((base) + (0x6008+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_CM_CNT_MUX1_ADDR(base,slc_idxa) ((base) + (0x600C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_CM_CNT_MUX2_ADDR(base,slc_idxa) ((base) + (0x6010+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT0_TH_L_ADDR(base,slc_idxa) ((base) + (0x6014+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT0_TH_H_ADDR(base,slc_idxa) ((base) + (0x6018+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT1_TH_L_ADDR(base,slc_idxa) ((base) + (0x601C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT1_TH_H_ADDR(base,slc_idxa) ((base) + (0x6020+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT2_TH_L_ADDR(base,slc_idxa) ((base) + (0x6024+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT2_TH_H_ADDR(base,slc_idxa) ((base) + (0x6028+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT3_TH_L_ADDR(base,slc_idxa) ((base) + (0x602C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT3_TH_H_ADDR(base,slc_idxa) ((base) + (0x6030+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT4_TH_L_ADDR(base,slc_idxa) ((base) + (0x6034+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT4_TH_H_ADDR(base,slc_idxa) ((base) + (0x6038+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT5_TH_L_ADDR(base,slc_idxa) ((base) + (0x603C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT5_TH_H_ADDR(base,slc_idxa) ((base) + (0x6040+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT6_TH_L_ADDR(base,slc_idxa) ((base) + (0x6044+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT6_TH_H_ADDR(base,slc_idxa) ((base) + (0x6048+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT7_TH_L_ADDR(base,slc_idxa) ((base) + (0x604C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT7_TH_H_ADDR(base,slc_idxa) ((base) + (0x6050+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT8_TH_L_ADDR(base,slc_idxa) ((base) + (0x6054+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT8_TH_H_ADDR(base,slc_idxa) ((base) + (0x6058+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT9_TH_L_ADDR(base,slc_idxa) ((base) + (0x605C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT9_TH_H_ADDR(base,slc_idxa) ((base) + (0x6060+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT10_TH_L_ADDR(base,slc_idxa) ((base) + (0x6064+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT10_TH_H_ADDR(base,slc_idxa) ((base) + (0x6068+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT11_TH_L_ADDR(base,slc_idxa) ((base) + (0x606C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT11_TH_H_ADDR(base,slc_idxa) ((base) + (0x6070+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP2_CFG_ADDR(base,slc_idx) ((base) + (0x6094+(slc_idx)*0x400UL))
#define SOC_SC_SLC_BP5_CFG_ADDR(base,slc_idxa) ((base) + (0x6098+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP6_CFG_ADDR(base,slc_idxa) ((base) + (0x609C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP7_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60A0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP7_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60A4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP7_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60A8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP8_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60AC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP8_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60B0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP8_CFG_3_ADDR(base,slc_idxa) ((base) + (0x60B4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP8_CFG_4_ADDR(base,slc_idxa) ((base) + (0x60B8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60BC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP10_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60C8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP10_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60CC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP10_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60D0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP11_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60D4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP12_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60DC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP12_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60E0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP12_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60E4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP14A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60E8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP14A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60EC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP14B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60F0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP14B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60F4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_BP15_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60F8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP0_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60FC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP0_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6100+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP0_CFG_2_ADDR(base,slc_idxa) ((base) + (0x6104+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP1_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6108+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP1_CFG_1_ADDR(base,slc_idxa) ((base) + (0x610C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP1_CFG_2_ADDR(base,slc_idxa) ((base) + (0x6110+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP2A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6114+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP2A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6118+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP2B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x611C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP2B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6120+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP3A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6124+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP3A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6128+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP3B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x612C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP3B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6130+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP4_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6134+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP5_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6138+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP5_CFG_1_ADDR(base,slc_idxa) ((base) + (0x613C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP6A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6140+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP6A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6144+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP6B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6148+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP6B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x614C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP7A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6150+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP7A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6154+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP7B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6158+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP7B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x615C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP8A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6160+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP8A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6164+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP8B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6168+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP8B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x616C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6170+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP9_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6174+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_TCP10_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6178+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_DCP03_CFG_0_ADDR(base,slc_idxa) ((base) + (0x617C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_DCP6_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6180+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_DCP7_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6184+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_DCP8_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6188+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_DCP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x618C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMP_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6190+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT0_L_ADDR(base,slc_idxa) ((base) + (0x6194+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT0_H_ADDR(base,slc_idxa) ((base) + (0x6198+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT1_L_ADDR(base,slc_idxa) ((base) + (0x619C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT1_H_ADDR(base,slc_idxa) ((base) + (0x61A0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT2_L_ADDR(base,slc_idxa) ((base) + (0x61A4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT2_H_ADDR(base,slc_idxa) ((base) + (0x61A8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT3_L_ADDR(base,slc_idxa) ((base) + (0x61AC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT3_H_ADDR(base,slc_idxa) ((base) + (0x61B0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT4_L_ADDR(base,slc_idxa) ((base) + (0x61B4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT4_H_ADDR(base,slc_idxa) ((base) + (0x61B8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT5_L_ADDR(base,slc_idxa) ((base) + (0x61BC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT5_H_ADDR(base,slc_idxa) ((base) + (0x61C0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT6_L_ADDR(base,slc_idxa) ((base) + (0x61C4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT6_H_ADDR(base,slc_idxa) ((base) + (0x61C8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT7_L_ADDR(base,slc_idxa) ((base) + (0x61CC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT7_H_ADDR(base,slc_idxa) ((base) + (0x61D0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT8_L_ADDR(base,slc_idxa) ((base) + (0x61D4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT8_H_ADDR(base,slc_idxa) ((base) + (0x61D8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT9_L_ADDR(base,slc_idxa) ((base) + (0x61DC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT9_H_ADDR(base,slc_idxa) ((base) + (0x61E0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT10_L_ADDR(base,slc_idxa) ((base) + (0x61E4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT10_H_ADDR(base,slc_idxa) ((base) + (0x61E8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT11_L_ADDR(base,slc_idxa) ((base) + (0x61EC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT11_H_ADDR(base,slc_idxa) ((base) + (0x61F0+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT12_L_ADDR(base,slc_idxa) ((base) + (0x61F4+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT12_H_ADDR(base,slc_idxa) ((base) + (0x61F8+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT13_L_ADDR(base,slc_idxa) ((base) + (0x61FC+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT13_H_ADDR(base,slc_idxa) ((base) + (0x6200+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT14_L_ADDR(base,slc_idxa) ((base) + (0x6204+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT14_H_ADDR(base,slc_idxa) ((base) + (0x6208+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT15_L_ADDR(base,slc_idxa) ((base) + (0x620C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_CNT15_H_ADDR(base,slc_idxa) ((base) + (0x6210+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_STAT_CYCLE_L_ADDR(base,slc_idxa) ((base) + (0x6214+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_STAT_CYCLE_H_ADDR(base,slc_idxa) ((base) + (0x6218+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_STAT_BUSY_L_ADDR(base,slc_idxa) ((base) + (0x621C+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_PMU_STAT_BUSY_H_ADDR(base,slc_idxa) ((base) + (0x6220+(slc_idxa)*0x400UL))
#define SOC_SC_SLC_WAY_PWRUP_STAT_ADDR(base,slc_idx) ((base) + (0x8000+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_GID_COUNT_ADDR(base,gid_idx,slc_idx) ((base) + (0x8010+(slc_idx)*0x2000+(gid_idx)*0x4UL))
#define SOC_SC_SLC02_INT_ST_ADDR(base,slc_idxa) ((base) + (0x8080+(slc_idxa)*0x2000UL))
#define SOC_SC_SLC02_INT_INI_ADDR(base,slc_idxa) ((base) + (0x8084+(slc_idxa)*0x2000UL))
#define SOC_SC_SLC02_INT_CLEAR_ADDR(base,slc_idxa) ((base) + (0x8088+(slc_idxa)*0x2000UL))
#define SOC_SC_SLC02_INT_EN_ADDR(base,slc_idxa) ((base) + (0x8090+(slc_idxa)*0x2000UL))
#define SOC_SC_SLC13_INT_ST_ADDR(base,slc_idxb) ((base) + (0x8080+(slc_idxb)*0x2000UL))
#define SOC_SC_SLC13_INT_INI_ADDR(base,slc_idxb) ((base) + (0x8084+(slc_idxb)*0x2000UL))
#define SOC_SC_SLC13_INT_CLEAR_ADDR(base,slc_idxb) ((base) + (0x8088+(slc_idxb)*0x2000UL))
#define SOC_SC_SLC13_INT_EN_ADDR(base,slc_idxb) ((base) + (0x8090+(slc_idxb)*0x2000UL))
#define SOC_SC_SLC_DFX_MODULE_ADDR(base,slc_idx) ((base) + (0x8400+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCQ_ADDR(base,slc_idx) ((base) + (0x8404+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SQUE0_ADDR(base,slc_idx) ((base) + (0x8410+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_REQ0_ADDR(base,slc_idx) ((base) + (0x8418+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_BUF_ADDR(base,slc_idx) ((base) + (0x8420+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_OT_ADDR(base,slc_idx) ((base) + (0x8424+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_FIFO0_ADDR(base,slc_idx) ((base) + (0x8430+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_FIFO1_ADDR(base,slc_idx) ((base) + (0x8434+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_BP_ADDR(base,slc_idx) ((base) + (0x8440+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_ERR_INF1_ADDR(base,slc_idx) ((base) + (0x8454+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_ERR_INF2_ADDR(base,slc_idx) ((base) + (0x8458+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_ECCERR_ADDR(base,slc_idx) ((base) + (0x8460+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_MEM0_ADDR(base,slc_idx) ((base) + (0x8470+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_MEM1_ADDR(base,slc_idx) ((base) + (0x8474+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_CTRL_ADDR(base,slc_idx) ((base) + (0x8480+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_INFO0_ADDR(base,slc_idx) ((base) + (0x8484+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_INFO1_ADDR(base,slc_idx) ((base) + (0x8488+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_INFO2_ADDR(base,slc_idx) ((base) + (0x848C+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_INFO3_ADDR(base,slc_idx) ((base) + (0x8490+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_SCH_INFO4_ADDR(base,slc_idx) ((base) + (0x8494+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_CMOGEN_ADDR(base,slc_idx) ((base) + (0x84E0+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_DUMMY0_ADDR(base,slc_idx) ((base) + (0x8500+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DFX_DUMMY1_ADDR(base,slc_idx) ((base) + (0x8504+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_WAY_PWRUP_S_ADDR(base,slc_idx) ((base) + (0x9000+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_SPMEM_CTRL_S_ADDR(base,slc_idx) ((base) + (0x9020+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_TPMEM_CTRL_S_ADDR(base,slc_idx) ((base) + (0x9024+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_TAG_MEM_RD_EN_S_ADDR(base,slc_idx) ((base) + (0x9100+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_RD_EN_S_ADDR(base,slc_idx) ((base) + (0x9104+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_ADDR(base,slc_idx) ((base) + (0x9108+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_ADDR(base,slc_idx) ((base) + (0x910C+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_TAG_MEM_DATA_VLD_S_ADDR(base,slc_idx) ((base) + (0x9110+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA_VLD_S_ADDR(base,slc_idx) ((base) + (0x9114+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_TAG_MEM_DATA_S_ADDR(base,slc_idx) ((base) + (0x911C+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA1_S_ADDR(base,slc_idx) ((base) + (0x9120+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA2_S_ADDR(base,slc_idx) ((base) + (0x9124+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA3_S_ADDR(base,slc_idx) ((base) + (0x9128+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA4_S_ADDR(base,slc_idx) ((base) + (0x912C+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA5_S_ADDR(base,slc_idx) ((base) + (0x9130+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA6_S_ADDR(base,slc_idx) ((base) + (0x9134+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA7_S_ADDR(base,slc_idx) ((base) + (0x9138+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA8_S_ADDR(base,slc_idx) ((base) + (0x913C+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DATA_MEM_DATA9_S_ADDR(base,slc_idx) ((base) + (0x9140+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DUMMY_RW0_S_ADDR(base,slc_idx) ((base) + (0x9180+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DUMMY_RW1_S_ADDR(base,slc_idx) ((base) + (0x9184+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DUMMY_RO0_S_ADDR(base,slc_idx) ((base) + (0x9188+(slc_idx)*0x2000UL))
#define SOC_SC_SLC_DUMMY_RO1_S_ADDR(base,slc_idx) ((base) + (0x918C+(slc_idx)*0x2000UL))
#else
#define SOC_SC_GLB_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_SC_GLB_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_SC_GLB_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_SC_GLB_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_SC_GLB_WAY_EN_ADDR(base) ((base) + (0x0080))
#define SOC_SC_GLB_QOS_CTRL_URGT_ADDR(base) ((base) + (0x0100))
#define SOC_SC_GLB_QOS_CTRL_EV_ADDR(base) ((base) + (0x0104))
#define SOC_SC_GLB_QOS_CTRL_SCH_ADDR(base) ((base) + (0x0108))
#define SOC_SC_GLB_SCQ_CTRL0_ADDR(base) ((base) + (0x0140))
#define SOC_SC_GLB_SCQ_CTRL1_ADDR(base) ((base) + (0x0144))
#define SOC_SC_GLB_CFC0_ADDR(base) ((base) + (0x0180))
#define SOC_SC_GLB_CFC1_ADDR(base) ((base) + (0x0184))
#define SOC_SC_GLB_CKG_BYP_ADDR(base) ((base) + (0x0800))
#define SOC_SC_GLB_CKG_EXT_ADDR(base) ((base) + (0x0804))
#define SOC_SC_GLB_FUNC_BYP_ADDR(base) ((base) + (0x0808))
#define SOC_SC_GLB_PARAM_OVRD_ADDR(base) ((base) + (0x080C))
#define SOC_SC_GLB_PMU_CTRL_ADDR(base) ((base) + (0x0820))
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_ADDR(base) ((base) + (0x0824))
#define SOC_SC_CFG_GID_SEC_ATTR_S_ADDR(base,gid_idx) ((base) + (0x1000+(gid_idx)*0x4))
#define SOC_SC_GLB_ALLC_PLC_S_ADDR(base) ((base) + (0x1100))
#define SOC_SC_GLB_SCB_EN_S_ADDR(base) ((base) + (0x1104))
#define SOC_SC_GLB_MEM_LP_SLP_S_ADDR(base) ((base) + (0x1200))
#define SOC_SC_GLB_MEM_LP_STA0_S_ADDR(base) ((base) + (0x1210))
#define SOC_SC_GLB_MEM_LP_STA1_S_ADDR(base) ((base) + (0x1214))
#define SOC_SC_GLB_MEM_LP_STA2_S_ADDR(base) ((base) + (0x1218))
#define SOC_SC_GLB_MEM_LP_PARAM_S_ADDR(base) ((base) + (0x121C))
#define SOC_SC_GLB_FUNC_BYP_S_ADDR(base) ((base) + (0x1280))
#define SOC_SC_GLB_DUMMY_RW0_S_ADDR(base) ((base) + (0x1284))
#define SOC_SC_GLB_DUMMY_RW1_S_ADDR(base) ((base) + (0x1288))
#define SOC_SC_GLB_DUMMY_RO0_S_ADDR(base) ((base) + (0x128C))
#define SOC_SC_GLB_DUMMY_RO1_S_ADDR(base) ((base) + (0x1290))
#define SOC_SC_CFG_INT_STATUS_ADDR(base) ((base) + (0x2000))
#define SOC_SC_CMO_CFG_INT_INI_ADDR(base) ((base) + (0x2004))
#define SOC_SC_CMO_CFG_INT_EN_ADDR(base) ((base) + (0x2008))
#define SOC_SC_CMO_CFG_INT_CLR_ADDR(base) ((base) + (0x200C))
#define SOC_SC_CFG_CMO_QUEUE_CNT_ADDR(base) ((base) + (0x2018))
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_ADDR(base) ((base) + (0x2020))
#define SOC_SC_CFG_READY_WAIT_TIME_ADDR(base) ((base) + (0x2030))
#define SOC_SC_CFG_CMO_ERR_CMD_L_ADDR(base) ((base) + (0x2058))
#define SOC_SC_CFG_CMO_ERR_CMD_H_ADDR(base) ((base) + (0x205C))
#define SOC_SC_CFG_DFX_DISTR_ADDR(base) ((base) + (0x2078))
#define SOC_SC_CFG_CMO_STATUS_ADDR(base,cmo_st) ((base) + (0x2100+(cmo_st)*0x4))
#define SOC_SC_CFG_CMO_CLEAR_ADDR(base,cmo_st) ((base) + (0x2200+(cmo_st)*0x4))
#define SOC_SC_CFG_NON_SECURITY_CFG_S_ADDR(base) ((base) + (0x3000))
#define SOC_SC_CFG_ALLOW_MID_S_ADDR(base) ((base) + (0x3010))
#define SOC_SC_CFG_CMO_SET_S_ADDR(base) ((base) + (0x3100))
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_ADDR(base) ((base) + (0x3014))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_ADDR(base) ((base) + (0x3018))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_ADDR(base) ((base) + (0x301C))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_ADDR(base) ((base) + (0x3020))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_ADDR(base) ((base) + (0x3024))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_ADDR(base) ((base) + (0x3028))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_ADDR(base) ((base) + (0x302C))
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_ADDR(base) ((base) + (0x3030))
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_ADDR(base) ((base) + (0x3034))
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_ADDR(base) ((base) + (0x3038))
#define SOC_SC_CFG_JTAG_SUPER_ACCESS_ADDR(base) ((base) + (0x3FFC))
#define SOC_SC_GID_QUOTA_ADDR(base,gid_idx) ((base) + (0x4000+(gid_idx)*0x100))
#define SOC_SC_GID_WAY_ALLC_ADDR(base,gid_idx) ((base) + (0x4004+(gid_idx)*0x100))
#define SOC_SC_GID_ALLC_PLC_ADDR(base,gid_idx) ((base) + (0x4008+(gid_idx)*0x100))
#define SOC_SC_GID_MID_FLT0_ADDR(base,gid_idx) ((base) + (0x400C+(gid_idx)*0x100))
#define SOC_SC_GID_MID_FLT1_ADDR(base,gid_idx) ((base) + (0x4010+(gid_idx)*0x100))
#define SOC_SC_CMO_CMD_L_ADDR(base) ((base) + (0x5000))
#define SOC_SC_CMO_CMD_H_ADDR(base) ((base) + (0x5004))
#define SOC_SC_SLC_PERF_MUX_MODE_ADDR(base,slc_idx) ((base) + (0x6000+(slc_idx)*0x400))
#define SOC_SC_SLC_CM_CNT_EN_ADDR(base,slc_idxa) ((base) + (0x6004+(slc_idxa)*0x400))
#define SOC_SC_SLC_CM_CNT_MUX0_ADDR(base,slc_idxa) ((base) + (0x6008+(slc_idxa)*0x400))
#define SOC_SC_SLC_CM_CNT_MUX1_ADDR(base,slc_idxa) ((base) + (0x600C+(slc_idxa)*0x400))
#define SOC_SC_SLC_CM_CNT_MUX2_ADDR(base,slc_idxa) ((base) + (0x6010+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT0_TH_L_ADDR(base,slc_idxa) ((base) + (0x6014+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT0_TH_H_ADDR(base,slc_idxa) ((base) + (0x6018+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT1_TH_L_ADDR(base,slc_idxa) ((base) + (0x601C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT1_TH_H_ADDR(base,slc_idxa) ((base) + (0x6020+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT2_TH_L_ADDR(base,slc_idxa) ((base) + (0x6024+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT2_TH_H_ADDR(base,slc_idxa) ((base) + (0x6028+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT3_TH_L_ADDR(base,slc_idxa) ((base) + (0x602C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT3_TH_H_ADDR(base,slc_idxa) ((base) + (0x6030+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT4_TH_L_ADDR(base,slc_idxa) ((base) + (0x6034+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT4_TH_H_ADDR(base,slc_idxa) ((base) + (0x6038+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT5_TH_L_ADDR(base,slc_idxa) ((base) + (0x603C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT5_TH_H_ADDR(base,slc_idxa) ((base) + (0x6040+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT6_TH_L_ADDR(base,slc_idxa) ((base) + (0x6044+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT6_TH_H_ADDR(base,slc_idxa) ((base) + (0x6048+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT7_TH_L_ADDR(base,slc_idxa) ((base) + (0x604C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT7_TH_H_ADDR(base,slc_idxa) ((base) + (0x6050+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT8_TH_L_ADDR(base,slc_idxa) ((base) + (0x6054+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT8_TH_H_ADDR(base,slc_idxa) ((base) + (0x6058+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT9_TH_L_ADDR(base,slc_idxa) ((base) + (0x605C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT9_TH_H_ADDR(base,slc_idxa) ((base) + (0x6060+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT10_TH_L_ADDR(base,slc_idxa) ((base) + (0x6064+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT10_TH_H_ADDR(base,slc_idxa) ((base) + (0x6068+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT11_TH_L_ADDR(base,slc_idxa) ((base) + (0x606C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT11_TH_H_ADDR(base,slc_idxa) ((base) + (0x6070+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP2_CFG_ADDR(base,slc_idx) ((base) + (0x6094+(slc_idx)*0x400))
#define SOC_SC_SLC_BP5_CFG_ADDR(base,slc_idxa) ((base) + (0x6098+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP6_CFG_ADDR(base,slc_idxa) ((base) + (0x609C+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP7_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60A0+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP7_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60A4+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP7_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60A8+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP8_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60AC+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP8_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60B0+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP8_CFG_3_ADDR(base,slc_idxa) ((base) + (0x60B4+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP8_CFG_4_ADDR(base,slc_idxa) ((base) + (0x60B8+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60BC+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP10_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60C8+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP10_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60CC+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP10_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60D0+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP11_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60D4+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP12_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60DC+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP12_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60E0+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP12_CFG_2_ADDR(base,slc_idxa) ((base) + (0x60E4+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP14A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60E8+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP14A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60EC+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP14B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60F0+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP14B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x60F4+(slc_idxa)*0x400))
#define SOC_SC_SLC_BP15_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60F8+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP0_CFG_0_ADDR(base,slc_idxa) ((base) + (0x60FC+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP0_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6100+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP0_CFG_2_ADDR(base,slc_idxa) ((base) + (0x6104+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP1_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6108+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP1_CFG_1_ADDR(base,slc_idxa) ((base) + (0x610C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP1_CFG_2_ADDR(base,slc_idxa) ((base) + (0x6110+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP2A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6114+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP2A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6118+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP2B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x611C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP2B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6120+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP3A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6124+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP3A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6128+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP3B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x612C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP3B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6130+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP4_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6134+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP5_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6138+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP5_CFG_1_ADDR(base,slc_idxa) ((base) + (0x613C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP6A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6140+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP6A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6144+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP6B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6148+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP6B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x614C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP7A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6150+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP7A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6154+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP7B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6158+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP7B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x615C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP8A_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6160+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP8A_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6164+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP8B_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6168+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP8B_CFG_1_ADDR(base,slc_idxa) ((base) + (0x616C+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6170+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP9_CFG_1_ADDR(base,slc_idxa) ((base) + (0x6174+(slc_idxa)*0x400))
#define SOC_SC_SLC_TCP10_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6178+(slc_idxa)*0x400))
#define SOC_SC_SLC_DCP03_CFG_0_ADDR(base,slc_idxa) ((base) + (0x617C+(slc_idxa)*0x400))
#define SOC_SC_SLC_DCP6_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6180+(slc_idxa)*0x400))
#define SOC_SC_SLC_DCP7_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6184+(slc_idxa)*0x400))
#define SOC_SC_SLC_DCP8_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6188+(slc_idxa)*0x400))
#define SOC_SC_SLC_DCP9_CFG_0_ADDR(base,slc_idxa) ((base) + (0x618C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMP_CFG_0_ADDR(base,slc_idxa) ((base) + (0x6190+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT0_L_ADDR(base,slc_idxa) ((base) + (0x6194+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT0_H_ADDR(base,slc_idxa) ((base) + (0x6198+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT1_L_ADDR(base,slc_idxa) ((base) + (0x619C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT1_H_ADDR(base,slc_idxa) ((base) + (0x61A0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT2_L_ADDR(base,slc_idxa) ((base) + (0x61A4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT2_H_ADDR(base,slc_idxa) ((base) + (0x61A8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT3_L_ADDR(base,slc_idxa) ((base) + (0x61AC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT3_H_ADDR(base,slc_idxa) ((base) + (0x61B0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT4_L_ADDR(base,slc_idxa) ((base) + (0x61B4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT4_H_ADDR(base,slc_idxa) ((base) + (0x61B8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT5_L_ADDR(base,slc_idxa) ((base) + (0x61BC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT5_H_ADDR(base,slc_idxa) ((base) + (0x61C0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT6_L_ADDR(base,slc_idxa) ((base) + (0x61C4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT6_H_ADDR(base,slc_idxa) ((base) + (0x61C8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT7_L_ADDR(base,slc_idxa) ((base) + (0x61CC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT7_H_ADDR(base,slc_idxa) ((base) + (0x61D0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT8_L_ADDR(base,slc_idxa) ((base) + (0x61D4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT8_H_ADDR(base,slc_idxa) ((base) + (0x61D8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT9_L_ADDR(base,slc_idxa) ((base) + (0x61DC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT9_H_ADDR(base,slc_idxa) ((base) + (0x61E0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT10_L_ADDR(base,slc_idxa) ((base) + (0x61E4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT10_H_ADDR(base,slc_idxa) ((base) + (0x61E8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT11_L_ADDR(base,slc_idxa) ((base) + (0x61EC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT11_H_ADDR(base,slc_idxa) ((base) + (0x61F0+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT12_L_ADDR(base,slc_idxa) ((base) + (0x61F4+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT12_H_ADDR(base,slc_idxa) ((base) + (0x61F8+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT13_L_ADDR(base,slc_idxa) ((base) + (0x61FC+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT13_H_ADDR(base,slc_idxa) ((base) + (0x6200+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT14_L_ADDR(base,slc_idxa) ((base) + (0x6204+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT14_H_ADDR(base,slc_idxa) ((base) + (0x6208+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT15_L_ADDR(base,slc_idxa) ((base) + (0x620C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_CNT15_H_ADDR(base,slc_idxa) ((base) + (0x6210+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_STAT_CYCLE_L_ADDR(base,slc_idxa) ((base) + (0x6214+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_STAT_CYCLE_H_ADDR(base,slc_idxa) ((base) + (0x6218+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_STAT_BUSY_L_ADDR(base,slc_idxa) ((base) + (0x621C+(slc_idxa)*0x400))
#define SOC_SC_SLC_PMU_STAT_BUSY_H_ADDR(base,slc_idxa) ((base) + (0x6220+(slc_idxa)*0x400))
#define SOC_SC_SLC_WAY_PWRUP_STAT_ADDR(base,slc_idx) ((base) + (0x8000+(slc_idx)*0x2000))
#define SOC_SC_SLC_GID_COUNT_ADDR(base,gid_idx,slc_idx) ((base) + (0x8010+(slc_idx)*0x2000+(gid_idx)*0x4))
#define SOC_SC_SLC02_INT_ST_ADDR(base,slc_idxa) ((base) + (0x8080+(slc_idxa)*0x2000))
#define SOC_SC_SLC02_INT_INI_ADDR(base,slc_idxa) ((base) + (0x8084+(slc_idxa)*0x2000))
#define SOC_SC_SLC02_INT_CLEAR_ADDR(base,slc_idxa) ((base) + (0x8088+(slc_idxa)*0x2000))
#define SOC_SC_SLC02_INT_EN_ADDR(base,slc_idxa) ((base) + (0x8090+(slc_idxa)*0x2000))
#define SOC_SC_SLC13_INT_ST_ADDR(base,slc_idxb) ((base) + (0x8080+(slc_idxb)*0x2000))
#define SOC_SC_SLC13_INT_INI_ADDR(base,slc_idxb) ((base) + (0x8084+(slc_idxb)*0x2000))
#define SOC_SC_SLC13_INT_CLEAR_ADDR(base,slc_idxb) ((base) + (0x8088+(slc_idxb)*0x2000))
#define SOC_SC_SLC13_INT_EN_ADDR(base,slc_idxb) ((base) + (0x8090+(slc_idxb)*0x2000))
#define SOC_SC_SLC_DFX_MODULE_ADDR(base,slc_idx) ((base) + (0x8400+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCQ_ADDR(base,slc_idx) ((base) + (0x8404+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SQUE0_ADDR(base,slc_idx) ((base) + (0x8410+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_REQ0_ADDR(base,slc_idx) ((base) + (0x8418+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_BUF_ADDR(base,slc_idx) ((base) + (0x8420+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_OT_ADDR(base,slc_idx) ((base) + (0x8424+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_FIFO0_ADDR(base,slc_idx) ((base) + (0x8430+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_FIFO1_ADDR(base,slc_idx) ((base) + (0x8434+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_BP_ADDR(base,slc_idx) ((base) + (0x8440+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_ERR_INF1_ADDR(base,slc_idx) ((base) + (0x8454+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_ERR_INF2_ADDR(base,slc_idx) ((base) + (0x8458+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_ECCERR_ADDR(base,slc_idx) ((base) + (0x8460+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_MEM0_ADDR(base,slc_idx) ((base) + (0x8470+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_MEM1_ADDR(base,slc_idx) ((base) + (0x8474+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_CTRL_ADDR(base,slc_idx) ((base) + (0x8480+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_INFO0_ADDR(base,slc_idx) ((base) + (0x8484+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_INFO1_ADDR(base,slc_idx) ((base) + (0x8488+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_INFO2_ADDR(base,slc_idx) ((base) + (0x848C+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_INFO3_ADDR(base,slc_idx) ((base) + (0x8490+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_SCH_INFO4_ADDR(base,slc_idx) ((base) + (0x8494+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_CMOGEN_ADDR(base,slc_idx) ((base) + (0x84E0+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_DUMMY0_ADDR(base,slc_idx) ((base) + (0x8500+(slc_idx)*0x2000))
#define SOC_SC_SLC_DFX_DUMMY1_ADDR(base,slc_idx) ((base) + (0x8504+(slc_idx)*0x2000))
#define SOC_SC_SLC_WAY_PWRUP_S_ADDR(base,slc_idx) ((base) + (0x9000+(slc_idx)*0x2000))
#define SOC_SC_SLC_SPMEM_CTRL_S_ADDR(base,slc_idx) ((base) + (0x9020+(slc_idx)*0x2000))
#define SOC_SC_SLC_TPMEM_CTRL_S_ADDR(base,slc_idx) ((base) + (0x9024+(slc_idx)*0x2000))
#define SOC_SC_SLC_TAG_MEM_RD_EN_S_ADDR(base,slc_idx) ((base) + (0x9100+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_RD_EN_S_ADDR(base,slc_idx) ((base) + (0x9104+(slc_idx)*0x2000))
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_ADDR(base,slc_idx) ((base) + (0x9108+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_ADDR(base,slc_idx) ((base) + (0x910C+(slc_idx)*0x2000))
#define SOC_SC_SLC_TAG_MEM_DATA_VLD_S_ADDR(base,slc_idx) ((base) + (0x9110+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA_VLD_S_ADDR(base,slc_idx) ((base) + (0x9114+(slc_idx)*0x2000))
#define SOC_SC_SLC_TAG_MEM_DATA_S_ADDR(base,slc_idx) ((base) + (0x911C+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA1_S_ADDR(base,slc_idx) ((base) + (0x9120+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA2_S_ADDR(base,slc_idx) ((base) + (0x9124+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA3_S_ADDR(base,slc_idx) ((base) + (0x9128+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA4_S_ADDR(base,slc_idx) ((base) + (0x912C+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA5_S_ADDR(base,slc_idx) ((base) + (0x9130+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA6_S_ADDR(base,slc_idx) ((base) + (0x9134+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA7_S_ADDR(base,slc_idx) ((base) + (0x9138+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA8_S_ADDR(base,slc_idx) ((base) + (0x913C+(slc_idx)*0x2000))
#define SOC_SC_SLC_DATA_MEM_DATA9_S_ADDR(base,slc_idx) ((base) + (0x9140+(slc_idx)*0x2000))
#define SOC_SC_SLC_DUMMY_RW0_S_ADDR(base,slc_idx) ((base) + (0x9180+(slc_idx)*0x2000))
#define SOC_SC_SLC_DUMMY_RW1_S_ADDR(base,slc_idx) ((base) + (0x9184+(slc_idx)*0x2000))
#define SOC_SC_SLC_DUMMY_RO0_S_ADDR(base,slc_idx) ((base) + (0x9188+(slc_idx)*0x2000))
#define SOC_SC_SLC_DUMMY_RO1_S_ADDR(base,slc_idx) ((base) + (0x918C+(slc_idx)*0x2000))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_SC_GLB_RTL_VER_UNION;
#endif
#define SOC_SC_GLB_RTL_VER_rtl_tag_START (0)
#define SOC_SC_GLB_RTL_VER_rtl_tag_END (7)
#define SOC_SC_GLB_RTL_VER_version_START (16)
#define SOC_SC_GLB_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_SC_GLB_RTL_INFO_UNION;
#endif
#define SOC_SC_GLB_RTL_INFO_rtl_info0_START (0)
#define SOC_SC_GLB_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_SC_GLB_RTL_INF1_UNION;
#endif
#define SOC_SC_GLB_RTL_INF1_rtl_info1_START (0)
#define SOC_SC_GLB_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_SC_GLB_RTL_INF2_UNION;
#endif
#define SOC_SC_GLB_RTL_INF2_rtl_info2_START (0)
#define SOC_SC_GLB_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_way_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_WAY_EN_UNION;
#endif
#define SOC_SC_GLB_WAY_EN_glb_way_en_START (0)
#define SOC_SC_GLB_WAY_EN_glb_way_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int urgt_pri_lvl : 3;
        unsigned int reserved_0 : 1;
        unsigned int urgt_push_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int urgt_weight : 8;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_SC_GLB_QOS_CTRL_URGT_UNION;
#endif
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_pri_lvl_START (0)
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_pri_lvl_END (2)
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_push_en_START (4)
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_push_en_END (4)
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_weight_START (8)
#define SOC_SC_GLB_QOS_CTRL_URGT_urgt_weight_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efifo_flush_lvl : 8;
        unsigned int efifo_flush_timeout : 8;
        unsigned int evict_cmd_pri : 3;
        unsigned int reserved_0 : 1;
        unsigned int mst_port_id : 4;
        unsigned int evict_cmd_mid : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SC_GLB_QOS_CTRL_EV_UNION;
#endif
#define SOC_SC_GLB_QOS_CTRL_EV_efifo_flush_lvl_START (0)
#define SOC_SC_GLB_QOS_CTRL_EV_efifo_flush_lvl_END (7)
#define SOC_SC_GLB_QOS_CTRL_EV_efifo_flush_timeout_START (8)
#define SOC_SC_GLB_QOS_CTRL_EV_efifo_flush_timeout_END (15)
#define SOC_SC_GLB_QOS_CTRL_EV_evict_cmd_pri_START (16)
#define SOC_SC_GLB_QOS_CTRL_EV_evict_cmd_pri_END (18)
#define SOC_SC_GLB_QOS_CTRL_EV_mst_port_id_START (20)
#define SOC_SC_GLB_QOS_CTRL_EV_mst_port_id_END (23)
#define SOC_SC_GLB_QOS_CTRL_EV_evict_cmd_mid_START (24)
#define SOC_SC_GLB_QOS_CTRL_EV_evict_cmd_mid_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdb_alfull_lvl : 7;
        unsigned int reserved_0 : 1;
        unsigned int iwdb_alfull_lvl : 7;
        unsigned int reserved_1 : 1;
        unsigned int sque_cmoblock_lvl : 8;
        unsigned int sque_bp_ctrl : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SC_GLB_QOS_CTRL_SCH_UNION;
#endif
#define SOC_SC_GLB_QOS_CTRL_SCH_fdb_alfull_lvl_START (0)
#define SOC_SC_GLB_QOS_CTRL_SCH_fdb_alfull_lvl_END (6)
#define SOC_SC_GLB_QOS_CTRL_SCH_iwdb_alfull_lvl_START (8)
#define SOC_SC_GLB_QOS_CTRL_SCH_iwdb_alfull_lvl_END (14)
#define SOC_SC_GLB_QOS_CTRL_SCH_sque_cmoblock_lvl_START (16)
#define SOC_SC_GLB_QOS_CTRL_SCH_sque_cmoblock_lvl_END (23)
#define SOC_SC_GLB_QOS_CTRL_SCH_sque_bp_ctrl_START (24)
#define SOC_SC_GLB_QOS_CTRL_SCH_sque_bp_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scq_lvl0 : 8;
        unsigned int scq_lvl0_pri : 3;
        unsigned int reserved_0 : 5;
        unsigned int scq_lvl1 : 8;
        unsigned int scq_lvl1_pri : 3;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_SC_GLB_SCQ_CTRL0_UNION;
#endif
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl0_START (0)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl0_END (7)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl0_pri_START (8)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl0_pri_END (10)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl1_START (16)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl1_END (23)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl1_pri_START (24)
#define SOC_SC_GLB_SCQ_CTRL0_scq_lvl1_pri_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scq_lvl2 : 8;
        unsigned int scq_lvl2_pri : 3;
        unsigned int reserved_0 : 5;
        unsigned int scq_lvl3 : 8;
        unsigned int scq_lvl3_pri : 3;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_SC_GLB_SCQ_CTRL1_UNION;
#endif
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl2_START (0)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl2_END (7)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl2_pri_START (8)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl2_pri_END (10)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl3_START (16)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl3_END (23)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl3_pri_START (24)
#define SOC_SC_GLB_SCQ_CTRL1_scq_lvl3_pri_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfc0_ostd_lvl : 8;
        unsigned int cfc0_bandwidth : 8;
        unsigned int cfc0_saturation : 10;
        unsigned int cfc0_lp : 2;
        unsigned int cfc0_mode : 2;
        unsigned int cfc0_flux_ctrl : 1;
        unsigned int cfc0_en : 1;
    } reg;
} SOC_SC_GLB_CFC0_UNION;
#endif
#define SOC_SC_GLB_CFC0_cfc0_ostd_lvl_START (0)
#define SOC_SC_GLB_CFC0_cfc0_ostd_lvl_END (7)
#define SOC_SC_GLB_CFC0_cfc0_bandwidth_START (8)
#define SOC_SC_GLB_CFC0_cfc0_bandwidth_END (15)
#define SOC_SC_GLB_CFC0_cfc0_saturation_START (16)
#define SOC_SC_GLB_CFC0_cfc0_saturation_END (25)
#define SOC_SC_GLB_CFC0_cfc0_lp_START (26)
#define SOC_SC_GLB_CFC0_cfc0_lp_END (27)
#define SOC_SC_GLB_CFC0_cfc0_mode_START (28)
#define SOC_SC_GLB_CFC0_cfc0_mode_END (29)
#define SOC_SC_GLB_CFC0_cfc0_flux_ctrl_START (30)
#define SOC_SC_GLB_CFC0_cfc0_flux_ctrl_END (30)
#define SOC_SC_GLB_CFC0_cfc0_en_START (31)
#define SOC_SC_GLB_CFC0_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfc1_ostd_lvl : 8;
        unsigned int cfc1_bandwidth : 8;
        unsigned int cfc1_saturation : 10;
        unsigned int cfc1_lp : 2;
        unsigned int cfc1_mode : 2;
        unsigned int cfc1_flux_ctrl : 1;
        unsigned int cfc1_en : 1;
    } reg;
} SOC_SC_GLB_CFC1_UNION;
#endif
#define SOC_SC_GLB_CFC1_cfc1_ostd_lvl_START (0)
#define SOC_SC_GLB_CFC1_cfc1_ostd_lvl_END (7)
#define SOC_SC_GLB_CFC1_cfc1_bandwidth_START (8)
#define SOC_SC_GLB_CFC1_cfc1_bandwidth_END (15)
#define SOC_SC_GLB_CFC1_cfc1_saturation_START (16)
#define SOC_SC_GLB_CFC1_cfc1_saturation_END (25)
#define SOC_SC_GLB_CFC1_cfc1_lp_START (26)
#define SOC_SC_GLB_CFC1_cfc1_lp_END (27)
#define SOC_SC_GLB_CFC1_cfc1_mode_START (28)
#define SOC_SC_GLB_CFC1_cfc1_mode_END (29)
#define SOC_SC_GLB_CFC1_cfc1_flux_ctrl_START (30)
#define SOC_SC_GLB_CFC1_cfc1_flux_ctrl_END (30)
#define SOC_SC_GLB_CFC1_cfc1_en_START (31)
#define SOC_SC_GLB_CFC1_cfc1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_byp_cfg : 1;
        unsigned int ckg_byp_slc : 1;
        unsigned int ckg_byp_bc : 1;
        unsigned int ckg_byp_fdb : 1;
        unsigned int ckg_byp_req : 1;
        unsigned int ckg_byp_sque : 1;
        unsigned int ckg_byp_slv : 1;
        unsigned int ckg_byp_mst : 1;
        unsigned int ckg_byp_tagctl : 1;
        unsigned int ckg_byp_ram : 1;
        unsigned int ckg_byp_pmu : 1;
        unsigned int ckg_byp_cmo : 1;
        unsigned int ckg_byp_lp : 1;
        unsigned int ckg_byp_datctl : 1;
        unsigned int ckg_byp_dummy : 2;
        unsigned int ckg_byp_sc : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SC_GLB_CKG_BYP_UNION;
#endif
#define SOC_SC_GLB_CKG_BYP_ckg_byp_cfg_START (0)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_cfg_END (0)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_slc_START (1)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_slc_END (1)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_bc_START (2)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_bc_END (2)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_fdb_START (3)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_fdb_END (3)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_req_START (4)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_req_END (4)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_sque_START (5)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_sque_END (5)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_slv_START (6)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_slv_END (6)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_mst_START (7)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_mst_END (7)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_tagctl_START (8)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_tagctl_END (8)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_ram_START (9)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_ram_END (9)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_pmu_START (10)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_pmu_END (10)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_cmo_START (11)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_cmo_END (11)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_lp_START (12)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_lp_END (12)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_datctl_START (13)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_datctl_END (13)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_dummy_START (14)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_dummy_END (15)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_sc_START (16)
#define SOC_SC_GLB_CKG_BYP_ckg_byp_sc_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_busy_ext : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_GLB_CKG_EXT_UNION;
#endif
#define SOC_SC_GLB_CKG_EXT_ckg_busy_ext_START (0)
#define SOC_SC_GLB_CKG_EXT_ckg_busy_ext_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int func_byp_sque_sprd : 1;
        unsigned int func_byp_ecc : 1;
        unsigned int func_byp_busy_ext : 1;
        unsigned int func_byp_dmem_dyn_lp : 1;
        unsigned int func_byp_tmem_dyn_lp : 1;
        unsigned int func_byp_quota_block : 1;
        unsigned int func_byp_bypefifo : 1;
        unsigned int func_byp_req_rh : 1;
        unsigned int func_byp_slv_ostd : 1;
        unsigned int func_byp_mst_ostd : 1;
        unsigned int func_byp_waygrp_cnt : 1;
        unsigned int func_byp_pmuckg : 1;
        unsigned int func_byp_dummy : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_FUNC_BYP_UNION;
#endif
#define SOC_SC_GLB_FUNC_BYP_func_byp_sque_sprd_START (0)
#define SOC_SC_GLB_FUNC_BYP_func_byp_sque_sprd_END (0)
#define SOC_SC_GLB_FUNC_BYP_func_byp_ecc_START (1)
#define SOC_SC_GLB_FUNC_BYP_func_byp_ecc_END (1)
#define SOC_SC_GLB_FUNC_BYP_func_byp_busy_ext_START (2)
#define SOC_SC_GLB_FUNC_BYP_func_byp_busy_ext_END (2)
#define SOC_SC_GLB_FUNC_BYP_func_byp_dmem_dyn_lp_START (3)
#define SOC_SC_GLB_FUNC_BYP_func_byp_dmem_dyn_lp_END (3)
#define SOC_SC_GLB_FUNC_BYP_func_byp_tmem_dyn_lp_START (4)
#define SOC_SC_GLB_FUNC_BYP_func_byp_tmem_dyn_lp_END (4)
#define SOC_SC_GLB_FUNC_BYP_func_byp_quota_block_START (5)
#define SOC_SC_GLB_FUNC_BYP_func_byp_quota_block_END (5)
#define SOC_SC_GLB_FUNC_BYP_func_byp_bypefifo_START (6)
#define SOC_SC_GLB_FUNC_BYP_func_byp_bypefifo_END (6)
#define SOC_SC_GLB_FUNC_BYP_func_byp_req_rh_START (7)
#define SOC_SC_GLB_FUNC_BYP_func_byp_req_rh_END (7)
#define SOC_SC_GLB_FUNC_BYP_func_byp_slv_ostd_START (8)
#define SOC_SC_GLB_FUNC_BYP_func_byp_slv_ostd_END (8)
#define SOC_SC_GLB_FUNC_BYP_func_byp_mst_ostd_START (9)
#define SOC_SC_GLB_FUNC_BYP_func_byp_mst_ostd_END (9)
#define SOC_SC_GLB_FUNC_BYP_func_byp_waygrp_cnt_START (10)
#define SOC_SC_GLB_FUNC_BYP_func_byp_waygrp_cnt_END (10)
#define SOC_SC_GLB_FUNC_BYP_func_byp_pmuckg_START (11)
#define SOC_SC_GLB_FUNC_BYP_func_byp_pmuckg_END (11)
#define SOC_SC_GLB_FUNC_BYP_func_byp_dummy_START (12)
#define SOC_SC_GLB_FUNC_BYP_func_byp_dummy_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int param_ovrd_ififo_depth : 7;
        unsigned int reserved : 1;
        unsigned int param_ovrd_iwdb_depth : 2;
        unsigned int param_ovrd_ewdb_depth : 2;
        unsigned int param_ovrd_efifo_depth : 4;
        unsigned int param_ovrd_sque_depth : 6;
        unsigned int param_ovrd_fdb_alcmem_depth : 2;
        unsigned int param_ovrd_fdb_slvfifo_depth : 7;
        unsigned int param_ovrd_en : 1;
    } reg;
} SOC_SC_GLB_PARAM_OVRD_UNION;
#endif
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_ififo_depth_START (0)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_ififo_depth_END (6)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_iwdb_depth_START (8)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_iwdb_depth_END (9)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_ewdb_depth_START (10)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_ewdb_depth_END (11)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_efifo_depth_START (12)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_efifo_depth_END (15)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_sque_depth_START (16)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_sque_depth_END (21)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_fdb_alcmem_depth_START (22)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_fdb_alcmem_depth_END (23)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_fdb_slvfifo_depth_START (24)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_fdb_slvfifo_depth_END (30)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_en_START (31)
#define SOC_SC_GLB_PARAM_OVRD_param_ovrd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_statgo_event0 : 4;
        unsigned int pmu_statgo_event1 : 4;
        unsigned int pmu_statgo_bw : 4;
        unsigned int pmu_statgo_glb : 4;
        unsigned int bit_en : 16;
    } reg;
} SOC_SC_GLB_PMU_CTRL_UNION;
#endif
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_event0_START (0)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_event0_END (3)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_event1_START (4)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_event1_END (7)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_bw_START (8)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_bw_END (11)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_glb_START (12)
#define SOC_SC_GLB_PMU_CTRL_pmu_statgo_glb_END (15)
#define SOC_SC_GLB_PMU_CTRL_bit_en_START (16)
#define SOC_SC_GLB_PMU_CTRL_bit_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt_mode_sel_sl0 : 4;
        unsigned int pmu_cnt_mode_sel_sl1 : 4;
        unsigned int pmu_cnt_mode_sel_sl2 : 4;
        unsigned int pmu_cnt_mode_sel_sl3 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_UNION;
#endif
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl0_START (0)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl0_END (3)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl1_START (4)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl1_END (7)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl2_START (8)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl2_END (11)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl3_START (12)
#define SOC_SC_GLB_PMU_CNT8_11_MODE_SEL_pmu_cnt_mode_sel_sl3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_sec_attr : 2;
        unsigned int reserved_0 : 14;
        unsigned int va_cmo_bypass : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_SC_CFG_GID_SEC_ATTR_S_UNION;
#endif
#define SOC_SC_CFG_GID_SEC_ATTR_S_gid_sec_attr_START (0)
#define SOC_SC_CFG_GID_SEC_ATTR_S_gid_sec_attr_END (1)
#define SOC_SC_CFG_GID_SEC_ATTR_S_va_cmo_bypass_START (16)
#define SOC_SC_CFG_GID_SEC_ATTR_S_va_cmo_bypass_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid0_bypass_policy : 2;
        unsigned int reserved_0 : 2;
        unsigned int glb_trusted_allocate_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int glb_prot_allocate_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int glb_invld_cmo_override : 2;
        unsigned int reserved_3 : 2;
        unsigned int glb_half_hit_alloc : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_SC_GLB_ALLC_PLC_S_UNION;
#endif
#define SOC_SC_GLB_ALLC_PLC_S_gid0_bypass_policy_START (0)
#define SOC_SC_GLB_ALLC_PLC_S_gid0_bypass_policy_END (1)
#define SOC_SC_GLB_ALLC_PLC_S_glb_trusted_allocate_en_START (4)
#define SOC_SC_GLB_ALLC_PLC_S_glb_trusted_allocate_en_END (4)
#define SOC_SC_GLB_ALLC_PLC_S_glb_prot_allocate_en_START (8)
#define SOC_SC_GLB_ALLC_PLC_S_glb_prot_allocate_en_END (8)
#define SOC_SC_GLB_ALLC_PLC_S_glb_invld_cmo_override_START (12)
#define SOC_SC_GLB_ALLC_PLC_S_glb_invld_cmo_override_END (13)
#define SOC_SC_GLB_ALLC_PLC_S_glb_half_hit_alloc_START (16)
#define SOC_SC_GLB_ALLC_PLC_S_glb_half_hit_alloc_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_scb_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_GLB_SCB_EN_S_UNION;
#endif
#define SOC_SC_GLB_SCB_EN_S_glb_scb_en_START (0)
#define SOC_SC_GLB_SCB_EN_S_glb_scb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_slp_byp : 1;
        unsigned int mem_slp_mode : 1;
        unsigned int reserved_0 : 2;
        unsigned int mem_slp_zcnt : 2;
        unsigned int reserved_1 : 2;
        unsigned int mem_slp_tcnt : 8;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_SC_GLB_MEM_LP_SLP_S_UNION;
#endif
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_byp_START (0)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_byp_END (0)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_mode_START (1)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_mode_END (1)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_zcnt_START (4)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_zcnt_END (5)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_tcnt_START (8)
#define SOC_SC_GLB_MEM_LP_SLP_S_mem_slp_tcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_sta_ls_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_MEM_LP_STA0_S_UNION;
#endif
#define SOC_SC_GLB_MEM_LP_STA0_S_mem_sta_ls_en_START (0)
#define SOC_SC_GLB_MEM_LP_STA0_S_mem_sta_ls_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_sta_ds_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_MEM_LP_STA1_S_UNION;
#endif
#define SOC_SC_GLB_MEM_LP_STA1_S_mem_sta_ds_en_START (0)
#define SOC_SC_GLB_MEM_LP_STA1_S_mem_sta_ds_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_sta_sd_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_MEM_LP_STA2_S_UNION;
#endif
#define SOC_SC_GLB_MEM_LP_STA2_S_mem_sta_sd_en_START (0)
#define SOC_SC_GLB_MEM_LP_STA2_S_mem_sta_sd_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmem_tslpwk2clk : 8;
        unsigned int tmem_tslpwk2clk : 8;
        unsigned int mem_tsdwk2clk : 8;
        unsigned int mem_tintvl : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_SC_GLB_MEM_LP_PARAM_S_UNION;
#endif
#define SOC_SC_GLB_MEM_LP_PARAM_S_dmem_tslpwk2clk_START (0)
#define SOC_SC_GLB_MEM_LP_PARAM_S_dmem_tslpwk2clk_END (7)
#define SOC_SC_GLB_MEM_LP_PARAM_S_tmem_tslpwk2clk_START (8)
#define SOC_SC_GLB_MEM_LP_PARAM_S_tmem_tslpwk2clk_END (15)
#define SOC_SC_GLB_MEM_LP_PARAM_S_mem_tsdwk2clk_START (16)
#define SOC_SC_GLB_MEM_LP_PARAM_S_mem_tsdwk2clk_END (23)
#define SOC_SC_GLB_MEM_LP_PARAM_S_mem_tintvl_START (24)
#define SOC_SC_GLB_MEM_LP_PARAM_S_mem_tintvl_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int func_byp_paf : 1;
        unsigned int func_byp_acpucmo : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_GLB_FUNC_BYP_S_UNION;
#endif
#define SOC_SC_GLB_FUNC_BYP_S_func_byp_paf_START (0)
#define SOC_SC_GLB_FUNC_BYP_S_func_byp_paf_END (0)
#define SOC_SC_GLB_FUNC_BYP_S_func_byp_acpucmo_START (1)
#define SOC_SC_GLB_FUNC_BYP_S_func_byp_acpucmo_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_dummy_rw0 : 32;
    } reg;
} SOC_SC_GLB_DUMMY_RW0_S_UNION;
#endif
#define SOC_SC_GLB_DUMMY_RW0_S_glb_dummy_rw0_START (0)
#define SOC_SC_GLB_DUMMY_RW0_S_glb_dummy_rw0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_dummy_rw1 : 32;
    } reg;
} SOC_SC_GLB_DUMMY_RW1_S_UNION;
#endif
#define SOC_SC_GLB_DUMMY_RW1_S_glb_dummy_rw1_START (0)
#define SOC_SC_GLB_DUMMY_RW1_S_glb_dummy_rw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_dummy_ro0 : 32;
    } reg;
} SOC_SC_GLB_DUMMY_RO0_S_UNION;
#endif
#define SOC_SC_GLB_DUMMY_RO0_S_glb_dummy_ro0_START (0)
#define SOC_SC_GLB_DUMMY_RO0_S_glb_dummy_ro0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_dummy_ro1 : 32;
    } reg;
} SOC_SC_GLB_DUMMY_RO1_S_UNION;
#endif
#define SOC_SC_GLB_DUMMY_RO1_S_glb_dummy_ro1_START (0)
#define SOC_SC_GLB_DUMMY_RO1_S_glb_dummy_ro1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_pmu_cnt_int_st : 4;
        unsigned int glb_eccerr_st : 4;
        unsigned int glb_dfx_err_st : 4;
        unsigned int cmo_cmd_access_err_st : 1;
        unsigned int cmo_overflow_st : 1;
        unsigned int cmo_pa_err_st : 1;
        unsigned int cmo_byway_err_st : 1;
        unsigned int cmo_bygid_err_st : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SC_CFG_INT_STATUS_UNION;
#endif
#define SOC_SC_CFG_INT_STATUS_glb_pmu_cnt_int_st_START (0)
#define SOC_SC_CFG_INT_STATUS_glb_pmu_cnt_int_st_END (3)
#define SOC_SC_CFG_INT_STATUS_glb_eccerr_st_START (4)
#define SOC_SC_CFG_INT_STATUS_glb_eccerr_st_END (7)
#define SOC_SC_CFG_INT_STATUS_glb_dfx_err_st_START (8)
#define SOC_SC_CFG_INT_STATUS_glb_dfx_err_st_END (11)
#define SOC_SC_CFG_INT_STATUS_cmo_cmd_access_err_st_START (12)
#define SOC_SC_CFG_INT_STATUS_cmo_cmd_access_err_st_END (12)
#define SOC_SC_CFG_INT_STATUS_cmo_overflow_st_START (13)
#define SOC_SC_CFG_INT_STATUS_cmo_overflow_st_END (13)
#define SOC_SC_CFG_INT_STATUS_cmo_pa_err_st_START (14)
#define SOC_SC_CFG_INT_STATUS_cmo_pa_err_st_END (14)
#define SOC_SC_CFG_INT_STATUS_cmo_byway_err_st_START (15)
#define SOC_SC_CFG_INT_STATUS_cmo_byway_err_st_END (15)
#define SOC_SC_CFG_INT_STATUS_cmo_bygid_err_st_START (16)
#define SOC_SC_CFG_INT_STATUS_cmo_bygid_err_st_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int cmo_cmd_access_err_ini : 1;
        unsigned int cmo_overflow_ini : 1;
        unsigned int cmo_pa_err_ini : 1;
        unsigned int cmo_byway_err_ini : 1;
        unsigned int cmo_bygid_err_ini : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_SC_CMO_CFG_INT_INI_UNION;
#endif
#define SOC_SC_CMO_CFG_INT_INI_cmo_cmd_access_err_ini_START (12)
#define SOC_SC_CMO_CFG_INT_INI_cmo_cmd_access_err_ini_END (12)
#define SOC_SC_CMO_CFG_INT_INI_cmo_overflow_ini_START (13)
#define SOC_SC_CMO_CFG_INT_INI_cmo_overflow_ini_END (13)
#define SOC_SC_CMO_CFG_INT_INI_cmo_pa_err_ini_START (14)
#define SOC_SC_CMO_CFG_INT_INI_cmo_pa_err_ini_END (14)
#define SOC_SC_CMO_CFG_INT_INI_cmo_byway_err_ini_START (15)
#define SOC_SC_CMO_CFG_INT_INI_cmo_byway_err_ini_END (15)
#define SOC_SC_CMO_CFG_INT_INI_cmo_bygid_err_ini_START (16)
#define SOC_SC_CMO_CFG_INT_INI_cmo_bygid_err_ini_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int cmo_cmd_access_err_en : 1;
        unsigned int cmo_overflow_en : 1;
        unsigned int cmo_pa_err_en : 1;
        unsigned int cmo_byway_err_en : 1;
        unsigned int cmo_bygid_err_en : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_SC_CMO_CFG_INT_EN_UNION;
#endif
#define SOC_SC_CMO_CFG_INT_EN_cmo_cmd_access_err_en_START (12)
#define SOC_SC_CMO_CFG_INT_EN_cmo_cmd_access_err_en_END (12)
#define SOC_SC_CMO_CFG_INT_EN_cmo_overflow_en_START (13)
#define SOC_SC_CMO_CFG_INT_EN_cmo_overflow_en_END (13)
#define SOC_SC_CMO_CFG_INT_EN_cmo_pa_err_en_START (14)
#define SOC_SC_CMO_CFG_INT_EN_cmo_pa_err_en_END (14)
#define SOC_SC_CMO_CFG_INT_EN_cmo_byway_err_en_START (15)
#define SOC_SC_CMO_CFG_INT_EN_cmo_byway_err_en_END (15)
#define SOC_SC_CMO_CFG_INT_EN_cmo_bygid_err_en_START (16)
#define SOC_SC_CMO_CFG_INT_EN_cmo_bygid_err_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int cmo_cmd_access_err_clr : 1;
        unsigned int cmo_overflow_clr : 1;
        unsigned int cmo_pa_err_clr : 1;
        unsigned int cmo_byway_err_clr : 1;
        unsigned int cmo_bygid_err_clr : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_SC_CMO_CFG_INT_CLR_UNION;
#endif
#define SOC_SC_CMO_CFG_INT_CLR_cmo_cmd_access_err_clr_START (12)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_cmd_access_err_clr_END (12)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_overflow_clr_START (13)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_overflow_clr_END (13)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_pa_err_clr_START (14)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_pa_err_clr_END (14)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_byway_err_clr_START (15)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_byway_err_clr_END (15)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_bygid_err_clr_START (16)
#define SOC_SC_CMO_CFG_INT_CLR_cmo_bygid_err_clr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_queue_cnt : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SC_CFG_CMO_QUEUE_CNT_UNION;
#endif
#define SOC_SC_CFG_CMO_QUEUE_CNT_cmo_queue_cnt_START (0)
#define SOC_SC_CFG_CMO_QUEUE_CNT_cmo_queue_cnt_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_regu_evt_time : 24;
        unsigned int reserved : 7;
        unsigned int cmo_regu_evt_en : 1;
    } reg;
} SOC_SC_CFG_CMO_REGULAR_EVT_TIME_UNION;
#endif
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_time_START (0)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_time_END (23)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_en_START (31)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_ready_wait_time : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SC_CFG_READY_WAIT_TIME_UNION;
#endif
#define SOC_SC_CFG_READY_WAIT_TIME_cfg_ready_wait_time_START (0)
#define SOC_SC_CFG_READY_WAIT_TIME_cfg_ready_wait_time_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_err_cmd_l : 32;
    } reg;
} SOC_SC_CFG_CMO_ERR_CMD_L_UNION;
#endif
#define SOC_SC_CFG_CMO_ERR_CMD_L_cmo_err_cmd_l_START (0)
#define SOC_SC_CFG_CMO_ERR_CMD_L_cmo_err_cmd_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_err_cmd_h : 32;
    } reg;
} SOC_SC_CFG_CMO_ERR_CMD_H_UNION;
#endif
#define SOC_SC_CFG_CMO_ERR_CMD_H_cmo_err_cmd_h_START (0)
#define SOC_SC_CFG_CMO_ERR_CMD_H_cmo_err_cmd_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_dfx_distr_st : 32;
    } reg;
} SOC_SC_CFG_DFX_DISTR_UNION;
#endif
#define SOC_SC_CFG_DFX_DISTR_cmo_dfx_distr_st_START (0)
#define SOC_SC_CFG_DFX_DISTR_cmo_dfx_distr_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_finish_flag : 1;
        unsigned int rpt_type_event : 1;
        unsigned int rpt_type_int : 1;
        unsigned int thread_id : 16;
        unsigned int sync_seq_num : 10;
        unsigned int reserved : 3;
    } reg;
} SOC_SC_CFG_CMO_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_STATUS_event_finish_flag_START (0)
#define SOC_SC_CFG_CMO_STATUS_event_finish_flag_END (0)
#define SOC_SC_CFG_CMO_STATUS_rpt_type_event_START (1)
#define SOC_SC_CFG_CMO_STATUS_rpt_type_event_END (1)
#define SOC_SC_CFG_CMO_STATUS_rpt_type_int_START (2)
#define SOC_SC_CFG_CMO_STATUS_rpt_type_int_END (2)
#define SOC_SC_CFG_CMO_STATUS_thread_id_START (3)
#define SOC_SC_CFG_CMO_STATUS_thread_id_END (18)
#define SOC_SC_CFG_CMO_STATUS_sync_seq_num_START (19)
#define SOC_SC_CFG_CMO_STATUS_sync_seq_num_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 19;
        unsigned int event_int_clr : 10;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SC_CFG_CMO_CLEAR_UNION;
#endif
#define SOC_SC_CFG_CMO_CLEAR_event_int_clr_START (19)
#define SOC_SC_CFG_CMO_CLEAR_event_int_clr_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_nonsec_cfg : 1;
        unsigned int pmu_nonsec_cfg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_CFG_NON_SECURITY_CFG_S_UNION;
#endif
#define SOC_SC_CFG_NON_SECURITY_CFG_S_glb_nonsec_cfg_START (0)
#define SOC_SC_CFG_NON_SECURITY_CFG_S_glb_nonsec_cfg_END (0)
#define SOC_SC_CFG_NON_SECURITY_CFG_S_pmu_nonsec_cfg_START (1)
#define SOC_SC_CFG_NON_SECURITY_CFG_S_pmu_nonsec_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int allow_mid1 : 6;
        unsigned int reserved_0 : 2;
        unsigned int allow_mid2 : 6;
        unsigned int reserved_1 : 2;
        unsigned int allow_mid1_mask : 6;
        unsigned int reserved_2 : 2;
        unsigned int allow_mid2_mask : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_SC_CFG_ALLOW_MID_S_UNION;
#endif
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_START (0)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_END (5)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_START (8)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_END (13)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_mask_START (16)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_mask_END (21)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_mask_START (24)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_mask_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_slice_intlv : 2;
        unsigned int cmo_overflow_mode : 1;
        unsigned int cmo_addr_shift_mode : 2;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_SC_CFG_CMO_SET_S_UNION;
#endif
#define SOC_SC_CFG_CMO_SET_S_cmo_slice_intlv_START (0)
#define SOC_SC_CFG_CMO_SET_S_cmo_slice_intlv_END (1)
#define SOC_SC_CFG_CMO_SET_S_cmo_overflow_mode_START (2)
#define SOC_SC_CFG_CMO_SET_S_cmo_overflow_mode_END (2)
#define SOC_SC_CFG_CMO_SET_S_cmo_addr_shift_mode_START (3)
#define SOC_SC_CFG_CMO_SET_S_cmo_addr_shift_mode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_en_addr_hole_0 : 1;
        unsigned int cmo_en_addr_hole_1 : 1;
        unsigned int cmo_en_addr_hole_2 : 1;
        unsigned int cmo_en_addr_hole_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_UNION;
#endif
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_0_END (0)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_1_START (1)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_1_END (1)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_2_START (2)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_2_END (2)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_3_START (3)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_str_addr_hole_0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_cmo_str_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_cmo_str_addr_hole_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_end_addr_hole_0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_cmo_end_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_cmo_end_addr_hole_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_str_addr_hole_1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_cmo_str_addr_hole_1_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_cmo_str_addr_hole_1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_end_addr_hole_1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_cmo_end_addr_hole_1_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_cmo_end_addr_hole_1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_str_addr_hole_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_cmo_str_addr_hole_2_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_cmo_str_addr_hole_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_end_addr_hole_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_cmo_end_addr_hole_2_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_cmo_end_addr_hole_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_str_addr_hole_3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_cmo_str_addr_hole_3_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_cmo_str_addr_hole_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_end_addr_hole_3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_cmo_end_addr_hole_3_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_cmo_end_addr_hole_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CFG_CMO_TPMEM_CTRL_S_UNION;
#endif
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_cmo_tpmem_ctrl_START (0)
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_cmo_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jtag_grant_force : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_CFG_JTAG_SUPER_ACCESS_UNION;
#endif
#define SOC_SC_CFG_JTAG_SUPER_ACCESS_jtag_grant_force_START (0)
#define SOC_SC_CFG_JTAG_SUPER_ACCESS_jtag_grant_force_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int quota_l : 16;
        unsigned int quota_h : 16;
    } reg;
} SOC_SC_GID_QUOTA_UNION;
#endif
#define SOC_SC_GID_QUOTA_quota_l_START (0)
#define SOC_SC_GID_QUOTA_quota_l_END (15)
#define SOC_SC_GID_QUOTA_quota_h_START (16)
#define SOC_SC_GID_QUOTA_quota_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_way_enable : 16;
        unsigned int gid_way_search : 16;
    } reg;
} SOC_SC_GID_WAY_ALLC_UNION;
#endif
#define SOC_SC_GID_WAY_ALLC_gid_way_enable_START (0)
#define SOC_SC_GID_WAY_ALLC_gid_way_enable_END (15)
#define SOC_SC_GID_WAY_ALLC_gid_way_search_START (16)
#define SOC_SC_GID_WAY_ALLC_gid_way_search_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int normal_rd_allc_plc : 2;
        unsigned int normal_wr_allc_plc : 2;
        unsigned int midflt_rd_allc_plc : 2;
        unsigned int midflt_wr_allc_plc : 2;
        unsigned int replace_same_gid_en : 1;
        unsigned int gid_priority : 2;
        unsigned int gid_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_GID_ALLC_PLC_UNION;
#endif
#define SOC_SC_GID_ALLC_PLC_normal_rd_allc_plc_START (0)
#define SOC_SC_GID_ALLC_PLC_normal_rd_allc_plc_END (1)
#define SOC_SC_GID_ALLC_PLC_normal_wr_allc_plc_START (2)
#define SOC_SC_GID_ALLC_PLC_normal_wr_allc_plc_END (3)
#define SOC_SC_GID_ALLC_PLC_midflt_rd_allc_plc_START (4)
#define SOC_SC_GID_ALLC_PLC_midflt_rd_allc_plc_END (5)
#define SOC_SC_GID_ALLC_PLC_midflt_wr_allc_plc_START (6)
#define SOC_SC_GID_ALLC_PLC_midflt_wr_allc_plc_END (7)
#define SOC_SC_GID_ALLC_PLC_replace_same_gid_en_START (8)
#define SOC_SC_GID_ALLC_PLC_replace_same_gid_en_END (8)
#define SOC_SC_GID_ALLC_PLC_gid_priority_START (9)
#define SOC_SC_GID_ALLC_PLC_gid_priority_END (10)
#define SOC_SC_GID_ALLC_PLC_gid_en_START (11)
#define SOC_SC_GID_ALLC_PLC_gid_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flt0 : 7;
        unsigned int reserved_0 : 9;
        unsigned int mid_flt0_mask : 7;
        unsigned int reserved_1 : 8;
        unsigned int mid_flt0_en : 1;
    } reg;
} SOC_SC_GID_MID_FLT0_UNION;
#endif
#define SOC_SC_GID_MID_FLT0_mid_flt0_START (0)
#define SOC_SC_GID_MID_FLT0_mid_flt0_END (6)
#define SOC_SC_GID_MID_FLT0_mid_flt0_mask_START (16)
#define SOC_SC_GID_MID_FLT0_mid_flt0_mask_END (22)
#define SOC_SC_GID_MID_FLT0_mid_flt0_en_START (31)
#define SOC_SC_GID_MID_FLT0_mid_flt0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_flt1 : 7;
        unsigned int reserved_0 : 9;
        unsigned int mid_flt1_mask : 7;
        unsigned int reserved_1 : 8;
        unsigned int mid_flt1_en : 1;
    } reg;
} SOC_SC_GID_MID_FLT1_UNION;
#endif
#define SOC_SC_GID_MID_FLT1_mid_flt1_START (0)
#define SOC_SC_GID_MID_FLT1_mid_flt1_END (6)
#define SOC_SC_GID_MID_FLT1_mid_flt1_mask_START (16)
#define SOC_SC_GID_MID_FLT1_mid_flt1_mask_END (22)
#define SOC_SC_GID_MID_FLT1_mid_flt1_en_START (31)
#define SOC_SC_GID_MID_FLT1_mid_flt1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_cmd_l : 32;
    } reg;
} SOC_SC_CMO_CMD_L_UNION;
#endif
#define SOC_SC_CMO_CMD_L_cmo_cmd_l_START (0)
#define SOC_SC_CMO_CMD_L_cmo_cmd_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmo_cmd_h : 32;
    } reg;
} SOC_SC_CMO_CMD_H_UNION;
#endif
#define SOC_SC_CMO_CMD_H_cmo_cmd_h_START (0)
#define SOC_SC_CMO_CMD_H_cmo_cmd_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int perf1_mode_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SLC_PERF_MUX_MODE_UNION;
#endif
#define SOC_SC_SLC_PERF_MUX_MODE_perf1_mode_sel_START (0)
#define SOC_SC_SLC_PERF_MUX_MODE_perf1_mode_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SLC_CM_CNT_EN_UNION;
#endif
#define SOC_SC_SLC_CM_CNT_EN_pmu_cnt_en_START (0)
#define SOC_SC_SLC_CM_CNT_EN_pmu_cnt_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_mux : 8;
        unsigned int pmu_cnt1_mux : 8;
        unsigned int pmu_cnt2_mux : 8;
        unsigned int pmu_cnt3_mux : 8;
    } reg;
} SOC_SC_SLC_CM_CNT_MUX0_UNION;
#endif
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt0_mux_START (0)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt0_mux_END (7)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt1_mux_START (8)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt1_mux_END (15)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt2_mux_START (16)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt2_mux_END (23)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt3_mux_START (24)
#define SOC_SC_SLC_CM_CNT_MUX0_pmu_cnt3_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt4_mux : 8;
        unsigned int pmu_cnt5_mux : 8;
        unsigned int pmu_cnt6_mux : 8;
        unsigned int pmu_cnt7_mux : 8;
    } reg;
} SOC_SC_SLC_CM_CNT_MUX1_UNION;
#endif
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt4_mux_START (0)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt4_mux_END (7)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt5_mux_START (8)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt5_mux_END (15)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt6_mux_START (16)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt6_mux_END (23)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt7_mux_START (24)
#define SOC_SC_SLC_CM_CNT_MUX1_pmu_cnt7_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt8_mux : 8;
        unsigned int pmu_cnt9_mux : 8;
        unsigned int pmu_cnt10_mux : 8;
        unsigned int pmu_cnt11_mux : 8;
    } reg;
} SOC_SC_SLC_CM_CNT_MUX2_UNION;
#endif
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt8_mux_START (0)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt8_mux_END (7)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt9_mux_START (8)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt9_mux_END (15)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt10_mux_START (16)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt10_mux_END (23)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt11_mux_START (24)
#define SOC_SC_SLC_CM_CNT_MUX2_pmu_cnt11_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT0_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT0_TH_L_pmu_cnt0_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT0_TH_L_pmu_cnt0_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT0_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT0_TH_H_pmu_cnt0_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT0_TH_H_pmu_cnt0_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt1_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT1_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT1_TH_L_pmu_cnt1_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT1_TH_L_pmu_cnt1_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt1_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT1_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT1_TH_H_pmu_cnt1_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT1_TH_H_pmu_cnt1_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt2_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT2_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT2_TH_L_pmu_cnt2_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT2_TH_L_pmu_cnt2_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt2_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT2_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT2_TH_H_pmu_cnt2_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT2_TH_H_pmu_cnt2_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt3_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT3_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT3_TH_L_pmu_cnt3_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT3_TH_L_pmu_cnt3_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt3_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT3_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT3_TH_H_pmu_cnt3_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT3_TH_H_pmu_cnt3_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt4_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT4_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT4_TH_L_pmu_cnt4_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT4_TH_L_pmu_cnt4_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt4_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT4_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT4_TH_H_pmu_cnt4_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT4_TH_H_pmu_cnt4_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt5_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT5_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT5_TH_L_pmu_cnt5_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT5_TH_L_pmu_cnt5_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt5_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT5_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT5_TH_H_pmu_cnt5_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT5_TH_H_pmu_cnt5_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt6_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT6_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT6_TH_L_pmu_cnt6_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT6_TH_L_pmu_cnt6_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt6_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT6_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT6_TH_H_pmu_cnt6_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT6_TH_H_pmu_cnt6_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt7_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT7_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT7_TH_L_pmu_cnt7_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT7_TH_L_pmu_cnt7_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt7_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT7_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT7_TH_H_pmu_cnt7_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT7_TH_H_pmu_cnt7_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt8_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT8_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT8_TH_L_pmu_cnt8_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT8_TH_L_pmu_cnt8_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt8_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT8_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT8_TH_H_pmu_cnt8_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT8_TH_H_pmu_cnt8_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt9_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT9_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT9_TH_L_pmu_cnt9_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT9_TH_L_pmu_cnt9_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt9_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT9_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT9_TH_H_pmu_cnt9_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT9_TH_H_pmu_cnt9_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt10_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT10_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT10_TH_L_pmu_cnt10_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT10_TH_L_pmu_cnt10_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt10_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT10_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT10_TH_H_pmu_cnt10_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT10_TH_H_pmu_cnt10_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt11_th_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT11_TH_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT11_TH_L_pmu_cnt11_th_l_START (0)
#define SOC_SC_SLC_PMU_CNT11_TH_L_pmu_cnt11_th_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt11_th_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT11_TH_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT11_TH_H_pmu_cnt11_th_h_START (0)
#define SOC_SC_SLC_PMU_CNT11_TH_H_pmu_cnt11_th_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp2_lvl_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_SLC_BP2_CFG_UNION;
#endif
#define SOC_SC_SLC_BP2_CFG_bp2_lvl_sel_START (0)
#define SOC_SC_SLC_BP2_CFG_bp2_lvl_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp5_th : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_BP5_CFG_UNION;
#endif
#define SOC_SC_SLC_BP5_CFG_bp5_th_START (0)
#define SOC_SC_SLC_BP5_CFG_bp5_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp6_th : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_BP6_CFG_UNION;
#endif
#define SOC_SC_SLC_BP6_CFG_bp6_th_START (0)
#define SOC_SC_SLC_BP6_CFG_bp6_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp7_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp7_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP7_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP7_CFG_0_bp7_lat_th0_START (0)
#define SOC_SC_SLC_BP7_CFG_0_bp7_lat_th0_END (9)
#define SOC_SC_SLC_BP7_CFG_0_bp7_lat_th1_START (16)
#define SOC_SC_SLC_BP7_CFG_0_bp7_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp7_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp7_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP7_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP7_CFG_1_bp7_lat_th2_START (0)
#define SOC_SC_SLC_BP7_CFG_1_bp7_lat_th2_END (9)
#define SOC_SC_SLC_BP7_CFG_1_bp7_lat_th3_START (16)
#define SOC_SC_SLC_BP7_CFG_1_bp7_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp7_prescaler : 8;
        unsigned int bp7_cmd_type_en : 2;
        unsigned int bp7_lat_en : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_SC_SLC_BP7_CFG_2_UNION;
#endif
#define SOC_SC_SLC_BP7_CFG_2_bp7_prescaler_START (0)
#define SOC_SC_SLC_BP7_CFG_2_bp7_prescaler_END (7)
#define SOC_SC_SLC_BP7_CFG_2_bp7_cmd_type_en_START (8)
#define SOC_SC_SLC_BP7_CFG_2_bp7_cmd_type_en_END (9)
#define SOC_SC_SLC_BP7_CFG_2_bp7_lat_en_START (10)
#define SOC_SC_SLC_BP7_CFG_2_bp7_lat_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp8_gid : 4;
        unsigned int bp8_gid_msk : 4;
        unsigned int bp8_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int bp8_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int bp8_bl : 4;
        unsigned int bp8_bl_msk : 4;
    } reg;
} SOC_SC_SLC_BP8_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP8_CFG_0_bp8_gid_START (0)
#define SOC_SC_SLC_BP8_CFG_0_bp8_gid_END (3)
#define SOC_SC_SLC_BP8_CFG_0_bp8_gid_msk_START (4)
#define SOC_SC_SLC_BP8_CFG_0_bp8_gid_msk_END (7)
#define SOC_SC_SLC_BP8_CFG_0_bp8_mid_START (8)
#define SOC_SC_SLC_BP8_CFG_0_bp8_mid_END (14)
#define SOC_SC_SLC_BP8_CFG_0_bp8_mid_msk_START (16)
#define SOC_SC_SLC_BP8_CFG_0_bp8_mid_msk_END (22)
#define SOC_SC_SLC_BP8_CFG_0_bp8_bl_START (24)
#define SOC_SC_SLC_BP8_CFG_0_bp8_bl_END (27)
#define SOC_SC_SLC_BP8_CFG_0_bp8_bl_msk_START (28)
#define SOC_SC_SLC_BP8_CFG_0_bp8_bl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp8_hit_en : 1;
        unsigned int bp8_miss_en : 1;
        unsigned int bp8_vacmo : 1;
        unsigned int bp8_vacmo_msk : 1;
        unsigned int bp8_paf : 1;
        unsigned int bp8_paf_msk : 1;
        unsigned int bp8_nsaid : 3;
        unsigned int bp8_nsaid_msk : 3;
        unsigned int bp8_ptl_en : 4;
        unsigned int bp8_prescaler : 8;
        unsigned int bp8_lat_en : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_SC_SLC_BP8_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP8_CFG_1_bp8_hit_en_START (0)
#define SOC_SC_SLC_BP8_CFG_1_bp8_hit_en_END (0)
#define SOC_SC_SLC_BP8_CFG_1_bp8_miss_en_START (1)
#define SOC_SC_SLC_BP8_CFG_1_bp8_miss_en_END (1)
#define SOC_SC_SLC_BP8_CFG_1_bp8_vacmo_START (2)
#define SOC_SC_SLC_BP8_CFG_1_bp8_vacmo_END (2)
#define SOC_SC_SLC_BP8_CFG_1_bp8_vacmo_msk_START (3)
#define SOC_SC_SLC_BP8_CFG_1_bp8_vacmo_msk_END (3)
#define SOC_SC_SLC_BP8_CFG_1_bp8_paf_START (4)
#define SOC_SC_SLC_BP8_CFG_1_bp8_paf_END (4)
#define SOC_SC_SLC_BP8_CFG_1_bp8_paf_msk_START (5)
#define SOC_SC_SLC_BP8_CFG_1_bp8_paf_msk_END (5)
#define SOC_SC_SLC_BP8_CFG_1_bp8_nsaid_START (6)
#define SOC_SC_SLC_BP8_CFG_1_bp8_nsaid_END (8)
#define SOC_SC_SLC_BP8_CFG_1_bp8_nsaid_msk_START (9)
#define SOC_SC_SLC_BP8_CFG_1_bp8_nsaid_msk_END (11)
#define SOC_SC_SLC_BP8_CFG_1_bp8_ptl_en_START (12)
#define SOC_SC_SLC_BP8_CFG_1_bp8_ptl_en_END (15)
#define SOC_SC_SLC_BP8_CFG_1_bp8_prescaler_START (16)
#define SOC_SC_SLC_BP8_CFG_1_bp8_prescaler_END (23)
#define SOC_SC_SLC_BP8_CFG_1_bp8_lat_en_START (24)
#define SOC_SC_SLC_BP8_CFG_1_bp8_lat_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp8_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp8_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP8_CFG_3_UNION;
#endif
#define SOC_SC_SLC_BP8_CFG_3_bp8_lat_th0_START (0)
#define SOC_SC_SLC_BP8_CFG_3_bp8_lat_th0_END (9)
#define SOC_SC_SLC_BP8_CFG_3_bp8_lat_th1_START (16)
#define SOC_SC_SLC_BP8_CFG_3_bp8_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp8_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp8_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP8_CFG_4_UNION;
#endif
#define SOC_SC_SLC_BP8_CFG_4_bp8_lat_th2_START (0)
#define SOC_SC_SLC_BP8_CFG_4_bp8_lat_th2_END (9)
#define SOC_SC_SLC_BP8_CFG_4_bp8_lat_th3_START (16)
#define SOC_SC_SLC_BP8_CFG_4_bp8_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp9_num_th0 : 8;
        unsigned int bp9_num_th1 : 8;
        unsigned int bp9_num_th2 : 8;
        unsigned int bp9_num_th3 : 8;
    } reg;
} SOC_SC_SLC_BP9_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th0_START (0)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th0_END (7)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th1_START (8)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th1_END (15)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th2_START (16)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th2_END (23)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th3_START (24)
#define SOC_SC_SLC_BP9_CFG_0_bp9_num_th3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp10_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp10_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP10_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP10_CFG_0_bp10_lat_th0_START (0)
#define SOC_SC_SLC_BP10_CFG_0_bp10_lat_th0_END (9)
#define SOC_SC_SLC_BP10_CFG_0_bp10_lat_th1_START (16)
#define SOC_SC_SLC_BP10_CFG_0_bp10_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp10_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp10_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP10_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP10_CFG_1_bp10_lat_th2_START (0)
#define SOC_SC_SLC_BP10_CFG_1_bp10_lat_th2_END (9)
#define SOC_SC_SLC_BP10_CFG_1_bp10_lat_th3_START (16)
#define SOC_SC_SLC_BP10_CFG_1_bp10_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp10_prescaler : 8;
        unsigned int bp10_cmd_type_en : 2;
        unsigned int bp10_lat_en : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_SC_SLC_BP10_CFG_2_UNION;
#endif
#define SOC_SC_SLC_BP10_CFG_2_bp10_prescaler_START (0)
#define SOC_SC_SLC_BP10_CFG_2_bp10_prescaler_END (7)
#define SOC_SC_SLC_BP10_CFG_2_bp10_cmd_type_en_START (8)
#define SOC_SC_SLC_BP10_CFG_2_bp10_cmd_type_en_END (9)
#define SOC_SC_SLC_BP10_CFG_2_bp10_lat_en_START (10)
#define SOC_SC_SLC_BP10_CFG_2_bp10_lat_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp11_num_th0 : 8;
        unsigned int bp11_num_th1 : 8;
        unsigned int bp11_num_th2 : 8;
        unsigned int bp11_num_th3 : 8;
    } reg;
} SOC_SC_SLC_BP11_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th0_START (0)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th0_END (7)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th1_START (8)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th1_END (15)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th2_START (16)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th2_END (23)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th3_START (24)
#define SOC_SC_SLC_BP11_CFG_0_bp11_num_th3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp12_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp12_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP12_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP12_CFG_0_bp12_lat_th0_START (0)
#define SOC_SC_SLC_BP12_CFG_0_bp12_lat_th0_END (9)
#define SOC_SC_SLC_BP12_CFG_0_bp12_lat_th1_START (16)
#define SOC_SC_SLC_BP12_CFG_0_bp12_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp12_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int bp12_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_BP12_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP12_CFG_1_bp12_lat_th2_START (0)
#define SOC_SC_SLC_BP12_CFG_1_bp12_lat_th2_END (9)
#define SOC_SC_SLC_BP12_CFG_1_bp12_lat_th3_START (16)
#define SOC_SC_SLC_BP12_CFG_1_bp12_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp12_prescaler : 8;
        unsigned int bp12_lat_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_SC_SLC_BP12_CFG_2_UNION;
#endif
#define SOC_SC_SLC_BP12_CFG_2_bp12_prescaler_START (0)
#define SOC_SC_SLC_BP12_CFG_2_bp12_prescaler_END (7)
#define SOC_SC_SLC_BP12_CFG_2_bp12_lat_en_START (8)
#define SOC_SC_SLC_BP12_CFG_2_bp12_lat_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp14a_gid : 4;
        unsigned int bp14a_gid_msk : 4;
        unsigned int bp14a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int bp14a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int bp14a_ca_rgn_hit : 1;
        unsigned int bp14a_ca_rgn_hit_msk : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SC_SLC_BP14A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_gid_START (0)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_gid_END (3)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_gid_msk_START (4)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_gid_msk_END (7)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_mid_START (8)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_mid_END (14)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_mid_msk_START (16)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_mid_msk_END (22)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_ca_rgn_hit_START (24)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_ca_rgn_hit_END (24)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_ca_rgn_hit_msk_START (25)
#define SOC_SC_SLC_BP14A_CFG_0_bp14a_ca_rgn_hit_msk_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp14a_op_en : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SC_SLC_BP14A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP14A_CFG_1_bp14a_op_en_START (0)
#define SOC_SC_SLC_BP14A_CFG_1_bp14a_op_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp14b_gid : 4;
        unsigned int bp14b_gid_msk : 4;
        unsigned int bp14b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int bp14b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int bp14b_ca_rgn_hit : 1;
        unsigned int bp14b_ca_rgn_hit_msk : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SC_SLC_BP14B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_gid_START (0)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_gid_END (3)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_gid_msk_START (4)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_gid_msk_END (7)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_mid_START (8)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_mid_END (14)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_mid_msk_START (16)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_mid_msk_END (22)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_ca_rgn_hit_START (24)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_ca_rgn_hit_END (24)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_ca_rgn_hit_msk_START (25)
#define SOC_SC_SLC_BP14B_CFG_0_bp14b_ca_rgn_hit_msk_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp14b_op_en : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SC_SLC_BP14B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_BP14B_CFG_1_bp14b_op_en_START (0)
#define SOC_SC_SLC_BP14B_CFG_1_bp14b_op_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp15_gid : 4;
        unsigned int bp15_gid_msk : 4;
        unsigned int bp15_op_en : 6;
        unsigned int reserved : 18;
    } reg;
} SOC_SC_SLC_BP15_CFG_0_UNION;
#endif
#define SOC_SC_SLC_BP15_CFG_0_bp15_gid_START (0)
#define SOC_SC_SLC_BP15_CFG_0_bp15_gid_END (3)
#define SOC_SC_SLC_BP15_CFG_0_bp15_gid_msk_START (4)
#define SOC_SC_SLC_BP15_CFG_0_bp15_gid_msk_END (7)
#define SOC_SC_SLC_BP15_CFG_0_bp15_op_en_START (8)
#define SOC_SC_SLC_BP15_CFG_0_bp15_op_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp0_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int tcp0_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_TCP0_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP0_CFG_0_tcp0_lat_th0_START (0)
#define SOC_SC_SLC_TCP0_CFG_0_tcp0_lat_th0_END (9)
#define SOC_SC_SLC_TCP0_CFG_0_tcp0_lat_th1_START (16)
#define SOC_SC_SLC_TCP0_CFG_0_tcp0_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp0_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int tcp0_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_TCP0_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP0_CFG_1_tcp0_lat_th2_START (0)
#define SOC_SC_SLC_TCP0_CFG_1_tcp0_lat_th2_END (9)
#define SOC_SC_SLC_TCP0_CFG_1_tcp0_lat_th3_START (16)
#define SOC_SC_SLC_TCP0_CFG_1_tcp0_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp0_prescaler : 8;
        unsigned int tcp0_op_en : 3;
        unsigned int tcp0_lat_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SLC_TCP0_CFG_2_UNION;
#endif
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_prescaler_START (0)
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_prescaler_END (7)
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_op_en_START (8)
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_op_en_END (10)
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_lat_en_START (11)
#define SOC_SC_SLC_TCP0_CFG_2_tcp0_lat_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp1_lat_th0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int tcp1_lat_th1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_TCP1_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP1_CFG_0_tcp1_lat_th0_START (0)
#define SOC_SC_SLC_TCP1_CFG_0_tcp1_lat_th0_END (9)
#define SOC_SC_SLC_TCP1_CFG_0_tcp1_lat_th1_START (16)
#define SOC_SC_SLC_TCP1_CFG_0_tcp1_lat_th1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp1_lat_th2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int tcp1_lat_th3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_SLC_TCP1_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP1_CFG_1_tcp1_lat_th2_START (0)
#define SOC_SC_SLC_TCP1_CFG_1_tcp1_lat_th2_END (9)
#define SOC_SC_SLC_TCP1_CFG_1_tcp1_lat_th3_START (16)
#define SOC_SC_SLC_TCP1_CFG_1_tcp1_lat_th3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp1_prescaler : 8;
        unsigned int tcp1_lat_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_SC_SLC_TCP1_CFG_2_UNION;
#endif
#define SOC_SC_SLC_TCP1_CFG_2_tcp1_prescaler_START (0)
#define SOC_SC_SLC_TCP1_CFG_2_tcp1_prescaler_END (7)
#define SOC_SC_SLC_TCP1_CFG_2_tcp1_lat_en_START (8)
#define SOC_SC_SLC_TCP1_CFG_2_tcp1_lat_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp2a_gid : 4;
        unsigned int tcp2a_gid_msk : 4;
        unsigned int tcp2a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp2a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp2a_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp2a_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP2A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_gid_START (0)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_gid_END (3)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_gid_msk_START (4)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_gid_msk_END (7)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_mid_START (8)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_mid_END (14)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_mid_msk_START (16)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_mid_msk_END (22)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_nsaid_START (24)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_nsaid_END (26)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP2A_CFG_0_tcp2a_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp2a_paf : 1;
        unsigned int tcp2a_paf_msk : 1;
        unsigned int tcp2a_cmd_type_en : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_SLC_TCP2A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_paf_START (0)
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_paf_END (0)
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_paf_msk_START (1)
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_paf_msk_END (1)
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP2A_CFG_1_tcp2a_cmd_type_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp2b_gid : 4;
        unsigned int tcp2b_gid_msk : 4;
        unsigned int tcp2b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp2b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp2b_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp2b_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP2B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_gid_START (0)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_gid_END (3)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_gid_msk_START (4)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_gid_msk_END (7)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_mid_START (8)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_mid_END (14)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_mid_msk_START (16)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_mid_msk_END (22)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_nsaid_START (24)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_nsaid_END (26)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP2B_CFG_0_tcp2b_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp2b_paf : 1;
        unsigned int tcp2b_paf_msk : 1;
        unsigned int tcp2b_cmd_type_en : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_SLC_TCP2B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_paf_START (0)
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_paf_END (0)
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_paf_msk_START (1)
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_paf_msk_END (1)
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP2B_CFG_1_tcp2b_cmd_type_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp3a_gid : 4;
        unsigned int tcp3a_gid_msk : 4;
        unsigned int tcp3a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp3a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp3a_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp3a_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP3A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_gid_START (0)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_gid_END (3)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_gid_msk_START (4)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_gid_msk_END (7)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_mid_START (8)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_mid_END (14)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_mid_msk_START (16)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_mid_msk_END (22)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_nsaid_START (24)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_nsaid_END (26)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP3A_CFG_0_tcp3a_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp3a_paf : 1;
        unsigned int tcp3a_paf_msk : 1;
        unsigned int tcp3a_cmd_type_en : 2;
        unsigned int tcp3a_ptl_en : 4;
        unsigned int tcp3a_bl : 4;
        unsigned int tcp3a_bl_msk : 4;
        unsigned int tcp3a_vacmo : 1;
        unsigned int tcp3a_vacmo_msk : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_TCP3A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_paf_START (0)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_paf_END (0)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_paf_msk_START (1)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_paf_msk_END (1)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_ptl_en_START (4)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_ptl_en_END (7)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_bl_START (8)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_bl_END (11)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_bl_msk_START (12)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_bl_msk_END (15)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_vacmo_START (16)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_vacmo_END (16)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP3A_CFG_1_tcp3a_vacmo_msk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp3b_gid : 4;
        unsigned int tcp3b_gid_msk : 4;
        unsigned int tcp3b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp3b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp3b_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp3b_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP3B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_gid_START (0)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_gid_END (3)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_gid_msk_START (4)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_gid_msk_END (7)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_mid_START (8)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_mid_END (14)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_mid_msk_START (16)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_mid_msk_END (22)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_nsaid_START (24)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_nsaid_END (26)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP3B_CFG_0_tcp3b_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp3b_paf : 1;
        unsigned int tcp3b_paf_msk : 1;
        unsigned int tcp3b_cmd_type_en : 2;
        unsigned int tcp3b_ptl_en : 4;
        unsigned int tcp3b_bl : 4;
        unsigned int tcp3b_bl_msk : 4;
        unsigned int tcp3b_vacmo : 1;
        unsigned int tcp3b_vacmo_msk : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_TCP3B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_paf_START (0)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_paf_END (0)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_paf_msk_START (1)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_paf_msk_END (1)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_ptl_en_START (4)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_ptl_en_END (7)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_bl_START (8)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_bl_END (11)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_bl_msk_START (12)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_bl_msk_END (15)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_vacmo_START (16)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_vacmo_END (16)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP3B_CFG_1_tcp3b_vacmo_msk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp4_optype : 3;
        unsigned int tcp4_optype_msk : 3;
        unsigned int tcp4_cmotype : 2;
        unsigned int tcp4_cmotype_msk : 2;
        unsigned int tcp4_sync_cmd : 1;
        unsigned int tcp4_sync_cmd_msk : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SLC_TCP4_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_optype_START (0)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_optype_END (2)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_optype_msk_START (3)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_optype_msk_END (5)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_cmotype_START (6)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_cmotype_END (7)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_cmotype_msk_START (8)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_cmotype_msk_END (9)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_sync_cmd_START (10)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_sync_cmd_END (10)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_sync_cmd_msk_START (11)
#define SOC_SC_SLC_TCP4_CFG_0_tcp4_sync_cmd_msk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp5_gid : 4;
        unsigned int tcp5_gid_msk : 4;
        unsigned int tcp5_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp5_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp5_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp5_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP5_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_gid_START (0)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_gid_END (3)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_gid_msk_START (4)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_gid_msk_END (7)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_mid_START (8)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_mid_END (14)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_mid_msk_START (16)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_mid_msk_END (22)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_nsaid_START (24)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_nsaid_END (26)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP5_CFG_0_tcp5_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp5_paf : 1;
        unsigned int tcp5_paf_msk : 1;
        unsigned int tcp5_cmd_type_en : 2;
        unsigned int tcp5_ptl_en : 4;
        unsigned int tcp5_bl : 4;
        unsigned int tcp5_bl_msk : 4;
        unsigned int tcp5_vacmo : 1;
        unsigned int tcp5_vacmo_msk : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_TCP5_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_paf_START (0)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_paf_END (0)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_paf_msk_START (1)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_paf_msk_END (1)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_ptl_en_START (4)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_ptl_en_END (7)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_bl_START (8)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_bl_END (11)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_bl_msk_START (12)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_bl_msk_END (15)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_vacmo_START (16)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_vacmo_END (16)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP5_CFG_1_tcp5_vacmo_msk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp6a_gid : 4;
        unsigned int tcp6a_gid_msk : 4;
        unsigned int tcp6a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp6a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp6a_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp6a_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP6A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_gid_START (0)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_gid_END (3)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_gid_msk_START (4)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_gid_msk_END (7)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_mid_START (8)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_mid_END (14)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_mid_msk_START (16)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_mid_msk_END (22)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_nsaid_START (24)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_nsaid_END (26)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP6A_CFG_0_tcp6a_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp6a_paf : 1;
        unsigned int tcp6a_paf_msk : 1;
        unsigned int tcp6a_cmd_type_en : 2;
        unsigned int tcp6a_ptl_en : 4;
        unsigned int tcp6a_bl : 4;
        unsigned int tcp6a_bl_msk : 4;
        unsigned int tcp6a_vacmo : 1;
        unsigned int tcp6a_vacmo_msk : 1;
        unsigned int tcp6a_misstype_en : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_SC_SLC_TCP6A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_paf_START (0)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_paf_END (0)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_paf_msk_START (1)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_paf_msk_END (1)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_ptl_en_START (4)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_ptl_en_END (7)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_bl_START (8)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_bl_END (11)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_bl_msk_START (12)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_bl_msk_END (15)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_vacmo_START (16)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_vacmo_END (16)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_vacmo_msk_END (17)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_misstype_en_START (18)
#define SOC_SC_SLC_TCP6A_CFG_1_tcp6a_misstype_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp6b_gid : 4;
        unsigned int tcp6b_gid_msk : 4;
        unsigned int tcp6b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp6b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp6b_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp6b_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP6B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_gid_START (0)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_gid_END (3)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_gid_msk_START (4)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_gid_msk_END (7)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_mid_START (8)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_mid_END (14)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_mid_msk_START (16)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_mid_msk_END (22)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_nsaid_START (24)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_nsaid_END (26)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP6B_CFG_0_tcp6b_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp6b_paf : 1;
        unsigned int tcp6b_paf_msk : 1;
        unsigned int tcp6b_cmd_type_en : 2;
        unsigned int tcp6b_ptl_en : 4;
        unsigned int tcp6b_bl : 4;
        unsigned int tcp6b_bl_msk : 4;
        unsigned int tcp6b_vacmo : 1;
        unsigned int tcp6b_vacmo_msk : 1;
        unsigned int tcp6b_misstype_en : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_SC_SLC_TCP6B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_paf_START (0)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_paf_END (0)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_paf_msk_START (1)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_paf_msk_END (1)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_ptl_en_START (4)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_ptl_en_END (7)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_bl_START (8)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_bl_END (11)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_bl_msk_START (12)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_bl_msk_END (15)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_vacmo_START (16)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_vacmo_END (16)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_vacmo_msk_END (17)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_misstype_en_START (18)
#define SOC_SC_SLC_TCP6B_CFG_1_tcp6b_misstype_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp7a_gid : 4;
        unsigned int tcp7a_gid_msk : 4;
        unsigned int tcp7a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp7a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp7a_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp7a_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP7A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_gid_START (0)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_gid_END (3)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_gid_msk_START (4)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_gid_msk_END (7)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_mid_START (8)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_mid_END (14)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_mid_msk_START (16)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_mid_msk_END (22)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_nsaid_START (24)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_nsaid_END (26)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP7A_CFG_0_tcp7a_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp7a_paf : 1;
        unsigned int tcp7a_paf_msk : 1;
        unsigned int tcp7a_cmd_type_en : 2;
        unsigned int tcp7a_ptl_en : 4;
        unsigned int tcp7a_bl : 4;
        unsigned int tcp7a_bl_msk : 4;
        unsigned int tcp7a_vacmo : 1;
        unsigned int tcp7a_vacmo_msk : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_TCP7A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_paf_START (0)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_paf_END (0)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_paf_msk_START (1)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_paf_msk_END (1)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_ptl_en_START (4)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_ptl_en_END (7)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_bl_START (8)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_bl_END (11)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_bl_msk_START (12)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_bl_msk_END (15)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_vacmo_START (16)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_vacmo_END (16)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP7A_CFG_1_tcp7a_vacmo_msk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp7b_gid : 4;
        unsigned int tcp7b_gid_msk : 4;
        unsigned int tcp7b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp7b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp7b_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp7b_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP7B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_gid_START (0)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_gid_END (3)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_gid_msk_START (4)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_gid_msk_END (7)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_mid_START (8)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_mid_END (14)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_mid_msk_START (16)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_mid_msk_END (22)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_nsaid_START (24)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_nsaid_END (26)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP7B_CFG_0_tcp7b_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp7b_paf : 1;
        unsigned int tcp7b_paf_msk : 1;
        unsigned int tcp7b_cmd_type_en : 2;
        unsigned int tcp7b_ptl_en : 4;
        unsigned int tcp7b_bl : 4;
        unsigned int tcp7b_bl_msk : 4;
        unsigned int tcp7b_vacmo : 1;
        unsigned int tcp7b_vacmo_msk : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_TCP7B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_paf_START (0)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_paf_END (0)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_paf_msk_START (1)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_paf_msk_END (1)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_ptl_en_START (4)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_ptl_en_END (7)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_bl_START (8)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_bl_END (11)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_bl_msk_START (12)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_bl_msk_END (15)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_vacmo_START (16)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_vacmo_END (16)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP7B_CFG_1_tcp7b_vacmo_msk_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp8a_gid : 4;
        unsigned int tcp8a_gid_msk : 4;
        unsigned int tcp8a_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp8a_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp8a_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp8a_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP8A_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_gid_START (0)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_gid_END (3)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_gid_msk_START (4)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_gid_msk_END (7)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_mid_START (8)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_mid_END (14)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_mid_msk_START (16)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_mid_msk_END (22)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_nsaid_START (24)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_nsaid_END (26)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP8A_CFG_0_tcp8a_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp8a_paf : 1;
        unsigned int tcp8a_paf_msk : 1;
        unsigned int tcp8a_cmd_type_en : 2;
        unsigned int tcp8a_ptl_en : 4;
        unsigned int tcp8a_bl : 4;
        unsigned int tcp8a_bl_msk : 4;
        unsigned int tcp8a_vacmo : 1;
        unsigned int tcp8a_vacmo_msk : 1;
        unsigned int tcp8a_rplc_gid : 4;
        unsigned int tcp8a_rplc_gid_msk : 4;
        unsigned int tcp8a_gid_mode : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_SC_SLC_TCP8A_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_paf_START (0)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_paf_END (0)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_paf_msk_START (1)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_paf_msk_END (1)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_ptl_en_START (4)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_ptl_en_END (7)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_bl_START (8)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_bl_END (11)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_bl_msk_START (12)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_bl_msk_END (15)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_vacmo_START (16)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_vacmo_END (16)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_vacmo_msk_END (17)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_rplc_gid_START (18)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_rplc_gid_END (21)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_rplc_gid_msk_START (22)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_rplc_gid_msk_END (25)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_gid_mode_START (26)
#define SOC_SC_SLC_TCP8A_CFG_1_tcp8a_gid_mode_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp8b_gid : 4;
        unsigned int tcp8b_gid_msk : 4;
        unsigned int tcp8b_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp8b_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp8b_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp8b_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP8B_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_gid_START (0)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_gid_END (3)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_gid_msk_START (4)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_gid_msk_END (7)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_mid_START (8)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_mid_END (14)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_mid_msk_START (16)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_mid_msk_END (22)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_nsaid_START (24)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_nsaid_END (26)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP8B_CFG_0_tcp8b_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp8b_paf : 1;
        unsigned int tcp8b_paf_msk : 1;
        unsigned int tcp8b_cmd_type_en : 2;
        unsigned int tcp8b_ptl_en : 4;
        unsigned int tcp8b_bl : 4;
        unsigned int tcp8b_bl_msk : 4;
        unsigned int tcp8b_vacmo : 1;
        unsigned int tcp8b_vacmo_msk : 1;
        unsigned int tcp8b_rplc_gid : 4;
        unsigned int tcp8b_rplc_gid_msk : 4;
        unsigned int tcp8b_gid_mode : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_SC_SLC_TCP8B_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_paf_START (0)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_paf_END (0)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_paf_msk_START (1)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_paf_msk_END (1)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_ptl_en_START (4)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_ptl_en_END (7)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_bl_START (8)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_bl_END (11)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_bl_msk_START (12)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_bl_msk_END (15)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_vacmo_START (16)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_vacmo_END (16)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_vacmo_msk_END (17)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_rplc_gid_START (18)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_rplc_gid_END (21)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_rplc_gid_msk_START (22)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_rplc_gid_msk_END (25)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_gid_mode_START (26)
#define SOC_SC_SLC_TCP8B_CFG_1_tcp8b_gid_mode_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp9_gid : 4;
        unsigned int tcp9_gid_msk : 4;
        unsigned int tcp9_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int tcp9_mid_msk : 7;
        unsigned int reserved_1 : 1;
        unsigned int tcp9_nsaid : 3;
        unsigned int reserved_2 : 1;
        unsigned int tcp9_nsaid_msk : 3;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_SLC_TCP9_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_gid_START (0)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_gid_END (3)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_gid_msk_START (4)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_gid_msk_END (7)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_mid_START (8)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_mid_END (14)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_mid_msk_START (16)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_mid_msk_END (22)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_nsaid_START (24)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_nsaid_END (26)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_nsaid_msk_START (28)
#define SOC_SC_SLC_TCP9_CFG_0_tcp9_nsaid_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp9_paf : 1;
        unsigned int tcp9_paf_msk : 1;
        unsigned int tcp9_cmd_type_en : 2;
        unsigned int tcp9_ptl_en : 4;
        unsigned int tcp9_bl : 4;
        unsigned int tcp9_bl_msk : 4;
        unsigned int tcp9_vacmo : 1;
        unsigned int tcp9_vacmo_msk : 1;
        unsigned int tcp9_quota_exhaust_en : 1;
        unsigned int tcp9_pri_noreach_en : 1;
        unsigned int tcp9_quota_disable_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_SC_SLC_TCP9_CFG_1_UNION;
#endif
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_paf_START (0)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_paf_END (0)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_paf_msk_START (1)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_paf_msk_END (1)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_cmd_type_en_START (2)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_cmd_type_en_END (3)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_ptl_en_START (4)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_ptl_en_END (7)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_bl_START (8)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_bl_END (11)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_bl_msk_START (12)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_bl_msk_END (15)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_vacmo_START (16)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_vacmo_END (16)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_vacmo_msk_START (17)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_vacmo_msk_END (17)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_quota_exhaust_en_START (18)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_quota_exhaust_en_END (18)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_pri_noreach_en_START (19)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_pri_noreach_en_END (19)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_quota_disable_en_START (20)
#define SOC_SC_SLC_TCP9_CFG_1_tcp9_quota_disable_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcp10_cmd_type_en : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_SLC_TCP10_CFG_0_UNION;
#endif
#define SOC_SC_SLC_TCP10_CFG_0_tcp10_cmd_type_en_START (0)
#define SOC_SC_SLC_TCP10_CFG_0_tcp10_cmd_type_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcp03_cmd_type_en : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_SLC_DCP03_CFG_0_UNION;
#endif
#define SOC_SC_SLC_DCP03_CFG_0_dcp03_cmd_type_en_START (0)
#define SOC_SC_SLC_DCP03_CFG_0_dcp03_cmd_type_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcp6_iwdb_th : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_DCP6_CFG_0_UNION;
#endif
#define SOC_SC_SLC_DCP6_CFG_0_dcp6_iwdb_th_START (0)
#define SOC_SC_SLC_DCP6_CFG_0_dcp6_iwdb_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcp7_fdb_alc_th : 8;
        unsigned int dcp7_fdb_slv_th : 8;
        unsigned int dcp7_sel : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SC_SLC_DCP7_CFG_0_UNION;
#endif
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_fdb_alc_th_START (0)
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_fdb_alc_th_END (7)
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_fdb_slv_th_START (8)
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_fdb_slv_th_END (15)
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_sel_START (16)
#define SOC_SC_SLC_DCP7_CFG_0_dcp7_sel_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcp8_ewdb_th : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_DCP8_CFG_0_UNION;
#endif
#define SOC_SC_SLC_DCP8_CFG_0_dcp8_ewdb_th_START (0)
#define SOC_SC_SLC_DCP8_CFG_0_dcp8_ewdb_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcp9_cmd_type_en : 2;
        unsigned int dcp9_conflit_type_en : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_SLC_DCP9_CFG_0_UNION;
#endif
#define SOC_SC_SLC_DCP9_CFG_0_dcp9_cmd_type_en_START (0)
#define SOC_SC_SLC_DCP9_CFG_0_dcp9_cmd_type_en_END (1)
#define SOC_SC_SLC_DCP9_CFG_0_dcp9_conflit_type_en_START (2)
#define SOC_SC_SLC_DCP9_CFG_0_dcp9_conflit_type_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmp0_lp_mode : 2;
        unsigned int pmp1_lp_mode : 2;
        unsigned int pmp2_lp_mode : 2;
        unsigned int pmp3_lp_mode : 2;
        unsigned int pmp4_lp_mode : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_SC_SLC_PMP_CFG_0_UNION;
#endif
#define SOC_SC_SLC_PMP_CFG_0_pmp0_lp_mode_START (0)
#define SOC_SC_SLC_PMP_CFG_0_pmp0_lp_mode_END (1)
#define SOC_SC_SLC_PMP_CFG_0_pmp1_lp_mode_START (2)
#define SOC_SC_SLC_PMP_CFG_0_pmp1_lp_mode_END (3)
#define SOC_SC_SLC_PMP_CFG_0_pmp2_lp_mode_START (4)
#define SOC_SC_SLC_PMP_CFG_0_pmp2_lp_mode_END (5)
#define SOC_SC_SLC_PMP_CFG_0_pmp3_lp_mode_START (6)
#define SOC_SC_SLC_PMP_CFG_0_pmp3_lp_mode_END (7)
#define SOC_SC_SLC_PMP_CFG_0_pmp4_lp_mode_START (8)
#define SOC_SC_SLC_PMP_CFG_0_pmp4_lp_mode_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt0_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT0_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT0_L_pmu_cm_cnt0_l_START (0)
#define SOC_SC_SLC_PMU_CNT0_L_pmu_cm_cnt0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt0_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT0_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT0_H_pmu_cm_cnt0_h_START (0)
#define SOC_SC_SLC_PMU_CNT0_H_pmu_cm_cnt0_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt1_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT1_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT1_L_pmu_cm_cnt1_l_START (0)
#define SOC_SC_SLC_PMU_CNT1_L_pmu_cm_cnt1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt1_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT1_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT1_H_pmu_cm_cnt1_h_START (0)
#define SOC_SC_SLC_PMU_CNT1_H_pmu_cm_cnt1_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt2_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT2_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT2_L_pmu_cm_cnt2_l_START (0)
#define SOC_SC_SLC_PMU_CNT2_L_pmu_cm_cnt2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt2_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT2_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT2_H_pmu_cm_cnt2_h_START (0)
#define SOC_SC_SLC_PMU_CNT2_H_pmu_cm_cnt2_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt3_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT3_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT3_L_pmu_cm_cnt3_l_START (0)
#define SOC_SC_SLC_PMU_CNT3_L_pmu_cm_cnt3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt3_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT3_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT3_H_pmu_cm_cnt3_h_START (0)
#define SOC_SC_SLC_PMU_CNT3_H_pmu_cm_cnt3_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt4_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT4_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT4_L_pmu_cm_cnt4_l_START (0)
#define SOC_SC_SLC_PMU_CNT4_L_pmu_cm_cnt4_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt4_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT4_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT4_H_pmu_cm_cnt4_h_START (0)
#define SOC_SC_SLC_PMU_CNT4_H_pmu_cm_cnt4_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt5_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT5_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT5_L_pmu_cm_cnt5_l_START (0)
#define SOC_SC_SLC_PMU_CNT5_L_pmu_cm_cnt5_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt5_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT5_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT5_H_pmu_cm_cnt5_h_START (0)
#define SOC_SC_SLC_PMU_CNT5_H_pmu_cm_cnt5_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt6_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT6_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT6_L_pmu_cm_cnt6_l_START (0)
#define SOC_SC_SLC_PMU_CNT6_L_pmu_cm_cnt6_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt6_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT6_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT6_H_pmu_cm_cnt6_h_START (0)
#define SOC_SC_SLC_PMU_CNT6_H_pmu_cm_cnt6_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt7_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT7_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT7_L_pmu_cm_cnt7_l_START (0)
#define SOC_SC_SLC_PMU_CNT7_L_pmu_cm_cnt7_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt7_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT7_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT7_H_pmu_cm_cnt7_h_START (0)
#define SOC_SC_SLC_PMU_CNT7_H_pmu_cm_cnt7_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt8_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT8_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT8_L_pmu_cm_cnt8_l_START (0)
#define SOC_SC_SLC_PMU_CNT8_L_pmu_cm_cnt8_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt8_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT8_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT8_H_pmu_cm_cnt8_h_START (0)
#define SOC_SC_SLC_PMU_CNT8_H_pmu_cm_cnt8_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt9_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT9_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT9_L_pmu_cm_cnt9_l_START (0)
#define SOC_SC_SLC_PMU_CNT9_L_pmu_cm_cnt9_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt9_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT9_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT9_H_pmu_cm_cnt9_h_START (0)
#define SOC_SC_SLC_PMU_CNT9_H_pmu_cm_cnt9_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt10_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT10_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT10_L_pmu_cm_cnt10_l_START (0)
#define SOC_SC_SLC_PMU_CNT10_L_pmu_cm_cnt10_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt10_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT10_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT10_H_pmu_cm_cnt10_h_START (0)
#define SOC_SC_SLC_PMU_CNT10_H_pmu_cm_cnt10_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt11_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT11_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT11_L_pmu_cm_cnt11_l_START (0)
#define SOC_SC_SLC_PMU_CNT11_L_pmu_cm_cnt11_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt11_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT11_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT11_H_pmu_cm_cnt11_h_START (0)
#define SOC_SC_SLC_PMU_CNT11_H_pmu_cm_cnt11_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt12_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT12_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT12_L_pmu_cm_cnt12_l_START (0)
#define SOC_SC_SLC_PMU_CNT12_L_pmu_cm_cnt12_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt12_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT12_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT12_H_pmu_cm_cnt12_h_START (0)
#define SOC_SC_SLC_PMU_CNT12_H_pmu_cm_cnt12_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt13_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT13_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT13_L_pmu_cm_cnt13_l_START (0)
#define SOC_SC_SLC_PMU_CNT13_L_pmu_cm_cnt13_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt13_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT13_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT13_H_pmu_cm_cnt13_h_START (0)
#define SOC_SC_SLC_PMU_CNT13_H_pmu_cm_cnt13_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt14_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT14_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT14_L_pmu_cm_cnt14_l_START (0)
#define SOC_SC_SLC_PMU_CNT14_L_pmu_cm_cnt14_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt14_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT14_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT14_H_pmu_cm_cnt14_h_START (0)
#define SOC_SC_SLC_PMU_CNT14_H_pmu_cm_cnt14_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt15_l : 32;
    } reg;
} SOC_SC_SLC_PMU_CNT15_L_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT15_L_pmu_cm_cnt15_l_START (0)
#define SOC_SC_SLC_PMU_CNT15_L_pmu_cm_cnt15_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cm_cnt15_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_CNT15_H_UNION;
#endif
#define SOC_SC_SLC_PMU_CNT15_H_pmu_cm_cnt15_h_START (0)
#define SOC_SC_SLC_PMU_CNT15_H_pmu_cm_cnt15_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_stat_cycle_l : 32;
    } reg;
} SOC_SC_SLC_PMU_STAT_CYCLE_L_UNION;
#endif
#define SOC_SC_SLC_PMU_STAT_CYCLE_L_pmu_stat_cycle_l_START (0)
#define SOC_SC_SLC_PMU_STAT_CYCLE_L_pmu_stat_cycle_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_stat_cycle_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_STAT_CYCLE_H_UNION;
#endif
#define SOC_SC_SLC_PMU_STAT_CYCLE_H_pmu_stat_cycle_h_START (0)
#define SOC_SC_SLC_PMU_STAT_CYCLE_H_pmu_stat_cycle_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_stat_busy_l : 32;
    } reg;
} SOC_SC_SLC_PMU_STAT_BUSY_L_UNION;
#endif
#define SOC_SC_SLC_PMU_STAT_BUSY_L_pmu_stat_busy_l_START (0)
#define SOC_SC_SLC_PMU_STAT_BUSY_L_pmu_stat_busy_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_stat_busy_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_PMU_STAT_BUSY_H_UNION;
#endif
#define SOC_SC_SLC_PMU_STAT_BUSY_H_pmu_stat_busy_h_START (0)
#define SOC_SC_SLC_PMU_STAT_BUSY_H_pmu_stat_busy_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int way_pwrup_stat : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SLC_WAY_PWRUP_STAT_UNION;
#endif
#define SOC_SC_SLC_WAY_PWRUP_STAT_way_pwrup_stat_START (0)
#define SOC_SC_SLC_WAY_PWRUP_STAT_way_pwrup_stat_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_cnt : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_SC_SLC_GID_COUNT_UNION;
#endif
#define SOC_SC_SLC_GID_COUNT_gid_cnt_START (0)
#define SOC_SC_SLC_GID_COUNT_gid_cnt_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_st : 1;
        unsigned int pmu_cnt1_st : 1;
        unsigned int pmu_cnt2_st : 1;
        unsigned int pmu_cnt3_st : 1;
        unsigned int pmu_cnt4_st : 1;
        unsigned int pmu_cnt5_st : 1;
        unsigned int pmu_cnt6_st : 1;
        unsigned int pmu_cnt7_st : 1;
        unsigned int pmu_cnt8_st : 1;
        unsigned int pmu_cnt9_st : 1;
        unsigned int pmu_cnt10_st : 1;
        unsigned int pmu_cnt11_st : 1;
        unsigned int eccerr_st : 1;
        unsigned int dfx_gid_illegal_st : 1;
        unsigned int dfx_gid_mismatch_st : 1;
        unsigned int dfx_pri_noalloc_st : 1;
        unsigned int dfx_multihit_st : 1;
        unsigned int dfx_cmd_lpway_st : 1;
        unsigned int dfx_cmo_lpway_st : 1;
        unsigned int dfx_cmo_sec_st : 1;
        unsigned int dfx_cmogid_illegal_st : 1;
        unsigned int dfx_slv_wrap_write_st : 1;
        unsigned int dfx_slv_cross_align_st : 1;
        unsigned int dfx_slv_vacmo_err_st : 1;
        unsigned int dfx_slv_wd_mismatch_st : 1;
        unsigned int dfx_abnormal_dummy_st : 7;
    } reg;
} SOC_SC_SLC02_INT_ST_UNION;
#endif
#define SOC_SC_SLC02_INT_ST_pmu_cnt0_st_START (0)
#define SOC_SC_SLC02_INT_ST_pmu_cnt0_st_END (0)
#define SOC_SC_SLC02_INT_ST_pmu_cnt1_st_START (1)
#define SOC_SC_SLC02_INT_ST_pmu_cnt1_st_END (1)
#define SOC_SC_SLC02_INT_ST_pmu_cnt2_st_START (2)
#define SOC_SC_SLC02_INT_ST_pmu_cnt2_st_END (2)
#define SOC_SC_SLC02_INT_ST_pmu_cnt3_st_START (3)
#define SOC_SC_SLC02_INT_ST_pmu_cnt3_st_END (3)
#define SOC_SC_SLC02_INT_ST_pmu_cnt4_st_START (4)
#define SOC_SC_SLC02_INT_ST_pmu_cnt4_st_END (4)
#define SOC_SC_SLC02_INT_ST_pmu_cnt5_st_START (5)
#define SOC_SC_SLC02_INT_ST_pmu_cnt5_st_END (5)
#define SOC_SC_SLC02_INT_ST_pmu_cnt6_st_START (6)
#define SOC_SC_SLC02_INT_ST_pmu_cnt6_st_END (6)
#define SOC_SC_SLC02_INT_ST_pmu_cnt7_st_START (7)
#define SOC_SC_SLC02_INT_ST_pmu_cnt7_st_END (7)
#define SOC_SC_SLC02_INT_ST_pmu_cnt8_st_START (8)
#define SOC_SC_SLC02_INT_ST_pmu_cnt8_st_END (8)
#define SOC_SC_SLC02_INT_ST_pmu_cnt9_st_START (9)
#define SOC_SC_SLC02_INT_ST_pmu_cnt9_st_END (9)
#define SOC_SC_SLC02_INT_ST_pmu_cnt10_st_START (10)
#define SOC_SC_SLC02_INT_ST_pmu_cnt10_st_END (10)
#define SOC_SC_SLC02_INT_ST_pmu_cnt11_st_START (11)
#define SOC_SC_SLC02_INT_ST_pmu_cnt11_st_END (11)
#define SOC_SC_SLC02_INT_ST_eccerr_st_START (12)
#define SOC_SC_SLC02_INT_ST_eccerr_st_END (12)
#define SOC_SC_SLC02_INT_ST_dfx_gid_illegal_st_START (13)
#define SOC_SC_SLC02_INT_ST_dfx_gid_illegal_st_END (13)
#define SOC_SC_SLC02_INT_ST_dfx_gid_mismatch_st_START (14)
#define SOC_SC_SLC02_INT_ST_dfx_gid_mismatch_st_END (14)
#define SOC_SC_SLC02_INT_ST_dfx_pri_noalloc_st_START (15)
#define SOC_SC_SLC02_INT_ST_dfx_pri_noalloc_st_END (15)
#define SOC_SC_SLC02_INT_ST_dfx_multihit_st_START (16)
#define SOC_SC_SLC02_INT_ST_dfx_multihit_st_END (16)
#define SOC_SC_SLC02_INT_ST_dfx_cmd_lpway_st_START (17)
#define SOC_SC_SLC02_INT_ST_dfx_cmd_lpway_st_END (17)
#define SOC_SC_SLC02_INT_ST_dfx_cmo_lpway_st_START (18)
#define SOC_SC_SLC02_INT_ST_dfx_cmo_lpway_st_END (18)
#define SOC_SC_SLC02_INT_ST_dfx_cmo_sec_st_START (19)
#define SOC_SC_SLC02_INT_ST_dfx_cmo_sec_st_END (19)
#define SOC_SC_SLC02_INT_ST_dfx_cmogid_illegal_st_START (20)
#define SOC_SC_SLC02_INT_ST_dfx_cmogid_illegal_st_END (20)
#define SOC_SC_SLC02_INT_ST_dfx_slv_wrap_write_st_START (21)
#define SOC_SC_SLC02_INT_ST_dfx_slv_wrap_write_st_END (21)
#define SOC_SC_SLC02_INT_ST_dfx_slv_cross_align_st_START (22)
#define SOC_SC_SLC02_INT_ST_dfx_slv_cross_align_st_END (22)
#define SOC_SC_SLC02_INT_ST_dfx_slv_vacmo_err_st_START (23)
#define SOC_SC_SLC02_INT_ST_dfx_slv_vacmo_err_st_END (23)
#define SOC_SC_SLC02_INT_ST_dfx_slv_wd_mismatch_st_START (24)
#define SOC_SC_SLC02_INT_ST_dfx_slv_wd_mismatch_st_END (24)
#define SOC_SC_SLC02_INT_ST_dfx_abnormal_dummy_st_START (25)
#define SOC_SC_SLC02_INT_ST_dfx_abnormal_dummy_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_ini : 1;
        unsigned int pmu_cnt1_ini : 1;
        unsigned int pmu_cnt2_ini : 1;
        unsigned int pmu_cnt3_ini : 1;
        unsigned int pmu_cnt4_ini : 1;
        unsigned int pmu_cnt5_ini : 1;
        unsigned int pmu_cnt6_ini : 1;
        unsigned int pmu_cnt7_ini : 1;
        unsigned int pmu_cnt8_ini : 1;
        unsigned int pmu_cnt9_ini : 1;
        unsigned int pmu_cnt10_ini : 1;
        unsigned int pmu_cnt11_ini : 1;
        unsigned int eccerr_ini : 1;
        unsigned int dfx_gid_illegal_ini : 1;
        unsigned int dfx_gid_mismatch_ini : 1;
        unsigned int dfx_pri_noalloc_ini : 1;
        unsigned int dfx_multihit_ini : 1;
        unsigned int dfx_cmd_lpway_ini : 1;
        unsigned int dfx_cmo_lpway_ini : 1;
        unsigned int dfx_cmo_sec_ini : 1;
        unsigned int dfx_cmogid_illegal_ini : 1;
        unsigned int dfx_slv_wrap_write_ini : 1;
        unsigned int dfx_slv_cross_align_ini : 1;
        unsigned int dfx_slv_vacmo_err_ini : 1;
        unsigned int dfx_slv_wd_mismatch_ini : 1;
        unsigned int dfx_abnormal_dummy_ini : 7;
    } reg;
} SOC_SC_SLC02_INT_INI_UNION;
#endif
#define SOC_SC_SLC02_INT_INI_pmu_cnt0_ini_START (0)
#define SOC_SC_SLC02_INT_INI_pmu_cnt0_ini_END (0)
#define SOC_SC_SLC02_INT_INI_pmu_cnt1_ini_START (1)
#define SOC_SC_SLC02_INT_INI_pmu_cnt1_ini_END (1)
#define SOC_SC_SLC02_INT_INI_pmu_cnt2_ini_START (2)
#define SOC_SC_SLC02_INT_INI_pmu_cnt2_ini_END (2)
#define SOC_SC_SLC02_INT_INI_pmu_cnt3_ini_START (3)
#define SOC_SC_SLC02_INT_INI_pmu_cnt3_ini_END (3)
#define SOC_SC_SLC02_INT_INI_pmu_cnt4_ini_START (4)
#define SOC_SC_SLC02_INT_INI_pmu_cnt4_ini_END (4)
#define SOC_SC_SLC02_INT_INI_pmu_cnt5_ini_START (5)
#define SOC_SC_SLC02_INT_INI_pmu_cnt5_ini_END (5)
#define SOC_SC_SLC02_INT_INI_pmu_cnt6_ini_START (6)
#define SOC_SC_SLC02_INT_INI_pmu_cnt6_ini_END (6)
#define SOC_SC_SLC02_INT_INI_pmu_cnt7_ini_START (7)
#define SOC_SC_SLC02_INT_INI_pmu_cnt7_ini_END (7)
#define SOC_SC_SLC02_INT_INI_pmu_cnt8_ini_START (8)
#define SOC_SC_SLC02_INT_INI_pmu_cnt8_ini_END (8)
#define SOC_SC_SLC02_INT_INI_pmu_cnt9_ini_START (9)
#define SOC_SC_SLC02_INT_INI_pmu_cnt9_ini_END (9)
#define SOC_SC_SLC02_INT_INI_pmu_cnt10_ini_START (10)
#define SOC_SC_SLC02_INT_INI_pmu_cnt10_ini_END (10)
#define SOC_SC_SLC02_INT_INI_pmu_cnt11_ini_START (11)
#define SOC_SC_SLC02_INT_INI_pmu_cnt11_ini_END (11)
#define SOC_SC_SLC02_INT_INI_eccerr_ini_START (12)
#define SOC_SC_SLC02_INT_INI_eccerr_ini_END (12)
#define SOC_SC_SLC02_INT_INI_dfx_gid_illegal_ini_START (13)
#define SOC_SC_SLC02_INT_INI_dfx_gid_illegal_ini_END (13)
#define SOC_SC_SLC02_INT_INI_dfx_gid_mismatch_ini_START (14)
#define SOC_SC_SLC02_INT_INI_dfx_gid_mismatch_ini_END (14)
#define SOC_SC_SLC02_INT_INI_dfx_pri_noalloc_ini_START (15)
#define SOC_SC_SLC02_INT_INI_dfx_pri_noalloc_ini_END (15)
#define SOC_SC_SLC02_INT_INI_dfx_multihit_ini_START (16)
#define SOC_SC_SLC02_INT_INI_dfx_multihit_ini_END (16)
#define SOC_SC_SLC02_INT_INI_dfx_cmd_lpway_ini_START (17)
#define SOC_SC_SLC02_INT_INI_dfx_cmd_lpway_ini_END (17)
#define SOC_SC_SLC02_INT_INI_dfx_cmo_lpway_ini_START (18)
#define SOC_SC_SLC02_INT_INI_dfx_cmo_lpway_ini_END (18)
#define SOC_SC_SLC02_INT_INI_dfx_cmo_sec_ini_START (19)
#define SOC_SC_SLC02_INT_INI_dfx_cmo_sec_ini_END (19)
#define SOC_SC_SLC02_INT_INI_dfx_cmogid_illegal_ini_START (20)
#define SOC_SC_SLC02_INT_INI_dfx_cmogid_illegal_ini_END (20)
#define SOC_SC_SLC02_INT_INI_dfx_slv_wrap_write_ini_START (21)
#define SOC_SC_SLC02_INT_INI_dfx_slv_wrap_write_ini_END (21)
#define SOC_SC_SLC02_INT_INI_dfx_slv_cross_align_ini_START (22)
#define SOC_SC_SLC02_INT_INI_dfx_slv_cross_align_ini_END (22)
#define SOC_SC_SLC02_INT_INI_dfx_slv_vacmo_err_ini_START (23)
#define SOC_SC_SLC02_INT_INI_dfx_slv_vacmo_err_ini_END (23)
#define SOC_SC_SLC02_INT_INI_dfx_slv_wd_mismatch_ini_START (24)
#define SOC_SC_SLC02_INT_INI_dfx_slv_wd_mismatch_ini_END (24)
#define SOC_SC_SLC02_INT_INI_dfx_abnormal_dummy_ini_START (25)
#define SOC_SC_SLC02_INT_INI_dfx_abnormal_dummy_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_clr : 1;
        unsigned int pmu_cnt1_clr : 1;
        unsigned int pmu_cnt2_clr : 1;
        unsigned int pmu_cnt3_clr : 1;
        unsigned int pmu_cnt4_clr : 1;
        unsigned int pmu_cnt5_clr : 1;
        unsigned int pmu_cnt6_clr : 1;
        unsigned int pmu_cnt7_clr : 1;
        unsigned int pmu_cnt8_clr : 1;
        unsigned int pmu_cnt9_clr : 1;
        unsigned int pmu_cnt10_clr : 1;
        unsigned int pmu_cnt11_clr : 1;
        unsigned int eccerr_clr : 1;
        unsigned int dfx_err_clr : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_SC_SLC02_INT_CLEAR_UNION;
#endif
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt0_clr_START (0)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt0_clr_END (0)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt1_clr_START (1)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt1_clr_END (1)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt2_clr_START (2)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt2_clr_END (2)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt3_clr_START (3)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt3_clr_END (3)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt4_clr_START (4)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt4_clr_END (4)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt5_clr_START (5)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt5_clr_END (5)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt6_clr_START (6)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt6_clr_END (6)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt7_clr_START (7)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt7_clr_END (7)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt8_clr_START (8)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt8_clr_END (8)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt9_clr_START (9)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt9_clr_END (9)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt10_clr_START (10)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt10_clr_END (10)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt11_clr_START (11)
#define SOC_SC_SLC02_INT_CLEAR_pmu_cnt11_clr_END (11)
#define SOC_SC_SLC02_INT_CLEAR_eccerr_clr_START (12)
#define SOC_SC_SLC02_INT_CLEAR_eccerr_clr_END (12)
#define SOC_SC_SLC02_INT_CLEAR_dfx_err_clr_START (13)
#define SOC_SC_SLC02_INT_CLEAR_dfx_err_clr_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmu_cnt0_int_en : 1;
        unsigned int pmu_cnt1_int_en : 1;
        unsigned int pmu_cnt2_int_en : 1;
        unsigned int pmu_cnt3_int_en : 1;
        unsigned int pmu_cnt4_int_en : 1;
        unsigned int pmu_cnt5_int_en : 1;
        unsigned int pmu_cnt6_int_en : 1;
        unsigned int pmu_cnt7_int_en : 1;
        unsigned int pmu_cnt8_int_en : 1;
        unsigned int pmu_cnt9_int_en : 1;
        unsigned int pmu_cnt10_int_en : 1;
        unsigned int pmu_cnt11_int_en : 1;
        unsigned int eccerr_en : 1;
        unsigned int dfx_gid_illegal_en : 1;
        unsigned int dfx_gid_mismatch_en : 1;
        unsigned int dfx_pri_noalloc_en : 1;
        unsigned int dfx_multihit_en : 1;
        unsigned int dfx_cmd_lpway_en : 1;
        unsigned int dfx_cmo_lpway_en : 1;
        unsigned int dfx_cmo_sec_en : 1;
        unsigned int dfx_cmogid_illegal_en : 1;
        unsigned int dfx_slv_wrap_write_en : 1;
        unsigned int dfx_slv_cross_align_en : 1;
        unsigned int dfx_slv_vacmo_err_en : 1;
        unsigned int dfx_slv_wd_mismatch_en : 1;
        unsigned int dfx_abnormal_dummy_en : 7;
    } reg;
} SOC_SC_SLC02_INT_EN_UNION;
#endif
#define SOC_SC_SLC02_INT_EN_pmu_cnt0_int_en_START (0)
#define SOC_SC_SLC02_INT_EN_pmu_cnt0_int_en_END (0)
#define SOC_SC_SLC02_INT_EN_pmu_cnt1_int_en_START (1)
#define SOC_SC_SLC02_INT_EN_pmu_cnt1_int_en_END (1)
#define SOC_SC_SLC02_INT_EN_pmu_cnt2_int_en_START (2)
#define SOC_SC_SLC02_INT_EN_pmu_cnt2_int_en_END (2)
#define SOC_SC_SLC02_INT_EN_pmu_cnt3_int_en_START (3)
#define SOC_SC_SLC02_INT_EN_pmu_cnt3_int_en_END (3)
#define SOC_SC_SLC02_INT_EN_pmu_cnt4_int_en_START (4)
#define SOC_SC_SLC02_INT_EN_pmu_cnt4_int_en_END (4)
#define SOC_SC_SLC02_INT_EN_pmu_cnt5_int_en_START (5)
#define SOC_SC_SLC02_INT_EN_pmu_cnt5_int_en_END (5)
#define SOC_SC_SLC02_INT_EN_pmu_cnt6_int_en_START (6)
#define SOC_SC_SLC02_INT_EN_pmu_cnt6_int_en_END (6)
#define SOC_SC_SLC02_INT_EN_pmu_cnt7_int_en_START (7)
#define SOC_SC_SLC02_INT_EN_pmu_cnt7_int_en_END (7)
#define SOC_SC_SLC02_INT_EN_pmu_cnt8_int_en_START (8)
#define SOC_SC_SLC02_INT_EN_pmu_cnt8_int_en_END (8)
#define SOC_SC_SLC02_INT_EN_pmu_cnt9_int_en_START (9)
#define SOC_SC_SLC02_INT_EN_pmu_cnt9_int_en_END (9)
#define SOC_SC_SLC02_INT_EN_pmu_cnt10_int_en_START (10)
#define SOC_SC_SLC02_INT_EN_pmu_cnt10_int_en_END (10)
#define SOC_SC_SLC02_INT_EN_pmu_cnt11_int_en_START (11)
#define SOC_SC_SLC02_INT_EN_pmu_cnt11_int_en_END (11)
#define SOC_SC_SLC02_INT_EN_eccerr_en_START (12)
#define SOC_SC_SLC02_INT_EN_eccerr_en_END (12)
#define SOC_SC_SLC02_INT_EN_dfx_gid_illegal_en_START (13)
#define SOC_SC_SLC02_INT_EN_dfx_gid_illegal_en_END (13)
#define SOC_SC_SLC02_INT_EN_dfx_gid_mismatch_en_START (14)
#define SOC_SC_SLC02_INT_EN_dfx_gid_mismatch_en_END (14)
#define SOC_SC_SLC02_INT_EN_dfx_pri_noalloc_en_START (15)
#define SOC_SC_SLC02_INT_EN_dfx_pri_noalloc_en_END (15)
#define SOC_SC_SLC02_INT_EN_dfx_multihit_en_START (16)
#define SOC_SC_SLC02_INT_EN_dfx_multihit_en_END (16)
#define SOC_SC_SLC02_INT_EN_dfx_cmd_lpway_en_START (17)
#define SOC_SC_SLC02_INT_EN_dfx_cmd_lpway_en_END (17)
#define SOC_SC_SLC02_INT_EN_dfx_cmo_lpway_en_START (18)
#define SOC_SC_SLC02_INT_EN_dfx_cmo_lpway_en_END (18)
#define SOC_SC_SLC02_INT_EN_dfx_cmo_sec_en_START (19)
#define SOC_SC_SLC02_INT_EN_dfx_cmo_sec_en_END (19)
#define SOC_SC_SLC02_INT_EN_dfx_cmogid_illegal_en_START (20)
#define SOC_SC_SLC02_INT_EN_dfx_cmogid_illegal_en_END (20)
#define SOC_SC_SLC02_INT_EN_dfx_slv_wrap_write_en_START (21)
#define SOC_SC_SLC02_INT_EN_dfx_slv_wrap_write_en_END (21)
#define SOC_SC_SLC02_INT_EN_dfx_slv_cross_align_en_START (22)
#define SOC_SC_SLC02_INT_EN_dfx_slv_cross_align_en_END (22)
#define SOC_SC_SLC02_INT_EN_dfx_slv_vacmo_err_en_START (23)
#define SOC_SC_SLC02_INT_EN_dfx_slv_vacmo_err_en_END (23)
#define SOC_SC_SLC02_INT_EN_dfx_slv_wd_mismatch_en_START (24)
#define SOC_SC_SLC02_INT_EN_dfx_slv_wd_mismatch_en_END (24)
#define SOC_SC_SLC02_INT_EN_dfx_abnormal_dummy_en_START (25)
#define SOC_SC_SLC02_INT_EN_dfx_abnormal_dummy_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int slc13_eccerr_st : 1;
        unsigned int slc13_dfx_gid_illegal_st : 1;
        unsigned int slc13_dfx_gid_mismatch_st : 1;
        unsigned int slc13_dfx_pri_noalloc_st : 1;
        unsigned int slc13_dfx_multihit_st : 1;
        unsigned int slc13_dfx_cmd_lpway_st : 1;
        unsigned int slc13_dfx_cmo_lpway_st : 1;
        unsigned int slc13_dfx_cmo_sec_st : 1;
        unsigned int slc13_dfx_cmogid_illegal_st : 1;
        unsigned int slc13_dfx_slv_wrap_write_st : 1;
        unsigned int slc13_dfx_slv_cross_align_st : 1;
        unsigned int slc13_dfx_slv_vacmo_err_st : 1;
        unsigned int slc13_dfx_slv_wd_mismatch_st : 1;
        unsigned int slc13_dfx_abnormal_dummy_st : 7;
    } reg;
} SOC_SC_SLC13_INT_ST_UNION;
#endif
#define SOC_SC_SLC13_INT_ST_slc13_eccerr_st_START (12)
#define SOC_SC_SLC13_INT_ST_slc13_eccerr_st_END (12)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_gid_illegal_st_START (13)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_gid_illegal_st_END (13)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_gid_mismatch_st_START (14)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_gid_mismatch_st_END (14)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_pri_noalloc_st_START (15)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_pri_noalloc_st_END (15)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_multihit_st_START (16)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_multihit_st_END (16)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmd_lpway_st_START (17)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmd_lpway_st_END (17)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmo_lpway_st_START (18)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmo_lpway_st_END (18)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmo_sec_st_START (19)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmo_sec_st_END (19)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmogid_illegal_st_START (20)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_cmogid_illegal_st_END (20)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_wrap_write_st_START (21)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_wrap_write_st_END (21)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_cross_align_st_START (22)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_cross_align_st_END (22)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_vacmo_err_st_START (23)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_vacmo_err_st_END (23)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_wd_mismatch_st_START (24)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_slv_wd_mismatch_st_END (24)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_abnormal_dummy_st_START (25)
#define SOC_SC_SLC13_INT_ST_slc13_dfx_abnormal_dummy_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int slc13_eccerr_ini : 1;
        unsigned int slc13_dfx_gid_illegal_ini : 1;
        unsigned int slc13_dfx_gid_mismatch_ini : 1;
        unsigned int slc13_dfx_pri_noalloc_ini : 1;
        unsigned int slc13_dfx_multihit_ini : 1;
        unsigned int slc13_dfx_cmd_lpway_ini : 1;
        unsigned int slc13_dfx_cmo_lpway_ini : 1;
        unsigned int slc13_dfx_cmo_sec_ini : 1;
        unsigned int slc13_dfx_cmogid_illegal_ini : 1;
        unsigned int slc13_dfx_slv_wrap_write_ini : 1;
        unsigned int slc13_dfx_slv_cross_align_ini : 1;
        unsigned int slc13_dfx_slv_vacmo_err_ini : 1;
        unsigned int slc13_dfx_slv_wd_mismatch_ini : 1;
        unsigned int slc13_dfx_abnormal_dummy_ini : 7;
    } reg;
} SOC_SC_SLC13_INT_INI_UNION;
#endif
#define SOC_SC_SLC13_INT_INI_slc13_eccerr_ini_START (12)
#define SOC_SC_SLC13_INT_INI_slc13_eccerr_ini_END (12)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_gid_illegal_ini_START (13)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_gid_illegal_ini_END (13)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_gid_mismatch_ini_START (14)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_gid_mismatch_ini_END (14)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_pri_noalloc_ini_START (15)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_pri_noalloc_ini_END (15)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_multihit_ini_START (16)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_multihit_ini_END (16)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmd_lpway_ini_START (17)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmd_lpway_ini_END (17)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmo_lpway_ini_START (18)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmo_lpway_ini_END (18)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmo_sec_ini_START (19)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmo_sec_ini_END (19)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmogid_illegal_ini_START (20)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_cmogid_illegal_ini_END (20)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_wrap_write_ini_START (21)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_wrap_write_ini_END (21)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_cross_align_ini_START (22)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_cross_align_ini_END (22)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_vacmo_err_ini_START (23)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_vacmo_err_ini_END (23)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_wd_mismatch_ini_START (24)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_slv_wd_mismatch_ini_END (24)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_abnormal_dummy_ini_START (25)
#define SOC_SC_SLC13_INT_INI_slc13_dfx_abnormal_dummy_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int slc13_eccerr_clr : 1;
        unsigned int slc13_dfx_err_clr : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_SC_SLC13_INT_CLEAR_UNION;
#endif
#define SOC_SC_SLC13_INT_CLEAR_slc13_eccerr_clr_START (12)
#define SOC_SC_SLC13_INT_CLEAR_slc13_eccerr_clr_END (12)
#define SOC_SC_SLC13_INT_CLEAR_slc13_dfx_err_clr_START (13)
#define SOC_SC_SLC13_INT_CLEAR_slc13_dfx_err_clr_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int slc13_eccerr_int_en : 1;
        unsigned int slc13_dfx_gid_illegal_en : 1;
        unsigned int slc13_dfx_gid_mismatch_en : 1;
        unsigned int slc13_dfx_pri_noalloc_en : 1;
        unsigned int slc13_dfx_multihit_en : 1;
        unsigned int slc13_dfx_cmd_lpway_en : 1;
        unsigned int slc13_dfx_cmo_lpway_en : 1;
        unsigned int slc13_dfx_cmo_sec_en : 1;
        unsigned int slc13_dfx_cmogid_illegal_en : 1;
        unsigned int slc13_dfx_slv_wrap_write_en : 1;
        unsigned int slc13_dfx_slv_cross_align_en : 1;
        unsigned int slc13_dfx_slv_vacmo_err_en : 1;
        unsigned int slc13_dfx_slv_wd_mismatch_en : 1;
        unsigned int slc13_dfx_abnormal_dummy_en : 7;
    } reg;
} SOC_SC_SLC13_INT_EN_UNION;
#endif
#define SOC_SC_SLC13_INT_EN_slc13_eccerr_int_en_START (12)
#define SOC_SC_SLC13_INT_EN_slc13_eccerr_int_en_END (12)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_gid_illegal_en_START (13)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_gid_illegal_en_END (13)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_gid_mismatch_en_START (14)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_gid_mismatch_en_END (14)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_pri_noalloc_en_START (15)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_pri_noalloc_en_END (15)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_multihit_en_START (16)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_multihit_en_END (16)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmd_lpway_en_START (17)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmd_lpway_en_END (17)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmo_lpway_en_START (18)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmo_lpway_en_END (18)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmo_sec_en_START (19)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmo_sec_en_END (19)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmogid_illegal_en_START (20)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_cmogid_illegal_en_END (20)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_wrap_write_en_START (21)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_wrap_write_en_END (21)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_cross_align_en_START (22)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_cross_align_en_END (22)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_vacmo_err_en_START (23)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_vacmo_err_en_END (23)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_wd_mismatch_en_START (24)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_slv_wd_mismatch_en_END (24)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_abnormal_dummy_en_START (25)
#define SOC_SC_SLC13_INT_EN_slc13_dfx_abnormal_dummy_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_module_busy : 32;
    } reg;
} SOC_SC_SLC_DFX_MODULE_UNION;
#endif
#define SOC_SC_SLC_DFX_MODULE_dfx_module_busy_START (0)
#define SOC_SC_SLC_DFX_MODULE_dfx_module_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cmdque_st : 32;
    } reg;
} SOC_SC_SLC_DFX_SCQ_UNION;
#endif
#define SOC_SC_SLC_DFX_SCQ_dfx_cmdque_st_START (0)
#define SOC_SC_SLC_DFX_SCQ_dfx_cmdque_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sque_st0 : 32;
    } reg;
} SOC_SC_SLC_DFX_SQUE0_UNION;
#endif
#define SOC_SC_SLC_DFX_SQUE0_dfx_sque_st0_START (0)
#define SOC_SC_SLC_DFX_SQUE0_dfx_sque_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_req_st0 : 32;
    } reg;
} SOC_SC_SLC_DFX_REQ0_UNION;
#endif
#define SOC_SC_SLC_DFX_REQ0_dfx_req_st0_START (0)
#define SOC_SC_SLC_DFX_REQ0_dfx_req_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_buf_st : 32;
    } reg;
} SOC_SC_SLC_DFX_BUF_UNION;
#endif
#define SOC_SC_SLC_DFX_BUF_dfx_buf_st_START (0)
#define SOC_SC_SLC_DFX_BUF_dfx_buf_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slv_wostd : 4;
        unsigned int slv_rostd : 8;
        unsigned int mst_wostd : 4;
        unsigned int mst_rostd : 8;
        unsigned int resp_ostd : 8;
    } reg;
} SOC_SC_SLC_DFX_OT_UNION;
#endif
#define SOC_SC_SLC_DFX_OT_slv_wostd_START (0)
#define SOC_SC_SLC_DFX_OT_slv_wostd_END (3)
#define SOC_SC_SLC_DFX_OT_slv_rostd_START (4)
#define SOC_SC_SLC_DFX_OT_slv_rostd_END (11)
#define SOC_SC_SLC_DFX_OT_mst_wostd_START (12)
#define SOC_SC_SLC_DFX_OT_mst_wostd_END (15)
#define SOC_SC_SLC_DFX_OT_mst_rostd_START (16)
#define SOC_SC_SLC_DFX_OT_mst_rostd_END (23)
#define SOC_SC_SLC_DFX_OT_resp_ostd_START (24)
#define SOC_SC_SLC_DFX_OT_resp_ostd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_fifo_st0 : 32;
    } reg;
} SOC_SC_SLC_DFX_FIFO0_UNION;
#endif
#define SOC_SC_SLC_DFX_FIFO0_dfx_fifo_st0_START (0)
#define SOC_SC_SLC_DFX_FIFO0_dfx_fifo_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_fifo_st1 : 32;
    } reg;
} SOC_SC_SLC_DFX_FIFO1_UNION;
#endif
#define SOC_SC_SLC_DFX_FIFO1_dfx_fifo_st1_START (0)
#define SOC_SC_SLC_DFX_FIFO1_dfx_fifo_st1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_bp_st : 32;
    } reg;
} SOC_SC_SLC_DFX_BP_UNION;
#endif
#define SOC_SC_SLC_DFX_BP_dfx_bp_st_START (0)
#define SOC_SC_SLC_DFX_BP_dfx_bp_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cmd_addr : 32;
    } reg;
} SOC_SC_SLC_DFX_ERR_INF1_UNION;
#endif
#define SOC_SC_SLC_DFX_ERR_INF1_dfx_cmd_addr_START (0)
#define SOC_SC_SLC_DFX_ERR_INF1_dfx_cmd_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cmd_gid : 4;
        unsigned int dfx_cmd_mid : 8;
        unsigned int dfx_cmd_type : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_SC_SLC_DFX_ERR_INF2_UNION;
#endif
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_gid_START (0)
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_gid_END (3)
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_mid_START (4)
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_mid_END (11)
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_type_START (12)
#define SOC_SC_SLC_DFX_ERR_INF2_dfx_cmd_type_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_eccerr_single : 1;
        unsigned int dfx_eccerr_multi : 1;
        unsigned int dfx_eccerr_dmem : 1;
        unsigned int dfx_eccerr_tmem : 1;
        unsigned int dfx_eccerr_way : 4;
        unsigned int dfx_eccerr_idx : 10;
        unsigned int dfx_eccerr_ofs : 2;
        unsigned int dfx_eccerr_cnt_dmem_multi : 4;
        unsigned int dfx_eccerr_cnt_dmem_single : 4;
        unsigned int dfx_eccerr_cnt_tmem_multi : 2;
        unsigned int dfx_eccerr_cnt_tmem_single : 2;
    } reg;
} SOC_SC_SLC_DFX_ECCERR_UNION;
#endif
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_single_START (0)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_single_END (0)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_multi_START (1)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_multi_END (1)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_dmem_START (2)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_dmem_END (2)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_tmem_START (3)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_tmem_END (3)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_way_START (4)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_way_END (7)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_idx_START (8)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_idx_END (17)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_ofs_START (18)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_ofs_END (19)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_dmem_multi_START (20)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_dmem_multi_END (23)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_dmem_single_START (24)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_dmem_single_END (27)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_tmem_multi_START (28)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_tmem_multi_END (29)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_tmem_single_START (30)
#define SOC_SC_SLC_DFX_ECCERR_dfx_eccerr_cnt_tmem_single_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_mem_st0 : 32;
    } reg;
} SOC_SC_SLC_DFX_MEM0_UNION;
#endif
#define SOC_SC_SLC_DFX_MEM0_dfx_mem_st0_START (0)
#define SOC_SC_SLC_DFX_MEM0_dfx_mem_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_mem_st1 : 32;
    } reg;
} SOC_SC_SLC_DFX_MEM1_UNION;
#endif
#define SOC_SC_SLC_DFX_MEM1_dfx_mem_st1_START (0)
#define SOC_SC_SLC_DFX_MEM1_dfx_mem_st1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_sel : 6;
        unsigned int dfx_sch_snapshot_src : 2;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_SLC_DFX_SCH_CTRL_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_CTRL_dfx_sch_snapshot_sel_START (0)
#define SOC_SC_SLC_DFX_SCH_CTRL_dfx_sch_snapshot_sel_END (5)
#define SOC_SC_SLC_DFX_SCH_CTRL_dfx_sch_snapshot_src_START (6)
#define SOC_SC_SLC_DFX_SCH_CTRL_dfx_sch_snapshot_src_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_info0 : 32;
    } reg;
} SOC_SC_SLC_DFX_SCH_INFO0_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_INFO0_dfx_sch_snapshot_info0_START (0)
#define SOC_SC_SLC_DFX_SCH_INFO0_dfx_sch_snapshot_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_info1 : 32;
    } reg;
} SOC_SC_SLC_DFX_SCH_INFO1_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_INFO1_dfx_sch_snapshot_info1_START (0)
#define SOC_SC_SLC_DFX_SCH_INFO1_dfx_sch_snapshot_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_info2 : 32;
    } reg;
} SOC_SC_SLC_DFX_SCH_INFO2_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_INFO2_dfx_sch_snapshot_info2_START (0)
#define SOC_SC_SLC_DFX_SCH_INFO2_dfx_sch_snapshot_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_info3 : 32;
    } reg;
} SOC_SC_SLC_DFX_SCH_INFO3_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_INFO3_dfx_sch_snapshot_info3_START (0)
#define SOC_SC_SLC_DFX_SCH_INFO3_dfx_sch_snapshot_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sch_snapshot_info4 : 32;
    } reg;
} SOC_SC_SLC_DFX_SCH_INFO4_UNION;
#endif
#define SOC_SC_SLC_DFX_SCH_INFO4_dfx_sch_snapshot_info4_START (0)
#define SOC_SC_SLC_DFX_SCH_INFO4_dfx_sch_snapshot_info4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cmo_gen_st : 32;
    } reg;
} SOC_SC_SLC_DFX_CMOGEN_UNION;
#endif
#define SOC_SC_SLC_DFX_CMOGEN_dfx_cmo_gen_st_START (0)
#define SOC_SC_SLC_DFX_CMOGEN_dfx_cmo_gen_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dummy_st0 : 32;
    } reg;
} SOC_SC_SLC_DFX_DUMMY0_UNION;
#endif
#define SOC_SC_SLC_DFX_DUMMY0_dfx_dummy_st0_START (0)
#define SOC_SC_SLC_DFX_DUMMY0_dfx_dummy_st0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dummy_st1 : 32;
    } reg;
} SOC_SC_SLC_DFX_DUMMY1_UNION;
#endif
#define SOC_SC_SLC_DFX_DUMMY1_dfx_dummy_st1_START (0)
#define SOC_SC_SLC_DFX_DUMMY1_dfx_dummy_st1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int way_pwrup : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SLC_WAY_PWRUP_S_UNION;
#endif
#define SOC_SC_SLC_WAY_PWRUP_S_way_pwrup_START (0)
#define SOC_SC_SLC_WAY_PWRUP_S_way_pwrup_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spmem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SC_SLC_SPMEM_CTRL_S_UNION;
#endif
#define SOC_SC_SLC_SPMEM_CTRL_S_spmem_ctrl_START (0)
#define SOC_SC_SLC_SPMEM_CTRL_S_spmem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SLC_TPMEM_CTRL_S_UNION;
#endif
#define SOC_SC_SLC_TPMEM_CTRL_S_tpmem_ctrl_START (0)
#define SOC_SC_SLC_TPMEM_CTRL_S_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tag_mem_rd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SLC_TAG_MEM_RD_EN_S_UNION;
#endif
#define SOC_SC_SLC_TAG_MEM_RD_EN_S_tag_mem_rd_en_START (0)
#define SOC_SC_SLC_TAG_MEM_RD_EN_S_tag_mem_rd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_rd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SLC_DATA_MEM_RD_EN_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_RD_EN_S_data_mem_rd_en_START (0)
#define SOC_SC_SLC_DATA_MEM_RD_EN_S_data_mem_rd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tag_mem_index : 12;
        unsigned int tag_mem_way_num : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SLC_TAG_MEM_RD_ADDR_S_UNION;
#endif
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_tag_mem_index_START (0)
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_tag_mem_index_END (11)
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_tag_mem_way_num_START (12)
#define SOC_SC_SLC_TAG_MEM_RD_ADDR_S_tag_mem_way_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_index : 12;
        unsigned int data_mem_way_num : 4;
        unsigned int data_mem_tsf_num : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SLC_DATA_MEM_RD_ADDR_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_index_START (0)
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_index_END (11)
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_way_num_START (12)
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_way_num_END (15)
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_tsf_num_START (16)
#define SOC_SC_SLC_DATA_MEM_RD_ADDR_S_data_mem_tsf_num_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tag_mem_data_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SLC_TAG_MEM_DATA_VLD_S_UNION;
#endif
#define SOC_SC_SLC_TAG_MEM_DATA_VLD_S_tag_mem_data_vld_START (0)
#define SOC_SC_SLC_TAG_MEM_DATA_VLD_S_tag_mem_data_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA_VLD_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA_VLD_S_data_mem_data_vld_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA_VLD_S_data_mem_data_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tag_mem_data : 32;
    } reg;
} SOC_SC_SLC_TAG_MEM_DATA_S_UNION;
#endif
#define SOC_SC_SLC_TAG_MEM_DATA_S_tag_mem_data_START (0)
#define SOC_SC_SLC_TAG_MEM_DATA_S_tag_mem_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data0 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA1_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA1_S_data_mem_data0_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA1_S_data_mem_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data1 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA2_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA2_S_data_mem_data1_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA2_S_data_mem_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data2 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA3_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA3_S_data_mem_data2_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA3_S_data_mem_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data3 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA4_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA4_S_data_mem_data3_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA4_S_data_mem_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data4 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA5_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA5_S_data_mem_data4_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA5_S_data_mem_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data5 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA6_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA6_S_data_mem_data5_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA6_S_data_mem_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data6 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA7_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA7_S_data_mem_data6_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA7_S_data_mem_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data7 : 32;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA8_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA8_S_data_mem_data7_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA8_S_data_mem_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_mem_data8 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SC_SLC_DATA_MEM_DATA9_S_UNION;
#endif
#define SOC_SC_SLC_DATA_MEM_DATA9_S_data_mem_data8_START (0)
#define SOC_SC_SLC_DATA_MEM_DATA9_S_data_mem_data8_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_rw0 : 32;
    } reg;
} SOC_SC_SLC_DUMMY_RW0_S_UNION;
#endif
#define SOC_SC_SLC_DUMMY_RW0_S_dummy_rw0_START (0)
#define SOC_SC_SLC_DUMMY_RW0_S_dummy_rw0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_rw1 : 32;
    } reg;
} SOC_SC_SLC_DUMMY_RW1_S_UNION;
#endif
#define SOC_SC_SLC_DUMMY_RW1_S_dummy_rw1_START (0)
#define SOC_SC_SLC_DUMMY_RW1_S_dummy_rw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_ro0 : 32;
    } reg;
} SOC_SC_SLC_DUMMY_RO0_S_UNION;
#endif
#define SOC_SC_SLC_DUMMY_RO0_S_dummy_ro0_START (0)
#define SOC_SC_SLC_DUMMY_RO0_S_dummy_ro0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dummy_ro1 : 32;
    } reg;
} SOC_SC_SLC_DUMMY_RO1_S_UNION;
#endif
#define SOC_SC_SLC_DUMMY_RO1_S_dummy_ro1_START (0)
#define SOC_SC_SLC_DUMMY_RO1_S_dummy_ro1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
