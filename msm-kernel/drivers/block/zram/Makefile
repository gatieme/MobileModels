# SPDX-License-Identifier: GPL-2.0-only
ifdef CONFIG_CRYPTO_DELTA
zram-y	:=	sddc/zcomp_ext.o zram_drv.o
else
zram-y	:=	zcomp.o zram_drv.o
endif

obj-$(CONFIG_ZRAM)	+=	zram.o
obj-$(CONFIG_HYPERHOLD_CORE) += hyperhold/
obj-$(CONFIG_CRYPTO_DELTA) += sddc/
