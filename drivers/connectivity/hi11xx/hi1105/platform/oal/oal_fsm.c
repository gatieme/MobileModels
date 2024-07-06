/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:General state machine file
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "securec.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_FSM_C

/*
 * 函 数 名  : oal_fsm_create
 * 功能描述  : 状态机创建接口
 * 输入参数  : p_oshandle: 状态机owner的指针，对低功耗状态机，指向VAP结构
 *             p_name    : 状态机的名字
 *             p_ctx     : 状态机context,指向pm_handler
 *             uc_init_state:初始状态
 *             p_state_info:状态机实例指针
 *             uc_num_states:状态机状态个数
 *             pp_event_names:本状态机中事件对应的事件名字
 *             us_num_event_names:事件个数
 */
uint32_t oal_fsm_create(void *p_oshandle, /* 状态机owner的指针，对低功耗状态机，指向VAP结构 */
                        const uint8_t *p_name,                    /* 状态机的名字 */
                        void *p_ctx,                            /* 状态机context */
                        oal_fsm_stru *pst_oal_fsm,                  /* oal状态机内容 */
                        uint8_t uc_init_state,                    /* 初始状态 */
                        const oal_fsm_state_info *p_state_info,     /* 状态机实例指针 */
                        uint8_t uc_num_states)                    /* 本状态机的状态个数 */
{
    uint32_t ul_loop;

    if (oal_any_null_ptr5(p_oshandle, p_name, p_ctx, pst_oal_fsm, p_state_info)) {
        oal_io_print("{oal_fsm_create:input ptr is NULL }");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (uc_num_states > OAL_FSM_MAX_STATES) {
        oal_io_print("{oal_fsm_create:state number [%d] too big. }", uc_num_states);
        return OAL_FAIL;
    }

    /* 检查状态信息顺序是否和状态定义匹配 */
    for (ul_loop = 0; ul_loop < uc_num_states; ul_loop++) {
        if ((p_state_info[ul_loop].state >= OAL_FSM_MAX_STATES) || (p_state_info[ul_loop].state != ul_loop)) {
            /* OAM日志中不能使用%s */
            oal_io_print("oal_fsm_create::entry %d has invalid state %d }", ul_loop, p_state_info[ul_loop].state);
            return OAL_FAIL;
        }
    }

    memset_s(pst_oal_fsm, sizeof(oal_fsm_stru), 0, sizeof(oal_fsm_stru));
    pst_oal_fsm->uc_cur_state = uc_init_state;
    pst_oal_fsm->uc_prev_state = uc_init_state;
    pst_oal_fsm->p_state_info = p_state_info;
    pst_oal_fsm->uc_num_states = uc_num_states;
    pst_oal_fsm->p_oshandler = p_oshandle;
    pst_oal_fsm->p_ctx = p_ctx;
    pst_oal_fsm->us_last_event = OAL_FSM_EVENT_NONE;

    /* strncpy fsm name */
    ul_loop = 0;
    while ((ul_loop < OAL_FSM_MAX_NAME - 1) && (p_name[ul_loop] != '\0')) {
        pst_oal_fsm->uc_name[ul_loop] = p_name[ul_loop];
        ul_loop++;
    }
    if (ul_loop < OAL_FSM_MAX_NAME) {
        pst_oal_fsm->uc_name[ul_loop] = '\0';
    }

    /* 启动状态机 */
    if (pst_oal_fsm->p_state_info[pst_oal_fsm->uc_cur_state].oal_fsm_entry) {
        pst_oal_fsm->p_state_info[pst_oal_fsm->uc_cur_state].oal_fsm_entry(pst_oal_fsm->p_ctx);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : mac_fsm_trans_to
 * 功能描述  : 状态机的destroy接口
 * 输入参数  : p_fsm:状态机指针
 */
uint32_t oal_fsm_trans_to_state(oal_fsm_stru *p_fsm, uint8_t uc_state)
{
    uint8_t uc_cur_state;

    if (oal_any_null_ptr1(p_fsm)) {
        oal_io_print("oal_fsm_trans_to_state input ptr null\n");
        return OAL_ERR_CODE_PTR_NULL;
    }
    uc_cur_state = p_fsm->uc_cur_state;
    if ((uc_state == OAL_FSM_STATE_NONE) || (uc_state >= OAL_FSM_MAX_STATES) || (uc_state >= p_fsm->uc_num_states)) {
        oal_io_print("oal_fsm_trans_to_state::trans to state %d needs to be a valid state cur_state=%d",
                     uc_state, uc_cur_state);
        return OAL_FAIL;
    }

    if (uc_state == uc_cur_state) {
        oal_io_print("oal_fsm_trans_to_state::trans to state %d needs to be a valid state cur_state=%d",
                     uc_state, uc_cur_state);
        return OAL_SUCC;
    }

    /* 调用前一状态的退出函数 */
    if (p_fsm->p_state_info[p_fsm->uc_cur_state].oal_fsm_exit) {
        p_fsm->p_state_info[p_fsm->uc_cur_state].oal_fsm_exit(p_fsm->p_ctx);
    }

    /* 调用本状态的进入函数 */
    if (p_fsm->p_state_info[uc_state].oal_fsm_entry) {
        p_fsm->p_state_info[uc_state].oal_fsm_entry(p_fsm->p_ctx);
    }

    p_fsm->uc_prev_state = uc_cur_state;
    p_fsm->uc_cur_state = uc_state;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oal_fsm_event_dispatch
 * 功能描述  : 状态机的事件处理接口
 * 输入参数  : p_fsm:状态机指针
 */
uint32_t oal_fsm_event_dispatch(oal_fsm_stru *p_fsm, uint16_t us_event,
                                uint16_t us_event_data_len, void *p_event_data)
{
    uint32_t ul_event_handled = OAL_FAIL;

    if (oal_any_null_ptr2(p_fsm, p_event_data)) {
        oal_io_print("oal_fsm_event_dispatch:p_fsm or p_event_data is NULL");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if ((p_fsm->uc_cur_state != OAL_FSM_STATE_NONE) &&
        (p_fsm->uc_cur_state < p_fsm->uc_num_states) &&
        p_fsm->p_state_info[p_fsm->uc_cur_state].oal_fsm_event != NULL) {
        p_fsm->us_last_event = us_event;
        ul_event_handled = (*p_fsm->p_state_info[p_fsm->uc_cur_state].oal_fsm_event)(p_fsm->p_ctx, us_event,
                                                                                     us_event_data_len,
                                                                                     p_event_data);
    }
    if (ul_event_handled == OAL_FAIL) {
        oal_io_print("oal_fsm_event_dispatch:event[%d] did not handled in state %d",
                     us_event, p_fsm->p_state_info[p_fsm->uc_cur_state].state);
        return OAL_FAIL;
    }

    return OAL_SUCC;
}

oal_module_symbol(oal_fsm_create);
oal_module_symbol(oal_fsm_trans_to_state);
oal_module_symbol(oal_fsm_event_dispatch);
