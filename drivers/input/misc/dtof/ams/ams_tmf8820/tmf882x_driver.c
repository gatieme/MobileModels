/*
 *****************************************************************************
 * Copyright by ams AG                                                       *
 * All rights are reserved.                                                  *
 *                                                                           *
 * IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING     *
 * THE SOFTWARE.                                                             *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED FOR USE ONLY IN CONJUNCTION WITH AMS PRODUCTS.  *
 * USE OF THE SOFTWARE IN CONJUNCTION WITH NON-AMS-PRODUCTS IS EXPLICITLY    *
 * EXCLUDED.                                                                 *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS         *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT          *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
 *****************************************************************************
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <linux/interrupt.h>
#include <linux/firmware.h>
#include <linux/irq.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/gpio/consumer.h>
#include <linux/kfifo.h>
#include <linux/input.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/poll.h>
#include <linux/eventpoll.h>
#ifdef CONFIG_TMF882X_QCOM_AP
#include <linux/sensors.h>
#endif

#include "tmf882x_driver.h"
#include "tmf882x_interface.h"

#define TMF882X_NAME                "tmf882x"
#define TOF_GPIO_INT_NAME           "irq"
#define TOF_GPIO_ENABLE_NAME        "enable"
#define TOF_PROP_NAME_POLLIO        "tof,tof_poll_period"
#define TMF882X_DEFAULT_INTERVAL_MS 10
#define TMF882X_SN_ADDR             0x1C
#define TMF882X_SN_LEN              4

#define AMS_MUTEX_LOCK(m) { \
    mutex_lock(m); \
}
#define AMS_MUTEX_TRYLOCK(m) ({ \
    mutex_trylock(m); \
})
#define AMS_MUTEX_UNLOCK(m) { \
    mutex_unlock(m); \
}

struct tmf882x_platform_data {
    const char *tof_name;
    struct gpio_desc *gpiod_interrupt;
    struct gpio_desc *gpiod_enable;
    const char *fac_calib_data_fname;
    const char *config_calib_data_fname;
    const char *ram_patch_fname_ROM_1v1[2];
    const char *ram_patch_fname_ROM_1v2[2];
};

struct tof_sensor_chip {

    bool driver_remove;
    bool fwdl_needed;
    char rom_version;
    int poll_period;
    int open_refcnt;
    int driver_debug;

    /* Linux kernel structure(s) */
    DECLARE_KFIFO(fifo_out, u8, 4*PAGE_SIZE);
    struct mutex lock;
    struct miscdevice tof_mdev;
    struct input_dev *tof_idev;
    struct completion ram_patch_in_progress;
    struct firmware *tof_fw;
    struct tmf882x_platform_data *pdata;
    struct i2c_client *client;
    struct task_struct *poll_irq;
    wait_queue_head_t fifo_wait;

#ifdef CONFIG_TMF882X_QCOM_AP
    // Qualcomm linux kernel AP structures
    struct sensors_classdev cdev;
#endif

    /* ToF structure(s) */
    struct tmf882x_tof  tof;
    struct tmf882x_mode_app_config  tof_cfg;
    struct tmf882x_mode_app_spad_config  tof_spad_cfg;
    struct tmf882x_mode_app_calib tof_calib;
    bool tof_spad_uncommitted;
    //struct delayed_work init_delaywork;
};

static struct tmf882x_platform_data tof_pdata = {
    .tof_name = TMF882X_NAME,
    .fac_calib_data_fname = "tmf882x_fac_calib.bin",
    .config_calib_data_fname = "tmf882x_config_calib.bin",
    .ram_patch_fname_ROM_1v1 = {
        "tmf882x_firmware_1v1.bin",
        NULL,
    },
    .ram_patch_fname_ROM_1v2 = {
        "tmf882x_firmware_1v2.bin",
        NULL,
    },
};

#ifdef CONFIG_TMF882X_QCOM_AP
static struct sensors_classdev sensors_cdev = {
    .name = TMF882X_NAME,
    .vendor = "ams",
    .version = 1,
    .handle = SENSORS_PROXIMITY_HANDLE,
    .type = SENSOR_TYPE_PROXIMITY,
    .max_range = "5",
    .resolution = "0.001",
    .sensor_power = "40",
    .min_delay = 0,
    .max_delay = USHRT_MAX,
    .fifo_reserved_event_count = 0,
    .fifo_max_event_count = 0,
    .enabled = 0,
    .delay_msec = TMF882X_DEFAULT_INTERVAL_MS,
    .sensors_enable = NULL,
    .sensors_poll_delay = NULL,
};
#endif

inline struct device * tof_to_dev(struct tof_sensor_chip *chip)
{
    return &chip->client->dev;
}
/*
 *
 * Function Declarations
 *
 */
static void tof_ram_patch_callback(const struct firmware *cfg, void *ctx);
static irqreturn_t tof_irq_handler(int irq, void *dev_id);
static int tof_hard_reset(struct tof_sensor_chip *chip);
static int tof_frwk_i2c_write_mask(struct tof_sensor_chip *chip, char reg,
                                   const char *val, char mask);
static int tof_poweroff_device(struct tof_sensor_chip *chip);
static int tof_poweron_device(struct tof_sensor_chip *chip);
static int tof_open_mode(struct tof_sensor_chip *chip, uint32_t req_mode);

static size_t tof_fifo_next_msg_size(struct tof_sensor_chip *chip)
{
    struct tmf882x_msg_header hdr;
    int ret;
    if (kfifo_is_empty(&chip->fifo_out))
        return 0;
    ret = kfifo_out_peek(&chip->fifo_out, (char *)&hdr, sizeof(hdr));
    if (ret != sizeof(hdr))
        return 0;
    return hdr.msg_len;
}

static void tof_publish_input_events(struct tof_sensor_chip *chip,
                                     struct tmf882x_msg *msg)
{
    int val = 0;
    uint32_t code = 0;
    uint32_t i = 0;
    struct tmf882x_msg_meas_results *res;
    switch(msg->hdr.msg_id) {
        case ID_MEAS_RESULTS:
            /* Input Event encoding for measure results :
             *     code       => channel
             *     val(31:24) => sub capture index
             *     val(23:16) => confidence
             *     val(15:0)  => distance in mm
             */
            res = &msg->meas_result_msg;
            for (i = 0; i < res->num_results; i++) {
                val = 0;
                code = res->results[i].channel;
                val |= (res->results[i].sub_capture & 0xFF) << 24;
                val |= (res->results[i].confidence & 0xFF) << 16;
                val |= res->results[i].distance_mm & 0xFFFF;
                input_report_abs(chip->tof_idev, code, val);
            }
            break;
        default:
            /* Don't publish any input events if not explicitly handled */
            return;
    }
    input_sync(chip->tof_idev);
}

static int tof_firmware_download(struct tof_sensor_chip *chip)
{
    /*** ASSUME MUTEX IS ALREADY HELD ***/
    int error = 0;
    int file_idx = 0;
    const struct firmware *fw = NULL;
    char rom_version = 0;

    if(chip->rom_version == 0) {
        tmf882x_get_rom_version(&chip->tof, &rom_version);
        chip->rom_version = rom_version;
    }
    dev_err(&chip->client->dev, "rom_version is 0x%x\n", chip->rom_version);
    if(chip->rom_version == 0x26) {
        /* Iterate through all Firmware(s) to find one that works
         */
        for (file_idx=0;
             chip->pdata->ram_patch_fname_ROM_1v1[file_idx] != NULL;
             file_idx++) {

            /*** reset completion event that FWDL is starting ***/
            reinit_completion(&chip->ram_patch_in_progress);

            dev_info(&chip->client->dev, "Trying firmware: \'%s\'...\n",
                    chip->pdata->ram_patch_fname_ROM_1v1[file_idx]);

            /***** Check for available firmware to load *****/
            error = request_firmware_direct(&fw,
                                            chip->pdata->ram_patch_fname_ROM_1v1[file_idx],
                                            &chip->client->dev);
            if (error) {
                dev_warn(&chip->client->dev,
                         "Firmware not available \'%s\': %d\n",
                         chip->pdata->ram_patch_fname_ROM_1v1[file_idx], error);
                continue;
            } else {
                tof_ram_patch_callback(fw, chip);
            }

            if (!wait_for_completion_interruptible_timeout(&chip->ram_patch_in_progress,
                                                           msecs_to_jiffies(TOF_FWDL_TIMEOUT_MSEC))) {
                dev_err(&chip->client->dev,
                        "Timeout waiting for Ram Patch \'%s\' Complete",
                        chip->pdata->ram_patch_fname_ROM_1v1[file_idx]);
                error = -EIO;
                continue;
            }

            // assume everything was successful
            error = 0;
        }
    } else if(chip->rom_version == 0x29) {
        /* Iterate through all Firmware(s) to find one that works
         */
        for (file_idx=0;
             chip->pdata->ram_patch_fname_ROM_1v2[file_idx] != NULL;
             file_idx++) {

            /*** reset completion event that FWDL is starting ***/
            reinit_completion(&chip->ram_patch_in_progress);

            dev_info(&chip->client->dev, "Trying firmware: \'%s\'...\n",
                    chip->pdata->ram_patch_fname_ROM_1v2[file_idx]);

            /***** Check for available firmware to load *****/
            error = request_firmware_direct(&fw,
                                            chip->pdata->ram_patch_fname_ROM_1v2[file_idx],
                                            &chip->client->dev);
            if (error) {
                dev_warn(&chip->client->dev,
                         "Firmware not available \'%s\': %d\n",
                         chip->pdata->ram_patch_fname_ROM_1v2[file_idx], error);
                continue;
            } else {
                tof_ram_patch_callback(fw, chip);
            }

            if (!wait_for_completion_interruptible_timeout(&chip->ram_patch_in_progress,
                                                           msecs_to_jiffies(TOF_FWDL_TIMEOUT_MSEC))) {
                dev_err(&chip->client->dev,
                        "Timeout waiting for Ram Patch \'%s\' Complete",
                        chip->pdata->ram_patch_fname_ROM_1v2[file_idx]);
                error = -EIO;
                continue;
            }

            // assume everything was successful
            error = 0;
        }
    }
    return error;
}

static int tof_poweron_device(struct tof_sensor_chip *chip)
{
    int error = 0;
    if (chip->pdata->gpiod_enable &&
        !gpiod_get_value(chip->pdata->gpiod_enable)) {
        error = gpiod_direction_output(chip->pdata->gpiod_enable, 1);
        if (error) {
            dev_err(&chip->client->dev,
                    "Error powering chip: %d\n", error);
            return error;
        }
    }

    return 0;
}

