#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
void outbyte (unsigned char c)
{
	_write(1, &c, 1);
}
