#include "pcie-kirin.h"
/*lint -e438 -e550 -e715 -e750 -esym(438,*) -esym(550,*) -esym(715,*) -esym(750,*) */

/* SYSCTRL register */
#define MTCMOS_CTRL_BIT    0x10
#define HW_AUTO_CF_BIT		((0x1 << 20) | (0x1 << 14))
#define IO_HARD_CTRL_DEBOUNCE_BYPASS (0x1 << 28)
#define IO_OE_EN_HARD_BYPASS (0x1 << 29)

#define SCTRL_SCPERCLKEN3	0x1a4
#define SCTRL_SCPWRDIS	0x64
#define SCTRL_SCPWREN	0x60
#define SCTRL_SCPEREN2	0x190
#define SCTRL_SCPERCLKDIS2	0x194

static void kirin_pcie_oe_ctrl(struct kirin_pcie *pcie, int en_flag)
{
	u32 val;

	val = readl(pcie->sctrl_base + SCTRL_SCPERCLKEN3);//lint !e732

	/* set phy_debounce in&out time: 300ns*/
	val |= 0xF0F000;

	/*select oe_gt_mode */
	val |= 0x400;

	/*IO bypass */
	val &= ~IO_HARD_CTRL_DEBOUNCE_BYPASS;

	if (en_flag)
		val &= ~IO_OE_EN_HARD_BYPASS;
	else
		val |= IO_OE_EN_HARD_BYPASS;

	writel(val, pcie->sctrl_base + SCTRL_SCPERCLKEN3);
}

static void kirin_pcie_iso_ctrl(struct kirin_pcie *pcie, int en_flag)
{
	if (en_flag)
		writel(pcie->dtsinfo.isoen_value, pcie->sctrl_base + pcie->dtsinfo.isoen_offset);
	else
		writel(pcie->dtsinfo.isodis_value, pcie->sctrl_base + pcie->dtsinfo.isodis_offset);
}

static void kirin_pcie_mtcmos_ctrl(struct kirin_pcie *pcie, int enable)
{
	if (enable)/* [false alarm]:fortify */
		writel(MTCMOS_CTRL_BIT, pcie->sctrl_base + SCTRL_SCPWREN);
	else
		writel(MTCMOS_CTRL_BIT, pcie->sctrl_base + SCTRL_SCPWRDIS);
}

static void kirin_pcie_reset_ctrl(struct kirin_pcie *pcie, int reset)
{
	u32 val;

	if (reset) {
		val = pcie->dtsinfo.core_assert_value | pcie->dtsinfo.phy_assert_value;
		writel(val, pcie->crg_base + pcie->dtsinfo.core_assert_offset);
	} else {
		val = pcie->dtsinfo.core_deassert_value | pcie->dtsinfo.phy_deassert_value;
		writel(val, pcie->crg_base + pcie->dtsinfo.core_deassert_offset);
	}
}

static int kirin_pcie_clk_ctrl(struct kirin_pcie *pcie, int clk_on)
{
	int ret = 0;
	unsigned long ref_clk_rate = REF_CLK_FREQ;

	if (clk_on) {
		ret = clk_set_rate(pcie->phy_ref_clk, ref_clk_rate);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to set ref clk rate 100MHz ");
			return ret;
		}

		ret = clk_prepare_enable(pcie->phy_ref_clk);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to enable phy_ref_clk ");
			return ret;
		}

		ret = clk_prepare_enable(pcie->apb_sys_clk);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to enable apb_sys_clk ");
			clk_disable_unprepare(pcie->phy_ref_clk);
			return ret;
		}

		ret = clk_prepare_enable(pcie->apb_phy_clk);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to enable apb_phy_clk ");
			clk_disable_unprepare(pcie->apb_sys_clk);
			clk_disable_unprepare(pcie->phy_ref_clk);
			return ret;
		}

		ret = clk_prepare_enable(pcie->pcie_aclk);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to enable pcie_aclk ");
			clk_disable_unprepare(pcie->apb_phy_clk);
			clk_disable_unprepare(pcie->phy_ref_clk);
			clk_disable_unprepare(pcie->apb_sys_clk);
			return ret;
		}

		ret = clk_prepare_enable(pcie->pcie_aux_clk);
		if (0 != ret) {
			PCIE_PR_ERR("Failed to enable pcie_pclk ");
			clk_disable_unprepare(pcie->pcie_aclk);
			clk_disable_unprepare(pcie->apb_phy_clk);
			clk_disable_unprepare(pcie->phy_ref_clk);
			clk_disable_unprepare(pcie->apb_sys_clk);
			return ret;
		}
	} else {
		clk_disable_unprepare(pcie->apb_sys_clk);
		clk_disable_unprepare(pcie->apb_phy_clk);
		clk_disable_unprepare(pcie->pcie_aclk);
		clk_disable_unprepare(pcie->phy_ref_clk);
		clk_disable_unprepare(pcie->pcie_aux_clk);
	}

	return ret;
}

