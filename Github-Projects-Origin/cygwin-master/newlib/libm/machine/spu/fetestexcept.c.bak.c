#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/fetestexcept.h"

int fetestexcept(int excepts)
{
    return _fetestexcept(excepts);
}
