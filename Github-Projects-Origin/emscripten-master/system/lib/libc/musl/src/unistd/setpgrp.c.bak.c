#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>

pid_t setpgrp(void)
{
	return setpgid(0, 0);
}
