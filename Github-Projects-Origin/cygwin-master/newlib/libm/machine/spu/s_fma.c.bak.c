#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/fma.h"

double fma(double x, double y, double z)
{
    return _fma(x, y, z);
}
