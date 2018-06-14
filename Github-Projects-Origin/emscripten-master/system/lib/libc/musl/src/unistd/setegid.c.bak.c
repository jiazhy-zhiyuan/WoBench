#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "libc.h"
#include "syscall.h"

int setegid(gid_t egid)
{
	return __setxid(SYS_setresgid, -1, egid, -1);
}
