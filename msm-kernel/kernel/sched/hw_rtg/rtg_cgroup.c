/*
 * rtg_cgroup.c
 *
 * Default cgroup load tracking for RTG
 *
 * Copyright (c) 2020-2021 Huawei Technologies Co., Ltd.
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
#ifdef CONFIG_HW_CGROUP_RTG

static
void update_best_cluster(struct related_thread_group *grp,
				   u64 demand, bool boost)
{
	if (boost) {
		/*
		 * since we are in boost, we can keep grp on min, the boosts
		 * will ensure tasks get to bigs
		 */
		grp->skip_min = false;
		return;
	}

	if (is_suh_max())
		demand = sched_group_upmigrate;

	if (!grp->skip_min) {
		if (demand >= sched_group_upmigrate)
			grp->skip_min = true;
		return;
	}
	if (demand < sched_group_downmigrate) {
		if (!sysctl_sched_coloc_downmigrate_ns ||
				(grp->last_update - grp->start_ts) <
				sysctl_sched_hyst_min_coloc_ns) {
			grp->downmigrate_ts = 0;
			grp->skip_min = false;
			return;
		}
		if (!grp->downmigrate_ts) {
			grp->downmigrate_ts = grp->last_update;
			return;
		}
		if (grp->last_update - grp->downmigrate_ts >
				sysctl_sched_coloc_downmigrate_ns) {
			grp->downmigrate_ts = 0;
			grp->skip_min = false;
		}
	} else if (grp->downmigrate_ts) {
		grp->downmigrate_ts = 0;
	}
}

void _do_update_preferred_cluster(struct related_thread_group *grp)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct walt_task_struct *wts = NULL;
#endif
	struct task_struct *p = NULL;
	u64 combined_demand = 0;
	bool group_boost = false;
	u64 wallclock;
	bool prev_skip_min = grp->skip_min;

	if (grp->id != DEFAULT_CGROUP_COLOC_ID)
		return;

	if (list_empty(&grp->tasks)) {
		grp->skip_min = false;
		goto out;
	}

	if (!hmp_capable()) {
		grp->skip_min = false;
		goto out;
	}

	wallclock = walt_ktime_clock();

	/*
	 * wakeup of two or more related tasks could race with each other and
	 * could result in multiple calls to _do_update_preferred_cluster being issued
	 * at same time. Avoid overhead in such cases of rechecking preferred
	 * cluster
	 */
	if (wallclock - grp->last_update < sched_ravg_window / 10)
		return;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	list_for_each_entry(wts, &grp->tasks, grp_list) {
		p = wts_to_ts(wts);
#else
	list_for_each_entry(p, &grp->tasks, grp_list) {
#endif
		if (task_boost_policy(p) == SCHED_BOOST_ON_BIG) {
			group_boost = true;
			break;
		}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0))
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		if (wts->mark_start < wallclock -
#else
		if (p->wts.mark_start < wallclock -
#endif
#else
		if (p->ravg.mark_start < wallclock -
#endif
		    (sched_ravg_window * sched_ravg_hist_size))
			continue;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0))
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		combined_demand += wts->coloc_demand;
#else
		combined_demand += p->wts.coloc_demand;
#endif
#else
		combined_demand += p->ravg.coloc_demand;
#endif
		if (!trace_cgroup_rtg_debug_enabled()) {
			if (combined_demand > sched_group_upmigrate)
				break;
		}
	}

	grp->last_update = wallclock;
	update_best_cluster(grp, combined_demand, group_boost);
out:
	trace_cgroup_rtg_debug(0, "combined_demand", combined_demand);
	trace_cgroup_rtg_debug(0, "skip_min", grp->skip_min);
	if (grp->id == DEFAULT_CGROUP_COLOC_ID
	    && grp->skip_min != prev_skip_min) {
		if (grp->skip_min)
			grp->start_ts = wallclock;
		else
			grp->start_ts = 0;
		sched_update_hyst_times();
	}
}

void do_update_preferred_cluster(struct related_thread_group *grp)
{
	raw_spin_lock(&grp->lock);
	_do_update_preferred_cluster(grp);
	raw_spin_unlock(&grp->lock);
}

int update_preferred_cluster(struct related_thread_group *grp,
		struct task_struct *p, u32 old_load, bool from_tick)
{
	u32 new_load = task_load(p);

	if (!grp || grp->id != DEFAULT_CGROUP_COLOC_ID)
		return 0;

	if (unlikely(from_tick && is_suh_max()))
		return 1;

	/*
	 * Update if task's load has changed significantly or a complete window
	 * has passed since we last updated preference
	 */
	if (abs(new_load - old_load) > sched_ravg_window / 4 ||
		walt_ktime_clock() - grp->last_update > sched_ravg_window)
		return 1;

	return 0;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
int preferred_skip_min(struct sched_cluster *cluster, struct task_struct *p)
{
	struct related_thread_group *grp = NULL;
	int rc = 1;

	rcu_read_lock();

	grp = task_related_thread_group(p);
	if (grp && grp->id == DEFAULT_CGROUP_COLOC_ID)
		rc = (sched_cluster[(int)grp->skip_min] == cluster ||
		      cpumask_subset(&cluster->cpus, &asym_cap_sibling_cpus));

	rcu_read_unlock();
	return rc;
}
#endif

static void update_cgroup_rtg_tick(struct related_thread_group *grp,
				   struct rtg_tick_info *tick_info)
{
	if (!tick_info)
		return;

