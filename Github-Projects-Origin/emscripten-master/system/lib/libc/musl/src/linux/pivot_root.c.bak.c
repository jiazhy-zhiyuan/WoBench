#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "syscall.h"

int pivot_root(const char *new, const char *old)
{
	return syscall(SYS_pivot_root, new, old);
}
