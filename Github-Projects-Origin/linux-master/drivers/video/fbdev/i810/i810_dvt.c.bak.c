#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/*-*- linux-c -*-
 *  linux/drivers/video/i810_dvt.c -- Intel 810 Discrete Video Timings (Intel)
 *
 *      Copyright (C) 2001 Antonino Daplas<adaplas@pol.net>
 *      All Rights Reserved      
 *
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License. See the file COPYING in the main directory of this archive for
 *  more details.
 */

#include <linux/kernel.h>

#include "i810_regs.h"
#include "i810.h"

struct mode_registers std_modes[] = {
	/* 640x480 @ 60Hz */
	{ 25000, 0x0013, 0x0003, 0x40, 0x5F, 0x4F, 0x50, 0x82, 0x51, 0x9D,
	  0x0B, 0x10, 0x40, 0xE9, 0x0B, 0xDF, 0x50, 0xE7, 0x04, 0x02,
	  0x01, 0x01, 0x01, 0x00, 0x01, 0x22002000, 0x22004000, 0x22006000,
	  0x22002000, 0x22004000, 0x22006000, 0xC0 }, 
	  
	/* 640x480 @ 70Hz */
	{ 28000, 0x0053, 0x0010, 0x40, 0x61, 0x4F, 0x4F, 0x85, 0x52, 0x9A,
	  0xF2, 0x10, 0x40, 0xE0, 0x03, 0xDF, 0x50, 0xDF, 0xF3, 0x01, 
	  0x01, 0x01, 0x01, 0x00, 0x01, 0x22002000, 0x22004000, 0x22005000,
          0x22002000, 0x22004000, 0x22005000, 0xC0 },
          
        /* 640x480 @ 72Hz */
        { 31000, 0x0013, 0x0002, 0x40, 0x63, 0x4F, 0x4F, 0x87, 0x52, 0x97,
          0x06, 0x0F, 0x40, 0xE8, 0x0B, 0xDF, 0x50, 0xDF, 0x07, 0x02, 
          0x01, 0x01, 0x01, 0x00, 0x01, 0x22003000, 0x22005000, 0x22007000,
          0x22003000, 0x22005000, 0x22007000, 0xC0 },
          
        /* 640x480 @ 75Hz */
        { 31000, 0x0013, 0x0002, 0x40, 0x64, 0x4F, 0x4F, 0x88, 0x51, 0x99, 
          0xF2, 0x10, 0x40, 0xE0, 0x03, 0xDF, 0x50, 0xDF, 0xF3, 0x01, 
          0x01, 0x01, 0x01, 0x00, 0x01, 0x22003000, 0x22005000, 0x22007000, 
          0x22003000, 0x22005000, 0x22007000, 0xC0 },
          
        /* 640x480 @ 85Hz */
        { 36000, 0x0010, 0x0001, 0x40, 0x63, 0x4F, 0x4F, 0x87, 0x56, 0x9D,
          0xFB, 0x10, 0x40, 0xE0, 0x03, 0xDF, 0x50, 0xDF, 0xFC, 0x01,
          0x01, 0x01, 0x01, 0x00, 0x01, 0x22003000, 0x22005000, 0x22107000,
          0x22003000, 0x22005000, 0x22107000, 0xC0 },
          
        /* 800x600 @ 56Hz */
        { 36000, 0x0010, 0x0001, 0x40, 0x7B, 0x63, 0x63, 0x9F, 0x66, 0x8F,
          0x6F, 0x10, 0x40, 0x58, 0x0A, 0x57, 0xC8, 0x57, 0x70, 0x02, 
          0x02, 0x02, 0x02, 0x00, 0x01, 0x22003000, 0x22005000, 0x22107000,
          0x22003000, 0x22005000, 0x22107000, 0x00 },
          
