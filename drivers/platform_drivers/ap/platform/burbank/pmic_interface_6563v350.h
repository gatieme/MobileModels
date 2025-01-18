#ifndef __PMIC_INTERFACE_6563V350_H__
#define __PMIC_INTERFACE_6563V350_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x000UL))
#define COMMON_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x001UL))
#define COMMON_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x002UL))
#define COMMON_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x003UL))
#define COMMON_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x004UL))
#define COMMON_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x005UL))
#define COMMON_PMIC_LOCK_ADDR(base) ((base) + (0x006UL))
#define COMMON_PMIC_SYS_STATUS_ADDR(base) ((base) + (0x008UL))
#define COMMON_PMIC_OCP_STATUS0_ADDR(base) ((base) + (0x009UL))
#define COMMON_PMIC_OCP_STATUS1_ADDR(base) ((base) + (0x00AUL))
#define COMMON_PMIC_SCP_STATUS0_ADDR(base) ((base) + (0x00BUL))
#define COMMON_PMIC_RAMP_ST0_ADDR(base) ((base) + (0x010UL))
#define COMMON_PMIC_POWER_STATUS0_ADDR(base) ((base) + (0x015UL))
#define COMMON_PMIC_POWER_STATUS1_ADDR(base) ((base) + (0x016UL))
#define COMMON_PMIC_SEL_STATUS_ADDR(base) ((base) + (0x017UL))
#define COMMON_PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x01EUL))
#define COMMON_PMIC_BUCK0_ONOFF_ADDR(base) ((base) + (0x01FUL))
#define COMMON_PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x020UL))
#define COMMON_PMIC_BUCK1_ONOFF_ADDR(base) ((base) + (0x021UL))
#define COMMON_PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x022UL))
#define COMMON_PMIC_BUCK2_ONOFF_ADDR(base) ((base) + (0x023UL))
#define COMMON_PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x024UL))
#define COMMON_PMIC_BUCK3_ONOFF_ADDR(base) ((base) + (0x025UL))
#define COMMON_PMIC_LDO1_VSET_ADDR(base) ((base) + (0x026UL))
#define COMMON_PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x027UL))
#define COMMON_PMIC_LDO2_VSET_ADDR(base) ((base) + (0x028UL))
#define COMMON_PMIC_LDO2_ONOFF_ADDR(base) ((base) + (0x029UL))
#define COMMON_PMIC_LDO3_VSET_ADDR(base) ((base) + (0x02AUL))
#define COMMON_PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x02BUL))
#define COMMON_PMIC_LDO4_VSET_ADDR(base) ((base) + (0x02CUL))
#define COMMON_PMIC_LDO4_ONOFF_ADDR(base) ((base) + (0x02DUL))
#define COMMON_PMIC_LDO5_VSET_ADDR(base) ((base) + (0x02EUL))
#define COMMON_PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x02FUL))
#define COMMON_PMIC_LDO6_VSET_ADDR(base) ((base) + (0x030UL))
#define COMMON_PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x031UL))
#define COMMON_PMIC_LDO7_VSET_ADDR(base) ((base) + (0x032UL))
#define COMMON_PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x033UL))
#define COMMON_PMIC_LDO8_VSET_ADDR(base) ((base) + (0x034UL))
#define COMMON_PMIC_LDO8_ONOFF_ADDR(base) ((base) + (0x035UL))
#define COMMON_PMIC_PMUH_VSET_ADDR(base) ((base) + (0x036UL))
#define COMMON_PMIC_PMUD_VSET_ADDR(base) ((base) + (0x037UL))
#define COMMON_PMIC_PWR_ECO_ONOFF0_ADDR(base) ((base) + (0x038UL))
#define COMMON_PMIC_PWR_ECO_ONOFF1_ADDR(base) ((base) + (0x039UL))
#define COMMON_PMIC_BG_THSD_EN_ADDR(base) ((base) + (0x03DUL))
#define COMMON_PMIC_PMUH_LOCK_ADDR(base) ((base) + (0x03EUL))
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x040UL))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x041UL))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ADDR(base) ((base) + (0x042UL))
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_ADDR(base) ((base) + (0x043UL))
#define COMMON_PMIC_OCP_DEB_CTRL_ADDR(base) ((base) + (0x04BUL))
#define COMMON_PMIC_SCP_DEB_CTRL_ADDR(base) ((base) + (0x04CUL))
#define COMMON_PMIC_OTMP_DEB_CTRL_ADDR(base) ((base) + (0x04DUL))
#define COMMON_PMIC_RAMP_CLK_EN_ADDR(base) ((base) + (0x05FUL))
#define COMMON_PMIC_RAMP_GT_DEBUG_ADDR(base) ((base) + (0x060UL))
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_ADDR(base) ((base) + (0x068UL))
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_ADDR(base) ((base) + (0x069UL))
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_ADDR(base) ((base) + (0x06AUL))
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_ADDR(base) ((base) + (0x06BUL))
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_ADDR(base) ((base) + (0x06CUL))
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_ADDR(base) ((base) + (0x06DUL))
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_ADDR(base) ((base) + (0x06EUL))
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_ADDR(base) ((base) + (0x06FUL))
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_ADDR(base) ((base) + (0x070UL))
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_ADDR(base) ((base) + (0x071UL))
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_ADDR(base) ((base) + (0x072UL))
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_ADDR(base) ((base) + (0x073UL))
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_ADDR(base) ((base) + (0x074UL))
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_ADDR(base) ((base) + (0x075UL))
#define COMMON_PMIC_EFUSE_DATA_ADDR(base) ((base) + (0x083UL))
#define COMMON_PMIC_EFUSE_CLK_GT_EN_ADDR(base) ((base) + (0x084UL))
#define COMMON_PMIC_EFUSE_TRIM_SEL_ADDR(base) ((base) + (0x085UL))
#define COMMON_PMIC_EFUSE_CFG_0_ADDR(base) ((base) + (0x086UL))
#define COMMON_PMIC_EFUSE_CFG_1_ADDR(base) ((base) + (0x087UL))
#define COMMON_PMIC_EFUSE_CFG_2_ADDR(base) ((base) + (0x088UL))
#define COMMON_PMIC_EFUSE_CFG_3_ADDR(base) ((base) + (0x089UL))
#define COMMON_PMIC_EFUSE_AUTO_RD_ADDR(base) ((base) + (0x08AUL))
#define COMMON_PMIC_EFUSE_RDATA_ADDR(base) ((base) + (0x08BUL))
#define COMMON_PMIC_EFUSE_13_W_ADDR(base) ((base) + (0x08CUL))
#define COMMON_PMIC_EFUSE_16_W_ADDR(base) ((base) + (0x08DUL))
#define COMMON_PMIC_EFUSE_17_W_ADDR(base) ((base) + (0x08EUL))
#define COMMON_PMIC_EFUSE_18_W_ADDR(base) ((base) + (0x08FUL))
#define COMMON_PMIC_EFUSE_19_W_ADDR(base) ((base) + (0x090UL))
#define COMMON_PMIC_EFUSE_20_W_ADDR(base) ((base) + (0x091UL))
#define COMMON_PMIC_EFUSE_21_W_ADDR(base) ((base) + (0x092UL))
#define COMMON_PMIC_EFUSE_22_W_ADDR(base) ((base) + (0x093UL))
#define COMMON_PMIC_EFUSE_23_W_ADDR(base) ((base) + (0x094UL))
#define COMMON_PMIC_EFUSE_24_W_ADDR(base) ((base) + (0x095UL))
#define COMMON_PMIC_EFUSE_25_W_ADDR(base) ((base) + (0x096UL))
#define COMMON_PMIC_EFUSE_26_W_ADDR(base) ((base) + (0x097UL))
#define COMMON_PMIC_EFUSE_27_W_ADDR(base) ((base) + (0x098UL))
#define COMMON_PMIC_EFUSE_28_W_ADDR(base) ((base) + (0x099UL))
#define COMMON_PMIC_EFUSE_29_W_ADDR(base) ((base) + (0x09AUL))
#define COMMON_PMIC_EFUSE_30_W_ADDR(base) ((base) + (0x09BUL))
#define COMMON_PMIC_EFUSE_31_W_ADDR(base) ((base) + (0x09CUL))
#define COMMON_PMIC_EFUSE_32_W_ADDR(base) ((base) + (0x09DUL))
#define COMMON_PMIC_EFUSE_33_W_ADDR(base) ((base) + (0x09EUL))
#define COMMON_PMIC_EFUSE_34_W_ADDR(base) ((base) + (0x09FUL))
#define COMMON_PMIC_EFUSE_35_W_ADDR(base) ((base) + (0x0A0UL))
#define COMMON_PMIC_EFUSE_36_W_ADDR(base) ((base) + (0x0A1UL))
#define COMMON_PMIC_EFUSE_37_W_ADDR(base) ((base) + (0x0A2UL))
#define COMMON_PMIC_EFUSE_38_W_ADDR(base) ((base) + (0x0A3UL))
#define COMMON_PMIC_EFUSE_39_W_ADDR(base) ((base) + (0x0A4UL))
#define COMMON_PMIC_EFUSE_40_W_ADDR(base) ((base) + (0x0A5UL))
#define COMMON_PMIC_EFUSE_41_W_ADDR(base) ((base) + (0x0A6UL))
#define COMMON_PMIC_EFUSE_42_W_ADDR(base) ((base) + (0x0A7UL))
#define COMMON_PMIC_EFUSE_43_W_ADDR(base) ((base) + (0x0A8UL))
#define COMMON_PMIC_EFUSE_44_W_ADDR(base) ((base) + (0x0A9UL))
#define COMMON_PMIC_EFUSE_45_W_ADDR(base) ((base) + (0x0AAUL))
#define COMMON_PMIC_EFUSE_46_W_ADDR(base) ((base) + (0x0ABUL))
#define COMMON_PMIC_EFUSE_47_W_ADDR(base) ((base) + (0x0ACUL))
#else
#define COMMON_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x000))
#define COMMON_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x001))
#define COMMON_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x002))
#define COMMON_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x003))
#define COMMON_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x004))
#define COMMON_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x005))
#define COMMON_PMIC_LOCK_ADDR(base) ((base) + (0x006))
#define COMMON_PMIC_SYS_STATUS_ADDR(base) ((base) + (0x008))
#define COMMON_PMIC_OCP_STATUS0_ADDR(base) ((base) + (0x009))
#define COMMON_PMIC_OCP_STATUS1_ADDR(base) ((base) + (0x00A))
#define COMMON_PMIC_SCP_STATUS0_ADDR(base) ((base) + (0x00B))
#define COMMON_PMIC_RAMP_ST0_ADDR(base) ((base) + (0x010))
#define COMMON_PMIC_POWER_STATUS0_ADDR(base) ((base) + (0x015))
#define COMMON_PMIC_POWER_STATUS1_ADDR(base) ((base) + (0x016))
#define COMMON_PMIC_SEL_STATUS_ADDR(base) ((base) + (0x017))
#define COMMON_PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x01E))
#define COMMON_PMIC_BUCK0_ONOFF_ADDR(base) ((base) + (0x01F))
#define COMMON_PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x020))
#define COMMON_PMIC_BUCK1_ONOFF_ADDR(base) ((base) + (0x021))
#define COMMON_PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x022))
#define COMMON_PMIC_BUCK2_ONOFF_ADDR(base) ((base) + (0x023))
#define COMMON_PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x024))
#define COMMON_PMIC_BUCK3_ONOFF_ADDR(base) ((base) + (0x025))
#define COMMON_PMIC_LDO1_VSET_ADDR(base) ((base) + (0x026))
#define COMMON_PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x027))
#define COMMON_PMIC_LDO2_VSET_ADDR(base) ((base) + (0x028))
#define COMMON_PMIC_LDO2_ONOFF_ADDR(base) ((base) + (0x029))
#define COMMON_PMIC_LDO3_VSET_ADDR(base) ((base) + (0x02A))
#define COMMON_PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x02B))
#define COMMON_PMIC_LDO4_VSET_ADDR(base) ((base) + (0x02C))
#define COMMON_PMIC_LDO4_ONOFF_ADDR(base) ((base) + (0x02D))
#define COMMON_PMIC_LDO5_VSET_ADDR(base) ((base) + (0x02E))
#define COMMON_PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x02F))
#define COMMON_PMIC_LDO6_VSET_ADDR(base) ((base) + (0x030))
#define COMMON_PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x031))
#define COMMON_PMIC_LDO7_VSET_ADDR(base) ((base) + (0x032))
#define COMMON_PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x033))
#define COMMON_PMIC_LDO8_VSET_ADDR(base) ((base) + (0x034))
#define COMMON_PMIC_LDO8_ONOFF_ADDR(base) ((base) + (0x035))
#define COMMON_PMIC_PMUH_VSET_ADDR(base) ((base) + (0x036))
#define COMMON_PMIC_PMUD_VSET_ADDR(base) ((base) + (0x037))
#define COMMON_PMIC_PWR_ECO_ONOFF0_ADDR(base) ((base) + (0x038))
#define COMMON_PMIC_PWR_ECO_ONOFF1_ADDR(base) ((base) + (0x039))
#define COMMON_PMIC_BG_THSD_EN_ADDR(base) ((base) + (0x03D))
#define COMMON_PMIC_PMUH_LOCK_ADDR(base) ((base) + (0x03E))
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x040))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x041))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ADDR(base) ((base) + (0x042))
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_ADDR(base) ((base) + (0x043))
#define COMMON_PMIC_OCP_DEB_CTRL_ADDR(base) ((base) + (0x04B))
#define COMMON_PMIC_SCP_DEB_CTRL_ADDR(base) ((base) + (0x04C))
#define COMMON_PMIC_OTMP_DEB_CTRL_ADDR(base) ((base) + (0x04D))
#define COMMON_PMIC_RAMP_CLK_EN_ADDR(base) ((base) + (0x05F))
#define COMMON_PMIC_RAMP_GT_DEBUG_ADDR(base) ((base) + (0x060))
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_ADDR(base) ((base) + (0x068))
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_ADDR(base) ((base) + (0x069))
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_ADDR(base) ((base) + (0x06A))
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_ADDR(base) ((base) + (0x06B))
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_ADDR(base) ((base) + (0x06C))
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_ADDR(base) ((base) + (0x06D))
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_ADDR(base) ((base) + (0x06E))
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_ADDR(base) ((base) + (0x06F))
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_ADDR(base) ((base) + (0x070))
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_ADDR(base) ((base) + (0x071))
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_ADDR(base) ((base) + (0x072))
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_ADDR(base) ((base) + (0x073))
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_ADDR(base) ((base) + (0x074))
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_ADDR(base) ((base) + (0x075))
#define COMMON_PMIC_EFUSE_DATA_ADDR(base) ((base) + (0x083))
#define COMMON_PMIC_EFUSE_CLK_GT_EN_ADDR(base) ((base) + (0x084))
#define COMMON_PMIC_EFUSE_TRIM_SEL_ADDR(base) ((base) + (0x085))
#define COMMON_PMIC_EFUSE_CFG_0_ADDR(base) ((base) + (0x086))
#define COMMON_PMIC_EFUSE_CFG_1_ADDR(base) ((base) + (0x087))
#define COMMON_PMIC_EFUSE_CFG_2_ADDR(base) ((base) + (0x088))
#define COMMON_PMIC_EFUSE_CFG_3_ADDR(base) ((base) + (0x089))
#define COMMON_PMIC_EFUSE_AUTO_RD_ADDR(base) ((base) + (0x08A))
#define COMMON_PMIC_EFUSE_RDATA_ADDR(base) ((base) + (0x08B))
#define COMMON_PMIC_EFUSE_13_W_ADDR(base) ((base) + (0x08C))
#define COMMON_PMIC_EFUSE_16_W_ADDR(base) ((base) + (0x08D))
#define COMMON_PMIC_EFUSE_17_W_ADDR(base) ((base) + (0x08E))
#define COMMON_PMIC_EFUSE_18_W_ADDR(base) ((base) + (0x08F))
#define COMMON_PMIC_EFUSE_19_W_ADDR(base) ((base) + (0x090))
#define COMMON_PMIC_EFUSE_20_W_ADDR(base) ((base) + (0x091))
#define COMMON_PMIC_EFUSE_21_W_ADDR(base) ((base) + (0x092))
#define COMMON_PMIC_EFUSE_22_W_ADDR(base) ((base) + (0x093))
#define COMMON_PMIC_EFUSE_23_W_ADDR(base) ((base) + (0x094))
#define COMMON_PMIC_EFUSE_24_W_ADDR(base) ((base) + (0x095))
#define COMMON_PMIC_EFUSE_25_W_ADDR(base) ((base) + (0x096))
#define COMMON_PMIC_EFUSE_26_W_ADDR(base) ((base) + (0x097))
#define COMMON_PMIC_EFUSE_27_W_ADDR(base) ((base) + (0x098))
#define COMMON_PMIC_EFUSE_28_W_ADDR(base) ((base) + (0x099))
#define COMMON_PMIC_EFUSE_29_W_ADDR(base) ((base) + (0x09A))
#define COMMON_PMIC_EFUSE_30_W_ADDR(base) ((base) + (0x09B))
#define COMMON_PMIC_EFUSE_31_W_ADDR(base) ((base) + (0x09C))
#define COMMON_PMIC_EFUSE_32_W_ADDR(base) ((base) + (0x09D))
#define COMMON_PMIC_EFUSE_33_W_ADDR(base) ((base) + (0x09E))
#define COMMON_PMIC_EFUSE_34_W_ADDR(base) ((base) + (0x09F))
#define COMMON_PMIC_EFUSE_35_W_ADDR(base) ((base) + (0x0A0))
#define COMMON_PMIC_EFUSE_36_W_ADDR(base) ((base) + (0x0A1))
#define COMMON_PMIC_EFUSE_37_W_ADDR(base) ((base) + (0x0A2))
#define COMMON_PMIC_EFUSE_38_W_ADDR(base) ((base) + (0x0A3))
#define COMMON_PMIC_EFUSE_39_W_ADDR(base) ((base) + (0x0A4))
#define COMMON_PMIC_EFUSE_40_W_ADDR(base) ((base) + (0x0A5))
#define COMMON_PMIC_EFUSE_41_W_ADDR(base) ((base) + (0x0A6))
#define COMMON_PMIC_EFUSE_42_W_ADDR(base) ((base) + (0x0A7))
#define COMMON_PMIC_EFUSE_43_W_ADDR(base) ((base) + (0x0A8))
#define COMMON_PMIC_EFUSE_44_W_ADDR(base) ((base) + (0x0A9))
#define COMMON_PMIC_EFUSE_45_W_ADDR(base) ((base) + (0x0AA))
#define COMMON_PMIC_EFUSE_46_W_ADDR(base) ((base) + (0x0AB))
#define COMMON_PMIC_EFUSE_47_W_ADDR(base) ((base) + (0x0AC))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_IRQ_OCP_MASK0_ADDR(base) ((base) + (0x000UL))
#define COMMON_PMIC_IRQ_OCP_MASK1_ADDR(base) ((base) + (0x001UL))
#define COMMON_PMIC_IRQ_SCP_MASK0_ADDR(base) ((base) + (0x002UL))
#define COMMON_PMIC_IRQ_MASK_0_ADDR(base) ((base) + (0x004UL))
#else
#define COMMON_PMIC_IRQ_OCP_MASK0_ADDR(base) ((base) + (0x000))
#define COMMON_PMIC_IRQ_OCP_MASK1_ADDR(base) ((base) + (0x001))
#define COMMON_PMIC_IRQ_SCP_MASK0_ADDR(base) ((base) + (0x002))
#define COMMON_PMIC_IRQ_MASK_0_ADDR(base) ((base) + (0x004))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_IRQ_OCP0_ADDR(base) ((base) + (0x000UL))
#define COMMON_PMIC_IRQ_OCP1_ADDR(base) ((base) + (0x001UL))
#define COMMON_PMIC_IRQ_SCP0_ADDR(base) ((base) + (0x002UL))
#define COMMON_PMIC_IRQ0_SYS_ADDR(base) ((base) + (0x004UL))
#else
#define COMMON_PMIC_IRQ_OCP0_ADDR(base) ((base) + (0x000))
#define COMMON_PMIC_IRQ_OCP1_ADDR(base) ((base) + (0x001))
#define COMMON_PMIC_IRQ_SCP0_ADDR(base) ((base) + (0x002))
#define COMMON_PMIC_IRQ0_SYS_ADDR(base) ((base) + (0x004))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_NP_OCP0_ADDR(base) ((base) + (0x0000UL))
#define COMMON_PMIC_NP_OCP1_ADDR(base) ((base) + (0x0001UL))
#define COMMON_PMIC_NP_SCP0_ADDR(base) ((base) + (0x0002UL))
#define COMMON_PMIC_RAMP_EVENT0_ADDR(base) ((base) + (0x0004UL))
#define COMMON_PMIC_RAMP_EVENT1_ADDR(base) ((base) + (0x0005UL))
#define COMMON_PMIC_NP_SYS_EVENT0_ADDR(base) ((base) + (0x0006UL))
#define COMMON_PMIC_NP_SYS_EVENT1_ADDR(base) ((base) + (0x0007UL))
#else
#define COMMON_PMIC_NP_OCP0_ADDR(base) ((base) + (0x0000))
#define COMMON_PMIC_NP_OCP1_ADDR(base) ((base) + (0x0001))
#define COMMON_PMIC_NP_SCP0_ADDR(base) ((base) + (0x0002))
#define COMMON_PMIC_RAMP_EVENT0_ADDR(base) ((base) + (0x0004))
#define COMMON_PMIC_RAMP_EVENT1_ADDR(base) ((base) + (0x0005))
#define COMMON_PMIC_NP_SYS_EVENT0_ADDR(base) ((base) + (0x0006))
#define COMMON_PMIC_NP_SYS_EVENT1_ADDR(base) ((base) + (0x0007))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x000UL))
#define COMMON_PMIC_NP_PD_MASK_ADDR(base) ((base) + (0x007UL))
#define COMMON_PMIC_NP_PWRUP_DLY_CTRL_ADDR(base) ((base) + (0x008UL))
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_ADDR(base) ((base) + (0x009UL))
#define COMMON_PMIC_NP_RC256K_CTRL_ADDR(base) ((base) + (0x00BUL))
#define COMMON_PMIC_NP_DATA_IO_DS0_ADDR(base) ((base) + (0x011UL))
#define COMMON_PMIC_NP_DATA_IO_DS1_ADDR(base) ((base) + (0x012UL))
#define COMMON_PMIC_NP_EFUSE_READ_SEL_ADDR(base) ((base) + (0x013UL))
#define COMMON_PMIC_NP_ATEST_SEL_ADDR(base) ((base) + (0x020UL))
#define COMMON_PMIC_NP_SYS_CTRL0_ADDR(base) ((base) + (0x021UL))
#define COMMON_PMIC_NP_PMUD_CTRL0_ADDR(base) ((base) + (0x022UL))
#define COMMON_PMIC_NP_PMUD_CTRL1_ADDR(base) ((base) + (0x023UL))
#define COMMON_PMIC_NP_BANDGAP_CTRL0_ADDR(base) ((base) + (0x025UL))
#define COMMON_PMIC_NP_BANDGAP_CTRL1_ADDR(base) ((base) + (0x026UL))
#define COMMON_PMIC_NP_BUCK2_CTRL0_ADDR(base) ((base) + (0x050UL))
#define COMMON_PMIC_NP_BUCK2_CTRL1_ADDR(base) ((base) + (0x051UL))
#define COMMON_PMIC_NP_BUCK2_CTRL2_ADDR(base) ((base) + (0x052UL))
#define COMMON_PMIC_NP_BUCK3_CTRL0_ADDR(base) ((base) + (0x060UL))
#define COMMON_PMIC_NP_BUCK3_CTRL1_ADDR(base) ((base) + (0x061UL))
#define COMMON_PMIC_NP_BUCK3_CTRL2_ADDR(base) ((base) + (0x062UL))
#define COMMON_PMIC_NP_LDO_RESERVE0_ADDR(base) ((base) + (0x070UL))
#define COMMON_PMIC_NP_LDO_RESERVE1_ADDR(base) ((base) + (0x071UL))
#define COMMON_PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x080UL))
#define COMMON_PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x081UL))
#define COMMON_PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x082UL))
#define COMMON_PMIC_NP_D2A_RES3_ADDR(base) ((base) + (0x083UL))
#define COMMON_PMIC_NP_D2A_RES4_ADDR(base) ((base) + (0x084UL))
#define COMMON_PMIC_DEBUG_LOCK_ADDR(base) ((base) + (0x090UL))
#define COMMON_PMIC_SYS_DEBUG0_ADDR(base) ((base) + (0x091UL))
#define COMMON_PMIC_SYS_DEBUG1_ADDR(base) ((base) + (0x092UL))
#define COMMON_PMIC_NP_HRST_REG0_ADDR(base) ((base) + (0x093UL))
#define COMMON_PMIC_NP_HRST_REG1_ADDR(base) ((base) + (0x094UL))
#define COMMON_PMIC_NP_HRST_REG2_ADDR(base) ((base) + (0x095UL))
#define COMMON_PMIC_NP_HRST_REG3_ADDR(base) ((base) + (0x096UL))
#else
#define COMMON_PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x000))
#define COMMON_PMIC_NP_PD_MASK_ADDR(base) ((base) + (0x007))
#define COMMON_PMIC_NP_PWRUP_DLY_CTRL_ADDR(base) ((base) + (0x008))
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_ADDR(base) ((base) + (0x009))
#define COMMON_PMIC_NP_RC256K_CTRL_ADDR(base) ((base) + (0x00B))
#define COMMON_PMIC_NP_DATA_IO_DS0_ADDR(base) ((base) + (0x011))
#define COMMON_PMIC_NP_DATA_IO_DS1_ADDR(base) ((base) + (0x012))
#define COMMON_PMIC_NP_EFUSE_READ_SEL_ADDR(base) ((base) + (0x013))
#define COMMON_PMIC_NP_ATEST_SEL_ADDR(base) ((base) + (0x020))
#define COMMON_PMIC_NP_SYS_CTRL0_ADDR(base) ((base) + (0x021))
#define COMMON_PMIC_NP_PMUD_CTRL0_ADDR(base) ((base) + (0x022))
#define COMMON_PMIC_NP_PMUD_CTRL1_ADDR(base) ((base) + (0x023))
#define COMMON_PMIC_NP_BANDGAP_CTRL0_ADDR(base) ((base) + (0x025))
#define COMMON_PMIC_NP_BANDGAP_CTRL1_ADDR(base) ((base) + (0x026))
#define COMMON_PMIC_NP_BUCK2_CTRL0_ADDR(base) ((base) + (0x050))
#define COMMON_PMIC_NP_BUCK2_CTRL1_ADDR(base) ((base) + (0x051))
#define COMMON_PMIC_NP_BUCK2_CTRL2_ADDR(base) ((base) + (0x052))
#define COMMON_PMIC_NP_BUCK3_CTRL0_ADDR(base) ((base) + (0x060))
#define COMMON_PMIC_NP_BUCK3_CTRL1_ADDR(base) ((base) + (0x061))
#define COMMON_PMIC_NP_BUCK3_CTRL2_ADDR(base) ((base) + (0x062))
#define COMMON_PMIC_NP_LDO_RESERVE0_ADDR(base) ((base) + (0x070))
#define COMMON_PMIC_NP_LDO_RESERVE1_ADDR(base) ((base) + (0x071))
#define COMMON_PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x080))
#define COMMON_PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x081))
#define COMMON_PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x082))
#define COMMON_PMIC_NP_D2A_RES3_ADDR(base) ((base) + (0x083))
#define COMMON_PMIC_NP_D2A_RES4_ADDR(base) ((base) + (0x084))
#define COMMON_PMIC_DEBUG_LOCK_ADDR(base) ((base) + (0x090))
#define COMMON_PMIC_SYS_DEBUG0_ADDR(base) ((base) + (0x091))
#define COMMON_PMIC_SYS_DEBUG1_ADDR(base) ((base) + (0x092))
#define COMMON_PMIC_NP_HRST_REG0_ADDR(base) ((base) + (0x093))
#define COMMON_PMIC_NP_HRST_REG1_ADDR(base) ((base) + (0x094))
#define COMMON_PMIC_NP_HRST_REG2_ADDR(base) ((base) + (0x095))
#define COMMON_PMIC_NP_HRST_REG3_ADDR(base) ((base) + (0x096))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_BANDGAP_CFG0_ADDR(base) ((base) + (0x000UL))
#define COMMON_PMIC_BANDGAP_CFG1_ADDR(base) ((base) + (0x001UL))
#define COMMON_PMIC_BANDGAP_CFG2_ADDR(base) ((base) + (0x002UL))
#define COMMON_PMIC_BANDGAP_CFG3_ADDR(base) ((base) + (0x003UL))
#define COMMON_PMIC_BANDGAP_CFG4_ADDR(base) ((base) + (0x004UL))
#define COMMON_PMIC_BANDGAP_CFG5_ADDR(base) ((base) + (0x005UL))
#define COMMON_PMIC_OSC_9M6_CFG0_ADDR(base) ((base) + (0x00AUL))
#define COMMON_PMIC_SYS_CTRL_CFG0_ADDR(base) ((base) + (0x00BUL))
#define COMMON_PMIC_SYS_CTRL_CFG1_ADDR(base) ((base) + (0x00CUL))
#define COMMON_PMIC_BUCK0_CFG0_ADDR(base) ((base) + (0x010UL))
#define COMMON_PMIC_BUCK0_CFG1_ADDR(base) ((base) + (0x011UL))
#define COMMON_PMIC_BUCK0_CFG2_ADDR(base) ((base) + (0x012UL))
#define COMMON_PMIC_BUCK0_CFG3_ADDR(base) ((base) + (0x013UL))
#define COMMON_PMIC_BUCK0_CFG4_ADDR(base) ((base) + (0x014UL))
#define COMMON_PMIC_BUCK0_CFG5_ADDR(base) ((base) + (0x015UL))
#define COMMON_PMIC_BUCK0_CFG6_ADDR(base) ((base) + (0x016UL))
#define COMMON_PMIC_BUCK0_CFG7_ADDR(base) ((base) + (0x017UL))
#define COMMON_PMIC_BUCK0_CFG8_ADDR(base) ((base) + (0x018UL))
#define COMMON_PMIC_BUCK0_CFG9_ADDR(base) ((base) + (0x019UL))
#define COMMON_PMIC_BUCK0_CFG10_ADDR(base) ((base) + (0x01AUL))
#define COMMON_PMIC_BUCK0_CFG11_ADDR(base) ((base) + (0x01BUL))
#define COMMON_PMIC_BUCK0_CFG12_ADDR(base) ((base) + (0x01CUL))
#define COMMON_PMIC_BUCK0_CFG13_ADDR(base) ((base) + (0x01DUL))
#define COMMON_PMIC_BUCK0_CFG14_ADDR(base) ((base) + (0x01EUL))
#define COMMON_PMIC_BUCK0_CFG15_ADDR(base) ((base) + (0x01FUL))
#define COMMON_PMIC_BUCK0_STATUS0_ADDR(base) ((base) + (0x020UL))
#define COMMON_PMIC_BUCK1_CFG0_ADDR(base) ((base) + (0x030UL))
#define COMMON_PMIC_BUCK1_CFG1_ADDR(base) ((base) + (0x031UL))
#define COMMON_PMIC_BUCK1_CFG2_ADDR(base) ((base) + (0x032UL))
#define COMMON_PMIC_BUCK1_CFG3_ADDR(base) ((base) + (0x033UL))
#define COMMON_PMIC_BUCK1_CFG4_ADDR(base) ((base) + (0x034UL))
#define COMMON_PMIC_BUCK1_CFG5_ADDR(base) ((base) + (0x035UL))
#define COMMON_PMIC_BUCK1_CFG6_ADDR(base) ((base) + (0x036UL))
#define COMMON_PMIC_BUCK1_CFG7_ADDR(base) ((base) + (0x037UL))
#define COMMON_PMIC_BUCK1_CFG8_ADDR(base) ((base) + (0x038UL))
#define COMMON_PMIC_BUCK1_CFG9_ADDR(base) ((base) + (0x039UL))
#define COMMON_PMIC_BUCK1_CFG10_ADDR(base) ((base) + (0x03AUL))
#define COMMON_PMIC_BUCK1_CFG11_ADDR(base) ((base) + (0x03BUL))
#define COMMON_PMIC_BUCK1_CFG12_ADDR(base) ((base) + (0x03CUL))
#define COMMON_PMIC_BUCK1_CFG13_ADDR(base) ((base) + (0x03DUL))
#define COMMON_PMIC_BUCK1_CFG14_ADDR(base) ((base) + (0x03EUL))
#define COMMON_PMIC_BUCK1_CFG15_ADDR(base) ((base) + (0x03FUL))
#define COMMON_PMIC_BUCK1_STATUS0_ADDR(base) ((base) + (0x040UL))
#define COMMON_PMIC_BUCK2_CFG0_ADDR(base) ((base) + (0x060UL))
#define COMMON_PMIC_BUCK2_CFG1_ADDR(base) ((base) + (0x061UL))
#define COMMON_PMIC_BUCK2_CFG2_ADDR(base) ((base) + (0x062UL))
#define COMMON_PMIC_BUCK2_CFG3_ADDR(base) ((base) + (0x063UL))
#define COMMON_PMIC_BUCK2_CFG4_ADDR(base) ((base) + (0x064UL))
#define COMMON_PMIC_BUCK2_CFG5_ADDR(base) ((base) + (0x065UL))
#define COMMON_PMIC_BUCK2_CFG6_ADDR(base) ((base) + (0x066UL))
#define COMMON_PMIC_BUCK2_CFG7_ADDR(base) ((base) + (0x067UL))
#define COMMON_PMIC_BUCK2_CFG8_ADDR(base) ((base) + (0x068UL))
#define COMMON_PMIC_BUCK2_CFG9_ADDR(base) ((base) + (0x069UL))
#define COMMON_PMIC_BUCK2_CFG10_ADDR(base) ((base) + (0x06AUL))
#define COMMON_PMIC_BUCK2_CFG11_ADDR(base) ((base) + (0x06BUL))
#define COMMON_PMIC_BUCK2_CFG12_ADDR(base) ((base) + (0x06CUL))
#define COMMON_PMIC_BUCK2_CFG13_ADDR(base) ((base) + (0x06DUL))
#define COMMON_PMIC_BUCK2_STATUS0_ADDR(base) ((base) + (0x06EUL))
#define COMMON_PMIC_BUCK3_CFG0_ADDR(base) ((base) + (0x080UL))
#define COMMON_PMIC_BUCK3_CFG1_ADDR(base) ((base) + (0x081UL))
#define COMMON_PMIC_BUCK3_CFG2_ADDR(base) ((base) + (0x082UL))
#define COMMON_PMIC_BUCK3_CFG3_ADDR(base) ((base) + (0x083UL))
#define COMMON_PMIC_BUCK3_CFG4_ADDR(base) ((base) + (0x084UL))
#define COMMON_PMIC_BUCK3_CFG5_ADDR(base) ((base) + (0x085UL))
#define COMMON_PMIC_BUCK3_CFG6_ADDR(base) ((base) + (0x086UL))
#define COMMON_PMIC_BUCK3_CFG7_ADDR(base) ((base) + (0x087UL))
#define COMMON_PMIC_BUCK3_CFG8_ADDR(base) ((base) + (0x088UL))
#define COMMON_PMIC_BUCK3_CFG9_ADDR(base) ((base) + (0x089UL))
#define COMMON_PMIC_BUCK3_CFG10_ADDR(base) ((base) + (0x08AUL))
#define COMMON_PMIC_BUCK3_CFG11_ADDR(base) ((base) + (0x08BUL))
#define COMMON_PMIC_BUCK3_CFG12_ADDR(base) ((base) + (0x08CUL))
#define COMMON_PMIC_BUCK3_CFG13_ADDR(base) ((base) + (0x08DUL))
#define COMMON_PMIC_BUCK3_STATUS0_ADDR(base) ((base) + (0x08EUL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_ADDR(base) ((base) + (0x0A0UL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG1_ADDR(base) ((base) + (0x0A1UL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG2_ADDR(base) ((base) + (0x0A2UL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG3_ADDR(base) ((base) + (0x0A3UL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG4_ADDR(base) ((base) + (0x0A4UL))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG5_ADDR(base) ((base) + (0x0A5UL))
#define COMMON_PMIC_LDO1_CFG0_ADDR(base) ((base) + (0x0B0UL))
#define COMMON_PMIC_LDO1_CFG1_ADDR(base) ((base) + (0x0B1UL))
#define COMMON_PMIC_LDO2_CFG0_ADDR(base) ((base) + (0x0B2UL))
#define COMMON_PMIC_LDO2_CFG1_ADDR(base) ((base) + (0x0B3UL))
#define COMMON_PMIC_LDO3_CFG0_ADDR(base) ((base) + (0x0B4UL))
#define COMMON_PMIC_LDO3_CFG1_ADDR(base) ((base) + (0x0B5UL))
#define COMMON_PMIC_LDO4_CFG0_ADDR(base) ((base) + (0x0B6UL))
#define COMMON_PMIC_LDO4_CFG1_ADDR(base) ((base) + (0x0B7UL))
#define COMMON_PMIC_LDO5_CFG0_ADDR(base) ((base) + (0x0B8UL))
#define COMMON_PMIC_LDO5_CFG1_ADDR(base) ((base) + (0x0B9UL))
#define COMMON_PMIC_LDO6_CFG0_ADDR(base) ((base) + (0x0BAUL))
#define COMMON_PMIC_LDO6_CFG1_ADDR(base) ((base) + (0x0BBUL))
#define COMMON_PMIC_LDO7_CFG0_ADDR(base) ((base) + (0x0BCUL))
#define COMMON_PMIC_LDO7_CFG1_ADDR(base) ((base) + (0x0BDUL))
#define COMMON_PMIC_LDO8_CFG0_ADDR(base) ((base) + (0x0BEUL))
#define COMMON_PMIC_LDO8_CFG1_ADDR(base) ((base) + (0x0BFUL))
#define COMMON_PMIC_LDO_RESERVE_CFG0_ADDR(base) ((base) + (0x0C4UL))
#define COMMON_PMIC_LDO_RESERVE_CFG1_ADDR(base) ((base) + (0x0C5UL))
#define COMMON_PMIC_LDO_RESERVE_CFG2_ADDR(base) ((base) + (0x0C6UL))
#define COMMON_PMIC_LDO_RESERVE_CFG3_ADDR(base) ((base) + (0x0C7UL))
#define COMMON_PMIC_LDO_RESERVE_CFG4_ADDR(base) ((base) + (0x0C8UL))
#define COMMON_PMIC_PMUH_CFG0_ADDR(base) ((base) + (0x0D0UL))
#define COMMON_PMIC_D2A_RESERVE_CFG0_ADDR(base) ((base) + (0x0E0UL))
#define COMMON_PMIC_D2A_RESERVE_CFG1_ADDR(base) ((base) + (0x0E1UL))
#define COMMON_PMIC_D2A_RESERVE_CFG2_ADDR(base) ((base) + (0x0E2UL))
#define COMMON_PMIC_D2A_RESERVE_CFG3_ADDR(base) ((base) + (0x0E3UL))
#define COMMON_PMIC_A2D_RESERVE0_ADDR(base) ((base) + (0x0E4UL))
#define COMMON_PMIC_A2D_RESERVE1_ADDR(base) ((base) + (0x0E5UL))
#define COMMON_PMIC_ATEST_RESERVE_CFG0_ADDR(base) ((base) + (0x0E6UL))
#define COMMON_PMIC_ATEST_RESERVE_CFG1_ADDR(base) ((base) + (0x0E7UL))
#define COMMON_PMIC_ATEST_RESERVE_CFG2_ADDR(base) ((base) + (0x0E8UL))
#define COMMON_PMIC_ATEST_RESERVE_CFG3_ADDR(base) ((base) + (0x0E9UL))
#else
#define COMMON_PMIC_BANDGAP_CFG0_ADDR(base) ((base) + (0x000))
#define COMMON_PMIC_BANDGAP_CFG1_ADDR(base) ((base) + (0x001))
#define COMMON_PMIC_BANDGAP_CFG2_ADDR(base) ((base) + (0x002))
#define COMMON_PMIC_BANDGAP_CFG3_ADDR(base) ((base) + (0x003))
#define COMMON_PMIC_BANDGAP_CFG4_ADDR(base) ((base) + (0x004))
#define COMMON_PMIC_BANDGAP_CFG5_ADDR(base) ((base) + (0x005))
#define COMMON_PMIC_OSC_9M6_CFG0_ADDR(base) ((base) + (0x00A))
#define COMMON_PMIC_SYS_CTRL_CFG0_ADDR(base) ((base) + (0x00B))
#define COMMON_PMIC_SYS_CTRL_CFG1_ADDR(base) ((base) + (0x00C))
#define COMMON_PMIC_BUCK0_CFG0_ADDR(base) ((base) + (0x010))
#define COMMON_PMIC_BUCK0_CFG1_ADDR(base) ((base) + (0x011))
#define COMMON_PMIC_BUCK0_CFG2_ADDR(base) ((base) + (0x012))
#define COMMON_PMIC_BUCK0_CFG3_ADDR(base) ((base) + (0x013))
#define COMMON_PMIC_BUCK0_CFG4_ADDR(base) ((base) + (0x014))
#define COMMON_PMIC_BUCK0_CFG5_ADDR(base) ((base) + (0x015))
#define COMMON_PMIC_BUCK0_CFG6_ADDR(base) ((base) + (0x016))
#define COMMON_PMIC_BUCK0_CFG7_ADDR(base) ((base) + (0x017))
#define COMMON_PMIC_BUCK0_CFG8_ADDR(base) ((base) + (0x018))
#define COMMON_PMIC_BUCK0_CFG9_ADDR(base) ((base) + (0x019))
#define COMMON_PMIC_BUCK0_CFG10_ADDR(base) ((base) + (0x01A))
#define COMMON_PMIC_BUCK0_CFG11_ADDR(base) ((base) + (0x01B))
#define COMMON_PMIC_BUCK0_CFG12_ADDR(base) ((base) + (0x01C))
#define COMMON_PMIC_BUCK0_CFG13_ADDR(base) ((base) + (0x01D))
#define COMMON_PMIC_BUCK0_CFG14_ADDR(base) ((base) + (0x01E))
#define COMMON_PMIC_BUCK0_CFG15_ADDR(base) ((base) + (0x01F))
#define COMMON_PMIC_BUCK0_STATUS0_ADDR(base) ((base) + (0x020))
#define COMMON_PMIC_BUCK1_CFG0_ADDR(base) ((base) + (0x030))
#define COMMON_PMIC_BUCK1_CFG1_ADDR(base) ((base) + (0x031))
#define COMMON_PMIC_BUCK1_CFG2_ADDR(base) ((base) + (0x032))
#define COMMON_PMIC_BUCK1_CFG3_ADDR(base) ((base) + (0x033))
#define COMMON_PMIC_BUCK1_CFG4_ADDR(base) ((base) + (0x034))
#define COMMON_PMIC_BUCK1_CFG5_ADDR(base) ((base) + (0x035))
#define COMMON_PMIC_BUCK1_CFG6_ADDR(base) ((base) + (0x036))
#define COMMON_PMIC_BUCK1_CFG7_ADDR(base) ((base) + (0x037))
#define COMMON_PMIC_BUCK1_CFG8_ADDR(base) ((base) + (0x038))
#define COMMON_PMIC_BUCK1_CFG9_ADDR(base) ((base) + (0x039))
#define COMMON_PMIC_BUCK1_CFG10_ADDR(base) ((base) + (0x03A))
#define COMMON_PMIC_BUCK1_CFG11_ADDR(base) ((base) + (0x03B))
#define COMMON_PMIC_BUCK1_CFG12_ADDR(base) ((base) + (0x03C))
#define COMMON_PMIC_BUCK1_CFG13_ADDR(base) ((base) + (0x03D))
#define COMMON_PMIC_BUCK1_CFG14_ADDR(base) ((base) + (0x03E))
#define COMMON_PMIC_BUCK1_CFG15_ADDR(base) ((base) + (0x03F))
#define COMMON_PMIC_BUCK1_STATUS0_ADDR(base) ((base) + (0x040))
#define COMMON_PMIC_BUCK2_CFG0_ADDR(base) ((base) + (0x060))
#define COMMON_PMIC_BUCK2_CFG1_ADDR(base) ((base) + (0x061))
#define COMMON_PMIC_BUCK2_CFG2_ADDR(base) ((base) + (0x062))
#define COMMON_PMIC_BUCK2_CFG3_ADDR(base) ((base) + (0x063))
#define COMMON_PMIC_BUCK2_CFG4_ADDR(base) ((base) + (0x064))
#define COMMON_PMIC_BUCK2_CFG5_ADDR(base) ((base) + (0x065))
#define COMMON_PMIC_BUCK2_CFG6_ADDR(base) ((base) + (0x066))
#define COMMON_PMIC_BUCK2_CFG7_ADDR(base) ((base) + (0x067))
#define COMMON_PMIC_BUCK2_CFG8_ADDR(base) ((base) + (0x068))
#define COMMON_PMIC_BUCK2_CFG9_ADDR(base) ((base) + (0x069))
#define COMMON_PMIC_BUCK2_CFG10_ADDR(base) ((base) + (0x06A))
#define COMMON_PMIC_BUCK2_CFG11_ADDR(base) ((base) + (0x06B))
#define COMMON_PMIC_BUCK2_CFG12_ADDR(base) ((base) + (0x06C))
#define COMMON_PMIC_BUCK2_CFG13_ADDR(base) ((base) + (0x06D))
#define COMMON_PMIC_BUCK2_STATUS0_ADDR(base) ((base) + (0x06E))
#define COMMON_PMIC_BUCK3_CFG0_ADDR(base) ((base) + (0x080))
#define COMMON_PMIC_BUCK3_CFG1_ADDR(base) ((base) + (0x081))
#define COMMON_PMIC_BUCK3_CFG2_ADDR(base) ((base) + (0x082))
#define COMMON_PMIC_BUCK3_CFG3_ADDR(base) ((base) + (0x083))
#define COMMON_PMIC_BUCK3_CFG4_ADDR(base) ((base) + (0x084))
#define COMMON_PMIC_BUCK3_CFG5_ADDR(base) ((base) + (0x085))
#define COMMON_PMIC_BUCK3_CFG6_ADDR(base) ((base) + (0x086))
#define COMMON_PMIC_BUCK3_CFG7_ADDR(base) ((base) + (0x087))
#define COMMON_PMIC_BUCK3_CFG8_ADDR(base) ((base) + (0x088))
#define COMMON_PMIC_BUCK3_CFG9_ADDR(base) ((base) + (0x089))
#define COMMON_PMIC_BUCK3_CFG10_ADDR(base) ((base) + (0x08A))
#define COMMON_PMIC_BUCK3_CFG11_ADDR(base) ((base) + (0x08B))
#define COMMON_PMIC_BUCK3_CFG12_ADDR(base) ((base) + (0x08C))
#define COMMON_PMIC_BUCK3_CFG13_ADDR(base) ((base) + (0x08D))
#define COMMON_PMIC_BUCK3_STATUS0_ADDR(base) ((base) + (0x08E))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_ADDR(base) ((base) + (0x0A0))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG1_ADDR(base) ((base) + (0x0A1))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG2_ADDR(base) ((base) + (0x0A2))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG3_ADDR(base) ((base) + (0x0A3))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG4_ADDR(base) ((base) + (0x0A4))
#define COMMON_PMIC_BUCK_HYS_TOP_CFG5_ADDR(base) ((base) + (0x0A5))
#define COMMON_PMIC_LDO1_CFG0_ADDR(base) ((base) + (0x0B0))
#define COMMON_PMIC_LDO1_CFG1_ADDR(base) ((base) + (0x0B1))
#define COMMON_PMIC_LDO2_CFG0_ADDR(base) ((base) + (0x0B2))
#define COMMON_PMIC_LDO2_CFG1_ADDR(base) ((base) + (0x0B3))
#define COMMON_PMIC_LDO3_CFG0_ADDR(base) ((base) + (0x0B4))
#define COMMON_PMIC_LDO3_CFG1_ADDR(base) ((base) + (0x0B5))
#define COMMON_PMIC_LDO4_CFG0_ADDR(base) ((base) + (0x0B6))
#define COMMON_PMIC_LDO4_CFG1_ADDR(base) ((base) + (0x0B7))
#define COMMON_PMIC_LDO5_CFG0_ADDR(base) ((base) + (0x0B8))
#define COMMON_PMIC_LDO5_CFG1_ADDR(base) ((base) + (0x0B9))
#define COMMON_PMIC_LDO6_CFG0_ADDR(base) ((base) + (0x0BA))
#define COMMON_PMIC_LDO6_CFG1_ADDR(base) ((base) + (0x0BB))
#define COMMON_PMIC_LDO7_CFG0_ADDR(base) ((base) + (0x0BC))
#define COMMON_PMIC_LDO7_CFG1_ADDR(base) ((base) + (0x0BD))
#define COMMON_PMIC_LDO8_CFG0_ADDR(base) ((base) + (0x0BE))
#define COMMON_PMIC_LDO8_CFG1_ADDR(base) ((base) + (0x0BF))
#define COMMON_PMIC_LDO_RESERVE_CFG0_ADDR(base) ((base) + (0x0C4))
#define COMMON_PMIC_LDO_RESERVE_CFG1_ADDR(base) ((base) + (0x0C5))
#define COMMON_PMIC_LDO_RESERVE_CFG2_ADDR(base) ((base) + (0x0C6))
#define COMMON_PMIC_LDO_RESERVE_CFG3_ADDR(base) ((base) + (0x0C7))
#define COMMON_PMIC_LDO_RESERVE_CFG4_ADDR(base) ((base) + (0x0C8))
#define COMMON_PMIC_PMUH_CFG0_ADDR(base) ((base) + (0x0D0))
#define COMMON_PMIC_D2A_RESERVE_CFG0_ADDR(base) ((base) + (0x0E0))
#define COMMON_PMIC_D2A_RESERVE_CFG1_ADDR(base) ((base) + (0x0E1))
#define COMMON_PMIC_D2A_RESERVE_CFG2_ADDR(base) ((base) + (0x0E2))
#define COMMON_PMIC_D2A_RESERVE_CFG3_ADDR(base) ((base) + (0x0E3))
#define COMMON_PMIC_A2D_RESERVE0_ADDR(base) ((base) + (0x0E4))
#define COMMON_PMIC_A2D_RESERVE1_ADDR(base) ((base) + (0x0E5))
#define COMMON_PMIC_ATEST_RESERVE_CFG0_ADDR(base) ((base) + (0x0E6))
#define COMMON_PMIC_ATEST_RESERVE_CFG1_ADDR(base) ((base) + (0x0E7))
#define COMMON_PMIC_ATEST_RESERVE_CFG2_ADDR(base) ((base) + (0x0E8))
#define COMMON_PMIC_ATEST_RESERVE_CFG3_ADDR(base) ((base) + (0x0E9))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num0 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_0_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_0_project_num0_START (0)
#define COMMON_PMIC_CHIP_VERSION_0_project_num0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num1 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_1_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_1_project_num1_START (0)
#define COMMON_PMIC_CHIP_VERSION_1_project_num1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num2 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_2_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_2_project_num2_START (0)
#define COMMON_PMIC_CHIP_VERSION_2_project_num2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num3 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_3_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_3_project_num3_START (0)
#define COMMON_PMIC_CHIP_VERSION_3_project_num3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char version : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_4_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_4_version_START (0)
#define COMMON_PMIC_CHIP_VERSION_4_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_5_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_5_chip_id_START (0)
#define COMMON_PMIC_CHIP_VERSION_5_chip_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char lock : 8;
    } reg;
} COMMON_PMIC_LOCK_UNION;
#endif
#define COMMON_PMIC_LOCK_lock_START (0)
#define COMMON_PMIC_LOCK_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_thsd_otmp140_d180ur : 1;
        unsigned char st_thsd_otmp125_d120ur : 1;
        unsigned char st_vsys_pwroff_abs_d20nr : 1;
        unsigned char st_vsys_ov_d200ur : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_SYS_STATUS_UNION;
