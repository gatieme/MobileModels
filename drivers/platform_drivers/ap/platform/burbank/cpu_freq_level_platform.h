#ifndef __CPU_FREQ_LEVEL_PLATFORM_H__
#define __CPU_FREQ_LEVEL_PLATFORM_H__ 
#include <cpu_cluster_def.h>
#include <soc_spec_info.h>
enum chip_freq_level {
 NORMAL_LEVEL_FREQ,
 LOW_LEVEL_FREQ,
 FREQ_LEVEL_MAX,
};
#define NORMAL_LEVEL_FREQ_VALID (0x1)
#define LOW_LEVEL_FREQ_VALID (0x2)
struct freq_property {
 unsigned int freq_valid[FREQ_LEVEL_MAX];
 unsigned int efuse_freq_level[CPU_FCM_ALL_CNT];
 unsigned int is_freq_update_need[FREQ_LEVEL_MAX][CPU_FCM_ALL_CNT];
};
static struct freq_property g_freq_property = {
 .freq_valid = {
  [NORMAL_LEVEL_FREQ] = NORMAL_LEVEL_FREQ_VALID,
  [LOW_LEVEL_FREQ] = LOW_LEVEL_FREQ_VALID,
 },
 .efuse_freq_level = {
  [CPU_LIT_CLUSTER] = FREQ_INVALID,
  [CPU_MID_CLUSTER] = FREQ_INVALID,
  [CPU_BIG_CLUSTER] = FREQ_INVALID,
  [CPU_FCM_CLUSTER] = FREQ_INVALID,
 },
 .is_freq_update_need = {
  [NORMAL_LEVEL_FREQ] = { 0, 0, 0, 0 },
  [LOW_LEVEL_FREQ] = { 1, 1, 1, 1 },
 },
};
#define cpu_efuse_freq_level_update(phase) ({ \
 g_freq_property.efuse_freq_level[CPU_LIT_CLUSTER] = get_module_freq_level(phase, cpul); \
 g_freq_property.efuse_freq_level[CPU_MID_CLUSTER] = get_module_freq_level(phase, cpum); \
 g_freq_property.efuse_freq_level[CPU_BIG_CLUSTER] = get_module_freq_level(phase, cpub); \
 g_freq_property.efuse_freq_level[CPU_FCM_CLUSTER] = get_module_freq_level(phase, cpul3); \
})
static inline unsigned int is_freq_update_needed(unsigned int cluster, unsigned int freq_level)
{
 return g_freq_property.is_freq_update_need[freq_level][cluster];
}
static inline unsigned int is_freq_vaild(unsigned int hw_version, unsigned int freq_level)
{
 return hw_version & g_freq_property.freq_valid[freq_level];
}
#endif
