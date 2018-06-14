#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Copyright (C) Sistina Software, Inc.  1997-2003 All rights reserved.
 * Copyright (C) 2004-2006 Red Hat, Inc.  All rights reserved.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License version 2.
 */

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/completion.h>
#include <linux/buffer_head.h>
#include <linux/gfs2_ondisk.h>
#include <linux/crc32.h>
#include <linux/crc32c.h>

#include "gfs2.h"
#include "incore.h"
#include "bmap.h"
#include "glock.h"
#include "glops.h"
#include "log.h"
#include "lops.h"
#include "meta_io.h"
#include "recovery.h"
#include "super.h"
#include "util.h"
#include "dir.h"

struct workqueue_struct *gfs_recovery_wq;

int gfs2_replay_read_block(struct gfs2_jdesc *jd, unsigned int blk,
			   struct buffer_head **bh)
{
	struct gfs2_inode *ip = GFS2_I(jd->jd_inode);
	struct gfs2_glock *gl = ip->i_gl;
	int new = 0;
	u64 dblock;
	u32 extlen;
	int error;

	error = gfs2_extent_map(&ip->i_inode, blk, &new, &dblock, &extlen);
	if (error)
		return error;
	if (!dblock) {
		gfs2_consist_inode(ip);
		return -EIO;
	}

	*bh = gfs2_meta_ra(gl, dblock, extlen);

	return error;
}

int gfs2_revoke_add(struct gfs2_jdesc *jd, u64 blkno, unsigned int where)
{
	struct list_head *head = &jd->jd_revoke_list;
	struct gfs2_revoke_replay *rr;
	int found = 0;

	list_for_each_entry(rr, head, rr_list) {
		if (rr->rr_blkno == blkno) {
			found = 1;
			break;
		}
	}

	if (found) {
		rr->rr_where = where;
		return 0;
	}

	rr = kmalloc(sizeof(struct gfs2_revoke_replay), GFP_NOFS);
	if (!rr)
		return -ENOMEM;

	rr->rr_blkno = blkno;
	rr->rr_where = where;
	list_add(&rr->rr_list, head);

	return 1;
}

int gfs2_revoke_check(struct gfs2_jdesc *jd, u64 blkno, unsigned int where)
{
	struct gfs2_revoke_replay *rr;
	int wrap, a, b, revoke;
	int found = 0;

	list_for_each_entry(rr, &jd->jd_revoke_list, rr_list) {
		if (rr->rr_blkno == blkno) {
			found = 1;
			break;
		}
	}

	if (!found)
		return 0;

	wrap = (rr->rr_where < jd->jd_replay_tail);
	a = (jd->jd_replay_tail < where);
	b = (where < rr->rr_where);
	revoke = (wrap) ? (a || b) : (a && b);

	return revoke;
}

void gfs2_revoke_clean(struct gfs2_jdesc *jd)
{
	struct list_head *head = &jd->jd_revoke_list;
	struct gfs2_revoke_replay *rr;

	while (!list_empty(head)) {
		rr = list_entry(head->next, struct gfs2_revoke_replay, rr_list);
		list_del(&rr->rr_list);
		kfree(rr);
	}
}

/**
 * get_log_header - read the log header for a given segment
 * @jd: the journal
 * @blk: the block to look at
 * @lh: the log header to return
 *
 * Read the log header for a given segement in a given journal.  Do a few
 * sanity checks on it.
 *
 * Returns: 0 on success,
 *          1 if the header was invalid or incomplete,
 *          errno on error
 */

static int get_log_header(struct gfs2_jdesc *jd, unsigned int blk,
			  struct gfs2_log_header_host *head)
{
	struct gfs2_log_header *lh;
	struct buffer_head *bh;
	u32 hash, crc;
	int error;

	error = gfs2_replay_read_block(jd, blk, &bh);
	if (error)
		return error;
	lh = (void *)bh->b_data;

	hash = crc32(~0, lh, LH_V1_SIZE - 4);
	hash = ~crc32_le_shift(hash, 4);  /* assume lh_hash is zero */

	crc = crc32c(~0, (void *)lh + LH_V1_SIZE + 4,
		     bh->b_size - LH_V1_SIZE - 4);

	error = lh->lh_header.mh_magic != cpu_to_be32(GFS2_MAGIC) ||
		lh->lh_header.mh_type != cpu_to_be32(GFS2_METATYPE_LH) ||
		be32_to_cpu(lh->lh_blkno) != blk ||
		be32_to_cpu(lh->lh_hash) != hash ||
		(lh->lh_crc != 0 && be32_to_cpu(lh->lh_crc) != crc);

