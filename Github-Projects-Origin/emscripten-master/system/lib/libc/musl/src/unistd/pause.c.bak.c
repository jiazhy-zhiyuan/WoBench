#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int pause(void)
{
	return syscall_cp(SYS_pause);
}
