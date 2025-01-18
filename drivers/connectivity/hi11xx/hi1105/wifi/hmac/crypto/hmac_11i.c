/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : STA侧管理帧处理
 * 作    者 :
 * 创建日期 : 2013年12月10日
 */


#include "oal_ext_if.h"
#include "oal_types.h"
#include "oal_net.h"
#include "frw_ext_if.h"
#include "wlan_types.h"
#include "mac_resource.h"
#include "mac_frame.h"
#include "mac_device.h"
#include "mac_resource.h"
#include "mac_vap.h"
#include "wlan_chip_i.h"

#include "hmac_11i.h"

#include "hmac_wapi.h"

#include "hmac_main.h"
#include "hmac_crypto_tkip.h"
#include "hmac_config.h"
#include "hmac_mgmt_bss_comm.h"
#include "hmac_roam_main.h"
#include "securec.h"
#include "mac_mib.h"
#ifdef _PRE_WLAN_CHBA_MGMT
#include "hmac_chba_function.h"
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
#include "hmac_pwl.h"
#endif
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_11I_C

/*
 * 函 数 名  : hmac_get_key_info
 * 功能描述  : 获取key
 * 1.日    期  : 2013年11月22日
  *   修改内容  : 新生成函数
 */
OAL_STATIC wlan_priv_key_param_stru *hmac_get_key_info(mac_vap_stru *pst_mac_vap, uint8_t *puc_mac_addr,
    oal_bool_enum_uint8 en_pairwise, uint8_t uc_key_index, uint16_t *pus_user_idx)
{
    oal_bool_enum_uint8 en_macaddr_is_zero;
    mac_user_stru *pst_mac_user = NULL;
    uint32_t ret;

    /* 1.1 根据mac addr 找到对应sta索引号 */
    en_macaddr_is_zero = mac_addr_is_zero(puc_mac_addr);
    if (!mac_11i_is_ptk(en_macaddr_is_zero, en_pairwise)) {
        /* 如果是组播用户，不能使用mac地址来查找, 根据索引找到组播user内存区域 */
        *pus_user_idx = pst_mac_vap->us_multi_user_idx;
    } else { /* 单播用户 */
        ret = mac_vap_find_user_by_macaddr(pst_mac_vap, puc_mac_addr, pus_user_idx);
        if (ret != OAL_SUCC) {
            oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                             "{hmac_get_key_info::mac_vap_find_user_by_macaddr failed[%d]}", ret);
            return NULL;
        }
    }

    pst_mac_user = (mac_user_stru *)mac_res_get_mac_user(*pus_user_idx);
    if (pst_mac_user == NULL) {
        oam_warning_log1(pst_mac_vap->uc_vap_id,
            OAM_SF_WPA, "{hmac_get_key_info::pst_mac_user[%d] null.}", *pus_user_idx);
        return NULL;
    }

    /* LOG */
    oam_info_log2(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                  "{hmac_get_key_info::key_index=%d,pairwise=%d.}", uc_key_index, en_pairwise);

    if (puc_mac_addr != NULL) {
        oam_info_log4(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                      "{hmac_get_key_info::user[%d] mac_addr = %02X:XX:XX:XX:%02X:%02X.}",
                      *pus_user_idx, puc_mac_addr[0], puc_mac_addr[4], puc_mac_addr[5]); // mac地址的第0 4 5字节
    }

    return mac_user_get_key(pst_mac_user, uc_key_index);
}
#ifdef _PRE_WLAN_FEATURE_WAPI
static void hmac_wapi_update_device_param(oal_bool_enum_uint8 value)
{
    mac_device_stru *mac_device = mac_res_get_mac_dev();
    mac_device->uc_wapi = value;
}

static void hmac_wapi_update_user_param(uint16_t user_index, wlan_ciper_protocol_type_enum_uint8 cipher_type)
{
    mac_user_stru *mac_user = mac_res_get_mac_user(user_index);
    if (mac_user == NULL) {
        oam_error_log1(0, OAM_SF_CFG, "{hmac_wapi_update_user_param::user[%d] null.}", user_index);
        return;
    }
    /* 配置WAPI密钥，更新加密类型为WAPI */
    mac_user->st_key_info.en_cipher_type = cipher_type;
}

