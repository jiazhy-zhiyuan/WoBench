#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <inttypes.h>

intmax_t imaxabs(intmax_t a)
{
	return a>0 ? a : -a;
}
