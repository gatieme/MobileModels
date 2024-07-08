

#include <linux/init.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/debugfs.h>
#include <linux/of.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>
#include <linux/firmware.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/pm_runtime.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <huawei_platform/log/hw_log.h>
#include <media/huawei/hw_extern_pmic.h>
#include "cyp_touch_key.h"
#ifdef CONFIG_FB
#include <linux/notifier.h>
#include <linux/fb.h>
#endif

#define HWLOG_TAG cyp_key

HWLOG_REGIST();

int fw_update_flag;
bool in_bootloader;
struct i2c_client *this_client;

static int cyttsp_i2c_read_block(struct device *dev, unsigned char addr,
				unsigned char len, void *data)
{
	unsigned char this_addr = addr;
	int ret = 0;
	struct i2c_client *client = to_i2c_client(dev);

	ret = i2c_master_send(client, &this_addr, 1);
	if (ret != 1) {
		hwlog_err("%s-%d: failed to read block!\n", __func__, __LINE__);
		return -EIO;
	}

	ret = i2c_master_recv(client, data, len);

	return (ret < 0) ? ret : ret != len ? -EIO : 0;
}

static unsigned char cyttsp_read_reg(struct cyttsp_button_data *data, unsigned char reg)
{
	unsigned char val = 0;
	int ret = 0;

	ret = cyttsp_i2c_read_block(&data->client->dev,
				reg, 1, &val);
	if (ret < 0) {
		hwlog_err("%s-%d: failed to read reg!\n", __func__, __LINE__);
		return ret;
	}

	return val;
}

static int cyttsp_write_reg(struct cyttsp_button_data *data,
				unsigned char reg, unsigned char val)
{
	int ret = 0;
	unsigned char buffer[2] = {0};
	struct device *dev = &data->client->dev;
	struct i2c_client *client = to_i2c_client(dev);

	buffer[0] = reg;
	buffer[1] = val;

	ret = i2c_master_send(client, buffer, (int)sizeof(buffer));
	if (ret != sizeof(buffer)) {
		hwlog_err("%s-%d: failed to write reg!\n", __func__, __LINE__);
		return ret;
	}
	return 0;
}

static int cyttsp_i2c_recv(struct device *dev, unsigned char len, void *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int count = i2c_master_recv(client, buf, len);

	return count < 0 ? count : 0;
}

static int cyttsp_i2c_send(struct device *dev, unsigned char len, const void *buf)
{
	struct i2c_client *client = to_i2c_client(dev);
	int count = i2c_master_send(client, buf, len);

	return count < 0 ? count : 0;
}

static int cyttsp_get_single_line(const unsigned char *src, unsigned char *dst)
{
	int i = 0;

	while (src[i++] != '\n');

	strncpy(dst, src, (i - 1));

	return i;
}

static unsigned char cyttsp_convert(unsigned char c)
{
	if (c >= '0' && c <= '9') {
		return c - '0';
	}

	if (c >= 'a' && c <= 'f') {
		return c - 'a' + 10;
	}

	if (c >= 'A' && c <= 'F') {
		return c - 'A' + 10;
	}

	return 0;
}

static unsigned char cyttsp_convert_to_u8(unsigned char *buf)
{
	unsigned char msb = cyttsp_convert(buf[0]);
	unsigned char lsb = cyttsp_convert(buf[1]);
	unsigned char ret = msb;

	ret = ret * CYTTSP_16BITS_SHIFT + lsb;
	return ret;
}

static unsigned short cyttsp_convert_to_u16(unsigned char *buf)
{
	unsigned char msb = cyttsp_convert_to_u8(buf);
	unsigned char lsb = cyttsp_convert_to_u8(buf + 2);
	unsigned short ret = msb;

	ret = (ret << CYTTSP_16BITS_SHIFT) | lsb;
	return ret;
}

static unsigned char calculate_checksum8(unsigned char *src, int len)
{
	unsigned char total = 0;
	int i;

	for (i = 0; i < len; i++) {
		total += src[i];
	}
	total = 256 - total;

	return total;
}

static unsigned short cyttsp_checksum16(unsigned char *data, int len)
{
	unsigned short total = 0;
	int i;

	for (i = 0; i < len; i++) {
		total += data[i];
	}
	total = CYTTSP_16BITS_FULL_MASK - total;

	return (unsigned short)(total & CYTTSP_16BITS_FULL_MASK);
}

