#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

long double nexttowardl(long double x, long double y)
{
	return nextafterl(x, y);
}
