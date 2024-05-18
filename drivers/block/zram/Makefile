# SPDX-License-Identifier: GPL-2.0-only
zram-y	:=	zcomp.o zram_drv.o

ifeq ($(CONFIG_HYPERHOLD_GKI),y)
zram-y += hyperhold/hyperhold_area.o \
       hyperhold/hyperhold_list.o \
       hyperhold/hyperhold_perf.o \
       hyperhold/hyperhold_schedule.o \
       hyperhold/hyperhold_stats.o \
       hyperhold/hyperhold_core.o \
       hyperhold/hyperhold_manager.o \
       hyperhold/hyperhold_ctrl.o \
       hyperhold/hyperhold_lru_rmap.o \
       hyperhold/hyperhold_gki_memcg_control.o \
       hyperhold/hyperhold_gki_zswapd.o
endif

obj-$(CONFIG_ZRAM)	+=	zram.o

ifeq ($(CONFIG_HYPERHOLD_CORE),y)
obj-$(CONFIG_HYPERHOLD_CORE)	+=	hyperhold/
endif
