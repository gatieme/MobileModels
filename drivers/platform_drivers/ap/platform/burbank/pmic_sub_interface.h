#ifndef __SUB_SUB_PMIC_HI6422V500_INTERFACE_H__
#define __SUB_SUB_PMIC_HI6422V500_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x0000UL))
#define SUB_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x0001UL))
#define SUB_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x0002UL))
#define SUB_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x0003UL))
#define SUB_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x0004UL))
#define SUB_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x0005UL))
#define SUB_PMIC_STATUS0_ADDR(base) ((base) + (0x0006UL))
#define SUB_PMIC_OCP_SCP_STATUS_ADDR(base) ((base) + (0x0007UL))
#define SUB_PMIC_BUCK_EN_STATUS_ADDR(base) ((base) + (0x0008UL))
#define SUB_PMIC_RAMP_STATUS_ADDR(base) ((base) + (0x0009UL))
#define SUB_PMIC_SYS_CTRL_STATUS_ADDR(base) ((base) + (0x000AUL))
#define SUB_PMIC_BUCK0_TOP_CFG0_ADDR(base) ((base) + (0x000BUL))
#define SUB_PMIC_BUCK0_TOP_CFG1_ADDR(base) ((base) + (0x000CUL))
#define SUB_PMIC_BUCK0_TOP_CFG2_ADDR(base) ((base) + (0x000DUL))
#define SUB_PMIC_BUCK0_TOP_CFG3_ADDR(base) ((base) + (0x000EUL))
#define SUB_PMIC_BUCK0_TOP_CFG4_ADDR(base) ((base) + (0x000FUL))
#define SUB_PMIC_BUCK0_TOP_CFG5_ADDR(base) ((base) + (0x0010UL))
#define SUB_PMIC_BUCK0_TOP_CFG6_ADDR(base) ((base) + (0x0011UL))
#define SUB_PMIC_BUCK0_TOP_CFG7_ADDR(base) ((base) + (0x0012UL))
#define SUB_PMIC_BUCK0_TOP_CFG8_ADDR(base) ((base) + (0x0013UL))
#define SUB_PMIC_BUCK0_TOP_CFG9_ADDR(base) ((base) + (0x0014UL))
#define SUB_PMIC_BUCK0_TOP_CFG10_ADDR(base) ((base) + (0x0015UL))
#define SUB_PMIC_BUCK0_TOP_CFG11_ADDR(base) ((base) + (0x0016UL))
#define SUB_PMIC_BUCK0_TOP_CFG12_ADDR(base) ((base) + (0x0017UL))
#define SUB_PMIC_BUCK0_TOP_CFG13_ADDR(base) ((base) + (0x0018UL))
#define SUB_PMIC_BUCK0_TOP_CFG14_ADDR(base) ((base) + (0x0019UL))
#define SUB_PMIC_BUCK0_TOP_CFG15_ADDR(base) ((base) + (0x001AUL))
#define SUB_PMIC_BUCK0_TOP_CFG16_ADDR(base) ((base) + (0x001BUL))
#define SUB_PMIC_BUCK0_TOP_CFG17_ADDR(base) ((base) + (0x001CUL))
#define SUB_PMIC_BUCK0_TOP_CFG18_ADDR(base) ((base) + (0x001DUL))
#define SUB_PMIC_BUCK0_TOP_CFG19_ADDR(base) ((base) + (0x001EUL))
#define SUB_PMIC_BUCK0_TOP_STATE0_0_ADDR(base) ((base) + (0x001FUL))
#define SUB_PMIC_BUCK0_TOP_STATE0_1_ADDR(base) ((base) + (0x0020UL))
#define SUB_PMIC_BUCK0_TOP_STATE1_0_ADDR(base) ((base) + (0x0021UL))
#define SUB_PMIC_BUCK0_TOP_STATE1_1_ADDR(base) ((base) + (0x0022UL))
#define SUB_PMIC_BUCK0_TOP_STATE2_0_ADDR(base) ((base) + (0x0023UL))
#define SUB_PMIC_BUCK0_TOP_STATE2_1_ADDR(base) ((base) + (0x0024UL))
#define SUB_PMIC_BUCK0_TOP_STATE3_0_ADDR(base) ((base) + (0x0025UL))
#define SUB_PMIC_BUCK0_TOP_STATE3_1_ADDR(base) ((base) + (0x0026UL))
#define SUB_PMIC_BUCK1_TOP_CFG0_ADDR(base) ((base) + (0x0027UL))
#define SUB_PMIC_BUCK1_TOP_CFG1_ADDR(base) ((base) + (0x0028UL))
#define SUB_PMIC_BUCK1_TOP_CFG2_ADDR(base) ((base) + (0x0029UL))
#define SUB_PMIC_BUCK1_TOP_CFG3_ADDR(base) ((base) + (0x002AUL))
#define SUB_PMIC_BUCK1_TOP_CFG4_ADDR(base) ((base) + (0x002BUL))
#define SUB_PMIC_BUCK1_TOP_CFG5_ADDR(base) ((base) + (0x002CUL))
#define SUB_PMIC_BUCK1_TOP_CFG6_ADDR(base) ((base) + (0x002DUL))
#define SUB_PMIC_BUCK1_TOP_CFG7_ADDR(base) ((base) + (0x002EUL))
#define SUB_PMIC_BUCK1_TOP_CFG8_ADDR(base) ((base) + (0x002FUL))
#define SUB_PMIC_BUCK1_TOP_CFG9_ADDR(base) ((base) + (0x0030UL))
#define SUB_PMIC_BUCK1_TOP_CFG10_ADDR(base) ((base) + (0x0031UL))
#define SUB_PMIC_BUCK1_TOP_CFG11_ADDR(base) ((base) + (0x0032UL))
#define SUB_PMIC_BUCK1_TOP_CFG12_ADDR(base) ((base) + (0x0033UL))
#define SUB_PMIC_BUCK1_TOP_CFG13_ADDR(base) ((base) + (0x0034UL))
#define SUB_PMIC_BUCK1_TOP_CFG14_ADDR(base) ((base) + (0x0035UL))
#define SUB_PMIC_BUCK1_TOP_CFG15_ADDR(base) ((base) + (0x0036UL))
#define SUB_PMIC_BUCK1_TOP_CFG16_ADDR(base) ((base) + (0x0037UL))
#define SUB_PMIC_BUCK1_TOP_CFG17_ADDR(base) ((base) + (0x0038UL))
#define SUB_PMIC_BUCK1_TOP_CFG18_ADDR(base) ((base) + (0x0039UL))
#define SUB_PMIC_BUCK1_TOP_CFG19_ADDR(base) ((base) + (0x003AUL))
#define SUB_PMIC_BUCK1_TOP_STATE0_0_ADDR(base) ((base) + (0x003BUL))
#define SUB_PMIC_BUCK1_TOP_STATE0_1_ADDR(base) ((base) + (0x003CUL))
#define SUB_PMIC_BUCK1_TOP_STATE1_0_ADDR(base) ((base) + (0x003DUL))
#define SUB_PMIC_BUCK1_TOP_STATE1_1_ADDR(base) ((base) + (0x003EUL))
#define SUB_PMIC_BUCK1_TOP_STATE2_0_ADDR(base) ((base) + (0x003FUL))
#define SUB_PMIC_BUCK1_TOP_STATE2_1_ADDR(base) ((base) + (0x0040UL))
#define SUB_PMIC_BUCK1_TOP_STATE3_0_ADDR(base) ((base) + (0x0041UL))
#define SUB_PMIC_BUCK1_TOP_STATE3_1_ADDR(base) ((base) + (0x0042UL))
#define SUB_PMIC_BUCK2_TOP_CFG0_ADDR(base) ((base) + (0x0043UL))
#define SUB_PMIC_BUCK2_TOP_CFG1_ADDR(base) ((base) + (0x0044UL))
#define SUB_PMIC_BUCK2_TOP_CFG2_ADDR(base) ((base) + (0x0045UL))
#define SUB_PMIC_BUCK2_TOP_CFG3_ADDR(base) ((base) + (0x0046UL))
#define SUB_PMIC_BUCK2_TOP_CFG4_ADDR(base) ((base) + (0x0047UL))
#define SUB_PMIC_BUCK2_TOP_CFG5_ADDR(base) ((base) + (0x0048UL))
#define SUB_PMIC_BUCK2_TOP_CFG6_ADDR(base) ((base) + (0x0049UL))
#define SUB_PMIC_BUCK2_TOP_CFG7_ADDR(base) ((base) + (0x004AUL))
#define SUB_PMIC_BUCK2_TOP_CFG8_ADDR(base) ((base) + (0x004BUL))
#define SUB_PMIC_BUCK2_TOP_CFG9_ADDR(base) ((base) + (0x004CUL))
#define SUB_PMIC_BUCK2_TOP_CFG10_ADDR(base) ((base) + (0x004DUL))
#define SUB_PMIC_BUCK2_TOP_CFG11_ADDR(base) ((base) + (0x004EUL))
#define SUB_PMIC_BUCK2_TOP_CFG12_ADDR(base) ((base) + (0x004FUL))
#define SUB_PMIC_BUCK2_TOP_CFG13_ADDR(base) ((base) + (0x0050UL))
#define SUB_PMIC_BUCK2_TOP_CFG14_ADDR(base) ((base) + (0x0051UL))
#define SUB_PMIC_BUCK2_TOP_CFG15_ADDR(base) ((base) + (0x0052UL))
#define SUB_PMIC_BUCK2_TOP_CFG16_ADDR(base) ((base) + (0x0053UL))
#define SUB_PMIC_BUCK2_TOP_CFG17_ADDR(base) ((base) + (0x0054UL))
#define SUB_PMIC_BUCK2_TOP_CFG18_ADDR(base) ((base) + (0x0055UL))
#define SUB_PMIC_BUCK2_TOP_CFG19_ADDR(base) ((base) + (0x0056UL))
#define SUB_PMIC_BUCK2_TOP_STATE0_0_ADDR(base) ((base) + (0x0057UL))
#define SUB_PMIC_BUCK2_TOP_STATE0_1_ADDR(base) ((base) + (0x0058UL))
#define SUB_PMIC_BUCK2_TOP_STATE1_0_ADDR(base) ((base) + (0x0059UL))
#define SUB_PMIC_BUCK2_TOP_STATE1_1_ADDR(base) ((base) + (0x005AUL))
#define SUB_PMIC_BUCK2_TOP_STATE2_0_ADDR(base) ((base) + (0x005BUL))
#define SUB_PMIC_BUCK2_TOP_STATE2_1_ADDR(base) ((base) + (0x005CUL))
#define SUB_PMIC_BUCK2_TOP_STATE3_0_ADDR(base) ((base) + (0x005DUL))
#define SUB_PMIC_BUCK2_TOP_STATE3_1_ADDR(base) ((base) + (0x005EUL))
#define SUB_PMIC_BUCK3_TOP_CFG0_ADDR(base) ((base) + (0x005FUL))
#define SUB_PMIC_BUCK3_TOP_CFG1_ADDR(base) ((base) + (0x0060UL))
#define SUB_PMIC_BUCK3_TOP_CFG2_ADDR(base) ((base) + (0x0061UL))
#define SUB_PMIC_BUCK3_TOP_CFG3_ADDR(base) ((base) + (0x0062UL))
#define SUB_PMIC_BUCK3_TOP_CFG4_ADDR(base) ((base) + (0x0063UL))
#define SUB_PMIC_BUCK3_TOP_CFG5_ADDR(base) ((base) + (0x0064UL))
#define SUB_PMIC_BUCK3_TOP_CFG6_ADDR(base) ((base) + (0x0065UL))
#define SUB_PMIC_BUCK3_TOP_CFG7_ADDR(base) ((base) + (0x0066UL))
#define SUB_PMIC_BUCK3_TOP_CFG8_ADDR(base) ((base) + (0x0067UL))
#define SUB_PMIC_BUCK3_TOP_CFG9_ADDR(base) ((base) + (0x0068UL))
#define SUB_PMIC_BUCK3_TOP_CFG10_ADDR(base) ((base) + (0x0069UL))
#define SUB_PMIC_BUCK3_TOP_CFG11_ADDR(base) ((base) + (0x006AUL))
#define SUB_PMIC_BUCK3_TOP_CFG12_ADDR(base) ((base) + (0x006BUL))
#define SUB_PMIC_BUCK3_TOP_CFG13_ADDR(base) ((base) + (0x006CUL))
#define SUB_PMIC_BUCK3_TOP_CFG14_ADDR(base) ((base) + (0x006DUL))
#define SUB_PMIC_BUCK3_TOP_CFG15_ADDR(base) ((base) + (0x006EUL))
#define SUB_PMIC_BUCK3_TOP_CFG16_ADDR(base) ((base) + (0x006FUL))
#define SUB_PMIC_BUCK3_TOP_CFG17_ADDR(base) ((base) + (0x0070UL))
#define SUB_PMIC_BUCK3_TOP_CFG18_ADDR(base) ((base) + (0x0071UL))
#define SUB_PMIC_BUCK3_TOP_CFG19_ADDR(base) ((base) + (0x0072UL))
#define SUB_PMIC_BUCK3_TOP_STATE0_0_ADDR(base) ((base) + (0x0073UL))
#define SUB_PMIC_BUCK3_TOP_STATE0_1_ADDR(base) ((base) + (0x0074UL))
#define SUB_PMIC_BUCK3_TOP_STATE1_0_ADDR(base) ((base) + (0x0075UL))
#define SUB_PMIC_BUCK3_TOP_STATE1_1_ADDR(base) ((base) + (0x0076UL))
#define SUB_PMIC_BUCK3_TOP_STATE2_0_ADDR(base) ((base) + (0x0077UL))
#define SUB_PMIC_BUCK3_TOP_STATE2_1_ADDR(base) ((base) + (0x0078UL))
#define SUB_PMIC_BUCK3_TOP_STATE3_0_ADDR(base) ((base) + (0x0079UL))
#define SUB_PMIC_BUCK3_TOP_STATE3_1_ADDR(base) ((base) + (0x007AUL))
#define SUB_PMIC_BUCK01_COMMON_CFG0_ADDR(base) ((base) + (0x007BUL))
#define SUB_PMIC_BUCK01_COMMON_CFG1_ADDR(base) ((base) + (0x007CUL))
#define SUB_PMIC_BUCK01_COMMON_CFG2_ADDR(base) ((base) + (0x007DUL))
#define SUB_PMIC_BUCK01_COMMON_CFG3_ADDR(base) ((base) + (0x007EUL))
#define SUB_PMIC_BUCK01_COMMON_CFG4_ADDR(base) ((base) + (0x007FUL))
#define SUB_PMIC_BUCK01_COMMON_CFG5_ADDR(base) ((base) + (0x0080UL))
#define SUB_PMIC_BUCK01_COMMON_CFG6_ADDR(base) ((base) + (0x0081UL))
#define SUB_PMIC_BUCK01_COMMON_CFG7_ADDR(base) ((base) + (0x0082UL))
#define SUB_PMIC_BUCK01_COMMON_CFG8_ADDR(base) ((base) + (0x0083UL))
#define SUB_PMIC_BUCK2_COMMON_CFG0_ADDR(base) ((base) + (0x0084UL))
#define SUB_PMIC_BUCK2_COMMON_CFG1_ADDR(base) ((base) + (0x0085UL))
#define SUB_PMIC_BUCK2_COMMON_CFG2_ADDR(base) ((base) + (0x0086UL))
#define SUB_PMIC_BUCK2_COMMON_CFG3_ADDR(base) ((base) + (0x0087UL))
#define SUB_PMIC_BUCK3_COMMON_CFG0_ADDR(base) ((base) + (0x0088UL))
#define SUB_PMIC_BUCK3_COMMON_CFG1_ADDR(base) ((base) + (0x0089UL))
#define SUB_PMIC_BUCK3_COMMON_CFG2_ADDR(base) ((base) + (0x008AUL))
#define SUB_PMIC_BUCK3_COMMON_CFG3_ADDR(base) ((base) + (0x008BUL))
#define SUB_PMIC_BUCK3_COMMON_CFG4_ADDR(base) ((base) + (0x008CUL))
#define SUB_PMIC_BUCK3_COMMON_CFG5_ADDR(base) ((base) + (0x008DUL))
#define SUB_PMIC_BUCK3_COMMON_CFG6_ADDR(base) ((base) + (0x008EUL))
#define SUB_PMIC_BUCK3_COMMON_CFG7_ADDR(base) ((base) + (0x008FUL))
#define SUB_PMIC_BUCK3_COMMON_CFG8_ADDR(base) ((base) + (0x0090UL))
#define SUB_PMIC_BUCK01_I_SHARE_CFG0_ADDR(base) ((base) + (0x0091UL))
#define SUB_PMIC_BUCK01_I_SHARE_CFG1_ADDR(base) ((base) + (0x0092UL))
#define SUB_PMIC_BUCK23_I_SHARE_CFG0_ADDR(base) ((base) + (0x0093UL))
#define SUB_PMIC_BUCK23_I_SHARE_CFG1_ADDR(base) ((base) + (0x0094UL))
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG0_ADDR(base) ((base) + (0x0095UL))
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG1_ADDR(base) ((base) + (0x0096UL))
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG0_ADDR(base) ((base) + (0x0097UL))
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG1_ADDR(base) ((base) + (0x0098UL))
#define SUB_PMIC_BUCK01_CLK_CFG0_ADDR(base) ((base) + (0x0099UL))
#define SUB_PMIC_BUCK01_CLK_CFG1_ADDR(base) ((base) + (0x009AUL))
#define SUB_PMIC_BUCK23_CLK_CFG0_ADDR(base) ((base) + (0x009BUL))
#define SUB_PMIC_BUCK23_CLK_CFG1_ADDR(base) ((base) + (0x009CUL))
#define SUB_PMIC_BUCK01_VO_DET_CFG0_ADDR(base) ((base) + (0x009DUL))
#define SUB_PMIC_BUCK01_VO_DET_CFG1_ADDR(base) ((base) + (0x009EUL))
#define SUB_PMIC_BUCK01_VO_DET_CFG2_ADDR(base) ((base) + (0x009FUL))
#define SUB_PMIC_BUCK23_VO_DET_CFG0_ADDR(base) ((base) + (0x00A0UL))
#define SUB_PMIC_BUCK23_VO_DET_CFG1_ADDR(base) ((base) + (0x00A1UL))
#define SUB_PMIC_BUCK23_VO_DET_CFG2_ADDR(base) ((base) + (0x00A2UL))
#define SUB_PMIC_ANA_RESERVE_D2A0_ADDR(base) ((base) + (0x00A3UL))
#define SUB_PMIC_ANA_RESERVE_D2A1_ADDR(base) ((base) + (0x00A4UL))
#define SUB_PMIC_ANA_RESERVE_D2A2_ADDR(base) ((base) + (0x00A5UL))
#define SUB_PMIC_ANA_RESERVE_D2A3_ADDR(base) ((base) + (0x00A6UL))
#define SUB_PMIC_BUCK01_CTRL_ADDR(base) ((base) + (0x00A7UL))
#define SUB_PMIC_BUCK2_CTRL_ADDR(base) ((base) + (0x00A8UL))
#define SUB_PMIC_BUCK3_CTRL_ADDR(base) ((base) + (0x00A9UL))
#define SUB_PMIC_BUCK_STATE_CTRL_ADDR(base) ((base) + (0x00AAUL))
#define SUB_PMIC_BUCK_VO_DET_STATUS_ADDR(base) ((base) + (0x00ABUL))
#define SUB_PMIC_OSC_9M6_CTRL_ADDR(base) ((base) + (0x00ACUL))
#define SUB_PMIC_REF_TEST_ADDR(base) ((base) + (0x00ADUL))
#define SUB_PMIC_REF_CTRL_ADDR(base) ((base) + (0x00AEUL))
#define SUB_PMIC_REF_RESERVE_ADDR(base) ((base) + (0x00AFUL))
#define SUB_PMIC_TH_CTRL_ADDR(base) ((base) + (0x00B0UL))
#define SUB_PMIC_SYS_CTRL_RESERVE_ADDR(base) ((base) + (0x00B1UL))
#define SUB_PMIC_LDO01_RESERVE_ADDR(base) ((base) + (0x00B2UL))
#define SUB_PMIC_ANA_TEST_CTRL_ADDR(base) ((base) + (0x00B3UL))
#define SUB_PMIC_ANA_RSV_A2D0_ADDR(base) ((base) + (0x00B4UL))
#define SUB_PMIC_ANA_RSV_A2D1_ADDR(base) ((base) + (0x00B5UL))
#define SUB_PMIC_OTP_0_ADDR(base) ((base) + (0x00C0UL))
#define SUB_PMIC_OTP_1_ADDR(base) ((base) + (0x00C1UL))
#define SUB_PMIC_OTP_CLK_CTRL_ADDR(base) ((base) + (0x00C2UL))
#define SUB_PMIC_OTP_CTRL0_ADDR(base) ((base) + (0x00C3UL))
#define SUB_PMIC_OTP_CTRL1_ADDR(base) ((base) + (0x00C4UL))
#define SUB_PMIC_OTP_CTRL2_ADDR(base) ((base) + (0x00C5UL))
#define SUB_PMIC_OTP_WDATA_ADDR(base) ((base) + (0x00C6UL))
#define SUB_PMIC_OTP_0_W_ADDR(base) ((base) + (0x00C7UL))
#define SUB_PMIC_OTP_1_W_ADDR(base) ((base) + (0x00C8UL))
#define SUB_PMIC_OTP_2_W_ADDR(base) ((base) + (0x00C9UL))
#define SUB_PMIC_OTP_3_W_ADDR(base) ((base) + (0x00CAUL))
#define SUB_PMIC_OTP_4_W_ADDR(base) ((base) + (0x00CBUL))
#define SUB_PMIC_OTP_5_W_ADDR(base) ((base) + (0x00CCUL))
#define SUB_PMIC_OTP_6_W_ADDR(base) ((base) + (0x00CDUL))
#define SUB_PMIC_OTP_7_W_ADDR(base) ((base) + (0x00CEUL))
#define SUB_PMIC_OTP_8_W_ADDR(base) ((base) + (0x00CFUL))
#define SUB_PMIC_OTP_9_W_ADDR(base) ((base) + (0x00D0UL))
#define SUB_PMIC_OTP_10_W_ADDR(base) ((base) + (0x00D1UL))
#define SUB_PMIC_OTP_11_W_ADDR(base) ((base) + (0x00D2UL))
#define SUB_PMIC_OTP_12_W_ADDR(base) ((base) + (0x00D3UL))
#define SUB_PMIC_OTP_13_W_ADDR(base) ((base) + (0x00D4UL))
#define SUB_PMIC_OTP_14_W_ADDR(base) ((base) + (0x00D5UL))
#define SUB_PMIC_OTP_15_W_ADDR(base) ((base) + (0x00D6UL))
#define SUB_PMIC_OTP_16_W_ADDR(base) ((base) + (0x00D7UL))
#define SUB_PMIC_OTP_17_W_ADDR(base) ((base) + (0x00D8UL))
#define SUB_PMIC_OTP_18_W_ADDR(base) ((base) + (0x00D9UL))
#define SUB_PMIC_OTP_19_W_ADDR(base) ((base) + (0x00DAUL))
#define SUB_PMIC_OTP_20_W_ADDR(base) ((base) + (0x00DBUL))
#define SUB_PMIC_OTP_21_W_ADDR(base) ((base) + (0x00DCUL))
#define SUB_PMIC_OTP_22_W_ADDR(base) ((base) + (0x00DDUL))
#define SUB_PMIC_OTP_23_W_ADDR(base) ((base) + (0x00DEUL))
#define SUB_PMIC_OTP_24_W_ADDR(base) ((base) + (0x00DFUL))
#define SUB_PMIC_OTP_25_W_ADDR(base) ((base) + (0x00E0UL))
#define SUB_PMIC_OTP_26_W_ADDR(base) ((base) + (0x00E1UL))
#define SUB_PMIC_OTP_27_W_ADDR(base) ((base) + (0x00E2UL))
#define SUB_PMIC_OTP_28_W_ADDR(base) ((base) + (0x00E3UL))
#define SUB_PMIC_OTP_29_W_ADDR(base) ((base) + (0x00E4UL))
#define SUB_PMIC_OTP_30_W_ADDR(base) ((base) + (0x00E5UL))
#define SUB_PMIC_OTP_31_W_ADDR(base) ((base) + (0x00E6UL))
#define SUB_PMIC_ENABLE0_BUCK_ADDR(base) ((base) + (0x00E7UL))
#define SUB_PMIC_ENABLE2_BUCK_ADDR(base) ((base) + (0x00E8UL))
#define SUB_PMIC_ENABLE3_BUCK_ADDR(base) ((base) + (0x00E9UL))
#define SUB_PMIC_BUCK01_RAMP_CTRL_ADDR(base) ((base) + (0x00EAUL))
#define SUB_PMIC_BUCK01_VSET_CTRL_ADDR(base) ((base) + (0x00EBUL))
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00ECUL))
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00EDUL))
#define SUB_PMIC_BUCK01_RAMPUP_STATE_ADDR(base) ((base) + (0x00EEUL))
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00EFUL))
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00F0UL))
#define SUB_PMIC_BUCK2_RAMP_CTRL_ADDR(base) ((base) + (0x00F1UL))
#define SUB_PMIC_BUCK2_VSET_CTRL_ADDR(base) ((base) + (0x00F2UL))
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00F3UL))
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00F4UL))
#define SUB_PMIC_BUCK2_RAMPUP_STATE_ADDR(base) ((base) + (0x00F5UL))
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00F6UL))
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00F7UL))
#define SUB_PMIC_BUCK3_RAMP_CTRL_ADDR(base) ((base) + (0x00F8UL))
#define SUB_PMIC_BUCK3_VSET_CTRL_ADDR(base) ((base) + (0x00F9UL))
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00FAUL))
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00FBUL))
#define SUB_PMIC_BUCK3_RAMPUP_STATE_ADDR(base) ((base) + (0x00FCUL))
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00FDUL))
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00FEUL))
#define SUB_PMIC_BUCK01_VSET_STATUS_ADDR(base) ((base) + (0x00FFUL))
#define SUB_PMIC_BUCK2_VSET_STATUS_ADDR(base) ((base) + (0x0100UL))
#define SUB_PMIC_BUCK3_VSET_STATUS_ADDR(base) ((base) + (0x0101UL))
#define SUB_PMIC_BUCK0123_CTRL0_ADDR(base) ((base) + (0x0102UL))
#define SUB_PMIC_OCP_DEB_CTRL0_ADDR(base) ((base) + (0x0103UL))
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_ADDR(base) ((base) + (0x0104UL))
#define SUB_PMIC_BUCK_STATE_MASK_ADDR(base) ((base) + (0x0105UL))
#define SUB_PMIC_SYS_CTRL_ADDR(base) ((base) + (0x0106UL))
#define SUB_PMIC_DIG_DEBUG_0_ADDR(base) ((base) + (0x0107UL))
#define SUB_PMIC_DIG_DEBUG_1_ADDR(base) ((base) + (0x0108UL))
#define SUB_PMIC_DIG_IO_DS_CFG_ADDR(base) ((base) + (0x0109UL))
#define SUB_PMIC_SPMI_DEBUG_0_ADDR(base) ((base) + (0x0110UL))
#define SUB_PMIC_SPMI_DEBUG_1_ADDR(base) ((base) + (0x0111UL))
#define SUB_PMIC_SPMI_DEBUG_2_ADDR(base) ((base) + (0x0112UL))
#define SUB_PMIC_SPMI_DEBUG_3_ADDR(base) ((base) + (0x0113UL))
#define SUB_PMIC_SPMI_DEBUG_4_ADDR(base) ((base) + (0x0114UL))
#define SUB_PMIC_SPMI_DEBUG_5_ADDR(base) ((base) + (0x0115UL))
#define SUB_PMIC_SPMI_DEBUG_6_ADDR(base) ((base) + (0x0116UL))
#define SUB_PMIC_SPMI_DEBUG_7_ADDR(base) ((base) + (0x0117UL))
#else
#define SUB_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x0000))
#define SUB_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x0001))
#define SUB_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x0002))
#define SUB_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x0003))
#define SUB_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x0004))
#define SUB_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x0005))
#define SUB_PMIC_STATUS0_ADDR(base) ((base) + (0x0006))
#define SUB_PMIC_OCP_SCP_STATUS_ADDR(base) ((base) + (0x0007))
#define SUB_PMIC_BUCK_EN_STATUS_ADDR(base) ((base) + (0x0008))
#define SUB_PMIC_RAMP_STATUS_ADDR(base) ((base) + (0x0009))
#define SUB_PMIC_SYS_CTRL_STATUS_ADDR(base) ((base) + (0x000A))
#define SUB_PMIC_BUCK0_TOP_CFG0_ADDR(base) ((base) + (0x000B))
#define SUB_PMIC_BUCK0_TOP_CFG1_ADDR(base) ((base) + (0x000C))
#define SUB_PMIC_BUCK0_TOP_CFG2_ADDR(base) ((base) + (0x000D))
#define SUB_PMIC_BUCK0_TOP_CFG3_ADDR(base) ((base) + (0x000E))
#define SUB_PMIC_BUCK0_TOP_CFG4_ADDR(base) ((base) + (0x000F))
#define SUB_PMIC_BUCK0_TOP_CFG5_ADDR(base) ((base) + (0x0010))
#define SUB_PMIC_BUCK0_TOP_CFG6_ADDR(base) ((base) + (0x0011))
#define SUB_PMIC_BUCK0_TOP_CFG7_ADDR(base) ((base) + (0x0012))
#define SUB_PMIC_BUCK0_TOP_CFG8_ADDR(base) ((base) + (0x0013))
#define SUB_PMIC_BUCK0_TOP_CFG9_ADDR(base) ((base) + (0x0014))
#define SUB_PMIC_BUCK0_TOP_CFG10_ADDR(base) ((base) + (0x0015))
#define SUB_PMIC_BUCK0_TOP_CFG11_ADDR(base) ((base) + (0x0016))
#define SUB_PMIC_BUCK0_TOP_CFG12_ADDR(base) ((base) + (0x0017))
#define SUB_PMIC_BUCK0_TOP_CFG13_ADDR(base) ((base) + (0x0018))
#define SUB_PMIC_BUCK0_TOP_CFG14_ADDR(base) ((base) + (0x0019))
#define SUB_PMIC_BUCK0_TOP_CFG15_ADDR(base) ((base) + (0x001A))
#define SUB_PMIC_BUCK0_TOP_CFG16_ADDR(base) ((base) + (0x001B))
#define SUB_PMIC_BUCK0_TOP_CFG17_ADDR(base) ((base) + (0x001C))
#define SUB_PMIC_BUCK0_TOP_CFG18_ADDR(base) ((base) + (0x001D))
#define SUB_PMIC_BUCK0_TOP_CFG19_ADDR(base) ((base) + (0x001E))
#define SUB_PMIC_BUCK0_TOP_STATE0_0_ADDR(base) ((base) + (0x001F))
#define SUB_PMIC_BUCK0_TOP_STATE0_1_ADDR(base) ((base) + (0x0020))
#define SUB_PMIC_BUCK0_TOP_STATE1_0_ADDR(base) ((base) + (0x0021))
#define SUB_PMIC_BUCK0_TOP_STATE1_1_ADDR(base) ((base) + (0x0022))
#define SUB_PMIC_BUCK0_TOP_STATE2_0_ADDR(base) ((base) + (0x0023))
#define SUB_PMIC_BUCK0_TOP_STATE2_1_ADDR(base) ((base) + (0x0024))
#define SUB_PMIC_BUCK0_TOP_STATE3_0_ADDR(base) ((base) + (0x0025))
#define SUB_PMIC_BUCK0_TOP_STATE3_1_ADDR(base) ((base) + (0x0026))
#define SUB_PMIC_BUCK1_TOP_CFG0_ADDR(base) ((base) + (0x0027))
#define SUB_PMIC_BUCK1_TOP_CFG1_ADDR(base) ((base) + (0x0028))
#define SUB_PMIC_BUCK1_TOP_CFG2_ADDR(base) ((base) + (0x0029))
#define SUB_PMIC_BUCK1_TOP_CFG3_ADDR(base) ((base) + (0x002A))
#define SUB_PMIC_BUCK1_TOP_CFG4_ADDR(base) ((base) + (0x002B))
#define SUB_PMIC_BUCK1_TOP_CFG5_ADDR(base) ((base) + (0x002C))
#define SUB_PMIC_BUCK1_TOP_CFG6_ADDR(base) ((base) + (0x002D))
#define SUB_PMIC_BUCK1_TOP_CFG7_ADDR(base) ((base) + (0x002E))
#define SUB_PMIC_BUCK1_TOP_CFG8_ADDR(base) ((base) + (0x002F))
#define SUB_PMIC_BUCK1_TOP_CFG9_ADDR(base) ((base) + (0x0030))
#define SUB_PMIC_BUCK1_TOP_CFG10_ADDR(base) ((base) + (0x0031))
#define SUB_PMIC_BUCK1_TOP_CFG11_ADDR(base) ((base) + (0x0032))
#define SUB_PMIC_BUCK1_TOP_CFG12_ADDR(base) ((base) + (0x0033))
#define SUB_PMIC_BUCK1_TOP_CFG13_ADDR(base) ((base) + (0x0034))
#define SUB_PMIC_BUCK1_TOP_CFG14_ADDR(base) ((base) + (0x0035))
#define SUB_PMIC_BUCK1_TOP_CFG15_ADDR(base) ((base) + (0x0036))
#define SUB_PMIC_BUCK1_TOP_CFG16_ADDR(base) ((base) + (0x0037))
#define SUB_PMIC_BUCK1_TOP_CFG17_ADDR(base) ((base) + (0x0038))
#define SUB_PMIC_BUCK1_TOP_CFG18_ADDR(base) ((base) + (0x0039))
#define SUB_PMIC_BUCK1_TOP_CFG19_ADDR(base) ((base) + (0x003A))
#define SUB_PMIC_BUCK1_TOP_STATE0_0_ADDR(base) ((base) + (0x003B))
#define SUB_PMIC_BUCK1_TOP_STATE0_1_ADDR(base) ((base) + (0x003C))
#define SUB_PMIC_BUCK1_TOP_STATE1_0_ADDR(base) ((base) + (0x003D))
#define SUB_PMIC_BUCK1_TOP_STATE1_1_ADDR(base) ((base) + (0x003E))
#define SUB_PMIC_BUCK1_TOP_STATE2_0_ADDR(base) ((base) + (0x003F))
#define SUB_PMIC_BUCK1_TOP_STATE2_1_ADDR(base) ((base) + (0x0040))
#define SUB_PMIC_BUCK1_TOP_STATE3_0_ADDR(base) ((base) + (0x0041))
#define SUB_PMIC_BUCK1_TOP_STATE3_1_ADDR(base) ((base) + (0x0042))
#define SUB_PMIC_BUCK2_TOP_CFG0_ADDR(base) ((base) + (0x0043))
#define SUB_PMIC_BUCK2_TOP_CFG1_ADDR(base) ((base) + (0x0044))
#define SUB_PMIC_BUCK2_TOP_CFG2_ADDR(base) ((base) + (0x0045))
#define SUB_PMIC_BUCK2_TOP_CFG3_ADDR(base) ((base) + (0x0046))
#define SUB_PMIC_BUCK2_TOP_CFG4_ADDR(base) ((base) + (0x0047))
#define SUB_PMIC_BUCK2_TOP_CFG5_ADDR(base) ((base) + (0x0048))
#define SUB_PMIC_BUCK2_TOP_CFG6_ADDR(base) ((base) + (0x0049))
#define SUB_PMIC_BUCK2_TOP_CFG7_ADDR(base) ((base) + (0x004A))
#define SUB_PMIC_BUCK2_TOP_CFG8_ADDR(base) ((base) + (0x004B))
#define SUB_PMIC_BUCK2_TOP_CFG9_ADDR(base) ((base) + (0x004C))
#define SUB_PMIC_BUCK2_TOP_CFG10_ADDR(base) ((base) + (0x004D))
#define SUB_PMIC_BUCK2_TOP_CFG11_ADDR(base) ((base) + (0x004E))
#define SUB_PMIC_BUCK2_TOP_CFG12_ADDR(base) ((base) + (0x004F))
#define SUB_PMIC_BUCK2_TOP_CFG13_ADDR(base) ((base) + (0x0050))
#define SUB_PMIC_BUCK2_TOP_CFG14_ADDR(base) ((base) + (0x0051))
#define SUB_PMIC_BUCK2_TOP_CFG15_ADDR(base) ((base) + (0x0052))
#define SUB_PMIC_BUCK2_TOP_CFG16_ADDR(base) ((base) + (0x0053))
#define SUB_PMIC_BUCK2_TOP_CFG17_ADDR(base) ((base) + (0x0054))
#define SUB_PMIC_BUCK2_TOP_CFG18_ADDR(base) ((base) + (0x0055))
#define SUB_PMIC_BUCK2_TOP_CFG19_ADDR(base) ((base) + (0x0056))
#define SUB_PMIC_BUCK2_TOP_STATE0_0_ADDR(base) ((base) + (0x0057))
#define SUB_PMIC_BUCK2_TOP_STATE0_1_ADDR(base) ((base) + (0x0058))
#define SUB_PMIC_BUCK2_TOP_STATE1_0_ADDR(base) ((base) + (0x0059))
#define SUB_PMIC_BUCK2_TOP_STATE1_1_ADDR(base) ((base) + (0x005A))
#define SUB_PMIC_BUCK2_TOP_STATE2_0_ADDR(base) ((base) + (0x005B))
#define SUB_PMIC_BUCK2_TOP_STATE2_1_ADDR(base) ((base) + (0x005C))
#define SUB_PMIC_BUCK2_TOP_STATE3_0_ADDR(base) ((base) + (0x005D))
#define SUB_PMIC_BUCK2_TOP_STATE3_1_ADDR(base) ((base) + (0x005E))
#define SUB_PMIC_BUCK3_TOP_CFG0_ADDR(base) ((base) + (0x005F))
#define SUB_PMIC_BUCK3_TOP_CFG1_ADDR(base) ((base) + (0x0060))
#define SUB_PMIC_BUCK3_TOP_CFG2_ADDR(base) ((base) + (0x0061))
#define SUB_PMIC_BUCK3_TOP_CFG3_ADDR(base) ((base) + (0x0062))
#define SUB_PMIC_BUCK3_TOP_CFG4_ADDR(base) ((base) + (0x0063))
#define SUB_PMIC_BUCK3_TOP_CFG5_ADDR(base) ((base) + (0x0064))
#define SUB_PMIC_BUCK3_TOP_CFG6_ADDR(base) ((base) + (0x0065))
#define SUB_PMIC_BUCK3_TOP_CFG7_ADDR(base) ((base) + (0x0066))
#define SUB_PMIC_BUCK3_TOP_CFG8_ADDR(base) ((base) + (0x0067))
#define SUB_PMIC_BUCK3_TOP_CFG9_ADDR(base) ((base) + (0x0068))
#define SUB_PMIC_BUCK3_TOP_CFG10_ADDR(base) ((base) + (0x0069))
#define SUB_PMIC_BUCK3_TOP_CFG11_ADDR(base) ((base) + (0x006A))
#define SUB_PMIC_BUCK3_TOP_CFG12_ADDR(base) ((base) + (0x006B))
#define SUB_PMIC_BUCK3_TOP_CFG13_ADDR(base) ((base) + (0x006C))
#define SUB_PMIC_BUCK3_TOP_CFG14_ADDR(base) ((base) + (0x006D))
#define SUB_PMIC_BUCK3_TOP_CFG15_ADDR(base) ((base) + (0x006E))
#define SUB_PMIC_BUCK3_TOP_CFG16_ADDR(base) ((base) + (0x006F))
#define SUB_PMIC_BUCK3_TOP_CFG17_ADDR(base) ((base) + (0x0070))
#define SUB_PMIC_BUCK3_TOP_CFG18_ADDR(base) ((base) + (0x0071))
#define SUB_PMIC_BUCK3_TOP_CFG19_ADDR(base) ((base) + (0x0072))
#define SUB_PMIC_BUCK3_TOP_STATE0_0_ADDR(base) ((base) + (0x0073))
#define SUB_PMIC_BUCK3_TOP_STATE0_1_ADDR(base) ((base) + (0x0074))
#define SUB_PMIC_BUCK3_TOP_STATE1_0_ADDR(base) ((base) + (0x0075))
#define SUB_PMIC_BUCK3_TOP_STATE1_1_ADDR(base) ((base) + (0x0076))
#define SUB_PMIC_BUCK3_TOP_STATE2_0_ADDR(base) ((base) + (0x0077))
#define SUB_PMIC_BUCK3_TOP_STATE2_1_ADDR(base) ((base) + (0x0078))
#define SUB_PMIC_BUCK3_TOP_STATE3_0_ADDR(base) ((base) + (0x0079))
#define SUB_PMIC_BUCK3_TOP_STATE3_1_ADDR(base) ((base) + (0x007A))
#define SUB_PMIC_BUCK01_COMMON_CFG0_ADDR(base) ((base) + (0x007B))
#define SUB_PMIC_BUCK01_COMMON_CFG1_ADDR(base) ((base) + (0x007C))
#define SUB_PMIC_BUCK01_COMMON_CFG2_ADDR(base) ((base) + (0x007D))
#define SUB_PMIC_BUCK01_COMMON_CFG3_ADDR(base) ((base) + (0x007E))
#define SUB_PMIC_BUCK01_COMMON_CFG4_ADDR(base) ((base) + (0x007F))
#define SUB_PMIC_BUCK01_COMMON_CFG5_ADDR(base) ((base) + (0x0080))
#define SUB_PMIC_BUCK01_COMMON_CFG6_ADDR(base) ((base) + (0x0081))
#define SUB_PMIC_BUCK01_COMMON_CFG7_ADDR(base) ((base) + (0x0082))
#define SUB_PMIC_BUCK01_COMMON_CFG8_ADDR(base) ((base) + (0x0083))
#define SUB_PMIC_BUCK2_COMMON_CFG0_ADDR(base) ((base) + (0x0084))
#define SUB_PMIC_BUCK2_COMMON_CFG1_ADDR(base) ((base) + (0x0085))
#define SUB_PMIC_BUCK2_COMMON_CFG2_ADDR(base) ((base) + (0x0086))
#define SUB_PMIC_BUCK2_COMMON_CFG3_ADDR(base) ((base) + (0x0087))
#define SUB_PMIC_BUCK3_COMMON_CFG0_ADDR(base) ((base) + (0x0088))
#define SUB_PMIC_BUCK3_COMMON_CFG1_ADDR(base) ((base) + (0x0089))
#define SUB_PMIC_BUCK3_COMMON_CFG2_ADDR(base) ((base) + (0x008A))
#define SUB_PMIC_BUCK3_COMMON_CFG3_ADDR(base) ((base) + (0x008B))
#define SUB_PMIC_BUCK3_COMMON_CFG4_ADDR(base) ((base) + (0x008C))
#define SUB_PMIC_BUCK3_COMMON_CFG5_ADDR(base) ((base) + (0x008D))
#define SUB_PMIC_BUCK3_COMMON_CFG6_ADDR(base) ((base) + (0x008E))
#define SUB_PMIC_BUCK3_COMMON_CFG7_ADDR(base) ((base) + (0x008F))
#define SUB_PMIC_BUCK3_COMMON_CFG8_ADDR(base) ((base) + (0x0090))
#define SUB_PMIC_BUCK01_I_SHARE_CFG0_ADDR(base) ((base) + (0x0091))
#define SUB_PMIC_BUCK01_I_SHARE_CFG1_ADDR(base) ((base) + (0x0092))
#define SUB_PMIC_BUCK23_I_SHARE_CFG0_ADDR(base) ((base) + (0x0093))
#define SUB_PMIC_BUCK23_I_SHARE_CFG1_ADDR(base) ((base) + (0x0094))
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG0_ADDR(base) ((base) + (0x0095))
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG1_ADDR(base) ((base) + (0x0096))
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG0_ADDR(base) ((base) + (0x0097))
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG1_ADDR(base) ((base) + (0x0098))
#define SUB_PMIC_BUCK01_CLK_CFG0_ADDR(base) ((base) + (0x0099))
#define SUB_PMIC_BUCK01_CLK_CFG1_ADDR(base) ((base) + (0x009A))
#define SUB_PMIC_BUCK23_CLK_CFG0_ADDR(base) ((base) + (0x009B))
#define SUB_PMIC_BUCK23_CLK_CFG1_ADDR(base) ((base) + (0x009C))
#define SUB_PMIC_BUCK01_VO_DET_CFG0_ADDR(base) ((base) + (0x009D))
#define SUB_PMIC_BUCK01_VO_DET_CFG1_ADDR(base) ((base) + (0x009E))
#define SUB_PMIC_BUCK01_VO_DET_CFG2_ADDR(base) ((base) + (0x009F))
#define SUB_PMIC_BUCK23_VO_DET_CFG0_ADDR(base) ((base) + (0x00A0))
#define SUB_PMIC_BUCK23_VO_DET_CFG1_ADDR(base) ((base) + (0x00A1))
#define SUB_PMIC_BUCK23_VO_DET_CFG2_ADDR(base) ((base) + (0x00A2))
#define SUB_PMIC_ANA_RESERVE_D2A0_ADDR(base) ((base) + (0x00A3))
#define SUB_PMIC_ANA_RESERVE_D2A1_ADDR(base) ((base) + (0x00A4))
#define SUB_PMIC_ANA_RESERVE_D2A2_ADDR(base) ((base) + (0x00A5))
#define SUB_PMIC_ANA_RESERVE_D2A3_ADDR(base) ((base) + (0x00A6))
#define SUB_PMIC_BUCK01_CTRL_ADDR(base) ((base) + (0x00A7))
#define SUB_PMIC_BUCK2_CTRL_ADDR(base) ((base) + (0x00A8))
#define SUB_PMIC_BUCK3_CTRL_ADDR(base) ((base) + (0x00A9))
#define SUB_PMIC_BUCK_STATE_CTRL_ADDR(base) ((base) + (0x00AA))
#define SUB_PMIC_BUCK_VO_DET_STATUS_ADDR(base) ((base) + (0x00AB))
#define SUB_PMIC_OSC_9M6_CTRL_ADDR(base) ((base) + (0x00AC))
#define SUB_PMIC_REF_TEST_ADDR(base) ((base) + (0x00AD))
#define SUB_PMIC_REF_CTRL_ADDR(base) ((base) + (0x00AE))
#define SUB_PMIC_REF_RESERVE_ADDR(base) ((base) + (0x00AF))
#define SUB_PMIC_TH_CTRL_ADDR(base) ((base) + (0x00B0))
#define SUB_PMIC_SYS_CTRL_RESERVE_ADDR(base) ((base) + (0x00B1))
#define SUB_PMIC_LDO01_RESERVE_ADDR(base) ((base) + (0x00B2))
#define SUB_PMIC_ANA_TEST_CTRL_ADDR(base) ((base) + (0x00B3))
#define SUB_PMIC_ANA_RSV_A2D0_ADDR(base) ((base) + (0x00B4))
#define SUB_PMIC_ANA_RSV_A2D1_ADDR(base) ((base) + (0x00B5))
#define SUB_PMIC_OTP_0_ADDR(base) ((base) + (0x00C0))
#define SUB_PMIC_OTP_1_ADDR(base) ((base) + (0x00C1))
#define SUB_PMIC_OTP_CLK_CTRL_ADDR(base) ((base) + (0x00C2))
#define SUB_PMIC_OTP_CTRL0_ADDR(base) ((base) + (0x00C3))
#define SUB_PMIC_OTP_CTRL1_ADDR(base) ((base) + (0x00C4))
#define SUB_PMIC_OTP_CTRL2_ADDR(base) ((base) + (0x00C5))
#define SUB_PMIC_OTP_WDATA_ADDR(base) ((base) + (0x00C6))
#define SUB_PMIC_OTP_0_W_ADDR(base) ((base) + (0x00C7))
#define SUB_PMIC_OTP_1_W_ADDR(base) ((base) + (0x00C8))
#define SUB_PMIC_OTP_2_W_ADDR(base) ((base) + (0x00C9))
#define SUB_PMIC_OTP_3_W_ADDR(base) ((base) + (0x00CA))
#define SUB_PMIC_OTP_4_W_ADDR(base) ((base) + (0x00CB))
#define SUB_PMIC_OTP_5_W_ADDR(base) ((base) + (0x00CC))
#define SUB_PMIC_OTP_6_W_ADDR(base) ((base) + (0x00CD))
#define SUB_PMIC_OTP_7_W_ADDR(base) ((base) + (0x00CE))
#define SUB_PMIC_OTP_8_W_ADDR(base) ((base) + (0x00CF))
#define SUB_PMIC_OTP_9_W_ADDR(base) ((base) + (0x00D0))
#define SUB_PMIC_OTP_10_W_ADDR(base) ((base) + (0x00D1))
#define SUB_PMIC_OTP_11_W_ADDR(base) ((base) + (0x00D2))
#define SUB_PMIC_OTP_12_W_ADDR(base) ((base) + (0x00D3))
#define SUB_PMIC_OTP_13_W_ADDR(base) ((base) + (0x00D4))
#define SUB_PMIC_OTP_14_W_ADDR(base) ((base) + (0x00D5))
#define SUB_PMIC_OTP_15_W_ADDR(base) ((base) + (0x00D6))
#define SUB_PMIC_OTP_16_W_ADDR(base) ((base) + (0x00D7))
#define SUB_PMIC_OTP_17_W_ADDR(base) ((base) + (0x00D8))
#define SUB_PMIC_OTP_18_W_ADDR(base) ((base) + (0x00D9))
#define SUB_PMIC_OTP_19_W_ADDR(base) ((base) + (0x00DA))
#define SUB_PMIC_OTP_20_W_ADDR(base) ((base) + (0x00DB))
#define SUB_PMIC_OTP_21_W_ADDR(base) ((base) + (0x00DC))
#define SUB_PMIC_OTP_22_W_ADDR(base) ((base) + (0x00DD))
#define SUB_PMIC_OTP_23_W_ADDR(base) ((base) + (0x00DE))
#define SUB_PMIC_OTP_24_W_ADDR(base) ((base) + (0x00DF))
#define SUB_PMIC_OTP_25_W_ADDR(base) ((base) + (0x00E0))
#define SUB_PMIC_OTP_26_W_ADDR(base) ((base) + (0x00E1))
#define SUB_PMIC_OTP_27_W_ADDR(base) ((base) + (0x00E2))
#define SUB_PMIC_OTP_28_W_ADDR(base) ((base) + (0x00E3))
#define SUB_PMIC_OTP_29_W_ADDR(base) ((base) + (0x00E4))
#define SUB_PMIC_OTP_30_W_ADDR(base) ((base) + (0x00E5))
#define SUB_PMIC_OTP_31_W_ADDR(base) ((base) + (0x00E6))
#define SUB_PMIC_ENABLE0_BUCK_ADDR(base) ((base) + (0x00E7))
#define SUB_PMIC_ENABLE2_BUCK_ADDR(base) ((base) + (0x00E8))
#define SUB_PMIC_ENABLE3_BUCK_ADDR(base) ((base) + (0x00E9))
#define SUB_PMIC_BUCK01_RAMP_CTRL_ADDR(base) ((base) + (0x00EA))
#define SUB_PMIC_BUCK01_VSET_CTRL_ADDR(base) ((base) + (0x00EB))
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00EC))
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00ED))
#define SUB_PMIC_BUCK01_RAMPUP_STATE_ADDR(base) ((base) + (0x00EE))
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00EF))
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00F0))
#define SUB_PMIC_BUCK2_RAMP_CTRL_ADDR(base) ((base) + (0x00F1))
#define SUB_PMIC_BUCK2_VSET_CTRL_ADDR(base) ((base) + (0x00F2))
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00F3))
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00F4))
#define SUB_PMIC_BUCK2_RAMPUP_STATE_ADDR(base) ((base) + (0x00F5))
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00F6))
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00F7))
#define SUB_PMIC_BUCK3_RAMP_CTRL_ADDR(base) ((base) + (0x00F8))
#define SUB_PMIC_BUCK3_VSET_CTRL_ADDR(base) ((base) + (0x00F9))
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_ADDR(base) ((base) + (0x00FA))
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_ADDR(base) ((base) + (0x00FB))
#define SUB_PMIC_BUCK3_RAMPUP_STATE_ADDR(base) ((base) + (0x00FC))
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_ADDR(base) ((base) + (0x00FD))
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_ADDR(base) ((base) + (0x00FE))
#define SUB_PMIC_BUCK01_VSET_STATUS_ADDR(base) ((base) + (0x00FF))
#define SUB_PMIC_BUCK2_VSET_STATUS_ADDR(base) ((base) + (0x0100))
#define SUB_PMIC_BUCK3_VSET_STATUS_ADDR(base) ((base) + (0x0101))
#define SUB_PMIC_BUCK0123_CTRL0_ADDR(base) ((base) + (0x0102))
#define SUB_PMIC_OCP_DEB_CTRL0_ADDR(base) ((base) + (0x0103))
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_ADDR(base) ((base) + (0x0104))
#define SUB_PMIC_BUCK_STATE_MASK_ADDR(base) ((base) + (0x0105))
#define SUB_PMIC_SYS_CTRL_ADDR(base) ((base) + (0x0106))
#define SUB_PMIC_DIG_DEBUG_0_ADDR(base) ((base) + (0x0107))
#define SUB_PMIC_DIG_DEBUG_1_ADDR(base) ((base) + (0x0108))
#define SUB_PMIC_DIG_IO_DS_CFG_ADDR(base) ((base) + (0x0109))
#define SUB_PMIC_SPMI_DEBUG_0_ADDR(base) ((base) + (0x0110))
#define SUB_PMIC_SPMI_DEBUG_1_ADDR(base) ((base) + (0x0111))
#define SUB_PMIC_SPMI_DEBUG_2_ADDR(base) ((base) + (0x0112))
#define SUB_PMIC_SPMI_DEBUG_3_ADDR(base) ((base) + (0x0113))
#define SUB_PMIC_SPMI_DEBUG_4_ADDR(base) ((base) + (0x0114))
#define SUB_PMIC_SPMI_DEBUG_5_ADDR(base) ((base) + (0x0115))
#define SUB_PMIC_SPMI_DEBUG_6_ADDR(base) ((base) + (0x0116))
#define SUB_PMIC_SPMI_DEBUG_7_ADDR(base) ((base) + (0x0117))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_IRQ1_MASK_ADDR(base) ((base) + (0x0200UL))
#define SUB_PMIC_OCP_IRQ_MASK_ADDR(base) ((base) + (0x0201UL))
#define SUB_PMIC_SCP_IRQ_MASK_ADDR(base) ((base) + (0x0202UL))
#define SUB_PMIC_OVP_IRQ_MASK_ADDR(base) ((base) + (0x0203UL))
#define SUB_PMIC_RAMP_IRQ_MASK_ADDR(base) ((base) + (0x0204UL))
#else
#define SUB_PMIC_IRQ1_MASK_ADDR(base) ((base) + (0x0200))
#define SUB_PMIC_OCP_IRQ_MASK_ADDR(base) ((base) + (0x0201))
#define SUB_PMIC_SCP_IRQ_MASK_ADDR(base) ((base) + (0x0202))
#define SUB_PMIC_OVP_IRQ_MASK_ADDR(base) ((base) + (0x0203))
#define SUB_PMIC_RAMP_IRQ_MASK_ADDR(base) ((base) + (0x0204))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_IRQ1_ADDR(base) ((base) + (0x0205UL))
#define SUB_PMIC_OCP_IRQ_ADDR(base) ((base) + (0x0206UL))
#define SUB_PMIC_SCP_IRQ_ADDR(base) ((base) + (0x0207UL))
#define SUB_PMIC_OVP_IRQ_ADDR(base) ((base) + (0x0208UL))
#define SUB_PMIC_RAMP_IRQ_ADDR(base) ((base) + (0x0209UL))
#else
#define SUB_PMIC_IRQ1_ADDR(base) ((base) + (0x0205))
#define SUB_PMIC_OCP_IRQ_ADDR(base) ((base) + (0x0206))
#define SUB_PMIC_SCP_IRQ_ADDR(base) ((base) + (0x0207))
#define SUB_PMIC_OVP_IRQ_ADDR(base) ((base) + (0x0208))
#define SUB_PMIC_RAMP_IRQ_ADDR(base) ((base) + (0x0209))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_NP_IRQ1_RECORD_ADDR(base) ((base) + (0x020AUL))
#define SUB_PMIC_NP_OCP_RECORD_ADDR(base) ((base) + (0x020BUL))
#define SUB_PMIC_NP_SCP_RECORD_ADDR(base) ((base) + (0x020CUL))
#define SUB_PMIC_NP_OVP_RECORD_ADDR(base) ((base) + (0x020DUL))
#define SUB_PMIC_RAMP_IRQ_RECORD_ADDR(base) ((base) + (0x020EUL))
#else
#define SUB_PMIC_NP_IRQ1_RECORD_ADDR(base) ((base) + (0x020A))
#define SUB_PMIC_NP_OCP_RECORD_ADDR(base) ((base) + (0x020B))
#define SUB_PMIC_NP_SCP_RECORD_ADDR(base) ((base) + (0x020C))
#define SUB_PMIC_NP_OVP_RECORD_ADDR(base) ((base) + (0x020D))
#define SUB_PMIC_RAMP_IRQ_RECORD_ADDR(base) ((base) + (0x020E))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SUB_PMIC_VSYS_SET_ADDR(base) ((base) + (0x0400UL))
#define SUB_PMIC_NP_DEB_CTRL_ADDR(base) ((base) + (0x0401UL))
#define SUB_PMIC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x0402UL))
#define SUB_PMIC_OTP_7_0_ADDR(base) ((base) + (0x0403UL))
#define SUB_PMIC_OTP_15_8_ADDR(base) ((base) + (0x0404UL))
#define SUB_PMIC_OTP_23_16_ADDR(base) ((base) + (0x0405UL))
#define SUB_PMIC_OTP_31_24_ADDR(base) ((base) + (0x0406UL))
#define SUB_PMIC_OTP_39_32_ADDR(base) ((base) + (0x0407UL))
#define SUB_PMIC_OTP_47_40_ADDR(base) ((base) + (0x0408UL))
#define SUB_PMIC_OTP_55_48_ADDR(base) ((base) + (0x0409UL))
#define SUB_PMIC_OTP_63_56_ADDR(base) ((base) + (0x040AUL))
#define SUB_PMIC_OTP_71_64_ADDR(base) ((base) + (0x040BUL))
#define SUB_PMIC_OTP_79_72_ADDR(base) ((base) + (0x040CUL))
#define SUB_PMIC_OTP_87_80_ADDR(base) ((base) + (0x040DUL))
#define SUB_PMIC_OTP_95_88_ADDR(base) ((base) + (0x040EUL))
#define SUB_PMIC_OTP_103_96_ADDR(base) ((base) + (0x040FUL))
#define SUB_PMIC_OTP_111_104_ADDR(base) ((base) + (0x0410UL))
#define SUB_PMIC_OTP_119_112_ADDR(base) ((base) + (0x0411UL))
#define SUB_PMIC_OTP_127_120_ADDR(base) ((base) + (0x0412UL))
#define SUB_PMIC_OTP_135_128_ADDR(base) ((base) + (0x0413UL))
#define SUB_PMIC_OTP_143_136_ADDR(base) ((base) + (0x0414UL))
#define SUB_PMIC_OTP_151_144_ADDR(base) ((base) + (0x0415UL))
#define SUB_PMIC_OTP_159_152_ADDR(base) ((base) + (0x0416UL))
#define SUB_PMIC_OTP_167_160_ADDR(base) ((base) + (0x0417UL))
#define SUB_PMIC_OTP_175_168_ADDR(base) ((base) + (0x0418UL))
#define SUB_PMIC_OTP_183_176_ADDR(base) ((base) + (0x0419UL))
#define SUB_PMIC_OTP_191_184_ADDR(base) ((base) + (0x041AUL))
#define SUB_PMIC_OTP_199_192_ADDR(base) ((base) + (0x041BUL))
#define SUB_PMIC_OTP_207_200_ADDR(base) ((base) + (0x041CUL))
#define SUB_PMIC_OTP_215_208_ADDR(base) ((base) + (0x041DUL))
#define SUB_PMIC_OTP_223_216_ADDR(base) ((base) + (0x041EUL))
#define SUB_PMIC_OTP_231_224_ADDR(base) ((base) + (0x041FUL))
#define SUB_PMIC_OTP_239_232_ADDR(base) ((base) + (0x0420UL))
#define SUB_PMIC_OTP_247_240_ADDR(base) ((base) + (0x0421UL))
#define SUB_PMIC_OTP_255_248_ADDR(base) ((base) + (0x0422UL))
#else
#define SUB_PMIC_VSYS_SET_ADDR(base) ((base) + (0x0400))
#define SUB_PMIC_NP_DEB_CTRL_ADDR(base) ((base) + (0x0401))
#define SUB_PMIC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x0402))
#define SUB_PMIC_OTP_7_0_ADDR(base) ((base) + (0x0403))
#define SUB_PMIC_OTP_15_8_ADDR(base) ((base) + (0x0404))
#define SUB_PMIC_OTP_23_16_ADDR(base) ((base) + (0x0405))
#define SUB_PMIC_OTP_31_24_ADDR(base) ((base) + (0x0406))
#define SUB_PMIC_OTP_39_32_ADDR(base) ((base) + (0x0407))
#define SUB_PMIC_OTP_47_40_ADDR(base) ((base) + (0x0408))
#define SUB_PMIC_OTP_55_48_ADDR(base) ((base) + (0x0409))
#define SUB_PMIC_OTP_63_56_ADDR(base) ((base) + (0x040A))
#define SUB_PMIC_OTP_71_64_ADDR(base) ((base) + (0x040B))
#define SUB_PMIC_OTP_79_72_ADDR(base) ((base) + (0x040C))
#define SUB_PMIC_OTP_87_80_ADDR(base) ((base) + (0x040D))
#define SUB_PMIC_OTP_95_88_ADDR(base) ((base) + (0x040E))
#define SUB_PMIC_OTP_103_96_ADDR(base) ((base) + (0x040F))
#define SUB_PMIC_OTP_111_104_ADDR(base) ((base) + (0x0410))
#define SUB_PMIC_OTP_119_112_ADDR(base) ((base) + (0x0411))
#define SUB_PMIC_OTP_127_120_ADDR(base) ((base) + (0x0412))
#define SUB_PMIC_OTP_135_128_ADDR(base) ((base) + (0x0413))
#define SUB_PMIC_OTP_143_136_ADDR(base) ((base) + (0x0414))
#define SUB_PMIC_OTP_151_144_ADDR(base) ((base) + (0x0415))
#define SUB_PMIC_OTP_159_152_ADDR(base) ((base) + (0x0416))
#define SUB_PMIC_OTP_167_160_ADDR(base) ((base) + (0x0417))
#define SUB_PMIC_OTP_175_168_ADDR(base) ((base) + (0x0418))
#define SUB_PMIC_OTP_183_176_ADDR(base) ((base) + (0x0419))
#define SUB_PMIC_OTP_191_184_ADDR(base) ((base) + (0x041A))
#define SUB_PMIC_OTP_199_192_ADDR(base) ((base) + (0x041B))
#define SUB_PMIC_OTP_207_200_ADDR(base) ((base) + (0x041C))
#define SUB_PMIC_OTP_215_208_ADDR(base) ((base) + (0x041D))
#define SUB_PMIC_OTP_223_216_ADDR(base) ((base) + (0x041E))
#define SUB_PMIC_OTP_231_224_ADDR(base) ((base) + (0x041F))
#define SUB_PMIC_OTP_239_232_ADDR(base) ((base) + (0x0420))
#define SUB_PMIC_OTP_247_240_ADDR(base) ((base) + (0x0421))
#define SUB_PMIC_OTP_255_248_ADDR(base) ((base) + (0x0422))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num0 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_0_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_0_project_num0_START (0)
#define SUB_PMIC_CHIP_VERSION_0_project_num0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num1 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_1_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_1_project_num1_START (0)
#define SUB_PMIC_CHIP_VERSION_1_project_num1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num2 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_2_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_2_project_num2_START (0)
#define SUB_PMIC_CHIP_VERSION_2_project_num2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num3 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_3_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_3_project_num3_START (0)
#define SUB_PMIC_CHIP_VERSION_3_project_num3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char version0 : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_4_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_4_version0_START (0)
#define SUB_PMIC_CHIP_VERSION_4_version0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id : 8;
    } reg;
} SUB_PMIC_CHIP_VERSION_5_UNION;
#endif
#define SUB_PMIC_CHIP_VERSION_5_chip_id_START (0)
#define SUB_PMIC_CHIP_VERSION_5_chip_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char thsd_otmp140_d540ur : 1;
        unsigned char thsd_otmp125_d1mr : 1;
        unsigned char vsys_pwroff_abs_d20nr : 1;
        unsigned char vsys_ov_d200ur : 1;
        unsigned char vsys_pwron_d60ur : 1;
        unsigned char buck01_ovp_masked : 1;
        unsigned char buck2_ovp_masked : 1;
        unsigned char buck3_ovp_masked : 1;
    } reg;
} SUB_PMIC_STATUS0_UNION;
#endif
#define SUB_PMIC_STATUS0_thsd_otmp140_d540ur_START (0)
#define SUB_PMIC_STATUS0_thsd_otmp140_d540ur_END (0)
#define SUB_PMIC_STATUS0_thsd_otmp125_d1mr_START (1)
#define SUB_PMIC_STATUS0_thsd_otmp125_d1mr_END (1)
#define SUB_PMIC_STATUS0_vsys_pwroff_abs_d20nr_START (2)
#define SUB_PMIC_STATUS0_vsys_pwroff_abs_d20nr_END (2)
#define SUB_PMIC_STATUS0_vsys_ov_d200ur_START (3)
#define SUB_PMIC_STATUS0_vsys_ov_d200ur_END (3)
#define SUB_PMIC_STATUS0_vsys_pwron_d60ur_START (4)
#define SUB_PMIC_STATUS0_vsys_pwron_d60ur_END (4)
#define SUB_PMIC_STATUS0_buck01_ovp_masked_START (5)
#define SUB_PMIC_STATUS0_buck01_ovp_masked_END (5)
#define SUB_PMIC_STATUS0_buck2_ovp_masked_START (6)
#define SUB_PMIC_STATUS0_buck2_ovp_masked_END (6)
#define SUB_PMIC_STATUS0_buck3_ovp_masked_START (7)
#define SUB_PMIC_STATUS0_buck3_ovp_masked_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ocp_masked : 1;
        unsigned char buck1_ocp_masked : 1;
        unsigned char buck2_ocp_masked : 1;
        unsigned char buck3_ocp_masked : 1;
        unsigned char buck0_scp_masked : 1;
        unsigned char buck1_scp_masked : 1;
        unsigned char buck2_scp_masked : 1;
        unsigned char buck3_scp_masked : 1;
    } reg;
} SUB_PMIC_OCP_SCP_STATUS_UNION;
#endif
#define SUB_PMIC_OCP_SCP_STATUS_buck0_ocp_masked_START (0)
#define SUB_PMIC_OCP_SCP_STATUS_buck0_ocp_masked_END (0)
#define SUB_PMIC_OCP_SCP_STATUS_buck1_ocp_masked_START (1)
#define SUB_PMIC_OCP_SCP_STATUS_buck1_ocp_masked_END (1)
#define SUB_PMIC_OCP_SCP_STATUS_buck2_ocp_masked_START (2)
#define SUB_PMIC_OCP_SCP_STATUS_buck2_ocp_masked_END (2)
#define SUB_PMIC_OCP_SCP_STATUS_buck3_ocp_masked_START (3)
#define SUB_PMIC_OCP_SCP_STATUS_buck3_ocp_masked_END (3)
#define SUB_PMIC_OCP_SCP_STATUS_buck0_scp_masked_START (4)
#define SUB_PMIC_OCP_SCP_STATUS_buck0_scp_masked_END (4)
#define SUB_PMIC_OCP_SCP_STATUS_buck1_scp_masked_START (5)
#define SUB_PMIC_OCP_SCP_STATUS_buck1_scp_masked_END (5)
#define SUB_PMIC_OCP_SCP_STATUS_buck2_scp_masked_START (6)
#define SUB_PMIC_OCP_SCP_STATUS_buck2_scp_masked_END (6)
#define SUB_PMIC_OCP_SCP_STATUS_buck3_scp_masked_START (7)
#define SUB_PMIC_OCP_SCP_STATUS_buck3_scp_masked_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_en_st : 1;
        unsigned char buck2_en_st : 1;
        unsigned char buck3_en_st : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck01_pg_st : 1;
        unsigned char buck2_pg_st : 1;
        unsigned char buck3_pg_st : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SUB_PMIC_BUCK_EN_STATUS_UNION;
