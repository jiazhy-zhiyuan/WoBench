#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>
#undef isupper

int isupper(int c)
{
	return (unsigned)c-'A' < 26;
}
