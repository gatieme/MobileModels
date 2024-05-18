/*
 * Copyright (c) Honor Device Co., Ltd. 2023-2024. All rights reserved.
 * Description: hidiagnostic drivers for kernel
 * Author: jiangfeng
 * Create: 20230406
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
#include <securec.h>

#include <log/hiview_hievent.h>
#include <log/log_exception.h>
#include <log/hw_log.h>
#include <log/hiview_hidiagnostic.h>

/**
 * Diagnostic raw id.
 */
#define DIAGNOSTIC_RAWID 1002

/**
 * Max event id num.
 */
#define MAX_RELATED_ID_LEN 10

/**
 * Max tag num.
 */
#define MAX_TAG_LEN 10

/**
 * Max tag value len.
 */
#define MAX_TAG_VALUE_LEN 128

/**
 * Max tag value len.
 */
#define MAX_KEY_LEN 32

/**
 * Max bufer len of event ids string.
 */
#define RELATED_ID_BUF_LEN 128

/**
 * Max len of info string.
 */
#define MAX_INFO_VALUE_LEN 1024

/**
 * Min UE event id.
 */
#define UE_EVENT_ID_MIN 990000000

/**
 * Max UE event id.
 */
#define UE_EVENT_ID_MAX 992999999

/**
 * Key of related ids.
*/
#define KEY_RELATED_ID "_RelatedID"

/**
 * Key of privacy.
*/
#define KEY_PRIVACY "_Privacy"

/**
 * Key of mark end.
*/
#define KEY_MARK_END "_MarkEnd"


#define HWLOG_TAG hiview_hidiagnostic
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

struct diagnostic_info {
	char *key;
	char *value;
	struct diagnostic_info *next;
};

struct hiview_hidiagnostic {
	int related_id[MAX_RELATED_ID_LEN];
	const char *tag[MAX_TAG_LEN];
	enum privacy_flag flag;
	bool mark;
	struct diagnostic_info *head;
	int related_id_num;
	int tag_num;
	bool is_tag_set;
	bool is_id_set;
};

static struct diagnostic_info *hiview_hidiagnostic_info_node_create(void);

static void hiview_hidiagnostic_info_node_destroy(struct diagnostic_info *diag_info);

static struct diagnostic_info *hiview_hidiagnostic_get_info_node(struct diagnostic_info *head, const char *key);

static void hiview_hidiagnostic_add_info_node(struct hiview_hidiagnostic *hidiagnostic, struct diagnostic_info *diag_info);

bool hiview_hidiagnostic_is_ue_event(int event_id);

static struct diagnostic_info *hiview_hidiagnostic_info_node_create(void)
{
	struct diagnostic_info *diag_info = NULL;

	diag_info = vmalloc(sizeof(*diag_info));
	if (!diag_info) {
		return NULL;
	}
	diag_info->key = NULL;
	diag_info->value = NULL;
	diag_info->next = NULL;

	return diag_info;
}

static void hiview_hidiagnostic_info_node_destroy(struct diagnostic_info *diag_info)
{
	if (!diag_info) {
		return;
	}
	if (diag_info->value)
		vfree(diag_info->value);

	kfree(diag_info->key);
	vfree(diag_info);
}

static struct diagnostic_info *hiview_hidiagnostic_get_info_node(struct diagnostic_info *head, const char *key)
{
	struct diagnostic_info *diag_info = head;

	while (diag_info) {
		if (key && diag_info->key) {
			if (strcmp(diag_info->key, key) == 0) {
				return diag_info;
			}
		}
		diag_info = diag_info->next;
	}

	return NULL;
}

static void hiview_hidiagnostic_add_info_node(struct hiview_hidiagnostic *hidiagnostic, struct diagnostic_info *diag_info)
{
	if (!hidiagnostic->head) {
		hidiagnostic->head = diag_info;
	} else {
		struct diagnostic_info *temp = hidiagnostic->head;

		while (temp->next)
			temp = temp->next;
		temp->next = diag_info;
	}
}

bool hiview_hidiagnostic_is_ue_event(int event_id)
{
	if (UE_EVENT_ID_MIN <= event_id && event_id <= UE_EVENT_ID_MAX) {
		return true;
	}
	return false;
}

/**
 * Create a the diagnostic event.
 */
struct hiview_hidiagnostic *hiview_hidiagnostic_create(void)
{
	struct hiview_hidiagnostic *hidiagnostic = NULL;

