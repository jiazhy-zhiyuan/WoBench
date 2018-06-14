#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/sincos.h"

void sincos(double angle, double* sinx, double* cosx)
{
  return _sincos(angle, sinx, cosx);
}
