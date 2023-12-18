// SPDX-License-Identifier: GPL-2.0
/*
 * power_glink_ulog.c
 *
 * glink ulog for power module
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/jiffies.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/rpmsg.h>
#include <linux/slab.h>
#include <linux/soc/qcom/pmic_glink.h>
#include <linux/workqueue.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG power_glink_ulog
HWLOG_REGIST();

#define POWER_GLINK_ULOG_MSG_NAME              "oem_power_ulog"
#define POWER_GLINK_ULOG_MSG_OWNER_ID          32789
#define POWER_GLINK_ULOG_MSG_TYPE_REQ_RESP     1
#define POWER_GLINK_ULOG_MSG_TYPE_NOTIFY       2

/* opcode for power_glink_ulog */
#define POWER_GLINK_ULOG_OPCODE_GET_REG_DUMP   0x20000

#define POWER_GLINK_ULOG_MSG_WAIT_MS           1000
#define POWER_GLINK_ULOG_REG_DUMP_MAX_SIZE     2048

#define PM8350B_REGISTER_ADDRESS               0x2600

struct power_glink_ulog_req_reg_dump_msg {
	struct pmic_glink_hdr hdr;
};

struct reg_dump_data {
	u8 buffer[POWER_GLINK_ULOG_REG_DUMP_MAX_SIZE];
	u32 len;
};

struct power_glink_ulog_get_reg_dump_msg {
	struct pmic_glink_hdr hdr;
	struct reg_dump_data data;
};

struct power_glink_ulog_dev {
	struct device *dev;
	struct pmic_glink_client *client;
	struct mutex send_lock;
	struct completion msg_ack;
	struct dentry *root;
	struct reg_dump_data data;
};

static struct power_glink_ulog_dev *g_power_glink_ulog_dev;

static int power_glink_ulog_send_message(struct power_glink_ulog_dev *l_dev,
	void *data, int len)
{
	int ret;

	mutex_lock(&l_dev->send_lock);
	reinit_completion(&l_dev->msg_ack);

	ret = pmic_glink_write(l_dev->client, data, len);
	if (ret) {
		mutex_unlock(&l_dev->send_lock);
		hwlog_err("send message error\n");
		return ret;
	}

	/* wait for to receive data when message send success */
	ret = wait_for_completion_timeout(&l_dev->msg_ack,
		msecs_to_jiffies(POWER_GLINK_ULOG_MSG_WAIT_MS));
	if (!ret) {
		mutex_unlock(&l_dev->send_lock);
		hwlog_err("send message timeout\n");
		return -ETIMEDOUT;
	}

	mutex_unlock(&l_dev->send_lock);
	return 0;
}

static int power_glink_ulog_req_reg_dump(struct power_glink_ulog_dev *l_dev)
{
	struct power_glink_ulog_req_reg_dump_msg msg = { { 0 } };

	/* prepare header */
	msg.hdr.owner = POWER_GLINK_ULOG_MSG_OWNER_ID;
	msg.hdr.type = POWER_GLINK_ULOG_MSG_TYPE_REQ_RESP;
	msg.hdr.opcode = POWER_GLINK_ULOG_OPCODE_GET_REG_DUMP;

	return power_glink_ulog_send_message(l_dev, &msg, sizeof(msg));
}

static void power_glink_ulog_reg_dump_rsp(struct power_glink_ulog_dev *l_dev,
	void *data, size_t len)
{
	struct power_glink_ulog_get_reg_dump_msg *msg = data;

	if (len != sizeof(*msg)) {
		hwlog_err("invalid msg len: %u!=%u\n", len, sizeof(*msg));
		return;
	}

	memcpy(l_dev->data.buffer, msg->data.buffer, sizeof(msg->data.buffer));
	l_dev->data.len = msg->data.len;
	hwlog_info("get reg dump success, len=%u\n", l_dev->data.len);

	complete(&l_dev->msg_ack);
}

