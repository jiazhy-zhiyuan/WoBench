#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}
