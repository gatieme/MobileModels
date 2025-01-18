#include "bridge_pinctrl.h"
#include <linux/pinctrl/consumer.h>

static int bridge_get_dtype_pinctrl(struct device *dev,
	struct pinctrl_cmd_desc *cm, int i)
{
	if (!cm->pctrl_data) {
		HISI_FB_ERR("pctrl_data is NULL\n", i);
		return -EINVAL;
	}

	cm->pctrl_data->p = devm_pinctrl_get(dev);
	if (IS_ERR(cm->pctrl_data->p)) {
		HISI_FB_ERR("failed to get p, index=%d!\n", i);
		return -1;
	}
	return 0;
}

static int bridge_get_dtype_pinctrl_state(struct pinctrl_cmd_desc *cm, int i)
{
	if (!cm->pctrl_data) {
		HISI_FB_ERR("pctrl_data is NULL\n");
		return -1;
	}

	if (cm->mode == DTYPE_PINCTRL_STATE_DEFAULT) {
		cm->pctrl_data->pinctrl_def = pinctrl_lookup_state(cm->pctrl_data->p,
			PINCTRL_STATE_DEFAULT);
		if (IS_ERR(cm->pctrl_data->pinctrl_def)) {
			HISI_FB_ERR("failed to get pinctrl_def, index=%d!\n", i);
			return -1;
		}
	} else if (cm->mode == DTYPE_PINCTRL_STATE_IDLE) {
		cm->pctrl_data->pinctrl_idle = pinctrl_lookup_state(cm->pctrl_data->p,
			PINCTRL_STATE_IDLE);
		if (IS_ERR(cm->pctrl_data->pinctrl_idle)) {
			HISI_FB_ERR("failed to get pinctrl_idle, index=%d!\n", i);
			return -1;
		}
	} else {
		HISI_FB_ERR("unknown pinctrl type to get!\n");
		return -1;
	}
	return 0;
}


static int bridge_set_dtype_pinctrl(struct pinctrl_cmd_desc *cm)
{
	int ret;

	if (!cm->pctrl_data) {
		HISI_FB_ERR("pctrl_data is NULL\n");
		return -1;
	}

	if (cm->mode == DTYPE_PINCTRL_STATE_DEFAULT) {
		if (cm->pctrl_data->p && cm->pctrl_data->pinctrl_def) {
			ret = pinctrl_select_state(cm->pctrl_data->p,
				cm->pctrl_data->pinctrl_def);
			if (ret) {
				HISI_FB_ERR("could not set this pin to default state!\n");
				ret = -1;
				return ret;
			}
		}
	} else if (cm->mode == DTYPE_PINCTRL_STATE_IDLE) {
		if (cm->pctrl_data->p && cm->pctrl_data->pinctrl_idle) {
			ret = pinctrl_select_state(cm->pctrl_data->p,
				cm->pctrl_data->pinctrl_idle);
			if (ret) {
				HISI_FB_ERR("could not set this pin to idle state!\n");
				ret = -1;
				return ret;
			}
		}
	} else {
		ret = -1;
		HISI_FB_ERR("unknown pinctrl type to set!\n");
		return ret;
	}
	return 0;
}


int bridge_pinctrl_cmds_tx(struct device *dev,
	struct pinctrl_cmd_desc *cmds, int cnt)
{
	int ret = 0;

	int i = 0;
	struct pinctrl_cmd_desc *cm = NULL;

	if (!dev) {
		HISI_FB_ERR("pdev is NULL");
		return -EINVAL;
	}

	cm = cmds;

	for (i = 0; i < cnt; i++) {
		if (cm == NULL) {
			HISI_FB_ERR("cm is null! index=%d\n", i);
			continue;
		}

		if (cm->dtype == DTYPE_PINCTRL_GET) {
			ret = bridge_get_dtype_pinctrl(dev, cm, i);
			if (ret)
				goto err;
		} else if (cm->dtype == DTYPE_PINCTRL_STATE_GET) {
			ret = bridge_get_dtype_pinctrl_state(cm, i);
			if (ret)
				goto err;
		} else if (cm->dtype == DTYPE_PINCTRL_SET) {
			ret = bridge_set_dtype_pinctrl(cm);
			if (ret)
				goto err;
		} else if (cm->dtype == DTYPE_PINCTRL_PUT) {
			if (cm->pctrl_data->p)
				pinctrl_put(cm->pctrl_data->p);
		} else {
			HISI_FB_ERR("not supported command type!\n");
			ret = -1;
			goto err;
		}

		cm++;
	}

	return 0;

err:
	return ret;
}