static int power_glink_ulog_msg_callback(void *dev_data, void *data, size_t len)
{
	struct pmic_glink_hdr *hdr = data;
	struct power_glink_ulog_dev *l_dev = dev_data;

	if (!l_dev || !hdr)
		return -ENODEV;

	hwlog_info("msg_callback: owner=%u type=%u opcode=%u len=%zu\n",
		hdr->owner, hdr->type, hdr->opcode, len);

	if (hdr->owner != POWER_GLINK_ULOG_MSG_OWNER_ID) {
		hwlog_err("invalid msg owner: %u\n", hdr->owner);
		return -EINVAL;
	}

	switch (hdr->opcode) {
	case POWER_GLINK_ULOG_OPCODE_GET_REG_DUMP:
		power_glink_ulog_reg_dump_rsp(l_dev, data, len);
		break;
	default:
		hwlog_err("invalid opcode: %u\n", hdr->opcode);
		break;
	}

	return 0;
}

static int reg_dump_set(void *data, u64 val)
{
	return 0;
}

static int reg_dump_get(void *data, u64 *val)
{
	int i, ret;
	struct power_glink_ulog_dev *l_dev = data;

	if (!l_dev)
		return 0;

	memset(l_dev->data.buffer, 0, sizeof(l_dev->data.buffer));
	l_dev->data.len = 0;

	ret = power_glink_ulog_req_reg_dump(l_dev);
	if (ret || l_dev->data.len == 0) {
		hwlog_err("%s: ret=%d", __func__, ret);
		return ret;
	}

	*val = l_dev->data.len;
	hwlog_info("%s: data_len=%u\n", __func__, l_dev->data.len);
	for (i = 0; i < l_dev->data.len; i++)
		hwlog_info("%x: %x\n", PM8350B_REGISTER_ADDRESS + i,
			l_dev->data.buffer[i]);

	return 0;
}
DEFINE_DEBUGFS_ATTRIBUTE(reg_dump_fops, reg_dump_get, reg_dump_set, "%llu\n");

static void power_glink_ulog_create_debugfs(struct power_glink_ulog_dev *l_dev)
{
	l_dev->root = debugfs_create_dir("power_ulog", NULL);

	if (!l_dev->root) {
		hwlog_err("%s: create debugfs root node fail\n", __func__);
		return;
	}

	debugfs_create_file("reg_dump", 0600, l_dev->root, l_dev,
		&reg_dump_fops);
}

static int power_glink_ulog_probe(struct platform_device *pdev)
{
	int ret;
	struct power_glink_ulog_dev *l_dev = NULL;
	struct pmic_glink_client_data client_data = { 0 };

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	l_dev = devm_kzalloc(&pdev->dev, sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;

	l_dev->dev = &pdev->dev;

	mutex_init(&l_dev->send_lock);
	init_completion(&l_dev->msg_ack);

	client_data.id = POWER_GLINK_ULOG_MSG_OWNER_ID;
	client_data.name = POWER_GLINK_ULOG_MSG_NAME;
	client_data.msg_cb = power_glink_ulog_msg_callback;
	client_data.priv = l_dev;
	l_dev->client = pmic_glink_register_client(l_dev->dev, &client_data);
	if (IS_ERR(l_dev->client)) {
		hwlog_err("glink register fail\n");
		ret = -EPROBE_DEFER;
		goto fail_free_mem;
	}

	power_glink_ulog_create_debugfs(l_dev);
	platform_set_drvdata(pdev, l_dev);
	g_power_glink_ulog_dev = l_dev;
	hwlog_info("probe ok\n");

	return 0;

fail_free_mem:
	mutex_destroy(&l_dev->send_lock);
	return ret;
}

static int power_glink_ulog_remove(struct platform_device *pdev)
{
	struct power_glink_ulog_dev *l_dev = platform_get_drvdata(pdev);

	if (!l_dev)
		return -ENODEV;

	mutex_destroy(&l_dev->send_lock);
	pmic_glink_unregister_client(l_dev->client);
	g_power_glink_ulog_dev = NULL;
	return 0;
}

static const struct of_device_id power_glink_ulog_match_table[] = {
	{
		.compatible = "huawei,power_glink_ulog",
		.data = NULL,
	},
	{},
};

static struct platform_driver power_glink_ulog_driver = {
	.probe = power_glink_ulog_probe,
	.remove = power_glink_ulog_remove,
	.driver = {
		.name = "huawei,power_glink_ulog",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(power_glink_ulog_match_table),
	},
};

int __init power_glink_ulog_init(void)
{
	return platform_driver_register(&power_glink_ulog_driver);
}

void __exit power_glink_ulog_exit(void)
{
	platform_driver_unregister(&power_glink_ulog_driver);
}

module_init(power_glink_ulog_init);
module_exit(power_glink_ulog_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("power glink ulog module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
