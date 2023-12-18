/*
 * ��Ȩ���� (c) ��Ϊ�������޹�˾ 2001-2011
 * ����˵�� : linux cfgid ���õ�������
 * ��    �� : zhangheng
 * �������� : 2012��11��6��
 */

#ifdef _PRE_WLAN_CFGID_DEBUG

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "oal_types.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "wlan_types.h"

#include "mac_device.h"
#include "mac_vap.h"
#include "mac_resource.h"

#include "hmac_custom_security.h"
#include "hmac_resource.h"
#include "hmac_device.h"
#include "hmac_scan.h"
#include "hmac_ext_if.h"
#include "hmac_config.h"
#include "hmac_204080_coexist.h"
#include "hmac_ftm.h"
#include "wal_ext_if.h"
#include "wal_main.h"
#include "wal_config.h"
#include "wal_linux_bridge.h"
#if defined(_PRE_PRODUCT_ID_HI110X_HOST)

#include "hmac_cali_mgmt.h"
#endif
#ifdef _PRE_WLAN_FEATURE_WAPI
#include "hmac_wapi.h"
#endif

#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "plat_pm_wlan.h"
#endif
#ifdef _PRE_WLAN_FEATURE_WMMAC
#include "hmac_wmmac.h"
#endif
#include "hmac_rx_data.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_WAL_CONFIG_DEBUG_C

