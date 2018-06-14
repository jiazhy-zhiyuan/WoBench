#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isprint_l(int c, locale_t l)
{
	return isprint(c);
}
