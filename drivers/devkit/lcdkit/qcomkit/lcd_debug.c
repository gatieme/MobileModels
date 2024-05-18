/*
 * lcd_debug.c
 *
 * lcd debug function for lcd head file
 *
 * Copyright (c) 2021-2022 Honor Technologies Co., Ltd.
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

#include <linux/string.h>
#include "lcd_defs.h"
#include "lcd_debug.h"

static int dbg_type;
static int lcd_debug_level;
static int dbg_enable;
struct dsi_panel_cmds panel_on_cmds;

static int dbg_on_cmd(char *par);

struct debug_func item_func[] = {
	{ "PanelOnCommand", dbg_on_cmd },
};

struct debug_cmds cmd_list[] = {
	{ DEBUG_LEVEL_SET, "set_debug_level" },
	{ DEBUG_PARAM_CONFIG, "set_param_config" },
	{ DEBUG_WRITE_REG, "write_reg:" },
	{ DEBUG_READ_REG, "read_reg:" },
};

struct debug_buf dbg_buf;
/* show usage or print last read result */
static char read_debug_buf[LCD_DBG_BUFF_MAX];

struct dsi_read_desc read_reg;

bool is_valid_char(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}

static char hex_char_to_value(char ch)
{
	switch (ch) {
	case 'a' ... 'f':
		ch = 10 + (ch - 'a');
		break;
	case 'A' ... 'F':
		ch = 10 + (ch - 'A');
		break;
	case '0' ... '9':
		ch = ch - '0';
		break;
	}

	return ch;
}

void dump_buf(const char *buf, int cnt)
{
	int i;

	if (!buf) {
		LCD_ERR("buf is null\n");
		return;
	}
	for (i = 0; i < cnt; i++)
		LCD_DEBUG("buf[%d] = 0x%02x\n", i, buf[i]);
}

void dump_cmds_desc(struct dbg_dsi_cmd_desc *desc)
{
	if (!desc) {
		LCD_ERR("NULL point!\n");
		return;
	}
	LCD_DEBUG("dtype      = 0x%02x\n", desc->dtype);
	LCD_DEBUG("last       = 0x%02x\n", desc->last);
	LCD_DEBUG("vc         = 0x%02x\n", desc->vc);
	LCD_DEBUG("ack        = 0x%02x\n", desc->ack);
	LCD_DEBUG("wait       = 0x%02x\n", desc->wait);
	LCD_DEBUG("dlen0   = 0x%02x\n", desc->dlen0);
	LCD_DEBUG("dlen1       = 0x%02x\n", desc->dlen1);

	dump_buf(desc->payload, (int)(desc->dlen0 << 8 | desc->dlen1));
}

void dump_cmds(struct dsi_panel_cmds *cmds)
{
	int i;

	if (!cmds) {
		LCD_ERR("NULL point!\n");
		return;
	}
	LCD_DEBUG("blen       = 0x%02x\n", cmds->blen);
	LCD_DEBUG("cmd_cnt    = 0x%02x\n", cmds->cmd_cnt);
	LCD_DEBUG("link_state = 0x%02x\n", cmds->link_state);
	LCD_DEBUG("flags      = 0x%02x\n", cmds->flags);
	for (i = 0; i < cmds->cmd_cnt; i++)
		dump_cmds_desc(&cmds->cmds[i]);
}

/* convert string to lower case */
/* return: 0 - success, negative - fail */
static int str_to_lower(char *str)
{
	char *tmp = str;

	/* check param */
	if (!tmp)
		return -1;
	while (*tmp != '\0') {
		*tmp = tolower(*tmp);
		tmp++;
	}
	return 0;
}

/* check if string start with sub string */
/* return: 0 - success, negative - fail */
static int str_start_with(const char *str, const char *sub)
{
	/* check param */
	if (!str || !sub)
		return -EINVAL;
	return ((strncmp(str, sub, strlen(sub)) == 0) ? 0 : -1);
}

int str_to_del_invalid_ch(char *str)
{
	char *tmp = str;

	/* check param */
	if (!tmp)
		return -1;
	while (*str != '\0') {
		if (is_valid_char(*str) || *str == ' ' || *str == 'x' ||
			*str == 'X') {
			*tmp = *str;
			tmp++;
		}
		str++;
	}
	*tmp = '\0';
	return 0;
}

