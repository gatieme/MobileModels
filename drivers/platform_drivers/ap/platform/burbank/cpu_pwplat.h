#ifndef __CPU_PWPLAT_H__
#define __CPU_PWPLAT_H__ 
#include <soc_corecrg_b_m_interface.h>
#include <soc_corecrg_l_l3_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_fcm_local_cpu_interface.h>
#include <soc_fcm_local_gic_interface.h>
#include <soc_fcm_local_peri_interface.h>
#include <soc_fcm_secure_interface.h>
#include <soc_sctrl_interface.h>
#include <soc_pctrl_interface.h>
#include <soc_lpmcu_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_gic600_interface.h>
#define CPU_POWER_OFF 0
#define CPU_POWER_ON 1
#define POWER_STATE_FCM 0
#define POWER_STATE_LIT 1
#define POWER_STATE_MID 2
#define POWER_STATE_BIG 3
#define CORE_NUM_LIT 4
#define CORE_NUM_MID 3
#define CORE_NUM_BIG 1
#define CORE_NUM_ALL 8
#define CORE_PWR_ON 0x6
#define CORE_PWR_MSK 0xF
#define CORE_PWR_WIDTH 0x4
#define BIT_MASK_OFFSET 16
#define CORE_MEMREPAIR_WAIT 400
#define RVBAR_OFFSET 2
#define CORE_RESET_WAIT 5000
#define DIV_CPU_GIC 0x7
#define DIV_CPU_GIC_MASK (BIT(SOC_CRGPERIPH_CLKDIV17_div_cpu_gic_END + 1) - BIT(SOC_CRGPERIPH_CLKDIV17_div_cpu_gic_START))
#define DIV_CORE_CRG_APB 0x5
#define DIV_CORE_CRG_APB_MASK (BIT(SOC_CRGPERIPH_CLKDIV28_div_core_crg_apb_END + 1) - BIT(SOC_CRGPERIPH_CLKDIV28_div_core_crg_apb_START))
#define CPU_ADB_REQ_BIT BIT(0)
#define CPU_ADB_PWRQACCEPTN_ACK_BIT BIT(3)
#define CPU_ADB_PWRQDENY_ACK_BIT BIT(4)
#ifdef CPU_PW_PLAT_M
#define SCTRL_BASE_ADDR SOC_LPMCU_SCTRL_BASE_ADDR
#define PERI_CRG_BASE_ADDR SOC_LPMCU_PERI_CRG_BASE_ADDR
#define CORE_CRG_L_L3_BASE_ADDR SOC_LPMCU_CORE_CRG_L_L3_BASE_ADDR
#define CORE_CRG_B_M_BASE_ADDR SOC_LPMCU_CORE_CRG_B_M_BASE_ADDR
#define FCM_LOCAL_CPU_BASE_ADDR SOC_LPMCU_FCM_LOCAL_CPU_BASE_ADDR
#define FCM_LOCAL_PERI_BASE_ADDR SOC_LPMCU_FCM_LOCAL_PERI_BASE_ADDR
#define FCM_LOCAL_GIC_BASE_ADDR SOC_LPMCU_FCM_LOCAL_GIC_BASE_ADDR
#define PCTRL_BASE_ADDR SOC_LPMCU_PCTRL_BASE_ADDR
#else
#define SCTRL_BASE_ADDR SOC_ACPU_SCTRL_BASE_ADDR
#define PERI_CRG_BASE_ADDR SOC_ACPU_PERI_CRG_BASE_ADDR
#define CORE_CRG_L_L3_BASE_ADDR SOC_ACPU_CORE_CRG_L_L3_BASE_ADDR
#define CORE_CRG_B_M_BASE_ADDR SOC_ACPU_CORE_CRG_B_M_BASE_ADDR
#define FCM_LOCAL_CPU_BASE_ADDR SOC_ACPU_FCM_LOCAL_CPU_BASE_ADDR
#define FCM_LOCAL_PERI_BASE_ADDR SOC_ACPU_FCM_LOCAL_PERI_BASE_ADDR
#define FCM_LOCAL_GIC_BASE_ADDR SOC_ACPU_FCM_LOCAL_GIC_BASE_ADDR
#define PCTRL_BASE_ADDR SOC_ACPU_PCTRL_BASE_ADDR
#endif
typedef struct {
 SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_UNION PCHANNEL[CORE_NUM_ALL];
}SOC_FCM_LOCAL_PERI_FCM_CORES_PCHANNEL_CFG_STRUCT;
#define LOCAL_PERI_FCM_CORES_PCHANNEL (*(volatile SOC_FCM_LOCAL_PERI_FCM_CORES_PCHANNEL_CFG_STRUCT*)(SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
typedef struct {
 SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_UNION RVBAR_CTRL[CORE_NUM_ALL];
}SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRLS_STRUCT;
#define FCM_LOCAL_PERI_FCM_RVBAR (*(volatile SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRLS_STRUCT*)(SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define CRGPERIPH_FCM_STAT0 (*(volatile SOC_CRGPERIPH_FCM_STAT0_UNION*)(SOC_CRGPERIPH_FCM_STAT0_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_FCM_RSTSTAT (*(volatile SOC_CRGPERIPH_FCM_RSTSTAT_UNION*)(SOC_CRGPERIPH_FCM_RSTSTAT_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_CLKDIV15 (*(volatile SOC_CRGPERIPH_CLKDIV15_UNION*)(SOC_CRGPERIPH_CLKDIV15_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_PERI_COMMON_CTRL1 (*(volatile SOC_CRGPERIPH_PERI_COMMON_CTRL1_UNION*)(SOC_CRGPERIPH_PERI_COMMON_CTRL1_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_A53_COREGICMASK (*(volatile SOC_CRGPERIPH_A53_COREGICMASK_UNION*)(SOC_CRGPERIPH_A53_COREGICMASK_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_MAIA_COREGICMASK (*(volatile SOC_CRGPERIPH_MAIA_COREGICMASK_UNION*)(SOC_CRGPERIPH_MAIA_COREGICMASK_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_A53_COREPWRINTSTAT (*(volatile SOC_CRGPERIPH_A53_COREPWRINTSTAT_UNION*)(SOC_CRGPERIPH_A53_COREPWRINTSTAT_ADDR(PERI_CRG_BASE_ADDR)))
#define CRGPERIPH_MAIA_COREPWRINTSTAT (*(volatile SOC_CRGPERIPH_MAIA_COREPWRINTSTAT_UNION*)(SOC_CRGPERIPH_MAIA_COREPWRINTSTAT_ADDR(PERI_CRG_BASE_ADDR)))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_ddrc_cpu_START 5
#define CRGPERIPH_PERI_COMMON_CTRL3 (*(volatile SOC_CRGPERIPH_PERI_COMMON_CTRL3_UNION*)(SOC_CRGPERIPH_PERI_COMMON_CTRL3_ADDR(PERI_CRG_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL0 (*(volatile SOC_FCM_LOCAL_PERI_CTRL0_UNION*)(SOC_FCM_LOCAL_PERI_CTRL0_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL7 (*(volatile SOC_FCM_LOCAL_PERI_CTRL7_UNION*)(SOC_FCM_LOCAL_PERI_CTRL7_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL8 (*(volatile SOC_FCM_LOCAL_PERI_CTRL8_UNION*)(SOC_FCM_LOCAL_PERI_CTRL8_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL10 (*(volatile SOC_FCM_LOCAL_PERI_CTRL10_UNION*)(SOC_FCM_LOCAL_PERI_CTRL10_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL23 (*(volatile SOC_FCM_LOCAL_PERI_CTRL23_UNION*)(SOC_FCM_LOCAL_PERI_CTRL23_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL24 (*(volatile SOC_FCM_LOCAL_PERI_CTRL24_UNION*)(SOC_FCM_LOCAL_PERI_CTRL24_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL25 (*(volatile SOC_FCM_LOCAL_PERI_CTRL25_UNION*)(SOC_FCM_LOCAL_PERI_CTRL25_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_PERI_CTRL26 (*(volatile SOC_FCM_LOCAL_PERI_CTRL26_UNION*)(SOC_FCM_LOCAL_PERI_CTRL26_ADDR(FCM_LOCAL_PERI_BASE_ADDR)))
#define FCM_LOCAL_CPU_CTRL0 (*(volatile SOC_FCM_LOCAL_CPU_CTRL0_UNION*)(SOC_FCM_LOCAL_CPU_CTRL0_ADDR(FCM_LOCAL_CPU_BASE_ADDR)))
#define FCM_LOCAL_CPU_CTRL10 (*(volatile SOC_FCM_LOCAL_CPU_CTRL10_UNION*)(SOC_FCM_LOCAL_CPU_CTRL10_ADDR(FCM_LOCAL_CPU_BASE_ADDR)))
#define FCM_LOCAL_CPU_CTRL6 (*(volatile SOC_FCM_LOCAL_CPU_CTRL6_UNION*)(SOC_FCM_LOCAL_CPU_CTRL6_ADDR(FCM_LOCAL_CPU_BASE_ADDR)))
#define FCM_LOCAL_CPU_CTRL13 (*(volatile SOC_FCM_LOCAL_CPU_CTRL13_UNION*)(SOC_FCM_LOCAL_CPU_CTRL13_ADDR(FCM_LOCAL_CPU_BASE_ADDR)))
#define FCM_LOCAL_GIC_CTRL1 (*(volatile SOC_FCM_LOCAL_GIC_CTRL1_UNION*)(SOC_FCM_LOCAL_GIC_CTRL1_ADDR(FCM_LOCAL_GIC_BASE_ADDR)))
#define FCM_SECURE_DECPROT0SET (*(volatile SOC_FCM_SECURE_DECPROT0SET_UNION*)(SOC_FCM_SECURE_DECPROT0SET_ADDR(SOC_LPMCU_FCM_SECURE_BASE_ADDR)))
#define FCM0_ADBLPSTAT (SOC_CRGPERIPH_FCM0_ADBLPSTAT_ADDR(PERI_CRG_BASE_ADDR))
#define FCM1_ADBLPSTAT (SOC_CRGPERIPH_FCM1_ADBLPSTAT_ADDR(PERI_CRG_BASE_ADDR))
#define FCM_PERIPH_ADBLPSTAT (SOC_CRGPERIPH_FCM_PERIPH_ADBLPSTAT_ADDR(PERI_CRG_BASE_ADDR))
typedef enum {
 CPU_DTS_FPGA,
 CPU_DTS_DEFAULT,
 CPU_DTS_LITE,
 CPU_DTS_TYPE1,
 CPU_DTS_TYPE2
} cpu_dts_type;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_on : 1;
        unsigned int lit_on : 1;
        unsigned int mid_on : 1;
        unsigned int big_on : 1;
        unsigned int reserved : 16;
        unsigned int dts_type : 4;
        unsigned int lit_mask : 4;
        unsigned int mid_mask : 3;
        unsigned int big_mask : 1;
    } reg;
    struct
    {
        unsigned int fcm_on : 1;
        unsigned int lit_on : 1;
        unsigned int mid_on : 1;
        unsigned int big_on : 1;
        unsigned int reserved : 16;
        unsigned int dts_type : 4;
        unsigned int cpu_mask : 8;
    } reg2;
} SELF_SCTRL_SCBAKDATA2_UNION;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int main_core : 8;
        unsigned int main_cluster : 8;
        unsigned int lit_status : 4;
        unsigned int mid_status : 3;
        unsigned int big_status : 1;
        unsigned int first_boot : 1;
        unsigned int reserved : 1;
  unsigned int lit_mode : 2;
  unsigned int mid_mode : 2;
  unsigned int big_mode : 2;
    } reg;
    struct
    {
        unsigned int main_core : 8;
        unsigned int main_cluster : 8;
        unsigned int cpu_status : 8;
        unsigned int first_boot : 1;
        unsigned int reserved : 1;
        unsigned int cpu_mode : 6;
    } reg2;
} SELF_SCTRL_SCBAKDATA3_UNION;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lit_idle : 4;
        unsigned int mid_idle : 3;
        unsigned int big_idle : 1;
        unsigned int reserved_0 : 8;
        unsigned int syssr_flag : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SELF_SCTRL_SCBAKDATA8_UNION;
