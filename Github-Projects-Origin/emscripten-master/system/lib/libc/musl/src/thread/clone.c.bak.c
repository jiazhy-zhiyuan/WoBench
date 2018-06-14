#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <errno.h>
#include "pthread_impl.h"

int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
{
	return -ENOSYS;
}
