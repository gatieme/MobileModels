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
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <net/genetlink.h>
#include <securec.h>
#include <mdrv_sysboot.h>
#include <mdrv_msg.h>
#include <mdrv_timer.h>
#include <osl_types.h>
#include <osl_malloc.h>
#include <msg_id.h>
#include "chr_app.h"
#include "chr_core.h"
#include "chr_blocklist.h"
#include "chr_priority.h"
#include "chr_period.h"
#include "chr_report.h"

#undef THIS_MODU
#define THIS_MODU mod_chr

chr_msg_core_s g_chr_msg_ctrl; // 储存msg相关配置的全局变量
u32 g_chr_init_state;

int chr_cdev_open(struct inode *inode, struct file *file);
u32 chr_cdev_poll(struct file *fp, struct poll_table_struct *wait);
ssize_t chr_cdev_read(struct file *file, char __user *buf, size_t count, loff_t *ppos);
ssize_t chr_cdev_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos);

chr_cdev_ctrl_s g_chr_cdev_ctrl = {
    .fops = {
        .open   = chr_cdev_open,
        .write  = chr_cdev_write,
        .read   = chr_cdev_read,
        .poll   = chr_cdev_poll,
    },
};

int chr_cdev_open(struct inode *inode, struct file *file)
{
    if (g_chr_init_state != 1) {
        return -1;
    }

    return 0;
}

u32 chr_cdev_poll(struct file *fp, struct poll_table_struct *wait)
{
    poll_wait(fp, &g_chr_cdev_ctrl.wait, wait);

    if (g_chr_cdev_ctrl.wptr != g_chr_cdev_ctrl.rptr) {
        return POLLIN | POLLRDNORM;
    }

    return 0;
}

void chr_read_done(chr_cdev_ctrl_s *cdev_ctrl, u32 read_size)
{
    cdev_ctrl->rptr += read_size;
    if (cdev_ctrl->rptr > (cdev_ctrl->buf_len - 1)) {
        cdev_ctrl->rptr -= cdev_ctrl->buf_len;
    }
}

ssize_t chr_cdev_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    s32 ret;
    rw_buff_s rw_buff;

    if (wait_event_interruptible(g_chr_cdev_ctrl.wait, (g_chr_cdev_ctrl.wptr != g_chr_cdev_ctrl.rptr))) {
        return -ERESTARTSYS;
    }

    down(&g_chr_cdev_ctrl.send_sem);

    chr_get_data_buffer(&rw_buff);
    if (count <= rw_buff.buff_size) {
        ret = copy_to_user(buf, rw_buff.buffer, count);
        if (ret) {
            up(&g_chr_cdev_ctrl.send_sem);
            return -1;
        }
        chr_read_done(&g_chr_cdev_ctrl, count);
    } else {
        ret = copy_to_user(buf, rw_buff.buffer, rw_buff.buff_size);
        if (ret) {
            up(&g_chr_cdev_ctrl.send_sem);
            return -2;
        }
        chr_read_done(&g_chr_cdev_ctrl, rw_buff.buff_size);
        if (rw_buff.rb_size != 0) {
            if ((count - rw_buff.buff_size) > rw_buff.rb_size) {
                ret = copy_to_user(buf + rw_buff.buff_size, rw_buff.rb_buff, rw_buff.rb_size);
                if (ret) {
                    up(&g_chr_cdev_ctrl.send_sem);
                    return -3;
                }
                count = rw_buff.buff_size + rw_buff.rb_size;
            } else {
                ret = copy_to_user(buf + rw_buff.buff_size, rw_buff.rb_buff, count - rw_buff.buff_size);
                if (ret) {
                    up(&g_chr_cdev_ctrl.send_sem);
                    return -4;
                }
            }
            chr_read_done(&g_chr_cdev_ctrl, count - rw_buff.buff_size);
        }
    }

    up(&g_chr_cdev_ctrl.send_sem);
    chr_print("read data from kernel ok, count=0x%x\n", (u32)count);
    return (ssize_t)count;
}

