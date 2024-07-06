/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
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

#ifndef BSP_HMI_H
#define BSP_HMI_H

#include <linux/netdevice.h>
#include <linux/module.h>
#include <net/genetlink.h>
#include <osl_types.h>
#include <osl_sem.h>

#define HMI_GENL_HDR_LEN (NLMSG_HDRLEN + GENL_HDRLEN)

typedef enum {
    GENL_CMD_UNSPEC,
    GENL_CMD_CHR_RCV_MSG,
    GENL_CMD_BUTT,
} hmi_genl_cmd_e;

typedef enum {
    GENL_CHAN_CHR,
    GENL_CHAN_BUTT,
} hmi_genl_chan_e;

typedef struct {
    struct net *net;
    u32 port_id;
    osl_sem_id chan_sem;
} genl_chan_ctrl_s;

typedef struct {
    struct genl_family family;
    genl_chan_ctrl_s chan_ctrl_info[GENL_CHAN_BUTT];
} hmi_genl_ctrl_s;

typedef int (*hmi_genl_doit_handler)(struct sk_buff *skb, struct genl_info *info);

void bsp_hmi_genl_set_port_info(hmi_genl_chan_e chan_id, struct genl_info *info);
int bsp_hmi_genl_rcv_para_check(struct sk_buff *skb, struct genl_info *info);
int bsp_hmi_genl_send_data(hmi_genl_chan_e chan_id, u8 *buf, u32 len);
int bsp_hmi_genl_chan_register(hmi_genl_chan_e chan_id, hmi_genl_cmd_e cmd, hmi_genl_doit_handler doit_handler);

#endif
