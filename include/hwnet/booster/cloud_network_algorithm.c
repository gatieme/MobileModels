/**
 * cloud_cellular_algorithm.c
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
*/

#include <linux/spinlock.h>
#include <linux/hrtimer.h>
#include <linux/slab.h>
#include "cloud_network_algorithm.h"
#include "cloud_network_utils.h"
#include "cloud_network_detect.h"


#define PROBE_TIME_INTERVAL 300
#define RESPOND_TIMEOUT_DUR 5000
#define ARR_LENGTH 20
#define DELAY_VAL_BAD_TH 80
#define DELAY_VAL_GOOD_TH 60
#define DELAY_RELATIVE_BAD_TH 20
#define DELAY_RELATIVE_GOOD_TH 10
#define DELAY_GRAD_BAD_TH 1
#define DELAY_GRAD_GOOD_TH 0
#define DELAY_GRAD_INC_TH 5
#define LOSSRATE_BAD_TH 6
#define LOSSRATE_GOOD_TH 4
#define CNT_BAD 3
#define CNT_GOOD (-3)
#define MAX_LOSS_RATE 100
#define DOUBLE_NUMBER 2
#define DOUBLE_DOUBLE_NUMBER 4
#define MIN_QUEUE_LENGTH_FOR_GRAD 2

typedef struct {
	int value; // 当前值，加入到queue之前和之后都保持
	int grad_val; // 梯度值，获取到本次value后记录本次的梯度值，梯度值需要明确数据类型
	int last_grad_val; // 上一次的梯度值,用于和本次梯度的比较
	int min_val; // queue中的最小值；
	int relative_val; // value-min_val的值，用于标识当前探测值与最小值的差值，如果差值较大，则认为链路波动较大；
	int queue[ARR_LENGTH]; // 队列，记录链路的连续探测结果
	int head; // 环形队列头
	int tail; // 环形队列尾
} path_info_stat;

typedef struct {
	int val_cnt_bad; // 实际值小于阈值的次数计数，包括时延，丢包等；负值表示变好的次数，正值表示变差的次数
	int relative_cnt_bad; // 相对值的次数计数,三次相对值统计结果小于阈值，认为链路质量差；负值表示变好的次数，正值表示变差的次数
	int grad_cnt_bad; // 梯度的计数，梯度持续变差三次认为变坏趋势增加，负值表示变好的次数，正值表示变差的次数
} path_info_cnt; // path_info中任意一个满足条件都会触发链路质量差的判决

typedef enum {
	PERFORM_NO_VALUE = 0,
	PERFORM_BAD,
	PERFORM_FLUCTUATE,
	PERFORM_GOOD,
} perform_level;

typedef struct {
	bool is_usage;
	struct hrtimer timer;
	int lossrate;
	path_info_cnt lossrate_cnt; // 三次连续丢包率的统计
	path_info_stat delay_stat;
	path_info_cnt delay_cnt; // 三次连续时延低于预期认为质量差
} path_info;

typedef struct {
	path_info cellular1;
	path_info cellular2;
	algorithm_path exp_status; // 本次算法计算后的输出建议，是用蜂窝1，蜂窝2还是双路
	algorithm_path real_status; // 当前链路选择的实际值
	status_change_callback status_change; // 外部提供的回调函数，通知外部当前算法的建议结果
} algorithm_ctx;

static algorithm_ctx *g_algCtx __read_mostly;

static path_info* path_type_to_info(algorithm_path path_type)
{
	switch (path_type) {
	case DETECT_PATH_BIT_MODEM_1:
		return &(g_algCtx->cellular1);
	case DETECT_PATH_BIT_MODEM_2:
		return &(g_algCtx->cellular2);
	// WiFi等其他链路在此增加case条件即可；
	default:
		log_err("cloud cellular algorithm, algorithm utils path type error");
		return NULL;
	}
}

static bool is_queue_full(int head, int tail, int size)
{
	if (size == 0) {
		log_err("input error, size is zero!");
		return true;
	}
	return (tail + 1) % size == head;
}