#endif
#define SUB_PMIC_BUCK_EN_STATUS_buck01_en_st_START (0)
#define SUB_PMIC_BUCK_EN_STATUS_buck01_en_st_END (0)
#define SUB_PMIC_BUCK_EN_STATUS_buck2_en_st_START (1)
#define SUB_PMIC_BUCK_EN_STATUS_buck2_en_st_END (1)
#define SUB_PMIC_BUCK_EN_STATUS_buck3_en_st_START (2)
#define SUB_PMIC_BUCK_EN_STATUS_buck3_en_st_END (2)
#define SUB_PMIC_BUCK_EN_STATUS_buck01_pg_st_START (4)
#define SUB_PMIC_BUCK_EN_STATUS_buck01_pg_st_END (4)
#define SUB_PMIC_BUCK_EN_STATUS_buck2_pg_st_START (5)
#define SUB_PMIC_BUCK_EN_STATUS_buck2_pg_st_END (5)
#define SUB_PMIC_BUCK_EN_STATUS_buck3_pg_st_START (6)
#define SUB_PMIC_BUCK_EN_STATUS_buck3_pg_st_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b01_ramp_flag : 1;
        unsigned char b2_ramp_flag : 1;
        unsigned char b3_ramp_flag : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_RAMP_STATUS_UNION;
