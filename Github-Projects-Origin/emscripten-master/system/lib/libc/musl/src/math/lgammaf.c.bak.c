#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

extern int __signgam;
float __lgammaf_r(float, int *);

float lgammaf(float x)
{
	return __lgammaf_r(x, &__signgam);
}
