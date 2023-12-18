/*
 * ��Ȩ���� (c) ��Ϊ�������޹�˾ 2001-2011
 * �������� : WAL linux�Ž��ļ�
 * ��    �� : x00189397
 * �������� : 2014��3��3��
 */

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "oam_ext_if.h"
#include "frw_ext_if.h"
#ifdef _PRE_WLAN_FEATURE_ALWAYS_TX
#include "hal_ext_if.h"
#endif
#include "hmac_vap.h"
#include "mac_vap.h"
#include "mac_resource.h"
#include "mac_data.h"
#include "hmac_ext_if.h"
#include "wal_main.h"
#include "wal_linux_bridge.h"
#ifdef _PRE_WLAN_FEATURE_BTCOEX
#include "hmac_device.h"
#include "hmac_resource.h"
#endif

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_WAL_LINUX_BRIDGE_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/
/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/
/*
 * �� �� ��  : wal_bridge_vap_xmit
 * ��������  : �ҽӵ�VAP��Ӧnet_device�ṹ���µķ��ͺ���
 * �޸���ʷ  :
 * 1.��    ��  : 2012��11��6��
 *   ��    ��  : zhangheng
 *   �޸�����  : �����ɺ���
 */
oal_uint8    g_sk_pacing_shift = 6;

oal_net_dev_tx_enum  wal_bridge_vap_xmit(oal_netbuf_stru *pst_buf, oal_net_device_stru *pst_dev)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (oal_unlikely(skb_linearize(pst_buf))) {
        oam_warning_log0(0, OAM_SF_TX, "{wal_bridge_vap_xmit::[GSO] failed at skb_linearize}");
        oal_netbuf_free(pst_buf);
        return OAL_NETDEV_TX_OK;
    }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,9,0))
    sk_pacing_shift_update(pst_buf->sk, g_sk_pacing_shift);
#endif
#endif /* _PRE_OS_VERSION_LINUX == _PRE_OS_VERSION */

    return hmac_bridge_vap_xmit(pst_buf, pst_dev);
}
oal_module_symbol(wal_bridge_vap_xmit);
