/*
 * slub_track.c
 *
 * Copyright(C) 2022 Honor Device Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/string.h>
#include <linux/spinlock_types.h>
#include <linux/err.h>
#include <linux/vmalloc.h>
#include <linux/mutex.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <trace/hooks/mm.h>
#include <linux/jhash.h>
#include <../mm/slab.h>
#include "slub_track.h"
#include "securec.h"

#define invalid_slub_type(type) (type != SLUB_ALLOC && type != SLUB_FREE)
#define SLUB_RINGBUF_LEN   SZ_8K
#define SLUB_RINGBUF_HALF   2
#define SLUB_STACK_SAVE_SKIP   1

struct slub_rb_node {
	struct rb_node node;
	struct stack_track slub_track;
	atomic_t ref;
};

struct slub_ring_buf {
	int type;
	struct stack_track *stack_buf;
	spinlock_t lock;
	size_t size;
	unsigned long in;
	unsigned long out;
};

struct slub_track {
	int type;
	wait_queue_head_t slub_wait;
	struct mutex slub_mutex;
	struct task_struct *slub_ktrackd;
	struct rb_root slubrb;
};

static int slub_track_flag;
static struct slub_track slub_tracks[NR_SLUB_ID];
static struct slub_ring_buf srb_array[NR_SLUB_ID];
static struct kmem_cache *slub_track_cache;

static inline unsigned long get_ring_buf_len(struct slub_ring_buf *srb)
{
	return (srb->in - srb->out);
}

static inline int ring_buf_is_full(struct slub_ring_buf *srb)
{
	return (get_ring_buf_len(srb) == srb->size);
}

static inline int ring_buf_is_half(struct slub_ring_buf *srb)
{
	return (get_ring_buf_len(srb) >= (srb->size / SLUB_RINGBUF_HALF));
}

static inline int ring_buf_is_empty(struct slub_ring_buf *srb)
{
	return (srb->in == srb->out);
}

static inline void __set_stack_to_buf(struct slub_ring_buf *srb, struct stack_track *slub_stack)
{
	errno_t err = EOK;
	size_t idx = srb->in & (srb->size - 1);

	if (ring_buf_is_full(srb))
		return;
	if (unlikely(idx >= srb->size))
		idx = 0;
	err = memmove_s(srb->stack_buf + idx, sizeof(struct stack_track), slub_stack, sizeof(struct stack_track));
	if (err == EOK) {
		srb->in++;
	}
}

static inline int __get_stack_from_buf(
	struct slub_ring_buf *srb, struct stack_track *slub_stack)
{
	errno_t err = EOK;
	size_t idx = srb->out & (srb->size - 1);

	if (ring_buf_is_empty(srb))
		return -ENOSPC;
	if (unlikely(idx >= srb->size))
		idx = 0;
	err = memmove_s(slub_stack, sizeof(struct stack_track), srb->stack_buf + idx, sizeof(struct stack_track));
	if (err == EOK) {
		srb->out++;
	}

	return err;
}

static inline void set_stack_to_buf(struct slub_ring_buf *srb,
	struct stack_track *slub_stack, int type)
{
	if (slub_track_flag) {
		__set_stack_to_buf(srb, slub_stack);
		if (ring_buf_is_half(srb)) {
			wake_up(&slub_tracks[type].slub_wait);
		}
	}
}

inline void get_slub_stacks(struct stack_track *slub_stack, unsigned long caller) {
	if (slub_stack == NULL) {
		pr_err("slub_stack is null");
		return;
	}
	slub_stack->caller = caller;
#ifdef CONFIG_STACKTRACE
	slub_stack->stack_len = stack_trace_save(slub_stack->addrs, MM_TRACK_STACK_DEPTH, SLUB_STACK_SAVE_SKIP);
	slub_stack->stack_hash = jhash2((u32 *)slub_stack->addrs, slub_stack->stack_len *
		sizeof(unsigned long) / sizeof(u32), 0xface);
#else
	slub_stack->stack_hash = caller;
#endif
}

inline void set_alloc_track(unsigned long caller)
{
	unsigned long flags;
	struct slub_ring_buf *srb = &srb_array[SLUB_ALLOC];
	struct stack_track slub_stack_track;

	if (!slub_track_flag)
		return;
	get_slub_stacks(&slub_stack_track, caller);
	spin_lock_irqsave(&srb->lock, flags);
	set_stack_to_buf(srb, &slub_stack_track, SLUB_ALLOC);
	spin_unlock_irqrestore(&srb->lock, flags);
}

static void slab_alloc_node_hook(void *data, void *object, unsigned long addr,
	struct kmem_cache *s)
{
	if (likely(object) && (s->flags & SLAB_MM_TRACK)) {
		set_alloc_track(addr);
	}
}

inline void set_free_track(unsigned long caller)
{
	unsigned long flags;
	struct slub_ring_buf *srb = &srb_array[SLUB_FREE];
	struct stack_track slub_stack_track;

	if (!slub_track_flag)
		return;
	get_slub_stacks(&slub_stack_track, caller);
	spin_lock_irqsave(&srb->lock, flags);
	set_stack_to_buf(srb, &slub_stack_track, SLUB_FREE);
	spin_unlock_irqrestore(&srb->lock, flags);
}

static void slab_free_hook(void *data, unsigned long addr, struct kmem_cache *s)
{
#ifdef CONFIG_HN_MM_TRACK
	if (s->flags & SLAB_MM_TRACK) {
		set_free_track(addr);
	}
#endif
}

static void slub_add_node(struct stack_track *slub_stack, int type)
{
	struct rb_node **p = &slub_tracks[type].slubrb.rb_node;
	struct rb_node *parent = NULL;
	struct slub_rb_node *entry = NULL;
	struct slub_rb_node *rbnode = NULL;
	errno_t err = EOK;

	while (*p) {
		parent = *p;
		entry = rb_entry(parent, struct slub_rb_node, node);

		if (slub_stack->stack_hash < entry->slub_track.stack_hash) {
			p = &(*p)->rb_left;
		} else if (slub_stack->stack_hash > entry->slub_track.stack_hash) {
			p = &(*p)->rb_right;
		} else {
			atomic_inc(&entry->ref);
			return;
		}
	}
	rbnode = kmem_cache_alloc(slub_track_cache, GFP_ATOMIC);
	if (rbnode) {
		err = memmove_s(&rbnode->slub_track, sizeof(struct stack_track), slub_stack, sizeof(struct stack_track));
		if (err == EOK) {
			atomic_set(&rbnode->ref, 1);
			rb_link_node(&rbnode->node, parent, p);
			rb_insert_color(&rbnode->node, &slub_tracks[type].slubrb);
		}
	}
}

static void slub_del_node(struct slub_rb_node *rbnode, int type)
{
	rb_erase(&rbnode->node, &slub_tracks[type].slubrb);
	kmem_cache_free(slub_track_cache, rbnode);
}

static size_t slub_read_node(struct mm_stack_info *buf, const size_t len, int type)
{
	struct rb_node *n = NULL;
	struct slub_rb_node *vnode = NULL;
	size_t length = len;
	size_t cnt = 0;
	errno_t err = EOK;

	if (!buf)
		return 0;

	mutex_lock(&slub_tracks[type].slub_mutex);
	n = rb_first(&slub_tracks[type].slubrb);
	while (n && (length--)) {
		vnode = rb_entry(n, struct slub_rb_node, node);
		err = memmove_s(&(buf + cnt)->stack_entry, sizeof(struct stack_track), &vnode->slub_track,
				sizeof(struct stack_track));
		if (err == EOK) {
			atomic_set(&((buf + cnt)->ref), atomic_read(&vnode->ref));
		}
		n = rb_next(n);
		slub_del_node(vnode, type);
		cnt++;
	}
	mutex_unlock(&slub_tracks[type].slub_mutex);
	return cnt;
}

static void __slub_fetch_node(struct slub_ring_buf *srb, int type)
{
	struct stack_track slub_stack;
	int ret;

	ret = __get_stack_from_buf(srb, &slub_stack);
	if (ret)
		return;
	slub_add_node(&slub_stack, type);
}

static void slub_fetch_node(int slubtype)
{
	unsigned long i, len, flags;
	struct slub_ring_buf *srb = &srb_array[slubtype];

	spin_lock_irqsave(&srb->lock, flags);
	len = get_ring_buf_len(srb);
	for (i = 0; i < len; i++)
		__slub_fetch_node(srb, slubtype);
	spin_unlock_irqrestore(&srb->lock, flags);
}

static int kslubtrackd(void *p)
{
	DEFINE_WAIT(wait);
	int type;
	struct slub_track *track = (struct slub_track *)p;

	type = track->type;
	while (!kthread_should_stop()) {
		prepare_to_wait(&slub_tracks[type].slub_wait,
			&wait, TASK_UNINTERRUPTIBLE);
		schedule();
		finish_wait(&slub_tracks[type].slub_wait, &wait);
		mutex_lock(&slub_tracks[type].slub_mutex);
		if (slub_track_flag)
			slub_fetch_node(type);
		mutex_unlock(&slub_tracks[type].slub_mutex);
	};
	return 0;
}

static inline void slub_build_rb_tree(int type)
{
	slub_tracks[type].slubrb = RB_ROOT;
}

static long slub_create_track(int type)
{
	long err;

	init_waitqueue_head(&slub_tracks[type].slub_wait);
	mutex_init(&slub_tracks[type].slub_mutex);
	slub_build_rb_tree(type);
	slub_tracks[type].type = type;
	slub_tracks[type].slub_ktrackd = kthread_run(kslubtrackd,
		&slub_tracks[type], "slub-%s",
		(type == SLUB_ALLOC) ? "alloc" : "free");
	if (IS_ERR(slub_tracks[type].slub_ktrackd)) {
		err = PTR_ERR(slub_tracks[type].slub_ktrackd);
		pr_err("%s: slub_ktrackd failed!\n", __func__);
		return err;
	}
	return 0;
}

static int __slub_create_ringbuf(int type)
{
	void *buf = NULL;
	size_t size = SLUB_RINGBUF_LEN;
	struct slub_ring_buf *srb = &srb_array[type];

	if (!is_power_of_2(size)) {
		pr_err("%s: size must be 2 power!\n", __func__);
		return -EINVAL;
	}

	buf = vmalloc(size * sizeof(struct stack_track));
	if (!buf)
		return -ENOMEM;

	srb->in = 0;
	srb->out = 0;
	srb->stack_buf = buf;
	srb->size = size;
	srb->type = type;
	spin_lock_init(&srb->lock);
	return 0;
}

static int slub_create_ringbuf(void)
{
	int ret;

	ret = __slub_create_ringbuf(SLUB_ALLOC);
	if (ret) {
		pr_err("%s,create alloc ringbuf failed\n", __func__);
		return -ENOMEM;
	}
	ret = __slub_create_ringbuf(SLUB_FREE);
	if (ret) {
		pr_err("%s,create free ringbuf failed\n", __func__);
		return -ENOMEM;
	}
	return 0;
}

static void __slub_del_ringbuf(int type)
{
	struct slub_ring_buf *srb = &srb_array[type];

	if (srb->stack_buf) {
		vfree(srb->stack_buf);
		srb->stack_buf = NULL;
	}
	srb->in = 0;
	srb->out = 0;

}

static int slub_del_ringbuf(void)
{
	__slub_del_ringbuf(SLUB_ALLOC);
	__slub_del_ringbuf(SLUB_FREE);
	return 0;
}

static inline int enable_slab_alloc_node_hook(void)
{
	int ret;

	ret = register_trace_android_vh_slab_alloc_node(slab_alloc_node_hook, NULL);
	if (ret) {
		pr_err("regsiter slab_alloc_node_hook failed, rc:%d\n", ret);
	}
	ret = register_trace_android_vh_slab_free(slab_free_hook, NULL);
	if (ret) {
		pr_err("regsiter slab_free_hook failed, rc:%d\n", ret);
	}

	return ret;
}

static inline int disable_slab_alloc_node_hook(void)
{
	int ret;

	ret = unregister_trace_android_vh_slab_alloc_node(slab_alloc_node_hook, NULL);
	if (ret) {
		pr_err("unregsiter slab_alloc_node_hook failed, rc:%d\n", ret);
	}
	ret = unregister_trace_android_vh_slab_free(slab_free_hook, NULL);
	if (ret) {
		pr_err("unregsiter slab_free_hook failed, rc:%d\n", ret);
	}

	return ret;
}

int slub_stack_track_on(const char *name)
{
	int ret;
	int found = 0;
	struct kmem_cache *cachep = NULL;

	if (slub_track_flag)
		return 0;
	ret = enable_slab_alloc_node_hook();
	if (ret) {
		return -EINVAL;
	}

	mutex_lock(&slab_mutex);
	list_for_each_entry(cachep, &slab_caches, list) {
		/* slub_track_cache self should not be tracked */
		if (slub_track_cache && strncmp(cachep->name, slub_track_cache->name,
			strlen(cachep->name) + 1) == 0) {
			continue;
		}
		if (strncmp(cachep->name, name, strlen(cachep->name) + 1) == 0) {
			cachep->flags |= SLAB_MM_TRACK;
			found = 1;
			break;
		}
	}
	mutex_unlock(&slab_mutex);
	if (!found) {
		pr_err("%s, slub name[%s] not found\n", __func__, name);
		return -EINVAL;
	}

	ret = slub_create_ringbuf();
	if (ret) {
		pr_err("%s, create ringbuf failed\n", __func__);
		return -ENOMEM;
	}
	pr_info("%s, slub name[%s] start track\n", __func__, name);
	slub_track_flag = 1;
	return 0;
}

