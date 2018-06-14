#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int setregid(gid_t rgid, gid_t egid)
{
	return __setxid(SYS_setregid, rgid, egid, 0);
}
