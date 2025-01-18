#ifndef __AO_VOLT_COMMON_H_
#define __AO_VOLT_COMMON_H_ 
#include <peri_ao_volt.h>
#include <soc_sctrl_interface.h>
#include <pmic_interface.h>
#define AO_VOLT_REG_ADDR PMIC_LDO0_VSET_ADDR(0)
#define AO_VOLT_ECO_REG_ADDR PMIC_LDO0_VSET_ECO_ADDR(0)
#define AO_VOLT_STEP 10
#define AO_VOLT_BASE 500
#define ao_volt_mv2code(mv) pmu_mv2code(mv, AO_VOLT_BASE, AO_VOLT_STEP)
#define ao_volt_code2mv(code) pmu_code2mv(code, AO_VOLT_BASE, AO_VOLT_STEP)
#define AO_AVS_DNLIMIT 535
#define AO_HOLD_TIME 70
#define RAMP_RATIO 60
enum ao_volt_level {
 AO_VOLT_LEVEL0,
 AO_VOLT_LEVEL1,
 AO_VOLT_LEVEL_MAX,
};
#define AO_VOL_LOWTEMP AO_VOLT_LEVEL1
enum ao_vote_module {
 AO_VOTE_MODULE_IOMCU,
 AO_VOTE_MODULE_ASP,
 AO_VOTE_MODULE_LOWTEMP,
 AO_VOTE_MODULE_STD,
 AO_VOTE_MODULE_MAX
};
enum ao_avs_page {
 AO_AVS_STD,
 AO_AVS_IOMCU,
 AO_AVS_ASP,
 AO_AVS_END,
};
#define AO_AVS_BASE AO_AVS_IOMCU
union ao_vote_reg {
 unsigned int value;
 struct {
  unsigned int vote0: 2;
  unsigned int vote1: 2;
  unsigned int vote2: 2;
  unsigned int vote3: 2;
  unsigned int vote4: 2;
  unsigned int vote5: 2;
  unsigned int vote6: 2;
  unsigned int vote7: 2;
  unsigned int valid0: 1;
  unsigned int valid1: 1;
  unsigned int valid2: 1;
  unsigned int valid3: 1;
  unsigned int valid4: 1;
  unsigned int valid5: 1;
  unsigned int valid6: 1;
  unsigned int valid7: 1;
  unsigned int rsv: 5;
  unsigned int avs_done: 1;
  unsigned int vote_result: 2;
 } reg;
};
#define AO_VOTE_MASK 0x3
#define ao_vote_offset(vote) ((unsigned int)(vote) * 2)
#define ao_vote_clr(src,vote) ((src) &= (~(unsigned int)(AO_VOTE_MASK << ao_vote_offset(vote))))
#define ao_vote_get(src,vote) (((src) >> ao_vote_offset(vote)) & AO_VOTE_MASK)
#define ao_vote_set(src,vote,lvl) do { \
 ao_vote_clr(src, vote); \
 (src) |= ((lvl) & AO_VOTE_MASK) << ao_vote_offset(vote); \
} while (0)
#define ao_valid_offset(vote) ((unsigned int)(vote) + 16)
#define ao_vote_enable(src,vote) ((src) |= (1 << ao_valid_offset(vote)))
#define ao_vote_disable(src,vote) ((src) &= (~(unsigned int)(1 << ao_valid_offset(vote))))
#define ao_vote_is_enable(src,vote) ((src >> ao_valid_offset(vote)) & 0x1)
#define ao_vote_reg_addr(cpu,vote) (SOC_SCTRL_SCBAKDATA17_ADDR(SOC_ ##cpu ##_SCTRL_BASE_ADDR))
#endif
