#ifndef __MNTN_PUBLIC_INTERFACE_H__
#define __MNTN_PUBLIC_INTERFACE_H__ 
#include "soc_acpu_baseaddr_interface.h"
#include "soc_dmss_interface.h"
#include "pmic_interface.h"
#include "global_ddr_map.h"
#include "../common/mntn_dump_interface.h"
#include "../common/qic_interface.h"
#include "../common/mntn_common_interface.h"
#define PMU_SAVE_CPU_ID (PMIC_HRST_REG18_ADDR(0))
#define MEMUPLOAD_SEC_MEM 0
#define MEMUPLOAD_NONE_SEC_MEM 1
#define JTAG_SD_LDO0 DEVICE_SDJTAG
#define JTAG_SD_LDO1 DEVICE_SD_SIM_JTAG
#define JTAG_SIM_LDO0 DEVICE_SIM_JTAG
#define JTAG_SIM_LDO1 DEVICE_SIM_JTAG2
#define JTAG_SD_LDO0_VAL 3000000
#define JTAG_SD_LDO1_VAL 1200000
#define JTAG_SIM_LDO0_VAL 1800000
#define JTAG_SIM_LDO1_VAL 1800000
#define SD2JTAG_SIM_CFG0_OFFSET 0x670
#define SD2JTAG_SIM_CFG1_OFFSET 0x671
#define SD2JTAG_SIM_CFG2_OFFSET 0x672
#define SD2JTAG_SIM_CFG3_OFFSET 0x673
#define SD2JTAG_SIM_CFG1_RSTIN_INPUT 0x17
#define SD2JTAG_SIM_CFG3_RSTIN_INPUT 0x17
#define SD2JTAG_SIM_CFG0_ENABLE_SH 0x9
#define SD2JTAG_SIM_CFG2_ENABLE_SH 0x9
#define SD2JTAG_SIMJTAG_PMUID 1
enum {
 BL31_TRACE_EXCEPTION_SIZE = 0x100,
 BL31_TRACE_IRQ_SMC_SIZE = 0x3F000,
 BL31_TRACE_DMSS_SIZE = 0x10000,
};
typedef struct dmss_asi_sec_fail_info_s{
 SOC_DMSS_ASI_SEC_INT_STATUS_UNION asi_sec_int_status;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF0_UNION asi_sec_fail_cmd_inf0;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF1_UNION asi_sec_fail_cmd_inf1;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF2_UNION asi_sec_fail_cmd_inf2;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF3_UNION asi_sec_fail_cmd_inf3;
} dmss_asi_sec_fail_info;
typedef struct dmss_dmi_sec_fail_info_s{
 SOC_DMSS_DMI_SEC_INT_STATUS_UNION dmi_sec_int_status;
 SOC_DMSS_DMI_ENHN_INT_STATUS_UNION dmi_enhn_int_status;
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF0_UNION dmi_sec_fail_cmd_inf0;
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF1_UNION dmi_sec_fail_cmd_inf1;
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF2_UNION dmi_sec_fail_cmd_inf2;
} dmss_dmi_sec_fail_info;
typedef struct dmss_ami_sec_fail_info_s{
 SOC_DMSS_AMI_SEC_INT_STATUS_UNION ami_sec_int_status;
 SOC_DMSS_AMI_SEC_FAIL_CMD_INF0_UNION ami_sec_fail_cmd_inf0;
 SOC_DMSS_AMI_SEC_FAIL_CMD_INF1_UNION ami_sec_fail_cmd_inf1;
 SOC_DMSS_AMI_SEC_FAIL_CMD_INF2_UNION ami_sec_fail_cmd_inf2;
} dmss_ami_sec_fail_info;
typedef struct dmss_dmi_mpu_fail_info_s{
 SOC_DMSS_DMI_MPU_INT_STATUS_UNION dmi_mpu_int_status;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF0_UNION dmi_mpu_fail_cmd_inf0;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF1_UNION dmi_mpu_fail_cmd_inf1;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF2_UNION dmi_mpu_fail_cmd_inf2;
} dmss_dmi_mpu_fail_info;
typedef struct dmss_ami_mpu_fail_info_s{
 SOC_DMSS_AMI_MPU_INT_STATUS_UNION ami_mpu_int_status;
 SOC_DMSS_AMI_MPU_FAIL_CMD_INF0_UNION ami_mpu_fail_cmd_inf0;
 SOC_DMSS_AMI_MPU_FAIL_CMD_INF1_UNION ami_mpu_fail_cmd_inf1;
 SOC_DMSS_AMI_MPU_FAIL_CMD_INF2_UNION ami_mpu_fail_cmd_inf2;
} dmss_ami_mpu_fail_info;
 #define MNTN_DMSS_ACPU_ASI_MAX 2
 #define MNTN_DMSS_DMI_MAX 2
typedef struct dmss_exception_trace_s {
 unsigned long long e_32k_time;
 dmss_asi_sec_fail_info asi_sec[MNTN_DMSS_ACPU_ASI_MAX];
 dmss_dmi_sec_fail_info dmi_sec[MNTN_DMSS_DMI_MAX];
 dmss_ami_sec_fail_info ami_sec;
 dmss_dmi_mpu_fail_info dmi_mpu[MNTN_DMSS_DMI_MAX];
 dmss_ami_mpu_fail_info ami_mpu;
} dmss_exception_trace_t;
enum SECMEM_MODULE {
 M3_DDR_MEM,
 BL31_LOG_MEM,
 MAX_MEM,
};
#if defined(CONFIG_GCOV_KERNEL) || defined(CONFIG_HISI_GCOV_FASTBOOT)
struct mdump_gcov {
 unsigned long gcda_addr;
 unsigned int gcda_size;
};
#endif
struct mntn_reg_val {
        unsigned int init_flag;
        unsigned int scsysstat;
        unsigned int bootpoint;
};
void mntn_reg_save(void *mntn_reg);
void mntn_reg_restore(void *mntn_reg);
#endif
