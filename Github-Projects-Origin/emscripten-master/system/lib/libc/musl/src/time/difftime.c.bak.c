#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <time.h>

double difftime(time_t t1, time_t t0)
{
	return t1-t0;
}
