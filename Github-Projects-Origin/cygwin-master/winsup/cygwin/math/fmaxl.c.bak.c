#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double
fmaxl (long double _x, long double  _y)
{
  return (__builtin_isgreaterequal (_x, _y) || __builtin_isnan (_y))
	 ?  _x : _y;
}