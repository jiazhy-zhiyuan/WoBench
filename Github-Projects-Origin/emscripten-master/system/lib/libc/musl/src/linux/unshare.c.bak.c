#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <sched.h>
#include "syscall.h"

int unshare(int flags)
{
	return syscall(SYS_unshare, flags);
}
