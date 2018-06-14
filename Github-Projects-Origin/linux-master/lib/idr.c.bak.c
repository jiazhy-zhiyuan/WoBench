#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <linux/bitmap.h>
#include <linux/bug.h>
#include <linux/export.h>
#include <linux/idr.h>
#include <linux/slab.h>
#include <linux/spinlock.h>

DEFINE_PER_CPU(struct ida_bitmap *, ida_bitmap);
static DEFINE_SPINLOCK(simple_ida_lock);

/**
 * idr_alloc_u32() - Allocate an ID.
 * @idr: IDR handle.
 * @ptr: Pointer to be associated with the new ID.
 * @nextid: Pointer to an ID.
 * @max: The maximum ID to allocate (inclusive).
 * @gfp: Memory allocation flags.
 *
 * Allocates an unused ID in the range specified by @nextid and @max.
 * Note that @max is inclusive whereas the @end parameter to idr_alloc()
 * is exclusive.  The new ID is assigned to @nextid before the pointer
 * is inserted into the IDR, so if @nextid points into the object pointed
 * to by @ptr, a concurrent lookup will not find an uninitialised ID.
 *
 * The caller should provide their own locking to ensure that two
 * concurrent modifications to the IDR are not possible.  Read-only
 * accesses to the IDR may be done under the RCU read lock or may
 * exclude simultaneous writers.
 *
 * Return: 0 if an ID was allocated, -ENOMEM if memory allocation failed,
 * or -ENOSPC if no free IDs could be found.  If an error occurred,
 * @nextid is unchanged.
 */
int idr_alloc_u32(struct idr *idr, void *ptr, u32 *nextid,
			unsigned long max, gfp_t gfp)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	unsigned int base = idr->idr_base;
	unsigned int id = *nextid;

	if (WARN_ON_ONCE(radix_tree_is_internal_node(ptr)))
		return -EINVAL;
	if (WARN_ON_ONCE(!(idr->idr_rt.gfp_mask & ROOT_IS_IDR)))
		idr->idr_rt.gfp_mask |= IDR_RT_MARKER;

	id = (id < base) ? 0 : id - base;
	radix_tree_iter_init(&iter, id);
	slot = idr_get_free(&idr->idr_rt, &iter, gfp, max - base);
	if (IS_ERR(slot))
		return PTR_ERR(slot);

	*nextid = iter.index + base;
	/* there is a memory barrier inside radix_tree_iter_replace() */
	radix_tree_iter_replace(&idr->idr_rt, &iter, slot, ptr);
	radix_tree_iter_tag_clear(&idr->idr_rt, &iter, IDR_FREE);

	return 0;
}
EXPORT_SYMBOL_GPL(idr_alloc_u32);

/**
 * idr_alloc() - Allocate an ID.
 * @idr: IDR handle.
 * @ptr: Pointer to be associated with the new ID.
 * @start: The minimum ID (inclusive).
 * @end: The maximum ID (exclusive).
 * @gfp: Memory allocation flags.
 *
 * Allocates an unused ID in the range specified by @start and @end.  If
 * @end is <= 0, it is treated as one larger than %INT_MAX.  This allows
 * callers to use @start + N as @end as long as N is within integer range.
 *
 * The caller should provide their own locking to ensure that two
 * concurrent modifications to the IDR are not possible.  Read-only
 * accesses to the IDR may be done under the RCU read lock or may
 * exclude simultaneous writers.
 *
 * Return: The newly allocated ID, -ENOMEM if memory allocation failed,
 * or -ENOSPC if no free IDs could be found.
 */
int idr_alloc(struct idr *idr, void *ptr, int start, int end, gfp_t gfp)
{
	u32 id = start;
	int ret;

	if (WARN_ON_ONCE(start < 0))
		return -EINVAL;

	ret = idr_alloc_u32(idr, ptr, &id, end > 0 ? end - 1 : INT_MAX, gfp);
	if (ret)
		return ret;

	return id;
}
EXPORT_SYMBOL_GPL(idr_alloc);

/**
 * idr_alloc_cyclic() - Allocate an ID cyclically.
 * @idr: IDR handle.
 * @ptr: Pointer to be associated with the new ID.
 * @start: The minimum ID (inclusive).
 * @end: The maximum ID (exclusive).
 * @gfp: Memory allocation flags.
 *
 * Allocates an unused ID in the range specified by @nextid and @end.  If
 * @end is <= 0, it is treated as one larger than %INT_MAX.  This allows
 * callers to use @start + N as @end as long as N is within integer range.
 * The search for an unused ID will start at the last ID allocated and will
 * wrap around to @start if no free IDs are found before reaching @end.
 *
 * The caller should provide their own locking to ensure that two
 * concurrent modifications to the IDR are not possible.  Read-only
 * accesses to the IDR may be done under the RCU read lock or may
 * exclude simultaneous writers.
 *
 * Return: The newly allocated ID, -ENOMEM if memory allocation failed,
 * or -ENOSPC if no free IDs could be found.
 */
