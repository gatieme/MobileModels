#
# Logger extend configuration
#
obj-$(CONFIG_LOGGER) = logger.o

logger-$(CONFIG_LOGGER)	        += hw_logger.o
logger-$(CONFIG_LOGGER)	        += hw_reboot_wdt.o
logger-$(CONFIG_LOG_EXCEPTION)	+= log_exception.o
logger-$(CONFIG_LOG_EXCEPTION)	+= log_usertype.o
logger-$(CONFIG_LOG_EXCEPTION)	+= imonitor_events.o
logger-$(CONFIG_LOG_EXCEPTION)	+= hiview_hievent.o
logger-$(CONFIG_LOG_EXCEPTION)	+= hiview_hidiagnostic.o
logger-$(CONFIG_LOG_KERNEL)	+= hwlog_kernel.o

# diasbled by default
logger-$(CONFIG_HIVIEW_SELINUX)	+= hiview_selinux.o

obj-y += module_test/
