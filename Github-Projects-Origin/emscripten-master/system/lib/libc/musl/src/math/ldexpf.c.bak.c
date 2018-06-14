#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

float ldexpf(float x, int n)
{
	return scalbnf(x, n);
}
