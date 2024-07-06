/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : WIFI omeimage宏定义文件
 * 作    者 : wifi
 * 创建日期 : 2019年7月26日
 */

#ifndef WLAN_ONEIMAGE_DEFINE_HMAC1_H
#define WLAN_ONEIMAGE_DEFINE_HMAC1_H

/* 1 其他头文件包含 */
/* 2 宏定义 */
#if !defined(WIN32) && !defined(_PRE_WINDOWS_SUPPORT)
#define hmac_11i_ether_type_filter   wlan_oneimage_rename(hmac_11i_ether_type_filter)
#define hmac_11v_roam_start_worker   wlan_oneimage_rename(hmac_11v_roam_start_worker)
#define hmac_11v_roam_scan_check   wlan_oneimage_rename(hmac_11v_roam_scan_check)
#define hmac_11v_sta_tx_query   wlan_oneimage_rename(hmac_11v_sta_tx_query)
#define hmac_40m_intol_sync_data   wlan_oneimage_rename(hmac_40m_intol_sync_data)
#define hmac_get_80211_band_type   wlan_oneimage_rename(hmac_get_80211_band_type)
#define hmac_40m_intol_sync_event   wlan_oneimage_rename(hmac_40m_intol_sync_event)
#define hmac_add_and_clear_repeat_op_rates   wlan_oneimage_rename(hmac_add_and_clear_repeat_op_rates)
#define hmac_add_bound   wlan_oneimage_rename(hmac_add_bound)
#define hmac_add_p2p_cl_vap   wlan_oneimage_rename(hmac_add_p2p_cl_vap)
#define hmac_add_user_rates   wlan_oneimage_rename(hmac_add_user_rates)
#define hmac_adjust_freq   wlan_oneimage_rename(hmac_adjust_freq)
#define hmac_adjust_netbuf_data   wlan_oneimage_rename(hmac_adjust_netbuf_data)
#define hmac_adjust_set_freq   wlan_oneimage_rename(hmac_adjust_set_freq)
#define hmac_adjust_throughput   wlan_oneimage_rename(hmac_adjust_throughput)
#define hmac_amsdu_init_user   wlan_oneimage_rename(hmac_amsdu_init_user)
#define hmac_amsdu_notify   wlan_oneimage_rename(hmac_amsdu_notify)
#define hmac_amsdu_tx_process   wlan_oneimage_rename(hmac_amsdu_tx_process)
#define hmac_ant_tas_switch_rssi_notify_event_status wlan_oneimage_rename(hmac_ant_tas_switch_rssi_notify_event_status)
#define hmac_hid2d_drop_report wlan_oneimage_rename(hmac_hid2d_drop_report)
#define hmac_ap_check_owe_capa   wlan_oneimage_rename(hmac_ap_check_owe_capa)
#define hmac_ap_clean_bss   wlan_oneimage_rename(hmac_ap_clean_bss)
#define hmac_apf_program_report_event   wlan_oneimage_rename(hmac_apf_program_report_event)
#define hmac_apf_program_report_rx_adapt   wlan_oneimage_rename(hmac_apf_program_report_rx_adapt)
#define hmac_ap_save_user_assoc_req   wlan_oneimage_rename(hmac_ap_save_user_assoc_req)
#define hmac_ap_send_assoc_rsp   wlan_oneimage_rename(hmac_ap_send_assoc_rsp)
#define hmac_ap_up_misc   wlan_oneimage_rename(hmac_ap_up_misc)
#define hmac_ap_up_rx_auth_req_to_host   wlan_oneimage_rename(hmac_ap_up_rx_auth_req_to_host)
#define hmac_ap_up_rx_mgmt   wlan_oneimage_rename(hmac_ap_up_rx_mgmt)
#define hmac_ap_wait_start_misc   wlan_oneimage_rename(hmac_ap_wait_start_misc)
#define hmac_arp_offload_set_ip_addr   wlan_oneimage_rename(hmac_arp_offload_set_ip_addr)
#define hmac_assoc_set_siso_mode   wlan_oneimage_rename(hmac_assoc_set_siso_mode)
#define hmac_atcmdsrv_dbb_num_response   wlan_oneimage_rename(hmac_atcmdsrv_dbb_num_response)
#define hmac_atcmdsrv_fem_pa_response   wlan_oneimage_rename(hmac_atcmdsrv_fem_pa_response)
#define hmac_atcmdsrv_get_ant_response   wlan_oneimage_rename(hmac_atcmdsrv_get_ant_response)
#define hmac_config_get_rx_fcs_info   wlan_oneimage_rename(hmac_config_get_rx_fcs_info)
#define hmac_atcmdsrv_lte_gpio_check   wlan_oneimage_rename(hmac_atcmdsrv_lte_gpio_check)
#define hmac_atcmdsrv_report_efuse_reg   wlan_oneimage_rename(hmac_atcmdsrv_report_efuse_reg)
#define hmac_autoblacklist_enable   wlan_oneimage_rename(hmac_autoblacklist_enable)
#define hmac_autoblacklist_filter   wlan_oneimage_rename(hmac_autoblacklist_filter)
#define hmac_autoblacklist_set_aging   wlan_oneimage_rename(hmac_autoblacklist_set_aging)
#define hmac_autoblacklist_set_reset_time   wlan_oneimage_rename(hmac_autoblacklist_set_reset_time)
#define hmac_autoblacklist_set_threshold   wlan_oneimage_rename(hmac_autoblacklist_set_threshold)
#define hwifi_get_nvram_params   wlan_oneimage_rename(hwifi_get_nvram_params)
#define hwifi_config_init_nvram   wlan_oneimage_rename(hwifi_config_init_nvram)
#define original_value_for_nvram_params   wlan_oneimage_rename(original_value_for_nvram_params)
#define hwifi_config_sepa_coefficient_from_param   wlan_oneimage_rename(hwifi_config_sepa_coefficient_from_param)
#define hmac_backlist_get_drop   wlan_oneimage_rename(hmac_backlist_get_drop)
#define hmac_backlist_get_list_num   wlan_oneimage_rename(hmac_backlist_get_list_num)
#define hmac_ba_filter_serv   wlan_oneimage_rename(hmac_ba_filter_serv)
#define hmac_ba_rx_hdl_init   wlan_oneimage_rename(hmac_ba_rx_hdl_init)
#define hmac_ba_rx_hdl_baw_init   wlan_oneimage_rename(hmac_ba_rx_hdl_baw_init)
#define hmac_ba_reset_rx_handle   wlan_oneimage_rename(hmac_ba_reset_rx_handle)
#define hmac_ba_timeout_fn   wlan_oneimage_rename(hmac_ba_timeout_fn)
#define hmac_bgscan_enable   wlan_oneimage_rename(hmac_bgscan_enable)
#define hmac_blacklist_add   wlan_oneimage_rename(hmac_blacklist_add)
#define hmac_blacklist_add_only   wlan_oneimage_rename(hmac_blacklist_add_only)
#define hmac_blacklist_del   wlan_oneimage_rename(hmac_blacklist_del)
#define hmac_blacklist_filter   wlan_oneimage_rename(hmac_blacklist_filter)
#define hmac_blacklist_get_assoc_ap   wlan_oneimage_rename(hmac_blacklist_get_assoc_ap)
#define hmac_blacklist_get_mode   wlan_oneimage_rename(hmac_blacklist_get_mode)
#define hmac_blacklist_get_vap_in_device   wlan_oneimage_rename(hmac_blacklist_get_vap_in_device)
#define hmac_blacklist_set_mode   wlan_oneimage_rename(hmac_blacklist_set_mode)
#define hmac_board_exit   wlan_oneimage_rename(hmac_board_exit)
#define hmac_board_get_instance   wlan_oneimage_rename(hmac_board_get_instance)
#define hmac_board_init   wlan_oneimage_rename(hmac_board_init)
#define hmac_bridge_vap_xmit   wlan_oneimage_rename(hmac_bridge_vap_xmit)
#define hmac_btcoex_arp_fail_delba_process   wlan_oneimage_rename(hmac_btcoex_arp_fail_delba_process)
#define hmac_btcoex_blacklist_handle_init   wlan_oneimage_rename(hmac_btcoex_blacklist_handle_init)
#define hmac_btcoex_check_by_ba_size   wlan_oneimage_rename(hmac_btcoex_check_by_ba_size)
#define hmac_btcoex_check_exception_in_list   wlan_oneimage_rename(hmac_btcoex_check_exception_in_list)
#define hmac_btcoex_check_rx_same_baw_start_from_addba_req   \
    wlan_oneimage_rename(hmac_btcoex_check_rx_same_baw_start_from_addba_req)
