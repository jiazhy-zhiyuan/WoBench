#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Generated by: intel-gpu-tools-1.8-220-g01153e7
 */

#include "intel_renderstate.h"

static const u32 gen7_null_state_relocs[] = {
	0x0000000c,
	0x00000010,
	0x00000018,
	0x000001ec,
	-1,
};

static const u32 gen7_null_state_batch[] = {
	0x69040000,
	0x61010008,
	0x00000000,
	0x00000001,	 /* reloc */
	0x00000001,	 /* reloc */
	0x00000000,
	0x00000001,	 /* reloc */
	0x00000000,
	0x00000001,
	0x00000000,
	0x00000001,
	0x790d0002,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78180000,
	0x00000001,
	0x79160000,
	0x00000008,
	0x78300000,
	0x02010040,
	0x78310000,
	0x04000000,
	0x78320000,
	0x04000000,
	0x78330000,
	0x02000000,
	0x78100004,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x781b0005,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x781c0002,
	0x00000000,
	0x00000000,
	0x00000000,
	0x781d0004,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78110005,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78120002,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78210000,
	0x00000000,
	0x78130005,
	0x00000000,
	0x20000000,
	0x04000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78140001,
	0x20000800,
	0x00000000,
	0x781e0001,
	0x00000000,
	0x00000000,
	0x78050005,
	0xe0040000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78040001,
	0x00000000,
	0x00000000,
	0x78240000,
	0x00000240,
	0x78230000,
	0x00000260,
	0x782f0000,
	0x00000280,
	0x781f000c,
	0x00400810,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78200006,
	0x000002c0,
	0x08080000,
	0x00000000,
	0x28000402,
	0x00060000,
	0x00000000,
	0x00000000,
	0x78090005,
	0x02000000,
	0x22220000,
	0x02f60000,
	0x11230000,
	0x02f60004,
	0x11230000,
	0x78080003,
	0x00006008,
	0x00000340,	 /* reloc */
	0xffffffff,
	0x00000000,
	0x782a0000,
	0x00000360,
	0x79000002,
	0xffffffff,
	0x00000000,
	0x00000000,
	0x7b000005,
	0x0000000f,
	0x00000003,
	0x00000000,
	0x00000001,
	0x00000000,
	0x00000000,
	0x05000000,	 /* cmds end */
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000031,	 /* state start */
	0x00000003,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0xf99a130c,
	0x799a130c,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000492,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0080005a,
	0x2e2077bd,
	0x000000c0,
	0x008d0040,
	0x0080005a,
	0x2e6077bd,
	0x000000d0,
	0x008d0040,
	0x02800031,
	0x21801fa9,
	0x008d0e20,
	0x08840001,
	0x00800001,
	0x2e2003bd,
	0x008d0180,
	0x00000000,
	0x00800001,
	0x2e6003bd,
	0x008d01c0,
	0x00000000,
	0x00800001,
	0x2ea003bd,
	0x008d0200,
	0x00000000,
	0x00800001,
	0x2ee003bd,
	0x008d0240,
	0x00000000,
	0x05800031,
	0x20001fa8,
	0x008d0e20,
	0x90031000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000380,
	0x000003a0,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,	 /* state end */
};

RO_RENDERSTATE(7);