// 获取path_info_stat的queue中的最小值
static int get_arr_min(path_info_stat* stat)
{
	if (unlikely(stat == NULL)) {
		log_err("cloud cellular algorithm get array minimum value, stat null pointer error");
		return ERROR;
	}
	if (stat->head == stat->tail) {
		log_err("cloud cellular algorithm get array minimum value, queue is empty");
		return 0;
	}
	int i;
	int out = stat->queue[0];
	for (i = stat->head; i != stat->tail; i = (i + 1) % ARR_LENGTH) {
		if (out > stat->queue[i])
			out = stat->queue[i];
	}
	return out;
}

static int get_queue_size(int head, int tail, int size)
{
	if (unlikely(size == 0)) {
		log_err("size == 0");
		return ERROR;
	}
	return (tail - head + size) % size;
}

/*
	更新path_info中的path_info_stat信息
	value: input，本次探测到的值，如时延
*/
static void update_path_stat(path_info_stat* stat, int value)
{
	if (unlikely(stat == NULL)) {
		log_err("cloud cellular algorithm update path stat, stat null potiner error");
		return;
	}
	
	stat->value = value;
	stat->queue[stat->tail] = value;

	// 仅当队列满才会计算最小值
	if (is_queue_full(stat->head, stat->tail, ARR_LENGTH)) {
		stat->min_val = get_arr_min(stat);
		stat->head = (stat->head + 1) % ARR_LENGTH;
		stat->relative_val = value - stat->min_val;
	} else {
		stat->min_val = value;
		stat->relative_val = 0;
	}
	// 计算梯度值，需要大于2个数据才可以计算
	if (get_queue_size(stat->head, stat->tail, ARR_LENGTH) > MIN_QUEUE_LENGTH_FOR_GRAD) {
		// last_val&llast_val用于计算上次的梯度值；
		int last_val = stat->queue[(stat->tail + ARR_LENGTH - 1) % ARR_LENGTH];
		int llast_val = stat->queue[(stat->tail + ARR_LENGTH - 2) % ARR_LENGTH];
		stat->grad_val = (value - last_val);
		stat->last_grad_val = (last_val - llast_val);
	} else {
		stat->grad_val = 0;
		stat->last_grad_val = 0;
	}

	stat->tail = (stat->tail + 1) % ARR_LENGTH;
}

static int init_path_info(path_info *path_ptr)
{
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm init path info, pointer error");
		return ERROR;
	}
		
	path_ptr->lossrate = 0;
	path_ptr->delay_stat.value = 0;
	path_ptr->delay_stat.head = 0;
	path_ptr->delay_stat.tail = 0;
	path_ptr->delay_cnt.grad_cnt_bad = 0;
	path_ptr->delay_cnt.relative_cnt_bad = 0;
	path_ptr->delay_cnt.val_cnt_bad = 0;
	path_ptr->lossrate_cnt.grad_cnt_bad = 0;
	path_ptr->lossrate_cnt.relative_cnt_bad = 0;
	path_ptr->lossrate_cnt.val_cnt_bad = 0;
	return SUCCESS;
}

/*
	val:本次探测到的值；
*/
static void update_stat_count(int *counter, int val, int upper_bound, int lower_bound)
{
	if (unlikely(counter == NULL)) {
		log_err("cloud cellular algorithm update statistic count, counter null pointer error");
		return;
	}
	/*
		在好的情况下，如果出现一次差，则认为变化趋势时变差，在差的情况下出现一次好，则认为变化趋势时变好
	*/
	if (val >= upper_bound) {
		if (*counter < 0) {
			*counter = 1;
		} else {
			*counter += 1;
		}
	} else if (val < lower_bound) {
		if (*counter > 0) {
			*counter = -1;
		} else {
			*counter -= 1;
		}
	} else { // 在lower_bound和upper_bound之间counter要设置为0，表示满足预期，没有变好或者变差的趋势
		*counter = 0;
	}
}

static int sgn_func(int val)
{
	if (val > 0) {
		return 1;
	} else if (val < 0) {
		return -1;
	} else {
		return 0;
	}
}

