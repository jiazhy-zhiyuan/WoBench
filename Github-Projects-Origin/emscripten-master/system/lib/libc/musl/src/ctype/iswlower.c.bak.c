#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswlower(wint_t wc)
{
	return towupper(wc) != wc || wc == 0xdf;
}
