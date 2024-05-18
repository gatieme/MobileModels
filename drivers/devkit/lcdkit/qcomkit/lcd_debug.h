/*
 * lcd_kit_dbg.h
 *
 * lcdkit debug function for lcdkit head file
 *
 * Copyright (c) 2018-2019 Honor Technologies Co., Ltd.
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

#ifndef __LCD_DEBUG_H_
#define __LCD_DEBUG_H_

#include <linux/debugfs.h>

/* define macro */
#define LCD_MAX_PARAM_NUM        25

#define LCD_OPER_READ           1
#define LCD_OPER_WRITE          2
#define LCD_MIPI_PATH_OPEN      1
#define LCD_MIPI_PATH_CLOSE     0
#define LCD_MIPI_DCS_COMMAND    (1<<0)
#define LCD_MIPI_GEN_COMMAND    4

#define LCD_HEX_BASE ((char)16)

/* dcs read/write */
#define DTYPE_DCS_WRITE     0x05 /* short write, 0 parameter */
#define DTYPE_DCS_WRITE1    0x15 /* short write, 1 parameter */
#define DTYPE_DCS_READ      0x06 /* read */
#define DTYPE_DCS_LWRITE    0x39 /* long write */

/* generic read/write */
#define DTYPE_GEN_WRITE     0x03 /* short write, 0 parameter */
#define DTYPE_GEN_WRITE1    0x13 /* short write, 1 parameter */
#define DTYPE_GEN_WRITE2    0x23 /* short write, 2 parameter */
#define DTYPE_GEN_LWRITE    0x29 /* long write */
#define DTYPE_GEN_READ      0x04 /* long read, 0 parameter */
#define DTYPE_GEN_READ1     0x14 /* long read, 1 parameter */
#define DTYPE_GEN_READ2     0x24 /* long read, 2 parameter */

/*
 * Message printing priorities:
 * LEVEL 0 KERN_EMERG (highest priority)
 * LEVEL 1 KERN_ALERT
 * LEVEL 2 KERN_CRIT
 * LEVEL 3 KERN_ERR
 * LEVEL 4 KERN_WARNING
 * LEVEL 5 KERN_NOTICE
 * LEVEL 6 KERN_INFO
 * LEVEL 7 KERN_DEBUG (Lowest priority)
 */

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define FILE_LIMIT 0666

#define LCD_CONFIG_TABLE_MAX_NUM (2 * PAGE_SIZE)
#define LCD_CMD_MAX_NUM          (PAGE_SIZE)
#define LCD_DCS_CMD_MAX_NUM (4 * PAGE_SIZE)

#define LCD_PARAM_FILE_PATH "/data/lcd_param_config.xml"
#define LCD_ITEM_NAME_MAX   100
#define LCD_DBG_BUFF_MAX    2048
/* cmdline buffer max */
#define CMDLINE_MAX 10
#define XML_FILE_MAX 100
#define XML_NAME_MAX 100
#define MAX_PAYLOAD 400
#define MAX_READ_BUF 100

/* cmd type */
#define DBG_TYPE_CMD_ON BIT(0)

enum parse_status {
	PARSE_HEAD,
	RECEIVE_DATA,
	PARSE_FINAL,
	NOT_MATCH,
	INVALID_DATA,
};
enum cmds_type {
	DEBUG_LEVEL_SET = 0,
	DEBUG_INIT_CODE,
	DEBUG_PARAM_CONFIG,
	DEBUG_WRITE_REG,
	DEBUG_READ_REG,
	DEBUG_NUM_MAX,
};


struct dsi_ctrl_hdr {
	char dtype; /* data type */
	char last;  /* last in chain */
	char vc;    /* virtual chan */
	char ack;   /* ask ACK from peripheral */
	char wait;  /* ms */
	char dlen0;
	char dlen1;  /* 8 bits */
};

#define PSTR_LEN 100
struct debug_cmds {
	char type;
	char pstr[PSTR_LEN];
};

typedef int (*DBG_FUNC)(char *PAR);
struct debug_func {
	unsigned char *name;
	DBG_FUNC func;
};

struct debug_buf {
	char *panel_on_buf;
};

struct dbg_dsi_cmd_desc {
        char dtype; /* data type */
        char last; /* last in chain */
        char vc; /* virtual chan */
        char ack; /* ask ACK from peripheral */
        char wait; /* ms */
        char dlen0;
        char dlen1; /* 8 bits */
        char *payload;
};

struct dsi_panel_cmds {
        char *buf;
        int blen;
        struct dbg_dsi_cmd_desc *cmds;
        int cmd_cnt;
        int link_state;
        u32 flags;
};

struct dsi_read_desc {
	int dsi;
	u8 cmd;
	int read_count;
	char read_value[MAX_READ_BUF];
};

int dbg_parse_cmd(struct dsi_panel_cmds *pcmds, char *buf,
	int length);
bool is_valid_char(char ch);
#endif
