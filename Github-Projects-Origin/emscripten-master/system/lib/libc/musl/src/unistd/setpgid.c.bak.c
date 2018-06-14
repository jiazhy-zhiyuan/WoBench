#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int setpgid(pid_t pid, pid_t pgid)
{
	return syscall(SYS_setpgid, pid, pgid);
}
