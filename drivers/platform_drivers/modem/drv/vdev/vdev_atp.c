/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
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
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS"
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

#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <securec.h>
#include <bsp_print.h>
#include "vdev.h"

#define THIS_MODU mod_vcom

struct vcom_cdev g_atp;

#define ATP_DEV_T   100   /* ATP dev_t */

static const char *g_at_ret = "OK\n";
#define AT_RET_LEN 4

enum at_set_id {
    ATP_SET_FUNC_ID0 = 0,
    ATP_SET_FUNC_ID1 = 1,
    ATP_SET_FUNC_BOT,
};

struct at_func_set {
    unsigned int id;
    int (*func)(unsigned char *data, unsigned int size);
};

static int at_func0(unsigned char *data, unsigned int size);
static int at_func1(unsigned char *data, unsigned int size);

struct at_func_set g_at_func_map[] = {
    {ATP_SET_FUNC_ID0, at_func0},
    {ATP_SET_FUNC_ID1, at_func1},
};

static int at_func0(unsigned char *data, unsigned int size)
{
    bsp_err("at_func0\n");
    bsp_err("%s\n", data);
    return 0;
}

static int at_func1(unsigned char *data, unsigned int size)
{
    bsp_err("at_func1\n");
    return memcpy_s(data, size, g_at_ret, AT_RET_LEN);
}

struct at_func_set *at_search_func(unsigned int id)
{
    unsigned int i;
    for (i = 0; i < sizeof(g_at_func_map) / sizeof(g_at_func_map[0]); i++) {
        if (g_at_func_map[i].id == id) {
            return &g_at_func_map[i];
        }
    }
    return NULL;
}

int atp_exe_cmd(struct at_func_set *func_set, unsigned int cmd, struct at_exec_msg *msg)
{
    char *buf = NULL;
    int ret;

    buf = kmalloc(msg->len, GFP_KERNEL);
    if (buf == NULL) {
        return -1;
    }

    ret = copy_from_user(buf, msg->data, msg->len);
    if (ret) {
        kfree(buf);
        return ret;
    }

    bsp_err("cmd = %d\n", cmd);

    mutex_lock(&g_atp.write_lock);
    switch (cmd) {
        case ATP_CMD_SET:
            ret = func_set->func(buf, msg->len);
            break;
        case ATP_CMD_GET:
            bsp_err("copy from user: %s\n", buf);
            ret = func_set->func(buf, msg->len);
            if (ret == 0) {
                ret = copy_to_user(msg->data, buf, msg->len);
                bsp_err("copy to user: %s\n", buf);
            }
            break;
        default:
            ret = -EIO;
            VCOM_PRINT_ERROR("Ioctl command ERROR.\n");
            break;
    }
    mutex_unlock(&g_atp.write_lock);

    kfree(buf);
    return ret;
}

static long atp_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
    int ret;
    struct at_exec_msg msg;
    struct at_func_set *func_set = NULL;

    if (data == (unsigned long)NULL) {
        VCOM_PRINT_ERROR("data is NULL.\n");
        return -EIO;
    }

    ret = copy_from_user(&msg, (void *)(uintptr_t)data, sizeof(struct at_exec_msg));
    if (ret) {
        VCOM_PRINT_ERROR("copy_from_user failed\n");
    }

    if (msg.id >= ATP_SET_FUNC_BOT || msg.data == NULL) {
        bsp_err("unsupport exec msg id:%u\n", msg.id);
        return -1;
    }

    if (msg.len > VCOM_MAX_DATA_SIZE) {
        VCOM_PRINT_ERROR("exec msg is too large: %#x\n", msg.len);
        return -1;
    }

    func_set = at_search_func(msg.id);
    if (func_set == NULL || func_set->func == NULL) {
        VCOM_PRINT_ERROR("exec msg data null\n");
        return -1;
    }

    return atp_exe_cmd(func_set, cmd, &msg);
}

struct file_operations g_atp_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = atp_ioctl,
};


int vcom_at_exec_init(struct vcom_hd *hd)
{
    unsigned int id = ATP_DEV_T;
    struct vcom_cdev* dev = &g_atp;

    mutex_init(&dev->write_lock);
    init_waitqueue_head(&dev->wait);
    cdev_init(&dev->cdev, &g_atp_fops);

    dev->dev = vcom_create_dev(&dev->cdev, hd->name, id, hd);
    if (IS_ERR(dev->dev)) {
        VCOM_PRINT_ERROR("device create err\n");
        return -1;
    }
    return 0;
}


