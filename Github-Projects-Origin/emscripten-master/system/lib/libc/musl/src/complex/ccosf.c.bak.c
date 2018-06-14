#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

float complex ccosf(float complex z)
{
	return ccoshf(CMPLXF(-cimagf(z), crealf(z)));
}
