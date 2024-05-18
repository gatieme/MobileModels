#
# Makefile for wifi Tcp-ipv4
#
obj-$(CONFIG_HN_WIFIPRO) += wifipro_tcp_monitor.o
obj-$(CONFIG_HN_SNIFFER) += sysctl_sniffer.o
obj-$(CONFIG_HN_CHR_TCP_SMALL_WIN_MONITOR) += tcp_small_window_chr_monitor.o

ifdef CONFIG_HONOR_MSS_AUTO_CHANGE
ccflags-y += -Inet/ipv4/tmss/
endif

obj-$(CONFIG_HONOR_MSS_AUTO_CHANGE) += tcp_mss.o

