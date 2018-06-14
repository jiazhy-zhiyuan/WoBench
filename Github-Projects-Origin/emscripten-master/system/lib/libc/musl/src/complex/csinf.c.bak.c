#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

float complex csinf(float complex z)
{
	z = csinhf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(z), -crealf(z));
}
