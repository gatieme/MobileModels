// SPDX-License-Identifier: GPL-2.0
/*
 * wireless_tx_fod.c
 *
 * tx fod for wireless reverse charging
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/workqueue.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_debug.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/protocol/wireless_protocol.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_cap.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_fod.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_pwr_src.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_ic_intf.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_pwr_ctrl.h>
#include <huawei_platform/power/wireless/wireless_transmitter.h>

#define HWLOG_TAG wireless_tx_fod
HWLOG_REGIST();

#define WLTX_PREVFOD_CHK_MAX_PLOSS          5000

#define WLTX_CURFOD_CHK_ACT_NONE            0
#define WLTX_CURFOD_CHK_ACT_SWITCH_PWR      1

#define WLTX_CURFOD_DBG_MAX_PARA_SIZE       54

static struct wltx_fod_dev_info *g_tx_fod_di;

static int wltx_get_fod_alarm_id(struct wltx_fod_dev_info *di)
{
	int ret;
	int i;
	s32 ploss = 0;
	u8 ploss_id = 0;

	ret = wltx_ic_get_ploss(WLTRX_IC_MAIN, &ploss);
	ret += wltx_ic_get_ploss_id(WLTRX_IC_MAIN, &ploss_id);
	if (ret)
		return di->cfg.fod_alarm_level;

	for (i = 0; i < di->cfg.fod_alarm_level; i++) {
		if (ploss_id != di->cfg.fod_alarm[i].ploss_id)
			continue;
		if ((ploss <= di->cfg.fod_alarm[i].ploss_lth) ||
			(ploss >= di->cfg.fod_alarm[i].ploss_hth))
			continue;
		break;
	}

	return i;
}

static void wltx_monitor_fod_alarm(struct wltx_fod_dev_info *di)
{
	int cur_id;
	static unsigned long time_out;

	if (di->cfg.fod_alarm_level <= 0)
		return;

	cur_id = wltx_get_fod_alarm_id(di);
	if ((cur_id < 0) || (cur_id >= di->cfg.fod_alarm_level))
		return;

	if (di->alarm_id != cur_id)
		time_out = jiffies + msecs_to_jiffies(WLTX_FOD_MON_DEBOUNCE);
	di->alarm_id = cur_id;
	if (!time_after(jiffies, time_out))
		return;

	wltx_update_alarm_data(&di->cfg.fod_alarm[cur_id].alarm, TX_ALARM_SRC_FOD);
	di->mon_delay = di->cfg.fod_alarm[cur_id].delay;
}

static void wltx_fod_monitor(struct wltx_fod_dev_info *di)
{
	wltx_monitor_fod_alarm(di);
}

static void wltx_fod_monitor_work(struct work_struct *work)
{
	struct wltx_fod_dev_info *di = container_of(work,
		struct wltx_fod_dev_info, mon_work.work);

	if (!di || !di->need_monitor)
		return;

	wltx_fod_monitor(di);

	if (di->mon_delay > 0) {
		schedule_delayed_work(&di->mon_work,
			msecs_to_jiffies(di->mon_delay));
		di->mon_delay = 0;
		return;
	}

	schedule_delayed_work(&di->mon_work,
		msecs_to_jiffies(WLTX_FOD_MON_INTERVAL));
}

void wltx_start_monitor_fod(struct wltx_fod_cfg *cfg, const unsigned int delay)
{
	struct wltx_fod_dev_info *di = g_tx_fod_di;

	if (!di || !cfg || wltx_cap_get_cur_id(WLTRX_DRV_MAIN) != WLTX_HIGH_PWR2_CAP)
		return;

	hwlog_info("start monitor fod_alarm\n");
	if (delayed_work_pending(&di->mon_work))
		cancel_delayed_work_sync(&di->mon_work);
	di->need_monitor = true;
	di->mon_delay = 0;
	di->alarm_id = -1;
	memcpy(&di->cfg, cfg, sizeof(di->cfg));
	schedule_delayed_work(&di->mon_work, msecs_to_jiffies(delay));
}

void wltx_stop_monitor_fod(void)
{
	struct wltx_fod_dev_info *di = g_tx_fod_di;

	if (!di)
		return;

	hwlog_info("stop monitor fod\n");
	di->need_monitor = false;
	di->stop_prevfod_chk = true;
}

void wltx_reset_current_fod_para(void)
{
	struct wltx_fod_dev_info *di = g_tx_fod_di;

	if (!di)
		return;

	di->curfod_chk.ping_times = 0;
	di->curfod_chk.ilim = 0;
}

static bool wltx_prevfod_ptrx_err_check(struct wltx_fod_dev_info *di, int ptx, int prx)
{
	int i;
	int pwr_src;

	if (di->tx_prevfod_ptrx_err_cnt_level <= 0)
		return true;

	if ((ptx <= 0) || (prx <= 0) || (ptx - prx < 0))
		return false;

	pwr_src = wltx_get_cur_pwr_src();
	for (i = 0; i < di->tx_prevfod_ptrx_err_cnt_level; i++) {
		if (pwr_src != di->tx_prevfod_ptrx_err_cnt[i].pwr_src)
			continue;
		if (di->tx_prevfod_ptrx_err_cnt[i].ptrx_err_cnt <= 0)
			break;
		if ((di->tx_prevfod_ptrx_err_cnt[i].ptx_min > 0) &&
			(ptx < di->tx_prevfod_ptrx_err_cnt[i].ptx_min))
			di->ptrx_err_cnt++;
		else if ((di->tx_prevfod_ptrx_err_cnt[i].prx_min > 0) &&
			(prx < di->tx_prevfod_ptrx_err_cnt[i].prx_min))
			di->ptrx_err_cnt++;

		if (di->ptrx_err_cnt >= di->tx_prevfod_ptrx_err_cnt[i].ptrx_err_cnt)
			return false;
		break;
	}

	return true;
}

static void wltx_prevfod_count(struct wltx_fod_dev_info *di, int *cnt, int idx)
{
	int ret, i;
	int ploss;
	int ptx = 0;
	int prx = 0;
	int pwr_src;

	ret = wltx_ic_get_ptx(WLTRX_IC_MAIN, (u32 *)&ptx);
	ret += wltx_ic_get_prx(WLTRX_IC_MAIN, (u32 *)&prx);
	if (ret) {
		hwlog_err("handle_fod_chk_event: get ptx/prx fail\n");
		return;
	}

	ploss = ptx - prx;
	hwlog_info("prevfod_count[%d] ptx=%d prx=%d ploss=%d\n", idx, ptx, prx, ploss);
	if (!wltx_prevfod_ptrx_err_check(di, ptx, prx)) {
		hwlog_err("ptrx_err_cnt=%d\n", di->ptrx_err_cnt);
		di->stop_prevfod_chk = true;
		if (wltx_pwr_prevfod_limit_handler())
			power_event_bnc_notify(POWER_BNT_WLTX, POWER_NE_WLTX_TX_FOD, NULL);
		return;
	}
	if ((ptx <= 0) && (prx <= 0))
		ploss = WLTX_PREVFOD_CHK_MAX_PLOSS;
	pwr_src = wltx_get_cur_pwr_src();
	for (i = 0; i < di->prevfod_cfg.level; i++) {
		if ((di->prevfod_cfg.prevfod_alarm[i].pwr_src >= 0) &&
			(pwr_src != di->prevfod_cfg.prevfod_alarm[i].pwr_src))
			continue;
		if ((ploss >= di->prevfod_cfg.prevfod_alarm[i].ploss_lth) &&
			(ploss < di->prevfod_cfg.prevfod_alarm[i].ploss_hth))
			cnt[i]++;
	}
}

static void wltx_prevfod_act(struct wltx_fod_dev_info *di, int *cnt)
{
	int i;
	struct wltx_alarm_prevfod_para *para;
	int ilimit;

	for (i = di->prevfod_cfg.level - 1; i >= 0 ; i--) {
		para = &di->prevfod_cfg.prevfod_alarm[i];
		if (!para)
			continue;
		hwlog_info("[prevfod_act][%d] match_cnt=%d th=%d\n",
			i, cnt[i], para->cnt_th);
		if (cnt[i] < para->cnt_th)
			continue;
		if (para->ilim < 0) {
			power_event_bnc_notify(POWER_BNT_WLTX,
				POWER_NE_WLTX_TX_FOD, NULL);
		} else if (para->ilim == 0) {
			(void)wltx_pwr_prevfod_limit_handler();
		} else {
			if (wltx_msleep(WLTX_PREVFOD_ALARM_DELAY))
				return;
			wltx_update_alarm_data(&para->alarm, TX_ALARM_SRC_PREVFOD);
			ilimit = power_min_positive(para->ilim, di->curfod_chk.ilim);
			wltx_ic_set_ilim(WLTRX_IC_MAIN, ilimit);
		}
		hwlog_info("[prevfod_act] ilim=%d\n", ilimit);
		return;
	}
}

static void wltx_prevfod_check_work(struct work_struct *work)
{
	int i;
	int *cnt;
	struct wltx_fod_dev_info *di = container_of(work,
		struct wltx_fod_dev_info, prevfod_chk_work.work);

	if (!di || (di->prevfod_cfg.level <= 0) || di->stop_prevfod_chk)
		return;

	cnt = kzalloc(sizeof(int) * di->prevfod_cfg.level, GFP_KERNEL);
	if (!cnt)
		return;

	wltx_ic_prevfod_check(WLTRX_IC_MAIN, WLTX_PREVFOD_CHK_START);
	for (i = 0; i < WLTX_PREVFOD_CHK_CNT; i++) {
		wltx_prevfod_count(di, cnt, i);
		if (di->stop_prevfod_chk || wltx_msleep(WLTX_PREVFOD_CHK_INTERVAL))
			goto exit;
	}

	wltx_prevfod_act(di, cnt);

exit:
	wltx_ic_prevfod_check(WLTRX_IC_MAIN, WLTX_PREVFOD_CHK_STOP);
	kfree(cnt);
}

void wltx_prevfod_check(struct wltx_prevfod_cfg *cfg)
{
	struct wltx_fod_dev_info *di = g_tx_fod_di;

	if (!di || !cfg || (cfg->level <= 0))
		return;

	hwlog_info("start prevfod check: index = %d\n", cfg->index);
	di->stop_prevfod_chk = false;
	di->ptrx_err_cnt = 0;
	memcpy(&di->prevfod_cfg, cfg, sizeof(di->prevfod_cfg));
	cancel_delayed_work_sync(&di->prevfod_chk_work);
	schedule_delayed_work(&di->prevfod_chk_work,
		msecs_to_jiffies(WLTX_PREVFOD_CHK_DELAY));
}

static void wltx_parse_tx_prevfod_ptrx_err_cnt(struct wltx_fod_dev_info *di)
{
	int i;
	int len;
	struct device_node *np = wltx_ic_get_dev_node(WLTRX_IC_MAIN);

	if (!np)
		return;

	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np,
		"tx_prevfod_ptrx_err_cnt", (int *)di->tx_prevfod_ptrx_err_cnt,
		WLTX_PREVFOD_PTRX_ERR_CNT_ROW, WLTX_PREVFOD_PTRX_ERR_CNT_COL);
	if (len <= 0) {
		di->tx_prevfod_ptrx_err_cnt_level = 0;
		return;
	}

	di->tx_prevfod_ptrx_err_cnt_level = len / WLTX_PREVFOD_PTRX_ERR_CNT_COL;
	for (i = 0; i < di->tx_prevfod_ptrx_err_cnt_level; i++)
		hwlog_info("[tx_prevfod_ptrx_err_cnt][%d] pwr_src:%d ptx_min:%d prx_min:%d ptrx_err_cnt:%d\n",
			i, di->tx_prevfod_ptrx_err_cnt[i].pwr_src,
			di->tx_prevfod_ptrx_err_cnt[i].ptx_min,
			di->tx_prevfod_ptrx_err_cnt[i].prx_min,
			di->tx_prevfod_ptrx_err_cnt[i].ptrx_err_cnt);
}

static void wltx_current_fod_act(int ilimit)
{
	hwlog_info("%s: ilimt = %d\n", __func__, ilimit);
	if (ilimit == WLTX_CURFOD_CHK_ACT_NONE)
		return;

	if (ilimit == WLTX_CURFOD_CHK_ACT_SWITCH_PWR) {
		wltx_pwr_prevfod_limit_handler();
		return;
	}
	wltx_ic_set_ilim(WLTRX_IC_MAIN, ilimit);
}

static void wltx_ping_current_fod_check(struct wltx_current_fod_chk *curfod_chk, int tx_iin)
{
	int tx_iin_avg = 0;
	int i;
	struct wltx_current_fod_cfg *cfg = NULL;
	struct wltx_dev_info *di = wltx_get_dev_info();

	if (!di || !curfod_chk)
		return;

	if (curfod_chk->ping_times >= WLTX_CURRENT_FOD_MAX_PING_TIMES)
		return;

	if (tx_iin == 0) {
		hwlog_err("%s:abnormal tx iin\n", __func__);
		return;
	}

	curfod_chk->ping_current[curfod_chk->ping_times++] = tx_iin;
	hwlog_info("%s: time:%d current:%d\n", __func__, curfod_chk->ping_times, tx_iin);

	if (curfod_chk->ping_times < WLTX_CURRENT_FOD_MAX_PING_TIMES)
		return;

	for (i = 0; i < WLTX_CURRENT_FOD_MAX_PING_TIMES; i++)
		tx_iin_avg += curfod_chk->ping_current[i];

	tx_iin_avg = tx_iin_avg / WLTX_CURRENT_FOD_MAX_PING_TIMES;
	cfg = &curfod_chk->curfod_cfg;
	for (i = 0; i < cfg->level; i++) {
		if (di->cur_pwr_src != cfg->curfod_para[i].pwr_src)
			continue;
		if (tx_iin_avg >= cfg->curfod_para[i].ping_current_min &&
			tx_iin_avg < cfg->curfod_para[i].ping_current_max)
			break;
	}

	if (i == cfg->level)
		return;

	curfod_chk->ilim = cfg->curfod_para[i].ilimit;
	wltx_current_fod_act(cfg->curfod_para[i].ilimit);
}

static void wltx_ss_current_fod_check(struct wltx_current_fod_chk *curfod_chk, int tx_iin)
{
	int i;
	struct wltx_current_fod_cfg *cfg = NULL;
	struct wltx_dev_info *di = wltx_get_dev_info();

	if (!di || !curfod_chk)
		return;

	if (curfod_chk->ilim != 0)
		return;

	cfg = &curfod_chk->curfod_cfg;
	hwlog_info("%s: ss current:%d\n", __func__, tx_iin);

	for (i = 0; i < cfg->level; i++) {
		if (di->cur_pwr_src != cfg->curfod_para[i].pwr_src)
			continue;
		if (tx_iin >= cfg->curfod_para[i].ss_current_min &&
			tx_iin < cfg->curfod_para[i].ss_current_max)
			break;
	}

	if (i == cfg->level)
		return;

	curfod_chk->ilim = cfg->curfod_para[i].ilimit;
	wltx_current_fod_act(cfg->curfod_para[i].ilimit);
}

static int wltx_current_fod_notifier_call(struct notifier_block *curfod_nb,
	unsigned long event, void *data)
{
	struct wltx_fod_dev_info *di =
		container_of(curfod_nb, struct wltx_fod_dev_info, curfod_nb);
	u16 iin = 0;

	if (!di)
		return NOTIFY_OK;

	if (wltx_ic_get_curfod_iin(WLTRX_IC_MAIN, &iin))
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_WLTX_PING_RX:
		wltx_ping_current_fod_check(&di->curfod_chk, (int)iin);
		return NOTIFY_OK;
	case POWER_NE_WLTX_RX_SS:
		wltx_ss_current_fod_check(&di->curfod_chk, (int)iin);
		return NOTIFY_OK;
	default:
		return NOTIFY_OK;
	}
}

static void wltx_current_fod_parse_dts(struct wltx_fod_dev_info *di)
{
	int i;
	int len;
	struct wltx_current_fod_cfg *cfg = NULL;
	struct device_node *np = wltx_ic_get_dev_node(WLTRX_IC_MAIN);

	if (!np || !di)
		return;

	cfg = &di->curfod_chk.curfod_cfg;
	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np,
		"tx_current_fod_para", (int *)cfg->curfod_para,
		WLTX_CURRENT_FOD_PARA_ROW, WLTX_CURRENT_FOD_PARA_COL);
	if (len <= 0) {
		cfg->level = 0;
		return;
	}

	cfg->level = len / WLTX_CURRENT_FOD_PARA_COL;
	for (i = 0; i < cfg->level; i++)
		hwlog_info("current fod para[%d] pwr_src:%d ping_current_min:%d ping_current_max:%d \
			ss_current_min:%d ss_current_max:%d ilim:%d\n", i,
			cfg->curfod_para[i].pwr_src,
			cfg->curfod_para[i].ping_current_min,
			cfg->curfod_para[i].ping_current_max,
			cfg->curfod_para[i].ss_current_min,
			cfg->curfod_para[i].ss_current_max,
			cfg->curfod_para[i].ilimit);
}

#ifdef CONFIG_HUAWEI_POWER_DEBUG
static ssize_t wltx_dbg_curfod_cfg_store(void *dev_data, const char *buf, size_t size)
{
	struct wltx_fod_dev_info *di = dev_data;
	struct wltx_current_fod_cfg *cfg = NULL;
	struct wltx_current_fod_para *para = NULL;
	int num = 0;

	if (!buf || !di) {
		hwlog_err("buf or di is null\n");
		return -EINVAL;
	}

	cfg = &di->curfod_chk.curfod_cfg;
	para = cfg->curfod_para;
	hwlog_info("%s get input:%s\n", __func__, buf);
	if (power_strsep_to_array(buf, (int *)para, " ", WLTX_CURFOD_DBG_MAX_PARA_SIZE, &num)) {
		hwlog_err("fail to get para\n");
		return -EINVAL;
	}

	if ((num <= 0) || (num % WLTX_CURRENT_FOD_PARA_COL != 0)) {
		hwlog_err("para num is fault\n");
		return -EINVAL;
	}

	if (cfg->level == 0) {
		di->curfod_nb.notifier_call = wltx_current_fod_notifier_call;
		power_event_bnc_register(POWER_BNT_WLTX, &di->curfod_nb);
	}

	cfg->level = num / WLTX_CURRENT_FOD_PARA_COL;
	return size;
}
#endif /* CONFIG_HUAWEI_POWER_DEBUG */