int str_to_del_ch(char *str, char ch)
{
	char *tmp = str;

	/* check param */
	if (!tmp)
		return -1;
	while (*str != '\0') {
		if (*str != ch) {
			*tmp = *str;
			tmp++;
		}
		str++;
	}
	*tmp = '\0';
	return 0;
}

/* parse config xml */
int parse_u8_digit(const char *in, char *out, int max)
{
	unsigned char ch = '\0';
	unsigned char last_char = 'Z';
	unsigned char last_ch = 'Z';
	int j = 0;
	int i = 0;
	int len;

	if (!in || !out) {
		LCD_ERR("in or out is null\n");
		return LCD_FAIL;
	}
	len = strlen(in);
	LCD_INFO("LEN = %d\n", len);
	while (len--) {
		ch = in[i++];
		if (last_ch == '0' && ((ch == 'x') || (ch == 'X'))) {
			j--;
			last_char = 'Z';
			continue;
		}
		last_ch = ch;
		if (!is_valid_char(ch)) {
			last_char = 'Z';
			continue;
		}
		if (last_char != 'Z') {
			/*
			 * two char value is possible like F0,
			 * so make it a single char
			 */
			--j;
			if (j >= max) {
				LCD_ERR("number is too much\n");
				return LCD_FAIL;
			}
			out[j] = (out[j] * LCD_HEX_BASE) +
				hex_char_to_value(ch);
			last_char = 'Z';
		} else {
			if (j >= max) {
				LCD_ERR("number is too much\n");
				return LCD_FAIL;
			}
			out[j] = hex_char_to_value(ch);
			last_char = out[j];
		}
		j++;
	}
	return j;
}

int parse_u32_digit(char *in, u8 *out, int len)
{
	char *delim = " ";
	int i = 0;
	char *str1 = NULL;
	char *str2 = NULL;

	if (!in || !out) {
		LCD_ERR("in or out is null\n");
		return LCD_FAIL;
	}

	str_to_del_invalid_ch(in);
	str1 = in;
	do {
		str2 = strstr(str1, delim);
		if (i >= len) {
			LCD_ERR("number is too much\n");
			return LCD_FAIL;
		}
		if (str2 == NULL) {
			out[i++] = simple_strtoul(str1, NULL, 0);
			break;
		}
		*str2 = 0;
		out[i++] = simple_strtoul(str1, NULL, 0);
		str2++;
		str1 = str2;
	} while (str2 != NULL);
	return i;
}

int dbg_parse_cmd(struct dsi_panel_cmds *pcmds, char *buf,
	int length)
{
	int blen;
	int len;
	char *bp = NULL;
	struct dsi_ctrl_hdr *dchdr = NULL;
	struct dbg_dsi_cmd_desc *newcmds = NULL;
	int i;
	int cnt = 0;

	if (!pcmds || !buf) {
		LCD_ERR("null pointer\n");
		return LCD_FAIL;
	}
	/* scan dcs commands */
	bp = buf;
	blen = length;
	len = blen;
	while (len > sizeof(*dchdr)) {
		dchdr = (struct dsi_ctrl_hdr *)bp;
		bp += sizeof(*dchdr);
		len -= sizeof(*dchdr);
		if (((dchdr->dlen0 << 8) | dchdr->dlen1) > len) {
			LCD_ERR("dtsi cmd=%x error, len=%d, cnt=%d\n",
				dchdr->dtype, ((dchdr->dlen0 << 8) | dchdr->dlen1), cnt);
			return LCD_FAIL;
		}
		bp += ((dchdr->dlen0 << 8) | dchdr->dlen1);
		len -= ((dchdr->dlen0 << 8) | dchdr->dlen1);
		cnt++;
	}
	if (len != 0) {
		LCD_ERR("dcs_cmd=%x len=%d error!\n", buf[0], blen);
		return LCD_FAIL;
	}
	newcmds = kzalloc(cnt * sizeof(*newcmds), GFP_KERNEL);
	if (newcmds == NULL) {
		LCD_ERR("kzalloc fail\n");
		return LCD_FAIL;
	}
	if (pcmds->cmds != NULL)
		kfree(pcmds->cmds);
	pcmds->cmds = newcmds;
	pcmds->cmd_cnt = cnt;
	pcmds->buf = buf;
	pcmds->blen = blen;
	bp = buf;
	len = blen;
	for (i = 0; i < cnt; i++) {
		dchdr = (struct dsi_ctrl_hdr *)bp;
		len -= sizeof(*dchdr);
		bp += sizeof(*dchdr);
		pcmds->cmds[i].dtype = dchdr->dtype;
		pcmds->cmds[i].last = dchdr->last;
		pcmds->cmds[i].vc = dchdr->vc;
		pcmds->cmds[i].ack = dchdr->ack;
		pcmds->cmds[i].wait = dchdr->wait;
		pcmds->cmds[i].dlen0 = dchdr->dlen0;
		pcmds->cmds[i].dlen1 = dchdr->dlen1;
		pcmds->cmds[i].payload = bp;
		bp += ((dchdr->dlen0 << 8) | dchdr->dlen1);
		len -= ((dchdr->dlen0 << 8) | dchdr->dlen1);
	}
	return 0;
}

