/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明 : WIFI 资源限制实现
 * 作    者 :
 * 创建日期 : 2023年2月1日
 */

#include "hmac_resource_restriction.h"
#include "mac_device.h"
#include "mac_vap.h"
#include "mac_resource.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RESOURCE_RESTRICTION_C

/* 功能描述：判断当前是否2vap_ap 场景
 * 返回值：TRUE:是2vap_ap工作场景；FALSE：非2vap_ap 工作场景
 */
oal_bool_enum_uint8 hmac_res_restriction_is_ap_with_other_vap(void)
{
    mac_device_stru *mac_device = mac_res_get_mac_dev();
    mac_vap_stru *up_vap_array[WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE] = { NULL };
    uint32_t up_vap_num;
    uint32_t idx;
    uint32_t have_legacy_ap = OAL_FALSE;
    uint32_t have_other_vap = OAL_FALSE;
    up_vap_num = mac_device_find_up_vaps(mac_device, up_vap_array, WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE);
    for (idx = 0; idx < up_vap_num; idx++) {
        mac_vap_stru *tmp_vap = up_vap_array[idx];
        if (is_legacy_ap(tmp_vap) == OAL_TRUE && mac_is_chba_mode(tmp_vap) == OAL_FALSE) {
            have_legacy_ap = OAL_TRUE;
        } else {
            have_other_vap = OAL_TRUE;
        }
    }
    return (have_legacy_ap == OAL_TRUE && have_other_vap == OAL_TRUE) ? OAL_TRUE : OAL_FALSE;
}