static int cyttsp_handle_response(struct cyttsp_button_data *data,
				unsigned char cmd, unsigned char *buffer, int resp_len, unsigned char other)
{
	if (cmd == CYTTSP_CMD_ENTER_BTLD) {
		if (resp_len < CYTTSP_ENTER_BTLD_RESP_LEN) {
			hwlog_warn("%s: response length mismatch for enter bootloader\n", __func__);
		}
		hwlog_info("%s: silicon id = 0x%02x 0x%02x 0x%02x 0x%02x, "
			"rev = 0x%02x, bootloader ver = 0x%02x 0x%02x 0x%02x\n", __func__,
			buffer[0], buffer[1], buffer[2], buffer[3],
			buffer[4], buffer[5], buffer[6], buffer[7]);
	} else if (cmd == CYTTSP_CMD_GET_FLASH_SIZE) {
		if (resp_len < CYTTSP_GET_FLASHSZ_RESP_LEN) {
			hwlog_warn("%s: response length mismatch for get flash size\n", __func__);
		}
		hwlog_info("%s: first row number of flash: 0x%02x 0x%02x\n", __func__,
			buffer[0], buffer[1]);
		hwlog_info("%s: last row number of flash: 0x%02x 0x%02x\n", __func__,
			buffer[2], buffer[3]);
	} else if (cmd == CYTTSP_CMD_VERIFY_ROW) {
		if (other != buffer[0]) {
			hwlog_err("%s: row_checksum = 0x%02x, received = 0x%02x\n", __func__,
				other, buffer[4]);
			return -EINVAL;
		}
	}

	return 0;
}

static int cyttsp_recv_command(struct cyttsp_button_data *data,
				unsigned char *error_code, unsigned char *payload, int *data_len)
{
	struct device *dev = &data->client->dev;
	unsigned char buffer[CYTTSP_FW_ORG_DATA_LEN];
	int remain_len;
	int len;
	int ret;
	int offset;
	int i = 0, k = 0;
	unsigned char *curr = payload;
	unsigned short cal_checksum;
	unsigned short buffer_u16;

	while (1) {
		ret = cyttsp_i2c_recv(dev, 1, buffer);
		if (ret != 0) {
			hwlog_err("%s: failed to read buffer\n", __func__);
			return ret;
		}
		if (CYTTSP_PACKET_START == buffer[0]) {
			break;
		}
	}

	ret = cyttsp_i2c_recv(dev, CYTTSP_RESP_HEADER_LEN - 1, &buffer[1]);
	if (ret != 0) {
		hwlog_err("%s: failed to read response header\n", __func__);
		return ret;
	}
	if (buffer[1] != CYTTSP_STS_SUCCESS) {
		*error_code = buffer[1];
		return -EINVAL;
	}
	remain_len = buffer[2] | (buffer[3] << CYTTSP_8BITS_SHIFT);
	*data_len = remain_len;
	offset = 4;

	while (remain_len > 0) {
		if (remain_len > CYTTSP_MAX_PAYLOAD_LEN) {
			len = CYTTSP_MAX_PAYLOAD_LEN;
		} else {
			len = remain_len;
		}

		ret = cyttsp_i2c_recv(dev, len, &buffer[offset]);
		if (ret != 0) {
			hwlog_err("failed to receive response at %d\n", i);
			return ret;
		}
		memcpy(curr, &buffer[offset], len);
		offset += len;
		curr += len;
		remain_len -= len;
		i++;
	}
	cal_checksum = cyttsp_checksum16(&buffer[1], 3 + (*data_len));
	ret = cyttsp_i2c_recv(dev, CYTTSP_RESP_TAIL_LEN, &buffer[offset]);
	if (ret != 0) {
		hwlog_err("%s: failed to receive tail\n", __func__);
		return ret;
	}
	buffer_u16 = buffer[offset+1] << CYTTSP_8BITS_SHIFT;
	if (cal_checksum != (buffer_u16 | buffer[offset])) {
		hwlog_err("%s: checksum not equal\n", __func__);
		return ret;
	}
	if (buffer[offset+2] != CYTTSP_PACKET_END) {
		hwlog_err("%s: Invalid packet tail\n", __func__);
		return -EINVAL;
	}
	if (data->dbg_dump) {
		hwlog_info("recv buffer = ");
		for (k = 0; k < *data_len + CYTTSP_RESP_HEADER_LEN + CYTTSP_RESP_TAIL_LEN; k++) {
			hwlog_info("0x%02x ", buffer[k]);
		}
		hwlog_info("\n");
	}
	return 0;
}