/*
 * 函 数 名  : hmac_config_wapi_add_key
 * 功能描述  : 配置wapi key并且同步
 * 1.日    期  : 2015年2月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static uint32_t hmac_config_wapi_add_key(mac_vap_stru *pst_mac_vap, mac_addkey_param_stru *pst_payload_addkey_params)
{
    uint8_t uc_key_index = pst_payload_addkey_params->uc_key_index;
    oal_bool_enum_uint8 pairwise = pst_payload_addkey_params->en_pairwise;
    mac_key_params_stru *pst_key_param = &pst_payload_addkey_params->st_key;
    hmac_user_stru *hmac_user = NULL;
    uint32_t ret;
    uint16_t us_user_index;

    if (uc_key_index >= HMAC_WAPI_MAX_KEYID) {
        oam_error_log1(0, OAM_SF_WPA, "{hmac_config_wapi_add_key::keyid==%u Err!.}", uc_key_index);
        return OAL_FAIL;
    }
    if (pst_key_param->key_len != (WAPI_KEY_LEN * 2)) { // key_len值为32，WAPI_KEY_LEN的2倍
        oam_error_log1(0, OAM_SF_WPA, "{hmac_config_wapi_add_key:: key_len %u Err!.}", pst_key_param->key_len);
        return OAL_FAIL;
    }
    if (pairwise) {
        ret = mac_vap_find_user_by_macaddr(pst_mac_vap, pst_payload_addkey_params->auc_mac_addr, &us_user_index);
        if (ret != OAL_SUCC) {
            oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY,
                "{hmac_config_wapi_add_key::mac_vap_find_user_by_macaddr failed. %u}", ret);
            return OAL_ERR_CODE_PTR_NULL;
        }
    } else {
        us_user_index = pst_mac_vap->us_multi_user_idx;
    }
    oam_warning_log2(pst_mac_vap->uc_vap_id, OAM_SF_WAPI,
        "hmac_config_wapi_add_key:add wapi [%u][0:mcast, 1:pairwise] key to user [%u]", pairwise, us_user_index);
    hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(us_user_index);
    if (hmac_user == NULL) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "hmac_config_wapi_add_key:user_index[%d] get hmac user fail",
            us_user_index);
        return OAL_FAIL;
    }
    hmac_wapi_add_key(hmac_user, pairwise, uc_key_index, pst_key_param->auc_key);
    hmac_wapi_update_device_param(OAL_TRUE);
    hmac_wapi_update_user_param(us_user_index, WLAN_80211_CIPHER_SUITE_WAPI);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_wapi_add_key_and_sync
 * 功能描述  : 保存wapi key并且同步
 * 1.日    期  : 2015年2月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
static uint32_t hmac_config_wapi_add_key_and_sync(mac_vap_stru *pst_mac_vap,
    mac_addkey_param_stru *pst_payload_addkey_params)
{
    hmac_vap_stru *pst_hmac_vap = NULL;
    uint32_t ret;

    oam_warning_log2(0, OAM_SF_WAPI, "{hmac_config_wapi_add_key_and_sync:: key idx==%u, pairwise==%u}",
        pst_payload_addkey_params->uc_key_index, pst_payload_addkey_params->en_pairwise);
    oam_warning_log3(0, OAM_SF_WAPI, "{hmac_config_wapi_add_key_and_sync::mac_addr[%02X:XX:XX:XX:%02X:%02X]}",
        pst_payload_addkey_params->auc_mac_addr[MAC_ADDR_0],
        pst_payload_addkey_params->auc_mac_addr[MAC_ADDR_4], pst_payload_addkey_params->auc_mac_addr[MAC_ADDR_5]);

    pst_hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(pst_mac_vap->uc_vap_id);
    if (pst_hmac_vap == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_ANY, "{hmac_config_11i_add_key::pst_hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = hmac_config_wapi_add_key(&pst_hmac_vap->st_vap_base_info, pst_payload_addkey_params);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_add_key::hmac_config_wapi_add_key fail[%d].}", ret);
        return ret;
    }

    ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_ADD_WAPI_KEY,
        sizeof(*pst_payload_addkey_params), (uint8_t *)pst_payload_addkey_params);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_add_key::WLAN_CFGID_ADD_WAPI_KEY send fail[%d].}", ret);
        return ret;
    }

    return ret;
}
#endif /* #ifdef _PRE_WLAN_FEATURE_WAPI */

void hmac_user_clear_ptk_rx_pn(hmac_user_stru *hmac_user)
{
    memset_s(&(hmac_user->last_pn_info.ucast_qos_last_lsb_pn), WLAN_TID_MAX_NUM * sizeof(uint32_t),
        0, WLAN_TID_MAX_NUM * sizeof(uint32_t));
    memset_s(&(hmac_user->last_pn_info.ucast_qos_last_msb_pn), WLAN_TID_MAX_NUM * sizeof(uint16_t),
        0, WLAN_TID_MAX_NUM * sizeof(uint16_t));
    memset_s(&(hmac_user->last_pn_info.mcast_qos_last_lsb_pn), WLAN_TID_MAX_NUM * sizeof(uint32_t),
        0, WLAN_TID_MAX_NUM * sizeof(uint32_t));
    memset_s(&(hmac_user->last_pn_info.mcast_qos_last_msb_pn), WLAN_TID_MAX_NUM * sizeof(uint16_t),
        0, WLAN_TID_MAX_NUM * sizeof(uint16_t));
    hmac_user->last_pn_info.ucast_nonqos_last_lsb_pn = 0;
    hmac_user->last_pn_info.ucast_nonqos_last_msb_pn = 0;
}
void hmac_user_clear_gtk_rx_pn(hmac_user_stru *hmac_user)
{
    hmac_user->last_pn_info.mcast_nonqos_last_lsb_pn = 0;
    hmac_user->last_pn_info.mcast_nonqos_last_msb_pn = 0;
    hmac_user->last_pn_info.ucast_nonqos_last_lsb_pn = 0;
    hmac_user->last_pn_info.ucast_nonqos_last_msb_pn = 0;
}

/*
 * 功能描述   : 更新秘钥时，清除本地保存的PN号
 * 1.日    期   : 2020年6月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hmac_user_clear_rx_pn(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user,
    uint8_t pairwise)
{
    uint16_t user_idx = g_wlan_spec_cfg->invalid_user_id;

    if (pairwise) {
        hmac_user_clear_ptk_rx_pn(hmac_user);
    } else {
        hmac_user_clear_gtk_rx_pn(hmac_user);
    }

    if (!is_sta(mac_vap)) {
        return;
    }

    /* STA只有一个关联用户，组播秘钥更新时，需要找到关联用户下记录的PN号进行清除 */
    if (OAL_SUCC != mac_vap_find_user_by_macaddr(mac_vap, mac_vap->auc_bssid, &user_idx)) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_user_clear_rx_pn::user_idx[%d] find_user_by_macaddr fail.}", user_idx);
        return;
    }

    /* 单播用户不用再继续处理 */
    if (user_idx == hmac_user->st_user_base_info.us_assoc_id) {
        return;
    }

    hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(user_idx);
    if (hmac_user == NULL) {
        return;
    }

    oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_WPA,
        "{hmac_user_clear_rx_pn::user_idx[%d] multi_user_idx[%d].}", user_idx, mac_vap->us_multi_user_idx);

    hmac_user_clear_gtk_rx_pn(hmac_user);
    return;
}

