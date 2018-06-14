#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <fenv.h>

int fesetexceptflag(const fexcept_t *fp, int mask)
{
	feclearexcept(~*fp & mask);
	feraiseexcept(*fp & mask);
	return 0;
}