/*****************************************************************************
  2 �ṹ�嶨��
*****************************************************************************/
/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/
/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/
/*
 * �� �� ��  : wal_config_get_hipkt_stat
 * ��������  : ��ȡ�����ȼ����ĵ�ͳ�����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��12��2��
 *   ��    ��  : xiechunhui
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_get_hipkt_stat(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_get_hipkt_stat(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_flowctl_param
 * ��������  : ����flowctl��ز���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��08��25��
 *   ��    ��  : xiechunhui
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_flowctl_param(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_set_flowctl_param(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_get_flowctl_stat
 * ��������  : ����flowctl��ز���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��08��25��
 *   ��    ��  : xiechunhui
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_get_flowctl_stat(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_get_flowctl_stat(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_get_fem_pa_status
 * ��������  : ��ȡ�汾
 * �޸���ʷ  :
 * 1.��    ��  : 2015��7��20��
 *   ��    ��  : z00285102
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_get_fem_pa_status(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_get_fem_pa_status(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_event_switch
 * ��������  : ����OAM eventģ����ܿ���
 * �޸���ʷ  :
 * 1.��    ��  : 2013��12��5��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_event_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_event_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_eth_switch
 * ��������  : ������̫���շ�����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��5��24��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_eth_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_eth_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_80211_ucast_switch
 * ��������  : ����80211����֡�ϱ�����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��5��24��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_80211_ucast_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_80211_ucast_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_2040_coext_switch
 * ��������  : ����APUT 20/40�����л�����
 * �޸���ʷ  :
 * 1.��    ��  : 2019��1��17��
 *   ��    ��  : x00456388
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_2040_coext_switch(mac_vap_stru *pst_mac_vap,
                                                       oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_2040_coext_switch(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_DEBUG_MODE_USER_TRACK
/*
 * �� �� ��  : wal_config_report_thrput_stat
 * ��������  : �ϱ�Ӱ���û�ʵʱ���µ�ͳ����Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��8��19��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_report_thrput_stat(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_report_thrput_stat(pst_mac_vap, us_len, puc_param);
}

#endif

#ifdef _PRE_WLAN_FEATURE_TXOPPS

/*
 * �� �� ��  : wal_config_set_txop_ps_machw
 * ��������  : ����mac txop psʹ�ܼĴ���
 * �޸���ʷ  :
 * 1.��    ��  : 2014��7��16��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_txop_ps_machw(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_set_txop_ps_machw(pst_mac_vap, us_len, puc_param);
}

#endif

/*
 * �� �� ��  : wal_config_80211_mcast_switch
 * ��������  : ����80211�鲥\�㲥֡�ϱ�����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��5��24��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_80211_mcast_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_80211_mcast_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_probe_switch
 * ��������  : ����probe request��probe response�ϱ��Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2014��5��30��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_probe_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_probe_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_rssi_switch
 * ��������  : ���ô�ӡ���ձ�����rssi��Ϣ�Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��3��7��
 *   ��    ��  : l00279018
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_phy_debug_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_phy_debug_switch(pst_mac_vap, us_len, puc_param);
}
OAL_STATIC oal_uint32 wal_config_opmode_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                               oal_uint8 *puc_param)
{
    return hmac_config_opmode_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_ota_beacon_switch
 * ��������  : �����Ƿ��ϱ�beacon֡�Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2014��1��7��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_ota_beacon_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_ota_beacon_switch(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_ota_rx_dscr_switch
 * ��������  : �����Ƿ��ϱ�beacon֡�Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��3��19��
 *   ��    ��  : z00285102
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_ota_rx_dscr_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_ota_rx_dscr_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_all_ota
 * ��������  : ���������û�֡�ϱ������п��أ������1�����ϱ���������֡��֡���ݣ�
 * �޸���ʷ  :
 * 1.��    ��  : 2015��1��23��
 *   ��    ��  : w00316376
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_all_ota(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_all_ota(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_dhcp_arp_switch
 * ��������  : ���÷��͹㲥dhcp��arp����
 * �޸���ʷ  :
 * 1.��    ��  : 2015��1��29��
 *   ��    ��  : w00316376
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_dhcp_arp_switch(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_dhcp_arp_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_oam_output
 * ��������  : ����oamģ������λ��
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��3��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_oam_output(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_oam_output(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_amsdu_start
 * ��������  : ����AMPDU��������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : t00231215
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_amsdu_start(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_amsdu_start(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_auto_ba_switch
 * ��������  : �����Զ�����BA�Ự�Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��20��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_auto_ba_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_auto_ba_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_auto_ba_switch
 * ��������  : ����amsdu+ampdu���ϾۺϵĿ���
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��20��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_amsdu_ampdu_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_amsdu_ampdu_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_addba_req
 * ��������  : ����BA�Ự����������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_addba_req(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_addba_req(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_delba_req
 * ��������  : ɾ��BA�Ự����������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_delba_req(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_delba_req(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_WLAN_FEATURE_WMMAC
/*
 * �� �� ��  : wal_config_addts_req
 * ��������  : ����ADDTS REQ����������
 * �޸���ʷ  :
 * 1.��    ��  : 2016��9��18��
 *   ��    ��  : l00357925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_addts_req(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_addts_req(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_delts
 * ��������  : ɾ��TS����������
 * �޸���ʷ  :
 * 1.��    ��  : 2016��9��18��
 *   ��    ��  : l00357925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_delts(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_delts(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_wmmac_switch
 * ��������  : ����WMMAC���ص���������
 * �޸���ʷ  :
 * 1.��    ��  : 2016��9��18��
 *   ��    ��  : l00357925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_wmmac_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_wmmac_switch(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_reassoc_req
 * ��������  : ���÷����ع���������������
 * �޸���ʷ  :
 * 1.��    ��  : 2016��9��24��
 *   ��    ��  : l00357925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_reassoc_req(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_reassoc_req(pst_mac_vap);
}

#endif

OAL_STATIC oal_uint32 wal_config_voe_enable(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_voe_enable(pst_mac_vap, us_len, puc_param);
}
#ifdef _PRE_WLAN_FEATURE_11K
OAL_STATIC oal_uint32 wal_config_bcn_table_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_bcn_table_switch(pst_mac_vap, us_len, puc_param);
}

#endif
/*
 * �� �� ��  : wal_config_list_ap
 * ��������  : ��ʾSTAɨ�赽��AP
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_list_ap(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_list_ap(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_list_ap
 * ��������  : ��ʾSTAɨ�赽��AP
 * �޸���ʷ  :
 * 1.��    ��  : 2013��7��22��
 *   ��    ��  : zhangyu
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_list_sta(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_list_sta(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_list_channel
 * ��������  : ��ʾ֧�ֵ��ŵ��б�
 * �޸���ʷ  :
 * 1.��    ��  : 2013��12��27��,������
 *   ��    ��  : y00201072
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_list_channel(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_list_channel(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_start_scan
 * ��������  : ������ʼɨ��
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_start_scan(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_sta_initiate_scan(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_start_join
 * ��������  : ����join
 * �޸���ʷ  :
 * 1.��    ��  : 2013��7��24��
 *   ��    ��  : zhangyu
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_start_join(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    mac_bss_dscr_stru *pst_bss_dscr;
    oal_uint32 ul_bss_idx;

    ul_bss_idx = (oal_uint8)oal_atoi((oal_int8 *)puc_param);

    /* ??bss???,??????bss dscr??? */
    pst_bss_dscr = hmac_scan_find_scanned_bss_dscr_by_index(pst_mac_vap->uc_device_id, ul_bss_idx);
    if (pst_bss_dscr == OAL_PTR_NULL) {
        oam_warning_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{wal_config_start_join::find bss failed by index!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    return hmac_sta_initiate_join(pst_mac_vap, pst_bss_dscr);
}

/*
 * �� �� ��  : wal_config_start_scan
 * ��������  : ������ʼɨ��
 * �޸���ʷ  :
 * 1.��    ��  : 2013��6��7��
 *   ��    ��  : huxiaotong
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_start_deauth(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    hmac_config_send_deauth(pst_mac_vap, pst_mac_vap->auc_bssid);
    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_kick_user
 * ��������  : ȥ����1���û�
 * �޸���ʷ  :
 * 1.��    ��  : 2013��8��27��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_pause_tid(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_pause_tid(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_tcp_ack_buf
 * ��������  : wal������tcp ack�����������
 * �޸���ʷ  :
 * 1.��    ��  : 2018��7��26��
 *   ��    ��  : y84102835
 *   �޸�����  : �����ɺ���
 */
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
OAL_STATIC oal_uint32 wal_config_tcp_ack_buf(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_tcp_ack_buf(pst_mac_vap, us_len, puc_param);
}
#endif

OAL_STATIC oal_uint32 wal_config_set_ps_params(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_ps_params(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_WLAN_FEATURE_BTCOEX
/*
 * �� �� ��  : wal_config_set_btcoex_params
 * ��������  : ���ù���������Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2018��11��2��
 *   ��    ��  : r00356856
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_btcoex_params(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_set_btcoex_params(pst_mac_vap, us_len, puc_param);
}
#endif
/*
 * �� �� ��  : wal_config_set_btcoex_params
 * ��������  : ���ð����Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2018��12��30��
 *   ��    ��  : l00422505
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_bindcpu_params(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_bindcpu(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_napi_weight
 * ��������  : �������napiֵ
 * �޸���ʷ  :
 * 1.��    ��  : 2018��12��30��
 *   ��    ��  : l00422505
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_napi_weight_params(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_napi_weight(pst_mac_vap, us_len, puc_param);
}

OAL_STATIC oal_uint32 wal_config_alg(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_alg(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� �� : wal_config_packet_check
 * �������� : �ض��㲥֡��������
 * �޸���ʷ :
 * 1.�� ��  : 2019��9��17��
 * ��    ��   : b00484323
 * �޸�����     : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_packet_check(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint8 uc_skb_num;
    oal_uint8 uc_skb_idx;
    mac_cfg_packet_check_param_stru *pst_pkt_check_param = OAL_PTR_NULL;
    hmac_device_stru *pst_hmac_device = OAL_PTR_NULL;
    hmac_packet_check_rx_info_stru *pst_pkt_check_rx_info = hmac_get_pkt_check_rx_info_addr();

    pst_hmac_device = hmac_res_get_mac_dev(pst_mac_vap->uc_device_id);
    if (pst_hmac_device == OAL_PTR_NULL) {
        oam_warning_log0(0, OAM_SF_CFG, "{wal_config_packet_check::pst_hmac_device is null}");
        return OAL_FAIL;
    }

    pst_pkt_check_param = (mac_cfg_packet_check_param_stru *)puc_param;
    uc_skb_num = pst_pkt_check_param->uc_packet_num;

    /* �򿪰�У�鿪��,���Ѽ��������� */
    pst_hmac_device->st_packet_check.en_pkt_check_on = OAL_TRUE;
    memset_s(pst_pkt_check_rx_info,
        OAL_SIZEOF(hmac_packet_check_rx_info_stru), 0, OAL_SIZEOF(hmac_packet_check_rx_info_stru));
    pst_pkt_check_rx_info->us_pkt_check_send_num = uc_skb_num;

    for (uc_skb_idx = 0; uc_skb_idx < uc_skb_num; uc_skb_idx++) {
        hmac_config_send_check_data(pst_mac_vap, WLAN_PACKET_CHECK_DATA_TYPE0);
        hmac_config_send_check_data(pst_mac_vap, WLAN_PACKET_CHECK_DATA_TYPE1);
        hmac_config_send_check_data(pst_mac_vap, WLAN_PACKET_CHECK_DATA_TYPE2);
        hmac_config_send_check_data(pst_mac_vap, WLAN_PACKET_CHECK_DATA_TYPE3);
    }

    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_timer_start
 * ��������  : �����жϴ�����Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2013��10��8��
 *   ��    ��  : t00231215
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_timer_start(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint8 uc_timer_switch;

    uc_timer_switch = *(puc_param);

    if (uc_timer_switch == OAL_TRUE) {
        oal_5115timer_init();
    } else {
        oal_5115timer_exit();
    }

    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_show_profiling
 * ��������  : ��ӡprofiling��Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2013��10��8��
 *   ��    ��  : t00231215
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_show_profiling(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_ampdu_tx_on
 * ��������  : ȥ����1���û�
 * �޸���ʷ  :
 * 1.��    ��  : 2013��8��27��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_amsdu_tx_on(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_amsdu_tx_on(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_ampdu_tx_on
 * ��������  : ȥ����1���û�
 * �޸���ʷ  :
 * 1.��    ��  : 2013��8��27��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_ampdu_tx_on(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_ampdu_tx_on(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_ampdu_tx_on
 * ��������  : ȥ����1���û�
 * �޸���ʷ  :
 * 1.��    ��  : 2013��8��27��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_txbf_switch(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    mac_cfg_ampdu_tx_on_param_stru *pst_txbf_on_param = OAL_PTR_NULL;

    if (oal_unlikely((pst_mac_vap == OAL_PTR_NULL) || (puc_param == OAL_PTR_NULL))) {
        oam_error_log2(0, OAM_SF_ANY, "{wal_config_txbf_switch:: pst_mac_vap/puc_param is null ptr %x, %x!}\r\n",
                       (uintptr_t)pst_mac_vap, (uintptr_t)puc_param);
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_txbf_on_param = (mac_cfg_ampdu_tx_on_param_stru *)puc_param;

    if ((pst_txbf_on_param->uc_aggr_tx_on == 1) || (pst_txbf_on_param->uc_aggr_tx_on == 0)) {
    } else {
        OAM_ERROR_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                       "{wal_config_txbf_switch:: pst_ampdu_tx_on_param->uc_aggr_tx_on %d!}",
                       pst_txbf_on_param->uc_aggr_tx_on);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}
/*
 * �� �� ��  : wal_config_set_country
 * ��������  : ���ù�����
 * �޸���ʷ  :
 * 1.��    ��  : 2013��10��18��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_reset_operate(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_reset_operate(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_WLAN_FEATURE_UAPSD
OAL_STATIC oal_uint32 wal_config_uapsd_debug(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_sync_cmd_common(pst_mac_vap, WLAN_CFGID_UAPSD_DEBUG, us_len, puc_param);
}

#endif

#ifdef _PRE_WLAN_DFT_STAT
/*
 * �� �� ��  : wal_config_usr_queue_stat
 * ��������  : �ϱ����������û�����ͳ����Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��8��18��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_usr_queue_stat(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_usr_queue_stat(pst_mac_vap, us_len, puc_param);
}
#endif

/*
 * �� �� ��  : wal_config_dump_rx_dscr
 * ��������  : dump����������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��12��2��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dump_rx_dscr(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_dump_rx_dscr(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_dump_tx_dscr
 * ��������  : dump��������������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��12��2��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dump_tx_dscr(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_dump_tx_dscr(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_dump_memory
 * ��������  : dump��������������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��12��2��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dump_memory(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    mac_cfg_dump_memory_stru *pst_param;
    oal_uint8 *puc_addr;
    oal_uint32 ul_i;

    pst_param = (mac_cfg_dump_memory_stru *)puc_param;
    puc_addr = (oal_uint8 *)(uintptr_t)(pst_param->ul_addr);

    for (ul_i = 0; ul_i < pst_param->ul_len; ul_i++) {
        OAL_IO_PRINT("%02x ", puc_addr[ul_i]);
        if (ul_i && (ul_i % 20 == 0)) { /* ul_i����20 */
            OAL_IO_PRINT("\n");
        }
    }

    OAL_IO_PRINT("\n");

    return OAL_SUCC;
}

#ifdef _PRE_WLAN_FEATURE_11D
/*
 * �� �� ��  : wal_config_set_rd_by_ie_switch
 * ��������  : ��ȡ������
 * �޸���ʷ  :
 * 1.��    ��  : 2015��1��17��
 *   ��    ��  : zhangxiang
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_rd_by_ie_switch(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_rd_by_ie_switch(pst_mac_vap, us_len, puc_param);
}
#endif

/*
 * �� �� ��  : wal_config_vap_pkt_stat
 * ��������  : �ϱ�ĳһ��vap�µ��շ���ͳ����Ϣ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��7��10��
 *   ��    ��  : z00237171
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_vap_pkt_stat(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_vap_pkt_stat(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_log_level
 * ��������  : ������־�����¼�����hmac
 * �޸���ʷ  :
 * 1.��    ��  : 2015��1��21��
 *   ��    ��  : jwx222439
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_feature_log(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                 oal_uint8 *puc_param)
{
    oal_uint32 ul_ret;

    /***************************************************************************
        ���¼���DMAC��, ͬ��DMAC����
    ***************************************************************************/
    ul_ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_SET_FEATURE_LOG, us_len, puc_param);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        OAM_WARNING_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{wal_config_set_feature_log::hmac_config_send_event failed[%d].}", ul_ret);
    }

    return ul_ret;
}

#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
/*
 * �� �� ��  : wal_config_set_log_lowpower
 * ��������  : ������־�͹���ģʽ������buff������־�����ǻ���host
 * �޸���ʷ  :
 * 1.��    ��  : 2015��1��21��
 *   ��    ��  : jwx222439
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_log_lowpower(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    oal_uint32 ul_ret;

    /***************************************************************************
        ���¼���DMAC��, ͬ��DMAC����
    ***************************************************************************/
    ul_ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_SET_LOG_PM, us_len, puc_param);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        OAM_WARNING_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{wal_config_set_feature_log::hmac_config_send_event failed[%d].}", ul_ret);
    }

    return ul_ret;
}
#endif
/*
 * �� �� ��  : wal_config_create_al_tx_packet
 * ��������  : �����һ������
 * �޸���ʷ  :
 * 1.��    ��  : 2013��9��22��
 *   ��    ��  : t00231215
 *   �޸�����  : �����ɺ���
 */
oal_netbuf_stru *wal_config_create_al_tx_packet(oal_uint32 ul_size,
                                                oal_uint8 uc_tid,
                                                mac_rf_payload_enum_uint8 en_payload_flag,
                                                oal_bool_enum_uint8 en_init_flag)
{
    static oal_netbuf_stru *pst_buf = OAL_PTR_NULL;
    oal_uint32 ul_loop = 0;
    oal_uint32 l_reserve = 256;

    if (en_init_flag == OAL_TRUE) {
        pst_buf = oal_netbuf_alloc(ul_size + l_reserve, (oal_int32)l_reserve, 4); /* 4��ʾ4�ֽڶ��� */
        if (oal_unlikely(pst_buf == OAL_PTR_NULL)) {
            OAM_ERROR_LOG0(0, OAM_SF_TX, "wal_config_create_al_tx_packet::alloc Fail");
            return OAL_PTR_NULL;
        }
        oal_netbuf_put(pst_buf, ul_size);
    }

    if (pst_buf == OAL_PTR_NULL) {
        OAM_ERROR_LOG0(0, OAM_SF_TX, "wal_config_create_al_tx_packet::pst_buf is not initiate");
        return OAL_PTR_NULL;
    }

    switch (en_payload_flag) {
        case RF_PAYLOAD_ALL_ZERO:
            memset_s(pst_buf->data, ul_size, 0, ul_size);
            break;
        case RF_PAYLOAD_ALL_ONE:
            memset_s(pst_buf->data, ul_size, 0xFF, ul_size);
            break;
        case RF_PAYLOAD_RAND:
            pst_buf->data[0] = oal_gen_random(18, 1); /* 18��ʾ��������� */
            for (ul_loop = 1; ul_loop < ul_size; ul_loop++) {
                pst_buf->data[ul_loop] = oal_gen_random(18, 0); /* 18��ʾ��������� */
            }
            break;
        default:
            break;
    }

    pst_buf->next = OAL_PTR_NULL;
    pst_buf->prev = OAL_PTR_NULL;

    memset_s(oal_netbuf_cb(pst_buf), oal_netbuf_cb_size(), 0, oal_netbuf_cb_size());
    return pst_buf;
}

#ifdef _PRE_WLAN_NARROW_BAND
/*
 * �� �� ��  : wal_config_narrow_bw
 * ��������  : խ���Ĵ���
 * �޸���ʷ  :
 * 1.��    ��  : 2016��7��25��
 *   ��    ��  : z00260280
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_narrow_bw(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint32 ul_ret;
    mac_cfg_narrow_bw_stru *pst_nb;

    if (oal_unlikely((pst_mac_vap == OAL_PTR_NULL) || (puc_param == OAL_PTR_NULL))) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_config_narrow_bw::pst_mac_vap/puc_param is null ptr!}\r\n");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_nb = (mac_cfg_narrow_bw_stru *)puc_param;

    pst_mac_vap->st_nb = *pst_nb;

    /***************************************************************************
        ���¼���DMAC��, ͬ��DMAC����
    ***************************************************************************/
    ul_ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_NARROW_BW, us_len, puc_param);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        OAM_WARNING_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_CFG, "{wal_config_narrow_bw::send_event failed[%d]}",
                         ul_ret);
    }

    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_set_nbfh
 * ��������  : ����device������Ƶ
 * �޸���ʷ  :
 * 1.��    ��  : 2019��1��19��
 *   ��    ��  : l00423930
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_nbfh(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint32 ul_ret;

    if (oal_unlikely((pst_mac_vap == OAL_PTR_NULL) || (puc_param == OAL_PTR_NULL))) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_config_set_nbfh::pst_mac_vap/puc_param is null ptr!}\r\n");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /***************************************************************************
        ���¼���DMAC��, ͬ��DMAC����
    ***************************************************************************/
    ul_ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_SET_NBFH, us_len, puc_param);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        OAM_WARNING_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_CFG, "{wal_config_set_nbfh::hmac_config_send_event failed[%d]}",
                         ul_ret);
    }

    return OAL_SUCC;
}