hmac_user_stru *hmac_config_11i_get_assoc_user(mac_vap_stru *mac_vap,
    mac_addkey_param_stru *addkey_params)
{
    uint32_t ret;
    uint8_t *mac_addr = NULL;
    oal_bool_enum_uint8 pairwise;
    uint8_t key_index;
    uint16_t user_idx = g_wlan_spec_cfg->invalid_user_id;
    hmac_user_stru *hmac_user = NULL;

    key_index = addkey_params->uc_key_index;
    pairwise = addkey_params->en_pairwise;
    mac_addr = (uint8_t *)addkey_params->auc_mac_addr;

    /* 2.2 索引值最大值检查 */
    if (key_index >= WLAN_NUM_TK + WLAN_NUM_IGTK) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_get_assoc_user::invalid key_index[%d].}", key_index);
        return NULL;
    }

    if (pairwise == OAL_TRUE) {
        /* 单播密钥存放在单播用户中 */
        ret = mac_vap_find_user_by_macaddr(mac_vap, mac_addr, &user_idx);
        if (ret != OAL_SUCC) {
            // 驱动删用户与hostapd删用户在时序上无法保证原子过程，可能出现二者同时删除的情形
            oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_WPA,
                "{hmac_config_11i_get_assoc_user::user_idx[%d] find_user_by_macaddr fail[%d].}", user_idx, ret);
            return NULL;
        }
    } else {
        /* 组播密钥存放在组播用户中 */
        user_idx = mac_vap->us_multi_user_idx;
    }

    hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(user_idx);
    if (hmac_user == NULL) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_get_assoc_user::get_mac_user null.idx:%u}", user_idx);
        return NULL;
    }
    return hmac_user;
}

uint32_t hmac_config_11i_update_key(hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    mac_addkey_param_stru *addkey_params)
{
    uint32_t ret;
    uint8_t *mac_addr = NULL;
    oal_bool_enum_uint8 pairwise;
    uint8_t key_index;
    mac_key_params_stru *key = NULL;
    wlan_cipher_key_type_enum_uint8 key_type;
    mac_vap_stru *mac_vap = NULL;

    key_index = addkey_params->uc_key_index;
    pairwise = addkey_params->en_pairwise;
    mac_addr = (uint8_t *)addkey_params->auc_mac_addr;
    key = &(addkey_params->st_key);

    mac_vap = &hmac_vap->st_vap_base_info;

    /* 3.1 将加密属性更新到用户中 */
    ret = mac_vap_add_key(mac_vap, &hmac_user->st_user_base_info, key_index, key);
    if (ret != OAL_SUCC) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_update_key::mac_11i_add_key fail[%d].}", ret);
        return ret;
    }

    key_type = (pairwise == OAL_TRUE) ? WLAN_KEY_TYPE_PTK : WLAN_KEY_TYPE_RX_GTK;
    mac_user_set_key(&hmac_user->st_user_base_info, key_type, key->cipher, key_index);

    /* 组播秘钥更新后，应该清除关联用户下记录的组播帧PN号，而不是组播用户下记录的组播帧PN号 */
    hmac_user_clear_rx_pn(mac_vap, hmac_user, pairwise);

    /* 设置用户8021x端口合法性的状态为合法 */
    mac_user_set_port(&hmac_user->st_user_base_info, OAL_TRUE);

    if ((mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA) && (mac_vap->en_vap_state == MAC_VAP_STATE_ROAMING) &&
        (pairwise == OAL_FALSE)) {
        hmac_roam_add_key_done(hmac_vap);
    }

    return ret;
}

#ifdef _PRE_WLAN_FEATURE_WAPI
static uint32_t hmac_config_11i_close_wapi_port(mac_vap_stru *mac_vap, hmac_user_stru *hmac_user)
{
    mac_device_stru *mac_device = NULL;
    /* 11i的情况下，关掉wapi端口 */
    hmac_wapi_set_port(&hmac_user->st_wapi, OAL_FALSE);

    mac_device = mac_res_get_dev(mac_vap->uc_device_id);
    if (mac_device == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_config_11i_add_key::mac_device null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }
    mac_device->uc_wapi = OAL_FALSE;
    return OAL_SUCC;
}
#endif

#ifdef _PRE_WLAN_FEATURE_PWL
static void hmac_config_11i_close_pwl_port(hmac_user_stru *hmac_user)
{
    hmac_pwl_set_port(&hmac_user->pwl_pre, OAL_FALSE);
    hmac_pwl_set_port(&hmac_user->pwl, OAL_FALSE);
}
#endif

/*
 * 函 数 名  : hmac_config_11i_add_key
 * 功能描述  : add key 逻辑，抛事件到DMAC
 * 1.日    期  : 2013年12月26日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_11i_add_key(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    hmac_user_stru *hmac_user = NULL;
    hmac_vap_stru *hmac_vap = NULL;
    mac_addkey_param_stru *addkey_params = (mac_addkey_param_stru *)param;
    uint32_t ret;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(mac_vap, addkey_params)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_add_key::param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hmac_vap = (hmac_vap_stru *)mac_res_get_hmac_vap(mac_vap->uc_vap_id);
    if (hmac_vap == NULL) {
        oam_error_log0(mac_vap->uc_vap_id, OAM_SF_CFG, "{hmac_config_11i_add_key::hmac_vap null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

#ifdef _PRE_WLAN_FEATURE_WAPI
    if (oal_unlikely(WLAN_CIPHER_SUITE_SMS4 == addkey_params->st_key.cipher)) {
        return hmac_config_wapi_add_key_and_sync(mac_vap, addkey_params);
    }
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    if (hmac_is_pwl_cipher(addkey_params) == OAL_TRUE) {
        return hmac_pwl_add_key(mac_vap, addkey_params);
    }
#endif

    hmac_user = hmac_config_11i_get_assoc_user(mac_vap, addkey_params);
    if (hmac_user == NULL) {
        return OAL_ERR_CODE_SECURITY_USER_INVAILD;
    }
    // add_key流程中清除user下的分片缓存，防止重关联或者rekey流程报文重组攻击
    hmac_user_clear_defrag_res(hmac_user);
#ifdef _PRE_WLAN_FEATURE_WAPI
    if (hmac_config_11i_close_wapi_port(mac_vap, hmac_user) != OAL_SUCC) {
        return OAL_FAIL;
    }
#endif
#ifdef _PRE_WLAN_FEATURE_PWL
    hmac_config_11i_close_pwl_port(hmac_user);
#endif
    ret = hmac_config_11i_update_key(hmac_vap, hmac_user, addkey_params);
    if (ret != OAL_SUCC) {
        return ret;
    }
    /***************************************************************************
    抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    ret = hmac_config_send_event(mac_vap, WLAN_CFGID_ADD_KEY, len, param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(mac_vap->uc_vap_id, OAM_SF_WPA,  "{hmac_config_11i_add_key::send_event failed[%d].}", ret);
    }
#ifdef _PRE_WLAN_CHBA_MGMT
    /* CHBA user同步处理 */
    hmac_chba_sync_process_after_asoc(hmac_vap, hmac_user);
