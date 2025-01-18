#ifndef __SOC_VDEC_INTERFACE_H__
#define __SOC_VDEC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_VDH_START_CNT_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_VDH_REPAIR_CNT_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_BASIC_CFG0_CNT_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_BASIC_CFG1_CNT_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_AVM_ADDR_CNT_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_VAM_ADDR_CNT_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_STREAM_BASE_ADDR_CNT_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_VDH_STATE_CNT_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_NORM_INT_STATE_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_NORM_INT_MASK_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_VCTRL_STATE_CNT_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_VDH_VERSION_ID_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_CFMW_REG_CMP_THR_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_RPT_CNT_CNT_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_VCTRL_TO_CNT_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_SED_TO_CNT_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_IT_TO_CNT_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_PMV_TO_CNT_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_PRC_TO_CNT_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_RCN_TO_CNT_ADDR(base) ((base) + (0x004cUL))
#define SOC_VDEC_DBLK_TO_CNT_ADDR(base) ((base) + (0x0050UL))
#define SOC_VDEC_PPFD_TO_CNT_ADDR(base) ((base) + (0x0054UL))
#define SOC_VDEC_FPGA_VERSION_ADDR(base) ((base) + (0x0058UL))
#define SOC_VDEC_PART_OVER_INT_LEVEL_ADDR(base) ((base) + (0x005cUL))
#define SOC_VDEC_YSTADDR_1D_CNT_ADDR(base) ((base) + (0x0060UL))
#define SOC_VDEC_YSTRIDE_1D_CNT_ADDR(base) ((base) + (0x0064UL))
#define SOC_VDEC_UVOFFSET_1D_CNT_ADDR(base) ((base) + (0x0068UL))
#define SOC_VDEC_HEAD_OFFSET_CNT_ADDR(base) ((base) + (0x006cUL))
#define SOC_VDEC_LINE_NUM_STADDR_CNT_ADDR(base) ((base) + (0x0070UL))
#define SOC_VDEC_YOFFSET_2BIT_CNT_ADDR(base) ((base) + (0x0078UL))
#define SOC_VDEC_UVOFFSET_2BIT_CNT_ADDR(base) ((base) + (0x007cUL))
#define SOC_VDEC_PPFD_BUF_ADDR_CNT_ADDR(base) ((base) + (0x0080UL))
#define SOC_VDEC_PPFD_BUF_LEN_CNT_ADDR(base) ((base) + (0x0084UL))
#define SOC_VDEC_REF_PIC_TYPE_CNT_ADDR(base) ((base) + (0x0094UL))
#define SOC_VDEC_PIC_CACHE_TYPE_ADDR(base) ((base) + (0x0098UL))
#define SOC_VDEC_DOMN_CLK_CFG_CNT_ADDR(base) ((base) + (0x009cUL))
#define SOC_VDEC_WATERMARK_START_POS_CNT_ADDR(base) ((base) + (0x00A0UL))
#define SOC_VDEC_WATERMARK_END_POS_CNT_ADDR(base) ((base) + (0x00A4UL))
#define SOC_VDEC_SAFE_INT_STATE_ADDR(base) ((base) + (0x00A8UL))
#define SOC_VDEC_SAFE_INT_MASK_ADDR(base) ((base) + (0x00ACUL))
#define SOC_VDEC_VDH_DEC_CYCLEPERPIC_ADDR(base) ((base) + (0x00B0UL))
#define SOC_VDEC_VDH_RD_BDWIDTH_PERPIC_ADDR(base) ((base) + (0x00B4UL))
#define SOC_VDEC_VDH_WR_BDWIDTH_PERPIC_ADDR(base) ((base) + (0x00B8UL))
#define SOC_VDEC_VDH_RD_REQ_PERPIC_ADDR(base) ((base) + (0x00BCUL))
#define SOC_VDEC_VDH_WR_REQ_PERPIC_ADDR(base) ((base) + (0x00C0UL))
#define SOC_VDEC_UV_STRIDE_1D_ADDR(base) ((base) + (0x00C4UL))
#define SOC_VDEC_CFGINFO_ADDR_ADDR(base) ((base) + (0x00C8UL))
#define SOC_VDEC_VIDEO_STANDARD_EN_ADDR(base) ((base) + (0x00CCUL))
#define SOC_VDEC_MB0_QP_IN_CURR_PIC_ADDR(base) ((base) + (0x00D0UL))
#define SOC_VDEC_SWITCH_ROUNDING_ADDR(base) ((base) + (0x00D4UL))
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_L_ADDR(base) ((base) + (0x00D8UL))
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_H_ADDR(base) ((base) + (0x00DCUL))
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_L_ADDR(base) ((base) + (0x00E0UL))
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_H_ADDR(base) ((base) + (0x00E4UL))
#define SOC_VDEC_EMAR_STATE2_ADDR(base) ((base) + (0x00E8UL))
#define SOC_VDEC_EMAR_STATE3_ADDR(base) ((base) + (0x00ECUL))
#define SOC_VDEC_EMAR_STATE4_ADDR(base) ((base) + (0x00F0UL))
#else
#define SOC_VDEC_VDH_START_CNT_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_VDH_REPAIR_CNT_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_BASIC_CFG0_CNT_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_BASIC_CFG1_CNT_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_AVM_ADDR_CNT_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_VAM_ADDR_CNT_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_STREAM_BASE_ADDR_CNT_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_VDH_STATE_CNT_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_NORM_INT_STATE_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_NORM_INT_MASK_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_VCTRL_STATE_CNT_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_VDH_VERSION_ID_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_CFMW_REG_CMP_THR_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_RPT_CNT_CNT_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_VCTRL_TO_CNT_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_SED_TO_CNT_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_IT_TO_CNT_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_PMV_TO_CNT_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_PRC_TO_CNT_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_RCN_TO_CNT_ADDR(base) ((base) + (0x004c))
#define SOC_VDEC_DBLK_TO_CNT_ADDR(base) ((base) + (0x0050))
#define SOC_VDEC_PPFD_TO_CNT_ADDR(base) ((base) + (0x0054))
#define SOC_VDEC_FPGA_VERSION_ADDR(base) ((base) + (0x0058))
#define SOC_VDEC_PART_OVER_INT_LEVEL_ADDR(base) ((base) + (0x005c))
#define SOC_VDEC_YSTADDR_1D_CNT_ADDR(base) ((base) + (0x0060))
#define SOC_VDEC_YSTRIDE_1D_CNT_ADDR(base) ((base) + (0x0064))
#define SOC_VDEC_UVOFFSET_1D_CNT_ADDR(base) ((base) + (0x0068))
#define SOC_VDEC_HEAD_OFFSET_CNT_ADDR(base) ((base) + (0x006c))
#define SOC_VDEC_LINE_NUM_STADDR_CNT_ADDR(base) ((base) + (0x0070))
#define SOC_VDEC_YOFFSET_2BIT_CNT_ADDR(base) ((base) + (0x0078))
#define SOC_VDEC_UVOFFSET_2BIT_CNT_ADDR(base) ((base) + (0x007c))
#define SOC_VDEC_PPFD_BUF_ADDR_CNT_ADDR(base) ((base) + (0x0080))
#define SOC_VDEC_PPFD_BUF_LEN_CNT_ADDR(base) ((base) + (0x0084))
#define SOC_VDEC_REF_PIC_TYPE_CNT_ADDR(base) ((base) + (0x0094))
#define SOC_VDEC_PIC_CACHE_TYPE_ADDR(base) ((base) + (0x0098))
#define SOC_VDEC_DOMN_CLK_CFG_CNT_ADDR(base) ((base) + (0x009c))
#define SOC_VDEC_WATERMARK_START_POS_CNT_ADDR(base) ((base) + (0x00A0))
#define SOC_VDEC_WATERMARK_END_POS_CNT_ADDR(base) ((base) + (0x00A4))
#define SOC_VDEC_SAFE_INT_STATE_ADDR(base) ((base) + (0x00A8))
#define SOC_VDEC_SAFE_INT_MASK_ADDR(base) ((base) + (0x00AC))
#define SOC_VDEC_VDH_DEC_CYCLEPERPIC_ADDR(base) ((base) + (0x00B0))
#define SOC_VDEC_VDH_RD_BDWIDTH_PERPIC_ADDR(base) ((base) + (0x00B4))
#define SOC_VDEC_VDH_WR_BDWIDTH_PERPIC_ADDR(base) ((base) + (0x00B8))
#define SOC_VDEC_VDH_RD_REQ_PERPIC_ADDR(base) ((base) + (0x00BC))
#define SOC_VDEC_VDH_WR_REQ_PERPIC_ADDR(base) ((base) + (0x00C0))
#define SOC_VDEC_UV_STRIDE_1D_ADDR(base) ((base) + (0x00C4))
#define SOC_VDEC_CFGINFO_ADDR_ADDR(base) ((base) + (0x00C8))
#define SOC_VDEC_VIDEO_STANDARD_EN_ADDR(base) ((base) + (0x00CC))
#define SOC_VDEC_MB0_QP_IN_CURR_PIC_ADDR(base) ((base) + (0x00D0))
#define SOC_VDEC_SWITCH_ROUNDING_ADDR(base) ((base) + (0x00D4))
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_L_ADDR(base) ((base) + (0x00D8))
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_H_ADDR(base) ((base) + (0x00DC))
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_L_ADDR(base) ((base) + (0x00E0))
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_H_ADDR(base) ((base) + (0x00E4))
#define SOC_VDEC_EMAR_STATE2_ADDR(base) ((base) + (0x00E8))
#define SOC_VDEC_EMAR_STATE3_ADDR(base) ((base) + (0x00EC))
#define SOC_VDEC_EMAR_STATE4_ADDR(base) ((base) + (0x00F0))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_SED_STA_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_SED_MBXY_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_SED_FSTMB_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_SED_LSTMB_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_SED_STATE2_0(H264) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(MPEG2) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(DIVX3) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(MPEG4) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(H265) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(H264) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(VP9) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(RV) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE2_1(AVS) _ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SED_STATE1_0(VP9) _ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_SED_STATE1_0(H265) _ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_SED_STATE0_0(REAL) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SED_STATE0_1(DIVX3) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SED_STATE0_2(VPX) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SED_STATE0_3(HEVC) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SED_STATE0_4(VP9) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SED_MB_CNT_0_ADDR(base) ((base) + (0x001CUL))
#define SOC_VDEC_SED_RESIDUAL_CNT(others) _ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_SED_CTB_CNT_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_SED_BSINV_CNT(others) _ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_VP9_CU_CNT_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_SED_HEAD_CNT(Others) _ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_SED_PU_CNT_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_SED_RESIDUAL_NUM(others) _ADDR(base) ((base) + (0x002CUL))
#define SOC_VDEC_SED_COEF_CNT_ADDR(base) ((base) + (0x002CUL))
#define SOC_VDEC_SED_SPRESIDUAL_NUM(Others) _ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_HEVC_T_TREE_CNT_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_VP9_TU_CNT_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_HEVC_ITRANS_CNT_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_VP9_COEF_SEND_WAIT_CNT_ADDR(base) ((base) + (0x00034UL))
#define SOC_VDEC_HEVC_CU_WRIT_TOP_CNT(HEVC) _ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_VP9_PU_HP_WAIT_CNT_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_HEVC_SEND_WAIT_CNT_ADDR(base) ((base) + (0x003CUL))
#define SOC_VDEC_HEVC_SE_DEC_CNT_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_HEVC_RGU_DEC_CNT_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_HEVC_BYPASS_DEC_CNT_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_HEVC_TERM_DEC_CNT_ADDR(base) ((base) + (0x004CUL))
#define SOC_VDEC_BIT_NUM_CNT_ADDR(base) ((base) + (0x0050UL))
#define SOC_VDEC_VPSSINFO_READ0_ADDR(base) ((base) + (0x0054UL))
#define SOC_VDEC_VPSSINFO_READ1_ADDR(base) ((base) + (0x0058UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK0_ADDR(base) ((base) + (0x0080UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK1_ADDR(base) ((base) + (0x0084UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK2_ADDR(base) ((base) + (0x0088UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK3_ADDR(base) ((base) + (0x008cUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK4_ADDR(base) ((base) + (0x0090UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK5_ADDR(base) ((base) + (0x0094UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK6_ADDR(base) ((base) + (0x0098UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK7_ADDR(base) ((base) + (0x009cUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK8_ADDR(base) ((base) + (0x00a0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK9_ADDR(base) ((base) + (0x00a4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK10_ADDR(base) ((base) + (0x00a8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK11_ADDR(base) ((base) + (0x00acUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK12_ADDR(base) ((base) + (0x00b0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK13_ADDR(base) ((base) + (0x00b4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK14_ADDR(base) ((base) + (0x00b8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK15_ADDR(base) ((base) + (0x00bcUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK16_ADDR(base) ((base) + (0x00c0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK17_ADDR(base) ((base) + (0x00c4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK18_ADDR(base) ((base) + (0x00c8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK19_ADDR(base) ((base) + (0x00ccUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK20_ADDR(base) ((base) + (0x00d0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK21_ADDR(base) ((base) + (0x00d4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK22_ADDR(base) ((base) + (0x00d8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK23_ADDR(base) ((base) + (0x00dcUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK24_ADDR(base) ((base) + (0x00e0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK25_ADDR(base) ((base) + (0x00e4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK26_ADDR(base) ((base) + (0x00e8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK27_ADDR(base) ((base) + (0x00ecUL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK28_ADDR(base) ((base) + (0x00f0UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK29_ADDR(base) ((base) + (0x00f4UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK30_ADDR(base) ((base) + (0x00f8UL))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK31_ADDR(base) ((base) + (0x00fcUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK0_ADDR(base) ((base) + (0x0100UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK1_ADDR(base) ((base) + (0x0104UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK2_ADDR(base) ((base) + (0x0108UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK3_ADDR(base) ((base) + (0x010cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK4_ADDR(base) ((base) + (0x0110UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK5_ADDR(base) ((base) + (0x0114UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK6_ADDR(base) ((base) + (0x0118UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK7_ADDR(base) ((base) + (0x011cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK8_ADDR(base) ((base) + (0x0120UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK9_ADDR(base) ((base) + (0x0124UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK10_ADDR(base) ((base) + (0x0128UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK11_ADDR(base) ((base) + (0x012cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK12_ADDR(base) ((base) + (0x0130UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK13_ADDR(base) ((base) + (0x0134UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK14_ADDR(base) ((base) + (0x0138UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK15_ADDR(base) ((base) + (0x013cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK16_ADDR(base) ((base) + (0x0140UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK17_ADDR(base) ((base) + (0x0144UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK18_ADDR(base) ((base) + (0x0148UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK19_ADDR(base) ((base) + (0x014cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK20_ADDR(base) ((base) + (0x0150UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK21_ADDR(base) ((base) + (0x0154UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK22_ADDR(base) ((base) + (0x0158UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK23_ADDR(base) ((base) + (0x015cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK24_ADDR(base) ((base) + (0x0160UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK25_ADDR(base) ((base) + (0x0164UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK26_ADDR(base) ((base) + (0x0168UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK27_ADDR(base) ((base) + (0x016cUL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK28_ADDR(base) ((base) + (0x0170UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK29_ADDR(base) ((base) + (0x0174UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK30_ADDR(base) ((base) + (0x0178UL))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK31_ADDR(base) ((base) + (0x017cUL))
#else
#define SOC_VDEC_SED_STA_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_SED_MBXY_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_SED_FSTMB_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_SED_LSTMB_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_SED_STATE2_0(H264) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(MPEG2) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(DIVX3) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(MPEG4) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(H265) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(H264) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(VP9) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(RV) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE2_1(AVS) _ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SED_STATE1_0(VP9) _ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_SED_STATE1_0(H265) _ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_SED_STATE0_0(REAL) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SED_STATE0_1(DIVX3) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SED_STATE0_2(VPX) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SED_STATE0_3(HEVC) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SED_STATE0_4(VP9) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SED_MB_CNT_0_ADDR(base) ((base) + (0x001C))
#define SOC_VDEC_SED_RESIDUAL_CNT(others) _ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_SED_CTB_CNT_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_SED_BSINV_CNT(others) _ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_VP9_CU_CNT_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_SED_HEAD_CNT(Others) _ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_SED_PU_CNT_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_SED_RESIDUAL_NUM(others) _ADDR(base) ((base) + (0x002C))
#define SOC_VDEC_SED_COEF_CNT_ADDR(base) ((base) + (0x002C))
#define SOC_VDEC_SED_SPRESIDUAL_NUM(Others) _ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_HEVC_T_TREE_CNT_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_VP9_TU_CNT_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_HEVC_ITRANS_CNT_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_VP9_COEF_SEND_WAIT_CNT_ADDR(base) ((base) + (0x00034))
#define SOC_VDEC_HEVC_CU_WRIT_TOP_CNT(HEVC) _ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_VP9_PU_HP_WAIT_CNT_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_HEVC_SEND_WAIT_CNT_ADDR(base) ((base) + (0x003C))
#define SOC_VDEC_HEVC_SE_DEC_CNT_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_HEVC_RGU_DEC_CNT_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_HEVC_BYPASS_DEC_CNT_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_HEVC_TERM_DEC_CNT_ADDR(base) ((base) + (0x004C))
#define SOC_VDEC_BIT_NUM_CNT_ADDR(base) ((base) + (0x0050))
#define SOC_VDEC_VPSSINFO_READ0_ADDR(base) ((base) + (0x0054))
#define SOC_VDEC_VPSSINFO_READ1_ADDR(base) ((base) + (0x0058))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK0_ADDR(base) ((base) + (0x0080))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK1_ADDR(base) ((base) + (0x0084))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK2_ADDR(base) ((base) + (0x0088))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK3_ADDR(base) ((base) + (0x008c))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK4_ADDR(base) ((base) + (0x0090))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK5_ADDR(base) ((base) + (0x0094))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK6_ADDR(base) ((base) + (0x0098))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK7_ADDR(base) ((base) + (0x009c))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK8_ADDR(base) ((base) + (0x00a0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK9_ADDR(base) ((base) + (0x00a4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK10_ADDR(base) ((base) + (0x00a8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK11_ADDR(base) ((base) + (0x00ac))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK12_ADDR(base) ((base) + (0x00b0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK13_ADDR(base) ((base) + (0x00b4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK14_ADDR(base) ((base) + (0x00b8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK15_ADDR(base) ((base) + (0x00bc))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK16_ADDR(base) ((base) + (0x00c0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK17_ADDR(base) ((base) + (0x00c4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK18_ADDR(base) ((base) + (0x00c8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK19_ADDR(base) ((base) + (0x00cc))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK20_ADDR(base) ((base) + (0x00d0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK21_ADDR(base) ((base) + (0x00d4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK22_ADDR(base) ((base) + (0x00d8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK23_ADDR(base) ((base) + (0x00dc))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK24_ADDR(base) ((base) + (0x00e0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK25_ADDR(base) ((base) + (0x00e4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK26_ADDR(base) ((base) + (0x00e8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK27_ADDR(base) ((base) + (0x00ec))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK28_ADDR(base) ((base) + (0x00f0))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK29_ADDR(base) ((base) + (0x00f4))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK30_ADDR(base) ((base) + (0x00f8))
#define SOC_VDEC_SED_STRM_BUF0_RDBCK31_ADDR(base) ((base) + (0x00fc))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK0_ADDR(base) ((base) + (0x0100))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK1_ADDR(base) ((base) + (0x0104))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK2_ADDR(base) ((base) + (0x0108))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK3_ADDR(base) ((base) + (0x010c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK4_ADDR(base) ((base) + (0x0110))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK5_ADDR(base) ((base) + (0x0114))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK6_ADDR(base) ((base) + (0x0118))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK7_ADDR(base) ((base) + (0x011c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK8_ADDR(base) ((base) + (0x0120))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK9_ADDR(base) ((base) + (0x0124))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK10_ADDR(base) ((base) + (0x0128))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK11_ADDR(base) ((base) + (0x012c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK12_ADDR(base) ((base) + (0x0130))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK13_ADDR(base) ((base) + (0x0134))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK14_ADDR(base) ((base) + (0x0138))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK15_ADDR(base) ((base) + (0x013c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK16_ADDR(base) ((base) + (0x0140))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK17_ADDR(base) ((base) + (0x0144))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK18_ADDR(base) ((base) + (0x0148))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK19_ADDR(base) ((base) + (0x014c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK20_ADDR(base) ((base) + (0x0150))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK21_ADDR(base) ((base) + (0x0154))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK22_ADDR(base) ((base) + (0x0158))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK23_ADDR(base) ((base) + (0x015c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK24_ADDR(base) ((base) + (0x0160))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK25_ADDR(base) ((base) + (0x0164))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK26_ADDR(base) ((base) + (0x0168))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK27_ADDR(base) ((base) + (0x016c))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK28_ADDR(base) ((base) + (0x0170))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK29_ADDR(base) ((base) + (0x0174))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK30_ADDR(base) ((base) + (0x0178))
#define SOC_VDEC_SED_STRM_BUF1_RDBCK31_ADDR(base) ((base) + (0x017c))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_EMAR_STATE_0_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_EMAR_STATE_1_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_EMAR_STATE_2_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_EMAR_STATE_3_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_EMAR_STATE_4_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_EMAR_STATE_5_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_EMAR_STATE_6_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_EMAR_STATE_7_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_EMAR_STATE_8_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_EMAR_STATE_9_ADDR(base) ((base) + (0x0024UL))
#else
#define SOC_VDEC_EMAR_STATE_0_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_EMAR_STATE_1_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_EMAR_STATE_2_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_EMAR_STATE_3_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_EMAR_STATE_4_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_EMAR_STATE_5_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_EMAR_STATE_6_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_EMAR_STATE_7_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_EMAR_STATE_8_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_EMAR_STATE_9_ADDR(base) ((base) + (0x0024))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_ITRANS_INFO_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_ITR_ADDR_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_ITR_INF_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_ITR_STA_0_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_ITR_STA_1_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_IS_FRM_CYCLE_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_AHS_FRM_CYCLE_ADDR(base) ((base) + (0x001cUL))
#else
#define SOC_VDEC_ITRANS_INFO_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_ITR_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_ITR_INF_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_ITR_STA_0_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_ITR_STA_1_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_IS_FRM_CYCLE_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_AHS_FRM_CYCLE_ADDR(base) ((base) + (0x001c))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_PMV_STATE0_0_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_PMV_STATE0_1_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_PMV_STATE1_0_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_PMV_STATE1_1_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_PMV_CYCLE_CNT_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_PMV_STATE_2 (H265)_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_PMV_STATE_2 (VP9)_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_PMV_STATE_3 (H265)_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_PMV_STATE_3 (VP9)_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_0_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_PMV_STATE_4 (H265)_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_PMV_STATE_4 (VP9)_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_1_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_PMV_STATE_5_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_2_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_PMV_STATE_6(H265) _ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_PMV_STATE_6 (VP9)_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_3_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_4_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_5_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_6_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_7_ADDR(base) ((base) + (0x002cUL))
#else
#define SOC_VDEC_PMV_STATE0_0_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_PMV_STATE0_1_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_PMV_STATE1_0_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_PMV_STATE1_1_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_PMV_CYCLE_CNT_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_PMV_STATE_2 (H265)_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_PMV_STATE_2 (VP9)_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_PMV_STATE_3 (H265)_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_PMV_STATE_3 (VP9)_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_0_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_PMV_STATE_4 (H265)_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_PMV_STATE_4 (VP9)_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_1_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_PMV_STATE_5_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_2_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_PMV_STATE_6(H265) _ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_PMV_STATE_6 (VP9)_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_3_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_4_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_5_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_6_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_7_ADDR(base) ((base) + (0x002c))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_MB_INF_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_CACHE0_TOTAL_CNT_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_CACHE0_HIT_CNT_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_CACHE0_REQHIT_CNT_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_CACHE0_MISS_CNT_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_CACHE0_FE_WORK_TIME_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_CACHE1_TOTAL_CNT_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_CACHE1_HIT_CNT_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_CACHE1_REQHIT_CNT_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_CACHE1_MISS_CNT_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_CACHE1_FE_WORK_TIME_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_PRC_STATE_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_PRC_BUF_STATE0_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_OUT_STATE &#10;_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_FMT_STATE_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_L_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_H_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_L_ADDR(base) ((base) + (0x004cUL))
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_H_ADDR(base) ((base) + (0x0050UL))
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT_ADDR(base) ((base) + (0x0054UL))
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT_ADDR(base) ((base) + (0x0058UL))
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT1_ADDR(base) ((base) + (0x005cUL))
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT1_ADDR(base) ((base) + (0x0060UL))
#define SOC_VDEC_DCMP_IP_ERROR_ADDR(base) ((base) + (0x0064UL))
#else
#define SOC_VDEC_MB_INF_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_CACHE0_TOTAL_CNT_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_CACHE0_HIT_CNT_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_CACHE0_REQHIT_CNT_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_CACHE0_MISS_CNT_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_CACHE0_FE_WORK_TIME_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_CACHE1_TOTAL_CNT_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_CACHE1_HIT_CNT_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_CACHE1_REQHIT_CNT_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_CACHE1_MISS_CNT_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_CACHE1_FE_WORK_TIME_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_PRC_STATE_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_PRC_BUF_STATE0_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_OUT_STATE &#10;_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_FMT_STATE_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_L_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_H_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_L_ADDR(base) ((base) + (0x004c))
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_H_ADDR(base) ((base) + (0x0050))
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT_ADDR(base) ((base) + (0x0054))
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT_ADDR(base) ((base) + (0x0058))
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT1_ADDR(base) ((base) + (0x005c))
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT1_ADDR(base) ((base) + (0x0060))
#define SOC_VDEC_DCMP_IP_ERROR_ADDR(base) ((base) + (0x0064))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_PRF_INFO_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_PRF_STATE_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_PRF_IBUF_ST_ADDR(base) ((base) + (0x0008UL))
#else
#define SOC_VDEC_PRF_INFO_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_PRF_STATE_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_PRF_IBUF_ST_ADDR(base) ((base) + (0x0008))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_RCN_PIC_PARA_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_RCN_MB_PARA_0_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_RCN_MB_PARA_1_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_RCN_MB_PARA_2_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_RCN_MB_PARA_3_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_RCN_MB_PARA_4_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_RCN_MB_PARA_5_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_RCN_MB_PARA_6_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_RCN_BUF_STATE_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_RCN_MB_NUM_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_RCN_CTB_NUM_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_RCN_MB_PART_7_ADDR(base) ((base) + (0x002CUL))
#define SOC_VDEC_RCN_FSM_STATE_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_RCN_PRF_STATE_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_RCN_VP9_INFO_ADDR(base) ((base) + (0x0038UL))
#else
#define SOC_VDEC_RCN_PIC_PARA_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_RCN_MB_PARA_0_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_RCN_MB_PARA_1_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_RCN_MB_PARA_2_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_RCN_MB_PARA_3_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_RCN_MB_PARA_4_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_RCN_MB_PARA_5_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_RCN_MB_PARA_6_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_RCN_BUF_STATE_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_RCN_MB_NUM_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_RCN_CTB_NUM_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_RCN_MB_PART_7_ADDR(base) ((base) + (0x002C))
#define SOC_VDEC_RCN_FSM_STATE_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_RCN_PRF_STATE_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_RCN_VP9_INFO_ADDR(base) ((base) + (0x0038))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_DBLK_PIC_INFO_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_DBLK_FLT_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_DBLK_DDR_STRD_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_DBLK_YADDR_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_DBLK_CADDR_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_DBLK_ST_TOP_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_DBLK_ST_TA_CTRL_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_DBLK_ST_DI_CTRL_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_DBLK_ST_DF_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_DBLK_ST_DO_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_DBLK_IBUFFER_STATE_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_DBLK2CMP_STATE_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_OBUFFER_STATE_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT0_ADDR(base) ((base) + (0x0100UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT1_ADDR(base) ((base) + (0x0104UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT2_ADDR(base) ((base) + (0x0108UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT3_ADDR(base) ((base) + (0x010cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT4_ADDR(base) ((base) + (0x0110UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT5_ADDR(base) ((base) + (0x0114UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT6_ADDR(base) ((base) + (0x0118UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT7_ADDR(base) ((base) + (0x011cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT8_ADDR(base) ((base) + (0x0120UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT9_ADDR(base) ((base) + (0x0124UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT10_ADDR(base) ((base) + (0x0128UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT11_ADDR(base) ((base) + (0x012cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT12_ADDR(base) ((base) + (0x0130UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT13_ADDR(base) ((base) + (0x0134UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT14_ADDR(base) ((base) + (0x0138UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT15_ADDR(base) ((base) + (0x013cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT16_ADDR(base) ((base) + (0x0140UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT17_ADDR(base) ((base) + (0x0144UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT18_ADDR(base) ((base) + (0x0148UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT19_ADDR(base) ((base) + (0x014cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT20_ADDR(base) ((base) + (0x0150UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT21_ADDR(base) ((base) + (0x0154UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT22_ADDR(base) ((base) + (0x0158UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT23_ADDR(base) ((base) + (0x015cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT24_ADDR(base) ((base) + (0x0160UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT25_ADDR(base) ((base) + (0x0164UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT26_ADDR(base) ((base) + (0x0168UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT27_ADDR(base) ((base) + (0x016cUL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT28_ADDR(base) ((base) + (0x0170UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT29_ADDR(base) ((base) + (0x0174UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT30_ADDR(base) ((base) + (0x0178UL))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT31_ADDR(base) ((base) + (0x017cUL))
#define SOC_VDEC_LUMA_SUM0_ADDR(base) ((base) + (0x0180UL))
#define SOC_VDEC_LUMA_SUM1_ADDR(base) ((base) + (0x0184UL))
#define SOC_VDEC_DBLK_MEM_INFO_ADDR(base) ((base) + (0x0400~0x053fUL))
#define SOC_VDEC_DBLK_MEM_PIX0_ADDR(base) ((base) + (0x0800~0x097fUL))
#define SOC_VDEC_DBLK_MEM_PIX1_ADDR(base) ((base) + (0x0c00~0x0d7fUL))
#else
#define SOC_VDEC_DBLK_PIC_INFO_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_DBLK_FLT_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_DBLK_DDR_STRD_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_DBLK_YADDR_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_DBLK_CADDR_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_DBLK_ST_TOP_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_DBLK_ST_TA_CTRL_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_DBLK_ST_DI_CTRL_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_DBLK_ST_DF_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_DBLK_ST_DO_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_DBLK_IBUFFER_STATE_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_DBLK2CMP_STATE_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_OBUFFER_STATE_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT0_ADDR(base) ((base) + (0x0100))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT1_ADDR(base) ((base) + (0x0104))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT2_ADDR(base) ((base) + (0x0108))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT3_ADDR(base) ((base) + (0x010c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT4_ADDR(base) ((base) + (0x0110))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT5_ADDR(base) ((base) + (0x0114))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT6_ADDR(base) ((base) + (0x0118))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT7_ADDR(base) ((base) + (0x011c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT8_ADDR(base) ((base) + (0x0120))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT9_ADDR(base) ((base) + (0x0124))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT10_ADDR(base) ((base) + (0x0128))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT11_ADDR(base) ((base) + (0x012c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT12_ADDR(base) ((base) + (0x0130))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT13_ADDR(base) ((base) + (0x0134))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT14_ADDR(base) ((base) + (0x0138))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT15_ADDR(base) ((base) + (0x013c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT16_ADDR(base) ((base) + (0x0140))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT17_ADDR(base) ((base) + (0x0144))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT18_ADDR(base) ((base) + (0x0148))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT19_ADDR(base) ((base) + (0x014c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT20_ADDR(base) ((base) + (0x0150))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT21_ADDR(base) ((base) + (0x0154))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT22_ADDR(base) ((base) + (0x0158))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT23_ADDR(base) ((base) + (0x015c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT24_ADDR(base) ((base) + (0x0160))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT25_ADDR(base) ((base) + (0x0164))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT26_ADDR(base) ((base) + (0x0168))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT27_ADDR(base) ((base) + (0x016c))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT28_ADDR(base) ((base) + (0x0170))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT29_ADDR(base) ((base) + (0x0174))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT30_ADDR(base) ((base) + (0x0178))
#define SOC_VDEC_LUMA_HISTOGRAM_CNT31_ADDR(base) ((base) + (0x017c))
#define SOC_VDEC_LUMA_SUM0_ADDR(base) ((base) + (0x0180))
#define SOC_VDEC_LUMA_SUM1_ADDR(base) ((base) + (0x0184))
#define SOC_VDEC_DBLK_MEM_INFO_ADDR(base) ((base) + (0x0400~0x053f))
#define SOC_VDEC_DBLK_MEM_PIX0_ADDR(base) ((base) + (0x0800~0x097f))
#define SOC_VDEC_DBLK_MEM_PIX1_ADDR(base) ((base) + (0x0c00~0x0d7f))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_SAO_RD_BACK_REG0_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_SAO_RD_BACK_REG1_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_SAO_RD_BACK_REG2_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_SAO_RD_BACK_REG3_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_SAO_RD_BACK_REG4_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_SAO_RD_BACK_REG5_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_SAO_RD_BACK_REG6_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SAO_RD_BACK_REG7_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_SAO_RD_BACK_REG8_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_SAO_RD_BACK_REG9_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_SAO_RD_BACK_REG10_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_SAO_RD_BACK_REG11_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_SAO_RD_BACK_REG12_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_SAO_RD_BACK_REG13_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_SAO_RD_BACK_REG14_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_SAO_RD_BACK_REG15_ADDR(base) ((base) + (0x003CUL))
#define SOC_VDEC_SAO_RD_BACK_REG16_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_SAO_RD_BACK_REG17_ADDR(base) ((base) + (0x0044UL))
#else
#define SOC_VDEC_SAO_RD_BACK_REG0_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_SAO_RD_BACK_REG1_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_SAO_RD_BACK_REG2_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_SAO_RD_BACK_REG3_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_SAO_RD_BACK_REG4_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_SAO_RD_BACK_REG5_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_SAO_RD_BACK_REG6_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SAO_RD_BACK_REG7_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_SAO_RD_BACK_REG8_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_SAO_RD_BACK_REG9_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_SAO_RD_BACK_REG10_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_SAO_RD_BACK_REG11_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_SAO_RD_BACK_REG12_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_SAO_RD_BACK_REG13_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_SAO_RD_BACK_REG14_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_SAO_RD_BACK_REG15_ADDR(base) ((base) + (0x003C))
#define SOC_VDEC_SAO_RD_BACK_REG16_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_SAO_RD_BACK_REG17_ADDR(base) ((base) + (0x0044))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_SRC_LUMA_ADDR_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_SRC_CHROMA_ADDR_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_DST_LUMA_ADDR_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_DST_CHROMA_ADDR_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_DATA_STRIDE_8BIT_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_HEAD_INF_OFFSET_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_PIC_IN_MB_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_TOTAL_GRP_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_START_MB_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_END_MB_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_IN_MB_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_SEND_MB_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_DMA_CMD_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_CNT0_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_CNT1_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_DATA_STRIDE_2BIT_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_YOFFSET_2BIT_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_UVOFFSET_2BIT_ADDR(base) ((base) + (0x0044UL))
#else
#define SOC_VDEC_SRC_LUMA_ADDR_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_SRC_CHROMA_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_DST_LUMA_ADDR_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_DST_CHROMA_ADDR_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_DATA_STRIDE_8BIT_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_HEAD_INF_OFFSET_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_PIC_IN_MB_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_TOTAL_GRP_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_START_MB_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_END_MB_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_IN_MB_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_SEND_MB_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_DMA_CMD_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_CNT0_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_CNT1_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_DATA_STRIDE_2BIT_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_YOFFSET_2BIT_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_UVOFFSET_2BIT_ADDR(base) ((base) + (0x0044))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_CMP_YSTADDR_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_CMP_UVOFFSET_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_CMP_YSTRIDE_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_CMP_LINE_NUM_STADDR_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_CMP_LINE_LEVEL_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_CMP_PIC_INFO_H265_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_CMP_PIC_PIX_INFO_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_CMP_BITDEPTH_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_CMP_HEAD_INF_SIZE_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_CMP_WATERMARK_START_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_CMP_WATERMARK_END_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_CMP_YOFFSET_2BIT_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_CMP_UVOFFSET_2BIT_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_CMP_STATE_MACHINE_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_CMP_DEFAULT_ADDR(base) ((base) + (0x004cUL))
#else
#define SOC_VDEC_CMP_YSTADDR_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_CMP_UVOFFSET_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_CMP_YSTRIDE_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_CMP_LINE_NUM_STADDR_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_CMP_LINE_LEVEL_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_CMP_PIC_INFO_H265_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_CMP_PIC_PIX_INFO_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_CMP_BITDEPTH_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_CMP_HEAD_INF_SIZE_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_CMP_WATERMARK_START_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_CMP_WATERMARK_END_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_CMP_YOFFSET_2BIT_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_CMP_UVOFFSET_2BIT_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_CMP_STATE_MACHINE_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_CMP_DEFAULT_ADDR(base) ((base) + (0x004c))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_SCD_START_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_LIST_ADDRESS_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_UP_ADDRESS_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_UP_LEN_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_BUFFER_FIRST_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_BUFFER_LAST_ADDR(base) ((base) + (0x0014UL))
#define SOC_VDEC_BUFFER_INI_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_SCD_NORM_INT_MASK_ADDR(base) ((base) + (0x001cUL))
#define SOC_VDEC_SCD__PROTOCOL_ADDR(base) ((base) + (0x0020UL))
#define SOC_VDEC_SCD_NORM_INI_CLR_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_DSP_SPS_ADDR_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_DSP_PPS_ADDR_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_DSP_MSG_ADDR_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_DSP_TOP_ADDR_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_DSP_CAMN_ADDR_ADDR(base) ((base) + (0x0038UL))
#define SOC_VDEC_SCD_PREVIOUS_LSB_ADDR(base) ((base) + (0x003cUL))
#define SOC_VDEC_SCD_INT_FLAG_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_SCD_PREVIOUS_MSB_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_SCD_BYTE_VALID_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_SCD_NUMBER_ADDR(base) ((base) + (0x004cUL))
#define SOC_VDEC_RLL_ADDR_ADDR(base) ((base) + (0x0050UL))
#define SOC_VDEC_SCR_RAT_ADDR(base) ((base) + (0x0054UL))
#define SOC_VDEC_SCR_OFFSET_ADDR(base) ((base) + (0x0058UL))
#define SOC_VDEC_SCR_NXT_ADDR_ADDR(base) ((base) + (0x005cUL))
#define SOC_VDEC_STA_ADDR(base) ((base) + (0x0060UL))
#define SOC_VDEC_SDWR_ADDR(base) ((base) + (0x0064UL))
#define SOC_VDEC_RUN_CYCLE_ADDR(base) ((base) + (0x0068UL))
#define SOC_VDEC_SCD_RD_REQ_ADDR(base) ((base) + (0x006cUL))
#define SOC_VDEC_SCD_RD_DAT_ADDR(base) ((base) + (0x0070UL))
#define SOC_VDEC_SCD_WR_REQ_ADDR(base) ((base) + (0x0074UL))
#define SOC_VDEC_SCD_WR_DAT_ADDR(base) ((base) + (0x0078UL))
#define SOC_VDEC_SCD_WORK_ST_ADDR(base) ((base) + (0x007cUL))
#define SOC_VDEC_SCD_CLK_CFG_ADDR(base) ((base) + (0x0080UL))
#define SOC_VDEC_SCD_ARBIT_DG0_ADDR(base) ((base) + (0x0084UL))
#define SOC_VDEC_SCD_ARBIT_DG1_ADDR(base) ((base) + (0x0088UL))
#define SOC_VDEC_SCD_ARBIT_DG2_ADDR(base) ((base) + (0x008cUL))
#define SOC_VDEC_SCD_ARBIT_DG3_ADDR(base) ((base) + (0x0090UL))
#define SOC_VDEC_SCD_SOFTRST_DG0_ADDR(base) ((base) + (0x0094UL))
#define SOC_VDEC_SCD_SOFTRST_DG1_ADDR(base) ((base) + (0x0098UL))
#define SOC_VDEC_SCD_SAFE_INT_MASK_ADDR(base) ((base) + (0x00c4UL))
#define SOC_VDEC_SCD_SAFE_INI_CLR_ADDR(base) ((base) + (0x00c8UL))
#else
#define SOC_VDEC_SCD_START_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_LIST_ADDRESS_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_UP_ADDRESS_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_UP_LEN_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_BUFFER_FIRST_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_BUFFER_LAST_ADDR(base) ((base) + (0x0014))
#define SOC_VDEC_BUFFER_INI_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_SCD_NORM_INT_MASK_ADDR(base) ((base) + (0x001c))
#define SOC_VDEC_SCD__PROTOCOL_ADDR(base) ((base) + (0x0020))
#define SOC_VDEC_SCD_NORM_INI_CLR_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_DSP_SPS_ADDR_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_DSP_PPS_ADDR_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_DSP_MSG_ADDR_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_DSP_TOP_ADDR_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_DSP_CAMN_ADDR_ADDR(base) ((base) + (0x0038))
#define SOC_VDEC_SCD_PREVIOUS_LSB_ADDR(base) ((base) + (0x003c))
#define SOC_VDEC_SCD_INT_FLAG_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_SCD_PREVIOUS_MSB_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_SCD_BYTE_VALID_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_SCD_NUMBER_ADDR(base) ((base) + (0x004c))
#define SOC_VDEC_RLL_ADDR_ADDR(base) ((base) + (0x0050))
#define SOC_VDEC_SCR_RAT_ADDR(base) ((base) + (0x0054))
#define SOC_VDEC_SCR_OFFSET_ADDR(base) ((base) + (0x0058))
#define SOC_VDEC_SCR_NXT_ADDR_ADDR(base) ((base) + (0x005c))
#define SOC_VDEC_STA_ADDR(base) ((base) + (0x0060))
#define SOC_VDEC_SDWR_ADDR(base) ((base) + (0x0064))
#define SOC_VDEC_RUN_CYCLE_ADDR(base) ((base) + (0x0068))
#define SOC_VDEC_SCD_RD_REQ_ADDR(base) ((base) + (0x006c))
#define SOC_VDEC_SCD_RD_DAT_ADDR(base) ((base) + (0x0070))
#define SOC_VDEC_SCD_WR_REQ_ADDR(base) ((base) + (0x0074))
#define SOC_VDEC_SCD_WR_DAT_ADDR(base) ((base) + (0x0078))
#define SOC_VDEC_SCD_WORK_ST_ADDR(base) ((base) + (0x007c))
#define SOC_VDEC_SCD_CLK_CFG_ADDR(base) ((base) + (0x0080))
#define SOC_VDEC_SCD_ARBIT_DG0_ADDR(base) ((base) + (0x0084))
#define SOC_VDEC_SCD_ARBIT_DG1_ADDR(base) ((base) + (0x0088))
#define SOC_VDEC_SCD_ARBIT_DG2_ADDR(base) ((base) + (0x008c))
#define SOC_VDEC_SCD_ARBIT_DG3_ADDR(base) ((base) + (0x0090))
#define SOC_VDEC_SCD_SOFTRST_DG0_ADDR(base) ((base) + (0x0094))
#define SOC_VDEC_SCD_SOFTRST_DG1_ADDR(base) ((base) + (0x0098))
#define SOC_VDEC_SCD_SAFE_INT_MASK_ADDR(base) ((base) + (0x00c4))
#define SOC_VDEC_SCD_SAFE_INI_CLR_ADDR(base) ((base) + (0x00c8))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_AVS_PLUS_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_EMAR_ADDR_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_VDH_RST_EN_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_CK_GT_EN_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_VDH_USE_STATE_ADDR(base) ((base) + (0x0010UL))
#define SOC_VDEC_OVER_TIME_ADDR(base) ((base) + (0x0018UL))
#define SOC_VDEC_VDH_ARQOS_ADDR(base) ((base) + (0x0024UL))
#define SOC_VDEC_VDH_ARQOS_CYCLE_ADDR(base) ((base) + (0x0028UL))
#define SOC_VDEC_VDH_ARQOS_NUMBERS_ADDR(base) ((base) + (0x002cUL))
#define SOC_VDEC_EMAR_ADDR1_ADDR(base) ((base) + (0x0030UL))
#define SOC_VDEC_VDH_FORCE_REQ_ACK_ADDR(base) ((base) + (0x0034UL))
#define SOC_VDEC_VDH_RFS_EMA_ADDR(base) ((base) + (0x0070UL))
#define SOC_VDEC_VDH_RFT_EMA_ADDR(base) ((base) + (0x0074UL))
#define SOC_VDEC_VDH_ROM_EMA_ADDR(base) ((base) + (0x0078UL))
#else
#define SOC_VDEC_AVS_PLUS_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_EMAR_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_VDH_RST_EN_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_CK_GT_EN_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_VDH_USE_STATE_ADDR(base) ((base) + (0x0010))
#define SOC_VDEC_OVER_TIME_ADDR(base) ((base) + (0x0018))
#define SOC_VDEC_VDH_ARQOS_ADDR(base) ((base) + (0x0024))
#define SOC_VDEC_VDH_ARQOS_CYCLE_ADDR(base) ((base) + (0x0028))
#define SOC_VDEC_VDH_ARQOS_NUMBERS_ADDR(base) ((base) + (0x002c))
#define SOC_VDEC_EMAR_ADDR1_ADDR(base) ((base) + (0x0030))
#define SOC_VDEC_VDH_FORCE_REQ_ACK_ADDR(base) ((base) + (0x0034))
#define SOC_VDEC_VDH_RFS_EMA_ADDR(base) ((base) + (0x0070))
#define SOC_VDEC_VDH_RFT_EMA_ADDR(base) ((base) + (0x0074))
#define SOC_VDEC_VDH_ROM_EMA_ADDR(base) ((base) + (0x0078))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_VDH_CLKSEL_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_VDHAPB_CLKSEL_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_VDH_SRST_REQ_ADDR(base) ((base) + (0x000CUL))
#define SOC_VDEC_VDH_SRST_ST_ADDR(base) ((base) + (0x0010UL))
#else
#define SOC_VDEC_VDH_CLKSEL_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_VDHAPB_CLKSEL_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_VDH_SRST_REQ_ADDR(base) ((base) + (0x000C))
#define SOC_VDEC_VDH_SRST_ST_ADDR(base) ((base) + (0x0010))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VDEC_EMAR_OUTSANDING_ADDR(base) ((base) + (0x0000UL))
#define SOC_VDEC_ALL_R_MID_RRMAX_ADDR(base) ((base) + (0x0004UL))
#define SOC_VDEC_R_BG_ADJUST_ADDR(base) ((base) + (0x0008UL))
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_ADDR(base) ((base) + (0x000cUL))
#define SOC_VDEC_ALL_R_MID_INFO_ADDR(base) ((base) + (0x0040UL))
#define SOC_VDEC_ALL_W_MID_INFO_ADDR(base) ((base) + (0x0044UL))
#define SOC_VDEC_AXI_SOFTRST_STATE0_ADDR(base) ((base) + (0x0048UL))
#define SOC_VDEC_AXI_SOFTRST_STATE1_ADDR(base) ((base) + (0x004cUL))
#else
#define SOC_VDEC_EMAR_OUTSANDING_ADDR(base) ((base) + (0x0000))
#define SOC_VDEC_ALL_R_MID_RRMAX_ADDR(base) ((base) + (0x0004))
#define SOC_VDEC_R_BG_ADJUST_ADDR(base) ((base) + (0x0008))
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_ADDR(base) ((base) + (0x000c))
#define SOC_VDEC_ALL_R_MID_INFO_ADDR(base) ((base) + (0x0040))
#define SOC_VDEC_ALL_W_MID_INFO_ADDR(base) ((base) + (0x0044))
#define SOC_VDEC_AXI_SOFTRST_STATE0_ADDR(base) ((base) + (0x0048))
#define SOC_VDEC_AXI_SOFTRST_STATE1_ADDR(base) ((base) + (0x004c))
#endif
#ifndef __SOC_H_FOR_ASM__
#else
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_VDH_START_CNT_UNION;
#endif
#define SOC_VDEC_VDH_START_CNT_dec_start_START (0)
#define SOC_VDEC_VDH_START_CNT_dec_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_VDH_REPAIR_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mbamt_to_dec : 20;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int marker_bit_detect_en : 1;
        unsigned int ac_last_detect_en : 1;
        unsigned int coef_idx_detect_en : 1;
        unsigned int vop_type_detect_en : 1;
        unsigned int work_mode : 2;
        unsigned int luma_sum_en : 1;
        unsigned int luma_histogram_en : 1;
        unsigned int ld_qmatrix_flag : 1;
        unsigned int vdh_safe_flag : 1;
    } reg;
} SOC_VDEC_BASIC_CFG0_CNT_UNION;
#endif
#define SOC_VDEC_BASIC_CFG0_CNT_mbamt_to_dec_START (0)
#define SOC_VDEC_BASIC_CFG0_CNT_mbamt_to_dec_END (19)
#define SOC_VDEC_BASIC_CFG0_CNT_marker_bit_detect_en_START (22)
#define SOC_VDEC_BASIC_CFG0_CNT_marker_bit_detect_en_END (22)
#define SOC_VDEC_BASIC_CFG0_CNT_ac_last_detect_en_START (23)
#define SOC_VDEC_BASIC_CFG0_CNT_ac_last_detect_en_END (23)
#define SOC_VDEC_BASIC_CFG0_CNT_coef_idx_detect_en_START (24)
#define SOC_VDEC_BASIC_CFG0_CNT_coef_idx_detect_en_END (24)
#define SOC_VDEC_BASIC_CFG0_CNT_vop_type_detect_en_START (25)
#define SOC_VDEC_BASIC_CFG0_CNT_vop_type_detect_en_END (25)
#define SOC_VDEC_BASIC_CFG0_CNT_work_mode_START (26)
#define SOC_VDEC_BASIC_CFG0_CNT_work_mode_END (27)
#define SOC_VDEC_BASIC_CFG0_CNT_luma_sum_en_START (28)
#define SOC_VDEC_BASIC_CFG0_CNT_luma_sum_en_END (28)
#define SOC_VDEC_BASIC_CFG0_CNT_luma_histogram_en_START (29)
#define SOC_VDEC_BASIC_CFG0_CNT_luma_histogram_en_END (29)
#define SOC_VDEC_BASIC_CFG0_CNT_ld_qmatrix_flag_START (30)
#define SOC_VDEC_BASIC_CFG0_CNT_ld_qmatrix_flag_END (30)
#define SOC_VDEC_BASIC_CFG0_CNT_vdh_safe_flag_START (31)
#define SOC_VDEC_BASIC_CFG0_CNT_vdh_safe_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int video_standard : 4;
        unsigned int ddr_stride_reserved : 8;
        unsigned int mfd_mmu_en : 1;
        unsigned int uv_order_en : 1;
        unsigned int fst_slc_grp : 1;
        unsigned int mv_output_en : 1;
        unsigned int max_slcgrp_num : 12;
        unsigned int line_num_oen : 1;
        unsigned int dblk_1d_en : 1;
        unsigned int compress_en : 1;
        unsigned int ppfd_en : 1;
    } reg;
} SOC_VDEC_BASIC_CFG1_CNT_UNION;
#endif
#define SOC_VDEC_BASIC_CFG1_CNT_video_standard_START (0)
#define SOC_VDEC_BASIC_CFG1_CNT_video_standard_END (3)
#define SOC_VDEC_BASIC_CFG1_CNT_ddr_stride_reserved_START (4)
#define SOC_VDEC_BASIC_CFG1_CNT_ddr_stride_reserved_END (11)
#define SOC_VDEC_BASIC_CFG1_CNT_mfd_mmu_en_START (12)
#define SOC_VDEC_BASIC_CFG1_CNT_mfd_mmu_en_END (12)
#define SOC_VDEC_BASIC_CFG1_CNT_uv_order_en_START (13)
#define SOC_VDEC_BASIC_CFG1_CNT_uv_order_en_END (13)
#define SOC_VDEC_BASIC_CFG1_CNT_fst_slc_grp_START (14)
#define SOC_VDEC_BASIC_CFG1_CNT_fst_slc_grp_END (14)
#define SOC_VDEC_BASIC_CFG1_CNT_mv_output_en_START (15)
#define SOC_VDEC_BASIC_CFG1_CNT_mv_output_en_END (15)
#define SOC_VDEC_BASIC_CFG1_CNT_max_slcgrp_num_START (16)
#define SOC_VDEC_BASIC_CFG1_CNT_max_slcgrp_num_END (27)
#define SOC_VDEC_BASIC_CFG1_CNT_line_num_oen_START (28)
#define SOC_VDEC_BASIC_CFG1_CNT_line_num_oen_END (28)
#define SOC_VDEC_BASIC_CFG1_CNT_dblk_1d_en_START (29)
#define SOC_VDEC_BASIC_CFG1_CNT_dblk_1d_en_END (29)
#define SOC_VDEC_BASIC_CFG1_CNT_compress_en_START (30)
#define SOC_VDEC_BASIC_CFG1_CNT_compress_en_END (30)
#define SOC_VDEC_BASIC_CFG1_CNT_ppfd_en_START (31)
#define SOC_VDEC_BASIC_CFG1_CNT_ppfd_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int av_msg_addr : 28;
    } reg;
} SOC_VDEC_AVM_ADDR_CNT_UNION;
#endif
#define SOC_VDEC_AVM_ADDR_CNT_av_msg_addr_START (4)
#define SOC_VDEC_AVM_ADDR_CNT_av_msg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int va_msg_addr : 28;
    } reg;
} SOC_VDEC_VAM_ADDR_CNT_UNION;
#endif
#define SOC_VDEC_VAM_ADDR_CNT_va_msg_addr_START (4)
#define SOC_VDEC_VAM_ADDR_CNT_va_msg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int stream_base_addr : 28;
    } reg;
} SOC_VDEC_STREAM_BASE_ADDR_CNT_UNION;
#endif
#define SOC_VDEC_STREAM_BASE_ADDR_CNT_stream_base_addr_START (4)
#define SOC_VDEC_STREAM_BASE_ADDR_CNT_stream_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decoded_slice_num : 17;
        unsigned int intrs_vdh_dec_over : 1;
        unsigned int intrs_vdh_dec_err : 1;
        unsigned int intrs_vdh_part_dec_over : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_VDH_STATE_CNT_UNION;