static int update_path_count(algorithm_path path_type)
{
	path_info *path_ptr = path_type_to_info(path_type);
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm update path count, null pointer error");
		return ERROR;
	}

	update_stat_count(&(path_ptr->delay_cnt.val_cnt_bad),
		path_ptr->delay_stat.value, DELAY_VAL_BAD_TH, DELAY_VAL_GOOD_TH);
	update_stat_count(&(path_ptr->delay_cnt.relative_cnt_bad),
		path_ptr->delay_stat.relative_val, DELAY_RELATIVE_BAD_TH, DELAY_RELATIVE_GOOD_TH);
	update_stat_count(&(path_ptr->delay_cnt.grad_cnt_bad),
		sgn_func(path_ptr->delay_stat.grad_val), DELAY_GRAD_BAD_TH, DELAY_GRAD_GOOD_TH);
	
	/* lossrate不存在state信息，值需要更新cnt_bad */
	update_stat_count(&(path_ptr->lossrate_cnt.val_cnt_bad),
		path_ptr->lossrate, LOSSRATE_BAD_TH, LOSSRATE_GOOD_TH);
	return SUCCESS;
}

/*
	1. 评估链路质量的入口函数，用于联络切换判断，如果满足则需要启动链路切换
	2. 评估逻辑：
	评估Bad：
		1）时延梯度>上次时延梯度>限制值，或者
		2）时延梯度连续三次变差，或者
		3）时延、时延相对值、丢包，任一值连续统计三次不达标

	评估Good：
		1）时延、时延相对值、丢包，所有值统计连续三次较优
	评估一般：
		Others
*/
static perform_level evaluate_link_quality(algorithm_path path_type)
{
	path_info *path_ptr = path_type_to_info(path_type);
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm evaluate link quality, null pointer error");
		return PERFORM_NO_VALUE;
	}
	perform_level ret;
	ret = PERFORM_FLUCTUATE;

	if (path_ptr->delay_stat.grad_val > DELAY_GRAD_INC_TH && path_ptr->delay_stat.last_grad_val > DELAY_GRAD_INC_TH
		&& path_ptr->delay_stat.grad_val > path_ptr->delay_stat.last_grad_val)
		ret = PERFORM_BAD;

	if (path_ptr->delay_cnt.val_cnt_bad >= CNT_BAD || path_ptr->delay_cnt.relative_cnt_bad >= CNT_BAD
		|| path_ptr->delay_cnt.grad_cnt_bad >= CNT_BAD || path_ptr->lossrate_cnt.val_cnt_bad >= CNT_BAD)
		ret = PERFORM_BAD;

	if (path_ptr->delay_cnt.val_cnt_bad <= CNT_GOOD && path_ptr->delay_cnt.relative_cnt_bad <= CNT_GOOD
		&& path_ptr->lossrate_cnt.val_cnt_bad <= CNT_GOOD)
		ret = PERFORM_GOOD;

	log_info("cloud cellular algorithm, evaluate_link_quality result:%d", ret);
	return ret;
}

/*
	收到探测包之后，外部模块会调用该函数，通知当前获取到的rtt，丢包率等信息
	限制：当前外部的探测结果要求是串行调用，不支持并发
*/
static void cellular_usage_path_respond(int path_type, u32 rtt, int average_rtt, int loss_rate)
{
	algorithm_path temp_path_type = (algorithm_path)path_type;
	if (rtt < 0 || loss_rate < 0 || loss_rate > MAX_LOSS_RATE) {
		log_err("cloud cellular algorithm cellular usage path respond, Invalid parameter. rtt= %d, loss_rate = %d", rtt, loss_rate);
		return;
	}
	log_info("cellular usage path respond, rtt is %d, loss_rate is %d", rtt, loss_rate);

	perform_level ret = PERFORM_NO_VALUE;
	path_info *path_ptr = path_type_to_info(temp_path_type);
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm cellular usage path respond, path null pointer error");
		return;
	}
	if (!path_ptr->is_usage)
		return;
	/*
		在启动算法时timer已经启动，先停止
	*/
	if (hrtimer_active(&path_ptr->timer))
		hrtimer_cancel(&(path_ptr->timer));

	hrtimer_start(&(path_ptr->timer), ms_to_ktime(RESPOND_TIMEOUT_DUR), HRTIMER_MODE_REL);
	path_ptr->lossrate = loss_rate;
	update_path_stat(&(path_ptr->delay_stat), rtt);
	update_path_count(path_type);
	ret =  evaluate_link_quality(path_type);
	switch (ret) {
	case PERFORM_BAD:
		if (!g_algCtx->cellular1.is_usage || !g_algCtx->cellular2.is_usage) {
			g_algCtx->exp_status = DETECT_PATH_BIT_MODEM_1 | DETECT_PATH_BIT_MODEM_2;
			g_algCtx->status_change(g_algCtx->exp_status);
		}
		break;
	case PERFORM_GOOD:
		if (g_algCtx->cellular1.is_usage && g_algCtx->cellular2.is_usage) {
			if (path_type == PATH_MODEM_1) {
				g_algCtx->exp_status = DETECT_PATH_BIT_MODEM_1;
			} else if (path_type == PATH_MODEM_2) {
				g_algCtx->exp_status = DETECT_PATH_BIT_MODEM_2;
			}
			g_algCtx->status_change(g_algCtx->exp_status);
		}
		break;
	case PERFORM_FLUCTUATE:
		break;
	default:
		log_err("cloud cellular algorithm, the evaluation result is incorrect");
		break;
	}
	return;
}

