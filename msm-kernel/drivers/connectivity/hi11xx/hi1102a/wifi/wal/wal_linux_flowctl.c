/*
 * 版权所有 (c) 华为技术有限公司 2001-2011
 * 功能描述 : wal_linux_flowctl.c
 * 作    者 : x00189397
 * 生成日期 : 2014年3月3日
 */

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "oal_ext_if.h"
#include "oal_util.h"
#include "frw_ext_if.h"

#include "mac_vap.h"
#include "mac_device.h"
#include "mac_resource.h"

#include "hmac_ext_if.h"

#include "wal_main.h"
#include "wal_linux_flowctl.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_WAL_LINUX_FLOWCTL_C

/* lint +e830 */ /* lint +e550 */
/*
 * 函 数 名  : wal_netdev_select_queue
 * 功能描述  : kernel给skb选择合适的tx subqueue;
 * 修改历史  :
 * 1.日    期  : 2015年3月17日
 *   作    者  : xiechunhui
 *   修改内容  : 新生成函数
 */
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 1, 0))
uint16_t wal_netdev_select_queue(oal_net_device_stru *pst_dev, oal_netbuf_stru *pst_buf)
#elif (LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0))
uint16_t wal_netdev_select_queue(oal_net_device_stru *pst_dev, oal_netbuf_stru *pst_buf,
    void *accel_priv, select_queue_fallback_t fallback)
#elif(LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
uint16_t wal_netdev_select_queue(oal_net_device_stru *pst_dev, oal_netbuf_stru *pst_buf,
    oal_net_device_stru *pst_buf_dev)
#else
uint16_t wal_netdev_select_queue(oal_net_device_stru *pst_dev, oal_netbuf_stru *pst_buf,
    oal_net_device_stru *pst_buf_dev, select_queue_fallback_t fallback)
#endif /* (LINUX_VERSION_CODE < KERNEL_VERSION(4,1,0)) */
{
    return oal_netbuf_select_queue(pst_buf);
}


