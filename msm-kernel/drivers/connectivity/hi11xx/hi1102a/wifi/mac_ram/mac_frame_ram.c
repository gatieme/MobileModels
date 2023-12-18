/*
 * 版权所有 (c) 华为技术有限公司 2001-2011
 * 功能说明 : 对应帧的结构定义的源文件
 * 作    者 : l00280485
 * 创建日期 : 2018年3月20日
 */

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "mac_frame.h"
#include "mac_vap.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_MAC_FRAME_RAM_C
/*****************************************************************************
  4 函数实现
*****************************************************************************/
/*
 *  函 数 名   : mac_ftm_set_rrm_enabled_cap_field
 *  功能描述   : 填充RRM Enabled Cap IE
 *  修改历史   :
 *   1.日    期   : 2016年9月22日
 *     作    者   : y00196452
 *     修改内容   : 新生成函数
 */
oal_void mac_set_rrm_enabled_cap_field_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}

/*
 *  函 数 名   : mac_set_vht_capabilities_ie_cb
 *  功能描述   : mac_set_vht_capabilities_ie的回调函数
 *  修改历史   :
 *   1.日    期   : 2018年6月19日
 *     作    者   : r00356856
 *     修改内容   : 新生成函数
 */
oal_void mac_set_vht_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}
/*
 *  函 数 名   : mac_set_ht_capabilities_ie_cb
 *  功能描述   : mac_set_ht_capabilities_ie的回调函数
 *  修改历史   :
 *   1.日    期   : 2018年6月19日
 *     作    者   : r00356856
 *     修改内容   : 新生成函数
 */
oal_void mac_set_ht_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
}
/*
 *  函 数 名   : mac_set_ext_capabilities_ie_cb
 *  功能描述   : mac_set_ext_capabilities_ie的回调函数
 *  修改历史   :
 *   1.日    期   : 2017年09月12日
 *     作    者   : l00280485
 *     修改内容   : 新生成函数
 */
oal_void mac_set_ext_capabilities_ie_cb(oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len)
{
    mac_ext_cap_ie_stru     *pst_ext_cap = OAL_PTR_NULL;
    mac_vap_stru            *pst_mac_vap;

    pst_mac_vap = (mac_vap_stru *)pst_vap;

    /* aput模式不支持interworking; DTS2019040802891: sta模式interworking随定制化置位 */
    if ((g_customize_interworking == OAL_FALSE) || (pst_mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_AP)) {
        pst_ext_cap = (mac_ext_cap_ie_stru *)(puc_buffer + MAC_IE_HDR_LEN);
        pst_ext_cap->bit_interworking = 0;
    }
}

/*
 *  函 数 名   : mac_set_rsn_ie_cb
 *  功能描述   : mac_set_rsn_ie的回调函数
 *  修改历史   :
 *   1.日    期   : 2018年9月3日
 *     作    者   : g00428180
 *     修改内容   : 新生成函数
 */
oal_rom_cb_result_enum_uint8 mac_set_rsn_ie_cb(
    oal_void *pst_vap, oal_uint8 *puc_pmkid, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len, oal_uint32 *pul_ret)
{
    return OAL_CONTINUE;
}

/*
 *  函 数 名   : mac_set_wpa_ie_cb
 *  功能描述   : mac_set_wpa_ie的回调函数
 *  修改历史   :
 *   1.日    期   : 2018年9月11日
 *     作    者   : g00428180
 *     修改内容   : 新生成函数
 */
oal_rom_cb_result_enum_uint8 mac_set_wpa_ie_cb(
    oal_void *pst_vap, oal_uint8 *puc_buffer, oal_uint8 *puc_ie_len, oal_uint32 *pul_ret)
{
    return OAL_CONTINUE;
}


