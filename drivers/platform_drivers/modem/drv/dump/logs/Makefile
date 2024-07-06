#
# Makefile for the memory technology device drivers.
#
# Core functionality.

ifeq ($(strip $(llt_gcov)),y)
GCOV_PROFILE := y
endif

obj-y				+= dump_log_strategy.o 
obj-y				+= dump_logs.o
obj-y				+= dump_reset_log.o
obj-y				+= dump_sec_log.o
obj-y				+= dump_teeos_service.o
obj-y                           += dump_log_parser.o
obj-y				+= dump_avs_escape.o