/*
 * �� �� ��  : wal_config_hitalk_listen
 * ��������  : ����hitalk����
 * �޸���ʷ  :
 * 1.��    ��  : 2019��1��19��
 *   ��    ��  : l00423930
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_hitalk_listen(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint32 ul_ret;

    if (oal_unlikely((pst_mac_vap == OAL_PTR_NULL) || (puc_param == OAL_PTR_NULL))) {
        oam_warning_log0(0, OAM_SF_ANY, "{wal_config_hitalk_listen::pst_mac_vap/puc_param is null ptr!}\r\n");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /***************************************************************************
        ���¼���DMAC��, ͬ��DMAC����
    ***************************************************************************/
    ul_ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_HITALK_LISTEN, us_len, puc_param);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        OAM_WARNING_LOG1(pst_mac_vap->uc_vap_id, OAM_SF_CFG,
                         "{wal_config_hitalk_listen::hmac_config_send_event failed[%d].}", ul_ret);
    }

    return OAL_SUCC;
}

#endif

/*
 * �� �� ��  : wal_config_dscr_th_opt
 * ��������  : ����host���������Ż�����
 * �޸���ʷ  :
 * 1.��    ��  : 2019��2��16��
 *   ��    ��  : g00428180
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dscr_th_opt(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_dscr_th_opt(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_dscr_th_opt
 * ��������  : ����tcp ack���˹��ܿ���
 * �޸���ʷ  :
 * 1.��    ��  : 2019��4��2��
 *   ��    ��  : g00428180
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_tcp_ack_filter(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_tcp_ack_filter(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_dbb_scaling
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2016��1��9��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dbb_scaling_amend(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_dbb_scaling_amend(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_2040_channel_switch_prohibited
 * ��������  : 20/40�����ŵ��л����ÿ���(0: ����ֹ; 1: ��ֹ)
 * �޸���ʷ  :
 * 1.��    ��  : 2014��4��18��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_2040_channel_switch_prohibited(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                                oal_uint8 *puc_param)
{
    return hmac_config_2040_channel_switch_prohibited(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_fortymhzintolerant
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2014��6��5��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_fortymhzintolerant(mac_vap_stru *pst_mac_vap,
                                                        oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_fortymhzintolerant(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_2040_coext_support
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2014��6��5��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_2040_coext_support(mac_vap_stru *pst_mac_vap,
                                                        oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_2040_coext_support(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_auto_protection
 * ��������  : ����auto protection ����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��2��28��
 *   ��    ��  : c00260463
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_auto_protection(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    oal_uint8 uc_auto_protection_flag;

    if ((pst_mac_vap == OAL_PTR_NULL) || (puc_param == OAL_PTR_NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    uc_auto_protection_flag = (oal_uint8) * ((oal_uint32 *)puc_param);

    return hmac_config_set_auto_protection(pst_mac_vap, uc_auto_protection_flag);
}

/*
 * �� �� ��  : wal_config_send_2040_coext
 * ��������  : ����20/40�������֡
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��26��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_send_2040_coext(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                 oal_uint8 *puc_param)
{
    return hmac_config_send_2040_coext(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_2040_coext_info
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2014��6��10��
 *   ��    ��  : mayuan
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_2040_coext_info(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                 oal_uint8 *puc_param)
{
    return hmac_config_2040_coext_info(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_WLAN_FEATURE_FTM
/*
 * �� �� ��  : wal_config_ftm_dbg
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2017��5��22��
 *   ��    ��  : wwx408792
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_ftm_dbg(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_ftm_dbg(pst_mac_vap, us_len, puc_param);
}
#endif

#ifdef _PRE_WLAN_FEATURE_CSI_RAM
/*
 * �� �� ��  : wal_config_set_csi
 * ��������  : wal_config_set_csi
 * �޸���ʷ  :
 * 1.��    ��  : 2017��11��6��
 *   ��    ��  : l00357925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_csi(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_csi(pst_mac_vap, us_len, puc_param);
}
#endif
#ifdef _PRE_WLAN_FEATURE_OPMODE_NOTIFY

/*
 * �� �� ��  : wal_config_set_opmode_notify
 * ��������  : ���ù���ģʽ֪ͨ����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��6��12��
 *   ��    ��  : z00241943
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_opmode_notify(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                   oal_uint8 *puc_param)
{
    return hmac_config_set_opmode_notify(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_get_user_rssbw
 * ��������  : ���ù���ģʽ֪ͨ����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��6��12��
 *   ��    ��  : z00241943
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_get_user_rssbw(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_get_user_rssbw(pst_mac_vap, us_len, puc_param);
}

#endif
#ifdef _PRE_WLAN_FEATURE_CUSTOM_SECURITY
/*
 * �� �� ��  : wal_config_isolation_show
 * ��������  : ������Ϣ��ӡ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��7��9��
 *   ��    ��  : chenchongbao
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_isolation_show(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_show_isolation(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_autoblacklist_enable
 * ��������  : �Զ�������ȥ/ʹ��
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_autoblacklist_enable(mac_vap_stru *pst_mac_vap,
                                                      oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_autoblacklist_enable(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_autoblacklist_aging
 * ��������  : �����û�����ģʽ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_autoblacklist_aging(mac_vap_stru *pst_mac_vap,
                                                         oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_autoblacklist_aging(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_autoblacklist_aging
 * ��������  : �����û�����ģʽ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_autoblacklist_threshold(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                             oal_uint8 *puc_param)
{
    return hmac_config_set_autoblacklist_threshold(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_autoblacklist_aging
 * ��������  : �����û�����ģʽ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_autoblacklist_reset_time(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                              oal_uint8 *puc_param)
{
    return hmac_config_set_autoblacklist_reset_time(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_isolation_mode
 * ��������  : �����û�����ģʽ
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_isolation_mode(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_set_isolation_mode(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_isolation_type
 * ��������  : �����û���������
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_isolation_type(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_set_isolation_type(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_isolation_forward
 * ��������  : �����û�����forward
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_isolation_forward(mac_vap_stru *pst_mac_vap,
                                                       oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_isolation_forword(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_isolation_clear
 * ��������  : ����ͳ����0
 * �޸���ʷ  :
 * 1.��    ��  : 2014��3��27��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_isolation_clear(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_isolation_clear(pst_mac_vap, us_len, puc_param);
}
#endif

#ifdef _PRE_WLAN_FEATURE_WAPI
/*
 * �� �� ��  : wal_config_wapi_info
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��30��
 *   ��    ��  : z00260280
 *   �޸�����  : �����ɺ���
 */
