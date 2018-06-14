#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "stdio_impl.h"

int putchar_unlocked(int c)
{
	return putc_unlocked(c, stdout);
}
