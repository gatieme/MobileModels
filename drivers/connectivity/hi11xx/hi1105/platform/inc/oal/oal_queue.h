/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: oal_bit.h header file
 * Author: @CompanyNameTag
 */

#ifndef OAL_DATA_STRU_H
#define OAL_DATA_STRU_H

/* 其他头文件包含 */
#include "oal_types.h"
#include "oal_mem.h"
#include "oam_wdk.h"
#include "securec.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAML_QUEUE_H

/* 宏定义 */
#define OAL_QUEUE_DESTROY

/* 判断x是否是2的整数幂 */
#define oal_is_not_pow_of_2(_x) ((_x) & ((_x) - 1))

/* STRUCT定义 */
typedef struct {
    uint8_t uc_element_cnt;  /* 本队列中已经存放的元素个数 */
    uint8_t uc_max_elements; /* 本队列中所能存放的最大元素个数 */
    uint8_t uc_tail_index;   /* 指向下一个元素入队位置的索引 */
    uint8_t uc_head_index;   /* 指向当前元素出队位置的索引 */
    uintptr_t *pul_buf;        /* 队列缓存 */
} oal_queue_stru;

typedef struct {
    uint16_t us_element_cnt;  /* 本队列中已经存放的元素个数 */
    uint16_t us_max_elements; /* 本队列中所能存放的最大元素个数 */
    uint16_t us_tail_index;   /* 指向下一个元素入队位置的索引 */
    uint16_t us_head_index;   /* 指向当前元素出队位置的索引 */
    uintptr_t *pul_buf;         /* 队列缓存 */
} oal_queue_stru_16;


/*
 * 函 数 名  : oal_queue_set
 * 功能描述  : 设置队列参数
 * 输入参数  : pst_queue      : 队列指针
 *             pul_buf        : 指向队列缓冲区的指针
 *             us_max_elements: 最大元素个数
 */
OAL_STATIC OAL_INLINE void oal_queue_set(oal_queue_stru *pst_queue, oal_uint *pul_buf, uint8_t uc_max_elements)
{
    pst_queue->pul_buf = (uintptr_t *)pul_buf;

    pst_queue->uc_tail_index = 0;
    pst_queue->uc_head_index = 0;
    pst_queue->uc_element_cnt = 0;
    pst_queue->uc_max_elements = uc_max_elements;
}

OAL_STATIC OAL_INLINE void oal_queue_set_16(oal_queue_stru_16 *pst_queue, oal_uint *pul_buf,
                                            uint16_t us_max_elements)
{
    pst_queue->pul_buf = (uintptr_t *)pul_buf;

    pst_queue->us_tail_index = 0;
    pst_queue->us_head_index = 0;
    pst_queue->us_element_cnt = 0;
    pst_queue->us_max_elements = us_max_elements;
}

/*
 * 函 数 名  : oal_queue_init
 * 功能描述  : 队列初始化, uc_max_events必须是2的整数次幂
 * 输入参数  : pst_queue      : 队列指针
 *             uc_max_events: 最大元素个数
 */
OAL_STATIC OAL_INLINE uint32_t oal_queue_init(oal_queue_stru *pst_queue, uint8_t uc_max_events,
                                              oal_mem_pool_context_stru *ctx)
{
    uintptr_t *pul_buf = NULL;

    if (uc_max_events == 0) {
        return OAL_SUCC;
    } else {
        if (oal_unlikely(oal_is_not_pow_of_2(uc_max_events))) {
            return OAL_ERR_CODE_CONFIG_UNSUPPORT;
        }
        pul_buf = (uintptr_t *)oal_mem_alloc_ctx(OAL_MEM_POOL_ID_LOCAL, (uint16_t)(uc_max_events * sizeof(uintptr_t)),
                                                 OAL_TRUE, ctx);
        if (oal_unlikely(pul_buf == NULL)) {
            return OAL_ERR_CODE_ALLOC_MEM_FAIL;
        }
        memset_s(pul_buf, uc_max_events * sizeof(uintptr_t), 0, uc_max_events * sizeof(uintptr_t));
        oal_queue_set(pst_queue, pul_buf, uc_max_events);

        return OAL_SUCC;
    }
}

