#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
int
isnan (double x)
{
  return __builtin_isnan (x);
}

int
isnanf (float x)
{
  return __builtin_isnan (x);
}

int
isnanl (long double x)
{
  return __builtin_isnan (x);
}

