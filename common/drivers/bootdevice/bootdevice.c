#include <linux/bootdevice.h>
#include <linux/bootconfig.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/setup.h>
#include <linux/slab.h>
#include <linux/version.h>

#define ANDROID_BOOT_DEV_MAX 50
static char android_boot_dev[ANDROID_BOOT_DEV_MAX];

#if !(LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static char *saved_boot_config;

/* Rest size of buffer */
#define rest(dst, end) ((end) > (dst) ? (end) - (dst) : 0)

/* Return the needed total length if @size is 0 */
static int __init copy_xbc_key_value_list(char *dst, size_t size)
{
	struct xbc_node *leaf, *vnode;
	char *key, *end = dst + size;
	const char *val;
	char q;
	int ret = 0;

	key = kzalloc(XBC_KEYLEN_MAX, GFP_KERNEL);

	xbc_for_each_key_value(leaf, val) {
		ret = xbc_node_compose_key(leaf, key, XBC_KEYLEN_MAX);
		if (ret < 0)
			break;
		ret = snprintf(dst, rest(dst, end), "%s=", key);
		if (ret < 0)
			break;
		dst += ret;
		vnode = xbc_node_get_child(leaf);
		if (vnode) {
			xbc_array_for_each_value(vnode, val) {
				if (strchr(val, '"'))
					q = '\'';
				else
					q = '"';
				ret = snprintf(dst, rest(dst, end), "%s%c",
					val, ' ');
				if (ret < 0)
					goto out;
				dst += ret;
			}
		} else {
			ret = snprintf(dst, rest(dst, end), "\"\"");
			if (ret < 0)
				break;
			dst += ret;
		}
	}
out:
	kfree(key);

	return ret < 0 ? ret : dst - (end - size);
}

static int get_bootconfig(void)
{
	int len = -1;

	len = copy_xbc_key_value_list(NULL, 0);
	if (len < 0) {
		goto out;
	}

	if (len > 0) {
		saved_boot_config = kzalloc(len + 1, GFP_KERNEL);
		if (!saved_boot_config)
			return -ENOMEM;

		len = copy_xbc_key_value_list(saved_boot_config, len + 1);
		if (len < 0) {
			kfree(saved_boot_config);
			goto out;
		}
	}

out:
	return len;
}
#endif

static int  get_android_boot_dev(void)
{
	int ret = 0;
	int len;
	char *p1 = NULL;
	char *p2 = NULL;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	p1 = strnstr(saved_command_line, "androidboot.bootdevice=",
		COMMAND_LINE_SIZE);
#else
	len = get_bootconfig();
	if (len < 0) {
		ret = -1;
		return ret;
	}
	p1 = strnstr(saved_boot_config, "androidboot.bootdevice=",
		COMMAND_LINE_SIZE);
#endif
	if (p1 == NULL) {
		ret = -1;
		return ret;
	}

	p2 = strnchr(p1, strlen(p1), ' ');
	if (p2 == NULL) {
		ret = -1;
		return ret;
	}

	strlcpy(android_boot_dev, p1,
		((p2 - p1 + 1) > ANDROID_BOOT_DEV_MAX) ?
			ANDROID_BOOT_DEV_MAX : (p2 - p1 + 1));

	return ret;
}

static int get_bootdevice_type_from_cmdline(void)
{
	int type;

	if (strnstr(android_boot_dev, "sdhci", ANDROID_BOOT_DEV_MAX))
		type = 0;
	else if (strnstr(android_boot_dev, "ufshc", ANDROID_BOOT_DEV_MAX))
		type = 1;
	else
		type = -1;

	return type;
}
static int __init bootdevice_init(void)
{
	int err;
	enum bootdevice_type type;

	if (get_android_boot_dev()) {
		type = -1;
		err = -ENODEV;
		goto out;
	}

	type = get_bootdevice_type_from_cmdline();
	if (type == -1) {
		err = -ENODEV;
		goto out;
	}
	pr_info("storage bootdevice: %s\n",
		type == BOOT_DEVICE_EMMC ? "eMMC" : "UFS");

	err = 0;

out:
	set_bootdevice_type(type);
	return err;
}
arch_initcall(bootdevice_init);
