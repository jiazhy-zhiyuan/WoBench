#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <math.h>

int finitef(float x)
{
	return isfinite(x);
}