#endif
    return ret;
}

static void hmac_config_11i_trans_key(wlan_priv_key_param_stru *priv_key, oal_key_params_stru *key)
{
    memset_s(key, sizeof(oal_key_params_stru), 0, sizeof(oal_key_params_stru));
    key->key = priv_key->auc_key;
    key->key_len = (int32_t)priv_key->key_len;
    key->seq = priv_key->auc_seq;
    key->seq_len = (int32_t)priv_key->seq_len;
    key->cipher = priv_key->cipher;
}

/*
 * 函 数 名  : hmac_config_11i_get_key
 * 功能描述  : 获取密钥，不需要抛事件到DMAC,直接从hmac数据区中拿数据
 * 1.日    期  : 2013年8月16日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_config_11i_get_key(mac_vap_stru *pst_mac_vap, uint16_t us_len, uint8_t *puc_param)
{
    wlan_priv_key_param_stru *pst_priv_key = NULL;
    oal_key_params_stru st_key;
    uint8_t uc_key_index;
    uint16_t us_user_idx = g_wlan_spec_cfg->invalid_user_id;
    oal_bool_enum_uint8 en_pairwise;
    uint8_t *puc_mac_addr = NULL;
    void *cookie = NULL;
    void (*callback)(void *, oal_key_params_stru *);
    hmac_getkey_param_stru *pst_payload_getkey_params = NULL;

    callback = NULL;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(pst_mac_vap, puc_param)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_get_key::pst_mac_vap or puc_param is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 2.1 获取参数 */
    pst_payload_getkey_params = (hmac_getkey_param_stru *)puc_param;
    uc_key_index = pst_payload_getkey_params->uc_key_index;
    en_pairwise = pst_payload_getkey_params->en_pairwise;
    puc_mac_addr = pst_payload_getkey_params->puc_mac_addr;
    cookie = pst_payload_getkey_params->cookie;
    callback = pst_payload_getkey_params->callback;

    /* 2.2 索引值最大值检查 */
    if (uc_key_index >= WLAN_NUM_TK + WLAN_NUM_IGTK) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_get_key::uc_key_index invalid[%d].}", uc_key_index);
        return OAL_ERR_CODE_SECURITY_KEY_ID;
    }

    /* 3.1 获取密钥 */
    pst_priv_key = hmac_get_key_info(pst_mac_vap, puc_mac_addr, en_pairwise, uc_key_index, &us_user_idx);
    /* begin:  四次握手获取密钥信息长度为0 是正常值,不应该为error 级别打印 */
    if (pst_priv_key == NULL) {
        oam_error_log2(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_get_key::key is null.pairwise[%d], key_idx[%d]}",
            en_pairwise, uc_key_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (pst_priv_key->key_len == 0) {
        oam_info_log2(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_get_key::key len = 0.pairwise[%d], key_idx[%d]}",
            en_pairwise, uc_key_index);
        return OAL_ERR_CODE_SECURITY_KEY_LEN;
    }
    /* end:  四次握手获取密钥信息长度为0 是正常值,不应该为error 级别打印 */
    /* 4.1 密钥赋值转换 */
    hmac_config_11i_trans_key(pst_priv_key, &st_key);
    /* 5.1 调用回调函数 */
    if (callback != NULL) {
        callback(cookie, &st_key);
    }

    return OAL_SUCC;
}

static void hmac_user_remove_key_clear_rx_pn(mac_vap_stru *mac_vap,
    uint8_t pairwise, uint8_t *mac_addr)
{
    hmac_user_stru *hmac_user = NULL;
    uint16_t user_idx = g_wlan_spec_cfg->invalid_user_id;
    uint32_t ret;

    if (pairwise == OAL_TRUE) {
        /* 单播密钥存放在单播用户中 */
        ret = mac_vap_find_user_by_macaddr(mac_vap, mac_addr, &user_idx);
        if (ret != OAL_SUCC) {
            // 驱动删用户与hostapd删用户在时序上无法保证原子过程，可能出现二者同时删除的情形
            oam_warning_log2(mac_vap->uc_vap_id, OAM_SF_WPA,
                "{hmac_user_clear_remove_key_rx_pn::us_user_idx[%d] ret[%d].}", user_idx, ret);
            return;
        }
    } else {
        /* 组播密钥存放在组播用户中 */
        user_idx = mac_vap->us_multi_user_idx;
    }

    hmac_user = (hmac_user_stru *)mac_res_get_hmac_user(user_idx);
    if (hmac_user == NULL) {
        oam_error_log1(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_user_clear_remove_key_rx_pn::get_mac_user null.idx:%u}", user_idx);
        return;
    }

    hmac_user_clear_rx_pn(mac_vap, hmac_user, pairwise);
}