#ifdef _PRE_WAPI_DEBUG
OAL_STATIC oal_uint32 wal_config_wapi_info(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    mac_cfg_user_info_param_stru *pst_user_info;
    pst_user_info = (mac_cfg_user_info_param_stru *)puc_param;

    hmac_wapi_display_info(pst_mac_vap, pst_user_info->us_user_idx);
    return OAL_SUCC;
}
#endif

#endif /* _PRE_WLAN_FEATURE_WAPI */

/*
 * �� �� ��  : wal_config_set_ampdu_aggr_num
 * ��������  : ���þۺ�������
 * �޸���ʷ  :
 * 1.��    ��  : 2014��10��29��
 *   ��    ��  : h00212953
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_ampdu_aggr_num(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_set_ampdu_aggr_num(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_stbc_cap
 * ��������  : ����AP��STBC����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��11��14��
 *   ��    ��  : W00269675
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_stbc_cap(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_stbc_cap(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_ldpc_cap
 * ��������  : ����AP��LDPC����
 * �޸���ʷ  :
 * 1.��    ��  : 2014��11��14��
 *   ��    ��  : W00269675
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_ldpc_cap(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_ldpc_cap(pst_mac_vap, us_len, puc_param);
}
#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
OAL_STATIC oal_uint32 wal_config_show_device_meminfo(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_sync_cmd_common(pst_mac_vap, WLAN_CFGID_DEVICE_MEM_INFO, us_len, puc_param);
}
#endif

#ifdef _PRE_WLAN_FEATURE_STA_PM
OAL_STATIC oal_uint32 wal_config_set_pm_param(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_sync_cmd_common(pst_mac_vap, WLAN_CFGID_SET_PSM_PARAM, us_len, puc_param);
}
#endif

/*
 * �� �� ��  : wal_config_vap_classify_en
 * ��������  : ����vap���ȼ��Ƿ�ʹ��
 * �޸���ʷ  :
 * 1.��    ��  : 2012��12��24��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_vap_classify_en(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                 oal_uint8 *puc_param)
{
    return hmac_config_vap_classify_en(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_vap_classify_tid
 * ��������  : ����vap���ȼ���tid
 * �޸���ʷ  :
 * 1.��    ��  : 2012��12��24��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_vap_classify_tid(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_vap_classify_tid(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_bgscan_enable
 * ��������  : ɨ��ģ���������
 * �޸���ʷ  :
 * 1.��    ��  : 2015��11��2��
 *   ��    ��  : W00346925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_bgscan_enable(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_bgscan_enable(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_mcs_set_check_enable
 * ��������  : 11n���ʼ�����������
 * �޸���ʷ  :
 * 1.��    ��  : 2018��8��3��
 *   ��    ��  : l00453963
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_mcs_set_check_enable(mac_vap_stru *pst_mac_vap,
                                                      oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_mcs_set_check_enable(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_set_tx_pow_param
 * ��������  : ����HAL�㷢�͹��ʲ���
 * �޸���ʷ  :
 * 1.��    ��  : 2016��12��23��
 *   ��    ��  : k00347307
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_tx_pow_param(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_set_tx_pow_param(pst_mac_vap, us_len, puc_param);
}

#ifdef _PRE_BT_FITTING_DATA_COLLECT
OAL_STATIC oal_uint32 wal_config_init_bt_env(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_init_bt_env(pst_mac_vap, us_len, puc_param);
}

OAL_STATIC oal_uint32 wal_config_set_bt_freq(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_bt_freq(pst_mac_vap, us_len, puc_param);
}

OAL_STATIC oal_uint32 wal_config_set_bt_upc_by_freq(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                    oal_uint8 *puc_param)
{
    return hmac_config_set_bt_upc_by_freq(pst_mac_vap, us_len, puc_param);
}

OAL_STATIC oal_uint32 wal_config_print_bt_gm(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_print_bt_gm(pst_mac_vap, us_len, puc_param);
}
#endif
#ifdef _PRE_WLAN_TCP_OPT
/*
 * �� �� ��  : wal_config_get_tcp_ack_stream_info
 * ��������  : ��ѯTCP ACK����ͳ��ֵ
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��19��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_get_tcp_ack_stream_info(mac_vap_stru *pst_mac_vap,
                                                         oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_get_tcp_ack_stream_info(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_tx_tcp_ack_opt_enable
 * ��������  : ���÷���TCP ACK�Ż�ʹ��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��19��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_tx_tcp_ack_opt_enable(mac_vap_stru *pst_mac_vap,
                                                       oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_tx_tcp_ack_opt_enable(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_rx_tcp_ack_opt_enable
 * ��������  : ���ý���TCP ACK�Ż�ʹ��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��19��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_rx_tcp_ack_opt_enable(mac_vap_stru *pst_mac_vap,
                                                       oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_rx_tcp_ack_opt_enable(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_tx_tcp_ack_limit
 * ��������  : ���÷���ack limit
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��19��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_tx_tcp_ack_limit(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_tx_tcp_ack_limit(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_rx_tcp_ack_limit
 * ��������  : ���ý���ack limit
 * �޸���ʷ  :
 * 1.��    ��  : 2015��5��19��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_rx_tcp_ack_limit(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                  oal_uint8 *puc_param)
{
    return hmac_config_rx_tcp_ack_limit(pst_mac_vap, us_len, puc_param);
}
#endif
#ifdef _PRE_WLAN_FEATURE_ROAM
/*
 * �� �� ��  : wal_config_roam_enable
 * ��������  : ��/�ر����ι���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��6��11��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_roam_enable(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_roam_enable(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_roam_band
 * ��������  : ��������Ƶ��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��6��11��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_roam_band(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_roam_band(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_roam_org
 * ��������  : �������������ŵ�
 * �޸���ʷ  :
 * 1.��    ��  : 2015��6��11��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_roam_org(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_roam_org(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_roam_start
 * ��������  : �������ι���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��6��11��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_roam_start(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_roam_start(pst_mac_vap, us_len, puc_param);
}

/*
 * �� �� ��  : wal_config_roam_info
 * ��������  : �������ι���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��6��11��
 *   ��    ��  : g00260350
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_roam_info(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_roam_info(pst_mac_vap, us_len, puc_param);
}
#endif  // _PRE_WLAN_FEATURE_ROAM

#ifdef _PRE_WLAN_FEATURE_20_40_80_COEXIST
/*
 * �� �� ��  : wal_config_enable_2040bss
 * ��������  : 20/40 bss��⿪��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��8��31��
 *   ��    ��  : w00249967
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_enable_2040bss(mac_vap_stru *pst_mac_vap, oal_uint16 us_len,
                                                oal_uint8 *puc_param)
{
    return hmac_config_enable_2040bss(pst_mac_vap, us_len, puc_param);
}
#endif /* _PRE_WLAN_FEATURE_20_40_80_COEXIST */