#endif
#define SOC_VDEC_VDH_STATE_CNT_decoded_slice_num_START (0)
#define SOC_VDEC_VDH_STATE_CNT_decoded_slice_num_END (16)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_dec_over_START (17)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_dec_over_END (17)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_dec_err_START (18)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_dec_err_END (18)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_part_dec_over_START (19)
#define SOC_VDEC_VDH_STATE_CNT_intrs_vdh_part_dec_over_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int norm_intrms_vdh_dec_over : 1;
        unsigned int norm_intrms_vdh_dec_err : 1;
        unsigned int norm_intrms_vdh_part_dec_over : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_VDEC_NORM_INT_STATE_UNION;
#endif
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_dec_over_START (0)
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_dec_over_END (0)
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_dec_err_START (1)
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_dec_err_END (1)
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_part_dec_over_START (2)
#define SOC_VDEC_NORM_INT_STATE_norm_intrms_vdh_part_dec_over_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int norm_intm_vdh_dec_over : 1;
        unsigned int norm_intm_vdh_dec_err : 1;
        unsigned int norm_intm_vdh_part_dec_over : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_VDEC_NORM_INT_MASK_UNION;
#endif
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_dec_over_START (0)
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_dec_over_END (0)
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_dec_err_START (1)
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_dec_err_END (1)
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_part_dec_over_START (2)
#define SOC_VDEC_NORM_INT_MASK_norm_intm_vdh_part_dec_over_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vctrl_state : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VDEC_VCTRL_STATE_CNT_UNION;
#endif
#define SOC_VDEC_VCTRL_STATE_CNT_vctrl_state_START (0)
#define SOC_VDEC_VCTRL_STATE_CNT_vctrl_state_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_version_id : 32;
    } reg;
} SOC_VDEC_VDH_VERSION_ID_UNION;
#endif
#define SOC_VDEC_VDH_VERSION_ID_vdh_version_id_START (0)
#define SOC_VDEC_VDH_VERSION_ID_vdh_version_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Uv_dcmp_rate_mode : 2;
        unsigned int y_dcmp_rate_mode : 2;
        unsigned int mb_offset_thr : 4;
        unsigned int Lst_msq_mb_num : 4;
        unsigned int vdh_cmp_thr_reserved : 20;
    } reg;
} SOC_VDEC_CFMW_REG_CMP_THR_UNION;
#endif
#define SOC_VDEC_CFMW_REG_CMP_THR_Uv_dcmp_rate_mode_START (0)
#define SOC_VDEC_CFMW_REG_CMP_THR_Uv_dcmp_rate_mode_END (1)
#define SOC_VDEC_CFMW_REG_CMP_THR_y_dcmp_rate_mode_START (2)
#define SOC_VDEC_CFMW_REG_CMP_THR_y_dcmp_rate_mode_END (3)
#define SOC_VDEC_CFMW_REG_CMP_THR_mb_offset_thr_START (4)
#define SOC_VDEC_CFMW_REG_CMP_THR_mb_offset_thr_END (7)
#define SOC_VDEC_CFMW_REG_CMP_THR_Lst_msq_mb_num_START (8)
#define SOC_VDEC_CFMW_REG_CMP_THR_Lst_msq_mb_num_END (11)
#define SOC_VDEC_CFMW_REG_CMP_THR_vdh_cmp_thr_reserved_START (12)
#define SOC_VDEC_CFMW_REG_CMP_THR_vdh_cmp_thr_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_cnt_dblk_rd : 5;
        unsigned int max_cnt_dblk_wr : 5;
        unsigned int max_cnt_prc : 5;
        unsigned int max_cnt_other : 5;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_RPT_CNT_CNT_UNION;
#endif
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_dblk_rd_START (0)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_dblk_rd_END (4)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_dblk_wr_START (5)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_dblk_wr_END (9)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_prc_START (10)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_prc_END (14)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_other_START (15)
#define SOC_VDEC_RPT_CNT_CNT_max_cnt_other_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vctrl_rd_to : 10;
        unsigned int vctrl_wr_to : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_VCTRL_TO_CNT_UNION;
#endif
#define SOC_VDEC_VCTRL_TO_CNT_vctrl_rd_to_START (0)
#define SOC_VDEC_VCTRL_TO_CNT_vctrl_rd_to_END (9)
#define SOC_VDEC_VCTRL_TO_CNT_vctrl_wr_to_START (10)
#define SOC_VDEC_VCTRL_TO_CNT_vctrl_wr_to_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_rd_stream_to : 10;
        unsigned int sed_rd_top_to : 10;
        unsigned int sed_wr_top_to : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_VDEC_SED_TO_CNT_UNION;
#endif
#define SOC_VDEC_SED_TO_CNT_sed_rd_stream_to_START (0)
#define SOC_VDEC_SED_TO_CNT_sed_rd_stream_to_END (9)
#define SOC_VDEC_SED_TO_CNT_sed_rd_top_to_START (10)
#define SOC_VDEC_SED_TO_CNT_sed_rd_top_to_END (19)
#define SOC_VDEC_SED_TO_CNT_sed_wr_top_to_START (20)
#define SOC_VDEC_SED_TO_CNT_sed_wr_top_to_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int it_rd_to : 10;
        unsigned int it_wr_to : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_IT_TO_CNT_UNION;
#endif
#define SOC_VDEC_IT_TO_CNT_it_rd_to_START (0)
#define SOC_VDEC_IT_TO_CNT_it_rd_to_END (9)
#define SOC_VDEC_IT_TO_CNT_it_wr_to_START (10)
#define SOC_VDEC_IT_TO_CNT_it_wr_to_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmv_rd_col_to : 10;
        unsigned int pmv_rd_top_to : 10;
        unsigned int pmv_wr_to : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_VDEC_PMV_TO_CNT_UNION;
#endif
#define SOC_VDEC_PMV_TO_CNT_pmv_rd_col_to_START (0)
#define SOC_VDEC_PMV_TO_CNT_pmv_rd_col_to_END (9)
#define SOC_VDEC_PMV_TO_CNT_pmv_rd_top_to_START (10)
#define SOC_VDEC_PMV_TO_CNT_pmv_rd_top_to_END (19)
#define SOC_VDEC_PMV_TO_CNT_pmv_wr_to_START (20)
#define SOC_VDEC_PMV_TO_CNT_pmv_wr_to_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prc_rd_to : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VDEC_PRC_TO_CNT_UNION;
#endif
#define SOC_VDEC_PRC_TO_CNT_prc_rd_to_START (0)
#define SOC_VDEC_PRC_TO_CNT_prc_rd_to_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_rd_to : 10;
        unsigned int rcn_wr_to : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_RCN_TO_CNT_UNION;
#endif
#define SOC_VDEC_RCN_TO_CNT_rcn_rd_to_START (0)
#define SOC_VDEC_RCN_TO_CNT_rcn_rd_to_END (9)
#define SOC_VDEC_RCN_TO_CNT_rcn_wr_to_START (10)
#define SOC_VDEC_RCN_TO_CNT_rcn_wr_to_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_rd_to : 10;
        unsigned int dblk_wr_to : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_DBLK_TO_CNT_UNION;
#endif
#define SOC_VDEC_DBLK_TO_CNT_dblk_rd_to_START (0)
#define SOC_VDEC_DBLK_TO_CNT_dblk_rd_to_END (9)
#define SOC_VDEC_DBLK_TO_CNT_dblk_wr_to_START (10)
#define SOC_VDEC_DBLK_TO_CNT_dblk_wr_to_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ppfd_rd_slice_to : 10;
        unsigned int ppfd_rd_buf_to : 10;
        unsigned int ppfd_wr_buf_to : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_VDEC_PPFD_TO_CNT_UNION;
