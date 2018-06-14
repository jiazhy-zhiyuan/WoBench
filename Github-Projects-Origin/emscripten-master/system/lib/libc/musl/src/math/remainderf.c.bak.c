#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "libc.h"

float remainderf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
}

weak_alias(remainderf, dremf);