#endif
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp140_d180ur_START (0)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp140_d180ur_END (0)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp125_d120ur_START (1)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp125_d120ur_END (1)
#define COMMON_PMIC_SYS_STATUS_st_vsys_pwroff_abs_d20nr_START (2)
#define COMMON_PMIC_SYS_STATUS_st_vsys_pwroff_abs_d20nr_END (2)
#define COMMON_PMIC_SYS_STATUS_st_vsys_ov_d200ur_START (3)
#define COMMON_PMIC_SYS_STATUS_st_vsys_ov_d200ur_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b0_ocp : 1;
        unsigned char st_b1_ocp : 1;
        unsigned char st_b2_ocp : 1;
        unsigned char st_b3_ocp : 1;
        unsigned char st_pmuh_ocp : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_OCP_STATUS0_UNION;
#endif
#define COMMON_PMIC_OCP_STATUS0_st_b0_ocp_START (0)
#define COMMON_PMIC_OCP_STATUS0_st_b0_ocp_END (0)
#define COMMON_PMIC_OCP_STATUS0_st_b1_ocp_START (1)
#define COMMON_PMIC_OCP_STATUS0_st_b1_ocp_END (1)
#define COMMON_PMIC_OCP_STATUS0_st_b2_ocp_START (2)
#define COMMON_PMIC_OCP_STATUS0_st_b2_ocp_END (2)
#define COMMON_PMIC_OCP_STATUS0_st_b3_ocp_START (3)
#define COMMON_PMIC_OCP_STATUS0_st_b3_ocp_END (3)
#define COMMON_PMIC_OCP_STATUS0_st_pmuh_ocp_START (4)
#define COMMON_PMIC_OCP_STATUS0_st_pmuh_ocp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_ldo1_ocp : 1;
        unsigned char st_ldo2_ocp : 1;
        unsigned char st_ldo3_ocp : 1;
        unsigned char st_ldo4_ocp : 1;
        unsigned char st_ldo5_ocp : 1;
        unsigned char st_ldo6_ocp : 1;
        unsigned char st_ldo7_ocp : 1;
        unsigned char st_ldo8_ocp : 1;
    } reg;
} COMMON_PMIC_OCP_STATUS1_UNION;
#endif
#define COMMON_PMIC_OCP_STATUS1_st_ldo1_ocp_START (0)
#define COMMON_PMIC_OCP_STATUS1_st_ldo1_ocp_END (0)
#define COMMON_PMIC_OCP_STATUS1_st_ldo2_ocp_START (1)
#define COMMON_PMIC_OCP_STATUS1_st_ldo2_ocp_END (1)
#define COMMON_PMIC_OCP_STATUS1_st_ldo3_ocp_START (2)
#define COMMON_PMIC_OCP_STATUS1_st_ldo3_ocp_END (2)
#define COMMON_PMIC_OCP_STATUS1_st_ldo4_ocp_START (3)
#define COMMON_PMIC_OCP_STATUS1_st_ldo4_ocp_END (3)
#define COMMON_PMIC_OCP_STATUS1_st_ldo5_ocp_START (4)
#define COMMON_PMIC_OCP_STATUS1_st_ldo5_ocp_END (4)
#define COMMON_PMIC_OCP_STATUS1_st_ldo6_ocp_START (5)
#define COMMON_PMIC_OCP_STATUS1_st_ldo6_ocp_END (5)
#define COMMON_PMIC_OCP_STATUS1_st_ldo7_ocp_START (6)
#define COMMON_PMIC_OCP_STATUS1_st_ldo7_ocp_END (6)
#define COMMON_PMIC_OCP_STATUS1_st_ldo8_ocp_START (7)
#define COMMON_PMIC_OCP_STATUS1_st_ldo8_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b0_scp : 1;
        unsigned char st_b1_scp : 1;
        unsigned char st_b2_scp : 1;
        unsigned char st_b3_scp : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_SCP_STATUS0_UNION;
