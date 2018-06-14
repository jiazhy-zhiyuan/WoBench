#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

pid_t getppid(void)
{
	return __syscall(SYS_getppid);
}
