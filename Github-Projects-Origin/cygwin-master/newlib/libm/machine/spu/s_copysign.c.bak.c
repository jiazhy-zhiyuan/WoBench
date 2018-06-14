#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/copysign.h"

double copysign(double x, double y)
{
    return _copysign(x, y);
}