uint32_t hmac_config_11i_remove_wpa_key(mac_vap_stru *mac_vap, mac_removekey_param_stru *removekey_params)
{
    uint8_t key_index;
    mac_user_stru *mac_user = NULL;
    oal_bool_enum_uint8 pairwise;
    oal_bool_enum_uint8 macaddr_is_zero;
    uint8_t *mac_addr = NULL;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(mac_vap, removekey_params)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_remove_wpa_key::mac_vap or param is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 2.1 获取参数 */
    key_index = removekey_params->uc_key_index;
    pairwise = removekey_params->en_pairwise;
    mac_addr = removekey_params->auc_mac_addr;

    macaddr_is_zero = mac_addr_is_zero(mac_addr);
    if (mac_11i_is_ptk(macaddr_is_zero, pairwise)) {
        mac_user = mac_vap_get_user_by_addr(mac_vap, mac_addr);
        if (mac_user == NULL) {
            return OAL_ERR_CODE_SECURITY_USER_INVAILD;
        }
        mac_user->st_user_tx_info.st_security.en_cipher_key_type = HAL_KEY_TYPE_BUTT;
    } else {
        mac_user = (mac_user_stru *)mac_res_get_mac_user(mac_vap->us_multi_user_idx);
        if (mac_user == NULL) {
            return OAL_ERR_CODE_SECURITY_USER_INVAILD;
        }
        mac_user_init_key(mac_user);
    }

    hmac_user_remove_key_clear_rx_pn(mac_vap, pairwise, mac_addr);
    mac_user_set_port(mac_user, OAL_FALSE);

    if (mac_vap->en_vap_mode == WLAN_VAP_MODE_BSS_STA &&  mac_vap->en_vap_state != MAC_VAP_STATE_STA_FAKE_UP) {
        mac_user_set_pmf_active(mac_user, mac_vap->en_user_pmf_cap);
    }

    return OAL_SUCC;
}
/*
 * 函 数 名  : hmac_config_11i_remove_key
 * 功能描述  : 处理remove key事件，抛事件到DMAC
 * 1.日    期  : 2014年1月4日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_11i_remove_key(mac_vap_stru *mac_vap, uint16_t len, uint8_t *param)
{
    wlan_priv_key_param_stru *priv_key = NULL;
    uint32_t ret;
    uint8_t key_index;
    uint16_t user_idx = g_wlan_spec_cfg->invalid_user_id;
    mac_removekey_param_stru *removekey_params = (mac_removekey_param_stru *)param;
    wlan_cfgid_enum_uint16 cfgid;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(mac_vap, removekey_params)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_remove_key::mac_vap or param is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 2.1 获取参数 */
    key_index = removekey_params->uc_key_index;

    /* 2.2 索引值最大值检查 */
    if (key_index >= WLAN_NUM_TK + WLAN_NUM_IGTK) {
        /* 内核会下发删除6 个组播密钥，驱动现有6个组播密钥保存空间 */
        /* 对于检测到key idx > 最大密钥数，不做处理 */
        return OAL_SUCC;
    }

     /* 3.1 获取本地密钥信息 */
    priv_key = hmac_get_key_info(mac_vap, removekey_params->auc_mac_addr, removekey_params->en_pairwise,
        removekey_params->uc_key_index, &user_idx);
    if (priv_key == NULL) {
        /* ,用户已经删除返回成功，不然上层因为remove key失败下发踢用户动作，
           用户好不容易再自动关联又被踢，体验不好 */
        if (user_idx == g_wlan_spec_cfg->invalid_user_id) {
            oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_WPA, "{hmac_config_11i_remove_key::user already del.}");
            return OAL_SUCC;
        } else {
            oam_warning_log0(mac_vap->uc_vap_id, OAM_SF_WPA, "{hmac_config_11i_remove_key::priv_key null.}");
            return OAL_ERR_CODE_SECURITY_USER_INVAILD;
        }
    }

    if (priv_key->key_len == 0) {
        /* 如果检测到密钥没有使用， 则直接返回正确 */
        return OAL_SUCC;
    }

    /* 4.1 区分是wep还是wpa */
    if ((WLAN_CIPHER_SUITE_WEP40 == priv_key->cipher) || (WLAN_CIPHER_SUITE_WEP104 == priv_key->cipher)) {
        mac_mib_set_wep(mac_vap, key_index, WLAN_WEP_40_KEY_SIZE);
        cfgid = WLAN_CFGID_REMOVE_WEP_KEY;
    } else {
        ret = hmac_config_11i_remove_wpa_key(mac_vap, removekey_params);
        if (ret != OAL_SUCC) {
            return ret;
        }
        cfgid = WLAN_CFGID_REMOVE_KEY;
    }

    /* 4.2 抛事件到dmac层处理 */
    ret = hmac_config_send_event(mac_vap, cfgid, len, param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_error_log2(mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_remove_key::hmac_config_send_event failed[%d], cfgid=%d .}", ret, cfgid);
        return ret;
    }

    /* 5.1 删除密钥成功，设置密钥长度为0 */
    priv_key->key_len = 0;

    return ret;
}

