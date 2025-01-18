#ifndef __LP_GPU_PLATFORM_H__
#define __LP_GPU_PLATFORM_H__ 
#include "soc_crgperiph_interface.h"
#include "soc_pmctrl_interface.h"
#define APLL2_CFG0_VALUE 0x44831022
#define APLL2_CFG1_VALUE 0x0000005F
#define APLL2_CFG2_VALUE 0x800180A6
#define APLL2_CFG3_VALUE 0x0028E291
struct prof_ctrl {
 unsigned int prof_dis : 1;
 unsigned int idle_div_en : 1;
 unsigned int svfd_en : 1;
 unsigned int active_defense_en : 1;
 unsigned int hpm_en : 1;
};
struct gpu_info {
 unsigned int prof_mask;
 unsigned char lowtemp_freq_id;
 unsigned char lowtemp_volt_id;
};
struct gpu_runtime {
 unsigned char gpu_current;
 unsigned char gpu_target;
 unsigned char gpu_tctrl;
 unsigned char gpu_last;
 unsigned char gpu_min;
 unsigned char gpu_max;
 unsigned char gpu_low_tctrl;
 unsigned char gpu_step;
 unsigned char gpu_status;
 unsigned char gpu_online_num;
 unsigned char gpu_online_status;
 unsigned char gpu_pll;
 unsigned short gpu_lowtemp_volt;
 unsigned short gpu_lowtemp_mem_volt;
};
#ifdef CONFIG_XLOADER_LP_GPU
struct gpu_profile {
 const unsigned short freq;
 const unsigned int pllctrl0;
 const unsigned int pllctrl1;
 const unsigned char pllsel;
 const unsigned char plldiv;
 unsigned short logic_volt;
 unsigned short mem_volt;
 struct prof_ctrl ctrl;
};
#else
#define AVS_TZONE_NUM 8
#define DDR_LINK_LVL_NUM 2
struct gpu_profile {
 const unsigned short freq;
 const unsigned char hpmclkdiv;
 unsigned short avs_volt[AVS_TZONE_NUM];
 unsigned int pllctrl0;
 unsigned int pllctrl1;
 unsigned char pllsel;
 unsigned char plldiv;
 unsigned short logic_volt;
 unsigned short mem_volt;
 unsigned short avsvoluplimit;
 unsigned short avsvoldnlimit;
 unsigned char idle_div;
 unsigned short svfd_code;
 struct prof_ctrl ctrl;
};
enum svfd_enable_mode {
 SVFD_SHUTDOWN,
 SVFD_CPM,
 SVFD_VDM,
 SVFD_CPM_VDM,
};
enum cpmffs_reset_mode {
 CPM_MODE,
 FFS_MODE,
 CPM_FFS_MODE,
 CPMFFS_MODE_MAX,
};
#define CPMFSS_RSTDIS_ADDR SOC_CRGPERIPH_PERRSTDIS5_ADDR
#define CPMFSS_RSTEN_ADDR SOC_CRGPERIPH_PERRSTEN5_ADDR
#define VS_SVFD_CTRL0_ADDR SOC_CRGPERIPH_VS_SVFD_CTRL0_G3D_ADDR
#define VS_SVFD_CTRL1_ADDR SOC_CRGPERIPH_VS_SVFD_CTRL1_G3D_ADDR
#define VS_SVFD_CTRL2_ADDR SOC_CRGPERIPH_VS_SVFD_CTRL2_G3D_ADDR
#define VS_SVFD_CTRL3_ADDR SOC_CRGPERIPH_VS_SVFD_CTRL3_G3D_ADDR
#define VS_SVFD_CTRL_ADDR SOC_PMCTRL_VS_CTRL_GPU_ADDR
#define VS_CPM_DATA_STAT_ADDR SOC_CRGPERIPH_VS_CPM_DATA_STAT_G3D_ADDR
#endif
#endif