        /* 800x600 @ 60Hz */
        { 40000, 0x0008, 0x0001, 0x30, 0x7F, 0x63, 0x63, 0x83, 0x68, 0x18, 
          0x72, 0x10, 0x40, 0x58, 0x0C, 0x57, 0xC8, 0x57, 0x73, 0x02,
          0x02, 0x02, 0x02, 0x00, 0x00, 0x22003000, 0x22006000, 0x22108000,
          0x22003000, 0x22006000, 0x22108000, 0x00 },
          
        /* 800x600 @ 70Hz */
        { 45000, 0x0054, 0x0015, 0x30, 0x7D, 0x63, 0x63, 0x81, 0x68, 0x12,
          0x6f, 0x10, 0x40, 0x58, 0x0b, 0x57, 0x64, 0x57, 0x70, 0x02, 
          0x02, 0x02, 0x02, 0x00, 0x00, 0x22004000, 0x22007000, 0x2210A000, 
          0x22004000, 0x22007000, 0x2210A000, 0x00 },
          
        /* 800x600 @ 72Hz */
        { 50000, 0x0017, 0x0004, 0x30, 0x7D, 0x63, 0x63, 0x81, 0x6A, 0x19,
          0x98, 0x10, 0x40, 0x7C, 0x02, 0x57, 0xC8, 0x57, 0x99, 0x02, 
          0x02, 0x02, 0x02, 0x00, 0x00, 0x22004000, 0x22007000, 0x2210A000,
          0x22004000, 0x22007000, 0x2210A000, 0x00 }, 
          
        /* 800x600 @ 75Hz */
        { 49000, 0x001F, 0x0006, 0x30, 0x7F, 0x63, 0x63, 0x83, 0x65, 0x0F,
          0x6F, 0x10, 0x40, 0x58, 0x0B, 0x57, 0xC8, 0x57, 0x70, 0x02, 
          0x02, 0x02, 0x02, 0x00, 0x00, 0x22004000, 0x22007000, 0x2210B000,
          0x22004000, 0x22007000, 0x2210B000, 0x00 },
          
        /* 800x600 @ 85Hz */
        { 56000, 0x0049, 0x000E, 0x30, 0x7E, 0x63, 0x63, 0x82, 0x67, 0x0F,
          0x75, 0x10, 0x40, 0x58, 0x0B, 0x57, 0xC8, 0x57, 0x76, 0x02,
          0x02, 0x02, 0x02, 0x00, 0x00, 0x22004000, 0x22108000, 0x2210b000, 
          0x22004000, 0x22108000, 0x2210b000, 0x00 },
          
        /* 1024x768 @ 60Hz */
        { 65000, 0x003F, 0x000A, 0x30, 0xA3, 0x7F, 0x7F, 0x87, 0x83, 0x94,
          0x24, 0x10, 0x40, 0x02, 0x08, 0xFF, 0x80, 0xFF, 0x25, 0x03,
          0x02, 0x03, 0x02, 0x00, 0x00, 0x22005000, 0x22109000, 0x2220D000,
          0x22005000, 0x22109000, 0x2220D000, 0xC0 },
          
        /* 1024x768 @ 70Hz */
	{ 75000, 0x0017, 0x0002, 0x30, 0xA1, 0x7F, 0x7F, 0x85, 0x82, 0x93,
	  0x24, 0x10, 0x40, 0x02, 0x08, 0xFF, 0x80, 0xFF, 0x25, 0x03,
	  0x02, 0x03, 0x02, 0x00, 0x00, 0x22005000, 0x2210A000, 0x2220F000,
	  0x22005000, 0x2210A000, 0x2220F000, 0xC0 }, 
	  
	/* 1024x768 @ 75Hz */          
	{ 78000, 0x0050, 0x0017, 0x20, 0x9F, 0x7F, 0x7F, 0x83, 0x81, 0x8D,
	  0x1E, 0x10, 0x40, 0x00, 0x03, 0xFF, 0x80, 0xFF, 0x1F, 0x03,
	  0x02, 0x03, 0x02, 0x00, 0x00, 0x22006000, 0x2210B000, 0x22210000,
	  0x22006000, 0x2210B000, 0x22210000, 0x00 },
	  