/*
 * 函 数 名  : hmac_config_11i_set_default_key
 * 功能描述  : 处理set default key事件，抛事件到DMAC
 * 1.日    期  : 2014年1月4日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_config_11i_set_default_key(mac_vap_stru *pst_mac_vap,
    uint16_t us_len, uint8_t *puc_param)
{
    uint32_t ret;
    uint8_t uc_key_index;
    oal_bool_enum_uint8 en_unicast;
    oal_bool_enum_uint8 en_multicast;
    mac_setdefaultkey_param_stru *pst_payload_setdefaultkey_params = NULL;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(pst_mac_vap, puc_param)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_set_default_key::param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 2.1 获取参数 */
    pst_payload_setdefaultkey_params = (mac_setdefaultkey_param_stru *)puc_param;
    uc_key_index = pst_payload_setdefaultkey_params->uc_key_index;
    en_unicast = pst_payload_setdefaultkey_params->en_unicast;
    en_multicast = pst_payload_setdefaultkey_params->en_multicast;

    /* 2.2 索引值最大值检查 */
    if (uc_key_index >= (WLAN_NUM_TK + WLAN_NUM_IGTK)) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_set_default_key::invalid uc_key_index[%d].}",
            uc_key_index);
        return OAL_ERR_CODE_SECURITY_KEY_ID;
    }

    /* 2.3 参数有效性检查 */
    if ((en_multicast == OAL_FALSE) && (en_unicast == OAL_FALSE)) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_config_11i_set_default_key::not ptk or gtk,invalid mode.}");
        return OAL_ERR_CODE_SECURITY_PARAMETERS;
    }

    if (uc_key_index >= WLAN_NUM_TK) {
        /* 3.1 设置default mgmt key属性 */
        ret = mac_vap_set_default_mgmt_key(pst_mac_vap, uc_key_index);
    } else {
        ret = mac_vap_set_default_wep_key(pst_mac_vap, uc_key_index);
    }

    if (ret != OAL_SUCC) {
        oam_error_log2(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                       "{hmac_config_11i_set_default_key::set key[%d] failed[%d].}", uc_key_index, ret);
        return ret;
    }
    oam_info_log3(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
        "{hmac_config_11i_set_default_key::key_id[%d] un[%d] mu[%d] OK}",
        uc_key_index, en_unicast, en_multicast);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_config_11i_add_wep_entry
 * 功能描述  : add wep加密，抛事件到DMAC
 * 1.日    期  : 2013年11月13日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_config_11i_add_wep_entry(mac_vap_stru *pst_mac_vap,
    uint16_t us_len, uint8_t *puc_param)
{
    mac_user_stru *pst_mac_user = NULL;
    uint32_t ret;

    if (oal_any_null_ptr2(pst_mac_vap, puc_param)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_config_11i_add_wep_entry::PARMA NULL}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_mac_user = (mac_user_stru *)mac_vap_get_user_by_addr(pst_mac_vap, puc_param);
    if (pst_mac_user == NULL) {
        oam_error_log0(pst_mac_vap->uc_vap_id, OAM_SF_WPA, "{hmac_config_11i_add_wep_entry::mac_user NULL}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    ret = mac_user_update_wep_key(pst_mac_user, pst_mac_vap->us_multi_user_idx);
    if (ret != OAL_SUCC) {
        oam_error_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                       "{hmac_config_11i_add_wep_entry::mac_wep_add_usr_key failed[%d].}", ret);
        return ret;
    }
    /***************************************************************************
    抛事件到DMAC层, 同步DMAC数据
    ***************************************************************************/
    ret = hmac_config_send_event(pst_mac_vap, WLAN_CFGID_ADD_WEP_ENTRY, us_len, puc_param);
    if (oal_unlikely(ret != OAL_SUCC)) {
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                         "{hmac_config_11i_add_wep_entry::hmac_config_send_event failed[%d].}", ret);
    }

    /* 设置用户的发送加密套件 */
    oam_info_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
                  "{hmac_config_11i_add_wep_entry:: usridx[%d] OK.}", pst_mac_user->us_assoc_id);

    return ret;
}

/*
 * 函 数 名  : hmac_init_security
 * 功能描述  : 初始化加密数据。
 * 1.日    期  : 2013年10月18日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_init_security(mac_vap_stru *pst_mac_vap, uint8_t *puc_addr, uint8_t uc_mac_len)
{
    uint32_t ret = OAL_SUCC;
    uint16_t us_len;
    uint8_t *puc_param = NULL;

    if (pst_mac_vap == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (uc_mac_len != WLAN_MAC_ADDR_LEN) {
        return OAL_FAIL;
    }

    if (OAL_TRUE == mac_is_wep_enabled(pst_mac_vap)) {
        puc_param = puc_addr;
        us_len = WLAN_MAC_ADDR_LEN;
        ret = hmac_config_11i_add_wep_entry(pst_mac_vap, us_len, puc_param);
    }
    return ret;
}

/*
 * 函 数 名  : hmac_check_capability_mac_phy_supplicant
 * 功能描述  : 检测期望join 的AP能力信息是否匹配
 * 1.日    期  : 2013年9月25日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_check_capability_mac_phy_supplicant(mac_vap_stru *pst_mac_vap,
                                                  mac_bss_dscr_stru *pst_bss_dscr)
{
    uint32_t ret;

    if (oal_any_null_ptr2(pst_mac_vap, pst_bss_dscr)) {
        oam_warning_log0(0, OAM_SF_WPA, "{hmac_check_capability_mac_phy_supplicant:: \
            pst_mac_vap or pst_bss_dscr is null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 根据协议模式重新初始化STA HT/VHT mib值 */
    mac_vap_config_vht_ht_mib_by_protocol(pst_mac_vap);

    ret = hmac_check_bss_cap_info(pst_bss_dscr->us_cap_info, pst_mac_vap);
    if (ret != OAL_TRUE) {
        /*  MAC能力不做严格检查 */
        oam_warning_log1(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
            "{hmac_check_capability_mac_phy_supplicant::hmac_check_bss_cap_info failed[%d].}", ret);
    }

    /* check bss capability info PHY,忽略PHY能力不匹配的AP */
    mac_vap_check_bss_cap_info_phy_ap(pst_bss_dscr->us_cap_info, pst_mac_vap);

    return OAL_SUCC;
}

