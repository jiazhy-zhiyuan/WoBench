#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/sincosf.h"

void sincosf(float angle, float* sinx, float* cosx)
{
  return _sincosf(angle, sinx, cosx);
}