	brelse(bh);

	if (!error) {
		head->lh_sequence = be64_to_cpu(lh->lh_sequence);
		head->lh_flags = be32_to_cpu(lh->lh_flags);
		head->lh_tail = be32_to_cpu(lh->lh_tail);
		head->lh_blkno = be32_to_cpu(lh->lh_blkno);
	}
	return error;
}

/**
 * find_good_lh - find a good log header
 * @jd: the journal
 * @blk: the segment to start searching from
 * @lh: the log header to fill in
 * @forward: if true search forward in the log, else search backward
 *
 * Call get_log_header() to get a log header for a segment, but if the
 * segment is bad, either scan forward or backward until we find a good one.
 *
 * Returns: errno
 */

static int find_good_lh(struct gfs2_jdesc *jd, unsigned int *blk,
			struct gfs2_log_header_host *head)
{
	unsigned int orig_blk = *blk;
	int error;

	for (;;) {
		error = get_log_header(jd, *blk, head);
		if (error <= 0)
			return error;

		if (++*blk == jd->jd_blocks)
			*blk = 0;

		if (*blk == orig_blk) {
			gfs2_consist_inode(GFS2_I(jd->jd_inode));
			return -EIO;
		}
	}
}

/**
 * jhead_scan - make sure we've found the head of the log
 * @jd: the journal
 * @head: this is filled in with the log descriptor of the head
 *
 * At this point, seg and lh should be either the head of the log or just
 * before.  Scan forward until we find the head.
 *
 * Returns: errno
 */

static int jhead_scan(struct gfs2_jdesc *jd, struct gfs2_log_header_host *head)
{
	unsigned int blk = head->lh_blkno;
	struct gfs2_log_header_host lh;
	int error;

	for (;;) {
		if (++blk == jd->jd_blocks)
			blk = 0;

		error = get_log_header(jd, blk, &lh);
		if (error < 0)
			return error;
		if (error == 1)
			continue;

		if (lh.lh_sequence == head->lh_sequence) {
			gfs2_consist_inode(GFS2_I(jd->jd_inode));
			return -EIO;
		}
		if (lh.lh_sequence < head->lh_sequence)
			break;

		*head = lh;
	}

	return 0;
}

/**
 * gfs2_find_jhead - find the head of a log
 * @jd: the journal
 * @head: the log descriptor for the head of the log is returned here
 *
 * Do a binary search of a journal and find the valid log entry with the
 * highest sequence number.  (i.e. the log head)
 *
 * Returns: errno
 */

int gfs2_find_jhead(struct gfs2_jdesc *jd, struct gfs2_log_header_host *head)
{
	struct gfs2_log_header_host lh_1, lh_m;
	u32 blk_1, blk_2, blk_m;
	int error;

	blk_1 = 0;
	blk_2 = jd->jd_blocks - 1;

	for (;;) {
		blk_m = (blk_1 + blk_2) / 2;

		error = find_good_lh(jd, &blk_1, &lh_1);
		if (error)
			return error;

		error = find_good_lh(jd, &blk_m, &lh_m);
		if (error)
			return error;

		if (blk_1 == blk_m || blk_m == blk_2)
			break;

		if (lh_1.lh_sequence <= lh_m.lh_sequence)
			blk_1 = blk_m;
		else
			blk_2 = blk_m;
	}

	error = jhead_scan(jd, &lh_1);
	if (error)
		return error;

	*head = lh_1;

	return error;
}

/**
 * foreach_descriptor - go through the active part of the log
 * @jd: the journal
 * @start: the first log header in the active region
 * @end: the last log header (don't process the contents of this entry))
 *
 * Call a given function once for every log descriptor in the active
 * portion of the log.
 *
 * Returns: errno
 */

