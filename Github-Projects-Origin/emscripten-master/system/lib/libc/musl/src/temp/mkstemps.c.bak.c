#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _BSD_SOURCE
#include <stdlib.h>
#include "libc.h"

int __mkostemps(char *, int, int);

int mkstemps(char *template, int len)
{
	return __mkostemps(template, len, 0);
}

LFS64(mkstemps);
