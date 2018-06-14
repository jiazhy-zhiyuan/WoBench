#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isxdigit(int c)
{
	return isdigit(c) || ((unsigned)c|32)-'a' < 6;
}