#endif
#define SUB_PMIC_RAMP_STATUS_b01_ramp_flag_START (0)
#define SUB_PMIC_RAMP_STATUS_b01_ramp_flag_END (0)
#define SUB_PMIC_RAMP_STATUS_b2_ramp_flag_START (1)
#define SUB_PMIC_RAMP_STATUS_b2_ramp_flag_END (1)
#define SUB_PMIC_RAMP_STATUS_b3_ramp_flag_START (2)
#define SUB_PMIC_RAMP_STATUS_b3_ramp_flag_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char phase_ctrl_set_st : 1;
        unsigned char i2c_spmi_sel_st : 1;
        unsigned char atest_a2d_st : 1;
        unsigned char pmu1_en_a2d_st : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_SYS_CTRL_STATUS_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_STATUS_phase_ctrl_set_st_START (0)
#define SUB_PMIC_SYS_CTRL_STATUS_phase_ctrl_set_st_END (0)
#define SUB_PMIC_SYS_CTRL_STATUS_i2c_spmi_sel_st_START (1)
#define SUB_PMIC_SYS_CTRL_STATUS_i2c_spmi_sel_st_END (1)
#define SUB_PMIC_SYS_CTRL_STATUS_atest_a2d_st_START (2)
#define SUB_PMIC_SYS_CTRL_STATUS_atest_a2d_st_END (2)
#define SUB_PMIC_SYS_CTRL_STATUS_pmu1_en_a2d_st_START (3)
#define SUB_PMIC_SYS_CTRL_STATUS_pmu1_en_a2d_st_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg000 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG0_pmu_ana_rwreg000_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG0_pmu_ana_rwreg000_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg001 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG1_pmu_ana_rwreg001_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG1_pmu_ana_rwreg001_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg002 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG2_pmu_ana_rwreg002_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG2_pmu_ana_rwreg002_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg003 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG3_pmu_ana_rwreg003_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG3_pmu_ana_rwreg003_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg004 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG4_pmu_ana_rwreg004_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG4_pmu_ana_rwreg004_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg005 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG5_pmu_ana_rwreg005_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG5_pmu_ana_rwreg005_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg006 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG6_pmu_ana_rwreg006_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG6_pmu_ana_rwreg006_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg007 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG7_pmu_ana_rwreg007_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG7_pmu_ana_rwreg007_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg008 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG8_pmu_ana_rwreg008_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG8_pmu_ana_rwreg008_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg009 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG9_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG9_pmu_ana_rwreg009_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG9_pmu_ana_rwreg009_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg010 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG10_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG10_pmu_ana_rwreg010_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG10_pmu_ana_rwreg010_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg011 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG11_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG11_pmu_ana_rwreg011_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG11_pmu_ana_rwreg011_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg012 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG12_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG12_pmu_ana_rwreg012_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG12_pmu_ana_rwreg012_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg013 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG13_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG13_pmu_ana_rwreg013_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG13_pmu_ana_rwreg013_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg014 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG14_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG14_pmu_ana_rwreg014_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG14_pmu_ana_rwreg014_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg015 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG15_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG15_pmu_ana_rwreg015_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG15_pmu_ana_rwreg015_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg016 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG16_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG16_pmu_ana_rwreg016_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG16_pmu_ana_rwreg016_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg017 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG17_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG17_pmu_ana_rwreg017_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG17_pmu_ana_rwreg017_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg018 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG18_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG18_pmu_ana_rwreg018_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG18_pmu_ana_rwreg018_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg019 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_CFG19_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_CFG19_pmu_ana_rwreg019_START (0)
#define SUB_PMIC_BUCK0_TOP_CFG19_pmu_ana_rwreg019_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg020_0 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE0_0_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE0_0_pmu_ana_rwreg020_0_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE0_0_pmu_ana_rwreg020_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg020_1 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE0_1_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE0_1_pmu_ana_rwreg020_1_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE0_1_pmu_ana_rwreg020_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg021_0 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE1_0_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE1_0_pmu_ana_rwreg021_0_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE1_0_pmu_ana_rwreg021_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg021_1 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE1_1_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE1_1_pmu_ana_rwreg021_1_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE1_1_pmu_ana_rwreg021_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg022_0 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE2_0_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE2_0_pmu_ana_rwreg022_0_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE2_0_pmu_ana_rwreg022_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg022_1 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE2_1_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE2_1_pmu_ana_rwreg022_1_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE2_1_pmu_ana_rwreg022_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg023_0 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE3_0_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE3_0_pmu_ana_rwreg023_0_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE3_0_pmu_ana_rwreg023_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg023_1 : 8;
    } reg;
} SUB_PMIC_BUCK0_TOP_STATE3_1_UNION;
#endif
#define SUB_PMIC_BUCK0_TOP_STATE3_1_pmu_ana_rwreg023_1_START (0)
#define SUB_PMIC_BUCK0_TOP_STATE3_1_pmu_ana_rwreg023_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg024 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG0_pmu_ana_rwreg024_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG0_pmu_ana_rwreg024_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg025 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG1_pmu_ana_rwreg025_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG1_pmu_ana_rwreg025_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg026 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG2_pmu_ana_rwreg026_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG2_pmu_ana_rwreg026_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg027 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG3_pmu_ana_rwreg027_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG3_pmu_ana_rwreg027_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg028 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG4_pmu_ana_rwreg028_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG4_pmu_ana_rwreg028_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg029 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG5_pmu_ana_rwreg029_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG5_pmu_ana_rwreg029_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg030 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG6_pmu_ana_rwreg030_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG6_pmu_ana_rwreg030_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg031 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG7_pmu_ana_rwreg031_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG7_pmu_ana_rwreg031_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg032 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG8_pmu_ana_rwreg032_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG8_pmu_ana_rwreg032_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg033 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG9_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG9_pmu_ana_rwreg033_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG9_pmu_ana_rwreg033_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg034 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG10_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG10_pmu_ana_rwreg034_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG10_pmu_ana_rwreg034_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg035 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG11_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG11_pmu_ana_rwreg035_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG11_pmu_ana_rwreg035_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg036 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG12_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG12_pmu_ana_rwreg036_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG12_pmu_ana_rwreg036_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg037 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG13_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG13_pmu_ana_rwreg037_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG13_pmu_ana_rwreg037_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg038 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG14_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG14_pmu_ana_rwreg038_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG14_pmu_ana_rwreg038_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg039 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG15_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG15_pmu_ana_rwreg039_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG15_pmu_ana_rwreg039_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg040 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG16_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG16_pmu_ana_rwreg040_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG16_pmu_ana_rwreg040_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg041 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG17_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG17_pmu_ana_rwreg041_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG17_pmu_ana_rwreg041_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg042 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG18_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG18_pmu_ana_rwreg042_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG18_pmu_ana_rwreg042_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg043 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_CFG19_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_CFG19_pmu_ana_rwreg043_START (0)
#define SUB_PMIC_BUCK1_TOP_CFG19_pmu_ana_rwreg043_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg044_0 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE0_0_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE0_0_pmu_ana_rwreg044_0_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE0_0_pmu_ana_rwreg044_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg044_1 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE0_1_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE0_1_pmu_ana_rwreg044_1_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE0_1_pmu_ana_rwreg044_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg045_0 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE1_0_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE1_0_pmu_ana_rwreg045_0_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE1_0_pmu_ana_rwreg045_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg045_1 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE1_1_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE1_1_pmu_ana_rwreg045_1_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE1_1_pmu_ana_rwreg045_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg046_0 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE2_0_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE2_0_pmu_ana_rwreg046_0_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE2_0_pmu_ana_rwreg046_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg046_1 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE2_1_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE2_1_pmu_ana_rwreg046_1_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE2_1_pmu_ana_rwreg046_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg047_0 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE3_0_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE3_0_pmu_ana_rwreg047_0_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE3_0_pmu_ana_rwreg047_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg047_1 : 8;
    } reg;
} SUB_PMIC_BUCK1_TOP_STATE3_1_UNION;
#endif
#define SUB_PMIC_BUCK1_TOP_STATE3_1_pmu_ana_rwreg047_1_START (0)
#define SUB_PMIC_BUCK1_TOP_STATE3_1_pmu_ana_rwreg047_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg048 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG0_pmu_ana_rwreg048_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG0_pmu_ana_rwreg048_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg049 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG1_pmu_ana_rwreg049_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG1_pmu_ana_rwreg049_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg050 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG2_pmu_ana_rwreg050_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG2_pmu_ana_rwreg050_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg051 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG3_pmu_ana_rwreg051_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG3_pmu_ana_rwreg051_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg052 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG4_pmu_ana_rwreg052_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG4_pmu_ana_rwreg052_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg053 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG5_pmu_ana_rwreg053_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG5_pmu_ana_rwreg053_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg054 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG6_pmu_ana_rwreg054_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG6_pmu_ana_rwreg054_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg055 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG7_pmu_ana_rwreg055_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG7_pmu_ana_rwreg055_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg056 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG8_pmu_ana_rwreg056_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG8_pmu_ana_rwreg056_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg057 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG9_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG9_pmu_ana_rwreg057_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG9_pmu_ana_rwreg057_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg058 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG10_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG10_pmu_ana_rwreg058_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG10_pmu_ana_rwreg058_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg059 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG11_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG11_pmu_ana_rwreg059_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG11_pmu_ana_rwreg059_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg060 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG12_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG12_pmu_ana_rwreg060_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG12_pmu_ana_rwreg060_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg061 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG13_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG13_pmu_ana_rwreg061_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG13_pmu_ana_rwreg061_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg062 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG14_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG14_pmu_ana_rwreg062_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG14_pmu_ana_rwreg062_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg063 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG15_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG15_pmu_ana_rwreg063_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG15_pmu_ana_rwreg063_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg064 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG16_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG16_pmu_ana_rwreg064_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG16_pmu_ana_rwreg064_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg065 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG17_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG17_pmu_ana_rwreg065_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG17_pmu_ana_rwreg065_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg066 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG18_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG18_pmu_ana_rwreg066_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG18_pmu_ana_rwreg066_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg067 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_CFG19_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_CFG19_pmu_ana_rwreg067_START (0)
#define SUB_PMIC_BUCK2_TOP_CFG19_pmu_ana_rwreg067_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg068_0 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE0_0_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE0_0_pmu_ana_rwreg068_0_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE0_0_pmu_ana_rwreg068_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg068_1 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE0_1_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE0_1_pmu_ana_rwreg068_1_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE0_1_pmu_ana_rwreg068_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg069_0 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE1_0_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE1_0_pmu_ana_rwreg069_0_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE1_0_pmu_ana_rwreg069_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg069_1 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE1_1_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE1_1_pmu_ana_rwreg069_1_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE1_1_pmu_ana_rwreg069_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg070_0 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE2_0_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE2_0_pmu_ana_rwreg070_0_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE2_0_pmu_ana_rwreg070_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg070_1 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE2_1_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE2_1_pmu_ana_rwreg070_1_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE2_1_pmu_ana_rwreg070_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg071_0 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE3_0_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE3_0_pmu_ana_rwreg071_0_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE3_0_pmu_ana_rwreg071_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg071_1 : 8;
    } reg;
} SUB_PMIC_BUCK2_TOP_STATE3_1_UNION;
#endif
#define SUB_PMIC_BUCK2_TOP_STATE3_1_pmu_ana_rwreg071_1_START (0)
#define SUB_PMIC_BUCK2_TOP_STATE3_1_pmu_ana_rwreg071_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg072 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG0_pmu_ana_rwreg072_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG0_pmu_ana_rwreg072_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg073 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG1_pmu_ana_rwreg073_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG1_pmu_ana_rwreg073_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg074 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG2_pmu_ana_rwreg074_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG2_pmu_ana_rwreg074_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg075 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG3_pmu_ana_rwreg075_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG3_pmu_ana_rwreg075_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg076 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG4_pmu_ana_rwreg076_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG4_pmu_ana_rwreg076_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg077 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG5_pmu_ana_rwreg077_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG5_pmu_ana_rwreg077_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg078 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG6_pmu_ana_rwreg078_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG6_pmu_ana_rwreg078_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg079 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG7_pmu_ana_rwreg079_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG7_pmu_ana_rwreg079_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg080 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG8_pmu_ana_rwreg080_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG8_pmu_ana_rwreg080_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg081 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG9_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG9_pmu_ana_rwreg081_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG9_pmu_ana_rwreg081_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg082 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG10_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG10_pmu_ana_rwreg082_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG10_pmu_ana_rwreg082_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg083 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG11_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG11_pmu_ana_rwreg083_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG11_pmu_ana_rwreg083_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg084 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG12_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG12_pmu_ana_rwreg084_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG12_pmu_ana_rwreg084_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg085 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG13_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG13_pmu_ana_rwreg085_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG13_pmu_ana_rwreg085_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg086 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG14_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG14_pmu_ana_rwreg086_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG14_pmu_ana_rwreg086_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg087 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG15_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG15_pmu_ana_rwreg087_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG15_pmu_ana_rwreg087_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg088 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG16_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG16_pmu_ana_rwreg088_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG16_pmu_ana_rwreg088_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg089 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG17_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG17_pmu_ana_rwreg089_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG17_pmu_ana_rwreg089_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg090 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG18_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG18_pmu_ana_rwreg090_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG18_pmu_ana_rwreg090_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg091 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_CFG19_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_CFG19_pmu_ana_rwreg091_START (0)
#define SUB_PMIC_BUCK3_TOP_CFG19_pmu_ana_rwreg091_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg092_0 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE0_0_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE0_0_pmu_ana_rwreg092_0_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE0_0_pmu_ana_rwreg092_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg092_1 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE0_1_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE0_1_pmu_ana_rwreg092_1_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE0_1_pmu_ana_rwreg092_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg093_0 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE1_0_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE1_0_pmu_ana_rwreg093_0_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE1_0_pmu_ana_rwreg093_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg093_1 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE1_1_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE1_1_pmu_ana_rwreg093_1_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE1_1_pmu_ana_rwreg093_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg094_0 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE2_0_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE2_0_pmu_ana_rwreg094_0_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE2_0_pmu_ana_rwreg094_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg094_1 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE2_1_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE2_1_pmu_ana_rwreg094_1_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE2_1_pmu_ana_rwreg094_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg095_0 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE3_0_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE3_0_pmu_ana_rwreg095_0_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE3_0_pmu_ana_rwreg095_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg095_1 : 8;
    } reg;
} SUB_PMIC_BUCK3_TOP_STATE3_1_UNION;
#endif
#define SUB_PMIC_BUCK3_TOP_STATE3_1_pmu_ana_rwreg095_1_START (0)
#define SUB_PMIC_BUCK3_TOP_STATE3_1_pmu_ana_rwreg095_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg096 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG0_pmu_ana_rwreg096_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG0_pmu_ana_rwreg096_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg097 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG1_pmu_ana_rwreg097_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG1_pmu_ana_rwreg097_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg098 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG2_pmu_ana_rwreg098_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG2_pmu_ana_rwreg098_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg099 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG3_pmu_ana_rwreg099_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG3_pmu_ana_rwreg099_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg100 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG4_pmu_ana_rwreg100_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG4_pmu_ana_rwreg100_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg101 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG5_pmu_ana_rwreg101_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG5_pmu_ana_rwreg101_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg102 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG6_pmu_ana_rwreg102_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG6_pmu_ana_rwreg102_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg103 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG7_pmu_ana_rwreg103_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG7_pmu_ana_rwreg103_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg104 : 8;
    } reg;
} SUB_PMIC_BUCK01_COMMON_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK01_COMMON_CFG8_pmu_ana_rwreg104_START (0)
#define SUB_PMIC_BUCK01_COMMON_CFG8_pmu_ana_rwreg104_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg105 : 8;
    } reg;
} SUB_PMIC_BUCK2_COMMON_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK2_COMMON_CFG0_pmu_ana_rwreg105_START (0)
#define SUB_PMIC_BUCK2_COMMON_CFG0_pmu_ana_rwreg105_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg106 : 8;
    } reg;
} SUB_PMIC_BUCK2_COMMON_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK2_COMMON_CFG1_pmu_ana_rwreg106_START (0)
#define SUB_PMIC_BUCK2_COMMON_CFG1_pmu_ana_rwreg106_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg107 : 8;
    } reg;
} SUB_PMIC_BUCK2_COMMON_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK2_COMMON_CFG2_pmu_ana_rwreg107_START (0)
#define SUB_PMIC_BUCK2_COMMON_CFG2_pmu_ana_rwreg107_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg108 : 8;
    } reg;
} SUB_PMIC_BUCK2_COMMON_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK2_COMMON_CFG3_pmu_ana_rwreg108_START (0)
#define SUB_PMIC_BUCK2_COMMON_CFG3_pmu_ana_rwreg108_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg109 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG0_pmu_ana_rwreg109_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG0_pmu_ana_rwreg109_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg110 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG1_pmu_ana_rwreg110_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG1_pmu_ana_rwreg110_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg111 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG2_pmu_ana_rwreg111_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG2_pmu_ana_rwreg111_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg112 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG3_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG3_pmu_ana_rwreg112_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG3_pmu_ana_rwreg112_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg113 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG4_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG4_pmu_ana_rwreg113_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG4_pmu_ana_rwreg113_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg114 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG5_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG5_pmu_ana_rwreg114_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG5_pmu_ana_rwreg114_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg115 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG6_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG6_pmu_ana_rwreg115_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG6_pmu_ana_rwreg115_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg116 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG7_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG7_pmu_ana_rwreg116_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG7_pmu_ana_rwreg116_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg117 : 8;
    } reg;
} SUB_PMIC_BUCK3_COMMON_CFG8_UNION;
#endif
#define SUB_PMIC_BUCK3_COMMON_CFG8_pmu_ana_rwreg117_START (0)
#define SUB_PMIC_BUCK3_COMMON_CFG8_pmu_ana_rwreg117_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg118 : 8;
    } reg;
} SUB_PMIC_BUCK01_I_SHARE_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK01_I_SHARE_CFG0_pmu_ana_rwreg118_START (0)
#define SUB_PMIC_BUCK01_I_SHARE_CFG0_pmu_ana_rwreg118_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg119 : 8;
    } reg;
} SUB_PMIC_BUCK01_I_SHARE_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK01_I_SHARE_CFG1_pmu_ana_rwreg119_START (0)
#define SUB_PMIC_BUCK01_I_SHARE_CFG1_pmu_ana_rwreg119_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg120 : 8;
    } reg;
} SUB_PMIC_BUCK23_I_SHARE_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK23_I_SHARE_CFG0_pmu_ana_rwreg120_START (0)
#define SUB_PMIC_BUCK23_I_SHARE_CFG0_pmu_ana_rwreg120_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg121 : 8;
    } reg;
} SUB_PMIC_BUCK23_I_SHARE_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK23_I_SHARE_CFG1_pmu_ana_rwreg121_START (0)
#define SUB_PMIC_BUCK23_I_SHARE_CFG1_pmu_ana_rwreg121_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg122 : 8;
    } reg;
} SUB_PMIC_BUCK01_STATUS_SWITCH_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG0_pmu_ana_rwreg122_START (0)
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG0_pmu_ana_rwreg122_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg123 : 8;
    } reg;
} SUB_PMIC_BUCK01_STATUS_SWITCH_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG1_pmu_ana_rwreg123_START (0)
#define SUB_PMIC_BUCK01_STATUS_SWITCH_CFG1_pmu_ana_rwreg123_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg124 : 8;
    } reg;
} SUB_PMIC_BUCK23_STATUS_SWITCH_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG0_pmu_ana_rwreg124_START (0)
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG0_pmu_ana_rwreg124_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg125 : 8;
    } reg;
} SUB_PMIC_BUCK23_STATUS_SWITCH_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG1_pmu_ana_rwreg125_START (0)
#define SUB_PMIC_BUCK23_STATUS_SWITCH_CFG1_pmu_ana_rwreg125_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg126 : 8;
    } reg;
} SUB_PMIC_BUCK01_CLK_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK01_CLK_CFG0_pmu_ana_rwreg126_START (0)
#define SUB_PMIC_BUCK01_CLK_CFG0_pmu_ana_rwreg126_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg127 : 8;
    } reg;
} SUB_PMIC_BUCK01_CLK_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK01_CLK_CFG1_pmu_ana_rwreg127_START (0)
#define SUB_PMIC_BUCK01_CLK_CFG1_pmu_ana_rwreg127_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg128 : 8;
    } reg;
} SUB_PMIC_BUCK23_CLK_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK23_CLK_CFG0_pmu_ana_rwreg128_START (0)
#define SUB_PMIC_BUCK23_CLK_CFG0_pmu_ana_rwreg128_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg129 : 8;
    } reg;
} SUB_PMIC_BUCK23_CLK_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK23_CLK_CFG1_pmu_ana_rwreg129_START (0)
#define SUB_PMIC_BUCK23_CLK_CFG1_pmu_ana_rwreg129_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg130 : 8;
    } reg;
} SUB_PMIC_BUCK01_VO_DET_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK01_VO_DET_CFG0_pmu_ana_rwreg130_START (0)
#define SUB_PMIC_BUCK01_VO_DET_CFG0_pmu_ana_rwreg130_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg131 : 8;
    } reg;
} SUB_PMIC_BUCK01_VO_DET_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK01_VO_DET_CFG1_pmu_ana_rwreg131_START (0)
#define SUB_PMIC_BUCK01_VO_DET_CFG1_pmu_ana_rwreg131_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg132 : 8;
    } reg;
} SUB_PMIC_BUCK01_VO_DET_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK01_VO_DET_CFG2_pmu_ana_rwreg132_START (0)
#define SUB_PMIC_BUCK01_VO_DET_CFG2_pmu_ana_rwreg132_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg133 : 8;
    } reg;
} SUB_PMIC_BUCK23_VO_DET_CFG0_UNION;
#endif
#define SUB_PMIC_BUCK23_VO_DET_CFG0_pmu_ana_rwreg133_START (0)
#define SUB_PMIC_BUCK23_VO_DET_CFG0_pmu_ana_rwreg133_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg134 : 8;
    } reg;
} SUB_PMIC_BUCK23_VO_DET_CFG1_UNION;
#endif
#define SUB_PMIC_BUCK23_VO_DET_CFG1_pmu_ana_rwreg134_START (0)
#define SUB_PMIC_BUCK23_VO_DET_CFG1_pmu_ana_rwreg134_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg135 : 8;
    } reg;
} SUB_PMIC_BUCK23_VO_DET_CFG2_UNION;
#endif
#define SUB_PMIC_BUCK23_VO_DET_CFG2_pmu_ana_rwreg135_START (0)
#define SUB_PMIC_BUCK23_VO_DET_CFG2_pmu_ana_rwreg135_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg136 : 8;
    } reg;
} SUB_PMIC_ANA_RESERVE_D2A0_UNION;
#endif
#define SUB_PMIC_ANA_RESERVE_D2A0_pmu_ana_rwreg136_START (0)
#define SUB_PMIC_ANA_RESERVE_D2A0_pmu_ana_rwreg136_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg137 : 8;
    } reg;
} SUB_PMIC_ANA_RESERVE_D2A1_UNION;
#endif
#define SUB_PMIC_ANA_RESERVE_D2A1_pmu_ana_rwreg137_START (0)
#define SUB_PMIC_ANA_RESERVE_D2A1_pmu_ana_rwreg137_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg138 : 8;
    } reg;
} SUB_PMIC_ANA_RESERVE_D2A2_UNION;
#endif
#define SUB_PMIC_ANA_RESERVE_D2A2_pmu_ana_rwreg138_START (0)
#define SUB_PMIC_ANA_RESERVE_D2A2_pmu_ana_rwreg138_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmu_ana_rwreg139 : 8;
    } reg;
} SUB_PMIC_ANA_RESERVE_D2A3_UNION;
#endif
#define SUB_PMIC_ANA_RESERVE_D2A3_pmu_ana_rwreg139_START (0)
#define SUB_PMIC_ANA_RESERVE_D2A3_pmu_ana_rwreg139_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b01_dv_h : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_BUCK01_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK01_CTRL_b01_dv_h_START (0)
#define SUB_PMIC_BUCK01_CTRL_b01_dv_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b2_dv_h : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_BUCK2_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK2_CTRL_b2_dv_h_START (0)
#define SUB_PMIC_BUCK2_CTRL_b2_dv_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b3_dv_h : 4;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_BUCK3_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK3_CTRL_b3_dv_h_START (0)
#define SUB_PMIC_BUCK3_CTRL_b3_dv_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_state_ctrl : 2;
        unsigned char buck2_state_ctrl : 2;
        unsigned char buck3_state_ctrl : 2;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK_STATE_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK_STATE_CTRL_buck01_state_ctrl_START (0)