ssize_t chr_cdev_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    u8 *data = NULL;
    s32 ret;

    if (count > CHR_MAX_CFG_LEN) {
        return -1;
    }

    data = kmalloc(count, GFP_KERNEL);
    if (data == NULL) {
        chr_print("malloc data buffer fail, count=0x%x\n", (u32)count);
        return -1;
    }

    ret = copy_from_user(data, buf, count);
    if (ret) {
        chr_print("copy_from_user fail, count=0x%x\n", (u32)count);
        osl_free(data);
        return -1;
    }

    ret = chr_receive_app_data(data, count);
    if (ret) {
        chr_print("chr receive data fail\n");
        osl_free(data);
        return 0;
    }

    chr_print("write data to kernel ok, count=0x%x\n", (u32)count);
    osl_free(data);
    return count;
}

void chr_get_data_buffer(rw_buff_s *rw_buff)
{
    u8 *buffer_start = g_chr_cdev_ctrl.send_buffer;
    u32 write_ptr  = g_chr_cdev_ctrl.wptr;
    u32 read_ptr = g_chr_cdev_ctrl.rptr;
    u8 *buffer_end = buffer_start + g_chr_cdev_ctrl.buf_len - 1;

    if (read_ptr <= write_ptr) {
        rw_buff->buffer = (char *)(uintptr_t)(buffer_start + read_ptr);
        rw_buff->buff_size = write_ptr - read_ptr;
        rw_buff->rb_buff = NULL;
        rw_buff->rb_size = 0;
    } else {
        rw_buff->buffer = (char *)(uintptr_t)(buffer_start + read_ptr);
        rw_buff->buff_size = (u32)(buffer_end - (buffer_start + read_ptr) + 1);
        rw_buff->rb_buff = buffer_start;
        rw_buff->rb_size = write_ptr;
    }
}

void chr_get_write_buffer(rw_buff_s *rw_buff)
{
    u8 *buffer_start = g_chr_cdev_ctrl.send_buffer;
    u32 write_ptr  = g_chr_cdev_ctrl.wptr;
    u32 read_ptr = g_chr_cdev_ctrl.rptr;
    u8 *buffer_end = buffer_start + g_chr_cdev_ctrl.buf_len - 1;

    if (write_ptr < read_ptr) {
        rw_buff->buffer = (u8 *)(uintptr_t)(buffer_start + write_ptr);
        rw_buff->buff_size = read_ptr - write_ptr - 1;
        rw_buff->rb_buff = NULL;
        rw_buff->rb_size = 0;
    } else {
        rw_buff->buffer = (u8 *)(uintptr_t)(buffer_start + write_ptr);
        rw_buff->buff_size = (u32)(buffer_end - (buffer_start + write_ptr) + 1);
        rw_buff->rb_buff = buffer_start;
        rw_buff->rb_size = read_ptr;
    }

    return;
}


int chr_receive_app_data(unsigned char *data, unsigned int msg_len)
{
    chr_alarm_msg_head_s *alarm_msg_head = NULL;

    down(&g_chr_msg_ctrl.chr_msg_sem);

    if (data == NULL) {
        chr_print("data is null\n");
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return BSP_ERROR;
    }
    if (msg_len < sizeof(chr_alarm_msg_head_s) || msg_len > CHR_MAX_CFG_LEN) {
        chr_print("len wrong, len= %d.\n", msg_len);
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return BSP_ERROR;
    }

    alarm_msg_head = (chr_alarm_msg_head_s *)data; // 只解析头部

    if (msg_len != alarm_msg_head->msg_len + sizeof(chr_alarm_msg_head_s)) {
        chr_print("len not match, len= %d.\n", msg_len);
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return BSP_ERROR;
    }

    chr_log_print("recv.type:0x%x,msgLen:0x%x,totallen:0x%x!\n",
                  alarm_msg_head->msg_type, alarm_msg_head->msg_len, msg_len);

    if (alarm_msg_head->msg_type == OM_ERR_LOG_MSG_SET_ERR_REPORT) {
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return chr_request_chr_proc(data, msg_len);
    } else if (alarm_msg_head->msg_type == OM_ERR_LOG_MSG_BLOCKLIST_CFG) {
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return chr_provide_blocklist_cfg_proc(data, msg_len);
    } else if (alarm_msg_head->msg_type == OM_ERR_LOG_MSG_PRIORITY_CFG) {
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return chr_provide_priority_cfg_proc(data, msg_len);
    } else if (alarm_msg_head->msg_type == OM_ERR_LOG_MSG_PERIOD_CFG) {
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return chr_provide_period_cfg_proc(data, msg_len);
    } else {
        chr_print("wrong msg type\n");
        up(&g_chr_msg_ctrl.chr_msg_sem);
        return BSP_ERROR;
    }
    up(&g_chr_msg_ctrl.chr_msg_sem);
    return BSP_OK;
}

