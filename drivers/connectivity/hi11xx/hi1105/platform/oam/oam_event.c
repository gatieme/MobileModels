/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description:Event reporting
 * Author: @CompanyNameTag
 */

/* 头文件包含 */
#include "oam_event.h"
#include "oam_main.h"
#include "oam_ext_if.h"
#include "securec.h"
#include "board.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAM_EVENT_C

/*
 * 函 数 名  : oam_report_data_get_global_switch
 * 功能描述  : 获取收发数据帧的总开关，如果总开关不开，则不用进入上报逻辑判断
 *             某一个用户的上报开关是否打开，不用消耗mips。只要有一个用户的开
 *             关打开了总开关就打开
 * 输入参数  : en_direction:方向，发送还是接收  0 发送  1接收
 *             en_direction->oam_ota_frame_direction_type_enum
 */
oal_switch_enum_uint8 oam_report_data_get_global_switch_ctx(uint8_t en_direction,
    oam_mng_ctx_stru *ctx)
{
    if (en_direction >= oal_unlikely(OAM_OTA_FRAME_DIRECTION_TYPE_BUTT)) {
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    return ctx->pst_user_track_ctx->aen_data_global_switch[en_direction];
}

/*
 * 函 数 名  : oam_report_data_set_global_switch
 * 功能描述  : 设置上报数据帧的全局开关，只要有一个用户要上报，则总开关就为开，
 *             否则关闭，防止消耗mips
 * 输入参数  : direction:取值范围 oam_ota_frame_direction_type_enum
 */
OAL_STATIC uint32_t oam_report_data_set_global_switch(uint8_t direction,
    oam_mng_ctx_stru *ctx)
{
    uint16_t usr_idx;
    oal_switch_enum_uint8 mcast_switch = OAL_SWITCH_OFF;
    oal_switch_enum_uint8 ucast_switch = OAL_SWITCH_OFF;

    if (direction >= oal_unlikely(OAM_OTA_FRAME_DIRECTION_TYPE_BUTT)) {
        return OAL_ERR_CODE_ARRAY_OVERFLOW;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 先检查单播数据帧是否有用户已经打开了 */
    for (usr_idx = 0; usr_idx < ctx->max_user; usr_idx++) {
        if (ctx->pst_user_track_ctx->ast_80211_ucast_data_ctx[usr_idx][direction].value != 0) {
            ucast_switch = OAL_SWITCH_ON;
            break;
        }
    }

    /* 再检查组播数据帧是否开关打开了 */
    if (ctx->pst_user_track_ctx->ast_80211_mcast_data_ctx[direction].value != 0) {
        mcast_switch = OAL_SWITCH_ON;
    }

    ctx->pst_user_track_ctx->aen_data_global_switch[direction] = (ucast_switch | mcast_switch);

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_eth_frame_set_switch
 * 功能描述  : 设置上报以太网帧的开关
 * 输入参数  : us_user_idx:用户资源池id
 *             en_switch  :打开还是关闭
 *             en_eth_direction:发送还是接收方向
 *             en_eth_direction->oam_ota_frame_direction_type_enum
 */
uint32_t oam_report_eth_frame_set_switch_ctx(uint16_t us_user_idx,
                                             oal_switch_enum_uint8 en_switch,
                                             uint8_t en_eth_direction,
                                             oam_mng_ctx_stru *ctx)
{
    uint8_t ota_switch_id;

    if (us_user_idx >= ctx->max_user) {
        oal_io_print("oam_report_eth_frame_set_switch::user_idx exceeds!\n");
        return OAL_ERR_CODE_OAM_EVT_USER_IDX_EXCEED;
    }

    if (en_eth_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        oal_io_print("oam_report_eth_frame_set_switch::eth_direction exceeds!\n");
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    ctx->pst_user_track_ctx->aen_eth_data_ctx[us_user_idx][en_eth_direction] = en_switch;

    ota_switch_id = en_eth_direction == OAM_OTA_FRAME_DIRECTION_TYPE_TX ?
                                        OAM_OTA_SWITCH_TX_ETH_FRAME : OAM_OTA_SWITCH_RX_ETH_FRAME;
    oam_ota_set_switch(ota_switch_id, en_switch);

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_eth_frame_get_switch
 * 功能描述  : 获取上报以太网帧的开关
 * 输入参数  : us_user_idx:用户资源池id
 *             en_eth_direction:发送还是接收
 *             en_eth_direction->oam_ota_frame_direction_type_enum
 *             pen_eth_switch:以太网帧打印开关
 */
uint32_t oam_report_eth_frame_get_switch_ctx(uint16_t us_user_idx,
                                             uint8_t en_eth_direction,
                                             oal_switch_enum_uint8 *pen_eth_switch,
                                             oam_mng_ctx_stru *ctx)
{
    if (us_user_idx >= ctx->max_user) {
        return OAL_ERR_CODE_OAM_EVT_USER_IDX_EXCEED;
    }

    if (en_eth_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (pen_eth_switch == NULL || ctx->pst_user_track_ctx == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    *pen_eth_switch = ctx->pst_user_track_ctx->aen_eth_data_ctx[us_user_idx][en_eth_direction];

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_mcast_set_switch
 * 功能描述  : 设置上报80211组播\广播数据或者管理帧的开关
 * 输入参数  : en_mcast_direction:帧是发送还是接收
 *             en_mcast_direction->oam_ota_frame_direction_type_enum
 *             en_frame_type     :数据帧还是管理帧(包含控制帧)
 *             en_frame_type->oam_user_track_frame_type_enum
 *             en_frame_switch   :帧开关
 *             en_cb_switch      :CB开关
 *             en_dscr_switch    :描述符开关
 */
uint32_t oam_report_80211_mcast_set_switch_ctx(uint8_t en_mcast_direction,
                                               uint8_t en_frame_type,
                                               oam_80211_frame_ctx_union *oam_frame_report,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_mcast_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (en_frame_type >= OAM_USER_TRACK_FRAME_TYPE_BUTT) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 为组播管理帧设置开关 */
    if (en_frame_type == OAM_USER_TRACK_FRAME_TYPE_MGMT) {
        ctx->pst_user_track_ctx->ast_80211_mcast_mgmt_ctx[en_mcast_direction].value = oam_frame_report->value;
    } else {
        ctx->pst_user_track_ctx->ast_80211_mcast_data_ctx[en_mcast_direction].value = oam_frame_report->value;

        /* 设置总开关 */
        oam_report_data_set_global_switch(en_mcast_direction, ctx);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_mcast_get_switch
 * 功能描述  : 获取上报80211组播帧的开关
 * 输入参数  : en_mcast_direction:帧是发送还是接收
 *             en_mcast_direction->oam_ota_frame_direction_type_enum
 *             en_frame_type     :数据帧还是管理帧(包含控制帧)
 *             en_frame_type->oam_user_track_frame_type_enum
 *             pen_frame_switch  :帧开关
 *             pen_cb_switch     :CB开关
 *             pen_dscr_switch   :描述符开关
 */
uint32_t oam_report_80211_mcast_get_switch_ctx(uint8_t en_mcast_direction,
                                               uint8_t en_frame_type,
                                               oam_80211_frame_ctx_union *oam_frame_report,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_mcast_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (en_frame_type >= OAM_USER_TRACK_FRAME_TYPE_BUTT) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (oal_unlikely(oal_any_null_ptr1(oam_frame_report))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_frame_type == OAM_USER_TRACK_FRAME_TYPE_MGMT) {
        oam_frame_report->value = ctx->pst_user_track_ctx->ast_80211_mcast_mgmt_ctx[en_mcast_direction].value;
    } else {
        oam_frame_report->value = ctx->pst_user_track_ctx->ast_80211_mcast_data_ctx[en_mcast_direction].value;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_ucast_set_switch
 * 功能描述  : 设置80211单播帧上报的开关
 * 输入参数  : en_ucast_direction:帧是发送还是接收
 *             en_ucast_direction->oam_ota_frame_direction_type_enum
 *             en_frame_type     :数据帧还是管理帧(包含控制帧)
 *             en_frame_type->oam_user_track_frame_type_enum
 *             en_frame_switch   :帧开关
 *             en_cb_switch      :CB开关
 *             en_dscr_switch    :描述符开关
 *             us_user_idx       :用户资源池id
 */
uint32_t oam_report_80211_ucast_set_switch_ctx(uint8_t en_ucast_direction,
                                               uint8_t en_frame_type,
                                               oam_80211_frame_ctx_union *oam_switch_param,
                                               uint16_t us_user_idx,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_ucast_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (en_frame_type >= OAM_USER_TRACK_FRAME_TYPE_BUTT) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (us_user_idx >= ctx->max_user) {
        return OAL_ERR_CODE_OAM_EVT_USER_IDX_EXCEED;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_frame_type == OAM_USER_TRACK_FRAME_TYPE_MGMT) {
        ctx->pst_user_track_ctx->ast_80211_ucast_mgmt_ctx[us_user_idx][en_ucast_direction].value =
            oam_switch_param->value;
    } else {
        ctx->pst_user_track_ctx->ast_80211_ucast_data_ctx[us_user_idx][en_ucast_direction].value =
            oam_switch_param->value;

        /* 设置总开关 */
        oam_report_data_set_global_switch(en_ucast_direction, ctx);
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_ucast_get_switch
 * 功能描述  : 获取80211单播帧的上报开关
 * 输入参数  : en_ucast_direction:帧是发送还是接收
 *             en_ucast_direction->oam_ota_frame_direction_type_enum
 *             en_frame_type     :数据帧还是管理帧(包含控制帧)
 *             en_frame_type->oam_user_track_frame_type_enum
 *             pen_frame_switch  :帧开关
 *             pen_cb_switch     :CB开关
 *             pen_dscr_switch   :描述符开关
 *             us_user_idx       :用户资源池id
 */
uint32_t oam_report_80211_ucast_get_switch_ctx(uint8_t en_ucast_direction,
                                               uint8_t en_frame_type,
                                               oam_80211_frame_ctx_union *oam_frame_report_un,
                                               uint16_t us_user_idx,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_ucast_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (en_frame_type >= OAM_USER_TRACK_FRAME_TYPE_BUTT) {
        return OAL_ERR_CODE_CONFIG_UNSUPPORT;
    }

    if (us_user_idx >= ctx->max_user) {
        return OAL_ERR_CODE_OAM_EVT_USER_IDX_EXCEED;
    }

    if (oal_unlikely(oal_any_null_ptr1(oam_frame_report_un))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_frame_type == OAM_USER_TRACK_FRAME_TYPE_MGMT) {
        oam_frame_report_un->value =
            ctx->pst_user_track_ctx->ast_80211_ucast_mgmt_ctx[us_user_idx][en_ucast_direction].value;
    } else {
        oam_frame_report_un->value =
            ctx->pst_user_track_ctx->ast_80211_ucast_data_ctx[us_user_idx][en_ucast_direction].value;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_probe_set_switch
 * 功能描述  : 设置probe request 和 probe response的打印开关
 * 输入参数  : en_ucast_direction:帧是发送还是接收
 *             en_probe_direction->oam_ota_frame_direction_type_enum
 *             en_frame_switch   :帧开关
 *             en_cb_switch      :CB开关
 *             en_dscr_switch    :描述符开关
 */
uint32_t oam_report_80211_probe_set_switch_ctx(uint8_t en_probe_direction,
                                               oam_80211_frame_ctx_union *oam_switch_param,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_probe_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (oam_switch_param == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    ctx->pst_user_track_ctx->aen_80211_probe_switch[en_probe_direction].value = oam_switch_param->value;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_80211_probereq_get_switch
 * 功能描述  : 获取prebe request和probe response的打印开关
 * 输入参数  : en_ucast_direction:帧是发送还是接收
 *             en_probe_direction->oam_ota_frame_direction_type_enum
 *             pen_frame_switch  :帧开关
 *             pen_cb_switch     :CB开关
 *             pen_dscr_switch   :描述符开关
 */
uint32_t oam_report_80211_probe_get_switch_ctx(uint8_t en_probe_direction,
                                               oam_80211_frame_ctx_union *oam_frame_report_un,
                                               oam_mng_ctx_stru *ctx)
{
    if (en_probe_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    if (oal_unlikely(oal_any_null_ptr1(oam_frame_report_un))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    oam_frame_report_un->value = ctx->pst_user_track_ctx->aen_80211_probe_switch[en_probe_direction].value;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_dhcp_arp_set_switch
 * 功能描述  : 设置广播的dhcp和arp的上报开关
 */
uint32_t oam_report_dhcp_arp_set_switch_ctx(oal_switch_enum_uint8 en_switch, oam_mng_ctx_stru *ctx)
{
    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    ctx->pst_user_track_ctx->en_tx_mcast_dhcp_arp_switch = en_switch;

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_dhcp_arp_get_switch
 * 功能描述  : 获取上报广播dhcp和arp的开关
 */
oal_switch_enum_uint8 oam_report_dhcp_arp_get_switch_ctx(oam_mng_ctx_stru *ctx)
{
    if (oal_unlikely(ctx->pst_user_track_ctx == NULL)) {
        return OAL_SWITCH_OFF;
    }

    return ctx->pst_user_track_ctx->en_tx_mcast_dhcp_arp_switch;
}

static void oam_ota_set_global_switch(uint8_t ota_switch_id, uint8_t ota_switch, oam_mng_ctx_stru *ctx)
{
    if (ctx->pst_ota_ctx == NULL) {
        return;
    }
    if (ota_switch == OAL_SWITCH_ON) {
        ctx->pst_ota_ctx->golble_switch |= (uint32_t)((uint32_t)ota_switch << ota_switch_id);
    } else {
        /* static函数，上层函数已经保证了ota_switch只有ON和OFF两种情况 */
        ctx->pst_ota_ctx->golble_switch &= (uint32_t)((uint32_t)ota_switch << ota_switch_id);
    }
}

void oam_ota_set_switch_ctx(uint8_t ota_switch_id, uint8_t ota_switch, oam_mng_ctx_stru *ctx)
{
    if ((ota_switch_id >= OAM_OTA_SWITCH_BUTT) || (ota_switch >= OAL_SWITCH_BUTT || ctx->pst_ota_ctx == NULL)) {
        return;
    }

    ctx->pst_ota_ctx->ota_switch[ota_switch_id] = ota_switch;

    /* 设置ota上报全局开关mib，上报时首先判断全局开关mib若为0，则直接返回，降低mips */
    oam_ota_set_global_switch(ota_switch_id, ota_switch, ctx);
}

/* ota上报全局开关mib，上报时首先判断该值，如果为0，则直接返回，减少消耗mips */
uint32_t oam_ota_get_global_switch_ctx(oam_mng_ctx_stru *ctx)
{
    if (ctx->pst_ota_ctx == NULL) {
        return 0;
    }
    return ctx->pst_ota_ctx->golble_switch;
}

oal_switch_enum_uint8 oam_ota_get_switch_ctx(uint8_t ota_switch_id, oam_mng_ctx_stru *ctx)
{
    if (ota_switch_id >= OAM_OTA_SWITCH_BUTT || ctx->pst_ota_ctx == NULL) {
        return OAL_SWITCH_OFF;
    }

    return ctx->pst_ota_ctx->ota_switch[ota_switch_id];
}

void oam_set_ota_board_type(oam_ota_stru *ota_data)
{
    int32_t chip_type = get_mpxx_subchip_type();
    switch (chip_type) {
        case BOARD_VERSION_MP13:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_MP13_HOST;
            break;
        case BOARD_VERSION_MP15:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_MP15_HOST;
            break;
        case BOARD_VERSION_MP16:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_MP16_HOST;
            break;
        case BOARD_VERSION_MP16C:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_MP16C_HOST;
            break;
        case BOARD_VERSION_GF61:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_GF61_HOST;
            break;
        default:
            ota_data->st_ota_hdr.auc_resv[0] = OAM_OTA_TYPE_CHIP_INVALID;
            break;
    }
}

uint32_t oam_event_init(void)
{
    /* 设置单用户跟踪相关的所有开关 */
    oam_report_set_all_switch(OAL_SWITCH_OFF);

    oam_report_dhcp_arp_set_switch(OAL_SWITCH_OFF);

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_ota_report_to_std
 * 功能描述  : 将OTA数据打印到标准窗口:
 *             (1)如果是描述符，中断信息，内存池信息，定时器信息,或者事件队列信息,
 *                则屏幕上每行打印4字节；
 *             (2)如果是帧或者内存块信息，则每行打印20字节
 *             (3)如果是帧的话，而且帧体太长，则帧体只打印前300个字节
 * 输入参数   : puc_param_one_addr:如果是描述符，则表示描述符的地址;如果是帧，表示帧头地址
 *              ul_param_one_len  :如果是描述符，则表示描述符长度;如果是帧，表示帧头长度
 *              puc_param_two_addr:如果是描述符，则为0;如果是帧，表示帧体地址
 *              ul_param_two_len  :如果是描述符，则为0;如果是帧，表示帧体长度
 *              en_ota_type       :OTA类型 取值范围 oam_ota_type_enum
 */
OAL_STATIC uint32_t oam_ota_report_to_std(uint8_t *puc_param_one_addr,
                                          uint16_t us_param_one_len,
                                          uint8_t *puc_param_two_addr,
                                          uint16_t us_param_two_len,
                                          uint8_t en_ota_type)
{
    if ((us_param_two_len == 0) || (puc_param_two_addr == NULL)) {
        oal_io_print("\n\nOTA TYPE is--> %d and OTA DATA is:\n", en_ota_type);
        oam_dump_buff_by_hex(puc_param_one_addr, us_param_one_len, 4); /* 4表示每打印4次内容则进行一次换行 */
    } else {
        /* 打印第一段内容 */
        oal_io_print("\n\nOTA TYPE is--> %d and OTA DATA the first part is:\n", en_ota_type);
        oam_dump_buff_by_hex(puc_param_one_addr, us_param_one_len, OAM_PRINT_CRLF_NUM);

        /* 打印第二段内容 */
        oal_io_print("\nOTA DATA tht second part is:\n");

        if (en_ota_type == OAM_OTA_TYPE_80211_FRAME) {
            us_param_two_len = oal_min(us_param_two_len, OAM_OTA_DATA_TO_STD_MAX_LEN);
        }

        oam_dump_buff_by_hex(puc_param_two_addr, us_param_two_len, OAM_PRINT_CRLF_NUM);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_ota_report_to_sdt
 * 功能描述  : 将空口消息上报SDT工具，包括接收描述符，发送描述符，帧
 * 输入参数  : puc_param_one_addr:如果是描述符，则表示描述符的地址;如果是帧，表示帧头地址
 *             ul_param_one_len  :如果是描述符，则表示描述符长度;如果是帧，表示帧头长度
 *             puc_param_two_addr:如果是描述符，则为0;如果是帧，表示帧体地址
 *             ul_param_two_len  :如果是描述符，则为0;如果是帧，表示帧体长度
 *             en_ota_type       :OTA类型 取值范围 oam_ota_type_enum
 */
uint32_t oam_ota_report_to_sdt_ctx(uint8_t *puc_param_one_addr,
                                   uint16_t us_param_one_len,
                                   uint8_t *puc_param_two_addr,
                                   uint16_t us_param_two_len,
                                   uint8_t en_ota_type,
                                   oam_mng_ctx_stru *ctx)
{
    uint32_t ul_ret = OAL_SUCC;
#if ((_PRE_OS_VERSION_RAW != _PRE_OS_VERSION) && (_PRE_OS_VERSION_WIN32_RAW != _PRE_OS_VERSION))
    uint32_t ul_tick;
    uint16_t us_skb_len;
    oal_netbuf_stru *pst_netbuf;
    oam_ota_stru *pst_ota_data;

    if (oal_unlikely(g_oam_sdt_func_hook.p_sdt_report_data_func == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 为上报OTA数据申请空间，如果是描述符，us_param_two_len为0 */
    us_skb_len = us_param_one_len + us_param_two_len + (uint16_t)sizeof(oam_ota_hdr_stru);
    if (us_skb_len > SDT_NETBUF_MAX_PAYLOAD) {
        us_skb_len = SDT_NETBUF_MAX_PAYLOAD;
        if ((us_param_one_len + sizeof(oam_ota_hdr_stru)) < us_skb_len) {
            us_param_two_len = us_skb_len - us_param_one_len - (uint16_t)sizeof(oam_ota_hdr_stru);
        } else {
            us_param_one_len = us_skb_len - (uint16_t)sizeof(oam_ota_hdr_stru);
            us_param_two_len = 0;
        }
    }

    pst_netbuf = oam_alloc_data2sdt((uint16_t)us_skb_len);
    if (pst_netbuf == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_ota_data = (oam_ota_stru *)oal_netbuf_data(pst_netbuf);

    /* 获取系统TICK值 */
    ul_tick = (uint32_t)oal_time_get_stamp_ms();

    pst_ota_data->st_ota_hdr.ul_tick = ul_tick;
    pst_ota_data->st_ota_hdr.en_ota_type = en_ota_type;
    oam_set_ota_board_type(pst_ota_data);

    /* 封装帧对应OTA结构体的其它成员 */
    if (en_ota_type == OAM_OTA_TYPE_80211_FRAME || en_ota_type == OAM_OTA_TYPE_MEMBLOCK) {
        pst_ota_data->st_ota_hdr.uc_frame_hdr_len = (uint8_t)us_param_one_len;
    }
    pst_ota_data->st_ota_hdr.us_ota_data_len = us_param_one_len + us_param_two_len;

    /* 复制帧头 */
    if (memcpy_s((void *)pst_ota_data->auc_ota_data, (uint32_t)(us_param_one_len + us_param_two_len),
                 (const void *)puc_param_one_addr, (uint32_t)us_param_one_len) != EOK) {
        oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
        oal_io_print("oam_ota_report_to_sdt::memcpy_s failed.\n");
        return OAL_FAIL;
    }

    /* 复制帧体 */
    if (puc_param_two_addr != NULL) {
        if (memcpy_s((void *)(pst_ota_data->auc_ota_data + us_param_one_len), (uint32_t)(us_param_two_len),
                     (const void *)puc_param_two_addr, (uint32_t)us_param_two_len) != EOK) {
            oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
            return OAL_FAIL;
        }
    }

    /* 判断sdt发送消息队列是否已满，若满输出至串口 */
    ul_ret = oam_report_data2sdt_ctx(pst_netbuf, OAM_DATA_TYPE_OTA, OAM_PRIMID_TYPE_OUTPUT_CONTENT, ctx);
#endif
    return ul_ret;
}

/*
 * 函 数 名  : oam_ota_report
 * 功能描述  : 上报OTA(over the air)事件,包括接收描述符，发送描述符，帧三种。
 * 输入参数  : puc_param_one_addr:如果是描述符，则表示描述符的地址;如果是帧，表示帧头地址
 *             ul_param_one_len  :如果是描述符，则表示描述符长度;如果是帧，表示帧头长度
 *             puc_param_two_addr:如果是描述符，则为0;如果是帧，表示帧体地址
 *             ul_param_two_len  :如果是描述符，则为0;如果是帧，表示帧体长度
 *             en_ota_type       :OTA类型 取值范围 oam_ota_type_enum
 */
uint32_t oam_ota_report_ctx(uint8_t *puc_param_one_addr,
                            uint16_t us_param_one_len,
                            uint8_t *puc_param_two_addr,
                            uint16_t us_param_two_len,
                            uint8_t en_ota_type,
                            oam_mng_ctx_stru *ctx)
{
    uint32_t ul_rslt = OAL_ERR_CODE_BUTT;

    switch (ctx->en_output_type) {
        /* 输出至控制台 */
        case OAM_OUTPUT_TYPE_CONSOLE:
            ul_rslt = oam_ota_report_to_std(puc_param_one_addr,
                                            us_param_one_len,
                                            puc_param_two_addr,
                                            us_param_two_len,
                                            en_ota_type);

            break;

        /* 输出至SDT工具 */
        case OAM_OUTPUT_TYPE_SDT:
            ul_rslt = oam_ota_report_to_sdt_ctx(puc_param_one_addr,
                                                us_param_one_len,
                                                puc_param_two_addr,
                                                us_param_two_len,
                                                en_ota_type, ctx);

            break;

        default:
            ul_rslt = OAL_ERR_CODE_INVALID_CONFIG;

            break;
    }

    if (ul_rslt != OAL_SUCC) {
        return ul_rslt;
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_dscr_to_console
 * 功能描述  : 将描述符信息打印到控制台（一般就是串口）
 * 输入参数  : puc_dscr_addr :描述符地址
 *             us_dscr_len   :描述符长度
 *             en_ota_type   :ota类型 取值范围 oam_ota_type_enum
 */
OAL_STATIC uint32_t oam_report_dscr_to_console(uint8_t *puc_dscr_addr,
                                               uint16_t us_dscr_len,
                                               uint8_t en_ota_type)
{
    if ((en_ota_type == OAM_OTA_TYPE_RX_DSCR) || (en_ota_type == OAM_OTA_TYPE_RX_DSCR_PILOT)) {
        oal_io_print("oam_report_dscr_to_console::rx_dscr info:\n\n");
    } else {
        oal_io_print("oam_report_dscr_to_console::tx_dscr info:\n\n");
    }

    oam_dump_buff_by_hex(puc_dscr_addr, us_dscr_len, 4); /* 4表示每打印4次内容则进行一次换行 */

    return OAL_SUCC;
}

/*
 * 函数 名   : oam_report_dscr_to_sdt
 * 功能描述  : 将描述符信息上报SDT
 * 输入参数  : puc_user_macaddr  :目的用户mac地址
 *             puc_dscr_addr     :描述符地址
 *             us_dscr_len       :描述符长度
 *             en_ota_type       :ota类型 取值范围 oam_ota_type_enum
 */
OAL_STATIC uint32_t oam_report_dscr_to_sdt(uint8_t *puc_user_macaddr,
                                           uint8_t *puc_dscr_addr,
                                           uint16_t us_dscr_len,
                                           uint8_t en_ota_type,
                                           oam_mng_ctx_stru *ctx)
{
    uint32_t ul_tick;
    uint16_t us_skb_len;
    oal_netbuf_stru *pst_netbuf = NULL;
    oam_ota_stru *pst_ota_data = NULL;
    uint32_t ul_ret;

    if (oal_unlikely(g_oam_sdt_func_hook.p_sdt_report_data_func == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 为上报描述符申请空间 */
    us_skb_len = us_dscr_len + (uint16_t)sizeof(oam_ota_hdr_stru);
    if (us_skb_len > SDT_NETBUF_MAX_PAYLOAD) {
        us_skb_len = SDT_NETBUF_MAX_PAYLOAD;
        us_dscr_len = SDT_NETBUF_MAX_PAYLOAD - (uint16_t)sizeof(oam_ota_hdr_stru);
    }

    pst_netbuf = oam_alloc_data2sdt((uint16_t)us_skb_len);
    if (oal_unlikely(pst_netbuf == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_ota_data = (oam_ota_stru *)oal_netbuf_data(pst_netbuf);

    /* 获取系统TICK值 */
    ul_tick = (uint32_t)oal_time_get_stamp_ms();

    /* 填写ota消息头结构体 */
    pst_ota_data->st_ota_hdr.ul_tick = ul_tick;
    pst_ota_data->st_ota_hdr.en_ota_type = en_ota_type;
    pst_ota_data->st_ota_hdr.us_ota_data_len = us_dscr_len;
    pst_ota_data->st_ota_hdr.uc_frame_hdr_len = 0;
    oal_set_mac_addr(pst_ota_data->st_ota_hdr.auc_user_macaddr, puc_user_macaddr);
    oam_set_ota_board_type(pst_ota_data);

    /* 复制数据,填写ota数据 */
    ul_ret = memcpy_s((void *)pst_ota_data->auc_ota_data,
                      (uint32_t)us_dscr_len,
                      (const void *)puc_dscr_addr,
                      (uint32_t)us_dscr_len);
    if (ul_ret != EOK) {
        oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
        oal_io_print("oam_report_dscr_to_sdt:: memcpy_s failed\r\n");
        return OAL_FAIL;
    }

    /* 判断sdt发送消息队列是否已满，若满输出至串口 */
    ul_ret = oam_report_data2sdt_ctx(pst_netbuf, OAM_DATA_TYPE_OTA, OAM_PRIMID_TYPE_OUTPUT_CONTENT, ctx);

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_dscr
 * 功能描述  : 将描述符上报sdt,包括上报tx描述符和rx描述符
 *            注意::由于rx描述符最大长度为64，tx描述符最大长度为256，所以如果参数
 *            us_dscr_len大于256的话表明传入参数错误，直接返回
 * 输入参数  : puc_user_macaddr  :目的用户mac地址
 *             puc_dscr_addr     :描述符地址
 *             us_dscr_len       :描述符长度
 *             en_ota_type       :ota类型(rx描述符或者tx描述符)，由于描述符的上报
 *             是通过ota通道，因此需要这个参数，SDT解析的时候可以显示上报的是rx描
 *             述符还是tx描述符 取值范围 oam_ota_type_enum
 */
uint32_t oam_report_dscr_ctx(uint8_t *puc_user_macaddr,
                             uint8_t *puc_dscr_addr,
                             uint16_t us_dscr_len,
                             uint8_t en_ota_type,
                             oam_mng_ctx_stru *ctx)
{
    uint32_t ul_ret;

    if (oal_unlikely(oal_any_null_ptr2(puc_user_macaddr, puc_dscr_addr))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if ((us_dscr_len > WLAN_MEM_SHARED_TX_DSCR_SIZE2) ||
        (us_dscr_len == 0)) {
        oam_dump_buff_by_hex(puc_dscr_addr, us_dscr_len, OAM_PRINT_CRLF_NUM);
        return OAL_ERR_CODE_OAM_EVT_DSCR_LEN_INVALID;
    }

    if (en_ota_type >= OAM_OTA_TYPE_BUTT) {
        return OAL_ERR_CODE_INVALID_CONFIG;
    }

    switch (ctx->en_output_type) {
        /* 输出至控制台 */
        case OAM_OUTPUT_TYPE_CONSOLE:
            ul_ret = oam_report_dscr_to_console(puc_dscr_addr, us_dscr_len, en_ota_type);

            break;

        /* 输出至SDT工具 */
        case OAM_OUTPUT_TYPE_SDT:
            ul_ret = oam_report_dscr_to_sdt(puc_user_macaddr, puc_dscr_addr, us_dscr_len, en_ota_type, ctx);

            break;

        default:
            ul_ret = OAL_ERR_CODE_INVALID_CONFIG;

            break;
    }

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_eth_frame_to_console
 * 功能描述  : 将beacon帧内容打印到控制台（一般是串口）
 * 输入参数  ：en_eth_frame_direction 取值范围 oam_ota_frame_direction_type_enum
 */
OAL_STATIC uint32_t oam_report_eth_frame_to_console(uint8_t *puc_eth_frame_hdr_addr,
                                                    uint16_t us_eth_frame_len,
                                                    uint8_t en_eth_frame_direction)
{
    uint8_t *puc_eth_frame_body_addr = NULL;
    uint16_t us_eth_frame_body_len;

    if (en_eth_frame_direction == OAM_OTA_FRAME_DIRECTION_TYPE_TX) {
        oal_io_print("oam_report_eth_frame_to_console::recv frame from eth:\n");
    } else {
        oal_io_print("oam_report_eth_frame_to_console::report frame to eth:\n");
    }

    oal_io_print("oam_report_eth_frame_to_console::eth_frame header:\n");
    oam_dump_buff_by_hex(puc_eth_frame_hdr_addr, ETHER_HDR_LEN, OAM_PRINT_CRLF_NUM);

    puc_eth_frame_body_addr = puc_eth_frame_hdr_addr + ETHER_HDR_LEN;
    us_eth_frame_body_len = us_eth_frame_len - ETHER_HDR_LEN;

    oal_io_print("oam_report_eth_frame_to_console::eth_frame body:\n");
    oam_dump_buff_by_hex(puc_eth_frame_body_addr, us_eth_frame_body_len, OAM_PRINT_CRLF_NUM);

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_report_eth_frame_to_sdt
 * 功能描述  : 将以太网帧内容上报SDT
 * 输入参数  : puc_user_mac_addr      :目的用户mac地址
 *             puc_eth_frame_hdr_addr :以太网帧头地址
 *             us_eth_frame_len       :以太网帧长度(帧头+帧体)
 *             en_eth_frame_direction :来自以太网(tx流程)还是发往以太网(rx流程)
 *             en_eth_frame_direction->oam_ota_frame_direction_type_enum
 */
OAL_STATIC uint32_t oam_report_eth_frame_to_sdt(uint8_t *puc_user_mac_addr,
                                                uint8_t *puc_eth_frame_hdr_addr,
                                                uint16_t us_eth_frame_len,
                                                uint8_t en_eth_frame_direction,
                                                oam_mng_ctx_stru *ctx)
{
    uint32_t ul_tick;
    uint16_t us_skb_len;
    oal_netbuf_stru *pst_netbuf = NULL;
    oam_ota_stru *pst_ota_data = NULL;
    uint32_t ul_ret;

    if (oal_unlikely(g_oam_sdt_func_hook.p_sdt_report_data_func == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 为上报beacon帧申请空间 */
    us_skb_len = us_eth_frame_len + (uint16_t)sizeof(oam_ota_hdr_stru);
    if (us_skb_len > SDT_NETBUF_MAX_PAYLOAD) {
        us_skb_len = SDT_NETBUF_MAX_PAYLOAD;
        us_eth_frame_len = SDT_NETBUF_MAX_PAYLOAD - (uint16_t)sizeof(oam_ota_hdr_stru);
    }

    pst_netbuf = oam_alloc_data2sdt((uint16_t)us_skb_len);
    if (oal_unlikely(pst_netbuf == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_ota_data = (oam_ota_stru *)oal_netbuf_data(pst_netbuf);

    /* 获取系统TICK值 */
    ul_tick = (uint32_t)oal_time_get_stamp_ms();

    /* 填写ota消息头结构体 */
    pst_ota_data->st_ota_hdr.ul_tick = ul_tick;
    pst_ota_data->st_ota_hdr.en_ota_type = OAM_OTA_TYPE_ETH_FRAME;
    pst_ota_data->st_ota_hdr.uc_frame_hdr_len = ETHER_HDR_LEN;
    pst_ota_data->st_ota_hdr.us_ota_data_len = us_eth_frame_len;
    pst_ota_data->st_ota_hdr.en_frame_direction = en_eth_frame_direction;
    oal_set_mac_addr(pst_ota_data->st_ota_hdr.auc_user_macaddr, puc_user_mac_addr);
    oam_set_ota_board_type(pst_ota_data);

    /* 复制数据,填写ota数据 */
    ul_ret = memcpy_s((void *)pst_ota_data->auc_ota_data,
                      (uint32_t)us_eth_frame_len,
                      (const void *)puc_eth_frame_hdr_addr,
                      (uint32_t)us_eth_frame_len);
    if (ul_ret != EOK) {
        oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
        oal_io_print("oam_report_eth_frame_to_sdt:: memcpy_s failed\r\n");
        return OAL_FAIL;
    }
    /* 下发至sdt接收队列，若队列满则串口输出 */
    ul_ret = oam_report_data2sdt_ctx(pst_netbuf, OAM_DATA_TYPE_OTA, OAM_PRIMID_TYPE_OUTPUT_CONTENT, ctx);

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_eth_frame
 * 功能描述  : 上报以太网帧，此接口只能用在两个地方:
 *             (1)发送流程，从以太网收到包之后，在wal_bridge_vap_xmit中
 *             (2)接收流程，将帧上报以太网之前，在hmac_rx_transmit_msdu_to_lan中调用
 *             oal_netif_rx之前
 * 输入参数  : puc_user_mac_addr      :目的用户mac地址
 *             us_user_idx            :用户资源池id
 *             puc_eth_frame_hdr_addr :以太网帧头地址
 *             us_eth_frame_len       :以太网帧长度(帧头+帧体)
 *             en_eth_frame_direction :来自以太网(tx流程)还是发往以太网(rx流程)
 *             en_eth_frame_direction->oam_ota_frame_direction_type_enum
 */
uint32_t oam_report_eth_frame_ctx(uint8_t *puc_user_mac_addr,
                                  uint8_t *puc_eth_frame_hdr_addr,
                                  uint16_t us_eth_frame_len,
                                  uint8_t en_eth_frame_direction,
                                  oam_mng_ctx_stru *ctx)
{
    uint32_t ul_ret;

    if (oal_unlikely(oal_any_null_ptr2(puc_user_mac_addr, puc_eth_frame_hdr_addr))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if ((us_eth_frame_len > ETHER_MAX_LEN) ||
        (us_eth_frame_len < ETHER_HDR_LEN)) {
        oam_dump_buff_by_hex(puc_eth_frame_hdr_addr, us_eth_frame_len, OAM_PRINT_CRLF_NUM);

        return OAL_ERR_CODE_OAM_EVT_FR_LEN_INVALID;
    }

    if (oal_unlikely(en_eth_frame_direction >= OAM_OTA_FRAME_DIRECTION_TYPE_BUTT)) {
        return OAL_ERR_CODE_OAM_EVT_FRAME_DIR_INVALID;
    }

    switch (ctx->en_output_type) {
        /* 输出至控制台 */
        case OAM_OUTPUT_TYPE_CONSOLE:
            ul_ret = oam_report_eth_frame_to_console(puc_eth_frame_hdr_addr,
                                                     us_eth_frame_len,
                                                     en_eth_frame_direction);

            break;

        /* 输出至SDT工具 */
        case OAM_OUTPUT_TYPE_SDT:
            ul_ret = oam_report_eth_frame_to_sdt(puc_user_mac_addr,
                                                 puc_eth_frame_hdr_addr,
                                                 us_eth_frame_len,
                                                 en_eth_frame_direction, ctx);
            break;

        default:
            ul_ret = OAL_ERR_CODE_INVALID_CONFIG;

            break;
    }

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_netbuf_cb_to_sdt
 * 功能描述  : 将80211帧的CB字段上报SDT
 * 输入参数  : puc_user_mac_addr  :目的用户mac地址
 *             puc_netbuf_cb      :要上报的CB字段
 *             en_frame_direction :接收还是发送
 *             en_ota_type       :ota类型 取值范围 oam_ota_type_enum
 */
OAL_STATIC uint32_t oam_report_netbuf_cb_to_sdt(uint8_t *user_mac_addr,
                                                uint8_t *netbuf_cb,
                                                uint16_t cb_len,
                                                uint8_t en_ota_type,
                                                oam_mng_ctx_stru *ctx)
{
    uint32_t ul_ret = OAL_SUCC;
#if ((_PRE_OS_VERSION_RAW != _PRE_OS_VERSION) && (_PRE_OS_VERSION_WIN32_RAW != _PRE_OS_VERSION))
    uint32_t ul_tick;
    uint16_t us_ota_data_len;
    uint16_t us_skb_len;
    oal_netbuf_stru *pst_netbuf;
    oam_ota_stru *pst_ota_data;

    if (oal_unlikely(g_oam_sdt_func_hook.p_sdt_report_data_func == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    us_skb_len = cb_len + (uint16_t)sizeof(oam_ota_hdr_stru) + OAM_RESERVE_SKB_LEN;
    us_ota_data_len = cb_len + (uint16_t)sizeof(oam_ota_hdr_stru);

    pst_netbuf = oal_mem_sdt_netbuf_alloc((uint16_t)us_skb_len, OAL_TRUE);
    if (pst_netbuf == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_netbuf_reserve(pst_netbuf, OAM_RESERVE_SKB_HEADROOM_LEN);

    oal_netbuf_put(pst_netbuf, us_ota_data_len);
    pst_ota_data = (oam_ota_stru *)oal_netbuf_data(pst_netbuf);

    /* 获取系统TICK值 */
    ul_tick = (uint32_t)oal_time_get_stamp_ms();

    /* 填写ota消息头结构体 */
    pst_ota_data->st_ota_hdr.ul_tick = ul_tick;
    pst_ota_data->st_ota_hdr.en_ota_type = en_ota_type;
    pst_ota_data->st_ota_hdr.us_ota_data_len = cb_len;
    pst_ota_data->st_ota_hdr.uc_frame_hdr_len = 0;
    oal_set_mac_addr(pst_ota_data->st_ota_hdr.auc_user_macaddr, user_mac_addr);
    oam_set_ota_board_type(pst_ota_data);

    /* 复制数据,填写ota数据 */
    ul_ret = memcpy_s((void *)pst_ota_data->auc_ota_data,
                      cb_len,
                      (const void *)netbuf_cb,
                      cb_len);
    if (ul_ret != EOK) {
        oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
        oal_io_print("oam_report_netbuf_cb_to_sdt:: memcpy_s failed\r\n");
        return OAL_FAIL;
    }
    /* 上报SDT */
    ul_ret = oam_report_data2sdt_ctx(pst_netbuf, OAM_DATA_TYPE_OTA, OAM_PRIMID_TYPE_OUTPUT_CONTENT, ctx);
#endif
    return ul_ret;
}

/*
 * 函 数 名  : oam_report_netbuf_cb
 * 功能描述  : 上报80211的cb字段
 * 输入参数  : puc_user_mac_addr  :目的用户mac地址
 *             puc_netbuf_cb      :要上报的CB字段
 *             en_frame_direction :接收还是发送
 *             en_ota_type       :ota类型 取值范围 oam_ota_type_enum
 */
uint32_t oam_report_netbuf_cb_ctx(uint8_t *user_mac_addr,
                                  uint8_t *netbuf_cb,
                                  uint16_t cb_len,
                                  uint8_t en_ota_type,
                                  oam_mng_ctx_stru *ctx)
{
    uint32_t ul_ret;

    if (oal_any_null_ptr2(user_mac_addr, netbuf_cb)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_ota_type >= OAM_OTA_TYPE_BUTT || cb_len > OAM_SKB_CB_LEN) {
        return OAL_ERR_CODE_INVALID_CONFIG;
    }

    ul_ret = oam_report_netbuf_cb_to_sdt(user_mac_addr, netbuf_cb, cb_len, en_ota_type, ctx);

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_dft_params_to_sdt
 * 功能描述  : 将维测信息数据上报sdt
 * 参数：    ：en_type 取值范围 oam_ota_type_enum
 */
uint32_t oam_report_dft_params_to_sdt(uint8_t *puc_user_mac_addr,
                                      uint8_t *puc_param,
                                      uint16_t us_param_len,
                                      uint8_t en_type,
                                      oam_mng_ctx_stru *ctx)
{
    uint32_t ul_tick;
    uint16_t us_ota_data_len;
    uint16_t us_skb_len;
    oal_netbuf_stru *pst_netbuf = NULL;
    oam_ota_stru *pst_ota_data = NULL;
    uint32_t ul_ret;

    if (oal_unlikely(g_oam_sdt_func_hook.p_sdt_report_data_func == NULL)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    us_ota_data_len = us_param_len + (uint16_t)sizeof(oam_ota_hdr_stru);
    us_skb_len = us_ota_data_len + OAM_RESERVE_SKB_LEN;

    if (us_skb_len > SDT_NETBUF_MAX_PAYLOAD) {
        return OAL_FAIL;
    }

    pst_netbuf = oal_mem_sdt_netbuf_alloc(us_skb_len, OAL_TRUE);
    if (pst_netbuf == NULL) {
        return OAL_ERR_CODE_PTR_NULL;
    }
    oal_netbuf_reserve(pst_netbuf, OAM_RESERVE_SKB_HEADROOM_LEN);

    oal_netbuf_put(pst_netbuf, us_ota_data_len);
    pst_ota_data = (oam_ota_stru *)oal_netbuf_data(pst_netbuf);

    /* 获取系统TICK值 */
    ul_tick = (uint32_t)oal_time_get_stamp_ms();

    /* 填写ota消息头结构体 */
    pst_ota_data->st_ota_hdr.ul_tick = ul_tick;
    pst_ota_data->st_ota_hdr.en_ota_type = en_type;
    pst_ota_data->st_ota_hdr.us_ota_data_len = us_param_len;
    pst_ota_data->st_ota_hdr.uc_frame_hdr_len = 0;
    oal_set_mac_addr(pst_ota_data->st_ota_hdr.auc_user_macaddr, puc_user_mac_addr);
    oam_set_ota_board_type(pst_ota_data);

    /* 复制数据,填写ota数据 */
    if (memcpy_s((void *)pst_ota_data->auc_ota_data,
                 (uint32_t)us_param_len,
                 (const void *)puc_param,
                 (uint32_t)us_param_len) != EOK) {
        oal_mem_sdt_netbuf_free(pst_netbuf, OAL_TRUE);
        oal_io_print("oam_report_dft_params_to_sdt:: memcpy_s failed\r\n");
        return OAL_FAIL;
    }
    /* 上报SDT */
    ul_ret = oam_report_data2sdt_ctx(pst_netbuf, OAM_DATA_TYPE_OTA, OAM_PRIMID_TYPE_OUTPUT_CONTENT, ctx);

    return ul_ret;
}

/*
 * 函 数 名  : oam_report_phy_stat
 * 功能描述  : 上报维测信息数据
 * 参数：    ：en_type 取值范围 oam_ota_type_enum
 */
uint32_t oam_report_dft_params_ctx(uint8_t *puc_user_mac_addr,
                                   uint8_t *puc_param,
                                   uint16_t us_param_len,
                                   uint8_t en_type,
                                   oam_mng_ctx_stru *ctx)
{
    if (oal_unlikely(oal_any_null_ptr2(puc_user_mac_addr, puc_param))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (en_type >= OAM_OTA_TYPE_BUTT) {
        return OAL_ERR_CODE_INVALID_CONFIG;
    }

    if (us_param_len != 0) {
        return oam_report_dft_params_to_sdt(puc_user_mac_addr, puc_param, us_param_len, en_type, ctx);
    }

    return OAL_ERR_CODE_INVALID_CONFIG;
}

/*
 * 函 数 名  : oam_report_set_all_switch
 * 功能描述  : 设置所有用户帧上报的所有开关，如果是1，则上报所有类型帧的帧内容，
 *             cb字段，描述符；如果是0，则什么都不上报
 */
void oam_report_set_all_switch_ctx(oal_switch_enum_uint8 en_switch, oam_mng_ctx_stru *ctx)
{
    if (ctx->pst_user_track_ctx == NULL || ctx->pst_ota_ctx == NULL) {
        return;
    }

    memset_s(ctx->pst_user_track_ctx, sizeof(oam_user_track_ctx_stru),
        en_switch == OAL_SWITCH_OFF ? 0x00 : 0xFF, sizeof(oam_user_track_ctx_stru));
    memset_s(ctx->pst_ota_ctx, sizeof(oam_ota_ctx_stru),
        en_switch == OAL_SWITCH_OFF ? OAL_SWITCH_OFF : OAL_SWITCH_ON, sizeof(oam_ota_ctx_stru));
    ctx->pst_ota_ctx->golble_switch = en_switch == OAL_SWITCH_ON ? 0xFFFFFFFF : 0x0;
}

/*
 * 函 数 名  : oam_report_backtrace
 * 功能描述  : 通过OAM上报调用栈
 */
void oam_report_backtrace_ctx(oam_mng_ctx_stru *ctx)
{
    uint8_t *puc_buff = (uint8_t *)oal_mem_alloc_ctx(OAL_MEM_POOL_ID_LOCAL, OAM_REPORT_MAX_STRING_LEN, OAL_TRUE,
        CUR_OAL_MEM_CONTEXT);

    if (puc_buff == NULL) {
        oam_error_log0(0, OAM_SF_CFG, "{oam_report_backtrace::pc_print_buff null.}");
        return;
    }

    if (oal_dump_stack_str(puc_buff, OAM_REPORT_MAX_STRING_LEN) > 0) {
        oam_print_ctx((int8_t *)puc_buff, ctx);
    } else {
        oam_warning_log0(0, OAM_SF_CFG, "{oam_report_backtrace::dump stack str failed.}");
    }

    oal_mem_free_ctx(puc_buff, OAL_TRUE, CUR_OAL_MEM_CONTEXT);
}

oal_module_symbol(oam_report_backtrace_ctx);
oal_module_symbol(oam_ota_report_ctx);
oal_module_symbol(oam_report_dscr_ctx);
oal_module_symbol(oam_report_eth_frame_ctx);
oal_module_symbol(oam_ota_set_switch_ctx);
oal_module_symbol(oam_ota_get_global_switch_ctx);
oal_module_symbol(oam_ota_get_switch_ctx);
oal_module_symbol(oam_set_ota_board_type);
oal_module_symbol(oam_report_eth_frame_set_switch_ctx);
oal_module_symbol(oam_report_eth_frame_get_switch_ctx);
oal_module_symbol(oam_report_80211_mcast_set_switch_ctx);
oal_module_symbol(oam_report_80211_mcast_get_switch_ctx);
oal_module_symbol(oam_report_80211_ucast_set_switch_ctx);
oal_module_symbol(oam_report_80211_ucast_get_switch_ctx);
oal_module_symbol(oam_report_80211_probe_set_switch_ctx);
oal_module_symbol(oam_report_80211_probe_get_switch_ctx);
oal_module_symbol(oam_report_netbuf_cb_ctx);
oal_module_symbol(oam_report_set_all_switch_ctx);
oal_module_symbol(oam_report_dhcp_arp_get_switch_ctx);
oal_module_symbol(oam_report_dhcp_arp_set_switch_ctx);
oal_module_symbol(oam_report_dft_params_ctx);
oal_module_symbol(oam_report_data_get_global_switch_ctx);
