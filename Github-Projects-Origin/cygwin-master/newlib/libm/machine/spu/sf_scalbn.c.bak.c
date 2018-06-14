#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/scalbnf.h"

float scalbnf(float x, int exp)
{
    return _scalbnf(x, exp);
}
