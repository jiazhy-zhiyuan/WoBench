#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>

int vprintf(const char *restrict fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}