static int cyttsp_send_command(struct cyttsp_button_data *data,
				unsigned char cmd, unsigned char *payload, int data_len, unsigned char other)
{
	int i = 0;
	int k = 0;
	int len = 0;
	int ret = 0;
	int resp_len = 0;
	unsigned char buffer[512];
	unsigned char resp[50];
	unsigned char error_code = 0;
	unsigned short checksum;
	unsigned char *curr_buf = payload;
	struct device *dev = &data->client->dev;

	buffer[0] = CYTTSP_PACKET_START;
	buffer[1] = cmd;

	do {
		i = 0;

		if (data_len > CYTTSP_MAX_PAYLOAD_LEN) {
			len = CYTTSP_MAX_PAYLOAD_LEN;
		} else {
			len = data_len;
		}

		buffer[2] = (unsigned char)(len & CYTTSP_8BITS_MASK);
		buffer[3] = (unsigned char)((len & CYTTSP_16BITS_MASK) >> CYTTSP_8BITS_SHIFT);

		data_len -= len;
		if (len != 0) {
			memcpy(&buffer[4], curr_buf, len);
		}
		i = 4 + len;

		checksum = cyttsp_checksum16(buffer+1, len+3);
		curr_buf += len;

		buffer[i++] = (unsigned char)(checksum & CYTTSP_8BITS_MASK);
		buffer[i++] = (unsigned char)((checksum & CYTTSP_16BITS_MASK) >> CYTTSP_8BITS_SHIFT);
		buffer[i++] = CYTTSP_PACKET_END;

		ret = cyttsp_i2c_send(dev, i, buffer);
		if (ret != 0) {
			hwlog_err("%s: failed to send cmd 0x%02x\n", __func__, cmd);
			return ret;
		}

		mdelay(CYTTSP_WRITE_DELAY_COUNT);

		if (cmd != CYTTSP_CMD_EXIT_BTLD) {
			error_code = 0;
			resp_len = 0;
			ret = cyttsp_recv_command(data, &error_code, resp, &resp_len);
			if (ret) {
				hwlog_err("%s: response error code = 0x%02x\n",
					__func__, error_code);
				return ret;
			}
			ret = cyttsp_handle_response(data, cmd, resp, resp_len, other);
			if (ret) {
				hwlog_err("%s: response error for cmd 0x%x\n", __func__, cmd);
				return ret;
			}
		}

		if (data->dbg_dump) {
			hwlog_info("send buffer = ");
			for (k = 0; k < i; k++) {
				hwlog_info("0x%x ", buffer[k]);
			}
			hwlog_info("\n");
		}
	} while (data_len > 0);

	return 0;
}

static void cyttsp_button_print_dt(struct device *dev,
			struct cyttsp_button_platform_data *pdata)
{
	hwlog_info("%s: irq gpio = %d\n", __func__, pdata->irq_gpio);
	hwlog_info("%s: irq_flags = %d\n", __func__, (int)pdata->irq_flags);
	hwlog_info("%s: input name = %s\n", __func__, pdata->input_name);
	hwlog_info("%s: button number = %d\n", __func__, pdata->nbuttons);
	hwlog_info("%s: button_status_reg = 0x%02x\n", __func__, pdata->button_status_reg);
	hwlog_info("%s: work_mode_reg = 0x%02x\n", __func__, pdata->work_mode_reg);
	hwlog_info("%s: bootloader_addr = 0x%02x\n", __func__, pdata->bl_addr);
}

static int cyttsp_button_parse_dt(struct device *dev,
			struct cyttsp_button_platform_data *pdata)
{
	int ret = 0;
	unsigned int temp_val = 0;
	unsigned long long vdd_temp = 0;
	struct device_node *np = dev->of_node;

	/* irq gpio */
	pdata->irq_gpio = of_get_named_gpio_flags(np, "cyttsp,irq-gpio",
				0, &pdata->irq_gpio_flags);
	pdata->irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT | IRQF_NO_SUSPEND;

	/* vdd chanel num */
	ret = of_property_read_u32(np, "cyttsp,extern_vdd_supply", &temp_val);
	if (ret) {
		hwlog_err("%s: unable to read vdd supply\n", __func__);
	} else {
		pdata->vdd = temp_val;
		hwlog_info("%s: vdd chanel is %d\n", __func__, pdata->vdd);
	}

	/* voltage of vdd */
	ret = of_property_read_u64(np, "cyttsp,extern_vdd_vol", &vdd_temp);
	if (ret) {
		pdata->vdd_vol = CYP_DEFAULT_VDD_VOL;
		hwlog_err("%s: unable to read vdd supply, set default value: %ld\n",
			__func__, (unsigned long)pdata->vdd_vol);
	} else {
		pdata->vdd_vol = vdd_temp;
		hwlog_info("%s: pdata->vdd_vol = %ld\n", __func__, (unsigned long)pdata->vdd_vol);
	}

	/* charactors for input_dev */
	ret = of_property_read_string(np, "cyttsp,input-name",
			&pdata->input_name);
	if (ret && (ret != -EINVAL)) {
		hwlog_err("%s: unable to read input name\n", __func__);
		return ret;
	}

	/* addr of button status register */
	ret = of_property_read_u32(np, "cyttsp,button-status-reg",
			&temp_val);
	if (ret) {
		hwlog_err("%s: unable to read fw button-status-reg\n", __func__);
		return ret;
	} else {
		pdata->button_status_reg = (unsigned char)temp_val;
	}

	/* addr of work mode register */
	ret = of_property_read_u32(np, "cyttsp,work-mode-reg",
			&temp_val);
	if (ret) {
		hwlog_err("%s: unable to read work mode reg\n", __func__);
		return ret;
	} else {
		pdata->work_mode_reg = (unsigned char)temp_val;
	}

	/* numbers of key */
	ret = of_property_read_u32(np, "cyttsp,key-num", &temp_val);
	if (ret) {
		hwlog_err("%s: unable to read key num\n", __func__);
		return ret;
	} else {
		pdata->nbuttons = temp_val;
	}

	if (pdata->nbuttons != 0) {
		pdata->key_code = devm_kzalloc(dev, sizeof(int) * pdata->nbuttons, GFP_KERNEL);
		if (!pdata->key_code) {
			return -ENOMEM;
		}
		ret = of_property_read_u32_array(np, "cyttsp,key-codes",
						pdata->key_code, pdata->nbuttons);
		if (ret) {
			hwlog_err("%s: unable to read key codes\n", __func__);
			return ret;
		}
	}

