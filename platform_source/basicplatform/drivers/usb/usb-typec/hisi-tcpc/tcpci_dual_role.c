/*
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
 *
 * Copyright (C) 2016 Richtek Technology Corp.
 * Author: TH <tsunghan_tsai@richtek.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/timekeeping.h>
#include <linux/time64.h>
#include <linux/usb/class-dual-role.h>
#include <linux/delay.h>

#include "include/tcpci.h"
#include "include/tcpci_typec.h"
#include "../hisi-usb-typec.h"

static enum dual_role_property tcpc_dual_role_props[] = {
	DUAL_ROLE_PROP_SUPPORTED_MODES,
	DUAL_ROLE_PROP_MODE,
	DUAL_ROLE_PROP_PR,
	DUAL_ROLE_PROP_DR,
	DUAL_ROLE_PROP_VCONN_SUPPLY,
};

static int tcpc_dual_role_get_prop(struct dual_role_phy_instance *dual_role,
		enum dual_role_property prop, unsigned int *val)
{
	struct tcpc_device *tcpc = dev_get_drvdata(dual_role->dev.parent);
	int ret = 0;

	switch (prop) {
	case DUAL_ROLE_PROP_SUPPORTED_MODES:
		*val = tcpc->dual_role_supported_modes;
		break;

	case DUAL_ROLE_PROP_MODE:
		*val = tcpc->dual_role_mode;
		break;

	case DUAL_ROLE_PROP_PR:
		*val = tcpc->dual_role_pr;
		break;

	case DUAL_ROLE_PROP_DR:
		*val = tcpc->dual_role_dr;
		break;

	case DUAL_ROLE_PROP_VCONN_SUPPLY:
		*val = tcpc->dual_role_vconn;
		break;

	default:
		ret = -EINVAL;
		break;
	}

	D("prop %u val %u\n", prop, *val);
	return ret;
}

static int tcpc_dual_role_prop_is_writeable(
		struct dual_role_phy_instance *dual_role,
		enum dual_role_property prop)
{
	int retval = -ENOSYS;
	struct tcpc_device *tcpc = dev_get_drvdata(dual_role->dev.parent);

	D("+\n");
	switch (prop) {
	case DUAL_ROLE_PROP_PR:
	case DUAL_ROLE_PROP_DR:
	case DUAL_ROLE_PROP_VCONN_SUPPLY:
		if (tcpc->dual_role_supported_modes ==
				DUAL_ROLE_SUPPORTED_MODES_DFP_AND_UFP)
			retval = 1;
		break;

	default:
		break;
	}

	D("-\n");
	return retval;
}

static int tcpc_dual_role_pr_swap(struct tcpc_device *tcpc, uint8_t new_role)
{
	if (new_role == tcpc->dual_role_pr) {
		D("Same Power Role\n");
		return 0;
	}

	D("Power role swap (%u->%u)\n", tcpc->dual_role_pr, new_role);

	return hisi_tcpm_power_role_swap(tcpc);
}

static int tcpc_dual_role_dr_swap(struct tcpc_device *tcpc, uint8_t new_role)
{
	if (new_role == tcpc->dual_role_dr) {
		D("Same Data Role\n");
		return 0;
	}

	D("Data role swap (%u->%u)\n", tcpc->dual_role_dr, new_role);

	return hisi_tcpm_data_role_swap(tcpc);
}

static int tcpc_dual_role_vconn_swap(struct tcpc_device *tcpc, uint8_t new_role)
{
	if (new_role == tcpc->dual_role_vconn) {
		E("Same Vconn\n");
		return 0;
	}

	D("Vconn swap (%u->%u)\n", tcpc->dual_role_vconn, new_role);

	return hisi_tcpm_vconn_swap(tcpc);
}

static int rcg_to_rscp(struct tcpc_device *tcpc)
{
	set_desc_role_def(TYPEC_ROLE_SRC);
	tcpci_set_cc(tcpc, TYPEC_CC_RD);					

	return 0;
}

static int rscp_to_rcg(struct tcpc_device *tcpc)
{
	tcpc->pd_port.prev_rever_flag = false;
	tcpc->pd_port.curr_rever_flag = false;
	set_desc_role_def(TYPEC_ROLE_SRC);
	tcpci_set_cc(tcpc, TYPEC_CC_RD);

	return 0;
}

static int bcg_to_rscp(struct tcpc_device *tcpc)
{
	set_desc_role_def(TYPEC_ROLE_SRC);
	tcpci_set_cc(tcpc, TYPEC_CC_RP);
	return 0;
}

static int rscp_to_bcg(struct tcpc_device *tcpc)
{
	tcpc->pd_port.prev_rever_flag = false;
	tcpc->pd_port.curr_rever_flag = false;
	hisi_tcpm_typec_change_role(tcpc, TYPEC_ROLE_SNK);
	mdelay(500);
	hisi_tcpm_typec_change_role(tcpc, TYPEC_ROLE_TRY_SNK);

	return 0;
}

static int bcg_to_rcg(struct tcpc_device *tcpc)
{
	return tcpc_dual_role_pr_swap(tcpc, POWER_ROLE_SOURCE);
}

static int rcg_to_bcg(struct tcpc_device *tcpc)
{
	return tcpc_dual_role_pr_swap(tcpc, POWER_ROLE_SINK);
}

static int tcpc_dual_role_set_prop(struct dual_role_phy_instance *dual_role,
		enum dual_role_property prop, const unsigned int *val)
{
	struct tcpc_device *tcpc = dev_get_drvdata(dual_role->dev.parent);
	int ret = 0;

	D("prop %u val %u\n", prop, *val);
	switch (prop) {
#ifdef CONFIG_USB_POWER_DELIVERY_SUPPORT
	case DUAL_ROLE_PROP_PR:
		if (!get_desc_support_reverse_sc())
			ret = tcpc_dual_role_pr_swap(tcpc, *val);
		break;

	case DUAL_ROLE_PROP_DR:
		if (!get_desc_support_reverse_sc() || !tcpc->pd_port.curr_rever_flag)
			ret = tcpc_dual_role_dr_swap(tcpc, *val);
		break;

	case DUAL_ROLE_PROP_VCONN_SUPPLY:
		ret = tcpc_dual_role_vconn_swap(tcpc, *val);
		break;

	default:
		break;
#else
	case DUAL_ROLE_PROP_PR:
		ret = hisi_tcpm_typec_role_swap(tcpc);
		if (ret)
			E("hisi_tcpm_typec_role_swap failed\n");
		break;

	default:
		break;
#endif
	}

	return ret;
}

void tcpc_drive_path_prop(int val, struct tcpc_device *tcpc)
{
	if (!get_desc_support_reverse_sc())
		return;
	int path = 0;
	tcpc->pd_port.pd_curr_unattach = true;
	I("drive prop:cur_rever:%d prev_rever:%d dual_role_pr:%d\n",
		tcpc->pd_port.curr_rever_flag, tcpc->pd_port.prev_rever_flag, tcpc->dual_role_pr);
	switch (val) {
	case PR_SINK_NODE:
		tcpc->pd_port.curr_rever_flag = false;
		if (tcpc->pd_port.prev_rever_flag && tcpc->dual_role_pr == POWER_ROLE_SOURCE) {
			path = RSCP_TO_BCG;
		} else {
			path = RCG_TO_BCG;
		}
		break;
	case PR_SOURCE_NODE_NONE:
		tcpc->pd_port.curr_rever_flag = false;
		if (tcpc->pd_port.prev_rever_flag) {
			path = RSCP_TO_RCG;
		} else {
			path = BCG_TO_RCG;
		}
		break;
	case PR_SOURCE_NODE_REVER:
		tcpc->pd_port.curr_rever_flag = true;
		if (tcpc->dual_role_pr == POWER_ROLE_SOURCE) {
			path = RCG_TO_RSCP;
		} else {
			path = BCG_TO_RSCP;
		}
		break;
	default:
		break;
	}
	tcpc->pd_port.prev_rever_flag = tcpc->pd_port.curr_rever_flag;
	tcpc->pd_port.state_transfer_path = path;
	I("pd state_transfer_path: %d\n", tcpc->pd_port.state_transfer_path);
	switch (path) {
	case RCG_TO_RSCP:
		I("path: RCG_TO_RSCP\n");
		rcg_to_rscp(tcpc);
		break;
	case RSCP_TO_RCG:
		I("path: RSCP_TO_RCG\n");
		rscp_to_rcg(tcpc);
		break;
	case BCG_TO_RSCP:
		I("path: BCG_TO_RSCP\n");
		bcg_to_rscp(tcpc);
		break;
	case RSCP_TO_BCG:
		I("path: RSCP_TO_BCG\n");
		rscp_to_bcg(tcpc);
		break;
	case BCG_TO_RCG:
		I("path: BCG_TO_RCG\n");
		bcg_to_rcg(tcpc);
		break;
	case RCG_TO_BCG:
		I("path: RCG_TO_BCG\n");
		rcg_to_bcg(tcpc);
		break;	
	default:
		break;
	}
}

static void tcpc_get_dual_desc(struct tcpc_device *tcpc)
{
	struct device_node *np = of_find_node_by_name(NULL, tcpc->desc.name);
	u32 val = 0;

	if (!np)
		return;

	if (of_property_read_u32(np, "hisi-tcpc,supported_modes", &val) >= 0) {
		if (val > DUAL_ROLE_PROP_SUPPORTED_MODES_TOTAL)
			tcpc->dual_role_supported_modes =
				DUAL_ROLE_SUPPORTED_MODES_DFP_AND_UFP;
		else
			tcpc->dual_role_supported_modes = val;
	}
}

void hisi_tcpc_dual_role_instance_changed(
		struct dual_role_phy_instance *dual_role)
{
	static int change_counter = 0;
	static bool first_enter = true;
	static struct timespec64 ts64_last;

	struct timespec64 ts64_interval;
	struct timespec64 ts64_now;
	struct timespec64 ts64_sum;
	int change_counter_threshold = 100;

	D("+\n");
	ts64_interval.tv_sec = 0;
	ts64_interval.tv_nsec = 100 * NSEC_PER_MSEC;
	ktime_get_coarse_real_ts64(&ts64_now);

	if (first_enter) {
		first_enter = false;
	} else {
		ts64_sum = timespec64_add_safe(ts64_last, ts64_interval);
		if (ts64_sum.tv_sec == TIME64_MAX) {
			E("time overflow happend\n");
			change_counter = 0;
		} else if (timespec64_compare(&ts64_sum, &ts64_now) >= 0) {
			++change_counter;
			change_counter =
				(change_counter > change_counter_threshold) ?
					change_counter_threshold :
					change_counter;
			D("change_counter = %d\n", change_counter);
		} else {
			change_counter = 0;
		}
	}

	if (change_counter >= change_counter_threshold)
		D("change_counter hit\n");
	else
		dual_role_instance_changed(dual_role);

	ts64_last =  ts64_now;
	D("-\n");
}

int hisi_tcpc_dual_role_phy_init(struct tcpc_device *tcpc)
{
	struct dual_role_phy_desc *dual_desc = NULL;

	dual_desc = devm_kzalloc(&tcpc->dev, sizeof(*dual_desc), GFP_KERNEL);
	if (!dual_desc)
		return -ENOMEM;

	tcpc_get_dual_desc(tcpc);
	D("supported modes %u\n", tcpc->dual_role_supported_modes);

	dual_desc->name = "hisi-tcpc-dual-role";
	dual_desc->properties = tcpc_dual_role_props;
	dual_desc->num_properties = ARRAY_SIZE(tcpc_dual_role_props);
	dual_desc->get_property = tcpc_dual_role_get_prop;
	dual_desc->set_property = tcpc_dual_role_set_prop;
	dual_desc->property_is_writeable = tcpc_dual_role_prop_is_writeable;

	tcpc->dr_usb = devm_dual_role_instance_register(&tcpc->dev, dual_desc);
	if (IS_ERR(tcpc->dr_usb)) {
		dev_err(&tcpc->dev, "tcpc fail to register dual role usb\n");
		return -EINVAL;
	}

	/* init dual role phy instance property */
	tcpc->dual_role_pr = DUAL_ROLE_PROP_PR_NONE;
	tcpc->dual_role_dr = DUAL_ROLE_PROP_DR_NONE;
	tcpc->dual_role_mode = DUAL_ROLE_PROP_MODE_NONE;
	tcpc->dual_role_vconn = DUAL_ROLE_PROP_VCONN_SUPPLY_NO;

	return 0;
}

