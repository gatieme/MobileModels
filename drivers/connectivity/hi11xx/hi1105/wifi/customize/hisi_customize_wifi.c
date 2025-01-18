/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明   : wifi定制化函数
 * 作者       :
 * 创建日期   : 2020年11月05日
 */

#include "hisi_customize_wifi.h"
#include "hisi_ini.h"
#include "wlan_chip_i.h"
#include "wal_linux_ioctl.h"

char g_wifi_country_code[COUNTRY_CODE_LEN] = "00";

wlan_cust_country_code_ingore_flag_stru g_cust_country_code_ignore_flag = {0}; /* 定制化国家码配置 */

oal_bool_enum_uint8 g_en_nv_dp_init_is_null = OAL_TRUE; /* NVRAM中dp init置空标志 */
uint8_t g_wlan_priv_dbdc_radio_cap = 1; /* 默认支持dbdc */

#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
oal_bool_enum_uint8 g_tas_switch_en[HAL_HOST_MAX_RF_NUM] = {0};
#endif

/*
 *  regdomain <-> country code map table
 *  max support country num: MAX_COUNTRY_COUNT
 */
OAL_STATIC countryinfo_stru g_country_info_table[] = {
    /* Note:too few initializers for unsigned char [3] */

    { REGDOMAIN_COMMON, { '0', '0' }},  // WORLD DOMAIN
    { REGDOMAIN_FCC,    { 'A', 'A' }},  // Specific country code for pad
    { REGDOMAIN_FCC, { 'A', 'D' }},     // ANDORRA
    { REGDOMAIN_ETSI, { 'A', 'E' }},    // UAE
    { REGDOMAIN_ETSI, { 'A', 'F' }},    // AFGHANISTAN
    { REGDOMAIN_ETSI, { 'A', 'G' }},    // ANTIGUA AND BARBUDA
    { REGDOMAIN_ETSI, { 'A', 'I' }},    // ANGUILLA
    { REGDOMAIN_ETSI, { 'A', 'L' }},    // ALBANIA
    { REGDOMAIN_ETSI, { 'A', 'M' }},    // ARMENIA
    { REGDOMAIN_ETSI, { 'A', 'N' }},    // NETHERLANDS ANTILLES
    { REGDOMAIN_ETSI, { 'A', 'O' }},    // ANGOLA
    { REGDOMAIN_FCC, { 'A', 'R' }},     // ARGENTINA
    { REGDOMAIN_FCC, { 'A', 'S' }},     // AMERICAN SOMOA
    { REGDOMAIN_ETSI, { 'A', 'T' }},    // AUSTRIA
    { REGDOMAIN_ETSI, { 'A', 'U' }},    // AUSTRALIA
    { REGDOMAIN_ETSI, { 'A', 'W' }},    // ARUBA
    { REGDOMAIN_ETSI, { 'A', 'Z' }},    // AZERBAIJAN
    { REGDOMAIN_ETSI, { 'B', 'A' }},    // BOSNIA AND HERZEGOVINA
    { REGDOMAIN_FCC, { 'B', 'B' }},     // BARBADOS
    { REGDOMAIN_ETSI, { 'B', 'D' }},    // BANGLADESH
    { REGDOMAIN_ETSI, { 'B', 'E' }},    // BELGIUM
    { REGDOMAIN_ETSI, { 'B', 'G' }},    // BULGARIA
    { REGDOMAIN_ETSI, { 'B', 'H' }},    // BAHRAIN
    { REGDOMAIN_ETSI, { 'B', 'L' }},    //
    { REGDOMAIN_FCC, { 'B', 'M' }},     // BERMUDA
    { REGDOMAIN_ETSI, { 'B', 'N' }},    // BRUNEI DARUSSALAM
    { REGDOMAIN_FCC, { 'B', 'O' }},     // BOLIVIA
    { REGDOMAIN_FCC, { 'B', 'R' }},     // BRAZIL
    { REGDOMAIN_FCC, { 'B', 'S' }},     // BAHAMAS
    { REGDOMAIN_ETSI, { 'B', 'Y' }},    // BELARUS
    { REGDOMAIN_ETSI, { 'B', 'Z' }},    // BELIZE
    { REGDOMAIN_FCC, { 'C', 'A' }},     // CANADA
    { REGDOMAIN_ETSI, { 'C', 'H' }},    // SWITZERLAND
    { REGDOMAIN_FCC, { 'C', 'L' }},     // CHILE
    { REGDOMAIN_CN,  { 'C', 'N' }},  // CHINA
    { REGDOMAIN_FCC, { 'C', 'O' }},     // COLOMBIA
    { REGDOMAIN_FCC, { 'C', 'R' }},     // COSTA RICA
    { REGDOMAIN_ETSI, { 'C', 'S' }},
    { REGDOMAIN_ETSI, { 'C', 'U' }},  // CUBA
    { REGDOMAIN_ETSI, { 'C', 'Y' }},  // CYPRUS
    { REGDOMAIN_ETSI, { 'C', 'Z' }},  // CZECH REPUBLIC
    { REGDOMAIN_ETSI, { 'D', 'E' }},  // GERMANY
    { REGDOMAIN_ETSI, { 'D', 'K' }},  // DENMARK
    { REGDOMAIN_FCC, { 'D', 'O' }},   // DOMINICAN REPUBLIC
    { REGDOMAIN_ETSI, { 'D', 'Z' }},  // ALGERIA
    { REGDOMAIN_FCC, { 'E', 'C' }},   // ECUADOR
    { REGDOMAIN_ETSI, { 'E', 'E' }},  // ESTONIA
    { REGDOMAIN_ETSI, { 'E', 'G' }},  // EGYPT
    { REGDOMAIN_ETSI, { 'E', 'S' }},  // SPAIN
    { REGDOMAIN_ETSI, { 'E', 'T' }},  // ETHIOPIA
    { REGDOMAIN_ETSI, { 'F', 'I' }},  // FINLAND
    { REGDOMAIN_ETSI, { 'F', 'R' }},  // FRANCE
    { REGDOMAIN_ETSI, { 'G', 'B' }},  // UNITED KINGDOM
    { REGDOMAIN_FCC, { 'G', 'D' }},   // GRENADA
    { REGDOMAIN_ETSI, { 'G', 'E' }},  // GEORGIA
    { REGDOMAIN_ETSI, { 'G', 'F' }},  // FRENCH GUIANA
    { REGDOMAIN_ETSI, { 'G', 'L' }},  // GREENLAND
    { REGDOMAIN_ETSI, { 'G', 'P' }},  // GUADELOUPE
    { REGDOMAIN_ETSI, { 'G', 'R' }},  // GREECE
    { REGDOMAIN_FCC, { 'G', 'T' }},   // GUATEMALA
    { REGDOMAIN_FCC, { 'G', 'U' }},   // GUAM
    { REGDOMAIN_ETSI, { 'H', 'K' }},  // HONGKONG
    { REGDOMAIN_FCC, { 'H', 'N' }},   // HONDURAS
    { REGDOMAIN_ETSI, { 'H', 'R' }},  // Croatia
    { REGDOMAIN_ETSI, { 'H', 'U' }},  // HUNGARY
    { REGDOMAIN_ETSI, { 'I', 'D' }},  // INDONESIA
    { REGDOMAIN_ETSI, { 'I', 'E' }},  // IRELAND
    { REGDOMAIN_ETSI, { 'I', 'L' }},  // ISRAEL
    { REGDOMAIN_ETSI, { 'I', 'N' }},  // INDIA
    { REGDOMAIN_ETSI, { 'I', 'Q' }},  // IRAQ
    { REGDOMAIN_ETSI, { 'I', 'R' }},  // IRAN, ISLAMIC REPUBLIC OF
    { REGDOMAIN_ETSI, { 'I', 'S' }},  // ICELNAD
    { REGDOMAIN_ETSI, { 'I', 'T' }},  // ITALY
    { REGDOMAIN_FCC, { 'J', 'M' }},   // JAMAICA
    { REGDOMAIN_ETSI, { 'J', 'P' }},  // JAPAN /*  */
    { REGDOMAIN_ETSI, { 'J', 'O' }},  // JORDAN
    { REGDOMAIN_ETSI, { 'K', 'E' }},  // KENYA
    { REGDOMAIN_ETSI, { 'K', 'H' }},  // CAMBODIA
    { REGDOMAIN_ETSI, { 'K', 'P' }},  // KOREA, DEMOCRATIC PEOPLE's REPUBLIC OF
    { REGDOMAIN_ETSI, { 'K', 'R' }},  // KOREA, REPUBLIC OF
    { REGDOMAIN_ETSI, { 'K', 'W' }},  // KUWAIT
    { REGDOMAIN_ETSI, { 'K', 'Y' }},  // Cayman Is
    { REGDOMAIN_ETSI, { 'K', 'Z' }},  // KAZAKHSTAN
    { REGDOMAIN_ETSI, { 'L', 'B' }},  // LEBANON
    { REGDOMAIN_ETSI, { 'L', 'I' }},  // LIECHTENSTEIN
    { REGDOMAIN_ETSI, { 'L', 'K' }},  // SRI-LANKA
    { REGDOMAIN_ETSI, { 'L', 'S' }},  // KINGDOM OF LESOTH
    { REGDOMAIN_ETSI, { 'L', 'T' }},  // LITHUANIA
    { REGDOMAIN_ETSI, { 'L', 'U' }},  // LUXEMBOURG
    { REGDOMAIN_ETSI, { 'L', 'V' }},  // LATVIA
    { REGDOMAIN_ETSI, { 'M', 'A' }},  // MOROCCO
    { REGDOMAIN_ETSI, { 'M', 'C' }},  // MONACO
    { REGDOMAIN_ETSI, { 'M', 'D' }},  // REPUBLIC OF MOLDOVA
    { REGDOMAIN_ETSI, { 'M', 'E' }},  // Montenegro
    { REGDOMAIN_FCC, { 'M', 'H' }},   // Marshall Is
    { REGDOMAIN_ETSI, { 'M', 'K' }},  // MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF
    { REGDOMAIN_ETSI, { 'M', 'M' }},  // MYANMAR
    { REGDOMAIN_FCC, { 'M', 'N' }},   // MONGOLIA
    { REGDOMAIN_ETSI, { 'M', 'O' }},  // MACAO
    { REGDOMAIN_FCC, { 'M', 'P' }},   // NORTHERN MARIANA ISLANDS
    { REGDOMAIN_ETSI, { 'M', 'Q' }},  // MARTINIQUE
    { REGDOMAIN_ETSI, { 'M', 'R' }},  // Mauritania
    { REGDOMAIN_ETSI, { 'M', 'T' }},  // MALTA
    { REGDOMAIN_ETSI, { 'M', 'V' }},  // Maldives
    { REGDOMAIN_ETSI, { 'M', 'U' }},  // MAURITIUS
    { REGDOMAIN_ETSI, { 'M', 'W' }},  // MALAWI
    { REGDOMAIN_ETSI, { 'M', 'X' }},  // MEXICO
    { REGDOMAIN_ETSI, { 'M', 'Y' }},  // MALAYSIA
    { REGDOMAIN_ETSI, { 'N', 'G' }},  // NIGERIA
    { REGDOMAIN_FCC, { 'N', 'I' }},   // NICARAGUA
    { REGDOMAIN_ETSI, { 'N', 'L' }},  // NETHERLANDS
    { REGDOMAIN_ETSI, { 'N', 'O' }},  // NORWAY
    { REGDOMAIN_ETSI, { 'N', 'P' }},  // NEPAL
    { REGDOMAIN_ETSI, { 'N', 'Z' }},  // NEW-ZEALAND
    { REGDOMAIN_ETSI, { 'O', 'M' }},  // OMAN
    { REGDOMAIN_FCC, { 'P', 'A' }},   // PANAMA
    { REGDOMAIN_FCC, { 'P', 'E' }},   // PERU
    { REGDOMAIN_ETSI, { 'P', 'F' }},  // FRENCH POLYNESIA
    { REGDOMAIN_ETSI, { 'P', 'G' }},  // PAPUA NEW GUINEA
    { REGDOMAIN_ETSI, { 'P', 'H' }},  // PHILIPPINES
    { REGDOMAIN_ETSI, { 'P', 'K' }},  // PAKISTAN
    { REGDOMAIN_ETSI, { 'P', 'L' }},  // POLAND
    { REGDOMAIN_FCC, { 'P', 'R' }},   // PUERTO RICO
    { REGDOMAIN_FCC, { 'P', 'S' }},   // PALESTINIAN TERRITORY, OCCUPIED
    { REGDOMAIN_ETSI, { 'P', 'T' }},  // PORTUGAL
    { REGDOMAIN_FCC, { 'P', 'Y' }},   // PARAGUAY
    { REGDOMAIN_ETSI, { 'Q', 'A' }},  // QATAR
    { REGDOMAIN_ETSI, { 'R', 'E' }},  // REUNION
    { REGDOMAIN_ETSI, { 'R', 'O' }},  // ROMAINIA
    { REGDOMAIN_ETSI, { 'R', 'S' }},  // SERBIA
    { REGDOMAIN_ETSI, { 'R', 'U' }},  // RUSSIA
    { REGDOMAIN_FCC,  { 'R', 'W' }},   // RWANDA
    { REGDOMAIN_ETSI, { 'S', 'A' }},  // SAUDI ARABIA
    { REGDOMAIN_ETSI, { 'S', 'D' }},  // SUDAN ,REPUBLIC OF THE
    { REGDOMAIN_ETSI, { 'S', 'E' }},  // SWEDEN
    { REGDOMAIN_ETSI, { 'S', 'G' }},  // SINGAPORE
    { REGDOMAIN_ETSI, { 'S', 'I' }},  // SLOVENNIA
    { REGDOMAIN_ETSI, { 'S', 'K' }},  // SLOVAKIA
    { REGDOMAIN_ETSI, { 'S', 'N' }},  // SENEGAL
    { REGDOMAIN_COMMON, { 'S', 'W' }},  // CHINA 室外车载
    { REGDOMAIN_ETSI, { 'S', 'V' }},  // EL SALVADOR
    { REGDOMAIN_ETSI, { 'S', 'Y' }},  // SYRIAN ARAB REPUBLIC
    { REGDOMAIN_ETSI, { 'T', 'H' }},  // THAILAND
    { REGDOMAIN_ETSI, { 'T', 'J' }},  // TAJIKISTAN
    { REGDOMAIN_ETSI, { 'T', 'M' }},  // TURKMENISTAN
    { REGDOMAIN_ETSI, { 'T', 'N' }},  // TUNISIA
    { REGDOMAIN_ETSI, { 'T', 'R' }},  // TURKEY
    { REGDOMAIN_ETSI, { 'T', 'T' }},  // TRINIDAD AND TOBAGO
    { REGDOMAIN_FCC, { 'T', 'W' }},   // TAIWAN, PRIVINCE OF CHINA
    { REGDOMAIN_FCC, { 'T', 'Z' }},   // TANZANIA, UNITED REPUBLIC OF
    { REGDOMAIN_ETSI, { 'U', 'A' }},  // UKRAINE
    { REGDOMAIN_ETSI, { 'U', 'G' }},  // UGANDA
    { REGDOMAIN_FCC, { 'U', 'S' }},   // USA
    { REGDOMAIN_FCC, { 'U', 'Y' }},   // URUGUAY
    { REGDOMAIN_ETSI, { 'U', 'Z' }},  // UZBEKISTAN
    { REGDOMAIN_FCC, { 'V', 'E' }},   // VENEZUELA
    { REGDOMAIN_FCC, { 'V', 'I' }},   // VIRGIN ISLANDS, US
    { REGDOMAIN_ETSI, { 'V', 'N' }},  // VIETNAM
    { REGDOMAIN_ETSI, { 'Y', 'E' }},  // YEMEN
    { REGDOMAIN_ETSI, { 'Y', 'T' }},  // MAYOTTE
    { REGDOMAIN_ETSI, { 'Z', 'A' }},  // SOUTH AFRICA
    { REGDOMAIN_ETSI, { 'Z', 'M' }},  // Zambia
    { REGDOMAIN_ETSI, { 'Z', 'W' }},  // ZIMBABWE
    { REGDOMAIN_FCC,  { 'Z', 'Z' }},  // country code without mobile

    { REGDOMAIN_COUNT, { '9', '9' }}

};

