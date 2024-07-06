/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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

#include "pfa.h"
#include "pfa_dbg.h"
#include "pfa_desc.h"
#include "pfa_tft_reg.h"
#include "pfa_hal_reg.h"
#include "pfa_tft.h"


struct pfa_om_reg_set g_pfa_om_reg[PFA_REG_DUMP_GROUP_NUM] = {
    {
        .start = 0,
        .end = 0x34
    },
    {
        .start = 0x40,
        .end = 0xBC
    },
    {
        .start = 0x100,
        .end = 0x114
    },
    {
        .start = 0x200,
        .end = 0x37C
    },
    {
        .start = 0x500,
        .end = 0x5C0
    },
    {
        .start = 0x600,
        .end = 0x620
    },
    {
        .start = 0x700,
        .end = 0x7A8
    },
    {
        .start = 0x2800,
        .end = 0x2C0C
    },
    {
        .start = 0x3000,
        .end = 0x307c
    },
};

unsigned int g_pfa_reset_bak_reg[PFA_RESET_BAK_REG_NUM][PFA_STASH_REG_BUTTON] = {
    { PFA_PFA_TFT_BD_RD_IP_HEAD, 0 },
    { PFA_PFA_TFT_RDQ_WPTR_UPDATE_ADDR_L, 0 },
    { PFA_PFA_TFT_RDQ_WPTR_UPDATE_ADDR_H, 0 },
    { PFA_TFT_PFA_BDQ_RPTR_UPDATE_ADDR_L, 0 },
    { PFA_TFT_PFA_BDQ_RPTR_UPDATE_ADDR_H, 0 },
    { PFA_HASH_CACHE_EN, 0 },
    { PFA_ADQ_THRESHOLD, 0 },
    { PFA_ADQ0_LEN, 0 },
    { PFA_ADQ1_LEN, 0 },
};

void config_tft_bd_rd_ip_head(struct pfa *pfa)
{
    if (pfa->pfa_tftport.extend_desc) {
        pfa_writel(pfa->regs, PFA_PFA_TFT_BD_RD_IP_HEAD, 0);
    } else {
        pfa_writel(pfa->regs, PFA_PFA_TFT_BD_RD_IP_HEAD, 1);
    }
}

void tft_config_rd_ip_head(unsigned int ext_desc_en)
{
    unsigned int reg;

    if (ext_desc_en) {
        UPDATE2(reg, PFA_TFT_CTRL, dl_rdq_with_head, 1, ul_bdq_with_head, 1);
    } else {
        UPDATE2(reg, PFA_TFT_CTRL, dl_rdq_with_head, 0, ul_bdq_with_head, 0);
    }
}

void config_tft_bd_rd_ptr_update(struct pfa *pfa, struct iport_pfa_tft_addr *pfa_tft_reg)
{
    pfa_writel(pfa->regs, PFA_PFA_TFT_RDQ_WPTR_UPDATE_ADDR_L, lower_32_bits(pfa_tft_reg->ulrd_wptr_addr));
    pfa_writel(pfa->regs, PFA_PFA_TFT_RDQ_WPTR_UPDATE_ADDR_H, upper_32_bits(pfa_tft_reg->ulrd_wptr_addr));

    pfa->pfa_tftport.pfa_tft_rd_rptr_addr = (void *)(uintptr_t)(pfa_tft_reg->dltd_rptr_phy_addr);
    pfa_writel(pfa->regs, PFA_TFT_PFA_BDQ_RPTR_UPDATE_ADDR_L, (unsigned int)(uintptr_t)pfa->pfa_tftport.pfa_tft_rd_rptr_addr);
}

void queue_portx_save(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs)
{
    queue_regs->pfa_portx_udp_lmtnum[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_UDP_LMTNUM(portno));
    queue_regs->pfa_portx_lmtbyte[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_LMTBYTE(portno));
    queue_regs->pfa_portx_property[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_PROPERTY(portno));
    queue_regs->pfa_portx_mac_addr_l[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_L(portno));
    queue_regs->pfa_protx_mac_addr_h[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_H(portno));
    queue_regs->pfa_portx_ipv6_addr_1s[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_1ST(portno));
    queue_regs->pfa_portx_ipv6_addr_2n[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_2ND(portno));
    queue_regs->pfa_portx_ipv6_addr_3t[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_3TH(portno));
    queue_regs->pfa_portx_ipv6_addr_4t[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_4TH(portno));
    queue_regs->pfa_portx_ipv6_mask[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV6_MASK(portno));
    queue_regs->pfa_portx_ipv4_addr[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV4_ADDR(portno));
    queue_regs->pfa_portx_ipv4_mask[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_IPV4_MASK(portno));
}

