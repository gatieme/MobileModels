obj-m			+= hallsensor/
obj-$(CONFIG_HUAWEI_LP_SENSORS)				+= lpsensor/

obj-$(CONFIG_HUAWEI_PS_SENSOR)				+= pssensor/
obj-$(CONFIG_SENSOR_DEVELOP_TEST)			+= develop_test.o
obj-$(CONFIG_HUAWEI_SENSOR_INFO)			+= hw_sensor_info.o
obj-$(CONFIG_HUAWEI_SAR_SENSOR)				+= sarsensor/
obj-m                                       += sensors_class.o
obj-m                                       += sensors_sysfs_als.o
obj-m                                      += apsensor_channel/
obj-m                                       += xhub_router/
obj-m                                      += color_sensor/
obj-m                                       += xhub_logbuff.o
obj-m                                       += sensors_sysfs_ps.o
obj-m                                       += sensors_sysfs_hinge.o
ccflags-y += -Ivendor/huawei/chipset_common/plugins/kernel/include/

obj-$(CONFIG_HUAWEI_EXTRA_IR_MODE)			+= extra_ir_mode/
obj-$(CONFIG_HUAWEI_HORIZONTAL_MODE)			+= acc_horizontal_mode/