	ret = of_property_read_u32(np, "cyttsp,bootloader-addr", &temp_val);
	if (ret) {
		pdata->bl_addr = CYTTSP_DEFAULT_BL_ADDR;
		hwlog_err("%s: unable to read btld address, set default addr: 0x%02x\n",
			__func__, pdata->bl_addr);
	} else {
		pdata->bl_addr = (unsigned char)temp_val;
	}

	cyttsp_button_print_dt(dev, pdata);

	return 0;
}

static int cyttsp_button_power_on(struct input_dev *in_dev)
{
	int ret = 0;
	struct cyttsp_button_data *data = input_get_drvdata(in_dev);
	struct cyttsp_button_platform_data *pdata = data->pdata;

	if (pdata->vdd) {
		ret = hw_extern_pmic_config(pdata->vdd,  pdata->vdd_vol, TURN_ON);
		if (ret < 0) {
			hwlog_err("%s: failed to enable regulator vdd\n", __func__);
		}
	}
	return 0;
}

static int cyttsp_button_power_off(struct input_dev *in_dev)
{
	int ret = 0;
	struct cyttsp_button_data *data = input_get_drvdata(in_dev);
	struct cyttsp_button_platform_data *pdata = data->pdata;

	if (pdata->vdd) {
		ret = hw_extern_pmic_config(pdata->vdd,  pdata->vdd_vol, TURN_OFF);
		if (ret < 0) {
			hwlog_err("%s: Failed to disable regulator vdd\n", __func__);
		}
	}
	return 0;
}

static int cyttsp_button_input_enable(struct input_dev *in_dev)
{
	int ret = 0;
	struct cyttsp_button_data *data = input_get_drvdata(in_dev);
	struct cyttsp_button_platform_data *pdata = data->pdata;

	if (true == data->enable) {
		hwlog_err("%s: button power on already\n", __func__);
		return 0;
	}

	if (pdata->work_mode_reg != CYTTSP_REG_INVALID) {
		ret = cyttsp_write_reg(data, pdata->work_mode_reg, CYTTSP_NORMAL_MODE);
		if (ret) {
			hwlog_err("%s: fail to enter normal mode\n",
				__func__);
			return ret;
		} else {
			hwlog_info("%s: enter normal mode\n", __func__);
		}
	}
	data->enable = true;
	enable_irq(data->client->irq);

	return 0;
}

static int cyttsp_button_input_disable(struct input_dev *in_dev)
{
	int ret = 0;
	struct cyttsp_button_data *data = input_get_drvdata(in_dev);
	struct cyttsp_button_platform_data *pdata = data->pdata;

	if (false == data->enable) {
		hwlog_err("%s: button power off already\n", __func__);
		return 0;
	}
	disable_irq(data->client->irq);

	if (pdata->work_mode_reg != CYTTSP_REG_INVALID) {
		ret = cyttsp_write_reg(data, pdata->work_mode_reg, CYTTSP_DEEPSLEEP_MODE);
		if (ret) {
			hwlog_err("%s: fail to enter deep sleep mode\n", __func__);
			return ret;
		} else {
			hwlog_info("%s: enter deep sleep mode\n", __func__);
		}
	}
	data->enable = false;

	return 0;
}

#ifdef CONFIG_FB
static int fb_notifier_callback(struct notifier_block *self,
		unsigned long event, void *data)
{
	int *blank;
	int ret = 0;
	struct fb_event *evdata = data;
	struct cyttsp_button_data *cyp_data =
		container_of(self, struct cyttsp_button_data, fb_notif);

	if (PROC_ON == fw_update_flag) {
		cyp_data->enable = true;
		hwlog_debug("%s: fw updating, block callback\n", __func__);
		return -EBUSY;
	} else {
		if (evdata && evdata->data &&
				(FB_EVENT_BLANK == event) && cyp_data) {
			blank = evdata->data;
			if (FB_BLANK_UNBLANK == *blank) {
				hwlog_info("%s: --=UNBLANK SCREEN FOR CYTTSP=--\n", __func__);
				ret = cyttsp_button_input_enable(cyp_data->input_dev);
				if (ret) {
					hwlog_err("%s-%d: fail to enable button\n", __func__,
						__LINE__);
				}
			} else if (FB_BLANK_POWERDOWN == *blank) {
				hwlog_info("%s: --=BLANK SCREEN FOR CYTTSP=--\n", __func__);
				ret = cyttsp_button_input_disable(cyp_data->input_dev);
				if (ret) {
					hwlog_err("%s-%d: fail to disable button\n", __func__,
						__LINE__);
				}
			}
		}
	}
	return 0;
}
#endif