void chr_send_app_data(unsigned char *data, unsigned int msg_len)
{
    rw_buff_s rw_buff;

    down(&g_chr_cdev_ctrl.send_sem);

    chr_get_write_buffer(&rw_buff);

    if (msg_len > rw_buff.buff_size + rw_buff.rb_size) {
        chr_print("buffer busy, msg_len=0x%x, idle_size=0x%x\n", msg_len, rw_buff.buff_size + rw_buff.rb_size);
        up(&g_chr_cdev_ctrl.send_sem);
        return;
    }

    if (msg_len <= rw_buff.buff_size) {
        (void)memcpy_s(rw_buff.buffer, rw_buff.buff_size, data, msg_len);
    } else {
        (void)memcpy_s(rw_buff.buffer, rw_buff.buff_size, data, rw_buff.buff_size);
        (void)memcpy_s(rw_buff.rb_buff, rw_buff.buff_size, data + rw_buff.buff_size, msg_len - rw_buff.buff_size);
    }

    g_chr_cdev_ctrl.wptr = (g_chr_cdev_ctrl.wptr + msg_len) % g_chr_cdev_ctrl.buf_len;

    up(&g_chr_cdev_ctrl.send_sem);

    wake_up_interruptible(&g_chr_cdev_ctrl.wait);
    bsp_info("send data to app ok, msg_len=0x%x\n", msg_len);
    return;
}

// 接收到的消息的处理函数
int chr_msg_thread(void *arg)
{
    int ret;
    void *msg = NULL;
    unsigned int chr_msg_len;
    chr_msg_core_s *info = arg;
    chr_msg_recv_s *chr_msg = NULL;
    chr_print("chr msg thread running!\n");
    while (1) {
        ret = mdrv_msg_recv(0, &msg, MDRV_MSG_WAIT_FOREVER);
        if (ret != EOK) {
            chr_print("mdrv chr msg recv failed!\n");
            continue;
        }
        chr_msg_len = MDRV_MSG_HEAD_GET_LEN(msg);
        chr_msg = (chr_msg_recv_s *)msg;

        if (chr_msg->msg_name == CHR_REPORT_NEED_NUM_TO_AP) {
            chr_report_need_num_proc(msg);
        } else {
            chr_tsp_msg_proc(msg);
        }

        if (msg != NULL) {
            mdrv_msg_free(info->src_mid, msg);
            msg = NULL;
        }
    }
    return 0;
}