void dbg_free_buf(void)
{
	kfree(dbg_buf.panel_on_buf);
}

static int dbg_on_cmd(char *par)
{
	int len;

	dbg_buf.panel_on_buf = kzalloc(LCD_CONFIG_TABLE_MAX_NUM, 0);
	if (!dbg_buf.panel_on_buf) {
		LCD_ERR("kzalloc fail\n");
		return LCD_FAIL;
	}
	len = parse_u8_digit(par, dbg_buf.panel_on_buf,
		LCD_CONFIG_TABLE_MAX_NUM);
	LCD_INFO("len = %d\n", len);
	if (len > 0)
		dbg_parse_cmd(&panel_on_cmds,
			dbg_buf.panel_on_buf, len);
	dbg_type |= DBG_TYPE_CMD_ON;
	dump_cmds(&panel_on_cmds);
	return LCD_OK;
}

static void dbg_set_dbg_level(int level)
{
	lcd_debug_level = level;
	return;
}

int *dbg_find_item(unsigned char *item)
{
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(item_func); i++) {
		if (!strncmp(item, item_func[i].name, strlen(item))) {
			LCD_INFO("found %s\n", item);
			return (int *)item_func[i].func;
		}
	}
	LCD_ERR("not found %s\n", item);
	return NULL;
}

DBG_FUNC func;
static int parse_status = PARSE_HEAD;
static int cnt;
static int count;

static int right_angle_bra_pro(unsigned char *item_name,
	unsigned char *tmp_name, unsigned char *data)
{
	int ret;

	if (!item_name || !tmp_name || !data) {
		LCD_ERR("null pointer\n");
		return LCD_FAIL;
	}
	if (parse_status == PARSE_HEAD) {
		func = (DBG_FUNC)dbg_find_item(item_name);
		cnt = 0;
		parse_status = RECEIVE_DATA;
	} else if (parse_status == PARSE_FINAL) {
		if (strncmp(item_name, tmp_name, strlen(item_name))) {
			LCD_ERR("item head match final\n");
			return LCD_FAIL;
		}
		if (func) {
			ret = func(data);
			if (ret)
				LCD_ERR("func execute err:%d\n", ret);
		}
		/* parse new item start */
		parse_status = PARSE_HEAD;
		count = 0;
		cnt = 0;
		memset(data, 0, LCD_CONFIG_TABLE_MAX_NUM);
		memset(item_name, 0, LCD_ITEM_NAME_MAX);
		memset(tmp_name, 0, LCD_ITEM_NAME_MAX);
	}
	return LCD_OK;
}