static irqreturn_t cyttsp_button_interrupt_handler(int irq, void *dev_id)
{
	bool curr_state = 0;
	bool new_state = 0;
	bool sync = false;
	unsigned char val = 0;
	unsigned char key = 0;
	unsigned long key_states = 0;
	struct cyttsp_button_data *data = dev_id;
	struct cyttsp_button_platform_data *pdata = data->pdata;

	mutex_lock(&data->input_dev->mutex);
	if (data->enable) {
		val = cyttsp_read_reg(data, CYTTSP_REG_TOUCHMODE);
		if (val < 0) {
			hwlog_err("%s: fail to read touch mode reg\n", __func__);
			mutex_unlock(&data->input_dev->mutex);
			return IRQ_NONE;
		} else {
			data->glove_mode = !!(val & (1 << CYTTSP_GLOVE_MODE_SHIFT));
		}

		val = cyttsp_read_reg(data, pdata->button_status_reg);
		if (val < 0) {
			hwlog_err("%s: fail to read status reg\n", __func__);
			mutex_unlock(&data->input_dev->mutex);
			return IRQ_NONE;
		}

		key_states = (unsigned long)val;

		for (key = 0; key < pdata->nbuttons; key++) {
			curr_state = test_bit(key, &data->key_status);
			new_state = test_bit(key, &key_states);

			if (curr_state ^ new_state) {
				input_event(data->input_dev, EV_KEY,
					pdata->key_code[key], !!(key_states & (1 << key)));
				sync = true;
			}
		}

		data->key_status = key_states;

		if (sync) {
			input_sync(data->input_dev);
		}
	}
	mutex_unlock(&data->input_dev->mutex);

	return IRQ_HANDLED;
}

/* to be continue */
static ssize_t cyttsp_debug_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	char *c = "actived";
	return sprintf(buf, "%s\n", c);
}
/* to be continue */
static ssize_t cyttsp_debug_enable_store(struct device *dev,
			struct device_attribute *attr, const char *buf, size_t count)
{
	return 0;
}

static DEVICE_ATTR(debug_enable, S_IWUSR | S_IRUSR, cyttsp_debug_enable_show,
			cyttsp_debug_enable_store);

static struct attribute *cyttsp_attrs[] = {
	&dev_attr_debug_enable.attr,
	NULL
};

static const struct attribute_group cyttsp_attr_group = {
	.attrs = cyttsp_attrs,
};

static int cyttsp_need_update_or_not(struct cyttsp_button_data *data,
							const struct firmware *fw)
{
	unsigned char buffer[CYTTSP_FW_ORG_DATA_LEN];
	const unsigned char *curr = fw->data;
	unsigned char id[2], in_chip_id[2];
	int total = fw->size;
	int ret;

	while (total != 0) {
		ret = cyttsp_get_single_line(curr, buffer);
		total -= ret;
		curr += ret;
	}

	/* array element 56 and 58 contain fw version in image */
	id[1] = cyttsp_convert_to_u8(&buffer[57]);
	id[0] = cyttsp_convert_to_u8(&buffer[55]);

	/* get fw version in chip at addr 0x46 */
	ret = cyttsp_read_reg(data, CYTTSP_BUTTON_FW_VER1);
	if (ret < 0) {
		hwlog_err("%s: fail to read fw id0!\n", __func__);
		return false;
	}
	in_chip_id[0] = ret;

	/* get fw version in chip at addr 0x47 */
	ret = cyttsp_read_reg(data, CYTTSP_BUTTON_FW_VER2);
	if (ret < 0) {
		hwlog_err("%s: fail to read fw id1!\n", __func__);
		return false;
	}
	in_chip_id[1] = ret;

	hwlog_info("%s: image version = 0x%02x 0x%02x,"
		" in chip version = 0x%02x 0x%02x\n", __func__,
			id[0], id[1], in_chip_id[0], in_chip_id[1]);

	if (id[0] != in_chip_id[0] || id[1] != in_chip_id[1]) {
		return true;
	}

	return false;
}

