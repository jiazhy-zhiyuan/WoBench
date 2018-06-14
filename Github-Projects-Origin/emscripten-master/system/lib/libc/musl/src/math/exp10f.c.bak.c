#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#define _GNU_SOURCE
#include <math.h>
#include "libc.h"

float exp10f(float x)
{
	static const float p10[] = {
		1e-7f, 1e-6f, 1e-5f, 1e-4f, 1e-3f, 1e-2f, 1e-1f,
		1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7
	};
	float n, y = modff(x, &n);
	if (fabsf(n) < 8) {
		if (!y) return p10[(int)n+7];
		y = exp2f(3.32192809488736234787031942948939f * y);
		return y * p10[(int)n+7];
	}
	return exp2(3.32192809488736234787031942948939 * x);
}

weak_alias(exp10f, pow10f);
