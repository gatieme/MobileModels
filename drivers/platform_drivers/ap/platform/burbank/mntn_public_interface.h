#ifndef __MNTN_PUBLIC_INTERFACE_H__
#define __MNTN_PUBLIC_INTERFACE_H__ 
#include "soc_dmss_interface.h"
#include "pmic_interface.h"
#include "../common/mntn_dump_interface.h"
#include "../common/mntn_common_interface.h"
#define PMU_SAVE_CPU_ID (PMIC_HRST_REG18_ADDR(0))
#define MEMUPLOAD_SEC_MEM 0
#define MEMUPLOAD_NONE_SEC_MEM 1
#define JTAG_SD_LDO0 DEVICE_SDCARD
#define JTAG_SD_LDO1 DEVICE_SD_SIM_JTAG
#define JTAG_SIM_LDO0 DEVICE_SIM_JTAG
#define JTAG_SIM_LDO1 DEVICE_SIM_JTAG2
#define JTAG_SD_LDO0_VAL 1800000
#define JTAG_SD_LDO1_VAL 1200000
#define JTAG_SIM_LDO0_VAL 1800000
#define JTAG_SIM_LDO1_VAL 1800000
enum {
 BL31_TRACE_EXCEPTION_SIZE = 0x100,
 BL31_TRACE_IRQ_SMC_SIZE = 0x3F000,
 BL31_TRACE_DMSS_SIZE = 0x10000,
};
#define RDR_RESERVED_BL31_EXCEPTION_TRACE_SIZE (0x4F100)
#define RDR_RESERVED_BL31_EXCEPTION_TRACE_BASE ((RESERVED_MNTN_PHYMEM_BASE + RESERVED_MNTN_PHYMEM_SIZE) - 0x50000 + 0x200)
#define SUB_RESERVED_FASTBOOT_LOG_PYHMEM_BASE 0x11640000
#define SUB_RESERVED_FASTBOOT_LOG_PYHMEM_SIZE 0x40000
#define SUB_RESERVED_UNUSED_PHYMEM_BASE 0x116A4000
#define RESERVED_PSTORE_PHYMEM_BASE 0x1B410000
#define RESERVED_PSTORE_PHYMEM_SIZE 0x100000
#define RESERVED_MNTN_PHYMEM_BASE 0x1B510000
#define RESERVED_KERNEL_DUMP_PROTECT_BASE 0x80000000
#define RESERVED_KERNEL_DUMP_PRORECT_SIZE 0x20000000
typedef struct dmss_asi_sec_fail_info_s{
 SOC_DMSS_ASI_SEC_INT_STATUS_UNION asi_sec_int_status;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF0_UNION asi_sec_fail_cmd_inf0;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF1_UNION asi_sec_fail_cmd_inf1;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF2_UNION asi_sec_fail_cmd_inf2;
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
typedef struct dmss_exception_trace_s {
 unsigned long long e_32k_time;
 dmss_asi_sec_fail_info asi_sec[MNTN_DMSS_ACPU_ASI_MAX];
 dmss_dmi_sec_fail_info dmi_sec;
 dmss_ami_sec_fail_info ami_sec;
 dmss_dmi_mpu_fail_info dmi_mpu;
 dmss_ami_mpu_fail_info ami_mpu;
} dmss_exception_trace_t;
enum SECMEM_MODULE {
 M3_DDR_MEM,
 BL31_LOG_MEM,
 MAX_MEM,
};
struct mntn_reg_val {
        unsigned int init_flag;
        unsigned int scsysstat;
        unsigned int bootpoint;
};
void mntn_reg_save(void *mntn_reg);
void mntn_reg_restore(void *mntn_reg);
#if defined(CONFIG_GCOV_KERNEL) || defined(CONFIG_HISI_GCOV_FASTBOOT)
struct mdump_gcov {
 unsigned long gcda_addr;
 unsigned int gcda_size;
};
#endif
#endif