	hidiagnostic = vmalloc(sizeof(*hidiagnostic));
	if (!hidiagnostic) {
		return NULL;
	}

	if (memset_s(hidiagnostic, sizeof(*hidiagnostic), 0, sizeof(*hidiagnostic)) != EOK) {
		vfree(hidiagnostic);
		return NULL;
	}

	hidiagnostic->flag = UN_SET_DEST;
	hidiagnostic->mark = false;
	hidiagnostic->related_id_num = 0;
	hidiagnostic->tag_num = 0;

	hidiagnostic->is_tag_set = false;
	hidiagnostic->is_id_set = false;

	return (void *)hidiagnostic;
}
EXPORT_SYMBOL(hiview_hidiagnostic_create);

/**
 * Specify a event id for the diagnostic event.
 */
int hiview_hidiagnositc_for_eventid(struct hiview_hidiagnostic *hidiagnostic, int event_id)
{
	if (!hidiagnostic) {
		hilog_err("Bad input hidiagnostic for %s", __func__);
		return -EINVAL;
	}

	if (hidiagnostic->is_id_set) {
		hilog_err("%s event id has already been set", __func__);
		return -EINVAL;
	}

	if (hiview_hidiagnostic_is_ue_event(event_id)) {
		hilog_err("%s do not suport ue event %d", __func__, event_id);
		return -EINVAL;
	}

	hidiagnostic->related_id[0] = event_id;
	hidiagnostic->related_id_num = 1;
	hidiagnostic->is_id_set = true;

	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_for_eventid);

/**
 * Specify a event id list for the diagnostic event.
 */
int hiview_hidiagnositc_for_eventid_array(struct hiview_hidiagnostic *hidiagnostic, int event_id[], int id_num)
{
	int tempi;

	if ((!hidiagnostic) || (!event_id)) {
		hilog_err("Bad input hidiagnostic or event_id for %s", __func__);
		return -EINVAL;
	}

	if (hidiagnostic->is_id_set) {
		hilog_err("%s event id has already been set", __func__);
		return -EINVAL;
	}

	if (id_num > MAX_RELATED_ID_LEN) {
		hilog_err("Event id num over max: %d", MAX_RELATED_ID_LEN);
		return -EINVAL;
	}

	if (id_num == 0) {
		hilog_err("Event id num can not be zero in %s", __func__);
		return -EINVAL;
	}

	for (tempi = 0; tempi < id_num; tempi++) {
		if (hiview_hidiagnostic_is_ue_event(event_id[tempi])) {
			hilog_err("%s do not suport ue event %d", __func__, event_id[tempi]);
			hidiagnostic->related_id_num = tempi;
			hidiagnostic->is_id_set = true;
			return -EINVAL;
		}
		hidiagnostic->related_id[tempi] = event_id[tempi];
	}

	hidiagnostic->related_id_num = id_num;
	hidiagnostic->is_id_set = true;

	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_for_eventid_array);

/**
 * Set a tag for the diagnostic event.
 */
int hiview_hidiagnositc_set_tag(struct hiview_hidiagnostic *hidiagnostic, const char *tag)
{
	int tag_len = 0;

	if ((!hidiagnostic) || (!tag)) {
		hilog_err("Bad input hidiagnostic or tag for %s", __func__);
		return -EINVAL;
	}

	if (hidiagnostic->is_tag_set) {
		hilog_err("%s tag has already been set", __func__);
		return -EINVAL;
	}

	tag_len = strlen(tag);
	if (tag_len > MAX_TAG_VALUE_LEN) {
		hilog_err("Tag value over max: %d", MAX_TAG_VALUE_LEN);
		return -EINVAL;
	}

	hidiagnostic->tag[0] = kstrdup(tag, GFP_ATOMIC);
	if (!hidiagnostic->tag[0]) {
		hilog_err("Failed to allocate memory for tag[0] in %s", __func__);
		return -ENOMEM;
	}

	hidiagnostic->is_tag_set = true;
	hidiagnostic->tag_num = 1;

	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_set_tag);

/**
 * Set a tag list for the diagnostic event.
 */