static int cyttsp_fw_update_proc(struct cyttsp_button_data *data)
{
	int i = 0;
	int ret = 0;
	int total =0;
	unsigned char cmd[CYTTSP_FW_ORG_DATA_LEN];
	unsigned char buffer[CYTTSP_FW_ORG_DATA_LEN];
	bool need_update = false;
	const unsigned char *tmp_buf;
	const char *fw_info = "ts/touch_key/stf_cyp_psoc4000.cyacd";

	/* btld entrance: 0x04
	** cmd sequence to switch into btld mode: 0x2B, 0x2B, 0xFE, 0xFA
	*/
	unsigned char switch_to_btld_cmd[5] = {0x04, 0x2B, 0x2B, 0xFE, 0xFA,};

	const struct firmware *fw = NULL;
	struct device *dev = &data->client->dev;
	struct cyttsp_button_platform_data *pdata = data->pdata;

	disable_irq(pdata->irq_num);

	/* request fw image from bank */
	ret = request_firmware(&fw, fw_info, dev);
	if (ret < 0) {
		hwlog_err("%s: fail to request firmware %s\n", __func__, fw_info);
		goto recovery;
	}

	total = fw->size;
	tmp_buf = fw->data;

	if (false == in_bootloader) {
		/* get fw version in ic */
		ret = cyttsp_i2c_read_block(&data->client->dev,
					CYTTSP_BUTTON_FW_VER1, CYTTSP_FW_VER_SIZE,
					data->fw_version);
		if (ret) {
			hwlog_err("%s: unable to get fw version\n", __func__);
			goto free_fw;
		}
		hwlog_info("%s: ic fw version: 0x%02x 0x%02x\n", __func__,
				(unsigned int)data->fw_version[0], (unsigned int)data->fw_version[1]);

		/* check version and if not same, update fw */
		need_update = cyttsp_need_update_or_not(data, fw);
		if (!need_update) {
				hwlog_info("%s: same ver between ic and image, NO need to update\n",
				__func__);
			goto free_fw;
		} else {
				hwlog_info("%s: ver's diff between ic and image, NEED update\n",
				__func__);
		}

		ret = cyttsp_i2c_send(dev, sizeof(switch_to_btld_cmd), switch_to_btld_cmd);
		if (ret) {
			hwlog_err("%s: fail to switch to bootloader\n", __func__);
			goto free_fw;
		} else {
			hwlog_info("%s: jump into btld mode already\n", __func__);
		}
	}

	mdelay(CYTTSP_FWUP_DELAY_COUNT);
	data->app_addr = data->client->addr;
	data->bl_addr = pdata->bl_addr;
	data->client->addr = data->bl_addr;

	/* 1. enter into bootloader */
	ret = cyttsp_send_command(data, CYTTSP_CMD_ENTER_BTLD, NULL, 0, 0);
	if (ret) {
		hwlog_err("%s: fail to enter into bootloader\n", __func__);
		goto exit_bootloader;
	}

	/* 2. get flash size */
	cmd[0] = 0;
	ret = cyttsp_send_command(data, CYTTSP_CMD_GET_FLASH_SIZE, cmd, 1, 0);
	if (ret) {
		hwlog_err("%s: fail to get flash size\n", __func__);
		goto exit_bootloader;
	}

	ret = cyttsp_get_single_line(tmp_buf, buffer);
	total -= ret;
	tmp_buf += ret;

	/* 3. send data and program, verify*/
	while (total > 0) {

		int j;
		unsigned char tmp[CYTTSP_PROGRAM_DATA_LEN];
		unsigned char array_id;
		unsigned char data_buf[CYTTSP_AVAILABLE_DATA_LEN];
		unsigned char row_checksum;
		unsigned short row_num, length;
		unsigned char length_u8;

		ret = cyttsp_get_single_line(tmp_buf, buffer);
		total -= ret;
		tmp_buf += ret;

		array_id = cyttsp_convert_to_u8(&buffer[1]);
		row_num = cyttsp_convert_to_u16(&buffer[3]);
		length = cyttsp_convert_to_u16(&buffer[7]);
		length_u8 = (unsigned char)length;
		hwlog_debug("%s: array_id = 0x%02x, row_num = 0x%02x, len = 0x%02x\n",
				__func__, array_id, row_num, length);

		/* the following step will get ride of the inavailable data
		** in each line of .cyacd file, and put the usefull data into
		** data_buf array.
		** format of those inavailable data is like this:
		** 4 byte silicon id;
		** 1 byte silicon rev;
		** 1 byte checksum data;
		** 1 byte array id;
		** 2 byte row number;
		** 2 byte data length
		*/
		for (j = 0; j < length_u8 * 2; j += 2) {
			data_buf[j/2] = cyttsp_convert_to_u8(&buffer[11+j]);
		}

		/* send data here */
		ret = cyttsp_send_command(data, CYTTSP_CMD_SEND_DATA,
					&data_buf[0], length - 1, 0);
		if (ret) {
			hwlog_err("%s: fail to send data at round %d\n", __func__, i);
			goto exit_bootloader;
		}

		/* program here */
		tmp[0] = 0x00;
		tmp[1] = row_num & CYTTSP_8BITS_MASK;
		tmp[2] = (row_num & CYTTSP_16BITS_MASK) >> CYTTSP_8BITS_SHIFT;
		tmp[3] = data_buf[length - 1];
		ret = cyttsp_send_command(data, CYTTSP_CMD_PROGRAM_ROW, tmp, 4, 0);
		if (ret) {
			hwlog_err("%s: fail to program row at round %d!\n", __func__, i);
			goto exit_bootloader;
		}

		/* verify row */
		row_checksum = calculate_checksum8(&data_buf[0], length);
		tmp[0] = 0x00;
		tmp[1] = row_num & CYTTSP_8BITS_MASK;
		tmp[2] = (row_num & CYTTSP_16BITS_MASK) >> CYTTSP_8BITS_SHIFT;
		ret = cyttsp_send_command(data, CYTTSP_CMD_VERIFY_ROW, tmp, 3, row_checksum);
		if (ret) {
			hwlog_err("%s: fail to verify row at round %d\n", __func__, i);
			goto exit_bootloader;
		}
		i++;
	}

exit_bootloader:
	/* 4. Exit bootloader mode */
	cmd[0] = 0;
	ret = cyttsp_send_command(data, CYTTSP_CMD_EXIT_BTLD, cmd, 1, 0);
	if (ret) {
		hwlog_err("%s: fail to exit bootloader mode\n", __func__);
	} else {
		hwlog_info("%s: back into normal mode already\n", __func__);
	}
	data->client->addr = data->app_addr;
free_fw:
	release_firmware(fw);
recovery:
	enable_irq(pdata->irq_num);

	return ret;
}

