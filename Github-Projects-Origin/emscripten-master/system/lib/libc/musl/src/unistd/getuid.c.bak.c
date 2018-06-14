#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

uid_t getuid(void)
{
	return __syscall(SYS_getuid);
}