int hiview_hidiagnositc_set_tag_array(struct hiview_hidiagnostic *hidiagnostic, const char *tag[], int tag_num)
{
	int tempi;
	int tag_len = 0;

	if ((!hidiagnostic) || (!tag)) {
		hilog_err("Bad input hidiagnostic or tag for %s", __func__);
		return -EINVAL;
	}

	if (hidiagnostic->is_tag_set) {
		hilog_err("%s tag has already been set", __func__);
		return -EINVAL;
	}

	if (tag_num == 0) {
		hilog_err("Tag num can not be zero in %s", __func__);
		return -EINVAL;
	}

	if (tag_num > MAX_TAG_LEN) {
		hilog_err("Tag num over max : %d", MAX_TAG_LEN);
		return -EINVAL;
	}

	for (tempi = 0; tempi < tag_num; tempi++) {
		tag_len = strlen(tag[tempi]);
		if (tag_len > MAX_TAG_VALUE_LEN) {
			hilog_err("Tag %s over max len: %d", tag[tempi], MAX_TAG_VALUE_LEN);
			while (--tempi >= 0) {
				kfree(hidiagnostic->tag[tempi]);
				hidiagnostic->tag[tempi] = NULL;
			}
			return -EINVAL;
		}

		hidiagnostic->tag[tempi] = kstrdup(tag[tempi], GFP_ATOMIC);
		if (!hidiagnostic->tag[tempi]) {
			hilog_err("Failed to allocate memory for tag[%d] in %s", tempi, __func__);
			while (--tempi >= 0) {
				kfree(hidiagnostic->tag[tempi]);
				hidiagnostic->tag[tempi] = NULL;
			}
			return -ENOMEM;
		}
	}
	hidiagnostic->is_tag_set = true;
	hidiagnostic->tag_num = tag_num;

	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_set_tag_array);

/**
 * Add diagnostic info into the event.
 */
int hiview_hidiagnositc_add_info(struct hiview_hidiagnostic *hidiagnostic, const char *key, const char *value)
{
	struct diagnostic_info *diagnostic_info = NULL;
	int len = 0;

	if ((!hidiagnostic) || (!key) || (!value)) {
		hilog_err("Bad hidiagnostic or key or value for %s", __func__);
		return -EINVAL;
	}

	len = strlen(key);
	if (len > MAX_KEY_LEN) {
		hilog_err("key %s over max len: %d", key, MAX_KEY_LEN);
		return -EINVAL;
	}

	diagnostic_info = hiview_hidiagnostic_get_info_node(hidiagnostic->head, key);
	if (!diagnostic_info) {
		diagnostic_info = hiview_hidiagnostic_info_node_create();
		if (!diagnostic_info) {
			return -ENOMEM;
		}
		diagnostic_info->key = kstrdup(key, GFP_ATOMIC);
		hiview_hidiagnostic_add_info_node(hidiagnostic, diagnostic_info);
	}
	if (diagnostic_info->value)
		vfree(diagnostic_info->value);
	len = strlen(value);
	if (len > MAX_INFO_VALUE_LEN)
		len = MAX_INFO_VALUE_LEN;
	diagnostic_info->value = vmalloc(len + 1);
	if (!diagnostic_info->value) {
		return -ENOMEM;
	}
	if (memset_s(diagnostic_info->value, len + 1, 0, len + 1) != EOK) {
		return -ENOMEM;
	}
	if (strncpy_s(diagnostic_info->value, len + 1, value, len) != EOK) {
		return -ENOMEM;
	}

	diagnostic_info->value[len] = '\0';
	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_add_info);

/**
 * Set privacy for the diagnostic event.
 */
int hiview_hidiagnositc_set_privacy(struct hiview_hidiagnostic *hidiagnostic, enum privacy_flag flag)
{
	if (!hidiagnostic) {
		hilog_err("Bad input hidiagnostic for %s", __func__);
		return -EINVAL;
	}

	if (flag == UN_SET_DEST) {
		hilog_err("%s privacy can not be set for UN_SET_DEST", __func__);
		return -EINVAL;
	}
	hidiagnostic->flag = flag;

	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_set_privacy);

/**
 * Mark related end for the diagnostic event.
 */
int hiview_hidiagnositc_mark_related_end(struct hiview_hidiagnostic *hidiagnostic, bool mark)
{
	if (!hidiagnostic) {
		hilog_err("Bad input hidiagnostic for %s", __func__);
		return -EINVAL;
	}

	hidiagnostic->mark = mark;
	return 0;
}
EXPORT_SYMBOL(hiview_hidiagnositc_mark_related_end);

/**
 * Report a diagnostic event to hiview. event id
 * 1、Event id can not be empty.
 * 2、Tag can not be empty.
 * 3、Info can not be empty.
 * 4、Privacy flag can not be UN_SET_DEST.
 * 5、There is vmalloc inside, maybe scheduel out. So don't use it either in irq or atomic function.
 */
