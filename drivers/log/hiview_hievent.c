/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2020. All rights reserved.
 * Description: hievent drivers for kernel
 * Author: xiaocong
 * Create: 2019-10-17
 */

#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/version.h>
#include <linux/vmalloc.h>

#include <log/log_exception.h>
#include <log/hw_log.h>
#include <securec.h>

#define INT_TYPE_MAX_LEN 22

#define MAX_PATH_NUMBER  10
#define MAX_PATH_LEN     256
#define MAX_STR_LEN      (10 * 1024)

/* 64K is max length of /dev/hwlog_exception */
#define EVENT_INFO_BUF_LEN      (16 * 1024)
#define EVENT_INFO_PACK_BUF_LEN (16 * 1024)

/*
 * Max number of tags.
 */
#define MAX_TAG_LEN 10

/*
 * Max bufer len of tags string.
 */
#define TAG_VALUE_BUF_LEN 512

/*
 * Key of tag.
 */
#define DIAGNOSTIC_KEY_TAG "_Tag"


#define HWLOG_TAG hiview_hievent
HILOG_REGIST();

#define BUF_POINTER_FORWARD                              \
	do {                                             \
		if (tmp_len >= 0 && tmp_len < len) {     \
			tmp += tmp_len;                  \
			len -= tmp_len;                  \
		} else {                                 \
			hilog_err("string over length"); \
			tmp += len;                      \
			len = 0;                         \
		}                                        \
	} while (0)

struct hiview_hievent_payload;
struct hiview_hievent_payload {
	char *key;
	char *value;
	struct hiview_hievent_payload *next;
};

/* hievent struct */
struct hiview_hievent {
	unsigned int event_id;
	long long time;
	/* payload linked list */
	struct hiview_hievent_payload *head;
	/* file path needs uploaded */
	char *file_path[MAX_PATH_NUMBER];
};

static int hiview_hievent_convert_string(struct hiview_hievent *event, char **buf_ptr);

static struct hiview_hievent_payload *hiview_hievent_payload_create(void);

static void hiview_hievent_payload_destroy(struct hiview_hievent_payload *payload);

static struct hiview_hievent_payload *hiview_hievent_get_payload(struct hiview_hievent_payload *head, const char *key);

static void hiview_hievent_add_payload(struct hiview_hievent *event, struct hiview_hievent_payload *payload);

static struct hiview_hievent_payload *hiview_hievent_payload_create(void)
{
	struct hiview_hievent_payload *payload = NULL;

	payload = vmalloc(sizeof(*payload));
	if (!payload)
		return NULL;
	payload->key = NULL;
	payload->value = NULL;
	payload->next = NULL;

	return payload;
}

static void hiview_hievent_payload_destroy(struct hiview_hievent_payload *payload)
{
	if (!payload)
		return;
	if (payload->value)
		vfree(payload->value);
	kfree(payload->key);
	vfree(payload);
}

static struct hiview_hievent_payload *hiview_hievent_get_payload(struct hiview_hievent_payload *head, const char *key)
{
	struct hiview_hievent_payload *payload = head;

	while (payload) {
		if (key && payload->key) {
			if (strcmp(payload->key, key) == 0)
				return payload;
		}
		payload = payload->next;
	}

	return NULL;
}

static void hiview_hievent_add_payload(struct hiview_hievent *event, struct hiview_hievent_payload *payload)
{
	if (!event->head) {
		event->head = payload;
	} else {
		struct hiview_hievent_payload *temp = event->head;

		while (temp->next)
			temp = temp->next;
		temp->next = payload;
	}
}

struct hiview_hievent *hiview_hievent_create(unsigned int event_id)
{
	struct hiview_hievent *event = NULL;

	/* combined event obj struct */
	event = vmalloc(sizeof(*event));
	if (!event)
		return NULL;

	if (memset_s(event, sizeof(*event), 0, sizeof(*event)) != EOK) {
		vfree(event);
		return NULL;
	}

	event->event_id = event_id;
	hilog_info("%s : %u", __func__, event_id);

	return (void *)event;
}
EXPORT_SYMBOL(hiview_hievent_create);