	if (update_preferred_cluster(grp, tick_info->curr, tick_info->old_load, true))
		do_update_preferred_cluster(grp);
}

const struct rtg_class cgroup_rtg_class = {
	.sched_update_rtg_tick = update_cgroup_rtg_tick,
};

u64 get_rtgb_active_time(void)
{
	struct related_thread_group *grp;
	u64 now = walt_ktime_clock();

	grp = lookup_related_thread_group(DEFAULT_CGROUP_COLOC_ID);

	if (grp && grp->skip_min && grp->start_ts)
		return now - grp->start_ts;

	return 0;
}

bool walt_get_rtg_status(struct task_struct *p)
{
	struct related_thread_group *grp;
	bool ret = false;

	rcu_read_lock();

	grp = task_related_thread_group(p);
	if (grp)
		ret = grp->skip_min;

	rcu_read_unlock();

	return ret;
}

void add_new_task_to_grp(struct task_struct *new)
{
	struct related_thread_group *grp = NULL;
	struct related_thread_group *curr_grp = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	struct walt_task_struct *wts = (struct walt_task_struct *) new->android_vendor_data1;
#endif
	unsigned long flag;

#if IS_ENABLED(CONFIG_UCLAMP_TASK_GROUP) && !IS_ENABLED(CONFIG_SCHED_TUNE)
	/*
	 * If the task does not belong to colocated schedtune
	 * cgroup, nothing to do. We are checking this without
	 * lock. Even if there is a race, it will be added
	 * to the co-located cgroup via cgroup attach.
	 */
	if (!uclamp_task_colocated(new))
		return;
#else
	struct task_struct *leader = new->group_leader;
	unsigned int leader_grp_id = sched_get_group_id(leader);

	if (leader_grp_id != DEFAULT_CGROUP_COLOC_ID)
		return;

	if (thread_group_leader(new))
		return;
	if (leader_grp_id == DEFAULT_CGROUP_COLOC_ID) {
		if (!same_schedtune(new, leader))
			return;
	}
#endif

#if IS_ENABLED(CONFIG_UCLAMP_TASK_GROUP) && !IS_ENABLED(CONFIG_SCHED_TUNE)
	grp = lookup_related_thread_group(DEFAULT_CGROUP_COLOC_ID);
#else
	rcu_read_lock();
	grp = task_related_thread_group(leader);
	rcu_read_unlock();
#endif
	raw_spin_lock_irqsave(&new->pi_lock, flag);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	curr_grp = wts->grp;
#else
	curr_grp = new->grp;
#endif
#if IS_ENABLED(CONFIG_UCLAMP_TASK_GROUP) && !IS_ENABLED(CONFIG_SCHED_TUNE)
	/*
	 * It's possible that someone already added the new task to the
	 * group. or it might have taken out from the colocated schedtune
	 * cgroup. check these conditions under lock.
	 */
	if (!uclamp_task_colocated(new) || curr_grp) {
		raw_spin_unlock_irqrestore(&new->pi_lock, flag);
		return;
	}
#else
	/*
	 * It's possible that someone already added the new task to the
	 * group. A leader's thread group is updated prior to calling
	 * this function. It's also possible that the leader has exited
	 * the group. In either case, there is nothing else to do.
	 */
	if (!grp || curr_grp) {
		raw_spin_unlock_irqrestore(&new->pi_lock, flag);
		return;
	}
#endif

	raw_spin_lock(&grp->lock);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	rcu_assign_pointer(wts->grp, grp);
	list_add(&wts->grp_list, &grp->tasks);
#else
	rcu_assign_pointer(new->grp, grp);
	list_add(&new->grp_list, &grp->tasks);
#endif

	raw_spin_unlock(&grp->lock);
	raw_spin_unlock_irqrestore(&new->pi_lock, flag);
}

/*
 * We create a default colocation group at boot. There is no need to
 * synchronize tasks between cgroups at creation time because the
 * correct cgroup hierarchy is not available at boot. Therefore cgroup
 * colocation is turned off by default even though the colocation group
 * itself has been allocated. Furthermore this colocation group cannot
 * be destroyted once it has been created. All of this has been as part
 * of runtime optimizations.
 *
 * The job of synchronizing tasks to the colocation group is done when
 * the colocation flag in the cgroup is turned on.
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
int create_default_coloc_group(void)
#else
static int __init create_default_coloc_group(void)
#endif
{
	struct related_thread_group *grp = NULL;
	unsigned long flags;

	grp = lookup_related_thread_group(DEFAULT_CGROUP_COLOC_ID);
	write_lock_irqsave(&related_thread_group_lock, flags);
	grp->rtg_class = &cgroup_rtg_class;
	list_add(&grp->list, &active_related_thread_groups);
	write_unlock_irqrestore(&related_thread_group_lock, flags);

	return 0;
}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0))
late_initcall(create_default_coloc_group);
#endif

int sync_cgroup_colocation(struct task_struct *p, bool insert)
{
	unsigned int grp_id = insert ? DEFAULT_CGROUP_COLOC_ID : 0;
	unsigned int old_grp_id;
	if (p) {
		old_grp_id = sched_get_group_id(p);
		/*
		 * If the task is already in a group which is not DEFAULT_CGROUP_COLOC_ID,
		 * we should not change the group id during switch to background.
		 */
		if ((old_grp_id != DEFAULT_CGROUP_COLOC_ID) && (grp_id == 0))
			return 0;
	}

	return __sched_set_group_id(p, grp_id);
}

#endif
