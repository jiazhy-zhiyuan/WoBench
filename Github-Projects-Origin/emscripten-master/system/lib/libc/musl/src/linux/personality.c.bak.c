#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/personality.h>
#include "syscall.h"
#ifdef SYS_personality
int personality(unsigned long persona)
{
	return syscall(SYS_personality, persona);
}
#endif
