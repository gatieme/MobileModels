#include <soc_sctrl_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_pctrl_interface.h>
#include <soc_usb31_misc_ctrl_interface.h>
#include <soc_usb31_tca_interface.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/hisi/contexthub/tca.h>
#include "inputhub_route.h"
#include "common.h"

#define PD_PLATFORM_INIT_OK (0X56781234)
struct pd_ipc {
	pkt_header_t hd;
	int usb_or_dp;/*usb 0*/
	int in_or_out;/*in 0*/
};

struct pd_config_res {
	int init;
	void __iomem *pericfg_reg_base;
	void __iomem *sctrl_reg_base;
	void __iomem *pctrl_reg_base;
	void __iomem *usb3otg_bc_base;
	void __iomem *usb3otg_base;
	void __iomem *tca_base;
	void __iomem *dp_ctrl_base;
};

static DEFINE_MUTEX(pd_event_mutex);
static DEFINE_MUTEX(pd_sw_mutex);
static struct pd_config_res pd_res;

__weak void hisi_dptx_hpd_trigger(int inout)
{
	pr_info("[%s][%d]\n", __func__, inout);
}

static int pd_get_config_resource(struct pd_config_res * res,
	struct device_node *dev_node)
{
	struct device_node *np;
	/*
	 * map PERI CRG region
	 */
	np = of_find_compatible_node(NULL, NULL, "hisilicon,crgctrl");
	if (!np) {
		pr_err("[%s]get peri cfg node failed!\n", __func__);
		return -EINVAL;
	}
	res->pericfg_reg_base = of_iomap(np, 0);
	if (!res->pericfg_reg_base) {
		pr_err("[%s]iomap pericfg_reg_base failed!\n", __func__);
		return -EINVAL;
	}

	/*
	 * map SCTRL region
	 */
	np = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
	if (!np) {
		pr_err("[%s]get sysctrl node failed!\n", __func__);
		goto CRGCTRL_MAP_REL;
	}
	res->sctrl_reg_base = of_iomap(np, 0);
	if (!res->sctrl_reg_base) {
		pr_err("[%s]iomap sctrl_reg_base failed!\n", __func__);
		goto CRGCTRL_MAP_REL;
	}

	/*
	 * map PCTRL region
	 */
	np = of_find_compatible_node(NULL, NULL, "hisilicon,pctrl");
	if (!np) {
		pr_err("[%s]get pctrl node failed!\n",__func__);
		goto SCTRL_MAP_REL;
	}
	res->pctrl_reg_base = of_iomap(np, 0);
	if (!res->pctrl_reg_base) {
		pr_err("[%s]iomap pctrl_reg_base failed!\n",__func__);
		goto SCTRL_MAP_REL;
	}

	/*
	 * map USB2OTG bc region
	 */
	np = of_find_compatible_node(NULL, NULL, "hisilicon,usb3otg_bc");
	if (!np) {
		pr_err("[%s]get usb3otg_bc failed!\n",__func__);
		goto PCTRL_MAP_REL;
	}
	res->usb3otg_bc_base = of_iomap(np, 0);
	if (!res->usb3otg_bc_base) {
		pr_err("[%s]iomap usb3otg_bc failed!\n",__func__);
		goto PCTRL_MAP_REL;
	}

	res->tca_base = res->usb3otg_bc_base + 0x200;

	/*
	 * map USB2OTG region
	 */
	np = of_find_compatible_node(NULL, NULL, "hisilicon,usb3otg");
	if (!np) {
		pr_err("[%s]get usb3otg node failed!\n",__func__);
		goto USB3OTG_BC_MAP_REL;
	}
	res->usb3otg_base = of_iomap(np, 0);
	if (!res->usb3otg_base) {
		pr_err("[%s]iomap usb3otg failed!\n",__func__);
		goto USB3OTG_BC_MAP_REL;
	}

