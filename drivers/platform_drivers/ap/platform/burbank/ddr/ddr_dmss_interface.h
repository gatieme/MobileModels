#ifndef __DDR_DMSS_INTERFACE_H__
#define __DDR_DMSS_INTERFACE_H__ 
#ifndef __SOC_H_FOR_ASM__
#define SOC_DMSS_GLB_STAT_CTRL_ADDR(base) ((base) + (0x16400UL))
#define SOC_DMSS_ASI_DYN_CKG_ADDR(base,asi_base) ((base) + (0x014+0x800*(asi_base)))
#else
#define SOC_DMSS_ASI_DYN_CKG_ADDR(base,asi_base) ((base) + (0x014+0x800*(asi_base)))
#define SOC_DMSS_GLB_STAT_CTRL_ADDR(base) ((base) + (0x16400))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
  unsigned int ckg_byp_asi : 1;
  unsigned int ckg_byp_ra : 1;
  unsigned int ckg_byp_arcs : 1;
  unsigned int ckg_byp_awcs : 1;
  unsigned int ckg_byp_wd : 1;
  unsigned int ckg_byp_b : 1;
  unsigned int ckg_byp_rd : 1;
  unsigned int ckg_byp_fkrd : 1;
  unsigned int ckg_byp_asi_sec : 1;
  unsigned int ckg_byp_rdr_est : 1;
  unsigned int ckg_byp_rdr_buf : 1;
  unsigned int ckg_byp_async : 1;
  unsigned int ckg_byp_ca : 1;
  unsigned int ckg_byp_qos_bwc : 1;
  unsigned int ckg_byp_qos_lat : 1;
  unsigned int ckg_byp_stat : 1;
  unsigned int ckg_byp_wooo : 1;
  unsigned int ckg_byp_detect : 1;
  unsigned int reserved : 14;
 } reg;
} SOC_DMSS_ASI_DYN_CKG_UNION;
#endif
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_asi_START (0)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_asi_END (0)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_ra_START (1)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_ra_END (1)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_arcs_START (2)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_arcs_END (2)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_awcs_START (3)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_awcs_END (3)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_wd_START (4)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_wd_END (4)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_b_START (5)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_b_END (5)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rd_START (6)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rd_END (6)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_fkrd_START (7)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_fkrd_END (7)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_asi_sec_START (8)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_asi_sec_END (8)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rdr_est_START (9)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rdr_est_END (9)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rdr_buf_START (10)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_rdr_buf_END (10)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_async_START (11)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_async_END (11)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_ca_START (12)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_ca_END (12)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_qos_bwc_START (13)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_qos_bwc_END (13)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_qos_lat_START (14)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_qos_lat_END (14)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_stat_START (15)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_stat_END (15)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_wooo_START (16)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_wooo_END (16)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_detect_START (17)
#define SOC_DMSS_ASI_DYN_CKG_ckg_byp_detect_END (17)
#endif
