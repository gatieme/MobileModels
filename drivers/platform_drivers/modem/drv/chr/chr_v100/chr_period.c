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
#include "chr_period.h"

#undef THIS_MODU
#define THIS_MODU mod_chr

chr_period_save_s g_chr_period; // 储存周期的全局变量

// 发送周期配置给C核
int chr_period_send(void)
{
    int ret;
    unsigned int malloc_size;
    chr_period_send_s *period_msg = NULL;

    if (g_chr_period.packet_len == 0) {
        return BSP_OK; // 配置为空，不发送
    }

    // 分配消息内存，选取MSG_DEFAULT意味着只分配除了msg_hd以外的长度。
    malloc_size = sizeof(int) + sizeof(int) + sizeof(int) + g_chr_period.packet_len;
    period_msg = (chr_period_send_s *)mdrv_msg_alloc(DRV_MID_CHR_APSS, malloc_size, MSG_DEFAULT);
    if (period_msg == NULL) {
        chr_print("msg alloc failed");
        return OM_APP_MEM_ALLOC_MSG_ERR;
    }

    // 把分配的消息内存各处填入信息
    MDRV_MSG_HEAD_FILL(period_msg, DRV_MID_CHR_APSS, DRV_MID_CHR_TSP, malloc_size);
    period_msg->msg_name = CHR_PERIOD_CFG_SEND_TO_TSP;
    period_msg->pkt_len = g_chr_period.packet_len;
    period_msg->period = g_chr_period.period;
    ret = memcpy_s(period_msg->period_cfg, period_msg->pkt_len,
                   g_chr_period.chr_period, g_chr_period.packet_len);
    if (ret != EOK) {
        chr_print("msg memcpy failed!\n");
    }

    // 发送，失败了要释放消息内存
    ret = mdrv_msg_send(period_msg, MSG_DEFAULT);
    if (ret != EOK) {
        mdrv_msg_free(DRV_MID_CHR_APSS, period_msg);
        chr_print("period msg send failed!\n");
        return OM_APP_SEND_CCPU_FAIL;
    }
    return BSP_OK;
}

// 检查接收到的这包是不是符合规则的。
int chr_check_period_packet(chr_app_period_cfg_s *chr_period_cfg, unsigned int pkt_len)
{
    if (chr_period_cfg->num != pkt_len / sizeof(chr_period_info_s)) {
        chr_print("input length not match num!\n");  // 检查这一包里包含的alarm_id数量对不对
        return CHR_CHECK_FAIL;
    }
    if ((chr_period_cfg->packet_sn != g_chr_period.packet_sn) &&
        (chr_period_cfg->packet_sn != CHR_PACKET_START) &&
        (chr_period_cfg->packet_sn != CHR_PACKET_END)) { // 例如已经接受了0号，1号，全局变量里的sn累加到2了因为加了两下
        chr_print("SN wrong!\n");                        // 这时，如果下一个包不是2号包、重置包或结束包，就有问题。
        return CHR_CHECK_FAIL;
    }
    if (chr_period_cfg->packet_sn == CHR_PACKET_START) {
        chr_print("SN restart!\n");  // 开始，或者可能重新开始
        return CHR_CHECK_RESTART;
    }
    if (chr_period_cfg->packet_sn == CHR_PACKET_END) {
        chr_print("SN complete!\n");  // 接收完成
        return CHR_CHECK_COMPLETE;
    }
    return CHR_CHECK_CONTINUE; // 不是第二个if里的后两种情况，那就是还正在累加，说明包正接收到中间了，继续接收。
}

// 清除周期配置
void chr_clear_saved_period(void)
{
    int ret;
    ret = memset_s(&g_chr_period, sizeof(g_chr_period), 0, sizeof(g_chr_period));
    if (ret != EOK) {
        chr_print("clear saved period failed!\n");
    }
}

// 接收到周期配置的处理函数
int chr_provide_period_cfg_proc(unsigned char *data, unsigned int msg_len)
{
    int pkt_len;
    int ret;
    int i;
    u32 dst_len;
    char *pos = NULL;

    chr_app_period_cfg_s *chr_period_cfg = (chr_app_period_cfg_s *)data;

    // 这里可以求得cfg包里的period_info_s结构体的map的size。
    // 两个uchar和一个ushort，长度是4，所以减一个sizeof(uint)
    pkt_len = chr_period_cfg->chr_om_header.msg_len - sizeof(unsigned int);
    chr_log_print("msg_len:0x%x,pkt_len:0x%x!\n", msg_len, pkt_len);
    // 包含长度校验，找到当前的包走到哪一步了，方便后续操作。
    ret = chr_check_period_packet(chr_period_cfg, pkt_len);
    if (ret == CHR_CHECK_FAIL) {
        chr_print("param check failed!\n");
        chr_clear_saved_period();
        return OM_APP_PARAM_INAVALID;
    } else if (ret == CHR_CHECK_RESTART) {
        chr_print("period restart!\n");
        chr_clear_saved_period();
    }

    for (i = 0; i < chr_period_cfg->num; i++) {
        chr_log_print("period moduleid:0x%x, count:0x%x!\n", chr_period_cfg->period_map[i].module_id,
                      chr_period_cfg->period_map[i].count);
    }

    if (g_chr_period.packet_len >= sizeof(g_chr_period.chr_period)) {
        chr_print("period array full\n");
        return BSP_ERROR;
    }

    pos = (char *)((uintptr_t)g_chr_period.chr_period + g_chr_period.packet_len);
    dst_len = sizeof(g_chr_period.chr_period) - g_chr_period.packet_len;
    if (memcpy_s(pos, dst_len, chr_period_cfg->period_map, pkt_len) != EOK) {
        chr_print("memcpy failed!\n");
        return BSP_ERROR;
    }
    g_chr_period.packet_sn++;
    g_chr_period.period = chr_period_cfg->period; // 和优先级相比，还要额外存下一个period值
    g_chr_period.packet_len += pkt_len;

    if (ret == CHR_CHECK_COMPLETE) {
        g_chr_period.packet_sn = CHR_PACKET_END;

        ret = chr_period_send();
        if (ret != EOK) {
            chr_print("send period failed with ret 0x%x!\n", ret);
            return ret;
        }
    }
    return BSP_OK;
}
