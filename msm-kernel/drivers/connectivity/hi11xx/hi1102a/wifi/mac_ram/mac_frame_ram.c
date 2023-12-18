/*
 * ��Ȩ���� (c) ��Ϊ�������޹�˾ 2001-2011
 * ����˵�� : ��Ӧ֡�Ľṹ�����Դ�ļ�
 * ��    �� : l00280485
 * �������� : 2018��3��20��
 */

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "mac_frame.h"
#include "mac_vap.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_MAC_FRAME_RAM_C
/*****************************************************************************
  4 ����ʵ��
*****************************************************************************/
/*
 *  �� �� ��   : mac_ftm_set_rrm_enabled_cap_field
 *  ��������   : ���RRM Enabled Cap IE
 *  �޸���ʷ   :
 *   1.��    ��   : 2016��9��22��
 *     ��    ��   : y00196452
 *     �޸�����   : �����ɺ���
 */
oal_void mac_set_rrm_enabled_cap_field_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}

/*
 *  �� �� ��   : mac_set_vht_capabilities_ie_cb
 *  ��������   : mac_set_vht_capabilities_ie�Ļص�����
 *  �޸���ʷ   :
 *   1.��    ��   : 2018��6��19��
 *     ��    ��   : r00356856
 *     �޸�����   : �����ɺ���
 */
oal_void mac_set_vht_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}
/*
 *  �� �� ��   : mac_set_ht_capabilities_ie_cb
 *  ��������   : mac_set_ht_capabilities_ie�Ļص�����
 *  �޸���ʷ   :
 *   1.��    ��   : 2018��6��19��
 *     ��    ��   : r00356856
 *     �޸�����   : �����ɺ���
 */
oal_void mac_set_ht_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}
/*
 *  �� �� ��   : mac_set_ext_capabilities_ie_cb
 *  ��������   : mac_set_ext_capabilities_ie�Ļص�����
 *  �޸���ʷ   :
 *   1.��    ��   : 2017��09��12��
 *     ��    ��   : l00280485
 *     �޸�����   : �����ɺ���
 */
oal_void mac_set_ext_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
    mac_ext_cap_ie_stru     *pst_ext_cap = OAL_PTR_NULL;
    mac_vap_stru            *pst_mac_vap;

    pst_mac_vap = (mac_vap_stru *)pst_vap;

    /* aputģʽ��֧��interworking; DTS2019040802891: staģʽinterworking�涨�ƻ���λ */
    if ((g_customize_interworking == OAL_FALSE) || (pst_mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP)) {
        pst_ext_cap = (mac_ext_cap_ie_stru *)(puc_buffer + MAC_IE_HDR_LEN);
        pst_ext_cap->bit_interworking = 0;
    }
}

/*
 *  �� �� ��   : mac_set_rsn_ie_cb
 *  ��������   : mac_set_rsn_ie�Ļص�����
 *  �޸���ʷ   :
 *   1.��    ��   : 2018��9��3��
 *     ��    ��   : g00428180
 *     �޸�����   : �����ɺ���
 */
oal_rom_cb_result_enum_uint8 mac_set_rsn_ie_cb(
    oal_void *pst_vap, oal_uint8 *puc_pmkid, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len, oal_uint32 *pul_ret)
{
    return OAL_CONTINUE;
}

/*
 *  �� �� ��   : mac_set_wpa_ie_cb
 *  ��������   : mac_set_wpa_ie�Ļص�����
 *  �޸���ʷ   :
 *   1.��    ��   : 2018��9��11��
 *     ��    ��   : g00428180
 *     �޸�����   : �����ɺ���
 */
oal_rom_cb_result_enum_uint8 mac_set_wpa_ie_cb(
    oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len, oal_uint32 *pul_ret)
{
    return OAL_CONTINUE;
}


