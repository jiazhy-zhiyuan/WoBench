#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

/* nonsense function that should NEVER be used! */
int toascii(int c)
{
	return c & 0x7f;
}
