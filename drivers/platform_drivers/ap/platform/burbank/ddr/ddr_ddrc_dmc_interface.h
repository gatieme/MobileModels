#ifndef __DDR_DDRC_DMC_INTERFACE_H__
#define __DDR_DDRC_DMC_INTERFACE_H__ 
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900UL))
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918UL))
#define SOC_DDRC_DMC_DDRC_CFG_STAID_ADDR(base) ((base) + (0x938UL))
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_ADDR(base) ((base) + (0x93CUL))
#else
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_ADDR(base) ((base) + (0x900))
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_ADDR(base) ((base) + (0x918))
#define SOC_DDRC_DMC_DDRC_CFG_STAID_ADDR(base) ((base) + (0x938))
#define SOC_DDRC_DMC_DDRC_CFG_STAIDMSK_ADDR(base) ((base) + (0x93C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
 unsigned int value;
 struct {
  unsigned int dat_stat_en : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_DDRC_DMC_DDRC_CTRL_STADAT_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_dat_stat_en_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_STADAT_dat_stat_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
 unsigned int value;
 struct {
  unsigned int load_stat_en : 1;
  unsigned int reserved : 31;
 } reg;
} SOC_DDRC_DMC_DDRC_CTRL_STACMD_UNION;
#endif
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_load_stat_en_START (0)
#define SOC_DDRC_DMC_DDRC_CTRL_STACMD_load_stat_en_END (0)
#endif
