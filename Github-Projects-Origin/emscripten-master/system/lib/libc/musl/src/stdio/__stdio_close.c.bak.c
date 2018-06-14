#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "stdio_impl.h"

int __stdio_close(FILE *f)
{
	return syscall(SYS_close, f->fd);
}