void queue_portx_restore(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs)
{
    pfa_writel(pfa_ctx->regs, PFA_PORTX_UDP_LMTNUM(portno), queue_regs->pfa_portx_udp_lmtnum[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_LMTBYTE(portno), queue_regs->pfa_portx_lmtbyte[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_PROPERTY(portno), queue_regs->pfa_portx_property[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_L(portno), queue_regs->pfa_portx_mac_addr_l[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_H(portno), queue_regs->pfa_protx_mac_addr_h[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_1ST(portno), queue_regs->pfa_portx_ipv6_addr_1s[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_2ND(portno), queue_regs->pfa_portx_ipv6_addr_2n[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_3TH(portno), queue_regs->pfa_portx_ipv6_addr_3t[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV6_ADDR_4TH(portno), queue_regs->pfa_portx_ipv6_addr_4t[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV6_MASK(portno), queue_regs->pfa_portx_ipv6_mask[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV4_ADDR(portno), queue_regs->pfa_portx_ipv4_addr[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_IPV4_MASK(portno), queue_regs->pfa_portx_ipv4_mask[portno]);
}

void config_hash_cache_en(struct pfa *pfa, unsigned int enable)
{
    pfa_writel(pfa->regs, PFA_HASH_CACHE_EN, enable);
}

void config_adq_threshold_and_len(struct pfa *pfa, unsigned int size)
{
    pfa_writel_relaxed(pfa->regs, PFA_ADQ_THRESHOLD, size);
    pfa_writel_relaxed(pfa->regs, PFA_ADQ0_LEN, PFA_ADQ_LONG);
    pfa_writel_relaxed(pfa->regs, PFA_ADQ1_LEN, PFA_ADQ_SHORT);
}

void config_qos_lmttime(struct pfa *pfa, unsigned int value)
{
    pfa_writel(pfa->regs, PFA_QOS_LMTTIME, value);
}

void config_eth_vlan_tag_sel(struct pfa *pfa, unsigned int flag)
{
    return;
}

void config_dport_adq_core_type(struct pfa *pfa, unsigned int portno, unsigned int type)
{
    return;
}

void pfa_print_one_rd(struct pfa_rd_desc *cur_rd)
{
    PFA_ERR("rd_int_en %u \n", cur_rd->rd_int_en);
    PFA_ERR("rd_mode %u \n", cur_rd->rd_mode);
    PFA_ERR("rd_data_from_unsec %u \n", cur_rd->rd_data_from_unsec);
    PFA_ERR("rd_pfa_tft_dl_err_flag %u \n", cur_rd->rd_pfa_tft_dl_err_flag);
    PFA_ERR("rd_ack_flag %u \n", cur_rd->rd_ack_flag);
    PFA_ERR("rd_fc_head %u \n", cur_rd->rd_fc_head);
    PFA_ERR("rd_high_pri_flag %u \n", cur_rd->rd_high_pri_flag);
    PFA_ERR("rd_pkt_len %u \n", cur_rd->rd_pkt_len);

    PFA_ERR("\n RD word 1~2 \n");
    PFA_ERR("rd_out_lower %x \n", cur_rd->rd_outaddr_lower);
    PFA_ERR("rd_out_upper %x \n", cur_rd->rd_outaddr_upper);

    PFA_ERR("\n RD word 3 \n");
    PFA_ERR("rd_pdu_ssid %u \n", cur_rd->rd_pdu_ssid);
    PFA_ERR("rd_ips_id %u \n", cur_rd->rd_ips_id);
    PFA_ERR("rd_modem_id %u \n", cur_rd->rd_modem_id);
    PFA_ERR("rd_offset_bd %u \n", cur_rd->rd_offset_bd);
    PFA_ERR("rd_offset_bd_drct %u \n", cur_rd->rd_offset_bd_drct);
    PFA_ERR("rd_l2_hdr_offset %u \n", cur_rd->rd_l2_hdr_offset);
    PFA_ERR("rd_iptype %u \n", cur_rd->rd_iptype);

    PFA_ERR("\n RD word 4 \n");
    PFA_ERR("rd_trans_result %u \n", cur_rd->rd_trans_result);
    PFA_ERR("rd_drop_rsn %u \n", cur_rd->rd_drop_rsn);
    PFA_ERR("rd_trans_path %u \n", cur_rd->rd_trans_path);
    PFA_ERR("rd_trans_path_finish %u \n", cur_rd->rd_trans_path_finish);
    PFA_ERR("rd_pkt_type %u \n", cur_rd->rd_pkt_type);
    PFA_ERR("rd_finish_warp_res %u \n", cur_rd->rd_finish_warp_res);
    PFA_ERR("rd_tocpu_res %u \n", cur_rd->rd_tocpu_res);
    PFA_ERR("rd_bd_cd_len_not_same %u \n", cur_rd->rd_bd_cd_len_not_same);
    PFA_ERR("rd_updata_only %u \n", cur_rd->rd_updata_only);

    PFA_ERR("\n RD word 5 \n");
    PFA_ERR("rd_sport %x \n", cur_rd->rd_sport);
    PFA_ERR("rd_dport %x \n", cur_rd->rd_dport);
    PFA_ERR("rd_pktnum %x \n", cur_rd->rd_pktnum);
    PFA_ERR("rd_ethtype %x \n", cur_rd->rd_ethtype);

    PFA_ERR("\n RD word 6-9 \n");
    PFA_ERR("rd_pfa_tftres_stmid %x \n", cur_rd->rd_pfa_tftres_stmid);
    PFA_ERR("rd_user_field0 %x \n", cur_rd->rd_user_field0);
    PFA_ERR("rd_user_field1 %x \n", cur_rd->rd_user_field1);
    PFA_ERR("rd_user_field2 %x \n", cur_rd->rd_user_field2);
}

void pfa_print_one_td(struct pfa_td_desc *cur_td)
{
    PFA_ERR("TD word 0 \n");
    PFA_ERR("td_int_en %u \n", cur_td->td_int_en);
    PFA_ERR("td_mode %u \n", cur_td->td_mode);
    PFA_ERR("td_cd_en %u \n", cur_td->td_cd_en);
    PFA_ERR("td_copy_en %u \n", cur_td->td_copy_en);
    PFA_ERR("td_fc_head %u \n", cur_td->td_fc_head);
    PFA_ERR("td_push_en %u \n", cur_td->td_push_en);
    PFA_ERR("td_high_pri_flag %u \n", cur_td->td_high_pri_flag);
    PFA_ERR("td_pkt_len %u \n", cur_td->td_pkt_len);

    PFA_ERR("TD word 1~2 \n");
    PFA_ERR("td_in_lower %x \n", cur_td->td_inaddr_lower);
    PFA_ERR("td_in_upper %x \n", cur_td->td_inaddr_upper);

    PFA_ERR("TD word 3 \n");
    PFA_ERR("td_pdu_ssid %u \n", cur_td->td_pdu_ssid);
    PFA_ERR("td_modem_id %u \n", cur_td->td_modem_id);
    PFA_ERR("td_stick_en %u \n", cur_td->td_stick_en);
    PFA_ERR("td_iptype %u \n", cur_td->td_iptype);

    PFA_ERR("TD word 4 \n");
    PFA_ERR("td_bypass_en %u \n", cur_td->td_bypass_en);
    PFA_ERR("td_bypass_addr %u \n", cur_td->td_bypass_addr);
    PFA_ERR("td_host_ana %u \n", cur_td->td_host_ana);
    PFA_ERR("td_drop_ack_ind %u \n", cur_td->td_drop_ack_ind);
    PFA_ERR("td_usb_net_id %u \n", cur_td->td_usb_net_id);

    PFA_ERR("TD word 5-9 \n");
    PFA_ERR("td_result %x \n", cur_td->td_result);

    PFA_ERR("td_info %x \n", cur_td->td_info);

    PFA_ERR("td_user_field0 %x \n", cur_td->td_user_field0);
    PFA_ERR("td_user_field1 %x \n", cur_td->td_user_field1);
    PFA_ERR("td_user_field2 %x \n", cur_td->td_user_field2);
}

void set_update_only_produce_mod(struct pfa *pfa)
{
    unsigned int mod;

    mod = pfa_readl(pfa->regs, PFA_DEBUG_WORD);
    mod |= 0x1;

    pfa_writel(pfa->regs, PFA_DEBUG_WORD, mod);
}

void enable_macfw_to_ip(struct pfa *pfa, unsigned int portno, unsigned int enable)
{
    unsigned int value;

    value = pfa_readl_relaxed(pfa->regs, PFA_MAC_IP_FW_FLAG);
    if (enable) {
        pfa_writel(pfa->regs, PFA_MAC_IP_FW_FLAG, value |= BIT(portno));
    } else {
        pfa_writel(pfa->regs, PFA_MAC_IP_FW_FLAG, value &= (~BIT(portno)));
    }
}