#define SUB_PMIC_BUCK_STATE_CTRL_buck01_state_ctrl_END (1)
#define SUB_PMIC_BUCK_STATE_CTRL_buck2_state_ctrl_START (2)
#define SUB_PMIC_BUCK_STATE_CTRL_buck2_state_ctrl_END (3)
#define SUB_PMIC_BUCK_STATE_CTRL_buck3_state_ctrl_START (4)
#define SUB_PMIC_BUCK_STATE_CTRL_buck3_state_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_vo_f : 1;
        unsigned char reserved_0 : 1;
        unsigned char buck3_vo_f : 1;
        unsigned char reserved_1 : 5;
    } reg;
} SUB_PMIC_BUCK_VO_DET_STATUS_UNION;
#endif
#define SUB_PMIC_BUCK_VO_DET_STATUS_buck01_vo_f_START (0)
#define SUB_PMIC_BUCK_VO_DET_STATUS_buck01_vo_f_END (0)
#define SUB_PMIC_BUCK_VO_DET_STATUS_buck3_vo_f_START (2)
#define SUB_PMIC_BUCK_VO_DET_STATUS_buck3_vo_f_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char osc_9m6_sel : 8;
    } reg;
} SUB_PMIC_OSC_9M6_CTRL_UNION;
#endif
#define SUB_PMIC_OSC_9M6_CTRL_osc_9m6_sel_START (0)
#define SUB_PMIC_OSC_9M6_CTRL_osc_9m6_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ref_test : 8;
    } reg;
} SUB_PMIC_REF_TEST_UNION;
#endif
#define SUB_PMIC_REF_TEST_ref_test_START (0)
#define SUB_PMIC_REF_TEST_ref_test_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ref_eco_en : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_REF_CTRL_UNION;
#endif
#define SUB_PMIC_REF_CTRL_ref_eco_en_START (0)
#define SUB_PMIC_REF_CTRL_ref_eco_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ref_reserved : 8;
    } reg;
} SUB_PMIC_REF_RESERVE_UNION;
#endif
#define SUB_PMIC_REF_RESERVE_ref_reserved_START (0)
#define SUB_PMIC_REF_RESERVE_ref_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char thsd_set_tmp : 2;
        unsigned char reg_thsd_en : 1;
        unsigned char thsd_en_sel : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_TH_CTRL_UNION;
