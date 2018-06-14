#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
// SPDX-License-Identifier: GPL-2.0+
/*
 * comedi/drivers/amplc_pc236_common.c
 * Common support code for "amplc_pc236" and "amplc_pci236".
 *
 * Copyright (C) 2002-2014 MEV Ltd. <http://www.mev.co.uk/>
 *
 * COMEDI - Linux Control and Measurement Device Interface
 * Copyright (C) 2000 David A. Schleef <ds@schleef.org>
 */

#include <linux/module.h>
#include <linux/interrupt.h>

#include "../comedidev.h"

#include "amplc_pc236.h"
#include "8255.h"

static void pc236_intr_update(struct comedi_device *dev, bool enable)
{
	const struct pc236_board *board = dev->board_ptr;
	struct pc236_private *devpriv = dev->private;
	unsigned long flags;

	spin_lock_irqsave(&dev->spinlock, flags);
	devpriv->enable_irq = enable;
	if (board->intr_update_cb)
		board->intr_update_cb(dev, enable);
	spin_unlock_irqrestore(&dev->spinlock, flags);
}

/*
 * This function is called when an interrupt occurs to check whether
 * the interrupt has been marked as enabled and was generated by the
 * board.  If so, the function prepares the hardware for the next
 * interrupt.
 * Returns false if the interrupt should be ignored.
 */
static bool pc236_intr_check(struct comedi_device *dev)
{
	const struct pc236_board *board = dev->board_ptr;
	struct pc236_private *devpriv = dev->private;
	bool retval = false;
	unsigned long flags;

	spin_lock_irqsave(&dev->spinlock, flags);
	if (devpriv->enable_irq) {
		if (board->intr_chk_clr_cb)
			retval = board->intr_chk_clr_cb(dev);
		else
			retval = true;
	}
	spin_unlock_irqrestore(&dev->spinlock, flags);

	return retval;
}

static int pc236_intr_insn(struct comedi_device *dev,
			   struct comedi_subdevice *s, struct comedi_insn *insn,
			   unsigned int *data)
{
	data[1] = 0;
	return insn->n;
}

static int pc236_intr_cmdtest(struct comedi_device *dev,
			      struct comedi_subdevice *s,
			      struct comedi_cmd *cmd)
{
	int err = 0;

	/* Step 1 : check if triggers are trivially valid */

	err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
	err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
	err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
	err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
	err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);

	if (err)
		return 1;

	/* Step 2a : make sure trigger sources are unique */
	/* Step 2b : and mutually compatible */

	/* Step 3: check it arguments are trivially valid */

	err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
	err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
					   cmd->chanlist_len);
	err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);

	if (err)
		return 3;

	/* Step 4: fix up any arguments */

	/* Step 5: check channel list if it exists */

	return 0;
}

static int pc236_intr_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
	pc236_intr_update(dev, true);

	return 0;
}

static int pc236_intr_cancel(struct comedi_device *dev,
			     struct comedi_subdevice *s)
{
	pc236_intr_update(dev, false);

	return 0;
}

static irqreturn_t pc236_interrupt(int irq, void *d)
{
	struct comedi_device *dev = d;
	struct comedi_subdevice *s = dev->read_subdev;
	bool handled;

	handled = pc236_intr_check(dev);
	if (dev->attached && handled) {
		comedi_buf_write_samples(s, &s->state, 1);
		comedi_handle_events(dev, s);
	}
	return IRQ_RETVAL(handled);
}

int amplc_pc236_common_attach(struct comedi_device *dev, unsigned long iobase,
			      unsigned int irq, unsigned long req_irq_flags)
{
	struct comedi_subdevice *s;
	int ret;

	dev->iobase = iobase;

	ret = comedi_alloc_subdevices(dev, 2);
	if (ret)
		return ret;

	s = &dev->subdevices[0];
	/* digital i/o subdevice (8255) */
	ret = subdev_8255_init(dev, s, NULL, 0x00);
	if (ret)
		return ret;

	s = &dev->subdevices[1];
	dev->read_subdev = s;
	s->type = COMEDI_SUBD_UNUSED;
	pc236_intr_update(dev, false);
	if (irq) {
		if (request_irq(irq, pc236_interrupt, req_irq_flags,
				dev->board_name, dev) >= 0) {
			dev->irq = irq;
			s->type = COMEDI_SUBD_DI;
			s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
			s->n_chan = 1;
			s->maxdata = 1;
			s->range_table = &range_digital;
			s->insn_bits = pc236_intr_insn;
			s->len_chanlist	= 1;
			s->do_cmdtest = pc236_intr_cmdtest;
			s->do_cmd = pc236_intr_cmd;
			s->cancel = pc236_intr_cancel;
		}
	}

	return 0;
}
EXPORT_SYMBOL_GPL(amplc_pc236_common_attach);

static int __init amplc_pc236_common_init(void)
{
	return 0;
}
module_init(amplc_pc236_common_init);

static void __exit amplc_pc236_common_exit(void)
{
}
module_exit(amplc_pc236_common_exit);

MODULE_AUTHOR("Comedi http://www.comedi.org");
MODULE_DESCRIPTION("Comedi helper for amplc_pc236 and amplc_pci236");
MODULE_LICENSE("GPL");
