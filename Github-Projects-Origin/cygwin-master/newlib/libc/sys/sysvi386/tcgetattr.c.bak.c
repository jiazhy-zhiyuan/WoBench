#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <sys/termios.h>

int
tcgetattr (int fd, struct termios *tp) {
	return _ioctl (fd, _XCGETA, tp);
}