#endif
#define COMMON_PMIC_SCP_STATUS0_st_b0_scp_START (0)
#define COMMON_PMIC_SCP_STATUS0_st_b0_scp_END (0)
#define COMMON_PMIC_SCP_STATUS0_st_b1_scp_START (1)
#define COMMON_PMIC_SCP_STATUS0_st_b1_scp_END (1)
#define COMMON_PMIC_SCP_STATUS0_st_b2_scp_START (2)
#define COMMON_PMIC_SCP_STATUS0_st_b2_scp_END (2)
#define COMMON_PMIC_SCP_STATUS0_st_b3_scp_START (3)
#define COMMON_PMIC_SCP_STATUS0_st_b3_scp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b3_rampup : 1;
        unsigned char st_b3_rampdown : 1;
        unsigned char st_b3_pull_down : 1;
        unsigned char reserved_0 : 1;
        unsigned char st_b2_rampup : 1;
        unsigned char st_b2_rampdown : 1;
        unsigned char st_b2_pull_down : 1;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_RAMP_ST0_UNION;
#endif
#define COMMON_PMIC_RAMP_ST0_st_b3_rampup_START (0)
#define COMMON_PMIC_RAMP_ST0_st_b3_rampup_END (0)
#define COMMON_PMIC_RAMP_ST0_st_b3_rampdown_START (1)
#define COMMON_PMIC_RAMP_ST0_st_b3_rampdown_END (1)
#define COMMON_PMIC_RAMP_ST0_st_b3_pull_down_START (2)
#define COMMON_PMIC_RAMP_ST0_st_b3_pull_down_END (2)
#define COMMON_PMIC_RAMP_ST0_st_b2_rampup_START (4)
#define COMMON_PMIC_RAMP_ST0_st_b2_rampup_END (4)
#define COMMON_PMIC_RAMP_ST0_st_b2_rampdown_START (5)
#define COMMON_PMIC_RAMP_ST0_st_b2_rampdown_END (5)
#define COMMON_PMIC_RAMP_ST0_st_b2_pull_down_START (6)
#define COMMON_PMIC_RAMP_ST0_st_b2_pull_down_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b0_en : 1;
        unsigned char st_b1_en : 1;
        unsigned char st_b2_en : 1;
        unsigned char st_b3_en : 1;
        unsigned char st_pmuh_en : 1;
        unsigned char st_pmud_buck_en : 1;
        unsigned char st_pmud_state : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_POWER_STATUS0_UNION;
