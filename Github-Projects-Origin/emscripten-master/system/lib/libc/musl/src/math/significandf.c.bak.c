#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <math.h>

float significandf(float x)
{
	return scalbnf(x, -ilogbf(x));
}
