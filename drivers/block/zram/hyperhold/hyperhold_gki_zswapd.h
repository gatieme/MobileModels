#ifndef _HYPERHOLD_GKI_ZSWAPD_
#define _HYPERHOLD_GKI_ZSWAPD_

#if (defined CONFIG_ZSWAPD_GKI) && (CONFIG_HYPERHOLD_GKI)

ssize_t hyperhold_zram_wm_ratio_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zram_wm_ratio_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_compress_ratio_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_compress_ratio_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_pressure_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zswapd_pid_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_avail_buffers_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_avail_buffers_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_eswap_avail_buffers_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_eswap_avail_buffers_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_max_reclaim_size_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zswapd_max_reclaim_size_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_pause_zswapd_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_pause_zswapd_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_area_anon_refault_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_area_anon_refault_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_empty_round_skip_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_empty_round_skip_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_max_skip_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_max_skip_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_empty_round_check_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_empty_round_check_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_anon_refault_snapshot_min_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_anon_refault_snapshot_min_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_single_memcg_param_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zswapd_single_memcg_param_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_pressure_info_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_min_anon_size_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zswapd_min_anon_size_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zram_critical_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zram_critical_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_psi_info_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_eswap_stat_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_eswap_stat_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_stat_show(struct device *dev,
	struct device_attribute *attr, char *buf);

ssize_t hyperhold_zswapd_trigger_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_zswapd_trigger_show(struct device *dev,
	struct device_attribute *attr, char *buf);

pid_t hyperhold_gki_zswapd_pid_get(void);


#endif

#endif
