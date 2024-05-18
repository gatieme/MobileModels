#
# Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
# Description: Makefile for the KERNEL STP
# Author: jiayunlong <jiayunlong@hihonor.com>
# Create: 2021-08-30
#

ifdef CONFIG_HN_KERNEL_STP

HN_KERNEL_STP_OBJS += hn_kernel_stp_module.o \
                      hn_kernel_stp_proc.o \
                      hn_kernel_stp_scanner.o \
                      hn_kernel_stp_uploader.o \
                      hn_kernel_stp_saudit.o
obj-$(CONFIG_HN_KERNEL_STP) += kernel_stp.o
kernel_stp-y:=$(HN_KERNEL_STP_OBJS)
endif
flags += -Wdate-time -Wfloat-equal
