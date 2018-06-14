#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/mman.h>
#include "syscall.h"

int mlockall(int flags)
{
	return syscall(SYS_mlockall, flags);
}