#endif
#define SOC_VDEC_PPFD_TO_CNT_ppfd_rd_slice_to_START (0)
#define SOC_VDEC_PPFD_TO_CNT_ppfd_rd_slice_to_END (9)
#define SOC_VDEC_PPFD_TO_CNT_ppfd_rd_buf_to_START (10)
#define SOC_VDEC_PPFD_TO_CNT_ppfd_rd_buf_to_END (19)
#define SOC_VDEC_PPFD_TO_CNT_ppfd_wr_buf_to_START (20)
#define SOC_VDEC_PPFD_TO_CNT_ppfd_wr_buf_to_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fpga_version_id : 32;
    } reg;
} SOC_VDEC_FPGA_VERSION_UNION;
#endif
#define SOC_VDEC_FPGA_VERSION_fpga_version_id_START (0)
#define SOC_VDEC_FPGA_VERSION_fpga_version_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_over_int_level : 32;
    } reg;
} SOC_VDEC_PART_OVER_INT_LEVEL_UNION;
#endif
#define SOC_VDEC_PART_OVER_INT_LEVEL_part_over_int_level_START (0)
#define SOC_VDEC_PART_OVER_INT_LEVEL_part_over_int_level_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ystaddr_1d : 32;
    } reg;
} SOC_VDEC_YSTADDR_1D_CNT_UNION;
#endif
#define SOC_VDEC_YSTADDR_1D_CNT_ystaddr_1d_START (0)
#define SOC_VDEC_YSTADDR_1D_CNT_ystaddr_1d_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int ystride_1d : 16;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_VDEC_YSTRIDE_1D_CNT_UNION;
#endif
#define SOC_VDEC_YSTRIDE_1D_CNT_ystride_1d_START (4)
#define SOC_VDEC_YSTRIDE_1D_CNT_ystride_1d_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvoffset_1d : 32;
    } reg;
} SOC_VDEC_UVOFFSET_1D_CNT_UNION;
#endif
#define SOC_VDEC_UVOFFSET_1D_CNT_uvoffset_1d_START (0)
#define SOC_VDEC_UVOFFSET_1D_CNT_uvoffset_1d_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Head_offset : 32;
    } reg;
} SOC_VDEC_HEAD_OFFSET_CNT_UNION;
#endif
#define SOC_VDEC_HEAD_OFFSET_CNT_Head_offset_START (0)
#define SOC_VDEC_HEAD_OFFSET_CNT_Head_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int line_num_staddr : 32;
    } reg;
} SOC_VDEC_LINE_NUM_STADDR_CNT_UNION;
#endif
#define SOC_VDEC_LINE_NUM_STADDR_CNT_line_num_staddr_START (0)
#define SOC_VDEC_LINE_NUM_STADDR_CNT_line_num_staddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int yoffset_2bit : 32;
    } reg;
} SOC_VDEC_YOFFSET_2BIT_CNT_UNION;
#endif
#define SOC_VDEC_YOFFSET_2BIT_CNT_yoffset_2bit_START (0)
#define SOC_VDEC_YOFFSET_2BIT_CNT_yoffset_2bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvoffset_2bit : 32;
    } reg;
} SOC_VDEC_UVOFFSET_2BIT_CNT_UNION;
#endif
#define SOC_VDEC_UVOFFSET_2BIT_CNT_uvoffset_2bit_START (0)
#define SOC_VDEC_UVOFFSET_2BIT_CNT_uvoffset_2bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int ppfd_buf_addr : 28;
    } reg;
} SOC_VDEC_PPFD_BUF_ADDR_CNT_UNION;
#endif
#define SOC_VDEC_PPFD_BUF_ADDR_CNT_ppfd_buf_addr_START (4)
#define SOC_VDEC_PPFD_BUF_ADDR_CNT_ppfd_buf_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ppfd_buf_len : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_VDEC_PPFD_BUF_LEN_CNT_UNION;
#endif
#define SOC_VDEC_PPFD_BUF_LEN_CNT_ppfd_buf_len_START (0)
#define SOC_VDEC_PPFD_BUF_LEN_CNT_ppfd_buf_len_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_pic_type : 2;
        unsigned int ref_pic_type_rev : 30;
    } reg;
} SOC_VDEC_REF_PIC_TYPE_CNT_UNION;
#endif
#define SOC_VDEC_REF_PIC_TYPE_CNT_ref_pic_type_START (0)
#define SOC_VDEC_REF_PIC_TYPE_CNT_ref_pic_type_END (1)
#define SOC_VDEC_REF_PIC_TYPE_CNT_ref_pic_type_rev_START (2)
#define SOC_VDEC_REF_PIC_TYPE_CNT_ref_pic_type_rev_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pic_cache_type : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_PIC_CACHE_TYPE_UNION;
#endif
#define SOC_VDEC_PIC_CACHE_TYPE_pic_cache_type_START (0)
#define SOC_VDEC_PIC_CACHE_TYPE_pic_cache_type_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Sed_domn_clk_cfg : 2;
        unsigned int itrans_domn_clk_cfg : 2;
        unsigned int pmv_domn_clk_cfg : 2;
        unsigned int prc_domn_clk_cfg : 2;
        unsigned int prf_domn_clk_cfg : 2;
        unsigned int rcn_domn_clk_cfg : 2;
        unsigned int dblk_domn_clk_cfg : 2;
        unsigned int Sao_domn_clk_cfg : 2;
        unsigned int Cmp_domn_clk_cfg : 2;
        unsigned int Vctrl_domn_clk_cfg : 2;
        unsigned int Vpss_domn_clk_cfg : 2;
        unsigned int domn_clk_cfg_cnt_rev : 10;
    } reg;
} SOC_VDEC_DOMN_CLK_CFG_CNT_UNION;
#endif
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Sed_domn_clk_cfg_START (0)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Sed_domn_clk_cfg_END (1)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_itrans_domn_clk_cfg_START (2)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_itrans_domn_clk_cfg_END (3)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_pmv_domn_clk_cfg_START (4)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_pmv_domn_clk_cfg_END (5)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_prc_domn_clk_cfg_START (6)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_prc_domn_clk_cfg_END (7)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_prf_domn_clk_cfg_START (8)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_prf_domn_clk_cfg_END (9)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_rcn_domn_clk_cfg_START (10)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_rcn_domn_clk_cfg_END (11)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_dblk_domn_clk_cfg_START (12)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_dblk_domn_clk_cfg_END (13)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Sao_domn_clk_cfg_START (14)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Sao_domn_clk_cfg_END (15)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Cmp_domn_clk_cfg_START (16)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Cmp_domn_clk_cfg_END (17)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Vctrl_domn_clk_cfg_START (18)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Vctrl_domn_clk_cfg_END (19)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Vpss_domn_clk_cfg_START (20)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_Vpss_domn_clk_cfg_END (21)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_domn_clk_cfg_cnt_rev_START (22)
#define SOC_VDEC_DOMN_CLK_CFG_CNT_domn_clk_cfg_cnt_rev_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int watermark_start_pos : 32;
    } reg;
} SOC_VDEC_WATERMARK_START_POS_CNT_UNION;
#endif
#define SOC_VDEC_WATERMARK_START_POS_CNT_watermark_start_pos_START (0)
#define SOC_VDEC_WATERMARK_START_POS_CNT_watermark_start_pos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int watermark_end_pos : 32;
    } reg;
} SOC_VDEC_WATERMARK_END_POS_CNT_UNION;
#endif
#define SOC_VDEC_WATERMARK_END_POS_CNT_watermark_end_pos_START (0)
#define SOC_VDEC_WATERMARK_END_POS_CNT_watermark_end_pos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int safe_intrms_vdh_dec_over : 1;
        unsigned int safe_intrms_vdh_dec_err : 1;
        unsigned int safe_intrms_vdh_part_dec_over : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_VDEC_SAFE_INT_STATE_UNION;
#endif
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_dec_over_START (0)
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_dec_over_END (0)
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_dec_err_START (1)
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_dec_err_END (1)
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_part_dec_over_START (2)
#define SOC_VDEC_SAFE_INT_STATE_safe_intrms_vdh_part_dec_over_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int safe_intm_vdh_dec_over : 1;
        unsigned int safe_intm_vdh_dec_err : 1;
        unsigned int safe_intm_vdh_part_dec_over : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_VDEC_SAFE_INT_MASK_UNION;
#endif
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_dec_over_START (0)
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_dec_over_END (0)
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_dec_err_START (1)
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_dec_err_END (1)
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_part_dec_over_START (2)
#define SOC_VDEC_SAFE_INT_MASK_safe_intm_vdh_part_dec_over_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_cycleperpic : 32;
    } reg;
} SOC_VDEC_VDH_DEC_CYCLEPERPIC_UNION;
#endif
#define SOC_VDEC_VDH_DEC_CYCLEPERPIC_dec_cycleperpic_START (0)
#define SOC_VDEC_VDH_DEC_CYCLEPERPIC_dec_cycleperpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_bdwidth_perpic : 32;
    } reg;
} SOC_VDEC_VDH_RD_BDWIDTH_PERPIC_UNION;
#endif
#define SOC_VDEC_VDH_RD_BDWIDTH_PERPIC_rd_bdwidth_perpic_START (0)
#define SOC_VDEC_VDH_RD_BDWIDTH_PERPIC_rd_bdwidth_perpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_bdwidth_perpic : 32;
    } reg;
} SOC_VDEC_VDH_WR_BDWIDTH_PERPIC_UNION;
#endif
#define SOC_VDEC_VDH_WR_BDWIDTH_PERPIC_wr_bdwidth_perpic_START (0)
#define SOC_VDEC_VDH_WR_BDWIDTH_PERPIC_wr_bdwidth_perpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_req_perpic : 32;
    } reg;
} SOC_VDEC_VDH_RD_REQ_PERPIC_UNION;
#endif
#define SOC_VDEC_VDH_RD_REQ_PERPIC_rd_req_perpic_START (0)
#define SOC_VDEC_VDH_RD_REQ_PERPIC_rd_req_perpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_req_perpic : 32;
    } reg;
} SOC_VDEC_VDH_WR_REQ_PERPIC_UNION;
#endif
#define SOC_VDEC_VDH_WR_REQ_PERPIC_wr_req_perpic_START (0)
#define SOC_VDEC_VDH_WR_REQ_PERPIC_wr_req_perpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 3;
        unsigned int uv_stride_1d : 16;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_VDEC_UV_STRIDE_1D_UNION;
#endif
#define SOC_VDEC_UV_STRIDE_1D_uv_stride_1d_START (3)
#define SOC_VDEC_UV_STRIDE_1D_uv_stride_1d_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfginfo_addr : 32;
    } reg;
} SOC_VDEC_CFGINFO_ADDR_UNION;
#endif
#define SOC_VDEC_CFGINFO_ADDR_cfginfo_addr_START (0)
#define SOC_VDEC_CFGINFO_ADDR_cfginfo_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int video_standard_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_VDEC_VIDEO_STANDARD_EN_UNION;
#endif
#define SOC_VDEC_VIDEO_STANDARD_EN_video_standard_en_START (0)
#define SOC_VDEC_VIDEO_STANDARD_EN_video_standard_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CurrPicMb0QP : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_VDEC_MB0_QP_IN_CURR_PIC_UNION;
#endif
#define SOC_VDEC_MB0_QP_IN_CURR_PIC_CurrPicMb0QP_START (0)
#define SOC_VDEC_MB0_QP_IN_CURR_PIC_CurrPicMb0QP_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SwitchRounding : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SWITCH_ROUNDING_UNION;
#endif
#define SOC_VDEC_SWITCH_ROUNDING_SwitchRounding_START (0)
#define SOC_VDEC_SWITCH_ROUNDING_SwitchRounding_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cnt_total[31:0] : 32;
    } reg;
} SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_L_UNION;
#endif
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_L_rd_cnt_total [31:0]_START (0)
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_L_rd_cnt_total [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cnt_total[63:31] : 32;
    } reg;
} SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_H_UNION;
#endif
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_H_rd_cnt_total [63:31]_START (0)
#define SOC_VDEC_VDH_RD_REQ_CYCLE_PERPIC_H_rd_cnt_total [63:31]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cnt_total[31:0] : 32;
    } reg;
} SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_L_UNION;
#endif
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_L_wr_cnt_total [31:0]_START (0)
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_L_wr_cnt_total [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cnt_total[63:32] : 32;
    } reg;
} SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_H_UNION;
#endif
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_H_wr_cnt_total [63:32]_START (0)
#define SOC_VDEC_VDH_WR_REQ_CYCLE_PERPIC_H_wr_cnt_total [63:32]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emar_state2 : 32;
    } reg;
} SOC_VDEC_EMAR_STATE2_UNION;
#endif
#define SOC_VDEC_EMAR_STATE2_emar_state2_START (0)
#define SOC_VDEC_EMAR_STATE2_emar_state2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emar_state3 : 32;
    } reg;
} SOC_VDEC_EMAR_STATE3_UNION;
#endif
#define SOC_VDEC_EMAR_STATE3_emar_state3_START (0)
#define SOC_VDEC_EMAR_STATE3_emar_state3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emar_state4 : 32;
    } reg;
} SOC_VDEC_EMAR_STATE4_UNION;
#endif
#define SOC_VDEC_EMAR_STATE4_emar_state4_START (0)
#define SOC_VDEC_EMAR_STATE4_emar_state4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl2par_mb_rdy : 1;
        unsigned int ctl2par_slc_rdy : 1;
        unsigned int ctl2par_pic_rdy : 1;
        unsigned int ctl2par_err : 1;
        unsigned int ctl2par_top_sta : 11;
        unsigned int pmv2sed_tu_buf_full : 1;
        unsigned int pmv2sed_pu_buf_full : 1;
        unsigned int pmv2sed_cu_buf_full : 1;
        unsigned int pmv2sed_ctb_buf_full : 1;
        unsigned int pmv2se_buffer_full : 1;
        unsigned int it2se_buffer_full : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_VDEC_SED_STA_UNION;
#endif
#define SOC_VDEC_SED_STA_ctl2par_mb_rdy_START (0)
#define SOC_VDEC_SED_STA_ctl2par_mb_rdy_END (0)
#define SOC_VDEC_SED_STA_ctl2par_slc_rdy_START (1)
#define SOC_VDEC_SED_STA_ctl2par_slc_rdy_END (1)
#define SOC_VDEC_SED_STA_ctl2par_pic_rdy_START (2)
#define SOC_VDEC_SED_STA_ctl2par_pic_rdy_END (2)
#define SOC_VDEC_SED_STA_ctl2par_err_START (3)
#define SOC_VDEC_SED_STA_ctl2par_err_END (3)
#define SOC_VDEC_SED_STA_ctl2par_top_sta_START (4)
#define SOC_VDEC_SED_STA_ctl2par_top_sta_END (14)
#define SOC_VDEC_SED_STA_pmv2sed_tu_buf_full_START (15)
#define SOC_VDEC_SED_STA_pmv2sed_tu_buf_full_END (15)
#define SOC_VDEC_SED_STA_pmv2sed_pu_buf_full_START (16)
#define SOC_VDEC_SED_STA_pmv2sed_pu_buf_full_END (16)
#define SOC_VDEC_SED_STA_pmv2sed_cu_buf_full_START (17)
#define SOC_VDEC_SED_STA_pmv2sed_cu_buf_full_END (17)
#define SOC_VDEC_SED_STA_pmv2sed_ctb_buf_full_START (18)
#define SOC_VDEC_SED_STA_pmv2sed_ctb_buf_full_END (18)
#define SOC_VDEC_SED_STA_pmv2se_buffer_full_START (19)
#define SOC_VDEC_SED_STA_pmv2se_buffer_full_END (19)
#define SOC_VDEC_SED_STA_it2se_buffer_full_START (20)
#define SOC_VDEC_SED_STA_it2se_buffer_full_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int se2dpi_mbx : 9;
        unsigned int reserved_0 : 7;
        unsigned int se2dpi_mby : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_VDEC_SED_MBXY_UNION;
#endif
#define SOC_VDEC_SED_MBXY_se2dpi_mbx_START (0)
#define SOC_VDEC_SED_MBXY_se2dpi_mbx_END (8)
#define SOC_VDEC_SED_MBXY_se2dpi_mby_START (16)
#define SOC_VDEC_SED_MBXY_se2dpi_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int first_mb_num : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_SED_FSTMB_UNION;
#endif
#define SOC_VDEC_SED_FSTMB_first_mb_num_START (0)
#define SOC_VDEC_SED_FSTMB_first_mb_num_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_mb_num : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_SED_LSTMB_UNION;
#endif
#define SOC_VDEC_SED_LSTMB_last_mb_num_START (0)
#define SOC_VDEC_SED_LSTMB_last_mb_num_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mb_layer_state : 4;
        unsigned int residul_state : 3;
        unsigned int seg_luma4x4_state : 4;
        unsigned int luma4x4_b8_state : 3;
        unsigned int resblk_state : 3;
        unsigned int reserved : 11;
        unsigned int se_mvd_state : 4;
    } reg;
} SOC_VDEC_SED_STATE2_0(H264)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_0(H264) _mb_layer_state_START (0)
#define SOC_VDEC_SED_STATE2_0(H264) _mb_layer_state_END (3)
#define SOC_VDEC_SED_STATE2_0(H264) _residul_state_START (4)
#define SOC_VDEC_SED_STATE2_0(H264) _residul_state_END (6)
#define SOC_VDEC_SED_STATE2_0(H264) _seg_luma4x4_state_START (7)
#define SOC_VDEC_SED_STATE2_0(H264) _seg_luma4x4_state_END (10)
#define SOC_VDEC_SED_STATE2_0(H264) _luma4x4_b8_state_START (11)
#define SOC_VDEC_SED_STATE2_0(H264) _luma4x4_b8_state_END (13)
#define SOC_VDEC_SED_STATE2_0(H264) _resblk_state_START (14)
#define SOC_VDEC_SED_STATE2_0(H264) _resblk_state_END (16)
#define SOC_VDEC_SED_STATE2_0(H264) _se_mvd_state_START (28)
#define SOC_VDEC_SED_STATE2_0(H264) _se_mvd_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int macroblock_pattern : 1;
        unsigned int macroblock_forward : 1;
        unsigned int reserved : 6;
        unsigned int cur_sta_qpmode : 9;
        unsigned int mb_addr_incr : 11;
        unsigned int err_sta : 4;
    } reg;
} SOC_VDEC_SED_STATE2_1(MPEG2)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(MPEG2) _macroblock_pattern_START (0)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _macroblock_pattern_END (0)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _macroblock_forward_START (1)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _macroblock_forward_END (1)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _cur_sta_qpmode_START (8)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _cur_sta_qpmode_END (16)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _mb_addr_incr_START (17)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _mb_addr_incr_END (27)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _err_sta_START (28)
#define SOC_VDEC_SED_STATE2_1(MPEG2) _err_sta_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d3_coef_sta : 5;
        unsigned int d3_blk_sta : 7;
        unsigned int d3_mb_sta : 9;
        unsigned int d3_main_sta : 4;
        unsigned int cbp_cur : 6;
        unsigned int mb_type : 1;
    } reg;
} SOC_VDEC_SED_STATE2_1(DIVX3)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_coef_sta_START (0)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_coef_sta_END (4)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_blk_sta_START (5)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_blk_sta_END (11)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_mb_sta_START (12)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_mb_sta_END (20)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_main_sta_START (21)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _d3_main_sta_END (24)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _cbp_cur_START (25)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _cbp_cur_END (30)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _mb_type_START (31)
#define SOC_VDEC_SED_STATE2_1(DIVX3) _mb_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_sta_inlac : 4;
        unsigned int cur_sta_mv : 6;
        unsigned int cur_sta_mb : 10;
        unsigned int reserved : 8;
        unsigned int err_sta : 4;
    } reg;
} SOC_VDEC_SED_STATE2_1(MPEG4)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_inlac_START (0)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_inlac_END (3)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_mv_START (4)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_mv_END (9)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_mb_START (10)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _cur_sta_mb_END (19)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _err_sta_START (28)
#define SOC_VDEC_SED_STATE2_1(MPEG4) _err_sta_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Stacker1 : 4;
        unsigned int Stacker2 : 4;
        unsigned int Stacker3 : 4;
        unsigned int Stacker_ptr : 4;
        unsigned int Part_mode : 4;
        unsigned int Cu_pred_mode : 4;
        unsigned int scanidx : 4;
        unsigned int Cu_skip_flag : 1;
        unsigned int Pcm_flag : 1;
        unsigned int Repair_en : 1;
        unsigned int Rqt_root_cbf : 1;
    } reg;
} SOC_VDEC_SED_STATE2_1(H265)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker1_START (0)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker1_END (3)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker2_START (4)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker2_END (7)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker3_START (8)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker3_END (11)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker_ptr_START (12)
#define SOC_VDEC_SED_STATE2_1(H265) _Stacker_ptr_END (15)
#define SOC_VDEC_SED_STATE2_1(H265) _Part_mode_START (16)
#define SOC_VDEC_SED_STATE2_1(H265) _Part_mode_END (19)
#define SOC_VDEC_SED_STATE2_1(H265) _Cu_pred_mode_START (20)
#define SOC_VDEC_SED_STATE2_1(H265) _Cu_pred_mode_END (23)
#define SOC_VDEC_SED_STATE2_1(H265) _scanidx_START (24)
#define SOC_VDEC_SED_STATE2_1(H265) _scanidx_END (27)
#define SOC_VDEC_SED_STATE2_1(H265) _Cu_skip_flag_START (28)
#define SOC_VDEC_SED_STATE2_1(H265) _Cu_skip_flag_END (28)
#define SOC_VDEC_SED_STATE2_1(H265) _Pcm_flag_START (29)
#define SOC_VDEC_SED_STATE2_1(H265) _Pcm_flag_END (29)
#define SOC_VDEC_SED_STATE2_1(H265) _Repair_en_START (30)
#define SOC_VDEC_SED_STATE2_1(H265) _Repair_en_END (30)
#define SOC_VDEC_SED_STATE2_1(H265) _Rqt_root_cbf_START (31)
#define SOC_VDEC_SED_STATE2_1(H265) _Rqt_root_cbf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_err_state : 3;
        unsigned int prs_err_state : 3;
        unsigned int h4_err_state : 2;
        unsigned int submb_pred_cur_sta : 4;
        unsigned int mb_pred_cur_sta : 5;
        unsigned int h4_mb_cur_sta : 10;
        unsigned int h4_slc_cur_sta : 5;
    } reg;
} SOC_VDEC_SED_STATE2_1(H264)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(H264) _blk_err_state_START (0)
#define SOC_VDEC_SED_STATE2_1(H264) _blk_err_state_END (2)
#define SOC_VDEC_SED_STATE2_1(H264) _prs_err_state_START (3)
#define SOC_VDEC_SED_STATE2_1(H264) _prs_err_state_END (5)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_err_state_START (6)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_err_state_END (7)
#define SOC_VDEC_SED_STATE2_1(H264) _submb_pred_cur_sta_START (8)
#define SOC_VDEC_SED_STATE2_1(H264) _submb_pred_cur_sta_END (11)
#define SOC_VDEC_SED_STATE2_1(H264) _mb_pred_cur_sta_START (12)
#define SOC_VDEC_SED_STATE2_1(H264) _mb_pred_cur_sta_END (16)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_mb_cur_sta_START (17)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_mb_cur_sta_END (26)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_slc_cur_sta_START (27)
#define SOC_VDEC_SED_STATE2_1(H264) _h4_slc_cur_sta_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Stacker1 : 6;
        unsigned int Stacker2 : 6;
        unsigned int Stacker3 : 6;
        unsigned int Stacker_ptr : 2;
        unsigned int partition : 4;
        unsigned int sub_part_modev : 4;
        unsigned int Repair_en : 4;
    } reg;
} SOC_VDEC_SED_STATE2_1(VP9)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker1_START (0)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker1_END (5)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker2_START (6)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker2_END (11)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker3_START (12)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker3_END (17)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker_ptr_START (18)
#define SOC_VDEC_SED_STATE2_1(VP9) _Stacker_ptr_END (19)
#define SOC_VDEC_SED_STATE2_1(VP9) _partition_START (20)
#define SOC_VDEC_SED_STATE2_1(VP9) _partition_END (23)
#define SOC_VDEC_SED_STATE2_1(VP9) _sub_part_modev_START (24)
#define SOC_VDEC_SED_STATE2_1(VP9) _sub_part_modev_END (27)
#define SOC_VDEC_SED_STATE2_1(VP9) _Repair_en_START (28)
#define SOC_VDEC_SED_STATE2_1(VP9) _Repair_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mb0_qp_in_cur_pic : 5;
        unsigned int reserved_0 : 3;
        unsigned int rv_error_state : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_VDEC_SED_STATE2_1(RV)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(RV) _mb0_qp_in_cur_pic_START (0)
