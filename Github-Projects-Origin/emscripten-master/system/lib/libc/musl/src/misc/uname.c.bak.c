#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/utsname.h>
#include "syscall.h"

int uname(struct utsname *uts)
{
	return syscall(SYS_uname, uts);
}