static int tof_open_mode(struct tof_sensor_chip *chip, uint32_t mode)
{
    tmf882x_mode_t req_mode = (tmf882x_mode_t) mode;

    if (tof_poweron_device(chip))
        return -1;

    dev_info(&chip->client->dev, "%s: %#x\n", __func__, req_mode);

    // open core driver
    if (tmf882x_open(&chip->tof)) {
        dev_err(&chip->client->dev, "failed to open TMF882X core driver\n");
        return -1;
    }

    if (req_mode == TMF882X_MODE_BOOTLOADER) {

        // mode switch to the bootloader (no-op if already in bootloader)
        if (tmf882x_mode_switch(&chip->tof, TMF882X_MODE_BOOTLOADER)) {
            dev_info(&chip->client->dev, "%s mode switch failed\n", __func__);
            tmf882x_dump_i2c_regs(tmf882x_mode_hndl(&chip->tof));
            return -1;
        }
        // we lose the FW if switching to the bootloader
        chip->fwdl_needed = true;

    } else if (req_mode == TMF882X_MODE_APP) {

        // Try FWDL - this will perform no action if poweroff has not occurred
        //  result state is that of the FW if successful, or the bootloader if not
        if (chip->fwdl_needed) {
            if (0 == tof_firmware_download(chip))
                // FWDL is no longer necessary unless device loses power
                chip->fwdl_needed = false;
        }

        // NO-OP If already in APP, else mode switch to the APP by loading from
        //  ROM/FLASH/etc
        if (tmf882x_mode_switch(&chip->tof, req_mode)) {
            tmf882x_dump_i2c_regs(tmf882x_mode_hndl(&chip->tof));
            return -1;
        }

    }

    // if we have gotten here then one of FWDL/ROM/FLASH load was successful
    return !(tmf882x_get_mode(&chip->tof) == req_mode);
}

static int tof_set_default_config(struct tof_sensor_chip *chip)
{
    int error;

    // use current debug setting
    tmf882x_set_debug(&chip->tof, !!(chip->driver_debug));

    error = tmf882x_ioctl(&chip->tof, IOCAPP_GET_CFG, NULL, &chip->tof_cfg);
    if (error) {
        dev_err(&chip->client->dev, "Error, app get config failed.\n");
        return error;
    }

    /////////////////////////////////////
    //
    //  Set default config (if any)
    //
    ////////////////////////////////////

    memset(&chip->tof_spad_cfg, 0, sizeof(chip->tof_spad_cfg));
    error = tmf882x_ioctl(&chip->tof, IOCAPP_GET_SPADCFG, NULL, &chip->tof_spad_cfg);
    if (error) {
        dev_err(&chip->client->dev, "Error, app get spad config failed.\n");
        return error;
    }

    return 0;
}

static ssize_t mode_show(struct device * dev,
                         struct device_attribute * attr,
                         char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    dev_info(dev, "%s\n", __func__);
    return scnprintf(buf, PAGE_SIZE, "0x%hhx\n",
                     tmf882x_mode(tmf882x_mode_hndl(&chip->tof)));
}

static ssize_t mode_store(struct device * dev,
                          struct device_attribute * attr,
                          const char * buf,
                          size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int req_mode;
    int error;
    dev_info(dev, "%s\n", __func__);
    sscanf(buf, "%i", &req_mode);
    AMS_MUTEX_LOCK(&chip->lock);
    error = tof_open_mode(chip, req_mode);
    if (error) {
        dev_err(&chip->client->dev, "Error opening requested mode: %#hhx", req_mode);
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t chip_enable_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int state;
    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);
    if (!chip->pdata->gpiod_enable) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    state = gpiod_get_value(chip->pdata->gpiod_enable);
    dev_info(dev, "%s: %u\n", __func__, state);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return scnprintf(buf, PAGE_SIZE, "%d\n", !!state);
}

static ssize_t chip_enable_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buf,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int req_state;
    int error;
    dev_info(dev, "%s\n", __func__);
    error = sscanf(buf, "%i", &req_state);
    if (error != 1)
        return -1;
    AMS_MUTEX_LOCK(&chip->lock);
    if (!chip->pdata->gpiod_enable) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    if (req_state == 0) {
        tof_poweroff_device(chip);
    } else {
        error = tof_open_mode(chip, TMF882X_MODE_APP);
        if (error) {
            dev_err(&chip->client->dev, "Error powering-on device");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t driver_debug_show(struct device * dev,
                                 struct device_attribute * attr,
                                 char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    dev_info(dev, "%s\n", __func__);
    return scnprintf(buf, PAGE_SIZE, "%d\n", chip->driver_debug);
}

static ssize_t driver_debug_store(struct device * dev,
                                  struct device_attribute * attr,
                                  const char * buf,
                                  size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int debug;
    dev_info(dev, "%s\n", __func__);
    sscanf(buf, "%i", &debug);
    if (debug == 0) {
        chip->driver_debug = 0;
    } else {
        chip->driver_debug = debug;
    }
    tmf882x_set_debug(&chip->tof, !!(chip->driver_debug));
    return count;
}

static ssize_t firmware_version_show(struct device * dev,
                                     struct device_attribute * attr,
                                     char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int len = 0;
    char str[17] = {0};
    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);
    len = tmf882x_get_firmware_ver(&chip->tof, str, sizeof(str));
    if (len < 0) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    len = scnprintf(buf, PAGE_SIZE, "%s\n", str);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return len;
}

static ssize_t device_uid_show(struct device * dev,
                               struct device_attribute * attr,
                               char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int len = 0;
    struct tmf882x_mode_app_dev_UID uid;
    int error;
    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);

    //UID is only available through the application so we must open it
    error = tof_open_mode(chip, TMF882X_MODE_APP);
    if (error) {
        dev_err(&chip->client->dev, "Error powering-on device");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    memset(&uid, 0, sizeof(uid));
    error = tmf882x_ioctl(&chip->tof, IOCAPP_DEV_UID, NULL, &uid);
    if (error) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    if (!chip->open_refcnt) {
        tmf882x_close(&chip->tof);
    }
    len = scnprintf(buf, PAGE_SIZE, "%s\n", uid.uid);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return len;
}

static ssize_t device_revision_show(struct device * dev,
                                    struct device_attribute * attr,
                                    char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int len = 0;
    char revision[17] = {0};
    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);
    if (tof_poweron_device(chip)) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    len = tmf882x_get_device_revision(&chip->tof, revision, sizeof(revision));
    if (len < 0) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    len = scnprintf(buf, PAGE_SIZE, "%s\n", revision);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return len;
}

static ssize_t registers_show(struct device * dev,
                              struct device_attribute * attr,
                              char * buf)
{
    int per_line = 4;
    int len = 0;
    int idx, per_line_idx;
    int bufsize = PAGE_SIZE;
    int error;
    char regs[MAX_REGS] = {0};
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);

    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);
    error = tof_frwk_i2c_read(chip, 0x00, regs, MAX_REGS);
    if (error < 0) {
        dev_err(&chip->client->dev, "Read all registers failed: %d\n", error);
        return error;
    }
    if (error) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return error;
    }

    for (idx = 0; idx < MAX_REGS; idx += per_line) {
        len += scnprintf(buf + len, bufsize - len, "0x%02x:", idx);
        for (per_line_idx = 0; per_line_idx < per_line; per_line_idx++) {
            len += scnprintf(buf + len, bufsize - len, " ");
            len += scnprintf(buf + len, bufsize - len, "%02x", regs[idx+per_line_idx]);
        }
        len += scnprintf(buf + len, bufsize - len, "\n");
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return len;
}

static ssize_t register_write_store(struct device * dev,
                                    struct device_attribute * attr,
                                    const char * buf,
                                    size_t count)
{
    char preg;
    char pval;
    char pmask = -1;
    int numparams;
    int rc;
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    dev_info(dev, "%s\n", __func__);

    numparams = sscanf(buf, "%hhi:%hhi:%hhi", &preg, &pval, &pmask);
    if ((numparams < 2) || (numparams > 3))
        return -EINVAL;
    if ((numparams >= 1) && (preg < 0))
        return -EINVAL;
    if ((numparams >= 2) && (preg < 0 || preg > 0xff))
        return -EINVAL;
    if ((numparams >= 3) && (pmask < 0 || pmask > 0xff))
        return -EINVAL;

    if (pmask == -1) {
        rc = tof_frwk_i2c_write(chip, preg, &pval, 1);
    } else {
        rc = tof_frwk_i2c_write_mask(chip, preg, &pval, pmask);
    }

    return rc ? rc : count;
}