	np = of_find_compatible_node(NULL, NULL, "hisilicon,dpctrl");
	if (!np) {
		pr_err("[%s]get dpctrl node failed!\n",__func__);
		goto USB3OTG_MAP_REL;
	}
	res->dp_ctrl_base = of_iomap(np, 0);
	if (!res->dp_ctrl_base) {
		pr_err("[%s]iomap dpctrl failed!\n",__func__);
		goto USB3OTG_MAP_REL;
	}

	return 0;

USB3OTG_MAP_REL:
	iounmap(res->usb3otg_base);
USB3OTG_BC_MAP_REL:
	iounmap(res->usb3otg_bc_base);
PCTRL_MAP_REL:
	iounmap(res->pctrl_reg_base);
SCTRL_MAP_REL:
	iounmap(res->sctrl_reg_base);
CRGCTRL_MAP_REL:
	iounmap(res->pericfg_reg_base);
	return -1;
}

static void tca_notify_usb_dp_ctrl(TCPC_MUX_CTRL_TYPE mode_type, enum otg_dev_event_type usb_type)
{
	int dp_inout = (TCPC_DP&mode_type) >>1;
	pr_info("[%s]DPinout[%d]USB[%d]", __func__, dp_inout, usb_type);
	hisi_dptx_hpd_trigger(dp_inout);
	(void)hisi_usb_otg_event(usb_type);
}

static TCPC_MUX_CTRL_TYPE _tca_mode_switch(TCPC_MUX_CTRL_TYPE mode_type, TCA_SW_MODE switch_mode, enum otg_dev_event_type usb_type)
{
	int cnt = 100;
	volatile unsigned int reg_data = 0x10;
	static int cur_mode_t = TCPC_NO_CONNECTION;

	if (mode_type == cur_mode_t) {
		pr_info("[%s][%d]is not changed\n", __func__, mode_type);
		return cur_mode_t;
	}
	writel(0xFFFF, SOC_USB31_TCA_TCA_INTR_STS_ADDR(pd_res.tca_base));
	/*set_bits(0x3, SOC_USB31_TCA_TCA_INTR_EN_ADDR(pd_res.tca_base));  for irq mode,but we use poll waitting */
	reg_data |= mode_type;
	writel_mask(0x1F,reg_data, SOC_USB31_TCA_TCA_TCPC_ADDR(pd_res.tca_base));
	pr_info("[%s]TCPC[0x%x]\n", __func__, readl(SOC_USB31_TCA_TCA_TCPC_ADDR(pd_res.tca_base)));

	if (TCA_FORCE_DP_DISABLE_ACK & switch_mode) {
		cnt = 100;
		if (TCPC_DP == cur_mode_t && TCPC_USB31_AND_DP_2LINE == mode_type) {
			while(is_bits_clr(BIT(1), pd_res.dp_ctrl_base +0xc08)) {
				if (--cnt < 0) {
					pr_err("force mode:TCA wait DP recv tca_disable timeout1\n");
					goto PD_FIN;
				}
			}
			set_bits(BIT(0), pd_res.dp_ctrl_base +0xc08);

			while(is_bits_set(BIT(1), pd_res.dp_ctrl_base +0xc08)) {
				if (--cnt < 0) {
					pr_err("force mode:TCA wait DP recv tca_disable timeout2\n");
					goto PD_FIN;
				}
			}

			clr_bits(BIT(0), pd_res.dp_ctrl_base +0xc08);

		}else if (TCPC_DP & cur_mode_t && TCPC_USB31_CONNECTED >= mode_type) {
			while(is_bits_clr(BIT(1), pd_res.dp_ctrl_base +0xc08)) {
				if (--cnt < 0) {
					pr_err("force mode:TCA wait DP recv tca_disable timeout3\n");
					goto PD_FIN;
				}
			}
			set_bits(BIT(0), pd_res.dp_ctrl_base +0xc08);
		}else if (TCPC_DP <= mode_type) {
			while(is_bits_set(BIT(1), pd_res.dp_ctrl_base +0xc08)) {
				if (--cnt < 0) {
					pr_err("force mode:TCA wait DP recv tca_disable timeout4\n");
					goto PD_FIN;
				}
			}
			clr_bits(BIT(0), pd_res.dp_ctrl_base +0xc08);
		}
	}

	cnt = 100;
	while(is_bits_clr(BIT(SOC_USB31_TCA_TCA_INTR_STS_xa_ack_evt_START),
		SOC_USB31_TCA_TCA_INTR_STS_ADDR(pd_res.tca_base))) {
		if (--cnt < 0) {
			pr_err("TCA wait ack timeout\n");
			goto PD_FIN;
		}
	}

	cur_mode_t = mode_type;

PD_FIN:
	pr_info("0x28:[%x]0x2c:[%x]0x30:[%x]0x34:[%x]0x08:[%x]\n",
		readl(0x28+pd_res.tca_base), readl(0x2c+pd_res.tca_base), readl(0x30+pd_res.tca_base),
		readl(0x34+pd_res.tca_base),readl(0x8+pd_res.tca_base));
	pr_info("[%s]USB0xc2c0[0x%x],DP0xc08[0x%x]\n", __func__,
			readl(pd_res.usb3otg_base + 0xc2c0),readl(pd_res.dp_ctrl_base +0xc08));

	return cur_mode_t;
}

