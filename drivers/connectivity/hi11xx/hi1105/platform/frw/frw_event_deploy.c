/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: module for event deployment, inter-core communication and external interfaces
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "frw_main.h"
#include "frw_event_deploy.h"
#include "securec.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_FRW_EVENT_DEPLOY_C

/* ipc全局结构体:每个核一个,AMP情况下当前只考虑双核场景 */
OAL_STATIC frw_ipc_node_stru g_ipc_node[FRW_IPC_CORE_TYPE_BUTT];

/* 主核发送给从核的消息队列 */
OAL_STATIC frw_ipc_msg_queue_stru g_queue_master_to_slave;

/* 从核发送给主核的消息队列 */
OAL_STATIC frw_ipc_msg_queue_stru g_queue_slave_to_master;

/* IPC接口 */
OAL_STATIC uint32_t frw_ipc_init(void);
OAL_STATIC uint32_t frw_ipc_init_master(frw_ipc_node_stru *pst_ipc_node);
OAL_STATIC uint32_t frw_ipc_init_slave(frw_ipc_node_stru *pst_ipc_node);
OAL_STATIC uint32_t frw_ipc_exit(void);
OAL_STATIC void frw_ipc_recv(frw_ipc_msg_mem_stru *pst_ipc_mem_msg);
OAL_STATIC uint32_t frw_ipc_send(frw_ipc_msg_mem_stru *pst_ipc_mem_msg);
OAL_STATIC uint32_t frw_ipc_send_connect_request(void);
OAL_STATIC uint32_t frw_ipc_send_connect_response(void);
OAL_STATIC uint32_t frw_ipc_send_inter_msg(uint8_t uc_msg_type, uint8_t *puc_data, uint8_t us_len);
OAL_STATIC void frw_ipc_tx_complete(frw_ipc_msg_mem_stru *pst_msg);
OAL_STATIC uint32_t frw_ipc_event_queue_full(void);
OAL_STATIC uint32_t frw_ipc_event_queue_empty(void);

/* 事件部署接口 */
OAL_STATIC uint32_t frw_event_deploy_pipeline(oal_mem_stru *pst_mem_event,
                                              uint8_t *en_deploy_result);

/*
 * 函 数 名  : frw_ipc_proc_msg
 * 功能描述  : 根据ipc消息类型处理消息
 * 输入参数  : pst_ipc_mem_msg: 消息结构体指针, pst_header：消息头
 */
OAL_STATIC void frw_ipc_proc_msg(frw_ipc_msg_mem_stru *pst_ipc_mem_msg,
                                 frw_ipc_msg_header_stru *pst_header,
                                 uint8_t en_type)
{
    switch (pst_header->uc_msg_type) {
        case FRW_IPC_MSG_TYPE_EVENT:

            /* 在IPC发送时被偏移到IPC头部位置，所以这里需要再偏移到事件结构体位置 */
            pst_ipc_mem_msg->puc_data += FRW_IPC_MSG_HEADER_LENGTH;

            /* 事件直接入队操作: ipc暂不支持context, 直接先设置为NULL */
            frw_event_post_event_ctx(pst_ipc_mem_msg, oal_get_core_id(), CUR_OAL_MEM_CONTEXT);

            break;

        case FRW_IPC_MSG_TYPE_TX_INT_ENABLE:
            /* 修改发送状态控制标识，原子操作 */
            g_ipc_node[en_type].en_tx_int_ctl = FRW_IPC_TX_CTRL_ENABLED;

            break;

        case FRW_IPC_MSG_TYPE_TX_INT_DISENABLE:
            /* 修改发送状态控制标识，原子操作 */
            g_ipc_node[en_type].en_tx_int_ctl = FRW_IPC_TX_CTRL_DISABLED;

            break;

        case FRW_IPC_MSG_TYPE_CONNECT_REQUEST:
            /* 发送连接响应 */
            frw_ipc_send_connect_response();

            break;

        case FRW_IPC_MSG_TYPE_CONNECT_RESPONSE:
            /* 修改状态，原子操作 */
            g_ipc_node[en_type].en_states = FRW_IPC_CORE_STATE_CONNECTED;

            break;

        case FRW_IPC_MSG_TYPE_CONFIG_REQUEST:
        case FRW_IPC_MSG_TYPE_CONFIG_RESPONSE:
        case FRW_IPC_MSG_TYPE_ERROR_NOTICE:
        case FRW_IPC_MSG_TYPE_RESET_REQUEST:
        case FRW_IPC_MSG_TYPE_RESET_RESPONSE:
        case FRW_IPC_MSG_TYPE_OPEN_OAM:
        case FRW_IPC_MSG_TYPE_CLOSE_OAM:
        case FRW_IPC_MSG_TYPE_EXIT_REQUEST:
        case FRW_IPC_MSG_TYPE_EXIT_RESPONSE:
        default:
            break;
    }
}