#endif
#define COMMON_PMIC_POWER_STATUS0_st_b0_en_START (0)
#define COMMON_PMIC_POWER_STATUS0_st_b0_en_END (0)
#define COMMON_PMIC_POWER_STATUS0_st_b1_en_START (1)
#define COMMON_PMIC_POWER_STATUS0_st_b1_en_END (1)
#define COMMON_PMIC_POWER_STATUS0_st_b2_en_START (2)
#define COMMON_PMIC_POWER_STATUS0_st_b2_en_END (2)
#define COMMON_PMIC_POWER_STATUS0_st_b3_en_START (3)
#define COMMON_PMIC_POWER_STATUS0_st_b3_en_END (3)
#define COMMON_PMIC_POWER_STATUS0_st_pmuh_en_START (4)
#define COMMON_PMIC_POWER_STATUS0_st_pmuh_en_END (4)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_buck_en_START (5)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_buck_en_END (5)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_state_START (6)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_state_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_ldo1_en : 1;
        unsigned char st_ldo2_en : 1;
        unsigned char st_ldo3_en : 1;
        unsigned char st_ldo4_en : 1;
        unsigned char st_ldo5_en : 1;
        unsigned char st_ldo6_en : 1;
        unsigned char st_ldo7_en : 1;
        unsigned char st_ldo8_en : 1;
    } reg;
} COMMON_PMIC_POWER_STATUS1_UNION;
#endif
#define COMMON_PMIC_POWER_STATUS1_st_ldo1_en_START (0)
#define COMMON_PMIC_POWER_STATUS1_st_ldo1_en_END (0)
#define COMMON_PMIC_POWER_STATUS1_st_ldo2_en_START (1)
#define COMMON_PMIC_POWER_STATUS1_st_ldo2_en_END (1)
#define COMMON_PMIC_POWER_STATUS1_st_ldo3_en_START (2)
#define COMMON_PMIC_POWER_STATUS1_st_ldo3_en_END (2)
#define COMMON_PMIC_POWER_STATUS1_st_ldo4_en_START (3)
#define COMMON_PMIC_POWER_STATUS1_st_ldo4_en_END (3)
#define COMMON_PMIC_POWER_STATUS1_st_ldo5_en_START (4)
#define COMMON_PMIC_POWER_STATUS1_st_ldo5_en_END (4)
#define COMMON_PMIC_POWER_STATUS1_st_ldo6_en_START (5)
#define COMMON_PMIC_POWER_STATUS1_st_ldo6_en_END (5)
#define COMMON_PMIC_POWER_STATUS1_st_ldo7_en_START (6)
#define COMMON_PMIC_POWER_STATUS1_st_ldo7_en_END (6)
#define COMMON_PMIC_POWER_STATUS1_st_ldo8_en_START (7)
#define COMMON_PMIC_POWER_STATUS1_st_ldo8_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_i2c_spmi_sel : 1;
        unsigned char st_rfic_mode_sel : 1;
        unsigned char st_slave_id_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_SEL_STATUS_UNION;
#endif
#define COMMON_PMIC_SEL_STATUS_st_i2c_spmi_sel_START (0)
#define COMMON_PMIC_SEL_STATUS_st_i2c_spmi_sel_END (0)
#define COMMON_PMIC_SEL_STATUS_st_rfic_mode_sel_START (1)
#define COMMON_PMIC_SEL_STATUS_st_rfic_mode_sel_END (1)
#define COMMON_PMIC_SEL_STATUS_st_slave_id_sel_START (2)
#define COMMON_PMIC_SEL_STATUS_st_slave_id_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_vset : 8;
    } reg;
} COMMON_PMIC_BUCK0_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK0_VSET_b0_vset_START (0)
#define COMMON_PMIC_BUCK0_VSET_b0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b0_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK0_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK0_ONOFF_reg_b0_en_START (0)
#define COMMON_PMIC_BUCK0_ONOFF_reg_b0_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_vset : 8;
    } reg;
} COMMON_PMIC_BUCK1_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK1_VSET_b1_vset_START (0)
#define COMMON_PMIC_BUCK1_VSET_b1_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b1_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK1_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK1_ONOFF_reg_b1_en_START (0)
#define COMMON_PMIC_BUCK1_ONOFF_reg_b1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK2_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK2_VSET_b2_vset_cfg_START (0)
#define COMMON_PMIC_BUCK2_VSET_b2_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b2_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK2_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK2_ONOFF_reg_b2_en_START (0)
#define COMMON_PMIC_BUCK2_ONOFF_reg_b2_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK3_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK3_VSET_b3_vset_cfg_START (0)
#define COMMON_PMIC_BUCK3_VSET_b3_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b3_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK3_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK3_ONOFF_reg_b3_en_START (0)
#define COMMON_PMIC_BUCK3_ONOFF_reg_b3_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO1_VSET_UNION;
#endif
#define COMMON_PMIC_LDO1_VSET_ldo1_vset_START (0)
#define COMMON_PMIC_LDO1_VSET_ldo1_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo1_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO1_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO1_ONOFF_reg_ldo1_en_START (0)
#define COMMON_PMIC_LDO1_ONOFF_reg_ldo1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO2_VSET_UNION;
#endif
#define COMMON_PMIC_LDO2_VSET_ldo2_vset_START (0)
#define COMMON_PMIC_LDO2_VSET_ldo2_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo2_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO2_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO2_ONOFF_reg_ldo2_en_START (0)
#define COMMON_PMIC_LDO2_ONOFF_reg_ldo2_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_vset : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO3_VSET_UNION;
#endif
#define COMMON_PMIC_LDO3_VSET_ldo3_vset_START (0)
#define COMMON_PMIC_LDO3_VSET_ldo3_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo3_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO3_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO3_ONOFF_reg_ldo3_en_START (0)
#define COMMON_PMIC_LDO3_ONOFF_reg_ldo3_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO4_VSET_UNION;
#endif
#define COMMON_PMIC_LDO4_VSET_ldo4_vset_START (0)
#define COMMON_PMIC_LDO4_VSET_ldo4_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo4_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO4_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO4_ONOFF_reg_ldo4_en_START (0)
#define COMMON_PMIC_LDO4_ONOFF_reg_ldo4_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO5_VSET_UNION;
#endif
#define COMMON_PMIC_LDO5_VSET_ldo5_vset_START (0)
#define COMMON_PMIC_LDO5_VSET_ldo5_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo5_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO5_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO5_ONOFF_reg_ldo5_en_START (0)
#define COMMON_PMIC_LDO5_ONOFF_reg_ldo5_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO6_VSET_UNION;
#endif
#define COMMON_PMIC_LDO6_VSET_ldo6_vset_START (0)
#define COMMON_PMIC_LDO6_VSET_ldo6_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo6_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO6_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO6_ONOFF_reg_ldo6_en_START (0)
#define COMMON_PMIC_LDO6_ONOFF_reg_ldo6_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO7_VSET_UNION;
#endif
#define COMMON_PMIC_LDO7_VSET_ldo7_vset_START (0)
#define COMMON_PMIC_LDO7_VSET_ldo7_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo7_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO7_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO7_ONOFF_reg_ldo7_en_START (0)
#define COMMON_PMIC_LDO7_ONOFF_reg_ldo7_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_vset : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO8_VSET_UNION;
#endif
#define COMMON_PMIC_LDO8_VSET_ldo8_vset_START (0)
#define COMMON_PMIC_LDO8_VSET_ldo8_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo8_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO8_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO8_ONOFF_reg_ldo8_en_START (0)
#define COMMON_PMIC_LDO8_ONOFF_reg_ldo8_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_vset : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_PMUH_VSET_UNION;
#endif
#define COMMON_PMIC_PMUH_VSET_pmuh_vset_START (0)
#define COMMON_PMIC_PMUH_VSET_pmuh_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmud_vset : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_PMUD_VSET_UNION;
#endif
#define COMMON_PMIC_PMUD_VSET_pmud_vset_START (0)
#define COMMON_PMIC_PMUD_VSET_pmud_vset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b0_eco_en : 1;
        unsigned char reg_b1_eco_en : 1;
        unsigned char reg_b2_eco_en : 1;
        unsigned char reg_b3_eco_en : 1;
        unsigned char reg_pmuh_eco_en : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_PWR_ECO_ONOFF0_UNION;
#endif
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b0_eco_en_START (0)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b0_eco_en_END (0)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b1_eco_en_START (1)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b1_eco_en_END (1)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b2_eco_en_START (2)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b2_eco_en_END (2)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b3_eco_en_START (3)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b3_eco_en_END (3)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_pmuh_eco_en_START (4)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_pmuh_eco_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo1_eco_en : 1;
        unsigned char reg_ldo2_eco_en : 1;
        unsigned char reg_ldo3_eco_en : 1;
        unsigned char reg_ldo4_eco_en : 1;
        unsigned char reg_ldo5_eco_en : 1;
        unsigned char reg_ldo6_eco_en : 1;
        unsigned char reg_ldo7_eco_en : 1;
        unsigned char reg_ldo8_eco_en : 1;
    } reg;
} COMMON_PMIC_PWR_ECO_ONOFF1_UNION;
#endif
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo1_eco_en_START (0)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo1_eco_en_END (0)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo2_eco_en_START (1)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo2_eco_en_END (1)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo3_eco_en_START (2)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo3_eco_en_END (2)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo4_eco_en_START (3)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo4_eco_en_END (3)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo5_eco_en_START (4)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo5_eco_en_END (4)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo6_eco_en_START (5)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo6_eco_en_END (5)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo7_eco_en_START (6)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo7_eco_en_END (6)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo8_eco_en_START (7)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo8_eco_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char thsd_mode_sel : 1;
        unsigned char thsd_tmp_set : 2;
        unsigned char reg_thsd_en : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BG_THSD_EN_UNION;
#endif
#define COMMON_PMIC_BG_THSD_EN_thsd_mode_sel_START (0)
#define COMMON_PMIC_BG_THSD_EN_thsd_mode_sel_END (0)
#define COMMON_PMIC_BG_THSD_EN_thsd_tmp_set_START (1)
#define COMMON_PMIC_BG_THSD_EN_thsd_tmp_set_END (2)
#define COMMON_PMIC_BG_THSD_EN_reg_thsd_en_START (3)
#define COMMON_PMIC_BG_THSD_EN_reg_thsd_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_lock : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_PMUH_LOCK_UNION;
#endif
#define COMMON_PMIC_PMUH_LOCK_pmuh_lock_START (0)
#define COMMON_PMIC_PMUH_LOCK_pmuh_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ocp_auto_stop : 2;
        unsigned char b1_ocp_auto_stop : 2;
        unsigned char b2_ocp_auto_stop : 2;
        unsigned char b3_ocp_auto_stop : 2;
    } reg;
} COMMON_PMIC_BUCK_OCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b0_ocp_auto_stop_START (0)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b0_ocp_auto_stop_END (1)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b1_ocp_auto_stop_START (2)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b1_ocp_auto_stop_END (3)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b2_ocp_auto_stop_START (4)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b2_ocp_auto_stop_END (5)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b3_ocp_auto_stop_START (6)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b3_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_ocp_auto_stop : 2;
        unsigned char ldo2_ocp_auto_stop : 2;
        unsigned char ldo3_ocp_auto_stop : 2;
        unsigned char ldo4_ocp_auto_stop : 2;
    } reg;
} COMMON_PMIC_LDO_OCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo1_ocp_auto_stop_START (0)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo1_ocp_auto_stop_END (1)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo2_ocp_auto_stop_START (2)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo2_ocp_auto_stop_END (3)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo3_ocp_auto_stop_START (4)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo3_ocp_auto_stop_END (5)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo4_ocp_auto_stop_START (6)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo4_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_ocp_auto_stop : 2;
        unsigned char ldo6_ocp_auto_stop : 2;
        unsigned char ldo7_ocp_auto_stop : 2;
        unsigned char ldo8_ocp_auto_stop : 2;
    } reg;
} COMMON_PMIC_LDO_OCP_MODE_CTRL1_UNION;
#endif
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo5_ocp_auto_stop_START (0)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo5_ocp_auto_stop_END (1)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo6_ocp_auto_stop_START (2)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo6_ocp_auto_stop_END (3)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo7_ocp_auto_stop_START (4)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo7_ocp_auto_stop_END (5)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo8_ocp_auto_stop_START (6)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo8_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_scp_auto_stop : 2;
        unsigned char b1_scp_auto_stop : 2;
        unsigned char b2_scp_auto_stop : 2;
        unsigned char b3_scp_auto_stop : 2;
    } reg;
} COMMON_PMIC_BUCK_SCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b0_scp_auto_stop_START (0)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b0_scp_auto_stop_END (1)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b1_scp_auto_stop_START (2)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b1_scp_auto_stop_END (3)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b2_scp_auto_stop_START (4)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b2_scp_auto_stop_END (5)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b3_scp_auto_stop_START (6)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b3_scp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_ocp_deb_sel : 2;
        unsigned char en_buck_ocp_deb : 1;
        unsigned char ldo_ocp_deb_sel : 2;
        unsigned char en_ldo_ocp_deb : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_OCP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_OCP_DEB_CTRL_buck_ocp_deb_sel_START (0)
#define COMMON_PMIC_OCP_DEB_CTRL_buck_ocp_deb_sel_END (1)
#define COMMON_PMIC_OCP_DEB_CTRL_en_buck_ocp_deb_START (2)
#define COMMON_PMIC_OCP_DEB_CTRL_en_buck_ocp_deb_END (2)
#define COMMON_PMIC_OCP_DEB_CTRL_ldo_ocp_deb_sel_START (3)
#define COMMON_PMIC_OCP_DEB_CTRL_ldo_ocp_deb_sel_END (4)
#define COMMON_PMIC_OCP_DEB_CTRL_en_ldo_ocp_deb_START (5)
#define COMMON_PMIC_OCP_DEB_CTRL_en_ldo_ocp_deb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_scp_deb_sel : 2;
        unsigned char en_buck_scp_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_SCP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_SCP_DEB_CTRL_buck_scp_deb_sel_START (0)
#define COMMON_PMIC_SCP_DEB_CTRL_buck_scp_deb_sel_END (1)
#define COMMON_PMIC_SCP_DEB_CTRL_en_buck_scp_deb_START (2)
#define COMMON_PMIC_SCP_DEB_CTRL_en_buck_scp_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char otmp140_deb_sel : 2;
        unsigned char otmp125_deb_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_OTMP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp140_deb_sel_START (0)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp140_deb_sel_END (1)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp125_deb_sel_START (2)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp125_deb_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char osc_9m6_en_d2a : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_RAMP_CLK_EN_UNION;
#endif
#define COMMON_PMIC_RAMP_CLK_EN_osc_9m6_en_d2a_START (0)
#define COMMON_PMIC_RAMP_CLK_EN_osc_9m6_en_d2a_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ramp_gt_debug : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_RAMP_GT_DEBUG_UNION;
#endif
#define COMMON_PMIC_RAMP_GT_DEBUG_ramp_gt_debug_START (0)
#define COMMON_PMIC_RAMP_GT_DEBUG_ramp_gt_debug_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampdown_ctrl : 3;
        unsigned char b2_rampup_ctrl : 3;
        unsigned char b2_ramp_en_cfg : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_rampdown_ctrl_START (0)
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_rampdown_ctrl_END (2)
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_rampup_ctrl_START (3)
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_rampup_ctrl_END (5)
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_ramp_en_cfg_START (6)
#define COMMON_PMIC_BUCK2_RAMP_CTRL0_b2_ramp_en_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_pull_down_off_cfg : 3;
        unsigned char b2_pull_down_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_CTRL1_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_b2_pull_down_off_cfg_START (0)
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_b2_pull_down_off_cfg_END (2)
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_b2_pull_down_on_cfg_START (3)
#define COMMON_PMIC_BUCK2_RAMP_CTRL1_b2_pull_down_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dly_ru_off_cfg : 3;
        unsigned char b2_dly_ru_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_RAMPUP_STATE_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_b2_dly_ru_off_cfg_START (0)
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_b2_dly_ru_off_cfg_END (2)
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_b2_dly_ru_on_cfg_START (3)
#define COMMON_PMIC_BUCK2_RAMPUP_STATE_b2_dly_ru_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dly_rd_pd_off_cfg : 3;
        unsigned char b2_dly_rd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_RAMPDOWN_STATE_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_b2_dly_rd_pd_off_cfg_START (0)
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_b2_dly_rd_pd_off_cfg_END (2)
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_b2_dly_rd_on_cfg_START (3)
#define COMMON_PMIC_BUCK2_RAMPDOWN_STATE_b2_dly_rd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampdown_chg_rate : 2;
        unsigned char reserved_0 : 2;
        unsigned char b2_rampup_chg_rate : 2;
        unsigned char reserved_1 : 2;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_CHG_RATE_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_b2_rampdown_chg_rate_START (0)
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_b2_rampdown_chg_rate_END (1)
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_b2_rampup_chg_rate_START (4)
#define COMMON_PMIC_BUCK2_RAMP_CHG_RATE_b2_rampup_chg_rate_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char b2_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_CHG_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_b2_rampdown_chg_vset_START (0)
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_b2_rampdown_chg_vset_END (2)
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_b2_rampup_chg_vset_START (4)
#define COMMON_PMIC_BUCK2_RAMP_CHG_VSET_b2_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rd_nochg_rate_sel : 1;
        unsigned char reserved_0 : 3;
        unsigned char b2_ru_nochg_rate_sel : 1;
        unsigned char reserved_1 : 3;
    } reg;
} COMMON_PMIC_BUCK2_CHG_RATE_SEL_UNION;
#endif
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_b2_rd_nochg_rate_sel_START (0)
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_b2_rd_nochg_rate_sel_END (0)
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_b2_ru_nochg_rate_sel_START (4)
#define COMMON_PMIC_BUCK2_CHG_RATE_SEL_b2_ru_nochg_rate_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampdown_ctrl : 3;
        unsigned char b3_rampup_ctrl : 3;
        unsigned char b3_ramp_en_cfg : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_rampdown_ctrl_START (0)
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_rampdown_ctrl_END (2)
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_rampup_ctrl_START (3)
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_rampup_ctrl_END (5)
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_ramp_en_cfg_START (6)
#define COMMON_PMIC_BUCK3_RAMP_CTRL0_b3_ramp_en_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_pull_down_off_cfg : 3;
        unsigned char b3_pull_down_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_CTRL1_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_b3_pull_down_off_cfg_START (0)
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_b3_pull_down_off_cfg_END (2)
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_b3_pull_down_on_cfg_START (3)
#define COMMON_PMIC_BUCK3_RAMP_CTRL1_b3_pull_down_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dly_ru_off_cfg : 3;
        unsigned char b3_dly_ru_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_RAMPUP_STATE_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_b3_dly_ru_off_cfg_START (0)
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_b3_dly_ru_off_cfg_END (2)
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_b3_dly_ru_on_cfg_START (3)
#define COMMON_PMIC_BUCK3_RAMPUP_STATE_b3_dly_ru_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dly_rd_pd_off_cfg : 3;
        unsigned char b3_dly_rd_on_cfg : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_RAMPDOWN_STATE_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_b3_dly_rd_pd_off_cfg_START (0)
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_b3_dly_rd_pd_off_cfg_END (2)
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_b3_dly_rd_on_cfg_START (3)
#define COMMON_PMIC_BUCK3_RAMPDOWN_STATE_b3_dly_rd_on_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampdown_chg_rate : 2;
        unsigned char reserved_0 : 2;
        unsigned char b3_rampup_chg_rate : 2;
        unsigned char reserved_1 : 2;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_CHG_RATE_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_b3_rampdown_chg_rate_START (0)
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_b3_rampdown_chg_rate_END (1)
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_b3_rampup_chg_rate_START (4)
#define COMMON_PMIC_BUCK3_RAMP_CHG_RATE_b3_rampup_chg_rate_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampdown_chg_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char b3_rampup_chg_vset : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_CHG_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_b3_rampdown_chg_vset_START (0)
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_b3_rampdown_chg_vset_END (2)
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_b3_rampup_chg_vset_START (4)
#define COMMON_PMIC_BUCK3_RAMP_CHG_VSET_b3_rampup_chg_vset_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rd_nochg_rate_sel : 1;
        unsigned char reserved_0 : 3;
        unsigned char b3_ru_nochg_rate_sel : 1;
        unsigned char reserved_1 : 3;
    } reg;
} COMMON_PMIC_BUCK3_CHG_RATE_SEL_UNION;
#endif
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_b3_rd_nochg_rate_sel_START (0)
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_b3_rd_nochg_rate_sel_END (0)
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_b3_ru_nochg_rate_sel_START (4)
#define COMMON_PMIC_BUCK3_CHG_RATE_SEL_b3_ru_nochg_rate_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_data : 8;
    } reg;
} COMMON_PMIC_EFUSE_DATA_UNION;
#endif
#define COMMON_PMIC_EFUSE_DATA_efuse_data_START (0)
#define COMMON_PMIC_EFUSE_DATA_efuse_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_clk_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_CLK_GT_EN_UNION;
#endif
#define COMMON_PMIC_EFUSE_CLK_GT_EN_sc_efuse_clk_en_START (0)
#define COMMON_PMIC_EFUSE_CLK_GT_EN_sc_efuse_clk_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_aen_lock : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_TRIM_SEL_UNION;
#endif
#define COMMON_PMIC_EFUSE_TRIM_SEL_sc_efuse_aen_lock_START (0)
#define COMMON_PMIC_EFUSE_TRIM_SEL_sc_efuse_aen_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_inctrl_sel : 1;
        unsigned char sc_efuse_prog_sel : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_EFUSE_CFG_0_UNION;
