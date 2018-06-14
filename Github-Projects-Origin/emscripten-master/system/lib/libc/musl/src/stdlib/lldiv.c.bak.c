#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

lldiv_t lldiv(long long num, long long den)
{
	return (lldiv_t){ num/den, num%den };
}