#endif
#define SUB_PMIC_TH_CTRL_thsd_set_tmp_START (0)
#define SUB_PMIC_TH_CTRL_thsd_set_tmp_END (1)
#define SUB_PMIC_TH_CTRL_reg_thsd_en_START (2)
#define SUB_PMIC_TH_CTRL_reg_thsd_en_END (2)
#define SUB_PMIC_TH_CTRL_thsd_en_sel_START (3)
#define SUB_PMIC_TH_CTRL_thsd_en_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sys_ctrl_reserve : 8;
    } reg;
} SUB_PMIC_SYS_CTRL_RESERVE_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_RESERVE_sys_ctrl_reserve_START (0)
#define SUB_PMIC_SYS_CTRL_RESERVE_sys_ctrl_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_reserve : 8;
    } reg;
} SUB_PMIC_LDO01_RESERVE_UNION;
#endif
#define SUB_PMIC_LDO01_RESERVE_ldo_reserve_START (0)
#define SUB_PMIC_LDO01_RESERVE_ldo_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ana_test_sel : 8;
    } reg;
} SUB_PMIC_ANA_TEST_CTRL_UNION;
#endif
#define SUB_PMIC_ANA_TEST_CTRL_ana_test_sel_START (0)
#define SUB_PMIC_ANA_TEST_CTRL_ana_test_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char a2d_rsv0 : 8;
    } reg;
} SUB_PMIC_ANA_RSV_A2D0_UNION;
#endif
#define SUB_PMIC_ANA_RSV_A2D0_a2d_rsv0_START (0)
#define SUB_PMIC_ANA_RSV_A2D0_a2d_rsv0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char a2d_rsv1 : 8;
    } reg;
} SUB_PMIC_ANA_RSV_A2D1_UNION;
#endif
#define SUB_PMIC_ANA_RSV_A2D1_a2d_rsv1_START (0)
#define SUB_PMIC_ANA_RSV_A2D1_a2d_rsv1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob0 : 8;
    } reg;
} SUB_PMIC_OTP_0_UNION;
#endif
#define SUB_PMIC_OTP_0_otp_pdob0_START (0)
#define SUB_PMIC_OTP_0_otp_pdob0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob1 : 8;
    } reg;
} SUB_PMIC_OTP_1_UNION;
#endif
#define SUB_PMIC_OTP_1_otp_pdob1_START (0)
#define SUB_PMIC_OTP_1_otp_pdob1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_clk_ctrl : 8;
    } reg;
} SUB_PMIC_OTP_CLK_CTRL_UNION;
#endif
#define SUB_PMIC_OTP_CLK_CTRL_otp_clk_ctrl_START (0)
#define SUB_PMIC_OTP_CLK_CTRL_otp_clk_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pwe_int : 1;
        unsigned char otp_pwe_pulse : 1;
        unsigned char otp_por_int : 1;
        unsigned char otp_por_pulse : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_OTP_CTRL0_UNION;