int idr_alloc_cyclic(struct idr *idr, void *ptr, int start, int end, gfp_t gfp)
{
	u32 id = idr->idr_next;
	int err, max = end > 0 ? end - 1 : INT_MAX;

	if ((int)id < start)
		id = start;

	err = idr_alloc_u32(idr, ptr, &id, max, gfp);
	if ((err == -ENOSPC) && (id > start)) {
		id = start;
		err = idr_alloc_u32(idr, ptr, &id, max, gfp);
	}
	if (err)
		return err;

	idr->idr_next = id + 1;
	return id;
}
EXPORT_SYMBOL(idr_alloc_cyclic);

/**
 * idr_remove() - Remove an ID from the IDR.
 * @idr: IDR handle.
 * @id: Pointer ID.
 *
 * Removes this ID from the IDR.  If the ID was not previously in the IDR,
 * this function returns %NULL.
 *
 * Since this function modifies the IDR, the caller should provide their
 * own locking to ensure that concurrent modification of the same IDR is
 * not possible.
 *
 * Return: The pointer formerly associated with this ID.
 */
void *idr_remove(struct idr *idr, unsigned long id)
{
	return radix_tree_delete_item(&idr->idr_rt, id - idr->idr_base, NULL);
}
EXPORT_SYMBOL_GPL(idr_remove);

/**
 * idr_find() - Return pointer for given ID.
 * @idr: IDR handle.
 * @id: Pointer ID.
 *
 * Looks up the pointer associated with this ID.  A %NULL pointer may
 * indicate that @id is not allocated or that the %NULL pointer was
 * associated with this ID.
 *
 * This function can be called under rcu_read_lock(), given that the leaf
 * pointers lifetimes are correctly managed.
 *
 * Return: The pointer associated with this ID.
 */
void *idr_find(const struct idr *idr, unsigned long id)
{
	return radix_tree_lookup(&idr->idr_rt, id - idr->idr_base);
}
EXPORT_SYMBOL_GPL(idr_find);

/**
 * idr_for_each() - Iterate through all stored pointers.
 * @idr: IDR handle.
 * @fn: Function to be called for each pointer.
 * @data: Data passed to callback function.
 *
 * The callback function will be called for each entry in @idr, passing
 * the ID, the entry and @data.
 *
 * If @fn returns anything other than %0, the iteration stops and that
 * value is returned from this function.
 *
 * idr_for_each() can be called concurrently with idr_alloc() and
 * idr_remove() if protected by RCU.  Newly added entries may not be
 * seen and deleted entries may be seen, but adding and removing entries
 * will not cause other entries to be skipped, nor spurious ones to be seen.
 */
int idr_for_each(const struct idr *idr,
		int (*fn)(int id, void *p, void *data), void *data)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	int base = idr->idr_base;

	radix_tree_for_each_slot(slot, &idr->idr_rt, &iter, 0) {
		int ret;
		unsigned long id = iter.index + base;

		if (WARN_ON_ONCE(id > INT_MAX))
			break;
		ret = fn(id, rcu_dereference_raw(*slot), data);
		if (ret)
			return ret;
	}

	return 0;
}
EXPORT_SYMBOL(idr_for_each);

/**
 * idr_get_next() - Find next populated entry.
 * @idr: IDR handle.
 * @nextid: Pointer to an ID.
 *
 * Returns the next populated entry in the tree with an ID greater than
 * or equal to the value pointed to by @nextid.  On exit, @nextid is updated
 * to the ID of the found value.  To use in a loop, the value pointed to by
 * nextid must be incremented by the user.
 */
void *idr_get_next(struct idr *idr, int *nextid)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	unsigned long base = idr->idr_base;
	unsigned long id = *nextid;

	id = (id < base) ? 0 : id - base;
	slot = radix_tree_iter_find(&idr->idr_rt, &iter, id);
	if (!slot)
		return NULL;
	id = iter.index + base;

	if (WARN_ON_ONCE(id > INT_MAX))
		return NULL;

	*nextid = id;
	return rcu_dereference_raw(*slot);
}
EXPORT_SYMBOL(idr_get_next);

