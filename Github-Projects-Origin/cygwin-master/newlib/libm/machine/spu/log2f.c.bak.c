#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include <math.h>
#include "headers/log2f.h"

#undef log2f
float log2f(float x)
{
    return _log2f(x);
}