/* 产品host共用定制化结构体 */
wlan_customize_stru g_wlan_cust = {
    .ampdu_tx_max_num = 64, /* 64 addba_buffer_size */
    .uc_roam_switch = 1,                    /* roam switch */
    .uc_roam_scan_orthogonal = CUS_ROAM_SCAN_ORTHOGONAL_DEFAULT,  /* roam scan org */
    .c_roam_trigger_b = -70,                /* roam trigger 2G */
    .c_roam_trigger_a = -70,                /* roam trigger 5G */
    .c_roam_delta_b = 10,                   /* roam delta 2G */
    .c_roam_delta_a = 10,                   /* roam delta 5G */
    .uc_random_mac_addr_scan = 0,           /* random mac addr scan */
    .uc_disable_capab_2ght40 = 0,           /* disable_capab_2ght40 */
    .lte_gpio_check_switch = 0, /* lte_gpio_check_switch */
    .ism_priority = 0, /* ism_priority */
    .lte_rx = 0, /* lte_rx */
    .lte_tx = 0, /* lte_tx */
    .lte_inact = 0, /* lte_inact */
    .ism_rx_act = 0, /* ism_rx_act */
    .bant_pri = 0, /* bant_pri */
    .bant_status = 0, /* bant_status */
    .want_pri = 0, /* want_pri */
    .want_status = 0, /* want_status */
    .uc_scenario_enable = 1,
    .c_dense_env_roam_trigger_a = -70,
    .c_dense_env_roam_trigger_b = -72,
    .c_candidate_good_rssi = -60,
    .uc_candidate_good_num = 5,
    .uc_candidate_weak_num = 10,
    .us_roam_interval = 0x8003,
};
/*  host侧使用定制化参数分成两部分: g_wlan_cust(与mp13 mp15共结构体), g_cust_host */
cust_host_cfg_stru g_cust_host = {
    .wlan_ps_mode = WLAN_PS_MODE,
    .freq_lock = {
        .throughput_irq_high = WLAN_IRQ_TH_HIGH,
        .dma_latency_val = OAL_FALSE,
        .lock_cpu_th_high = 0,
        .lock_cpu_th_low = 0,
        .en_irq_affinity = OAL_FALSE,
        .throughput_irq_low = WLAN_IRQ_TH_LOW,
        .irq_pps_high = WLAN_IRQ_PPS_TH_HIGH,
        .irq_pps_low = WLAN_IRQ_PPS_TH_LOW,
    },
    .tcp_ack_buf = {
        .host_buf_en = OAL_TRUE,
        .throughput_high = WLAN_TCP_ACK_BUF_HIGH,
        .throughput_low = WLAN_TCP_ACK_BUF_LOW,
        .throughput_high_40m = WLAN_TCP_ACK_BUF_HIGH_40M,
        .throughput_low_40m = WLAN_TCP_ACK_BUF_LOW_40M,
        .throughput_high_80m = WLAN_TCP_ACK_BUF_HIGH_80M,
        .throughput_low_80m = WLAN_TCP_ACK_BUF_LOW_80M,
        .throughput_high_160m = WLAN_TCP_ACK_BUF_HIGH_160M,
        .throughput_low_160m = WLAN_TCP_ACK_BUF_LOW_160M,
        .buf_userctl_test_en = OAL_FALSE,
        .buf_userctl_high = WLAN_TCP_ACK_BUF_USERCTL_HIGH,
        .buf_userctl_low = WLAN_TCP_ACK_BUF_USERCTL_LOW,
    },
    .dyn_extlna = {
        .switch_en = OAL_FALSE,
        .throughput_high = WLAN_RX_DYN_BYPASS_EXTLNA_HIGH,
        .throughput_low = WLAN_RX_DYN_BYPASS_EXTLNA_LOW,
    },
    .tx_ampdu = {
        .ampdu_hw_en = OAL_FALSE,
        .throughput_high = WLAN_HW_AMPDU_TH_HIGH,
        .throughput_low = WLAN_HW_AMPDU_TH_LOW,
    },
    .tcp_ack_filt = {
        .filter_en = OAL_FALSE,
        .throughput_high = WLAN_TCP_ACK_FILTER_TH_HIGH,
        .throughput_low = WLAN_TCP_ACK_FILTER_TH_LOW,
    },
    .host_rx_ampdu_amsdu = OAL_FALSE,
    .rx_buffer_size = OAL_FALSE,
    .en_hmac_feature_switch = {0, 0, 1},
    .roam_switch = WLAN_ROAM_SWITCH_MODE,
    .wlan_11ac2g_switch = OAL_TRUE,
    .wlan_probe_resp_mode = 0x10,
    .small_amsdu = {
        .throughput_high = WLAN_SMALL_AMSDU_HIGH,
        .throughput_low = WLAN_SMALL_AMSDU_LOW,
        .pps_low = WLAN_SMALL_AMSDU_PPS_LOW,
        .pps_high = WLAN_SMALL_AMSDU_PPS_HIGH,
    },
    /* 2G 40MHz降功率中心信道BITMAP
     * bit_x=1，表示对应信道不支持作为40MHz带宽中心信道.
     * 0xC00表示不支持10和11信道作为40MHz带宽中心信道.
     */
    .reduce_pwr_2g_40mhz_channel_bitmap = 0,
};

