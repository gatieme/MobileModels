/*
 * honor_charger_event.h
 *
 * honor charger event
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _HONOR_CHARGER_EVENT
#define _HONOR_CHARGER_EVENT
void charger_source_sink_event(enum charger_event_type event, int allow_bc12);
#endif /* _HONOR_CHARGER_EVENT */