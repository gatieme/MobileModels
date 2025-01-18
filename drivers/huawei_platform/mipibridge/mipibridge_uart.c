/*
 * Huawei mipibridge uart driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#include "mipibridge.h"

#define MIPIBRIDGE_UART_STATE_EMPTY 0
#define MIPIBRIDGE_UART_STATE_FULL 1

#define MIPIBRIDGE_UART_OPEN 0
#define MIPIBRIDGE_UART_CLOSE 1

#define MIPIBRIDGE_UART_CLEAR_RECV 0
#define MIPIBRIDGE_UART_SET_RECV 1

#define MIPIBRIDGE_UART_CLEAR_SEND 1
#define MIPIBRIDGE_UART_SET_SEND 1

#define MIPIBRIDGE_UART_CTR_NO_INIT 0
#define MIPIBRIDGE_UART_CTR_INIT 1
/* keyboard use 27 */
#define MIPIBRIDGE_UART 28
#define PUBLIC_BUF_MAX (8 * 1024)
#define MIPIBRIDGE_UART_WRITE_TIMEOUT 1000
#define MIPIBRIDGE_UART_SEND_MAX 4000
#define MIPIBRIDGE_UART_BUFF_LEN 100

/* mipibridge uart */
struct _mipibridge_uart_recv {
	u8 buf[MIPIBRIDGE_UART_BUFF_LEN];
	int len;
	int buf_state;
	int recv_state;
	int send_state;
	int controll_init;
	int open_flag;
	int read_buf_len;
	int recv_buf_len;
	spinlock_t uart_lock;
	struct completion recv_complete;
	struct completion send_complete;
};

static struct _mipibridge_uart_recv g_uart_controll = {
	.buf = {0},
	.buf_state = MIPIBRIDGE_UART_STATE_EMPTY,
	.recv_state = MIPIBRIDGE_UART_CLEAR_RECV,
	.send_state = MIPIBRIDGE_UART_CLEAR_SEND,
	.controll_init = MIPIBRIDGE_UART_CTR_NO_INIT,
	.open_flag = MIPIBRIDGE_UART_CLOSE,
};

static struct tty_struct *g_mipibridge_tty = NULL;
static spinlock_t *g_uart_lock = &g_uart_controll.uart_lock;
static struct completion *g_recv_complete = &g_uart_controll.recv_complete;
static struct completion *g_send_complete = &g_uart_controll.send_complete;
static struct mipibridge_uart *g_uart = NULL;
static u8 g_recv_check_buf[MIPIBRIDGE_UART_BUFF_LEN] = {0};

static int mipibridge_tty_open(struct tty_struct *tty)
{
	if (!tty)
		return MIPI_BRIDGE_FAIL;

	/* don't do an wakeup for now */
	clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

	/* set mem already allocated */
	tty->receive_room = PUBLIC_BUF_MAX;
	/* Flush any pending characters in the driver and discipline. */
	tty_ldisc_flush(tty);
	tty_driver_flush_buffer(tty);
	mipibridge_infomsg("tty: open\n");
	return MIPI_BRIDGE_OK;
}

static void mipibridge_tty_close(struct tty_struct *tty)
{
	mipibridge_infomsg("tty: close\n");
	return;
}

static void mipibridge_tty_receive(struct tty_struct *tty,
	const unsigned char *cp, char *fp, int count)
{
	int ret;

	if (!tty || !cp || !g_uart || count > MIPIBRIDGE_UART_BUFF_LEN) {
		mipibridge_errmsg("tty/cp/fp/count/g_uart err!\n");
		return;
	}

	spin_lock(g_uart_lock);
	if (g_uart_controll.recv_state != MIPIBRIDGE_UART_SET_RECV) {
		mipibridge_errmsg("err recv_state=%d\n", g_uart_controll.recv_state);
		spin_unlock(g_uart_lock);
		return;
	}
	mipibridge_infomsg("count=%d\n", count);

	mb();
	/* optimize the read buff size */
	if (g_uart_controll.len + count > MIPIBRIDGE_UART_BUFF_LEN)
		count = MIPIBRIDGE_UART_BUFF_LEN - g_uart_controll.len;

	ret = memcpy_s(g_uart_controll.buf + g_uart_controll.len,
		MIPIBRIDGE_UART_BUFF_LEN - g_uart_controll.len, cp, count);
	if (ret < 0) {
		mipibridge_errmsg("memcpy_s err\n");
		spin_unlock(g_uart_lock);
		return;
	}

	g_uart_controll.len += count;
	if (g_uart_controll.read_buf_len > 0 && g_uart_controll.len >= g_uart_controll.read_buf_len) {
		g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_FULL;
		g_uart_controll.recv_state = MIPIBRIDGE_UART_CLEAR_RECV;
		complete(g_recv_complete);
	}

	if (g_uart_controll.recv_buf_len > 0 && g_uart_controll.len >= g_uart_controll.recv_buf_len) {
		g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_FULL;
		g_uart_controll.recv_state = MIPIBRIDGE_UART_CLEAR_RECV;
		schedule_delayed_work(&g_uart->recv_work, 0);
	}
	spin_unlock(g_uart_lock);

	return;
}

