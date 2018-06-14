#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "headers/feclearexcept.h"

void feclearexcept(int excepts)
{
    _feclearexcept(excepts);
}
