#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/ldexpf.h"

float ldexpf(float x, int exp)
{
    return _ldexpf(x, exp);
}
