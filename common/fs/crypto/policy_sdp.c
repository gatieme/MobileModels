/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: Implementation of 1) sdp context inherit;
 *                                2) set/get sdp and dps context.
 * Create: 2021-05-21
 */

#include <keys/user-type.h>
#include <linux/printk.h>
#include <linux/mount.h>
#include <securec.h>
#include "fscrypt_private.h"
#include "sdp_internal.h"
#include "keyinfo_sdp.h"

#define FSCRYPT_POLICY_FLAGS_VALID 0x0F

#ifdef CONFIG_HWDPS
#include <huawei_platform/hwdps/hwdps_fs_hooks.h>
#include <huawei_platform/hwdps/hwdps_limits.h>
#endif

/* sdp crypto policy for f2fs */
struct fscrypt_sdp_policy {
	__u8 version;
	__u8 sdp_class;
	__u8 contents_encryption_mode;
	__u8 filenames_encryption_mode;
	__u8 flags;
	__u8 master_key_descriptor[FSCRYPT_KEY_DESCRIPTOR_SIZE];
} __packed;

/* crypto policy type for f2fs */
struct fscrypt_policy_type {
	__u8 version;
	__u8 encryption_type;
	__u8 contents_encryption_mode;
	__u8 filenames_encryption_mode;
	__u8 master_key_descriptor[FSCRYPT_KEY_DESCRIPTOR_SIZE];
} __packed;

#ifdef CONFIG_HWDPS
#define RESERVED_DATA_LEN 8

/* dps crypto policy for f2fs */
struct fscrypt_dps_policy {
	__u8 version;
	__u8 reserved[RESERVED_DATA_LEN];
} __packed;
#endif

static inline bool f2fs_inode_is_config_encryption(struct inode *inode)
{
	if (!inode->i_sb->s_cop->get_context)
		return false;

	return (inode->i_sb->s_cop->get_context(inode, NULL, 0L) > 0);
}

static void set_sdp_context_from_policy(struct sdp_fscrypt_context *sdp_ctx,
	const struct fscrypt_sdp_policy *policy)
{
	sdp_ctx->format = FS_ENCRYPTION_CONTEXT_FORMAT_V2;
	(void)memcpy_s(sdp_ctx->master_key_descriptor,
		sizeof(sdp_ctx->master_key_descriptor),
		policy->master_key_descriptor,
		sizeof(policy->master_key_descriptor));
	sdp_ctx->contents_encryption_mode = policy->contents_encryption_mode;
	sdp_ctx->filenames_encryption_mode = policy->filenames_encryption_mode;
	sdp_ctx->flags = policy->flags;
	sdp_ctx->sdp_class = policy->sdp_class;
	sdp_ctx->version = policy->version;
}

static bool fscrypt_valid_enc_modes(u32 contents_mode, u32 filenames_mode)
{
	if (contents_mode == FSCRYPT_MODE_AES_256_XTS &&
	    filenames_mode == FSCRYPT_MODE_AES_256_CTS)
		return true;

	if (contents_mode == FSCRYPT_MODE_AES_128_CBC &&
	    filenames_mode == FSCRYPT_MODE_AES_128_CTS)
		return true;

	if (contents_mode == FSCRYPT_MODE_ADIANTUM &&
	    filenames_mode == FSCRYPT_MODE_ADIANTUM)
		return true;

	return false;
}

static int check_policy_valid(const struct fscrypt_sdp_policy *policy)
{
	if ((policy->sdp_class != FSCRYPT_SDP_ECE_CLASS) &&
		(policy->sdp_class != FSCRYPT_SDP_SECE_CLASS)) {
		pr_err("%s: class err %x\n", __func__, policy->sdp_class);
		return -EINVAL;
	}

	if (!fscrypt_valid_enc_modes(policy->contents_encryption_mode,
		policy->filenames_encryption_mode)) {
		pr_err("%s modes invalid content %x, file %x\n",
			__func__, policy->contents_encryption_mode,
			policy->filenames_encryption_mode);
		return -EINVAL;
	}

	if ((policy->flags & ~FSCRYPT_POLICY_FLAGS_VALID) != 0) {
		pr_err("%s flags is err %x\n", __func__, policy->flags);
		return -EINVAL;
	}
	return 0;
}