static int cyttsp_fw_update_thread(void *arg)
{
	int error = 0;
	struct cyttsp_button_data *data = i2c_get_clientdata(this_client);

	if(kthread_should_stop()) {
		hwlog_err("%s: thread had stopped\n", __func__);
		return -EIO;
	}
	hwlog_info("%s: fw update process running\n", __func__);

	fw_update_flag = PROC_ON;
	error = cyttsp_fw_update_proc(data);
	if (error < 0) {
		fw_update_flag = PROC_OFF;
		hwlog_info("%s: fw update failed\n", __func__);
		return -EIO;
	}
	fw_update_flag = PROC_OFF;

	return 0;
}
static int cyttsp_button_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	unsigned char val = 0;
	struct device *dev = NULL;
	int i = 0;
	int error = 0;
	struct cyttsp_button_data *data = NULL;
	struct cyttsp_button_platform_data *pdata = client->dev.platform_data;

	in_bootloader = false;
	fw_update_flag = PROC_OFF;
	hwlog_info("%s: cyttsp button's probing\n", __func__);

	/* i2c sm-bus check */
	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		hwlog_err("%s: SMBus byte data not supported\n", __func__);
		return -EIO;
	}

	/* get and set dts node info */
	if (client->dev.of_node) {
		pdata = devm_kzalloc(&client->dev,
				sizeof(struct cyttsp_button_platform_data), GFP_KERNEL);
		if (!pdata) {
			hwlog_err("%s: fail to allocate memroy for pdata\n", __func__);
			error = -ENOMEM;
			goto err_pdata_request;
		}
		error = cyttsp_button_parse_dt(&client->dev, pdata);
		if (error) {
			hwlog_err("%s: parse dts failed\n", __func__);
			goto parse_dt_error;
		}
	} else {
		pdata = client->dev.platform_data;
	}

	data = kzalloc(sizeof(struct cyttsp_button_data), GFP_KERNEL);
	if (!data) {
		hwlog_err("%s: fail to allocate memory for data!\n", __func__);
		error = -ENOMEM;
		goto err_data_request;
	}

	this_client = client;
	data->client = client;
	data->pdata = pdata;

	/* setup irq gpio */
	error = gpio_request(pdata->irq_gpio, "cyttsp_button_irq_gpio");
	if (error) {
		hwlog_err("%s: unable to request gpio [%d]\n",
				__func__, pdata->irq_gpio);
		goto err_irq_gpio_req;
	}

	error = gpio_direction_input(pdata->irq_gpio);
	if (error) {
		hwlog_err("%s: unable to set direction for gpio [%d]\n",
				__func__, pdata->irq_gpio);
		goto err_irq_gpio_req_direction;
	}

	pdata->irq_num = gpio_to_irq(pdata->irq_gpio);
	if (!pdata->irq_num) {
		hwlog_err("%s: fail to request irq numbers\n", __func__);
		error = pdata->irq_num;
		goto err_request_irq_num;
	}

	i2c_set_clientdata(data->client, data);

	/* Initialize input device */
	data->input_dev = input_allocate_device();
	if (!data->input_dev) {
		hwlog_err("%s: fail to allocate input device\n", __func__);
		goto err_allocate_input;
	}

	if (data->pdata->input_name) {
		data->input_dev->name = data->pdata->input_name;
	} else {
		data->input_dev->name = "cyttsp_button";
	}

	input_set_drvdata(data->input_dev, data);
	dev_set_drvdata(&data->client->dev, data);

	data->input_dev->id.bustype = BUS_I2C;
	data->input_dev->dev.parent = &data->client->dev;

	/* power on button */
	error = cyttsp_button_power_on(data->input_dev);
	if (error) {
		hwlog_err("%s(%d): fail to power on button\n", __func__,
			__LINE__);
		goto err_request_irq;
	}

	data->enable = false;
#ifdef CONFIG_FB
	data->fb_notif.notifier_call = fb_notifier_callback;
	error = fb_register_client(&data->fb_notif);
	if (error) {
		hwlog_err("%s: unable to register fb_notifier: %d", __func__, error);
		goto err_register_fb;
	}
