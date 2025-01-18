

#ifndef __BOARD_NFC_H__
#define __BOARD_NFC_H__

enum NFC_CHIPTYPE {
	NFCTYPE_INVALID = 0,
	NFCTYPE_CA01    = 0x7,
	NFCTYPE_CA11    = 0x8
};

enum {
	BOARD_SUCC = 0,
	BOARD_FAIL = (-1)
};

typedef enum {
	NFC_DISABLE = 0,
	NFC_ENABLE  = 1
} nfc_enable_ctrl_t;

// �弶��ʼ��
int board_init(void *param);
void board_deinit(void);

// ҵ��ӿ�
void board_pwn_ctrl(nfc_enable_ctrl_t enable);               // ����device���µ�
void board_wkup_host_gpio_int_enable(nfc_enable_ctrl_t en);  // device����host��gpio�ж�ʹ�ܺͳ���
int board_get_dev_wkup_host_status(void);                    // ��ȡdevice����host��gpio��ƽ״̬
int board_get_host_wkup_dev_status(void);                    // ��ȡhost����device��gpio��ƽ״̬
void board_set_host_wkup_dev_value(int value);               // ����host����device��gpio��ƽ״̬
const char *board_get_fw_cfg_path(void);                     // ��ȡ�̼������ļ��Ĵ��·��
int board_i2c_write(char *buf, int count);                   // i2c_write�弶�ӿ�
int board_i2c_read(char *buf, int count);                    // i2c_reade�弶�ӿ�

#ifdef PLATFORM_DEBUG_ENABLE
// SSI��ؽӿ�
int board_get_ssi_data_gpio_value(void);
void board_set_ssi_data_gpio_value(int value);
void board_set_ssi_clk_gpio_value(int value);
void board_ssi_gpio_init(void);
void board_ssi_gpio_restore(void);
#endif

#endif