int hiview_hidiagnositc_report(struct hiview_hidiagnostic *hidiagnostic)
{
	struct hiview_hievent *event = NULL;
	int ret = 0;
	int tempi;
	int len;
	char *tmp = NULL;
	int tmp_len = 0;
	char *buf = NULL;
	struct diagnostic_info *diag_info = NULL;

	if (!hidiagnostic) {
		hilog_err("Bad input hidiagnostic for %s", __func__);
		return -EINVAL;
	}
	if (hidiagnostic->related_id_num == 0) {
		hilog_err("Event ID is not allowed to be empty, failed to report in %s", __func__);
		return -EINVAL;
	}
	if (hidiagnostic->tag_num == 0) {
		hilog_err("Tag is not allowed to be empty, failed to report in %s", __func__);
		return -EINVAL;
	}
	if (hidiagnostic->head == NULL) {
		hilog_err("Info is not allowed to be empty, failed to report in %s", __func__);
		return -EINVAL;
	}
	if (hidiagnostic->flag == UN_SET_DEST) {
		hilog_err("Privacy level is not set, failed to report in %s", __func__);
		return -EINVAL;
	}

	event= hiview_hievent_create(DIAGNOSTIC_RAWID);
	if (event == NULL) {
		hilog_err("Create hievent failed in %s", __func__);
		return -EINVAL;
	}

	buf = vmalloc(RELATED_ID_BUF_LEN);
	if (!buf) {
		hilog_err("Vmalloc buf failed in %s", __func__);
		return -ENOMEM;
	}

	if (memset_s(buf, RELATED_ID_BUF_LEN, 0, RELATED_ID_BUF_LEN) != EOK) {
		vfree(buf);
		return -ENOMEM;
	}

	len = RELATED_ID_BUF_LEN - 1;
	tmp = buf;
	for (tempi = 0; tempi < hidiagnostic->related_id_num; tempi++) {
		if (!hidiagnostic->related_id[tempi]) {
			break;
		}
		if (tmp_len > 0) {
			tmp_len = snprintf_s(tmp, len + 1, len, "|");
			BUF_POINTER_FORWARD;
		}
		tmp_len = snprintf_s(tmp, len + 1, len, "%lld", hidiagnostic->related_id[tempi]);
		BUF_POINTER_FORWARD;
	}
	buf[RELATED_ID_BUF_LEN - 1] = '\0';
	hiview_hievent_put_string(event, KEY_RELATED_ID, buf);
	vfree(buf);

	ret = hiview_hievent_set_tag_array(event, hidiagnostic->tag, hidiagnostic->tag_num);

	diag_info = hidiagnostic->head;
	while (diag_info) {
		hiview_hievent_put_string(event, diag_info->key, diag_info->value);
		diag_info = diag_info->next;
	}

	if (DEST_BETA == hidiagnostic->flag) {
		hiview_hievent_put_string(event, KEY_PRIVACY, "DEST_BETA");
	} else if (DEST_COMMECIAL == hidiagnostic->flag) {
		hiview_hievent_put_string(event, KEY_PRIVACY, "DEST_COMMECIAL");
	}

	if (hidiagnostic->mark)
		hiview_hievent_put_string(event, KEY_MARK_END, "1");

	ret = hiview_hievent_report(event);
	if (ret < 0)
		hilog_err("Report to hievent failed in %s", __func__);
	hiview_hievent_destroy(event);
	return ret;
}
EXPORT_SYMBOL(hiview_hidiagnositc_report);

/**
 * Release memory after report diagnostic event.
 */
void hiview_hidiagnositc_destroy(struct hiview_hidiagnostic *hidiagnostic)
{
	struct diagnostic_info *diag_info = NULL;
	int tempi;

	if (!hidiagnostic) {
		return;
	}

	diag_info = hidiagnostic->head;
	while (diag_info) {
		struct diagnostic_info *del = diag_info;
		diag_info = diag_info->next;
		hiview_hidiagnostic_info_node_destroy(del);
	}
	hidiagnostic->head = NULL;
	for (tempi = 0; tempi < hidiagnostic->tag_num; tempi++) {
		kfree(hidiagnostic->tag[tempi]);
		hidiagnostic->tag[tempi] = NULL;
	}
	vfree(hidiagnostic);
}
EXPORT_SYMBOL(hiview_hidiagnositc_destroy);