/*
 * 函 数 名  : frw_ipc_recv
 * 功能描述  : 消息接收处理，运行在中断上下文环境，不能加锁
 * 输入参数  : pst_ipc_mem_msg: 消息结构体指针
 */
OAL_STATIC void frw_ipc_recv(frw_ipc_msg_mem_stru *pst_ipc_mem_msg)
{
    frw_ipc_msg_header_stru *pst_header = NULL;  /* 消息头部结构体 */
    uint8_t en_type; /* CPU类型: 主核或从核 */

    /* 入参检查 */
    if (oal_unlikely(pst_ipc_mem_msg == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_ipc_recv::NULL == pst_ipc_mem_msg}\r\n");
        return;
    }

    /* 获取信息头部, 在IPC发送时已经挪了puc_data指针，此处该指针已指向IPC头 */
    pst_header = (frw_ipc_msg_header_stru *)(pst_ipc_mem_msg->puc_data);
    if (oal_unlikely(pst_header == NULL ||
                     pst_header->uc_target_cpuid > FRW_IPC_CORE_NUM_BUTT ||
                     pst_header->uc_msg_type > FRW_IPC_MSG_TYPE_BUTT)) {
        oam_error_log0(0, OAM_SF_FRW, "{pst_header is incorrect.}");
        return;
    }

    /* 获取当前内核信息 */
    en_type = frw_ipc_get_core_type();
    /* 判断seq number是否正确 */
    if (oal_likely(g_ipc_node[en_type].us_seq_num_rx_expect == pst_header->us_seq_number)) {
        g_ipc_node[en_type].us_seq_num_rx_expect++; /* 该变量只有在这里读写 */
    } else if (g_ipc_node[en_type].us_seq_num_rx_expect < pst_header->us_seq_number) {
        /* 期望下次收到是匹配的 */
        g_ipc_node[en_type].us_seq_num_rx_expect = pst_header->us_seq_number + 1;
    } else {
        /* 说明溢出且丢包了, 期望下次收到是匹配的 */
        g_ipc_node[en_type].us_seq_num_rx_expect = pst_header->us_seq_number + 1;
    }
    /* 处理消息 */
    frw_ipc_proc_msg(pst_ipc_mem_msg, pst_header, en_type);

    /* 释放消息, ipc暂时不支持ctx */
    frw_event_free_append_line(pst_ipc_mem_msg, CUR_OAL_MEM_CONTEXT);
}

/*
 * 函 数 名  : frw_ipc_send
 * 功能描述  : 对外接口, 发送核间消息, 消息内容为事件, 调用该函数后可以释放内存
 * 输入参数  : pst_ipc_mem_msg: 消息结构体指针
 */
