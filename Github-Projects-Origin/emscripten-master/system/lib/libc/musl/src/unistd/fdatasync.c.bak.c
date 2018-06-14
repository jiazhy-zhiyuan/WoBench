#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int fdatasync(int fd)
{
	return syscall(SYS_fdatasync, fd);
}
