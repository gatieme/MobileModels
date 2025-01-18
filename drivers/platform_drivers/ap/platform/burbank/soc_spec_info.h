#ifndef __SOC_SPEC_INFO_H__
#define __SOC_SPEC_INFO_H__ 
typedef union
{
 unsigned int value;
 struct
 {
  unsigned int reserved : 22;
  unsigned int chip_version : 2;
  unsigned int soc_spec_info : 4;
  unsigned int magic : 4;
 } reg;
} SELF_SCTRL_SPEC_UNION;
enum soc_spec_level {
 SOC_SPEC_LEVEL1 = 0,
 SOC_SPEC_LEVEL2,
 SOC_SPEC_PAD = 1,
 SOC_SPEC_PARTIAL_GOOD,
 SOC_SPEC_LITE_PHONE = 2,
 SOC_SPEC_MAX,
 SOC_SPEC_INVALID = 0xF
};
enum module_freq_level {
 FREQ_LEVEL1 = 0,
 FREQ_LEVEL2,
 FREQ_INVALID
};
struct soc_module_type {
 unsigned int cpul;
 unsigned int cpum;
 unsigned int cpub;
 unsigned int cpul3;
 unsigned int gpu;
 unsigned int modem;
 unsigned int npu;
 unsigned int ddr;
 unsigned int peri;
 unsigned int audio;
 unsigned int iomcu;
};
static struct soc_module_type g_soc_info[SOC_SPEC_MAX] __attribute__((__used__)) = {
 {
  .cpul = FREQ_LEVEL1,
  .cpum = FREQ_LEVEL1,
  .cpub = FREQ_LEVEL1,
  .cpul3 = FREQ_LEVEL1,
  .gpu = FREQ_LEVEL1,
  .modem = FREQ_LEVEL1,
  .npu = FREQ_LEVEL1,
  .ddr = FREQ_LEVEL1,
  .peri = FREQ_LEVEL1,
  .audio = FREQ_LEVEL1,
  .iomcu = FREQ_LEVEL1,
 },
 {
  .cpul = FREQ_LEVEL1,
  .cpum = FREQ_LEVEL1,
  .cpub = FREQ_LEVEL1,
  .cpul3 = FREQ_LEVEL1,
  .gpu = FREQ_LEVEL1,
  .modem = FREQ_LEVEL1,
  .npu = FREQ_LEVEL1,
  .ddr = FREQ_LEVEL1,
  .peri = FREQ_LEVEL1,
  .audio = FREQ_LEVEL1,
  .iomcu = FREQ_LEVEL1,
 },
 {
  .cpul = FREQ_LEVEL1,
  .cpum = FREQ_LEVEL1,
  .cpub = FREQ_LEVEL1,
  .cpul3 = FREQ_LEVEL1,
  .gpu = FREQ_LEVEL1,
  .modem = FREQ_LEVEL1,
  .npu = FREQ_LEVEL1,
  .ddr = FREQ_LEVEL1,
  .peri = FREQ_LEVEL1,
  .audio = FREQ_LEVEL1,
  .iomcu = FREQ_LEVEL1,
 },
};
#define EFUSE_CHIP_VERSION_START 1335
#define EFUSE_CHIP_VERSION_SIZE 3
#define CHIP_VERSION_MASK 0x7
#define VERSION_V100_VALUE 0
#define VERSION_V110_VALUE 1
#define VERSION_V120_VALUE 2
enum CHIP_VERSION{
 VERSION_V100,
 VERSION_V110,
 VERSION_V120
};
unsigned int __attribute__((weak)) get_cmd_sepc_info(void){ return 0;}
#define SOC_SPEC_INFO_MAGIC 0xA
#define SOC_ACPU_SCTRL_BASE_ADDR_DEFINE (0xFA89B000)
#define SOC_LPMCU_SCTRL_BASE_ADDR_DEFINE (0x4021B000)
#define SCTRL_SPEC_INFO(core_type) \
 (*(volatile SELF_SCTRL_SPEC_UNION*)((SOC_##core_type##_SCTRL_BASE_ADDR_DEFINE) + (0x43CUL)))
#define get_soc_level_sctrl(core_type) \
 ((SCTRL_SPEC_INFO(core_type).reg.magic == SOC_SPEC_INFO_MAGIC) ? \
   SCTRL_SPEC_INFO(core_type).reg.soc_spec_info : SOC_SPEC_LEVEL1)
#define get_chip_version_sctrl(core_type) \
 ((SCTRL_SPEC_INFO(core_type).reg.magic == SOC_SPEC_INFO_MAGIC) ? \
   SCTRL_SPEC_INFO(core_type).reg.chip_version : VERSION_V110)
static inline unsigned int get_kernel_soc_level()
{
 return get_cmd_sepc_info();
}
static inline unsigned int get_lpmcu_soc_level()
{
 return get_soc_level_sctrl(LPMCU);
}
static inline unsigned int get_acpu_soc_level()
{
 return get_soc_level_sctrl(ACPU);
}
static inline unsigned int get_lpmcu_chip_version()
{
 return get_chip_version_sctrl(LPMCU);
}
static inline unsigned int get_acpu_chip_version()
{
 return get_chip_version_sctrl(ACPU);
}
#define get_module_freq_level(phase,module_type) ({ \
 unsigned int soc_type = get_##phase##_soc_level(); \
  (soc_type < SOC_SPEC_MAX) ? \
   g_soc_info[soc_type].module_type : FREQ_LEVEL1;})
#endif
