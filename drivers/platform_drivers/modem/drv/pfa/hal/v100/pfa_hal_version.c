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
#include "pfa_tft_reg.h"
#include "pfa_hal_reg.h"
#include "pfa_tft.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

struct pfa_om_reg_set g_pfa_om_reg[] = {
    {
        .start = 0x0,
        .end = 0x61c
    },
    {
        .start = 0x700,
        .end = 0x71c
    },
    {
        .start = 0x800,
        .end = 0x9fc
    },
    {
        .start = 0xa00,
        .end = 0xafc
    },
    {
        .start = 0xc00,
        .end = 0xcbc
    },
    {
        .start = 0xc000,
        .end = 0xc12c
    },
};

unsigned int g_pfa_reset_bak_reg[PFA_RESET_BAK_REG_NUM][PFA_STASH_REG_BUTTON] = {

};

void config_tft_svlan_tag_sel(unsigned int flag)
{
    unsigned int reg;

    UPDATE1(reg, PFA_TFT_CTRL, svlan_tag_sel, flag);
}

void config_tft_bd_rd_ip_head(struct pfa *pfa)
{
    return;
}

void tft_config_rd_ip_head(unsigned int ext_desc_en)
{
    return;
}

void config_tft_bd_rd_ptr_update(struct pfa *pfa, struct iport_pfa_tft_addr *pfa_tft_reg)
{
    return;
}

void queue_portx_save(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs)
{
    queue_regs->pfa_portx_udp_lmtnum[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_UDP_LMTNUM(portno));
    queue_regs->pfa_portx_lmtbyte[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_LMTBYTE(portno));
    queue_regs->pfa_portx_property[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_PROPERTY(portno));
    queue_regs->pfa_portx_mac_addr_l[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_L(portno));
    queue_regs->pfa_protx_mac_addr_h[portno] = pfa_readl(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_H(portno));
}

