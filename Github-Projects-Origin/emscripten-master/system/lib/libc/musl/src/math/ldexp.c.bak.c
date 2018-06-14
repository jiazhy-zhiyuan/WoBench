#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

double ldexp(double x, int n)
{
	return scalbn(x, n);
}
