#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wchar.h>
#include <wctype.h>

#undef iswdigit

int iswdigit(wint_t wc)
{
	return (unsigned)wc-'0' < 10;
}