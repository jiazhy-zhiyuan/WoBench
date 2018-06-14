#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int isgraph_l(int c, locale_t l)
{
	return isgraph(c);
}
