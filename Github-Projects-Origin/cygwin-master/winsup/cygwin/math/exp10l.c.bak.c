#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#undef exp10l
#include <math.h>

long double
exp10l (long double x)
{
  return powl (10.0L, x);
}