#endif
#define SUB_PMIC_OTP_CTRL0_otp_pwe_int_START (0)
#define SUB_PMIC_OTP_CTRL0_otp_pwe_int_END (0)
#define SUB_PMIC_OTP_CTRL0_otp_pwe_pulse_START (1)
#define SUB_PMIC_OTP_CTRL0_otp_pwe_pulse_END (1)
#define SUB_PMIC_OTP_CTRL0_otp_por_int_START (2)
#define SUB_PMIC_OTP_CTRL0_otp_por_int_END (2)
#define SUB_PMIC_OTP_CTRL0_otp_por_pulse_START (3)
#define SUB_PMIC_OTP_CTRL0_otp_por_pulse_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pprog : 1;
        unsigned char otp_inctrl_sel : 1;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_OTP_CTRL1_UNION;
#endif
#define SUB_PMIC_OTP_CTRL1_otp_pprog_START (0)
#define SUB_PMIC_OTP_CTRL1_otp_pprog_END (0)
#define SUB_PMIC_OTP_CTRL1_otp_inctrl_sel_START (1)
#define SUB_PMIC_OTP_CTRL1_otp_inctrl_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pa_cfg : 6;
        unsigned char otp_ptm : 2;
    } reg;
} SUB_PMIC_OTP_CTRL2_UNION;
#endif
#define SUB_PMIC_OTP_CTRL2_otp_pa_cfg_START (0)
#define SUB_PMIC_OTP_CTRL2_otp_pa_cfg_END (5)
#define SUB_PMIC_OTP_CTRL2_otp_ptm_START (6)
#define SUB_PMIC_OTP_CTRL2_otp_ptm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdin : 8;
    } reg;
} SUB_PMIC_OTP_WDATA_UNION;
#endif
#define SUB_PMIC_OTP_WDATA_otp_pdin_START (0)
#define SUB_PMIC_OTP_WDATA_otp_pdin_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob0_w : 8;
    } reg;
} SUB_PMIC_OTP_0_W_UNION;
#endif
#define SUB_PMIC_OTP_0_W_otp_pdob0_w_START (0)
#define SUB_PMIC_OTP_0_W_otp_pdob0_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob1_w : 8;
    } reg;
} SUB_PMIC_OTP_1_W_UNION;
#endif
#define SUB_PMIC_OTP_1_W_otp_pdob1_w_START (0)
#define SUB_PMIC_OTP_1_W_otp_pdob1_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob2_w : 8;
    } reg;
} SUB_PMIC_OTP_2_W_UNION;
#endif
#define SUB_PMIC_OTP_2_W_otp_pdob2_w_START (0)
#define SUB_PMIC_OTP_2_W_otp_pdob2_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob3_w : 8;
    } reg;
} SUB_PMIC_OTP_3_W_UNION;
#endif
#define SUB_PMIC_OTP_3_W_otp_pdob3_w_START (0)
#define SUB_PMIC_OTP_3_W_otp_pdob3_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob4_w : 8;
    } reg;
} SUB_PMIC_OTP_4_W_UNION;
#endif
#define SUB_PMIC_OTP_4_W_otp_pdob4_w_START (0)
#define SUB_PMIC_OTP_4_W_otp_pdob4_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob5_w : 8;
    } reg;
} SUB_PMIC_OTP_5_W_UNION;
#endif
#define SUB_PMIC_OTP_5_W_otp_pdob5_w_START (0)
#define SUB_PMIC_OTP_5_W_otp_pdob5_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob6_w : 8;
    } reg;
} SUB_PMIC_OTP_6_W_UNION;
#endif
#define SUB_PMIC_OTP_6_W_otp_pdob6_w_START (0)
#define SUB_PMIC_OTP_6_W_otp_pdob6_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob7_w : 8;
    } reg;
} SUB_PMIC_OTP_7_W_UNION;
#endif
#define SUB_PMIC_OTP_7_W_otp_pdob7_w_START (0)
#define SUB_PMIC_OTP_7_W_otp_pdob7_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob8_w : 8;
    } reg;
} SUB_PMIC_OTP_8_W_UNION;
#endif
#define SUB_PMIC_OTP_8_W_otp_pdob8_w_START (0)
#define SUB_PMIC_OTP_8_W_otp_pdob8_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob9_w : 8;
    } reg;
} SUB_PMIC_OTP_9_W_UNION;
#endif
#define SUB_PMIC_OTP_9_W_otp_pdob9_w_START (0)
#define SUB_PMIC_OTP_9_W_otp_pdob9_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob10_w : 8;
    } reg;
} SUB_PMIC_OTP_10_W_UNION;
#endif
#define SUB_PMIC_OTP_10_W_otp_pdob10_w_START (0)
#define SUB_PMIC_OTP_10_W_otp_pdob10_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob11_w : 8;
    } reg;
} SUB_PMIC_OTP_11_W_UNION;
#endif
#define SUB_PMIC_OTP_11_W_otp_pdob11_w_START (0)
#define SUB_PMIC_OTP_11_W_otp_pdob11_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob12_w : 8;
    } reg;
} SUB_PMIC_OTP_12_W_UNION;
#endif
#define SUB_PMIC_OTP_12_W_otp_pdob12_w_START (0)
#define SUB_PMIC_OTP_12_W_otp_pdob12_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob13_w : 8;
    } reg;
} SUB_PMIC_OTP_13_W_UNION;
#endif
#define SUB_PMIC_OTP_13_W_otp_pdob13_w_START (0)
#define SUB_PMIC_OTP_13_W_otp_pdob13_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob14_w : 8;
    } reg;
} SUB_PMIC_OTP_14_W_UNION;
#endif
#define SUB_PMIC_OTP_14_W_otp_pdob14_w_START (0)
#define SUB_PMIC_OTP_14_W_otp_pdob14_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob15_w : 8;
    } reg;
} SUB_PMIC_OTP_15_W_UNION;
#endif
#define SUB_PMIC_OTP_15_W_otp_pdob15_w_START (0)
#define SUB_PMIC_OTP_15_W_otp_pdob15_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob16_w : 8;
    } reg;
} SUB_PMIC_OTP_16_W_UNION;
#endif
#define SUB_PMIC_OTP_16_W_otp_pdob16_w_START (0)
#define SUB_PMIC_OTP_16_W_otp_pdob16_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob17_w : 8;
    } reg;
} SUB_PMIC_OTP_17_W_UNION;
#endif
#define SUB_PMIC_OTP_17_W_otp_pdob17_w_START (0)
#define SUB_PMIC_OTP_17_W_otp_pdob17_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob18_w : 8;
    } reg;
} SUB_PMIC_OTP_18_W_UNION;
#endif
#define SUB_PMIC_OTP_18_W_otp_pdob18_w_START (0)
#define SUB_PMIC_OTP_18_W_otp_pdob18_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob19_w : 8;
    } reg;
} SUB_PMIC_OTP_19_W_UNION;
#endif
#define SUB_PMIC_OTP_19_W_otp_pdob19_w_START (0)
#define SUB_PMIC_OTP_19_W_otp_pdob19_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob20_w : 8;
    } reg;
} SUB_PMIC_OTP_20_W_UNION;
#endif
#define SUB_PMIC_OTP_20_W_otp_pdob20_w_START (0)
#define SUB_PMIC_OTP_20_W_otp_pdob20_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob21_w : 8;
    } reg;
} SUB_PMIC_OTP_21_W_UNION;
#endif
#define SUB_PMIC_OTP_21_W_otp_pdob21_w_START (0)
#define SUB_PMIC_OTP_21_W_otp_pdob21_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob22_w : 8;
    } reg;
} SUB_PMIC_OTP_22_W_UNION;
#endif
#define SUB_PMIC_OTP_22_W_otp_pdob22_w_START (0)
#define SUB_PMIC_OTP_22_W_otp_pdob22_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob23_w : 8;
    } reg;
} SUB_PMIC_OTP_23_W_UNION;
#endif
#define SUB_PMIC_OTP_23_W_otp_pdob23_w_START (0)
#define SUB_PMIC_OTP_23_W_otp_pdob23_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob24_w : 8;
    } reg;
} SUB_PMIC_OTP_24_W_UNION;
#endif
#define SUB_PMIC_OTP_24_W_otp_pdob24_w_START (0)
#define SUB_PMIC_OTP_24_W_otp_pdob24_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob25_w : 8;
    } reg;
} SUB_PMIC_OTP_25_W_UNION;
#endif
#define SUB_PMIC_OTP_25_W_otp_pdob25_w_START (0)
#define SUB_PMIC_OTP_25_W_otp_pdob25_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob26_w : 8;
    } reg;
} SUB_PMIC_OTP_26_W_UNION;
#endif
#define SUB_PMIC_OTP_26_W_otp_pdob26_w_START (0)
#define SUB_PMIC_OTP_26_W_otp_pdob26_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob27_w : 8;
    } reg;
} SUB_PMIC_OTP_27_W_UNION;
#endif
#define SUB_PMIC_OTP_27_W_otp_pdob27_w_START (0)
#define SUB_PMIC_OTP_27_W_otp_pdob27_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob28_w : 8;
    } reg;
} SUB_PMIC_OTP_28_W_UNION;
#endif
#define SUB_PMIC_OTP_28_W_otp_pdob28_w_START (0)
#define SUB_PMIC_OTP_28_W_otp_pdob28_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob29_w : 8;
    } reg;
} SUB_PMIC_OTP_29_W_UNION;
#endif
#define SUB_PMIC_OTP_29_W_otp_pdob29_w_START (0)
#define SUB_PMIC_OTP_29_W_otp_pdob29_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob30_w : 8;
    } reg;
} SUB_PMIC_OTP_30_W_UNION;
#endif
#define SUB_PMIC_OTP_30_W_otp_pdob30_w_START (0)
#define SUB_PMIC_OTP_30_W_otp_pdob30_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob31_w : 8;
    } reg;
} SUB_PMIC_OTP_31_W_UNION;
#endif
#define SUB_PMIC_OTP_31_W_otp_pdob31_w_START (0)
#define SUB_PMIC_OTP_31_W_otp_pdob31_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck01_en : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_ENABLE0_BUCK_UNION;
#endif
#define SUB_PMIC_ENABLE0_BUCK_reg_buck01_en_START (0)
#define SUB_PMIC_ENABLE0_BUCK_reg_buck01_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck2_en : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_ENABLE2_BUCK_UNION;
#endif
#define SUB_PMIC_ENABLE2_BUCK_reg_buck2_en_START (0)
#define SUB_PMIC_ENABLE2_BUCK_reg_buck2_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck3_en : 1;
        unsigned char reserved : 7;
    } reg;
} SUB_PMIC_ENABLE3_BUCK_UNION;
#endif
#define SUB_PMIC_ENABLE3_BUCK_reg_buck3_en_START (0)
#define SUB_PMIC_ENABLE3_BUCK_reg_buck3_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck01_rampdown_ctr : 3;
        unsigned char reg_buck01_rampup_ctr : 3;
        unsigned char reg_buck01_ramp_en : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_BUCK01_RAMP_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_rampdown_ctr_START (0)
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_rampdown_ctr_END (2)
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_rampup_ctr_START (3)
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_rampup_ctr_END (5)
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_ramp_en_START (6)
#define SUB_PMIC_BUCK01_RAMP_CTRL_reg_buck01_ramp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck01_vset : 8;
    } reg;
} SUB_PMIC_BUCK01_VSET_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK01_VSET_CTRL_reg_buck01_vset_START (0)
#define SUB_PMIC_BUCK01_VSET_CTRL_reg_buck01_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_rampup_chg_vset : 3;
        unsigned char buck01_rampup_chg_rate : 2;
        unsigned char buck01_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_UNION;
#endif
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_rampup_chg_vset_START (0)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_rampup_chg_vset_END (2)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_rampup_chg_rate_START (3)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_rampup_chg_rate_END (4)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_ru_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL0_buck01_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_rampdown_chg_vset : 3;
        unsigned char buck01_rampdown_chg_rate : 2;
        unsigned char buck01_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_UNION;
