#ifndef __SOC_NPU_CPU_SYSCTRL_INTERFACE_H__
#define __SOC_NPU_CPU_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_CPU_SYSCTRL_SC_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT0_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT1_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT10_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT11_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT13_ADDR(base) ((base) + (0x003CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT14_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT15_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT16_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT17_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT18_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT19_ADDR(base) ((base) + (0x0054UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT20_ADDR(base) ((base) + (0x0058UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT21_ADDR(base) ((base) + (0x005CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT22_ADDR(base) ((base) + (0x0060UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL0_ADDR(base) ((base) + (0x009CUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL1_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_ADDR(base) ((base) + (0x00A4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL3_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL4_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL5_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL6_ADDR(base) ((base) + (0x00B4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL7_ADDR(base) ((base) + (0x00B8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL8_ADDR(base) ((base) + (0x00BCUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL9_ADDR(base) ((base) + (0x00C0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL10_ADDR(base) ((base) + (0x00C4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL11_ADDR(base) ((base) + (0x00C8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL12_ADDR(base) ((base) + (0x00CCUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL13_ADDR(base) ((base) + (0x00D0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_ADDR(base) ((base) + (0x00D4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_ADDR(base) ((base) + (0x00D8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL16_ADDR(base) ((base) + (0x00DCUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ADDR(base) ((base) + (0x00E0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ADDR(base) ((base) + (0x00E4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_ADDR(base) ((base) + (0x00E8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL20_ADDR(base) ((base) + (0x00ECUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL21_ADDR(base) ((base) + (0x00F0UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL22_ADDR(base) ((base) + (0x00F4UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL23_ADDR(base) ((base) + (0x00F8UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL24_ADDR(base) ((base) + (0x00FCUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL25_ADDR(base) ((base) + (0x0100UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL26_ADDR(base) ((base) + (0x0104UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL27_ADDR(base) ((base) + (0x0108UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL28_ADDR(base) ((base) + (0x010CUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL29_ADDR(base) ((base) + (0x0110UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL30_ADDR(base) ((base) + (0x0114UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL31_ADDR(base) ((base) + (0x0118UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL32_ADDR(base) ((base) + (0x011CUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_ADDR(base) ((base) + (0x0120UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_ADDR(base) ((base) + (0x0124UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL35_ADDR(base) ((base) + (0x0128UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_ADDR(base) ((base) + (0x0164UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_ADDR(base) ((base) + (0x0168UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_ADDR(base) ((base) + (0x016cUL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_ADDR(base) ((base) + (0x0170UL))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_ADDR(base) ((base) + (0x0174UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG0_ADDR(base) ((base) + (0x0BE0UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG1_ADDR(base) ((base) + (0x0BE4UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG2_ADDR(base) ((base) + (0x0BE8UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG3_ADDR(base) ((base) + (0x0BECUL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG4_ADDR(base) ((base) + (0x0BF0UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG5_ADDR(base) ((base) + (0x0BF4UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG6_ADDR(base) ((base) + (0x0BF8UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG7_ADDR(base) ((base) + (0x0BFCUL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG8_ADDR(base) ((base) + (0x0C00UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG9_ADDR(base) ((base) + (0x0C04UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG10_ADDR(base) ((base) + (0x0C08UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG11_ADDR(base) ((base) + (0x0C0CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG12_ADDR(base) ((base) + (0x0C10UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG13_ADDR(base) ((base) + (0x0C14UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG14_ADDR(base) ((base) + (0x0C18UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG15_ADDR(base) ((base) + (0x0C1CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG0_ADDR(base) ((base) + (0x0C20UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG1_ADDR(base) ((base) + (0x0C24UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG2_ADDR(base) ((base) + (0x0C28UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG3_ADDR(base) ((base) + (0x0C2CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG4_ADDR(base) ((base) + (0x0C30UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG5_ADDR(base) ((base) + (0x0C34UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG6_ADDR(base) ((base) + (0x0C38UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG7_ADDR(base) ((base) + (0x0C3CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG8_ADDR(base) ((base) + (0x0C40UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG9_ADDR(base) ((base) + (0x0C44UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG10_ADDR(base) ((base) + (0x0C48UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG11_ADDR(base) ((base) + (0x0C4CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG12_ADDR(base) ((base) + (0x0C50UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG13_ADDR(base) ((base) + (0x0C54UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG14_ADDR(base) ((base) + (0x0C58UL))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG15_ADDR(base) ((base) + (0x0C5CUL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG16_ADDR(base) ((base) + (0x0C60UL))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG17_ADDR(base) ((base) + (0x0C64UL))
#define SOC_NPU_CPU_SYSCTRL_SCPROTREG_ADDR(base) ((base) + (0x0C68UL))
#else
#define SOC_NPU_CPU_SYSCTRL_SC_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT0_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT1_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT10_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT11_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT13_ADDR(base) ((base) + (0x003C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT14_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT15_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT16_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT17_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT18_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT19_ADDR(base) ((base) + (0x0054))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT20_ADDR(base) ((base) + (0x0058))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT21_ADDR(base) ((base) + (0x005C))
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT22_ADDR(base) ((base) + (0x0060))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL0_ADDR(base) ((base) + (0x009C))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL1_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_ADDR(base) ((base) + (0x00A4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL3_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL4_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL5_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL6_ADDR(base) ((base) + (0x00B4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL7_ADDR(base) ((base) + (0x00B8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL8_ADDR(base) ((base) + (0x00BC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL9_ADDR(base) ((base) + (0x00C0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL10_ADDR(base) ((base) + (0x00C4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL11_ADDR(base) ((base) + (0x00C8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL12_ADDR(base) ((base) + (0x00CC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL13_ADDR(base) ((base) + (0x00D0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_ADDR(base) ((base) + (0x00D4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_ADDR(base) ((base) + (0x00D8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL16_ADDR(base) ((base) + (0x00DC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ADDR(base) ((base) + (0x00E0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ADDR(base) ((base) + (0x00E4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_ADDR(base) ((base) + (0x00E8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL20_ADDR(base) ((base) + (0x00EC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL21_ADDR(base) ((base) + (0x00F0))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL22_ADDR(base) ((base) + (0x00F4))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL23_ADDR(base) ((base) + (0x00F8))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL24_ADDR(base) ((base) + (0x00FC))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL25_ADDR(base) ((base) + (0x0100))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL26_ADDR(base) ((base) + (0x0104))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL27_ADDR(base) ((base) + (0x0108))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL28_ADDR(base) ((base) + (0x010C))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL29_ADDR(base) ((base) + (0x0110))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL30_ADDR(base) ((base) + (0x0114))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL31_ADDR(base) ((base) + (0x0118))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL32_ADDR(base) ((base) + (0x011C))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_ADDR(base) ((base) + (0x0120))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_ADDR(base) ((base) + (0x0124))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL35_ADDR(base) ((base) + (0x0128))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_ADDR(base) ((base) + (0x0164))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_ADDR(base) ((base) + (0x0168))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_ADDR(base) ((base) + (0x016c))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_ADDR(base) ((base) + (0x0170))
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_ADDR(base) ((base) + (0x0174))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG0_ADDR(base) ((base) + (0x0BE0))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG1_ADDR(base) ((base) + (0x0BE4))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG2_ADDR(base) ((base) + (0x0BE8))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG3_ADDR(base) ((base) + (0x0BEC))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG4_ADDR(base) ((base) + (0x0BF0))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG5_ADDR(base) ((base) + (0x0BF4))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG6_ADDR(base) ((base) + (0x0BF8))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG7_ADDR(base) ((base) + (0x0BFC))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG8_ADDR(base) ((base) + (0x0C00))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG9_ADDR(base) ((base) + (0x0C04))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG10_ADDR(base) ((base) + (0x0C08))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG11_ADDR(base) ((base) + (0x0C0C))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG12_ADDR(base) ((base) + (0x0C10))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG13_ADDR(base) ((base) + (0x0C14))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG14_ADDR(base) ((base) + (0x0C18))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG15_ADDR(base) ((base) + (0x0C1C))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG0_ADDR(base) ((base) + (0x0C20))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG1_ADDR(base) ((base) + (0x0C24))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG2_ADDR(base) ((base) + (0x0C28))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG3_ADDR(base) ((base) + (0x0C2C))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG4_ADDR(base) ((base) + (0x0C30))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG5_ADDR(base) ((base) + (0x0C34))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG6_ADDR(base) ((base) + (0x0C38))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG7_ADDR(base) ((base) + (0x0C3C))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG8_ADDR(base) ((base) + (0x0C40))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG9_ADDR(base) ((base) + (0x0C44))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG10_ADDR(base) ((base) + (0x0C48))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG11_ADDR(base) ((base) + (0x0C4C))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG12_ADDR(base) ((base) + (0x0C50))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG13_ADDR(base) ((base) + (0x0C54))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG14_ADDR(base) ((base) + (0x0C58))
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG15_ADDR(base) ((base) + (0x0C5C))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG16_ADDR(base) ((base) + (0x0C60))
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG17_ADDR(base) ((base) + (0x0C64))
#define SOC_NPU_CPU_SYSCTRL_SCPROTREG_ADDR(base) ((base) + (0x0C68))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_CPU_SYSCTRL_MON_ENABLE_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_IDMASK_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_IDMASK_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_LOW_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_HIGH_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_LOW_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_HIGH_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_L_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_CPU_SYSCTRL_MON_AW_CNT_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_CNT_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_L_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_CPU_SYSCTRL_MON_AR_CNT_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_CNT_ADDR(base) ((base) + (0x0054UL))
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_H_ADDR(base) ((base) + (0x0058UL))
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_H_ADDR(base) ((base) + (0x005CUL))
#else
#define SOC_NPU_CPU_SYSCTRL_MON_ENABLE_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_CPU_SYSCTRL_MON_W_IDMASK_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_CPU_SYSCTRL_MON_R_IDMASK_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_LOW_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_HIGH_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_LOW_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_HIGH_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_L_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_CPU_SYSCTRL_MON_AW_CNT_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_CPU_SYSCTRL_MON_W_CNT_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_L_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_CPU_SYSCTRL_MON_AR_CNT_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_CPU_SYSCTRL_MON_R_CNT_ADDR(base) ((base) + (0x0054))
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_H_ADDR(base) ((base) + (0x0058))
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_H_ADDR(base) ((base) + (0x005C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE1_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE2_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE3_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE4_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE5_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE6_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE7_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE8_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE9_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE10_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE11_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE12_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE13_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE14_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE15_ADDR(base) ((base) + (0x003CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE16_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE17_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE18_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE19_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE20_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE21_ADDR(base) ((base) + (0x0054UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE22_ADDR(base) ((base) + (0x0058UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE23_ADDR(base) ((base) + (0x005CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE24_ADDR(base) ((base) + (0x0060UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE25_ADDR(base) ((base) + (0x0064UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE26_ADDR(base) ((base) + (0x0068UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE27_ADDR(base) ((base) + (0x006CUL))
#define SOC_NPU_CPU_SYSCTRL_SECURE28_ADDR(base) ((base) + (0x0070UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE29_ADDR(base) ((base) + (0x0074UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE30_ADDR(base) ((base) + (0x0078UL))
#define SOC_NPU_CPU_SYSCTRL_SECURE31_ADDR(base) ((base) + (0x007CUL))
#else
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_CPU_SYSCTRL_SECURE1_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_CPU_SYSCTRL_SECURE2_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_CPU_SYSCTRL_SECURE3_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_CPU_SYSCTRL_SECURE4_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_CPU_SYSCTRL_SECURE5_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_CPU_SYSCTRL_SECURE6_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_CPU_SYSCTRL_SECURE7_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_CPU_SYSCTRL_SECURE8_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_CPU_SYSCTRL_SECURE9_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_CPU_SYSCTRL_SECURE10_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_CPU_SYSCTRL_SECURE11_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_CPU_SYSCTRL_SECURE12_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_CPU_SYSCTRL_SECURE13_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_CPU_SYSCTRL_SECURE14_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_CPU_SYSCTRL_SECURE15_ADDR(base) ((base) + (0x003C))
#define SOC_NPU_CPU_SYSCTRL_SECURE16_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_CPU_SYSCTRL_SECURE17_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_CPU_SYSCTRL_SECURE18_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_CPU_SYSCTRL_SECURE19_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_CPU_SYSCTRL_SECURE20_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_CPU_SYSCTRL_SECURE21_ADDR(base) ((base) + (0x0054))
#define SOC_NPU_CPU_SYSCTRL_SECURE22_ADDR(base) ((base) + (0x0058))
#define SOC_NPU_CPU_SYSCTRL_SECURE23_ADDR(base) ((base) + (0x005C))
#define SOC_NPU_CPU_SYSCTRL_SECURE24_ADDR(base) ((base) + (0x0060))
#define SOC_NPU_CPU_SYSCTRL_SECURE25_ADDR(base) ((base) + (0x0064))
#define SOC_NPU_CPU_SYSCTRL_SECURE26_ADDR(base) ((base) + (0x0068))
#define SOC_NPU_CPU_SYSCTRL_SECURE27_ADDR(base) ((base) + (0x006C))
#define SOC_NPU_CPU_SYSCTRL_SECURE28_ADDR(base) ((base) + (0x0070))
#define SOC_NPU_CPU_SYSCTRL_SECURE29_ADDR(base) ((base) + (0x0074))
#define SOC_NPU_CPU_SYSCTRL_SECURE30_ADDR(base) ((base) + (0x0078))
#define SOC_NPU_CPU_SYSCTRL_SECURE31_ADDR(base) ((base) + (0x007C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 22;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axiecs0_dlock_irq : 1;
        unsigned int axiecs0_dlock_wr : 1;
        unsigned int reserved_0 : 2;
        unsigned int axiecs0_dlock_id : 12;
        unsigned int axiecs0_dlock_slv : 3;
        unsigned int reserved_1 : 1;
        unsigned int axiecs0_dlock_mst : 2;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_irq_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_irq_END (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_wr_START (1)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_wr_END (1)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_id_START (4)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_id_END (15)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_slv_START (16)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_slv_END (18)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_mst_START (20)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT2_axiecs0_dlock_mst_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axiecs0_port_busy_bus_slave : 7;
        unsigned int reserved_0 : 1;
        unsigned int axiecs0_port_busy_bus_master : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_axiecs0_port_busy_bus_slave_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_axiecs0_port_busy_bus_slave_END (6)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_axiecs0_port_busy_bus_master_START (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT3_axiecs0_port_busy_bus_master_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svt_wrap0_tidm_tihpm_code : 9;
        unsigned int svt_wrap0_tidm_hpmx_code : 9;
        unsigned int svt_wrap0_tidm_hpm_code : 9;
        unsigned int svt_wrap0_tidm_finish_valid : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_tihpm_code_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_tihpm_code_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_hpmx_code_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_hpmx_code_END (17)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_hpm_code_START (18)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_hpm_code_END (26)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_finish_valid_START (27)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT4_svt_wrap0_tidm_finish_valid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svt_wrap0_pasensor_hci_0oout : 9;
        unsigned int svt_wrap0_pasensor_hci_a_out : 9;
        unsigned int svt_wrap0_pasensor_nbti_o_out : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_hci_0oout_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_hci_0oout_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_hci_a_out_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_hci_a_out_END (17)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_nbti_o_out_START (18)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT5_svt_wrap0_pasensor_nbti_o_out_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svt_wrap0_pasensor_nbti_a_out : 9;
        unsigned int svt_wrap0_pasensor_cfg_ready : 1;
        unsigned int svt_wrap0_pasensor_valid : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_nbti_a_out_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_nbti_a_out_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_cfg_ready_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_cfg_ready_END (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_valid_START (10)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT6_svt_wrap0_pasensor_valid_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap1_tidm_tihpm_code : 9;
        unsigned int lvt_wrap1_tidm_hpmx_code : 9;
        unsigned int lvt_wrap1_tidm_hpm_code : 9;
        unsigned int lvt_wrap1_tidm_finish_valid : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_tihpm_code_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_tihpm_code_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_hpmx_code_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_hpmx_code_END (17)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_hpm_code_START (18)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_hpm_code_END (26)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_finish_valid_START (27)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT7_lvt_wrap1_tidm_finish_valid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap1_pasensor_hci_o_out : 9;
        unsigned int lvt_wrap1_pasensor_hci_a_out : 9;
        unsigned int lvt_wrap1_pasensor_nbti_o_out : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_hci_o_out_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_hci_o_out_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_hci_a_out_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_hci_a_out_END (17)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_nbti_o_out_START (18)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT8_lvt_wrap1_pasensor_nbti_o_out_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap1_pasensor_nbti_a_out : 9;
        unsigned int lvt_wrap1_pasensor_cfg_ready : 1;
        unsigned int lvt_wrap1_pasensor_valid : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_nbti_a_out_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_nbti_a_out_END (8)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_cfg_ready_START (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_cfg_ready_END (9)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_valid_START (10)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT9_lvt_wrap1_pasensor_valid_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_low32 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT10_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT10_cnt_low32_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT10_cnt_low32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_high32 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT11_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT11_cnt_high32_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT11_cnt_high32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx_opc_valid : 1;
        unsigned int hpmx_opc : 10;
        unsigned int hpm_opc : 10;
        unsigned int hpm_opc_valid : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpmx_opc_valid_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpmx_opc_valid_END (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpmx_opc_START (1)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpmx_opc_END (10)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpm_opc_START (11)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpm_opc_END (20)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpm_opc_valid_START (21)
#define SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT12_hpm_opc_valid_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SYSSTAT22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_id_bypass : 1;
        unsigned int reserved_0 : 4;
        unsigned int sc_ts_core_idle : 1;
        unsigned int sc_ts_core_idle_sel : 1;
        unsigned int reserved_1 : 4;
        unsigned int sc_ai_core_idle : 1;
        unsigned int sc_ai_core_idle_sel : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_axi_id_bypass_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_axi_id_bypass_END (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ts_core_idle_START (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ts_core_idle_END (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ts_core_idle_sel_START (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ts_core_idle_sel_END (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ai_core_idle_START (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ai_core_idle_END (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ai_core_idle_sel_START (12)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL2_sc_ai_core_idle_sel_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_dw_axi_auto_gate_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL4_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL4_sc_dw_axi_auto_gate_en_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL4_sc_dw_axi_auto_gate_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_axiecs0_dlock_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL5_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL5_sc_axiecs0_dlock_clear_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL5_sc_axiecs0_dlock_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npu_mem_awqos : 4;
        unsigned int npu_mem_arqos : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_npu_mem_awqos_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_npu_mem_awqos_END (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_npu_mem_arqos_START (4)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL14_npu_mem_arqos_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bs_awqos : 4;
        unsigned int bs_arqos : 4;
        unsigned int fcm_awqos : 4;
        unsigned int fcm_arqos : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_bs_awqos_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_bs_awqos_END (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_bs_arqos_START (4)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_bs_arqos_END (7)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_fcm_awqos_START (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_fcm_awqos_END (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_fcm_arqos_START (12)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL15_fcm_arqos_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_db_mem_LS : 1;
        unsigned int ts_db_mem_DS : 1;
        unsigned int ts_db_mem_SD : 1;
        unsigned int ts_db_mem_TSELR : 3;
        unsigned int ts_db_mem_TSELW : 2;
        unsigned int ts_db_mem_TEST : 3;
        unsigned int reserved_0 : 5;
        unsigned int ts_db_mem_TRA : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_LS_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_LS_END (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_DS_START (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_DS_END (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_SD_START (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_SD_END (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TSELR_START (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TSELR_END (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TSELW_START (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TSELW_END (7)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TEST_START (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TEST_END (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TRA_START (16)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL17_ts_db_mem_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_sram_mem_LS : 1;
        unsigned int ts_sram_mem_DS : 1;
        unsigned int ts_sram_mem_SD : 1;
        unsigned int reserved_0 : 5;
        unsigned int ts_sram_mem_TEST : 3;
        unsigned int ts_sram_mem_TSELR : 3;
        unsigned int ts_sram_mem_TSELW : 2;
        unsigned int ts_sram_mem_TRA : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_LS_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_LS_END (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_DS_START (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_DS_END (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_SD_START (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_SD_END (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TEST_START (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TEST_END (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TSELR_START (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TSELR_END (13)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TSELW_START (14)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TSELW_END (15)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TRA_START (16)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL18_ts_sram_mem_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_priority_m1 : 2;
        unsigned int mst_priority_m2 : 2;
        unsigned int mst_priority_m3 : 2;
        unsigned int reserved_0 : 2;
        unsigned int slv_priority_s1 : 3;
        unsigned int slv_priority_s2 : 3;
        unsigned int slv_priority_s3 : 3;
        unsigned int slv_priority_s4 : 3;
        unsigned int slv_priority_s5 : 3;
        unsigned int slv_priority_s6 : 3;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m1_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m1_END (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m2_START (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m2_END (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m3_START (4)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_mst_priority_m3_END (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s1_START (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s1_END (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s2_START (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s2_END (13)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s3_START (14)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s3_END (16)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s4_START (17)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s4_END (19)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s5_START (20)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s5_END (22)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s6_START (23)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL19_slv_priority_s6_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL31_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_reset_prot_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL32_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL32_sc_reset_prot_disable_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL32_sc_reset_prot_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_override : 4;
        unsigned int awcache_override : 4;
        unsigned int special_gid : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_arcache_override_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_arcache_override_END (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_awcache_override_START (4)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_awcache_override_END (7)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_special_gid_START (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL33_special_gid_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sgid_enable : 1;
        unsigned int axcache_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_sgid_enable_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_sgid_enable_END (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_axcache_sel_START (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL34_axcache_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL35_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svt_wrap0_tihpm_mode : 3;
        unsigned int svt_wrap0_tidm_div : 6;
        unsigned int svt_wrap0_tidm_en : 1;
        unsigned int svt_wrap0_pasensor_cfg_valid : 1;
        unsigned int svt_wrap0_pasensor_cmd : 2;
        unsigned int reserved : 3;
        unsigned int svt_wrap0_pasensor_msq : 16;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tihpm_mode_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tihpm_mode_END (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tidm_div_START (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tidm_div_END (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tidm_en_START (9)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_tidm_en_END (9)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_cfg_valid_START (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_cfg_valid_END (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_cmd_START (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_cmd_END (12)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_msq_START (16)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL50_svt_wrap0_pasensor_msq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap0_pasensor_ctrl : 6;
        unsigned int lvt_wrap0_pasensor_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_lvt_wrap0_pasensor_ctrl_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_lvt_wrap0_pasensor_ctrl_END (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_lvt_wrap0_pasensor_en_START (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL51_lvt_wrap0_pasensor_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap1_tihpm_mode : 3;
        unsigned int lvt_wrap1_tidm_div : 6;
        unsigned int lvt_wrap1_tidm_en : 1;
        unsigned int lvt_wrap1_pasensor_cfg_valid : 1;
        unsigned int lvt_wrap1_pasensor_cmd : 2;
        unsigned int reserved : 3;
        unsigned int lvt_wrap1_pasensor_msq : 16;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tihpm_mode_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tihpm_mode_END (2)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tidm_div_START (3)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tidm_div_END (8)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tidm_en_START (9)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_tidm_en_END (9)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_cfg_valid_START (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_cfg_valid_END (10)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_cmd_START (11)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_cmd_END (12)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_msq_START (16)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL52_lvt_wrap1_pasensor_msq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lvt_wrap1_pasensor_ctrl : 6;
        unsigned int lvt_wrap1_pasensor_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_lvt_wrap1_pasensor_ctrl_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_lvt_wrap1_pasensor_ctrl_END (5)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_lvt_wrap1_pasensor_en_START (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL53_lvt_wrap1_pasensor_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx_en : 1;
        unsigned int hpm_clk_div : 6;
        unsigned int hpm_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpmx_en_START (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpmx_en_END (0)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpm_clk_div_START (1)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpm_clk_div_END (6)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpm_en_START (7)
#define SOC_NPU_CPU_SYSCTRL_PERIPHCTRL54_hpm_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg0 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG0_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG0_test_reg0_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG0_test_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg1 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG1_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG1_test_reg1_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG1_test_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg2 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG2_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG2_test_reg2_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG2_test_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg3 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG3_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG3_test_reg3_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG3_test_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg4 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG4_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG4_test_reg4_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG4_test_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg5 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG5_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG5_test_reg5_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG5_test_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg6 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG6_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG6_test_reg6_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG6_test_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg7 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG7_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG7_test_reg7_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG7_test_reg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg8 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG8_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG8_test_reg8_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG8_test_reg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg9 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG9_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG9_test_reg9_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG9_test_reg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg10 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG10_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG10_test_reg10_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG10_test_reg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg11 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG11_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG11_test_reg11_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG11_test_reg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg12 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG12_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG12_test_reg12_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG12_test_reg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg13 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG13_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG13_test_reg13_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG13_test_reg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg14 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG14_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG14_test_reg14_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG14_test_reg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg15 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG15_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG15_test_reg15_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG15_test_reg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg0 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG0_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG0_sema_reg0_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG0_sema_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg1 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG1_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG1_sema_reg1_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG1_sema_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg2 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG2_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG2_sema_reg2_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG2_sema_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg3 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG3_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG3_sema_reg3_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG3_sema_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg4 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG4_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG4_sema_reg4_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG4_sema_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg5 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG5_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG5_sema_reg5_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG5_sema_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg6 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG6_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG6_sema_reg6_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG6_sema_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg7 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG7_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG7_sema_reg7_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG7_sema_reg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg8 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG8_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG8_sema_reg8_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG8_sema_reg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg9 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG9_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG9_sema_reg9_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG9_sema_reg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg10 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG10_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG10_sema_reg10_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG10_sema_reg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg11 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG11_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG11_sema_reg11_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG11_sema_reg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg12 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG12_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG12_sema_reg12_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG12_sema_reg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg13 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG13_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG13_sema_reg13_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG13_sema_reg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg14 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG14_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG14_sema_reg14_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG14_sema_reg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sema_reg15 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_SEMAREG15_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG15_sema_reg15_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_SEMAREG15_sema_reg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg16 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG16_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG16_test_reg16_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG16_test_reg16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_reg17 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SC_TESTREG17_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG17_test_reg17_START (0)
#define SOC_NPU_CPU_SYSCTRL_SC_TESTREG17_test_reg17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scprotreg : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SCPROTREG_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SCPROTREG_scprotreg_START (0)
#define SOC_NPU_CPU_SYSCTRL_SCPROTREG_scprotreg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_ENABLE_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_ENABLE_sample_en_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_ENABLE_sample_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_compara_id : 12;
        unsigned int reserved_0 : 4;
        unsigned int w_compara_len : 4;
        unsigned int reserved_1 : 4;
        unsigned int w_compara_size : 3;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_id_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_id_END (11)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_len_START (16)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_len_END (19)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_size_START (24)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARA_w_compara_size_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_len_en : 1;
        unsigned int w_size_en : 1;
        unsigned int w_unalign_en : 1;
        unsigned int all_wstrb_1_en : 1;
        unsigned int w_interleaving_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_len_en_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_len_en_END (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_size_en_START (1)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_size_en_END (1)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_unalign_en_START (2)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_unalign_en_END (2)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_all_wstrb_1_en_START (3)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_all_wstrb_1_en_END (3)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_interleaving_en_START (4)
#define SOC_NPU_CPU_SYSCTRL_MON_W_COMPPARAEN_w_interleaving_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_idmask : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_IDMASK_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_IDMASK_w_idmask_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_IDMASK_w_idmask_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_compara_id : 12;
        unsigned int reserved_0 : 4;
        unsigned int r_compara_len : 4;
        unsigned int reserved_1 : 4;
        unsigned int r_compara_size : 3;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_id_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_id_END (11)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_len_START (16)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_len_END (19)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_size_START (24)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARA_r_compara_size_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_len_en : 1;
        unsigned int r_size_en : 1;
        unsigned int r_unalign_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int r_interleaving_en : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_len_en_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_len_en_END (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_size_en_START (1)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_size_en_END (1)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_unalign_en_START (2)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_unalign_en_END (2)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_interleaving_en_START (4)
#define SOC_NPU_CPU_SYSCTRL_MON_R_COMPPARAEN_r_interleaving_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_idmask : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_IDMASK_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_IDMASK_r_idmask_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_IDMASK_r_idmask_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_addr_base_low : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_START_ADDR_LOW_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_LOW_w_addr_base_low_START (0)
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_LOW_w_addr_base_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_addr_base_high : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_START_ADDR_HIGH_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_HIGH_w_addr_base_high_START (0)
#define SOC_NPU_CPU_SYSCTRL_START_ADDR_HIGH_w_addr_base_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_addr_end_low : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_END_ADDR_LOW_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_LOW_w_addr_end_low_START (0)
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_LOW_w_addr_end_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_addr_end_high : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_END_ADDR_HIGH_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_HIGH_w_addr_end_high_START (0)
#define SOC_NPU_CPU_SYSCTRL_END_ADDR_HIGH_w_addr_end_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_match_addr_l : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_L_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_L_w_match_addr_l_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_L_w_match_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aw_match_cnt : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_AW_CNT_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_AW_CNT_aw_match_cnt_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_AW_CNT_aw_match_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_match_cnt : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_CNT_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_CNT_w_match_cnt_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_CNT_w_match_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_match_addr_l : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_L_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_L_r_match_addr_l_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_L_r_match_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ar_match_cnt : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_AR_CNT_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_AR_CNT_ar_match_cnt_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_AR_CNT_ar_match_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_match_cnt : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_CNT_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_CNT_r_match_cnt_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_CNT_r_match_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_match_addr_h : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_H_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_H_w_match_addr_h_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_W_ADDR_H_w_match_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_match_addr_h : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_H_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_H_r_match_addr_h_START (0)
#define SOC_NPU_CPU_SYSCTRL_MON_R_ADDR_H_r_match_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_sysctrl_ns : 1;
        unsigned int ts_wdog_ns : 1;
        unsigned int ai_wdog_ns : 1;
        unsigned int ts_core_ctrl_ns : 1;
        unsigned int ai_core_ctrl_ns : 1;
        unsigned int ts_aximon_noc_ns : 1;
        unsigned int ts_aximon_bs_ns : 1;
        unsigned int ts_aximon_cpu_ns : 1;
        unsigned int ts_core_local_apb_ns : 1;
        unsigned int ai_core_local_apb_ns : 1;
        unsigned int npu_fcm_local_ctrl_ns : 1;
        unsigned int ts_timer_ns : 1;
        unsigned int ai_timer_ns : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE0_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_sysctrl_ns_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_sysctrl_ns_END (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_wdog_ns_START (1)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_wdog_ns_END (1)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_wdog_ns_START (2)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_wdog_ns_END (2)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_core_ctrl_ns_START (3)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_core_ctrl_ns_END (3)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_core_ctrl_ns_START (4)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_core_ctrl_ns_END (4)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_noc_ns_START (5)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_noc_ns_END (5)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_bs_ns_START (6)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_bs_ns_END (6)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_cpu_ns_START (7)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_aximon_cpu_ns_END (7)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_core_local_apb_ns_START (8)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_core_local_apb_ns_END (8)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_core_local_apb_ns_START (9)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_core_local_apb_ns_END (9)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_npu_fcm_local_ctrl_ns_START (10)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_npu_fcm_local_ctrl_ns_END (10)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_timer_ns_START (11)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ts_timer_ns_END (11)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_timer_ns_START (12)
#define SOC_NPU_CPU_SYSCTRL_SECURE0_ai_timer_ns_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure1 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE1_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE1_secure1_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE1_secure1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_cpu_awmid : 6;
        unsigned int reserved_0 : 2;
        unsigned int data_cpu_armid : 6;
        unsigned int reserved_1 : 2;
        unsigned int data_bs_awmid : 6;
        unsigned int reserved_2 : 2;
        unsigned int data_bs_armid : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE2_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_cpu_awmid_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_cpu_awmid_END (5)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_cpu_armid_START (8)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_cpu_armid_END (13)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_bs_awmid_START (16)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_bs_awmid_END (21)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_bs_armid_START (24)
#define SOC_NPU_CPU_SYSCTRL_SECURE2_data_bs_armid_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_cpu_awmid : 6;
        unsigned int reserved_0 : 2;
        unsigned int cfg_cpu_armid : 6;
        unsigned int reserved_1 : 2;
        unsigned int cfg_bs_awmid : 6;
        unsigned int reserved_2 : 2;
        unsigned int cfg_bs_armid : 6;
        unsigned int secure3 : 2;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE3_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_cpu_awmid_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_cpu_awmid_END (5)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_cpu_armid_START (8)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_cpu_armid_END (13)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_bs_awmid_START (16)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_bs_awmid_END (21)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_bs_armid_START (24)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_cfg_bs_armid_END (29)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_secure3_START (30)
#define SOC_NPU_CPU_SYSCTRL_SECURE3_secure3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bs_axprot : 1;
        unsigned int bs_axprot_sel : 1;
        unsigned int secure4 : 30;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE4_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE4_bs_axprot_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE4_bs_axprot_END (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE4_bs_axprot_sel_START (1)
#define SOC_NPU_CPU_SYSCTRL_SECURE4_bs_axprot_sel_END (1)
#define SOC_NPU_CPU_SYSCTRL_SECURE4_secure4_START (2)
#define SOC_NPU_CPU_SYSCTRL_SECURE4_secure4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure5 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE5_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE5_secure5_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE5_secure5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure6 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE6_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE6_secure6_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE6_secure6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure7 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE7_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE7_secure7_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE7_secure7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure8 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE8_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE8_secure8_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE8_secure8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure9 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE9_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE9_secure9_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE9_secure9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure10 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE10_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE10_secure10_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE10_secure10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure11 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE11_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE11_secure11_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE11_secure11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure12 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE12_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE12_secure12_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE12_secure12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure13 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE13_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE13_secure13_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE13_secure13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure14 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE14_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE14_secure14_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE14_secure14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure15 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE15_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE15_secure15_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE15_secure15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure16 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE16_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE16_secure16_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE16_secure16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure17 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE17_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE17_secure17_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE17_secure17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure18 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE18_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE18_secure18_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE18_secure18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure19 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE19_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE19_secure19_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE19_secure19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure20 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE20_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE20_secure20_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE20_secure20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure21 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE21_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE21_secure21_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE21_secure21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure22 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE22_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE22_secure22_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE22_secure22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure23 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE23_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE23_secure23_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE23_secure23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure24 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE24_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE24_secure24_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE24_secure24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure25 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE25_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE25_secure25_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE25_secure25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure26 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE26_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE26_secure26_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE26_secure26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure27 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE27_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE27_secure27_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE27_secure27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure28 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE28_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE28_secure28_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE28_secure28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure29 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE29_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE29_secure29_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE29_secure29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure30 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE30_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE30_secure30_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE30_secure30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure31 : 32;
    } reg;
} SOC_NPU_CPU_SYSCTRL_SECURE31_UNION;
#endif
#define SOC_NPU_CPU_SYSCTRL_SECURE31_secure31_START (0)
#define SOC_NPU_CPU_SYSCTRL_SECURE31_secure31_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
