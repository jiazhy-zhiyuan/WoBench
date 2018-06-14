#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

/* pow(z, c) = exp(c log(z)), See C99 G.6.4.1 */

double complex cpow(double complex z, double complex c)
{
	return cexp(c * clog(z));
}
