#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>
#undef isalpha

int isalpha(int c)
{
	return ((unsigned)c|32)-'a' < 26;
}
