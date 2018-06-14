#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int setuid(uid_t uid)
{
	return __setxid(SYS_setuid, uid, 0, 0);
}
