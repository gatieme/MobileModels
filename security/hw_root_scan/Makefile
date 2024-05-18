#
# Copyright (c) Honor Device Co., Ltd. 2016-2020. All rights reserved.
# Description: Makefile for the Honor root scanner.
# Author: likun <quentin.lee.>
# Create: 2016-06-18
#

obj-$(CONFIG_HN_ROOT_SCAN) += hw_rscan_utils.o
obj-$(CONFIG_HN_ROOT_SCAN) += kcode.o
obj-$(CONFIG_HN_ROOT_SCAN) += rproc.o
obj-$(CONFIG_HN_ROOT_SCAN) += sescan.o
obj-$(CONFIG_HN_ROOT_SCAN) += setids.o
obj-$(CONFIG_HN_ROOT_SCAN) += hw_rscan_scanner.o
obj-$(CONFIG_HN_ROOT_SCAN) += hw_rscan_module.o

ccflags-$(CONFIG_HN_ROOT_SCAN) += -I$(srctree)/drivers/tzdriver/ca_antiroot
ccflags-$(CONFIG_HN_ROOT_SCAN) += -I$(srctree)/lib/libc_sec/include
ccflags-$(CONFIG_HN_ROOT_SCAN) += -Isecurity/selinux/include

flags += -Wdate-time -Wfloat-equal
