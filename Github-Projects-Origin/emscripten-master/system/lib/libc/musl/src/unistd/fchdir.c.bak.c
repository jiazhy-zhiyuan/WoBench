#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

void __procfdname(char *, unsigned);

int fchdir(int fd)
{
	int ret = __syscall(SYS_fchdir, fd);
	if (ret != -EBADF || __syscall(SYS_fcntl, fd, F_GETFD) < 0)
		return __syscall_ret(ret);

	char buf[15+3*sizeof(int)];
	__procfdname(buf, fd);
	return syscall(SYS_chdir, buf);
}
