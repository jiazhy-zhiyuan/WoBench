#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int getgroups(int count, gid_t list[])
{
	return syscall(SYS_getgroups, count, list);
}
