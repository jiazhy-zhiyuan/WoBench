#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
int inbyte(void)
{
	char ch = 0;
	read(0, &ch, 1);
	return ch;
}
