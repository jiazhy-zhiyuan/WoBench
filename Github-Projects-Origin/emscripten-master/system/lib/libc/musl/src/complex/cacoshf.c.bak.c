#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

float complex cacoshf(float complex z)
{
	z = cacosf(z);
	return CMPLXF(-cimagf(z), crealf(z));
}
