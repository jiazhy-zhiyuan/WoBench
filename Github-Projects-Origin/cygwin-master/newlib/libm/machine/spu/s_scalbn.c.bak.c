#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/scalbn.h"

double scalbn(double x, int exp)
{
    return _scalbn(x, exp);
}
