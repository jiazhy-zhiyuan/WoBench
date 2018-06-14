#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>
#include "libc.h"

int __fxstat(int ver, int fd, struct stat *buf)
{
	return fstat(fd, buf);
}

LFS64(__fxstat);
