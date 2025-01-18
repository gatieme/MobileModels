#ifndef __LOAD_LPMCU_COMMON_H__
#define __LOAD_LPMCU_COMMON_H__ 
#include <trim.h>
#include <lp_debug.h>
#include <lpmcu_runtime.h>
#define MAX_CPU_MEMORY_STEP_NUM 4
#define MAX_FCM_MEMORY_STEP_NUM 2
struct lpnv_state_type {
 unsigned int valid;
 unsigned int state;
};
struct lpnv_value_type {
 int lowtemp_volt[MAX_CLUSTER];
 int thermal_die_threshold;
 int thermal_high_threshold;
 int thermal_nor_threshold;
 int ao_volt_bias;
};
struct lpmcu_config {
 unsigned char freq_array_exist[MAX_CLUSTER];
 unsigned char min_freq[MAX_CLUSTER];
 unsigned char max_freq[MAX_CLUSTER];
 struct lpnv_state_type lpnv_state[LP_MODULE_IP_MAX];
 struct lpnv_value_type lpnv_value;
 unsigned int general_see_data;
 unsigned char is_modem;
 unsigned int cpumem_volt_bias[MAX_CPU_MEMORY_STEP_NUM];
 unsigned int fcmmem_volt_bias[MAX_FCM_MEMORY_STEP_NUM];
 unsigned char vbat_drop_value;
};
#endif
