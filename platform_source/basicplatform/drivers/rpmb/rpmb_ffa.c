/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: rpmb ffa interface for kernel redirect to secure partition
 * Create: 2023-02-07
 */

#include <linux/module.h>
#include <linux/arm_ffa.h>

const struct ffa_ops *g_rpmb_ffa_ops;
struct ffa_device *g_rpmb_ffa_dev;

const struct ffa_device_id rpmb_ffa_device_id[] = {
	/* uuid = <0x165b35eb 0x9a8c475d 0x8810f319 0xe801572b> */
	{0xeb, 0x35, 0x5b, 0x16, 0x5d, 0x47, 0x8c, 0x9a,
	0x19, 0xf3, 0x10, 0x88, 0x2b, 0x57, 0x01, 0xe8},
	{}
};


int rpmb_ffa_send(u64 arg0, u64 arg1, u64 arg2, u64 arg3)
{
	if (g_rpmb_ffa_ops == NULL || g_rpmb_ffa_dev == NULL) {
		pr_err("rpmb:ffa not init\n");
		return -1;
	}

	int ret;
	struct ffa_send_direct_data args = {
		.data0 = arg0,
		.data1 = arg1,
		.data2 = arg2,
		.data3 = arg3,
		.data4 = 0,
	};

	ret = g_rpmb_ffa_ops->sync_send_receive(g_rpmb_ffa_dev, &args);
	if (ret != 0) {
		pr_err("%s:rpmb:sync_send_receive fail:%d\n", __func__, ret);
		return ret;
	}

	return (int)args.data1;
}

static void rpmb_ffa_remove(struct ffa_device *ffa_dev)
{
	pr_err("rpmb:ffa removed\n");
}

static int rpmb_ffa_probe(struct ffa_device *ffa_dev)
{
	g_rpmb_ffa_ops = ffa_dev->ops;
	g_rpmb_ffa_dev = ffa_dev;
	if (g_rpmb_ffa_ops == NULL) {
		pr_err("%s:rpmb:fail to get ffa_ops\n", __func__);
		return -ENOENT;
	}

	g_rpmb_ffa_ops->mode_32bit_set(ffa_dev);
	pr_info("rpmb:ffa probe OK!\n");
	return 0;
}

static struct ffa_driver rpmb_ffa_driver = {
	.name = "RPMB_FFA",
	.probe = rpmb_ffa_probe,
	.remove = rpmb_ffa_remove,
	.id_table = rpmb_ffa_device_id,
};

static int rpmb_ffa_init(void)
{
	pr_info("rpmb ffa init\n");
	return ffa_register(&rpmb_ffa_driver);
}
#ifdef CONFIG_RPMB_FFA_SUPPORT
module_init(rpmb_ffa_init);
#endif
