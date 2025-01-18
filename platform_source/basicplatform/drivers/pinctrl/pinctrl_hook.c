#include <linux/of.h>
#include <platform_include/basicplatform/linux/usb_phy_chip.h>
#ifdef CONFIG_PINCRTL_VIRTUAL
#include "pinctrl_vm.h"
#endif
#include <platform_include/basicplatform/linux/hck/pinctrl/hck_pinctrl.h>

static void hck_6502_dt_to_map(struct device_node *np_config, int *ret)
{
	*ret = 0;
#ifdef CONFIG_PINCTRL_HI6502
	extern unsigned int phy_type;

	if (strstr(np_config->name, "6502gpio") != NULL) {
		if (phy_type == HISI_USB_PHY_CHIP) {
			if (strstr(np_config->name, "t6502") != NULL) {
				pr_err("config  %s t28 need cacel DT\n",
					np_config->name);
				*ret = 1;
				return;
			}
		} else if (phy_type == SNOPSYS_USB_PHY_CHIP) {
			if (strstr(np_config->name, "s6502") != NULL) {
				pr_err("config  %s s28 need cancel DT\n",
					np_config->name);
				*ret = 1;
				return;
			}
		}
	}
#endif
}
#ifdef CONFIG_PINCRTL_VIRTUAL
static void hck_pinctrl_vm_set_mux(size_t reg, size_t val)
{
	pcs_mux_virt_set(reg, val);
}
#endif
static int hook_pinctrl_init(void)
{
	REGISTER_HCK_VH(hi6502_dt_to_map, hck_6502_dt_to_map);
#ifdef CONFIG_PINCRTL_VIRTUAL
	REGISTER_HCK_VH(pinctrl_vm_set_mux, hck_pinctrl_vm_set_mux);
#endif
	return 0;
}
early_initcall(hook_pinctrl_init);
