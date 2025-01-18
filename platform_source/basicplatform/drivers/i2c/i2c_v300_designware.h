/*
 * I2c V300 DesignWare adapter.
 *
 * Based on the TI DAVINCI I2C adapter driver.
 *
 * Copyright (C) 2006 Texas Instruments.
 * Copyright (C) 2007 MontaVista Software Inc.
 * Copyright (C) 2009 Provigent Ltd.
 */

#include <linux/dmaengine.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <linux/clk.h>

#define ACCESS_32BIT   0x00000004

struct dw_i2c_dev;

struct hs_i2c_priv_data {
	u32 delay_off;
	u32 delay_bit;
	u32 reset_enable_off;
	u32 reset_disable_off;
	u32 reset_status_off;
	u32 reset_bit;
};

struct dw_i2c_dma_data {
	struct dma_chan	*chan;
	struct scatterlist	sg;
	u8     *buf;
};

struct dw_i2c_controller {
	/* DMA stuff */
	u32          dmacr;
	bool         using_tx_dma;
	bool         using_rx_dma;
	struct dw_i2c_dma_data dmarx;
	struct dw_i2c_dma_data dmatx;
	int          timeout_count;
	struct completion      dma_complete;
	bool         using_dma;
	/* user defined */
	struct pinctrl *pinctrl;
	int	         pinctrl_flag;
	resource_size_t       mapbase;
	u32	         delay_off;
	void         __iomem *reset_reg_base;
	void         (*recover_bus)(struct i2c_adapter *);
	struct hs_i2c_priv_data priv;
	u32         rst_for_status_err;
};

extern int i2c_dw_init_master(struct dw_i2c_dev *dev);
extern irqreturn_t i2c_dw_isr(int this_irq, void *dev_id);
void i2c_dw_xfer_init(struct dw_i2c_dev *dev);
int i2c_dw_set_timings_master(struct dw_i2c_dev *dev);
void i2c_dw_dma_fifo_cfg(struct dw_i2c_dev *dev);
void i2c_dw_read(struct dw_i2c_dev *dev);