static ssize_t request_ram_patch_store(struct device * dev,
                                       struct device_attribute * attr,
                                       const char * buf,
                                       size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int error = 0;
    dev_info(dev, "%s\n", __func__);
    AMS_MUTEX_LOCK(&chip->lock);
    /***** Try to re-open the app (perform fwdl if available) *****/
    error = tof_hard_reset(chip);
    if (error) {
        dev_err(dev, "Error re-patching device\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t capture_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    bool meas = false;

    dev_info(dev, "%s\n", __func__);

    (void) tmf882x_ioctl(&chip->tof, IOCAPP_IS_MEAS, NULL, &meas);
    return scnprintf(buf, PAGE_SIZE, "%u\n", meas);
}

static ssize_t capture_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int capture;

    sscanf(buf, "%i", &capture);
    AMS_MUTEX_LOCK(&chip->lock);
    if (capture) {
        dev_info(dev, "%s: start capture\n", __func__);
        if (tof_open_mode(chip, TMF882X_MODE_APP)) {
            dev_err(dev, "Chip power-on failed\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        // start measurements
        if (tmf882x_start(&chip->tof)) {
            dev_info(dev, "Error starting measurements\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
    } else {
        dev_info(dev, "%s: stop capture\n", __func__);
        // stop measurements
        if (tmf882x_stop(&chip->tof)) {
            dev_info(dev, "Error stopping measurements\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        // stopping measurements, lets flush the ring buffer
        kfifo_reset(&chip->fifo_out);
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t report_period_ms_show(struct device * dev,
                                     struct device_attribute * attr,
                                     char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n", chip->tof_cfg.report_period_ms);
}

static ssize_t report_period_ms_store(struct device * dev,
                                      struct device_attribute * attr,
                                      const char * buf,
                                      size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t period_ms;
    int rc;

    sscanf(buf, "%i", &period_ms);
    dev_info(dev, "%s: %u ms\n", __func__, period_ms);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.report_period_ms = period_ms;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring reporting period\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t iterations_show(struct device * dev,
                               struct device_attribute * attr,
                               char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n",
                     chip->tof_cfg.kilo_iterations << 10);
}

static ssize_t iterations_store(struct device * dev,
                                struct device_attribute * attr,
                                const char * buf,
                                size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t iterations;
    int rc;

    sscanf(buf, "%i", &iterations);
    dev_info(dev, "%s: %u\n", __func__, iterations);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.kilo_iterations = iterations >> 10;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring iterations\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t alg_setting_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#x\n",
                     chip->tof_cfg.alg_setting);
}

static ssize_t alg_setting_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buf,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t alg_mask;
    int rc;

    sscanf(buf, "%i", &alg_mask);
    dev_info(dev, "%s: %#x\n", __func__, alg_mask);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.alg_setting = alg_mask;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring alg setting\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t power_cfg_show(struct device * dev,
                              struct device_attribute * attr,
                              char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#x\n",
                     chip->tof_cfg.power_cfg);
}

static ssize_t power_cfg_store(struct device * dev,
                               struct device_attribute * attr,
                               const char * buf,
                               size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t power_cfg;
    int rc;

    sscanf(buf, "%i", &power_cfg);
    dev_info(dev, "%s: %#x\n", __func__, power_cfg);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.power_cfg = power_cfg;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring power config\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t gpio_0_show(struct device * dev,
                           struct device_attribute * attr,
                           char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#hhx\n",
                     chip->tof_cfg.gpio_0);
}

static ssize_t gpio_0_store(struct device * dev,
                            struct device_attribute * attr,
                            const char * buf,
                            size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t gpio_mask;
    int rc;

    sscanf(buf, "%hhi", &gpio_mask);
    dev_info(dev, "%s: %#x\n", __func__, gpio_mask);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.gpio_0 = gpio_mask;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring gpio_0\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t gpio_1_show(struct device * dev,
                           struct device_attribute * attr,
                           char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#hhx\n",
                     chip->tof_cfg.gpio_1);
}

static ssize_t gpio_1_store(struct device * dev,
                            struct device_attribute * attr,
                            const char * buf,
                            size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t gpio_mask;
    int rc;

    sscanf(buf, "%hhi", &gpio_mask);
    dev_info(dev, "%s: %#x\n", __func__, gpio_mask);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.gpio_1 = gpio_mask;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring gpio_1\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t histogram_dump_show(struct device * dev,
                                   struct device_attribute * attr,
                                   char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#hhx\n",
                     chip->tof_cfg.histogram_dump);
}

static ssize_t histogram_dump_store(struct device * dev,
                                    struct device_attribute * attr,
                                    const char * buf,
                                    size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t hist_mask;
    int rc;

    sscanf(buf, "%hhi", &hist_mask);
    dev_info(dev, "%s: %#x\n", __func__, hist_mask);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.histogram_dump = hist_mask;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring histogram dump mask\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t spad_map_id_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#hhx\n",
                     chip->tof_cfg.spad_map_id);
}

static ssize_t spad_map_id_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buf,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t map_id;
    int rc;

    sscanf(buf, "%hhi", &map_id);
    dev_info(dev, "%s: %#x\n", __func__, map_id);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.spad_map_id = map_id;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring spad_map_id\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    // read out spad config since spad map id has changed
    memset(&chip->tof_spad_cfg, 0, sizeof(chip->tof_spad_cfg));
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_GET_SPADCFG, NULL, &chip->tof_spad_cfg);
    if (rc) {
        dev_err(&chip->client->dev, "Error, reading spad config failed.\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    // read out fresh spad configuration from device, overwrite local copy
    chip->tof_spad_uncommitted = false;
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t zone_mask_show(struct device * dev,
                              struct device_attribute * attr,
                              char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%#x\n",
                     chip->tof_cfg.zone_mask);
}

static ssize_t zone_mask_store(struct device * dev,
                               struct device_attribute * attr,
                               const char * buf,
                               size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t mask;
    int rc;

    sscanf(buf, "%i", &mask);
    dev_info(dev, "%s: %#x\n", __func__, mask);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.zone_mask = mask;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring zone_mask\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t conf_threshold_show(struct device * dev,
                                  struct device_attribute * attr,
                                  char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%hhu\n",
                     chip->tof_cfg.confidence_threshold);
}

static ssize_t conf_threshold_store(struct device * dev,
                                   struct device_attribute * attr,
                                   const char * buf,
                                   size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t th;
    int rc;

    sscanf(buf, "%hhi", &th);
    dev_info(dev, "%s: %hhu\n", __func__, th);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.confidence_threshold = th;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring conf threshold\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t low_threshold_show(struct device * dev,
                                  struct device_attribute * attr,
                                  char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%hu\n",
                     chip->tof_cfg.low_threshold);
}

static ssize_t low_threshold_store(struct device * dev,
                                   struct device_attribute * attr,
                                   const char * buf,
                                   size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint16_t th;
    int rc;

    sscanf(buf, "%hi", &th);
    dev_info(dev, "%s: %hu\n", __func__, th);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.low_threshold = th;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring low threshold\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t high_threshold_show(struct device * dev,
                                   struct device_attribute * attr,
                                   char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%hu\n",
                     chip->tof_cfg.high_threshold);
}

static ssize_t high_threshold_store(struct device * dev,
                                    struct device_attribute * attr,
                                    const char * buf,
                                    size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint16_t th;
    int rc;

    sscanf(buf, "%hi", &th);
    dev_info(dev, "%s: %hu\n", __func__, th);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.high_threshold = th;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring high threshold\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t persistence_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%hhu\n",
                     chip->tof_cfg.persistence);
}

static ssize_t persistence_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buf,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t per;
    int rc;

    sscanf(buf, "%hhi", &per);
    dev_info(dev, "%s: %hhu\n", __func__, per);
    AMS_MUTEX_LOCK(&chip->lock);

    chip->tof_cfg.persistence = per;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_info(dev, "Error configuring persistence\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    kfifo_reset(&chip->fifo_out);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t xoff_q1_0_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%d\n",
                     chip->tof_spad_cfg.spad_configs[0].xoff_q1);
}

static ssize_t xoff_q1_0_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int8_t xoff;

    sscanf(buf, "%hhi", &xoff);
    dev_info(dev, "%s: %d\n", __func__, xoff);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[0].xoff_q1 = xoff;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t xoff_q1_1_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%d\n",
                     chip->tof_spad_cfg.spad_configs[1].xoff_q1);
}

static ssize_t xoff_q1_1_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int8_t xoff;

    sscanf(buf, "%hhi", &xoff);
    dev_info(dev, "%s: %d\n", __func__, xoff);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[1].xoff_q1 = xoff;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t yoff_q1_0_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%d\n",
                     chip->tof_spad_cfg.spad_configs[0].yoff_q1);
}

static ssize_t yoff_q1_0_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int8_t yoff;

    sscanf(buf, "%hhi", &yoff);
    dev_info(dev, "%s: %d\n", __func__, yoff);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[0].yoff_q1 = yoff;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t yoff_q1_1_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%d\n",
                     chip->tof_spad_cfg.spad_configs[1].yoff_q1);
}

static ssize_t yoff_q1_1_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int8_t yoff;

    sscanf(buf, "%hhi", &yoff);
    dev_info(dev, "%s: %d\n", __func__, yoff);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[1].yoff_q1 = yoff;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t xsize_0_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n",
                     chip->tof_spad_cfg.spad_configs[0].xsize);
}

static ssize_t xsize_0_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t xsize;

    sscanf(buf, "%hhi", &xsize);
    dev_info(dev, "%s: %u\n", __func__, xsize);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[0].xsize = xsize;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t xsize_1_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n",
                     chip->tof_spad_cfg.spad_configs[1].xsize);
}

static ssize_t xsize_1_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t xsize;

    sscanf(buf, "%hhi", &xsize);
    dev_info(dev, "%s: %u\n", __func__, xsize);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[1].xsize = xsize;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t ysize_0_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n",
                     chip->tof_spad_cfg.spad_configs[0].ysize);
}

static ssize_t ysize_0_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t ysize;

    sscanf(buf, "%hhi", &ysize);
    dev_info(dev, "%s: %u\n", __func__, ysize);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[0].ysize = ysize;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t ysize_1_show(struct device * dev,
                            struct device_attribute * attr,
                            char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%u\n",
                     chip->tof_spad_cfg.spad_configs[1].ysize);
}

static ssize_t ysize_1_store(struct device * dev,
                             struct device_attribute * attr,
                             const char * buf,
                             size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t ysize;

    sscanf(buf, "%hhi", &ysize);
    dev_info(dev, "%s: %u\n", __func__, ysize);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->tof_spad_cfg.spad_configs[1].ysize = ysize;
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t spad_mask_0_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t i, j, idx;
    uint32_t len = 0;
    uint32_t xlen, ylen;
    xlen = chip->tof_spad_cfg.spad_configs[0].xsize;
    ylen = chip->tof_spad_cfg.spad_configs[0].ysize;
    for (i = 0; i < ylen; ++i) {
        for (j = 0; j < xlen; ++j) {
            idx = i*xlen + j;
            len += scnprintf(buf + len, PAGE_SIZE - len,
                             "%u ", chip->tof_spad_cfg.spad_configs[0].spad_mask[idx]);
        }
        len += scnprintf(buf + len, PAGE_SIZE - len, "\n");
    }
    return len;
}

static ssize_t spad_mask_0_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buffer,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t mask[TMF8X2X_COM_MAX_SPAD_SIZE] = {0};
    uint32_t i;
    int rc;
    char *buf = kstrndup(buffer, count, GFP_KERNEL);
    char *save_str = buf;
    char *tok = strsep((char **)&buf, " \n\r\t");

    for (i = 0; i < ARRAY_SIZE(mask) && tok; ++i) {
        while (tok && !(rc = sscanf(tok, "%hhi", &mask[i])))
            tok = strsep(&buf, " \n\r\t");
        if (rc < 0) {
            kfree(save_str);
            return -EIO;
        }
        tok = strsep(&buf, " \n\r\t");
    }
    AMS_MUTEX_LOCK(&chip->lock);
    memset(chip->tof_spad_cfg.spad_configs[0].spad_mask, 0,
           sizeof(chip->tof_spad_cfg.spad_configs[0].spad_mask));
    memcpy(chip->tof_spad_cfg.spad_configs[0].spad_mask, mask,
           sizeof(chip->tof_spad_cfg.spad_configs[0].spad_mask));
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    kfree(save_str);
    return count;
}

static ssize_t spad_mask_1_show(struct device * dev,
                                struct device_attribute * attr,
                                char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t i, j, idx;
    uint32_t len = 0;
    uint32_t xlen, ylen;
    xlen = chip->tof_spad_cfg.spad_configs[1].xsize;
    ylen = chip->tof_spad_cfg.spad_configs[1].ysize;
    for (i = 0; i < ylen; ++i) {
        for (j = 0; j < xlen; ++j) {
            idx = i*xlen + j;
            len += scnprintf(buf + len, PAGE_SIZE - len,
                             "%u ", chip->tof_spad_cfg.spad_configs[1].spad_mask[idx]);
        }
        len += scnprintf(buf + len, PAGE_SIZE - len, "\n");
    }
    return len;
}

static ssize_t spad_mask_1_store(struct device * dev,
                                 struct device_attribute * attr,
                                 const char * buffer,
                                 size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t mask[TMF8X2X_COM_MAX_SPAD_SIZE] = {0};
    uint32_t i;
    int rc;
    char *buf = kstrndup(buffer, count, GFP_KERNEL);
    char *save_str = buf;
    char *tok = strsep((char **)&buf, " \n\r\t");

    for (i = 0; i < ARRAY_SIZE(mask) && tok; ++i) {
        while (tok && !(rc = sscanf(tok, "%hhi", &mask[i])))
            tok = strsep(&buf, " \n\r\t");
        if (rc < 0) {
            kfree(save_str);
            return -EIO;
        }
        tok = strsep(&buf, " \n\r\t");
    }
    AMS_MUTEX_LOCK(&chip->lock);
    memset(chip->tof_spad_cfg.spad_configs[1].spad_mask, 0,
           sizeof(chip->tof_spad_cfg.spad_configs[1].spad_mask));
    memcpy(chip->tof_spad_cfg.spad_configs[1].spad_mask, mask,
           sizeof(chip->tof_spad_cfg.spad_configs[1].spad_mask));
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    kfree(save_str);
    return count;
}

