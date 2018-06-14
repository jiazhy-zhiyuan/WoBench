#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>
#include "libc.h"

int __lxstat(int ver, const char *path, struct stat *buf)
{
	return lstat(path, buf);
}

LFS64(__lxstat);