static void mipibridge_tty_wakeup(struct tty_struct *tty)
{
	if (!tty)
		return;
	/* clear wakeup flage for now */
	clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);

	spin_lock(g_uart_lock);
	if (g_uart_controll.send_state != MIPIBRIDGE_UART_SET_SEND) {
		spin_unlock(g_uart_lock);
		return;
	}
	g_uart_controll.send_state = MIPIBRIDGE_UART_CLEAR_SEND;
	spin_unlock(g_uart_lock);

	complete(g_send_complete);
	return;
}

static void mipibridge_tty_flush_buffer(struct tty_struct *tty)
{
	mipibridge_infomsg("tty: flush\n");
	return;
}

static struct tty_ldisc_ops mipibridge_ldisc_ops = {
	.magic = TTY_LDISC_MAGIC,
	.name = "mipibridge_tty",
	.open = mipibridge_tty_open,
	.close = mipibridge_tty_close,
	.receive_buf = mipibridge_tty_receive,
	.write_wakeup = mipibridge_tty_wakeup,
	.flush_buffer = mipibridge_tty_flush_buffer,
	.owner = THIS_MODULE
};

static void mipibridge_ktty_set_termios(struct tty_struct *tty, long baud_rate)
{
	struct ktermios ktermios;

	if (!tty)
		return;

	ktermios = tty->termios;
	/* close soft flowctrl */
	ktermios.c_iflag = 0;
	/* set uart cts/rts flowctrl */
	ktermios.c_cflag &= ~CRTSCTS;
	/* set csize */
	ktermios.c_cflag &= ~(CSIZE);
	ktermios.c_cflag |= CS8;
	/* set uart baudrate */
	ktermios.c_cflag &= ~CBAUD;
	ktermios.c_cflag |= BOTHER;
	tty_termios_encode_baud_rate(&ktermios, baud_rate, baud_rate);
	tty_set_termios(tty, &ktermios);
	mipibridge_errmsg("set baud_rate=%d, except=%d\n",
		(int)tty_termios_baud_rate(&tty->termios), (int)baud_rate);
}

static int mipibridge_uart_open(const char *uart_port, long baud, dev_t *dev_no)
{
	int ret = MIPI_BRIDGE_OK;

	if (!uart_port || !dev_no)
		return MIPI_BRIDGE_FAIL;

	/* open tty */
	g_mipibridge_tty = tty_kopen(*dev_no);
	if (IS_ERR_OR_NULL(g_mipibridge_tty)
		|| IS_ERR_OR_NULL(g_mipibridge_tty->ops)) {
		mipibridge_errmsg("open tty %s failed\n", uart_port);
		goto MIPIBRIDGE_KOPEN_ERROR;
	}

	if (g_mipibridge_tty->ops->open) {
		ret = g_mipibridge_tty->ops->open(g_mipibridge_tty, NULL);
	} else {
		mipibridge_errmsg("tty->ops->open is NULL\n");
		ret = MIPI_BRIDGE_FAIL;
	}

	if (ret) {
		tty_unlock(g_mipibridge_tty);
		goto MIPIBRIDGE_OPEN_ERROR;
	}

	mipibridge_ktty_set_termios(g_mipibridge_tty, baud);
	tty_unlock(g_mipibridge_tty);

	ret = tty_set_ldisc(g_mipibridge_tty, MIPIBRIDGE_UART);
	if (ret) {
		mipibridge_errmsg("tty_set_ldisc error\n");
		goto MIPIBRIDGE_LDISC_ERROR;
	}
	g_uart_controll.open_flag = MIPIBRIDGE_UART_OPEN;

	return MIPI_BRIDGE_OK;
MIPIBRIDGE_LDISC_ERROR:
	g_mipibridge_tty->ops->close(g_mipibridge_tty, NULL);
MIPIBRIDGE_OPEN_ERROR:
	tty_kclose(g_mipibridge_tty);
MIPIBRIDGE_KOPEN_ERROR:
	tty_unregister_ldisc(MIPIBRIDGE_UART);
	g_mipibridge_tty = NULL;
	return MIPI_BRIDGE_FAIL;
}

