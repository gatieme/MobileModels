/*
 * Copyright (C) 2021 Honor Device Co.Ltd
 * License terms: GNU General Public License (GPL) version 2
 *
 */

#ifndef __SUBSYS_FAILURE_LOG_H
#define __SUBSYS_FAILURE_LOG_H

//extern int strncpy_s(char *strDest, size_t destMax, const char *strSrc, size_t count);

void report_subsys_crash_log(const char *name, const char *reason, size_t reason_len);
void upload_subsys_crash_log_direct(const char *name, const char *reason, size_t reason_len);

#endif
