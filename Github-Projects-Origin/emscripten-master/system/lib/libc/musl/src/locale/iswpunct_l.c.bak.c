#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswpunct_l(wint_t c, locale_t l)
{
	return iswpunct(c);
}
