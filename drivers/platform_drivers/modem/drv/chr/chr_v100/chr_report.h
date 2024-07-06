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

#ifndef __CHR_REPORT_H__
#define __CHR_REPORT_H__

#include "chr_app.h"


#define     ID_OM_ERR_LOG_CTRL_IND          (0x9001)
#define     ID_OM_ERR_LOG_REPORT_REQ        (0x9002)
#define     ID_OM_ERR_LOG_REPORT_CNF        (0x9003)

// 平台检测故障主动上报消息名称
#define ID_OM_FAULT_ERR_LOG_IND (0x9009)
// 平台检测告警主动上报消息名称
#define ID_OM_ALARM_ERR_LOG_IND (0x900A)


#define CHR_TIMER_LENTH 5000000 // 定时器，单位微秒

#define OM_PID_NULL 0           /* OM PID为空 */
#define OM_AP_NO_MSG_SEND 0     /* OM上报没有给AP上报的消息 */
#define OM_AP_SEND_MSG_FINISH 0 /* OM上报给AP消息完成 */

#define ERRLOG_IDLE 0
#define ERRLOG_BUSY 1


/* OM收到AP需要在全局变量中记录内容 g_chr_app_msg_record */
typedef struct {
    unsigned short fault_id;          /* 本次请求的faultid */
    unsigned short modem_id;          /* 本次请求的modemid */
    unsigned int alarm_id_num;       /* 本次请求的alarm配置总数 */
    unsigned int report_need; /* 记录需要上报alarm个数，差别在于可能某些pid在当前版本不存在 */
    unsigned int state;      /* 请求处理状态 */
    unsigned int msg_sn;
} chr_app_msg_record_s;

// 查询上报发给C核结构体
typedef struct {
    struct msg_head msg_hd;
    unsigned int msg_name;
    unsigned int modem_id;
    unsigned int fault_id;
    unsigned int msg_sn;
} chr_request_send_s;

// c核告知的查询上报数目的结构体
typedef struct {
    struct msg_head msg_hd;
    unsigned int msg_name;
    unsigned int num;
    unsigned int msg_sn;
} chr_report_need_num_s;

int chr_request_chr_proc(unsigned char *data, unsigned int msg_len);
void chr_tsp_msg_proc(void *msg);
void chr_rcv_msg_finish(void);
void chr_report_need_num_proc(void *msg);
#endif
