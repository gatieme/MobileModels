/*
 * Huawei mipibridge spi driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include "mipibridge.h"

/* spi config */
#define SPI_RETRY_TIMES 5
#define SPI_DELAY_MS 5
#define SPI_BUF_SIZE 300
#define SPI_COM_MODE_POLL 1
#define SPI_COM_MODE_DMA 2
#define DEFAULT_BITS_PER_WORD 8
#define DEFAULT_SPI_SPEED 2000000

struct spi_config {
	bool inited;
	char *tx_buff;
	char *rx_buff;
	u32 max_speed_hz;
	u32 mode;
	u32 bits_per_word;
	u32 bus_id;
	int cs_gpio;
	struct spi_device *spi_dev;
	struct semaphore spi_sem;
	struct pl022_config_chip pl022_spi_config;
};

static struct spi_config g_spi_config = {0};

int mipibridge_spi_send_transfer(uint8_t *wdata, unsigned int wlen)
{
	struct spi_transfer xfer = {0};
	struct spi_message msg;
	int retry = 0;
	int ret = MIPI_BRIDGE_OK;

	if (!g_spi_config.inited) {
		mipibridge_errmsg("spi config is not init!!!");
		return MIPI_BRIDGE_FAIL;
	}

	if (!wdata)
		return MIPI_BRIDGE_FAIL;

	down(&g_spi_config.spi_sem);
	g_spi_config.pl022_spi_config.com_mode = SPI_COM_MODE_DMA;
	spi_setup(g_spi_config.spi_dev);
	ret = memcpy_s(g_spi_config.tx_buff, SPI_BUF_SIZE, wdata, wlen);
	if (ret != EOK) {
		mipibridge_errmsg("memcpy_s fail err %d\n", ret);
		up(&g_spi_config.spi_sem);
		return MIPI_BRIDGE_FAIL;
	}

	xfer.tx_buf = g_spi_config.tx_buff;
	xfer.len = wlen;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);
	while (retry < SPI_RETRY_TIMES) {
		ret = spi_sync(g_spi_config.spi_dev, &msg);
		if (ret) {
			mipibridge_errmsg("spi_sync failed: ret=%d, retry=%d\n", ret, retry);
			retry++;
			mdelay(SPI_DELAY_MS);
			continue;
		} else {
			break;
		}
	}

	up(&g_spi_config.spi_sem);
	return ret;
}

int mipibridge_spi_recive_transfer(uint8_t cmd, uint8_t *rbuf, unsigned int rlen)
{
	struct spi_transfer xfer0 = {0};
	struct spi_transfer xfer1 = {0};
	struct spi_message msg;
	int retry = 0;
	int ret = MIPI_BRIDGE_OK;

	if (!g_spi_config.inited) {
		mipibridge_errmsg("spi config is not init!!!");
		return MIPI_BRIDGE_FAIL;
	}

	if (!rbuf)
		return MIPI_BRIDGE_FAIL;

	down(&g_spi_config.spi_sem);
	g_spi_config.pl022_spi_config.com_mode = SPI_COM_MODE_POLL;
	spi_setup(g_spi_config.spi_dev);
	spi_message_init(&msg);

	g_spi_config.tx_buff[0] = cmd;

	xfer0.tx_buf = g_spi_config.tx_buff;
	xfer0.len = 1;
	spi_message_add_tail(&xfer0, &msg);

	xfer1.rx_buf = g_spi_config.rx_buff;
	xfer1.len = rlen;
	spi_message_add_tail(&xfer1, &msg);
	while (retry < SPI_RETRY_TIMES) {
		ret = spi_sync(g_spi_config.spi_dev, &msg);
		if (ret) {
			mipibridge_errmsg("spi_sync failed: ret=%d, retry=%d\n", ret, retry);
			retry++;
			mdelay(SPI_DELAY_MS);
			continue;
		} else {
			break;
		}
	}

	ret = memcpy_s(rbuf, rlen, g_spi_config.rx_buff, rlen);
	if (ret != EOK) {
		mipibridge_errmsg("memcpy_s fail err %d\n", ret);
		up(&g_spi_config.spi_sem);
		return MIPI_BRIDGE_FAIL;
	}

	up(&g_spi_config.spi_sem);
	return ret;
}