#endif
#define COMMON_PMIC_EFUSE_CFG_0_sc_efuse_inctrl_sel_START (0)
#define COMMON_PMIC_EFUSE_CFG_0_sc_efuse_inctrl_sel_END (0)
#define COMMON_PMIC_EFUSE_CFG_0_sc_efuse_prog_sel_START (1)
#define COMMON_PMIC_EFUSE_CFG_0_sc_efuse_prog_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_aen : 1;
        unsigned char sc_efuse_pgmen : 1;
        unsigned char sc_efuse_rden : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_EFUSE_CFG_1_UNION;
#endif
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_aen_START (0)
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_aen_END (0)
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_pgmen_START (1)
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_pgmen_END (1)
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_rden_START (2)
#define COMMON_PMIC_EFUSE_CFG_1_sc_efuse_rden_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_addrl : 8;
    } reg;
} COMMON_PMIC_EFUSE_CFG_2_UNION;
#endif
#define COMMON_PMIC_EFUSE_CFG_2_sc_efuse_addrl_START (0)
#define COMMON_PMIC_EFUSE_CFG_2_sc_efuse_addrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_addrh : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_CFG_3_UNION;
#endif
#define COMMON_PMIC_EFUSE_CFG_3_sc_efuse_addrh_START (0)
#define COMMON_PMIC_EFUSE_CFG_3_sc_efuse_addrh_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_loop_read : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_AUTO_RD_UNION;
#endif
#define COMMON_PMIC_EFUSE_AUTO_RD_sc_efuse_loop_read_START (0)
#define COMMON_PMIC_EFUSE_AUTO_RD_sc_efuse_loop_read_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_rdata : 8;
    } reg;
} COMMON_PMIC_EFUSE_RDATA_UNION;
#endif
#define COMMON_PMIC_EFUSE_RDATA_efuse_rdata_START (0)
#define COMMON_PMIC_EFUSE_RDATA_efuse_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob13_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_13_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_13_W_efuse_pdob13_w_START (0)
#define COMMON_PMIC_EFUSE_13_W_efuse_pdob13_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob16_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_16_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_16_W_efuse_pdob16_w_START (0)
#define COMMON_PMIC_EFUSE_16_W_efuse_pdob16_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob17_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_17_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_17_W_efuse_pdob17_w_START (0)
#define COMMON_PMIC_EFUSE_17_W_efuse_pdob17_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob18_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_18_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_18_W_efuse_pdob18_w_START (0)
#define COMMON_PMIC_EFUSE_18_W_efuse_pdob18_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob19_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_19_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_19_W_efuse_pdob19_w_START (0)
#define COMMON_PMIC_EFUSE_19_W_efuse_pdob19_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob20_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_20_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_20_W_efuse_pdob20_w_START (0)
#define COMMON_PMIC_EFUSE_20_W_efuse_pdob20_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob21_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_21_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_21_W_efuse_pdob21_w_START (0)
#define COMMON_PMIC_EFUSE_21_W_efuse_pdob21_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob22_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_22_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_22_W_efuse_pdob22_w_START (0)
#define COMMON_PMIC_EFUSE_22_W_efuse_pdob22_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob23_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_23_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_23_W_efuse_pdob23_w_START (0)
#define COMMON_PMIC_EFUSE_23_W_efuse_pdob23_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob24_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_24_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_24_W_efuse_pdob24_w_START (0)
#define COMMON_PMIC_EFUSE_24_W_efuse_pdob24_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob25_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_25_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_25_W_efuse_pdob25_w_START (0)
#define COMMON_PMIC_EFUSE_25_W_efuse_pdob25_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob26_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_26_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_26_W_efuse_pdob26_w_START (0)
#define COMMON_PMIC_EFUSE_26_W_efuse_pdob26_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob27_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_27_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_27_W_efuse_pdob27_w_START (0)
#define COMMON_PMIC_EFUSE_27_W_efuse_pdob27_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob28_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_28_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_28_W_efuse_pdob28_w_START (0)
#define COMMON_PMIC_EFUSE_28_W_efuse_pdob28_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob29_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_29_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_29_W_efuse_pdob29_w_START (0)
#define COMMON_PMIC_EFUSE_29_W_efuse_pdob29_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob30_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_30_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_30_W_efuse_pdob30_w_START (0)
#define COMMON_PMIC_EFUSE_30_W_efuse_pdob30_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob31_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_31_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_31_W_efuse_pdob31_w_START (0)
#define COMMON_PMIC_EFUSE_31_W_efuse_pdob31_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob32_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_32_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_32_W_efuse_pdob32_w_START (0)
#define COMMON_PMIC_EFUSE_32_W_efuse_pdob32_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob33_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_33_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_33_W_efuse_pdob33_w_START (0)
#define COMMON_PMIC_EFUSE_33_W_efuse_pdob33_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob34_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_34_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_34_W_efuse_pdob34_w_START (0)
#define COMMON_PMIC_EFUSE_34_W_efuse_pdob34_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob35_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_35_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_35_W_efuse_pdob35_w_START (0)
#define COMMON_PMIC_EFUSE_35_W_efuse_pdob35_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob36_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_36_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_36_W_efuse_pdob36_w_START (0)
#define COMMON_PMIC_EFUSE_36_W_efuse_pdob36_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob37_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_37_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_37_W_efuse_pdob37_w_START (0)
#define COMMON_PMIC_EFUSE_37_W_efuse_pdob37_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob38_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_38_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_38_W_efuse_pdob38_w_START (0)
#define COMMON_PMIC_EFUSE_38_W_efuse_pdob38_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob39_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_39_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_39_W_efuse_pdob39_w_START (0)
#define COMMON_PMIC_EFUSE_39_W_efuse_pdob39_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob40_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_40_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_40_W_efuse_pdob40_w_START (0)
#define COMMON_PMIC_EFUSE_40_W_efuse_pdob40_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob41_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_41_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_41_W_efuse_pdob41_w_START (0)
#define COMMON_PMIC_EFUSE_41_W_efuse_pdob41_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob42_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_42_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_42_W_efuse_pdob42_w_START (0)
#define COMMON_PMIC_EFUSE_42_W_efuse_pdob42_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob43_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_43_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_43_W_efuse_pdob43_w_START (0)
#define COMMON_PMIC_EFUSE_43_W_efuse_pdob43_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob44_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_44_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_44_W_efuse_pdob44_w_START (0)
#define COMMON_PMIC_EFUSE_44_W_efuse_pdob44_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob45_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_45_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_45_W_efuse_pdob45_w_START (0)
#define COMMON_PMIC_EFUSE_45_W_efuse_pdob45_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob46_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_46_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_46_W_efuse_pdob46_w_START (0)
#define COMMON_PMIC_EFUSE_46_W_efuse_pdob46_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_pdob47_w : 8;
    } reg;
} COMMON_PMIC_EFUSE_47_W_UNION;
#endif
#define COMMON_PMIC_EFUSE_47_W_efuse_pdob47_w_START (0)
#define COMMON_PMIC_EFUSE_47_W_efuse_pdob47_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b0_ocp_mk : 1;
        unsigned char irq_b1_ocp_mk : 1;
        unsigned char irq_b2_ocp_mk : 1;
        unsigned char irq_b3_ocp_mk : 1;
        unsigned char irq_pmuh_ocp_mk : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_IRQ_OCP_MASK0_UNION;
#endif
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b0_ocp_mk_START (0)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b0_ocp_mk_END (0)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b1_ocp_mk_START (1)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b1_ocp_mk_END (1)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b2_ocp_mk_START (2)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b2_ocp_mk_END (2)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b3_ocp_mk_START (3)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_b3_ocp_mk_END (3)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_pmuh_ocp_mk_START (4)
#define COMMON_PMIC_IRQ_OCP_MASK0_irq_pmuh_ocp_mk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ldo1_ocp_mk : 1;
        unsigned char irq_ldo2_ocp_mk : 1;
        unsigned char irq_ldo3_ocp_mk : 1;
        unsigned char irq_ldo4_ocp_mk : 1;
        unsigned char irq_ldo5_ocp_mk : 1;
        unsigned char irq_ldo6_ocp_mk : 1;
        unsigned char irq_ldo7_ocp_mk : 1;
        unsigned char irq_ldo8_ocp_mk : 1;
    } reg;
} COMMON_PMIC_IRQ_OCP_MASK1_UNION;
#endif
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo1_ocp_mk_START (0)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo1_ocp_mk_END (0)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo2_ocp_mk_START (1)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo2_ocp_mk_END (1)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo3_ocp_mk_START (2)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo3_ocp_mk_END (2)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo4_ocp_mk_START (3)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo4_ocp_mk_END (3)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo5_ocp_mk_START (4)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo5_ocp_mk_END (4)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo6_ocp_mk_START (5)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo6_ocp_mk_END (5)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo7_ocp_mk_START (6)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo7_ocp_mk_END (6)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo8_ocp_mk_START (7)
#define COMMON_PMIC_IRQ_OCP_MASK1_irq_ldo8_ocp_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b0_scp_mk : 1;
        unsigned char irq_b1_scp_mk : 1;
        unsigned char irq_b2_scp_mk : 1;
        unsigned char irq_b3_scp_mk : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ_SCP_MASK0_UNION;
#endif
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b0_scp_mk_START (0)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b0_scp_mk_END (0)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b1_scp_mk_START (1)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b1_scp_mk_END (1)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b2_scp_mk_START (2)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b2_scp_mk_END (2)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b3_scp_mk_START (3)
#define COMMON_PMIC_IRQ_SCP_MASK0_irq_b3_scp_mk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_thsd_otmp125_d120ur_mk : 1;
        unsigned char irq_thsd_otmp140_d180ur_mk : 1;
        unsigned char irq_vsys_pwroff_abs_mk : 1;
        unsigned char irq_vsys_ov_d200ur_mk : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ_MASK_0_UNION;
#endif
#define COMMON_PMIC_IRQ_MASK_0_irq_thsd_otmp125_d120ur_mk_START (0)
#define COMMON_PMIC_IRQ_MASK_0_irq_thsd_otmp125_d120ur_mk_END (0)
#define COMMON_PMIC_IRQ_MASK_0_irq_thsd_otmp140_d180ur_mk_START (1)
#define COMMON_PMIC_IRQ_MASK_0_irq_thsd_otmp140_d180ur_mk_END (1)
#define COMMON_PMIC_IRQ_MASK_0_irq_vsys_pwroff_abs_mk_START (2)
#define COMMON_PMIC_IRQ_MASK_0_irq_vsys_pwroff_abs_mk_END (2)
#define COMMON_PMIC_IRQ_MASK_0_irq_vsys_ov_d200ur_mk_START (3)
#define COMMON_PMIC_IRQ_MASK_0_irq_vsys_ov_d200ur_mk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b0_ocp : 1;
        unsigned char irq_b1_ocp : 1;
        unsigned char irq_b2_ocp : 1;
        unsigned char irq_b3_ocp : 1;
        unsigned char irq_pmuh_ocp : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_IRQ_OCP0_UNION;
#endif
#define COMMON_PMIC_IRQ_OCP0_irq_b0_ocp_START (0)
#define COMMON_PMIC_IRQ_OCP0_irq_b0_ocp_END (0)
#define COMMON_PMIC_IRQ_OCP0_irq_b1_ocp_START (1)
#define COMMON_PMIC_IRQ_OCP0_irq_b1_ocp_END (1)
#define COMMON_PMIC_IRQ_OCP0_irq_b2_ocp_START (2)
#define COMMON_PMIC_IRQ_OCP0_irq_b2_ocp_END (2)
#define COMMON_PMIC_IRQ_OCP0_irq_b3_ocp_START (3)
#define COMMON_PMIC_IRQ_OCP0_irq_b3_ocp_END (3)
#define COMMON_PMIC_IRQ_OCP0_irq_pmuh_ocp_START (4)
#define COMMON_PMIC_IRQ_OCP0_irq_pmuh_ocp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ldo1_ocp : 1;
        unsigned char irq_ldo2_ocp : 1;
        unsigned char irq_ldo3_ocp : 1;
        unsigned char irq_ldo4_ocp : 1;
        unsigned char irq_ldo5_ocp : 1;
        unsigned char irq_ldo6_ocp : 1;
        unsigned char irq_ldo7_ocp : 1;
        unsigned char irq_ldo8_ocp : 1;
    } reg;
} COMMON_PMIC_IRQ_OCP1_UNION;
#endif
#define COMMON_PMIC_IRQ_OCP1_irq_ldo1_ocp_START (0)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo1_ocp_END (0)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo2_ocp_START (1)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo2_ocp_END (1)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo3_ocp_START (2)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo3_ocp_END (2)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo4_ocp_START (3)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo4_ocp_END (3)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo5_ocp_START (4)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo5_ocp_END (4)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo6_ocp_START (5)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo6_ocp_END (5)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo7_ocp_START (6)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo7_ocp_END (6)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo8_ocp_START (7)
#define COMMON_PMIC_IRQ_OCP1_irq_ldo8_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b0_scp : 1;
        unsigned char irq_b1_scp : 1;
        unsigned char irq_b2_scp : 1;
        unsigned char irq_b3_scp : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ_SCP0_UNION;
#endif
#define COMMON_PMIC_IRQ_SCP0_irq_b0_scp_START (0)
#define COMMON_PMIC_IRQ_SCP0_irq_b0_scp_END (0)
#define COMMON_PMIC_IRQ_SCP0_irq_b1_scp_START (1)
#define COMMON_PMIC_IRQ_SCP0_irq_b1_scp_END (1)
#define COMMON_PMIC_IRQ_SCP0_irq_b2_scp_START (2)
#define COMMON_PMIC_IRQ_SCP0_irq_b2_scp_END (2)
#define COMMON_PMIC_IRQ_SCP0_irq_b3_scp_START (3)
#define COMMON_PMIC_IRQ_SCP0_irq_b3_scp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_thsd_otmp125_d120ur : 1;
        unsigned char irq_thsd_otmp140_d180ur : 1;
        unsigned char irq_vsys_pwroff_abs : 1;
        unsigned char irq_vsys_ov_d200ur : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ0_SYS_UNION;
#endif
#define COMMON_PMIC_IRQ0_SYS_irq_thsd_otmp125_d120ur_START (0)
#define COMMON_PMIC_IRQ0_SYS_irq_thsd_otmp125_d120ur_END (0)
#define COMMON_PMIC_IRQ0_SYS_irq_thsd_otmp140_d180ur_START (1)
#define COMMON_PMIC_IRQ0_SYS_irq_thsd_otmp140_d180ur_END (1)
#define COMMON_PMIC_IRQ0_SYS_irq_vsys_pwroff_abs_START (2)
#define COMMON_PMIC_IRQ0_SYS_irq_vsys_pwroff_abs_END (2)
#define COMMON_PMIC_IRQ0_SYS_irq_vsys_ov_d200ur_START (3)
#define COMMON_PMIC_IRQ0_SYS_irq_vsys_ov_d200ur_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b0_ocp : 1;
        unsigned char np_b1_ocp : 1;
        unsigned char np_b2_ocp : 1;
        unsigned char np_b3_ocp : 1;
        unsigned char np_pmuh_ocp : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_NP_OCP0_UNION;
#endif
#define COMMON_PMIC_NP_OCP0_np_b0_ocp_START (0)
#define COMMON_PMIC_NP_OCP0_np_b0_ocp_END (0)
#define COMMON_PMIC_NP_OCP0_np_b1_ocp_START (1)
#define COMMON_PMIC_NP_OCP0_np_b1_ocp_END (1)
#define COMMON_PMIC_NP_OCP0_np_b2_ocp_START (2)
#define COMMON_PMIC_NP_OCP0_np_b2_ocp_END (2)
#define COMMON_PMIC_NP_OCP0_np_b3_ocp_START (3)
#define COMMON_PMIC_NP_OCP0_np_b3_ocp_END (3)
#define COMMON_PMIC_NP_OCP0_np_pmuh_ocp_START (4)
#define COMMON_PMIC_NP_OCP0_np_pmuh_ocp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo1_ocp : 1;
        unsigned char np_ldo2_ocp : 1;
        unsigned char np_ldo3_ocp : 1;
        unsigned char np_ldo4_ocp : 1;
        unsigned char np_ldo5_ocp : 1;
        unsigned char np_ldo6_ocp : 1;
        unsigned char np_ldo7_ocp : 1;
        unsigned char np_ldo8_ocp : 1;
    } reg;
} COMMON_PMIC_NP_OCP1_UNION;
#endif
#define COMMON_PMIC_NP_OCP1_np_ldo1_ocp_START (0)
#define COMMON_PMIC_NP_OCP1_np_ldo1_ocp_END (0)
#define COMMON_PMIC_NP_OCP1_np_ldo2_ocp_START (1)
#define COMMON_PMIC_NP_OCP1_np_ldo2_ocp_END (1)
#define COMMON_PMIC_NP_OCP1_np_ldo3_ocp_START (2)
#define COMMON_PMIC_NP_OCP1_np_ldo3_ocp_END (2)
#define COMMON_PMIC_NP_OCP1_np_ldo4_ocp_START (3)
#define COMMON_PMIC_NP_OCP1_np_ldo4_ocp_END (3)
#define COMMON_PMIC_NP_OCP1_np_ldo5_ocp_START (4)
#define COMMON_PMIC_NP_OCP1_np_ldo5_ocp_END (4)
#define COMMON_PMIC_NP_OCP1_np_ldo6_ocp_START (5)
#define COMMON_PMIC_NP_OCP1_np_ldo6_ocp_END (5)
#define COMMON_PMIC_NP_OCP1_np_ldo7_ocp_START (6)
#define COMMON_PMIC_NP_OCP1_np_ldo7_ocp_END (6)
#define COMMON_PMIC_NP_OCP1_np_ldo8_ocp_START (7)
#define COMMON_PMIC_NP_OCP1_np_ldo8_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b0_scp : 1;
        unsigned char np_b1_scp : 1;
        unsigned char np_b2_scp : 1;
        unsigned char np_b3_scp : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_SCP0_UNION;