TCPC_MUX_CTRL_TYPE tca_mode_switch(TCPC_MUX_CTRL_TYPE mode_type, TCA_SW_MODE switch_mode, enum otg_dev_event_type usb_type)
{
	int cur_mode_t = TCPC_NO_CONNECTION;

	pr_info("[%s]MODE[%d]FORCE[%d]USB[%d]\n", __func__, mode_type, switch_mode, usb_type);

	if (mode_type >= TCPC_MUX_MODE_MAX || usb_type >= NONE_EVENT || switch_mode >= TCA_SW_MAX)
		return 	TCPC_MUX_MODE_MAX;

	mutex_lock(&pd_sw_mutex);
	if(TCPC_DP == mode_type) {/*TCA does not support NC->DP4*/
		(void)_tca_mode_switch(TCPC_USB31_CONNECTED,switch_mode, NONE_EVENT);
		if (TCA_FORCE_USB_DISABLE_ACK  & switch_mode)
			set_bits(BIT(17), pd_res.usb3otg_base + 0xc2c0);
		set_bits(BIT(SOC_USB31_TCA_TCA_CTRLSYNCMODE_CFG0_block_ss_op_START),
			SOC_USB31_TCA_TCA_CTRLSYNCMODE_CFG0_ADDR(pd_res.tca_base));
	}
	cur_mode_t = _tca_mode_switch(mode_type, switch_mode, usb_type);
	if(TCPC_DP == mode_type) {
		clr_bits(BIT(SOC_USB31_TCA_TCA_CTRLSYNCMODE_CFG0_block_ss_op_START),
			SOC_USB31_TCA_TCA_CTRLSYNCMODE_CFG0_ADDR(pd_res.tca_base));
	}

	/*tca_notify_usb_dp_ctrl(cur_mode_t, usb_type);*/
	mutex_unlock(&pd_sw_mutex);
	return cur_mode_t;
}

