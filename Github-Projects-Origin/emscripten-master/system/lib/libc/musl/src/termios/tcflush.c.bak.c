#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <termios.h>
#include <sys/ioctl.h>

int tcflush(int fd, int queue)
{
	return ioctl(fd, TCFLSH, queue);
}
