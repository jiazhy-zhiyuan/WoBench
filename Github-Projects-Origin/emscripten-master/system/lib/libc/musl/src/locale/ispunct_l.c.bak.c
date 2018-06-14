#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int ispunct_l(int c, locale_t l)
{
	return ispunct(c);
}