static int f2fs_create_sdp_encryption_context_from_policy(struct inode *inode,
	const struct fscrypt_sdp_policy *policy)
{
	int res;
	struct sdp_fscrypt_context sdp_ctx = {0};

	res = check_policy_valid(policy);
	if (res != 0)
		return res;
	if (S_ISREG(inode->i_mode) && (inode->i_crypt_info) &&
		i_size_read(inode)) {
		pr_err("%s: inode:%lu the file is not null in FBE,"
			"can not set sdp!\n", __func__, inode->i_ino);
		return -EINVAL;
	}

	if (S_ISREG(inode->i_mode)) {
		res = f2fs_inode_check_sdp_keyring(
			(const u8 *)policy->master_key_descriptor,
			NULL, 0, NO_NEED_TO_CHECK_KEYFING);
		if (res != 0)
			return res;
	}
	set_sdp_context_from_policy(&sdp_ctx, policy);
	res = inode->i_sb->s_cop->set_sdp_context(inode, &sdp_ctx,
		sizeof(sdp_ctx), NULL);
	if (res != 0) {
		pr_err("%s: inode:%lu, set sdp ctx failed res:%d\n",
			__func__, inode->i_ino, res);
		return res;
	}

	if (policy->sdp_class == FSCRYPT_SDP_ECE_CLASS)
		res = f2fs_inode_set_sdp_encryption_flags(inode, NULL,
			F2FS_XATTR_SDP_ECE_CONFIG_FLAG);
	else
		res = f2fs_inode_set_sdp_encryption_flags(inode, NULL,
			F2FS_XATTR_SDP_SECE_CONFIG_FLAG);
	if (res != 0)
		pr_err("%s: inode:%lu set sdp config flags failed res:%d\n",
			__func__, inode->i_ino, res);

	if (S_ISREG(inode->i_mode) && !res && (inode->i_crypt_info))
		res = f2fs_change_to_sdp_crypto(inode, NULL,
			policy->sdp_class);

	return res;
}

static bool f2fs_is_sdp_context_consistent_with_policy(struct inode *inode,
	const struct fscrypt_sdp_policy *policy)
{
	int res;
	struct sdp_fscrypt_context ctx = {0};

	if (!inode->i_sb->s_cop->get_sdp_context)
		return false;

	res = inode->i_sb->s_cop->get_sdp_context(inode,
		&ctx, sizeof(ctx), NULL);
	if (res != sizeof(ctx))
		return false;

	res = memcmp(ctx.master_key_descriptor, policy->master_key_descriptor,
		FSCRYPT_KEY_DESCRIPTOR_SIZE) == 0;

	res = res && (ctx.sdp_class == policy->sdp_class) &&
		(ctx.flags == policy->flags);

	res = res && (ctx.contents_encryption_mode ==
		policy->contents_encryption_mode);

	res = res && (ctx.filenames_encryption_mode ==
		policy->filenames_encryption_mode);

	return res;
}

int fscrypt_ioctl_set_sdp_policy(struct file *filp,
	const void __user *arg)
{
	int res;
	u32 flag;
	struct fscrypt_sdp_policy policy = {0};
	struct inode *inode = NULL;

	if (!filp || !arg) {
		pr_err("%s set policy invalid param\n", __func__);
		return -EINVAL;
	}

	inode = file_inode(filp);
	if (!inode_owner_or_capable(inode))
		return -EACCES;

	if (copy_from_user(&policy, arg, sizeof(policy)) != 0)
		return -EFAULT;

	if (policy.version != 0)
		return -EINVAL;

	res = mnt_want_write_file(filp);
	if (res != 0) {
		pr_err("%s mnt write failed ret:%d\n", __func__, res);
		return res;
	}

	inode_lock(inode);
	(void)inode->i_sb->s_cop->operate_sdp_lock(inode, 0); /* 0 for lock */
	res = f2fs_inode_get_sdp_encrypt_flags(inode, NULL, &flag);
	if (res != 0) {
		pr_err("%s get flag failed res %d\n", __func__, res);
		goto err;
	}

	if (!f2fs_inode_is_config_encryption(inode)) {
		pr_err("%s is not config!\n", __func__);
		res = -EINVAL;
	} else if (!f2fs_inode_is_config_sdp_encryption(flag)) {
		res = f2fs_create_sdp_encryption_context_from_policy(inode,
			&policy);
	} else if (!f2fs_is_sdp_context_consistent_with_policy(inode,
		&policy)) {
		pr_warn("%s: Policy inconsistent with sdp context\n",
			__func__);
		res = -EINVAL;
	}
err:
	(void)inode->i_sb->s_cop->operate_sdp_lock(inode, 1); /* 1 for unlock */
	inode_unlock(inode);
	mnt_drop_write_file(filp);
	return res;
}

