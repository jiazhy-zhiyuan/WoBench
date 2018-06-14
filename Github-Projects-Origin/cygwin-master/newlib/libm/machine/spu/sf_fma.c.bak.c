#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/fmaf.h"

float fmaf(float x, float y, float z)
{
    return _fmaf(x, y, z);
}
