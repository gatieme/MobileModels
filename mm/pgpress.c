/*
 * Copyright (c) Honor Technologies Co., Ltd. 2022. All rights reserved.
 * Description: According to workingset refault, add pgpress for I/O performence.
 * Created by yangpanfei
 * Create:  2022-07-14
 */
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/vmstat.h>
#include <linux/time.h>
#include <linux/magic.h>
#include <linux/swap.h>
#include <linux/backing-dev.h>
#include <linux/pgpress.h>
#include <linux/types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/blk-cgroup.h>
#ifdef CONFIG_HN_QOS_THREAD
#include <chipset_common/hwqos/hwqos_common.h>
#endif

#define BTOKB(n) ((n) >> 10)
#define BTOMB(n) ((n) >> 20)
#define KBTOMB(n) ((n) >> 10)
#define SECTOKB(n) ((n) >> 1)
#ifndef EROFS_SUPER_MAGIC_V1
#define EROFS_SUPER_MAGIC_V1	0xE0F5E1E2
#endif
#define PG_S_PER_MS			1000

/* swappiness windows config */
#define SWAPPNIESS_MAX			140
#define DIRECT_SWAPPNIESS_MAX	60
#define SWAPPNIESS_STEP			10

/* feature switch*/
#define FEA_RA_ADAPT		(1 << 0)
#define FEA_SW_ADAPT		(1 << 1)
#define FEA_MAX			(1 << 7)
#define PATH_MAX_CHAR		256

/*mem info*/
#define PAGETOKB(x) ((x) << (PAGE_SHIFT - 10))
#define MEMSIZE_8 7000000
#define MEMSIZE_12	10000000

static u8 g_feature_on = FEA_RA_ADAPT | FEA_SW_ADAPT;
static unsigned int g_critical_memory = 1200;
static unsigned int default_pgpress_level = 5;
static unsigned int default_exempt_level = 10;
static unsigned int default_min_window = 32;
static unsigned int quota_ratio = 60;

static struct pgpress_stats g_pgpress = {0};
static DEFINE_SPINLOCK(g_pglock);

static inline bool check_fs_valid(struct inode *inode)
{
	return inode && inode->i_sb;
}
enum pg_fs_type pg_get_fs_type(struct inode *inode)
{
	unsigned long magic;
	if (!check_fs_valid(inode))
		return FS_TYPE_INVALID;
	magic = inode->i_sb->s_magic;
	switch (magic) {
	case F2FS_SUPER_MAGIC:
		return FS_TYPE_F2FS;
	case EROFS_SUPER_MAGIC_V1:
		return FS_TYPE_EROFS;
	case EXT4_SUPER_MAGIC:
		return FS_TYPE_EXT4;
	default:
		return FS_TYPE_OTHER;
	}
}
/*
 * update pgpress from refault behavior.
 * pgpress = Δrefault/file/Δtime
 */
void refault_monitor(void)
{
	unsigned int time = 0;
	unsigned long pgfile = global_node_page_state(NR_ACTIVE_FILE) +
		global_node_page_state(NR_INACTIVE_FILE);

	if (!g_feature_on)
		return;
	spin_lock(&g_pglock);
	if (!g_pgpress.quota)
		goto init;
	g_pgpress.quota--;
	/* Prevent a high and unsuited pgpress value */
	if (g_pgpress.pgpress >= default_pgpress_level &&
		time_after(jiffies, g_pgpress.start_time + HZ))
		g_pgpress.pgpress = 0;
	/* when quota is zero, update pgpress and reinit */
	if (!g_pgpress.quota) {
		time = jiffies_to_msecs(jiffies - g_pgpress.start_time);
		if (likely(time > 0))
			g_pgpress.pgpress = default_pgpress_level *
							PG_S_PER_MS / time;
init:
		/* init quota = (100/quoota_ratio)% * file and record the init time */
		g_pgpress.quota = pgfile / quota_ratio;
		g_pgpress.start_time = jiffies;
	}
	spin_unlock(&g_pglock);
}

bool is_vip_task(struct task_struct *task)
{
#ifdef CONFIG_FS_TOPIO_TRACE
	if (blk_is_topio())
		return true;
#endif

#ifdef CONFIG_HN_VIP_THREAD
	if(task->static_vip)
		return true;
#endif
	return false;
}

int get_pgpress(void)
{
	return g_pgpress.pgpress;
}
/*
 * lowmem: if lowmem is true, only return pgpress when lowmem
 * exempt: if exempt is true, top task exempt few press
 */
int get_current_pgpress(bool lowmem, bool exempt)
{
	unsigned long pgfile;
	unsigned long freeram;
	int pgpress = 0;

	pgfile = global_node_page_state(NR_ACTIVE_FILE) +
		global_node_page_state(NR_INACTIVE_FILE);
	freeram = global_zone_page_state(NR_FREE_PAGES);

	if(!lowmem || pgfile + freeram <=
		(g_critical_memory * SZ_1M >> PAGE_SHIFT))
		pgpress = g_pgpress.pgpress - (!!exempt) *
			default_exempt_level * is_vip_task(current);

	return max(pgpress, 0);
}

