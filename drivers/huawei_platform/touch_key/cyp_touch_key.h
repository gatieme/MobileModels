

#ifndef _CYTTSP_BUTTON_H_
#define _CYTTSP_BUTTON_H_

#include <linux/types.h>

/* operate command list */
#define CYTTSP_CMD_VERIFY_CHKSUM		0x31
#define CYTTSP_CMD_GET_FLASH_SIZE		0x32
#define CYTTSP_CMD_GET_APP_STATUS     	0x33
#define CYTTSP_CMD_ERASE_ROW			0x34
#define CYTTSP_CMD_CLEAR_BUF			0x35
#define CYTTSP_CMD_SET_ACTIVE_APP      	0x36
#define CYTTSP_CMD_SEND_DATA			0x37
#define CYTTSP_CMD_ENTER_BTLD			0x38
#define CYTTSP_CMD_PROGRAM_ROW			0x39
#define CYTTSP_CMD_VERIFY_ROW			0x3A
#define CYTTSP_CMD_EXIT_BTLD			0x3B
#define CYTTSP_ENABLE_CAP_TEST			0x4E

/* register map list */
#define CYTTSP_DEFAULT_BL_ADDR			0x28
#define CYTTSP_REG_TOUCHMODE			0x00
#define CYTTSP_REG_WORKMODE				0x01
#define CYTTSP_REG_CAP_EN				0x1B
#define CYTTSP_REG_HWVERSION			0x48
#define CYTTSP_REG_INVALID				0xFF
#define CYTTSP_SILICON_VER1				0x40
#define CYTTSP_BTLD_VER1				0x44
#define CYTTSP_BTLD_VER2				0x45
#define CYTTSP_BUTTON_FW_VER1			0x46
#define CYTTSP_BUTTON_FW_VER2			0x47
#define CYTTSP_BTN0_CAP					0x5E
#define CYTTSP_BTN1_CAP					0x5F
#define CYTTSP_BTN0_RAW_START			0x66
#define CYTTSP_BTN1_RAW_START			0x68
#define CYTTSP_BTN0_RAW_CNT_START		0x4B
#define CYTTSP_BTN1_RAW_CNT_START		0x4D

/* mask value list */
#define CYTTSP_NORMAL_MODE				0x00
#define CYTTSP_DEEPSLEEP_MODE			0x01
#define CYTTSP_STS_SUCCESS				0x00
#define CYTTSP_BUTTON_OP_MODE			0x00
#define CYTTSP_PACKET_START				0x01
#define CYTTSP_PACKET_END				0x17
#define CYTTSP_MAX_PAYLOAD_LEN			0x15
#define CYTTSP_RESP_HEADER_LEN			0x04
#define CYTTSP_RESP_TAIL_LEN			0x03
#define CYTTSP_ENTER_BTLD_RESP_LEN		8
#define CYTTSP_GET_FLASHSZ_RESP_LEN		4
#define CYTTSP_8BITS_SHIFT				8
#define CYTTSP_16BITS_SHIFT				16
#define CYTTSP_8BITS_MASK				0xFF
#define CYTTSP_16BITS_MASK				0xFF00
#define CYTTSP_16BITS_FULL_MASK			0xFFFF

/* delay count list */
#define CYTTSP_WRITE_DELAY_COUNT		25
#define CYTTSP_WAKE_DELAY_COUNT 		100
#define CYTTSP_CAP_TEST_DELAY_COUNT		500
#define CYTTSP_FWUP_DELAY_COUNT 		1000

/* shift value list */
#define CYTTSP_GLOVE_MODE_SHIFT			2
#define CYTTSP_FW_VER_SIZE				2
#define CYTTSP_BTLD_VER_SIZE			2
#define CYTTSP_RAW_DATA_SIZE			2
#define CYTTSP_CAP_DATA_SIZE			2
#define CYTTSP_SILICON_VER_SIZE			4

/* magic number */
#define CYTTSP_PROGRAM_DATA_LEN			4
#define CYTTSP_AVAILABLE_DATA_LEN		70
#define CYTTSP_FW_ORG_DATA_LEN			512

#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif

#ifndef TURN_ON
#define TURN_ON 1
#endif
#ifndef TURN_OFF
#define TURN_OFF 0
#endif

#ifndef PROC_ON
#define PROC_ON 1
#endif
#ifndef PROC_OFF
#define PROC_OFF 0
#endif

#ifndef I2C_NAME_SIZE
#define I2C_NAME_SIZE	20
#endif
#ifndef CYTTSP_I2C_DEFAULT_ADDR
#define CYTTSP_I2C_DEFAULT_ADDR 0x27
#endif

#define CYP_TOUCH_KEY_COMPATIBLE_ID	"huawei,cyp_touch_key"
#define CYP_DEFAULT_VDD_VOL 3300000

struct cyttsp_config_info {
	unsigned char panel_id;
	const char* fw_info;
};

struct cyttsp_button_platform_data {
	int irq_gpio;
	unsigned int irq_num;
	unsigned int irq_gpio_flags;
	unsigned long irq_flags;
	unsigned int vdd;
	unsigned long long vdd_vol;
	const char *input_name;
	int nbuttons;
	int *key_code;
	unsigned char button_status_reg;
	unsigned char bl_addr;
	unsigned char work_mode_reg;
	int default_config;
	int config_array_size;
	struct cyttsp_config_info *config_array;
};

struct cyttsp_button_data {
	struct i2c_client *client;
	struct cyttsp_button_platform_data *pdata;
	struct input_dev *input_dev;
	bool dbg_dump;
	unsigned long key_status;
	bool enable;
	unsigned char bl_addr;
	unsigned char app_addr;
#ifdef CONFIG_FB
	struct notifier_block fb_notif;
#endif
	struct notifier_block glove_mode_notif;
	bool glove_mode;
	unsigned char fw_version[CYTTSP_FW_VER_SIZE];
};

int fw_update_flag;
bool in_bootloader;
struct i2c_client *this_client;

#endif