/**
 * idr_get_next_ul() - Find next populated entry.
 * @idr: IDR handle.
 * @nextid: Pointer to an ID.
 *
 * Returns the next populated entry in the tree with an ID greater than
 * or equal to the value pointed to by @nextid.  On exit, @nextid is updated
 * to the ID of the found value.  To use in a loop, the value pointed to by
 * nextid must be incremented by the user.
 */
void *idr_get_next_ul(struct idr *idr, unsigned long *nextid)
{
	struct radix_tree_iter iter;
	void __rcu **slot;
	unsigned long base = idr->idr_base;
	unsigned long id = *nextid;

	id = (id < base) ? 0 : id - base;
	slot = radix_tree_iter_find(&idr->idr_rt, &iter, id);
	if (!slot)
		return NULL;

	*nextid = iter.index + base;
	return rcu_dereference_raw(*slot);
}
EXPORT_SYMBOL(idr_get_next_ul);

/**
 * idr_replace() - replace pointer for given ID.
 * @idr: IDR handle.
 * @ptr: New pointer to associate with the ID.
 * @id: ID to change.
 *
 * Replace the pointer registered with an ID and return the old value.
 * This function can be called under the RCU read lock concurrently with
 * idr_alloc() and idr_remove() (as long as the ID being removed is not
 * the one being replaced!).
 *
 * Returns: the old value on success.  %-ENOENT indicates that @id was not
 * found.  %-EINVAL indicates that @ptr was not valid.
 */
void *idr_replace(struct idr *idr, void *ptr, unsigned long id)
{
	struct radix_tree_node *node;
	void __rcu **slot = NULL;
	void *entry;

	if (WARN_ON_ONCE(radix_tree_is_internal_node(ptr)))
		return ERR_PTR(-EINVAL);
	id -= idr->idr_base;

	entry = __radix_tree_lookup(&idr->idr_rt, id, &node, &slot);
	if (!slot || radix_tree_tag_get(&idr->idr_rt, id, IDR_FREE))
		return ERR_PTR(-ENOENT);

	__radix_tree_replace(&idr->idr_rt, node, slot, ptr, NULL);

	return entry;
}
EXPORT_SYMBOL(idr_replace);

/**
 * DOC: IDA description
 *
 * The IDA is an ID allocator which does not provide the ability to
 * associate an ID with a pointer.  As such, it only needs to store one
 * bit per ID, and so is more space efficient than an IDR.  To use an IDA,
 * define it using DEFINE_IDA() (or embed a &struct ida in a data structure,
 * then initialise it using ida_init()).  To allocate a new ID, call
 * ida_simple_get().  To free an ID, call ida_simple_remove().
 *
 * If you have more complex locking requirements, use a loop around
 * ida_pre_get() and ida_get_new() to allocate a new ID.  Then use
 * ida_remove() to free an ID.  You must make sure that ida_get_new() and
 * ida_remove() cannot be called at the same time as each other for the
 * same IDA.
 *
 * You can also use ida_get_new_above() if you need an ID to be allocated
 * above a particular number.  ida_destroy() can be used to dispose of an
 * IDA without needing to free the individual IDs in it.  You can use
 * ida_is_empty() to find out whether the IDA has any IDs currently allocated.
 *
 * IDs are currently limited to the range [0-INT_MAX].  If this is an awkward
 * limitation, it should be quite straightforward to raise the maximum.
 */

/*
 * Developer's notes:
 *
 * The IDA uses the functionality provided by the IDR & radix tree to store
 * bitmaps in each entry.  The IDR_FREE tag means there is at least one bit
 * free, unlike the IDR where it means at least one entry is free.
 *
 * I considered telling the radix tree that each slot is an order-10 node
 * and storing the bit numbers in the radix tree, but the radix tree can't
 * allow a single multiorder entry at index 0, which would significantly
 * increase memory consumption for the IDA.  So instead we divide the index
 * by the number of bits in the leaf bitmap before doing a radix tree lookup.
 *
 * As an optimisation, if there are only a few low bits set in any given
 * leaf, instead of allocating a 128-byte bitmap, we use the 'exceptional
 * entry' functionality of the radix tree to store BITS_PER_LONG - 2 bits
 * directly in the entry.  By being really tricksy, we could store
 * BITS_PER_LONG - 1 bits, but there're diminishing returns after optimising
 * for 0-3 allocated IDs.
 *
 * We allow the radix tree 'exceptional' count to get out of date.  Nothing
 * in the IDA nor the radix tree code checks it.  If it becomes important
 * to maintain an accurate exceptional count, switch the rcu_assign_pointer()
 * calls to radix_tree_iter_replace() which will correct the exceptional
 * count.
 *
 * The IDA always requires a lock to alloc/free.  If we add a 'test_bit'
 * equivalent, it will still need locking.  Going to RCU lookup would require
 * using RCU to free bitmaps, and that's not trivial without embedding an
 * RCU head in the bitmap, which adds a 2-pointer overhead to each 128-byte
 * bitmap, which is excessive.
 */

