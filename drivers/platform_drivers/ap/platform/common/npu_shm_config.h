#ifndef __NPU_SHM_CONFIG_H__
#define __NPU_SHM_CONFIG_H__ 
#include <npu_ddr_map.h>
enum {
 NPU_SEC_FEATURE_UNSUPPORTED = 0,
 NPU_SEC_FEATURE_SUPPORTED,
};
struct npu_chip_cfg {
 unsigned int valid_magic;
 unsigned int aicore_disable_bitmap;
 unsigned int platform_specification;
};
typedef union {
 struct {
  unsigned int npu_sec_status;
  struct npu_chip_cfg chip_cfg;
 } cfg;
 unsigned char reserved[NPU_S_NPU_CONFIG_SIZE];
} npu_shm_cfg;
#endif