#ifdef CONFIG_HONOR_PGPRESS_DEBUG
static void readahead_switch_trace(struct file *file,
					unsigned int ra_pages_org,
					unsigned int ra_page_new,
					bool buffer, int pgpress)
{
	char *filepath;
	char buf[PATH_MAX_CHAR] = {0};
	struct inode *inode = file->f_mapping->host;

	filepath = d_path(&file->f_path, buf, PATH_MAX_CHAR);
	if (IS_ERR_OR_NULL(filepath))
		return;
	printk(KERN_ERR "[PGPRESS]:nid:%lx,file: %s,buffer=%d "
		"ra_pages=%d to %d, fstype=%d,pgpress=%d\n",
		inode->i_ino, filepath, buffer,
		ra_pages_org, ra_page_new, pg_get_fs_type(inode), pgpress);
}
#endif

void readahead_adaptive(struct file *file, struct vm_fault *vmf, bool buffer)
{
	int pgpress = 0;
	unsigned int ra_pages;
	struct file_ra_state *ra = &file->f_ra;
	struct inode *inode = file->f_mapping->host;
	unsigned int ra_pages_org = inode_to_bdi(inode)->ra_pages;
	unsigned int ra_min = default_min_window << buffer;

	if (!(g_feature_on & FEA_RA_ADAPT))
		return;

	if(pg_get_fs_type(inode) > FS_TYPE_OTHER || ra_pages_org <= ra_min || ra->ra_pages <= ra_min)
		return;

	pgpress = get_current_pgpress(true, true);
	if (pgpress <= 0) {
		ra->ra_pages = ra_pages_org;
		return;
	}

	pgpress /= (default_pgpress_level << buffer);

	ra_pages = ra_pages_org >> pgpress;
	if(vmf && vmf->vma &&
		vmf->vma->vm_flags & VM_EXEC)
		ra_pages /= 2;
	ra->ra_pages = max(ra_pages,  ra_min);
#ifdef CONFIG_HONOR_PGPRESS_DEBUG
	readahead_switch_trace(file, ra_pages_org,
					ra->ra_pages, buffer, pgpress);
#endif
	return;
}
EXPORT_SYMBOL(readahead_adaptive);

int swappniess_adaptive(int swappiness)
{
	int pgpress = 0;
	int swappiness_adjust = swappiness;
	int swappiness_max = max(swappiness, SWAPPNIESS_MAX);


	if (!(g_feature_on & FEA_SW_ADAPT) ||
			swappiness >= SWAPPNIESS_MAX)
		goto out;

	pgpress = get_current_pgpress(false, true);
	pgpress /= (default_pgpress_level << 1);

	if(pgpress < 1)
		goto out;

	swappiness_adjust += pgpress * SWAPPNIESS_STEP;
#ifdef CONFIG_DIRECT_SWAPPINESS
	if (!current_is_kswapd())
		swappiness_max = max(swappiness, DIRECT_SWAPPNIESS_MAX);
#endif

	swappiness_adjust = min(swappiness_adjust, swappiness_max);
out:
	return swappiness_adjust;

}

#define BASE_NUM 10
static int enable_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", g_feature_on);
	return 0;
}

static int enable_open(struct inode *inode, struct file *file)
{
	return single_open(file, enable_show, inode->i_private);
}
static ssize_t enable_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret, value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	g_feature_on = (u8)value;

	return count;
}

static int critical_memory_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", g_critical_memory);
	return 0;
}

static int critical_memory_open(struct inode *inode, struct file *file)
{
	return single_open(file, critical_memory_show, inode->i_private);
}
static ssize_t critical_memory_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret;
	unsigned int value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	g_critical_memory = value;

	return count;
}

/*adjust pgpress default level*/
static int default_level_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", default_pgpress_level);
	return 0;
}

static int default_level_open(struct inode *inode, struct file *file)
{
	return single_open(file, default_level_show, inode->i_private);
}

static ssize_t default_level_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret;
	unsigned int value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	default_pgpress_level = value;

	return count;
}

/*adjust pgpress exempt level*/
static int exempt_level_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", default_exempt_level);
	return 0;
}

static int exempt_level_open(struct inode *inode, struct file *file)
{
	return single_open(file, exempt_level_show, inode->i_private);
}

static ssize_t exempt_level_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret;
	unsigned int value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	default_exempt_level = value;

	return count;
}

/*adjust ra min window*/
static int min_window_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", default_min_window);
	return 0;
}

static int min_window_open(struct inode *inode, struct file *file)
{
	return single_open(file, min_window_show, inode->i_private);
}