OAL_STATIC uint32_t frw_ipc_send(frw_ipc_msg_mem_stru *pst_ipc_mem_msg)
{
    uint32_t ul_ret;
    frw_ipc_msg_header_stru *pst_header = NULL;   /* 消息头部结构体 */
    frw_ipc_msg_queue_stru *pst_msg_queue = NULL; /* 消息队列 */
    uint8_t en_type;  /* CPU类型: 主核或从核 */

    /* 获取当前内核信息 */
    en_type = frw_ipc_get_core_type();
    frw_ipc_get_msg_queue(pst_msg_queue, en_type);

    /* 检查当前IPC模块状态 */
    if (g_ipc_node[en_type].en_states != FRW_IPC_CORE_STATE_CONNECTED) {
        oam_warning_log2(0, OAM_SF_FRW,
            "{frw_ipc_send::FRW_IPC_CORE_STATE_CONNECTED != g_ipc_node[en_type].en_states. en_type:%d, en_states:%d}",
            en_type, g_ipc_node[en_type].en_states);
        return OAL_FAIL;
    }

    /* 获取IPC头部 */
    pst_header = (frw_ipc_msg_header_stru *)frw_ipc_get_header(pst_ipc_mem_msg);

    /* 核间消息头部填充 */
    pst_header->us_seq_number = g_ipc_node[en_type].us_seq_num_tx_expect;
    pst_header->uc_target_cpuid = g_ipc_node[en_type].en_target_cpuid;
    pst_header->uc_msg_type = FRW_IPC_MSG_TYPE_EVENT;

    /* 发送核间消息 */
    ul_ret = frw_ipc_msg_queue_send(pst_msg_queue,
                                    pst_ipc_mem_msg,
                                    g_ipc_node[en_type].en_tx_int_ctl,
                                    g_ipc_node[en_type].en_target_cpuid);
    if (oal_unlikely(ul_ret == OAL_ERR_CODE_IPC_QUEUE_FULL)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_send::frw_ipc_msg_queue_send return err code: %d}",
                         OAL_ERR_CODE_IPC_QUEUE_FULL);
        return ul_ret;
    }

    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_send::frw_ipc_msg_queue_send return err code:%d}", ul_ret);
        return ul_ret;
    }

    /* 更新序列号 */
    g_ipc_node[en_type].us_seq_num_tx_expect++;

    /* 更新事件结构体引用计数 */
    pst_ipc_mem_msg->uc_user_cnt++;
    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_tx_complete
 * 功能描述  : 发送完成中断处理，非OFFLOAD情况下不用，OFFLOAD情况下需要用
 * 输入参数  : pst_msg:消息结构体指针
 */
OAL_STATIC void frw_ipc_tx_complete(frw_ipc_msg_mem_stru *pst_msg)
{
}

/*
 * 函 数 名  : frw_ipc_init
 * 功能描述  : 对外接口，IPC模块初始化，OFFLOAD情况下主CPU侧由主核调用该函数
 */
OAL_STATIC uint32_t frw_ipc_init(void)
{
    uint32_t ul_ret;

    if (frw_ipc_get_core_type() == FRW_IPC_CORE_TYPE_MASTER) {
        ul_ret = frw_ipc_init_master(&g_ipc_node[FRW_IPC_CORE_TYPE_MASTER]);
    } else {
        ul_ret = frw_ipc_init_slave(&g_ipc_node[FRW_IPC_CORE_TYPE_SLAVE]);
    }

    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw ipc init fail.}");
        return ul_ret;
    }

    /* 启动连接 */
    ul_ret = frw_ipc_send_connect_request();
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw ipc connect fail.}");
        return ul_ret;
    }

    /* 将以下函数注册到事件管理模块中 */
    frw_event_ipc_event_queue_full_register(frw_ipc_event_queue_full);
    frw_event_ipc_event_queue_empty_register(frw_ipc_event_queue_empty);

    return OAL_SUCC;
}

OAL_STATIC void frw_ipc_node_init(frw_ipc_node_stru *pst_ipc_node)
{
    pst_ipc_node->en_cpuid = FRW_IPC_CORE_ID_MASTER;
    pst_ipc_node->en_target_cpuid = FRW_IPC_CORE_ID_SLAVE;
    pst_ipc_node->en_cpu_type = FRW_IPC_CORE_TYPE_MASTER;
    pst_ipc_node->us_seq_num_rx_expect = 0;
    pst_ipc_node->us_seq_num_tx_expect = 0;
    pst_ipc_node->en_states = FRW_IPC_CORE_STATE_INIT;
    pst_ipc_node->en_tx_int_ctl = FRW_IPC_TX_CTRL_ENABLED;
}

/*
 * 函 数 名  : frw_ipc_init_master
 * 功能描述  : 主核IPC模块初始化，OFFLOAD情况下主CPU和WIFI都调用该函数
 */
