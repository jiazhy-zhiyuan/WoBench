#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
int isprint(int c)
{
	return (unsigned)c-0x20 < 0x5f;
}
