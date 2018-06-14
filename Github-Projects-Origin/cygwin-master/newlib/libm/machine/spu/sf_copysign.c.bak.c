#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/copysignf.h"

float copysignf(float x, float y)
{
    return _copysignf(x, y);
}
