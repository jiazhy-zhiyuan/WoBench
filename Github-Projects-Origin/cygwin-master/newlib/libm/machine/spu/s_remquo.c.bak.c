#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/remquo.h"

double remquo(double x, double y, int *quo)
{
    return _remquo(x, y, quo);
}
