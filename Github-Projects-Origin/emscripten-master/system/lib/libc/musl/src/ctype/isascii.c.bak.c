#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isascii(int c)
{
	return !(c&~0x7f);
}
