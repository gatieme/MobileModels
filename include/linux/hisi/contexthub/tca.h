#ifndef __LINUX_USB31_TCA_H__
#define __LINUX_USB31_TCA_H__
#include <linux/hisi/usb/hisi_usb.h>
typedef enum {
	TCPC_NO_CONNECTION = 0,
	TCPC_USB31_CONNECTED = 1,
	TCPC_DP = 2,
	TCPC_USB31_AND_DP_2LINE = 3,
	TCPC_MUX_MODE_MAX
}TCPC_MUX_CTRL_TYPE;

typedef enum {
	TCA_SWITCH_REQUEST = 0,
	TCA_FORCE_USB_DISABLE_ACK = 1,
	TCA_FORCE_DP_DISABLE_ACK = 2,
	TCA_FORCE_USB_DP_DISABLE_ACK = 3,
	TCA_SW_MAX
}TCA_SW_MODE;


extern TCPC_MUX_CTRL_TYPE tca_mode_switch(TCPC_MUX_CTRL_TYPE mode_type, TCA_SW_MODE switch_mode, enum otg_dev_event_type usb_type);

#endif 