static oal_bool_enum_uint8 hmac_sta_chipher_get_legcy_flag(mac_vap_stru *mac_vap,
                                                           mac_bss_dscr_stru *bss_dscr)
{
    oal_bool_enum_uint8 legcy_only = OAL_FALSE;
    uint32_t pair_suite[WLAN_PAIRWISE_CIPHER_SUITES] = { 0 };

    if (mac_vap->en_protocol >= WLAN_HT_MODE) {
        /* 在WEP / TKIP 加密模式下，不能工作在HT MODE */
        if (mac_mib_get_privacyinvoked(mac_vap) == OAL_TRUE &&
            mac_mib_get_rsnaactivated(mac_vap) == OAL_FALSE) {
            legcy_only = OAL_TRUE;
        }

        if (mac_vap->st_cap_flag.bit_wpa == OAL_TRUE) {
            pair_suite[0] = MAC_WPA_CHIPER_TKIP;

            if (mac_mib_wpa_pair_match_suites_s(mac_vap, pair_suite, sizeof(pair_suite)) != 0) {
                legcy_only = OAL_TRUE;
            }
        }

        if (mac_vap->st_cap_flag.bit_wpa2 == OAL_TRUE) {
            pair_suite[0] = MAC_RSN_CHIPER_TKIP;

            if (mac_mib_rsn_pair_match_suites_s(mac_vap, pair_suite, sizeof(pair_suite)) != 0) {
                legcy_only = OAL_TRUE;
            }
        }

#ifdef _PRE_WLAN_FEATURE_WAPI
        /* 芯片不支持硬件加解密WAPI，关联WAPI网络，则降协议为legacy模式 */
        if ((wlan_chip_is_support_hw_wapi() == OAL_FALSE) && bss_dscr->uc_wapi) {
            legcy_only = OAL_TRUE;
        }
#endif
    }

    return legcy_only;
}

