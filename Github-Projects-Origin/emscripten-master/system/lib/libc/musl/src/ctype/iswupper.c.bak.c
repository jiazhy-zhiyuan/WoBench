#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswupper(wint_t wc)
{
	return towlower(wc) != wc;
}