static enum hrtimer_restart usage_path_respond_timeout(struct hrtimer *timer)
{
	log_info("cloud cellular algorithm, usage path respond timeout");
	if (timer == NULL) {
		log_err("timer is null");
		return HRTIMER_NORESTART;
	}
	
	/*
	   如果双蜂窝没有开启，并且超时，这时表示单路的业务已经中断或者变差，
	   因此需要启动另一路。因为当前无法判断另外一路，因此先启动冗余；
	   因为任何一路不好，都需要切换为冗余模式，因此不需要关注超时的timer是关联哪个链路的
	*/
	if (!g_algCtx->cellular1.is_usage || !g_algCtx->cellular2.is_usage) {
		g_algCtx->exp_status = (DETECT_PATH_BIT_MODEM_1 | DETECT_PATH_BIT_MODEM_2); // 只要超时，当前又是单链路，则修改状态位双路冗余
		g_algCtx->status_change(g_algCtx->exp_status);
	}
	return HRTIMER_NORESTART;
}
static int start_timeout_timer(algorithm_path path_type)
{
	log_info("start timeout timer");
	path_info *path_ptr = path_type_to_info(path_type);
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm start_probe_path, path null pointer error");
		return ERROR;
	}
	if (hrtimer_active(&path_ptr->timer))
		hrtimer_cancel(&(path_ptr->timer));
	path_ptr->timer.function = usage_path_respond_timeout;
	hrtimer_start(&(path_ptr->timer), ms_to_ktime(RESPOND_TIMEOUT_DUR), HRTIMER_MODE_REL);
	return SUCCESS;
}

static int stop_timeout_timer(algorithm_path path_type)
{
	log_info("stop timeout timer");
	path_info *path_ptr = path_type_to_info(path_type);
	if (unlikely(path_ptr == NULL)) {
		log_err("cloud cellular algorithm start_probe_path, path null pointer error");
		return ERROR;
	}
	if (hrtimer_active(&path_ptr->timer))
		hrtimer_cancel(&(path_ptr->timer));
	init_path_info(path_ptr);
	return SUCCESS;
}

/*
	外部调用，用户通知算法模块，当前使用的链路有变化
	算法模块根据：
	0==》1  启动探测；
	1==》0停止探测；
	1==》other 改变探测状态
*/
int cellular_usage_notification(algorithm_path paths_in_use)
{
	log_info("cloud cellular algorithm, cellular usage notification");
	if (unlikely(g_algCtx == NULL)) {
		log_info("g_algCtx does not init!");
		return ERROR;
	}
	bool cellular1_usage = (paths_in_use & PATH_MODEM_1) > 0 ? true : false;
	bool cellular2_usage = (paths_in_use & PATH_MODEM_2) > 0 ? true : false;

	/* 如果当前的状态和传入的状态一致，说明探测已经启动 */
	if (g_algCtx->cellular1.is_usage != cellular1_usage) {
		if (cellular1_usage) {
			start_timeout_timer(DETECT_PATH_VAL_MODEM_1);
		} else {
			stop_timeout_timer(DETECT_PATH_VAL_MODEM_1);
		}
	}
	
	if (g_algCtx->cellular2.is_usage != cellular2_usage) {
		if (cellular2_usage) {
			start_timeout_timer(DETECT_PATH_VAL_MODEM_2);
		} else {
			stop_timeout_timer(DETECT_PATH_VAL_MODEM_2);
		}
	}
	
	int old_status = g_algCtx->real_status;
	g_algCtx->real_status = paths_in_use;
	g_algCtx->cellular1.is_usage = cellular1_usage;
	g_algCtx->cellular2.is_usage = cellular2_usage;
	
	if (old_status == 0 && g_algCtx->real_status != 0) {
		detect_module_start(ALGORITHM_MODULE_ID, PROBE_TIME_INTERVAL,
			(int)g_algCtx->real_status, cellular_usage_path_respond);
	} else if (old_status != 0 && g_algCtx->real_status == 0) {
		detect_module_stop(ALGORITHM_MODULE_ID);
	} else if (old_status != 0 && g_algCtx->real_status != 0) {
		change_detect_path(ALGORITHM_MODULE_ID, (int)g_algCtx->real_status);
	}
	g_algCtx->exp_status = DETECT_PATH_BIT_ERROR;
	return SUCCESS;
}