static void usb_power_on_rst(void)
{
	if(is_bits_clr(BIT(20), SOC_SCTRL_SCDEEPSLEEPED_ADDR(pd_res.sctrl_reg_base))) {
		writel(BIT(SOC_CRGPERIPH_ISODIS_usb_refclk_iso_en_START),
			SOC_CRGPERIPH_ISODIS_ADDR(pd_res.pericfg_reg_base));
		writel(HM_EN(SOC_PCTRL_PERI_CTRL3_usb_tcxo_en_START),
			SOC_PCTRL_PERI_CTRL3_ADDR(pd_res.pctrl_reg_base));
	}

#ifdef SOC_CRGPERIPH_PEREN6_gt_clk_usb_pipe_trans_START
	writel(BIT(SOC_CRGPERIPH_PEREN6_gt_clk_usb_pipe_trans_START)|
		BIT(SOC_CRGPERIPH_PEREN6_gt_clk_usb2phy_ref_START),
		SOC_CRGPERIPH_PEREN6_ADDR(pd_res.pericfg_reg_base));
#endif
#ifdef SOC_CRGPERIPH_PEREN3_gt_clk_usb_pipe_trans_START
	writel(BIT(SOC_CRGPERIPH_PEREN6_gt_clk_usb2phy_ref_START),
		SOC_CRGPERIPH_PEREN6_ADDR(pd_res.pericfg_reg_base));
	writel(BIT(SOC_CRGPERIPH_PEREN3_gt_clk_usb_pipe_trans_START),
		SOC_CRGPERIPH_PEREN3_ADDR(pd_res.pericfg_reg_base));
#endif

	writel(BIT(SOC_CRGPERIPH_PEREN4_gt_aclk_usb3otg_START)|
		BIT(SOC_CRGPERIPH_PEREN4_gt_clk_usb3otg_ref_START),
		SOC_CRGPERIPH_PEREN4_ADDR(pd_res.pericfg_reg_base));

	writel(BIT(SOC_CRGPERIPH_PEREN0_gt_hclk_usb3otg_misc_START),
		SOC_CRGPERIPH_PEREN0_ADDR(pd_res.pericfg_reg_base));

	writel(BIT(SOC_CRGPERIPH_PERRSTDIS4_ip_rst_usb3otg_32k_START)|
		BIT(SOC_CRGPERIPH_PERRSTDIS4_ip_hrst_usb3otg_misc_START),
		SOC_CRGPERIPH_PERRSTDIS4_ADDR(pd_res.pericfg_reg_base));

	if(is_bits_clr(BIT(20), SOC_SCTRL_SCDEEPSLEEPED_ADDR(pd_res.sctrl_reg_base))) {
		set_bits(BIT(SOC_USB31_MISC_CTRL_USBOTG3_CTRL7_usb2_refclksel_START)|
			BIT(SOC_USB31_MISC_CTRL_USBOTG3_CTRL7_usb2_refclksel_END),
			SOC_USB31_MISC_CTRL_USBOTG3_CTRL7_ADDR(pd_res.usb3otg_bc_base));
	}
}

static void usb_init(void)
{
	/*usb init step1*/
	clr_bits(BIT(SOC_USB31_MISC_CTRL_USBOTG3_CTRL5_usb2_siddq_START),
			SOC_USB31_MISC_CTRL_USBOTG3_CTRL5_ADDR(pd_res.usb3otg_bc_base));
	clr_bits(BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFG50_usb3_phy_test_powerdown_START),
			SOC_USB31_MISC_CTRL_USB_MISC_CFG50_ADDR(pd_res.usb3otg_bc_base));
	set_bits(BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFG54_usb3_phy0_ana_pwr_en_START)|
		BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFG54_phy0_pcs_pwr_stable_START)|
		BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFG54_phy0_pma_pwr_stable_START),
			SOC_USB31_MISC_CTRL_USB_MISC_CFG54_ADDR(pd_res.usb3otg_bc_base));
	/*phy release*/
	set_bits(BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_usb31c_resetn_START)|
		BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_vaux_reset_n_START),
		SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_ADDR(pd_res.usb3otg_bc_base));
	udelay(2);
}

