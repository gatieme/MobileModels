

#ifndef __LCD_KIT_SCP_H_
#define __LCD_KIT_SCP_H_
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/types.h>

enum {
	PRIMARY_PANEL_SHORT_CIRCUIT_BIT = 16,
	SECONDARY_PANEL_SHORT_CIRCUIT_BIT = 17,
};

struct lcd_kit_scp_ops {
	int (*scp_check_start)(int panel_id, void *hld);
	int (*get_short_circuit_state)(int panel_id);
};

struct lcd_kit_scp_ops *lcd_kit_get_scp_ops(void);
int lcd_kit_scp_init(int panel_id, struct device_node *np);

#endif
