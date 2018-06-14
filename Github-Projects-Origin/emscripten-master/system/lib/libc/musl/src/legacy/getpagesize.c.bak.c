#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <unistd.h>
#include "libc.h"

int getpagesize(void)
{
	return PAGE_SIZE;
}
