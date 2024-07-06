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
#include <securec.h>

#include <mdrv_msg.h>

#include <osl_types.h>
#include <osl_malloc.h>

#include <msg_id.h>

#include "chr_core.h"
#include "chr_app.h"
#include "chr_blocklist.h"

#undef THIS_MODU
#define THIS_MODU mod_chr

chr_blocklist_save_s g_chr_blocklist; // 储存黑名单的全局变量

// 发送黑名单给C核
int chr_blocklist_send(void)
{
    int ret;
    unsigned int malloc_size;
    chr_blocklist_send_s *blocklist_msg = NULL;

    if (g_chr_blocklist.packet_len == 0) {
        return BSP_OK; // 配置为空，不发送
    }

    // 分配消息内存，选取MSG_DEFAULT意味着只分配除了msg_hd以外的长度。
    malloc_size = sizeof(unsigned int) + sizeof(unsigned int) + g_chr_blocklist.packet_len;
    blocklist_msg = (chr_blocklist_send_s *)mdrv_msg_alloc(DRV_MID_CHR_APSS, malloc_size, MSG_DEFAULT);
    if (blocklist_msg == NULL) {
        chr_print("msg alloc failed");
        return OM_APP_MEM_ALLOC_MSG_ERR;
    }

    // 把分配的消息内存各处填入信息
    MDRV_MSG_HEAD_FILL(blocklist_msg, DRV_MID_CHR_APSS, DRV_MID_CHR_TSP, malloc_size);
    blocklist_msg->msg_name = CHR_BLOCKLIST_CFG_SEND_TO_TSP;
    blocklist_msg->pkt_len = g_chr_blocklist.packet_len;
    ret = memcpy_s(blocklist_msg->blocklist_cfg, blocklist_msg->pkt_len,
                   g_chr_blocklist.chr_blocklist, g_chr_blocklist.packet_len);
    if (ret != EOK) {
        chr_print("msg memcpy failed!\n");
    }

    // 发送，失败了要释放消息内存
    ret = mdrv_msg_send(blocklist_msg, MSG_DEFAULT);
    if (ret != EOK) {
        mdrv_msg_free(DRV_MID_CHR_APSS, blocklist_msg);
        chr_print("blocklist msg send failed!\n");
        return OM_APP_SEND_CCPU_FAIL;
    }
    return BSP_OK;
}

// 清除黑名单配置
void chr_clear_saved_blocklist(void)
{
    int ret;
    ret = memset_s(&g_chr_blocklist, sizeof(g_chr_blocklist), 0, sizeof(g_chr_blocklist));
    if (ret != EOK) {
        chr_print("clear saved blocklist failed!\n");
    }
}

// 接收到黑名单配置的处理函数
int chr_provide_blocklist_cfg_proc(unsigned char *data, unsigned int msg_len)
{
    int pkt_len;
    int ret;
    int i;
    chr_app_blocklist_cfg_s *chr_blocklist_cfg = (chr_app_blocklist_cfg_s *)data;

    pkt_len = chr_blocklist_cfg->chr_om_header.msg_len;
    chr_log_print("msg_len:0x%x,pkt_len:0x%x!\n", msg_len, pkt_len);
    if (msg_len != pkt_len + sizeof(chr_alarm_msg_head_s)) {
        chr_print("input length error !\n");
        return OM_APP_MSG_LENGTH_ERR;
    }

    // 检查黑名单 是否有效
    for (i = 0; i < (pkt_len / sizeof(chr_blocklist_info_s)); i++) {
        if (chr_blocklist_cfg->blocklist_map[i].module_id >= OM_ERR_LOG_MOUDLE_ID_BUTT ||
            chr_blocklist_cfg->blocklist_map[i].module_id < OM_ERR_LOG_MOUDLE_ID_GUNAS) {
            chr_print("module id invalid !\n");
            return OM_APP_PARAM_INAVALID;
        }

        chr_log_print("blocklist moduleid:0x%x, alarmid:0x%x, alarmtype:%d\n",
                      chr_blocklist_cfg->blocklist_map[i].module_id,
                      chr_blocklist_cfg->blocklist_map[i].alarm_id,
                      chr_blocklist_cfg->blocklist_map[i].alarm_type);
    }

    if (g_chr_blocklist.packet_len != 0) {
        chr_clear_saved_blocklist(); // 如果旧配置存在，就清除掉，去存新的
    }

    g_chr_blocklist.packet_len = pkt_len;
    ret = memcpy_s(g_chr_blocklist.chr_blocklist, sizeof(g_chr_blocklist.chr_blocklist),
        chr_blocklist_cfg->blocklist_map, pkt_len);
    if (ret != EOK) {
        chr_print("memcpy failed\n");
        return BSP_ERROR;
    }

    ret = chr_blocklist_send();
    if (ret != EOK) {
        chr_print("send blocklist failed with ret 0x%x!\n", ret);
        return ret;
    }
    return BSP_OK;
}
