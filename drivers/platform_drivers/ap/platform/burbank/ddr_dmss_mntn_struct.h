#ifndef __DDR_DMSS_MNTN_STRUCT_H__
#define __DDR_DMSS_MNTN_STRUCT_H__ 
enum ddr_mntn_ipc_type {
 DDR_MNTN_CLEAN_INT = 0,
 DDR_MNTN_DISABLE_INT,
 DDR_MNTN_SET_GLB_INT_CLEAR1,
 DDR_MNTN_GET_DMSS_MNTN_INFO,
 DDR_DMSS_LPRAM_LOCK,
 DDR_MNTN_IPC_MAX_TYPE
};
struct ddr_mntn_ipc_msg {
 unsigned int ipc_cmd;
 unsigned int ack;
 unsigned int ipc_type;
 unsigned int reserved[5];
};
struct ddr_mntn_clean_int_info {
 unsigned int clear0_val;
 unsigned int clear1_val;
};
struct ddr_mntn_set_clear1_info {
 unsigned int clear1_val;
};
union ddr_mntn_ipc_data {
 struct ddr_mntn_clean_int_info clean_int_info;
 struct ddr_mntn_set_clear1_info set_clear1_info;
};
struct ddr_mntn_ipc_info {
 unsigned int ipc_type;
 union ddr_mntn_ipc_data ipc_data;
};
struct ddr_dmss_asi_sec_port_desc {
 SOC_DMSS_ASI_SEC_INT_STATUS_UNION asi_sec_int_status;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF0_UNION asi_sec_fail_cmd_inf0;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF1_UNION asi_sec_fail_cmd_inf1;
 SOC_DMSS_ASI_SEC_FAIL_CMD_INF2_UNION asi_sec_fail_cmd_inf2;
};
struct ddr_dmss_asi_dfx_abnm_desc {
 SOC_DMSS_ASI_DFX_INT_STATUS_UNION asi_dfx_int_status;
 SOC_DMSS_ASI_DFX_ABNM_INF0_UNION asi_dfx_abnm_inf0;
 SOC_DMSS_ASI_DFX_ABNM_INF1_UNION asi_dfx_abnm_inf1;
 SOC_DMSS_ASI_DFX_ABNM_INF2_UNION asi_dfx_abnm_inf2;
 SOC_DMSS_ASI_QOS_RDOSTD_UNION asi_qos_rdostd;
 SOC_DMSS_ASI_DFX_MODULE_UNION asi_dfx_module;
 SOC_DMSS_ASI_DFX_OSTD_UNION asi_dfx_ostd;
};
struct ddr_dmi_sec_irq_desc {
 SOC_DMSS_DMI_SEC_INT_STATUS_UNION dmi_sec_int_status;
};
struct ddr_dmi_sec_port_desc {
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF0_UNION dmi_sec_fail_cmd_inf0;
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF1_UNION dmi_sec_fail_cmd_inf1;
 SOC_DMSS_DMI_SEC_FAIL_CMD_INF2_UNION dmi_sec_fail_cmd_inf2;
};
struct ddr_dmi_enhn_desc {
 SOC_DMSS_DMI_ENHN_INT_STATUS_UNION dmi_enhn_int_status;
};
struct ddr_dmi_mpu_irq_desc {
 SOC_DMSS_DMI_MPU_INT_STATUS_UNION dmi_mpu_int_status;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF0_UNION dmi_mpu_fail_cmd_inf0;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF1_UNION dmi_mpu_fail_cmd_inf1;
 SOC_DMSS_DMI_MPU_FAIL_CMD_INF2_UNION dmi_mpu_fail_cmd_inf2;
};
struct ddr_dmi_enhn_cfg_irq_desc {
 SOC_DMSS_DMI_ENHN_CFG_INT_STATUS_UNION dmi_enhn_cfg_int;
};
struct ddr_dmss_mntn_desc {
 SOC_DMSS_GLB_INT_STATUS0_UNION glb_int_status0;
 SOC_DMSS_GLB_INT_STATUS1_UNION glb_int_status1;
 struct ddr_dmss_asi_sec_port_desc asi_sec_port[DMSS_ASI_MAX];
 struct ddr_dmss_asi_dfx_abnm_desc asi_dfx_abnm[DMSS_ASI_MAX];
 struct ddr_dmi_sec_irq_desc dmi_sec_int_port[DMSS_DMI_MAX];
 struct ddr_dmi_sec_port_desc dmi_sec_port[DMSS_DMI_MAX];
 struct ddr_dmi_enhn_desc dmi_enhn_port[DMSS_DMI_MAX];
 SOC_DMSS_GLB_DFX_MODULE_UNION glb_dfx_module;
 struct ddr_dmi_mpu_irq_desc dmi_mpu_irq_port[DMSS_DMI_MAX];
 struct ddr_dmi_enhn_cfg_irq_desc dmi_enhn_cfg_irq_port[DMSS_DMI_MAX];
 SOC_DMSS_GLB_ADDR_INTLV_UNION glb_addr_intlv;
};
#endif
