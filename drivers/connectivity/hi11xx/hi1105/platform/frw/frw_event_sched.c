/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: Implementation of the Event Scheduling Interface
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "frw_event_sched.h"

#include "oam_ext_if.h"
#include "frw_main.h"
#include "frw_event_main.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_FRW_EVENT_SCHED_C

/*
 * 函 数 名  : frw_event_sched_deactivate_queue_no_lock
 * 功能描述  : 从调度队列删除一个事件队列
 * 输入参数  : pst_sched_queue: 调度队列指针
 *             pst_event_queue: 事件队列指针
 */
uint32_t frw_event_sched_deactivate_queue_no_lock(frw_event_sched_queue_stru *pst_sched_queue,
                                                  frw_event_queue_stru *pst_event_queue)
{
    if (pst_event_queue->st_queue.uc_element_cnt != 0) {
        return OAL_SUCC;
    }

    /* 更新调度队列上的总权重计数器 */
    pst_sched_queue->ul_total_weight_cnt -= pst_event_queue->uc_weight_cnt;

    /* 将事件队列的权重计数器清零 */
    pst_event_queue->uc_weight_cnt = 0;

    /*  debug */
    if (((uintptr_t)&pst_event_queue->st_list) == ((uintptr_t)&pst_sched_queue->st_head)) {
        oam_error_log0(0, OAM_SF_FRW, "frw_event_sched_deactivate_queue, delete header itself.");
        return OAL_FAIL;
    }

    /* 将事件队列从调度链表上删除 */
    oal_dlist_delete_entry(&pst_event_queue->st_list);

    /* 将事件队列置为不活跃状态 */
    pst_event_queue->en_state = FRW_EVENT_QUEUE_STATE_INACTIVE;

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_sched_activate_queue_no_lock
 * 功能描述  : 向调度队列添加一个新的事件队列
 *             封装为不加锁接口，保持接口对称性，供加锁接口调用
 * 输入参数  : past_sched_queue: 调度队列指针
 *             pst_event_queue : 事件队列指针
 */
uint32_t frw_event_sched_activate_queue_no_lock(frw_event_sched_queue_stru *pst_sched_queue,
                                                frw_event_queue_stru *pst_event_queue)
{
    /* 如果事件队列已经在可执行队列上(处于激活状态)，则直接返回成功 */
    if (pst_event_queue->en_state == FRW_EVENT_QUEUE_STATE_ACTIVE) {
        return OAL_SUCC;
    }

    /* 置为事件队列的权重计数器 */
    pst_event_queue->uc_weight_cnt = pst_event_queue->uc_weight;

    /* 更新调度队列上的总权重计数器 */
    pst_sched_queue->ul_total_weight_cnt += pst_event_queue->uc_weight_cnt;

    /* 将事件队列加入调度链表的末尾 */
    oal_dlist_add_tail(&pst_event_queue->st_list, &pst_sched_queue->st_head);

    /* 将事件队列置为激活状态 */
    pst_event_queue->en_state = FRW_EVENT_QUEUE_STATE_ACTIVE;

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_sched_pick_next_event_queue_wrr
 * 功能描述  : 从调度类中挑选下一个待处理的事件
 * 输入参数  : pst_sched_queue: 调度队列指针
 * 输出参数  : pst_sched_queue: 调度队列指针
 */
void *frw_event_sched_pick_next_event_queue_wrr(frw_event_sched_queue_stru *pst_sched_queue)
{
    oal_dlist_head_stru *pst_list = NULL;
    frw_event_queue_stru *pst_event_queue = NULL;
    void *p_event = NULL;
    oal_uint flag = 0;
    oal_dlist_head_stru *pst_header = NULL;

    if (oal_unlikely(pst_sched_queue == NULL)) {
        oal_warn_on(1);
        return NULL;
    }

    oal_spin_lock_irq_save(&pst_sched_queue->st_lock, &flag);

    pst_header = &pst_sched_queue->st_head;
    /* 遍历整个调度链表 */
    oal_dlist_search_for_each(pst_list, pst_header)
    {
        pst_event_queue = oal_dlist_get_entry(pst_list, frw_event_queue_stru, st_list);
        /* 如果事件队列的vap_state为暂停，则跳过，继续挑选下一个事件队列 */
        if (pst_event_queue->en_vap_state == FRW_VAP_STATE_PAUSE) {
            continue;
        }

        /* 如果事件队列的权重计数器为0，则挑选下一个事件队列 */
        if (pst_event_queue->uc_weight_cnt == 0) {
            continue;
        }

        /* 更新事件队列权重计数器 */
        pst_event_queue->uc_weight_cnt--;

        /* 更新调度队列的总权重计数器 */
        pst_sched_queue->ul_total_weight_cnt--;

        /* 从事件队列中取出一个事件 */
        p_event = frw_event_queue_dequeue(pst_event_queue);

        /* 如果事件队列变空，需要将其从调度队列上删除，并将事件队列状态置为不活跃(不可被调度) */
        frw_event_sched_deactivate_queue_no_lock(pst_sched_queue, pst_event_queue);

        break;
    }

    /* 如果调度队列的总权重计数器为0，则需要重置调度队列上各个事件队列的权重计数器 */
    if (pst_sched_queue->ul_total_weight_cnt == 0) {
        frw_event_sched_reset_weight(pst_sched_queue);
    }

    oal_spin_unlock_irq_restore(&pst_sched_queue->st_lock, &flag);
    return p_event;
}

/*
 * 函 数 名  : frw_event_sched_init
 * 功能描述  : 调度器初始化
 * 输入参数  : pst_sched_queue: 调度队列指针
 */
uint32_t frw_event_sched_init(frw_event_sched_queue_stru *pst_sched_queue)
{
    if (oal_unlikely(pst_sched_queue == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_event_sched_init:: pointer is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 初始化锁 */
    oal_spin_lock_init(&pst_sched_queue->st_lock);

    /* 初始化调度队列总权重计数器 */
    pst_sched_queue->ul_total_weight_cnt = 0;

    /* 初始化调度链表头 */
    oal_dlist_init_head(&pst_sched_queue->st_head);

    return OAL_SUCC;
}

/*
 * 函 数 名  : frw_event_queue_set
 * 功能描述  : 设置事件队列参数
 * 输入参数  : pst_prio_queue: 事件队列指针
 *             us_weight     : 队列权重
 *             en_policy     : 队列调度策略
 *             en_state      : 事件队列状态
 */
OAL_STATIC void frw_event_queue_set(frw_event_queue_stru *pst_event_queue,
                                    uint8_t uc_weight,
                                    uint8_t en_policy,
                                    uint8_t en_state)
{
    pst_event_queue->uc_weight = uc_weight;
    pst_event_queue->uc_weight_cnt = 0;
    pst_event_queue->en_policy = en_policy;
    pst_event_queue->en_state = en_state;
    pst_event_queue->en_vap_state = FRW_VAP_STATE_RESUME;
}

/*
 * 函 数 名  : frw_event_queue_init
 * 功能描述  : 事件队列初始化
 * 输入参数  : pst_event_queue: 事件队列指针
 *             us_weight      : 队列权重
 *             en_policy      : 队列调度策略
 *             en_state       : 事件队列状态
 *             us_max_events  : 最大事件个数
 */
uint32_t frw_event_queue_init_ctx(frw_event_queue_stru *pst_event_queue,
                                  uint8_t uc_weight,
                                  uint8_t en_policy,
                                  uint8_t en_state,
                                  uint8_t uc_max_events,
                                  frw_subsys_context *ctx)
{
    uint32_t ul_ret;
    oal_mem_pool_context_stru *mem_ctx = frw_context_get_mem_ctx(ctx);

    if (oal_unlikely(pst_event_queue == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_event_queue_init:: pointer is NULL!}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 初始化锁 */
    oal_spin_lock_init(&pst_event_queue->st_lock);

    ul_ret = oal_queue_init(&pst_event_queue->st_queue, uc_max_events, mem_ctx);
    if (oal_unlikely(ul_ret != OAL_SUCC)) {
        oam_warning_log1(0, OAM_SF_FRW, "{frw_event_queue_init:: OAL_QUEUE_INIT return != OAL_SUCC! %d}", ul_ret);
        frw_event_queue_set(pst_event_queue, 0, FRW_SCHED_POLICY_BUTT, FRW_EVENT_QUEUE_STATE_INACTIVE);

        return ul_ret;
    }

    frw_event_queue_set(pst_event_queue, uc_weight, en_policy, en_state);

    return OAL_SUCC;
}

void frw_event_queue_destroy_ctx(frw_event_queue_stru *pst_event_queue, frw_subsys_context *ctx)
{
    oal_mem_pool_context_stru *mem_ctx = frw_context_get_mem_ctx(ctx);
    if (oal_unlikely(pst_event_queue == NULL)) {
        oam_error_log0(0, OAM_SF_FRW, "{frw_event_queue_destroy:: pointer is NULL!}");
        return;
    }

    oal_queue_destroy(&pst_event_queue->st_queue, mem_ctx);

    frw_event_queue_set(pst_event_queue, 0, FRW_SCHED_POLICY_BUTT, FRW_EVENT_QUEUE_STATE_INACTIVE);
}

/*
 * 函 数 名  : frw_event_sched_deactivate_queue
 * 功能描述  : 从调度队列删除一个事件队列
 * 输入参数  : pst_sched_queue: 调度队列指针
 *             pst_event_queue: 事件队列指针
 */
uint32_t frw_event_sched_deactivate_queue(frw_event_sched_queue_stru *pst_sched_queue,
                                          frw_event_queue_stru *pst_event_queue)
{
    oal_uint flag = 0;
    uint32_t ret;

    if (oal_unlikely((pst_sched_queue == NULL) || (pst_event_queue == NULL))) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    /* 关中断，加锁 */
    oal_spin_lock_irq_save(&pst_sched_queue->st_lock, &flag);

    ret = frw_event_sched_deactivate_queue_no_lock(pst_sched_queue, pst_event_queue);

    /* 解锁，开中断 */
    oal_spin_unlock_irq_restore(&pst_sched_queue->st_lock, &flag);

    return ret;
}

/*
 * 函 数 名  : frw_event_sched_activate_queue
 * 功能描述  : 向调度队列添加一个新的事件队列
 *             封装调用不加锁实现，保持接口对称性
 * 输入参数  : past_sched_queue: 调度队列指针
 *             pst_event_queue : 事件队列指针
 */
uint32_t frw_event_sched_activate_queue(frw_event_sched_queue_stru *pst_sched_queue,
                                        frw_event_queue_stru *pst_event_queue)
{
    oal_uint flag = 0;
    uint32_t ret;

    if (oal_unlikely((pst_sched_queue == NULL) || (pst_event_queue == NULL))) {
        oal_warn_on(1);
        return OAL_FAIL;
    }

    oal_spin_lock_irq_save(&pst_sched_queue->st_lock, &flag);

    ret = frw_event_sched_activate_queue_no_lock(pst_sched_queue, pst_event_queue);

    oal_spin_unlock_irq_restore(&pst_sched_queue->st_lock, &flag);

    return ret;
}

/*
 * 函 数 名  : frw_event_sched_pause_queue
 * 功能描述  : 暂停队列调度状态
 * 输入参数  : past_sched_queue: 调度队列指针
 *             pst_event_queue : 事件队列指针
 */
void frw_event_sched_pause_queue(frw_event_sched_queue_stru *pst_sched_queue,
                                 frw_event_queue_stru *pst_event_queue)
{
    oal_uint flag = 0;

    if (oal_unlikely((pst_sched_queue == NULL) || (pst_event_queue == NULL))) {
        oal_warn_on(1);
        return;
    }

    oal_spin_lock_irq_save(&pst_sched_queue->st_lock, &flag);

    /* 该VAP对应的所有事件队列vap_state设置为暂停 */
    pst_event_queue->en_vap_state = FRW_VAP_STATE_PAUSE;

    /* 更新调度队列的总权重计数器 */
    if (pst_event_queue->en_state == FRW_EVENT_QUEUE_STATE_ACTIVE) {
        pst_sched_queue->ul_total_weight_cnt -= pst_event_queue->uc_weight_cnt;
    }

    oal_spin_unlock_irq_restore(&pst_sched_queue->st_lock, &flag);
}

/*
 * 函 数 名  : frw_event_sched_resume_queue
 * 功能描述  : 恢复队列调度状态
 * 输入参数  : past_sched_queue: 调度队列指针
 *             pst_event_queue : 事件队列指针
 */
void frw_event_sched_resume_queue(frw_event_sched_queue_stru *pst_sched_queue,
                                  frw_event_queue_stru *pst_event_queue)
{
    oal_uint flag = 0;

    if (oal_unlikely((pst_sched_queue == NULL) || (pst_event_queue == NULL))) {
        oal_warn_on(1);
        return;
    }

    oal_spin_lock_irq_save(&pst_sched_queue->st_lock, &flag);

    /* 该VAP对应的所有事件队列vap_state设置为恢复 */
    pst_event_queue->en_vap_state = FRW_VAP_STATE_RESUME;

    /* 更新调度队列的总权重计数器 */
    if (pst_event_queue->en_state == FRW_EVENT_QUEUE_STATE_ACTIVE) {
        pst_sched_queue->ul_total_weight_cnt += pst_event_queue->uc_weight_cnt;
    }

    oal_spin_unlock_irq_restore(&pst_sched_queue->st_lock, &flag);
}
