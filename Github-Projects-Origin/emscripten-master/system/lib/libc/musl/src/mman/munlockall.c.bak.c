#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/mman.h>
#include "syscall.h"

int munlockall(void)
{
	return syscall(SYS_munlockall);
}