static int parse_ch(unsigned char *ch, unsigned char *data,
	unsigned char *item_name, unsigned char *tmp_name)
{
	int ret;

	switch (*ch) {
	case '<':
		if (parse_status == PARSE_HEAD)
			parse_status = PARSE_HEAD;
		return LCD_OK;
	case '>':
		ret = right_angle_bra_pro(item_name, tmp_name, data);
		if (ret < 0) {
			LCD_ERR("right_angle_bra_pro error\n");
			return LCD_FAIL;
		}
		return LCD_OK;
	case '/':
		if (parse_status == RECEIVE_DATA)
			parse_status = PARSE_FINAL;
		return LCD_OK;
	default:
		if (parse_status == PARSE_HEAD && is_valid_char(*ch)) {
			if (cnt >= LCD_ITEM_NAME_MAX) {
				LCD_ERR("item is too long\n");
				return LCD_FAIL;
			}
			item_name[cnt++] = *ch;
			return LCD_OK;
		}
		if (parse_status == PARSE_FINAL && is_valid_char(*ch)) {
			if (cnt >= LCD_ITEM_NAME_MAX) {
				LCD_ERR("item is too long\n");
				return LCD_FAIL;
			}
			tmp_name[cnt++] = *ch;
			return LCD_OK;
		}
		if (parse_status == RECEIVE_DATA) {
			if (count >= LCD_CONFIG_TABLE_MAX_NUM) {
				LCD_ERR("data is too long\n");
				return LCD_FAIL;
			}
			data[count++] = *ch;
			return LCD_OK;
		}
	}
	return LCD_OK;
}

static int parse_fd(struct file *fd, unsigned char *data,
	unsigned char *item_name, unsigned char *tmp_name)
{
	unsigned char ch = '\0';
	int ret;
	loff_t cur_pos = 0;

	if (!fd || !data || !item_name || !tmp_name) {
		LCD_ERR("null pointer\n");
		return LCD_FAIL;
	}
	while (1) {
		if ((unsigned int)kernel_read(fd, &ch, 1, &cur_pos) != 1) {
			LCD_INFO("it's end of file\n");
			break;
		}
		ret = parse_ch(&ch, data, item_name, tmp_name);
		if (ret < 0) {
			LCD_ERR("parse_ch error!\n");
			return LCD_FAIL;
		}
		continue;
	}
	return LCD_OK;
}

int dbg_parse_config(void)
{
	unsigned char *item_name = NULL;
	unsigned char *tmp_name = NULL;
	unsigned char *data = NULL;
	struct file *fd = NULL;
	mm_segment_t fs;
	int ret;

	fs = get_fs(); /* save previous value */
	set_fs(KERNEL_DS); /* use kernel limit */
	fd = filp_open((const char __force *) LCD_PARAM_FILE_PATH, O_RDONLY, FILE_LIMIT);
	if (fd < 0) {
		LCD_ERR("%s file doesn't exsit\n", LCD_PARAM_FILE_PATH);
		set_fs(fs);
		return FALSE;
	}
	LCD_INFO("Config file %s opened\n", LCD_PARAM_FILE_PATH);
	data = kzalloc(LCD_CONFIG_TABLE_MAX_NUM, 0);
	if (!data) {
		LCD_ERR("data kzalloc fail\n");
		return LCD_FAIL;
	}
	item_name = kzalloc(LCD_ITEM_NAME_MAX, 0);
	if (!item_name) {
		kfree(data);
		LCD_ERR("item_name kzalloc fail\n");
		return LCD_FAIL;
	}
	tmp_name = kzalloc(LCD_ITEM_NAME_MAX, 0);
	if (!tmp_name) {
		kfree(data);
		kfree(item_name);
		LCD_ERR("tmp_name kzalloc fail\n");
		return LCD_FAIL;
	}
	ret = parse_fd(fd, data, item_name, tmp_name);
	if (ret < 0) {
		LCD_INFO("parse fail\n");
		filp_close(fd, NULL);
		set_fs(fs);
		kfree(data);
		kfree(item_name);
		kfree(tmp_name);
		return LCD_FAIL;
	}
	LCD_INFO("parse success\n");
	filp_close(fd, NULL);
	set_fs(fs);
	kfree(data);
	kfree(item_name);
	kfree(tmp_name);
	return LCD_OK;
}

