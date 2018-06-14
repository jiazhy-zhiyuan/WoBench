#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>
#include "syscall.h"
#include "libc.h"

int lstat(const char *restrict path, struct stat *restrict buf)
{
	return syscall(SYS_lstat, path, buf);
}

LFS64(lstat);