#define hmac_btcoex_rx_delba_trigger   wlan_oneimage_rename(hmac_btcoex_rx_delba_trigger)
#define hmac_cac_chan_ctrl_machw_tx   wlan_oneimage_rename(hmac_cac_chan_ctrl_machw_tx)
#define hmac_calc_up_and_wait_vap   wlan_oneimage_rename(hmac_calc_up_and_wait_vap)
#define hmac_calc_up_ap_num   wlan_oneimage_rename(hmac_calc_up_ap_num)
#define hmac_cali2hmac_event_rx_adapt   wlan_oneimage_rename(hmac_cali2hmac_event_rx_adapt)
#define hmac_cfg80211_check_can_start_sched_scan wlan_oneimage_rename(hmac_cfg80211_check_can_start_sched_scan)
#define hmac_cfg80211_dump_survey   wlan_oneimage_rename(hmac_cfg80211_dump_survey)
#define hmac_cfg80211_start_scan_sta   wlan_oneimage_rename(hmac_cfg80211_start_scan_sta)
#define hmac_cfg80211_start_sched_scan   wlan_oneimage_rename(hmac_cfg80211_start_sched_scan)
#define hmac_cfg80211_stop_sched_scan   wlan_oneimage_rename(hmac_cfg80211_stop_sched_scan)
#define hmac_cfg_vap_send_event   wlan_oneimage_rename(hmac_cfg_vap_send_event)

#define hmac_chan_do_sync   wlan_oneimage_rename(hmac_chan_do_sync)

#define hmac_chan_initiate_switch_to_new_channel_tx_adapt   \
    wlan_oneimage_rename(hmac_chan_initiate_switch_to_new_channel_tx_adapt)