#endif
#define COMMON_PMIC_NP_SCP0_np_b0_scp_START (0)
#define COMMON_PMIC_NP_SCP0_np_b0_scp_END (0)
#define COMMON_PMIC_NP_SCP0_np_b1_scp_START (1)
#define COMMON_PMIC_NP_SCP0_np_b1_scp_END (1)
#define COMMON_PMIC_NP_SCP0_np_b2_scp_START (2)
#define COMMON_PMIC_NP_SCP0_np_b2_scp_END (2)
#define COMMON_PMIC_NP_SCP0_np_b3_scp_START (3)
#define COMMON_PMIC_NP_SCP0_np_b3_scp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reserved_0 : 1;
        unsigned char np_b2_ramp_chg : 1;
        unsigned char np_b3_ramp_chg : 1;
        unsigned char reserved_1 : 5;
    } reg;
} COMMON_PMIC_RAMP_EVENT0_UNION;
#endif
#define COMMON_PMIC_RAMP_EVENT0_np_b2_ramp_chg_START (1)
#define COMMON_PMIC_RAMP_EVENT0_np_b2_ramp_chg_END (1)
#define COMMON_PMIC_RAMP_EVENT0_np_b3_ramp_chg_START (2)
#define COMMON_PMIC_RAMP_EVENT0_np_b3_ramp_chg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reserved_0 : 1;
        unsigned char np_b2_ramp_abnor : 1;
        unsigned char np_b3_ramp_abnor : 1;
        unsigned char reserved_1 : 5;
    } reg;
} COMMON_PMIC_RAMP_EVENT1_UNION;
#endif
#define COMMON_PMIC_RAMP_EVENT1_np_b2_ramp_abnor_START (1)
#define COMMON_PMIC_RAMP_EVENT1_np_b2_ramp_abnor_END (1)
#define COMMON_PMIC_RAMP_EVENT1_np_b3_ramp_abnor_START (2)
#define COMMON_PMIC_RAMP_EVENT1_np_b3_ramp_abnor_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_thsd_otmp125_d120ur : 1;
        unsigned char np_thsd_otmp140_d180ur : 1;
        unsigned char np_vsys_pwroff_abs_d20nr : 1;
        unsigned char np_vsys_ov_d200ur : 1;
        unsigned char np_pmuh_short_f : 1;
        unsigned char np_pmud_short_f : 1;
        unsigned char np_core_io_vld_f : 1;
        unsigned char np_hreset_n_d300uf : 1;
    } reg;
} COMMON_PMIC_NP_SYS_EVENT0_UNION;
#endif
#define COMMON_PMIC_NP_SYS_EVENT0_np_thsd_otmp125_d120ur_START (0)
#define COMMON_PMIC_NP_SYS_EVENT0_np_thsd_otmp125_d120ur_END (0)
#define COMMON_PMIC_NP_SYS_EVENT0_np_thsd_otmp140_d180ur_START (1)
#define COMMON_PMIC_NP_SYS_EVENT0_np_thsd_otmp140_d180ur_END (1)
#define COMMON_PMIC_NP_SYS_EVENT0_np_vsys_pwroff_abs_d20nr_START (2)
#define COMMON_PMIC_NP_SYS_EVENT0_np_vsys_pwroff_abs_d20nr_END (2)
#define COMMON_PMIC_NP_SYS_EVENT0_np_vsys_ov_d200ur_START (3)
#define COMMON_PMIC_NP_SYS_EVENT0_np_vsys_ov_d200ur_END (3)
#define COMMON_PMIC_NP_SYS_EVENT0_np_pmuh_short_f_START (4)
#define COMMON_PMIC_NP_SYS_EVENT0_np_pmuh_short_f_END (4)
#define COMMON_PMIC_NP_SYS_EVENT0_np_pmud_short_f_START (5)
#define COMMON_PMIC_NP_SYS_EVENT0_np_pmud_short_f_END (5)
#define COMMON_PMIC_NP_SYS_EVENT0_np_core_io_vld_f_START (6)
#define COMMON_PMIC_NP_SYS_EVENT0_np_core_io_vld_f_END (6)
#define COMMON_PMIC_NP_SYS_EVENT0_np_hreset_n_d300uf_START (7)
#define COMMON_PMIC_NP_SYS_EVENT0_np_hreset_n_d300uf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_en_off : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_NP_SYS_EVENT1_UNION;
#endif
#define COMMON_PMIC_NP_SYS_EVENT1_np_pmu_en_off_START (0)
#define COMMON_PMIC_NP_SYS_EVENT1_np_pmu_en_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char soft_rst_n : 8;
    } reg;
} COMMON_PMIC_PMU_SOFT_RST_UNION;
#endif
#define COMMON_PMIC_PMU_SOFT_RST_soft_rst_n_START (0)
#define COMMON_PMIC_PMU_SOFT_RST_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_pwroff_abs_pd_mask : 1;
        unsigned char np_thsd_otmp140_pd_mask : 1;
        unsigned char np_vsys_ov_pd_mask : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_PD_MASK_UNION;
#endif
#define COMMON_PMIC_NP_PD_MASK_np_vsys_pwroff_abs_pd_mask_START (0)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_pwroff_abs_pd_mask_END (0)
#define COMMON_PMIC_NP_PD_MASK_np_thsd_otmp140_pd_mask_START (1)
#define COMMON_PMIC_NP_PD_MASK_np_thsd_otmp140_pd_mask_END (1)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_ov_pd_mask_START (2)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_ov_pd_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_abnor_mask_deb_sel : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_PWRUP_DLY_CTRL_UNION;
#endif
#define COMMON_PMIC_NP_PWRUP_DLY_CTRL_np_abnor_mask_deb_sel_START (0)
#define COMMON_PMIC_NP_PWRUP_DLY_CTRL_np_abnor_mask_deb_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_en_deb_sel : 3;
        unsigned char np_en_pmu_en_deb : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_PWRUP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_np_pmu_en_deb_sel_START (0)
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_np_pmu_en_deb_sel_END (2)
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_np_en_pmu_en_deb_START (3)
#define COMMON_PMIC_NP_PWRUP_DEB_CTRL_np_en_pmu_en_deb_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_rc_clk_en_n : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_NP_RC256K_CTRL_UNION;
#endif
#define COMMON_PMIC_NP_RC256K_CTRL_np_rc_clk_en_n_START (0)
#define COMMON_PMIC_NP_RC256K_CTRL_np_rc_clk_en_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_spmi_data_ds : 2;
        unsigned char np_spmi_data_ds_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_DATA_IO_DS0_UNION;
#endif
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_START (0)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_END (1)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_sel_START (2)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_irq_n_ds : 2;
        unsigned char reserved_0 : 2;
        unsigned char np_sys_rst_n_ds : 2;
        unsigned char reserved_1 : 2;
    } reg;
} COMMON_PMIC_NP_DATA_IO_DS1_UNION;
#endif
#define COMMON_PMIC_NP_DATA_IO_DS1_np_pmu_irq_n_ds_START (0)
#define COMMON_PMIC_NP_DATA_IO_DS1_np_pmu_irq_n_ds_END (1)
#define COMMON_PMIC_NP_DATA_IO_DS1_np_sys_rst_n_ds_START (4)
#define COMMON_PMIC_NP_DATA_IO_DS1_np_sys_rst_n_ds_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_read_mux : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_EFUSE_READ_SEL_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE_READ_SEL_np_efuse_read_mux_START (0)
#define COMMON_PMIC_NP_EFUSE_READ_SEL_np_efuse_read_mux_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_atest_sel : 8;
    } reg;
} COMMON_PMIC_NP_ATEST_SEL_UNION;
#endif
#define COMMON_PMIC_NP_ATEST_SEL_np_atest_sel_START (0)
#define COMMON_PMIC_NP_ATEST_SEL_np_atest_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_pwroff_abs_set : 2;
        unsigned char np_vsys_ov_set : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_SYS_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_pwroff_abs_set_START (0)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_pwroff_abs_set_END (1)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_ov_set_START (2)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_ov_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmud_switch_set : 2;
        unsigned char np_pmud_res_sel : 2;
        unsigned char np_pmud_buck_en : 1;
        unsigned char np_pmud_vsys_ctrl : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_PMUD_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_switch_set_START (0)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_switch_set_END (1)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_res_sel_START (2)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_res_sel_END (3)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_buck_en_START (4)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_buck_en_END (4)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_vsys_ctrl_START (5)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_vsys_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmud_ib_set : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_PMUD_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_PMUD_CTRL1_np_pmud_ib_set_START (0)
#define COMMON_PMIC_NP_PMUD_CTRL1_np_pmud_ib_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_BANDGAP_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BANDGAP_CTRL0_np_ref_reserve0_START (0)
#define COMMON_PMIC_NP_BANDGAP_CTRL0_np_ref_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_BANDGAP_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BANDGAP_CTRL1_np_ref_reserve1_START (0)
#define COMMON_PMIC_NP_BANDGAP_CTRL1_np_ref_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_cot_rlx : 1;
        unsigned char np_b2_adj_rlx : 4;
        unsigned char np_b2_adj_clx : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_NP_BUCK2_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_cot_rlx_START (0)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_cot_rlx_END (0)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_adj_rlx_START (1)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_adj_rlx_END (4)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_adj_clx_START (5)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_adj_clx_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_reg_ibias : 1;
        unsigned char np_b2_reg_en : 1;
        unsigned char np_b2_reg_dr : 3;
        unsigned char np_b2_pulldn_pd_en : 1;
        unsigned char np_b2_offres_sel : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_NP_BUCK2_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_ibias_START (0)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_ibias_END (0)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_en_START (1)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_en_END (1)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_dr_START (2)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_reg_dr_END (4)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_pulldn_pd_en_START (5)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_pulldn_pd_en_END (5)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_offres_sel_START (6)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_offres_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_fb_cap_sel : 1;
        unsigned char np_b2_reg_op_c : 1;
        unsigned char np_b2_reg_r : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_BUCK2_CTRL2_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_fb_cap_sel_START (0)
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_fb_cap_sel_END (0)
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_reg_op_c_START (1)
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_reg_op_c_END (1)
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_reg_r_START (2)
#define COMMON_PMIC_NP_BUCK2_CTRL2_np_b2_reg_r_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_cot_rlx : 1;
        unsigned char np_b3_adj_rlx : 4;
        unsigned char np_b3_adj_clx : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_NP_BUCK3_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_cot_rlx_START (0)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_cot_rlx_END (0)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_adj_rlx_START (1)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_adj_rlx_END (4)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_adj_clx_START (5)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_adj_clx_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_reg_ibias : 1;
        unsigned char np_b3_reg_en : 1;
        unsigned char np_b3_reg_dr : 3;
        unsigned char np_b3_pulldn_pd_en : 1;
        unsigned char np_b3_offres_sel : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_NP_BUCK3_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_ibias_START (0)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_ibias_END (0)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_en_START (1)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_en_END (1)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_dr_START (2)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_reg_dr_END (4)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_pulldn_pd_en_START (5)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_pulldn_pd_en_END (5)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_offres_sel_START (6)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_offres_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_fb_cap_sel : 1;
        unsigned char np_b3_reg_op_c : 1;
        unsigned char np_b3_reg_r : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_BUCK3_CTRL2_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_fb_cap_sel_START (0)
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_fb_cap_sel_END (0)
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_reg_op_c_START (1)
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_reg_op_c_END (1)
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_reg_r_START (2)
#define COMMON_PMIC_NP_BUCK3_CTRL2_np_b3_reg_r_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_LDO_RESERVE0_UNION;
#endif
#define COMMON_PMIC_NP_LDO_RESERVE0_np_ldo_reserve0_START (0)
#define COMMON_PMIC_NP_LDO_RESERVE0_np_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_LDO_RESERVE1_UNION;
#endif
#define COMMON_PMIC_NP_LDO_RESERVE1_np_ldo_reserve1_START (0)
#define COMMON_PMIC_NP_LDO_RESERVE1_np_ldo_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES0_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES0_np_d2a_reserve0_START (0)
#define COMMON_PMIC_NP_D2A_RES0_np_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES1_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES1_np_d2a_reserve1_START (0)
#define COMMON_PMIC_NP_D2A_RES1_np_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve2 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES2_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES2_np_d2a_reserve2_START (0)
#define COMMON_PMIC_NP_D2A_RES2_np_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve3 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES3_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES3_np_d2a_reserve3_START (0)
#define COMMON_PMIC_NP_D2A_RES3_np_d2a_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve4 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES4_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES4_np_d2a_reserve4_START (0)
#define COMMON_PMIC_NP_D2A_RES4_np_d2a_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_debug_lock : 8;
    } reg;
} COMMON_PMIC_DEBUG_LOCK_UNION;
#endif
#define COMMON_PMIC_DEBUG_LOCK_np_debug_lock_START (0)
#define COMMON_PMIC_DEBUG_LOCK_np_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_sys_debug0 : 8;
    } reg;
} COMMON_PMIC_SYS_DEBUG0_UNION;
#endif
#define COMMON_PMIC_SYS_DEBUG0_np_sys_debug0_START (0)
#define COMMON_PMIC_SYS_DEBUG0_np_sys_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_sys_debug1 : 8;
    } reg;
} COMMON_PMIC_SYS_DEBUG1_UNION;
#endif
#define COMMON_PMIC_SYS_DEBUG1_np_sys_debug1_START (0)
#define COMMON_PMIC_SYS_DEBUG1_np_sys_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg0 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG0_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG0_np_hrst_reg0_START (0)
#define COMMON_PMIC_NP_HRST_REG0_np_hrst_reg0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg1 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG1_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG1_np_hrst_reg1_START (0)
#define COMMON_PMIC_NP_HRST_REG1_np_hrst_reg1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg2 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG2_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG2_np_hrst_reg2_START (0)
#define COMMON_PMIC_NP_HRST_REG2_np_hrst_reg2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg3 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG3_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG3_np_hrst_reg3_START (0)
#define COMMON_PMIC_NP_HRST_REG3_np_hrst_reg3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_ibias_sel : 1;
        unsigned char ref_eco_shield : 1;
        unsigned char ref_eco_en : 1;
        unsigned char ref_chop_sel : 1;
        unsigned char ref_chop_clk_sel : 2;
        unsigned char ref_bg_test : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BANDGAP_CFG0_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG0_ref_ibias_sel_START (0)
#define COMMON_PMIC_BANDGAP_CFG0_ref_ibias_sel_END (0)
#define COMMON_PMIC_BANDGAP_CFG0_ref_eco_shield_START (1)
#define COMMON_PMIC_BANDGAP_CFG0_ref_eco_shield_END (1)
#define COMMON_PMIC_BANDGAP_CFG0_ref_eco_en_START (2)
#define COMMON_PMIC_BANDGAP_CFG0_ref_eco_en_END (2)
#define COMMON_PMIC_BANDGAP_CFG0_ref_chop_sel_START (3)
#define COMMON_PMIC_BANDGAP_CFG0_ref_chop_sel_END (3)
#define COMMON_PMIC_BANDGAP_CFG0_ref_chop_clk_sel_START (4)
#define COMMON_PMIC_BANDGAP_CFG0_ref_chop_clk_sel_END (5)
#define COMMON_PMIC_BANDGAP_CFG0_ref_bg_test_START (6)
#define COMMON_PMIC_BANDGAP_CFG0_ref_bg_test_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_ibias_trim_en : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BANDGAP_CFG1_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG1_ref_ibias_trim_en_START (0)
#define COMMON_PMIC_BANDGAP_CFG1_ref_ibias_trim_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve0 : 8;
    } reg;
} COMMON_PMIC_BANDGAP_CFG2_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG2_ref_reserve0_START (0)
#define COMMON_PMIC_BANDGAP_CFG2_ref_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve1 : 8;
    } reg;
} COMMON_PMIC_BANDGAP_CFG3_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG3_ref_reserve1_START (0)
#define COMMON_PMIC_BANDGAP_CFG3_ref_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve2 : 8;
    } reg;
} COMMON_PMIC_BANDGAP_CFG4_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG4_ref_reserve2_START (0)
#define COMMON_PMIC_BANDGAP_CFG4_ref_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve3 : 8;
    } reg;
} COMMON_PMIC_BANDGAP_CFG5_UNION;
#endif
#define COMMON_PMIC_BANDGAP_CFG5_ref_reserve3_START (0)
#define COMMON_PMIC_BANDGAP_CFG5_ref_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char osc_9m6_sel : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_OSC_9M6_CFG0_UNION;
#endif
#define COMMON_PMIC_OSC_9M6_CFG0_osc_9m6_sel_START (0)
#define COMMON_PMIC_OSC_9M6_CFG0_osc_9m6_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sys_ctrl_reserve0 : 8;
    } reg;
} COMMON_PMIC_SYS_CTRL_CFG0_UNION;
#endif
#define COMMON_PMIC_SYS_CTRL_CFG0_sys_ctrl_reserve0_START (0)
#define COMMON_PMIC_SYS_CTRL_CFG0_sys_ctrl_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sys_ctrl_reserve1 : 8;
    } reg;
} COMMON_PMIC_SYS_CTRL_CFG1_UNION;
#endif
#define COMMON_PMIC_SYS_CTRL_CFG1_sys_ctrl_reserve1_START (0)
#define COMMON_PMIC_SYS_CTRL_CFG1_sys_ctrl_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_adj_rlx : 4;
        unsigned char b0_adj_clx : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG0_b0_adj_rlx_START (0)
#define COMMON_PMIC_BUCK0_CFG0_b0_adj_rlx_END (3)
#define COMMON_PMIC_BUCK0_CFG0_b0_adj_clx_START (4)
#define COMMON_PMIC_BUCK0_CFG0_b0_adj_clx_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_dmd_blanktime_sel : 1;
        unsigned char b0_cot_rlx : 1;
        unsigned char b0_cmp_ibias : 4;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG1_b0_dmd_blanktime_sel_START (0)
#define COMMON_PMIC_BUCK0_CFG1_b0_dmd_blanktime_sel_END (0)
#define COMMON_PMIC_BUCK0_CFG1_b0_cot_rlx_START (1)
#define COMMON_PMIC_BUCK0_CFG1_b0_cot_rlx_END (1)
#define COMMON_PMIC_BUCK0_CFG1_b0_cmp_ibias_START (2)
#define COMMON_PMIC_BUCK0_CFG1_b0_cmp_ibias_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_dmd_sel_eco : 4;
        unsigned char b0_dmd_sel : 4;
    } reg;
} COMMON_PMIC_BUCK0_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG2_b0_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK0_CFG2_b0_dmd_sel_eco_END (3)
#define COMMON_PMIC_BUCK0_CFG2_b0_dmd_sel_START (4)
#define COMMON_PMIC_BUCK0_CFG2_b0_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ea_clp_eco_dis : 1;
        unsigned char b0_dt_sel : 2;
        unsigned char b0_dmd_type_sel : 1;
        unsigned char b0_dmd_ton : 3;
        unsigned char b0_dmd_shield_ton : 1;
    } reg;
} COMMON_PMIC_BUCK0_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG3_b0_ea_clp_eco_dis_START (0)
#define COMMON_PMIC_BUCK0_CFG3_b0_ea_clp_eco_dis_END (0)
#define COMMON_PMIC_BUCK0_CFG3_b0_dt_sel_START (1)
#define COMMON_PMIC_BUCK0_CFG3_b0_dt_sel_END (2)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_type_sel_START (3)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_type_sel_END (3)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_ton_START (4)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_ton_END (6)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_shield_ton_START (7)
#define COMMON_PMIC_BUCK0_CFG3_b0_dmd_shield_ton_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_fix_ton : 1;
        unsigned char b0_fb_cap_sel : 1;
        unsigned char b0_eco_ibias : 1;
        unsigned char b0_ea_ibias : 1;
        unsigned char b0_ea_eco_dis : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK0_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG4_b0_fix_ton_START (0)
