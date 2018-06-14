#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int chdir(const char *path)
{
	return syscall(SYS_chdir, path);
}
