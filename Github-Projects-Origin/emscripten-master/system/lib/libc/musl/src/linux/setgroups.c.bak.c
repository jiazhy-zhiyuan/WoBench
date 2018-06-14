#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

int setgroups(size_t count, const gid_t list[])
{
	return syscall(SYS_setgroups, count, list);
}