static int dbg_dsi_reg_write(const char *buf)
{
	int i;
	int val;
	int cnt = 0;
	int dsi = 0;
	u32 lp_mode = 0;
	u8 cmd = 0;
	char *cur = NULL;
	char payload[MAX_PAYLOAD] = {0};
	char tmp_buf[MAX_PAYLOAD] = {0};
	struct panel_info *pinfo = NULL;

	if (!buf) {
		LCD_ERR("buf is null\n");
		return -1;
	}
	cur = strstr(buf, "dsi:");
	if (!cur) {
		LCD_INFO("default dsi\n");
		dsi = 0;
	} else {
		cnt = sscanf(cur, "dsi:%d", &val);
		if (cnt != 1) {
			LCD_ERR("parse dsi error\n");
			return -1;
		}
		dsi = val;
	}

	cur = strstr(buf, "lp_mode:");
	if (!cur) {
		LCD_INFO("default lp_mode\n");
		lp_mode = 1;
	} else {
		cnt = sscanf(cur, "lp_mode:%d", &val);
		if (cnt != 1) {
			LCD_ERR("parse lp_mode error\n");
			return -1;
		}
		lp_mode = val;
	}

	cur = strstr(buf, "cmd:");
	if (!cur) {
		LCD_ERR("parse cmd error\n");
		return -1;
	}
	cnt = sscanf(cur, "cmd:0x%x", &val);
	if (cnt != 1) {
		LCD_ERR("parse cmd error\n");
		return -1;
	}
	cmd = val;

	cur = strstr(buf, "payload:");
	if (!cur) {
		LCD_INFO("don't have payload, only cmd\n");
		cnt = 0;
	} else {
		cur += strlen("payload:");
		strncpy(tmp_buf, cur, MAX_PAYLOAD - 1);
		cnt = parse_u32_digit(tmp_buf, payload, MAX_PAYLOAD);
	}
	LCD_INFO("dsi = %d, lp_mode = %d, cmd = 0x%x\n", dsi, lp_mode, cmd);
	LCD_INFO("cnt = %d\n", cnt);
	for (i = 0; i < cnt; i++)
		LCD_INFO("payload[%d] = 0x%x\n", i, payload[i]);
	pinfo = get_panel_info(dsi);
	if (!pinfo) {
		LCD_ERR("get panel info failed\n");
		return -1;
	}
	return dsi_panel_reg_write(pinfo->panel, cmd, payload, cnt, lp_mode);
}

static int dbg_dsi_reg_read(const char *buf)
{
	int ret, i;
	int val;
	int cnt = 0;
	char *cur = NULL;
	struct panel_info *pinfo = NULL;

	if (!buf) {
		LCD_ERR("buf is null\n");
		return -1;
	}
	memset(&read_reg, 0, sizeof(struct dsi_read_desc));
	cur = strstr(buf, "dsi:");
	if (!cur) {
		LCD_INFO("default dsi\n");
		read_reg.dsi = 0;
	} else {
		cnt = sscanf(cur, "dsi:%d", &val);
		if (cnt != 1) {
			LCD_ERR("parse dsi error\n");
			return -1;
		}
		read_reg.dsi = val;
	}

	cur = strstr(buf, "cmd:");
	if (!cur) {
		LCD_ERR("parse cmd error\n");
		return -1;
	}
	cnt = sscanf(cur, "cmd:0x%x", &val);
	if (cnt != 1) {
		LCD_ERR("parse cmd error\n");
		return -1;
	}
	read_reg.cmd = val;

	cur = strstr(buf, "read_count:");
	if (!cur) {
		LCD_INFO("default read_count\n");
		read_reg.read_count = 1;
	} else {
		cnt = sscanf(cur, "read_count:%d", &val);
		if (cnt != 1) {
			LCD_ERR("parse read_count error\n");
			return -1;
		}
		read_reg.read_count = val;
	}

	LCD_INFO("dsi = %d, cmd = 0x%x, read_count = %d\n", read_reg.dsi,
		read_reg.cmd, read_reg.read_count);

	pinfo = get_panel_info(read_reg.dsi);
	if (!pinfo) {
		LCD_ERR("get panel info failed\n");
		return -1;
	}
	ret = dsi_panel_reg_read(pinfo->panel, read_reg.cmd, read_reg.read_value,
		read_reg.read_count);
	if (ret) {
		LCD_ERR("reg read error\n");
		return ret;
	}
	for (i = 0; i < read_reg.read_count; i++) {
		LCD_INFO("read_value[%d] = 0x%x\n", i, read_reg.read_value[i]);
	}
	return ret;
}

/* open function */
static int dbg_open(struct inode *inode, struct file *file)
{
	/* non-seekable */
	file->f_mode &= ~(FMODE_LSEEK | FMODE_PREAD | FMODE_PWRITE);
	return 0;
}

