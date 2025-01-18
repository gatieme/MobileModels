#ifndef __FREQDUMP_PLAT_H__
#define __FREQDUMP_PLAT_H__ 
#include <stdbool.h>
#include <tsensor_interface.h>
#include <freqdump_plat_common.h>
#include <loadmonitor_plat.h>
#define MAX_NPU_MODULE_SHOW 4
#define MAX_APLL_TYPE 6
#define MAX_APLL_CTRL 2
#define MAX_PPLL_TYPE 5
#define MAX_PPLL_CTRL 2
#define NPU_FREQ_VOLT 2
#define MAX_NPU_NAME_LEN 10
#define MAX_AO_VOTE_NUM 3
struct gpu_info {
 unsigned int pwr_status;
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int freq;
};
struct ddr_info {
 unsigned int ddr_freq_khz;
 unsigned int dmss_freq_khz;
 struct loadmonitor_ddr ddr_flux;
 unsigned int dmc_work_mode;
 unsigned int tmon_refi;
 unsigned int ddr_type;
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int vdd2h_voltage;
};
#define NPU_INFO_FROM_KERNEL 
struct npu_info {
 unsigned int freq_volt[MAX_NPU_MODULE_SHOW][NPU_FREQ_VOLT];
 char name[MAX_NPU_MODULE_SHOW][MAX_NPU_NAME_LEN];
};
struct peri_info {
 unsigned int vote[MAX_PERI_VOTE_TYPE];
 unsigned int clk_div;
 unsigned int voltage;
 unsigned int mem_voltage;
};
struct ao_info {
 unsigned int vote[MAX_AO_VOTE_NUM];
 unsigned int freq;
 unsigned int voltage;
 unsigned int mem_voltage;
};
struct cpu_info {
 unsigned int clk_sel_little;
 unsigned int voltage_little;
 unsigned int voltage_middle;
 unsigned int voltage_big;
 unsigned int mem_voltage_little;
 unsigned int mem_voltage_middle;
 unsigned int mem_voltage_big;
 unsigned int temp_little;
 unsigned int temp_middle;
 unsigned int temp_big;
 unsigned int iso_stat;
};
struct l3_info {
 unsigned int clk_sel;
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int pwr_stat;
};
struct clock_info {
 unsigned int apll[MAX_APLL_TYPE][MAX_APLL_CTRL];
 unsigned int ppll[MAX_PPLL_TYPE][MAX_PPLL_CTRL];
};
struct temp_info {
 long module_temp[MAX_MODULE_TEMP];
 long tsensor_temp[SENSOR_UNKNOWN_MAX];
};
struct freqdump_data {
 struct clock_info clock;
 struct cpu_info cpu;
 struct ddr_info ddr;
 struct l3_info l3;
 struct peri_info peri;
 struct ao_info ao;
 struct npu_info npu;
 struct gpu_info gpu;
 struct temp_info temp;
 unsigned int flags;
 bool is_fpga;
};
struct freqdump_and_monitor_data {
 struct loadmonitor_data monitor;
 struct freqdump_data freqdump;
};
#endif
