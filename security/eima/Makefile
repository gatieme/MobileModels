# Copyright (c) Honor Device Co., Ltd. 2017-2020. All rights reserved.
#
# Makefile for the MAGIC Integrity Measurement Architecture(EIMA).
#

obj-$(CONFIG_HONOR_EIMA) += eima_module.o eima_queue.o eima_fs.o dkm.o hash_generator.o
obj-$(CONFIG_HONOR_EIMA_ACCESS_CONTROL) += eima_netlink.o

ccflags-$(CONFIG_HONOR_EIMA) += -I$(srctree)/drivers/tzdriver/ca_antiroot \
				-I$(srctree)/drivers/tzdriver/lib_sec/include

flags += -Wdate-time -Wfloat-equal
