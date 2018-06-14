#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

pid_t setsid(void)
{
	return syscall(SYS_setsid);
}
