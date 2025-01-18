

#ifndef __PRIV_NFC_DRIVER_H__
#define __PRIV_NFC_DRIVER_H__

#define MAX_SEND_DATA_LEN 258 // �û��������ݵ���󳤶�
#define MAX_RECV_DATA_LEN 258 // �û��������ݵ���󳤶�
#define NCI_HEAD_LEN 3
#define NCI_PAYLOAD_LEN_INDEX 2

enum return_type_enum {
	NFC_SUCC = 0,
	NFC_EFAIL,
};

struct download_file_head {
	char start;
	char type;
	short len;
};

int nfc_driver_init(void *param);
void nfc_driver_deinit(void);

void nfc_wakeup_host_gpio_isr(void); // ���ϲ��ʼ��ʱ��ע��
void nfc_host_wkup_dev(void);
int nfc_i2c_write(char *buf, int count);
int nfc_i2c_read(char *buf, int count, unsigned long timeout);
int nfc_i2c_nci_read(char *buf, int buf_len, unsigned long timeout);
int nfc_chip_power_on(void);
int nci_format_check(unsigned char *buf, int count);

// �ϲ�ҵ��ע��device�����¼��ص�������ΪNULLΪ��ע��
void nfc_register_wakeup_host_callback(void (*cb)(void));

#endif