/* 特性功能开关和能力定制化参数 */
mac_cust_feature_cap_stru g_cust_cap = {
    .fast_ps = {WLAN_MIN_FAST_PS_IDLE, WLAN_MIN_FAST_PS_IDLE, WLAN_AUTO_FAST_PS_SCREENON, WLAN_AUTO_FAST_PS_SCREENOFF},
    .wlan_device_pm_switch = OAL_TRUE,
    .radio_cap = {WLAN_INIT_DEVICE_RADIO_CAP, WLAN_INIT_DEVICE_RADIO_CAP},
    .autocali_switch = OAL_FALSE,
    .en_channel_width = WLAN_HAL0_BW_MAX_WIDTH,
    .en_ldpc_is_supp = WLAN_HAL0_LDPC_IS_EN,
    .dev_frequency = {
        {PPS_VALUE_0, FREQ_IDLE, {0}},
        {PPS_VALUE_1, FREQ_MIDIUM, {0}},
        {PPS_VALUE_2, FREQ_HIGHER, {0}},
        {PPS_VALUE_3, FREQ_HIGHEST, {0}}},
    .used_mem_for_start = WLAN_MEM_FOR_START,
    .used_mem_for_stop = WLAN_MEM_FOR_STOP,
    .sdio_assem_h2d = WLAN_SDIO_H2D_ASSEMBLE_COUNT_VAL,
    .sdio_assem_d2h = WLAN_SDIO_D2H_ASSEMBLE_COUNT_VAL,
    .linkloss_th = {WLAN_LOSS_THRESHOLD_WLAN_BT, WLAN_LOSS_THRESHOLD_WLAN_DBAC, WLAN_LOSS_THRESHOLD_WLAN_NORMAL},
    .mbo_switch = 0,
    .dbac_dynamic_switch = 1,
    .hiex_cap = (uint8_t)WLAN_HIEX_DEV_CAP,
    .fast_mode = 0,
    .btcoex_threshold_mcm = {WLAN_BTCOEX_THRESHOLD_MCM_DOWN, WLAN_BTCOEX_THRESHOLD_MCM_UP},
    .ftm_cap = OAL_FALSE,
    .ftm_board_delay = OAL_FALSE,
    .trx_switch = WLAN_DEFAULT_TRX_SWITCH,
    .hcc_flowctrl_type = 0,
    .hcc_flowctrl_switch = OAL_FALSE,
    .aput_160m_switch = OAL_FALSE,
    .en_rx_stbc_is_supp = WLAN_HAL0_RX_STBC_IS_EN,
    .en_tx_stbc_is_supp = WLAN_HAL0_TX_STBC_IS_EN,
    .en_su_bfmer_is_supp = WLAN_HAL0_SU_BFER_IS_EN,
    .en_su_bfmee_is_supp = WLAN_HAL0_SU_BFEE_IS_EN,
    .en_mu_bfmer_is_supp = WLAN_HAL0_MU_BFER_IS_EN,
    .en_mu_bfmee_is_supp = WLAN_HAL0_MU_BFEE_IS_EN,
    .optimized_feature_mask = 0,
    .en_1024qam_is_supp = WLAN_HAL0_1024QAM_IS_EN,
    .hisi_priv_cap = 0, /* 私有IE能力，mp15通过该默认值获取，mp16 会通过INI文件读取 */
    .txopps_switch = WLAN_HAL0_TXOPPS_IS_EN,
    .gle_ant_use = 0,                                 /* 默认值写0 */
    .nrcoex_params.nrcoex_switch = OAL_FALSE,         /* 默认nrcoex方案关闭 */
    .nrcoex_params.version_num = 1,                   /* 默认采用第1版方案 */
    .nrcoex_params.nrcoex_hw = OAL_FALSE,             /* 默认关闭硬解功能 */
    .nrcoex_params.advance_low_power = OAL_FALSE,     /* 默认不提前降功率 */
    .loglevel = OAM_LOG_DEFAULT_LEVEL, /* 默认日志级别WARNING */
    /* BIT7:CHA3_5G BIT6:CHA2_5G BIT5:CHA1_5G BIT4:CHA0_5G BIT3:CHA3_2G BIT2:CHA2_2G BIT1:CHA1_2G BIT0:CHA0_2G */
    .chn_radio_cap = 0xFF, /* 默认值 0xFF */
    .uwbcoex_switch = OAL_FALSE,  /* 默认uwbcoex方案关闭 */
    .cali_data_h_phy_addr = 0,
    .alg_switch_ini = 1,         /* bit[1-0] | private VHT Q  | Spatial Reuse */
    /* bit[7-4]  WFA Test  |      CFR    | Lower DAC/ADC FS | Rxcointf Immu
       bit[3-0]FOC sw calc | Interleaved ADC | Power Saving | Power Gating */
    .phy_cap_mask = 0xBE,
    /* bit[3-0] UL OFDMA:ac suspend VO/VI/BK/BE bit[7-4] HIEX TX OPT:priv ac VO/VI/BK/BE */
    .ac_suspend_mask = 0x8F,
    .frame_tx_chain_ctl = -55,
    .htc_switch_mask = 7,
    .rssi_switch_ant = 3,
    .wlan_device_lp_agent_switch = OAL_FALSE,
    .chba_dbac_chan_follow_switch = OAL_TRUE, /* chba dbac信道跟随, 默认支持 */
    .expand_feature_switch_bitmap = 0,
    .fem_pow_3a.tpc_adj_pow_start_idx_3a[0] = 0xFF, /* 2G fem_3a start index默认值 */
    .fem_pow_3a.tpc_adj_pow_start_idx_3a[1] = 0xFF, /* 5G fem_3a start index默认值 */
    .dyn_bypass_extlna_rssi_th_h = { {-45, -45, -35, -35}, {-45, -45, -35, -35}, },
    .dyn_bypass_extlna_rssi_th_l = { {-48, -48, -38, -38}, {-48, -48, -38, -38}, },
};