#define SCTRL_SCBAKDATA2 (*(volatile SELF_SCTRL_SCBAKDATA2_UNION*)(SOC_SCTRL_SCBAKDATA2_ADDR(SCTRL_BASE_ADDR)))
#define SCTRL_SCBAKDATA3 (*(volatile SELF_SCTRL_SCBAKDATA3_UNION*)(SOC_SCTRL_SCBAKDATA3_ADDR(SCTRL_BASE_ADDR)))
#define SCTRL_SCBAKDATA8 (*(volatile SELF_SCTRL_SCBAKDATA8_UNION*)(SOC_SCTRL_SCBAKDATA8_ADDR(SCTRL_BASE_ADDR)))
typedef union {
 unsigned int value;
 struct {
  unsigned int repair_ack_0 : 4;
  unsigned int repair_ack_lit4 : 4;
  unsigned int repair_ack_mid3 : 3;
  unsigned int repair_ack_big1 : 1;
  unsigned int repair_ack_fcm0 : 1;
  unsigned int repair_ack_1 : 19;
 } reg;
} SELF_SCTRL_SCPERSTATUS3_UNION;
#define SCTRL_SCPERSTATUS3 (*(volatile SELF_SCTRL_SCPERSTATUS3_UNION*)(SOC_SCTRL_SCPERSTATUS3_ADDR(SCTRL_BASE_ADDR)))
#endif
