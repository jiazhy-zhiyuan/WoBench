#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <unistd.h>

int posix_close(int fd, int flags)
{
	return close(fd);
}