bool get_reverse_charge_enable(struct tcpc_device *tcpc)
{
	I("send charge_rever_flag :%d\n", tcpc->pd_port.curr_rever_flag);
	return tcpc->pd_port.curr_rever_flag;
}

void clear_rchg_rever_flag(struct tcpc_device *tcpc)
{
	tcpc->pd_port.curr_rever_flag = false;
	tcpc->pd_port.pd_curr_unattach = false;
	tcpc->pd_port.prev_rever_flag = false;
	I("clear curr_rever_flag pd_curr_unattach prev_rever_flag\n");
}
 
int get_state_path(struct tcpc_device *tcpc)
{
	return tcpc->pd_port.state_transfer_path;
}

bool get_first_attach(struct tcpc_device *tcpc)
{
	if (!tcpc->pd_port.pd_curr_unattach && tcpc->pd_port.state_transfer_path == 0) {
		tcpc->pd_port.first_attach = true;
	}
	else {
		tcpc->pd_port.first_attach = false;
	}
	I("send pd first_attach : %d\n", tcpc->pd_port.first_attach);
	return tcpc->pd_port.first_attach;
}

bool timer_called_by_timeout(struct tcpc_device *tcpc)
{
	return tcpc->pd_port.called_by_timeout;
}

bool get_pd_unattach_state(struct tcpc_device *tcpc)
{
	return tcpc->pd_port.pd_curr_unattach;
}

bool rchg_check_cc_state(struct tcpc_device *tcpc)
{
	D("rchg check tcpc_dev->typec_state: %d\n", tcpc->typec_state);
	return tcpc->typec_state > CC_UNATTACH_SCOPE ? false : true;
}