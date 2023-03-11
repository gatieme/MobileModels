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
#include <linux/delay.h>
#include <linux/version.h>
#if defined(CONFIG_HISI_RPROC)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <linux/platform_drivers/hisi_rproc.h>
#else
#include <linux/hisi/hisi_rproc.h>
#endif
#endif
#include <mdrv_ipc_enum.h>
#include <bsp_ipc.h>
#include <mntn_interface.h>
#include <drv_comm.h>
#include <bsp_slice.h>
#include <bsp_fiq.h>
#include <bsp_reset.h>
#include <bsp_dump.h>
#include "dump_config.h"
#include "dump_exc_handle.h"
#include "dump_area.h"
#include "dump_m3_agent.h"

#undef THIS_MODU
#define THIS_MODU mod_dump

struct dump_lpm3_agent_ctrl_info_s g_mdm_lpm3_ctrl;

void dump_mdm_lpm3_field_show(void)
{
    if (!g_mdm_lpm3_ctrl.virt_area_addr) {
        dump_error("virt_addr is null!\n");
        return;
    }
    dump_error("virt_addr=%pk,phy_addr=%pk\n", g_mdm_lpm3_ctrl.virt_area_addr, g_mdm_lpm3_ctrl.phy_area_addr);
    dump_error("length=%d,is_lpm3exc=%d,init_flag=%d!\n", g_mdm_lpm3_ctrl.length, g_mdm_lpm3_ctrl.is_lpm3exc,
               g_mdm_lpm3_ctrl.ulInitstate);
    dump_error("magic_num=0x%x,area_name=%s,field_num=%d\n", g_mdm_lpm3_ctrl.virt_area_addr->area_head.magic_num,
               g_mdm_lpm3_ctrl.virt_area_addr->area_head.name, g_mdm_lpm3_ctrl.virt_area_addr->area_head.field_num);
    dump_error("done_flag=%d\n", g_mdm_lpm3_ctrl.virt_area_addr->area_head.share_info.done_flag);
}

void dump_mdm_lpm3_int_handle(u32 param)
{
    dump_base_info_s *base_ctrl = NULL;
    dump_exception_info_s exception_info_s = {0};
    g_mdm_lpm3_ctrl.is_lpm3exc = true;

    dump_error("modem lpmcu exc int handler enter!slice=0x%x\n", bsp_get_slice_value());

    base_ctrl = (dump_base_info_s *)bsp_dump_get_field_addr(DUMP_MDM_M3_BASE_INFO);
    if (base_ctrl == NULL) {
        dump_error("base ctrl is null!\n");
        return;
    }

    // 没有填desc和task name
    dump_fill_excption_info(&exception_info_s, base_ctrl->mod_id, base_ctrl->arg1, base_ctrl->arg2, NULL, 0,
                            DUMP_CPU_MDMM3, DUMP_REASON_NORMAL, NULL, base_ctrl->reboot_context, base_ctrl->reboot_task,
                            base_ctrl->reboot_int, NULL);
    dump_register_exception(&exception_info_s);

    dump_error("dump_mdm_lpm3_int_handle end!\n");
}

#define IPC_MSG_TX_LEN 4
#define IPC_MSG_RX_LEN 2
#define IPC_MSG_TX_DATA0 ((0 << 24) | (9 << 16) | (4 << 8))
s32 dump_send_msg_to_mcore(void)
{
    s32 ret;
    rproc_msg_t tx_buffer[IPC_MSG_TX_LEN] = { IPC_MSG_TX_DATA0, DUMP_IPMSG_MAGIC_NUMBER,
                                              MNTN_AREA_LPM3_ADDR, MNTN_AREA_LPM3_SIZE };
    rproc_msg_t ack_buffer[IPC_MSG_RX_LEN] = {0};

    dump_debug("tx_buffer1,2,3=0x%x,0x%x,0x%x!\n", tx_buffer[1], tx_buffer[2], tx_buffer[3]);
#if defined(CONFIG_HISI_RPROC)
    /* 14代表同步，13代表异步 */
    ret = RPROC_SYNC_SEND(HISI_RPROC_LPM3_MBX14, tx_buffer, sizeof(tx_buffer) / sizeof(rproc_msg_t), ack_buffer,
                          sizeof(ack_buffer) / sizeof(rproc_msg_t));
#else
    dump_error("hisi_proc close!\n");
#endif
    return ret;
}

s32 dump_match_mdm_lpm3_rdr_id(dump_exception_info_s *dump_exception_info)
{
    return RDR_MODEM_LPM3_MOD_ID;
}

s32 dump_get_mdm_lpm3_save_done(void)
{
    s32 flag = 0;
    struct dump_area_s *dump_area_info = g_mdm_lpm3_ctrl.virt_area_addr;

    if (dump_area_info) {
        flag = readl(&dump_area_info->area_head.share_info.done_flag);
    }
    /*lint -e650 -esym(650,*)*/
    if (flag == DUMP_SAVE_SUCCESS) {
        return BSP_OK;
    }

    /*lint -e650 +esym(650,*)*/
    return BSP_ERROR;
}

