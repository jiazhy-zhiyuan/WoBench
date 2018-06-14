#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>

int
finite (double x)
{
  return __builtin_isfinite (x);
}

int
finitef (float x)
{
  return __builtin_isfinite (x);
}

int
finitel (long double x)
{
  return __builtin_isfinite (x);
}
