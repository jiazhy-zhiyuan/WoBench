#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wchar.h>
#include <wctype.h>
#include <ctype.h>

int iswblank(wint_t wc)
{
	return isblank(wc);
}