/*
 * �� �� ��  : wal_config_set_auto_freq_enable
 * ��������  : �����Զ���Ƶʹ��
 * �޸���ʷ  :
 * 1.��    ��  : 2015��9��16��
 *   ��    ��  : z00185449
 *   �޸�����  : �����ɺ���
 */
#ifdef _PRE_WLAN_FEATURE_AUTO_FREQ
OAL_STATIC oal_uint32 wal_config_set_auto_freq_enable(mac_vap_stru *pst_mac_vap,
                                                      oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_set_device_freq_enable(pst_mac_vap, us_len, puc_param);
}
#endif
#ifdef _PRE_WLAN_FIT_BASED_REALTIME_CALI
/*
 * �� �� ��  : wal_config_dyn_cali_param
 * ��������  : wal�㶯̬У׼���ú���
 * �޸���ʷ  :
 * 1.��    ��  : 2018��04��29��
 *   ��    ��  : w00434750
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_dyn_cali_param(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_dyn_cali_param(pst_mac_vap, us_len, puc_param);
}
#endif

#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
/*
 * �� �� ��  : wal_config_set_pm_debug_switch
 * ��������  : �������  : ��
 * �޸���ʷ  :
 * 1.��    ��  : 2017��9��7��
 *   ��    ��  : dwx371754
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_set_pm_debug_switch(mac_vap_stru *pst_mac_vap,
                                                     oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_pm_debug_switch(pst_mac_vap, us_len, puc_param);
}
#endif

/*
 * �� �� ��  : wal_config_protocol_debug_switch
 * ��������  : ���ô���Ŀ���
 * �޸���ʷ  :
 * 1.��    ��  : 2015��2��13��
 *   ��    ��  : wwx408792
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_protocol_debug_switch(mac_vap_stru *pst_mac_vap,
                                                       oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_protocol_debug_switch(pst_mac_vap, us_len, puc_param);
}
/*
 * �� �� ��  : wal_config_query_psm_flt_info
 * ��������  : ��ѯ�͹���֡����ͳ��
 * �޸���ʷ  :
 * 1.��    ��  : 2019��3��19��
 *   ��    ��  : d00469925
 *   �޸�����  : �����ɺ���
 */
