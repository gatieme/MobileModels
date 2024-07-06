/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2018. All rights reserved.
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

#include <securec.h>
#include <bsp_slice.h>
#include <bsp_nvim.h>
#include "nv_comm.h"
#include "nv_msg.h"
#include "nv_partition.h"

u32 nv_flush_data(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 i;
    u32 ret;
    u32 msg = msg_data->msg;
    UNUSED(sync_flag);

    for (i = 0; i < NV_SECTION_END; i++) {
        if (msg & ((u32)1 << i)) {
            ret = nv_img_single_flush(i);
            if (ret != NV_OK) {
                nv_printf("nv image %d file err\n", i);
                return ret;
            }
        }
    }

    return NV_OK;
}

u32 nv_flush_rwbuf(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 ret;
    u32 buf = msg_data->msg;
    UNUSED(sync_flag);

    ret = nv_img_rwflush(buf);
    if (ret != NV_OK) {
        nv_printf("flush rwbuf err\n");
        return ret;
    }

    return NV_OK;
}

/* need flush image after reload backup */
u32 nv_reload_flush(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 ret;
    UNUSED(msg_data);
    UNUSED(sync_flag);

    ret = nv_img_flush_base();
    if (ret != NV_OK) {
        nv_printf("[reload bak]flush img base err\n");
        return ret;
    }

    nv_printf("reload backup flush image success\n");
    return NV_OK;
}

u32 nv_update_factory(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 ret;
    UNUSED(msg_data);
    UNUSED(sync_flag);

    nv_printf("^INFORBU: factory bakup start!\n");

    ret = nv_fac_flush();
    if (ret) {
        nv_printf("^INFORBU: flush factory nv faild! 0x%x\n", ret);
        return ret;
    }

    ret = nv_bak_flush();
    if (ret) {
        nv_printf("^INFORBU: flush backup nv failed! 0x%x\n", ret);
        return ret;
    }

    nv_printf("^INFORBU: factory bakup end!\n");

    return NV_OK;
}

u32 nv_update_backup(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 ret;
    UNUSED(msg_data);
    UNUSED(sync_flag);

    nv_printf("^NVBACKUP: bakup start!\n");
    ret = nv_img_flush_base();
    if (ret) {
        nv_printf("^NVBACKUP: flush image nv failed! ret :0x%x\n", ret);
        return ret;
    }

    ret = nv_bak_flush();
    if (ret) {
        nv_printf("^NVBACKUP: flush backup nv failed! 0x%x\n", ret);
        return ret;
    }

    nv_printf("^NVBACKUP: bakup end!\n");
    return NV_OK;
}

u32 nv_update_backup_bk(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    UNUSED(msg_data);
    UNUSED(sync_flag);
    nv_printf("^NVBACKUP_BK: bakup start!\n");
    return NV_OK;
}


u32 nv_factory_reset(struct nv_msg_data *msg_data, u32 *sync_flag)
{
    u32 ret;
    UNUSED(msg_data);
    UNUSED(sync_flag);

    nv_printf("nv factory reset start\n");
    ret = nv_bak_flush();
    if (ret) {
        nv_printf("nv factory reset flush backup failed, ret:0x%x\n", ret);
        return ret;
    }

    ret = nv_set_upgrade_flag();
    if (ret) {
        nv_printf("nv factory reset set upgrade flag failed, ret:0x%x\n", ret);
        return ret;
    }
    ret = nv_set_ftyrst_flag();
    if (ret) {
        nv_printf("nv factory reset set ftyrst flag failed, ret:0x%x\n", ret);
        return ret;
    }

    nv_printf("nv factory reset end\n");

    return NV_OK;
}