	/* 1024x768 @ 85Hz */
	{ 94000, 0x003D, 0x000E, 0x20, 0xA7, 0x7F, 0x7F, 0x8B, 0x85, 0x91,
	  0x26, 0x10, 0x40, 0x00, 0x03, 0xFF, 0x80, 0xFF, 0x27, 0x03,
	  0x02, 0x03, 0x02, 0x00, 0x00, 0x22007000, 0x2220E000, 0x22212000,
	  0x22007000, 0x2220E000, 0x22212000, 0x00 },
	  
	/* 1152x864 @ 60Hz */ 
	{ 80000, 0x0008, 0x0001, 0x20, 0xB3, 0x8F, 0x8F, 0x97, 0x93, 0x9f,
	  0x87, 0x10, 0x40, 0x60, 0x03, 0x5F, 0x90, 0x5f, 0x88, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x00, 0x2220C000, 0x22210000, 0x22415000,   
	  0x2220C000, 0x22210000, 0x22415000, 0x00 },
	  
	/* 1152x864 @ 70Hz */
	{ 96000, 0x000a, 0x0001, 0x20, 0xbb, 0x8F, 0x8F, 0x9f, 0x98, 0x87, 
	  0x82, 0x10, 0x40, 0x60, 0x03, 0x5F, 0x90, 0x5F, 0x83, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x00, 0x22107000, 0x22210000, 0x22415000,
	  0x22107000, 0x22210000, 0x22415000, 0x00 },
	  
	/* 1152x864 @ 72Hz */
	{ 99000, 0x001f, 0x0006, 0x20, 0xbb, 0x8F, 0x8F, 0x9f, 0x98, 0x87,
	  0x83, 0x10, 0x40, 0x60, 0x03, 0x5F, 0x90, 0x5F, 0x84, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x00, 0x22107000, 0x22210000, 0x22415000,
	  0x22107000, 0x22210000, 0x22415000, 0x00 },
	  
	/* 1152x864 @ 75Hz */
	{ 108000, 0x0010, 0x0002, 0x20, 0xC3, 0x8F, 0x8F, 0x87, 0x97, 0x07,
	  0x82, 0x10, 0x40, 0x60, 0x03, 0x5F, 0x90, 0x5F, 0x83, 0x03, 
	  0x03, 0x03, 0x03, 0x00, 0x01, 0x22107000, 0x22210000, 0x22415000,
	  0x22107000, 0x22210000, 0x22415000, 0x00 },
	  
	/* 1152x864 @ 85Hz */
	{ 121000, 0x006D, 0x0014, 0x20, 0xc0, 0x8F, 0x8F, 0x84, 0x97, 0x07,
	  0x93, 0x10, 0x40, 0x60, 0x03, 0x5F, 0x90, 0x5F, 0x94, 0x03, 
	  0x03, 0x03, 0x03, 0x00, 0x01, 0x2220C000, 0x22210000, 0x22415000,
	  0x2220C000, 0x22210000, 0x22415000, 0x0 },
	  
	/* 1280x960 @ 60Hz */
	{ 108000, 0x0010, 0x0002, 0x20, 0xDC, 0x9F, 0x9F, 0x80, 0xAB, 0x99,
	  0xE6, 0x10, 0x40, 0xC0, 0x03, 0xBF, 0xA0, 0xBF, 0xE7, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x01, 0x2210A000, 0x22210000, 0x22415000,
	  0x2210A000, 0x22210000, 0x22415000, 0x00 },
	  
	/* 1280x960 @ 75Hz */
	{ 129000, 0x0029, 0x0006, 0x20, 0xD3, 0x9F, 0x9F, 0x97, 0xaa, 0x1b,
	  0xE8, 0x10, 0x40, 0xC0, 0x03, 0xBF, 0xA0, 0xBF, 0xE9, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x01, 0x2210A000, 0x22210000, 0x2241B000,
	  0x2210A000, 0x22210000, 0x2241B000, 0x00 },
	  