static int mipibridge_uart_init(const char *uart_port, long baud)
{
	int ret = MIPI_BRIDGE_OK;
	dev_t dev_no = 0;

	if (!uart_port)
		return MIPI_BRIDGE_FAIL;

	if (g_uart_controll.open_flag == MIPIBRIDGE_UART_OPEN) {
		mipibridge_errmsg("init have done\n");
		return MIPI_BRIDGE_OK;
	}

	ret = tty_register_ldisc(MIPIBRIDGE_UART, &mipibridge_ldisc_ops);
	if (ret != 0)
		mipibridge_errmsg("tty_register_ldisc error ret=%d\n", ret);

	ret = tty_dev_name_to_number(uart_port, &dev_no);
	if (ret != 0) {
		mipibridge_errmsg("dev to number tty:%s ret=%d\n", uart_port, ret);
		tty_unregister_ldisc(MIPIBRIDGE_UART);
		return MIPI_BRIDGE_FAIL;
	}

	ret = mipibridge_uart_open(uart_port, baud, &dev_no);
	if (ret < 0) {
		mipibridge_errmsg("open uart fail! tty:%s ret=%d\n", uart_port, ret);
		tty_unregister_ldisc(MIPIBRIDGE_UART);
		return MIPI_BRIDGE_FAIL;
	}

	mipibridge_infomsg("%s end\n", uart_port);

	return MIPI_BRIDGE_OK;
}

static void mipibridge_uart_clear_state(void)
{
	if (!g_mipibridge_tty)
		return;

	tty_ldisc_flush(g_mipibridge_tty);
	tty_driver_flush_buffer(g_mipibridge_tty);

	spin_lock(g_uart_lock);
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.recv_state = MIPIBRIDGE_UART_CLEAR_RECV;
	g_uart_controll.len = 0;
	spin_unlock(g_uart_lock);
	return;
}

int mipibridge_uart_read(u8 *buf, size_t *len, int time_out, int want_len)
{
	int ret = MIPI_BRIDGE_OK;

	if (!buf || !len)
		return MIPI_BRIDGE_FAIL;

	if (!g_mipibridge_tty) {
		*len = 0;
		return MIPI_BRIDGE_FAIL;
	}

	if (g_uart_controll.recv_buf_len) {
		mipibridge_infomsg("uart waiting err recv, not support read\n");
		return MIPI_BRIDGE_FAIL;
	}

	spin_lock(g_uart_lock);
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.recv_state = MIPIBRIDGE_UART_SET_RECV;
	g_uart_controll.len = 0;
	g_uart_controll.read_buf_len = want_len;
	spin_unlock(g_uart_lock);

	if (!wait_for_completion_timeout(g_recv_complete, msecs_to_jiffies(time_out))) {
		*len = 0;
		spin_lock(g_uart_lock);
		g_uart_controll.recv_state = MIPIBRIDGE_UART_CLEAR_RECV;
		spin_unlock(g_uart_lock);
		return -EIO;
	}

	spin_lock(g_uart_lock);
	*len = g_uart_controll.len;
	ret = memcpy_s(buf, MIPIBRIDGE_UART_BUFF_LEN, g_uart_controll.buf, g_uart_controll.len);
	if (ret < 0) {
		mipibridge_errmsg("memcpy_s err\n");
		spin_unlock(g_uart_lock);
		return MIPI_BRIDGE_FAIL;
	}
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.len = 0;
	g_uart_controll.read_buf_len = 0;
	spin_unlock(g_uart_lock);

	return MIPI_BRIDGE_OK;
}