/*
	外部调用，用于启动整个算法，需要check入参是否合理
	算法处理逻辑：
	1. 外部调用cellular_algorithm_start，timer启动，超时触发timer的回调；
	2. 外部启用某一条链路有刷新时，调用cellular_usage_notification
	3. 外部收到回程报文时，主动调用cellular_usage_path_respond触发算法计算；
	4. 算法计算结果通过status_change_callback通知给外部应用模块；
	5. 考虑下传入参数的通用性
	paths_in_use是当前使用的链路，status_change是注册回调，用户执行切换动作；
*/
void cellular_algorithm_start(algorithm_path paths_in_use, status_change_callback status_change)
{
	log_info("cloud cellular algorithm, cellular algorithm start");
	if (g_algCtx != NULL) {
		log_info("cloud cellular algorithm, context has kmalloced");
		return;
	}
	g_algCtx = (algorithm_ctx *)kmalloc(sizeof(algorithm_ctx), GFP_ATOMIC);
	if (unlikely(g_algCtx == NULL)) {
		log_err("cloud cellular algorithm, context kmalloc failed");
		return;
	}

	g_algCtx->real_status = paths_in_use;
	if (paths_in_use > 0) {
		g_algCtx->exp_status = DETECT_PATH_BIT_ERROR;
		g_algCtx->status_change = status_change;
	}

	// 初始化路径1信息
	g_algCtx->cellular1.is_usage = (paths_in_use & PATH_MODEM_1) > 0 ? true : false;
	init_path_info(&(g_algCtx->cellular1));
	hrtimer_init(&(g_algCtx->cellular1.timer), CLOCK_MONOTONIC, HRTIMER_MODE_REL);

	// 初始化路径2信息
	g_algCtx->cellular2.is_usage = (paths_in_use & PATH_MODEM_2) > 0 ? true : false;
	init_path_info(&(g_algCtx->cellular2));
	hrtimer_init(&(g_algCtx->cellular2.timer), CLOCK_MONOTONIC, HRTIMER_MODE_REL);

	if (g_algCtx->real_status != DETECT_PATH_BIT_ERROR) {
		if (g_algCtx->cellular1.is_usage)
			start_timeout_timer(DETECT_PATH_VAL_MODEM_1);

		if (g_algCtx->cellular2.is_usage)
			start_timeout_timer(DETECT_PATH_VAL_MODEM_2);
		/* 启动探测模块，按照指定的interval通过cellular_usage_path_respond反馈指定路径的探测结果 */
		detect_module_start(ALGORITHM_MODULE_ID, PROBE_TIME_INTERVAL,
			(int)paths_in_use, cellular_usage_path_respond);
	}
}

/*
	外部调用，用于停止整个算法
*/
void cellular_algorithm_stop(void)
{
	log_info("cloud cellular algorithm, stop module exit");
	if (unlikely(g_algCtx == NULL)) {
		log_err("cloud cellular algorithm, cellular algorithm stop has exited");
		return;
	}
	
	detect_module_stop(ALGORITHM_MODULE_ID);
	if (hrtimer_active(&(g_algCtx->cellular1.timer)))
		hrtimer_cancel(&(g_algCtx->cellular1.timer));
	
	if (hrtimer_active(&(g_algCtx->cellular2.timer)))
		hrtimer_cancel(&(g_algCtx->cellular2.timer));
	kfree(g_algCtx);
	g_algCtx = NULL;
}

algorithm_path cellular_expect_status(void)
{
	return g_algCtx->exp_status;
}