/* release function */
static int dbg_release(struct inode *inode, struct file *file)
{
	return 0;
}

/* read function */
static ssize_t dbg_read(struct file *file,  char __user *buff,
	size_t count, loff_t *ppos)
{
	int i;
	int len;
	int ret_len;
	char *cur = NULL;
	int buf_len = sizeof(read_debug_buf);

	cur = read_debug_buf;
	if (*ppos)
		return 0;
	/* show usage */
	len = snprintf(cur, buf_len, "Usage:\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "eg. echo set_debug_level:4 > /sys/kernel/debug/lcd-dbg/lcd_kit_dbg to open set debug level\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "eg. echo set_param_config:1 > /sys/kernel/debug/lcd-dbg/lcd_kit_dbg to set parameter\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "eg. echo write_reg:dsi:0 lp_mode:1 cmd:0x28 > /sys/kernel/debug/lcd-dbg/lcd_kit_dbg to write reg\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "eg. echo read_reg:dsi:0 cmd:0x0a read_count:1 > /sys/kernel/debug/lcd-dbg/lcd_kit_dbg to read reg\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "######################################################################################################\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "Display read info:\n");
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "dsi = %d, cmd = 0x%x, read_count = %d\n", read_reg.dsi, read_reg.cmd, read_reg.read_count);
	buf_len -= len;
	cur += len;

	len = snprintf(cur, buf_len, "read_value:");
	buf_len -= len;
	cur += len;
	for (i = 0; i < read_reg.read_count; i++) {
		len = snprintf(cur, buf_len, " 0x%x", read_reg.read_value[i]);
		buf_len -= len;
		cur += len;
	}
	len = snprintf(cur, buf_len, "\n");
	buf_len -= len;
	cur += len;

	ret_len = sizeof(read_debug_buf) - buf_len;

	// error happened!
	if (ret_len < 0)
		return 0;

	/* copy to user */
	if (copy_to_user(buff, read_debug_buf, ret_len))
		return -EFAULT;

	*ppos += ret_len; // increase offset
	return ret_len;
}

/* write function */
static ssize_t dbg_write(struct file *file, const char __user *buff,
	size_t count, loff_t *ppos)
{
#define BUF_LEN 256
	char *cur = NULL;
	int ret = 0;
	int cmd_type = -1;
	int cnt = 0;
	int i;
	int val;
	char lcd_debug_buf[BUF_LEN];

	cur = lcd_debug_buf;
	if (count > (BUF_LEN - 1))
		return count;
	if (copy_from_user(lcd_debug_buf, buff, count))
		return -EFAULT;
	lcd_debug_buf[count] = 0;
	/* convert to lower case */
	if (str_to_lower(cur) != 0)
		goto err_handle;
	LCD_INFO("cur=%s\n", cur);
	/* get cmd type */
	for (i = 0; i < ARRAY_SIZE(cmd_list); i++) {
		if (!str_start_with(cur, cmd_list[i].pstr)) {
			cmd_type = cmd_list[i].type;
			cur += strlen(cmd_list[i].pstr);
			break;
		}
	}
	if (i >= ARRAY_SIZE(cmd_list)) {
		LCD_ERR("cmd type not find!\n");  // not support
		goto err_handle;
	}
	switch (cmd_type) {
	case DEBUG_LEVEL_SET:
		cnt = sscanf(cur, ":%d", &val);
		if (cnt != 1) {
			LCD_ERR("get param fail!\n");
			goto err_handle;
		}
		dbg_set_dbg_level(val);
		break;
	case DEBUG_PARAM_CONFIG:
		cnt = sscanf(cur, ":%d", &val);
		if (cnt != 1) {
			dbg_enable = 0;
			LCD_INFO("dbg disable!\n");
			goto err_handle;
		}
		LCD_INFO("dbg enable!\n");
		dbg_enable = 1;
		dbg_free_buf();
		if (val) {
			ret = dbg_parse_config();
			if (!ret)
				LCD_INFO("parse parameter succ!\n");
		}
		break;
	case DEBUG_WRITE_REG:
		ret = dbg_dsi_reg_write(cur);
		break;
	case DEBUG_READ_REG:
		ret = dbg_dsi_reg_read(cur);
		break;
	default:
		LCD_ERR("cmd type not support!\n"); // not support
		ret = LCD_FAIL;
		break;
	}
	/* finish */
	if (ret) {
		LCD_ERR("fail\n");
		goto err_handle;
	} else {
		return count;
	}

err_handle:
	return -EFAULT;
}