int hiview_hievent_put_integral(struct hiview_hievent *event, const char *key, long long value)
{
	struct hiview_hievent_payload *payload = NULL;

	if ((!event) || (!key)) {
		hilog_err("Bad input event or key for %s", __func__);
		return -EINVAL;
	}

	payload = hiview_hievent_get_payload(event->head, key);
	if (!payload) {
		payload = hiview_hievent_payload_create();
		if (!payload)
			return -ENOMEM;
		payload->key = kstrdup(key, GFP_ATOMIC);
		hiview_hievent_add_payload(event, payload);
	}
	if (payload->value)
		vfree(payload->value);
	payload->value = vmalloc(INT_TYPE_MAX_LEN);
	if (!payload->value)
		return -ENOMEM;
	if (memset_s(payload->value, INT_TYPE_MAX_LEN, 0, INT_TYPE_MAX_LEN) != EOK)
		return -ENOMEM;
	if (snprintf_s(payload->value, INT_TYPE_MAX_LEN, INT_TYPE_MAX_LEN - 1, "%lld", value) < 0)
		return -ENOMEM;

	return 0;
}
EXPORT_SYMBOL(hiview_hievent_put_integral);

int hiview_hievent_put_string(struct hiview_hievent *event, const char *key, const char *value)
{
	struct hiview_hievent_payload *payload = NULL;
	int len;

	if ((!event) || (!key) || (!value)) {
		hilog_err("Bad key for %s", __func__);
		return -EINVAL;
	}

	payload = hiview_hievent_get_payload(event->head, key);
	if (!payload) {
		payload = hiview_hievent_payload_create();
		if (!payload)
			return -ENOMEM;
		payload->key = kstrdup(key, GFP_ATOMIC);
		hiview_hievent_add_payload(event, payload);
	}
	if (payload->value)
		vfree(payload->value);
	len = strlen(value);
	/* prevent length larger than MAX_STR_LEN */
	if (len > MAX_STR_LEN)
		len = MAX_STR_LEN;
	payload->value = vmalloc(len + 1);
	if (!payload->value)
		return -ENOMEM;
	if (memset_s(payload->value, len + 1, 0, len + 1) != EOK)
		return -ENOMEM;
	if (strncpy_s(payload->value, len + 1, value, len) != EOK)
		return -ENOMEM;

	payload->value[len] = '\0';

	return 0;
}
EXPORT_SYMBOL(hiview_hievent_put_string);

int hiview_hievent_set_time(struct hiview_hievent *event, long long seconds)
{
	if ((!event) || (seconds == 0)) {
		hilog_err("Bad input for %s", __func__);
		return -EINVAL;
	}
	event->time = seconds;
	return 0;
}
EXPORT_SYMBOL(hiview_hievent_set_time);

static int append_array_item(char **pool, int pool_len, const char *path)
{
	int i;

	if ((!path) || (path[0] == 0)) {
		hilog_err("Bad path %s", __func__);
		return -EINVAL;
	}

	if (strlen(path) > MAX_PATH_LEN) {
		hilog_err("file path over max: %d", MAX_PATH_LEN);
		return -EINVAL;
	}

	for (i = 0; i < pool_len; i++) {
		if (pool[i] != 0)
			continue;
		pool[i] = kstrdup(path, GFP_ATOMIC);
		break;
	}

	if (i == MAX_PATH_NUMBER) {
		hilog_err("Too many pathes");
		return -EINVAL;
	}

	return 0;
}

int hiview_hievent_add_file_path(struct hiview_hievent *event, const char *path)
{
	if (!event) {
		hilog_err("Bad path %s", __func__);
		return -EINVAL;
	}
	return append_array_item(event->file_path, MAX_PATH_NUMBER, path);
}
EXPORT_SYMBOL(hiview_hievent_add_file_path);

int hiview_hievent_set_tag(struct hiview_hievent *event,  const char *value)
{
	if ((!event) || (!value)) {
		hilog_err("Bad event or value %s", __func__);
		return -EINVAL;
	}

	return hiview_hievent_put_string(event, DIAGNOSTIC_KEY_TAG, value);
}
EXPORT_SYMBOL(hiview_hievent_set_tag);