/* write */
int mipibridge_spi_send_and_receive_transfer(uint8_t *wdata, unsigned int wlen, uint8_t *rbuf, unsigned int rlen)
{
	struct spi_transfer xfer = {0};
	struct spi_message msg;
	int retry = 0;
	int ret = MIPI_BRIDGE_OK;

	if (!g_spi_config.inited) {
		mipibridge_errmsg("spi config is not init!!!");
		return MIPI_BRIDGE_FAIL;
	}

	if (!wdata || !rbuf)
		return MIPI_BRIDGE_FAIL;

	down(&g_spi_config.spi_sem);
	g_spi_config.pl022_spi_config.com_mode = SPI_COM_MODE_DMA;
	spi_setup(g_spi_config.spi_dev);
	spi_message_init(&msg);

	ret = memcpy_s(g_spi_config.tx_buff, SPI_BUF_SIZE, wdata, wlen);
	if (ret != EOK) {
		mipibridge_errmsg("memcpy_s fail err %d\n", ret);
		up(&g_spi_config.spi_sem);
		return MIPI_BRIDGE_FAIL;
	}

	xfer.tx_buf = g_spi_config.tx_buff;
	xfer.rx_buf = g_spi_config.rx_buff;
	xfer.len = wlen + rlen;
	spi_message_add_tail(&xfer, &msg);
	while (retry < SPI_RETRY_TIMES) {
		ret = spi_sync(g_spi_config.spi_dev, &msg);
		if (ret) {
			mipibridge_errmsg("spi_sync failed: ret=%d, retry=%d\n", ret, retry);
			retry++;
			mdelay(SPI_DELAY_MS);
			continue;
		} else {
			break;
		}
	}

	ret = memcpy_s(rbuf, rlen, g_spi_config.rx_buff + wlen, rlen);
	if (ret != EOK) {
		mipibridge_errmsg("memcpy_s fail err %d\n", ret);
		up(&g_spi_config.spi_sem);
		return MIPI_BRIDGE_FAIL;
	}

	up(&g_spi_config.spi_sem);
	return ret;
}

int mipibridge_set_spi_freq_and_mode(u32 max_speed_hz, u32 mode)
{
	if (!g_spi_config.inited) {
		mipibridge_errmsg("spi config is not init!!!");
		return MIPI_BRIDGE_FAIL;
	}

	if (max_speed_hz)
		g_spi_config.spi_dev->max_speed_hz = max_speed_hz;
	if (mode == SPI_MODE_0 || mode == SPI_MODE_1 || mode == SPI_MODE_2 || mode == SPI_MODE_3)
		g_spi_config.spi_dev->mode = mode;

	spi_setup(g_spi_config.spi_dev);
	return MIPI_BRIDGE_OK;
}

static int mipibridge_spi_parse_u32(const struct device_node *np, const char *prop_name,
	unsigned int *out, unsigned int def)
{
	unsigned int temp = 0;

	if (!np || !out || !prop_name) {
		mipibridge_errmsg("pointer is null\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (of_property_read_u32(np, prop_name, &temp)) {
		*out = def;
		mipibridge_errmsg("of_property_read: %s not find, val = %d\n", prop_name, *out);
		return MIPI_BRIDGE_FAIL;
	}
	*out = temp;
	return MIPI_BRIDGE_OK;
}

/* free dev and buffers */
static int mipibridge_spi_buffer_free()
{
	if (g_spi_config.tx_buff) {
		kfree(g_spi_config.tx_buff);
		g_spi_config.tx_buff = NULL;
	}
	
	if (g_spi_config.rx_buff) {
		kfree(g_spi_config.rx_buff);
		g_spi_config.rx_buff = NULL;
	}
	return MIPI_BRIDGE_OK;
}

/* malloc dev and buffers */
static int  mipibridge_spi_buffer_malloc(void)
{
	g_spi_config.tx_buff = kzalloc(SPI_BUF_SIZE, GFP_KERNEL);
	if (!g_spi_config.tx_buff)
		goto err_spi_dev_free;
	g_spi_config.rx_buff = kzalloc(SPI_BUF_SIZE, GFP_KERNEL);
	if (!g_spi_config.rx_buff)
		goto err_spi_dev_free;

	return MIPI_BRIDGE_OK;

err_spi_dev_free:
	mipibridge_errmsg("mipibridge_spi_buffer_malloc failed\n");
	mipibridge_spi_buffer_free();
	return MIPI_BRIDGE_FAIL;
}

static void mipibridge_spi_cs_set(u32 control)
{
	if (gpio_direction_output(g_spi_config.cs_gpio, control) < 0)
		mipibridge_errmsg("fail to set gpio cs\n");
}

static int mipibridge_spi_parse_config(struct device_node *spi_cfg_node)
{
	int ret = MIPI_BRIDGE_OK;
	if (!spi_cfg_node) {
		mipibridge_errmsg("bridge not config in dts, exit\n");
		return -ENODEV;
	}
	
	mipibridge_spi_parse_u32(spi_cfg_node, "spi-max-frequency", &g_spi_config.max_speed_hz, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "spi-bus-id", &g_spi_config.bus_id, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "spi-mode", &g_spi_config.mode, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "bits-per-word", &g_spi_config.bits_per_word, DEFAULT_BITS_PER_WORD);

	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,interface", &g_spi_config.pl022_spi_config.iface, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,com-mode", &g_spi_config.pl022_spi_config.com_mode, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,rx-level-trig", &g_spi_config.pl022_spi_config.rx_lev_trig, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,tx-level-trig", &g_spi_config.pl022_spi_config.tx_lev_trig, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,ctrl-len", &g_spi_config.pl022_spi_config.ctrl_len, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,wait-state", &g_spi_config.pl022_spi_config.wait_state, 0);
	mipibridge_spi_parse_u32(spi_cfg_node, "pl022,duplex", &g_spi_config.pl022_spi_config.duplex, 0);

	if (!g_spi_config.max_speed_hz)
		g_spi_config.max_speed_hz = DEFAULT_SPI_SPEED;
	if (!g_spi_config.mode)
		g_spi_config.mode = SPI_MODE_0;
	if (!g_spi_config.bits_per_word)
		g_spi_config.bits_per_word = DEFAULT_BITS_PER_WORD;

	g_spi_config.pl022_spi_config.cs_control = mipibridge_spi_cs_set;
	g_spi_config.pl022_spi_config.hierarchy = SSP_MASTER;

	mipibridge_spi_parse_u32(spi_cfg_node, "cs_gpio", &g_spi_config.cs_gpio, 0);
	ret = gpio_request(g_spi_config.cs_gpio, "spi_cs");
	if (ret) {
		mipibridge_errmsg("gpio_request %d failed\n", g_spi_config.cs_gpio);
		return ret;
	}
	gpio_direction_output(g_spi_config.cs_gpio, 1);
	mipibridge_errmsg("set cs gpio %d deault hi\n", g_spi_config.cs_gpio);

	return MIPI_BRIDGE_OK;
}

