#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/socket.h>
#include "syscall.h"

int shutdown(int fd, int how)
{
	return socketcall(shutdown, fd, how, 0, 0, 0, 0);
}
