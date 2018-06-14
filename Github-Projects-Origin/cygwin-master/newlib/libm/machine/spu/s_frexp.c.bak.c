#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/frexp.h"

double frexp(double x, int *pexp)
{
    return _frexp(x, pexp);
}
