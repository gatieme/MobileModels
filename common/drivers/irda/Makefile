ifneq ($(TARGET_BUILD_VARIANT), user)
ccflags-y += -DIR_CORE_DEBUG
endif

obj-$(CONFIG_HUAWEI_IR_CORE) += infrared_ctl.o

infrared_ctl-y := ir_core.o
infrared_ctl-$(CONFIG_HUAWEI_IR_PWM) += ir_pwm.o