/*
 * 函 数 名  : oal_queue_destroy
 * 功能描述  : 销毁队列
 * 输入参数  : pst_queue: 队列指针
 */
OAL_STATIC OAL_INLINE void oal_queue_destroy(oal_queue_stru *pst_queue, oal_mem_pool_context_stru *ctx)
{
    if (pst_queue == NULL) {
        return;
    }

    if (pst_queue->pul_buf == NULL) {
        return;
    }

    oal_mem_free_ctx(pst_queue->pul_buf, OAL_TRUE, ctx);

    oal_queue_set(pst_queue, NULL, 0);
}

/*
 * 函 数 名  : oal_queue_enqueue
 * 功能描述  : 元素入队
 * 输入参数  : pst_queue: 队列指针
 *             p_element: 元素指针
 */
OAL_STATIC OAL_INLINE uint32_t oal_queue_enqueue(oal_queue_stru *pst_queue, const void *p_element)
{
    uint8_t uc_tail_index;

    /* 异常: 队列已满 */
    if (pst_queue->uc_element_cnt == pst_queue->uc_max_elements) {
        return OAL_FAIL;
    }

    uc_tail_index = pst_queue->uc_tail_index;

    /* 将元素的地址保存在队列中 */
    pst_queue->pul_buf[uc_tail_index] = (uintptr_t)p_element;

    uc_tail_index++;

    pst_queue->uc_tail_index = ((uc_tail_index >= pst_queue->uc_max_elements) ? 0 : uc_tail_index);

    pst_queue->uc_element_cnt++;

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE uint32_t oal_queue_enqueue_16(oal_queue_stru_16 *pst_queue, const void *p_element)
{
    uint16_t us_tail_index;

    /* 异常: 队列已满 */
    if (pst_queue->us_element_cnt == pst_queue->us_max_elements) {
        return OAL_FAIL;
    }

    us_tail_index = pst_queue->us_tail_index;

    /* 将元素的地址保存在队列中 */
    pst_queue->pul_buf[us_tail_index] = (uintptr_t)p_element;

    us_tail_index++;

    pst_queue->us_tail_index = ((us_tail_index >= pst_queue->us_max_elements) ? 0 : us_tail_index);

    pst_queue->us_element_cnt++;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oal_queue_dequeue
 * 功能描述  : 元素出队
 * 输入参数  : pst_queue: 队列指针
 * 返 回 值  : 成功: 事件指针
 *             失败:NULLL
 */
OAL_STATIC OAL_INLINE void *oal_queue_dequeue(oal_queue_stru *pst_queue)
{
    uint8_t uc_head_index;
    void *p_element = NULL;

    /* 异常: 队列为空 */
    if (pst_queue->uc_element_cnt == 0) {
        return NULL;
    }

    uc_head_index = pst_queue->uc_head_index;

    p_element = (void *)pst_queue->pul_buf[uc_head_index];

    uc_head_index++;

    pst_queue->uc_head_index = ((uc_head_index >= pst_queue->uc_max_elements) ? 0 : uc_head_index);
    pst_queue->uc_element_cnt--;

    return p_element;
}

OAL_STATIC OAL_INLINE void *oal_queue_dequeue_16(oal_queue_stru_16 *pst_queue)
{
    uint16_t us_head_index;
    void *p_element = NULL;

    /* 异常: 队列为空 */
    if (pst_queue->us_element_cnt == 0) {
        return NULL;
    }

    us_head_index = pst_queue->us_head_index;

    p_element = (void *)pst_queue->pul_buf[us_head_index];

    us_head_index++;

    pst_queue->us_head_index = ((us_head_index >= pst_queue->us_max_elements) ? 0 : us_head_index);
    pst_queue->us_element_cnt--;

    return p_element;
}

/*
 * 函 数 名  : oal_queue_get_length
 * 功能描述  : 获取队列中已经存放的元素个数
 * 输入参数  : pst_queue: 队列指针
 * 返 回 值  : 队列中存放的事件个数
 */
OAL_STATIC OAL_INLINE uint8_t oal_queue_get_length(oal_queue_stru *pst_queue)
{
    if (pst_queue == NULL) {
        return 0;
    }

    return pst_queue->uc_element_cnt;
}

#endif /* end of oal_data_stru.h */
