#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/file.h>
#include "syscall.h"

int flock(int fd, int op)
{
	return syscall(SYS_flock, fd, op);
}
