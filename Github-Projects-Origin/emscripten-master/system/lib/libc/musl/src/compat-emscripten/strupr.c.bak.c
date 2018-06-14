#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

char *strupr(char *str)
{
	char *ret = str;
	while(*str)
	{
		*str = toupper(*str);
		++str;
	}
	return ret;
}