static void pd_combophy_init(void)
{
	int cnt = 50;
/*1	MMC0 POWER ON*/
/*2	open DP USB clk rst*/
	/*dpctrl clk rest*/
	writel(BIT(SOC_CRGPERIPH_PEREN5_gt_clk_mmc_dpctrl_START),
		SOC_CRGPERIPH_PEREN5_ADDR(pd_res.pericfg_reg_base));
	writel(BIT(SOC_CRGPERIPH_PEREN12_gt_pclk_dpctrl_START)|
		BIT(SOC_CRGPERIPH_PEREN12_gt_aclk_dpctrl_START)|
		BIT(SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_16m_START),
		SOC_CRGPERIPH_PEREN12_ADDR(pd_res.pericfg_reg_base));
	writel(BIT(SOC_CRGPERIPH_PERRSTEN0_ip_rst_dpctrl_START),
		SOC_CRGPERIPH_PERRSTDIS0_ADDR(pd_res.pericfg_reg_base));
	/*config usb ctrl to usb tca apb*/
	writel(BIT(SOC_CRGPERIPH_PEREN0_gt_hclk_usb3otg_misc_START),
		SOC_CRGPERIPH_PEREN0_ADDR(pd_res.pericfg_reg_base));
	writel(BIT(SOC_CRGPERIPH_PEREN4_gt_clk_usb3otg_ref_START)|
		BIT(SOC_CRGPERIPH_PEREN4_gt_aclk_usb3otg_START),
		SOC_CRGPERIPH_PEREN4_ADDR(pd_res.pericfg_reg_base));
	writel(BIT(SOC_CRGPERIPH_PERRSTDIS4_ip_rst_usb3otg_32k_START)|
		BIT(SOC_CRGPERIPH_PERRSTDIS4_ip_hrst_usb3otg_misc_START),
		SOC_CRGPERIPH_PERRSTDIS4_ADDR(pd_res.pericfg_reg_base));

/*3	usb init; config usb into suspend mode*/
	/*init usb*/
	usb_power_on_rst();
	usb_init();
	/*usb suspend*/
	set_bits(BIT(17), pd_res.usb3otg_base + 0xc2c0);
	writel((2 * 0x0927C), SOC_USB31_TCA_TCA_CTRLSYNCMODE_CFG1_ADDR(pd_res.tca_base));
/*4	open combo phy */
	writel(BIT(SOC_CRGPERIPH_ISODIS_usb_refclk_iso_en_START),
		SOC_CRGPERIPH_ISODIS_ADDR(pd_res.pericfg_reg_base));
	writel(HM_EN(SOC_PCTRL_PERI_CTRL3_usb_tcxo_en_START),
			SOC_PCTRL_PERI_CTRL3_ADDR(pd_res.pctrl_reg_base));
	udelay(160);

/*5	dp-->p3 mode*/
	set_bits(0xff<<17, pd_res.dp_ctrl_base + 0xa00);
/*6	unreset combo phy*/
	set_bits(BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_usb2phy_por_n_START)|
		BIT(SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_usb3phy_reset_n_START),
	SOC_USB31_MISC_CTRL_USB_MISC_CFGA0_ADDR(pd_res.usb3otg_bc_base));
/*7	make sure DP recv tca_disable*/
	while(is_bits_clr(BIT(1), pd_res.dp_ctrl_base +0xc08)) {/*BIT1-->0 DP can use*/
		if (--cnt < 0) {
			pr_err("[%s]wait DP recv tca_disable signal timeout\n", __func__);
			return;
		}
	}

	set_bits(BIT(0), pd_res.dp_ctrl_base +0xc08);
/*waiting TCA fin*/
	cnt = 50;
	writel(0x10, SOC_USB31_TCA_TCA_TCPC_ADDR(pd_res.tca_base));
	while(is_bits_clr(BIT(SOC_USB31_TCA_TCA_INTR_STS_xa_ack_evt_START)|
		BIT(SOC_USB31_TCA_TCA_INTR_STS_xa_timeout_evt_START),
		SOC_USB31_TCA_TCA_INTR_STS_ADDR(pd_res.tca_base))) {
		if (--cnt < 0) {
			pr_err("phy power on timeout\n");
			return;
		}
	}

	pr_info("[%s]set usb suspend[%x]\n", __func__, readl(pd_res.usb3otg_base + 0xc2c0));
	pr_info("[%s]TCA INTR[%x]\n", __func__, readl(SOC_USB31_TCA_TCA_INTR_STS_ADDR(pd_res.tca_base)));
	pr_info("[%x][%x][%x][%x][%x]\n", readl(0x28+pd_res.tca_base), readl(0x2c+pd_res.tca_base), readl(0x30+pd_res.tca_base),
		readl(0x34+pd_res.tca_base),readl(0x8+pd_res.tca_base));

	writel(BIT(SOC_USB31_TCA_TCA_INTR_STS_xa_ack_evt_START)|
		BIT(SOC_USB31_TCA_TCA_INTR_STS_xa_timeout_evt_START),
		SOC_USB31_TCA_TCA_INTR_STS_ADDR(pd_res.tca_base));
}

