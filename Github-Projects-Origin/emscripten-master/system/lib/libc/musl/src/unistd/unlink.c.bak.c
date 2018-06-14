#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int unlink(const char *path)
{
	return syscall(SYS_unlink, path);
}
