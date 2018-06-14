#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int unlinkat(int fd, const char *path, int flag)
{
	return syscall(SYS_unlinkat, fd, path, flag);
}