char *hwifi_get_country_code(void)
{
    int32_t l_ret;
    if (g_wifi_country_code[0] != '0' && g_wifi_country_code[1] != '0') {
        return g_wifi_country_code;
    }

    /* 获取cust国家码 */
    l_ret = get_cust_conf_string(INI_MODU_WIFI, STR_COUNTRY_CODE, g_wifi_country_code, sizeof(g_wifi_country_code));
    if (l_ret == INI_FAILED) {
        oam_warning_log0(0, OAM_SF_ANY, "hwifi_get_country_code read country code failed, check if it exists!");
        if (strncpy_s(g_wifi_country_code, COUNTRY_CODE_LEN, "99", sizeof("99") - 1) != EOK) { /* 长度去掉结束符 */
            return g_wifi_country_code;
        }
    } else {
        /*  定制化文件读取国家码成功，判断是否为99 */
        if (!OAL_MEMCMP(g_wifi_country_code, "99", sizeof("99") - 1)) { /* 长度去掉结束符 */
            oam_warning_log0(0, OAM_SF_ANY, "hwifi_get_country_code is set 99!");
            g_cust_country_code_ignore_flag.en_country_code_ingore_ini_flag = OAL_TRUE;
        }
    }
    g_wifi_country_code[COUNTRY_CODE_LEN - 1] = '\0'; /* 以'\0'结尾 */

    return g_wifi_country_code;
}

