/*
 * slub_track_unit_test.c
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

#include <kunit/test.h>
#include <../mm/slab.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/mutex.h>
#include <chipset_common/mm_track/mm_track.h>

#define SLUB_NAME_LEN 64
#define SLUB_CACHE_LEN 250
#define STACK_ENTRY_MAX_SIZE 1024
#define SLUB_TEST_CACHE_OBJ_COUNT 3
#define SLUB_TEST_CACHE_OBJ_UNIQUE_CALL 1

struct slub_cache_test {
	int test;
	char *name;
};

static struct kmem_cache *slub_test_cache;
static struct slub_cache_test* slub_cache_test_array[SLUB_TEST_CACHE_OBJ_COUNT];
static const char slub_test_cache_name[] = "slub_test_cache";

static void test_slub_hook(struct kunit *test)
{
	int hook_count = 0;
	struct kmem_cache *cachep = NULL;

	mm_track_on(SLUB_TRACK, slub_test_cache_name);

	mutex_lock(&slab_mutex);
	list_for_each_entry(cachep, &slab_caches, list) {
		if (strncmp(cachep->name, slub_test_cache_name, strlen(cachep->name) + 1) == 0 &&
				cachep->flags & SLAB_MM_TRACK) {
			hook_count++;
		}
	}
	mutex_unlock(&slab_mutex);

	mm_track_off(SLUB_TRACK, slub_test_cache_name);
	KUNIT_EXPECT_EQ(test, 1, hook_count);
}

static void test_slub_unhook(struct kunit *test)
{
	int hook_count = 0;
	struct kmem_cache *cachep = NULL;

	mm_track_off(SLUB_TRACK, slub_test_cache_name);

	mm_track_on(SLUB_TRACK, slub_test_cache_name);

	mm_track_off(SLUB_TRACK, slub_test_cache_name);

	mutex_lock(&slab_mutex);
	list_for_each_entry(cachep, &slab_caches, list) {
		if (strncmp(cachep->name, slub_test_cache_name, strlen(cachep->name) + 1) == 0 &&
				cachep->flags & SLAB_MM_TRACK) {
			hook_count++;
		}
	}
	mutex_unlock(&slab_mutex);

	KUNIT_EXPECT_EQ(test, 0, hook_count);
}

static inline void kuint_expect_check_stack_list(struct kunit *test, struct mm_stack_info *list,
	int stack_counts, unsigned long return_addr)
{
	int i = 0, j = 0;
	bool can_unwind_caller = false;
	struct stack_track *stack_track_test = NULL;

	if (list == NULL) {
		KUNIT_FAIL(test, "mm_stack_info is null, should not pass!");
		return;
	}
	for (i = 0; i < stack_counts; i++) {
		KUNIT_EXPECT_EQ(test, SLUB_TEST_CACHE_OBJ_UNIQUE_CALL, list[i].ref.counter);
		stack_track_test = &list[i].stack_entry;
		for (j = 0; j < stack_track_test->stack_len; j++) {
			if (stack_track_test->addrs[j] == return_addr) {
				can_unwind_caller = true;
				break;
			}
		}
		KUNIT_EXPECT_TRUE(test, can_unwind_caller);
		can_unwind_caller = false;
	}
}

static void test_slub_alloc_track(struct kunit *test)
{
	int i = 0;
	size_t stack_entry_size;
	unsigned long return_addr = _RET_IP_;
	struct mm_stack_info *list = NULL;

	mm_track_on(SLUB_TRACK, slub_test_cache_name);

	for (i = 0; i < SLUB_TEST_CACHE_OBJ_COUNT; i++) {
		slub_cache_test_array[i] = kmem_cache_alloc(slub_test_cache, GFP_ATOMIC);
	}

	mm_track_off(SLUB_TRACK, slub_test_cache_name);

	list = vzalloc(STACK_ENTRY_MAX_SIZE * sizeof(*list));
	stack_entry_size = mm_track_read(SLUB_TRACK, list, STACK_ENTRY_MAX_SIZE, SLUB_ALLOC);

	KUNIT_EXPECT_EQ(test, SLUB_TEST_CACHE_OBJ_COUNT, stack_entry_size);
	kuint_expect_check_stack_list(test, list, stack_entry_size, return_addr);

	for (i = 0; i < SLUB_TEST_CACHE_OBJ_COUNT; i++) {
		kmem_cache_free(slub_test_cache, slub_cache_test_array[i]);
	}
	vfree(list);
}

static void test_slub_free_track(struct kunit *test)
{
	int i = 0;
	size_t stack_entry_size;
	unsigned long return_addr = _RET_IP_;
	struct mm_stack_info *list = NULL;

	mm_track_on(SLUB_TRACK, slub_test_cache_name);

	for (i = 0; i < SLUB_TEST_CACHE_OBJ_COUNT; i++) {
		slub_cache_test_array[i] = kmem_cache_alloc(slub_test_cache, GFP_ATOMIC);
	}
	for (i = 0; i < SLUB_TEST_CACHE_OBJ_COUNT; i++) {
		kmem_cache_free(slub_test_cache, slub_cache_test_array[i]);
	}

	mm_track_off(SLUB_TRACK, slub_test_cache_name);

	list = vzalloc(STACK_ENTRY_MAX_SIZE * sizeof(*list));
	stack_entry_size = mm_track_read(SLUB_TRACK, list, STACK_ENTRY_MAX_SIZE, SLUB_FREE);

	KUNIT_EXPECT_EQ(test, SLUB_TEST_CACHE_OBJ_COUNT, stack_entry_size);
	kuint_expect_check_stack_list(test, list, stack_entry_size, return_addr);

	vfree(list);
}

static int test_init(struct kunit *test)
{
	slub_test_cache = kmem_cache_create(slub_test_cache_name, SLUB_CACHE_LEN, 0, 0, NULL);
	return 0;
}

static void test_exit(struct kunit *test)
{
	if (slub_test_cache) {
		kmem_cache_destroy(slub_test_cache);
	}
}

static struct kunit_case slub_track_test_cases[] = {
	KUNIT_CASE(test_slub_hook),
	KUNIT_CASE(test_slub_unhook),
	KUNIT_CASE(test_slub_alloc_track),
	KUNIT_CASE(test_slub_free_track),
	{}
};

static struct kunit_suite slub_track_test_suite = {
	.name = "slub_track_test",
	.init = test_init,
	.exit = test_exit,
	.test_cases = slub_track_test_cases,
};

kunit_test_suite(slub_track_test_suite);