#define SOC_VDEC_SED_STATE2_1(RV) _mb0_qp_in_cur_pic_END (4)
#define SOC_VDEC_SED_STATE2_1(RV) _rv_error_state_START (8)
#define SOC_VDEC_SED_STATE2_1(RV) _rv_error_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk2ctl_blkcnt : 3;
        unsigned int cur_sta_cbpqp : 5;
        unsigned int cur_sta_mb : 8;
        unsigned int reserved : 7;
        unsigned int cur_sta_main : 5;
        unsigned int error_state : 4;
    } reg;
} SOC_VDEC_SED_STATE2_1(AVS)_UNION;
#endif
#define SOC_VDEC_SED_STATE2_1(AVS) _blk2ctl_blkcnt_START (0)
#define SOC_VDEC_SED_STATE2_1(AVS) _blk2ctl_blkcnt_END (2)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_cbpqp_START (3)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_cbpqp_END (7)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_mb_START (8)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_mb_END (15)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_main_START (23)
#define SOC_VDEC_SED_STATE2_1(AVS) _cur_sta_main_END (27)
#define SOC_VDEC_SED_STATE2_1(AVS) _error_state_START (28)
#define SOC_VDEC_SED_STATE2_1(AVS) _error_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_sta_debug[47:32] : 16;
        unsigned int sed_error : 1;
        unsigned int dpi2se_endofvop : 1;
        unsigned int reserved_0 : 3;
        unsigned int se2dpi_err_type : 8;
        unsigned int reserved_1 : 2;
        unsigned int se2dpi_err : 1;
    } reg;
} SOC_VDEC_SED_STATE1_0(VP9)_UNION;
#endif
#define SOC_VDEC_SED_STATE1_0(VP9) _vp9_sta_debug[47:32]_START (0)
#define SOC_VDEC_SED_STATE1_0(VP9) _vp9_sta_debug[47:32]_END (15)
#define SOC_VDEC_SED_STATE1_0(VP9) _sed_error_START (16)
#define SOC_VDEC_SED_STATE1_0(VP9) _sed_error_END (16)
#define SOC_VDEC_SED_STATE1_0(VP9) _dpi2se_endofvop_START (17)
#define SOC_VDEC_SED_STATE1_0(VP9) _dpi2se_endofvop_END (17)
#define SOC_VDEC_SED_STATE1_0(VP9) _se2dpi_err_type_START (21)
#define SOC_VDEC_SED_STATE1_0(VP9) _se2dpi_err_type_END (28)
#define SOC_VDEC_SED_STATE1_0(VP9) _se2dpi_err_START (31)
#define SOC_VDEC_SED_STATE1_0(VP9) _se2dpi_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_sta_debug[47:32] : 16;
        unsigned int sed_error : 1;
        unsigned int dpi2se_endofvop : 1;
        unsigned int reserved_0 : 3;
        unsigned int se2dpi_err_type : 8;
        unsigned int reserved_1 : 2;
        unsigned int se2dpi_err : 1;
    } reg;
} SOC_VDEC_SED_STATE1_0(H265)_UNION;
#endif
#define SOC_VDEC_SED_STATE1_0(H265) _hevc_sta_debug[47:32]_START (0)
#define SOC_VDEC_SED_STATE1_0(H265) _hevc_sta_debug[47:32]_END (15)
#define SOC_VDEC_SED_STATE1_0(H265) _sed_error_START (16)
#define SOC_VDEC_SED_STATE1_0(H265) _sed_error_END (16)
#define SOC_VDEC_SED_STATE1_0(H265) _dpi2se_endofvop_START (17)
#define SOC_VDEC_SED_STATE1_0(H265) _dpi2se_endofvop_END (17)
#define SOC_VDEC_SED_STATE1_0(H265) _se2dpi_err_type_START (21)
#define SOC_VDEC_SED_STATE1_0(H265) _se2dpi_err_type_END (28)
#define SOC_VDEC_SED_STATE1_0(H265) _se2dpi_err_START (31)
#define SOC_VDEC_SED_STATE1_0(H265) _se2dpi_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Se2dpi_sta_1 : 32;
    } reg;
} SOC_VDEC_SED_STATE0_0(REAL)_UNION;
#endif
#define SOC_VDEC_SED_STATE0_0(REAL) _Se2dpi_sta_1_START (0)
#define SOC_VDEC_SED_STATE0_0(REAL) _Se2dpi_sta_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Se2dpi_d3_switch_rounding : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SED_STATE0_1(DIVX3)_UNION;
#endif
#define SOC_VDEC_SED_STATE0_1(DIVX3) _Se2dpi_d3_switch_rounding_START (0)
#define SOC_VDEC_SED_STATE0_1(DIVX3) _Se2dpi_d3_switch_rounding_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Ctrl2par_last_num : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_VDEC_SED_STATE0_2(VPX)_UNION;
#endif
#define SOC_VDEC_SED_STATE0_2(VPX) _Ctrl2par_last_num_START (0)
#define SOC_VDEC_SED_STATE0_2(VPX) _Ctrl2par_last_num_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Cur_slice_st : 4;
        unsigned int Cur_sub_strm_st : 4;
        unsigned int Cur_ctb_st : 4;
        unsigned int Cur_q_tree : 4;
        unsigned int Cur_cu_st : 8;
        unsigned int Cur_pcm_st : 4;
        unsigned int Slice_type : 4;
    } reg;
} SOC_VDEC_SED_STATE0_3(HEVC)_UNION;
#endif
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_slice_st_START (0)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_slice_st_END (3)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_sub_strm_st_START (4)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_sub_strm_st_END (7)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_ctb_st_START (8)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_ctb_st_END (11)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_q_tree_START (12)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_q_tree_END (15)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_cu_st_START (16)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_cu_st_END (23)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_pcm_st_START (24)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Cur_pcm_st_END (27)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Slice_type_START (28)
#define SOC_VDEC_SED_STATE0_3(HEVC) _Slice_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_tile_st : 3;
        unsigned int cur_ctb_st : 3;
        unsigned int cur_cu_st : 4;
        unsigned int cur_intra_st : 3;
        unsigned int cur_inter_st : 4;
        unsigned int cur_mv_st : 3;
        unsigned int cur_mv_comp_st : 3;
        unsigned int cur_tu_st : 3;
        unsigned int cur_res_st : 4;
        unsigned int cur_send_st : 2;
    } reg;
} SOC_VDEC_SED_STATE0_4(VP9)_UNION;
#endif
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_tile_st_START (0)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_tile_st_END (2)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_ctb_st_START (3)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_ctb_st_END (5)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_cu_st_START (6)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_cu_st_END (9)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_intra_st_START (10)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_intra_st_END (12)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_inter_st_START (13)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_inter_st_END (16)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_mv_st_START (17)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_mv_st_END (19)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_mv_comp_st_START (20)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_mv_comp_st_END (22)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_tu_st_START (23)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_tu_st_END (25)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_res_st_START (26)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_res_st_END (29)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_send_st_START (30)
#define SOC_VDEC_SED_STATE0_4(VP9) _cur_send_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_performance_perpic : 32;
    } reg;
} SOC_VDEC_SED_MB_CNT_0_UNION;
#endif
#define SOC_VDEC_SED_MB_CNT_0_sed_performance_perpic_START (0)
#define SOC_VDEC_SED_MB_CNT_0_sed_performance_perpic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_residual_cnt : 32;
    } reg;
} SOC_VDEC_SED_RESIDUAL_CNT(others)_UNION;
#endif
#define SOC_VDEC_SED_RESIDUAL_CNT(others) _sed_residual_cnt_START (0)
#define SOC_VDEC_SED_RESIDUAL_CNT(others) _sed_residual_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_ctb_cnt : 32;
    } reg;
} SOC_VDEC_SED_CTB_CNT_UNION;
#endif
#define SOC_VDEC_SED_CTB_CNT_sed_ctb_cnt_START (0)
#define SOC_VDEC_SED_CTB_CNT_sed_ctb_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_bs_inv_cnt : 32;
    } reg;
} SOC_VDEC_SED_BSINV_CNT(others)_UNION;
#endif
#define SOC_VDEC_SED_BSINV_CNT(others) _sed_bs_inv_cnt_START (0)
#define SOC_VDEC_SED_BSINV_CNT(others) _sed_bs_inv_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_cu_cnt : 32;
    } reg;
} SOC_VDEC_VP9_CU_CNT_UNION;
#endif
#define SOC_VDEC_VP9_CU_CNT_vp9_cu_cnt_START (0)
#define SOC_VDEC_VP9_CU_CNT_vp9_cu_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_head_cnt : 32;
    } reg;
} SOC_VDEC_SED_HEAD_CNT(Others)_UNION;
#endif
#define SOC_VDEC_SED_HEAD_CNT(Others) _sed_head_cnt_START (0)
#define SOC_VDEC_SED_HEAD_CNT(Others) _sed_head_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_pu_cnt : 32;
    } reg;
} SOC_VDEC_SED_PU_CNT_UNION;
#endif
#define SOC_VDEC_SED_PU_CNT_sed_pu_cnt_START (0)
#define SOC_VDEC_SED_PU_CNT_sed_pu_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_residual_num : 32;
    } reg;
} SOC_VDEC_SED_RESIDUAL_NUM(others)_UNION;
#endif
#define SOC_VDEC_SED_RESIDUAL_NUM(others) _sed_residual_num_START (0)
#define SOC_VDEC_SED_RESIDUAL_NUM(others) _sed_residual_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_coeff_cnt : 32;
    } reg;
} SOC_VDEC_SED_COEF_CNT_UNION;
#endif
#define SOC_VDEC_SED_COEF_CNT_sed_coeff_cnt_START (0)
#define SOC_VDEC_SED_COEF_CNT_sed_coeff_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sed_spresidual_num : 32;
    } reg;
} SOC_VDEC_SED_SPRESIDUAL_NUM(Others)_UNION;
#endif
#define SOC_VDEC_SED_SPRESIDUAL_NUM(Others) _sed_spresidual_num_START (0)
#define SOC_VDEC_SED_SPRESIDUAL_NUM(Others) _sed_spresidual_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h5_t_tree_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_T_TREE_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_T_TREE_CNT_h5_t_tree_cnt_START (0)
#define SOC_VDEC_HEVC_T_TREE_CNT_h5_t_tree_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_tu_cnt : 32;
    } reg;
} SOC_VDEC_VP9_TU_CNT_UNION;
#endif
#define SOC_VDEC_VP9_TU_CNT_vp9_tu_cnt_START (0)
#define SOC_VDEC_VP9_TU_CNT_vp9_tu_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_itrans_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_ITRANS_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_ITRANS_CNT_hevc_itrans_cnt_START (0)
#define SOC_VDEC_HEVC_ITRANS_CNT_hevc_itrans_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_coef_send_wait_cnt : 32;
    } reg;
} SOC_VDEC_VP9_COEF_SEND_WAIT_CNT_UNION;
#endif
#define SOC_VDEC_VP9_COEF_SEND_WAIT_CNT_vp9_coef_send_wait_cnt_START (0)
#define SOC_VDEC_VP9_COEF_SEND_WAIT_CNT_vp9_coef_send_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_cu_write_top_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_CU_WRIT_TOP_CNT(HEVC)_UNION;
#endif
#define SOC_VDEC_HEVC_CU_WRIT_TOP_CNT(HEVC) _hevc_cu_write_top_cnt_START (0)
#define SOC_VDEC_HEVC_CU_WRIT_TOP_CNT(HEVC) _hevc_cu_write_top_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_pu_hp_wait_cnt : 32;
    } reg;
} SOC_VDEC_VP9_PU_HP_WAIT_CNT_UNION;
#endif
#define SOC_VDEC_VP9_PU_HP_WAIT_CNT_vp9_pu_hp_wait_cnt_START (0)
#define SOC_VDEC_VP9_PU_HP_WAIT_CNT_vp9_pu_hp_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_send_wait_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_SEND_WAIT_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_SEND_WAIT_CNT_hevc_send_wait_cnt_START (0)
#define SOC_VDEC_HEVC_SEND_WAIT_CNT_hevc_send_wait_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_se_dec_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_SE_DEC_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_SE_DEC_CNT_hevc_se_dec_cnt_START (0)
#define SOC_VDEC_HEVC_SE_DEC_CNT_hevc_se_dec_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_regular_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_RGU_DEC_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_RGU_DEC_CNT_hevc_regular_cnt_START (0)
#define SOC_VDEC_HEVC_RGU_DEC_CNT_hevc_regular_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_bypass_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_BYPASS_DEC_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_BYPASS_DEC_CNT_hevc_bypass_cnt_START (0)
#define SOC_VDEC_HEVC_BYPASS_DEC_CNT_hevc_bypass_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hevc_terminal_cnt : 32;
    } reg;
} SOC_VDEC_HEVC_TERM_DEC_CNT_UNION;
#endif
#define SOC_VDEC_HEVC_TERM_DEC_CNT_hevc_terminal_cnt_START (0)
#define SOC_VDEC_HEVC_TERM_DEC_CNT_hevc_terminal_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bit_num_cnt_total : 32;
    } reg;
} SOC_VDEC_BIT_NUM_CNT_UNION;
#endif
#define SOC_VDEC_BIT_NUM_CNT_bit_num_cnt_total_START (0)
#define SOC_VDEC_BIT_NUM_CNT_bit_num_cnt_total_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpssi2sed_read_info[31:0] : 32;
    } reg;
} SOC_VDEC_VPSSINFO_READ0_UNION;
#endif
#define SOC_VDEC_VPSSINFO_READ0_vpssi2sed_read_info [31:0]_START (0)
#define SOC_VDEC_VPSSINFO_READ0_vpssi2sed_read_info [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpssi2sed_read_info[63:32] : 32;
    } reg;
} SOC_VDEC_VPSSINFO_READ1_UNION;
#endif
#define SOC_VDEC_VPSSINFO_READ1_vpssi2sed_read_info [63:32]_START (0)
#define SOC_VDEC_VPSSINFO_READ1_vpssi2sed_read_info [63:32]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata0 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK0_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK0_Strm_buf0_rdata0_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK0_Strm_buf0_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata1 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK1_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK1_Strm_buf0_rdata1_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK1_Strm_buf0_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata2 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK2_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK2_Strm_buf0_rdata2_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK2_Strm_buf0_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata3 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK3_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK3_Strm_buf0_rdata3_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK3_Strm_buf0_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata4 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK4_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK4_Strm_buf0_rdata4_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK4_Strm_buf0_rdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata5 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK5_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK5_Strm_buf0_rdata5_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK5_Strm_buf0_rdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata6 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK6_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK6_Strm_buf0_rdata6_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK6_Strm_buf0_rdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata7 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK7_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK7_Strm_buf0_rdata7_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK7_Strm_buf0_rdata7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata8 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK8_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK8_Strm_buf0_rdata8_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK8_Strm_buf0_rdata8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata9 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK9_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK9_Strm_buf0_rdata9_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK9_Strm_buf0_rdata9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata10 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK10_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK10_Strm_buf0_rdata10_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK10_Strm_buf0_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata11 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK11_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK11_Strm_buf0_rdata11_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK11_Strm_buf0_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata12 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK12_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK12_Strm_buf0_rdata12_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK12_Strm_buf0_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata13 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK13_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK13_Strm_buf0_rdata13_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK13_Strm_buf0_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata14 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK14_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK14_Strm_buf0_rdata14_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK14_Strm_buf0_rdata14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata15 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK15_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK15_Strm_buf0_rdata15_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK15_Strm_buf0_rdata15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata16 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK16_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK16_Strm_buf0_rdata16_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK16_Strm_buf0_rdata16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata17 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK17_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK17_Strm_buf0_rdata17_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK17_Strm_buf0_rdata17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata18 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK18_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK18_Strm_buf0_rdata18_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK18_Strm_buf0_rdata18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata19 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK19_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK19_Strm_buf0_rdata19_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK19_Strm_buf0_rdata19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata20 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK20_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK20_Strm_buf0_rdata20_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK20_Strm_buf0_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata21 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK21_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK21_Strm_buf0_rdata21_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK21_Strm_buf0_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata22 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK22_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK22_Strm_buf0_rdata22_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK22_Strm_buf0_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata23 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK23_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK23_Strm_buf0_rdata23_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK23_Strm_buf0_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata24 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK24_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK24_Strm_buf0_rdata24_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK24_Strm_buf0_rdata24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata25 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK25_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK25_Strm_buf0_rdata25_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK25_Strm_buf0_rdata25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata26 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK26_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK26_Strm_buf0_rdata26_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK26_Strm_buf0_rdata26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata27 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK27_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK27_Strm_buf0_rdata27_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK27_Strm_buf0_rdata27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata28 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK28_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK28_Strm_buf0_rdata28_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK28_Strm_buf0_rdata28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata29 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK29_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK29_Strm_buf0_rdata29_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK29_Strm_buf0_rdata29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata30 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK30_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK30_Strm_buf0_rdata30_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK30_Strm_buf0_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf0_rdata31 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF0_RDBCK31_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF0_RDBCK31_Strm_buf0_rdata31_START (0)
#define SOC_VDEC_SED_STRM_BUF0_RDBCK31_Strm_buf0_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata0 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK0_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK0_Strm_buf1_rdata0_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK0_Strm_buf1_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata1 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK1_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK1_Strm_buf1_rdata1_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK1_Strm_buf1_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata2 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK2_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK2_Strm_buf1_rdata2_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK2_Strm_buf1_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata3 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK3_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK3_Strm_buf1_rdata3_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK3_Strm_buf1_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata4 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK4_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK4_Strm_buf1_rdata4_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK4_Strm_buf1_rdata4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata5 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK5_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK5_Strm_buf1_rdata5_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK5_Strm_buf1_rdata5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata6 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK6_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK6_Strm_buf1_rdata6_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK6_Strm_buf1_rdata6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata7 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK7_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK7_Strm_buf1_rdata7_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK7_Strm_buf1_rdata7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata8 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK8_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK8_Strm_buf1_rdata8_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK8_Strm_buf1_rdata8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata9 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK9_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK9_Strm_buf1_rdata9_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK9_Strm_buf1_rdata9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata10 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK10_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK10_Strm_buf1_rdata10_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK10_Strm_buf1_rdata10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata11 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK11_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK11_Strm_buf1_rdata11_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK11_Strm_buf1_rdata11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata12 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK12_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK12_Strm_buf1_rdata12_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK12_Strm_buf1_rdata12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata13 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK13_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK13_Strm_buf1_rdata13_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK13_Strm_buf1_rdata13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata14 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK14_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK14_Strm_buf1_rdata14_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK14_Strm_buf1_rdata14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata15 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK15_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK15_Strm_buf1_rdata15_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK15_Strm_buf1_rdata15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata16 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK16_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK16_Strm_buf1_rdata16_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK16_Strm_buf1_rdata16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata17 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK17_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK17_Strm_buf1_rdata17_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK17_Strm_buf1_rdata17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata18 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK18_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK18_Strm_buf1_rdata18_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK18_Strm_buf1_rdata18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata19 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK19_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK19_Strm_buf1_rdata19_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK19_Strm_buf1_rdata19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata20 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK20_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK20_Strm_buf1_rdata20_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK20_Strm_buf1_rdata20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata21 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK21_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK21_Strm_buf1_rdata21_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK21_Strm_buf1_rdata21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata22 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK22_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK22_Strm_buf1_rdata22_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK22_Strm_buf1_rdata22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata23 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK23_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK23_Strm_buf1_rdata23_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK23_Strm_buf1_rdata23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata24 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK24_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK24_Strm_buf1_rdata24_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK24_Strm_buf1_rdata24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata25 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK25_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK25_Strm_buf1_rdata25_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK25_Strm_buf1_rdata25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata26 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK26_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK26_Strm_buf1_rdata26_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK26_Strm_buf1_rdata26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata27 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK27_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK27_Strm_buf1_rdata27_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK27_Strm_buf1_rdata27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata28 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK28_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK28_Strm_buf1_rdata28_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK28_Strm_buf1_rdata28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata29 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK29_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK29_Strm_buf1_rdata29_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK29_Strm_buf1_rdata29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata30 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK30_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK30_Strm_buf1_rdata30_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK30_Strm_buf1_rdata30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Strm_buf1_rdata31 : 32;
    } reg;
} SOC_VDEC_SED_STRM_BUF1_RDBCK31_UNION;
#endif
#define SOC_VDEC_SED_STRM_BUF1_RDBCK31_Strm_buf1_rdata31_START (0)
#define SOC_VDEC_SED_STRM_BUF1_RDBCK31_Strm_buf1_rdata31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_VDEC_EMAR_STATE_9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prot_mod : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_VDEC_ITRANS_INFO_UNION;
#endif
#define SOC_VDEC_ITRANS_INFO_prot_mod_START (0)
#define SOC_VDEC_ITRANS_INFO_prot_mod_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adm_staddr : 32;
    } reg;
} SOC_VDEC_ITR_ADDR_UNION;
#endif
#define SOC_VDEC_ITR_ADDR_adm_staddr_START (0)
#define SOC_VDEC_ITR_ADDR_adm_staddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adm_width : 9;
        unsigned int reserved_0 : 4;
        unsigned int scale_type : 1;
        unsigned int dc_precision : 2;
        unsigned int mpeg1_flag : 1;
        unsigned int short_header : 1;
        unsigned int interlaced : 1;
        unsigned int vc1_overlap : 1;
        unsigned int picture_structure : 2;
        unsigned int real_pic_type : 2;
        unsigned int quant_type : 1;
        unsigned int alver_scanflag : 1;
        unsigned int pic_structure : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_VDEC_ITR_INF_UNION;
#endif
#define SOC_VDEC_ITR_INF_adm_width_START (0)
#define SOC_VDEC_ITR_INF_adm_width_END (8)
#define SOC_VDEC_ITR_INF_scale_type_START (13)
#define SOC_VDEC_ITR_INF_scale_type_END (13)
#define SOC_VDEC_ITR_INF_dc_precision_START (14)
#define SOC_VDEC_ITR_INF_dc_precision_END (15)
#define SOC_VDEC_ITR_INF_mpeg1_flag_START (16)
#define SOC_VDEC_ITR_INF_mpeg1_flag_END (16)
#define SOC_VDEC_ITR_INF_short_header_START (17)
#define SOC_VDEC_ITR_INF_short_header_END (17)
#define SOC_VDEC_ITR_INF_interlaced_START (18)
#define SOC_VDEC_ITR_INF_interlaced_END (18)
#define SOC_VDEC_ITR_INF_vc1_overlap_START (19)
#define SOC_VDEC_ITR_INF_vc1_overlap_END (19)
#define SOC_VDEC_ITR_INF_picture_structure_START (20)
#define SOC_VDEC_ITR_INF_picture_structure_END (21)
#define SOC_VDEC_ITR_INF_real_pic_type_START (22)
#define SOC_VDEC_ITR_INF_real_pic_type_END (23)
#define SOC_VDEC_ITR_INF_quant_type_START (24)
#define SOC_VDEC_ITR_INF_quant_type_END (24)
#define SOC_VDEC_ITR_INF_alver_scanflag_START (25)
#define SOC_VDEC_ITR_INF_alver_scanflag_END (25)
#define SOC_VDEC_ITR_INF_pic_structure_START (26)
#define SOC_VDEC_ITR_INF_pic_structure_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int is_cur_fsm : 3;
        unsigned int reserved_0 : 2;
        unsigned int scaling_list_enable_flag : 1;
        unsigned int reserved_1 : 1;
        unsigned int is_inb_empt : 1;
        unsigned int ahs_inb_empt : 1;
        unsigned int top_rdy : 1;
        unsigned int it2se_buffer_full : 1;
        unsigned int reserved_2 : 1;
        unsigned int cal_cur_fsm : 4;
        unsigned int ctrl_cur_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int outb_pempt : 1;
        unsigned int itb_empt_hvp : 1;
        unsigned int itb_full_hvp : 1;
        unsigned int outb_reg_empt : 1;
        unsigned int routb_cur_fsm : 2;
        unsigned int obutb_empt : 1;
        unsigned int outb_full : 1;
        unsigned int ritb_cur_fsm : 2;
        unsigned int itb_empt : 1;
        unsigned int itb_full : 1;
    } reg;
} SOC_VDEC_ITR_STA_0_UNION;
#endif
#define SOC_VDEC_ITR_STA_0_is_cur_fsm_START (0)
#define SOC_VDEC_ITR_STA_0_is_cur_fsm_END (2)
#define SOC_VDEC_ITR_STA_0_scaling_list_enable_flag_START (5)
#define SOC_VDEC_ITR_STA_0_scaling_list_enable_flag_END (5)
#define SOC_VDEC_ITR_STA_0_is_inb_empt_START (7)
#define SOC_VDEC_ITR_STA_0_is_inb_empt_END (7)
#define SOC_VDEC_ITR_STA_0_ahs_inb_empt_START (8)
#define SOC_VDEC_ITR_STA_0_ahs_inb_empt_END (8)
#define SOC_VDEC_ITR_STA_0_top_rdy_START (9)
#define SOC_VDEC_ITR_STA_0_top_rdy_END (9)
#define SOC_VDEC_ITR_STA_0_it2se_buffer_full_START (10)
#define SOC_VDEC_ITR_STA_0_it2se_buffer_full_END (10)
#define SOC_VDEC_ITR_STA_0_cal_cur_fsm_START (12)
#define SOC_VDEC_ITR_STA_0_cal_cur_fsm_END (15)
#define SOC_VDEC_ITR_STA_0_ctrl_cur_fsm_START (16)
#define SOC_VDEC_ITR_STA_0_ctrl_cur_fsm_END (17)
#define SOC_VDEC_ITR_STA_0_outb_pempt_START (20)
#define SOC_VDEC_ITR_STA_0_outb_pempt_END (20)
#define SOC_VDEC_ITR_STA_0_itb_empt_hvp_START (21)
#define SOC_VDEC_ITR_STA_0_itb_empt_hvp_END (21)
#define SOC_VDEC_ITR_STA_0_itb_full_hvp_START (22)
#define SOC_VDEC_ITR_STA_0_itb_full_hvp_END (22)
#define SOC_VDEC_ITR_STA_0_outb_reg_empt_START (23)
#define SOC_VDEC_ITR_STA_0_outb_reg_empt_END (23)
#define SOC_VDEC_ITR_STA_0_routb_cur_fsm_START (24)
#define SOC_VDEC_ITR_STA_0_routb_cur_fsm_END (25)
#define SOC_VDEC_ITR_STA_0_obutb_empt_START (26)
#define SOC_VDEC_ITR_STA_0_obutb_empt_END (26)
#define SOC_VDEC_ITR_STA_0_outb_full_START (27)
#define SOC_VDEC_ITR_STA_0_outb_full_END (27)
#define SOC_VDEC_ITR_STA_0_ritb_cur_fsm_START (28)
#define SOC_VDEC_ITR_STA_0_ritb_cur_fsm_END (29)
#define SOC_VDEC_ITR_STA_0_itb_empt_START (30)
#define SOC_VDEC_ITR_STA_0_itb_empt_END (30)
#define SOC_VDEC_ITR_STA_0_itb_full_START (31)
#define SOC_VDEC_ITR_STA_0_itb_full_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int is_quant : 7;
        unsigned int reserved_0 : 2;
        unsigned int is_dct_type : 1;
        unsigned int is_field : 1;
        unsigned int is_intra_16x16 : 1;
        unsigned int is_predmode : 3;
        unsigned int is_inter_16x16 : 1;
        unsigned int is_mb_type : 2;
        unsigned int reserved_1 : 2;
        unsigned int acdcmtn_st : 12;
    } reg;
} SOC_VDEC_ITR_STA_1_UNION;
#endif
#define SOC_VDEC_ITR_STA_1_is_quant_START (0)
#define SOC_VDEC_ITR_STA_1_is_quant_END (6)
#define SOC_VDEC_ITR_STA_1_is_dct_type_START (9)
#define SOC_VDEC_ITR_STA_1_is_dct_type_END (9)
#define SOC_VDEC_ITR_STA_1_is_field_START (10)
#define SOC_VDEC_ITR_STA_1_is_field_END (10)
#define SOC_VDEC_ITR_STA_1_is_intra_16x16_START (11)
#define SOC_VDEC_ITR_STA_1_is_intra_16x16_END (11)
#define SOC_VDEC_ITR_STA_1_is_predmode_START (12)
#define SOC_VDEC_ITR_STA_1_is_predmode_END (14)
#define SOC_VDEC_ITR_STA_1_is_inter_16x16_START (15)
#define SOC_VDEC_ITR_STA_1_is_inter_16x16_END (15)
#define SOC_VDEC_ITR_STA_1_is_mb_type_START (16)
#define SOC_VDEC_ITR_STA_1_is_mb_type_END (17)
#define SOC_VDEC_ITR_STA_1_acdcmtn_st_START (20)
#define SOC_VDEC_ITR_STA_1_acdcmtn_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ahs_adm_mbx : 9;
        unsigned int reserved_0 : 3;
        unsigned int ahs_adm_mby : 9;
        unsigned int reserved_1 : 3;
        unsigned int ahs_quant : 7;
        unsigned int acpre_flag : 1;
    } reg;
} SOC_VDEC_ITR_MB_INF（非hevc、非vp9）_UNION;
#endif
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_adm_mbx_START (0)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_adm_mbx_END (8)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_adm_mby_START (12)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_adm_mby_END (20)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_quant_START (24)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_ahs_quant_END (30)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_acpre_flag_START (31)
#define SOC_VDEC_ITR_MB_INF （非hevc、非vp9）_acpre_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x_tu : 16;
        unsigned int y_tu : 16;
    } reg;
} SOC_VDEC_ITR_MB_INF（hevc、vp9）_UNION;
#endif
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_x_tu_START (0)
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_x_tu_END (15)
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_y_tu_START (16)
#define SOC_VDEC_ITR_MB_INF （hevc、vp9）_y_tu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int is_frm_cycle : 32;
    } reg;
} SOC_VDEC_IS_FRM_CYCLE_UNION;
#endif
#define SOC_VDEC_IS_FRM_CYCLE_is_frm_cycle_START (0)
#define SOC_VDEC_IS_FRM_CYCLE_is_frm_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ahs_frm_cycle : 32;
    } reg;
} SOC_VDEC_AHS_FRM_CYCLE_UNION;
#endif
#define SOC_VDEC_AHS_FRM_CYCLE_ahs_frm_cycle_START (0)
#define SOC_VDEC_AHS_FRM_CYCLE_ahs_frm_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpi2pmv_mbx : 10;
        unsigned int reserved_0 : 6;
        unsigned int dpi2pmv_mby : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE0_0_UNION;
#endif
#define SOC_VDEC_PMV_STATE0_0_dpi2pmv_mbx_START (0)
#define SOC_VDEC_PMV_STATE0_0_dpi2pmv_mbx_END (9)
#define SOC_VDEC_PMV_STATE0_0_dpi2pmv_mby_START (16)
#define SOC_VDEC_PMV_STATE0_0_dpi2pmv_mby_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_ctb_y : 10;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_ctb_x : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE0_1_UNION;
#endif
#define SOC_VDEC_PMV_STATE0_1_ctrl2cfg_ctb_y_START (0)
#define SOC_VDEC_PMV_STATE0_1_ctrl2cfg_ctb_y_END (9)
#define SOC_VDEC_PMV_STATE0_1_ctrl2cfg_ctb_x_START (16)
#define SOC_VDEC_PMV_STATE0_1_ctrl2cfg_ctb_x_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_st_pmv[4:0] : 5;
        unsigned int reserved_0 : 3;
        unsigned int pmv2se_buffer_full : 1;
        unsigned int reserved_1 : 7;
        unsigned int mp2dpi_mp_err : 1;
        unsigned int reserved_2 : 7;
        unsigned int ci2cfg_mb_is_discon : 1;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_VDEC_PMV_STATE1_0_UNION;
#endif
#define SOC_VDEC_PMV_STATE1_0_cur_st_pmv [4:0]_START (0)
#define SOC_VDEC_PMV_STATE1_0_cur_st_pmv [4:0]_END (4)
#define SOC_VDEC_PMV_STATE1_0_pmv2se_buffer_full_START (8)
#define SOC_VDEC_PMV_STATE1_0_pmv2se_buffer_full_END (8)
#define SOC_VDEC_PMV_STATE1_0_mp2dpi_mp_err_START (16)
#define SOC_VDEC_PMV_STATE1_0_mp2dpi_mp_err_END (16)
#define SOC_VDEC_PMV_STATE1_0_ci2cfg_mb_is_discon_START (24)
#define SOC_VDEC_PMV_STATE1_0_ci2cfg_mb_is_discon_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_pu_mby : 10;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_pu_mbx : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE1_1_UNION;
#endif
#define SOC_VDEC_PMV_STATE1_1_ctrl2cfg_pu_mby_START (0)
#define SOC_VDEC_PMV_STATE1_1_ctrl2cfg_pu_mby_END (9)
#define SOC_VDEC_PMV_STATE1_1_ctrl2cfg_pu_mbx_START (16)
#define SOC_VDEC_PMV_STATE1_1_ctrl2cfg_pu_mbx_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmv_cycle_cnt : 32;
    } reg;
} SOC_VDEC_PMV_CYCLE_CNT_UNION;
#endif
#define SOC_VDEC_PMV_CYCLE_CNT_pmv_cycle_cnt_START (0)
#define SOC_VDEC_PMV_CYCLE_CNT_pmv_cycle_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_tu_mby : 10;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_tu_mbx : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE_2 (H265)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_2 (H265)_ctrl2cfg_tu_mby_START (0)
#define SOC_VDEC_PMV_STATE_2 (H265)_ctrl2cfg_tu_mby_END (9)
#define SOC_VDEC_PMV_STATE_2 (H265)_ctrl2cfg_tu_mbx_START (16)
#define SOC_VDEC_PMV_STATE_2 (H265)_ctrl2cfg_tu_mbx_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_rcn_mby : 10;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_rcn_mbx : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE_2 (VP9)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_2 (VP9)_ctrl2cfg_rcn_mby_START (0)
#define SOC_VDEC_PMV_STATE_2 (VP9)_ctrl2cfg_rcn_mby_END (9)
#define SOC_VDEC_PMV_STATE_2 (VP9)_ctrl2cfg_rcn_mbx_START (16)
#define SOC_VDEC_PMV_STATE_2 (VP9)_ctrl2cfg_rcn_mbx_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_ctb_st : 3;
        unsigned int reserved_0 : 5;
        unsigned int ctrl2cfg_cu_st : 2;
        unsigned int reserved_1 : 6;
        unsigned int ctrl2cfg_tu_st : 4;
        unsigned int reserved_2 : 4;
        unsigned int ctrl2cfg_pu_st : 3;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_VDEC_PMV_STATE_3 (H265)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_ctb_st_START (0)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_ctb_st_END (2)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_cu_st_START (8)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_cu_st_END (9)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_tu_st_START (16)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_tu_st_END (19)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_pu_st_START (24)
#define SOC_VDEC_PMV_STATE_3 (H265)_ctrl2cfg_pu_st_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_dblk_mby : 10;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_dblk_mbx : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_PMV_STATE_3 (VP9)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_3 (VP9)_ctrl2cfg_dblk_mby_START (0)
#define SOC_VDEC_PMV_STATE_3 (VP9)_ctrl2cfg_dblk_mby_END (9)
#define SOC_VDEC_PMV_STATE_3 (VP9)_ctrl2cfg_dblk_mbx_START (16)
#define SOC_VDEC_PMV_STATE_3 (VP9)_ctrl2cfg_dblk_mbx_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err0 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_0_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_0_ipmd_err0_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_0_ipmd_err0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_qp_st : 2;
        unsigned int reserved_0 : 6;
        unsigned int ctrl2cfg_rcn_st : 2;
        unsigned int reserved_1 : 6;
        unsigned int ctrl2cfg_dblk_st : 3;
        unsigned int reserved_2 : 5;
        unsigned int ctrl2cfg_bak_pu_st : 2;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_VDEC_PMV_STATE_4 (H265)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_qp_st_START (0)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_qp_st_END (1)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_rcn_st_START (8)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_rcn_st_END (9)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_dblk_st_START (16)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_dblk_st_END (18)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_bak_pu_st_START (24)
#define SOC_VDEC_PMV_STATE_4 (H265)_ctrl2cfg_bak_pu_st_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_ctb_st : 3;
        unsigned int reserved_0 : 5;
        unsigned int ctrl2cfg_prc_cq_st : 3;
        unsigned int reserved_1 : 4;
        unsigned int ctrl2cfg_pu_st : 3;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_VDEC_PMV_STATE_4 (VP9)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_ctb_st_START (0)
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_ctb_st_END (2)
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_prc_cq_st_START (8)
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_prc_cq_st_END (10)
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_pu_st_START (15)
#define SOC_VDEC_PMV_STATE_4 (VP9)_ctrl2cfg_pu_st_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err1 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_1_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_1_ipmd_err1_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_1_ipmd_err1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_obuf_ctb_full : 1;
        unsigned int reserved_0 : 7;
        unsigned int ctrl2cfg_obuf_mb_full : 1;
        unsigned int reserved_1 : 7;
        unsigned int ctrl2cfg_obuf_cbf_full : 1;
        unsigned int reserved_2 : 7;
        unsigned int buf2cfg_ctb_full : 1;
        unsigned int reserved_3 : 7;
    } reg;
} SOC_VDEC_PMV_STATE_5_UNION;
#endif
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_ctb_full_START (0)
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_ctb_full_END (0)
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_mb_full_START (8)
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_mb_full_END (8)
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_cbf_full_START (16)
#define SOC_VDEC_PMV_STATE_5_ctrl2cfg_obuf_cbf_full_END (16)
#define SOC_VDEC_PMV_STATE_5_buf2cfg_ctb_full_START (24)
#define SOC_VDEC_PMV_STATE_5_buf2cfg_ctb_full_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err2 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_2_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_2_ipmd_err2_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_2_ipmd_err2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf2cfg_cu_full : 1;
        unsigned int reserved_0 : 7;
        unsigned int buf2cfg_tu_full : 1;
        unsigned int reserved_1 : 7;
        unsigned int buf2cfg_pu_full : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_VDEC_PMV_STATE_6(H265)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_cu_full_START (0)
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_cu_full_END (0)
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_tu_full_START (8)
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_tu_full_END (8)
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_pu_full_START (16)
#define SOC_VDEC_PMV_STATE_6(H265) _buf2cfg_pu_full_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl2cfg_rcndblk_cq_st : 3;
        unsigned int reserved_0 : 5;
        unsigned int ctrl2cfg_rcndblk_pu_st : 4;
        unsigned int reserved_1 : 4;
        unsigned int ctrl2cfg_dblk_st : 3;
        unsigned int reserved_2 : 5;
        unsigned int ctrl2cfg_rcn_st : 2;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_VDEC_PMV_STATE_6 (VP9)_UNION;
