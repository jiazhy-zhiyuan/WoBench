#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isdigit_l(int c, locale_t l)
{
	return isdigit(c);
}