int hiview_hievent_set_tag_array(struct hiview_hievent *event, const char *value_array[], int tag_num)
{
	int ret;
	int tempi;
	int len;
	char *buf = NULL;
	char *tmp = NULL;
	int tmp_len = 0;

	if ((!event) || (!value_array)) {
		hilog_err("Bad input event or value_array for %s", __func__);
		return -EINVAL;
	}

	if (tag_num > MAX_TAG_LEN || tag_num == 0) {
		hilog_err("Tag num over max: %d or is zero", MAX_TAG_LEN);
		return -EINVAL;
	}

	buf = vmalloc(TAG_VALUE_BUF_LEN);
	if (!buf) {
		return -ENOMEM;
	}

	if (memset_s(buf, TAG_VALUE_BUF_LEN, 0, TAG_VALUE_BUF_LEN) != EOK) {
		vfree(buf);
		return -ENOMEM;
	}

	len = TAG_VALUE_BUF_LEN - 1;
	tmp = buf;
	for (tempi = 0; tempi < tag_num; tempi++) {
		if (!value_array[tempi]) {
			break;
		}
		if (tmp_len > 0) {
			tmp_len = snprintf_s(tmp, len + 1, len, "&");
			BUF_POINTER_FORWARD;
		}
		tmp_len = snprintf_s(tmp, len + 1, len, "%s", value_array[tempi]);
		BUF_POINTER_FORWARD;
	}
	buf[TAG_VALUE_BUF_LEN - 1] = '\0';
	ret = hiview_hievent_put_string(event, DIAGNOSTIC_KEY_TAG, buf);
	vfree(buf);
	return ret;
}
EXPORT_SYMBOL(hiview_hievent_set_tag_array);

/*
 * make string ":" to "::", ";" to ";;", and remove newline character
 * for example: "abc:def;ghi" transfer to "abc::def;;ghi"
 */
static char *make_regular(char *value)
{
	int count = 0;
	int len = 0;
	char *temp = value;
	char *regular = NULL;
	char *regular_temp = NULL;

	while (*temp != '\0') {
		if (*temp == ':')
			count++;
		else if (*temp == ';')
			count++;
		else if ((*temp == '\n') || (*temp == '\r'))
			*temp = ' ';
		temp++;
		len++;
	}

	/* no need to transfer, just return old value */
	if (count == 0)
		return value;
	regular = vmalloc(len + count * 2 + 1);
	if (!regular)
		return NULL;
	if (memset_s(regular, len + count * 2 + 1, 0, len + count * 2 + 1) != EOK) {
		vfree(regular);
		return NULL;
	}
	regular_temp = regular;
	temp = value;
	while (*temp != 0) {
		if ((*temp == ':') || (*temp == ';'))
			*regular_temp++ = *temp;
		*regular_temp++ = *temp;
		temp++;
	}
	*regular_temp = '\0';

	return regular;
}

static int hiview_hievent_convert_string(struct hiview_hievent *event, char **buf_ptr)
{
	int len;
	char *tmp = NULL;
	int tmp_len;
	unsigned int i;
	unsigned int key_count;
	struct hiview_hievent_payload *payload = NULL;

	char *buf = vmalloc(EVENT_INFO_BUF_LEN);
	if (!buf) {
		*buf_ptr = NULL;
		return 0;
	}
	if (memset_s(buf, EVENT_INFO_BUF_LEN, 0, EVENT_INFO_BUF_LEN) != EOK) {
		vfree(buf);
		*buf_ptr = NULL;
		return 0;
	}

	len = EVENT_INFO_BUF_LEN - 1;
	tmp = buf;

	/* fill event_id */
	tmp_len = snprintf_s(tmp, len + 1, len, "eventid %d", event->event_id);
	BUF_POINTER_FORWARD;

	/* fill the path */
	for (i = 0; i < MAX_PATH_NUMBER; i++) {
		if (!event->file_path[i])
			break;
		tmp_len = snprintf_s(tmp, len + 1, len, " -i %s", event->file_path[i]);
		BUF_POINTER_FORWARD;
	}

	/* fill time */
	if (event->time) {
		tmp_len = snprintf_s(tmp, len + 1, len, " -t %lld", event->time);
		BUF_POINTER_FORWARD;
	}

	/* fill the payload info */
	key_count = 0;
	payload = event->head;
	while (payload) {
		char *value = NULL;
		char *regular_value = NULL;
		int need_free = 1;

		if (!payload->value) {
			payload = payload->next;
			continue;
		}
		if (key_count == 0) {
			tmp_len = snprintf_s(tmp, len + 1, len, " --extra ");
			BUF_POINTER_FORWARD;
		}
		key_count++;

		/* fill key */
		if (payload->key) {
			tmp_len = snprintf_s(tmp, len + 1, len, "%s:", payload->key);
			BUF_POINTER_FORWARD;
		}

		/* fill value */
		tmp_len = 0;
		value = payload->value;
		regular_value = make_regular(value);
		if (!regular_value) {
			regular_value = "NULL";
			need_free = 0;
		}
		tmp_len = snprintf_s(tmp, len + 1, len, "%s;", regular_value);
		BUF_POINTER_FORWARD;
		if ((value != regular_value) && need_free)
			vfree(regular_value);
		payload = payload->next;
	}

	buf[EVENT_INFO_BUF_LEN - 1] = '\0';
	*buf_ptr = buf;

	return (EVENT_INFO_BUF_LEN - len);
}