static ssize_t min_window_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret;
	unsigned int value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	default_min_window = value;

	return count;
}


/*adjust quoota_ratio*/
static int quota_ratio_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", quota_ratio);
	return 0;
}

static int quota_ratio_open(struct inode *inode, struct file *file)
{
	return single_open(file, quota_ratio_show, inode->i_private);
}

static ssize_t quota_ratio_write(struct file *file, const char *buf,
	size_t count, loff_t *pos)
{
	int ret;
	unsigned int value;

	ret = kstrtoint_from_user(buf, count, BASE_NUM, &value);
	if (ret)
		return ret;
	quota_ratio = value;

	return count;
}

//stat
static int cachestat_show(struct seq_file *m, void *v)
{
	seq_printf(m, "file: %lu free: %lu pgpress:%lu%%\n",
				global_node_page_state(NR_ACTIVE_FILE) +
				global_node_page_state(NR_INACTIVE_FILE),
				global_zone_page_state(NR_FREE_PAGES),
				g_pgpress.pgpress);
	return 0;
}

static int cachestat_open(struct inode *inode, struct file *file)
{
	return single_open(file, cachestat_show, inode->i_private);
}

static const struct proc_ops enable_fops = {
	.proc_open = enable_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = enable_write,
};

static const struct proc_ops critical_memory_fops = {
	.proc_open = critical_memory_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = critical_memory_write,
};

static const struct proc_ops cachestat_fops = {
	.proc_open = cachestat_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static const struct proc_ops default_level_fops = {
	.proc_open = default_level_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = default_level_write,
};

static const struct proc_ops exempt_level_fops = {
	.proc_open = exempt_level_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = exempt_level_write,
};

static const struct proc_ops min_window_fops = {
	.proc_open = min_window_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = min_window_write,
};

static const struct proc_ops quota_ratio_fops = {
	.proc_open = quota_ratio_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = quota_ratio_write,
};

static const struct pgcache_proc_node pgcache_proc_list[] = {
	{"enable", S_IRUGO | S_IWUGO, &enable_fops},
	{"critical_memory", S_IRUGO | S_IWUGO, &critical_memory_fops},
	{"stat", S_IRUGO, &cachestat_fops},
	{"pg_level_default", S_IRUGO | S_IWUGO, &default_level_fops},
	{"pg_level_exempt", S_IRUGO | S_IWUGO, &exempt_level_fops},
	{"min_ra_window", S_IRUGO | S_IWUGO, &min_window_fops},
	{"quota_ratio", S_IRUGO | S_IWUGO, &quota_ratio_fops},
};

static void args_init(void)
{
	__kernel_ulong_t totalram = 0;
	unsigned long totalram_kb = 0;

	totalram = totalram_pages();
	totalram_kb = PAGETOKB(totalram);
	printk(KERN_ERR "[PGPRESS]:MemTotal= %8lu kB\n",totalram_kb);

	if (totalram_kb == 0)
		return;

	if (totalram_kb > MEMSIZE_12) {
		g_critical_memory = 1800;
		default_min_window = 2;
		quota_ratio = 20;
	} else if (totalram_kb > MEMSIZE_8) {
		g_critical_memory = 1100;
		default_min_window = 2;
		quota_ratio = 20;
	} else {
		g_critical_memory = 1100;
		default_min_window = 8;
		quota_ratio = 20;
	}
}

static int __init pgpress_init(void)
{
	struct proc_dir_entry *prEntry;
	struct proc_dir_entry *pgpress_dir;
	int i, num;

	args_init();
	pgpress_dir = proc_mkdir("pgpress", NULL);

	if (!pgpress_dir) {
		pr_info("[%s]: failed to create /proc/pgpress\n",
			__func__);
		return -1;
	}

	num = ARRAY_SIZE(pgcache_proc_list);
	for (i = 0; i < num; i++) {
		prEntry = proc_create(pgcache_proc_list[i].name,
			pgcache_proc_list[i].mode, pgpress_dir,
			pgcache_proc_list[i].proc_fops);
		if (prEntry)
			continue;
		pr_info("[%s]: failed to create /proc/pgpress/%s\n",
			__func__, pgcache_proc_list[i].name);
	}
	return 0;
}

static void __exit pgpress_exit(void)
{
	remove_proc_entry("proc/pgpress/enable", NULL);
	remove_proc_entry("proc/pgpress/stat", NULL);
	remove_proc_entry("proc/pgpress/critical_memory", NULL);
	remove_proc_entry("proc/pgpress/pg_level_default", NULL);
	remove_proc_entry("proc/pgpress/pg_level_exempt", NULL);
	remove_proc_entry("proc/pgpress/min_ra_window", NULL);
	remove_proc_entry("proc/pgpress/quota_ratio", NULL);
	remove_proc_entry("proc/pgpress", NULL);
}

module_init(pgpress_init);
module_exit(pgpress_exit);
MODULE_LICENSE("GPL");
