/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <product_config.h>
#include <linux/list.h>
#include <linux/semaphore.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <securec.h>

#include <mdrv_msg.h>
#include <mdrv_timer.h>
#include <mdrv_chr.h>

#include <osl_types.h>
#include <osl_malloc.h>

#include <bsp_chr.h>

#include <msg_id.h>

#include "chr_core.h"
#include "chr_app.h"
#include "chr_report.h"


#undef THIS_MODU
#define THIS_MODU mod_chr

chr_app_msg_record_s g_chr_app_msg_record; // 储存查询上报的参数

timer_handle g_chr_timer;

// 查询上报超时处理函数，不等没有返回的组件，直接结束。
int chr_timer_timeout_proc(int para)
{
    chr_rcv_msg_finish();
    return BSP_OK;
}

// 各组件给Om上报消息已经完毕，通知上层
#define OM_ERR_LOG_MSG_ERR_REPORT_END 0x2
void chr_rcv_msg_finish(void)
{
    chr_app_report_status_s app_report_status;

    if (memset_s(&app_report_status, sizeof(app_report_status), 0, sizeof(app_report_status)) != EOK) {
        chr_print("memset failed!\n");
    }

    app_report_status.chr_om_header.msg_type = OM_ERR_LOG_MSG_ERR_REPORT_END;
    app_report_status.chr_om_header.msg_sn = 0;
    app_report_status.chr_om_header.msg_len = sizeof(chr_app_report_status_s) - sizeof(chr_alarm_msg_head_s);
    app_report_status.modem_id = g_chr_app_msg_record.modem_id;
    app_report_status.fault_id = g_chr_app_msg_record.fault_id;
    app_report_status.report_status = g_chr_app_msg_record.report_need;

    mdrv_timer_get_accuracy_timestamp(&app_report_status.high_slice, &app_report_status.low_slice);

    chr_send_app_data((unsigned char *)&app_report_status, sizeof(chr_app_report_status_s));

    /* 防止消息再次下发不成功 */
    g_chr_app_msg_record.report_need = OM_AP_SEND_MSG_FINISH;
    g_chr_app_msg_record.state = ERRLOG_IDLE;

    chr_print("success!\n");
    return;
}

int chr_rcv_msg_header_check(chr_recv_report_s *recv_chr_data, int *check_flag)
{
    if (g_chr_app_msg_record.state == ERRLOG_IDLE) {
        chr_print("state is idle, drop the message!\n");
        return BSP_ERROR;
    }
    (*check_flag)++;
    g_chr_app_msg_record.report_need--;
    return BSP_OK;
}

int chr_rcv_msg_check(chr_recv_report_s *recv_chr_data)
{
    int check_flag = 0;
    switch (recv_chr_data->chr_type_union.msg_type) {
        // 查询上报
        case OM_ERR_LOG_MSG_ERR_REPORT:
            if (chr_rcv_msg_header_check(recv_chr_data, &check_flag) != EOK) {
                return BSP_ERROR;
            }
            break;
        // 故障主动上报
        case OM_ERR_LOG_MSG_FAULT_REPORT:
            check_flag++;
            break;
        // 警告主动上报
        case OM_ERR_LOG_MSG_ALARM_REPORT:
            check_flag++;
            break;
        // 异常处理
        default:
            chr_print("Msg type wrong!\n ");
            return BSP_ERROR;
    }

    if (check_flag == OM_AP_NO_MSG_SEND) {
        chr_print("No msg Send!\n ");
        return BSP_ERROR;
    }
    return BSP_OK;
}

void chr_tsp_msg_proc(void *msg)
{
    int ret;
    chr_recv_report_s *recv_chr_data;

    recv_chr_data = (chr_recv_report_s *)msg;

    // 判断是否是主动上报或者查询上报
    if ((recv_chr_data->chr_rcv_header.msgname != ID_OM_ERR_LOG_REPORT_CNF) &&
        (recv_chr_data->chr_rcv_header.msgname != ID_OM_FAULT_ERR_LOG_IND) &&
        (recv_chr_data->chr_rcv_header.msgname != ID_OM_ALARM_ERR_LOG_IND)) {
        chr_log_print("not chr msg\n");
        return;
    }

    // 收到消息检查是否需要上报
    ret = chr_rcv_msg_check(recv_chr_data);
    if (ret != EOK) {
        chr_log_print("rcv msg wrong!\n ");
        return;
    }

    recv_chr_data->chr_type_union.chr_type.msg_type_short = recv_chr_data->chr_type_union.msg_type & 0xffff;
    recv_chr_data->chr_type_union.chr_type.fault_id = recv_chr_data->chr_rcv_header.faultid;

    // 把这条chr发走。
    chr_send_app_data((unsigned char *)&recv_chr_data->chr_type_union.msg_type,
                      recv_chr_data->rpt_len + sizeof(chr_alarm_msg_head_s));
    chr_log_print("msg send success,name 0x%x, type 0x%x, moduleid 0x%x\n",
        recv_chr_data->chr_rcv_header.msgname, recv_chr_data->chr_type_union.chr_type.msg_type_short,
        recv_chr_data->chr_rcv_header.moduleid);

    // 如果这条chr是查询上报的返回的，而且需要返回的计数值已经到完成标志，就可以结束这次查询上报。
    if ((recv_chr_data->chr_type_union.chr_type.msg_type_short == OM_ERR_LOG_MSG_ERR_REPORT) &&
        (g_chr_app_msg_record.report_need == OM_AP_SEND_MSG_FINISH)) {
        mdrv_timer_delete(g_chr_timer);
        chr_rcv_msg_finish();
        chr_log_print("report all msg, stop timer\n");
    }
    return;
}

