/*
 * Copyright (c) Honor Device Co., Ltd. 2023-2024. All rights reserved.
 * Description: hidiagnostic drivers for kernel
 * Author: jiangfeng
 * Create: 20230406
 */

#ifndef HIVIEW_HIDIAGNOSTIC_H
#define HIVIEW_HIDIAGNOSTIC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The privacy flag of diagnostic event.
 */
enum privacy_flag {
	/**
	 * If this value is used, the diagnostic event will not be reported.
	 */
	UN_SET_DEST = -1,
	/**
	 * If this value is used, the diagnostic event will only be reported in Beta version.
	 */
	DEST_BETA = 1,
	/**
	 * If this value is used, the diagnostic event will  be reported in both Beta and commerical version.
	 */
	DEST_COMMECIAL = 2,
};

struct hiview_hidiagnostic;

struct hiview_hidiagnostic *hiview_hidiagnostic_create(void);

int hiview_hidiagnositc_report(struct hiview_hidiagnostic *hidiagnostic);

void hiview_hidiagnositc_destroy(struct hiview_hidiagnostic *hidiagnostic);

int hiview_hidiagnositc_for_eventid(struct hiview_hidiagnostic *hidiagnostic, int event_id);

int hiview_hidiagnositc_for_eventid_array(struct hiview_hidiagnostic *hidiagnostic, int event_id[], int id_num);

int hiview_hidiagnositc_set_tag(struct hiview_hidiagnostic *hidiagnostic, const char *tag);

int hiview_hidiagnositc_set_tag_array(struct hiview_hidiagnostic *hidiagnostic, const char *tag[], int tag_num);

int hiview_hidiagnositc_add_info(struct hiview_hidiagnostic *hidiagnostic, const char *key, const char *value);

int hiview_hidiagnositc_set_privacy(struct hiview_hidiagnostic *hidiagnostic, enum privacy_flag flag);

int hiview_hidiagnositc_mark_related_end(struct hiview_hidiagnostic *hidiagnostic, bool mark);

#ifdef __cplusplus
}
#endif

#endif