void hwifi_set_country_code(const char *country_code, const uint32_t len)
{
    int32_t l_ret;

    if (country_code == NULL || len != COUNTRY_CODE_LEN) {
        oam_error_log0(0, OAM_SF_ANY, "hwifi_get_country_code ptr null or illegal len!");
        return;
    }

    l_ret = memcpy_s(g_wifi_country_code, COUNTRY_CODE_LEN, country_code, COUNTRY_CODE_LEN);
    if (l_ret != EOK) {
        return;
    }

    g_wifi_country_code[COUNTRY_CODE_LEN - 1] = '\0'; /* 以'\0'结尾 */
}

/*
 * 函 数 名  : hwifi_get_regdomain_from_country_code
 * 功能描述  : 根据国家码找到对应的regdomain
 */
regdomain_enum_uint8 hwifi_get_regdomain_from_country_code(const countrycode_t country_code)
{
    regdomain_enum_uint8 en_regdomain = REGDOMAIN_COMMON;
    int32_t table_idx = 0;

    while (g_country_info_table[table_idx].en_regdomain != REGDOMAIN_COUNT) {
        if (oal_memcmp(country_code, g_country_info_table[table_idx].auc_country_code, COUNTRY_CODE_LEN) == 0) {
            en_regdomain = g_country_info_table[table_idx].en_regdomain;
            break;
        }
        ++table_idx;
    }

    return en_regdomain;
}

