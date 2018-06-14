#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
int isgraph(int c)
{
	return (unsigned)c-0x21 < 0x5e;
}
