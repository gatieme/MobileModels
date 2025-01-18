/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: frw_event_main.c header file
 * Author: @CompanyNameTag
 */

#ifndef FRW_EVENT_MAIN_H
#define FRW_EVENT_MAIN_H

/* 其他头文件包含 */
#include "frw_event_sched.h"
#include "securec.h"
#include "frw_subsys_context.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_FRW_EVENT_MAIN_H

/*
 * 枚举说明: 事件部署类型
 */
typedef enum {
    FRW_EVENT_DEPLOY_NON_IPC = 0, /* 非核间通信 */
    FRW_EVENT_DEPLOY_IPC,         /* 核间通讯 */

    FRW_EVENT_DEPLOY_BUTT
} frw_event_deploy_enum;

typedef uint32_t (*f_frw_event_deploy)(frw_event_mem_stru *pst_even, uint8_t *pen_deploy_result);

/* 事件表的最大个数 */
/* 一种类型的事件对应两个表项，所以事件表的大小为事件类型的2倍 */
#define FRW_EVENT_TABLE_MAX_ITEMS (FRW_EVENT_TYPE_BUTT * 2)

/* 全局变量声明 */
#ifdef _PRE_FRW_EVENT_PROCESS_TRACE_DEBUG
typedef struct _frw_event_segment_stru_ {
    uint8_t en_type;         /* 事件类型 */
    uint8_t uc_sub_type;                     /* 事件子类型 */
    uint8_t en_pipeline; /* 事件分段号 */
    uint8_t uc_vap_id;                       /* VAP ID */
} frw_event_segment_stru;

typedef struct _frw_event_trace_item_stru_ {
    frw_event_segment_stru st_event_seg;
    uint64_t timestamp;
} frw_event_trace_item_stru;

#define CONFIG_FRW_MAX_TRACE_EVENT_NUMS 50
typedef struct _frw_event_trace_stru_ {
    frw_event_trace_item_stru st_trace_item[CONFIG_FRW_MAX_TRACE_EVENT_NUMS];
    uint32_t ul_current_pos;
    uint32_t ul_over_flag;
    const char *pst_func_name;
    int32_t line_num;
} frw_event_trace_stru;
#endif

/*
 * 结构名  : frw_event_mgmt_stru
 * 结构说明: 事件管理结构体
 */
struct _frw_event_mgmt_stru_ {
    frw_event_queue_stru st_event_queue[FRW_EVENT_MAX_NUM_QUEUES];    /* 事件队列: 需要保证足够空间能够存储 WIFI/GT 的配置 */
    frw_event_sched_queue_stru st_sched_queue[FRW_SCHED_POLICY_BUTT]; /* 可调度队列 */
#ifdef _PRE_FRW_EVENT_PROCESS_TRACE_DEBUG
    frw_event_trace_stru *pst_frw_trace;
#endif
};

extern frw_event_mgmt_stru g_event_manager_gt[WLAN_FRW_MAX_NUM_CORES];
extern frw_event_mgmt_stru g_event_manager_wifi[WLAN_FRW_MAX_NUM_CORES];

/* 函数声明 */
uint32_t frw_event_init_ctx(frw_subsys_context *ctx);
uint32_t frw_event_exit_ctx(frw_subsys_context *ctx);
uint32_t frw_event_queue_enqueue(frw_event_queue_stru *pst_event_queue, frw_event_mem_stru *pst_event_mem);
frw_event_mem_stru *frw_event_queue_dequeue(frw_event_queue_stru *pst_event_queue);
uint32_t frw_event_post_event_ctx(frw_event_mem_stru *pst_event_mem, uint32_t ul_core_id, frw_subsys_context *ctx);
void frw_event_deploy_register(f_frw_event_deploy p_func);
void frw_event_ipc_event_queue_full_register (uint32_t(*p_func)(void));
void frw_event_ipc_event_queue_empty_register (uint32_t(*p_func)(void));
frw_event_sched_queue_stru *frw_event_get_sched_queue_ctx(uint32_t core_id, uint8_t en_policy, frw_subsys_context *ctx);
void frw_event_vap_pause_event_ctx(uint8_t uc_vap_id, frw_subsys_context *ctx);
void frw_event_vap_resume_event_ctx(uint8_t uc_vap_id, frw_subsys_context *ctx);
uint32_t frw_event_vap_flush_event_ctx(uint8_t uc_vap_id, uint8_t en_event_type,
                                       oal_bool_enum_uint8 en_drop, frw_subsys_context *ctx);
uint32_t frw_event_queue_info_ctx(frw_subsys_context *ctx);