#define IDA_MAX (0x80000000U / IDA_BITMAP_BITS - 1)

/**
 * ida_get_new_above - allocate new ID above or equal to a start id
 * @ida: ida handle
 * @start: id to start search at
 * @id: pointer to the allocated handle
 *
 * Allocate new ID above or equal to @start.  It should be called
 * with any required locks to ensure that concurrent calls to
 * ida_get_new_above() / ida_get_new() / ida_remove() are not allowed.
 * Consider using ida_simple_get() if you do not have complex locking
 * requirements.
 *
 * If memory is required, it will return %-EAGAIN, you should unlock
 * and go back to the ida_pre_get() call.  If the ida is full, it will
 * return %-ENOSPC.  On success, it will return 0.
 *
 * @id returns a value in the range @start ... %0x7fffffff.
 */
int ida_get_new_above(struct ida *ida, int start, int *id)
{
	struct radix_tree_root *root = &ida->ida_rt;
	void __rcu **slot;
	struct radix_tree_iter iter;
	struct ida_bitmap *bitmap;
	unsigned long index;
	unsigned bit, ebit;
	int new;

	index = start / IDA_BITMAP_BITS;
	bit = start % IDA_BITMAP_BITS;
	ebit = bit + RADIX_TREE_EXCEPTIONAL_SHIFT;

	slot = radix_tree_iter_init(&iter, index);
	for (;;) {
		if (slot)
			slot = radix_tree_next_slot(slot, &iter,
						RADIX_TREE_ITER_TAGGED);
		if (!slot) {
			slot = idr_get_free(root, &iter, GFP_NOWAIT, IDA_MAX);
			if (IS_ERR(slot)) {
				if (slot == ERR_PTR(-ENOMEM))
					return -EAGAIN;
				return PTR_ERR(slot);
			}
		}
		if (iter.index > index) {
			bit = 0;
			ebit = RADIX_TREE_EXCEPTIONAL_SHIFT;
		}
		new = iter.index * IDA_BITMAP_BITS;
		bitmap = rcu_dereference_raw(*slot);
		if (radix_tree_exception(bitmap)) {
			unsigned long tmp = (unsigned long)bitmap;
			ebit = find_next_zero_bit(&tmp, BITS_PER_LONG, ebit);
			if (ebit < BITS_PER_LONG) {
				tmp |= 1UL << ebit;
				rcu_assign_pointer(*slot, (void *)tmp);
				*id = new + ebit - RADIX_TREE_EXCEPTIONAL_SHIFT;
				return 0;
			}
			bitmap = this_cpu_xchg(ida_bitmap, NULL);
			if (!bitmap)
				return -EAGAIN;
			bitmap->bitmap[0] = tmp >> RADIX_TREE_EXCEPTIONAL_SHIFT;
			rcu_assign_pointer(*slot, bitmap);
		}

		if (bitmap) {
			bit = find_next_zero_bit(bitmap->bitmap,
							IDA_BITMAP_BITS, bit);
			new += bit;
			if (new < 0)
				return -ENOSPC;
			if (bit == IDA_BITMAP_BITS)
				continue;

			__set_bit(bit, bitmap->bitmap);
			if (bitmap_full(bitmap->bitmap, IDA_BITMAP_BITS))
				radix_tree_iter_tag_clear(root, &iter,
								IDR_FREE);
		} else {
			new += bit;
			if (new < 0)
				return -ENOSPC;
			if (ebit < BITS_PER_LONG) {
				bitmap = (void *)((1UL << ebit) |
						RADIX_TREE_EXCEPTIONAL_ENTRY);
				radix_tree_iter_replace(root, &iter, slot,
						bitmap);
				*id = new;
				return 0;
			}
			bitmap = this_cpu_xchg(ida_bitmap, NULL);
			if (!bitmap)
				return -EAGAIN;
			__set_bit(bit, bitmap->bitmap);
			radix_tree_iter_replace(root, &iter, slot, bitmap);
		}

		*id = new;
		return 0;
	}
}
EXPORT_SYMBOL(ida_get_new_above);

/**
 * ida_remove - Free the given ID
 * @ida: ida handle
 * @id: ID to free
 *
 * This function should not be called at the same time as ida_get_new_above().
 */
