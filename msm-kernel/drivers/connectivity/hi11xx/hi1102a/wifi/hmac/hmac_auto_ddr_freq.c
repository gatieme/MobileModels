/*
 * 版权所有 (c) 华为技术有限公司 2019-2019
 * 功能说明 : Host侧DDR调频相关函数实现
 * 作    者 : g00428180
 * 创建日期 : 2019年4月10日
 */
/* 1 头文件包含 */
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION) && (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_HOST)
#include "hmac_auto_ddr_freq.h"
#include <linux/pm_qos.h>
#endif
#include "hmac_statistic_data_flow.h"
#include "external/oal_pm_qos_interface.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_AUTO_DDR_FREQ_C

/* 2 全局变量定义 */
volatile hmac_auto_ddr_freq_mgmt_stru g_st_auto_ddr_freq_mgmt = { 0 };

/* 3 函数实现 */
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION) && (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1102A_HOST)
/*
 * 函 数 名  : hmac_remove_ddr_freq_req
 * 功能描述  : 移除内核ddr调频请求
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
OAL_STATIC oal_void hmac_remove_ddr_freq_req(oal_void)
{
    if (g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq == OAL_PTR_NULL) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_add_ddr_freq_req::remove ddr freq req from kernel FAIL!}");
        return;
    }

    oal_pm_qos_remove_request(g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq);

    oam_warning_log0(0, OAM_SF_ANY, "{hmac_remove_ddr_freq_req::remove ddr freq req from kernel SUCC!}");
}

/*
 * 函 数 名  : hmac_add_ddr_freq_req
 * 功能描述  : 向内核发起ddr调频请求
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
OAL_STATIC oal_void hmac_add_ddr_freq_req(oal_void)
{
    if (g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq == OAL_PTR_NULL) {
        oam_warning_log0(0, OAM_SF_ANY, "{hmac_add_ddr_freq_req::add ddr freq req to kernel FAIL!}");
        return;
    }
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0))
    oal_pm_qos_add_request(g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq, PM_QOS_MEMORY_THROUGHPUT, HMAC_DDR_MAX_FREQ);
#endif
    oam_warning_log0(0, OAM_SF_ANY, "{hmac_add_ddr_freq_req::add ddr freq req to kernel SUCC!}");
}

/*
 * 函 数 名  : hmac_auto_ddr_init
 * 功能描述  : 初始化host侧DDR自动调频
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
oal_void hmac_auto_ddr_init(oal_void)
{
    g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq = kzalloc(sizeof(struct pm_qos_request), GFP_KERNEL);
    if (g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq == OAL_PTR_NULL) {
        OAL_IO_PRINT("{hmac_auto_ddr_init::auto ddr init failed!}");
        return;
    }

    g_st_auto_ddr_freq_mgmt.en_auto_ddr_freq_switch = OAL_TRUE;
}

/*
 * 函 数 名  : hmac_auto_ddr_exit
 * 功能描述  : 退出host侧DDR自动调频
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
oal_void hmac_auto_ddr_exit(oal_void)
{
    hmac_remove_ddr_freq_req();
    kfree(g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq);

    g_st_auto_ddr_freq_mgmt.pst_auto_ddr_freq = OAL_PTR_NULL;
    g_st_auto_ddr_freq_mgmt.en_auto_ddr_freq_switch = OAL_FALSE;
}

/*
 * 函 数 名  : hmac_get_ddr_freq_update_type
 * 功能描述  : 根据pps统计及是否已更新频率, 得到当前应进行的操作
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
OAL_STATIC hmac_auto_ddr_freq_update_enum hmac_get_ddr_freq_update_type(oal_uint32 ul_total_pps)
{
    if ((ul_total_pps > g_st_auto_ddr_freq_mgmt.ul_auto_ddr_freq_pps_th_high) &&
        !g_st_auto_ddr_freq_mgmt.en_ddr_freq_updated) {
        g_st_auto_ddr_freq_mgmt.en_ddr_freq_updated = OAL_TRUE;
        return HMAC_AUTO_DDR_FREQ_ADD_REQUEST;
    } else if ((ul_total_pps < g_st_auto_ddr_freq_mgmt.ul_auto_ddr_freq_pps_th_low) &&
               g_st_auto_ddr_freq_mgmt.en_ddr_freq_updated) {
        g_st_auto_ddr_freq_mgmt.en_ddr_freq_updated = OAL_FALSE;
        return HMAC_AUTO_DDR_FREQ_REMOVE_REQUEST;
    } else {
        return HMAC_AUTO_DDR_FREQ_RETURN;
    }
}

/*
 * 函 数 名  : hmac_auto_set_ddr_freq
 * 功能描述  : Host侧动态DDR调频入口, 根据pps统计调整DDR频率
 * 修改历史  :
 * 1.日    期  : 2019年4月10日
 *   作    者  : g00428180
 *   修改内容  : 新生成函数
 */
oal_void hmac_auto_set_ddr_freq(oal_uint32 ul_total_pps)
{
    hmac_auto_ddr_freq_update_enum en_update_type;

    if (!g_st_auto_ddr_freq_mgmt.en_auto_ddr_freq_switch) {
        return;
    }
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_spin_lock_bh(&(g_st_wifi_rxtx_statis.st_txrx_opt_lock));
#endif
    en_update_type = hmac_get_ddr_freq_update_type(ul_total_pps);
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_spin_unlock_bh(&(g_st_wifi_rxtx_statis.st_txrx_opt_lock));
#endif

    switch (en_update_type) {
        case HMAC_AUTO_DDR_FREQ_ADD_REQUEST:
            hmac_add_ddr_freq_req();
            break;
        case HMAC_AUTO_DDR_FREQ_REMOVE_REQUEST:
            hmac_remove_ddr_freq_req();
            break;
        case HMAC_AUTO_DDR_FREQ_RETURN:
        default:
            break;
    }
}

#endif

