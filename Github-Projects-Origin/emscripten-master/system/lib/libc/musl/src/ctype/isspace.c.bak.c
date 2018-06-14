#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isspace(int c)
{
	return c == ' ' || (unsigned)c-'\t' < 5;
}