#define COMMON_PMIC_BUCK0_CFG4_b0_fix_ton_END (0)
#define COMMON_PMIC_BUCK0_CFG4_b0_fb_cap_sel_START (1)
#define COMMON_PMIC_BUCK0_CFG4_b0_fb_cap_sel_END (1)
#define COMMON_PMIC_BUCK0_CFG4_b0_eco_ibias_START (2)
#define COMMON_PMIC_BUCK0_CFG4_b0_eco_ibias_END (2)
#define COMMON_PMIC_BUCK0_CFG4_b0_ea_ibias_START (3)
#define COMMON_PMIC_BUCK0_CFG4_b0_ea_ibias_END (3)
#define COMMON_PMIC_BUCK0_CFG4_b0_ea_eco_dis_START (4)
#define COMMON_PMIC_BUCK0_CFG4_b0_ea_eco_dis_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_min_ton : 3;
        unsigned char b0_lx_dt : 1;
        unsigned char b0_ibias_dmd_ctrl : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG5_b0_min_ton_START (0)
#define COMMON_PMIC_BUCK0_CFG5_b0_min_ton_END (2)
#define COMMON_PMIC_BUCK0_CFG5_b0_lx_dt_START (3)
#define COMMON_PMIC_BUCK0_CFG5_b0_lx_dt_END (3)
#define COMMON_PMIC_BUCK0_CFG5_b0_ibias_dmd_ctrl_START (4)
#define COMMON_PMIC_BUCK0_CFG5_b0_ibias_dmd_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ntp_dt_ctrl : 1;
        unsigned char b0_nonlinear_driver : 1;
        unsigned char b0_ng_p_sel : 3;
        unsigned char b0_ng_n_sel : 3;
    } reg;
} COMMON_PMIC_BUCK0_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG6_b0_ntp_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK0_CFG6_b0_ntp_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK0_CFG6_b0_nonlinear_driver_START (1)
#define COMMON_PMIC_BUCK0_CFG6_b0_nonlinear_driver_END (1)
#define COMMON_PMIC_BUCK0_CFG6_b0_ng_p_sel_START (2)
#define COMMON_PMIC_BUCK0_CFG6_b0_ng_p_sel_END (4)
#define COMMON_PMIC_BUCK0_CFG6_b0_ng_n_sel_START (5)
#define COMMON_PMIC_BUCK0_CFG6_b0_ng_n_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ocp_sel : 3;
        unsigned char b0_ocp_delay : 1;
        unsigned char b0_ocp_cmp_ibias : 1;
        unsigned char b0_ntp_dt_sel : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK0_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_sel_START (0)
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_sel_END (2)
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_delay_START (3)
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_delay_END (3)
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_cmp_ibias_START (4)
#define COMMON_PMIC_BUCK0_CFG7_b0_ocp_cmp_ibias_END (4)
#define COMMON_PMIC_BUCK0_CFG7_b0_ntp_dt_sel_START (5)
#define COMMON_PMIC_BUCK0_CFG7_b0_ntp_dt_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_offres_shut : 1;
        unsigned char b0_offres_sel : 1;
        unsigned char b0_ocpibias : 2;
        unsigned char b0_ocp_toff : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG8_b0_offres_shut_START (0)
#define COMMON_PMIC_BUCK0_CFG8_b0_offres_shut_END (0)
#define COMMON_PMIC_BUCK0_CFG8_b0_offres_sel_START (1)
#define COMMON_PMIC_BUCK0_CFG8_b0_offres_sel_END (1)
#define COMMON_PMIC_BUCK0_CFG8_b0_ocpibias_START (2)
#define COMMON_PMIC_BUCK0_CFG8_b0_ocpibias_END (3)
#define COMMON_PMIC_BUCK0_CFG8_b0_ocp_toff_START (4)
#define COMMON_PMIC_BUCK0_CFG8_b0_ocp_toff_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ptn_dt_ctrl : 1;
        unsigned char b0_pg_p_sel : 3;
        unsigned char b0_pg_n_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK0_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG9_b0_ptn_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK0_CFG9_b0_ptn_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK0_CFG9_b0_pg_p_sel_START (1)
#define COMMON_PMIC_BUCK0_CFG9_b0_pg_p_sel_END (3)
#define COMMON_PMIC_BUCK0_CFG9_b0_pg_n_sel_START (4)
#define COMMON_PMIC_BUCK0_CFG9_b0_pg_n_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reg_en : 1;
        unsigned char b0_reg_dr : 3;
        unsigned char b0_ramp_ton_ctrl : 1;
        unsigned char b0_ramp_prebias : 1;
        unsigned char b0_ptn_dt_sel : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG10_b0_reg_en_START (0)
#define COMMON_PMIC_BUCK0_CFG10_b0_reg_en_END (0)
#define COMMON_PMIC_BUCK0_CFG10_b0_reg_dr_START (1)
#define COMMON_PMIC_BUCK0_CFG10_b0_reg_dr_END (3)
#define COMMON_PMIC_BUCK0_CFG10_b0_ramp_ton_ctrl_START (4)
#define COMMON_PMIC_BUCK0_CFG10_b0_ramp_ton_ctrl_END (4)
#define COMMON_PMIC_BUCK0_CFG10_b0_ramp_prebias_START (5)
#define COMMON_PMIC_BUCK0_CFG10_b0_ramp_prebias_END (5)
#define COMMON_PMIC_BUCK0_CFG10_b0_ptn_dt_sel_START (6)
#define COMMON_PMIC_BUCK0_CFG10_b0_ptn_dt_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reg_r : 2;
        unsigned char b0_reg_op_c : 1;
        unsigned char b0_reg_ibias : 1;
        unsigned char b0_softime_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK0_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_r_START (0)
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_r_END (1)
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_op_c_START (2)
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_op_c_END (2)
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_ibias_START (3)
#define COMMON_PMIC_BUCK0_CFG11_b0_reg_ibias_END (3)
#define COMMON_PMIC_BUCK0_CFG11_b0_softime_sel_START (4)
#define COMMON_PMIC_BUCK0_CFG11_b0_softime_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK0_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG12_b0_reserve0_START (0)
#define COMMON_PMIC_BUCK0_CFG12_b0_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK0_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG13_b0_reserve1_START (0)
#define COMMON_PMIC_BUCK0_CFG13_b0_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK0_CFG14_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG14_b0_reserve2_START (0)
#define COMMON_PMIC_BUCK0_CFG14_b0_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK0_CFG15_UNION;
#endif
#define COMMON_PMIC_BUCK0_CFG15_b0_reserve3_START (0)
#define COMMON_PMIC_BUCK0_CFG15_b0_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_ocp_state : 1;
        unsigned char b0_ccm_state : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK0_STATUS0_UNION;
#endif
#define COMMON_PMIC_BUCK0_STATUS0_b0_ocp_state_START (0)
#define COMMON_PMIC_BUCK0_STATUS0_b0_ocp_state_END (0)
#define COMMON_PMIC_BUCK0_STATUS0_b0_ccm_state_START (1)
#define COMMON_PMIC_BUCK0_STATUS0_b0_ccm_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_adj_rlx : 4;
        unsigned char b1_adj_clx : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG0_b1_adj_rlx_START (0)
#define COMMON_PMIC_BUCK1_CFG0_b1_adj_rlx_END (3)
#define COMMON_PMIC_BUCK1_CFG0_b1_adj_clx_START (4)
#define COMMON_PMIC_BUCK1_CFG0_b1_adj_clx_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_blanktime_sel : 1;
        unsigned char b1_cot_rlx : 1;
        unsigned char b1_cmp_ibias : 4;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_blanktime_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_blanktime_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG1_b1_cot_rlx_START (1)
#define COMMON_PMIC_BUCK1_CFG1_b1_cot_rlx_END (1)
#define COMMON_PMIC_BUCK1_CFG1_b1_cmp_ibias_START (2)
#define COMMON_PMIC_BUCK1_CFG1_b1_cmp_ibias_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_sel_eco : 4;
        unsigned char b1_dmd_sel : 4;
    } reg;
} COMMON_PMIC_BUCK1_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_eco_END (3)
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ea_clp_eco_dis : 1;
        unsigned char b1_dt_sel : 2;
        unsigned char b1_dmd_type_sel : 1;
        unsigned char b1_dmd_ton : 3;
        unsigned char b1_dmd_shield_ton : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG3_b1_ea_clp_eco_dis_START (0)
#define COMMON_PMIC_BUCK1_CFG3_b1_ea_clp_eco_dis_END (0)
#define COMMON_PMIC_BUCK1_CFG3_b1_dt_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG3_b1_dt_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_type_sel_START (3)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_type_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_ton_START (4)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_ton_END (6)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_shield_ton_START (7)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_shield_ton_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_fix_ton : 1;
        unsigned char b1_fb_cap_sel : 1;
        unsigned char b1_eco_ibias : 1;
        unsigned char b1_ea_ibias : 1;
        unsigned char b1_ea_eco_dis : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG4_b1_fix_ton_START (0)
#define COMMON_PMIC_BUCK1_CFG4_b1_fix_ton_END (0)
#define COMMON_PMIC_BUCK1_CFG4_b1_fb_cap_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG4_b1_fb_cap_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG4_b1_eco_ibias_START (2)
#define COMMON_PMIC_BUCK1_CFG4_b1_eco_ibias_END (2)
#define COMMON_PMIC_BUCK1_CFG4_b1_ea_ibias_START (3)
#define COMMON_PMIC_BUCK1_CFG4_b1_ea_ibias_END (3)
#define COMMON_PMIC_BUCK1_CFG4_b1_ea_eco_dis_START (4)
#define COMMON_PMIC_BUCK1_CFG4_b1_ea_eco_dis_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_min_ton : 3;
        unsigned char b1_lx_dt : 1;
        unsigned char b1_ibias_dmd_ctrl : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG5_b1_min_ton_START (0)
#define COMMON_PMIC_BUCK1_CFG5_b1_min_ton_END (2)
#define COMMON_PMIC_BUCK1_CFG5_b1_lx_dt_START (3)
#define COMMON_PMIC_BUCK1_CFG5_b1_lx_dt_END (3)
#define COMMON_PMIC_BUCK1_CFG5_b1_ibias_dmd_ctrl_START (4)
#define COMMON_PMIC_BUCK1_CFG5_b1_ibias_dmd_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ntp_dt_ctrl : 1;
        unsigned char b1_nonlinear_driver : 1;
        unsigned char b1_ng_p_sel : 3;
        unsigned char b1_ng_n_sel : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG6_b1_ntp_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG6_b1_ntp_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK1_CFG6_b1_nonlinear_driver_START (1)
#define COMMON_PMIC_BUCK1_CFG6_b1_nonlinear_driver_END (1)
#define COMMON_PMIC_BUCK1_CFG6_b1_ng_p_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG6_b1_ng_p_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG6_b1_ng_n_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG6_b1_ng_n_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ocp_sel : 3;
        unsigned char b1_ocp_delay : 1;
        unsigned char b1_ocp_cmp_ibias : 1;
        unsigned char b1_ntp_dt_sel : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_delay_START (3)
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_delay_END (3)
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_cmp_ibias_START (4)
#define COMMON_PMIC_BUCK1_CFG7_b1_ocp_cmp_ibias_END (4)
#define COMMON_PMIC_BUCK1_CFG7_b1_ntp_dt_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG7_b1_ntp_dt_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_offres_shut : 1;
        unsigned char b1_offres_sel : 1;
        unsigned char b1_ocpibias : 2;
        unsigned char b1_ocp_toff : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG8_b1_offres_shut_START (0)
#define COMMON_PMIC_BUCK1_CFG8_b1_offres_shut_END (0)
#define COMMON_PMIC_BUCK1_CFG8_b1_offres_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG8_b1_offres_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG8_b1_ocpibias_START (2)
#define COMMON_PMIC_BUCK1_CFG8_b1_ocpibias_END (3)
#define COMMON_PMIC_BUCK1_CFG8_b1_ocp_toff_START (4)
#define COMMON_PMIC_BUCK1_CFG8_b1_ocp_toff_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ptn_dt_ctrl : 1;
        unsigned char b1_pg_p_sel : 3;
        unsigned char b1_pg_n_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG9_b1_ptn_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG9_b1_ptn_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK1_CFG9_b1_pg_p_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG9_b1_pg_p_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG9_b1_pg_n_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG9_b1_pg_n_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reg_en : 1;
        unsigned char b1_reg_dr : 3;
        unsigned char b1_ramp_ton_ctrl : 1;
        unsigned char b1_ramp_prebias : 1;
        unsigned char b1_ptn_dt_sel : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG10_b1_reg_en_START (0)
#define COMMON_PMIC_BUCK1_CFG10_b1_reg_en_END (0)
#define COMMON_PMIC_BUCK1_CFG10_b1_reg_dr_START (1)
#define COMMON_PMIC_BUCK1_CFG10_b1_reg_dr_END (3)
#define COMMON_PMIC_BUCK1_CFG10_b1_ramp_ton_ctrl_START (4)
#define COMMON_PMIC_BUCK1_CFG10_b1_ramp_ton_ctrl_END (4)
#define COMMON_PMIC_BUCK1_CFG10_b1_ramp_prebias_START (5)
#define COMMON_PMIC_BUCK1_CFG10_b1_ramp_prebias_END (5)
#define COMMON_PMIC_BUCK1_CFG10_b1_ptn_dt_sel_START (6)
#define COMMON_PMIC_BUCK1_CFG10_b1_ptn_dt_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reg_r : 2;
        unsigned char b1_reg_op_c : 1;
        unsigned char b1_reg_ibias : 1;
        unsigned char b1_softime_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_r_START (0)
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_r_END (1)
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_op_c_START (2)
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_op_c_END (2)
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_ibias_START (3)
#define COMMON_PMIC_BUCK1_CFG11_b1_reg_ibias_END (3)
#define COMMON_PMIC_BUCK1_CFG11_b1_softime_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG11_b1_softime_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK1_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG12_b1_reserve0_START (0)
#define COMMON_PMIC_BUCK1_CFG12_b1_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK1_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG13_b1_reserve1_START (0)
#define COMMON_PMIC_BUCK1_CFG13_b1_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK1_CFG14_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG14_b1_reserve2_START (0)
#define COMMON_PMIC_BUCK1_CFG14_b1_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK1_CFG15_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG15_b1_reserve3_START (0)
#define COMMON_PMIC_BUCK1_CFG15_b1_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ocp_state : 1;
        unsigned char b1_ccm_state : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK1_STATUS0_UNION;
#endif
#define COMMON_PMIC_BUCK1_STATUS0_b1_ocp_state_START (0)
#define COMMON_PMIC_BUCK1_STATUS0_b1_ocp_state_END (0)
#define COMMON_PMIC_BUCK1_STATUS0_b1_ccm_state_START (1)
#define COMMON_PMIC_BUCK1_STATUS0_b1_ccm_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_blanktime_sel : 1;
        unsigned char b2_cmp_ibias : 4;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_blanktime_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_blanktime_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG0_b2_cmp_ibias_START (1)
#define COMMON_PMIC_BUCK2_CFG0_b2_cmp_ibias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_sel_eco : 4;
        unsigned char b2_dmd_sel : 4;
    } reg;
} COMMON_PMIC_BUCK2_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_sel_eco_END (3)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ea_clp_eco_dis : 1;
        unsigned char b2_dt_sel : 2;
        unsigned char b2_dmd_type_sel : 1;
        unsigned char b2_dmd_ton : 3;
        unsigned char b2_dmd_shield_ton : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG2_b2_ea_clp_eco_dis_START (0)
#define COMMON_PMIC_BUCK2_CFG2_b2_ea_clp_eco_dis_END (0)
#define COMMON_PMIC_BUCK2_CFG2_b2_dt_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG2_b2_dt_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_type_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_type_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_ton_START (4)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_ton_END (6)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_shield_ton_START (7)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_shield_ton_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_eco_ibias : 1;
        unsigned char b2_ea_ibias : 1;
        unsigned char b2_ea_eco_dis : 1;
        unsigned char b2_softime_sel : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG3_b2_eco_ibias_START (0)
#define COMMON_PMIC_BUCK2_CFG3_b2_eco_ibias_END (0)
#define COMMON_PMIC_BUCK2_CFG3_b2_ea_ibias_START (1)
#define COMMON_PMIC_BUCK2_CFG3_b2_ea_ibias_END (1)
#define COMMON_PMIC_BUCK2_CFG3_b2_ea_eco_dis_START (2)
#define COMMON_PMIC_BUCK2_CFG3_b2_ea_eco_dis_END (2)
#define COMMON_PMIC_BUCK2_CFG3_b2_softime_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG3_b2_softime_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_lx_dt : 1;
        unsigned char b2_ibias_dmd_sel : 2;
        unsigned char b2_fix_ton : 1;
        unsigned char b2_fastramp_ctrl : 4;
    } reg;
} COMMON_PMIC_BUCK2_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG4_b2_lx_dt_START (0)
#define COMMON_PMIC_BUCK2_CFG4_b2_lx_dt_END (0)
#define COMMON_PMIC_BUCK2_CFG4_b2_ibias_dmd_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG4_b2_ibias_dmd_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG4_b2_fix_ton_START (3)
#define COMMON_PMIC_BUCK2_CFG4_b2_fix_ton_END (3)
#define COMMON_PMIC_BUCK2_CFG4_b2_fastramp_ctrl_START (4)
#define COMMON_PMIC_BUCK2_CFG4_b2_fastramp_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ng_n_sel : 3;
        unsigned char b2_min_ton : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG5_b2_ng_n_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG5_b2_ng_n_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG5_b2_min_ton_START (3)
#define COMMON_PMIC_BUCK2_CFG5_b2_min_ton_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ocp_cmp_ibias : 1;
        unsigned char b2_ntp_dt_sel : 2;
        unsigned char b2_ntp_dt_ctrl : 1;
        unsigned char b2_nonlinear_driver : 1;
        unsigned char b2_ng_p_sel : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG6_b2_ocp_cmp_ibias_START (0)
#define COMMON_PMIC_BUCK2_CFG6_b2_ocp_cmp_ibias_END (0)
#define COMMON_PMIC_BUCK2_CFG6_b2_ntp_dt_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG6_b2_ntp_dt_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG6_b2_ntp_dt_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG6_b2_ntp_dt_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG6_b2_nonlinear_driver_START (4)
#define COMMON_PMIC_BUCK2_CFG6_b2_nonlinear_driver_END (4)
#define COMMON_PMIC_BUCK2_CFG6_b2_ng_p_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG6_b2_ng_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ocpibias : 2;
        unsigned char b2_ocp_toff : 2;
        unsigned char b2_ocp_sel : 3;
        unsigned char b2_ocp_delay : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG7_b2_ocpibias_START (0)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocpibias_END (1)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_toff_START (2)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_toff_END (3)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_sel_END (6)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_delay_START (7)