#endif
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rampdown_chg_rate_START (3)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rampdown_chg_rate_END (4)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rd_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK01_RAMP_CHG_CTRL1_buck01_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_dly_ru_off_cfg : 3;
        unsigned char buck01_dly_ru_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK01_RAMPUP_STATE_UNION;
#endif
#define SUB_PMIC_BUCK01_RAMPUP_STATE_buck01_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK01_RAMPUP_STATE_buck01_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK01_RAMPUP_STATE_buck01_dly_ru_on_cfg_START (3)
#define SUB_PMIC_BUCK01_RAMPUP_STATE_buck01_dly_ru_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_dly_rd_off_cfg : 3;
        unsigned char buck01_dly_rd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK01_RAMPDOWN_STATE_UNION;
#endif
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_buck01_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_buck01_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_buck01_dly_rd_on_cfg_START (3)
#define SUB_PMIC_BUCK01_RAMPDOWN_STATE_buck01_dly_rd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_dly_pd_off_cfg : 3;
        unsigned char buck01_dly_pd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK01_PULL_DOWN_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_buck01_dly_pd_off_cfg_START (0)
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_buck01_dly_pd_off_cfg_END (2)
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_buck01_dly_pd_on_cfg_START (3)
#define SUB_PMIC_BUCK01_PULL_DOWN_CTRL_buck01_dly_pd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck2_rampdown_ctr : 3;
        unsigned char reg_buck2_rampup_ctr : 3;
        unsigned char reg_buck2_ramp_en : 1;
        unsigned char reserved : 1;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_rampdown_ctr_START (0)
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_rampdown_ctr_END (2)
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_rampup_ctr_START (3)
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_rampup_ctr_END (5)
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_ramp_en_START (6)
#define SUB_PMIC_BUCK2_RAMP_CTRL_reg_buck2_ramp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck2_vset : 8;
    } reg;
} SUB_PMIC_BUCK2_VSET_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK2_VSET_CTRL_reg_buck2_vset_START (0)
#define SUB_PMIC_BUCK2_VSET_CTRL_reg_buck2_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_rampup_chg_vset : 3;
        unsigned char buck2_rampup_chg_rate : 2;
        unsigned char buck2_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_rampup_chg_vset_START (0)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_rampup_chg_vset_END (2)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_rampup_chg_rate_START (3)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_rampup_chg_rate_END (4)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_ru_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL0_buck2_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_rampdown_chg_vset : 3;
        unsigned char buck2_rampdown_chg_rate : 2;
        unsigned char buck2_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rampdown_chg_rate_START (3)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rampdown_chg_rate_END (4)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rd_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK2_RAMP_CHG_CTRL1_buck2_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_dly_ru_off_cfg : 3;
        unsigned char buck2_dly_ru_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK2_RAMPUP_STATE_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMPUP_STATE_buck2_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK2_RAMPUP_STATE_buck2_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK2_RAMPUP_STATE_buck2_dly_ru_on_cfg_START (3)
#define SUB_PMIC_BUCK2_RAMPUP_STATE_buck2_dly_ru_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_dly_rd_off_cfg : 3;
        unsigned char buck2_dly_rd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK2_RAMPDOWN_STATE_UNION;
#endif
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_buck2_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_buck2_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_buck2_dly_rd_on_cfg_START (3)
#define SUB_PMIC_BUCK2_RAMPDOWN_STATE_buck2_dly_rd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_dly_pd_off_cfg : 3;
        unsigned char buck2_dly_pd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK2_PULL_DOWN_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_buck2_dly_pd_off_cfg_START (0)
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_buck2_dly_pd_off_cfg_END (2)
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_buck2_dly_pd_on_cfg_START (3)
#define SUB_PMIC_BUCK2_PULL_DOWN_CTRL_buck2_dly_pd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck3_rampdown_ctr : 3;
        unsigned char reg_buck3_rampup_ctr : 3;
        unsigned char reg_buck3_ramp_en : 1;
        unsigned char buck3_vset_offset_sel : 1;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_rampdown_ctr_START (0)
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_rampdown_ctr_END (2)
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_rampup_ctr_START (3)
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_rampup_ctr_END (5)
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_ramp_en_START (6)
#define SUB_PMIC_BUCK3_RAMP_CTRL_reg_buck3_ramp_en_END (6)
#define SUB_PMIC_BUCK3_RAMP_CTRL_buck3_vset_offset_sel_START (7)
#define SUB_PMIC_BUCK3_RAMP_CTRL_buck3_vset_offset_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck3_vset : 8;
    } reg;
} SUB_PMIC_BUCK3_VSET_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK3_VSET_CTRL_reg_buck3_vset_START (0)
#define SUB_PMIC_BUCK3_VSET_CTRL_reg_buck3_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_rampup_chg_vset : 3;
        unsigned char buck3_rampup_chg_rate : 2;
        unsigned char buck3_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_rampup_chg_vset_START (0)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_rampup_chg_vset_END (2)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_rampup_chg_rate_START (3)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_rampup_chg_rate_END (4)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_ru_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL0_buck3_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_rampdown_chg_vset : 3;
        unsigned char buck3_rampdown_chg_rate : 2;
        unsigned char buck3_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rampdown_chg_vset_START (0)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rampdown_chg_vset_END (2)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rampdown_chg_rate_START (3)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rampdown_chg_rate_END (4)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rd_nochg_rate_sel_START (5)
#define SUB_PMIC_BUCK3_RAMP_CHG_CTRL1_buck3_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_dly_ru_off_cfg : 3;
        unsigned char buck3_dly_ru_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK3_RAMPUP_STATE_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMPUP_STATE_buck3_dly_ru_off_cfg_START (0)
#define SUB_PMIC_BUCK3_RAMPUP_STATE_buck3_dly_ru_off_cfg_END (2)
#define SUB_PMIC_BUCK3_RAMPUP_STATE_buck3_dly_ru_on_cfg_START (3)
#define SUB_PMIC_BUCK3_RAMPUP_STATE_buck3_dly_ru_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_dly_rd_off_cfg : 3;
        unsigned char buck3_dly_rd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK3_RAMPDOWN_STATE_UNION;
#endif
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_buck3_dly_rd_off_cfg_START (0)
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_buck3_dly_rd_off_cfg_END (2)
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_buck3_dly_rd_on_cfg_START (3)
#define SUB_PMIC_BUCK3_RAMPDOWN_STATE_buck3_dly_rd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_dly_pd_off_cfg : 3;
        unsigned char buck3_dly_pd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_BUCK3_PULL_DOWN_CTRL_UNION;
#endif
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_buck3_dly_pd_off_cfg_START (0)
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_buck3_dly_pd_off_cfg_END (2)
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_buck3_dly_pd_on_cfg_START (3)
#define SUB_PMIC_BUCK3_PULL_DOWN_CTRL_buck3_dly_pd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_vset_status : 8;
    } reg;
} SUB_PMIC_BUCK01_VSET_STATUS_UNION;
#endif
#define SUB_PMIC_BUCK01_VSET_STATUS_buck01_vset_status_START (0)
#define SUB_PMIC_BUCK01_VSET_STATUS_buck01_vset_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_vset_status : 8;
    } reg;
} SUB_PMIC_BUCK2_VSET_STATUS_UNION;
#endif
#define SUB_PMIC_BUCK2_VSET_STATUS_buck2_vset_status_START (0)
#define SUB_PMIC_BUCK2_VSET_STATUS_buck2_vset_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_vset_status : 8;
    } reg;
} SUB_PMIC_BUCK3_VSET_STATUS_UNION;
#endif
#define SUB_PMIC_BUCK3_VSET_STATUS_buck3_vset_status_START (0)
#define SUB_PMIC_BUCK3_VSET_STATUS_buck3_vset_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_ocp_sel : 1;
        unsigned char buck23_ocp_sel : 1;
        unsigned char buck01_scp_sel : 1;
        unsigned char buck23_scp_sel : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_BUCK0123_CTRL0_UNION;
#endif
#define SUB_PMIC_BUCK0123_CTRL0_buck01_ocp_sel_START (0)
#define SUB_PMIC_BUCK0123_CTRL0_buck01_ocp_sel_END (0)
#define SUB_PMIC_BUCK0123_CTRL0_buck23_ocp_sel_START (1)
#define SUB_PMIC_BUCK0123_CTRL0_buck23_ocp_sel_END (1)
#define SUB_PMIC_BUCK0123_CTRL0_buck01_scp_sel_START (2)
#define SUB_PMIC_BUCK0123_CTRL0_buck01_scp_sel_END (2)
#define SUB_PMIC_BUCK0123_CTRL0_buck23_scp_sel_START (3)
#define SUB_PMIC_BUCK0123_CTRL0_buck23_scp_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char scp_buck_deb_sel : 2;
        unsigned char ocp_buck_deb_sel : 2;
        unsigned char en_buck_scp_deb : 1;
        unsigned char en_buck_ocp_deb : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_OCP_DEB_CTRL0_UNION;
#endif
#define SUB_PMIC_OCP_DEB_CTRL0_scp_buck_deb_sel_START (0)
#define SUB_PMIC_OCP_DEB_CTRL0_scp_buck_deb_sel_END (1)
#define SUB_PMIC_OCP_DEB_CTRL0_ocp_buck_deb_sel_START (2)
#define SUB_PMIC_OCP_DEB_CTRL0_ocp_buck_deb_sel_END (3)
#define SUB_PMIC_OCP_DEB_CTRL0_en_buck_scp_deb_START (4)
#define SUB_PMIC_OCP_DEB_CTRL0_en_buck_scp_deb_END (4)
#define SUB_PMIC_OCP_DEB_CTRL0_en_buck_ocp_deb_START (5)
#define SUB_PMIC_OCP_DEB_CTRL0_en_buck_ocp_deb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otmp140_deb_sel : 2;
        unsigned char ovp_buck_deb_sel : 2;
        unsigned char en_buck_ovp_deb : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_OTMP140_OVP_DEB_CTRL_UNION;
#endif
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_otmp140_deb_sel_START (0)
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_otmp140_deb_sel_END (1)
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_ovp_buck_deb_sel_START (2)
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_ovp_buck_deb_sel_END (3)
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_en_buck_ovp_deb_START (4)
#define SUB_PMIC_OTMP140_OVP_DEB_CTRL_en_buck_ovp_deb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck01_state_mask : 1;
        unsigned char reg_buck2_state_mask : 1;
        unsigned char reg_buck3_state_mask : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_BUCK_STATE_MASK_UNION;
#endif
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck01_state_mask_START (0)
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck01_state_mask_END (0)
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck2_state_mask_START (1)
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck2_state_mask_END (1)
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck3_state_mask_START (2)
#define SUB_PMIC_BUCK_STATE_MASK_reg_buck3_state_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otmp140_pd_mask : 1;
        unsigned char vsys_ov_pd_mask : 1;
        unsigned char vsys_pwroff_pd_mask : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_SYS_CTRL_UNION;
#endif
#define SUB_PMIC_SYS_CTRL_otmp140_pd_mask_START (0)
#define SUB_PMIC_SYS_CTRL_otmp140_pd_mask_END (0)
#define SUB_PMIC_SYS_CTRL_vsys_ov_pd_mask_START (1)
#define SUB_PMIC_SYS_CTRL_vsys_ov_pd_mask_END (1)
#define SUB_PMIC_SYS_CTRL_vsys_pwroff_pd_mask_START (2)
#define SUB_PMIC_SYS_CTRL_vsys_pwroff_pd_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dig_debug_lock : 8;
    } reg;
} SUB_PMIC_DIG_DEBUG_0_UNION;
#endif
#define SUB_PMIC_DIG_DEBUG_0_dig_debug_lock_START (0)
#define SUB_PMIC_DIG_DEBUG_0_dig_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dig_debug_cfg : 6;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_DIG_DEBUG_1_UNION;
#endif
#define SUB_PMIC_DIG_DEBUG_1_dig_debug_cfg_START (0)
#define SUB_PMIC_DIG_DEBUG_1_dig_debug_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_data_ds_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SUB_PMIC_DIG_IO_DS_CFG_UNION;
#endif
#define SUB_PMIC_DIG_IO_DS_CFG_spmi_data_ds_sel_START (0)
#define SUB_PMIC_DIG_IO_DS_CFG_spmi_data_ds_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_0 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_0_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_0_spmi_debug_info_0_START (0)
#define SUB_PMIC_SPMI_DEBUG_0_spmi_debug_info_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_1 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_1_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_1_spmi_debug_info_1_START (0)
#define SUB_PMIC_SPMI_DEBUG_1_spmi_debug_info_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_2 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_2_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_2_spmi_debug_info_2_START (0)
#define SUB_PMIC_SPMI_DEBUG_2_spmi_debug_info_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_3 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_3_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_3_spmi_debug_info_3_START (0)
#define SUB_PMIC_SPMI_DEBUG_3_spmi_debug_info_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_4 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_4_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_4_spmi_debug_info_4_START (0)
#define SUB_PMIC_SPMI_DEBUG_4_spmi_debug_info_4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_5 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_5_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_5_spmi_debug_info_5_START (0)
#define SUB_PMIC_SPMI_DEBUG_5_spmi_debug_info_5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_6 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_6_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_6_spmi_debug_info_6_START (0)
#define SUB_PMIC_SPMI_DEBUG_6_spmi_debug_info_6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug_info_7 : 8;
    } reg;
} SUB_PMIC_SPMI_DEBUG_7_UNION;
#endif
#define SUB_PMIC_SPMI_DEBUG_7_spmi_debug_info_7_START (0)
#define SUB_PMIC_SPMI_DEBUG_7_spmi_debug_info_7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char thsd_otmp140_d540ur_mk : 1;
        unsigned char thsd_otmp125_d1mr_mk : 1;
        unsigned char vsys_pwroff_d20nr_mk : 1;
        unsigned char vsys_ov_d200ur_mk : 1;
        unsigned char vsys_pwron_d60ur_mk : 1;
        unsigned char ocp_scp_ovp_r_mk : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_IRQ1_MASK_UNION;
#endif
#define SUB_PMIC_IRQ1_MASK_thsd_otmp140_d540ur_mk_START (0)
#define SUB_PMIC_IRQ1_MASK_thsd_otmp140_d540ur_mk_END (0)
#define SUB_PMIC_IRQ1_MASK_thsd_otmp125_d1mr_mk_START (1)
#define SUB_PMIC_IRQ1_MASK_thsd_otmp125_d1mr_mk_END (1)
#define SUB_PMIC_IRQ1_MASK_vsys_pwroff_d20nr_mk_START (2)
#define SUB_PMIC_IRQ1_MASK_vsys_pwroff_d20nr_mk_END (2)
#define SUB_PMIC_IRQ1_MASK_vsys_ov_d200ur_mk_START (3)
#define SUB_PMIC_IRQ1_MASK_vsys_ov_d200ur_mk_END (3)
#define SUB_PMIC_IRQ1_MASK_vsys_pwron_d60ur_mk_START (4)
#define SUB_PMIC_IRQ1_MASK_vsys_pwron_d60ur_mk_END (4)
#define SUB_PMIC_IRQ1_MASK_ocp_scp_ovp_r_mk_START (5)
#define SUB_PMIC_IRQ1_MASK_ocp_scp_ovp_r_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ocp_mk : 1;
        unsigned char buck1_ocp_mk : 1;
        unsigned char buck2_ocp_mk : 1;
        unsigned char buck3_ocp_mk : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_OCP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_MASK_buck0_ocp_mk_START (0)
#define SUB_PMIC_OCP_IRQ_MASK_buck0_ocp_mk_END (0)
#define SUB_PMIC_OCP_IRQ_MASK_buck1_ocp_mk_START (1)
#define SUB_PMIC_OCP_IRQ_MASK_buck1_ocp_mk_END (1)
#define SUB_PMIC_OCP_IRQ_MASK_buck2_ocp_mk_START (2)
#define SUB_PMIC_OCP_IRQ_MASK_buck2_ocp_mk_END (2)
#define SUB_PMIC_OCP_IRQ_MASK_buck3_ocp_mk_START (3)
#define SUB_PMIC_OCP_IRQ_MASK_buck3_ocp_mk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_scp_mk : 1;
        unsigned char buck1_scp_mk : 1;
        unsigned char buck2_scp_mk : 1;
        unsigned char buck3_scp_mk : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_SCP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_SCP_IRQ_MASK_buck0_scp_mk_START (0)
#define SUB_PMIC_SCP_IRQ_MASK_buck0_scp_mk_END (0)
#define SUB_PMIC_SCP_IRQ_MASK_buck1_scp_mk_START (1)
#define SUB_PMIC_SCP_IRQ_MASK_buck1_scp_mk_END (1)
#define SUB_PMIC_SCP_IRQ_MASK_buck2_scp_mk_START (2)
#define SUB_PMIC_SCP_IRQ_MASK_buck2_scp_mk_END (2)
#define SUB_PMIC_SCP_IRQ_MASK_buck3_scp_mk_START (3)
#define SUB_PMIC_SCP_IRQ_MASK_buck3_scp_mk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_ovp_mk : 1;
        unsigned char buck2_ovp_mk : 1;
        unsigned char buck3_ovp_mk : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_OVP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_OVP_IRQ_MASK_buck01_ovp_mk_START (0)
#define SUB_PMIC_OVP_IRQ_MASK_buck01_ovp_mk_END (0)
#define SUB_PMIC_OVP_IRQ_MASK_buck2_ovp_mk_START (1)
#define SUB_PMIC_OVP_IRQ_MASK_buck2_ovp_mk_END (1)
#define SUB_PMIC_OVP_IRQ_MASK_buck3_ovp_mk_START (2)
#define SUB_PMIC_OVP_IRQ_MASK_buck3_ovp_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b01_ramp_irq_mk : 1;
        unsigned char b2_ramp_irq_mk : 1;
        unsigned char b3_ramp_irq_mk : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_RAMP_IRQ_MASK_UNION;
