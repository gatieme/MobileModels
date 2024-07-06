/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Description: IOCTL command handler.
 * Author: jiaqinyong@huawei.com
 * Create: 2019-12-05
 */

#ifndef BASTET_IOCTL_HANDLER_H
#define BASTET_IOCTL_HANDLER_H

/* Common Params */
{ 0, NULL, "null" },
{ BST_IOC_SOCK_SYNC_START_ID, handle_bst_ioc_sock_sync_start,
	"BST_IOC_SOCK_SYNC_START" },
{ BST_IOC_SOCK_SYNC_STOP_ID, handle_bst_ioc_sock_sync_stop,
	"BST_IOC_SOCK_SYNC_STOP" },
{ BST_IOC_SOCK_SYNC_SET_ID, handle_bst_ioc_sock_sync_set,
	"BST_IOC_SOCK_SYNC_SET" },
{ BST_IOC_SOCK_COMM_GET_ID, handle_bst_ioc_sock_comm_get,
	"BST_IOC_SOCK_COMM_GET" },
{ BST_IOC_SOCK_CLOSE_SET_ID, handle_bst_ioc_sock_close_set,
	"BST_IOC_SOCK_CLOSE_SET" },
{ BST_IOC_SOCK_STATE_GET_ID, handle_bst_ioc_sock_state_get,
	"BST_IOC_SOCK_STATE_GET" },
{ BST_IOC_APPLY_LOCAL_PORT_ID, handle_bst_ioc_apply_local_port,
	"BST_IOC_APPLY_LOCAL_PORT" },
{ BST_IOC_RELEASE_LOCAL_PORT_ID, handle_bst_ioc_release_local_port,
	"BST_IOC_RELEASE_LOCAL_PORT" },
{ BST_IOC_SET_TRAFFIC_FLOW_ID, handle_bst_ioc_set_traffic_flow,
	"BST_IOC_SET_TRAFFIC_FLOW" },
{ BST_IOC_GET_TIMESTAMP_INFO_ID, handle_bst_ioc_get_timestamp_info,
	"BST_IOC_GET_TIMESTAMP_INFO" },
{ BST_IOC_SET_NET_DEV_NAME_ID, handle_bst_ioc_set_net_dev_name,
	"BST_IOC_SET_NET_DEV_NAME" },
{ BST_IOC_GET_MODEM_RAB_ID_ID, handle_bst_ioc_get_modem_rab_id,
	"BST_IOC_GET_MODEM_RAB_ID" },
{ BST_IOC_SOCK_RECONN_SET_ID, handle_bst_ioc_sock_reconn_set,
	"BST_IOC_SOCK_RECONN_SET" },
{ BST_IOC_SOCK_RECONN_FAIL_ID, handle_bst_ioc_sock_reconn_fail,
	"BST_IOC_SOCK_RECONN_FAIL" },
{ BST_IOC_SET_RECONN_PROXYID_ID, handle_bst_ioc_set_reconn_proxyid,
	"BST_IOC_SET_RECONN_PROXYID" },
{ BST_IOC_SYNC_PROP_START_ID, handle_bst_ioc_sync_prop_start,
	"BST_IOC_SYNC_PROP_START" },
{ BST_IOC_SYNC_PROP_STOP_ID, handle_bst_ioc_sync_prop_stop,
	"BST_IOC_SYNC_PROP_STOP" },
{ BST_IOC_PROXY_AVAILABLE_ID, handle_bst_ioc_proxy_available,
	"BST_IOC_PROXY_AVAILABLE" },
{ BST_IOC_BUF_AVAILABLE_ID, handle_bst_ioc_buf_available,
	"BST_IOC_BUF_AVAILABLE" },
{ BST_IOC_PRIO_SEND_SUC_ID, handle_bst_ioc_prio_send_suc,
	"BST_IOC_PRIO_SEND_SUC" },
{ BST_IOC_SOCK_SYNC_PREPARE_ID, handle_bst_ioc_sock_sync_prepare,
	"BST_IOC_SOCK_SYNC_PREPARE" },
{ BST_IOC_GET_FD_BY_ADDR_ID, handle_bst_ioc_get_fd_by_addr,
	"BST_IOC_GET_FD_BY_ADDR" },
{ BST_IOC_GET_CMDLINE_ID, handle_bst_ioc_get_cmdline,
	"BST_IOC_GET_CMDLINE" },
{ BST_IOC_SYNC_HOLD_TIME_ID, handle_bst_ioc_sync_hold_time,
	"BST_IOC_SYNC_HOLD_TIME" },
{ BST_IOC_NET_DEV_RESET_ID, handle_bst_ioc_net_dev_reset,
	"BST_IOC_NET_DEV_RESET" },
{ BST_IOC_UID_PROP_MONITOR_ID, handle_bst_ioc_uid_prop_monitor,
	"BST_IOC_UID_PROP_MONITOR" },
{ BST_IOC_SET_HRTAPP_ACTIVITY_ID, handle_bst_ioc_set_hrtapp_activity,
	"BST_IOC_SET_HRTAPP_ACTIVITY" },
{ BST_IOC_FAST_GRAB_INFO_ID, handle_bst_ioc_fg_io_ctrl,
	"BST_IOC_FAST_GRAB_INFO" },
{ BST_IOC_SET_PROC_INFO_ID, handle_bst_ioc_set_proc_info,
	"BST_IOC_SET_PROC_INFO" },
{ BST_IOC_SET_SPECIAL_UID_ID, handle_bst_ioc_set_special_uid,
	"BST_IOC_SET_SPECIAL_UID" },
{ BST_IOC_NF_CONTROL_ID, handle_bst_ioc_nf_control,
	"BST_IOC_NF_CONTROL" },
{ BST_IOC_GET_SOCK_NETDEV_NAME_ID, handle_bst_ioc_get_sock_netdev_name,
	"BST_IOC_GET_SOCK_NETDEV_NAME" },
{ BST_IOC_SEND_HB_DATA_ID, handle_bst_ioc_send_hb_data,
	"BST_IOC_SEND_HB_DATA" },
{ BST_IOC_SET_HB_REPLY_ID, handle_bst_ioc_set_hb_reply,
	"BST_IOC_SET_HB_REPLY" },
{ BST_IOC_FILTER_HB_REPLY_ID, handle_bst_ioc_filter_hb_reply,
	"BST_IOC_FILTER_HB_REPLY" },
{ BST_IOC_SET_FREEZER_STATE_ID, handle_bst_ioc_set_freezer_state,
	"BST_IOC_SET_FREEZER_STATE" },
{ BST_IOC_SET_PRIO_CH_ENABLE_ID, handle_bst_ioc_set_prio_ch_enable,
	"BST_IOC_SET_PRIO_CH_ENABLE" },
{ BST_IOC_SOCK_COMM_GET_IPV6_ID, handle_bst_ioc_sock_comm_get_ipv6,
	"BST_IOC_SOCK_COMM_GET_IPV6" },
{ BST_IOC_SOCK_SYNC_SET_IPV6_ID, handle_bst_ioc_sock_sync_set_ipv6,
	"BST_IOC_SOCK_SYNC_SET_IPV6" },
{ BST_IOC_SOCK_CLOSE_SET_IPV6_ID, handle_bst_ioc_sock_close_set_ipv6,
	"BST_IOC_SOCK_CLOSE_SET_IPV6" },
{ BST_IOC_SYNC_PROP_START_IPV6_ID, handle_bst_ioc_sync_prop_start_ipv6,
	"BST_IOC_SYNC_PROP_START_IPV6" },
{ BST_IOC_SYNC_PROP_STOP_IPV6_ID, handle_bst_ioc_sync_prop_stop_ipv6,
	"BST_IOC_SYNC_PROP_STOP_IPV6" },
{ BST_IOC_GET_MODEM_RAB_ID_IPV6, handle_bst_ioc_get_ipv6_modem_rab_id,
	"BST_IOC_GET_MODEM_RAB_ID_IPV6" },
{ BST_IOC_CHECK_MAC_ADDRESS_AVAILABLE_ID, handle_bst_ioc_check_mac_address_available,
	"BST_IOC_CHECK_MAC_ADDRESS_AVAILABLE" },

#endif