#endif
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcndblk_cq_st_START (0)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcndblk_cq_st_END (2)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcndblk_pu_st_START (8)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcndblk_pu_st_END (11)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_dblk_st_START (16)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_dblk_st_END (18)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcn_st_START (24)
#define SOC_VDEC_PMV_STATE_6 (VP9)_ctrl2cfg_rcn_st_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err3 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_3_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_3_ipmd_err3_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_3_ipmd_err3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err4 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_4_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_4_ipmd_err4_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_4_ipmd_err4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err5 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_5_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_5_ipmd_err5_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_5_ipmd_err5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err6 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_6_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_6_ipmd_err6_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_6_ipmd_err6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipmd_err7 : 32;
    } reg;
} SOC_VDEC_INTRA_PRED_MODE_ERROR_7_UNION;
#endif
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_7_ipmd_err7_START (0)
#define SOC_VDEC_INTRA_PRED_MODE_ERROR_7_ipmd_err7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Prc_mbx : 9;
        unsigned int reserved_0: 7;
        unsigned int Prc_mby : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_VDEC_MB_INF_UNION;
#endif
#define SOC_VDEC_MB_INF_Prc_mbx_START (0)
#define SOC_VDEC_MB_INF_Prc_mbx_END (8)
#define SOC_VDEC_MB_INF_Prc_mby_START (16)
#define SOC_VDEC_MB_INF_Prc_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_Total_cnt : 32;
    } reg;
} SOC_VDEC_CACHE0_TOTAL_CNT_UNION;
#endif
#define SOC_VDEC_CACHE0_TOTAL_CNT_fetch0_Total_cnt_START (0)
#define SOC_VDEC_CACHE0_TOTAL_CNT_fetch0_Total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_Hit_cnt : 32;
    } reg;
} SOC_VDEC_CACHE0_HIT_CNT_UNION;
#endif
#define SOC_VDEC_CACHE0_HIT_CNT_fetch0_Hit_cnt_START (0)
#define SOC_VDEC_CACHE0_HIT_CNT_fetch0_Hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_Reqhit_cnt : 32;
    } reg;
} SOC_VDEC_CACHE0_REQHIT_CNT_UNION;
#endif
#define SOC_VDEC_CACHE0_REQHIT_CNT_fetch0_Reqhit_cnt_START (0)
#define SOC_VDEC_CACHE0_REQHIT_CNT_fetch0_Reqhit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_Miss_cnt : 32;
    } reg;
} SOC_VDEC_CACHE0_MISS_CNT_UNION;
#endif
#define SOC_VDEC_CACHE0_MISS_CNT_fetch0_Miss_cnt_START (0)
#define SOC_VDEC_CACHE0_MISS_CNT_fetch0_Miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_fe_work_time : 32;
    } reg;
} SOC_VDEC_CACHE0_FE_WORK_TIME_UNION;
#endif
#define SOC_VDEC_CACHE0_FE_WORK_TIME_fetch0_fe_work_time_START (0)
#define SOC_VDEC_CACHE0_FE_WORK_TIME_fetch0_fe_work_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch1_Total_cnt : 32;
    } reg;
} SOC_VDEC_CACHE1_TOTAL_CNT_UNION;
#endif
#define SOC_VDEC_CACHE1_TOTAL_CNT_fetch1_Total_cnt_START (0)
#define SOC_VDEC_CACHE1_TOTAL_CNT_fetch1_Total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch1_Hit_cnt : 32;
    } reg;
} SOC_VDEC_CACHE1_HIT_CNT_UNION;
#endif
#define SOC_VDEC_CACHE1_HIT_CNT_fetch1_Hit_cnt_START (0)
#define SOC_VDEC_CACHE1_HIT_CNT_fetch1_Hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch1_Reqhit_cnt : 32;
    } reg;
} SOC_VDEC_CACHE1_REQHIT_CNT_UNION;
#endif
#define SOC_VDEC_CACHE1_REQHIT_CNT_fetch1_Reqhit_cnt_START (0)
#define SOC_VDEC_CACHE1_REQHIT_CNT_fetch1_Reqhit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch1_Miss_cnt : 32;
    } reg;
} SOC_VDEC_CACHE1_MISS_CNT_UNION;
#endif
#define SOC_VDEC_CACHE1_MISS_CNT_fetch1_Miss_cnt_START (0)
#define SOC_VDEC_CACHE1_MISS_CNT_fetch1_Miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch1_fe_work_time : 32;
    } reg;
} SOC_VDEC_CACHE1_FE_WORK_TIME_UNION;
#endif
#define SOC_VDEC_CACHE1_FE_WORK_TIME_fetch1_fe_work_time_START (0)
#define SOC_VDEC_CACHE1_FE_WORK_TIME_fetch1_fe_work_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_Festate : 3;
        unsigned int reserved_0 : 1;
        unsigned int fetch0_fistate : 3;
        unsigned int reserved_1 : 1;
        unsigned int cmd_state : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_VDEC_PRC_STATE_UNION;
#endif
#define SOC_VDEC_PRC_STATE_fetch0_Festate_START (0)
#define SOC_VDEC_PRC_STATE_fetch0_Festate_END (2)
#define SOC_VDEC_PRC_STATE_fetch0_fistate_START (4)
#define SOC_VDEC_PRC_STATE_fetch0_fistate_END (6)
#define SOC_VDEC_PRC_STATE_cmd_state_START (8)
#define SOC_VDEC_PRC_STATE_cmd_state_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fetch0_fbuf_valid_fag : 1;
        unsigned int fetch0_fereqfull : 1;
        unsigned int fetcho_festall : 1;
        unsigned int fetcho_fbuffull : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VDEC_PRC_BUF_STATE0_UNION;
#endif
#define SOC_VDEC_PRC_BUF_STATE0_fetch0_fbuf_valid_fag_START (0)
#define SOC_VDEC_PRC_BUF_STATE0_fetch0_fbuf_valid_fag_END (0)
#define SOC_VDEC_PRC_BUF_STATE0_fetch0_fereqfull_START (1)
#define SOC_VDEC_PRC_BUF_STATE0_fetch0_fereqfull_END (1)
#define SOC_VDEC_PRC_BUF_STATE0_fetcho_festall_START (2)
#define SOC_VDEC_PRC_BUF_STATE0_fetcho_festall_END (2)
#define SOC_VDEC_PRC_BUF_STATE0_fetcho_fbuffull_START (3)
#define SOC_VDEC_PRC_BUF_STATE0_fetcho_fbuffull_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fmt_inf0_8bit_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int fmt_inf1_8bit_cnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int fe_inf0_8bit_cnt : 8;
        unsigned int fe_inf1_8bit_cnt : 8;
    } reg;
} SOC_VDEC_PRC_BUF_8BIT_STATE1_UNION;
#endif
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fmt_inf0_8bit_cnt_START (0)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fmt_inf0_8bit_cnt_END (6)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fmt_inf1_8bit_cnt_START (8)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fmt_inf1_8bit_cnt_END (14)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fe_inf0_8bit_cnt_START (16)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fe_inf0_8bit_cnt_END (23)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fe_inf1_8bit_cnt_START (24)
#define SOC_VDEC_PRC_BUF_8BIT_STATE1_fe_inf1_8bit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Out_str_ful : 1;
        unsigned int reserved_0 : 3;
        unsigned int Out_str_2bit_ful : 1;
        unsigned int reserved_1 : 3;
        unsigned int cur_st_2bit_fmt : 3;
        unsigned int reserved_2 : 5;
        unsigned int cur_st_2bit_rdf : 2;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_VDEC_OUT_STATE&#10;_UNION;
#endif
#define SOC_VDEC_OUT_STATE &#10;_Out_str_ful_START (0)
#define SOC_VDEC_OUT_STATE &#10;_Out_str_ful_END (0)
#define SOC_VDEC_OUT_STATE &#10;_Out_str_2bit_ful_START (4)
#define SOC_VDEC_OUT_STATE &#10;_Out_str_2bit_ful_END (4)
#define SOC_VDEC_OUT_STATE &#10;_cur_st_2bit_fmt_START (8)
#define SOC_VDEC_OUT_STATE &#10;_cur_st_2bit_fmt_END (10)
#define SOC_VDEC_OUT_STATE &#10;_cur_st_2bit_rdf_START (16)
#define SOC_VDEC_OUT_STATE &#10;_cur_st_2bit_rdf_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Cur_st_fmt : 3;
        unsigned int reserved_0 : 1;
        unsigned int Cur_st_pod : 3;
        unsigned int reserved_1 : 1;
        unsigned int Cur_st_rdf : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_VDEC_FMT_STATE_UNION;
#endif
#define SOC_VDEC_FMT_STATE_Cur_st_fmt_START (0)
#define SOC_VDEC_FMT_STATE_Cur_st_fmt_END (2)
#define SOC_VDEC_FMT_STATE_Cur_st_pod_START (4)
#define SOC_VDEC_FMT_STATE_Cur_st_pod_END (6)
#define SOC_VDEC_FMT_STATE_Cur_st_rdf_START (8)
#define SOC_VDEC_FMT_STATE_Cur_st_rdf_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fmt_inf0_2bit_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int fmt_inf1_2bit_cnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int fe_inf0_2bit_cnt : 8;
        unsigned int fe_inf1_2bit_cnt : 8;
    } reg;
} SOC_VDEC_PRC_BUF_2BIT_STATE1_UNION;
#endif
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fmt_inf0_2bit_cnt_START (0)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fmt_inf0_2bit_cnt_END (6)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fmt_inf1_2bit_cnt_START (8)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fmt_inf1_2bit_cnt_END (14)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fe_inf0_2bit_cnt_START (16)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fe_inf0_2bit_cnt_END (23)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fe_inf1_2bit_cnt_START (24)
#define SOC_VDEC_PRC_BUF_2BIT_STATE1_fe_inf1_2bit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_abs_mvx[31:0] : 32;
    } reg;
} SOC_VDEC_PRC_TOTAL_ABS_MVX_L_UNION;
#endif
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_L_total_abs_mvx [31:0]_START (0)
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_L_total_abs_mvx [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_abs_mvx[63:32] : 32;
    } reg;
} SOC_VDEC_PRC_TOTAL_ABS_MVX_H_UNION;
#endif
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_H_total_abs_mvx [63:32]_START (0)
#define SOC_VDEC_PRC_TOTAL_ABS_MVX_H_total_abs_mvx [63:32]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_abs_mvy[31:0 : 32;
    } reg;
} SOC_VDEC_PRC_TOTAL_ABS_MVY_L_UNION;
#endif
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_L_total_abs_mvy [31:0_START (0)
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_L_total_abs_mvy [31:0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_abs_mvy[63:32] : 32;
    } reg;
} SOC_VDEC_PRC_TOTAL_ABS_MVY_H_UNION;
#endif
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_H_total_abs_mvy [63:32]_START (0)
#define SOC_VDEC_PRC_TOTAL_ABS_MVY_H_total_abs_mvy [63:32]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_total_count0 : 32;
    } reg;
} SOC_VDEC_HEAD_CACHE0_TOTAL_CNT_UNION;
#endif
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT_head_total_count0_START (0)
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT_head_total_count0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_miss_count0 : 32;
    } reg;
} SOC_VDEC_HEAD_CACHE0_MISS_CNT_UNION;
#endif
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT_head_miss_count0_START (0)
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT_head_miss_count0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_total_count1 : 32;
    } reg;
} SOC_VDEC_HEAD_CACHE0_TOTAL_CNT1_UNION;
#endif
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT1_head_total_count1_START (0)
#define SOC_VDEC_HEAD_CACHE0_TOTAL_CNT1_head_total_count1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_miss_count1 : 32;
    } reg;
} SOC_VDEC_HEAD_CACHE0_MISS_CNT1_UNION;
#endif
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT1_head_miss_count1_START (0)
#define SOC_VDEC_HEAD_CACHE0_MISS_CNT1_head_miss_count1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_decmp_err0 : 1;
        unsigned int luma_decmp_err1 : 1;
        unsigned int chroma_decmp_err0 : 1;
        unsigned int chroma_decmp_err1 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VDEC_DCMP_IP_ERROR_UNION;
#endif
#define SOC_VDEC_DCMP_IP_ERROR_luma_decmp_err0_START (0)
#define SOC_VDEC_DCMP_IP_ERROR_luma_decmp_err0_END (0)
#define SOC_VDEC_DCMP_IP_ERROR_luma_decmp_err1_START (1)
#define SOC_VDEC_DCMP_IP_ERROR_luma_decmp_err1_END (1)
#define SOC_VDEC_DCMP_IP_ERROR_chroma_decmp_err0_START (2)
#define SOC_VDEC_DCMP_IP_ERROR_chroma_decmp_err0_END (2)
#define SOC_VDEC_DCMP_IP_ERROR_chroma_decmp_err1_START (3)
#define SOC_VDEC_DCMP_IP_ERROR_chroma_decmp_err1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prf_protocol : 4;
        unsigned int flt_mode_mpeg4 : 1;
        unsigned int frst_cmd[4:3] : 2;
        unsigned int frst_mvy : 4;
        unsigned int frst_mvx : 4;
        unsigned int mpeg4_rnd : 1;
        unsigned int frst_part_mode : 4;
        unsigned int frst_data_type : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_VDEC_PRF_INFO_UNION;
#endif
#define SOC_VDEC_PRF_INFO_prf_protocol_START (0)
#define SOC_VDEC_PRF_INFO_prf_protocol_END (3)
#define SOC_VDEC_PRF_INFO_flt_mode_mpeg4_START (4)
#define SOC_VDEC_PRF_INFO_flt_mode_mpeg4_END (4)
#define SOC_VDEC_PRF_INFO_frst_cmd [4:3]_START (5)
#define SOC_VDEC_PRF_INFO_frst_cmd [4:3]_END (6)
#define SOC_VDEC_PRF_INFO_frst_mvy_START (7)
#define SOC_VDEC_PRF_INFO_frst_mvy_END (10)
#define SOC_VDEC_PRF_INFO_frst_mvx_START (11)
#define SOC_VDEC_PRF_INFO_frst_mvx_END (14)
#define SOC_VDEC_PRF_INFO_mpeg4_rnd_START (15)
#define SOC_VDEC_PRF_INFO_mpeg4_rnd_END (15)
#define SOC_VDEC_PRF_INFO_frst_part_mode_START (16)
#define SOC_VDEC_PRF_INFO_frst_part_mode_END (19)
#define SOC_VDEC_PRF_INFO_frst_data_type_START (20)
#define SOC_VDEC_PRF_INFO_frst_data_type_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_hst : 8;
        unsigned int cur_vst : 7;
        unsigned int reserved : 17;
    } reg;
} SOC_VDEC_PRF_STATE_UNION;
#endif
#define SOC_VDEC_PRF_STATE_cur_hst_START (0)
#define SOC_VDEC_PRF_STATE_cur_hst_END (7)
#define SOC_VDEC_PRF_STATE_cur_vst_START (8)
#define SOC_VDEC_PRF_STATE_cur_vst_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prf2prc_wac : 1;
        unsigned int prf2prc_2bit_wac : 1;
        unsigned int 6'd0                   : 6;  /* bit[2-7]  : debug信息 */
        unsigned int ibuf_cmd_cnt[7:0] : 8;
        unsigned int ibuf_2bit_cmd_cnt[7:0] : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_VDEC_PRF_IBUF_ST_UNION;
#endif
#define SOC_VDEC_PRF_IBUF_ST_prf2prc_wac_START (0)
#define SOC_VDEC_PRF_IBUF_ST_prf2prc_wac_END (0)
#define SOC_VDEC_PRF_IBUF_ST_prf2prc_2bit_wac_START (1)
#define SOC_VDEC_PRF_IBUF_ST_prf2prc_2bit_wac_END (1)
#define SOC_VDEC_PRF_IBUF_ST_6 'd0_START                    (2)
#define SOC_VDEC_PRF_IBUF_ST_6 'd0_END                      (7)
#define SOC_VDEC_PRF_IBUF_ST_ibuf_cmd_cnt [7:0]_START (8)
#define SOC_VDEC_PRF_IBUF_ST_ibuf_cmd_cnt [7:0]_END (15)
#define SOC_VDEC_PRF_IBUF_ST_ibuf_2bit_cmd_cnt [7:0]_START (16)
#define SOC_VDEC_PRF_IBUF_ST_ibuf_2bit_cmd_cnt [7:0]_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int weight_flag : 2;
        unsigned int pic_type : 2;
        unsigned int avs_code_type : 2;
        unsigned int rcn_slc_type : 2;
        unsigned int rcn_cnstrn_prd : 1;
        unsigned int first_mb_inslc : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_VDEC_RCN_PIC_PARA_UNION;
#endif
#define SOC_VDEC_RCN_PIC_PARA_weight_flag_START (0)
#define SOC_VDEC_RCN_PIC_PARA_weight_flag_END (1)
#define SOC_VDEC_RCN_PIC_PARA_pic_type_START (2)
#define SOC_VDEC_RCN_PIC_PARA_pic_type_END (3)
#define SOC_VDEC_RCN_PIC_PARA_avs_code_type_START (4)
#define SOC_VDEC_RCN_PIC_PARA_avs_code_type_END (5)
#define SOC_VDEC_RCN_PIC_PARA_rcn_slc_type_START (6)
#define SOC_VDEC_RCN_PIC_PARA_rcn_slc_type_END (7)
#define SOC_VDEC_RCN_PIC_PARA_rcn_cnstrn_prd_START (8)
#define SOC_VDEC_RCN_PIC_PARA_rcn_cnstrn_prd_END (8)
#define SOC_VDEC_RCN_PIC_PARA_first_mb_inslc_START (9)
#define SOC_VDEC_RCN_PIC_PARA_first_mb_inslc_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_mbx : 10;
        unsigned int reserved_0 : 2;
        unsigned int rcn_mby : 10;
        unsigned int reserved_1 : 2;
        unsigned int mb_type_sc : 6;
        unsigned int transform_size_8x8_flag : 1;
        unsigned int rcn_fld_prd : 1;
    } reg;
} SOC_VDEC_RCN_MB_PARA_0_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_0_rcn_mbx_START (0)
#define SOC_VDEC_RCN_MB_PARA_0_rcn_mbx_END (9)
#define SOC_VDEC_RCN_MB_PARA_0_rcn_mby_START (12)
#define SOC_VDEC_RCN_MB_PARA_0_rcn_mby_END (21)
#define SOC_VDEC_RCN_MB_PARA_0_mb_type_sc_START (24)
#define SOC_VDEC_RCN_MB_PARA_0_mb_type_sc_END (29)
#define SOC_VDEC_RCN_MB_PARA_0_transform_size_8x8_flag_START (30)
#define SOC_VDEC_RCN_MB_PARA_0_transform_size_8x8_flag_END (30)
#define SOC_VDEC_RCN_MB_PARA_0_rcn_fld_prd_START (31)
#define SOC_VDEC_RCN_MB_PARA_0_rcn_fld_prd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_mbav : 12;
        unsigned int rcn_cbcr_mod : 2;
        unsigned int reserved_0 : 2;
        unsigned int rcn_l16_mod : 2;
        unsigned int reserved_1 : 2;
        unsigned int rcn_wght_pred : 1;
        unsigned int rcn_mb_wght : 1;
        unsigned int rcn_slc_wght : 1;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_VDEC_RCN_MB_PARA_1_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_1_rcn_mbav_START (0)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_mbav_END (11)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_cbcr_mod_START (12)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_cbcr_mod_END (13)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_l16_mod_START (16)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_l16_mod_END (17)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_wght_pred_START (20)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_wght_pred_END (20)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_mb_wght_START (21)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_mb_wght_END (21)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_slc_wght_START (22)
#define SOC_VDEC_RCN_MB_PARA_1_rcn_slc_wght_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_l4_mod[31:0] : 32;
    } reg;
} SOC_VDEC_RCN_MB_PARA_2_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_2_rcn_l4_mod [31:0]_START (0)
#define SOC_VDEC_RCN_MB_PARA_2_rcn_l4_mod [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_l4_mod[63:32] : 32;
    } reg;
} SOC_VDEC_RCN_MB_PARA_3_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_3_rcn_l4_mod [63:32]_START (0)
#define SOC_VDEC_RCN_MB_PARA_3_rcn_l4_mod [63:32]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_prd_l0 : 8;
        unsigned int mv_mod_pmv : 2;
        unsigned int reserved_0 : 2;
        unsigned int rcn_prd_c0 : 8;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_VDEC_RCN_MB_PARA_4_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_4_rcn_prd_l0_START (0)
#define SOC_VDEC_RCN_MB_PARA_4_rcn_prd_l0_END (7)
#define SOC_VDEC_RCN_MB_PARA_4_mv_mod_pmv_START (8)
#define SOC_VDEC_RCN_MB_PARA_4_mv_mod_pmv_END (9)
#define SOC_VDEC_RCN_MB_PARA_4_rcn_prd_c0_START (12)
#define SOC_VDEC_RCN_MB_PARA_4_rcn_prd_c0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_prd_l1 : 8;
        unsigned int reserved : 4;
        unsigned int rcn_prd_c1 : 8;
        unsigned int tu_size_cfg[11:0] : 12;
    } reg;
} SOC_VDEC_RCN_MB_PARA_5_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_5_rcn_prd_l1_START (0)
#define SOC_VDEC_RCN_MB_PARA_5_rcn_prd_l1_END (7)
#define SOC_VDEC_RCN_MB_PARA_5_rcn_prd_c1_START (12)
#define SOC_VDEC_RCN_MB_PARA_5_rcn_prd_c1_END (19)
#define SOC_VDEC_RCN_MB_PARA_5_tu_size_cfg [11:0]_START (20)
#define SOC_VDEC_RCN_MB_PARA_5_tu_size_cfg [11:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_st_cfg : 3;
        unsigned int reserved_0 : 1;
        unsigned int bitdepth[7:0] : 8;
        unsigned int ctb_size[2:0] : 3;
        unsigned int reserved_1 : 1;
        unsigned int part_mod[7:0] : 8;
        unsigned int pred_type[7:0] : 8;
    } reg;
} SOC_VDEC_RCN_MB_PARA_6_UNION;
#endif
#define SOC_VDEC_RCN_MB_PARA_6_cur_st_cfg_START (0)
#define SOC_VDEC_RCN_MB_PARA_6_cur_st_cfg_END (2)
#define SOC_VDEC_RCN_MB_PARA_6_bitdepth [7:0]_START (4)
#define SOC_VDEC_RCN_MB_PARA_6_bitdepth [7:0]_END (11)
#define SOC_VDEC_RCN_MB_PARA_6_ctb_size [2:0]_START (12)
#define SOC_VDEC_RCN_MB_PARA_6_ctb_size [2:0]_END (14)
#define SOC_VDEC_RCN_MB_PARA_6_part_mod [7:0]_START (16)
#define SOC_VDEC_RCN_MB_PARA_6_part_mod [7:0]_END (23)
#define SOC_VDEC_RCN_MB_PARA_6_pred_type [7:0]_START (24)
#define SOC_VDEC_RCN_MB_PARA_6_pred_type [7:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inf_dat_cnt : 5;
        unsigned int reserved_0 : 3;
        unsigned int rsd_ram_cnt : 6;
        unsigned int rcn_ram_cnt : 6;
        unsigned int rcn2pmv_buffer_full : 1;
        unsigned int dblk2rcn_wack : 1;
        unsigned int reserved_1 : 1;
        unsigned int rcn2itrans_ack : 1;
        unsigned int cbf_flag : 1;
        unsigned int rcn_rdy : 1;
        unsigned int m_rcn_rdy : 1;
        unsigned int intra_rdy : 1;
        unsigned int pred_inter_rdy : 1;
        unsigned int top_rdy : 1;
        unsigned int rtop_inf_full : 1;
        unsigned int wbtm_empty : 1;
    } reg;
} SOC_VDEC_RCN_BUF_STATE_UNION;
#endif
#define SOC_VDEC_RCN_BUF_STATE_inf_dat_cnt_START (0)
#define SOC_VDEC_RCN_BUF_STATE_inf_dat_cnt_END (4)
#define SOC_VDEC_RCN_BUF_STATE_rsd_ram_cnt_START (8)
#define SOC_VDEC_RCN_BUF_STATE_rsd_ram_cnt_END (13)
#define SOC_VDEC_RCN_BUF_STATE_rcn_ram_cnt_START (14)
#define SOC_VDEC_RCN_BUF_STATE_rcn_ram_cnt_END (19)
#define SOC_VDEC_RCN_BUF_STATE_rcn2pmv_buffer_full_START (20)
#define SOC_VDEC_RCN_BUF_STATE_rcn2pmv_buffer_full_END (20)
#define SOC_VDEC_RCN_BUF_STATE_dblk2rcn_wack_START (21)
#define SOC_VDEC_RCN_BUF_STATE_dblk2rcn_wack_END (21)
#define SOC_VDEC_RCN_BUF_STATE_rcn2itrans_ack_START (23)
#define SOC_VDEC_RCN_BUF_STATE_rcn2itrans_ack_END (23)
#define SOC_VDEC_RCN_BUF_STATE_cbf_flag_START (24)
#define SOC_VDEC_RCN_BUF_STATE_cbf_flag_END (24)
#define SOC_VDEC_RCN_BUF_STATE_rcn_rdy_START (25)
#define SOC_VDEC_RCN_BUF_STATE_rcn_rdy_END (25)
#define SOC_VDEC_RCN_BUF_STATE_m_rcn_rdy_START (26)
#define SOC_VDEC_RCN_BUF_STATE_m_rcn_rdy_END (26)
#define SOC_VDEC_RCN_BUF_STATE_intra_rdy_START (27)
#define SOC_VDEC_RCN_BUF_STATE_intra_rdy_END (27)
#define SOC_VDEC_RCN_BUF_STATE_pred_inter_rdy_START (28)
#define SOC_VDEC_RCN_BUF_STATE_pred_inter_rdy_END (28)
#define SOC_VDEC_RCN_BUF_STATE_top_rdy_START (29)
#define SOC_VDEC_RCN_BUF_STATE_top_rdy_END (29)
#define SOC_VDEC_RCN_BUF_STATE_rtop_inf_full_START (30)
#define SOC_VDEC_RCN_BUF_STATE_rtop_inf_full_END (30)
#define SOC_VDEC_RCN_BUF_STATE_wbtm_empty_START (31)
#define SOC_VDEC_RCN_BUF_STATE_wbtm_empty_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_imgwidth : 10;
        unsigned int reserved_0 : 6;
        unsigned int rcn_imgheight : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_VDEC_RCN_MB_NUM_UNION;
#endif
#define SOC_VDEC_RCN_MB_NUM_rcn_imgwidth_START (0)
#define SOC_VDEC_RCN_MB_NUM_rcn_imgwidth_END (9)
#define SOC_VDEC_RCN_MB_NUM_rcn_imgheight_START (16)
#define SOC_VDEC_RCN_MB_NUM_rcn_imgheight_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctb_imgwidth : 9;
        unsigned int reserved_0 : 3;
        unsigned int ctb_imgheight[8:0] : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_VDEC_RCN_CTB_NUM_UNION;
#endif
#define SOC_VDEC_RCN_CTB_NUM_ctb_imgwidth_START (0)
#define SOC_VDEC_RCN_CTB_NUM_ctb_imgwidth_END (8)
#define SOC_VDEC_RCN_CTB_NUM_ctb_imgheight [8:0]_START (12)
#define SOC_VDEC_RCN_CTB_NUM_ctb_imgheight [8:0]_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_l8_mod : 16;
        unsigned int rcn_ema : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_VDEC_RCN_MB_PART_7_UNION;
#endif
#define SOC_VDEC_RCN_MB_PART_7_rcn_l8_mod_START (0)
#define SOC_VDEC_RCN_MB_PART_7_rcn_l8_mod_END (15)
#define SOC_VDEC_RCN_MB_PART_7_rcn_ema_START (16)
#define SOC_VDEC_RCN_MB_PART_7_rcn_ema_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int pred_ctrl_cur : 3;
        unsigned int reserved_1 : 1;
        unsigned int wbtm_cur_st : 2;
        unsigned int reserved_2 : 2;
        unsigned int cur_state : 3;
        unsigned int reserved_3 : 1;
        unsigned int cur_st_wbtm : 2;
        unsigned int reserved_4 : 2;
        unsigned int cur_st_rtop : 2;
        unsigned int reserved_5 : 2;
        unsigned int mb_inf_cnt : 5;
        unsigned int reserved_6 : 3;
    } reg;
} SOC_VDEC_RCN_FSM_STATE_UNION;
#endif
#define SOC_VDEC_RCN_FSM_STATE_pred_ctrl_cur_START (4)
#define SOC_VDEC_RCN_FSM_STATE_pred_ctrl_cur_END (6)
#define SOC_VDEC_RCN_FSM_STATE_wbtm_cur_st_START (8)
#define SOC_VDEC_RCN_FSM_STATE_wbtm_cur_st_END (9)
#define SOC_VDEC_RCN_FSM_STATE_cur_state_START (12)
#define SOC_VDEC_RCN_FSM_STATE_cur_state_END (14)
#define SOC_VDEC_RCN_FSM_STATE_cur_st_wbtm_START (16)
#define SOC_VDEC_RCN_FSM_STATE_cur_st_wbtm_END (17)
#define SOC_VDEC_RCN_FSM_STATE_cur_st_rtop_START (20)
#define SOC_VDEC_RCN_FSM_STATE_cur_st_rtop_END (21)
#define SOC_VDEC_RCN_FSM_STATE_mb_inf_cnt_START (24)
#define SOC_VDEC_RCN_FSM_STATE_mb_inf_cnt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int store_0_blk_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int store_1_blk_cnt : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_VDEC_RCN_PRF_STATE_UNION;
#endif
#define SOC_VDEC_RCN_PRF_STATE_store_0_blk_cnt_START (0)
#define SOC_VDEC_RCN_PRF_STATE_store_0_blk_cnt_END (6)
#define SOC_VDEC_RCN_PRF_STATE_store_1_blk_cnt_START (8)
#define SOC_VDEC_RCN_PRF_STATE_store_1_blk_cnt_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp9_inf_data_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int vp9_inf_buf_rpt : 7;
        unsigned int reserved_1 : 1;
        unsigned int vp9_inf_buf_wpt : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_VDEC_RCN_VP9_INFO_UNION;
#endif
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_data_cnt_START (0)
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_data_cnt_END (6)
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_buf_rpt_START (8)
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_buf_rpt_END (14)
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_buf_wpt_START (16)
#define SOC_VDEC_RCN_VP9_INFO_vp9_inf_buf_wpt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int video_standard : 4;
        unsigned int pic_struct : 2;
        unsigned int reserved_0 : 2;
        unsigned int int2core_imagewidth : 9;
        unsigned int reserved_1 : 3;
        unsigned int int2core_imageheight : 9;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_VDEC_DBLK_PIC_INFO_UNION;
