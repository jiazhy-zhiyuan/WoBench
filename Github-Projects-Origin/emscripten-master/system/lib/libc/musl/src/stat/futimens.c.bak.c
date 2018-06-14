#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2])
{
	return utimensat(fd, 0, times, 0);
}
