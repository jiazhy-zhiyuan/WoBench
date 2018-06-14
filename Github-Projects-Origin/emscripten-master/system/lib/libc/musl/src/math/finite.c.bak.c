#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <math.h>

int finite(double x)
{
	return isfinite(x);
}