#endif

	for (i = 0; i < pdata->nbuttons; i++) {
		input_set_capability(data->input_dev, EV_KEY, pdata->key_code[i]);
		hwlog_info("%s: key_code[%d] = %d\n", __func__, i + 1, pdata->key_code[i]);
	}

	__set_bit(EV_SYN, data->input_dev->evbit);
	__set_bit(EV_KEY, data->input_dev->evbit);

	error = input_register_device(data->input_dev);
	if (error) {
		hwlog_err("%s: unable to register input device, error: %d\n", __func__, error);
		goto err_register_device;
	}

	/* request irq and install interrupt handler */
	error = request_threaded_irq(pdata->irq_num, NULL, cyttsp_button_interrupt_handler,
					pdata->irq_flags, client->dev.driver->name, data);
	if (error) {
		hwlog_err("%s: error %d registering irq\n", __func__, error);
		goto err_request_irq;
	}
	disable_irq(pdata->irq_num);

	/* make debug sysfs nodes */
	error = sysfs_create_group(&client->dev.kobj, &cyttsp_attr_group);
	if (error) {
		hwlog_err("%s: failure %d creating sysfs group\n", __func__, error);
	}

	dev = &data->client->dev;
	mdelay(CYTTSP_WAKE_DELAY_COUNT);
	error = cyttsp_i2c_read_block(dev, CYTTSP_REG_TOUCHMODE, 1, &val);
	if (error < 0) {
		hwlog_warn("%s: fail to read from app slave addr\n", __func__);
		hwlog_warn("%s: switch to btld slave addr to read\n", __func__);

		data->app_addr = data->client->addr;
		data->bl_addr = pdata->bl_addr;
		data->client->addr = data->bl_addr;

		error = cyttsp_i2c_recv(dev, 1, &val);
		if (error != 0) {
			hwlog_err("%s: fail to read btld slave addr\n", __func__);
			hwlog_err("%s: button's not on site\n", __func__);
			goto err_write_no_sleep_mode;
		} else {
			in_bootloader = true;
			data->client->addr = data->app_addr;
			hwlog_info("%s: succ to read from btld addr, in btld mode\n", __func__);
		}
	} else {
		hwlog_info("%s: succ to read from app addr, in app mode\n", __func__);

		/* wake ic up from deep sleep mode */
		mdelay(CYTTSP_WAKE_DELAY_COUNT);
		error = cyttsp_write_reg(data, pdata->work_mode_reg, CYTTSP_NORMAL_MODE);
		if (!error) {
			hwlog_info("%s: ic awaken from sleep mode\n", __func__);
		} else {
			hwlog_err("%s: wake ic from sleep mode failed\n", __func__);
			goto err_write_no_sleep_mode;
		}
	}

	kthread_run(cyttsp_fw_update_thread, NULL, "cyp_key_updatethread");

	enable_irq(pdata->irq_num);
	hwlog_info("%s: button probe done\n", __func__);

	return 0;
err_write_no_sleep_mode:
err_request_irq:
	input_unregister_device(data->input_dev);
err_register_device:
err_register_fb:
#ifdef CONFIG_FB
	fb_unregister_client(&data->fb_notif);
#endif
	input_free_device(data->input_dev);
err_allocate_input:
err_request_irq_num:
err_irq_gpio_req_direction:
	if (gpio_is_valid(pdata->irq_gpio)) {
		gpio_free(pdata->irq_gpio);
	}
err_irq_gpio_req:
	kfree(data);
err_data_request:
parse_dt_error:
err_pdata_request:
	hwlog_err("%s: Button probe failed\n", __func__);
	return error;
}

static int cyttsp_button_remove(struct i2c_client *client)
{
	int error = 0;
	struct cyttsp_button_data *data = i2c_get_clientdata(client);
	const struct cyttsp_button_platform_data *pdata = data->pdata;

	sysfs_remove_group(&client->dev.kobj, &cyttsp_attr_group);

	error = cyttsp_button_power_off(data->input_dev);
	if (error) {
		hwlog_err("%s(%d): fail to power off button\n", __func__,
			__LINE__);
	}
	disable_irq(client->irq);
	free_irq(client->irq, data);

	input_unregister_device(data->input_dev);
	if (gpio_is_valid(pdata->irq_gpio)) {
		gpio_free(pdata->irq_gpio);
	}

#ifdef CONFIG_FB
	fb_unregister_client(&data->fb_notif);
#endif

	kfree(data);
	data = NULL;

	return 0;
}

static const struct i2c_device_id cyttsp_key_id[] = {
	{CYP_TOUCH_KEY_COMPATIBLE_ID, 0},
	{ },
};

static struct of_device_id cyttsp_match_table[] = {
	{
		.compatible = CYP_TOUCH_KEY_COMPATIBLE_ID,
		.data = NULL,
	},
	{ },
};

static struct i2c_driver cyttsp_button_driver = {
	.driver = {
		.name	= CYP_TOUCH_KEY_COMPATIBLE_ID,
		.owner	= THIS_MODULE,
		.of_match_table = cyttsp_match_table,
	},
	.probe		= cyttsp_button_probe,
	.remove		= cyttsp_button_remove,
	.id_table		= cyttsp_key_id,
};

static int __init cyttsp_button_init(void)
{
	hwlog_info("%s: button module init\n", __func__);
	return i2c_add_driver(&cyttsp_button_driver);
}

static void __exit cyttsp_button_exit(void)
{
	hwlog_info("%s: cyttsp touch key exit\n", __func__);
	i2c_del_driver(&cyttsp_button_driver);
}

module_init(cyttsp_button_init);
module_exit(cyttsp_button_exit);

MODULE_AUTHOR("hwx370038, huzheng3@huawei.com");
MODULE_DESCRIPTION("huawei cypress touch key driver");
MODULE_LICENSE("GPL");