int fscrypt_ioctl_get_sdp_policy(struct file *filp,
	void __user *arg)
{
	int res;
	struct sdp_fscrypt_context ctx = {0};
	struct fscrypt_sdp_policy policy = {0};
	struct inode *inode = NULL;

	if (!filp || !arg) {
		pr_err("%s get policy invalid param\n", __func__);
		return -EINVAL;
	}

	inode = file_inode(filp);
	if (!inode->i_sb->s_cop->get_sdp_context) {
		pr_err("%s get context is null\n", __func__);
		return -ENODATA;
	}

	res = inode->i_sb->s_cop->get_sdp_context(inode,
		&ctx, sizeof(ctx), NULL);
	if (res != sizeof(ctx)) {
		pr_err("%s get sdp context failed, res:%d\n", __func__, res);
		return -ENODATA;
	}

	if (ctx.format != FS_ENCRYPTION_CONTEXT_FORMAT_V2) {
		pr_err("%s format is err %x\n", __func__, ctx.format);
		return -EINVAL;
	}

	policy.version = ctx.version;
	policy.sdp_class = ctx.sdp_class;
	policy.contents_encryption_mode = ctx.contents_encryption_mode;
	policy.filenames_encryption_mode = ctx.filenames_encryption_mode;
	policy.flags = ctx.flags;
	(void)memcpy_s(policy.master_key_descriptor,
		FSCRYPT_KEY_DESCRIPTOR_SIZE,
		ctx.master_key_descriptor, FSCRYPT_KEY_DESCRIPTOR_SIZE);

	if (copy_to_user(arg, &policy, sizeof(policy)) != 0)
		return -EFAULT;

	return 0;
}

static int fill_encryption_type(struct inode *inode, struct fscrypt_policy_type *policy_type)
{
	int res;
	u32 flags = 0;

	res = inode->i_sb->s_cop->get_sdp_encrypt_flags(inode, NULL, &flags);
	if (res != 0) {
		pr_err("%s get flags failed res:%d\n", __func__, res);
		return res;
	}
	if ((flags & F2FS_XATTR_SDP_ECE_ENABLE_FLAG) != 0)
		policy_type->encryption_type = FSCRYPT_SDP_ECE_CLASS;
	else if ((flags & F2FS_XATTR_SDP_SECE_ENABLE_FLAG) != 0)
		policy_type->encryption_type = FSCRYPT_SDP_SECE_CLASS;
#ifdef CONFIG_HWDPS
	else if ((flags & F2FS_XATTR_DPS_ENABLE_FLAG) != 0)
		policy_type->encryption_type = FSCRYPT_DPS_CLASS;
#endif
	else
		policy_type->encryption_type = FSCRYPT_CE_CLASS;
	return 0;
}

static int set_encryption_type_from_policy(struct inode *inode,
	const union fscrypt_policy *ci_policy,
	struct fscrypt_policy_type *policy_type)
{
	int res;
	u32 flags;

	if (ci_policy->version != FSCRYPT_POLICY_V2)
		return -EINVAL;

	policy_type->contents_encryption_mode =
		fscrypt_policy_contents_mode(ci_policy);
	policy_type->filenames_encryption_mode =
		fscrypt_policy_fnames_mode(ci_policy);
	policy_type->version = 0;

	(void)memcpy_s(policy_type->master_key_descriptor,
		sizeof(policy_type->master_key_descriptor),
		ci_policy->v2.master_key_identifier, FSCRYPT_KEY_DESCRIPTOR_SIZE);
	policy_type->encryption_type = FSCRYPT_CE_CLASS;

