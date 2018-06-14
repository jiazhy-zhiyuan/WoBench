#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int tolower(int c)
{
	if (isupper(c)) return c | 32;
	return c;
}
