#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/mman.h>
#include "syscall.h"

int msync(void *start, size_t len, int flags)
{
	return syscall(SYS_msync, start, len, flags);
}