#endif
#define SOC_VDEC_DBLK_PIC_INFO_video_standard_START (0)
#define SOC_VDEC_DBLK_PIC_INFO_video_standard_END (3)
#define SOC_VDEC_DBLK_PIC_INFO_pic_struct_START (4)
#define SOC_VDEC_DBLK_PIC_INFO_pic_struct_END (5)
#define SOC_VDEC_DBLK_PIC_INFO_int2core_imagewidth_START (8)
#define SOC_VDEC_DBLK_PIC_INFO_int2core_imagewidth_END (16)
#define SOC_VDEC_DBLK_PIC_INFO_int2core_imageheight_START (20)
#define SOC_VDEC_DBLK_PIC_INFO_int2core_imageheight_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_beta_offset : 5;
        unsigned int dblk_alpha_offset : 5;
        unsigned int dblk_dis_filter_idc : 2;
        unsigned int dblk_chr_qp_idx : 5;
        unsigned int reserved : 15;
    } reg;
} SOC_VDEC_DBLK_FLT_INFO_UNION;
#endif
#define SOC_VDEC_DBLK_FLT_INFO_dblk_beta_offset_START (0)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_beta_offset_END (4)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_alpha_offset_START (5)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_alpha_offset_END (9)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_dis_filter_idc_START (10)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_dis_filter_idc_END (11)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_chr_qp_idx_START (12)
#define SOC_VDEC_DBLK_FLT_INFO_dblk_chr_qp_idx_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_stride : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VDEC_DBLK_DDR_STRD_UNION;
#endif
#define SOC_VDEC_DBLK_DDR_STRD_ddr_stride_START (0)
#define SOC_VDEC_DBLK_DDR_STRD_ddr_stride_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_ystaddr : 32;
    } reg;
} SOC_VDEC_DBLK_YADDR_UNION;
#endif
#define SOC_VDEC_DBLK_YADDR_dblk_ystaddr_START (0)
#define SOC_VDEC_DBLK_YADDR_dblk_ystaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_cstaddr : 32;
    } reg;
} SOC_VDEC_DBLK_CADDR_UNION;
#endif
#define SOC_VDEC_DBLK_CADDR_dblk_cstaddr_START (0)
#define SOC_VDEC_DBLK_CADDR_dblk_cstaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_tx_st : 3;
        unsigned int reserved_0 : 1;
        unsigned int cur_emar_st : 2;
        unsigned int reserved_1 : 2;
        unsigned int emar_tx_cnt : 8;
        unsigned int dblk2emar_top_awvalid : 1;
        unsigned int dblk2emar_top_wvalid : 1;
        unsigned int emar2dblk_top_awready : 1;
        unsigned int emar2dblk_top_wready : 1;
        unsigned int dblk2emar_left_awvalid : 1;
        unsigned int dblk2emar_left_wvalid : 1;
        unsigned int emar2dblk_left_awready : 1;
        unsigned int emar2dblk_left_wready : 1;
        unsigned int emar_tx_cnt_num : 8;
    } reg;
} SOC_VDEC_DBLK_ST_TOP_UNION;
#endif
#define SOC_VDEC_DBLK_ST_TOP_cur_tx_st_START (0)
#define SOC_VDEC_DBLK_ST_TOP_cur_tx_st_END (2)
#define SOC_VDEC_DBLK_ST_TOP_cur_emar_st_START (4)
#define SOC_VDEC_DBLK_ST_TOP_cur_emar_st_END (5)
#define SOC_VDEC_DBLK_ST_TOP_emar_tx_cnt_START (8)
#define SOC_VDEC_DBLK_ST_TOP_emar_tx_cnt_END (15)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_top_awvalid_START (16)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_top_awvalid_END (16)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_top_wvalid_START (17)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_top_wvalid_END (17)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_top_awready_START (18)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_top_awready_END (18)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_top_wready_START (19)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_top_wready_END (19)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_left_awvalid_START (20)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_left_awvalid_END (20)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_left_wvalid_START (21)
#define SOC_VDEC_DBLK_ST_TOP_dblk2emar_left_wvalid_END (21)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_left_awready_START (22)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_left_awready_END (22)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_left_wready_START (23)
#define SOC_VDEC_DBLK_ST_TOP_emar2dblk_left_wready_END (23)
#define SOC_VDEC_DBLK_ST_TOP_emar_tx_cnt_num_START (24)
#define SOC_VDEC_DBLK_ST_TOP_emar_tx_cnt_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_st_ta_inf : 4;
        unsigned int cur_st : 2;
        unsigned int reserved_0 : 2;
        unsigned int dblk2emar_ta_arvalid : 1;
        unsigned int dblk2emar_ta_rready : 1;
        unsigned int emar2dblk_ta_arready : 1;
        unsigned int emar2dblk_ta_rvalid : 1;
        unsigned int dblk2emar_left_arvalid : 1;
        unsigned int dblk2emar_left_rready : 1;
        unsigned int dblk2emar_left_arready : 1;
        unsigned int dblk2emar_left_rvalid : 1;
        unsigned int ta_buf_cnt : 3;
        unsigned int reserved_1 : 1;
        unsigned int left_buf_cnt : 3;
        unsigned int reserved_2 : 1;
        unsigned int neib2ibuf_ful : 1;
        unsigned int neib2ibuf_wac : 1;
        unsigned int dblk2pmv_ack : 1;
        unsigned int ovl_wack : 1;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_VDEC_DBLK_ST_TA_CTRL_UNION;
#endif
#define SOC_VDEC_DBLK_ST_TA_CTRL_cur_st_ta_inf_START (0)
#define SOC_VDEC_DBLK_ST_TA_CTRL_cur_st_ta_inf_END (3)
#define SOC_VDEC_DBLK_ST_TA_CTRL_cur_st_START (4)
#define SOC_VDEC_DBLK_ST_TA_CTRL_cur_st_END (5)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_ta_arvalid_START (8)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_ta_arvalid_END (8)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_ta_rready_START (9)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_ta_rready_END (9)
#define SOC_VDEC_DBLK_ST_TA_CTRL_emar2dblk_ta_arready_START (10)
#define SOC_VDEC_DBLK_ST_TA_CTRL_emar2dblk_ta_arready_END (10)
#define SOC_VDEC_DBLK_ST_TA_CTRL_emar2dblk_ta_rvalid_START (11)
#define SOC_VDEC_DBLK_ST_TA_CTRL_emar2dblk_ta_rvalid_END (11)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_arvalid_START (12)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_arvalid_END (12)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_rready_START (13)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_rready_END (13)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_arready_START (14)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_arready_END (14)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_rvalid_START (15)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2emar_left_rvalid_END (15)
#define SOC_VDEC_DBLK_ST_TA_CTRL_ta_buf_cnt_START (16)
#define SOC_VDEC_DBLK_ST_TA_CTRL_ta_buf_cnt_END (18)
#define SOC_VDEC_DBLK_ST_TA_CTRL_left_buf_cnt_START (20)
#define SOC_VDEC_DBLK_ST_TA_CTRL_left_buf_cnt_END (22)
#define SOC_VDEC_DBLK_ST_TA_CTRL_neib2ibuf_ful_START (24)
#define SOC_VDEC_DBLK_ST_TA_CTRL_neib2ibuf_ful_END (24)
#define SOC_VDEC_DBLK_ST_TA_CTRL_neib2ibuf_wac_START (25)
#define SOC_VDEC_DBLK_ST_TA_CTRL_neib2ibuf_wac_END (25)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2pmv_ack_START (26)
#define SOC_VDEC_DBLK_ST_TA_CTRL_dblk2pmv_ack_END (26)
#define SOC_VDEC_DBLK_ST_TA_CTRL_ovl_wack_START (27)
#define SOC_VDEC_DBLK_ST_TA_CTRL_ovl_wack_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcn_flt_cnt : 3;
        unsigned int reserved_0 : 1;
        unsigned int pmv_flt_cnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int rcn_flt_rpt : 2;
        unsigned int reserved_2 : 2;
        unsigned int rcn_mb_wpt : 2;
        unsigned int reserved_3 : 2;
        unsigned int pmv_mb_wpt : 6;
        unsigned int pmv_info_rpt : 6;
    } reg;
} SOC_VDEC_DBLK_ST_DI_CTRL_UNION;
#endif
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_flt_cnt_START (0)
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_flt_cnt_END (2)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_flt_cnt_START (4)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_flt_cnt_END (10)
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_flt_rpt_START (12)
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_flt_rpt_END (13)
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_mb_wpt_START (16)
#define SOC_VDEC_DBLK_ST_DI_CTRL_rcn_mb_wpt_END (17)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_mb_wpt_START (20)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_mb_wpt_END (25)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_info_rpt_START (26)
#define SOC_VDEC_DBLK_ST_DI_CTRL_pmv_info_rpt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_mbx : 10;
        unsigned int reserved_0: 6;
        unsigned int cur_mby : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_VDEC_DBLK_ST_DF_UNION;
#endif
#define SOC_VDEC_DBLK_ST_DF_cur_mbx_START (0)
#define SOC_VDEC_DBLK_ST_DF_cur_mbx_END (9)
#define SOC_VDEC_DBLK_ST_DF_cur_mby_START (16)
#define SOC_VDEC_DBLK_ST_DF_cur_mby_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcmp_bypass : 1;
        unsigned int last_sgmt_cmd : 1;
        unsigned int fld_pic_type : 2;
        unsigned int bondry_flag : 2;
        unsigned int obuf_rdy : 1;
        unsigned int reserved : 1;
        unsigned int mbx : 10;
        unsigned int mby : 10;
        unsigned int mb_num_in_obuf : 4;
    } reg;
} SOC_VDEC_DBLK_ST_DO_UNION;
#endif
#define SOC_VDEC_DBLK_ST_DO_vcmp_bypass_START (0)
#define SOC_VDEC_DBLK_ST_DO_vcmp_bypass_END (0)
#define SOC_VDEC_DBLK_ST_DO_last_sgmt_cmd_START (1)
#define SOC_VDEC_DBLK_ST_DO_last_sgmt_cmd_END (1)
#define SOC_VDEC_DBLK_ST_DO_fld_pic_type_START (2)
#define SOC_VDEC_DBLK_ST_DO_fld_pic_type_END (3)
#define SOC_VDEC_DBLK_ST_DO_bondry_flag_START (4)
#define SOC_VDEC_DBLK_ST_DO_bondry_flag_END (5)
#define SOC_VDEC_DBLK_ST_DO_obuf_rdy_START (6)
#define SOC_VDEC_DBLK_ST_DO_obuf_rdy_END (6)
#define SOC_VDEC_DBLK_ST_DO_mbx_START (8)
#define SOC_VDEC_DBLK_ST_DO_mbx_END (17)
#define SOC_VDEC_DBLK_ST_DO_mby_START (18)
#define SOC_VDEC_DBLK_ST_DO_mby_END (27)
#define SOC_VDEC_DBLK_ST_DO_mb_num_in_obuf_START (28)
#define SOC_VDEC_DBLK_ST_DO_mb_num_in_obuf_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_wr_st : 8;
        unsigned int cur_rd_st : 8;
        unsigned int regs_full : 1;
        unsigned int sao2dblk_wack : 1;
        unsigned int flt2ibuf_flt_end : 1;
        unsigned int reserved_0 : 5;
        unsigned int cur_mst : 3;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_VDEC_DBLK_ST_FLT_STATE_0_UNION;
#endif
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_wr_st_START (0)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_wr_st_END (7)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_rd_st_START (8)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_rd_st_END (15)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_regs_full_START (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_regs_full_END (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_sao2dblk_wack_START (17)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_sao2dblk_wack_END (17)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_flt2ibuf_flt_end_START (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_flt2ibuf_flt_end_END (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_mst_START (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_0_cur_mst_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_cnt0 : 4;
        unsigned int data_cnt1 : 4;
        unsigned int data_cnt2 : 4;
        unsigned int data_cnt_p : 4;
        unsigned int dataout_pt : 3;
        unsigned int reserved_0 : 1;
        unsigned int flt2ovl_wtype : 2;
        unsigned int ovl2flt_wac : 1;
        unsigned int ovl2flt_rac : 1;
        unsigned int mbuf2flt_rac : 1;
        unsigned int mbuf2flt_wac : 1;
        unsigned int obuf2flt_wac : 1;
        unsigned int ibuf2flt_rac : 1;
        unsigned int rcn_buf2flt_rac : 1;
        unsigned int flt2obuf_we : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_VDEC_DBLK_ST_FLT_STATE_1_UNION;
#endif
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt0_START (0)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt0_END (3)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt1_START (4)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt1_END (7)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt2_START (8)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt2_END (11)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt_p_START (12)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_data_cnt_p_END (15)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_dataout_pt_START (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_dataout_pt_END (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_flt2ovl_wtype_START (20)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_flt2ovl_wtype_END (21)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ovl2flt_wac_START (22)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ovl2flt_wac_END (22)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ovl2flt_rac_START (23)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ovl2flt_rac_END (23)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_mbuf2flt_rac_START (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_mbuf2flt_rac_END (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_mbuf2flt_wac_START (25)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_mbuf2flt_wac_END (25)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_obuf2flt_wac_START (26)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_obuf2flt_wac_END (26)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ibuf2flt_rac_START (27)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_ibuf2flt_rac_END (27)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_rcn_buf2flt_rac_START (28)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_rcn_buf2flt_rac_END (28)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_flt2obuf_we_START (29)
#define SOC_VDEC_DBLK_ST_FLT_STATE_1_flt2obuf_we_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ta_inf_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int ta_inf_rreq : 1;
        unsigned int reserved_1 : 3;
        unsigned int c_flt2ibuf_re : 1;
        unsigned int flt2ibuf_re : 1;
        unsigned int pmv2dblk_we : 1;
        unsigned int dblk2pmv_buffer_full : 1;
        unsigned int emar2ibuf_we : 1;
        unsigned int ta_cmd_rw[cur_tacmd_rpt] : 1;
        unsigned int reg2ibuf_we : 1;
        unsigned int reserved_2 : 1;
        unsigned int ovl2ibuf_we : 1;
        unsigned int reserved_3 : 3;
        unsigned int ovl2repix_buf_wtype : 4;
        unsigned int ovl2ibuf_re : 1;
        unsigned int reserved_4 : 3;
    } reg;
} SOC_VDEC_DBLK_IBUFFER_STATE_UNION;
#endif
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_inf_cnt_START (0)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_inf_cnt_END (6)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_inf_rreq_START (8)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_inf_rreq_END (8)
#define SOC_VDEC_DBLK_IBUFFER_STATE_c_flt2ibuf_re_START (12)
#define SOC_VDEC_DBLK_IBUFFER_STATE_c_flt2ibuf_re_END (12)
#define SOC_VDEC_DBLK_IBUFFER_STATE_flt2ibuf_re_START (13)
#define SOC_VDEC_DBLK_IBUFFER_STATE_flt2ibuf_re_END (13)
#define SOC_VDEC_DBLK_IBUFFER_STATE_pmv2dblk_we_START (14)
#define SOC_VDEC_DBLK_IBUFFER_STATE_pmv2dblk_we_END (14)
#define SOC_VDEC_DBLK_IBUFFER_STATE_dblk2pmv_buffer_full_START (15)
#define SOC_VDEC_DBLK_IBUFFER_STATE_dblk2pmv_buffer_full_END (15)
#define SOC_VDEC_DBLK_IBUFFER_STATE_emar2ibuf_we_START (16)
#define SOC_VDEC_DBLK_IBUFFER_STATE_emar2ibuf_we_END (16)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_cmd_rw [cur_tacmd_rpt]_START (17)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ta_cmd_rw [cur_tacmd_rpt]_END (17)
#define SOC_VDEC_DBLK_IBUFFER_STATE_reg2ibuf_we_START (18)
#define SOC_VDEC_DBLK_IBUFFER_STATE_reg2ibuf_we_END (18)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2ibuf_we_START (20)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2ibuf_we_END (20)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2repix_buf_wtype_START (24)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2repix_buf_wtype_END (27)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2ibuf_re_START (28)
#define SOC_VDEC_DBLK_IBUFFER_STATE_ovl2ibuf_re_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int c_flt2ovl_we : 1;
        unsigned int flt2ovl_we : 1;
        unsigned int ibuf2neib_weq : 1;
        unsigned int reserved_0 : 1;
        unsigned int c_flt2ovl_re : 1;
        unsigned int flt2ovl_re : 1;
        unsigned int tile_info_data_valid : 1;
        unsigned int ovl2flt_rack : 1;
        unsigned int rd_buf_rrq : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_VDEC_DBLK_OVL_BUFFER_STATE_UNION;
#endif
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_c_flt2ovl_we_START (0)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_c_flt2ovl_we_END (0)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_flt2ovl_we_START (1)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_flt2ovl_we_END (1)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ibuf2neib_weq_START (2)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ibuf2neib_weq_END (2)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_c_flt2ovl_re_START (4)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_c_flt2ovl_re_END (4)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_flt2ovl_re_START (5)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_flt2ovl_re_END (5)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_tile_info_data_valid_START (6)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_tile_info_data_valid_END (6)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ovl2flt_rack_START (7)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_ovl2flt_rack_END (7)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_rd_buf_rrq_START (8)
#define SOC_VDEC_DBLK_OVL_BUFFER_STATE_rd_buf_rrq_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_mbx : 10;
        unsigned int reserved_0: 6;
        unsigned int cur_mby : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_VDEC_DBLK_ST_FLT_STATE_2_UNION;
#endif
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_cur_mbx_START (0)
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_cur_mbx_END (9)
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_cur_mby_START (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_2_cur_mby_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_wr_st : 8;
        unsigned int cur_rd_st : 8;
        unsigned int regs_full : 1;
        unsigned int sao2dblk_wack : 1;
        unsigned int flt2ibuf_flt_end : 1;
        unsigned int reserved_0 : 5;
        unsigned int cur_mst : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_VDEC_DBLK_ST_FLT_STATE_3_UNION;
#endif
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_wr_st_START (0)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_wr_st_END (7)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_rd_st_START (8)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_rd_st_END (15)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_regs_full_START (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_regs_full_END (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_sao2dblk_wack_START (17)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_sao2dblk_wack_END (17)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_flt2ibuf_flt_end_START (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_flt2ibuf_flt_end_END (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_mst_START (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_3_cur_mst_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_cnt0 : 4;
        unsigned int data_cnt1 : 4;
        unsigned int data_cnt2 : 4;
        unsigned int data_cnt_p : 4;
        unsigned int dataout_pt : 3;
        unsigned int reserved_0 : 1;
        unsigned int flt2ovl_wtype : 2;
        unsigned int ovl2flt_wac : 1;
        unsigned int ovl2flt_rac : 1;
        unsigned int mbuf2flt_rac : 1;
        unsigned int mbuf2flt_wac : 1;
        unsigned int obuf2flt_wac : 1;
        unsigned int ibuf2flt_rac : 1;
        unsigned int repix2flt_rac : 1;
        unsigned int flt2obuf_we : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_VDEC_DBLK_ST_FLT_STATE_4_UNION;
#endif
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt0_START (0)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt0_END (3)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt1_START (4)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt1_END (7)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt2_START (8)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt2_END (11)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt_p_START (12)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_data_cnt_p_END (15)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_dataout_pt_START (16)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_dataout_pt_END (18)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_flt2ovl_wtype_START (20)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_flt2ovl_wtype_END (21)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ovl2flt_wac_START (22)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ovl2flt_wac_END (22)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ovl2flt_rac_START (23)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ovl2flt_rac_END (23)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_mbuf2flt_rac_START (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_mbuf2flt_rac_END (24)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_mbuf2flt_wac_START (25)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_mbuf2flt_wac_END (25)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_obuf2flt_wac_START (26)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_obuf2flt_wac_END (26)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ibuf2flt_rac_START (27)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_ibuf2flt_rac_END (27)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_repix2flt_rac_START (28)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_repix2flt_rac_END (28)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_flt2obuf_we_START (29)
#define SOC_VDEC_DBLK_ST_FLT_STATE_4_flt2obuf_we_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk2cmp_awvalid : 1;
        unsigned int cmp2dblk_awready : 1;
        unsigned int dblk2cmp_wvalid : 1;
        unsigned int cmp2dblk_wready : 1;
        unsigned int dblk2cmp_awcoef2[13:0] : 14;
        unsigned int dblk2cmp_awcoef3[13:0] : 14;
    } reg;
} SOC_VDEC_DBLK2CMP_STATE_UNION;
#endif
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awvalid_START (0)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awvalid_END (0)
#define SOC_VDEC_DBLK2CMP_STATE_cmp2dblk_awready_START (1)
#define SOC_VDEC_DBLK2CMP_STATE_cmp2dblk_awready_END (1)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_wvalid_START (2)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_wvalid_END (2)
#define SOC_VDEC_DBLK2CMP_STATE_cmp2dblk_wready_START (3)
#define SOC_VDEC_DBLK2CMP_STATE_cmp2dblk_wready_END (3)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awcoef2 [13:0]_START (4)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awcoef2 [13:0]_END (17)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awcoef3 [13:0]_START (18)
#define SOC_VDEC_DBLK2CMP_STATE_dblk2cmp_awcoef3 [13:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf0_full : 1;
        unsigned int buf1_full : 1;
        unsigned int avs_btm_field : 1;
        unsigned int ch_flag : 1;
        unsigned int wr_eamr_cur_st : 10;
        unsigned int reserved_0 : 2;
        unsigned int wr_emar_mb_cur_st : 9;
        unsigned int reserved_1 : 3;
        unsigned int emar_tx_cur_st : 3;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_VDEC_OBUFFER_STATE_UNION;
#endif
#define SOC_VDEC_OBUFFER_STATE_buf0_full_START (0)
#define SOC_VDEC_OBUFFER_STATE_buf0_full_END (0)
#define SOC_VDEC_OBUFFER_STATE_buf1_full_START (1)
#define SOC_VDEC_OBUFFER_STATE_buf1_full_END (1)
#define SOC_VDEC_OBUFFER_STATE_avs_btm_field_START (2)
#define SOC_VDEC_OBUFFER_STATE_avs_btm_field_END (2)
#define SOC_VDEC_OBUFFER_STATE_ch_flag_START (3)
#define SOC_VDEC_OBUFFER_STATE_ch_flag_END (3)
#define SOC_VDEC_OBUFFER_STATE_wr_eamr_cur_st_START (4)
#define SOC_VDEC_OBUFFER_STATE_wr_eamr_cur_st_END (13)
#define SOC_VDEC_OBUFFER_STATE_wr_emar_mb_cur_st_START (16)
#define SOC_VDEC_OBUFFER_STATE_wr_emar_mb_cur_st_END (24)
#define SOC_VDEC_OBUFFER_STATE_emar_tx_cur_st_START (28)
#define SOC_VDEC_OBUFFER_STATE_emar_tx_cur_st_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt0 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT0_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT0_luma_histogram_cnt0_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT0_luma_histogram_cnt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt1 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT1_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT1_luma_histogram_cnt1_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT1_luma_histogram_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt2 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT2_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT2_luma_histogram_cnt2_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT2_luma_histogram_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt3 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT3_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT3_luma_histogram_cnt3_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT3_luma_histogram_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt4 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT4_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT4_luma_histogram_cnt4_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT4_luma_histogram_cnt4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt5 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT5_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT5_luma_histogram_cnt5_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT5_luma_histogram_cnt5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt6 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT6_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT6_luma_histogram_cnt6_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT6_luma_histogram_cnt6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt7 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT7_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT7_luma_histogram_cnt7_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT7_luma_histogram_cnt7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt8 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT8_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT8_luma_histogram_cnt8_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT8_luma_histogram_cnt8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt9 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT9_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT9_luma_histogram_cnt9_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT9_luma_histogram_cnt9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt10 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT10_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT10_luma_histogram_cnt10_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT10_luma_histogram_cnt10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt11 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT11_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT11_luma_histogram_cnt11_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT11_luma_histogram_cnt11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt12 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT12_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT12_luma_histogram_cnt12_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT12_luma_histogram_cnt12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt13 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT13_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT13_luma_histogram_cnt13_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT13_luma_histogram_cnt13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt14 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT14_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT14_luma_histogram_cnt14_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT14_luma_histogram_cnt14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt15 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT15_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT15_luma_histogram_cnt15_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT15_luma_histogram_cnt15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt16 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT16_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT16_luma_histogram_cnt16_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT16_luma_histogram_cnt16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt17 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT17_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT17_luma_histogram_cnt17_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT17_luma_histogram_cnt17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt18 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT18_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT18_luma_histogram_cnt18_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT18_luma_histogram_cnt18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt19 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT19_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT19_luma_histogram_cnt19_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT19_luma_histogram_cnt19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt20 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT20_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT20_luma_histogram_cnt20_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT20_luma_histogram_cnt20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt21 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT21_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT21_luma_histogram_cnt21_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT21_luma_histogram_cnt21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt22 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT22_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT22_luma_histogram_cnt22_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT22_luma_histogram_cnt22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt23 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT23_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT23_luma_histogram_cnt23_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT23_luma_histogram_cnt23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt24 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT24_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT24_luma_histogram_cnt24_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT24_luma_histogram_cnt24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt25 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT25_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT25_luma_histogram_cnt25_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT25_luma_histogram_cnt25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt26 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT26_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT26_luma_histogram_cnt26_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT26_luma_histogram_cnt26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt27 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT27_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT27_luma_histogram_cnt27_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT27_luma_histogram_cnt27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt28 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT28_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT28_luma_histogram_cnt28_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT28_luma_histogram_cnt28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt29 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT29_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT29_luma_histogram_cnt29_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT29_luma_histogram_cnt29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt30 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT30_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT30_luma_histogram_cnt30_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT30_luma_histogram_cnt30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_histogram_cnt31 : 32;
    } reg;
} SOC_VDEC_LUMA_HISTOGRAM_CNT31_UNION;
#endif
#define SOC_VDEC_LUMA_HISTOGRAM_CNT31_luma_histogram_cnt31_START (0)
#define SOC_VDEC_LUMA_HISTOGRAM_CNT31_luma_histogram_cnt31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_sum[31:0] : 32;
    } reg;
} SOC_VDEC_LUMA_SUM0_UNION;
#endif
#define SOC_VDEC_LUMA_SUM0_luma_sum [31:0]_START (0)
#define SOC_VDEC_LUMA_SUM0_luma_sum [31:0]_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int luma_sum[35:32] : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_VDEC_LUMA_SUM1_UNION;
#endif
#define SOC_VDEC_LUMA_SUM1_luma_sum [35:32]_START (0)
#define SOC_VDEC_LUMA_SUM1_luma_sum [35:32]_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_mem_info : 32;
    } reg;
} SOC_VDEC_DBLK_MEM_INFO_UNION;
#endif
#define SOC_VDEC_DBLK_MEM_INFO_dblk_mem_info_START (0)
#define SOC_VDEC_DBLK_MEM_INFO_dblk_mem_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_mem_pix0 : 32;
    } reg;
} SOC_VDEC_DBLK_MEM_PIX0_UNION;
#endif
#define SOC_VDEC_DBLK_MEM_PIX0_dblk_mem_pix0_START (0)
#define SOC_VDEC_DBLK_MEM_PIX0_dblk_mem_pix0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dblk_mem_pix1 : 32;
    } reg;
} SOC_VDEC_DBLK_MEM_PIX1_UNION;
#endif
#define SOC_VDEC_DBLK_MEM_PIX1_dblk_mem_pix1_START (0)
#define SOC_VDEC_DBLK_MEM_PIX1_dblk_mem_pix1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ld_info_cur_st : 4;
        unsigned int ld_data_cur_st : 4;
        unsigned int cal_cur_st : 8;
        unsigned int bps_cur_st : 4;
        unsigned int snd_cur_st : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG0_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG0_ld_info_cur_st_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG0_ld_info_cur_st_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG0_ld_data_cur_st_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG0_ld_data_cur_st_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG0_cal_cur_st_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG0_cal_cur_st_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG0_bps_cur_st_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG0_bps_cur_st_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG0_snd_cur_st_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG0_snd_cur_st_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_in_ctb_cnt : 4;
        unsigned int ctb_x : 8;
        unsigned int ctb_y : 8;
        unsigned int ld_data_line_cnt : 4;
        unsigned int ld_data_left_line_cnt : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG1_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG1_blk_in_ctb_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG1_blk_in_ctb_cnt_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG1_ctb_x_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG1_ctb_x_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG1_ctb_y_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG1_ctb_y_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG1_ld_data_line_cnt_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG1_ld_data_line_cnt_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG1_ld_data_left_line_cnt_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG1_ld_data_left_line_cnt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ld_stack_wptr : 4;
        unsigned int ld_strack_wptr_cnt : 8;
        unsigned int ld_strack_wptr_cnt_pre : 8;
        unsigned int stack_cur_empty : 1;
        unsigned int stack_cur_empty_pre : 1;
        unsigned int stack_cur_full : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG2_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_stack_wptr_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_stack_wptr_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_strack_wptr_cnt_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_strack_wptr_cnt_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_strack_wptr_cnt_pre_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG2_ld_strack_wptr_cnt_pre_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_empty_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_empty_END (20)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_empty_pre_START (21)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_empty_pre_END (21)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_full_START (22)
#define SOC_VDEC_SAO_RD_BACK_REG2_stack_cur_full_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bps_line_cnt : 4;
        unsigned int bps_stack_rptr : 4;
        unsigned int bps_stack_rptr_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG3_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_line_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_line_cnt_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_stack_rptr_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_stack_rptr_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_stack_rptr_cnt_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG3_bps_stack_rptr_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cal_stack_cur_rptr_cnt : 8;
        unsigned int cal_stack_cur_rptr : 4;
        unsigned int cal_line_cnt : 4;
        unsigned int cal_col_cnt : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG4_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_stack_cur_rptr_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_stack_cur_rptr_cnt_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_stack_cur_rptr_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_stack_cur_rptr_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_line_cnt_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_line_cnt_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_col_cnt_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG4_cal_col_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snd_top_cnt : 4;
        unsigned int snd_left_line_cnt : 4;
        unsigned int snd_left_stack_rptr_cnt : 8;
        unsigned int snd_left_stack_rptr : 4;
        unsigned int stack_empty : 1;
        unsigned int stack_left_full : 1;
        unsigned int stack_left_full_pre : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG5_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_top_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_top_cnt_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_line_cnt_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_line_cnt_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_stack_rptr_cnt_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_stack_rptr_cnt_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_stack_rptr_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG5_snd_left_stack_rptr_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_empty_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_empty_END (20)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_left_full_START (21)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_left_full_END (21)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_left_full_pre_START (22)
#define SOC_VDEC_SAO_RD_BACK_REG5_stack_left_full_pre_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_buf_cur_st : 4;
        unsigned int rd_emar_cur_st : 4;
        unsigned int wr_nbr_emar_cur_st : 4;
        unsigned int rd_nbr_buf_cur_st : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG6_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG6_wr_buf_cur_st_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG6_wr_buf_cur_st_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG6_rd_emar_cur_st_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG6_rd_emar_cur_st_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG6_wr_nbr_emar_cur_st_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG6_wr_nbr_emar_cur_st_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG6_rd_nbr_buf_cur_st_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG6_rd_nbr_buf_cur_st_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int top_blk_vld : 4;
        unsigned int nbr_ctbx : 8;
        unsigned int nbr_ctby : 8;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG7_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG7_top_blk_vld_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG7_top_blk_vld_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG7_nbr_ctbx_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG7_nbr_ctbx_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG7_nbr_ctby_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG7_nbr_ctby_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_color_index : 4;
        unsigned int wstack_rptr : 4;
        unsigned int wstack_wptr : 4;
        unsigned int wstack_wptr_pre : 4;
        unsigned int wstack_empty : 1;
        unsigned int wstack_full_pre : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG8_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG8_wr_color_index_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG8_wr_color_index_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_rptr_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_rptr_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_wptr_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_wptr_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_wptr_pre_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_wptr_pre_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_empty_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_empty_END (16)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_full_pre_START (17)
#define SOC_VDEC_SAO_RD_BACK_REG8_wstack_full_pre_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emar_left_wvld_cnt : 8;
        unsigned int emar_left_awvld_cnt : 4;
        unsigned int emar2sao_left_wready : 1;
        unsigned int sao2emar_left_wvalid : 1;
        unsigned int emar2sao_left_awready : 1;
        unsigned int sao2emar_left_awvalid : 1;
        unsigned int nbr2obuf_left_raddr_cnt : 8;
        unsigned int wr_tile_right_ctbx : 8;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG9_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG9_emar_left_wvld_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar_left_wvld_cnt_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar_left_awvld_cnt_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar_left_awvld_cnt_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar2sao_left_wready_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar2sao_left_wready_END (12)
#define SOC_VDEC_SAO_RD_BACK_REG9_sao2emar_left_wvalid_START (13)
#define SOC_VDEC_SAO_RD_BACK_REG9_sao2emar_left_wvalid_END (13)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar2sao_left_awready_START (14)
#define SOC_VDEC_SAO_RD_BACK_REG9_emar2sao_left_awready_END (14)
#define SOC_VDEC_SAO_RD_BACK_REG9_sao2emar_left_awvalid_START (15)
#define SOC_VDEC_SAO_RD_BACK_REG9_sao2emar_left_awvalid_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG9_nbr2obuf_left_raddr_cnt_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG9_nbr2obuf_left_raddr_cnt_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG9_wr_tile_right_ctbx_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG9_wr_tile_right_ctbx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emar_top_wvld_in_wstack_cnt : 4;
        unsigned int emar_top_wvld_cnt : 8;
        unsigned int emar2sao_top_wready : 1;
        unsigned int sao2emar_top_wvalid : 1;
        unsigned int emar2sao_top_awready : 1;
        unsigned int sao2emar_top_awvalid : 1;
        unsigned int nbr2nbuf_top_raddr_cnt : 8;
        unsigned int nbuf2nbr_rack : 1;
        unsigned int nbr2nbuf_top_rreq : 1;
        unsigned int obuf2nbr_rack : 1;
        unsigned int nbr2obuf_left_rreq : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG10_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG10_emar_top_wvld_in_wstack_cnt_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar_top_wvld_in_wstack_cnt_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar_top_wvld_cnt_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar_top_wvld_cnt_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar2sao_top_wready_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar2sao_top_wready_END (12)
#define SOC_VDEC_SAO_RD_BACK_REG10_sao2emar_top_wvalid_START (13)
#define SOC_VDEC_SAO_RD_BACK_REG10_sao2emar_top_wvalid_END (13)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar2sao_top_awready_START (14)
#define SOC_VDEC_SAO_RD_BACK_REG10_emar2sao_top_awready_END (14)
#define SOC_VDEC_SAO_RD_BACK_REG10_sao2emar_top_awvalid_START (15)
#define SOC_VDEC_SAO_RD_BACK_REG10_sao2emar_top_awvalid_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2nbuf_top_raddr_cnt_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2nbuf_top_raddr_cnt_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbuf2nbr_rack_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbuf2nbr_rack_END (24)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2nbuf_top_rreq_START (25)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2nbuf_top_rreq_END (25)
#define SOC_VDEC_SAO_RD_BACK_REG10_obuf2nbr_rack_START (26)
#define SOC_VDEC_SAO_RD_BACK_REG10_obuf2nbr_rack_END (26)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2obuf_left_rreq_START (27)
#define SOC_VDEC_SAO_RD_BACK_REG10_nbr2obuf_left_rreq_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stack_chroma_full_pre : 1;
        unsigned int stack_chroma_emtpy : 1;
        unsigned int stack_luma_full_pre : 1;
        unsigned int stack_luma_empty : 1;
        unsigned int stack_chroma_rptr : 4;
        unsigned int stack_luma_rptr : 4;
        unsigned int stack_chroma_wptr_pre : 4;
        unsigned int stack_luma_wptr_pre : 4;
        unsigned int wr_emar_cur_st : 4;
        unsigned int rd_obuf_cur_st : 4;
        unsigned int sao2emar_wvalid : 1;
        unsigned int sao2emar_awvalid : 1;
        unsigned int emar2sao_wready : 1;
        unsigned int emar2sao_awready : 1;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG11_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_full_pre_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_full_pre_END (0)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_emtpy_START (1)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_emtpy_END (1)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_full_pre_START (2)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_full_pre_END (2)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_empty_START (3)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_empty_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_rptr_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_rptr_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_rptr_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_rptr_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_wptr_pre_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_chroma_wptr_pre_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_wptr_pre_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG11_stack_luma_wptr_pre_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG11_wr_emar_cur_st_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG11_wr_emar_cur_st_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG11_rd_obuf_cur_st_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG11_rd_obuf_cur_st_END (27)
#define SOC_VDEC_SAO_RD_BACK_REG11_sao2emar_wvalid_START (28)
#define SOC_VDEC_SAO_RD_BACK_REG11_sao2emar_wvalid_END (28)
#define SOC_VDEC_SAO_RD_BACK_REG11_sao2emar_awvalid_START (29)
#define SOC_VDEC_SAO_RD_BACK_REG11_sao2emar_awvalid_END (29)
#define SOC_VDEC_SAO_RD_BACK_REG11_emar2sao_wready_START (30)
#define SOC_VDEC_SAO_RD_BACK_REG11_emar2sao_wready_END (30)
#define SOC_VDEC_SAO_RD_BACK_REG11_emar2sao_awready_START (31)
#define SOC_VDEC_SAO_RD_BACK_REG11_emar2sao_awready_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_emar_ctby : 8;
        unsigned int wr_emar_ctbx : 8;
        unsigned int ctby : 8;
        unsigned int ctbx : 8;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG12_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG12_wr_emar_ctby_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG12_wr_emar_ctby_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG12_wr_emar_ctbx_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG12_wr_emar_ctbx_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG12_ctby_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG12_ctby_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG12_ctbx_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG12_ctbx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sao2emar_awcoef3 : 16;
        unsigned int sao2emar_awcoef2 : 16;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG13_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG13_sao2emar_awcoef3_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG13_sao2emar_awcoef3_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG13_sao2emar_awcoef2_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG13_sao2emar_awcoef2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sao2emar_awcoef4 : 32;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG14_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG14_sao2emar_awcoef4_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG14_sao2emar_awcoef4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int obuf2core_wack : 1;
        unsigned int obuf2nbr_rack : 1;
        unsigned int obuf2nbr_wack : 2;
        unsigned int obuf2core_rack : 1;
        unsigned int obuf2core_tile_right_wack : 1;
        unsigned int obuf2ldstr_rack : 1;
        unsigned int obuf2core_reconstr_wack : 1;
        unsigned int obuf_nbr_tile_right_empty : 1;
        unsigned int obuf_nbr_tile_right_full : 1;
        unsigned int obuf_core_tile_right_empty : 1;
        unsigned int obuf_core_tile_right_full : 1;
        unsigned int obuf_empty : 1;
        unsigned int obuf_full : 3;
        unsigned int obuf_rptr : 4;
        unsigned int obuf_whole_wptr : 4;
        unsigned int obuf_wptr : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG15_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_wack_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_wack_END (0)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2nbr_rack_START (1)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2nbr_rack_END (1)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2nbr_wack_START (2)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2nbr_wack_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_rack_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_rack_END (4)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_tile_right_wack_START (5)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_tile_right_wack_END (5)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2ldstr_rack_START (6)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2ldstr_rack_END (6)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_reconstr_wack_START (7)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf2core_reconstr_wack_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_nbr_tile_right_empty_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_nbr_tile_right_empty_END (8)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_nbr_tile_right_full_START (9)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_nbr_tile_right_full_END (9)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_core_tile_right_empty_START (10)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_core_tile_right_empty_END (10)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_core_tile_right_full_START (11)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_core_tile_right_full_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_empty_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_empty_END (12)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_full_START (13)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_full_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_rptr_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_rptr_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_whole_wptr_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_whole_wptr_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_wptr_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG15_obuf_wptr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_nbr_pmv_empty : 1;
        unsigned int ibuf_nbr_pmv_full : 1;
        unsigned int ibuf_pmv_emtpy : 1;
        unsigned int ibuf_pmv_full : 1;
        unsigned int ibuf_dblk_cmd_rptr : 4;
        unsigned int ibuf_dblk_cmd_wptr : 4;
        unsigned int ibuf_dblk_empty : 1;
        unsigned int ibuf_dblk_full : 3;
        unsigned int ibuf_dblk_rptr : 2;
        unsigned int ibuf_dblk_wptr : 2;
        unsigned int ibuf2nbr_pmv_rack : 1;
        unsigned int ibuf2core_pmv_rack : 1;
        unsigned int ibuf2core_dblk_rack : 2;
        unsigned int sao2dblk_wack : 1;
        unsigned int sao2pmv_wack : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG16_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_nbr_pmv_empty_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_nbr_pmv_empty_END (0)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_nbr_pmv_full_START (1)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_nbr_pmv_full_END (1)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_pmv_emtpy_START (2)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_pmv_emtpy_END (2)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_pmv_full_START (3)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_pmv_full_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_cmd_rptr_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_cmd_rptr_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_cmd_wptr_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_cmd_wptr_END (11)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_empty_START (12)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_empty_END (12)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_full_START (13)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_full_END (15)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_rptr_START (16)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_rptr_END (17)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_wptr_START (18)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf_dblk_wptr_END (19)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2nbr_pmv_rack_START (20)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2nbr_pmv_rack_END (20)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2core_pmv_rack_START (21)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2core_pmv_rack_END (21)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2core_dblk_rack_START (22)
#define SOC_VDEC_SAO_RD_BACK_REG16_ibuf2core_dblk_rack_END (23)
#define SOC_VDEC_SAO_RD_BACK_REG16_sao2dblk_wack_START (24)
#define SOC_VDEC_SAO_RD_BACK_REG16_sao2dblk_wack_END (24)
#define SOC_VDEC_SAO_RD_BACK_REG16_sao2pmv_wack_START (25)
#define SOC_VDEC_SAO_RD_BACK_REG16_sao2pmv_wack_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nbuf2nbr_rack : 1;
        unsigned int nbr2nbuf_rreq : 1;
        unsigned int nbuf2nbr_wack : 1;
        unsigned int nbr2nbuf_wreq : 1;
        unsigned int nbuf2core_rack : 1;
        unsigned int core2nbuf_rreq : 1;
        unsigned int nbuf2core_wack : 1;
        unsigned int core2nbuf_wreq : 1;
        unsigned int nbuf_nbr_top_empty : 1;
        unsigned int nbuf_nbr_top_full : 1;
        unsigned int nbuf_core_top_empty : 1;
        unsigned int nbuf_core_top_full : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_VDEC_SAO_RD_BACK_REG17_UNION;
#endif
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2nbr_rack_START (0)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2nbr_rack_END (0)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbr2nbuf_rreq_START (1)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbr2nbuf_rreq_END (1)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2nbr_wack_START (2)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2nbr_wack_END (2)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbr2nbuf_wreq_START (3)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbr2nbuf_wreq_END (3)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2core_rack_START (4)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2core_rack_END (4)
#define SOC_VDEC_SAO_RD_BACK_REG17_core2nbuf_rreq_START (5)
#define SOC_VDEC_SAO_RD_BACK_REG17_core2nbuf_rreq_END (5)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2core_wack_START (6)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf2core_wack_END (6)
#define SOC_VDEC_SAO_RD_BACK_REG17_core2nbuf_wreq_START (7)
#define SOC_VDEC_SAO_RD_BACK_REG17_core2nbuf_wreq_END (7)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_nbr_top_empty_START (8)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_nbr_top_empty_END (8)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_nbr_top_full_START (9)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_nbr_top_full_END (9)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_core_top_empty_START (10)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_core_top_empty_END (10)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_core_top_full_START (11)
#define SOC_VDEC_SAO_RD_BACK_REG17_nbuf_core_top_full_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int src_luma_base_addr : 32;
    } reg;
} SOC_VDEC_SRC_LUMA_ADDR_UNION;
#endif
#define SOC_VDEC_SRC_LUMA_ADDR_src_luma_base_addr_START (0)
#define SOC_VDEC_SRC_LUMA_ADDR_src_luma_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int src_chma_base_addr : 32;
    } reg;
} SOC_VDEC_SRC_CHROMA_ADDR_UNION;
#endif
#define SOC_VDEC_SRC_CHROMA_ADDR_src_chma_base_addr_START (0)
#define SOC_VDEC_SRC_CHROMA_ADDR_src_chma_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dst_luma_base_addr : 32;
    } reg;
} SOC_VDEC_DST_LUMA_ADDR_UNION;
#endif
#define SOC_VDEC_DST_LUMA_ADDR_dst_luma_base_addr_START (0)
#define SOC_VDEC_DST_LUMA_ADDR_dst_luma_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dst_chma_base_addr : 32;
    } reg;
} SOC_VDEC_DST_CHROMA_ADDR_UNION;
#endif
#define SOC_VDEC_DST_CHROMA_ADDR_dst_chma_base_addr_START (0)
#define SOC_VDEC_DST_CHROMA_ADDR_dst_chma_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ncmp_data_stride : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_VDEC_DATA_STRIDE_8BIT_UNION;
#endif
#define SOC_VDEC_DATA_STRIDE_8BIT_ncmp_data_stride_START (0)
#define SOC_VDEC_DATA_STRIDE_8BIT_ncmp_data_stride_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_offset : 32;
    } reg;
} SOC_VDEC_HEAD_INF_OFFSET_UNION;
#endif
#define SOC_VDEC_HEAD_INF_OFFSET_head_offset_START (0)
#define SOC_VDEC_HEAD_INF_OFFSET_head_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int img_width_in_mb : 9;
        unsigned int reserved_0 : 7;
        unsigned int img_height_in_mb : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_VDEC_PIC_IN_MB_UNION;
