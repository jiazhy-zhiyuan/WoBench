#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <spawn.h>

int posix_spawnattr_getflags(const posix_spawnattr_t *restrict attr, short *restrict flags)
{
	*flags = attr->__flags;
	return 0;
}