static int pd_iomcu_event_hander(const pkt_header_t *head)
{
	struct pd_ipc *msg;
	if (NULL == head) {
		pr_err("[%s]parm null\n", __func__);
		return -EINVAL;
	}

	mutex_lock(&pd_event_mutex);
	msg = (struct pd_ipc *)head;
	pr_info("[%s]type[%d]inout[%d]\n", __func__, msg->usb_or_dp, msg->in_or_out);
	/*tca_mode_switch(msg->usb_or_dp);*/
	if (1 == msg->usb_or_dp)
		hisi_dptx_hpd_trigger(!msg->in_or_out);
	else
		hisi_usb_otg_event(!!msg->in_or_out);

	mutex_unlock(&pd_event_mutex);
	return 0;
}

static int __init pd_probe(struct platform_device *pdev)
{
	int ret;
	struct device *dev = &pdev->dev;
	struct device_node *dev_node = dev->of_node;
	if (!of_device_is_available(dev_node))
		return -ENODEV;
	ret = pd_get_config_resource(&pd_res, dev_node);
	if (ret) {
		pr_err("[%s] pd_get_config_resource err\n", __func__);
		return -EINVAL;
	}

	pd_combophy_init();
	pd_res.init = PD_PLATFORM_INIT_OK;
	return ret;
}

static void pd_resouces_rel(void)
{
	iounmap(pd_res.dp_ctrl_base);
	iounmap(pd_res.usb3otg_base);
	iounmap(pd_res.usb3otg_bc_base);
	iounmap(pd_res.pctrl_reg_base);
	iounmap(pd_res.sctrl_reg_base);
	iounmap(pd_res.pericfg_reg_base);
}

static int pd_remove(struct platform_device *pdev)
{
	pd_resouces_rel();
	return 0;
}

static int __init iomcu_pd_init(void)
{
	if (PD_PLATFORM_INIT_OK == pd_res.init) {
		int ret = register_mcu_event_notifier(TAG_PD,
			CMD_PD_REQ, pd_iomcu_event_hander);
		if (ret) {
			pd_resouces_rel();
			pr_err("[%s] register_mcu_event_notifier err\n", __func__);
			return ret;
		}
	}

	return 0;
}

static void __exit iomcu_pd_exit(void)
{
	int ret;
	ret = unregister_mcu_event_notifier(TAG_PD,
		CMD_PD_REQ, pd_iomcu_event_hander);
	if (ret) {
		pr_err("[%s] unregister_mcu_event_notifier err\n", __func__);
	}
}

late_initcall_sync(iomcu_pd_init);
module_exit(iomcu_pd_exit);

static struct of_device_id hisi_pd_of_match[] = {
	{ .compatible = "hisilicon,pd"},
	{},
};

MODULE_DEVICE_TABLE(of, hisi_pd_of_match);

static int tca_pm_suspend(struct device *dev)
{
	pr_info("%s -s\n", __func__);
	pr_info("%s -e\n", __func__);
	return 0;
}

static int tca_pm_resume(struct device *dev)
{
	pr_info("%s -s\n", __func__);
	pd_combophy_init();
	pr_info("%s -e\n", __func__);
	return 0;
}

static struct dev_pm_ops tca_pm_ops = {
	.suspend = tca_pm_suspend,
	.resume = tca_pm_resume,
};

static struct platform_driver pd_platdrv = {
	.driver = {
		.name		= "hisi-pd",
		.owner		= THIS_MODULE,
		.of_match_table = hisi_pd_of_match,
		.pm = &tca_pm_ops,
	},
	.probe	= pd_probe,
	.remove	= pd_remove,
};
module_platform_driver(pd_platdrv);
MODULE_LICENSE("GPL");
