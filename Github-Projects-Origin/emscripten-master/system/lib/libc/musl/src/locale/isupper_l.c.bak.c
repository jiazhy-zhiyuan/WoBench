#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isupper_l(int c, locale_t l)
{
	return isupper(c);
}