int mipibridge_uart_write(u8 *buf, size_t len)
{
	unsigned int remain = len;
	int size_send = 0;
	int addr = 0;

	if (!buf || !g_mipibridge_tty || !g_mipibridge_tty->ops) {
		mipibridge_errmsg("buf, g_mipibridge_tty err!\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (g_uart_controll.recv_buf_len) {
		mipibridge_infomsg("uart waiting err recv, not support write\n");
		return MIPI_BRIDGE_FAIL;
	}

	addr = 0;
	while (remain > 0) {
		size_send = MIPIBRIDGE_UART_SEND_MAX > remain ? remain : MIPIBRIDGE_UART_SEND_MAX;
		set_bit(TTY_DO_WRITE_WAKEUP, &g_mipibridge_tty->flags);

		spin_lock(g_uart_lock);
		g_uart_controll.send_state = MIPIBRIDGE_UART_SET_SEND;
		spin_unlock(g_uart_lock);

		g_mipibridge_tty->ops->write(g_mipibridge_tty, buf + addr, size_send);
		if (!wait_for_completion_timeout(g_send_complete,
				msecs_to_jiffies(MIPIBRIDGE_UART_WRITE_TIMEOUT))) {
			spin_lock(g_uart_lock);
			g_uart_controll.send_state = MIPIBRIDGE_UART_CLEAR_SEND;
			spin_unlock(g_uart_lock);
			return -EIO;
		}
		remain -= size_send;
		addr += size_send;
	}
	return MIPI_BRIDGE_OK;
}

static int mipibridge_uart_deinit(void)
{
	if (g_uart_controll.open_flag != MIPIBRIDGE_UART_OPEN)
		return MIPI_BRIDGE_OK;

	if (!g_mipibridge_tty)
		return MIPI_BRIDGE_FAIL;

	tty_ldisc_release(g_mipibridge_tty);
	g_mipibridge_tty->ops->close(g_mipibridge_tty, NULL);
	tty_kclose(g_mipibridge_tty);
	tty_unregister_ldisc(MIPIBRIDGE_UART);
	g_mipibridge_tty = NULL;

	spin_lock(g_uart_lock);
	g_uart_controll.send_state = MIPIBRIDGE_UART_CLEAR_SEND;
	g_uart_controll.recv_state = MIPIBRIDGE_UART_CLEAR_RECV;
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.open_flag = MIPIBRIDGE_UART_CLOSE;
	spin_unlock(g_uart_lock);

	return MIPI_BRIDGE_OK;
}

static void mipibridge_uart_recv_check(struct work_struct *work)
{
	unsigned int len = 0;

	if (!g_uart || !g_uart->recv_fuc) {
		mipibridge_errmsg("g_uart/g_uart->recv_fuc err!\n");
		return;
	}

	if (down_trylock(&(g_uart->sem))) {
		mipibridge_infomsg("Now in recv\n");
		return;
	}

	spin_lock(g_uart_lock);
	len = g_uart_controll.len;
	if (memcpy_s(g_recv_check_buf, MIPIBRIDGE_UART_BUFF_LEN, g_uart_controll.buf, len) < 0) {
		mipibridge_errmsg("memcpy_s err\n");
		spin_unlock(g_uart_lock);
		up(&(g_uart->sem));
		return;
	}
	spin_unlock(g_uart_lock);

	g_uart->recv_fuc(g_recv_check_buf, len);

	spin_lock(g_uart_lock);
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.recv_state = MIPIBRIDGE_UART_SET_RECV;
	g_uart_controll.len = 0;
	spin_unlock(g_uart_lock);
	up(&(g_uart->sem));
}

int mipibridge_uart_recv_enable(int want_len)
{
	if (!g_uart || !g_uart->recv_fuc) {
		mipibridge_errmsg("uart or recv_fuc is null!\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (!g_uart->uart_recv_support || want_len == 0) {
		mipibridge_errmsg("not support recv or want_len is 0!\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (g_uart_controll.recv_state == MIPIBRIDGE_UART_SET_RECV) {
		mipibridge_errmsg("recv_state is reading!\n");
		return MIPI_BRIDGE_FAIL;
	}

	spin_lock(g_uart_lock);
	g_uart_controll.buf_state = MIPIBRIDGE_UART_STATE_EMPTY;
	g_uart_controll.recv_state = MIPIBRIDGE_UART_SET_RECV;
	g_uart_controll.len = 0;
	g_uart_controll.recv_buf_len = want_len;
	spin_unlock(g_uart_lock);

	INIT_DELAYED_WORK(&(g_uart->recv_work), mipibridge_uart_recv_check);
	sema_init(&(g_uart->sem), 1);

	return MIPI_BRIDGE_OK;
}

int mipibridge_uart_register(struct mipibridge_uart *uart)
{
	int ret = MIPI_BRIDGE_OK;

	mipibridge_infomsg("mipibridge_uart_register enter\n");
	g_uart = uart;
	if (!g_uart || !g_uart->tty_name) {
		mipibridge_errmsg("uart is null\n");
		return MIPI_BRIDGE_FAIL;
	}

	if (g_uart_controll.controll_init == MIPIBRIDGE_UART_CTR_NO_INIT) {
		spin_lock_init(g_uart_lock);
		init_completion(g_recv_complete);
		init_completion(g_send_complete);
		g_uart_controll.controll_init = MIPIBRIDGE_UART_CTR_INIT;
	}

	ret = mipibridge_uart_init(g_uart->tty_name, g_uart->default_baud);
	if (ret) {
		mipibridge_errmsg("uart init err!\n");
		return MIPI_BRIDGE_FAIL;
	}
	return MIPI_BRIDGE_OK;
}