#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>

int mkfifo(const char *path, mode_t mode)
{
	return mknod(path, mode | S_IFIFO, 0);
}