OAL_STATIC uint32_t frw_ipc_init_master(frw_ipc_node_stru *pst_ipc_node)
{
    uint32_t ul_ret;

    /* 全局结构体初始化 */
    frw_ipc_node_init(pst_ipc_node);

    /* 主核完成消息队列初始化 */
    /* 发送队列初始化 */
    ul_ret = frw_ipc_msg_queue_init(&g_queue_master_to_slave,
                                    FRW_IPC_MASTER_TO_SLAVE_QUEUE_MAX_NUM);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW,
                         "{frw_ipc_init_master: frw_ipc_msg_queue_init slave return err code:%d}", ul_ret);
        return ul_ret;
    }

    /* 接收队列初始化 */
    ul_ret = frw_ipc_msg_queue_init(&g_queue_slave_to_master,
                                    FRW_IPC_SLAVE_TO_MASTER_QUEUE_MAX_NUM);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW,
                         "{frw_ipc_init_master:: frw_ipc_msg_queue_init master return err code:%d}", ul_ret);
        return ul_ret;
    }

    /* 中断注册 */
    pst_ipc_node->st_irq_dev.p_irq_intr_func = frw_ipc_msg_queue_recv;
    pst_ipc_node->st_irq_dev.irq = OAL_IRQ_NUM;
    pst_ipc_node->st_irq_dev.l_irq_type = OAL_SA_SHIRQ;
    pst_ipc_node->st_irq_dev.pc_name = "ipc";
    pst_ipc_node->st_irq_dev.p_drv_arg = (void *)&g_queue_slave_to_master;

    if (oal_unlikely(oal_irq_setup(&pst_ipc_node->st_irq_dev) != 0)) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw_ipc_msg_queue_setup_irq:: oal_irq_setup fail!}");
        return OAL_FAIL;
    }

    /* 回调函数注册 */
    pst_ipc_node->st_ipc_msg_callback.p_rx_complete_func = frw_ipc_recv;
    pst_ipc_node->st_ipc_msg_callback.p_tx_complete_func = frw_ipc_tx_complete;
    ul_ret = frw_ipc_msg_queue_register_callback(&pst_ipc_node->st_ipc_msg_callback);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_init_master: ipc msg queue register return err code:%d}", ul_ret);
        return ul_ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_init_slave
 * 功能描述  : 从核IPC模块初始化: OFFLOAD情况下不需要用
 */
OAL_STATIC uint32_t frw_ipc_init_slave(frw_ipc_node_stru *pst_ipc_node)
{
    uint32_t ul_ret;

    /* 全局结构体初始化 */
    pst_ipc_node->en_cpuid = (uint8_t)oal_get_core_id();
    pst_ipc_node->en_target_cpuid = FRW_IPC_CORE_ID_MASTER;
    pst_ipc_node->en_cpu_type = FRW_IPC_CORE_TYPE_SLAVE;
    pst_ipc_node->us_seq_num_rx_expect = 0;
    pst_ipc_node->us_seq_num_tx_expect = 0;
    pst_ipc_node->en_states = FRW_IPC_CORE_STATE_INIT;
    pst_ipc_node->en_tx_int_ctl = FRW_IPC_TX_CTRL_ENABLED;

    /* 中断注册 */
    pst_ipc_node->st_irq_dev.p_irq_intr_func = frw_ipc_msg_queue_recv;
    pst_ipc_node->st_irq_dev.irq = OAL_IRQ_NUM;
    pst_ipc_node->st_irq_dev.l_irq_type = OAL_SA_SHIRQ;
    pst_ipc_node->st_irq_dev.pc_name = "ipc";
    pst_ipc_node->st_irq_dev.p_drv_arg = (void *)&g_queue_master_to_slave;

    if (oal_unlikely(oal_irq_setup(&pst_ipc_node->st_irq_dev) != 0)) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw_ipc_msg_queue_setup_irq: oal_irq_setup fail!}");
        return OAL_FAIL;
    }

    /* 回调函数注册 */
    pst_ipc_node->st_ipc_msg_callback.p_rx_complete_func = frw_ipc_recv;
    pst_ipc_node->st_ipc_msg_callback.p_tx_complete_func = frw_ipc_tx_complete;
    ul_ret = frw_ipc_msg_queue_register_callback(&pst_ipc_node->st_ipc_msg_callback);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW,
                         "{frw_ipc_init_slave:: frw_ipc_msg_queue_register_callback return err code:%d}", ul_ret);
        return ul_ret;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_exit
 * 功能描述  : 真正的释放资源
 */