/*
 * 函 数 名  : hwifi_is_regdomain_changed
 * 功能描述  : 国家码改变后，对应的regdomain是否有变化
 */
int32_t hwifi_is_regdomain_changed(const countrycode_t country_code_old, const countrycode_t country_code_new)
{
    return hwifi_get_regdomain_from_country_code(country_code_old) !=
           hwifi_get_regdomain_from_country_code(country_code_new);
}

/*
 * 函 数 名  : hwifi_config_init_ini_Hisilicon_country
 * 功能描述  : 国家码定制化
 * 1.日    期  : 2015年10月22日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hwifi_config_init_ini_country(oal_net_device_stru *pst_cfg_net_dev)
{
    int32_t l_ret;
    l_ret = (int32_t)wal_hipriv_setcountry(pst_cfg_net_dev, hwifi_get_country_code());
    if (oal_unlikely(l_ret != OAL_SUCC)) {
        oam_error_log1(0, OAM_SF_ANY, "{hwifi_config_init_ini_country::send_cfg_event return err code [%d]!}", l_ret);
    }

    /* 开关wifi定制化配置国家码 */
    g_cust_country_code_ignore_flag.en_country_code_ingore_hipriv_flag = OAL_FALSE;
}

#ifdef _PRE_WLAN_COUNTRYCODE_SELFSTUDY

