#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <stdarg.h>
#include "libc.h"

int vscanf(const char *restrict fmt, va_list ap)
{
	return vfscanf(stdin, fmt, ap);
}

weak_alias(vscanf,__isoc99_vscanf);
