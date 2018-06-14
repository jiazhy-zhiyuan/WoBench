#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/socket.h>

ssize_t recv(int fd, void *buf, size_t len, int flags)
{
	return recvfrom(fd, buf, len, flags, 0, 0);
}