static int kirin_pcie_phy_init(struct kirin_pcie *pcie);

int kirin_pcie_power_on(struct pcie_port *pp, enum rc_power_status on_flag)
{
	struct kirin_pcie *pcie = to_kirin_pcie(pp);//lint !e826
	int ret;
	struct kirin_pcie_dtsinfo *dtsinfo;

	PCIE_PR_DEBUG("++");

	dtsinfo = &pcie->dtsinfo;

	/*power on*/
	if (on_flag == RC_POWER_ON || on_flag == RC_POWER_RESUME) {
		PCIE_PR_DEBUG("ON");

		if (pcie->is_power_on) {
			PCIE_PR_INFO("PCIe%d already power on", pcie->rc_id);
			return 0;
		}

		if (on_flag == RC_POWER_ON) {
			kirin_pcie_mtcmos_ctrl(pcie, ENABLE);
			udelay((unsigned long)100);//lint !e778  !e774  !e516
			PCIE_PR_DEBUG("mtcmos on Done ");
		}

		if (dtsinfo->board_type == BOARD_ASIC) {
			kirin_pcie_oe_ctrl(pcie, ENABLE);
			PCIE_PR_DEBUG("OE CFG Done ");
		}
			/*clk enable*/
		ret = kirin_pcie_clk_ctrl(pcie, ENABLE);
		udelay((unsigned long)1);//lint !e778  !e774  !e516
		if (ret)
			return -EINVAL;
		PCIE_PR_DEBUG("clock on Done ");

		/*clk disable*/
		ret = kirin_pcie_clk_ctrl(pcie, DISABLE);
		if (ret)
			return -EINVAL;
		udelay((unsigned long)1);//lint !e778  !e774  !e516
		PCIE_PR_DEBUG("clk off Done ");

		/*ISO disable*/
		if (on_flag == RC_POWER_ON) {
			kirin_pcie_iso_ctrl(pcie, DISABLE);
			PCIE_PR_DEBUG("iso disable Done ");
		}

		/*unset module*/
		kirin_pcie_reset_ctrl(pcie, DISABLE);
		PCIE_PR_DEBUG("module unreset Done ");

		/*clk on*/
		ret = kirin_pcie_clk_ctrl(pcie, ENABLE);
		if (ret)
			return -EINVAL;
		PCIE_PR_DEBUG("clk on Done ");

		/*Enable 100MHz gate*/
		if (dtsinfo->board_type == BOARD_ASIC) {
			writel(HW_AUTO_CF_BIT, pcie->sctrl_base + SCTRL_SCPEREN2);
			ret = kirin_pcie_phy_init(pcie);
			if (ret) {
				PCIE_PR_ERR("Phy Init Failed ");
				return ret;
			}
			PCIE_PR_DEBUG("Phy Init Done ");
		}

		pcie->is_power_on = 1;

		mdelay((unsigned long)22);//lint !e778  !e774  !e516  !e747  !e845
		if (gpio_direction_output((unsigned int)pcie->gpio_id_reset, 1)) {
			PCIE_PR_ERR("perst deassert fail");
			return -1;
		}

		mdelay((unsigned long)7);//lint !e778  !e774  !e516  !e747  !e845
	} else if(on_flag == RC_POWER_OFF || on_flag == RC_POWER_SUSPEND) {
		PCIE_PR_DEBUG("OFF");

		if (!pcie->is_power_on) {
			PCIE_PR_INFO("PCIe%d already power off", pcie->rc_id);
			return 0;
		}

		/*perst assert*/
		if (gpio_direction_output((unsigned int)pcie->gpio_id_reset, 0)) {
			PCIE_PR_ERR("perst assert fail");
			return -1;
		}
		mdelay((unsigned long)10);//lint !e778  !e774  !e516  !e747  !e845

		kirin_pcie_reset_ctrl(pcie, ENABLE);

		ret = kirin_pcie_clk_ctrl(pcie, DISABLE);
		if (ret)
			return -EINVAL;

		if (on_flag == RC_POWER_OFF) {
			kirin_pcie_iso_ctrl(pcie, ENABLE);
			kirin_pcie_mtcmos_ctrl(pcie, DISABLE);
		}

		if (dtsinfo->board_type == BOARD_ASIC) {
			kirin_pcie_oe_ctrl(pcie, DISABLE);
			PCIE_PR_DEBUG("OE CFG Done ");

			/*Close 100MHz Gate*/
			writel(HW_AUTO_CF_BIT, pcie->sctrl_base + SCTRL_SCPERCLKDIS2);
		}

		pcie->is_power_on = 0;

	} else {
		PCIE_PR_ERR("Invalid Param");
		return -1;
	}

	PCIE_PR_DEBUG("--");

	return 0;
}

