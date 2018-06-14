#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>
#include "libc.h"

int __xstat(int ver, const char *path, struct stat *buf)
{
	return stat(path, buf);
}

LFS64(__xstat);
