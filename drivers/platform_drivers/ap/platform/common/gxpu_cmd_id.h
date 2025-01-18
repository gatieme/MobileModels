#ifndef __GXPU_CMD_ID_H__
#define __GXPU_CMD_ID_H__ 
#include <soc_pmctrl_xpu_interface.h>
#define WRITE_CMD_BIT 12U
#define READ_CMD_BIT 13U
#define SETTING_CMD_BIT 14U
#define CMD_VAL_MASK 0xFFFU
#define GXPU_SYNC_CMD_TIME_OUT 100000
#define MAX_GPU_PROFILE_CNT 20U
#define WR_VALUE_MASK 0x3fff
#define WR_SIGN_MASK BIT(14)
#define GPU_VOLT_DOWN_LIMIT 400
#define GPU_VOLT_UP_LIMIT 1200
#define GPU_PAMARGIN_NUM 2
enum gpu_power_state {
 GPU_PWR_ON,
 GPU_PWR_ONING,
 GPU_PWR_OFF,
 GPU_PWR_OFFING,
};
enum read_req_cmd {
 CMD_R_LOGIC_VOLT,
 CMD_R_MEM_VOLT,
 CMD_R_LOGIC_STEP_VOLT,
 CMD_R_MEM_STEP_VOLT,
 CMD_R_CUR_FREQ,
 CMD_R_FREQ_TABLE,
 CMD_R_LOGIC_VOL_TABLE,
 CMD_R_MEM_VOL_TABLE,
 CMD_R_PRO_COUNT,
 CMD_R_MAX,
};
enum write_req_cmd {
 CMD_W_PROFILE_VOL,
 CMD_W_AVS_VOL,
 CMD_W_DBG_GFVOLT,
 CMD_W_DBG_GMVOLT,
 CMD_W_CONTEXT,
 CMD_W_MAX,
};
enum setting_req_cmd {
 CMD_S_VOL_TYPE,
 CMD_S_DISABLE_PRO,
 CMD_S_LOGIC_VOLT,
 CMD_S_FREQ_BY_PID,
 CMD_S_BIAS_LOGIC_VOLT,
 CMD_S_MEM_VOLT,
 CMD_S_MIN_MAX_PRO,
 CMD_S_ATE_FEATURE,
 CMD_S_SVFD_TRIM,
 CMD_S_UPDATE_NV,
 CMD_S_MAX,
};
enum gxpu_cmd_type {
 TYPE_READ,
 TYPE_WRITE,
 TYPE_SETTING,
};
enum context_subcmd {
 CMD_CONTEXT_PROFDIS,
 CMD_CONTEXT_PROFILE_VOLT,
 CMD_CONTEXT_AVS_VOLT,
 CMD_CONTEXT_PA_MARGIN,
 CMD_CONTEXT_MAX
};
struct cx_element {
 unsigned short logic_volt;
 unsigned short mem_volt;
 unsigned short avs_volt[8];
 unsigned short avs_mem_volt;
 unsigned short pa_margin[GPU_PAMARGIN_NUM];
 unsigned char prof_dis;
};
struct gxpu_cmd {
 unsigned int cmd;
 enum gxpu_cmd_type type;
 unsigned int data[MAX_GPU_PROFILE_CNT];
 unsigned int len;
};
#define lp_gxpu_send_cmd(cmd_s,time_out) \
({ \
 vote.reg.freq_vote_d_channel0 = (unsigned int)cmd_s->cmd; \
 vote.reg.freq_vote_d0_msk0 = 1; \
 vote.reg.freq_vote_d_channel1 = cmd_s->len; \
 vote.reg.freq_vote_d0_msk1 = 1; \
 writel(vote.value, xpu_pmctrl_addr(FREQ_VOTE_D0)); \
                                                                           \
 while (vote.reg.freq_vote_d_channel0 == (unsigned int)cmd_s->cmd && time_out != 0) { \
  udelay(1); \
  time_out--; \
  vote.value = readl(xpu_pmctrl_addr(FREQ_VOTE_D0)); \
 } \
                                                                           \
                                                                    \
 vote.reg.freq_vote_d_channel1; \
})
#define lp_gxpu_get_data(buf,len,i,j) \
{ \
 for (i = 0, j = 0; i < len; i = i + 2, j++) { \
  vote.value = readl(xpu_pmctrl_addr(FREQ_VOTE_E0) + j * 4);\
  buf[i] = vote.reg.freq_vote_d_channel0; \
  if (i + 1 < len) \
   buf[i + 1] = vote.reg.freq_vote_d_channel1; \
 } \
}
#define lp_gxpu_set_data(buf,len,i,j) \
{ \
 for (i = 0, j = 0; i < len; i = i + 2, j++) { \
  vote.reg.freq_vote_d_channel0 = (unsigned int)buf[i]; \
  vote.reg.freq_vote_d0_msk0 = 1; \
  if (i + 1 < len) { \
   vote.reg.freq_vote_d_channel1 = (unsigned int)buf[i + 1]; \
   vote.reg.freq_vote_d0_msk1 = 1; \
  } \
  writel(vote.value, xpu_pmctrl_addr(FREQ_VOTE_E0) + j * 4); \
 } \
}
#define lp_gxpu_set_cmd(type,cmd) \
 switch(type) { \
  case TYPE_WRITE: \
   cmd |= BIT(WRITE_CMD_BIT); \
   break; \
  case TYPE_READ: \
   cmd |= BIT(READ_CMD_BIT); \
   break; \
  case TYPE_SETTING: \
   cmd |= BIT(SETTING_CMD_BIT); \
   break; \
  default: \
   return 0; \
 }
#endif