	res = fill_encryption_type(inode, policy_type);
	if (res == -EOPNOTSUPP)
		res = 0;
	return res;
}

static int set_encryption_type_from_context_inner(struct inode *inode,
	struct fscrypt_policy_type *policy_type, struct sdp_fscrypt_context *sdp_ctx)
{
	int res;

	res = fill_encryption_type(inode, policy_type);
	if (res == -EOPNOTSUPP)
		return 0;
	if (res != 0)
		return res;

	policy_type->contents_encryption_mode = sdp_ctx->contents_encryption_mode;
	policy_type->filenames_encryption_mode = sdp_ctx->filenames_encryption_mode;
	policy_type->version = 0;
	(void)memcpy_s(policy_type->master_key_descriptor,
		sizeof(policy_type->master_key_descriptor),
		sdp_ctx->master_key_descriptor,
		sizeof(sdp_ctx->master_key_descriptor));
	return 0;
}

static int set_encryption_type_from_context(struct inode *inode,
	struct fscrypt_policy_type *policy_type)
{
	int res;
	struct sdp_fscrypt_context sdp_ctx = {0};
	union fscrypt_context ctx = {0};

	if (!inode->i_sb->s_cop->get_context) {
		pr_err("%s get context failed");
		return -EINVAL;
	}
	res = inode->i_sb->s_cop->get_context(inode, &ctx, sizeof(union fscrypt_context));
	if (res != sizeof(union fscrypt_context)) {
		pr_err("%s get_context failed, res:%d", __func__, res);
		return -EINVAL;
	}
	policy_type->version = ctx.version;
	policy_type->encryption_type = FSCRYPT_CE_CLASS;
	policy_type->contents_encryption_mode = ctx.v2.contents_encryption_mode;
	policy_type->filenames_encryption_mode = ctx.v2.filenames_encryption_mode;
	(void)memcpy_s(policy_type->master_key_descriptor, sizeof(policy_type->master_key_descriptor),
		ctx.v2.master_key_identifier, FSCRYPT_KEY_DESCRIPTOR_SIZE);

	if (!inode->i_sb->s_cop->get_sdp_context) {
		pr_info("%s not support sdp context", __func__);
		return 0;
	}

	res = inode->i_sb->s_cop->get_sdp_context(inode,
		&sdp_ctx, sizeof(struct sdp_fscrypt_context), NULL);
	if (res != sizeof(struct sdp_fscrypt_context)) {
		pr_info("%s not sdp context", __func__);
		return 0;
	}

	return set_encryption_type_from_context_inner(inode, policy_type, &sdp_ctx);
}

int fscrypt_ioctl_get_policy_type(struct file *filp,
	void __user *arg)
{
	int res;
	struct inode *inode = NULL;
	struct fscrypt_info *ci = NULL;
	struct fscrypt_policy_type policy_type = {0};
	const union fscrypt_policy *ci_policy = NULL;

	if (!filp || !arg) {
		pr_err("%s invalid param\n", __func__);
		return -EINVAL;
	}

	inode = file_inode(filp);
	ci = inode->i_crypt_info;
	if (ci) {
		ci_policy = &ci->ci_policy;
		res = set_encryption_type_from_policy(inode, ci_policy, &policy_type);
		if (res != 0)
			pr_err("%s set_encryption_type_from_policy failed, res:%d", __func__, res);
	} else {
		res = set_encryption_type_from_context(inode, &policy_type);
		if (res != 0)
			pr_err("%s set_encryption_type_from_context failed, res:%d", __func__, res);
	}
out:
	if (copy_to_user(arg, &policy_type, sizeof(policy_type)) != 0)
		return -EFAULT;

	return res;
}

