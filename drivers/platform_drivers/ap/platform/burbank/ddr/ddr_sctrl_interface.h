#ifndef __SOC_SCTRL_INTERFACE_H__
#define __SOC_SCTRL_INTERFACE_H__ 
#ifndef __SOC_H_FOR_ASM__
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41CUL))
#define SOC_SCTRL_SCPEREN1_ADDR(base) ((base) + (0x170UL))
#else
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41C))
#define SOC_SCTRL_SCPEREN1_ADDR(base) ((base) + (0x170))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
 unsigned int value;
 struct {
  unsigned int bakdata : 32;
 } reg;
} SOC_SCTRL_SCBAKDATA4_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA4_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA4_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
 unsigned int value;
 struct {
  unsigned int gt_clk_asp_dw_axi : 1;
  unsigned int gt_clk_asp_x2h : 1;
  unsigned int gt_clk_asp_h2p : 1;
  unsigned int gt_asp_cfg : 1;
  unsigned int gt_clk_asp_subsys_acpu : 1;
  unsigned int gt_clk_noc_aobus2sysbusddrc : 1;
  unsigned int reserved_0 : 1;
  unsigned int ddr_loopback_en : 1;
  unsigned int gt_clk_out1 : 1;
  unsigned int gt_clk_fll_src_tp : 1;
  unsigned int gt_pclk_timer4 : 1;
  unsigned int gt_clk_timer4 : 1;
  unsigned int gt_pclk_timer5 : 1;
  unsigned int gt_clk_timer5 : 1;
  unsigned int gt_pclk_timer6 : 1;
  unsigned int gt_clk_timer6 : 1;
  unsigned int gt_pclk_timer7 : 1;
  unsigned int gt_clk_timer7 : 1;
  unsigned int gt_pclk_timer8 : 1;
  unsigned int gt_clk_timer8 : 1;
  unsigned int gt_timerclk_refh : 1;
  unsigned int ddr_reset_en : 1;
  unsigned int gt_clk_hifd_fll : 1;
  unsigned int gt_clk_hifd_pll : 1;
  unsigned int gt_clk_noc_aobus2aspbus : 1;
  unsigned int gt_clk_noc_aobus2iomcubus : 1;
  unsigned int reserved_1 : 1;
  unsigned int gt_clk_asp_codec_acpu : 1;
  unsigned int gt_clk_autodiv_aonoc_pll : 1;
  unsigned int gt_clk_autodiv_aonoc_fll : 1;
  unsigned int gt_clk_hsdt_fdul_noc : 1;
  unsigned int wait_ddr_selfreflash_done_bypass : 1;
 } reg;
} SOC_SCTRL_SCPEREN1_UNION;
#endif
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_dw_axi_START (0)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_dw_axi_END (0)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_x2h_START (1)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_x2h_END (1)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_h2p_START (2)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_h2p_END (2)
#define SOC_SCTRL_SCPEREN1_gt_asp_cfg_START (3)
#define SOC_SCTRL_SCPEREN1_gt_asp_cfg_END (3)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_subsys_acpu_START (4)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_subsys_acpu_END (4)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2sysbusddrc_START (5)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2sysbusddrc_END (5)
#define SOC_SCTRL_SCPEREN1_ddr_loopback_en_START (7)
#define SOC_SCTRL_SCPEREN1_ddr_loopback_en_END (7)
#define SOC_SCTRL_SCPEREN1_gt_clk_out1_START (8)
#define SOC_SCTRL_SCPEREN1_gt_clk_out1_END (8)
#define SOC_SCTRL_SCPEREN1_gt_clk_fll_src_tp_START (9)
#define SOC_SCTRL_SCPEREN1_gt_clk_fll_src_tp_END (9)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer4_START (10)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer4_END (10)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer4_START (11)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer4_END (11)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer5_START (12)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer5_END (12)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer5_START (13)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer5_END (13)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer6_START (14)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer6_END (14)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer6_START (15)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer6_END (15)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer7_START (16)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer7_END (16)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer7_START (17)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer7_END (17)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer8_START (18)
#define SOC_SCTRL_SCPEREN1_gt_pclk_timer8_END (18)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer8_START (19)
#define SOC_SCTRL_SCPEREN1_gt_clk_timer8_END (19)
#define SOC_SCTRL_SCPEREN1_gt_timerclk_refh_START (20)
#define SOC_SCTRL_SCPEREN1_gt_timerclk_refh_END (20)
#define SOC_SCTRL_SCPEREN1_ddr_reset_en_START (21)
#define SOC_SCTRL_SCPEREN1_ddr_reset_en_END (21)
#define SOC_SCTRL_SCPEREN1_gt_clk_hifd_fll_START (22)
#define SOC_SCTRL_SCPEREN1_gt_clk_hifd_fll_END (22)
#define SOC_SCTRL_SCPEREN1_gt_clk_hifd_pll_START (23)
#define SOC_SCTRL_SCPEREN1_gt_clk_hifd_pll_END (23)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2aspbus_START (24)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2aspbus_END (24)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2iomcubus_START (25)
#define SOC_SCTRL_SCPEREN1_gt_clk_noc_aobus2iomcubus_END (25)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_codec_acpu_START (27)
#define SOC_SCTRL_SCPEREN1_gt_clk_asp_codec_acpu_END (27)
#define SOC_SCTRL_SCPEREN1_gt_clk_autodiv_aonoc_pll_START (28)
#define SOC_SCTRL_SCPEREN1_gt_clk_autodiv_aonoc_pll_END (28)
#define SOC_SCTRL_SCPEREN1_gt_clk_autodiv_aonoc_fll_START (29)
#define SOC_SCTRL_SCPEREN1_gt_clk_autodiv_aonoc_fll_END (29)
#define SOC_SCTRL_SCPEREN1_gt_clk_hsdt_fdul_noc_START (30)
#define SOC_SCTRL_SCPEREN1_gt_clk_hsdt_fdul_noc_END (30)
#define SOC_SCTRL_SCPEREN1_wait_ddr_selfreflash_done_bypass_START (31)
#define SOC_SCTRL_SCPEREN1_wait_ddr_selfreflash_done_bypass_END (31)
#endif
