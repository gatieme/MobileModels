dtb-y += VICTORIA_LX9_LV1_config.dtb
dtb-y += VICTORIA_TUGL_V4_V110_config.dtb
dtb-y += VICTORIA_LX9_V4_config.dtb
dtb-y += VICTORIA_TUGL_LV1_config.dtb
dtb-y += VICTORIA_LX9_LV4_config.dtb
dtb-y += VICTORIA_TUGL_V3_config.dtb
dtb-y += VICTORIA_LX9_LV3_config.dtb
dtb-y += VICTORIA_LX9_V3_V101_config.dtb
dtb-y += VICTORIA_LX9_LV2_config.dtb
dtb-y += VICTORIA_TUGL_V4_config.dtb
dtb-y += VICTORIA_TUGL_LV3_config.dtb
dtb-y += VICTORIA_TUGL_LV2_config.dtb
dtb-y += VICTORIA_LX9_V3_BACKLIGHT_config.dtb
dtb-y += VICTORIA_TUGL_V3_V101_config.dtb
dtb-y += VICTORIA_TUGL_V3_BACKLIGHT_config.dtb
dtb-y += VICTORIA_LX9_V3_config.dtb
dtb-y += VICTORIA_TUGL_V1_config.dtb
dtb-y += VICTORIA_TUGL_LV4_config.dtb
dtb-y += VICTORIA_TUGL_V3_DPD_SKY2_5_config.dtb

targets += dtbs

dtbs: $(addprefix $(obj)/, $(dtb-y))
	$(Q)rm -f $(obj)/../*.dtb

clean-files := *.dtb
