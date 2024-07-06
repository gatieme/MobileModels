/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#include "pfa_mac_entry.h"

int exe_pfa_mac_pdu_cmd(void)
{
    return 0;
}
int mac_pdu_index(const char *buf) {return 0;}
int mac_pdu_rule_type(const char *buf) {return 0;}
int mac_pdu_mask(const char *buf) {return 0;}
int mac_pdu_modem_id(const char *buf) {return 0;}
int mac_pdu_session_status(const char *buf) {return 0;}
int mac_pdu_eth_type(const char *buf) {return 0;}
int mac_pdu_s_tag_vid_start(const char *buf) {return 0;}
int mac_pdu_s_tag_pcp_dei(const char *buf) {return 0;}
int mac_pdu_s_tag_vid_end(const char *buf) {return 0;}
int mac_pdu_s_tag_pcp_dei_mask(const char *buf) {return 0;}
int mac_pdu_c_tag_vid_start(const char *buf) {return 0;}
int mac_pdu_c_tag_pcp_dei(const char *buf) {return 0;}
int mac_pdu_c_tag_vid_end(const char *buf) {return 0;}
int mac_pdu_c_tag_pcp_dei_mask(const char *buf) {return 0;}
int mac_pdu_dmac(const char *buf) {return 0;}
int mac_pdu_session_id(const char *buf) {return 0;}
int mac_pdu_session_vld(const char *buf) {return 0;}
int mac_pdu_fc_head(const char *buf) {return 0;}
int pfa_mac_pdu_add(struct pfa_mac_pdu_entry *ent) {return 0;}

int exe_pfa_ip_qos_cmd(void)
{
    return 0;
}
int ip_qos_filter_mask(const char *buf) {return 0;}
int ip_qos_sport_min(const char *buf) {return 0;}
int ip_qos_sport_max(const char *buf) {return 0;}
int ip_qos_dport_min(const char *buf) {return 0;}
int ip_qos_dport_max(const char *buf) {return 0;}
int ip_qos_sip(const char *buf) {return 0;}
int ip_qos_sip_mask(const char *buf) {return 0;}
int ip_qos_dip(const char *buf) {return 0;}
int ip_qos_dip_mask(const char *buf) {return 0;}
int ip_qos_protocol_or_next_hdr(const char *buf) {return 0;}
int ip_qos_priority(const char *buf) {return 0;}
int ip_qos_discard_time(const char *buf) {return 0;}
int ip_qos_flow_label(const char *buf) {return 0;}
int ip_qos_dscp_max(const char *buf) {return 0;}
int ip_qos_dscp_min(const char *buf) {return 0;}
int pfa_ip_qos_add(struct pfa_ip_qos_entry *ent) {return 0;}
int pfa_ip_qos_del(struct pfa_ip_qos_entry *ent) {return 0;}

EXPORT_SYMBOL(pfa_mac_pdu_add);
EXPORT_SYMBOL(pfa_ip_qos_add);
EXPORT_SYMBOL(pfa_ip_qos_del);