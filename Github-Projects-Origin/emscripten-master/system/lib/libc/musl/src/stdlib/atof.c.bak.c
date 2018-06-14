#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <stdlib.h>

double atof(const char *s)
{
	return strtod(s, 0);
}
