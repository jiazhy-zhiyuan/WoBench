#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <wctype.h>

int iswgraph_l(wint_t c, locale_t l)
{
	return iswgraph(c);
}
