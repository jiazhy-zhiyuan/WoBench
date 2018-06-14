#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswdigit_l(wint_t c, locale_t l)
{
	return iswdigit(c);
}