/*
 * 函 数 名  : hmac_sta_protocol_down_by_chipher
 * 功能描述  : 更新STA 加密的mib 信息
 * 1.日    期  : 2016年11月7日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_sta_protocol_down_by_chipher(mac_vap_stru *pst_mac_vap, mac_bss_dscr_stru *pst_bss_dscr)
{
    mac_cfg_mode_param_stru st_cfg_mode;
    oal_bool_enum_uint8 en_legcy_only;

    en_legcy_only = hmac_sta_chipher_get_legcy_flag(pst_mac_vap, pst_bss_dscr);

    oam_warning_log3(pst_mac_vap->uc_vap_id, OAM_SF_WPA,
        "hmac_sta_protocol_down_by_chipher::legacy_only[%d],wpa[%d]wpa2[%d]",
        en_legcy_only, pst_mac_vap->st_cap_flag.bit_wpa, pst_mac_vap->st_cap_flag.bit_wpa2);

    st_cfg_mode.en_protocol = pst_mac_vap->en_protocol;

    if (en_legcy_only == OAL_TRUE) {
        if (WLAN_BAND_2G == pst_mac_vap->st_channel.en_band) {
            st_cfg_mode.en_protocol = WLAN_MIXED_ONE_11G_MODE;
            pst_mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_20M;
        }
        if (WLAN_BAND_5G == pst_mac_vap->st_channel.en_band) {
            st_cfg_mode.en_protocol = WLAN_LEGACY_11A_MODE;
            pst_mac_vap->st_channel.en_bandwidth = WLAN_BAND_WIDTH_20M;
        }
    }

    if (st_cfg_mode.en_protocol >= WLAN_HT_MODE) {
        mac_mib_set_TxAggregateActived(pst_mac_vap, OAL_TRUE);
        mac_mib_set_AmsduAggregateAtive(pst_mac_vap, OAL_TRUE);
    } else {
        mac_mib_set_TxAggregateActived(pst_mac_vap, OAL_FALSE);
        mac_mib_set_AmsduAggregateAtive(pst_mac_vap, OAL_FALSE);
    }

    mac_vap_init_by_protocol(pst_mac_vap, st_cfg_mode.en_protocol);

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_en_mic
 * 功能描述  : 增加mic校验码
 * 1.日    期  : 2014年1月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_en_mic(hmac_vap_stru *pst_hmac_vap, hmac_user_stru *pst_hmac_user,
    oal_netbuf_stru *pst_netbuf, uint8_t *puc_iv_len)
{
    wlan_priv_key_param_stru *pst_key = NULL;
    uint32_t ret;
    wlan_ciper_protocol_type_enum_uint8 en_cipher_type;
    wlan_cipher_key_type_enum_uint8 en_key_type;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr4(pst_hmac_vap, pst_hmac_user, pst_netbuf, puc_iv_len)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_en_mic::input param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    *puc_iv_len = 0;
    en_key_type = pst_hmac_user->st_user_base_info.st_user_tx_info.st_security.en_cipher_key_type;
    en_cipher_type = pst_hmac_user->st_user_base_info.st_key_info.en_cipher_type;
    pst_key = mac_user_get_key(&pst_hmac_user->st_user_base_info,
        pst_hmac_user->st_user_base_info.st_key_info.uc_default_index);
    if (pst_key == NULL) {
        oam_error_log1(0, OAM_SF_WPA, "{hmac_en_mic::mac_user_get_key FAIL. en_key_type[%d]}", en_key_type);
        return OAL_ERR_CODE_SECURITY_KEY_ID;
    }

    switch (en_cipher_type) {
        case WLAN_80211_CIPHER_SUITE_TKIP:
            if (en_key_type == 0 || en_key_type > 5) { // 5代表无效的秘钥类型
                return OAL_ERR_CODE_SECURITY_KEY_TYPE;
            }
            ret = hmac_crypto_tkip_enmic(pst_key, pst_netbuf);
            if (ret != OAL_SUCC) {
                oam_error_log1(pst_hmac_vap->st_vap_base_info.uc_vap_id, OAM_SF_WPA,
                               "{hmac_en_mic::hmac_crypto_tkip_enmic failed[%d].}", ret);
                return ret;
            }
            *puc_iv_len = WEP_IV_FIELD_SIZE + EXT_IV_FIELD_SIZE;
            break;
        case WLAN_80211_CIPHER_SUITE_CCMP:
            *puc_iv_len = WEP_IV_FIELD_SIZE + EXT_IV_FIELD_SIZE;
            break;
        default:
            break;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_de_mic
 * 功能描述  : mic码校验
 * 1.日    期  : 2014年1月23日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
uint32_t hmac_de_mic(hmac_user_stru *pst_hmac_user, oal_netbuf_stru *pst_netbuf)
{
    wlan_priv_key_param_stru *pst_key = NULL;
    uint32_t ret;
    wlan_ciper_protocol_type_enum_uint8 en_cipher_type;
    wlan_cipher_key_type_enum_uint8 en_key_type;

    /* 1.1 入参检查 */
    if (oal_any_null_ptr2(pst_hmac_user, pst_netbuf)) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_de_mic::param null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    en_key_type = pst_hmac_user->st_user_base_info.st_user_tx_info.st_security.en_cipher_key_type;
    en_cipher_type = pst_hmac_user->st_user_base_info.st_key_info.en_cipher_type;
    pst_key = mac_user_get_key(&pst_hmac_user->st_user_base_info,
        pst_hmac_user->st_user_base_info.st_key_info.uc_default_index);
    if (pst_key == NULL) {
        oam_error_log1(0, OAM_SF_WPA, "{hmac_de_mic::mac_user_get_key FAIL. en_key_type[%d]}", en_key_type);
        return OAL_ERR_CODE_SECURITY_KEY_ID;
    }

    switch (en_cipher_type) {
        case WLAN_80211_CIPHER_SUITE_TKIP:
            if (en_key_type == 0 || en_key_type > 5) { // 大于5代表无效的秘钥类型
                return OAL_ERR_CODE_SECURITY_KEY_TYPE;
            }
            ret = hmac_crypto_tkip_demic(pst_key, pst_netbuf);
            if (ret != OAL_SUCC) {
                oam_error_log1(pst_hmac_user->st_user_base_info.uc_vap_id, OAM_SF_WPA,
                               "{hmac_de_mic::hmac_crypto_tkip_demic failed[%d].}", ret);
                return ret;
            }
            break;
        default:
            break;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_rx_tkip_mic_failure_process
 * 功能描述  : ap 和 sta 接收到MIC fail 事件处理
 * 1.日    期  : 2013年8月28日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_rx_tkip_mic_failure_process(frw_event_mem_stru *pst_event_mem)
{
    frw_event_stru *pst_event = NULL;
    frw_event_mem_stru *pst_hmac_event_mem = NULL;
    frw_event_hdr_stru *pst_event_hdr = NULL;
    dmac_to_hmac_mic_event_stru *pst_mic_event = NULL;

    if (pst_event_mem == NULL) {
        oam_error_log0(0, OAM_SF_WPA, "{hmac_rx_tkip_mic_failure_process::pst_event_mem null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 获取事件头和事件结构体指针 */
    pst_event = frw_get_event_stru(pst_event_mem);
    pst_event_hdr = &(pst_event->st_event_hdr);
    pst_mic_event = (dmac_to_hmac_mic_event_stru *)&(pst_event->auc_event_data);

    /* 将mic事件抛到WAL */
    pst_hmac_event_mem = frw_event_alloc_m(sizeof(dmac_to_hmac_mic_event_stru));
    if (pst_hmac_event_mem == NULL) {
        oam_error_log0(pst_event_hdr->uc_vap_id, OAM_SF_WPA,
            "{hmac_rx_tkip_mic_failure_process::pst_hmac_event_mem null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 填写事件 */
    pst_event = frw_get_event_stru(pst_hmac_event_mem);

    frw_event_hdr_init(&(pst_event->st_event_hdr),
                       FRW_EVENT_TYPE_HOST_CTX,
                       HMAC_HOST_CTX_EVENT_SUB_TYPE_MIC_FAILURE,
                       sizeof(dmac_to_hmac_mic_event_stru),
                       FRW_EVENT_PIPELINE_STAGE_0,
                       pst_event_hdr->uc_chip_id,
                       pst_event_hdr->uc_device_id,
                       pst_event_hdr->uc_vap_id);

    /* 去关联的STA mac地址 */
    if (EOK != memcpy_s((uint8_t *)frw_get_event_payload(pst_hmac_event_mem), sizeof(dmac_to_hmac_mic_event_stru),
        (uint8_t *)pst_mic_event, sizeof(dmac_to_hmac_mic_event_stru))) {
        oam_error_log0(0, OAM_SF_WPA, "hmac_rx_tkip_mic_failure_process::memcpy fail!");
        frw_event_free_m(pst_hmac_event_mem);
        return OAL_FAIL;
    }

    /* 分发事件 */
    frw_event_dispatch_event(pst_hmac_event_mem);
    frw_event_free_m(pst_hmac_event_mem);
    return OAL_SUCC;
}

/*
 * 函 数 名  : hmac_11i_port_filter
 * 功能描述  : 接收数据，安全相关过滤
 * 1.日    期  : 2014年1月6日
  *   修改内容  : 新生成函数
 */
uint32_t hmac_11i_ether_type_filter(hmac_vap_stru *pst_vap,
    hmac_user_stru *pst_hmac_user, uint16_t us_ether_type)
{
    if (mac_user_get_port(&pst_hmac_user->st_user_base_info) == OAL_FALSE) { /* 判断端口是否打开 */
        /* 接收数据时，针对非EAPOL 的数据帧做过滤 */
#ifdef _PRE_WLAN_FEATURE_PWL
        if ((oal_byteorder_host_to_net_uint16(ETHER_TYPE_PAE) != us_ether_type) &&
            (oal_byteorder_host_to_net_uint16(ETHER_TYPE_WAI) != us_ether_type)) {
#else
        if (oal_byteorder_host_to_net_uint16(ETHER_TYPE_PAE) != us_ether_type) {
#endif
            oam_warning_log1(pst_vap->st_vap_base_info.uc_vap_id, OAM_SF_WPA,
                "{hmac_11i_ether_type_filter::TYPE 0x%04x not permission.}", us_ether_type);
            return OAL_ERR_CODE_SECURITY_PORT_INVALID;
        }
    }

    return OAL_SUCC;
}