#define hmac_chan_initiate_switch_to_new_channel   wlan_oneimage_rename(hmac_chan_initiate_switch_to_new_channel)
#define hmac_chan_multi_select_channel_mac   wlan_oneimage_rename(hmac_chan_multi_select_channel_mac)
#define hmac_chan_multi_switch_to_new_channel   wlan_oneimage_rename(hmac_chan_multi_switch_to_new_channel)
#define hmac_chan_restart_network_after_switch   wlan_oneimage_rename(hmac_chan_restart_network_after_switch)
#define hmac_chan_reval_bandwidth_sta   wlan_oneimage_rename(hmac_chan_reval_bandwidth_sta)
#define hmac_chan_select_channel_mac_tx_adapt   wlan_oneimage_rename(hmac_chan_select_channel_mac_tx_adapt)
#define hmac_chan_start_bss   wlan_oneimage_rename(hmac_chan_start_bss)
#define hmac_chan_switch_to_new_chan_complete   wlan_oneimage_rename(hmac_chan_switch_to_new_chan_complete)
#define hmac_chan_sync   wlan_oneimage_rename(hmac_chan_sync)
#define hmac_chan_sync_init   wlan_oneimage_rename(hmac_chan_sync_init)
#define hmac_chan_update_40m_intol_user   wlan_oneimage_rename(hmac_chan_update_40m_intol_user)
#define hmac_check_bss_cap_info   wlan_oneimage_rename(hmac_check_bss_cap_info)
#define hmac_check_capability_mac_phy_supplicant wlan_oneimage_rename(hmac_check_capability_mac_phy_supplicant)
#define hmac_check_opmode_notify   wlan_oneimage_rename(hmac_check_opmode_notify)
#define hmac_check_p2p_vap_num   wlan_oneimage_rename(hmac_check_p2p_vap_num)
#define hmac_chr_connect_code_get_pointer   wlan_oneimage_rename(hmac_chr_connect_code_get_pointer)
#define hmac_chr_connect_fail_query_and_report   wlan_oneimage_rename(hmac_chr_connect_fail_query_and_report)
#define hmac_chr_del_ba_info_get_pointer   wlan_oneimage_rename(hmac_chr_del_ba_info_get_pointer)
#define hmac_chr_disasoc_reason_get_pointer   wlan_oneimage_rename(hmac_chr_disasoc_reason_get_pointer)
#define hmac_chr_get_chip_info   wlan_oneimage_rename(hmac_chr_get_chip_info)
#define hmac_chr_get_connect_code   wlan_oneimage_rename(hmac_chr_get_connect_code)
#define hmac_chr_get_del_ba_info   wlan_oneimage_rename(hmac_chr_get_del_ba_info)
#define hmac_chr_get_disasoc_reason   wlan_oneimage_rename(hmac_chr_get_disasoc_reason)
#define hmac_chr_get_vap_info   wlan_oneimage_rename(hmac_chr_get_vap_info)
#define hmac_chr_info_clean   wlan_oneimage_rename(hmac_chr_info_clean)
#define hmac_chr_roam_info_report   wlan_oneimage_rename(hmac_chr_roam_info_report)
#define hmac_chr_set_ba_session_num   wlan_oneimage_rename(hmac_chr_set_ba_session_num)
#define hmac_chr_set_connect_code   wlan_oneimage_rename(hmac_chr_set_connect_code)
#define hmac_chr_set_del_ba_info   wlan_oneimage_rename(hmac_chr_set_del_ba_info)
#define hmac_chr_set_disasoc_reason   wlan_oneimage_rename(hmac_chr_set_disasoc_reason)
#define hmac_clr_p2p_status   wlan_oneimage_rename(hmac_clr_p2p_status)
#define hmac_identify_type_of_ap_with_compatibility_issues \
    wlan_oneimage_rename(hmac_identify_type_of_ap_with_compatibility_issues)
#define hmac_user_set_amsdu_level_by_max_mpdu_len   wlan_oneimage_rename(hmac_user_set_amsdu_level_by_max_mpdu_len)
#define hmac_user_set_amsdu_level   wlan_oneimage_rename(hmac_user_set_amsdu_level)
#define hmac_compability_ap_tpye_identify_for_btcoex wlan_oneimage_rename(hmac_compability_ap_tpye_identify_for_btcoex)
#define hmac_user_cap_update_by_hisi_cap_ie   wlan_oneimage_rename(hmac_user_cap_update_by_hisi_cap_ie)
#define hwifi_config_init_private_custom wlan_oneimage_rename(hwifi_config_init_private_custom)
#define hwifi_get_init_priv_value   wlan_oneimage_rename(hwifi_get_init_priv_value)
#define hwifi_custom_adapt_device_priv_ini_param   wlan_oneimage_rename(hwifi_custom_adapt_device_priv_ini_param)
#define hwifi_config_init_dts_main    wlan_oneimage_rename(hwifi_config_init_dts_main)
#define hmac_config_11i_add_key   wlan_oneimage_rename(hmac_config_11i_add_key)
#define hmac_config_11i_add_wep_entry   wlan_oneimage_rename(hmac_config_11i_add_wep_entry)
#define hmac_config_11i_get_key   wlan_oneimage_rename(hmac_config_11i_get_key)
#define hmac_config_11i_remove_key   wlan_oneimage_rename(hmac_config_11i_remove_key)
#define hmac_config_11i_set_default_key   wlan_oneimage_rename(hmac_config_11i_set_default_key)
#define hmac_config_80211_ucast_switch   wlan_oneimage_rename(hmac_config_80211_ucast_switch)
#define hmac_config_addba_req   wlan_oneimage_rename(hmac_config_addba_req)
#define hmac_config_addts_req   wlan_oneimage_rename(hmac_config_addts_req)
#define hmac_config_reassoc_req   wlan_oneimage_rename(hmac_config_reassoc_req)
#define hmac_config_add_user   wlan_oneimage_rename(hmac_config_add_user)
#define hmac_config_add_vap   wlan_oneimage_rename(hmac_config_add_vap)
#define hmac_config_akm2string   wlan_oneimage_rename(hmac_config_akm2string)
#define hmac_config_alg   wlan_oneimage_rename(hmac_config_alg)
#define hmac_config_alg_param   wlan_oneimage_rename(hmac_config_alg_param)
#define hmac_config_always_rx   wlan_oneimage_rename(hmac_config_always_rx)
#define hmac_config_always_tx_aggr_num   wlan_oneimage_rename(hmac_config_always_tx_aggr_num)
#define hmac_config_always_tx_num   wlan_oneimage_rename(hmac_config_always_tx_num)
#define hmac_config_always_tx   wlan_oneimage_rename(hmac_config_always_tx)
#define hmac_config_amsdu_ampdu_switch   wlan_oneimage_rename(hmac_config_amsdu_ampdu_switch)
#define hmac_config_apf_filter_cmd   wlan_oneimage_rename(hmac_config_apf_filter_cmd)
#define hmac_config_autoblacklist_enable   wlan_oneimage_rename(hmac_config_autoblacklist_enable)
#define hmac_config_ax_debug   wlan_oneimage_rename(hmac_config_ax_debug)
#define hmac_config_band2string   wlan_oneimage_rename(hmac_config_band2string)
#define hmac_config_bcn_table_switch   wlan_oneimage_rename(hmac_config_bcn_table_switch)
#define hmac_config_beacon_chain_switch   wlan_oneimage_rename(hmac_config_beacon_chain_switch)

