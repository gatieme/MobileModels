#ifndef __NPU_CONFIG_FLOW_H__
#define __NPU_CONFIG_FLOW_H__ 
#define REG_INFO_SIZE (64)
struct module_regs_s {
  unsigned long long addr;
  unsigned long long op_type;
  unsigned long long mask;
  unsigned long long value;
  unsigned int wait_time;
  char info[REG_INFO_SIZE];
};
#endif
