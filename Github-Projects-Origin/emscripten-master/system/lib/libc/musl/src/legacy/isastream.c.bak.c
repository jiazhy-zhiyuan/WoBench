#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stropts.h>
#include <fcntl.h>

int isastream(int fd)
{
	return fcntl(fd, F_GETFD) < 0 ? -1 : 0;
}
