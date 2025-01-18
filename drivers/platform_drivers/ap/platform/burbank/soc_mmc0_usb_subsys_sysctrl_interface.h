#ifndef __SOC_MMC0_USB_SUBSYS_SYSCTRL_INTERFACE_H__
#define __SOC_MMC0_USB_SUBSYS_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_rst_n_ADDR(base) ((base) + (0x0000UL))
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_refresh_ADDR(base) ((base) + (0x0004UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_ADDR(base) ((base) + (0x0008UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_ADDR(base) ((base) + (0x000CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_ADDR(base) ((base) + (0x0010UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_h_ADDR(base) ((base) + (0x0014UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_ADDR(base) ((base) + (0x0018UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_ADDR(base) ((base) + (0x001CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_ADDR(base) ((base) + (0x0020UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_ADDR(base) ((base) + (0x0024UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_ADDR(base) ((base) + (0x0028UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txready_ADDR(base) ((base) + (0x002CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_ADDR(base) ((base) + (0x0030UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_ADDR(base) ((base) + (0x0034UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_ADDR(base) ((base) + (0x0038UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_ADDR(base) ((base) + (0x003CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_ADDR(base) ((base) + (0x0040UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_ADDR(base) ((base) + (0x0044UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_ADDR(base) ((base) + (0x0048UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_ADDR(base) ((base) + (0x004CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_ADDR(base) ((base) + (0x0050UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxerror_ADDR(base) ((base) + (0x0054UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_ADDR(base) ((base) + (0x0058UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxactive_ADDR(base) ((base) + (0x005CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_ADDR(base) ((base) + (0x0060UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_linerate_ADDR(base) ((base) + (0x0064UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_ADDR(base) ((base) + (0x0068UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_ADDR(base) ((base) + (0x006CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_ADDR(base) ((base) + (0x0070UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vcvrselect_ADDR(base) ((base) + (0x0074UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_ADDR(base) ((base) + (0x0078UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_termselect_ADDR(base) ((base) + (0x007CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_ADDR(base) ((base) + (0x0080UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_opmode_ADDR(base) ((base) + (0x0084UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_ADDR(base) ((base) + (0x0088UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_ADDR(base) ((base) + (0x008CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_ADDR(base) ((base) + (0x0090UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_ADDR(base) ((base) + (0x0094UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_ADDR(base) ((base) + (0x0098UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_suspend_n_ADDR(base) ((base) + (0x009CUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_ADDR(base) ((base) + (0x00A0UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_sleep_n_ADDR(base) ((base) + (0x00A4UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_ADDR(base) ((base) + (0x00A8UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_ADDR(base) ((base) + (0x00ACUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_ADDR(base) ((base) + (0x00B0UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dppulldown_ADDR(base) ((base) + (0x00B4UL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_ADDR(base) ((base) + (0x00B8UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_ADDR(base) ((base) + (0x00BCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_serialmode_ADDR(base) ((base) + (0x00C0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txdata_ADDR(base) ((base) + (0x00C4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txenablen_ADDR(base) ((base) + (0x00C8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txse0_ADDR(base) ((base) + (0x00CCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fslsrxv_ADDR(base) ((base) + (0x00D0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvminus_ADDR(base) ((base) + (0x00D4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvplus_ADDR(base) ((base) + (0x00D8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_databus_ADDR(base) ((base) + (0x00DCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bist_ovrd_en_ADDR(base) ((base) + (0x00E0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_common_resv_ADDR(base) ((base) + (0x00E4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_port_resv_ADDR(base) ((base) + (0x00E8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_atp_sel_ADDR(base) ((base) + (0x00ECUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dmpulldown_ADDR(base) ((base) + (0x00F0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dppulldown_ADDR(base) ((base) + (0x00F4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_ovrd_en_ADDR(base) ((base) + (0x00F8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_en_ADDR(base) ((base) + (0x00FCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_tune_ADDR(base) ((base) + (0x0100UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_soft_en_ADDR(base) ((base) + (0x0104UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tst_ADDR(base) ((base) + (0x0108UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tx_vref_tune_ADDR(base) ((base) + (0x010CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_controller_en_ADDR(base) ((base) + (0x0110UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_databus_ADDR(base) ((base) + (0x0114UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_en_ADDR(base) ((base) + (0x0118UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_finish_ADDR(base) ((base) + (0x011CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_loopbackenb_ADDR(base) ((base) + (0x0120UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_mode_ADDR(base) ((base) + (0x0124UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_repeat_ADDR(base) ((base) + (0x0128UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_result_ADDR(base) ((base) + (0x012CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_speed_ADDR(base) ((base) + (0x0130UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_testburnin_ADDR(base) ((base) + (0x0134UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_ADDR(base) ((base) + (0x0138UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cktst_sel_ADDR(base) ((base) + (0x013CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_cp_ADDR(base) ((base) + (0x0140UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_en_lckdet_ADDR(base) ((base) + (0x0144UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fastlock_sel_ADDR(base) ((base) + (0x0148UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fb_div_sel_ADDR(base) ((base) + (0x014CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_force_lock_ADDR(base) ((base) + (0x0150UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_en_ADDR(base) ((base) + (0x0154UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_sel_ADDR(base) ((base) + (0x0158UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rt_code_fb_sel_ADDR(base) ((base) + (0x015CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_dcd_vref_sel_ADDR(base) ((base) + (0x0160UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_buf_sel_ADDR(base) ((base) + (0x0164UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_clk180_en_ADDR(base) ((base) + (0x0168UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_en_ADDR(base) ((base) + (0x016CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_path_en_ADDR(base) ((base) + (0x0170UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_ADDR(base) ((base) + (0x0174UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_selfbias_en_ADDR(base) ((base) + (0x0178UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_en_ADDR(base) ((base) + (0x017CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_filter_en_ADDR(base) ((base) + (0x0180UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_il_sel_ADDR(base) ((base) + (0x0184UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_in_sel_ADDR(base) ((base) + (0x0188UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_src_vref_sel_ADDR(base) ((base) + (0x018CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_en_ADDR(base) ((base) + (0x0190UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_sel_ADDR(base) ((base) + (0x0194UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_vbus_vref_ADDR(base) ((base) + (0x0198UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_code_sel_ADDR(base) ((base) + (0x019CUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_de_en_ADDR(base) ((base) + (0x01A0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_vco_st_mcu_en_ADDR(base) ((base) + (0x01A8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvminus_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvplus_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusdeten_ADDR(base) ((base) + (0x01B4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdeten_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdetsrcen_ADDR(base) ((base) + (0x01BCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrdet_ADDR(base) ((base) + (0x01C0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrgsel_ADDR(base) ((base) + (0x01C4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_dcden_ADDR(base) ((base) + (0x01C8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdpdata_ADDR(base) ((base) + (0x01CCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdmdata_ADDR(base) ((base) + (0x01D0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassen_ADDR(base) ((base) + (0x01D4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypasssel_ADDR(base) ((base) + (0x01D8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsrxdat_ADDR(base) ((base) + (0x01DCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hssquelch_ADDR(base) ((base) + (0x01E0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsxcvrextctl_ADDR(base) ((base) + (0x01E4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_commononn_ADDR(base) ((base) + (0x01E8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusvldext_ADDR(base) ((base) + (0x01ECUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_fsel_ADDR(base) ((base) + (0x01F0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_pll_lock_ADDR(base) ((base) + (0x01F4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_ref_clk_req_ADDR(base) ((base) + (0x01F8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_test_iddq_ADDR(base) ((base) + (0x01FCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_usb_test_bus_ADDR(base) ((base) + (0x0200UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ldo_tst_en_ADDR(base) ((base) + (0x0204UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_test_vref_sel_ADDR(base) ((base) + (0x0208UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_disc_il_sel_ADDR(base) ((base) + (0x020CUL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_test_ADDR(base) ((base) + (0x0210UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_ldo_vref_tune_ADDR(base) ((base) + (0x0214UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_bg_detec_en_ADDR(base) ((base) + (0x0218UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_ADDR(base) ((base) + (0x021CUL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_de_ibsel_ADDR(base) ((base) + (0x0220UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_main_ibsel_ADDR(base) ((base) + (0x0224UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_ADDR(base) ((base) + (0x0228UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_ADDR(base) ((base) + (0x022CUL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_sr_selslow_ADDR(base) ((base) + (0x0230UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby4_ADDR(base) ((base) + (0x0234UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby2_ADDR(base) ((base) + (0x0238UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_test_ADDR(base) ((base) + (0x023CUL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_pll_fastlock_pd_ADDR(base) ((base) + (0x0240UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vco_st_pd_ADDR(base) ((base) + (0x0244UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_isel_ADDR(base) ((base) + (0x0248UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_vsel_ADDR(base) ((base) + (0x024CUL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_trim_ADDR(base) ((base) + (0x0250UL))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_rx_sq_bias_sel_ADDR(base) ((base) + (0x0254UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bigendian_gs_ADDR(base) ((base) + (0x0258UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_en_ADDR(base) ((base) + (0x025CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_31_0_ADDR(base) ((base) + (0x0260UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_63_32_ADDR(base) ((base) + (0x0264UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_66_64_ADDR(base) ((base) + (0x0268UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_31_0_ADDR(base) ((base) + (0x026CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_63_32_ADDR(base) ((base) + (0x0270UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_current_belt_ADDR(base) ((base) + (0x0274UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_generation_ADDR(base) ((base) + (0x0278UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_operational_mode_ADDR(base) ((base) + (0x027CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_interrupt_ADDR(base) ((base) + (0x0280UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_host_system_err_ADDR(base) ((base) + (0x0284UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_n_ADDR(base) ((base) + (0x0288UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_com_n_ADDR(base) ((base) + (0x028CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_suspend_com_n_ADDR(base) ((base) + (0x0290UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_word_if_ADDR(base) ((base) + (0x0294UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fsls_low_power_ADDR(base) ((base) + (0x0298UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fslsserialmode_ADDR(base) ((base) + (0x029CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_overcurrent_ADDR(base) ((base) + (0x02A0UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_perm_attach_ADDR(base) ((base) + (0x02A4UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_num_u2_port_ADDR(base) ((base) + (0x02A8UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_u2_port_disable_ADDR(base) ((base) + (0x02ACUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_port_power_control_present_ADDR(base) ((base) + (0x02B0UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_msi_enable_ADDR(base) ((base) + (0x02B4UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_ADDR(base) ((base) + (0x02B8UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_bar_wr_ADDR(base) ((base) + (0x02BCUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_interrupt_ADDR(base) ((base) + (0x02C0UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_fladj_30mhz_reg_ADDR(base) ((base) + (0x02C4UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_xhc_bme_ADDR(base) ((base) + (0x02C8UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bus_filter_bypass_ADDR(base) ((base) + (0x02CCUL))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_ADDR(base) ((base) + (0x02D0UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_ADDR(base) ((base) + (0x02D4UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_ADDR(base) ((base) + (0x02D8UL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_ADDR(base) ((base) + (0x02DCUL))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_ADDR(base) ((base) + (0x02E0UL))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_sel_ADDR(base) ((base) + (0x02E4UL))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_ADDR(base) ((base) + (0x02E8UL))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_ulpi_rst_ADDR(base) ((base) + (0x02ECUL))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_ADDR(base) ((base) + (0x02F0UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_ADDR(base) ((base) + (0x02F4UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_eop_timer_update_ADDR(base) ((base) + (0x02F8UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_ADDR(base) ((base) + (0x02FCUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_ADDR(base) ((base) + (0x0300UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_ADDR(base) ((base) + (0x0304UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_ADDR(base) ((base) + (0x0308UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_valid_update_ADDR(base) ((base) + (0x030CUL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_ADDR(base) ((base) + (0x0310UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_ADDR(base) ((base) + (0x0314UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_ADDR(base) ((base) + (0x0318UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_ADDR(base) ((base) + (0x031CUL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_ADDR(base) ((base) + (0x0320UL))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_ADDR(base) ((base) + (0x0324UL))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_utmisrp_bvalid_ADDR(base) ((base) + (0x0328UL))
#define SOC_MMC0_usb_subsys_sysctrl_pad_mode_ulpi_sel_ADDR(base) ((base) + (0x032CUL))
#define SOC_MMC0_usb_subsys_sysctrl_usb_ulpi_sel_indicator_ADDR(base) ((base) + (0x0330UL))
#define SOC_MMC0_usb_subsys_sysctrl_usb20phy_refclk_sel_gpio_status_ADDR(base) ((base) + (0x0334UL))
#else
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_rst_n_ADDR(base) ((base) + (0x0000))
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_refresh_ADDR(base) ((base) + (0x0004))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_ADDR(base) ((base) + (0x0008))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_ADDR(base) ((base) + (0x000C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_ADDR(base) ((base) + (0x0010))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_h_ADDR(base) ((base) + (0x0014))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_ADDR(base) ((base) + (0x0018))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_ADDR(base) ((base) + (0x001C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_ADDR(base) ((base) + (0x0020))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_ADDR(base) ((base) + (0x0024))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_ADDR(base) ((base) + (0x0028))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txready_ADDR(base) ((base) + (0x002C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_ADDR(base) ((base) + (0x0030))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_ADDR(base) ((base) + (0x0034))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_ADDR(base) ((base) + (0x0038))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_ADDR(base) ((base) + (0x003C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_ADDR(base) ((base) + (0x0040))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_ADDR(base) ((base) + (0x0044))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_ADDR(base) ((base) + (0x0048))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_ADDR(base) ((base) + (0x004C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_ADDR(base) ((base) + (0x0050))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxerror_ADDR(base) ((base) + (0x0054))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_ADDR(base) ((base) + (0x0058))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxactive_ADDR(base) ((base) + (0x005C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_ADDR(base) ((base) + (0x0060))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_linerate_ADDR(base) ((base) + (0x0064))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_ADDR(base) ((base) + (0x0068))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_ADDR(base) ((base) + (0x006C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_ADDR(base) ((base) + (0x0070))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vcvrselect_ADDR(base) ((base) + (0x0074))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_ADDR(base) ((base) + (0x0078))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_termselect_ADDR(base) ((base) + (0x007C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_ADDR(base) ((base) + (0x0080))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_opmode_ADDR(base) ((base) + (0x0084))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_ADDR(base) ((base) + (0x0088))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_ADDR(base) ((base) + (0x008C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_ADDR(base) ((base) + (0x0090))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_ADDR(base) ((base) + (0x0094))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_ADDR(base) ((base) + (0x0098))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_suspend_n_ADDR(base) ((base) + (0x009C))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_ADDR(base) ((base) + (0x00A0))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_sleep_n_ADDR(base) ((base) + (0x00A4))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_ADDR(base) ((base) + (0x00A8))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_ADDR(base) ((base) + (0x00AC))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_ADDR(base) ((base) + (0x00B0))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dppulldown_ADDR(base) ((base) + (0x00B4))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_ADDR(base) ((base) + (0x00B8))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_ADDR(base) ((base) + (0x00BC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_serialmode_ADDR(base) ((base) + (0x00C0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txdata_ADDR(base) ((base) + (0x00C4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txenablen_ADDR(base) ((base) + (0x00C8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txse0_ADDR(base) ((base) + (0x00CC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fslsrxv_ADDR(base) ((base) + (0x00D0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvminus_ADDR(base) ((base) + (0x00D4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvplus_ADDR(base) ((base) + (0x00D8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_databus_ADDR(base) ((base) + (0x00DC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bist_ovrd_en_ADDR(base) ((base) + (0x00E0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_common_resv_ADDR(base) ((base) + (0x00E4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_port_resv_ADDR(base) ((base) + (0x00E8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_atp_sel_ADDR(base) ((base) + (0x00EC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dmpulldown_ADDR(base) ((base) + (0x00F0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dppulldown_ADDR(base) ((base) + (0x00F4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_ovrd_en_ADDR(base) ((base) + (0x00F8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_en_ADDR(base) ((base) + (0x00FC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_tune_ADDR(base) ((base) + (0x0100))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_soft_en_ADDR(base) ((base) + (0x0104))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tst_ADDR(base) ((base) + (0x0108))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tx_vref_tune_ADDR(base) ((base) + (0x010C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_controller_en_ADDR(base) ((base) + (0x0110))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_databus_ADDR(base) ((base) + (0x0114))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_en_ADDR(base) ((base) + (0x0118))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_finish_ADDR(base) ((base) + (0x011C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_loopbackenb_ADDR(base) ((base) + (0x0120))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_mode_ADDR(base) ((base) + (0x0124))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_repeat_ADDR(base) ((base) + (0x0128))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_result_ADDR(base) ((base) + (0x012C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_speed_ADDR(base) ((base) + (0x0130))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_testburnin_ADDR(base) ((base) + (0x0134))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_ADDR(base) ((base) + (0x0138))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cktst_sel_ADDR(base) ((base) + (0x013C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_cp_ADDR(base) ((base) + (0x0140))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_en_lckdet_ADDR(base) ((base) + (0x0144))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fastlock_sel_ADDR(base) ((base) + (0x0148))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fb_div_sel_ADDR(base) ((base) + (0x014C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_force_lock_ADDR(base) ((base) + (0x0150))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_en_ADDR(base) ((base) + (0x0154))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_sel_ADDR(base) ((base) + (0x0158))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rt_code_fb_sel_ADDR(base) ((base) + (0x015C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_dcd_vref_sel_ADDR(base) ((base) + (0x0160))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_buf_sel_ADDR(base) ((base) + (0x0164))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_clk180_en_ADDR(base) ((base) + (0x0168))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_en_ADDR(base) ((base) + (0x016C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_path_en_ADDR(base) ((base) + (0x0170))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_ADDR(base) ((base) + (0x0174))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_selfbias_en_ADDR(base) ((base) + (0x0178))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_en_ADDR(base) ((base) + (0x017C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_filter_en_ADDR(base) ((base) + (0x0180))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_il_sel_ADDR(base) ((base) + (0x0184))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_in_sel_ADDR(base) ((base) + (0x0188))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_src_vref_sel_ADDR(base) ((base) + (0x018C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_en_ADDR(base) ((base) + (0x0190))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_sel_ADDR(base) ((base) + (0x0194))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_vbus_vref_ADDR(base) ((base) + (0x0198))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_code_sel_ADDR(base) ((base) + (0x019C))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_de_en_ADDR(base) ((base) + (0x01A0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_ADDR(base) ((base) + (0x01A4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_vco_st_mcu_en_ADDR(base) ((base) + (0x01A8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvminus_ADDR(base) ((base) + (0x01AC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvplus_ADDR(base) ((base) + (0x01B0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusdeten_ADDR(base) ((base) + (0x01B4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdeten_ADDR(base) ((base) + (0x01B8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdetsrcen_ADDR(base) ((base) + (0x01BC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrdet_ADDR(base) ((base) + (0x01C0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrgsel_ADDR(base) ((base) + (0x01C4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_dcden_ADDR(base) ((base) + (0x01C8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdpdata_ADDR(base) ((base) + (0x01CC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdmdata_ADDR(base) ((base) + (0x01D0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassen_ADDR(base) ((base) + (0x01D4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypasssel_ADDR(base) ((base) + (0x01D8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsrxdat_ADDR(base) ((base) + (0x01DC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hssquelch_ADDR(base) ((base) + (0x01E0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsxcvrextctl_ADDR(base) ((base) + (0x01E4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_commononn_ADDR(base) ((base) + (0x01E8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusvldext_ADDR(base) ((base) + (0x01EC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_fsel_ADDR(base) ((base) + (0x01F0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_pll_lock_ADDR(base) ((base) + (0x01F4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_ref_clk_req_ADDR(base) ((base) + (0x01F8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_test_iddq_ADDR(base) ((base) + (0x01FC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_usb_test_bus_ADDR(base) ((base) + (0x0200))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ldo_tst_en_ADDR(base) ((base) + (0x0204))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_test_vref_sel_ADDR(base) ((base) + (0x0208))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_disc_il_sel_ADDR(base) ((base) + (0x020C))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_test_ADDR(base) ((base) + (0x0210))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_ldo_vref_tune_ADDR(base) ((base) + (0x0214))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_bg_detec_en_ADDR(base) ((base) + (0x0218))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_ADDR(base) ((base) + (0x021C))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_de_ibsel_ADDR(base) ((base) + (0x0220))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_main_ibsel_ADDR(base) ((base) + (0x0224))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_ADDR(base) ((base) + (0x0228))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_ADDR(base) ((base) + (0x022C))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_sr_selslow_ADDR(base) ((base) + (0x0230))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby4_ADDR(base) ((base) + (0x0234))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby2_ADDR(base) ((base) + (0x0238))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_test_ADDR(base) ((base) + (0x023C))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_pll_fastlock_pd_ADDR(base) ((base) + (0x0240))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vco_st_pd_ADDR(base) ((base) + (0x0244))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_isel_ADDR(base) ((base) + (0x0248))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_vsel_ADDR(base) ((base) + (0x024C))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_trim_ADDR(base) ((base) + (0x0250))
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_rx_sq_bias_sel_ADDR(base) ((base) + (0x0254))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bigendian_gs_ADDR(base) ((base) + (0x0258))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_en_ADDR(base) ((base) + (0x025C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_31_0_ADDR(base) ((base) + (0x0260))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_63_32_ADDR(base) ((base) + (0x0264))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_66_64_ADDR(base) ((base) + (0x0268))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_31_0_ADDR(base) ((base) + (0x026C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_63_32_ADDR(base) ((base) + (0x0270))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_current_belt_ADDR(base) ((base) + (0x0274))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_generation_ADDR(base) ((base) + (0x0278))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_operational_mode_ADDR(base) ((base) + (0x027C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_interrupt_ADDR(base) ((base) + (0x0280))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_host_system_err_ADDR(base) ((base) + (0x0284))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_n_ADDR(base) ((base) + (0x0288))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_com_n_ADDR(base) ((base) + (0x028C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_suspend_com_n_ADDR(base) ((base) + (0x0290))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_word_if_ADDR(base) ((base) + (0x0294))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fsls_low_power_ADDR(base) ((base) + (0x0298))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fslsserialmode_ADDR(base) ((base) + (0x029C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_overcurrent_ADDR(base) ((base) + (0x02A0))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_perm_attach_ADDR(base) ((base) + (0x02A4))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_num_u2_port_ADDR(base) ((base) + (0x02A8))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_u2_port_disable_ADDR(base) ((base) + (0x02AC))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_port_power_control_present_ADDR(base) ((base) + (0x02B0))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_msi_enable_ADDR(base) ((base) + (0x02B4))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_ADDR(base) ((base) + (0x02B8))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_bar_wr_ADDR(base) ((base) + (0x02BC))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_interrupt_ADDR(base) ((base) + (0x02C0))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_fladj_30mhz_reg_ADDR(base) ((base) + (0x02C4))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_xhc_bme_ADDR(base) ((base) + (0x02C8))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bus_filter_bypass_ADDR(base) ((base) + (0x02CC))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_ADDR(base) ((base) + (0x02D0))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_ADDR(base) ((base) + (0x02D4))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_ADDR(base) ((base) + (0x02D8))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_ADDR(base) ((base) + (0x02DC))
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_ADDR(base) ((base) + (0x02E0))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_sel_ADDR(base) ((base) + (0x02E4))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_ADDR(base) ((base) + (0x02E8))
#define SOC_MMC0_usb_subsys_sysctrl_usb20_ulpi_rst_ADDR(base) ((base) + (0x02EC))
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_ADDR(base) ((base) + (0x02F0))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_ADDR(base) ((base) + (0x02F4))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_eop_timer_update_ADDR(base) ((base) + (0x02F8))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_ADDR(base) ((base) + (0x02FC))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_ADDR(base) ((base) + (0x0300))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_ADDR(base) ((base) + (0x0304))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_ADDR(base) ((base) + (0x0308))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_valid_update_ADDR(base) ((base) + (0x030C))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_ADDR(base) ((base) + (0x0310))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_ADDR(base) ((base) + (0x0314))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_ADDR(base) ((base) + (0x0318))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_ADDR(base) ((base) + (0x031C))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_ADDR(base) ((base) + (0x0320))
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_ADDR(base) ((base) + (0x0324))
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_utmisrp_bvalid_ADDR(base) ((base) + (0x0328))
#define SOC_MMC0_usb_subsys_sysctrl_pad_mode_ulpi_sel_ADDR(base) ((base) + (0x032C))
#define SOC_MMC0_usb_subsys_sysctrl_usb_ulpi_sel_indicator_ADDR(base) ((base) + (0x0330))
#define SOC_MMC0_usb_subsys_sysctrl_usb20phy_refclk_sel_gpio_status_ADDR(base) ((base) + (0x0334))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_dbg_utmi_rst_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_rst_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_rst_n_SET_dbg_utmi_rst_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_rst_n_SET_dbg_utmi_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_dbg_utmi_refresh : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_refresh_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_refresh_SET_dbg_utmi_refresh_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_dbg_utmi_refresh_SET_dbg_utmi_refresh_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txdata : 8;
        unsigned int SEL_utmi_txdata : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_SET_utmi_txdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_SET_utmi_txdata_END (7)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_SEL_utmi_txdata_START (8)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_SEL_utmi_txdata_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txdata : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_STATUS_utmi_txdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_STATUS_utmi_txdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txdata_h : 8;
        unsigned int SEL_utmi_txdata_h : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_SET_utmi_txdata_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_SET_utmi_txdata_h_END (7)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_SEL_utmi_txdata_h_START (8)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txdata_h_SEL_utmi_txdata_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txdata_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_h_STATUS_utmi_txdata_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txdata_h_STATUS_utmi_txdata_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txvalid : 1;
        unsigned int SEL_utmi_txvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_SET_utmi_txvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_SET_utmi_txvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_SEL_utmi_txvalid_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_SEL_utmi_txvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_STATUS_utmi_txvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_STATUS_utmi_txvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txvalid_h : 1;
        unsigned int SEL_utmi_txvalid_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_SET_utmi_txvalid_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_SET_utmi_txvalid_h_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_SEL_utmi_txvalid_h_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txvalid_h_SEL_utmi_txvalid_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txvalid_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_STATUS_utmi_txvalid_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txvalid_h_STATUS_utmi_txvalid_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txready : 1;
        unsigned int SEL_utmi_txready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txready_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_SET_utmi_txready_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_SET_utmi_txready_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_SEL_utmi_txready_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txready_SEL_utmi_txready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txready_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txready_STATUS_utmi_txready_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txready_STATUS_utmi_txready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxdata : 8;
        unsigned int SEL_utmi_rxdata : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_SET_utmi_rxdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_SET_utmi_rxdata_END (7)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_SEL_utmi_rxdata_START (8)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_SEL_utmi_rxdata_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxdata : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_STATUS_utmi_rxdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_STATUS_utmi_rxdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxdata_h : 8;
        unsigned int SEL_utmi_rxdata_h : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_SET_utmi_rxdata_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_SET_utmi_rxdata_h_END (7)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_SEL_utmi_rxdata_h_START (8)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxdata_h_SEL_utmi_rxdata_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxdata_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_STATUS_utmi_rxdata_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxdata_h_STATUS_utmi_rxdata_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxvalid : 1;
        unsigned int SEL_utmi_rxvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_SET_utmi_rxvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_SET_utmi_rxvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_SEL_utmi_rxvalid_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_SEL_utmi_rxvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_STATUS_utmi_rxvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_STATUS_utmi_rxvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxvalid_h : 1;
        unsigned int SEL_utmi_rxvalid_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_SET_utmi_rxvalid_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_SET_utmi_rxvalid_h_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_SEL_utmi_rxvalid_h_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxvalid_h_SEL_utmi_rxvalid_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxvalid_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_STATUS_utmi_rxvalid_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxvalid_h_STATUS_utmi_rxvalid_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxerror : 1;
        unsigned int SEL_utmi_rxerror : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_SET_utmi_rxerror_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_SET_utmi_rxerror_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_SEL_utmi_rxerror_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxerror_SEL_utmi_rxerror_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxerror : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxerror_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxerror_STATUS_utmi_rxerror_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxerror_STATUS_utmi_rxerror_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_rxactive : 1;
        unsigned int SEL_utmi_rxactive : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_SET_utmi_rxactive_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_SET_utmi_rxactive_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_SEL_utmi_rxactive_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_rxactive_SEL_utmi_rxactive_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_rxactive : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxactive_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxactive_STATUS_utmi_rxactive_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_rxactive_STATUS_utmi_rxactive_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_linerate : 2;
        unsigned int SEL_utmi_linerate : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_SET_utmi_linerate_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_SET_utmi_linerate_END (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_SEL_utmi_linerate_START (2)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_linerate_SEL_utmi_linerate_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_linerate : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_linerate_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_linerate_STATUS_utmi_linerate_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_linerate_STATUS_utmi_linerate_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_hostdisconnect : 1;
        unsigned int SEL_utmi_hostdisconnect : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_SET_utmi_hostdisconnect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_SET_utmi_hostdisconnect_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_SEL_utmi_hostdisconnect_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_hostdisconnect_SEL_utmi_hostdisconnect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_hostdisconnect : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_STATUS_utmi_hostdisconnect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_hostdisconnect_STATUS_utmi_hostdisconnect_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_vcvrselect : 2;
        unsigned int SEL_utmi_vcvrselect : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_SET_utmi_vcvrselect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_SET_utmi_vcvrselect_END (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_SEL_utmi_vcvrselect_START (2)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vcvrselect_SEL_utmi_vcvrselect_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_vcvrselect : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vcvrselect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vcvrselect_STATUS_utmi_vcvrselect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vcvrselect_STATUS_utmi_vcvrselect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_termselect : 1;
        unsigned int SEL_utmi_termselect : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_SET_utmi_termselect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_SET_utmi_termselect_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_SEL_utmi_termselect_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_termselect_SEL_utmi_termselect_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_termselect : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_termselect_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_termselect_STATUS_utmi_termselect_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_termselect_STATUS_utmi_termselect_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_opmode : 2;
        unsigned int SEL_utmi_opmode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_SET_utmi_opmode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_SET_utmi_opmode_END (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_SEL_utmi_opmode_START (2)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_opmode_SEL_utmi_opmode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_opmode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_opmode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_opmode_STATUS_utmi_opmode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_opmode_STATUS_utmi_opmode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txbitstuffenable : 1;
        unsigned int SEL_utmi_txbitstuffenable : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_SET_utmi_txbitstuffenable_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_SET_utmi_txbitstuffenable_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_SEL_utmi_txbitstuffenable_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_SEL_utmi_txbitstuffenable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txbitstuffenable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_STATUS_utmi_txbitstuffenable_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_STATUS_utmi_txbitstuffenable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_txbitstuffenable_h : 1;
        unsigned int SEL_utmi_txbitstuffenable_h : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SET_utmi_txbitstuffenable_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SET_utmi_txbitstuffenable_h_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SEL_utmi_txbitstuffenable_h_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_txbitstuffenable_h_SEL_utmi_txbitstuffenable_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_txbitstuffenable_h : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_STATUS_utmi_txbitstuffenable_h_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_txbitstuffenable_h_STATUS_utmi_txbitstuffenable_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_suspend_n : 1;
        unsigned int SEL_utmi_suspend_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_SET_utmi_suspend_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_SET_utmi_suspend_n_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_SEL_utmi_suspend_n_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_suspend_n_SEL_utmi_suspend_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_suspend_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_suspend_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_suspend_n_STATUS_utmi_suspend_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_suspend_n_STATUS_utmi_suspend_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_sleep_n : 1;
        unsigned int SEL_utmi_sleep_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_SET_utmi_sleep_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_SET_utmi_sleep_n_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_SEL_utmi_sleep_n_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_sleep_n_SEL_utmi_sleep_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_sleep_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_sleep_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_sleep_n_STATUS_utmi_sleep_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_sleep_n_STATUS_utmi_sleep_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_dmpulldown : 1;
        unsigned int SEL_utmi_dmpulldown : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_SET_utmi_dmpulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_SET_utmi_dmpulldown_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_SEL_utmi_dmpulldown_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dmpulldown_SEL_utmi_dmpulldown_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_dmpulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_STATUS_utmi_dmpulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dmpulldown_STATUS_utmi_dmpulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_dppulldown : 1;
        unsigned int SEL_utmi_dppulldown : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_SET_utmi_dppulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_SET_utmi_dppulldown_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_SEL_utmi_dppulldown_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_dppulldown_SEL_utmi_dppulldown_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_dppulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dppulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dppulldown_STATUS_utmi_dppulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_dppulldown_STATUS_utmi_dppulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_vbusvalid : 1;
        unsigned int SEL_utmi_vbusvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_SET_utmi_vbusvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_SET_utmi_vbusvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_SEL_utmi_vbusvalid_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_vbusvalid_SEL_utmi_vbusvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_utmi_vbusvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_STATUS_utmi_vbusvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_utmi_vbusvalid_STATUS_utmi_vbusvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_utmi_fsls_serialmode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_serialmode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_serialmode_SET_his_usb20phy_dbg_utmi_fsls_serialmode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_serialmode_SET_his_usb20phy_dbg_utmi_fsls_serialmode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_utmi_fsls_txdata : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txdata_SET_his_usb20phy_dbg_utmi_fsls_txdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txdata_SET_his_usb20phy_dbg_utmi_fsls_txdata_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_utmi_fsls_txenablen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txenablen_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txenablen_SET_his_usb20phy_dbg_utmi_fsls_txenablen_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txenablen_SET_his_usb20phy_dbg_utmi_fsls_txenablen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_utmi_fsls_txse0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txse0_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txse0_SET_his_usb20phy_dbg_utmi_fsls_txse0_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsls_txse0_SET_his_usb20phy_dbg_utmi_fsls_txse0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_utmi_fslsrxv : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fslsrxv_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fslsrxv_STATUS_his_usb20phy_dbg_utmi_fslsrxv_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fslsrxv_STATUS_his_usb20phy_dbg_utmi_fslsrxv_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_utmi_fsvminus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvminus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvminus_STATUS_his_usb20phy_dbg_utmi_fsvminus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvminus_STATUS_his_usb20phy_dbg_utmi_fsvminus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_utmi_fsvplus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvplus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvplus_STATUS_his_usb20phy_dbg_utmi_fsvplus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_fsvplus_STATUS_his_usb20phy_dbg_utmi_fsvplus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_utmi_databus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_databus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_databus_SET_his_usb20phy_dbg_utmi_databus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_utmi_databus_SET_his_usb20phy_dbg_utmi_databus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_bist_ovrd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bist_ovrd_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bist_ovrd_en_SET_his_usb20phy_dbg_bist_ovrd_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bist_ovrd_en_SET_his_usb20phy_dbg_bist_ovrd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_ana_common_resv : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_common_resv_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_common_resv_SET_his_usb20phy_dbg_phy_ana_common_resv_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_common_resv_SET_his_usb20phy_dbg_phy_ana_common_resv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_ana_port_resv : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_port_resv_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_port_resv_SET_his_usb20phy_dbg_phy_ana_port_resv_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ana_port_resv_SET_his_usb20phy_dbg_phy_ana_port_resv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_atp_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_atp_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_atp_sel_SET_his_usb20phy_dbg_phy_atp_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_atp_sel_SET_his_usb20phy_dbg_phy_atp_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bc12_dmpulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dmpulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dmpulldown_SET_his_usb20phy_dbg_phy_bc12_dmpulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dmpulldown_SET_his_usb20phy_dbg_phy_bc12_dmpulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bc12_dppulldown : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dppulldown_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dppulldown_SET_his_usb20phy_dbg_phy_bc12_dppulldown_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_dppulldown_SET_his_usb20phy_dbg_phy_bc12_dppulldown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bc12_ovrd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_ovrd_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_ovrd_en_SET_his_usb20phy_dbg_phy_bc12_ovrd_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bc12_ovrd_en_SET_his_usb20phy_dbg_phy_bc12_ovrd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bg_mt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_en_SET_his_usb20phy_dbg_phy_bg_mt_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_en_SET_his_usb20phy_dbg_phy_bg_mt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bg_mt_tune : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_tune_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_tune_SET_his_usb20phy_dbg_phy_bg_mt_tune_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_mt_tune_SET_his_usb20phy_dbg_phy_bg_mt_tune_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bg_soft_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_soft_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_soft_en_SET_his_usb20phy_dbg_phy_bg_soft_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_soft_en_SET_his_usb20phy_dbg_phy_bg_soft_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bg_tst : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tst_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tst_SET_his_usb20phy_dbg_phy_bg_tst_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tst_SET_his_usb20phy_dbg_phy_bg_tst_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bg_tx_vref_tune : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tx_vref_tune_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tx_vref_tune_SET_his_usb20phy_dbg_phy_bg_tx_vref_tune_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bg_tx_vref_tune_SET_his_usb20phy_dbg_phy_bg_tx_vref_tune_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_controller_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_controller_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_controller_en_SET_his_usb20phy_dbg_phy_bist_controller_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_controller_en_SET_his_usb20phy_dbg_phy_bist_controller_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_databus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_databus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_databus_SET_his_usb20phy_dbg_phy_bist_databus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_databus_SET_his_usb20phy_dbg_phy_bist_databus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_en_SET_his_usb20phy_dbg_phy_bist_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_en_SET_his_usb20phy_dbg_phy_bist_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_phy_bist_finish : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_finish_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_finish_STATUS_his_usb20phy_dbg_phy_bist_finish_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_finish_STATUS_his_usb20phy_dbg_phy_bist_finish_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_loopbackenb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_loopbackenb_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_loopbackenb_SET_his_usb20phy_dbg_phy_bist_loopbackenb_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_loopbackenb_SET_his_usb20phy_dbg_phy_bist_loopbackenb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_mode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_mode_SET_his_usb20phy_dbg_phy_bist_mode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_mode_SET_his_usb20phy_dbg_phy_bist_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_repeat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_repeat_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_repeat_SET_his_usb20phy_dbg_phy_bist_repeat_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_repeat_SET_his_usb20phy_dbg_phy_bist_repeat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_phy_bist_result : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_result_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_result_STATUS_his_usb20phy_dbg_phy_bist_result_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_result_STATUS_his_usb20phy_dbg_phy_bist_result_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_speed : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_speed_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_speed_SET_his_usb20phy_dbg_phy_bist_speed_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_speed_SET_his_usb20phy_dbg_phy_bist_speed_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_bist_testburnin : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_testburnin_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_testburnin_SET_his_usb20phy_dbg_phy_bist_testburnin_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_bist_testburnin_SET_his_usb20phy_dbg_phy_bist_testburnin_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_cfg_ana_ovrd_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_SET_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_SET_his_usb20phy_dbg_phy_cfg_ana_ovrd_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_cktst_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cktst_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cktst_sel_SET_his_usb20phy_dbg_phy_cktst_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_cktst_sel_SET_his_usb20phy_dbg_phy_cktst_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_cp : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_cp_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_cp_SET_his_usb20phy_dbg_phy_pll_cp_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_cp_SET_his_usb20phy_dbg_phy_pll_cp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_en_lckdet : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_en_lckdet_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_en_lckdet_SET_his_usb20phy_dbg_phy_pll_en_lckdet_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_en_lckdet_SET_his_usb20phy_dbg_phy_pll_en_lckdet_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_fastlock_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fastlock_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fastlock_sel_SET_his_usb20phy_dbg_phy_pll_fastlock_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fastlock_sel_SET_his_usb20phy_dbg_phy_pll_fastlock_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_fb_div_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fb_div_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fb_div_sel_SET_his_usb20phy_dbg_phy_pll_fb_div_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_fb_div_sel_SET_his_usb20phy_dbg_phy_pll_fb_div_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_force_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_force_lock_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_force_lock_SET_his_usb20phy_dbg_phy_pll_force_lock_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_force_lock_SET_his_usb20phy_dbg_phy_pll_force_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_test_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_en_SET_his_usb20phy_dbg_phy_pll_test_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_en_SET_his_usb20phy_dbg_phy_pll_test_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_pll_test_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_sel_SET_his_usb20phy_dbg_phy_pll_test_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_pll_test_sel_SET_his_usb20phy_dbg_phy_pll_test_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rt_code_fb_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rt_code_fb_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rt_code_fb_sel_SET_his_usb20phy_dbg_phy_rt_code_fb_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rt_code_fb_sel_SET_his_usb20phy_dbg_phy_rt_code_fb_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_dcd_vref_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_dcd_vref_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_dcd_vref_sel_SET_his_usb20phy_dbg_phy_rx_dcd_vref_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_dcd_vref_sel_SET_his_usb20phy_dbg_phy_rx_dcd_vref_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_hs_buf_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_buf_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_buf_sel_SET_his_usb20phy_dbg_phy_rx_hs_buf_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_buf_sel_SET_his_usb20phy_dbg_phy_rx_hs_buf_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_hs_clk180_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_clk180_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_clk180_en_SET_his_usb20phy_dbg_phy_rx_hs_clk180_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_clk180_en_SET_his_usb20phy_dbg_phy_rx_hs_clk180_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_hs_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_en_SET_his_usb20phy_dbg_phy_rx_hs_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_en_SET_his_usb20phy_dbg_phy_rx_hs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_hs_path_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_path_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_path_en_SET_his_usb20phy_dbg_phy_rx_hs_path_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_path_en_SET_his_usb20phy_dbg_phy_rx_hs_path_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_SET_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_SET_his_usb20phy_dbg_phy_rx_hs_valid_delay_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_selfbias_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_selfbias_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_selfbias_en_SET_his_usb20phy_dbg_phy_rx_selfbias_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_selfbias_en_SET_his_usb20phy_dbg_phy_rx_selfbias_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_sq_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_en_SET_his_usb20phy_dbg_phy_rx_sq_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_en_SET_his_usb20phy_dbg_phy_rx_sq_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_sq_filter_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_filter_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_filter_en_SET_his_usb20phy_dbg_phy_rx_sq_filter_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_filter_en_SET_his_usb20phy_dbg_phy_rx_sq_filter_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_sq_il_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_il_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_il_sel_SET_his_usb20phy_dbg_phy_rx_sq_il_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_il_sel_SET_his_usb20phy_dbg_phy_rx_sq_il_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_sq_in_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_in_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_in_sel_SET_his_usb20phy_dbg_phy_rx_sq_in_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_sq_in_sel_SET_his_usb20phy_dbg_phy_rx_sq_in_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_src_vref_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_src_vref_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_src_vref_sel_SET_his_usb20phy_dbg_phy_rx_src_vref_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_src_vref_sel_SET_his_usb20phy_dbg_phy_rx_src_vref_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_tst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_en_SET_his_usb20phy_dbg_phy_rx_tst_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_en_SET_his_usb20phy_dbg_phy_rx_tst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_tst_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_sel_SET_his_usb20phy_dbg_phy_rx_tst_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_tst_sel_SET_his_usb20phy_dbg_phy_rx_tst_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_vbus_vref : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_vbus_vref_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_vbus_vref_SET_his_usb20phy_dbg_phy_rx_vbus_vref_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_vbus_vref_SET_his_usb20phy_dbg_phy_rx_vbus_vref_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_tx_code_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_code_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_code_sel_SET_his_usb20phy_dbg_phy_tx_code_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_code_sel_SET_his_usb20phy_dbg_phy_tx_code_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_tx_hs_de_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_de_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_de_en_SET_his_usb20phy_dbg_phy_tx_hs_de_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_de_en_SET_his_usb20phy_dbg_phy_tx_hs_de_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_SET_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_SET_his_usb20phy_dbg_phy_tx_hs_drvcap_de_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_vco_st_mcu_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_vco_st_mcu_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_vco_st_mcu_en_SET_his_usb20phy_dbg_phy_vco_st_mcu_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_vco_st_mcu_en_SET_his_usb20phy_dbg_phy_vco_st_mcu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_bc12_fsvminus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvminus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvminus_STATUS_his_usb20phy_dbg_bc12_fsvminus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvminus_STATUS_his_usb20phy_dbg_bc12_fsvminus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_bc12_fsvplus : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvplus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvplus_STATUS_his_usb20phy_dbg_bc12_fsvplus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bc12_fsvplus_STATUS_his_usb20phy_dbg_bc12_fsvplus_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_vbusdeten : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusdeten_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusdeten_SET_his_usb20phy_dbg_vbusdeten_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusdeten_SET_his_usb20phy_dbg_vbusdeten_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_vdatdeten : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdeten_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdeten_SET_his_usb20phy_dbg_vdatdeten_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdeten_SET_his_usb20phy_dbg_vdatdeten_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_vdatdetsrcen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdetsrcen_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdetsrcen_SET_his_usb20phy_dbg_vdatdetsrcen_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vdatdetsrcen_SET_his_usb20phy_dbg_vdatdetsrcen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_chrdet : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrdet_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrdet_STATUS_his_usb20phy_dbg_chrdet_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrdet_STATUS_his_usb20phy_dbg_chrdet_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_chrgsel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrgsel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrgsel_SET_his_usb20phy_dbg_chrgsel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_chrgsel_SET_his_usb20phy_dbg_chrgsel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_dcden : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_dcden_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_dcden_SET_his_usb20phy_dbg_dcden_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_dcden_SET_his_usb20phy_dbg_dcden_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_bypassdpdata : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdpdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdpdata_SET_his_usb20phy_dbg_bypassdpdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdpdata_SET_his_usb20phy_dbg_bypassdpdata_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_bypassdmdata : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdmdata_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdmdata_SET_his_usb20phy_dbg_bypassdmdata_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassdmdata_SET_his_usb20phy_dbg_bypassdmdata_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_bypassen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassen_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassen_SET_his_usb20phy_dbg_bypassen_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypassen_SET_his_usb20phy_dbg_bypassen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_bypasssel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypasssel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypasssel_SET_his_usb20phy_dbg_bypasssel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_bypasssel_SET_his_usb20phy_dbg_bypasssel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_hsrxdat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsrxdat_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsrxdat_STATUS_his_usb20phy_dbg_hsrxdat_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsrxdat_STATUS_his_usb20phy_dbg_hsrxdat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_hssquelch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hssquelch_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hssquelch_STATUS_his_usb20phy_dbg_hssquelch_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hssquelch_STATUS_his_usb20phy_dbg_hssquelch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_hsxcvrextctl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsxcvrextctl_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsxcvrextctl_SET_his_usb20phy_dbg_hsxcvrextctl_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_hsxcvrextctl_SET_his_usb20phy_dbg_hsxcvrextctl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_commononn : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_commononn_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_commononn_SET_his_usb20phy_dbg_commononn_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_commononn_SET_his_usb20phy_dbg_commononn_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_vbusvldext : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusvldext_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusvldext_SET_his_usb20phy_dbg_vbusvldext_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_vbusvldext_SET_his_usb20phy_dbg_vbusvldext_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_fsel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_fsel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_fsel_SET_his_usb20phy_dbg_fsel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_fsel_SET_his_usb20phy_dbg_fsel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_pll_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_pll_lock_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_pll_lock_STATUS_his_usb20phy_dbg_pll_lock_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_pll_lock_STATUS_his_usb20phy_dbg_pll_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_ref_clk_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_ref_clk_req_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_ref_clk_req_STATUS_his_usb20phy_dbg_ref_clk_req_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_ref_clk_req_STATUS_his_usb20phy_dbg_ref_clk_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_test_iddq : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_test_iddq_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_test_iddq_SET_his_usb20phy_dbg_test_iddq_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_test_iddq_SET_his_usb20phy_dbg_test_iddq_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_dbg_usb_test_bus : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_usb_test_bus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_usb_test_bus_STATUS_his_usb20phy_dbg_usb_test_bus_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_usb_test_bus_STATUS_his_usb20phy_dbg_usb_test_bus_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_ldo_tst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ldo_tst_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ldo_tst_en_SET_his_usb20phy_dbg_phy_ldo_tst_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_ldo_tst_en_SET_his_usb20phy_dbg_phy_ldo_tst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_test_vref_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_test_vref_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_test_vref_sel_SET_his_usb20phy_dbg_phy_rx_test_vref_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_test_vref_sel_SET_his_usb20phy_dbg_phy_rx_test_vref_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_dbg_phy_rx_disc_il_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_disc_il_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_disc_il_sel_SET_his_usb20phy_dbg_phy_rx_disc_il_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_dbg_phy_rx_disc_il_sel_SET_his_usb20phy_dbg_phy_rx_disc_il_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_topldo_test : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_test_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_test_SET_his_usb20phy_phy_topldo_test_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_test_SET_his_usb20phy_phy_topldo_test_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_ldo_vref_tune : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_ldo_vref_tune_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_ldo_vref_tune_SET_his_usb20phy_phy_ldo_vref_tune_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_ldo_vref_tune_SET_his_usb20phy_phy_ldo_vref_tune_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_bg_detec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_bg_detec_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_bg_detec_en_SET_his_usb20phy_phy_bg_detec_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_bg_detec_en_SET_his_usb20phy_phy_bg_detec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_hs_drvcap_de_selh : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_SET_his_usb20phy_phy_tx_hs_drvcap_de_selh_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_hs_de_ibsel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_de_ibsel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_de_ibsel_SET_his_usb20phy_phy_tx_hs_de_ibsel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_de_ibsel_SET_his_usb20phy_phy_tx_hs_de_ibsel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_hs_main_ibsel : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_main_ibsel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_main_ibsel_SET_his_usb20phy_phy_tx_hs_main_ibsel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_main_ibsel_SET_his_usb20phy_phy_tx_hs_main_ibsel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_hs_drvcap_main_selh : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_SET_his_usb20phy_phy_tx_hs_drvcap_main_selh_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_hs_drvcap_main_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_SET_his_usb20phy_phy_tx_hs_drvcap_main_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_fls_sr_selslow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_sr_selslow_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_sr_selslow_SET_his_usb20phy_phy_tx_fls_sr_selslow_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_sr_selslow_SET_his_usb20phy_phy_tx_fls_sr_selslow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_fls_clkdivby4 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby4_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby4_SET_his_usb20phy_phy_tx_fls_clkdivby4_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby4_SET_his_usb20phy_phy_tx_fls_clkdivby4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_fls_clkdivby2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby2_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby2_SET_his_usb20phy_phy_tx_fls_clkdivby2_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_fls_clkdivby2_SET_his_usb20phy_phy_tx_fls_clkdivby2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_tx_test : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_test_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_test_SET_his_usb20phy_phy_tx_test_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_tx_test_SET_his_usb20phy_phy_tx_test_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_pll_fastlock_pd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_pll_fastlock_pd_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_pll_fastlock_pd_SET_his_usb20phy_phy_pll_fastlock_pd_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_pll_fastlock_pd_SET_his_usb20phy_phy_pll_fastlock_pd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_vco_st_pd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vco_st_pd_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vco_st_pd_SET_his_usb20phy_phy_vco_st_pd_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vco_st_pd_SET_his_usb20phy_phy_vco_st_pd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_vpbias_isel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_isel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_isel_SET_his_usb20phy_phy_vpbias_isel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_isel_SET_his_usb20phy_phy_vpbias_isel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_vpbias_vsel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_vsel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_vsel_SET_his_usb20phy_phy_vpbias_vsel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_vpbias_vsel_SET_his_usb20phy_phy_vpbias_vsel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_topldo_trim : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_trim_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_trim_SET_his_usb20phy_phy_topldo_trim_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_topldo_trim_SET_his_usb20phy_phy_topldo_trim_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_phy_rx_sq_bias_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_rx_sq_bias_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_rx_sq_bias_sel_SET_his_usb20phy_phy_rx_sq_bias_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_SET_his_usb20phy_phy_rx_sq_bias_sel_SET_his_usb20phy_phy_rx_sq_bias_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_bigendian_gs : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bigendian_gs_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bigendian_gs_SET_snp_usb20_dbg_bigendian_gs_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bigendian_gs_SET_snp_usb20_dbg_bigendian_gs_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_pme_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_en_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_en_SET_snp_usb20_dbg_pme_en_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_en_SET_snp_usb20_dbg_pme_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_debug_31_0 : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_31_0_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_31_0_STATUS_snp_usb20_dbg_debug_31_0_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_31_0_STATUS_snp_usb20_dbg_debug_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_debug_63_32 : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_63_32_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_63_32_STATUS_snp_usb20_dbg_debug_63_32_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_63_32_STATUS_snp_usb20_dbg_debug_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_debug_66_64 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_66_64_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_66_64_STATUS_snp_usb20_dbg_debug_66_64_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_debug_66_64_STATUS_snp_usb20_dbg_debug_66_64_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_logic_analyzer_trace_31_0 : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_31_0_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_31_0_STATUS_snp_usb20_dbg_logic_analyzer_trace_31_0_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_31_0_STATUS_snp_usb20_dbg_logic_analyzer_trace_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_logic_analyzer_trace_63_32 : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_63_32_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_63_32_STATUS_snp_usb20_dbg_logic_analyzer_trace_63_32_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_logic_analyzer_trace_63_32_STATUS_snp_usb20_dbg_logic_analyzer_trace_63_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_host_current_belt : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_current_belt_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_current_belt_STATUS_snp_usb20_dbg_host_current_belt_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_current_belt_STATUS_snp_usb20_dbg_host_current_belt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_pme_generation : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_generation_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_generation_STATUS_snp_usb20_dbg_pme_generation_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_pme_generation_STATUS_snp_usb20_dbg_pme_generation_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_operational_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_operational_mode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_operational_mode_STATUS_snp_usb20_dbg_operational_mode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_operational_mode_STATUS_snp_usb20_dbg_operational_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_interrupt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_interrupt_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_interrupt_STATUS_snp_usb20_interrupt_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_interrupt_STATUS_snp_usb20_interrupt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_sysctrl_snp_usb20_host_system_err : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_host_system_err_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_host_system_err_STATUS_sysctrl_snp_usb20_host_system_err_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_host_system_err_STATUS_sysctrl_snp_usb20_host_system_err_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_l1_suspend_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_n_STATUS_snp_usb20_dbg_utmi_l1_suspend_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_n_STATUS_snp_usb20_dbg_utmi_l1_suspend_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_l1_suspend_com_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_com_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_com_n_STATUS_snp_usb20_dbg_utmi_l1_suspend_com_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_l1_suspend_com_n_STATUS_snp_usb20_dbg_utmi_l1_suspend_com_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_suspend_com_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_suspend_com_n_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_suspend_com_n_STATUS_snp_usb20_dbg_utmi_suspend_com_n_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_suspend_com_n_STATUS_snp_usb20_dbg_utmi_suspend_com_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_word_if : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_word_if_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_word_if_STATUS_snp_usb20_dbg_utmi_word_if_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_word_if_STATUS_snp_usb20_dbg_utmi_word_if_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_fsls_low_power : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fsls_low_power_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fsls_low_power_STATUS_snp_usb20_dbg_utmi_fsls_low_power_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fsls_low_power_STATUS_snp_usb20_dbg_utmi_fsls_low_power_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmi_fslsserialmode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fslsserialmode_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fslsserialmode_STATUS_snp_usb20_dbg_utmi_fslsserialmode_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmi_fslsserialmode_STATUS_snp_usb20_dbg_utmi_fslsserialmode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_hub_port_overcurrent : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_overcurrent_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_overcurrent_SET_snp_usb20_dbg_hub_port_overcurrent_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_overcurrent_SET_snp_usb20_dbg_hub_port_overcurrent_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_hub_port_perm_attach : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_perm_attach_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_perm_attach_SET_snp_usb20_dbg_hub_port_perm_attach_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_port_perm_attach_SET_snp_usb20_dbg_hub_port_perm_attach_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_num_u2_port : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_num_u2_port_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_num_u2_port_SET_snp_usb20_dbg_host_num_u2_port_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_num_u2_port_SET_snp_usb20_dbg_host_num_u2_port_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_u2_port_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_u2_port_disable_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_u2_port_disable_SET_snp_usb20_dbg_host_u2_port_disable_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_u2_port_disable_SET_snp_usb20_dbg_host_u2_port_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_port_power_control_present : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_port_power_control_present_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_port_power_control_present_SET_snp_usb20_dbg_host_port_power_control_present_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_port_power_control_present_SET_snp_usb20_dbg_host_port_power_control_present_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_msi_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_msi_enable_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_msi_enable_SET_snp_usb20_dbg_host_msi_enable_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_msi_enable_SET_snp_usb20_dbg_host_msi_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_SET_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_SET_snp_usb20_dbg_host_legacy_smi_pci_cmd_reg_wr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_host_legacy_smi_bar_wr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_bar_wr_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_bar_wr_SET_snp_usb20_dbg_host_legacy_smi_bar_wr_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_bar_wr_SET_snp_usb20_dbg_host_legacy_smi_bar_wr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_host_legacy_smi_interrupt : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_interrupt_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_interrupt_STATUS_snp_usb20_dbg_host_legacy_smi_interrupt_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_host_legacy_smi_interrupt_STATUS_snp_usb20_dbg_host_legacy_smi_interrupt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_fladj_30mhz_reg : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_fladj_30mhz_reg_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_fladj_30mhz_reg_SET_snp_usb20_dbg_fladj_30mhz_reg_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_fladj_30mhz_reg_SET_snp_usb20_dbg_fladj_30mhz_reg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_xhc_bme : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_xhc_bme_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_xhc_bme_SET_snp_usb20_dbg_xhc_bme_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_xhc_bme_SET_snp_usb20_dbg_xhc_bme_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_bus_filter_bypass : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bus_filter_bypass_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bus_filter_bypass_SET_snp_usb20_dbg_bus_filter_bypass_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bus_filter_bypass_SET_snp_usb20_dbg_bus_filter_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_work_mom : 1;
        unsigned int STATUS_his_usb20phy_suspend_mom : 1;
        unsigned int STATUS_his_usb20phy_sleep_mom : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_work_mom_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_work_mom_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_suspend_mom_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_suspend_mom_END (1)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_sleep_mom_START (2)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_powerstatus_STATUS_his_usb20phy_sleep_mom_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_rxerror_detect_cnt_clear : 1;
        unsigned int SET_his_usb20phy_rxerror_detect_cnt_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_SET_his_usb20phy_rxerror_detect_cnt_clear_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_SET_his_usb20phy_rxerror_detect_cnt_clear_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_SET_his_usb20phy_rxerror_detect_cnt_en_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_set_SET_his_usb20phy_rxerror_detect_cnt_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_rxerror_detect_cnt : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_STATUS_his_usb20phy_rxerror_detect_cnt_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_rxerror_detect_cnt_STATUS_his_usb20phy_rxerror_detect_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_his_usb20phy_pll_unlock_cnt_clear : 1;
        unsigned int SET_his_usb20phy_pll_unlock_cnt_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_SET_his_usb20phy_pll_unlock_cnt_clear_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_SET_his_usb20phy_pll_unlock_cnt_clear_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_SET_his_usb20phy_pll_unlock_cnt_en_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_set_SET_his_usb20phy_pll_unlock_cnt_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_his_usb20phy_pll_unlock_cnt : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_STATUS_his_usb20phy_pll_unlock_cnt_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_his_usb20phy_pll_unlock_cnt_STATUS_his_usb20phy_pll_unlock_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb20_testpoint_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_sel_SET_usb20_testpoint_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_sel_SET_usb20_testpoint_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_usb20_testpoint : 32;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_STATUS_usb20_testpoint_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_testpoint_STATUS_usb20_testpoint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb20_ulpi_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb20_ulpi_rst_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb20_ulpi_rst_SET_usb20_ulpi_rst_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20_ulpi_rst_SET_usb20_ulpi_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_utmi_port_reset_sel : 1;
        unsigned int SET_utmi_port_reset : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_SET_utmi_port_reset_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_SET_utmi_port_reset_sel_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_SET_utmi_port_reset_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_utmi_port_reset_SET_utmi_port_reset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_ram0_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_SET_snp_usb20_ram0_mem_ctrl_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_ram0_mem_ctrl_SET_snp_usb20_ram0_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_eop_timer_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_eop_timer_update_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_eop_timer_update_SET_snp_usb20_dbg_eop_timer_update_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_eop_timer_update_SET_snp_usb20_dbg_eop_timer_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_SET_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_SET_snp_usb20_dbg_usb20phy_8bit_ls_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_SET_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_SET_snp_usb20_dbg_usb20phy_16bit_ls_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_SET_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_SET_snp_usb20_dbg_usb20phy_8bit_nols_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_SET_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_SET_snp_usb20_dbg_usb20phy_16bit_nols_eop_timer_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_usb20phy_valid_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_valid_update_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_valid_update_SET_snp_usb20_dbg_usb20phy_valid_update_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_usb20phy_valid_update_SET_snp_usb20_dbg_usb20phy_valid_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_vbusvalid : 1;
        unsigned int SET_snp_usb20_dbg_vbusvalid_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_SET_snp_usb20_dbg_vbusvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_SET_snp_usb20_dbg_vbusvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_SET_snp_usb20_dbg_vbusvalid_sel_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_vbusvalid_SET_snp_usb20_dbg_vbusvalid_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_bvalid : 1;
        unsigned int SET_snp_usb20_dbg_bvalid_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_SET_snp_usb20_dbg_bvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_SET_snp_usb20_dbg_bvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_SET_snp_usb20_dbg_bvalid_sel_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_bvalid_SET_snp_usb20_dbg_bvalid_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_sessend : 1;
        unsigned int SET_snp_usb20_dbg_sessend_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_SET_snp_usb20_dbg_sessend_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_SET_snp_usb20_dbg_sessend_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_SET_snp_usb20_dbg_sessend_sel_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_sessend_SET_snp_usb20_dbg_sessend_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_hub_vbus_ctrl : 1;
        unsigned int SEL_snp_usb20_dbg_hub_vbus_ctrl : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_SET_snp_usb20_dbg_hub_vbus_ctrl_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_SET_snp_usb20_dbg_hub_vbus_ctrl_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_SEL_snp_usb20_dbg_hub_vbus_ctrl_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_hub_vbus_ctrl_SEL_snp_usb20_dbg_hub_vbus_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_hub_vbus_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_STATUS_snp_usb20_dbg_hub_vbus_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_snp_usb20_dbg_utmisrp_bvalid : 1;
        unsigned int SEL_snp_usb20_dbg_utmisrp_bvalid : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_SET_snp_usb20_dbg_utmisrp_bvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_SET_snp_usb20_dbg_utmisrp_bvalid_END (0)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_SEL_snp_usb20_dbg_utmisrp_bvalid_START (1)
#define SOC_MMC0_usb_subsys_sysctrl_snp_usb20_dbg_utmisrp_bvalid_SEL_snp_usb20_dbg_utmisrp_bvalid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_snp_usb20_dbg_utmisrp_bvalid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_utmisrp_bvalid_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_utmisrp_bvalid_STATUS_snp_usb20_dbg_utmisrp_bvalid_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_STATUS_snp_usb20_dbg_utmisrp_bvalid_STATUS_snp_usb20_dbg_utmisrp_bvalid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SEL_pad_mode_ulpi_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_pad_mode_ulpi_sel_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_pad_mode_ulpi_sel_SEL_pad_mode_ulpi_sel_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_pad_mode_ulpi_sel_SEL_pad_mode_ulpi_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_usb_ulpi_sel_indicator : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb_ulpi_sel_indicator_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb_ulpi_sel_indicator_STATUS_usb_ulpi_sel_indicator_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb_ulpi_sel_indicator_STATUS_usb_ulpi_sel_indicator_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int STATUS_usb20phy_refclk_sel_gpio_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_usb_subsys_sysctrl_usb20phy_refclk_sel_gpio_status_UNION;
#endif
#define SOC_MMC0_usb_subsys_sysctrl_usb20phy_refclk_sel_gpio_status_STATUS_usb20phy_refclk_sel_gpio_status_START (0)
#define SOC_MMC0_usb_subsys_sysctrl_usb20phy_refclk_sel_gpio_status_STATUS_usb20phy_refclk_sel_gpio_status_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
