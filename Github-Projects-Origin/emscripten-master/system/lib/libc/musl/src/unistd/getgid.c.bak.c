#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

gid_t getgid(void)
{
	return __syscall(SYS_getgid);
}
