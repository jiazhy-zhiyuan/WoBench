#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int rmdir(const char *path)
{
	return syscall(SYS_rmdir, path);
}
