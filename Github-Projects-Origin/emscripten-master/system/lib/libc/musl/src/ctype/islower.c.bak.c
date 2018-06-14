#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>
#undef islower

int islower(int c)
{
	return (unsigned)c-'a' < 26;
}
