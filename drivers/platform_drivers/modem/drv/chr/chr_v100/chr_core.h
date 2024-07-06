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

#ifndef __CHR_CORE_H__
#define __CHR_CORE_H__

#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <mdrv_sysboot.h>
#include <bsp_print.h>
#include "chr_app.h"

#define chr_print(fmt, ...) (bsp_err(" <%s> " fmt, __FUNCTION__, ##__VA_ARGS__))
#define chr_log_print(fmt, ...) (bsp_info(" <%s> " fmt, __FUNCTION__, ##__VA_ARGS__))

#define CHR_MDM_RESET_PRIO (49) // 单独复位优先级


#define CHR_BLOCKLIST_CFG_SEND_TO_TSP (0x8001)
#define CHR_PRIORITY_CFG_SEND_TO_TSP  (0x8002)
#define CHR_PERIOD_CFG_SEND_TO_TSP    (0x8003)
#define CHR_REQUEST_SEND_TO_TSP       (0x8004)
#define CHR_REPORT_NEED_NUM_TO_AP     (0x8005)

// 优先级周期多包校验标志
#define CHR_PACKET_START   (0)
#define CHR_PACKET_END     (0x7F)
#define CHR_CHECK_COMPLETE (0)
#define CHR_CHECK_CONTINUE (1)
#define CHR_CHECK_RESTART  (2)
#define CHR_CHECK_FAIL     (3)

#define CHR_MAX_CFG_LEN 1024

// 配置更新到这里边
typedef struct {
    struct semaphore chr_msg_sem;
    struct task_struct *chr_msg_task;
    unsigned int src_mid;
    unsigned int dst_mid;
} chr_msg_core_s;

// 这里是因为pkt传过来，总是一个头，头后边紧跟一个msg_name，这就要求A核和C核收到的数据至少具有这种形式。
typedef struct {
    struct msg_head msg_hd;
    unsigned int msg_name;
} chr_msg_recv_s;

#define CHR_CDEV_SEND_BUFF_LEN      0x10000
typedef struct {
    struct cdev dev;
    u32 devno;
    u8 *send_buffer;
    u32 buf_len;
    u32 wptr;
    u32 rptr;
    wait_queue_head_t wait;
    struct semaphore send_sem;
    struct file_operations fops;
} chr_cdev_ctrl_s;

typedef struct {
    u8 *buffer;
    u32 buff_size;
    u8 *rb_buff;
    u32 rb_size;
} rw_buff_s;

void chr_get_data_buffer(rw_buff_s *rw_buff);
void chr_get_write_buffer(rw_buff_s *rw_buff);
int chr_receive_app_data(unsigned char *data, unsigned int msg_len);
void chr_send_app_data(unsigned char *data, unsigned int msg_len);
int chr_modem_reset(drv_reset_cb_moment_e param, int userdata);
#endif
