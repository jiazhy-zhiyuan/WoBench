#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int toupper(int c)
{
	if (islower(c)) return c & 0x5f;
	return c;
}