	/* 1280x960 @ 85Hz */
	{ 148000, 0x0042, 0x0009, 0x20, 0xD3, 0x9F, 0x9F, 0x97, 0xA7, 0x1B,
	  0xF1, 0x10, 0x40, 0xC0, 0x03, 0xBF, 0xA0, 0xBF, 0xF2, 0x03,
	  0x03, 0x03, 0x03, 0x00, 0x01, 0x2210A000, 0x22220000, 0x2241D000,       
	  0x2210A000, 0x22220000, 0x2241D000, 0x00 },
	  
	/* 1600x1200 @ 60Hz */
	{ 162000, 0x0019, 0x0006, 0x10, 0x09, 0xC7, 0xC7, 0x8D, 0xcf, 0x07,
	  0xE0, 0x10, 0x40, 0xB0, 0x03, 0xAF, 0xC8, 0xAF, 0xE1, 0x04, 
	  0x04, 0x04, 0x04, 0x01, 0x00, 0x2210b000, 0x22416000, 0x44419000,
	  0x2210b000, 0x22416000, 0x44419000, 0x00 },
	  
	/* 1600x1200 @ 65 Hz */
	{ 175000, 0x005d, 0x0018, 0x10, 0x09, 0xC7, 0xC7, 0x8D, 0xcf, 0x07,
	  0xE0, 0x10, 0x40, 0xB0, 0x03, 0xAF, 0xC8, 0xAF, 0xE1, 0x04, 
	  0x04, 0x04, 0x04, 0x01, 0x00, 0x2210c000, 0x22416000, 0x44419000,
	  0x2210c000, 0x22416000, 0x44419000, 0x00 },
	  
	/* 1600x1200 @ 70 Hz */
	{ 189000, 0x003D, 0x000e, 0x10, 0x09, 0xC7, 0xC7, 0x8d, 0xcf, 0x07,
	  0xE0, 0x10, 0x40, 0xb0, 0x03, 0xAF, 0xC8, 0xaf, 0xE1, 0x04, 
	  0x04, 0x04, 0x04, 0x01, 0x00, 0x2220e000, 0x22416000, 0x44419000,
	  0x2220e000, 0x22416000, 0x44419000, 0x00 },
	  
 	/* 1600x1200 @ 72 Hz */
 	{ 195000, 0x003f, 0x000e, 0x10, 0x0b, 0xC7, 0xC7, 0x8f, 0xd5, 0x0b,
 	  0xE1, 0x10, 0x40, 0xb0, 0x03, 0xAF, 0xC8, 0xaf, 0xe2, 0x04, 0x04,
 	  0x04, 0x04, 0x01, 0x00, 0x2220e000, 0x22416000, 0x44419000,
 	  0x2220e000, 0x22416000, 0x44419000, 0x00 }, 
 	  
 	/* 1600x1200 @ 75 Hz */
 	{ 202000, 0x0024, 0x0007, 0x10, 0x09, 0xC7, 0xC7, 0x8d, 0xcf, 0x07,
 	  0xE0, 0x10, 0x40, 0xb0, 0x03, 0xAF, 0xC8, 0xaf, 0xE1, 0x04, 0x04,
 	  0x04, 0x04, 0x01, 0x00, 0x2220e000, 0x22416000, 0x44419000,      
 	  0x2220e000, 0x22416000, 0x44419000,  0x00 },
 	  
 	/* 1600x1200 @ 85 Hz */
	{ 229000, 0x0029, 0x0007, 0x10, 0x09, 0xC7, 0xC7, 0x8d, 0xcf, 0x07,
	  0xE0, 0x10, 0x40, 0xb0, 0x03, 0xAF, 0xC8, 0xaf, 0xE1, 0x04, 0x04,
	  0x04, 0x04, 0x01, 0x00, 0x22210000, 0x22416000, 0x0,
	  0x22210000, 0x22416000, 0x0, 0x00 },
};	 