static int foreach_descriptor(struct gfs2_jdesc *jd, unsigned int start,
			      unsigned int end, int pass)
{
	struct gfs2_sbd *sdp = GFS2_SB(jd->jd_inode);
	struct buffer_head *bh;
	struct gfs2_log_descriptor *ld;
	int error = 0;
	u32 length;
	__be64 *ptr;
	unsigned int offset = sizeof(struct gfs2_log_descriptor);
	offset += sizeof(__be64) - 1;
	offset &= ~(sizeof(__be64) - 1);

	while (start != end) {
		error = gfs2_replay_read_block(jd, start, &bh);
		if (error)
			return error;
		if (gfs2_meta_check(sdp, bh)) {
			brelse(bh);
			return -EIO;
		}
		ld = (struct gfs2_log_descriptor *)bh->b_data;
		length = be32_to_cpu(ld->ld_length);

		if (be32_to_cpu(ld->ld_header.mh_type) == GFS2_METATYPE_LH) {
			struct gfs2_log_header_host lh;
			error = get_log_header(jd, start, &lh);
			if (!error) {
				gfs2_replay_incr_blk(jd, &start);
				brelse(bh);
				continue;
			}
			if (error == 1) {
				gfs2_consist_inode(GFS2_I(jd->jd_inode));
				error = -EIO;
			}
			brelse(bh);
			return error;
		} else if (gfs2_metatype_check(sdp, bh, GFS2_METATYPE_LD)) {
			brelse(bh);
			return -EIO;
		}
		ptr = (__be64 *)(bh->b_data + offset);
		error = lops_scan_elements(jd, start, ld, ptr, pass);
		if (error) {
			brelse(bh);
			return error;
		}

		while (length--)
			gfs2_replay_incr_blk(jd, &start);

		brelse(bh);
	}

	return 0;
}

/**
 * clean_journal - mark a dirty journal as being clean
 * @jd: the journal
 * @head: the head journal to start from
 *
 * Returns: errno
 */

static void clean_journal(struct gfs2_jdesc *jd,
			  struct gfs2_log_header_host *head)
{
	struct gfs2_sbd *sdp = GFS2_SB(jd->jd_inode);

	sdp->sd_log_flush_head = head->lh_blkno;
	gfs2_replay_incr_blk(jd, &sdp->sd_log_flush_head);
	gfs2_write_log_header(sdp, jd, head->lh_sequence + 1, 0,
			      GFS2_LOG_HEAD_UNMOUNT | GFS2_LOG_HEAD_RECOVERY,
			      REQ_PREFLUSH | REQ_FUA | REQ_META | REQ_SYNC);
}


static void gfs2_recovery_done(struct gfs2_sbd *sdp, unsigned int jid,
                               unsigned int message)
{
	char env_jid[20];
	char env_status[20];
	char *envp[] = { env_jid, env_status, NULL };
	struct lm_lockstruct *ls = &sdp->sd_lockstruct;

        ls->ls_recover_jid_done = jid;
        ls->ls_recover_jid_status = message;
	sprintf(env_jid, "JID=%u", jid);
	sprintf(env_status, "RECOVERY=%s",
		message == LM_RD_SUCCESS ? "Done" : "Failed");
        kobject_uevent_env(&sdp->sd_kobj, KOBJ_CHANGE, envp);

	if (sdp->sd_lockstruct.ls_ops->lm_recovery_result)
		sdp->sd_lockstruct.ls_ops->lm_recovery_result(sdp, jid, message);
}

