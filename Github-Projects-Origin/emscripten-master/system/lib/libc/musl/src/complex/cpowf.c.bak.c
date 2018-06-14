#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

float complex cpowf(float complex z, float complex c)
{
	return cexpf(c * clogf(z));
}