static ssize_t spad_map_0_show(struct device * dev,
                               struct device_attribute * attr,
                               char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t i, j, idx;
    uint32_t len = 0;
    uint32_t xlen, ylen;
    xlen = chip->tof_spad_cfg.spad_configs[0].xsize;
    ylen = chip->tof_spad_cfg.spad_configs[0].ysize;
    for (i = 0; i < ylen; ++i) {
        for (j = 0; j < xlen; ++j) {
            idx = i*xlen + j;
            len += scnprintf(buf + len, PAGE_SIZE - len,
                             "%u ", chip->tof_spad_cfg.spad_configs[0].spad_map[idx]);
        }
        len += scnprintf(buf + len, PAGE_SIZE - len, "\n");
    }
    return len;
}

static ssize_t spad_map_0_store(struct device * dev,
                                struct device_attribute * attr,
                                const char * buffer,
                                size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t map[TMF8X2X_COM_MAX_SPAD_SIZE] = {0};
    uint32_t i;
    int rc;
    char *buf = kstrndup(buffer, count, GFP_KERNEL);
    char *save_str = buf;
    char *tok = strsep((char **)&buf, " \n\r\t");

    for (i = 0; i < ARRAY_SIZE(map) && tok; ++i) {
        while (tok && !(rc = sscanf(tok, "%hhi", &map[i])))
            tok = strsep(&buf, " \n\r\t");
        if (rc < 0) {
            kfree(save_str);
            return -EIO;
        }
        tok = strsep(&buf, " \n\r\t");
    }
    AMS_MUTEX_LOCK(&chip->lock);
    memset(chip->tof_spad_cfg.spad_configs[0].spad_map, 0,
           sizeof(chip->tof_spad_cfg.spad_configs[0].spad_map));
    memcpy(chip->tof_spad_cfg.spad_configs[0].spad_map, map,
           sizeof(chip->tof_spad_cfg.spad_configs[0].spad_map));
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    kfree(save_str);
    return count;
}

static ssize_t spad_map_1_show(struct device * dev,
                               struct device_attribute * attr,
                               char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint32_t i, j, idx;
    uint32_t len = 0;
    uint32_t xlen, ylen;
    xlen = chip->tof_spad_cfg.spad_configs[1].xsize;
    ylen = chip->tof_spad_cfg.spad_configs[1].ysize;
    for (i = 0; i < ylen; ++i) {
        for (j = 0; j < xlen; ++j) {
            idx = i*xlen + j;
            len += scnprintf(buf + len, PAGE_SIZE - len,
                             "%u ", chip->tof_spad_cfg.spad_configs[1].spad_map[idx]);
        }
        len += scnprintf(buf + len, PAGE_SIZE - len, "\n");
    }
    return len;
}

static ssize_t spad_map_1_store(struct device * dev,
                                struct device_attribute * attr,
                                const char * buffer,
                                size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    uint8_t map[TMF8X2X_COM_MAX_SPAD_SIZE] = {0};
    uint32_t i;
    int rc;
    char *buf = kstrndup(buffer, count, GFP_KERNEL);
    char *save_str = buf;
    char *tok = strsep((char **)&buf, " \n\r\t");

    for (i = 0; i < ARRAY_SIZE(map) && tok; ++i) {
        while (tok && !(rc = sscanf(tok, "%hhi", &map[i])))
            tok = strsep(&buf, " \n\r\t");
        if (rc < 0) {
            kfree(save_str);
            return -EIO;
        }
        tok = strsep(&buf, " \n\r\t");
    }
    AMS_MUTEX_LOCK(&chip->lock);
    memset(chip->tof_spad_cfg.spad_configs[1].spad_map, 0,
           sizeof(chip->tof_spad_cfg.spad_configs[1].spad_map));
    memcpy(chip->tof_spad_cfg.spad_configs[1].spad_map, map,
           sizeof(chip->tof_spad_cfg.spad_configs[1].spad_map));
    chip->tof_spad_uncommitted = true;
    AMS_MUTEX_UNLOCK(&chip->lock);
    kfree(save_str);
    return count;
}

static ssize_t commit_spad_cfg_show(struct device * dev,
                                    struct device_attribute * attr,
                                    char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    // return true if spad configuration is committed
    return scnprintf(buf, PAGE_SIZE, "%u\n", !chip->tof_spad_uncommitted);
}

static ssize_t commit_spad_cfg_store(struct device * dev,
                                     struct device_attribute * attr,
                                     const char * buf,
                                     size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int rc;
    int val;
    sscanf(buf, "%i", &val);
    if (val == 1) {
        AMS_MUTEX_LOCK(&chip->lock);
        rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_SPADCFG, &chip->tof_spad_cfg, NULL);
        if (rc) {
            dev_err(&chip->client->dev, "Error, committing spad config failed.\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        chip->tof_spad_uncommitted = false;
        kfifo_reset(&chip->fifo_out);
        AMS_MUTEX_UNLOCK(&chip->lock);
    }
    return count;
}

static ssize_t clock_compensation_show(struct device * dev,
                                       struct device_attribute * attr,
                                       char * buf)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    bool clk_skew_corr_enabled;
    int rc;
    AMS_MUTEX_LOCK(&chip->lock);
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_IS_CLKADJ, NULL, &clk_skew_corr_enabled);
    if (rc) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        dev_err(&chip->client->dev,
                "Error, reading clock compensation state\n");
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return scnprintf(buf, PAGE_SIZE, "%u\n", clk_skew_corr_enabled);
}