void gfs2_recover_func(struct work_struct *work)
{
	struct gfs2_jdesc *jd = container_of(work, struct gfs2_jdesc, jd_work);
	struct gfs2_inode *ip = GFS2_I(jd->jd_inode);
	struct gfs2_sbd *sdp = GFS2_SB(jd->jd_inode);
	struct gfs2_log_header_host head;
	struct gfs2_holder j_gh, ji_gh, thaw_gh;
	unsigned long t;
	int ro = 0;
	unsigned int pass;
	int error;
	int jlocked = 0;

	if (sdp->sd_args.ar_spectator ||
	    (jd->jd_jid != sdp->sd_lockstruct.ls_jid)) {
		fs_info(sdp, "jid=%u: Trying to acquire journal lock...\n",
			jd->jd_jid);
		jlocked = 1;
		/* Acquire the journal lock so we can do recovery */

		error = gfs2_glock_nq_num(sdp, jd->jd_jid, &gfs2_journal_glops,
					  LM_ST_EXCLUSIVE,
					  LM_FLAG_NOEXP | LM_FLAG_TRY | GL_NOCACHE,
					  &j_gh);
		switch (error) {
		case 0:
			break;

		case GLR_TRYFAILED:
			fs_info(sdp, "jid=%u: Busy\n", jd->jd_jid);
			error = 0;

		default:
			goto fail;
		};

		error = gfs2_glock_nq_init(ip->i_gl, LM_ST_SHARED,
					   LM_FLAG_NOEXP | GL_NOCACHE, &ji_gh);
		if (error)
			goto fail_gunlock_j;
	} else {
		fs_info(sdp, "jid=%u, already locked for use\n", jd->jd_jid);
	}

	fs_info(sdp, "jid=%u: Looking at journal...\n", jd->jd_jid);

	error = gfs2_jdesc_check(jd);
	if (error)
		goto fail_gunlock_ji;

	error = gfs2_find_jhead(jd, &head);
	if (error)
		goto fail_gunlock_ji;

	if (!(head.lh_flags & GFS2_LOG_HEAD_UNMOUNT)) {
		fs_info(sdp, "jid=%u: Acquiring the transaction lock...\n",
			jd->jd_jid);

		t = jiffies;

		/* Acquire a shared hold on the freeze lock */

		error = gfs2_glock_nq_init(sdp->sd_freeze_gl, LM_ST_SHARED,
					   LM_FLAG_NOEXP | LM_FLAG_PRIORITY,
					   &thaw_gh);
		if (error)
			goto fail_gunlock_ji;

		if (test_bit(SDF_RORECOVERY, &sdp->sd_flags)) {
			ro = 1;
		} else if (test_bit(SDF_JOURNAL_CHECKED, &sdp->sd_flags)) {
			if (!test_bit(SDF_JOURNAL_LIVE, &sdp->sd_flags))
				ro = 1;
		} else {
			if (sb_rdonly(sdp->sd_vfs)) {
				/* check if device itself is read-only */
				ro = bdev_read_only(sdp->sd_vfs->s_bdev);
				if (!ro) {
					fs_info(sdp, "recovery required on "
						"read-only filesystem.\n");
					fs_info(sdp, "write access will be "
						"enabled during recovery.\n");
				}
			}
		}

		if (ro) {
			fs_warn(sdp, "jid=%u: Can't replay: read-only block "
				"device\n", jd->jd_jid);
			error = -EROFS;
			goto fail_gunlock_thaw;
		}

		fs_info(sdp, "jid=%u: Replaying journal...\n", jd->jd_jid);

		for (pass = 0; pass < 2; pass++) {
			lops_before_scan(jd, &head, pass);
			error = foreach_descriptor(jd, head.lh_tail,
						   head.lh_blkno, pass);
			lops_after_scan(jd, error, pass);
			if (error)
				goto fail_gunlock_thaw;
		}

		clean_journal(jd, &head);

		gfs2_glock_dq_uninit(&thaw_gh);
		t = DIV_ROUND_UP(jiffies - t, HZ);
		fs_info(sdp, "jid=%u: Journal replayed in %lus\n",
			jd->jd_jid, t);
	}

	gfs2_recovery_done(sdp, jd->jd_jid, LM_RD_SUCCESS);

	if (jlocked) {
		gfs2_glock_dq_uninit(&ji_gh);
		gfs2_glock_dq_uninit(&j_gh);
	}

	fs_info(sdp, "jid=%u: Done\n", jd->jd_jid);
	goto done;

fail_gunlock_thaw:
	gfs2_glock_dq_uninit(&thaw_gh);
fail_gunlock_ji:
	if (jlocked) {
		gfs2_glock_dq_uninit(&ji_gh);
fail_gunlock_j:
		gfs2_glock_dq_uninit(&j_gh);
	}

	fs_info(sdp, "jid=%u: %s\n", jd->jd_jid, (error) ? "Failed" : "Done");
fail:
	jd->jd_recover_error = error;
	gfs2_recovery_done(sdp, jd->jd_jid, LM_RD_GAVEUP);
done:
	clear_bit(JDF_RECOVERY, &jd->jd_flags);
	smp_mb__after_atomic();
	wake_up_bit(&jd->jd_flags, JDF_RECOVERY);
}

int gfs2_recover_journal(struct gfs2_jdesc *jd, bool wait)
{
	int rv;

	if (test_and_set_bit(JDF_RECOVERY, &jd->jd_flags))
		return -EBUSY;

	/* we have JDF_RECOVERY, queue should always succeed */
	rv = queue_work(gfs_recovery_wq, &jd->jd_work);
	BUG_ON(!rv);

	if (wait)
		wait_on_bit(&jd->jd_flags, JDF_RECOVERY,
			    TASK_UNINTERRUPTIBLE);

	return wait ? jd->jd_recover_error : 0;
}

