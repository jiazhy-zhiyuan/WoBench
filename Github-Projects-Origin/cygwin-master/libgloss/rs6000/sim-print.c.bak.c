#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/* sim-print.c -- print a string on the output device.
 *
 * Copyright (c) 1995 Cygnus Support
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

/*
 * print -- do a raw print of a string
 */ 
void
print (ptr)
     char *ptr;
{
  int len = 0;
  char *p = ptr;

  while (*p != '\0')
    p++;

  write (1, ptr, p-ptr);
}

/*
 * outbyte -- write a single character.
 */

void
outbyte (c_int)
     int c_int;
{
  char c = c_int;

  write (1, &c, 1);
}