/*
 * 函 数 名  : frw_event_to_qid
 * 功能描述  : 根据事件内容获取相应的事件队列ID
 * 输入参数  : pst_event_mem: 指向事件内存块的指针
 * 输出参数  : pus_qid      : 队列ID
 */
OAL_STATIC OAL_INLINE uint32_t frw_event_to_qid(frw_event_mem_stru *pst_event_mem, uint16_t *pus_qid)
{
    uint16_t us_qid;
    frw_event_hdr_stru *pst_event_hrd = NULL;

    if (oal_unlikely((pst_event_mem == NULL) || (pus_qid == NULL))) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    /* 获取事件头结构 */
    pst_event_hrd = (frw_event_hdr_stru *)pst_event_mem->puc_data;

    us_qid = pst_event_hrd->uc_vap_id * FRW_EVENT_TYPE_BUTT + pst_event_hrd->en_type;

    /* 异常: 队列ID超过最大值 */
    if ((us_qid >= FRW_EVENT_MAX_NUM_QUEUES)) {
        oam_error_log4(0, OAM_SF_FRW,
                       "{frw_event_to_qid, array overflow! us_qid[%d], vap_id[%d], en_type[%d], sub_type[%d]}",
                       us_qid, pst_event_hrd->uc_vap_id, pst_event_hrd->en_type, pst_event_hrd->uc_sub_type);
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    *pus_qid = us_qid;

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE uint32_t frw_event_process_for_trx_adapt(frw_event_table_item_stru *pst_frw_event_table,
                                                               uint8_t uc_sub_type,
                                                               frw_event_mem_stru *pst_event_mem,
                                                               uint8_t uc_index,
                                                               frw_subsys_context *ctx)
{
    oal_mem_pool_context_stru *mem_ctx = frw_context_get_mem_ctx(ctx);
    frw_event_mem_stru *pst_tmp_event_mem = NULL;
    uint32_t ul_ret = 0;

    /* For tx adapt */
    if (pst_frw_event_table->pst_sub_table[uc_sub_type].p_tx_adapt_func != NULL) {
        ul_ret = pst_frw_event_table->pst_sub_table[uc_sub_type].p_tx_adapt_func(pst_event_mem);
        if (ul_ret != OAL_SUCC) {
            oam_error_log3(0, OAM_SF_FRW,
                "{_frw_event_lookup_process_entry_::tx adapt process failed!sub_type[0x%x],index[0x%x],ret[%d].}",
                uc_sub_type, uc_index, ul_ret);
            return ul_ret;
        }

        return OAL_SUCC;
    }

    /* For rx adapt */
    if (pst_frw_event_table->pst_sub_table[uc_sub_type].p_rx_adapt_func != NULL) {
        /* rx adapt first */
        pst_tmp_event_mem = pst_frw_event_table->pst_sub_table[uc_sub_type].p_rx_adapt_func(pst_event_mem);
        if ((pst_tmp_event_mem != NULL) &&
            (pst_frw_event_table->pst_sub_table[uc_sub_type].p_func != NULL)) {
            /* then call action frame */
            pst_frw_event_table->pst_sub_table[uc_sub_type].p_func(pst_tmp_event_mem);
            frw_event_free_append_line(pst_tmp_event_mem, mem_ctx);
        } else {
            oam_error_log4(0, OAM_SF_FRW,
                "{frw_event_lookup_process_entry::rx adapt process failed! sub_type[0x%x], index[0x%x].[%d][%d]}",
                uc_sub_type, uc_index, (uintptr_t)pst_tmp_event_mem,
                (uintptr_t)pst_frw_event_table->pst_sub_table[uc_sub_type].p_func);

            if (pst_tmp_event_mem != NULL) {
                frw_event_free_append_line(pst_tmp_event_mem, mem_ctx);
            }
            return OAL_ERR_CODE_PTR_NULL;
        }
    }

    return OAL_SUCC;
}


/*
 * 函 数 名  : frw_event_lookup_process_entry
 * 功能描述  : 根据事件类型，子类型以及分段号，找到相应事件处理函数
 */
OAL_STATIC OAL_INLINE uint32_t _frw_event_lookup_process_entry_ctx_(frw_event_mem_stru *pst_event_mem,
                                                                    frw_event_hdr_stru *pst_event_hrd,
                                                                    frw_subsys_context *ctx)
{
    uint8_t uc_index;
    uint8_t uc_sub_type;
    const int32_t l_dump_event_len = 64;  /* 64:代表异常时输出事件内存的前64字节 */
    const int32_t l_dump_head_len = (int32_t)(FRW_EVENT_HDR_LEN + 20);  /* 20:代表维测字段长度 */
    frw_event_table_item_stru *pst_frw_event_table = NULL;

    uc_sub_type = pst_event_hrd->uc_sub_type;
    /* 根据事件类型及分段号计算事件表索引 */
    uc_index = (uint8_t)((pst_event_hrd->en_type << 1) | (pst_event_hrd->en_pipeline & 0x01));
    if (oal_unlikely(uc_index >= FRW_EVENT_TABLE_MAX_ITEMS)) {
        oam_error_log3(0, OAM_SF_FRW,
                       "{frw_event_lookup_process_entry::array overflow! type[0x%x], sub_type[0x%x], pipeline[0x%x]}",
                       pst_event_hrd->en_type, uc_sub_type, pst_event_hrd->en_pipeline);
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    pst_frw_event_table = &ctx->event_table[uc_index];
    if (pst_frw_event_table->pst_sub_table == NULL) {
        oam_error_log2(0, OAM_SF_FRW,
                       "{frw_event_lookup_process_entry::pst_sub_table is NULL! sub_type[0x%x], index[0x%x].}",
                       uc_sub_type, uc_index);

        /* 打印当前事件内存的部分内容 */
        oal_print_hex_dump(frw_get_event_data(pst_event_mem), l_dump_head_len,
                           HEX_DUMP_GROUP_SIZE, "current event mem info:");

        /* 打印当前事件内存的前64字节内容 */
        oal_print_hex_dump(frw_get_event_data(pst_event_mem) + l_dump_event_len,
                           l_dump_event_len, HEX_DUMP_GROUP_SIZE, "64bytes mem info in front of this mem:");

        return OAL_ERR_CODE_PTR_NULL;
    }

    /* For pipeline 0 type */
    if (pst_event_hrd->en_pipeline == 0) {
        if (pst_frw_event_table->pst_sub_table[uc_sub_type].p_func != NULL) {
            pst_frw_event_table->pst_sub_table[uc_sub_type].p_func(pst_event_mem);
            return OAL_SUCC;
        } else {
            oam_error_log2(0, OAM_SF_FRW,
                "{frw_event_lookup_process_entry::p_func is NULL! sub_type[0x%x], index[0x%x], pipeline=0.}",
                uc_sub_type, uc_index);
            return OAL_ERR_CODE_PTR_NULL;
        }
    }

    /* For pipeline 1 type */
    if (oal_unlikely((pst_frw_event_table->pst_sub_table[uc_sub_type].p_tx_adapt_func == NULL) &&
                     (pst_frw_event_table->pst_sub_table[uc_sub_type].p_rx_adapt_func == NULL))) {
        oam_error_log2(0, OAM_SF_FRW,
            "{frw_event_lookup_process_entry::tx and rx adapt pointer all NULL! sub_type[0x%x], index[0x%x].}",
            uc_sub_type, uc_index);
        return OAL_ERR_CODE_PTR_NULL;
    }

    return frw_event_process_for_trx_adapt(pst_frw_event_table, uc_sub_type, pst_event_mem, uc_index, ctx);
}

OAL_STATIC OAL_INLINE uint32_t frw_event_lookup_process_entry_ctx(frw_event_mem_stru *pst_event_mem,
                                                                  frw_event_hdr_stru *pst_event_hrd,
                                                                  frw_subsys_context *ctx)
{
    uint32_t ul_ret;

    if (oal_unlikely((pst_event_mem == NULL) || (pst_event_hrd == NULL))) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    ul_ret = _frw_event_lookup_process_entry_ctx_(pst_event_mem, pst_event_hrd, ctx);
    return ul_ret;
}

/*
 * 函 数 名  : frw_event_process
 * 功能描述  : 根据事件分段号，处理事件
 * 输入参数  : pst_event_mem: 指向事件内存块的指针
 */
OAL_STATIC OAL_INLINE uint32_t frw_event_process_ctx(frw_event_mem_stru *pst_event_mem, frw_subsys_context *ctx)
{
    frw_event_hdr_stru *pst_event_hrd = NULL;
    uint32_t ul_core_id;

    if (oal_unlikely(pst_event_mem == NULL)) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    /* 获取事件头结构 */
    pst_event_hrd = (frw_event_hdr_stru *)pst_event_mem->puc_data;

    if (oal_unlikely(pst_event_hrd->en_pipeline >= FRW_EVENT_PIPELINE_STAGE_BUTT)) {
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    /* 如果pipleline为0，则将事件入队。否则，根据事件类型，子类型以及分段号，执行相应的事件处理函数 */
    if (pst_event_hrd->en_pipeline == FRW_EVENT_PIPELINE_STAGE_0) {
        ul_core_id = oal_get_core_id();
        return frw_event_post_event_ctx(pst_event_mem, ul_core_id, ctx);
    }

    return frw_event_lookup_process_entry_ctx(pst_event_mem, pst_event_hrd, ctx);
}

#ifdef _PRE_FRW_EVENT_PROCESS_TRACE_DEBUG
OAL_STATIC OAL_INLINE void frw_event_last_pc_trace_ctx(const char *pst_func_name, int32_t line_num,
                                                       uint32_t ul_core_id, frw_subsys_context *ctx)
{
    if (oal_unlikely(pst_func_name == NULL)) {
        oal_warn_on(1);
        return;
    }

    if (oal_warn_on(ul_core_id >= WLAN_FRW_MAX_NUM_CORES)) {
        oam_error_log2(0, OAM_SF_FRW, "{frw_event_last_pc_trace: ul_core_id:%d beyond limit:%d}",
                       ul_core_id, WLAN_FRW_MAX_NUM_CORES);
        return;
    }

    if (oal_unlikely(ctx->event_manager[ul_core_id].pst_frw_trace == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_event_last_pc_trace: pst_frw_trace is null}");
        return;
    }

    ctx->event_manager[ul_core_id].pst_frw_trace->pst_func_name = pst_func_name;
    ctx->event_manager[ul_core_id].pst_frw_trace->line_num = line_num;
}

OAL_STATIC OAL_INLINE void frw_event_trace_ctx(frw_event_mem_stru *pst_event_mem, uint32_t ul_core_id,
                                               frw_subsys_context *ctx)
{
    uint32_t ul_pos;
    frw_event_trace_item_stru *pst_trace_item = NULL;
    frw_event_hdr_stru *pst_event_hdr = NULL;

    if (oal_unlikely(pst_event_mem == NULL)) {
        oal_warn_on(1);
        return;
    }

    pst_event_hdr = frw_get_event_hdr(pst_event_mem);
    ul_pos = ctx->event_manager[ul_core_id].pst_frw_trace->ul_current_pos;

    if (oal_warn_on(ul_pos >= CONFIG_FRW_MAX_TRACE_EVENT_NUMS)) {
        oam_error_log2(0, OAM_SF_FRW, "{frw_event_last_pc_trace: ul_core_id:%d beyond limit:%d}",
                       ul_pos, CONFIG_FRW_MAX_TRACE_EVENT_NUMS);
        return;
    };

    if (oal_warn_on(ul_core_id >= WLAN_FRW_MAX_NUM_CORES)) {
        oam_error_log2(0, OAM_SF_FRW, "{frw_event_last_pc_trace: ul_core_id:%d beyond limit:%d}",
                       ul_core_id, WLAN_FRW_MAX_NUM_CORES);
        return;
    };

    pst_trace_item = &(ctx->event_manager[ul_core_id].pst_frw_trace->st_trace_item[ul_pos]);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 35))
    pst_trace_item->timestamp = local_clock();
#else
    pst_trace_item->timestamp = 0;
#endif
    pst_trace_item->st_event_seg.en_type = pst_event_hdr->en_type;
    pst_trace_item->st_event_seg.uc_sub_type = pst_event_hdr->uc_sub_type;
    pst_trace_item->st_event_seg.uc_vap_id = pst_event_hdr->uc_vap_id;
    pst_trace_item->st_event_seg.en_pipeline = pst_event_hdr->en_pipeline;

    if ((++ul_pos) >= CONFIG_FRW_MAX_TRACE_EVENT_NUMS) {
        ctx->event_manager[ul_core_id].pst_frw_trace->ul_current_pos = 0;
        ctx->event_manager[ul_core_id].pst_frw_trace->ul_over_flag = 1;
    } else {
        ctx->event_manager[ul_core_id].pst_frw_trace->ul_current_pos++;
    }
}
#endif

#ifdef _PRE_OAL_FEATURE_TASK_NEST_LOCK
extern oal_task_lock_stru g_event_task_lock_gt;
extern oal_task_lock_stru g_event_task_lock_wifi;
#define frw_event_task_lock_ctx(ctx)                    \
    do {                                         \
        oal_smp_task_lock(ctx->event_task_lock); \
    } while (0)
#define frw_event_task_unlock_ctx(ctx)                    \
    do {                                           \
        oal_smp_task_unlock(ctx->event_task_lock); \
    } while (0)
#else
#define frw_event_task_lock_ctx(ctx) \
    do {                      \
    } while (0)
#define frw_event_task_unlock_ctx(ctx) \
    do {                        \
    } while (0)
#endif

#endif /* end of frw_event_main.h */