OAL_STATIC oal_uint32 wal_config_query_psm_flt_info(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param)
{
    return hmac_config_query_psm_flt_info(pst_mac_vap, us_len, puc_param);
}

OAL_CONST wal_wid_op_stru g_ast_board_wid_op_debug[] = {
    { WLAN_CFGID_CHECK_FEM_PA, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_get_fem_pa_status },
    { WLAN_CFGID_EVENT_SWITCH,            OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_event_switch },
    { WLAN_CFGID_ETH_SWITCH,              OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_eth_switch },
    { WLAN_CFGID_80211_UCAST_SWITCH,      OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_80211_ucast_switch },
    { WLAN_CFGID_SET_VAP_CAP_FLAG_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_2040_coext_switch },
#ifdef _PRE_DEBUG_MODE_USER_TRACK
    { WLAN_CFGID_USR_THRPUT_STAT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_report_thrput_stat },
#endif
#ifdef _PRE_WLAN_FEATURE_TXOPPS
    { WLAN_CFGID_TXOP_PS_MACHW, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_txop_ps_machw },
#endif
    { WLAN_CFGID_80211_MCAST_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_80211_mcast_switch },
    { WLAN_CFGID_PROBE_SWITCH,       OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_probe_switch },
    { WLAN_CFGID_PHY_DEBUG_SWITCH,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_phy_debug_switch },
    { WLAN_CFGID_OTA_BEACON_SWITCH,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_ota_beacon_switch },
    { WLAN_CFGID_OTA_RX_DSCR_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_ota_rx_dscr_switch },
    { WLAN_CFGID_SET_ALL_OTA,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_all_ota },
    { WLAN_CFGID_SET_DHCP_ARP,       OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_dhcp_arp_switch },
    { WLAN_CFGID_OAM_OUTPUT_TYPE,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_oam_output },
    { WLAN_CFGID_AMSDU_START,      OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_amsdu_start },
    { WLAN_CFGID_AUTO_BA_SWITCH,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_auto_ba_switch },
    { WLAN_CFGID_ADDBA_REQ,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_addba_req },
    { WLAN_CFGID_DELBA_REQ,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_delba_req },
#ifdef _PRE_WLAN_FEATURE_WMMAC
    { WLAN_CFGID_ADDTS_REQ,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_addts_req },
    { WLAN_CFGID_DELTS,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_delts },
    { WLAN_CFGID_REASSOC_REQ,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_reassoc_req },
    { WLAN_CFGID_WMMAC_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_wmmac_switch },
#endif
#ifdef _PRE_WLAN_FEATURE_11K
    { WLAN_CFGID_BCN_TABLE_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_bcn_table_switch },
#endif  // _PRE_WLAN_FEATURE_11K
    { WLAN_CFGID_VOE_ENABLE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_voe_enable },
    { WLAN_CFGID_SET_FEATURE_LOG, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_feature_log },
#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
    { WLAN_CFGID_SET_LOG_PM, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_log_lowpower },
#endif
    { WLAN_CFGID_LIST_AP,      OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_list_ap },
    { WLAN_CFGID_LIST_STA,     OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_list_sta },
    { WLAN_CFGID_START_SCAN,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_start_scan },
    { WLAN_CFGID_START_JOIN,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_start_join },
    { WLAN_CFGID_START_DEAUTH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_start_deauth },
    { WLAN_CFGID_PAUSE_TID, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_pause_tid },
    { WLAN_CFGID_AMPDU_TX_ON, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_ampdu_tx_on },
    { WLAN_CFGID_AMSDU_TX_ON, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_amsdu_tx_on },
    { WLAN_CFGID_VAP_PKT_STAT,       OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_vap_pkt_stat },
    { WLAN_CFGID_TIMER_START,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_timer_start },
    { WLAN_CFGID_SHOW_PROFILING,     OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_show_profiling },
    { WLAN_CFGID_AMSDU_AMPDU_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_amsdu_ampdu_switch },
    { WLAN_CFGID_RESET_HW_OPERATE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_reset_operate },

#ifdef _PRE_WLAN_FEATURE_UAPSD
    { WLAN_CFGID_UAPSD_DEBUG, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_uapsd_debug },
#endif

#ifdef _PRE_WLAN_NARROW_BAND
    { WLAN_CFGID_NARROW_BW,     OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_narrow_bw },
    { WLAN_CFGID_SET_NBFH,      OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_nbfh },
    { WLAN_CFGID_HITALK_LISTEN, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_hitalk_listen },
#endif
    { WLAN_CFGID_SET_DSCR_TH_HOST, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dscr_th_opt },
    { WLAN_CFGID_SET_TCP_ACK_FILTER, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_tcp_ack_filter },

#ifdef _PRE_WLAN_DFT_STAT
    { WLAN_CFGID_USR_QUEUE_STAT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_usr_queue_stat },
#endif
    { WLAN_CFGID_DUMP_RX_DSCR, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dump_rx_dscr },
    { WLAN_CFGID_DUMP_TX_DSCR, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dump_tx_dscr },
    { WLAN_CFGID_DUMP_MEMORY,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dump_memory },
    { WLAN_CFGID_ALG,          OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_alg },
    {   WLAN_CFGID_2040_CHASWI_PROHI, OAL_FALSE, { 0 }, OAL_PTR_NULL,
        wal_config_2040_channel_switch_prohibited
    },
    { WLAN_CFGID_2040_INTOLERANT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_fortymhzintolerant },
    { WLAN_CFGID_2040_COEXISTENCE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_2040_coext_support },
#ifdef _PRE_WLAN_FEATURE_TCP_ACK_BUFFER
    { WLAN_CFGID_TCP_ACK_BUF, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_tcp_ack_buf },
#endif
    { WLAN_CFGID_SET_PS_PARAMS, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_ps_params },
    { WLAN_CFGID_LIST_CHAN, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_list_channel },
    { WLAN_CFGID_DBB_SCALING_AMEND, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dbb_scaling_amend },
    { WLAN_CFGID_TXBF_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_txbf_switch },
    { WLAN_CFGID_GET_HIPKT_STAT,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_get_hipkt_stat },
    { WLAN_CFGID_SET_FLOWCTL_PARAM, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_flowctl_param },
    { WLAN_CFGID_GET_FLOWCTL_STAT,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_get_flowctl_stat },
    { WLAN_CFGID_SET_AUTO_PROTECTION, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_auto_protection },
    { WLAN_CFGID_SEND_2040_COEXT,     OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_send_2040_coext },
    { WLAN_CFGID_2040_COEXT_INFO,     OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_2040_coext_info },

#ifdef _PRE_WLAN_FEATURE_FTM
    { WLAN_CFGID_FTM_DBG, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_ftm_dbg },
#endif

#ifdef _PRE_WLAN_FEATURE_CSI_RAM
    { WLAN_CFGID_SET_CSI, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_csi },
#endif

#ifdef _PRE_WLAN_FEATURE_OPMODE_NOTIFY
    { WLAN_CFGID_SET_OPMODE_NOTIFY, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_opmode_notify },
    { WLAN_CFGID_GET_USER_RSSBW, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_get_user_rssbw },
#endif
    { WLAN_CFGID_SET_AGGR_NUM, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_ampdu_aggr_num },
    { WLAN_CFGID_SET_STBC_CAP, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_stbc_cap },
    { WLAN_CFGID_SET_LDPC_CAP, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_ldpc_cap },

#ifdef _PRE_WLAN_FEATURE_CUSTOM_SECURITY
    /* �Զ��������������� */
    { WLAN_CFGID_AUTOBLACKLIST_ON, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_autoblacklist_enable },
    {   WLAN_CFGID_AUTOBLACKLIST_AGING, OAL_FALSE, { 0 }, OAL_PTR_NULL,
        wal_config_set_autoblacklist_aging
    },
    {   WLAN_CFGID_AUTOBLACKLIST_THRESHOLD, OAL_FALSE, { 0 }, OAL_PTR_NULL,
        wal_config_set_autoblacklist_threshold
    },
    {   WLAN_CFGID_AUTOBLACKLIST_RESET, OAL_FALSE, { 0 }, OAL_PTR_NULL,
        wal_config_set_autoblacklist_reset_time
    },

    /* �û������������ */
    { WLAN_CFGID_ISOLATION_MODE,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_isolation_mode },
    { WLAN_CFGID_ISOLATION_TYPE,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_isolation_type },
    { WLAN_CFGID_ISOLATION_FORWARD, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_isolation_forward },
    { WLAN_CFGID_ISOLATION_CLEAR,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_isolation_clear },
    { WLAN_CFGID_ISOLATION_SHOW,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_isolation_show },
#endif
#ifdef _PRE_WLAN_FEATURE_WAPI
#ifdef _PRE_WAPI_DEBUG
    { WLAN_CFGID_WAPI_INFO, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_wapi_info },
#endif
#endif

    { WLAN_CFGID_VAP_CLASSIFY_EN, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_vap_classify_en },
    { WLAN_CFGID_VAP_CLASSIFY_TID, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_vap_classify_tid },
    { WLAN_CFIGD_BGSCAN_ENABLE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_bgscan_enable },
#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
    { WLAN_CFGID_DEVICE_MEM_INFO, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_show_device_meminfo },
#endif
#ifdef _PRE_WLAN_FEATURE_STA_PM
    { WLAN_CFGID_SET_PSM_PARAM, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_pm_param },
#endif
#ifdef _PRE_WLAN_FEATURE_11D
    { WLAN_CFGID_SET_RD_IE_SWITCH, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_rd_by_ie_switch },
#endif
#ifdef _PRE_WLAN_TCP_OPT
    {   WLAN_CFGID_GET_TCP_ACK_STREAM_INFO, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_get_tcp_ack_stream_info
    },
    {   WLAN_CFGID_TX_TCP_ACK_OPT_ENALBE, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_tx_tcp_ack_opt_enable
    },
    {   WLAN_CFGID_RX_TCP_ACK_OPT_ENALBE, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_rx_tcp_ack_opt_enable
    },
    { WLAN_CFGID_TX_TCP_ACK_OPT_LIMIT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_tx_tcp_ack_limit },
    { WLAN_CFGID_RX_TCP_ACK_OPT_LIMIT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_rx_tcp_ack_limit },
#endif
#ifdef _PRE_WLAN_FEATURE_ROAM
    { WLAN_CFGID_ROAM_ENABLE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_roam_enable },
    { WLAN_CFGID_ROAM_ORG,    OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_roam_org },
    { WLAN_CFGID_ROAM_BAND,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_roam_band },
    { WLAN_CFGID_ROAM_START,  OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_roam_start },
    { WLAN_CFGID_ROAM_INFO,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_roam_info },
#endif  // _PRE_WLAN_FEATURE_ROAM

#ifdef _PRE_WLAN_FEATURE_20_40_80_COEXIST
    { WLAN_CFGID_2040BSS_ENABLE, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_enable_2040bss },
#endif
#ifdef _PRE_WLAN_FEATURE_AUTO_FREQ
    {   WLAN_CFGID_SET_DEVICE_FREQ_ENABLE, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_set_auto_freq_enable
    },
#endif
#ifdef _PRE_WLAN_FIT_BASED_REALTIME_CALI
    { WLAN_CFGID_DYN_CALI_CFG, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_dyn_cali_param },
#endif
#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC == _PRE_MULTI_CORE_MODE)
    {   WLAN_CFGID_PM_DEBUG_SWITCH, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_set_pm_debug_switch
    },
#endif

    {   WLAN_CFGID_PROTOCOL_DBG, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_protocol_debug_switch },
    {   WLAN_CFIGD_MCS_SET_CHECK_ENABLE, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_mcs_set_check_enable
    },
#ifdef _PRE_WLAN_FEATURE_BTCOEX
    { WLAN_CFGID_SET_BTCOEX_PARAMS, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_btcoex_params },
#endif
    { WLAN_CFGID_BINDCPU, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_bindcpu_params },
    {   WLAN_CFGID_NAPIWEIGHT, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_napi_weight_params
    },
    { WLAN_CFGID_SET_TX_POW, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_tx_pow_param },

#ifdef _PRE_BT_FITTING_DATA_COLLECT
    { WLAN_CFGID_INIT_BT_ENV,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_init_bt_env },
    { WLAN_CFGID_SET_BT_FREQ,        OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_set_bt_freq },
    {   WLAN_CFGID_SET_BT_UPC_BY_FREQ, OAL_FALSE, { 0 },
        OAL_PTR_NULL, wal_config_set_bt_upc_by_freq
    },
    { WLAN_CFGID_PRINT_BT_GM, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_print_bt_gm },
#endif
    { WLAN_CFGID_CHECK_PACKET, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_packet_check },

    { WLAN_CFGID_QUERY_PSM_STAT, OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_query_psm_flt_info },

    { WLAN_CFGID_OPMODE_SWITCH,   OAL_FALSE, { 0 }, OAL_PTR_NULL, wal_config_opmode_switch },

    { WLAN_CFGID_BUTT, OAL_FALSE, { 0 }, 0, 0 },
};

oal_uint32 wal_config_get_debug_wid_arrysize(oal_void)
{
    return oal_array_size(g_ast_board_wid_op_debug);
}
#endif