static void wltx_fod_register_power_debug(struct wltx_fod_dev_info *di)
{
#ifdef CONFIG_HUAWEI_POWER_DEBUG
	power_dbg_ops_register("wireless_tx_fod", "curfod_para", di,
		NULL, wltx_dbg_curfod_cfg_store);
#endif /* CONFIG_HUAWEI_POWER_DEBUG */
}

static int __init wltx_fod_init(void)
{
	struct wltx_fod_dev_info *di = NULL;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_tx_fod_di = di;

	wltx_parse_tx_prevfod_ptrx_err_cnt(di);
	wltx_current_fod_parse_dts(di);
	if (di->curfod_chk.curfod_cfg.level > 0) {
		di->curfod_nb.notifier_call = wltx_current_fod_notifier_call;
		power_event_bnc_register(POWER_BNT_WLTX, &di->curfod_nb);
	}
	wltx_fod_register_power_debug(di);

	INIT_DELAYED_WORK(&di->mon_work, wltx_fod_monitor_work);
	INIT_DELAYED_WORK(&di->prevfod_chk_work, wltx_prevfod_check_work);
	return 0;
}

static void __exit wltx_fod_exit(void)
{
	struct wltx_fod_dev_info *di = g_tx_fod_di;

	kfree(di);
	g_tx_fod_di = NULL;
}

device_initcall(wltx_fod_init);
module_exit(wltx_fod_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("wireless tx fod driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