static ssize_t clock_compensation_store(struct device * dev,
                                        struct device_attribute * attr,
                                        const char * buf,
                                        size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int rc;
    int val = 0;
    rc = sscanf(buf, "%i", &val);
    if (!rc) {
        dev_err(&chip->client->dev, "Error, invalid input\n");
        return -EINVAL;
    }
    AMS_MUTEX_LOCK(&chip->lock);
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CLKADJ, &val, NULL);
    if (rc) {
        dev_err(&chip->client->dev,
                "Error, setting clock compensation state %u\n", !!val);
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t set_default_cfg_store(struct device * dev,
                                     struct device_attribute * attr,
                                     const char * buf,
                                     size_t count)
{
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int error;
    AMS_MUTEX_LOCK(&chip->lock);
    error = tof_set_default_config(chip);
    if (error) {
        dev_err(&chip->client->dev, "Error, set default config failed.\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t calibration_data_write(struct file * f, struct kobject * kobj,
                                      struct bin_attribute * attr, char *buf,
                                      loff_t off, size_t size)
{
    struct device *dev = kobj_to_dev(kobj);
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    int rc;
    AMS_MUTEX_LOCK(&chip->lock);
    memcpy(chip->tof_calib.data, buf, size);
    chip->tof_calib.calib_len = size;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CALIB, &chip->tof_calib, NULL);
    if (rc < 0) {
        dev_err(&chip->client->dev, "Error, writing calibration data\n");
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return size;
}

static ssize_t calibration_data_read(struct file * f, struct kobject * kobj,
                                     struct bin_attribute * attr, char *buf,
                                     loff_t off, size_t size)
{
    struct device *dev = kobj_to_dev(kobj);
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    ssize_t count = 0;

    AMS_MUTEX_LOCK(&chip->lock);
    if (off == 0) {
        count = tmf882x_ioctl(&chip->tof, IOCAPP_GET_CALIB,
                              NULL, &chip->tof_calib);
        if (count) {
            dev_err(&chip->client->dev, "Error, reading calibration data\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        count = chip->tof_calib.calib_len;
    }

    if (off >= chip->tof_calib.calib_len || off >= sizeof(chip->tof_calib.data)) {
        // no more data to give
        AMS_MUTEX_UNLOCK(&chip->lock);
        return 0;
    }

    count = size < count ? size : count;

    if (size + off > chip->tof_calib.calib_len) {
        count = chip->tof_calib.calib_len - off;
    }

    memcpy(buf, &chip->tof_calib.data[off], count);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static ssize_t factory_calibration_read(struct file * f, struct kobject * kobj,
                                        struct bin_attribute * attr, char *buf,
                                        loff_t off, size_t size)
{
    struct device *dev = kobj_to_dev(kobj);
    struct tof_sensor_chip *chip = dev_get_drvdata(dev);
    ssize_t count = 0;
    AMS_MUTEX_LOCK(&chip->lock);
    if (off == 0) {
        count = tmf882x_ioctl(&chip->tof, IOCAPP_DO_FACCAL,
                              NULL, &chip->tof_calib);
        if (count) {
            dev_err(&chip->client->dev, "Error, performing factory calibration\n");
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        count = chip->tof_calib.calib_len;
    }

    if (off >= chip->tof_calib.calib_len || off >= sizeof(chip->tof_calib.data)) {
        // no more data to give
        AMS_MUTEX_UNLOCK(&chip->lock);
        return 0;
    }

    // cap return amount to user space
    count = size < count ? size : count;

    if (size + off > chip->tof_calib.calib_len) {
        count = chip->tof_calib.calib_len - off;
    }

    memcpy(buf, &chip->tof_calib.data[off], count);
    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

/****************************************************************************
 * Common Sysfs Attributes
 * **************************************************************************/
/******* READ-WRITE attributes ******/
static DEVICE_ATTR_RW(mode);
static DEVICE_ATTR_RW(chip_enable);
static DEVICE_ATTR_RW(driver_debug);
/******* READ-ONLY attributes ******/
static DEVICE_ATTR_RO(firmware_version);
static DEVICE_ATTR_RO(registers);
static DEVICE_ATTR_RO(device_uid);
static DEVICE_ATTR_RO(device_revision);
/******* WRITE-ONLY attributes ******/
static DEVICE_ATTR_WO(register_write);
static DEVICE_ATTR_WO(request_ram_patch);

/****************************************************************************
 * Bootloader Sysfs Attributes
 * **************************************************************************/
/******* READ-WRITE attributes ******/
/******* READ-ONLY attributes ******/
/******* WRITE-ONLY attributes ******/

/****************************************************************************
 * app Sysfs Attributes
 * *************************************************************************/
/******* READ-WRITE attributes ******/
static DEVICE_ATTR_RW(capture);
static DEVICE_ATTR_RW(report_period_ms);
static DEVICE_ATTR_RW(iterations);
static DEVICE_ATTR_RW(alg_setting);
static DEVICE_ATTR_RW(power_cfg);
static DEVICE_ATTR_RW(gpio_0);
static DEVICE_ATTR_RW(gpio_1);
static DEVICE_ATTR_RW(histogram_dump);
static DEVICE_ATTR_RW(spad_map_id);
static DEVICE_ATTR_RW(zone_mask);
static DEVICE_ATTR_RW(conf_threshold);
static DEVICE_ATTR_RW(low_threshold);
static DEVICE_ATTR_RW(high_threshold);
static DEVICE_ATTR_RW(persistence);
static DEVICE_ATTR_RW(xoff_q1_0);
static DEVICE_ATTR_RW(xoff_q1_1);
static DEVICE_ATTR_RW(yoff_q1_0);
static DEVICE_ATTR_RW(yoff_q1_1);
static DEVICE_ATTR_RW(xsize_0);
static DEVICE_ATTR_RW(xsize_1);
static DEVICE_ATTR_RW(ysize_0);
static DEVICE_ATTR_RW(ysize_1);
static DEVICE_ATTR_RW(spad_mask_0);
static DEVICE_ATTR_RW(spad_mask_1);
static DEVICE_ATTR_RW(spad_map_0);
static DEVICE_ATTR_RW(spad_map_1);
static DEVICE_ATTR_RW(commit_spad_cfg);
static DEVICE_ATTR_RW(clock_compensation);
/******* WRITE-ONLY attributes ******/
static DEVICE_ATTR_WO(set_default_cfg);

/******* READ-WRITE BINARY attributes ******/
static BIN_ATTR_RW(calibration_data, 0);
/******* WRITE-ONLY BINARY attributes ******/
/******* READ-ONLY BINARY attributes ******/
static BIN_ATTR_RO(factory_calibration, 0);

static struct attribute *tof_common_attrs[] = {
    &dev_attr_mode.attr,
    &dev_attr_chip_enable.attr,
    &dev_attr_driver_debug.attr,
    &dev_attr_firmware_version.attr,
    &dev_attr_registers.attr,
    &dev_attr_register_write.attr,
    &dev_attr_request_ram_patch.attr,
    &dev_attr_device_uid.attr,
    &dev_attr_device_revision.attr,
    NULL,
};
static struct attribute *tof_bl_attrs[] = {
    NULL,
};
static struct attribute *tof_app_attrs[] = {
    &dev_attr_capture.attr,
    &dev_attr_report_period_ms.attr,
    &dev_attr_iterations.attr,
    &dev_attr_alg_setting.attr,
    &dev_attr_power_cfg.attr,
    &dev_attr_gpio_0.attr,
    &dev_attr_gpio_1.attr,
    &dev_attr_histogram_dump.attr,
    &dev_attr_set_default_cfg.attr,
    &dev_attr_spad_map_id.attr,
    &dev_attr_conf_threshold.attr,
    &dev_attr_low_threshold.attr,
    &dev_attr_high_threshold.attr,
    &dev_attr_persistence.attr,
    &dev_attr_zone_mask.attr,
    &dev_attr_xoff_q1_0.attr,
    &dev_attr_xoff_q1_1.attr,
    &dev_attr_yoff_q1_0.attr,
    &dev_attr_yoff_q1_1.attr,
    &dev_attr_xsize_0.attr,
    &dev_attr_xsize_1.attr,
    &dev_attr_ysize_0.attr,
    &dev_attr_ysize_1.attr,
    &dev_attr_spad_mask_0.attr,
    &dev_attr_spad_mask_1.attr,
    &dev_attr_spad_map_0.attr,
    &dev_attr_spad_map_1.attr,
    &dev_attr_commit_spad_cfg.attr,
    &dev_attr_clock_compensation.attr,
    NULL,
};
static struct bin_attribute *tof_app_bin_attrs[] = {
    &bin_attr_factory_calibration,
    &bin_attr_calibration_data,
    NULL,
};
static const struct attribute_group tof_common_group = {
    .attrs = tof_common_attrs,
};
static const struct attribute_group tof_bl_group = {
    .name = "bootloader",
    .attrs = tof_bl_attrs,
};
static const struct attribute_group tof_app_group = {
    .name = "app",
    .attrs = tof_app_attrs,
    .bin_attrs = tof_app_bin_attrs,
};
static const struct attribute_group *tof_groups[] = {
    &tof_common_group,
    &tof_bl_group,
    &tof_app_group,
    NULL,
};

/**
 * tof_frwk_i2c_read - Read number of bytes starting at a specific address over I2C
 *
 * @client: the i2c client
 * @reg: the i2c register address
 * @buf: pointer to a buffer that will contain the received data
 * @len: number of bytes to read
 */
int tof_frwk_i2c_read(struct tof_sensor_chip *chip, char reg, char *buf, int len)
{
    struct i2c_client *client = chip->client;
    struct i2c_msg msgs[2];
    int ret;

    msgs[0].flags = 0;
    msgs[0].addr  = client->addr;
    msgs[0].len   = 1;
    msgs[0].buf   = &reg;

    msgs[1].flags = I2C_M_RD;
    msgs[1].addr  = client->addr;
    msgs[1].len   = len;
    msgs[1].buf   = buf;

    ret = i2c_transfer(client->adapter, msgs, 2);
    return ret < 0 ? ret : (ret != ARRAY_SIZE(msgs) ? -EIO : 0);
}

/**
 * tof_frwk_i2c_write - Write nuber of bytes starting at a specific address over I2C
 *
 * @client: the i2c client
 * @reg: the i2c register address
 * @buf: pointer to a buffer that will contain the data to write
 * @len: number of bytes to write
 */
int tof_frwk_i2c_write(struct tof_sensor_chip *chip, char reg, const char *buf, int len)
{
    struct i2c_client *client = chip->client;
    u8 *addr_buf;
    struct i2c_msg msg;
    int idx = reg;
    int ret;
    char debug[120];
    u32 strsize = 0;

    addr_buf = kmalloc(len + 1, GFP_KERNEL);
    if (!addr_buf)
        return -ENOMEM;

    addr_buf[0] = reg;
    memcpy(&addr_buf[1], buf, len);
    msg.flags = 0;
    msg.addr = client->addr;
    msg.buf = addr_buf;
    msg.len = len + 1;

    ret = i2c_transfer(client->adapter, &msg, 1);
    if (ret != 1) {
        dev_err(&client->dev, "i2c_transfer failed: %d msg_len: %u", ret, len);
    }
    if (chip->driver_debug > 2) {
        strsize = scnprintf(debug, sizeof(debug), "i2c_write: ");
        for(idx = 0; (ret == 1) && (idx < msg.len); idx++) {
            strsize += scnprintf(debug + strsize, sizeof(debug) - strsize, "%02x ", addr_buf[idx]);
        }
        dev_info(&client->dev, "%s", debug);
    }

    kfree(addr_buf);
    return ret < 0 ? ret : (ret != 1 ? -EIO : 0);
}

/**
 * tof_frwk_i2c_write_mask - Write a byte to the specified address with a given bitmask
 *
 * @client: the i2c client
 * @reg: the i2c register address
 * @val: byte to write
 * @mask: bitmask to apply to address before writing
 */
static int tof_frwk_i2c_write_mask(struct tof_sensor_chip *chip, char reg,
                                   const char *val, char mask)
{
    int ret;
    u8 temp;

    ret = tof_frwk_i2c_read(chip, reg, &temp, 1);
    temp &= ~mask;
    temp |= *val;
    ret = tof_frwk_i2c_write(chip, reg, &temp, 1);

    return ret;
}

/**
 * tof_hard_reset - use GPIO Chip Enable to reset the device
 *
 * @tof_chip: tof_sensor_chip pointer
 */
static int tof_hard_reset(struct tof_sensor_chip *chip)
{
    int error = 0;

    (void) tof_poweroff_device(chip);
    error = tof_open_mode(chip, TMF882X_MODE_APP);
    if (error) {
        dev_err(&chip->client->dev, "Error powering up device: %d\n", error);
        return error;
    }

    return error;
}

/**
 * tof_get_gpio_config - Get GPIO config from DT
 *
 * @tof_chip: tof_sensor_chip pointer
 */
static int tof_get_gpio_config(struct tof_sensor_chip *tof_chip)
{
    int error;
    struct device *dev;
    struct gpio_desc *gpiod;
    int irq_num;
    int pin_num;
    int direction;
    int state1, state2;

    if (!tof_chip->client)
        return -EINVAL;
    dev = &tof_chip->client->dev;

    /* Get the enable line GPIO pin number */
    gpiod = devm_gpiod_get_optional(dev, TOF_GPIO_ENABLE_NAME, GPIOD_OUT_HIGH);
    if (IS_ERR(gpiod)) {
        error = PTR_ERR(gpiod);
        return error;
    }
    tof_chip->pdata->gpiod_enable = gpiod;

    pin_num = desc_to_gpio(tof_chip->pdata->gpiod_enable);
    state1 = gpiod_get_value(tof_chip->pdata->gpiod_enable);
    state2 = gpiod_get_raw_value(tof_chip->pdata->gpiod_enable);
    direction = gpiod_get_direction(tof_chip->pdata->gpiod_enable);
    dev_err(&tof_chip->client->dev, "gpiod_enable pin_num %d, state1: %d, state2: %d, direction %d \n", pin_num, state1, state2, direction);

    // HW Chip reset
    if (gpiod) {
        (void) gpiod_direction_output(tof_chip->pdata->gpiod_enable, 0);
        pin_num = desc_to_gpio(tof_chip->pdata->gpiod_enable);
        state1 = gpiod_get_value(tof_chip->pdata->gpiod_enable);
        state2 = gpiod_get_raw_value(tof_chip->pdata->gpiod_enable);
        direction = gpiod_get_direction(tof_chip->pdata->gpiod_enable);
        dev_err(&tof_chip->client->dev, "HW Chip reset - gpiod_enable pin_num %d, state1: %d, state2: %d, direction %d \n", pin_num, state1, state2, direction);

        usleep_range(1000, 1001);
        (void) gpiod_direction_output(tof_chip->pdata->gpiod_enable, 1);

        pin_num = desc_to_gpio(tof_chip->pdata->gpiod_enable);
        state1 = gpiod_get_value(tof_chip->pdata->gpiod_enable);
        state2 = gpiod_get_raw_value(tof_chip->pdata->gpiod_enable);
        direction = gpiod_get_direction(tof_chip->pdata->gpiod_enable);
        dev_err(&tof_chip->client->dev, "HW Chip reset - gpiod_enable pin_num %d, state1: %d, state2: %d, direction %d \n", pin_num, state1, state2, direction);
        usleep_range(2000, 2001);
    }

    /* Get the interrupt GPIO pin number */
    gpiod = devm_gpiod_get_optional(dev, TOF_GPIO_INT_NAME, GPIOD_IN);
    if (IS_ERR(gpiod)) {
        error = PTR_ERR(gpiod);
        return error;
    }
    tof_chip->pdata->gpiod_interrupt = gpiod;

    irq_num = gpiod_to_irq(tof_chip->pdata->gpiod_interrupt);
    pin_num = desc_to_gpio(tof_chip->pdata->gpiod_interrupt);
    state1 = gpiod_get_value(tof_chip->pdata->gpiod_interrupt);
    state2 = gpiod_get_raw_value(tof_chip->pdata->gpiod_interrupt);
    direction = gpiod_get_direction(tof_chip->pdata->gpiod_interrupt);
    dev_err(&tof_chip->client->dev, "gpiod_interrupt irq_num %d, pin_num %d, state1: %d, state2: %d, direction %d \n", irq_num, pin_num, state1, state2, direction);
    return 0;
}

/**
 * tof_ram_patch_callback - The firmware download callback
 *
 * @cfg: the firmware cfg structure
 * @ctx: private data pointer to struct tof_sensor_chip
 */
static void tof_ram_patch_callback(const struct firmware *cfg, void *ctx)
{
    struct tof_sensor_chip *chip = ctx;
    int result = 0;
    struct timespec64 fwdl_time = {0};
    struct timespec64 start_ts = {0}, end_ts = {0};
    s64 delay_ms;

    if (!chip) {
        pr_err("AMS-TOF Error: Ram patch callback NULL context pointer.\n");
    }

    if (!cfg) {
        dev_warn(&chip->client->dev, "%s: Warning, firmware not available.\n", __func__);
        goto err_fwdl;
    }

    // mode switch to the bootloader for FWDL
    if (tmf882x_mode_switch(&chip->tof, TMF882X_MODE_BOOTLOADER)) {
        dev_info(&chip->client->dev, "%s mode switch for FWDL failed\n", __func__);
        tmf882x_dump_i2c_regs(tmf882x_mode_hndl(&chip->tof));
        goto err_fwdl;
    }

    dev_info(&chip->client->dev, "%s: Ram patch in progress...\n", __func__);
    //Start fwdl timer
    ktime_get_ts64(&start_ts);
    result = tmf882x_fwdl(&chip->tof, FWDL_TYPE_HEX, cfg->data, cfg->size);
    if (result)
        goto err_fwdl;
    //Stop fwdl timer
    ktime_get_ts64(&end_ts);
    //time in ms
    fwdl_time = timespec64_sub(end_ts, start_ts);
    delay_ms = div_s64(timespec64_to_ns(&fwdl_time), 1000000);
    dev_info(&chip->client->dev,
            "%s: Ram patch complete, dl time: %llu ms\n", __func__, delay_ms);
err_fwdl:
    release_firmware(cfg);
    complete_all(&chip->ram_patch_in_progress);
}

static int tof_poweroff_device(struct tof_sensor_chip *chip)
{
    tmf882x_close(&chip->tof);
    if (!chip->pdata->gpiod_enable) {
        return 0;
    }
    chip->fwdl_needed = true;
    return gpiod_direction_output(chip->pdata->gpiod_enable, 0);
}

/**
 * tof_irq_handler - The IRQ handler
 *
 * @irq: interrupt number.
 * @dev_id: private data pointer.
 */
static irqreturn_t tof_irq_handler(int irq, void *dev_id)
{
    struct tof_sensor_chip *tof_chip = (struct tof_sensor_chip *)dev_id;
    AMS_MUTEX_LOCK(&tof_chip->lock);
    (void) tmf882x_process_irq(&tof_chip->tof);
    // wake up userspace even for errors
    wake_up_interruptible_sync(&tof_chip->fifo_wait);
    AMS_MUTEX_UNLOCK(&tof_chip->lock);
    return IRQ_HANDLED;
}

static int tmf882x_poll_irq_thread(void *tof_chip)
{
    struct tof_sensor_chip *chip = (struct tof_sensor_chip *)tof_chip;
    int us_sleep = 0;
    AMS_MUTEX_LOCK(&chip->lock);
    // Poll period is interpreted in units of 100 usec
    us_sleep = chip->poll_period * 100;
    dev_info(&chip->client->dev,
             "Starting ToF irq polling thread, period: %u us\n", us_sleep);
    AMS_MUTEX_UNLOCK(&chip->lock);
    while (!kthread_should_stop()) {
        (void) tof_irq_handler(0, tof_chip);
        AMS_MUTEX_LOCK(&chip->lock);
        // Poll period is interpreted in units of 100 usec
        us_sleep = chip->poll_period * 100;
        AMS_MUTEX_UNLOCK(&chip->lock);
        usleep_range(us_sleep, us_sleep + us_sleep/10);
    }
    return 0;
}

/**
 * tof_request_irq - request IRQ for given gpio
 *
 * @tof_chip: tof_sensor_chip pointer
 */
static int tof_request_irq(struct tof_sensor_chip *tof_chip)
{
    int irq = tof_chip->client->irq;
    unsigned long default_trigger =
        irqd_get_trigger_type(irq_get_irq_data(irq));
    dev_info(&tof_chip->client->dev,
             "irq: %d, trigger_type: %lu", irq, default_trigger);
    return devm_request_threaded_irq(&tof_chip->client->dev,
                                     tof_chip->client->irq,
                                     NULL, tof_irq_handler,
                                     default_trigger |
                                     IRQF_SHARED     |
                                     IRQF_ONESHOT,
                                     tof_chip->client->name,
                                     tof_chip);
}

int tof_frwk_queue_msg(struct tof_sensor_chip *chip, struct tmf882x_msg *msg)
{
    unsigned int fifo_len;
    int result = kfifo_in(&chip->fifo_out, msg->msg_buf, msg->hdr.msg_len);
    struct tmf882x_msg_error err;

    tof_publish_input_events(chip, msg); // publish any input events

    // handle FIFO overflow case
    if (result != msg->hdr.msg_len) {
        TOF_SET_ERR_MSG(&err, ERR_BUF_OVERFLOW);
        (void) kfifo_in(&chip->fifo_out, (char *)&err, err.hdr.msg_len);
        if (chip->driver_debug == 1)
            dev_err(&chip->client->dev,
                    "Error: Message buffer is full, clearing buffer.\n");
        kfifo_reset(&chip->fifo_out);
        result = kfifo_in(&chip->fifo_out, msg->msg_buf, msg->hdr.msg_len);
        if (result != msg->hdr.msg_len) {
            dev_err(&chip->client->dev,
                    "Error: queueing ToF output message.\n");
        }
    }
    if (chip->driver_debug == 2) {
        fifo_len = kfifo_len(&chip->fifo_out);
        dev_info(&chip->client->dev,
                "New fifo len: %u, fifo utilization: %u%%\n",
                fifo_len, (1000*fifo_len/kfifo_size(&chip->fifo_out))/10);
    }
    return (result == msg->hdr.msg_len) ? 0 : -1;
}

static void tof_idev_close(struct input_dev *dev)
{
    struct tof_sensor_chip *chip = input_get_drvdata(dev);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->open_refcnt--;
    if (!chip->open_refcnt) {
        dev_info(&dev->dev, "%s\n", __func__);
        tof_poweroff_device(chip);
        kfifo_reset(&chip->fifo_out);
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return;
}

static int tof_idev_open(struct input_dev *dev)
{
    struct tof_sensor_chip *chip = input_get_drvdata(dev);
    int error = 0;
    AMS_MUTEX_LOCK(&chip->lock);
    if (chip->open_refcnt++) {
        error = tmf882x_start(&chip->tof);
        if (error) {
            dev_err(&dev->dev, "Error, start measurements failed.\n");
            chip->open_refcnt--;
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        AMS_MUTEX_UNLOCK(&chip->lock);
        return 0;
    }

    dev_info(&dev->dev, "%s\n", __func__);
    error = tof_open_mode(chip, TMF882X_MODE_APP);
    if (error) {
        dev_err(&dev->dev, "Chip enable failed.\n");
        chip->open_refcnt--;
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    error = tof_set_default_config(chip);
    if (error) {
        dev_err(&dev->dev, "Error, set default config failed.\n");
        chip->open_refcnt--;
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    error = tmf882x_start(&chip->tof);
    if (error) {
        dev_err(&dev->dev, "Error, start measurements failed.\n");
        chip->open_refcnt--;
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return error;
}

static int tof_misc_release(struct inode *inode, struct file *f)
{
    struct miscdevice *misc = (struct miscdevice *)f->private_data;
    struct tof_sensor_chip *chip =
        container_of(misc, struct tof_sensor_chip, tof_mdev);
    AMS_MUTEX_LOCK(&chip->lock);
    chip->open_refcnt--;
    if (!chip->open_refcnt) {
        dev_info(&chip->client->dev, "%s\n", __func__);
        tof_poweroff_device(chip);
        kfifo_reset(&chip->fifo_out);
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return 0;
}

static int tof_misc_open(struct inode *inode, struct file *f)
{
    struct miscdevice *misc = (struct miscdevice *)f->private_data;
    struct tof_sensor_chip *chip =
        container_of(misc, struct tof_sensor_chip, tof_mdev);
    int ret;

    if (O_WRONLY == (f->f_flags & O_ACCMODE))
        return -EACCES;

    if (f->f_flags & O_NONBLOCK) {
        ret = AMS_MUTEX_TRYLOCK(&chip->lock);
        if(!ret){
            dev_info(&chip->client->dev, "Error, open would block\n");
            return -EWOULDBLOCK;
        }
    } else {
        AMS_MUTEX_LOCK(&chip->lock);
    }
    if (chip->open_refcnt++) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return 0;
    }

    dev_info(&chip->client->dev, "%s\n", __func__);
    ret = tof_open_mode(chip, TMF882X_MODE_APP);
    if (ret) {
        dev_err(&chip->client->dev, "Chip init failed: %d\n", ret);
        chip->open_refcnt--;
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    ret = tof_set_default_config(chip);
    if (ret) {
        dev_err(&chip->client->dev, "Error, set default config failed.\n");
        chip->open_refcnt--;
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EIO;
    }
    AMS_MUTEX_UNLOCK(&chip->lock);
    return 0;
}

static ssize_t tof_misc_read(struct file *f, char *buf,
                             size_t len, loff_t *off)
{
    struct miscdevice *misc = (struct miscdevice *)f->private_data;
    struct tof_sensor_chip *chip =
        container_of(misc, struct tof_sensor_chip, tof_mdev);
    unsigned int copied = 0;
    int ret = 0;
    size_t msg_size;
    ssize_t count = 0;

    if (f->f_flags & O_NONBLOCK) {
        ret = AMS_MUTEX_TRYLOCK(&chip->lock);
        if(!ret){
            dev_info(&chip->client->dev, "Error, read would block\n");
            return -EWOULDBLOCK;
        }
    } else {
        AMS_MUTEX_LOCK(&chip->lock);
    }

    // sleep for more data
    while ( kfifo_is_empty(&chip->fifo_out) ) {
        if (f->f_flags & O_NONBLOCK) {
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -ENODATA;
        }
        AMS_MUTEX_UNLOCK(&chip->lock);
        ret = wait_event_interruptible(chip->fifo_wait,
                                       (!kfifo_is_empty(&chip->fifo_out) ||
                                        chip->driver_remove));
        if (ret) return ret;
        else if (chip->driver_remove) return 0;
        AMS_MUTEX_LOCK(&chip->lock);
    }

    count = 0;
    msg_size = tof_fifo_next_msg_size(chip);
    if (len < msg_size) {
        AMS_MUTEX_UNLOCK(&chip->lock);
        return -EINVAL;
    }

    do {
        ret = kfifo_to_user(&chip->fifo_out, &buf[count], msg_size, &copied);
        if (ret) {
            dev_err(&chip->client->dev, "Error (%d), reading from fifo\n", ret);
            AMS_MUTEX_UNLOCK(&chip->lock);
            return -EIO;
        }
        count += copied;
        msg_size = tof_fifo_next_msg_size(chip);
        if (!msg_size) break;
    } while (msg_size < (len - count));

    AMS_MUTEX_UNLOCK(&chip->lock);
    return count;
}

static unsigned int tof_misc_poll(struct file *f,
                                  struct poll_table_struct *wait)
{
    struct miscdevice *misc = (struct miscdevice *)f->private_data;
    struct tof_sensor_chip *chip =
        container_of(misc, struct tof_sensor_chip, tof_mdev);

    poll_wait(f, &chip->fifo_wait, wait);
    if (!kfifo_is_empty(&chip->fifo_out))
        return POLLIN | POLLRDNORM;
    return 0;
}

#define TEST_READ
static ams_calibration_data amsCalibData;

static int tmf882x_get_info(struct tof_sensor_chip *chip, void __user *p)
{
    hwlaser_info_t info;
    hwlaser_info_t __user *pinfo = NULL;
    uint8_t sn_buf[TMF882X_SN_LEN] = {0};
    int32_t ret;

    if (!p) {
        dev_err(&chip->client->dev, "invalid params\n");
        return -EINVAL;
    }

    pinfo = (hwlaser_info_t *)p;

    memset(&info, 0, sizeof(info));

    info.version = LASER_AMS_TMF882X_VERSION;

    ret = tof_i2c_read(chip, TMF882X_SN_ADDR, sn_buf, TMF882X_SN_LEN);
    if (ret) {
        dev_err(&chip->client->dev, "Error reading SN");
        return -EINVAL;
    }

    info.sn = (uint32_t)sn_buf[3] << 24 | (uint32_t)sn_buf[2] << 16 |
        (uint32_t)sn_buf[1] << 8 | (uint32_t)sn_buf[0];
    dev_info(&chip->client->dev, "%s version %d, sn 0x%x\n", __func__, info.version, info.sn);

    if (copy_to_user(pinfo, &info, sizeof(hwlaser_info_t))) {
        dev_err(&chip->client->dev, "fail\n");
        return -EFAULT;
    }

    return 0;
}

static int tmf882x_set_spad_map_id_and_iterations(struct tof_sensor_chip *chip, uint8_t map_id, uint32_t iterations)
{
    int rc;
    dev_info(&chip->client->dev, "%s: map_id %u, iterations %u\n", __func__, map_id, iterations);

    chip->tof_cfg.kilo_iterations = iterations >> 10;
    chip->tof_cfg.spad_map_id = map_id;
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_SET_CFG, &chip->tof_cfg, NULL);
    if (rc) {
        dev_err(&chip->client->dev, "Error configuring spad_map_id_and_iterations\n");
        return -EIO;
    }
    // read out spad config since spad map id has changed
    memset(&chip->tof_spad_cfg, 0, sizeof(chip->tof_spad_cfg));
    rc = tmf882x_ioctl(&chip->tof, IOCAPP_GET_SPADCFG, NULL, &chip->tof_spad_cfg);
    if (rc) {
        dev_err(&chip->client->dev, "Error, reading spad config failed.\n");
        return -EIO;
    }
    // read out fresh spad configuration from device, overwrite local copy
    chip->tof_spad_uncommitted = false;
    kfifo_reset(&chip->fifo_out);
    return 0;
}

static int tmf882x_calibrate_crosstalk_3x3(struct tof_sensor_chip *chip)
{
    int i;
    int32_t rc;
    struct tmf882x_mode *self = &chip->tof.state;
    struct tmf882x_mode_app *app;
    uint32_t calib_cross_data_3x3[CROSSTALK_SIZE] = {0};
    int index = CROSSTALK_SIZE - 1;
    int calib_addr = 0x5f;

    if (tmf882x_set_spad_map_id_and_iterations(chip, 1, 550000) < 0) {
        dev_err(&chip->client->dev, "tmf882x_set_spad_map_id_and_iterations fail\n");
        return -EFAULT;
    }

    app = member_of(self, struct tmf882x_mode_app, mode);
    rc = tmf882x_mode_app_do_factory_calib(app, &chip->tof_calib);

    memset(&amsCalibData.calib_cross_data_3x3[0], 0, sizeof(amsCalibData.calib_cross_data_3x3));

    for (; index >= 0; index--) {
        calib_cross_data_3x3[index] = (uint32_t)(chip->tof_calib.data[calib_addr]) << 24 |
            (uint32_t)(chip->tof_calib.data[calib_addr - 1]) << 16 |
            (uint32_t)(chip->tof_calib.data[calib_addr - 2]) << 8 |
            (uint32_t)(chip->tof_calib.data[calib_addr - 3]);
        calib_addr -= 4;
    }

    memcpy(&amsCalibData.calib_cross_data_3x3[0], &calib_cross_data_3x3[0],
           sizeof(amsCalibData.calib_cross_data_3x3));
#ifdef TEST_READ
    /* test read */
    for (i = 0; i < CROSSTALK_SIZE; i++) {
        dev_info(&chip->client->dev, "%s get calib_data[%d] = %d\n", __func__, i, amsCalibData.calib_cross_data_3x3[i]);
    }
#endif
    return rc;
}

static int tmf882x_calibrate_4x4(struct tof_sensor_chip *chip)
{
    int i;
    int32_t rc;
    struct tmf882x_mode *self = &chip->tof.state;
    struct tmf882x_mode_app *app;
    if (tmf882x_set_spad_map_id_and_iterations(chip, 7, 4000000) < 0) {
        dev_err(&chip->client->dev, "tmf882x_set_spad_map_id_and_iterations fail\n");
        return -EFAULT;
    }

    app = member_of(self, struct tmf882x_mode_app, mode);
    rc = tmf882x_mode_app_do_factory_calib(app, &chip->tof_calib);

    memset(&amsCalibData.calib_data_4x4[0], 0, sizeof(amsCalibData.calib_data_4x4));
    memcpy(&amsCalibData.calib_data_4x4[0], &chip->tof_calib.data[0],
           sizeof(amsCalibData.calib_data_4x4));
#ifdef TEST_READ
    /* test read */
    for (i = 0; i < QUADRANT_CALIB_SIZE; i++) {
        dev_info(&chip->client->dev, "%s get calib_data[%d] = %d\n", __func__, i, amsCalibData.calib_data_4x4[i]);
    }
#endif
    return rc;
}

static int tmf882x_perform_calibration(struct tof_sensor_chip *chip, void __user *p)
{
    int rc;
    hwlaser_ioctl_perform_calibration_t calib;

    rc = copy_from_user(&calib, p, sizeof(calib));
    if (rc) {
        rc = -EFAULT;
        return rc;
    }

    dev_info(&chip->client->dev, "%s calib type %d\n", __func__, calib.calibration_type);

    if (tmf882x_calibrate_crosstalk_3x3(chip)) {
        dev_err(&chip->client->dev, "tmf882x_calibrate_crosstalk_3x3 fail\n");
        return -EFAULT;
    }
    dev_info(&chip->client->dev, "%s 3x3 calib crosstalk done\n", __func__);
    usleep_range(1000, 1001);

    if (tmf882x_calibrate_4x4(chip)) {
        dev_err(&chip->client->dev, "tmf882x_calibrate_4x4 fail\n");
        return -EFAULT;
    }
    dev_info(&chip->client->dev, "%s 4x4 calib done\n", __func__);
    usleep_range(1000, 1001);

    return rc;
}

static int tmf882x_ctrl_calibration_data(struct tof_sensor_chip *chip, void __user *p)
{
    int i;
    int rc;
    struct tmf882x_mode *self = &chip->tof.state;
    struct tmf882x_mode_app *app;
    hwlaser_calibration_data_t calib;
    int data_offset = offsetof(hwlaser_calibration_data_t, amsCalibData);
    rc = copy_from_user(&calib, p, data_offset);
    if (rc) {
        dev_err(&chip->client->dev, "fail to detect read or write %d", rc);
        rc = -EFAULT;
        return rc;
    }

    dev_info(&chip->client->dev, "%s calib.is_read %d\n", __func__, calib.is_read);
    if (calib.is_read == 1) {
        memset(&calib.amsCalibData, 0, sizeof(calib.amsCalibData));
        memcpy(&calib.amsCalibData, &amsCalibData, sizeof(calib.amsCalibData));

        rc = copy_to_user(p + data_offset, &calib.amsCalibData,
            sizeof(calib.amsCalibData));
    } else {
        rc = copy_from_user(&calib.amsCalibData, p + data_offset,
            sizeof(calib.amsCalibData));
        if (rc) {
            dev_err(&chip->client->dev, "fail to copy calib data");
            rc = -EFAULT;
            return rc;
        }
        memset(chip->tof_calib.data, 0, sizeof(chip->tof_calib.data));
        app = member_of(self, struct tmf882x_mode_app, mode);

        memcpy(chip->tof_calib.data, &calib.amsCalibData.calib_data_4x4[0], sizeof(chip->tof_calib.data));
        chip->tof_calib.calib_len = sizeof(chip->tof_calib.data);
        tmf882x_mode_app_set_calib_data(app, &chip->tof_calib);

#ifdef TEST_READ
        /* test read */
        for (i = 0; i < QUADRANT_CALIB_SIZE; i++) {
            dev_info(&chip->client->dev, "%s set calib_data[%d] = %d\n", __func__, i, chip->tof_calib.data[i]);
        }
#endif
    }
    return 0;
}

static int tmf882x_ioctl_handler(
        struct tof_sensor_chip *chip,
        unsigned int cmd, unsigned long arg,
        void __user *p)
{
    int rc = 0;

    if (!chip)
        return -EINVAL;

    switch (cmd) {
        case HWLASER_IOCTL_GET_INFO:
            dev_info(&chip->client->dev, "HWLASER_IOCTL_GET_INFO\n");
            tmf882x_get_info(chip, p);
            break;
        case HWLASER_IOCTL_PERFORM_CALIBRATION:
            dev_info(&chip->client->dev, "HWLASER_IOCTL_PERFORM_CALIBRATION\n");
            rc = tmf882x_perform_calibration(chip, p);
            break;
        case HWLASER_IOCTL_CALIBRATION_DATA:
            dev_info(&chip->client->dev, "HWLASER_IOCTL_CALIBRATION_DATA\n");
            rc = tmf882x_ctrl_calibration_data(chip, p);
            break;
        default:
            dev_err(&chip->client->dev, "cmd not support!!");
            rc = -EINVAL;
            break;
    }

    return rc;
}

static long tof_misc_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
    struct miscdevice *misc = (struct miscdevice *)f->private_data;
    struct tof_sensor_chip *chip =
        container_of(misc, struct tof_sensor_chip, tof_mdev);
    int ret = 0;

    if (f->f_flags & O_NONBLOCK) {
        ret = AMS_MUTEX_TRYLOCK(&chip->lock);
        if(!ret){
            dev_info(&chip->client->dev, "Error, read would block\n");
            return -EWOULDBLOCK;
        }
    } else {
        AMS_MUTEX_LOCK(&chip->lock);
    }

    ret = tmf882x_ioctl_handler(chip, cmd, arg, (void __user *)arg);

    AMS_MUTEX_UNLOCK(&chip->lock);
    return ret;
}

static const struct file_operations tof_miscdev_fops = {
    .owner          = THIS_MODULE,
    .read           = tof_misc_read,
    .poll           = tof_misc_poll,
    .unlocked_ioctl = tof_misc_ioctl,
    .open           = tof_misc_open,
    .release        = tof_misc_release,
    .llseek         = no_llseek,
};

#ifdef CONFIG_TMF882X_QCOM_AP
static int sensors_classdev_enable(struct sensors_classdev *cdev,
                                   unsigned int enable)
{
    struct tof_sensor_chip *chip =
        container_of(cdev, struct tof_sensor_chip, cdev);

    if (enable) {
        chip->tof_idev->open(chip->tof_idev);
    } else {
        chip->tof_idev->close(chip->tof_idev);
    }
    return 0;
}

static int sensors_classdev_poll_delay(struct sensors_classdev *cdev,
                                       unsigned int delay_msec)
{
    struct tof_sensor_chip *chip =
        container_of(cdev, struct tof_sensor_chip, cdev);

    AMS_MUTEX_LOCK(&chip->lock);
    chip->poll_period = delay_msec * 100; // poll period in 100s of usec
    AMS_MUTEX_UNLOCK(&chip->lock);
    return 0;
}
#endif

/*
static void tof882x_init_delaywork_func(struct work_struct *work)
{
    int error;
    struct delayed_work  *init_delayed_work =
        container_of(work, struct delayed_work, work);
    if (init_delayed_work != NULL) {
        struct tof_sensor_chip *chip =
            container_of(init_delayed_work, struct tof_sensor_chip, init_delaywork);
        dev_err(&chip->client->dev, "TMF8820 init start");
        if (chip != NULL) {
            AMS_MUTEX_LOCK(&chip->lock);
            error = tof_open_mode(chip, TMF882X_MODE_APP);
            if (error) {
                dev_err(&chip->client->dev, "Chip init failed.");
            } else {
                // Turn off device until requested
                //tof_poweroff_device(chip);
                //tmf8820_close(&chip->tof);
                dev_err(&chip->client->dev, "TMF8820 init success");
            }
            AMS_MUTEX_UNLOCK(&chip->lock);
        } else {
            dev_err(&chip->client->dev, "chip is NULL");
        }
    }
}
*/
static int tof_probe(struct i2c_client *client,
                     const struct i2c_device_id *idp)
{
    struct tof_sensor_chip *tof_chip;
    int error = 0;
    void *poll_prop_ptr = NULL;
    int i;

    dev_info(&client->dev, "I2C Address: %#04x\n", client->addr);
    tof_chip = devm_kzalloc(&client->dev, sizeof(*tof_chip), GFP_KERNEL);
    if (!tof_chip)
        return -ENOMEM;

    /***** Setup data structures *****/
    mutex_init(&tof_chip->lock);
    client->dev.platform_data = (void *)&tof_pdata;
    tof_chip->client = client;
    tof_chip->pdata = &tof_pdata;
    i2c_set_clientdata(client, tof_chip);
    /***** Firmware sync structure initialization*****/
    init_completion(&tof_chip->ram_patch_in_progress);
    //initialize kfifo for frame output
    INIT_KFIFO(tof_chip->fifo_out);
    init_waitqueue_head(&tof_chip->fifo_wait);
    // init core ToF DCB
    tmf882x_init(&tof_chip->tof, tof_chip);

    AMS_MUTEX_LOCK(&tof_chip->lock);

    //Setup input device
    tof_chip->tof_idev = devm_input_allocate_device(&client->dev);
    if (tof_chip->tof_idev == NULL) {
        dev_err(&client->dev, "Error allocating input_dev.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto input_dev_alloc_err;
    }
    tof_chip->tof_idev->name = tof_chip->pdata->tof_name;
    tof_chip->tof_idev->id.bustype = BUS_I2C;
    input_set_drvdata(tof_chip->tof_idev, tof_chip);
    tof_chip->tof_idev->open = tof_idev_open;
    tof_chip->tof_idev->close = tof_idev_close;
    // add attributes to input device
    tof_chip->tof_idev->dev.groups = tof_groups;
    set_bit(EV_ABS, tof_chip->tof_idev->evbit);
    for (i = 0; i < TMF882X_HIST_NUM_TDC * 2; ++i) {
        // allow input event publishing for any channel (2 ch per TDC)
        input_set_abs_params(tof_chip->tof_idev, i, 0, 0xFFFFFFFF, 0, 0);
    }

    // setup misc char device
    tof_chip->tof_mdev.fops = &tof_miscdev_fops;
    tof_chip->tof_mdev.name = "dtof";
    tof_chip->tof_mdev.minor = MISC_DYNAMIC_MINOR;

    error = tof_get_gpio_config(tof_chip);
    if (error) {
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto gpio_err;
    }

    poll_prop_ptr = (void *)of_get_property(tof_chip->client->dev.of_node,
                                            TOF_PROP_NAME_POLLIO,
                                            NULL);
    tof_chip->poll_period = poll_prop_ptr ? be32_to_cpup(poll_prop_ptr) : 0;
    //tof_chip->poll_period = 330;
    if (tof_chip->poll_period == 0) {
        /*** Use Interrupt I/O instead of polled ***/
        /***** Setup GPIO IRQ handler *****/
        dev_err(&client->dev, "Use Interrupt I/O instead of polled.\n");
        if (tof_chip->pdata->gpiod_interrupt) {
            error = tof_request_irq(tof_chip);
            if (error) {
                dev_err(&client->dev, "Interrupt request Failed.\n");
                AMS_MUTEX_UNLOCK(&tof_chip->lock);
                goto gen_err;
            }
        }

    } else {
        /*** Use Polled I/O instead of interrupt ***/
        dev_err(&client->dev, "Use Polled I/O instead of interrupt.\n");
        tof_chip->poll_irq = kthread_run(tmf882x_poll_irq_thread,
                                         (void *)tof_chip,
                                         "tof-irq_poll");
        if (IS_ERR(tof_chip->poll_irq)) {
            dev_err(&client->dev, "Error starting IRQ polling thread.\n");
            error = PTR_ERR(tof_chip->poll_irq);
            AMS_MUTEX_UNLOCK(&tof_chip->lock);
            goto kthread_start_err;
        }
    }
/*
    error = tof_hard_reset(tof_chip);
    if (error) {
        dev_err(&client->dev, "Chip init failed.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto gen_err;
    }
*/
    tof_chip->rom_version = 0;

    error = sysfs_create_groups(&client->dev.kobj, tof_groups);
    if (error) {
        dev_err(&client->dev, "Error creating sysfs attribute group.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto gen_err;
    }

    error = input_register_device(tof_chip->tof_idev);
    if (error) {
        dev_err(&client->dev, "Error registering input_dev.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto sysfs_err;
    }

    error = misc_register(&tof_chip->tof_mdev);
    if (error) {
        dev_err(&client->dev, "Error registering misc_dev.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto misc_reg_err;
    }

#ifdef CONFIG_TMF882X_QCOM_AP
    tof_chip->cdev = sensors_cdev;
    tof_chip->cdev.sensors_enable = sensors_classdev_enable;
    tof_chip->cdev.sensors_poll_delay = sensors_classdev_poll_delay;
    error = sensors_classdev_register(&tof_chip->tof_idev->dev,
                                      &tof_chip->cdev);
    if (error) {
        dev_err(&client->dev, "Error registering sensors_classdev.\n");
        AMS_MUTEX_UNLOCK(&tof_chip->lock);
        goto classdev_reg_err;
    }
#endif

    // Turn off device until requested
    tof_poweroff_device(tof_chip);

    AMS_MUTEX_UNLOCK(&tof_chip->lock);

//    INIT_DELAYED_WORK(&tof_chip->init_delaywork, tof882x_init_delaywork_func);
//    schedule_delayed_work(&tof_chip->init_delaywork, msecs_to_jiffies(5000));
    dev_info(&client->dev, "Probe ok.\n");
    return 0;

    /***** Failure case(s), unwind and return error *****/
#ifdef CONFIG_TMF882X_QCOM_AP
classdev_reg_err:
    misc_deregister(&tof_chip->tof_mdev);
#endif
misc_reg_err:
    input_unregister_device(tof_chip->tof_idev);
sysfs_err:
    sysfs_remove_groups(&client->dev.kobj, tof_groups);
gen_err:
    if (tof_chip->poll_period != 0) {
        (void)kthread_stop(tof_chip->poll_irq);
    }
gpio_err:
    if (tof_chip->pdata->gpiod_enable)
        (void) gpiod_direction_output(tof_chip->pdata->gpiod_enable, 0);
kthread_start_err:
input_dev_alloc_err:
    i2c_set_clientdata(client, NULL);
    dev_info(&client->dev, "Probe failed.\n");
    return error;
}

static int tof_remove(struct i2c_client *client)
{
    struct tof_sensor_chip *chip = i2c_get_clientdata(client);

    (void) tof_poweroff_device(chip);
    chip->driver_remove = true;
    wake_up_all(&chip->fifo_wait);

#ifdef CONFIG_TMF882X_QCOM_AP
    sensors_classdev_unregister(&chip->cdev);
#endif

    if (chip->pdata->gpiod_interrupt) {
        devm_gpiod_put(&client->dev, chip->pdata->gpiod_interrupt);
    }

    if (chip->pdata->gpiod_enable) {
        devm_gpiod_put(&client->dev, chip->pdata->gpiod_enable);
    }

    if (chip->poll_period != 0) {
        (void)kthread_stop(chip->poll_irq);
    } else {
        devm_free_irq(&client->dev, client->irq, chip);
    }

    misc_deregister(&chip->tof_mdev);
    input_unregister_device(chip->tof_idev);
    sysfs_remove_groups(&client->dev.kobj,
                        (const struct attribute_group **)&tof_groups);

    i2c_set_clientdata(client, NULL);
//    cancel_delayed_work_sync(&chip->init_delaywork);
    dev_info(&client->dev, "%s\n", __func__);
    return 0;
}

static struct i2c_device_id tof_idtable[] = {
    { TMF882X_NAME, 0 },
    {}
};
MODULE_DEVICE_TABLE(i2c, tof_idtable);

static const struct of_device_id tof_of_match[] = {
    { .compatible = "ams,tmf882x" },
    { }
};
MODULE_DEVICE_TABLE(of, tof_of_match);

static struct i2c_driver tof_driver = {
    .driver = {
        .name = "ams-tof",
        .of_match_table = of_match_ptr(tof_of_match),
    },
    .id_table = tof_idtable,
    .probe = tof_probe,
    .remove = tof_remove,
};

module_i2c_driver(tof_driver);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("AMS TMF882X ToF sensor driver");
MODULE_VERSION(TMF882X_MODULE_VER);
