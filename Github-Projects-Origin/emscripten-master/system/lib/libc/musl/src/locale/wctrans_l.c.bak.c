#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

wctrans_t wctrans_l(const char *s, locale_t l)
{
	return wctrans(s);
}
