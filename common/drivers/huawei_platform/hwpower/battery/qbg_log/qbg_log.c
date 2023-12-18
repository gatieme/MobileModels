/*
 * qbg_log.c
 *
 * huawei qbg adsp log
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

#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/completion.h>
#include <linux/workqueue.h>
#include <linux/debugfs.h>
#include <linux/timex.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/of.h>
#include <linux/syscalls.h>
#include <linux/platform_device.h>
#include <linux/soc/qcom/pmic_glink.h>
#include <securec.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include "qbg_file.h"

#if IS_ENABLED(HWLOG_TAG)
#undef HWLOG_TAG
#endif
#define HWLOG_TAG huawei_qbg_log
HWLOG_REGIST();

#define QBG_LOG_GLINK_OWNER_HW    32786
#define QBG_TYPE_REQ_RESP         1
#define QBG_DUMP_REQ              0x36

#define MAX_BUF_LEN               4096 /* 4k */
#define QBG_WAIT_TIME_MS          1000
#define QBG_WORK_TIMEOUT          20000 /* get qbg dump log per 20s */

#define QBG_BETA_FILE_PATH_1      "/hw_product/region_comm/china/log_collect_service_beta.xml"
#define QBG_BETA_FILE_PATH_2      "/system/etc/log_collect_service_beta.xml"

struct qbg_log_req_msg {
	struct pmic_glink_hdr hdr;
};

struct qbg_log_rsp_msg {
	struct pmic_glink_hdr hdr;
	u32 length;
	u8 buf[MAX_BUF_LEN];
};

struct qbg_log_device {
	struct device *dev;
	struct pmic_glink_client *client;
	struct completion wait_rsp;
	struct qbg_log_rsp_msg qbg_dump;
	struct mutex lock;
	struct delayed_work dbg_work;
	bool first_work;
	u32 log_size;
	struct qbg_log_file ufile;
};

static void handle_qbg_log_dump_message(struct qbg_log_device *di,
	struct qbg_log_rsp_msg *msg, size_t len)
{
	u32 buf_len;
	int ret;

	if (!di) {
		hwlog_err("%s di is null\n", __func__);
		return;
	}

	if (len >= sizeof(di->qbg_dump)) {
		hwlog_err("incorrect length received: %zu expected: %u\n", len,
			sizeof(di->qbg_dump));
		return;
	}

	buf_len = msg->length;
	if (buf_len > sizeof(di->qbg_dump.buf)) {
		hwlog_err("incorrect buffer length: %u\n", buf_len);
		return;
	}

	ret = memcpy_s(di->qbg_dump.buf, MAX_BUF_LEN, msg->buf, buf_len);
	if (ret)
		hwlog_err("%s memcpy_s failed\n", __func__);

	di->log_size = buf_len;
	hwlog_info("get qbg success size =%u\n", di->log_size);
	complete(&di->wait_rsp);
}

static int qbg_log_glink_callback(void *priv, void *data, size_t len)
{
	struct pmic_glink_hdr *hdr = data;
	struct qbg_log_device *di = priv;

	hwlog_info("owner: %u type: %u opcode: %#x len: %zu\n", hdr->owner,
		hdr->type, hdr->opcode, len);

	switch (hdr->opcode) {
	case QBG_DUMP_REQ:
		handle_qbg_log_dump_message(di, data, len);
		break;
	default:
		hwlog_err("unknown opcode %u\n", hdr->opcode);
		break;
	}

	return 0;
}

static int qbg_log_glink_sync_write(struct qbg_log_device *di, void *data, size_t len)
{
	int rc;

	mutex_lock(&di->lock);
	reinit_completion(&di->wait_rsp);
	rc = pmic_glink_write(di->client, data, len);
	if (!rc) {
		rc = wait_for_completion_timeout(&di->wait_rsp,
			msecs_to_jiffies(QBG_WAIT_TIME_MS));
		if (!rc) {
			hwlog_err("error, timed out sending message\n");
			mutex_unlock(&di->lock);
			return -ETIMEDOUT;
		}
		rc = 0;
	}
	mutex_unlock(&di->lock);

	return rc;
}