void chr_report_need_num_proc(void *msg)
{
    chr_report_need_num_s *report_need_num = (chr_report_need_num_s *)msg;
    if (report_need_num->msg_sn != g_chr_app_msg_record.msg_sn) {
        chr_print("wrong report num, report sn not match\n");
        return;
    }
    g_chr_app_msg_record.alarm_id_num = report_need_num->num;
    g_chr_app_msg_record.report_need = report_need_num->num;
    return;
}

// 查询上报的fault_id, modem_id, msg_sn发送C核
int chr_request_send(void)
{
    int ret;
    unsigned int malloc_size;
    chr_request_send_s *request_msg;

    // 分配消息内存，选取MSG_DEFAULT意味着只分配除了msg_hd以外的长度。
    malloc_size = sizeof(chr_request_send_s) - MDRV_MSG_HEAD_LEN;
    request_msg = (chr_request_send_s *)mdrv_msg_alloc(DRV_MID_CHR_APSS, malloc_size, MSG_DEFAULT);
    if (request_msg == NULL) {
        chr_print("msg alloc failed\n");
        return OM_APP_MEM_ALLOC_MSG_ERR;
    }

    // 把分配的消息内存各处填入信息
    MDRV_MSG_HEAD_FILL(request_msg, DRV_MID_CHR_APSS, DRV_MID_CHR_TSP, malloc_size);
    request_msg->msg_name = CHR_REQUEST_SEND_TO_TSP;
    request_msg->fault_id = g_chr_app_msg_record.fault_id;
    request_msg->modem_id = g_chr_app_msg_record.modem_id;
    request_msg->msg_sn = g_chr_app_msg_record.msg_sn;

    ret = mdrv_msg_send(request_msg, MSG_DEFAULT);
    if (ret != EOK) {
        mdrv_msg_free(DRV_MID_CHR_APSS, request_msg);
        chr_print("request msg send failed!\n");
        return OM_APP_SEND_CCPU_FAIL;
    }
    return BSP_OK;
}


// 检查这一轮查询上报有没有发送完
int chr_rcv_app_msg_check(chr_app_om_req_s *app_om_req)
{
    /* 如果没有上报完成 */
    if ((g_chr_app_msg_record.report_need != OM_AP_SEND_MSG_FINISH) ||
        (g_chr_app_msg_record.state != ERRLOG_IDLE)) {
        chr_print("error log report not end. reportsend = %d!\n ", g_chr_app_msg_record.report_need);
        return OM_APP_REPORT_NOT_FINISH_ERR;
    }
    return BSP_OK;
}

// 接收到查询上报请求的处理函数
int chr_request_chr_proc(unsigned char *data, unsigned int msg_len)
{
    int ret;
    chr_app_om_req_s *app_om_req = NULL;
    timer_attr_s attr = {"chr_timer", CHR_TIMER_LENTH, TIMER_FLAG_DEFAULT, chr_timer_timeout_proc, 0};

    if (msg_len < sizeof(chr_app_om_req_s)) {
        chr_print("input length too short !\n");
        return OM_APP_MSG_LENGTH_ERR;
    }

    // 收到AP消息检查
    app_om_req = (chr_app_om_req_s *)data;

    // 输入消息长度的检查
    if (msg_len != (app_om_req->chr_om_header.msg_len + sizeof(chr_alarm_msg_head_s))) {
        chr_print("input length not match !\n");
        return OM_APP_MSG_LENGTH_ERR;
    }

    // 检查上一次上报是否完成
    ret = chr_rcv_app_msg_check(app_om_req);
    if (ret != EOK) {
        chr_print("check req failed. status = 0x%x,fauiltid = %d, modemid = %d!\n", ret, app_om_req->fault_id,
                  app_om_req->modem_id);
        return OM_APP_REPORT_NOT_FINISH_ERR;
    }

    g_chr_app_msg_record.state = ERRLOG_BUSY;
    g_chr_app_msg_record.fault_id = app_om_req->fault_id;
    g_chr_app_msg_record.modem_id = app_om_req->modem_id;
    g_chr_app_msg_record.msg_sn++;

    ret = chr_request_send();
    if (ret != EOK) {
        chr_print("send failed.\n");
        return BSP_ERROR;
    }

    // 起查询上报定时器，5秒
    g_chr_timer = mdrv_timer_add(&attr);
    if (g_chr_timer < MDRV_OK) {
        chr_print("fail to add chr_timer.handle=%d.\n", (int)g_chr_timer);
        return BSP_ERROR;
    }

    return BSP_OK;
}


// a核主动上报
int bsp_chr_drv_ind(void *data, unsigned int len)
{
    chr_drv_ind_s *recv_data = NULL;

    if (data == NULL) {
        chr_print("given data null\n");
        return BSP_ERROR;
    }
    if (len < sizeof(chr_drv_ind_s)) {
        chr_print("given data len too short\n");
        return BSP_ERROR;
    }

    recv_data = (chr_drv_ind_s *)data;
    chr_send_app_data((unsigned char *)&(recv_data->msg_type), recv_data->msglen + sizeof(chr_alarm_msg_head_s));

    return BSP_OK;
}

EXPORT_SYMBOL(bsp_chr_drv_ind);