static void set_phy_eye_param(struct kirin_pcie *pcie)
{
	u32 eye_param;
	struct kirin_pcie_dtsinfo *dtsinfo;

	dtsinfo = &pcie->dtsinfo;

	if (dtsinfo->pcie_eye_param_ctrl2)
		kirin_phy_writel(pcie, dtsinfo->pcie_eye_param_ctrl2, SOC_PCIEPHY_CTRL2_ADDR);

	if (dtsinfo->pcie_eye_param_ctrl3)
		kirin_phy_writel(pcie, dtsinfo->pcie_eye_param_ctrl3, SOC_PCIEPHY_CTRL3_ADDR);

	eye_param = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL2_ADDR);
	PCIE_PR_INFO("pcie_eye_param_ctrl2 is 0x%x", eye_param);
	eye_param = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL3_ADDR);
	PCIE_PR_INFO("pcie_eye_param_ctrl3 is 0x%x", eye_param);
}

static int kirin_pcie_phy_init(struct kirin_pcie *pcie)
{
	u32 reg_val;
	u32 pipe_clk_stable = 0x1 << 19;
	u32 time = 10;

	set_phy_eye_param(pcie);

	/*choose 100MHz clk src: Bit[8]==1 pll, Bit[8]==0 Board */
	reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL1_ADDR);
	reg_val &= ~(0x1 << 8);
	kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL1_ADDR);

	/*pull down phy_test_powerdown signal */
	reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL0_ADDR);
	reg_val &= ~(0x1 << 22);
	kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL0_ADDR);
	udelay((unsigned long)10);//lint !e778  !e774  !e516

	/*derst PHY */
	reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL1_ADDR);
	reg_val &= ~(0x1 << 16);
	kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL1_ADDR);


	reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE0_ADDR);
	while (reg_val & pipe_clk_stable) {
		udelay((unsigned long)100);//lint !e778  !e774  !e516
		if (time == 0) {
			PCIE_PR_INFO("PIPE clk is not stable");
			return -EINVAL;
		}
		time--;
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE0_ADDR);
	}

	return 0;
}
/*lint -e438 -e550 -e715 -e750 +esym(438,*) +esym(550,*) +esym(715,*) +esym(750,*) */

