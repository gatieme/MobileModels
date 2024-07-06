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

#ifndef __CHR_APP_H__
#define __CHR_APP_H__

#include <mdrv_msg.h>
#include <bsp_chr.h>

#define CHR_PRE_ALLOC_LEN 4

/* 错误码,与ap之间的错误码 */
typedef enum {
    OM_APP_MSG_OK = 0x00,                    // MSG_OK
    OM_APP_VCOM_DEV_INDEX_ERR = 0x01,
    OM_APP_MSG_LENGTH_ERR = 0x02,            // 消息长度错误
    OM_APP_MSG_TYPE_ERR = 0x03,              // 消息类型错误
    OM_APP_SEND_MODEM_ID_ERR = 0x04,         // Modem_id错误
    OM_APP_MEM_ALLOC_MSG_ERR = 0x06,         // 分配消息内存错误
    OM_APP_READ_NV_ERR = 0x07,               // 读nv错误
    OM_APP_GET_NVID_ERR = 0x08,              // 取NVID错误
    OM_APP_MSG_MODULE_ID_ERR = 0x09,         // 消息module_id错误
    OM_APP_REPORT_NOT_FINISH_ERR = 0x0A,     // 上报未完成错误
    OM_APP_ERRLOG_START_TIMER_ERR = 0x0B,    // 启动定时器错误
    OM_APP_MEM_ALLOC_ERR = 0x0C,             // 分配内存错误
    OM_APP_PARAM_INAVALID = 0x0D,            // 参数无效
    OM_APP_SEND_CCPU_FAIL = 0x0E,            // 给C核发消息错误
    OM_APP_SAVE_LIST_FAIL = 0x0F,            // 存链表错误
    OM_APP_SEND_RESULT_BUTT                  // BUTT
} chr_app_send_result_e;


typedef struct {
    struct msg_head msg_hd;
    unsigned int msgname;
    unsigned int moduleid;
    unsigned short faultid; // 主动上报时，GUTL不关注 ,x模的需要填写
    unsigned short alarmid;
    unsigned short alarm_type; // 被动上报时，不关注
    unsigned short resv;
} chr_rcv_data_header_s;

typedef struct {
    chr_rcv_data_header_s chr_rcv_header;

    // app下发的时候，发的是unsigned int msg_type
    // 给app上报的时，需要使用unsigned short msg_type_short 和 unsigned short fault_id，一起形成union
    union {
        unsigned int msg_type;
        struct {
            unsigned short msg_type_short;
            unsigned short fault_id;
        } chr_type;
    } chr_type_union;

    unsigned int msg_sn;
    unsigned int rpt_len;
} chr_recv_report_s;

// 上报的chr结构体
typedef struct {
    chr_rcv_data_header_s chr_om_header;
    unsigned int msgtype;
    unsigned int msgsn;
    unsigned int rptlen;
    unsigned char data[CHR_PRE_ALLOC_LEN]; // 上报的内容
} chr_fault_ind_s;


/* APP-->OM error log, chr_om_header */
typedef struct {
    unsigned int msg_type;
    unsigned int msg_sn;
    unsigned int msg_len;
} chr_alarm_msg_head_s;


/* Error log 上报完成 type=0x02 OM-> APP  这个就是用来回复APP查询上报结果的  */
typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned int module_id;
    unsigned short modem_id;
    unsigned short fault_id;
    unsigned int report_status; /* result */
    unsigned int low_slice;     /* 记录触发上报请求时的时间戳 */
    unsigned int high_slice;
} chr_app_report_status_s;

/* APP请求Error log上报 type=0x01 App->OM */
typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned int module_id;
    unsigned short modem_id;
    unsigned short fault_id; /* 故障场景编号 */
} chr_app_om_req_s;


/* APP-->OM  type=0x14  黑名单配置下发给 OM */
typedef struct {
    unsigned int module_id;
    unsigned short alarm_id;
    unsigned short alarm_type;
} chr_blocklist_info_s;

typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    chr_blocklist_info_s blocklist_map[0];
} chr_app_blocklist_cfg_s;

/* APP-->OM  type=0x15  优先级配置下发给 OM */
typedef struct {
    unsigned int module_id;
    unsigned short alarm_id;   /*  alarm id */
    unsigned short priority;   /*  优先级 */
    unsigned short alarm_type; /*  alarm type */
    unsigned short resv;
} chr_priority_info_s;

typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned char packet_sn; /* sn号，标识为第几包数据， 从0开始，最后一包数据值定义为0xFF */
    unsigned char num;       /* 当前包中AlarmID配置个数 */

    unsigned short resv;     /* 预留 */
    chr_priority_info_s priority_map[0];
} chr_app_priority_cfg_s;

/* APP-->OM  type=0x16  周期配置下发给 OM */
typedef struct {
    unsigned int module_id; /* module id */
    unsigned int count;     /* 周期内1优先级允许上报次数 */
} chr_period_info_s;

typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned char packet_sn;         /* sn号，标识为第几包数据， 从0开始，最后一包数据值定义为0xFF */
    unsigned char num;               /* 当前包中period_info_s配置个数 */
    unsigned char period;            /* 上报周期，以第一包为准，单位小时 */
    unsigned char resv;              /* 预留 */
    chr_period_info_s period_map[0];
} chr_app_period_cfg_s;


/* Result To App type=0x06  OM -> App */
typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned int moduleid;
    unsigned short modemid;
    unsigned short resv;
    unsigned int status; /* result */
} chr_app_result_cnf_s;

/* Result To App type=0x17  OM -> App */
typedef struct {
    chr_alarm_msg_head_s chr_om_header;
    unsigned int status; /* result,app并不解析此状态，只检查type=0x17 */
} chr_app_result_cfg_cnf_s;

#endif
