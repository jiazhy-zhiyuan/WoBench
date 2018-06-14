#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

ldiv_t ldiv(long num, long den)
{
	return (ldiv_t){ num/den, num%den };
}
