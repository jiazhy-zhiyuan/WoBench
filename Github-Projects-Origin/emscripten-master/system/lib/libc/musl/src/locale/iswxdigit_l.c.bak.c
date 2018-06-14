#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswxdigit_l(wint_t c, locale_t l)
{
	return iswxdigit(c);
}