static int hiview_hievent_write_log_exception(char *str, const int str_len)
{
	char *strptr = str;
	int left_buf_len = str_len;
	int sent_cnt = 0;

	if (left_buf_len > EVENT_INFO_PACK_BUF_LEN) {
		hilog_err("%s packet over length", __func__);
		sent_cnt = 0;
	} else {
#ifdef CONFIG_LOGGER_LEGACY
		logbuf_to_exception(0, 0, IDAP_LOGTYPE_CMD, 0, strptr, left_buf_len);
#else
		send_hievent(0, strptr, left_buf_len); // 0:tail
#endif
		sent_cnt++;
	}

	return sent_cnt;
}

#ifdef CONFIG_LOGGER_LEGACY
static void hiview_hievent_file_lock(struct file *filp, int cmd)
{
	struct file_lock *fl = NULL;

	fl = locks_alloc_lock();
	if (!fl) {
		hilog_err("%s alloc error", __func__);
		return;
	}
	fl->fl_file = filp;
	fl->fl_owner = filp;
	fl->fl_pid = 0;
	fl->fl_flags = FL_FLOCK;
	fl->fl_type = cmd;
	fl->fl_end = OFFSET_MAX;

#if (LINUX_VERSION_CODE > KERNEL_VERSION(4, 4, 0))
	locks_lock_file_wait(filp, fl);
#else
	flock_lock_file_wait(filp, fl);
#endif
	locks_free_lock(fl);
}

int hiview_hievent_report(struct hiview_hievent *event)
{
	char *str = NULL;
	int buf_len;
	int sent_packet;
	struct file *fp = NULL;

	if (!event) {
		hilog_err("Bad event %s", __func__);
		return -EINVAL;
	}

	if (current->fs == NULL)
		return -EBUSY;
	buf_len = hiview_hievent_convert_string(event, &str);
	if (!str)
		return -EINVAL;
	fp = filp_open("/dev/hwlog_exception", O_WRONLY, 0);
	if (IS_ERR(fp)) {
		hilog_info("%s open fail", __func__);
		sent_packet = hiview_hievent_write_log_exception(str, buf_len);
	} else {
		hiview_hievent_file_lock(fp, F_WRLCK);
		sent_packet = hiview_hievent_write_log_exception(str, buf_len);
		hiview_hievent_file_lock(fp, F_UNLCK);
		filp_close(fp, 0);
	}
	sent_packet = hiview_hievent_write_log_exception(str, buf_len);

	hilog_info("%s : %u", __func__, event->event_id);
	vfree(str);

	return sent_packet;
}
#else
int hiview_hievent_report(struct hiview_hievent *event)
{
	char *str = NULL;
	int buf_len;
	int sent_packet;
	if (!event) {
		hilog_err("Bad event %s", __func__);
		return -EINVAL;
	}

	buf_len = hiview_hievent_convert_string(event, &str);
	if (!str)
		return -EINVAL;
	sent_packet = hiview_hievent_write_log_exception(str, buf_len);

	hilog_info("%s : %u", __func__, event->event_id);
	vfree(str);

	return sent_packet;
}
#endif
EXPORT_SYMBOL(hiview_hievent_report);

void hiview_hievent_destroy(struct hiview_hievent *event)
{
	int i;
	struct hiview_hievent_payload *payload = NULL;

	if (!event)
		return;

	payload = event->head;
	while (payload) {
		struct hiview_hievent_payload *del = payload;

		payload = payload->next;
		hiview_hievent_payload_destroy(del);
	}
	event->head = NULL;
	for (i = 0; i < MAX_PATH_NUMBER; i++) {
		kfree(event->file_path[i]);
		event->file_path[i] = NULL;
	}
	vfree(event);
}
EXPORT_SYMBOL(hiview_hievent_destroy);