OAL_STATIC uint32_t frw_ipc_exit(void)
{
    uint32_t ul_ret;
    uint8_t en_type; /* CPU类型: 主核或从核 */

    /* 获取当前内核信息 */
    en_type = frw_ipc_get_core_type();

    /* 修改IPC模块状态 */
    g_ipc_node[en_type].en_states = FRW_IPC_CORE_STATE_EXIT;

    /* 注销核间中断 */
    oal_irq_free(&g_ipc_node[en_type].st_irq_dev);

    /* 释放消息队列 */
    if (en_type == FRW_IPC_CORE_ID_MASTER) { /* 主核 */
        /* 发送队列注销 */
        ul_ret = frw_ipc_msg_queue_destroy(&g_queue_master_to_slave);
        if (oal_unlikely(ul_ret != OAL_SUCC)) {
            oam_warning_log1(0, OAM_SF_FRW,
                             "{frw_ipc_exit: frw_ipc_msg_queue_destroy g_queue_master_to_slave return err code:%d}",
                             ul_ret);
            return ul_ret;
        }

        /* 接收队列注销 */
        ul_ret = frw_ipc_msg_queue_destroy(&g_queue_slave_to_master);
        if (oal_unlikely(ul_ret != OAL_SUCC)) {
            oam_warning_log1(0, OAM_SF_FRW,
                             "frw_ipc_exit:: frw_ipc_msg_queue_destroy g_queue_slave_to_master return err code:%d",
                             ul_ret);
            return ul_ret;
        }
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_send_connect_request
 * 功能描述  : 采用异步方式进行连接，该函数只发送连接请求，
 *             在中断服务例程中接收处理连接响应，并改变IPC状态
 */
OAL_STATIC uint32_t frw_ipc_send_connect_request(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_send_inter_msg(FRW_IPC_MSG_TYPE_CONNECT_REQUEST,
                                    NULL,
                                    0);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_send_connect_request: frw_ipc_send_inter_msg return %d}", ul_ret);
        return ul_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_send_connect_response
 * 功能描述  : 运行在中断上下文，采用异步方式进行连接，该函数只发送连接响应，
 */
OAL_STATIC uint32_t frw_ipc_send_connect_response(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_send_inter_msg(FRW_IPC_MSG_TYPE_CONNECT_RESPONSE, NULL, 0);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_send_connect_response: frw_ipc_send_inter_msg return %d}", ul_ret);
        return ul_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_send_inter_msg
 * 功能描述  : 发送核间通信内部消息
 * 输入参数  : uc_msg_type: 内部消息类型
 *             puc_data: 需要发送的数据
 *             us_len: 数据长度
 */
OAL_STATIC uint32_t frw_ipc_send_inter_msg(uint8_t uc_msg_type,
                                           uint8_t *puc_data,
                                           uint8_t us_len)
{
    uint32_t ul_ret;
    frw_ipc_msg_mem_stru *pst_msg_mem_stru = NULL; /* 消息内存块 */
    frw_ipc_inter_msg_stru *pst_ipc_msg = NULL;    /* 消息结构体 */
    frw_ipc_msg_queue_stru *pst_msg_queue = NULL;  /* 消息队列 */
    uint8_t en_type;   /* CPU类型: 主核或从核 */
    uint8_t ul_length;

    /* 获取当前内核信息 */
    en_type = frw_ipc_get_core_type();
    frw_ipc_get_msg_queue(pst_msg_queue, en_type);

    /* 申请核间内部消息内存 */
    // cppcheck-suppress * /* 屏蔽pst_ipc_msg变量空指针引用告警 */
    ul_length = (uint8_t)(sizeof(frw_ipc_inter_msg_stru) - sizeof(pst_ipc_msg->auc_data)) + us_len;
    pst_msg_mem_stru = frw_event_alloc_append_line(ul_length, CUR_OAL_MEM_CONTEXT);
    if (oal_unlikely(pst_msg_mem_stru == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_ipc_send_inter_msg: frw_event_alloc_m fail!}");
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }

    /* 获取消息地址 */
    pst_ipc_msg = (frw_ipc_inter_msg_stru *)frw_ipc_get_header(pst_msg_mem_stru);

    /* 填充消息头 */
    pst_ipc_msg->st_ipc_hdr.us_seq_number = g_ipc_node[en_type].us_seq_num_tx_expect;
    pst_ipc_msg->st_ipc_hdr.uc_target_cpuid = g_ipc_node[en_type].en_target_cpuid;
    pst_ipc_msg->st_ipc_hdr.uc_msg_type = uc_msg_type;
    pst_ipc_msg->ul_length = us_len;

    /* 填充数据 */
    if (us_len > 0) {
        ul_ret = memcpy_s((void *)pst_ipc_msg->auc_data, us_len,
                          (void *)puc_data, us_len);
        if (ul_ret != EOK) {
            oam_warning_log0(0, OAM_SF_FRW, "{frw_ipc_send_inter_msg: memcpy_s failed!}");
            frw_event_free_append_line(pst_msg_mem_stru, CUR_OAL_MEM_CONTEXT);
            return OAL_FAIL;
        }
    }

    /* 发送内部消息 */
    ul_ret = frw_ipc_msg_queue_send(pst_msg_queue,
                                    pst_msg_mem_stru,
                                    g_ipc_node[en_type].en_tx_int_ctl,
                                    g_ipc_node[en_type].en_target_cpuid);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log0(0, OAM_SF_FRW, "{send inter msg fail.}");
        frw_event_free_append_line(pst_msg_mem_stru, CUR_OAL_MEM_CONTEXT);
        return ul_ret;
    }
    /* 更新序列号 */
    g_ipc_node[en_type].us_seq_num_tx_expect++;

    return OAL_SUCC;
}

uint32_t frw_ipc_reset(void)
{
    return OAL_SUCC;
}

uint32_t frw_ipc_smp_dispatch(void *buf)
{
    return OAL_SUCC;
}

uint32_t frw_ipc_smp_ordering(void *buf)
{
    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_event_queue_full
 * 功能描述  : 当事件调度模块发现队列高于某个阀值时，调用该接口通知对方内核
 */
OAL_STATIC uint32_t frw_ipc_event_queue_full(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_send_inter_msg(FRW_IPC_MSG_TYPE_TX_INT_DISENABLE, NULL, 0);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_event_queue_full: frw_ipc_send_inter_msg return err code:%d}",
                         ul_ret);
        return ul_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_ipc_event_queue_empty
 * 功能描述  : 当事件调度模块发现队列低于某个阀值时，调用该接口通知对方内核
 */
OAL_STATIC uint32_t frw_ipc_event_queue_empty(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_send_inter_msg(FRW_IPC_MSG_TYPE_TX_INT_ENABLE, NULL, 0);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_ipc_event_queue_empty: frw_ipc_send_inter_msg return err code:%d}",
                         ul_ret);
        return ul_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_deploy_init
 * 功能描述  : 对外接口，事件部署模块初始化接口
 */
