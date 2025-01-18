#ifndef DUBAI_HW_VOTE_H
#define DUBAI_HW_VOTE_H 
#include "ddr_vote_statistic_struct.h"
#define DDR_VOTE_NUM 19
static struct ddr_vote_ip g_ddr_vote_table[DDR_VOTE_NUM] = {
 { LIT_CLUSTER_ID, "lit_cluster" },
 { BIG_CLUSTER_ID, "big_cluster" },
 { GPU_ID, "gpu" },
 { IOMCU_ID, "iomcu" },
 { MODEM_ID, "modem" },
 { TEMPERTURE_ID, "temperture" },
 { MID_CLUSTER_ID, "mid_cluster" },
 { L3_CLUSTER_ID, "l3_cluster" },
 { CPU_MONITOR_ID, "cpu_monitor"},
 { AP_SR_ID, "ap_sr"},
 { PERI_VOLT_ID, "peri_volt"},
 { MODEM_5G_ID, "modem_5g"},
 { FLOOR_VOTE_HW_AP_ID, "hw_ap" },
 { FLOOR_VOTE_HW_HIFI_ID, "hw_hifi" },
 { FLOOR_VOTE_HW_IOMCU_ID, "hw_iomcu" },
 { FLOOR_VOTE_HW_LIT_LAT_ID, "hw_lit_lat" },
 { FLOOR_VOTE_HW_BIG_LAT_ID, "hw_big_lat" },
 { FLOOR_VOTE_HW_MID_LAT_ID, "hw_mid_lat" },
 { FLOOR_VOTE_HW_LATSTAT_ID, "hw_latstat" },
};
#endif