#endif
#define SUB_PMIC_RAMP_IRQ_MASK_b01_ramp_irq_mk_START (0)
#define SUB_PMIC_RAMP_IRQ_MASK_b01_ramp_irq_mk_END (0)
#define SUB_PMIC_RAMP_IRQ_MASK_b2_ramp_irq_mk_START (1)
#define SUB_PMIC_RAMP_IRQ_MASK_b2_ramp_irq_mk_END (1)
#define SUB_PMIC_RAMP_IRQ_MASK_b3_ramp_irq_mk_START (2)
#define SUB_PMIC_RAMP_IRQ_MASK_b3_ramp_irq_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_thsd_otmp140_d540ur : 1;
        unsigned char irq_thsd_otmp125_d1mr : 1;
        unsigned char irq_vsys_pwroff_abs_d20nr : 1;
        unsigned char irq_vsys_ov_d200ur : 1;
        unsigned char irq_vsys_pwron_d60ur : 1;
        unsigned char ocp_scp_ovp_r : 1;
        unsigned char reserved : 2;
    } reg;
} SUB_PMIC_IRQ1_UNION;
#endif
#define SUB_PMIC_IRQ1_irq_thsd_otmp140_d540ur_START (0)
#define SUB_PMIC_IRQ1_irq_thsd_otmp140_d540ur_END (0)
#define SUB_PMIC_IRQ1_irq_thsd_otmp125_d1mr_START (1)
#define SUB_PMIC_IRQ1_irq_thsd_otmp125_d1mr_END (1)
#define SUB_PMIC_IRQ1_irq_vsys_pwroff_abs_d20nr_START (2)
#define SUB_PMIC_IRQ1_irq_vsys_pwroff_abs_d20nr_END (2)
#define SUB_PMIC_IRQ1_irq_vsys_ov_d200ur_START (3)
#define SUB_PMIC_IRQ1_irq_vsys_ov_d200ur_END (3)
#define SUB_PMIC_IRQ1_irq_vsys_pwron_d60ur_START (4)
#define SUB_PMIC_IRQ1_irq_vsys_pwron_d60ur_END (4)
#define SUB_PMIC_IRQ1_ocp_scp_ovp_r_START (5)
#define SUB_PMIC_IRQ1_ocp_scp_ovp_r_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ocp : 1;
        unsigned char buck1_ocp : 1;
        unsigned char buck2_ocp : 1;
        unsigned char buck3_ocp : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_OCP_IRQ_UNION;
#endif
#define SUB_PMIC_OCP_IRQ_buck0_ocp_START (0)
#define SUB_PMIC_OCP_IRQ_buck0_ocp_END (0)
#define SUB_PMIC_OCP_IRQ_buck1_ocp_START (1)
#define SUB_PMIC_OCP_IRQ_buck1_ocp_END (1)
#define SUB_PMIC_OCP_IRQ_buck2_ocp_START (2)
#define SUB_PMIC_OCP_IRQ_buck2_ocp_END (2)
#define SUB_PMIC_OCP_IRQ_buck3_ocp_START (3)
#define SUB_PMIC_OCP_IRQ_buck3_ocp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_scp : 1;
        unsigned char buck1_scp : 1;
        unsigned char buck2_scp : 1;
        unsigned char buck3_scp : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_SCP_IRQ_UNION;
#endif
#define SUB_PMIC_SCP_IRQ_buck0_scp_START (0)
#define SUB_PMIC_SCP_IRQ_buck0_scp_END (0)
#define SUB_PMIC_SCP_IRQ_buck1_scp_START (1)
#define SUB_PMIC_SCP_IRQ_buck1_scp_END (1)
#define SUB_PMIC_SCP_IRQ_buck2_scp_START (2)
#define SUB_PMIC_SCP_IRQ_buck2_scp_END (2)
#define SUB_PMIC_SCP_IRQ_buck3_scp_START (3)
#define SUB_PMIC_SCP_IRQ_buck3_scp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck01_ovp : 1;
        unsigned char buck2_ovp : 1;
        unsigned char buck3_ovp : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_OVP_IRQ_UNION;
#endif
#define SUB_PMIC_OVP_IRQ_buck01_ovp_START (0)
#define SUB_PMIC_OVP_IRQ_buck01_ovp_END (0)
#define SUB_PMIC_OVP_IRQ_buck2_ovp_START (1)
#define SUB_PMIC_OVP_IRQ_buck2_ovp_END (1)
#define SUB_PMIC_OVP_IRQ_buck3_ovp_START (2)
#define SUB_PMIC_OVP_IRQ_buck3_ovp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char b01_ramp_irq : 1;
        unsigned char b2_ramp_irq : 1;
        unsigned char b3_ramp_irq : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_RAMP_IRQ_UNION;
#endif
#define SUB_PMIC_RAMP_IRQ_b01_ramp_irq_START (0)
#define SUB_PMIC_RAMP_IRQ_b01_ramp_irq_END (0)
#define SUB_PMIC_RAMP_IRQ_b2_ramp_irq_START (1)
#define SUB_PMIC_RAMP_IRQ_b2_ramp_irq_END (1)
#define SUB_PMIC_RAMP_IRQ_b3_ramp_irq_START (2)
#define SUB_PMIC_RAMP_IRQ_b3_ramp_irq_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_thsd_otmp140_d540ur : 1;
        unsigned char np_thsd_otmp125_d1mr : 1;
        unsigned char np_vsys_pwroff_abs_d20nr : 1;
        unsigned char np_vsys_ov_d200ur : 1;
        unsigned char np_vsys_pwron_d60ur : 1;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_NP_IRQ1_RECORD_UNION;
#endif
#define SUB_PMIC_NP_IRQ1_RECORD_np_thsd_otmp140_d540ur_START (0)
#define SUB_PMIC_NP_IRQ1_RECORD_np_thsd_otmp140_d540ur_END (0)
#define SUB_PMIC_NP_IRQ1_RECORD_np_thsd_otmp125_d1mr_START (1)
#define SUB_PMIC_NP_IRQ1_RECORD_np_thsd_otmp125_d1mr_END (1)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_pwroff_abs_d20nr_START (2)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_pwroff_abs_d20nr_END (2)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_ov_d200ur_START (3)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_ov_d200ur_END (3)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_pwron_d60ur_START (4)
#define SUB_PMIC_NP_IRQ1_RECORD_np_vsys_pwron_d60ur_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_buck0_ocp : 1;
        unsigned char np_buck1_ocp : 1;
        unsigned char np_buck2_ocp : 1;
        unsigned char np_buck3_ocp : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_NP_OCP_RECORD_UNION;
#endif
#define SUB_PMIC_NP_OCP_RECORD_np_buck0_ocp_START (0)
#define SUB_PMIC_NP_OCP_RECORD_np_buck0_ocp_END (0)
#define SUB_PMIC_NP_OCP_RECORD_np_buck1_ocp_START (1)
#define SUB_PMIC_NP_OCP_RECORD_np_buck1_ocp_END (1)
#define SUB_PMIC_NP_OCP_RECORD_np_buck2_ocp_START (2)
#define SUB_PMIC_NP_OCP_RECORD_np_buck2_ocp_END (2)
#define SUB_PMIC_NP_OCP_RECORD_np_buck3_ocp_START (3)
#define SUB_PMIC_NP_OCP_RECORD_np_buck3_ocp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_buck0_scp : 1;
        unsigned char np_buck1_scp : 1;
        unsigned char np_buck2_scp : 1;
        unsigned char np_buck3_scp : 1;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_NP_SCP_RECORD_UNION;
#endif
#define SUB_PMIC_NP_SCP_RECORD_np_buck0_scp_START (0)
#define SUB_PMIC_NP_SCP_RECORD_np_buck0_scp_END (0)
#define SUB_PMIC_NP_SCP_RECORD_np_buck1_scp_START (1)
#define SUB_PMIC_NP_SCP_RECORD_np_buck1_scp_END (1)
#define SUB_PMIC_NP_SCP_RECORD_np_buck2_scp_START (2)
#define SUB_PMIC_NP_SCP_RECORD_np_buck2_scp_END (2)
#define SUB_PMIC_NP_SCP_RECORD_np_buck3_scp_START (3)
#define SUB_PMIC_NP_SCP_RECORD_np_buck3_scp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_buck01_ovp : 1;
        unsigned char np_buck2_ovp : 1;
        unsigned char np_buck3_ovp : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_NP_OVP_RECORD_UNION;
#endif
#define SUB_PMIC_NP_OVP_RECORD_np_buck01_ovp_START (0)
#define SUB_PMIC_NP_OVP_RECORD_np_buck01_ovp_END (0)
#define SUB_PMIC_NP_OVP_RECORD_np_buck2_ovp_START (1)
#define SUB_PMIC_NP_OVP_RECORD_np_buck2_ovp_END (1)
#define SUB_PMIC_NP_OVP_RECORD_np_buck3_ovp_START (2)
#define SUB_PMIC_NP_OVP_RECORD_np_buck3_ovp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_b0_ramp_irq : 1;
        unsigned char np_b2_ramp_irq : 1;
        unsigned char np_b3_ramp_irq : 1;
        unsigned char reserved : 5;
    } reg;
} SUB_PMIC_RAMP_IRQ_RECORD_UNION;
#endif
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b0_ramp_irq_START (0)
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b0_ramp_irq_END (0)
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b2_ramp_irq_START (1)
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b2_ramp_irq_END (1)
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b3_ramp_irq_START (2)
#define SUB_PMIC_RAMP_IRQ_RECORD_np_b3_ramp_irq_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_vsys_pwron_set : 3;
        unsigned char np_vsys_pwroff_abs_set : 2;
        unsigned char reserved : 3;
    } reg;
} SUB_PMIC_VSYS_SET_UNION;
#endif
#define SUB_PMIC_VSYS_SET_np_vsys_pwron_set_START (0)
#define SUB_PMIC_VSYS_SET_np_vsys_pwron_set_END (2)
#define SUB_PMIC_VSYS_SET_np_vsys_pwroff_abs_set_START (3)
#define SUB_PMIC_VSYS_SET_np_vsys_pwroff_abs_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_pmu1_en_deb_sel : 2;
        unsigned char np_otmp125_deb_sel : 2;
        unsigned char reserved : 4;
    } reg;
} SUB_PMIC_NP_DEB_CTRL_UNION;
#endif
#define SUB_PMIC_NP_DEB_CTRL_np_pmu1_en_deb_sel_START (0)
#define SUB_PMIC_NP_DEB_CTRL_np_pmu1_en_deb_sel_END (1)
#define SUB_PMIC_NP_DEB_CTRL_np_otmp125_deb_sel_START (2)
#define SUB_PMIC_NP_DEB_CTRL_np_otmp125_deb_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_rst_cfg : 8;
    } reg;
} SUB_PMIC_SOFT_RST_CTRL_UNION;
#endif
#define SUB_PMIC_SOFT_RST_CTRL_soft_rst_cfg_START (0)
#define SUB_PMIC_SOFT_RST_CTRL_soft_rst_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_7_0 : 8;
    } reg;
} SUB_PMIC_OTP_7_0_UNION;
#endif
#define SUB_PMIC_OTP_7_0_np_otp_pdob_7_0_START (0)
#define SUB_PMIC_OTP_7_0_np_otp_pdob_7_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_15_8 : 8;
    } reg;
} SUB_PMIC_OTP_15_8_UNION;
#endif
#define SUB_PMIC_OTP_15_8_np_otp_pdob_15_8_START (0)
#define SUB_PMIC_OTP_15_8_np_otp_pdob_15_8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_23_16 : 8;
    } reg;
} SUB_PMIC_OTP_23_16_UNION;
#endif
#define SUB_PMIC_OTP_23_16_np_otp_pdob_23_16_START (0)
#define SUB_PMIC_OTP_23_16_np_otp_pdob_23_16_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_31_24 : 8;
    } reg;
} SUB_PMIC_OTP_31_24_UNION;
#endif
#define SUB_PMIC_OTP_31_24_np_otp_pdob_31_24_START (0)
#define SUB_PMIC_OTP_31_24_np_otp_pdob_31_24_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_39_32 : 8;
    } reg;
} SUB_PMIC_OTP_39_32_UNION;
#endif
#define SUB_PMIC_OTP_39_32_np_otp_pdob_39_32_START (0)
#define SUB_PMIC_OTP_39_32_np_otp_pdob_39_32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_47_40 : 8;
    } reg;
} SUB_PMIC_OTP_47_40_UNION;
#endif
#define SUB_PMIC_OTP_47_40_np_otp_pdob_47_40_START (0)
#define SUB_PMIC_OTP_47_40_np_otp_pdob_47_40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_55_48 : 8;
    } reg;
} SUB_PMIC_OTP_55_48_UNION;
#endif
#define SUB_PMIC_OTP_55_48_np_otp_pdob_55_48_START (0)
#define SUB_PMIC_OTP_55_48_np_otp_pdob_55_48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_63_56 : 8;
    } reg;
} SUB_PMIC_OTP_63_56_UNION;
#endif
#define SUB_PMIC_OTP_63_56_np_otp_pdob_63_56_START (0)
#define SUB_PMIC_OTP_63_56_np_otp_pdob_63_56_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_71_64 : 8;
    } reg;
} SUB_PMIC_OTP_71_64_UNION;
#endif
#define SUB_PMIC_OTP_71_64_np_otp_pdob_71_64_START (0)
#define SUB_PMIC_OTP_71_64_np_otp_pdob_71_64_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_79_72 : 8;
    } reg;
} SUB_PMIC_OTP_79_72_UNION;
#endif
#define SUB_PMIC_OTP_79_72_np_otp_pdob_79_72_START (0)
#define SUB_PMIC_OTP_79_72_np_otp_pdob_79_72_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_87_80 : 8;
    } reg;
} SUB_PMIC_OTP_87_80_UNION;
#endif
#define SUB_PMIC_OTP_87_80_np_otp_pdob_87_80_START (0)
#define SUB_PMIC_OTP_87_80_np_otp_pdob_87_80_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_95_88 : 8;
    } reg;
} SUB_PMIC_OTP_95_88_UNION;
#endif
#define SUB_PMIC_OTP_95_88_np_otp_pdob_95_88_START (0)
#define SUB_PMIC_OTP_95_88_np_otp_pdob_95_88_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_103_96 : 8;
    } reg;
} SUB_PMIC_OTP_103_96_UNION;
#endif
#define SUB_PMIC_OTP_103_96_np_otp_pdob_103_96_START (0)
#define SUB_PMIC_OTP_103_96_np_otp_pdob_103_96_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_111_104 : 8;
    } reg;
} SUB_PMIC_OTP_111_104_UNION;
#endif
#define SUB_PMIC_OTP_111_104_np_otp_pdob_111_104_START (0)
#define SUB_PMIC_OTP_111_104_np_otp_pdob_111_104_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_119_112 : 8;
    } reg;
} SUB_PMIC_OTP_119_112_UNION;
#endif
#define SUB_PMIC_OTP_119_112_np_otp_pdob_119_112_START (0)
#define SUB_PMIC_OTP_119_112_np_otp_pdob_119_112_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_127_120 : 8;
    } reg;
} SUB_PMIC_OTP_127_120_UNION;
#endif
#define SUB_PMIC_OTP_127_120_np_otp_pdob_127_120_START (0)
#define SUB_PMIC_OTP_127_120_np_otp_pdob_127_120_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_135_128 : 8;
    } reg;
} SUB_PMIC_OTP_135_128_UNION;
#endif
#define SUB_PMIC_OTP_135_128_np_otp_pdob_135_128_START (0)
#define SUB_PMIC_OTP_135_128_np_otp_pdob_135_128_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_143_136 : 8;
    } reg;
} SUB_PMIC_OTP_143_136_UNION;
#endif
#define SUB_PMIC_OTP_143_136_np_otp_pdob_143_136_START (0)
#define SUB_PMIC_OTP_143_136_np_otp_pdob_143_136_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_151_144 : 8;
    } reg;
} SUB_PMIC_OTP_151_144_UNION;
#endif
#define SUB_PMIC_OTP_151_144_np_otp_pdob_151_144_START (0)
#define SUB_PMIC_OTP_151_144_np_otp_pdob_151_144_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_159_152 : 8;
    } reg;
} SUB_PMIC_OTP_159_152_UNION;
#endif
#define SUB_PMIC_OTP_159_152_np_otp_pdob_159_152_START (0)
#define SUB_PMIC_OTP_159_152_np_otp_pdob_159_152_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_167_160 : 8;
    } reg;
} SUB_PMIC_OTP_167_160_UNION;
#endif
#define SUB_PMIC_OTP_167_160_np_otp_pdob_167_160_START (0)
#define SUB_PMIC_OTP_167_160_np_otp_pdob_167_160_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_175_168 : 8;
    } reg;
} SUB_PMIC_OTP_175_168_UNION;
#endif
#define SUB_PMIC_OTP_175_168_np_otp_pdob_175_168_START (0)
#define SUB_PMIC_OTP_175_168_np_otp_pdob_175_168_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_183_176 : 8;
    } reg;
} SUB_PMIC_OTP_183_176_UNION;
#endif
#define SUB_PMIC_OTP_183_176_np_otp_pdob_183_176_START (0)
#define SUB_PMIC_OTP_183_176_np_otp_pdob_183_176_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_191_184 : 8;
    } reg;
} SUB_PMIC_OTP_191_184_UNION;
#endif
#define SUB_PMIC_OTP_191_184_np_otp_pdob_191_184_START (0)
#define SUB_PMIC_OTP_191_184_np_otp_pdob_191_184_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_199_192 : 8;
    } reg;
} SUB_PMIC_OTP_199_192_UNION;
#endif
#define SUB_PMIC_OTP_199_192_np_otp_pdob_199_192_START (0)
#define SUB_PMIC_OTP_199_192_np_otp_pdob_199_192_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_207_200 : 8;
    } reg;
} SUB_PMIC_OTP_207_200_UNION;
#endif
#define SUB_PMIC_OTP_207_200_np_otp_pdob_207_200_START (0)
#define SUB_PMIC_OTP_207_200_np_otp_pdob_207_200_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_215_208 : 8;
    } reg;
} SUB_PMIC_OTP_215_208_UNION;
#endif
#define SUB_PMIC_OTP_215_208_np_otp_pdob_215_208_START (0)
#define SUB_PMIC_OTP_215_208_np_otp_pdob_215_208_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_223_216 : 8;
    } reg;
} SUB_PMIC_OTP_223_216_UNION;
#endif
#define SUB_PMIC_OTP_223_216_np_otp_pdob_223_216_START (0)
#define SUB_PMIC_OTP_223_216_np_otp_pdob_223_216_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_231_224 : 8;
    } reg;
} SUB_PMIC_OTP_231_224_UNION;
#endif
#define SUB_PMIC_OTP_231_224_np_otp_pdob_231_224_START (0)
#define SUB_PMIC_OTP_231_224_np_otp_pdob_231_224_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_239_232 : 8;
    } reg;
} SUB_PMIC_OTP_239_232_UNION;
#endif
#define SUB_PMIC_OTP_239_232_np_otp_pdob_239_232_START (0)
#define SUB_PMIC_OTP_239_232_np_otp_pdob_239_232_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_247_240 : 8;
    } reg;
} SUB_PMIC_OTP_247_240_UNION;
#endif
#define SUB_PMIC_OTP_247_240_np_otp_pdob_247_240_START (0)
#define SUB_PMIC_OTP_247_240_np_otp_pdob_247_240_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob_255_248 : 8;
    } reg;
} SUB_PMIC_OTP_255_248_UNION;
#endif
#define SUB_PMIC_OTP_255_248_np_otp_pdob_255_248_START (0)
#define SUB_PMIC_OTP_255_248_np_otp_pdob_255_248_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