s32 dump_wait_mdm_lpm3_done(bool block)
{
    u32 time_start;

    time_start = bsp_get_elapse_ms();

    do {
        if (BSP_OK == dump_get_mdm_lpm3_save_done()) {
            dump_error("mdmlpm3 save done\n");
            return BSP_OK;
        }

        if (bsp_get_elapse_ms() - time_start >= DUMP_M3_TIMEOUT_MS) {
            dump_error("dump wait mdmlpm3 done time out\n");
            return BSP_ERROR;
        }

        if (block) {
            msleep(DUMP_SLEEP_5MS_NUM);
        }
    } while (1);
    return BSP_ERROR;
}

void dump_notify_mdm_lpm3(u32 mod_id)
{
    s32 ret;

    if (g_mdm_lpm3_ctrl.is_lpm3exc) {
        return;
    }

    ret = bsp_ipc_int_send(IPC_CORE_MCORE, IPC_MCU_INT_SRC_DUMP);
    if (ret != BSP_OK) {
        dump_error("notify modem lpm3 fail,please let ipc check!\n");
        return;
    }

    dump_error("notify modem lpm3 success\n");
}

s32 dump_mdm_lpm3_callback(u32 modid, u32 etype, u64 coreid, char *logpath, pfn_cb_dump_done fndone)
{
    dump_error("enter mdm lpm3 dump callback, mod id:0x%x\n", modid);

    dump_notify_mdm_lpm3(modid);

    dump_error("mdm_lpm3_callback finish!\n");
    return BSP_OK;
}

s32 dump_field_head_init(void)
{
    u32 ret;
    struct dump_area_mntn_addr_info_s area_info = {
        NULL,
    };

    ret = bsp_dump_get_area_info(DUMP_AREA_LPM3, &area_info);
    if (ret) {
        dump_error("fail to find lpm3 area head\n");
        return BSP_ERROR;
    }

    g_mdm_lpm3_ctrl.phy_area_addr = area_info.paddr;
    g_mdm_lpm3_ctrl.virt_area_addr = area_info.vaddr;
    g_mdm_lpm3_ctrl.length = area_info.len;
    if (!g_mdm_lpm3_ctrl.virt_area_addr) {
        dump_error("mdm lpm3 area info is wrong!\n");
        return BSP_ERROR;
    }
    if (EOK != memset_s(g_mdm_lpm3_ctrl.virt_area_addr, g_mdm_lpm3_ctrl.length, 0, g_mdm_lpm3_ctrl.length)) {
        dump_error("memset lpm3 area fail!\n");
    }

    g_mdm_lpm3_ctrl.virt_area_addr->area_head.magic_num = DUMP_AREA_MAGICNUM;

    if (EOK != memcpy_s(g_mdm_lpm3_ctrl.virt_area_addr->area_head.name,
                        sizeof(g_mdm_lpm3_ctrl.virt_area_addr->area_head.name), "MDMM3", strlen("MDMM3"))) {
        dump_error("memset lpm3 area fail!\n");
    }

    g_mdm_lpm3_ctrl.virt_area_addr->area_head.field_num = 0;

    return BSP_OK;
}

int dump_lpm3_modem_reset_cb(drv_reset_cb_moment_e param, int user_data)
{
    switch (param) {
        case MDRV_RESET_CB_BEFORE:
            g_mdm_lpm3_ctrl.is_lpm3exc = false;
            break;
        default:
            break;
    }

    return BSP_OK;
}

s32 dump_lpm3_agent_init(void)
{
    s32 ret;

    ret = bsp_ipc_int_connect(IPC_ACPU_INT_MCU_SRC_DUMP, (voidfuncptr)dump_mdm_lpm3_int_handle, 0);
    if (ret) {
        dump_error("ipc_int_connect fail!lpm3_agent fail!\n");
        return BSP_OK;
    }
    ret = bsp_ipc_int_enable(IPC_ACPU_INT_MCU_SRC_DUMP);
    if (ret) {
        dump_error("ipc_int_enable fail!lpm3_agent fail!\n");
        return BSP_OK;
    }
    ret = dump_field_head_init();
    if (ret) {
        dump_error("field head init fail!lpm3_agent fail!\n");
        return BSP_OK;
    }
    /* lpm3 agent 初始化完成之后向M3发送地址信息 */
    ret = dump_send_msg_to_mcore();
    if (ret) {
        dump_error("ipc_msg_send fail ret=%d!lpm3_agent fail!\n", ret);
        return BSP_OK;
    }
    /* 注册单独复位回调，复位之前清掉复位异常标志 */
    ret = (u32)bsp_reset_cb_func_register("dump_lpm3", dump_lpm3_modem_reset_cb, 0, DRV_RESET_CB_PIOR_DUMPLPM3);
    if (ret) {
        dump_error("register reset cb fail, ret:0x%x\n", ret);
    }
    g_mdm_lpm3_ctrl.is_lpm3exc = false;
    g_mdm_lpm3_ctrl.ulInitstate = true;
    dump_error("[init]ok\n");

    return BSP_OK;
}
