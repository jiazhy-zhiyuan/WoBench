#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdio.h>

int putchar(int c)
{
	return fputc(c, stdout);
}
