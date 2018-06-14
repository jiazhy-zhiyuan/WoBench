#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"

int pipe(int fd[2])
{
	return syscall(SYS_pipe, fd);
}