#define hmac_config_blacklist_add   wlan_oneimage_rename(hmac_config_blacklist_add)
#define hmac_config_blacklist_add_only   wlan_oneimage_rename(hmac_config_blacklist_add_only)
#define hmac_config_blacklist_del   wlan_oneimage_rename(hmac_config_blacklist_del)
#define hmac_config_btcoex_preempt_type   wlan_oneimage_rename(hmac_config_btcoex_preempt_type)
#define hmac_config_btcoex_set_perf_param   wlan_oneimage_rename(hmac_config_btcoex_set_perf_param)
#define hmac_config_b_w2string   wlan_oneimage_rename(hmac_config_b_w2string)
#define hmac_config_bw2string   wlan_oneimage_rename(hmac_config_bw2string)
#define hmac_config_cancel_remain_on_channel   wlan_oneimage_rename(hmac_config_cancel_remain_on_channel)
#define hmac_config_cfg_vap_h2d   wlan_oneimage_rename(hmac_config_cfg_vap_h2d)
#define hmac_config_chan_bw_exceed   wlan_oneimage_rename(hmac_config_chan_bw_exceed)
#define hmac_config_ch_status_sync   wlan_oneimage_rename(hmac_config_ch_status_sync)
#define hmac_config_ciper2string   wlan_oneimage_rename(hmac_config_ciper2string)
#define hmac_config_cipher2string   wlan_oneimage_rename(hmac_config_cipher2string)
#define hmac_config_connect   wlan_oneimage_rename(hmac_config_connect)
#define hmac_config_d2h_device_m2s_info_syn   wlan_oneimage_rename(hmac_config_d2h_device_m2s_info_syn)
#define hmac_config_d2h_vap_m2s_info_syn   wlan_oneimage_rename(hmac_config_d2h_vap_m2s_info_syn)
#define hmac_config_dbdc_debug_switch   wlan_oneimage_rename(hmac_config_dbdc_debug_switch)
#define hmac_config_def_chan   wlan_oneimage_rename(hmac_config_def_chan)
#define hmac_config_delba_req   wlan_oneimage_rename(hmac_config_delba_req)
#define hmac_config_del_p2p_ie   wlan_oneimage_rename(hmac_config_del_p2p_ie)
#define hmac_config_del_pmksa   wlan_oneimage_rename(hmac_config_del_pmksa)
#define hmac_config_del_scaning_flag   wlan_oneimage_rename(hmac_config_del_scaning_flag)
#define hmac_config_delts   wlan_oneimage_rename(hmac_config_delts)
#define hmac_config_del_user   wlan_oneimage_rename(hmac_config_del_user)
#define hmac_config_del_vap   wlan_oneimage_rename(hmac_config_del_vap)
#define hmac_config_dev2string   wlan_oneimage_rename(hmac_config_dev2string)
#define hmac_config_down_vap   wlan_oneimage_rename(hmac_config_down_vap)
#define hmac_config_dpd_cfg   wlan_oneimage_rename(hmac_config_dpd_cfg)
#define hmac_config_dyn_cali_param   wlan_oneimage_rename(hmac_config_dyn_cali_param)
#define hmac_config_enable_2040bss   wlan_oneimage_rename(hmac_config_enable_2040bss)
#define hmac_config_enable_arp_offload   wlan_oneimage_rename(hmac_config_enable_arp_offload)
#define hmac_config_eth_switch   wlan_oneimage_rename(hmac_config_eth_switch)
#define hmac_config_external_auth   wlan_oneimage_rename(hmac_config_external_auth)
#define hmac_config_fem_lp_flag   wlan_oneimage_rename(hmac_config_fem_lp_flag)
#define hmac_config_flush_pmksa   wlan_oneimage_rename(hmac_config_flush_pmksa)
#define hmac_config_force_stop_filter   wlan_oneimage_rename(hmac_config_force_stop_filter)
#define hmac_config_ftm_dbg   wlan_oneimage_rename(hmac_config_ftm_dbg)
#define hmac_config_get_2040bss_sw   wlan_oneimage_rename(hmac_config_get_2040bss_sw)
#define hmac_config_get_ampdu_tx_on   wlan_oneimage_rename(hmac_config_get_ampdu_tx_on)
#define hmac_config_get_amsdu_tx_on   wlan_oneimage_rename(hmac_config_get_amsdu_tx_on)
#define hmac_config_get_auth_mode   wlan_oneimage_rename(hmac_config_get_auth_mode)
#define hmac_config_get_bintval   wlan_oneimage_rename(hmac_config_get_bintval)
#define hmac_config_get_blacklist_mode   wlan_oneimage_rename(hmac_config_get_blacklist_mode)
#define hmac_config_get_bss_type   wlan_oneimage_rename(hmac_config_get_bss_type)
#define hmac_config_get_country   wlan_oneimage_rename(hmac_config_get_country)
#define hmac_config_get_device_freq   wlan_oneimage_rename(hmac_config_get_device_freq)
#define hmac_config_get_dieid_rsp   wlan_oneimage_rename(hmac_config_get_dieid_rsp)
#define hmac_config_get_dieid   wlan_oneimage_rename(hmac_config_get_dieid)
#define hmac_config_get_dtimperiod   wlan_oneimage_rename(hmac_config_get_dtimperiod)
#define hmac_config_get_flowctl_stat   wlan_oneimage_rename(hmac_config_get_flowctl_stat)
#define hmac_config_get_freq   wlan_oneimage_rename(hmac_config_get_freq)
#define hmac_config_get_hipkt_stat   wlan_oneimage_rename(hmac_config_get_hipkt_stat)
#define hmac_config_get_max_user   wlan_oneimage_rename(hmac_config_get_max_user)
#define hmac_config_get_mode   wlan_oneimage_rename(hmac_config_get_mode)
#define hmac_config_get_monitor   wlan_oneimage_rename(hmac_config_get_monitor)
#define hmac_config_set_pt_mcast   wlan_oneimage_rename(hmac_config_set_pt_mcast)
#define hmac_config_get_mpdu_num   wlan_oneimage_rename(hmac_config_get_mpdu_num)
#define hmac_config_get_nobeacon   wlan_oneimage_rename(hmac_config_get_nobeacon)
#define hmac_config_get_prot_mode   wlan_oneimage_rename(hmac_config_get_prot_mode)
#define hmac_config_get_shortgi20   wlan_oneimage_rename(hmac_config_get_shortgi20)
#define hmac_config_get_shortgi40   wlan_oneimage_rename(hmac_config_get_shortgi40)
#define hmac_config_get_shortgi80   wlan_oneimage_rename(hmac_config_get_shortgi80)
#define hmac_config_get_shpreamble   wlan_oneimage_rename(hmac_config_get_shpreamble)
#define hmac_config_get_ssid   wlan_oneimage_rename(hmac_config_get_ssid)
#define hmac_config_get_sta_11h_abillty   wlan_oneimage_rename(hmac_config_get_sta_11h_abillty)
#define hmac_config_get_sta_list   wlan_oneimage_rename(hmac_config_get_sta_list)
#define hmac_config_get_tid   wlan_oneimage_rename(hmac_config_get_tid)
#define hmac_config_get_txpower   wlan_oneimage_rename(hmac_config_get_txpower)
#define hmac_config_get_uapsden   wlan_oneimage_rename(hmac_config_get_uapsden)
#define hmac_config_get_user_rssbw   wlan_oneimage_rename(hmac_config_get_user_rssbw)
#define hmac_config_get_vap_wmm_switch   wlan_oneimage_rename(hmac_config_get_vap_wmm_switch)
#define hmac_config_get_version   wlan_oneimage_rename(hmac_config_get_version)
#define hmac_config_get_wmmswitch   wlan_oneimage_rename(hmac_config_get_wmmswitch)
#define hmac_config_h2d_send_app_ie   wlan_oneimage_rename(hmac_config_h2d_send_app_ie)
#define hmac_config_host_dev_exit   wlan_oneimage_rename(hmac_config_host_dev_exit)
#define hmac_config_host_dev_init   wlan_oneimage_rename(hmac_config_host_dev_init)
#define hmac_config_index2string   wlan_oneimage_rename(hmac_config_index2string)
#define hmac_config_keytype2string   wlan_oneimage_rename(hmac_config_keytype2string)
#define hmac_config_kick_user   wlan_oneimage_rename(hmac_config_kick_user)
#define hmac_config_list_channel   wlan_oneimage_rename(hmac_config_list_channel)
#define hmac_config_list_sta   wlan_oneimage_rename(hmac_config_list_sta)
#define hmac_config_log_level   wlan_oneimage_rename(hmac_config_log_level)
#define hmac_config_lte_gpio_mode   wlan_oneimage_rename(hmac_config_lte_gpio_mode)
#define hmac_config_mimo_compatibility   wlan_oneimage_rename(hmac_config_mimo_compatibility)
#define hmac_config_nrcoex_test   wlan_oneimage_rename(hmac_config_nrcoex_test)
#define hmac_config_nss2string   wlan_oneimage_rename(hmac_config_nss2string)
#define hmac_config_open_wmm   wlan_oneimage_rename(hmac_config_open_wmm)
#define hmac_config_ota_switch   wlan_oneimage_rename(hmac_config_ota_switch)
#define hmac_config_ota_rx_dscr_switch   wlan_oneimage_rename(hmac_config_ota_rx_dscr_switch)
#define hmac_config_phy_debug_switch   wlan_oneimage_rename(hmac_config_phy_debug_switch)
#define hmac_config_pk_mode_debug   wlan_oneimage_rename(hmac_config_pk_mode_debug)
#define hmac_config_pkt_time_switch   wlan_oneimage_rename(hmac_config_pkt_time_switch)
#define hmac_config_pm_debug_switch   wlan_oneimage_rename(hmac_config_pm_debug_switch)
#define hmac_config_protocol2string   wlan_oneimage_rename(hmac_config_protocol2string)
#define hmac_config_protocol_debug_switch   wlan_oneimage_rename(hmac_config_protocol_debug_switch)
#define hmac_config_query_ani   wlan_oneimage_rename(hmac_config_query_ani)
#define hmac_config_query_nrcoex_stat   wlan_oneimage_rename(hmac_config_query_nrcoex_stat)
#define hmac_config_query_psm_flt_stat   wlan_oneimage_rename(hmac_config_query_psm_flt_stat)
#define hmac_config_query_psst   wlan_oneimage_rename(hmac_config_query_psst)
#define hmac_config_query_rate   wlan_oneimage_rename(hmac_config_query_rate)
#define hmac_config_query_rssi   wlan_oneimage_rename(hmac_config_query_rssi)
#define hmac_config_query_station_info   wlan_oneimage_rename(hmac_config_query_station_info)
#define hmac_config_reduce_sar   wlan_oneimage_rename(hmac_config_reduce_sar)
#ifdef PLATFORM_DEBUG_ENABLE
#define hmac_config_reg_info   wlan_oneimage_rename(hmac_config_reg_info)
#define hmac_config_reg_write   wlan_oneimage_rename(hmac_config_reg_write)
#endif
#define hmac_config_remove_app_ie   wlan_oneimage_rename(hmac_config_remove_app_ie)
#define hmac_config_report_all_stat   wlan_oneimage_rename(hmac_config_report_all_stat)
#define hmac_config_reset_hw   wlan_oneimage_rename(hmac_config_reset_hw)
#define hmac_config_reset_operate   wlan_oneimage_rename(hmac_config_reset_operate)
#define hmac_config_roam_start   wlan_oneimage_rename(hmac_config_roam_start)
#define hmac_config_ru_set   wlan_oneimage_rename(hmac_config_ru_set)
#define hmac_config_rx_ampdu_amsdu   wlan_oneimage_rename(hmac_config_rx_ampdu_amsdu)
#define hmac_config_rx_fcs_info   wlan_oneimage_rename(hmac_config_rx_fcs_info)
#define hmac_config_scan_abort   wlan_oneimage_rename(hmac_config_scan_abort)
#define hmac_config_sdio_flowctrl   wlan_oneimage_rename(hmac_config_sdio_flowctrl)
#define hmac_config_send_2040_coext   wlan_oneimage_rename(hmac_config_send_2040_coext)
#define hmac_config_send_bar   wlan_oneimage_rename(hmac_config_send_bar)
#define hmac_config_send_deauth   wlan_oneimage_rename(hmac_config_send_deauth)
#define hmac_config_send_event   wlan_oneimage_rename(hmac_config_send_event)
#define hmac_config_alg_send_event   wlan_oneimage_rename(hmac_config_alg_send_event)
#define hmac_config_send_neighbor_req   wlan_oneimage_rename(hmac_config_send_neighbor_req)
#define hmac_config_set_2040_coext_support   wlan_oneimage_rename(hmac_config_set_2040_coext_support)
#define hmac_config_set_addba_rsp_buffer   wlan_oneimage_rename(hmac_config_set_addba_rsp_buffer)
#define hmac_config_set_addba_rsp_extend   wlan_oneimage_rename(hmac_config_set_addba_rsp_extend)
#define hmac_config_set_all_log_level   wlan_oneimage_rename(hmac_config_set_all_log_level)
#define hmac_config_set_ampdu_aggr_num   wlan_oneimage_rename(hmac_config_set_ampdu_aggr_num)
#define hmac_config_set_ampdu_tx_on   wlan_oneimage_rename(hmac_config_set_ampdu_tx_on)
#define hmac_config_set_amsdu_tx_on   wlan_oneimage_rename(hmac_config_set_amsdu_tx_on)
#define hmac_config_set_app_ie_to_vap   wlan_oneimage_rename(hmac_config_set_app_ie_to_vap)
#define hmac_config_set_auth_mode   wlan_oneimage_rename(hmac_config_set_auth_mode)
#define hmac_config_set_autoblacklist_aging   wlan_oneimage_rename(hmac_config_set_autoblacklist_aging)
#define hmac_config_set_autoblacklist_reset_time wlan_oneimage_rename(hmac_config_set_autoblacklist_reset_time)
#define hmac_config_set_autoblacklist_threshold   wlan_oneimage_rename(hmac_config_set_autoblacklist_threshold)
#define hmac_config_set_auto_freq_enable   wlan_oneimage_rename(hmac_config_set_auto_freq_enable)
#define hmac_config_set_beacon   wlan_oneimage_rename(hmac_config_set_beacon)
#define hmac_config_set_bintval   wlan_oneimage_rename(hmac_config_set_bintval)
#define hmac_config_set_blacklist_mode   wlan_oneimage_rename(hmac_config_set_blacklist_mode)
#define hmac_config_set_bss_type   wlan_oneimage_rename(hmac_config_set_bss_type)
#define hmac_config_set_bw   wlan_oneimage_rename(hmac_config_set_bw)
#define hmac_config_set_channel   wlan_oneimage_rename(hmac_config_set_channel)
#define hmac_config_set_country   wlan_oneimage_rename(hmac_config_set_country)
#define hmac_config_set_country_for_dfs   wlan_oneimage_rename(hmac_config_set_country_for_dfs)
#define hmac_config_set_csi   wlan_oneimage_rename(hmac_config_set_csi)
#define hmac_config_set_cus_dts_cali   wlan_oneimage_rename(hmac_config_set_cus_dts_cali)
#define hmac_config_set_cus_dyn_cali   wlan_oneimage_rename(hmac_config_set_cus_dyn_cali)
#define hmac_config_set_cus_nvram_params   wlan_oneimage_rename(hmac_config_set_cus_nvram_params)
#define hmac_config_set_cus_rf   wlan_oneimage_rename(hmac_config_set_cus_rf)
#define hmac_config_set_device_freq   wlan_oneimage_rename(hmac_config_set_device_freq)
#define hmac_config_set_device_freq_testcase   wlan_oneimage_rename(hmac_config_set_device_freq_testcase)
#define hmac_config_set_device_pkt_stat   wlan_oneimage_rename(hmac_config_set_device_pkt_stat)
#define hmac_config_set_dscr_param   wlan_oneimage_rename(hmac_config_set_dscr_param)
#define hmac_config_set_dtimperiod   wlan_oneimage_rename(hmac_config_set_dtimperiod)
#define hmac_config_set_fast_sleep_para   wlan_oneimage_rename(hmac_config_set_fast_sleep_para)
#define hmac_config_set_freq   wlan_oneimage_rename(hmac_config_set_freq)
#define hmac_config_set_ft_ies   wlan_oneimage_rename(hmac_config_set_ft_ies)
#define hmac_config_set_ip_addr   wlan_oneimage_rename(hmac_config_set_ip_addr)
#define hmac_config_set_m2s_switch   wlan_oneimage_rename(hmac_config_set_m2s_switch)
#define hmac_config_set_mac_addr   wlan_oneimage_rename(hmac_config_set_mac_addr)
#define hmac_config_set_max_user   wlan_oneimage_rename(hmac_config_set_max_user)
#define hmac_config_set_mcsac   wlan_oneimage_rename(hmac_config_set_mcsac)
#define hmac_config_set_mcsax_er   wlan_oneimage_rename(hmac_config_set_mcsax_er)
#define hmac_config_set_mcsax   wlan_oneimage_rename(hmac_config_set_mcsax)
#define hmac_config_set_mcs   wlan_oneimage_rename(hmac_config_set_mcs)
#define hmac_config_set_mgmt_log   wlan_oneimage_rename(hmac_config_set_mgmt_log)
#define hmac_config_set_mib_by_bw   wlan_oneimage_rename(hmac_config_set_mib_by_bw)
#define hmac_config_set_mlme   wlan_oneimage_rename(hmac_config_set_mlme)
#define hmac_config_set_mode   wlan_oneimage_rename(hmac_config_set_mode)
#define hmac_config_set_monitor_mode   wlan_oneimage_rename(hmac_config_set_monitor_mode)
#define hmac_config_set_nobeacon   wlan_oneimage_rename(hmac_config_set_nobeacon)
#define hmac_config_set_nss   wlan_oneimage_rename(hmac_config_set_nss)
#define hmac_config_set_owe   wlan_oneimage_rename(hmac_config_set_owe)
#define hmac_config_set_dc_status   wlan_oneimage_rename(hmac_config_set_dc_status)
#define hmac_config_set_p2p_miracast_status   wlan_oneimage_rename(hmac_config_set_p2p_miracast_status)
#define hmac_config_set_p2p_ps_noa   wlan_oneimage_rename(hmac_config_set_p2p_ps_noa)
#define hmac_config_set_p2p_ps_ops   wlan_oneimage_rename(hmac_config_set_p2p_ps_ops)
#define hmac_config_set_p2p_ps_stat   wlan_oneimage_rename(hmac_config_set_p2p_ps_stat)
#define hmac_config_set_pm_by_module   wlan_oneimage_rename(hmac_config_set_pm_by_module)
#define hmac_config_set_pmksa   wlan_oneimage_rename(hmac_config_set_pmksa)
#define hmac_config_set_prot_mode   wlan_oneimage_rename(hmac_config_set_prot_mode)
#define hmac_config_set_random_mac_addr_scan   wlan_oneimage_rename(hmac_config_set_random_mac_addr_scan)
#define hmac_config_set_random_mac_oui   wlan_oneimage_rename(hmac_config_set_random_mac_oui)
#define hmac_config_set_rate   wlan_oneimage_rename(hmac_config_set_rate)
#define hmac_config_set_reset_state   wlan_oneimage_rename(hmac_config_set_reset_state)
#define hmac_config_set_rfch   wlan_oneimage_rename(hmac_config_set_rfch)
#define hmac_config_set_shortgi20   wlan_oneimage_rename(hmac_config_set_shortgi20)
#define hmac_config_set_shortgi40   wlan_oneimage_rename(hmac_config_set_shortgi40)
#define hmac_config_set_shortgi80   wlan_oneimage_rename(hmac_config_set_shortgi80)
#define hmac_config_set_shpreamble   wlan_oneimage_rename(hmac_config_set_shpreamble)
#define hmac_config_set_sniffer   wlan_oneimage_rename(hmac_config_set_sniffer)
#define hmac_config_set_ssid   wlan_oneimage_rename(hmac_config_set_ssid)
#define hmac_config_set_sta_pm_mode   wlan_oneimage_rename(hmac_config_set_sta_pm_mode)
#define hmac_config_set_sta_pm_on   wlan_oneimage_rename(hmac_config_set_sta_pm_on)
#define hmac_config_set_str_cmd   wlan_oneimage_rename(hmac_config_set_str_cmd)
#define hmac_config_set_tlv_cmd   wlan_oneimage_rename(hmac_config_set_tlv_cmd)
#define hmac_config_set_tx_ampdu_type   wlan_oneimage_rename(hmac_config_set_tx_ampdu_type)
#define hmac_config_set_txpower   wlan_oneimage_rename(hmac_config_set_txpower)
#define hmac_config_set_tx_pow_param   wlan_oneimage_rename(hmac_config_set_tx_pow_param)
#define hmac_config_set_uapsden   wlan_oneimage_rename(hmac_config_set_uapsden)
#define hmac_config_set_uapsd_para   wlan_oneimage_rename(hmac_config_set_uapsd_para)
#define hmac_config_set_vap_wmm_switch   wlan_oneimage_rename(hmac_config_set_vap_wmm_switch)
#define hmac_config_set_vendor_ie   wlan_oneimage_rename(hmac_config_set_vendor_ie)
#define hmac_config_set_vowifi_nat_keep_alive_params wlan_oneimage_rename(hmac_config_set_vowifi_nat_keep_alive_params)
#define hmac_config_set_wmm_params   wlan_oneimage_rename(hmac_config_set_wmm_params)
#define hmac_config_set_wps_ie   wlan_oneimage_rename(hmac_config_set_wps_ie)
#define hmac_config_set_wps_p2p_ie   wlan_oneimage_rename(hmac_config_set_wps_p2p_ie)
#define hmac_config_smps2string   wlan_oneimage_rename(hmac_config_smps2string)
#define hmac_config_softap_mimo_mode   wlan_oneimage_rename(hmac_config_softap_mimo_mode)
#define hmac_config_start_vap   wlan_oneimage_rename(hmac_config_start_vap)
#define hmac_config_start_vap_event   wlan_oneimage_rename(hmac_config_start_vap_event)
#define hmac_config_sta_update_rates   wlan_oneimage_rename(hmac_config_sta_update_rates)
#define hmac_config_sta_vap_info_syn   wlan_oneimage_rename(hmac_config_sta_vap_info_syn)
#define hmac_config_stop_altx   wlan_oneimage_rename(hmac_config_stop_altx)
#define hmac_config_sync_cmd_common   wlan_oneimage_rename(hmac_config_sync_cmd_common)
#define hmac_config_tas_pwr_ctrl   wlan_oneimage_rename(hmac_config_tas_pwr_ctrl)
#define hmac_config_tas_rssi_access   wlan_oneimage_rename(hmac_config_tas_rssi_access)
#define hmac_config_tcp_ack_buf   wlan_oneimage_rename(hmac_config_tcp_ack_buf)
#define hmac_config_twt_setup_req_auto   wlan_oneimage_rename(hmac_config_twt_setup_req_auto)
#define hmac_config_twt_setup_req   wlan_oneimage_rename(hmac_config_twt_setup_req)
#define hmac_config_twt_teardown_req_auto   wlan_oneimage_rename(hmac_config_twt_teardown_req_auto)
#define hmac_config_twt_teardown_req   wlan_oneimage_rename(hmac_config_twt_teardown_req)
#define hmac_config_update_ip_filter   wlan_oneimage_rename(hmac_config_update_ip_filter)
#define hmac_config_user_asoc_state_syn   wlan_oneimage_rename(hmac_config_user_asoc_state_syn)
#define hmac_config_user_cap_syn   wlan_oneimage_rename(hmac_config_user_cap_syn)
#define hmac_config_user_info   wlan_oneimage_rename(hmac_config_user_info)
#define hmac_config_user_info_syn   wlan_oneimage_rename(hmac_config_user_info_syn)
#define hmac_config_user_m2s_info_syn   wlan_oneimage_rename(hmac_config_user_m2s_info_syn)
#define hmac_config_user_num_spatial_stream_cap_syn   wlan_oneimage_rename(hmac_config_user_num_spatial_stream_cap_syn)
#define hmac_config_user_rate_info_syn   wlan_oneimage_rename(hmac_config_user_rate_info_syn)
#define hmac_config_usr_queue_stat   wlan_oneimage_rename(hmac_config_usr_queue_stat)
#define hmac_config_vap_classify_en   wlan_oneimage_rename(hmac_config_vap_classify_en)
#define hmac_config_vap_classify_tid   wlan_oneimage_rename(hmac_config_vap_classify_tid)
#define hmac_config_vap_close_txbf_cap   wlan_oneimage_rename(hmac_config_vap_close_txbf_cap)
#define hmac_config_vap_info   wlan_oneimage_rename(hmac_config_vap_info)
#define hmac_config_vap_m2s_info_syn   wlan_oneimage_rename(hmac_config_vap_m2s_info_syn)
#define hmac_config_vap_pmf_cap   wlan_oneimage_rename(hmac_config_vap_pmf_cap)
#define hmac_config_vap_state_syn   wlan_oneimage_rename(hmac_config_vap_state_syn)
#define hmac_config_vendor_cmd_get_channel_list   wlan_oneimage_rename(hmac_config_vendor_cmd_get_channel_list)
#define hmac_config_voe_enable   wlan_oneimage_rename(hmac_config_voe_enable)
#define hmac_config_vowifi_info   wlan_oneimage_rename(hmac_config_vowifi_info)
#define hmac_config_vowifi_report   wlan_oneimage_rename(hmac_config_vowifi_report)

#endif /* end of #if !defined(WIN32) */

#endif /* end of wlan_oneimage_define.h */
