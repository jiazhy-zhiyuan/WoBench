#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

double carg(double complex z)
{
	return atan2(cimag(z), creal(z));
}