#endif
#define SOC_VDEC_PIC_IN_MB_img_width_in_mb_START (0)
#define SOC_VDEC_PIC_IN_MB_img_width_in_mb_END (8)
#define SOC_VDEC_PIC_IN_MB_img_height_in_mb_START (16)
#define SOC_VDEC_PIC_IN_MB_img_height_in_mb_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmd_num_min1 : 16;
        unsigned int frm_cmp_en : 1;
        unsigned int tile_linear_mode : 1;
        unsigned int bitdepth : 4;
        unsigned int src_lode_mode : 2;
        unsigned int dst_store_mode : 2;
        unsigned int reserved : 6;
    } reg;
} SOC_VDEC_TOTAL_GRP_UNION;
#endif
#define SOC_VDEC_TOTAL_GRP_dma_cmd_num_min1_START (0)
#define SOC_VDEC_TOTAL_GRP_dma_cmd_num_min1_END (15)
#define SOC_VDEC_TOTAL_GRP_frm_cmp_en_START (16)
#define SOC_VDEC_TOTAL_GRP_frm_cmp_en_END (16)
#define SOC_VDEC_TOTAL_GRP_tile_linear_mode_START (17)
#define SOC_VDEC_TOTAL_GRP_tile_linear_mode_END (17)
#define SOC_VDEC_TOTAL_GRP_bitdepth_START (18)
#define SOC_VDEC_TOTAL_GRP_bitdepth_END (21)
#define SOC_VDEC_TOTAL_GRP_src_lode_mode_START (22)
#define SOC_VDEC_TOTAL_GRP_src_lode_mode_END (23)
#define SOC_VDEC_TOTAL_GRP_dst_store_mode_START (24)
#define SOC_VDEC_TOTAL_GRP_dst_store_mode_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_start_mbx : 9;
        unsigned int reserved_0 : 7;
        unsigned int in_start_mby : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_VDEC_START_MB_UNION;
#endif
#define SOC_VDEC_START_MB_in_start_mbx_START (0)
#define SOC_VDEC_START_MB_in_start_mbx_END (8)
#define SOC_VDEC_START_MB_in_start_mby_START (16)
#define SOC_VDEC_START_MB_in_start_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_end_mbx : 9;
        unsigned int reserved_0 : 7;
        unsigned int in_end_mby : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_VDEC_END_MB_UNION;
#endif
#define SOC_VDEC_END_MB_in_end_mbx_START (0)
#define SOC_VDEC_END_MB_in_end_mbx_END (8)
#define SOC_VDEC_END_MB_in_end_mby_START (16)
#define SOC_VDEC_END_MB_in_end_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int in_mbx : 9;
        unsigned int reserved_0: 7;
        unsigned int in_mby : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_VDEC_IN_MB_UNION;
#endif
#define SOC_VDEC_IN_MB_in_mbx_START (0)
#define SOC_VDEC_IN_MB_in_mbx_END (8)
#define SOC_VDEC_IN_MB_in_mby_START (16)
#define SOC_VDEC_IN_MB_in_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int send_mbx : 9;
        unsigned int reserved_0: 7;
        unsigned int send_mby : 9;
        unsigned int reserved_1: 7;
    } reg;
} SOC_VDEC_SEND_MB_UNION;
#endif
#define SOC_VDEC_SEND_MB_send_mbx_START (0)
#define SOC_VDEC_SEND_MB_send_mbx_END (8)
#define SOC_VDEC_SEND_MB_send_mby_START (16)
#define SOC_VDEC_SEND_MB_send_mby_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_st_dma : 4;
        unsigned int cur_send_st : 3;
        unsigned int reserved_0 : 1;
        unsigned int cur_emar_st : 2;
        unsigned int reserved_1 : 6;
        unsigned int dma_cmd_cnt : 16;
    } reg;
} SOC_VDEC_DMA_CMD_UNION;
#endif
#define SOC_VDEC_DMA_CMD_cur_st_dma_START (0)
#define SOC_VDEC_DMA_CMD_cur_st_dma_END (3)
#define SOC_VDEC_DMA_CMD_cur_send_st_START (4)
#define SOC_VDEC_DMA_CMD_cur_send_st_END (6)
#define SOC_VDEC_DMA_CMD_cur_emar_st_START (8)
#define SOC_VDEC_DMA_CMD_cur_emar_st_END (9)
#define SOC_VDEC_DMA_CMD_dma_cmd_cnt_START (16)
#define SOC_VDEC_DMA_CMD_dma_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_inf_cnt : 8;
        unsigned int cmp_dat_cnt : 6;
        unsigned int reserved_0 : 2;
        unsigned int dma_in_cnt : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_VDEC_CNT0_UNION;
#endif
#define SOC_VDEC_CNT0_head_inf_cnt_START (0)
#define SOC_VDEC_CNT0_head_inf_cnt_END (7)
#define SOC_VDEC_CNT0_cmp_dat_cnt_START (8)
#define SOC_VDEC_CNT0_cmp_dat_cnt_END (13)
#define SOC_VDEC_CNT0_dma_in_cnt_START (16)
#define SOC_VDEC_CNT0_dma_in_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int send_part_cnt : 16;
        unsigned int send_inmb_cnt : 6;
        unsigned int sdat_cnt : 4;
        unsigned int wemar_data_cnt : 6;
    } reg;
} SOC_VDEC_CNT1_UNION;
#endif
#define SOC_VDEC_CNT1_send_part_cnt_START (0)
#define SOC_VDEC_CNT1_send_part_cnt_END (15)
#define SOC_VDEC_CNT1_send_inmb_cnt_START (16)
#define SOC_VDEC_CNT1_send_inmb_cnt_END (21)
#define SOC_VDEC_CNT1_sdat_cnt_START (22)
#define SOC_VDEC_CNT1_sdat_cnt_END (25)
#define SOC_VDEC_CNT1_wemar_data_cnt_START (26)
#define SOC_VDEC_CNT1_wemar_data_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ystride_nbit : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_VDEC_DATA_STRIDE_2BIT_UNION;
#endif
#define SOC_VDEC_DATA_STRIDE_2BIT_ystride_nbit_START (0)
#define SOC_VDEC_DATA_STRIDE_2BIT_ystride_nbit_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int yoffset_nbit : 32;
    } reg;
} SOC_VDEC_YOFFSET_2BIT_UNION;
#endif
#define SOC_VDEC_YOFFSET_2BIT_yoffset_nbit_START (0)
#define SOC_VDEC_YOFFSET_2BIT_yoffset_nbit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvoffset_nbit : 32;
    } reg;
} SOC_VDEC_UVOFFSET_2BIT_UNION;
#endif
#define SOC_VDEC_UVOFFSET_2BIT_uvoffset_nbit_START (0)
#define SOC_VDEC_UVOFFSET_2BIT_uvoffset_nbit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ystaddr : 32;
    } reg;
} SOC_VDEC_CMP_YSTADDR_UNION;
#endif
#define SOC_VDEC_CMP_YSTADDR_ystaddr_START (0)
#define SOC_VDEC_CMP_YSTADDR_ystaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvoffset : 32;
    } reg;
} SOC_VDEC_CMP_UVOFFSET_UNION;
#endif
#define SOC_VDEC_CMP_UVOFFSET_uvoffset_START (0)
#define SOC_VDEC_CMP_UVOFFSET_uvoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_ystride : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_VDEC_CMP_YSTRIDE_UNION;
#endif
#define SOC_VDEC_CMP_YSTRIDE_cfg_ystride_START (0)
#define SOC_VDEC_CMP_YSTRIDE_cfg_ystride_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int line_num_staddr : 32;
    } reg;
} SOC_VDEC_CMP_LINE_NUM_STADDR_UNION;
#endif
#define SOC_VDEC_CMP_LINE_NUM_STADDR_line_num_staddr_START (0)
#define SOC_VDEC_CMP_LINE_NUM_STADDR_line_num_staddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmp_line_level : 32;
    } reg;
} SOC_VDEC_CMP_LINE_LEVEL_UNION;
#endif
#define SOC_VDEC_CMP_LINE_LEVEL_cmp_line_level_START (0)
#define SOC_VDEC_CMP_LINE_LEVEL_cmp_line_level_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pic_width_other_protocol : 10;
        unsigned int pic_height_other_protocol : 10;
        unsigned int frm_cmp_en : 1;
        unsigned int protocol : 4;
        unsigned int reserved : 7;
    } reg;
} SOC_VDEC_CMP_PIC_INFO_OTHERS_UNION;
#endif
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_pic_width_other_protocol_START (0)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_pic_width_other_protocol_END (9)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_pic_height_other_protocol_START (10)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_pic_height_other_protocol_END (19)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_frm_cmp_en_START (20)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_frm_cmp_en_END (20)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_protocol_START (21)
#define SOC_VDEC_CMP_PIC_INFO_OTHERS_protocol_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pic_width_h265_protocol : 15;
        unsigned int pic_height_h265_protocol : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_VDEC_CMP_PIC_INFO_H265_UNION;
#endif
#define SOC_VDEC_CMP_PIC_INFO_H265_pic_width_h265_protocol_START (0)
#define SOC_VDEC_CMP_PIC_INFO_H265_pic_width_h265_protocol_END (14)
#define SOC_VDEC_CMP_PIC_INFO_H265_pic_height_h265_protocol_START (15)
#define SOC_VDEC_CMP_PIC_INFO_H265_pic_height_h265_protocol_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pic_width_in_sample : 15;
        unsigned int pic_height_in_sample : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_VDEC_CMP_PIC_PIX_INFO_UNION;
#endif
#define SOC_VDEC_CMP_PIC_PIX_INFO_pic_width_in_sample_START (0)
#define SOC_VDEC_CMP_PIC_PIX_INFO_pic_width_in_sample_END (14)
#define SOC_VDEC_CMP_PIC_PIX_INFO_pic_height_in_sample_START (15)
#define SOC_VDEC_CMP_PIC_PIX_INFO_pic_height_in_sample_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int c_bitdepth : 4;
        unsigned int y_bitdepth : 4;
        unsigned int cmp_ema : 2;
        unsigned int watermark_en : 1;
        unsigned int cmp_linear_mode : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_VDEC_CMP_BITDEPTH_UNION;
#endif
#define SOC_VDEC_CMP_BITDEPTH_c_bitdepth_START (0)
#define SOC_VDEC_CMP_BITDEPTH_c_bitdepth_END (3)
#define SOC_VDEC_CMP_BITDEPTH_y_bitdepth_START (4)
#define SOC_VDEC_CMP_BITDEPTH_y_bitdepth_END (7)
#define SOC_VDEC_CMP_BITDEPTH_cmp_ema_START (8)
#define SOC_VDEC_CMP_BITDEPTH_cmp_ema_END (9)
#define SOC_VDEC_CMP_BITDEPTH_watermark_en_START (10)
#define SOC_VDEC_CMP_BITDEPTH_watermark_en_END (10)
#define SOC_VDEC_CMP_BITDEPTH_cmp_linear_mode_START (11)
#define SOC_VDEC_CMP_BITDEPTH_cmp_linear_mode_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int head_stride : 16;
        unsigned int head_inf_size : 16;
    } reg;
} SOC_VDEC_CMP_HEAD_INF_SIZE_UNION;
#endif
#define SOC_VDEC_CMP_HEAD_INF_SIZE_head_stride_START (0)
#define SOC_VDEC_CMP_HEAD_INF_SIZE_head_stride_END (15)
#define SOC_VDEC_CMP_HEAD_INF_SIZE_head_inf_size_START (16)
#define SOC_VDEC_CMP_HEAD_INF_SIZE_head_inf_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int watermark_start_pose : 32;
    } reg;
} SOC_VDEC_CMP_WATERMARK_START_UNION;
#endif
#define SOC_VDEC_CMP_WATERMARK_START_watermark_start_pose_START (0)
#define SOC_VDEC_CMP_WATERMARK_START_watermark_start_pose_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int watermark_end_pose : 32;
    } reg;
} SOC_VDEC_CMP_WATERMARK_END_UNION;
#endif
#define SOC_VDEC_CMP_WATERMARK_END_watermark_end_pose_START (0)
#define SOC_VDEC_CMP_WATERMARK_END_watermark_end_pose_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int yoffset_2bit : 32;
    } reg;
} SOC_VDEC_CMP_YOFFSET_2BIT_UNION;
#endif
#define SOC_VDEC_CMP_YOFFSET_2BIT_yoffset_2bit_START (0)
#define SOC_VDEC_CMP_YOFFSET_2BIT_yoffset_2bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvoffset_2bit : 32;
    } reg;
} SOC_VDEC_CMP_UVOFFSET_2BIT_UNION;
#endif
#define SOC_VDEC_CMP_UVOFFSET_2BIT_uvoffset_2bit_START (0)
#define SOC_VDEC_CMP_UVOFFSET_2BIT_uvoffset_2bit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_st_wibuf : 2;
        unsigned int cur_st_nocmp : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_VDEC_CMP_STATE_MACHINE_UNION;
#endif
#define SOC_VDEC_CMP_STATE_MACHINE_cur_st_wibuf_START (0)
#define SOC_VDEC_CMP_STATE_MACHINE_cur_st_wibuf_END (1)
#define SOC_VDEC_CMP_STATE_MACHINE_cur_st_nocmp_START (2)
#define SOC_VDEC_CMP_STATE_MACHINE_cur_st_nocmp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_field_cnt : 7;
        unsigned int ibuf_field_wpt : 7;
        unsigned int ibuf_field_rpt : 7;
        unsigned int reserved : 11;
    } reg;
} SOC_VDEC_CMP_DEFAULT_UNION;
#endif
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_cnt_START (0)
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_cnt_END (6)
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_wpt_START (7)
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_wpt_END (13)
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_rpt_START (14)
#define SOC_VDEC_CMP_DEFAULT_ibuf_field_rpt_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_top_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SCD_START_UNION;
#endif
#define SOC_VDEC_SCD_START_scd_top_start_START (0)
#define SOC_VDEC_SCD_START_scd_top_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int List_base_addr : 32;
    } reg;
} SOC_VDEC_LIST_ADDRESS_UNION;
#endif
#define SOC_VDEC_LIST_ADDRESS_List_base_addr_START (0)
#define SOC_VDEC_LIST_ADDRESS_List_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Up_base_address : 32;
    } reg;
} SOC_VDEC_UP_ADDRESS_UNION;
#endif
#define SOC_VDEC_UP_ADDRESS_Up_base_address_START (0)
#define SOC_VDEC_UP_ADDRESS_Up_base_address_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Up_length : 32;
    } reg;
} SOC_VDEC_UP_LEN_UNION;
#endif
#define SOC_VDEC_UP_LEN_Up_length_START (0)
#define SOC_VDEC_UP_LEN_Up_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buffer_first_addr : 32;
    } reg;
} SOC_VDEC_BUFFER_FIRST_UNION;
#endif
#define SOC_VDEC_BUFFER_FIRST_buffer_first_addr_START (0)
#define SOC_VDEC_BUFFER_FIRST_buffer_first_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Buffer_last_addr : 32;
    } reg;
} SOC_VDEC_BUFFER_LAST_UNION;
#endif
#define SOC_VDEC_BUFFER_LAST_Buffer_last_addr_START (0)
#define SOC_VDEC_BUFFER_LAST_Buffer_last_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Buffer_ini_addr : 32;
    } reg;
} SOC_VDEC_BUFFER_INI_UNION;
#endif
#define SOC_VDEC_BUFFER_INI_Buffer_ini_addr_START (0)
#define SOC_VDEC_BUFFER_INI_Buffer_ini_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Scd_norm_intr_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SCD_NORM_INT_MASK_UNION;
#endif
#define SOC_VDEC_SCD_NORM_INT_MASK_Scd_norm_intr_mask_START (0)
#define SOC_VDEC_SCD_NORM_INT_MASK_Scd_norm_intr_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Scd_protocol : 4;
        unsigned int Slice_check_flag : 1;
        unsigned int Mpeg4_fpga_flag : 1;
        unsigned int Pes_check_flag : 1;
        unsigned int scd_safe_mode : 1;
        unsigned int Scd_lowdly_en : 1;
        unsigned int other_mmu_en : 1;
        unsigned int scd_ema : 3;
        unsigned int rdbuf_mmu_en : 1;
        unsigned int cfg_metadata_en : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_VDEC_SCD__PROTOCOL_UNION;
