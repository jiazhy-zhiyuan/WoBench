#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

char *strlwr(char *str)
{
	char *ret = str;
	while(*str)
	{
		*str = tolower(*str);
		++str;
	}
	return ret;
}
