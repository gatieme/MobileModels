ifneq ($(TARGET_BUILD_VARIANT),user)
ccflags-y += -DDBG_ULOG_TRACE
endif

obj-$(CONFIG_ULOG_TRACE) += ulog_module.o
ulog_module-y := ulog_trace.o
ulog_module-y += ulog_file.o