// A核消息初始化
int chr_msg_init(void)
{
    int ret;
    struct task_struct *atask = NULL;

    g_chr_msg_ctrl.src_mid = DRV_MID_CHR_APSS;
    g_chr_msg_ctrl.dst_mid = DRV_MID_CHR_TSP;
    sema_init(&(g_chr_msg_ctrl.chr_msg_sem), 1);

    // 创建消息进程，第一个参数是函数，把第二个参数当它的参数。第三个参数为任务名。
    atask = kthread_create(chr_msg_thread, (void *)(&g_chr_msg_ctrl), "chr_msg_thread");
    if (IS_ERR(atask)) {
        chr_print("fail to create kthread!\n");
        return BSP_ERROR;
    }

    // 创建队列
    ret = mdrv_msg_qcreate(atask->pid, 1);
    if (ret != EOK) {
        chr_print("fail to create queue!\n");
        return BSP_ERROR;
    }

    g_chr_msg_ctrl.chr_msg_task = atask; // 全局变量存下struct_task

    // 先注册，再运行，第三个参数qid，队列的id，从0开始。
    mdrv_msg_register_mid(atask->pid, g_chr_msg_ctrl.src_mid, 0);
    // 唤醒进程。
    wake_up_process(atask);
    return BSP_OK;
}

// modem单独复位的话，就要把配置重新发送一次
int chr_modem_reset(drv_reset_cb_moment_e param, int userdata)
{
    if (param == MDRV_RESET_CB_AFTER) {
        chr_print("modem reset after!\n");
        (void)chr_blocklist_send();
        (void)chr_priority_send();
        (void)chr_period_send();
    }
    return BSP_OK;
}

int chr_cdev_init(void)
{
    s32 ret;
    dev_t dev = 0;
    struct class *chr_class = NULL;

    ret = alloc_chrdev_region(&dev, 0, 1, "appvcomERRLOG");
    if (ret) {
        chr_print("chr alloc chrdev region fail, ret=0x%x\n", ret);
        return ret;
    }

    g_chr_cdev_ctrl.devno = MKDEV(MAJOR(dev), 53);

    cdev_init(&g_chr_cdev_ctrl.dev, &g_chr_cdev_ctrl.fops);
    ret = cdev_add(&g_chr_cdev_ctrl.dev, g_chr_cdev_ctrl.devno, 1);
    if (ret) {
        chr_print("chr cdev add fail, ret=0x%x, chr_id=0x%x\n", ret, g_chr_cdev_ctrl.devno);
        return ret;
    }

    chr_class = class_create(THIS_MODULE, "chr_cdev_class");
    if (IS_ERR(chr_class)) {
        chr_print("class create fail\n");
        return BSP_ERROR;
    }

    device_create(chr_class, NULL, g_chr_cdev_ctrl.devno, NULL, "appvcomERRLOG");

    g_chr_cdev_ctrl.send_buffer = kmalloc(CHR_CDEV_SEND_BUFF_LEN, GFP_KERNEL);
    if (g_chr_cdev_ctrl.send_buffer == NULL) {
        chr_print("malloc send_buffer fail\n");
        return BSP_ERROR;
    }
    g_chr_cdev_ctrl.buf_len = CHR_CDEV_SEND_BUFF_LEN;

    init_waitqueue_head(&g_chr_cdev_ctrl.wait);

    sema_init(&g_chr_cdev_ctrl.send_sem, 1);

    return BSP_OK;
}

int chr_init(void)
{
    int ret;
    char *reset_name = "CHR_FS"; // C核单独复位的名字

    ret = chr_msg_init();
    if (ret != EOK) {
        chr_print("chr msg init failed.\n");
        return BSP_ERROR;
    }

    ret = mdrv_sysboot_register_reset_notify(reset_name, (pdrv_reset_cbfun)chr_modem_reset, 0, CHR_MDM_RESET_PRIO);
    if (ret != EOK) {
        chr_print("chr register modem reset failed.\n");
        return BSP_ERROR;
    }

    ret = chr_cdev_init();
    if (ret) {
        return BSP_ERROR;
    }

    g_chr_init_state = 1;

    chr_print("chr init ok!\n");
    return BSP_OK;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(chr_init);
#endif

EXPORT_SYMBOL(chr_modem_reset);
EXPORT_SYMBOL(chr_receive_app_data);

int bsp_chr_genl_rcv_handler(struct sk_buff *skb, struct genl_info *info)
{
    return 0;
}


