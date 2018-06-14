#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <ctype.h>

int iscntrl_l(int c, locale_t l)
{
	return iscntrl(c);
}
