#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>
#include <wchar.h>

int wctob(wint_t c)
{
	if (c < 128U) return c;
	return EOF;
}