void queue_portx_restore(struct pfa *pfa_ctx, unsigned int portno, struct pfa_queue_stash *queue_regs)
{
    pfa_writel(pfa_ctx->regs, PFA_PORTX_UDP_LMTNUM(portno), queue_regs->pfa_portx_udp_lmtnum[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_LMTBYTE(portno), queue_regs->pfa_portx_lmtbyte[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_PROPERTY(portno), queue_regs->pfa_portx_property[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_L(portno), queue_regs->pfa_portx_mac_addr_l[portno]);
    pfa_writel(pfa_ctx->regs, PFA_PORTX_MAC_ADDR_H(portno), queue_regs->pfa_protx_mac_addr_h[portno]);
}

void config_hash_cache_en(struct pfa *pfa, unsigned int enable)
{
    return;
}

void config_adq_threshold_and_len(struct pfa *pfa, unsigned int size)
{
    return;
}

void config_qos_lmttime(struct pfa *pfa, unsigned int value)
{
    return;
}

void config_eth_vlan_tag_sel(struct pfa *pfa, unsigned int flag)
{
    eth_vlan_tag_sel value;

    value.u32 = pfa_readl(pfa->regs, PFA_TOP_TAG_SEL_REG);
    value.bits.one_vlan_tag_sel = flag;
    pfa_writel(pfa->regs, PFA_TOP_TAG_SEL_REG, value.u32);
    if (flag) {
        pfa_writel(pfa->regs, PFA_TOP_SVLAN_TPID0_REG, 0x88a8);
        pfa_writel(pfa->regs, PFA_TOP_SVLAN_TPID1_REG, 0x9100);
        pfa_writel(pfa->regs, PFA_TOP_SVLAN_TPID2_REG, 0x9200);
        pfa_writel(pfa->regs, PFA_TOP_SVLAN_TPID3_REG, 0x8300);
    } else {
        pfa_writel(pfa->regs, PFA_TOP_SVLAN_TPID0_REG, 0x8100);
    }
}

void config_dport_adq_core_type(struct pfa *pfa, unsigned int portno, unsigned int type)
{
    pfa_port_prop_t prop;

    prop.u32 = pfa_readl(pfa->regs, PFA_PORTX_PROPERTY(portno));
    prop.bits.pfa_dport_adq_core_type = type;
    pfa_writel(pfa->regs, PFA_PORTX_PROPERTY(portno), prop.u32);
}

void pfa_print_one_rd_word_five_to_end(struct pfa_rd_desc *cur_rd)
{
    PFA_ERR("\n RD word 5 \n");
    PFA_ERR("rd_sport %x \n", cur_rd->rd_sport);
    PFA_ERR("rd_dport %x \n", cur_rd->rd_dport);
    PFA_ERR("rd_pktnum %x \n", cur_rd->rd_pktnum);
    PFA_ERR("rd_ethtype %x \n", cur_rd->rd_ethtype);

    PFA_ERR("\n RD word 6 \n");
    PFA_ERR("rd_pfa_tftres_stmid %x \n", cur_rd->rd_pfa_tftres_stmid);

    PFA_ERR("\n RD word 7 \n");
    PFA_ERR("rd_reserve5 %u \n", cur_rd->rd_reserve5);
    PFA_ERR("rd_vlan_flag %u \n", cur_rd->rd_vlan_flag);
    PFA_ERR("rd_vlan_pcp %u \n", cur_rd->rd_vlan_pcp);
    PFA_ERR("rd_vlan_vid %u \n", cur_rd->rd_vlan_vid);
    PFA_ERR("rd_qos_priority %u \n", cur_rd->rd_qos_priority);
    PFA_ERR("rd_qos_discard_time %u \n", cur_rd->rd_qos_discard_time);

    PFA_ERR("\n RD word 8 \n");
    PFA_ERR("tft_pdcp_cnt %x \n", cur_rd->tft_pdcp_cnt);

    PFA_ERR("\n RD word 9-11 \n");
    PFA_ERR("rd_user_field0 %x \n", cur_rd->rd_user_field0);
    PFA_ERR("rd_user_field1 %x \n", cur_rd->rd_user_field1);
    PFA_ERR("rd_user_field2 %x \n", cur_rd->rd_user_field2);
}

void pfa_print_one_rd(struct pfa_rd_desc *cur_rd)
{
    PFA_ERR("rd_int_en %u \n", cur_rd->rd_int_en);
    PFA_ERR("rd_mode %u \n", cur_rd->rd_mode);
    PFA_ERR("rd_cd_en %u \n", cur_rd->rd_cd_en);
    PFA_ERR("rd_data_from_unsec %u \n", cur_rd->rd_data_from_unsec);
    PFA_ERR("rd_ptp_syn_ind %u \n", cur_rd->rd_ptp_syn_ind);
    PFA_ERR("rd_pfa_tft_dl_err_flag %u \n", cur_rd->rd_pfa_tft_dl_err_flag);
    PFA_ERR("rd_ack_flag %u \n", cur_rd->rd_ack_flag);
    PFA_ERR("rd_fc_head %u \n", cur_rd->rd_fc_head);
    PFA_ERR("rd_packet_ind %u \n", cur_rd->rd_packet_ind);
    PFA_ERR("rd_v2x_ind %u \n", cur_rd->rd_v2x_ind);
    PFA_ERR("rd_tft_mac_err %u \n", cur_rd->rd_tft_mac_err);
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
    PFA_ERR("rd_iptype %u \n", cur_rd->rd_pkt_type);

    PFA_ERR("\n RD word 4 \n");
    PFA_ERR("rd_trans_result %u \n", cur_rd->rd_trans_result);
    PFA_ERR("rd_drop_rsn %u \n", cur_rd->rd_drop_rsn);
    PFA_ERR("rd_trans_path %u \n", cur_rd->rd_trans_path);
    PFA_ERR("rd_trans_path_finish %u \n", cur_rd->rd_trans_path_finish);
    PFA_ERR("rd_pkt_err %u \n", cur_rd->rd_pkt_err);
    PFA_ERR("rd_finish_warp_res %u \n", cur_rd->rd_finish_warp_res);
    PFA_ERR("rd_tocpu_res %u \n", cur_rd->rd_tocpu_res);

    pfa_print_one_rd_word_five_to_end(cur_rd);
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
    PFA_ERR("td_pdu_ssid %u \n", cur_td->v2x_ind);
    PFA_ERR("td_modem_id %u \n", cur_td->td_modem_id);
    PFA_ERR("td_stick_en %u \n", cur_td->td_stick_en);
    PFA_ERR("td_pkt_ind %u \n", cur_td->pkt_ind);
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
}

void enable_macfw_to_ip(struct pfa *pfa, unsigned int portno, unsigned int enable)
{
    pfa_port_prop_t property;

    property.u32 = pfa_readl_relaxed(pfa->regs, PFA_PORTX_PROPERTY(portno));
    if (enable) {
        property.bits.mac_ip_fw_flag = 1;
    } else {
        property.bits.mac_ip_fw_flag = 0;
    }
    pfa_writel_relaxed(pfa->regs, PFA_PORTX_PROPERTY(portno), property.u32);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */