#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

uid_t geteuid(void)
{
	return __syscall(SYS_geteuid);
}
