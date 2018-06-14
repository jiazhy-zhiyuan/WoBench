#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/log2.h"

#undef log2
double log2(double vx)
{
  return _log2(vx);
}