int fscrypt_sdp_crypt_inherit(struct inode *parent, struct inode *child,
	void *dpage, void *fs_data)
{
	int res;
	struct sdp_fscrypt_context sdp_ctx = {0};
	char *sdp_mkey_desc = NULL;

	if (!parent || !child || !fs_data) {
		pr_err("%s invalid param\n", __func__);
		return -EINVAL;
	}

	res = parent->i_sb->s_cop->get_sdp_context(parent, &sdp_ctx,
		sizeof(sdp_ctx), dpage);
	if (res != sizeof(sdp_ctx))
		return 0;
	(void)parent->i_sb->s_cop->operate_sdp_lock(child, 0); /* 0 for lock */
	res = parent->i_sb->s_cop->set_sdp_context(child, &sdp_ctx,
		sizeof(sdp_ctx), fs_data);
	if (res != 0)
		goto out;
	if (sdp_ctx.sdp_class == FSCRYPT_SDP_ECE_CLASS) {
		res = f2fs_inode_set_sdp_encryption_flags(child, fs_data,
			F2FS_XATTR_SDP_ECE_CONFIG_FLAG);
		if (res == 0 && child->i_crypt_info && !S_ISREG(child->i_mode))
			child->i_crypt_info->ci_hw_enc_flag = F2FS_XATTR_SDP_ECE_CONFIG_FLAG;
	}
	else if (sdp_ctx.sdp_class == FSCRYPT_SDP_SECE_CLASS) {
		/* SECE can not be enable at the first time */
		res = f2fs_inode_set_sdp_encryption_flags(child, fs_data,
			F2FS_XATTR_SDP_SECE_CONFIG_FLAG);
		if (res == 0 && child->i_crypt_info && !S_ISREG(child->i_mode))
			child->i_crypt_info->ci_hw_enc_flag = F2FS_XATTR_SDP_SECE_CONFIG_FLAG;
	}
	else
		res = -EOPNOTSUPP;
	if (res != 0)
		pr_err("%s failed, res:%d\n", __func__, res);
out:
	(void)parent->i_sb->s_cop->operate_sdp_lock(child, 1); /* 1 for unlock */
	return res;
}

#ifdef CONFIG_HWDPS
static int check_inode_flag(struct inode *inode)
{
	int res;
	u32 flags;

	res = inode->i_sb->s_cop->get_hwdps_flags(inode, NULL, &flags);
	if (res != 0) {
		pr_err("%s get_sdp_encrypt_flags err = %d\n", __func__, res);
		return -EFAULT;
	}

	if ((flags & HWDPS_XATTR_ENABLE_FLAG) != 0) {
		pr_err("%s has flag, no need to set again\n", __func__);
		return -EEXIST;
	}

	if (f2fs_inode_is_sdp_encrypted(flags)) {
		pr_err("%s has sdp flag, fialed to set dps flag\n", __func__);
		return -EFAULT;
	}
	return 0;
}

static int set_dps_policy_inner(struct file *filp, struct inode *inode)
{
	int ret;

	ret = mnt_want_write_file(filp);
	if (ret != 0) {
		pr_err("f2fs_dps mnt_want_write_file erris %d\n", ret);
		return ret;
	}

	inode_lock(inode);
	ret = check_inode_flag(inode);
	if (ret == -EEXIST) {
		ret = 0;
		goto err;
	}
	if (ret != 0)
		goto err;

	ret = f2fs_set_hwdps_enable_flags(inode, NULL);
	if (ret != 0)
		goto err;
	/* just set hw_enc_flag for regular file */
	if (S_ISREG(inode->i_mode) && inode->i_crypt_info)
		inode->i_crypt_info->ci_hw_enc_flag |= HWDPS_XATTR_ENABLE_FLAG;
err:
	inode_unlock(inode);
	mnt_drop_write_file(filp);
	return ret;
}

int fscrypt_ioctl_set_dps_policy(struct file *filp,
	const void __user *arg)
{
	struct fscrypt_dps_policy policy = {0};
	struct inode *inode = NULL;

	if (!filp || !arg) {
		pr_err("%s invalid param\n", __func__);
		return -EINVAL;
	}

	inode = file_inode(filp);
	if (!inode_owner_or_capable(inode)) {
		pr_err("%s inode_owner_or_capable\n", __func__);
		return -EACCES;
	}

	if (copy_from_user(&policy, arg, sizeof(policy)) != 0) {
		pr_err("%s copy_from_user\n", __func__);
		return -EFAULT;
	}

	if (policy.version != 0) {
		pr_err("%s policy.version : %u\n", __func__, policy.version);
		return -EINVAL;
	}

	return set_dps_policy_inner(filp, inode);
}
#endif
