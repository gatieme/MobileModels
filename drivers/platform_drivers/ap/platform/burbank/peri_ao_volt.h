#ifndef PERI_AO_VOLT_H_
#define PERI_AO_VOLT_H_ 
#include <soc_pmctrl_interface.h>
#include <soc_spec_info.h>
#ifndef PMC_BASE
#if defined(__FASTBOOT__) || defined(CONFIG_BL2_LOAD_LPMCU)
#include <soc_acpu_baseaddr_interface.h>
#define PMC_BASE SOC_ACPU_PMC_BASE_ADDR
#else
#include <soc_lpmcu_baseaddr_interface.h>
#define PMC_BASE SOC_LPMCU_PMC_BASE_ADDR
#endif
#endif
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif
#define BIT_OF_CHAR 8
#define is_support_share_image (get_lpmcu_chip_version() == VERSION_V120)
#define is_ap_support_share_image (get_acpu_chip_version() == VERSION_V120)
#define MV2UV 1000
#define MAX_VOLT_BIAS 200
#define pmu_mv2code(mv,base,step) ((mv) <= (base) ? 0 : ((mv) - (base) + (step) - 1) / (step))
#define pmu_code2mv(code,base,step) ((code) * (step) + base)
#define LPMCU_VOTE_REG (SOC_PMCTRL_PERI_CTRL4_ADDR(PMC_BASE))
#define AP_VOTE_REG (SOC_PMCTRL_PERI_CTRL5_ADDR(PMC_BASE))
enum avs_tzone_idx {
 AVS_TZONE0,
 AVS_TZONE1,
 AVS_TZONE2,
 AVS_TZONE3,
 AVS_TZONE4,
 AVS_TZONE5,
 AVS_TZONE_VALID_NUM,
 AVS_TZONE6 = AVS_TZONE_VALID_NUM,
 AVS_TZONE7,
 AVS_TZONE_END
};
enum dpm_rank_idx {
 RANK_IDX_0 = 0,
 RANK_IDX_1,
 RANK_IDX_2,
 RANK_IDX_3,
 RANK_IDX_4,
 RANK_IDX_5,
 RANK_IDX_6,
 RANK_IDX_MAX
};
#define RANK_IDX_VAL(x,y,z,w) (((x) & 0xFF) | (((y) & 0xFF) << 8) | (((z) & 0xFF) << 16) | (((w) & 0xFF) << 24))
typedef union {
 unsigned int value;
 struct {
  unsigned int volt_0 : 2;
  unsigned int volt_1 : 2;
  unsigned int volt_2 : 2;
  unsigned int volt_3 : 2;
  unsigned int volt_4 : 2;
  unsigned int volt_5 : 2;
  unsigned int volt_6 : 2;
  unsigned int volt_7 : 2;
  unsigned int volt_8 : 2;
  unsigned int volt_9 : 2;
  unsigned int volt_10 : 2;
  unsigned int volt_11 : 2;
  unsigned int volt_12 : 2;
  unsigned int volt_13 : 2;
  unsigned int volt_14 : 2;
  unsigned int volt_15 : 1;
  unsigned int coresight_vote : 1;
 } reg;
} VOLT_VOTE_REG_AP;
typedef union {
 unsigned int value;
 struct {
  unsigned int volt_0 : 2;
  unsigned int volt_1 : 2;
  unsigned int volt_2 : 2;
  unsigned int volt_3 : 2;
  unsigned int volt_4 : 2;
  unsigned int volt_5 : 2;
  unsigned int volt_6 : 2;
  unsigned int volt_7 : 2;
  unsigned int volt_8 : 2;
  unsigned int volt_lock_ao : 4;
  unsigned int volt_lock_peri : 4;
  unsigned int lowtemp : 2;
  unsigned int rsv : 4;
 } reg;
} VOLT_VOTE_REG_LPM3;
#define SYSTEM_VOLT_LEVEL_MAX 4
#define AVS_PAGE_MAX 16
#define PERI_REG_LEVEL_NUM_MAX 4
#define REG_VALID_BIT_NUM 16
#define VOTE_BIT_NUM 2
#define VOTE_BIT_MAK ((1 << VOTE_BIT_NUM) - 1)
#define MK_MASK_VAL(val,msk,start) ((((unsigned int)(val) & (msk)) << (unsigned int)(start)) | \
  ((msk) << ((unsigned int)(start) + 16)))
#define VOLT_VOTE_SET(val,vote) MK_MASK_VAL(val, VOTE_BIT_MAK, ((unsigned int)(vote) * VOTE_BIT_NUM) % REG_VALID_BIT_NUM)
#define VOLT_VOTE_GET(val,vote) (((val) >> (((unsigned int)(vote) * VOTE_BIT_NUM) % REG_VALID_BIT_NUM)) & VOTE_BIT_MAK)
#define vote_reg_addr(base_ptr,type,vote) ({ \
 void *_addr = (void *)(base_ptr); \
 unsigned int _reg_idx = (vote) / (REG_VALID_BIT_NUM / VOTE_BIT_NUM); \
 if (_reg_idx == 0) \
  _addr += offsetof(type, sft_vol_vote0); \
 else if (_reg_idx == 1) \
  _addr += offsetof(type, sft_vol_vote1); \
 else \
  _addr = NULL; \
 (volatile typeof((base_ptr)->sft_vol_vote0) *)_addr; \
 })
#define LEVEL_NUM_EACH_REG 4
#define VOL_IDX_VAL(idx,val) (((val) & 0xFF) << (((unsigned int)(idx) % LEVEL_NUM_EACH_REG) * 8))
#define VOL_IDX_GET(idx,val) (((val) >> (((unsigned int)(idx) % LEVEL_NUM_EACH_REG) * 8)) & 0xFF)
struct bus_clk_cfg {
 unsigned int pclk_sel;
 unsigned int pclk_id;
 unsigned int div;
 unsigned int div_addr;
};
struct bus_clk_parent {
 unsigned int addr;
 unsigned short bitmsk;
 unsigned short shift;
};
struct bus_clk {
 struct bus_clk_parent pclk;
 struct bus_clk_cfg *cfg;
 unsigned int cfg_size;
};
struct volt_obj {
 unsigned int pmu_step;
 int (*set_volt)(unsigned int mv);
};
#endif
