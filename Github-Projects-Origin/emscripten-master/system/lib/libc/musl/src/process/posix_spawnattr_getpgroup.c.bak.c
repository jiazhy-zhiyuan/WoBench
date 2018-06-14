#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <spawn.h>

int posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict attr, pid_t *restrict pgrp)
{
	*pgrp = attr->__pgrp;
	return 0;
}