void ida_remove(struct ida *ida, int id)
{
	unsigned long index = id / IDA_BITMAP_BITS;
	unsigned offset = id % IDA_BITMAP_BITS;
	struct ida_bitmap *bitmap;
	unsigned long *btmp;
	struct radix_tree_iter iter;
	void __rcu **slot;

	slot = radix_tree_iter_lookup(&ida->ida_rt, &iter, index);
	if (!slot)
		goto err;

	bitmap = rcu_dereference_raw(*slot);
	if (radix_tree_exception(bitmap)) {
		btmp = (unsigned long *)slot;
		offset += RADIX_TREE_EXCEPTIONAL_SHIFT;
		if (offset >= BITS_PER_LONG)
			goto err;
	} else {
		btmp = bitmap->bitmap;
	}
	if (!test_bit(offset, btmp))
		goto err;

	__clear_bit(offset, btmp);
	radix_tree_iter_tag_set(&ida->ida_rt, &iter, IDR_FREE);
	if (radix_tree_exception(bitmap)) {
		if (rcu_dereference_raw(*slot) ==
					(void *)RADIX_TREE_EXCEPTIONAL_ENTRY)
			radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
	} else if (bitmap_empty(btmp, IDA_BITMAP_BITS)) {
		kfree(bitmap);
		radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
	}
	return;
 err:
	WARN(1, "ida_remove called for id=%d which is not allocated.\n", id);
}
EXPORT_SYMBOL(ida_remove);

/**
 * ida_destroy - Free the contents of an ida
 * @ida: ida handle
 *
 * Calling this function releases all resources associated with an IDA.  When
 * this call returns, the IDA is empty and can be reused or freed.  The caller
 * should not allow ida_remove() or ida_get_new_above() to be called at the
 * same time.
 */
void ida_destroy(struct ida *ida)
{
	struct radix_tree_iter iter;
	void __rcu **slot;

	radix_tree_for_each_slot(slot, &ida->ida_rt, &iter, 0) {
		struct ida_bitmap *bitmap = rcu_dereference_raw(*slot);
		if (!radix_tree_exception(bitmap))
			kfree(bitmap);
		radix_tree_iter_delete(&ida->ida_rt, &iter, slot);
	}
}
EXPORT_SYMBOL(ida_destroy);

/**
 * ida_simple_get - get a new id.
 * @ida: the (initialized) ida.
 * @start: the minimum id (inclusive, < 0x8000000)
 * @end: the maximum id (exclusive, < 0x8000000 or 0)
 * @gfp_mask: memory allocation flags
 *
 * Allocates an id in the range start <= id < end, or returns -ENOSPC.
 * On memory allocation failure, returns -ENOMEM.
 *
 * Compared to ida_get_new_above() this function does its own locking, and
 * should be used unless there are special requirements.
 *
 * Use ida_simple_remove() to get rid of an id.
 */
int ida_simple_get(struct ida *ida, unsigned int start, unsigned int end,
		   gfp_t gfp_mask)
{
	int ret, id;
	unsigned int max;
	unsigned long flags;

	BUG_ON((int)start < 0);
	BUG_ON((int)end < 0);

	if (end == 0)
		max = 0x80000000;
	else {
		BUG_ON(end < start);
		max = end - 1;
	}

again:
	if (!ida_pre_get(ida, gfp_mask))
		return -ENOMEM;

	spin_lock_irqsave(&simple_ida_lock, flags);
	ret = ida_get_new_above(ida, start, &id);
	if (!ret) {
		if (id > max) {
			ida_remove(ida, id);
			ret = -ENOSPC;
		} else {
			ret = id;
		}
	}
	spin_unlock_irqrestore(&simple_ida_lock, flags);

	if (unlikely(ret == -EAGAIN))
		goto again;

	return ret;
}
EXPORT_SYMBOL(ida_simple_get);

/**
 * ida_simple_remove - remove an allocated id.
 * @ida: the (initialized) ida.
 * @id: the id returned by ida_simple_get.
 *
 * Use to release an id allocated with ida_simple_get().
 *
 * Compared to ida_remove() this function does its own locking, and should be
 * used unless there are special requirements.
 */
void ida_simple_remove(struct ida *ida, unsigned int id)
{
	unsigned long flags;

	BUG_ON((int)id < 0);
	spin_lock_irqsave(&simple_ida_lock, flags);
	ida_remove(ida, id);
	spin_unlock_irqrestore(&simple_ida_lock, flags);
}
EXPORT_SYMBOL(ida_simple_remove);