#endif
#define SOC_VDEC_SCD__PROTOCOL_Scd_protocol_START (0)
#define SOC_VDEC_SCD__PROTOCOL_Scd_protocol_END (3)
#define SOC_VDEC_SCD__PROTOCOL_Slice_check_flag_START (4)
#define SOC_VDEC_SCD__PROTOCOL_Slice_check_flag_END (4)
#define SOC_VDEC_SCD__PROTOCOL_Mpeg4_fpga_flag_START (5)
#define SOC_VDEC_SCD__PROTOCOL_Mpeg4_fpga_flag_END (5)
#define SOC_VDEC_SCD__PROTOCOL_Pes_check_flag_START (6)
#define SOC_VDEC_SCD__PROTOCOL_Pes_check_flag_END (6)
#define SOC_VDEC_SCD__PROTOCOL_scd_safe_mode_START (7)
#define SOC_VDEC_SCD__PROTOCOL_scd_safe_mode_END (7)
#define SOC_VDEC_SCD__PROTOCOL_Scd_lowdly_en_START (8)
#define SOC_VDEC_SCD__PROTOCOL_Scd_lowdly_en_END (8)
#define SOC_VDEC_SCD__PROTOCOL_other_mmu_en_START (9)
#define SOC_VDEC_SCD__PROTOCOL_other_mmu_en_END (9)
#define SOC_VDEC_SCD__PROTOCOL_scd_ema_START (10)
#define SOC_VDEC_SCD__PROTOCOL_scd_ema_END (12)
#define SOC_VDEC_SCD__PROTOCOL_rdbuf_mmu_en_START (13)
#define SOC_VDEC_SCD__PROTOCOL_rdbuf_mmu_en_END (13)
#define SOC_VDEC_SCD__PROTOCOL_cfg_metadata_en_START (14)
#define SOC_VDEC_SCD__PROTOCOL_cfg_metadata_en_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_norm_int_flag : 1;
        unsigned int scd_int_flag : 31;
    } reg;
} SOC_VDEC_SCD_NORM_INI_CLR_UNION;
#endif
#define SOC_VDEC_SCD_NORM_INI_CLR_scd_norm_int_flag_START (0)
#define SOC_VDEC_SCD_NORM_INI_CLR_scd_norm_int_flag_END (0)
#define SOC_VDEC_SCD_NORM_INI_CLR_scd_int_flag_START (1)
#define SOC_VDEC_SCD_NORM_INI_CLR_scd_int_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_sps_addr : 32;
    } reg;
} SOC_VDEC_DSP_SPS_ADDR_UNION;
#endif
#define SOC_VDEC_DSP_SPS_ADDR_dsp_sps_addr_START (0)
#define SOC_VDEC_DSP_SPS_ADDR_dsp_sps_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_pps_addr : 32;
    } reg;
} SOC_VDEC_DSP_PPS_ADDR_UNION;
#endif
#define SOC_VDEC_DSP_PPS_ADDR_dsp_pps_addr_START (0)
#define SOC_VDEC_DSP_PPS_ADDR_dsp_pps_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_msg_addr : 32;
    } reg;
} SOC_VDEC_DSP_MSG_ADDR_UNION;
#endif
#define SOC_VDEC_DSP_MSG_ADDR_dsp_msg_addr_START (0)
#define SOC_VDEC_DSP_MSG_ADDR_dsp_msg_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_top_addr : 32;
    } reg;
} SOC_VDEC_DSP_TOP_ADDR_UNION;
#endif
#define SOC_VDEC_DSP_TOP_ADDR_dsp_top_addr_START (0)
#define SOC_VDEC_DSP_TOP_ADDR_dsp_top_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_camn_addr : 32;
    } reg;
} SOC_VDEC_DSP_CAMN_ADDR_UNION;
#endif
#define SOC_VDEC_DSP_CAMN_ADDR_dsp_camn_addr_START (0)
#define SOC_VDEC_DSP_CAMN_ADDR_dsp_camn_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_previous_byte_lsb : 32;
    } reg;
} SOC_VDEC_SCD_PREVIOUS_LSB_UNION;
#endif
#define SOC_VDEC_SCD_PREVIOUS_LSB_scd_previous_byte_lsb_START (0)
#define SOC_VDEC_SCD_PREVIOUS_LSB_scd_previous_byte_lsb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_int_flag : 1;
        unsigned int scd_rst_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_SCD_INT_FLAG_UNION;
#endif
#define SOC_VDEC_SCD_INT_FLAG_scd_int_flag_START (0)
#define SOC_VDEC_SCD_INT_FLAG_scd_int_flag_END (0)
#define SOC_VDEC_SCD_INT_FLAG_scd_rst_busy_START (1)
#define SOC_VDEC_SCD_INT_FLAG_scd_rst_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_previous_byte_msb : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_VDEC_SCD_PREVIOUS_MSB_UNION;
#endif
#define SOC_VDEC_SCD_PREVIOUS_MSB_scd_previous_byte_msb_START (0)
#define SOC_VDEC_SCD_PREVIOUS_MSB_scd_previous_byte_msb_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_bytes_valid : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_VDEC_SCD_BYTE_VALID_UNION;
#endif
#define SOC_VDEC_SCD_BYTE_VALID_scd_bytes_valid_START (0)
#define SOC_VDEC_SCD_BYTE_VALID_scd_bytes_valid_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_num_out : 22;
        unsigned int short_header_num : 10;
    } reg;
} SOC_VDEC_SCD_NUMBER_UNION;
#endif
#define SOC_VDEC_SCD_NUMBER_scd_num_out_START (0)
#define SOC_VDEC_SCD_NUMBER_scd_num_out_END (21)
#define SOC_VDEC_SCD_NUMBER_short_header_num_START (22)
#define SOC_VDEC_SCD_NUMBER_short_header_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int roll_addr : 32;
    } reg;
} SOC_VDEC_RLL_ADDR_UNION;
#endif
#define SOC_VDEC_RLL_ADDR_roll_addr_START (0)
#define SOC_VDEC_RLL_ADDR_roll_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scr_eaten[30:0] : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_VDEC_SCR_RAT_UNION;
#endif
#define SOC_VDEC_SCR_RAT_scr_eaten [30:0]_START (0)
#define SOC_VDEC_SCR_RAT_scr_eaten [30:0]_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int seg_buffer_offset : 32;
    } reg;
} SOC_VDEC_SCR_OFFSET_UNION;
#endif
#define SOC_VDEC_SCR_OFFSET_seg_buffer_offset_START (0)
#define SOC_VDEC_SCR_OFFSET_seg_buffer_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int seg_next_addr : 32;
    } reg;
} SOC_VDEC_SCR_NXT_ADDR_UNION;
#endif
#define SOC_VDEC_SCR_NXT_ADDR_seg_next_addr_START (0)
#define SOC_VDEC_SCR_NXT_ADDR_seg_next_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_sta_main : 7;
        unsigned int reserved_0 : 1;
        unsigned int cur_sta_det : 4;
        unsigned int reserved_1 : 4;
        unsigned int cur_sta_rdat : 4;
        unsigned int cur_sta_wdat : 4;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_VDEC_STA_UNION;
#endif
#define SOC_VDEC_STA_cur_sta_main_START (0)
#define SOC_VDEC_STA_cur_sta_main_END (6)
#define SOC_VDEC_STA_cur_sta_det_START (8)
#define SOC_VDEC_STA_cur_sta_det_END (11)
#define SOC_VDEC_STA_cur_sta_rdat_START (16)
#define SOC_VDEC_STA_cur_sta_rdat_END (19)
#define SOC_VDEC_STA_cur_sta_wdat_START (20)
#define SOC_VDEC_STA_cur_sta_wdat_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdwr_curr_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int sdwr_cnt_burst : 4;
        unsigned int sdwr_num_burst : 5;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_VDEC_SDWR_UNION;
#endif
#define SOC_VDEC_SDWR_sdwr_curr_state_START (0)
#define SOC_VDEC_SDWR_sdwr_curr_state_END (2)
#define SOC_VDEC_SDWR_sdwr_cnt_burst_START (4)
#define SOC_VDEC_SDWR_sdwr_cnt_burst_END (7)
#define SOC_VDEC_SDWR_sdwr_num_burst_START (8)
#define SOC_VDEC_SDWR_sdwr_num_burst_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_run_cycle : 32;
    } reg;
} SOC_VDEC_RUN_CYCLE_UNION;
#endif
#define SOC_VDEC_RUN_CYCLE_scd_run_cycle_START (0)
#define SOC_VDEC_RUN_CYCLE_scd_run_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_req_num : 32;
    } reg;
} SOC_VDEC_SCD_RD_REQ_UNION;
#endif
#define SOC_VDEC_SCD_RD_REQ_rd_req_num_START (0)
#define SOC_VDEC_SCD_RD_REQ_rd_req_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_dat_num : 32;
    } reg;
} SOC_VDEC_SCD_RD_DAT_UNION;
#endif
#define SOC_VDEC_SCD_RD_DAT_rd_dat_num_START (0)
#define SOC_VDEC_SCD_RD_DAT_rd_dat_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_req_num : 32;
    } reg;
} SOC_VDEC_SCD_WR_REQ_UNION;
#endif
#define SOC_VDEC_SCD_WR_REQ_wr_req_num_START (0)
#define SOC_VDEC_SCD_WR_REQ_wr_req_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_dat_num : 32;
    } reg;
} SOC_VDEC_SCD_WR_DAT_UNION;
#endif
#define SOC_VDEC_SCD_WR_DAT_wr_dat_num_START (0)
#define SOC_VDEC_SCD_WR_DAT_wr_dat_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_scd_st : 32;
    } reg;
} SOC_VDEC_SCD_WORK_ST_UNION;
#endif
#define SOC_VDEC_SCD_WORK_ST_cur_scd_st_START (0)
#define SOC_VDEC_SCD_WORK_ST_cur_scd_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_cfg[1:0] : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_SCD_CLK_CFG_UNION;
#endif
#define SOC_VDEC_SCD_CLK_CFG_clk_cfg [1:0]_START (0)
#define SOC_VDEC_SCD_CLK_CFG_clk_cfg [1:0]_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_arbit_dg0 : 32;
    } reg;
} SOC_VDEC_SCD_ARBIT_DG0_UNION;
#endif
#define SOC_VDEC_SCD_ARBIT_DG0_scd_arbit_dg0_START (0)
#define SOC_VDEC_SCD_ARBIT_DG0_scd_arbit_dg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_arbit_dg1 : 32;
    } reg;
} SOC_VDEC_SCD_ARBIT_DG1_UNION;
#endif
#define SOC_VDEC_SCD_ARBIT_DG1_scd_arbit_dg1_START (0)
#define SOC_VDEC_SCD_ARBIT_DG1_scd_arbit_dg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_c2a_fifo_dg : 32;
    } reg;
} SOC_VDEC_SCD_ARBIT_DG2_UNION;
#endif
#define SOC_VDEC_SCD_ARBIT_DG2_rcmd_c2a_fifo_dg_START (0)
#define SOC_VDEC_SCD_ARBIT_DG2_rcmd_c2a_fifo_dg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wcmd_c2a_fifo_dg : 32;
    } reg;
} SOC_VDEC_SCD_ARBIT_DG3_UNION;
#endif
#define SOC_VDEC_SCD_ARBIT_DG3_wcmd_c2a_fifo_dg_START (0)
#define SOC_VDEC_SCD_ARBIT_DG3_wcmd_c2a_fifo_dg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int softrst_state0 : 32;
    } reg;
} SOC_VDEC_SCD_SOFTRST_DG0_UNION;
#endif
#define SOC_VDEC_SCD_SOFTRST_DG0_softrst_state0_START (0)
#define SOC_VDEC_SCD_SOFTRST_DG0_softrst_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int softrst_state1 : 32;
    } reg;
} SOC_VDEC_SCD_SOFTRST_DG1_UNION;
#endif
#define SOC_VDEC_SCD_SOFTRST_DG1_softrst_state1_START (0)
#define SOC_VDEC_SCD_SOFTRST_DG1_softrst_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Scd_safe_intr_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SCD_SAFE_INT_MASK_UNION;
#endif
#define SOC_VDEC_SCD_SAFE_INT_MASK_Scd_safe_intr_mask_START (0)
#define SOC_VDEC_SCD_SAFE_INT_MASK_Scd_safe_intr_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scd_safe_int_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VDEC_SCD_SAFE_INI_CLR_UNION;
#endif
#define SOC_VDEC_SCD_SAFE_INI_CLR_scd_safe_int_flag_START (0)
#define SOC_VDEC_SCD_SAFE_INI_CLR_scd_safe_int_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int is_avsplus : 1;
        unsigned int test_reserve0 : 31;
    } reg;
} SOC_VDEC_AVS_PLUS_UNION;
#endif
#define SOC_VDEC_AVS_PLUS_is_avsplus_START (0)
#define SOC_VDEC_AVS_PLUS_is_avsplus_END (0)
#define SOC_VDEC_AVS_PLUS_test_reserve0_START (1)
#define SOC_VDEC_AVS_PLUS_test_reserve0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sep_typ : 2;
        unsigned int reserved_0 : 2;
        unsigned int axi_4k_bypass : 1;
        unsigned int reserved_1 : 3;
        unsigned int acfg2arb_ramtype : 2;
        unsigned int reserved_2 : 2;
        unsigned int acfg2arb_repeat_cnt : 4;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_VDEC_EMAR_ADDR_UNION;
#endif
#define SOC_VDEC_EMAR_ADDR_axi_sep_typ_START (0)
#define SOC_VDEC_EMAR_ADDR_axi_sep_typ_END (1)
#define SOC_VDEC_EMAR_ADDR_axi_4k_bypass_START (4)
#define SOC_VDEC_EMAR_ADDR_axi_4k_bypass_END (4)
#define SOC_VDEC_EMAR_ADDR_acfg2arb_ramtype_START (8)
#define SOC_VDEC_EMAR_ADDR_acfg2arb_ramtype_END (9)
#define SOC_VDEC_EMAR_ADDR_acfg2arb_repeat_cnt_START (12)
#define SOC_VDEC_EMAR_ADDR_acfg2arb_repeat_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rstself_or_no : 1;
        unsigned int debug_en : 1;
        unsigned int test_reserve1 : 30;
    } reg;
} SOC_VDEC_VDH_RST_EN_UNION;
#endif
#define SOC_VDEC_VDH_RST_EN_rstself_or_no_START (0)
#define SOC_VDEC_VDH_RST_EN_rstself_or_no_END (0)
#define SOC_VDEC_VDH_RST_EN_debug_en_START (1)
#define SOC_VDEC_VDH_RST_EN_debug_en_END (1)
#define SOC_VDEC_VDH_RST_EN_test_reserve1_START (2)
#define SOC_VDEC_VDH_RST_EN_test_reserve1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clock_gating_en : 1;
        unsigned int memroy_clock_gating_en_tmp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_CK_GT_EN_UNION;
#endif
#define SOC_VDEC_CK_GT_EN_module_clock_gating_en_START (0)
#define SOC_VDEC_CK_GT_EN_module_clock_gating_en_END (0)
#define SOC_VDEC_CK_GT_EN_memroy_clock_gating_en_tmp_START (1)
#define SOC_VDEC_CK_GT_EN_memroy_clock_gating_en_tmp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_use_state : 32;
    } reg;
} SOC_VDEC_VDH_USE_STATE_UNION;
#endif
#define SOC_VDEC_VDH_USE_STATE_vdh_use_state_START (0)
#define SOC_VDEC_VDH_USE_STATE_vdh_use_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int over_time : 32;
    } reg;
} SOC_VDEC_OVER_TIME_UNION;
#endif
#define SOC_VDEC_OVER_TIME_over_time_START (0)
#define SOC_VDEC_OVER_TIME_over_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_default_arqos : 3;
        unsigned int reserved_0 : 1;
        unsigned int cfg_prc_data_arqos : 3;
        unsigned int reserved_1 : 1;
        unsigned int cfg_prc_head_arqos : 3;
        unsigned int reserved_2 : 1;
        unsigned int cfg_arqos_flag : 1;
        unsigned int reserved_3 : 19;
    } reg;
} SOC_VDEC_VDH_ARQOS_UNION;
#endif
#define SOC_VDEC_VDH_ARQOS_cfg_default_arqos_START (0)
#define SOC_VDEC_VDH_ARQOS_cfg_default_arqos_END (2)
#define SOC_VDEC_VDH_ARQOS_cfg_prc_data_arqos_START (4)
#define SOC_VDEC_VDH_ARQOS_cfg_prc_data_arqos_END (6)
#define SOC_VDEC_VDH_ARQOS_cfg_prc_head_arqos_START (8)
#define SOC_VDEC_VDH_ARQOS_cfg_prc_head_arqos_END (10)
#define SOC_VDEC_VDH_ARQOS_cfg_arqos_flag_START (12)
#define SOC_VDEC_VDH_ARQOS_cfg_arqos_flag_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_arqos_cycle : 32;
    } reg;
} SOC_VDEC_VDH_ARQOS_CYCLE_UNION;
#endif
#define SOC_VDEC_VDH_ARQOS_CYCLE_vdh_arqos_cycle_START (0)
#define SOC_VDEC_VDH_ARQOS_CYCLE_vdh_arqos_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_arqos_numbers : 32;
    } reg;
} SOC_VDEC_VDH_ARQOS_NUMBERS_UNION;
#endif
#define SOC_VDEC_VDH_ARQOS_NUMBERS_vdh_arqos_numbers_START (0)
#define SOC_VDEC_VDH_ARQOS_NUMBERS_vdh_arqos_numbers_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acfg2arb_ch0_max_repeat : 6;
        unsigned int reserved_0 : 2;
        unsigned int acfg2arb_ch1_max_repeat : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_VDEC_EMAR_ADDR1_UNION;
#endif
#define SOC_VDEC_EMAR_ADDR1_acfg2arb_ch0_max_repeat_START (0)
#define SOC_VDEC_EMAR_ADDR1_acfg2arb_ch0_max_repeat_END (5)
#define SOC_VDEC_EMAR_ADDR1_acfg2arb_ch1_max_repeat_START (8)
#define SOC_VDEC_EMAR_ADDR1_acfg2arb_ch1_max_repeat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mfde_force_req_ack : 1;
        unsigned int scd_force_req_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_VDH_FORCE_REQ_ACK_UNION;
#endif
#define SOC_VDEC_VDH_FORCE_REQ_ACK_mfde_force_req_ack_START (0)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_mfde_force_req_ack_END (0)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_scd_force_req_ack_START (1)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_scd_force_req_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_rfs : 32;
    } reg;
} SOC_VDEC_VDH_RFS_EMA_UNION;
#endif
#define SOC_VDEC_VDH_RFS_EMA_mem_ctrl_rfs_START (0)
#define SOC_VDEC_VDH_RFS_EMA_mem_ctrl_rfs_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_tpram_rft : 16;
        unsigned int mem_ctrl_bpram_rft : 16;
    } reg;
} SOC_VDEC_VDH_RFT_EMA_UNION;
#endif
#define SOC_VDEC_VDH_RFT_EMA_mem_ctrl_tpram_rft_START (0)
#define SOC_VDEC_VDH_RFT_EMA_mem_ctrl_tpram_rft_END (15)
#define SOC_VDEC_VDH_RFT_EMA_mem_ctrl_bpram_rft_START (16)
#define SOC_VDEC_VDH_RFT_EMA_mem_ctrl_bpram_rft_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_rom : 32;
    } reg;
} SOC_VDEC_VDH_ROM_EMA_UNION;
#endif
#define SOC_VDEC_VDH_ROM_EMA_mem_ctrl_rom_START (0)
#define SOC_VDEC_VDH_ROM_EMA_mem_ctrl_rom_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_vdec_clken : 2;
        unsigned int vdh_dsp_clken : 2;
        unsigned int vdh_mmu_clken : 2;
        unsigned int vdh_bpd_clken : 2;
        unsigned int vdh_scd_clken : 2;
        unsigned int vdh_mfde_clken : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_VDEC_VDH_CLKSEL_UNION;
#endif
#define SOC_VDEC_VDH_CLKSEL_vdh_vdec_clken_START (0)
#define SOC_VDEC_VDH_CLKSEL_vdh_vdec_clken_END (1)
#define SOC_VDEC_VDH_CLKSEL_vdh_dsp_clken_START (2)
#define SOC_VDEC_VDH_CLKSEL_vdh_dsp_clken_END (3)
#define SOC_VDEC_VDH_CLKSEL_vdh_mmu_clken_START (4)
#define SOC_VDEC_VDH_CLKSEL_vdh_mmu_clken_END (5)
#define SOC_VDEC_VDH_CLKSEL_vdh_bpd_clken_START (6)
#define SOC_VDEC_VDH_CLKSEL_vdh_bpd_clken_END (7)
#define SOC_VDEC_VDH_CLKSEL_vdh_scd_clken_START (8)
#define SOC_VDEC_VDH_CLKSEL_vdh_scd_clken_END (9)
#define SOC_VDEC_VDH_CLKSEL_vdh_mfde_clken_START (10)
#define SOC_VDEC_VDH_CLKSEL_vdh_mfde_clken_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_apb_clken : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_VDHAPB_CLKSEL_UNION;
#endif
#define SOC_VDEC_VDHAPB_CLKSEL_vdh_apb_clken_START (0)
#define SOC_VDEC_VDHAPB_CLKSEL_vdh_apb_clken_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_all_srst_req : 1;
        unsigned int vdh_mfde_srst_req : 1;
        unsigned int vdh_scd_srst_req : 1;
        unsigned int vdh_bpd_srst_req : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VDEC_VDH_SRST_REQ_UNION;
#endif
#define SOC_VDEC_VDH_SRST_REQ_vdh_all_srst_req_START (0)
#define SOC_VDEC_VDH_SRST_REQ_vdh_all_srst_req_END (0)
#define SOC_VDEC_VDH_SRST_REQ_vdh_mfde_srst_req_START (1)
#define SOC_VDEC_VDH_SRST_REQ_vdh_mfde_srst_req_END (1)
#define SOC_VDEC_VDH_SRST_REQ_vdh_scd_srst_req_START (2)
#define SOC_VDEC_VDH_SRST_REQ_vdh_scd_srst_req_END (2)
#define SOC_VDEC_VDH_SRST_REQ_vdh_bpd_srst_req_START (3)
#define SOC_VDEC_VDH_SRST_REQ_vdh_bpd_srst_req_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdh_all_srst_ok : 1;
        unsigned int vdh_mfde_srst_ok : 1;
        unsigned int vdh_scd_srst_ok : 1;
        unsigned int vdh_bpd_srst_ok : 1;
        unsigned int vdh_idle : 1;
        unsigned int vdh_bpd_idle : 1;
        unsigned int vdh_scd_idle : 1;
        unsigned int vdh_mfde_idle : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_VDEC_VDH_SRST_ST_UNION;
#endif
#define SOC_VDEC_VDH_SRST_ST_vdh_all_srst_ok_START (0)
#define SOC_VDEC_VDH_SRST_ST_vdh_all_srst_ok_END (0)
#define SOC_VDEC_VDH_SRST_ST_vdh_mfde_srst_ok_START (1)
#define SOC_VDEC_VDH_SRST_ST_vdh_mfde_srst_ok_END (1)
#define SOC_VDEC_VDH_SRST_ST_vdh_scd_srst_ok_START (2)
#define SOC_VDEC_VDH_SRST_ST_vdh_scd_srst_ok_END (2)
#define SOC_VDEC_VDH_SRST_ST_vdh_bpd_srst_ok_START (3)
#define SOC_VDEC_VDH_SRST_ST_vdh_bpd_srst_ok_END (3)
#define SOC_VDEC_VDH_SRST_ST_vdh_idle_START (4)
#define SOC_VDEC_VDH_SRST_ST_vdh_idle_END (4)
#define SOC_VDEC_VDH_SRST_ST_vdh_bpd_idle_START (5)
#define SOC_VDEC_VDH_SRST_ST_vdh_bpd_idle_END (5)
#define SOC_VDEC_VDH_SRST_ST_vdh_scd_idle_START (6)
#define SOC_VDEC_VDH_SRST_ST_vdh_scd_idle_END (6)
#define SOC_VDEC_VDH_SRST_ST_vdh_mfde_idle_START (7)
#define SOC_VDEC_VDH_SRST_ST_vdh_mfde_idle_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acfg2arb_wosd : 4;
        unsigned int acfg2arb_rosd : 8;
        unsigned int acfg2arb_mid_en : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_VDEC_EMAR_OUTSANDING_UNION;
#endif
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_wosd_START (0)
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_wosd_END (3)
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_rosd_START (4)
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_rosd_END (11)
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_mid_en_START (12)
#define SOC_VDEC_EMAR_OUTSANDING_acfg2arb_mid_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int all_r_arbit_mid_rrmax0 : 5;
        unsigned int all_r_arbit_mid_rrmax1 : 5;
        unsigned int all_r_arbit_mid_rrmax2 : 5;
        unsigned int all_r_arbit_mid_rrmax3 : 5;
        unsigned int all_r_arbit_mid_rrmax4 : 5;
        unsigned int reserved : 7;
    } reg;
} SOC_VDEC_ALL_R_MID_RRMAX_UNION;
#endif
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax0_START (0)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax0_END (4)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax1_START (5)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax1_END (9)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax2_START (10)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax2_END (14)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax3_START (15)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax3_END (19)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax4_START (20)
#define SOC_VDEC_ALL_R_MID_RRMAX_all_r_arbit_mid_rrmax4_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_bg_kind : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_R_BG_ADJUST_UNION;
#endif
#define SOC_VDEC_R_BG_ADJUST_cfg_bg_kind_START (0)
#define SOC_VDEC_R_BG_ADJUST_cfg_bg_kind_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bpd_force_req_ack : 1;
        unsigned int vdh_force_req_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_UNION;
#endif
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_bpd_force_req_ack_START (0)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_bpd_force_req_ack_END (0)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_vdh_force_req_ack_START (1)
#define SOC_VDEC_VDH_FORCE_REQ_ACK_AXI_vdh_force_req_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rcmd_chn_cnt : 7;
        unsigned int reserved : 1;
        unsigned int cur_rcmd_st : 4;
        unsigned int ch3_signal : 4;
        unsigned int ch2_signal : 4;
        unsigned int ch1_signal : 4;
        unsigned int ch0_signal : 4;
        unsigned int sel_signal : 4;
    } reg;
} SOC_VDEC_ALL_R_MID_INFO_UNION;
#endif
#define SOC_VDEC_ALL_R_MID_INFO_rcmd_chn_cnt_START (0)
#define SOC_VDEC_ALL_R_MID_INFO_rcmd_chn_cnt_END (6)
#define SOC_VDEC_ALL_R_MID_INFO_cur_rcmd_st_START (8)
#define SOC_VDEC_ALL_R_MID_INFO_cur_rcmd_st_END (11)
#define SOC_VDEC_ALL_R_MID_INFO_ch3_signal_START (12)
#define SOC_VDEC_ALL_R_MID_INFO_ch3_signal_END (15)
#define SOC_VDEC_ALL_R_MID_INFO_ch2_signal_START (16)
#define SOC_VDEC_ALL_R_MID_INFO_ch2_signal_END (19)
#define SOC_VDEC_ALL_R_MID_INFO_ch1_signal_START (20)
#define SOC_VDEC_ALL_R_MID_INFO_ch1_signal_END (23)
#define SOC_VDEC_ALL_R_MID_INFO_ch0_signal_START (24)
#define SOC_VDEC_ALL_R_MID_INFO_ch0_signal_END (27)
#define SOC_VDEC_ALL_R_MID_INFO_sel_signal_START (28)
#define SOC_VDEC_ALL_R_MID_INFO_sel_signal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cur_wcmd_st : 3;
        unsigned int reserved_0 : 1;
        unsigned int wcmd_chn_cnt : 2;
        unsigned int wcmd_b_chn_cnt : 6;
        unsigned int reserved_1 : 2;
        unsigned int ch1_signal : 6;
        unsigned int ch0_signal : 6;
        unsigned int sel_signal : 6;
    } reg;
} SOC_VDEC_ALL_W_MID_INFO_UNION;
#endif
#define SOC_VDEC_ALL_W_MID_INFO_cur_wcmd_st_START (0)
#define SOC_VDEC_ALL_W_MID_INFO_cur_wcmd_st_END (2)
#define SOC_VDEC_ALL_W_MID_INFO_wcmd_chn_cnt_START (4)
#define SOC_VDEC_ALL_W_MID_INFO_wcmd_chn_cnt_END (5)
#define SOC_VDEC_ALL_W_MID_INFO_wcmd_b_chn_cnt_START (6)
#define SOC_VDEC_ALL_W_MID_INFO_wcmd_b_chn_cnt_END (11)
#define SOC_VDEC_ALL_W_MID_INFO_ch1_signal_START (14)
#define SOC_VDEC_ALL_W_MID_INFO_ch1_signal_END (19)
#define SOC_VDEC_ALL_W_MID_INFO_ch0_signal_START (20)
#define SOC_VDEC_ALL_W_MID_INFO_ch0_signal_END (25)
#define SOC_VDEC_ALL_W_MID_INFO_sel_signal_START (26)
#define SOC_VDEC_ALL_W_MID_INFO_sel_signal_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bus_ready_sig : 8;
        unsigned int cbb_ready_sig : 8;
        unsigned int cbb_valid_sig : 8;
        unsigned int bus_valid_sig : 8;
    } reg;
} SOC_VDEC_AXI_SOFTRST_STATE0_UNION;
#endif
#define SOC_VDEC_AXI_SOFTRST_STATE0_bus_ready_sig_START (0)
#define SOC_VDEC_AXI_SOFTRST_STATE0_bus_ready_sig_END (7)
#define SOC_VDEC_AXI_SOFTRST_STATE0_cbb_ready_sig_START (8)
#define SOC_VDEC_AXI_SOFTRST_STATE0_cbb_ready_sig_END (15)
#define SOC_VDEC_AXI_SOFTRST_STATE0_cbb_valid_sig_START (16)
#define SOC_VDEC_AXI_SOFTRST_STATE0_cbb_valid_sig_END (23)
#define SOC_VDEC_AXI_SOFTRST_STATE0_bus_valid_sig_START (24)
#define SOC_VDEC_AXI_SOFTRST_STATE0_bus_valid_sig_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int wr_cnt : 6;
        unsigned int reserved_1 : 2;
        unsigned int wr_aw_wlast_cnt : 6;
        unsigned int reserved_2 : 2;
        unsigned int srcw_cur_fsm : 2;
        unsigned int srcr_cur_fsm : 2;
        unsigned int bus_axi_rst_req : 1;
        unsigned int bus_axi_rst_ack : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_VDEC_AXI_SOFTRST_STATE1_UNION;
#endif
#define SOC_VDEC_AXI_SOFTRST_STATE1_rd_cnt_START (0)
#define SOC_VDEC_AXI_SOFTRST_STATE1_rd_cnt_END (6)
#define SOC_VDEC_AXI_SOFTRST_STATE1_wr_cnt_START (8)
#define SOC_VDEC_AXI_SOFTRST_STATE1_wr_cnt_END (13)
#define SOC_VDEC_AXI_SOFTRST_STATE1_wr_aw_wlast_cnt_START (16)
#define SOC_VDEC_AXI_SOFTRST_STATE1_wr_aw_wlast_cnt_END (21)
#define SOC_VDEC_AXI_SOFTRST_STATE1_srcw_cur_fsm_START (24)
#define SOC_VDEC_AXI_SOFTRST_STATE1_srcw_cur_fsm_END (25)
#define SOC_VDEC_AXI_SOFTRST_STATE1_srcr_cur_fsm_START (26)
#define SOC_VDEC_AXI_SOFTRST_STATE1_srcr_cur_fsm_END (27)
#define SOC_VDEC_AXI_SOFTRST_STATE1_bus_axi_rst_req_START (28)
#define SOC_VDEC_AXI_SOFTRST_STATE1_bus_axi_rst_req_END (28)
#define SOC_VDEC_AXI_SOFTRST_STATE1_bus_axi_rst_ack_START (29)
#define SOC_VDEC_AXI_SOFTRST_STATE1_bus_axi_rst_ack_END (29)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
