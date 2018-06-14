#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

void sync(void)
{
	__syscall(SYS_sync);
}
