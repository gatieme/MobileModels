/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
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
 */

#include <linux/bitops.h>
#include <linux/rcupdate.h>
#include "mdrv_pfa.h"
#include "rnic_vnet.h"
#include "rnic_vnet_hdlr.h"
#include "rnic_private.h"
#include "rnic_vnet_cfg.h"

static inline int rnic_vnet_add_lan_netdev(struct rnic_vnet_priv_s *priv)
{
	return 0;
}

static inline int rnic_vnet_rm_lan_netdev(struct rnic_vnet_priv_s *priv)
{
	return 0;
}

STATIC void rnic_vnet_eth_rx_cb_regist(struct rnic_vnet_priv_s *priv, u32 pif_id)
{
	struct rnic_handle_s *handle = priv->handle;

	if (likely(handle->ops != NULL))
		handle->ops->rx_cb_register(pif_id, 1);
}

STATIC void rnic_vnet_eth_link_cfg(struct rnic_vnet_priv_s *priv, u32 pif_id)
{
	priv->fill_desc = rnic_vnet_fill_eth_desc;
	rnic_vnet_add_lan_netdev(priv);
	rnic_vnet_eth_rx_cb_regist(priv, pif_id);
}

STATIC void rnic_vnet_eth_link_rel(struct rnic_vnet_priv_s *priv)
{
	priv->fill_desc = NULL;
	rnic_vnet_rm_lan_netdev(priv);
}

STATIC void rnic_vnet_ip_link_cfg(struct rnic_vnet_priv_s *priv, u32 pif_id)
{
	struct rnic_handle_s *handle = priv->handle;

	if (priv->frag_en)
		priv->fill_desc = rnic_vnet_fill_frag_desc;
	else
		priv->fill_desc = rnic_vnet_fill_ip_desc;

	rnic_vnet_reg_wan_dev(priv);

	if (likely(handle->ops != NULL))
		handle->ops->rx_cb_register(pif_id, 1);
}

STATIC void rnic_vnet_ip_link_rel(struct rnic_vnet_priv_s *priv)
{
	if (!test_bit(RNIC_ADDR_IPV4, &priv->link_state) &&
	    !test_bit(RNIC_ADDR_IPV6, &priv->link_state))
	    priv->fill_desc = NULL;

	rnic_vnet_reg_wan_dev(priv);
}

STATIC void rnic_vnet_mbs_link_cfg(struct rnic_vnet_priv_s *priv, u32 pif_id)
{
	struct rnic_handle_s *handle = priv->handle;

	priv->fill_desc = NULL;
	rnic_vnet_reg_wan_dev(priv);

	if (likely(handle->ops != NULL))
		handle->ops->rx_cb_register(pif_id, 1);
}

STATIC void rnic_vnet_mbs_link_rel(struct rnic_vnet_priv_s *priv)
{
	priv->fill_desc = NULL;
	rnic_vnet_reg_wan_dev(priv);
}

STATIC int rnic_vnet_link_cfg(struct rnic_vnet_priv_s *priv, const struct rnic_link_info_s *info)
{
	enum rnic_addr_type_e addr_type = info->type;

	priv->copy_en = info->copy_en;
	priv->tft_infos[addr_type] = info->tft_info;
	set_bit(addr_type, &priv->link_state);

	if (addr_type == RNIC_ADDR_IPV4 || addr_type == RNIC_ADDR_IPV6)
		rnic_vnet_ip_link_cfg(priv, info->pif_id);
	else if (addr_type == RNIC_ADDR_ETH)
		rnic_vnet_eth_link_cfg(priv, info->pif_id);
	else
		rnic_vnet_mbs_link_cfg(priv, info->pif_id);

	return 0;
}

STATIC int rnic_vnet_link_rel(struct rnic_vnet_priv_s *priv, const struct rnic_link_info_s *info)
{
	enum rnic_addr_type_e type = info->type;

	priv->tft_infos[type] = info->tft_info;
	clear_bit(type, &priv->link_state);

	if (type == RNIC_ADDR_IPV4 || type == RNIC_ADDR_IPV6)
		rnic_vnet_ip_link_rel(priv);
	else if (type == RNIC_ADDR_ETH)
		rnic_vnet_eth_link_rel(priv);
	else
		rnic_vnet_mbs_link_rel(priv);

	return 0;
}

int rnic_vnet_reg_wan_dev(const struct rnic_vnet_priv_s *priv)
{
	struct wan_dev_info_s winfo = {0};

	winfo.dev           = priv->netdev;
	winfo.v4.info       = priv->tft_infos[RNIC_ADDR_IPV4];
	winfo.v4.userfield0 = priv->pif_id | (priv->drop_code << RNIC_WAN_DROP_SHIFT);
	winfo.v6.info       = priv->tft_infos[RNIC_ADDR_IPV6];
	winfo.v6.userfield0 = priv->pif_id | (priv->drop_code << RNIC_WAN_DROP_SHIFT);

	return mdrv_wan_dev_info_register(&winfo);
}

void rnic_vnet_link_init(struct rnic_vnet_priv_s *priv)
{
	struct pfa_tft_info_s tft_info = {
		.pdu_session_id = RNIC_INVALID_SESSID,
		.fc_head        = RNIC_INVALID_FCHEAD,
		.modem_id       = RNIC_INVALID_MODEMID,
	};
	int i;

	for (i = 0; i < RNIC_ADDR_MAX; i++) {
		clear_bit(i, &priv->link_state);
		priv->tft_infos[i] = tft_info;
	}
}

int rnic_vnet_link_change(struct rnic_handle_s *handle, const struct rnic_link_info_s *info)
{
	struct rnic_vnet_ctx_s *vctx = handle->priv;

	if (info->link_up)
		rnic_vnet_link_cfg(vctx->privs[info->pif_id], info);
	else
		rnic_vnet_link_rel(vctx->privs[info->pif_id], info);

	return 0;
}

void rnic_vnet_feature_cfg(struct rnic_handle_s *handle, const void *cfg)
{
	struct rnic_vnet_ctx_s *vctx = handle->priv;

	if (vctx->srs_ops != NULL)
		vctx->srs_ops->set_feature_cfg(cfg);
}

void rnic_vnet_reset_notify(struct rnic_handle_s *handle)
{
	struct rnic_vnet_ctx_s *vctx = handle->priv;
	struct rnic_vnet_priv_s *priv = NULL;
	unsigned long long pifmask = handle->client->pif_bitmask;
	const unsigned long *bitmasks = (const unsigned long *)&pifmask;
	unsigned long bit;

	for_each_set_bit(bit, bitmasks, (unsigned long)RNIC_MAX_PIF_NUM) {
		priv = vctx->privs[bit];
		rnic_vnet_link_init(priv);

		priv->fill_desc = NULL;

		rnic_vnet_rm_lan_netdev(priv);
		rnic_vnet_reg_wan_dev(priv);
	}
}
