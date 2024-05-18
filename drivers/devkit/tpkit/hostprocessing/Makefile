EXTRA_CFLAGS += -I$(srctree)/drivers/hwspinlock
# EXTRA_CFLAGS += -Idrivers/video/fbdev/honor/dss

obj-$(CONFIG_HONOR_THP) += thp.o
thp-objs += honor_thp_attr.o honor_thp_core.o honor_thp_mt_wrapper.o goodix_thp.o synaptics_thp.o himax_thp.o honor_thp_pen_core.o himax_thp_pen.o

ifeq ($(CONFIG_HONOR_TRUSTED_TOUCH), y)
thp-objs += honor_thp_vm.o
endif

obj-$(CONFIG_HONOR_THP_FOCALTECH) += focaltech_thp.o
obj-$(CONFIG_HONOR_THP_NOVATECH) += novatek_thp.o
#obj-$(CONFIG_HONOR_THP_SYNAPTICS) += synaptics_thp.o
obj-$(CONFIG_JDI_HOST_TS_KIT) += bu21150_thp.o
#obj-$(CONFIG_HONOR_THP_HIMAX) += himax_thp.o
#obj-$(CONFIG_HONOR_THP_GOODIX) += goodix_thp.o
obj-$(CONFIG_HONOR_THP_SOLOMON) += ssl_thp.o
obj-$(CONFIG_HONOR_SHB_THP) += honor_thp_log.o
obj-$(CONFIG_HONOR_THP_ILITEK) += ilitek_thp.o
obj-$(CONFIG_HONOR_THP_ST) += stmicro_thp.o

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DTP_FACTORY_MODE
endif

# EXTRA_CFLAGS += -Idrivers/honor/tzdriver
# EXTRA_CFLAGS += -Idrivers/tzdriver
# EXTRA_CFLAGS += -Idrivers/devkit/lcdkit/lcdkit1.0/core/common
# EXTRA_CFLAGS += -Idrivers/devkit/lcdkit/lcdkit3.0/kernel/common/include
# ifeq ($(wildcard $(srctree)/drivers/honor_platform/inputhub/$(TARGET_BOARD_PLATFORM)),)
# EXTRA_CFLAGS += -Idrivers/honor_platform/inputhub/default
# else
# EXTRA_CFLAGS += -Idrivers/honor_platform/inputhub/$(TARGET_BOARD_PLATFORM)
# endif

# ifeq ($(TARGET_BOARD_PLATFORM), $(TRINKET))
# EXTRA_CFLAGS += -Idrivers/gpu/drm/msm
# EXTRA_CFLAGS += -Idrivers/gpu/drm/msm/dsi-staging
# EXTRA_CFLAGS += -Idrivers/hwsensor/pssensor
# endif

# EXTRA_CFLAGS += -Idrivers/honor_platform/sensor2_0/
# EXTRA_CFLAGS += -I$(srctree)/drivers/misc/mediatek/sensor/2.0/core

# EXTRA_CFLAGS += -I$(srctree)/drivers/misc/mediatek/sensors-1.0/alsps/alspshub
# EXTRA_CFLAGS += -I$(srctree)/drivers/devkit/lcdkit/lcdkit3.0/kernel/common/include
