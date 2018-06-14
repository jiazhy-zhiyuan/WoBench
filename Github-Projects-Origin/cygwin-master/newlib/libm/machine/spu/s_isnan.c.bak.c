#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/isnan.h"

#undef isnan
int isnan(double x)
{
  return _isnan(x);
}
