#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}
