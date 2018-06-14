#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <errno.h>
#include "syscall.h"

int brk(void *end)
{
	return __syscall_ret(-ENOMEM);
}
