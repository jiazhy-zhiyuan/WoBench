#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <termios.h>
#include <sys/ioctl.h>

speed_t cfgetospeed(const struct termios *tio)
{
	return tio->c_cflag & CBAUD;
}

speed_t cfgetispeed(const struct termios *tio)
{
	return cfgetospeed(tio);
}
