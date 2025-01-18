/* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved. */
#include <securec.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/sysfs.h>
#include <linux/io.h>
#include <ddr/ddr_perf_scene.h>
#include <linux/platform_device.h>
#include <platform_include/basicplatform/linux/ipc_rproc.h>
#include <platform_include/basicplatform/linux/ipc_msg.h>

#define OK	0
#define ERR	(-1)
#define ACK_BUFFER_LEN	8
#define PERF_SCENE_CHAINING_MAGIC	0x1A1213B4
#define MAX_QOS_SWITCH_LEN	10

static struct class *g_ddr_devqos_class;

struct master_qos_switch {
	char npu_qos_switch[MAX_QOS_SWITCH_LEN];
};
struct master_qos_switch g_master_qos_switch = {
	.npu_qos_switch = "OFF",
};

static int send_npu_dmss_pri_info(unsigned int type)
{
	int ret;
	union ipc_data msg;
	rproc_id_t mbx = IPC_ACPU_LPM3_MBX_3;
	rproc_msg_t ack[ACK_BUFFER_LEN] = {0};

	msg.cmd_mix.cmd = CMD_SETTING;
	msg.cmd_mix.cmd_src = OBJ_AP;
	msg.cmd_mix.cmd_obj = OBJ_DDR;
	msg.cmd_mix.cmd_type = TYPE_PERF_SCENE;

	ret = memset_s(msg.cmd_mix.cmd_para, sizeof(msg.cmd_mix.cmd_para), 0, sizeof(msg.cmd_mix.cmd_para));
	if (ret != EOK) {
		pr_err("[%s]memset_s fail[%d]\n", __func__, ret);
		return ERR;
	}

	msg.cmd_mix.cmd_para[0] = type;

	ret = RPROC_SYNC_SEND(mbx, (rproc_msg_t *)&msg, MAX_MAIL_SIZE, ack, ACK_BUFFER_LEN);
	if (ret != 0) {
		pr_err("[%s]send info failed err %d!\n", __func__, ret);
		return ERR;
	}
	pr_info("send_npu_dmss_pri_info RPROC_SYNC_SEND success\n");

	return OK;
}

static ssize_t npu_qos_switch_show(struct class *dev, struct class_attribute *attr, char *buf)
{
	pr_info("%s,%d: show_npu_qos\n",__func__,__LINE__);
	return sprintf_s(buf, MAX_QOS_SWITCH_LEN, "%s\n", g_master_qos_switch.npu_qos_switch);
}

static ssize_t npu_qos_switch_store(struct class *dev, struct class_attribute *attr, const char *buf, size_t len)
{
	if (strlen(buf) >= MAX_QOS_SWITCH_LEN)
		return ERR;

	if (sscanf_s(buf, "%s", g_master_qos_switch.npu_qos_switch, MAX_QOS_SWITCH_LEN) != 1)
		return ERR;

	if (strcmp(g_master_qos_switch.npu_qos_switch, "ON") == 0) {
		send_npu_dmss_pri_info(PERF_SCENE_DL_QOS_ON);
	}
	else if (strcmp(g_master_qos_switch.npu_qos_switch, "OFF") == 0) {
		send_npu_dmss_pri_info(PERF_SCENE_DL_QOS_OFF);
	}

	return len;
}

static struct class_attribute g_ddr_devqos_attrs[] = {
	__ATTR(npu_qos_switch, 0664, npu_qos_switch_show, npu_qos_switch_store),
};

static int32_t create_ddr_devqos_attrs(struct class *cur_class)
{
	int32_t i;
	int32_t ret;

	for (i = 0; (unsigned int)i < (sizeof(g_ddr_devqos_attrs)/sizeof(struct class_attribute)); i++) {
		ret = class_create_file(cur_class, &g_ddr_devqos_attrs[i]);
		if (ret)
			goto error;
	}

	return ret;
error:
	while (--i >= 0)
		class_remove_file(cur_class, &g_ddr_devqos_attrs[i]);
	return ret;
}

static void remove_ddr_devqos_attrs(struct class *cur_class)
{
	uint32_t i;

	for (i = 0; i < (sizeof(g_ddr_devqos_attrs) / sizeof(struct class_attribute)); i++)
		class_remove_file(cur_class, &g_ddr_devqos_attrs[i]);
}

static int ddr_devqos_driver_probe(struct platform_device *pdev)
{
	pr_info("%s,%d: ddr_devqos_driver_probe\n",__func__,__LINE__);
	return OK;
}

static int ddr_devqos_driver_remove(struct platform_device *pdev)
{
	pr_info("%s,%d: ddr_devqos_driver_remove\n",__func__,__LINE__);
	return OK;
}

static struct platform_driver g_ddr_devqos_driver ={
	.probe = ddr_devqos_driver_probe,
	.driver.name = "ddr_devqos",
	.remove = ddr_devqos_driver_remove,
};

static int __init ddr_devqos_init(void)
{
	int ret;

	g_ddr_devqos_class = class_create(THIS_MODULE, "ddr_devqos");
	if (IS_ERR(g_ddr_devqos_class)) {
		pr_err("[%s:%d]: ddr_devqos class creat fail\n", __func__, __LINE__);
		goto CLASS_ERR;
	}

	ret = create_ddr_devqos_attrs(g_ddr_devqos_class);
	if (ret != 0) {
		pr_err("[%s:%d]: ddr_devqos file creat fail\n", __func__, __LINE__);
		goto CLASS_FILE_ERR;
	}

	return platform_driver_register(&g_ddr_devqos_driver);;

CLASS_FILE_ERR:
	class_destroy(g_ddr_devqos_class);
CLASS_ERR:
	return ERR;
}

static void __exit ddr_devqos_exit(void)
{
	remove_ddr_devqos_attrs(g_ddr_devqos_class);
	class_destroy(g_ddr_devqos_class);
	g_ddr_devqos_class = NULL;
	platform_driver_unregister(&g_ddr_devqos_driver);
}

module_init(ddr_devqos_init);
module_exit(ddr_devqos_exit);
MODULE_LICENSE("GPL");