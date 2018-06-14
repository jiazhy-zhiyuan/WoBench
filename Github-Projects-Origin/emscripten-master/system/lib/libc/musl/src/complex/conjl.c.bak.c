#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

long double complex conjl(long double complex z)
{
	return CMPLXL(creall(z), -cimagl(z));
}
