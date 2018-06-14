#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

/* acosh(z) = i acos(z) */

double complex cacosh(double complex z)
{
	z = cacos(z);
	return CMPLX(-cimag(z), creal(z));
}
