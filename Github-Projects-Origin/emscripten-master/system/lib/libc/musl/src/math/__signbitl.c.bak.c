#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "libm.h"

#if (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
int __signbitl(long double x)
{
	union ldshape u = {x};
	return u.i.se >> 15;
}
#endif