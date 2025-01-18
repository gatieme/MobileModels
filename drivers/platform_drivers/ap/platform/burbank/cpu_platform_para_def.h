#ifndef __CPU_PLATFORM_PARA_DEF_H__
#define __CPU_PLATFORM_PARA_DEF_H__ 
#include <cpu_cluster_def.h>
#define CPU_MAX_AVS_TZONE 8
typedef struct {
 unsigned short freq;
 unsigned char volprofile;
 unsigned char memvoltprofile;
 unsigned char avs_volt[CPU_MAX_AVS_TZONE];
 unsigned short ddr_freq_limit[2];
 unsigned int apll_ctrl0;
 unsigned int apll_ctrl1;
 unsigned char clkdiv;
 unsigned char div_code;
 unsigned short svfd_code;
 unsigned char feature_switch;
 unsigned char idle_clkdiv;
 unsigned short pcr_a_x;
 unsigned char pcr_a_y;
 unsigned char pcr_c_y;
 unsigned short pcr_c_z;
 unsigned int pcr_c_x;
 unsigned int hw_version;
 unsigned char mem_avs_volt;
} cpu_profile;
#endif
