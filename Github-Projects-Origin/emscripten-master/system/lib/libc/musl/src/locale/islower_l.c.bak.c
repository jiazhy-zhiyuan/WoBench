#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int islower_l(int c, locale_t l)
{
	return islower(c);
}