void round_off_xres(u32 *xres) 
{
	if (*xres <= 640)
		*xres = 640;
	else if (*xres <= 800)
		*xres = 800;
	else if (*xres <= 1024)
		*xres = 1024;
	else if (*xres <= 1152)
		*xres = 1152;
	else if (*xres <= 1280)
		*xres = 1280;
	else
		*xres = 1600;
}

inline void round_off_yres(u32 *xres, u32 *yres)
{
	*yres = (*xres * 3) >> 2;
}

static int i810fb_find_best_mode(u32 xres, u32 yres, u32 pixclock)
{ 
	u32 diff = 0, diff_best = 0xFFFFFFFF, i = 0, i_best = 0; 
	u8 hfl = (u8) ((xres >> 3) - 1);

	for (i = 0; i < ARRAY_SIZE(std_modes); i++) { 
		if (std_modes[i].cr01 == hfl) { 
			if (std_modes[i].pixclock <= pixclock)
				diff = pixclock - std_modes[i].pixclock;
			if (diff < diff_best) {	 
		    		i_best = i;
		    		diff_best = diff;
			}
		}
	}
	return i_best;
}

void i810fb_encode_registers(const struct fb_var_screeninfo *var,
			     struct i810fb_par *par, u32 xres, u32 yres)
{
	u32 i_best = i810fb_find_best_mode(xres, yres, par->regs.pixclock);

	par->regs = std_modes[i_best];

	/* overlay */
	par->ovract = ((xres + var->right_margin + var->hsync_len + 
			var->left_margin - 32) | ((xres - 32) << 16));
}

void i810fb_fill_var_timings(struct fb_var_screeninfo *var)
{
	u32 total, xres, yres;
	u32 mode, pixclock;

	xres = var->xres;
	yres = var->yres;
	
	pixclock = 1000000000 / var->pixclock;
	mode = i810fb_find_best_mode(xres, yres, pixclock);
	
	total = (std_modes[mode].cr00 | (std_modes[mode].cr35 & 1) << 8) + 3;
	total <<= 3;
	
	var->pixclock = 1000000000 / std_modes[mode].pixclock;
	var->right_margin = (std_modes[mode].cr04 << 3) - xres;
	var->hsync_len = ((std_modes[mode].cr05 & 0x1F) -
			 (std_modes[mode].cr04 & 0x1F)) << 3;
	var->left_margin = (total - (xres + var->right_margin + 
				     var->hsync_len));
	var->sync = FB_SYNC_ON_GREEN;
	if (~(std_modes[mode].msr & (1 << 6)))
		var->sync |= FB_SYNC_HOR_HIGH_ACT;
	if (~(std_modes[mode].msr & (1 << 7)))
		var->sync |= FB_SYNC_VERT_HIGH_ACT;

	total = (std_modes[mode].cr06 | (std_modes[mode].cr30 & 0xF)  << 8) + 2;
	var->lower_margin = (std_modes[mode].cr10 |
			    (std_modes[mode].cr32 & 0x0F) << 8) - yres;
	var->vsync_len = (std_modes[mode].cr11 & 0x0F) -
			 (var->lower_margin & 0x0F);
	var->upper_margin = total - (yres + var->lower_margin + var->vsync_len);
}

u32 i810_get_watermark(struct fb_var_screeninfo *var,
		       struct i810fb_par *par)
{
	struct mode_registers *params = &par->regs;
	u32 wmark = 0;
	
	if (par->mem_freq == 100) {
		switch (var->bits_per_pixel) {
		case 8:
			wmark = params->bpp8_100;
			break;
		case 16:
			wmark = params->bpp16_100;
			break;
		case 24:
		case 32:
			wmark = params->bpp24_100;
		}
	} else {					
		switch (var->bits_per_pixel) {
		case 8:
			wmark = params->bpp8_133;
			break;
		case 16:
			wmark = params->bpp16_133;
			break;
		case 24:
		case 32:
			wmark = params->bpp24_133;
		}
	}
	return wmark;
}	

