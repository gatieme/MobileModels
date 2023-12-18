ifeq ($(TARGET_PRODUCT),bengal)
$(info "TARGET_PRODUCT = bengal_1")
EXTRA_CFLAGS += -DQCOM_PLATFORM_6225
endif
EXTRA_CFLAGS += -I$(srctree)/drivers/devkit/tpkit/ \
                -I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/common/displayengine/include
obj-$(CONFIG_FINGERPRINT)	+= fingerprint.o