uint32_t frw_event_deploy_init(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_init();
    if (ul_ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw event deploy init fail.}");
        return ul_ret;
    }

    /*
     * 事件部署模块数据结构初始化
     * 各种级别的事件部署按照均衡部署方式进行初始化
     * 引入宏, 如果是HMAC DMAC PIPELINE方式，则注册frw_event_deploy_pipeline
     * 引入宏, 如果是按照CHIP,DEVICE,VAP方式，则注册frw_event_deploy_owner
     */
    frw_event_deploy_register(frw_event_deploy_pipeline);

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_deploy_exit
 * 功能描述  : 对外接口，事件部署模块退出接口
 */
uint32_t frw_event_deploy_exit(void)
{
    uint32_t ul_ret;

    ul_ret = frw_ipc_exit();
    if (ul_ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_FRW, "{frw event deploy exit fail.}");
        return ul_ret;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_deploy_pipeline
 * 功能描述  : 内部函数，事件部署接口，挂接到事件管理模块中，按照PIPELINE部署
 * 输入参数  : pst_mem_event: 事件内存块指针
 * 输出参数  : en_deploy: FRW_EVENT_DEPLOY_IPC-该事件需要IPC
 *                        FRW_EVENT_DEPLOY_POST-该事件需要入队列
 */
OAL_STATIC uint32_t frw_event_deploy_pipeline(frw_ipc_msg_mem_stru *pst_ipc_mem_msg,
                                              uint8_t *en_deploy_result)
{
    frw_event_hdr_stru *pst_event_hdr = NULL;

    if (oal_unlikely(pst_ipc_mem_msg == NULL) || (en_deploy_result == NULL)) {
        oam_error_log2(0, OAM_SF_FRW,
                       "{frw_event_deploy_pipeline: pst_ipc_mem_msg/en_deploy_result null ptr err:%d, %d}",
                       (uintptr_t)pst_ipc_mem_msg, (uintptr_t)en_deploy_result);
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_event_hdr = (frw_event_hdr_stru *)pst_ipc_mem_msg->puc_data;

    if (pst_event_hdr->en_pipeline == FRW_EVENT_PIPELINE_STAGE_0) {
        (*en_deploy_result) = FRW_EVENT_DEPLOY_NON_IPC;
    } else {
        (*en_deploy_result) = FRW_EVENT_DEPLOY_IPC;

        frw_ipc_send(pst_ipc_mem_msg);
    }

    return OAL_SUCC;
}