/* 枚举定义 */
typedef enum {
    CUS_PARAM_COUNTRYCODE_SELFSTUDY_OPEN0 = BIT0,
    CUS_PARAM_COUNTRYCODE_SELFSTUDY_OPEN1 = BIT1,
    CUS_PARAM_COUNTRYCODE_SELFSTUDY_MODE_BUTT,
} hwifi_country_code_mode_enum;

/*
 * 函 数 名  : hwifi_config_selfstudy_init_country
 * 功能描述  : 国家码定制化
 * 1.日    期  : 2019年12月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
void hwifi_config_selfstudy_init_country(oal_net_device_stru *pst_cfg_net_dev)
{
    uint8_t default_country_code[] = "99";
    uint8_t uc_val;

    uc_val = wlan_chip_get_selfstudy_country_flag();
    if ((uc_val & CUS_PARAM_COUNTRYCODE_SELFSTUDY_OPEN0) &&
        (!OAL_MEMCMP(hwifi_get_country_code(), default_country_code, sizeof(default_country_code) - 1))) {
        g_cust_country_code_ignore_flag.en_country_code_study_ingore_hipriv_flag = OAL_FALSE;
    } else {
        g_cust_country_code_ignore_flag.en_country_code_study_ingore_hipriv_flag = OAL_TRUE;
    }
    oam_warning_log1(0, OAM_SF_ANY, "{hwifi_config_selfstudy_init_country::custom_value [%d]!}", uc_val);
}
#endif

uint8_t g_wlan_open_cnt = 0;
oal_bool_enum_uint8 g_wlan_cal_intvl_enable = OAL_TRUE; /* 使能开wifi重复校准的间隔 */
oal_bool_enum_uint8 g_wlan_cal_disable_switch = OAL_FALSE; /* 禁能wifi自校准 */
uint8_t hwifi_custom_cali_ini_param(uint8_t uc_priv_cfg_value)
{
    uint8_t uc_cali_interval;

    /* 开机默认打开校准数据上传下发 */
    g_wlan_open_cnt++;
    if (g_custom_cali_done == OAL_FALSE) {
        uc_priv_cfg_value |= (CALI_DATA_REFRESH_MASK | CALI_DATA_REUPLOAD_MASK);
    } else if (g_wlan_cal_disable_switch == OAL_TRUE) {
        uc_priv_cfg_value &= (~CALI_DATA_REFRESH_MASK);
    } else {
        if (g_wlan_cal_intvl_enable && (uc_priv_cfg_value & CALI_DATA_REFRESH_MASK)) {
            uc_cali_interval = (uc_priv_cfg_value >> CALI_INTVL_OFFSET) + 1;
            if (g_wlan_open_cnt % uc_cali_interval) {
                uc_priv_cfg_value &= (~CALI_DATA_REFRESH_MASK);
            }
        }
    }

    return uc_priv_cfg_value;
}

/*
 * 函 数 名  : hwifi_hcc_custom_netbuf_alloc
 * 功能描述  : 下发定制化配置命令pst_netbuf内存申请
 */
oal_netbuf_stru* hwifi_hcc_custom_netbuf_alloc(void)
{
    oal_netbuf_stru *netbuf = NULL;
    uint8_t count;
    // count计数内存申请次数，最多申请3次
    for (count = 1; count <= 3; count++) {
        netbuf = oal_mem_netbuf_alloc(OAL_NORMAL_NETBUF, WLAN_LARGE_NETBUF_SIZE, OAL_NETBUF_PRIORITY_HIGH);
        if (netbuf != NULL) {
            return netbuf;
        }
        oal_msleep(30);    // 内存申请失败 延时30ms
    }
    oam_error_log0(0, OAM_SF_CFG, "hwifi_hcc_custom_netbuf_alloc::alloc netbuf 3 times fail.");
    return NULL;
}
