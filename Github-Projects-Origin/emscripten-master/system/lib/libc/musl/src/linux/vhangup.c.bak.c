#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

int vhangup(void)
{
	return syscall(SYS_vhangup);
}