static int mipibridge_spi_probe(struct spi_device *spi_dev)
{
	int ret = MIPI_BRIDGE_OK;

	if (!spi_dev)
		return -ENODEV;

	g_spi_config.spi_dev = spi_dev;
	mipibridge_spi_parse_config(spi_dev->dev.of_node);
	/* spi config */
	spi_dev->controller_data = &g_spi_config.pl022_spi_config;
	spi_dev->mode = (uint8_t)g_spi_config.mode;
	spi_dev->max_speed_hz = g_spi_config.max_speed_hz;
	spi_dev->bits_per_word = (uint8_t)g_spi_config.bits_per_word;

	sema_init(&g_spi_config.spi_sem, 1);

	ret = spi_setup(spi_dev);
	if (ret) {
		mipibridge_errmsg("spi setup fail\n");
		return ret;
	}

	ret = mipibridge_spi_buffer_malloc();
	if (ret) {
		mipibridge_errmsg("malloc failed\n");
		return -EIO;
	}

	g_spi_config.inited = true;
	return MIPI_BRIDGE_OK;
}

static int mipibridge_spi_remove(struct spi_device *sdev)
{
	mipibridge_spi_buffer_free();
	return 0;
}

static const struct of_device_id g_mipibridge_spi_match_table[] = {
	{ .compatible = "huawei,mipibridge_spi", },
	{},
};

static const struct spi_device_id g_mipibridge_spi_device_id[] = {
	{ "huawei,mipibridge_spi", 0 },
	{},
};
MODULE_DEVICE_TABLE(spi, g_mipibridge_spi_device_id);

static struct spi_driver g_mipibridge_spi_spi_driver = {
	.probe = mipibridge_spi_probe,
	.remove = mipibridge_spi_remove,
	.id_table = g_mipibridge_spi_device_id,
	.driver = {
		.name = "huawei,mipibridge_spi",
		.owner = THIS_MODULE,
		.bus = &spi_bus_type,
		.of_match_table = of_match_ptr(g_mipibridge_spi_match_table),
	},
};

static int __init mipibridge_spi_module_init(void)
{
	spi_register_driver(&g_mipibridge_spi_spi_driver);
	return 0;
}

static void __exit mipibridge_spi_module_exit(void)
{
	spi_unregister_driver(&g_mipibridge_spi_spi_driver);
}

module_init(mipibridge_spi_module_init);
module_exit(mipibridge_spi_module_exit);

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
