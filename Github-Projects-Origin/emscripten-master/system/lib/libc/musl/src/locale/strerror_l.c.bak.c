#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <string.h>
#include <locale.h>

char *strerror_l(int err, locale_t l)
{
	return strerror(err);
}