#define COMMON_PMIC_BUCK2_CFG7_b2_ocp_delay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ptn_dt_ctrl : 1;
        unsigned char b2_pg_p_sel : 3;
        unsigned char b2_pg_n_sel : 3;
        unsigned char b2_offres_shut : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG8_b2_ptn_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG8_b2_ptn_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK2_CFG8_b2_pg_p_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG8_b2_pg_p_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG8_b2_pg_n_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG8_b2_pg_n_sel_END (6)
#define COMMON_PMIC_BUCK2_CFG8_b2_offres_shut_START (7)
#define COMMON_PMIC_BUCK2_CFG8_b2_offres_shut_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampdown_ndmd : 3;
        unsigned char b2_ramp_ton_ctrl : 1;
        unsigned char b2_ramp_prebias : 1;
        unsigned char b2_ptn_dt_sel : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG9_b2_rampdown_ndmd_START (0)
#define COMMON_PMIC_BUCK2_CFG9_b2_rampdown_ndmd_END (2)
#define COMMON_PMIC_BUCK2_CFG9_b2_ramp_ton_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG9_b2_ramp_ton_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG9_b2_ramp_prebias_START (4)
#define COMMON_PMIC_BUCK2_CFG9_b2_ramp_prebias_END (4)
#define COMMON_PMIC_BUCK2_CFG9_b2_ptn_dt_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG9_b2_ptn_dt_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK2_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG10_b2_reserve0_START (0)
#define COMMON_PMIC_BUCK2_CFG10_b2_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK2_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG11_b2_reserve1_START (0)
#define COMMON_PMIC_BUCK2_CFG11_b2_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK2_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG12_b2_reserve2_START (0)
#define COMMON_PMIC_BUCK2_CFG12_b2_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK2_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG13_b2_reserve3_START (0)
#define COMMON_PMIC_BUCK2_CFG13_b2_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ocp_state : 1;
        unsigned char b2_ccm_state : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK2_STATUS0_UNION;
#endif
#define COMMON_PMIC_BUCK2_STATUS0_b2_ocp_state_START (0)
#define COMMON_PMIC_BUCK2_STATUS0_b2_ocp_state_END (0)
#define COMMON_PMIC_BUCK2_STATUS0_b2_ccm_state_START (1)
#define COMMON_PMIC_BUCK2_STATUS0_b2_ccm_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_negcur_sel : 1;
        unsigned char b3_dmd_blanktime_sel : 1;
        unsigned char b3_cmp_ibias : 4;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_negcur_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_negcur_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_blanktime_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_blanktime_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG0_b3_cmp_ibias_START (2)
#define COMMON_PMIC_BUCK3_CFG0_b3_cmp_ibias_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_sel_eco : 4;
        unsigned char b3_dmd_sel : 4;
    } reg;
} COMMON_PMIC_BUCK3_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_sel_eco_END (3)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ea_clamp_eco_dis : 1;
        unsigned char b3_dt_sel : 1;
        unsigned char b3_dmdcmp_sel_eco : 1;
        unsigned char b3_dmd_type_sel : 1;
        unsigned char b3_dmd_ton : 3;
        unsigned char b3_dmd_shield_ton : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG2_b3_ea_clamp_eco_dis_START (0)
#define COMMON_PMIC_BUCK3_CFG2_b3_ea_clamp_eco_dis_END (0)
#define COMMON_PMIC_BUCK3_CFG2_b3_dt_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG2_b3_dt_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmdcmp_sel_eco_START (2)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmdcmp_sel_eco_END (2)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_type_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_type_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_ton_START (4)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_ton_END (6)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_shield_ton_START (7)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_shield_ton_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_eco_ibias_sel : 1;
        unsigned char b3_ea_ibias_sel : 1;
        unsigned char b3_ea_eco_dis : 1;
        unsigned char b3_softime_sel : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG3_b3_eco_ibias_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG3_b3_eco_ibias_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG3_b3_ea_ibias_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG3_b3_ea_ibias_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG3_b3_ea_eco_dis_START (2)
#define COMMON_PMIC_BUCK3_CFG3_b3_ea_eco_dis_END (2)
#define COMMON_PMIC_BUCK3_CFG3_b3_softime_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG3_b3_softime_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_lx_dt : 1;
        unsigned char b3_ibias_dmd_ctrl : 2;
        unsigned char b3_fix_ton : 1;
        unsigned char b3_fastramp_ctrl : 4;
    } reg;
} COMMON_PMIC_BUCK3_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG4_b3_lx_dt_START (0)
#define COMMON_PMIC_BUCK3_CFG4_b3_lx_dt_END (0)
#define COMMON_PMIC_BUCK3_CFG4_b3_ibias_dmd_ctrl_START (1)
#define COMMON_PMIC_BUCK3_CFG4_b3_ibias_dmd_ctrl_END (2)
#define COMMON_PMIC_BUCK3_CFG4_b3_fix_ton_START (3)
#define COMMON_PMIC_BUCK3_CFG4_b3_fix_ton_END (3)
#define COMMON_PMIC_BUCK3_CFG4_b3_fastramp_ctrl_START (4)
#define COMMON_PMIC_BUCK3_CFG4_b3_fastramp_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ng_n_sel : 3;
        unsigned char b3_min_ton : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG5_b3_ng_n_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG5_b3_ng_n_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG5_b3_min_ton_START (3)
#define COMMON_PMIC_BUCK3_CFG5_b3_min_ton_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ocp_cmp_ibias : 1;
        unsigned char b3_ntp_dt_sel : 2;
        unsigned char b3_ntp_dt_ctrl : 1;
        unsigned char b3_nonlinear_driver : 1;
        unsigned char b3_ng_p_sel : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG6_b3_ocp_cmp_ibias_START (0)
#define COMMON_PMIC_BUCK3_CFG6_b3_ocp_cmp_ibias_END (0)
#define COMMON_PMIC_BUCK3_CFG6_b3_ntp_dt_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG6_b3_ntp_dt_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG6_b3_ntp_dt_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG6_b3_ntp_dt_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG6_b3_nonlinear_driver_START (4)
#define COMMON_PMIC_BUCK3_CFG6_b3_nonlinear_driver_END (4)
#define COMMON_PMIC_BUCK3_CFG6_b3_ng_p_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG6_b3_ng_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ocpibias_sel : 2;
        unsigned char b3_ocpblanktime_sel : 1;
        unsigned char b3_ocp_toff : 2;
        unsigned char b3_ocp_sel : 2;
        unsigned char b3_ocp_delay : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG7_b3_ocpibias_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocpibias_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocpblanktime_sel_START (2)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocpblanktime_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_toff_START (3)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_toff_END (4)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_sel_END (6)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_delay_START (7)
#define COMMON_PMIC_BUCK3_CFG7_b3_ocp_delay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ptn_dt_ctrl : 1;
        unsigned char b3_pg_p_sel : 3;
        unsigned char b3_pg_n_sel : 3;
        unsigned char b3_offres_shut : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG8_b3_ptn_dt_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG8_b3_ptn_dt_ctrl_END (0)
#define COMMON_PMIC_BUCK3_CFG8_b3_pg_p_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG8_b3_pg_p_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG8_b3_pg_n_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG8_b3_pg_n_sel_END (6)
#define COMMON_PMIC_BUCK3_CFG8_b3_offres_shut_START (7)
#define COMMON_PMIC_BUCK3_CFG8_b3_offres_shut_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampdown_ndmd : 3;
        unsigned char b3_ramp_ton_ctrl : 1;
        unsigned char b3_ramp_prebias : 1;
        unsigned char b3_ptn_dt_sel : 2;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG9_b3_rampdown_ndmd_START (0)
#define COMMON_PMIC_BUCK3_CFG9_b3_rampdown_ndmd_END (2)
#define COMMON_PMIC_BUCK3_CFG9_b3_ramp_ton_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG9_b3_ramp_ton_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG9_b3_ramp_prebias_START (4)
#define COMMON_PMIC_BUCK3_CFG9_b3_ramp_prebias_END (4)
#define COMMON_PMIC_BUCK3_CFG9_b3_ptn_dt_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG9_b3_ptn_dt_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK3_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG10_b3_reserve0_START (0)
#define COMMON_PMIC_BUCK3_CFG10_b3_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK3_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG11_b3_reserve1_START (0)
#define COMMON_PMIC_BUCK3_CFG11_b3_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK3_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG12_b3_reserve2_START (0)
#define COMMON_PMIC_BUCK3_CFG12_b3_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK3_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG13_b3_reserve3_START (0)
#define COMMON_PMIC_BUCK3_CFG13_b3_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ocp_state : 1;
        unsigned char b3_ccm_state : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK3_STATUS0_UNION;
#endif
#define COMMON_PMIC_BUCK3_STATUS0_b3_ocp_state_START (0)
#define COMMON_PMIC_BUCK3_STATUS0_b3_ocp_state_END (0)
#define COMMON_PMIC_BUCK3_STATUS0_b3_ccm_state_START (1)
#define COMMON_PMIC_BUCK3_STATUS0_b3_ccm_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_regop_clp : 1;
        unsigned char b_hys_ocptrim_ctrl : 1;
        unsigned char b_hys_ocp_dis : 1;
        unsigned char b_hys_lxres_trim : 1;
        unsigned char b_hys_filter_ton : 2;
        unsigned char b_hys_dmd_clp : 1;
        unsigned char b_hys_cmp_filter : 1;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_regop_clp_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_regop_clp_END (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_ocptrim_ctrl_START (1)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_ocptrim_ctrl_END (1)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_ocp_dis_START (2)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_ocp_dis_END (2)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_lxres_trim_START (3)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_lxres_trim_END (3)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_filter_ton_START (4)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_filter_ton_END (5)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_dmd_clp_START (6)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_dmd_clp_END (6)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_cmp_filter_START (7)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG0_b_hys_cmp_filter_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_short_pdp : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG1_b_hys_short_pdp_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG1_b_hys_short_pdp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG2_b_hys_reserve0_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG2_b_hys_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG3_b_hys_reserve1_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG3_b_hys_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG4_b_hys_reserve2_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG4_b_hys_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b_hys_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK_HYS_TOP_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK_HYS_TOP_CFG5_b_hys_reserve3_START (0)
#define COMMON_PMIC_BUCK_HYS_TOP_CFG5_b_hys_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_config : 8;
    } reg;
} COMMON_PMIC_LDO1_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO1_CFG0_ldo1_config_START (0)
#define COMMON_PMIC_LDO1_CFG0_ldo1_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_ocp_test : 1;
        unsigned char ldo1_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO1_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO1_CFG1_ldo1_ocp_test_START (0)
#define COMMON_PMIC_LDO1_CFG1_ldo1_ocp_test_END (0)
#define COMMON_PMIC_LDO1_CFG1_ldo1_ocp_set_START (1)
#define COMMON_PMIC_LDO1_CFG1_ldo1_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_config : 8;
    } reg;
} COMMON_PMIC_LDO2_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO2_CFG0_ldo2_config_START (0)
#define COMMON_PMIC_LDO2_CFG0_ldo2_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_ocp_test : 1;
        unsigned char ldo2_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO2_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO2_CFG1_ldo2_ocp_test_START (0)
#define COMMON_PMIC_LDO2_CFG1_ldo2_ocp_test_END (0)
#define COMMON_PMIC_LDO2_CFG1_ldo2_ocp_set_START (1)
#define COMMON_PMIC_LDO2_CFG1_ldo2_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_config : 8;
    } reg;
} COMMON_PMIC_LDO3_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO3_CFG0_ldo3_config_START (0)
#define COMMON_PMIC_LDO3_CFG0_ldo3_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_ocp_test : 1;
        unsigned char ldo3_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO3_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO3_CFG1_ldo3_ocp_test_START (0)
#define COMMON_PMIC_LDO3_CFG1_ldo3_ocp_test_END (0)
#define COMMON_PMIC_LDO3_CFG1_ldo3_ocp_set_START (1)
#define COMMON_PMIC_LDO3_CFG1_ldo3_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_config : 8;
    } reg;
} COMMON_PMIC_LDO4_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO4_CFG0_ldo4_config_START (0)
#define COMMON_PMIC_LDO4_CFG0_ldo4_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_ocp_test : 1;
        unsigned char ldo4_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO4_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO4_CFG1_ldo4_ocp_test_START (0)
#define COMMON_PMIC_LDO4_CFG1_ldo4_ocp_test_END (0)
#define COMMON_PMIC_LDO4_CFG1_ldo4_ocp_set_START (1)
#define COMMON_PMIC_LDO4_CFG1_ldo4_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_config : 8;
    } reg;
} COMMON_PMIC_LDO5_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO5_CFG0_ldo5_config_START (0)
#define COMMON_PMIC_LDO5_CFG0_ldo5_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_ss_config : 1;
        unsigned char ldo5_ocp_test : 1;
        unsigned char ldo5_ocp_set : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_LDO5_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO5_CFG1_ldo5_ss_config_START (0)
#define COMMON_PMIC_LDO5_CFG1_ldo5_ss_config_END (0)
#define COMMON_PMIC_LDO5_CFG1_ldo5_ocp_test_START (1)
#define COMMON_PMIC_LDO5_CFG1_ldo5_ocp_test_END (1)
#define COMMON_PMIC_LDO5_CFG1_ldo5_ocp_set_START (2)
#define COMMON_PMIC_LDO5_CFG1_ldo5_ocp_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_config : 8;
    } reg;
} COMMON_PMIC_LDO6_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO6_CFG0_ldo6_config_START (0)
#define COMMON_PMIC_LDO6_CFG0_ldo6_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_ocp_test : 1;
        unsigned char ldo6_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO6_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO6_CFG1_ldo6_ocp_test_START (0)
#define COMMON_PMIC_LDO6_CFG1_ldo6_ocp_test_END (0)
#define COMMON_PMIC_LDO6_CFG1_ldo6_ocp_set_START (1)
#define COMMON_PMIC_LDO6_CFG1_ldo6_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_config : 8;
    } reg;
} COMMON_PMIC_LDO7_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO7_CFG0_ldo7_config_START (0)
#define COMMON_PMIC_LDO7_CFG0_ldo7_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_ocp_test : 1;
        unsigned char ldo7_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO7_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_test_START (0)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_test_END (0)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_set_START (1)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_config : 8;
    } reg;
} COMMON_PMIC_LDO8_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO8_CFG0_ldo8_config_START (0)
#define COMMON_PMIC_LDO8_CFG0_ldo8_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_ocp_test : 1;
        unsigned char ldo8_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO8_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO8_CFG1_ldo8_ocp_test_START (0)
#define COMMON_PMIC_LDO8_CFG1_ldo8_ocp_test_END (0)
#define COMMON_PMIC_LDO8_CFG1_ldo8_ocp_set_START (1)
#define COMMON_PMIC_LDO8_CFG1_ldo8_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve0 : 8;
    } reg;
} COMMON_PMIC_LDO_RESERVE_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO_RESERVE_CFG0_ldo_reserve0_START (0)
#define COMMON_PMIC_LDO_RESERVE_CFG0_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve1 : 8;
    } reg;
} COMMON_PMIC_LDO_RESERVE_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO_RESERVE_CFG1_ldo_reserve1_START (0)
#define COMMON_PMIC_LDO_RESERVE_CFG1_ldo_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve2 : 8;
    } reg;
} COMMON_PMIC_LDO_RESERVE_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO_RESERVE_CFG2_ldo_reserve2_START (0)
#define COMMON_PMIC_LDO_RESERVE_CFG2_ldo_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve3 : 8;
    } reg;
} COMMON_PMIC_LDO_RESERVE_CFG3_UNION;
#endif
#define COMMON_PMIC_LDO_RESERVE_CFG3_ldo_reserve3_START (0)
#define COMMON_PMIC_LDO_RESERVE_CFG3_ldo_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve4 : 8;
    } reg;
} COMMON_PMIC_LDO_RESERVE_CFG4_UNION;
#endif
#define COMMON_PMIC_LDO_RESERVE_CFG4_ldo_reserve4_START (0)
#define COMMON_PMIC_LDO_RESERVE_CFG4_ldo_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_stb_set : 4;
        unsigned char pmuh_config : 4;
    } reg;
} COMMON_PMIC_PMUH_CFG0_UNION;
#endif
#define COMMON_PMIC_PMUH_CFG0_pmuh_stb_set_START (0)
#define COMMON_PMIC_PMUH_CFG0_pmuh_stb_set_END (3)
#define COMMON_PMIC_PMUH_CFG0_pmuh_config_START (4)
#define COMMON_PMIC_PMUH_CFG0_pmuh_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve0 : 8;
    } reg;
} COMMON_PMIC_D2A_RESERVE_CFG0_UNION;
#endif
#define COMMON_PMIC_D2A_RESERVE_CFG0_d2a_reserve0_START (0)
#define COMMON_PMIC_D2A_RESERVE_CFG0_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve1 : 8;
    } reg;
} COMMON_PMIC_D2A_RESERVE_CFG1_UNION;
#endif
#define COMMON_PMIC_D2A_RESERVE_CFG1_d2a_reserve1_START (0)
#define COMMON_PMIC_D2A_RESERVE_CFG1_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve2 : 8;
    } reg;
} COMMON_PMIC_D2A_RESERVE_CFG2_UNION;
#endif
#define COMMON_PMIC_D2A_RESERVE_CFG2_d2a_reserve2_START (0)
#define COMMON_PMIC_D2A_RESERVE_CFG2_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve3 : 8;
    } reg;
} COMMON_PMIC_D2A_RESERVE_CFG3_UNION;
#endif
#define COMMON_PMIC_D2A_RESERVE_CFG3_d2a_reserve3_START (0)
#define COMMON_PMIC_D2A_RESERVE_CFG3_d2a_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve0 : 8;
    } reg;
} COMMON_PMIC_A2D_RESERVE0_UNION;
#endif
#define COMMON_PMIC_A2D_RESERVE0_a2d_reserve0_START (0)
#define COMMON_PMIC_A2D_RESERVE0_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve1 : 8;
    } reg;
} COMMON_PMIC_A2D_RESERVE1_UNION;
#endif
#define COMMON_PMIC_A2D_RESERVE1_a2d_reserve1_START (0)
#define COMMON_PMIC_A2D_RESERVE1_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve0 : 8;
    } reg;
} COMMON_PMIC_ATEST_RESERVE_CFG0_UNION;
#endif
#define COMMON_PMIC_ATEST_RESERVE_CFG0_atest_reserve0_START (0)
#define COMMON_PMIC_ATEST_RESERVE_CFG0_atest_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve1 : 8;
    } reg;
} COMMON_PMIC_ATEST_RESERVE_CFG1_UNION;
#endif
#define COMMON_PMIC_ATEST_RESERVE_CFG1_atest_reserve1_START (0)
#define COMMON_PMIC_ATEST_RESERVE_CFG1_atest_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve2 : 8;
    } reg;
} COMMON_PMIC_ATEST_RESERVE_CFG2_UNION;
#endif
#define COMMON_PMIC_ATEST_RESERVE_CFG2_atest_reserve2_START (0)
#define COMMON_PMIC_ATEST_RESERVE_CFG2_atest_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve3 : 8;
    } reg;
} COMMON_PMIC_ATEST_RESERVE_CFG3_UNION;
#endif
#define COMMON_PMIC_ATEST_RESERVE_CFG3_atest_reserve3_START (0)
#define COMMON_PMIC_ATEST_RESERVE_CFG3_atest_reserve3_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
