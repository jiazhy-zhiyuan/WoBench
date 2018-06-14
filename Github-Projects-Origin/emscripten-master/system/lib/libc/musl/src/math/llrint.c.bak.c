#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

/* uses LLONG_MAX > 2^53, see comments in lrint.c */

long long llrint(double x)
{
	return rint(x);
}