static int dbg_set_on_cmd(struct dsi_panel *panel, enum dsi_cmd_set_type type,
	struct dsi_panel_cmds *pcmds)
{
	int i = 0, j = 0;
	struct dsi_cmd_desc *cmds;
	u32 count;
	struct dsi_display_mode *mode;

	if (!panel || !panel->cur_mode)
		return -EINVAL;

	count = pcmds->cmd_cnt;

	mode = panel->cur_mode;
	mode->priv_info->cmd_sets[type].count = count;
	cmds = mode->priv_info->cmd_sets[type].cmds;
	for (i = 0; i < count; i++) {
		cmds->last_command = pcmds->cmds[i].last;
		cmds->post_wait_ms = pcmds->cmds[i].wait;
		cmds->msg.channel = pcmds->cmds[i].vc;
		cmds->msg.type = pcmds->cmds[i].dtype;
		cmds->msg.flags |= pcmds->cmds[i].ack;
		cmds->msg.tx_len = ((pcmds->cmds[i].dlen0 << 8) | pcmds->cmds[i].dlen1);
		cmds->msg.tx_buf = pcmds->cmds[i].payload;
		LCD_DEBUG("cmds->msg.type = 0x%x\n", cmds->msg.type);
		LCD_DEBUG("cmds->last_command = 0x%x\n", cmds->last_command);
		LCD_DEBUG("cmds->msg.channel = 0x%x\n", cmds->msg.channel);
		LCD_DEBUG("cmds->msg.flags = 0x%x\n", cmds->msg.flags);
		LCD_DEBUG("cmds->post_wait_ms = 0x%x\n", cmds->post_wait_ms);
		LCD_DEBUG("cmds->msg.tx_len = 0x%x\n", cmds->msg.tx_len);
		LCD_DEBUG("payload:\n");
		for (j = 0; j < cmds->msg.tx_len; j++)
			LCD_DEBUG("0x%x\n", pcmds->cmds[i].payload[j]);
		cmds++;
	}

	return 0;
}

int get_dbg_level(void)
{
	return lcd_debug_level;
}

int dbg_set_cmd(struct dsi_panel *panel, enum dsi_cmd_set_type type)
{
	int ret = 0;

	if (!dbg_enable)
		return ret;
	switch (type) {
	case DSI_CMD_SET_ON:
		if (dbg_type & DBG_TYPE_CMD_ON)
			ret = dbg_set_on_cmd(panel, type, &panel_on_cmds);
		break;
	default:
		break;
	}
	return ret;
}

static const struct file_operations lcd_kit_debug_fops = {
	.open = dbg_open,
	.release = dbg_release,
	.read = dbg_read,
	.write = dbg_write,
};

/* init lcd debugfs interface */
int debugfs_init(void)
{
	static char already_init;  // internal flag
	struct dentry *dent = NULL;
	struct dentry *file = NULL;

	/* judge if already init */
	if (already_init) {
		LCD_INFO("(%d): already init\n", __LINE__);
		return LCD_OK;
	}
	/* create dir */
	dent = debugfs_create_dir("lcd-dbg", NULL);
	if (IS_ERR_OR_NULL(dent)) {
		LCD_ERR("(%d):create_dir fail, error %ld\n", __LINE__,
			PTR_ERR(dent));
		dent = NULL;
		goto err_create_dir;
	}
	/* create reg_dbg_mipi node */
	file = debugfs_create_file("lcd_kit_dbg", 0644, dent, 0,
		&lcd_kit_debug_fops);
	if (IS_ERR_OR_NULL(file)) {
		LCD_ERR("(%d):create_file: lcd_kit_dbg fail\n", __LINE__);
		goto err_create_mipi;
	}
	already_init = 1;  // set flag
	return LCD_OK;
err_create_mipi:
		debugfs_remove_recursive(dent);
err_create_dir:
	return LCD_FAIL;
}