int slub_stack_track_off(const char *name)
{
	int found = 0;
	struct kmem_cache *cachep = NULL;

	if (!slub_track_flag)
		return 0;

	mutex_lock(&slab_mutex);
	list_for_each_entry(cachep, &slab_caches, list) {
		if (strncmp(cachep->name, name, strlen(cachep->name) + 1) == 0) {
			cachep->flags &= ~SLAB_MM_TRACK;
			found = 1;
			break;
		}
	}
	mutex_unlock(&slab_mutex);
	if (!found) {
		pr_err("%s, slub name[%s] not found\n", __func__, name);
		return -EINVAL;
	}
	slub_track_flag = 0;
	disable_slab_alloc_node_hook();
	slub_fetch_node(SLUB_ALLOC);
	slub_fetch_node(SLUB_FREE);
	slub_del_ringbuf();
	pr_info("%s, slub name[%s] stop track\n", __func__, name);
	return 0;
}

size_t slub_stack_read(struct mm_stack_info *buf, size_t len, int type)
{
	size_t cnt;

	if (invalid_slub_type(type))
		return 0;
	cnt = slub_read_node(buf, len, type);
	return cnt;
}

int slub_stack_clean(void)
{
	return 0;
}

static int __init slub_track_init(void)
{
	slub_track_cache = kmem_cache_create("slub_track_cache",
		sizeof(struct slub_rb_node), 0, SLAB_MM_NOTRACK, NULL);
	if (!slub_track_cache) {
		pr_err("%s: alloc failed!\n", __func__);
		return -EINVAL;
	}
	slub_create_track(SLUB_ALLOC);
	slub_create_track(SLUB_FREE);
	return 0;
}

late_initcall(slub_track_init);
