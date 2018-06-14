#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include <stdint.h>

float fabsf(float x)
{
	union {float f; uint32_t i;} u = {x};
	u.i &= 0x7fffffff;
	return u.f;
}
