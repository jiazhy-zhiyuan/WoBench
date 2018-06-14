#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int tolower_l(int c, locale_t l)
{
	return tolower(c);
}
