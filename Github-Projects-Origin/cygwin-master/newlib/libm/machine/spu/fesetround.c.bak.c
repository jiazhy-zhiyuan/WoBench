#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/fesetround.h"

int fesetround(int rounding_mode)
{
    return _fesetround(rounding_mode);
}
