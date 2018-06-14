#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

// FIXME

/* log(z) = log(|z|) + i arg(z) */

double complex clog(double complex z)
{
	double r, phi;

	r = cabs(z);
	phi = carg(z);
	return CMPLX(log(r), phi);
}