static int qbg_log_req_ulog(struct qbg_log_device *di)
{
	struct qbg_log_req_msg msg = { { 0 } };

	msg.hdr.owner = QBG_LOG_GLINK_OWNER_HW;
	msg.hdr.type = QBG_TYPE_REQ_RESP;
	msg.hdr.opcode = QBG_DUMP_REQ;

	return qbg_log_glink_sync_write(di, &msg, sizeof(msg));
}

static bool qbg_log_check_version(struct qbg_log_device *di)
{
	int ret;

	di->first_work = false;
	ret = ksys_access(QBG_BETA_FILE_PATH_1, 0);
	if (!ret) {
		hwlog_info("hw_product path access ok\n");
		return true;
	}

	ret = ksys_access(QBG_BETA_FILE_PATH_2, 0);
	if (!ret) {
		hwlog_info("system path access ok\n");
		return true;
	}

	return false;
}

static void battery_dbg_work(struct work_struct *work)
{
	int ret;
	struct qbg_log_device *di = container_of(work, struct qbg_log_device,
		dbg_work.work);

	if (!di) {
		hwlog_err("%s di is null\n", __func__);
		return;
	}

	if (di->first_work && (!qbg_log_check_version(di))) {
		hwlog_info("no log version\n");
		return;
	}

	ret = qbg_log_req_ulog(di);
	if (!ret) {
		ret = qbg_log_write(&di->ufile, di->qbg_dump.buf, di->log_size);
		if (ret)
			hwlog_err("%s qbg log write fail\n", __func__);
	}

	queue_delayed_work(system_power_efficient_wq, &di->dbg_work,
		msecs_to_jiffies(QBG_WORK_TIMEOUT));
}

static bool qbg_log_normal_mode(void)
{
	if (power_cmdline_is_powerdown_charging_mode() ||
		power_cmdline_is_recovery_mode() ||
		power_cmdline_is_erecovery_mode()) {
		hwlog_info("current mode not support qbg log trace\n");
		return false;
	}

	return true;
}

static int qbg_log_probe(struct platform_device *pdev)
{
	int rc;
	struct qbg_log_device *udi = NULL;
	struct pmic_glink_client_data client_data = { 0 };

	hwlog_info("qbg_log_probe probe\n");
	if (!qbg_log_normal_mode())
		return 0;

	udi = devm_kzalloc(&pdev->dev, sizeof(*udi), GFP_KERNEL);
	if (!udi)
		return -ENOMEM;

	udi->dev = &pdev->dev;
	client_data.id = QBG_LOG_GLINK_OWNER_HW;
	client_data.name = "fg_dump";
	client_data.msg_cb = qbg_log_glink_callback;
	client_data.priv = udi;

	udi->client = pmic_glink_register_client(udi->dev, &client_data);
	if (IS_ERR(udi->client)) {
		rc = PTR_ERR(udi->client);
		if (rc != -EPROBE_DEFER)
			hwlog_err("error in registering with pmic_glink %d\n", rc);
		return rc;
	}

	init_completion(&udi->wait_rsp);
	mutex_init(&udi->lock);
	INIT_DELAYED_WORK(&udi->dbg_work, battery_dbg_work);
	qbg_log_init(&udi->ufile);
	queue_delayed_work(system_power_efficient_wq, &udi->dbg_work, msecs_to_jiffies(QBG_WORK_TIMEOUT));
	udi->first_work = true;
	platform_set_drvdata(pdev, udi);

	return 0;
}

static int qbg_log_remove(struct platform_device *pdev)
{
	int rc;
	struct qbg_log_device *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	rc = pmic_glink_unregister_client(di->client);
	if (rc < 0) {
		hwlog_err("error unregistering from pmic_glink, rc=%d\n", rc);
		return rc;
	}

	return 0;
}

static const struct of_device_id qbg_log_match_table[] = {
	{ .compatible = "huawei,qbg_adsp_log" },
	{},
};

static struct platform_driver qbg_log_driver = {
	.driver = {
		.name = "huawei_qbg_log",
		.owner = THIS_MODULE,
		.of_match_table = qbg_log_match_table,
	},
	.probe = qbg_log_probe,
	.remove = qbg_log_remove,
};
module_platform_driver(qbg_log_driver);

MODULE_LICENSE("GPL v2");
MODULE_IMPORT_NS(VFS_internal_I_am_really_a_filesystem_and_am_NOT_a_driver);
MODULE_DESCRIPTION("huawei qbg log driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
