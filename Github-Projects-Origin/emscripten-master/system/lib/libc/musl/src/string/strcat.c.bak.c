#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <string.h>

char *strcat(char *restrict dest, const char *restrict src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
